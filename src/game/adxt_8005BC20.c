#pragma push
#pragma force_active on

typedef struct AdxtVoiceSlot {
    char pad0[8];
    void* voice[2];
    char pad10[0xd8];
} AdxtVoiceSlot;

typedef struct AdxtNotifySlot {
    int used;
    char pad4[8];
} AdxtNotifySlot;


extern void AXFreeVoice(void);
extern void ARFree(void);
extern void axmix_device_ctrl_clear();
extern void adxtSetNotifyCallback();
extern void fn_8005A614(void);
extern void svm_exit_critical_wrapper(void);
extern void svm_enter_critical_wrapper(void);
extern void ADXTServerStateRequest(void);
extern void mfCiOpen_resource_mgr(void);
extern void ADXT_DestroyHandle();
extern void fn_8005BFB4(void);
extern void SndInitManager(void);
extern void memset();
extern unsigned char lbl_800927BC[4];
extern unsigned char lbl_80092988[36];
extern unsigned char lbl_800929AC[43];
extern unsigned char lbl_80190C78[4];
extern AdxtVoiceSlot lbl_80191D4C[16];
extern unsigned char lbl_80192BD0[20];
extern AdxtNotifySlot lbl_80192BE4[32];

// provenance: original
void fn_8005BC20(void* h)
{
    int i;
    int j;

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 2; j++) {
            if (h == lbl_80191D4C[i].voice[j]) {
                axmix_device_ctrl_clear(lbl_80191D4C[i].voice[j]);
                lbl_80191D4C[i].voice[j] = 0;
                return;
            }
        }
    }
}

asm void fn_8005BCB4(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r3, lbl_80190C78@ha
    stw	r0, 0x24(r1)
    addi	r4, r3, lbl_80190C78@l
    stmw	r27, 0xc(r1)
    lwz	r3, 0(r4)
    addic.	r0, r3, -1
    stw	r0, 0(r4)
    bne     _8005bdc0
    lis     r3, lbl_80191D4C@ha
    li	r27, 0
    addi	r28, r3, lbl_80191D4C@l
_8005bce8:
    lbz	r0, 0(r28)
    cmpwi	r0, 1
    bne     _8005bd98
    cmplwi	r28, 0
    beq     _8005bd98
    mr	r3, r28
    li	r4, 0
    bl      ADXTServerStateRequest
    mr	r3, r28
    li	r4, 0
    bl      mfCiOpen_resource_mgr
    mr	r30, r28
    addi	r29, r28, 2
    li	r31, 0
    b     _8005bd78
_8005bd24:
    lwz	r3, 0x38(r30)
    cmplwi	r3, 0
    beq     _8005bd40
    lwz	r4, 0(r3)
    lwz	r12, 0xc(r4)
    mtctr	r12
    bctrl	
_8005bd40:
    lwz	r3, 0x10(r30)
    cmplwi	r3, 0
    beq     _8005bd50
    bl      ADXT_DestroyHandle
_8005bd50:
    bl      svm_enter_critical_wrapper
    lwz	r3, 8(r30)
    cmplwi	r3, 0
    beq     _8005bd6c
    bl      axmix_device_ctrl_clear
    lwz	r3, 8(r30)
    bl      AXFreeVoice
_8005bd6c:
    bl      svm_exit_critical_wrapper
    addi	r30, r30, 4
    addi	r31, r31, 1
_8005bd78:
    lbz	r0, 0(r29)
    extsb	r0, r0
    cmpw	r31, r0
    blt     _8005bd24
    mr	r3, r28
    li	r4, 0
    li	r5, 0xe8
    bl      memset
_8005bd98:
    addi	r27, r27, 1
    addi	r28, r28, 0xe8
    cmpwi	r27, 0x10
    blt     _8005bce8
    lis     r3, lbl_80191D4C@ha
    li	r4, 0
    addi	r3, r3, lbl_80191D4C@l
    li	r5, 0xe80
    bl      memset
    bl      fn_8005BFB4
_8005bdc0:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8005BDD4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_800927BC@ha
    lis     r4, lbl_80190C78@ha
    stw	r0, 0x14(r1)
    addi	r3, r3, lbl_800927BC@l
    lwz	r3, 0(r3)
    stw	r31, 0xc(r1)
    addi	r31, r4, lbl_80190C78@l
    lwz	r0, 0(r31)
    cmplwi	r0, 0
    bne     _8005be28
    bl      SndInitManager
    addi	r3, r31, 0x10d4
    li	r4, 0
    li	r5, 0xe80
    bl      memset
    addi	r3, r31, 0x94
    addi	r0, r3, 0x1f
    rlwinm	r0, r0, 0, 0, 0x1a
    stw	r0, 4(r31)
_8005be28:
    lwz	r3, 0(r31)
    addi	r0, r3, 1
    stw	r0, 0(r31)
    lwz	r31, 0xc(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

// provenance: original
void fn_8005BE48(void)
{
    fn_8005A614();
}

// provenance: original
int ADXT_GetId(void* p)
{
    if (p == 0) {
        return 0;
    }
    return *(int*)((char*)p + 8);
}

// provenance: original
int ADXT_GetNumHandles(void* p)
{
    if (p == 0) {
        return 0;
    }
    return *(int*)((char*)p + 4);
}

// provenance: original
void ADXT_DestroyHandle(void* p)
{
    if (p != 0) {
        *(int*)p = 0;
    }
}

// provenance: original
AdxtNotifySlot* fn_8005BEAC(void)
{
    AdxtNotifySlot* s;
    int i;

    for (i = 0; i < 32; i++) {
        if (lbl_80192BE4[i].used == 0) {
            break;
        }
    }
    if (i == 32) {
        adxtSetNotifyCallback(lbl_80092988);
        return 0;
    }
    s = &lbl_80192BE4[i];
    s->used = 1;
    return s;
}

asm void fn_8005BFB4(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r3, lbl_80192BD0@ha
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r3, lbl_80192BD0@l
    lwz	r3, 0(r31)
    addic.	r0, r3, -1
    stw	r0, 0(r31)
    bne     _8005c10c
    li	r0, 4
    addi	r4, r31, 0x14
    li	r5, 0
    li	r3, 0
    mtctr	r0
_8005bff0:
    lwz	r0, 0(r4)
    cmpwi	r0, 1
    bne     _8005c008
    cmplwi	r4, 0
    beq     _8005c008
    stw	r3, 0(r4)
_8005c008:
    lwzu	r0, 0xc(r4)
    cmpwi	r0, 1
    bne     _8005c020
    cmplwi	r4, 0
    beq     _8005c020
    stw	r3, 0(r4)
_8005c020:
    lwzu	r0, 0xc(r4)
    cmpwi	r0, 1
    bne     _8005c038
    cmplwi	r4, 0
    beq     _8005c038
    stw	r3, 0(r4)
_8005c038:
    lwzu	r0, 0xc(r4)
    cmpwi	r0, 1
    bne     _8005c050
    cmplwi	r4, 0
    beq     _8005c050
    stw	r3, 0(r4)
_8005c050:
    lwzu	r0, 0xc(r4)
    cmpwi	r0, 1
    bne     _8005c068
    cmplwi	r4, 0
    beq     _8005c068
    stw	r3, 0(r4)
_8005c068:
    lwzu	r0, 0xc(r4)
    cmpwi	r0, 1
    bne     _8005c080
    cmplwi	r4, 0
    beq     _8005c080
    stw	r3, 0(r4)
_8005c080:
    lwzu	r0, 0xc(r4)
    cmpwi	r0, 1
    bne     _8005c098
    cmplwi	r4, 0
    beq     _8005c098
    stw	r3, 0(r4)
_8005c098:
    lwzu	r0, 0xc(r4)
    cmpwi	r0, 1
    bne     _8005c0b0
    cmplwi	r4, 0
    beq     _8005c0b0
    stw	r3, 0(r4)
_8005c0b0:
    addi	r4, r4, 0xc
    addi	r5, r5, 7
    bdnz     _8005bff0
    addi	r3, r31, 0x14
    li	r4, 0
    li	r5, 0x180
    bl      memset
    lwz	r0, 4(r31)
    cmplwi	r0, 0
    bne     _8005c10c
    addi	r3, r1, 8
    bl      ARFree
    lwz	r3, 8(r1)
    lwz	r0, 0xc(r31)
    cmplw	r3, r0
    beq     _8005c0fc
    lis     r3, lbl_800929AC@ha
    addi	r3, r3, lbl_800929AC@l
    bl      adxtSetNotifyCallback
_8005c0fc:
    li	r0, 0
    stw	r0, 8(r31)
    stw	r0, 0xc(r31)
    stw	r0, 0x10(r31)
_8005c10c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
