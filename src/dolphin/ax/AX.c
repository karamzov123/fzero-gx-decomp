#pragma push
#pragma force_active on

typedef signed int s32;
typedef unsigned int u32;

#define NULL ((void*) 0)

extern void OSRegisterVersion(const char* version);
extern void __AXInitVoiceStacks(void);
extern void __AXAllocQuit(void);
extern void __AXPushFreeStack(register void* p);
extern void* __AXPopCallbackStack(void);
extern void __AXRemoveFromStack(register void* p);
extern void fn_80022EA4(void);
extern void fn_80022420(void);
extern void AXInitAux(void);
extern void AXInitCommandList(void);
extern void fn_80021910(void);
extern void fn_80021C7C(void);
extern void fn_800230A0(void);
extern void fn_8002244C(void);
extern void AXClearAuxBufferPtrs(void);
extern void fn_80021FBC(void);
extern unsigned char __AXStackHead[128];
extern unsigned char __AXStackTail[128];

asm void fn_80020724(void)
{
    nofralloc
    li	r0, 0
    stb	r0, -0x7910(r13)
    stb	r0, -0x7910(r13)
    stb	r0, -0x7918(r13)
    stb	r0, -0x7920(r13)
    stb	r0, -0x7928(r13)
    stb	r0, -0x7930(r13)
    stb	r0, -0x7938(r13)
    stb	r0, -0x7940(r13)
    stb	r0, -0x7948(r13)
    stb	r0, -0x7950(r13)
    stb	r0, -0x7958(r13)
    stb	r0, -0x7960(r13)
    stb	r0, -0x7968(r13)
    stb	r0, -0x7970(r13)
    stb	r0, -0x7978(r13)
    stb	r0, -0x7980(r13)
    stb	r0, -0x7988(r13)
    stb	r0, -0x7990(r13)
    stb	r0, -0x7998(r13)
    blr	
}

asm void AXInit(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    lwz	r3, -0x7ed8(r13)
    bl      OSRegisterVersion
    bl      __AXInitVoiceStacks
    bl      fn_80022EA4
    bl      fn_80022420
    bl      AXInitAux
    bl      AXInitCommandList
    bl      fn_80021C7C
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void AXQuit(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    bl      __AXAllocQuit
    bl      fn_800230A0
    bl      fn_8002244C
    bl      AXClearAuxBufferPtrs
    bl      fn_80021910
    bl      fn_80021FBC
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void* __AXGetStackHead(register u32 priority)
{
    nofralloc
    lis     r4, __AXStackHead@ha
    slwi	r3, r3, 2
    addi	r0, r4, __AXStackHead@l
    add	r3, r0, r3
    lwz	r3, 0(r3)
    blr	
}

asm void __AXServiceCallbackStack(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x10(r1)
    stw	r31, 0xc(r1)
    bl      __AXPopCallbackStack
    mr	r31, r3
    b       _80020858
_8002081c:
    lwz	r0, 0xc(r31)
    cmplwi	r0, 0
    beq     _80020850
    lwz	r12, 0x10(r31)
    cmplwi	r12, 0
    beq     _80020840
    mtlr	r12
    addi	r3, r31, 0
    blrl	
_80020840:
    mr	r3, r31
    bl      __AXRemoveFromStack
    mr	r3, r31
    bl      __AXPushFreeStack
_80020850:
    bl      __AXPopCallbackStack
    mr	r31, r3
_80020858:
    cmplwi	r31, 0
    bne     _8002081c
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr	
}

asm void __AXInitVoiceStacks(void)
{
    nofralloc
    li	r0, 0
    stw	r0, -0x7908(r13)
    li	r0, 2
    lis     r4, __AXStackTail@ha
    mtctr	r0
    lis     r3, __AXStackHead@ha
    addi	r4, r4, __AXStackTail@l
    addi	r3, r3, __AXStackHead@l
_80020894:
    li	r0, 0
    stw	r0, 0(r4)
    stw	r0, 0(r3)
    stw	r0, 4(r4)
    stw	r0, 4(r3)
    stw	r0, 8(r4)
    stw	r0, 8(r3)
    stw	r0, 0xc(r4)
    stw	r0, 0xc(r3)
    stw	r0, 0x10(r4)
    stw	r0, 0x10(r3)
    stw	r0, 0x14(r4)
    stw	r0, 0x14(r3)
    stw	r0, 0x18(r4)
    stw	r0, 0x18(r3)
    stw	r0, 0x1c(r4)
    stw	r0, 0x1c(r3)
    stw	r0, 0x20(r4)
    stw	r0, 0x20(r3)
    stw	r0, 0x24(r4)
    stw	r0, 0x24(r3)
    stw	r0, 0x28(r4)
    stw	r0, 0x28(r3)
    stw	r0, 0x2c(r4)
    stw	r0, 0x2c(r3)
    stw	r0, 0x30(r4)
    stw	r0, 0x30(r3)
    stw	r0, 0x34(r4)
    stw	r0, 0x34(r3)
    stw	r0, 0x38(r4)
    stw	r0, 0x38(r3)
    stw	r0, 0x3c(r4)
    addi	r4, r4, 0x40
    stw	r0, 0x3c(r3)
    addi	r3, r3, 0x40
    bdnz    _80020894
    blr	
}

asm void __AXAllocQuit(void)
{
    nofralloc
    li	r0, 0
    stw	r0, -0x7908(r13)
    li	r0, 2
    lis     r4, __AXStackTail@ha
    mtctr	r0
    lis     r3, __AXStackHead@ha
    addi	r4, r4, __AXStackTail@l
    addi	r3, r3, __AXStackHead@l
_80020948:
    li	r0, 0
    stw	r0, 0(r4)
    stw	r0, 0(r3)
    stw	r0, 4(r4)
    stw	r0, 4(r3)
    stw	r0, 8(r4)
    stw	r0, 8(r3)
    stw	r0, 0xc(r4)
    stw	r0, 0xc(r3)
    stw	r0, 0x10(r4)
    stw	r0, 0x10(r3)
    stw	r0, 0x14(r4)
    stw	r0, 0x14(r3)
    stw	r0, 0x18(r4)
    stw	r0, 0x18(r3)
    stw	r0, 0x1c(r4)
    stw	r0, 0x1c(r3)
    stw	r0, 0x20(r4)
    stw	r0, 0x20(r3)
    stw	r0, 0x24(r4)
    stw	r0, 0x24(r3)
    stw	r0, 0x28(r4)
    stw	r0, 0x28(r3)
    stw	r0, 0x2c(r4)
    stw	r0, 0x2c(r3)
    stw	r0, 0x30(r4)
    stw	r0, 0x30(r3)
    stw	r0, 0x34(r4)
    stw	r0, 0x34(r3)
    stw	r0, 0x38(r4)
    stw	r0, 0x38(r3)
    stw	r0, 0x3c(r4)
    addi	r4, r4, 0x40
    stw	r0, 0x3c(r3)
    addi	r3, r3, 0x40
    bdnz    _80020948
    blr	
}

#pragma pop
