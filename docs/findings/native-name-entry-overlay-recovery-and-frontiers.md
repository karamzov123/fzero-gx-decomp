# Native name-entry overlay recovery and bounded continuation frontiers

## Verified result

`e232dde7` restores `fn_10_266AC` (sel, 760 bytes) to the actual native-C link.
This is a recovery of previously claimed-but-unauthored credit, not a newly
discovered function. Before recovery, the registry pointed at a nonexistent
`rel/sel/name_entry/fn_10_266AC.c`, marked the unit nonmatching, and disagreed with
the split's `rel/sel/fn_10_266AC.c`. An orphan source at that latter path contained
an allocator identity helper and an optimizer workaround.

The standalone and generated tagged-TU units now match retail exactly. The
registry uses the split's correct virtual unit path and status `matching`; the
canonical native body is the tagged block in `src/rel/sel/name_entry.c`. The
obsolete standalone file is removed after proving that the generated TU-backed
unit is built and linked. Configuration no longer emits the sel missing-unit
warning. `fn_80036AC4` remains an unrelated missing-source warning and remains
blocked; no stale verified flag was promoted.

## Structural repair

Use the existing 88-byte `FontDrawPacket` from `include/font.h`, with independent
packet and packed-color locals. Do not group unrelated locals in an invented
frame-shaped aggregate. Mark GX FIFO accesses volatile because the write-gather
pipe is hardware. Remove the scalar identity helper and `opt_common_subs off`
workaround. These changes together preserve all 190 instruction words. The
packet's existing image/position/flags fields replace private byte padding and
word-offset casts.

`state/repairs/native_font_recovery_20261021.json` records the source hash,
compiler, registration correction, integration commit and verification evidence.

## Portable reproduction

    uv run tools/fzgx.py fixup --archive state/repairs/native_font_and_frontiers_20261021.json.gz

Expected: `{"reproduced": 4}`. Exactly one record is matched: `fn_10_266AC` under
GC/1.3.2. The other three are explicitly nonmatching compiler-backed frontiers,
not accepted source and not byte credit. Their exact C and compiler settings are
retained outside scratch/cache so another session can continue without repeating
these experiments:

- `fn_1_111980`, 5568 bytes: removed a real duplicate distance computation before
  applying the first cloth constraint; retained the second distance recomputation
  after height clamping; passed already-loaded particle pointers into the solver;
  corrected rounded radius-squared constants to measured retail float bits.
  Fresh result: 92.096985%, 659 word errors and 79 shape errors. FPR/stack pressure
  remains structural. A few meaningful vector-helper/array forms and local
  optimizer-option probes did not close it; stop that unchanged cohort.
- `fn_1_10069C`, 2864 bytes: GX color is passed by value. A real four-byte color
  struct replaces fake volatile scalar temporaries and pointer simulation;
  operand identity helpers are removed. The scale coefficient must have bits
  `3d4ccccc` (0.04999999701976776), not the rounded decimal `0.05f`.
  Fresh result: 96.25698%, 94 word errors and 14 shape errors. This is cleaner
  source, not a claim to beat every saved score. A fully external measured-constant
  view worsened codegen and was not accepted. The bounded native-source repair
  pass found no closure.
- `fn_80036AC4`, 352 bytes: retail implements an indirect-texture matrix setter:
  matrix-ID normalization, six scaled integer coefficients, split exponent bits,
  and three BP register writes. New assembly-derived native C reaches 86.079544%
  under GC/1.2.5n, with 60 word errors and 8 shape errors. The remaining conversion
  scratch-frame/scheduling mismatch is real. A hardware bitfield representation
  worsened codegen and was rejected. This does not recover the missing original
  source or justify reinstating its suspended credit.

The portable archive pins effective compiler versions rather than storing an
ambiguous module default. All records were recompiled/replayed against current
retail targets after restoring the build from the experiment below.

## Code-interior call evidence: measured, not integrated

The renderer's two apparent self-branches at function offsets `0x7B0` and `0x7D0`
are retail `REL24` relocations to `mathutil_mtxA_rotate_z + 12`, not two unknown
independent functions. The target entry is `0x8006E430`; retail instructions at
`0x8006E424` save LR, call the trig routine, and restore LR before falling through
to the paired-single sin/cos implementation.

A global label added only to the symbol configuration does NOT solve this: the
matching owner is marked `asm: true` and does not export the additional entry.
The real link failed to resolve the alias. The label experiment was reverted;
a complete subsequent build and all sixteen hashes passed. Never report the old
unchanged output hashes as proof of a failed new build. Future work must provide
a legitimate owner-export solution without new handwritten asm, hardcoded calls,
or moving interior code away from its owner. No alias/config change from that
experiment is retained.

## Other bounded work and verification

One external runner-bound Codex model session at depth one attempted
`fn_3_8A90`; it released without a match after 20 checks. A first setup attempt
failed the attempt-cap preflight before any model started. Only process-local
runner limits were used; no personal auth/config, provider/fleet configuration,
in-process subagents, or swarms were used.

A fresh licensed mfci donor build succeeded for all twelve compiler profiles,
but `fn_80059DD8` import failed a source/retail relocation mismatch and was not
submitted. A typed decoder-state reconstruction for `fn_12_27884` removed a
one-field carrier but did not resolve its register-color residual; no credit.

Final gates: complete `configure.py && ninja` after restoring the code-interior
experiment, all sixteen `dtk shasum` targets OK, zero lint findings, four portable
records replayed, and a fresh snapshot. The audit now reports 743 functions to
write and zero credited-but-unauthored functions. All manual claims were released.
Unrelated compiler-GC and storage-service edits remain untouched and uncommitted.
