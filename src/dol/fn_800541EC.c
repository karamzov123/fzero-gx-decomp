#include "types.h"


/* --- dol/fn_800541EC.c --- */
/* --- dol/fn_800541EC.c --- */
/* --- dol/fn_800541EC.c --- */
extern u32 fn_80051678(u32);

struct fn_800541EC_Arg0 {
    u32 unk_0;
};

void fn_800541EC(struct fn_800541EC_Arg0 *arg0) {
    fn_80051678(arg0->unk_0);
    *(u8 *)((u8 *)(u32)arg0 + 5) = 0;
}

/* --- dol/fn_80054224.c --- */
extern u32 fn_800504BC(u32);
extern u32 fn_800504EC(u32);
extern u32 fn_80051594(u32, u32);

struct fn_80054224_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
};

void fn_80054224(struct fn_80054224_Arg0 *arg0) {
    u32 v0;
    u32 t1;
    arg0->unk_18 = 0;
    *(u32 *)((u8 *)(u32)arg0 + 28) = 0;
    *(u32 *)((u8 *)(u32)arg0 + 32) = 0;
    *(u32 *)((u8 *)(u32)arg0 + 36) = 0;
    *(u32 *)((u8 *)(u32)arg0 + 40) = (0x80000000 - 1);
    *(u32 *)((u8 *)(u32)arg0 + 44) = -1;
    *(u32 *)((u8 *)(u32)arg0 + 48) = 0;
    *(u32 *)((u8 *)(u32)arg0 + 52) = 0;
    *(u8 *)((u8 *)(u32)arg0 + 7) = 0;
    v0 = *(u32 *)((u8 *)(u32)arg0 + 8);
    if (v0 != 0) {
    *(u32 *)((u8 *)(u32)arg0 + 8) = 0;
    fn_800504BC(v0);
    }
    t1 = fn_800504EC(*(u32 *)((u8 *)(u32)arg0 + 12));
    *(u32 *)((u8 *)(u32)arg0 + 8) = t1;
    fn_80051594(*(u32 *)((u8 *)(u32)arg0 + 0), *(u32 *)((u8 *)(u32)arg0 + 8));
    *(u8 *)((u8 *)(u32)arg0 + 5) = 1;
}

/* --- dol/fn_800542B4.c --- */
/* --- dol/fn_800542B4.c --- */
struct fn_800542B4_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

void fn_800542B4(struct fn_800542B4_Arg0 *arg0, u32 arg1) {
    arg0->unk_C = arg1;
}

/* --- dol/fn_800542BC.c --- */
typedef struct {
    u8 pad[5];
    s8 value;
} Fn800542BC;

int fn_800542BC(Fn800542BC *obj) {
    return obj->value;
}

/* --- dol/fn_800542C8.c --- */
typedef struct {
    u32 unk_0;
    u8 pad_4[4];
    u32 unk_8;
    u8 pad_C[0x2C];
    u32 unk_38;
    u8 pad_3C[0x10];
} Fn800542C8;

extern void fn_8005174C(u32);
extern u32 memset(u32, u32, u32);
extern u32 lbl_801873EC[];

void fn_800542C8(Fn800542C8 *obj) {
    u32 index;
    u32 value;

    if (obj != 0) {
        value = obj->unk_8;
        index = obj->unk_38;
        if (value != 0) {
            obj->unk_8 = 0;
            fn_800504BC(value);
        }
        value = obj->unk_0;
        if (value != 0) {
            obj->unk_0 = 0;
            fn_8005174C(value);
        }
        memset((u32)obj, 0, 0x4C);
        lbl_801873EC[index] = 0;
    }
}

/* --- dol/fn_80054354.c --- */
struct fn_80054354_object {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 count;
    u8 unk_7;
    u32 unk_8;
    u32 unk_c;
    u32 data[10];
    u32 unk_38;
    u32 unk_3c;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4c;
};

extern u32 fn_800517C0(u32, u32);

u32 fn_80054354(u32 arg0, s32 arg1, u32 *arg2, u32 *arg3, u32 arg4) {
    s32 index;
    struct fn_80054354_object *obj;
    s32 i;

    for (index = 0; index < 16; index++) {
        if (lbl_801873EC[index] == 0) {
            break;
        }
    }
    if (index == 16) {
        return 0;
    }

    memset((u32)arg3, 0, arg4);
    {
        u32 *table;
        table = lbl_801873EC;
        table[index] = (u32)arg3;
        obj = (struct fn_80054354_object *)table[index];
    }
    obj->unk_38 = index;
    obj->unk_8 = fn_800504EC(arg0);
    if (obj->unk_8 == 0) {
        return 0;
    }
    obj->unk_0 = fn_800517C0((u32)&obj->unk_4c, 0x2bcc);
    if (obj->unk_0 == 0) {
        return 0;
    }

    obj->count = (u8)arg1;
    obj->unk_c = arg0;
    for (i = 0; i < arg1; i++) {
        obj->data[i] = arg2[i];
    }
    obj->unk_5 = 0;
    obj->data[2] = 0;
    obj->data[3] = 0;
    obj->data[4] = 0;
    obj->data[5] = 0;
    obj->data[6] = 0x7fffffff;
    obj->data[7] = 0xffffffff;
    obj->data[8] = 0;
    obj->data[9] = 0;
    obj->unk_7 = 0;
    obj->unk_3c = 0;
    obj->unk_40 = 0;
    obj->unk_44 = 0;
    obj->unk_48 = 0;
    obj->unk_4 = 1;
    return (u32)obj;
}

/* --- dol/fn_800545B0.c --- */
struct fn_800545B0_lbl_801873D8 {
    u32 unk_0;
};

extern struct fn_800545B0_lbl_801873D8 lbl_801873D8[];
extern u32 fn_8005190C(void);

u32 fn_800545B0(void) {
    u32 v0;
    u32 v1;
    u32 t0, t1;
    if ((s32)lbl_801873D8[0].unk_0 == 1) {
    v1 = 0;
    v0 = (u32)&lbl_801873EC;
    t0 = memset((u32)v0, v1, 64);
    v0 = t0;
    t1 = fn_8005190C();
    v0 = t1;
    }
    v1 = (u32)&lbl_801873D8;
    v0 = *(u32 *)((u8 *)v1 + 0);
    *(u32 *)((u8 *)v1 + 0) = (v0 - 1);
    return v0;
}
