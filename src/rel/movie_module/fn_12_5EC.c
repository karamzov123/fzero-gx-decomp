#include "types.h"


/* --- rel/movie_module/fn_12_5EC.c --- */
extern u32 lbl_12_rodata_34;
extern u32 strncmp(u32, u32, u32);

u32 fn_12_5EC(u32 arg0, u32 arg1) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0 || (s32)arg1 < 0) {
    v0 = 0;
    } else {
    v0 += 18;
    t0 = strncmp(v0, (u32)&lbl_12_rodata_34, 1);
    v0 = t0;
    v0 = ((u32)__cntlzw(v0) >> 5);
    }
    return v0;
}

/* --- rel/movie_module/fn_12_63C.c --- */
extern s32 lbl_12_bss_0;

void fn_12_63C(void) {
    if (lbl_12_bss_0 > 0) {
        lbl_12_bss_0--;
    }
}

/* --- rel/movie_module/fn_12_65C.c --- */
extern char lbl_12_rodata_0[49];
extern u32 lbl_12_bss_4;

void fn_12_65C(void) {
    if (lbl_12_bss_0 < 1) {
        lbl_12_bss_4 = (u32)&lbl_12_rodata_0;
        lbl_12_bss_0 = lbl_12_bss_0 + 1;
    }
}

/* --- rel/movie_module/fn_12_68C.c --- */
struct fn_12_68C_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
    u8 pad_10[0xC];
    u32 unk_1C;
    u8 pad_20[0xC];
    u32 unk_2C;
};

void fn_12_68C(struct fn_12_68C_Arg0 *arg0, u32 arg1) {
    s32 v0;
    u32 v1;
    s32 v2;
    v0 = ((s32)(((u32)arg1 >> 31) + arg1) >> 1);
    v1 = (v0 << 1);
    arg0->unk_C = v1;
    v2 = ((s32)(((v0 >> 30) & 0x1) + v1) >> 1);
    arg0->unk_1C = v2;
    arg0->unk_2C = v2;
}

/* --- rel/movie_module/fn_12_6B8.c --- */
struct fn_12_6B8_Arg0 {
    u8 pad_0[4];
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    u8 pad_10[4];
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    u8 pad_20[4];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
};

void fn_12_6B8(struct fn_12_6B8_Arg0 *arg0, u32 arg1) {
    s32 v0;
    s32 v2;
    s32 t8;
    s32 t4;
    s32 tc;
    s32 t18;
    s32 t1c;
    s32 t14;
    s32 t28;
    s32 t2c;
    s32 t24;
    t8 = arg0->unk_8;
    t4 = arg0->unk_4;
    tc = arg0->unk_C;
    v0 = ((s32)(((u32)arg1 >> 31) + arg1) >> 1);
{
    s32 v1;
    v1 = (v0 << 1);
    arg0->unk_4 = t4 + v1 * t8;
    arg0->unk_C = tc - v1;
    v2 = ((s32)(((v0 >> 30) & 0x1) + v1) >> 1);
}
    t18 = arg0->unk_18;
    t1c = arg0->unk_1C;
    t14 = arg0->unk_14;
    arg0->unk_14 = t14 + v2 * t18;
    arg0->unk_1C = t1c - v2;
    t28 = arg0->unk_28;
    t2c = arg0->unk_2C;
    t24 = arg0->unk_24;
    arg0->unk_24 = t24 + v2 * t28;
    arg0->unk_2C = t2c - v2;
}

/* --- rel/movie_module/fn_12_738.c --- */
struct MovieData {
    u8 pad[0x64];
    int value;
};

int fn_12_738(struct MovieData *movie) {
    return movie->value;
}

/* --- rel/movie_module/fn_12_740.c --- */
typedef struct MovieModule {
    u8 pad[0x60];
    int value;
} MovieModule;

int fn_12_740(MovieModule *self) {
    return self->value;
}
