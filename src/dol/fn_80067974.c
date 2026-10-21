#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "dol/globals.h"
#include "sdk_addresses.h"
u32 __OSBusClock : FZGX_ADDR___OSBusClock;
#define OS_BUS_CLOCK __OSBusClock
#define OS_TIMER_CLOCK (OS_BUS_CLOCK / 4)

typedef struct Fn80067974Timer {
    u8 active;
    u8 _pad_1[3];
    u32 rate;
    u8 _pad_8[4];
    u32 value;
    u8 _pad_10[0x18];
} Fn80067974Timer;

typedef struct Fn80067974Motion {
    u8 _pad_0[0xE];
    s16 x;
    s16 y;
} Fn80067974Motion;

typedef struct Fn80067974Obj {
    u8 _pad_0[0x146];
    u16 state;
} Fn80067974Obj;

typedef struct Fn80067974Slot {
    u8 type;
    u8 mode;
    u8 _pad_2[0xC];
    u16 count;
    s32 offset;
    u8 _pad_14[0x8];
    Fn80067974Motion *motion;
    u8 _pad_20[0xC];
    Fn80067974Obj *obj;
    u8 _pad_30[0x84];
    s32 x;
    s32 y;
    s32 z;
    u8 _pad_c0[0x58];
} Fn80067974Slot;

typedef struct Fn80067974Work {
    u8 _pad_0[0x240];
    u32 in[0x40];
    u32 out[0x40];
    u8 outCount;
    u8 inCount;
    u8 outRead;
    u8 _pad_443[0xD];
    u32 elapsed;
    u8 _pad_454[5];
    u8 outWrite;
    u8 inRead;
    u8 _pad_45B[2];
    u8 ready;
    u8 budget;
    u8 _pad_45F[9];
    u32 frames;
    u8 _pad_46C[0xD1C];
    Fn80067974Timer timers[0x10];
    Fn80067974Slot slots[0x40];
    u8 _pad_5A08[0x10C];
    u32 lastTick;
} Fn80067974Work;

#define WORK ((Fn80067974Work *)lbl_801A6C80)

extern u32 OSGetTick(void);
extern double floor(double);
extern void fn_8005FCD8(u32);
extern s32 fn_80026DB8(Fn80067974Obj *);
extern void fn_80026D90(Fn80067974Obj *, s32);
extern void fn_8006953C(u32);
extern void fn_8005FDE0(u32);
extern void fn_80068EB4(void);

void fn_80067974(void) {
    u32 tick;
    u32 elapsed;
    u8 i;
    u8 n;
    Fn80067974Motion *motion;
    u32 msg;
    s32 r;
    s32 active;
    u16 count;
    u8 type;

    if (WORK->ready != 1) {
        return;
    }
    WORK->ready = 0;
    tick = OSGetTick();
    /* OSTicksToMilliseconds, rounded */
    elapsed = (u32)floor((f32)(0.5 + (f32)(((tick - WORK->lastTick) * 8) / (OS_TIMER_CLOCK / 125000)) / 1000.0));
    WORK->elapsed = elapsed;
    if (elapsed != 0) {
        for (i = 0; i < 0x10; i++) {
            active = WORK->timers[i].active;
            if (active != 0 && !(active & 1)) {
                WORK->timers[i].value -= WORK->timers[i].rate * elapsed;
            }
        }
    }
    WORK->lastTick = tick;

    for (i = 0; i < 0x40; i++) {
        type = WORK->slots[i].type;
        if (type == 0xFF) {
            continue;
        }
        if (WORK->slots[i].obj->state == 0) {
            if (type != 4 || WORK->slots[i].mode != 0) {
                fn_8005FCD8(i);
            }
        } else if (WORK->slots[i].mode == 2) {
            if (type == 3) {
                r = fn_80026DB8(WORK->slots[i].obj);
                if (WORK->slots[i].count == 0 || r <= -450) {
                    fn_8005FCD8(i);
                } else {
                    WORK->slots[i].count--;
                    r += WORK->slots[i].offset;
                    fn_80026D90(WORK->slots[i].obj, r);
                }
            } else if (WORK->slots[i].count == 2 && WORK->slots[i].z == (s32)0xFC400000) {
                fn_8005FCD8(i);
            }
        } else if (WORK->slots[i].mode == 1) {
            if (WORK->slots[i].count == 0 && WORK->slots[i].z == 0) {
                motion = WORK->slots[i].motion;
                WORK->slots[i].x = motion->x << 16;
                WORK->slots[i].y = motion->y << 16;
                WORK->slots[i].count = 1;
            }
        }
    }

    n = WORK->budget;
    if (WORK->inCount != 0) {
        do {
            msg = WORK->in[WORK->inRead];
            if ((msg >> 24) == 0xA0) {
                if (WORK->outCount < 0x40) {
                    WORK->out[WORK->outWrite] = msg | 0x40;
                    WORK->outWrite = (WORK->outWrite + 1) & 0x3F;
                    WORK->outCount++;
                }
                fn_8006953C(msg | 0x40);
            } else if ((msg >> 24) < 0xA8) {
                if (WORK->outCount < 0x40) {
                    WORK->out[WORK->outWrite] = msg;
                    WORK->outWrite = (WORK->outWrite + 1) & 0x3F;
                    WORK->outCount++;
                }
            } else if ((msg >> 24) < 0xAD) {
                fn_8006953C(msg);
            } else {
                if (WORK->outCount < 0x40) {
                    WORK->out[WORK->outWrite] = msg;
                    WORK->outWrite = (WORK->outWrite + 1) & 0x3F;
                    WORK->outCount++;
                }
            }
            n--;
            WORK->in[WORK->inRead] = 0;
            WORK->inRead = (WORK->inRead + 1) & 0x3F;
            WORK->inCount--;
        } while (WORK->inCount != 0 && n != 0);
    }

    if (WORK->outCount != 0) {
        do {
            fn_8005FDE0(WORK->out[WORK->outRead]);
            WORK->out[WORK->outRead] = 0;
            WORK->outRead = (WORK->outRead + 1) & 0x3F;
            WORK->outCount--;
        } while (WORK->outCount != 0);
    }

    fn_80068EB4();
    WORK->frames++;
    WORK->ready = 1;
}
