#include "types.h"


/* --- dol/fn_8004541C.c --- */
extern u32 fn_8004E2CC(u32, u32, u32, u32);
extern u32 fn_8004E300(u32, u32, u32);

struct fn_8004541C_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

void fn_8004541C(struct fn_8004541C_Arg0 *arg0) {
    fn_8004E300(arg0->unk_8, ((u32)arg0 + 168), ((u32)arg0 + 172));
    fn_8004E2CC(*(u32 *)((u8 *)(u32)arg0 + 8), *(s16 *)((u8 *)(u32)arg0 + 162), *(s16 *)((u8 *)(u32)arg0 + 164), *(s16 *)((u8 *)(u32)arg0 + 166));
}

/* --- dol/fn_80045468.c --- */
extern u32 fn_8004E2B0(u32, u32, u32, u32);
extern u32 fn_8004E2DC(u32, u32, u32);

struct fn_80045468_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

void fn_80045468(struct fn_80045468_Arg0 *arg0) {
    fn_8004E2DC(arg0->unk_8, ((u32)arg0 + 168), ((u32)arg0 + 172));
    fn_8004E2B0(*(u32 *)((u8 *)(u32)arg0 + 8), ((u32)arg0 + 162), ((u32)arg0 + 164), ((u32)arg0 + 166));
}
