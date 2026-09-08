# Getting started with this F-Zero GX repository

This checkout targets the complete GFZE01 executable set. The manifest contains
`sys/main.dol`, 14 direct `bg/fze.*.rel` modules, and the encrypted/LZ-packed
`bg/enemy_line/line__.bin` that produces `bg/enemy_line/main.rel`. Do not
silently reduce the target to the DOL.

## Build and verify

Install Python, Ninja and `uv` (see [dependencies](dependencies.md)). Supply your own extracted game tree at `orig/GFZE01/`; retail game files are
not distributed with the repository. The DOL expected SHA-1 is
`421c88106697d3275a3fc26fb7a01bf6d816b271`.

Before configuring a full build, inventory the tree:

```sh
python3 tools/game_inventory.py orig/GFZE01 --output build/GFZE01/game-inventory.json
```

This command exits non-zero until all 16 executable images and the packed
`line__.bin` container are present. The repository does not commit retail game
files; use a legally obtained and extracted copy. `configure.py` then verifies
all module hashes before generating the full multi-module build.

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
