# USA completion audit (GFZE01)

This is a living checklist for finishing the USA reconstruction. Update the relevant row in the same change that resolves it, with a commit or PR link and the evidence used to close it. A passing retail hash is required, but it does not by itself establish original source form or the absence of compiler workarounds. See [assembly policy](ASM_POLICY.md).

## Measured baseline

Source baseline: `34dd6166ac74ea55679a43a13059758790391387` plus the `bg_lig.c` 24-function consolidation in this batch, built against the original USA inputs. All 16 targets match (`16 files OK`); 7,159 of 7,351 functions have compiled C credit (`192` functions outside C credit: `mixed=1`, `original-assembly=5`, `standalone-assembly=186`), with 13 of 16 modules at full C credit and zero functions credited without compiled C credit. C credit is not a certified device-free natural-C total.

| Module | Blocked (`C` suspect) | `evidenced-assembly` (reviewed + manifest) | `mixed-review` (C + inline `asm`) | `needs-origin-review` |
| --- | ---: | ---: | ---: | ---: |
| `main` (DOL) | 0 | 175 | 7 | 0 |
| `movie_module` | 0 | 4 | 3 | 0 |
| `main_rel` | 2 | 1 | 0 | 0 |
| Other 13 modules | 0 | 0 | 0 | 0 |
| Total | 2 | 180 | 10 | 0 |

In the `fzgx devicecensus` run after retiring the 7 `.fzgxpool` primer blocks in `bg_lig.c`: `marked-warning` has 104 explicit spots (61 owner functions, 1 unassigned), `layout-primer-function` has 9,603 spots (864 owner functions across 134 files, down from 871), and the known marked/dead-write/primer/tagged-staging owner-function union is 924 (down from 931). Counts overlap and are not an exhaustive device backlog. Ordinary uses of `volatile`, pragmas, or one-field types are review signals, not defects by themselves. Data ownership and native translation-unit boundaries are separate review tracks; this baseline does not certify their completion.

## Worklist

| Status | Work | Evidence / next action |
| --- | --- | --- |
| Verified | USA binary parity | Keep all 16 checks green on each landed change (`16 files OK`). |
| Blocked | `main_rel` font: `fn_1_4B6D4`, `fn_1_4B788` | [Font probe](findings/gfze01-main-rel-assembly-frontier.md#font-pair-follow-up). Reopen on evidence of how the entry scheduler moves an independent `lis` before `stwu`; do not repeat ordinary source spelling or compiler-flag sweeps. |
| Closed (`evidenced-assembly`) | `main_rel` curve: `fn_1_9DFB8` | [Origin audit](findings/gfze01-main-rel-assembly-frontier.md#curve-evaluator-fn_1_9dfb8-origin-audit-evidenced-assembly): six `bCC+` hints (`0/7,159` in C), two `xor rX, rX, rX`, locked-cache `0xE000019C` reads via clobbered `r6`, dead branch preserved after `b`. Retain `.s`. |
| Closed (`evidenced-assembly`) | `movie_module`: `fn_12_52E8`, `fn_12_12564`, `fn_12_33664`, `fn_12_33698` | [Movie GQR audit](findings/gfze01-assembly-origin-audit.md#movie-gqr): frameless `GQR2`–`GQR7` `mtspr`/`mfspr` leaves (`li; oris; mtspr`); MWCC `GC/1.3.2` has no `__mtspr`/`__mfspr` builtins. |
| Audited (`mixed-review`) | `movie_module`: `fn_12_D0B8`, `fn_12_3CB74`, `fn_12_3D144` | [Movie middleware audit](findings/gfze01-assembly-origin-audit.md#movie-middleware): MWCC C prologues and outer loops wrapping inline `asm` (`HID2`/`dcbi`/`dcbz_l` locked-cache setup; `GQR4` + `dcbz` + paired-single YCC420->ARGB8888 kernels). `fn_12_D0B8` already calls `DCT_FsriInit` cleanly on `main`. |
| Audited (170 `evidenced-assembly`, 6 `mixed-review`) | `main`: 176 standalone assembly functions | [DOL origin audit](findings/gfze01-assembly-origin-audit.md#main-dol-176-audited---170-evidenced-assembly-6-mixed-review) and [symbol inventory](US_ASSEMBLY_INVENTORY.csv): 0 `needs-origin-review` remaining; 6 `mixed-review` candidates (`PPCMffpscr`, `PPCMtfpscr`, `fn_800071B8`, `fn_80007664`, `fn_8003AB08`, `fn_8003B010`), 170 `evidenced-assembly` across 14 SDK/TRK/runtime/AV/audio families. |
| Baseline recorded | `main`: five original-assembly and one mixed function | Maintain the scope and evidence in [the original assembly manifest](../config/original_assembly.json). Do not count these as missing C by default. |
| Open | Marked devices and literal-pool primers | Start with an explicit warning or a small owner group with shared evidence. Remove a device only when retail code and relocations survive; record failed hypotheses rather than relabeling a workaround. Prioritize real literal/data ownership over mechanical primer removal. |
| Open | Unmarked compiler-device review | Triage census signals by subsystem, starting with shared helpers and directives that affect multiple functions. Confirm intent and codegen before classifying them. |
| In progress | Native TU and data ownership | [`bg_lig.c` pilot](TU_COLLAPSE.md#bg_ligc-pilot-closure-0x6360-emission-proof-lbl_1_data_2abac-boundary-and-24-function-primer-free-group): consolidated `fn_1_D720C`–`fn_1_D8F4C` (24 fns) into one primer-free unit, retiring 7 `.fzgxpool` blocks (reducing `bg_lig.c` from 19 units / 8 primers to 5 units / 1 primer) and proving why `0x6360` (`fn_1_D6748`+`fn_1_D6C10`) splits from `0x6490` (`fn_1_D720C`–`fn_1_DA6A8`). `bg_tow` is the landed 16-function control. Track this separately from C coverage. |

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
