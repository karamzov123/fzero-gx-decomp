// MetroTRK nub init functions (0x80088910-0x80088B00).

#pragma push
#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

extern void fn_8008AF50(void*);
extern void TRKReleaseMutex_stub(void*);
extern void TRKAcquireMutex_stub(void*);
extern void TRK_board_display(char*);
extern void TRKAcquireMutex(void);
extern int usr_put_initialize(void);
extern int TRKInitializeEventQueue(void);
extern int TRKInitializeMessageBuffers(void);
extern int TRKInitializeDispatcher(void);
extern void InitializeProgramEndTrap(void);
extern int TRKInitializeSerialHandler(void);
extern int TRKInitializeTarget(void);
extern unsigned long TRKInitializeIntDrivenUART(unsigned long, unsigned long,
                                               unsigned long, void**);
extern void TRKTargetSetInputPendingPtr(void*);
extern void MWTRACE(unsigned long, char*, ...);
extern void* gTRKInputPendingPtr[];
extern unsigned char lbl_801A36B8[40];

// provenance: sms:src/TRK_MINNOW_DOLPHIN/debugger/embedded/MetroTRK/Portable/nubevent.c:8
#pragma dont_inline on
int TRKInitializeEventQueue(void)
{
    fn_8008AF50(&lbl_801A36B8);
    TRKReleaseMutex_stub((void*)(char(*)[40])&lbl_801A36B8);
    *(unsigned long*)(lbl_801A36B8 + 0x04) = 0;
    *(unsigned long*)(lbl_801A36B8 + 0x08) = 0;
    *(unsigned long*)(lbl_801A36B8 + 0x24) = 0x100;
    TRKAcquireMutex_stub((void*)lbl_801A36B8);
    return 0;
}
#pragma dont_inline reset


extern unsigned char TRKNubWelcomeMsg_80095648[27];
extern unsigned char TRKNubInitMsg_80095664[16];
extern int gTRKBigEndian[];

// provenance: original
int TRKNubWelcome(void) {
    TRK_board_display((char*)TRKNubWelcomeMsg_80095648);
}

// provenance: original
int TRKTerminateNub(void) {
    TRKAcquireMutex();
    return 0;
}

static inline int TRKInitializeEndian(void)
{
    u8 bendian[4];
    int result = 0;

    gTRKBigEndian[0] = 1;

    bendian[0] = 0x12;
    bendian[1] = 0x34;
    bendian[2] = 0x56;
    bendian[3] = 0x78;

    if (*(u32*)bendian == 0x12345678) {
        gTRKBigEndian[0] = 1;
    } else if (*(u32*)bendian == 0x78563412) {
        gTRKBigEndian[0] = 0;
    } else {
        result = 1;
    }

    return result;
}

// 0x800889B4 | size: 0x14C
// provenance: sms:src/TRK_MINNOW_DOLPHIN/debugger/embedded/MetroTRK/Portable/nubinit.c:16
int TRKInitializeNub(void)
{
    int result;
    int resultTemp;

    result = TRKInitializeEndian();

    MWTRACE(1, (char*)TRKNubInitMsg_80095664);

    if (result == 0) {
        usr_put_initialize();
    }

    if (result == 0) {
        result = TRKInitializeEventQueue();
    }

    if (result == 0) {
        result = TRKInitializeMessageBuffers();
    }

    if (result == 0) {
        result = TRKInitializeDispatcher();
    }

    InitializeProgramEndTrap();

    if (result == 0) {
        result = TRKInitializeSerialHandler();
    }

    if (result == 0) {
        result = TRKInitializeTarget();
    }

    if (result == 0) {
        resultTemp = TRKInitializeIntDrivenUART(0xE100, 1, 0, (void**)gTRKInputPendingPtr);
        TRKTargetSetInputPendingPtr(gTRKInputPendingPtr[0]);
        if (resultTemp != 0) {
            result = resultTemp;
        }
    }

    return result;
}

#pragma pop
