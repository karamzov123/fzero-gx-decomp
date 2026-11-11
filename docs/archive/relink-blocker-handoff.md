# Handoff: the full relink cannot open its own input list

Written 2026-10-29 for the next person (or model) to pick this up. Everything here is
measured on this working tree; nothing is inferred where a number is given.

## 1. Symptom

`ninja build/GFZE01/ok` — the documented gate, and exactly what `oracle.relink()`
(`tools/fzgx/oracle.py:125`) runs — fails on a **clean checkout of the tracked files**:

```
FAILED: [code=1] build/GFZE01/main.elf
### mwldeppc.exe Importer Error:
#   Can't read library file 'fn_8004ED5C.o'.

FAILED: [code=1] build/GFZE01/main_rel/main_rel.preplf
### mwldeppc.exe Importer Error:
#   Can't read library file 'fn_1_39C60.o'.
```

`sha1sum -c config/GFZE01/build.sha1` still reports **16/16 OK**, because those files on
disk were linked before the break. The gate is green on stale artifacts while nothing can
be relinked. Any `submit`, `verify`, `asm-unit` or integrator run fails at this point, so
**no function of any quality can be landed** until this is fixed.

Reproduce in one command:

```
cd /home/armandofm/projects/fzgx && ninja build/GFZE01/ok
```

## 2. What has been ruled out (all measured)

| Hypothesis | Test | Result |
| --- | --- | --- |
| missing input files | every `.o` line in both `.rsp` files `test -f`'d | **0 missing** in both |
| corrupt/empty objects | `readelf -h/-S`; sizes; delete + let ninja rebuild | valid ELF32 PPC; rebuilt identically; still fails |
| the object itself is unreadable | `mwldeppc -r -o /tmp/t.o <that object>` | **links fine standalone** (only the expected `-fp` warning) |
| duplicate rsp entries | `sort \| uniq -d` on both `.rsp` | **0 duplicates** |
| file-descriptor limit | `ulimit -n` (soft 1048576), retry with 8192 | no change |
| stale build directory | delete the named objects, `ninja` recreates them | recreated at 22:55, failure unchanged |
| bad split/units record for the named symbols | inspected `units.json` + `splits.txt` | records are ordinary `matching` units |

## 3. The real signature: positional, and capacity-bound

The reported name is whatever sits at a cutoff, not a bad file:

* delete the failing line from `main.elf.rsp` → the error is the **next** entry
  (`fn_8004ED80.o`);
* drop the 26 full-TU-sized `game/` objects from `main_rel.preplf.rsp` → the error moves
  exactly 26 entries later (`fn_1_3F4B8.o`).

Splitting the same inputs over several response files changes the failure class:

```
@elf0.rsp @elf1.rsp            -> Linker Error: undefined: '__start'
@elf0.rsp @elf1.rsp @elf2.rsp  -> Can't read library file 'fn_8006CD40.o'
```

Two chunks get **past input reading** entirely (the linker then resolves symbols and only
complains about `__start`), while three *smaller* chunks fail again. So the wall is the
number of inputs one invocation will open, cumulative over the invocation — not one file,
not one chunk. Chunking the `@` list is therefore not a fix.

## 4. Why the input list is this large

The tree is configured as **one unit per function**, with `tu` metadata pointing each unit
at its translation-unit file:

| measurement | value |
| --- | --- |
| units in `config/GFZE01/units.json` | 7092 |
| units carrying a `tu` key | 3905 |
| units pointing at `rel/main_rel/game.c` | 143 (142 `matching`, 1 `nonmatching`) |
| `src/rel/main_rel/game.c` | exists, 941 KB |
| objects `main_rel.preplf` must open | 3293 |
| objects `main.elf` must open | 2207 |
| `game/` entries in the preplf, of which >100 KB | 143 / 27 |

A TU is represented by **one object per member function** rather than one object per TU.
`fzgx tu-organize` (`tools/fzgx/cli.py:736`) only moves units into TU directories; there
is no mode that collapses N units into one TU object.

## 5. Suggested direction

1. **Consolidate units into real TU objects.** 3905 units already carry `tu` naming their
   source file, so the mapping exists. The change is in how `units.json` records are
   emitted/consumed (`tufile.py`, `tools/fzgx/tufile.py`, and the `tu` handling in
   `configure.py`): one unit record per TU whose `symbols` list is every member, instead of
   one record per function. That takes the DOL link from 2207 inputs to the low hundreds.
2. **If consolidation is too large to land at once**, do one TU first (`game.c`, 143
   members → 1 object) and confirm the link moves further, then generalise. Note that 143
   fewer entries will *not* clear the wall on its own; it is a step, not the fix.
3. **Then re-run** `ninja build/GFZE01/ok` and `sha1sum -c config/GFZE01/build.sha1`. Only
   when a relink reproduces 16/16 does landing anything become meaningful again.

Hypotheses not yet tested, if consolidation is unattractive: an internal token/file table
inside `mwldeppc` or `wibo` (`build/tools/wibo`) with a fixed capacity; a response-file
parse buffer whose size differs from any byte offset observed (the cutoffs are at byte
46300 of 80185 and 27333 of 168408, i.e. not a round number); or a per-invocation open
counter inside wibo that is not the OS fd limit. Testing either means instrumenting wibo,
which is why consolidation was preferred.

## 6. Second bug: `asmunit` does not roll back cleanly

`tools/fzgx/asmunit.py::finalize` prints
`"the tree no longer hashes with these units; rolled back"` and uncarves, but it does not
restore everything it mutated. Measured after a failed batch:

* `config/GFZE01/splits.txt` — modified
* `config/GFZE01/main_rel/splits.txt` — modified
* `config/GFZE01/units.json` — modified
* `src/dol/fn_80059DD8.c` — **deleted** (the stub `carve` wrote, removed by `make()`)

Those four were restored by hand from `HEAD`. The fix is to snapshot those paths (plus any
removed stub) before `make()` mutates them and restore them on the failure path.
`tools/fzgx/asmunit.py` currently carries uncommitted owner edits, so it was left alone.

## 7. State of the ten functions this round was about

C is measured exhausted for all of them; 72 capture-seeded candidates were compiled and
**every one scored identically to its seed** (see `docs/findings/392`).

| symbol | module | rows | capture says | C route |
| --- | --- | ---: | --- | --- |
| `fn_80059DD8` | main | 14 | `buffer` r30→r28 vs temporary `@59` r28→r30 | **C-plausible**: remove the temporary |
| `fn_1_14E2DC` | main_rel | 25 | seven misplaced webs, **all `@` temporaries** in r23-r27 | **C-plausible**: change which temporaries the front end creates |
| `fn_1_12C110` | main_rel | 9 | one web `p_cur` r5→r4 | every lever inert |
| `fn_12_7870`, `fn_12_11204` | movie_module | 6 | `arg1`/`offset` r7→r4, `x` r4→r0 | every lever inert |
| `fn_1_2221C` | main_rel | 23 | `v19` f2→f3, `v18` f0→f2, `v22` r29→r25 | every lever inert |
| `fn_1_141C10` | main_rel | 6 | no named web misplaced | set-up order (finding 391) |
| `fn_80070AC0` | main | 4 | none | two scratch webs, 14 spellings flat |
| `fn_1_4B6D4`, `fn_1_4B788` | main_rel | 2 | none; `no-allocation-difference` | pre-RA `lis`-above-`stwu` schedule |

Do not re-run: declaration-order permutation, aggregate carriers, `(void)x;`/`x=x;`
probes, inline parameter barriers. All four are implemented and were measured inert on all
ten (`docs/findings/392`). The eight non-C-plausible ones are asm-fallback candidates once
the relink works.

## 8. Verification used for this handoff

```
ninja build/GFZE01/ok                       # fails: Can't read library file (two targets)
sha1sum -c config/GFZE01/build.sha1         # 16/16 OK (stale artifacts)
uv run tools/fzgx.py lint                   # 0 findings
```
