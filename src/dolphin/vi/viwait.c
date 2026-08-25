typedef signed int s32;
typedef unsigned int u32;

extern s32 OSDisableInterrupts(void);
extern s32 OSRestoreInterrupts(s32 level);
extern void OSSleepThread(void*);

/* VI wait-for-retrace helper: sleeps on the queue at r13-0x7a94 until the
   retrace count at r13-0x7a9c changes. Carved from coarse/text_8001A8B4.c. */

#pragma push
#pragma force_active on

extern unsigned char lbl_801A6924[4];
extern unsigned char lbl_801A692C[8];

asm void VIWaitForRetrace(void)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x10(r1)
    stw     r31, 0xc(r1)
    stw     r30, 8(r1)
    bl      OSDisableInterrupts
    lwz	r30, lbl_801A6924
    mr      r31, r3
_8001af84:
    addi    r3, r13, lbl_801A692C
    bl      OSSleepThread
    lwz	r0, lbl_801A6924
    cmplw   r30, r0
    beq     _8001af84
    mr      r3, r31
    bl      OSRestoreInterrupts
    lwz     r0, 0x14(r1)
    lwz     r31, 0xc(r1)
    lwz     r30, 8(r1)
    addi    r1, r1, 0x10
    mtlr    r0
    blr
}

#pragma pop
