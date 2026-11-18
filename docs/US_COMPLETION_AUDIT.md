# USA completion audit (GFZE01)

This is a living checklist for finishing the USA reconstruction. Update the relevant row in the same change that resolves it, with a commit or PR link and the evidence used to close it. A passing retail hash is required, but it does not by itself establish original source form or the absence of compiler workarounds. See [assembly policy](ASM_POLICY.md).

## Measured baseline

Source baseline: `b2d7361a30119ec49687ee6aec9b37f988f40159`, built against the original USA inputs. All 16 targets match; 7,159 of 7,351 functions have compiled C credit, with 13 of 16 modules at full C credit. There are zero functions credited without compiled C credit in this baseline. C credit is not a certified device-free natural-C total.

| Module | Standalone assembly: review origin | Scoped original assembly | Mixed source |
| --- | ---: | ---: | ---: |
| `main` (DOL) | 176 | 5 | 1 |
| `movie_module` | 7 | 0 | 0 |
| `main_rel` | 3 | 0 | 0 |
| Other 13 modules | 0 | 0 | 0 |
| Total | 186 | 5 | 1 |

The device census found 104 explicit warning locations (61 attributed functions, one unattributed location) and 871 functions associated with layout primers. The union with the tagged staging/dead-write categories is 931 owner functions. Counts overlap and are not an exhaustive device backlog. Ordinary uses of `volatile`, pragmas, or one-field types are review signals, not defects by themselves. Data ownership and native translation-unit boundaries are separate review tracks; this baseline does not certify their completion.

## Worklist

| Status | Work | Evidence / next action |
| --- | --- | --- |
| Verified | USA binary parity | Keep all 16 checks green on each landed change. |
| Blocked | `main_rel` font: `fn_1_4B6D4`, `fn_1_4B788` | [Font probe](findings/gfze01-main-rel-assembly-frontier.md#font-pair-follow-up). Reopen on evidence of how the entry scheduler moves an independent `lis` before `stwu`; do not repeat ordinary source spelling or compiler-flag sweeps. |
| Open | `main_rel` curve: `fn_1_9DFB8` | [Source-origin audit](findings/gfze01-main-rel-assembly-frontier.md). Keep assembly until the evidence distinguishes original assembly from compiler output. The wrapper ABI cleanup is already landed. |
| Open | `movie_module`: `fn_12_52E8`, `fn_12_12564`, `fn_12_33664`, `fn_12_33698` | Audit the GQR setup/save/restore functions as one group. Compare compiler intrinsic probes and caller/SDK evidence before deciding source form. |
| Open | `movie_module`: `fn_12_D0B8`, `fn_12_3CB74`, `fn_12_3D144` | Audit implementation origin, algorithms, and owned data. For `fn_12_D0B8`, see [the historical symbol/relocation finding](findings/295-fn_12_5674-is-dct-fsriinit.md); recheck against current main before using it as a blocker. |
| Open | `main`: 176 standalone assembly functions | Split the review by SDK/runtime and game-code families. Use source-version, caller, and instruction evidence before approving assembly or attempting a C conversion. The [symbol inventory](US_ASSEMBLY_INVENTORY.csv) identifies each entry. |
| Baseline recorded | `main`: five original-assembly and one mixed function | Maintain the scope and evidence in [the original assembly manifest](../config/original_assembly.json). Do not count these as missing C by default. |
| Open | Marked devices and literal-pool primers | Start with an explicit warning or a small owner group with shared evidence. Remove a device only when retail code and relocations survive; record failed hypotheses rather than relabeling a workaround. Prioritize real literal/data ownership over mechanical primer removal. |
| Open | Unmarked compiler-device review | Triage census signals by subsystem, starting with shared helpers and directives that affect multiple functions. Confirm intent and codegen before classifying them. |
| In progress | Native TU and data ownership | [TU collapse pilot](TU_COLLAPSE.md#next-batch-unify-declarations-before-moving-storage): `bg_lig` declaration cleanup first, then whole-file scoring and native pool placement. `bg_tow` is the landed 16-function control. Track this separately from C coverage. |

## Refreshing and editing the audit

From the built GFZE01 checkout being audited:

```sh
python3 configure.py
ninja build/GFZE01/ok
build/tools/dtk shasum -q -c config/GFZE01/build.sha1
python3 tools/fzgx.py lint
python3 tools/fzgx.py honest --snapshot --closure
python3 tools/fzgx.py devicecensus
```

Record the audited commit before changing counts. In the symbol inventory use `needs-origin-review`, `blocked`, `evidenced-assembly`, `mixed-review`, or `closed`; retain closed rows with a link or commit in the evidence column, and keep the headline counts tied to a fresh build rather than the number of rows. When picking up work, note the module-qualified symbols and discovery or compiler experiment you are testing. To close an item, record the chosen source form and origin evidence, exact object/relocation results where applicable, sibling/TU checks, the linked hashes, lint, and the landing commit. For device families, record which functions remain affected, not just the number of warning comments removed.
