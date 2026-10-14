/* Non-matching: best partial attempt (95.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/movie/movie.h"

typedef u32 (*fn_5_3C44_Fn0)(u32);
typedef u32 (*fn_5_3C44_Fn1)(u32);
typedef u32 (*fn_5_3C44_Fn2)(void);
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

#pragma opt_common_subs off
void fn_5_3C44(u32 arg0) {
    u32 v11;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    void *v4;
    u32 v6;
    u8 v7;
    void *v8;
    void *v9;
    u8 v10;
    struct fn_5_3C44_lbl_801A6410 *p_lbl_801A6410;
    u32 v12;
    u32 v13;
    u32 v14;
    const char * lab_t2;
    
    if ((s32)lbl_5_bss_40 == 1) {
        v0 = fzgx_obj_lbl_5_bss_0;
        v1 = *(u32 *)v0;
        ((fn_5_3C44_Fn0)*(u32 *)((u8 *)v1 + 28))(v0);
        lbl_5_bss_40 = 0;
        lbl_5_bss_40__fzgx_offset_1 = 0;
    }
    v2 = fzgx_obj_lbl_5_bss_0;
    v3 = *(u32 *)v2;
    ((fn_5_3C44_Fn1)*(u32 *)((u8 *)v3 + 20))(v2);
    ((fn_5_3C44_Fn2)lbl_1_bss_190)();
    p_lbl_801A6410 = &lbl_801A6410;
    fzgx_obj_lbl_5_bss_0 = 0;
    fn_1_46B4(p_lbl_801A6410->unk_0, lbl_5_bss_40__fzgx_offset_4, (const char *)"movie.c", 1945);
    lbl_5_bss_40__fzgx_offset_4 = 0;
    v4 = (void *)((u8 *)&lbl_5_bss_AF4);
    p_lbl_801A6410 = &lbl_801A6410;
    fzgx_obj_lbl_5_bss_B90 = 0;
    
    while ((s8)(v7 = lbl_5_bss_0__fzgx_offset_13) >= 0) {
        v6 = *(u32 *)((u8 *)v4 + ((s8)v7 << 2));
        if (v6 != 0) {
            fn_1_46B4(p_lbl_801A6410->unk_0, v6, (const char *)"movie.c", 1951);
        }
        v7 = lbl_5_bss_0__fzgx_offset_13;
        lbl_5_bss_0__fzgx_offset_13 = v7;
        *(u32 *)((u8 *)v4 + ((s8)v7 << 2)) = 0;
        lbl_5_bss_0__fzgx_offset_13 -= 1;
    }
    v8 = (void *)((u8 *)&lbl_5_bss_61__fzgx_offset_17);
    v9 = (void *)((u8 *)&lbl_5_bss_61__fzgx_offset_1F);
    v10 = 0;
    (void) v10;  /* fzgx: keeps the web at its definition */
    while (v10 < 2U) {
        v11 = v10 << 2;
        v12 = *(u32 *)((u8 *)v8 + v11);
        if (v12 != 0) {
            lab_t2 = (const char *)"movie.c";
            fn_1_46B4(lbl_801A6410.unk_0, v12, lab_t2, 1957);
            *(u32 *)((u8 *)v8 + v11) = 0;
        }
        v13 = *(u32 *)((u8 *)v9 + v11);
        if (v13 != 0) {
            fn_1_46B4(lbl_801A6410.unk_0, v13, (const char *)"movie.c", 1958);
            *(u32 *)((u8 *)v9 + v11) = 0;
        }
        v10++;
    }
    v14 = lbl_5_bss_61__fzgx_offset_6B;
    if (0 != v14) {
        fn_1_46B4(lbl_801A6410.unk_0, v14, (const char *)"movie.c", 1960);
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
#pragma opt_common_subs reset

