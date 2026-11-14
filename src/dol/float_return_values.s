.include "macros.inc"
.file "float_return_values.c"

# Assembly by evidence (docs/ASM_POLICY.md section 1). CodeWarrior asm function with entry labels.
# Shared float returns of the square-root routines: each entry loads the bit pattern of NaN, 0.0f or
# +inf into f1 through the stack. Entries _return_zero, _return_inf, _sqrt_return_special and
# _rsqrt_return_special; the two *_return_special entries pick one from cr1 after the caller's
# mcrfs (bgt: +inf/0, blt: 0/+inf, else NaN). The word after _return_inf (-inf) is never reached.
# - Four further global entry points. Callers reach them directly. Each one follows an
#   unconditional `b` or `blr`. The routine keeps the dead -inf word. Only assembly does this.
#   Measured 2026-11-12 (x1 probes): MWCC deletes inline-asm code unreachable from the function's own
#   entry (GC/1.2.5n, 1.3.2, 2.6; opt_dead_code, peephole, optimization_level 0), `entry`/`nofralloc`
#   are rejected outside an asm function, and a C function cannot emit a global symbol at an interior
#   offset (an ldscript alias makes `dtk rel make` panic, rel.rs:240).
# - Source: Super Monkey Ball (same engine) has only an asm version, float_return_values,
#   under `#ifdef __MWERKS__`:
#   https://github.com/camthesaxman/smb-decomp/blob/5cd6ffccf3f8508231c7cd9cce5b722be4465a2b/src/mathutil.c#L75-L96

# 0x8006D044..0x8006D088 | size: 0x44
.text
.balign 4

# .text:0x0 | 0x8006D044 | size: 0x44
.fn float_return_values, global
/* 8006D044 0006A044  3C 00 7F FF */	lis r0, 0x7fff
/* 8006D048 0006A048  48 00 00 18 */	b .L_8006D060
# .text:0x8 | 0x8006D04C | size: 0x0
.sym _return_zero, global
/* 8006D04C 0006A04C  38 00 00 00 */	li r0, 0x0
/* 8006D050 0006A050  48 00 00 10 */	b .L_8006D060
# .text:0x10 | 0x8006D054 | size: 0x0
.sym _return_inf, global
/* 8006D054 0006A054  3C 00 7F 80 */	lis r0, 0x7f80
/* 8006D058 0006A058  48 00 00 08 */	b .L_8006D060
/* 8006D05C 0006A05C  3C 00 FF 80 */	lis r0, 0xff80
.L_8006D060:
/* 8006D060 0006A060  94 01 FF F0 */	stwu r0, -0x10(r1)
/* 8006D064 0006A064  C0 21 00 00 */	lfs f1, 0x0(r1)
/* 8006D068 0006A068  38 21 00 10 */	addi r1, r1, 0x10
/* 8006D06C 0006A06C  4E 80 00 20 */	blr
# .text:0x2C | 0x8006D070 | size: 0x0
.sym _sqrt_return_special, global
/* 8006D070 0006A070  41 85 FF E4 */	bgt cr1, _return_inf
/* 8006D074 0006A074  41 84 FF D8 */	blt cr1, _return_zero
/* 8006D078 0006A078  4B FF FF CC */	b float_return_values
# .text:0x38 | 0x8006D07C | size: 0x0
.sym _rsqrt_return_special, global
/* 8006D07C 0006A07C  41 85 FF D0 */	bgt cr1, _return_zero
/* 8006D080 0006A080  41 84 FF D4 */	blt cr1, _return_inf
/* 8006D084 0006A084  4B FF FF C0 */	b float_return_values
.endfn float_return_values
