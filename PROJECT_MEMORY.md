# Project memory

## Permanent owner decisions

- The active project goal (2026-11-20) is a recompilable USA (GFZE01) reconstruction: source from which others could build a recompilation/port for any platform, while the tree keeps the 16-target byte match. We do not write the port. Scope, requirements and work order (TU map -> TU collapse -> data ownership) are in docs/RECOMPILATION_SCOPE.md; the natural-C/original-assembly/device-free policy in docs/ASM_POLICY.md is part of it.
- F-Zero AX (Japan Rev C, `GFZJ8P`, owner-supplied) is a reference input for TU boundaries and names only. Never commit or copy its bytes or code; record provenance for derived names and boundaries.
- The owner gives standing authorization to publish each completed, verified progress batch without repeated permission requests. Consolidate already-merged approved GitHub main changes with accepted local work before continuing. Use only tools/fleet_integrator.py for clean pinned-main, hash/lint-verified, fast-forward publication and independently read back the remote SHA. This does not authorize bypassing guards, changing tool approval configuration or force pushes.
- Any agent may pull and merge open PRs unless the owner says otherwise (owner, 2026-11-27), through the normal gates: a `--no-ff` merge commit, all three region builds, `dtk shasum -c`, `fzgx lint`, then the approved publisher.

- Direct imports from nkhoit (the owner's spelling: "nkoit") are prohibited. This covers harvesting, cherry-picking and copying code, tools, data, partial bodies or repair recipes, including cached candidates and indirect copies through another fork. Do not fetch that contributor's refs for direct import work.
- The owner will still use nkhoit's work through pull requests. The direct-import ban does not prohibit that PR workflow or maintaining work already accepted through it. Agents may merge its PRs under the general PR rule (owner, 2026-11-27).
- Existing landed code and attribution remain; no rollback was requested.
- Independent deltawave784 contributions remain permitted under the normal compiler, source-admission, lint, provenance and complete 16-target hash gates.
- The direct-import restriction has no automatic expiry. Change it only on explicit owner instruction.

These decisions are also in AGENTS.md, CLAUDE.md and docs/SOURCE_IMPORT_POLICY.md. Historical import reports are provenance, not permission to resume direct nkhoit imports.
