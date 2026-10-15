/* Non-matching: best partial attempt (96.35% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "sdk_addresses.h"

typedef struct SoundEntry {
    u32 unk_0;
    u8 pad_4[0x2C];
    u32 unk_30;
    u32 unk_34;
} SoundEntry;

typedef struct SoundSlot {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3[0x11];
} SoundSlot;

typedef struct SoundBanks {
    void *bank0;
    void *bank1;
    u8 pad_8[8];
    u8 data[0x10];
} SoundBanks;

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6EA98;
u32 fzgx_obj_lbl_1_bss_6EA9C;
u32 lbl_1_bss_6EA9C__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_6EAA4;
u8 lbl_1_bss_6EAA4__fzgx_offset_1;
s8 fzgx_obj_lbl_1_bss_6EAA6;
u32 fzgx_obj_lbl_1_bss_6EAA8[2];
u8 fzgx_obj_lbl_1_bss_6EAB0;
u32 fzgx_obj_lbl_1_bss_6EAB4[4];
u8 lbl_1_bss_6EAB4__fzgx_offset_10;
u8 lbl_1_bss_6EAB4__fzgx_offset_11;
s8 fzgx_obj_lbl_1_bss_6EAC6;
u8 fzgx_obj_lbl_1_bss_6EAC6__b1;
u8 fzgx_obj_lbl_1_bss_6EAC6__b2;
u8 fzgx_obj_lbl_1_bss_6EAC6__b3;
u8 fzgx_obj_lbl_1_bss_6EAC6__b4;
u8 fzgx_obj_lbl_1_bss_6EAC6__b5;
u8 fzgx_obj_lbl_1_bss_6EAC6__b6;
u8 fzgx_obj_lbl_1_bss_6EAC6__b7;
u8 fzgx_obj_lbl_1_bss_6EAC6__b8;
u8 fzgx_obj_lbl_1_bss_6EAC6__b9;
u32 fzgx_obj_lbl_1_bss_6EAD0[2];
SoundEntry lbl_1_bss_6EAD0__fzgx_offset_8[32];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 fzgx_obj_lbl_1_bss_6F1E1;
SoundSlot fzgx_obj_lbl_1_bss_6F1E4[4];
u8 lbl_1_bss_6F1E4__fzgx_offset_50[4];
u8 lbl_1_bss_6F1E4__fzgx_offset_54;
u8 fzgx_obj_lbl_1_bss_6F239;
u32 fzgx_obj_lbl_1_bss_6F23C;
u8 lbl_1_bss_6F23C__fzgx_offset_4;
u8 lbl_1_bss_6F23C__fzgx_offset_5;
u8 lbl_1_bss_6F23C__fzgx_offset_6;
u8 fzgx_obj_lbl_1_bss_6F243;
u8 fzgx_obj_lbl_1_bss_6F244;
u8 lbl_1_bss_6F244__fzgx_offset_1;
u8 lbl_1_bss_6F244__fzgx_offset_1__b1;
u8 lbl_1_bss_6F244__fzgx_offset_1__b2;
u8 lbl_1_bss_6F244__fzgx_offset_4[4];
u32 lbl_1_bss_6F244__fzgx_offset_8[30];
u8 fzgx_obj_lbl_1_bss_6F2C4;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_6EA98;
    s = fzgx_obj_lbl_1_bss_6EA9C;
    s = lbl_1_bss_6EA9C__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_6EAA4;
    s = lbl_1_bss_6EAA4__fzgx_offset_1;
    s = fzgx_obj_lbl_1_bss_6EAA6;
    s = fzgx_obj_lbl_1_bss_6EAA8[0];
    s = fzgx_obj_lbl_1_bss_6EAB0;
    s = fzgx_obj_lbl_1_bss_6EAB4[0];
    s = lbl_1_bss_6EAB4__fzgx_offset_10;
    s = lbl_1_bss_6EAB4__fzgx_offset_11;
    s = fzgx_obj_lbl_1_bss_6EAC6;
    s = fzgx_obj_lbl_1_bss_6EAC6__b1;
    s = fzgx_obj_lbl_1_bss_6EAC6__b2;
    s = fzgx_obj_lbl_1_bss_6EAC6__b3;
    s = fzgx_obj_lbl_1_bss_6EAC6__b4;
    s = fzgx_obj_lbl_1_bss_6EAC6__b5;
    s = fzgx_obj_lbl_1_bss_6EAC6__b6;
    s = fzgx_obj_lbl_1_bss_6EAC6__b7;
    s = fzgx_obj_lbl_1_bss_6EAC6__b8;
    s = fzgx_obj_lbl_1_bss_6EAC6__b9;
    s = fzgx_obj_lbl_1_bss_6EAD0[0];
    s = lbl_1_bss_6EAD0__fzgx_offset_8[0].unk_0;
    s = fzgx_obj_lbl_1_bss_6F1D8;
    s = fzgx_obj_lbl_1_bss_6F1DC;
    s = fzgx_obj_lbl_1_bss_6F1E0;
    s = fzgx_obj_lbl_1_bss_6F1E1;
    s = fzgx_obj_lbl_1_bss_6F1E4[0].unk_0;
    s = lbl_1_bss_6F1E4__fzgx_offset_50[0];
    s = lbl_1_bss_6F1E4__fzgx_offset_54;
    s = fzgx_obj_lbl_1_bss_6F239;
    s = fzgx_obj_lbl_1_bss_6F23C;
    s = lbl_1_bss_6F23C__fzgx_offset_4;
    s = lbl_1_bss_6F23C__fzgx_offset_5;
    s = lbl_1_bss_6F23C__fzgx_offset_6;
    s = fzgx_obj_lbl_1_bss_6F243;
    s = fzgx_obj_lbl_1_bss_6F244;
    s = lbl_1_bss_6F244__fzgx_offset_1;
    s = lbl_1_bss_6F244__fzgx_offset_1__b1;
    s = lbl_1_bss_6F244__fzgx_offset_1__b2;
    s = lbl_1_bss_6F244__fzgx_offset_4[0];
    s = lbl_1_bss_6F244__fzgx_offset_8[0];
    s = fzgx_obj_lbl_1_bss_6F2C4;
}
#pragma section code_type ".text"

extern u32 OSGetTick(void);
extern void fn_1_A04C4(void);
extern void fn_1_A0D7C(void);
extern void *fn_8004CD70(u32, void *, u32);
extern void *fn_80008BEC(void *, s32, u32);
extern void fn_1_A2E24(u32, u32, u32);
extern void fn_1_A2DF4(u32, u32, u32);

static inline void sound_wait(void) {
    lbl_1_bss_6EA9C__fzgx_offset_4 = OSGetTick();
    fzgx_obj_lbl_1_bss_6EAA4 = 1;
    while (fzgx_obj_lbl_1_bss_6EAA4 != 0) {
        if (OSGetTick() - lbl_1_bss_6EA9C__fzgx_offset_4 >= (__OSBusClock / 4) / 1000 * 100) {
            fzgx_obj_lbl_1_bss_6EAA4 = 0;
            lbl_1_bss_6EAA4__fzgx_offset_1 = 1;
            fn_1_A04C4();
        }
    }
}

static inline u8 * fn_1_A0680_read_pointer(SoundBanks * owner) { return owner->data; }
#pragma peephole off
void fn_1_A0680(void) {
    s32 i;

    if (lbl_1_bss_6EAA4__fzgx_offset_1 != 0) {
        return;
    }
    sound_wait();
    fn_1_A0D7C();
    sound_wait();
    if ((SoundBanks *)fzgx_obj_lbl_1_bss_6EAD0[0] != NULL) {
        SoundBanks *banks = (SoundBanks *)fzgx_obj_lbl_1_bss_6EAD0[0];
        if (banks->bank0 == NULL) {
            ((SoundBanks *)fzgx_obj_lbl_1_bss_6EAD0[0])->bank0 = fn_8004CD70(2, fn_1_A0680_read_pointer(banks), 0x4A248);
        }
        if (((SoundBanks *)fzgx_obj_lbl_1_bss_6EAD0[0])->bank1 == NULL) {
            ((SoundBanks *)((0)[fzgx_obj_lbl_1_bss_6EAD0]))->bank1 =
                fn_8004CD70(2, (u8 *)fzgx_obj_lbl_1_bss_6EAD0[0] + 0x4A258, 0x4A248);
        }
    }
    fzgx_obj_lbl_1_bss_6EAC6 = 1;
    fzgx_obj_lbl_1_bss_6EAA6 = 1;
    fn_80008BEC(fzgx_obj_lbl_1_bss_6F1E4, 0, sizeof(fzgx_obj_lbl_1_bss_6F1E4));
    for (i = 0; i < 4; i++) {
        fzgx_obj_lbl_1_bss_6F1E4[i].unk_1 = 0xFF;
        fzgx_obj_lbl_1_bss_6F1E4[i].unk_2 = 0;
        lbl_1_bss_6F1E4__fzgx_offset_50[i] = 0;
    }
    fn_80008BEC(lbl_1_bss_6EAD0__fzgx_offset_8, 0, sizeof(lbl_1_bss_6EAD0__fzgx_offset_8));
    fzgx_obj_lbl_1_bss_6EAB4[0] = 0;
    lbl_1_bss_6F1E4__fzgx_offset_54 = 0;
    fzgx_obj_lbl_1_bss_6F239 = 0;
    fzgx_obj_lbl_1_bss_6F23C = 0;
    lbl_1_bss_6EAB4__fzgx_offset_10 = 0xFF;
    lbl_1_bss_6F23C__fzgx_offset_4 = 0;
    lbl_1_bss_6F23C__fzgx_offset_5 = 0;
    lbl_1_bss_6F23C__fzgx_offset_6 = 0;
    fzgx_obj_lbl_1_bss_6F243 = 0;
    fzgx_obj_lbl_1_bss_6F244 = 1;
    if (lbl_1_bss_6F244__fzgx_offset_1 != 0) {
        fn_1_A2E24(0x10, 0xA0010000, 0);
    } else {
        fn_1_A2E24(0x10, 0xA0010000, 0x7F);
    }
    fn_1_A2E24(0x10, 0xA0100000, 0x7F);
    fn_1_A2DF4(0x10, 0xA5100000, 0);
    fn_1_A2DF4(0, 0xA6000000, 0);
    fn_1_A2DF4(1, 0xA6000000, 0);
    fn_1_A2DF4(2, 0xA6000000, 0);
    fn_1_A2DF4(3, 0xA6000000, 0);
    fn_1_A2DF4(6, 0xA6000000, 0);
    fn_1_A2DF4(7, 0xA6000000, 0);
    fn_1_A2DF4(5, 0xA6000000, 0);
    fn_1_A2DF4(4, 0xA6000000, 0);
    for (i = 0; i < 4; i++) {
        lbl_1_bss_6F244__fzgx_offset_4[i] = 9;
    }
}
#pragma peephole reset

