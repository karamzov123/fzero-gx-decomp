typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern void* memset(void*, int, unsigned long);
extern void fn_80039088(void);
extern unsigned char jumptable_8012AD40[104];
extern unsigned char jumptable_8012ADA8[104];
extern unsigned char jumptable_8012AE10[104];
extern unsigned char jumptable_8012AE78[68];
extern unsigned char jumptable_8012AEBC[68];
extern unsigned char jumptable_8012AF00[68];
extern unsigned char jumptable_8012AF44[28];
extern unsigned char jumptable_8012AF60[84];

void __GXXfVtxSpecs(register void* p);
void GXSetVtxDesc(register void* p, register int a, register int b);
void fn_80032818(register void* p, register int a, register int b);
void __GXSetVCD(void);
void __GXCalculateVatSizes(void);
void GXGetVtxDesc(register void* p, register int a);
void GXGetVtxDescv(register void* p);
void GXClearVtxDesc(register void* p);
void GXBuildPackedRegister(register void* p, register int a, register int b);
void fn_800332D8(register void* p, register int a, register int b);
void __GXSetVAT(void);
void fn_800336EC(register void* p, register int a, register int b);
void fn_8003396C(register void* p);
void GXSetArray(register void* p);
void fn_80033A6C(register void* p);
void GXSetTexCoordGen2(register void* p, register int a, register int b);
void GXSetNumTexGens(register void* p);

#pragma push
#pragma force_active on

asm void __GXXfVtxSpecs(register void* p)
{
    nofralloc
    lwz	r5, -0x7de8(r2)
    lwz	r4, 0x14(r5)
    rlwinm.	r0, r4, 0x13, 0x1e, 0x1f
    beq     _80032388
    li	r3, 1
    b       _8003238c
_80032388:
    li	r3, 0
_8003238c:
    rlwinm.	r0, r4, 0x11, 0x1e, 0x1f
    beq     _8003239c
    li	r4, 1
    b       _800323a0
_8003239c:
    li	r4, 0
_800323a0:
    lbz	r0, 0x41d(r5)
    add	r7, r3, r4
    cmplwi	r0, 0
    beq     _800323b8
    li	r4, 2
    b       _800323d0
_800323b8:
    lbz	r0, 0x41c(r5)
    cmplwi	r0, 0
    beq     _800323cc
    li	r4, 1
    b       _800323d0
_800323cc:
    li	r4, 0
_800323d0:
    lwz	r6, 0x18(r5)
    clrlwi.	r0, r6, 0x1e
    beq     _800323e4
    li	r3, 1
    b       _800323e8
_800323e4:
    li	r3, 0
_800323e8:
    rlwinm.	r0, r6, 0x1e, 0x1e, 0x1f
    beq     _800323f8
    li	r5, 1
    b       _800323fc
_800323f8:
    li	r5, 0
_800323fc:
    rlwinm.	r0, r6, 0x1c, 0x1e, 0x1f
    add	r8, r3, r5
    beq     _80032410
    li	r3, 1
    b       _80032414
_80032410:
    li	r3, 0
_80032414:
    rlwinm.	r0, r6, 0x1a, 0x1e, 0x1f
    add	r8, r8, r3
    beq     _80032428
    li	r3, 1
    b       _8003242c
_80032428:
    li	r3, 0
_8003242c:
    rlwinm.	r0, r6, 0x18, 0x1e, 0x1f
    add	r8, r8, r3
    beq     _80032440
    li	r3, 1
    b       _80032444
_80032440:
    li	r3, 0
_80032444:
    rlwinm.	r0, r6, 0x16, 0x1e, 0x1f
    add	r8, r8, r3
    beq     _80032458
    li	r3, 1
    b       _8003245c
_80032458:
    li	r3, 0
_8003245c:
    rlwinm.	r0, r6, 0x14, 0x1e, 0x1f
    add	r8, r8, r3
    beq     _80032470
    li	r3, 1
    b       _80032474
_80032470:
    li	r3, 0
_80032474:
    rlwinm.	r0, r6, 0x12, 0x1e, 0x1f
    add	r8, r8, r3
    beq     _80032488
    li	r6, 1
    b       _8003248c
_80032488:
    li	r6, 0
_8003248c:
    li	r0, 0x10
    lwz	r3, -0x7de8(r2)
    lis	r5, -0x33ff
    add	r8, r8, r6
    stb	r0, -0x8000(r5)
    slwi	r0, r4, 2
    li	r4, 0x1008
    stw	r4, -0x8000(r5)
    slwi	r4, r8, 4
    or	r0, r7, r0
    or	r0, r4, r0
    stw	r0, -0x8000(r5)
    li	r0, 1
    sth	r0, 2(r3)
    blr	
}

asm void GXSetVtxDesc(register void* p, register int a, register int b)
{
    nofralloc
    cmplwi	r3, 0x19
    bgt     _800327bc
    lis     r5, jumptable_8012AD40@ha
    addi	r5, r5, jumptable_8012AD40@l
    slwi	r0, r3, 2
    lwzx	r0, r5, r0
    mtctr	r0
    bctr	
    lwz	r3, -0x7de8(r2)
    lwzu	r0, 0x14(r3)
    rlwinm	r0, r0, 0, 0, 0x1e
    or	r0, r0, r4
    stw	r0, 0(r3)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 1
    addi	r4, r3, 0x14
    lwz	r3, 0x14(r3)
    rlwinm	r3, r3, 0, 0x1f, 0x1d
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 2
    addi	r4, r3, 0x14
    lwz	r3, 0x14(r3)
    rlwinm	r3, r3, 0, 0x1e, 0x1c
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 3
    addi	r4, r3, 0x14
    lwz	r3, 0x14(r3)
    rlwinm	r3, r3, 0, 0x1d, 0x1b
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 4
    addi	r4, r3, 0x14
    lwz	r3, 0x14(r3)
    rlwinm	r3, r3, 0, 0x1c, 0x1a
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 5
    addi	r4, r3, 0x14
    lwz	r3, 0x14(r3)
    rlwinm	r3, r3, 0, 0x1b, 0x19
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 6
    addi	r4, r3, 0x14
    lwz	r3, 0x14(r3)
    rlwinm	r3, r3, 0, 0x1a, 0x18
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 7
    addi	r4, r3, 0x14
    lwz	r3, 0x14(r3)
    rlwinm	r3, r3, 0, 0x19, 0x17
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 8
    addi	r4, r3, 0x14
    lwz	r3, 0x14(r3)
    rlwinm	r3, r3, 0, 0x18, 0x16
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 9
    addi	r4, r3, 0x14
    lwz	r3, 0x14(r3)
    rlwinm	r3, r3, 0, 0x17, 0x14
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    cmpwi	r4, 0
    beq     _80032644
    lwz	r3, -0x7de8(r2)
    li	r5, 1
    li	r0, 0
    stb	r5, 0x41c(r3)
    stb	r0, 0x41d(r3)
    stw	r4, 0x418(r3)
    b       _800327bc
_80032644:
    lwz	r3, -0x7de8(r2)
    li	r0, 0
    stb	r0, 0x41c(r3)
    b       _800327bc
    cmpwi	r4, 0
    beq     _80032678
    lwz	r3, -0x7de8(r2)
    li	r5, 1
    li	r0, 0
    stb	r5, 0x41d(r3)
    stb	r0, 0x41c(r3)
    stw	r4, 0x418(r3)
    b       _800327bc
_80032678:
    lwz	r3, -0x7de8(r2)
    li	r0, 0
    stb	r0, 0x41d(r3)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 0xd
    addi	r4, r3, 0x14
    lwz	r3, 0x14(r3)
    rlwinm	r3, r3, 0, 0x13, 0x10
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 0xf
    addi	r4, r3, 0x14
    lwz	r3, 0x14(r3)
    rlwinm	r3, r3, 0, 0x11, 0xe
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    lwzu	r0, 0x18(r3)
    rlwinm	r0, r0, 0, 0, 0x1d
    or	r0, r0, r4
    stw	r0, 0(r3)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 2
    addi	r4, r3, 0x18
    lwz	r3, 0x18(r3)
    rlwinm	r3, r3, 0, 0x1e, 0x1b
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 4
    addi	r4, r3, 0x18
    lwz	r3, 0x18(r3)
    rlwinm	r3, r3, 0, 0x1c, 0x19
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 6
    addi	r4, r3, 0x18
    lwz	r3, 0x18(r3)
    rlwinm	r3, r3, 0, 0x1a, 0x17
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 8
    addi	r4, r3, 0x18
    lwz	r3, 0x18(r3)
    rlwinm	r3, r3, 0, 0x18, 0x15
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 0xa
    addi	r4, r3, 0x18
    lwz	r3, 0x18(r3)
    rlwinm	r3, r3, 0, 0x16, 0x13
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 0xc
    addi	r4, r3, 0x18
    lwz	r3, 0x18(r3)
    rlwinm	r3, r3, 0, 0x14, 0x11
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _800327bc
    lwz	r3, -0x7de8(r2)
    slwi	r0, r4, 0xe
    addi	r4, r3, 0x18
    lwz	r3, 0x18(r3)
    rlwinm	r3, r3, 0, 0x12, 0xf
    or	r0, r3, r0
    stw	r0, 0(r4)
_800327bc:
    lwz	r3, -0x7de8(r2)
    lbz	r0, 0x41c(r3)
    cmplwi	r0, 0
    bne     _800327d8
    lbz	r0, 0x41d(r3)
    cmplwi	r0, 0
    beq     _800327f8
_800327d8:
    addi	r4, r3, 0x14
    lwz	r0, 0x418(r3)
    lwz	r3, 0x14(r3)
    slwi	r0, r0, 0xb
    rlwinm	r3, r3, 0, 0x15, 0x12
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _80032804
_800327f8:
    lwzu	r0, 0x14(r3)
    rlwinm	r0, r0, 0, 0x15, 0x12
    stw	r0, 0(r3)
_80032804:
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x4f4(r3)
    ori	r0, r0, 8
    stw	r0, 0x4f4(r3)
    blr	
}

asm void fn_80032818(register void* p, register int a, register int b)
{
    nofralloc
    lis     r4, jumptable_8012ADA8@ha
    addi	r4, r4, jumptable_8012ADA8@l
    b       _80032b24
_80032824:
    lwz	r5, 0(r3)
    lwz	r0, 4(r3)
    cmplwi	r5, 0x19
    bgt     _80032b20
    slwi	r5, r5, 2
    lwzx	r5, r4, r5
    mtctr	r5
    bctr	
    lwz	r5, -0x7de8(r2)
    addi	r6, r5, 0x14
    lwz	r5, 0x14(r5)
    rlwinm	r5, r5, 0, 0, 0x1e
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 1
    addi	r6, r5, 0x14
    lwz	r5, 0x14(r5)
    rlwinm	r5, r5, 0, 0x1f, 0x1d
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 2
    addi	r6, r5, 0x14
    lwz	r5, 0x14(r5)
    rlwinm	r5, r5, 0, 0x1e, 0x1c
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 3
    addi	r6, r5, 0x14
    lwz	r5, 0x14(r5)
    rlwinm	r5, r5, 0, 0x1d, 0x1b
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 4
    addi	r6, r5, 0x14
    lwz	r5, 0x14(r5)
    rlwinm	r5, r5, 0, 0x1c, 0x1a
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 5
    addi	r6, r5, 0x14
    lwz	r5, 0x14(r5)
    rlwinm	r5, r5, 0, 0x1b, 0x19
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 6
    addi	r6, r5, 0x14
    lwz	r5, 0x14(r5)
    rlwinm	r5, r5, 0, 0x1a, 0x18
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 7
    addi	r6, r5, 0x14
    lwz	r5, 0x14(r5)
    rlwinm	r5, r5, 0, 0x19, 0x17
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 8
    addi	r6, r5, 0x14
    lwz	r5, 0x14(r5)
    rlwinm	r5, r5, 0, 0x18, 0x16
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 9
    addi	r6, r5, 0x14
    lwz	r5, 0x14(r5)
    rlwinm	r5, r5, 0, 0x17, 0x14
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    cmpwi	r0, 0
    beq     _800329a4
    lwz	r6, -0x7de8(r2)
    li	r7, 1
    li	r5, 0
    stb	r7, 0x41c(r6)
    stb	r5, 0x41d(r6)
    stw	r0, 0x418(r6)
    b       _80032b20
_800329a4:
    lwz	r5, -0x7de8(r2)
    li	r0, 0
    stb	r0, 0x41c(r5)
    b       _80032b20
    cmpwi	r0, 0
    beq     _800329d8
    lwz	r6, -0x7de8(r2)
    li	r7, 1
    li	r5, 0
    stb	r7, 0x41d(r6)
    stb	r5, 0x41c(r6)
    stw	r0, 0x418(r6)
    b       _80032b20
_800329d8:
    lwz	r5, -0x7de8(r2)
    li	r0, 0
    stb	r0, 0x41d(r5)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 0xd
    addi	r6, r5, 0x14
    lwz	r5, 0x14(r5)
    rlwinm	r5, r5, 0, 0x13, 0x10
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 0xf
    addi	r6, r5, 0x14
    lwz	r5, 0x14(r5)
    rlwinm	r5, r5, 0, 0x11, 0xe
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    addi	r6, r5, 0x18
    lwz	r5, 0x18(r5)
    rlwinm	r5, r5, 0, 0, 0x1d
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 2
    addi	r6, r5, 0x18
    lwz	r5, 0x18(r5)
    rlwinm	r5, r5, 0, 0x1e, 0x1b
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 4
    addi	r6, r5, 0x18
    lwz	r5, 0x18(r5)
    rlwinm	r5, r5, 0, 0x1c, 0x19
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 6
    addi	r6, r5, 0x18
    lwz	r5, 0x18(r5)
    rlwinm	r5, r5, 0, 0x1a, 0x17
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 8
    addi	r6, r5, 0x18
    lwz	r5, 0x18(r5)
    rlwinm	r5, r5, 0, 0x18, 0x15
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 0xa
    addi	r6, r5, 0x18
    lwz	r5, 0x18(r5)
    rlwinm	r5, r5, 0, 0x16, 0x13
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 0xc
    addi	r6, r5, 0x18
    lwz	r5, 0x18(r5)
    rlwinm	r5, r5, 0, 0x14, 0x11
    or	r0, r5, r0
    stw	r0, 0(r6)
    b       _80032b20
    lwz	r5, -0x7de8(r2)
    slwi	r0, r0, 0xe
    addi	r6, r5, 0x18
    lwz	r5, 0x18(r5)
    rlwinm	r5, r5, 0, 0x12, 0xf
    or	r0, r5, r0
    stw	r0, 0(r6)
_80032b20:
    addi	r3, r3, 8
_80032b24:
    lwz	r0, 0(r3)
    cmpwi	r0, 0xff
    bne     _80032824
    lwz	r3, -0x7de8(r2)
    lbz	r0, 0x41c(r3)
    cmplwi	r0, 0
    bne     _80032b4c
    lbz	r0, 0x41d(r3)
    cmplwi	r0, 0
    beq     _80032b6c
_80032b4c:
    addi	r4, r3, 0x14
    lwz	r0, 0x418(r3)
    lwz	r3, 0x14(r3)
    slwi	r0, r0, 0xb
    rlwinm	r3, r3, 0, 0x15, 0x12
    or	r0, r3, r0
    stw	r0, 0(r4)
    b       _80032b78
_80032b6c:
    lwzu	r0, 0x14(r3)
    rlwinm	r0, r0, 0, 0x15, 0x12
    stw	r0, 0(r3)
_80032b78:
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x4f4(r3)
    ori	r0, r0, 8
    stw	r0, 0x4f4(r3)
    blr	
}

asm void __GXSetVCD(void)
{
    nofralloc
    mflr	r0
    li	r6, 8
    stw	r0, 4(r1)
    lis	r5, -0x33ff
    li	r3, 0x50
    stwu	r1, -8(r1)
    li	r0, 0x60
    stb	r6, -0x8000(r5)
    lwz	r4, -0x7de8(r2)
    stb	r3, -0x8000(r5)
    lwz	r3, 0x14(r4)
    stw	r3, -0x8000(r5)
    stb	r6, -0x8000(r5)
    stb	r0, -0x8000(r5)
    lwz	r0, 0x18(r4)
    stw	r0, -0x8000(r5)
    bl      __GXXfVtxSpecs
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void __GXCalculateVatSizes(void)
{
    nofralloc
    lwz	r3, -0x7de8(r2)
    lhz	r0, 4(r3)
    cmplwi	r0, 0
    beqlr	
    lwz	r9, 0x14(r3)
    addi	r5, r13, -0x7e90
    lwz	r8, 0x1c(r3)
    clrlwi	r0, r9, 0x1f
    lwz	r4, 0x18(r3)
    rlwinm	r6, r9, 0x1f, 0x1f, 0x1f
    add	r0, r0, r6
    rlwinm	r6, r9, 0x1e, 0x1f, 0x1f
    add	r0, r0, r6
    rlwinm	r7, r9, 0x1d, 0x1f, 0x1f
    rlwinm	r6, r9, 0x17, 0x1e, 0x1f
    lbzx	r5, r5, r6
    rlwinm	r8, r8, 0x17, 0x1f, 0x1f
    add	r0, r0, r7
    rlwinm	r6, r9, 0x1c, 0x1f, 0x1f
    add	r0, r0, r6
    rlwinm	r6, r9, 0x1b, 0x1f, 0x1f
    add	r0, r0, r6
    rlwinm	r6, r9, 0x1a, 0x1f, 0x1f
    add	r0, r0, r6
    rlwinm	r6, r9, 0x19, 0x1f, 0x1f
    add	r0, r0, r6
    rlwinm	r6, r9, 0x18, 0x1f, 0x1f
    add	r0, r0, r6
    cmpwi	r8, 1
    add	r0, r0, r5
    bne     _80032c64
    li	r8, 3
    b       _80032c68
_80032c64:
    li	r8, 1
_80032c68:
    rlwinm	r6, r9, 0x15, 0x1e, 0x1f
    addi	r5, r13, -0x7e90
    lbzx	r6, r5, r6
    rlwinm	r5, r9, 0x13, 0x1e, 0x1f
    addi	r7, r13, -0x7e98
    mullw	r8, r6, r8
    lbzx	r6, r7, r5
    add	r0, r0, r8
    rlwinm	r5, r9, 0x11, 0x1e, 0x1f
    lbzx	r9, r7, r5
    add	r0, r0, r6
    clrlwi	r6, r4, 0x1e
    addi	r8, r13, -0x7e94
    rlwinm	r5, r4, 0x1e, 0x1e, 0x1f
    lbzx	r7, r8, r6
    add	r0, r0, r9
    lbzx	r6, r8, r5
    add	r0, r0, r7
    rlwinm	r5, r4, 0x1c, 0x1e, 0x1f
    lbzx	r7, r8, r5
    add	r0, r0, r6
    rlwinm	r5, r4, 0x1a, 0x1e, 0x1f
    lbzx	r6, r8, r5
    add	r0, r0, r7
    rlwinm	r5, r4, 0x18, 0x1e, 0x1f
    lbzx	r7, r8, r5
    add	r0, r0, r6
    rlwinm	r5, r4, 0x16, 0x1e, 0x1f
    lbzx	r6, r8, r5
    rlwinm	r5, r4, 0x14, 0x1e, 0x1f
    add	r0, r0, r7
    lbzx	r5, r8, r5
    rlwinm	r4, r4, 0x12, 0x1e, 0x1f
    add	r0, r0, r6
    lbzx	r4, r8, r4
    add	r0, r0, r5
    add	r0, r0, r4
    sth	r0, 6(r3)
    blr	
}

asm void GXGetVtxDesc(register void* p, register int a)
{
    nofralloc
    cmplwi	r3, 0x19
    bgt     _80032eac
    lis     r5, jumptable_8012AE10@ha
    addi	r5, r5, jumptable_8012AE10@l
    slwi	r0, r3, 2
    lwzx	r0, r5, r0
    mtctr	r0
    bctr	
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x14(r3)
    clrlwi	r0, r0, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x14(r3)
    rlwinm	r0, r0, 0x1f, 0x1f, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x14(r3)
    rlwinm	r0, r0, 0x1e, 0x1f, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x14(r3)
    rlwinm	r0, r0, 0x1d, 0x1f, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x14(r3)
    rlwinm	r0, r0, 0x1c, 0x1f, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x14(r3)
    rlwinm	r0, r0, 0x1b, 0x1f, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x14(r3)
    rlwinm	r0, r0, 0x1a, 0x1f, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x14(r3)
    rlwinm	r0, r0, 0x19, 0x1f, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x14(r3)
    rlwinm	r0, r0, 0x18, 0x1f, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x14(r3)
    rlwinm	r0, r0, 0x17, 0x1e, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lbz	r0, 0x41c(r3)
    cmplwi	r0, 0
    beq     _80032de0
    lwz	r0, 0x14(r3)
    rlwinm	r0, r0, 0x15, 0x1e, 0x1f
    b       _80032eb0
_80032de0:
    li	r0, 0
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lbz	r0, 0x41d(r3)
    cmplwi	r0, 0
    beq     _80032e04
    lwz	r0, 0x14(r3)
    rlwinm	r0, r0, 0x15, 0x1e, 0x1f
    b       _80032eb0
_80032e04:
    li	r0, 0
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x14(r3)
    rlwinm	r0, r0, 0x13, 0x1e, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x14(r3)
    rlwinm	r0, r0, 0x11, 0x1e, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x18(r3)
    clrlwi	r0, r0, 0x1e
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x18(r3)
    rlwinm	r0, r0, 0x1e, 0x1e, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x18(r3)
    rlwinm	r0, r0, 0x1c, 0x1e, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x18(r3)
    rlwinm	r0, r0, 0x1a, 0x1e, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x18(r3)
    rlwinm	r0, r0, 0x18, 0x1e, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x18(r3)
    rlwinm	r0, r0, 0x16, 0x1e, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x18(r3)
    rlwinm	r0, r0, 0x14, 0x1e, 0x1f
    b       _80032eb0
    lwz	r3, -0x7de8(r2)
    lwz	r0, 0x18(r3)
    rlwinm	r0, r0, 0x12, 0x1e, 0x1f
    b       _80032eb0
_80032eac:
    li	r0, 0
_80032eb0:
    stw	r0, 0(r4)
    blr	
}

asm void GXGetVtxDescv(register void* p)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    li	r31, 0
    stw	r30, 0x18(r1)
    li	r30, 0
    stw	r29, 0x14(r1)
    addi	r29, r3, 0
_80032edc:
    add	r4, r29, r31
    stw	r30, 0(r4)
    addi	r3, r30, 0
    addi	r4, r4, 4
    bl      GXGetVtxDesc
    addi	r30, r30, 1
    cmpwi	r30, 0x14
    addi	r31, r31, 8
    ble     _80032edc
    slwi	r0, r30, 3
    add	r3, r29, r0
    li	r0, 0x19
    stw	r0, 0(r3)
    addi	r4, r3, 4
    li	r3, 0x19
    bl      GXGetVtxDesc
    addi	r30, r30, 1
    slwi	r0, r30, 3
    li	r3, 0xff
    stwx	r3, r29, r0
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void GXClearVtxDesc(register void* p)
{
    nofralloc
    lwz	r3, -0x7de8(r2)
    li	r4, 0
    stw	r4, 0x14(r3)
    lwz	r0, 0x14(r3)
    rlwinm	r0, r0, 0, 0x17, 0x14
    ori	r0, r0, 0x200
    stw	r0, 0x14(r3)
    stw	r4, 0x18(r3)
    stb	r4, 0x41c(r3)
    stb	r4, 0x41d(r3)
    lwz	r0, 0x4f4(r3)
    ori	r0, r0, 8
    stw	r0, 0x4f4(r3)
    blr	
}

asm void GXBuildPackedRegister(register void* p, register int a, register int b)
{
    nofralloc
    addi	r0, r4, -9
    lwz	r8, -0x7de8(r2)
    slwi	r4, r3, 2
    add	r9, r8, r4
    cmplwi	r0, 0x10
    addi	r4, r9, 0x1c
    addi	r8, r9, 0x3c
    addi	r9, r9, 0x5c
    bgt     _800332a8
    lis     r10, jumptable_8012AE78@ha
    addi	r10, r10, jumptable_8012AE78@l
    slwi	r0, r0, 2
    lwzx	r0, r10, r0
    mtctr	r0
    bctr	
    lwz	r0, 0(r4)
    slwi	r6, r6, 1
    rlwinm	r0, r0, 0, 0, 0x1e
    or	r0, r0, r5
    stw	r0, 0(r4)
    rlwinm	r0, r7, 4, 0x14, 0x1b
    lwz	r5, 0(r4)
    rlwinm	r5, r5, 0, 0x1f, 0x1b
    or	r5, r5, r6
    stw	r5, 0(r4)
    lwz	r5, 0(r4)
    rlwinm	r5, r5, 0, 0x1c, 0x16
    or	r0, r5, r0
    stw	r0, 0(r4)
    b       _800332a8
    lwz	r7, 0(r4)
    slwi	r0, r6, 0xa
    cmpwi	r5, 2
    rlwinm	r6, r7, 0, 0x16, 0x12
    or	r0, r6, r0
    stw	r0, 0(r4)
    bne     _80033038
    lwz	r0, 0(r4)
    rlwinm	r0, r0, 0, 0x17, 0x15
    ori	r0, r0, 0x200
    stw	r0, 0(r4)
    lwz	r0, 0(r4)
    clrlwi	r0, r0, 1
    oris	r0, r0, 0x8000
    stw	r0, 0(r4)
    b       _800332a8
_80033038:
    lwz	r6, 0(r4)
    slwi	r0, r5, 9
    rlwinm	r5, r6, 0, 0x17, 0x15
    or	r0, r5, r0
    stw	r0, 0(r4)
    lwz	r0, 0(r4)
    clrlwi	r0, r0, 1
    stw	r0, 0(r4)
    b       _800332a8
    lwz	r7, 0(r4)
    slwi	r5, r5, 0xd
    slwi	r0, r6, 0xe
    rlwinm	r6, r7, 0, 0x13, 0x11
    or	r5, r6, r5
    stw	r5, 0(r4)
    lwz	r5, 0(r4)
    rlwinm	r5, r5, 0, 0x12, 0xe
    or	r0, r5, r0
    stw	r0, 0(r4)
    b       _800332a8
    lwz	r7, 0(r4)
    slwi	r5, r5, 0x11
    slwi	r0, r6, 0x12
    rlwinm	r6, r7, 0, 0xf, 0xd
    or	r5, r6, r5
    stw	r5, 0(r4)
    lwz	r5, 0(r4)
    rlwinm	r5, r5, 0, 0xe, 0xa
    or	r0, r5, r0
    stw	r0, 0(r4)
    b       _800332a8
    lwz	r8, 0(r4)
    slwi	r0, r5, 0x15
    rlwinm	r5, r8, 0, 0xb, 9
    or	r0, r5, r0
    stw	r0, 0(r4)
    slwi	r5, r6, 0x16
    slwi	r0, r7, 0x19
    lwz	r6, 0(r4)
    rlwinm	r6, r6, 0, 0xa, 6
    or	r5, r6, r5
    stw	r5, 0(r4)
    lwz	r5, 0(r4)
    rlwinm	r5, r5, 0, 7, 1
    or	r0, r5, r0
    stw	r0, 0(r4)
    b       _800332a8
    lwz	r0, 0(r8)
    slwi	r4, r6, 1
    rlwinm	r0, r0, 0, 0, 0x1e
    or	r0, r0, r5
    stw	r0, 0(r8)
    rlwinm	r0, r7, 4, 0x14, 0x1b
    lwz	r5, 0(r8)
    rlwinm	r5, r5, 0, 0x1f, 0x1b
    or	r4, r5, r4
    stw	r4, 0(r8)
    lwz	r4, 0(r8)
    rlwinm	r4, r4, 0, 0x1c, 0x16
    or	r0, r4, r0
    stw	r0, 0(r8)
    b       _800332a8
    lwz	r4, 0(r8)
    slwi	r0, r5, 9
    rlwinm	r4, r4, 0, 0x17, 0x15
    or	r0, r4, r0
    stw	r0, 0(r8)
    slwi	r4, r6, 0xa
    rlwinm	r0, r7, 0xd, 0xb, 0x12
    lwz	r5, 0(r8)
    rlwinm	r5, r5, 0, 0x16, 0x12
    or	r4, r5, r4
    stw	r4, 0(r8)
    lwz	r4, 0(r8)
    rlwinm	r4, r4, 0, 0x13, 0xd
    or	r0, r4, r0
    stw	r0, 0(r8)
    b       _800332a8
    lwz	r4, 0(r8)
    slwi	r0, r5, 0x12
    rlwinm	r4, r4, 0, 0xe, 0xc
    or	r0, r4, r0
    stw	r0, 0(r8)
    slwi	r4, r6, 0x13
    rlwinm	r0, r7, 0x16, 2, 9
    lwz	r5, 0(r8)
    rlwinm	r5, r5, 0, 0xd, 9
    or	r4, r5, r4
    stw	r4, 0(r8)
    lwz	r4, 0(r8)
    rlwinm	r4, r4, 0, 0xa, 4
    or	r0, r4, r0
    stw	r0, 0(r8)
    b       _800332a8
    lwz	r10, 0(r8)
    slwi	r0, r5, 0x1b
    slwi	r4, r6, 0x1c
    rlwinm	r5, r10, 0, 5, 3
    or	r0, r5, r0
    stw	r0, 0(r8)
    clrlwi	r0, r7, 0x18
    lwz	r5, 0(r8)
    rlwinm	r5, r5, 0, 4, 0
    or	r4, r5, r4
    stw	r4, 0(r8)
    lwz	r4, 0(r9)
    rlwinm	r4, r4, 0, 0, 0x1a
    or	r0, r4, r0
    stw	r0, 0(r9)
    b       _800332a8
    lwz	r4, 0(r9)
    slwi	r0, r5, 5
    rlwinm	r4, r4, 0, 0x1b, 0x19
    or	r0, r4, r0
    stw	r0, 0(r9)
    slwi	r4, r6, 6
    rlwinm	r0, r7, 9, 0xf, 0x16
    lwz	r5, 0(r9)
    rlwinm	r5, r5, 0, 0x1a, 0x16
    or	r4, r5, r4
    stw	r4, 0(r9)
    lwz	r4, 0(r9)
    rlwinm	r4, r4, 0, 0x17, 0x11
    or	r0, r4, r0
    stw	r0, 0(r9)
    b       _800332a8
    lwz	r4, 0(r9)
    slwi	r0, r5, 0xe
    rlwinm	r4, r4, 0, 0x12, 0x10
    or	r0, r4, r0
    stw	r0, 0(r9)
    slwi	r4, r6, 0xf
    rlwinm	r0, r7, 0x12, 6, 0xd
    lwz	r5, 0(r9)
    rlwinm	r5, r5, 0, 0x11, 0xd
    or	r4, r5, r4
    stw	r4, 0(r9)
    lwz	r4, 0(r9)
    rlwinm	r4, r4, 0, 0xe, 8
    or	r0, r4, r0
    stw	r0, 0(r9)
    b       _800332a8
    lwz	r4, 0(r9)
    slwi	r0, r5, 0x17
    rlwinm	r4, r4, 0, 9, 7
    or	r0, r4, r0
    stw	r0, 0(r9)
    slwi	r0, r6, 0x18
    lwz	r4, 0(r9)
    rlwinm	r4, r4, 0, 8, 4
    or	r0, r4, r0
    stw	r0, 0(r9)
    lwz	r0, 0(r9)
    clrlwi	r0, r0, 5
    rlwimi	r0, r7, 0x1b, 0, 4
    stw	r0, 0(r9)
_800332a8:
    lwz	r5, -0x7de8(r2)
    clrlwi	r0, r3, 0x18
    li	r3, 1
    lwz	r4, 0x4f4(r5)
    slw	r0, r3, r0
    clrlwi	r0, r0, 0x18
    ori	r3, r4, 0x10
    stw	r3, 0x4f4(r5)
    lbz	r3, 0x4f3(r5)
    or	r0, r3, r0
    stb	r0, 0x4f3(r5)
    blr	
}

asm void fn_800332D8(register void* p, register int a, register int b)
{
    nofralloc
    lwz	r6, -0x7de8(r2)
    slwi	r0, r3, 2
    lis     r5, -0x7fed
    add	r6, r6, r0
    addi	r8, r6, 0x1c
    addi	r9, r6, 0x3c
    addi	r10, r6, 0x5c
    addi	r5, r5, -0x5144
    b       _80033614
_800332fc:
    lwz	r6, 0(r4)
    lbz	r7, 0xc(r4)
    addi	r11, r6, -9
    lwz	r6, 8(r4)
    cmplwi	r11, 0x10
    lwz	r0, 4(r4)
    bgt     _80033610
    slwi	r11, r11, 2
    lwzx	r11, r5, r11
    mtctr	r11
    bctr	
    lwz	r12, 0(r8)
    slwi	r11, r6, 1
    slwi	r6, r7, 4
    rlwinm	r7, r12, 0, 0, 0x1e
    or	r0, r7, r0
    stw	r0, 0(r8)
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 0, 0x1f, 0x1b
    or	r0, r0, r11
    stw	r0, 0(r8)
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 0, 0x1c, 0x16
    or	r0, r0, r6
    stw	r0, 0(r8)
    b       _80033610
    lwz	r7, 0(r8)
    slwi	r6, r6, 0xa
    cmpwi	r0, 2
    rlwinm	r7, r7, 0, 0x16, 0x12
    or	r6, r7, r6
    stw	r6, 0(r8)
    bne     _800333a4
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 0, 0x17, 0x15
    ori	r0, r0, 0x200
    stw	r0, 0(r8)
    lwz	r0, 0(r8)
    clrlwi	r0, r0, 1
    oris	r0, r0, 0x8000
    stw	r0, 0(r8)
    b       _80033610
_800333a4:
    lwz	r6, 0(r8)
    slwi	r0, r0, 9
    rlwinm	r6, r6, 0, 0x17, 0x15
    or	r0, r6, r0
    stw	r0, 0(r8)
    lwz	r0, 0(r8)
    clrlwi	r0, r0, 1
    stw	r0, 0(r8)
    b       _80033610
    lwz	r11, 0(r8)
    slwi	r7, r0, 0xd
    slwi	r0, r6, 0xe
    rlwinm	r6, r11, 0, 0x13, 0x11
    or	r6, r6, r7
    stw	r6, 0(r8)
    lwz	r6, 0(r8)
    rlwinm	r6, r6, 0, 0x12, 0xe
    or	r0, r6, r0
    stw	r0, 0(r8)
    b       _80033610
    lwz	r11, 0(r8)
    slwi	r7, r0, 0x11
    slwi	r0, r6, 0x12
    rlwinm	r6, r11, 0, 0xf, 0xd
    or	r6, r6, r7
    stw	r6, 0(r8)
    lwz	r6, 0(r8)
    rlwinm	r6, r6, 0, 0xe, 0xa
    or	r0, r6, r0
    stw	r0, 0(r8)
    b       _80033610
    lwz	r11, 0(r8)
    slwi	r0, r0, 0x15
    slwi	r6, r6, 0x16
    rlwinm	r11, r11, 0, 0xb, 9
    or	r0, r11, r0
    stw	r0, 0(r8)
    slwi	r0, r7, 0x19
    lwz	r7, 0(r8)
    rlwinm	r7, r7, 0, 0xa, 6
    or	r6, r7, r6
    stw	r6, 0(r8)
    lwz	r6, 0(r8)
    rlwinm	r6, r6, 0, 7, 1
    or	r0, r6, r0
    stw	r0, 0(r8)
    b       _80033610
    lwz	r12, 0(r9)
    slwi	r11, r6, 1
    slwi	r6, r7, 4
    rlwinm	r7, r12, 0, 0, 0x1e
    or	r0, r7, r0
    stw	r0, 0(r9)
    lwz	r0, 0(r9)
    rlwinm	r0, r0, 0, 0x1f, 0x1b
    or	r0, r0, r11
    stw	r0, 0(r9)
    lwz	r0, 0(r9)
    rlwinm	r0, r0, 0, 0x1c, 0x16
    or	r0, r0, r6
    stw	r0, 0(r9)
    b       _80033610
    lwz	r11, 0(r9)
    slwi	r0, r0, 9
    slwi	r6, r6, 0xa
    rlwinm	r11, r11, 0, 0x17, 0x15
    or	r0, r11, r0
    stw	r0, 0(r9)
    slwi	r0, r7, 0xd
    lwz	r7, 0(r9)
    rlwinm	r7, r7, 0, 0x16, 0x12
    or	r6, r7, r6
    stw	r6, 0(r9)
    lwz	r6, 0(r9)
    rlwinm	r6, r6, 0, 0x13, 0xd
    or	r0, r6, r0
    stw	r0, 0(r9)
    b       _80033610
    lwz	r11, 0(r9)
    slwi	r0, r0, 0x12
    slwi	r6, r6, 0x13
    rlwinm	r11, r11, 0, 0xe, 0xc
    or	r0, r11, r0
    stw	r0, 0(r9)
    slwi	r0, r7, 0x16
    lwz	r7, 0(r9)
    rlwinm	r7, r7, 0, 0xd, 9
    or	r6, r7, r6
    stw	r6, 0(r9)
    lwz	r6, 0(r9)
    rlwinm	r6, r6, 0, 0xa, 4
    or	r0, r6, r0
    stw	r0, 0(r9)
    b       _80033610
    lwz	r12, 0(r9)
    slwi	r11, r0, 0x1b
    slwi	r0, r6, 0x1c
    rlwinm	r6, r12, 0, 5, 3
    or	r6, r6, r11
    stw	r6, 0(r9)
    lwz	r6, 0(r9)
    rlwinm	r6, r6, 0, 4, 0
    or	r0, r6, r0
    stw	r0, 0(r9)
    lwz	r0, 0(r10)
    rlwinm	r0, r0, 0, 0, 0x1a
    or	r0, r0, r7
    stw	r0, 0(r10)
    b       _80033610
    lwz	r11, 0(r10)
    slwi	r0, r0, 5
    slwi	r6, r6, 6
    rlwinm	r11, r11, 0, 0x1b, 0x19
    or	r0, r11, r0
    stw	r0, 0(r10)
    slwi	r0, r7, 9
    lwz	r7, 0(r10)
    rlwinm	r7, r7, 0, 0x1a, 0x16
    or	r6, r7, r6
    stw	r6, 0(r10)
    lwz	r6, 0(r10)
    rlwinm	r6, r6, 0, 0x17, 0x11
    or	r0, r6, r0
    stw	r0, 0(r10)
    b       _80033610
    lwz	r11, 0(r10)
    slwi	r0, r0, 0xe
    slwi	r6, r6, 0xf
    rlwinm	r11, r11, 0, 0x12, 0x10
    or	r0, r11, r0
    stw	r0, 0(r10)
    slwi	r0, r7, 0x12
    lwz	r7, 0(r10)
    rlwinm	r7, r7, 0, 0x11, 0xd
    or	r6, r7, r6
    stw	r6, 0(r10)
    lwz	r6, 0(r10)
    rlwinm	r6, r6, 0, 0xe, 8
    or	r0, r6, r0
    stw	r0, 0(r10)
    b       _80033610
    lwz	r12, 0(r10)
    slwi	r11, r0, 0x17
    slwi	r0, r6, 0x18
    rlwinm	r6, r12, 0, 9, 7
    or	r6, r6, r11
    stw	r6, 0(r10)
    lwz	r6, 0(r10)
    rlwinm	r6, r6, 0, 8, 4
    or	r0, r6, r0
    stw	r0, 0(r10)
    lwz	r0, 0(r10)
    clrlwi	r0, r0, 5
    rlwimi	r0, r7, 0x1b, 0, 4
    stw	r0, 0(r10)
_80033610:
    addi	r4, r4, 0x10
_80033614:
    lwz	r0, 0(r4)
    cmpwi	r0, 0xff
    bne     _800332fc
    lwz	r5, -0x7de8(r2)
    clrlwi	r0, r3, 0x18
    li	r3, 1
    lwz	r4, 0x4f4(r5)
    slw	r0, r3, r0
    clrlwi	r0, r0, 0x18
    ori	r3, r4, 0x10
    stw	r3, 0x4f4(r5)
    lbz	r3, 0x4f3(r5)
    or	r0, r3, r0
    stb	r0, 0x4f3(r5)
    blr	
}

asm void __GXSetVAT(void)
{
    nofralloc
    lwz	r10, -0x7de8(r2)
    li	r12, 0
    li	r11, 0
    lis	r7, -0x33ff
    b       _800336d0
_80033664:
    clrlwi	r9, r12, 0x18
    lbz	r3, 0x4f3(r10)
    li	r0, 1
    slw	r0, r0, r9
    and.	r0, r3, r0
    beq     _800336c8
    li	r8, 8
    stb	r8, -0x8000(r7)
    ori	r3, r9, 0x70
    addi	r0, r11, 0x1c
    stb	r3, -0x8000(r7)
    ori	r5, r9, 0x80
    addi	r4, r11, 0x3c
    lwzx	r6, r10, r0
    ori	r3, r9, 0x90
    addi	r0, r11, 0x5c
    stw	r6, -0x8000(r7)
    stb	r8, -0x8000(r7)
    stb	r5, -0x8000(r7)
    lwzx	r4, r10, r4
    stw	r4, -0x8000(r7)
    stb	r8, -0x8000(r7)
    stb	r3, -0x8000(r7)
    lwzx	r0, r10, r0
    stw	r0, -0x8000(r7)
_800336c8:
    addi	r11, r11, 4
    addi	r12, r12, 1
_800336d0:
    clrlwi	r0, r12, 0x18
    cmplwi	r0, 8
    blt     _80033664
    lwz	r3, -0x7de8(r2)
    li	r0, 0
    stb	r0, 0x4f3(r3)
    blr	
}

asm void fn_800336EC(register void* p, register int a, register int b)
{
    nofralloc
    addi	r0, r4, -9
    lwz	r4, -0x7de8(r2)
    slwi	r3, r3, 2
    add	r4, r4, r3
    cmplwi	r0, 0x10
    addi	r3, r4, 0x1c
    addi	r8, r4, 0x3c
    addi	r9, r4, 0x5c
    bgt     _80033954
    lis     r4, jumptable_8012AF00@ha
    addi	r4, r4, jumptable_8012AF00@l
    slwi	r0, r0, 2
    lwzx	r0, r4, r0
    mtctr	r0
    bctr	
    lwz	r0, 0(r3)
    clrlwi	r0, r0, 0x1f
    stw	r0, 0(r5)
    lwz	r0, 0(r3)
    rlwinm	r0, r0, 0x1f, 0x1d, 0x1f
    stw	r0, 0(r6)
    lwz	r0, 0(r3)
    rlwinm	r0, r0, 0x1c, 0x1b, 0x1f
    stb	r0, 0(r7)
    blr	
    lwz	r0, 0(r3)
    rlwinm	r0, r0, 0x17, 0x1f, 0x1f
    stw	r0, 0(r5)
    lwz	r0, 0(r5)
    cmpwi	r0, 1
    bne     _8003377c
    lwz	r0, 0(r3)
    rlwinm.	r0, r0, 1, 0x1f, 0x1f
    beq     _8003377c
    li	r0, 2
    stw	r0, 0(r5)
_8003377c:
    lwz	r0, 0(r3)
    rlwinm	r0, r0, 0x16, 0x1d, 0x1f
    stw	r0, 0(r6)
    lwz	r0, 0(r6)
    cmpwi	r0, 2
    beq     _800337c0
    bge     _800337a4
    cmpwi	r0, 1
    bge     _800337b0
    b       _800337c0
_800337a4:
    cmpwi	r0, 4
    bge     _800337c0
    b       _800337b8
_800337b0:
    li	r0, 6
    b       _800337c4
_800337b8:
    li	r0, 0xe
    b       _800337c4
_800337c0:
    li	r0, 0
_800337c4:
    stb	r0, 0(r7)
    blr	
    lwz	r4, 0(r3)
    li	r0, 0
    rlwinm	r4, r4, 0x13, 0x1f, 0x1f
    stw	r4, 0(r5)
    lwz	r3, 0(r3)
    rlwinm	r3, r3, 0x12, 0x1d, 0x1f
    stw	r3, 0(r6)
    stb	r0, 0(r7)
    blr	
    lwz	r4, 0(r3)
    li	r0, 0
    rlwinm	r4, r4, 0xf, 0x1f, 0x1f
    stw	r4, 0(r5)
    lwz	r3, 0(r3)
    rlwinm	r3, r3, 0xe, 0x1d, 0x1f
    stw	r3, 0(r6)
    stb	r0, 0(r7)
    blr	
    lwz	r0, 0(r3)
    rlwinm	r0, r0, 0xb, 0x1f, 0x1f
    stw	r0, 0(r5)
    lwz	r0, 0(r3)
    rlwinm	r0, r0, 0xa, 0x1d, 0x1f
    stw	r0, 0(r6)
    lwz	r0, 0(r3)
    rlwinm	r0, r0, 7, 0x1b, 0x1f
    stb	r0, 0(r7)
    blr	
    lwz	r0, 0(r8)
    clrlwi	r0, r0, 0x1f
    stw	r0, 0(r5)
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 0x1f, 0x1d, 0x1f
    stw	r0, 0(r6)
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 0x1c, 0x1b, 0x1f
    stb	r0, 0(r7)
    blr	
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 0x17, 0x1f, 0x1f
    stw	r0, 0(r5)
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 0x16, 0x1d, 0x1f
    stw	r0, 0(r6)
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 0x13, 0x1b, 0x1f
    stb	r0, 0(r7)
    blr	
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 0xe, 0x1f, 0x1f
    stw	r0, 0(r5)
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 0xd, 0x1d, 0x1f
    stw	r0, 0(r6)
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 0xa, 0x1b, 0x1f
    stb	r0, 0(r7)
    blr	
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 5, 0x1f, 0x1f
    stw	r0, 0(r5)
    lwz	r0, 0(r8)
    rlwinm	r0, r0, 4, 0x1d, 0x1f
    stw	r0, 0(r6)
    lwz	r0, 0(r9)
    clrlwi	r0, r0, 0x1b
    stb	r0, 0(r7)
    blr	
    lwz	r0, 0(r9)
    rlwinm	r0, r0, 0x1b, 0x1f, 0x1f
    stw	r0, 0(r5)
    lwz	r0, 0(r9)
    rlwinm	r0, r0, 0x1a, 0x1d, 0x1f
    stw	r0, 0(r6)
    lwz	r0, 0(r9)
    rlwinm	r0, r0, 0x17, 0x1b, 0x1f
    stb	r0, 0(r7)
    blr	
    lwz	r0, 0(r9)
    rlwinm	r0, r0, 0x12, 0x1f, 0x1f
    stw	r0, 0(r5)
    lwz	r0, 0(r9)
    rlwinm	r0, r0, 0x11, 0x1d, 0x1f
    stw	r0, 0(r6)
    lwz	r0, 0(r9)
    rlwinm	r0, r0, 0xe, 0x1b, 0x1f
    stb	r0, 0(r7)
    blr	
    lwz	r0, 0(r9)
    rlwinm	r0, r0, 9, 0x1f, 0x1f
    stw	r0, 0(r5)
    lwz	r0, 0(r9)
    rlwinm	r0, r0, 8, 0x1d, 0x1f
    stw	r0, 0(r6)
    lwz	r0, 0(r9)
    srwi	r0, r0, 0x1b
    stb	r0, 0(r7)
    blr	
_80033954:
    li	r0, 1
    stw	r0, 0(r5)
    li	r0, 0
    stw	r0, 0(r6)
    stb	r0, 0(r7)
    blr	
}

asm void fn_8003396C(register void* p)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    li	r31, 9
    stw	r30, 0x18(r1)
    addi	r30, r4, 0
    stw	r29, 0x14(r1)
    addi	r29, r3, 0
_80033990:
    stw	r31, 0(r30)
    addi	r3, r29, 0
    addi	r4, r31, 0
    addi	r5, r30, 4
    addi	r6, r30, 8
    addi	r7, r30, 0xc
    bl      fn_800336EC
    addi	r31, r31, 1
    cmpwi	r31, 0x14
    addi	r30, r30, 0x10
    ble     _80033990
    li	r0, 0xff
    stw	r0, 0(r30)
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void GXSetArray(register void* p)
{
    nofralloc
    cmpwi	r3, 0x19
    bne     _800339ec
    li	r3, 0xa
_800339ec:
    li	r0, 8
    addi	r6, r3, -9
    lis	r3, -0x33ff
    stb	r0, -0x8000(r3)
    ori	r0, r6, 0xa0
    clrlwi	r4, r4, 2
    stb	r0, -0x8000(r3)
    addic.	r0, r6, -0xc
    stw	r4, -0x8000(r3)
    blt     _80033a2c
    cmpwi	r0, 4
    bge     _80033a2c
    lwz	r3, -0x7de8(r2)
    slwi	r0, r0, 2
    add	r3, r3, r0
    stw	r4, 0x88(r3)
_80033a2c:
    li	r0, 8
    lis	r3, -0x33ff
    stb	r0, -0x8000(r3)
    ori	r0, r6, 0xb0
    clrlwi	r4, r5, 0x18
    stb	r0, -0x8000(r3)
    addic.	r0, r6, -0xc
    stw	r4, -0x8000(r3)
    bltlr	
    cmpwi	r0, 4
    bgelr	
    lwz	r3, -0x7de8(r2)
    slwi	r0, r0, 2
    add	r3, r3, r0
    stw	r4, 0x98(r3)
    blr	
}

asm void fn_80033A6C(register void* p)
{
    nofralloc
    li	r0, 0x48
    lis	r3, -0x33ff
    stb	r0, -0x8000(r3)
    blr	
}

asm void GXSetTexCoordGen2(register void* p, register int a, register int b)
{
    nofralloc
    mflr	r0
    cmplwi	r5, 0x14
    stw	r0, 4(r1)
    li	r11, 0
    li	r12, 0
    stwu	r1, -8(r1)
    li	r10, 5
    bgt     _80033b30
    lis     r9, -0x7fed
    addi	r9, r9, -0x50a0
    slwi	r0, r5, 2
    lwzx	r0, r9, r0
    mtctr	r0
    bctr	
    li	r10, 0
    li	r12, 1
    b       _80033b30
    li	r10, 1
    li	r12, 1
    b       _80033b30
    li	r10, 3
    li	r12, 1
    b       _80033b30
    li	r10, 4
    li	r12, 1
    b       _80033b30
    li	r10, 2
    b       _80033b30
    li	r10, 2
    b       _80033b30
    li	r10, 5
    b       _80033b30
    li	r10, 6
    b       _80033b30
    li	r10, 7
    b       _80033b30
    li	r10, 8
    b       _80033b30
    li	r10, 9
    b       _80033b30
    li	r10, 0xa
    b       _80033b30
    li	r10, 0xb
    b       _80033b30
    li	r10, 0xc
_80033b30:
    cmpwi	r4, 1
    beq     _80033b58
    bge     _80033b48
    cmpwi	r4, 0
    bge     _80033b6c
    b       _80033be8
_80033b48:
    cmpwi	r4, 0xa
    beq     _80033bc0
    bge     _80033be8
    b       _80033b84
_80033b58:
    slwi	r0, r12, 2
    rlwinm	r4, r0, 0, 0x1c, 0x13
    slwi	r0, r10, 7
    or	r11, r4, r0
    b       _80033be8
_80033b6c:
    slwi	r0, r12, 2
    ori	r0, r0, 2
    rlwinm	r4, r0, 0, 0x1c, 0x13
    slwi	r0, r10, 7
    or	r11, r4, r0
    b       _80033be8
_80033b84:
    slwi	r0, r12, 2
    rlwinm	r0, r0, 0, 0x1c, 0x18
    ori	r0, r0, 0x10
    rlwinm	r9, r0, 0, 0x19, 0x13
    slwi	r0, r10, 7
    or	r9, r9, r0
    addi	r5, r5, -0xc
    addi	r0, r4, -2
    rlwinm	r9, r9, 0, 0x14, 0x10
    slwi	r4, r5, 0xc
    or	r4, r9, r4
    rlwinm	r4, r4, 0, 0x11, 0xd
    slwi	r0, r0, 0xf
    or	r11, r4, r0
    b       _80033be8
_80033bc0:
    cmpwi	r5, 0x13
    slwi	r0, r12, 2
    bne     _80033bd8
    rlwinm	r0, r0, 0, 0x1c, 0x18
    ori	r0, r0, 0x20
    b       _80033be0
_80033bd8:
    rlwinm	r0, r0, 0, 0x1c, 0x18
    ori	r0, r0, 0x30
_80033be0:
    rlwinm	r0, r0, 0, 0x19, 0x13
    ori	r11, r0, 0x100
_80033be8:
    li	r10, 0x10
    lis	r9, -0x33ff
    stb	r10, -0x8000(r9)
    addi	r0, r3, 0x1040
    addi	r4, r8, -0x40
    stw	r0, -0x8000(r9)
    rlwinm	r5, r4, 0, 0x18, 0x16
    rlwinm	r4, r7, 8, 0x10, 0x17
    stw	r11, -0x8000(r9)
    addi	r0, r3, 0x1050
    cmplwi	r3, 6
    stb	r10, -0x8000(r9)
    or	r4, r5, r4
    stw	r0, -0x8000(r9)
    stw	r4, -0x8000(r9)
    bgt     _80033d18
    lis     r4, jumptable_8012AF44@ha
    addi	r4, r4, jumptable_8012AF44@l
    slwi	r0, r3, 2
    lwzx	r0, r4, r0
    mtctr	r0
    bctr	
    lwz	r4, -0x7de8(r2)
    slwi	r0, r6, 6
    addi	r5, r4, 0x80
    lwz	r4, 0x80(r4)
    rlwinm	r4, r4, 0, 0x1a, 0x13
    or	r0, r4, r0
    stw	r0, 0(r5)
    b       _80033d34
    lwz	r4, -0x7de8(r2)
    slwi	r0, r6, 0xc
    addi	r5, r4, 0x80
    lwz	r4, 0x80(r4)
    rlwinm	r4, r4, 0, 0x14, 0xd
    or	r0, r4, r0
    stw	r0, 0(r5)
    b       _80033d34
    lwz	r4, -0x7de8(r2)
    slwi	r0, r6, 0x12
    addi	r5, r4, 0x80
    lwz	r4, 0x80(r4)
    rlwinm	r4, r4, 0, 0xe, 7
    or	r0, r4, r0
    stw	r0, 0(r5)
    b       _80033d34
    lwz	r4, -0x7de8(r2)
    slwi	r0, r6, 0x18
    addi	r5, r4, 0x80
    lwz	r4, 0x80(r4)
    rlwinm	r4, r4, 0, 8, 1
    or	r0, r4, r0
    stw	r0, 0(r5)
    b       _80033d34
    lwz	r4, -0x7de8(r2)
    lwzu	r0, 0x84(r4)
    rlwinm	r0, r0, 0, 0, 0x19
    or	r0, r0, r6
    stw	r0, 0(r4)
    b       _80033d34
    lwz	r4, -0x7de8(r2)
    slwi	r0, r6, 6
    addi	r5, r4, 0x84
    lwz	r4, 0x84(r4)
    rlwinm	r4, r4, 0, 0x1a, 0x13
    or	r0, r4, r0
    stw	r0, 0(r5)
    b       _80033d34
    lwz	r4, -0x7de8(r2)
    slwi	r0, r6, 0xc
    addi	r5, r4, 0x84
    lwz	r4, 0x84(r4)
    rlwinm	r4, r4, 0, 0x14, 0xd
    or	r0, r4, r0
    stw	r0, 0(r5)
    b       _80033d34
_80033d18:
    lwz	r4, -0x7de8(r2)
    slwi	r0, r6, 0x12
    addi	r5, r4, 0x84
    lwz	r4, 0x84(r4)
    rlwinm	r4, r4, 0, 0xe, 7
    or	r0, r4, r0
    stw	r0, 0(r5)
_80033d34:
    addi	r3, r3, 1
    bl      fn_80039088
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void GXSetNumTexGens(register void* p)
{
    nofralloc
    lwz	r6, -0x7de8(r2)
    clrlwi	r8, r3, 0x18
    li	r4, 0x10
    lwz	r5, 0x204(r6)
    lis	r3, -0x33ff
    li	r0, 0x103f
    rlwinm	r5, r5, 0, 0, 0x1b
    or	r5, r5, r8
    stw	r5, 0x204(r6)
    stb	r4, -0x8000(r3)
    stw	r0, -0x8000(r3)
    stw	r8, -0x8000(r3)
    lwz	r0, 0x4f4(r6)
    ori	r0, r0, 4
    stw	r0, 0x4f4(r6)
    blr	
}


#pragma pop
