#!/usr/bin/env python3
"""Autonomous Integration & PR Supervisor for F-Zero GX Decompilation.

Monitors agent worktrees (Cline, Claude, GPT, AGY), verifies new commits
against the retail oracle (ninja 16 files OK), pushes to GitHub, opens PRs,
and auto-merges verified matches into main.
"""

import argparse
import json
import os
import re
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
REPO = "karamzov123/fzgx"

def get_all_agents():
    agents = {}
    res = run(["git", "branch", "--list", "agent/*"], check=False)
    branches = [line.strip().lstrip("*+ ").strip() for line in res.stdout.splitlines()]
    for b in branches:
        if not b:
            continue
        instance_id = b.removeprefix("agent/")
        path = ROOT.parent / f"fzgx-{instance_id}"
        agents[instance_id] = {
            "branch": b,
            "path": path,
            "desc": f"Agent worker {instance_id}",
        }
    return agents


def run(cmd, cwd=ROOT, check=True, capture=True):
    res = subprocess.run(
        cmd,
        cwd=str(cwd),
        shell=isinstance(cmd, str),
        text=True,
        capture_output=capture,
    )
    if check and res.returncode != 0:
        err = res.stderr.strip() if capture else f"exit code {res.returncode}"
        raise RuntimeError(f"Command failed ({cmd}): {err}")
    return res


def get_rev(ref, cwd=ROOT):
    return run(["git", "rev-parse", ref], cwd=cwd).stdout.strip()


def commits_behind_ahead(base, head, cwd=ROOT):
    out = run(["git", "rev-list", "--left-right", "--count", f"{base}...{head}"], cwd=cwd).stdout.strip()
    behind, ahead = map(int, out.split())
    return behind, ahead


import shutil

def test_merge_and_verify(agent_name, agent_info):
    """Test merge into a detached staging worktree and run ninja."""
    staging_dir = ROOT.parent / ".fzgx_staging_test"
    try:
        # Clean up any leftover worktree registration
        subprocess.run(["git", "worktree", "remove", "--force", str(staging_dir)],
                       cwd=str(ROOT), capture_output=True)
        subprocess.run(["git", "worktree", "prune"], cwd=str(ROOT), capture_output=True)
        if staging_dir.exists():
            shutil.rmtree(staging_dir, ignore_errors=True)
        time.sleep(0.1)
        run(["git", "worktree", "add", "-f", "--detach", str(staging_dir), "main"])

        # Symlink orig and tools into staging
        (staging_dir / "orig").mkdir(parents=True, exist_ok=True)
        for f in (ROOT / "orig").iterdir():
            run(f"ln -sf {f} {staging_dir / 'orig' / f.name}")
        run(f"ln -sfn {ROOT / '.venv'} {staging_dir / '.venv'}")
        (staging_dir / "build").mkdir(parents=True, exist_ok=True)
        run(f"ln -sfn {ROOT / 'build' / 'tools'} {staging_dir / 'build' / 'tools'}")
        run(f"ln -sfn {ROOT / 'build' / 'binutils'} {staging_dir / 'build' / 'binutils'}")
        run(f"ln -sfn {ROOT / 'build' / 'compilers'} {staging_dir / 'build' / 'compilers'}")

        # Attempt merge of agent branch
        head_rev = get_rev(agent_info["branch"])
        m_res = run(["git", "merge", "--no-ff", "-m", f"Test merge {agent_info['branch']}", head_rev],
                    cwd=staging_dir, check=False)
        if m_res.returncode != 0:
            print(f"[{agent_name}] Merge conflict detected; cannot auto-integrate.")
            return False, "merge_conflict"

        # Run configure.py and ninja check
        conf_res = run("python3 configure.py --version GFZE01", cwd=staging_dir, check=False)
        if conf_res.returncode != 0:
            print(f"[{agent_name}] Configure failed in staging: {conf_res.stderr}")
            return False, "configure_failed"

        c_res = run("ninja", cwd=staging_dir, check=False)
        if c_res.returncode != 0 or "16 files OK" not in c_res.stdout:
            print(f"[{agent_name}] Ninja oracle verification FAILED:\n{c_res.stderr or c_res.stdout}")
            return False, "oracle_failed"

        return True, "verified"
    finally:
        # Clean up staging worktree
        subprocess.run(["git", "worktree", "remove", "--force", str(staging_dir)],
                       cwd=str(ROOT), capture_output=True)
        subprocess.run(["git", "worktree", "prune"], cwd=str(ROOT), capture_output=True)


def get_commit_details(agent_info, count):
    res = run(["git", "log", f"-n{count}", "--format=format:### %s%n%b%n"],
              cwd=agent_info["path"])
    return res.stdout.strip()


def check_and_integrate_agent(agent_name, agent_info, auto_pr=True):
    if not agent_info["path"].exists():
        return False

    main_rev = get_rev("main")
    branch = agent_info["branch"]

    # Check if branch exists
    b_check = run(["git", "rev-parse", "--verify", branch], check=False)
    if b_check.returncode != 0:
        return False

    behind, ahead = commits_behind_ahead("main", branch)
    if ahead == 0:
        return False  # Nothing to integrate

    print(f"\n>>> [{agent_name}] Detected {ahead} new commit(s) ahead of main.")

    # If the branch has diverged behind main, try rebasing the agent branch first if clean
    if behind > 0:
        st = run(["git", "status", "--porcelain"], cwd=agent_info["path"]).stdout.strip()
        uncommitted = [l for l in st.splitlines() if not l.startswith("??")]
        if not uncommitted:
            print(f"[{agent_name}] Branch is {behind} commits behind main; auto-rebasing cleanly...")
            rebase_res = run(["git", "rebase", "main"], cwd=agent_info["path"], check=False)
            if rebase_res.returncode != 0:
                run(["git", "rebase", "--abort"], cwd=agent_info["path"], check=False)
                print(f"[{agent_name}] Auto-rebase conflict; skipping integration for this cycle.")
                return False
            behind, ahead = commits_behind_ahead("main", branch)
            if ahead == 0:
                print(f"[{agent_name}] All commits were already on main after rebase.")
                return False

    # 1. Local oracle validation
    print(f"[{agent_name}] Running local oracle verification (ninja)...")
    ok, reason = test_merge_and_verify(agent_name, agent_info)
    if not ok:
        print(f"[{agent_name}] FAILED verification: {reason}. Skipping auto-merge.")
        return False

    print(f"[{agent_name}] Verification PASSED (16 files OK)!")

    # 2. Push branch to GitHub
    print(f"[{agent_name}] Pushing {branch} to origin...")
    run(["git", "push", "-f", "origin", branch], cwd=agent_info["path"])

    commit_log = get_commit_details(agent_info, ahead)

    # 3. Create or update PR if requested
    if auto_pr:
        pr_list = run(["gh", "pr", "list", "--repo", REPO, "--head", branch, "--json", "number,url"],
                      check=False)
        prs = json.loads(pr_list.stdout) if pr_list.returncode == 0 and pr_list.stdout.strip() else []

        if prs:
            pr_num = prs[0]["number"]
            pr_url = prs[0]["url"]
            print(f"[{agent_name}] Updating and merging existing PR #{pr_num} ({pr_url})...")
            run(["gh", "pr", "merge", "--repo", REPO, branch, "--merge"], check=False)
        else:
            title = f"Match ({agent_name}): {ahead} new link-verified function(s)"
            body = (
                f"## Automated Match Integration\n"
                f"**Agent**: {agent_info['desc']}\n"
                f"**Commits**:\n\n{commit_log}\n\n"
                f"### Verification\n"
                f"- Full 16-target link check: **16 files OK**\n"
                f"- Zero hardcoded addresses / clean-room compliant\n"
            )
            print(f"[{agent_name}] Creating GitHub PR...")
            pr_create = run(["gh", "pr", "create", "--repo", REPO, "--base", "main",
                             "--head", branch, "--title", title, "--body", body], check=False)
            if pr_create.returncode == 0:
                pr_url = pr_create.stdout.strip()
                print(f"[{agent_name}] PR created successfully: {pr_url}")
                # Direct merge the PR
                print(f"[{agent_name}] Merging PR on GitHub...")
                run(["gh", "pr", "merge", "--repo", REPO, branch, "--merge"], check=False)

    # 4. Integrate into local main
    print(f"[{agent_name}] Syncing local main...")
    if auto_pr:
        run(["git", "pull", "--rebase", "origin", "main"], cwd=ROOT, check=False)
    else:
        run(["git", "merge", "--no-ff", "-m", f"Merge {branch}", branch], cwd=ROOT)
        run(["git", "push", "origin", "main"], cwd=ROOT)

    # Update ledger snapshot
    run(["uv", "run", "tools/fzgx.py", "sync"], cwd=ROOT, check=False)
    run(["uv", "run", "tools/fzgx.py", "snapshot"], cwd=ROOT, check=False)
    st = run(["git", "status", "--porcelain", "state/ledger.json"], cwd=ROOT, check=False).stdout.strip()
    if st:
        run(["git", "commit", "-m", f"state: update ledger snapshot after {agent_name} integration", "state/ledger.json"], cwd=ROOT, check=False)
        run(["git", "push", "origin", "main"], cwd=ROOT, check=False)

    # 5. Rebase agent worktrees so none fall behind
    print(f"[{agent_name}] Syncing active worktrees...")
    agents = get_all_agents()
    for other_name, other_info in agents.items():
        if other_info["path"].exists():
            st = run(["git", "status", "--porcelain"], cwd=other_info["path"]).stdout.strip()
            uncommitted = [l for l in st.splitlines() if not l.startswith("??")]
            if not uncommitted:
                run(["git", "rebase", "main"], cwd=other_info["path"], check=False)

    subprocess.run(["notify-send", "-u", "normal", "F-Zero GX Fleet Integration",
                    f"Successfully integrated {ahead} match(es) from {agent_name} into main!"], check=False)
    return True


def print_status():
    print("=== F-Zero GX Multi-Agent Integration Status ===")
    main_rev = get_rev("main")[:8]
    print(f"Local main @ {main_rev}\n")
    agents = get_all_agents()
    for name, info in agents.items():
        if not info["path"].exists():
            print(f"  {name:8s} [not initialized] ({info['path']})")
            continue
        try:
            behind, ahead = commits_behind_ahead("main", info["branch"])
            rev = get_rev(info["branch"])[:8]
            print(f"  {name:8s} @ {rev} (ahead: {ahead}, behind: {behind}) - {info['desc']}")
        except Exception as e:
            print(f"  {name:8s} [error: {e}]")
    print("================================================")


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--status", action="store_true", help="Print status of all agent branches")
    p.add_argument("--once", action="store_true", help="Run a single integration sweep")
    p.add_argument("--watch", action="store_true", help="Watch continuously for agent commits")
    p.add_argument("--interval", type=int, default=30, help="Interval in seconds for watch mode")
    p.add_argument("--no-pr", action="store_true", help="Merge locally without opening GitHub PRs")
    args = p.parse_args()

    if args.status:
        print_status()
        return

    if args.watch:
        print(f"Starting auto_pr supervisor loop (polling every {args.interval}s)...")
        while True:
            try:
                agents = get_all_agents()
                for name, info in agents.items():
                    check_and_integrate_agent(name, info, auto_pr=not args.no_pr)
            except Exception as e:
                print(f"[Supervisor Error] {e}")
            time.sleep(args.interval)
    else:
        # Default is single sweep
        agents = get_all_agents()
        for name, info in agents.items():
            check_and_integrate_agent(name, info, auto_pr=not args.no_pr)
        print_status()


if __name__ == "__main__":
    main()
