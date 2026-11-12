#ifndef ADX_COMPILER_DIFF_H
#define ADX_COMPILER_DIFF_H

/* WARNING: compiler-diff device, not original code.
 *
 * CRI built the ADX decoders with a compiler build we do not have. Its entry-block instruction order and
 * register colouring are reproduced here by dead register writes: `mr r6, value` emits nothing, because r6
 * (the fourth argument register) is copied into its own register object when the function is entered, so a
 * later write to r6 is dead and MWCC deletes it before register colouring. Until then the write exists,
 * and it has two effects that survive it:
 *
 *   - `value` has a reader in the entry block, so the first instruction scheduling issues the instruction
 *     that defines `value` earlier (it is no longer a leaf of the dependency graph);
 *   - when `value` is the address of a stack-passed parameter, that parameter counts as escaped (its address
 *     reached a caller-saved register), so the final scheduling orders the parameter's load after the
 *     prologue's `stmw`, which may alias it.
 *
 * `value` must be a `register` variable or parameter. This is a macro, not an inline function, because an
 * inline function's parameter would be a register object of its own. The technique (not code) is the dead
 * `mr r6` consumers of the RE4 decomp's ADX_DecodeSte4AsMono (adonis-singh/re4, src/lib/adx_dcd5.c). */
#define ADX_COMPILER_DIFF_DEAD_WRITE(value) asm { mr r6, value }

#endif
