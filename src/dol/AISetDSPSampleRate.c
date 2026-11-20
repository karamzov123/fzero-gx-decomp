#include <types.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#include "types.h"


/* --- dol/AISetDSPSampleRate.c --- */
u32 AIGetDSPSampleRate();

u32 AIGetStreamPlayState();

u32 AIGetStreamSampleRate();

void AISetStreamVolLeft(u8 vol);

void AISetStreamVolRight(u8 vol);

u8 AIGetStreamVolLeft();

u8 AIGetStreamVolRight();

vu32 __AIRegs[8] : FZGX_ADDR___AIRegs;

void __AI_SRC_INIT(void);

static inline u32 AIGetStreamPlayState() { return __AIRegs[0] & 1; }

void AISetStreamVolLeft(u8 volume);

void AISetStreamVolRight(u8 volume);

void AISetDSPSampleRate(u32 rate) {
    u32 state;
    s32 oldInts;
    u8 left;
    u8 right;
    u32 sampleRate;
    if (rate == AIGetDSPSampleRate()) {
        return;
    }
    __AIRegs[0] &= ~0x40;
    if (rate == 0) {
        left = AIGetStreamVolLeft();
        right = AIGetStreamVolRight();
        state = AIGetStreamPlayState();
        sampleRate = AIGetStreamSampleRate();
        AISetStreamVolLeft(0);
        AISetStreamVolRight(0);
        oldInts = OSDisableInterrupts();
        __AI_SRC_INIT();
        __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20;
        __AIRegs[0] = (__AIRegs[0] & ~2) | (sampleRate * 2);
        __AIRegs[0] = (__AIRegs[0] & ~1) | state;
        __AIRegs[0] |= 0x40;
        OSRestoreInterrupts(oldInts);
        AISetStreamVolLeft(left);
        AISetStreamVolRight(right);
    }
}

/* --- dol/AIGetDSPSampleRate.c --- */
u32 AIGetDSPSampleRate(void) {
    return (((*(u32 *)0xCC006C00 >> 6) & 0x1) ^ 1);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

/* --- dol/__AI_set_stream_sample_rate.c --- */
void AISetStreamPlayState(u32 state);

u32 AIGetStreamPlayState();

u32 AIGetStreamSampleRate();

void AISetStreamVolLeft(u8 vol);

void AISetStreamVolRight(u8 vol);

u8 AIGetStreamVolLeft();

u8 AIGetStreamVolRight();


void __AI_SRC_INIT(void);


void AISetStreamVolLeft(u8 volume);

void AISetStreamVolRight(u8 volume);

void __AI_set_stream_sample_rate(u32 rate) {
    s32 oldInts;
    s32 state;
    u8 left;
    u8 right;
    s32 temp_r26;
    if (rate == AIGetStreamSampleRate()) {
        return;
    }
    state = AIGetStreamPlayState();
    left = AIGetStreamVolLeft();
    right = AIGetStreamVolRight();
    AISetStreamVolRight(0);
    AISetStreamVolLeft(0);
    temp_r26 = __AIRegs[0] & 0x40;
    __AIRegs[0] &= ~0x40;
    oldInts = OSDisableInterrupts();
    __AI_SRC_INIT();
    __AIRegs[0] |= temp_r26;
    __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20;
    __AIRegs[0] = (__AIRegs[0] & ~2) | (rate * 2);
    OSRestoreInterrupts(oldInts);
    AISetStreamPlayState(state);
    AISetStreamVolLeft(left);
    AISetStreamVolRight(right);
}

/* --- dol/AIGetStreamSampleRate.c --- */
u32 AIGetStreamSampleRate(void) {
    return ((*(u32 *)0xCC006C00 >> 1) & 0x1);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

/* --- dol/AISetStreamVolLeft.c --- */
void AISetStreamVolLeft(u8 volume) { __AIRegs[1] = (__AIRegs[1] & ~0xFF) | (volume & 0xFF); }

/* --- dol/AIGetStreamVolLeft.c --- */
#define AI_STREAM_VOL_LEFT_ADDR 0xCC006C04 // fzgx-allow: A1 hardware register address

u8 AIGetStreamVolLeft(void) {
    return *(volatile u32 *)AI_STREAM_VOL_LEFT_ADDR; // fzgx-allow: A2 hardware register access
}

/* --- dol/AISetStreamVolRight.c --- */
void AISetStreamVolRight(u8 volume) {
    __AIRegs[1] = (__AIRegs[1] & ~0xFF00) | ((volume & 0xFF) << 8);
}
