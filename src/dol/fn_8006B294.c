#include "types.h"

typedef struct Fn8006B294Flags {
    u8 flag7 : 1;
    u8 flag6 : 1;
    u8 rest : 6;
} Fn8006B294Flags;

typedef struct Fn8006B294Entry {
    u32 unk_0;
    Fn8006B294Flags flags;
    u8 _pad_5[3];
    u32 value;
    u8 _pad_c[8];
    s8 state;
    u8 _pad_15[0x38];
    s8 field_4d;
    u8 _pad_4e[0x11fa];
} Fn8006B294Entry;

extern u8 lbl_80199670[18720];

extern s32 fn_8006B3F0(Fn8006B294Entry *);
extern void fn_8006AA20(u32, u32);
extern s32 fn_80013428(s32, void *);
extern void fn_8006B048(Fn8006B294Entry *, s32);
extern void fn_800137C4(s32, void *);
extern void fn_8006AE90(void *, void *, void *);
extern void fn_8006BC1C(void *, Fn8006B294Entry *);

s32 fn_8006B294(s32 index, u32 *out) {
    s32 offset;
    Fn8006B294Entry *entry;
    u8 *data;
    s8 state;

    if (index >= 4 || index < 0) {
        return -2;
    }
    if (out == 0) {
        return -2;
    }

    offset = index * 0x1248;
    entry = (Fn8006B294Entry *)(lbl_80199670 + offset);
    if (entry->flags.flag6) {
        fn_8006B3F0(entry);
    }
    if (entry->flags.flag7) {
        *out = entry->value;
        return -3;
    }
    if (fn_80013428(index, fn_8006AA20) != -1) {
    fn_8006B048(entry, index);
    data = (u8 *)entry + 0xc;
    fn_800137C4(index, data);
    state = (lbl_80199670)[offset + 0x14];
    switch (state) {
    case -1:
        ((s8 *)lbl_80199670)[offset + 0x4d] = -1;
        return -4;
    case 0:
        fn_8006AE90((u8 *)entry + 0x44, data, (u8 *)entry + 0x18);
        break;
    }
    (lbl_80199670)[offset + 0x4d] = 0;
    *out = (u32)entry;
    entry->unk_0 = index;
    entry->value = *out;
    fn_8006BC1C((u8 *)entry + 0x50, entry);
    entry->flags.flag7 = 1;
    return 0;
    }
    return -4;
}
