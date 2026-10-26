Starter notes on CodeWarrior for GameCube 1.x codegen at `-O4,p`. Grow this
file from what actually unblocked functions; keep each item one or two lines.

## Laws to apply first (probe-verified, 2026-09-15)

- **Compound assignments affect induction lifetimes.** `a[n - 2] -= rhs` closed
  `fn_1_F4F08`'s 39/340 register differences under GC/1.3.2. Contract only pure
  repeated lvalues at the RHS root: `x = x - a + b` is not `x -= a + b`.

- **Paired-single vectors**: `psq_l f, off(rN), 0, qr0` / `psq_st` / `ps_sub` / `ps_add` /
  `ps_muls0` / `ps_madds0` / `ps_merge00` in retail are inline-assembly helpers. Write
  `#include "psvec.h"` and call `psvec_sub(a, b, out)`, `psvec_add(a, b, out)`,
  `psvec_scale(a, s, out)`, `psvec_scale_add(acc, v, s, out)` (out = acc + v*s),
  `psvec_sub_scale_add(a, b, s, d, out)` (d = a - b; out = b + d*s) and
  `psvec_set(out, z, y, x)` (note the z, y, x order) with `void *` addresses such as
  `&v->x`. Never write the three scalar component statements: MWCC can only produce
  the indexed `psq_lx` forms from C, so scalar or `__vec2x32float__` code can never match.
  Pass loads straight as `psvec_set` arguments; loading them into locals first changes
  the registers.
- **Fused multiply-add**: `a + b*c` in one expression gives `fmadds`; a product held in a
  temporary or wrapped in `(f32)` stays `fmuls` + `fadds`. Only the product that is a
  direct operand fuses: retail `fmuls; fnmsubs` for `x*y - z*w` is `(f32)(x*y) - z*w`;
  retail `fmuls x; fmadds y; fmadds z` for a squared length is `(f32)(x*x) + y*y + z*z`.
- **Signedness**: `cmpwi`/`lha`/`extsh`/`srawi` need a signed operand type (cast or
  declaration), `cmplwi`/`lhz`/`clrlwi`/`srwi` an unsigned one; flip the operand of that
  statement, not unrelated locals. `cmpw` vs `cmplw` on the same operands is a type error,
  not a strength-reduction difference.
- **Prologue form counts live values.** Retail uses `bl _savegpr_NN` far more often than
  `stmw`/`lmw` (21:5 across a 400-function matched sample), so a `stmw r27, 0x1c(r1)` where
  ours emits `_savegpr_27` is not a formatting difference -- per the rule above it says retail
  keeps **five or more** values live across every call in the body and ours keeps fewer. That
  is a control-flow-shape fact, not a register one: it usually means retail shares one loop
  across several call sites where ours repeats near-identical calls, each of which frees its
  registers at the call. `fn_12_23410` is the worked example (docs/findings/285).
- **Locked cache**: `lis rX, 0xe000` + `lfs f, 0xc(rX)` is `*(f32 *)(0xE0000000 + 0x0C)`
  (the current matrix); do not invent a symbol for it.
- **Evaluation order at a call**: a value produced by a call and consumed in an expression
  is evaluated first when written inline; holding it in a local moves the call and can
  swap `mullw`/`add` operands (fn_1_76704).

- **Loop pointers**: a pointer initialised straight into its callee-saved register
  (`addi r30, r3, sym@l`, no copy) and stepped by a constant is a strength-reduced
  induction shadow of an indexed access: write `base[i].f` or `*(T *)((u8 *)base + i * K + off)`
  with the loop counter, never `p = base; ... p = (T *)((u8 *)p + K)` (that lowers as
  `addi r0, ...; mr r30, r0`). Likewise `off += K` against `i * K`. Shadows are numbered
  above every declared local and coloured first (r31 downward); a constant base that
  retail keeps above them (`manager = lbl + 0x50000` in r31 with the induction shadows in
  r30/r29) is itself a shadow: hold it in a one-member struct (`struct { u8 *value; } mgr;`)
  so its load is the CSE'd value (fn_10_7130, capture-verified).

- **Literal pool base** (383 unmatched functions carry a private `lfd @N` where retail has
  `lfd f, off(r31)`): MWCC lays every `.rodata` object *defined in the unit* (the compiler's own
  float/double literals, including the 2^52 int-to-float constant, `static const` tables) in one
  section in definition/first-use order and, once a base register holds one of them, addresses
  the rest by displacement. An `extern` view of retail's pool can never join that base: the
  compiler's constants stay in the unit's private pool. So the whole retail pool region has to be
  defined inside the unit (`native_pool_objects` + `shared_pool_primer`). Two rules of that
  definition, probe-verified 2026-09-16: a `const f32` scalar definition folds into a literal
  (fine, it dedupes onto the primed slot) but a `const u32` scalar folds into `li` — integer pool
  words must be one-element arrays read as `[0]` (retail's `lwz r0, 0x490(r31)`); and the
  oracle's pool byte comparison must stop at retail's last displacement (the next word belongs
  to the following object). Refinement (probe `head.c`, 2026-09-16): the shared base is the
  *section symbol* `...rodata.0`, which MWCC CSEs across a function's own private literals; a
  user-declared `const` object (even `static`, even one defined in the unit) is addressed by its
  own symbol and never joins that base. So retail's `lfs f, 0x3c(r30)` reads are plain float
  literals in the source (`5.0f`), not fields of a pool object: bodies must spell pool reads as
  native literals (`native_pool_literals`), integer-read words as primer table entries, and the
  primer fixes the first-use order. `#pragma pool_data on` produces the same base-relative
  shape for a unit's own data but is not what retail used (retail leaf functions keep
  per-literal `lis`).

- **Parameter above a local** (capture-verified on fn_1_A358C, landed): parameters are
  numbered below every declared local (`arg0` is vr32 under every declaration order), so a
  parameter that retail keeps in a callee-saved register *above* a local's (`mr r28, r3` with
  the loop counter in r27) is a local copy of the parameter, `s32 id = arg0;`, declared where
  the register order puts it (after the locals retail colours above it). The copy is folded by
  copy propagation unless the body carries `#pragma opt_propagation off` or the copy has its own
  lifetime; 488 stuck bodies show the retail shape, 136 have ours below retail. Evidence family
  `retail parameter copy` (`fixup_evidence.parameter_copies`) reads both prologues and ranks the
  predicted position first; it reproduced every retail parameter register in 85 of 137 bodies.
- **Survivor order** (fn_1_76504, replay-verified): among callee-saved webs the first claims are
  not by vreg number but by *survival*: a web whose total interference degree stays >= K=29
  through simplification pops first (r31 downward, longest survivor first); only then does the
  descending vreg sweep colour the rest. A retail parameter in r28 above a constant-address
  shadow (r27) with identical code means the parameter interferes with ~4 more webs in retail
  (a longer lifetime or more temporaries in its range); declaration order and the struct
  wrapper cannot change it. `simplify_replay.py DIR 0001 32:+6` answers "how much more degree".
- **Lifter pool reads** (fn_1_53830, 405-body sweep 2026-09-16): the byte-addressed forms
  `*(f32 *)((u8 *)pool + 0x140)` and `*(u32 *)((u8 *)pool + 0x138)` through an alias of the pool
  object are pool reads too; `pool_scalar_reads` turns the float ones into native literals and
  the primer turns the integer ones into table entries. Each integer word the function reads
  must be its own one-element table object: `table[1]` materialises the table's address where
  retail has `lwz r0, 0x13c(r29)`. Native literals + primer over the 405 unprimed
  private-literal bodies: 5 matches, 258 improved (up to +31 points), 83 regressed, 97 s.
  The regressions were reads retail makes by the literal's own `lis`/`lo` pair or as a
  materialised single address (`addi r5, r3, sym@l; lfs f0, 0x0(r5)`): the extern declaration
  already reproduces both, and a native literal pools them behind a base instead. Only reads
  through a base that retail reads at several offsets convert (`memory_loads` records the
  form; `pool_scalar_reads` keeps multi-offset pool bases).

## Selection panel evidence (2026-09-15)

- Four-byte color structs reproduce pooled `lwz` initializers; scalar `const u32`
  colors can fold into immediates. Automatic struct initializers keep per-iteration copies inside loops.
- Separate initialized data objects establish MWCC's native data base. A pointer
  to an extern aggregate can change base setup and address lifetimes despite identical field offsets.
- Complete nested calls before binding a localized string table when retail does;
  an inline indexed lookup closed the last four register differences in `fn_10_1C2D8`.
- DTK `pad_` objects contained 93 of this panel's 867 data pointers. Pool proof
  must inspect their relocations, including unused slots, rather than assuming zero padding.
- Split grouped declarations before allocation analysis. On `fn_10_1D314`, this
  preserved the code and exposed ten locals; the resulting partial repairs remain unmatched.

## General observations

- Register allocation follows declaration order of locals and argument order.
  Reordering declarations moves registers; extra temporaries can force a spill
  or a different register.
- `int` vs `u8/s16` locals change sign/zero extension (`extsb`, `extsh`,
  `rlwinm ... 0xff`). Match the extension you see.
- `-inline auto`: small `static` functions in the same file are inlined into
  callers. If retail has the body inline, define the helper `static inline` in
  the same unit.
- Float compares: `fcmpu` + `cror` patterns come from `<=`/`>=`; a plain
  `fcmpo` from `<`/`>`. `frsp` appears when a double is narrowed to float:
  use `f32` literals (`1.0f`) to avoid double promotion.
- `switch` with dense cases produces a jump table (`.data`); sparse cases
  produce compare chains. A `default` placement can change the layout.
- Struct field access uses the field offset directly in `lwz r, off(base)`;
  when you see an offset, add the field at that offset in the struct.
- Loops: `bdnz` implies a counted loop the compiler could prove; `for (i = 0;
  i < n; i++)` with `n` loop-invariant. `mtctr` at loop entry.
- `stwu r1, -N(r1)` frame size N and `_savegpr_NN` tell how many non-volatile
  registers are live across calls: roughly how many values survive a call.
- String literals go to `.rodata` (`-str reuse` pools identical ones); float
  constants to `.rodata` in RELs (`-sdata2 0`) and `.sdata2` in the DOL.
- `lis/addi` (`@ha/@l`) is a normal address materialisation, not a constant:
  declare the symbol and take its address.
- A value loaded into `r4` (or `r5`...) right before a `bl`, while `r3` is left
  untouched, means the callee takes the caller's first argument as its own
  first parameter and the loaded value as the second: write
  `callee(arg0, table[idx])`, not `callee(table[idx])`. Register choice here is
  a signature question, never a compiler quirk.
- The same in reverse: if you need a parameter in `r4`, add the preceding
  parameter to the signature even when the function body ignores it.
- A missing return can look like register allocation: `fn_80069AE0` needs the
  loaded flags in r3 on one path and the callee's result on the other. Returning
  the flags after both paths incorrectly keeps them live across the call.
- (tooling, not codegen) RELs are linked without `-strip_partial` because retail
  kept unreferenced functions; with stripping on, a carved function nobody
  references vanishes from the link and every REL importing later symbols
  fails its hash.
- A value used both before and after a call is loaded once into a local (a
  non-volatile register, `r31` down); reloading it after the call gives a
  second `lwz` retail does not have. The reverse too: two loads in retail mean
  two expressions in the source, not one local.
- Argument materialisation follows source order: `f(1, 15, g)` loads `g`
  after `li r4, 15`; if retail loads `g` first, `g` came from a local set
  earlier in the function.
- Same asm modulo two swapped `li`/`lwz` rows is never a compiler quirk: it is
  statement order or an intermediate local.

## Rules the lifter learned (each verified byte-exact on retail functions, 2026-09-08)

- `p = (struct S *)&sym;` keeps the address in a saved register across calls; a plain
  `&sym` or `sym.field` is rematerialised (`lis/addi`) after every call. When retail
  holds a global's address in r31/r30 and uses `off(r31)` after calls, write the cast form.
- A loaded value that is read again after a store to the same location lived in a
  local: `v = x; x = v + 1; f(v, &x)`. A plain `x++` reuses the register instead.
- A value used twice (two reads of the same register before it is rewritten, a call
  argument plus a return, a field plus a compare) lived in a local; recomputing the
  expression twice gives extra loads or a different register.
- A value computed into a saved register (r14–r31) before a call and used after it is a
  local assigned before the call.
- The same expression passed as several arguments of one call (`f(v, v, v)`, three
  `fmr` from one `lfs`) is a local assigned right before that call, not a CSE across
  calls (which would land in f31 with `stfd f31` saves).
- Call arguments are the argument registers written since the previous call; an
  untouched r3..r5 followed by a temporary in r6 means the function's own first three
  parameters are passed straight through: `void f(a, b, c) { g(a, b, c); }`.
- `crclr cr1eq` (`crclr 6`) right before a `bl` marks a variadic callee.
- A variadic entry saves r3-r10 and conditionally f1-f8 under `bne cr1`; these are
  the argument-save area, not sixteen fixed parameters. `fn_1_4AE0C` matches with
  `(const char *format, ...)`, a 512-byte character buffer and `__builtin_va_info`.
- Address arguments need pointer-typed prototypes; `(u32)&x` as an argument is hoisted
  into a saved register, `&x` with a `void *` parameter is recomputed per call.
- An address-taken scalar local stays a scalar (`f(&x)` recomputes `addi rN, r1, off` at
  each use); an array decays once into a saved register. A `u8` buffer is 16-byte
  aligned in the frame, a `u32` array or a struct is not.
- When fields match but a struct-copy loop starts four bytes early, check for a
  fake leading field plus an array-minus-four pointer. `fn_1_133BD8` needs an
  aggregate local with the prefix removed, preserving the union's copy extent.
- Signedness of a compare comes from the operand types: `cmpwi` needs a signed
  operand, `cmplwi` an unsigned one, whatever the width.
- Unsigned division by a constant: `mulhwu` with a magic multiplier, then
  `subf/srwi 1/add/srwi s` (or just `srwi s`); a following `mulli` by the divisor and
  `subf` is the remainder. Write `x / 360`, `x % 360`; never the magic number.
- int → float: `lis 0x4330; stw hi; (xoris x,0x8000;) stw x; lfd; fsub(s) <2^52 constant
  from the pool>` is `(f32)(s32)x` (with the xoris) or `(f32)(u32)x` (without). The
  constant is a pooled `lbl_*_rodata_*` symbol; float → int: `fctiwz; stfd; lwz low` is
  `(s32)f`.
- A struct assignment of 8×N bytes is a counted loop: `li rN, N; mtctr; lwz/lwzu/stw/stwu
  … bdnz` with both bases pre-decremented by 4. Write `dst = src;` with a struct of
  that size; never a loop.
- A `while` loop compiles to a jump to the test at the bottom; loop variables live in
  locals initialised before the loop. Registers assigned inside an `if` block and read
  after it are locals too; a flag set to 0 before an if-chain and to 1 inside is a
  local, not a constant.

## What closed the agents' plateaus (spelling search over 1,285 saved bodies, 2026-09-08)

Each line is a family that turned a 60–99% body into a match; the count is how many.
- Declaration order of locals (5) and moving one local into an inner block (2): the
  allocator follows declaration order, so a swapped r30/r31 is a swapped declaration.
- One extra unused trailing parameter (3): a function that ignores an argument still
  declared it; add `u32 unused` before rewriting anything else.
- Hoisting a call argument into a local right before the call (4), or inlining a
  single-use temporary (4): `f(a, p->x)` vs `t = p->x; f(a, t)` moves the load.
- Signedness of a local (3), a parameter (1), a struct field (2): `s32` vs `u32` changes
  `cmpw`/`cmplw` and `extsh`/`rlwinm`, nothing else; flip one at a time.
- `x == 0` -> `!x`, `x != 0` -> `x` (2), and commuted compare operands `2 == x` (2):
  the branch is the same, the register that holds the constant moves.
- Two adjacent statements that share nothing, swapped (2): free order, different
  scheduling.

## Large saved bodies (2026-09-14)

- `fn_8_1394` (GC/2.0): assigning the zero operand inside a floating comparison
  gives it a separate scalar lifetime and reproduces the retail operand order.
- `fn_1_988DC`: completing a dead integer counter's square immediately after its
  definition changes the later register interference. Its floating clamp also
  needs the retail unordered branch behavior; positive nested tests and a
  min/max expression are not interchangeable for NaNs.
- `fn_1_13C1A0`: a 200-byte stack copy is ten rows of five words. Recovering the
  row shape reproduces the address arithmetic that a flat guessed table misses.
- `fn_1_13D460`: placing the count assignment before packet setup and forming
  the strip base plus width-times-index before the final displacement reproduces
  the allocation and operand order without declaration permutations.
- Shared BSS section bases do not emit relocations to every named object. Bind
  split definitions by measured module, section, address and owner bounds. Give
  interior pieces canonical `OWNER__fzgx_offset_HEX` names. Private primer storage
  can disappear only after its section base is proven and no live relocation
  reaches the remaining storage. This linked the 6,608-byte `fn_1_AD264`.

## Shared SDK state (2026-09-15)

- A code-complete function can still have a wrong unused data prefix. In VI
  configuration, reconstructing the retail prefix and symbolic switch pointers
  closed two unresolved base relocations without changing an instruction.
  Verify pointer relocation kind, module, section and destination as well as
  initialized bytes. A size-zero section symbol is not a relocation-free object.
- Keep section anchors that already have verified bindings. Rename remaining
  native BSS members from their measured positions, including SDK layout gaps.
  Missing BSS symbols can hide complete typed objects: the OS inquiry block and
  DVD workaround alarm/buffers accounted for 112 bytes of shared storage.
- MWCC emits unreferenced BSS definitions in reverse declaration order. Data-only
  grouped imports must reverse definitions and still prove every object offset,
  section extent and alignment. First-use order in a function primer is a
  different case; put such primers explicitly in `.fzgxpool`.
- MWCC numbers native section bases by earlier functions' first accesses,
  independently of the object ordering within each section. An SDK BSS primer
  alone can therefore produce the right offsets but swap every `.data`/`.bss`
  base register. In `SIInterruptHandler` (GC/1.2.5n), priming the three existing
  initialized objects before the BSS primer closed all 15 instruction-word
  differences. Keep both primers in discarded `.fzgxpool`, preserve the data
  definitions and their section order, and require the existing byte/relocation
  proofs and all 16 hashes. The `initialized_base_order` fixup family and
  `state/repairs/sdk-native-section-base-order.json.gz` reproduce this repair.
- Preprocessed C may contain spaces around `->`. Normalize the member-access
  token before the layout parser checks whether a base pointer escapes.

## Lost switch cases and string objects (2026-09-15)

- An integer interval recovered as `if (value < 2 && value >= 0)` can be a
  switch with cases 0 and 1. MWCC retains a different conditional/unconditional
  branch pair for the switch. Restoring contiguous cases exactly matched
  `fn_8002A74C`, `fn_8006BA74` and `fn_12_3256C`. This is a source control-flow
  distinction; disabling dead-code elimination did not repair these examples.
- A shifted sign-bit test can be an incorrectly lifted rotated low-bit test.
  Recover the retail `__rlwnm(value, amount, 31, 31)` expression before changing
  register allocation. This closed `fn_1_7F3AC`, `fn_1_557C4` and `fn_1_55A84`.
- Error-string pools need separate native string objects. A pointer to one
  external character array changes both base initialization and offset-zero
  address formation. Recover each string, its terminating zero and measured
  padding, and reject any intersecting data relocation. This closed
  `fn_12_34390`, `fn_12_346BC` and `fn_12_34798` with the original compiler.
  The repair archive retains all nine inputs, outputs and compiler settings.

## Root causes measured over the whole stuck corpus (2026-09-15)

`fzgx stuck --min-percent 50` over 1,962 saved bodies, counting mnemonics per side
without row alignment (`retail - ours` net rows):

- `lis` -2073 / `addi` +1622 (731 functions): the TU section base and shared literal
  pool (existing primer/layout families).
- `psq_st` +608, `psq_l` +579, `ps_madds0` +148, `ps_sub` +111: 164 unmatched
  functions (244 KB) use paired-single vector kernels. **MWCC's `__vec2x32float__`
  only emits the indexed `psq_lx`/`psq_stx`; the displacement form `psq_l f, 0x10(r29)`
  comes only from inline assembly inlined into the caller.** `include/psvec.h` holds
  the helpers (sub, add, scale, scale_add, sub_scale_add, set), each byte-exact on
  retail: fn_1_FB50 and fn_1_7EB8C match with one call. An inlined asm block's
  register parameters take f0, f1, f2 in declaration order, which is why `psvec_set`
  declares (dst, z, y, x): retail merges x from f2 with y from f1 and stores z from
  f0. Loads passed straight as arguments keep that order; loading into locals first
  changes it (fn_1_2A694). The lifter recognises the kernels (`psvec.kernels`) and the
  engine rewrites per-component statement triples (`paired_vector_kernels`).
- `fmuls` +615 / `fmadds` -525 / `fadds` +318 (251 functions): retail keeps products
  separate where ours fuse. Probe law (GC/1.3.2): `a + b*c` fuses; a product held in a
  named temporary or wrapped in an explicit `(f32)` cast does not (`t = b*c; a + t`
  and `a + (f32)(b*c)` give `fmuls; fadds`), and only the multiply that is a direct
  operand of the add/sub fuses: `(f32)(a*b) - c*d` gives `fmuls; fnmsubs`, `a*b - c*d`
  gives `fmuls(c*d); fmsubs`. `x*x + y*y + z*z` accumulated from the first product
  (`fmuls x; fmadds y; fmadds z`) is `(f32)(x*x) + y*y + z*z`; the plain expression
  materialises `y*y` first. Family: `fusion_control`.
- `cmpwi` +764 / `cmplwi` -443 (460 functions) and `lha` +93: our bodies are
  unsigned where retail is signed. With `-sym on` MWCC emits a DWARF 1 `.line` table
  and byte-identical code, so every differing row names its statement
  (`tools/fzgx/linemap.py`); `attributed_type_flips` flips the casts and declarations
  of that statement's operands toward retail's signedness, `attributed_inlines` folds a
  single-use local read there back into its use (fn_1_76704: the call evaluated
  inside the multiply fixes `mullw` operand order), and the engine tries candidates
  that edit implicated statements before the rest.
- Epilogue `lwz r31; lwz r0` against `lwz r0; lwz r31` (10 functions): the scheduler
  hoists the LR reload only when nothing ties it; same instruction stream, different
  DAG, not closable by flags (`-O3` disables scheduling entirely).
- No other retail-only opcode family above 40 functions exists; the rest of the
  residuals are register allocation, frame layout and control-flow shape.

## Packed-time swaps and signed remainder (2026-10-19)

- `fn_1_2E3B4`'s packed-time difference keeps the smaller timestamp in its
  first parameter: `if (first > second) { larger = first; first = second; }
  else { larger = second; }`. Separate minimum/maximum locals change its
  copy webs. The previous high-scoring seed left the larger value uninitialized
  on one branch; reproducing missing instructions from that seed was not a match.
- The same function's automatic six-element penalty table is
  `{1000, -300, -400, -500, -500, -500}`. Priming those bytes separately and
  priming the trailing floats moved the real initializer past its retail pool
  position. Removing those redundant primer entries let the initializer and
  following literals establish their own measured order; all 349 words matched.
- In `fn_1_142BDC`, initialize the original x-coordinate before either display
  branch. Expressing the ordinal column as `(s32)index % 2`, rather than a
  manually expanded sign/xor/subtract sequence, reproduces the temporary ordering
  around the adjacent integer-to-double conversions. Direct x/y/z field
  assignments plus the signed remainder closed the final eight register-only
  differences; all 428 words matched under GC/1.3.2.

## Preserve measured pool primers during expression repairs (2026-10-19)

- `fn_1_1188CC` exposed a repair-order defect: float binding replaced literal
  assignments inside `.fzgxpool` primers with external field reads. Those reads
  no longer emit the constants that establish the measured pool order. The
  variant that retained a local pool pointer also used that pointer from the
  separate primer functions, where it was out of scope.
- Float repairs now preserve section-pragma regions and explicitly attributed
  primer functions, including constant tables inside the pragma regions. The
  real-function reproducer previously rewrote three of its 42 primer functions;
  the repaired candidates preserve all 42. The pointer-based candidate now
  compiles, but still has 44 differing rows and is not an accepted match.
- Read retail comparison idioms as operations before repairing allocation.
  In `fn_1_9C724`, `xor; cntlzw; slw; srwi` implements unsigned `value > 1`.
  Writing that comparison removes a manual C shift whose count becomes 32 at
  equality. This repaired two rows, but the function remains unmatched.

## Inlined-helper returns and the `cond; b target` branch pair (2026-10-19, fn_1_14F608)

- Retail's `cmp; bne +8; b <tail>` (a conditional branch whose taken path is a
  one-instruction unconditional jump to a shared tail) is the codegen of an
  **inlined helper's `return`**, not of a `goto`/`break` in the caller: the
  helper's `return expr` lowers to a jump to the caller's join block and the
  condition is emitted branch-over-branch because branch folding does not run
  across the inline boundary. ~113 sites across all modules carry the pair;
  matched exemplars: `fn_1_14F608` (landed 100% this way), `fn_12_2396C`'s
  inlined `find_start` (`if (fn_12_67A4(p) == 0x10000) return p;`) and
  `fn_8006A768`'s one-level self-recursion inline.
- Consequence: when a near-match differs **only** on such a pair (ours
  `beq <tail>` where retail has `bne +8; b <tail>`, all other words identical
  modulo the shift), stop searching loop spellings — `for`/`while`/`do`,
  `!=`+`continue`, empty then-arm, `-opt` levels and pragmas all fold to `beq`
  (measured: the branch shape is invariant for every spelling tried on
  `fn_1_14F608`). Move the search loop into a `static inline` helper and let its
  `return` feed the caller's tail.
- Keep the helper's result **inside the call expression**
  (`return base + find_ordinal(table, (s16)arg0) * 0xb4;`). Binding it to a
  local first (`index = find_ordinal(...); return base + index * 0xb4;`) keeps
  the branch pair but swaps the value/index registers and adds an `extsh`
  (measured 86.67% vs 100% on the same body).
- The helper must be `static inline` **in the unit**; a plain extern call in a
  separately compiled unit cannot be inlined by the oracle, so the body must
  carry the definition for `write-unit`/`check` to reproduce the inline.

## Compound `||` guards produce the same pair without a helper (2026-10-19, fn_1_426C)

- The `cond; b tail` pair is **not helper-specific**. A compound `||` guard whose
  second operand returns lowers the same way: with
  `if (arg0 < 32 || node->field_0 == 0) { return; }`, operand A's true path branches
  straight to the tail (`blt 0x88`), and operand B's true path — the shared return
  label — is materialised as an explicit jump with the condition branching over it
  (`bne 0x44; b 0x88`).
- Measured on `fn_1_426C`: two separate guards
  (`if (arg0 < 32) return; if (node->field_0 == 0) return;`) give 97.3% with the
  folded `beq 0x84`; merging them into one compound condition reproduces retail
  word-for-word (41/41). Matched reference in the same shape: `CARDCheck`
  (`if (result < 0 || &xferBytes == 0) { return result; }` → `blt 0x40` then
  `bne 0x38; b 0x40`).
- So for a pair-only near-miss, try both spellings before moving on: the inlined
  helper from the section above, and the compound `||` guard with the shared
  `return` tail. The pairs survive because branch folding does not run across the
  materialised join label in either case.
- `fn_1_1420E0` is another measured closure (62/62 instructions):
  `if (flag >= 1) { if (bits & mask) { ... } }` folds the second guard into
  `beq tail`. The equivalent early return
  `if (flag < 1 || !(bits & mask)) return;` retains retail's `bne body; b tail`.
  Keep the original value/mask calculations and compiler profile; this repair
  needs neither a helper nor a code-generation carrier.
- `#pragma opt_propagation off` was required for the landed `fn_1_426C` body: with
  propagation on, MWCC copies the loaded global into a fresh temporary
  (`lwz r5, ...; mr r31, r5`) instead of keeping the global load's web.

## Pool `L` rows: the whole pool region must be byte-identical (2026-10-19, fn_1_FE644)

- A body whose instruction rows all match can still report `no match` when the two
  base rows (`lis rB, <pool>@ha; addi rB, rB, <pool>@l`) are `L` rows: ours reaches
  the private pool through the anonymous section symbol (`...rodata.0`), retail
  through the named pool object (`lbl_1_rodata_76A8`).
- `_pool_rows` accepts the base rows as pool rows only when the bytes from our pool
  start to the last pooled literal equal retail's bytes at the named object for the
  **whole region**. One wrong initializer word keeps every literal read an accepted
  `p` row but fails the base proof, so `real_rows > 0` and the unit is no
  `MATCH (pool)`. The guessed constant value is codegen-neutral, so objdiff stays
  green while the pool byte is wrong.
- Read retail's actual bytes (`project.symbols(module)[name]`, `_raw_section`,
  `_section_base`) before choosing the constant, not after. `fn_1_FE644`'s
  `lwz r0, 0x4(r31)` reads zero, not the fleet's guessed `0x000000FF`; with the byte
  fixed the whole 0x28-byte pool maps to `lbl_1_rodata_76A8`
  (`lbl_1_rodata_76A8=initializer[40]`) and the unit lands as a pool match.
- A zero-valued `static const u32 arr[1] = {0};` read as `arr[0]` still emits the
  pool load (`lwz r0, 0x4(r31)`), it does not fold to `li` — verified word-for-word
  on the landed `fn_1_FE644` body.

## Byte swaps, add association and template ports (2026-10-19, 22 landed)

- **u32 byte swap without `stwbrx`.** GC/1.3.2 turns any byte swap it recognises (all
  permutations, masked or not, through inlines, locals or casts) into `stwbrx` when the
  result is stored. Retail's `rlwinm 8,8,15; rlwimi 24,0,7; rlwimi 24,16,23; rlwimi 8,24,31`
  + `stw` chain is a swap whose low half is narrowed first:
  `u32 low = (u16)value; return (low << 24) | ((low << 8) & 0xFF0000) | ((value >> 8) & 0xFF00) | (value >> 24);`
  Closed the six movie header getters (`fn_12_321E8` ...) and `fn_12_31CA4`.
- **Add association is a tree shape.** MWCC reassociates flat sums; the retail add order
  survives only as parentheses. Compile every binary tree of the terms in one file and
  word-compare (30,240 trees for six terms compile in seconds): the drop-frame timecode
  converters are `(h * K1 + m * K2 + m / 10 * 2 + s * fps + (frames + extra)) * 1000`.
- **Dual induction variables are lifter output.** `src = base + 0x28 + i; ... i += 2; n += 1`
  is retail's strength-reduced shadow of `base + 0x28 + n * 2`; writing the scaled index
  reproduced the `mr`-initialised offset and its register (`fn_4_D420`).
- **Square in place before the next constant.** `inv = 1 - t; inv *= inv;` then
  `scale = 1 + (f32)(2 * t)` gave retail's float register reuse in `fn_14_D600`; the
  order of the 0.07f store relative to `scale` decided the remaining two rows.
- **A mask local fixes bit-clear scheduling.** `u32 mask = 0x80000000 >> n; word &= ~mask;`
  put the address before the shift amount like retail (`fn_1_F9888`).
- **Templates:** option/title/sel share menu code (`fn_4_D420` = `fn_8_FC5C` =
  `fn_10_25888`), and spline/pilotpoint have getter/setter families. An opcode-sequence
  clone scan (unmatched vs matched, then unmatched vs unmatched) found 9 of today's
  matches; porting the matched sibling and renaming symbols beat repairing the saved body.
- **Unsolved here, measured:** GC/1.3.2 -O4 folds a held member pointer (`p = &s->m` kept
  in a saved register, `fn_12_2E7C8`, `fn_12_2E8C8`) in every form tried (inline, casts,
  arrays, all opt pragmas); only -O2 or GC <= 1.2.5n keep it, and those change the rest
  of the function. `fzgx search` can "match" by inventing a return value (`fn_1_4DE04`
  returned its loop pointer); reject that and check what search changed before `verify`.

## Movie bit-reader fields and consumed chunks (2026-10-19)

- `fn_12_9D08` and `fn_12_8BD8` decode the same packed run/level table. The
  secondary table index is `code >> 6`. Its `lhax` offset is the retail
  `rlwinm ...,27,5,30`; using the low five bits or adding another pointer
  indirection changes the decoder's meaning.
- Keep the packed run-code byte separate from the decoded run:
  `u8 run_code = (entry >> 2) & 0xFF; run = run_code >> 2;`.
  GC/1.3.2 emits the retail eight-bit extraction followed by `srawi ...,2`.
  A single reused signed local chooses a different intermediate register.
- Stuffing (`0x22`) and escape (`0x23`) codes retry inside the decode loop,
  after the original block index is saved. Retrying the outer delimiter check,
  or saving the block index again after an escape, changes behavior.
- `SJCK.len` is signed. The split size is the consumed prefix,
  `position - chunk.data`; the refill test uses `chunk.len - consumed`.
  Reversed subtraction can look like register allocation in an object diff.
  Trace both `subf` inputs before changing declarations or compiler settings.
- The continuation variant consumes exactly one bit after each block and exits
  when it is zero. Both variants preserve the residual bit offset with `& 7`.
  Shared `SJ`/`SJCK` declarations and ordinary field accesses match without
  volatile qualifiers or identity read wrappers. Both functions passed the
  complete retail hash gate; sequence/slice-header frontiers remain partials in
  `state/repairs/movie-bitreader-frontiers-20261019.json.gz`.

## BSS primer arrays and symbol extents (2026-10-23)

- A primer-only array spanning several retail objects cannot bind as one
  subobject. Split it at measured symbol boundaries, preserving its element
  type and first-access order. Each resulting definition must independently
  fit a named object in the same module and BSS section. Unknown intervals
  are not proof of padding. `fn_3_83CC` needs the original 16-byte array split
  into the retail 4-byte and 12-byte objects.
- MWCC four-aligns file-scope byte arrays and byte-only structs. At an
  unaligned boundary, scalar elements can occupy the leading bytes before
  the next array. `fn_17_3410` needs byte scalars at offsets 0xD6, 0xD7,
  0xFA and 0xFB; an array can then begin at 0xFC. The whole function and
  linked targets must still match after the compiler measures this layout.
- Do not widen a retail symbol merely to fit a candidate definition.
  `fn_1_83070` provides direct extent evidence: four explicit byte stores
  cover `lbl_1_bss_6D868` through +3, and the next symbol starts at +4.
  Its inferred one-byte size was corrected to four, with the retail
  instructions recorded in `state/repairs/bss_extents.json`. Existing
  scalar header views remain unchanged.
- BSS objects used only by discarded layout primers can keep their original
  declarations and first-access order while being named as private pool copies.
  `unused_bss_primer_objects` checks every source use against emitted primer
  functions and excludes known retail objects. It does not infer padding from
  gaps or externalize live members. The existing relocation guard must still
  prove the entire private section can disappear. This closes the otherwise
  unbound one-byte primer objects in `fn_1_A1DCC` and `fn_1_A1964`.
- Generated live BSS members need not be static or named `fzgx_obj_*`.
  `bss_member_bindings` can name a globally bound member such as `sprite_8_344`
  from its measured section offset, provided its complete extent fits one
  retail object. The oracle independently checks module, section, address and
  size before accepting that binding.
- An oversized view can include a neighboring object's storage only through
  unused trailing padding. In `fn_1_31C3C`, the last live `GameState` field
  ends at 0x1464, within `lbl_1_bss_3C30`'s measured 0x14BC bytes. Reducing
  its trailing padding from 0x1508 to 0x14BC and keeping the remaining 0x4C
  bytes as a separate primer-only array preserves MWCC's section layout and
  allows the live definition to pass the existing object-bounds proof.

## Unused compiler strings after data binding (2026-10-24)

`fn_1_EB4BC` binds its two live compiler strings (`@12` and `@26`)
to retail data, leaving thirteen unused compiler strings in the private
`.data` section. These copies need no anonymous `...data` binding to be
removed. Data cleanup uses the same whole-section relocation guard as
rodata: every remaining object must be compiler-private, and no incoming
relocation, including one against the section base, may survive. Named
owned data and live strings remain intact. The function then matches fully
without any changes to its machine instructions.

## Extra helper bodies in accepted pool sources (2026-10-24)

MWCC can inline every use of a static helper while retaining an unused
out-of-line copy. `fn_3_23724`'s clamp and `fn_1_5D378`'s random helper
already generate matching caller instructions; declaring those helpers
`static inline` removes the extra bodies. Pool upgrades use the existing
inline-helper family only for helpers the compiled object actually emits.
The full oracle must still prove that the target instructions are unchanged.

An uncalled legacy `primer` is different: its accesses establish the BSS
order, so retain its body in `.fzgxpool` rather than removing it. This closes
`fn_1_384E8`; its definition is the identifier's only source occurrence.
For `fn_17_3090`, the last BSS view's unused trailing array rounded its size
from the retail object's 0x76 bytes to 0x78. Keeping only the live fields
makes the view fit the measured owner without changing later layout.

Old standalone sources can also contain generated global BSS copies that
their functions never reference. `fn_1_FC760` and `fn_3_17098` use the
header-declared retail objects, leaving nine and twenty unused definitions.
Their function diffs match even though the extra BSS breaks module hashes.
`unused_bss_definitions` removes only generated, unowned aliases whose sole
source occurrence is a file-scope declaration and which have no ELF
references. Retail exports, owned storage and referenced definitions stay.
The repair engine excludes these storage-bearing object-only matches until
the copies are removed; the complete link/hash gate remains mandatory.

## Empty case labels change switch tree selection (2026-10-23)

MWCC selects a `switch` binary-search tree from the *distinct* case labels, and
an empty `case N:` that falls into `default:` is not distinct. `fn_12_27884`
needs the retail pivot order (`cmpwi 4` then `cmpwi 2`), which only appears when
`case 4` has a body — the redundant `case 4: result = 0;` is load-bearing — and
`case 5` is written as `case 5: break;` rather than sharing `default:`'s label.
Folding either one into `default:` selects a three-case tree that pivots on 3
and emits 246 words instead of 247. Always compare the pivot order before
attributing a switch body's row diff to allocation.

## Unused BSS definitions can outlive their layout primers (2026-10-24)

A static-inline layout primer that is never called or emitted can keep BSS
copies alive in the source after MWCC has discarded the primer. Remove the
uncalled primer and unused, unowned definition copies together. Keep an
`extern` declaration for an ordinary retail name; keep definitions whose range
belongs to the current unit. `fn_1_32600`, `fn_1_7E8F4` and `fn_1_C6F8C` reproduce
this with unchanged function bodies and exact MWCC object matches.

Primer-only private copies also occur when the oracle binds every live BSS
object by name, without an anonymous `...bss` section-base binding. Either kind
of verified BSS binding can anchor the cleanup. Restrict uses to emitted
`.fzgxpool` functions, retain known retail definitions, and leave poolfix's
incoming-relocation and complete-section checks in place.

A primer-only BSS copy may also use an ordinary retail symbol name. Its spelling
is not an ownership proof: preserve it when the current unit owns its range;
otherwise only uses inside emitted `.fzgxpool` functions may be privatized.
`fn_800756B0` and `fn_8005A24C` reproduce this case without changing their live
function bodies. All live relocations and complete-section cleanup remain gated.

Oversized saved live declarations can include later layout objects. In
`fn_1_30054`, bound `BurnerSub` to `lbl_1_bss_3C30`'s measured 0x14BC bytes and the
buffer pointer to `lbl_1_bss_523C`'s 0x20 bytes; retain the previous section extent
and first-access order with discarded primer-only tails. `fn_17_3C5C` explicitly
clears eight object slots, proving the eight-entry object view used by
`fn_17_3A28`; its value table is also eight entries at `.bss+0x34`.

An initialized section copy needs its real pointers as well as its bytes.
`fn_3_130C8`'s saved data contains a 60-pointer manual/help table, not zero-filled
string placeholders. Recover it with `dataimport.pool_objects` and `payload`,
and express its pointers as symbolic relocations. Retain anonymous padding
objects in that proof, even when their measured bytes happen to be zero.

### Non-owning section views and scheduling (2026-10-24)

- A section-base symbol declared as a short scalar or prefix can distort MWCC's
  memory dependencies even when every cast access computes the right address.
  `fn_1_45E98` needs the non-owning load-state view through `+0x586c`;
  `fn_1_7ACDC` needs the course-load view through `+0x19c`. In both, correcting
  the declaration extent removes the final two differing instruction words.
  Preserve recovered member types and all individual object definitions and
  ownership; a larger external section view does not allocate or transfer data.
  Proofs and reproducible C are in `state/repairs/*load_state_view_20261024.json`
  and `state/repairs/fixup_imports.json`.

### Enum-biased callback tables and high BSS scalars (fn_1_37E98)

An `addi` of `0x38c`, a 16-byte indexed add, and a load at `-0x238`
represent `modes[mode - 36].cleanup`: the callback is eight bytes into each
entry. The table starts at data base plus `0x38c`; folding the negative load
displacement into the table base would put it among preceding strings and
lose the enum bias. Native
initialized entries reproduce the original address calculation, whereas a
byte pointer into a larger word array adds another instruction.

Separate native scalar objects in the high part of the BSS section let MWCC
reuse its low section base with `addis ..., ..., 2`. A single aggregate or
explicit high-address pointer produces different addressing. Preserve each
member's measured owner and bounds, including interior aliases, and discard
primer-only copies through the existing binding checks. An obsolete string
primer can leave extra initialized bytes and prevent an otherwise exact
native data section from binding. Full source and the 25 live member proofs
are in `state/repairs/game_shutdown_20261025.json.gz` and
`state/repairs/game_shutdown_layout_20261025.json`.

### Global address CSE and rematerialisation (probed 2026-10-25, GC/1.3.2)

Probes compiled with the project flags (`-O4,p -inline auto -sdata 0 -sdata2 0`),
`extern S g;` and a `call(&g)` between the uses:

- **Straight line, one use per statement, a call between them**: the base is
  re-materialised for *every* statement (`lis r3, g@ha; addi r3, r3, g@l;
  lwz r3, off(r3)`), whether the source spells `g.field`, `db->field` through a
  pointer local, `*(u32 *)((u8 *)&g + off)` or `((u32 *)&g)[i]`. No parking.
- **Loop body, no call between the uses**: the base is parked once in a
  callee-saved register in the prologue and every access in the body reads
  `off(rN)`, including accesses spelled through different typed views
  (`S **`, `u32 **`, `u32 *`) in the same body.
- **Address live across a call** (the same `&g` passed to two calls, or a
  global read before and after a call in a loop): the base is parked and reused
  on both sides of the call.
- **Address passed as an argument of an inlined function** (`f(at_d(&g))`):
  parked like any other live-across-call value; the inline boundary does not
  force rematerialisation.
- `#pragma opt_common_subs off` disables far more than these address CSEs: on
  `fn_17_3E08` it cost the whole `_savegpr_26` prologue (99.1 -> 83.0).

So a retail `lis/addi` on a symbol the function already addresses elsewhere
does *not* imply a second symbol or a different expression type. Within a
function that parks the base, it means the parked value was not available at
that point, i.e. a rematerialisation/spill decision under a different live set.
Chase the surrounding pressure (values live across the calls in that region)
rather than another spelling of the access.

### Register homes are coupled, so a one-row fix can move another (fn_12_7870, 2026-10-25)

`fn_12_7870` (80 B, 98.5%) is a three-way colour permutation around one
address computation: retail `slwi r4` (the incoming `arg1`), `lha r0` (the
scalar), `addi r7` (the entry); ours `slwi r7`, `lha r4`, `addi r7`. Giving the
shift its own local declared before the scalar (`u32 scaled; s16 x;`) produces
retail's `slwi r4` but moves the entry into r4 and the scalar into r7 (97.5),
and *removing* the scalar local flips the shift back to r7. So the shift's home
is conditioned on whether that local exists at all, not on how the shift is
spelled (`<<=`, `*= 2`, `arg1 + arg1`, an inline expression: all identical).

Practical rule: when a residue is a permutation, score each row's home against
the other values' homes before editing - a candidate that fixes one row without
fixing the set is not progress, and the score will happily rise or fall for the
wrong reason.

### The return value is pre-coloured to r3, and its absence is a signature (2026-10-25)

Retail bodies that end in the epilogue with **no** conversion into `r3` are
`void` functions whose callers discard the result, even when a reconstructed
header spells a return type. `fn_12_3A64` (movie_module, 0x354) and its sibling
`fn_12_3710` are the same case: retail's last write to `r3` is `lis r3, 0x4330`
(the u32->double bias inside the inlined table builder), the only caller
(`fn_12_A5C`) drops the value, and the saved bodies carry `s8`/`u16` returns.

Measured on `fn_12_3A64`, same body otherwise:

| return shape | instructions | residue |
|---|---|---|
| `s8` + `return (u32)far_z;` | 214 | one trailing `extsb r3, r29`; every other row matches |
| `u32` + `return far_z;`    | 214 | one trailing `mr r3, r29` |
| `void`, no return          | 213 | retail's instruction count, 20 rows of callee-saved rotation |

Two consequences:

- MWCC pre-colours the returned expression to `r3`, so *any* value-returning
  shape adds exactly one trailing copy. A diff whose only residue is a final
  `extsb`/`clrlwi`/`mr` into `r3` is evidence about the signature, not about the
  last statement. The score cannot see this: the wrong `s8` body reads 99.5.
- Dropping the return does **not** simply remove that instruction. `/tmp` probe:
  `void` reached retail's exact instruction count but permuted three
  callee-saved homes, because the returned web had been pinning the numbering.
  When two shapes differ only in a colouring rotation, the cheaper of the two
  (the one with matching instruction count) is not automatically forgivable:
  check whether retail shares one register between two *roles* (here the call
  argument and the inlined loop's destination pointer), which is a web-sharing
  question no return-type edit can express.

### Declaration order: real but weak, and exhausted by permutation (2026-10-25)

All 720 permutations of the seven locals of `fn_12_3A64` compile to **12
distinct objects** (so declaration order does reach the allocator), yet every
one of them scores the same 90.61% with the same 20 differing rows, and a full
5040-permutation sweep of the same body never beat it. On `fn_12_3710` the same
scan gives 6 distinct objects and one score.

So `fixup`'s declaration-order family is a genuine lever, but when it reports
`no-predicted-declaration-repair` after enumerating the orders, the residue is
*not* an ordering problem: retail is reusing one register for two roles (or
keeping one less web live), and no permutation expresses that.

### Zero-cost self-assignment barriers (`v = v;`) for coloring, inlining, and loop propagation (2026-10-26)

Implemented in `fixup_source.self_assign_barriers`:

- **User-local barrier (`v = expr; v = v;`, `fn_1_CDC8C`)**: A single-definition scalar local
  is normally folded by IRO into its downstream use, turning its value into a high-numbered
  expression temporary colored *before* IRO CSE `@` temporaries in `SelectColors`. Adding
  `v = v;` immediately after `v = expr;` prevents single-definition folding while coalescing
  the self-copy to zero instructions. The value remains in its user-local vreg (`v32..vK`),
  which is popped *after* IRO CSE `@` temporaries (`@101` in `fn_1_CDC8C` claims `f0` first).
- **Inline parameter barrier (`param = param;`, `fn_4_28FC`)**: Inside a `static inline`
  helper (`draw_marker` / `draw_marker2`), MWCC's AST inliner substitutes the caller's argument
  expression directly into uses of `param`, changing top-down expression lowering order
  (`320.0f + 2.0f * pos` vs `2.0f * pos + 320.0f`). Placing `param = param;` at the start of the
  helper body stops AST argument substitution and coalesces to zero instructions.
- **Loop-step barrier (`for (...; ...; step, v = v)`, `fn_1_22F90`)**: When `v = 0.0f;` is set
  before a `for` loop and read inside the loop without modification, `opt_propagation`
  constant-propagates `0.0f` into the loop. Appending `, v = v` to the `for` step creates a
  loop-carried reaching definition that blocks constant propagation for `v` alone without
  needing `#pragma opt_propagation off`.

### `extern const` read-only arrays unlock pre-RA load scheduling across stores (`fn_8006953C`, 2026-10-26)

Implemented in `fixup_source.const_array_qualifiers`:

- An unqualified `extern u16 table[];` is treated by MWCC's pre-RA scheduler as potentially
  aliasing preceding byte/halfword/word stores (`stb`, `sth`, `stw`), preventing `lhz`/`lwz`
  from being hoisted across the store. Qualifying read-only tables as `extern const u16 table[];`
  proves non-aliasing and unlocks pre-RA load scheduling across stores (`fn_8006953C`).

### `local_var_Scalarize` struct grouping and entry first-access order (`fn_1_4BD4C`, 2026-10-26)

Implemented in `fixup_source.scalarized_loop_structs`:

- Grouping unescaped loop locals into a local `struct { ... } lp;` causes MWCC's
  `local_var_Scalarize` pass to replace each member with a synthetic `@` variable numbered in
  *first-access order* (above ordinary user locals, so colored before them in `SelectColors`).
- Placing zero-cost `(void)lp.member;` statements at function entry controls the exact `@`
  numbering order without emitting instructions or requiring `#pragma opt_dead_assignments off`.

### Dual `.data` + `.bss` section bases and high-offset `.data + 0x10000` (`fn_7_520`, 2026-10-26)

Implemented in `fixup_layout.tu_section_layout`:

- When a function accesses both `.data` (including offsets `>= 0x8000` via `addis rH, rD, 1`,
  i.e. `...data.0 + 0x10000`) and `.bss` globals defined in the TU, `PPC_FindBaseRegisters`
  allocates `...data.0@ha/@l` (`v38, v39`), `...bss.0@ha/@l` (`v40, v41`), and
  `...data.0 + 0x10000` (`v42`). Defining both the `.data` and `.bss` TU objects in the unit
  gives `...data.0 + 0x10000` the highest virtual register (`r31`) while keeping `...data.0` in
  `r4` and `...bss.0` in `r3`/`r30`.

