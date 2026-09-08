# MSL bounded string functions

## Scope and provenance

Convert the existing assembly bodies of `__msl_strncmp` (GFZE01
`0x80083B8C`, 64 bytes) and `__msl_strncat` (`0x80083CF4`, 76 bytes) in
`src/dolphin/msl/tail_8008279C.c`. Preserve symbol names, source ownership,
neighboring functions/data, split configuration, and all compiler settings.

- `__msl_strncmp`: adapted from [PrimeDecomp/prime `strncmp`, lines 172–188](https://github.com/PrimeDecomp/prime/blob/efb5cb05977f685697df44253c5c7c77f1cec1b1/src/Runtime/string.c#L172-L188).
  Adaptations are the public symbol name, explicit count type, const-preserving
  pointer casts, and receiving-tree formatting.
- `__msl_strncat`: reconstruction of the retail instruction sequence using the
  MSL predecrement-pointer idiom, with [Prime's `strncpy`, lines 75–90](https://github.com/PrimeDecomp/prime/blob/efb5cb05977f685697df44253c5c7c77f1cec1b1/src/Runtime/string.c#L75-L90)
  as an idiom reference. It is **not** an imported Prime `strncat` implementation.
  Both reference links pin commit `efb5cb05977f685697df44253c5c7c77f1cec1b1`.
  Reference credit is not a claim of clean-room authorship or a license grant.
- `cvFsSetDefDev`: preserve the [existing upstream reconstruction](https://github.com/karamzov123/fzero-gx-decomp/blob/9af7e15af23b0dcfbce890532f984f5eb555edfd/src/game/adxt_80053EA0.c#L1224)
  and its original provenance. The only body edit changes local `len` from
  `int` to `unsigned int` to agree with the count parameter while retaining
  retail register allocation. All 308 bytes and the entire owner object are
  unchanged; this is not claimed as a newly reconstructed function.

## ABI and limitations

- Compare returns `int`; concatenation returns the original `char*`. Both
  accept a 32-bit `unsigned int` count, two pointers in r3/r4, and count in r5.
  All declarations are consistent, including the existing DVD prototype.
  `unsigned int` and `unsigned long` are both 32-bit here but are distinct C
  types; equal width alone does not make conflicting prototypes compatible.
- `cvFsSetDefDev` now stores its string length in `unsigned int`, matching the
  count argument. This also preserves its retail register allocation when a
  full prototype is supplied. The entire caller object remains unchanged.
- Unsigned bytes preserve high-bit comparisons. The inherited unsigned-long
  subtraction and conversion to `int` rely on this compiler's target behavior
  for a negative difference. The pointer-before-array idiom is not portable
  ISO C; this is a target/compiler-specific matching reconstruction.
- Normal string-library preconditions still apply: inputs must be readable
  through the first NUL or requested bound, destination must be terminated
  with sufficient writable space, and concatenation buffers must not overlap.
  Zero-count compare reads neither input; zero-count concatenation scans and
  rewrites the destination terminator without reading source. This patch does not
  repair pre-existing `adx_err_report` capacity/termination behavior.

## Verification

Current public base: `9af7e15af23b0dcfbce890532f984f5eb555edfd`.

Fresh builds using unchanged generated compiler commands proved:

- Both complete function byte sequences and relocation lists equal retail
  (64 and 76 bytes; neither function contains a relocation).
- All eight affected owner objects preserve every allocated section's contents,
  size/alignment, all function/symbol layouts, and relocation tuples. This
  includes all untouched functions and data, not only the two new C bodies.
  Independent comparison also confirms all eight objects are **raw byte-identical**.
- The repository's eight discovered tests pass on baseline and candidate.

### Supplementary full link; current-main caveat

Both current-base baseline and candidate fail the full build in unrelated
`src/dolphin/os/EXIBios.c`, at the `lbl_801A6840` assembly label. No unrelated
source or compiler-setting fix is included.

On last-green public base `675f69f289b338df4a7098fedcf89a73de23d113`, all eight
affected baseline sources are identical to current main. Baseline compiler
commands match across bases, and candidate commands separately match across
bases. Each base retains its own unrelated configuration.

```sh
ninja -v -j4 all_source build/GFZE01/main.dol
sha1sum -c config/GFZE01/build.sha1
python3 -B -m unittest discover -s tests
```

Both the unmodified and candidate supplementary builds produce retail DOL
SHA-1 `421c88106697d3275a3fc26fb7a01bf6d816b271`. Separately changing compare's
successful return from 0 to 1, then concatenation's final NUL from 0 to 127,
produces two successfully linked but hash-failing DOLs. Each mutation changes
only its intended function, preserving sizes, symbols, and relocations.
Restoring each exact C source restores the exact owner object and retail DOL.
These controls prove both C bodies participate in the actual link, rather
than being bypassed by original-object fallback. They do not claim that
current main's unrelated full-build failure is resolved.

Independent Unicorn execution of the actual linked PPC passes **68,336 cases**
per positive DOL: 66,936 comparisons and 1,400 concatenations. Coverage includes
all first-byte pairs, high-bit bytes, zero and bounded counts, UINT_MAX with
terminating inputs, alignments, return values, read/write boundaries, guards,
and preserved registers. Baseline, candidate, and both restored DOLs pass;
both actual source-mutant DOLs fail on the expected behavioral difference.
This is emulation with valid padded buffers, not hardware testing or a
portable-C proof.
