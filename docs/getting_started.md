# Getting started with this F-Zero GX repository

This checkout already has the GFZE01 configuration and carved source units.
Do **not** recreate it from the template or rename GAMEID directories. The
current build and progress denominator cover the NTSC-U **main.dol**, not a
verified inventory of every executable module on the game disc.

## Build and verify

Install Python, Ninja and `uv` (see [dependencies](dependencies.md)). Supply your
own game file at `orig/GFZE01/sys/main.dol`; retail game files are not distributed
with the repository. Its expected SHA-1 is
`421c88106697d3275a3fc26fb7a01bf6d816b271`.

From the repository root:

```sh
python3 configure.py
ninja -j4 all_source build/GFZE01/main.dol
sha1sum build/GFZE01/main.dol
ninja baseline build/GFZE01/report.json
uv run --with pytest --with capstone --with pyyaml python -m pytest -q
```

`all_source` is essential: a `NonMatching` unit is compiled and diffed but the
retail link uses its original object. Building only `main.dol` can leave those
candidate objects unbuilt. `ninja baseline` is also required before the
repository's similarity tests; a successful DOL build does not create that
fixture. Do not use `--non-matching` for the retail-preserving validation lane.

The first build downloads the configured compiler/tool dependencies. Avoid
sharing a writable `build/` between worktrees. If reusing local toolchains,
copy `build/tools`, `build/compilers` and `build/binutils` into the new worktree;
Ninja may refresh these directories, so symlinks do not provide read-only
isolation. The legally supplied `orig/` inputs may be shared read-only.

## Read progress honestly

```sh
python3 tools/decomp_report.py --report build/GFZE01/report.json --root . --out build/GFZE01/mission.json
```

The generated mission report uses code bytes as its denominator. Exact natural
C, fuzzy C-expressed, function counts and diagnostic objdiff matching answer
different questions. Handwritten asm is not natural C, even when it matches
perfectly. Do not compare a function-count percentage to a byte percentage.


## Further configuration

The project-specific map is `config/GFZE01/config.yml`; retail symbol and unit
boundaries are in `symbols.txt` and `splits.txt` next to it. Read
[common BSS](common_bss.md) and the upstream
[dtk-template documentation](https://github.com/encounter/dtk-template/tree/main/docs)
before changing those boundaries. Template bootstrapping instructions are not
the normal workflow for this already-configured checkout.
