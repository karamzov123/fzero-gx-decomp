#include "types.h"


/* --- rel/movie_module/fn_12_247BC.c --- */
extern void *fn_12_3310C(const void *, u32);
extern int fn_12_32EAC(void *, s32 *);
extern void fn_12_330E0(void *);
extern int fn_12_24670(void *, void *, int);

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
    *out = fn_12_24670(self, data - 12, size + 12);
    return 1;
}

/* --- rel/movie_module/fn_12_248D4.c --- */
/* --- rel/movie_module/fn_12_248D4.c --- */
typedef struct MovieModule {
    u32 unk_00;
    u8 pad_04[8];
    u32 unk_0c;
    u8 pad_10[0x80];
    u32 unk_90;
} MovieModule;

void fn_12_248D4(MovieModule *self) {
    self->unk_00 = 0;
    self->unk_0c = 0;
    self->unk_90 = 0;
}

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

/* --- rel/movie_module/fn_12_24904.c --- */
extern void fn_12_33178(void);

void fn_12_24904(void) {
    fn_12_33178();
}

/* --- rel/movie_module/fn_12_24924.c --- */
extern u8 lbl_12_bss_7A50[520];
extern void fn_12_331A8(s32, u8 *);

void fn_12_24924(void) {
    fn_12_331A8(0x20, lbl_12_bss_7A50);
}

/* --- rel/movie_module/fn_12_24950.c --- */
extern void fn_8004EBB4(void);

void fn_12_24950(void);

/* --- rel/movie_module/fn_12_24970.c --- */
extern void fn_8004EBD4(void);

void fn_12_24970(void);

/* --- rel/movie_module/fn_12_24990.c --- */
extern u32 lbl_12_bss_7C5C;

s32 fn_12_24990(u32 arg0);
