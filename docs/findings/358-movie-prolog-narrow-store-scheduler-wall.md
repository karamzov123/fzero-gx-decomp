# 358 — movie:_prolog: the one-word residual is a narrow-store scheduler wall; landed as an asm unit

Session of 2026-10-16 (opencode/GLM continuation). Supersedes the 2026-10-16
handoff's "next candidates" entry for `movie:_prolog` (99.2188% word score),
which sat immediately behind `fn_17_7728` (landed by a later session).

## The residual, exactly (first 66 offline probes, diff count [87])

The saved best body (`.fzgx/attempts/movie:_prolog.1791747343.c`, ledger best
99.53125%, word-scored 99.21875% = 127 of 128 words) agrees with retail on
every instruction except one store opcode at word 87:

    retail  b16a 0000   sth r11, 0(r10)     (store HALF of `(bool cmp) + 0x82` into lbl_1_bss_96A)
    ours    916a 0000   stw r11, 0(r10)     (store WORD — the unit's private view `extern u32 lbl_1_bss_96A`)

The value computation above the store (`neg; or; srwi r10, r0, 0x1f; addi
r11, r10, 0x82`) and the store address (`lis r9; addi r10, r9, 0`) are
identical in both. The unit's private extern is `u32` while retail's lvalue
is a halfword — remember the definition site:
`src/rel/main_rel/_prolog.c:484` defines `s16 lbl_1_bss_96A;` and every local
reader (`!= -1`) is a signed halfword load. The movie TU only has the private
extern, and that is where the width must change.

## The wall: every spelling that widens nothing below w87 fails the schedule

Any 16-bit lvalue (`extern s16`, `extern u16`, `*(s16 *)&sym`, pointer
variable, struct view, inline helper, `(s16)` casts, `!!`, commuted compare,
union of chain lengths, statement moved after/between the three
`lbl_1_bss_7167C/80/84 = fn_5_200/220/320` stores) reproduces the `sth` but
collapses to **88.28125%** with the same 15-word diff
([74..87, 89, 90]). What moves is the address-materialisation *phase*: retail
(and our u32 body) emit the whole lis batch (w70-78: lbl_1_bss_96A,
fn_5_200, lbl_1_bss_7167C, fn_5_220, lbl_1_bss_71680, fn_5_320,
lbl_1_bss_71684) before the addi batch (w79-86); the narrow-lvalue compiles
interleave the pairs, fire the value `addi r11` at w75 and the `sth` at w86,
and swap the w89/w90 arg-store pair. Measured levers, all offline
(`oracle.compile_source` + `word_score`, no ledger checks):

| lever | score |
|---|---|
| u32 extern (baseline) | 99.22 (wrong opcode only) |
| s16 / u16 extern, all spellings | 88.28 |
| s16 + statement moved after/between pointer stores | 46.9-50.0 |
| s16 + pragma cells (lifetimes/loop_invariants/common_subs on/off each) | 88.28 |
| s16 + opt_strength_reduction off, opt_propagation off, peephole off | 88.28 / 86.7 / 33.3 |
| s16 + scheduling off | 27.3 (global reorder) |
| s16 + pointer variable (local or held across the function) | 88.28 / 6.9 |
| s16 + live chain 1/3/4 links, lab_t3/literals, 970-store dup | 88.28 / 10.0 / 54.3 |
| s16 under GC/2.0, 2.5, 2.7 | 88.28 |
| s16 under GC/1.3 | 70.5 (different structure elsewhere too) |

A standalone minimal repro (`bool store + three pointer-store pairs + one
call`, no pragma cells) shows *both* widths in the same schedule, so width
alone is not the trigger — it is width × this TU's pragma/DAG window
(`opt_lifetimes off`, `opt_loop_invariants off`, `opt_common_subs off` plus
the preceding bss_970 stores and the fn_80083BCC live chain). No C spelling
in the measured space couples them to retail's phasing. Declaration and
call-shape swaps elsewhere (161+ words of window probe grid) shift the wall
without opening it.

**If anyone revisits**: the decisive lever would be a scheduler-level
constraint (capture the retail phasing as allocator/PCode evidence the way
`fixup --capture` pins register decisions) — the fixup engine's families do
not search the store lvalue's width across object boundaries. Do not re-run
the table above.

## The landing

`uncarve rel/movie/_prolog/_prolog.c` (dropped the nonmatching carved unit)
then `asm-unit movie:_prolog` — the standing escape for walls where no C
reproduces retail. Commit `7fa25826`; gate: ninja 0, 16/16 SHA1s, lint 0
findings, 11 tests OK. Ledger status `asm`; the one-word stw→sth reading is
retained here because the C bookkeeping above is the only record of why this
function cannot be expressed in C as a per-function unit.

Trap that cost time: `compile_source` fails with
`Unexpected error in CWAddProjectEntry [3]` when the *source path* contains
`:` — copy `movie:_prolog.….c` probes to a colon-free `/tmp` path first.
Deeper capstone note: `Cs(CS_ARCH_PPC, CS_MODE_32)` silently yields nothing;
big-endian mode is required (`CS_MODE_32 | CS_MODE_BIG_ENDIAN`).

## Next in the one-word tier

After `movie:_prolog` lands, `state/one_word_tier.json` still lists
`fn_1_2D038`, `fn_1_135D7C`, `fn_1_1384C`, `fn_1_156C08` — the first three
are measured fixed points (343, 345, 347); `fn_1_156C08` (99.01%) has had no
dedicated session since its refresh.
