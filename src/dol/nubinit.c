#include "types.h"

#pragma sdata2 off

typedef union {
    u32 word;
    u8 byte[4];
} EndianTest;

extern void TRK_board_display(const char *);
extern u32 fn_80089380(void);
extern u32 gTRKBigEndian[];
extern void MWTRACE(u32, ...);
extern void usr_put_initialize(void);
extern s32 TRKInitializeEventQueue(void);
extern int TRKInitializeMessageBuffers(void);
extern int TRKInitializeDispatcher(void);
extern void InitializeProgramEndTrap(void);
extern s32 TRKInitializeSerialHandler(void);
extern s32 TRKInitializeTarget(void);
extern u32 gTRKInputPendingPtr[];
extern s32 TRKInitializeIntDrivenUART(u32, u32, u32, void *);
extern void TRKTargetSetInputPendingPtr(void *);

void TRKNubWelcome(void) {
    TRK_board_display("MetroTRK for GAMECUBE v2.0");
}

s32 TRKTerminateNub(void) {
    fn_80089380();
    return 0;
}

static inline u8 * TRKInitializeNub_read_pointer_read_pointer(EndianTest * owner) { return owner->byte; }
static inline u8 * TRKInitializeNub_read_pointer(EndianTest * owner) { return TRKInitializeNub_read_pointer_read_pointer(owner); }
static inline u8 * TRKInitializeNub_read_pointer_(EndianTest * owner) { return owner->byte; }
#pragma opt_dead_assignments off
int TRKInitializeNub(void)
{
    struct { int value; } result;
    int resultTemp;
    EndianTest endian;
    u32 lab_t0;

    result.value = 0;
    gTRKBigEndian[0] = 1;

    TRKInitializeNub_read_pointer_(&endian)[0] = 0x12;
    TRKInitializeNub_read_pointer_(&endian)[1] = 0x34;
    TRKInitializeNub_read_pointer_(&endian)[2] = 0x56;
    TRKInitializeNub_read_pointer(&endian)[3] = 0x78;

    if (((0x12345678) == (endian.word))) {
        gTRKBigEndian[0] = 1;
    } else if (endian.word == 0x78563412) {
        gTRKBigEndian[0] = 0;
    } else {
        result.value = 1;
    }

    lab_t0 = 1;
    MWTRACE(lab_t0, (const char *)"Initialize NUB\n");

    if (result.value == 0) {
        usr_put_initialize();
    }

    if (result.value == 0) {
        result.value = TRKInitializeEventQueue();
    }

    if (result.value == 0) {
        result.value = TRKInitializeMessageBuffers();
    }

    if (result.value == 0) {
        result.value = TRKInitializeDispatcher();
    }

    InitializeProgramEndTrap();

    if (result.value == 0) {
        result.value = TRKInitializeSerialHandler();
    }

    if (result.value == 0) {
        result.value = TRKInitializeTarget();
    }

    if (result.value == 0) {
        resultTemp = TRKInitializeIntDrivenUART(0xE100, 1, 0, &gTRKInputPendingPtr);
        TRKTargetSetInputPendingPtr(*(void **)&gTRKInputPendingPtr);
        if (resultTemp != 0) {
            result.value = resultTemp;
        }
    }

    return result.value;
}
#pragma opt_dead_assignments reset
