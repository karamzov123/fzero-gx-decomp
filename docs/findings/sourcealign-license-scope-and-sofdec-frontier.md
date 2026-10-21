# Source license screening and GX Sofdec frontier

## Delivered tooling change

`tools/fzgx/sourcealign.py:source_license` now recognizes the standard MIT grant,
keeps the existing license path/SHA-256 provenance, and rejects an explicit
preamble excluding reconstructed source. This is a conservative text screen,
not a replacement for reading a new donor's license and scope.

Real-input regression evidence:

- Before the change, the Sonic Heroes MIT license was rejected, while RE4's
  restricted CC0 license was accepted. The latter explicitly excludes the
  reconstructed source under `src/` and headers under `include/`.
- After the change, Sonic Heroes is recognized as MIT; mk-deception, tww and
  sms remain CC0-1.0; the same RE4 license is rejected. No RE4 source was
  imported. The license probe used a scratch checkout layout, not repo tests.
- Sonic Heroes donor commit: `0915a08eb2829770aebf39924fdda7033db86b72`.
- Real function-mode MWCC compilation across the existing twelve profiles:
  470 CRI functions compiled per profile; 197 MSL/runtime functions compiled
  per profile; Dolphin compiled 1786/1793 functions per profile. The seven
  Dolphin failures were six AXOut functions and `__check_pad3`.
- Discovery screened each of those source-root cohorts against current retail
  objects with minimum size 64. No new import candidates cleared the existing
  threshold; no compiler or oracle gate was relaxed, and no Sonic Heroes
  source was integrated into the game.

The existing submit path copies the entire donor license into
`state/sdkimports/licenses/` and records source commit/hash and compiler
settings. MIT support uses that path without changing its provenance or
retail verification requirements.

## Nonmatching source retained for continuation

Portable archive:
`state/repairs/manual-sofdec-and-font-frontier-20261021.json.gz`

Replay with:

    uv run tools/fzgx.py fixup --archive state/repairs/manual-sofdec-and-font-frontier-20261021.json.gz

Real replay result: `{"reproduced": 2}`. Both records remain nonmatching:

| Function | Retail size | Raw objdiff | Differing words | Shape errors |
| --- | ---: | ---: | ---: | ---: |
| fn_12_28CC4 | 2144 | 96.591415% | 154 | 11 |
| fn_1_CFB28 | 380 | 99.73684% | 2 | 0 |

The word counts are authoritative for prioritization; the large Sofdec raw
percentage is not evidence of a two-percent-sized repair.

`fn_12_28CC4` reconstructs the older four-argument GX `sfmpv_DecodeOneUnit`
from retail control flow and the permitted mk-deception donor. It includes
endcode/time concatenation, timer snapshot copies, picture skipping and the
two-chunk delimiter search. The newer donor's extra `has_data` argument and
flow path do not describe GX. Remaining differences include folded snapshot
base addresses, instruction scheduling, stack slots and register allocation.
The retained compiler profile is GC/1.3.2 with
`-use_lmw_stmw on -opt nocommonsubs`.

`fn_1_CFB28` uses a plain scalar index rather than the saved one-field carrier.
Writing `index * 36` corrects the integer multiply operand order. The two
remaining differing words select f3 instead of retail f1 for the double
addition and its rounding source. Scalar type, expression, meaningful
interpolation-helper and bounded shared-engine repairs did not close it.

No new executable bytes were landed by this continuation. Previous verified
camera closure `cbf2da8f` remains intact. No worker ownership, provider/fleet
configuration, or remote branch was changed; all claims owned by hermes-kb
were released.

## Verification

- Python compile check for `sourcealign.py`: passed.
- Real license regression checks: passed as described above.
- Portable frontier replay: two records reproduced.
- `python3 configure.py && ninja`: passed. Existing configure warnings for
  `src/dol/fn_80036AC4.c` and `rel/sel/fn_10_266AC.c` remain.
- `build/tools/dtk shasum -q -c config/GFZE01/build.sha1`: `16 files OK`.
- `uv run tools/fzgx.py lint`: `0 finding(s)`.
