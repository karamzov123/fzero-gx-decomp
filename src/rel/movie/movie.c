#include "types.h"
#include "rel/movie/globals.h"
#include "rel/movie/movie.h"
extern u32 lbl_5_bss_AF4;
extern s32 fn_80082928(char *, const char *, ...);
extern char *strchr(const char *, int);
extern s8 lbl_5_bss_5D;
extern u32 lbl_5_bss_20;

/* fzgx:begin fn_5_3C44 noprologue */
#include "types.h"
#include "rel/movie/movie.h"

typedef struct MovieDecoder MovieDecoder;
typedef struct MovieDecoderVtbl {
    u8 pad_0[0x14];
    void (*stop)(MovieDecoder *);
    u8 pad_18[0x4];
    void (*close)(MovieDecoder *);
} MovieDecoderVtbl;
struct MovieDecoder {
    MovieDecoderVtbl *vtbl;
};
struct fn_5_3C44_lbl_5_bss_0 {
    u32 unk_0;
    u8 pad_4[0xF];
    u8 unk_13;
    u8 pad_14[0x14];
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x8];
    s8 unk_40;
    u8 unk_41;
    u8 pad_42[0x2];
    u32 unk_44;
    u8 pad_48[0x84];
    u32 unk_CC;
    u8 pad_D0[0xAC0];
    u32 unk_B90;
};
struct fn_5_3C44_lbl_801A6410 {
    u32 unk_0;
};
extern struct fn_5_3C44_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_435C(u32);
extern u32 lbl_1_bss_190;
extern void fn_1_157940(void);
extern void fn_1_41A8(void);
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_80070704(s32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_5_bss_0;
u32 lbl_5_bss_0__fzgx_offset_4[3];
u16 lbl_5_bss_0__fzgx_offset_10;
u8 lbl_5_bss_0__fzgx_offset_12;
u8 lbl_5_bss_0__fzgx_offset_13;
u32 lbl_5_bss_0__fzgx_offset_14[3];
u32 lbl_5_bss_20__fzgx_offset_0[2];
u32 lbl_5_bss_20__fzgx_offset_8;
u32 lbl_5_bss_20__fzgx_offset_C;
u32 lbl_5_bss_20__fzgx_offset_10;
u32 lbl_5_bss_20__fzgx_offset_14;
u32 lbl_5_bss_20__fzgx_offset_18[2];
s8 lbl_5_bss_40;
u8 lbl_5_bss_40__fzgx_offset_1;
u16 lbl_5_bss_40__fzgx_offset_2;
u32 lbl_5_bss_40__fzgx_offset_4;
u32 lbl_5_bss_40__fzgx_offset_8[5];
u8 lbl_5_bss_40__fzgx_offset_1C;
u8 lbl_5_bss_5D;
u8 fzgx_pool_lbl_5_bss_0_gap_5E;
u8 lbl_5_bss_5F;
u8 fzgx_pool_lbl_5_bss_0_gap_60;
u8 lbl_5_bss_61__fzgx_offset_0;
u16 lbl_5_bss_61__fzgx_offset_1;
u32 lbl_5_bss_61__fzgx_offset_3[5];
u8 lbl_5_bss_61__fzgx_offset_17;
u8 lbl_5_bss_61__fzgx_offset_18;
u16 lbl_5_bss_61__fzgx_offset_19;
u32 lbl_5_bss_61__fzgx_offset_1B;
u8 lbl_5_bss_61__fzgx_offset_1F;
u8 lbl_5_bss_61__fzgx_offset_20;
u16 lbl_5_bss_61__fzgx_offset_21;
u32 lbl_5_bss_61__fzgx_offset_23[18];
u32 lbl_5_bss_61__fzgx_offset_6B;
u32 lbl_5_bss_61__fzgx_offset_6F[649];
u8 lbl_5_bss_AF4;
u8 lbl_5_bss_AF4__fzgx_offset_1;
u16 lbl_5_bss_AF4__fzgx_offset_2;
u32 lbl_5_bss_AF4__fzgx_offset_4[38];
u32 fzgx_obj_lbl_5_bss_B90;
u32 lbl_5_bss_B90__fzgx_offset_4[9];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_5_bss_0;
    s = *(u8 *)&lbl_5_bss_0__fzgx_offset_4;
    s = *(u8 *)&lbl_5_bss_0__fzgx_offset_10;
    s = *(u8 *)&lbl_5_bss_0__fzgx_offset_12;
    s = *(u8 *)&lbl_5_bss_0__fzgx_offset_13;
    s = *(u8 *)&lbl_5_bss_0__fzgx_offset_14;
    s = *(u8 *)&lbl_5_bss_20__fzgx_offset_0;
    s = *(u8 *)&lbl_5_bss_20__fzgx_offset_8;
    s = *(u8 *)&lbl_5_bss_20__fzgx_offset_C;
    s = *(u8 *)&lbl_5_bss_20__fzgx_offset_10;
    s = *(u8 *)&lbl_5_bss_20__fzgx_offset_14;
    s = *(u8 *)&lbl_5_bss_20__fzgx_offset_18;
    s = *(u8 *)&lbl_5_bss_40;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_1;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_2;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_4;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_8;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_1C;
    s = *(u8 *)&lbl_5_bss_5D;
    s = *(u8 *)&fzgx_pool_lbl_5_bss_0_gap_5E;
    s = *(u8 *)&lbl_5_bss_5F;
    s = *(u8 *)&fzgx_pool_lbl_5_bss_0_gap_60;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_0;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_1;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_3;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_17;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_18;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_19;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_1B;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_1F;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_20;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_21;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_23;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_6B;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_6F;
    s = *(u8 *)&lbl_5_bss_AF4;
    s = *(u8 *)&lbl_5_bss_AF4__fzgx_offset_1;
    s = *(u8 *)&lbl_5_bss_AF4__fzgx_offset_2;
    s = *(u8 *)&lbl_5_bss_AF4__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_5_bss_B90;
    s = *(u8 *)&lbl_5_bss_B90__fzgx_offset_4;
}
#pragma section code_type ".text"

extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("movie.c");
}
#pragma section code_type ".text"

void fn_5_3C44(void) {
    MovieDecoder *dec;
    u8 i;
    u8 n;

    if (lbl_5_bss_40 == 1) {
        dec = (MovieDecoder *)fzgx_obj_lbl_5_bss_0;
        dec->vtbl->close(dec);
        lbl_5_bss_40 = 0;
        lbl_5_bss_40__fzgx_offset_1 = 0;
    }
    dec = (MovieDecoder *)fzgx_obj_lbl_5_bss_0;
    dec->vtbl->stop(dec);
    ((void (*)(void))lbl_1_bss_190)();
    fzgx_obj_lbl_5_bss_0 = 0;
    fn_1_46B4(lbl_801A6410.unk_0, lbl_5_bss_40__fzgx_offset_4, "movie.c", 1945);
    lbl_5_bss_40__fzgx_offset_4 = 0;
    fzgx_obj_lbl_5_bss_B90 = 0;

    while ((s8)(n = lbl_5_bss_0__fzgx_offset_13) >= 0) {
        if (((u32 *)&lbl_5_bss_AF4)[(s8)n] != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, ((u32 *)&lbl_5_bss_AF4)[(s8)n], "movie.c", 1951);
        }
        ((u32 *)&lbl_5_bss_AF4)[(s8)lbl_5_bss_0__fzgx_offset_13] = 0;
        lbl_5_bss_0__fzgx_offset_13--;
    }

    for (i = 0; i < 2; i++) {
        if (((u32 *)&lbl_5_bss_61__fzgx_offset_17)[i] != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, ((u32 *)&lbl_5_bss_61__fzgx_offset_17)[i], "movie.c", 1957);
            ((u32 *)&lbl_5_bss_61__fzgx_offset_17)[i] = 0;
        }
        if (((u32 *)&lbl_5_bss_61__fzgx_offset_1F)[i] != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, ((u32 *)&lbl_5_bss_61__fzgx_offset_1F)[i], "movie.c", 1958);
            ((u32 *)&lbl_5_bss_61__fzgx_offset_1F)[i] = 0;
        }
    }
    if (lbl_5_bss_61__fzgx_offset_6B != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, lbl_5_bss_61__fzgx_offset_6B, "movie.c", 1960);
        lbl_5_bss_61__fzgx_offset_6B = 0;
    }
    fn_1_157940();
    fn_1_435C(lbl_5_bss_20__fzgx_offset_8);
    fn_1_41A8();
    fn_1_435C(lbl_5_bss_20__fzgx_offset_C);
    fn_1_41A8();
    fn_1_435C(lbl_5_bss_20__fzgx_offset_10);
    fn_1_41A8();
    fn_1_435C(lbl_5_bss_20__fzgx_offset_14);
    fn_1_41A8();
    fn_80070704(1);
    lbl_5_bss_40 = -2;
}
/* fzgx:end fn_5_3C44 */

/* fzgx:begin fn_5_3E54 */
void fn_5_3E54(u32 arg0) {
    (*(u32 *)&lbl_5_bss_B90) = *(u32 *)((u8 *)&lbl_5_bss_AF4 + ((s8)arg0 << 2));
}
/* fzgx:end fn_5_3E54 */

/* fzgx:begin fn_5_3E74 */
struct fn_5_3E74_Arg0 {
    s32 unk_0;
    u8 pad_4[0xc];
    u8 unk_10[0x100];
};

u32 fn_5_3E74(struct fn_5_3E74_Arg0 *arg0) {
    u32 v1;
    s32 v3;
    s16 i;
    u8 c;

    v1 = 0;
    v3 = 0;
    fn_80082928((char *)(*(u32 *)&lbl_5_bss_B90), (*(char (*)[])&lbl_5_data_1784), arg0, (u8 *)arg0 + 4,
                (u8 *)arg0 + 8, (u8 *)arg0 + 12, (u8 *)arg0 + 16);
    if (arg0->unk_0 == -1) {
        (*(u32 *)&lbl_5_bss_B90) = 0;
    } else {
        i = 0;
        while ((c = arg0->unk_10[i]) != '*' && i < 255) {
            if (c == '[') {
                v3 = 1;
            } else if (c == ']') {
                v3 = 0;
            }
            i++;
            if (v3 == 0) {
                v1++;
            }
        }
        arg0->unk_10[i] = 0;
        (*(u32 *)&lbl_5_bss_B90) = (u32)strchr((const char *)(*(u32 *)&lbl_5_bss_B90), '\n') + 1;
    }
    if (lbl_5_bss_5D == 5) {
        v1 = (v1 >> 1) & 0x7f;
    }
    return v1;
}
/* fzgx:end fn_5_3E74 */

/* fzgx:begin fn_5_3F94 */
typedef u32 (*fn_5_3F94_Fn0)(void);
typedef u32 (*fn_5_3F94_Fn1)(u32, u32);
struct fn_5_3F94_lbl_5_bss_0 {
    u32 unk_0;
};

void fn_5_3F94(void) {
    u32 v0;
    if (lbl_5_bss_20 != 0) {
    ((fn_5_3F94_Fn0)lbl_5_bss_20)();
    }
    v0 = (*(struct fn_5_3F94_lbl_5_bss_0 *)&lbl_5_bss_0).unk_0;
    if (v0 != 0) {
    ((fn_5_3F94_Fn1)*(u32 *)((u8 *)*(u32 *)((u8 *)v0 + 0) + 40))(v0, 1);
    }
}
/* fzgx:end fn_5_3F94 */

/* fzgx:begin fn_5_3FF0 */
typedef u32 (*fn_5_3FF0_Fn0)(void);
typedef u32 (*fn_5_3FF0_Fn1)(u32, u32);
struct fn_5_3FF0_lbl_5_bss_0 {
    u32 unk_0;
    u8 pad_4[0x1C];
    u32 unk_20;
    u32 unk_24;
};



void fn_5_3FF0(void) {
    struct fn_5_3FF0_lbl_5_bss_0 *p_lbl_5_bss_0;
    u32 v0;
    p_lbl_5_bss_0 = (struct fn_5_3FF0_lbl_5_bss_0 *)&(*(struct fn_5_3FF0_lbl_5_bss_0 *)&lbl_5_bss_0);
    if (p_lbl_5_bss_0->unk_20 != 0) {
        ((fn_5_3FF0_Fn0)p_lbl_5_bss_0->unk_24)();
    }
    v0 = p_lbl_5_bss_0->unk_0;
    if (v0 != 0) {
        ((fn_5_3FF0_Fn1)*(u32 *)((u8 *)*(u32 *)((u8 *)v0 + 0) + 40))(v0, 0);
    }
}
/* fzgx:end fn_5_3FF0 */
