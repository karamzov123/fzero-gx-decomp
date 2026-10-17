# Finding 370: semantic corrections before source-shape closure

Manual continuation alongside the independent OpenCode worker. No new exact
matches in this pass; authored progress remains unchanged. Nineteen explicit
oracle checks across four functions (ledger counts 5 + 6 + 4 + 4), followed
by the normal deterministic release/repair lifecycle. All claims released.
Each target reached attempt three and is blocked for evidence-led triage,
not for unchanged retry/permutation sweeps.

Portable preferred C bodies, SHA-256 identities, compiler sidecars, scores,
and notes:

    state/repairs/manual-reset-rings-sound-and-selection-20261017.json

The bundle contains exactly four unmatched records. Three are byte-identical
to release-selected bodies with verified sidecar hashes. The selection-panel
record deliberately retains the manual semantic repair instead; see below.
Percentages are source-similarity measurements, not authored progress.

## main_rel fn_1_E9CFC (1560 bytes)

Saved source had k=5..1 and wrote zero to the halfword reset array. Retail
covers indices 0..4 and stores -1. Corrected extent, direction and sentinel.
The final 127-record clearing loop needs explicit byte-pointer induction,
not a multiply/add at every call. Saved candidate: 96.86667%.

Manual best has 59 differing rows / 391 aligned: reset addresses flatten
into offsets from bss instead of retaining three array bases, plus the last
loop's r14/r15 pointer/counter mirror. The entire middle resource/free loop
matches, including 16 pointer webs and its spill. Removing stale loop
pragmas, extracting the reset into an inline helper, and spelling typed
array fields all produce the same residual. Require a real source/TU base-CSE
witness before retrying.

## customize fn_3_1B130 (908 bytes)

Corrected xs to 4096 elements (instead of 4134), matching the retail 0x4060
frame. Restored modulo-4096 source wraparound for both queue indices instead
of plain narrowing casts. Documented the packed RGBA union representation.
Saved candidate: 97.77093%; 18 differing rows / 229 aligned.

Residual is the initial channel-compare load/store schedule and six operand
mirrors in horizontal scan comparisons. Queue/tail code is otherwise aligned.
Channel type promotion worsens allocation; explicit channel temporaries and
commuting equalities change nothing; a widened inline reader adds masks;
hoisting the initial red channel adds a duplicate shift. Stop after the
five-stale-check policy. Need compare value-flow/code-motion evidence.

## main fn_8005D258 / SndExpCurveLookup (844 bytes)

Fresh archived body: base similarity 97.8%, adjusted 95.31%, only ten true
rows differ after six pool-relocation equivalences. Compiler GC/1.3.2.

Six differences concern initial loop-bound/shift homes; four are tail
scheduling. Native dtk object disassembly confirms ours:

    fctiwz; add; stfs; stfd; lwz; sth

versus retail:

    fctiwz; stfs; add; sth; stfd; lwz

Removing the dead mask and holding the adjustment worsens initial homes;
extracting a pointer-advance helper adds scheduling/register differences;
reading the float output back introduces a real reload and FP changes.
Saved original valid body, not a non-exact rewrite. Need a dependency/lifetime
witness; avoid more compiler-flag/declaration enumeration.

## sel fn_10_1B6CC (1540 bytes)

Read the actual archive, not a truncated context rendering. Removed the
rejected temporary-result scaffolding. Corrected sprintf format from data
base +0x43 to retail +0x5628; +0x43 is the packet's destination text offset.
Corrected lbl_801A66C0 from s16 to u32: symbol extent is four bytes and retail
uses lwz/cmplwi plus unsigned integer-to-float conversion.

Preferred manual candidate: 97.03636%, 27 differing rows / 388 aligned.
Remaining causes include scalar/base address lowering, generated conversion
literal versus the shared float pool, first packet FP homes, and final packet
multiplication/argument setup. Named float locals do not close it; holding a
text pointer raises the saved register set to _savegpr_25 and regresses.

IMPORTANT: release selected 97.075325%, but source readback revealed a semantic
regression: s16 timer, wrong +0x43 format, u8 packet field at +8, and u16 field
at +0x14 where retail stores words. Reject it despite the higher score. The
portable record preserves the manual u32/0x5628/full-word body and records the
rejected candidate's hash and reason. The ledger block explicitly warns not
to treat the local release-selected archive as the preferred source. Shared
repair tooling was not changed while OpenCode was using the checkout.

## Verification and coordination

- Candidate bundle hashes verified against actual saved C/sidecars; preferred
  manual selection source checked separately before replacing that record.
- Current authored-tree lint: 0 finding(s).
- Current linked dtk checksum verification: 16 files OK.
- Honest closure: 1480 functions remain; no authored-count change this pass.
- OpenCode received non-resuming synthetic coordination notes identifying the
  active symbol and released targets. Its commits/targets were preserved.
- No source/TU, compiler pin, startup policy, fleet or shared tool changes.
- No push. No new agents were spawned.
