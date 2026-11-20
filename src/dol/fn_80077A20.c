#include "types.h"


/* --- dol/fn_80077A20.c --- */
extern void _savegpr_27(void);
extern u32 lbl_801A6DA4;
extern void lbl_8006DD14(void *arg0, void *arg1);
extern void _restgpr_27(void);

struct fn_80077A20_Arg0 {
    u16 unk_0;
    u8 pad_2[0x16];
    u16 index;
    u8 pad_1a[4];
    u8 count;
    u8 pad_1f[0x21];
    u8 data[1];
};

void *fn_80077A20(struct fn_80077A20_Arg0 *arg0, void **table) {
    u8 *entry;
    u8 *data;
    u8 i;

    entry = (u8 *)arg0 + (arg0->index << 5);
    entry += 0x40;
    data = entry;
    if (table == 0) {
        table = (void **)lbl_801A6DA4;
        i = 0;
        while (i < arg0->count) {
            *table = entry;
            entry += 0x30;
            table += 1;
            i += 1;
        }
    } else {
        i = 0;
        while (i < arg0->count) {
            lbl_8006DD14(entry, *table);
            entry += 0x30;
            table += 1;
            i += 1;
        }
    }
    return data;
}

/* --- dol/fn_80077AD0.c --- */
struct fn_80077AD0_Arg0 {
    u8 pad_0[0x1E];
    u8 unk_1E;
};


u32 fn_80077AD0(struct fn_80077AD0_Arg0 *arg0, u32 arg1) {
    u32 v0;
    s32 v1;
    s32 v2;

    v0 = arg1;
    v2 = 0;
    v1 = 0;
    while (v2 < (s32)arg0->unk_1E) {
        v2++;
        *(u32 *)((u8 *)lbl_801A6DA4 + v1) = v0;
        v0 += 48;
        v1 += 4;
    }
    return arg0->unk_1E;
}
