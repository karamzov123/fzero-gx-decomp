# The ≥95% near-match pool, censused: allocator evidence and a full deterministic sweep

Session of 2026-10-26, following `9ca99f100` (Gekko paired-single decode in
`mwconstraints`). That fix made `fzgx fixup --capture` usable on vector bodies, so
this session spent the whole pool on it once, instead of re-deriving walls one
function at a time.

## The pool

116 unmatched symbols carry a saved body at ≥95%. `fzgx fixup --min-percent 95`
over all of them compiles 3142 saved variants; `--capture` then captured 113 (three
are skipped as unsupported compilers: `GC/1.1`, `GC/1.3.2r`, `GC/2.0`).

`target_constraints.status` across those 113 captures:

| status | count |
| --- | ---: |
| `needs-web-alignment` | 68 |
| `instruction-shape` | 42 |
| `fixed-graph-hypothesis` | 3 |

Only the last group can drive `declaration_projection` at all, and all three are
dead ends for it:

- `fn_1_4B6D4`, `fn_1_4B788` — the map is the **identity** (`r6→r6`, `f0→f0`, …).
  There is no permutation to project; their two rows are the `lis`/`stwu` hoist below.
- `fn_1_3EC88` — the map is a real permutation (`r31↔r29`), and `constrain()` does
  produce a GPR selection witness, but the desired assignment is **not injective**:
  two distinct webs both want `r6`. Retail coalesces two of our values into one
  register, which no ordering of declarations can express.
  `declaration_candidates` answers `no-predicted-declaration-repair`,
  `orders: 3`, `exhaustive: True`, `best_conflicts: 2`.

## The sweep

`fzgx fixup --min-percent 95 --rounds 2 --beam 4 --max-candidates 90` over the same
116 symbols: **77,686 variants, 0 matches, 11 improved** (largest gain
`fn_1_12C110` 98.33 → 99.59). No body in the pool differs *only* by pool
relocations, so nothing was one submit away.

Closest residuals after the sweep: `fn_12_3A64` 1 row, then eleven symbols at 2 rows.

## The walls, measured

**`fn_1_1FDB0`** (46 rows). Two of them are the load slots of the third `psvec_add`:
retail puts `lfs <a.z>` in the slot before `psq_l <b.xy>` and pushes `psq_l <a.xy>`
after the `ps_add`; we do the reverse. Writing the helper with `lfs az` first and
`psq_l axy` last compiles to a **byte-identical object**, so the compiler reorders
those loads itself and the asm text order is not a lever. The remaining register
conflicts are `structural`: retail reuses one FPR for two of our webs.

**`fn_1_4B6D4` / `fn_1_4B788`** (2 rows). The whole function matches except that
retail hoists `lis r6, lbl_1_bss_4BA30@ha` **above** `stwu r1, -0x10(r1)` while we
emit it after. Ruled out, all measured:

- every installed GC compiler (1.0, 1.1, 1.2.5, 1.2.5n, 1.3, 1.3.2, 2.0, 2.5, 2.7):
  identical 2-row result; the 1.2.5 family is 61.6% for unrelated reasons.
- flag cells `-O4,s`, `-O4`, `-O3,p`, `-O4,p -schedule on`.
- pragma cells `scheduling on`, `peephole off`, `opt_propagation off`,
  `opt_common_subs on`, `opt_dead_assignments off`, `opt_lifetimes off`.
- three source forms of the first block: single-member aggregate local (saved),
  plain `f32`, and no local at all.
- TU context: compiled with a preceding `asm` function and with a preceding natural
  C function. Neither produces the hoist, so it is not findings/110's
  asm-poisoning either.

**`fn_12_3A64`** (1 row). Closes findings/379's open hypotheses:

- `void` prototype + value-carrying `return` is a hard compile error:
  `illegal return value in void/constructor/destructor function`.
- making the inlined helper return `far_z` leaves the caller's callee-saved panel
  rotated by one register (20 rows) — the value dies after the inline, so MWCC drops
  the slot that retail keeps.
- `return sfxzmv_MakeCnvZTbl(...)` folds the whole helper into the return, growing
  the frame to 0x70 and the body to 347 words.

**`fn_1_141C10`** (5 → 6 rows). The `accessor_lifetimes` block typed its first
intermediate `u16`, which emitted a spurious `clrlwi r0, r0, 16`. Dropping that
typing lifts 98.64 → 99.58 and removes the row, but the residue is the choice of
**which operand's address is materialised** (`lis`/`addi`/`lwz 0(r3)` for one, a
fused `lwz @l(r3)` for the other). Three source spellings — `A - B`, and the
two-statement `e.value` form in either operand order — compile to the same object,
so the fold is a fixed point of the same optimiser, not a source choice.

**`fn_1_A1364`** (2 rows). A single swap of `li r27, 1` with the call-result `stw`:
the same hoist/sink class.

## Consequence

Nothing in this pool is reachable by repair, capture or projection as the tooling
stands. The residuals are the two fixed points already characterised in
`REGISTER_REPAIR.md` (scheduler slot placement, and which operand the folder
materialises) plus allocator register *reuse*. The 95% of unqualified functions that
differ structurally are ordinary decompilation work and remain the real queue.

## Operational note

A corpus sweep itself stays read-only outside `.fzgx/`: `fzgx fixup` does not carve,
it only reads `unit_of()` and compiles uncarved symbols into scratch objects
(`oracle.check`'s uncarved path), so `--output` under `.fzgx/` touches no tracked
file. That matters here because a separate import process was committing `src/` and
`config/` changes in this same checkout throughout the session (`5c69914df` landed
mid-run), so `git status` has to be read before attributing any tracked-file change
to the sweep.

That commit also left the tree's build red, independently of this work: it
registered the unit `rel/main_rel/game/fn_1_3181C.c` in `splits.txt` and
`units.json` with a poolfix retarget list but no C source. `configure.py` then
generates the `// fn_1_3181C: not matched yet` stub, mwcc compiles it to an empty
object, and `tools/fzgx/poolfix.py` exits 1 because every requested retarget is
skipped. 123 other stub units build fine, so the rule is that a registered unit
with retargets needs a source; this one has none.
