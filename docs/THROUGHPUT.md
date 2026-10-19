# Execution-first throughput repair

The prior evidence-heavy prompt was not demonstrated acceleration. It made
optional diagnostics read like mandatory ceremony and made a single failed
hypothesis/release too easy to interpret as completion. This pass restores broad
manual investigation and measures direct tooling changes without launching agents.

## Actual stop and initialization failure

The reported run on `fn_3_990C` recorded four checks but only one substantive
candidate change, then voluntarily released it. It did not exhaust the live
16-check/5-stale-check budget. Its one-function host wording and long decision
protocol did not clearly tell an unbound contributor to continue to other work.

Separately, a real manual-claim probe on eligible `fn_1_93734` returned a
91-character placeholder even though complete saved C existed. Manual claims
without an explicit `FZGX_SEEDS` manifest did not initialize that saved body.
The agent therefore spent startup effort finding/retransmitting its own seed.

After the fix, the same normal claim path returned the saved 6,292-character C,
retained its source hash and compiler profile, and replayed at 97.68666%. The
claim was released with `save_only=True`; no source change or new match was
claimed. Explicit frozen manifests still take priority and a missing entry still
rejects before ownership changes. Shadow/revise behavior is not replaced by the
manual seed fallback. The original `fn_3_990C` cap remained intact; a capped
replay was rejected rather than silently resetting its history.

## Prompt and scope corrections

- `docs/AGENT_PROMPT.md`: short execution-first prompt, broad manual freedom for
  source/types/tools/shared work with ownership and verification. A failed check,
  released function or first match is explicitly not a session stop.
- `tools/codex_matcher.md`: substantially shorter; explore materially different
  approaches, permit coherent multi-line edits, no mandatory per-edit hypothesis
  recital or evidence forms. Runner-bound workers still obey actual assignments
  and tool stop signals.
- `tools/codex_revise.md`: optional diagnostics and substantive readability work,
  not a formal handoff ceremony after one rejected rewrite.
- `AGENTS.md`: distinguishes unbound multi-function contributors from one-function
  workers; allows useful process-local budgets and serialized shared changes.
- Unbound MCP server instructions no longer say "One function per agent". These
  instructions refresh on a new server instance/connection; no live server was
  restarted. Existing CLI-backed calls read the updated claim/context code.
- Context construction no longer automatically builds a decision packet, hashes
  its experiment identity, or injects hypothesis records. The evidence tools are
  still available on demand. Runtime provider/fleet settings were not changed.

Natural-C requirements, ownership, lint and the full retail hash gate remain.
Freedom to experiment is not permission to manufacture progress or repeat an
identical failed candidate indefinitely.

## Non-agent optimizations and measurements

Profiling found repeated signature inventory scans and repeated parsing of the
large objdiff metadata file inside a single request.

1. Context now reuses its recovered/propagated signature index for every referenced
   declaration. On the profiled target this reduced `recovered()` calls from 20
   to three; the remaining two are separate lifter work, not repeated declaration
   lookups. Existing signature invalidation was not weakened.
2. `Project.objdiff_units()` caches the parsed read-only mapping for that Project
   instance. It invalidates on device/inode/size/mtime_ns/ctime_ns changes.
   Real-metadata fixture checks verified reuse and invalidation after a same-size
   edit with the original mtime restored. All existing callers were checked for
   read-only use. This is not a new compiler-result cache.
3. Manual seed initialization avoids a useless placeholder check, unnecessary C
   retransmission and redundant alternate-draft context for an already supplied
   source. It changes no gate for accepting a function.

Five warm samples per operation, fresh Project per sample, same live machine:

| Metric | Before | After |
|---|---:|---:|
| Context median | 0.9841 s | 0.3239 s |
| Check median | 0.4062 s | 0.3258 s |
| Signature inventory calls in target context | 20 | 3 |
| Manual prompt characters | 5,498 | 1,690 |
| Worker prompt characters | 7,760 | 2,359 |
| Objdiff metadata reused within one Project | no | yes |

That is about 3.04x faster context construction and 19.8% lower check latency
in the final local samples; the prompts are 69.3% and 69.6% shorter by character
count. These are not tokenizer measurements, API-price estimates, controlled
provider comparisons, or demonstrated end-to-end matching-yield improvements.
Earlier repeats were around 2.7x for context and 20% lower check latency,
illustrating live-machine variability. The final raw samples are retained.

The generic unbound context still includes substantial target/source material:
34,939 -> 33,730 characters in the sample. Most text is actual asm/C/types rather
than the removed protocol. Truncating it indiscriminately would trade correctness
for a misleading token reduction. A seeded claim supplies its actual source once
and suppresses redundant draft sections through the existing supplied-source path.

## Further optimization decisions

- Continue improving deterministic batching and shared native ABI/layout recovery
  when there is a concrete cohort; a new worker/model is not required for those.
- Do not build another prompt/triage framework. Optional packet/clustering tools
  must justify their cost on the actual blocker.
- Do not silently turn `check` into an unverified cache response to make latency
  look better. Cached diff reads already exist; actual acceptance probes remain
  real compiler/object checks.
- A larger persistent service or new disk cache was not justified by this profile.
  The measured duplicate work had smaller fixes. Evaluate remaining compiler,
  objdiff, file hashing and transport overhead on representative unfinished bodies
  before adding more infrastructure.
- `CLAUDE.md` still contains 57,807 characters of project rules and technical
  reference. Agents that auto-load it can pay substantially more startup context
  than the short portable prompt. A rule-preserving reference split is a further
  token-cost opportunity; this pass did not silently remove those instructions
  or claim a measured saving from such a split.
- A future agent run should be evaluated by linked native functions/bytes per
  elapsed time/cost. This pass deliberately made no paid agent run and claims no
  new native closure from a tool-only replay.

## Verification and evidence

Real manual-claim before/after probes, MWCC replay, profile counts and five-sample
wall timings, metadata invalidation and frozen-seed rejection are archived in
`state/repairs/execution-throughput-validation.json.gz`. Existing regression
tests, compilation/lint and all 16 output hashes are checked for the final commit.
No new repository unit-test suite, worker, provider change, global cap reset,
remote push or merge was used.
