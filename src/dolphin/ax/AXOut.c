#pragma push
#pragma force_active on

typedef unsigned int u32;
typedef int BOOL;
extern unsigned long long OSGetTime(void);
extern void fn_80022BF4(void);
extern void fn_80022028(void);
extern void __AXSwapCommandList(void);
extern void DSPSendMailToDSP(void);
extern void DSPCheckMailToDSP(void);
extern void __AXServiceCallbackStack(void);
extern void fn_80020FA4(void);
extern void AXPushCLCommands(void);
extern void AIInitDMA(void);
extern void fn_800224E4(void);
extern void fn_800235D4(void);
extern void DSPAssertTask(void);
extern void OSWakeupThread(register void* queue);
extern void OSInitThreadQueue(register void* queue);
extern void DSPCheckInit(void);
extern void DSPInit(void);
extern void DSPAddTask(void);
extern void DCFlushRange(register void* addr, register u32 nBytes);
extern void AIRegisterDMACallback(void);
extern void AIStartDMA(void);
extern BOOL OSDisableInterrupts(void);
extern void DSPCancelTask(void);
extern void OSSleepThread(register void* queue);
extern void AIStopDMA(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern unsigned char lbl_80126240[7968];
extern unsigned char lbl_80160500[1920];
extern unsigned char lbl_80160C80[16544];

extern unsigned char lbl_801A64F0[8];
extern unsigned char lbl_801A6B30[8];
extern unsigned char lbl_801A6B10[4];
extern unsigned char lbl_801A6B14[4];
extern unsigned char lbl_801A6B18[4];
extern unsigned char lbl_801A6B1C[4];
extern unsigned char lbl_801A6B20[4];
extern unsigned char lbl_801A6B24[4];
extern unsigned char lbl_801A6B28[4];
extern unsigned char lbl_801A6B2C[4];
asm void __AXOutFrameTask(void)
{
    nofralloc
    mflr	r0
    lis     r4, lbl_80160500@ha
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    addi	r31, r4, lbl_80160500@l
    stw	r30, 0x10(r1)
    addi	r30, r3, 0
    bl      OSGetTime
    stw	r4, 0x47d4(r31)
    stw	r3, 0x47d0(r31)
    mr	r3, r30
    bl      fn_80022BF4
    bl      fn_80022028
    bl      __AXSwapCommandList
    lis	r4, -0x4542
    addi	r30, r3, 0
    addi	r3, r4, 0x180
    bl      DSPSendMailToDSP
_8002197c:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _8002197c
    mr	r3, r30
    bl      DSPSendMailToDSP
_80021990:
    bl      DSPCheckMailToDSP
    cmplwi	r3, 0
    bne     _80021990
    bl      __AXServiceCallbackStack
    bl      OSGetTime
    stw	r4, 0x47dc(r31)
    stw	r3, 0x47d8(r31)
    bl      fn_80020FA4
    bl      OSGetTime
    stw	r4, 0x47e4(r31)
    stw	r3, 0x47e0(r31)
    bl      OSGetTime
    stw	r4, 0x47ec(r31)
    stw	r3, 0x47e8(r31)
    lwz	r12, lbl_801A6B20
    cmplwi	r12, 0
    beq     _800219dc
    mtlr	r12
    blrl	
_800219dc:
    bl      OSGetTime
    stw	r4, 0x47f4(r31)
    stw	r3, 0x47f0(r31)
    addi	r3, r31, 0x500
    lwz	r0, lbl_801A6B10
    mulli	r0, r0, 0x280
    add	r4, r31, r0
    bl      AXPushCLCommands
    lwz	r3, lbl_801A6B10
    li	r4, 0x280
    addi	r0, r3, 1
    stw	r0, lbl_801A6B10
    lwz	r0, lbl_801A6B10
    clrlwi	r0, r0, 0x1f
    stw	r0, lbl_801A6B10
    lwz	r0, lbl_801A6B10
    mulli	r0, r0, 0x280
    add	r3, r31, r0
    bl      AIInitDMA
    bl      OSGetTime
    stw	r4, 0x47fc(r31)
    stw	r3, 0x47f8(r31)
    bl      fn_800224E4
    stw	r3, 0x4800(r31)
    bl      fn_800235D4
    cmplwi	r3, 0
    beq     _80021aa0
    li	r0, 7
    mtctr	r0
    addi	r4, r31, 0x47d0
_80021a54:
    lbz	r0, 0(r4)
    stb	r0, 0(r3)
    lbz	r0, 1(r4)
    stb	r0, 1(r3)
    lbz	r0, 2(r4)
    stb	r0, 2(r3)
    lbz	r0, 3(r4)
    stb	r0, 3(r3)
    lbz	r0, 4(r4)
    stb	r0, 4(r3)
    lbz	r0, 5(r4)
    stb	r0, 5(r3)
    lbz	r0, 6(r4)
    stb	r0, 6(r3)
    lbz	r0, 7(r4)
    addi	r4, r4, 8
    stb	r0, 7(r3)
    addi	r3, r3, 8
    bdnz    _80021a54
_80021aa0:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void __AXOutFirstFrameCallback(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    lwz	r0, lbl_801A6B14
    cmplwi	r0, 0
    bne     _80021adc
    bl      OSGetTime
    stw	r4, lbl_801A6B1C
    stw	r3, lbl_801A6B18
_80021adc:
    lwz	r0, lbl_801A6B14
    cmplwi	r0, 1
    bne     _80021afc
    li	r0, 0
    stw	r0, lbl_801A6B14
    li	r3, 0
    bl      __AXOutFrameTask
    b       _80021b10
_80021afc:
    li	r0, 2
    lis     r3, lbl_80160C80@ha
    stw	r0, lbl_801A6B14
    addi	r3, r3, lbl_80160C80@l
    bl      DSPAssertTask
_80021b10:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

void fn_80021B20(void)
{
    // provenance: original fn_80021B20
    *(u32*)lbl_801A6B24 = 1;
}

asm void __AXOutDspResumeCallback(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    lwz	r0, lbl_801A6B14
    cmplwi	r0, 2
    bne     _80021b6c
    li	r0, 0
    stw	r0, lbl_801A6B14
    bl      OSGetTime
    lwz	r5, lbl_801A6B18
    lwz	r0, lbl_801A6B1C
    subfc	r0, r0, r4
    srwi	r0, r0, 2
    mr	r3, r0
    bl      __AXOutFrameTask
    b       _80021b74
_80021b6c:
    li	r0, 1
    stw	r0, lbl_801A6B14
_80021b74:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void fn_80021B84(void)
{
    nofralloc
    mflr	r0
    li	r3, lbl_801A6B30
    stw	r0, 4(r1)
    li	r0, 1
    stwu	r1, -8(r1)
    stw	r0, lbl_801A6B28
    bl      OSWakeupThread
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void AXInitOutput(void)
{
    nofralloc
    mflr	r0
    lis	r5, fn_80021B20@ha
    stw	r0, 4(r1)
    lis     r3, lbl_80126240@ha
    addi	r0, r3, lbl_80126240@l
    stwu	r1, -0x10(r1)
    lis     r4, lbl_80160500@ha
    li	r9, 0
    stw	r31, 0xc(r1)
    addi	r31, r4, lbl_80160500@l
    lis	r4, __AXOutDspResumeCallback@ha
    stw	r0, 0x78c(r31)
    addi	r8, r31, 0x7d0
    li	r7, 0x10
    lhz	r0, lbl_801A64F0
    li	r6, 0x30
    addi	r5, r5, fn_80021B20@l
    stw	r0, 0x790(r31)
    li	r0, 0x2000
    addi	r4, r4, __AXOutDspResumeCallback@l
    stw	r9, 0x794(r31)
    lis     r3, fn_80021B84@ha
    stw	r8, 0x798(r31)
    stw	r0, 0x79c(r31)
    addi	r0, r3, fn_80021B84@l
    li	r3, lbl_801A6B30
    stw	r9, 0x7a0(r31)
    sth	r7, 0x7a4(r31)
    sth	r6, 0x7a6(r31)
    stw	r5, 0x7a8(r31)
    stw	r4, 0x7ac(r31)
    stw	r0, 0x7b0(r31)
    stw	r9, 0x7b4(r31)
    stw	r9, 0x784(r31)
    stw	r9, lbl_801A6B24
    stw	r9, lbl_801A6B28
    bl      OSInitThreadQueue
    bl      DSPCheckInit
    cmpwi	r3, 0
    bne     _80021c54
    bl      DSPInit
_80021c54:
    addi	r3, r31, 0x780
    bl      DSPAddTask
_80021c5c:
    lwz	r0, lbl_801A6B24
    cmpwi	r0, 0
    beq     _80021c5c
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr	
}

asm void fn_80021C7C(void)
{
    nofralloc
    mflr	r0
    li	r3, 0
    stw	r0, 4(r1)
    li	r0, 4
    lis     r4, lbl_80160500@ha
    mtctr	r0
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r4, lbl_80160500@l
    addi	r4, r31, 0
    stw	r3, lbl_801A6B10
    stw	r3, lbl_801A6B2C
_80021cac:
    stw	r3, 0(r4)
    stw	r3, 4(r4)
    stw	r3, 8(r4)
    stw	r3, 0xc(r4)
    stw	r3, 0x10(r4)
    stw	r3, 0x14(r4)
    stw	r3, 0x18(r4)
    stw	r3, 0x1c(r4)
    stw	r3, 0x20(r4)
    stw	r3, 0x24(r4)
    stw	r3, 0x28(r4)
    stw	r3, 0x2c(r4)
    stw	r3, 0x30(r4)
    stw	r3, 0x34(r4)
    stw	r3, 0x38(r4)
    stw	r3, 0x3c(r4)
    stw	r3, 0x40(r4)
    stw	r3, 0x44(r4)
    stw	r3, 0x48(r4)
    stw	r3, 0x4c(r4)
    stw	r3, 0x50(r4)
    stw	r3, 0x54(r4)
    stw	r3, 0x58(r4)
    stw	r3, 0x5c(r4)
    stw	r3, 0x60(r4)
    stw	r3, 0x64(r4)
    stw	r3, 0x68(r4)
    stw	r3, 0x6c(r4)
    stw	r3, 0x70(r4)
    stw	r3, 0x74(r4)
    stw	r3, 0x78(r4)
    stw	r3, 0x7c(r4)
    stw	r3, 0x80(r4)
    stw	r3, 0x84(r4)
    stw	r3, 0x88(r4)
    stw	r3, 0x8c(r4)
    stw	r3, 0x90(r4)
    stw	r3, 0x94(r4)
    stw	r3, 0x98(r4)
    stw	r3, 0x9c(r4)
    stw	r3, 0xa0(r4)
    stw	r3, 0xa4(r4)
    stw	r3, 0xa8(r4)
    stw	r3, 0xac(r4)
    stw	r3, 0xb0(r4)
    stw	r3, 0xb4(r4)
    stw	r3, 0xb8(r4)
    stw	r3, 0xbc(r4)
    stw	r3, 0xc0(r4)
    stw	r3, 0xc4(r4)
    stw	r3, 0xc8(r4)
    stw	r3, 0xcc(r4)
    stw	r3, 0xd0(r4)
    stw	r3, 0xd4(r4)
    stw	r3, 0xd8(r4)
    stw	r3, 0xdc(r4)
    stw	r3, 0xe0(r4)
    stw	r3, 0xe4(r4)
    stw	r3, 0xe8(r4)
    stw	r3, 0xec(r4)
    stw	r3, 0xf0(r4)
    stw	r3, 0xf4(r4)
    stw	r3, 0xf8(r4)
    stw	r3, 0xfc(r4)
    stw	r3, 0x100(r4)
    stw	r3, 0x104(r4)
    stw	r3, 0x108(r4)
    stw	r3, 0x10c(r4)
    stw	r3, 0x110(r4)
    stw	r3, 0x114(r4)
    stw	r3, 0x118(r4)
    stw	r3, 0x11c(r4)
    stw	r3, 0x120(r4)
    stw	r3, 0x124(r4)
    stw	r3, 0x128(r4)
    stw	r3, 0x12c(r4)
    stw	r3, 0x130(r4)
    stw	r3, 0x134(r4)
    stw	r3, 0x138(r4)
    stw	r3, 0x13c(r4)
    addi	r4, r4, 0x140
    bdnz    _80021cac
    addi	r3, r31, 0
    li	r4, 0x500
    bl      DCFlushRange
    li	r0, 2
    mtctr	r0
    addi	r3, r31, 0x500
    li	r0, 0
_80021e10:
    stw	r0, 0(r3)
    stw	r0, 4(r3)
    stw	r0, 8(r3)
    stw	r0, 0xc(r3)
    stw	r0, 0x10(r3)
    stw	r0, 0x14(r3)
    stw	r0, 0x18(r3)
    stw	r0, 0x1c(r3)
    stw	r0, 0x20(r3)
    stw	r0, 0x24(r3)
    stw	r0, 0x28(r3)
    stw	r0, 0x2c(r3)
    stw	r0, 0x30(r3)
    stw	r0, 0x34(r3)
    stw	r0, 0x38(r3)
    stw	r0, 0x3c(r3)
    stw	r0, 0x40(r3)
    stw	r0, 0x44(r3)
    stw	r0, 0x48(r3)
    stw	r0, 0x4c(r3)
    stw	r0, 0x50(r3)
    stw	r0, 0x54(r3)
    stw	r0, 0x58(r3)
    stw	r0, 0x5c(r3)
    stw	r0, 0x60(r3)
    stw	r0, 0x64(r3)
    stw	r0, 0x68(r3)
    stw	r0, 0x6c(r3)
    stw	r0, 0x70(r3)
    stw	r0, 0x74(r3)
    stw	r0, 0x78(r3)
    stw	r0, 0x7c(r3)
    stw	r0, 0x80(r3)
    stw	r0, 0x84(r3)
    stw	r0, 0x88(r3)
    stw	r0, 0x8c(r3)
    stw	r0, 0x90(r3)
    stw	r0, 0x94(r3)
    stw	r0, 0x98(r3)
    stw	r0, 0x9c(r3)
    stw	r0, 0xa0(r3)
    stw	r0, 0xa4(r3)
    stw	r0, 0xa8(r3)
    stw	r0, 0xac(r3)
    stw	r0, 0xb0(r3)
    stw	r0, 0xb4(r3)
    stw	r0, 0xb8(r3)
    stw	r0, 0xbc(r3)
    stw	r0, 0xc0(r3)
    stw	r0, 0xc4(r3)
    stw	r0, 0xc8(r3)
    stw	r0, 0xcc(r3)
    stw	r0, 0xd0(r3)
    stw	r0, 0xd4(r3)
    stw	r0, 0xd8(r3)
    stw	r0, 0xdc(r3)
    stw	r0, 0xe0(r3)
    stw	r0, 0xe4(r3)
    stw	r0, 0xe8(r3)
    stw	r0, 0xec(r3)
    stw	r0, 0xf0(r3)
    stw	r0, 0xf4(r3)
    stw	r0, 0xf8(r3)
    stw	r0, 0xfc(r3)
    stw	r0, 0x100(r3)
    stw	r0, 0x104(r3)
    stw	r0, 0x108(r3)
    stw	r0, 0x10c(r3)
    stw	r0, 0x110(r3)
    stw	r0, 0x114(r3)
    stw	r0, 0x118(r3)
    stw	r0, 0x11c(r3)
    stw	r0, 0x120(r3)
    stw	r0, 0x124(r3)
    stw	r0, 0x128(r3)
    stw	r0, 0x12c(r3)
    stw	r0, 0x130(r3)
    stw	r0, 0x134(r3)
    stw	r0, 0x138(r3)
    stw	r0, 0x13c(r3)
    addi	r3, r3, 0x140
    bdnz    _80021e10
    addi	r3, r31, 0x500
    li	r4, 0x280
    bl      DCFlushRange
    bl      AXInitOutput
    lis     r3, __AXOutFirstFrameCallback@ha
    addi	r3, r3, __AXOutFirstFrameCallback@l
    bl      AIRegisterDMACallback
    addi	r3, r31, 0x500
    addi	r4, r31, 0x280
    bl      AXPushCLCommands
    li	r0, 1
    stw	r0, lbl_801A6B14
    li	r3, 0
    li	r4, 0x280
    lwz	r0, lbl_801A6B10
    stw	r3, lbl_801A6B20
    mulli	r0, r0, 0x280
    add	r3, r31, r0
    bl      AIInitDMA
    bl      AIStartDMA
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void fn_80021FBC(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x10(r1)
    stw	r31, 0xc(r1)
    bl      OSDisableInterrupts
    li	r0, 0
    lis     r4, lbl_80160C80@ha
    stw	r0, lbl_801A6B20
    addi	r0, r4, lbl_80160C80@l
    addi	r31, r3, 0
    mr	r3, r0
    bl      DSPCancelTask
    li	r3, lbl_801A6B30
    bl      OSSleepThread
    bl      AIStopDMA
    mr	r3, r31
    bl      OSRestoreInterrupts
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr	
}

void fn_80022014(register void* p)
{
    *(volatile void**)lbl_801A6B20 = p;
}

#pragma pop
