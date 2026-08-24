typedef int BOOL;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

typedef struct OSContext OSContext;
struct OSContext {
    u32 gpr[32];
    u32 cr;
    u32 lr;
    u32 ctr;
    u32 xer;
    double fpr[32];
    u32 fpscr_pad[2];
    u32 srr0;
    u32 srr1;
    u16 mode;
    u16 state;
    u32 gqr[8];
    u32 psf[32];
};

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(register BOOL level);
extern void ICEnable(void);
extern void DCEnable(void);
extern u32 PPCMfhid0(void);
extern u32 PPCMfhid2(void);
extern void PPCMthid2(register u32 hid2);
extern u32 PPCMfl2cr(void);
extern void PPCMtl2cr(register u32 l2cr);
extern u32 PPCMfmsr(void);
extern void PPCMtmsr(register u32 msr);
extern void DBPrintf(char* msg, ...);
extern void OSReport(const char* msg, ...);
extern void OSDumpContext(OSContext* context);
extern void PPCHalt(void);
extern void OSSetErrorHandler(s32 error, void (*handler)(s32, OSContext*, ...));

#pragma push
#pragma force_active on

asm void __LCEnable(void)
{
    nofralloc
    mfmsr   r5
    ori     r5, r5, 0x1000
    mtmsr   r5
    lis     r3, 0x8000
    li      r4, 0x400
    mtctr   r4
B738_touchloop:
    dcbt    r0, r3
    dcbst   r0, r3
    addi    r3, r3, 0x20
    bdnz    B738_touchloop
    mfspr   r4, 920
    oris    r4, r4, 0x100F
    mtspr   920, r4
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lis     r3, 0xE000
    ori     r3, r3, 0x0002
    mtspr   543, r3
    ori     r3, r3, 0x01FE
    mtspr   542, r3
    isync
    lis     r3, 0xE000
    li      r6, 512
    mtctr   r6
    li      r6, 0
B738_lockloop:
    dcbz_l  r6, r3
    addi    r3, r3, 0x20
    bdnz    B738_lockloop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    blr
}

void fn_8000B804(void)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    __LCEnable();
    OSRestoreInterrupts(enabled);
}

asm void LCDisable(void)
{
    nofralloc
    lis     r3, 0xE000
    li      r4, 512
    mtctr   r4
B83C_loop:
    dcbi    r0, r3
    addi    r3, r3, 0x20
    bdnz    B83C_loop
    mfspr   r4, 920
    rlwinm  r4, r4, 0, 4, 2
    mtspr   920, r4
    blr
}

asm void LCLoadBlocks(register void* destTag, register void* srcAddr,
                      register u32 numBlocks)
{
    nofralloc
    extrwi  r6, r5, 5, 25
    clrlwi  r4, r4, 4
    or      r6, r6, r4
    mtspr   922, r6
    clrlslwi r6, r5, 30, 2
    or      r6, r6, r3
    ori     r6, r6, 0x12
    mtspr   923, r6
    blr
}

asm void LCStoreBlocks(register void* destAddr, register void* srcTag,
                       register u32 numBlocks)
{
    nofralloc
    extrwi  r6, r5, 5, 25
    clrlwi  r3, r3, 4
    or      r6, r6, r3
    mtspr   922, r6
    clrlslwi r6, r5, 30, 2
    or      r6, r6, r4
    ori     r6, r6, 0x02
    mtspr   923, r6
    blr
}

asm void LCQueueWait(register u32 len)
{
    nofralloc
LCQueueWait_loop:
    mfspr   r4, 920
    extrwi  r4, r4, 4, 4
    cmpw    r4, r3
    bgt     LCQueueWait_loop
    blr
}

asm void L2GlobalInvalidate(void)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x10(r1)
    stw     r31, 0xC(r1)
    sync
    bl      PPCMfl2cr
    clrlwi  r3, r3, 1
    bl      PPCMtl2cr
    sync
    bl      PPCMfl2cr
    oris    r3, r3, 0x20
    bl      PPCMtl2cr
    b       L2GlobalInvalidate_1
L2GlobalInvalidate_1:
    b       L2GlobalInvalidate_2
L2GlobalInvalidate_2:
    bl      PPCMfl2cr
    clrlwi  r0, r3, 31
    cmplwi  r0, 0x0
    bne     L2GlobalInvalidate_2
    bl      PPCMfl2cr
    rlwinm  r3, r3, 0, 11, 9
    bl      PPCMtl2cr
    b       L2GlobalInvalidate_3
L2GlobalInvalidate_3:
    lis     r3, 0x8012
    addi    r31, r3, 0x2828
    b       L2GlobalInvalidate_4
L2GlobalInvalidate_4:
    b       L2GlobalInvalidate_6
L2GlobalInvalidate_5:
    mr      r3, r31
    crxor   6, 6, 6
    bl      DBPrintf
L2GlobalInvalidate_6:
    bl      PPCMfl2cr
    clrlwi  r0, r3, 31
    cmplwi  r0, 0x0
    bne     L2GlobalInvalidate_5
    lwz     r0, 0x14(r1)
    lwz     r31, 0xC(r1)
    addi    r1, r1, 0x10
    mtlr    r0
    blr
}

void DMAErrorHandler(s32 error, OSContext* context, ...)
{
    char* strBase;
    u32 hid2;

    strBase = (char*)0x80122828;
    hid2 = PPCMfhid2();

    OSReport(strBase + 0x2C);
    OSReport(strBase + 0x44, hid2, context->srr1);

    if (!(hid2 & 0x00F00000) || !(context->srr1 & 0x00200000)) {
        OSReport(strBase + 0x60);
        OSDumpContext(context);
        PPCHalt();
    }

    OSReport(strBase + 0x90);
    OSReport(strBase + 0xCC);

    if (hid2 & 0x00800000) {
        OSReport(strBase + 0x104);
    }
    if (hid2 & 0x00400000) {
        OSReport(strBase + 0x144);
    }
    if (hid2 & 0x00200000) {
        OSReport(strBase + 0x170);
    }
    if (hid2 & 0x00100000) {
        OSReport(strBase + 0x190);
    }

    PPCMthid2(hid2);
}

asm void __OSCacheInit(void)
{
    nofralloc
    mflr    r0
    stw     r0, 4(r1)
    stwu    r1, -0x10(r1)
    stw     r31, 0xC(r1)
    stw     r30, 8(r1)
    lis     r3, 0x8012
    addi    r31, r3, 0x2828
    bl      PPCMfhid0
    rlwinm  r0, r3, 0, 16, 16
    cmplwi  r0, 0x0
    bne     OSCacheInit_ic_done
    bl      ICEnable
    addi    r3, r31, 0x1AC
    crxor   6, 6, 6
    bl      DBPrintf
OSCacheInit_ic_done:
    bl      PPCMfhid0
    rlwinm  r0, r3, 0, 17, 17
    cmplwi  r0, 0x0
    bne     OSCacheInit_dc_done
    bl      DCEnable
    addi    r3, r31, 0x1C8
    crxor   6, 6, 6
    bl      DBPrintf
OSCacheInit_dc_done:
    bl      PPCMfl2cr
    clrrwi  r0, r3, 31
    cmplwi  r0, 0x0
    bne     OSCacheInit_l2_done
    bl      PPCMfmsr
    mr      r30, r3
    sync
    li      r3, 0x30
    bl      PPCMtmsr
    sync
    sync
    bl      PPCMfl2cr
    clrlwi  r3, r3, 1
    bl      PPCMtl2cr
    sync
    bl      L2GlobalInvalidate
    mr      r3, r30
    bl      PPCMtmsr
    bl      PPCMfl2cr
    oris    r0, r3, 0x8000
    rlwinm  r3, r0, 0, 11, 9
    bl      PPCMtl2cr
    addi    r3, r31, 0x1E4
    crxor   6, 6, 6
    bl      DBPrintf
OSCacheInit_l2_done:
    lis     r3, DMAErrorHandler@ha
    addi    r4, r3, DMAErrorHandler@l
    li      r3, 1
    bl      OSSetErrorHandler
    addi    r3, r31, 0x1FC
    crxor   6, 6, 6
    bl      DBPrintf
    lwz     r0, 0x14(r1)
    lwz     r31, 0xC(r1)
    lwz     r30, 8(r1)
    addi    r1, r1, 0x10
    mtlr    r0
    blr
}

#pragma pop
