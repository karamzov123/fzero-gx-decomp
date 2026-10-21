# F-Zero GX (GFZE01) matching decompilation

Matching decompilation of F-Zero GX built on decomp-toolkit / dtk-template.
Targets: `sys/main.dol` plus fifteen RELs (fourteen shipped as `files/fze.*.rel`
and `main.rel`, which `tools/prepare_orig.py` derives from `enemy_line/line__.bin`).
`ninja` must always end with `16 files OK`.

## What "done" means (owner, 2026-10-04)

**The project is complete when all 16 targets link with 100% of code written in C.** That is
the definition and it is not yet met.

**The active goal is (b): all 16 targets linked, with honest code percentages, main_rel open.**
main_rel is 56% of the remaining work and its functions do not yield to the current methods, so
(b) is the milestone worth steering by while (a) stays the finish line.

Two metrics, and the difference between them matters:

    `fzgx report`      objdiff's matched_functions / complete_units -- SOFT
    `fzgx honest`      matched functions that have a compiled C body -- HONEST

The soft number credits functions that were never written in C, because a function inside a
retail auto object matches by construction (docs/findings/280). Giving such a function its own
split *lowers* both counters with nothing regressing, so the soft number cannot answer "did
that change help". `fzgx honest --closure` is the steering table for goal (b): per module, what
is authored and what each module still costs.

## Measured dead ends -- do not re-propose these

Each was measured, not assumed. The evidence is in `docs/findings/`.

- **A better `-O` level is not a match.** 269 functions have a measured better level; they are
  already applied, and none of the 268 still-valid ones reaches 90%. See 282 and
  `docs/LEVELSCAN.md`.
- **The deterministic repair engine does not close the ≥99% band.** 40,208 candidates over the
  whole band, 0 matches (282). Register repair has likewise produced 0 matches from 170
  functions of captured allocator decisions (`docs/REGISTER_REPAIR.md`). The hard tail is a
  source-shape problem; its owner is a model session, not a search.
- **The SDK save/restore register family cannot be asm units.** `__save_fpr` and friends alias
  compiler-generated symbols that mwld also defines (281).
- **Raising MAX_STALE** buys tokens, not matches: a 99.5-100% plateau exit converts 18.8% of
  the time even with unlimited further attempts (274).
- **Do not reallocate providers on the "gpt is 40% cheaper" claim** -- retracted as a
  measurement artifact (276).
- **The ≥90% band is not short of search, it is short of a source shape.** `sweep` on the whole
  band: 0/40,208 (282). Worked example in 284: four structurally different bodies for
  `colchg_menu_disp` converge on *exactly* 90.093025 with a byte-identical diff, because the
  residue is which register MWCC picks -- not a statement a family can move.
- **`regalloc` is a bucket, not a shape.** `fzgx shapecensus` splits the band's differing rows:
  12% are relocation-only (objdiff `p`, no codegen difference at all), and the ~64% that are
  register-only spread over ten unrelated pairs with different causes (285). Re-measure with
  the tool before building anything for this band.
- **Rank near-misses by differing WORDS, never by diff rows.** objdiff aligns rows, so one late
  divergence inflates into many flagged rows that then look like relocation problems.
  `fzgx shapecensus --words` is the honest count: `fn_1_2D038` shows 26 rows for **1 word**, and
  seven functions in the band are exactly one word from matching, five of them with a single
  named operand to change (286).
- **An attempt-cap refusal is triage, not an obstacle.** `colchg_menu_disp` sits at 94.74% and
  `claim` refuses it; the fix is a hypothesis about register liveness (284), not another run.
- **A family band that has drained is silent.** `FAMILY_BANDS` is a *supply* statement, and an
  exhausted band raises nothing: `choose()` widens to the whole backlog, so the family keeps
  producing plausible batches while re-deriving what it has already seen. That is how cline and
  oc1 spent 57% of six hours' attempts on a band measured at 0 matches (283). Re-run the
  virgin-by-band table before changing or trusting a band.

## Other forks and cloud sessions are a source of matches (2026-10-21)

`fzgx harvest REF [--land]` tries every function matched on another ref (a fork branch,
or a cloud session's `claude/*` branch) that is unmatched here, under that ref's compiler
options and with its names rebound by address; only oracle matches are submitted, and
`fzgx verify` still gates the link. The first run against `deltawave784/fzgx`
(`windows-and-types`) found 465 such functions, and 459 passed the oracle. **Fetch the
active forks before starting new matching work** (`gh api repos/rayanht/fzgx/forks`). Cloud
sessions: `tools/cloud/bootstrap.sh`, docs/CLOUD.md. Harvest candidates (raw, ours-prologue,
selective, fork-headers, preprocessed) and their gates are in docs/CLOUD.md; candidates are checked
in the spliced form (includes hoisted), because that is what the link compiles. On 2026-10-21 every
fork of rayanht/fzgx and karamzov123/fzero-gx-decomp was compared by module+address: only
deltawave784's `windows-and-types` holds matches we lack (462/465 landed, 3 left). Measured 2026-10-21, nothing left
there: exact and opcode-identical clones (2 recipients), siblings with ≥70% opcode
similarity (31 functions), SMB1 decomp as an engine donor (4 functions; it is also
unlicensed).

## Setup (once)

```sh
brew install ninja
# put the disc image in orig/ (RVZ/ISO), then:
uv run tools/prepare_orig.py --version GFZE01   # extracts targets, derives main.rel
python3 configure.py --version GFZE01 && ninja  # downloads dtk/objdiff/wibo/compilers on first run
uv run tools/fzgx.py sync                       # loads 7,308 functions into .fzgx/ledger.db
uv run tools/fzgx.py restore                    # (optional) load state/ledger.json history
```

## Agent workflow

Headless batches use `uv run tools/orchestrate.py --harness codex ...`.
One local Codex app server multiplexes the model sessions; a bounded pool of
persistent CLI workers serves dynamic tools. Each request binds its own function
and agent; project indexes are reused until symbols, units or build configuration
change. Active calls and claims share the tool bound with 3:1 fair dispatch, so
claims cannot starve behind a continuous stream of edits. The runner assigns functions
and supplies their existing C and initial diff. Models only edit/check their
bound work copy or release early for a technical reason. Tooling accepts matches
and releases exhausted attempts; the runner interrupts and unloads the thread.
No model-generated claim, submit, limit acknowledgement, or RESULT line is
needed. The manual CLI/MCP operations remain available. See
`AGENTS.md`, `docs/CODEX_APP_SERVER.md`, and `docs/CODING_RULES.md`.

Rules that hold for everyone:

- Never commit anything from `orig/` or `build/`; never commit compilers.
- Never push. Commits are local; the user pushes.
- Commit completed work before reporting it finished, including tooling, provenance,
  and dependent source changes required by generated matches. A working-tree hash
  check does not prove that an incomplete commit will build in CI.
- Adjacent SDK reuse goes through `fzgx sourcealign --compile-sdk NAME --root PATH`
  (repeat `--root`), then `--discover --min-size 64`, `--saved`, and `fzgx verify`.
  `fzgx sourcealign --apply-names` imports unambiguous donor function names after
  verification; it updates references and provenance and checks all target hashes.
  Check all library roots: MK Deception's ADX and MSL sources are separate from Sofdec.
  The importer currently accepts CC0 sources, copies their license and provenance into
  `state/sdkimports/`, and emits owned C without external-project includes. Compile donors
  against their own nested standard-library headers and source-relative includes.
  For game-code reuse, `--rel-only --root PATH` restricts discovery to REL targets
  and selected donor roots. `--compile-sdk NAME --functions --root FILE` compiles
  independent declaration closures when a full donor TU needs unavailable assets;
  unresolved dependencies are excluded. F-Zero X's N64 build defines are supplied
  by the importer, without inheriting F-Zero GX's project defines.
  `sourcealign --fuzzy --rel-only --min-size 256 --root PATH` ranks whole-function
  and partial opcode overlap without the importer's size and similarity cutoffs;
  `.fzgx/sourcealign/fuzzy.jsonl` retains block offsets and operand agreement.
  Compiler variants share shortlist slots; partial ranking counts distinct opcode
  four-grams so repeated stores and structure copies do not dominate. These are
  investigation leads, never evidence for automatic names or matching status.
- Never delete `build/` or `.fzgx/`. `.claude/settings.json` denies `rm -r`,
  `git clean/checkout/restore/reset/stash/rebase/push` and `ninja -t clean`
  for every agent in this repo. If the build looks broken, run
  `python3 configure.py && ninja build/GFZE01/ok` and report; do not "clean".
- `fzgx submit` accepts matching functions; `fzgx data-import --apply` accepts independent
  data after compiling its definitions, checking layout/relocations, and verifying all 16 hashes.
  `fzgx data-import --inventory --module MODULE` lists unowned data and existing declarations.
  `--recipes state/dataimports/recipes.json` supplies measured text layouts;
  `--regenerate --recipes state/dataimports/recipes.json --apply` reproduces the saved imports.
  See `docs/DATA_IMPORT.md`. Data units are marked `data: true` and have no function claims.
  The batch verifier drains
  completed matches every 60 seconds (`--verify-interval`) and checks every hash before
  committing. Its normal path runs one incremental Ninja build; baseline restoration and
  bisection run only after a failure. Literal-pool constants: retail pooled
  literals per TU (e.g. the 2^52 int-to-double constant), so a per-function unit's private
  `@N` literal never matches the relocation. When the only diffs are such relocations with
  equal bytes, `check` retargets the private symbols to the retail ones in the object
  (`tools/fzgx/poolfix.py`), the unit records the mapping (`pool` in units.json) and ninja
  applies it after every compile (`mwcc_pool` rule from `configure.py`), so the function
  matches and links from C. If the private rodata cannot be emptied the function is a
  *pool match*: accepted and spliced, retail object still linked (`link_state=pool`).
  REL pool reads must use the relocation target's section: offsets overlap across
  `.text`, `.rodata` and `.data`. DOL strings use address-based segment lookup.
  Shared BSS copies use the same binding path after symbol, size and zero-section
  checks; preserve definitions when their range already belongs to the function's
  unit. Compiler-generated `$N` names are ELF bindings, not valid MWCC C identifiers.
  `fzgx fixup` re-checks every saved body after oracle/header changes (and searches the rest).
- Matchers edit only their own unit, and only through `write_unit`. Headers,
  names and splits belong to the librarian.
- No hardcoded addresses (`fzgx lint`), no inline asm in `src/`.
- Symbols are addressed by name; the REL entry points `_prolog`/`_epilog`
  exist in every module and must be written `module:name` (e.g. `title:_epilog`).
- Nothing is carved before it matches. A function gets a split range and a unit (an object
  in the link) at `submit`; until then `check` diffs the agent's work copy against the retail
  auto object that contains the function (symbol-only, two-object objdiff). Reason: units
  are objects in the link and split ranges in the config; 900 stub units of the DOL made a
  link run for 20 min. Keep units at matched count regardless. mwld also never returns (found
  by bisection, 2026-09-09) when a dtk split object carrying its CodeWarrior `.comment` section
  starts with a size-0 label followed by a function at the same offset: dtk emits symbols in
  symbols.txt line order, so `carve.order_labels_after_functions` keeps every function line
  before a same-address label (10 such pairs, all in the DOL). If a link hangs, bisect the
  units with a capped mwld run, never wait on it.
- Assembly-only functions (privileged instructions, no `blr`, shapes MWCC never emits) are
  `fzgx asm-unit` units: `asm: true` in units.json, the split's `.s` copied to `src/`, GNU as
  builds it, ledger status `asm`. GNU as reads branch hints `+`/`-` relative to the branch
  direction while dtk prints the raw hint bit, so `asmunit.fix_branch_hints` respells hinted
  backward branches on copy. 107 landed on 2026-09-09; the ledger has no `blocked` rows left.
- Hardware register blocks: retail addresses them through linker-defined absolute symbols
  (`lis/addi` of `__DIRegs`, `__VIRegs`, `__SIRegs`... resolved by the link, never a folded
  literal). `config/GFZE01/ldscript.tpl` (dtk `ldscript_template`) defines them; C includes `dolphin/types.h` for `vu32` and declares
  `extern vu32 __DIRegs[];`. The object oracle cannot see the link, so `oracle._abs_rows`
  accepts a relocation against a template symbol wherever retail carries the resolved literal
  (`fzgx verify`'s hash is the guard). The lifter emits this form (`HW_BLOCKS`), the fixup
  renames invented names (`lbl_CC006000`) to the canonical symbol by address. Pooled literals
  in the DOL need `Project.bytes_at` to find the segment by address (it was broken for every
  DOL section until 2026-09-09: no DOL pool match could land).
  `fzgx uncarve --stubs` removes any unit without matched code (verify uncarves what it rejects).
  Symbol promotion must rewrite C `global.member` bases too; a following dot only
  extends a symbol name in assembly, not in C. Preserve separate token boundaries.
- Plateaus are data, not agent work. `fzgx stuck` classifies every saved best body at 80%+ by
  failure mode from the object diff (`.fzgx/stuck.json`, rows included). `fzgx fixup`
  is the sole deterministic repair command. All saved variants, source rewrites,
  byte-derived fixes, allocator evidence and compiler-response combinations share
  one engine, content-addressed compile cache and verification path. Session release
  and lifter repair call that same engine. `--apply` submits exact results and
  verifies all 16 hashes; without it, output remains in the repair corpus.
  `--clones` pools saved C across exact retail instruction families, repairs one
  representative and rechecks its copies. It preserves owned declaration closures,
  source pragmas and compiler settings; differing compiler responses keep independent
  search. `reuse` calls this same engine. Clone runs also save portable partial C
  and replay recipes in `sources.json.gz` for subsequent passes.
  `--capture --corpus PATH --output PATH` captures allocator/PCode evidence;
  `--captures PATH` consumes it. Do not add standalone repair/search runners.
  A unit may carry its own `mw_version`/`extra_cflags` (an `-O` override replaces the module's);
  `check`/`submit` honour them before the carve. The decomp-permuter was dropped: over the whole
  project it closed one function and cost minutes per try.
  Saved-candidate repairs must retain the recorded compiler version and flags through every
  rewrite. `fzgx stuck --seeds PATH` accepts a manifest of saved bodies with those settings.
  Fixup also probes function-scoped optimizer pragmas before source rewrites. A masked-word
  score of 100% is only a shortlist: keep trying candidates until relocation bindings and
  data pass the full oracle. The first code-only match must not stop the search.
  Include `opt_dead_assignments off/reset`: it reproduces the per-function effect
  of `-opt nodeadstore` without leaking optimizer state to a later TU merge.
  Recover floating literals from retail relocation bytes, trying repeated equal
  occurrences together as well as individually. Keep the original C as a register
  search seed alongside a locally improved rewrite, within the same repair budget;
  a better intermediate word score can remove the exact declaration-order solution.
  Shared-pool recovery follows symbolic bases through control-flow joins and reads
  ordinary load offsets as well as direct relocations. It proposes exact literal
  values and sparse external pool layouts, including uses in macros. No load
  immediate or mismatching data is patched in the object. Objdiff JSON addresses
  are decimal strings; parsing them as hex corrupts repair row accounting.
- `fzgx trivial` matches single-`blr` and `li r3,N; blr` functions mechanically (419 landed on
  2026-09-08) and then lifts straight-line functions from the disassembly (`tools/fzgx/lift.py`:
  getters, setters, one-call wrappers, short call-free bodies; 102 landed the same day). Run it
  before spending agents on small functions.
- `fzgx lift --tu rel/main_rel/accessory.c` lifts one whole TU without a size cap, saves drafts
  under `.fzgx/lift/`, and submits exact matches after the deterministic fixup. `--no-submit`
  keeps the results local. Signatures come from owned headers and matched C, with register-flow
  constraints scoped to the TU and its callees; context labels inferred signatures. A matched
  wrapper can still have missing passthrough parameters: follow its callees' entry registers
  (the `memset`/`fn_80008BEC` size argument was one such case). Drafts containing `???` remain
  incomplete and cannot be submitted by this pass.
- Prefer deterministic repairs, and carry recurring manual fixes back into the existing engine.
  Manual reconstruction and tuning are also authorized. Submit only oracle-verified C and
  check all 16 hashes. Use existing retail functions as the repair corpus; do not add unit tests.
  `fzgx lift --callee fn_1_4F734 --callee fn_1_4AE0C` selects the union of direct callers
  across TUs; `--no-submit` retains drafts without carving. Header layouts constrain copied
  stack objects. Integer-to-float recovery tracks both scratch-word stores in either order
  and keeps the encoding internal until its bias subtraction.
- `fzgx lift --all --engine m2c` runs the pinned PowerPC/CodeWarrior backend across every
  unmatched function; `--tu` and `--callee` also support this backend. It consumes owned
  declarations and recovered stack aggregates, lowers byte-addressed accesses to C, and
  rejects unresolved operations rather than including m2c's placeholder macros. Intermediate
  assembly, contexts and drafts live under `.fzgx/machine/`; generated candidates still go
  through the object oracle, `submit`, and all 16 hashes. No reconstructed C is edited by hand.
  Signature recovery follows callable assembly labels without changing their ownership.
  MWCC `_savegpr`/`_restgpr` and FPR frame helpers preserve arguments and return registers;
  never model them as ordinary calls. Self-xor/subtract zeroing idioms have no input.
  Fixup variants of the same symbol run serially because their scratch files are shared;
  different symbols may run in parallel. Keep the best saved draft when trying another backend.
  Backend generation uses isolated worker processes because its IR adapters mutate class methods.
  `fzgx lift --all --engine m2c --resume` reuses saved candidates and retries generation and
  compilation failures; omit `--resume` when changing lowering for already compilable functions.
  Compiler diagnostics and generation/scoring checkpoints stay under `.fzgx/lift/m2c/`.
  Signature flow also covers unmapped DOL functions and switch destinations. A matched `void`
  wrapper can omit a live return register; use caller consumption and callee register flow to
  recover it. Varargs save areas are not fixed arguments, and CR1 controls floating varargs.
  `machine.py` transports retail jump tables, shared stack-copy extents, packed byte/word
  locals, and 64-bit call arguments. `ppc_lowering.py` carries XER_CA through arithmetic and
  recovers consumed condition-register bits. Paired-single data stores must never disappear
  as backend no-ops; only recognized FPR frame saves may be elided.
  The default lifter uses MWCC's `__vec2x32float__` for paired arithmetic and
  unquantized loads/stores. It keeps scalar and paired FPR lifetimes distinct;
  unknown upper lanes and GQR formats remain explicit gaps. Native vector C can
  emit indexed loads and merge/multiply pairs where retail uses displacement
  loads and `ps_muls0`/`ps_madds0`; a compilable draft is not an object match.
  Keep reused int-to-float bias registers alive and follow XER_CA across
  intervening non-carry instructions in signed power-of-two division.
  Declaration normalization must parse lines without nested repetition over arbitrary C;
  the old regex stalled real drafts such as `fn_80005738` beyond repair time budgets.
  Register-only instruction differences are not proof of equivalent value flow.
  The oracle reports known non-stack store-value conflicts; fix those values before
  spending allocation searches. Compiler-response composition and source repairs
  now run together in `fzgx fixup`; see `docs/REGISTER_REPAIR.md` for measurements.
  Read disassembly only from the active `build/GFZE01/config.json` split units. Orphaned
  named `.s` files can retain obsolete local names after promotion and shadow current auto
  units, yielding an object match that fails the link (`SelectThread_800105D0` was one).
- The font/sprite UI interface has many large callers, but that dependency count is not
  evidence of a collapsible matching bucket: the corrected 318-function UI lift closed zero.
  `include/font.h` records the variadic text wrapper and 0x58-byte packet submission result;
  do not infer sixteen fixed parameters from a varargs register-save prologue.
- Prioritize deterministic SDK C imports (CARD, then OS, EXI, SI) regardless of size.
  Include REL middleware: the reconstructed Sofdec sources in the CC0 MK Deception decomp
  yielded 60,888 bytes from 24 functions (including one complete `mpvabdec.c` TU).
  Owned sources, headers and provenance are under `src/rel/movie_module/`, `include/sofdec/`
  and `state/sdkimports/sofdec.json`. GX and later Sofdec player layouts differ; only the
  recovered fields in `mwsfd.h` are named. Compare code bytes when tracking the 30% target.
  SDK imports must retain active compiler pragmas and distinguish function-pointer objects
  from prototypes. After a pool-backed submit re-splits retail objects, invalidate the
  in-memory object index before checking the next function (`api._reconfigure_and_split`).
  Code relocation masks apply to the containing instruction: MWCC's halfword SDA21 offsets
  and DTK's word offsets denote the same field. Use `poolfix.masked_code` for SDK signatures
  and candidate scoring, and normalized offsets for symbol binding. Never mask four bytes
  starting at a halfword relocation; that erases part of the following instruction.
  The corrected scan exposed 202 unmatched signatures / 76,612 bytes at >=64 bytes.
  SDK declaration closure includes enum members and local statics; symbol replacement must
  preserve struct members and parameter scope. Reject inline assembly in dependencies too.
  `sdkimport --library` also supports AR, VI, DVD, GX, DSP, PAD, AI and runtime libraries;
  generated sources use owned declarations, never build/tools headers.
  Refresh compiled SDK objects when the compiler or flags change; source mtime alone is
  insufficient. Imported callback names must follow local-to-global promotion. A C function
  can also own a retail entry label: `carve.retain_entry_labels` keeps that name as a symbolic
  linker alias. Link failures are retained in `.fzgx/verify_last_failure.log`.
  Functions **under 256 bytes** (`--max-size 255`) are a repair corpus, not a prerequisite. `fzgx stuck --max-size 255` classifies the saved attempts; `fzgx fixup --max-size 255`
  searches them. `fzgx reuse --max-size 255` rebinds verified C when retail instruction
  shapes agree, retaining registers, immediates, relocation kinds/addends and branch targets;
  all candidates pass the oracle and `fzgx verify`. Do not launch Luna agents or
  swarms (see `AGENTS.md`); remaining work goes to the bound matcher fleet in
  `docs/FLEET.md`. Do not add unit tests: use real
  MWCC/object-diff checks, lint, and the 16-target hash check.
- Readability tooling: `fzgx tu-organize` (TU directories from `tus.json`), `fzgx headers`
  (layouts from disassembly → `include/rel/<module>/globals.h`, offset self-checked under MWCC;
  `--symbol` prints one layout, `--oversize` lists dtk under-sized symbols), `fzgx rename`,
  `fzgx naming-bundle`/`naming-apply`. TU passes: `fzgx tu-migrate` (once per module),
  `fzgx tu-check` (the whole file as one unit: the goal state) and `fzgx tu-finish` (include,
  tidy, hoist, reflag, collapse as internal stages; the orchestrator's finish round). Agent ids
  prefixed `revise-` rewrite a matched unit and keep it only if still 100%; `shadow-` run A/B
  trials without committing.
- Naming: `fzgx naming-bundle <tu.c>` (sources, header, retail strings, assert hints) →
  a cheap model answers JSON → `fzgx naming-apply --file p.json`, which renames symbols,
  records typedef names in `config/GFZE01/<module>/typedefs.json`, re-splits, regenerates
  every header of the module (offset self-check) and relinks. Headers are generated:
  never hand-edit `include/rel/<module>/*.h`; change the analyzer or the name map.
- The split runs `dtk dol split --no-update`: dtk never rewrites `symbols.txt`/`splits.txt` (its rewrite
  dropped attributes). A carved DOL function with no callers is marked `force_active` in symbols.txt
  (alone in its object mwld dead-strips it and every hash after it fails); carve does this.
- Header changes can alter a matched unit's code. `ninja build/GFZE01/ok` must pass after
  regenerating; if a REL fails, byte-diff `build/GFZE01/<m>/<m>.rel` against `orig/` and
  map the first divergence to a function.
- `tools/seeds/asserts.py` → `state/seeds/asserts_<module>.json` (file:line + message per
  assert call); `tools/seeds/debug_strings.py --write` refreshes `tus.json` from `__FILE__`
  anchors (then `fzgx tu-organize` and regenerate headers).
- Batches: the fleet daemon owns batch launches (`tools/fleet_multi.py`, started as
  `tools/fleet.py daemon`, which delegates to it). To run one by hand:
  `uv run tools/fzgx.py` for the manual CLI, or
  `uv run tools/orchestrate.py --harness <claude|codex|cline|agy|opencode> ...`
  (headless, one report per batch, periodic live verification and a final drain).
  Harnesses and pinned models are listed in `docs/FLEET.md`; never edit personal
  auth or config, and never use in-process subagents.
- DeepSeek trials use the same Codex harness: `--provider deepseek --model deepseek-flash`
  selects DeepSeek-V4.1-Flash. Supply `DEEPSEEK_API_KEY` or `--api-key-file PATH`;
  keys stay outside the repository and out of command arguments. The provider and
  `tools/codex_models.json` are selected with run-local overrides; normal Codex config
  is untouched. Never set `forced_login_method="api"` for these runs: Codex 0.153.4
  deletes the shared ChatGPT login when enforcing it. `env_key` authenticates the
  custom provider without changing the OpenAI login. Keep all worker feature
  overrides inside `tools/orchestrate.py`; do not apply them through standalone
  Codex commands or write the user's personal Codex config/auth files.
  DeepSeek returns token usage,
  not dollar cost (confirmed with the live Responses API). Estimate each response
  at weekday UTC 01:00-04:00 / 06:00-10:00 peak rates, half otherwise; retain usage
  from failed turns too. Label estimates explicitly; use provider-reported dollar
  cost when available. Supported effort levels are `low`, `high`, and `max`.
  Load the four matcher dynamic tools directly (`supports_search_tool=false`): DeepSeek rejects
  duplicate MCP namespaces returned by parallel Codex tool searches. Shadow trials
  retain matched C and compiler options under `.fzgx/attempts/` for later integration;
  finishing or aborting them preserves the function's original matching status.
  App-server control commands use bounded concurrency with separate completion
  slots. Retry only explicit JSON-RPC -32001 overload rejections, never ambiguous
  timeouts. Codex 0.153.4 requires each inherited MCP server to be disabled in
  thread-local config; the global orchestrator MCP switch does not suppress
  their initialization. Disable worker hooks through runner overrides too.
  Completed items retain reasoning/text; do not persist every token delta at scale.
  Record compact stream progress every 30 seconds of activity and count retriable
  errors separately from final outcomes. Claim and initial check share one tool
  slot (`claim --check`), so a full-width startup does not enqueue all claims ahead
  of all preflights. Patch-anchor errors return current C under the ownership guard.
  The DeepSeek catalog must also set `apply_patch_tool_type=null`; disable the
  request-user-input tool in runner-local settings to leave exactly four tools.
  Compiler probes must persist their selected version for subsequent edits,
  submit, release repairs, and the next batch's saved-body selection. Context
  must display the actual seed compiler/flags. Similarity scores near 100% can
  still hide many register or scheduling differences; show remaining diff rows.
  Bind each headless worker to its assigned symbol and agent id. A successful
  submit/release ends that worker's attempt; reclaiming cannot reset its counters.
  Reject repeated shadow submits before checking or finishing: a finished trial no
  longer has the saved previous status and must not mark existing matched C unmatched.
  Direct checks and compiler-version probes must honor the same stop as source edits.
  Set catalog `multi_agent_version=null` as well as disabling `multi_agent` and
  `multi_agent_v2`: catalog v2 can enable delegation despite those feature flags. Nested agents
  otherwise share the claimed work copy and corrupt each other's checks. Enforce
  the assigned symbol and identity on every CLI tool call, serialize calls for that
  function, and pass the release caller's identity through to the ledger guard.
  Disable `goals` for matcher processes too: its unrelated `get_goal` call adds a
  model round trip before claiming the function.
  Provider/catalog reference: [DeepSeek's Codex integration](https://api-docs.deepseek.com/quick_start/agent_integrations/codex/).
  Example: `uv run tools/orchestrate.py --harness codex --provider deepseek
  --api-key-file ~/.config/fzgx/deepseek.key --seeds PATH --parallel 1 --no-trivial`.
- Whole-project seed batches use `uv run tools/seeds/small.py --max-size 0 --fresh-lift --output NEW_DIRECTORY`.
  Freeze a full-size deterministic lift for every unmatched function, compare the best saved C with its
  compiler settings through the unified fixup engine, and retain the best current word score
  (full oracle matches take precedence). No size, SDK or prior-attempt exclusions apply.
  The manifest retains fresh lifts alongside selected bodies. DeepSeek `--effort none` disables
  reasoning through the runner's DeepSeek transport, which removes the incompatible
  `x-codex-turn-metadata` header. Verify actual streamed items, not just thread settings;
  the runner stops a `none` batch if reasoning appears. Personal config is never edited.
- Fresh-function batches use `uv run tools/seeds/untouched.py --max-size 511 --output PATH`.
  It excludes prior matcher candidates/successful checks, known SDK signatures,
  prepared imports and ranked donor candidates, and freezes `lift_total` output
  with hashes. These are inferred drafts, including unresolved markers, not
  high-scoring repair seeds; workers complete the missing lowering before compiling.
  The selector rejects stale ledger symbols and fails if any selected function has
  no draft. Accepted C installs serially under `submit.lock`: different functions
  can share a TU, splits and symbol tables even when their work copies are isolated.
- Largest-function batches use `uv run tools/seeds/largest.py --count 50 --output NEW_DIRECTORY`.
  Select globally by unmatched retail byte size, without SDK or attempt exclusions.
  Size `lift_total`'s instruction allowance to each selected function and fail if any
  draft is missing. Include existing saved reconstructions as additional seed references.
  Context budgets apply to auxiliary examples/history; never truncate the target
  assembly or its referenced declarations, since matchers have no file reader.
- Recovered-candidate batches use `uv run tools/seeds/recovered.py --above 90 --output PATH`.
  This selects strict historical scores above the threshold without a size cap or SDK
  exclusion, joining attempt bodies, check archives, lifter drafts, owned SDK imports,
  repair results and sweep/spelling history. Donor fuzzy scores are not C match scores.
  Freeze the actual saved C, hashes, provenance and compiler settings; recheck it and
  try saved alternatives for regressed seeds. Keep historical eligibility separate
  from current scores in the manifest. Missing saved bodies fail preparation.
  Pass the resulting manifest to the orchestrator with `--seeds PATH --no-trivial`;
  `--provider deepseek --parallel 128 --effort low` requests the lowest supported
  reasoning effort through worker-local overrides.
- Retry a completed batch's still-unmatched releases with `uv run tools/seeds/released.py
  --batch BATCH --seeds ORIGINAL_MANIFEST --output NEW_DIRECTORY`. This freezes each
  release's saved C and compiler settings without a size or score cutoff. Older metadata
  is recovered only from identical checked C or an identical original seed. The runner
  performs the current compile as preflight. Use a new batch name and set `--parallel`
  to the manifest's function count for full-width concurrency.
- The orchestrator does three things: pick a pool, run the batch, run the TU-finish round
  (`--finish`, or `--finish-only --module M`). It reads reports. It does not edit blocks,
  headers or splits by hand, and does not experiment on the live tree (use `--shadow`).
- Agents only where the answer is not computable. The TU-finish pass (`fzgx tu-finish`,
  `tools/fzgx/reconcile.py`) is deterministic: it isolates colliding private typedefs by
  function prefix, tries each candidate declaration of every symbol (definition first, then
  the blocks' variants) and keeps the first under which every block naming the symbol still
  matches, marks the rest contested, and collapses complete TUs. Verdicts are memoised by
  generated-unit hash (`.fzgx/verify_cache.json`), so a pass over main.rel is ~30 s. The only
  agent task it emits is the fixed list of blocks that cannot compile under their prologue
  (one revise batch; a block that fails twice is blocked, never re-queued).
- Compiler versions (2026-09-13): 84 unmatched DOL functions (61 KB: the AX/MIX libraries,
  parts of OS/DVD/CARD, GXInit) carry the MWCC 1.0/1.1 prologue order (`mflr; lis; stw r0, 4(r1);
  stwu`), which 1.2.5 and later never emit. `oracle.CANDIDATE_VERSIONS` and the sourcealign
  donor profiles now include GC/1.1; ten of those bodies gained 6 to 43 points under it. MWCC 1.1
  also reserves frame space for a declared local that later optimization removes (later versions
  do not): a frame 8 bytes short of retail's means a missing local declaration.
- Allocation rules measured with probe compiles (2026-09-12): callee-saved registers go to
  variables in textual declaration order, highest register first, after the compiler's own
  hoisted temporaries; block scope does not matter. An inlined static helper's locals share one
  assignment across every inline site. Liveness is path-sensitive (a register dead on an
  early-return path is reused there). An address-of-object CSE temp (retail `addi r4, r31, off`
  reused for interior stores) is reproduced by direct member access, not by a pointer variable.
  Int-to-float conversions get one 8-byte stack temp per source site; sibling branches share a
  slot; conversions separated by calls reuse one slot; a macro that evaluates its argument twice
  creates two sites (fn_3_1D338's clamp). FPR temps are numbered by IR creation order, which
  follows source expression order.
- Rules measured 2026-09-13 (probe compiles, see fn_12_2D888, fn_1_327F8, fn_80025A24, fn_8006A768):
  under 1.2.5n/1.3.2 the callee-saved order follows the order in which variables are first
  *defined*, not declared (`s32 c; s32 b; s32 a; a = ..; b = ..; c = ..` gives a r31). A constant
  address assigned to a plain pointer (`char *s = table;`) is a rematerializable temp that takes
  the lowest register; wrapping it in a one-member struct local (the lifter's `struct { T *value; }`)
  keeps it a variable. A `u8` field read with an `(s8)` cast loads `lbz rT; extsb rD, rT`; a field
  declared `s8` loads `lbz r3; extsb r3, r3` straight into the argument register; a u32 parameter
  fed from an `s8` field needs `(u8)` to stay a bare lbz. `*q++ = v` keeps real pointer increments
  (`addi r4, r4, 4`, merged pairwise) where `q[k]; q += 2` folds into displacements (MWCC 1.1).
  An integer sum used as an address (`*(int *)(offset + entry + 0x9a0)` with `entry` a u32) emits
  `addi r0, entry, 0x9a0; stwx v, offset, r0`; any pointer-typed spelling folds the constant onto
  the offset instead. Three identical fill loops must reuse one counter for the stored zero to be
  copied from the counter (`addi r3, r4, 0`) in every loop. Under GC/1.1 declaration and
  assignment order never change callee-saved assignment; the order follows interference
  structure (a table pointer read once or four-plus times takes r31, two or three reads put it
  below the other pointers), so 1.1 near-misses with swapped r30/r31 are not fixable by reordering.
  The `-use_lmw_stmw on` response closes stmw/lmw prologue rows in DOL and movie_module functions
  and must be tried together with GC/1.3.2 before any source rewrite (fn_8004D8DC 98.2 -> 99.95).
- MWCC register allocator, from the recovered 1.2.5 backend (/Users/rayan/mwcc: Coloring.c,
  SpillCode.c, Registers.c, CodeGen.c) and confirmed by probes on 1.2.5n/1.3.2: every register
  candidate gets a virtual-register number before lowering (`CodeGen_PreallocateObjectRegisters`):
  parameters first (a later parameter numbers higher), then locals with the FIRST declared local
  numbered HIGHEST (inner-scope locals below outer ones), then a second pass that numbers CSE
  recompute and induction "shadow" objects above every local, then lowering temporaries as they
  are created (highest). Coalescing merges a copy into the lower-numbered web and only inside the
  post-local window, so a `local = temp` copy of a pass-1 local cannot coalesce (the `addi r0; mr`
  shape). Interference is exact per-instruction liveness; simplify pushes nodes of degree below
  the free-register count in ascending number, then the rest by lowest spill cost/degree (cost =
  2 per use + 1 per definition, weighted by block execution weight); colors are assigned in the
  reverse order (highest number first), each taking the lowest color in {free r0,r3-r12} plus the
  already claimed callee-saved registers that no colored neighbour holds, else claiming r31, r30,
  ... downward. Consequences: temps take r0 before r3, r4; a value dead before another's definition
  shares its register (a parameter copy reusing r31 after the last-declared local); the callee-
  saved permutation of a near-miss is fixed by declaration order alone unless a value is a shadow
  object (repeated expression, strength-reduced pointer, constant address) on one side and a
  declared local on the other: de-CSE it into a local used at every site (fn_12_2D888's offset),
  hold it in a local (fn_1_DA6C's call result), or wrap a constant pointer in a struct.
  Frame homes (measured on mwcceppc): under 1.2.5n an unreferenced local array and a stored-only
  one-field carrier reserve their bytes (0x18 -> 0x28 / 0x20); a dead scalar does not; under 1.3.2
  nothing dead reserves anything, so a frame that is short by a whole number of words is a
  compiler-version question first and a missing declared home second. The engine's
  `rewrites()` now carries the measured levers as families: held call results (widened to s32),
  struct-wrapped constant pointers, de-CSE into a declared local, one-field scalar carriers,
  `(void) x;` dead uses, two-region variable splits declared last, signedness flips, float
  literal suffixes / f32 locals, and `fixup_evidence.frame_padding` sized from the two `stwu`
  rows. Diff-row census of the largest 70 bodies scoring 50-90%: 43% register allocation, 28%
  missing/extra instructions, 12% frame offsets, 9% immediates, 7% opcode substitutions; only
  2.5% shared-pool literal rows. The most frequent substitutions are addi/li/mr copy spellings,
  lwzx against add+lwz (address kept in a variable), cmpwi against cmplwi (signedness) and
  fsubs/lfs against fsub/lfd (double promotion). The compiler's own IR dumper is a `ret` stub in
  every shipped build (`#pragma dumpir` and the gate byte do nothing); exact virtual-register
  numbers need the recovery project's sandboxed capture, which this machine cannot run (no
- Exact captures (2026-09-13): `tools/capture/capture.sh SYMBOL BODY.c MODULE [GC/1.2.5n]` runs the
  compiler inside the `fzgx-capture` Lima VM (`tools/capture/fzgx-capture.yaml`: Debian arm64,
  qemu-user, gdb-multiarch; separate from the recovery project's `mwcc-build` VM, never touch
  that one) under a GDB stub with the recovery project's `allocator_snapshot.py`, writing every
  PCode stage, the coloring graph before/after selection, creation events and the stack-frame
  home list to `.fzgx/capture/SYMBOL/`. `vreg_map.py DIR 0001` prints vreg -> name/cluster/color;
  `replay/simplify_replay.py DIR 0001` reproduces the compiler's colors exactly (38/38 on
  fn_8003043C) and answers hypothesis questions. Only the 1.2.5/1.2.5n address set is known to
  the scripts; 1.3.2 needs its own addresses. First validated loop: fn_8003043C's residual was the
  reassigned `result` becoming a copy-region web (vr42) numbered above `base` (vr40), so it claimed
  r27 before base claimed r26; a second local declared right after `base` put it in the named
  region and matched. The `variable_splits` family now emits that shape.
  Further capture-validated laws (fn_8000CEBC, fn_8008EDF0, fn_80022028, all landed): a virgin
  named local defined from a compared global lowers as `lhz rT; cmplwi rT; mr rX, rT` (the copy
  cannot coalesce into a pass-1 web); `if ((x = G) <= k) { x = G; } else ...` lowers the load into
  x's web and keeps the non-inverted `bgt; b` pair (`condition_embedded_assignments`). Stack homes
  are laid out in reverse declaration order and a call result assigned to a local that is later
  copied (`t = f(); v0 = t;`) owns a home under 1.2.5n even when it never reaches memory
  otherwise; the capture's stack-frame-NNNN.json lists every home with its owner, so a `frame`
  residual is solved by reading that list and reordering declarations. A plain pointer local
  holding a constant address is rematerialized at every site (extra `lis/addi` rows); the
  one-member struct wrapper keeps one materialization when every site, including the flush
  call, goes through the wrapper. Under 1.2.5n the compiler reloads a global after a volatile
  store unless the value sits in a local, and a dead first definition of that local is removed
  before numbering (a double definition cannot promote it).
  Capture verdicts over the 23 remaining 1.2.5-class near-misses (`tools/capture/autotarget.py`
  maps residual rows to webs, `source_rank_solver.py` decides): the replay reproduced every
  capture; 9 residuals are proven unreachable by declaration order (compiler temporaries or
  copy-region webs, which need the structural families), 8 unresolved by bounded search, none
  closable by declaration order alone. Porting captures to GC/1.3.2: the 1.3.2 build is not
  byte-similar to 1.2.5n even with address-masked patterns; anchors found from the dump strings
  are the register-coloring call `call 0x5077b0` at 0x433dc6, the dump gate byte 0x5e90ec, the
  post-coloring reconvergence 0x433df2, the scheduler call 0x500020 and the optimizer call
  0x506e10, but 0x5077b0 has a different shape (five calls) from the 1.2.5 coordinator, so every
  PCode/graph global and the operand layout must be re-derived before `allocator_snapshot.py`
  can read a 1.3.2 process.
  Derived so far for GC/1.3.2 (capstone over the shipped binary, 2026-09-13): the coordinator
  0x5077b0 loops over five register classes (class byte 0x5e931f, per-class virtual-register
  counts at 0x5e8a7c + 4*class, available counts at 0x5e8778 + 4*class, coloring count word
  0x5df940); per class it calls SpillCode_BuildInterference 0x579cf0, SetupClass 0x507d40,
  SimplifyGraph 0x507b50, SelectColors 0x507a30 (with 0x57abd0 the spill retry), Commit
  0x507900, FreeIteration 0x440b10; gPCodeBlocks 0x5e87b0 (block->instructions at +0x18,
  instruction operand_count at +0x22, operands at +0x24, 12-byte operands with kind at +0, class
  at +1, register at +2, the 1.2.5 layout), gInterferenceGraph 0x5e87d0, gInterferenceBits
  0x5e21cc, gCoalescedRegisters 0x5e21c8; the opcode descriptor table starts at 0x5bee78 with
  0x12-byte entries (mnemonic pointer first; 1.2.5 used 0x10). Still needed for a 1.3.2 capture:
  the CodeGen_Generator stage points (register-coloring reconvergence 0x433df2 is known), the
  initial-object and coalesce-window words, and the reaching-definition table.
  Also derived: the coalesce window is per class in 1.3.2, `gCoalesceFirst[class]` at
  0x5e7fc8 + 4*class and `gCoalesceLast[class]` at 0x5e86a8 + 4*class (BeginCoalesceWindow analog
  at 0x4fd570, Update/Close analogs at 0x4fd4b0 and 0x4fd520, the object allocators increment
  0x5e8a7c[class] at 0x4fd6a8 and 0x57b03e/0x57b1a6), so the essential reader constants for a
  coloring-only 1.3.2 capture (blocks, graph, coalesced roots, counts, coalesce ranges, opcode
  table, SelectColors/AllocateRegisters breakpoints) are all known; only the initial-object-last
  words (stratum labels) and the CodeGen stage points other than register coloring remain. The
  port itself is a version-keyed copy of the recovery project's `allocator_snapshot.py` reader and
  GDB driver under `tools/capture/` with these addresses and the 0x12-byte descriptor stride.
  DONE (2026-09-13): `tools/capture/capture132.sh SYMBOL BODY.c MODULE` captures GC/1.3.2 through
  `tools/capture/mwcc132_snapshot.py` (a Reader132 override of the recovery reader: GPR is class
  index 4, counts at 0x5e8a7c+4*class, instruction opcode at +0x20 / operand count +0x22 /
  operands +0x24 with kind +0, class +1, flags +2, register +4, object +8; interference node
  vreg +0x10, degree +0x12, physical +0x14, flags +0x16, count +0x18, neighbours +0x1a; final
  code point 0x433fc8). The 1.2.5 replay model reproduces the 1.3.2 compiler exactly (fn_1_ECC:
  143/143 simplify rows, 175/175 colors), so every allocation law above holds for 1.3.2 too.
  `autotarget.py` aligns the object rows with the final PCode 1:1 (237/237) and feeds the solver.
- Engine speed (2026-09-12): `fzgx fixup` startup read 182,000 saved bodies and 700 MB of
  reports on every run (55 s); `seeds/recovered.py` now caches the collected candidates in
  `.fzgx/saved_candidates.pickle` keyed by a cheap fingerprint (check-archive directory mtimes,
  attempts, stores), memoizes each fixup report by mtime, and reads bodies lazily
  (`LazyRecord`); `load_records` selects the functions before touching bodies. In the search,
  candidate compiles of every (module, compiler, flags) group share one 16-wide pool of 48-file
  chunks (a serial process per tiny group cost 117 ms each; one slow file no longer stalls a
  sixteenth of the round), checks are memoized per compiler response, `Project.unit_of` is a
  bisect index, and candidate generation runs in forked workers. Twelve functions: 114 s -> 27 s.
  Remaining per-round cost is mwcc itself (~5 ms per candidate, 16 wide) and the objdiff checks.
- Build speed: units compile in groups of 48 per mwcc process (`tools/mwcc_batch.sh`, one depfile
  per group, `mwcc_batch` rule); a full rebuild is ~8 s, of which ~5 s is the two-stage main_rel
  link. `build.ninja` names the interpreter `python3` on purpose: a baked-in path changed with every
  caller (uv venv vs homebrew) and rebuilt every unit. Candidate loops (fixup, spell, lifter)
  score by masked machine words (`oracle.words`/`word_score`), objdiff only on winners; batch passes
  compile through `oracle.compile_many`/`check_many` (parallel chunks), never one process per body.
- While a batch runs, never call `configure.py`, `ninja` or `dtk` by hand: go through
  `fzgx verify` or `oracle.build_lock()`. Two concurrent splits kill each other (exit 137)
  and a broken baseline makes a bisect blame every pending unit. Verification holds
  submit.lock then the build lock; after a failed incremental build it establishes a
  known-good baseline before bisection. Never wrap verify in another submit.lock.

- Shared literal pools (2026-09-12): 819 unmatched functions (1.15 MB, over half the remaining
  bytes) address their float constants through one base register into the TU's literal pool,
  which MWCC lays out in first-use order across the whole TU (dedupe is per compile unit, so
  dtk's rodata blocks carry repeats). A per-function unit never reproduces those offsets, so
  `fixup_evidence.shared_pool_primer` primes the unit's pool: dummy functions in `.fzgxpool` (a
  section mwld ignores) reference every pooled literal in retail address order, raw table
  bytes and repeats become private `static const` words, and the function's own literals and
  MWCC's conversion constants dedupe onto retail's offsets. The oracle binds the anonymous
  `...rodata.N` pool to the retail symbol (`oracle._pool_rows`), `poolfix.apply` drops the
  primer section and the private pool at integration, the extras rule ignores `.fzgxpool`.
  Pool element types come from every function of the module that addresses the pool
  (`_pool_widths`). It needs the body in native-literal form (`recover native shared-pool
  literals` runs first). 14 landed the day it was built.
- Retail TU section layout (2026-09-12): the near-miss shapes `addi rX, rBase, off` kept as a
  pointer (even `addi r3, r31, 0x0`), `stb r0, 0x5c49(rBase)` and string arguments as
  `addi r4, rBase, 0x8` come from MWCC addressing every object a TU defines in a section off one
  base register: an object's address is materialized whenever a pointer value is needed and only
  its offset 0 is addressed base-relative. A unit that declares the cluster as one extern struct
  can never produce it, and no cast, pragma, inline helper or late-constant offset changes that.
  `fixup_layout.tu_section_layout` defines the retail objects in the unit in retail order under
  MWCC's file-scope rules (scalars at natural alignment, arrays 4-aligned, `.bss` objects emitted
  in first-access order, string literals in first-use order; a primer in `.fzgxpool` with real
  loads/calls fixes the order, stores to a volatile local are dropped). Layouts come from an MWCC
  probe compile of the body's declarations. The oracle binds `...bss.N`/`...data.N` to the retail
  symbols (a base may be smaller than dtk's symbol; names a module header declares with another
  layout are defined as `fzgx_obj_<name>`). A single referenced object is addressed by name, so
  when retail hoists a base the dtk symbol hides several objects: the split-per-field variant.
  MWCC gives a named global r31 before an anonymous section base; that order is not reachable from
  C. Per-block definitions still collide at `tu-check`; the TU pass must hoist them once.
- Paired-single vector kernels (2026-09-15): retail's `psq_l/psq_st` displacement forms come
  only from inline-assembly helpers; `include/psvec.h` carries the validated set, the lifter
  substitutes recognised kernels (`psvec.kernels`) and `fixup` rewrites statement triples
  (`paired_vector_kernels`). Fusion law and line attribution: see `docs/MWCC_IDIOMS.md`
  ("Root causes measured over the whole stuck corpus"). `-sym on` compiles are byte-identical
  and give the `.line` table (`tools/fzgx/linemap.py`) that the engine uses to order and target
  candidates by implicated statement.
- TU truth (2026-09-16): no TU had ever compiled as one unit; matched blocks were accepted under
  whatever declarations made them match, so every large TU carried dozens of contested symbols
  (font.c: 82). `fzgx tutruth rel/<module>/<tu>.c` resolves one truth per symbol deterministically:
  a header declaration outranks everything; else the matched definition, else the old prologue,
  else the most common block spelling. Blocks follow the truth mechanically (call-site casts,
  register-class argument permutation, dropped redundant leading arguments, result casts,
  data views, non-prototype `extern T f();` and a K&R definition when callers pass fewer arguments
  than the `lab_unused` parameters), every rewritten block is re-verified through the oracle on
  scratch sources (no cache), and a block that cannot follow stays self-contained and is reported.
  Callers carry evidence the callee's code cannot: parameter order across register classes
  (fn_80071ED4: retail loads the s32 before the floats) and int/pointer return types
  (fn_1_548AC returns `void *`). MWCC's scheduler builds memory dependences per declared
  object, so a view `(*(T *)&sym)` over a smaller declared object schedules differently: the
  symbol's real size must reach the header (dtk under-sizes `lbl_1_bss_4C678`: the 8 objects
  4C678..4E6D0 are one 0x2050-byte cluster). `structs.py` now counts update-form stores (stwu).
  font.c: 169/170 blocks under one prologue; the whole TU (plus 34 unmatched best bodies and the
  pool primer) compiles as one unit and 163/211 functions match at TU level under `-inline on`.
  **`-inline auto` is wrong at TU scope**: MWCC auto-inlined five same-TU callees that retail
  calls; per-function units could never expose this. Collapsed TUs need `-inline on`.
- Fast repair path (2026-09-16): `fzgx sweep --min-percent N [--max-percent M] --rounds 4 --land`
  runs every cheap family (evidence, source, declaration moves, section layout, line-attributed
  flips/inlines) over every saved body in the range with one `compile_many` per module per round,
  word scores for ranking and objdiff only on winners: 686 bodies at 90%+ took 17 minutes for four
  rounds (5 matches, 167 improved); the pool pipeline over 405 private-literal bodies took 97 s
  (5 matches, 258 improved). Use it before `fzgx fixup`; the engine's per-seed rounds are two
  orders of magnitude slower on the same corpus. `--land` submits exact and pool matches through
  `api.submit` and saves improvements as attempts (`api.claim --max-attempts 999` / `release`);
  `fzgx verify` then links and commits. Census tooling: `.fzgx/fullrows.pickle` (full retail/ours
  rows for every stuck body, 100 s to rebuild with `oracle.check_many`) answers group questions
  (frame decomposition, parameter registers, first structural divergence) without re-running checks.
- Laws measured 2026-09-16 (see docs/MWCC_IDIOMS.md "Laws to apply first"): a parameter that retail
  keeps in a callee-saved register above a declared local is a local copy of the parameter declared
  at that position (`fixup_evidence.parameter_copies`, capture-verified, fn_1_A358C landed); the
  first callee-saved claims go to the webs whose interference degree survives simplification
  (>= K=29), only then in descending vreg order (`simplify_replay.py DIR 0001 32:+6` measures the
  missing degree); the lifter's byte-addressed pool reads `*(f32 *)((u8 *)pool + off)` are pool
  reads (native literals + primer, each read integer word its own one-element table object); a
  constant stored into an `s8`/`char` array element folds to the element's signedness (`li r0, -1`),
  retail's `li r0, 0xff` is a store through a `u8` lvalue (fn_1_8E3A4). A pool match
  (`matched_pool`) is accepted by `api.submit` but reported unmatched by `api.check`.
- Near-miss fixup must preserve a proven store-value correction in its search
  frontier even when register differences initially lower its word score. Value-flow
  diagnostics invalidate unsupported regions locally; mixed diffs must not disable
  them for the entire function. Operand swaps that compile identically can become
  effective under a different optimizer policy, so probe those combinations explicitly.
  Extra helper definitions block integration in both DOL and REL units. Separate
  inlined uses from calls to an already-owned helper when both appear in retail.
  Interior references use generated `OWNER__fzgx_offset_HEX` declarations and the
  existing pool-binding path: prove module, section, owner bounds, relocation type
  and resolved target, then adjust only relocation addends. Never patch instructions.
  Fixed hardware literals belong in `include/dolphin/hw_regs.h`, not matcher C.
  Repair provenance must be acyclic; rechecking an identical content-addressed
  candidate must not create a parent reference to itself.

- Matcher sessions have a sixth bound tool, `search` (`fzgx search SYMBOL --agent ID`): the fixup engine at
  12 rounds x beam 6 on the claimed work copy. The same deep search runs at release for bodies at 80%+ and before
  a bound retry (`claim --repair`); `<body>.searched.json` records it. Check output marks section/pool layout rows
  `L` and counts the rows that are the matcher's own. See `docs/FLEET.md` ("Deterministic search in the loop").

## Layout

- `config/GFZE01/` — dtk config, per-module `symbols.txt`/`splits.txt`, `units.json` (generated units, read by `configure.py`).
- `src/rel/<module>/<tu>.c` — one file per recovered translation unit, functions in retail
  order as blocks between `/* fzgx:begin NAME */ … /* fzgx:end NAME */` markers (tooling-owned;
  never hand-edit the markers). Every block is compiled as its own generated unit
  (`build/GFZE01/gen/…`, one split range per function) so the link and the oracle stay per
  function; `fzgx tu-check rel/<module>/<tu>.c` compiles the whole file as one unit (the goal
  state). Agents edit private work copies under `.fzgx/work/`; `submit` splices a block in.
  `src/dol/` and modules without a TU map keep one file per function (`fzgx tu-migrate --module M`
  converts a module once `tus.json` exists).
- `include/` — shared headers (generated per module/TU; see readability tooling).
- `tools/fzgx/` — ledger, carve, oracle, context, lint; `tools/linecrypt.py`, `tools/avlz.py`, `tools/prepare_orig.py`.
- `.fzgx/reports/` — per-batch reports (local, not committed, like SPEC.md); `state/ledger.json` — committed ledger snapshot.
