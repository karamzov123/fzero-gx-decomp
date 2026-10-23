#include "types.h"
#include "rel/movie/globals.h"
extern u32 lbl_5_bss_0[8];
extern struct fn_5_200_lbl_1_bss_970 lbl_1_bss_970;
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_435C(u32);
extern const f32 lbl_5_rodata_0;
extern void fn_8006CE1C(f32);
extern void fn_1_3C78(void);
extern void fn_1_157940(void);
extern void fn_1_41A8(u32);
extern void fn_1_A0AA4(void);
extern void fn_1_47A60(u32);
extern void fn_800068F4(u32);
extern void fn_80006904(u32);
extern void fn_1_A5C98(void *);
extern s16 lbl_1_bss_962;
extern struct fn_5_320_lbl_5_data_40 lbl_5_data_40;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 fn_1_412A0(u32);
extern u32 fn_1_48140(u32);
extern u8 lbl_5_bss_5F;
extern u8 lbl_5_bss_61;
extern u32 fn_5_3C44(void);
extern u8 lbl_5_bss_40;

/* fzgx:begin fn_5_200 */
struct fn_5_200_lbl_1_bss_970 {
    u32 unk_0;
};

void fn_5_200(void) {
    if ((s32) lbl_1_bss_970.unk_0 > 0) {
        lbl_1_bss_970.unk_0 -= 1;
    }
}
/* fzgx:end fn_5_200 */

/* fzgx:begin fn_5_220 */
struct fn_5_220_lbl_5_bss_0 {
    u8 pad_0[0x28];
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
};

void fn_5_220(void) {
    struct fn_5_220_lbl_5_bss_0 *p_lbl_5_bss_0;
    u32 t0, t2, t3, t5, t7;
    p_lbl_5_bss_0 = (struct fn_5_220_lbl_5_bss_0 *)&(*(struct fn_5_220_lbl_5_bss_0 *)&lbl_5_bss_0);
    t0 = fn_1_435C(p_lbl_5_bss_0->unk_28);
    fn_1_407C(t0);
    t2 = fn_1_435C(p_lbl_5_bss_0->unk_30);
    t3 = fn_1_407C(t2);
    fn_1_3CC4(t3);
    t5 = fn_1_435C(p_lbl_5_bss_0->unk_2C);
    fn_1_407C(t5);
    t7 = fn_1_435C(p_lbl_5_bss_0->unk_34);
    fn_1_407C(t7);
}
/* fzgx:end fn_5_220 */

/* fzgx:begin _epilog */
struct epilog_bss {
    u8 pad_0[0x20];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 unk_38[1];
};

void _epilog(void) {
    struct epilog_bss *p;
    u32 t0;

    p = (struct epilog_bss *)&lbl_5_bss_0;
    fn_8006CE1C(lbl_5_rodata_0);
    fn_1_3C78();
    fn_1_157940();
    t0 = fn_1_435C(p->unk_28);
    fn_1_41A8(t0);
    t0 = fn_1_435C(p->unk_2C);
    fn_1_41A8(t0);
    t0 = fn_1_435C(p->unk_30);
    fn_1_41A8(t0);
    t0 = fn_1_435C(p->unk_34);
    fn_1_41A8(t0);
    fn_1_A0AA4();
    fn_1_47A60(8);
    fn_800068F4(p->unk_20);
    fn_80006904(p->unk_24);
    p->unk_20 = 0;
    p->unk_24 = 0;
    fn_1_A5C98(&p->unk_38);
}
/* fzgx:end _epilog */

/* fzgx:begin fn_5_320 */
typedef u32 (*fn_5_320_Fn0)(void);
struct fn_5_320_lbl_5_data_40_0_E44 {
    u8 pad_0[0x20];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
};
struct fn_5_320_lbl_5_data_40 {
    struct fn_5_320_lbl_5_data_40_0_E44 unk_0[1];
};

void fn_5_320(void) {
    s32 i;
    struct fn_5_320_lbl_5_data_40_0_E44 *p;
    u32 v0;
    p = lbl_5_data_40.unk_0;
    i = lbl_1_bss_962;
    i -= 129;
    p += i;
    lbl_1_bss_71688 = p->unk_24;
    v0 = p->unk_28;
    lbl_1_bss_7168C = v0;
    ((fn_5_320_Fn0)p->unk_20)();
}
/* fzgx:end fn_5_320 */

/* fzgx:begin fn_5_37C noprologue */
#include "types.h"

struct fn_5_37C_in {
    s8 unk_0;
    u8 unk_1;
    s8 unk_2;
    s8 unk_3;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
    s16 unk_A;
    f32 unk_C;
    f32 unk_10;
    s8 unk_14;
    u8 pad_15[1];
    s8 unk_16;
    s8 unk_17;
    s16 unk_18;
    u8 pad_1A[2];
    u32 unk_1C;
};

struct fn_5_37C_out {
    u8 pad_0[0x40];
    u8 unk_40;
    u8 unk_41;
    u8 pad_42[2];
    u32 unk_44;
    u8 unk_48;
    u8 pad_49[1];
    s16 unk_4A;
    s16 unk_4C;
    s16 unk_4E;
    s16 unk_50;
    u8 pad_52[2];
    f32 unk_54;
    f32 unk_58;
    s8 unk_5C;
    s8 unk_5D;
    u8 unk_5E;
    u8 unk_5F;
    s8 unk_60;
    s8 unk_61;
    s8 unk_62;
    u8 pad_63[1];
    s16 unk_64;
    u8 unk_66;
};

extern struct fn_5_37C_in lbl_1_bss_58;
extern struct fn_5_37C_out lbl_5_bss_0;
extern u32 lbl_1_bss_970;
extern void fn_1_47F74(s32);
extern void fn_1_411A4(u32);
extern u32 fn_1_FA638(void);
extern u32 fn_5_169C(void);

#pragma opt_common_subs off
#pragma opt_lifetimes off
void fn_5_37C(void) {
    s32 tmp_call6;
    struct fn_5_37C_in *in;
    struct fn_5_37C_out *p;
    s8 v;

    in = &lbl_1_bss_58;
    p = &lbl_5_bss_0;
    p->unk_40 = 0;
    p->unk_41 = 0;
    p->unk_44 = 0;
    p->unk_48 = 1;
    p->unk_4A = in->unk_4;
    p->unk_4C = in->unk_6;
    p->unk_4E = in->unk_8;
    p->unk_50 = in->unk_A;
    p->unk_54 = in->unk_C;
    p->unk_58 = in->unk_10;
    p->unk_5C = in->unk_3;
    p->unk_5D = in->unk_0;
    p->unk_5E = in->unk_1;
    p->unk_5F = in->unk_2;
    p->unk_60 = in->unk_14;
    p->unk_61 = in->unk_16;
    p->unk_62 = in->unk_17;
    p->unk_64 = in->unk_18;
    if (in->unk_2) {
        fn_1_47F74(0x9a);
        fn_1_47F74(0x9b);
        fn_1_47F74(0x93);
        fn_1_411A4(1);
    }
    if (p->unk_61) {
        fn_1_47F74(1);
    }
    if (!(p->unk_5D)) {
        tmp_call6 = fn_1_FA638();
        v = (s8)tmp_call6;
    } else {
        v = 1;
    }
    p->unk_66 = v;
    lbl_1_bss_58.unk_1C = 0;
    if (p->unk_5C == 2) {
        lbl_1_bss_970 = 1;
    }
    fn_5_169C();
}
#pragma opt_lifetimes reset

#pragma opt_common_subs reset
/* fzgx:end fn_5_37C */

/* fzgx:begin fn_5_4C8 noprologue */
#include "types.h"
#include "rel/movie/globals.h"

extern u32 fn_5_3C44(void);
extern void fn_1_FA650(void);
extern void fn_1_4A00(s32, u8, void *);
extern int fn_1_4C10(void);
extern s16 lbl_1_bss_964;
extern s16 lbl_1_bss_968;

typedef struct { u8 pad_0[8]; u16 unk_8; u8 pad_A[10]; } fn_5_4C8_Pad;
extern fn_5_4C8_Pad lbl_1_bss_9F8[];

struct fn_5_4C8_58 {
    u8 pad_0[0x1C];
    u32 unk_1C;
};
extern struct fn_5_4C8_58 lbl_1_bss_58;

struct fn_5_4C8_bss {
    u8 pad_0[0x2C];
    void *unk_2C;
    u8 pad_30[0x10];
    s8 unk_40;
    u8 pad_41[0x1F];
    s8 unk_60;
    u8 unk_61;
    s8 unk_62;
    u8 pad_63[3];
    s8 unk_66;
    s8 unk_67;
};

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_5_bss_0[8];
u32 lbl_5_bss_20__fzgx_offset_0[3];
void *lbl_5_bss_20__fzgx_offset_C;
u32 lbl_5_bss_20__fzgx_offset_10[4];
s8 lbl_5_bss_40;
u8 lbl_5_bss_40__fzgx_offset_1;
u16 lbl_5_bss_40__fzgx_offset_2;
u32 lbl_5_bss_40__fzgx_offset_4[6];
u8 lbl_5_bss_40__fzgx_offset_1C;
u8 lbl_5_bss_5D;
u8 fzgx_pool_lbl_5_bss_0_gap_5E;
u8 lbl_5_bss_5F;
s8 fzgx_pool_lbl_5_bss_0_gap_60;
u8 lbl_5_bss_61__fzgx_offset_0;
s8 lbl_5_bss_61__fzgx_offset_1;
u8 lbl_5_bss_61__fzgx_offset_2;
u16 lbl_5_bss_61__fzgx_offset_3;
s8 lbl_5_bss_61__fzgx_offset_5;
s8 lbl_5_bss_61__fzgx_offset_6;
u32 lbl_5_bss_61__fzgx_offset_7[675];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_5_bss_0;
    s = *(u8 *)&lbl_5_bss_20__fzgx_offset_0;
    s = *(u8 *)&lbl_5_bss_20__fzgx_offset_C;
    s = *(u8 *)&lbl_5_bss_20__fzgx_offset_10;
    s = *(u8 *)&lbl_5_bss_40;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_1;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_2;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_4;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_1C;
    s = *(u8 *)&lbl_5_bss_5D;
    s = *(u8 *)&fzgx_pool_lbl_5_bss_0_gap_5E;
    s = *(u8 *)&lbl_5_bss_5F;
    s = *(u8 *)&fzgx_pool_lbl_5_bss_0_gap_60;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_0;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_1;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_2;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_3;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_5;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_6;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_7;
}
#pragma section code_type ".text"

#pragma opt_propagation off
void fn_5_4C8(void) {
    u32 flags;
    s32 f23;
    s32 f22;
    s32 f19;
    s32 f27;

    
    if (lbl_5_bss_40 == 1 || lbl_5_bss_40 == 0) {
        flags = 0;
        if (lbl_5_bss_61__fzgx_offset_6 == 1) {
            f27 = 0;
            f19 = 0;
            f22 = 0;
            f23 = 0;
        } else if (!(lbl_5_bss_61__fzgx_offset_1 < 0 || lbl_5_bss_61__fzgx_offset_1 >= 4)) {
            u16 *tbl = &lbl_1_bss_9F8[0].unk_8;
            u16 t = tbl[lbl_5_bss_61__fzgx_offset_1 * 10];
            f23 = (t >> 8) & 1;
            f22 = (t >> 9) & 1;
            f27 = (t >> 4) & 1;
            f19 = (t >> 12) & 1;
        } else {
            u16 t = lbl_1_bss_9F8[0].unk_8;
            f23 = (t >> 8) & 1;
            f22 = (t >> 9) & 1;
            f27 = (t >> 4) & 1;
            f19 = (t >> 12) & 1;
        }
        if ((fzgx_pool_lbl_5_bss_0_gap_60 & 1) && f23 != 0) {
            flags |= 1;
        } else if ((fzgx_pool_lbl_5_bss_0_gap_60 & 2) && f22 != 0) {
            flags |= 2;
        } else if ((fzgx_pool_lbl_5_bss_0_gap_60 & 4) && f19 != 0) {
            flags |= 4;
        }
        if (f27 != 0) {
            lbl_5_bss_61__fzgx_offset_5 = !lbl_5_bss_61__fzgx_offset_5;
            fn_1_FA650();
        }
        if (flags != 0) {
            fn_5_3C44();
            lbl_1_bss_58.unk_1C = flags;
        }
    } else if (lbl_5_bss_40 == -1) {
        if (lbl_1_bss_964 == 15) {
            lbl_5_bss_40 = 2;
            fn_1_4A00(0, 15, lbl_5_bss_20__fzgx_offset_C);
        } else {
            fn_5_3C44();
        }
    } else if (lbl_5_bss_40 == 2) {
        if (fn_1_4C10() == 0) {
            fn_5_3C44();
        }
    } else if (lbl_5_bss_40 != 0) {
        lbl_1_bss_968 = lbl_1_bss_964;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_5_4C8 */

/* fzgx:begin fn_5_684 */
void fn_5_684(void) {
    if ((s8)lbl_5_bss_5F != 0) {
    fn_1_48140(154);
    fn_1_48140(155);
    fn_1_48140(147);
    fn_1_412A0(1);
    }
    if ((s8)lbl_5_bss_61 != 0) {
    fn_1_48140(1);
    }
}
/* fzgx:end fn_5_684 */

/* fzgx:begin fn_5_6E8 noprologue */
#include "types.h"
#include "rel/movie/globals.h"

extern f32 lbl_5_rodata_4[51];
extern const f32 lbl_5_rodata_0;
extern u32 lbl_801A66B4;
extern struct fn_5_200_lbl_1_bss_970 lbl_1_bss_970[];
extern void fn_1_47F74(s32);
extern void fn_1_411A4(u32);
extern void fn_8006CE1C(f32);

struct init_bss {
    u8 pad_0[0x40];
    s8 unk_40;
    u8 unk_41;
    u8 pad_42[2];
    s32 unk_44;
    u8 unk_48;
    u8 pad_49[5];
    s16 unk_4E;
    s16 unk_50;
    u8 pad_52[2];
    f32 unk_54;
    f32 unk_58;
    u8 pad_5C;
    u8 unk_5D;
    u8 unk_5E;
    u8 unk_5F;
    u8 pad_60[4];
    s16 unk_64;
    u8 unk_66;
};

struct init_970 {
    u8 pad_0[4];
    u8 unk_4;
};

struct init_tbl {
    u32 field_0;
};

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_5_bss_0[8];
u32 lbl_5_bss_20[8];
s8 lbl_5_bss_40;
u8 lbl_5_bss_40__fzgx_offset_1;
u16 lbl_5_bss_40__fzgx_offset_2;
s32 lbl_5_bss_40__fzgx_offset_4;
u8 lbl_5_bss_40__fzgx_offset_8;
u8 lbl_5_bss_40__fzgx_offset_9;
u16 lbl_5_bss_40__fzgx_offset_A;
u16 lbl_5_bss_40__fzgx_offset_C;
s16 lbl_5_bss_40__fzgx_offset_E;
s16 lbl_5_bss_40__fzgx_offset_10;
u16 lbl_5_bss_40__fzgx_offset_12;
f32 lbl_5_bss_40__fzgx_offset_14;
f32 lbl_5_bss_40__fzgx_offset_18;
u8 lbl_5_bss_40__fzgx_offset_1C;
u8 lbl_5_bss_5D;
u8 fzgx_pool_lbl_5_bss_0_gap_5E;
u8 lbl_5_bss_5F;
u8 fzgx_pool_lbl_5_bss_0_gap_60;
u8 lbl_5_bss_61__fzgx_offset_0;
u16 lbl_5_bss_61__fzgx_offset_1;
s16 lbl_5_bss_61__fzgx_offset_3;
u8 lbl_5_bss_61__fzgx_offset_5;
u8 lbl_5_bss_61__fzgx_offset_6;
u32 lbl_5_bss_61__fzgx_offset_7[675];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_5_bss_0;
    s = *(u8 *)&lbl_5_bss_20;
    s = *(u8 *)&lbl_5_bss_40;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_1;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_2;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_4;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_8;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_9;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_A;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_C;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_E;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_10;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_12;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_14;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_18;
    s = *(u8 *)&lbl_5_bss_40__fzgx_offset_1C;
    s = *(u8 *)&lbl_5_bss_5D;
    s = *(u8 *)&fzgx_pool_lbl_5_bss_0_gap_5E;
    s = *(u8 *)&lbl_5_bss_5F;
    s = *(u8 *)&fzgx_pool_lbl_5_bss_0_gap_60;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_0;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_1;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_3;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_5;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_6;
    s = *(u8 *)&lbl_5_bss_61__fzgx_offset_7;
}
#pragma section code_type ".text"

void fn_5_6E8(void) {
    struct init_tbl *t;
    f32 *one;
    struct init_970 *q;
    f32 f;

    t = (struct init_tbl *)&lbl_801A66B4;
    
    one = &lbl_5_rodata_4[0];
    q = (struct init_970 *)&lbl_1_bss_970;
    f = *one;

    lbl_5_bss_40 = -2;
    lbl_5_bss_40__fzgx_offset_1 = 0;
    lbl_5_bss_40__fzgx_offset_4 = 0;
    lbl_5_bss_5D = (t->field_0);
    fzgx_pool_lbl_5_bss_0_gap_5E = 1;
    lbl_5_bss_40__fzgx_offset_E = 0;
    lbl_5_bss_40__fzgx_offset_10 = 0;
    lbl_5_bss_40__fzgx_offset_14 = f;
    lbl_5_bss_40__fzgx_offset_18 = f;
    lbl_5_bss_40__fzgx_offset_8 = 1;
    lbl_5_bss_5F = 0;
    lbl_5_bss_61__fzgx_offset_3 = -1;
    lbl_5_bss_61__fzgx_offset_5 = 1;
    q->unk_4 = 0;

    fn_1_47F74(154);
    fn_1_47F74(155);
    fn_1_47F74(147);
    fn_1_411A4(1);
    fn_8006CE1C(lbl_5_rodata_0);
}
/* fzgx:end fn_5_6E8 */

/* fzgx:begin fn_5_13B0 */
void fn_5_13B0(void) {
    if ((s8)lbl_5_bss_40 != -2) {
    fn_5_3C44();
    }
    fn_1_48140(154);
    fn_1_48140(155);
    fn_1_48140(147);
    fn_1_412A0(1);
}
/* fzgx:end fn_5_13B0 */

/* fzgx:begin fn_5_1404 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 8.0f;
    s = 0.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table4[1] = {0x80FF80FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table5[1] = {0xFF0000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table6[1] = {0x80FF80FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table7[1] = {0xFFFF80FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.0f;
    s = 4.0f;
    s = 80.0f;
    s = 360.0f;
    s = 0.6000000238418579f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern u8 lbl_5_data_0[];
extern u32 lbl_5_bss_0[8];
extern struct fn_5_200_lbl_1_bss_970 lbl_1_bss_970;
extern const f32 lbl_5_rodata_0;

extern void fn_1_49410(void *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49514(u32 *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4965C(u8);

struct rodata_5 {
    u8 pad_0[0x10];
    f32 unk_10;
    f32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
};

struct bss_5 {
    u8 pad_0[0x48];
    u8 unk_48;
    u8 pad_49[0x5];
    s16 unk_4E;
    s16 unk_50;
    u8 pad_52[0x2];
    f32 unk_54;
    u8 pad_58[0x5];
    s8 unk_5D;
    s8 unk_5E;
    s8 unk_5F;
};

void fn_5_1404(u8 *arg0) {
    struct rodata_5 *r28;
    u8 *r29;
    struct bss_5 *r30;
    u8 *r31;
    u8 *p;
    s32 i;
    f32 f30;
    f32 f29;
    u32 sp14;
    u32 sp10;
    u32 spC;
    u32 sp8;

    r28 = (struct rodata_5 *)&lbl_5_rodata_0;
    r29 = lbl_5_data_0;
    r30 = (struct bss_5 *)&lbl_5_bss_0;
    fn_1_49410(arg0);
    fn_1_4955C((0.5f), (0.5f));
    sp14 = fzgx_pool_table4[0];
    fn_1_49514(&sp14);
    r31 = (u8 *)&lbl_1_bss_970;
    p = arg0;
    i = 0;
    while (*(s16 *)(p + 2) != -1) {
        f30 = (f32)((s32)p[0] * 12 + 50);
        f29 = (f32)((s32)p[1] * 12 + 50);
        fn_1_496FC(f30, f29);
        fn_1_4AE0C((const char *)(r29 + 0x1544), p + 4);
        if (i == r31[4]) {
            fn_1_496FC((f30 - (12.0f)) - (4.0f), f29);
            sp10 = fzgx_pool_table5[0];
            fn_1_49514(&sp10);
            fn_1_4A0D8((const char *)(r29 + 0x1548));
            spC = fzgx_pool_table6[0];
            fn_1_49514(&spC);
        }
        p += 0x44;
        i += 1;
    }
    sp8 = fzgx_pool_table7[0];
    fn_1_49514(&sp8);
    fn_1_496FC((80.0f), (360.0f));
    fn_1_4955C((0.600000024f), (0.600000024f));
    fn_1_4965C(2);
    {
        u8 *s;
        u8 *r4;
        s = r29 + 0x154c;
        r4 = r29 + 0x1578;
        if (r30->unk_48 != 0) {
            r4 = r29 + 0x1574;
        }
        fn_1_4AE0C((const char *)s, r4);
    }
    fn_1_4AE0C((const char *)(r29 + 0x157c), r30->unk_54);
    fn_1_4AE0C((const char *)(r29 + 0x15b4), r30->unk_4E, r30->unk_50);
    {
        u8 *r4;
        if (r30->unk_5D == 5) {
            r4 = r29 + 0x15e8;
        } else if (r30->unk_5D == 0) {
            r4 = r29 + 0x15f4;
        } else if (r30->unk_5D == 1) {
            r4 = r29 + 0x1600;
        } else if (r30->unk_5D == 2) {
            r4 = r29 + 0x160c;
        } else if (r30->unk_5D == 3) {
            r4 = r29 + 0x1618;
        } else {
            r4 = r29 + 0x1630;
            if (r30->unk_5D == 4) {
                r4 = r29 + 0x1624;
            }
        }
        fn_1_4AE0C((const char *)(r29 + 0x1634), r4);
    }
    {
        u8 *s;
        u8 *r4;
        s = r29 + 0x1654;
        r4 = r29 + 0x1578;
        if (r30->unk_5E != 0) {
            r4 = r29 + 0x1574;
        }
        fn_1_4AE0C((const char *)s, r4);
    }
    {
        u8 *s;
        u8 *r4;
        s = r29 + 0x1678;
        r4 = r29 + 0x1578;
        if (r30->unk_5F != 0) {
            r4 = r29 + 0x1574;
        }
        fn_1_4AE0C((const char *)s, r4);
    }
}
/* fzgx:end fn_5_1404 */

/* fzgx:begin fn_5_2C54 */
static inline u8 fn_5_2C54_array_read(u8 *array, s32 index) { return array[index]; }
#pragma opt_propagation off
#pragma opt_lifetimes off
#pragma opt_common_subs off
s16 fn_5_2C54(u8 *arg0, s32 arg1, s32 arg2) {
    s16 v0 = 0;
    s32 v3_1;
    s32 v3_2;
    s32 v3_3;
    s32 v3_4;
    s32 v3_5;
    s32 v3_6;
    s32 v3_7;
    u8 *v1;
    u8 *v1_2;
    u8 *v2;
    s32 v3;
    s32 v3_t;
    s32 v4;
    s8 v5 = 0;

    if ((s8)arg2 > 0) {
        v4 = arg2 - 8;
        if ((s8)arg2 > 8) {
            v2 = arg0 + (s8)arg1;
            v1 = v2;
            while ((s8)v5 < (s8)v4) {
                v0 = (s16)(v0 * 10);
                v3 = *v1 + v0;
                v0 = (s16)(v3 - 0x30);
                v0 = (s16)(v0 * 10);
                v3_1 = fn_5_2C54_array_read(v2, (s8)(v5 + 1));
                v3_1 = v3_1 + v0;
                v0 = (s16)(v3_1 - 0x30);
                v0 = (s16)(v0 * 10);
                v3_2 = fn_5_2C54_array_read(v2, (s8)(v5 + 2));
                v3_2 = v3_2 + v0;
                v0 = (s16)(v3_2 - 0x30);
                v0 = (s16)(v0 * 10);
                v3_3 = v2[(s8)(v5 + 3)];
                v3_3 = v3_3 + v0;
                v0 = (s16)(v3_3 - 0x30);
                v0 = (s16)(v0 * 10);
                v3_4 = v2[(s8)(v5 + 4)];
                v3_4 = v3_4 + v0;
                v0 = (s16)(v3_4 - 0x30);
                v0 = (s16)(v0 * 10);
                v3_5 = fn_5_2C54_array_read(v2, (s8)(v5 + 5));
                v3_5 = v3_5 + v0;
                v0 = (s16)(v3_5 - 0x30);
                v0 = (s16)(v0 * 10);
                v3_6 = fn_5_2C54_array_read(v2, (s8)(v5 + 6));
                v3_6 = v3_6 + v0;
                v0 = (s16)(v3_6 - 0x30);
                v0 = (s16)(v0 * 10);
                v3_7 = fn_5_2C54_array_read(v2, (s8)(v5 + 7));
                v3_7 = v3_7 + v0;
                v0 = (s16)(v3_7 - 0x30);
                v1 += 8;
                v5 += 8;
            }
        }
        v1_2 = arg0 + (s8)arg1 + v5;
        while ((s8)v5 < (s8)arg2) {
            v0 = (s16)(v0 * 10);
            v3_t = *v1_2 + v0;
            v0 = (s16)(v3_t - 0x30);
            v1_2++;
            v5++;
        }
    }
    return v0;
}
#pragma opt_common_subs reset

#pragma opt_lifetimes reset

#pragma opt_propagation reset
/* fzgx:end fn_5_2C54 */

/* fzgx:begin fn_5_3BF8 */
typedef u32 (*fn_5_3BF8_Fn0)(u32);
struct fn_5_3BF8_lbl_5_bss_0 {
    u32 unk_0;
    u8 pad_4[0x3C];
    u8 unk_40;
    u8 unk_41;
};



void fn_5_3BF8(void) {
    struct fn_5_3BF8_lbl_5_bss_0 *p_lbl_5_bss_0;
    u32 v0;
    u32 v1;
    p_lbl_5_bss_0 = (struct fn_5_3BF8_lbl_5_bss_0 *)&(*(struct fn_5_3BF8_lbl_5_bss_0 *)&lbl_5_bss_0);
    v0 = p_lbl_5_bss_0->unk_0;
    v1 = *(u32 *)v0;
    ((fn_5_3BF8_Fn0)*(u32 *)((u8 *)v1 + 28))(v0);
    p_lbl_5_bss_0->unk_40 = 0;
    p_lbl_5_bss_0->unk_41 = 0;
}
/* fzgx:end fn_5_3BF8 */
