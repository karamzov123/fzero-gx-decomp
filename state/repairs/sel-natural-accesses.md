# Natural selection-resource accesses and device-removal frontiers

## Accepted change

`fn_10_757C` and `fn_10_CE6C`, in `src/rel/sel/sel.c`, no longer cast
`lbl_10_bss_51740` to `volatile s32 *`. They access the declared global directly,
using `(s32)` value casts for the signed `-1` sentinel and the signed callee
argument. The ordinary C function calls still separate the two global reads.
No single-read caching, new compiler settings, pragmas, assembly or barriers were
introduced. The `fzgx:begin/end` markers are unchanged.

The six volatile casts were unmarked and made the starting tree fail `fzgx lint`
with six S2 findings. Removing them is sufficient to preserve the complete retail
bodies; a justification comment or new warning would only have hidden the lint
failure, so neither was added.

Compiler: stock `GC/1.3.2`, existing module defaults, no per-unit extra flags.
Compiler SHA-256:
`7cbae0a5bd81e07d7fa8975bbc4e969b5dea265cc29c5ee6bae0453a6e25f225`.

Verification performed against the generated units after editing the TU:

```
uv run tools/manual.py try fn_10_757C build/GFZE01/gen/rel/sel/sel --glob fn_10_757C.c --mw GC/1.3.2 -v
uv run tools/manual.py try fn_10_CE6C build/GFZE01/gen/rel/sel/sel --glob fn_10_CE6C.c --mw GC/1.3.2 -v
python3 configure.py --version GFZE01
uv run ninja
uv run tools/fzgx.py lint
```

Both oracle results: `100.000 MATCH rows=0` (22 instruction words each).
Linked verification: `16 files OK`. Lint: `0 finding(s)`.
The linker also emitted its existing unknown-section warnings; the hash check
passed despite those warnings. `fzgx snapshot` was run, but its unrelated live
ledger drift was excluded; these already-matched functions need no ownership or
status transition.

## Scheduled targets: no weakened matches accepted

The following are measured positional differing-word counts, not aligned objdiff
row counts and not proof of a global search minimum. All existing matching source
and settings for these targets remain installed.

| Function | Tested natural candidate | Investigation |
| --- | ---: | --- |
| `fn_8006BCF8` | 2 | GC/2.0p1, `-use_lmw_stmw on`; seven processor models, older/newer stock compilers, float/double result locals, literal/array scale loads, real scale/table helpers. No closure. |
| `fn_1_145C6C` | 9 | GC/1.3.2; removed the marked dead-assignment pragma and `center_src` device, tested the saved WIP, index types, declaration locations, single index, direct center literal, arithmetic and centering helpers. No closure. Removing the additional existing optimization pragmas also failed. |
| `fn_1_977BC` | 37 | Module compiler defaults; removed the u64 round trip, tested view/model ordering, declaration locations, a real view accessor, shared animation pointer and matrix-pointer form. No closure. |
| `fn_1_12F4A8` | 29 | GC/1.3.2; removed all four marked devices, tested real progress-ratio/lookahead helpers and valid permutations of their independent calculations. No closure. |
| `fn_8004313C` | 12 | GC/1.3.2, `-sdata 0 -sdata2 0 -use_lmw_stmw on`; direct output parameters, inline endian helper, no dead address comparisons or dead-assignment pragma; stock processor models did not close it. |
| `fn_8004EFA8` | 5 | GC/1.3.2, `-sdata 0 -sdata2 0`; direct stack parameters, no dead comparisons or pragma; stock processor models did not close it. |
| `fn_8004F00C` | 115 | GC/1.3.2, `-use_lmw_stmw on`; direct stack parameters, removed identity helper/kept-copy devices and their pragmas. 7450 reduced this candidate to 113, not a match. |
| `fn_8004F26C` | 167 | GC/1.3.2, `-use_lmw_stmw on`; removed entry dead writes, dead sum and zero-conditioned prediction device. Partial-device-removal experiments reached 3 words but retain entry devices and are NOT natural-C matches. Real predictor helpers and shared arithmetic locals did not close those remaining three words. |
| `fn_8004F55C` | 3 | New portable native frontier below; full loop matches, only stack-argument load placement differs. |

`fn_800463E4` was already device-free before this change. Rechecked with its
recorded `GC/1.3.2 -proc 7450`: `100.000 MATCH rows=0`.
`include/adx_compiler_diff.h` remains required by the installed decoder and was not
removed. `fn_1_2CBAC` and `fn_1_10B800` were not changed.

There are still 36 primary `WARNING: compiler-diff device` occurrences and two
`WARNING: device` references across 12 source/header files. This change removes
six previously unmarked volatile accesses; it does not reduce that marked-warning
inventory. Do not count authored/matched code percentages as an audited natural-C
percentage.

## Portable fn_8004F55C frontier (not accepted)

Source: `device-frontiers/fn_8004F55C.native.c`.
SHA-256: `5b7c8f5c002c8c872dfbf57ebec4cb9cb5b876611711ca582defe50fc62fa831`.
Matching installed source SHA-256 at capture:
`23cc9610bb40c5c853ab94331cfef858cab3678048e1d329c334e9712bcf74cd`.
Compiler: the stock GC/1.3.2 binary identified above.
Flags: `-use_lmw_stmw on`, otherwise normal DOL defaults.

The native loop reuses `packed` for `lbl_800911E0[packed & 15]`. The old packed-byte
value is dead after that lookup. Gain is block-local; stack parameters are used
directly. There are no volatile casts, optimizer pragmas, inline assembly, dead
compares, identity helpers, ordering-only parameter copies or u64 tricks.

Results: 85/85 words, three positional differences, oracle `97.647`, two aligned
rows (one instruction movement). Only `lha r30, 0x2a(r1)` is too early: candidate
offset `0x18`, retail offset `0x24`. Reusing the nibble variable reduces the naive
native candidate from 31 positional differences to three, without retaining any
of the marked devices. A stock compiler/processor sweep did not reach zero.

Reproduce with all temporary output under the session scratch directory:

```
D=$(mktemp -d "$TMPDIR/fzgx-f55-frontier.XXXXXX")
cp state/repairs/device-frontiers/fn_8004F55C.native.c "$D/"
uv run python tools/manualkit/fast.py fn_8004F55C "$D" GC/1.3.2 '-use_lmw_stmw on'
uv run tools/manual.py try fn_8004F55C "$D" --mw GC/1.3.2 --flags='-use_lmw_stmw on' -v
```

Do not install this candidate until the full oracle reaches 100%, all 16 hashes
pass and lint remains at zero. No live-ledger score, ownership, matcher limit,
compiler executable or retail target was changed by these experiments.
