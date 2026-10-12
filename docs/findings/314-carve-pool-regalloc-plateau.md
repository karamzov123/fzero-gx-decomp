# Carve-pool near-99% functions: confirmed regalloc plateau (2026-10-11)

Fifteen high-value functions were carved into landable units and probed
directly. Every one sits at 99.0-99.4% with a **regalloc** residual that the
deterministic search and the fixup sweep cannot close. No match landed; no
executable-byte change is claimed.

## Evidence

fn_12_323B0 (172 B, movie_module) is the worked example. The residual is 5 rows,
all labelled `regalloc`:

    008C  lwz r6, 0xb4(r5)     | lwz r5, 0xb4(r5)
    0094  rlwinm r0, r6, 8,... | rlwinm r0, r5, 8,...
    0098  rlwimi r0, r6, ...   | rlwimi r0, r5, ...
    009C  rlwimi r0, r6, ...   | rlwimi r0, r5, ...
    00A0  rlwimi r0, r6, ...   | rlwimi r0, r5, ...

Retail loads `movie+0xb4` into a fresh r6 while `movie` stays in r5; MWCC reuses
r5 for the loaded value because `movie` is dead after the load. This is a
survivor-order register-allocation artifact (docs/findings survivor-order law):
the loaded web and the pointer web have different interference degree, and no
source permutation changes that.

## What was measured (do not repeat)

- Manual edits: `(void)movie`, a keep-load, direct `arg0->unk_4` access, removing
  the peephole pragma, declaration reorderings — all plateau or regress.
- Deterministic search: the claim context records **8846 compiled variants**
  already tried without closing it; a fresh `fzgx search` run reported
  "No candidate beat 99.4%: not reachable by declaration order, type/sign flips,
  pragmas or pool priming. They need a structural change."
- Fixup sweep over all 13 (`sweep --min-percent 99 --land`): 2 improved in
  round 0, 0 net, 0 matched.

The same r5/r6 and r7/r8 callee-saved split appears in fn_12_321E8,
fn_12_32280, fn_12_32318, fn_12_3267C, fn_12_32834, fn_1_53B14, fn_1_53BD8,
fn_1_8CA70, fn_1_8CAF4 — the whole near-99% shelf shares the failure mode.

## Conclusion

These functions need a register-allocation-level fix (a held local that changes
the interference graph, or an asm unit), not source spelling. They are the wrong
target for manual or cheap-family repair. The fleet matcher at full effort, or
an `asm-unit` landing, is the honest path. Carving them was correct (they are
landable units now); landing them is blocked on regalloc, recorded here.

## fn_12_72F4: a semantically-wrong 99.88% (2026-10-11)

fn_12_72F4 (movie_module, 172 B) scored 99.88% on a body that was actually
**semantically wrong**. Retail:

    mr r25, r3          ; r25 = movie
    addi r27, r25, 0x44 ; r27 = arg = movie+0x44
    mr r30, r25         ; r30 = movie   (the loop pointer)
    ...
    addi r0, r30, 0x640
    stw  r0, 0x1c(r27)  ; arg->field_1c = movie + 0x640

The canonical body set the loop pointer to `arg` (`mr r30, r27`), storing
`arg + 0x640` — the wrong base — yet scored 99.88% because only the single
`mr` register differed in the diff. Correcting `current_2` to `movie`
(matching `mr r30, r25`) drops the raw score to 95.5% (the `mr r30` moves
position) but is the faithful reconstruction. Neither the corrected body nor
source permutations close it: the search reports "not reachable by declaration
order... they need a structural change." Both bodies are saved in
`.fzgx/attempts/`. A 99.88% score is not proof of correctness — always read the
retail register trace before trusting a near-miss percentage.
