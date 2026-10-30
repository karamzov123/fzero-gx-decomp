# Register repair measurements, 2026-09-11

## GC/1.3.2 high-pressure simplify replay, 2026-09-15

The pinned compiler's simplify routine at `0x507B50` chooses an optimistic
removal when no low-degree node remains. Capture now retains its signed spill
cost at node offset 12, generated-register threshold, and fallback score.
Replay divides cost by the current degree and preserves the descending-rank
tie break of the compiler's linked list. This models allocation decisions;
it does not modify the compiler or its output.

Live validation covered **170 functions / 259 allocation passes**, with identical
stock objects and zero simplify/color replay errors. Three GPR passes previously
returned unsupported: `fn_80043798`, `fn_1_9D0EC`, and the 4,208-byte
`fn_12_364CC`. Capture took 14.206 seconds; the recorded replay took 36.398 ms.
The portable archive includes C, compiler settings and hashes, retail/baseline
words, complete captures, and validation results:

```sh
uv run tools/fzgx.py fixup --archive state/repairs/spill_graphs_20260915.json.gz
```

**No new C matches resulted.** Captured declaration-order projection produced
one candidate, which remained nonexact. Extending projection to nested scopes
also produced no new matches and was removed. The movie's 70 differing words
remain in seven inlined cleanup loops; their desired colors do not conflict
with the captured interference graph, but a source-realizable order is unresolved.
Older captures and compiler profiles without measured costs still report
unsupported high-pressure decisions. Existing cached captures need recapturing
to use the added fields.

## Loop-lifetime repair guard, 2026-09-15

`reuse_temporaries` previously used the last textual occurrence as a death point.
On `fn_1_13B98`, it therefore reused the live `for` counter `j` for a pointer
offset read inside the loop. This invalid rewrite improved the raw word score
from 241 differences to 230 while leaving 17 instruction-shape differences.

Loop uses now remain live through their enclosing back edges. Unbounded
statement bodies are conservative, and goto-bearing functions require control
flow analysis before this generator can reuse locals. Across all 2,171 saved
best bodies, proposals fell from 187,930 to 153,476: 34,454 proposals without a
sufficient liveness proof were excluded across 418 functions. This count is not
a count of proven miscompilations. The offending loader rewrite is excluded;
a retained post-lifetime reuse still compiles under stock MWCC. The original,
rejected and retained sources and their measured scores are preserved in
`state/repairs/reuse_liveness_20260915.json.gz`. Historical candidates are retained
as evidence; their similarity scores do not establish semantic correctness.

The stopped `deepseek-under1k-fast-512-20260911-021006` batch supplied
268 unmatched saved bodies at >=95%, totaling 79,616 bytes. Of these,
70 were classified as register-only from instruction spelling. That label
does not prove equivalent value flow.

## Findings

* The existing search enumerates up to 720 declaration orders before most
  other rewrites. Leading declarations exclude nested blocks. Its operand
  commutations, supplied by the separate spelling search, only recognize
  already-parenthesized simple expressions.
* Operand ordering, common subexpressions, declaration scopes, initialization
  order, and temporary materialization are coupled compiler decisions.
  A rewrite may repair some fields and disturb others; greedy improvement
  and independent-bit composition do not capture all these interactions.
* `fn_1_83CB0` is a concrete false allocation diagnosis: the stores at rows
  21 and 23 consume the wrong load results. Its 99.666664% similarity does
  not imply that physical register reassignment can repair it. The new
  `regflow` diagnostic distinguishes this from reordered intermediate
  producers, such as `fn_800581CC`.

`regflow` follows supported instructions within linear regions, discards
facts at branch targets and unknown operations, and respects call clobbers.
It reports only known non-stack store-value conflicts. It is neither a
whole-function equivalence proof nor permission to accept object differences.
The oracle's matcher output now includes these conflicts; `stuck` labels
them `value-flow`. Match acceptance is unchanged.

## Bounded compiler-response experiment

The original bounded compiler-response experiment preceded consolidation into
`fzgx fixup`. Its candidate generators and response algebra now share the engine. It parses expression precedence, handles
casts and repeated expression sites, probes nested declaration order, scopes,
materialization and optimizer state, then attempts to combine observed
repairs. It uses both disjoint repaired bits and bounded GF(2) response
equations. The compiler is nonlinear: every proposed combination is compiled
again and must pass the complete relocation-aware oracle.

Compiles are grouped across functions by module and recorded compiler options.
The input C hash is checked, and settings are preserved in output manifests.

| Pass on the same 70 bodies | Candidates | Wall time | Exact object matches |
| --- | ---: | ---: | ---: |
| Initial bounded probes | 1,274 | 3.941 s | 0 |
| Nested declarations, optimizer state, response equations | 1,625 | 7.027 s | 1 |
| Final version including value-flow diagnostics | 1,624 | 9.904 s | 1 |

The final pass improved 17 word scores, including its one exact match,
`fn_10_260D4`. That match was also found by the existing repair pass.
Final amortized time was **141.5 ms/function**, including 805.9 ms total
for proposals/reading diffs, 8,355.3 ms for probes, 621.5 ms for composition,
and 117.5 ms for combined compilation. This is throughput, not a per-function
latency guarantee. Frozen baseline compilation is excluded.

This does **not** solve register allocation generally. The old repair pass
found two exact objects in this register-only subset; the bounded pass found
one. It must not silently replace the old pass or claim equivalent coverage.
No equation-composed candidate closed in this corpus. Isolated commutations,
simultaneous repeated commutations, and explicit shared floating temporaries
also failed to close `fn_80015D7C`; more spellings alone lack evidence here.

Run the consolidated engine on the frozen diagnosis directory (the measurements
above describe the original experiment, not this expanded candidate set):

```sh
uv run tools/fzgx.py fixup --corpus .fzgx/near95-fast-batch \
    --output .fzgx/fixup/replay --max-candidates 32
```

Per-function hashes, attempt IDs, settings and measurements are committed in
`state/repairs/register_solver_20260911.json`. A coverage improvement needs
constraints connecting C expression/lifetime decisions to compiler allocation,
including decisions whose intermediate probes do not improve the score.
The current experiment measures responses; it does not recover MWCC's allocator.

## Integrated repairs from the full near-miss pass

The existing deterministic pass found four exact objects. Two passed source
lint and all 16 target hashes: `fn_10_260D4` and `fn_1_FC60C`, totaling
612 bytes. `fn_8006EFB4` remains unintegrated because of a literal pointer
to locked-cache memory; `fn_80083BCC` needs justified shared-control-flow
annotations. Neither is counted as an integrated match.

The batch remains stopped. No model sessions were launched for this work.

## Exact allocator capture and replay

`fzgx fixup --capture` reads the **actual** interference graph before
and after `SelectColors` in SHA-256-pinned GC/1.2.5n and GC/1.3.2. Native Wibo
runs under local LLDB; the compiler and generated instructions are not patched.
Sources with identical compiler settings share an invocation. Function-entry
breakpoints bind captures to function names, excluding emitted helper functions.
No personal debugger or Codex configuration is changed.

`mwgraph.py` implements the non-spilling simplify pass and color selection.
It preserves coalesced ghost edges in degree counts and reads neighbors'
physical fields directly, as the compiler does. It does **not** recursively
resolve coalesced parents while coloring. Unsupported simplify spill decisions
are explicit, not guessed. A constructive inverse finds sufficient selection
orders without enumerating permutations. Failure to construct an order is
inconclusive; a witness is not proof that a C edit can realize it.

Measured on the same 70 frozen candidates:

| Operation | Total | Per function |
| --- | ---: | ---: |
| Cold capture, one compiler process per source | 37.18 s | 531 ms amortized |
| Cold capture, five grouped compiler invocations | 4.45 s | 63.6 ms amortized |
| Simplify + color replay | 3.56 ms | 0.048 ms median |
| Reconstruct captured-color order witnesses | 25.44 ms | 0.257 ms median, 2.44 ms maximum |
| Target constraints and declaration projection | 34.34 ms | 0.415 ms median |

All **70 emitted function bodies are unchanged**, including 100% relocation-aware
object comparisons against their frozen baseline compiles. All **90 allocation passes**
for those named functions replay exactly. The earlier 93-pass count included
three passes from helpers emitted alongside `fn_1_579A0`; grouped capture now
separates those identities. Cold times include LLDB startup/capture, not corpus
loading; algorithm times exclude compilation and graph input decoding. These
are corpus measurements, not a general latency guarantee.

Target analysis finds 10 consistent fixed-graph hypotheses, 54 cases requiring
value-web alignment, and six with unsupported instructions. The ten hypotheses
produce nine selection witnesses across eleven graphs. **Zero declaration
projections pass the graph prediction; zero new functions are matched.**
Parameters, generated temporaries, coalescing, and scope-dependent creation
order cannot be arbitrarily reordered by shuffling declarations. We now check
that restriction before proposing a compile. Unsupported cases remain available
for further reconstruction; this does not prune them as impossible.

`fn_80015D7C` specifically needs reversed multiply operands at rows 8 and 20,
with an otherwise identity register map. Normal matcher check output now names
such operand-order differences separately from value-flow conflicts. Capturing
a graph does not recover the frontend expression/CSE decisions that produced it.
The remaining integration work is PCode value-web/source-origin alignment and
source transformations that realize those constraints. This tooling is an exact
allocator model and diagnostic foundation, **not a completed universal repair**.

The implementation is local and has no donor imports. Algorithm/layout research
used the CC0 [inspiredrobot/mwcc reconstruction](https://github.com/inspiredrobot/mwcc/tree/ef08e865561446c072f457eaf89bde9030cccb30),
particularly `Coloring.c`, `allocator_snapshot.py`, and `coloring_model.py`.
Its license is retained in `tools/licenses/mwcc-CC0.txt`. GC/1.3.2 addresses and
layouts were recovered from the installed PE and validated by live captures;
`mwgraph.PROFILES` records exact binary identities. Only owned Python and
measurement data are included here, not compiler binaries or external-project
includes.

The committed compressed archive contains real graph captures, saved C seeds,
compiler flags/hashes, and header/source hashes. It is a repair corpus, not a
unit-test suite. Replay it without MWCC, LLDB, or the original scratch directory:

```sh
uv run tools/fzgx.py fixup --archive state/repairs/register_graphs_20260911.json.gz
```

Capture a frozen diagnosis corpus, or recompute constraints from its cache:

```sh
uv run tools/fzgx.py fixup --capture --corpus .fzgx/near95-fast-batch --output .fzgx/mwgraph
uv run tools/fzgx.py fixup --capture --corpus .fzgx/near95-fast-batch --output .fzgx/mwgraph --replay
```

Capture requires macOS's `xcrun lldb` and the repository's native Wibo with its
loader symbols. On Linux a bare `lldb` with embedded Python is enough, provided
Wibo is at `build/tools/wibo`: the release binary from
`python3 tools/download_tool.py wibo build/tools/wibo --tag 1.0.0` carries the
debug info the loader breakpoint needs (`loadPEFromSource`). Verified on a Linux
host at 0.51 s/function with exact replay on six saved bodies; see
`docs/findings/390-linux-allocator-capture-unblocked.md`, which also records that
the six classic register walls come back `fixed-graph-hypothesis`
(`fn_12_3A64`) or `needs-web-alignment` (the rest) and that the projected run
closes none of them. Cached replay rejects changed source hashes, header hashes or
compiler settings. The normal relocation-aware oracle and all 16 target hashes
remain the acceptance authority. No model batch was resumed.


## PCode-directed source repairs (2026-09-11)

The next pass connects captured PCode operands and source lines to virtual value
webs, aligns their emitted instructions with retail, and proposes C changes for
the implicated locals. Commutative operand choices, conflicting constraints and
unresolved rows remain explicit hypotheses. Declaration orders are evaluated in
the captured allocator before compilation; bounded exhaustion is reported as
such. One-field scalar carriers change MWCC's scalarization/temporary creation
order while retaining the declared scalar type. Source-line provenance also
finds locals hidden behind compiler-generated `@` temporaries. Generated C must
still pass the stock compiler, relocation-aware oracle and all target hashes.

This integrated **9 generated repairs / 2,944 bytes**. A target-binding correction
also recovered **5 already-exact saved bodies / 868 bytes**: **14 functions and
3,812 bytes total**, verified in commits `d684864`, `b1e4500`, and `44b5f02`.

The auto-object index previously keyed functions globally by bare symbol name.
Consequently, `title:_prolog` was compared against car_colchg's 664-byte entrypoint
instead of title's 296-byte entrypoint. Index keys, normalized-object caches and
caller/context lookups now retain module identity. The oracle rejects foreign
frozen targets, including same-sized ambiguous targets with different bindings.
One generated candidate was recovered for its actual owner, car_colchg; no
foreign-target score is accepted as a match. The historical audit invalidated
48 attempt records across 15 functions and re-scored 47 saved sources. Original
scores are preserved in `state/repairs/target_binding_v4.json`; replacement
attempts carry correct-module scores. The migration cutoff protects new attempts.

Measured on 265 frozen near misses:

| Pass | Compiler probes | Exact candidate functions | Improved functions, including exact |
| --- | ---: | ---: | ---: |
| Named scalar carriers | 228 | 5 | 21 |
| Source-origin and initialized carriers | 545 | 9 | 34 |
| Add generated block-copy temporaries | 1,073 | 9 | 40 |

The final pass spent **12.605 s generating candidates and 3.085 s compiling**;
cold grouped PCode capture took **11.860 s** separately. These are corpus totals,
not per-function latency guarantees. The nine candidate functions include the
misbound entrypoint subsequently recovered for its correct owner. Parameter-home
rewrites added 32 probes with zero improvements and were removed. A further pass
on the 31 nonexact improvements used 240 probes, improved five seeds, and closed
zero additional functions. These results do not imply universal register repair.

Live capture now supports hash-identified GC/1.2.5, GC/1.2.5n, GC/1.3 and GC/1.3.2.
The remaining three GC/1.3 corpus functions also captured and replayed exactly;
14 repair probes yielded no improvements. All captured objects stayed unchanged.
There is no runtime dependency on donor sources or modified compiler binaries.

```sh
uv run tools/fzgx.py fixup --capture --corpus CORPUS --output CAPTURES
uv run tools/fzgx.py fixup --corpus CORPUS --captures CAPTURES --output REPAIRS
uv run tools/fzgx.py fixup --corpus CORPUS --output REPAIRS --saved --apply
```

Recapture after changing source, headers or compiler settings. Improved corpora
preserve compiler settings and replace seeds only on a strictly improved word
score; that score is not relocation-aware match acceptance. Integration rechecks
current module targets and performs the complete link verification.

The portable archive preserves all 14 seeds, generated hashes, the nine repairs'
PCode/allocator captures and baseline/retail words, plus the best 31 nonexact
improved seeds (including the five further improvements). Reproduce the accepted
source transformations without scratch files or a compiler:

```sh
uv run tools/fzgx.py fixup --archive state/repairs/mwgraph_repairs_20260911.json.gz
```

This reproduces all 14 source hashes; compilation and link acceptance are separate
checks. `state/repairs/mwgraph_imports.json` records compiler settings, transforms,
owning source and verification commits. No unit tests were added and no model
batch was resumed.


## Consolidated engine

`fzgx fixup` is the only repair command. Session release, lifter repair and the
orchestrator API invoke the same engine in `tools/fzgx/fixup.py`.
The former regalloc, spell, line-repair, lab, response-solver and graph-repair
search loops are removed. Their source transformations live in
`fixup_source.py`; retail-derived candidates and line diagnostics live in
`fixup_evidence.py`. These helpers do not compile, run searches, cache or submit.
Stock allocator capture/replay lives in `mwgraph.py` and is dispatched through
this command too. SDK/data import and `stuck` remain separate because they import
sources/data or diagnose failures, rather than running competing fixup searches.

The engine batches compilation across symbols by module/compiler/flags, caches
by source, headers, compiler flags/binary, retail object and oracle fingerprint, and
confirms potential matches with the relocation-aware oracle. A bounded frontier
retains distinct emitted bodies; all candidate families share its limits.
Compiler-response compositions return to that same evaluator. There is one
report and one cache in the output directory; `--saved --apply` verifies and
integrates completed results without repeating search. Frozen sources and their
compiler settings survive every round. Historical scores select candidates;
current module targets determine their actual scores.

```sh
uv run tools/fzgx.py fixup --min-percent 95 --output .fzgx/fixup/near95
uv run tools/fzgx.py fixup SYMBOL --body candidate.c --output .fzgx/fixup/one
uv run tools/fzgx.py fixup --output .fzgx/fixup/near95 --saved --apply
```

The default corpus includes every distinct saved C/compiler combination above
the threshold, not only one best body per function. `--rounds 0` rechecks and
freezes that corpus without searching. `inputs.json`/`results.json` expose the
best unfinished seeds for graph capture; `report.json` retains all variants.
Use `--corpus PATH` to repair an existing frozen corpus. `--rounds`, `--beam`,
`--max-candidates`, and optional total `--budget` bound the single shared search.


Consolidation validation used 4,242 distinct saved C/compiler combinations across
399 unfinished functions. One round evaluated 22,896 additional candidates:
299.11 seconds cold, including 261.36 seconds in compilation/oracle evaluation.
The cached repeat, after replacing whole-body character LCS in edit composition
with line alignment and local span trimming, reused 27,138 results and compiled
one new combination: 14.29 seconds total, 0.132 seconds in compiler evaluation.
These are different cold/warm workloads, not a claimed 21x compiler speedup.
The round improved 153 best word scores and found 12 function-level matches.

Nine passed all target hashes immediately (2,596 bytes). Two other candidates
emitted 1,004 bytes of unused static helper copies outside their matching
functions. The unified engine now rejects such extra REL functions before
integration and generates explicit inline helpers. The two repairs passed the
stock object comparison in 0.49 seconds for 34 compiles, then one additional
cached-pass compile selected the all-helpers rewrite. Both subsequently passed
all 16 hashes: **11 functions / 3,564 bytes integrated** in total during
consolidation, with source and recipe provenance in `state/repairs/fixup_imports.json`. The remaining original
candidate is lint-rejected; it is not counted as integrated.

Known link-rejected source/compiler combinations are retained with header and
oracle fingerprints so unchanged saved inputs are not resubmitted repeatedly.
Best bodies also retain current relocation-aware percentages; the shared saved
candidate collector consumes those reports for subsequent repair/model batches.
The one-time target-index history migration is complete: its standalone auditor
is removed, and its immutable migration/provenance records remain in `state/`.
All future compilation goes through module-qualified targets in the engine.

## Expanded corpus and binding repairs

A three-round continuation covered 387 unfinished functions / 161,896 bytes.
It evaluated 57,127 new candidate records, with 44,912 actual compiles and
12,602 cache hits including baselines. Four functions (724 bytes) reached the
object oracle; 80 best instruction-word scores improved. Wall time was
1,045.16 seconds, including 824.21 seconds in compiler/oracle evaluation.
This broader search is not a millisecond-per-function result. Its four closures
used response composition, field order, a scalar carrier, and graph-guided
declaration order.

Graph evidence now follows changed frontier bodies across rounds. Captures
retain stock object/color replay validation; an unsupported spilling simplify
path is reported separately from a replay mismatch. Three such graphs previously
aborted an otherwise valid 380-function capture. Binding quality participates in
frontier selection, so identical instruction words no longer automatically erase
better data bindings.

The same engine now derives string-pool boundaries and padding from emitted
symbols and retail bytes and recovers named floating initializer anchors. Whole readonly pools require complete byte
and padding equality with no internal relocations. Newly recognized DOL switch
tables require every entry to resolve to the correct containing-function offset.
REL pool reads are section-qualified, including local-symbol suffix resolution.

Shared BSS uses the existing relocation-retargeting path: symbol identity,
object size, zero-initialized section and addends are checked before copies are
removed. Data already owned by the function's unit remains defined there.
This preserves MWCC's code generation for shared section bases and handles its
compiler-generated `$N` local-static symbols without inventing invalid C names.
Exact bodies with unresolved shared definitions or source-lint failures remain
searchable. Branch comments are generated only after a full object match; lint
rules and address restrictions are not waived.

The expanded historical eligibility threshold is 90%, selecting 595 functions
and 7,063 distinct source/compiler combinations. All were recompiled against
current module targets; historical percentages are eligibility, not acceptance.


The 595-function pass evaluated 57,644 bodies including baselines in 984.13
seconds (864.49 seconds in compiler/oracle evaluation). It found 22 object
matches and improved 150 best instruction-word scores. A final pass over those
595 best bodies evaluated 5,163 bodies in 44.42 seconds, including 21.33 seconds
in compiler/oracle evaluation. It reached **25 functions / 6,844 bytes**, all
subsequently linked from C and verified against all 16 target hashes. Code
progress moved from 21.80% to **22.03% (647,044 / 2,937,044 bytes)**.

Direct extern conversions, byte-pointer aliases and typed array views did not
close the remaining scalar-alias examples: their instruction sequences changed.
Those added generators were removed rather than retained as another low-yield
search family. Shared BSS was instead repaired by the verified binding path.

Integration exposed two additional symbol-promotion gaps: existing pool mappings
retained stale suffixed targets, and renamed source definitions also needed their
private mapping keys updated. Promotion now updates both, including `@`/`$`
identifiers. Ninja mappings quote and escape compiler-generated `$N` symbols
through both expansion layers. The verifier filters absent, untracked rejected
files from its dependency journal before staging, while retaining tracked deletions.
The final 24-function and one-function link checks both used the fast path.

`state/repairs/fixup_imports.json` retains all 25 original seeds and 51 successive
source-repair steps, in addition to generated C, compiler settings and verification
commits. No model sessions or standalone repair tools were added.


## Whole-corpus near misses, 2026-09-11

The post-batch audit selected 598 historical >95% candidates; 592 remained above
95% after recompilation. This pass integrated **18 functions / 7,348 bytes**.
All 18 passed the 16-target hash check without bisection or rejection (9.229 s).
Tooling, headers, source and initial provenance landed together in `f7bf82d`.
`state/repairs/fixup_imports.json` retains the original seeds, final C, compiler
settings, source-repair chains and link results. Local detailed evidence is under
`.fzgx/fixup/near95-*/` and `.fzgx/reports/near95-current/`.

| Closing mechanism | Functions | Bytes |
| --- | ---: | ---: |
| Previously exact bodies: helper ownership and hardware declarations | 5 | 3,096 |
| Interior object/entrypoint bindings | 3 | 1,152 |
| Correct store values, then repair their code generation | 2 | 320 |
| Preserve aggregate size while correcting its field origin | 1 | 244 |
| Allocator capture and source-realizable carrier/declaration changes | 3 | 1,096 |
| Coupled operand order and optimizer policy | 3 | 1,316 |
| Existing block-declaration generator | 1 | 124 |

The important machinery changes are shared by the CLI and session/lifter adapter:

- Keep a proven value-correct candidate on the frontier even if its first word
  score decreases. `fn_1_83CB0` dropped from 93.33% exact words to 80% after fixing
  the swapped stores, then reached 100% with propagation disabled. The analogous
  `fn_1_72318` correction dropped from 96% to 88%, then reached 100% with an
  argument temporary. Both now use the shared hardware map instead of literal
  pointer casts. Mixed instruction differences no longer suppress all value-flow
  diagnostics; fused product operands commute in the diagnostic without moving
  the addend.
- Preserve coupled operand changes across optimizer policies. A commutation with
  zero machine-code response cannot participate in the existing linear response
  solver. Explicitly combining it with policy changes closed `fn_1_530C8` (four
  additions), `fn_1_E594C` and `fn_15_5864`. The original 80-proposal probe closed
  none; a targeted 155-combination probe found exact code for `fn_1_530C8`.
- Generate and prove symbolic interior bindings. `OWNER__fzgx_offset_HEX` retains
  the C declaration and uses the existing pool map to bind to `OWNER+offset`.
  Validate module, section, owner bounds, relocation kind, operand agreement and
  resolved retail target before acceptance. Only ELF relocation addends change;
  code/data bytes are not rewritten. Negative probes with wrong offsets were
  rejected on all three real functions. Symbol promotion updates the owning
  names in saved mappings. All three bindings linked exactly.
- Reject extra helper definitions in both DOL and REL objects. A public helper
  can become a private inline definition; mixed inlined/out-of-line uses need
  separate spellings with external calls bound to the already-owned function.
  This repaired all three earlier link rejections, including the movie function
  whose unused helper copy added 164 bytes. The session/lifter adapter no longer
  bypasses ownership/lint checks when the supplied function oracle is already
  exact; the real `fn_80010CB0` adapter probe repaired its duplicate helper.
- Derive a selection-order witness first, then validate it through stock
  simplify/color replay and source declaration order. Bound the small-stratum
  permutation fallback to 720 orders. A witness alone is never accepted C.
- Move false leading aggregate padding to the tail when retail stack stores
  identify a shifted field origin; preserve object extent. `fn_14_A2A4` closed
  by moving eight bytes, without changing its total frame size.

Measured passes (some ran concurrently with the blanket compiler sweep; these
are workload totals, not isolated speedup comparisons):

| Pass | Functions | Compiles | Wall seconds | Outcome |
| --- | ---: | ---: | ---: | --- |
| Blanket first round | 598 | 49,264 | 802.94 | 212 word-score improvements; three usable exact candidates |
| Captured allocator repair | 160 | 5,203 | 32.15 | Three exact, 13 improved; capture separately took 9.80 s |
| Up to four differing rows | 175 | 12,225 | 92.42 | Nine exact, 38 improved |
| Operand-order witnesses | 31 | 5,442 | 35.77 | Three exact, eight improved |
| Value-correction bridges | 2 | 346 | 1.95 | Both exact code; one then needed the hardware-map rewrite |

These pass outcomes overlap; only the 18 link-verified functions above are counted
as closures. The blanket second round expanded to roughly 144,000 additional
candidates and was interrupted. Its uncheckpointed work is excluded from the
reported completed-pass results. The first-round checkpoint and improved bodies
remain available to the saved-candidate collector.

Remaining limits: `fn_80048340` still needs its larger stack layout recovered;
packing scalar locals did not close it (that generator improved two other corpus
functions). `fn_1_59B00` still has a shared conversion-pool layout mismatch.
Recovery now considers equal-valued literals at different offsets, but generated
shared-field references did not reproduce its implicit conversion-bias addressing.
An explicit union-conversion experiment also regressed and was removed. Scalar
array spellings for interior references changed code generation and were replaced
by the proven relocation-binding path. Register allocation is not universally
solved, and the remaining high similarity scores must not be reported as closure.

## The 2026-10-04 gate census: "none qualify" does not reproduce

The withdrawn claim (git 59ba2e44) correctly retired the 496/0 reachability
number — `mwgraph.py` built `desired` from `after['nodes']`, the colouring of our
*own* SelectColors pass, so the question was whether an order reproduces what the
compiler just did. That circularity is real.

The follow-on "none qualify" claim did not survive measurement. Measured
directly — retail words vs our own compiled objects in `.fzgx/work/`
(2542 objects), restricted to `status != 'matched'`:

| Outcome | Count |
| --- | ---: |
| compared | 842 |
| equal length (clears the `mwconstraints.py:23` gate) | 661 |
| &nbsp;&nbsp;`fixed-graph-hypothesis` | 40 (34 distinct functions) |
| &nbsp;&nbsp;`needs-web-alignment` | 517 |
| &nbsp;&nbsp;`unsupported-instruction` | 104 |
| length mismatch | 1103 |

The gate fires on the plateau. `needs-web-alignment` at 517 is the actual wall,
not the length precondition — and that is the module's own documented position
("Conflicts require PCode/web alignment, not a broader permutation search").

Of the 34 reaching `fixed-graph-hypothesis`, six objdiff at exactly 100.0% while
the ledger still reads `unmatched`:

    colchg_selmate_disp   fn_1_128B60   fn_1_3F4B8
    fn_1_611EC            fn_1_FC760    fn_3_17098

These are `link-mismatch` bodies quarantined by `verify.py:160-162`: the object
matched, the batch relink did not, so the unit was uncarved and the body parked in
`.fzgx/attempts/<sym>.linkfail.<ts>.c` with `percent=100, link_fail=true`.

**Five of the six are now `matched` / `link_state=verified`.** Two distinct
repairs, both of which the engine already had:

**1. Missing TU context (four functions).** `fn_3_17098` (`6695b5e3`),
`fn_1_3F4B8` (`ca986079`), `fn_1_611EC` (`924f2754`), `fn_1_FC760` (`5607407a`).
The parked bodies are standalone copies, and a standalone body does not get the
TU's headers — the recarve path supplies them and the quarantine path does not.
Each failed to compile on its own evidence alone:

    ';' expected                              (fn_1_3F4B8, no types.h)
    undefined identifier 'lbl_9_bss_8'         (colchg_selmate_disp)

Prepending the owning TU header fixed all four with no source edit beyond the
include. `fn_3_17098` needed `rel/customize/editor.h` specifically because its
body *defines* 16 `lbl_3_bss_A2410*` fragment globals while that header already
declares `extern Obj_3_bss_A2410 lbl_3_bss_A2410` — without the header the
fragments collide; with it they are the layout primer they are meant to be.

**2. Non-inline static helper (`fn_1_128B60`, `a48591fa`).** Its body declared
`static s32 next_rand(void)` — the shape of finding 273. `inline_helpers` already
had the fix but never ran: it is gated on `row['score'] == 100` (fixup.py:432) and
the quarantined body was invisible to the corpus. It also needed `#include
"types.h"`.

**`colchg_selmate_disp` needed a real repair, and finding it exposed two tooling
gaps** (both fixed, both silent). It reaches 100% at the object but
`verify` rejected it on relink; its last agent note was *"All 8 remaining rows are
L-rows (private literal pool base only)"*, which was accurate.

Its literals bind to our own anonymous rodata while retail's bind to the module's
pooled `lbl_9_rodata_*`. Sibling units in the same TU carry exactly that mapping in
`units.json` and compile through the `mwcc_pool` rule, which retargets the literals
on every build. Three things had to line up, and each was broken in a different
place:

1. **`Engine` never retargeted the pool.** `oracle.check` retargets and drops the
   primer on all three of its paths, but the fixup scoring path calls
   `oracle._diff` directly, so a word-identical candidate was recorded as
   `matched` with its private literals still in place. `fixup.Engine.retarget_pool`
   now does the same repair, and restores the object if the re-diff disagrees.
2. **`api.submit` records the mapping**, so `units.json` gets the `pool` dict and
   the unit is accepted as `link: pending` rather than the terminal `pool: True`
   ("retail object still linked", `link_state=pool`, 35 functions today).
3. **`configure.add_pool_rules` silently skipped this unit.** Its regex required
   `mwcc` on the `build` line, but Ninja wraps the rule onto a continuation line
   when the output path is long:

       build .../colchg_selmate_disp.o: $
           mwcc build/.../colchg_selmate_disp.c | $      <- not matched

   Both spellings occur in one file, so the retargeting was skipped for exactly the
   longest-named units, with no error. The regex now accepts either form and is
   idempotent (439 units, 439 poolmap lines, no duplicates on re-run).

So: five functions were byte-identical and waiting on a repair that existed but was
gated off, and the sixth was waiting on two silent tooling gaps. All six are now
`matched` / `link_state=verified`; `matched` went 5682 -> 5689 and linked files
5704 -> 5706.

### The parked body now keeps its TU context

`verify` quarantines a link-mismatched body by copying it out of its unit
(`verify.py`, the `bad` loop). That copy is standalone, and the recarve path that
would normally supply the TU's headers does not apply to it — so the parked body
routinely cannot be recompiled on its own evidence, and the function gets
re-derived from scratch. Four of the six here needed nothing but the includes.

`_with_tu_context` now prepends the TU's own `#include` block, read from the TU file
rather than guessed from the unit path. A header is added only when the body does not
already carry it, and skipped when the body defines a name the header also declares
(`_include_is_safe`) — a parked body legitimately reconstructs a struct or defines
the `lbl_*` fragment globals a layout primer needs, and including that header would
then make the compiler reject the file. The guard was checked against the exact case
that motivated it: a body defining `lbl_3_bss_A2410` does not pull in
`rel/customize/editor.h`, which declares it. The rewrite is idempotent, and the sidecar
`.json` records the headers alongside the digest.

The header list is derived from `rec['tu']`, so a standalone unit (no TU) is left
alone rather than guessed at.

### Register repair is not a viable lever at this population size (2026-10-04)

This closes the line opened by the withdrawn reachability claim. Measured over the
`fzgx stuck` census (816 functions analysed), the 99-100% band is **44% pure
`regalloc`** — 75 functions where register assignment is the *only* difference. That
is exactly the population register repair is for, so it was measured properly:

| `mwconstraints.target_mapping` verdict | Count |
| --- | ---: |
| `needs-web-alignment` / **structural** | **40** |
| `unsupported-instruction` | 6 |
| `needs-web-alignment` / commutative-only | 2 |
| `fixed-graph-hypothesis` | 2 |
| (length mismatch / no object) | 25 |

Three conclusions, each earned:

1. **The `structural` label does not mean what it says here — corrected.** Reading the
   verdict alone, `structural` is documented as *"evidence of a source defect to fix
   first — aligning the webs would mean aligning two different programs."* Measured,
   **39 of the 40 have zero incompatible rows**: every instruction shape matches
   everywhere, and the verdict comes only from `hard_conflicts`. The distribution is
   15 functions with exactly **one** conflicting register, 15 with two, and one with
   incompatible rows at all.

   The cleanest case, `fn_12_321E8`, is a **five-row diff from one load**:

       30  lwz r6, 0xc0(r5)   |  lwz r5, 0xc0(r5)
       32  rlwinm r0, r6, ... |  rlwinm r0, r5, ...
       33  rlwimi r0, r6, ... |  rlwimi r0, r5, ...
       34  rlwimi r0, r6, ... |  rlwimi r0, r5, ...
       35  rlwimi r0, r6, ... |  rlwimi r0, r5, ...

   `r5` holds `movie_addr`, which dies at that statement, so MWCC coalesces the load
   destination onto it; retail kept a separate `r6`. One our-register is therefore bound
   to two retail registers and no consistent bijection exists — a register-allocator
   tie-break, **not** two different programs. So web alignment is still the wrong tool,
   but the reason is sharper than "source defect", and neither is source spelling:
   removing the `v0` temporary, re-spelling the load through a typed pointer, and
   `#pragma opt_lifetimes off` (which 15 matched functions in that module use) all
   left the count at exactly five differing rows. The coalescing is the allocator's
   choice and survives all three, so this is a genuine dead end at the source level —
   recorded so the three variants are not re-tried.

2. **Where a map does exist, nothing applies it.** `target_mapping` returns a
   register map for the two `fixed-graph-hypothesis` functions, but no transform
   consumes it: `declaration_projection` only accepts a reorder that preserves our own
   colours, which is what made the original reachability number vacuous.
   `fn_1_10161C` is the live case — 99.40% with **0 shape errors** and 16 word errors,
   a map in hand, and three rounds of `fixup` proposals that cannot move it.

3. **The population does not justify a register-mapping applier.** Two functions reach
   `fixed-graph-hypothesis` (one, `fn_1_131194`, is already matched), so at most one
   would benefit. The 40 are *not* value-flow repairs either — see 1; they are allocator
   tie-breaks that source spelling does not reach.

4. **The band is concentrated in clone families — but that no longer helps.** The 40
   span nine modules, and the small ones are retail clones of each other:

       fn_12_321E8  152 B / 38 words   } 37 of 38 words identical to
       fn_12_32280  152 B / 38 words   } each other (the difference is a
       fn_12_32318  152 B / 38 words   } relocation addend)
       fn_12_3267C  152 B / 38 words   }
       fn_12_32834  152 B / 38 words   }
       fn_12_323B0  172 B / 43 words   } a second family
       fn_12_72F4   172 B / 43 words   }

   Closing `fn_12_321E8` once would have been worth five functions through
   `fzgx fixup --clones`. **It is not reachable**, so that leverage is only
   theoretical — see 5.

5. **The tie-break is a deterministic floor, not a search problem.** Five independent
   approaches on `fn_12_321E8` all converge on *exactly* five differing words:

   | Approach | Candidates | Best word errors |
   | --- | ---: | ---: |
   | declaration-order permutation | 492 (8 distinct scores) | 5 |
   | remove the `v0` temporary | 1 | 5 |
   | typed-pointer re-spelling | 1 | 5 |
   | `#pragma opt_lifetimes off` | 1 | 5 |
   | parameter-copy idiom + `#pragma opt_propagation off` | 321 | 5 |

   The permutation search does move registers — 492 candidates produced eight distinct
   scores from 5 to 12 word errors — so it is genuinely exploring; 5 is simply its
   floor, and the baseline already sits there. This matches `MWCC_IDIOMS.md`: *"a
   longer lifetime or more temporaries in its range; declaration order and the struct
   wrapper cannot change it."* Every way of supplying that extra lifetime or temporary
   adds an instruction, so it cannot be had for free.

   **Conclusion: this band is closed.** Do not re-run these five approaches, and do not
   read the clone concentration as an opening. The remaining frontier is the `mixed`
   band (250 of the 95-99% functions), which is ordinary matcher work.

### Why the floor exists: band width

`MWCC_IDIOMS.md` says register allocation follows *declaration order of locals*. That
governs the **callee-saved** webs only. Measuring how many saved registers each target
actually uses (r13-r31):

| Function | Saved registers in retail | Band width |
| --- | --- | ---: |
| `fn_12_321E8` | **none** (`r5` is volatile) | 0 |
| `fn_10_22760` | r30, r31 | 2 |
| `fn_1_10161C` | r30, r31 | 2 |

So `fn_12_321E8`'s tie-break is in a *volatile scratch* register, which declaration
order does not reach at all — the 492-permutation sweep was flat because there was no
saved band to permute. That is the mechanism behind the floor in 5, not a search that
gave up. The two width-2 functions were re-swept properly (713 candidates on
`fn_1_10161C`) and also held at 16 word errors, so the band width does not rescue them
either.

### External survey: what other GameCube decompilations do

Checked `zcanann/mwcc-rs` and `zcanann/SFA-Decomp` (Star Fox Adventures, the closest
MWCC precedent — a byte-exact reimplementation plus a measured catalogue),
`ACreTeam/ac-decomp` (Animal Crossing, the largest GC corpus), and the usual
`doldecomp` projects. Corrections to commonly-assumed names: **there is no `smb-decomp`/
`smbc` MWCC repo** (those names are N64/IDO), and **Melee is CodeWarrior 2.6/2.7, not
`mwcceppc`**, with no published codegen material. `SFA-Decomp` targets GC/1.3, not
1.3.2, and its authors warn the lever catalogue may not transfer.

Techniques worth carrying over, and what happened when tried here:

| Technique | Source | Result here |
| --- | --- | --- |
| `-pool off` / AC rodata-patched compiler | `mwcc-rs` README (GC/1.3.2r "disabled `.rodata` pooling"); `ac-decomp` | **Refuted by measurement.** `GC/1.3.2r` is installed here and scores −12, −21, −33, −94, −89 against stock on six pool-heavy functions. F-Zero GX retail uses *stock* pooling, which validates the 439-unit `mwcc_pool` machinery rather than undermining it. |
| `#pragma scheduling off` | 24 functions in this tree; findings/110 | **Added as a transform.** `optimizer_pragmas` proposed seven options and omitted `scheduling`, the only one that changes instruction *order*. Now emitted as an 8th proposal; did not close a function in testing, but it was previously unreachable. |
| `#pragma push`/`#pragma pop` around top-level `asm` | findings/110 | Already in the tree. |
| `-O3` to disable scheduling entirely | `mwcc-rs` flags | Not tried; `-O3` changes far more than order. |
| Per-TU flag-cell probe: compile under two profiles, **diff your two objects against each other**, name the transform, then reproduce it in source | `SFA-Decomp` `source_shape_levers.md` step 1b | **Not implemented.** This is the cheapest untried item: the infrastructure to build candidate objects already exists; what is missing is object-vs-object diffing. |
| Declaration-band model, reliable only below width 4 | `SFA-Decomp` | Explains our floor (see above); their widths ≥5 are "provably flat". |

Not adopted: anything SFA warns may not transfer across compiler generations, and
their conclusions share one author with `mwcc-rs`, so they are not independent
corroboration. `ac-decomp`'s pooling usage is the independent signal, and it pointed
the wrong way for this title.

### `fzgx flagcell`: the flag-cell probe, and what the pragma cell actually holds

`SFA-Decomp`'s cheapest technique is to compile one body under two settings and diff
**our two objects against each other**, which names the transformation the setting
performed instead of only reporting that the score moved. That is now a tool:

    fzgx flagcell SYMBOL [--a as-is] [--b "scheduling off" | -O3 | pragma ...]

`tools/fzgx/flagcell.py` compiles both cells, reports each cell's word score, and lists
the instruction rows that differ between them plus named effects (constant
materialised, callee-saved store/copy in the prologue, branch moved). It flags
`LENGTH CHANGED` when a setting adds or removes instructions rather than reordering,
which separates a real codegen change from a no-op.

Applied to `fn_1_466B0` it shows what `scheduling off` actually does: it hoists the
loop's `li r3, 0` out of the body and reorders the prologue's `mr r31, r4` /
`stw r30, 8(r1)` pair — 21 rows, no length change. Without the A/B diff that reads as
"the pragma made it worse for no visible reason".

**`-O3` is refuted by measurement**, like `GC/1.3.2r`: on `fn_1_466B0` it drops
97.53% -> 11.11% *and* changes length (81 -> 57 words); on `fn_1_4068C`,
93.94% -> 66.67%. It disables far more than scheduling.

**The pragma cell is exhausted for this shape.** Sweeping all eight cells on both
pure-schedule functions:

| Cell | `fn_1_4068C` | `fn_1_466B0` |
| --- | ---: | ---: |
| as-is | **93.939** | **97.531** |
| `peephole off` | 55.882 | 23.810 |
| `opt_propagation off` | 93.939 | 14.458 |
| `opt_common_subs off` | 93.939 | 97.531 |
| `opt_lifetimes off` | 93.939 | 97.531 |
| `opt_dead_assignments off` | 93.939 | 97.531 |
| `opt_strength_reduction off` | 93.939 | 12.644 |
| `opt_loop_invariants off` | 93.939 | 97.531 |
| `scheduling off` | 66.667 | 71.605 |

Nothing beats as-is. Four to six cells per function are exact no-ops (identical score),
and every cell that acts makes it worse. So these functions are **not** waiting on a
flag or pragma: the compiler is already in the right configuration and the residue is
not reachable from the pragma cell at all. That is a stronger claim than "the search
found nothing", and it is exactly what the A/B diff exists to establish.

### The stock compiler takes `-pool off` / `-pool on`, and pooling must be on

`ac-decomp` used `-pool off`, which I had read as tied to their `GC/1.3.2r` patch
rather than a flag. It is a flag: the **stock `GC/1.3.2`** accepts `-pool off` and
`-pool on` cleanly (`-nopool` is rejected as unknown). That makes pooling directly
probeable, and it is reachable through `flagcell --b='-pool off'`.

On `fn_1_2D038`, the archetypal 99.68% pool-row near-miss:

| Cell | Words | Score |
| --- | ---: | ---: |
| as-is | 315 | **99.683** |
| `-pool on` | 315 | 99.683 (byte-identical no-op) |
| `-pool off` | 344 | 9.302 |

So the default already compiles with pooling **on**, and turning it off is
catastrophic: it adds 29 instructions and pushes the whole prologue out of alignment.
That finally accounts for the `GC/1.3.2r` failure I could previously only record as
"fails catastrophically" — that compiler version disables pooling, which is precisely
the wrong configuration for this title. It also explains why pooling is the *dominant*
axis in the gate census (pool-load identity ranks far above band width as a predictor)
while being the one axis that must not be touched.

The practical consequence: for a `pool_rows` near-miss, the flag dimension is already
at its optimum, so the remaining work is source-shaped. Matching a pool load means
getting the pool's *sizes and order* right — which is why `colchg_selmate_disp`
needed a two-pool retarget rather than a flag change, and why `fn_1_2D038`'s residue
is a pool-layout question and not a compiler-setting one.

A defect worth recording, since it is exactly the failure mode an A/B tool exists to
avoid: the first `_disasm` omitted capstone's `skipdata`, so disassembly stopped at the
first undecodable word and compared only the common prefix. `-pool off` reported "the
two cells compiled identically" while the word counts were 315 and 344. Enabling
`skipdata` (undecodable words become `.byte` rows) makes the comparison span both
objects in full and reports the 312 rows that actually differ.

### `fn_1_2D038`: one hoisted address computation, characterised

The pooling result above says a `pool_rows` near-miss is source-shaped, so I took the
archetypal one — 315 words, 99.683% — and diffed our object against retail directly.
Exactly one row differs:

    65   RETAIL  lbz r0, 5(r3)      |  OURS  lbz r0, 0x35(r31)

This is **not** a semantic error. `unk_30.unk_5` sits at `0x30 + 5 = 0x35`, so both
sides read the same byte; retail holds the `&unk_30` base in `r3` with displacement 5,
while we fold the whole `0x35` into the displacement off `r31`. The remaining 314 words
agree, including the register allocation everywhere else.

Rewriting the access drops the redundant cast chain on the source line that computes it
(`((struct fn_1_2D038_hdr *)p_rod)->unk_5`) and the compiler then emits retail's exact
`addi r3, r31, 0x30` — but places it one row *later* than retail:

    64   RETAIL  addi r3, r31, 0x30   |  OURS  lbz r0, 0x35(r31)
    65   RETAIL  lbz r0, 5(r3)        |  OURS  addi r3, r31, 0x30

So the materialised form is reachable from source and the residue is a pure one-slot
scheduling difference: retail hoists the address computation above the load, we sink it
to its use. Moving the assignment earlier in program order does not hoist it, and
neither do `opt_propagation`, `scheduling`, `peephole` or `opt_common_subs`, all of
which leave the result byte-identical to as-is in both the cast and non-cast forms.

That is a tighter statement than "99.68% and stuck": the function needs its address
computation hoisted by one instruction, and that hoist is not reachable from program
order or from any pragma cell. Worth recording as the next concrete thing to attack on
this function rather than re-deriving.

#### The residue is an allocator fixed point, not a source-shape problem

Reading the surrounding rows settles the mechanism. The `addi r3, r31, 0x30` exists in
*both* objects — it is the argument to the `bl` two rows later:

    row  RETAIL                       drop-cast ours
     64  addi r3, r31, 0x30           lbz r0, 0x35(r31)
     65  lbz r0, 5(r3)                addi r3, r31, 0x30
     66  cmplwi r0, 2                 cmplwi r0, 2

Retail puts the address computation *before* the load, which is the only reason the load
can read `5(r3)`; we sink it to its use at the `bl`, which leaves the load free to fold
to `r31+0x35`. Each arrangement is a valid fixed point of the same optimiser and each
justifies the other, so no source rewrite that leaves both the load and the call reading
the same pointer can move between them.

Every lever aimed at breaking the tie was measured:

- Hoisting the assignment earlier in program order: no effect.
- `opt_propagation` / `scheduling` / `peephole` / `opt_common_subs` around the
  statement: byte-identical to as-is in both cast forms.
- Calling the file's own `fn_1_2D038_hdr_chk` helper instead of hand-inlining the check
  (it is defined, semantically identical, and wrapped in `opt_propagation off`, so it
  should have forced opacity): **22.7%**, 317 words — the pragma region disrupts far more
  than this one load.
- Forcing materialisation with a `volatile` pointer variable (16.4%) or a `volatile`
  load (20.3%): both collapse the function, because volatile forces a stack round-trip.
- Feeding the load and the call from one pointer variable: reverts to the fold (99.683%).

So the honest conclusion is narrower than "needs one hoist". The materialised form *is*
reachable from source, but every route that makes the compiler commit to it costs far
more than the two instructions it would save. `fn_1_2D038` stays at 99.683%, and as-is
remains the best body — the drop-cast variant scores *worse* (99.365%) despite emitting
retail's exact instruction pair. Reaching this would take a new transform, not a source
rewrite.

Note `mwconstraints.py` has since gained a `subkind` split (`cfebd280`), which is what
separates rows 1 and 2 above; this census imports the live module.

### Two more link-mismatch recoveries, and one that needs re-derivation

`fn_1_17A9C` -> `matched`/`verified` (`b37ca544`) and `fn_1_32600` -> `matched`
(`82ef5b7a`). Both were parked at exactly 100% with the object already perfect.

**`fn_1_17A9C`: the helper carried a comment.** Its parked body declares
`static f32 vec_dist(...) /* locks the load order of the three components */ {`,
and `inline_helpers` required `{` immediately after the parameter list, so it never
matched — the shape most likely to need inlining (a hand-named reconstruction a
matcher wrote down and explained) was the one it never saw. `fn_1_32600`'s primer had
the same shape (`static void fzgx_bss_layout(void)`) and did match.

**`fn_1_32600`: one file-scope object violated the body's own convention.** A `.bss`
layout primer reconstructs the retail TU's file-scope objects in address order, and
each gets a private `fzgx_obj_` copy so it cannot collide with whatever unit really
owns it. Five of its six did:

    u32 fzgx_obj_lbl_1_bss_50EC[5];
    u32 fzgx_obj_lbl_1_bss_5100;
    u32 fzgx_obj_lbl_1_bss_5104[13];
    u32 fzgx_obj_lbl_1_bss_5138[65];
    u32 lbl_1_bss_523C[8];          <- real retail name, no prefix

`lbl_1_bss_523C` is a global 0x20-byte object referenced by `fn_1_3F250`, a different
function. Defining it here is a duplicate definition of another unit's symbol, which
the `extra_data` guard correctly refused. Adding the prefix its five siblings already
use fixed it, and the six objects then land in `.bss` at retail's exact sizes
(3C30=5308=0x14B0, 523C=32=0x20, 5138=260=0x104, 5104=52, 5100=4, 50EC=20).

It landed as `link_state=pool`, not `verified`: the private `.bss` copies cannot be
emptied, so the retail object is still linked. That is the documented pool-match
terminal state, and it counts as matched but does **not** advance linked-files — worth
knowing before reading a `matched` count as progress on linking from C.

**`fn_12_23410` needs re-deriving, not repairing.** Its parked body only reaches
96.84%; the 100% in the ledger came from an earlier body that is no longer on disk.
Attempted, and the structure is now known exactly — retail unrolls **four** search
passes over the same 0x800-byte staging buffer, at source offsets **0, 2, 1, 3** in
that order, each with its own 4-byte argument slot (`r1+0x14`, `+0x10`, `+0xc`,
`+0x8`), each computing `n = min(size - k, 0x800)` with a *signed* compare, and each
storing on a hit:

    st->unk_0c = lbl_12_rodata_A18; st->unk_28 = p[7];
    st->unk_2c = (p[8]<<24)|(p[9]<<16)|(p[10]<<8)|p[11];

It is **not** a called helper: the parked body's `static int find_entry(...)` models
something retail does not have. The assembled replacement reproduces the row count
exactly (192 target / 192 ours) and its field stores match, so the control flow is
right — but it scores **54%** on words against the parked body's **96.8%**.

The blocker is register allocation, not structure. Retail brackets the frame with
`stwu r1, -0x30(r1)` + `stmw r27, 0x1c(r1)` — five saved registers — and keeps the
hit flag in volatile `r6`, assigned only on the two loop exits. Every C spelling
tried instead allocates `hit` or `n`/`p` to callee-saved registers and emits
`bl _savegpr_23`/`_26` over a `-0x40` frame: scoping `n`/`p` inside each pass block
made it *worse* (9 saved registers), hoisting `n`/`p` with a per-block `hit` cost four
extra 4-byte slots, and a single hoisted `hit` with early returns still lands on 15
instruction-shape differences. Closing this needs the source spelling MWCC's
allocator actually chose, which the assembly alone does not pin down.

**The parked body is therefore left in place** — it is the better C, and replacing it
with a structurally more faithful but word-worse derivation would be a regression. A
machine doing this should iterate compile→diff→reshape, not apply one edit.

That empties the re-drivable pool: of 141 symbols with a `link-mismatch` history only
18 ever had a body parked on disk, and all 18 have now been driven.

The has-initializers guard is still moot for the reason given: it raises the
candidate count of a path gated earlier. That part of the withdrawal stands.

Caveat: `.fzgx/work/*.o` holds only what was last compiled locally, so this
census is a lower bound on the plateau, not the full fleet corpus. The
"317 captures with a saved body" set is not reconstructible from this tree, so
the original 317 figure could not be re-derived directly — only contradicted on
a comparable population.

### The compiler-configuration dimension is now fully exhausted

Sweeping every cflag the compiler *accepts* (28 of them, found by probing which flags are
rejected as unknown) against both a pool-heavy and a schedule-shaped function. Nothing
beats as-is on either:

| | `fn_1_2D038` (pool) | `fn_1_4068C` (schedule) |
| --- | ---: | ---: |
| as-is | **99.683** | **93.939** |
| `-O0` / `-O1` / `-Os` | 2.5 / 6.0 / 2.5 | 1.5 / 5.4 / 1.5 |
| `-O2` / `-O3` / `-O4` | 9.8 / 9.5 / 7.3 | 66.7 / 66.7 / 93.9 |
| `-sdatathreshold 0` | 99.683 | 93.939 |
| `-sdatathreshold 4..1024` | 41.905 | 93.939 (1024: 18.2) |
| `-pool off` | 9.302 | 93.939 |
| `use_lmw_stmw` / `lmw` / `char unsigned` / `nodefaults` / `longlong` | 99.683 | 93.939 |

The configuration space is not merely unexplored — it is fully mapped, and the project's
existing configuration is the global optimum of it. Together with the eight pragma cells
and the two compiler versions already refuted, there is no remaining compiler-side
lever. Anything that improves from here has to come from the source.

### Where the remaining work actually is

Profiling the 1613 unmatched by size against best score shows the mass is not where it
looks:

| size (bytes) | <50 | 50-79 | 80-94 | 95-98 | 99+ | total |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| 64-159 | 11 | 13 | 31 | 26 | 11 | 92 |
| 160-400 | 5 | 29 | 106 | 88 | 41 | 269 |
| 400-1000 | 20 | 111 | 233 | 167 | 73 | 604 |
| **1000+** | **108** | **331** | 160 | 28 | 12 | **639** |

639 functions are 1000+ words, and 69% of them are below 80%. They are 40% of the
unmatched population and the worst-performing segment by a wide margin. A 4000-byte
function must match every word, so 80% there is ~800 wrong instructions — a different
problem from the one-instruction residues chased above. Fixing these is a
decompilation-quality problem (struct layouts, control-flow reconstruction, float/int
typing), not a codegen problem, and no compiler setting touches it.

### 842 functions have attempt records whose bodies are not on this machine

1606 unmatched functions have `attempts > 0`, but only 764 have a retrievable body. The
rest record a `best_body_path` under `/Users/rayan/fzgx/.fzgx/attempts/` — another
machine. The ledger was seeded from that setup, so the attempt counts and percentages
arrived but the `.c` files did not.

This is not a blocker: nothing in the accept path compares against `best_percent`, so a
100% body still submits regardless, and `claim` seeds the work copy from
`state/donor_seeds/` or the existing `src/` body. But those recorded percentages are not
locally reproducible and the prior work cannot be recovered — an agent picking one up
starts from the donor seed with none of the earlier exploration available.

Recorded because it changes what a low `best_percent` on those symbols means: it is a
leftover, not a measurement anyone can reproduce here.

**A correction worth keeping.** An earlier `-use_lmw_stwm` sweep appeared to show
`fn_800478C0` jumping from 2.94% to 94.00% — a single-flag unlock. It was a bug in my
sweep, which hardcoded `main_rel` while the function is module `main`, comparing
mismatched builds. Measured properly it is 2.804% either way, and a corrected sweep over
13 functions found no improvement. The flag is inert here. The lesson is the boring one:
a surprising result that large is a bug until proven otherwise, and re-measuring against
the resolved module took seconds.

### `fzgx structmap`: naming the layout retail requires

The large-function profile above says the dominant problem is struct layouts, so the
tooling now says which layout. `fzgx structmap SYMBOL` reads the retail object only (no
candidate body, so it is fast) and prints, per base register, every field offset that
register actually touches, split by load/store and width:

    STRUCTMAP fn_8005DCEC (main)  retail 1980 words
      base r3: 44 distinct offsets (0x0..0x151c)
         lbz  load  15: 0x45b 0x461 0x462 0x589 ... 0x1408 0x140b
         stb  store 10: 0x1408 0x1409 0x140a 0x140b ... 0x1498 0x1499
         stw  store 15: 0x46c 0x141c 0x1420 0x1424 ... 0x151c
      base r9: 8 distinct offsets (0x0..0xe)
         sth  store   8: 0x0 0x2 0x4 0x6 0x8 0xa 0xc 0xe

Every offset listed is a field the struct definition has to account for. `r9`'s eight
even `sth` offsets are a packed `s16[8]`; the dense `0x1408`-`0x14f0` store region on
`r3` is almost certainly an embedded struct we have flattened or mis-sized. Comparing
that against the candidate makes the failure legible: on `fn_8005DCEC` (1980 words,
1.04%) retail performs 15 distinct `stw` offsets and our object manages one, with zero
`sth` anywhere — the layout is wrong, not the codegen, and no compiler setting touches it.

Useful on its own, and a cheap first move on any badly-scoring large function: read the
offsets the layout must have before touching the body.

#### `--body`: which fields the layout is missing

Passing a candidate body turns the fingerprint into a diff against it. Offsets are pooled
across base registers rather than compared per register, because retail and our object
need not pick the same register for a given struct and a per-base diff reports spurious
differences; the field *offsets* are what the layout must contain, and those do compare.

    fzgx structmap SYMBOL [--body PATH] [--mw-version V]

On `fn_8005DCEC` (1980 words, 1.04%) it reads as a work list rather than a mystery:

    STRUCTMAP COMPARE fn_8005DCEC (main)  retail 1980 words, ours 1.042%
      lbz  retail=49  ours=42   MISSING: 0x58e 0x590 0x591 0x594 0x59a 0x59b 0x1408 0x140b  EXTRA: 0x40 0x60
      lhz  retail=12  ours=25   MISSING:   EXTRA: 0xc 0xe 0x10 0x12 0x14 0x16 0x18 0x1a +5 more
      stb  retail=11  ours=1    MISSING: 0x1408 0x1409 0x140a 0x140b ... 0x1498 0x1499  EXTRA: 0x0
      sth  retail=10  ours=0    MISSING: 0x0 0x2 0x4 0x6 0x8 0xa 0xc 0xe 0x1414 0x1416
      stw  retail=15  ours=1    MISSING: 0x141c 0x1420 0x1424 0x1428 0x1434 0x1480 ... +2 more

`sth` 10 against 0 is the loudest line: the packed `s16[8]` at offsets `0x0`-`0xe` is
absent from our layout entirely, and the dense `0x141c`-`0x14f0` `stw` region has one
field against fifteen. Those are two concrete edits to a struct definition, which is a
very different next action from "the function scores 1% and I have no idea why".

Two limits worth stating. This compares offsets, not semantics: a function can have every
offset present and still score low if its control flow is wrong — `fn_9_1310` reports
"every field offset retail uses is present" on a candidate that scores 24.6%. And it
reports which offsets are absent, not the field *types* or names, so it narrows the
search without solving it. The fingerprint half needs no candidate body and so works on
functions whose history is entirely missing.

#### `--skeleton`: a provisional layout from access widths

`--skeleton` infers a struct for one base register from the widths retail touches,
grouping contiguous touched bytes into runs and classifying each as a scalar, an aligned
array, padding, or ambiguous. `--base rN` picks the register; the default is the
most-accessed one.

    fzgx structmap fn_8005DCEC --skeleton --base r9
      STRUCTMAP SKELETON fn_8005DCEC (main)  base r9  offsets 0x0..0xf  (INFERRED, review before use)
        u16 /* signedness unknown */ unk_0[8];   // 8 aligned sth accesses, store-only

    fzgx structmap fn_8005DCEC --skeleton     # base r3, the dense region
        u32 /* signedness unknown */ unk_141C;   // stw, store-only
        u8  pad_1420[4];
        u32 /* signedness unknown */ unk_1424;   // stw, store-only
        ...

This is a starting point for a human, not a header to paste, and three limits are
enforced in the output rather than buried here:

- **Signedness is only knowable from a signed load.** A field retail merely stores gives
  no evidence, so it prints `/* signedness unknown */` rather than a confident `u32`.
  That is most of the `0x141c`-`0x151c` region, which retail only ever writes.
- **Ambiguity is reported, not guessed.** Where runs have overlapping widths the field
  prints `/* ??? */` with the widths involved.
- **Store-only versus read-back is invisible.** A field written once and a field written
  in a loop are indistinguishable here.

Two bugs found by testing this on a 60-function sample rather than on the one function
that motivated it. `lmw`/`stmw` match the mnemonic shape but describe a register range,
not a field, and crashed the width lookup; they are now skipped. And the run builder
seeded each new run with the *gap* byte, which put an untouched offset inside a run and
raised `KeyError` on any struct with a hole. Both were invisible on `fn_8005DCEC`, whose
r9 accesses happen to be contiguous.

### Testing the struct-layout thesis, and narrowing it

The tool is built; the question is whether acting on it actually helps. Two functions with
the cheapest possible fix -- one missing offset -- say the answer is *sometimes*, and the
earlier framing was too broad.

**Where it is a real layout failure.** `fn_8005DCEC` (1980 words, 1.04%) keeps its verdict
even after the base-register fix below: 15 distinct `stw` offsets against 1, 11 `stb`
against 1, and 10 `sth` against 0 — a packed `s16[8]` that is simply absent from our layout.
That is a genuine, large, actionable gap.

**Where it is not.** On `fn_1_9A508` (28 words, 39.29%) the first diff said
`MISSING: 0x20  EXTRA: 0xb0c 0xfbc`, which reads like three layout errors. It is none of
them. Retail's offsets through r4 are `0x0, 0x48, 0x54` and ours are *identical* — the r4
layout is already correct. `0x20` comes from r6 and the extras from other bases; they are
different objects, not wrong fields. Its 39% is something else entirely.

**Where it is not even a struct.** `fn_8008F8B0` stores to `r5+0x3000`; we materialise the
absolute address. That is the `0xCC00xxxx` hardware register window, not a field. Any
non-stack base looks like a struct pointer in the instruction stream, so memory-mapped I/O
and struct layout are indistinguishable here.

So the thesis narrows to: **wrong struct layouts are a major cause on the very large
functions, and largely not a cause on small and mid-sized ones.** Of the 639 functions at
1000+ words that are 40% of the remaining work, the evidence supports it; across the rest
of the population it should not be assumed.

#### A false-positive mode in `--body`, and the guard

Comparing offsets pooled across base registers hides real gaps and invents them. It
invented the `fn_1_9A508` result above: pooling throws away which register produced an
offset, so two bases pointing at different places in one object look like one field
missing and another spurious. `compare` now uses the base directly when both sides use the
same register set, and otherwise says so in its own output:

    base registers differ (r3,r4,r6,r31): offsets pooled, so a missing/extra pair
    may be one field reached through a differently-based pointer

On a 22-function sample the modes split 3 per-base / 19 pooled with no crashes, which is
itself the useful finding: for most functions a pooled offset diff **cannot** be trusted,
and the tool now declines to imply that it can.

### `fn_1_4DE04`: MW unrolls, retail did not — and unknown pragmas are silently ignored

The cheapest end-to-end test of the layout thesis: `fn_1_4DE04` (16 words) reported one
missing field. It is not a layout problem at all. Our layout is exactly right — offsets
`0x0, 0x80, 0x100, 0x180, 0x200, 0x280, 0x300, 0x380` at stride `0x400`, precisely what
retail stores to. Retail is an 8-iteration CTR loop:

    li r0, 8 ; mtctr r0 ; stw r4, 0(r3) .. stw r4, 0x380(r3) ; addi r3, r3, 0x400 ; bdnz

We emit **63 distinct offsets**, because MW unrolls the loop. Rewriting the induction as a
strided pointer takes it from 67 words to 41 and from 0.000% to 4.878% — the unroll drops
from fully flattened to 4×. Every loop shape tried (countdown, post-decrement `i--`,
`while`, `volatile` pointer, `do/while`) lands at 39–41 words. Retail is 16.

**The finding that matters more than this function: MW does not reject unknown pragmas.**
Nine plausible names — `unroll off`, `nounroll`, `no_unroll`, `opt_unroll off`,
`opt_loop_unroll off`, `unroll 1`, `unroll 2`, `opt_unrolling off`, `ipa unroll off` —
all compiled cleanly and produced **byte-identical** objects. Not one took effect.

So a pragma experiment that only checks the exit code proves nothing here. An agent can
"apply" a pragma, see it accepted, and conclude it was honoured when it was discarded. Any
pragma result must be verified against the compiled object — which is exactly what
`flagcell A/B` does, and why the pragma-cell census in this document was run by comparing
objects rather than by trusting that a pragma compiled. The eight pragma cells are inert
for this function, which is consistent with them being inert generally.

Third distinct cause found for "the offsets do not match": after a genuinely wrong layout
(`fn_8005DCEC`) and a base-register artefact (`fn_8005DCEC` pooled, `fn_1_9A508`), this is
an induction-variable difference — same layout, different loop form. Reading `stw` counts
alone cannot tell them apart.

### The optimisation level is per-function, and my "as-is is the global optimum" was wrong

`fn_1_4DE04` turned out not to be a dead end. Sweeping levels on it:

| level | words | `mtctr`/`bdnz` | score |
| --- | ---: | :---: | ---: |
| as-is | 41 | yes | 4.878 |
| `-O0` / `-Os` | 31 | no | 0.000 |
| `-O1` | 26 | no | 3.846 |
| `-O2` | 19 | no | 5.263 |
| `-O3` | 17 | yes | 5.882 |
| **`-O4`** | **17** | **yes** | **17.647** |

Retail is 16 words. `-O4` produces retail's `mtctr`/`bdnz` form at 17 words. This overturns
the claim above that the configuration space is mapped and the project's configuration is
its global optimum. That claim was measured on `fn_1_2D038` and `fn_1_4068C`, which happen
not to be loop-sensitive; the correct statement is narrower.

Two samples of unmatched functions with a body, testing whether a level beats as-is:

- 13 functions, any of `-O2`/`-O3`/`-O4`: **6 of 13** improved by some level.
- 21 functions, `-O4` alone: **4 better, 9 worse, 8 equal.**

So no level is a global win — `-O4` loses more often than it wins. But it is
high-variance, and the wins are large where they happen: `fn_10_8DFC` 10.14% -> 51.47%
(**+41.3**), `fn_10_19924` 18.47% -> 45.45% (**+27.0**), and `fn_1_4DE04` above. Both
functions that gained the most were near-hopeless, which is where a stuck agent has
nothing to lose.

The actionable form is therefore narrow and specific: **sweep levels per function, do not
switch the project globally.** A level that helps one function wrecks another, and the
default is best on average, so this is a last-resort probe on a function that is otherwise
stuck — not a new build configuration. `flagcell --b=-O4` does exactly this in one command
and prints both scores.

Note also that `-inline on`, `-inline off` and `-nodefaults` are all byte-identical to
as-is on `fn_1_4DE04`, consistent with the pragma census: the configuration axis is mostly
inert, and the one part of it that is live (optimisation level) is per-function.

### Where the level probe can actually be applied

Per-unit `extra_cflags` are supported end to end — `_set_unit_opts` writes
`u["extra_cflags"]` into the unit and `_reconfigure_and_split` regenerates the build — so
`-O4` is applicable to a single function without touching the project configuration. On
`fn_10_8DFC` it takes the function from 10.14% to 51.47%, with the object the same length as
retail (68 against 67 words) and a differing prologue and call order. That is a far better
starting point, but closing it is real decompilation work rather than a probe.

The limiting factor is which functions can be probed at all, and it runs the opposite way to
intuition. Body availability by best score, among unmatched functions with `attempts > 0`:

| best_percent | functions | body available |
| --- | ---: | ---: |
| 0–35 | 51 | 6 (11%) |
| 35–60 | 177 | 30 (16%) |
| 60–90 | 735 | 315 (42%) |
| **90–100** | **641** | **625 (97%)** |

The worse a function scores, the less likely its body is on this machine — the opposite of
what is wanted. The functions a level probe would help most are the ones whose source is
missing, because those are the ones that were worked hardest elsewhere. A sweep of the 0–35%
band tested exactly one function in a minute and found nothing, because 89% of that band has
no body to sweep.

So the actionable population is the **90–100% band: 625 functions that both have a body and
are close enough that a different level could plausibly finish them.** That is where a
per-function level probe belongs, and it is cheap there — one `flagcell --b=-O4` per
function, no build change beyond that one unit's own flags.

This also sets a ceiling on the whole effort. A perfect level probe addresses the 625
functions that already have bodies; the 632 bodies that never migrated cap what any of this
tooling can reach without recovering rayan's tree.

### The right target set is "has a local body", not the 90–100% band

Testing the proposal before spending an hour on it turned up two things. First, taking the
best of `-O2`/`-O3`/`-O4` against as-is over 25 functions from the 90–100% band:

    some level better: 7 of 25 (28%)     worse: 0     equal: 18

    fn_10_8DFC   10.14% ->  51.47% via -O4  (+41.3)
    fn_1_3F5F8   41.57% ->  76.40% via -O4  (+34.8)
    fn_8005B264  17.97% ->  24.22% via -O3  (+ 6.2)

**Zero regressions**, against 9 losses out of 21 for `-O4` alone earlier. The difference is
that this takes the best level per function instead of committing to one, and a level that
hurts a function simply loses to as-is. So the probe is safe to run broadly, which the
`-O4`-alone result would not have suggested.

Second, and this corrects the target set: `fn_10_8DFC` was selected by the query
`best_percent >= 90` and yet compiles at **10.14%** here. The ledger says 90%+ because that
figure was recorded on another machine; the body on this tree is nowhere near. So the
"90–100% band" is not a band at all for the migrated functions — it is a set of stale
percentages. Selecting on ledger score picks the wrong functions.

The correct selection is simply **functions with a local body**, which after the `_attempt_text`
fallback is 974 of them. For those, `flagcell` against `-O2`, `-O3` and `-O4` is cheap, never
regresses, and wins on roughly a quarter to a third — with the largest gains concentrated
exactly where the earlier samples said they would be.

### Level scan result: 233 of 972 functions have a better level

`fzgx levelscan` over every unmatched function with a local body:

    checked 972   wins 233 (24%)   zero regressions by construction

| gain | functions |
| --- | ---: |
| > 20 points | 29 |
| 5–20 | 71 |
| 1–5 | 92 |
| < 1 | 41 |

By winning flag: `-O2` 104, `-O4` 67, `-O3` 62. The largest:

| function | as-is | best | flag | gain |
| --- | ---: | ---: | --- | ---: |
| `fn_8003D42C` | 7.89 | **89.19** | `-O2` | **+81.3** |
| `fn_12_2E7C8` | 1.45 | 61.54 | `-O2` | +60.1 |
| `fn_12_316A8` | 24.55 | 80.00 | `-O4` | +55.5 |
| `fn_1_A24CC` | 29.81 | 82.69 | `-O4` | +52.9 |
| `fn_8008983C` | 0.00 | 47.62 | `-O4` | +47.6 |
| `fn_80078360` | 2.54 | 49.15 | `-O2` | +46.6 |
| `fn_8006B224` | 0.00 | 42.86 | `-O3` | +42.9 |
| `fn_10_8DFC` | 10.14 | 51.47 | `-O4` | +41.3 |

`fn_8003D42C` was independently recompiled to confirm the scan rather than trust it:
7.895% as-is against 89.189% with `-O2`, reproducing the recorded figures exactly.

Two things this changes. The 24% hit rate on a population chosen for having a body is close
to the 28% seen in the 25-function sample, so the sample was not misleading. And the scan
finished in minutes, not the hour budgeted for it, because a compile of these small bodies
takes about **0.03 s** — far cheaper than this work has been treating it. Scepticism about the
run time was reasonable and wrong; the compiler is simply very fast on small functions, which
means the fleet can afford far more per-function probing than the cost model assumed.

The scan only reports. Applying a level means `_set_unit_opts` plus `_reconfigure_and_split`,
which mutates the build, so those 233 are a work list for whoever owns the build rather than
something to apply in bulk from here.

### Bottleneck 3 resolved: there is no global unroll discrepancy

The open question from `fn_1_4DE04` was whether MW unrolls where retail did not — which,
if global, would be a class. It is not global. Of 14 sampled **matched** functions, **12
contain a rolled loop in retail** (`mtctr`/`bdnz`), and MW reproduces all of them exactly:

    fn_1_9AF80  793w  mtctr=5  bdnz=5      fn_1_CC8E4   674w  mtctr=8  bdnz=8
    fn_1_134EE4 620w  mtctr=13 bdnz=13     fn_1_E4A38   430w  mtctr=48 bdnz=0
    fn_1_15578  913w  mtctr=1  bdnz=1      fn_1_CC280   409w  mtctr=2  bdnz=2

Since 5,701 functions match word for word, MW's unrolling already agrees with retail
everywhere it has been made to. So there was never a flag or build difference to find — the
residue is a per-function register-allocation tie-break.

And it is a small one. At `-O4` the function compiles to retail's exact loop structure —
`li r0,8; mtctr;` the same eight stores at `0x0`..`0x380`; `addi +0x400`; `bdnz` — at 17
words against retail's 16. The entire difference:

    RETAIL                          OURS (-O4)
    lis r3, 0                      lis r3, 0
    li r0, 8                       li r0, 8
    addi r3, r3, 0                 addi r3, r3, 0
    li r4, 0                       mr r4, r3        <- the only extra instruction
    mtctr r0                       li r3, 0         <- zero lands in r3, not r4
    stw r4, 0(r3) ...              stw r3, 0(r4) ...

Retail keeps the loop-carried pointer in `r3` and the invariant zero in `r4`. We do the
opposite, which forces the copy. Source shapes tried and all byte-identical at `-O4`:
making the zero an explicit local, a separate `zero = 0` statement, `u32` versus `s32`
types, a pointer-`++` induction over an array. None moves the allocation.

One result worth flagging as **not** a fix: advancing the pointer at the top of the body
gives exactly 16 words, but then strides by `0x800` instead of `0x400` and writes to the
wrong addresses. It matches the length and scores 31.25% while being semantically wrong, so
it must not be mistaken for progress toward a match.

Net: `fn_1_4DE04` is one register-role swap from matching, and the "MW unrolls" mystery —
the last open candidate for a class-level lever — is closed.

### Sizing the near-miss classes: the scheduler class is small

`fn_8003D42C` is the closest the level scan gets — 89.19% under `-O2`, and only **4 of 37
rows differ**, in two adjacent pairs:

    4  RETAIL li r0, 0x1a      | OURS lbz r5, 0(r4)
    5  RETAIL lbz r5, 0(r4)    | OURS li r0, 0x1a
    19 RETAIL addi r4, r4, 3   | OURS cmplwi r5, 0xff
    20 RETAIL cmplwi r5, 0xff  | OURS addi r4, r4, 3

Every register and every other instruction agrees. It is the same root cause as
`fn_1_2D038` (one hoisted address computation) and `fn_1_4DE04` (one register-role swap):
**retail hoists an independent instruction, MW sinks it to its use.** All the levers fail
here too — reordering the two independent statements in the source, hoisting the constant to
a function-scope `const`, rewriting `v1 += 3` as `v1 = v1 + 3`, and all five pragma cells at
`-O2` are byte-identical to as-is.

So the class is characterised but not reachable. The useful question is therefore its size.
Across all 978 unmatched functions that have a local body, each compiled at its recorded
level and compared row by row:

| class | count | share |
| --- | ---: | ---: |
| word-identical to retail | 11 | 1% |
| **adjacent-instruction swaps only** | **30** | **3%** |
| structural differences | 930 | 95% |
| no body / no target | 8 | 1% |

**The hoist/sink class is 30 functions, not a population.** Even perfect handling of it caps
out at 30, and each is 2–8 rows from a match — the hardest kind of work to automate. The
other 95% differ structurally, which is ordinary decompilation and belongs to the fleet.

Two corrections to claims made while measuring this. `oracle.check`'s `source` argument is a
`Path`, not the source text; passing a string hands the text to the compiler as a filename
and returns a usage error, which is what made the 11 look like they had failed a real diff.
With correct usage objdiff scores **higher** than raw word matching, because it treats
accepted relocation equivalences as equal — `fn_1_4068C` reads 99.64% against a word score
of 93.94%, and `fn_1_150654` 99.51%. None of the 11 is a match (`unit_fully_matches` is
False for all), so they are near-misses rather than submissions waiting to happen.
