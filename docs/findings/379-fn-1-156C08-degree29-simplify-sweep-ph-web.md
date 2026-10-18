# 379 — fn_1_156C08 landed: one interference edge flips MWCC's degree-29 simplify sweep (the `ph` pointer web)

Session of 2026-10-17 (opencode manual CLI, agent `opencode-manual-156c08`,
continuing finding 361's designated lead). Closes the 99.01% / 12-attempt
plateau at **attempt 13: 100.0%, 101/101 words, 2 checks**. Commit `9b299290`
(ranking.c block + `units.json` pool map, linked and hash-verified: 16 files
OK); supporting tooling commit `d69576ef`.

## Two corrections to finding 361 (both needed to unblock the work)

1. **The "retail row-12 `lis`/`addi` magic pair" does not exist.** Word 12 of the
   retail window is `0xFC020040` = `fcmpo cr0, f2, f0`. The project venv's
   pinned capstone 5.0.7 cannot decode `fcmpo` (opcode 63, XO 32) and emits
   `.byte 0xfc, 0x02, 0x00, 0x40` — that is what `mwconstraints.target_mapping`
   reported as `unsupported-instruction`, and it blocked the *entire* capture
   projection, not just that row. `d69576ef` adds `_recover_undecoded()` and the
   projections now work: retail-vs-retail returns `fixed-graph-hypothesis`;
   retail-vs-s32-no-ph returns `needs-web-alignment` with the flip rows.
2. **Callers do exist in `src/`.** 361's last entry point said "none found in
   src/ today"; `src/rel/main_rel/ranking.c` holds **nine matched callers** that
   all declare a wide (s32/int) `fn_8006B55C`: `fn_1_1568C4` (l.751),
   `fn_1_156D9C`, `fn_1_156F54`, `fn_1_157070`, `fn_1_157200`, `fn_1_157358`,
   `fn_1_1574E0`, `fn_1_157598`, `fn_1_1576B4` — plus the matched DOL unit
   `src/dol/fn_8006B55C.c` (`s32 fn_8006B55C(Fn8006B55CData *data, u32, u32)`).
   The s16 unit-local extern was the artifact; s32 was always the right type.

## The mechanism, capture-measured (the useful part)

MWCC's stock simplify removes webs in ascending-vr sweeps and **defers every
web whose interference degree stays >= K = 29 GPRs**; deferred webs are taken
in a later sweep and land at the front of the replay, which is how a web claims
the top callee-saved register. The fn_8006B55C caller flip is exactly this: an
**arg0 pointer web** whose degree is one edge short in the s32 build.

From the two stock-allocator captures (`fixup --capture`; final simplify stage):

| body | arg0 web (vr 32) | counter web (vr 37) | emitted |
|---|---|---|---|
| s32 extern (prior 99% body) | deg **28**, removed late (`…33,32`) → **r30** | deg 20 → **r31** | wrong colors, right `cmpwi` |
| s16 extern (archived best) | deg **29** — extra neighbors `{54,57,60}` = the `extsh` result web → **deferred to front** → **r31** | deg 20 → **r30** | retail colors, wrong `extsh.` |

So the entire 21-row "wholesale r30/r31 flip" of 361 is **one edge on one web**.
With the `extsh` gone (s32) the edge count drops to 28 and arg0 loses the
sweep; with `extsh` present (s16) the colors are retail's. Captures:
`/tmp/opencode/capout/fn_1_156C08.json` (s32), `/tmp/opencode/capout16/…` (s16).

## The landed source shape

Keep `extern s32 fn_8006B55C(...)` and materialize the handle address into a
local pointer **inside the then-branch, immediately before the call**:

```c
u32 *ph;                    /* declared with the other locals */
...
if (handle == (u32)-1) {
    ph = &arg0->handle;     /* the one extra edge; emits no instruction */
    if (fn_8006B55C(data, ph, (u8 *)&loc_8) < 0) {
    } else { v13 = 1; }
} else { ... }
```

The `ph` web is live only across the call, so it adds exactly one interfering
neighbor to arg0's web (28 → 29): arg0 is deferred, takes r31; the counter
falls to r30 — retail's assignment with the correct s32 compare. The body is a
**pool** unit: the `.fzgxpool` primer (finding 344/377 machinery) retargets the
body's private float literals to retail's shared `lbl_1_rodata_D8C8`
(`pool_map` `{...rodata.0, @5..@13}`, `@5` duplicated by 0.0f); after retarget
`.text` is byte-equal and `.rodata` empty.

An equivalent landing exists (`c5d_ph_lp`): hold the `loc_8` address in a
second local `u8 *lp` inside the same branch — also 100.000%, 0 diffs. Both
compile from `/tmp/opencode/p156/var/` via `/tmp/opencode/p156/batch2.py`.

## Plateaus measured dead on the way (do not repeat)

- `ok` local for the branch, `res` call-result local, `t = data`/`h2` copies,
  zero-split, declaration reorders, `(s16)` casts, wrapper inlines, pragma
  cells, `-O3/-O4,s`: 21 diffs or worse / compile errors (361's lists hold).
- `mwconstraints.declaration_projection`: no candidates. `target_mapping`
  cannot pass on the s32 body at all — the prologue instruction *sequence*
  differs (shape gate, rows 5–7), so the row-projection path is the wrong tool
  for a role swap; the **graph capture** (nodes/degrees/simplify_order) is the
  tool. The fcmpo decode fix (above) is what makes `target_mapping` usable at
  all on this function.

## Repro / evidence

- `/tmp/opencode/p156/batch2.py` — recompiles the two 100% variants and the
  dead ones, offline, ~10 s per compile, zero ledger checks.
- `/tmp/opencode/capout`, `/tmp/opencode/capout16` — the s32/s16 captures
  (capture 1 of each holds the table above; earlier sweeps were waste).
- Landed block: `src/rel/main_rel/ranking.c` `/* fzgx:begin fn_1_156C08 */`
  (~line 904), pool status in `config/GFZE01/units.json`.
