typedef int s32;
typedef unsigned int u32;
typedef void OSContext;
typedef void (*EXICallback)(s32 chan, OSContext* context);

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(register int level);
extern u32 __OSMaskInterrupts(u32 mask);
extern u32 __OSUnmaskInterrupts(u32 mask);
extern void __OSSetInterruptHandler(s32 interrupt, void* handler);
extern void* __OSGetInterruptHandler(s32 interrupt);
extern void OSRegisterVersion(const char* version);
extern u32 __OSGetDIConfig(void);
extern u32 OSGetConsoleType(void);
extern unsigned long long OSGetTime(void);
extern u32 __div2i(register u32 hi, register u32 lo, register u32 den_hi,
                       register u32 den_lo);
extern void* memmove(void* dst, const void* src, u32 len);

/*
 * Near globals (.sbss/.sdata) are referenced through the r13 small-data
 * anchor with hand-resolved displacements (.sdata base 0x801A63C0 + 0x8000).
 */
extern unsigned char Ecb[]; /* .bss:0x8015CCB0, 3 x 0x40-byte control blocks */

/* forward declarations */
extern void SetExiInterruptMask(register s32 chan, register void* exi);
extern u32 EXIClearInterrupts(register s32 chan, register int exi,
                              register int tc, register int ext);
extern int __EXIProbe(register s32 chan);
extern int EXILock(register s32 chan, register u32 dev,
                   register EXICallback unlockedCallback);
extern int EXISelect(register s32 chan, register u32 dev, register u32 freq);
extern int EXIImm(register s32 chan, register void* buf, register s32 len,
                  register u32 type, register EXICallback callback);
extern int EXISync(register s32 chan);
extern int EXIDeselect(register s32 chan);
extern int EXIUnlock(register s32 chan);
extern u32 EXIGetID(register s32 chan, register u32 dev, register u32* id);
extern void EXIIntrruptHandler(register s32 interrupt, register OSContext* context);
extern void TCIntrruptHandler(register s32 interrupt, register OSContext* context);
extern void EXTIntrruptHandler(register s32 interrupt, register OSContext* context);
extern void UnlockedHandler(register s32 chan, register OSContext* context);
extern void OSClearContext(OSContext* context);
extern void OSSetCurrentContext(OSContext* context);
extern void __OSEnableBarnacle(register s32 chan, register u32 dev);
extern int EXIProbe(register s32 chan);
extern int EXIDma(register s32 chan, register void* buf, register s32 len,
                  register u32 type, register EXICallback callback);
extern int __EXIGetID(register s32 chan, register u32 dev, register u32* id);
extern int EXIDetach(register s32 chan);

/* ---- SetExiInterruptMask ---- */
#pragma push
#pragma force_active on
extern unsigned char IDSerialPort1[4];
extern unsigned char __EXIVersion[4];
extern unsigned char __OSInIPL[4];
extern unsigned char lbl_801A6840[4];
extern unsigned char lbl_801A6844[4];
extern unsigned char lbl_801A6848[4];
extern unsigned char lbl_801A684C[4];
asm void SetExiInterruptMask(register s32 chan, register void* exi)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x18(r1)
    stw         r31, 0x14(r1)
    addi        r31, r4, 0x0
    lis         r4, Ecb@ha
    addi        r4, r4, Ecb@l
    addi        r4, r4, 0x80
    cmpwi       r3, 0x1
    beq         L_80013B08
    bge         L_80013AC0
    cmpwi       r3, 0x0
    bge         L_80013ACC
    b           L_80013B68
L_80013AC0:
    cmpwi       r3, 0x3
    bge         L_80013B68
    b           L_80013B38
L_80013ACC:
    lwz         r0, 0x0(r31)
    cmplwi      r0, 0x0
    bne         L_80013AE4
    lwz         r0, 0x0(r4)
    cmplwi      r0, 0x0
    beq         L_80013AF0
L_80013AE4:
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 27, 27
    beq         L_80013AFC
L_80013AF0:
    lis         r3, 0x41
    bl          __OSMaskInterrupts
    b           L_80013B68
L_80013AFC:
    lis         r3, 0x41
    bl          __OSUnmaskInterrupts
    b           L_80013B68
L_80013B08:
    lwz         r0, 0x0(r31)
    cmplwi      r0, 0x0
    beq         L_80013B20
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 27, 27
    beq         L_80013B2C
L_80013B20:
    lis         r3, 0x8
    bl          __OSMaskInterrupts
    b           L_80013B68
L_80013B2C:
    lis         r3, 0x8
    bl          __OSUnmaskInterrupts
    b           L_80013B68
L_80013B38:
    li          r3, 0x19
    bl          __OSGetInterruptHandler
    cmplwi      r3, 0x0
    beq         L_80013B54
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 27, 27
    beq         L_80013B60
L_80013B54:
    li          r3, 0x40
    bl          __OSMaskInterrupts
    b           L_80013B68
L_80013B60:
    li          r3, 0x40
    bl          __OSUnmaskInterrupts
L_80013B68:
    lwz         r0, 0x1c(r1)
    lwz         r31, 0x14(r1)
    addi        r1, r1, 0x18
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXIImm ---- */
#pragma push
#pragma force_active on
asm int EXIImm(register s32 chan, register void* buf, register s32 len,
               register u32 type, register EXICallback callback)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x40(r1)
    stmw        r25, 0x24(r1)
    addi        r26, r3, 0x0
    addi        r27, r4, 0x0
    addi        r28, r5, 0x0
    addi        r29, r6, 0x0
    addi        r25, r7, 0x0
    slwi        r4, r3, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r31, r0, r4
    bl          OSDisableInterrupts
    mr          r30, r3
    lwz         r0, 0xc(r31)
    clrlwi.     r0, r0, 30
    bne         L_80013BD0
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 29, 29
    bne         L_80013BE0
L_80013BD0:
    mr          r3, r30
    bl          OSRestoreInterrupts
    li          r3, 0x0
    b           L_80013DC4
L_80013BE0:
    stw         r25, 0x4(r31)
    lwz         r0, 0x4(r31)
    cmplwi      r0, 0x0
    beq         L_80013C14
    addi        r3, r26, 0x0
    li          r4, 0x0
    li          r5, 0x1
    li          r6, 0x0
    bl          EXIClearInterrupts
    lis         r3, 0x20
    mulli       r0, r26, 0x3
    srw         r3, r3, r0
    bl          __OSUnmaskInterrupts
L_80013C14:
    lwz         r0, 0xc(r31)
    ori         r0, r0, 0x2
    stw         r0, 0xc(r31)
    cmplwi      r29, 0x0
    beq         L_80013D68
    li          r0, 0x0
    li          r4, 0x0
    cmpw        r4, r28
    bge         L_80013D54
    subi        r6, r28, 0x8
    cmpwi       r28, 0x8
    ble         L_80013DBC
    addi        r3, r27, 0x0
    addi        r5, r6, 0x7
    srwi        r5, r5, 3
    mtctr       r5
    cmpwi       r6, 0x0
    ble         L_80013DBC
L_80013C5C:
    lbz         r6, 0x0(r3)
    subfic      r5, r4, 0x3
    slwi        r5, r5, 3
    slw         r5, r6, r5
    or          r0, r0, r5
    lbz         r6, 0x1(r3)
    addi        r5, r4, 0x1
    subfic      r5, r5, 0x3
    slwi        r5, r5, 3
    slw         r5, r6, r5
    or          r0, r0, r5
    lbz         r6, 0x2(r3)
    addi        r5, r4, 0x2
    subfic      r5, r5, 0x3
    slwi        r5, r5, 3
    slw         r5, r6, r5
    or          r0, r0, r5
    lbz         r6, 0x3(r3)
    neg         r5, r4
    slwi        r5, r5, 3
    slw         r5, r6, r5
    or          r0, r0, r5
    lbz         r6, 0x4(r3)
    addi        r5, r4, 0x4
    subfic      r5, r5, 0x3
    slwi        r5, r5, 3
    slw         r5, r6, r5
    or          r0, r0, r5
    lbz         r6, 0x5(r3)
    addi        r5, r4, 0x5
    subfic      r5, r5, 0x3
    slwi        r5, r5, 3
    slw         r5, r6, r5
    or          r0, r0, r5
    lbz         r6, 0x6(r3)
    addi        r5, r4, 0x6
    subfic      r5, r5, 0x3
    slwi        r5, r5, 3
    slw         r5, r6, r5
    or          r0, r0, r5
    lbz         r6, 0x7(r3)
    addi        r5, r4, 0x7
    subfic      r5, r5, 0x3
    slwi        r5, r5, 3
    slw         r5, r6, r5
    or          r0, r0, r5
    addi        r3, r3, 0x8
    addi        r4, r4, 0x8
    bdnz        L_80013C5C
    b           L_80013DBC
L_80013D24:
    subf        r3, r4, r28
    mtctr       r3
    cmpw        r4, r28
    bge         L_80013D54
L_80013D34:
    lbz         r5, 0x0(r6)
    subfic      r3, r4, 0x3
    slwi        r3, r3, 3
    slw         r3, r5, r3
    or          r0, r0, r3
    addi        r6, r6, 0x1
    addi        r4, r4, 0x1
    bdnz        L_80013D34
L_80013D54:
    lis         r3, 0xCC00
    addi        r4, r3, 0x6800
    mulli       r3, r26, 0x14
    add         r3, r4, r3
    stw         r0, 0x10(r3)
L_80013D68:
    stw         r27, 0x14(r31)
    cmplwi      r29, 0x1
    beq         L_80013D7C
    mr          r0, r28
    b           L_80013D80
L_80013D7C:
    li          r0, 0x0
L_80013D80:
    stw         r0, 0x10(r31)
    slwi        r0, r29, 2
    ori         r3, r0, 0x1
    subi        r0, r28, 0x1
    slwi        r0, r0, 4
    or          r4, r3, r0
    lis         r3, 0xCC00
    addi        r3, r3, 0x6800
    mulli       r0, r26, 0x14
    add         r3, r3, r0
    stw         r4, 0xc(r3)
    mr          r3, r30
    bl          OSRestoreInterrupts
    li          r3, 0x1
    b           L_80013DC4
L_80013DBC:
    add         r6, r27, r4
    b           L_80013D24
L_80013DC4:
    lwz         r0, 0x44(r1)
    lmw         r25, 0x24(r1)
    addi        r1, r1, 0x40
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXIImmEx ---- */
#pragma push
#pragma force_active on
asm int EXIImmEx(register s32 chan, register void* buf, register s32 len,
                 register u32 mode)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x30(r1)
    stmw        r27, 0x1c(r1)
    addi        r27, r3, 0x0
    addi        r28, r4, 0x0
    addi        r29, r5, 0x0
    addi        r30, r6, 0x0
    b           L_80013E58
L_80013DFC:
    cmpwi       r29, 0x4
    bge         L_80013E0C
    mr          r31, r29
    b           L_80013E10
L_80013E0C:
    li          r31, 0x4
L_80013E10:
    addi        r5, r31, 0x0
    addi        r3, r27, 0x0
    addi        r4, r28, 0x0
    addi        r6, r30, 0x0
    li          r7, 0x0
    bl          EXIImm
    cmpwi       r3, 0x0
    bne         L_80013E38
    li          r3, 0x0
    b           L_80013E64
L_80013E38:
    mr          r3, r27
    bl          EXISync
    cmpwi       r3, 0x0
    bne         L_80013E50
    li          r3, 0x0
    b           L_80013E64
L_80013E50:
    add         r28, r28, r31
    subf        r29, r31, r29
L_80013E58:
    cmpwi       r29, 0x0
    bne         L_80013DFC
    li          r3, 0x1
L_80013E64:
    lwz         r0, 0x34(r1)
    lmw         r27, 0x1c(r1)
    addi        r1, r1, 0x30
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXIDma ---- */
#pragma push
#pragma force_active on
asm int EXIDma(register s32 chan, register void* buf, register s32 len,
               register u32 type, register EXICallback callback)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x40(r1)
    stmw        r25, 0x24(r1)
    addi        r27, r3, 0x0
    addi        r28, r4, 0x0
    addi        r29, r5, 0x0
    addi        r30, r6, 0x0
    addi        r25, r7, 0x0
    slwi        r4, r3, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r26, r0, r4
    bl          OSDisableInterrupts
    mr          r31, r3
    lwz         r0, 0xc(r26)
    clrlwi.     r0, r0, 30
    bne         L_80013ECC
    lwz         r0, 0xc(r26)
    rlwinm.     r0, r0, 0, 29, 29
    bne         L_80013EDC
L_80013ECC:
    mr          r3, r31
    bl          OSRestoreInterrupts
    li          r3, 0x0
    b           L_80013F50
L_80013EDC:
    stw         r25, 0x4(r26)
    lwz         r0, 0x4(r26)
    cmplwi      r0, 0x0
    beq         L_80013F10
    addi        r3, r27, 0x0
    li          r4, 0x0
    li          r5, 0x1
    li          r6, 0x0
    bl          EXIClearInterrupts
    lis         r3, 0x20
    mulli       r0, r27, 0x3
    srw         r3, r3, r0
    bl          __OSUnmaskInterrupts
L_80013F10:
    lwz         r0, 0xc(r26)
    ori         r0, r0, 0x1
    stw         r0, 0xc(r26)
    rlwinm      r4, r28, 0, 6, 26
    lis         r3, 0xCC00
    addi        r0, r3, 0x6800
    mulli       r3, r27, 0x14
    add         r3, r0, r3
    stw         r4, 0x4(r3)
    stw         r29, 0x8(r3)
    slwi        r0, r30, 2
    ori         r0, r0, 0x3
    stw         r0, 0xc(r3)
    mr          r3, r31
    bl          OSRestoreInterrupts
    li          r3, 0x1
L_80013F50:
    lwz         r0, 0x44(r1)
    lmw         r25, 0x24(r1)
    addi        r1, r1, 0x40
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXISync ---- */
#pragma push
#pragma force_active on
asm int EXISync(register s32 chan)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x30(r1)
    stmw        r27, 0x1c(r1)
    slwi        r5, r3, 6
    lis         r4, Ecb@ha
    addi        r0, r4, Ecb@l
    add         r31, r0, r5
    li          r28, 0x0
    mulli       r30, r3, 0x14
    lis         r3, 0xCC00
    addi        r29, r3, 0x6800
    add         r29, r29, r30
    b           L_8001418C
L_80013F9C:
    lwz         r0, 0xc(r29)
    clrlwi.     r0, r0, 31
    bne         L_8001418C
    bl          OSDisableInterrupts
    mr          r27, r3
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 29, 29
    beq         L_80014180
    lwz         r0, 0xc(r31)
    clrlwi.     r0, r0, 30
    beq         L_800140F8
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 30, 30
    beq         L_800140EC
    lwz         r3, 0x10(r31)
    cmpwi       r3, 0x0
    beq         L_800140EC
    lwz         r5, 0x14(r31)
    lis         r4, 0xCC00
    addi        r0, r4, 0x6800
    add         r4, r0, r30
    lwz         r0, 0x10(r4)
    li          r4, 0x0
    ble         L_800140EC
    subi        r7, r3, 0x8
    cmpwi       r3, 0x8
    ble         L_800140C0
    addi        r6, r7, 0x7
    srwi        r6, r6, 3
    mtctr       r6
    cmpwi       r7, 0x0
    ble         L_800140C0
L_8001401C:
    subfic      r6, r4, 0x3
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x0(r5)
    addi        r6, r4, 0x1
    subfic      r6, r6, 0x3
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x1(r5)
    addi        r6, r4, 0x2
    subfic      r6, r6, 0x3
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x2(r5)
    neg         r6, r4
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x3(r5)
    addi        r6, r4, 0x4
    subfic      r6, r6, 0x3
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x4(r5)
    addi        r6, r4, 0x5
    subfic      r6, r6, 0x3
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x5(r5)
    addi        r6, r4, 0x6
    subfic      r6, r6, 0x3
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x6(r5)
    addi        r6, r4, 0x7
    subfic      r6, r6, 0x3
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x7(r5)
    addi        r5, r5, 0x8
    addi        r4, r4, 0x8
    bdnz        L_8001401C
L_800140C0:
    subf        r6, r4, r3
    mtctr       r6
    cmpw        r4, r3
    bge         L_800140EC
L_800140D0:
    subfic      r3, r4, 0x3
    slwi        r3, r3, 3
    srw         r3, r0, r3
    stb         r3, 0x0(r5)
    addi        r5, r5, 0x1
    addi        r4, r4, 0x1
    bdnz        L_800140D0
L_800140EC:
    lwz         r0, 0xc(r31)
    clrrwi      r0, r0, 2
    stw         r0, 0xc(r31)
L_800140F8:
    bl          __OSGetDIConfig
    cmplwi      r3, 0xff
    bne         L_8001417C
    bl          OSGetConsoleType
    clrrwi      r3, r3, 28
    subis       r0, r3, 0x2000
    cmplwi      r0, 0x0
    beq         L_8001417C
    lwz         r0, 0x10(r31)
    cmpwi       r0, 0x4
    bne         L_8001417C
    lwz         r0, 0x0(r29)
    rlwinm.     r0, r0, 0, 25, 27
    bne         L_8001417C
    lis         r3, 0xCC00
    addi        r0, r3, 0x6800
    add         r4, r0, r30
    lwzu        r3, 0x10(r4)
    subis       r0, r3, 0x101
    cmplwi      r0, 0x0
    beq         L_8001416C
    lwz         r3, 0x0(r4)
    subis       r0, r3, 0x507
    cmplwi      r0, 0x0
    beq         L_8001416C
    lwz         r3, 0x0(r4)
    subis       r0, r3, 0x422
    cmplwi      r0, 0x1
    bne         L_8001417C
L_8001416C:
    lis         r3, 0x8000
    lhz         r0, 0x30e6(r3)
    cmplwi      r0, 0x8200
    bne         L_80014180
L_8001417C:
    li          r28, 0x1
L_80014180:
    mr          r3, r27
    bl          OSRestoreInterrupts
    b           L_80014198
L_8001418C:
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 29, 29
    bne         L_80013F9C
L_80014198:
    mr          r3, r28
    lwz         r0, 0x34(r1)
    lmw         r27, 0x1c(r1)
    addi        r1, r1, 0x30
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXIClearInterrupts ---- */
#pragma push
#pragma force_active on
asm u32 EXIClearInterrupts(register s32 chan, register int exi,
                           register int tc, register int ext)
{
    nofralloc
    mulli       r0, r3, 0x14
    lis         r3, 0xCC00
    addi        r7, r3, 0x6800
    add         r7, r7, r0
    lwz         r0, 0x0(r7)
    mr          r3, r0
    andi.       r0, r0, 0x7f5
    cmpwi       r4, 0x0
    beq         L_800141D8
    ori         r0, r0, 0x2
L_800141D8:
    cmpwi       r5, 0x0
    beq         L_800141E4
    ori         r0, r0, 0x8
L_800141E4:
    cmpwi       r6, 0x0
    beq         L_800141F0
    ori         r0, r0, 0x800
L_800141F0:
    stw         r0, 0x0(r7)
    blr
}
#pragma pop

/* ---- EXISetExiCallback ---- */
#pragma push
#pragma force_active on
asm EXICallback EXISetExiCallback(register s32 chan, register EXICallback cb)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x28(r1)
    stmw        r26, 0x10(r1)
    addi        r26, r3, 0x0
    addi        r27, r4, 0x0
    slwi        r0, r3, 6
    lis         r3, Ecb@ha
    addi        r31, r3, Ecb@l
    add         r30, r31, r0
    bl          OSDisableInterrupts
    mr          r28, r3
    lwz         r29, 0x0(r30)
    stw         r27, 0x0(r30)
    cmpwi       r26, 0x2
    beq         L_80014248
    addi        r3, r26, 0x0
    addi        r4, r30, 0x0
    bl          SetExiInterruptMask
    b           L_80014254
L_80014248:
    li          r3, 0x0
    addi        r4, r31, 0x0
    bl          SetExiInterruptMask
L_80014254:
    mr          r3, r28
    bl          OSRestoreInterrupts
    mr          r3, r29
    lwz         r0, 0x2c(r1)
    lmw         r26, 0x10(r1)
    addi        r1, r1, 0x28
    mtlr        r0
    blr
}
#pragma pop

/* ---- __EXIProbe ---- */
#pragma push
#pragma force_active on
asm int __EXIProbe(register s32 chan)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x28(r1)
    stmw        r27, 0x14(r1)
    addi        r28, r3, 0x0
    slwi        r4, r3, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r31, r0, r4
    cmpwi       r28, 0x2
    bne         L_800142A8
    li          r3, 0x1
    b           L_800143D4
L_800142A8:
    li          r29, 0x1
    bl          OSDisableInterrupts
    addi        r30, r3, 0x0
    mulli       r0, r28, 0x14
    lis         r3, 0xCC00
    addi        r3, r3, 0x6800
    add         r3, r3, r0
    lwz         r5, 0x0(r3)
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 28, 28
    bne         L_8001439C
    rlwinm.     r0, r5, 0, 20, 20
    beq         L_80014304
    lwz         r0, 0x0(r3)
    andi.       r0, r0, 0x7f5
    ori         r0, r0, 0x800
    stw         r0, 0x0(r3)
    li          r4, 0x0
    stw         r4, 0x20(r31)
    slwi        r0, r28, 2
    lis         r3, 0x8000
    addi        r3, r3, 0x30c0
    stwx        r4, r3, r0
L_80014304:
    rlwinm.     r0, r5, 0, 19, 19
    beq         L_8001437C
    lis         r31, 0x8000
    lwz         r0, 0xf8(r31)
    srwi        r0, r0, 2
    lis         r3, 0x1062
    addi        r3, r3, 0x4dd3
    mulhwu      r0, r3, r0
    srwi        r27, r0, 6
    bl          OSGetTime
    li          r5, 0x0
    addi        r6, r27, 0x0
    bl          __div2i
    li          r5, 0x0
    li          r6, 0x64
    bl          __div2i
    addi        r4, r4, 0x1
    slwi        r0, r28, 2
    addi        r3, r31, 0x30c0
    add         r3, r3, r0
    lwz         r0, 0x0(r3)
    cmpwi       r0, 0x0
    bne         L_80014364
    stw         r4, 0x0(r3)
L_80014364:
    lwz         r0, 0x0(r3)
    subf        r0, r0, r4
    cmpwi       r0, 0x3
    bge         L_800143C8
    li          r29, 0x0
    b           L_800143C8
L_8001437C:
    li          r4, 0x0
    stw         r4, 0x20(r31)
    slwi        r0, r28, 2
    lis         r3, 0x8000
    addi        r3, r3, 0x30c0
    stwx        r4, r3, r0
    li          r29, 0x0
    b           L_800143C8
L_8001439C:
    rlwinm.     r0, r5, 0, 19, 19
    beq         L_800143AC
    rlwinm.     r0, r5, 0, 20, 20
    beq         L_800143C8
L_800143AC:
    li          r4, 0x0
    stw         r4, 0x20(r31)
    slwi        r0, r28, 2
    lis         r3, 0x8000
    addi        r3, r3, 0x30c0
    stwx        r4, r3, r0
    li          r29, 0x0
L_800143C8:
    mr          r3, r30
    bl          OSRestoreInterrupts
    mr          r3, r29
L_800143D4:
    lwz         r0, 0x2c(r1)
    lmw         r27, 0x14(r1)
    addi        r1, r1, 0x28
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXIProbe ---- */
#pragma push
#pragma force_active on
asm int EXIProbe(register s32 chan)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x18(r1)
    stw         r31, 0x14(r1)
    stw         r30, 0x10(r1)
    addi        r30, r3, 0x0
    slwi        r4, r3, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r31, r0, r4
    addi        r3, r30, 0x0
    bl          __EXIProbe
    cmpwi       r3, 0x0
    beq         L_80014450
    lwz         r0, 0x20(r31)
    cmpwi       r0, 0x0
    bne         L_80014450
    addi        r3, r30, 0x0
    li          r4, 0x0
    addi        r5, r1, 0xc
    bl          EXIGetID
    cmpwi       r3, 0x0
    beq         L_8001444C
    li          r3, 0x1
    b           L_80014450
L_8001444C:
    li          r3, 0x0
L_80014450:
    lwz         r0, 0x1c(r1)
    lwz         r31, 0x14(r1)
    lwz         r30, 0x10(r1)
    addi        r1, r1, 0x18
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXIProbeEx ---- */
#pragma push
#pragma force_active on
asm int EXIProbeEx(register s32 chan)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x18(r1)
    stw         r31, 0x14(r1)
    stw         r30, 0x10(r1)
    addi        r30, r3, 0x0
    slwi        r4, r3, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r31, r0, r4
    addi        r3, r30, 0x0
    bl          __EXIProbe
    cmpwi       r3, 0x0
    beq         L_800144D0
    lwz         r0, 0x20(r31)
    cmpwi       r0, 0x0
    bne         L_800144D0
    addi        r3, r30, 0x0
    li          r4, 0x0
    addi        r5, r1, 0xc
    bl          EXIGetID
    cmpwi       r3, 0x0
    beq         L_800144CC
    li          r3, 0x1
    b           L_800144D0
L_800144CC:
    li          r3, 0x0
L_800144D0:
    cmpwi       r3, 0x0
    beq         L_800144E0
    li          r3, 0x1
    b           L_80014504
L_800144E0:
    slwi        r0, r30, 2
    lis         r3, 0x8000
    addi        r3, r3, 0x30c0
    lwzx        r0, r3, r0
    cmpwi       r0, 0x0
    beq         L_80014500
    li          r3, 0x0
    b           L_80014504
L_80014500:
    li          r3, -0x1
L_80014504:
    lwz         r0, 0x1c(r1)
    lwz         r31, 0x14(r1)
    lwz         r30, 0x10(r1)
    addi        r1, r1, 0x18
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXIAttach ---- */
#pragma push
#pragma force_active on
asm int EXIAttach(register s32 chan, register EXICallback extCallback)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x40(r1)
    stmw        r27, 0x2c(r1)
    addi        r27, r3, 0x0
    addi        r28, r4, 0x0
    slwi        r4, r3, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r30, r0, r4
    addi        r3, r27, 0x0
    bl          __EXIProbe
    cmpwi       r3, 0x0
    beq         L_80014570
    lwz         r0, 0x20(r30)
    cmpwi       r0, 0x0
    bne         L_80014570
    addi        r3, r27, 0x0
    li          r4, 0x0
    addi        r5, r1, 0x1c
    bl          EXIGetID
L_80014570:
    bl          OSDisableInterrupts
    mr          r29, r3
    lwz         r0, 0x20(r30)
    cmpwi       r0, 0x0
    bne         L_80014594
    mr          r3, r29
    bl          OSRestoreInterrupts
    li          r3, 0x0
    b           L_80014614
L_80014594:
    bl          OSDisableInterrupts
    mr          r31, r3
    lwz         r0, 0xc(r30)
    rlwinm.     r0, r0, 0, 28, 28
    bne         L_800145B8
    mr          r3, r27
    bl          __EXIProbe
    cmpwi       r3, 0x0
    bne         L_800145C8
L_800145B8:
    mr          r3, r31
    bl          OSRestoreInterrupts
    li          r31, 0x0
    b           L_80014608
L_800145C8:
    addi        r3, r27, 0x0
    li          r4, 0x1
    li          r5, 0x0
    li          r6, 0x0
    bl          EXIClearInterrupts
    stw         r28, 0x8(r30)
    lis         r3, 0x10
    mulli       r0, r27, 0x3
    srw         r3, r3, r0
    bl          __OSUnmaskInterrupts
    lwz         r0, 0xc(r30)
    ori         r0, r0, 0x8
    stw         r0, 0xc(r30)
    mr          r3, r31
    bl          OSRestoreInterrupts
    li          r31, 0x1
L_80014608:
    mr          r3, r29
    bl          OSRestoreInterrupts
    mr          r3, r31
L_80014614:
    lwz         r0, 0x44(r1)
    lmw         r27, 0x2c(r1)
    addi        r1, r1, 0x40
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXIDetach ---- */
#pragma push
#pragma force_active on
asm int EXIDetach(register s32 chan)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x20(r1)
    stw         r31, 0x1c(r1)
    stw         r30, 0x18(r1)
    stw         r29, 0x14(r1)
    addi        r29, r3, 0x0
    slwi        r4, r3, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r31, r0, r4
    bl          OSDisableInterrupts
    mr          r30, r3
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 28, 28
    bne         L_80014678
    mr          r3, r30
    bl          OSRestoreInterrupts
    li          r3, 0x1
    b           L_800146C8
L_80014678:
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 27, 27
    beq         L_800146A0
    lwz         r0, 0x18(r31)
    cmplwi      r0, 0x0
    bne         L_800146A0
    mr          r3, r30
    bl          OSRestoreInterrupts
    li          r3, 0x0
    b           L_800146C8
L_800146A0:
    lwz         r0, 0xc(r31)
    rlwinm      r0, r0, 0, 29, 27
    stw         r0, 0xc(r31)
    lis         r3, 0x50
    mulli       r0, r29, 0x3
    srw         r3, r3, r0
    bl          __OSMaskInterrupts
    mr          r3, r30
    bl          OSRestoreInterrupts
    li          r3, 0x1
L_800146C8:
    lwz         r0, 0x24(r1)
    lwz         r31, 0x1c(r1)
    lwz         r30, 0x18(r1)
    lwz         r29, 0x14(r1)
    addi        r1, r1, 0x20
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXISelect ---- */
#pragma push
#pragma force_active on
asm int EXISelect(register s32 chan, register u32 dev, register u32 freq)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x30(r1)
    stmw        r27, 0x1c(r1)
    addi        r27, r3, 0x0
    addi        r28, r4, 0x0
    addi        r29, r5, 0x0
    slwi        r4, r3, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r31, r0, r4
    bl          OSDisableInterrupts
    mr          r30, r3
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 29, 29
    bne         L_80014768
    cmpwi       r27, 0x2
    beq         L_80014778
    cmplwi      r28, 0x0
    bne         L_80014750
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 28, 28
    bne         L_80014750
    mr          r3, r27
    bl          __EXIProbe
    cmpwi       r3, 0x0
    beq         L_80014768
L_80014750:
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 27, 27
    beq         L_80014768
    lwz         r0, 0x18(r31)
    cmplw       r0, r28
    beq         L_80014778
L_80014768:
    mr          r3, r30
    bl          OSRestoreInterrupts
    li          r3, 0x0
    b           L_800147FC
L_80014778:
    lwz         r0, 0xc(r31)
    ori         r0, r0, 0x4
    stw         r0, 0xc(r31)
    mulli       r0, r27, 0x14
    lis         r3, 0xCC00
    addi        r4, r3, 0x6800
    add         r4, r4, r0
    lwz         r5, 0x0(r4)
    andi.       r5, r5, 0x405
    li          r0, 0x1
    slw         r0, r0, r28
    slwi        r3, r0, 7
    slwi        r0, r29, 4
    or          r0, r3, r0
    or          r5, r5, r0
    stw         r5, 0x0(r4)
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 28, 28
    beq         L_800147F0
    cmpwi       r27, 0x1
    beq         L_800147E8
    bge         L_800147F0
    cmpwi       r27, 0x0
    bge         L_800147DC
    b           L_800147F0
L_800147DC:
    lis         r3, 0x10
    bl          __OSMaskInterrupts
    b           L_800147F0
L_800147E8:
    lis         r3, 0x2
    bl          __OSMaskInterrupts
L_800147F0:
    mr          r3, r30
    bl          OSRestoreInterrupts
    li          r3, 0x1
L_800147FC:
    lwz         r0, 0x34(r1)
    lmw         r27, 0x1c(r1)
    addi        r1, r1, 0x30
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXIDeselect ---- */
#pragma push
#pragma force_active on
asm int EXIDeselect(register s32 chan)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x20(r1)
    stw         r31, 0x1c(r1)
    stw         r30, 0x18(r1)
    stw         r29, 0x14(r1)
    stw         r28, 0x10(r1)
    addi        r31, r3, 0x0
    slwi        r4, r3, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r30, r0, r4
    bl          OSDisableInterrupts
    mr          r28, r3
    lwz         r0, 0xc(r30)
    rlwinm.     r0, r0, 0, 29, 29
    bne         L_80014864
    mr          r3, r28
    bl          OSRestoreInterrupts
    li          r3, 0x0
    b           L_80014900
L_80014864:
    lwz         r0, 0xc(r30)
    rlwinm      r0, r0, 0, 30, 28
    stw         r0, 0xc(r30)
    mulli       r0, r31, 0x14
    lis         r3, 0xCC00
    addi        r3, r3, 0x6800
    add         r3, r3, r0
    lwz         r29, 0x0(r3)
    andi.       r0, r29, 0x405
    stw         r0, 0x0(r3)
    lwz         r0, 0xc(r30)
    rlwinm.     r0, r0, 0, 28, 28
    beq         L_800148C4
    cmpwi       r31, 0x1
    beq         L_800148BC
    bge         L_800148C4
    cmpwi       r31, 0x0
    bge         L_800148B0
    b           L_800148C4
L_800148B0:
    lis         r3, 0x10
    bl          __OSUnmaskInterrupts
    b           L_800148C4
L_800148BC:
    lis         r3, 0x2
    bl          __OSUnmaskInterrupts
L_800148C4:
    mr          r3, r28
    bl          OSRestoreInterrupts
    cmpwi       r31, 0x2
    beq         L_800148FC
    rlwinm.     r0, r29, 0, 24, 24
    beq         L_800148FC
    mr          r3, r31
    bl          __EXIProbe
    cmpwi       r3, 0x0
    beq         L_800148F4
    li          r3, 0x1
    b           L_80014900
L_800148F4:
    li          r3, 0x0
    b           L_80014900
L_800148FC:
    li          r3, 0x1
L_80014900:
    lwz         r0, 0x24(r1)
    lwz         r31, 0x1c(r1)
    lwz         r30, 0x18(r1)
    lwz         r29, 0x14(r1)
    lwz         r28, 0x10(r1)
    addi        r1, r1, 0x20
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXIIntrruptHandler ---- */
#pragma push
#pragma force_active on
asm void EXIIntrruptHandler(register s32 interrupt, register OSContext* context)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x2f8(r1)
    stw         r31, 0x2f4(r1)
    stw         r30, 0x2f0(r1)
    stw         r29, 0x2ec(r1)
    addi        r31, r4, 0x0
    extsh       r3, r3
    subi        r0, r3, 0x9
    lis         r3, 0x5555
    addi        r3, r3, 0x5556
    mulhw       r3, r3, r0
    srwi        r0, r3, 31
    add         r30, r3, r0
    mulli       r0, r30, 0x14
    lis         r3, 0xCC00
    addi        r3, r3, 0x6800
    add         r3, r3, r0
    lwz         r0, 0x0(r3)
    andi.       r0, r0, 0x7f5
    ori         r0, r0, 0x2
    stw         r0, 0x0(r3)
    slwi        r4, r30, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r3, r0, r4
    lwz         r0, 0x0(r3)
    mr          r29, r0
    cmplwi      r0, 0x0
    beq         L_800149CC
    addi        r3, r1, 0x18
    bl          OSClearContext
    addi        r3, r1, 0x18
    bl          OSSetCurrentContext
    addi        r3, r30, 0x0
    addi        r4, r31, 0x0
    addi        r12, r29, 0x0
    mtlr        r12
    blrl
    addi        r3, r1, 0x18
    bl          OSClearContext
    mr          r3, r31
    bl          OSSetCurrentContext
L_800149CC:
    lwz         r0, 0x2fc(r1)
    lwz         r31, 0x2f4(r1)
    lwz         r30, 0x2f0(r1)
    lwz         r29, 0x2ec(r1)
    addi        r1, r1, 0x2f8
    mtlr        r0
    blr
}
#pragma pop

/* ---- TCIntrruptHandler ---- */
#pragma push
#pragma force_active on
asm void TCIntrruptHandler(register s32 interrupt, register OSContext* context)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x2f8(r1)
    stw         r31, 0x2f4(r1)
    stw         r30, 0x2f0(r1)
    stw         r29, 0x2ec(r1)
    stw         r28, 0x2e8(r1)
    addi        r28, r4, 0x0
    extsh       r5, r3
    subi        r0, r5, 0xa
    lis         r3, 0x5555
    addi        r3, r3, 0x5556
    mulhw       r3, r3, r0
    srwi        r0, r3, 31
    add         r30, r3, r0
    slwi        r4, r30, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r31, r0, r4
    lis         r0, 0x8000
    srw         r3, r0, r5
    bl          __OSMaskInterrupts
    mulli       r7, r30, 0x14
    lis         r6, 0xCC00
    addi        r3, r6, 0x6800
    add         r3, r3, r7
    lwz         r0, 0x0(r3)
    andi.       r0, r0, 0x7f5
    ori         r0, r0, 0x8
    stw         r0, 0x0(r3)
    lwz         r0, 0x4(r31)
    mr          r29, r0
    cmplwi      r0, 0x0
    beq         L_80014BE0
    li          r4, 0x0
    stw         r4, 0x4(r31)
    lwz         r0, 0xc(r31)
    clrlwi.     r0, r0, 30
    beq         L_80014BAC
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 30, 30
    beq         L_80014BA0
    lwz         r3, 0x10(r31)
    cmpwi       r3, 0x0
    beq         L_80014BA0
    lwz         r5, 0x14(r31)
    addi        r0, r6, 0x6800
    add         r6, r0, r7
    lwz         r0, 0x10(r6)
    ble         L_80014BA0
    subi        r7, r3, 0x8
    cmpwi       r3, 0x8
    ble         L_80014B74
    addi        r6, r7, 0x7
    srwi        r6, r6, 3
    mtctr       r6
    cmpwi       r7, 0x0
    ble         L_80014B74
L_80014AD0:
    subfic      r6, r4, 0x3
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x0(r5)
    addi        r6, r4, 0x1
    subfic      r6, r6, 0x3
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x1(r5)
    addi        r6, r4, 0x2
    subfic      r6, r6, 0x3
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x2(r5)
    neg         r6, r4
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x3(r5)
    addi        r6, r4, 0x4
    subfic      r6, r6, 0x3
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x4(r5)
    addi        r6, r4, 0x5
    subfic      r6, r6, 0x3
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x5(r5)
    addi        r6, r4, 0x6
    subfic      r6, r6, 0x3
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x6(r5)
    addi        r6, r4, 0x7
    subfic      r6, r6, 0x3
    slwi        r6, r6, 3
    srw         r6, r0, r6
    stb         r6, 0x7(r5)
    addi        r5, r5, 0x8
    addi        r4, r4, 0x8
    bdnz        L_80014AD0
L_80014B74:
    subf        r6, r4, r3
    mtctr       r6
    cmpw        r4, r3
    bge         L_80014BA0
L_80014B84:
    subfic      r3, r4, 0x3
    slwi        r3, r3, 3
    srw         r3, r0, r3
    stb         r3, 0x0(r5)
    addi        r5, r5, 0x1
    addi        r4, r4, 0x1
    bdnz        L_80014B84
L_80014BA0:
    lwz         r0, 0xc(r31)
    clrrwi      r0, r0, 2
    stw         r0, 0xc(r31)
L_80014BAC:
    addi        r3, r1, 0x20
    bl          OSClearContext
    addi        r3, r1, 0x20
    bl          OSSetCurrentContext
    addi        r3, r30, 0x0
    addi        r4, r28, 0x0
    addi        r12, r29, 0x0
    mtlr        r12
    blrl
    addi        r3, r1, 0x20
    bl          OSClearContext
    mr          r3, r28
    bl          OSSetCurrentContext
L_80014BE0:
    lwz         r0, 0x2fc(r1)
    lwz         r31, 0x2f4(r1)
    lwz         r30, 0x2f0(r1)
    lwz         r29, 0x2ec(r1)
    lwz         r28, 0x2e8(r1)
    addi        r1, r1, 0x2f8
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXTIntrruptHandler ---- */
#pragma push
#pragma force_active on
asm void EXTIntrruptHandler(register s32 interrupt, register OSContext* context)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x2e8(r1)
    stw         r31, 0x2e4(r1)
    stw         r30, 0x2e0(r1)
    stw         r29, 0x2dc(r1)
    stw         r28, 0x2d8(r1)
    addi        r31, r4, 0x0
    extsh       r3, r3
    subi        r0, r3, 0xb
    lis         r3, 0x5555
    addi        r3, r3, 0x5556
    mulhw       r3, r3, r0
    srwi        r0, r3, 31
    add         r30, r3, r0
    lis         r3, 0x50
    mulli       r0, r30, 0x3
    srw         r3, r3, r0
    bl          __OSMaskInterrupts
    slwi        r4, r30, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r29, r0, r4
    lwz         r28, 0x8(r29)
    lwz         r0, 0xc(r29)
    rlwinm      r0, r0, 0, 29, 27
    stw         r0, 0xc(r29)
    cmplwi      r28, 0x0
    beq         L_80014CB0
    addi        r3, r1, 0x10
    bl          OSClearContext
    addi        r3, r1, 0x10
    bl          OSSetCurrentContext
    li          r0, 0x0
    stw         r0, 0x8(r29)
    addi        r3, r30, 0x0
    addi        r4, r31, 0x0
    addi        r12, r28, 0x0
    mtlr        r12
    blrl
    addi        r3, r1, 0x10
    bl          OSClearContext
    mr          r3, r31
    bl          OSSetCurrentContext
L_80014CB0:
    lwz         r0, 0x2ec(r1)
    lwz         r31, 0x2e4(r1)
    lwz         r30, 0x2e0(r1)
    lwz         r29, 0x2dc(r1)
    lwz         r28, 0x2d8(r1)
    addi        r1, r1, 0x2e8
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXIInit ---- */
#pragma push
#pragma force_active on
asm void EXIInit(void)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x20(r1)
    stw         r31, 0x1c(r1)
    stw         r30, 0x18(r1)
    stw         r29, 0x14(r1)
    stw         r28, 0x10(r1)
    lis         r3, 0xCC00
    addi        r3, r3, 0x6800
L_80014CF4:
    lwz         r0, 0xc(r3)
    clrlwi      r0, r0, 31
    cmplwi      r0, 0x1
    beq         L_80014CF4
    lwz         r0, 0x20(r3)
    clrlwi      r0, r0, 31
    cmplwi      r0, 0x1
    beq         L_80014CF4
    lwz         r0, 0x34(r3)
    clrlwi      r0, r0, 31
    cmplwi      r0, 0x1
    beq         L_80014CF4
    lis         r3, 0x80
    addi        r3, r3, -0x8000
    bl          __OSMaskInterrupts
    li          r31, 0x0
    lis         r4, 0xCC00
    stw         r31, 0x6800(r4)
    stw         r31, 0x6814(r4)
    stw         r31, 0x6828(r4)
    li          r0, 0x2000
    stw         r0, 0x6800(r4)
    li          r3, 0x9
    lis         r4, EXIIntrruptHandler@ha
    addi        r28, r4, EXIIntrruptHandler@l
    addi        r4, r28, 0x0
    bl          __OSSetInterruptHandler
    li          r3, 0xa
    lis         r4, TCIntrruptHandler@ha
    addi        r29, r4, TCIntrruptHandler@l
    addi        r4, r29, 0x0
    bl          __OSSetInterruptHandler
    li          r3, 0xb
    lis         r4, EXTIntrruptHandler@ha
    addi        r30, r4, EXTIntrruptHandler@l
    addi        r4, r30, 0x0
    bl          __OSSetInterruptHandler
    li          r3, 0xc
    addi        r4, r28, 0x0
    bl          __OSSetInterruptHandler
    li          r3, 0xd
    addi        r4, r29, 0x0
    bl          __OSSetInterruptHandler
    li          r3, 0xe
    addi        r4, r30, 0x0
    bl          __OSSetInterruptHandler
    li          r3, 0xf
    addi        r4, r28, 0x0
    bl          __OSSetInterruptHandler
    li          r3, 0x10
    addi        r4, r29, 0x0
    bl          __OSSetInterruptHandler
    li          r3, 0x0
    li          r4, 0x2
    addi        r5, r13, -0x7B88 /* IDSerialPort1@sda21 */
    bl          EXIGetID
    lwz	r0, __OSInIPL /* __OSInIPL@sda21 */
    cmpwi       r0, 0x0
    beq         L_80014E10
    lis         r4, 0x8000
    stw         r31, 0x30c4(r4)
    stw         r31, 0x30c0(r4)
    lis         r3, Ecb@ha
    addi        r3, r3, Ecb@l
    stw         r31, 0x60(r3)
    stw         r31, 0x20(r3)
    li          r3, 0x0
    bl          __EXIProbe
    li          r3, 0x1
    bl          __EXIProbe
    b           L_80014E7C
L_80014E10:
    li          r3, 0x0
    li          r4, 0x0
    addi        r5, r1, 0x8
    bl          EXIGetID
    cmpwi       r3, 0x0
    beq         L_80014E48
    lwz         r3, 0x8(r1)
    subis       r0, r3, 0x701
    cmplwi      r0, 0x0
    bne         L_80014E48
    li          r3, 0x1
    li          r4, 0x0
    bl          __OSEnableBarnacle
    b           L_80014E7C
L_80014E48:
    li          r3, 0x1
    li          r4, 0x0
    addi        r5, r1, 0x8
    bl          EXIGetID
    cmpwi       r3, 0x0
    beq         L_80014E7C
    lwz         r3, 0x8(r1)
    subis       r0, r3, 0x701
    cmplwi      r0, 0x0
    bne         L_80014E7C
    li          r3, 0x0
    li          r4, 0x2
    bl          __OSEnableBarnacle
L_80014E7C:
    lwz	r3, __EXIVersion /* __EXIVersion@sda21 */
    bl          OSRegisterVersion
    lwz         r0, 0x24(r1)
    lwz         r31, 0x1c(r1)
    lwz         r30, 0x18(r1)
    lwz         r29, 0x14(r1)
    lwz         r28, 0x10(r1)
    addi        r1, r1, 0x20
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXILock ---- */
#pragma push
#pragma force_active on
asm int EXILock(register s32 chan, register u32 dev,
                register EXICallback unlockedCallback)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x30(r1)
    stmw        r27, 0x1c(r1)
    addi        r27, r3, 0x0
    addi        r31, r4, 0x0
    addi        r28, r5, 0x0
    slwi        r4, r3, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r30, r0, r4
    bl          OSDisableInterrupts
    mr          r29, r3
    lwz         r0, 0xc(r30)
    rlwinm.     r0, r0, 0, 27, 27
    beq         L_80014F5C
    cmplwi      r28, 0x0
    beq         L_80014F4C
    mr          r3, r30
    lwz         r4, 0x24(r30)
    mtctr       r4
    cmpwi       r4, 0x0
    ble         L_80014F24
L_80014F00:
    lwz         r0, 0x28(r3)
    cmplw       r0, r31
    bne         L_80014F1C
    mr          r3, r29
    bl          OSRestoreInterrupts
    li          r3, 0x0
    b           L_80014F84
L_80014F1C:
    addi        r3, r3, 0x8
    bdnz        L_80014F00
L_80014F24:
    slwi        r0, r4, 3
    add         r3, r30, r0
    stw         r28, 0x2c(r3)
    lwz         r0, 0x24(r30)
    slwi        r0, r0, 3
    add         r3, r30, r0
    stw         r31, 0x28(r3)
    lwz         r3, 0x24(r30)
    addi        r0, r3, 0x1
    stw         r0, 0x24(r30)
L_80014F4C:
    mr          r3, r29
    bl          OSRestoreInterrupts
    li          r3, 0x0
    b           L_80014F84
L_80014F5C:
    lwz         r0, 0xc(r30)
    ori         r0, r0, 0x10
    stw         r0, 0xc(r30)
    stw         r31, 0x18(r30)
    addi        r3, r27, 0x0
    addi        r4, r30, 0x0
    bl          SetExiInterruptMask
    mr          r3, r29
    bl          OSRestoreInterrupts
    li          r3, 0x1
L_80014F84:
    lwz         r0, 0x34(r1)
    lmw         r27, 0x1c(r1)
    addi        r1, r1, 0x30
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXIUnlock ---- */
#pragma push
#pragma force_active on
asm int EXIUnlock(register s32 chan)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x20(r1)
    stw         r31, 0x1c(r1)
    stw         r30, 0x18(r1)
    stw         r29, 0x14(r1)
    stw         r28, 0x10(r1)
    addi        r28, r3, 0x0
    slwi        r4, r3, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r31, r0, r4
    bl          OSDisableInterrupts
    mr          r30, r3
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 27, 27
    bne         L_80014FEC
    mr          r3, r30
    bl          OSRestoreInterrupts
    li          r3, 0x0
    b           L_80015054
L_80014FEC:
    lwz         r0, 0xc(r31)
    rlwinm      r0, r0, 0, 28, 26
    stw         r0, 0xc(r31)
    addi        r3, r28, 0x0
    addi        r4, r31, 0x0
    bl          SetExiInterruptMask
    lwz         r3, 0x24(r31)
    cmpwi       r3, 0x0
    ble         L_80015048
    lwz         r29, 0x2c(r31)
    subic.      r0, r3, 0x1
    stw         r0, 0x24(r31)
    ble         L_80015034
    addi        r3, r31, 0x28
    addi        r4, r31, 0x30
    lwz         r0, 0x24(r31)
    slwi        r5, r0, 3
    bl          memmove
L_80015034:
    addi        r3, r28, 0x0
    li          r4, 0x0
    addi        r12, r29, 0x0
    mtlr        r12
    blrl
L_80015048:
    mr          r3, r30
    bl          OSRestoreInterrupts
    li          r3, 0x1
L_80015054:
    lwz         r0, 0x24(r1)
    lwz         r31, 0x1c(r1)
    lwz         r30, 0x18(r1)
    lwz         r29, 0x14(r1)
    lwz         r28, 0x10(r1)
    addi        r1, r1, 0x20
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXIGetState ---- */
#pragma push
#pragma force_active on
asm u32 EXIGetState(register s32 chan)
{
    nofralloc
    slwi        r4, r3, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r3, r0, r4
    lwz         r3, 0xc(r3)
    blr
}
#pragma pop

/* ---- UnlockedHandler ---- */
#pragma push
#pragma force_active on
asm void UnlockedHandler(register s32 chan, register OSContext* context)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x18(r1)
    li          r4, 0x0
    addi        r5, r1, 0x10
    bl          EXIGetID
    lwz         r0, 0x1c(r1)
    addi        r1, r1, 0x18
    mtlr        r0
    blr
}
#pragma pop

/* ---- EXIGetID ---- */
#pragma push
#pragma force_active on
asm u32 EXIGetID(register s32 chan, register u32 dev, register u32* id)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x48(r1)
    stmw        r23, 0x24(r1)
    mr.         r25, r3
    addi        r26, r4, 0x0
    addi        r27, r5, 0x0
    slwi        r4, r3, 6
    lis         r3, Ecb@ha
    addi        r0, r3, Ecb@l
    add         r31, r0, r4
    bne         L_80015104
    cmplwi      r26, 0x2
    bne         L_80015104
    lwz	r0, IDSerialPort1 /* IDSerialPort1@sda21 */
    cmplwi      r0, 0x0
    beq         L_80015104
    stw         r0, 0x0(r27)
    li          r3, 0x1
    b           L_80015450
L_80015104:
    cmpwi       r25, 0x2
    bge         L_800151E8
    cmplwi      r26, 0x0
    bne         L_800151E8
    mr          r3, r25
    bl          __EXIProbe
    cmpwi       r3, 0x0
    bne         L_8001512C
    li          r3, 0x0
    b           L_80015450
L_8001512C:
    lwz         r4, 0x20(r31)
    slwi        r0, r25, 2
    lis         r3, 0x8000
    addi        r30, r3, 0x30c0
    add         r30, r30, r0
    lwz         r0, 0x0(r30)
    cmpw        r4, r0
    bne         L_8001515C
    lwz         r0, 0x1c(r31)
    stw         r0, 0x0(r27)
    lwz         r3, 0x20(r31)
    b           L_80015450
L_8001515C:
    bl          OSDisableInterrupts
    mr          r28, r3
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 28, 28
    bne         L_80015180
    mr          r3, r25
    bl          __EXIProbe
    cmpwi       r3, 0x0
    bne         L_80015190
L_80015180:
    mr          r3, r28
    bl          OSRestoreInterrupts
    li          r0, 0x0
    b           L_800151D4
L_80015190:
    addi        r3, r25, 0x0
    li          r4, 0x1
    li          r5, 0x0
    li          r6, 0x0
    bl          EXIClearInterrupts
    li          r0, 0x0
    stw         r0, 0x8(r31)
    lis         r3, 0x10
    mulli       r0, r25, 0x3
    srw         r3, r3, r0
    bl          __OSUnmaskInterrupts
    lwz         r0, 0xc(r31)
    ori         r0, r0, 0x8
    stw         r0, 0xc(r31)
    mr          r3, r28
    bl          OSRestoreInterrupts
    li          r0, 0x1
L_800151D4:
    cmpwi       r0, 0x0
    bne         L_800151E4
    li          r3, 0x0
    b           L_80015450
L_800151E4:
    lwz         r29, 0x0(r30)
L_800151E8:
    bl          OSDisableInterrupts
    addi        r28, r3, 0x0
    li          r0, 0x0
    cmpwi       r25, 0x2
    bge         L_80015208
    cmplwi      r26, 0x0
    bne         L_80015208
    li          r0, 0x1
L_80015208:
    cmpwi       r0, 0x0
    beq         L_8001521C
    lis         r3, UnlockedHandler@ha
    addi        r5, r3, UnlockedHandler@l
    b           L_80015220
L_8001521C:
    li          r5, 0x0
L_80015220:
    addi        r3, r25, 0x0
    addi        r4, r26, 0x0
    bl          EXILock
    cntlzw      r0, r3
    srwi        r0, r0, 5
    mr.         r30, r0
    bne         L_8001536C
    addi        r3, r25, 0x0
    addi        r4, r26, 0x0
    li          r5, 0x0
    bl          EXISelect
    cntlzw      r0, r3
    srwi        r0, r0, 5
    mr.         r30, r0
    bne         L_800152E8
    li          r0, 0x0
    stw         r0, 0x1c(r1)
    addi        r3, r25, 0x0
    addi        r4, r1, 0x1c
    li          r5, 0x2
    li          r6, 0x1
    li          r7, 0x0
    bl          EXIImm
    cntlzw      r0, r3
    srwi        r0, r0, 5
    or          r30, r30, r0
    addi        r3, r25, 0x0
    bl          EXISync
    cntlzw      r0, r3
    srwi        r0, r0, 5
    or          r30, r30, r0
    addi        r3, r25, 0x0
    addi        r4, r27, 0x0
    li          r5, 0x4
    li          r6, 0x0
    li          r7, 0x0
    bl          EXIImm
    cntlzw      r0, r3
    srwi        r0, r0, 5
    or          r30, r30, r0
    addi        r3, r25, 0x0
    bl          EXISync
    cntlzw      r0, r3
    srwi        r0, r0, 5
    or          r30, r30, r0
    addi        r3, r25, 0x0
    bl          EXIDeselect
    cntlzw      r0, r3
    srwi        r0, r0, 5
    or          r30, r30, r0
L_800152E8:
    bl          OSDisableInterrupts
    mr          r23, r3
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 27, 27
    bne         L_80015308
    mr          r3, r23
    bl          OSRestoreInterrupts
    b           L_8001536C
L_80015308:
    lwz         r0, 0xc(r31)
    rlwinm      r0, r0, 0, 28, 26
    stw         r0, 0xc(r31)
    addi        r3, r25, 0x0
    addi        r4, r31, 0x0
    bl          SetExiInterruptMask
    lwz         r3, 0x24(r31)
    cmpwi       r3, 0x0
    ble         L_80015364
    lwz         r24, 0x2c(r31)
    subic.      r0, r3, 0x1
    stw         r0, 0x24(r31)
    ble         L_80015350
    addi        r3, r31, 0x28
    addi        r4, r31, 0x30
    lwz         r0, 0x24(r31)
    slwi        r5, r0, 3
    bl          memmove
L_80015350:
    addi        r3, r25, 0x0
    li          r4, 0x0
    addi        r12, r24, 0x0
    mtlr        r12
    blrl
L_80015364:
    mr          r3, r23
    bl          OSRestoreInterrupts
L_8001536C:
    mr          r3, r28
    bl          OSRestoreInterrupts
    cmpwi       r25, 0x2
    bge         L_8001543C
    cmplwi      r26, 0x0
    bne         L_8001543C
    bl          OSDisableInterrupts
    mr          r23, r3
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 28, 28
    bne         L_800153A4
    mr          r3, r23
    bl          OSRestoreInterrupts
    b           L_800153EC
L_800153A4:
    lwz         r0, 0xc(r31)
    rlwinm.     r0, r0, 0, 27, 27
    beq         L_800153C8
    lwz         r0, 0x18(r31)
    cmplwi      r0, 0x0
    bne         L_800153C8
    mr          r3, r23
    bl          OSRestoreInterrupts
    b           L_800153EC
L_800153C8:
    lwz         r0, 0xc(r31)
    rlwinm      r0, r0, 0, 29, 27
    stw         r0, 0xc(r31)
    lis         r3, 0x50
    mulli       r0, r25, 0x3
    srw         r3, r3, r0
    bl          __OSMaskInterrupts
    mr          r3, r23
    bl          OSRestoreInterrupts
L_800153EC:
    bl          OSDisableInterrupts
    slwi        r0, r25, 2
    lis         r4, 0x8000
    addi        r4, r4, 0x30c0
    lwzx        r0, r4, r0
    subf        r4, r29, r0
    subic       r0, r4, 0x1
    subfe       r0, r0, r4
    or.         r30, r30, r0
    bne         L_80015420
    lwz         r0, 0x0(r27)
    stw         r0, 0x1c(r31)
    stw         r29, 0x20(r31)
L_80015420:
    bl          OSRestoreInterrupts
    cmpwi       r30, 0x0
    beq         L_80015434
    li          r3, 0x0
    b           L_80015450
L_80015434:
    lwz         r3, 0x20(r31)
    b           L_80015450
L_8001543C:
    cmpwi       r30, 0x0
    beq         L_8001544C
    li          r3, 0x0
    b           L_80015450
L_8001544C:
    li          r3, 0x1
L_80015450:
    lwz         r0, 0x4c(r1)
    lmw         r23, 0x24(r1)
    addi        r1, r1, 0x48
    mtlr        r0
    blr
}
#pragma pop

/* ---- __EXIGetID ---- */
#pragma push
#pragma force_active on
asm int __EXIGetID(register s32 chan, register u32 dev, register u32* id)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x28(r1)
    stw         r31, 0x24(r1)
    addi        r31, r5, 0x0
    stw         r30, 0x20(r1)
    addi        r30, r4, 0x0
    stw         r29, 0x1c(r1)
    addi        r29, r3, 0x0
    cmpwi       r29, 0x2
    stw         r28, 0x18(r1)
    beq         L_800154B8
    cmplwi      r30, 0x0
    bne         L_800154B8
    addi        r3, r29, 0x0
    li          r4, 0x0
    bl          EXIAttach
    cmpwi       r3, 0x0
    bne         L_800154B8
    li          r3, 0x0
    b           L_800155D0
L_800154B8:
    addi        r3, r29, 0x0
    addi        r4, r30, 0x0
    li          r5, 0x0
    bl          EXILock
    cntlzw      r0, r3
    srwi        r0, r0, 5
    mr.         r28, r0
    bne         L_8001558C
    addi        r3, r29, 0x0
    addi        r4, r30, 0x0
    li          r5, 0x0
    bl          EXISelect
    cntlzw      r0, r3
    srwi        r0, r0, 5
    mr.         r28, r0
    bne         L_80015584
    lis         r3, 0x2001
    addi        r0, r3, 0x1300
    stw         r0, 0x14(r1)
    addi        r3, r29, 0x0
    addi        r4, r1, 0x14
    li          r5, 0x4
    li          r6, 0x1
    li          r7, 0x0
    bl          EXIImm
    cntlzw      r0, r3
    addi        r3, r29, 0x0
    srwi        r28, r0, 5
    bl          EXISync
    cntlzw      r0, r3
    srwi        r0, r0, 5
    addi        r3, r29, 0x0
    addi        r4, r31, 0x0
    or          r28, r28, r0
    li          r5, 0x4
    li          r6, 0x0
    li          r7, 0x0
    bl          EXIImm
    cntlzw      r0, r3
    srwi        r0, r0, 5
    addi        r3, r29, 0x0
    or          r28, r28, r0
    bl          EXISync
    cntlzw      r0, r3
    srwi        r0, r0, 5
    addi        r3, r29, 0x0
    or          r28, r28, r0
    bl          EXIDeselect
    cntlzw      r0, r3
    srwi        r0, r0, 5
    or          r28, r28, r0
L_80015584:
    mr          r3, r29
    bl          EXIUnlock
L_8001558C:
    cmpwi       r29, 0x2
    beq         L_800155A4
    cmplwi      r30, 0x0
    bne         L_800155A4
    mr          r3, r29
    bl          EXIDetach
L_800155A4:
    cmpwi       r28, 0x0
    beq         L_800155B4
    li          r3, 0x0
    b           L_800155D0
L_800155B4:
    lwz         r3, 0x0(r31)
    addis       r0, r3, 0x1
    cmplwi      r0, 0xffff
    beq         L_800155CC
    li          r3, 0x1
    b           L_800155D0
L_800155CC:
    li          r3, 0x0
L_800155D0:
    lwz         r0, 0x2c(r1)
    lwz         r31, 0x24(r1)
    lwz         r30, 0x20(r1)
    lwz         r29, 0x1c(r1)
    lwz         r28, 0x18(r1)
    addi        r1, r1, 0x28
    mtlr        r0
    blr
}
#pragma pop

/* ---- __OSEnableBarnacle ---- */
#pragma push
#pragma force_active on
asm void __OSEnableBarnacle(register s32 chan, register u32 dev)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x20(r1)
    stw         r31, 0x1c(r1)
    addi        r31, r4, 0x0
    addi        r5, r1, 0x10
    stw         r30, 0x18(r1)
    addi        r30, r3, 0x0
    bl          EXIGetID
    cmpwi       r3, 0x0
    beq         L_80015794
    lwz         r4, 0x10(r1)
    lis         r0, 0x102
    cmpw        r4, r0
    beq         L_80015794
    bge         L_800156C0
    cmpwi       r4, 0x4
    beq         L_80015794
    bge         L_8001568C
    lis         r3, 0x8000
    addi        r0, r3, 0x10
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015670
    addi        r0, r3, 0x8
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015764
    addi        r0, r3, 0x4
    cmpw        r4, r0
    beq         L_80015794
    b           L_80015764
L_80015670:
    cmpwi       r4, -0x1
    beq         L_80015794
    bge         L_80015764
    addi        r0, r3, 0x20
    cmpw        r4, r0
    beq         L_80015794
    b           L_80015764
L_8001568C:
    cmpwi       r4, 0x20
    beq         L_80015794
    bge         L_800156B0
    cmpwi       r4, 0x10
    beq         L_80015794
    bge         L_80015764
    cmpwi       r4, 0x8
    beq         L_80015794
    b           L_80015764
L_800156B0:
    lis         r0, 0x101
    cmpw        r4, r0
    beq         L_80015794
    b           L_80015764
L_800156C0:
    lis         r3, 0x404
    addi        r0, r3, 0x404
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015728
    lis         r3, 0x402
    addi        r0, r3, 0x100
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015708
    lis         r0, 0x301
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015764
    lis         r0, 0x202
    cmpw        r4, r0
    beq         L_80015794
    b           L_80015764
L_80015708:
    addi        r0, r3, 0x300
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015764
    addi        r0, r3, 0x200
    cmpw        r4, r0
    beq         L_80015794
    b           L_80015764
L_80015728:
    lis         r0, 0x413
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015758
    lis         r0, 0x412
    cmpw        r4, r0
    beq         L_80015794
    bge         L_80015764
    lis         r0, 0x406
    cmpw        r4, r0
    beq         L_80015794
    b           L_80015764
L_80015758:
    lis         r0, 0x422
    cmpw        r4, r0
    beq         L_80015794
L_80015764:
    addi        r3, r30, 0x0
    addi        r4, r31, 0x0
    addi        r5, r1, 0x10
    bl          __EXIGetID
    cmpwi       r3, 0x0
    beq         L_80015794
    lis         r3, 0xa5ff
    stw	r30, lbl_801A6840 /* lbl_801A6840@sda21 */
    addi        r0, r3, 0x5a
    stw	r31, lbl_801A6844 /* lbl_801A6844@sda21 */
    stw	r0, lbl_801A684C /* lbl_801A684C@sda21 */
    stw	r0, lbl_801A6848 /* lbl_801A6848@sda21 */
L_80015794:
    lwz         r0, 0x24(r1)
    lwz         r31, 0x1c(r1)
    lwz         r30, 0x18(r1)
    addi        r1, r1, 0x20
    mtlr        r0
    blr
}
#pragma pop

/* ---- InitializeUART ---- */
#pragma push
#pragma force_active on
asm int InitializeUART(void)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x8(r1)
    lwz	r3, lbl_801A684C /* lbl_801A684C@sda21 */
    addis       r0, r3, 0x5a01
    cmplwi      r0, 0x5a
    bne         L_800157D0
    li          r3, 0x0
    b           L_8001580C
L_800157D0:
    bl          OSGetConsoleType
    rlwinm.     r0, r3, 0, 3, 3
    bne         L_800157EC
    li          r0, 0x0
    stw	r0, lbl_801A6848 /* lbl_801A6848@sda21 */
    li          r3, 0x2
    b           L_8001580C
L_800157EC:
    lis         r3, 0xa5ff
    addi        r0, r3, 0x5a
    li          r3, 0x0
    stw	r0, lbl_801A6848 /* lbl_801A6848@sda21 */
    li          r0, 0x1
    stw	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    li          r3, 0x0
    stw	r0, lbl_801A6844 /* lbl_801A6844@sda21 */
L_8001580C:
    lwz         r0, 0xc(r1)
    addi        r1, r1, 0x8
    mtlr        r0
    blr
}
#pragma pop

/* ---- WriteUARTN ---- */
#pragma push
#pragma force_active on
asm int WriteUARTN(register void* buffer, register s32 len)
{
    nofralloc
    mflr        r0
    stw         r0, 0x4(r1)
    stwu        r1, -0x38(r1)
    stmw        r25, 0x1c(r1)
    addi        r30, r3, 0x0
    addi        r31, r4, 0x0
    lwz	r5, lbl_801A6848 /* lbl_801A6848@sda21 */
    addis       r0, r5, 0x5a01
    cmplwi      r0, 0x5a
    beq         L_8001584C
    li          r3, 0x2
    b           L_80015A24
L_8001584C:
    bl          OSDisableInterrupts
    mr          r0, r3
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    lwz	r4, lbl_801A6844 /* lbl_801A6844@sda21 */
    mr          r27, r0
    li          r5, 0x0
    bl          EXILock
    cmpwi       r3, 0x0
    bne         L_80015880
    mr          r3, r27
    bl          OSRestoreInterrupts
    li          r3, 0x0
    b           L_80015A24
L_80015880:
    addi        r4, r30, 0x0
    li          r3, 0xd
    b           L_800158A0
L_8001588C:
    lbz         r0, 0x0(r4)
    cmpwi       r0, 0xa
    bne         L_8001589C
    stb         r3, 0x0(r4)
L_8001589C:
    addi        r4, r4, 0x1
L_800158A0:
    subf        r0, r30, r4
    cmplw       r0, r31
    blt         L_8001588C
    lis         r0, 0xa001
    stw         r0, 0x14(r1)
    li          r25, 0x0
    lis         r29, 0x2001
    b           L_80015A08
L_800158C0:
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    li          r5, 0x3
    lwz	r4, lbl_801A6844 /* lbl_801A6844@sda21 */
    bl          EXISelect
    cmpwi       r3, 0x0
    bne         L_800158E0
    li          r0, -0x1
    b           L_80015938
L_800158E0:
    stw         r29, 0x10(r1)
    addi        r4, r1, 0x10
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    li          r5, 0x4
    li          r6, 0x1
    li          r7, 0x0
    bl          EXIImm
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    bl          EXISync
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    addi        r4, r1, 0x10
    li          r5, 0x1
    li          r6, 0x0
    li          r7, 0x0
    bl          EXIImm
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    bl          EXISync
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    bl          EXIDeselect
    lwz         r0, 0x10(r1)
    srwi        r0, r0, 24
    subfic      r0, r0, 0x10
L_80015938:
    cmpwi       r0, 0x0
    mr          r26, r0
    bge         L_8001594C
    li          r25, 0x3
    b           L_80015A10
L_8001594C:
    cmpwi       r0, 0xc
    bge         L_8001595C
    cmplw       r0, r31
    blt         L_80015A08
L_8001595C:
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    li          r5, 0x3
    lwz	r4, lbl_801A6844 /* lbl_801A6844@sda21 */
    bl          EXISelect
    cmpwi       r3, 0x0
    bne         L_8001597C
    li          r25, 0x3
    b           L_80015A10
L_8001597C:
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    addi        r4, r1, 0x14
    li          r5, 0x4
    li          r6, 0x1
    li          r7, 0x0
    bl          EXIImm
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    bl          EXISync
    b           L_800159F0
L_800159A0:
    cmpwi       r26, 0x4
    bge         L_800159B0
    cmplw       r26, r31
    blt         L_80015A00
L_800159B0:
    cmplwi      r31, 0x4
    bge         L_800159C0
    mr          r28, r31
    b           L_800159C4
L_800159C0:
    li          r28, 0x4
L_800159C4:
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    mr          r5, r28
    addi        r4, r30, 0x0
    li          r6, 0x1
    li          r7, 0x0
    bl          EXIImm
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    add         r30, r30, r28
    subf        r31, r28, r31
    subf        r26, r28, r26
    bl          EXISync
L_800159F0:
    cmpwi       r26, 0x0
    beq         L_80015A00
    cmplwi      r31, 0x0
    bne         L_800159A0
L_80015A00:
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    bl          EXIDeselect
L_80015A08:
    cmplwi      r31, 0x0
    bne         L_800158C0
L_80015A10:
    lwz	r3, lbl_801A6840 /* lbl_801A6840@sda21 */
    bl          EXIUnlock
    mr          r3, r27
    bl          OSRestoreInterrupts
    mr          r3, r25
L_80015A24:
    lmw         r25, 0x1c(r1)
    lwz         r0, 0x3c(r1)
    addi        r1, r1, 0x38
    mtlr        r0
    blr
}
#pragma pop
