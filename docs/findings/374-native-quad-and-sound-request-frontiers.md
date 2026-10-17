# Finding 374: fresh native quad and sound-request reconstructions

Ten explicit oracle checks over two targets, plus normal deterministic repair
at release (3+2 render checks across two attempts, five sound checks). No exact
match was submitted in this pass. Both claims are released. Do not count the
near-matches as authored functions.

Preferred source bodies, identities and retention notes are portable:

    state/repairs/manual-native-quad-and-sound-request-20261017.json

The two records preserve the manually verified native source shapes, not the
automatic release candidates. Their hashes are verified from the actual C;
release-selected hashes/compiler sidecars are recorded separately.

## fn_80008204: full-screen quad, 740 bytes

Fresh source reconstructed from all 185 retail instructions and matched
neighbors fn_800084E8 / fn_800087F4. The mechanical skeleton invents live-in
floating parameters; retail only consumes a packed color pointer and gets
its ten-float projection block through fn_80038BFC. Keep the signature void.

Covers all GX state calls, two packed color copies, the single-case projection
switch, perspective/orthographic depth equations, matrix setup, and twelve
ordered float FIFO writes. The hardware macro is from hw_regs.h and the
volatile accesses have a hardware-ordering justification; no inline asm,
handcrafted bytes, or raw address literals were added.

- First native draft: 97.6%, 52 differing rows / 185 aligned, exact 0x90 frame.
- Separate near/far/ratio scalars: 54 rows; not an improvement.
- Named branch-local normalized rectangle offsets fix multiply operand order:
  97.86487%, 52 rows, ALL remaining differences are FPR allocation. Every
  instruction form and non-FP operand aligns.
- Aggregate bounds, then axis arrays x[2]/y[2]/depth: both 54 FPR rows, identical
  machine code. These are one source-shape experiment, not evidence to keep
  permuting fields. Need an actual FPR allocator / inlining witness.

IMPORTANT: the second release selected 98.10811%, but source readback showed
`void` changed to `u32` plus `return (u32)channel1;`, generated live-through
copies, and additional pragmas. The return changes live-out behavior without
ABI evidence. Reject it as the preferred frontier despite its higher score.
The portable record retains the clean scalar-offset void source. No accepted
source or compiler pin was changed.

## fn_1_A2210: sound request, 700 bytes

Fresh native C follows the sound state offsets, cue and filename tables,
invalid/sentinel handles, fade/volume flags, file change, ADXT pause, command
construction and queued request updates. Reuse finding 372's short-circuit
OR guard witness: the last unsigned byte test gets the retail beq/b pair.

- Entry-initialized table pointers survive calls and inflate the frame to0x30:
  first draft 69.2%, 120 differences /192 aligned.
- Short-lived direct table expressions restore exact0x20 frame and the four
  retail saved GPRs (r28 request, r29 command, r30 handle, r31 state).
- Byte-array cue lookup for the ID, struct view for command, and a word request
  variable with explicit initial u8 indexing reproduce lbzx/add/lha and the
  later full-word slwi. Keeping all table pointers live was the root cause,
  not a declaration-order problem.
- Preferred manual scoped-lookup draft: 28 true differing rows /180 aligned;
  raw similarity92.7%, rounded adjusted84.4% after pool accounting.
- Remaining: two integer-to-float volume conversions' scheduling/base homes,
  second-volume base ADDI folded into +0x886, and queued/request-flag scratch
  register homes. Integer value before conversion is better than a held f32
  result; getter/setter/queue helpers do not close those differences.

The final release chose the f32-result helper body at91.994286%, with44 true
rows rather than28. Its arithmetic is not the same ABI defect as the render
return trial, but prefer the fewer-difference integer-volume manual source.
The portable score is explicitly the rounded manual adjusted score; do not
compare it directly with the release's differently accounted similarity.

## Operational lessons and scope

- Preserve return ABI and native semantics before trusting automatic best
  selection. A higher score can be purchased with a spurious live-out.
- Capture long CLI output directly to scratch, then read its sections. A
  terminal tool's auto-truncated head/tail text is not a source artifact.
- No shared source/TU, compiler pin, repair tool or startup-policy changes.
- No fleet or subagents spawned. OpenCode is an independent existing worker;
  non-resuming coordination notes announced ownership and released targets.
- OpenCode's commits through finding373 were preserved, including its newly
  verified fn_10_1B2F4. Do not attribute that match to this pass.
