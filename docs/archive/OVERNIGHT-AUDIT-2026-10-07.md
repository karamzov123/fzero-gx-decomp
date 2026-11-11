# New fzgx: completion audit and overnight operating plan

Date: 2026-10-07. Target: `/home/armandofm/projects/fzgx`, branch `main`.
This is the new matching-decomp project, not gx-forge or legacy NATC. This document distinguishes measured evidence, implemented changes, and future experiments. It is not a claim of global optimality or an estimate that the project can finish tonight.

## Measured baseline

- The current build passed `ninja -j4 build/GFZE01/ok` and `build/tools/dtk shasum -q -c config/GFZE01/build.sha1`: **16 files OK**. `fzgx lint`: **0 findings**.
- The prior `honest` command silently excluded the DOL because it searched only configuration subdirectories. Fixed root `main` symbol/split discovery and `src/dol` object accounting, with a failing-then-passing fixture regression test. `.init` functions are counted too. No retail/auto split receives authored credit just because it links.
- Full known-symbol baseline: **7,308** nonzero functions, **5,692** authored, **1,616** not authored; **1,126,920 / 2,924,488 bytes = 38.5339%**. A smaller credited-minus-authored discrepancy remains intentionally visible.
- DTK reports **2,937,044 text-code bytes**, leaving **12,556 bytes** outside the known-function-size denominator. Completing `honest` alone does not prove every executable byte has a source owner. Reconcile this gap before declaring project completion.
- Remaining known bytes: **1,797,568**. `main_rel` accounts for **55.99%**. Functions over 2 KB account for **709,472 remaining bytes**. The existing size gate cannot be the permanent completion strategy.
- Local-attempt accounting found no virgin unmatched functions below 1 KB; there are **294** virgin 1–2 KB functions and **181** virgin functions above 2 KB. Repeatedly mining exhausted small functions is not the primary next phase.
- The local DTK report also measures data: **1,748,651 / 5,068,465 bytes = 34.500603%**, leaving **3,319,814 data bytes** outside that matched-data count. The code matcher fleet alone cannot finish data ownership. These are DTK data metrics, not a new independent semantic-ownership proof.
- Seven-day historical terminal results (observational, different target difficulty; not a fair model contest): Claude Opus 5.5: 42/151; GPT 6.1-Sol: 125/805; AGY Gemini 3.8: 24/117; Space Bunny oc1: 26/145; oc4: 31/147. Null-model/error rows are separate in the snapshot. Terminal matches must still be distinguished from verified delivery.

The repeatable evidence source is `tools/fleet_audit.py`, using only the authoritative `.fzgx/ledger.db` opened read-only. Do not use the untracked `state/fzgx.db`; it is not this project's ledger. Historical rate statistics include overhead and are not an ETA.

## Model discovery and actual trials

Installed CLIs were inspected: OpenCode 1.18.35 (pinned for `--pure`), system OpenCode 2.0.0, Claude 3.5.0, Codex 0.160.1, AGY 1.13.5. The installed OpenCode catalog includes `opencode/fledge-alpha-free`.

- Fledge Alpha: a real function-bound CLI trial on `fn_14_6044`, max 6 checks, ended in 9.8 s with **FreeTierError 403**, before any checks. Provider: “OpenCode's free tier can only be used from within OpenCode.” This was already the official CLI. Do not claim model incompetence from this, spoof provider headers, or enable shell/filesystem tools to pass provider admission. Root cause is not definitively established. Official OpenCode issue #49433 discusses related failures.
- Space Bunny control on `fn_1_210A8`: 274 s, **0 checks**, 31,999 reasoning tokens, ended `length`. It responded but did not execute a tool call. Not a successful decomp trial. A preceding mistyped-symbol invocation failed assignment and was excluded as model evidence.
- Both free lanes are held for 24 hours for review. Fledge remains an explicit experimental model pin, not a silent alias/fallback. Cline's withdrawn OpenRouter Space Bunny model stays off.
- Corrected mixed-model routing: shared OpenCode agent configuration is now model-independent; each command has an explicit `--model`. Existing `--pure`, denied built-ins, six bound tools, and no subagents remain intact.
- Corrected surge accounting: reserve actual configured sessions, not one slot per family. Admission also enforces the global ceiling.

Provider documentation: https://opencode.ai/docs/zen/ and https://opencode.ai/data/unknown/fledge-alpha . Fledge may use collected trial data for model improvement; Space Bunny's published policy says zero-retention/no training. No credential values were printed or added to prompts. Do not infer the real vendor behind a stealth name.

## Implemented overnight route and laptop envelope

- Main route: **Claude Opus 5.5 High ×2**, **GPT 6.1-Sol Medium ×2**, **AGY Gemini 3.8 High ×1**. Preserve the established, explicit AGY quota fallback mechanism; do not add a new hidden paid API fallback.
- This five-session route was started and exercised. At 02:47:49 EDT the live control file was changed externally to **Claude off, GPT ×1, AGY ×1**. The newer controls were preserved rather than overwritten. At the subsequent readback both active lanes had real compiler checks, the supervisor had no restarts, and there were no newly link-verified matches in the initial launch window. Model activity is not completed decompilation.
- Free reserve: oc1 Fledge and oc4 Space Bunny, one session each, held as above. They are not promoted merely because their price is zero. Existing surge policy remains dependent on measured paid-provider availability.
- Global session ceiling **8**. Final systemd envelope: **2 CPU equivalents**, CPU/IO weight 25, nice 10, MemoryHigh **8 GiB**, MemoryMax **10 GiB**, TasksMax **768**. The fleet started with six CPU equivalents, but a live 93 C reading prompted reducing its running quota to two without interrupting claims. The laptop has 22 logical CPUs and about 14 GiB RAM; this leaves headroom for desktop, compiler bursts, and unrelated services rather than assuming idle RAM is all available to agents. Thermal admission holds alone do not throttle already-running deterministic compiler searches.
- Pause admission below **2 GiB available host RAM**, **8 GiB disk free**, **100,000 free inodes**, at **90 C** or hotter, or at **25% battery off AC**. These are admission controls: existing bounded sessions drain, not an instantaneous thermal kill switch. cgroup limits protect the outer resource envelope.
- Existing session bounds remain: 16 checks, 5 stale checks, 1,800 s/session, bounded turns, serialized build/tool calls, live verification, provider reset-aware cooldowns, and no blind attempt-cap bypass except established evidence tiers. Cumulative cached input token limits are not reintroduced: earlier measured limits killed productive sessions.
- Pre-existing operator edits in `src/rel/pilotpoint/pilotpoint.c` are preserved. The entire pilotpoint module is excluded from autonomous dispatch for this daemon run, preventing workers' file commits from absorbing those edits. Existing modified `fleet_multi.py`, `fleet_cline.mjs`, and untracked model probes were not discarded.
- `fzgx-fleet.service` runs independently of this terminal, with its existing automatic restart and bounded SIGTERM drain. It is started, not newly enabled at every boot.
- `fzgx-awake.service` holds an actual login1 sleep/idle inhibitor and is bound to the fleet service. Keep the laptop plugged in, ventilated, and preferably with its lid open. Manual suspend, network loss, or a critical battery event can still interrupt work.
- New `fzgx-audit.timer` updates an atomic read-only snapshot every 30 minutes without a model request. It does not claim to send notifications to this CLI session.

The Oracle VM is **aarch64, 2 CPUs, 6.7 GiB RAM**, with **only 231 MB free on a 30 GB root filesystem (100%)**, and existing services/swap use. It is excluded tonight. No files/services were deleted or changed on the VM. Cleanup and independent storage headroom are prerequisites to using it for dashboards, artifact hosting, or isolated compilation; adding a fleet to that host now is unsafe. Never run desktop OAuth credentials on a public website worker or upload retail binaries to public storage.

## Best path to completion: ordered workstreams

### 0. Prefer deterministic SDK/data recovery before expensive model search

Follow the orchestrator contract: identify remaining CARD/OS/EXI/SI targets, reuse the existing SDK-import pipeline and recorded CC0 source revisions, preserve array bounds/callback signatures, and prove layout/data/relocations plus all sixteen targets before acceptance. `docs/RESOURCES.md` records MKDD/TWW SDK and MK Deception Sofdec adaptations and their provenance archives. Reuse the established compiler-response/capture engine for new generators; do not add another repair runner. SMB is the closest engine relative but lacks a license in the listed source, so use vocabulary only, not copied code. Community format research and decomp.me scratches are targeted references, not permission to upload retail binaries or share private credentials. This phase is a prioritized follow-up, not a claim that a new import batch was executed by this audit.

### 1. Deliver verified bytes, not large match-count headlines

Continue subscribed-model work on fresh 1–2 KB bodies and bounded structural repairs. Track verified authored bytes per wall-clock day, pending versus verified candidates, null-tool sessions, and blocked transport time. Do not use pooled terminal success or function-count completion as the sole dashboard. Existing live verifier and hash gate are stronger than post-hoc model claims. Keep object-equal/link-unequal cases out of matcher dispatch; use `why-link` with a reproducible link delta instead.

### 2. Graduate to large-function structural recovery

After observing the current night, run stratified, compiler-backed trials on virgin >2 KB bodies, at **one** expert session initially. Measure bytes delivered and wall time against the current 1–2 KB route; expand the size gate only on evidence. For large functions, build compact control-flow, field-offset, call-signature, literal-pool, and loop-shape evidence before spending checks. Use existing structmap/flagcell/lifter/constraint/capture tooling; do not proliferate disconnected duplicate harnesses.

Prioritized byte-heavy targets include `fn_1_BC310` (9,832 B), `fn_1_C4ABC` (9,240 B), DOL `fn_8005DCEC` (7,920 B), customize `fn_3_15A0` (7,680 B), `fn_1_10E3B4` (7,252 B), and `fn_1_120804` (6,980 B). These are a measured backlog, **not assigned tasks or permission to exceed current worker scope**. Pilotpoint stays quarantined until its operator edits are resolved.

### 3. Preserve and route compiler knowledge rather than regenerate it

The current assignment already delivers target assembly, exact flags/data bytes, sibling declarations, best body, real residual rows, previous failed edits, and compiler idioms. Keep this evidence flow. Near-miss tasks should start from the saved best body and a stated structural hypothesis; virgin tasks should start from a bounded draft. Avoid giant universal notes and repeated declaration-order sweeps, especially where the assignment records thousands of previous variants. Improve the existing selective knowledge path only with measured prompt/tool-call results. Convert reproducible captures and matching deltas into compact version/compiler-specific lessons, not global assertions about MWCC.

### 4. Benchmark genuinely new models safely

Discover through installed CLI catalogs and official provider pages, not search snippets alone. A catalog entry is availability metadata, not a capability proof. Require a tool-call/permission probe, then fixed representative decomp tasks with the same contexts, budgets, and correctness oracle; log actual model identity and compare difficulty strata. For matched-function controls, avoid handing the model the finished source as the answer. Do not use an API wrapper to evade a CLI-only free tier. Trial Nous/OpenRouter pools or new stealth releases only through an authenticated, proven six-tool transport, with public/non-secret context and no unsanctioned paid fallback. No arbitrary subagents in matcher sessions.

### 5. Close source ownership and module organization

The endgame includes DOL/SDK/compiler helper ownership, literal pools, cross-module imports, remaining C translation-unit grouping, data ownership, and the 12,556-byte denominator gap. `tu-migrate`, source alignment, and compatible reference research are specialist work, not reason to let every matcher modify build flags. C bodies must be portable within the approved project conventions, not wholesale asm, raw opcode arrays, register-name locals, or fabricated 100% markers. Keep immutable retail assets out of commits. A complete source build must independently reproduce all sixteen targets.

### Website and ecosystem evidence

The live upstream endpoint `https://decomp.dev/rayanht/fzgx.json?mode=overview` returned a **2026-09-16** commit (`3a0542c9d1b58f7a907f932bc00e3657b382e9aa`) and **30.597702% matched code**. It is not a live dashboard for this laptop's current fork. `https://decomp.dev/karamzov123/fzgx.json?mode=overview` returned **Not found**. The upstream “Game Code 100%” category is a filtered category, not whole-project completion. Use the local full-project accounting and exact verification receipts now; add a fork-specific public dashboard only from approved metadata/public source and an independently verified publication workflow, not by replacing the owner of the upstream report. Keep hosting and read-only reporting off the full Oracle root filesystem until it is safely repaired.

## Permissions and tooling policy

Matcher tools remain exactly `write_unit`, `patch_unit`, `check`, `read_evidence`, `submit`, `release`, bound to the runner-assigned function. No claim/inventory/context/shell/web/files or delegation tools. Supervisor controls capacity and routes; compiler/verifier decides success. No queue-pointer guessing, blanket approval, credential scraping, or automatic public publishing of retail bytes. New errors get classified, not counted as attempts to decompile successfully.

New maintained repository artifacts: `tools/fleet_audit.py` and `tools/systemd/` unit templates. Per AGENTS.md's no-repository-unit-tests rule, the seven controller/accounting regressions live outside the repository in `/home/armandofm/.local/share/fzgx-audit/tests/`; they passed after demonstrating relevant failures before fixes. Real bound model/compiler sessions, lint, and the full sixteen-target gate remain the repository acceptance evidence. One attempted `fzgx selftest` command is not supported by this CLI and is not counted as a passing gate.

## Morning inspection and safe stop

From `/home/armandofm/projects/fzgx`:

    .venv/bin/python tools/fleet.py status
    .venv/bin/python tools/fleet_audit.py --output .fzgx/overnight-latest.json
    .venv/bin/python tools/fzgx.py honest --closure
    .venv/bin/python tools/fzgx.py lint
    ninja -j4 build/GFZE01/ok
    build/tools/dtk shasum -q -c config/GFZE01/build.sha1
    journalctl --user -u fzgx-fleet.service -n 50 --no-pager

Compare `.fzgx/overnight-baseline-20261007.json` with `.fzgx/overnight-latest.json`. Latest state is atomically replaced, not a cumulative narrative log.

Safe stop:

    systemctl --user stop fzgx-fleet.service

Allow up to 300 seconds for the existing drain protocol; do not kill the compiler or clear the ledger. The awake inhibitor stops with the fleet. Optional stop for the read-only periodic monitor:

    systemctl --user disable --now fzgx-audit.timer

The existing publisher correctly refuses a dirty source tree. Operator source edits were not committed just to make auto-publishing succeed; local verified worker commits can continue. Tooling and this audit are committed locally under the shared submission lock; the controller commit includes the already-present model-withdrawal/backoff and batch-wave changes it builds upon, without discarding them. No promise of a clean tree or pushed audit commit is made while intentional pre-existing source/client changes remain.
