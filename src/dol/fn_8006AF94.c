#include "types.h"

typedef struct Fn8006AF94Flags {
    u8 flag7 : 1;
    u8 flag6 : 1;
    u8 rest : 6;
} Fn8006AF94Flags;

typedef struct Fn8006AF94Out {
    u16 buttons;
    u8 data[6];
    s8 status;
} Fn8006AF94Out;

typedef struct Fn8006AF94Entry {
    u32 unk_0;
    Fn8006AF94Flags flags;
    u8 _pad_5[3];
    u32 value;
    u8 _pad_c[8];
    s8 state;
    u8 _pad_15[0x38];
    s8 field_4d;
    u8 _pad_4e[0x11fa];
} Fn8006AF94Entry;

extern u8 lbl_80199670[18720];
extern void fn_800137C4(s32, void *);
extern void fn_8006AE90(void *, void *, void *);
extern void fn_8006C92C(void *);

void fn_8006AF94(void) {
    s32 off;
    u8 *base;
    s32 i;
    Fn8006AF94Entry *entry;
    Fn8006AF94Out *out;

    i = 0;
    base = lbl_80199670;
    do {
        entry = (Fn8006AF94Entry *)((u32)base + i * 0x1248);
        if (entry->flags.flag7) {
            out = (Fn8006AF94Out *)((u8 *)entry + 0xc);
            fn_800137C4(i, out);
            switch (out->status) {
            case -1:
                entry->field_4d = -1;
                entry->flags.flag6 = 1;
                break;
            case 0:
                fn_8006AE90(((0x44) + ((u8 *)entry)), out, (u8 *)entry + 0x18);
                fn_8006C92C((u8 *)entry + 0x50);
                break;
            }
        }
        i++;
        off += 0x1248;
    } while (i < 4);
}
