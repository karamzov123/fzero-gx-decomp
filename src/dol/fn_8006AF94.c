#include "types.h"


/* --- dol/fn_8006AF94.c --- */
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
        entry = (Fn8006AF94Entry *)(base + i * 0x1248);
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

/* --- dol/fn_8006B048.c --- */
typedef struct Fn8006B048Flags {
    u8 flag7 : 1;
    u8 flag6 : 1;
    u8 rest : 6;
} Fn8006B048Flags;

typedef struct Fn8006B048Entry {
    s32 index;
    Fn8006B048Flags flags;
    u8 pad_5[3];
    s32 value;
    u16 field_c;
    u8 field_e;
    u8 field_f;
    u8 field_10;
    u8 field_11;
    u8 field_12;
    u8 field_13;
    s8 state;
    u8 pad_15[6];
    s8 field_1b;
    u8 field_1c;
    u8 field_1d;
    u8 field_1e;
    u8 field_1f;
    u8 field_20;
    u8 pad_21[4];
    u8 field_25;
    u8 field_26;
    u8 field_27;
    u8 field_28;
    u8 field_29;
    u8 field_2a;
    u8 pad_2b[4];
    u8 field_2f;
    u8 field_30;
    u8 field_31;
    u8 pad_32;
    u8 field_33;
    u8 field_34;
    u8 pad_35[15];
    u8 data_44[1];
} Fn8006B048Entry;


void fn_8006B048(Fn8006B048Entry *arg, s32 index) {
    s32 value;
    Fn8006B048Entry *entry = arg;
    entry->index = index;
    entry->flags.flag7 = 0;
    entry->flags.flag6 = 0;
    entry->value = -1;
    entry->field_c = 0;
    entry->field_e = 0;
    entry->field_f = 0;
    entry->field_10 = 128;
    entry->field_11 = 128;
    entry->field_12 = 128;
    entry->field_13 = 128;
    entry->state = -1;
    entry->field_1b = -64;
    entry->field_1f = 80;
    entry->field_20 = 80;
    entry->field_25 = 64;
    entry->field_29 = 176;
    entry->field_2a = 176;
    entry->field_2f = 6;
    entry->field_33 = 12;
    entry->field_34 = 12;
    entry->field_1c = 80;
    entry->field_1d = 80;
    value = entry->field_1c - entry->field_1d;
    value /= 2;
    if (value < -128) value = -128;
    else if (value > 127) value = 127;
    entry->field_1e = value;
    entry->field_26 = 176;
    entry->field_27 = 176;
    value = entry->field_26 - entry->field_27;
    value /= 2;
    if (value < -128) value = -128;
    else if (value > 127) value = 127;
    entry->field_28 = value;
    entry->field_30 = 10;
    entry->field_31 = 10;
    fn_8006AE90(entry->data_44, &entry->field_c, (u8 *)entry + 0x18);
}
