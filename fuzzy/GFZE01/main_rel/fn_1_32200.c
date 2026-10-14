/* Non-matching: best partial attempt (86.55% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/game.h"

typedef struct {
    u32 unk_0;
    s16 unk_4;
    u8 pad_6[0x46f];
    s8 unk_475;
    u8 pad_476[0x116];
    u32 unk_58C;
    u8 pad_590[0x49];
    u8 unk_5D9;
} Racer32200;
extern void fn_1_2E928(Racer32200 *);

typedef struct {
    u8 pad_0[0x1f84];
    s32 unk_1F84;
    u32 unk_1F88;
    u16 *unk_1F8C;
    u32 unk_1F90;
    u32 unk_1F94;
    u16 unk_1F98;
    u8 pad_1f9a[0xf7e];
    u8 unk_2F18;
    u8 unk_2F19;
    u8 unk_2F1A;
    u8 unk_2F1B;
    u8 unk_2F1C;
} State32200;

static inline void register_timer(State32200 *state, Racer32200 *obj, u16 *timers) {
    u32 tmp_ra1;
    u16 *slot;
    tmp_ra1 = state->unk_1F98;
    state->unk_1F90++;
    slot = &timers[obj->unk_475];
    if (tmp_ra1 == 0) {
        if (0 == state->unk_1F8C) {
            state->unk_1F84 = 0;
            state->unk_1F8C = slot;
        } else if (*state->unk_1F8C == 0 || state->unk_1F84 == 0) {
            state->unk_1F84 = 0;
            state->unk_1F8C = slot;
        }
    }
}
#define B8(off) (*(u8 *)((u8 *)base2 + (off)))
#define UPDATE_TIMER(limit, reset) \
{ \
    u16 *timers = (u16 *)(base + 0x14ec); \
    u16 time = fn_1_32200_array_read(timers, obj->unk_475); \
    if (time > (limit)) { \
        timers[obj->unk_475] = (reset); \
        register_timer(base2, obj, timers); \
    } else { \
        timers[obj->unk_475] = time - (time != 0); \
    } \
}

static inline u16 fn_1_32200_array_read(u16 *array, u32 index) { return array[index]; }
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_1_32200(Racer32200 *obj, s32 index) {
    u8 *base = &lbl_1_bss_3C00;
    State32200 *base2 = (State32200 *)(base + 0x20000);
    u32 lab_v;
    if (obj->unk_475 != -1) {
        u8 bit = 1 << obj->unk_475;
        u8 kind = 0xff;
    lab_v = obj->unk_0;
        if (lab_v & 0x10000000) {
            B8(0x2f18) |= bit;
            kind = 2;
        } else if (lab_v & 0x80) {
            B8(0x2f19) |= bit;
            kind = 0;
        } else if (lab_v & 0x800) {
            B8(0x2f1a) |= bit;
            kind = 1;
        }
        switch (kind) {
        case 0: UPDATE_TIMER(300, 300); break;
        case 1: UPDATE_TIMER(300, 300); break;
        case 2: UPDATE_TIMER(300, 300); break;
        default: UPDATE_TIMER(60, 0); break;
        }
        if (lbl_1_data_5B7C != 5) {
            ((u32 *)&lbl_1_data_3D544)[obj->unk_475] = 0;
        }
    }
    if (index != -1) {
        u32 bit = 1 << index;
        B8(0x2f1b) |= bit;
        if (obj->unk_58C & 0x10) {
            obj->unk_5D9++;
            if (obj->unk_5D9 > 60) {
                obj->unk_5D9 = 60;
                B8(0x2f1c) |= bit;
            }
        }
    }
    if (obj->unk_4 < *(u8 *)(base + 0x38)) {
        obj->unk_0 |= 0x08000000;
    }
    fn_1_2E928(obj);
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset

