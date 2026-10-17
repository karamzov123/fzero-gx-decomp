# fn_4_8B3C: corrected option drawing frontier, not a match

Scope: manual `hermes-sol-option` lease on `fn_4_8B3C` only; no fleet or
OpenCode configuration changes. No canonical source, split, header or unit
registration was changed. The claim was released save-only at the plateau.

Portable source, compiler settings, complete preferred compiler receipt,
rejected search result and hash-gate output:
`state/repairs/option-8B3C-native-20261017.json`.

## Retail corrections

The saved C compiled at 76.9% raw objdiff similarity (68 differing rows of
179 aligned rows) under GC/1.3.2. The historical ledger said 77.2%; that is
not the fresh baseline.

- Retail converts `selection * 40 + 220` with signed xoris/bias subtraction;
  it does not negate the coordinate. Use s32 and a positive f32 conversion.
- The sine helper consumes only the signed angle in r3. The saved prototype
  invented three extra integer and five floating arguments from incidental
  live registers. Remove them rather than tuning allocation around them.
- State 3 branches directly to the epilogue; it must not run the two final
  calls. Return there.
- Use the existing 88-byte FontDrawPacket layout. The word at packet +0x38
  is color, alpha is +0x2c and flags is +0x30.
- Decode the pool literals from retail, then use the existing native-literal
  and shared-pool-primer generator. The measured prefix is 0x3f0 bytes.

A clean source using function-local `opt_propagation off/reset` and the angle
expression at the actual sine call reached 91.4% raw similarity, but still
has 75 differing rows of 164 aligned rows. The receipt reports 54.3% adjusted
instruction-row agreement. This is not a 91.4% instruction-exact function,
and the differing-row count has NOT improved from the initial baseline.
The shared base-register permutation affects many loads. Also unresolved:
BSS/data views that span separately named retail objects, and source
scheduling/address formation. Recover native ownership before submission.

GC/1.2.5n was also measured; it changes the frame/prologue and does not solve
this frontier. The retained source/settings are GC/1.3.2.

## Reject the deterministic-search best body

The one bounded public search returned a purported 91.0% improvement. Its
complete source and receipt are archived, but it is inadmissible:

- It widened/moved the byte at +0x285 into a word at +0x288.
- It changed selection accesses at +0x286/+0x284 into +0x284/+0x28c.
- It replaced the retail 260.0 coordinate with 320.0.
- It introduced tail_b_2, assigned only inside one nested path, then read it
  uninitialized by the final fn_1_13ABA8 call on other paths.
- It added allocator-only array-read and call-wrapper helpers.

Do not use the release best-body cache as the continuation source. Release
preserves the highest scored cache, not necessarily the admissible manual
source. The preferred source is explicit in the portable JSON. The final
attempt to restore it through write-unit was refused by the five-stale-check
plateau guard; that refused write has no new measurement. The JSON retains
the earlier successful preferred compiler receipt. No cap was bypassed.

## Verification and accounting

The source remains diagnostic/nonmatching and was NOT submitted or carved.
No linked C bytes or exact functions are credited.

After release, with no live claims or pending links, under oracle.build_lock:

    ninja build/GFZE01/ok       -> ninja: no work to do. (exit 0)
    build/tools/dtk shasum -q -c config/GFZE01/build.sha1
                               -> 16 files OK (exit 0)
    fzgx lint                  -> 0 finding(s) (exit 0)

This green gate validates the unchanged retail-fallback build, not execution
of the partial candidate. No game/runtime equivalence claim is made.
