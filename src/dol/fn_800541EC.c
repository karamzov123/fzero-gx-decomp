#include "types.h"


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
