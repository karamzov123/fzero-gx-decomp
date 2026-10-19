# Fleet acceleration

## Evidence-led agent workflow

The existing `fzgx evidence` diagnostic surface is optional help for blocked work,
not a mandatory preflight before more experiments:
[`EVIDENCE_WORKFLOW.md`](EVIDENCE_WORKFLOW.md). It provides identity-pinned
hypothesis handoffs, native instruction witnesses, shared blocker cohorts,
dependency-aware recheck proposals, licensed donor compile reuse and conservative
verified-yield reporting. Portable prompt: [`AGENT_PROMPT.md`](AGENT_PROMPT.md).
No diagnostic queue or observation grants a claim, budget override or worker
launch permission.

## Historical member-copy sweep and donor replay

The native member-copy family and compiler-context-safe sweep are documented in
[`findings/hermes-membercopy-acceleration-20261018.md`](findings/hermes-membercopy-acceleration-20261018.md).
Run the existing engine, not a separate repair runner:

```sh
.venv/bin/python tools/fzgx.py sweep --recover-membercopy --min-percent 0 \
  --rounds 2 --output .fzgx/work/membercopy-run
```

This freezes eligible historical sources, compiler versions and flags; `--seeds`
replays the selection. Review `coverage.json`, `errors.json`, and `report.json`.
`--land` submits exact candidates or saves improvements without starting another
full repair; `fzgx verify` is still required for hash-accepted progress. The first
pass plus refreshed licensed SDK imports gained 40 natural-C functions / 25,692
bytes. The new repair family alone did not produce an exact match: its strongest
lead required correcting the callback record's obsolete padding.

## Earlier fleet measurements

This is a measured trial, not a claim that a model or larger fleet is superior.

## Effort and transport

`orchestrate.py --effort` exports `FZGX_EFFORT`. The restricted Claude launcher uses that value; OpenCode passes it as per-session `--variant`, retaining `--pure`, the matcher agent, and all six-tool restrictions. Codex keeps its app-server reasoning setting. Direct Claude matcher runs must use `FZGX_BOUND_TRANSPORT=1`; the unrestricted legacy command is not an acceptable benchmark.

The current trial pins are `gpt-6-luna` high and `claude-sonnet-5-5` high, one session each. Luna was resolved using live Codex `model/list`; Sonnet's alias was confirmed by provider model usage. Three existing Space Bunny xhigh lanes remain enabled. AGY, Cline and OpenCode #4 retain operator-disabled state. No CPU or memory limits were raised.

## Recorded trials

All replay trials used already-matched functions, three checks, one model/tool worker, and shadow mode. They do not contribute new closures:

| Model/effort | Target | Result | Session seconds |
| --- | --- | --- | --- |
| Luna medium | fn_1_668 | 67%, released | 11.0 |
| Luna high | fn_1_668 | exact | 20.1 |
| Sonnet medium, bound | fn_1_798 | exact | 35.2 |
| Sonnet high, bound | fn_1_798 | exact | 18.3 |
| Space Bunny medium | fn_1_668 | no stdout/tool receipt; deadline | 204.5 |

The earlier Sonnet medium non-bound invocation was a setup failure (tools unavailable), not a model-quality result. Different replay targets and single samples prohibit cross-model rankings.

Real bounded trials:

- Luna high: fn_1_6E320, six checks, eight tool calls, 135.6 seconds; best increased from 86.605125 to 91.15385%. No exact closure.
- Sonnet high: fn_1_487EC, four checks, 137.9 seconds; attempt reached 48.4%, old 86.48529% frontier preserved. No exact closure.
- Attempt-capped targets fn_1_4068C and fn_1_1384C rejected standalone assignment before inference. No cap was raised for those tests. Fleet selector eligibility and standalone claim eligibility are separate contracts.

Do not use harness-reported $0 as evidence of free inference; price/usage support varies by provider.

## Session health telemetry

Bound CLI runs write a sibling `<symbol>.phase.json`: spawn, stdout/JSON/model event, actual bound-tool receipt timestamps, tool starts/completions, exit code/time, guard reason, and explicit provider errors/status. Receipts, not model prose, establish tool activity. Writes are atomic and failure-safe. A step-start event is activity evidence, not identity verification. A deadline with no stdout does not establish whether the provider or client was responsible. Terminal code 143 without a guard reason likewise does not prove a provider failure.

Historical read-only audit found 109 OpenCode attempts in its 24-hour window, including 53 normal incomplete sessions and 24 rc=-15 interruptions. Separate these outcomes; do not attribute all interruptions to providers. New phase telemetry enables useful first-tool comparisons without retries, header spoofing, or enlarged deadlines.

## Routing and specialist evidence

Fresh saved-body compiler checks (current project defaults plus source pragmas) reproduced:

- fn_1_12DAEC: 99.66307% raw, 94.34% adjusted, 21 register-allocation residuals. Treat as allocation analysis, not a one-word closure.
- fn_1_2D038: 99.53651% raw, 99.68% adjusted, one immediate and one register residual. Its completed zero-yield spelling search is not new work.
- fn_1_135D7C: 99.54724% raw, 99.61% adjusted, one mr/extsb instruction-form residual. Use signedness/instruction-form evidence, not a whole-function rewrite.

The existing selector already reserves measured residual-tier work, widens for saved near-misses, uses mid-band work and a bounded oversize probe, and excludes link-rejected functions from object-only matcher work. Keep these controls rather than replacing them with an unmeasured score formula. Small-module leads require fresh reference/claim eligibility checks; small size is not proof of easy closure.

The proven 0x440 row layout and failed three-function typed-view cohort remain useful shared context, but delivered zero closures. Do not repeat that substitution without changed evidence. No deterministic SDK-import candidate was established by this audit.

## Follow-up: recurrence diagnostics and search evidence

The current build graph needed legitimate recovery work. A later dry run specifically found `build/tools/dtk` newer than `build/GFZE01/config.json`, forcing split/reconfiguration. No incorrect dependency edge was proven. `run_gate()` now captures fail-safe before/after `gate-inputs-*.json` and `gate-explain-*.log` in the fleet cache. Real Ninja and the independent sixteen-target hash check remain mandatory. The final post-gate dry run reported no work to do.

Three Space Bunny sessions each reached the 600-second tool-idle guard without stdout or a tool receipt. Their successor sessions also remained silent at inspection. OpenCode #1/#2/#3 were disabled through normal controls; all their claims drained. Luna/Sonnet remain enabled at one session each.

Additional high-effort shadow replays:

- Haiku `claude-haiku-5-5`, fn_1_668: exact, two checks, 92.7 seconds.
- Opus `claude-opus-5-5`, fn_1_798: exact, two checks, 15.7 seconds.
- Sol `gpt-6.1-sol`, fn_1_668: exact, three checks, 31.3 seconds.
- Haiku real fn_3_12B14: six checks, 283.6-second session, saved at 88.34952%, no closure.

These single samples support tool admission only, not a general ranking. Shared deterministic repair contributes to replay outcomes.

The deterministic repair path now stores zero-improvement, nonmatching search evidence by symbol, source contents, conservative header inventory, compiler binaries/options, reference/config/tooling identity and the exact engine hypothesis. Identical source saved under another filename shares evidence; changed inputs expire it. Missing/custom unresolved inputs fail open. Improvements, errors and zero-variant searches do not create quarantine. Budget sufficiency is required. Existing sidecars gain context keys; legacy sidecars without compilation identity are not used to suppress potentially changed-context work. This may require one bounded contextual refresh, not a blanket function ban.

A real one-second compiler probe produced one variant and no improvement; the repeat reused its evidence with zero variants. Its one-second record cannot suppress a production 150-second search. Nine external gate/helper/integration tests passed. All sixteen hashes passed after integration.

The maintenance drain uncovered an unresolved teardown issue: `stop_runner()` timed out at 120 seconds, the supervisor failed closed, and systemd removed surviving descendants. The exact remaining Codex claim was recovered via normal `release --save-only` after checking no live owners remained. No claims were cleared directly. This recovery is not a teardown fix; do not silently enlarge cleanup timeouts or restart over live owners.

Two read-only investigation agents and one helper implementation agent assisted this follow-up, all at depth 1.

After restoration, the fleet total reached 405. The authoritative ledger attributes the new verified 2,240-byte `fn_1_138144` closure to `claude-sonnet-5-5`, accepted at commit `3e74a6bc`. It came from the preceding Sonnet batch; it is not evidence that the new search cache caused the closure.

## Follow-up: bounded idle-worker cleanup and interruption reporting

The external stalled-worker reproducer demonstrated that ToolPool previously waited indefinitely after stdin EOF. The fix bounds idle-worker cleanup (30-second EOF grace, 5-second TERM grace, 5-second KILL grace), using Linux pidfds and rechecked ownership. Escalation is refused when a request remains ambiguous/in flight or descendants remain. Busy mutation completion is still protected. Cancelled/malformed requests cannot reuse their worker, and closing during worker creation prevents dispatch after shutdown.

Nine process-level tests cover idle EOF stalls, ignored TERM, busy/descendant protection, successful in-flight completion, ambiguous-result reuse, post-close dispatch and the worker-creation race. A real Luna replay completed normally in 18 seconds.

The first real SIGTERM replay released its claim and finished the matcher in 27.4 seconds, but the outer orchestrator exceeded the 110-second observation limit while finishing reporting. The batch's own wall report was 29.7 seconds; this does not prove the idle-worker defect caused that reporting delay. Shadow runs nevertheless violated their documented non-committing contract by entering the final submit-lock ledger checkpoint.

`checkpoint_batch()` now skips presentation snapshots/commits for shadow and interrupted batches, while keeping the database, attempt bodies and reports. Normal checkpoints keep their serialization; source acceptance and hash verification are not bypassed. In a second actual Luna SIGTERM replay, the test held submit.lock after a completed tool operation: the orchestrator exited in 0.306 seconds after SIGTERM, saved/released its attempt, left no claims/runners, and left HEAD unchanged. Summary explicitly reported snapshot_deferred=true.

This repairs the reproduced idle-worker and optional reporting paths, not every possible hung RPC or compiler mutation. Genuine unfinished work still fails closed and may require owner-aware recovery. No transport/tool request deadline was added that could cancel an ambiguous mutation.

## Follow-up: publisher build lock isolation

The publisher previously held the main submit/build locks throughout a committed-snapshot build, despite compiling in a separate checkout. It now captures HEAD and pending state, archives the pinned SHA and materializes private inputs under short locks; releases main locks for compilation; then reacquires in the same order and rechecks HEAD, branch and pending work before any receipt. Changed HEAD/branch, new pending work or a busy reacquisition defers publication without altering that work. The publisher singleton, approved-fork checks, explicit-SHA push and exact remote readback remain unchanged.

Private input copying remaps internal aliases into the snapshot, materializes external tool links and avoids symlink cycles. The actual orig/GFZE01/GFZE01 alias exposed a recursion defect in the first copier attempt; the fixed helper preserves it as a private in-tree alias. Unrelated ISO/GCM links are omitted: config/GFZE01/config.yml consumes extracted DOL/REL objects. Inputs are not published. Receipt version is committed-snapshot-v2-private-inputs; old receipts cannot skip its gate.

Fourteen external Git/lock/input fixtures pass, covering free compiler locks during the gate, pending/HEAD/branch changes, reacquisition failure, dirty-file preservation, private cyclic aliases/backlinks, exact push/readback against a local bare fixture, receipt versions and all four required gate commands. Fixtures never use a real remote.

A real private gate under a one-CPU/two-GiB audit scope completed in 105.245 seconds for d1543a32f7c45e7883b7cf3d96077208a1d6f1e0: configure, Ninja, all sixteen hashes and lint passed. HEAD remained pinned and pending state was clear afterward. No real publication was attempted by this test. Raw proof is in the task scratch private-gate-result.json and private-gate-state.gate.log.

The initial audit attempt respected a thermal admission hold. The thermal diagnosis must distinguish sensors: the fleet guard reads /sys/class/thermal zones, not the separately observed NVMe hwmon sensors. A later valid admission showed a 59 C zone maximum before the real gate.

One depth-1 agent supplied the read-only lock audit. The publisher checkpoint includes its previously uncommitted snapshot support because that is a direct dependency; unrelated user edits stay outside the checkpoint.

## Acceptance and next measurements

Track verified bytes and unique accepted functions per wall-clock hour, tool-reaching fraction, first-tool latency, and terminal reasons. Compare equivalent target cohorts before permanent effort/model promotion. Do not increase concurrency or CPU allocation until phase telemetry and cgroup samples show local resource pressure rather than inference waits. Preserve existing source edits and all reference/hash gates.

Raw trial logs remain under `.fzgx/runs/accel-*`; external regression tests and diagnostic reports are under `/home/armandofm/.hermes/cache/scratch/fzgx-acceleration/` (scratch is temporary). Three depth-1 agents assisted: two read-only audits and one telemetry implementation. Parent review found and fixed actual OpenCode error/event shape handling; four telemetry and two effort tests passed.
