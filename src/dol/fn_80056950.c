#include "types.h"


/* --- dol/fn_80056950.c --- */
extern u32 fn_800565FC(u32, ...);
extern u32 lbl_80092188[];
extern u32 lbl_800921D0[];

typedef struct {
    s32 key;
    u8 unk04[0x14];
    s32 val;
    u8 unk1C[4];
} Entry;

typedef struct {
    u8 unk00[0x38];
    Entry entries[16];
} Table;

int fn_80056950(Table *tbl, int value) {
    int count;

    if (tbl == 0) {
        fn_800565FC((u32)&lbl_80092188);
        return -1;
    }

    for (count = 0; count < 16; count++) {
        if (tbl->entries[count].key == value) {
            break;
        }
    }

    if (count == 16) {
        fn_800565FC((u32)&lbl_800921D0);
        return -1;
    }

    return tbl->entries[count].val;
}

/* --- dol/fn_80056A50.c --- */
u32 fn_80056A50(s32 *arg0, s32 arg1) {
    s32 i;

    if (arg0 == 0) {
        fn_800565FC((u32)&lbl_80092188);
        return 0;
    }

    for (i = 0; i < 16; i++) {
        s32 v = arg0[i * 8 + 14];
        if (v == arg1) {
            break;
        }
    }

    if (i == 16) {
        fn_800565FC((u32)&lbl_800921D0);
        return 0;
    }

    return arg0[i * 8 + 15];
}

/* --- dol/fn_80056B50.c --- */
extern u32 lbl_800921F4[];

typedef struct {
    u8 pad20[0x20];
    u32 offset;
    u32 count;
    u8 pad2c[0x10];
    u32 values[1];
} Fn80056B50Data;

s32 fn_80056B50(Fn80056B50Data *arg0, s32 arg1) {
    if (arg0 == 0) {
        fn_800565FC((u32)&lbl_80092188);
        return -1;
    }
    if (arg1 < 0 || arg1 >= (s32)arg0->count) {
        fn_800565FC((u32)&lbl_800921F4);
        return -1;
    }
    arg1 = arg0->offset + arg1;
    arg0 = (Fn80056B50Data *)((u8 *)arg0 + (arg1 % 16) * 32);
    return arg0->values[0];
}

/* --- dol/fn_80056BE0.c --- */
u32 fn_80056BE0(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = (u32)&lbl_80092188;
    t0 = fn_800565FC(v0);
    v0 = t0;
    v0 = -1;
    } else {
    v0 = *(u32 *)(v0 + 36);
    }
    return v0;
}

/* --- dol/fn_80056C20.c --- */
u32 fn_80056C20(u32 arg0) {
    u32 v0;
    u32 t0;

    v0 = arg0;
    if (arg0 == 0) {
        v0 = (u32)&lbl_80092188;
        t0 = fn_800565FC(v0);
        v0 = t0;
        v0 = -1;
    } else {
        v0 = *(s8 *)(v0 + 1);
    }
    return v0;
}

/* --- dol/fn_80056C64.c --- */
extern void fn_80056710(void *);
extern void fn_800566F0(void *);
extern void fn_80057494(void *);

typedef struct Fn80056C64_Entry {
    s8 flag;
    u8 pad[0x237];
} Fn80056C64_Entry;

extern Fn80056C64_Entry lbl_80188A8C[16];

void fn_80056C64(void) {
    u8 local[16];
    s32 i;

    fn_80056710(local);
    i = 0;
    do {
        if (lbl_80188A8C[i].flag == 1) {
            fn_80057494(&lbl_80188A8C[i]);
        }
        i++;
    } while (i < 0x10);
    fn_800566F0(local);
}

/* --- dol/fn_80056CD0.c --- */
extern u32 fn_8004AC58(u32);

typedef struct Fn80056CD0 {
    u8 pad0[1];
    s8 flag1;
    s8 flag2;
    u8 pad3[0x19];
    u32 field1c;
    u32 field20;
    u32 field24;
    u32 resource;
    u32 field2c;
    u8 pad30[4];
    u32 field34;
} Fn80056CD0;

void fn_80056CD0(Fn80056CD0 *arg0) {
    if (arg0 == 0) {
        fn_800565FC((u32)&lbl_80092188);
    } else if (arg0->flag1) {
        arg0->flag1 = 0;
        if (arg0->resource != 0 && arg0->flag2 == 1) {
            fn_8004AC58(arg0->resource);
            arg0->flag2 = 0;
        }
        arg0->field2c = 0;
        if (arg0 == 0) {
            fn_800565FC((u32)&lbl_80092188);
        } else if (!arg0->flag1) {
            arg0->field1c = 0;
            arg0->field20 = 0;
            arg0->field24 = 0;
        }
        arg0->field34 = 0;
    }
}
