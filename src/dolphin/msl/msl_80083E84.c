typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

#pragma force_active on

// MSL math/string-glue region 0x80083E84-0x80088600 (pm11-c region A)

extern void fn_80087F54(void); // forward decl
extern void OSGetConsoleType(void);
extern void InitializeUART(void);
extern void WriteUARTN(void);
extern void _savefpr_25(void);
extern void _restfpr_25(void);
extern void __div2u(void);
extern void __sformatter(void);
extern void TRKWriteFileChecked(void);
extern void MSL_device_link_fn(void); // forward decl: label must be declared before first use
extern void MSLStrToLong(void); // forward decl
extern void __fpclassifyd(void); // forward decl
extern void atan(void); // forward decl
extern void fn_80087E80(void); // forward decl
extern void fn_80086D50(void); // forward decl
extern void fn_800868BC(void); // forward decl
extern void fn_80087BA4(void); // forward decl
extern void fn_80087F54(void); // forward decl
extern void fn_80087F54(void); // forward decl
extern unsigned char INFINITY_str[12];
extern void __StringRead(void);
extern unsigned char jumptable_8015B738[68];
extern unsigned char jumptable_8015B77C[68];
extern unsigned char lbl_800953A0[44];
extern unsigned char lbl_800953D8[48];
extern unsigned char lbl_80095408[264];
extern unsigned char lbl_80095510[128];
extern unsigned char lbl_80095590[16];
extern unsigned char lbl_800955A0[64];
extern unsigned char lbl_800955E0[104];
extern unsigned char lbl_8015B100[256];
extern unsigned char lbl_8015B300[256];
extern unsigned char lbl_8015B400[56];

asm void atof(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r4, __StringRead@ha
    stw	r0, 0x24(r1)
    li	r0, 0
    addi	r4, r4, __StringRead@l
    addi	r5, r1, 0x10
    stw	r3, 0x10(r1)
    lis	r3, -0x8000
    addi	r3, r3, -1
    addi	r6, r1, 8
    stw	r0, 0x14(r1)
    addi	r7, r1, 0xc
    bl      MSL_device_link_fn
    lwz	r0, 0xc(r1)
    fabs	f2, f1
    cmpwi	r0, 0
    bc      4, 2, _80083ef8
    lfd	f0, -0x7948(r2)
    fcmpu	cr0, f0, f1
    bc      12, 2, _80083f00
    lis	r3, -0x7fe6
    lfd	f0, 0x6650(r3)
    fcmpo	cr0, f2, f0
    bc      12, 0, _80083ef8
    lis	r3, -0x7fe6
    lfd	f0, 0x6658(r3)
    fcmpo	cr0, f2, f0
    bc      4, 1, _80083f00
_80083ef8:
    li	r0, 0x22
    stw	r0, -0x75e0(r13)
_80083f00:
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void MSL_device_link_fn(void)
{
    nofralloc
    stwu	r1, -0xb0(r1)
    mflr	r0
    lis     r8, lbl_800953A0@ha
    stw	r0, 0xb4(r1)
    li	r0, 0
    stmw	r14, 0x68(r1)
    addi	r23, r8, lbl_800953A0@l
    mr	r16, r4
    lis     r4, lbl_8015B400@ha
    addi	r14, r4, lbl_8015B400@l
    mr	r17, r5
    mr	r18, r7
    stw	r6, 0xc(r1)
    mr	r12, r16
    addi	r26, r1, 0x18
    stw	r3, 8(r1)
    mr	r3, r17
    li	r15, 1
    li	r31, 0
    li	r29, 0
    li	r28, 0
    li	r27, 0
    li	r24, 0
    lwz	r22, 0(r23)
    lwz	r20, 4(r23)
    lwz	r21, 8(r23)
    lwz	r4, 0xc(r23)
    lwz	r5, 0x10(r23)
    lwz	r19, 0x14(r23)
    lwz	r11, 0x18(r23)
    lwz	r10, 0x1c(r23)
    lwz	r9, 0x20(r23)
    lwz	r8, 0x24(r23)
    lhz	r7, 0x28(r23)
    li	r23, 0
    stw	r22, 0x2c(r1)
    li	r22, 0
    lwz	r6, 0(r14)
    li	r14, 0
    stw	r20, 0x30(r1)
    li	r20, 0
    stw	r4, 0x38(r1)
    li	r4, 0
    stw	r5, 0x3c(r1)
    li	r5, 0
    stw	r20, 0x60(r1)
    li	r20, 0
    stw	r20, 0x5c(r1)
    li	r20, 0
    stw	r21, 0x34(r1)
    stw	r19, 0x40(r1)
    stw	r11, 0x44(r1)
    stw	r10, 0x48(r1)
    stw	r9, 0x4c(r1)
    stw	r8, 0x50(r1)
    sth	r7, 0x54(r1)
    lbz	r21, 0(r6)
    stw	r20, 0x58(r1)
    stw	r0, 0(r18)
    mtctr	r12
    li	r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_80084010:
    cmpwi	r15, 0x80
    bc      12, 2, _80084690
    bc      4, 0, _80084074
    cmpwi	r15, 8
    bc      12, 2, _800844f8
    bc      4, 0, _80084050
    cmpwi	r15, 3
    bc      12, 2, _80084c54
    bc      4, 0, _80084044
    cmpwi	r15, 1
    bc      12, 2, _800840c4
    bc      4, 0, _80084404
    b       _80084c54
_80084044:
    cmpwi	r15, 5
    bc      4, 0, _80084c54
    b       _800844c4
_80084050:
    cmpwi	r15, 0x20
    bc      12, 2, _800845bc
    bc      4, 0, _80084068
    cmpwi	r15, 0x10
    bc      12, 2, _80084594
    b       _80084c54
_80084068:
    cmpwi	r15, 0x40
    bc      12, 2, _80084638
    b       _80084c54
_80084074:
    cmpwi	r15, 0x2000
    bc      12, 2, _800842c0
    bc      4, 0, _800840a4
    cmpwi	r15, 0x200
    bc      12, 2, _8008474c
    bc      4, 0, _80084098
    cmpwi	r15, 0x100
    bc      12, 2, _800846f4
    b       _80084c54
_80084098:
    cmpwi	r15, 0x400
    bc      12, 2, _80084780
    b       _80084c54
_800840a4:
    lis	r3, 1
    addi	r0, r3, -0x8000
    cmpw	r15, r0
    bc      12, 2, _800847e0
    bc      4, 0, _80084c54
    cmpwi	r15, 0x4000
    bc      12, 2, _800841e0
    b       _80084c54
_800840c4:
    lis     r3, lbl_8015B100@ha
    clrlwi	r5, r4, 0x18
    addi	r3, r3, lbl_8015B100@l
    lbzx	r0, r3, r5
    rlwinm.	r0, r0, 0, 0x1d, 0x1e
    bc      12, 2, _80084100
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    bctrl
    mr	r4, r3
    addi	r29, r29, 1
    b       _80084c54
_80084100:
    cmpwi	r4, -1
    bc      4, 2, _80084110
    li	r0, -1
    b       _8008411c
_80084110:
    lis     r3, lbl_8015B300@ha
    addi	r3, r3, lbl_8015B300@l
    lbzx	r0, r3, r5
_8008411c:
    cmpwi	r0, 0x49
    bc      12, 2, _80084188
    bc      4, 0, _8008414c
    cmpwi	r0, 0x2c
    bc      12, 2, _800841d8
    bc      4, 0, _80084140
    cmpwi	r0, 0x2b
    bc      4, 0, _8008415c
    b       _800841d8
_80084140:
    cmpwi	r0, 0x2e
    bc      4, 0, _800841d8
    b       _80084158
_8008414c:
    cmpwi	r0, 0x4e
    bc      12, 2, _800841b0
    b       _800841d8
_80084158:
    li	r14, 1
_8008415c:
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    li	r0, 1
    mr	r4, r3
    stw	r0, 0x5c(r1)
    b       _80084c54
_80084188:
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    li	r15, 0x4000
    mr	r4, r3
    b       _80084c54
_800841b0:
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    li	r15, 0x2000
    mr	r4, r3
    b       _80084c54
_800841d8:
    li	r15, 2
    b       _80084c54
_800841e0:
    lis     r3, INFINITY_str@ha
    addi	r15, r1, 0x21
    addi	r6, r3, INFINITY_str@l
    li	r19, 1
    lwz	r5, 0(r6)
    lwz	r3, 4(r6)
    lbz	r0, 8(r6)
    stw	r5, 0x20(r1)
    stw	r3, 0x24(r1)
    stb	r0, 0x28(r1)
    b       _80084234
_8008420c:
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r15, r15, 1
    addi	r19, r19, 1
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
_80084234:
    cmpwi	r19, 8
    bc      4, 0, _8008426c
    lbz	r0, 0(r15)
    cmpwi	r4, -1
    extsb	r5, r0
    bc      4, 2, _80084254
    li	r0, -1
    b       _80084264
_80084254:
    lis     r3, lbl_8015B300@ha
    clrlwi	r0, r4, 0x18
    addi	r3, r3, lbl_8015B300@l
    lbzx	r0, r3, r0
_80084264:
    cmpw	r5, r0
    bc      12, 2, _8008420c
_8008426c:
    cmpwi	r19, 3
    bc      12, 2, _8008427c
    cmpwi	r19, 8
    bc      4, 2, _800842b8
_8008427c:
    cmpwi	r14, 0
    bc      12, 2, _80084294
    lis	r3, -0x7fe6
    lfs	f0, 0x664c(r3)
    fneg	f1, f0
    b       _8008429c
_80084294:
    lis	r3, -0x7fe6
    lfs	f1, 0x664c(r3)
_8008429c:
    lwz	r0, 0x5c(r1)
    lwz	r3, 0xc(r1)
    add	r0, r19, r0
    stfd	f1, 0x18(r1)
    add	r0, r29, r0
    stw	r0, 0(r3)
    b       _80084f08
_800842b8:
    li	r15, 0x1000
    b       _80084c54
_800842c0:
    lwz	r3, -0x7950(r2)
    addi	r15, r1, 0x11
    lbz	r0, -0x794c(r2)
    li	r20, 1
    stw	r3, 0x10(r1)
    li	r19, 0
    stb	r0, 0x14(r1)
    b       _80084308
_800842e0:
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r15, r15, 1
    addi	r20, r20, 1
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
_80084308:
    cmpwi	r20, 4
    bc      4, 0, _80084340
    lbz	r0, 0(r15)
    cmpwi	r4, -1
    extsb	r5, r0
    bc      4, 2, _80084328
    li	r0, -1
    b       _80084338
_80084328:
    lis     r3, lbl_8015B300@ha
    clrlwi	r0, r4, 0x18
    addi	r3, r3, lbl_8015B300@l
    lbzx	r0, r3, r0
_80084338:
    cmpw	r5, r0
    bc      12, 2, _800842e0
_80084340:
    cmpwi	r20, 3
    bc      12, 2, _80084350
    cmpwi	r20, 4
    bc      4, 2, _800843fc
_80084350:
    cmpwi	r20, 4
    bc      4, 2, _800843bc
    lis     r3, lbl_8015B100@ha
    addi	r15, r3, lbl_8015B100@l
    b       _80084388
_80084364:
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r19, r19, 1
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
_80084388:
    cmpwi	r19, 0x20
    bc      4, 0, _800843a8
    clrlwi	r0, r4, 0x18
    lbzx	r3, r15, r0
    rlwinm.	r0, r3, 0, 0x1b, 0x1b
    bc      4, 2, _80084364
    rlwinm.	r0, r3, 0, 0x18, 0x19
    bc      4, 2, _80084364
_800843a8:
    cmpwi	r4, 0x29
    bc      12, 2, _800843b8
    li	r15, 0x1000
    b       _80084c54
_800843b8:
    addi	r19, r19, 1
_800843bc:
    cmpwi	r14, 0
    bc      12, 2, _800843d4
    lis	r3, -0x7fe6
    lfs	f0, 0x6648(r3)
    fneg	f1, f0
    b       _800843dc
_800843d4:
    lis	r3, -0x7fe6
    lfs	f1, 0x6648(r3)
_800843dc:
    lwz	r0, 0x5c(r1)
    add	r3, r20, r19
    stfd	f1, 0x18(r1)
    add	r0, r3, r0
    lwz	r3, 0xc(r1)
    add	r0, r29, r0
    stw	r0, 0(r3)
    b       _80084f08
_800843fc:
    li	r15, 0x1000
    b       _80084c54
_80084404:
    cmpw	r4, r21
    bc      4, 2, _80084434
    mr	r12, r16
    mr	r3, r17
    li	r15, 0x10
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_80084434:
    lis     r3, lbl_8015B100@ha
    clrlwi	r0, r4, 0x18
    addi	r3, r3, lbl_8015B100@l
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    bc      4, 2, _80084454
    li	r15, 0x1000
    b       _80084c54
_80084454:
    cmpwi	r4, 0x30
    bc      4, 2, _800844bc
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    cmpwi	r3, -1
    mr	r4, r3
    bc      4, 2, _8008448c
    li	r0, -1
    b       _8008449c
_8008448c:
    lis     r5, lbl_8015B300@ha
    clrlwi	r0, r3, 0x18
    addi	r3, r5, lbl_8015B300@l
    lbzx	r0, r3, r0
_8008449c:
    cmpwi	r0, 0x58
    bc      4, 2, _800844b4
    lis	r3, 1
    li	r31, 1
    addi	r15, r3, -0x8000
    b       _80084c54
_800844b4:
    li	r15, 4
    b       _80084c54
_800844bc:
    li	r15, 8
    b       _80084c54
_800844c4:
    cmpwi	r4, 0x30
    bc      4, 2, _800844f0
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_800844f0:
    li	r15, 8
    b       _80084c54
_800844f8:
    lis     r3, lbl_8015B100@ha
    clrlwi	r0, r4, 0x18
    addi	r3, r3, lbl_8015B100@l
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    bc      4, 2, _80084548
    cmpw	r4, r21
    bc      4, 2, _80084540
    mr	r12, r16
    mr	r3, r17
    li	r15, 0x20
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_80084540:
    li	r15, 0x40
    b       _80084c54
_80084548:
    lbz	r5, 0x30(r1)
    cmplwi	r5, 0x14
    bc      4, 0, _8008456c
    addi	r0, r5, 1
    addi	r3, r1, 0x2c
    stb	r0, 0x30(r1)
    addi	r0, r5, 5
    stbx	r4, r3, r0
    b       _80084570
_8008456c:
    addi	r27, r27, 1
_80084570:
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_80084594:
    lis     r3, lbl_8015B100@ha
    clrlwi	r0, r4, 0x18
    addi	r3, r3, lbl_8015B100@l
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    bc      4, 2, _800845b4
    li	r15, 0x1000
    b       _80084c54
_800845b4:
    li	r15, 0x20
    b       _80084c54
_800845bc:
    lis     r3, lbl_8015B100@ha
    clrlwi	r0, r4, 0x18
    addi	r3, r3, lbl_8015B100@l
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    bc      4, 2, _800845dc
    li	r15, 0x40
    b       _80084c54
_800845dc:
    lbz	r0, 0x30(r1)
    cmplwi	r0, 0x14
    bc      4, 0, _80084614
    cmpwi	r4, 0x30
    bc      4, 2, _800845f8
    cmplwi	r0, 0
    bc      12, 2, _80084610
_800845f8:
    lbz	r6, 0x30(r1)
    addi	r3, r1, 0x2c
    addi	r5, r6, 1
    addi	r0, r6, 5
    stb	r5, 0x30(r1)
    stbx	r4, r3, r0
_80084610:
    addi	r27, r27, -1
_80084614:
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_80084638:
    cmpwi	r4, -1
    bc      4, 2, _80084648
    li	r0, -1
    b       _80084658
_80084648:
    lis     r3, lbl_8015B300@ha
    clrlwi	r0, r4, 0x18
    addi	r3, r3, lbl_8015B300@l
    lbzx	r0, r3, r0
_80084658:
    cmpwi	r0, 0x45
    bc      4, 2, _80084688
    mr	r12, r16
    mr	r3, r17
    li	r15, 0x80
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_80084688:
    li	r15, 0x800
    b       _80084c54
_80084690:
    cmpwi	r4, 0x2b
    bc      4, 2, _800846bc
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _800846ec
_800846bc:
    cmpwi	r4, 0x2d
    bc      4, 2, _800846ec
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    li	r0, 1
    mr	r4, r3
    stw	r0, 0x60(r1)
_800846ec:
    li	r15, 0x100
    b       _80084c54
_800846f4:
    lis     r3, lbl_8015B100@ha
    clrlwi	r0, r4, 0x18
    addi	r3, r3, lbl_8015B100@l
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    bc      4, 2, _80084714
    li	r15, 0x1000
    b       _80084c54
_80084714:
    cmpwi	r4, 0x30
    bc      4, 2, _80084744
    mr	r12, r16
    mr	r3, r17
    li	r15, 0x200
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_80084744:
    li	r15, 0x400
    b       _80084c54
_8008474c:
    cmpwi	r4, 0x30
    bc      4, 2, _80084778
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_80084778:
    li	r15, 0x400
    b       _80084c54
_80084780:
    lis     r3, lbl_8015B100@ha
    clrlwi	r0, r4, 0x18
    addi	r3, r3, lbl_8015B100@l
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    bc      4, 2, _800847a0
    li	r15, 0x800
    b       _80084c54
_800847a0:
    mulli	r0, r28, 0xa
    add	r28, r4, r0
    addi	r28, r28, -0x30
    cmpwi	r28, 0x7fff
    bc      4, 1, _800847bc
    li	r0, 1
    stw	r0, 0(r18)
_800847bc:
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_800847e0:
    cmpwi	r31, 0x10
    bc      12, 2, _80084ad8
    bc      4, 0, _8008481c
    cmpwi	r31, 4
    bc      12, 2, _800848c4
    bc      4, 0, _80084810
    cmpwi	r31, 2
    bc      12, 2, _80084890
    bc      4, 0, _80084c54
    cmpwi	r31, 1
    bc      4, 0, _80084840
    b       _80084c54
_80084810:
    cmpwi	r31, 8
    bc      12, 2, _800849e8
    b       _80084c54
_8008481c:
    cmpwi	r31, 0x40
    bc      12, 2, _80084b94
    bc      4, 0, _80084834
    cmpwi	r31, 0x20
    bc      12, 2, _80084b34
    b       _80084c54
_80084834:
    cmpwi	r31, 0x100
    bc      12, 2, _80084bf0
    b       _80084c54
_80084840:
    li	r0, 0
    mr	r12, r16
    mr	r3, r17
    stb	r0, 0x18(r1)
    li	r25, 2
    li	r31, 2
    stb	r0, 0x19(r1)
    li	r4, 0
    li	r5, 0
    stb	r0, 0x1a(r1)
    stb	r0, 0x1b(r1)
    stb	r0, 0x1c(r1)
    stb	r0, 0x1d(r1)
    stb	r0, 0x1e(r1)
    stb	r0, 0x1f(r1)
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_80084890:
    cmpwi	r4, 0x30
    bc      4, 2, _800848bc
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_800848bc:
    li	r31, 4
    b       _80084c54
_800848c4:
    lis     r3, lbl_8015B100@ha
    clrlwi	r5, r4, 0x18
    addi	r3, r3, lbl_8015B100@l
    lbzx	r0, r3, r5
    rlwinm.	r0, r0, 0, 0x1a, 0x1a
    bc      4, 2, _80084914
    cmpw	r4, r21
    bc      4, 2, _8008490c
    mr	r12, r16
    mr	r3, r17
    li	r31, 8
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_8008490c:
    li	r31, 0x10
    b       _80084c54
_80084914:
    cmpwi	r25, 0x11
    bc      4, 0, _800849c4
    srwi	r0, r25, 0x1f
    cmpwi	r4, -1
    add	r0, r0, r25
    addi	r23, r23, 1
    srawi	r0, r0, 1
    lbzx	r6, r26, r0
    bc      4, 2, _80084940
    li	r3, -1
    b       _8008494c
_80084940:
    lis     r3, lbl_8015B300@ha
    addi	r3, r3, lbl_8015B300@l
    lbzx	r3, r3, r5
_8008494c:
    cmpwi	r3, 0x41
    bc      12, 0, _8008495c
    addi	r5, r3, -0x37
    b       _80084960
_8008495c:
    addi	r5, r3, -0x30
_80084960:
    srwi	r4, r25, 0x1f
    clrlwi	r0, r25, 0x1f
    xor	r3, r0, r4
    rlwinm	r0, r5, 4, 0x14, 0x1b
    subf.	r3, r4, r3
    clrlwi	r3, r5, 0x18
    or	r0, r6, r0
    clrlwi	r5, r0, 0x18
    bc      12, 2, _8008498c
    or	r0, r6, r3
    clrlwi	r5, r0, 0x18
_8008498c:
    srwi	r0, r25, 0x1f
    mr	r12, r16
    add	r0, r0, r25
    mr	r3, r17
    srawi	r0, r0, 1
    li	r4, 0
    stbx	r5, r26, r0
    li	r5, 0
    mtctr	r12
    addi	r25, r25, 1
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_800849c4:
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_800849e8:
    lis     r3, lbl_8015B100@ha
    clrlwi	r5, r4, 0x18
    addi	r3, r3, lbl_8015B100@l
    lbzx	r0, r3, r5
    rlwinm.	r0, r0, 0, 0x1a, 0x1a
    bc      4, 2, _80084a08
    li	r31, 0x10
    b       _80084c54
_80084a08:
    cmpwi	r25, 0x11
    bc      4, 0, _80084ab4
    srwi	r0, r25, 0x1f
    cmpwi	r4, -1
    add	r0, r0, r25
    srawi	r0, r0, 1
    lbzx	r6, r26, r0
    bc      4, 2, _80084a30
    li	r3, -1
    b       _80084a3c
_80084a30:
    lis     r3, lbl_8015B300@ha
    addi	r3, r3, lbl_8015B300@l
    lbzx	r3, r3, r5
_80084a3c:
    cmpwi	r3, 0x41
    bc      12, 0, _80084a4c
    addi	r5, r3, -0x37
    b       _80084a50
_80084a4c:
    addi	r5, r3, -0x30
_80084a50:
    srwi	r4, r25, 0x1f
    clrlwi	r0, r25, 0x1f
    xor	r3, r0, r4
    rlwinm	r0, r5, 4, 0x14, 0x1b
    subf.	r3, r4, r3
    clrlwi	r3, r5, 0x18
    or	r0, r6, r0
    clrlwi	r5, r0, 0x18
    bc      12, 2, _80084a7c
    or	r0, r6, r3
    clrlwi	r5, r0, 0x18
_80084a7c:
    srwi	r0, r25, 0x1f
    mr	r12, r16
    add	r0, r0, r25
    mr	r3, r17
    srawi	r0, r0, 1
    li	r4, 0
    stbx	r5, r26, r0
    li	r5, 0
    mtctr	r12
    addi	r25, r25, 1
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_80084ab4:
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_80084ad8:
    cmpwi	r4, -1
    bc      4, 2, _80084ae8
    li	r0, -1
    b       _80084af8
_80084ae8:
    lis     r3, lbl_8015B300@ha
    clrlwi	r0, r4, 0x18
    addi	r3, r3, lbl_8015B300@l
    lbzx	r0, r3, r0
_80084af8:
    cmpwi	r0, 0x50
    bc      4, 2, _80084b2c
    mr	r12, r16
    mr	r3, r17
    li	r31, 0x20
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r24, r24, 1
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_80084b2c:
    li	r15, 0x800
    b       _80084c54
_80084b34:
    cmpwi	r4, 0x2d
    addi	r24, r24, 1
    bc      4, 2, _80084b4c
    li	r0, 1
    stw	r0, 0x58(r1)
    b       _80084b6c
_80084b4c:
    cmpwi	r4, 0x2b
    bc      12, 2, _80084b6c
    mr	r12, r16
    mr	r3, r17
    li	r5, 1
    mtctr	r12
    bctrl
    addi	r24, r24, -1
_80084b6c:
    mr	r12, r16
    mr	r3, r17
    li	r31, 0x40
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_80084b94:
    lis     r3, lbl_8015B100@ha
    clrlwi	r0, r4, 0x18
    addi	r3, r3, lbl_8015B100@l
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    bc      4, 2, _80084bb4
    li	r15, 0x1000
    b       _80084c54
_80084bb4:
    cmpwi	r4, 0x30
    bc      4, 2, _80084be8
    mr	r12, r16
    mr	r3, r17
    li	r31, 0x80
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r24, r24, 1
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
    b       _80084c54
_80084be8:
    li	r31, 0x100
    b       _80084c54
_80084bf0:
    lis     r3, lbl_8015B100@ha
    clrlwi	r0, r4, 0x18
    addi	r3, r3, lbl_8015B100@l
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    bc      4, 2, _80084c10
    li	r15, 0x800
    b       _80084c54
_80084c10:
    mulli	r0, r22, 0xa
    cmpwi	r28, 0x7fff
    add	r3, r4, r0
    addi	r0, r3, -0x30
    extsh	r22, r0
    bc      4, 1, _80084c30
    li	r0, 1
    stw	r0, 0(r18)
_80084c30:
    mr	r12, r16
    mr	r3, r17
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r24, r24, 1
    addi	r30, r30, 1
    bctrl
    mr	r4, r3
_80084c54:
    lwz	r0, 8(r1)
    cmpw	r30, r0
    bc      12, 1, _80084c70
    cmpwi	r4, -1
    bc      12, 2, _80084c70
    rlwinm.	r0, r15, 0, 0x13, 0x14
    bc      12, 2, _80084010
_80084c70:
    andi.	r15, r15, 0xe2c
    bc      4, 2, _80084c88
    lwz	r3, 0xc(r1)
    li	r0, 0
    stw	r0, 0(r3)
    b       _80084c98
_80084c88:
    add	r3, r30, r29
    addi	r0, r3, -1
    lwz	r3, 0xc(r1)
    stw	r0, 0(r3)
_80084c98:
    mr	r12, r16
    mr	r3, r17
    li	r5, 1
    mtctr	r12
    bctrl
    cmpwi	r31, 0
    bc      4, 2, _80084df8
    lwz	r0, 0x60(r1)
    cmpwi	r0, 0
    bc      12, 2, _80084cc4
    neg	r28, r28
_80084cc4:
    lbz	r3, 0x30(r1)
    addi	r0, r1, 0x2c
    addi	r4, r3, 5
    add	r4, r0, r4
    b       _80084cdc
_80084cd8:
    addi	r27, r27, 1
_80084cdc:
    cmpwi	r3, 0
    addi	r3, r3, -1
    bc      12, 2, _80084cf4
    lbzu	r0, -1(r4)
    cmplwi	r0, 0x30
    bc      12, 2, _80084cd8
_80084cf4:
    addi	r0, r3, 1
    clrlwi.	r4, r0, 0x18
    stb	r0, 0x30(r1)
    bc      4, 2, _80084d18
    addi	r0, r4, 1
    addi	r3, r1, 0x31
    stb	r0, 0x30(r1)
    li	r0, 0x30
    stbx	r0, r3, r4
_80084d18:
    add	r28, r28, r27
    cmpwi	r28, -0x8000
    bc      12, 0, _80084d2c
    cmpwi	r28, 0x7fff
    bc      4, 1, _80084d34
_80084d2c:
    li	r0, 1
    stw	r0, 0(r18)
_80084d34:
    lwz	r0, 0(r18)
    cmpwi	r0, 0
    bc      12, 2, _80084d78
    lwz	r0, 0x60(r1)
    cmpwi	r0, 0
    bc      12, 2, _80084d54
    lfd	f1, -0x7948(r2)
    b       _80084f08
_80084d54:
    cmpwi	r14, 0
    bc      12, 2, _80084d6c
    lis	r3, -0x7fe6
    lfd	f0, 0x6660(r3)
    fneg	f1, f0
    b       _80084f08
_80084d6c:
    lis	r3, -0x7fe6
    lfd	f1, 0x6660(r3)
    b       _80084f08
_80084d78:
    sth	r28, 0x2e(r1)
    addi	r3, r1, 0x2c
    bl      __sformatter
    lfd	f0, -0x7948(r2)
    stfd	f1, 0x18(r1)
    fcmpu	cr0, f0, f1
    bc      12, 2, _80084db0
    lis	r3, -0x7fe6
    lfd	f0, 0x6668(r3)
    fcmpo	cr0, f1, f0
    bc      4, 0, _80084db0
    li	r0, 1
    stw	r0, 0(r18)
    b       _80084dd4
_80084db0:
    lis	r3, -0x7fe6
    lfd	f0, 0x6670(r3)
    fcmpo	cr0, f1, f0
    bc      4, 1, _80084dd4
    li	r0, 1
    lis	r3, -0x7fe6
    stw	r0, 0(r18)
    lfd	f0, 0x6660(r3)
    stfd	f0, 0x18(r1)
_80084dd4:
    cmpwi	r14, 0
    bc      12, 2, _80084df0
    cmpwi	r15, 0
    bc      12, 2, _80084df0
    lfd	f0, 0x18(r1)
    fneg	f0, f0
    stfd	f0, 0x18(r1)
_80084df0:
    lfd	f1, 0x18(r1)
    b       _80084f08
_80084df8:
    lfd	f1, 0x18(r1)
    lfd	f0, -0x7940(r2)
    fcmpu	cr0, f1, f0
    bc      12, 2, _80084efc
    lwz	r0, 0x58(r1)
    cmpwi	r0, 0
    bc      12, 2, _80084e40
    neg	r0, r22
    extsh	r22, r0
    b       _80084e40
_80084e20:
    lwz	r4, 0x18(r1)
    addi	r22, r22, 1
    lwz	r3, 0x1c(r1)
    srwi	r0, r4, 1
    rotlwi	r3, r3, 0x1f
    stw	r0, 0x18(r1)
    rlwimi	r3, r4, 0x1f, 0, 0
    stw	r3, 0x1c(r1)
_80084e40:
    lha	r3, 0x18(r1)
    rlwinm	r0, r3, 0, 0x18, 0x1b
    cmpwi	r0, 0x10
    bc      4, 2, _80084e20
    addi	r0, r23, -1
    clrlwi	r4, r3, 0x1c
    slwi	r5, r0, 2
    lwz	r0, 0x5c(r1)
    sth	r4, 0x18(r1)
    add	r3, r0, r25
    add	r0, r22, r5
    extsh	r22, r0
    lfd	f1, -0x7948(r2)
    addi	r0, r3, 1
    addi	r3, r22, 0x3ff
    rlwimi	r4, r3, 4, 0, 0x1b
    add	r0, r0, r24
    sth	r4, 0x18(r1)
    add	r0, r29, r0
    lwz	r3, 0xc(r1)
    lfd	f2, 0x18(r1)
    stw	r0, 0(r3)
    fcmpu	cr0, f1, f2
    bc      12, 2, _80084ec0
    lis	r3, -0x7fe6
    lfd	f0, 0x6668(r3)
    fcmpo	cr0, f2, f0
    bc      4, 0, _80084ec0
    li	r0, 1
    stfd	f1, 0x18(r1)
    stw	r0, 0(r18)
    b       _80084ee4
_80084ec0:
    lis	r3, -0x7fe6
    lfd	f0, 0x6670(r3)
    fcmpo	cr0, f2, f0
    bc      4, 1, _80084ee4
    li	r0, 1
    lis	r3, -0x7fe6
    stw	r0, 0(r18)
    lfd	f0, 0x6660(r3)
    stfd	f0, 0x18(r1)
_80084ee4:
    cmpwi	r14, 0
    bc      12, 2, _80084f04
    lha	r0, 0x18(r1)
    ori	r0, r0, 0x8000
    sth	r0, 0x18(r1)
    b       _80084f04
_80084efc:
    lfd	f0, -0x7948(r2)
    stfd	f0, 0x18(r1)
_80084f04:
    lfd	f1, 0x18(r1)
_80084f08:
    lmw	r14, 0x68(r1)
    lwz	r0, 0xb4(r1)
    mtlr	r0
    addi	r1, r1, 0xb0
    blr
}

asm void atoi(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r4, __StringRead@ha
    stw	r0, 0x24(r1)
    li	r0, 0
    addi	r5, r4, __StringRead@l
    addi	r6, r1, 0x14
    stw	r3, 0x14(r1)
    lis	r3, -0x8000
    addi	r4, r3, -1
    addi	r7, r1, 8
    stw	r0, 0x18(r1)
    addi	r8, r1, 0xc
    addi	r9, r1, 0x10
    li	r3, 0xa
    bl      MSLStrToLong
    lwz	r0, 0x10(r1)
    cmpwi	r0, 0
    bc      4, 2, _80084f98
    lwz	r5, 0xc(r1)
    cmpwi	r5, 0
    bc      4, 2, _80084f84
    lis	r4, -0x8000
    addi	r0, r4, -1
    cmplw	r3, r0
    bc      12, 1, _80084f98
_80084f84:
    cmpwi	r5, 0
    bc      12, 2, _80084fc0
    lis	r0, -0x8000
    cmplw	r3, r0
    bc      4, 1, _80084fc0
_80084f98:
    lwz	r5, 0xc(r1)
    lis	r3, -0x8000
    li	r0, 0x22
    neg	r4, r5
    addi	r3, r3, -1
    or	r4, r4, r5
    stw	r0, -0x75e0(r13)
    srwi	r0, r4, 0x1f
    add	r3, r0, r3
    b       _80084fcc
_80084fc0:
    cmpwi	r5, 0
    bc      12, 2, _80084fcc
    neg	r3, r3
_80084fcc:
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void strtol(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    li	r7, 0
    lis	r6, -0x8000
    stw	r0, 0x34(r1)
    addi	r8, r1, 0xc
    addi	r9, r1, 8
    stw	r31, 0x2c(r1)
    mr	r31, r4
    addi	r4, r6, -1
    addi	r6, r1, 0x14
    stw	r30, 0x28(r1)
    mr	r30, r3
    lis     r3, __StringRead@ha
    addi	r0, r3, __StringRead@l
    stw	r7, 0x18(r1)
    mr	r3, r5
    addi	r7, r1, 0x10
    stw	r30, 0x14(r1)
    mr	r5, r0
    bl      MSLStrToLong
    cmplwi	r31, 0
    bc      12, 2, _80085044
    lwz	r0, 0x10(r1)
    add	r0, r30, r0
    stw	r0, 0(r31)
_80085044:
    lwz	r0, 8(r1)
    cmpwi	r0, 0
    bc      12, 2, _80085060
    li	r0, 0x22
    li	r3, -1
    stw	r0, -0x75e0(r13)
    b       _80085070
_80085060:
    lwz	r0, 0xc(r1)
    cmpwi	r0, 0
    bc      12, 2, _80085070
    neg	r3, r3
_80085070:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr
}

asm void fn_80085088(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    li	r0, 0
    stmw	r16, 0x10(r1)
    or.	r31, r3, r3
    mr	r22, r9
    mr	r17, r8
    mr	r18, r4
    mr	r28, r5
    mr	r27, r6
    mr	r16, r7
    li	r30, 1
    li	r29, 0
    li	r19, 0
    li	r26, 0
    li	r23, 0
    li	r24, 0
    li	r25, 0
    stw	r0, 0(r9)
    stw	r0, 0(r8)
    bc      12, 0, _800850f8
    cmpwi	r31, 1
    bc      12, 2, _800850f8
    cmpwi	r31, 0x24
    bc      12, 1, _800850f8
    cmpwi	r18, 1
    bc      4, 0, _80085100
_800850f8:
    li	r30, 0x40
    b       _80085120
_80085100:
    mr	r12, r28
    mr	r3, r27
    li	r4, 0
    li	r5, 0
    mtctr	r12
    li	r29, 1
    bctrl
    mr	r20, r3
_80085120:
    cmpwi	r31, 0
    bc      12, 2, _80085420
    srawi	r5, r31, 0x1f
    mr	r6, r31
    li	r3, -1
    li	r4, -1
    bl      __div2u
    mr	r24, r4
    mr	r25, r3
    b       _80085420
_80085148:
    cmplwi	r30, 0x10
    bc      12, 1, _80085420
    lis     r3, -0x7fea
    slwi	r0, r30, 2
    addi	r3, r3, -0x48c8
    lwzx	r0, r3, r0
    mtctr	r0
    bctr
    lis     r3, lbl_8015B100@ha
    clrlwi	r0, r20, 0x18
    addi	r3, r3, lbl_8015B100@l
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x1d, 0x1e
    bc      12, 2, _800851a4
    mr	r12, r28
    mr	r3, r27
    li	r4, 0
    li	r5, 0
    mtctr	r12
    bctrl
    mr	r20, r3
    addi	r19, r19, 1
    b       _80085420
_800851a4:
    cmpwi	r20, 0x2b
    bc      4, 2, _800851d0
    mr	r12, r28
    mr	r3, r27
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r29, r29, 1
    bctrl
    mr	r20, r3
    b       _80085200
_800851d0:
    cmpwi	r20, 0x2d
    bc      4, 2, _80085200
    mr	r12, r28
    mr	r3, r27
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r29, r29, 1
    bctrl
    li	r0, 1
    mr	r20, r3
    stw	r0, 0(r17)
_80085200:
    li	r30, 2
    b       _80085420
    cmpwi	r31, 0
    bc      12, 2, _80085218
    cmpwi	r31, 0x10
    bc      4, 2, _80085248
_80085218:
    cmpwi	r20, 0x30
    bc      4, 2, _80085248
    mr	r12, r28
    mr	r3, r27
    li	r30, 4
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r29, r29, 1
    bctrl
    mr	r20, r3
    b       _80085420
_80085248:
    li	r30, 8
    b       _80085420
    cmpwi	r20, 0x58
    bc      12, 2, _80085260
    cmpwi	r20, 0x78
    bc      4, 2, _8008528c
_80085260:
    mr	r12, r28
    mr	r3, r27
    li	r31, 0x10
    li	r30, 8
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r29, r29, 1
    bctrl
    mr	r20, r3
    b       _80085420
_8008528c:
    cmpwi	r31, 0
    bc      4, 2, _80085298
    li	r31, 8
_80085298:
    li	r30, 0x10
    b       _80085420
    cmpwi	r31, 0
    bc      4, 2, _800852ac
    li	r31, 0xa
_800852ac:
    li	r3, 0
    srawi	r0, r3, 0x1f
    xor	r3, r24, r3
    xor	r0, r25, r0
    or.	r0, r3, r0
    bc      4, 2, _800852e0
    srawi	r5, r31, 0x1f
    mr	r6, r31
    li	r3, -1
    li	r4, -1
    bl      __div2u
    mr	r24, r4
    mr	r25, r3
_800852e0:
    lis     r3, lbl_8015B100@ha
    clrlwi	r4, r20, 0x18
    addi	r3, r3, lbl_8015B100@l
    lbzx	r3, r3, r4
    rlwinm.	r0, r3, 0, 0x1b, 0x1b
    bc      12, 2, _80085320
    addi	r20, r20, -0x30
    cmpw	r20, r31
    bc      12, 0, _80085388
    cmpwi	r30, 0x10
    li	r0, 0x40
    bc      4, 2, _80085314
    li	r0, 0x20
_80085314:
    mr	r30, r0
    addi	r20, r20, 0x30
    b       _80085420
_80085320:
    rlwinm.	r0, r3, 0, 0x18, 0x19
    bc      12, 2, _80085350
    cmpwi	r20, -1
    bc      4, 2, _80085338
    li	r3, -1
    b       _80085344
_80085338:
    lis     r3, lbl_8015B300@ha
    addi	r3, r3, lbl_8015B300@l
    lbzx	r3, r3, r4
_80085344:
    addi	r0, r3, -0x37
    cmpw	r0, r31
    bc      12, 0, _80085368
_80085350:
    cmpwi	r30, 0x10
    bc      4, 2, _80085360
    li	r30, 0x20
    b       _80085420
_80085360:
    li	r30, 0x40
    b       _80085420
_80085368:
    cmpwi	r20, -1
    bc      4, 2, _80085378
    li	r3, -1
    b       _80085384
_80085378:
    lis     r3, lbl_8015B300@ha
    addi	r3, r3, lbl_8015B300@l
    lbzx	r3, r3, r4
_80085384:
    addi	r20, r3, -0x37
_80085388:
    subfc	r0, r26, r24
    subfe	r0, r23, r25
    subfe	r0, r21, r21
    neg.	r0, r0
    bc      12, 2, _800853a4
    li	r0, 1
    stw	r0, 0(r22)
_800853a4:
    mulhwu	r3, r26, r31
    srawi	r8, r31, 0x1f
    srawi	r0, r20, 0x1f
    li	r4, -1
    mullw	r5, r23, r31
    add	r6, r3, r5
    mullw	r7, r26, r31
    mullw	r5, r26, r8
    subfc	r3, r7, r4
    add	r5, r6, r5
    subfe	r4, r5, r4
    subfc	r3, r20, r3
    subfe	r3, r0, r4
    subfe	r3, r21, r21
    neg.	r3, r3
    bc      12, 2, _800853ec
    li	r3, 1
    stw	r3, 0(r22)
_800853ec:
    addc	r4, r7, r20
    mr	r12, r28
    adde	r0, r5, r0
    mr	r3, r27
    mr	r26, r4
    li	r30, 0x10
    mr	r23, r0
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r29, r29, 1
    bctrl
    mr	r20, r3
_80085420:
    cmpw	r29, r18
    bc      12, 1, _80085438
    cmpwi	r20, -1
    bc      12, 2, _80085438
    rlwinm.	r0, r30, 0, 0x19, 0x1a
    bc      12, 2, _80085148
_80085438:
    andi.	r0, r30, 0x34
    bc      4, 2, _80085454
    li	r0, 0
    li	r26, 0
    stw	r0, 0(r16)
    srawi	r23, r0, 0x1f
    b       _80085460
_80085454:
    add	r3, r29, r19
    addi	r0, r3, -1
    stw	r0, 0(r16)
_80085460:
    mr	r12, r28
    mr	r3, r27
    mr	r4, r20
    li	r5, 1
    mtctr	r12
    bctrl
    mr	r4, r26
    mr	r3, r23
    lmw	r16, 0x10(r1)
    lwz	r0, 0x54(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr
}

asm void MSLStrToLong(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    li	r0, 0
    stmw	r20, 0x10(r1)
    or.	r29, r3, r3
    mr	r24, r9
    mr	r21, r8
    mr	r22, r4
    mr	r30, r5
    mr	r28, r6
    mr	r20, r7
    li	r25, 1
    li	r31, 0
    li	r23, 0
    li	r27, 0
    li	r26, 0
    stw	r0, 0(r9)
    stw	r0, 0(r8)
    bc      12, 0, _800854fc
    cmpwi	r29, 1
    bc      12, 2, _800854fc
    cmpwi	r29, 0x24
    bc      12, 1, _800854fc
    cmpwi	r22, 1
    bc      4, 0, _80085504
_800854fc:
    li	r25, 0x40
    b       _80085524
_80085504:
    mr	r12, r30
    mr	r3, r28
    li	r4, 0
    li	r5, 0
    mtctr	r12
    li	r31, 1
    bctrl
    mr	r4, r3
_80085524:
    cmpwi	r29, 0
    bc      12, 2, _800857a4
    li	r0, -1
    divwu	r26, r0, r29
    b       _800857a4
_80085538:
    cmplwi	r25, 0x10
    bc      12, 1, _800857a4
    lis     r3, -0x7fea
    slwi	r0, r25, 2
    addi	r3, r3, -0x4884
    lwzx	r0, r3, r0
    mtctr	r0
    bctr
    lis     r3, lbl_8015B100@ha
    clrlwi	r0, r4, 0x18
    addi	r3, r3, lbl_8015B100@l
    lbzx	r0, r3, r0
    rlwinm.	r0, r0, 0, 0x1d, 0x1e
    bc      12, 2, _80085594
    mr	r12, r30
    mr	r3, r28
    li	r4, 0
    li	r5, 0
    mtctr	r12
    bctrl
    mr	r4, r3
    addi	r23, r23, 1
    b       _800857a4
_80085594:
    cmpwi	r4, 0x2b
    bc      4, 2, _800855c0
    mr	r12, r30
    mr	r3, r28
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r31, r31, 1
    bctrl
    mr	r4, r3
    b       _800855f0
_800855c0:
    cmpwi	r4, 0x2d
    bc      4, 2, _800855f0
    mr	r12, r30
    mr	r3, r28
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r31, r31, 1
    bctrl
    li	r0, 1
    mr	r4, r3
    stw	r0, 0(r21)
_800855f0:
    li	r25, 2
    b       _800857a4
    cmpwi	r29, 0
    bc      12, 2, _80085608
    cmpwi	r29, 0x10
    bc      4, 2, _80085638
_80085608:
    cmpwi	r4, 0x30
    bc      4, 2, _80085638
    mr	r12, r30
    mr	r3, r28
    li	r25, 4
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r31, r31, 1
    bctrl
    mr	r4, r3
    b       _800857a4
_80085638:
    li	r25, 8
    b       _800857a4
    cmpwi	r4, 0x58
    bc      12, 2, _80085650
    cmpwi	r4, 0x78
    bc      4, 2, _8008567c
_80085650:
    mr	r12, r30
    mr	r3, r28
    li	r29, 0x10
    li	r25, 8
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r31, r31, 1
    bctrl
    mr	r4, r3
    b       _800857a4
_8008567c:
    cmpwi	r29, 0
    bc      4, 2, _80085688
    li	r29, 8
_80085688:
    li	r25, 0x10
    b       _800857a4
    cmpwi	r29, 0
    bc      4, 2, _8008569c
    li	r29, 0xa
_8008569c:
    cmplwi	r26, 0
    bc      4, 2, _800856ac
    li	r0, -1
    divwu	r26, r0, r29
_800856ac:
    lis     r3, lbl_8015B100@ha
    clrlwi	r5, r4, 0x18
    addi	r3, r3, lbl_8015B100@l
    lbzx	r3, r3, r5
    rlwinm.	r0, r3, 0, 0x1b, 0x1b
    bc      12, 2, _800856ec
    addi	r4, r4, -0x30
    cmpw	r4, r29
    bc      12, 0, _80085754
    cmpwi	r25, 0x10
    li	r0, 0x40
    bc      4, 2, _800856e0
    li	r0, 0x20
_800856e0:
    mr	r25, r0
    addi	r4, r4, 0x30
    b       _800857a4
_800856ec:
    rlwinm.	r0, r3, 0, 0x18, 0x19
    bc      12, 2, _8008571c
    cmpwi	r4, -1
    bc      4, 2, _80085704
    li	r3, -1
    b       _80085710
_80085704:
    lis     r3, lbl_8015B300@ha
    addi	r3, r3, lbl_8015B300@l
    lbzx	r3, r3, r5
_80085710:
    addi	r0, r3, -0x37
    cmpw	r0, r29
    bc      12, 0, _80085734
_8008571c:
    cmpwi	r25, 0x10
    bc      4, 2, _8008572c
    li	r25, 0x20
    b       _800857a4
_8008572c:
    li	r25, 0x40
    b       _800857a4
_80085734:
    cmpwi	r4, -1
    bc      4, 2, _80085744
    li	r3, -1
    b       _80085750
_80085744:
    lis     r3, lbl_8015B300@ha
    addi	r3, r3, lbl_8015B300@l
    lbzx	r3, r3, r5
_80085750:
    addi	r4, r3, -0x37
_80085754:
    cmplw	r27, r26
    bc      4, 1, _80085764
    li	r0, 1
    stw	r0, 0(r24)
_80085764:
    mullw	r27, r27, r29
    subfic	r0, r27, -1
    cmplw	r4, r0
    bc      4, 1, _8008577c
    li	r0, 1
    stw	r0, 0(r24)
_8008577c:
    mr	r12, r30
    mr	r3, r28
    add	r27, r27, r4
    li	r25, 0x10
    li	r4, 0
    li	r5, 0
    mtctr	r12
    addi	r31, r31, 1
    bctrl
    mr	r4, r3
_800857a4:
    cmpw	r31, r22
    bc      12, 1, _800857bc
    cmpwi	r4, -1
    bc      12, 2, _800857bc
    rlwinm.	r0, r25, 0, 0x19, 0x1a
    bc      12, 2, _80085538
_800857bc:
    andi.	r0, r25, 0x34
    bc      4, 2, _800857d4
    li	r0, 0
    li	r27, 0
    stw	r0, 0(r20)
    b       _800857e0
_800857d4:
    add	r3, r31, r23
    addi	r0, r3, -1
    stw	r0, 0(r20)
_800857e0:
    mr	r12, r30
    mr	r3, r28
    li	r5, 1
    mtctr	r12
    bctrl
    mr	r3, r27
    lmw	r20, 0x10(r1)
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr
}

asm void fn_8008580C(void)
{
    nofralloc
    li	r3, 0
    blr
}

asm void fn_80085814(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r6
    stw	r30, 0x18(r1)
    mr	r30, r5
    stw	r29, 0x14(r1)
    mr	r29, r4
    stw	r28, 0x10(r1)
    mr	r28, r3
    bl      OSGetConsoleType
    rlwinm.	r0, r3, 0, 2, 2
    bc      4, 2, _800858ac
    lwz	r0, -0x75d8(r13)
    li	r3, 0
    cmpwi	r0, 0
    bc      4, 2, _80085878
    lis	r3, 1
    addi	r3, r3, -0x1f00
    bl      InitializeUART
    cmpwi	r3, 0
    bc      4, 2, _80085878
    li	r0, 1
    stw	r0, -0x75d8(r13)
_80085878:
    cmpwi	r3, 0
    bc      12, 2, _80085888
    li	r3, 1
    b       _800858c4
_80085888:
    lwz	r4, 0(r30)
    mr	r3, r29
    bl      WriteUARTN
    cmpwi	r3, 0
    bc      12, 2, _800858ac
    li	r0, 0
    li	r3, 1
    stw	r0, 0(r30)
    b       _800858c4
_800858ac:
    mr	r3, r28
    mr	r4, r29
    mr	r5, r30
    mr	r6, r31
    bl      TRKWriteFileChecked
    li	r3, 0
_800858c4:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fwide(void)
{
    nofralloc
    cmplwi	r3, 0
    bc      12, 2, _800858f8
    lhz	r0, 4(r3)
    rlwinm.	r0, r0, 0x1a, 0x1d, 0x1f
    bc      4, 2, _80085900
_800858f8:
    li	r3, 0
    blr
_80085900:
    lbz	r5, 5(r3)
    rlwinm	r0, r5, 0x1c, 0x1e, 0x1f
    cmpwi	r0, 1
    bc      12, 2, _80085964
    bc      4, 0, _80085920
    cmpwi	r0, 0
    bc      4, 0, _8008592c
    blr
_80085920:
    cmpwi	r0, 3
    bgelr	
    b       _8008595c
_8008592c:
    cmpwi	r4, 0
    bc      4, 1, _80085944
    li	r0, 2
    rlwimi	r5, r0, 4, 0x1a, 0x1b
    stb	r5, 5(r3)
    b       _80085954
_80085944:
    bc      4, 0, _80085954
    li	r0, 1
    rlwimi	r5, r0, 4, 0x1a, 0x1b
    stb	r5, 5(r3)
_80085954:
    mr	r3, r4
    blr
_8008595c:
    li	r3, 1
    blr
_80085964:
    li	r3, -1
    blr
}

asm void fn_8008596C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    lis	r0, 0x3ff0
    stfd	f1, 8(r1)
    lwz	r4, 8(r1)
    clrlwi	r3, r4, 1
    cmpw	r3, r0
    bc      12, 0, _800859bc
    lwz	r0, 0xc(r1)
    addis	r3, r3, -0x3ff0
    or.	r0, r3, r0
    bc      4, 2, _800859b0
    cmpwi	r4, 0
    bc      4, 1, _800859a8
    lfd	f1, -0x7938(r2)
    b       _80085c74
_800859a8:
    lfd	f1, -0x7930(r2)
    b       _80085c74
_800859b0:
    lis	r3, -0x7fe6
    lfs	f1, 0x6648(r3)
    b       _80085c74
_800859bc:
    lis	r0, 0x3fe0
    cmpw	r3, r0
    bc      4, 0, _80085a50
    lis	r0, 0x3c60
    cmpw	r3, r0
    bc      12, 1, _800859dc
    lfd	f1, -0x7928(r2)
    b       _80085c74
_800859dc:
    fmul	f10, f1, f1
    lfd	f2, -0x78f0(r2)
    lfd	f0, -0x78f8(r2)
    lfd	f3, -0x7900(r2)
    lfd	f8, -0x7908(r2)
    fmadd	f4, f2, f10, f0
    lfd	f2, -0x78c8(r2)
    lfd	f0, -0x78d0(r2)
    lfd	f7, -0x7910(r2)
    fmadd	f9, f10, f4, f3
    lfd	f4, -0x78d8(r2)
    lfd	f6, -0x7918(r2)
    fmadd	f5, f2, f10, f0
    lfd	f3, -0x78e0(r2)
    lfd	f2, -0x78e8(r2)
    fmadd	f8, f10, f9, f8
    lfd	f0, -0x7920(r2)
    lfd	f9, -0x7928(r2)
    fmadd	f4, f10, f5, f4
    fmadd	f5, f10, f8, f7
    fmadd	f3, f10, f4, f3
    fmadd	f4, f10, f5, f6
    fmadd	f2, f10, f3, f2
    fmul	f3, f10, f4
    fdiv	f2, f3, f2
    fnmsub	f0, f1, f2, f0
    fsub	f0, f1, f0
    fsub	f1, f9, f0
    b       _80085c74
_80085a50:
    cmpwi	r4, 0
    bc      4, 0, _80085b5c
    lfd	f10, -0x78e8(r2)
    lfd	f0, -0x78c0(r2)
    fadd	f1, f10, f1
    lfd	f5, -0x78f0(r2)
    lfd	f4, -0x78f8(r2)
    lfd	f8, -0x7900(r2)
    fmul	f1, f0, f1
    lfd	f11, -0x7938(r2)
    lfd	f7, -0x7908(r2)
    lfd	f3, -0x78c8(r2)
    lfd	f2, -0x78d0(r2)
    fmadd	f9, f5, f1, f4
    lfd	f6, -0x7910(r2)
    fmadd	f4, f3, f1, f2
    lfd	f3, -0x78d8(r2)
    lfd	f5, -0x7918(r2)
    fmadd	f8, f1, f9, f8
    lfd	f2, -0x78e0(r2)
    fmadd	f3, f1, f4, f3
    fmadd	f4, f1, f8, f7
    fmadd	f2, f1, f3, f2
    fmadd	f3, f1, f4, f6
    fmadd	f6, f1, f2, f10
    fmadd	f2, f1, f3, f5
    fcmpo	cr0, f1, f11
    fmul	f5, f1, f2
    bc      4, 1, _80085b14
    frsqrte	f3, f1
    lfd	f4, -0x78b8(r2)
    fmul	f2, f3, f3
    fmul	f3, f0, f3
    fnmsub	f2, f1, f2, f4
    fmul	f3, f3, f2
    fmul	f2, f3, f3
    fmul	f3, f0, f3
    fnmsub	f2, f1, f2, f4
    fmul	f3, f3, f2
    fmul	f2, f3, f3
    fmul	f3, f0, f3
    fnmsub	f2, f1, f2, f4
    fmul	f3, f3, f2
    fmul	f2, f3, f3
    fmul	f3, f0, f3
    fnmsub	f0, f1, f2, f4
    fmul	f0, f3, f0
    fmul	f11, f1, f0
    b       _80085b3c
_80085b14:
    fcmpu	cr0, f11, f1
    bc      4, 2, _80085b20
    b       _80085b3c
_80085b20:
    fcmpu	cr0, f1, f11
    bc      12, 2, _80085b34
    lis	r3, -0x7fe6
    lfs	f11, 0x6648(r3)
    b       _80085b3c
_80085b34:
    lis	r3, -0x7fe6
    lfs	f11, 0x664c(r3)
_80085b3c:
    fdiv	f2, f5, f6
    lfd	f1, -0x7920(r2)
    lfd	f3, -0x78b0(r2)
    lfd	f0, -0x7930(r2)
    fmsub	f1, f2, f11, f1
    fadd	f1, f11, f1
    fnmsub	f1, f3, f1, f0
    b       _80085c74
_80085b5c:
    lfd	f0, -0x78e8(r2)
    lfd	f4, -0x78c0(r2)
    fsub	f0, f0, f1
    lfd	f9, -0x7938(r2)
    fmul	f0, f4, f0
    fcmpo	cr0, f0, f9
    bc      4, 1, _80085bc8
    frsqrte	f2, f0
    lfd	f3, -0x78b8(r2)
    fmul	f1, f2, f2
    fmul	f2, f4, f2
    fnmsub	f1, f0, f1, f3
    fmul	f2, f2, f1
    fmul	f1, f2, f2
    fmul	f2, f4, f2
    fnmsub	f1, f0, f1, f3
    fmul	f2, f2, f1
    fmul	f1, f2, f2
    fmul	f2, f4, f2
    fnmsub	f1, f0, f1, f3
    fmul	f2, f2, f1
    fmul	f1, f2, f2
    fmul	f2, f4, f2
    fnmsub	f1, f0, f1, f3
    fmul	f1, f2, f1
    fmul	f9, f0, f1
    b       _80085bf0
_80085bc8:
    fcmpu	cr0, f9, f0
    bc      4, 2, _80085bd4
    b       _80085bf0
_80085bd4:
    fcmpu	cr0, f0, f9
    bc      12, 2, _80085be8
    lis	r3, -0x7fe6
    lfs	f9, 0x6648(r3)
    b       _80085bf0
_80085be8:
    lis	r3, -0x7fe6
    lfs	f9, 0x664c(r3)
_80085bf0:
    lfd	f2, -0x78f0(r2)
    li	r0, 0
    lfd	f1, -0x78f8(r2)
    stfd	f9, 0x10(r1)
    fmadd	f3, f2, f0, f1
    lfd	f2, -0x7900(r2)
    stw	r0, 0x14(r1)
    lfd	f1, -0x7908(r2)
    lfd	f10, 0x10(r1)
    fmadd	f5, f0, f3, f2
    lfd	f4, -0x78c8(r2)
    lfd	f2, -0x78d0(r2)
    fnmsub	f3, f10, f10, f0
    lfd	f7, -0x7910(r2)
    fmadd	f8, f0, f5, f1
    lfd	f1, -0x78d8(r2)
    fmadd	f5, f4, f0, f2
    lfd	f6, -0x7918(r2)
    lfd	f2, -0x78e0(r2)
    fmadd	f7, f0, f8, f7
    lfd	f4, -0x78e8(r2)
    fmadd	f5, f0, f5, f1
    lfd	f1, -0x78b0(r2)
    fmadd	f6, f0, f7, f6
    fmadd	f5, f0, f5, f2
    fadd	f2, f9, f10
    fmul	f6, f0, f6
    fmadd	f4, f0, f5, f4
    fdiv	f0, f3, f2
    fdiv	f2, f6, f4
    fmadd	f0, f2, f9, f0
    fadd	f0, f10, f0
    fmul	f1, f1, f0
_80085c74:
    addi	r1, r1, 0x20
    blr
}

asm void fn_80085C7C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    lis	r0, 0x10
    li	r8, 0
    stfd	f1, 8(r1)
    lwz	r3, 8(r1)
    lwz	r4, 0xc(r1)
    cmpw	r3, r0
    bc      4, 0, _80085cec
    clrlwi	r0, r3, 1
    or.	r0, r0, r4
    bc      4, 2, _80085cb8
    lfd	f1, -0x78a8(r2)
    lfd	f0, -0x75d0(r13)
    fdiv	f1, f1, f0
    b       _80085ef0
_80085cb8:
    cmpwi	r3, 0
    bc      4, 0, _80085cd8
    fsub	f1, f1, f1
    lfd	f0, -0x75d0(r13)
    li	r0, 0x21
    stw	r0, -0x75e0(r13)
    fdiv	f1, f1, f0
    b       _80085ef0
_80085cd8:
    lfd	f0, -0x78a0(r2)
    li	r8, -0x36
    fmul	f0, f1, f0
    stfd	f0, 8(r1)
    lwz	r3, 8(r1)
_80085cec:
    lis	r0, 0x7ff0
    cmpw	r3, r0
    bc      12, 0, _80085d04
    lfd	f0, 8(r1)
    fadd	f1, f0, f0
    b       _80085ef0
_80085d04:
    clrlwi	r6, r3, 0xc
    srawi	r4, r3, 0x14
    addis	r3, r6, 9
    lfd	f0, -0x7898(r2)
    addi	r5, r3, 0x5f64
    add	r8, r4, r8
    rlwinm	r3, r5, 0, 0xb, 0xb
    addi	r0, r6, 2
    xoris	r3, r3, 0x3ff0
    addi	r8, r8, -0x3ff
    or	r4, r6, r3
    clrlwi	r0, r0, 0xc
    stw	r4, 8(r1)
    rlwinm	r3, r5, 0xc, 0x1f, 0x1f
    cmpwi	r0, 3
    lfd	f1, 8(r1)
    add	r8, r8, r3
    fsub	f0, f1, f0
    bc      4, 0, _80085df0
    lfd	f1, -0x75d0(r13)
    fcmpu	cr0, f0, f1
    bc      4, 2, _80085d98
    cmpwi	r8, 0
    bc      4, 2, _80085d68
    b       _80085ef0
_80085d68:
    xoris	r3, r8, 0x8000
    lis	r0, 0x4330
    stw	r3, 0x14(r1)
    lfd	f3, -0x7830(r2)
    stw	r0, 0x10(r1)
    lfd	f0, -0x7888(r2)
    lfd	f2, 0x10(r1)
    lfd	f1, -0x7890(r2)
    fsub	f2, f2, f3
    fmul	f0, f0, f2
    fmadd	f1, f1, f2, f0
    b       _80085ef0
_80085d98:
    lfd	f3, -0x7878(r2)
    fmul	f1, f0, f0
    lfd	f2, -0x7880(r2)
    cmpwi	r8, 0
    fnmsub	f2, f3, f0, f2
    fmul	f5, f2, f1
    bc      4, 2, _80085dbc
    fsub	f1, f0, f5
    b       _80085ef0
_80085dbc:
    xoris	r3, r8, 0x8000
    lis	r0, 0x4330
    stw	r3, 0x14(r1)
    lfd	f4, -0x7830(r2)
    stw	r0, 0x10(r1)
    lfd	f1, -0x7888(r2)
    lfd	f3, 0x10(r1)
    lfd	f2, -0x7890(r2)
    fsub	f3, f3, f4
    fnmsub	f1, f1, f3, f5
    fsub	f0, f1, f0
    fmsub	f1, f2, f3, f0
    b       _80085ef0
_80085df0:
    lfd	f1, -0x7870(r2)
    xoris	r5, r8, 0x8000
    lis	r4, 0x4330
    lis	r3, 7
    fadd	f1, f1, f0
    addis	r7, r6, -6
    addi	r0, r3, -0x47af
    lfd	f8, -0x7850(r2)
    lfd	f7, -0x7858(r2)
    subf	r0, r6, r0
    fdiv	f1, f0, f1
    addi	r7, r7, -0x147a
    lfd	f6, -0x7860(r2)
    or.	r7, r7, r0
    lfd	f4, -0x7838(r2)
    lfd	f3, -0x7840(r2)
    fmul	f11, f1, f1
    lfd	f5, -0x7868(r2)
    lfd	f2, -0x7848(r2)
    stw	r5, 0x14(r1)
    lfd	f10, -0x7830(r2)
    fmul	f12, f11, f11
    stw	r4, 0x10(r1)
    lfd	f9, 0x10(r1)
    fmadd	f7, f8, f12, f7
    fmadd	f3, f4, f12, f3
    fmadd	f4, f12, f7, f6
    fmadd	f2, f12, f3, f2
    fmadd	f3, f12, f4, f5
    fmul	f2, f12, f2
    fmul	f3, f11, f3
    fsub	f5, f9, f10
    fadd	f3, f3, f2
    bc      4, 1, _80085ec0
    lfd	f2, -0x7880(r2)
    cmpwi	r8, 0
    fmul	f2, f2, f0
    fmul	f6, f2, f0
    bc      4, 2, _80085e9c
    fadd	f2, f6, f3
    fnmsub	f1, f1, f2, f6
    fsub	f1, f0, f1
    b       _80085ef0
_80085e9c:
    lfd	f2, -0x7888(r2)
    fadd	f3, f6, f3
    lfd	f4, -0x7890(r2)
    fmul	f2, f2, f5
    fmadd	f1, f1, f3, f2
    fsub	f1, f6, f1
    fsub	f0, f1, f0
    fmsub	f1, f4, f5, f0
    b       _80085ef0
_80085ec0:
    cmpwi	r8, 0
    bc      4, 2, _80085ed4
    fsub	f2, f0, f3
    fnmsub	f1, f1, f2, f0
    b       _80085ef0
_80085ed4:
    lfd	f2, -0x7888(r2)
    fsub	f3, f0, f3
    lfd	f4, -0x7890(r2)
    fmul	f2, f2, f5
    fmsub	f1, f1, f3, f2
    fsub	f0, f1, f0
    fmsub	f1, f4, f5, f0
_80085ef0:
    addi	r1, r1, 0x20
    blr
}

asm void __msl_exp(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    li	r4, 0
    stfd	f1, 8(r1)
    lwz	r5, 8(r1)
    stw	r0, 0x24(r1)
    lis	r0, 0x10
    cmpw	r5, r0
    lwz	r3, 0xc(r1)
    stfd	f31, 0x18(r1)
    bc      4, 0, _80085f7c
    clrlwi	r0, r5, 1
    or.	r0, r0, r3
    bc      4, 2, _80085f48
    lfd	f1, -0x7828(r2)
    li	r0, 0x21
    lfd	f0, -0x75c8(r13)
    stw	r0, -0x75e0(r13)
    fdiv	f1, f1, f0
    b       _80085ff4
_80085f48:
    cmpwi	r5, 0
    bc      4, 0, _80085f68
    fsub	f1, f1, f1
    lfd	f0, -0x75c8(r13)
    li	r0, 0x21
    stw	r0, -0x75e0(r13)
    fdiv	f1, f1, f0
    b       _80085ff4
_80085f68:
    lfd	f0, -0x7820(r2)
    li	r4, -0x36
    fmul	f0, f1, f0
    stfd	f0, 8(r1)
    lwz	r5, 8(r1)
_80085f7c:
    lis	r0, 0x7ff0
    cmpw	r5, r0
    bc      12, 0, _80085f94
    lfd	f0, 8(r1)
    fadd	f1, f0, f0
    b       _80085ff4
_80085f94:
    srawi	r3, r5, 0x14
    lis	r0, 0x4330
    add	r4, r3, r4
    stw	r0, 0x10(r1)
    addi	r4, r4, -0x3ff
    lfd	f1, -0x7800(r2)
    srwi	r3, r4, 0x1f
    add	r0, r4, r3
    xoris	r0, r0, 0x8000
    subfic	r3, r3, 0x3ff
    stw	r0, 0x14(r1)
    slwi	r0, r3, 0x14
    rlwimi	r0, r5, 0, 0xc, 0x1f
    lfd	f0, 0x10(r1)
    stw	r0, 8(r1)
    fsub	f31, f0, f1
    lfd	f1, 8(r1)
    bl      fn_80085C7C
    lfd	f0, -0x7810(r2)
    lfd	f2, -0x7818(r2)
    fmul	f1, f0, f1
    lfd	f0, -0x7808(r2)
    fmadd	f1, f2, f31, f1
    fmadd	f1, f0, f31, f1
_80085ff4:
    lwz	r0, 0x24(r1)
    lfd	f31, 0x18(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_80086008(void)
{
    nofralloc
    stwu	r1, -0xb0(r1)
    mflr	r0
    stw	r0, 0xb4(r1)
    stfd	f31, 0xa0(r1)
    psq_st	f31, 0xa8(r1), 0, 0
    stfd	f30, 0x90(r1)
    psq_st	f30, 0x98(r1), 0, 0
    stfd	f29, 0x80(r1)
    psq_st	f29, 0x88(r1), 0, 0
    stfd	f28, 0x70(r1)
    psq_st	f28, 0x78(r1), 0, 0
    stfd	f27, 0x60(r1)
    psq_st	f27, 0x68(r1), 0, 0
    stfd	f2, 0x10(r1)
    lis     r3, lbl_800953D8@ha
    addi	r3, r3, lbl_800953D8@l
    lwz	r5, 0x10(r1)
    stfd	f1, 8(r1)
    lwz	r11, 0x14(r1)
    clrlwi	r7, r5, 1
    lwz	r0, 8(r1)
    or.	r4, r7, r11
    lwz	r10, 0xc(r1)
    clrlwi	r6, r0, 1
    bc      4, 2, _80086074
    lfd	f1, -0x77f8(r2)
    b       _80086884
_80086074:
    lis	r4, 0x7ff0
    cmpw	r6, r4
    bc      12, 1, _800860b4
    addis	r4, r6, -0x7ff0
    cmplwi	r4, 0
    bc      4, 2, _80086094
    cmplwi	r10, 0
    bc      4, 2, _800860b4
_80086094:
    lis	r4, 0x7ff0
    cmpw	r7, r4
    bc      12, 1, _800860b4
    addis	r4, r7, -0x7ff0
    cmplwi	r4, 0
    bc      4, 2, _800860c4
    cmplwi	r11, 0
    bc      12, 2, _800860c4
_800860b4:
    lfd	f1, 8(r1)
    lfd	f0, 0x10(r1)
    fadd	f1, f1, f0
    b       _80086884
_800860c4:
    cmpwi	r0, 0
    li	r4, 0
    bc      4, 0, _80086144
    lis	r8, 0x4340
    cmpw	r7, r8
    bc      12, 0, _800860e4
    li	r4, 2
    b       _80086144
_800860e4:
    lis	r8, 0x3ff0
    cmpw	r7, r8
    bc      12, 0, _80086144
    srawi	r8, r7, 0x14
    addi	r8, r8, -0x3ff
    cmpwi	r8, 0x14
    bc      4, 1, _80086120
    subfic	r8, r8, 0x34
    srw	r9, r11, r8
    slw	r8, r9, r8
    cmplw	r11, r8
    bc      4, 2, _80086144
    clrlwi	r4, r9, 0x1f
    subfic	r4, r4, 2
    b       _80086144
_80086120:
    cmplwi	r11, 0
    bc      4, 2, _80086144
    subfic	r8, r8, 0x14
    sraw	r9, r7, r8
    slw	r8, r9, r8
    cmpw	r7, r8
    bc      4, 2, _80086144
    clrlwi	r4, r9, 0x1f
    subfic	r4, r4, 2
_80086144:
    cmplwi	r11, 0
    bc      4, 2, _80086298
    addis	r8, r7, -0x7ff0
    cmplwi	r8, 0
    bc      4, 2, _800861b0
    addis	r0, r6, -0x3ff0
    or.	r0, r0, r10
    bc      4, 2, _80086170
    lfd	f0, 0x10(r1)
    fsub	f1, f0, f0
    b       _80086884
_80086170:
    lis	r0, 0x3ff0
    cmpw	r6, r0
    bc      12, 0, _80086194
    cmpwi	r5, 0
    bc      12, 0, _8008618c
    lfd	f1, 0x10(r1)
    b       _80086884
_8008618c:
    lfd	f1, -0x77f0(r2)
    b       _80086884
_80086194:
    cmpwi	r5, 0
    bc      4, 0, _800861a8
    lfd	f0, 0x10(r1)
    fneg	f1, f0
    b       _80086884
_800861a8:
    lfd	f1, -0x77f0(r2)
    b       _80086884
_800861b0:
    addis	r8, r7, -0x3ff0
    cmplwi	r8, 0
    bc      4, 2, _800861dc
    cmpwi	r5, 0
    bc      4, 0, _800861d4
    lfd	f1, -0x77f8(r2)
    lfd	f0, 8(r1)
    fdiv	f1, f1, f0
    b       _80086884
_800861d4:
    lfd	f1, 8(r1)
    b       _80086884
_800861dc:
    addis	r8, r5, -0x4000
    cmplwi	r8, 0
    bc      4, 2, _800861f4
    lfd	f0, 8(r1)
    fmul	f1, f0, f0
    b       _80086884
_800861f4:
    addis	r8, r5, -0x3fe0
    cmplwi	r8, 0
    bc      4, 2, _80086298
    cmpwi	r0, 0
    bc      12, 0, _80086298
    lfd	f4, 8(r1)
    lfd	f1, -0x77f0(r2)
    fcmpo	cr0, f4, f1
    bc      4, 1, _8008626c
    frsqrte	f1, f4
    lfd	f3, -0x77e8(r2)
    lfd	f2, -0x77e0(r2)
    fmul	f0, f1, f1
    fmul	f1, f3, f1
    fnmsub	f0, f4, f0, f2
    fmul	f1, f1, f0
    fmul	f0, f1, f1
    fmul	f1, f3, f1
    fnmsub	f0, f4, f0, f2
    fmul	f1, f1, f0
    fmul	f0, f1, f1
    fmul	f1, f3, f1
    fnmsub	f0, f4, f0, f2
    fmul	f1, f1, f0
    fmul	f0, f1, f1
    fmul	f1, f3, f1
    fnmsub	f0, f4, f0, f2
    fmul	f0, f1, f0
    fmul	f1, f4, f0
    b       _80086884
_8008626c:
    fcmpu	cr0, f1, f4
    bc      4, 2, _80086278
    b       _80086884
_80086278:
    fcmpu	cr0, f4, f1
    bc      12, 2, _8008628c
    lis	r3, -0x7fe6
    lfs	f1, 0x6648(r3)
    b       _80086884
_8008628c:
    lis	r3, -0x7fe6
    lfs	f1, 0x664c(r3)
    b       _80086884
_80086298:
    lfd	f0, 8(r1)
    cmplwi	r10, 0
    fabs	f1, f0
    stfd	f1, 0x48(r1)
    bc      4, 2, _80086328
    addis	r8, r6, -0x7ff0
    cmplwi	r8, 0
    bc      12, 2, _800862cc
    cmpwi	r6, 0
    bc      12, 2, _800862cc
    addis	r8, r6, -0x3ff0
    cmplwi	r8, 0
    bc      4, 2, _80086328
_800862cc:
    cmpwi	r5, 0
    stfd	f1, 0x50(r1)
    bc      4, 0, _800862e4
    lfd	f0, -0x77f8(r2)
    fdiv	f0, f0, f1
    stfd	f0, 0x50(r1)
_800862e4:
    cmpwi	r0, 0
    bc      4, 0, _80086320
    addis	r0, r6, -0x3ff0
    or.	r0, r0, r4
    bc      4, 2, _8008630c
    lfd	f0, 0x50(r1)
    fsub	f0, f0, f0
    fdiv	f0, f0, f0
    stfd	f0, 0x50(r1)
    b       _80086320
_8008630c:
    cmpwi	r4, 1
    bc      4, 2, _80086320
    lfd	f0, 0x50(r1)
    fneg	f0, f0
    stfd	f0, 0x50(r1)
_80086320:
    lfd	f1, 0x50(r1)
    b       _80086884
_80086328:
    srawi	r8, r0, 0x1f
    addi	r0, r8, 1
    or.	r8, r0, r4
    bc      4, 2, _8008634c
    lis	r3, -0x7fe6
    li	r0, 0x21
    stw	r0, -0x75e0(r13)
    lfs	f1, 0x6648(r3)
    b       _80086884
_8008634c:
    lis	r8, 0x41e0
    cmpw	r7, r8
    bc      4, 1, _80086458
    lis	r3, 0x43f0
    cmpw	r7, r3
    bc      4, 1, _800863ac
    lis	r3, 0x3ff0
    addi	r7, r3, -1
    cmpw	r6, r7
    bc      12, 1, _8008638c
    cmpwi	r5, 0
    bc      4, 0, _80086384
    lfd	f1, -0x77d8(r2)
    b       _80086884
_80086384:
    lfd	f1, -0x77f0(r2)
    b       _80086884
_8008638c:
    cmpw	r6, r3
    bc      12, 0, _800863ac
    cmpwi	r5, 0
    bc      4, 1, _800863a4
    lfd	f1, -0x77d8(r2)
    b       _80086884
_800863a4:
    lfd	f1, -0x77f0(r2)
    b       _80086884
_800863ac:
    lis	r3, 0x3ff0
    addi	r7, r3, -1
    cmpw	r6, r7
    bc      4, 0, _800863d4
    cmpwi	r5, 0
    bc      4, 0, _800863cc
    lfd	f1, -0x77d8(r2)
    b       _80086884
_800863cc:
    lfd	f1, -0x77f0(r2)
    b       _80086884
_800863d4:
    cmpw	r6, r3
    bc      4, 1, _800863f4
    cmpwi	r5, 0
    bc      4, 1, _800863ec
    lfd	f1, -0x77d8(r2)
    b       _80086884
_800863ec:
    lfd	f1, -0x77f0(r2)
    b       _80086884
_800863f4:
    lfd	f2, 8(r1)
    li	r3, 0
    lfd	f0, -0x77f8(r2)
    lfd	f1, -0x77c8(r2)
    fsub	f6, f2, f0
    lfd	f0, -0x77d0(r2)
    lfd	f2, -0x77c0(r2)
    lfd	f3, -0x77e8(r2)
    fnmsub	f4, f1, f6, f0
    lfd	f0, -0x77b0(r2)
    lfd	f1, -0x77b8(r2)
    fmul	f5, f6, f6
    stfd	f6, 0x28(r1)
    fnmsub	f3, f6, f4, f3
    fmul	f2, f2, f6
    fmul	f3, f5, f3
    fmul	f0, f0, f3
    fmsub	f1, f1, f6, f0
    fadd	f0, f2, f1
    stfd	f0, 0x30(r1)
    stw	r3, 0x34(r1)
    lfd	f0, 0x30(r1)
    fsub	f0, f0, f2
    fsub	f0, f1, f0
    b       _80086640
_80086458:
    lis	r5, 0x10
    li	r10, 0
    cmpw	r6, r5
    bc      4, 0, _80086480
    lfd	f1, 0x48(r1)
    li	r10, -0x35
    lfd	f0, -0x77a8(r2)
    fmul	f0, f1, f0
    stfd	f0, 0x48(r1)
    lwz	r6, 0x48(r1)
_80086480:
    lis	r5, 4
    clrlwi	r8, r6, 0xc
    addi	r5, r5, -0x6772
    srawi	r6, r6, 0x14
    cmpw	r8, r5
    oris	r7, r8, 0x3ff0
    add	r10, r6, r10
    addi	r10, r10, -0x3ff
    bc      12, 1, _800864ac
    li	r11, 0
    b       _800864d0
_800864ac:
    lis	r5, 0xc
    addi	r5, r5, -0x4986
    cmpw	r8, r5
    bc      4, 0, _800864c4
    li	r11, 1
    b       _800864d0
_800864c4:
    addis	r7, r7, -0x10
    li	r11, 0
    addi	r10, r10, 1
_800864d0:
    stw	r7, 0x48(r1)
    srawi	r5, r7, 1
    slwi	r9, r11, 3
    addi	r6, r3, 0
    lfd	f30, 0x48(r1)
    oris	r8, r5, 0x2000
    lfdx	f5, r6, r9
    addi	r7, r3, 0x20
    lfd	f1, -0x77f0(r2)
    xoris	r6, r10, 0x8000
    fadd	f0, f30, f5
    lfd	f2, -0x77f8(r2)
    lis	r5, 0x4330
    addi	r10, r3, 0x10
    fsub	f31, f30, f5
    lfd	f4, -0x7778(r2)
    fdiv	f28, f2, f0
    lfd	f0, -0x7780(r2)
    lfd	f3, -0x7788(r2)
    addis	r8, r8, 8
    slwi	r3, r11, 0x12
    stfd	f1, 0x18(r1)
    fmul	f1, f31, f28
    add	r3, r8, r3
    stw	r3, 0x18(r1)
    li	r3, 0
    lfd	f2, -0x7790(r2)
    lfd	f12, 0x18(r1)
    fmul	f27, f1, f1
    stfd	f1, 0x20(r1)
    lfd	f11, -0x7798(r2)
    stw	r3, 0x24(r1)
    fsub	f13, f12, f5
    lfd	f9, -0x77a0(r2)
    fmadd	f4, f4, f27, f0
    lfd	f29, 0x20(r1)
    lfd	f10, -0x77e0(r2)
    fmul	f0, f29, f29
    lfd	f5, -0x7760(r2)
    lfd	f6, -0x7768(r2)
    fmadd	f3, f27, f4, f3
    lfd	f8, -0x7770(r2)
    lfdx	f7, r7, r9
    fnmsub	f31, f29, f12, f31
    stw	r6, 0x5c(r1)
    lfd	f4, -0x76f0(r2)
    fmadd	f12, f27, f3, f2
    stw	r5, 0x58(r1)
    lfdx	f2, r10, r9
    fsub	f30, f30, f13
    lfd	f3, 0x58(r1)
    fmul	f13, f27, f27
    fmadd	f11, f27, f12, f11
    fnmsub	f12, f29, f30, f31
    fmadd	f9, f27, f11, f9
    fmul	f27, f28, f12
    fmul	f12, f13, f9
    fadd	f11, f29, f1
    fadd	f9, f10, f0
    fsub	f3, f3, f4
    fmadd	f12, f27, f11, f12
    stfd	f3, 0x28(r1)
    fadd	f4, f9, f12
    stfd	f4, 0x18(r1)
    stw	r3, 0x1c(r1)
    lfd	f9, 0x18(r1)
    fsub	f4, f9, f10
    fmul	f10, f29, f9
    fsub	f0, f4, f0
    fsub	f0, f12, f0
    fmul	f0, f0, f1
    fmadd	f4, f27, f9, f0
    fadd	f0, f10, f4
    stfd	f0, 0x40(r1)
    stw	r3, 0x44(r1)
    lfd	f1, 0x40(r1)
    fsub	f0, f1, f10
    fmul	f8, f8, f1
    fsub	f0, f4, f0
    fmul	f0, f5, f0
    fmadd	f0, f6, f1, f0
    fadd	f1, f7, f0
    fadd	f0, f8, f1
    fadd	f0, f0, f2
    fadd	f0, f3, f0
    stfd	f0, 0x30(r1)
    stw	r3, 0x34(r1)
    lfd	f0, 0x30(r1)
    fsub	f0, f0, f3
    fsub	f0, f0, f2
    fsub	f0, f0, f8
    fsub	f0, f1, f0
_80086640:
    addi	r3, r4, -1
    lfd	f31, -0x77f8(r2)
    or.	r0, r0, r3
    bc      4, 2, _80086654
    lfd	f31, -0x7758(r2)
_80086654:
    lfd	f1, 0x10(r1)
    li	r3, 0
    lfd	f3, 0x30(r1)
    lis	r0, 0x4090
    stfd	f1, 0x38(r1)
    fmul	f0, f1, f0
    stw	r3, 0x3c(r1)
    lfd	f2, 0x38(r1)
    fsub	f1, f1, f2
    fmul	f2, f2, f3
    fmadd	f12, f3, f1, f0
    stfd	f2, 0x40(r1)
    fadd	f0, f12, f2
    stfd	f0, 0x50(r1)
    lwz	r6, 0x50(r1)
    lwz	r5, 0x54(r1)
    cmpw	r6, r0
    bc      12, 0, _800866dc
    addis	r0, r6, -0x4090
    or.	r0, r0, r5
    bc      12, 2, _800866b8
    lfd	f1, -0x7750(r2)
    fmul	f0, f1, f31
    fmul	f1, f1, f0
    b       _80086884
_800866b8:
    lfd	f1, -0x7748(r2)
    fsub	f0, f0, f2
    fadd	f1, f1, f12
    fcmpo	cr0, f1, f0
    bc      4, 1, _80086730
    lfd	f1, -0x7750(r2)
    fmul	f0, f1, f31
    fmul	f1, f1, f0
    b       _80086884
_800866dc:
    lis	r3, 0x4091
    clrlwi	r4, r6, 1
    addi	r0, r3, -0x3400
    cmpw	r4, r0
    bc      12, 0, _80086730
    addis	r3, r6, 0x3f6f
    addi	r0, r3, 0x3400
    or.	r0, r0, r5
    bc      12, 2, _80086710
    lfd	f1, -0x7740(r2)
    fmul	f0, f1, f31
    fmul	f1, f1, f0
    b       _80086884
_80086710:
    fsub	f0, f0, f2
    fcmpo	cr0, f12, f0
    cror	2, 0, 2
    bc      4, 2, _80086730
    lfd	f1, -0x7740(r2)
    fmul	f0, f1, f31
    fmul	f1, f1, f0
    b       _80086884
_80086730:
    clrlwi	r3, r6, 1
    lis	r0, 0x3fe0
    cmpw	r3, r0
    rlwinm	r4, r6, 0xc, 0x15, 0x1f
    li	r3, 0
    bc      4, 1, _800867a8
    lis	r3, 0x10
    addi	r0, r4, -0x3fe
    sraw	r0, r3, r0
    lfd	f0, -0x77f0(r2)
    add	r7, r6, r0
    addi	r3, r3, -1
    clrlwi	r0, r7, 1
    stfd	f0, 0x28(r1)
    srawi	r4, r0, 0x14
    clrlwi	r0, r7, 0xc
    addi	r5, r4, -0x3ff
    cmpwi	r6, 0
    sraw	r4, r3, r5
    oris	r3, r0, 0x10
    andc	r4, r7, r4
    subfic	r0, r5, 0x14
    stw	r4, 0x28(r1)
    sraw	r3, r3, r0
    bc      4, 0, _80086798
    neg	r3, r3
_80086798:
    lfd	f1, 0x40(r1)
    lfd	f0, 0x28(r1)
    fsub	f0, f1, f0
    stfd	f0, 0x40(r1)
_800867a8:
    lfd	f2, 0x40(r1)
    li	r0, 0
    lfd	f1, -0x7728(r2)
    slwi	r4, r3, 0x14
    fadd	f0, f12, f2
    lfd	f10, -0x7738(r2)
    lfd	f9, -0x7730(r2)
    lfd	f6, -0x7700(r2)
    stfd	f0, 0x28(r1)
    lfd	f5, -0x7708(r2)
    stw	r0, 0x2c(r1)
    lfd	f0, -0x7710(r2)
    lfd	f11, 0x28(r1)
    lfd	f4, -0x7718(r2)
    fsub	f8, f11, f2
    lfd	f3, -0x7720(r2)
    fmul	f7, f1, f11
    lfd	f2, -0x76f8(r2)
    lfd	f1, -0x77f8(r2)
    fsub	f8, f12, f8
    fmul	f10, f10, f11
    fmadd	f11, f9, f8, f7
    fadd	f9, f10, f11
    fmul	f7, f9, f9
    stfd	f9, 0x50(r1)
    fsub	f8, f9, f10
    fmadd	f5, f6, f7, f5
    stfd	f7, 0x28(r1)
    fsub	f6, f11, f8
    fmadd	f5, f7, f5, f0
    fmadd	f0, f9, f6, f6
    fmadd	f4, f7, f5, f4
    fmadd	f3, f7, f4, f3
    fmul	f3, f7, f3
    fsub	f4, f9, f3
    fmul	f3, f9, f4
    stfd	f4, 0x30(r1)
    fsub	f2, f4, f2
    fdiv	f2, f3, f2
    fsub	f0, f2, f0
    fsub	f0, f0, f9
    fsub	f1, f1, f0
    stfd	f1, 0x50(r1)
    lwz	r0, 0x50(r1)
    add	r0, r0, r4
    srawi.	r0, r0, 0x14
    bc      12, 1, _80086870
    bl      __fpclassifyd
    stfd	f1, 0x50(r1)
    b       _8008687c
_80086870:
    lwz	r0, 0x50(r1)
    add	r0, r0, r4
    stw	r0, 0x50(r1)
_8008687c:
    lfd	f0, 0x50(r1)
    fmul	f1, f31, f0
_80086884:
    psq_l	f31, 0xa8(r1), 0, 0
    lfd	f31, 0xa0(r1)
    psq_l	f30, 0x98(r1), 0, 0
    lfd	f30, 0x90(r1)
    psq_l	f29, 0x88(r1), 0, 0
    lfd	f29, 0x80(r1)
    psq_l	f28, 0x78(r1), 0, 0
    lfd	f28, 0x70(r1)
    psq_l	f27, 0x68(r1), 0, 0
    lwz	r0, 0xb4(r1)
    lfd	f27, 0x60(r1)
    mtlr	r0
    addi	r1, r1, 0xb0
    blr
}

asm void fn_800868BC(void)
{
    nofralloc
    stwu	r1, -0x60(r1)
    mflr	r0
    lis	r4, 0x3fe9
    stw	r0, 0x64(r1)
    addi	r0, r4, 0x21fb
    stw	r31, 0x5c(r1)
    stfd	f1, 8(r1)
    lwz	r31, 8(r1)
    stw	r30, 0x58(r1)
    mr	r30, r3
    clrlwi	r6, r31, 1
    cmpw	r6, r0
    bc      12, 1, _80086904
    stfd	f1, 0(r30)
    li	r3, 0
    lfd	f0, -0x76e8(r2)
    stfd	f0, 8(r30)
    b       _80086c44
_80086904:
    lis	r3, 0x4003
    addi	r0, r3, -0x2684
    cmpw	r6, r0
    bc      4, 0, _800869ec
    cmpwi	r31, 0
    bc      4, 1, _80086984
    lfd	f0, -0x76e0(r2)
    addis	r0, r6, -0x3ff9
    cmplwi	r0, 0x21fb
    fsub	f2, f1, f0
    stfd	f2, 0x10(r1)
    bc      12, 2, _80086954
    lfd	f1, -0x76d8(r2)
    fsub	f0, f2, f1
    stfd	f0, 0(r30)
    lfd	f0, 0(r30)
    fsub	f0, f2, f0
    fsub	f0, f0, f1
    stfd	f0, 8(r30)
    b       _8008697c
_80086954:
    lfd	f0, -0x76d0(r2)
    lfd	f1, -0x76c8(r2)
    fsub	f2, f2, f0
    fsub	f0, f2, f1
    stfd	f2, 0x10(r1)
    stfd	f0, 0(r30)
    lfd	f0, 0(r30)
    fsub	f0, f2, f0
    fsub	f0, f0, f1
    stfd	f0, 8(r30)
_8008697c:
    li	r3, 1
    b       _80086c44
_80086984:
    lfd	f0, -0x76e0(r2)
    addis	r0, r6, -0x3ff9
    cmplwi	r0, 0x21fb
    fadd	f2, f0, f1
    stfd	f2, 0x10(r1)
    bc      12, 2, _800869bc
    lfd	f1, -0x76d8(r2)
    fadd	f0, f1, f2
    stfd	f0, 0(r30)
    lfd	f0, 0(r30)
    fsub	f0, f2, f0
    fadd	f0, f1, f0
    stfd	f0, 8(r30)
    b       _800869e4
_800869bc:
    lfd	f0, -0x76d0(r2)
    lfd	f1, -0x76c8(r2)
    fadd	f2, f2, f0
    fadd	f0, f1, f2
    stfd	f2, 0x10(r1)
    stfd	f0, 0(r30)
    lfd	f0, 0(r30)
    fsub	f0, f2, f0
    fadd	f0, f1, f0
    stfd	f0, 8(r30)
_800869e4:
    li	r3, -1
    b       _80086c44
_800869ec:
    lis	r3, 0x4139
    addi	r0, r3, 0x21fb
    cmpw	r6, r0
    bc      12, 1, _80086b34
    fabs	f4, f1
    lis	r0, 0x4330
    lfd	f1, -0x76b8(r2)
    lfd	f0, -0x76c0(r2)
    stw	r0, 0x38(r1)
    fmadd	f2, f1, f4, f0
    lfd	f3, -0x7698(r2)
    lfd	f1, -0x76e0(r2)
    lfd	f0, -0x76d8(r2)
    fctiwz	f2, f2
    stfd	f2, 0x30(r1)
    lwz	r3, 0x34(r1)
    xoris	r0, r3, 0x8000
    cmpwi	r3, 0x20
    stw	r0, 0x3c(r1)
    lfd	f2, 0x38(r1)
    fsub	f5, f2, f3
    fnmsub	f4, f1, f5, f4
    fmul	f1, f0, f5
    bc      4, 0, _80086a74
    lis     r4, lbl_80095510@ha
    slwi	r0, r3, 2
    addi	r4, r4, lbl_80095510@l
    add	r4, r4, r0
    lwz	r0, -4(r4)
    cmpw	r6, r0
    bc      12, 2, _80086a74
    fsub	f0, f4, f1
    stfd	f0, 0(r30)
    b       _80086af8
_80086a74:
    fsub	f0, f4, f1
    srawi	r4, r6, 0x14
    stfd	f0, 0(r30)
    lwz	r0, 0(r30)
    rlwinm	r0, r0, 0xc, 0x15, 0x1f
    subf	r0, r0, r4
    cmpwi	r0, 0x10
    bc      4, 1, _80086af8
    lfd	f0, -0x76d0(r2)
    fmr	f3, f4
    lfd	f1, -0x76c8(r2)
    fmul	f2, f0, f5
    fsub	f4, f4, f2
    fsub	f0, f3, f4
    fsub	f0, f0, f2
    fmsub	f1, f1, f5, f0
    fsub	f0, f4, f1
    stfd	f0, 0(r30)
    lwz	r0, 0(r30)
    rlwinm	r0, r0, 0xc, 0x15, 0x1f
    subf	r0, r0, r4
    cmpwi	r0, 0x31
    bc      4, 1, _80086af8
    lfd	f0, -0x76b0(r2)
    fmr	f2, f4
    lfd	f1, -0x76a8(r2)
    fmul	f3, f0, f5
    fsub	f4, f4, f3
    fsub	f0, f2, f4
    fsub	f0, f0, f3
    fmsub	f1, f1, f5, f0
    fsub	f0, f4, f1
    stfd	f0, 0(r30)
_80086af8:
    lfd	f0, 0(r30)
    cmpwi	r31, 0
    fsub	f0, f4, f0
    fsub	f0, f0, f1
    stfd	f0, 8(r30)
    bc      4, 0, _80086c44
    lfd	f0, 0(r30)
    neg	r3, r3
    fneg	f0, f0
    stfd	f0, 0(r30)
    lfd	f0, 8(r30)
    fneg	f0, f0
    stfd	f0, 8(r30)
    b       _80086c44
    b       _80086c44
_80086b34:
    lis	r0, 0x7ff0
    cmpw	r6, r0
    bc      12, 0, _80086b54
    fsub	f0, f1, f1
    li	r3, 0
    stfd	f0, 8(r30)
    stfd	f0, 0(r30)
    b       _80086c44
_80086b54:
    srawi	r3, r6, 0x14
    lis	r0, 0x4330
    addi	r5, r3, -0x416
    lwz	r4, 0xc(r1)
    slwi	r3, r5, 0x14
    stw	r0, 0x30(r1)
    subf	r3, r3, r6
    lfd	f5, -0x7698(r2)
    stw	r4, 0x14(r1)
    addi	r4, r1, 0x30
    lfd	f4, -0x76a0(r2)
    li	r6, 3
    stw	r3, 0x10(r1)
    lfd	f1, -0x76e8(r2)
    lfd	f3, 0x10(r1)
    stw	r0, 0x48(r1)
    fctiwz	f0, f3
    stfd	f0, 0x38(r1)
    lwz	r0, 0x3c(r1)
    xoris	r0, r0, 0x8000
    stw	r0, 0x34(r1)
    lfd	f0, 0x30(r1)
    fsub	f2, f0, f5
    fsub	f0, f3, f2
    stfd	f2, 0x18(r1)
    fmul	f3, f4, f0
    fctiwz	f0, f3
    stfd	f3, 0x10(r1)
    stfd	f0, 0x40(r1)
    lwz	r0, 0x44(r1)
    xoris	r0, r0, 0x8000
    stw	r0, 0x4c(r1)
    lfd	f0, 0x48(r1)
    fsub	f2, f0, f5
    fsub	f0, f3, f2
    stfd	f2, 0x20(r1)
    fmul	f0, f4, f0
    stfd	f0, 0x10(r1)
    stfd	f0, 0x28(r1)
    b       _80086bfc
_80086bf4:
    addi	r4, r4, -8
    addi	r6, r6, -1
_80086bfc:
    lfd	f0, -8(r4)
    fcmpu	cr0, f1, f0
    bc      12, 2, _80086bf4
    lis     r3, lbl_80095408@ha
    mr	r4, r30
    addi	r8, r3, lbl_80095408@l
    li	r7, 2
    addi	r3, r1, 0x18
    bl      fn_80086D50
    cmpwi	r31, 0
    bc      4, 0, _80086c44
    lfd	f0, 0(r30)
    neg	r3, r3
    fneg	f0, f0
    stfd	f0, 0(r30)
    lfd	f0, 8(r30)
    fneg	f0, f0
    stfd	f0, 8(r30)
_80086c44:
    lwz	r0, 0x64(r1)
    lwz	r31, 0x5c(r1)
    lwz	r30, 0x58(r1)
    mtlr	r0
    addi	r1, r1, 0x60
    blr
}

asm void MSL_strtod_nan(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    lis	r0, 0x3e40
    stfd	f1, 8(r1)
    lwz	r3, 8(r1)
    clrlwi	r4, r3, 1
    cmpw	r4, r0
    bc      4, 0, _80086c94
    fctiwz	f0, f1
    stfd	f0, 0x18(r1)
    lwz	r0, 0x1c(r1)
    cmpwi	r0, 0
    bc      4, 2, _80086c94
    lfd	f1, -0x7690(r2)
    b       _80086d48
_80086c94:
    lfd	f6, 8(r1)
    lis	r3, 0x3fd3
    addi	r0, r3, 0x3333
    lfd	f5, -0x7660(r2)
    fmul	f7, f6, f6
    lfd	f0, -0x7668(r2)
    lfd	f4, -0x7670(r2)
    cmpw	r4, r0
    lfd	f3, -0x7678(r2)
    lfd	f1, -0x7680(r2)
    fmadd	f5, f5, f7, f0
    lfd	f0, -0x7688(r2)
    fmadd	f4, f7, f5, f4
    fmadd	f3, f7, f4, f3
    fmadd	f1, f7, f3, f1
    fmadd	f0, f7, f1, f0
    fmul	f4, f7, f0
    bc      4, 0, _80086cf8
    fmul	f0, f6, f2
    lfd	f1, -0x7658(r2)
    lfd	f2, -0x7690(r2)
    fmsub	f0, f7, f4, f0
    fmsub	f0, f1, f7, f0
    fsub	f1, f2, f0
    b       _80086d48
_80086cf8:
    lis	r0, 0x3fe9
    cmpw	r4, r0
    bc      4, 1, _80086d10
    lfd	f0, -0x7650(r2)
    stfd	f0, 0x10(r1)
    b       _80086d20
_80086d10:
    addis	r3, r4, -0x20
    li	r0, 0
    stw	r3, 0x10(r1)
    stw	r0, 0x14(r1)
_80086d20:
    lfd	f0, 8(r1)
    lfd	f3, 0x10(r1)
    fmul	f0, f0, f2
    lfd	f1, -0x7658(r2)
    lfd	f2, -0x7690(r2)
    fmsub	f1, f1, f7, f3
    fmsub	f0, f7, f4, f0
    fsub	f2, f2, f3
    fsub	f0, f1, f0
    fsub	f1, f2, f0
_80086d48:
    addi	r1, r1, 0x20
    blr
}

asm void fn_80086D50(void)
{
    nofralloc
    stwu	r1, -0x2d0(r1)
    mflr	r0
    stw	r0, 0x2d4(r1)
    addi	r11, r1, 0x2d0
    bl      _savefpr_25
    stmw	r16, 0x258(r1)
    lis	r9, 0x2aab
    mr	r23, r7
    addi	r0, r5, -3
    lis     r10, lbl_80095590@ha
    addi	r7, r9, -0x5555
    slwi	r9, r23, 2
    mulhw	r0, r7, r0
    addi	r7, r10, lbl_80095590@l
    lwzx	r28, r7, r9
    mr	r21, r3
    mr	r22, r4
    mr	r24, r8
    srawi	r0, r0, 2
    addi	r30, r6, -1
    srwi	r3, r0, 0x1f
    add.	r29, r0, r3
    bc      4, 0, _80086db0
    li	r29, 0
_80086db0:
    addi	r0, r29, 1
    add.	r7, r30, r28
    mulli	r4, r0, 0x18
    subf	r6, r30, r29
    lfd	f1, -0x7610(r2)
    slwi	r3, r6, 2
    subf	r26, r4, r5
    addi	r0, r7, 1
    add	r4, r24, r3
    addi	r5, r1, 0x198
    lis	r3, 0x4330
    mtctr	r0
    bc      12, 0, _80086e20
_80086de4:
    cmpwi	r6, 0
    bc      4, 0, _80086df4
    lfd	f0, -0x7648(r2)
    b       _80086e0c
_80086df4:
    lwz	r0, 0(r4)
    stw	r3, 0x238(r1)
    xoris	r0, r0, 0x8000
    stw	r0, 0x23c(r1)
    lfd	f0, 0x238(r1)
    fsub	f0, f0, f1
_80086e0c:
    stfd	f0, 0(r5)
    addi	r5, r5, 8
    addi	r4, r4, 4
    addi	r6, r6, 1
    bc      16, 0, _80086de4
_80086e20:
    addi	r5, r1, 0x58
    li	r7, 0
    b       _80086f84
_80086e2c:
    cmpwi	r30, 0
    lfd	f4, -0x7648(r2)
    li	r6, 0
    bc      12, 0, _80086f78
    addi	r0, r30, 1
    addi	r9, r30, -8
    cmpwi	r0, 8
    bc      4, 1, _80086f34
    addi	r8, r9, 8
    mr	r4, r21
    srwi	r8, r8, 3
    add	r0, r30, r7
    addi	r3, r1, 0x198
    mtctr	r8
    cmpwi	r9, 0
    bc      12, 0, _80086f34
_80086e6c:
    subf	r8, r6, r0
    addi	r9, r6, 1
    slwi	r10, r8, 3
    lfd	f1, 0(r4)
    lfdx	f0, r3, r10
    subf	r9, r9, r0
    slwi	r10, r9, 3
    addi	r8, r6, 2
    fmadd	f4, f1, f0, f4
    subf	r9, r8, r0
    addi	r8, r6, 3
    lfd	f1, 8(r4)
    lfdx	f0, r3, r10
    subf	r8, r8, r0
    fmadd	f4, f1, f0, f4
    slwi	r9, r9, 3
    lfd	f1, 0x10(r4)
    slwi	r10, r8, 3
    lfdx	f0, r3, r9
    addi	r8, r6, 4
    fmadd	f4, f1, f0, f4
    lfd	f1, 0x18(r4)
    lfdx	f0, r3, r10
    subf	r9, r8, r0
    slwi	r10, r9, 3
    addi	r8, r6, 5
    fmadd	f4, f1, f0, f4
    lfd	f2, 0x20(r4)
    lfdx	f0, r3, r10
    subf	r8, r8, r0
    slwi	r10, r8, 3
    addi	r9, r6, 6
    fmadd	f4, f2, f0, f4
    subf	r9, r9, r0
    slwi	r9, r9, 3
    lfd	f1, 0x28(r4)
    lfdx	f0, r3, r10
    addi	r8, r6, 7
    fmadd	f4, f1, f0, f4
    subf	r8, r8, r0
    slwi	r8, r8, 3
    lfd	f3, 0x30(r4)
    lfdx	f2, r3, r9
    addi	r6, r6, 8
    lfd	f1, 0x38(r4)
    fmadd	f4, f3, f2, f4
    lfdx	f0, r3, r8
    addi	r4, r4, 0x40
    fmadd	f4, f1, f0, f4
    bc      16, 0, _80086e6c
_80086f34:
    addi	r0, r30, 1
    slwi	r3, r6, 3
    subf	r0, r6, r0
    add	r8, r30, r7
    add	r4, r21, r3
    addi	r3, r1, 0x198
    mtctr	r0
    cmpw	r6, r30
    bc      12, 1, _80086f78
_80086f58:
    subf	r0, r6, r8
    lfd	f1, 0(r4)
    slwi	r0, r0, 3
    addi	r4, r4, 8
    lfdx	f0, r3, r0
    addi	r6, r6, 1
    fmadd	f4, f1, f0, f4
    bc      16, 0, _80086f58
_80086f78:
    stfd	f4, 0(r5)
    addi	r5, r5, 8
    addi	r7, r7, 1
_80086f84:
    cmpw	r7, r28
    bc      4, 1, _80086e2c
    subfic	r18, r26, 0x18
    lfd	f26, -0x7640(r2)
    lfd	f27, -0x7610(r2)
    addi	r16, r1, 8
    lfd	f28, -0x7638(r2)
    mr	r31, r28
    lfd	f29, -0x7628(r2)
    subfic	r17, r26, 0x17
    lfd	f30, -0x7630(r2)
    addi	r20, r1, 0x198
    lfd	f31, -0x7648(r2)
    lis	r19, 0x4330
_80086fbc:
    slwi	r0, r31, 3
    addi	r5, r1, 0x58
    add	r5, r5, r0
    cmpwi	r31, 0
    lfd	f1, 0(r5)
    mr	r4, r16
    mr	r3, r31
    bc      4, 1, _800870c4
    rlwinm.	r0, r31, 0x1f, 1, 0x1f
    mtctr	r0
    bc      12, 2, _80087078
_80086fe8:
    fmul	f3, f26, f1
    stw	r19, 0x240(r1)
    lfd	f0, -8(r5)
    fctiwz	f2, f3
    stfd	f2, 0x238(r1)
    lwz	r0, 0x23c(r1)
    xoris	r0, r0, 0x8000
    stw	r0, 0x244(r1)
    lfd	f2, 0x240(r1)
    fsub	f3, f2, f27
    stw	r19, 0x240(r1)
    fnmsub	f2, f28, f3, f1
    fadd	f1, f3, f0
    lfdu	f0, -0x10(r5)
    fctiwz	f2, f2
    fmul	f3, f26, f1
    stfd	f2, 0x248(r1)
    fctiwz	f2, f3
    lwz	r0, 0x24c(r1)
    stw	r0, 0(r4)
    stfd	f2, 0x238(r1)
    lwz	r0, 0x23c(r1)
    xoris	r0, r0, 0x8000
    stw	r0, 0x244(r1)
    lfd	f2, 0x240(r1)
    fsub	f3, f2, f27
    fnmsub	f2, f28, f3, f1
    fadd	f1, f3, f0
    fctiwz	f2, f2
    stfd	f2, 0x248(r1)
    lwz	r0, 0x24c(r1)
    stw	r0, 4(r4)
    addi	r4, r4, 8
    bc      16, 0, _80086fe8
    andi.	r3, r3, 1
    bc      12, 2, _800870c4
_80087078:
    mtctr	r3
_8008707c:
    fmul	f3, f26, f1
    stw	r19, 0x240(r1)
    lfdu	f0, -8(r5)
    fctiwz	f2, f3
    stfd	f2, 0x238(r1)
    lwz	r0, 0x23c(r1)
    xoris	r0, r0, 0x8000
    stw	r0, 0x244(r1)
    lfd	f2, 0x240(r1)
    fsub	f3, f2, f27
    fnmsub	f2, f28, f3, f1
    fadd	f1, f3, f0
    fctiwz	f2, f2
    stfd	f2, 0x248(r1)
    lwz	r0, 0x24c(r1)
    stw	r0, 0(r4)
    addi	r4, r4, 4
    bc      16, 0, _8008707c
_800870c4:
    mr	r3, r26
    bl      __fpclassifyd
    fmr	f25, f1
    fmul	f1, f29, f25
    bl      fn_80087F54
    fnmsub	f25, f30, f1, f25
    stw	r19, 0x240(r1)
    cmpwi	r26, 0
    li	r25, 0
    fctiwz	f0, f25
    stfd	f0, 0x248(r1)
    lwz	r27, 0x24c(r1)
    xoris	r0, r27, 0x8000
    stw	r0, 0x244(r1)
    lfd	f0, 0x240(r1)
    fsub	f0, f0, f27
    fsub	f25, f25, f0
    bc      4, 1, _8008713c
    slwi	r3, r31, 2
    addi	r4, r1, 8
    addi	r5, r3, -4
    lwzx	r3, r4, r5
    sraw	r6, r3, r18
    slw	r0, r6, r18
    subf	r0, r0, r3
    add	r27, r27, r6
    stwx	r0, r4, r5
    lwzx	r0, r4, r5
    sraw	r25, r0, r17
    b       _8008716c
_8008713c:
    bc      4, 2, _80087158
    slwi	r4, r31, 2
    addi	r3, r1, 8
    addi	r0, r4, -4
    lwzx	r0, r3, r0
    srawi	r25, r0, 0x17
    b       _8008716c
_80087158:
    lfd	f0, -0x7620(r2)
    fcmpo	cr0, f25, f0
    cror	2, 1, 2
    bc      4, 2, _8008716c
    li	r25, 2
_8008716c:
    cmpwi	r25, 0
    bc      4, 1, _80087240
    lis	r5, 0x100
    mr	r6, r16
    li	r0, 0
    addi	r4, r5, -1
    mtctr	r31
    cmpwi	r31, 0
    addi	r27, r27, 1
    bc      4, 1, _800871c8
_80087194:
    cmpwi	r0, 0
    lwz	r3, 0(r6)
    bc      4, 2, _800871b8
    cmpwi	r3, 0
    bc      12, 2, _800871c0
    subf	r3, r3, r5
    li	r0, 1
    stw	r3, 0(r6)
    b       _800871c0
_800871b8:
    subf	r3, r3, r4
    stw	r3, 0(r6)
_800871c0:
    addi	r6, r6, 4
    bc      16, 0, _80087194
_800871c8:
    cmpwi	r26, 0
    bc      4, 1, _8008721c
    cmpwi	r26, 2
    bc      12, 2, _80087204
    bc      4, 0, _8008721c
    cmpwi	r26, 1
    bc      4, 0, _800871e8
    b       _8008721c
_800871e8:
    slwi	r3, r31, 2
    addi	r5, r1, 8
    addi	r4, r3, -4
    lwzx	r3, r5, r4
    clrlwi	r3, r3, 9
    stwx	r3, r5, r4
    b       _8008721c
_80087204:
    slwi	r3, r31, 2
    addi	r5, r1, 8
    addi	r4, r3, -4
    lwzx	r3, r5, r4
    clrlwi	r3, r3, 0xa
    stwx	r3, r5, r4
_8008721c:
    cmpwi	r25, 2
    bc      4, 2, _80087240
    lfd	f1, -0x7618(r2)
    cmpwi	r0, 0
    fsub	f25, f1, f25
    bc      12, 2, _80087240
    mr	r3, r26
    bl      __fpclassifyd
    fsub	f25, f25, f1
_80087240:
    fcmpu	cr0, f31, f25
    bc      4, 2, _800874a8
    addi	r3, r31, -1
    addi	r4, r1, 8
    cmpw	r3, r28
    li	r5, 0
    slwi	r0, r3, 2
    addi	r3, r3, 1
    add	r4, r4, r0
    subf	r3, r28, r3
    bc      12, 0, _800872dc
    rlwinm.	r0, r3, 0x1d, 3, 0x1f
    mtctr	r0
    bc      12, 2, _800872c8
_80087278:
    lwz	r0, 0(r4)
    or	r5, r5, r0
    lwz	r0, -4(r4)
    or	r5, r5, r0
    lwz	r0, -8(r4)
    or	r5, r5, r0
    lwz	r0, -0xc(r4)
    or	r5, r5, r0
    lwz	r0, -0x10(r4)
    or	r5, r5, r0
    lwz	r0, -0x14(r4)
    or	r5, r5, r0
    lwz	r0, -0x18(r4)
    or	r5, r5, r0
    lwz	r0, -0x1c(r4)
    addi	r4, r4, -0x20
    or	r5, r5, r0
    bc      16, 0, _80087278
    andi.	r3, r3, 7
    bc      12, 2, _800872dc
_800872c8:
    mtctr	r3
_800872cc:
    lwz	r0, 0(r4)
    addi	r4, r4, -4
    or	r5, r5, r0
    bc      16, 0, _800872cc
_800872dc:
    cmpwi	r5, 0
    bc      4, 2, _800874a8
    li	r10, 1
    b       _800872f0
_800872ec:
    addi	r10, r10, 1
_800872f0:
    subf	r0, r10, r28
    slwi	r0, r0, 2
    lwzx	r0, r16, r0
    cmpwi	r0, 0
    bc      12, 2, _800872ec
    addi	r9, r31, 1
    addi	r5, r1, 0x58
    slwi	r0, r9, 3
    add	r6, r31, r10
    add	r5, r5, r0
    b       _80087498
_8008731c:
    add	r0, r29, r9
    add	r7, r30, r9
    slwi	r0, r0, 2
    stw	r19, 0x248(r1)
    lwzx	r3, r24, r0
    cmpwi	r30, 0
    slwi	r0, r7, 3
    lfd	f4, -0x7648(r2)
    xoris	r3, r3, 0x8000
    li	r8, 0
    stw	r3, 0x24c(r1)
    lfd	f0, 0x248(r1)
    fsub	f0, f0, f27
    stfdx	f0, r20, r0
    bc      12, 0, _8008748c
    addi	r0, r30, 1
    addi	r11, r30, -8
    cmpwi	r0, 8
    bc      4, 1, _8008744c
    addi	r0, r11, 8
    mr	r4, r21
    srwi	r0, r0, 3
    addi	r3, r1, 0x198
    mtctr	r0
    cmpwi	r11, 0
    bc      12, 0, _8008744c
_80087384:
    subf	r11, r8, r7
    addi	r0, r8, 1
    slwi	r12, r11, 3
    lfd	f1, 0(r4)
    lfdx	f0, r3, r12
    subf	r0, r0, r7
    addi	r11, r8, 2
    lfd	f2, 0x20(r4)
    fmadd	f4, f1, f0, f4
    subf	r12, r11, r7
    slwi	r0, r0, 3
    addi	r11, r8, 3
    lfdx	f0, r3, r0
    slwi	r25, r12, 3
    lfd	f1, 8(r4)
    subf	r11, r11, r7
    slwi	r12, r11, 3
    addi	r0, r8, 4
    fmadd	f4, f1, f0, f4
    lfd	f1, 0x10(r4)
    lfdx	f0, r3, r25
    subf	r11, r0, r7
    addi	r0, r8, 5
    lfd	f3, 0x30(r4)
    fmadd	f4, f1, f0, f4
    lfdx	f0, r3, r12
    lfd	f1, 0x18(r4)
    slwi	r12, r11, 3
    addi	r11, r8, 6
    subf	r0, r0, r7
    fmadd	f4, f1, f0, f4
    lfdx	f0, r3, r12
    slwi	r12, r0, 3
    lfd	f1, 0x28(r4)
    addi	r0, r8, 7
    subf	r11, r11, r7
    fmadd	f4, f2, f0, f4
    lfdx	f0, r3, r12
    slwi	r11, r11, 3
    subf	r0, r0, r7
    lfdx	f2, r3, r11
    slwi	r0, r0, 3
    fmadd	f4, f1, f0, f4
    lfd	f1, 0x38(r4)
    lfdx	f0, r3, r0
    addi	r4, r4, 0x40
    addi	r8, r8, 8
    fmadd	f4, f3, f2, f4
    fmadd	f4, f1, f0, f4
    bc      16, 0, _80087384
_8008744c:
    addi	r0, r30, 1
    slwi	r4, r8, 3
    subf	r0, r8, r0
    addi	r3, r1, 0x198
    add	r4, r21, r4
    mtctr	r0
    cmpw	r8, r30
    bc      12, 1, _8008748c
_8008746c:
    subf	r0, r8, r7
    lfd	f1, 0(r4)
    slwi	r0, r0, 3
    addi	r4, r4, 8
    lfdx	f0, r3, r0
    addi	r8, r8, 1
    fmadd	f4, f1, f0, f4
    bc      16, 0, _8008746c
_8008748c:
    stfd	f4, 0(r5)
    addi	r5, r5, 8
    addi	r9, r9, 1
_80087498:
    cmpw	r9, r6
    bc      4, 1, _8008731c
    add	r31, r31, r10
    b       _80086fbc
_800874a8:
    lfd	f0, -0x7648(r2)
    fcmpu	cr0, f0, f25
    bc      4, 2, _800874e8
    addi	r31, r31, -1
    addi	r3, r1, 8
    slwi	r0, r31, 2
    addi	r26, r26, -0x18
    add	r3, r3, r0
    b       _800874d8
_800874cc:
    addi	r3, r3, -4
    addi	r31, r31, -1
    addi	r26, r26, -0x18
_800874d8:
    lwz	r0, 0(r3)
    cmpwi	r0, 0
    bc      12, 2, _800874cc
    b       _80087588
_800874e8:
    fmr	f1, f25
    neg	r3, r26
    bl      __fpclassifyd
    lfd	f3, -0x7638(r2)
    fcmpo	cr0, f1, f3
    cror	2, 1, 2
    bc      4, 2, _80087570
    lfd	f0, -0x7640(r2)
    lis	r0, 0x4330
    slwi	r5, r31, 2
    stw	r0, 0x240(r1)
    fmul	f0, f0, f1
    addi	r31, r31, 1
    lfd	f2, -0x7610(r2)
    addi	r4, r1, 8
    slwi	r0, r31, 2
    addi	r26, r26, 0x18
    fctiwz	f0, f0
    stfd	f0, 0x248(r1)
    lwz	r3, 0x24c(r1)
    xoris	r3, r3, 0x8000
    stw	r3, 0x244(r1)
    lfd	f0, 0x240(r1)
    fsub	f0, f0, f2
    fnmsub	f1, f3, f0, f1
    fctiwz	f0, f0
    fctiwz	f1, f1
    stfd	f0, 0x250(r1)
    stfd	f1, 0x238(r1)
    lwz	r3, 0x254(r1)
    lwz	r6, 0x23c(r1)
    stwx	r6, r4, r5
    stwx	r3, r4, r0
    b       _80087588
_80087570:
    fctiwz	f0, f1
    slwi	r0, r31, 2
    addi	r3, r1, 8
    stfd	f0, 0x250(r1)
    lwz	r4, 0x254(r1)
    stwx	r4, r3, r0
_80087588:
    lfd	f1, -0x7618(r2)
    mr	r3, r26
    bl      __fpclassifyd
    cmpwi	r31, 0
    slwi	r0, r31, 2
    addi	r6, r1, 8
    slwi	r8, r31, 3
    addi	r7, r1, 0x58
    lfd	f5, -0x7610(r2)
    lfd	f0, -0x7640(r2)
    add	r6, r6, r0
    add	r7, r7, r8
    addi	r3, r31, 1
    lis	r4, 0x4330
    bc      12, 0, _800876a8
    rlwinm.	r0, r3, 0x1e, 2, 0x1f
    mtctr	r0
    bc      12, 2, _80087674
_800875d0:
    lwz	r5, 0(r6)
    stw	r4, 0x250(r1)
    xoris	r0, r5, 0x8000
    lwz	r5, -4(r6)
    stw	r0, 0x254(r1)
    xoris	r0, r5, 0x8000
    lwz	r5, -8(r6)
    lfd	f4, 0x250(r1)
    stw	r0, 0x254(r1)
    fsub	f3, f4, f5
    xoris	r0, r5, 0x8000
    lwz	r5, -0xc(r6)
    stw	r4, 0x250(r1)
    addi	r6, r6, -0x10
    fmul	f2, f1, f3
    lfd	f4, 0x250(r1)
    fmul	f1, f1, f0
    stw	r0, 0x254(r1)
    xoris	r0, r5, 0x8000
    fsub	f3, f4, f5
    stw	r4, 0x250(r1)
    lfd	f4, 0x250(r1)
    stfd	f2, 0(r7)
    fmul	f2, f1, f3
    fmul	f1, f1, f0
    stw	r0, 0x254(r1)
    stw	r4, 0x250(r1)
    fsub	f3, f4, f5
    stfd	f2, -8(r7)
    fmul	f2, f1, f3
    lfd	f4, 0x250(r1)
    fmul	f1, f1, f0
    fsub	f3, f4, f5
    stfd	f2, -0x10(r7)
    fmul	f2, f1, f3
    fmul	f1, f1, f0
    stfd	f2, -0x18(r7)
    addi	r7, r7, -0x20
    bc      16, 0, _800875d0
    andi.	r3, r3, 3
    bc      12, 2, _800876a8
_80087674:
    mtctr	r3
_80087678:
    lwz	r5, 0(r6)
    addi	r6, r6, -4
    stw	r4, 0x250(r1)
    xoris	r0, r5, 0x8000
    stw	r0, 0x254(r1)
    lfd	f4, 0x250(r1)
    fsub	f3, f4, f5
    fmul	f2, f1, f3
    fmul	f1, f1, f0
    stfd	f2, 0(r7)
    addi	r7, r7, -8
    bc      16, 0, _80087678
_800876a8:
    lis     r3, lbl_800955A0@ha
    addi	r0, r31, 1
    mr	r9, r31
    addi	r4, r1, 0x58
    addi	r5, r3, lbl_800955A0@l
    addi	r3, r1, 0xf8
    mtctr	r0
    cmpwi	r31, 0
    bc      12, 0, _8008771c
_800876cc:
    lfd	f2, -0x7648(r2)
    mr	r6, r5
    subf	r7, r9, r31
    li	r10, 0
    b       _800876fc
_800876e0:
    add	r0, r9, r10
    lfd	f1, 0(r6)
    slwi	r0, r0, 3
    addi	r6, r6, 8
    lfdx	f0, r4, r0
    addi	r10, r10, 1
    fmadd	f2, f1, f0, f2
_800876fc:
    cmpw	r10, r28
    bc      12, 1, _8008770c
    cmpw	r10, r7
    bc      4, 1, _800876e0
_8008770c:
    slwi	r0, r7, 3
    addi	r9, r9, -1
    stfdx	f2, r3, r0
    bc      16, 0, _800876cc
_8008771c:
    cmpwi	r23, 3
    bc      12, 2, _80087944
    bc      4, 0, _80087b84
    cmpwi	r23, 0
    bc      12, 2, _80087738
    bc      4, 0, _800877d8
    b       _80087b84
_80087738:
    cmpwi	r31, 0
    addi	r4, r1, 0xf8
    lfd	f1, -0x7648(r2)
    add	r4, r4, r8
    addi	r3, r31, 1
    bc      12, 0, _800877c0
    rlwinm.	r0, r3, 0x1d, 3, 0x1f
    mtctr	r0
    bc      12, 2, _800877ac
_8008775c:
    lfd	f0, 0(r4)
    fadd	f1, f1, f0
    lfd	f0, -8(r4)
    fadd	f1, f1, f0
    lfd	f0, -0x10(r4)
    fadd	f1, f1, f0
    lfd	f0, -0x18(r4)
    fadd	f1, f1, f0
    lfd	f0, -0x20(r4)
    fadd	f1, f1, f0
    lfd	f0, -0x28(r4)
    fadd	f1, f1, f0
    lfd	f0, -0x30(r4)
    fadd	f1, f1, f0
    lfd	f0, -0x38(r4)
    addi	r4, r4, -0x40
    fadd	f1, f1, f0
    bc      16, 0, _8008775c
    andi.	r3, r3, 7
    bc      12, 2, _800877c0
_800877ac:
    mtctr	r3
_800877b0:
    lfd	f0, 0(r4)
    addi	r4, r4, -8
    fadd	f1, f1, f0
    bc      16, 0, _800877b0
_800877c0:
    cmpwi	r25, 0
    bc      4, 2, _800877cc
    b       _800877d0
_800877cc:
    fneg	f1, f1
_800877d0:
    stfd	f1, 0(r22)
    b       _80087b84
_800877d8:
    cmpwi	r31, 0
    addi	r4, r1, 0xf8
    lfd	f2, -0x7648(r2)
    add	r4, r4, r8
    addi	r3, r31, 1
    bc      12, 0, _80087860
    rlwinm.	r0, r3, 0x1d, 3, 0x1f
    mtctr	r0
    bc      12, 2, _8008784c
_800877fc:
    lfd	f0, 0(r4)
    fadd	f2, f2, f0
    lfd	f0, -8(r4)
    fadd	f2, f2, f0
    lfd	f0, -0x10(r4)
    fadd	f2, f2, f0
    lfd	f0, -0x18(r4)
    fadd	f2, f2, f0
    lfd	f0, -0x20(r4)
    fadd	f2, f2, f0
    lfd	f0, -0x28(r4)
    fadd	f2, f2, f0
    lfd	f0, -0x30(r4)
    fadd	f2, f2, f0
    lfd	f0, -0x38(r4)
    addi	r4, r4, -0x40
    fadd	f2, f2, f0
    bc      16, 0, _800877fc
    andi.	r3, r3, 7
    bc      12, 2, _80087860
_8008784c:
    mtctr	r3
_80087850:
    lfd	f0, 0(r4)
    addi	r4, r4, -8
    fadd	f2, f2, f0
    bc      16, 0, _80087850
_80087860:
    cmpwi	r25, 0
    bc      4, 2, _80087870
    fmr	f1, f2
    b       _80087874
_80087870:
    fneg	f1, f2
_80087874:
    lfd	f0, 0xf8(r1)
    cmpwi	r31, 1
    stfd	f1, 0(r22)
    li	r5, 1
    fsub	f6, f0, f2
    bc      12, 0, _8008792c
    cmpwi	r31, 8
    addi	r3, r31, -8
    bc      4, 1, _800878fc
    addi	r0, r3, 7
    addi	r4, r1, 0x100
    srwi	r0, r0, 3
    mtctr	r0
    cmpwi	r3, 1
    bc      12, 0, _800878fc
_800878b0:
    lfd	f1, 0(r4)
    addi	r5, r5, 8
    lfd	f0, 8(r4)
    fadd	f6, f6, f1
    lfd	f5, 0x10(r4)
    lfd	f4, 0x18(r4)
    lfd	f3, 0x20(r4)
    fadd	f6, f6, f0
    lfd	f2, 0x28(r4)
    lfd	f1, 0x30(r4)
    lfd	f0, 0x38(r4)
    addi	r4, r4, 0x40
    fadd	f6, f6, f5
    fadd	f6, f6, f4
    fadd	f6, f6, f3
    fadd	f6, f6, f2
    fadd	f6, f6, f1
    fadd	f6, f6, f0
    bc      16, 0, _800878b0
_800878fc:
    addi	r0, r31, 1
    slwi	r3, r5, 3
    addi	r4, r1, 0xf8
    subf	r0, r5, r0
    add	r4, r4, r3
    mtctr	r0
    cmpw	r5, r31
    bc      12, 1, _8008792c
_8008791c:
    lfd	f0, 0(r4)
    addi	r4, r4, 8
    fadd	f6, f6, f0
    bc      16, 0, _8008791c
_8008792c:
    cmpwi	r25, 0
    bc      4, 2, _80087938
    b       _8008793c
_80087938:
    fneg	f6, f6
_8008793c:
    stfd	f6, 8(r22)
    b       _80087b84
_80087944:
    addi	r5, r1, 0xf8
    cmpwi	r31, 0
    add	r5, r5, r8
    mr	r3, r31
    mr	r4, r5
    bc      4, 1, _80087a08
    rlwinm.	r0, r31, 0x1e, 2, 0x1f
    mtctr	r0
    bc      12, 2, _800879e4
_80087968:
    lfd	f0, -8(r4)
    lfd	f1, 0(r4)
    fadd	f2, f0, f1
    fsub	f0, f0, f2
    fadd	f0, f1, f0
    stfd	f0, 0(r4)
    stfd	f2, -8(r4)
    lfd	f0, -0x10(r4)
    lfd	f1, -8(r4)
    fadd	f2, f0, f1
    fsub	f0, f0, f2
    fadd	f0, f1, f0
    stfd	f0, -8(r4)
    stfd	f2, -0x10(r4)
    lfd	f0, -0x18(r4)
    lfd	f1, -0x10(r4)
    fadd	f2, f0, f1
    fsub	f0, f0, f2
    fadd	f0, f1, f0
    stfd	f0, -0x10(r4)
    stfd	f2, -0x18(r4)
    lfd	f0, -0x20(r4)
    lfd	f1, -0x18(r4)
    fadd	f2, f0, f1
    fsub	f0, f0, f2
    fadd	f0, f1, f0
    stfd	f0, -0x18(r4)
    stfdu	f2, -0x20(r4)
    bc      16, 0, _80087968
    andi.	r3, r3, 3
    bc      12, 2, _80087a08
_800879e4:
    mtctr	r3
_800879e8:
    lfd	f0, -8(r4)
    lfd	f1, 0(r4)
    fadd	f2, f0, f1
    fsub	f0, f0, f2
    fadd	f0, f1, f0
    stfd	f0, 0(r4)
    stfdu	f2, -8(r4)
    bc      16, 0, _800879e8
_80087a08:
    cmpwi	r31, 1
    mr	r4, r5
    addi	r3, r31, -1
    bc      4, 1, _80087ac4
    rlwinm.	r0, r3, 0x1e, 2, 0x1f
    mtctr	r0
    bc      12, 2, _80087aa0
_80087a24:
    lfd	f0, -8(r4)
    lfd	f1, 0(r4)
    fadd	f2, f0, f1
    fsub	f0, f0, f2
    fadd	f0, f1, f0
    stfd	f0, 0(r4)
    stfd	f2, -8(r4)
    lfd	f0, -0x10(r4)
    lfd	f1, -8(r4)
    fadd	f2, f0, f1
    fsub	f0, f0, f2
    fadd	f0, f1, f0
    stfd	f0, -8(r4)
    stfd	f2, -0x10(r4)
    lfd	f0, -0x18(r4)
    lfd	f1, -0x10(r4)
    fadd	f2, f0, f1
    fsub	f0, f0, f2
    fadd	f0, f1, f0
    stfd	f0, -0x10(r4)
    stfd	f2, -0x18(r4)
    lfd	f0, -0x20(r4)
    lfd	f1, -0x18(r4)
    fadd	f2, f0, f1
    fsub	f0, f0, f2
    fadd	f0, f1, f0
    stfd	f0, -0x18(r4)
    stfdu	f2, -0x20(r4)
    bc      16, 0, _80087a24
    andi.	r3, r3, 3
    bc      12, 2, _80087ac4
_80087aa0:
    mtctr	r3
_80087aa4:
    lfd	f0, -8(r4)
    lfd	f1, 0(r4)
    fadd	f2, f0, f1
    fsub	f0, f0, f2
    fadd	f0, f1, f0
    stfd	f0, 0(r4)
    stfdu	f2, -8(r4)
    bc      16, 0, _80087aa4
_80087ac4:
    cmpwi	r31, 2
    lfd	f3, -0x7648(r2)
    addi	r3, r31, -1
    bc      12, 0, _80087b44
    rlwinm.	r0, r3, 0x1d, 3, 0x1f
    mtctr	r0
    bc      12, 2, _80087b30
_80087ae0:
    lfd	f0, 0(r5)
    fadd	f3, f3, f0
    lfd	f0, -8(r5)
    fadd	f3, f3, f0
    lfd	f0, -0x10(r5)
    fadd	f3, f3, f0
    lfd	f0, -0x18(r5)
    fadd	f3, f3, f0
    lfd	f0, -0x20(r5)
    fadd	f3, f3, f0
    lfd	f0, -0x28(r5)
    fadd	f3, f3, f0
    lfd	f0, -0x30(r5)
    fadd	f3, f3, f0
    lfd	f0, -0x38(r5)
    addi	r5, r5, -0x40
    fadd	f3, f3, f0
    bc      16, 0, _80087ae0
    andi.	r3, r3, 7
    bc      12, 2, _80087b44
_80087b30:
    mtctr	r3
_80087b34:
    lfd	f0, 0(r5)
    addi	r5, r5, -8
    fadd	f3, f3, f0
    bc      16, 0, _80087b34
_80087b44:
    cmpwi	r25, 0
    bc      4, 2, _80087b64
    lfd	f1, 0xf8(r1)
    lfd	f0, 0x100(r1)
    stfd	f1, 0(r22)
    stfd	f0, 8(r22)
    stfd	f3, 0x10(r22)
    b       _80087b84
_80087b64:
    lfd	f2, 0xf8(r1)
    fneg	f0, f3
    lfd	f1, 0x100(r1)
    fneg	f2, f2
    fneg	f1, f1
    stfd	f2, 0(r22)
    stfd	f1, 8(r22)
    stfd	f0, 0x10(r22)
_80087b84:
    clrlwi	r3, r27, 0x1d
    addi	r11, r1, 0x2d0
    bl      _restfpr_25
    lmw	r16, 0x258(r1)
    lwz	r0, 0x2d4(r1)
    mtlr	r0
    addi	r1, r1, 0x2d0
    blr
}

asm void fn_80087BA4(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    lis	r0, 0x3e40
    stfd	f1, 8(r1)
    lwz	r4, 8(r1)
    clrlwi	r4, r4, 1
    cmpw	r4, r0
    bc      4, 0, _80087bd8
    fctiwz	f0, f1
    stfd	f0, 0x10(r1)
    lwz	r0, 0x14(r1)
    cmpwi	r0, 0
    bc      4, 2, _80087bd8
    b       _80087c3c
_80087bd8:
    lfd	f6, 8(r1)
    cmpwi	r3, 0
    lfd	f5, -0x75e8(r2)
    fmul	f7, f6, f6
    lfd	f4, -0x75f0(r2)
    lfd	f3, -0x75f8(r2)
    lfd	f1, -0x7600(r2)
    lfd	f0, -0x7608(r2)
    fmadd	f4, f5, f7, f4
    fmul	f5, f7, f6
    fmadd	f3, f7, f4, f3
    fmadd	f1, f7, f3, f1
    fmadd	f1, f7, f1, f0
    bc      4, 2, _80087c20
    lfd	f0, -0x75e0(r2)
    fmadd	f0, f7, f1, f0
    fmadd	f1, f5, f0, f6
    b       _80087c3c
_80087c20:
    fmul	f0, f5, f1
    lfd	f1, -0x75d8(r2)
    lfd	f3, -0x75e0(r2)
    fmsub	f0, f1, f2, f0
    fmsub	f0, f7, f0, f2
    fnmsub	f0, f3, f5, f0
    fsub	f1, f6, f0
_80087c3c:
    addi	r1, r1, 0x20
    blr
}

asm void fn_80087C44(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    stfd	f31, 0x30(r1)
    psq_st	f31, 0x38(r1), 0, 0
    stfd	f1, 8(r1)
    lis	r0, 0x3e30
    lwz	r7, 8(r1)
    clrlwi	r6, r7, 1
    cmpw	r6, r0
    bc      4, 0, _80087cb8
    fctiwz	f0, f1
    stfd	f0, 0x20(r1)
    lwz	r0, 0x24(r1)
    cmpwi	r0, 0
    bc      4, 2, _80087cb8
    lwz	r0, 0xc(r1)
    addi	r4, r3, 1
    or	r0, r6, r0
    or.	r0, r4, r0
    bc      4, 2, _80087ca0
    fabs	f1, f1
    lfd	f0, -0x75d0(r2)
    fdiv	f1, f0, f1
    b       _80087e48
_80087ca0:
    cmpwi	r3, 1
    bc      4, 2, _80087cac
    b       _80087e48
_80087cac:
    lfd	f0, -0x75c8(r2)
    fdiv	f1, f0, f1
    b       _80087e48
_80087cb8:
    lis	r4, 0x3fe6
    addi	r0, r4, -0x6bd8
    cmpw	r6, r0
    bc      12, 0, _80087d04
    cmpwi	r7, 0
    bc      4, 0, _80087ce0
    lfd	f0, 8(r1)
    fneg	f2, f2
    fneg	f0, f0
    stfd	f0, 8(r1)
_80087ce0:
    lfd	f0, -0x75b8(r2)
    lfd	f3, -0x75c0(r2)
    lfd	f1, 8(r1)
    fsub	f0, f0, f2
    lfd	f2, -0x75b0(r2)
    fsub	f1, f3, f1
    fadd	f0, f1, f0
    stfd	f1, 0x18(r1)
    stfd	f0, 8(r1)
_80087d04:
    lfd	f0, 8(r1)
    lis     r4, lbl_800955E0@ha
    addi	r5, r4, lbl_800955E0@l
    lis	r4, 0x3fe6
    fmul	f13, f0, f0
    addi	r0, r4, -0x6bd8
    lfd	f5, 0x60(r5)
    cmpw	r6, r0
    lfd	f4, 0x50(r5)
    lfd	f9, 0x58(r5)
    fmul	f31, f13, f13
    lfd	f8, 0x48(r5)
    lfd	f3, 0x40(r5)
    lfd	f11, 0x38(r5)
    fmul	f1, f13, f0
    lfd	f6, 0x30(r5)
    fmadd	f7, f31, f5, f4
    lfd	f10, 0x28(r5)
    lfd	f5, 0x20(r5)
    fmadd	f12, f31, f9, f8
    lfd	f9, 0x18(r5)
    lfd	f4, 0x10(r5)
    fmadd	f7, f31, f7, f3
    lfd	f8, 8(r5)
    lfd	f3, 0(r5)
    fmadd	f11, f31, f12, f11
    stfd	f13, 0x18(r1)
    fmadd	f6, f31, f7, f6
    fmadd	f7, f31, f11, f10
    fmadd	f5, f31, f6, f5
    fmadd	f6, f31, f7, f9
    fmadd	f4, f31, f5, f4
    fmadd	f5, f31, f6, f8
    fmul	f4, f13, f4
    fadd	f4, f5, f4
    fmadd	f4, f1, f4, f2
    fmadd	f6, f13, f4, f2
    fmadd	f6, f3, f1, f6
    fadd	f1, f0, f6
    bc      12, 0, _80087e00
    lis	r4, 0x4330
    xoris	r0, r3, 0x8000
    stw	r0, 0x24(r1)
    rlwinm	r0, r7, 2, 0x1e, 0x1e
    subfic	r0, r0, 1
    lfd	f5, -0x75a0(r2)
    stw	r4, 0x20(r1)
    xoris	r0, r0, 0x8000
    fmul	f2, f1, f1
    lfd	f3, -0x75a8(r2)
    lfd	f4, 0x20(r1)
    stw	r0, 0x2c(r1)
    fsub	f7, f4, f5
    stw	r4, 0x28(r1)
    fadd	f1, f1, f7
    lfd	f4, 0x28(r1)
    fsub	f4, f4, f5
    fdiv	f1, f2, f1
    fsub	f1, f1, f6
    fsub	f0, f0, f1
    fnmsub	f0, f3, f0, f7
    fmul	f1, f4, f0
    b       _80087e48
_80087e00:
    cmpwi	r3, 1
    bc      4, 2, _80087e0c
    b       _80087e48
_80087e0c:
    lfd	f2, -0x75c8(r2)
    li	r0, 0
    stfd	f1, 0x18(r1)
    fdiv	f4, f2, f1
    lfd	f1, -0x75d0(r2)
    stw	r0, 0x1c(r1)
    lfd	f2, 0x18(r1)
    stfd	f4, 0x10(r1)
    fsub	f0, f2, f0
    stw	r0, 0x14(r1)
    fsub	f0, f6, f0
    lfd	f3, 0x10(r1)
    fmadd	f1, f3, f2, f1
    fmadd	f0, f3, f0, f1
    fmadd	f1, f4, f0, f3
_80087e48:
    psq_l	f31, 0x38(r1), 0, 0
    lfd	f31, 0x30(r1)
    addi	r1, r1, 0x40
    blr
}

asm void __fp_compare_greater_equal(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    stfd	f1, 8(r1)
    stfd	f2, 0x10(r1)
    lwz	r3, 8(r1)
    lwz	r0, 0x10(r1)
    rlwimi	r0, r3, 0, 1, 0x1f
    stw	r0, 8(r1)
    lfd	f1, 8(r1)
    addi	r1, r1, 0x20
    blr
}

asm void fn_80087E80(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis	r3, 0x3fe9
    stfd	f1, 8(r1)
    stw	r0, 0x24(r1)
    addi	r0, r3, 0x21fb
    lwz	r3, 8(r1)
    clrlwi	r3, r3, 1
    cmpw	r3, r0
    bc      12, 1, _80087eb4
    lfd	f2, -0x7598(r2)
    bl      MSL_strtod_nan
    b       _80087f44
_80087eb4:
    lis	r0, 0x7ff0
    cmpw	r3, r0
    bc      12, 0, _80087ec8
    fsub	f1, f1, f1
    b       _80087f44
_80087ec8:
    addi	r3, r1, 0x10
    bl      fn_800868BC
    clrlwi	r0, r3, 0x1e
    cmpwi	r0, 1
    bc      12, 2, _80087f08
    bc      4, 0, _80087eec
    cmpwi	r0, 0
    bc      4, 0, _80087ef8
    b       _80087f34
_80087eec:
    cmpwi	r0, 3
    bc      4, 0, _80087f34
    b       _80087f20
_80087ef8:
    lfd	f1, 0x10(r1)
    lfd	f2, 0x18(r1)
    bl      MSL_strtod_nan
    b       _80087f44
_80087f08:
    lfd	f1, 0x10(r1)
    li	r3, 1
    lfd	f2, 0x18(r1)
    bl      fn_80087BA4
    fneg	f1, f1
    b       _80087f44
_80087f20:
    lfd	f1, 0x10(r1)
    lfd	f2, 0x18(r1)
    bl      MSL_strtod_nan
    fneg	f1, f1
    b       _80087f44
_80087f34:
    lfd	f1, 0x10(r1)
    li	r3, 1
    lfd	f2, 0x18(r1)
    bl      fn_80087BA4
_80087f44:
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_80087F54(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    stfd	f1, 8(r1)
    lwz	r5, 8(r1)
    lwz	r6, 0xc(r1)
    rlwinm	r3, r5, 0xc, 0x15, 0x1f
    addi	r7, r3, -0x3ff
    cmpwi	r7, 0x14
    bc      4, 0, _80088008
    cmpwi	r7, 0
    bc      4, 0, _80087fbc
    lfd	f2, -0x7590(r2)
    lfd	f0, -0x7588(r2)
    fadd	f1, f2, f1
    fcmpo	cr0, f1, f0
    bc      4, 1, _80088088
    cmpwi	r5, 0
    bc      12, 0, _80087fa4
    li	r6, 0
    li	r5, 0
    b       _80088088
_80087fa4:
    clrlwi	r0, r5, 1
    or.	r0, r0, r6
    bc      12, 2, _80088088
    lis	r5, -0x4010
    li	r6, 0
    b       _80088088
_80087fbc:
    lis	r3, 0x10
    addi	r0, r3, -1
    sraw	r4, r0, r7
    and	r0, r5, r4
    or.	r0, r6, r0
    bc      4, 2, _80087fd8
    b       _80088094
_80087fd8:
    lfd	f2, -0x7590(r2)
    lfd	f0, -0x7588(r2)
    fadd	f1, f2, f1
    fcmpo	cr0, f1, f0
    bc      4, 1, _80088088
    cmpwi	r5, 0
    bc      4, 0, _80087ffc
    sraw	r0, r3, r7
    add	r5, r5, r0
_80087ffc:
    andc	r5, r5, r4
    li	r6, 0
    b       _80088088
_80088008:
    cmpwi	r7, 0x33
    bc      4, 1, _80088020
    cmpwi	r7, 0x400
    bc      4, 2, _80088094
    fadd	f1, f1, f1
    b       _80088094
_80088020:
    addi	r0, r7, -0x14
    li	r3, -1
    srw	r4, r3, r0
    and.	r0, r6, r4
    bc      4, 2, _80088038
    b       _80088094
_80088038:
    lfd	f2, -0x7590(r2)
    lfd	f0, -0x7588(r2)
    fadd	f1, f2, f1
    fcmpo	cr0, f1, f0
    bc      4, 1, _80088088
    cmpwi	r5, 0
    bc      4, 0, _80088084
    cmpwi	r7, 0x14
    bc      4, 2, _80088064
    addi	r5, r5, 1
    b       _80088084
_80088064:
    subfic	r0, r7, 0x34
    li	r3, 1
    slw	r0, r3, r0
    add	r0, r6, r0
    cmplw	r0, r6
    bc      4, 0, _80088080
    addi	r5, r5, 1
_80088080:
    mr	r6, r0
_80088084:
    andc	r6, r6, r4
_80088088:
    stw	r5, 8(r1)
    stw	r6, 0xc(r1)
    lfd	f1, 8(r1)
_80088094:
    addi	r1, r1, 0x10
    blr
}

asm void frexp(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    li	r4, 0
    lis	r0, 0x7ff0
    stfd	f1, 8(r1)
    lwz	r5, 8(r1)
    stw	r4, 0(r3)
    clrlwi	r4, r5, 1
    lwz	r6, 0xc(r1)
    cmpw	r4, r0
    bc      4, 0, _800880cc
    or.	r0, r4, r6
    bc      4, 2, _800880d4
_800880cc:
    lfd	f1, 8(r1)
    b       _80088120
_800880d4:
    lis	r0, 0x10
    cmpw	r4, r0
    bc      4, 0, _800880fc
    lfd	f0, -0x7580(r2)
    li	r0, -0x36
    stw	r0, 0(r3)
    fmul	f0, f1, f0
    stfd	f0, 8(r1)
    lwz	r5, 8(r1)
    clrlwi	r4, r5, 1
_800880fc:
    rlwinm	r0, r5, 0, 0xc, 0
    lwz	r5, 0(r3)
    srawi	r4, r4, 0x14
    oris	r0, r0, 0x3fe0
    stw	r0, 8(r1)
    add	r4, r4, r5
    addi	r0, r4, -0x3fe
    stw	r0, 0(r3)
    lfd	f1, 8(r1)
_80088120:
    addi	r1, r1, 0x10
    blr
}

asm void __fpclassifyd(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stfd	f1, 0x10(r1)
    lwz	r5, 0x10(r1)
    stw	r0, 0x24(r1)
    lis	r0, 0x7ff0
    rlwinm	r4, r5, 0, 1, 0xb
    cmpw	r4, r0
    stfd	f1, 8(r1)
    bc      12, 2, _80088160
    bc      4, 0, _800881a8
    cmpwi	r4, 0
    bc      12, 2, _80088184
    b       _800881a8
_80088160:
    clrlwi.	r0, r5, 0xc
    bc      4, 2, _80088174
    lwz	r0, 0x14(r1)
    cmpwi	r0, 0
    bc      12, 2, _8008817c
_80088174:
    li	r0, 1
    b       _800881ac
_8008817c:
    li	r0, 2
    b       _800881ac
_80088184:
    clrlwi.	r0, r5, 0xc
    bc      4, 2, _80088198
    lwz	r0, 0x14(r1)
    cmpwi	r0, 0
    bc      12, 2, _800881a0
_80088198:
    li	r0, 5
    b       _800881ac
_800881a0:
    li	r0, 3
    b       _800881ac
_800881a8:
    li	r0, 4
_800881ac:
    cmpwi	r0, 2
    bc      4, 1, _800882dc
    lfd	f0, -0x7578(r2)
    fcmpu	cr0, f0, f1
    bc      4, 2, _800881c4
    b       _800882dc
_800881c4:
    lwz	r5, 8(r1)
    lwz	r6, 0xc(r1)
    rlwinm.	r4, r5, 0xc, 0x15, 0x1f
    bc      4, 2, _8008821c
    clrlwi	r0, r5, 1
    or.	r0, r6, r0
    bc      4, 2, _800881e4
    b       _800882dc
_800881e4:
    lfd	f1, 8(r1)
    lis	r4, -1
    lfd	f0, -0x7570(r2)
    addi	r0, r4, 0x3cb0
    cmpw	r3, r0
    fmul	f1, f1, f0
    stfd	f1, 8(r1)
    lwz	r5, 8(r1)
    rlwinm	r4, r5, 0xc, 0x15, 0x1f
    addi	r4, r4, -0x36
    bc      4, 0, _8008821c
    lfd	f0, -0x7568(r2)
    fmul	f1, f0, f1
    b       _800882dc
_8008821c:
    cmpwi	r4, 0x7ff
    bc      4, 2, _80088230
    lfd	f0, 8(r1)
    fadd	f1, f0, f0
    b       _800882dc
_80088230:
    add	r4, r4, r3
    cmpwi	r4, 0x7fe
    bc      4, 1, _80088254
    lfd	f1, -0x7560(r2)
    lfd	f2, 8(r1)
    bl      __fp_compare_greater_equal
    lfd	f0, -0x7560(r2)
    fmul	f1, f0, f1
    b       _800882dc
_80088254:
    cmpwi	r4, 0
    bc      4, 1, _80088274
    rlwinm	r3, r5, 0, 0xc, 0
    slwi	r0, r4, 0x14
    or	r0, r3, r0
    stw	r0, 8(r1)
    lfd	f1, 8(r1)
    b       _800882dc
_80088274:
    cmpwi	r4, -0x36
    bc      12, 1, _800882bc
    lis	r4, 1
    addi	r0, r4, -0x3cb0
    cmpw	r3, r0
    bc      4, 1, _800882a4
    lfd	f1, -0x7560(r2)
    lfd	f2, 8(r1)
    bl      __fp_compare_greater_equal
    lfd	f0, -0x7560(r2)
    fmul	f1, f0, f1
    b       _800882dc
_800882a4:
    lfd	f1, -0x7568(r2)
    lfd	f2, 8(r1)
    bl      __fp_compare_greater_equal
    lfd	f0, -0x7568(r2)
    fmul	f1, f0, f1
    b       _800882dc
_800882bc:
    addi	r0, r4, 0x36
    rlwinm	r3, r5, 0, 0xc, 0
    slwi	r0, r0, 0x14
    lfd	f1, -0x7558(r2)
    or	r0, r3, r0
    stw	r0, 8(r1)
    lfd	f0, 8(r1)
    fmul	f1, f1, f0
_800882dc:
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void modf(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    stfd	f1, 8(r1)
    lwz	r5, 8(r1)
    lwz	r6, 0xc(r1)
    rlwinm	r4, r5, 0xc, 0x15, 0x1f
    addi	r7, r4, -0x3ff
    cmpwi	r7, 0x14
    bc      4, 0, _80088378
    cmpwi	r7, 0
    bc      4, 0, _80088328
    rlwinm	r4, r5, 0, 0, 0
    li	r0, 0
    stw	r4, 0(r3)
    stw	r0, 4(r3)
    b       _800883e0
_80088328:
    lis	r4, 0x10
    addi	r0, r4, -1
    sraw	r4, r0, r7
    and	r0, r5, r4
    or.	r0, r6, r0
    bc      4, 2, _8008835c
    rlwinm	r4, r5, 0, 0, 0
    li	r0, 0
    stw	r4, 8(r1)
    stw	r0, 0xc(r1)
    stfd	f1, 0(r3)
    lfd	f1, 8(r1)
    b       _800883e0
_8008835c:
    andc	r4, r5, r4
    li	r0, 0
    stw	r4, 0(r3)
    stw	r0, 4(r3)
    lfd	f0, 0(r3)
    fsub	f1, f1, f0
    b       _800883e0
_80088378:
    cmpwi	r7, 0x33
    bc      4, 1, _8008839c
    rlwinm	r4, r5, 0, 0, 0
    li	r0, 0
    stw	r4, 8(r1)
    stw	r0, 0xc(r1)
    stfd	f1, 0(r3)
    lfd	f1, 8(r1)
    b       _800883e0
_8008839c:
    addi	r0, r7, -0x14
    li	r4, -1
    srw	r4, r4, r0
    and.	r0, r6, r4
    bc      4, 2, _800883cc
    rlwinm	r4, r5, 0, 0, 0
    li	r0, 0
    stw	r4, 8(r1)
    stw	r0, 0xc(r1)
    stfd	f1, 0(r3)
    lfd	f1, 8(r1)
    b       _800883e0
_800883cc:
    stw	r5, 0(r3)
    andc	r0, r6, r4
    stw	r0, 4(r3)
    lfd	f0, 0(r3)
    fsub	f1, f1, f0
_800883e0:
    addi	r1, r1, 0x10
    blr
}

asm void atan(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis	r3, 0x3fe9
    stfd	f1, 8(r1)
    stw	r0, 0x24(r1)
    addi	r0, r3, 0x21fb
    lwz	r3, 8(r1)
    clrlwi	r3, r3, 1
    cmpw	r3, r0
    bc      12, 1, _80088420
    lfd	f2, -0x7550(r2)
    li	r3, 0
    bl      fn_80087BA4
    b       _800884b0
_80088420:
    lis	r0, 0x7ff0
    cmpw	r3, r0
    bc      12, 0, _80088434
    fsub	f1, f1, f1
    b       _800884b0
_80088434:
    addi	r3, r1, 0x10
    bl      fn_800868BC
    clrlwi	r0, r3, 0x1e
    cmpwi	r0, 1
    bc      12, 2, _80088478
    bc      4, 0, _80088458
    cmpwi	r0, 0
    bc      4, 0, _80088464
    b       _800884a0
_80088458:
    cmpwi	r0, 3
    bc      4, 0, _800884a0
    b       _80088488
_80088464:
    lfd	f1, 0x10(r1)
    li	r3, 1
    lfd	f2, 0x18(r1)
    bl      fn_80087BA4
    b       _800884b0
_80088478:
    lfd	f1, 0x10(r1)
    lfd	f2, 0x18(r1)
    bl      MSL_strtod_nan
    b       _800884b0
_80088488:
    lfd	f1, 0x10(r1)
    li	r3, 1
    lfd	f2, 0x18(r1)
    bl      fn_80087BA4
    fneg	f1, f1
    b       _800884b0
_800884a0:
    lfd	f1, 0x10(r1)
    lfd	f2, 0x18(r1)
    bl      MSL_strtod_nan
    fneg	f1, f1
_800884b0:
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_800884C0(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis	r3, 0x3fe9
    stfd	f1, 8(r1)
    stw	r0, 0x24(r1)
    addi	r0, r3, 0x21fb
    lwz	r3, 8(r1)
    clrlwi	r3, r3, 1
    cmpw	r3, r0
    bc      12, 1, _800884f8
    lfd	f2, -0x7548(r2)
    li	r3, 1
    bl      fn_80087C44
    b       _80088528
_800884f8:
    lis	r0, 0x7ff0
    cmpw	r3, r0
    bc      12, 0, _8008850c
    fsub	f1, f1, f1
    b       _80088528
_8008850c:
    addi	r3, r1, 0x10
    bl      fn_800868BC
    rlwinm	r0, r3, 1, 0x1e, 0x1e
    lfd	f1, 0x10(r1)
    lfd	f2, 0x18(r1)
    subfic	r3, r0, 1
    bl      fn_80087C44
_80088528:
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr
}

asm void fn_80088538(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8008596C
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_80088558(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_80085C7C
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void expf(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      __msl_exp
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void __msl_fp_helper(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_80086008
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_800885B8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      __msl_fp_helper
    lwz	r0, 0x14(r1)
    frsp	f1, f1
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

asm void fn_800885DC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_800884C0
    lwz	r0, 0x14(r1)
    frsp	f1, f1
    mtlr	r0
    addi	r1, r1, 0x10
    blr
}

#pragma force_active off
