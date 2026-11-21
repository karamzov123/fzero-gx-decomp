#include "types.h"


/* --- dol/fn_80026FE0.c --- */
typedef struct SoundChan {
    u8 pad_00[0x1C];
    u32 unk_1C;
    u8 pad_20[0x124];
    u16 unk_144;
    u8 pad_146[4];
    u16 unk_14A[18];
    u8 pad_16E[0x2E];
    u16 unk_19C;
    s16 unk_19E;
} SoundChan;

typedef struct SoundEntry {
    SoundChan *chan;
    u32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    u8 pad_14[8];
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    u16 unk_38;
    u16 unk_3A;
    u16 unk_3C;
    u16 unk_3E;
    u16 unk_40;
    u16 unk_42;
    u16 unk_44;
    u16 unk_46;
    u16 unk_48;
    u16 unk_4A;
    u16 unk_4C;
    u16 unk_4E;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
    u16 unk_56;
    u16 unk_58;
    u16 unk_5A;
    u16 unk_5C;
    u16 unk_5E;
} SoundEntry;

extern SoundEntry lbl_80176160[64];
extern u8 lbl_80128990[3008];
extern s32 lbl_801A6B80;
extern s32 lbl_801A6B84;
extern s32 lbl_801A6B88;

void AISetStreamVolLeft(u8 vol);
void AISetStreamVolRight(u8 vol);

static inline s32 get_curve(u8 *base, s32 idx) {
    s32 r;
    if (idx <= -904) {
        r = 0;
    } else if (idx >= 60) {
        r = 0xFF64;
    } else {
        r = *(u16 *)(base + (idx << 1) + 0x710);
    }
    return r;
}

void fn_80026FE0(void);

/* --- dol/fn_8002805C.c --- */
extern f32 lbl_801A7000;
extern f32 lbl_801A7004;
extern u32 fn_80028B2C(f32);
extern u32 fn_80028B34(f32);
extern u32 lbl_801A6B90;

void fn_8002805C(void) {
    lbl_801A6B90 = 0;
    fn_80028B34(lbl_801A7000);
    fn_80028B2C(lbl_801A7004);
}
