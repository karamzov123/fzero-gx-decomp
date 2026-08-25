// provenance: original
typedef signed int s32;
typedef unsigned int u32;
typedef int BOOL;

typedef void (*ARQCallback)(void);
typedef struct ARQRequest ARQRequest;
typedef struct ARQReq {
    struct ARQReq* next;   /* 0x00 */
    u32 owner;             /* 0x04 */
    u32 type;              /* 0x08 */
    u32 unk0C;             /* 0x0c */
    u32 source;            /* 0x10 */
    u32 dest;              /* 0x14 */
    u32 length;            /* 0x18 */
    void (*callback)(u32); /* 0x1c */
} ARQReq;


extern void OSRegisterVersion(const char* version);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void ARStartDMA(register u32 dir, register u32 memaddr, register u32 aramaddr, register u32 length);
extern ARQCallback ARRegisterDMACallback(register ARQCallback callback);

#pragma push
#pragma force_active on

extern unsigned char lbl_801A64E0[8];
extern unsigned char lbl_801A6A00[4];
extern unsigned char lbl_801A6A04[4];
extern ARQReq* lbl_801A6A08;
extern unsigned char lbl_801A6A0C[4];
extern unsigned char lbl_801A6A10[4];
extern ARQReq* lbl_801A6A14;
extern void (*lbl_801A6A18)(u32);
extern void (*lbl_801A6A1C)(u32);
extern u32 lbl_801A6A20;
extern unsigned char lbl_801A6A24[4];
// provenance: original
void __ARQServiceQueueLo(void) {
    if (lbl_801A6A14 == 0 && lbl_801A6A08 != 0) {
        lbl_801A6A14 = lbl_801A6A08;
        lbl_801A6A08 = lbl_801A6A08->next;
    }
    if (lbl_801A6A14 != 0) {
        if (lbl_801A6A14->length <= lbl_801A6A20) {
            if (lbl_801A6A14->type == 0) {
                ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->source, lbl_801A6A14->dest, lbl_801A6A14->length);
            } else {
                ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->dest, lbl_801A6A14->source, lbl_801A6A14->length);
            }
            lbl_801A6A1C = lbl_801A6A14->callback;
        } else if (lbl_801A6A14->type == 0) {
            ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->source, lbl_801A6A14->dest, lbl_801A6A20);
        } else {
            ARStartDMA(lbl_801A6A14->type, lbl_801A6A14->dest, lbl_801A6A14->source, lbl_801A6A20);
        }
        lbl_801A6A14->length -= lbl_801A6A20;
        lbl_801A6A14->source += lbl_801A6A20;
        lbl_801A6A14->dest += lbl_801A6A20;
    }
}

// provenance: original
void __ARQCallbackHack(u32 result) {
}

asm u32 __ARQInterruptServiceRoutine(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    lwz	r12, lbl_801A6A18
    cmplwi	r12, 0
    beq     _80020498
    lwz	r3, lbl_801A6A10
    mtlr	r12
    blrl	
    li	r0, 0
    stw	r0, lbl_801A6A10
    stw	r0, lbl_801A6A18
    b       _800204bc
_80020498:
    lwz	r12, lbl_801A6A1C
    cmplwi	r12, 0
    beq     _800204bc
    lwz	r3, lbl_801A6A14
    mtlr	r12
    blrl	
    li	r0, 0
    stw	r0, lbl_801A6A14
    stw	r0, lbl_801A6A1C
_800204bc:
    lwz	r6, lbl_801A6A00
    cmplwi	r6, 0
    beq     _80020510
    lwz	r3, 8(r6)
    cmplwi	r3, 0
    bne     _800204e8
    lwz	r4, 0x10(r6)
    lwz	r5, 0x14(r6)
    lwz	r6, 0x18(r6)
    bl      ARStartDMA
    b       _800204f8
_800204e8:
    lwz	r4, 0x14(r6)
    lwz	r5, 0x10(r6)
    lwz	r6, 0x18(r6)
    bl      ARStartDMA
_800204f8:
    lwz	r3, lbl_801A6A00
    lwz	r0, 0x1c(r3)
    stw	r0, lbl_801A6A18
    stw	r3, lbl_801A6A10
    lwz	r0, 0(r3)
    stw	r0, lbl_801A6A00
_80020510:
    lwz	r0, lbl_801A6A10
    cmplwi	r0, 0
    bne     _80020520
    bl      __ARQServiceQueueLo
_80020520:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void ARQInit(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x10(r1)
    stw	r31, 0xc(r1)
    lwz	r0, lbl_801A6A24
    cmpwi	r0, 1
    beq     _8002058c
    lwz	r3, lbl_801A64E0
    bl      OSRegisterVersion
    li	r31, 0
    li	r0, 0x1000
    stw	r31, lbl_801A6A08
    lis     r3, __ARQInterruptServiceRoutine@ha
    stw	r31, lbl_801A6A00
    addi	r3, r3, __ARQInterruptServiceRoutine@l
    stw	r0, lbl_801A6A20
    bl      ARRegisterDMACallback
    li	r0, 1
    stw	r31, lbl_801A6A10
    stw	r31, lbl_801A6A14
    stw	r31, lbl_801A6A18
    stw	r31, lbl_801A6A1C
    stw	r0, lbl_801A6A24
_8002058c:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    addi	r1, r1, 0x10
    mtlr	r0
    blr	
}

asm void ARQPostRequest(register struct ARQRequest* request, register u32 owner, register u32 type, register u32 priority, register u32 source, register u32 dest, register u32 length, register ARQCallback callback)
{
    nofralloc
    mflr	r0
    cmplwi	r10, 0
    stw	r0, 4(r1)
    li	r0, 0
    stwu	r1, -0x38(r1)
    stw	r31, 0x34(r1)
    stw	r30, 0x30(r1)
    addi	r30, r6, 0
    stw	r29, 0x2c(r1)
    addi	r29, r3, 0
    stw	r0, 0(r3)
    stw	r4, 4(r3)
    stw	r5, 8(r3)
    stw	r7, 0x10(r3)
    stw	r8, 0x14(r3)
    stw	r9, 0x18(r3)
    beq     _800205ec
    stw	r10, 0x1c(r29)
    b       _800205f8
_800205ec:
    lis     r3, __ARQCallbackHack@ha
    addi	r0, r3, __ARQCallbackHack@l
    stw	r0, 0x1c(r29)
_800205f8:
    bl      OSDisableInterrupts
    cmpwi	r30, 1
    addi	r31, r3, 0
    beq     _8002063c
    bge     _8002065c
    cmpwi	r30, 0
    bge     _80020618
    b       _8002065c
_80020618:
    lwz	r0, lbl_801A6A08
    cmplwi	r0, 0
    beq     _80020630
    lwz	r3, lbl_801A6A0C
    stw	r29, 0(r3)
    b       _80020634
_80020630:
    stw	r29, lbl_801A6A08
_80020634:
    stw	r29, lbl_801A6A0C
    b       _8002065c
_8002063c:
    lwz	r0, lbl_801A6A00
    cmplwi	r0, 0
    beq     _80020654
    lwz	r3, lbl_801A6A04
    stw	r29, 0(r3)
    b       _80020658
_80020654:
    stw	r29, lbl_801A6A00
_80020658:
    stw	r29, lbl_801A6A04
_8002065c:
    lwz	r0, lbl_801A6A10
    cmplwi	r0, 0
    bne     _800206d8
    lwz	r0, lbl_801A6A14
    cmplwi	r0, 0
    bne     _800206d8
    lwz	r6, lbl_801A6A00
    cmplwi	r6, 0
    beq     _800206c8
    lwz	r3, 8(r6)
    cmplwi	r3, 0
    bne     _800206a0
    lwz	r4, 0x10(r6)
    lwz	r5, 0x14(r6)
    lwz	r6, 0x18(r6)
    bl      ARStartDMA
    b       _800206b0
_800206a0:
    lwz	r4, 0x14(r6)
    lwz	r5, 0x10(r6)
    lwz	r6, 0x18(r6)
    bl      ARStartDMA
_800206b0:
    lwz	r3, lbl_801A6A00
    lwz	r0, 0x1c(r3)
    stw	r0, lbl_801A6A18
    stw	r3, lbl_801A6A10
    lwz	r0, 0(r3)
    stw	r0, lbl_801A6A00
_800206c8:
    lwz	r0, lbl_801A6A10
    cmplwi	r0, 0
    bne     _800206d8
    bl      __ARQServiceQueueLo
_800206d8:
    mr	r3, r31
    bl      OSRestoreInterrupts
    lwz	r0, 0x3c(r1)
    lwz	r31, 0x34(r1)
    lwz	r30, 0x30(r1)
    lwz	r29, 0x2c(r1)
    addi	r1, r1, 0x38
    mtlr	r0
    blr	
}

asm void ARQSetChunkSize(register u32 size)
{
    nofralloc
    clrlwi.	r0, r3, 0x1b
    beq     _80020714
    subfic	r0, r0, 0x20
    add	r0, r3, r0
    stw	r0, lbl_801A6A20
    blr	
_80020714:
    stw	r3, lbl_801A6A20
    blr	
}

// provenance: original
u32 ARQGetChunkSize(void) {
    return lbl_801A6A20;
}

#pragma pop
