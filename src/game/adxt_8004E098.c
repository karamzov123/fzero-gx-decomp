#pragma push
#pragma force_active on

/* The server thread and the caller both poll these words, so every read is a
   real load. */
typedef struct AdxSrv {
    char pad0[4];
    int unk4;
    volatile int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    char pad1C[0xc];
    char unk28[0x318];
    char unk340[0x318];
    char unk658[0x318];
    char unk970[0x318];
    int unkC88;
    int unkC8C;
    int unkC90;
    volatile int unkC94;
    int unkC98;
    volatile int unkC9C;
    int unkCA0;
    int unkCA4;
    int unkCA8;
    volatile int unkCAC;
} AdxSrv;

typedef struct AdxCb {
    void (*fn)();
    void* arg;
} AdxCb;

extern void OSCancelThread();
extern void OSCreateThread();
extern int OSDisableInterrupts();
extern void OSDisableScheduler();
extern void OSEnableScheduler();
extern void OSRestoreInterrupts();
extern void OSResumeThread();
extern void OSSetThreadPriority();
extern void OSSuspendThread();
extern void* OSGetCurrentThread();
extern int fn_80011358();
extern void VIWaitForRetrace();
extern void CRI_SPSD_parser();
extern void criErr_CallErrCallback();
extern void fn_8004ED3C();
extern void fn_8004EFA8();
extern void fn_8004F00C();
extern void fn_8004F26C();
extern void fn_8004F55C();
extern void fn_8005466C();
extern void cvFsSetDefDev();
extern void fn_80055304();
extern void fn_800565F0();
extern void SVM_ServerExit();
extern void SVM_ServerInit();
extern void fn_80058C94();
extern void fn_80058D24();
extern void fn_80058DB4();
extern void fn_80058E44();
extern void fn_80058ED4();
extern void fn_80058EE4();
extern void fn_80058EF4();
extern void fn_80059028();
extern void SVM_ReportErrorString();
extern void svmUnlockServer();
extern void svmLockServer();
extern void fn_8005A668();
extern void fn_8005A678();
extern void fn_8005A680();
extern void fn_8005A688();
extern void fn_8005A698();
extern void fn_8005A74C();
extern void fn_8005A7F8();
extern void fn_8005A94C();
extern void fn_8005A95C();
extern void fn_8005B010();
extern void fn_8005B068();
extern void ADXTServerStateRequest();
extern void mfCiOpen_resource_mgr();
extern void fn_8005B464();
extern void fn_8005B534();
extern void fn_8005BCB4();
extern void fn_8005BDD4();
extern void fn_8005BE48();
extern void memset();
extern unsigned char _Internal_Error_adxm_goto_mwidle_border_str[49];
extern void fn_80056584();
extern void fn_8005A5A8();
extern unsigned char lbl_8017E5B8[4];
extern unsigned char lbl_8017B028[4];
extern void fn_8004ECF4();
extern unsigned char lbl_8009115C[4];
void fn_8004E7D4();
void fn_8004E8A0();
void fn_8004E8F8();
void fn_8004E9A8();
void fn_8004E9D8();
void fn_8004EA94();
void fn_8004EB00();
void fn_8004ECF4();
extern unsigned char lbl_80091198[72];
extern int lbl_8012B918[6];
extern AdxCb lbl_8012B930[];
extern int lbl_80178CB8[];
extern unsigned char lbl_8017E5BC[964];
extern unsigned char lbl_8017E980[];
extern unsigned char lbl_8017E984[31916];
extern void fn_80056584();
extern void fn_8005A5A8();


/* harvest: declarations carried over from the recovered
   candidate — the converted body below needs them. */
typedef struct {
    unsigned char _pad[0xc];
    int unkC;
} ADXTStruct;
asm void fn_8004E098(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r3
    lwz	r0, 0xc(r3)
    cmpwi	r0, 1
    bne     _8004e0c0
    li	r0, 2
    stw	r0, 0xc(r31)
_8004e0c0:
    lwz	r0, 0xc(r31)
    cmpwi	r0, 2
    bne     _8004e17c
    lwz	r0, 0x14(r31)
    cmpwi	r0, 1
    bne     _8004e10c
    lha	r0, 0x38(r31)
    addi	r6, r31, 0x28
    addi	r9, r31, 0x34
    stw	r0, 8(r1)
    lwz	r3, 0x18(r31)
    lwz	r4, 0x1c(r31)
    lwz	r5, 0x20(r31)
    lha	r7, 0x30(r31)
    lha	r8, 0x32(r31)
    lha	r10, 0x36(r31)
    bl      fn_8004F55C
    stw	r3, 0x10(r31)
    b       _8004e174
_8004e10c:
    addi	r0, r31, 0x34
    addi	r6, r31, 0x28
    stw	r0, 8(r1)
    addi	r8, r31, 0x2c
    lha	r0, 0x36(r31)
    stw	r0, 0xc(r1)
    lha	r0, 0x38(r31)
    stw	r0, 0x10(r1)
    lwz	r3, 0x18(r31)
    lwz	r4, 0x1c(r31)
    lwz	r5, 0x20(r31)
    lwz	r7, 0x24(r31)
    lha	r9, 0x30(r31)
    lha	r10, 0x32(r31)
    bl      fn_8004EFA8
    stw	r3, 0x10(r31)
    lwz	r0, 0x10(r31)
    srwi	r3, r0, 0x1f
    clrlwi	r0, r0, 0x1f
    xor	r0, r0, r3
    subf	r0, r3, r0
    cmpwi	r0, 1
    bne     _8004e174
    lis	r3, lbl_8017E5B8@ha
    li	r0, 1
    stw	r0, lbl_8017E5B8@l(r3)
_8004e174:
    li	r0, 3
    stw	r0, 0xc(r31)
_8004e17c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

int fn_8004E190(void *arg0)
{
    // provenance: original
    return *(int*)((char*)arg0 + 0x10);
}

// provenance: original
void fn_8004E198(void* p)
{
    if (*(int*)((char*)p + 0xc) == 3) {
        *(int*)((char*)p + 0xc) = 0;
    }
}

// provenance: original
void fn_8004E1B0(void* p)
{
    *(int*)((char*)p + 0xc) = 0;
    memset((char*)p + 0x28, 0, 8);
}

// provenance: original
void fn_8004E1E4(void* p)
{
    if (*(int*)((char*)p + 0xc) == 0) {
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 0xc) = 1;
    }
}

// provenance: original
int fn_8004E204(void* p, int a, int b, int c, int d)
{
    if (*(int*)((char*)p + 0xc) == 0) {
        *(int*)((char*)p + 0x14) = 2;
        *(int*)((char*)p + 0x18) = a;
        *(int*)((char*)p + 0x1c) = b;
        *(int*)((char*)p + 0x20) = c;
        *(int*)((char*)p + 0x24) = d;
        return 1;
    }
    return 0;
}

// provenance: original
int fn_8004E238(void* p, int a, int b, int c)
{
    if (*(int*)((char*)p + 0xc) == 0) {
        *(int*)((char*)p + 0x14) = 1;
        *(int*)((char*)p + 0x18) = a;
        *(int*)((char*)p + 0x1c) = b;
        *(int*)((char*)p + 0x20) = c;
        *(int*)((char*)p + 0x24) = 0;
        return 1;
    }
    return 0;
}

// provenance: harvest:runs.sqlite — ADXT_GetCmdState recovered from adxt_8004E098.c, compiled by natc5 at 2026-08-31T23:42 and scored 100 against main/game/adxt_8004E098; original reference not recorded
int ADXT_GetCmdState(void *arg0)
{
    return ((ADXTStruct *)arg0)->unkC;
}

// provenance: original
void fn_8004E278(void* p)
{
    if (p != 0) {
        *(int*)p = 0;
        memset(p, 0, 0x3c);
    }
}

// provenance: original
void fn_8004E2B0(void* p, short* a, short* b, short* c)
{
    *a = *(short*)((char*)p + 0x34);
    *b = *(short*)((char*)p + 0x36);
    *c = *(short*)((char*)p + 0x38);
}

// provenance: original
void fn_8004E2CC(void* p, short a, short b, short c)
{
    *(short*)((char*)p + 0x34) = a;
    *(short*)((char*)p + 0x36) = b;
    *(short*)((char*)p + 0x38) = c;
}

void fn_8004E2DC(void *a, void *b, void *c) {
// provenance: original fn_8004E2DC
    *(short *)b = *(short *)((char *)a + 0x28);
    *(short *)c = *(short *)((char *)a + 0x2a);
    *(short *)((char *)b + 2) = *(short *)((char *)a + 0x2c);
    *(short *)((char *)c + 2) = *(short *)((char *)a + 0x2e);
}


typedef signed short s16;
typedef struct {
    char pad[0x28];
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
} StructR3;
typedef struct {
    s16 unk0;
    s16 unk2;
} StructR45;
// provenance: original
void fn_8004E300(StructR3* r3, StructR45* r4, StructR45* r5) {
    r3->unk28 = r4->unk0;
    r3->unk2A = r5->unk0;
    r3->unk2C = r4->unk2;
    r3->unk2E = r5->unk2;
}

// provenance: original
void fn_8004E324(void* p, int a, void* src)
{
    CRI_SPSD_parser(src, a, (char*)p + 0x30, (char*)p + 0x32);
}

asm void fn_8004E354(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_8017E5BC@ha
    stw	r0, 0x14(r1)
    li	r0, 2
    addi	r3, r3, lbl_8017E5BC@l
    stw	r31, 0xc(r1)
    li	r31, 0
    stw	r30, 8(r1)
    mtctr	r0
_8004e37c:
    lwz	r0, 0(r3)
    cmpwi	r0, 0
    beq     _8004e420
    lwz	r0, 0x3c(r3)
    addi	r31, r31, 1
    addi	r3, r3, 0x3c
    cmpwi	r0, 0
    beq     _8004e420
    lwz	r0, 0x3c(r3)
    addi	r31, r31, 1
    addi	r3, r3, 0x3c
    cmpwi	r0, 0
    beq     _8004e420
    lwz	r0, 0x3c(r3)
    addi	r31, r31, 1
    addi	r3, r3, 0x3c
    cmpwi	r0, 0
    beq     _8004e420
    lwz	r0, 0x3c(r3)
    addi	r31, r31, 1
    addi	r3, r3, 0x3c
    cmpwi	r0, 0
    beq     _8004e420
    lwz	r0, 0x3c(r3)
    addi	r31, r31, 1
    addi	r3, r3, 0x3c
    cmpwi	r0, 0
    beq     _8004e420
    lwz	r0, 0x3c(r3)
    addi	r31, r31, 1
    addi	r3, r3, 0x3c
    cmpwi	r0, 0
    beq     _8004e420
    lwz	r0, 0x3c(r3)
    addi	r31, r31, 1
    addi	r3, r3, 0x3c
    cmpwi	r0, 0
    beq     _8004e420
    addi	r3, r3, 0x3c
    addi	r31, r31, 1
    bdnz    _8004e37c
_8004e420:
    cmpwi	r31, 0x10
    bne     _8004e430
    li	r3, 0
    b       _8004e494
_8004e430:
    mulli	r5, r31, 0x3c
    lis     r3, lbl_8017E5BC@ha
    li	r4, 0
    addi	r0, r3, lbl_8017E5BC@l
    add	r30, r0, r5
    li	r5, 0x3c
    mr	r3, r30
    bl      memset
    li	r0, 1
    lis	r3, 1
    stw	r0, 0(r30)
    li	r0, 0
    addi	r4, r3, -0x53bc
    addi	r5, r30, 0x30
    stw	r31, 4(r30)
    addi	r6, r30, 0x32
    li	r3, 0x1f4
    stw	r0, 8(r30)
    stw	r0, 0xc(r30)
    bl      CRI_SPSD_parser
    addi	r3, r30, 0x28
    li	r4, 0
    li	r5, 8
    bl      memset
    mr	r3, r30
_8004e494:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

// provenance: original
void fn_8004E4AC(void)
{
    memset(lbl_8017E5BC, 0, 0x3c0);
}

// provenance: original
void fn_8004E4DC(void)
{
    AdxSrv* g = (AdxSrv*)lbl_8017E980;

    if (--g->unk4 == 0) {
        g->unkCA4 = 0;
        OSSetThreadPriority(g->unk28, 1);
        while (g->unkCA0 == 0) {
            OSResumeThread(g->unk28);
        }

        OSCancelThread(g->unk340);
        OSCancelThread(g->unk658);

        g->unkCAC = 0;
        OSResumeThread(g->unk970);
        while (g->unkCA8 == 0) {
            OSResumeThread(g->unk970);
        }
        SVM_ServerExit();
    }
}

// provenance: original
int fn_8004E580(void)
{
    return *(int*)lbl_8017E984 != 0;
}

asm void fn_8004E59C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r5, lbl_8017E980@ha
    lis     r4, lbl_8009115C@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r5, lbl_8017E980@l
    stw	r30, 8(r1)
    mr	r30, r3
    addi	r3, r4, lbl_8009115C@l
    lwz	r0, 4(r31)
    lwz	r3, 0(r3)
    cmpwi	r0, 0
    bne     _8004e790
    bl      SVM_ServerInit
    lis     r3, fn_8004EB00@ha
    li	r4, 0
    addi	r3, r3, fn_8004EB00@l
    bl      fn_80058EE4
    lis     r3, fn_8004EA94@ha
    li	r4, 0
    addi	r3, r3, fn_8004EA94@l
    bl      fn_80058ED4
    cmplwi	r30, 0
    bne     _8004e63c
    lis     r3, lbl_8012B918@ha
    li	r8, 0x10
    addi	r7, r3, lbl_8012B918@l
    li	r6, 1
    li	r5, 8
    li	r4, 0xc
    li	r3, 0xe
    li	r0, 0x18
    stw	r8, 0x10(r7)
    stw	r6, 0(r7)
    stw	r5, 4(r7)
    stw	r4, 8(r7)
    stw	r3, 0xc(r7)
    stw	r0, 0x14(r7)
    b       _8004e670
_8004e63c:
    lwz	r3, 0(r30)
    lis	r4, lbl_8012B918@ha
    lwz	r0, 4(r30)
    stwu	r3, lbl_8012B918@l(r4)
    stw	r0, 4(r4)
    lwz	r3, 8(r30)
    lwz	r0, 0xc(r30)
    stw	r3, 8(r4)
    stw	r0, 0xc(r4)
    lwz	r3, 0x10(r30)
    lwz	r0, 0x14(r30)
    stw	r3, 0x10(r4)
    stw	r0, 0x14(r4)
_8004e670:
    lis     r3, lbl_8012B918@ha
    lis     r4, fn_8004E9A8@ha
    addi	r3, r3, lbl_8012B918@l
    addi	r6, r31, 0x6cb0
    lwz	r8, 4(r3)
    addi	r4, r4, fn_8004E9A8@l
    addi	r3, r31, 0x970
    li	r5, 0
    li	r7, 0x1000
    li	r9, 1
    addi	r6, r6, 0x1000
    bl      OSCreateThread
    lis     r3, lbl_8012B918@ha
    lis     r4, fn_8004E8F8@ha
    addi	r3, r3, lbl_8012B918@l
    addi	r6, r31, 0x4cb0
    lwz	r8, 8(r3)
    addi	r4, r4, fn_8004E8F8@l
    addi	r3, r31, 0x340
    li	r5, 0
    li	r7, 0x2000
    li	r9, 1
    addi	r6, r6, 0x2000
    bl      OSCreateThread
    lis     r3, lbl_8012B918@ha
    lis     r4, fn_8004E8A0@ha
    addi	r3, r3, lbl_8012B918@l
    addi	r6, r31, 0x2cb0
    lwz	r8, 0xc(r3)
    addi	r4, r4, fn_8004E8A0@l
    addi	r3, r31, 0x658
    li	r5, 0
    li	r7, 0x2000
    li	r9, 1
    addi	r6, r6, 0x2000
    bl      OSCreateThread
    lis     r3, lbl_8012B918@ha
    lis     r4, fn_8004E7D4@ha
    addi	r3, r3, lbl_8012B918@l
    addi	r6, r31, 0xcb0
    lwz	r8, 0x14(r3)
    addi	r4, r4, fn_8004E7D4@l
    addi	r3, r31, 0x28
    li	r5, 0
    li	r7, 0x2000
    li	r9, 1
    addi	r6, r6, 0x2000
    bl      OSCreateThread
    bl      OSGetCurrentThread
    li	r4, 1
    li	r0, 0
    stw	r3, 0x24(r31)
    addi	r3, r31, 0x340
    stw	r4, 0xc94(r31)
    stw	r4, 0xca4(r31)
    stw	r4, 0xc9c(r31)
    stw	r4, 0xcac(r31)
    stw	r0, 0xc90(r31)
    stw	r0, 0xca0(r31)
    stw	r0, 0xc98(r31)
    stw	r0, 0xca8(r31)
    stw	r0, 0xc8c(r31)
    bl      OSResumeThread
    addi	r3, r31, 0x658
    bl      OSResumeThread
    addi	r3, r31, 0x28
    bl      OSResumeThread
    lis     r4, fn_8004E9D8@ha
    li	r3, 6
    addi	r4, r4, fn_8004E9D8@l
    li	r5, 0
    bl      fn_80059028
_8004e790:
    lwz	r3, 4(r31)
    addi	r0, r3, 1
    stw	r0, 4(r31)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

// provenance: original
void fn_8004E7B4(void)
{
    fn_80058EF4();
}

asm void fn_8004E7D4(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis	r5, lbl_8017E980@ha
    lis     r4, lbl_8012B918@ha
    stw	r0, 0x24(r1)
    lis     r3, lbl_8012B930@ha
    stw	r31, 0x1c(r1)
    addi	r31, r3, lbl_8012B930@l
    stw	r30, 0x18(r1)
    addi	r30, r4, lbl_8012B918@l
    stw	r29, 0x14(r1)
    addi	r29, r5, lbl_8017E980@l
    b       _8004e870
_8004e808:
    lwz	r3, 0x1c(r29)
    addi	r0, r3, 1
    stw	r0, 0x1c(r29)
    bl      fn_80058C94
    cmpwi	r3, 0
    beq     _8004e82c
    lwz	r0, 0xc(r29)
    cmpwi	r0, 1
    bne     _8004e870
_8004e82c:
    lwz	r0, 0xc(r29)
    cmpwi	r0, 1
    bne     _8004e84c
    li	r0, 0
    lwz	r4, 0x14(r30)
    stw	r0, 0xc(r29)
    addi	r3, r29, 0x28
    bl      OSSetThreadPriority
_8004e84c:
    lis	r3, lbl_8012B930@ha
    lwz	r12, lbl_8012B930@l(r3)
    cmplwi	r12, 0
    beq     _8004e868
    lwz	r3, 4(r31)
    mtctr	r12
    bctrl	
_8004e868:
    addi	r3, r29, 0x28
    bl      OSSuspendThread
_8004e870:
    lwz	r0, 0xca4(r29)
    cmpwi	r0, 1
    beq     _8004e808
    li	r0, 1
    stw	r0, 0xca0(r29)
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

// provenance: original
void fn_8004E8A0(void)
{
    AdxSrv* g = (AdxSrv*)lbl_8017E980;

    while (g->unkC94 == 1) {
        VIWaitForRetrace();
        g->unk18++;
        fn_80058DB4();
    }
    g->unkC90 = 1;
}

// provenance: original
void fn_8004E8F8(void)
{
    AdxSrv* g = (AdxSrv*)lbl_8017E980;

    while (g->unkC9C == 1) {
        VIWaitForRetrace();
        g->unk14++;
        lbl_80178CB8[0]++;
        fn_80058E44();
        if (g->unkCA0 == 0) {
            OSResumeThread(g->unk28);
            if (lbl_8012B930[0].fn != 0) {
                lbl_8012B930[0].fn(lbl_8012B930[0].arg);
            }
        }
    }
    g->unkC98 = 1;
}

// provenance: original
void fn_8004E9A8(void)
{
    AdxSrv* g = (AdxSrv*)lbl_8017E980;

    while (g->unkCAC == 1) {
        g->unk10++;
    }
    g->unkCA8 = 1;
}

// provenance: original
void fn_8004E9D8(void)
{
    AdxSrv* g = (AdxSrv*)lbl_8017E980;
    int i;

    if (g->unkCA0 == 1) {
        return;
    }

    g->unkC = 1;
    OSSetThreadPriority(g->unk28, lbl_8012B918[0]);

    for (i = 0; i < 200000000; i++) {
        OSResumeThread(g->unk28);
        if (g->unkC == 0) {
            break;
        }
    }
    if (i == 200000000) {
        SVM_ReportErrorString(_Internal_Error_adxm_goto_mwidle_border_str);
    }
    OSSetThreadPriority(g->unk28, lbl_8012B918[5]);
}

// provenance: original
void fn_8004EA94(void)
{
    AdxSrv* g = (AdxSrv*)lbl_8017E980;
    void* self;

    g->unk8--;
    if (g->unk8 == 0) {
        self = OSGetCurrentThread();
        OSSuspendThread(g->unk970);
        OSSetThreadPriority(self, g->unkC88);
    }
}

// provenance: original
void fn_8004EB00(void)
{
    AdxSrv* g = (AdxSrv*)lbl_8017E980;
    int intr;
    void* self;
    int pri;

    if (g->unk8 == 0) {
        intr = OSDisableInterrupts();
        OSDisableScheduler();
        g->unkC8C = 1;
        self = OSGetCurrentThread();
        pri = fn_80011358();
        OSSetThreadPriority(self, lbl_8012B918[0]);
        g->unkC88 = pri;
        g->unkC8C = 0;
        OSEnableScheduler();
        OSRestoreInterrupts(intr);
        OSResumeThread(g->unk970);
    }
    g->unk8++;
}

// provenance: original
void fn_8004EBB4(void)
{
    svmUnlockServer();
}

// provenance: original
void fn_8004EBD4(void)
{
    svmLockServer();
}

// provenance: original
void fn_8004EBF4(void)
{
    fn_80058D24();
}

// provenance: original
void fn_8004EC14(void)
{
    VIWaitForRetrace();
}

asm void fn_8004EC34(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r5, lbl_80091198@ha
    lis	r4, fn_8004ECF4@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r5, lbl_80091198@l
    lwz	r0, 0x3c(r31)
    stw	r30, 8(r1)
    mr	r30, r3
    addi	r3, r4, fn_8004ECF4@l
    li	r4, 0
    bl      fn_8005466C
    lis     r4, fn_8005A5A8@ha
    addi	r3, r31, 0x40
    addi	r4, r4, fn_8005A5A8@l
    li	r5, 0
    bl      fn_80055304
    lis     r3, fn_8004ECF4@ha
    li	r4, 0
    addi	r3, r3, fn_8004ECF4@l
    bl      fn_8005466C
    lis     r4, fn_80056584@ha
    addi	r3, r31, 0x44
    addi	r4, r4, fn_80056584@l
    li	r5, 0
    bl      fn_80055304
    addi	r3, r31, 0x44
    bl      cvFsSetDefDev
    cmplwi	r30, 0
    beq     _8004ecc8
    lwz	r6, 0(r30)
    li	r3, 0
    li	r4, 0
    li	r5, 0
    bl      fn_800565F0
    b       _8004ecdc
_8004ecc8:
    li	r3, 0
    li	r4, 0
    li	r5, 0
    li	r6, 0
    bl      fn_800565F0
_8004ecdc:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

// provenance: original
void fn_8004ECF4(int unused, int b)
{
    criErr_CallErrCallback(b);
}

// provenance: original
void fn_8004ED18(void* p)
{
    fn_8004ED3C(*(int*)((char*)p + 0xc));
}

// provenance: original
void fn_8004ED3C(int a)
{
    fn_8005A668(a);
}

// provenance: original
int fn_8004ED5C(int a)
{
    fn_8005A680(a);
    return 0;
}

// provenance: original fn_8004ED80 (no-op stub: retail body is a single blr)
void fn_8004ED80(void)
{
}

// provenance: original
void fn_8004ED84(int a)
{
    fn_8005A678(a);
}

// provenance: original
void fn_8004EDA4(int a)
{
    fn_8005A688(a);
}

// provenance: original
void adxtSetHandleVolume(int a, int b)
{
    fn_8005A698(a, b);
}

// provenance: original
void fn_8004EDE4(int a, int b)
{
    fn_8005A74C(a, b);
}

// provenance: original
void fn_8004EE04(int a)
{
    fn_8005A7F8(a);
}

// provenance: original
void fn_8004EE24(int a, int b)
{
    fn_8005A94C(a, b);
}

// provenance: original
void fn_8004EE44(int a)
{
    fn_8005A95C(a);
}

// provenance: original
void fn_8004EE64(int a)
{
    fn_8005B010(a);
}

// provenance: original
void fn_8004EE84(int a)
{
    fn_8005B068(a);
}

// provenance: original
void ADXTServerStateRequest_wrapper(void* p, int a)
{
    ADXTServerStateRequest(p, a);
}

// provenance: original
void ADXT_GetResourceManager(void* p, int a)
{
    mfCiOpen_resource_mgr(p, a);
}

// provenance: original
void fn_8004EEE4(void* p)
{
    ADXTServerStateRequest(p, 0);
    mfCiOpen_resource_mgr(p, 0);
    fn_8005B464(p);
}

// provenance: original
void fn_8004EF28(void* p)
{
    fn_8005B534(p);
}

// provenance: original
void fn_8004EF48(void)
{
    fn_8005BE48();
}

// provenance: original
void fn_8004EF68(void)
{
    fn_8005BCB4();
}

// provenance: original
void fn_8004EF88(void)
{
    fn_8005BDD4();
}

asm void fn_8004EFA8(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis	r11, lbl_8017B028@ha
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    lwz	r0, lbl_8017B028@l(r11)
    lwz	r31, 0x28(r1)
    cmpwi	r0, 0
    lha	r12, 0x2e(r1)
    lha	r11, 0x32(r1)
    bne     _8004efe8
    stw	r31, 8(r1)
    stw	r12, 0xc(r1)
    stw	r11, 0x10(r1)
    bl      fn_8004F00C
    b       _8004eff8
_8004efe8:
    stw	r31, 8(r1)
    stw	r12, 0xc(r1)
    stw	r11, 0x10(r1)
    bl      fn_8004F26C
_8004eff8:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
