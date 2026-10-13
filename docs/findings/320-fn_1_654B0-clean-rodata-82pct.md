# fn_1_654B0 (effect): clean-rodata version reaches 82.3%; pool-primer inadmissible

Selected a carved-but-never-written unit (856 B, `main_rel/rel/main_rel/effect`). A prior session
reached 96.96% but only via a pool-primer scaffold (finding 299 — inadmissible). No claims remained;
no fleet settings were changed and no canonical gameplay source was submitted. Only `.fzgx` state and
the unit body were touched.

## The pool-primer trap

The prior 96.96% attempt (`fn_1_654B0.1790952858.c`) used `#pragma section code_type ".fzgxpool"`
with ~200 lines of `fzgx_pool_prime` stubs and `fzgx_pool_table` arrays to force float constants into
rodata. That is the inadmissible pool-primer family. The actual function body (lines 217-326 of that
file) is what this attempt reproduced cleanly.

## Clean approach: extern const struct for all rodata constants

Retail loads every float constant from `lbl_1_rodata_2950` via `lfs fX, offset(r8)`. The clean
version declares an `extern const struct` with the exact field offsets and references
`lbl_1_rodata_2950.unk_XX` for each constant. This produces the same `lfs` instructions without any
pool primer.

Key idiom discovered: `(f32)(s16)value` (not `(double)`) triggers the xoris/lfd/fsubs/fctiwz
conversion sequence that retail uses for the s16 angle fields. The `(double)` cast forces
`fsub`/`fmul` (double precision) which does not match.

## Residual: register allocation, ~77 rows

The clean version reaches **82.3% raw** (up from 73.3% on the first structural attempt). The body is
at `.fzgx/attempts/fn_1_654B0.best.c`
(SHA-256 `64dfabc8192d5b63...`, full hash in `.fzgx/attempts/fn_1_654B0.best.json`).

Remaining diffs are predominantly `regalloc` (register number swaps: r8 vs r4 for the pool pointer,
r7 vs r8/r9 for 0x4330, f2 vs f3 for temporaries). The instruction sequence and operand structure
match; only the register colouring differs. This is the documented register-allocation wall.

Specific structural items that were probed but did not improve the score:
- `#pragma fp_contract off` — prevents `fmadds` fusion but scored 77.7% (worse)
- Explicit `* unk_5C / unk_5C` for the 255/255 normalization — scored 77.7% (worse)
- Swapped operand order (`unk_54 * (f32)p->unk_10` vs `(f32)p->unk_10 * unk_54`) — no improvement

Not an exact C match. Resume `.fzgx/attempts/fn_1_654B0.best.c`, compiler GC/1.3.2, no extra
command-line flags. The pool-primer version at 96.96% is inadmissible per finding 299.
