typedef int BOOL;
typedef signed char s8;
typedef short s16;
typedef long long s64;
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
#pragma push
#pragma force_active on

extern asm int WriteSram(void* buffer, unsigned long offset, unsigned long size);
extern s32 EXILock(s32 chan, s32 dev, void* callback);
extern s32 EXISelect(s32 chan, s32 dev, s32 freq);
extern s32 EXIUnlock(s32 chan);
extern s32 EXIImm(s32 chan, void* buffer, u32 size, u32 type, void* callback);
extern s32 EXISync(s32 chan);
extern s32 EXIDeselect(s32 chan);
extern s32 EXIImmEx(s32 chan, void* buffer, u32 size, s32 periodic);

static asm void WriteSramCallback(void)
{
    nofralloc
    mflr	r0
    lis	r3, -0x7fea
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    addi	r31, r3, -0x4040
    stw	r30, 0x10(r1)
    addi	r30, r31, 0x40
    lwz	r4, 0x40(r31)
    add	r3, r31, r4
    subfic	r5, r4, 0x40
    bl      WriteSram
    stw	r3, 0x4c(r31)
    lwz	r0, 0x4c(r31)
    cmpwi	r0, 0
    beq     _8000f658
    li	r0, 0x40
    stw	r0, 0(r30)
_8000f658:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

static asm int WriteSram(void* buffer, unsigned long offset, unsigned long size)
{
    nofralloc
    mflr	r0
    lis	r6, -0x7fff
    stw	r0, 4(r1)
    addi	r0, r6, -0x9f0
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    addi	r31, r4, 0
    li	r4, 1
    stw	r30, 0x20(r1)
    addi	r30, r5, 0
    mr	r5, r0
    stw	r29, 0x1c(r1)
    addi	r29, r3, 0
    li	r3, 0
    bl      EXILock
    cmpwi	r3, 0
    bne     _8000f6bc
    li	r3, 0
    b       _8000f76c
_8000f6bc:
    li	r3, 0
    li	r4, 1
    li	r5, 3
    bl      EXISelect
    cmpwi	r3, 0
    bne     _8000f6e4
    li	r3, 0
    bl      EXIUnlock
    li	r3, 0
    b       _8000f76c
_8000f6e4:
    slwi	r31, r31, 6
    addi	r0, r31, 0x100
    oris	r0, r0, 0xa000
    stw	r0, 0x14(r1)
    addi	r4, r1, 0x14
    li	r3, 0
    li	r5, 4
    li	r6, 1
    li	r7, 0
    bl      EXIImm
    cntlzw	r0, r3
    srwi	r31, r0, 5
    li	r3, 0
    bl      EXISync
    cntlzw	r0, r3
    srwi	r0, r0, 5
    addi	r4, r29, 0
    addi	r5, r30, 0
    or	r31, r31, r0
    li	r3, 0
    li	r6, 1
    bl      EXIImmEx
    cntlzw	r0, r3
    srwi	r0, r0, 5
    or	r31, r31, r0
    li	r3, 0
    bl      EXIDeselect
    cntlzw	r0, r3
    srwi	r0, r0, 5
    or	r31, r31, r0
    li	r3, 0
    bl      EXIUnlock
    cntlzw	r0, r31
    srwi	r3, r0, 5
_8000f76c:
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

#pragma pop
