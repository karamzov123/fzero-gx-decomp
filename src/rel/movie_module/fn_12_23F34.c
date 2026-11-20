#include "types.h"


/* --- rel/movie_module/fn_12_23F34.c --- */
typedef struct MovieModule {
    u8 pad_00[0x78];
    s32 unk_78;
    u32 unk_7c;
    u8 *unk_80;
} MovieModule;

u8 *fn_12_23F34(MovieModule *self) {
    if (self->unk_78 != 0) {
        return self->unk_80 + self->unk_7c * 0x64;
    }
    return 0;
}

/* --- rel/movie_module/fn_12_23F5C.c --- */
typedef struct MovieSlotInfo {
s32 unk_00; s32 unk_04; s32 unk_08; s32 unk_0c;
s32 unk_10; s32 unk_14; s32 unk_18; s32 unk_1c;
s32 unk_20; s32 unk_24; s32 unk_28; s32 unk_2c;
s32 unk_30; s32 unk_34; s32 unk_38; s32 unk_3c;
s32 unk_40; s32 unk_44; s32 unk_48; s32 unk_4c;
s32 unk_50; s32 unk_54; s32 unk_58; s32 unk_5c;
s32 unk_60; s32 unk_64; s32 unk_68; s32 unk_6c;
s32 unk_70; s32 unk_74; s32 unk_78; s32 unk_7c;
s32 unk_80; s32 unk_84; s32 unk_88; s32 unk_8c;
} MovieSlotInfo;
extern int fn_12_32EAC(void *, s32 *);
extern int fn_12_328CC(void *, s32 *, s32 *);
extern int fn_12_323B0(void *, s32 *);
extern int fn_12_32834(void *, s32 *);
extern int fn_12_327AC(void *, s32 *);
extern int fn_12_32714(void *, s32 *);
extern int fn_12_3267C(void *, s32 *);
extern int fn_12_325F4(void *, s32 *);
extern int fn_12_3256C(void *, s32 *);
extern int fn_12_324E4(void *, s32 *);
extern int fn_12_3245C(void *, s32 *);
extern int fn_12_32318(void *, s32 *);
extern int fn_12_32280(void *, s32 *);
extern int fn_12_321E8(void *, s32 *);
extern int fn_12_32DBC(void *, u8, s32 *);
extern int fn_12_320A0(void *, u8, s32 *);
extern int fn_12_31F44(void *, u8, s32 *);
extern int fn_12_31DFC(void *, u8, s32 *);
extern int fn_12_31CA4(void *, u8, s32 *);
extern int fn_12_31B5C(void *, u8, s32 *);
extern int fn_12_319EC(void *, u8, s32 *);
extern int fn_12_31860(void *, u8, s32 *, s32 *);
extern int fn_12_316A8(void *, u8, s32 *);
extern int fn_12_32A70(void *, u8, s32 *);
extern int fn_12_31528(void *, u8, s32 *);
extern int fn_12_313A8(void *, u8, s32 *);
extern int fn_12_31224(void *, u8, s32 *);
extern int fn_12_310A0(void *, u8, s32 *);
extern int fn_12_30F20(void *, u8, s32 *);
extern int fn_12_30D8C(void *, u8, s32 *);
extern int fn_12_30BF8(void *, u8, s32 *);
static inline s32 scan(void *movie, s32 first, s32 last, s32 *value) {
    s32 index;
    for (index = first; index <= last; index++) {
        if (fn_12_32DBC(movie, index, value) != 0 && *value != 0) {
            return index;
        }
    }
    return 0;
}
void fn_12_23F5C(void *arg0, MovieSlotInfo *arg1) {
    MovieSlotInfo *out = arg1;
    void *movie = arg0;
    s32 index;
    s32 value;
    s32 sp8c; s32 sp88; s32 sp84; s32 sp80;
    s32 sp7c; s32 sp78; s32 sp74; s32 sp70; s32 sp6c;
    s32 sp68; s32 sp64; s32 sp60; s32 sp5c; s32 sp58;
    s32 sp54; s32 sp50; s32 sp4c; s32 sp48; s32 sp44;
    s32 sp40; s32 sp3c; s32 sp38; s32 sp34; s32 sp30;
    s32 sp2c; s32 sp28; s32 sp24; s32 sp20; s32 sp1c;
    s32 sp18; s32 sp14; s32 sp10; s32 sp0c; s32 sp08;
    if (fn_12_32EAC(movie, &sp8c) == 0) sp8c = 0;
    if (sp8c == 0) return;
    if (fn_12_328CC(movie, &sp84, &sp80) == 0) {
        sp84 = 0; sp80 = 0;
    }
    out->unk_04 = sp84;
    out->unk_08 = sp80;
    index = out->unk_08 + out->unk_04 * 0x64;
    if (fn_12_323B0(movie, &sp88) == 0) sp88 = 0;
    if (index < 0x6e) sp88 = -sp88;
    out->unk_0c = sp88;
    if (fn_12_32834(movie, &sp68) == 0) value = -1; else value = sp68;
    out->unk_10 = value;
    if (fn_12_327AC(movie, &sp64) == 0) value = -1; else value = sp64;
    out->unk_14 = value;
    if (fn_12_32714(movie, &sp60) == 0) value = -1; else value = sp60;
    out->unk_18 = value;
    if (out->unk_18 == -1) out->unk_18 = 2;
    if (fn_12_3267C(movie, &sp5c) == 0) value = -1; else value = sp5c;
    out->unk_1c = value;
    if (fn_12_325F4(movie, &sp58) == 0) value = -1; else value = sp58;
    out->unk_20 = value;
    if (fn_12_3256C(movie, &sp54) == 0) value = -1; else value = sp54;
    out->unk_24 = value;
    if (fn_12_324E4(movie, &sp50) == 0) value = -1; else value = sp50;
    out->unk_28 = value;
    if (fn_12_3245C(movie, &sp4c) == 0) value = -1; else value = sp4c;
    out->unk_2c = value;
    if (fn_12_32318(movie, &sp48) == 0) value = -1; else value = sp48;
    out->unk_30 = value;
    if (fn_12_32280(movie, &sp44) == 0) value = -1; else value = sp44;
    out->unk_34 = value;
    if (fn_12_321E8(movie, &sp40) == 0) value = -1; else value = sp40;
    out->unk_38 = value;
    if (fn_12_32DBC(movie, 0xbd, &sp7c) != 0 && sp7c != 0) value = 0xbd; else value = 0;
    out->unk_3c = value;
    if (fn_12_32DBC(movie, 0xbf, &sp78) != 0 && sp78 != 0) value = 0xbf; else value = 0;
    out->unk_40 = value;
    out->unk_44 = scan(movie, 0xc0, 0xdf, &sp74);
    out->unk_48 = scan(movie, 0xe0, 0xef, &sp70);
    index = out->unk_44;
    if (index != 0) {
        if (fn_12_320A0(movie, index, &sp3c) == 0) value = -1; else value = sp3c;
        out->unk_4c = value;
        if (fn_12_31F44(movie, index, &sp38) == 0) value = -1; else value = sp38;
        out->unk_50 = value;
        if (fn_12_31DFC(movie, index, &sp34) == 0) value = -1; else value = sp34;
        out->unk_54 = value;
        if (fn_12_31CA4(movie, index, &sp30) == 0) value = -1; else value = sp30;
        out->unk_58 = value;
    }
    index = out->unk_48;
    if (fn_12_31B5C(movie, index, &sp2c) == 0) value = -1; else value = sp2c;
    out->unk_5c = value;
    if (fn_12_319EC(movie, index, &sp28) == 0) value = -1; else value = sp28;
    out->unk_60 = value;
    if (fn_12_31860(movie, index, &out->unk_64, &out->unk_68) == 0) {
        out->unk_64 = -1; out->unk_68 = -1;
    }
    if (fn_12_316A8(movie, index, &sp24) == 0) value = -1; else value = sp24;
    out->unk_6c = value;
    if (fn_12_32A70(movie, index, &sp6c) == 0) sp6c = 0;
    out->unk_70 = (sp6c != 0);
    if (sp6c != 0) {
        if (fn_12_31528(movie, index, &sp20) == 0) value = -1; else value = sp20;
        out->unk_74 = value;
        if (fn_12_313A8(movie, index, &sp1c) == 0) value = -1; else value = sp1c;
        out->unk_78 = value;
        if (fn_12_31224(movie, index, &sp18) == 0) value = -1; else value = sp18;
        out->unk_7c = value;
        if (fn_12_310A0(movie, index, &sp14) == 0) value = -1; else value = sp14;
        out->unk_80 = value;
        if (fn_12_30F20(movie, index, &sp10) == 0) value = -1; else value = sp10;
        out->unk_84 = value;
        if (fn_12_30D8C(movie, index, &sp0c) == 0) value = -1; else value = sp0c;
        out->unk_88 = value;
        if (fn_12_30BF8(movie, index, &sp08) == 0) value = -1; else value = sp08;
        out->unk_8c = value;
    }
    out->unk_00 = 1;
}
