#pragma push
#pragma force_active on

typedef unsigned int u32;
extern void fn_8002201C(void);
extern void fn_80022E5C(void);
extern void AXGetAuxBufferA_Active(void);
extern void AXGetAuxBufferB_500(void);
extern void AXGetAuxBufferA_Current(void);
extern void AXGetAuxBufferA_280(void);
extern void AXGetAuxBufferA_500(void);
extern void AXGetAuxBufferB_Current500(void);
extern void AXGetAuxBufferB_280(void);
extern void AXGetAuxBufferB_Unknown(void);
extern void AXGetAuxBufferB_Active(void);
extern void AXGetAuxBufferB_Current(void);
extern void DCFlushRange(register void* addr, register u32 nBytes);
extern unsigned char lbl_80124800[6720];
extern unsigned char lbl_8015FF00[1536];

asm void fn_80021200(void)
{
    nofralloc
    lwz	r5, -0x78c8(r13)
    lis     r3, lbl_8015FF00@ha
    addi	r4, r3, lbl_8015FF00@l
    addi	r0, r5, 1
    stw	r0, -0x78c8(r13)
    mulli	r3, r5, 0x300
    lwz	r0, -0x78c8(r13)
    add	r3, r4, r3
    clrlwi	r0, r0, 0x1f
    stw	r0, -0x78c8(r13)
    lwz	r0, -0x78c8(r13)
    mulli	r0, r0, 0x300
    add	r0, r4, r0
    stw	r0, -0x78c4(r13)
    blr	
}

asm void fn_8002123C(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    li	r0, 0x1a9
    stwu	r1, -0x60(r1)
    stw	r31, 0x5c(r1)
    stw	r30, 0x58(r1)
    addi	r30, r4, 0
    stw	r29, 0x54(r1)
    addi	r29, r3, 0
    lwz	r31, -0x78c4(r13)
    stw	r0, -0x78c0(r13)
    bl      fn_8002201C
    stw	r3, 0x48(r1)
    li	r0, 0
    lwz	r3, -0x78c4(r13)
    sth	r0, 0(r3)
    lwz	r3, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r3, r3, 2
    stw	r3, -0x78c4(r13)
    srwi	r0, r0, 0x10
    lwz	r3, -0x78c4(r13)
    sth	r0, 0(r3)
    lwz	r3, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r3, r3, 2
    stw	r3, -0x78c4(r13)
    lwz	r3, -0x78c4(r13)
    sth	r0, 0(r3)
    lwz	r4, -0x78c4(r13)
    lwz	r3, -0x78c0(r13)
    lwz	r0, -0x78b8(r13)
    addi	r4, r4, 2
    addi	r3, r3, 0x2e44
    stw	r4, -0x78c4(r13)
    cmpwi	r0, 1
    stw	r3, -0x78c0(r13)
    beq     _8002133c
    bge     _8002138c
    cmpwi	r0, 0
    bge     _800212e8
    b       _8002138c
    b       _8002138c
_800212e8:
    lwz	r3, -0x78c4(r13)
    li	r4, 7
    srwi	r0, r29, 0x10
    sth	r4, 0(r3)
    lwz	r3, -0x78c4(r13)
    addi	r3, r3, 2
    stw	r3, -0x78c4(r13)
    lwz	r3, -0x78c4(r13)
    sth	r0, 0(r3)
    lwz	r3, -0x78c4(r13)
    addi	r0, r3, 2
    stw	r0, -0x78c4(r13)
    lwz	r3, -0x78c4(r13)
    sth	r29, 0(r3)
    lwz	r4, -0x78c4(r13)
    lwz	r3, -0x78c0(r13)
    addi	r4, r4, 2
    addi	r0, r3, 0x546
    stw	r4, -0x78c4(r13)
    stw	r0, -0x78c0(r13)
    b       _8002138c
_8002133c:
    lwz	r3, -0x78c4(r13)
    li	r4, 0x11
    srwi	r0, r29, 0x10
    sth	r4, 0(r3)
    lwz	r3, -0x78c4(r13)
    addi	r3, r3, 2
    stw	r3, -0x78c4(r13)
    lwz	r3, -0x78c4(r13)
    sth	r0, 0(r3)
    lwz	r3, -0x78c4(r13)
    addi	r0, r3, 2
    stw	r0, -0x78c4(r13)
    lwz	r3, -0x78c4(r13)
    sth	r29, 0(r3)
    lwz	r4, -0x78c4(r13)
    lwz	r3, -0x78c0(r13)
    addi	r4, r4, 2
    addi	r0, r3, 0x5e6
    stw	r4, -0x78c4(r13)
    stw	r0, -0x78c0(r13)
_8002138c:
    bl      fn_80022E5C
    stw	r3, 0x48(r1)
    li	r4, 2
    lwz	r3, -0x78c4(r13)
    li	r0, 3
    sth	r4, 0(r3)
    lwz	r4, -0x78c4(r13)
    lwz	r3, 0x48(r1)
    addi	r4, r4, 2
    stw	r4, -0x78c4(r13)
    srwi	r4, r3, 0x10
    lwz	r3, -0x78c4(r13)
    sth	r4, 0(r3)
    lwz	r3, -0x78c4(r13)
    lwz	r4, 0x48(r1)
    addi	r3, r3, 2
    stw	r3, -0x78c4(r13)
    lwz	r3, -0x78c4(r13)
    sth	r4, 0(r3)
    lwz	r3, -0x78c4(r13)
    addi	r3, r3, 2
    stw	r3, -0x78c4(r13)
    lwz	r3, -0x78c4(r13)
    sth	r0, 0(r3)
    lwz	r3, -0x78c4(r13)
    lwz	r0, -0x78b8(r13)
    addi	r3, r3, 2
    cmplwi	r0, 2
    stw	r3, -0x78c4(r13)
    bne     _8002163c
    addi	r3, r1, 0x48
    bl      AXGetAuxBufferA_Active
    lwz	r0, 0x48(r1)
    cmplwi	r0, 0
    beq     _8002159c
    lwz	r4, -0x78c4(r13)
    li	r0, 0x13
    addi	r3, r1, 0x48
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r4, r4, 2
    stw	r4, -0x78c4(r13)
    srwi	r0, r0, 0x10
    lwz	r4, -0x78c4(r13)
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r4, r4, 2
    stw	r4, -0x78c4(r13)
    lwz	r4, -0x78c4(r13)
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    addi	r0, r4, 2
    stw	r0, -0x78c4(r13)
    bl      AXGetAuxBufferB_500
    lwz	r0, 0x48(r1)
    addi	r3, r1, 0x48
    lwz	r4, -0x78c4(r13)
    srwi	r0, r0, 0x10
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r4, r4, 2
    stw	r4, -0x78c4(r13)
    lwz	r4, -0x78c4(r13)
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    addi	r0, r4, 2
    stw	r0, -0x78c4(r13)
    bl      AXGetAuxBufferA_Current
    lwz	r0, 0x48(r1)
    addi	r3, r1, 0x48
    lwz	r4, -0x78c4(r13)
    srwi	r0, r0, 0x10
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r4, r4, 2
    stw	r4, -0x78c4(r13)
    lwz	r4, -0x78c4(r13)
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    addi	r0, r4, 2
    stw	r0, -0x78c4(r13)
    bl      AXGetAuxBufferA_280
    lwz	r0, 0x48(r1)
    addi	r3, r1, 0x48
    lwz	r4, -0x78c4(r13)
    srwi	r0, r0, 0x10
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r4, r4, 2
    stw	r4, -0x78c4(r13)
    lwz	r4, -0x78c4(r13)
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    addi	r0, r4, 2
    stw	r0, -0x78c4(r13)
    bl      AXGetAuxBufferA_500
    lwz	r0, 0x48(r1)
    addi	r3, r1, 0x48
    lwz	r4, -0x78c4(r13)
    srwi	r0, r0, 0x10
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r4, r4, 2
    stw	r4, -0x78c4(r13)
    lwz	r4, -0x78c4(r13)
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    addi	r0, r4, 2
    stw	r0, -0x78c4(r13)
    bl      AXGetAuxBufferB_Current500
    lwz	r0, 0x48(r1)
    lwz	r3, -0x78c4(r13)
    srwi	r0, r0, 0x10
    sth	r0, 0(r3)
    lwz	r3, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r3, r3, 2
    stw	r3, -0x78c4(r13)
    lwz	r3, -0x78c4(r13)
    sth	r0, 0(r3)
    lwz	r4, -0x78c4(r13)
    lwz	r3, -0x78c0(r13)
    addi	r4, r4, 2
    addi	r0, r3, 0xded
    stw	r4, -0x78c4(r13)
    stw	r0, -0x78c0(r13)
_8002159c:
    lwz	r4, -0x78c4(r13)
    li	r0, 0x10
    addi	r3, r1, 0x48
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    addi	r0, r4, 2
    stw	r0, -0x78c4(r13)
    bl      AXGetAuxBufferB_280
    lwz	r0, 0x48(r1)
    addi	r3, r1, 0x48
    lwz	r4, -0x78c4(r13)
    srwi	r0, r0, 0x10
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r4, r4, 2
    stw	r4, -0x78c4(r13)
    lwz	r4, -0x78c4(r13)
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    addi	r0, r4, 2
    stw	r0, -0x78c4(r13)
    bl      AXGetAuxBufferB_Unknown
    lwz	r0, 0x48(r1)
    lwz	r3, -0x78c4(r13)
    srwi	r0, r0, 0x10
    sth	r0, 0(r3)
    lwz	r3, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r3, r3, 2
    stw	r3, -0x78c4(r13)
    lwz	r3, -0x78c4(r13)
    sth	r0, 0(r3)
    lwz	r4, -0x78c4(r13)
    lwz	r3, -0x78c0(r13)
    addi	r4, r4, 2
    addi	r0, r3, 0xded
    stw	r4, -0x78c4(r13)
    stw	r0, -0x78c0(r13)
    b       _8002178c
_8002163c:
    addi	r3, r1, 0x48
    bl      AXGetAuxBufferA_Active
    lwz	r0, 0x48(r1)
    cmplwi	r0, 0
    beq     _800216e4
    lwz	r4, -0x78c4(r13)
    li	r0, 4
    addi	r3, r1, 0x48
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r4, r4, 2
    stw	r4, -0x78c4(r13)
    srwi	r0, r0, 0x10
    lwz	r4, -0x78c4(r13)
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r4, r4, 2
    stw	r4, -0x78c4(r13)
    lwz	r4, -0x78c4(r13)
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    addi	r0, r4, 2
    stw	r0, -0x78c4(r13)
    bl      AXGetAuxBufferA_Current
    lwz	r0, 0x48(r1)
    lwz	r3, -0x78c4(r13)
    srwi	r0, r0, 0x10
    sth	r0, 0(r3)
    lwz	r3, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r3, r3, 2
    stw	r3, -0x78c4(r13)
    lwz	r3, -0x78c4(r13)
    sth	r0, 0(r3)
    lwz	r4, -0x78c4(r13)
    lwz	r3, -0x78c0(r13)
    addi	r4, r4, 2
    addi	r0, r3, 0xded
    stw	r4, -0x78c4(r13)
    stw	r0, -0x78c0(r13)
_800216e4:
    addi	r3, r1, 0x48
    bl      AXGetAuxBufferB_Active
    lwz	r0, 0x48(r1)
    cmplwi	r0, 0
    beq     _8002178c
    lwz	r4, -0x78c4(r13)
    li	r0, 5
    addi	r3, r1, 0x48
    sth	r0, 0(r4)
    lwz	r5, -0x78c4(r13)
    lwz	r4, -0x78c0(r13)
    addi	r5, r5, 2
    lwz	r0, 0x48(r1)
    stw	r5, -0x78c4(r13)
    addi	r4, r4, 0xded
    srwi	r0, r0, 0x10
    stw	r4, -0x78c0(r13)
    lwz	r4, -0x78c4(r13)
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r4, r4, 2
    stw	r4, -0x78c4(r13)
    lwz	r4, -0x78c4(r13)
    sth	r0, 0(r4)
    lwz	r4, -0x78c4(r13)
    addi	r0, r4, 2
    stw	r0, -0x78c4(r13)
    bl      AXGetAuxBufferB_Current
    lwz	r0, 0x48(r1)
    lwz	r3, -0x78c4(r13)
    srwi	r0, r0, 0x10
    sth	r0, 0(r3)
    lwz	r3, -0x78c4(r13)
    lwz	r0, 0x48(r1)
    addi	r3, r3, 2
    stw	r3, -0x78c4(r13)
    lwz	r3, -0x78c4(r13)
    sth	r0, 0(r3)
    lwz	r3, -0x78c4(r13)
    addi	r0, r3, 2
    stw	r0, -0x78c4(r13)
_8002178c:
    lwz	r0, -0x78bc(r13)
    cmplwi	r0, 0
    beq     _80021824
    lwz	r3, -0x78c4(r13)
    li	r0, 0x12
    lis	r5, 1
    sth	r0, 0(r3)
    lis     r3, lbl_80124800@ha
    addi	r4, r3, lbl_80124800@l
    lwz	r3, -0x78c4(r13)
    addi	r6, r5, -0x8000
    li	r5, 0xa
    addi	r0, r3, 2
    stw	r0, -0x78c4(r13)
    srwi	r0, r4, 0x10
    lwz	r3, -0x78c4(r13)
    sth	r6, 0(r3)
    lwz	r3, -0x78c4(r13)
    addi	r3, r3, 2
    stw	r3, -0x78c4(r13)
    lwz	r3, -0x78c4(r13)
    sth	r5, 0(r3)
    lwz	r3, -0x78c4(r13)
    addi	r3, r3, 2
    stw	r3, -0x78c4(r13)
    lwz	r3, -0x78c4(r13)
    sth	r0, 0(r3)
    lwz	r3, -0x78c4(r13)
    addi	r0, r3, 2
    stw	r0, -0x78c4(r13)
    lwz	r3, -0x78c4(r13)
    sth	r4, 0(r3)
    lwz	r4, -0x78c4(r13)
    lwz	r3, -0x78c0(r13)
    addi	r4, r4, 2
    addi	r0, r3, 0xbb8
    stw	r4, -0x78c4(r13)
    stw	r0, -0x78c0(r13)
_80021824:
    lwz	r3, -0x78c4(r13)
    li	r0, 0xe
    srwi	r7, r29, 0x10
    sth	r0, 0(r3)
    srwi	r6, r30, 0x10
    li	r0, 0xf
    lwz	r3, -0x78c4(r13)
    li	r4, 0x300
    addi	r3, r3, 2
    stw	r3, -0x78c4(r13)
    addi	r3, r31, 0
    lwz	r5, -0x78c4(r13)
    sth	r7, 0(r5)
    lwz	r5, -0x78c4(r13)
    addi	r5, r5, 2
    stw	r5, -0x78c4(r13)
    lwz	r5, -0x78c4(r13)
    sth	r29, 0(r5)
    lwz	r5, -0x78c4(r13)
    addi	r5, r5, 2
    stw	r5, -0x78c4(r13)
    lwz	r5, -0x78c4(r13)
    sth	r6, 0(r5)
    lwz	r5, -0x78c4(r13)
    addi	r5, r5, 2
    stw	r5, -0x78c4(r13)
    lwz	r5, -0x78c4(r13)
    sth	r30, 0(r5)
    lwz	r6, -0x78c4(r13)
    lwz	r5, -0x78c0(r13)
    addi	r6, r6, 2
    stw	r6, -0x78c4(r13)
    addi	r5, r5, 0x2710
    stw	r5, -0x78c0(r13)
    lwz	r5, -0x78c4(r13)
    sth	r0, 0(r5)
    lwz	r6, -0x78c4(r13)
    lwz	r5, -0x78c0(r13)
    addi	r6, r6, 2
    addi	r0, r5, 2
    stw	r6, -0x78c4(r13)
    stw	r0, -0x78c0(r13)
    bl      DCFlushRange
    lwz	r0, 0x64(r1)
    lwz	r31, 0x5c(r1)
    lwz	r30, 0x58(r1)
    lwz	r29, 0x54(r1)
    addi	r1, r1, 0x60
    mtlr	r0
    blr	
}

asm void fn_800218EC(void)
{
    nofralloc
    lis     r3, lbl_8015FF00@ha
    li	r4, 0
    addi	r3, r3, lbl_8015FF00@l
    stw	r4, -0x78b8(r13)
    li	r0, 1
    stw	r4, -0x78c8(r13)
    stw	r3, -0x78c4(r13)
    stw	r0, -0x78bc(r13)
    blr	
}

asm void fn_80021910(void)
{
    nofralloc
    blr	
}

asm void fn_80021914(void)
{
    nofralloc
    lwz	r0, -0x78b8(r13)
    cmplw	r0, r3
    beqlr	
    stw	r3, -0x78b8(r13)
    blr	
}

asm void fn_80021928(void)
{
    nofralloc
    lwz	r3, -0x78b8(r13)
    blr	
}

#pragma pop
