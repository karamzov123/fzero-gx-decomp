# 348 — fn_1_D123C: the value-merge diamond gives `cmplwi; beq 8; b`, and `s32 sid` is the register lever

Session of 2026-10-16, agent `deepseek-opencode`. **fn_1_D123C is MATCHED
(commit `63413b8d`, attempt 17, verify fast path, 16 files OK, lint 0).**
This closes the campaign whose construct ground truth was established earlier
(`src/dol/fn_8007AA7C.c` if/else both-assign, `src/dol/fn_80006B30.c`
ternary-into-store): the two dispatch sites compile to

    lwzx  r25, r4, r30
    cmplwi r25, 0
    beq   8              ; ==0 -> alloc block
    b     +0x2c          ; !=0 -> join
    <fn_1_45D0 call block, ends `mr r25, r3`>
    join

only when the source is a value-merge diamond: condition and taken arm read
the **same table expression** (`if (EXPR != 0) { v = EXPR; } else { v = call; }`).
CSE leaves no code in the true arm, but the CFG block survives and forces the
`beq`-around-`b` pair.

## Measured construct table (337-word function, 2 sites)

| source shape | words | diffs (vs retail) |
|---|---|---|
| `switch ((u32)v) { case 0: ... }` | 337 | 2 — `cmpwi` vs `cmplwi` at w160/w292, otherwise byte-exact |
| plain `if (v == 0) { v = call; }` | 335 | single `bne`, missing `b` |
| diamond `if (EXPR != 0) v = EXPR; else v = call;` | 337 | 3 — w10/11/16 only (`sid` in r25 vs retail r27) |
| same diamond, `s32 sid;` instead of `s8 sid;` | **337** | **0** |

`tern_dup` (value merge spelled as `v = EXPR ? EXPR : call`), `reload_then`,
`load_and_cond`, `ifelse_dup_ptr` all produce the identical site code — the
residual was never the site shape, only `sid`'s register.

## The register lever: `s32 sid`

`s8 sid; sid = (s8)arg0;` allocates `sid` to **r25**; declaring it `s32`
(or `int`) allocates **r27** (retail) with *identical* instruction stream
(`extsb r27, r26` — the value stays a sign-extended byte; MWCC does not
re-widen at the two call uses). Sweep of the declaration position for `s8 sid`
(12 locals): positions 0–6 → r25, 7 → r24, 8+ → r23 — i.e. moving a
declaration *later* lowers its register band; the flip upward needs the type
change. Unused trailing dummies, added stack objects, and `sid` declared first
change nothing. The other local register web order was undisturbed
(`base` r31, `arg0` r26, `v1` r28, `v4` r29, `size` r23, `entry` r25).

## Two-compile trap: standalone unit vs TU prologue (PROLOGUE CONFLICT)

`write-unit`/`check` compile the *work copy* standalone (it must carry its own
externs — the headers do not declare `fn_1_86690`, `fn_1_12C930`, …), and then
`_prologue_conflict` compiles `prologue + body` to prove the block will splice
clean. Our first submission passed the standalone diff at 100.0% but was
flagged: `extern u32 lbl_801A6410;` vs the prologue's `void *` (MWCC aborts
after the first conflict). Both must be satisfied:

| declaration | prologue says | codegen-exact alignment |
|---|---|---|
| `lbl_801A6410` | `void *` | use `void *` — the code reads `*(u32 *)&lbl_801A6410`, unaffected |
| `fn_1_12C930` | `u32 fn_1_12C930(u32)` | keep prologue type + cast the index `(s16)fn_1_12C930(v1)` |

`fn_1_12C930`'s **return** type is the codegen-critical part: `u32` alone
drops the `extsh r5, r3` at w22 (336 words / 312 diffs); `s16` return restores
it. The argument type is irrelevant (`s16 f(s16)`, `s16 f(u32)`, `u32 f(u32)`
+ `(s16)` cast all give 337/0 standalone). A file-scope `s16`-returning
redeclaration also passed the probe (rc=0, 337/0) but was **not** chosen: it
leaks a conflicting declaration ahead of later blocks in the TU. The chosen
body keeps every file-scope declaration byte-identical to the prologue.

Offline validation recipe before spending checks (used here; each `write-unit`
and `check` consumes one of MAX 5 non-improving checks):

1. standalone: `oracle.compile_source(p, module, src, /tmp/x.o, None, None)`
   then `word_score(words(target), words(obj))` — expect 337/0;
2. prologue probe: replicate `api._prologue_conflict` —
   `tufile.split_includes(text)` → `prologue + extra + body` →
   `oracle.compile_unit(p, unit, unit_src, probe, output=obj)` — expect rc=0
   and (optionally) 337/0 on the probe object.

Both passed on the final body before the successful `write-unit`.

## Landing trail

- `claim fn_1_D123C --agent deepseek-opencode --max-attempts 50` → attempt 17
  (attempts were 16; a plain claim is refused at `attempts >= 3`).
- `write-unit` #1 → standalone 100.0% + PROLOGUE CONFLICT; `write-unit` #2
  (aligned decls + call-site cast) → 100.0% MATCH, lint clean, no conflict.
- `submit` → `link: pending`; `verify` → fast path, `commit 63413b8d`
  (`units.json` + 153-line block in `src/rel/main_rel/enemy_ctrl.c`, includes
  deduped, spliced **with** prologue).
- Gate: `ninja build/GFZE01/ok` no-op, `sha1sum -c` 16/16 OK, `fzgx lint`
  0 findings, `unittest discover -s tests` 11 OK.
