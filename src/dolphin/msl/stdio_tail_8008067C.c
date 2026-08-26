typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

#pragma force_active on

// MSL stdio tail 0x8008067C-0x800807F4 (__stdio_atexit, vfprintf-ish wrappers)

extern void __pformatter(void);
extern void __close_all(void);
extern void __StringWrite(void);

extern unsigned char __stdio_exit[4];
// provenance: original
// harvested 2026-08-26 from hard's logged 100% attempt; spliced into the current head
void __stdio_atexit(void) { *(void (**)(void))__stdio_exit = __close_all; }

// provenance: original
// harvested 2026-08-26 from hard's logged 100% attempt; spliced into the current head
void fn_8008068C(unsigned char* p) { p[9] = 0; p[10] = 0; }

asm void sprintf(void)
{
    nofralloc
    stwu	r1, -0xa0(r1)
    mflr	r0
    stw	r0, 0xa4(r1)
    stmw	r25, 0x84(r1)
    mr	r25, r3
    mr	r26, r4
    bne     cr1, _800806d8
    stfd	f1, 0x28(r1)
    stfd	f2, 0x30(r1)
    stfd	f3, 0x38(r1)
    stfd	f4, 0x40(r1)
    stfd	f5, 0x48(r1)
    stfd	f6, 0x50(r1)
    stfd	f7, 0x58(r1)
    stfd	f8, 0x60(r1)
_800806d8:
    addi	r29, r1, 0xa8
    addi	r30, r1, 8
    lis	r28, 0x200
    li	r31, -1
    li	r12, 0
    lis     r11, __StringWrite@ha
    stw	r4, 0xc(r1)
    addi	r27, r1, 0x74
    addi	r0, r11, __StringWrite@l
    addi	r4, r1, 0x68
    stw	r3, 8(r1)
    mr	r3, r0
    stw	r5, 0x10(r1)
    mr	r5, r26
    stw	r6, 0x14(r1)
    mr	r6, r27
    stw	r7, 0x18(r1)
    stw	r8, 0x1c(r1)
    stw	r9, 0x20(r1)
    stw	r10, 0x24(r1)
    stw	r28, 0x74(r1)
    stw	r29, 0x78(r1)
    stw	r30, 0x7c(r1)
    stw	r25, 0x68(r1)
    stw	r31, 0x6c(r1)
    stw	r12, 0x70(r1)
    bl      __pformatter
    cmplwi	r25, 0
    beq     _80080768
    li	r0, -1
    li	r4, -2
    cmplw	r3, r0
    bge     _80080760
    mr	r4, r3
_80080760:
    li	r0, 0
    stbx	r0, r25, r4
_80080768:
    lmw	r25, 0x84(r1)
    lwz	r0, 0xa4(r1)
    mtlr	r0
    addi	r1, r1, 0xa0
    blr
}

asm void fn_8008077C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    mr	r6, r5
    mr	r5, r4
    stw	r0, 0x24(r1)
    li	r7, -1
    li	r0, 0
    addi	r4, r1, 8
    stw	r31, 0x1c(r1)
    mr	r31, r3
    lis     r3, __StringWrite@ha
    stw	r31, 8(r1)
    addi	r3, r3, __StringWrite@l
    stw	r7, 0xc(r1)
    stw	r0, 0x10(r1)
    bl      __pformatter
    cmplwi	r31, 0
    beq     _800807e0
    li	r0, -1
    li	r4, -2
    cmplw	r3, r0
    bge     _800807d8
    mr	r4, r3
_800807d8:
    li	r0, 0
    stbx	r0, r31, r4
_800807e0:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

#pragma force_active off
