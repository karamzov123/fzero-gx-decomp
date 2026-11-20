#include "types.h"


/* --- dol/fn_800566BC.c --- */
extern u32 lbl_80188970[];
extern u32 lbl_80188974[65];

void fn_800566BC(u32 arg0, u32 arg1) {
    if (arg0 == 0) {
        lbl_80188970[0] = 0;
        lbl_80188974[0] = 0;
    } else {
        lbl_80188970[0] = arg0;
        lbl_80188974[0] = arg1;
    }
}

/* --- dol/fn_800566F0.c --- */
extern u32 fn_800576DC(void);

void fn_800566F0(void) {
    fn_800576DC();
}

/* --- dol/fn_80056710.c --- */
extern u32 fn_80057728(void);

void fn_80056710(void) {
    fn_80057728();
}

/* --- dol/fn_80056730.c --- */
extern u32 fn_800565FC(u32, ...);
extern u32 lbl_80092188[];

u32 fn_80056730(u32 arg0, u32 arg1) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = (u32)&lbl_80092188;
    t0 = fn_800565FC((u32)v0);
    v0 = t0;
    } else {
    *(u8 *)((u8 *)v0 + 3) = arg1;
    }
    return v0;
}

/* --- dol/fn_8005676C.c --- */
typedef u32 (*fn_8005676C_Fn0)(u32, u32);
struct fn_8005676C_lbl_80188A78 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

extern struct fn_8005676C_lbl_80188A78 lbl_80188A78[];

void fn_8005676C(void) {
    u32 v0;
    u32 t0;
    if (lbl_80188A78[0].unk_0 != 0) {
    v0 = lbl_80188A78[0].unk_4;
    t0 = ((fn_8005676C_Fn0)lbl_80188A78[0].unk_0)(v0, lbl_80188A78[0].unk_8);
    v0 = t0;
    }
}

/* --- dol/fn_800567AC.c --- */
u32 fn_800567AC(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = (u32)&lbl_80092188;
    t0 = fn_800565FC((u32)v0);
    v0 = t0;
    v0 = -1;
    } else {
    v0 = *(u32 *)((u8 *)v0 + 20);
    }
    return v0;
}

/* --- dol/fn_800567EC.c --- */
extern u32 lbl_800921AC[];

u32 fn_800567EC(u32 arg0, u32 arg1) {
    u32 v0;
    u32 t0, t1;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = (u32)&lbl_80092188;
    t0 = fn_800565FC((u32)v0);
    v0 = t0;
    } else {
    if ((s32)arg1 < 0 || (s32)arg1 > (s32)*(u32 *)((u8 *)v0 + 24)) {
    v0 = (u32)&lbl_800921AC;
    t1 = fn_800565FC((u32)v0, arg1);
    v0 = t1;
    } else {
    *(u32 *)((u8 *)v0 + 20) = arg1;
    }
    }
    return v0;
}

/* --- dol/fn_80056850.c --- */
extern u32 lbl_800921D0[];

typedef struct {
    u32 key;
    u8 unk04[0x18];
    u32 val;
} Entry;

typedef struct {
    u8 unk00[0x38];
    Entry entries[16];
} Table;

u32 fn_80056850(u32 arg0, u32 arg1) {
    u32 v0;
    s32 v3;
    Table *tbl;

    v0 = arg0;
    if (arg0 == 0) {
    v0 = (u32)&lbl_80092188;
    fn_800565FC((u32)v0);
    v0 = 0;
    } else {
    tbl = (Table *)arg0;
    for (v3 = 0; v3 < 16; v3++) {
    if ((s32)tbl->entries[v3].key == (s32)arg1) {
    break;
    }
    }
    if (v3 == 16) {
    v0 = (u32)&lbl_800921D0;
    fn_800565FC((u32)v0, arg1);
    v0 = 0;
    } else {
    v0 = tbl->entries[v3].val;
    }
    }
    return v0;
}
