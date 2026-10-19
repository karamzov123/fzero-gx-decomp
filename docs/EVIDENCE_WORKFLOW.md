# Evidence-led matching workflow

Portable agent prompt: [`AGENT_PROMPT.md`](AGENT_PROMPT.md).

Execution-first correction: these are optional tools, not a required per-edit
workflow. Contexts no longer auto-load a decision packet, and agents need not
write a formal hypothesis or four-field log before experimenting. Failed ideas
and released functions do not end unbound sessions. Manual claims now initialize
usable saved C/profile rather than a placeholder. See
[`THROUGHPUT.md`](THROUGHPUT.md) for measured costs and fixes.

This extends the existing fzgx context/search/sourcealign/verifier flows. It is
not a new matching runner, scheduler, provider selector or permission to bypass
claims. Queues and observations are advisory. Native-C rules, existing budgets,
shared-file ownership, lint and the 16-target hash gate remain authoritative.

## 1. Decision packets and repeat suppression

```sh
.venv/bin/python tools/fzgx.py evidence packet fn_1_F38C0 --check
.venv/bin/python tools/fzgx.py evidence eligibility fn_1_F38C0
```

The packet selects actual saved source with its compiler metadata (or canonical
C for a matched function), hashes the source/target, locates the earliest own
residual and classifies its kinds. `--check` is a real standalone MWCC probe;
it does not claim, submit or grant credit. Without it, only a current identity-
validated cached check is displayed. Missing evidence is reported, not invented.

Experiment identity includes source, full inventoried headers, available
compiler binaries, effective flags, target/configuration and engine inputs.
Argument-vector-equivalent flags are normalized; unknown/macro include closure
disables deduplication. Invalidation is intentionally conservative: an unrelated
header/tool change may reopen evidence. It cannot prove that another attempt
will help. An old target without any comparable hypothesis record is reported
as unbaselined, not as newly improved evidence.

The existing zero-yield search cache is reused before spending an on-demand
search slot. Cached reuse preserves `searches_left`; it does not reset the cap.
A real baseline compile can still be required to establish current inputs. A
short-budget negative is not treated as exhaustion of a larger-budget search.
Cached diff pages now also validate header/compiler/target/tool context, not just
body and attempt. Compiler selection is recorded before that cache identity is
saved.

## 2. Matched native-C instruction witnesses

```sh
.venv/bin/python tools/fzgx.py evidence witnesses fn_12_2F730 \
  --pattern 'li r6, 0; mr r31, r6' --limit 8
```

Patterns contain one to four semicolon-separated instructions. Register numbers
are normalized while preserving register reuse, constants and operand order.
A bounded gap is allowed (`--max-gap`, default four); gap instructions that
clobber the reused value or cross unknown control flow are rejected. Multi-
register/update-form loads/stores are conservatively excluded from gaps.

Only native built units with ledger link verification are considered. Locally
edited source is excluded. Results include source C, retail instructions,
compiler/flags and accepted-commit provenance. Ranking favors the same module,
compiler and extra flags before address proximity. This is a source witness,
not proof that its idiom will transfer to a new function.

Without an explicit pattern, the current cached diff supplies a retail locator.
If no current locator is available, supply a pattern rather than guessing one.

## 3. Structured handoffs and restricted agents

Contexts keep code, retail assembly and compiler information central. Decision
packets and prior observations are fetched only when useful, not on every claim.
The existing `read_evidence` tool accepts `decision` and `witnesses` sections:

```sh
.venv/bin/python tools/fzgx.py read-evidence fn_1_F38C0 --section decision
```

Restricted matchers do not need shell access or another provider-specific tool.
Old adapters that cannot expose these sections can still use supplied context
and the existing release reason. Matcher and readability prompts prioritize real
compiler work and substantive exploration, not a mandatory hypothesis ceremony.

If a structured handoff will help another attempt, optionally use separate lines
in `release(reason)`:

```text
HYPOTHESIS: source explanation tested
PREDICTION: expected instruction/dataflow change
OBSERVATION: actual compiler/diff result, including remaining own rows
UNLOCK: specific new evidence needed before another useful attempt
```

Release automatically archives a complete handoff before releasing the claim.
The same hypothesis and prediction on an unchanged context returns its previous
observation instead of appending a duplicate. A handoff storage failure is
reported but cannot trap a claim or alter hash acceptance. Notes grant no match
credit. Shell contributors can explicitly use `evidence record SYMBOL` with
`--hypothesis`, `--prediction`, `--observation`, and `--unlock`; `--agent ID`
enforces that agent's live ownership.

## 4. Shared blockers and changed-evidence queues

```sh
.venv/bin/python tools/fzgx.py evidence clusters --module main_rel --limit 10
.venv/bin/python tools/fzgx.py evidence refresh --limit 10
.venv/bin/python tools/fzgx.py evidence queue --limit 10
.venv/bin/python tools/fzgx.py evidence acknowledge SYMBOL
```

Cohorts share a callee, object or recovered translation unit. Reports show members,
affected bytes, prior checks and measured cost. Broad references with more than
64 unfinished members are ranked after narrower cohorts so ubiquitous helpers
do not dominate every recommendation. A shared reference is not proof of a
shared root cause. Only an authorized integrator may alter shared declarations;
matched siblings and affected callers must be rechecked serially.

`refresh` snapshots real source/header/configuration/tool/compiler and licensed
donor content hashes. It compares dependencies and stores proposed rechecks,
returning only a bounded queue view. The verifier invokes it after a transaction
with accepted/rejected/dependency changes; external edits are detected on the
next explicit refresh. This is not a background filesystem watcher.

Cross-module includes are followed. A main_rel header can legitimately affect
interview/sel functions that include it. Global headers, compiler/tool changes,
and donor changes are conservatively broad. Matched functions are not dispatched
as new work; a cohort integrator remains responsible for matched-sibling checks.
The queue never claims, unblocks, resets attempts, launches a model or overrides
a model budget. Acknowledge an examined proposal explicitly.

## 5. Content-addressed licensed donor compilation

```sh
.venv/bin/python tools/fzgx.py evidence donors
.venv/bin/python tools/fzgx.py sourcealign --compile-sdk mk-deception --root PATH
```

Sourcealign compile batches now record source-corpus/header/license/revision,
compiler/tool/header/profile and output-object hashes. An identical batch can
reuse those actual objects. Changed/corrupted/missing objects force real rebuilds.
Manifest updates are serialized and atomic; a failed rebuild removes old success
records in the requested source/mode scope instead of retaining stale evidence.

Cataloging rejects fingerprinted objects whose compile context, donor corpus or
object hash changed. Legacy objects are explicitly labeled as unfingerprinted;
they remain discovery hints, never proof of a compiled source snapshot or a
retail match. `catalog-health.json` records excluded objects and reasons. Old
accepted source/license provenance is not rewritten.

## 6. Yield rather than activity

```sh
.venv/bin/python tools/fzgx.py evidence yield
.venv/bin/python tools/fzgx.py evidence yield --module movie_module
```

This conservatively counts native built units with explicit ledger link
verification. Historical units lacking that marker are excluded, so this report
is not a replacement for `honest`. It assigns closure credit to the last
non-shadow successful attempt, reports unattributed functions and missing cost,
and separates raw checks/attempts from verified functions/bytes. Missing cost is
not zero cost; summed wall time can overlap. Different target assignments prevent
these groups from being a fair causal model leaderboard.

## Original implementation validation (archived)

These results describe the initial evidence-tool implementation, not an
end-to-end agent-yield benchmark. Current throughput validation is documented in
`THROUGHPUT.md`; automatic decision-context injection was subsequently removed.

Real repository/MWCC probes, with no added repository unit-test suite:

- Scanned 5,277 verified native functions; found 74 zero-copy witnesses and ranked
  `fn_12_2F7AC` first for the callback-loop query.
- Replayed `fn_1_F38C0` at 98.46774%, exposing 15 own rows (14 register-allocation,
  one instruction); verified that packet identity agrees before/after the replay.
- Recorded/reused a structured hypothesis and conservatively suppressed a retry
  recommendation for that unchanged context.
- Executed an actual ten-second bounded search, recording thousands of trials and
  no closure; subsequent identical calls returned zero trials/zero search time.
  The budget here was a probe-local value, not a provider/fleet setting change.
- Compiled a real Sofdec C file to 12 profile objects, reused an unchanged batch,
  deliberately corrupted one generated object and verified a real rebuild restored
  its original bytes. No donor source was modified.
- Temporarily added a comment to the real main_rel globals header, observed cached
  check invalidation and dependency-scoped proposals, then restored it byte-for-
  byte. Restoration was detected for 742 functions across main_rel/interview/sel;
  a subsequent unchanged refresh produced zero new proposals.
- Exercised the existing restricted-agent decision/witness sections and verified
  conservative yield totals reconcile with attribution groups and explicit gaps.
- Existing regression suite, lint and full build/hash gates are recorded in the
  portable validation archive; no new function closure is claimed by this tools
  pass and no workers/providers were started or reconfigured.

Portable probe results:
`state/repairs/evidence-workflow-validation.json.gz`. The verifier's post-transaction
refresh hook is installed; no synthetic pending match was created just to trigger
it. Real refresh behavior was exercised directly as described above.
