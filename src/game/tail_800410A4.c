// Tail of the GX SDK region: 0x800410A4-0x80041460.
// Carved from coarse/text_8003E344.c via asm transcription (nofralloc).
//
// fn_80041330/54/78/A4/C8/EC/10/34 are small trampolines that forward to
// game-side helpers (fn_80047608/fn_8004BDD8/fn_80056C64/criErr_CallErrCallback/
// fn_8004541C/fn_80045468) and return 0 — callback thunks registered from
// fn_800411F4. fn_80041458 is a this+0x58 accessor stub.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_80038A88(register void* p1, register void* p2);
extern void fn_8003E9EC(void); // sdata2-fetched fnptr, blrl'd
extern void fn_800424B8(void);
extern void fn_800424E8(void);
extern int fn_8004541C(register void* p1);
extern int fn_80045468(register void* p1);
extern void svmUnlockServer_wrapper(void);
extern void svmLockServer_wrapper(void);
extern void fn_80046758(void);
extern void criErr_CallErrCallback(register void* p1);
extern void fn_800475C0(void);
extern void fn_80047578(void);
extern void fn_80047608(void);
extern void fn_8004B79C(void);
extern void fn_8004B7A0(void);
extern void fn_8004BDD8(void);
extern void fn_8004E580(void);
extern void fn_8004EF48(register void* p1, register u32 p2);
extern void fn_8004EF68(void);
extern void fn_8004EF88(void);
extern void fn_8004F6B0(void);
extern void fn_8004F74C(void);
extern void fn_800566BC(register void* p1, register u32 p2);
extern void fn_80056C64(void);
extern void fn_80057378(void);
extern void fn_8005741C(void);
extern void fn_80057CC4(void);
extern void fn_80057D0C(void);
extern void fn_80058630(void);
extern void fn_80058680(void);
extern void fn_8005870C(void);
extern void fn_80058754(void);
extern void fn_80058B54(void);
extern void fn_80058BFC(void);
extern void fn_8005912C(register u32 p1, register u32 p2, register void* p3, register u32 p4);
extern void SVM_DelCbSvr(register u32 p1, register void* p2);
extern void SVM_SetCbSvr_2(register u32 p1, register void* p2, register u32 p3);
extern void memset(register void* dst, register int v, register unsigned long n);
extern unsigned char lbl_80090010[8];
extern unsigned char lbl_80178C18[144];
extern unsigned char lbl_80178CA8[16];

#pragma push
#pragma force_active on
int fn_80041330(void);
int fn_80041354(void);
int fn_80041378(void);
int fn_800413A4(void);
int fn_800413C8(void* a);
int fn_800413EC(void* a);

asm void fn_800410A4(void)
{
    nofralloc
    mflr    r0
    lis     r3, lbl_80178C18@ha
    stw     r0, 4(r1)
    addi    r5, r3, lbl_80178C18@l
    addi    r3, r5, 0x30
    stwu    r1, -8(r1)
    li      r4, 0
    lfs     f0, -0x7c68(r2)
    stfs    f0, 0x30(r5)
    stfs    f0, 0x34(r5)
    stfs    f0, 0x38(r5)
    stfs    f0, 0x3c(r5)
    stfs    f0, 0x40(r5)
    stfs    f0, 0x44(r5)
    stfs    f0, 0x48(r5)
    stfs    f0, 0x4c(r5)
    stfs    f0, 0x50(r5)
    stfs    f0, 0x54(r5)
    stfs    f0, 0x58(r5)
    stfs    f0, 0x5c(r5)
    stfs    f0, 0x60(r5)
    stfs    f0, 0x64(r5)
    stfs    f0, 0x68(r5)
    stfs    f0, 0x6c(r5)
    lfs     f0, 0x74(r5)
    stfs    f0, 0x30(r5)
    lfs     f0, 0x78(r5)
    stfs    f0, 0x38(r5)
    lfs     f0, 0x7c(r5)
    stfs    f0, 0x44(r5)
    lfs     f0, 0x80(r5)
    stfs    f0, 0x48(r5)
    lfs     f0, 0x84(r5)
    stfs    f0, 0x58(r5)
    lfs     f0, 0x88(r5)
    stfs    f0, 0x5c(r5)
    lfs     f0, -0x7c48(r2)
    stfs    f0, 0x68(r5)
    bl      fn_80038A88
    lwz     r12, -0x774c(r13)
    mtlr    r12
    blrl
    lwz     r0, 0xc(r1)
    addi    r1, r1, 8
    mtlr    r0
    blr
}

asm void fn_8004115C(register u32 a)
{
    nofralloc
    stw     r3, -0x7754(r13)
    blr
}

asm void fn_80041164(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    lis     r3, lbl_80178CA8@ha
    stw     r0, 0x14(r1)
    stw     r31, 0xc(r1)
    addi    r31, r3, lbl_80178CA8@l
    lwz     r3, 0(r31)
    addic.  r0, r3, -1
    stw     r0, 0(r31)
    bne     _800411e0
    bl      fn_8004EF68
    bl      fn_8004F6B0
    bl      fn_8004B79C
    bl      fn_80057378
    bl      svmLockServer_wrapper
    li      r3, 2
    li      r4, 1
    bl      SVM_DelCbSvr
    lwz     r4, 0xc(r31)
    li      r3, 4
    bl      SVM_DelCbSvr
    lwz     r4, 8(r31)
    li      r3, 5
    bl      SVM_DelCbSvr
    bl      fn_80058B54
    bl      fn_800424B8
    bl      fn_80047578
    bl      fn_80057CC4
    bl      fn_80058630
    bl      fn_8005870C
    bl      svmUnlockServer_wrapper
_800411e0:
    lwz     r0, 0x14(r1)
    lwz     r31, 0xc(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm void fn_800411F4(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    lis     r3, lbl_80090010@ha
    lis     r4, lbl_80178CA8@ha
    stw     r0, 0x14(r1)
    addi    r3, r3, lbl_80090010@l
    lwz     r3, 0(r3)
    stw     r31, 0xc(r1)
    addi    r31, r4, lbl_80178CA8@l
    lwz     r0, 0(r31)
    cmpwi   r0, 0
    bne     _80041310
    bl      fn_80046758
    bl      svmLockServer_wrapper
    bl      fn_80058754
    bl      fn_80058680
    bl      fn_80057D0C
    bl      fn_800475C0
    bl      fn_8004B7A0
    bl      fn_800424E8
    bl      fn_8004F74C
    bl      fn_8004EF88
    bl      fn_8005741C
    bl      fn_80058BFC
    lis     r3, fn_800413EC@ha
    li      r4, 0
    addi    r3, r3, fn_800413EC@l
    bl      fn_8004EF48
    lis     r3, fn_800413C8@ha
    li      r4, 0
    addi    r3, r3, fn_800413C8@l
    bl      fn_800566BC
    addi    r3, r31, 0x14
    li      r4, 0
    li      r5, 0xc00
    bl      memset
    bl      fn_8004E580
    cmpwi   r3, 1
    bne     _800412ec
    lis     r3, -0x7fed
    lwz     r0, -0x4918(r3)
    cmpwi   r0, 1
    bne     _800412ec
    lis     r4, fn_80041354@ha
    li      r3, 2
    addi    r5, r4, fn_80041354@l
    li      r6, 0
    li      r4, 1
    bl      fn_8005912C
    lis     r4, fn_80041330@ha
    li      r3, 4
    addi    r4, r4, fn_80041330@l
    li      r5, 0
    bl      SVM_SetCbSvr_2
    lis     r4, fn_800413A4@ha
    stw     r3, 0xc(r31)
    addi    r4, r4, fn_800413A4@l
    li      r3, 5
    li      r5, 0
    bl      SVM_SetCbSvr_2
    stw     r3, 8(r31)
    b       _80041304
_800412ec:
    lis     r4, fn_80041378@ha
    li      r3, 5
    addi    r4, r4, fn_80041378@l
    li      r5, 0
    bl      SVM_SetCbSvr_2
    stw     r3, 8(r31)
_80041304:
    li      r0, 0
    stw     r0, 0x10(r31)
    bl      svmUnlockServer_wrapper
_80041310:
    lwz     r3, 0(r31)
    addi    r0, r3, 1
    stw     r0, 0(r31)
    lwz     r31, 0xc(r1)
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm int fn_80041330(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    bl      fn_80047608
    lwz     r0, 0x14(r1)
    li      r3, 0
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm int fn_80041354(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    bl      fn_8004BDD8
    lwz     r0, 0x14(r1)
    li      r3, 0
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm int fn_80041378(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    bl      fn_8004BDD8
    bl      fn_80047608
    bl      fn_80056C64
    lwz     r0, 0x14(r1)
    li      r3, 0
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm int fn_800413A4(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    bl      fn_80056C64
    lwz     r0, 0x14(r1)
    li      r3, 0
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm int fn_800413C8(register void* a)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    mr      r3, r4
    stw     r0, 0x14(r1)
    bl      criErr_CallErrCallback
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm int fn_800413EC(register void* a)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    mr      r3, r4
    stw     r0, 0x14(r1)
    bl      criErr_CallErrCallback
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm int fn_80041410(register void* a)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    lwz     r3, 4(r3)
    bl      fn_8004541C
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm int fn_80041434(register void* a)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    lwz     r3, 4(r3)
    bl      fn_80045468
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm void* fn_80041458(register void* a)
{
    nofralloc
    addi    r3, r3, 0x58
    blr
}

#pragma pop
