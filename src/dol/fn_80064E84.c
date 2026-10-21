#include "types.h"

struct Entry64E84 {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[0x16];
    u32 unk_1c;
};

struct Slot64E84 {
    u32 unk_0;
    u32 unk_4;
    u8 *unk_8;
    u32 unk_c;
};

struct Data64E84 {
    struct Slot64E84 slots[0x58];
    u8 pad_580[8];
    struct Entry64E84 entries[0x40];
};

extern struct Data64E84 *lbl_801A6C80;

static inline u8 *fn_80064E84_offset(s32 offset, u8 *base) {
    u8 *result;
    result = (u8 *)offset;
    result = base + (s32)result;
    return result;
}

void fn_80064E84(u8 arg0, u8 arg1) {
    u8 *a;
    u32 i;
    u16 v;

    a = lbl_801A6C80->slots[arg0].unk_8;
    if (lbl_801A6C80->entries[arg1].unk_1 & 2) {
        if (*(u32 *)(a + 0x28) != 0) {
            lbl_801A6C80->entries[arg1].unk_1c = (u32)a + *(u32 *)(a + 0x28);
        } else {
            lbl_801A6C80->entries[arg1].unk_1c = 0;
        }
        return;
    }
    a += *(u32 *)(a + 0x1c);
    {
        u8 *b;
        b = a;
        for (i = 0; i <= lbl_801A6C80->entries[arg1].unk_4; i++) {
            b += 2;
        }
        a = fn_80064E84_offset(*(u16 *)b, a);
        b = a;
        for (i = 0; i <= lbl_801A6C80->entries[arg1].unk_5; i++) {
            b += 2;
        }
        v = *(u16 *)b;
    }
    if (v != 0) {
        lbl_801A6C80->entries[arg1].unk_1c = v + (u32)a;
    } else {
        lbl_801A6C80->entries[arg1].unk_1c = 0;
    }
}
