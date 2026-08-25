#pragma push
#pragma force_active on

typedef unsigned int u32;
extern void DCInvalidateRange(register void* addr, register u32 nBytes);
extern void DCFlushRangeNoSync(register void* addr, register u32 nBytes);
extern unsigned char __AXBufferAuxA[5760];
extern unsigned char __AXBufferAuxB[5760];

extern unsigned char lbl_801A6AC0[4];
extern unsigned char lbl_801A6AC4[4];
extern unsigned char lbl_801A6AC8[4];
extern unsigned char lbl_801A6ACC[4];
extern unsigned char lbl_801A6AD0[4];
extern unsigned char lbl_801A6AD4[4];
extern unsigned char lbl_801A6AD8[4];
extern unsigned char lbl_801A6ADC[4];
extern unsigned char lbl_801A6AE0[4];
extern unsigned char lbl_801A6AE4[4];
extern unsigned char lbl_801A6AE8[4];
extern unsigned char lbl_801A6AEC[4];
extern unsigned char lbl_801A6AF0[8];
extern unsigned char lbl_801A6B00[4];
extern unsigned char lbl_801A6B08[8];
// provenance: original
void AXInitAux(void) {
    u32* pA;
    u32* pB;
    int i;
    *(u32*)lbl_801A6AC0 = 0;
    *(u32*)lbl_801A6AC4 = 0;
    *(u32*)lbl_801A6AC8 = 0;
    *(u32*)lbl_801A6ACC = 0;
    *(u32*)lbl_801A6AE0 = 0;
    *(u32*)lbl_801A6AE4 = 1;
    *(u32*)lbl_801A6AE8 = 0;
    *(u32*)lbl_801A6AEC = 1;
    *(u32*)lbl_801A6AF0 = 2;
    pA = (u32*)__AXBufferAuxA;
    pB = (u32*)__AXBufferAuxB;
    for (i = 0; i < 30; i++) {
        pA[0] = 0; pB[0] = 0;
        pA[1] = 0; pB[1] = 0;
        pA[2] = 0; pB[2] = 0;
        pA[3] = 0; pB[3] = 0;
        pA[4] = 0; pB[4] = 0;
        pA[5] = 0; pB[5] = 0;
        pA[6] = 0; pB[6] = 0;
        pA[7] = 0; pB[7] = 0;
        pA[8] = 0; pB[8] = 0;
        pA[9] = 0; pB[9] = 0;
        pA[10] = 0; pB[10] = 0;
        pA[11] = 0; pB[11] = 0;
        pA[12] = 0; pB[12] = 0;
        pA[13] = 0; pB[13] = 0;
        pA[14] = 0; pB[14] = 0;
        pA[15] = 0; pB[15] = 0;
        pA += 16;
        pB += 16;
    }
}

// provenance: original
void AXClearAuxBufferPtrs(void) {
    *(u32*)lbl_801A6AC0 = 0;
    *(u32*)lbl_801A6AC4 = 0;
}

// provenance: original
void AXGetAuxBufferA_Active(void** out) {
    if (*(u32*)lbl_801A6AC0 != 0) {
        *out = __AXBufferAuxA + *(u32*)lbl_801A6AE0 * 0x780;
        return;
    }
    *out = 0;
}

// provenance: original
void AXGetAuxBufferB_500(void** out) {
    *out = __AXBufferAuxB + *(u32*)lbl_801A6AE0 * 0x780 + 0x500;
}

// provenance: original
void AXGetAuxBufferA_Current(void** out) {
    *out = __AXBufferAuxA + *(u32*)lbl_801A6AE4 * 0x780;
}

// provenance: original
void AXGetAuxBufferA_280(void** out) {
    *out = __AXBufferAuxA + *(u32*)lbl_801A6AE4 * 0x780 + 0x280;
}

// provenance: original
void AXGetAuxBufferA_500(void** out) {
    *out = __AXBufferAuxA + *(u32*)lbl_801A6AE4 * 0x780 + 0x500;
}

// provenance: original
void AXGetAuxBufferB_Current500(void** out) {
    *out = __AXBufferAuxB + *(u32*)lbl_801A6AE4 * 0x780 + 0x500;
}

// provenance: original
void AXGetAuxBufferB_Active(void** out) {
    if (*(u32*)lbl_801A6AC4 != 0) {
        *out = __AXBufferAuxB + *(u32*)lbl_801A6AE0 * 0x780;
        return;
    }
    *out = 0;
}

// provenance: original
void AXGetAuxBufferB_Current(void** out) {
    *out = __AXBufferAuxB + *(u32*)lbl_801A6AE4 * 0x780;
}

// provenance: original
void AXGetAuxBufferB_280(void** out) {
    *out = __AXBufferAuxB + *(u32*)lbl_801A6AE8 * 0x780;
}

// provenance: original
void AXGetAuxBufferB_Unknown(void** out) {
    *out = __AXBufferAuxB + *(u32*)lbl_801A6AEC * 0x780;
}

asm void fn_80020FA4(void)
{
    nofralloc
    mflr	r0
    lis     r4, __AXBufferAuxA@ha
    stw	r0, 4(r1)
    stwu	r1, -0x38(r1)
    stw	r31, 0x34(r1)
    addi	r31, r4, __AXBufferAuxA@l
    lwz	r0, lbl_801A6AE0
    lwz	r3, lbl_801A6AE4
    mulli	r4, r0, 0x780
    lwz	r0, lbl_801A6AC0
    mulli	r3, r3, 0x780
    add	r4, r31, r4
    add	r3, r31, r3
    stw	r4, lbl_801A6AD0
    addi	r4, r4, 0x1680
    stw	r3, lbl_801A6AD4
    addi	r3, r3, 0x1680
    cmplwi	r0, 0
    stw	r4, lbl_801A6AD8
    stw	r3, lbl_801A6ADC
    beq     _800210c0
    lwz	r0, lbl_801A6B08
    cmplwi	r0, 2
    bne     _80021074
    lwz	r0, lbl_801A6AF0
    li	r4, 0x780
    mulli	r0, r0, 0x780
    add	r5, r31, r0
    stw	r5, 0x20(r1)
    addi	r0, r5, 0x280
    addi	r3, r5, 0x500
    stw	r0, 0x24(r1)
    addi	r0, r5, 0x1b80
    stw	r3, 0x28(r1)
    stw	r0, 0x2c(r1)
    lwz	r3, 0x20(r1)
    bl      DCInvalidateRange
    lwz	r3, 0x2c(r1)
    li	r4, 0x280
    bl      DCInvalidateRange
    lwz	r12, lbl_801A6AC0
    addi	r3, r1, 0x20
    lwz	r4, lbl_801A6AC8
    mtlr	r12
    blrl	
    lwz	r3, 0x20(r1)
    li	r4, 0x780
    bl      DCFlushRangeNoSync
    lwz	r3, 0x2c(r1)
    li	r4, 0x280
    bl      DCFlushRangeNoSync
    b       _800210c0
_80021074:
    lwz	r0, lbl_801A6AF0
    li	r4, 0x780
    mulli	r0, r0, 0x780
    add	r5, r31, r0
    stw	r5, 0x14(r1)
    addi	r3, r5, 0x280
    addi	r0, r5, 0x500
    stw	r3, 0x18(r1)
    stw	r0, 0x1c(r1)
    lwz	r3, 0x14(r1)
    bl      DCInvalidateRange
    lwz	r12, lbl_801A6AC0
    addi	r3, r1, 0x14
    lwz	r4, lbl_801A6AC8
    mtlr	r12
    blrl	
    lwz	r3, 0x14(r1)
    li	r4, 0x780
    bl      DCFlushRangeNoSync
_800210c0:
    lwz	r0, lbl_801A6AC4
    cmplwi	r0, 0
    beq     _80021128
    lwz	r0, lbl_801A6B08
    cmplwi	r0, 2
    beq     _80021128
    lwz	r0, lbl_801A6AF0
    li	r4, 0x780
    mulli	r0, r0, 0x780
    add	r5, r31, r0
    addi	r5, r5, 0x1680
    stw	r5, 8(r1)
    addi	r3, r5, 0x280
    addi	r0, r5, 0x500
    stw	r3, 0xc(r1)
    stw	r0, 0x10(r1)
    lwz	r3, 8(r1)
    bl      DCInvalidateRange
    lwz	r12, lbl_801A6AC4
    addi	r3, r1, 8
    lwz	r4, lbl_801A6ACC
    mtlr	r12
    blrl	
    lwz	r3, 8(r1)
    li	r4, 0x780
    bl      DCFlushRangeNoSync
_80021128:
    lwz	r4, lbl_801A6AE0
    lis	r3, -0x5555
    lwz	r5, lbl_801A6AE4
    addi	r8, r3, -0x5555
    lwz	r3, lbl_801A6AF0
    addi	r0, r4, 1
    lwz	r4, lbl_801A6AE8
    addi	r5, r5, 1
    stw	r0, lbl_801A6AE0
    addi	r0, r3, 1
    lwz	r3, lbl_801A6AEC
    stw	r5, lbl_801A6AE4
    addi	r5, r4, 1
    lwz	r10, lbl_801A6AE0
    addi	r4, r3, 1
    stw	r0, lbl_801A6AF0
    lwz	r7, lbl_801A6AE4
    mulhwu	r9, r8, r10
    lwz	r3, lbl_801A6AF0
    stw	r5, lbl_801A6AE8
    stw	r4, lbl_801A6AEC
    mulhwu	r6, r8, r7
    lwz	r5, lbl_801A6AE8
    lwz	r4, lbl_801A6AEC
    mulhwu	r0, r8, r3
    srwi	r9, r9, 1
    srwi	r6, r6, 1
    srwi	r0, r0, 1
    mulli	r8, r9, 3
    mulli	r6, r6, 3
    mulli	r0, r0, 3
    subf	r8, r8, r10
    subf	r6, r6, r7
    stw	r8, lbl_801A6AE0
    clrlwi	r5, r5, 0x1f
    clrlwi	r4, r4, 0x1f
    stw	r6, lbl_801A6AE4
    subf	r0, r0, r3
    stw	r5, lbl_801A6AE8
    stw	r4, lbl_801A6AEC
    stw	r0, lbl_801A6AF0
    lwz	r0, 0x3c(r1)
    lwz	r31, 0x34(r1)
    addi	r1, r1, 0x38
    mtlr	r0
    blr	
}

void AXSetAuxCallbackDestA(register void* destA, register void* param_2)
{
    *(volatile void**)lbl_801A6AC0 = destA;
    *(volatile void**)lbl_801A6AC8 = param_2;
}

// provenance: original
void AXSetAuxCallbackDestB(u32 destA, u32 destB) {
    *(u32*)lbl_801A6AC4 = destA;
    *(u32*)lbl_801A6ACC = destB;
}

void* fn_800211F8(void)
{
    return *(volatile void**)lbl_801A6B00;
}

#pragma pop
