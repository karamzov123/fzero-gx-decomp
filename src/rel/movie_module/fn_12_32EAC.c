#include "types.h"


/* --- rel/movie_module/fn_12_32EAC.c --- */
struct fn_12_32EAC_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};
struct fn_12_32EAC_Arg1 {
    u32 unk_0;
};

extern s32 memcmp(u32, u32, u32);
extern char lbl_12_rodata_10DC[5];
extern char lbl_12_rodata_10E4[25];
extern u8 *strstr(u8 *, const u8 *);
extern void *memcpy(void *, const void *, u32);
extern void *memset(void *, int, u32);

static inline s32 digit(s32 c) {
    s32 result = 0;
    if (c >= 48 && c <= 57) result = 1;
    return result;
}
static inline u32 number(s8 **p) {
    s8 *v6 = *p;
    s32 c;
    u32 v0 = 0;
    for (;;) {
        c = *v6;
        if (c == 46 || c == 32 || c == 0) break;
        if (!digit(c)) break;
        v0 = c + v0 * 10;
        v0 -= 48;
        ++v6;
    }
    *p = v6;
    return v0;
}
static inline s32 parse(u8 *buf, u32 *major, u32 *minor) {
    s8 *v4 = (s8 *)strstr(buf, (const u8 *)lbl_12_rodata_10DC);
    if (!v4) return 0;
    v4 += 4;
    *major = number(&v4);
    ++v4;
    *minor = number(&v4);
    return 1;
}
static inline s32 copy(struct fn_12_32EAC_Arg0 *arg0, void *buf) {
    u32 v1 = arg0->unk_4 + 96;
    s32 ok;
    switch ((s32)arg0->unk_0) {
    case -1: case 0: case 1: ok = 0; break;
    default: ok = 1; break;
    }
    if (!ok) return 0;
    memset(buf, 0, 33);
    memcpy(buf, (void *)v1, 32);
    return 1;
}
static inline s32 version(struct fn_12_32EAC_Arg0 *arg0, u32 *major, u32 *minor) {
    struct { u8 a[33]; } loc_8;
    if (!copy(arg0, &loc_8)) return 0;
    if (!parse((u8 *)&loc_8, major, minor)) return 0;
    return 1;
}
s32 fn_12_32EAC(struct fn_12_32EAC_Arg0 *arg0, struct fn_12_32EAC_Arg1 *arg1) {
    u32 v0;
    u32 v2;
    u32 v3;
    arg1->unk_0 = 0;
    v0 = arg0->unk_4 + 32;
    if ((s32)((u32)__cntlzw(arg0->unk_0) >> 5) == 1) return 0;
    if (arg0->unk_8 < 2048) {
        arg0->unk_0 = -1;
        return 0;
    }
    if (memcmp(v0, (u32)lbl_12_rodata_10E4, 24) != 0) {
        arg0->unk_0 = -1;
        return 0;
    }
    arg0->unk_0 = 2;
    if (!version(arg0, &v2, &v3)) return 0;
    arg0->unk_C = v3 + v2 * 100;
    arg1->unk_0 = 1;
    return 1;
}

/* --- rel/movie_module/fn_12_330E0.c --- */
extern struct fn_12_330E0_lbl_12_bss_1B75C lbl_12_bss_1B75C;

struct fn_12_330E0_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};
struct fn_12_330E0_lbl_12_bss_1B75C {
    u8 pad_0[0x4];
    u32 unk_4;
};

u32 fn_12_330E0(struct fn_12_330E0_Arg0 *arg0) {
    u32 v0;
    arg0->unk_0 = 0;
    arg0->unk_4 = 0;
    arg0->unk_8 = 0;
    arg0->unk_C = 0;
    v0 = lbl_12_bss_1B75C.unk_4;
    lbl_12_bss_1B75C.unk_4 = (v0 - 1);
    return v0;
}
