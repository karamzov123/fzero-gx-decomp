#include "types.h"

extern f32 fn_80088578(f32 x);

typedef struct {
    u8 pad00[0x15];
    u8 unk15;
    u8 pad16;
    u8 unk17;
    u8 unk18;
} Fn8005C5C8Info;

typedef struct {
    u8 pad00[3];
    u8 unk03;
    u8 unk04;
    u8 pad05[0x14 - 0x05];
    u8 *unk14;
    u8 pad18[0x20 - 0x18];
} Fn8005C5C8Slot;

typedef struct {
    u8 pad00[0x0A];
    u8 slot;
    u8 pad0B[0x24 - 0x0B];
    Fn8005C5C8Info *info;
    u8 pad28[0xA4 - 0x28];
    s32 unkA4;
    u8 padA8[0xB0 - 0xA8];
    s32 unkB0;
    u8 padB4[0x118 - 0xB4];
} Fn8005C5C8Entry;

typedef struct {
    u8 pad0000[0x590];
    Fn8005C5C8Slot slots[0x70];
    u8 pad1390[0x1400 - 0x1390];
    Fn8005C5C8Entry entries[1];
} Fn8005C5C8Root;

extern Fn8005C5C8Root *lbl_801A6C80;

/* 0..127 level byte -> attenuation in 0.1 dB units; zero means silence */
#define LEVEL(dst, v)                                                    \
    if ((v) != 0) {                                                      \
        dst = (s32)(10.0 * (20.0 * fn_80088578((f32)(v) / 127.0f)));     \
    } else {                                                             \
        dst = -904;                                                      \
    }

void fn_8005C5C8(s32 arg0) {
    u8 *ptr = lbl_801A6C80->slots[lbl_801A6C80->entries[arg0].slot].unk14;
    Fn8005C5C8Info *info;
    s32 left;
    s32 right;
    u8 v;
    u8 idx;

    if (ptr == NULL) {
        return;
    }
    info = lbl_801A6C80->entries[arg0].info;
    v = *ptr;
    if (info->unk15 != 0 || v == 0) {
        idx = lbl_801A6C80->entries[arg0].slot;
        LEVEL(left, lbl_801A6C80->slots[idx].unk03);
        LEVEL(right, lbl_801A6C80->slots[idx].unk04);
    } else {
        LEVEL(left, info->unk17);
        LEVEL(right, info->unk18);
    }
    lbl_801A6C80->entries[arg0].unkA4 = left;
    lbl_801A6C80->entries[arg0].unkB0 = right;
}
