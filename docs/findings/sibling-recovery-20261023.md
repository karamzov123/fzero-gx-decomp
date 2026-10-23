# Sibling recovery, 2026-10-23

Three functions passed the stock MWCC object oracle and all sixteen linked
hashes, adding 5,664 bytes of compiled C:

| Function | Bytes | Local commit | Matched sibling |
| --- | ---: | --- | --- |
| `fn_1_943F8` | 3,312 | `ce7bf0496` | `fn_1_93734` |
| `fn_1_79E54` | 1,004 | `56603bb2d` | `fn_1_7A240` |
| `fn_1_11ED0C` | 1,348 | `5509fb5b1` | `fn_1_110008` |

The car-animation routine retains the sibling's measured native data objects,
uses a shared blend-flags local, and declares its first slot cursor after the
other cursors. The screen-effect routine needs a local copy of its scale
parameter and returns the selected entry's object. The eleven-column grid
adds two sets of diagonal links and initializes its row-sort counter and
cursor in the same `for` initializer.

`state/repairs/sibling_recovery_20261023.json.gz` contains the original sibling
C, byte-exact source-edit recipes, resulting C, and compiler settings. Replay:

```sh
uv run tools/fzgx.py fixup --archive state/repairs/sibling_recovery_20261023.json.gz
```

Replay reproduces six records: the three exact objects above and three
explicitly nonmatching frontiers. `fn_3_20748` has seven differing words;
`fn_1_1244F0` has four; `fn_1_11A158` has 61. None of those partials is
submitted or counted as landed code. The nine-column frontier's stock allocator
capture reproduces without errors; its first cursor uses a different value
web from later cursors sharing the same physical register. Declaration moves
and explicit pointer induction did not close it.

The default sibling scan found the first three closures. Widening its trigram
and length filters found fourteen further leads totaling 12,356 bytes. The
scanner now exposes these filters as optional arguments while preserving its
defaults. A bounded 129-variant title-layout experiment produced no closure.
The refreshed active forks supplied no additional exact objects.

Validation: archive replay, `python3 configure.py` followed by `ninja`,
`build/tools/dtk shasum -c config/GFZE01/build.sha1` (all sixteen targets OK),
`fzgx lint` (zero findings), and `fzgx snapshot`.
