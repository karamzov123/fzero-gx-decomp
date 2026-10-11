# New fzgx autonomous fleet

## Current owner override (2026-10-11): Hermes Step 5 Preview Free Ultra

The four existing `oc1`..`oc4` lane identifiers now pin the `hermes` transport,
`stepfun/step-5-preview:free` through Nous, and `ultra` reasoning. This replaces
OpenCode/Space Bunny for those lanes only; other provider controls are preserved.
The six bound MCP tools, no-native-tool guard, compiler-progress idle timeout,
atomic claims, session limits and six-session fleet cap remain unchanged. Historical
low-effort and OpenCode measurements below do not authorize fallback substitution.
Ultra's earlier stall evidence remains a risk, not a reason to silently lower the
explicit owner pin. Startup/activity is not a match; compiler receipts and all
sixteen hash checks are required evidence.

Finding 304 now has a 228-body compiler/settings recheck and portable source archive.
Before retrying a near-miss, supply its measured source hash, compiler and flags via
`--seeds`; the plain universal-1.3.2 histogram is historical, not final.

## Current owner direction: interactive five-provider bar, bounded six-session fleet (2026-10-07)

The owner directed one grouped tile (not per-model icons) for the four matcher lanes, now running the **hermes** transport against `stepfun/step-5-preview:free` on the Nous portal at `low` reasoning; concurrency for the group is capped at 4 and the fleet total at 6, allocated as those ×4 + Codex ×2. The bar remains five provider tiles: Claude, GPT, Cline, AGY, and the grouped matcher tile. Its tooltip lists the four lane states and has left-click group toggle, right-click scale-up, scroll scale, and middle-click log controls. All four lanes are enabled; the control still refuses to bypass a provider cooldown. Automatic surge remains disabled.

The opencode transport was retired for these lanes on measured evidence: the opencode free tier answers the fleet's restricted matcher agent with `403 FreeTierError: OpenCode's free tier can only be used from within Opencode` for every free model (`step-5-preview-free`, `muse-spark-1.3-contributor-free`, `ling-3.1-flash-free`), which parked all four lanes as `unavailable` within a minute. The same model is served by the Nous portal through hermes, which keeps the identical six-tool/no-shell boundary: hermes runs with `--toolsets fzgx`, so the only advertised tools are `mcp__fzgx__write_unit|patch_unit|check|search|read_evidence|release` plus its own MCP bridge (`tool_search`/`tool_describe`/`tool_call`, confined to the enabled toolset). The matcher contract travels in the prompt because hermes has no agent-prompt flag.

At the latest readback, `fzgx-fleet.service` and `fzgx-awake.service` are active. The refreshed Ninja/DTK gate passed all 16 target hashes before work. The Eww bar was reopened on monitor 0; its OpenCode tile read 3/3 sessions active and showed four lanes, with lane 4's retry timer. The small-model trial evidence remains limited: `gpt-6-luna` is the Codex catalog ID (not `gpt-6-luna-900k`) and has no exact-match evidence in the bounded trials; Space Bunny is explicitly selected by the owner despite its recent non-match trial outcomes. Keep the six-tool/no-shell matcher boundary and do not claim a match before link verification.

The repaired seed path and bounded Claude results are recorded below/at [the fleet resume](FLEET-RESUME-2026-10-07.md). Sonnet 5.5 and Haiku 5.5 both hit Anthropic `429 usage_limit_reached` before inference; their effectiveness is untested and nested subagents remain disabled.

GitHub publishing uses the existing authorized `fzgx-integrator.timer`, which is active. Fresh publisher-receipt and `git ls-remote origin refs/heads/main` readback confirmed `b40b1db4322c8c793e4193628f45418ac35e8cb8`. It publishes verified committed snapshots only and does not stage working-tree edits. The local `origin/main` tracking ref may remain stale because the publisher deliberately does not fetch; use its receipt plus `ls-remote` for live status.

### Gate recovery (2026-10-07, after the 16:23 failure)

The earlier supervisor failed when a repeated Ninja gate exceeded its uncaught 180-second timeout. Successful gates now persist in `runtime-v3.json` as `passed_gate` and are reusable only for the exact HEAD/context/split-unit identity. Changed identities gate again. Unchanged failures block every family in the same tick and later ticks/restarts; no model dispatch is allowed on a failed gate. Only successful Ninja plus the explicit sixteen-target DTK check records a passed identity. Ninja now has a 600-second bound; Ninja/hash timeouts return a logged failure instead of terminating the daemon. The local overnight systemd drop-in raises `TimeoutStopSec` to 900 seconds to accommodate the gate and tool drain; boot enablement and resource limits are unchanged.

Scratch timeout/cache and real-scheduler regressions passed, as did group-control regression, Python compilation and lint (zero findings). On recovery the service-owned gate finished and all sixteen target hashes reported OK. Fresh status showed Codex ×2, AGY ×1 and OpenCode ×3; the grouped Eww tile read 3/3 active, and oc4 retained `retry_at=1791441782.6341531`. Thermal admission briefly held oc1 and then admitted it without overriding the guard. These activity checks establish operation, not a new match. The latest verified delivery remains AGY's `fn_1_E1A00` at `454f918a`.

Two wibo SIGABRT core records at 16:13 identify the same GC/1.3.2 fixup probe for `fn_13_3FC`, not the Ninja gate command. They remain separate compiler-probe evidence; no causal attribution to the gate timeout is established.

## Historical owner policy: models only for bounded tests

The previous test-only hold and Exo-only policy below are historical and have been superseded by the latest explicit owner direction. See the live `model-policy.json`, `control-v3.json`, and service status for current operation.

See [the current completion frontier](COMPLETION-FRONTIER-2026-10-07.md) for Exo's prior native-client admission findings, model-free declared-BSS recovery, and the large-candidate residual limits. Its test-only execution instructions predate this renewed owner authorization; the no-shell matcher boundary and data-ownership cautions remain valid.

## Superseded test-only snapshot (pre-authorization)

The following completion-frontier findings retain historical evidence but do not define current launch controls. The renewed owner direction above and the live policy/control files take precedence.

See [the current completion frontier](COMPLETION-FRONTIER-2026-10-07.md) for Exo's prior native-client admission findings, model-free declared-BSS recovery, and large-candidate residual limits. Its test-only execution instructions predate the current fleet authorization; the no-shell matcher boundary and data-ownership cautions remain valid.

## Historical audited operating envelope (2026-10-07)

See [the completion/overnight audit](OVERNIGHT-AUDIT-2026-10-07.md) for the measured whole-project baseline, resource evidence, tests, and unresolved blockers. This entry supersedes older capacity/model counts below: standing sessions are Claude ×2, GPT ×2, AGY ×1; Cline is off. Only oc1/oc4 remain in the surge family set, one session each; oc1 explicitly pins Fledge Alpha Free, oc4 Space Bunny. Both were held for 24 hours after real failed transport/tool-use trials, not promoted on catalog availability. The global ceiling is eight actual sessions, with host admission safeguards and a systemd resource envelope. OpenCode models are pinned per command rather than written into shared agent configuration.

`honest` now includes the root DOL and its objects. `tools/fleet_audit.py` provides read-only, atomic full-project snapshots; `fzgx-audit.timer` refreshes them every thirty minutes without model requests. Pre-existing dirty source modules are quarantined from dispatch for each daemon run. The overnight fleet was started without newly enabling it on every boot; `fzgx-awake.service` holds a sleep/idle inhibitor while the fleet is active. The Oracle VM's full root filesystem makes it ineligible for workers until storage headroom is restored.

This is `~/projects/fzgx`, not the legacy NATC/PM fleet. The enabled user service `fzgx-fleet.service` runs `tools/fleet.py daemon`, whose entrypoint delegates to `fleet_multi.py`. Do not enable the conflicting old `fzgx-autopr.service`.

## Explicit model policy

All model IDs are pinned and controls never silently substitute providers. The current session mix is matcher lanes ×4 (hermes), Codex ×2, capped at six. All four lanes are enabled; Claude and Cline remain off.

| Provider | Requested model/effort | Runtime identifier |
| --- | --- | --- |
| Claude | Opus 5.5 High | claude-opus-5-5, high |
| GPT | 6.1-Sol Medium | gpt-6.1-sol, medium |
| AGY | Gemini 3.8 High | gemini-3.8-flash-high, high |
| Cline | Space Bunny Alpha High | stealth/space-bunny-alpha, high |
| Hermes matcher lanes | Step 5 Preview Free low ×4 concurrent | stepfun/step-5-preview:free, low |

Reasoning effort on the Hermes lanes is pinned to `low`, not claimed universally optimal. Earlier medium samples were bimodal; new bounded medium probes still produced zero compiler receipts even with exactly six direct MCP schemas registered. A low-effort probe on `fn_1_1384C` performed ten real compiler cycles in 318 seconds, but delivered no oracle match. These samples are not a controlled benchmark. The Hermes default compiler-progress idle bound is now 240 seconds, independently overrideable with `FZGX_TOOL_IDLE_TIMEOUT_S`. It measures compiler receipts, not stdout, reasoning, or discovery calls; silent sessions drain and save/release before advancing. Other provider defaults remain unchanged.

AGY's installed authenticated model catalog recognizes that identifier. Quota failure remains quota failure, not permission to choose a different model. Its reset time is parsed for automatic retry.

## Hermes matcher lanes and the controlled pool

Four `oc1`..`oc4` lanes (lane ids retained for ledger continuity) are configured with the same exact pin, `stepfun/step-5-preview:free` at `low`, served by hermes through the Nous portal. They share one tile; each lane appears in its tooltip. Group controls are operator-driven: left-click toggles the group, right-click/scroll-up adds a session, scroll-down removes one, and middle-click opens the active lane's log. The group respects `OPEN_CODE_ACTIVE_CAP = 4` and the global `FLEET_CAP = 6`, so four matcher sessions plus Codex ×2 fill the cap and AGY must stay off while all four lanes run. A cooling lane is not force-enabled. `automatic_surge` remains false, so paid-provider state cannot silently enable the group.

Each Hermes session advertises exactly the six bound matcher tools and no shell/filesystem. `fleet_clients.hermes_command` prepends the matcher contract (previously constructed but discarded), uses `--ignore-rules --source tool`, and builds an isolated, reusable disk-backed fleet runtime home under `~/.cache/fzgx-agents/hermes-runtime/active`. It copies configuration privately and configures it through the installed CLI: only the bound `fzgx` server, native six-tool include filter, resource/prompt utilities disabled, and `tools.tool_search.enabled=off` so schemas arrive directly without discovery round trips. Auxiliary title generation is disabled to avoid an additional competing model request for every matcher startup. Function/agent environment uses per-process placeholders; setup is serialized and signature-cached. Auth is reused; the runtime/dependency environment is shared across matcher sessions rather than rebuilt per function, avoiding hundreds of MB per session and exhausting `/run/user/1000`. The operator's interactive configuration and memories remain unchanged. Any native tool call — terminal, file, web, delegate — remains a session-ending violation in `fleet_provider.py`. Compiler-progress silence triggers descendant drain before cleanup. Catalog presence, running processes, or compiler attempts are not deliveries: only link-verified oracle acceptance counts.

The opencode transport has three constraints that are load-bearing and easy to
regress: the client runs from a directory outside `$HOME` (opencode loads `AGENTS.md`
upward, and `~/AGENTS.md` is an unrelated project's contract); `XDG_CONFIG_HOME` points
at a shared private config root that exposes only the six bound tools (writing the
config without redirecting `XDG_CONFIG_HOME` leaves the session with a full shell); and
the binary is resolved explicitly to the official client, because the free models answer
403 `FreeTierError` on any other build. A runtime guard in `fleet_provider.run` kills any
session whose first non-`fzgx_*` tool call appears.

## Execution contract

The host assigns explicit unique symbols through orchestrate.py. Atomic SQLite claims, private source copies, and shared-unit/pending reservation exclusion prevent overlapping assignments. Models receive source, assembly and initial diff, and exactly six function-bound operations: write_unit, patch_unit, check, search, read_evidence, release. The host binds identity and handles submission and serialized 16-target hash verification. Accepted source is committed locally by the existing verifier. Worker/model transports never push. A separate user-authorized deterministic publisher forwards verified local main commits to the fork; it does not integrate candidates.

GPT uses the constrained Codex app server. Claude uses restricted mode, no builtin tools, strict MCP and no interactive permission prompts. Cline uses its genuine SDK and existing account, five supplied tools, no model/native tools, sequential execution and high reasoning. AGY uses a session-local HOME with the existing account state and only the bound MCP server, plus a PreToolUse deny guard; personal broad project plugins/configuration are not merged. Its native tools are denied rather than prompt-trusted. AGY print mode soft-denies `call_mcp_tool` without a grant, so the session-local `settings.json` allows exactly `mcp(fzgx/<tool>)` for the five bound tools; without it every session ends `incomplete` with zero checks. Cline's per-response output cap is 32,768 tokens: at 8,192, high-effort reasoning truncated 32 of 209 turns before any tool call.

Sixteen checks, five stale checks (the matcher core's defaults), three attempts and forty model turns bound a session. There are no token guards (2026-10-01): cumulative input counts re-read cached context on every turn, so the former 256,000-token guard killed productive Claude sessions at seven checks, reported them as crashes, dropped the rest of the batch and triggered exponential backoff. Provider quota rejections keep their own cooldown. Time limits are hang detectors only: 30 minutes per session, 15 minutes without any log event in a batch, and a batch deadline scaled to its function count. A runaway-log guard (64 MiB per session slot) remains. Cline's SDK reports usage only when a response ends; there is no missing-usage watchdog. A batch that finishes cleanly without a match is not a failure and is followed immediately by fresh work. `FZGX_MAX_MODEL_INPUT_TOKENS`/`FZGX_MAX_MODEL_OUTPUT_TOKENS` still work when set; 0 disables them. Failed/quota backoff still survives restart. Runtime adapter changes invalidate schedule context; accepted commits do not themselves justify repeated attempts. Empty eligible inventory idles without model calls.

A real Ninja and DTK hash gate runs before work. Bootstrap health records credit zero matches. Singleton ownership, orphan recovery, graceful signal draining, mixed systemd kill mode and bounded restarts prevent duplicate hosts and preserve candidate work. Existing old branches/worktrees are preserved.

## Cline effort and output cap (2026-10-03)

`fleet_cline.mjs` hardcoded `reasoningEffort:'high'` in three places and `maxTokens:32768`
beside it, so `fzgx --effort` never reached the SDK for this harness — the `POLICY` entry was
decorative. Both are tunable now:

    ~/.cache/fzgx-agents/cline-tuner.json   {"effort":"xhigh","maxTokens":65536}

The file is read **per session**, so a change lands on the next batch without restarting the
daemon (a restart drains in-flight work). `FZGX_CLINE_EFFORT` / `FZGX_MAX_MODEL_OUTPUT_TOKENS`
still win when set, for a one-batch override. With no file and no env the harness keeps its
old defaults (`high` / 32768). `node tools/fleet_cline.mjs --describe` reports what a session
will actually use — check that before blaming a setting for not working.

**Current: effort `xhigh`, maxTokens 65536.** The cap went 32768 → 65536 deliberately, not to
128k: 65536 is the standard next step on an OpenAI-compatible endpoint (`api.cline.bot`),
whereas a request above the model's real output ceiling comes back as a 400 and fails the
whole session rather than slowing it. If a batch dies immediately after this change, that is
the first thing to suspect — revert the file to `{"effort":"high","maxTokens":32768}`.

**Order matters, and it is the opposite of what the flag names suggest.** On this endpoint
`maxTokens` bounds the whole completion, reasoning included. So raising the cap is what buys
room to think; raising `effort` at an unchanged cap spends the *same* budget faster and makes
truncation worse. The measured symptom was 32 of 209 turns truncated before any tool call at
32768. Both are raised here because the cap increase is what makes the effort increase
affordable — had only the effort moved, the expected result was fewer, not more, usable turns.

`ultra` exists only for hermes: `orchestrate.py --effort` accepts it, and hermes is the sole
transport that reaches it. Measured on `stepfun/step-5-preview:free` it stalls the model on a
full-size assignment, so the lanes are pinned to `low` (see the effort table above); the value is
accepted for re-measurement, not for use.

Cline (`stealth/space-bunny-alpha`) and the matcher surge families
(`stepfun/step-5-preview:free` via hermes) are free with no usage limit for a few more days. That
changes the allocation rule, and it is worth stating plainly because the obvious
efficiency ranking points the other way.

Measured over the overnight window (2026-10-02 18:00 onward), per family:

| family | attempts | matches | rate | worker-hours | matches/hour | cost |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| `gpt` | 269 | 51 | 19.0 % | 10.72 | **4.76** | quota |
| `oc2` | 31 | 5 | 16.1 % | 4.96 | 1.01 | free |
| `oc1` | 60 | 8 | 13.3 % | 11.08 | 0.72 | free |
| `oc4` | 70 | 8 | 11.4 % | 12.70 | 0.63 | free |
| `cline` | 379 | 31 | 8.2 % | **73.34** | **0.42** | free |

On efficiency alone this says cut Cline: 0.42 matches/hour against GPT's 4.76, an 11x gap,
and Cline alone consumed 62 % of all fleet hours for 30 % of the matches. **That reasoning
is wrong while Cline is free.** Efficiency per hour only decides allocation when hours are
the scarce input. Cline's hours cost nothing and are unlimited, so its low conversion rate
costs nothing either — it is spare capacity that happens to be slow. Cutting it would buy
back wall-clock time that can then be spent on... nothing, because GPT cannot absorb it:
its throughput is quota-capped, not slot-capped.

So the rule while the free tier lasts: **push work onto the free families and leave the
quota families at whatever their quota allows.** GPT stays at `parallel 2` (its cap);
Cline was raised 6 -> 8. Surge capacity is deliberately not operator-scalable — it comes
and goes with paid-provider availability — so the standing free family is the only lever.

Two things bound this, and both are real:

- **Shared build lock.** Every check serialises on it. Cline sessions are long (about 700 s
  each, against GPT's 143 s), so raising Cline's parallelism can delay a GPT submit. GPT is
  the highest-yield family, so it must not be starved. Watch GPT throughput; if it drops,
  back Cline off. `active` slots stay within `FLEET_CAP` 18.
- **This is a time box.** When the free tier ends, this rule inverts and the efficiency
  table above becomes the right basis. Re-measure then; do not leave Cline at 8 by default.

Worth noting at the time of writing: GPT was `rate-limited`, i.e. the paid providers were
down and the free families were the only capacity actually running.

The fleet stopped committing for 70 minutes: four provider batches each ended with an unlocked `snapshot` + `git add state/ledger.json`, and `snapshot` truncated the 13 MB file in place. A rewrite under another batch's `git add` kills git with SIGBUS (reproduced: 32 of 60 adds), git does not remove `.git/index.lock` on that signal, and every later `git add` exits 128, so each verifier failed, every family was held and backed off, and one pool match stayed uncommitted. Now `Ledger.snapshot` replaces the file atomically, the batch-end snapshot commit holds `submit.lock` like the verifier, and both call `oracle.clear_stale_index_lock()` first (lock older than 30 s and no git process in the repository). Symptom to recognise: all families `error` with `Hash verification failed; saving and holding producers.` while `gate.log` says `16 files OK`; read the batch's `verify.stderr.log`.

## Deterministic search in the loop (2026-10-01)

Measured on the day's sessions: about 70% of a near-miss's residual rows were register allocation, agents permuted declarations by hand at one check per guess, and the repair engine ran only at release with 2 rounds x beam 2 in 6 seconds. The same engine at 12 rounds x beam 6 compiles 6,000-14,000 variants in 12-18 seconds.

- `api._search_body` is that deep search (150 s budget, three concurrent slots). It runs at release for any body at 80% or better, before a retry's model request (`claim --repair`, bound fleet claims only), and on demand through the sixth tool `search` (three uses per attempt; an exact result is accepted, a better body replaces the work copy, otherwise nothing changes and no check is spent). A searched body gets `<body>.searched.json` (engine hash, variants); the same body is not searched again until the engine changes. When a search improves a body without closing it, the improved body is what the next attempt receives.
- Check output marks rows `L` when only a section/pool base or a displacement off it differs (`stuck.layout_rows`) and states how many rows are the matcher's, by kind. The retry context lists only those rows, says when the search has already exhausted permutations, and lists edits earlier sessions compiled without gain (`context._tried_edits`).
- A failed compile spends a check but not a stale check; fewer differing rows than the attempt has seen resets the stale counter (the score metric changes once pool rows appear).
- Functions past the three-attempt cap with a saved body at 90% or better that the current engine has not searched are eligible once more (`fleet_multi.unsearched_near_misses`); the release marker ends that. The claim cap is therefore enforced by selection, not by `--max-attempts`.
- Restored upstream history names saved bodies under `/Users/rayan/fzgx/.fzgx/attempts/` that are not on this machine: of 567 capped functions at 90%+ under 1 KiB, 464 have no local body. Those upstream attempts (DeepSeek, effort-none and Luna batches) no longer count toward this fleet's cap: selection counts only `fleet-v2-*` attempts (`fleet_multi.local_attempts`), which raised the eligible pool under 1 KiB from 434 to 1,390 functions and its 90%+ share from 15 to 579 (a 2026-10-01 snapshot; both pools shrink as the fleet matches and caps functions). Without a local body they start from the mechanical draft; the committed repair archives hold C for only a few of them.
- First result: `fn_14_82E4` (99.0% under Claude and AGY) matched after one `search` (register rows and pool primed) plus two structural edits. One of those undid an engine bug, fixed here: the one-field carrier rewrite renamed text inside string literals (`"%d"` became `"%d.value"`).

## What counts as an attempt (2026-10-02)

`local_attempts()` counts a `fleet-v2-*` attempt only if it ran a check, spent tokens,
or matched. A provider refused for quota, credits or transport still writes an *ended*
attempt row, but one with no checks and no tokens: no evidence and no work. Those rows
were consuming a slot against the three-attempt cap and retiring the function from
selection. 139 such rows existed when this was measured (58 codex, the rest
agy/claude/cline/opencode), and about 27 functions were at the cap on nothing but those
rows; fixing the predicate returned them to the pool with no data migration. Both
numbers move while the fleet runs. Upstream history (below) is still excluded for the
original reason.

Provider refusals are also now read correctly. The Codex app-server reports them as
events (`{"method":"error","params":{"error":{...}}}`) and Claude as a result row;
`provider_error_text` previously matched neither shape, so a usage limit extracted no
text, was classified a generic error, and got a 60 s backoff instead of the rate-limit
path. Reset times are now taken from the provider: `try again at Oct 2nd, 2026 1:08 AM`,
`try again at 1:08 AM` (date omitted), `resets 1am`, and `Resets in 46h40m56s` all
resolve to the stated wall clock.

Broken-batch detection reads terminal outcomes from the ledger
(`fleet_multi.batch_outcomes`). It used to read `<run dir>/results.json`, a filename
nothing has ever written — the codex transport writes `results.jsonl` and the bound
harnesses write no results file at all — so the list was always empty and a batch whose
every session crashed was treated as a clean batch that matched nothing, relaunched
three seconds later, indefinitely.

## Eww and diagnostics

The wrapper `~/.config/eww/scripts/fzgx-agent-fleet.py` execs the project venv. Icons show green recent claim activity, amber starting/idle, red stalled/error, grey disabled and an hourglass for quota cooldown. Activity is not a match claim. Tooltips include selected model, symbols, checks, batch matches, unique verified fleet total and retry time. Left toggles each family; right/up increases sessions; down decreases them; middle opens logs.

Use:

    systemctl --user status fzgx-fleet.service
    ~/.config/eww/scripts/fzgx-agent-fleet.py status
    journalctl --user -u fzgx-fleet.service -n 50 --no-pager
    eww poll fzgx-agents

Claude stream events named `rate_limit_event` are not themselves failures. `allowed` and `allowed_warning` permit requests; only `rejected` indicates an actual quota rejection. Quota classification examines structured error fields rather than assistant/tool text or event names. A captured live-log regression and allowed/rejected/error cases verify this boundary. The false Claude cooldown was cleared and a fresh Opus session performed a compiler check after restart.

State/control/history/runtime live in `~/.cache/fzgx-agents/*-v3.json`. Evidence remains under `.fzgx/runs/fleet-v2-*`; that prefix is retained for progress provenance. Gate log is `~/.cache/fzgx-agents/gate.log`. Eww reload can close the bar: inspect active-windows, reopen bar if needed, and poll before reading cached state.

## Non-competing fork integrator

`tools/fleet_integrator.py` is a deterministic publisher, not another decompilation agent. The existing `fzgx verify` watchers remain the sole owners of candidate acceptance and source commits. The publisher does not drain pending candidates, manipulate claims, stage files, commit, merge, rebase, reset, or force-push.

`fzgx-integrator.timer` runs a single oneshot approximately every two minutes. It requires local main and the exact origin fetch/push URL `https://github.com/karamzov123/fzgx.git`. It checks remote main ancestry and blocks on unknown/divergent history. It rejects obvious retail/auth artifacts in outgoing commits. This filename screen is not a general secret scanner; never commit secrets or proprietary binaries.

For a new SHA it acquires the existing submit.lock then build.lock nonblockingly. Busy locks yield immediately to workers/verifier. Pending ledger/dependency records and tracked/index changes defer publication without modifying them. Untracked personal files are preserved and never staged. A clean unchanged HEAD must pass Ninja's GFZE01/ok target, an explicit 16-target DTK hash check, and lint. Failed gates are persisted and not rebuilt for an unchanged commit. Success persists a receipt for that exact SHA; unchanged verified commits do not rebuild during network retries.

Compiler locks are released before network operations. A normal explicit-SHA fast-forward push updates only fork main, and an exact ls-remote readback is required before reporting publication. Newer local commits wait for the next tick. Network timeouts/auth failures produce status and retry on the timer; interactive login is prohibited. Divergence never triggers a merge or force push. The old fzgx-autopr.service stays disabled/conflicting.

Reproducible service templates live in tools/systemd/. Operational state and gate log live in `~/.cache/fzgx-agents/integrator-v1.json` and `integrator-v1.gate.log`.

    .venv/bin/python tools/fleet_integrator.py status
    systemctl --user status fzgx-integrator.timer
    journalctl --user -u fzgx-integrator.service -n 20 --no-pager

To stop automatic publication without stopping matching:

    systemctl --user disable --now fzgx-integrator.timer

Real local Git/bare-remote acceptance fixtures cover fast-forward/readback, unchanged gate suppression, dirty/index preservation, pending work, compiler-lock yielding, failed-gate suppression, changing HEAD, untracked preservation, remote divergence, destination/branch rejection and outgoing retail-artifact rejection. No unit tests are added to the project repository.

## Verified rollout evidence

Initial constrained batches accepted fn_12_38340 (38c65f05), fn_12_2EE7C (7e11f357); subsequent fleet telemetry records three unique verified symbols, last e7ce845b. This is not a promised throughput rate.

The four-provider policy/adapter scratch acceptance suite passes nine checks; the updated controller suite passes ten. Python compile and Node syntax checks pass. Real Ninja, DTK report `16 files OK`, and fzgx lint reports zero findings. No mock tests are added to the repository.

Live restart shows Opus 5.5 High and GPT 6.1-Sol Medium making checked attempts; Space Bunny Alpha High emits genuine model usage through its SDK. AGY's real request is blocked by account quota and autonomously schedules retry using the returned reset duration. Do not report AGY as productive while quota-blocked. Read live status for current counts; these are not static guarantees.

## Provider fallback: agy serves Opus on Gemini quota exhaustion (2026-10-03)

A quota failure used to mean the family simply idled, wasting the slot. `agy` now has a
declared fallback: it keeps its own transport (existing login, PreToolUse guard, six bound
MCP tools — all verified) and swaps **only the model** to `claude-opus-5-5` at `high`, taking
the `>=1 KB` band so it works the cold large functions like `gpt` does.

- Normal: Gemini 3.8 Flash High, unchanged band behaviour.
- On a measured **rate-limit**: switches to Opus 5.5 High, tile reads
  `Opus 5.5 High (agy fallback)`, band `(1024, inf)`.
- On the next clean batch, the fallback clears and Gemini resumes.
- If no batch finishes cleanly, the dwell now expires after `FALLBACK_TTL` (30 min) and the
  primary is re-probed. See "Running unattended" below: the unbounded dwell was real.

This does not weaken the no-silent-fallback rule it sits next to. That rule exists so a quota
failure is never quietly answered with a different model; this swap is declared in `FALLBACK`,
operator-directed, shown in the tile, the runner banner and the log, and persisted in
`runtime-v3.json` so a daemon restart cannot drop the family back onto a model just measured
out of quota. An `error` — as opposed to a rate limit — does **not** trigger it: a transport
or tool failure says nothing about quota, and swapping on it would hide the real fault.

Only `agy` declares a fallback; `claude` and `gpt` are unaffected. Reverting is deleting the
`FALLBACK` entry.

## Running unattended

The supervisor runs as a systemd **user** service (linger is enabled, so it survives logout):

    systemctl --user status  fzgx-fleet.service
    systemctl --user start   fzgx-fleet.service
    systemctl --user stop    fzgx-fleet.service     # deliberate stop stays stopped
    journalctl --user -u fzgx-fleet.service -f

The unit lives at `~/.config/systemd/user/fzgx-fleet.service`, outside this repository, so
it is not versioned with it. Re-create it from this section if the checkout moves.

Three properties it depends on, each of which was a real defect:

- **`Restart=always`, not `on-failure`.** The supervisor's SIGTERM drain exits 0, so
  `on-failure` read a normal stop as a completed run. The unit ran 14h44m and then sat
  `inactive (dead)` with nothing to bring it back. With `always`, a duplicate launch is
  harmless anyway: the `flock` in `run()` makes the second supervisor exit immediately with
  a one-line message.
- **`StartLimitBurst=20`, not 3.** A drain plus a manual restart costs several restarts
  inside 30 minutes, and at Burst=3 the unit reached `failed` and stayed dead. A limit that
  trips on normal operation defeats the point of the unit.
- **`TimeoutStopSec=300`, not 90.** The drain waits on bound tools, and with four families
  mid-batch it outlasts the default; stopping early strands claims.

To verify recovery rather than assume it:

    kill -9 $(systemctl --user show fzgx-fleet.service -p MainPID --value)
    sleep 40 && systemctl --user show fzgx-fleet.service -p NRestarts --value   # expect >= 1

A clean SIGTERM can take minutes by design, because the drain is doing work. That is the
supervisor preserving best bodies and releasing claims, not a hang.

Claims are recovered on startup regardless (`run()` releases anything still marked
`fleet-v2-*` before dispatching), so a hard kill costs a batch, not the ledger.

## Scratch growth in `.fzgx/fixup/sessions` (2026-10-04)

`.fzgx/fixup/sessions/<symbol>/` reached **192 GB** and was the single largest
consumer on the volume (84% full, inodes 88%). It is not evidence and nothing in it
is tracked: `git ls-files .fzgx/` is empty and `.gitignore:46` excludes the whole
tree.

Per session, `Engine` writes four things (`fixup.py:98`, `:232`):

| Entry | Nature |
| --- | --- |
| `report.json`, `cache.json` | durable result and compile cache — **keep** |
| `declarations/` | small declaration scratch — keep |
| `sources/<identity[:24]>.c` | every candidate body ever tried, content-addressed |
| `objects/<group>/<sha>.o` | every candidate's compiled object |

`sources/` and `objects/` are pure regenerable scratch: `record()` rewrites a source
only when absent and raises on a hash mismatch, and `compile_chunk` overwrites the
object group per compile. Worst observed was `customize___epilog` at 721 objects /
116 MB and `colchg_menu_disp` at 7537 sources / 31 MB — a single function's search
history. Nothing prunes them, so the directory only grows.

Safe cleanup, while the fleet is idle (no `fzgx.py fixup` running):

    cd .fzgx/fixup/sessions
    for d in */; do rm -rf "$d/sources" "$d/objects"; done

That reclaimed **~175 GB** and took the volume from 84% full to 54%. It costs
nothing: re-running a session regenerates both, and `report.json`/`cache.json`
still make the rerun cheap — verified by re-running a session afterwards and
getting an identical compile. **Do not delete `report.json` or `cache.json`** —
the cache is what makes a repeat run skip compiles.

Without this, a long fixup campaign fills the volume: growth is proportional to
candidates tried, and the largest sessions were `customize___epilog` (721 objects,
116 MB) and `colchg_menu_disp` (7537 sources, 31 MB) for single functions.

Two smaller consumers, both outside this repo and both deliberate build outputs:
`~/projects/fzero-gx-online/build` holds ~7 GB of built ISOs (five 1.4 GB images)
and `~/projects/fzero-gx-native` ~5 GB of extracted retail data. Neither is
scratch; both are reproducible from source, so they are the next place to look if
the volume needs more room.

## Report tables: no cell renders empty (2026-10-04)

669 of the 960 batch reports had a completely empty **Turns** column, which reads as
a broken render rather than as a measurement that was never taken. The cause is
structural, not cosmetic: `turns` is parsed from the Codex app-server's `num_turns`
(`orchestrate.parse_claude`), and no other harness reports it. `claude_command` passes
`--max-turns 40`, but a cap is not a count. So the column was dead for every provider
in use — cline 154, oc4 139, oc1 137, oc3 60, oc2 59, claude 59, agy 58, gpt 2 — and
zero reports carried a value.

Every cell now gets an explicit `-` when the harness did not report it
(`_pct`/`_num`), and each report states which case it is in:

    Turns: not reported by the cline harness (capped at 40 per session).

That distinguishes "not measured" from "not measured here", which is the difference
between a readable table and one that looks broken. If turn counts are actually
wanted, the fix is in the harnesses — have each emit its turn count in the result
record — not in the report.

Unrelated: `docs/dtk/` is vendored upstream DTK documentation and has 11
lists split by blank lines. Left alone deliberately; it is not this project's prose
and rewriting it would diverge from upstream.

## Target availability census (2026-10-04, corrects an earlier claim)

It was reported here that the fleet was "out of fresh work" because only 4 virgin
targets remained. **That was wrong**, and it conflated *virgin* with *eligible*.
`virgin_symbols` is an **ordering priority** (`order()` sorts virgin first), not an
availability filter — it does not exclude anything. Availability is `ATTEMPT_CAP`
(2 attempts by this fleet), `link_failed()`, and `size_allowed()`.

Measured through the fleet's own functions against the live ledger:

| Stage | Count |
| --- | ---: |
| unmatched | 1617 |
| under `ATTEMPT_CAP=2` | 966 |
| excluded by `link_failed()` | 0 |
| excluded by the size gate | 206 |
| **fully eligible** | **760** |

So batches returning 0/N is a **conversion-rate** result, not starvation. The gate
is also correctly placed: all 206 size-blocked functions are over 2 KB (117 at 2-3 KB,
54 at 3-4 KB) and sit at 65-85%, which is exactly the band the gate's own evidence
measured at 0/10. Opening it further would contradict the measurement.

The ordering is already right too: with 4 virgin symbols the `-best_percent` sort
takes over and serves the 95-100% band first, which is where the difficulty is. The
lever is conversion at that band, not more targets — so do not widen the gate to
"fix" a 0/N batch.
