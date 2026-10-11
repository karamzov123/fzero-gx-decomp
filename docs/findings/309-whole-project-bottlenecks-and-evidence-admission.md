# Whole-project bottlenecks: stop churn and separate exactness from source evidence

## Measured scope

This audit concerns the new fzgx repository/fleet, not the legacy NATC services.
The executable backlog is 1,757,180 bytes. main_rel accounts for 994,020 bytes
across 793 unauthored functions, 56.57% of that backlog. Strict historical source
accounting remains 39.915%; it is not a certification that every counted body
satisfies the newer source-hygiene expectations.

The three-day audit finds GPT/gpt-6-luna with 257 completed attempts, ten
zero-check attempts, and zero verified unique terminal deliveries. These are
attempt records, not unique functions or concurrent sessions. Historical unlabeled
work has 30 verified unique terminal symbols / 19,572 bytes; its lack of a model
label is not sufficient to identify all of that work as one deterministic engine.
Hermes has substantial zero-check sessions and no verified unique delivery in
its audited Step5 groups. Do not solve this by adding sessions, lowering effort
silently or clearing provider/resource holds.

## 1. Systematic retry churn: fixed

Near-miss and one-word tiers bypassed the normal per-family attempt cap. Save-only
budget release deliberately avoids hidden deep repair, leaving bodies "unsearched";
the scheduler then treated that marker as a reason to dispatch them again.
Changing the batch/context snapshot could reopen the same capped source.

Examples include fn_1_2D038 with 15 GPT attempts / 78 checks and fn_1_4068C with
13 GPT attempts / 56 checks, neither matched at audit time. The live selector
regression additionally selected fn_1_135D7C and fn_1_53E40 past cap=2, with 24
and 29 family-local attempts. It failed before the fix.

`choose()` now treats these tiers as ranking information only. The normal cap
holds unless an explicit, immutable source/compiler/flags/prologue admission
has fresh evidence. No broad attempt cap was raised. The real inventory regression
passes afterward and still selects fresh registered work. Existing unit/module
reservations and module-share limits remain unchanged.

## 2. Score-only source tricks: prospective gate and historical audit

The rejected car_test frontier demonstrates that stock object replay and a high
similarity do not establish natural source. Known `lab_pad` storage and the
explicit "keeps the web" liveness trick are now rejected at candidate write,
including patch-through-write, and at submit before compiler/integration work.
This narrow detector is not a general proof of C semantics or object layouts.
Ordinary offset padding is not forbidden by it.

The inventory also exposes 18 historical source files carrying the known
liveness marker. The audit records exact paths/lines. Do not delete those
expressions without replacement source and full hash verification. Prospective
candidate rejection and historical cleanup are separate: turning all 18 into
ordinary project-wide lint failures would block unrelated verified work. The
existing project lint therefore remains unchanged; the candidate boundaries are
strict and the historical findings remain visible, not silently exempted as
newly acceptable candidates.

## 3. Producer metrics lacked delivery and idle evidence: fixed

`fleet_audit` now distinguishes terminal outcomes from verified unique symbols
and their byte counts, requiring matched status, verified link state and a real
matched commit. It also counts zero-check attempts. Qualified ledger identities
are retained. Repeated outcomes cannot inflate a group's unique-delivery count;
per-group counts must not be summed as a global union without deduplication.
The real three-day audit asserts unique delivery cannot exceed terminal matches.

## 4. High-byte source debt: measured, not guessed into a matcher

Two real large saved bodies were replayed under GC/1.3.2 and module default:

- fn_1_BC310, 9,832 bytes, no registered unit: adjusted 53.8%, 1,202 differing
  rows. MWCC also reports v98 used uninitialized. Lint alone did not detect this
  undefined-dataflow risk. It requires dataflow/stack reconstruction, not a
  register permutation or a guessed initialization.
- fn_1_15C6C0, 5,820 bytes, no registered unit: raw 95.971825% but adjusted 83.15%,
  248 differing rows and pool/reference differences. Its apparent near-match
  needs constant-owner, storage/view and allocation analysis before admission.

The compiler/context variants give the same measured results in these probes.
No source was synthesized, no large body was dispatched as a near-exact seed,
and no registration or code credit was claimed merely from compilation.
The initial probe had an unresolved third identifier; it was not repaired into
a guessed symbol. The persisted dossier contains exactly the two resolved targets.

## 5. Shared data/type evidence is a multiplier, not free code progress

The existing inventory enumerates 10,798 main_rel objects / 719,964 bytes.
Highly referenced owners include lbl_1_rodata_26F8 (133 reference hits),
lbl_1_bss_960 (110), lbl_1_data_2A7E0 (99), and lbl_1_bss_3C30 (95).
These are source-reference hits, not unique caller counts or executable bytes.
Conflicting local views and unresolved object layouts are a plausible major
source barrier; the inventory alone does not prove a single canonical struct.
Prioritize consumers and real offsets/call lengths over arbitrary large arrays
or inferred SDK types. Data ownership must be reported separately from authored
executable bytes. A bounded existing AI SDK import probe found zero candidates;
no harvest or submission is claimed from that result.

## 6. Closure still needs stack/object evidence

Sample's byte-reversed operations are lowered, but sample sp47 and replay sp68
remain unproven escaped stack objects. Keep the fail-closed generation guard.
Recover alignment/interior-pointer/storage extents and overlapping frame ranges
before dispatch. car_colchg's source-generation control succeeds but has no exact
closure result. No module is declared complete from a generated or compiled draft.

## 7. Resource and publication constraints

The host audit reported 92 C and battery power; physical resource holds must not
be disabled to manufacture occupancy. The storage monitor is present and free
inodes are ample, while disk headroom is approximately 55 GiB. Lossless retention,
not deleting scored source or adding a duplicate watcher, is the supported path.
The publisher's private snapshot verification is distinct from local hash checks;
read the exact commit receipt and remote head before claiming publication.
Do not add a competing push/build loop while it is operating.

## Executed recovery and acceptance boundary

The configured fleet was drained before scheduler/API edits; claims cleared.
The existing cap regression and source-hygiene controls ran against actual saved
sources and inventory. No new model agents, repair framework, opcode fixture,
compiler-output imitation or forced assembly was introduced. The existing
11-test suite, ordinary lint and full sixteen-target build/hash gate are required
before commit and service restoration. Run tests that invoke oracle/build-lock
helpers outside an externally held build.lock: the combined invocation reproduced
a 120-second nested-lock timeout; the unlocked rerun passed all eleven tests.
The two-slot Codex high policy and parked
Hermes ultra policy remain unchanged; resumed dispatch obeys real resource holds.

state/repairs/whole-project-bottlenecks-20261011.json.gz preserves before/after
audits, historical hygiene paths, two exact source hashes/compiler verdicts and
the shared-data inventory. New delivered executable bytes from this audit are
zero. The fixes remove recurrent wasted work and prevent inadmissible candidates;
remaining structural obligations are explicit rather than falsely "solved".
