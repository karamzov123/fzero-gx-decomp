#include "types.h"

typedef struct MovieBuffer {
    u8 data[0x894];
} MovieBuffer;

typedef struct MovieData {
    u8 pad_00[0x0c];
    MovieBuffer buffer;
} MovieData;

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

typedef struct fn_12_245C4_MovieModule {
    u8 pad_00[0x78];
    MovieBuffer buffer;
    u8 pad_90c[0x2908 - 0x90c];
    MovieData *movie;
} fn_12_245C4_MovieModule;

typedef struct fn_12_24670_MovieModule {
    u8 pad_00[0x78];
    MovieBuffer buffer;
    u8 pad_90c[0x2908 - 0x90c];
    MovieData *movie;
} fn_12_24670_MovieModule;

typedef struct fn_12_24570_MovieModule {
    u32 unk_00;
    u8 pad_04[8];
    u32 unk_0c;
    u8 pad_10[0x80];
    u32 unk_90;
    u8 unk_94[1];
} fn_12_24570_MovieModule;
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
extern void * fn_12_3310C();
extern void fn_12_23F5C(void *arg0, MovieSlotInfo *arg1);
extern void fn_12_330E0(void *);
extern int fn_12_24E94(fn_12_245C4_MovieModule *self);
extern void fn_12_24570(fn_12_24570_MovieModule *self);
extern void *fn_12_57F0(void *dst, const void *src, u32 size);
extern int fn_12_24670(fn_12_24670_MovieModule *self, void *arg, int size);
extern void fn_12_33178();
extern u8 lbl_12_bss_7A50[520];
extern void fn_12_331A8(s32, u8 *);

/* fzgx:begin fn_12_23F00 */
typedef struct MovieSub {
    u8 pad_00[0x14];
    s32 unk_14;
    void *unk_18;
} MovieSub;

typedef struct fn_12_23F00_MovieModule {
    u8 pad_00[0x78];
    s32 unk_78;
    u8 pad_7c[0x58];
    u8 unk_d4[1];
} fn_12_23F00_MovieModule;

void *fn_12_23F00(fn_12_23F00_MovieModule *self) {
    void *base = (u8 *)self + 0xd4;

    if (self->unk_78 == 0) {
        return (void *)-1;
    }
    if (((MovieSub *)base)->unk_14 != 0) {
        return ((MovieSub *)base)->unk_18;
    }
    return (void *)-1;
}
/* fzgx:end fn_12_23F00 */

/* fzgx:begin fn_12_23F34 */
/* --- rel/movie_module/fn_12_23F34.c --- */
typedef struct fn_12_23F34_MovieModule {
    u8 pad_00[0x78];
    s32 unk_78;
    u32 unk_7c;
    u8 *unk_80;
} fn_12_23F34_MovieModule;

u8 *fn_12_23F34(fn_12_23F34_MovieModule *self) {
    if (self->unk_78 != 0) {
        return self->unk_80 + self->unk_7c * 0x64;
    }
    return 0;
}
/* fzgx:end fn_12_23F34 */

/* fzgx:begin fn_12_23F5C */
/* --- rel/movie_module/fn_12_23F5C.c --- */
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
/* fzgx:end fn_12_23F5C */

/* fzgx:begin fn_12_24570 */


void fn_12_24570(fn_12_24570_MovieModule *self) {
    void *movie;

    movie = fn_12_3310C(self->unk_94, self->unk_90);
    if (movie != 0) {
        fn_12_23F5C(movie, (MovieSlotInfo *)(fn_12_24570_MovieModule *)(self));
        fn_12_330E0(movie);
    }
}
/* fzgx:end fn_12_24570 */

/* fzgx:begin fn_12_245C4 */
/* --- rel/movie_module/fn_12_245C4.c --- */




void fn_12_245C4(fn_12_245C4_MovieModule *self) {
    MovieBuffer *copy;

    if (self->movie == 0) {
        copy = 0;
    } else if (fn_12_24E94(self) > 0) {
        copy = 0;
    } else {
        copy = &self->movie->buffer;
    }

    if (copy != 0) {
        self->buffer = *copy;
        fn_12_24570( (fn_12_24570_MovieModule *)(void *)(self->buffer.data));
        *(u32 *)((u8 *)self + 0x930) = *(u32 *)((u8 *)self + 0x9c);
        *(u32 *)((u8 *)self + 0x934) = *(u32 *)((u8 *)self + 0xa0);
        *(u32 *)((u8 *)self + 0x938) = *(u32 *)((u8 *)self + 0xa4);
    }
}
/* fzgx:end fn_12_245C4 */

/* fzgx:begin fn_12_24670 */
/* --- rel/movie_module/fn_12_245C4.c --- */




/* --- rel/movie_module/fn_12_24670.c --- */

int fn_12_24670(fn_12_24670_MovieModule *self, void *arg, int size) {
    int copy_size;
    MovieBuffer *copy;

    if (*(s32 *)self->buffer.data != 0) {
        return 0;
    }

    copy_size = 0x800;
    if (size < 0x800) {
        copy_size = size;
    }
    fn_12_57F0((u8 *)self + 0x10c, arg, copy_size);
    *(u32 *)((u8 *)self + 0x108) = copy_size;
    fn_12_24570( (fn_12_24570_MovieModule *)(void *)(self->buffer.data));
    *(u32 *)((u8 *)self + 0x930) = *(u32 *)((u8 *)self + 0x9c);
    *(u32 *)((u8 *)self + 0x934) = *(u32 *)((u8 *)self + 0xa0);
    *(u32 *)((u8 *)self + 0x938) = *(u32 *)((u8 *)self + 0xa4);

    if (self->movie == 0) {
        copy = 0;
    } else if (fn_12_24E94( (fn_12_245C4_MovieModule *)(fn_12_24670_MovieModule *)(self)) > 0) {
        copy = 0;
    } else {
        copy = (MovieBuffer *)((u8 *)self->movie + 0x0c);
    }
    if (copy != 0) {
        *copy = self->buffer;
    }
    return 1;
}
/* fzgx:end fn_12_24670 */

/* fzgx:begin fn_12_24760 */
/* --- rel/movie_module/fn_12_24760.c --- */

u32 fn_12_24760(void) {
    void *movie;
    u32 result;

    movie = fn_12_3310C();
    if (movie == 0) {
        return 0;
    }
    if (fn_12_32EAC(movie, (s32 *)(u32 *)(&result)) == 0) {
        result = 0;
    }
    fn_12_330E0(movie);
    return result;
}
/* fzgx:end fn_12_24760 */

/* fzgx:begin fn_12_247BC */
/* --- rel/movie_module/fn_12_247BC.c --- */

static inline s32 read_bytes(u8 *p, s32 count) {
    s32 value = *p++;
    int i;
    for (i = 1; i < count; i++) {
        value <<= 8;
        value |= *p++;
    }
    return value;
}

static inline s32 get_info(const void *data, u32 size) {
    void *movie;
    s32 result;
    movie = fn_12_3310C(data, size);
    if (movie == 0) return 0;
    if (fn_12_32EAC(movie, &result) == 0) result = 0;
    fn_12_330E0(movie);
    return result;
}

int fn_12_247BC(void *self, s32 type, u8 *data, s32 size, s32 *out) {
    s32 code;
    *out = 0;
    if (type != 2) return 0;
    data -= 6;
    size += 6;
    code = read_bytes(data, 4);
    if (code != 0x1bf) {
        data -= 2;
        size += 2;
        code = read_bytes(data, 4);
        if (code != 0x1bf) return 0;
    }
    if (!get_info(data - 12, size + 12)) return 0;
    *out = fn_12_24670( (fn_12_24670_MovieModule *)(void *)(self), data - 12, size + 12);
    return 1;
}
/* fzgx:end fn_12_247BC */

/* fzgx:begin fn_12_248D4 */
/* --- rel/movie_module/fn_12_248D4.c --- */
/* --- rel/movie_module/fn_12_248D4.c --- */
typedef struct fn_12_248D4_MovieModule {
    u32 unk_00;
    u8 pad_04[8];
    u32 unk_0c;
    u8 pad_10[0x80];
    u32 unk_90;
} fn_12_248D4_MovieModule;

void fn_12_248D4(fn_12_248D4_MovieModule *self) {
    self->unk_00 = 0;
    self->unk_0c = 0;
    self->unk_90 = 0;
}
/* fzgx:end fn_12_248D4 */

/* fzgx:begin fn_12_248E8 */
/* --- rel/movie_module/fn_12_248E8.c --- */
/* --- rel/movie_module/fn_12_248E8.c --- */
typedef struct MovieModule_u1 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u8 pad_10[0x80];
    u32 unk_90;
} MovieModule_u1;

void fn_12_248E8(MovieModule_u1 *self) {
    self->unk_00 = 0;
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_0c = 0;
    self->unk_90 = 0;
}
/* fzgx:end fn_12_248E8 */

/* fzgx:begin fn_12_24904 */
/* --- rel/movie_module/fn_12_24904.c --- */

void fn_12_24904(void) {
    fn_12_33178();
}
/* fzgx:end fn_12_24904 */

/* fzgx:begin fn_12_24924 */
/* --- rel/movie_module/fn_12_24924.c --- */

void fn_12_24924(void) {
    fn_12_331A8(0x20, lbl_12_bss_7A50);
}
/* fzgx:end fn_12_24924 */
