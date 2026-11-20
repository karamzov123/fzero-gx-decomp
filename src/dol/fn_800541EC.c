#include "types.h"


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
