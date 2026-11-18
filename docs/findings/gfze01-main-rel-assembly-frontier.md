# GFZE01 main_rel: three standalone assembly reconstructions

Audited against `6843bd5f1` and the extracted GFZE01 retail objects. Preserve the existing exact assembly while source origin or native codegen remains unresolved.

| Symbol | Evidence | Disposition |
| --- | --- | --- |
| `fn_1_4B6D4` | Updates font bounds with scalar loads, comparisons and an unsigned-byte-to-float conversion through the `0x4330` stack constant. The exact native-C residual documented in [the pool census](near-match-pool-census-20261026.md) is two exchanged prologue words: retail puts the bounds `lis` before frame setup. | Strong C candidate, not evidence of original assembly. Revisit both font helpers together if new evidence explains how the retail compiler schedules before frame setup. Do not repeat the existing flag/compiler sweep or copy the prologue into C as asm. |
| `fn_1_4B788` | Companion bounds update, called by the same font routine, with the same two-word scheduling residual. | Same disposition. |
| `fn_1_9DFB8` | Cached keyframe curve evaluator: 20-byte key stride, signed cursor in `r5`, derivative selector in `r6`, time and return value in `f1`. Its sibling `fn_1_9DDA8` already builds from C, whereas `fn_1_9DFB8` uses six `bCC+` static branch hints, two self-XOR register zeroes (`xor r9,r9,r9`, `xor r7,r7,r7`), direct locked-cache `0xE000019C` constant loads via clobbered parameter `r6`, and a dead duplicate branch after `b .L_0009E074`. | **Evidenced original assembly (`evidenced-assembly`)**. Closed by corpus-wide MWCC instruction evidence below; retain existing `.s` under `docs/ASM_POLICY.md`. |

The audit did recover the C boundary around the evaluator. The three retail wrappers preserve the incoming `f1`, set the derivative selector in `r5` for `fn_1_9DDA8` or `r6` for `fn_1_9DFB8`, and return the callee's `f1`. Call sites in `burner.c` consume the floating-point result of `fn_1_9E170`. The wrapper definitions now say that explicitly; the earlier declarations happened to preserve the register traffic while omitting the floating-point argument and result in C. This is source/ABI cleanup, not a conversion of any of the three assembly bodies.

## Font pair follow-up

Independently compiled a minimal C implementation of both bounds updates with GC/1.3.2, `-O4,p -fp_contract off -sdata 0 -sdata2 0`. The two updates differ only in their BSS owner (`lbl_1_bss_4BA30` versus `lbl_1_bss_4BA44`); each compares the x/y origin and updates the right/bottom extents from the advance and scaled unsigned glyph height.

* With scheduling enabled, both `-proc gekko` and `-proc 750` emitted 45 words per symbol. Against the extracted retail objects, only words 0 and 1 differed: candidate `stwu; lis`, retail `lis; stwu`. The BSS high-half relocation moves with the `lis`. The raw C probe emitted its own conversion bias rather than binding the retail constant; this is an instruction-word comparison, not a link match.
* Defining both BSS owners in the same probe TU, testing volatile access as a diagnostic, and enabling common subexpression optimization each left the same two-word residual under Gekko scheduling. None is proposed as a source change. Disabling scheduling or scheduling for `603e`/`604e` made the body diverge further.

Two compiled C controls in the same module, `fn_1_66254` and `fn_1_EB0D8`, have retail-identical instruction words and start with a relocated `lis` before the same 16-byte frame setup. Both materialize the global base in a different register (`lis r5; …; addi r6,r5` and `lis r4; …; addi r7,r4`), unlike the font pair's `lis r6; …; addi r6,r6`. Explicitly using a bounds pointer for the first update left the two-word residual; using one pointer for all four updates folded repeated address loads and produced 39 words, still with `stwu` first. The controls rule out a blanket prohibition against scheduling before the frame, but do not isolate the reason for the font ordering.

Keep both linked assembly implementations. Reopen with a control that produces a moved `lis` with a same-register address materialization, or scheduler-phase evidence that accounts for the distinction. Another spelling/flag sweep is not warranted by these results.

## Curve evaluator `fn_1_9DFB8` origin audit (`evidenced-assembly`)

Audited `src/rel/main_rel/background/fn_1_9DFB8.s` against the full 7,351-function GFZE01 corpus. Four independent instruction and relocation proofs establish that `fn_1_9DFB8` is hand-written CodeWarrior assembly rather than compiler output:

1. **Six static branch prediction hints (`bCC+`, BO hint bit `0x00200000`)**: `bgt+` (`0x9DFEC`), `blt+` (`0x9DFFC`), `bgt+` (`0x9E028`), `ble+` (`0x9E058`), `bne+` (`0x9E080`), and `bne+` (`0x9E090`). Across all 7,159 C-compiled functions in GFZE01, MWCC **never** emits `bCC+` (`0/7,159`); every function in the binary carrying static branch hints is hand-written assembly.
2. **Self-XOR integer zeroing**: `xor r9, r9, r9` (`0x9DFF0`) and `xor r7, r7, r7` (`0x9E130`). MWCC zeroes GPRs with `li rX, 0` (`addi`); self-XOR zeroing appears in `0/7,159` non-inline-asm C functions.
3. **Locked-cache `0xE000019C` constant read via `r6` with zero `.rodata` relocations**: In the interior interpolation paths, `fn_1_9DFB8` executes `lis r6, 0xe000` (`0x9E074`) followed by `lfs f9, 0x19c(r6)` (`0x9E0AC`, `0x9E0E8`) to fetch `1.0f` from the `mathutil` locked-cache scratchpad—reusing parameter register `r6` (`derivative`, which is only inspected on the boundary exit at `0x9E13C`) and emitting zero `.rodata` relocations, unlike its C sibling `fn_1_9DDA8` (`lbl_1_rodata_4788`).
4. **Dead branch preserved after unconditional branch**: `0x9E048: b .L_0009E074` is followed immediately by unreachable `0x9E04C: b .L_0009E05C` before `.L_0009E050`; MWCC dead-code elimination removes unreachable trailing branches from C codegen.
