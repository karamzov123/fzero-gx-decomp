typedef int BOOL;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned long long u64;

typedef struct OSContext OSContext;
struct OSContext {
    u32 gpr[32];
    u32 cr;
    u32 lr;
    u32 ctr;
    u32 xer;
    double fpr[32];
    u32 fpscr_pad[2];
    u32 srr0;
    u32 srr1;
    u16 mode;
    u16 state;
    u32 gqr[8];
    u32 psf[32];
};

extern void OSRestoreInterrupts(register BOOL level);
extern void OSDisableInterrupts(void);
extern int vprintf(const char* format, char* arg);
extern void OSDumpContext(OSContext* context);
extern void PPCHalt(void);
extern u32 PPCMfmsr(void);
extern void PPCMtmsr(register u32 msr);
extern u32 PPCMffpscr(void);
extern void PPCMtfpscr(register u32 fpscr);
extern u64 OSGetTime(void);
extern void OSDisableScheduler(void);
extern void OSEnableScheduler(void);
extern void __OSReschedule(void);
extern void OSLoadContext(register OSContext* context);
extern void OSSaveFPUContext(register OSContext* context);
extern u32 OSGetStackPointer(void);
extern u32 __OSErrorTable[];

#pragma push
#pragma force_active on

asm void OSReport(const char* msg, ...)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x78(r1)
    bne     cr1, OSReport_skipSpill
    stfd    f1, 0x28(r1)
    stfd    f2, 0x30(r1)
    stfd    f3, 0x38(r1)
    stfd    f4, 0x40(r1)
    stfd    f5, 0x48(r1)
    stfd    f6, 0x50(r1)
    stfd    f7, 0x58(r1)
    stfd    f8, 0x60(r1)
OSReport_skipSpill:
    stw     r3, 8(r1)
    lis     r0, 0x100
    stw     r4, 0xC(r1)
    addi    r4, r1, 0x6C
    stw     r5, 0x10(r1)
    stw     r6, 0x14(r1)
    stw     r7, 0x18(r1)
    stw     r8, 0x1C(r1)
    stw     r9, 0x20(r1)
    stw     r10, 0x24(r1)
    stw     r0, 0x6C(r1)
    addi    r0, r1, 0x80
    stw     r0, 0x70(r1)
    addi    r0, r1, 0x8
    stw     r0, 0x74(r1)
    bl      vprintf
    lwz     r0, 0x7C(r1)
    addi    r1, r1, 0x78
    mtlr    r0
    blr
}

asm void OSPanic(const char* file, s32 line, const char* msg, ...)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x90(r1)
    stw     r31, 0x8C(r1)
    stw     r30, 0x88(r1)
    stw     r29, 0x84(r1)
    stw     r28, 0x80(r1)
    bne     cr1, OSPanic_skipSpill
    stfd    f1, 0x28(r1)
    stfd    f2, 0x30(r1)
    stfd    f3, 0x38(r1)
    stfd    f4, 0x40(r1)
    stfd    f5, 0x48(r1)
    stfd    f6, 0x50(r1)
    stfd    f7, 0x58(r1)
    stfd    f8, 0x60(r1)
OSPanic_skipSpill:
    stw     r3, 8(r1)
    addi    r28, r3, 0
    addi    r30, r4, 0
    stw     r4, 0xC(r1)
    addi    r29, r5, 0
    stw     r5, 0x10(r1)
    stw     r6, 0x14(r1)
    lis     r6, 0x8012
    addi    r31, r6, 0x2C30
    stw     r7, 0x18(r1)
    stw     r8, 0x1C(r1)
    stw     r9, 0x20(r1)
    stw     r10, 0x24(r1)
    bl      OSDisableInterrupts
    lis     r0, 0x300
    stw     r0, 0x74(r1)
    addi    r0, r1, 0x98
    addi    r4, r1, 0x74
    stw     r0, 0x78(r1)
    addi    r0, r1, 0x8
    addi    r3, r29, 0
    stw     r0, 0x7C(r1)
    bl      vprintf
    addi    r3, r31, 0
    crxor   6, 6, 6
    addi    r4, r28, 0
    addi    r5, r30, 0
    bl      OSReport
    addi    r3, r31, 0x18
    crxor   6, 6, 6
    bl      OSReport
    li      r30, 0
    bl      OSGetStackPointer
    mr      r29, r3
    b       OSPanic_check
OSPanic_loop:
    lwz     r5, 0(r29)
    mr      r4, r29
    lwz     r6, 4(r29)
    addi    r3, r31, 0x40
    crxor   6, 6, 6
    bl      OSReport
    lwz     r29, 0(r29)
OSPanic_check:
    cmplwi  r29, 0
    beq     OSPanic_halt
    addis   r0, r29, 1
    cmplwi  r0, 0xFFFF
    beq     OSPanic_halt
    cmplwi  r30, 0x10
    addi    r30, r30, 1
    blt     OSPanic_loop
OSPanic_halt:
    bl      PPCHalt
    lwz     r0, 0x94(r1)
    lwz     r31, 0x8C(r1)
    lwz     r30, 0x88(r1)
    lwz     r29, 0x84(r1)
    lwz     r28, 0x80(r1)
    addi    r1, r1, 0x90
    mtlr    r0
    blr
}

asm void * OSSetErrorHandler(s32 error, void* handler)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x30(r1)
    stw     r31, 0x2C(r1)
    stw     r30, 0x28(r1)
    stw     r29, 0x24(r1)
    addi    r29, r3, 0
    stw     r28, 0x20(r1)
    addi    r28, r4, 0
    bl      OSDisableInterrupts
    lis     r4, __OSErrorTable@ha
    clrlslwi r5, r29, 16, 2
    addi    r0, r4, __OSErrorTable@l
    clrlwi  r6, r29, 16
    add     r4, r0, r5
    lwz     r30, 0(r4)
    cmplwi  r6, 0x10
    mr      r29, r3
    stw     r28, 0(r4)
    bne     OSSetErrorHandler_done
    bl      PPCMfmsr
    addi    r31, r3, 0
    ori     r3, r31, 0x2000
    bl      PPCMtmsr
    bl      PPCMffpscr
    cmplwi  r28, 0
    beq     OSSetErrorHandler_clearPath
    lis     r5, 0x8000
    lis     r4, 0x6006
    lwz     r6, 0xDC(r5)
    subi    r4, r4, 0x701
    b       OSSetErrorHandler_ctxCheck
OSSetErrorHandler_ctxLoop:
    lwz     r0, 0x19C(r6)
    ori     r0, r0, 0x900
    stw     r0, 0x19C(r6)
    lhz     r5, 0x1A2(r6)
    clrlwi. r0, r5, 31
    bne     OSSetErrorHandler_setField
    ori     r5, r5, 1
    li      r0, 4
    sth     r5, 0x1A2(r6)
    mtctr   r0
    addi    r5, r6, 0
OSSetErrorHandler_fillLoop:
    li      r0, -1
    stw     r0, 0x94(r5)
    stw     r0, 0x90(r5)
    stw     r0, 0x1CC(r5)
    stw     r0, 0x1C8(r5)
    stw     r0, 0x9C(r5)
    stw     r0, 0x98(r5)
    stw     r0, 0x1D4(r5)
    stw     r0, 0x1D0(r5)
    stw     r0, 0xA4(r5)
    stw     r0, 0xA0(r5)
    stw     r0, 0x1DC(r5)
    stw     r0, 0x1D8(r5)
    stw     r0, 0xAC(r5)
    stw     r0, 0xA8(r5)
    stw     r0, 0x1E4(r5)
    stw     r0, 0x1E0(r5)
    stw     r0, 0xB4(r5)
    stw     r0, 0xB0(r5)
    stw     r0, 0x1EC(r5)
    stw     r0, 0x1E8(r5)
    stw     r0, 0xBC(r5)
    stw     r0, 0xB8(r5)
    stw     r0, 0x1F4(r5)
    stw     r0, 0x1F0(r5)
    stw     r0, 0xC4(r5)
    stw     r0, 0xC0(r5)
    stw     r0, 0x1FC(r5)
    stw     r0, 0x1F8(r5)
    stw     r0, 0xCC(r5)
    stw     r0, 0xC8(r5)
    stw     r0, 0x204(r5)
    stw     r0, 0x200(r5)
    addi    r5, r5, 0x40
    bdnz    OSSetErrorHandler_fillLoop
    li      r0, 4
    stw     r0, 0x194(r6)
OSSetErrorHandler_setField:
    lwz     r0, -0x7F90(r13)
    lwz     r5, 0x194(r6)
    rlwinm  r0, r0, 0, 24, 28
    or      r0, r5, r0
    stw     r0, 0x194(r6)
    lwz     r0, 0x194(r6)
    and     r0, r0, r4
    stw     r0, 0x194(r6)
    lwz     r6, 0x2FC(r6)
OSSetErrorHandler_ctxCheck:
    cmplwi  r6, 0
    bne     OSSetErrorHandler_ctxLoop
    lwz     r0, -0x7F90(r13)
    ori     r31, r31, 0x900
    rlwinm  r0, r0, 0, 24, 28
    or      r3, r3, r0
    b       OSSetErrorHandler_fpscrSet
OSSetErrorHandler_clearPath:
    lis     r5, 0x8000
    lis     r4, 0x6006
    lwz     r6, 0xDC(r5)
    subi    r4, r4, 0x701
    li      r5, -0x901
    b       OSSetErrorHandler_clrCheck
OSSetErrorHandler_clrLoop:
    lwz     r0, 0x19C(r6)
    and     r0, r0, r5
    stw     r0, 0x19C(r6)
    lwz     r0, 0x194(r6)
    rlwinm  r0, r0, 0, 29, 23
    stw     r0, 0x194(r6)
    lwz     r0, 0x194(r6)
    and     r0, r0, r4
    stw     r0, 0x194(r6)
    lwz     r6, 0x2FC(r6)
OSSetErrorHandler_clrCheck:
    cmplwi  r6, 0
    bne     OSSetErrorHandler_clrLoop
    li      r0, -0x901
    rlwinm  r3, r3, 0, 29, 23
    and     r31, r31, r0
OSSetErrorHandler_fpscrSet:
    lis     r4, 0x6006
    subi    r0, r4, 0x701
    and     r3, r3, r0
    bl      PPCMtfpscr
    mr      r3, r31
    bl      PPCMtmsr
OSSetErrorHandler_done:
    mr      r3, r29
    bl      OSRestoreInterrupts
    mr      r3, r30
    lwz     r0, 0x34(r1)
    lwz     r31, 0x2C(r1)
    lwz     r30, 0x28(r1)
    lwz     r29, 0x24(r1)
    lwz     r28, 0x20(r1)
    addi    r1, r1, 0x30
    mtlr    r0
    blr
}

asm void __OSUnhandledException(unsigned char exception, OSContext* context,
                                u32 dsisr, u32 dar)
{
    nofralloc
    mflr    r0
    lis     r8, __OSErrorTable@ha
    stw     r0, 4(r1)
    lis     r7, 0x8012
    stwu    r1, -0x40(r1)
    stmw    r22, 0x18(r1)
    addi    r24, r3, 0
    addi    r25, r4, 0
    addi    r26, r5, 0
    addi    r27, r6, 0
    addi    r30, r8, __OSErrorTable@l
    addi    r31, r7, 0x2C30
    bl      OSGetTime
    lwz     r5, 0x19C(r25)
    addi    r28, r4, 0
    addi    r29, r3, 0
    rlwinm. r0, r5, 0, 30, 30
    bne     Unhandled_nonFatal
    addi    r3, r31, 0x5C
    crxor   6, 6, 6
    clrlwi  r4, r24, 24
    bl      OSReport
    b       Unhandled_afterDispatch
Unhandled_nonFatal:
    clrlwi  r0, r24, 24
    cmplwi  r0, 6
    bne     Unhandled_dispatch
    rlwinm. r0, r5, 0, 11, 11
    beq     Unhandled_dispatch
    lwz     r0, 0x40(r30)
    cmplwi  r0, 0
    beq     Unhandled_dispatch
    li      r24, 0x10
    bl      PPCMfmsr
    addi    r23, r3, 0
    ori     r3, r23, 0x2000
    bl      PPCMtmsr
    lis     r3, 0x8000
    lwz     r3, 0xD8(r3)
    cmplwi  r3, 0
    beq     Unhandled_noSaveFPU
    bl      OSSaveFPUContext
Unhandled_noSaveFPU:
    bl      PPCMffpscr
    lis     r4, 0x6006
    subi    r22, r4, 0x701
    and     r3, r3, r22
    bl      PPCMtfpscr
    mr      r3, r23
    bl      PPCMtmsr
    lis     r23, 0x8000
    lwz     r0, 0xD8(r23)
    cmplw   r0, r25
    bne     Unhandled_clearState
    bl      OSDisableScheduler
    lwz     r12, 0x40(r30)
    addi    r4, r25, 0
    addi    r5, r26, 0
    crxor   6, 6, 6
    mtlr    r12
    addi    r6, r27, 0
    li      r3, 0x10
    blrl
    lwz     r3, 0x19C(r25)
    li      r0, 0
    rlwinm  r3, r3, 0, 19, 17
    stw     r3, 0x19C(r25)
    stw     r0, 0xD8(r23)
    lwz     r0, 0x194(r25)
    and     r0, r0, r22
    stw     r0, 0x194(r25)
    bl      OSEnableScheduler
    bl      __OSReschedule
    b       Unhandled_loadCtx
Unhandled_clearState:
    lwz     r3, 0x19C(r25)
    li      r0, 0
    rlwinm  r3, r3, 0, 19, 17
    stw     r3, 0x19C(r25)
    stw     r0, 0xD8(r23)
Unhandled_loadCtx:
    mr      r3, r25
    bl      OSLoadContext
Unhandled_dispatch:
    clrlwi  r23, r24, 24
    clrlslwi r0, r24, 24, 2
    add     r22, r30, r0
    lwz     r0, 0(r22)
    cmplwi  r0, 0
    beq     Unhandled_checkDecrementer
    bl      OSDisableScheduler
    lwz     r12, 0(r22)
    addi    r3, r23, 0
    addi    r4, r25, 0
    crxor   6, 6, 6
    mtlr    r12
    addi    r5, r26, 0
    addi    r6, r27, 0
    blrl
    bl      OSEnableScheduler
    bl      __OSReschedule
    mr      r3, r25
    bl      OSLoadContext
Unhandled_checkDecrementer:
    clrlwi  r0, r24, 24
    cmplwi  r0, 8
    bne     Unhandled_report
    mr      r3, r25
    bl      OSLoadContext
Unhandled_report:
    addi    r3, r31, 0x7C
    crxor   6, 6, 6
    clrlwi  r4, r24, 24
    bl      OSReport
Unhandled_afterDispatch:
    addi    r3, r13, -0x7F8C
    crxor   6, 6, 6
    bl      OSReport
    mr      r3, r25
    bl      OSDumpContext
    addi    r4, r26, 0
    crxor   6, 6, 6
    addi    r5, r27, 0
    addi    r3, r31, 0x94
    bl      OSReport
    addi    r6, r28, 0
    crxor   6, 6, 6
    addi    r5, r29, 0
    addi    r3, r31, 0xC8
    bl      OSReport
    clrlwi  r0, r24, 24
    cmplwi  r0, 0xF
    bgt     Unhandled_lastInterrupt
    lis     r3, 0x8012
    addi    r3, r3, 0x2F0C
    slwi    r0, r0, 2
    lwzx    r0, r3, r0
    mtctr   r0
    bctr
    lwz     r4, 0x198(r25)
    addi    r5, r27, 0
    addi    r3, r31, 0xD8
    crxor   6, 6, 6
    bl      OSReport
    b       Unhandled_lastInterrupt
    lwz     r4, 0x198(r25)
    addi    r3, r31, 0x138
    crxor   6, 6, 6
    bl      OSReport
    b       Unhandled_lastInterrupt
    lwz     r4, 0x198(r25)
    addi    r5, r27, 0
    addi    r3, r31, 0x184
    crxor   6, 6, 6
    bl      OSReport
    b       Unhandled_lastInterrupt
    lwz     r4, 0x198(r25)
    addi    r5, r27, 0
    addi    r3, r31, 0x1E8
    crxor   6, 6, 6
    bl      OSReport
    b       Unhandled_lastInterrupt
    addi    r3, r13, -0x7F8C
    crxor   6, 6, 6
    bl      OSReport
    lis     r25, 0xCC00
    crxor   6, 6, 6
    addi    r24, r25, 0x5000
    lhz     r4, 0x5030(r25)
    addi    r3, r31, 0x248
    lhz     r5, 0x5032(r25)
    bl      OSReport
    lhz     r4, 0x20(r24)
    addi    r3, r31, 0x268
    lhz     r5, 0x22(r24)
    crxor   6, 6, 6
    bl      OSReport
    lwz     r4, 0x6014(r25)
    crxor   6, 6, 6
    addi    r3, r31, 0x288
    bl      OSReport
Unhandled_lastInterrupt:
    lha     r4, -0x7C10(r13)
    addi    r3, r31, 0x2A4
    crxor   6, 6, 6
    lwz     r5, -0x7C14(r13)
    lwz     r7, -0x7C08(r13)
    lwz     r8, -0x7C04(r13)
    bl      OSReport
    bl      PPCHalt
    lmw     r22, 0x18(r1)
    lwz     r0, 0x44(r1)
    addi    r1, r1, 0x40
    mtlr    r0
    blr
}

#pragma pop
