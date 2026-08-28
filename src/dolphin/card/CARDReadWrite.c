// dolphin/card/CARDReadWrite.c -- orphan unit auto_01_80030380_text
// 0x80030380-0x800307CC: CARDFastOpen, CARDFastWrite, CARDGetSerialNo,
// CARDWriteProfile. Newer-Dolphin CARD helpers absent from Melee SDK;
// transcribed from retail disasm as asm bodies (nofralloc).

typedef int s32;
typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void *memcpy(register void *dst, register const void *src, register u32 n);
extern int strncmp(register const char *a, register const char *b, register u32 n);

extern s32 __CARDGetControlBlock(s32 chan, void **pcard);
extern s32 __CARDPutControlBlock(void *card, s32 err);
extern void *__CARDGetDirBlock(void *card);
extern s32 __CARDAccess(void *card, void *ent);
extern s32 __CARDIsPublic(void *ent);
extern s32 __CARDUpdateDir(s32 chan, void *callback);

#pragma push
#pragma force_active on

// provenance: harvest:runs.sqlite — CARDFastOpen recovered from cardfastopen-retail-r1.c, compiled by hard2 at 2026-08-27T23:05 and scored 100 against main/dolphin/card/CARDReadWrite; original reference not recorded
// 0x80030380 | size: 0xBC
// provenance: dolsdk2001:src/card/CARDOpen.c:69; retail-adapted ABI/control flow
s32 CARDFastOpen(register s32 chan, register s32 fileNo, register void *fileInfo)
{
    void *card;
    unsigned char *dir;
    unsigned char *ent;
    s32 result;
    if (fileNo < 0 || fileNo >= 0x7f)
        return -0x80;
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0)
        return result;
    dir = (unsigned char *)__CARDGetDirBlock(card);
    ent = dir + (fileNo << 6);
    result = __CARDAccess(card, ent);
    if (result == -0xA)
        result = __CARDIsPublic(ent);
    if (result >= 0)
        memcpy(fileInfo, ent, 0x40);
    return __CARDPutControlBlock(card, result);
}

// 0x8003043C | size: 0x254
asm s32 CARDFastWrite(register s32 chan, register s32 fileNo, register void *buf, register void *fileInfo)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x40(r1)
    stmw    r25, 0x24(r1)
    mr.     r28, r4
    addi    r27, r3, 0
    addi    r29, r5, 0
    addi    r30, r6, 0
    blt     _8003047C
    cmpwi   r28, 0x7f
    bge     _8003047C
    lbz     r0, 0x8(r29)
    cmplwi  r0, 0xff
    beq     _8003047C
    cmplwi  r0, 0x0
    bne     _80030484
_8003047C:
    li      r3, -0x80
    b       _8003067C
_80030484:
    addi    r3, r27, 0
    addi    r4, r1, 0x18
    bl      __CARDGetControlBlock
    cmpwi   r3, 0x0
    bge     _8003049C
    b       _8003067C
_8003049C:
    lwz     r3, 0x18(r1)
    bl      __CARDGetDirBlock
    mr      r0, r3
    lwz     r3, 0x18(r1)
    mr      r26, r0
    slwi    r0, r28, 6
    add     r31, r26, r0
    addi    r4, r31, 0
    bl      __CARDAccess
    mr.     r4, r3
    bge     _800304D4
    lwz     r3, 0x18(r1)
    bl      __CARDPutControlBlock
    b       _8003067C
_800304D4:
    addi    r4, r29, 0x8
    addi    r3, r29, 0x28
    subf    r0, r4, r3
    cmplw   r4, r3
    mtctr   r0
    bge     _80030520
_800304EC:
    lbz     r0, 0x0(r4)
    cmplwi  r0, 0x0
    bne     _80030518
    addi    r0, r29, 0x28
    li      r3, 0x0
    b       _80030508
_80030504:
    stb     r3, 0x0(r4)
_80030508:
    addi    r4, r4, 0x1
    cmplw   r4, r0
    blt     _80030504
    b       _80030520
_80030518:
    addi    r4, r4, 0x1
    bdnz    _800304EC
_80030520:
    addi    r3, r31, 0x8
    addi    r4, r29, 0x8
    li      r5, 0x20
    bl      strncmp
    cmpwi   r3, 0x0
    bne     _80030568
    addi    r3, r31, 0
    addi    r4, r29, 0
    li      r5, 0x4
    bl      strncmp
    cmpwi   r3, 0x0
    bne     _80030568
    addi    r3, r31, 0x4
    addi    r4, r29, 0x4
    li      r5, 0x2
    bl      strncmp
    cmpwi   r3, 0x0
    beq     _80030618
_80030568:
    li      r25, 0x0
_8003056C:
    cmpw    r25, r28
    beq     _800305D8
    lbz     r0, 0x0(r26)
    cmplwi  r0, 0xff
    beq     _800305D8
    addi    r3, r26, 0
    addi    r4, r29, 0
    li      r5, 0x4
    bl      strncmp
    cmpwi   r3, 0x0
    bne     _800305D8
    addi    r3, r26, 0x4
    addi    r4, r29, 0x4
    li      r5, 0x2
    bl      strncmp
    cmpwi   r3, 0x0
    bne     _800305D8
    addi    r3, r26, 0x8
    addi    r4, r29, 0x8
    li      r5, 0x20
    bl      strncmp
    cmpwi   r3, 0x0
    bne     _800305D8
    lwz     r3, 0x18(r1)
    li      r4, -0x7
    bl      __CARDPutControlBlock
    b       _8003067C
_800305D8:
    addi    r25, r25, 0x1
    cmpwi   r25, 0x7f
    addi    r26, r26, 0x40
    blt     _8003056C
    addi    r3, r31, 0x8
    addi    r4, r29, 0x8
    li      r5, 0x20
    bl      memcpy
    addi    r3, r31, 0
    addi    r4, r29, 0
    li      r5, 0x4
    bl      memcpy
    addi    r3, r31, 0x4
    addi    r4, r29, 0x4
    li      r5, 0x2
    bl      memcpy
_80030618:
    lwz     r0, 0x28(r29)
    addi    r3, r27, 0
    addi    r4, r30, 0
    stw     r0, 0x28(r31)
    lbz     r0, 0x7(r29)
    stb     r0, 0x7(r31)
    lwz     r0, 0x2c(r29)
    stw     r0, 0x2c(r31)
    lhz     r0, 0x30(r29)
    sth     r0, 0x30(r31)
    lhz     r0, 0x32(r29)
    sth     r0, 0x32(r31)
    lwz     r0, 0x3c(r29)
    stw     r0, 0x3c(r31)
    lbz     r0, 0x34(r29)
    stb     r0, 0x34(r31)
    lbz     r0, 0x35(r29)
    stb     r0, 0x35(r31)
    bl      __CARDUpdateDir
    mr.     r26, r3
    bge     _80030678
    lwz     r3, 0x18(r1)
    mr      r4, r26
    bl      __CARDPutControlBlock
_80030678:
    mr      r3, r26
_8003067C:
    lmw     r25, 0x24(r1)
    lwz     r0, 0x44(r1)
    addi    r1, r1, 0x40
    mtlr    r0
    blr
}

// 0x80030690 | size: 0xC4
asm s32 CARDGetSerialNo(register s32 chan, register u32 *serial)
{
    nofralloc
    mflr    r0
    cmpwi   r3, 0x0
    stw     r0, 0x4(r1)
    stwu    r1, -0x20(r1)
    stw     r31, 0x1c(r1)
    addi    r31, r4, 0
    blt     _800306B4
    cmpwi   r3, 0x2
    blt     _800306BC
_800306B4:
    li      r3, -0x80
    b       _80030740
_800306BC:
    addi    r4, r1, 0x10
    bl      __CARDGetControlBlock
    cmpwi   r3, 0x0
    bge     _800306D0
    b       _80030740
_800306D0:
    lwz     r3, 0x10(r1)
    li      r7, 0x0
    li      r6, 0x0
    lwz     r5, 0x80(r3)
    li      r4, 0x0
    lwz     r3, 0x4(r5)
    lwz     r0, 0x0(r5)
    xor     r7, r7, r3
    addi    r3, r5, 0x8
    xor     r6, r6, r0
    lwz     r0, 0x8(r5)
    lwz     r3, 0x4(r3)
    xor     r6, r6, r0
    xor     r7, r7, r3
    addi    r3, r5, 0x10
    lwz     r0, 0x10(r5)
    lwz     r3, 0x4(r3)
    xor     r6, r6, r0
    xor     r7, r7, r3
    addi    r3, r5, 0x18
    lwz     r0, 0x18(r5)
    lwz     r3, 0x4(r3)
    xor     r6, r6, r0
    xor     r7, r7, r3
    stw     r7, 0x4(r31)
    stw     r6, 0x0(r31)
    lwz     r3, 0x10(r1)
    bl      __CARDPutControlBlock
_80030740:
    lwz     r0, 0x24(r1)
    lwz     r31, 0x1c(r1)
    addi    r1, r1, 0x20
    mtlr    r0
    blr
}

// 0x80030754 | size: 0x78
asm s32 CARDWriteProfile(register s32 chan, register void *buf,
                         register void *r5, register void *r6)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x68(r1)
    stw     r31, 0x64(r1)
    addi    r31, r6, 0
    stw     r30, 0x60(r1)
    addi    r30, r5, 0
    addi    r5, r1, 0x18
    stw     r29, 0x5c(r1)
    addi    r29, r4, 0
    stw     r28, 0x58(r1)
    addi    r28, r3, 0
    bl      CARDFastOpen
    cmpwi   r3, 0x0
    bge     _80030794
    b       _800307AC
_80030794:
    stb     r30, 0x4c(r1)
    addi    r3, r28, 0
    addi    r4, r29, 0
    addi    r6, r31, 0
    addi    r5, r1, 0x18
    bl      CARDFastWrite
_800307AC:
    lwz     r0, 0x6c(r1)
    lwz     r31, 0x64(r1)
    lwz     r30, 0x60(r1)
    lwz     r29, 0x5c(r1)
    lwz     r28, 0x58(r1)
    addi    r1, r1, 0x68
    mtlr    r0
    blr
}

#pragma pop
