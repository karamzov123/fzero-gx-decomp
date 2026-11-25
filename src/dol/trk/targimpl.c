#include "types.h"

typedef enum {
    DS_NoError = 0x0,
    DS_StepError = 0x1,
    DS_ParameterError = 0x2,
    DS_EventQueueFull = 0x100,
    DS_NoMessageBufferAvailable = 0x300,
    DS_MessageBufferOverflow = 0x301,
    DS_MessageBufferReadError = 0x302,
    DS_DispatchError = 0x500,
    DS_InvalidMemory = 0x700,
    DS_InvalidRegister = 0x701,
    DS_CWDSException = 0x702,
    DS_UnsupportedError = 0x703,
    DS_InvalidProcessID = 0x704,
    DS_InvalidThreadID = 0x705,
    DS_OSError = 0x706,
    DS_Error800 = 0x800,
} DSError;

typedef enum {
    NUBEVENT_Null = 0,
    NUBEVENT_Shutdown = 1,
    NUBEVENT_Request = 2,
    NUBEVENT_Breakpoint = 3,
    NUBEVENT_Exception = 4,
    NUBEVENT_Support = 5,
} NubEventType;

typedef enum {
    VALIDMEM_Readable = 0,
    VALIDMEM_Writeable = 1,
} ValidMemoryOptions;

typedef int MessageBufferID;
typedef u32 NubEventID;

typedef struct TRKEvent {
    NubEventType eventType;
    NubEventID eventID;
    MessageBufferID msgBufID;
} TRKEvent;

typedef struct TRKBuffer {
    u32 mutex;
    BOOL isInUse;
    u32 length;
    u32 position;
    u8 data[0x880];
} TRKBuffer;

typedef struct Default_PPC {
    u32 GPR[32];
    u32 PC;
    u32 LR;
    u32 CR;
    u32 CTR;
    u32 XER;
} Default_PPC;

typedef struct Float_PPC {
    u64 FPR[32];
    u64 FPSCR;
    u64 FPECR;
} Float_PPC;

typedef struct Extended1_PPC_6xx_7xx {
    u32 SR[16];
    u32 TBL;
    u32 TBU;
    u32 HID0;
    u32 HID1;
    u32 MSR;
    u32 PVR;
    u32 IBAT0U;
    u32 IBAT0L;
    u32 IBAT1U;
    u32 IBAT1L;
    u32 IBAT2U;
    u32 IBAT2L;
    u32 IBAT3U;
    u32 IBAT3L;
    u32 DBAT0U;
    u32 DBAT0L;
    u32 DBAT1U;
    u32 DBAT1L;
    u32 DBAT2U;
    u32 DBAT2L;
    u32 DBAT3U;
    u32 DBAT3L;
    u32 DMISS;
    u32 DCMP;
    u32 HASH1;
    u32 HASH2;
    u32 IMISS;
    u32 ICMP;
    u32 RPA;
    u32 SDR1;
    u32 DAR;
    u32 DSISR;
    u32 SPRG0;
    u32 SPRG1;
    u32 SPRG2;
    u32 SPRG3;
    u32 DEC;
    u32 IABR;
    u32 EAR;
    u32 DABR;
    u32 PMC1;
    u32 PMC2;
    u32 PMC3;
    u32 PMC4;
    u32 SIA;
    u32 MMCR0;
    u32 MMCR1;
    u32 THRM1;
    u32 THRM2;
    u32 THRM3;
    u32 ICTC;
    u32 L2CR;
    u32 UMMCR2;
    u32 UBAMR;
    u32 UMMCR0;
    u32 UPMC1;
    u32 UPMC2;
    u32 USIA;
    u32 UMMCR1;
    u32 UPMC3;
    u32 UPMC4;
    u32 USDA;
    u32 MMCR2;
    u32 BAMR;
    u32 SDA;
    u32 MSSCR0;
    u32 MSSCR1;
    u32 PIR;
    u32 exceptionID;
    u32 GQR[8];
    u32 HID_G;
    u32 WPAR;
    u32 DMA_U;
    u32 DMA_L;
} Extended1_PPC_6xx_7xx;

typedef struct Extended2_PPC_6xx_7xx {
    u32 PSR[32][2];
} Extended2_PPC_6xx_7xx;

typedef struct ProcessorState_PPC {
    Default_PPC Default;
    Float_PPC Float;
    Extended1_PPC_6xx_7xx Extended1;
    Extended2_PPC_6xx_7xx Extended2;
    u32 transport_handler_saved_ra;
} ProcessorState_PPC;

typedef struct TRKState {
    u32 gpr[32];
    u32 lr;
    u32 ctr;
    u32 xer;
    u32 msr;
    u32 dar;
    u32 dsisr;
    BOOL isStopped;
    BOOL inputActivated;
    void *inputPendingPtr;
} TRKState;

typedef struct StopInfo_PPC {
    u32 PC;
    u32 PCInstruction;
    u16 exceptionID;
} StopInfo_PPC;

typedef struct TRKExceptionStatus {
    StopInfo_PPC exceptionInfo;
    u8 inTRK;
    u8 exceptionDetected;
} TRKExceptionStatus;

typedef struct TRKStepStatus {
    s32 active;
    s32 type;
    u32 count;
    u32 rangeStart;
    u32 rangeEnd;
} TRKStepStatus;

typedef struct ASMTemplate {
    u32 code[10];
} ASMTemplate;

typedef struct memRange {
    u8 *start;
    u8 *end;
    BOOL readable;
    BOOL writeable;
} memRange;

extern TRKState gTRKState;
extern ProcessorState_PPC gTRKCPUState;
extern TRKExceptionStatus gTRKExceptionStatus;
extern TRKStepStatus lbl_8015B884;
extern u8 gTRKRestoreFlags[9];
extern u32 lbl_80095BA8[];
extern ASMTemplate lbl_80095B30;
extern ASMTemplate lbl_80095B58;
extern ASMTemplate lbl_80095B80;
extern u8 lbl_801A5624[20];
extern const memRange lbl_80095B20[1];

extern void fn_80088764(TRKEvent *, NubEventType);
extern DSError TRKPostEvent(TRKEvent *);
extern u32 fn_8008AA04(u32, u32, u32, s32 *);
extern s32 fn_8008A91C(u32, s32 *);
extern u32 fn_8008A80C(u32, s32 *, u32, s32 *);
extern u32 fn_8008AD00(u32, u32, u32 *, s32 *, u32, u32);
extern void fn_8008AFF0(u32, u32);
extern u32 MWTRACE(u32, ...);
extern void *memset(void *, s32, u32);
extern void TRKAppendBuffer_ui8(u32, void *, u32);
extern s32 fn_8008AF58(s32);
extern int TRKAppendBuffer1_ui64(TRKBuffer *, u64);
extern int TRKReadBuffer1_ui64(TRKBuffer *, u64 *);
extern DSError TRKAppendBuffer_ui32(TRKBuffer *buffer, const u32 *data, int count);
extern DSError TRKReadBuffer_ui32(TRKBuffer *buffer, u32 *data, int count);
extern u32 fn_8008D154(u32);

extern u8 gTRKSaveState[];
extern u16 TRK_saved_exceptionID;
void TRKUARTInterruptHandler(void);
void TRKSaveExtended1Block(void);
void TRKRestoreExtended1Block(void);
void TRKPostInterruptEvent(void);
void TRKInterruptHandlerEnableInterrupts(void);
void TRKExceptionHandler(void);

/* MetroTRK Processor/ppc/Generic/targimpl.c: the MSR accessors, the MSR-switching byte copy,
 * the interrupt/exception entry points, TRKSwapAndGo and the trap stubs are CodeWarrior asm
 * functions in the original (mfmsr/mtmsr, SPRG and SRR access, rfi, tw traps, no compiler
 * frames); the target support routines are C. */
asm u32 fn_8008B0E0(void) {
    nofralloc
    mfmsr r3
    blr
}

asm void fn_8008B0E8(register u32 msr) {
    nofralloc
    mtmsr r3
    blr
}

asm void fn_8008B0F0(register u32 dst, register u32 src, register u32 n, register u32 writeMsr, register u32 readMsr) {
    nofralloc
    mfmsr r8
    li r10, 0x0
L_8008B0F8:
    cmpw r10, r5
    beq L_8008B120
    mtmsr r7
    sync
    lbzx r9, r10, r4
    mtmsr r6
    sync
    stbx r9, r10, r3
    addi r10, r10, 0x1
    b L_8008B0F8
L_8008B120:
    mtmsr r8
    sync
    blr
}

asm void TRKInterruptHandler(void) {
    nofralloc
    mtsrr0 r2
    mtsrr1 r4
    mfsprg r4, 3
    mfcr r2
    mtsprg 3, r2
    lis r2, gTRKState@h
    ori r2, r2, gTRKState@l
    lwz r2, 0x8c(r2)
    ori r2, r2, 0x8002
    xori r2, r2, 0x8002
    sync
    mtmsr r2
    sync
    lis r2, TRK_saved_exceptionID@h
    ori r2, r2, TRK_saved_exceptionID@l
    sth r3, 0x0(r2)
    cmpwi r3, 0x500
    bne L_8008B1F4
    lis r2, gTRKCPUState@h
    ori r2, r2, gTRKCPUState@l
    mflr r3
    stw r3, 0x42c(r2)
    bl TRKUARTInterruptHandler
    lis r2, gTRKCPUState@h
    ori r2, r2, gTRKCPUState@l
    lwz r3, 0x42c(r2)
    mtlr r3
    lis r2, gTRKState@h
    ori r2, r2, gTRKState@l
    lwz r2, 0xa0(r2)
    lbz r2, 0x0(r2)
    cmpwi r2, 0x0
    beq L_8008B1D8
    lis r2, gTRKExceptionStatus@h
    ori r2, r2, gTRKExceptionStatus@l
    lbz r2, 0xc(r2)
    cmpwi r2, 0x1
    beq L_8008B1D8
    lis r2, gTRKState@h
    ori r2, r2, gTRKState@l
    li r3, 0x1
    stb r3, 0x9c(r2)
    b L_8008B1F4
L_8008B1D8:
    lis r2, gTRKSaveState@h
    ori r2, r2, gTRKSaveState@l
    lwz r3, 0x88(r2)
    mtcrf 255, r3
    lwz r3, 0xc(r2)
    lwz r2, 0x8(r2)
    rfi
L_8008B1F4:
    lis r2, TRK_saved_exceptionID@h
    ori r2, r2, TRK_saved_exceptionID@l
    lhz r3, 0x0(r2)
    lis r2, gTRKExceptionStatus@h
    ori r2, r2, gTRKExceptionStatus@l
    lbz r2, 0xc(r2)
    cmpwi r2, 0x0
    bne TRKExceptionHandler
    lis r2, gTRKCPUState@h
    ori r2, r2, gTRKCPUState@l
    stw r0, 0x0(r2)
    stw r1, 0x4(r2)
    mfsprg r0, 1
    stw r0, 0x8(r2)
    sth r3, 0x2f8(r2)
    sth r3, 0x2fa(r2)
    mfsprg r0, 2
    stw r0, 0xc(r2)
    stmw r4, 0x10(r2)
    mfsrr0 r27
    mflr r28
    mfsprg r29, 3
    mfctr r30
    mfxer r31
    stmw r27, 0x80(r2)
    bl TRKSaveExtended1Block
    lis r2, gTRKExceptionStatus@h
    ori r2, r2, gTRKExceptionStatus@l
    li r3, 0x1
    stb r3, 0xc(r2)
    lis r2, gTRKState@h
    ori r2, r2, gTRKState@l
    lwz r0, 0x8c(r2)
    sync
    mtmsr r0
    sync
    lwz r0, 0x80(r2)
    mtlr r0
    lwz r0, 0x84(r2)
    mtctr r0
    lwz r0, 0x88(r2)
    mtxer r0
    lwz r0, 0x94(r2)
    mtdsisr r0
    lwz r0, 0x90(r2)
    mtdar r0
    lmw r3, 0xc(r2)
    lwz r0, 0x0(r2)
    lwz r1, 0x4(r2)
    lwz r2, 0x8(r2)
    b TRKPostInterruptEvent
}

asm void TRKExceptionHandler(void) {
    nofralloc
    lis r2, gTRKExceptionStatus@h
    ori r2, r2, gTRKExceptionStatus@l
    sth r3, 0x8(r2)
    mfsrr0 r3
    stw r3, 0x0(r2)
    lhz r3, 0x8(r2)
    cmpwi r3, 0x200
    beq L_8008B32C
    cmpwi r3, 0x300
    beq L_8008B32C
    cmpwi r3, 0x400
    beq L_8008B32C
    cmpwi r3, 0x600
    beq L_8008B32C
    cmpwi r3, 0x700
    beq L_8008B32C
    cmpwi r3, 0x800
    beq L_8008B32C
    cmpwi r3, 0x1000
    beq L_8008B32C
    cmpwi r3, 0x1100
    beq L_8008B32C
    cmpwi r3, 0x1200
    beq L_8008B32C
    cmpwi r3, 0x1300
    beq L_8008B32C
    b L_8008B338
L_8008B32C:
    mfsrr0 r3
    addi r3, r3, 0x4
    mtsrr0 r3
L_8008B338:
    lis r2, gTRKExceptionStatus@h
    ori r2, r2, gTRKExceptionStatus@l
    li r3, 0x1
    stb r3, 0xd(r2)
    mfsprg r3, 3
    mtcrf 255, r3
    mfsprg r2, 1
    mfsprg r3, 2
    rfi
}

asm void TRKSwapAndGo(void) {
    nofralloc
    lis r3, gTRKState@h
    ori r3, r3, gTRKState@l
    stmw r0, 0x0(r3)
    mfmsr r0
    stw r0, 0x8c(r3)
    mflr r0
    stw r0, 0x80(r3)
    mfctr r0
    stw r0, 0x84(r3)
    mfxer r0
    stw r0, 0x88(r3)
    mfdsisr r0
    stw r0, 0x94(r3)
    mfdar r0
    stw r0, 0x90(r3)
    li r1, -0x7ffe
    nor r1, r1, r1
    mfmsr r3
    and r3, r3, r1
    mtmsr r3
    lis r2, gTRKState@h
    ori r2, r2, gTRKState@l
    lwz r2, 0xa0(r2)
    lbz r2, 0x0(r2)
    cmpwi r2, 0x0
    beq L_8008B3D8
    lis r2, gTRKState@h
    ori r2, r2, gTRKState@l
    li r3, 0x1
    stb r3, 0x9c(r2)
    b TRKInterruptHandlerEnableInterrupts
L_8008B3D8:
    lis r2, gTRKExceptionStatus@h
    ori r2, r2, gTRKExceptionStatus@l
    li r3, 0x0
    stb r3, 0xc(r2)
    bl TRKRestoreExtended1Block
    lis r2, gTRKCPUState@h
    ori r2, r2, gTRKCPUState@l
    lmw r27, 0x80(r2)
    mtsrr0 r27
    mtlr r28
    mtcrf 255, r29
    mtctr r30
    mtxer r31
    lmw r3, 0xc(r2)
    lwz r0, 0x0(r2)
    lwz r1, 0x4(r2)
    lwz r2, 0x8(r2)
    rfi
}

asm void TRKInterruptHandlerEnableInterrupts(void) {
    nofralloc
    lis r2, gTRKState@h
    ori r2, r2, gTRKState@l
    lwz r0, 0x8c(r2)
    sync
    mtmsr r0
    sync
    lwz r0, 0x80(r2)
    mtlr r0
    lwz r0, 0x84(r2)
    mtctr r0
    lwz r0, 0x88(r2)
    mtxer r0
    lwz r0, 0x94(r2)
    mtdsisr r0
    lwz r0, 0x90(r2)
    mtdar r0
    lmw r3, 0xc(r2)
    lwz r0, 0x0(r2)
    lwz r1, 0x4(r2)
    lwz r2, 0x8(r2)
    b TRKPostInterruptEvent
}

DSError fn_8008C6E4(void *data, u32 start);
s32 fn_8008C730(u32 arg0, u32 arg1, u32 *arg2, u32 arg3, s32 arg4);
DSError fn_8008C87C(const void *addr, size_t length, ValidMemoryOptions readWriteable);

void TRKTargetSetInputPendingPtr(void *ptr) {
    gTRKState.inputPendingPtr = ptr;
}

s32 fn_8008B484(void) {
    gTRKState.isStopped = 1;
    return 0;
}

void TRKTargetSetStopped(u32 arg0) {
    gTRKState.isStopped = arg0;
}

u32 TRKTargetStopped(void) {
    return gTRKState.isStopped;
}

s32 TRKTargetSupportRequest(void) {
    s32 local_c;
    s32 local_8;
    TRKEvent event;
    u32 *p14;
    s32 state;
    s32 result;

    state = gTRKCPUState.Default.GPR[3];
    if (state != 0xD1 && state != 0xD0 && state != 0xD2 && state != 0xD3 && state != 0xD4) {
        fn_80088764(&event, NUBEVENT_Exception);
        TRKPostEvent(&event);
        return 0;
    }

    if (state == 0xD2) {
        result = fn_8008AA04(gTRKCPUState.Default.GPR[4], gTRKCPUState.Default.GPR[5] & 0xFF, gTRKCPUState.Default.GPR[6], &local_c);
        if (local_c == 0 && result != 0) {
            local_c = 1;
        }
        gTRKCPUState.Default.GPR[3] = local_c;
    } else if (state == 0xD3) {
        result = fn_8008A91C(gTRKCPUState.Default.GPR[4], &local_c);
        if (local_c == 0 && result != 0) {
            local_c = 1;
        }
        gTRKCPUState.Default.GPR[3] = local_c;
    } else if (state == 0xD4) {
        local_8 = *(s32 *)gTRKCPUState.Default.GPR[5];
        result = fn_8008A80C(gTRKCPUState.Default.GPR[4], &local_8, gTRKCPUState.Default.GPR[6] & 0xFF, &local_c);
        if (local_c == 0 && result != 0) {
            local_c = 1;
        }
        gTRKCPUState.Default.GPR[3] = local_c;
        *(s32 *)gTRKCPUState.Default.GPR[5] = local_8;
    } else {
        p14 = (u32 *)gTRKCPUState.Default.GPR[5];
        result = fn_8008AD00(gTRKCPUState.Default.GPR[4], gTRKCPUState.Default.GPR[6], p14, &local_c, 1, state == 0xD1 ? 1 : 0);
        if (local_c == 0 && result != 0) {
            local_c = 1;
        }
        gTRKCPUState.Default.GPR[3] = local_c;
        if (state == 0xD1) {
            fn_8008AFF0(gTRKCPUState.Default.GPR[6], *p14);
        }
    }

    gTRKCPUState.Default.PC += 4;
    return result;
}

u32 fn_8008B6BC(void) {
    return gTRKCPUState.Default.PC;
}

s32 fn_8008B6CC(u32 arg0, u32 arg1, u32 arg2) {
    struct { u32 unk_0, unk_4, unk_8, unk_c, unk_10; } *p;
    u32 v0;
    u32 v1;
    u32 t0;

    v0 = arg0;
    if ((s32)arg2 != 0) {
        v0 = 1795;
    } else {
        p = (void *)&lbl_8015B884;
        p->unk_c = v0;
        v0 = 1;
        p->unk_10 = arg1;
        p->unk_4 = 1;
        p->unk_0 = 1;
        t0 = MWTRACE(v0, (u32)&lbl_80095BA8);
        v0 = t0;
        v1 = p->unk_4;
        gTRKCPUState.Extended1.MSR = gTRKCPUState.Extended1.MSR | 1024;
        if ((s32)v1 == 0 || (s32)v1 == 16) {
            struct { u32 unk_0, unk_4, unk_8, unk_c, unk_10; } *p2 = (void *)&lbl_8015B884;
            v0 = p2->unk_8;
            p2->unk_8 = v0 - 1;
        }
        ((struct { u8 pad[0x98]; u32 unk_98; } *)&gTRKState)->unk_98 = 0;
        v0 = 0;
    }
    return v0;
}

s32 fn_8008B784(u32 arg0, u32 arg1) {
    TRKStepStatus *p;
    u32 v0;
    u32 v1;
    u32 t0;

    v0 = arg0;
    if ((s32)arg1 != 0) {
        v0 = 1795;
    } else {
        p = &lbl_8015B884;
        p->count = v0;
        v0 = 1;
        p->type = 0;
        p->active = 1;
        t0 = MWTRACE(v0, (u32)&lbl_80095BA8);
        v0 = t0;
        v1 = p->type;
        gTRKCPUState.Extended1.MSR = gTRKCPUState.Extended1.MSR | 1024;
        if (p->type == 0 || (s32)v1 == 16) {
            v0 = p->count;
            p->count = v0 - 1;
        }
        v0 = 0;
        gTRKState.isStopped = 0;
    }
    return v0;
}

void fn_8008B830(u32 arg0) {
    struct { u32 unk_0; } header;
    struct {
        u32 length;
        u8 type;
        u8 pad_5[3];
        u32 status;
        u32 header;
        u32 exception;
        u8 rest[0x2c];
    } data;
    u32 status;
    u32 saved_arg;

    saved_arg = arg0;
    memset(&data, 0, 0x40);
    data.length = 0x40;
    data.type = 0x91;
    status = gTRKExceptionStatus.exceptionInfo.PC;
    data.status = status;
    fn_8008C6E4(&header, status);
    data.header = header.unk_0;
    data.exception = gTRKExceptionStatus.exceptionInfo.exceptionID;
    TRKAppendBuffer_ui8(saved_arg, &data, 0x40);
}

void fn_8008B8B4(u32 arg0) {
    struct {
        u32 length;
        u8 type;
        u8 pad_5[3];
        u32 state;
        u32 header;
        u32 cpu;
        u8 rest[0x30];
    } data;
    u32 header;

    memset(&data, 0, 0x40);
    data.length = 0x40;
    data.type = 0x90;
    data.state = gTRKCPUState.Default.PC;
    fn_8008C6E4(&header, gTRKCPUState.Default.PC);
    data.header = header;
    data.cpu = gTRKCPUState.Extended1.exceptionID & 0xffff;
    TRKAppendBuffer_ui8(arg0, &data, 0x40);
}

s32 TRKTargetInterrupt(TRKEvent *arg0) {
    ProcessorState_PPC *p_cpu;
    s32 v0;
    s32 v1;
    s32 v3;

    v0 = 0;
    switch (arg0->eventType) {
    case NUBEVENT_Breakpoint:
    case NUBEVENT_Exception:
        if (lbl_8015B884.active != 0) {
            p_cpu = &gTRKCPUState;
            p_cpu->Extended1.MSR = p_cpu->Extended1.MSR & ~0x400;
            v1 = 1;
            if (lbl_8015B884.active != 0 && (p_cpu->Extended1.exceptionID & 0xFFFF) == 0xD00) {
                switch (lbl_8015B884.type) {
                case 0:
                    if (lbl_8015B884.count != 0) {
                        v1 = 0;
                    }
                    break;
                case 1:
                    if (p_cpu->Default.PC >= lbl_8015B884.rangeStart &&
                        p_cpu->Default.PC <= lbl_8015B884.rangeEnd) {
                        v1 = 0;
                    }
                    break;
                }
            }
            if (v1 != 0) {
                lbl_8015B884.active = 0;
            } else {
                lbl_8015B884.active = 1;
                MWTRACE(1, (u32)&lbl_80095BA8);
                v3 = lbl_8015B884.type;
                p_cpu->Extended1.MSR = p_cpu->Extended1.MSR | 0x400;
                if (v3 == 0 || v3 == 16) {
                    lbl_8015B884.count--;
                }
                gTRKState.isStopped = 0;
            }
        }
        if (lbl_8015B884.active == 0) {
            gTRKState.isStopped = 1;
            v0 = fn_8008AF58(0x90);
        }
        break;
    }
    return v0;
}

void TRKPostInterruptEvent(void) {
    NubEventType eventType;
    TRKEvent event;
    u32 inst;
    if (gTRKState.inputActivated) {
        gTRKState.inputActivated = 0;
    } else {
        switch (gTRKCPUState.Extended1.exceptionID & 0xFFFF) {
        case 0xd00:
        case 0x700:
            fn_8008C6E4(&inst, gTRKCPUState.Default.PC);
            if (inst == 0xfe00000) {
                eventType = NUBEVENT_Support;
            } else {
                eventType = NUBEVENT_Breakpoint;
            }
            break;
        default:
            eventType = NUBEVENT_Exception;
            break;
        }
        fn_80088764(&event, eventType);
        TRKPostEvent(&event);
    }
}

s32 fn_8008BB7C(u32 firstRegister, u32 lastRegister, TRKBuffer *buffer, u32 *bytesReadOrWritten, BOOL readRegisters) {
    TRKExceptionStatus *status;
    u32 sprVal;
    u32 val[2];
    TRKExceptionStatus save;
    ASMTemplate buf1;
    ASMTemplate buf2;
    ASMTemplate buf3;
    ASMTemplate buf_write;
    ASMTemplate buf_read;
    u32 reg;
    s32 err;

    if (lastRegister > 31) {
        return 0x701;
    }

    status = &gTRKExceptionStatus;
    save = *status;
    status->exceptionDetected = 0;

    buf1 = lbl_80095B30;
    buf1.code[0] = 0x7C98E2A6;
    buf1.code[1] = 0x90830000;
    buf1.code[9] = 0x4E800020;
    fn_8008AFF0((u32)&buf1, 0x28);
    ((void (*)(void *, void *))&buf1)(&sprVal, lbl_801A5624);

    sprVal |= 0xA0000000;

    buf2 = lbl_80095B30;
    buf2.code[0] = (0x8083U << 16);
    buf2.code[1] = 0x7C98E3A6;
    buf2.code[9] = 0x4E800020;
    fn_8008AFF0((u32)&buf2, 0x28);
    ((void (*)(void *, void *))&buf2)(&sprVal, lbl_801A5624);

    sprVal = 0;

    buf3 = lbl_80095B30;
    buf3.code[0] = (0x8083U << 16);
    buf3.code[1] = 0x7C90E3A6;
    buf3.code[9] = 0x4E800020;
    fn_8008AFF0((u32)&buf3, 0x28);
    ((void (*)(void *, void *))&buf3)(&sprVal, lbl_801A5624);

    *bytesReadOrWritten = 0;
    err = 0;
    for (reg = firstRegister; reg <= lastRegister && err == 0; reg++, *bytesReadOrWritten += 8) {
        if (readRegisters) {
            buf_write = lbl_80095B58;
            buf_write.code[0] = readRegisters ? ((reg << 21) | 0xF0030000) : ((reg << 21) | 0xE0030000);
            buf_write.code[9] = 0x4E800020;
            fn_8008AFF0((u32)&buf_write, 0x28);
            ((void (*)(void *, void *))&buf_write)(val, lbl_801A5624);
            err = TRKAppendBuffer1_ui64(buffer, *(u64 *)val);
        } else {
            TRKReadBuffer1_ui64(buffer, (u64 *)val);
            buf_read = lbl_80095B58;
            buf_read.code[0] = readRegisters ? ((reg << 21) | 0xF0030000) : ((reg << 21) | 0xE0030000);
            buf_read.code[9] = 0x4E800020;
            fn_8008AFF0((u32)&buf_read, 0x28);
            ((void (*)(void *, void *))&buf_read)(val, lbl_801A5624);
            err = 0;
        }
    }

    if (status->exceptionDetected != 0) {
        err = 0x702;
        *bytesReadOrWritten = 0;
    }

    gTRKExceptionStatus = save;
    return err;
}

DSError fn_8008BFB4(u32 firstRegister, u32 lastRegister, TRKBuffer *b, size_t *registersLengthPtr,
                    BOOL read) {
    TRKExceptionStatus tempExceptionStatus;
    int error;
    u32 *data;
    int count;
    if (lastRegister > 0x60) {
        return DS_InvalidRegister;
    }
    tempExceptionStatus = gTRKExceptionStatus;
    gTRKExceptionStatus.exceptionDetected = 0;
    *registersLengthPtr = 0;
    if (firstRegister <= lastRegister) {
        data = (u32 *)&gTRKCPUState.Extended1 + firstRegister;
        count = lastRegister - firstRegister + 1;
        *registersLengthPtr += count * sizeof(u32);
        if (read) {
            error = TRKAppendBuffer_ui32(b, data, count);
        } else {
            if (data <= &gTRKCPUState.Extended1.TBU &&
                (data + count - 1) >= &gTRKCPUState.Extended1.TBL) {
                gTRKRestoreFlags[0] = 1;
            }
            if (data <= &gTRKCPUState.Extended1.DEC &&
                (data + count - 1) >= &gTRKCPUState.Extended1.DEC) {
                *((u8 *)&gTRKRestoreFlags + 1) = 1;
            }
            error = TRKReadBuffer_ui32(b, data, count);
        }
    }
    if (gTRKExceptionStatus.exceptionDetected) {
        *registersLengthPtr = 0;
        error = DS_CWDSException;
    }
    gTRKExceptionStatus = tempExceptionStatus;
    return error;
}

static inline s32 ExecuteInstructions(u64 *value, ASMTemplate *instructions) {
    instructions->code[9] = 0x4E800020;
    fn_8008AFF0((u32)instructions, 40);
    ((void (*)(u64 *, void *))instructions)(value, lbl_801A5624);
    return 0;
}

static inline s32 AccessFPSCR(u64 *value, s32 read) {
    ASMTemplate instructions = lbl_80095B30;
    if (read) {
        instructions.code[0] = 0x7C9EFAA6;
        instructions.code[1] = 0x90830000;
    } else {
        instructions.code[0] = (32u << 26) | (4u << 21) | (3u << 16);
        instructions.code[1] = 0x7C9EFBA6;
    }
    return ExecuteInstructions(value, &instructions);
}

static inline s32 AccessFP(u32 reg, u64 *value, s32 read) {
    s32 result = 0;
    ASMTemplate instructions = lbl_80095B80;
    if (reg < 32) {
        u32 instruction = (reg << 21) | 0xC8030000;
        if (read) instruction = (reg << 21) | 0xD8030000;
        instructions.code[0] = instruction;
        result = ExecuteInstructions(value, &instructions);
    } else if (reg == 32) {
        *value &= 0xFFFFFFFFULL;
    } else if (reg == 33) {
        if (!read) *(u32 *)value = ((u32 *)value)[1];
        result = AccessFPSCR(value, read);
        if (read) *value = (u64)*(u32 *)value & 0xFFFFFFFFULL;
    }
    return result;
}

s32 fn_8008C124(u32 arg0, u32 arg1, TRKBuffer *arg2, u32 *arg3, s32 arg4) {
    TRKExceptionStatus *p_status;
    TRKExceptionStatus save;
    u64 value;
    u32 reg;
    s32 result;
    if (arg1 > 33) return 0x701;
    p_status = &gTRKExceptionStatus;
    save = *p_status;
    p_status->exceptionDetected = 0;
    fn_8008B0E8(fn_8008B0E0() | 0x2000);
    *arg3 = 0;
    reg = arg0;
    result = 0;
    while (reg <= arg1 && result == 0) {
        if (arg4) {
            AccessFP(reg, &value, arg4);
            result = TRKAppendBuffer1_ui64(arg2, value);
        } else {
            TRKReadBuffer1_ui64(arg2, &value);
            result = AccessFP(reg, &value, arg4);
        }
        *arg3 += 8;
        reg++;
    }
    if (p_status->exceptionDetected != 0) {
        *arg3 = 0;
        result = 0x702;
    }
    gTRKExceptionStatus = save;
    return result;
}

DSError TRKTargetAccessDefault(u32 firstRegister, u32 lastRegister, TRKBuffer *b, size_t *registersLengthPtr,
                               BOOL read) {
    DSError error;
    u32 count;
    u32 *data;
    TRKExceptionStatus tempExceptionStatus;
    if (lastRegister > 0x24) {
        return DS_InvalidRegister;
    }
    tempExceptionStatus = gTRKExceptionStatus;
    gTRKExceptionStatus.exceptionDetected = 0;
    data = gTRKCPUState.Default.GPR + firstRegister;
    count = (lastRegister - firstRegister) + 1;
    *registersLengthPtr = count * sizeof(u32);
    if (read) {
        error = TRKAppendBuffer_ui32(b, data, count);
    } else {
        error = TRKReadBuffer_ui32(b, data, count);
    }
    if (gTRKExceptionStatus.exceptionDetected) {
        *registersLengthPtr = 0;
        error = DS_CWDSException;
    }
    gTRKExceptionStatus = tempExceptionStatus;
    return error;
}

DSError fn_8008C6E4(void *data, u32 start) {
    u32 v0;
    u32 loc_8[2];
    u32 t0;
    loc_8[0] = 4;
    t0 = fn_8008C730((u32)data, start, loc_8, 0, 1);
    v0 = t0;
    if ((s32)t0 == 0) {
        if (loc_8[0] != 4) {
            v0 = 1792;
        }
    }
    return (DSError)v0;
}

s32 fn_8008C730(u32 arg0, u32 arg1, u32 *arg2, u32 arg3, s32 arg4) {
    TRKExceptionStatus *status;
    TRKExceptionStatus save;
    u32 v0;
    u32 v1;

    status = &gTRKExceptionStatus;
    save = *status;
    status->exceptionDetected = 0;

    v0 = fn_8008D154(arg1);
    v1 = fn_8008C87C((const void *)v0, *arg2, (ValidMemoryOptions)(arg4 == 0));
    if (v1 != 0) {
        *arg2 = 0;
    } else {
        u32 v2;
        u32 f;
        v2 = fn_8008B0E0();
        f = v2 | (gTRKCPUState.Extended1.MSR & 0x10);
        if (arg4 != 0) {
            fn_8008B0F0(arg0, v0, *arg2, v2, f);
        } else {
            fn_8008B0F0(v0, arg0, *arg2, f, v2);
            fn_8008AFF0(v0, *arg2);
            if (arg1 != v0) {
                fn_8008AFF0(arg1, *arg2);
            }
        }
    }
    if (status->exceptionDetected != 0) {
        *arg2 = 0;
        v1 = 0x702;
    }
    gTRKExceptionStatus = save;
    return v1;
}

#pragma auto_inline on
DSError fn_8008C87C(const void *addr, size_t length, ValidMemoryOptions readWriteable) {
    DSError err = DS_InvalidMemory;
    const u8 *start;
    const u8 *end;
    int i;
    start = addr;
    end = ((const u8 *)addr + (length - 1));
    if (end < start)
        return DS_InvalidMemory;
    for (i = 0; (i < (sizeof(lbl_80095B20) / sizeof(memRange))); i++) {
        if ((start <= lbl_80095B20[i].end) &&
            (end >= lbl_80095B20[i].start)) {
            if (((readWriteable == VALIDMEM_Readable) && !lbl_80095B20[i].readable) ||
                ((readWriteable == VALIDMEM_Writeable) && !lbl_80095B20[i].writeable)) {
                err = DS_InvalidMemory;
            } else {
                err = DS_NoError;
                if (start < lbl_80095B20[i].start)
                    err = fn_8008C87C(start, (lbl_80095B20[i].start - start),
                                      readWriteable);
                if ((err == DS_NoError) && (end > lbl_80095B20[i].end))
                    err = fn_8008C87C(lbl_80095B20[i].end,
                                      (end - lbl_80095B20[i].end), readWriteable);
            }
            break;
        }
    }
    return err;
}
#pragma auto_inline reset

asm void fn_8008CB20(void) {
    nofralloc
    twi 31, r0, 0x0
    blr
}

asm void fn_8008CB28(void) {
    nofralloc
    twi 31, r0, 0x0
    blr
}

asm void fn_8008CB30(void) {
    nofralloc
    twi 31, r0, 0x0
    blr
}

asm void fn_8008CB38(void) {
    nofralloc
    twi 31, r0, 0x0
    blr
}

