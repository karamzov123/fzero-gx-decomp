# GFZE01 main_rel: three standalone assembly reconstructions

Audited against `6843bd5f1` and the extracted GFZE01 retail objects. Preserve the existing exact assembly while source origin or native codegen remains unresolved.

| Symbol | Evidence | Disposition |
| --- | --- | --- |
| `fn_1_4B6D4` | Updates font bounds with scalar loads, comparisons and an unsigned-byte-to-float conversion through the `0x4330` stack constant. The exact native-C residual documented in [the pool census](near-match-pool-census-20261026.md) is two exchanged prologue words: retail puts the bounds `lis` before frame setup. | Strong C candidate, not evidence of original assembly. Revisit both font helpers together if new evidence explains how the retail compiler schedules before frame setup. Do not repeat the existing flag/compiler sweep or copy the prologue into C as asm. |
| `fn_1_4B788` | Companion bounds update, called by the same font routine, with the same two-word scheduling residual. | Same disposition. |
| `fn_1_9DFB8` | Cached keyframe curve evaluator: 20-byte key stride, signed cursor in `r5`, derivative selector in `r6`, time and return value in `f1`. Its sibling `fn_1_9DDA8` already builds from C. The cached implementation also has explicit zeroing via self-XOR, branch hints, and hard-coded `0xe000019c` loads in the interpolation paths. | Possible hand-tuned implementation, not established original assembly. Keep the existing `.s` until newer compiler or source-origin evidence discriminates. Do not use the hard-coded address as a natural-C reconstruction. |

The audit did recover the C boundary around the evaluator. The three retail wrappers preserve the incoming `f1`, set the derivative selector in `r5` for `fn_1_9DDA8` or `r6` for `fn_1_9DFB8`, and return the callee's `f1`. Call sites in `burner.c` consume the floating-point result of `fn_1_9E170`. The wrapper definitions now say that explicitly; the earlier declarations happened to preserve the register traffic while omitting the floating-point argument and result in C. This is source/ABI cleanup, not a conversion of any of the three assembly bodies.
