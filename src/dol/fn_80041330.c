#include "types.h"


/* --- dol/fn_80041330.c --- */
/* --- dol/fn_80041330.c --- */
extern u32 fn_80047608(void);

s32 fn_80041330(void) {
    fn_80047608();
    return 0;
}

/* --- dol/fn_80041354.c --- */
extern u32 fn_8004BDD8(void);

s32 fn_80041354(void) {
    fn_8004BDD8();
    return 0;
}

/* --- dol/fn_80041378.c --- */
extern u32 fn_80056C64(void);

s32 fn_80041378(void) {
    fn_8004BDD8();
    fn_80047608();
    fn_80056C64();
    return 0;
}

/* --- dol/fn_800413A4.c --- */
s32 fn_800413A4(void) {
    fn_80056C64();
    return 0;
}

/* --- dol/fn_800413C8.c --- */
extern u32 fn_800474E4(u32, u32);

void fn_800413C8(u32 arg0, u32 arg1) {
    fn_800474E4(arg1, arg1);
}

/* --- dol/fn_800413EC.c --- */
void fn_800413EC(u32 arg0, u32 arg1) {
    fn_800474E4(arg1, arg1);
}

/* --- dol/fn_80041410.c --- */
extern u32 fn_8004541C(u32);

struct fn_80041410_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_80041410(struct fn_80041410_Arg0 *arg0) {
    fn_8004541C(arg0->unk_4);
}

/* --- dol/fn_80041434.c --- */
extern u32 fn_80045468(u32);

struct fn_80041434_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_80041434(struct fn_80041434_Arg0 *arg0) {
    fn_80045468(arg0->unk_4);
}

/* --- dol/fn_80041458.c --- */
void *fn_80041458(void *ptr) {
    return (u8 *)ptr + 0x58;
}

/* --- dol/fn_80041460.c --- */
struct fn_80041460_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

extern u32 fn_800454B4(u32, u32);
extern u32 fn_800454CC(u32, u32);

s32 fn_80041460(struct fn_80041460_Arg0 *arg0, u32 arg1) {
    u32 v0;
    u32 t0, t1;
    t0 = fn_800454CC(arg0->unk_4, arg1);
    v0 = t0;
    if ((s32)t0 > 0 && ((s8)*((u8 *)arg0 + 1) == 2 || (s8)*((u8 *)arg0 + 1) == 3)) {
    v0 = *(u32 *)((u8 *)arg0 + 4);
    t1 = fn_800454B4(v0, arg1);
    v0 = t1;
    } else {
    v0 = -128;
    }
    return v0;
}
