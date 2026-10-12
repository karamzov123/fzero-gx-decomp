# Finding 317: subagent worktrees need `.venv` and `orig` symlinks or delegation dies

**Symptom:** every delegated worker died in seconds with

    timeout: failed to run command '.venv/bin/python': No such file or directory

and reported `exit code 127`. Three separate delegation batches produced nothing this way,
which made delegation look useless in this repo. It is not — the worktrees were just
missing their interpreter.

## Cause

`delegate_task` creates worktrees under `.worktrees/subagent-*`. Those contain `build/`
and `.fzgx/` but **no `.venv` and no `orig`** — not even a symlink. The hand-created agent
worktrees (`fzgx-agy`, `fzgx-claude`, …) *do* have them, which is why the problem only
appeared for delegated workers:

    .venv -> /home/armandofm/projects/fzgx/.venv     # present in agent worktrees
                                                  # absent in .worktrees/subagent-*

`.fzgx` is also far smaller there (47M vs 188G), because the bulk is ignored fixup scratch.

## Fix

Two symlinks per worktree, pointing at the main checkout:

    ln -sfn /home/armandofm/projects/fzgx/.venv <worktree>/.venv
    ln -sfn /home/armandofm/projects/fzgx/orig  <worktree>/orig

The venv is relocatable and works from another directory — `capstone` and
`fzgx.project` both import fine, and the full `claim -> write-unit -> check -> release`
cycle runs.

## Verify before dispatching, do not assume

    cd <worktree> && .venv/bin/python -c \
      "import sys;sys.path.insert(0,'tools');from fzgx import project;project.Project('GFZE01')"

**Trap:** `.venv/bin/python tools/fzgx.py --version` is *not* a connectivity test — the CLI
takes `--version` as an option that expects an argument, so it exits 2 with
`argument --version: expected one argument`. That looks exactly like a broken toolchain.
Use the import probe above instead.

## Results after the fix

The first dispatched batch went from zero output to real work: `fn_8_5608` reached
**100.0% MATCH** and `fn_3_149AC` reached 91.4%, both from empty carve stubs. Delegation is
worth using here once the symlinks exist.

Note each worktree has its **own ledger**, so a worker's `100.0` claim is not evidence on
its own — re-verify in main before landing. One worker's worktree ledger reported 100.0%
while its source file was absent.
