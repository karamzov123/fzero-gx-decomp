# Explicit read-only repair probes for matched functions

## Tooling repair

`fixup.load_records()` previously admitted only unmatched functions (apart from
existing clone/read-only exceptions for other statuses). Consequently:

```
uv run tools/fzgx.py fixup fn_8004F55C \
  --body state/repairs/device-frontiers/fn_8004F55C.native.c \
  --output "$TMPDIR/fzgx-f55-baseline" --rounds 0 --budget 30
```

silently reported `functions: 0`, `compiled: 0`. The function is already matched,
but the explicit candidate is deliberately not its installed matching source:
it is a natural-C replacement being investigated for device removal.

Allow `matched` alongside `claimed` and `blocked` only in the existing
`read_only_body` branch: an explicit symbol and body, with `--apply` absent.
The corrected command reports `functions: 1`, `compiled: 1`, no exact match.
No apply, claim, release, ownership, compiler or source-integration behavior was
changed. Ordinary corpus scans retain their previous status filter. Clone and
pool-upgrade modes retain their separate pre-existing policies.

## Real-function verification

No unit tests were added. Verification used the actual ledger, stock MWCC,
retail objects and the shared deterministic engine.

1. Before the change, the command above loaded and compiled zero functions.
2. After the change, it loaded and compiled the real native candidate. The
   candidate remains non-matching; its three positional differing words are the
   one prologue-load movement documented in `sel-natural-accesses.md`.
3. An exact natural-C control also compiled successfully:

```
uv run tools/fzgx.py fixup fn_800463E4 --body src/dol/fn_800463E4.c \
  --output "$TMPDIR/fzgx-spsd-exact" --rounds 0 --budget 30
```

   It reported `functions: 1`, `compiled: 1`, `matches: ["fn_800463E4"]`.
   This is discovery only; no apply operation was requested.
4. Direct calls to the real `load_records()` with the actual matched
   `fn_8004F55C` record verified all three selection paths:

   - explicit read-only body: one record;
   - same explicit body with the apply flag set: zero records;
   - ordinary prepared corpus containing that matched record: zero records.

   The apply-path check stopped at record selection and never called integration.
5. Compared full ledger rows for `fn_8004F55C`, `fn_8006BCF8`, `fn_1_977BC` and
   `fn_1_145C6C` before/after the probes: unchanged, including ownership and status.
   SHA-256 checks of their canonical TUs and `config/GFZE01/units.json` likewise
   proved unchanged content.
6. Reconfigured and ran Ninja; independently verified every entry in
   `config/GFZE01/build.sha1`; lint reported `0 finding(s)`.

## Searches exercised through the repaired path

Each search used two rounds, beam three, at most 128 generated candidates per
frontier seed per round, a 45-second process-local budget, and no `--apply`.
The table includes the baseline compile. No source replacement was accepted.

| Target | Compiled candidate bodies | Native baseline positional word differences | Exact replacements |
| --- | ---: | ---: | ---: |
| `fn_8006BCF8` | 417 | 2 | 0 |
| `fn_1_145C6C` | 516 | 9 | 0 |
| `fn_1_977BC` | 499 | 37 | 0 |
| `fn_8004F55C` | 504 | 3 | 0 |
| Total | 1936 | — | 0 |

The engine emitted `improved: 0` in each search round. Stop this default search
cohort here rather than repeating it with larger blind budgets. Its proposal
families include optimizer-pragma variants: those were temporary compiler probes,
not approved natural-C replacements and not installed in any canonical source.
Any future exact candidate still needs source-policy review and the full oracle,
16-target hash and zero-lint gates before integration.

Do not confuse the engine's aligned edit-distance `word_errors` with the
positional masked-word count printed by `manualkit/fast.py`: the native ADX
frontier has engine distance two but three positional differences. This is not
an improvement from three to two.

Additional manual probes tried ordinary integer RNG locals instead of the
identity helper, removal-only subsets of the existing entry devices, meaningful
table/renderer helpers and native declaration orders. None closed a target.
All 29 installed compiler binaries were also measured against the native
`fn_8006BCF8`, `fn_8004EFA8` and `fn_8004F55C` candidates; their best positional
counts remained 2, 5 and 3 respectively. These measurements do not prove a
universal source-search minimum or identify CRI's original compiler.

No marked compiler-diff device was removed by this tooling commit. The two
functions assigned to another agent, `.claude/settings.json`, retail targets and
canonical compiler settings were not modified.
