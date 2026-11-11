# Completion frontier and Exo Free verification

2026-10-07. This is the new `/home/armandofm/projects/fzgx` project. The measurements below describe the earlier **models off except bounded tests** phase. The current owner direction is the five-tile Eww bar with four Space Bunny Free slots (maximum three OpenCode sessions), Codex ×2, AGY ×1 and global cap six; see [the live fleet handoff](../FLEET.md). The older test-only policy below is historical. Data-ownership and structural-frontier findings remain valid.

## Superseded pre-authorization test-only snapshot

The following describes the earlier test-only state; it is historical, not the current control policy. The owner later authorized the six-session mix documented in [FLEET.md](../FLEET.md). Do not infer current service state from these bullets.

- At that earlier snapshot the standing fleet and sleep inhibitor were stopped, provider controls were off, and `model-policy.json` used `mode: test-only`.
- The daemon's policy guard then suppressed surge, drained jobs on policy changes, and rejected new Job construction under that mode; malformed modes failed closed.
- Two abandoned GPT/AGY claims from that stopped period were recovered with `api.release(..., save_only=True)` only after confirming no active model runners. Candidate files were preserved; no direct SQLite ownership edits were made.

## Exo Free: native CLI verified working; bash denial causes restricted-test rejection

A subsequent one-variable-at-a-time investigation reproduced the owner's working native CLI. The actual OpenCode 1.18.35 executable returned `EXO_NATIVE_OK` under normal configuration; the local session metadata independently recorded provider `opencode`, model `exo-free`. The same request with **only `OPENCODE_PERMISSION='{"bash":"deny"}'` changed returned the 403**. Denying only `edit` still worked. Normal configuration with `--pure` worked; redirecting only configuration to a copy of the native public permission settings worked; a final unchanged native repeat worked. All seven comparison cases made zero tool calls. These results identify bash denial as a sufficient rejection trigger, not Hermes routing, missing credentials, `--pure`, or config redirection by itself. The provider's internal reason for that rule remains unproven.

The strict function-bound matcher deliberately denies native bash. Do not remove that boundary, spoof client headers, or advertise/expose an unrestricted shell just to pass Zen admission. Exo is verified for native text responses, **not yet verified as compatible with the six-tool-only decomp contract or as delivering compiler/link-verified C**. At the time of this historical test, the fleet was off under the then-current test-only policy; see [FLEET.md](../FLEET.md) for the later authorized live configuration. No personal global OpenCode configuration or existing TUI was changed during that investigation.

Native A/B receipts and logs are at `/home/armandofm/.hermes/cache/scratch/fzgx-exo-ab/`, including `receipts.json`; sanitized durable receipts are committed at `state/model-tests/exo-cli-admission-20261007.json`. The diagnostic cases were normal, deny-all, deny-bash, deny-edit, normal plus `--pure`, config-redirection-only, and normal repeat. Successful assistant identities were read back from the local OpenCode database in read-only mode, without printing account secrets or unrelated session content.

The earlier three restricted probe failures remain valid evidence about those configurations, but they did not establish general Exo unavailability:

Exact model ID: **`opencode/exo-free`**. Both the installed catalog and https://opencode.ai/docs/zen/ list it. The published price is free during its limited trial; its policy permits collected data to improve the model. Catalog presence and zero price do not prove a functioning session.

Three bounded tests were executed, with no permission loosening or paid fallback:

1. Actual six-tool function-bound decompilation trial, OpenCode **1.18.35**, `fn_3_106FC`, one session, max four checks/two stale checks/360-second timeout. Result: **FreeTierError 403**, 7.4 seconds, **zero checks and zero matches**. The runner preserved/released the claim.
2. Text-only OpenCode **1.18.35** probe using the ordinary `build` agent, `--pure`, empty working directory, isolated configuration, and all tool permissions denied. Result: **the same 403**; no `EXO_SMOKE_OK` response.
3. Text-only installed OpenCode **2.0.0** probe using `--standalone`, isolated configuration, empty working directory, and denied tools. Result: **the same 403**. No shared background server or fallback model was used.

The provider's exact message was: “OpenCode's free tier can only be used from within OpenCode.” The tests did use official installed OpenCode clients. There are no OpenCode credentials listed in the inspected account. Whether authentication, provider admission, or restricted-agent handling causes this is **not proven**. Do not represent any speculative explanation as a fix, spoof headers, enable filesystem/shell tools to pass admission, or loop on the same failure.

Evidence:

- `.fzgx/runs/audit-exo-20261007/fn_3_106FC.log`
- `.fzgx/reports/audit-exo-20261007-high.md`
- `/home/armandofm/.hermes/cache/scratch/fzgx-exo-smoke/native-smoke.log`
- `/home/armandofm/.hermes/cache/scratch/fzgx-exo-smoke/native-v2-smoke.log`

Future successful validation must establish a response, then the six bound tool contract, then real compiler-backed decompilation, then full-link acceptance. A text response alone will not prove usefulness to this project.

## Model-free progress actually delivered

The existing data-import engine was used; no new repair/search runner was created. The following four BSS objects now have explicit source ownership, exact declared types/array bounds, compiler-proven alignment/extent, provenance, and an independently passing sixteen-target link:

| Symbol | Type | Bytes |
| --- | --- | ---: |
| `lbl_1_bss_26C68` | `u16[35526]` | 71,052 |
| `lbl_12_bss_9710` | `u8[73760]` | 73,760 |
| `lbl_10_bss_493A0` | `u8[0x5B20]` | 23,328 |
| `lbl_12_bss_DB0` | `float[64][64]` | 16,384 |

**184,524 data bytes** gained source ownership without any model-generated C. The DTK matched-data metric increased from **1,748,651 / 5,068,465 (34.500603%)** to **1,933,175 / 5,068,465 (38.14123%)**. This is data ownership progress, not newly decompiled executable code, and not a claim that every buffer's gameplay semantics is understood.

The importer verified actual Ninja-produced objects as well as probe objects, and proved all sixteen hashes. Existing operator edits in `src/rel/pilotpoint/pilotpoint.c` and `tools/fleet_cline.mjs` were checked by SHA-256 and remained unchanged.

Two cases were intentionally not forced:

- `lbl_80164D60` (70,656 bytes) qualified only as `opaque-bss`, despite an unsized u32 view. It was not integrated to inflate data progress.
- `lbl_8018B2A4` (16,388 bytes) failed the compiler-section start alignment check. It was excluded from the batch rather than bypassing that proof. A partial probe failure did not cause a partial application; the three proven remaining targets were then tested/applied as a separate cohort.

Committed reproduction inputs are the generated C, split/unit ownership changes, and `state/dataimports/GFZE01.json`. Local probe reports are under `.fzgx/completion-declared-bss*-20261007.json`.

## Revised priorities from actual evidence

### 1. Finish proven data ownership before more low-yield matcher traffic

Read-only inventory found **16,658 unowned objects / 3,292,740 bytes** before this cohort. The inventory is not identical to DTK's unmatched-data denominator. A filter for BSS with explicitly bounded array declarations found **293 candidates / 531,181 bytes**, excluding the first already-imported array and pilotpoint. Those are investigation candidates, **not all validated imports**.

For each bounded cohort: reconcile every existing view, require `declared-bss` or a separately proven structured layout, validate MWCC alignment/extent/relocations, run the full link, and preserve operator source edits. Reject opaque fallback, conflicting aggregate views, code-interior pointers, and unexplained section alignment. Prioritize large objects with consistent declared layouts. Do not auto-import a half-megabyte unknown `.data` blob just because it lacks an owner.

Inventory and probe artifacts:

- `.fzgx/completion-data-inventory-20261007.json`
- `.fzgx/completion-data-probe-20261007.json`
- `.fzgx/completion-declared-bss-cohort-20261007.json`

### 2. Do not repeatedly import already-completed SDK records

Every target in the current CARD/OS/EXI/SI and other ordinary SDK import archives is already authored. The current CARD result report also has no matched/still candidates. Re-running successful import archives is not the next productive batch.

Comparing compatible MKDD/TWW SDK match seed hits with current authored ownership exposes a much smaller unresolved set: `SIInterruptHandler` (836 bytes), plus compiler-runtime helpers such as `__save_fpr`, `__restore_fpr`, `__save_gpr`, `__restore_gpr`, 64-bit division/modulo, and conversion helpers. Treat seed identity as a research lead, not acceptance; recheck settings and retail bytes. The register-save helpers have ABI/register contracts and cannot be claimed as ordinary C imports merely by copying SDK inline assembly. Keep compiler-generated runtime support explicitly accounted for; do not count raw opcodes or disguised assembly as decompilation.

### 3. Refresh large saved candidates before ranking or assigning them

`fn_12_364CC` is 4,208 bytes and the ledger advertised **99.343155%**. The existing engine freshly compiled its saved body under **GC/1.3.2** and measured **98.89354% raw**, **91.29% adjusted**, **97 word errors**, **7 shape errors**, and **92 differing instruction rows**. It is not a one-instruction repair.

A bounded existing-engine test (30-second budget, one round, beam one, eight generated probes) actually compiled **nine candidates** in **6.50 seconds** and produced **zero matches and zero improvements**. No source was applied. Preserve that stopping result instead of repeating declaration-order/local-variable sweeps with unchanged evidence. The next action is structural/value-flow diagnosis of the measured residual, not a higher concurrency setting or calling an old percent “nearly complete.”

Evidence: `.fzgx/completion-frontier-20261007/report.json` and its archived sources/compiler responses. The exact invocation was:

    .venv/bin/python tools/fzgx.py --json fixup fn_12_364CC --budget 30 --rounds 1 --beam 1 --max-candidates 8 --limit 1 --output .fzgx/completion-frontier-20261007

Use the same refresh-before-ranking discipline for the 3,708-byte DOL `fn_80025EF4` and 2,852-byte `fn_1_7D6B8`. These are backlog examples, not currently dispatched tasks.

### 4. Plan later model use around measured structural cohorts

Only test one transport/model at a time until a strict tool contract works. Keep model identity and difficulty strata explicit. After owner authorization for production work, allocate specialist sessions to diagnosed medium/large functions with compact actual residual evidence; retain no-result stopping rules. Do not reactivate the free reserve, subscribed lanes, Luna swarms, or nested matcher agents during this test-only phase.

## Verification and limitations

- Real MWCC data probes, actual installed OpenCode CLI requests, and the existing fixup engine were exercised; no fabricated API or compiler results.
- Eight external controller/accounting regressions passed, including test-only policy denial; no unit tests were added to this repository.
- The final acceptance commands are `fzgx lint`, `ninja -j2 build/GFZE01/ok`, and `build/tools/dtk shasum -q -c config/GFZE01/build.sha1`.
- Provenance/source changes are committed locally before completion is reported. Existing unrelated edits remain deliberately uncommitted, so no clean-tree or pushed-remote claim is made.
- Models and the fleet remain off. No sleep inhibitor or unattended production matcher is left running. The read-only audit timer is separate and makes no model requests.
