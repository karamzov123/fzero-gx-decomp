# Large option functions: safe source and pool layout

## Result and scope

Manual work on two large unmatched option REL functions, 5,540 retail bytes total. No exact C match and no newly authored byte credit. Neither candidate was submitted to canonical source. Existing source/config/header edits were preserved. Fleet stayed inactive.

Portable candidate bodies, retail assembly, source SHA-256 hashes, and exact compiler-check receipts are stored in `state/repairs/large-option-safe-source-20261012.json.gz`. Both candidates use GC/1.3.2 and no extra command-line flags. To resume, extract the explicitly named record's `source`; do not trust the ledger's highest-score body without checking source safety.

## fn_4_C768: 2,624 bytes

Fresh archived literal-body baseline: 92.8% raw similarity; 151 differing rows. Historical helpers returned a pointer to the array of a by-value local struct: a dangling pointer. Direct accesses to the actual local packet remove that undefined behavior. The retail loop comparison is unsigned; the local index was corrected accordingly.

The existing `shared_pool_primer` engine reconstructed the actual 0x820-byte literal-pool layout rooted at lbl_4_rodata_410. With the unsafe helpers removed, this produced 94.5% raw and 64 differing rows. The primer is project layout infrastructure, not authored game logic or a liveness helper.

Further source changes followed the actual retail operations:

- Explicit case 0 in the menu dispatch.
- Width-preserving byte-to-rotation conversion.
- Correct packet-store order around the sine call and color packet.
- A real 20-byte name row: u16 index, u16 field, three text pointers, final label pointer.
- Coordinate conversion before the following y/z stores, as in retail.

Final admissible `coords.c`: 96.5% raw similarity, 94.25% adjusted similarity, 38 differing rows out of 661. Residual classes: 13 instruction, 9 register-allocation, 7 operand, 7 immediate, 2 frame. This reduces the fresh baseline residual by 113 rows. It is not an exact match.

Rejected or neutral probes are retained locally: full named FontDrawPacket rewriting regressed; changing byte color locals to u32 was neutral. The 16-check budget ended this attempt. No budget increase or same-context retry was performed.

Local archive: `.fzgx/analysis/hermes-large-oct12/coords.c`.

## fn_4_BC04: 2,916 bytes

Fresh historical baseline: 85.3% raw, 60.08% adjusted, 309 differing rows. GC/1.2.5n was worse (47.0% adjusted) than GC/1.3.2.

The archived source contains an unreachable assignment between switch cases. Case 1 uses that uninitialized `fzgx_live` pointer. It is inadmissible even though it scores better. Replace it with the actual `e->p8` lookup shown by the retail assembly. The retail epilogue does not generate a floating-point return value; the reconstructed function is void. Reducible early exits now use return rather than goto. Redundant pointer-to-pointer aliases were removed.

Removing the prior common-subexpression pragma regressed materially. The safe source preserving the prior optimization setting compiled at 85.4% raw, 58.29% adjusted, 322 differing rows out of 772 (207 register-allocation, 73 instruction, 22 immediate, 20 operand). This is a source-safety correction, not a matching-progress claim. The highest-score ledger cache still selects the unsafe historical candidate, so do not resume from it automatically.

Stopped at the engine's five-consecutive-no-improvement plateau, without overriding the guard. The final declaration-order hypothesis was refused by the guard and therefore has no measured result.

Local admissible archive: `.fzgx/analysis/hermes-large-oct12/BC04-safe-nocse.c`.

## Repository gates

After releasing both claims, ran the full locked `ninja build/GFZE01/ok` gate and independent DTK SHA-1 verification: all 16 files OK. Repository lint: zero findings. Build output includes existing linker warnings and missing-source/configuration notices but the build and checksum gate succeeded. This verifies the existing project reconstruction, not either nonmatching candidate.

One depth-1 in-process agent was briefly dispatched, then interrupted because repository AGENTS.md forbids that method. No delegated candidate was used; all reported candidate edits and compiler results above were produced by the parent manually. No claims remained at verification.
