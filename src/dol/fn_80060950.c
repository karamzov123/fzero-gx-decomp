#include "types.h"

extern f32 fn_80088578(f32 x);

typedef struct {
    u8 unk_0;
    u8 unk_1;
    s16 unk_2;
} Fn80060950Range;

typedef struct {
    u8 unk_0;
    u8 unk_1;
} Fn80060950Table;

typedef struct {
    u8 pad_0[4];
    u8 unk_4;
    u8 pad_5[7];
    Fn80060950Table unk_C;
} Fn80060950Info;

typedef struct {
    u8 unk_0;
    u8 pad_1[2];
    u8 unk_3;
    u8 pad_4[0xE - 0x4];
    u8 unk_E;
    u8 pad_F[0x54 - 0xF];
} Fn80060950Channel;

typedef struct {
    u8 pad_00[0x20];
    s32 unk_20;
    u8 pad_24[0x84 - 0x24];
    u8 unk_84[1];
} Fn80060950Sample;

typedef struct {
    u8 pad_0[8];
    Fn80060950Sample *unk_8;
    u8 pad_C[4];
} Fn80060950Slot;

typedef struct {
    Fn80060950Slot unk_0[0x46];
    u8 pad_460;
    u8 unk_461;
    u8 pad_462[0x5A10 - 0x462];
    s16 unk_5A10;
    u8 pad_5A12[0x5A74 - 0x5A12];
    s16 unk_5A74[1];
} Fn80060950Root;

extern Fn80060950Channel lbl_80192D68[16];
extern Fn80060950Root *lbl_801A6C80;

s16 fn_80060950(Fn80060950Info *info, u8 value, u8 index, f32 *out_db, s16 *out_level) {
    Fn80060950Table *table = &info->unk_C;
    Fn80060950Range *range;
    Fn80060950Sample *sample;
    u8 *p;
    u8 i;
    u8 low = info->unk_4;
    u32 n;
    u8 b;
    f32 db;
    s16 level;

    range = (Fn80060950Range *)((u8 *)table + table->unk_1);
    for (i = 0; i < table->unk_0; range++, i++) {
        if (value <= range->unk_0) {
            break;
        }
        low = range->unk_0 + 1;
    }
    n = (range->unk_2 * (value - low)) >> 8;
    sample = lbl_801A6C80->unk_0[lbl_80192D68[index].unk_0].unk_8;
    /* sample->unk_84 + sample->unk_20, spelled as integers: retail adds the offset first (add r4,r3,r4) */
    p = (u8 *)(sample->unk_20 + (u32)sample + 0x84);
    n += range->unk_1;
    for (i = 0; i < n; i++) {
        p++;
    }
    b = *p;
    if (b != 0) {
        db = 20.0 * fn_80088578((f32)b / 255.0f);
    } else {
        db = -960.0f;
    }
    b = lbl_80192D68[index].unk_3;
    if (b != 0) {
        db += (f32)(20.0 * fn_80088578((f32)b / 127.0f));
    } else {
        db = -960.0f;
    }
    b = lbl_80192D68[index].unk_E;
    if (b != 0) {
        db += (f32)(20.0 * fn_80088578((f32)b / 127.0f));
    } else {
        db = -960.0f;
    }
    level = lbl_801A6C80->unk_5A74[index];
    b = lbl_801A6C80->unk_461;
    if (b != 0) {
        db += (f32)(20.0 * fn_80088578((f32)b / 127.0f));
    } else {
        db = -960.0f;
    }
    level += lbl_801A6C80->unk_5A10;
    *out_db = db;
    *out_level = level;
    level += (s16)(10.0f * db);
    if (level < -960) {
        level = -960;
    }
    return level;
}

