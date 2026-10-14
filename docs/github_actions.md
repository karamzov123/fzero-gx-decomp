# GitHub Actions and decomp.dev

The public repository never contains game files, so CI builds inside a **private**
container image that does. This follows dtk-template's pattern exactly.

## 1. The private build repository (`rayanht/fzgx-build`)

1. Create a **private** repository from the
   [dtk-template-build](https://github.com/new?template_name=dtk-template-build&template_owner=encounter)
   template, named `fzgx-build`.
2. Add the game files under `orig/GFZE01/`, **only what the build needs**: run
   `uv run tools/prepare_orig.py --version GFZE01` in this repository first, then copy
   `orig/GFZE01/sys/main.dol`, `orig/GFZE01/files/fze.*.rel` and
   `orig/GFZE01/files/enemy_line/main.rel` (the derived, decrypted REL; `line__.bin`
   itself is not needed by the build).
3. Let its action build the image, then in the package settings under
   "Manage Actions access" grant this repository (`rayanht/fzgx`) the **Read** role.

The workflow in `.github/workflows/build.yml` pulls `ghcr.io/rayanht/fzgx-build:main`,
copies `/orig` into the workspace, configures with `--compilers /compilers --binutils /binutils`,
builds `all_source progress build/GFZE01/report.json`, runs the tests, and uploads the
report as the `GFZE01_report` artifact.

## 2. decomp.dev

Once the workflow is green on `main`, register the project at
<https://decomp.dev/manage/new> with this GitHub repository. decomp.dev reads the
`GFZE01_report` artifact of every run on the default branch and renders:

- shield badges: `https://decomp.dev/rayanht/fzgx.svg?mode=shield&measure=code&label=Code&category=all`
  (`category` is `all`, `dol`, `modules`, or one of the extra categories in
  `configure.py`: `game`, `sdk`; `measure` is `code` or `data`);
- the live treemap: `https://decomp.dev/rayanht/fzgx.svg?w=1024&h=320`;
- per-version badges: `https://decomp.dev/rayanht/fzgx/GFZE01.svg?mode=shield`.

The README already embeds these URLs; they render once the first report is ingested.

## 3. Fuzzy match

`report.json` scores only linked or carved code, so an unmatched function sits at 0% however
close its best attempt came. `tools/fuzzy_report.py apply` (the "Fuzzy match" CI step) compiles
the partial bodies kept in `fuzzy/GFZE01/`, merges them per retail auto object into a base
object, and regenerates the report with those units pointed at it. Nothing is linked and no
split changes, so only `fuzzy_match_percent` moves: the step fails, and the exact report is
uploaded unchanged, if any matched/complete/total measure differs, and a body that objdiff would
score 100% is left out (it belongs in `fzgx submit`). The exact report is kept as the
`GFZE01_exact` artifact, a name decomp.dev's `<version>_report` pattern ignores.

The bodies refresh themselves: `fzgx-fuzzy-refresh.timer` (`tools/systemd/`) runs
`tools/fuzzy_refresh.py` every 30 minutes in the dedicated worktree `../fzgx-fuzzy`, reset to
`origin/main` first. When main or the ledger's best attempts changed since the last run, it
builds, re-runs `uv run tools/fuzzy_report.py export --version GFZE01` against the main
checkout's ledger, and lands a changed `fuzzy/GFZE01/` as a merged pull request from
`auto/fuzzy-refresh` (owner's choice: no review step), so the next CI report carries it; local
main is then fast-forwarded for the integrator. It waits while local main holds unpublished
commits. Stale bodies are harmless in between (a function carved since the export is skipped).
Worktree setup, once: `git worktree add --detach ../fzgx-fuzzy origin/main`, then symlink
`orig/GFZE01`, `build/compilers` and `build/binutils` to the main checkout's.

## 4. What the report counts

`report.json` is objdiff's whole-project measurement: matched code bytes and functions
per unit, split into the categories above. Units are the per-function and per-TU C
files in `config/GFZE01/units.json`; unmatched code is linked from decomp-toolkit's
split objects and counts as unmatched. There is no hand-written assembly anywhere, so
"matched" means matched in C.
