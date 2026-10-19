# Agent contract (Codex and any other harness)

This repository is driven by a small CLI so that any agent harness can do the
same work. Read `CLAUDE.md` for the project overview; this file is the
contract a subagent must follow. The Claude Code versions of these roles live
in `.claude/agents/*.md` and say the same things.

Do not add unit tests to this repository. Validate tooling changes against real
functions with MWCC, retail object diffs, `fzgx lint`, and the 16-target hash check.
Commit completed work locally before reporting it finished. Include the tooling,
provenance, and dependent source changes needed to reproduce generated matches.
Matchers and integration tooling must never push. The user-authorized
`tools/fleet_integrator.py` publisher is the sole exception: it may publish a
clean, hash/lint-verified pinned local `main` commit to the approved fork using
a normal fast-forward push. It must never accept candidates, merge, rebase,
force-push, or change worker ownership.

## Matcher (one function per session)

Headless Codex matchers use `tools/orchestrate.py` and one shared local Codex
app server. The runner claims each function, installs its saved C, and supplies
context plus the initial object diff before starting the model. Matchers have
no shell or filesystem tools. Their dynamic tools are `write_unit(source)`,
`patch_unit(old, new)`, `check(versions)`, `read_evidence(section, cursor)`, and
`release(reason)`; the host binds
the function and identity, so models cannot select another unit.

Continue the supplied C. Writes compile and diff immediately. A full oracle
match submits automatically; check/stale limits save and release automatically.
The host interrupts the turn before returning a terminal tool result. No claim,
submit, administrative release, or final RESULT message is required from the
model. Voluntary release is for a concrete technical obstacle. Numeric limits
belong in runner flags and tooling, never matcher prompts. Compiler probes
retain the selected compiler and archive the body with its compiler settings.
Evidence reads page through the selected compile's complete diff and decoded
retail data without compiling or consuming checks. Use the supplied cursor;
changing the work copy or compiler invalidates the cached diff.

The manual CLI (`uv run tools/fzgx.py ...`) and MCP server
(`tools/fzgx_mcp.py`) retain claim/context/check/submit/release operations for
humans and other harnesses. `fzgx verify` relinks all 16 targets and verifies
every hash before committing accepted source. Batches verify every 60 seconds by
default and drain again on exit; completed matches do not wait for outlier models.
Rules enforced by tooling:
no hardcoded addresses, no inline asm, no writes outside the assigned work copy.

Shared data is integrated independently with `fzgx data-import --apply`, never
through a matcher claim. Preserve recovered header types. The importer proves
MWCC layout, initialized bytes and relocation bindings before transferring splits,
then checks all 16 hashes. `--regenerate --apply` recreates saved imports;
`--recipes state/dataimports/recipes.json` applies measured text layouts.
Jump tables and code-interior pointers remain with their reconstructed functions.

## Librarian (serial; stronger model)

Applies name proposals (`fzgx names`), promotes shared structs into
`include/`, merges fully matched ranges into translation units, adjusts data
ownership in `splits.txt`, appends to `docs/MWCC_IDIOMS.md`. Always ends with
`python3 configure.py && ninja` printing `16 files OK`, `fzgx lint`,
`fzgx snapshot`, and a concise commit describing the actual changes.

## Triage

For functions with `attempts >= 3`: `fzgx block SYMBOL --reason "..."`
and a row in `state/blocked.md`. Triage is local only. Never create GitHub issues
for this repository; issue creation is not part of the workflow.

## Orchestrator

Prioritize deterministic SDK C imports (CARD, then OS, EXI, SI) regardless of
function size. Under-256-byte functions (`--max-size 255`) remain useful repair
corpora, not a gate on identified larger functions. Prefer deterministic work: `fzgx trivial`, `fzgx reuse`, and size-filtered `fzgx fixup`/`fzgx stuck`;
fix recurring failure modes in the tooling before spending agents on them.
SDK imports must preserve inferred array bounds and callback forward declarations.
Try native section objects with measured gaps and BSS first-access primers when
extern aggregate views lose TU addressing. Keep primers in `.fzgxpool`, normalize
promoted symbol names, and bind interior globals through the existing verified
subobject-relocation path. Recheck generated candidates after importer changes.
Register-field similarity is not proof of an allocation problem: inspect value-flow
and operand-order diagnostics first. `fzgx fixup --capture` captures/replays
the stock allocator; selection-order witnesses require a source-realizability
check and a stock-compiler oracle result before integration.
`fzgx fixup --captures PATH` projects captured PCode constraints into generated C;
recapture after changing source, headers or compiler settings. All deterministic
fixups use this engine, including release and lifter callers. Add candidate
generators to it; never add another standalone repair/search runner. Target-object
indexes and normalized-object caches must retain module identity, including REL
entrypoints. Reject stale frozen targets before accepting their scores.
Prioritize the largest unresolved regions and their saved near-match corpus.
Inspect value flow, control flow, data layout and compiler evidence; fix the
structural causes directly. Do not launch Luna agents or swarms. Record measured
repairs in `docs/batches/<date>.md`, which is intentionally untracked (see
`79a5ea74`), so it is a local report and not a deliverable; committed provenance
goes to `state/ledger.json` via `fzgx snapshot` and to `state/repairs/`.

Model sessions (`--parallel`) and local tool processes (`--tool-parallel`) have
separate limits. App-server JSON-RPC command backpressure is separate again;
a burst of thread starts must not prevent completed turns from being stopped.
Never modify personal Codex configuration or auth. All worker overrides stay
inside the runner. Do not use in-process subagents. See
`docs/CODEX_APP_SERVER.md` for transport, diagnostics, and failure handling.

## Large near-match evidence

Refresh saved candidates against current retail objects before ranking them; raw
objdiff percentages can hide hundreds of differing words in large functions.
Keep source structure and compiler settings in portable repair archives. Shared
BSS members accessed through a section base still require individual module,
section, address and size proofs before their definitions can be externalized.
Compiler-response cache keys must include allocated symbol definitions, even when
all accesses use a section base. Portable archives must retain word-scored frontier
candidates that have not received a full objdiff score. When attempting to link an
already accepted pool match, retain its prior C and compiler settings; a rejected
upgrade must not erase the previously accepted pool reconstruction.
Anonymous DTK `pad_` and `gap_` objects can contain initialized pointer tables;
use `dataimport.pool_objects` and `payload` for their bytes and relocations.
Do not infer zero padding from a label. Split grouped scalar declarations before
capturing allocation constraints so every local is visible. Arithmetic repairs
must preserve operator precedence; `x = input * a + b` is not `x = input; x *= a + b`.
Repeated candidate batches require evidence of a shared cause across a measured
cohort and an explicit stopping condition. Stop when measured closure yield fails
that condition; improving a near-match score does not count as closing a region.
Before a manual compiler probe, assert that the intended source edit occurred and
inspect existing pragmas that may override a newly inserted setting.
Temporary reuse requires liveness through loop back edges; a variable's last
textual occurrence, especially a `for` increment, does not prove it is dead.

## Productive execution

Manual contributors may investigate multiple functions/cohorts, improve tools and
make coherent shared changes with serialized ownership and affected-function
verification. The one-function restriction applies to runner-bound workers, not
to an unbound user-directed session. A failed idea or released function is not a
session stop: try other approaches or continue to a better target. Use supported
process-local budgets when useful; do not change fleet/provider configuration.
The `fzgx evidence` tools and structured notes are optional aids, not a required
ritual before each edit. Prefer compiler-backed experiments and concise handoffs.
Keep claims, natural-C requirements and the full hash gate intact. See
`docs/AGENT_PROMPT.md` for the short execution-first prompt.
