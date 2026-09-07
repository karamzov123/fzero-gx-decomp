#ifndef FZERO_DOLPHIN_OS_INTERRUPT_H
#define FZERO_DOLPHIN_OS_INTERRUPT_H

/*
 * Interrupt numbers and masks, read off the retail EXI handlers:
 * `subi r0, r3, 0x9 / 0xa / 0xb` for the three EXI-0 causes, and the mask bits
 * from `0x200000 >> (chan * 3)` (TC), `0x100000 >> (chan * 3)` (EXT) and
 * SetExiInterruptMask's 0x410000 / 0x80000 / 0x40.
 *
 * `short`, not an int enum: retail sign-extends the parameter with `extsh`.
 */
typedef short __OSInterrupt;

#define __OS_INTERRUPT_EXI_0_EXI 9
#define __OS_INTERRUPT_EXI_0_TC 10
#define __OS_INTERRUPT_EXI_0_EXT 11
#define __OS_INTERRUPT_EXI_1_EXI 12
#define __OS_INTERRUPT_EXI_1_TC 13
#define __OS_INTERRUPT_EXI_1_EXT 14
#define __OS_INTERRUPT_EXI_2_EXI 15
#define __OS_INTERRUPT_EXI_2_TC 16

#define OS_INTERRUPTMASK(intr) (0x80000000u >> (intr))

#define OS_INTERRUPTMASK_EXI_0_EXI 0x00400000u
#define OS_INTERRUPTMASK_EXI_0_TC 0x00200000u
#define OS_INTERRUPTMASK_EXI_0_EXT 0x00100000u
#define OS_INTERRUPTMASK_EXI_1_EXI 0x00080000u
#define OS_INTERRUPTMASK_EXI_1_TC 0x00040000u
#define OS_INTERRUPTMASK_EXI_1_EXT 0x00020000u
#define OS_INTERRUPTMASK_EXI_2_EXI 0x00010000u
#define OS_INTERRUPTMASK_EXI_2_TC 0x00008000u

#endif
