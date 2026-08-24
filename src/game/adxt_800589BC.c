#pragma push
#pragma force_active on

extern void SVM_ReportErrorString(void);
extern void svmErrPrintf(void);
extern void svmUnlockServer(void);
extern void svmLockServer(void);
extern void sprintf(void);
extern void fn_8008077C(void);
extern void strncpy(void);
extern void fn_80084FDC(void);
extern void memcpy(void);
extern void memset(void);
extern void strlen(void);
extern unsigned char E0040301_handl_is_null_str_2[120];
extern unsigned char E0040302_handl_is_null_str_2[24];
extern unsigned char E0092912_handl_is_null_str_2[24];
extern unsigned char E01100305_handl_is_null_str[152];
extern unsigned char E01100306_handl_is_null_str[25];
extern unsigned char _SVM_DelCbSvr_illegal_id_str[32];
extern unsigned char _SVM_SetCbSvr_too_many_server_function_str[52];
extern unsigned char lbl_80092384[288];
extern unsigned char lbl_8018FEB0[48];
extern unsigned char lbl_8018FEE0[128];
extern unsigned char lbl_8018FF60[8];
extern unsigned char lbl_8018FF78[512];
extern unsigned char lbl_80190178[4];
extern unsigned char lbl_8019017C[2548];

asm void svm_ringbuf_read(void)
{
    nofralloc
    lwz	r7, 0(r3)
    lwz	r0, 4(r3)
    stw	r7, 0(r5)
    stw	r0, 4(r5)
    lwz	r0, 4(r5)
    stw	r0, 4(r6)
    lwz	r0, 4(r5)
    cmpw	r0, r4
    ble     _800589e4
    stw	r4, 4(r5)
_800589e4:
    lwz	r3, 4(r5)
    lwz	r0, 4(r6)
    subf	r0, r3, r0
    stw	r0, 4(r6)
    lwz	r0, 4(r6)
    cmpwi	r0, 0
    bne     _80058a0c
    li	r0, 0
    stw	r0, 0(r6)
    blr	
_80058a0c:
    lwz	r3, 0(r5)
    lwz	r0, 4(r5)
    add	r0, r3, r0
    stw	r0, 0(r6)
    blr	
}

asm void fn_80058A20(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      SVM_ReportErrorString
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80058A40(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r4, lbl_8018FEB0@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r4, lbl_8018FEB0@l
    stw	r30, 8(r1)
    mr	r30, r3
    lwz	r12, 0x2c(r31)
    cmplwi	r12, 0
    beq     _80058a7c
    mtctr	r12
    bctrl	
    mr	r30, r3
    b     _80058b38
_80058a7c:
    lwz	r12, 0xc0(r31)
    cmplwi	r12, 0
    beq     _80058ab8
    addi	r3, r31, 0xc0
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _80058aac
    li	r0, 1
    stw	r0, 8(r31)
_80058aac:
    lwz	r3, 4(r31)
    addi	r0, r3, 1
    stw	r0, 4(r31)
_80058ab8:
    lwz	r3, 0(r30)
    li	r0, 1
    stw	r0, 0(r30)
    subfic	r4, r3, 1
    addi	r3, r3, -1
    lwz	r0, 0xb8(r31)
    or	r3, r4, r3
    srwi	r30, r3, 0x1f
    cmplwi	r0, 0
    beq     _80058b38
    lwz	r3, 4(r31)
    addi	r0, r3, -1
    stw	r0, 4(r31)
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _80058b24
    lwz	r0, 8(r31)
    cmpwi	r0, 1
    beq     _80058b1c
    lis     r3, lbl_80092384@ha
    lwz	r4, 8(r31)
    addi	r3, r3, lbl_80092384@l
    li	r5, 1
    crxor	6, 6, 6
    bl      svmErrPrintf
_80058b1c:
    li	r0, 0
    stw	r0, 8(r31)
_80058b24:
    lwz	r12, 0xb8(r31)
    addi	r3, r31, 0xb8
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_80058b38:
    lwz	r0, 0x14(r1)
    mr	r3, r30
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80058B54(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_8018FEB0@l
    lwz	r3, 0(r31)
    addi	r0, r3, -1
    stw	r0, 0(r31)
    lwz	r0, 0(r31)
    cmpwi	r0, 0
    bne     _80058be8
    addi	r3, r31, 0x288
    li	r4, 0
    li	r5, 0x20
    bl      memset
    addi	r3, r31, 0xc0
    li	r4, 0
    li	r5, 8
    bl      memset
    addi	r3, r31, 0xb8
    li	r4, 0
    li	r5, 8
    bl      memset
    li	r0, 0
    addi	r6, r31, 0x2a8
    stw	r0, 0(r6)
    addi	r3, r31, 0xb0
    li	r4, 0
    li	r5, 8
    stw	r0, 4(r6)
    stw	r0, 8(r6)
    stw	r0, 0xc(r6)
    stw	r0, 0x10(r6)
    stw	r0, 0x14(r6)
    stw	r0, 0x2c(r31)
    bl      memset
_80058be8:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80058BFC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_8018FEB0@l
    lwz	r0, 0(r31)
    cmpwi	r0, 0
    bne     _80058c74
    addi	r3, r31, 0x288
    li	r4, 0
    li	r5, 0x20
    bl      memset
    addi	r3, r31, 0xc0
    li	r4, 0
    li	r5, 8
    bl      memset
    addi	r3, r31, 0xb8
    li	r4, 0
    li	r5, 8
    bl      memset
    li	r0, 0
    addi	r3, r31, 0x2a8
    stw	r0, 0(r3)
    stw	r0, 4(r3)
    stw	r0, 8(r3)
    stw	r0, 0xc(r3)
    stw	r0, 0x10(r3)
    stw	r0, 0x14(r3)
    stw	r0, 0x2c(r31)
_80058c74:
    lwz	r3, 0(r31)
    addi	r0, r3, 1
    stw	r0, 0(r31)
    lwz	r31, 0xc(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80058C94(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x34(r1)
    stmw	r25, 0x14(r1)
    addi	r29, r3, lbl_8018FEB0@l
    li	r28, 0
    li	r30, 1
    addi	r26, r29, 0x108
    addi	r25, r29, 0x288
    mr	r27, r28
    mr	r31, r28
    addi	r26, r26, 0x120
_80058cc8:
    lwz	r12, 0(r26)
    cmplwi	r12, 0
    beq     _80058cec
    stw	r30, 0x18(r25)
    lwz	r3, 4(r26)
    mtctr	r12
    bctrl	
    or	r28, r28, r3
    stw	r31, 0x18(r25)
_80058cec:
    addi	r27, r27, 1
    addi	r26, r26, 8
    cmpwi	r27, 6
    blt     _80058cc8
    addi	r5, r29, 0x2a8
    mr	r3, r28
    lwz	r4, 0x18(r5)
    addi	r0, r4, 1
    stw	r0, 0x18(r5)
    lmw	r25, 0x14(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80058D24(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x34(r1)
    stmw	r25, 0x14(r1)
    addi	r29, r3, lbl_8018FEB0@l
    li	r28, 0
    li	r30, 1
    addi	r26, r29, 0x108
    addi	r25, r29, 0x288
    mr	r27, r28
    mr	r31, r28
    addi	r26, r26, 0xf0
_80058d58:
    lwz	r12, 0(r26)
    cmplwi	r12, 0
    beq     _80058d7c
    stw	r30, 0x14(r25)
    lwz	r3, 4(r26)
    mtctr	r12
    bctrl	
    or	r28, r28, r3
    stw	r31, 0x14(r25)
_80058d7c:
    addi	r27, r27, 1
    addi	r26, r26, 8
    cmpwi	r27, 6
    blt     _80058d58
    addi	r5, r29, 0x2a8
    mr	r3, r28
    lwz	r4, 0x14(r5)
    addi	r0, r4, 1
    stw	r0, 0x14(r5)
    lmw	r25, 0x14(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80058DB4(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x34(r1)
    stmw	r25, 0x14(r1)
    addi	r29, r3, lbl_8018FEB0@l
    li	r28, 0
    li	r30, 1
    addi	r26, r29, 0x108
    addi	r25, r29, 0x288
    mr	r27, r28
    mr	r31, r28
    addi	r26, r26, 0xc0
_80058de8:
    lwz	r12, 0(r26)
    cmplwi	r12, 0
    beq     _80058e0c
    stw	r30, 0x10(r25)
    lwz	r3, 4(r26)
    mtctr	r12
    bctrl	
    or	r28, r28, r3
    stw	r31, 0x10(r25)
_80058e0c:
    addi	r27, r27, 1
    addi	r26, r26, 8
    cmpwi	r27, 6
    blt     _80058de8
    addi	r5, r29, 0x2a8
    mr	r3, r28
    lwz	r4, 0x10(r5)
    addi	r0, r4, 1
    stw	r0, 0x10(r5)
    lmw	r25, 0x14(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80058E44(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x34(r1)
    stmw	r25, 0x14(r1)
    addi	r29, r3, lbl_8018FEB0@l
    li	r28, 0
    li	r30, 1
    addi	r26, r29, 0x108
    addi	r25, r29, 0x288
    mr	r27, r28
    mr	r31, r28
    addi	r26, r26, 0x60
_80058e78:
    lwz	r12, 0(r26)
    cmplwi	r12, 0
    beq     _80058e9c
    stw	r30, 8(r25)
    lwz	r3, 4(r26)
    mtctr	r12
    bctrl	
    or	r28, r28, r3
    stw	r31, 8(r25)
_80058e9c:
    addi	r27, r27, 1
    addi	r26, r26, 8
    cmpwi	r27, 6
    blt     _80058e78
    addi	r5, r29, 0x2a8
    mr	r3, r28
    lwz	r4, 8(r5)
    addi	r0, r4, 1
    stw	r0, 8(r5)
    lmw	r25, 0x14(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80058ED4(void)
{
    nofralloc
    lis	r5, -0x7fe7
    stwu	r3, -0x98(r5)
    stw	r4, 4(r5)
    blr	
}

asm void fn_80058EE4(void)
{
    nofralloc
    lis	r5, -0x7fe7
    stwu	r3, -0x90(r5)
    stw	r4, 4(r5)
    blr	
}

asm void fn_80058EF4(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r5, lbl_8018FEB0@ha
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r5, lbl_8018FEB0@l
    stw	r30, 0x18(r1)
    mr	r30, r4
    stw	r29, 0x14(r1)
    mr	r29, r3
    lwz	r12, 0xc0(r31)
    cmplwi	r12, 0
    beq     _80058f58
    addi	r3, r31, 0xc0
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _80058f4c
    li	r0, 1
    stw	r0, 8(r31)
_80058f4c:
    lwz	r3, 4(r31)
    addi	r0, r3, 1
    stw	r0, 4(r31)
_80058f58:
    lwz	r0, 0xb8(r31)
    addi	r3, r31, 0xb0
    stw	r29, 0xb0(r31)
    cmplwi	r0, 0
    stw	r30, 4(r3)
    beq     _80058fc8
    lwz	r3, 4(r31)
    addi	r0, r3, -1
    stw	r0, 4(r31)
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _80058fb4
    lwz	r0, 8(r31)
    cmpwi	r0, 1
    beq     _80058fac
    lis     r3, lbl_80092384@ha
    lwz	r4, 8(r31)
    addi	r3, r3, lbl_80092384@l
    li	r5, 1
    crxor	6, 6, 6
    bl      svmErrPrintf
_80058fac:
    li	r0, 0
    stw	r0, 8(r31)
_80058fb4:
    lwz	r12, 0xb8(r31)
    addi	r3, r31, 0xb8
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_80058fc8:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80058FE4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r4, lbl_8018FF78@ha
    stw	r0, 0x14(r1)
    slwi	r0, r3, 3
    addi	r3, r4, lbl_8018FF78@l
    lwzx	r12, r3, r0
    cmplwi	r12, 0
    beq     _80059018
    add	r3, r3, r0
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_80059018:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80059028(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r6, lbl_8018FEB0@ha
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r6, lbl_8018FEB0@l
    stw	r30, 0x18(r1)
    mr	r30, r5
    stw	r29, 0x14(r1)
    mr	r29, r4
    stw	r28, 0x10(r1)
    mr	r28, r3
    lwz	r12, 0xc0(r31)
    cmplwi	r12, 0
    beq     _80059094
    addi	r3, r31, 0xc0
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _80059088
    li	r0, 1
    stw	r0, 8(r31)
_80059088:
    lwz	r3, 4(r31)
    addi	r0, r3, 1
    stw	r0, 4(r31)
_80059094:
    lwz	r0, 0xb8(r31)
    slwi	r4, r28, 3
    addi	r3, r31, 0xc8
    stwx	r29, r3, r4
    add	r3, r3, r4
    cmplwi	r0, 0
    stw	r30, 4(r3)
    beq     _8005910c
    lwz	r3, 4(r31)
    addi	r0, r3, -1
    stw	r0, 4(r31)
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _800590f8
    lwz	r0, 8(r31)
    cmpwi	r0, 1
    beq     _800590f0
    lis     r3, lbl_80092384@ha
    lwz	r4, 8(r31)
    addi	r3, r3, lbl_80092384@l
    li	r5, 1
    crxor	6, 6, 6
    bl      svmErrPrintf
_800590f0:
    li	r0, 0
    stw	r0, 8(r31)
_800590f8:
    lwz	r12, 0xb8(r31)
    addi	r3, r31, 0xb8
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_8005910c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8005912C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis	r7, -0x7ff7
    stw	r0, 0x24(r1)
    stmw	r26, 8(r1)
    or.	r27, r4, r4
    lis     r4, lbl_8018FEB0@ha
    mr	r26, r3
    mr	r28, r5
    mr	r29, r6
    addi	r30, r7, 0x2350
    addi	r31, r4, lbl_8018FEB0@l
    blt     _80059168
    cmpwi	r27, 6
    blt     _80059198
_80059168:
    addi	r3, r31, 0x30
    addi	r4, r30, 0xd0
    li	r5, 0x7f
    bl      strncpy
    lwz	r12, 0xb0(r31)
    cmplwi	r12, 0
    beq     _80059198
    addi	r3, r31, 0xb0
    addi	r4, r31, 0x30
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_80059198:
    cmpwi	r26, 0
    blt     _800591a8
    cmpwi	r27, 8
    blt     _800591d8
_800591a8:
    addi	r3, r31, 0x30
    addi	r4, r30, 0xf4
    li	r5, 0x7f
    bl      strncpy
    lwz	r12, 0xb0(r31)
    cmplwi	r12, 0
    beq     _800591d8
    addi	r3, r31, 0xb0
    addi	r4, r31, 0x30
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_800591d8:
    lwz	r12, 0xc0(r31)
    cmplwi	r12, 0
    beq     _80059214
    addi	r3, r31, 0xc0
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _80059208
    li	r0, 1
    stw	r0, 8(r31)
_80059208:
    lwz	r3, 4(r31)
    addi	r0, r3, 1
    stw	r0, 4(r31)
_80059214:
    mulli	r4, r26, 0x30
    slwi	r0, r27, 3
    addi	r3, r31, 0x108
    add	r27, r4, r0
    add	r27, r3, r27
    lwz	r0, 0(r27)
    cmplwi	r0, 0
    beq     _80059264
    addi	r3, r31, 0x30
    addi	r4, r30, 0x11c
    li	r5, 0x7f
    bl      strncpy
    lwz	r12, 0xb0(r31)
    cmplwi	r12, 0
    beq     _80059264
    addi	r3, r31, 0xb0
    addi	r4, r31, 0x30
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_80059264:
    lwz	r0, 0xb8(r31)
    stw	r28, 0(r27)
    cmplwi	r0, 0
    stw	r29, 4(r27)
    beq     _800592cc
    lwz	r3, 4(r31)
    addi	r0, r3, -1
    stw	r0, 4(r31)
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _800592b8
    lwz	r0, 8(r31)
    cmpwi	r0, 1
    beq     _800592b0
    lwz	r4, 8(r31)
    addi	r3, r30, 0x34
    li	r5, 1
    crxor	6, 6, 6
    bl      svmErrPrintf
_800592b0:
    li	r0, 0
    stw	r0, 8(r31)
_800592b8:
    lwz	r12, 0xb8(r31)
    addi	r3, r31, 0xb8
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_800592cc:
    lmw	r26, 8(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void SVM_DelCbSvr(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    or.	r30, r4, r4
    lis     r4, lbl_8018FEB0@ha
    stw	r29, 0x14(r1)
    mr	r29, r3
    addi	r31, r4, lbl_8018FEB0@l
    blt     _80059314
    cmpwi	r30, 6
    blt     _80059348
_80059314:
    lis     r4, _SVM_DelCbSvr_illegal_id_str@ha
    addi	r3, r31, 0x30
    addi	r4, r4, _SVM_DelCbSvr_illegal_id_str@l
    li	r5, 0x7f
    bl      strncpy
    lwz	r12, 0xb0(r31)
    cmplwi	r12, 0
    beq     _80059348
    addi	r3, r31, 0xb0
    addi	r4, r31, 0x30
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_80059348:
    lwz	r12, 0xc0(r31)
    cmplwi	r12, 0
    beq     _80059384
    addi	r3, r31, 0xc0
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _80059378
    li	r0, 1
    stw	r0, 8(r31)
_80059378:
    lwz	r3, 4(r31)
    addi	r0, r3, 1
    stw	r0, 4(r31)
_80059384:
    mulli	r3, r29, 0x30
    slwi	r7, r30, 3
    addi	r5, r31, 0x108
    lwz	r0, 0xb8(r31)
    li	r6, 0
    add	r4, r3, r7
    add	r3, r5, r3
    stwx	r6, r5, r4
    add	r3, r3, r7
    cmplwi	r0, 0
    stw	r6, 4(r3)
    beq     _8005940c
    lwz	r3, 4(r31)
    addi	r0, r3, -1
    stw	r0, 4(r31)
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _800593f8
    lwz	r0, 8(r31)
    cmpwi	r0, 1
    beq     _800593f0
    lis     r3, lbl_80092384@ha
    lwz	r4, 8(r31)
    addi	r3, r3, lbl_80092384@l
    li	r5, 1
    crxor	6, 6, 6
    bl      svmErrPrintf
_800593f0:
    li	r0, 0
    stw	r0, 8(r31)
_800593f8:
    lwz	r12, 0xb8(r31)
    addi	r3, r31, 0xb8
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_8005940c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void SVM_SetCbSvr_2(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r6, lbl_8018FEB0@ha
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r6, lbl_8018FEB0@l
    stw	r30, 0x18(r1)
    mr	r30, r3
    stw	r29, 0x14(r1)
    mr	r29, r5
    stw	r28, 0x10(r1)
    mr	r28, r4
    lwz	r12, 0xc0(r31)
    cmplwi	r12, 0
    beq     _80059494
    addi	r3, r31, 0xc0
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _80059488
    li	r0, 1
    stw	r0, 8(r31)
_80059488:
    lwz	r3, 4(r31)
    addi	r0, r3, 1
    stw	r0, 4(r31)
_80059494:
    mulli	r3, r30, 0x30
    addi	r4, r31, 0x108
    li	r0, 6
    li	r30, 0
    add	r4, r4, r3
    mtctr	r0
_800594ac:
    lwz	r0, 0(r4)
    cmplwi	r0, 0
    bne     _800594c4
    stw	r28, 0(r4)
    stw	r29, 4(r4)
    b     _800594d0
_800594c4:
    addi	r4, r4, 8
    addi	r30, r30, 1
    bdnz     _800594ac
_800594d0:
    cmpwi	r30, 6
    bne     _8005950c
    lis     r4, _SVM_SetCbSvr_too_many_server_function_str@ha
    addi	r3, r31, 0x30
    addi	r4, r4, _SVM_SetCbSvr_too_many_server_function_str@l
    li	r5, 0x7f
    bl      strncpy
    lwz	r12, 0xb0(r31)
    cmplwi	r12, 0
    beq     _8005950c
    addi	r3, r31, 0xb0
    addi	r4, r31, 0x30
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_8005950c:
    lwz	r0, 0xb8(r31)
    cmplwi	r0, 0
    beq     _80059570
    lwz	r3, 4(r31)
    addi	r0, r3, -1
    stw	r0, 4(r31)
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _8005955c
    lwz	r0, 8(r31)
    cmpwi	r0, 1
    beq     _80059554
    lis     r3, lbl_80092384@ha
    lwz	r4, 8(r31)
    addi	r3, r3, lbl_80092384@l
    li	r5, 1
    crxor	6, 6, 6
    bl      svmErrPrintf
_80059554:
    li	r0, 0
    stw	r0, 8(r31)
_8005955c:
    lwz	r12, 0xb8(r31)
    addi	r3, r31, 0xb8
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_80059570:
    cmpwi	r30, 6
    bne     _80059580
    li	r3, -1
    b     _80059584
_80059580:
    mr	r3, r30
_80059584:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void SVM_ReportErrorString(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r5, lbl_8018FEE0@ha
    mr	r4, r3
    stw	r0, 0x14(r1)
    addi	r3, r5, lbl_8018FEE0@l
    li	r5, 0x7f
    bl      strncpy
    lis     r3, lbl_8018FF60@ha
    addi	r5, r3, lbl_8018FF60@l
    lwz	r12, 0(r5)
    cmplwi	r12, 0
    beq     _800595ec
    lis     r3, lbl_8018FEE0@ha
    addi	r4, r3, lbl_8018FEE0@l
    lwz	r3, 4(r5)
    mtctr	r12
    bctrl	
_800595ec:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void svmErrPrintf(void)
{
    nofralloc
    stwu	r1, -0x80(r1)
    mflr	r0
    stw	r0, 0x84(r1)
    stw	r31, 0x7c(r1)
    mr	r31, r3
    bne	cr1, _80059634
    stfd	f1, 0x28(r1)
    stfd	f2, 0x30(r1)
    stfd	f3, 0x38(r1)
    stfd	f4, 0x40(r1)
    stfd	f5, 0x48(r1)
    stfd	f6, 0x50(r1)
    stfd	f7, 0x58(r1)
    stfd	f8, 0x60(r1)
_80059634:
    lis     r11, lbl_8018FEE0@ha
    stw	r4, 0xc(r1)
    addi	r0, r11, lbl_8018FEE0@l
    li	r4, 0
    stw	r3, 8(r1)
    mr	r3, r0
    stw	r5, 0x10(r1)
    li	r5, 0x80
    stw	r6, 0x14(r1)
    stw	r7, 0x18(r1)
    stw	r8, 0x1c(r1)
    stw	r9, 0x20(r1)
    stw	r10, 0x24(r1)
    bl      memset
    addi	r6, r1, 0x88
    addi	r0, r1, 8
    lis	r4, 0x100
    lis     r3, lbl_8018FEE0@ha
    stw	r4, 0x68(r1)
    addi	r5, r1, 0x68
    addi	r3, r3, lbl_8018FEE0@l
    mr	r4, r31
    stw	r6, 0x6c(r1)
    stw	r0, 0x70(r1)
    bl      fn_8008077C
    lis     r3, lbl_8018FF60@ha
    addi	r5, r3, lbl_8018FF60@l
    lwz	r12, 0(r5)
    cmplwi	r12, 0
    beq     _800596c0
    lis     r3, lbl_8018FEE0@ha
    addi	r4, r3, lbl_8018FEE0@l
    lwz	r3, 4(r5)
    mtctr	r12
    bctrl	
_800596c0:
    lwz	r0, 0x84(r1)
    lwz	r31, 0x7c(r1)
    mtlr	r0
    addi	r1, r1, 0x80
    blr	
}

asm void fn_800596D4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_8018FEB0@l
    lwz	r0, 0xb8(r31)
    cmplwi	r0, 0
    beq     _80059750
    lwz	r3, 4(r31)
    addi	r0, r3, -1
    stw	r0, 4(r31)
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _8005973c
    lwz	r0, 8(r31)
    cmpwi	r0, 5
    beq     _80059734
    lis     r3, lbl_80092384@ha
    lwz	r4, 8(r31)
    addi	r3, r3, lbl_80092384@l
    li	r5, 5
    crxor	6, 6, 6
    bl      svmErrPrintf
_80059734:
    li	r0, 0
    stw	r0, 8(r31)
_8005973c:
    lwz	r12, 0xb8(r31)
    addi	r3, r31, 0xb8
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_80059750:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80059764(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_8018FEB0@l
    lwz	r0, 0xb8(r31)
    cmplwi	r0, 0
    beq     _800597e0
    lwz	r3, 4(r31)
    addi	r0, r3, -1
    stw	r0, 4(r31)
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _800597cc
    lwz	r0, 8(r31)
    cmpwi	r0, 4
    beq     _800597c4
    lis     r3, lbl_80092384@ha
    lwz	r4, 8(r31)
    addi	r3, r3, lbl_80092384@l
    li	r5, 4
    crxor	6, 6, 6
    bl      svmErrPrintf
_800597c4:
    li	r0, 0
    stw	r0, 8(r31)
_800597cc:
    lwz	r12, 0xb8(r31)
    addi	r3, r31, 0xb8
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_800597e0:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800597F4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_8018FEB0@l
    lwz	r0, 0xb8(r31)
    cmplwi	r0, 0
    beq     _80059870
    lwz	r3, 4(r31)
    addi	r0, r3, -1
    stw	r0, 4(r31)
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _8005985c
    lwz	r0, 8(r31)
    cmpwi	r0, 3
    beq     _80059854
    lis     r3, lbl_80092384@ha
    lwz	r4, 8(r31)
    addi	r3, r3, lbl_80092384@l
    li	r5, 3
    crxor	6, 6, 6
    bl      svmErrPrintf
_80059854:
    li	r0, 0
    stw	r0, 8(r31)
_8005985c:
    lwz	r12, 0xb8(r31)
    addi	r3, r31, 0xb8
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_80059870:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80059884(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_8018FEB0@l
    lwz	r0, 0xb8(r31)
    cmplwi	r0, 0
    beq     _80059900
    lwz	r3, 4(r31)
    addi	r0, r3, -1
    stw	r0, 4(r31)
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _800598ec
    lwz	r0, 8(r31)
    cmpwi	r0, 2
    beq     _800598e4
    lis     r3, lbl_80092384@ha
    lwz	r4, 8(r31)
    addi	r3, r3, lbl_80092384@l
    li	r5, 2
    crxor	6, 6, 6
    bl      svmErrPrintf
_800598e4:
    li	r0, 0
    stw	r0, 8(r31)
_800598ec:
    lwz	r12, 0xb8(r31)
    addi	r3, r31, 0xb8
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_80059900:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80059914(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_8018FEB0@l
    lwz	r12, 0xc0(r31)
    cmplwi	r12, 0
    beq     _80059968
    addi	r3, r31, 0xc0
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _8005995c
    li	r0, 5
    stw	r0, 8(r31)
_8005995c:
    lwz	r3, 4(r31)
    addi	r0, r3, 1
    stw	r0, 4(r31)
_80059968:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8005997C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_8018FEB0@l
    lwz	r12, 0xc0(r31)
    cmplwi	r12, 0
    beq     _800599d0
    addi	r3, r31, 0xc0
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _800599c4
    li	r0, 4
    stw	r0, 8(r31)
_800599c4:
    lwz	r3, 4(r31)
    addi	r0, r3, 1
    stw	r0, 4(r31)
_800599d0:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800599E4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_8018FEB0@l
    lwz	r12, 0xc0(r31)
    cmplwi	r12, 0
    beq     _80059a38
    addi	r3, r31, 0xc0
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _80059a2c
    li	r0, 3
    stw	r0, 8(r31)
_80059a2c:
    lwz	r3, 4(r31)
    addi	r0, r3, 1
    stw	r0, 4(r31)
_80059a38:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80059A4C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_8018FEB0@l
    lwz	r12, 0xc0(r31)
    cmplwi	r12, 0
    beq     _80059aa0
    addi	r3, r31, 0xc0
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _80059a94
    li	r0, 2
    stw	r0, 8(r31)
_80059a94:
    lwz	r3, 4(r31)
    addi	r0, r3, 1
    stw	r0, 4(r31)
_80059aa0:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void svmUnlockServer(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_8018FEB0@l
    lwz	r0, 0xb8(r31)
    cmplwi	r0, 0
    beq     _80059b30
    lwz	r3, 4(r31)
    addi	r0, r3, -1
    stw	r0, 4(r31)
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _80059b1c
    lwz	r0, 8(r31)
    cmpwi	r0, 1
    beq     _80059b14
    lis     r3, lbl_80092384@ha
    lwz	r4, 8(r31)
    addi	r3, r3, lbl_80092384@l
    li	r5, 1
    crxor	6, 6, 6
    bl      svmErrPrintf
_80059b14:
    li	r0, 0
    stw	r0, 8(r31)
_80059b1c:
    lwz	r12, 0xb8(r31)
    addi	r3, r31, 0xb8
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
_80059b30:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void svmLockServer(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8018FEB0@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_8018FEB0@l
    lwz	r12, 0xc0(r31)
    cmplwi	r12, 0
    beq     _80059b98
    addi	r3, r31, 0xc0
    lwz	r3, 4(r3)
    mtctr	r12
    bctrl	
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _80059b8c
    li	r0, 1
    stw	r0, 8(r31)
_80059b8c:
    lwz	r3, 4(r31)
    addi	r0, r3, 1
    stw	r0, 4(r31)
_80059b98:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80059BAC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _80059bf8
    lis	r3, -0x7fe7
    lwz	r12, 0x178(r3)
    cmplwi	r12, 0
    beq     _80059bf0
    lis     r4, lbl_8019017C@ha
    lis     r3, E0092912_handl_is_null_str_2@ha
    addi	r5, r4, lbl_8019017C@l
    addi	r4, r3, E0092912_handl_is_null_str_2@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_80059bf0:
    li	r3, 0
    b     _80059bfc
_80059bf8:
    lwz	r3, 0x14(r3)
_80059bfc:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80059C0C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _80059c54
    lis	r3, -0x7fe7
    lwz	r12, 0x178(r3)
    cmplwi	r12, 0
    beq     _80059c94
    lis     r4, lbl_8019017C@ha
    lis     r3, E0040302_handl_is_null_str_2@ha
    addi	r5, r4, lbl_8019017C@l
    addi	r4, r3, E0040302_handl_is_null_str_2@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
    b     _80059c94
_80059c54:
    lwz	r5, 0x10(r3)
    lwz	r0, 4(r3)
    stw	r4, 4(r3)
    mullw	r7, r5, r0
    lwz	r6, 4(r3)
    lwz	r0, 8(r3)
    add	r5, r6, r0
    addi	r0, r5, -1
    divw	r0, r0, r6
    stw	r0, 0xc(r3)
    lwz	r0, 4(r3)
    divw	r0, r7, r0
    stw	r0, 0x10(r3)
    lwz	r0, 0x18(r3)
    mullw	r0, r0, r4
    stw	r0, 0x14(r3)
_80059c94:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80059CA4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _80059cf0
    lis	r3, -0x7fe7
    lwz	r12, 0x178(r3)
    cmplwi	r12, 0
    beq     _80059ce8
    lis     r4, lbl_8019017C@ha
    lis     r3, E0040301_handl_is_null_str_2@ha
    addi	r5, r4, lbl_8019017C@l
    addi	r4, r3, E0040301_handl_is_null_str_2@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_80059ce8:
    li	r3, 0
    b     _80059cf4
_80059cf0:
    lwz	r3, 4(r3)
_80059cf4:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80059D04(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _80059d50
    lis	r3, -0x7fe7
    lwz	r12, 0x178(r3)
    cmplwi	r12, 0
    beq     _80059d48
    lis     r4, lbl_8019017C@ha
    lis     r3, E0092912_handl_is_null_str_2@ha
    addi	r5, r4, lbl_8019017C@l
    addi	r4, r3, E0092912_handl_is_null_str_2@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_80059d48:
    li	r3, 0
    b     _80059d58
_80059d50:
    lbz	r3, 1(r3)
    extsb	r3, r3
_80059d58:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80059D68(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    or.	r31, r3, r3
    bne     _80059db4
    lis	r3, -0x7fe7
    lwz	r12, 0x178(r3)
    cmplwi	r12, 0
    beq     _80059dc4
    lis     r4, lbl_8019017C@ha
    lis     r3, E0092912_handl_is_null_str_2@ha
    addi	r5, r4, lbl_8019017C@l
    addi	r4, r3, E0092912_handl_is_null_str_2@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
    b     _80059dc4
_80059db4:
    bl      svmLockServer
    li	r0, 0
    stb	r0, 1(r31)
    bl      svmUnlockServer
_80059dc4:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void SVM_SetCbSvr(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    lis	r6, -0x7ff7
    stw	r0, 0x34(r1)
    stmw	r27, 0x1c(r1)
    or.	r29, r3, r3
    lis     r3, lbl_80190178@ha
    mr	r27, r4
    mr	r28, r5
    addi	r30, r6, 0x24f8
    addi	r31, r3, lbl_80190178@l
    bne     _80059e30
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _80059e28
    addi	r4, r30, 0x184
    lwz	r3, 4(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
_80059e28:
    li	r3, 0
    b     _8005a04c
_80059e30:
    cmpwi	r27, 0
    bge     _80059e60
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _80059e58
    mr	r5, r29
    addi	r4, r30, 0x1a0
    lwz	r3, 4(r31)
    mtctr	r12
    bctrl	
_80059e58:
    li	r3, 0
    b     _8005a04c
_80059e60:
    cmplwi	r28, 0
    bne     _80059e90
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _80059e88
    mr	r5, r29
    addi	r4, r30, 0x1c0
    lwz	r3, 4(r31)
    mtctr	r12
    bctrl	
_80059e88:
    li	r3, 0
    b     _8005a04c
_80059e90:
    cmpwi	r27, 0
    bne     _80059ea8
    li	r0, 1
    li	r3, 0
    stb	r0, 1(r29)
    b     _8005a04c
_80059ea8:
    bl      svmLockServer
    li	r0, 0
    stw	r0, 0x14(r29)
    lwz	r3, 0x10(r29)
    lwz	r0, 0xc(r29)
    subf	r0, r3, r0
    cmpw	r27, r0
    bge     _80059ecc
    mr	r0, r27
_80059ecc:
    stw	r0, 0x18(r29)
    lwz	r4, 4(r29)
    lwz	r0, 0x18(r29)
    lwz	r3, 0x10(r29)
    mullw.	r5, r0, r4
    mullw	r0, r3, r4
    bne     _80059efc
    li	r0, 1
    stb	r0, 1(r29)
    bl      svmUnlockServer
    li	r3, 0
    b     _8005a04c
_80059efc:
    stw	r0, 0x30(r29)
    li	r0, 2
    addi	r3, r29, 0x1c
    stw	r5, 0x34(r29)
    stb	r0, 1(r29)
    bl      strlen
    cmplwi	r3, 0x11
    beq     _80059f50
    addi	r3, r31, 8
    addi	r4, r30, 0xc0
    addi	r5, r29, 0x1c
    crxor	6, 6, 6
    bl      sprintf
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _80059f50
    addi	r4, r31, 8
    lwz	r3, 4(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
_80059f50:
    lbz	r0, 0x24(r29)
    cmpwi	r0, 0x2e
    beq     _80059f90
    addi	r3, r31, 8
    addi	r4, r30, 0x100
    addi	r5, r29, 0x1c
    crxor	6, 6, 6
    bl      sprintf
    lwz	r12, 0(r31)
    cmplwi	r12, 0
    beq     _80059f90
    addi	r4, r31, 8
    lwz	r3, 4(r31)
    li	r5, 0
    mtctr	r12
    bctrl	
_80059f90:
    addi	r3, r29, 0x1c
    addi	r4, r1, 8
    stw	r3, 8(r1)
    li	r5, 0x10
    bl      fn_80084FDC
    lwz	r4, 8(r1)
    mr	r31, r3
    lbz	r0, 0(r4)
    extsb.	r0, r0
    beq     _80059fc0
    addi	r0, r4, 1
    stw	r0, 8(r1)
_80059fc0:
    addic.	r0, r1, 0xc
    beq     _80059fdc
    lwz	r3, 8(r1)
    addi	r4, r1, 8
    li	r5, 0x10
    bl      fn_80084FDC
    stw	r3, 0xc(r1)
_80059fdc:
    lwz	r4, 0x30(r29)
    lwz	r0, 0xc(r1)
    lwz	r5, 0x34(r29)
    subf	r0, r4, r0
    cmpw	r5, r0
    mr	r30, r5
    ble     _80059ffc
    mr	r30, r0
_80059ffc:
    mr	r3, r28
    add	r4, r31, r4
    bl      memcpy
    lwz	r0, 0x34(r29)
    add	r3, r28, r30
    li	r4, 0
    subf	r5, r30, r0
    bl      memset
    lwz	r4, 0x18(r29)
    li	r0, 1
    lwz	r3, 4(r29)
    mullw	r3, r4, r3
    stw	r3, 0x14(r29)
    lwz	r4, 0x10(r29)
    lwz	r3, 0x18(r29)
    add	r3, r4, r3
    stw	r3, 0x10(r29)
    stb	r0, 1(r29)
    bl      svmUnlockServer
    lwz	r3, 0x18(r29)
_8005a04c:
    lmw	r27, 0x1c(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_8005A060(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    cmplwi	r3, 0
    stw	r0, 0x14(r1)
    bne     _8005a0ac
    lis	r3, -0x7fe7
    lwz	r12, 0x178(r3)
    cmplwi	r12, 0
    beq     _8005a0a4
    lis     r4, lbl_8019017C@ha
    lis     r3, E01100306_handl_is_null_str@ha
    addi	r5, r4, lbl_8019017C@l
    addi	r4, r3, E01100306_handl_is_null_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_8005a0a4:
    li	r3, 0
    b     _8005a0b0
_8005a0ac:
    lwz	r3, 0x10(r3)
_8005a0b0:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8005A0C0(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r5
    stw	r30, 0x18(r1)
    mr	r30, r4
    stw	r29, 0x14(r1)
    or.	r29, r3, r3
    bne     _8005a120
    lis	r3, -0x7fe7
    lwz	r12, 0x178(r3)
    cmplwi	r12, 0
    beq     _8005a118
    lis     r4, lbl_8019017C@ha
    lis     r3, E01100305_handl_is_null_str@ha
    addi	r5, r4, lbl_8019017C@l
    addi	r4, r3, E01100305_handl_is_null_str@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
_8005a118:
    li	r3, 0
    b     _8005a198
_8005a120:
    bl      svmLockServer
    cmpwi	r31, 0
    bne     _8005a134
    stw	r30, 0x10(r29)
    b     _8005a160
_8005a134:
    cmpwi	r31, 2
    bne     _8005a14c
    lwz	r0, 0xc(r29)
    add	r0, r0, r30
    stw	r0, 0x10(r29)
    b     _8005a160
_8005a14c:
    cmpwi	r31, 1
    bne     _8005a160
    lwz	r0, 0x10(r29)
    add	r0, r0, r30
    stw	r0, 0x10(r29)
_8005a160:
    lwz	r3, 0xc(r29)
    lwz	r0, 0x10(r29)
    cmpw	r0, r3
    bge     _8005a174
    mr	r3, r0
_8005a174:
    stw	r3, 0x10(r29)
    lwz	r0, 0x10(r29)
    cmpwi	r0, 0
    ble     _8005a188
    b     _8005a18c
_8005a188:
    li	r0, 0
_8005a18c:
    stw	r0, 0x10(r29)
    bl      svmUnlockServer
    lwz	r3, 0x10(r29)
_8005a198:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8005A1B4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    or.	r31, r3, r3
    beq     _8005a238
    bne     _8005a204
    lis	r3, -0x7fe7
    lwz	r12, 0x178(r3)
    cmplwi	r12, 0
    beq     _8005a214
    lis     r4, lbl_8019017C@ha
    lis     r3, E0092912_handl_is_null_str_2@ha
    addi	r5, r4, lbl_8019017C@l
    addi	r4, r3, E0092912_handl_is_null_str_2@l
    lwz	r3, 0(r5)
    li	r5, 0
    mtctr	r12
    bctrl	
    b     _8005a214
_8005a204:
    bl      svmLockServer
    li	r0, 0
    stb	r0, 1(r31)
    bl      svmUnlockServer
_8005a214:
    lbz	r0, 0(r31)
    cmpwi	r0, 1
    bne     _8005a238
    li	r0, 0
    mr	r3, r31
    stb	r0, 0(r31)
    li	r4, 0
    li	r5, 0x38
    bl      memset
_8005a238:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

#pragma pop
