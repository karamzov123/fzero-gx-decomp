#include "types.h"


/* --- dol/fn_800079C4.c --- */
/* --- dol/fn_800079C4.c --- */
extern u32 fn_80007654(u32);

u32 fn_800079C4(u32 arg0) {
    u32 t0;
    t0 = fn_80007654(arg0);
    return ((((arg0 >> 12) & 0xFFFF) ^ (t0 & 0x7FFFF)) << 6);
}

/* --- dol/fn_80007A00.c --- */

u32 fn_80007A00(u32 value) {
    s32 result;

    result = fn_80007654(value);
    result = ((((value >> 12) & 0xffff) ^ (result & 0x7ffff)) << 6);
    return (result ^ 0x01ff0000) ^ 0xffc0;
}

/* --- dol/fn_80007A44.c --- */
extern u32 fn_800744F8(void *, u32);
extern u32 fn_80008204(void *);
extern u32 lbl_801A6408;
extern u32 lbl_801A6F00;
extern u32 lbl_801A6728;

void fn_80007A44(void) {
    u32 loc_8[2];

    loc_8[1] = lbl_801A6F00;
    ((u8 *)&lbl_801A6408)[0] = ((u8 *)&loc_8[1])[0];
    ((u8 *)&lbl_801A6408)[1] = ((u8 *)&loc_8[1])[1];
    ((u8 *)&lbl_801A6408)[2] = ((u8 *)&loc_8[1])[2];
    ((u8 *)&lbl_801A6408)[3] = ((u8 *)&loc_8[1])[3];
    loc_8[0] = lbl_801A6408;
    fn_800744F8(loc_8, 0x00ffffff);
    fn_80008204(&lbl_801A6408);
    lbl_801A6728 = 0;
}

/* --- dol/fn_80007AB4.c --- */
static inline int byte_equal(u8 *p) {
    u32 a;
    u32 b;
    /* Volatile byte reads preserve the retail input-before-cache load order. */
    b = *(volatile u8 *)p;
    a = ((volatile u8 *)&lbl_801A6408)[0]; /* volatile preserves the second ordered byte read. */
    return a == b;
}

void fn_80007AB4(u8 *arg0) {
    u32 loc_8[2];
    u8 b0;

    if (byte_equal(arg0)) {
        /* Goto shares the final flag store with the unchanged-value path. */
        if (((u8 *)&lbl_801A6408)[1] == arg0[1] &&
            ((u8 *)&lbl_801A6408)[2] == arg0[2] &&
            ((u8 *)&lbl_801A6408)[3] == arg0[3]) goto done; /* goto shares the final flag store. */
    }
    {
        loc_8[1] = *(u32 *)arg0;
        ((u8 *)&lbl_801A6408)[0] = ((u8 *)&loc_8[1])[0];
        ((u8 *)&lbl_801A6408)[1] = ((u8 *)&loc_8[1])[1];
        ((u8 *)&lbl_801A6408)[2] = ((u8 *)&loc_8[1])[2];
        ((u8 *)&lbl_801A6408)[3] = ((u8 *)&loc_8[1])[3];
        loc_8[0] = lbl_801A6408;
        fn_800744F8(loc_8, 0x1000000 - 1);
        fn_80008204(&lbl_801A6408);
    }
done:
    lbl_801A6728 = 1;
}

/* --- dol/fn_80007B68.c --- */
/* --- dol/fn_80007B68.c --- */

extern u32 lbl_801A6F04;

void fn_80007B68(void) {
    u32 loc_8[5];
    u8 *src;
    u8 *dst;

    loc_8[4] = lbl_801A6F04;
    loc_8[0] = lbl_801A6F04;
    loc_8[3] = lbl_801A6F04;
    if (((u8 *)&lbl_801A6408)[0] != ((u8 *)&loc_8[4])[0] ||
        ((u8 *)&lbl_801A6408)[1] != ((u8 *)&loc_8[4])[1] ||
        ((u8 *)&lbl_801A6408)[2] != ((u8 *)&loc_8[4])[2] ||
        ((u8 *)&lbl_801A6408)[3] != ((u8 *)&loc_8[4])[3]) {
        loc_8[2] = loc_8[3];
        ((u8 *)&lbl_801A6408)[0] = ((u8 *)&loc_8[2])[0];
        ((u8 *)&lbl_801A6408)[1] = ((u8 *)&loc_8[2])[1];
        ((u8 *)&lbl_801A6408)[2] = ((u8 *)&loc_8[2])[2];
        ((u8 *)&lbl_801A6408)[3] = ((u8 *)&loc_8[2])[3];
        loc_8[1] = lbl_801A6408;
        fn_800744F8(&loc_8[1], (0x1000000 - 1));
        fn_80008204(&lbl_801A6408);
    }
    lbl_801A6728 = 1;
}

/* --- dol/fn_80007C2C.c --- */

void fn_80007C2C(void) {
    u32 loc_8[2];
    /* frame */
    loc_8[0] = lbl_801A6408;
    fn_800744F8(loc_8, (0x1000000 - 1));
}
