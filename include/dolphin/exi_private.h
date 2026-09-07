#ifndef FZERO_DOLPHIN_EXI_PRIVATE_H
#define FZERO_DOLPHIN_EXI_PRIVATE_H

#include <dolphin/exi.h>

/*
 * Retail EXIControl. Stride 0x40 is proven by `slwi rX, chan, 6` at every
 * &Ecb[chan] site. Member offsets verified against retail EXIBios.c asm:
 *   0x00 exiCallback   EXISetExiCallback stw r27,0x0(r30) / SetExiInterruptMask
 *   0x04 tcCallback    EXIImm stw r25,0x4(r31); TCIntrruptHandler lwz 0x4
 *   0x08 extCallback   EXIAttach stw r28,0x8(r30)
 *   0x0C state         every rlwinm./ori on 0xc
 *   0x10 immLen        TCIntrruptHandler lwz r3,0x10(r31)
 *   0x14 immBuf        TCIntrruptHandler lwz r5,0x14(r31)
 *   0x18 dev           EXILock stw r31,0x18(r30)
 *   0x1C id            EXIGetID / EXIAttach id cache
 *   0x20 idTime        EXIAttach lwz r0,0x20(r30) guard
 *   0x24 items         EXILock/EXIUnlock lwz 0x24
 *   0x28 queue[3]      EXILock stw r31,0x28(r3) / stw r28,0x2c(r3), stride 8
 */
typedef struct EXIControl {
    /* 0x00 */ EXICallback exiCallback;
    /* 0x04 */ EXICallback tcCallback;
    /* 0x08 */ EXICallback extCallback;
    /* 0x0C */ volatile u32 state;
    /* 0x10 */ int immLen;
    /* 0x14 */ u8* immBuf;
    /* 0x18 */ u32 dev;
    /* 0x1C */ u32 id;
    /* 0x20 */ s32 idTime;
    /* 0x24 */ int items;
    /* 0x28 */ struct {
        u32 dev;
        EXICallback callback;
    } queue[MAX_DEV];
} EXIControl;

extern EXIControl Ecb[MAX_CHAN]; /* .bss:0x8015CCB0 */

/*
 * OS globals at 0x800030C0: one probe timestamp per channel. Retail addresses
 * it absolutely (`lis 0x8000 / addi 0x30c0 / stwx`, no relocation), so it is an
 * address-placed array like __EXIRegs. The dolsdk2001 dump has not recovered
 * the name and calls it __gUnknown800030C0; mkdd's newer tree calls it
 * __EXIProbeStartTime. The alias lets either reference body splice unmodified.
 */
#define __gUnknown800030C0 __EXIProbeStartTime

/* mkdd-era spellings of the state bits, for reference bodies from that tree. */
#define EXI_STATE_ATTACHED STATE_ATTACHED
#define EXI_STATE_LOCKED STATE_LOCKED
#define EXI_STATE_SELECTED STATE_SELECTED

typedef char EXI_control_is_0x40_bytes[(sizeof(EXIControl) == 0x40) ? 1 : -1];

#endif
