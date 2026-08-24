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

extern void OSDisableInterrupts(void);
extern void OSEnableInterrupts(void);
extern void OSClearContext(void* context);
extern void OSSetCurrentContext(void* context);
extern void DVDInit(void);
extern s32 DVDSetAutoInvalidation(s32);
extern s32 DVDPause(s32);
extern s32 DVDCancelAllAsync(void*);
extern void __OSMaskInterrupts(u32 mask);
extern void __OSUnmaskInterrupts(u32 mask);
extern u64 OSGetTime(void);
extern s32 DVDCheckCancel(void* block);
extern void* DVDGetCurrentDiskID(void);
extern void AISetStreamPlayState(s32);
extern void fn_8001E2BC(s32);
extern void fn_8001E2E8(s32);
extern s32 DVDBSChangeDiskAsync(void* a, s32 b);
extern s32 DVDGetCommandBlockStatus(void* block);
extern s32 DVDReadAbsAsyncPrio(void* block, void* addr, u32 length, u32 offset, void* caddr);
extern void ICInvalidateRange(void* addr, u32 nBytes);
extern void ICFlashInvalidate(void);
extern void __OSDoHotReset(int arg0);
extern unsigned char lbl_8015BFA0[32];

static asm void Run(register void* addr)
{
    nofralloc
    sync	
    isync	
    mtlr	r3
    blr	
}

static asm void Callback(s32 result, void* block)
{
    nofralloc
    li	r0, 1
    stw	r0, -0x7bf8(r13)
    blr	
}

asm void __OSReboot(register unsigned long resetCode, register unsigned long bootDol)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x380(r1)
    stmw	r26, 0x368(r1)
    lis     r3, lbl_8015BFA0@ha
    addi	r30, r3, lbl_8015BFA0@l
    bl      OSDisableInterrupts
    lwz	r5, -0x7c00(r13)
    lis	r4, -0x7ed0
    lwz	r0, -0x7bfc(r13)
    li	r27, 0
    lis	r31, -0x7e80
    li	r6, 1
    stw	r27, -4(r31)
    lis	r26, -0x8000
    stw	r27, -8(r31)
    addi	r3, r1, 0xa0
    stb	r6, 0x30e2(r26)
    stw	r5, -0x2010(r4)
    stw	r0, -0x2014(r4)
    bl      OSClearContext
    addi	r3, r1, 0xa0
    bl      OSSetCurrentContext
    bl      DVDInit
    li	r3, 1
    bl      DVDSetAutoInvalidation
    bl      DVDPause
    lis	r3, -0x7fff
    stw	r27, -0x7bf8(r13)
    addi	r3, r3, -0x14fc
    bl      DVDCancelAllAsync
    li	r3, -0x20
    bl      __OSMaskInterrupts
    li	r3, 0x400
    bl      __OSUnmaskInterrupts
    bl      OSEnableInterrupts
    bl      OSGetTime
    mr	r29, r4
    mr	r28, r3
    b       _8000ebb0
_8000ebb0:
    lwz	r0, 0xf8(r26)
    xoris	r26, r27, 0x8000
    srwi	r27, r0, 2
    b       _8000ebc0
_8000ebc0:
    b       _8000ec00
_8000ebc4:
    bl      DVDCheckCancel
    cmpwi	r3, 0
    beq     _8000ebf8
    bl      OSGetTime
    subfc	r4, r29, r4
    subfe	r0, r28, r3
    xoris	r3, r0, 0x8000
    subfc	r0, r4, r27
    subfe	r3, r3, r26
    subfe	r3, r26, r26
    neg	r3, r3
    cmpwi	r3, 0
    beq     _8000ec00
_8000ebf8:
    lwz	r3, -4(r31)
    bl      __OSDoHotReset
_8000ec00:
    lwz	r0, -0x7bf8(r13)
    cmpwi	r0, 1
    bne     _8000ebc4
    lwz	r0, -0x7c6c(r13)
    cmpwi	r0, 0
    bne     _8000ecdc
    bl      DVDGetCurrentDiskID
    lbz	r0, 8(r3)
    cmplwi	r0, 0
    beq     _8000ec30
    li	r0, 1
    b       _8000ec34
_8000ec30:
    li	r0, 0
_8000ec34:
    cmpwi	r0, 0
    beq     _8000ecdc
    li	r3, 0
    bl      fn_8001E2BC
    li	r3, 0
    bl      fn_8001E2E8
    addi	r3, r1, 0x70
    li	r4, 0
    bl      DVDBSChangeDiskAsync
    bl      OSGetTime
    mr	r31, r4
    mr	r29, r3
    b       _8000ec68
_8000ec68:
    lis	r3, -0x8000
    lwz	r3, 0xf8(r3)
    li	r0, 0
    xoris	r27, r0, 0x8000
    srwi	r28, r3, 2
    lis	r26, -0x7e80
    b       _8000ec84
_8000ec84:
    b       _8000ecc4
_8000ec88:
    bl      DVDCheckCancel
    cmpwi	r3, 0
    beq     _8000ecbc
    bl      OSGetTime
    subfc	r4, r31, r4
    subfe	r0, r29, r3
    xoris	r3, r0, 0x8000
    subfc	r0, r4, r28
    subfe	r3, r3, r27
    subfe	r3, r27, r27
    neg	r3, r3
    cmpwi	r3, 0
    beq     _8000ecc4
_8000ecbc:
    lwz	r3, -4(r26)
    bl      __OSDoHotReset
_8000ecc4:
    addi	r3, r1, 0x70
    bl      DVDGetCommandBlockStatus
    cmpwi	r3, 0
    bne     _8000ec88
    li	r3, 0
    bl      AISetStreamPlayState
_8000ecdc:
    mr	r4, r30
    addi	r3, r1, 0x40
    li	r5, 0x20
    li	r6, 0x2440
    li	r7, 0
    li	r8, 0
    bl      DVDReadAbsAsyncPrio
    bl      OSGetTime
    mr	r26, r4
    mr	r31, r3
    b       _8000ed08
_8000ed08:
    lis	r3, -0x8000
    lwz	r3, 0xf8(r3)
    li	r0, 0
    xoris	r28, r0, 0x8000
    srwi	r29, r3, 2
    lis	r27, -0x7e80
    b       _8000ed24
_8000ed24:
    b       _8000ed64
_8000ed28:
    bl      DVDCheckCancel
    cmpwi	r3, 0
    beq     _8000ed5c
    bl      OSGetTime
    subfc	r4, r26, r4
    subfe	r0, r31, r3
    xoris	r3, r0, 0x8000
    subfc	r0, r4, r29
    subfe	r3, r3, r28
    subfe	r3, r28, r28
    neg	r3, r3
    cmpwi	r3, 0
    beq     _8000ed64
_8000ed5c:
    lwz	r3, -4(r27)
    bl      __OSDoHotReset
_8000ed64:
    addi	r3, r1, 0x40
    bl      DVDGetCommandBlockStatus
    cmpwi	r3, 0
    bne     _8000ed28
    lwz	r5, 0x18(r30)
    addi	r3, r1, 0x10
    lwz	r6, 0x14(r30)
    lis	r4, -0x7ed0
    addi	r0, r5, 0x1f
    addi	r6, r6, 0x20
    rlwinm	r26, r0, 0, 0, 0x1a
    mr	r5, r26
    addi	r6, r6, 0x2440
    li	r7, 0
    li	r8, 0
    bl      DVDReadAbsAsyncPrio
    bl      OSGetTime
    mr	r27, r4
    mr	r28, r3
    b       _8000edb4
_8000edb4:
    lis	r3, -0x8000
    lwz	r3, 0xf8(r3)
    li	r0, 0
    xoris	r31, r0, 0x8000
    srwi	r29, r3, 2
    lis	r30, -0x7e80
    b       _8000edd0
_8000edd0:
    b       _8000ee10
_8000edd4:
    bl      DVDCheckCancel
    cmpwi	r3, 0
    beq     _8000ee08
    bl      OSGetTime
    subfc	r4, r27, r4
    subfe	r0, r28, r3
    xoris	r3, r0, 0x8000
    subfc	r0, r4, r29
    subfe	r3, r3, r31
    subfe	r3, r31, r31
    neg	r3, r3
    cmpwi	r3, 0
    beq     _8000ee10
_8000ee08:
    lwz	r3, -4(r30)
    bl      __OSDoHotReset
_8000ee10:
    addi	r3, r1, 0x10
    bl      DVDGetCommandBlockStatus
    cmpwi	r3, 0
    bne     _8000edd4
    lis	r3, -0x7ed0
    mr	r4, r26
    bl      ICInvalidateRange
    bl      OSDisableInterrupts
    bl      ICFlashInvalidate
    lis	r3, -0x7ed0
    bl      Run
    lmw	r26, 0x368(r1)
    lwz	r0, 0x384(r1)
    addi	r1, r1, 0x380
    mtlr	r0
    blr	
}

asm void OSSetSaveRegion(void* start, void* end)
{
    nofralloc
    stw	r3, -0x7c00(r13)
    stw	r4, -0x7bfc(r13)
    blr	
}

asm void OSGetSaveRegion(void* outStart, void* outEnd)
{
    nofralloc
    lwz	r0, -0x7c4c(r13)
    stw	r0, 0(r3)
    lwz	r0, -0x7c50(r13)
    stw	r0, 0(r4)
    blr	
}

#pragma pop
