# Fleet bottleneck repair — 2026-10-07

## Scope and acceptance

Preserve the owner's five Eww tiles, grouped four-lane OpenCode controls, Space Bunny Free xHigh pins, six-session ceiling (Codex two, AGY one, OpenCode three), and oc4's existing cooldown. No throughput claim is a source-delivery claim. Keep unrelated source, split, state and tooling changes out of the scoped tooling commit. Scratch regression fixtures remain outside this repository as required by AGENTS.md.

## Demonstrated operational defects and repairs

- Provider output can keep batch log timestamps fresh without a completed compiler operation. A per-session receipt-driven watchdog now bounds this interval to 600 seconds by default. Completed write/patch/check/search operations reset it; provider chatter and cached-evidence reads do not. Active bound operations suppress idle cancellation. Partial JSONL receipts are retained until complete. A stopped session keeps its actual process return code and a durable `.guard.json` reason. The runner distinguishes tool-idle/deadline timeouts and saves the candidate without another release-time search. The pinned model and effort are unchanged.
- Existing protection inspected dirty source but not dirty split ownership. The admission guard now excludes modules containing either type of operator edit. This prevents a successful autonomous acceptance from absorbing unrelated split changes. Protection is a startup admission snapshot, not permission to edit a reserved module while a worker owns it.
- The prior successful-gate identity omitted dirty source, root splits, symbol bindings and untracked source dependencies. The identity now incorporates their content. It is rechecked after taking submit/build ownership and after a successful gate; a changed identity is not credited with stale verification. The unchanged-identity success/failure cache remains in place.
- The service has a two-CPU resource quota, while deterministic pools defaulted to sixteen compiler workers and verifier relinks had no explicit Ninja limit. `FZGX_COMPILE_WORKERS` and `FZGX_BUILD_JOBS` now permit bounded process-local limits. The local fleet overnight drop-in sets both to two, leaving existing CPU/memory/thermal limits and session controls intact. The authorized publisher already uses Ninja `-j 2`. Parallelism is not a compiler flag and does not change candidate semantics.

## Exact AGY evidence

The session `fleet-v2-agy-1791405796815120628-agy-1` did perform bound tools; later checks disprove a permanent zero-check stall. Long no-tool intervals and large reasoning outputs are the relevant operational cost, not proof of a stuck MCP call.

Recovered historical terminal logs:

- `fleet-v2-agy-1791403101906647843-agy-3`, `fn_1_2F294`: rc 1, result error says the previous response exceeded the output token limit. Reported output and thinking counters are both 62,917. That is provider-output exhaustion, not a 429 quota refusal.
- `fleet-v2-agy-1791400587183415651-agy-2`, `fn_1_135D7C`: rc 1, result error `interrupted`, after four checks. The reason for interruption is not established merely by this log.

Do not silently change AGY effort/model or clear a provider cooldown to hide either condition.

## Fresh source frontier, not historical scores

After draining the fleet, candidate-only MWCC checks used saved C and retained available compiler metadata, with serialized submit/build ownership. They did not submit or accept any source:

| Symbol | Historical score | Fresh score | Differing / instruction rows | Disposition |
| --- | ---: | ---: | ---: | --- |
| movie_module:fn_12_23410 | 100.0 | 97.180855 | 7 / 191 | Current source-level residual, not a demonstrated current link rejection |
| interview:fn_17_7728 | 99.971565 | 99.971565 | 1 / 211 | Address-form residual; preserve and inspect the measured row, do not repeat identical source |
| main:fn_800288C4 | 99.84127 | 99.84127 | 2 / 63 | Fresh two-row residual, retained GC/1.2.5n setting |

The latest meaningful `fn_12_23410` ledger notes already state its old split gap was repaired and its 97.2% remainder was source-level. A historical 100% score is therefore not an acceptance fact. The diagnostic `why-link` showed zero module byte differences at its current configuration; it does not prove these saved candidates are exact. One subagent's assertion that the latest attempt was a link rejection was contradicted by direct ledger readback and was not implemented.

Full source paths, SHA-256 values, settings and fresh results are in the local scratch receipt `fzgx-bottleneck-fresh-oracles.json`. Existing saved bodies remain in `.fzgx/attempts/`; this receipt is diagnostic evidence, not a portable accepted-source archive.

## Remaining genuine evidence gaps

`customize:fn_3_15A0` stays blocked. Its historical best bodies were stored under `/Users/rayan/...` and are not locally available. None of the 21 local compressed repair archives mentions the symbol. Recovering that host's source or producing a new independently measured reconstruction is required; a guessed body or another unchanged stochastic attempt is not a repair.

The remaining 1,593-function backlog cannot be declared fixed by operational changes. Large-region semantic reconstruction and current-engine residual diagnosis remain source work. Keep old-object-score, current-object-match and link-verified delivery distinct.

## Review-driven safety checks

The independent safety review exposed a real descendant-drain hole. The runner now verifies all live processes in the original session, captured ancestry, or exact bound agent environment, using PID start-time cookies before sending signals. A still-active MCP operation drains first, including a child that created a new session and ignored SIGTERM. A failed drain raises a dedicated hard-stop exception past automatic release, and the startup recovery guard also sees surviving bound descendants. The claim is retained rather than reused. An unwritable diagnostic log must not downgrade that safety exception.

MCP receipts now include unique operation IDs and explicit success. Receipt appends use an advisory inter-process lock and flush a whole JSON record before unlocking. Duplicate/unmatched ends cannot clear a different concurrent operation. Failed operations do not reset the compiler-progress deadline. Malformed records, non-finite/overflowing timestamps, file loss, replacement or truncation make activity uncertain and disable idle cancellation until process ownership can be proved drained. The recognizer accepts actual `api.format_check()` verdicts, not arbitrary model prose. Untracked target-TU collisions are excluded individually; untracked split files protect their module. Unrelated data-only imports are retained without freezing every main_rel target.

The review's claim that `git diff HEAD` omits staged edits was disproved with a real scratch Git repository: staging a source edit still changes the HEAD-to-worktree gate identity. No redundant index-only hashing was added.

## Validation performed

Scratch regressions exercised incremental tool receipts, no-tool chatter with a real harmless subprocess, active-tool drain behavior, guard-status classification, dirty ownership protection, changed gate inputs, gate-cache success/failure across scheduler ticks/restarts, identity changes during verification, process-local job limits, and grouped OpenCode control/cooldown invariants. Each new behavior's regression was observed failing before implementation. Additional regressions cover unique/successful MCP receipts, surviving descendants in a new session, retained claims on drain errors, and startup orphan detection. Python compilation and `fzgx lint` passed. With the fleet drained, the real two-job Ninja plus explicit DTK gate passed all sixteen hashes. The service-owned and publisher gates remain the authoritative deployment checks.

Two diagnostic subagents and an independent safety reviewer ran at delegation depth one. Reports were read-only and independently checked before changes were chosen. Follow-up review precedes deployment.
