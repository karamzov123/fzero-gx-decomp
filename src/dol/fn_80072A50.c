#include "types.h"
#include "dol/globals.h"


/* --- dol/fn_80072A50.c --- */
extern void GXSetTevSwapModeTable(s32 index);

void fn_80072A50(u32 index, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 *entry = (u32 *)(lbl_801A6D38 + (index << 4) + 0x2c);

    GXSetTevSwapModeTable(index);
    entry[0] = arg1;
    entry[1] = arg2;
    entry[2] = arg3;
    entry[3] = arg4;
}

/* --- dol/fn_80072AB0.c --- */
extern void GXSetTevSwapMode(s32, s32, s32);

void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2) {
    s32 *entry;

    entry = (s32 *)(lbl_801A6D38 + (arg0 << 3) + 0x6c);
    if (entry[0] != arg1 || entry[1] != arg2) {
        GXSetTevSwapMode(arg0, arg1, arg2);
        entry[0] = arg1;
        entry[1] = arg2;
    }
}

/* --- dol/fn_80072B28.c --- */
extern void fn_80037B68(u32);

void fn_80072B28(u32 arg0) {
    if (*(u8 *)(lbl_801A6D38 + 0xec) != 0xff &&
        *(u8 *)(lbl_801A6D38 + 0xec) == (u8)arg0) {
        return;
    }

    fn_80037B68(arg0);
    *(u8 *)(lbl_801A6D38 + 0xec) = arg0;
}

/* --- dol/fn_80072B7C.c --- */
extern void fn_80037B94(u32);

void fn_80072B7C(u32 arg0) {
    if (*(u8 *)(lbl_801A6D38 + 0xed) != 0xff &&
        *(u8 *)(lbl_801A6D38 + 0xed) == (u8)arg0) {
        return;
    }

    fn_80037B94(arg0);
    *(u8 *)(lbl_801A6D38 + 0xed) = (u8)arg0;
}

/* --- dol/fn_80072BD0.c --- */
extern void GXSetZCompLoc(u32);

void fn_80072BD0(u32 arg0) {
    u8 value;

    value = *(u8 *)(lbl_801A6D38 + 0xee);
    if (value == 0xff || value != (u8)arg0) {
        GXSetZCompLoc(arg0);
        *(u8 *)(lbl_801A6D38 + 0xee) = arg0;
    }
}

/* --- dol/fn_80072C24.c --- */
extern void fn_800370A0(s32, s32, s32, s32, s32);

void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 *entry;

    entry = (u32 *)(lbl_801A6D38 + (arg0 << 4) + 0xf0);
    if ((s32)entry[0] == arg1 &&
        (s32)entry[1] == arg2 &&
        (s32)entry[2] == arg3 &&
        (s32)entry[3] == arg4) {
        return;
    }

    fn_800370A0(arg0, arg1, arg2, arg3, arg4);
    entry[0] = arg1;
    entry[1] = arg2;
    entry[2] = arg3;
    entry[3] = arg4;
}

/* --- dol/fn_80072CC4.c --- */
extern void fn_800370E4(s32, s32, s32, s32, s32);

void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 *entry;

    entry = (u32 *)(lbl_801A6D38 + (arg0 << 4) + 0x1f0);
    if ((s32)entry[0] == arg1 &&
        (s32)entry[1] == arg2 &&
        (s32)entry[2] == arg3 &&
        (s32)entry[3] == arg4) {
        return;
    }

    fn_800370E4(arg0, arg1, arg2, arg3, arg4);
    entry[0] = arg1;
    entry[1] = arg2;
    entry[2] = arg3;
    entry[3] = arg4;
}

/* --- dol/fn_80072D64.c --- */
extern void fn_80037128(s32, s32, s32, s32, u8, s32);

void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    u8 *entry;

    entry = (u8 *)lbl_801A6D38 + arg0 * 0x14 + 0x2F0;
    if (*(s32 *)(entry + 0x10) == arg5 &&
        *(s32 *)(entry + 0x8) == arg3 &&
        *(u8 *)(entry + 0xc) == arg4 &&
        *(s32 *)(entry + 0x0) == arg1 &&
        *(s32 *)(entry + 0x4) == arg2) {
        return;
    }

    fn_80037128(arg0, arg1, arg2, arg3, arg4, arg5);
    *(s32 *)(entry + 0x0) = arg1;
    *(s32 *)(entry + 0x4) = arg2;
    *(s32 *)(entry + 0x8) = arg3;
    *(u8 *)(entry + 0xc) = arg4;
    *(s32 *)(entry + 0x10) = arg5;
}

/* --- dol/fn_80072E20.c --- */
extern void fn_80037190(s32, s32, s32, s32, u8, s32);

void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    u8 *entry;

    entry = (u8 *)lbl_801A6D38 + arg0 * 0x14 + 0x430;
    if (*(s32 *)(entry + 0x10) == arg5 &&
        *(s32 *)(entry + 0x8) == arg3 &&
        *(u8 *)(entry + 0xc) == arg4 &&
        *(s32 *)(entry + 0x0) == arg1 &&
        *(s32 *)(entry + 0x4) == arg2) {
        return;
    }

    fn_80037190(arg0, arg1, arg2, arg3, arg4, arg5);
    *(s32 *)(entry + 0x0) = arg1;
    *(s32 *)(entry + 0x4) = arg2;
    *(s32 *)(entry + 0x8) = arg3;
    *(u8 *)(entry + 0xc) = arg4;
    *(s32 *)(entry + 0x10) = arg5;
}

/* --- dol/fn_80072EDC.c --- */
extern void fn_800370A0(s32,s32,s32,s32,s32);
extern void fn_800370E4(s32,s32,s32,s32,s32);
extern void fn_80037128(s32,s32,s32,s32,u8,s32);
extern void fn_80037190(s32,s32,s32,s32,u8,s32);

static void set_table_a(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 *entry;
    entry = (u32 *)(lbl_801A6D38 + (arg0 << 4) + 0xf0);
    if ((s32)entry[0] == arg1 &&
        (s32)entry[1] == arg2 &&
        (s32)entry[2] == arg3 &&
        (s32)entry[3] == arg4) {
        return;
    }
    fn_800370A0(arg0, arg1, arg2, arg3, arg4);
    entry[0] = arg1;
    entry[1] = arg2;
    entry[2] = arg3;
    entry[3] = arg4;
}

static void set_table_b(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 *entry;
    entry = (u32 *)(lbl_801A6D38 + (arg0 << 4) + 0x1f0);
    if ((s32)entry[0] == arg1 &&
        (s32)entry[1] == arg2 &&
        (s32)entry[2] == arg3 &&
        (s32)entry[3] == arg4) {
        return;
    }
    fn_800370E4(arg0, arg1, arg2, arg3, arg4);
    entry[0] = arg1;
    entry[1] = arg2;
    entry[2] = arg3;
    entry[3] = arg4;
}

static void set_table_c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    u8 *entry;
    entry = (u8 *)lbl_801A6D38 + arg0 * 0x14 + 0x2f0;
    if (*(s32 *)(entry + 0x10) == arg5 &&
        *(s32 *)(entry + 0x8) == arg3 &&
        *(u8 *)(entry + 0xc) == arg4 &&
        *(s32 *)(entry + 0x0) == arg1 &&
        *(s32 *)(entry + 0x4) == arg2) {
        return;
    }
    fn_80037128(arg0, arg1, arg2, arg3, arg4, arg5);
    *(s32 *)(entry + 0x0) = arg1;
    *(s32 *)(entry + 0x4) = arg2;
    *(s32 *)(entry + 0x8) = arg3;
    *(u8 *)(entry + 0xc) = arg4;
    *(s32 *)(entry + 0x10) = arg5;
}

static void set_table_d(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    u8 *entry;
    entry = (u8 *)lbl_801A6D38 + arg0 * 0x14 + 0x430;
    if (*(s32 *)(entry + 0x10) == arg5 &&
        *(s32 *)(entry + 0x8) == arg3 &&
        *(u8 *)(entry + 0xc) == arg4 &&
        *(s32 *)(entry + 0x0) == arg1 &&
        *(s32 *)(entry + 0x4) == arg2) {
        return;
    }
    fn_80037190(arg0, arg1, arg2, arg3, arg4, arg5);
    *(s32 *)(entry + 0x0) = arg1;
    *(s32 *)(entry + 0x4) = arg2;
    *(s32 *)(entry + 0x8) = arg3;
    *(u8 *)(entry + 0xc) = arg4;
    *(s32 *)(entry + 0x10) = arg5;
}

void fn_80072EDC(s32 arg0, s32 arg1) {
    s32 v0;
    s32 v1;
    if (arg0 == 0) { v0=10; v1=5; } else { v0=0; v1=0; }
    switch (arg1) {
case 1:
set_table_a(arg0, v0, 8, 9, 15);
set_table_b(arg0, 7, 7, 7, v1);
break;
case 0:
set_table_a(arg0, 15, 8, v0, 15);
set_table_b(arg0, 7, 4, v1, 7);
break;
case 3:
set_table_a(arg0, 15, 15, 15, 8);
set_table_b(arg0, 7, 7, 7, 4);
break;
case 4:
set_table_a(arg0, 15, 15, 15, v0);
set_table_b(arg0, 7, 7, 7, v1);
break;
case 2:
set_table_a(arg0, v0, 15, 8, 8);
set_table_b(arg0, 7, 4, v1, 7);
break;
}
set_table_c(arg0, 0, 0, 0, 1, 0);
set_table_d(arg0, 0, 0, 0, 1, 0);
}

/* --- dol/fn_800734A8.c --- */
extern void GXSetTevOrder(s32, s32, s32, s32);

void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p;
    u8 *q;

    p = (u8 *)lbl_801A6D38 + (arg0 << 4) + 0x570;
    if (arg2 >= 8) {
        if (*(s32 *)(p + 0) != arg1 || *(s32 *)(p + 4) != 0xff ||
            *(s32 *)(p + 8) != arg3) {
            GXSetTevOrder(arg0, arg1, arg2, arg3);
            *(s32 *)(p + 0) = arg1;
            *(s32 *)(p + 4) = 0xff;
            *(s32 *)(p + 8) = arg3;
            *(u16 *)(p + 0xc) = 0;
            *(u16 *)(p + 0xe) = 0;
        }
    } else {
        q = (u8 *)lbl_801A6D38 + arg2 * 36 + 0x720;
        if (*(s32 *)(p + 0) != arg1 || *(s32 *)(p + 4) != arg2 ||
            *(s32 *)(p + 8) != arg3 ||
            *(u16 *)(p + 0xc) != *(u16 *)(q + 0x20) ||
            *(u16 *)(p + 0xe) != *(u16 *)(q + 0x22)) {
            GXSetTevOrder(arg0, arg1, arg2, arg3);
            *(s32 *)(p + 0) = arg1;
            *(s32 *)(p + 4) = arg2;
            *(s32 *)(p + 8) = arg3;
            *(u16 *)(p + 0xc) = *(u16 *)(q + 0x20);
            *(u16 *)(p + 0xe) = *(u16 *)(q + 0x22);
        }
    }
}
