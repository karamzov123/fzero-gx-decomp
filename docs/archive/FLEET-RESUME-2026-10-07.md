# Verified fleet resumption

The owner renewed production authorization by asking to continue getting the fleet running on useful functions. This supersedes the earlier test-only hold in FLEET.md and COMPLETION-FRONTIER-2026-10-07.md; it does not authorize weakening matcher execution boundaries or reactivating failed providers.

## Admitted lanes and resource envelope

- GPT: `gpt-6.1-sol`, medium, two simultaneous sessions.
- oc1: `opencode/exo-free`, guarded native OpenCode, initially two simultaneous sessions. The existing selector favors the 1–2 KiB fresh supply, with bounded mid-band, one-word, and oversize shares.
- Claude, AGY, Cline and oc4 remain off. AGY's recent admission trials crashed; Cline's withdrawn pin and the previous oc4 failure are not cleared by another provider working.
- Global ceiling remains six; initial admitted total is four. Automatic surge is disabled explicitly in model-policy.json, so disabled paid lanes cannot silently enable a failed free lane.
- Existing service limits remain CPUQuota=200%, MemoryHigh=8G, MemoryMax=10G, TasksMax=768; admission also checks memory, disk, inodes, temperature and battery/AC. No VM worker is allocated.
- Starting the user service does not newly enable it at boot. The existing BindsTo sleep inhibitor is started with the requested unattended fleet.

## Recovered fixes and evidence

The interrupted work had already exercised two Exo sessions simultaneously: `exo-parallel-admission-20261007` recorded eight compiler checks, two saved releases, no crashes and zero matches. Its pre-execution receipts recorded only allowed fzgx tool calls. `exo-attested-20261007` separately recorded the guard initialization before its real bound edits. The earlier bash-denial provider rejection is not a general Exo outage.

The native adapter advertises native tools for provider compatibility but denies their execution in `tool.execute.before`; this is not an unrestricted-shell matcher. `fleet_opencode_launch.py` primes a private loopback/password-protected server and refuses any model request unless its guard receipt contains the current random nonce and exact server PID. The provider-level violation monitor remains a second boundary. Ordinary non-Exo OpenCode lanes retain hard-denied tools and `--pure`. Personal OpenCode/Codex configuration and authentication are not modified.

A direct pre-execution guard regression denied bash/edit/write/read/task/unknown/fzgx_claim and allowed exactly the six bound names. Historical live guard evidence also recorded `bash` with `allow:false`. Do not remove the guard, skip attestation, or use this compatibility advertisement on any untested transport.

`oracle.check` now normalizes list-valued manifest compiler flags to a shell-quoted string before compiling and persisting the result. The earlier real fn_80056084 reproduction compiled with `-O1` after this fix instead of throwing in shlex.

Fresh post-fix admission `codex-resume-admission-20261007` ran two main_rel functions, fn_1_C1394 and fn_1_E9770, with six checks/three stale checks/240 seconds per session: eleven actual checks, both saved releases, zero failures, zero matches, no live-verifier errors. This proves the transport and compiler path, not newly delivered code or an estimated overnight conversion rate.

The recovered selector repairs prevent multiple selections of the same existing unit, enforce the oversize probe count rather than comparing against unavailable pool shares, and do not withhold entire pools when their cap rounds to zero. The promoted Exo lane now obeys operator stop/scale controls rather than being incorrectly treated as manually untouchable surge capacity. Eleven external controller regressions pass; no tests were added to this repository.

## Routing and acceptance

Live inventory before launch contained 1,593 unmatched functions. Do not interpret an eligible function or historical near-match score as a verified result. Models receive a fresh initial compiler/diff result, actual saved C and compiler settings. Existing per-context history and attempt caps remain; no caps are inflated to keep lanes busy. Completed bounded admissions are recorded in current-context dispatch history so startup does not immediately repeat the same test functions. Accepted commits alone do not reset the context.

Pre-existing pilotpoint source edits are quarantined by module at daemon startup. Both pilotpoint.c and fleet_cline.mjs were hash-recorded before deployment; neither is staged in this tooling commit. Untracked operator scripts and state/fzgx.db are left alone; the authoritative ledger remains .fzgx/ledger.db.

Fresh acceptance before launch: Python compile, Node syntax, fzgx lint (zero findings), locked Ninja, and the explicit DTK sixteen-target hash check. The verifier remains the only matcher integration path; no manual configure/Ninja/DTK calls while workers run outside the existing locks. Matching C is not credited until link_state=verified. There is no clean-tree or remote publication claim while unrelated operator edits remain.

## Live rollout outcome

The initial four-session rollout produced one actual code delivery: main_rel:fn_1_5D1B8 (444 bytes), matched by `fleet-v2-gpt-1791381122859784455-codex-2` after six checks, accepted at fdbe02d5 with status=matched and link_state=verified. A concurrently running shared verifier used the Exo batch in the commit title; the matched attempt proves Codex ownership. The interpreter/source score alone is not the acceptance evidence.

Production Exo sessions, despite earlier successful standalone admission, exited with zero tool calls and empty client logs. The exact server sessions reported `AI_APICallError: ... Upstream request failed: Endpoint is unavailable.` This is a new upstream outage, not the old CLI-only rejection or a reason to relax the guard. oc1 was disabled with the repaired operator control and drained; no Exo claims/processes remained at readback. Automatic surge remains disabled. Final enabled capacity is two Codex sessions only, with the user service and its inhibitor still active.

At live readback, Codex was doing compiler checks on fn_1_B5310 and fn_1_12C110, reaching 94.875595 and 97.80822 respectively. Those are saved/working candidate scores, not additional accepted functions. The queued batch also contains bounded oversize work and fresh approximately 1 KiB main_rel functions. Historical results must not be counted as new delivery.

The pre-existing operator-file hashes remain unchanged. The tooling commit is 086baeba, with final rollout facts recorded separately. The tree still contains unrelated operator changes; no remote push is claimed.

## Owner check-in: exact Exo CLI pin

The owner clarified that the requested new worker is **Exo Free in the OpenCode CLI**, exact model `opencode/exo-free`, not a Hermes model and not a substitution from the larger catalog. The current production adapter already invokes the official `/home/armandofm/.opencode/bin/opencode` with that exact model through the attested launcher.

Fresh bounded `exo-owner-real-checkin-20261007` on fn_1_53E40 initialized the guard successfully but made zero tool calls/checks. Its exact session ses_ee9307671ffeU2KRacpQdi562K repeatedly reported `Upstream request failed: Endpoint is unavailable` for the matcher. The CLI returned zero, but the host correctly classified the incomplete session as failed and released it. Exo is not re-enabled on this evidence. No personal configuration/authentication or standing provider controls were changed. An earlier command-substitution syntax error created an empty-symbol failed test batch; it did not exercise a model and is not counted as admission.

Before that clarification, restricted Ling 3.1 Flash and Nemotron 3.5 Lightning catalog trials both returned the nonretryable FreeTierError 403. Admission-only reuse of the existing attested adapter produced one allowed write/check for Ling before timeout; Nemotron attempted the blocked `invalid` tool. Neither was promoted; those trials do not prove anything about the requested Exo model.

Live control readback is GPT/Codex parallel=2 plus owner-enabled AGY parallel=1. The GPT tile is the Codex app-server transport, not a separate GPT-versus-Codex provider pair. Preserve this external AGY enablement rather than restoring the previous off configuration. At the final live readback, two Codex functions and one AGY function had actual compiler checks.

Since production resumption, matched-attempt/verified-link intersection proves two new unique deliveries, both Codex-owned: fn_1_5D1B8 (444 bytes, fdbe02d5) and fn_1_7FD7C (628 bytes, 6f72e7ae). Saved improvements and AGY activity are not additional verified matches. Eww's stale 399/zero-batch-verification display is not the authoritative delivery count; another lane's shared verifier may have accepted the function.

## Earlier owner update: bounded small-model tests only (15:16 EDT; superseded by 15:40)

The owner asked to continue the new fleet and evaluate GPT-6 Luna plus Claude 5.5 Sonnet/Haiku. Production resumed with the existing verified lanes: Codex `gpt-6.1-sol` ×2 and owner-enabled AGY `gemini-3.8-flash-high` ×1; `fzgx-awake.service` was started explicitly. The pre-start Ninja and DTK gate passed, including all 16 retail target hashes. Pilotpoint operator source edits remain quarantined. Automatic surge and the failed Exo/OpenCode fleet lanes remain off.

A startup failure was traced to the new untracked `state/fleet/priority-seeds.json`: mixed work batches passed it as a mandatory manifest, but most selected symbols had no seed, and inline `source` entries lacked the `path` key that `api.claim` assumed. `fleet_multi.command` now passes the manifest only if every assigned symbol has a valid source+SHA record; `api.claim` accepts inline source or path and validates the SHA. `py_compile`, direct selection tests (seeded vs mixed vs normal), and a real seeded one-function OpenCode attempt passed the repaired path without claim crashes. The seeded `fn_1_12C110` attempt retained 99.589% after four checks; it did not match.

Model tests were bounded, run through their normal restricted harnesses, and did not produce an exact match. Codex's live catalog lists `gpt-6-luna` as API-supported (not the requested `gpt-6-luna-900k` alias). A four-check shadow replay on matched `fn_1_8D3F8` scored 0%, while a separate `__cvt_dbl_usll` attempt reached 51.16% in two checks. The existing GPT-6.1-Sol model scored 100% on that same matched-body replay, so the present sample does not support replacing Sol in production. Space Bunny Free did run via native OpenCode: a shadow replay reached 99.18% before timeout; an actual `__init_registers` attempt reached 2.78% (assembly-only GPR setup blocked by the no-inline-asm rule); the seeded `fn_1_12C110` attempt plateaued at 99.589%. Those non-match results did not justify promotion at that time. The later owner direction at 15:40 explicitly selected four Space Bunny lanes with a hard three-session OpenCode ceiling, documented below; retain the other guards and do not override lane-specific cooldowns.

Claude Sonnet 5.5 and Haiku 5.5 both returned Anthropic `429 usage_limit_reached` before any model tokens or tools (reported reset 3:40pm America/New_York); their effectiveness is untested. Do not retry before reset. Do not enable nested Haiku subagents: the harness is deliberately restricted to six bound tools. Current live status should be read from `systemctl --user status fzgx-fleet.service`, `fzgx-awake.service`, and `tools/fleet.py status`, not inferred from this dated note.

## Owner update: grouped OpenCode controls and live six-session mix (2026-10-07, 15:40 EDT)

The owner clarified the Eww design: keep the existing five provider tiles (Claude, GPT, Cline, AGY, OpenCode), keep OpenCode as one grouped icon, show four configured Space Bunny Free instances in its tooltip, and provide controls. The target concurrency is `FLEET_CAP=6`: OpenCode ×3, Codex ×2, AGY ×1. The four OpenCode lanes are all pinned to `opencode/space-bunny-free` xHigh; `oc4` remains off until its existing cooldown expires. No cooldown was cleared. OpenCode tile left-click toggles the group, right-click/scroll adjusts the group size, and middle-click opens a lane log.

The OpenCode group control was regression-tested in scratch for toggle, scale-up/down, exact global-cap arithmetic, and cooldown preservation. Python compilation and Eww reload passed; the bar was opened on monitor 0. Live readback showed six sessions: three Space Bunny lanes, two GPT/Codex, one AGY. After 90 seconds the three OpenCode lanes had 12 combined checks; one plateaued at 99.59% and two continued at 94.92%/98.1%. No exact match was established by those checks. Preserve the tool allowlist and wait for the lane-4 cooldown rather than overriding it.

GitHub publishing resumed through the existing authorized timer after its earlier stop. Fresh publisher receipt and `git ls-remote origin refs/heads/main` now confirm `b40b1db4322c8c793e4193628f45418ac35e8cb8`. The publisher uses its committed-snapshot gate and does not stage the dirty worktree. The remote-tracking `origin/main` may stay stale because this publisher does not fetch.

## Gate-timeout recovery (after 16:23 EDT)

The fleet failed on an uncaught 180-second Ninja timeout; the bar alone did not prove a working fleet. The controller now persists an exact successful gate identity across ticks/restarts, regates changed identities, and blocks unchanged failures, including other families in the failing tick. Ninja and DTK timeouts return logged gate failures. Ninja's bound is 600 seconds and the local overnight service drop-in now allows 900 seconds for graceful stopping; resource limits and disabled boot enablement are unchanged.

Scratch timeout/cache, real-scheduler and OpenCode-control regressions passed; Python compilation and lint passed with zero findings. The restarted fleet's own Ninja plus explicit DTK gate returned all sixteen hashes OK. Both fleet and inhibitor were active at readback; live status showed two Codex, one AGY, three OpenCode sessions, with the grouped tile reporting 3/3 active. No cooldown was cleared: oc4 remains off with `retry_at=1791441782.6341531`. Pilotpoint stays protected. Latest verified delivery is AGY's `fn_1_E1A00`, accepted at `454f918a`; recovery activity is not another match.

The two 16:13 wibo SIGABRT cores name the same GC/1.3.2 `fn_13_3FC` fixup probe. They do not establish the cause of the Ninja gate timeout.

## Operation

    systemctl --user status fzgx-fleet.service
    .venv/bin/python tools/fleet.py status
    journalctl --user -u fzgx-fleet.service -n 40 --no-pager
    systemctl --user stop fzgx-fleet.service

Stopping drains tools and preserves candidates; its BindsTo inhibitor stops with it. A running/green icon establishes activity, not a match. Inspect the live ledger and batch verifier evidence for delivery.
