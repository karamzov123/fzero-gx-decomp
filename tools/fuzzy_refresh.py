"""Keep fuzzy/<VERSION>/ in step with the published report, without anyone running export.

decomp.dev's fuzzy match comes from the partial bodies in fuzzy/<VERSION>/, which only
`fuzzy_report.py export` can refresh, because their source is the local ledger. This runs that
export whenever its inputs move: a new origin/main (carves and matches change which bodies are
eligible) or a ledger with new best attempts. It builds in a dedicated worktree detached at
origin/main (fzgx-fuzzy-refresh.service resets it first), so the main checkout and its branch
are never touched, and lands a changed export through a merged pull request, so the next CI run
scores it. Local main is then fast-forwarded, as the integrator requires.

Skips when nothing changed since the last refresh, when the only new commits on main touch
fuzzy/ alone (its own merges), and when local main holds unpublished commits (merging past them
would leave the integrator divergent).

    python3 tools/fuzzy_refresh.py [--version GFZE01] [--no-publish] [--force]
"""

from __future__ import annotations

import argparse
import json
import sqlite3
import subprocess
import sys
from pathlib import Path
from typing import List, Optional

ROOT = Path(__file__).resolve().parents[1]
BRANCH = "auto/fuzzy-refresh"


def run(*cmd: str, cwd: Path = ROOT, check: bool = True, timeout: Optional[int] = None) -> str:
    r = subprocess.run(cmd, cwd=cwd, capture_output=True, text=True, timeout=timeout)
    if check and r.returncode:
        raise SystemExit(f"{' '.join(cmd)} failed ({r.returncode}):\n{r.stdout[-2000:]}{r.stderr[-2000:]}")
    return r.stdout.strip()


def git(*args: str, check: bool = True) -> str:
    return run("git", *args, check=check)


def log(msg: str) -> None:
    print(msg, flush=True)


def main_checkout() -> Path:
    return Path(git("rev-parse", "--path-format=absolute", "--git-common-dir")).parent


def ledger_signature(ledger: Path) -> List:
    """Changes whenever export would read something new: a better attempt or a new match."""
    db = sqlite3.connect(f"file:{ledger}?mode=ro", uri=True)
    try:
        best = db.execute("select count(*), coalesce(max(id), 0), round(coalesce(sum(best_in_attempt), 0), 4) "
                          "from attempts where coalesce(best_body_path, '') != ''").fetchone()
        matched = db.execute("select count(*) from functions where status = 'matched'").fetchone()
    finally:
        db.close()
    return [*best, *matched]


def unchanged(state: dict, head: str, sig: List) -> bool:
    if not state or state.get("ledger") != sig or not state.get("main"):
        return False
    if state["main"] == head:
        return True
    r = subprocess.run(["git", "diff", "--name-only", state["main"], head], cwd=ROOT,
                       capture_output=True, text=True)
    paths = r.stdout.split()
    return r.returncode == 0 and all(p.startswith("fuzzy/") for p in paths)


def build(version: str) -> None:
    run(sys.executable, "configure.py", "--version", version,
        "--compilers", "build/compilers", "--binutils", "build/binutils")
    run("ninja", "all_source", f"build/{version}/report.json", timeout=3600)


def main_holder() -> Optional[Path]:
    """Worktree that has main checked out, if any."""
    path = None
    for line in git("worktree", "list", "--porcelain").splitlines():
        if line.startswith("worktree "):
            path = Path(line.split(" ", 1)[1])
        elif line == "branch refs/heads/main":
            return path
    return None


def fast_forward_main() -> None:
    git("fetch", "-q", "origin", "main")
    holder = main_holder()
    if holder is None:
        r = subprocess.run(["git", "fetch", "-q", "origin", "main:main"], cwd=ROOT, capture_output=True, text=True)
        log("local main fast-forwarded" if r.returncode == 0 else f"local main not fast-forwarded: {r.stderr.strip()}")
    elif run("git", "status", "--porcelain", "--untracked-files=no", cwd=holder):
        log(f"local main left behind: {holder} has uncommitted changes")
    else:
        r = subprocess.run(["git", "merge", "-q", "--ff-only", "origin/main"], cwd=holder, capture_output=True, text=True)
        log("local main fast-forwarded" if r.returncode == 0 else f"local main not fast-forwarded: {r.stderr.strip()}")


def fork() -> str:
    """owner/name of origin; gh would otherwise default to the upstream repository."""
    url = git("remote", "get-url", "origin").removesuffix(".git")
    return "/".join(url.replace(":", "/").split("/")[-2:])


def publish(version: str, summary: dict) -> None:
    changed = git("status", "--porcelain", "--", f"fuzzy/{version}").splitlines()
    paths = [line[3:] for line in changed]
    stray = [p for p in paths if not (p.startswith(f"fuzzy/{version}/") and p.endswith((".c", ".json")))]
    if stray:
        raise SystemExit(f"refusing to publish unexpected paths: {stray[:10]}")
    before, after = summary.get("fuzzy_match_percent", [0, 0])
    title = f"fuzzy: refresh partial bodies from the ledger ({summary.get('exported')} bodies, fuzzy {after:.2f}%)"
    git("add", "-A", "--", f"fuzzy/{version}")
    git("commit", "-q", "-m", title, "-m",
        "Automatic export by tools/fuzzy_refresh.py; scored for decomp.dev's fuzzy match only, never linked.")
    git("push", "-q", "--force", "origin", f"HEAD:refs/heads/{BRANCH}")
    repo = fork()
    prs = json.loads(run("gh", "pr", "list", "--repo", repo, "--head", BRANCH, "--state", "open", "--json", "number"))
    if prs:
        number = str(prs[0]["number"])
    else:
        body = (f"Automatic refresh of `fuzzy/{version}/` from the ledger's best attempts "
                f"({len(paths)} files changed).\n\n```json\n{json.dumps(summary, indent=1)}\n```\n\n"
                "Exact measures are unchanged (checked by `fuzzy_report.py`); only the fuzzy match moves.")
        url = run("gh", "pr", "create", "--repo", repo, "--base", "main", "--head", BRANCH, "--title", title, "--body", body)
        number = url.rstrip("/").rsplit("/", 1)[-1]
    run("gh", "pr", "merge", number, "--repo", repo, "--merge")
    git("push", "-q", "origin", "--delete", BRANCH, check=False)
    log(f"merged PR #{number}: {title}")
    fast_forward_main()


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--version", default="GFZE01")
    ap.add_argument("--ledger", type=Path, help="default: the main checkout's .fzgx/ledger.db")
    ap.add_argument("--no-publish", action="store_true", help="export only; leave fuzzy/ uncommitted")
    ap.add_argument("--force", action="store_true", help="export even if nothing changed")
    a = ap.parse_args()
    ledger = a.ledger or main_checkout() / ".fzgx" / "ledger.db"
    state_path = ROOT / ".fzgx" / "fuzzy-refresh.json"
    try:
        state = json.loads(state_path.read_text())
    except (OSError, ValueError):
        state = {}
    head = git("rev-parse", "HEAD")
    sig = ledger_signature(ledger)
    if not a.force and unchanged(state, head, sig):
        log("fuzzy bodies up to date")
        return
    if not a.no_publish:
        if git("rev-parse", "origin/main") != head:
            raise SystemExit("worktree is not at origin/main; the service resets it before each run")
        if subprocess.run(["git", "merge-base", "--is-ancestor", "main", head], cwd=ROOT).returncode:
            log("local main has unpublished commits; refresh deferred until the integrator pushes them")
            return
    build(a.version)
    out = run(sys.executable, "tools/fuzzy_report.py", "export", "--version", a.version,
              "--ledger", str(ledger), timeout=3600)
    summary = json.loads(out[out.index("{\n"):])
    log(json.dumps(summary))
    if git("status", "--porcelain", "--", f"fuzzy/{a.version}") and not a.no_publish:
        publish(a.version, summary)
        head = git("rev-parse", "HEAD")
    elif not a.no_publish:
        log("export unchanged")
    if not a.no_publish:
        state_path.parent.mkdir(exist_ok=True)
        state_path.write_text(json.dumps({"main": head, "ledger": sig, "summary": summary}) + "\n")


if __name__ == "__main__":
    main()
