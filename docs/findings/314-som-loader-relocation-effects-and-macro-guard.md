# SOM loader fn_1_13B98: preserve relocation effects before allocation repair

Selected the 4,380-byte main_rel SOM loader and continued beyond the plateau under explicit owner authorization. Work was manual with one claim; no fleet settings were changed, no subagents were launched, and no canonical gameplay source was submitted.

## Saved near-match was not a safe seed

The fresh historical candidate compiled at about 96.6% raw / 81.7% adjusted with 202 differing rows. Its cached 97.07763% score was not a tiny-residual admission. The current stock target is 4,380 bytes; older documents referring to a 4,416-byte frontier are historical measurements.

Retail exposes two missing relocation stores in that draft:

- Root +0xB8: at retail 0x1468C, store the root-relative pointer after adding the root base. The draft only adjusted a local lab_v and never updated the root member.
- Group +0x0C: at retail 0x14A80, store the adjusted pointer before reading and fixing its +0x1C/+0x20 entries. The draft adjusted tmp_call72 and then read the unrelocated pointer again.

Restoring these writes produced the initial admissible candidate: GC/1.3.2, 96.52968% raw / 78.84% adjusted, 234 differing rows. This is a safety correction, not a claim that the wrong draft's higher score improved.

Recovered the native pair-bank layout: two seven-entry banks of 8-byte pointer/offset pairs at 0x28 and 0x7C, with columns/rows at 0x70/0x74. All stores remain full-width. Manual work and reviewed lifetime splitting produced the final admissible source at **96.863014% raw / 80.16% adjusted, 219 differing rows out of 1,104**. That reduces the corrected seed's residual by 15 rows. It is not an exact C match.

The final classification is 188 register-allocation, 17 instruction, five immediate, five relocation, four operand rows. Four accepted pool rows are separate from those residuals. Most of the work remaining is broad induction/address/lifetime structure, not a one-word or pool-only fix.

Resume `.fzgx/analysis/hermes-large-oct12/13b98-clean-frontier.c`, SHA-256 `4cef633a3d194c8bdb2ed793b2ba91aee67ef87a077511341fb6d282110f19d5`, compiler GC/1.3.2, no extra command-line flags. The portable source, retail assembly, full oracle rows, stock capture, rejected sources, regression fixture, and receipts are in `state/repairs/som-13b98-relocation-effects-and-macro-guard-20261012.json.gz`.

## Repair generator was deleting real stores

The existing call_results_to_locals generator parsed W(p, o) as a function call even though W is a dereferenced lvalue macro. Its "hold W result" transformation rewrote:

    W(p_2_2,12) += (u32)lbl_1_bss_3BE0;

into a temporary load and temporary addition, omitting the memory write. The first capture-backed search reintroduced this exact defect into a repaired seed, explaining why historical tmp_call scaffolding cannot be trusted as a source frontier.

Fixed this narrowly in tools/fzgx/fixup_source.py:

- Exclude function-like macros defined in the candidate from function-return hoisting.
- Exclude direct assignment/compound-assignment and postfix increment/decrement targets even when a macro comes from a header.
- Retain the normal rvalue nested-function-call transformations.

An external native-C regression went RED on the original generator: "hold W result in a local declared last" observed `32 6` instead of `288 6`. It went GREEN after the five-line patch. The original Git implementation was reloaded privately to reproduce RED again, then the live fix reran GREEN; no shared source was reverted or stashed.

Verification includes two generated native variants for the real compound-store pattern, 13 header-supplied lvalue operators with 26 generated native comparisons, and compilation of all 18 remaining call-result variants against the actual complete SOM source with MWCC. No W/F/H macro-result variants remain. The fixture lives outside the repository per AGENTS.md and its full source is preserved in the repair archive.

This is a generator safety repair, not a guarantee that every other candidate family or unknown macro is semantically correct.

## Search and admissibility

Two existing-engine runs evaluated 36,564 and 44,283 variant records (80,847 evaluations total, not unique sources), with zero exact results. The second run preserved the two critical stores and rejected one-member allocator carriers, known scaffold/reuse families, and changes to the original signed loop variables.

Even that guarded frontier still introduced narrower/unsigned NEW loop variables, which its name-based filter did not protect. Those results were rejected on full-source review: dynamic counts compared with cmpw require the original signed 32-bit loop domain. Restore both introduced counters to s32, remove the allocator-only array_read helper and dead loop copy-backs, and keep direct array accesses. The fresh cleaned result is the 219-row admissible frontier above, not the superficially better 218-row candidate.

Final stock capture reproduces the same ordinary compiler code/object, with zero capture/simplify errors. The archive retains this capture and the compiler-replayed verdict; the residual has not been claimed unreachable in general.

## Cache warning and gates

The own save-only release's highest-score cache remains the inadmissible historical baseline because it scored above the corrected source. Its release reason explicitly marks this. Do not resume from `.fzgx/attempts/fn_1_13B98.1791859980.c` or the global highest score without auditing it; use the explicit clean archive.

After release, the locked full build succeeded; independent DTK verification reported **16 files OK**; lint reported **zero findings**. Pre-existing protected edits were unchanged and no claims remained. These checks verify the existing retail-fallback reconstruction, not runtime integration of the partial C. No newly authored code bytes or exact C matches are credited.
