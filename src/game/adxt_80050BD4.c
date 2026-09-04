#pragma push
#pragma force_active on

extern void svm_ringbuf_skip(void);

asm void fn_80050BD4(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    stmw	r19, 0xc(r1)
    mr	r26, r5
    mr	r27, r6
    mr	r25, r3
    mr	r28, r7
    mr	r23, r26
    mr	r22, r27
    li	r19, 0
    lwz	r30, 0x10(r4)
    lwz	r29, 4(r4)
    b       _80050c58
_80050c0c:
    mr	r31, r23
    mr	r24, r22
    li	r20, 0
    b       _80050c44
_80050c1c:
    lwz	r0, 0(r31)
    cmplwi	r0, 0
    beq     _80050c38
    mr	r3, r25
    li	r4, 2
    bl      svm_ringbuf_skip
    stw	r3, 0(r24)
_80050c38:
    addi	r31, r31, 0x80
    addi	r24, r24, 0x80
    addi	r20, r20, 1
_80050c44:
    cmpw	r20, r29
    blt     _80050c1c
    addi	r23, r23, 4
    addi	r22, r22, 4
    addi	r19, r19, 1
_80050c58:
    cmpw	r19, r30
    blt     _80050c0c
    slwi	r31, r30, 2
    mr	r20, r30
    add	r22, r27, r31
    b       _80050d20
_80050c70:
    cmpwi	r29, 0
    li	r19, 0
    ble     _80050d18
    cmpwi	r29, 8
    addi	r11, r29, -8
    ble     _80050cec
    addi	r0, r11, 7
    mr	r12, r22
    srwi	r0, r0, 3
    mr	r10, r19
    mr	r9, r19
    mr	r8, r19
    mr	r7, r19
    mr	r6, r19
    mr	r5, r19
    mr	r4, r19
    mr	r3, r19
    mtctr	r0
    cmpwi	r11, 0
    ble     _80050cec
_80050cc0:
    stw	r10, 0(r12)
    addi	r19, r19, 8
    stw	r9, 0x80(r12)
    stw	r8, 0x100(r12)
    stw	r7, 0x180(r12)
    stw	r6, 0x200(r12)
    stw	r5, 0x280(r12)
    stw	r4, 0x300(r12)
    stw	r3, 0x380(r12)
    addi	r12, r12, 0x400
    bdnz    _80050cc0
_80050cec:
    slwi	r3, r19, 7
    subf	r0, r19, r29
    add	r4, r22, r3
    li	r3, 0
    mtctr	r0
    cmpw	r19, r29
    bge     _80050d18
_80050d08:
    stw	r3, 0(r4)
    addi	r4, r4, 0x80
    addi	r19, r19, 1
    bdnz    _80050d08
_80050d18:
    addi	r22, r22, 4
    addi	r20, r20, 1
_80050d20:
    cmpwi	r20, 0x20
    blt     _80050c70
    mr	r21, r28
    li	r20, 0
    b       _80050e58
_80050d34:
    mr	r22, r26
    mr	r23, r27
    mr	r24, r21
    li	r19, 0
    b       _80050e40
_80050d48:
    lwz	r0, 0(r22)
    cmplwi	r0, 0
    beq     _80050e20
    lwz	r0, 0(r23)
    cmpwi	r0, 2
    beq     _80050e04
    bge     _80050d74
    cmpwi	r0, 0
    beq     _80050d80
    bge     _80050db4
    b       _80050e30
_80050d74:
    cmpwi	r0, 4
    bge     _80050e30
    b       _80050ddc
_80050d80:
    mr	r3, r25
    li	r4, 6
    bl      svm_ringbuf_skip
    stw	r3, 0(r24)
    mr	r3, r25
    li	r4, 6
    bl      svm_ringbuf_skip
    stw	r3, 0x80(r24)
    mr	r3, r25
    li	r4, 6
    bl      svm_ringbuf_skip
    stw	r3, 0x100(r24)
    b       _80050e30
_80050db4:
    mr	r3, r25
    li	r4, 6
    bl      svm_ringbuf_skip
    stw	r3, 0x80(r24)
    li	r4, 6
    stw	r3, 0(r24)
    mr	r3, r25
    bl      svm_ringbuf_skip
    stw	r3, 0x100(r24)
    b       _80050e30
_80050ddc:
    mr	r3, r25
    li	r4, 6
    bl      svm_ringbuf_skip
    stw	r3, 0(r24)
    mr	r3, r25
    li	r4, 6
    bl      svm_ringbuf_skip
    stw	r3, 0x100(r24)
    stw	r3, 0x80(r24)
    b       _80050e30
_80050e04:
    mr	r3, r25
    li	r4, 6
    bl      svm_ringbuf_skip
    stw	r3, 0x100(r24)
    stw	r3, 0x80(r24)
    stw	r3, 0(r24)
    b       _80050e30
_80050e20:
    li	r0, 0x3f
    stw	r0, 0x100(r24)
    stw	r0, 0x80(r24)
    stw	r0, 0(r24)
_80050e30:
    addi	r22, r22, 0x80
    addi	r23, r23, 0x80
    addi	r24, r24, 0x180
    addi	r19, r19, 1
_80050e40:
    cmpw	r19, r29
    blt     _80050d48
    addi	r26, r26, 4
    addi	r27, r27, 4
    addi	r21, r21, 4
    addi	r20, r20, 1
_80050e58:
    cmpw	r20, r30
    blt     _80050d34
    mr	r6, r30
    add	r5, r28, r31
    b       _80050f48
_80050e6c:
    cmpwi	r29, 0
    li	r7, 0
    ble     _80050f40
    cmpwi	r29, 8
    addi	r3, r29, -8
    ble     _80050f0c
    addi	r0, r3, 7
    mr	r4, r5
    srwi	r0, r0, 3
    mtctr	r0
    cmpwi	r3, 0
    ble     _80050f0c
_80050e9c:
    li	r0, 0x3f
    addi	r7, r7, 8
    stw	r0, 0x100(r4)
    stw	r0, 0x80(r4)
    stw	r0, 0(r4)
    stw	r0, 0x280(r4)
    stw	r0, 0x200(r4)
    stw	r0, 0x180(r4)
    stw	r0, 0x400(r4)
    stw	r0, 0x380(r4)
    stw	r0, 0x300(r4)
    stw	r0, 0x580(r4)
    stw	r0, 0x500(r4)
    stw	r0, 0x480(r4)
    stw	r0, 0x700(r4)
    stw	r0, 0x680(r4)
    stw	r0, 0x600(r4)
    stw	r0, 0x880(r4)
    stw	r0, 0x800(r4)
    stw	r0, 0x780(r4)
    stw	r0, 0xa00(r4)
    stw	r0, 0x980(r4)
    stw	r0, 0x900(r4)
    stw	r0, 0xb80(r4)
    stw	r0, 0xb00(r4)
    stw	r0, 0xa80(r4)
    addi	r4, r4, 0xc00
    bdnz    _80050e9c
_80050f0c:
    mulli	r4, r7, 0x180
    subf	r0, r7, r29
    li	r3, 0x3f
    add	r4, r5, r4
    mtctr	r0
    cmpw	r7, r29
    bge     _80050f40
_80050f28:
    stw	r3, 0x100(r4)
    addi	r7, r7, 1
    stw	r3, 0x80(r4)
    stw	r3, 0(r4)
    addi	r4, r4, 0x180
    bdnz    _80050f28
_80050f40:
    addi	r5, r5, 4
    addi	r6, r6, 1
_80050f48:
    cmpwi	r6, 0x20
    blt     _80050e6c
    lmw	r19, 0xc(r1)
    lwz	r0, 0x44(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

// provenance: original
int fn_80050F64(void)
{
    return 0x60;
}

// provenance: original
int fn_80050F6C(void)
{
    return 0x10;
}

// provenance: original
void* fn_80050F74(void* p)
{
    if (*(signed char*)((char*)p + 0x345) == 0) {
        return 0;
    }
    return *(void**)((char*)p + 0x388);
}

#pragma pop
