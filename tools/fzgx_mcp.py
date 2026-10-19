#!/usr/bin/env python3
"""MCP server exposing the fzgx matcher surface as tools.

Matcher agents get these tools and nothing else (no shell): they can only
claim a function, read its context, replace their own unit's source, check it
against retail, and submit or release. Every mutation is validated against
the ledger's claim (tools/fzgx/api.py), so an agent cannot touch a unit it
does not own.

Each tool call runs the CLI (`tools/fzgx.py --json ...`) in a subprocess
rather than importing the library, so fixes to tools/fzgx/ take effect on the
next call without restarting the server or the session. Overhead is ~0.1 s.

Registered in .mcp.json (Claude Code) and ~/.codex/config.toml (Codex).
Run from the repository root: `uv run tools/fzgx_mcp.py`.
"""

from __future__ import annotations

import json
import os
import subprocess
import sys
import tempfile
import threading
from pathlib import Path
from typing import List, Optional

import anyio
from mcp.server.fastmcp import FastMCP

ROOT = Path(__file__).resolve().parent.parent
CLI = ROOT / "tools" / "fzgx.py"

mcp = FastMCP("fzgx", instructions=(
    "F-Zero GX matching oracle. The runner supplies the assignment, C and initial diff. "
    "Edit and check; matches and attempt limits end the session automatically."
    if os.environ.get('FZGX_RESULT_FILE') else
    "F-Zero GX matching-decompilation oracle. Claim ownership before editing; "
    "use saved C, compiler feedback and submit/release. Unbound contributors may "
    "work through multiple functions sequentially: a failed idea or release is not "
    "a session stop. Keep ownership and hash verification; evidence tools are optional."))


def _cli(*args: str, as_json: bool = True, timeout: int = 900) -> str | dict | list:
    cmd = [sys.executable, str(CLI)] + (["--json"] if as_json else []) + list(args)
    cp = subprocess.run(cmd, cwd=ROOT, text=True, capture_output=True, timeout=timeout)
    result_file = os.environ.get('FZGX_RESULT_FILE')
    if result_file and Path(result_file).exists():
        # The runner consumes the terminal result and stops this process group.
        # Do not send another tool result to the model just to narrate completion.
        threading.Event().wait(30)
        raise RuntimeError('runner did not stop the completed worker')
    out = cp.stdout.strip()
    if as_json:
        try:
            return json.loads(out) if out else {"ok": False, "error": (cp.stderr or "no output").strip()[-2000:]}
        except json.JSONDecodeError:
            return {"ok": False, "error": (out + "\n" + cp.stderr).strip()[-2000:]}
    return out if cp.returncode == 0 or out else (cp.stderr.strip() or "no output")[-4000:]


async def _run(*args: str, as_json: bool = True):
    return await anyio.to_thread.run_sync(lambda: _cli(*args, as_json=as_json))


@mcp.tool()
async def claim(symbol: str, agent: str) -> dict:
    """Claim SYMBOL for AGENT, initialize its private work copy and return the full context bundle (retail asm, symbols, callers, nearby matched C, flags, idioms, rules) in `context`. Seeded claims include the complete existing candidate in `seed.source`."""
    return await _run("claim", symbol, "--agent", agent)


@mcp.tool()
async def context(symbol: str, budget_tokens: int = 6000) -> str:
    """Context bundle: retail assembly, referenced symbols with declarations, callers, nearby matched C, current unit source, compiler flags, idioms, rules."""
    return await _run("context", symbol, "--budget-tokens", str(budget_tokens), as_json=False)


@mcp.tool()
async def read_unit(symbol: str) -> dict:
    """Current source of SYMBOL's unit."""
    return await _run("read-unit", symbol)


@mcp.tool()
async def read_evidence(symbol: str, section: str = 'diff', cursor: int = 0) -> str:
    """Read cached diff or owned data layouts, values and bindings by line cursor, without compiling or spending a check."""
    return await _run('read-evidence', symbol, '--section', section, '--cursor', str(cursor), as_json=False)


@mcp.tool()
async def write_unit(symbol: str, agent: str, source: str) -> dict:
    """Replace the whole source of the unit AGENT has claimed for SYMBOL, then compile and diff it against retail. Returns lint findings (A1/A2 hardcoded addresses, S1/S2 goto/volatile) and `check`: match % with a `target | ours` diff."""
    def go():
        with tempfile.NamedTemporaryFile("w", suffix=".c", delete=False, dir=ROOT / ".fzgx") as f:
            f.write(source)
            path = f.name
        try:
            return _cli("write-unit", symbol, "--agent", agent, "--file", path)
        finally:
            Path(path).unlink(missing_ok=True)
    (ROOT / ".fzgx").mkdir(exist_ok=True)
    return await anyio.to_thread.run_sync(go)


@mcp.tool()
async def patch_unit(symbol: str, agent: str, old: str, new: str) -> dict:
    """Edit the unit AGENT has claimed for SYMBOL in place: `old` must occur exactly once in the current source and is replaced by `new`; then compile and diff like write_unit (same `check` result). Use it for every change after the first write_unit: one declaration, one statement, one struct field, sent as a few lines instead of the whole unit."""
    def go():
        (ROOT / ".fzgx").mkdir(exist_ok=True)
        with tempfile.NamedTemporaryFile("w", suffix=".old", delete=False, dir=ROOT / ".fzgx") as f1, \
             tempfile.NamedTemporaryFile("w", suffix=".new", delete=False, dir=ROOT / ".fzgx") as f2:
            f1.write(old); f2.write(new); p1, p2 = f1.name, f2.name
        try:
            return _cli("patch-unit", symbol, "--agent", agent, "--old-file", p1, "--new-file", p2)
        finally:
            Path(p1).unlink(missing_ok=True); Path(p2).unlink(missing_ok=True)
    return await anyio.to_thread.run_sync(go)


@mcp.tool()
async def check(symbol: str, versions: Optional[str] = None, max_diff_lines: int = 80) -> str:
    """Compile SYMBOL's unit and diff against retail. Prints match %, compiler settings and a `target | ours` instruction diff. With versions='all' (or a comma list like 'GC/1.2.5n,GC/1.3.2'), probe CodeWarrior versions, show the winning diff and retain that compiler for subsequent edits and submit."""
    args = ["check", symbol, "--max-diff-lines", str(max_diff_lines)]
    if versions:
        args += ["--versions", versions]
    return await _run(*args, as_json=False)


@mcp.tool()
async def submit(symbol: str, agent: str, message: str, harness: str = "", model: str = "",
                 mw_version: Optional[str] = None, names: Optional[List[dict]] = None) -> dict:
    """Accept a 100% match: lint, relink every target, verify all 16 hashes, commit. `names` is an optional list of {kind,target,name,rationale} proposals for the librarian. Pass mw_version (e.g. 'GC/1.3') only if check(versions=...) showed that version matches."""
    def go():
        args = ["submit", symbol, "--agent", agent, "--message", message]
        if harness:
            args += ["--harness", harness]
        if model:
            args += ["--model", model]
        if mw_version:
            args += ["--mw-version", mw_version]
        path = None
        if names:
            with tempfile.NamedTemporaryFile("w", suffix=".json", delete=False, dir=ROOT / ".fzgx") as f:
                json.dump(names, f)
                path = f.name
            args += ["--names", path]
        try:
            return _cli(*args)
        finally:
            if path:
                Path(path).unlink(missing_ok=True)
    (ROOT / ".fzgx").mkdir(exist_ok=True)
    return await anyio.to_thread.run_sync(go)


@mcp.tool()
async def search(symbol: str, agent: str) -> dict:
    """Run the deterministic search (declaration order, type and sign flips, optimizer pragmas, pool and section priming) on the work copy AGENT has claimed for SYMBOL. An exact result is accepted; a better body replaces the work copy and its diff is returned; otherwise nothing changes."""
    return await _run('search', symbol, '--agent', agent)


@mcp.tool()
async def release(symbol: str, agent: str, reason: str, harness: str = "", model: str = "") -> dict:
    """Give up on SYMBOL. The best attempt is saved for the next agent; say precisely what still differs."""
    args = ["release", symbol, "--agent", agent, "--reason", reason]
    if harness:
        args += ["--harness", harness]
    if model:
        args += ["--model", model]
    return await _run(*args)


@mcp.tool()
async def inventory(module: Optional[str] = None, status: Optional[str] = None,
                    max_size: Optional[int] = None, limit: Optional[int] = 50) -> list:
    """List functions (orchestrator use): filter by module (main, main_rel, ...), status (unmatched|claimed|matched|blocked), max_size bytes."""
    args = ["inventory"]
    if module:
        args += ["--module", module]
    if status:
        args += ["--status", status]
    if max_size:
        args += ["--max-size", str(max_size)]
    if limit:
        args += ["--limit", str(limit)]
    return await _run(*args)


@mcp.tool()
async def report() -> dict:
    """Ledger status totals, costs, and objdiff progress."""
    return await _run("report")


if __name__ == "__main__":
    mcp.run()
