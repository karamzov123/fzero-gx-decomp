#include "types.h"
#include "rel/story/globals.h"
#include "rel/story/story_mode.h"
extern u8 lbl_1_bss_5138[0x104];
extern u8 lbl_1_bss_58[0x2c];
extern void ** lbl_1_bss_6EAD0;
extern u8 lbl_1_bss_7F0C0[0x5360];
extern u8 lbl_1_bss_8B3A0[];
extern s16 lbl_1_bss_968;
extern s16 lbl_1_bss_96A;
extern s8 lbl_1_bss_9C[];
extern u8 lbl_1_bss_9F8[];
extern u16 lbl_1_data_414;
extern u32 lbl_1_rodata_26F8;
extern f32 lbl_7_rodata_0[330];
extern u32 lbl_801A6410;
extern s32 lbl_801A66A0;
extern s32 lbl_801A66B4;
extern u32 fn_1_4E060(void);
extern void fn_1_3C78(void);
extern void fn_1_41A8(void);
extern s16 lbl_1_bss_962;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 fn_1_A0AA4(void);
extern void fn_1_412A0(u32);
extern void fn_1_48140(int);
extern void fn_1_12F30C(u32, void *);
extern u32 fn_1_12F10C(u32);
extern u32 fn_1_3F038(void);
extern f32 lbl_7_rodata_5B4;
extern s32 fn_7_2170(u32 arg0);
extern char lbl_7_data_13F2C[];
extern char lbl_7_data_13F34[];
extern char lbl_7_data_13F3C[];
extern s32 fn_1_13018(void);
extern s32 fn_1_467F4(void);
extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);
extern const f32 lbl_7_rodata_784;
extern f32 lbl_7_rodata_788[4];

/* fzgx:begin _prolog noprologue */
#include "types.h"

struct _prolog_bss_9C {
    s8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    s16 unk_4;
    s16 unk_6;
    s32 unk_8;
};
struct _prolog_lbl_7_bss_0 {
    u32 unk_0;
    u8 pad_4[0xC];
    struct _prolog_bss_9C *unk_10;
    u8 *unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
};
struct _prolog_lbl_801A6410 {
    u32 unk_0;
};
struct _prolog_bss_970 {
    u32 unk_0;
    u8 unk_4;
};
struct _prolog_bss_58 {
    u8 pad_0[0x1C];
    u32 unk_1C;
};
struct _prolog_bss_7F0C0 {
    u8 pad_0[0x64];
    u16 unk_64;
};
struct _prolog_data_414 {
    u16 unk_0;
};

extern struct _prolog_lbl_7_bss_0 lbl_7_bss_0;
extern struct _prolog_lbl_801A6410 lbl_801A6410;
extern struct _prolog_bss_9C lbl_1_bss_9C;
extern struct _prolog_bss_970 lbl_1_bss_970;
extern struct _prolog_bss_58 lbl_1_bss_58;
extern struct _prolog_bss_7F0C0 lbl_1_bss_7F0C0;
extern struct _prolog_data_414 lbl_1_data_414;
extern s16 lbl_1_bss_964;
extern s16 lbl_1_bss_96A;
extern u8 lbl_7_rodata_0[];
extern char lbl_7_data_13A3C[];
extern char lbl_7_data_13A4C[];
extern void *lbl_1_bss_7167C;
extern void *lbl_1_bss_71680;
extern void *lbl_1_bss_71684;

extern u32 fn_7_244(void);
extern void fn_7_25C(void);
extern void fn_7_388(void);
extern void fn_1_A8F78(void);
extern u32 fn_1_45D0(u32, u32, const char *, int);
extern void fn_1_3CF0(u32, int);
extern void fn_1_F9EB0(int, int);
extern u32 fn_1_7BA08(int, int, int);
extern void fn_1_7BA48(void);
extern void fn_1_7BAF8(void);
extern void fn_1_3F8C(const char *, void *, u32, int);

#pragma opt_dead_assignments off
void _prolog(void) {
    struct _prolog_lbl_7_bss_0 *p;
    p = (struct _prolog_lbl_7_bss_0 *)&lbl_7_bss_0;
    p->unk_10 = &lbl_1_bss_9C;
    p->unk_14 = lbl_7_rodata_0 + p->unk_10->unk_0 * 0x84;
    p->unk_10->unk_4 = 6;
    fn_1_A8F78();
    p->unk_18 = fn_1_45D0(lbl_801A6410.unk_0, 0x5cc, lbl_7_data_13A3C, 333);
    p->unk_1C = fn_1_45D0(lbl_801A6410.unk_0, 0x5cc, lbl_7_data_13A3C, 334);
    fn_1_3CF0(p->unk_18, 4);
    fn_1_3CF0(p->unk_1C, 4);
    p->unk_20 = 1;
    lbl_1_bss_970.unk_0 = 0;
    lbl_1_bss_970.unk_4 = 0;
    if (lbl_1_bss_964 == 1 && p->unk_10->unk_8 == 0x86) {
        lbl_1_bss_9C.unk_3 = 0;
    }
    if (lbl_1_bss_964 == 8 && p->unk_10->unk_0 == 0) {
        fn_1_F9EB0(0, 0);
    }
    if (lbl_1_bss_964 == 8 && p->unk_10->unk_8 == 0x89) {
        if (lbl_1_bss_58.unk_1C & 2) {
            lbl_1_bss_96A = 0x87;
        } else {
            lbl_1_bss_96A = 0x89;
        }
    } else {
        lbl_1_bss_96A = p->unk_10->unk_8;
    }
    if (lbl_1_data_414.unk_0 == 0xffff) {
        u16 v = lbl_1_bss_7F0C0.unk_64;
        lbl_1_bss_96A = 0x86;
        lbl_1_data_414.unk_0 = v;
    }
    p->unk_0 = fn_1_45D0(lbl_801A6410.unk_0, fn_1_7BA08(0x20, 0x20, 0x40), lbl_7_data_13A3C, 390);
    fn_1_7BA48();
    fn_1_3F8C(lbl_7_data_13A4C, fn_1_7BAF8, p->unk_0, 2);
    lbl_1_bss_7167C = fn_7_244;
    lbl_1_bss_71680 = fn_7_25C;
    lbl_1_bss_71684 = fn_7_388;
}
#pragma opt_dead_assignments reset
/* fzgx:end _prolog */

/* fzgx:begin fn_7_244 */
extern struct fn_7_244_lbl_7_bss_C lbl_7_bss_C;

struct fn_7_244_lbl_7_bss_C {
    u32 unk_0;
};

u32 fn_7_244(void) {
    u32 v0;
    v0 = lbl_7_bss_C.unk_0;
    lbl_7_bss_C.unk_0 = (v0 + 1);
    return v0;
}
/* fzgx:end fn_7_244 */

/* fzgx:begin fn_7_25C */
extern u32 camera_get_state(u32);
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_5948(u32);
extern u32 fn_1_627C(u32);
extern u32 fn_1_9A770(u32);
extern u32 fn_1_B7C00(void);
extern u32 fn_1_C6F8C(u32);
extern u32 fn_1_C7224(u32);

struct fn_7_25C_lbl_7_bss_0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0xC];
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x4];
    u32 unk_24;
};

void fn_7_25C(void) {
    struct fn_7_25C_lbl_7_bss_0 *p_lbl_7_bss_0;
    u32 v0;
    u32 v1;
    u32 t0, t1, t4, t5, t7, t8, t9, t11;
    p_lbl_7_bss_0 = (struct fn_7_25C_lbl_7_bss_0 *)&(*(struct fn_7_25C_lbl_7_bss_0 *)&lbl_7_bss_0);
    if ((s32)p_lbl_7_bss_0->unk_24 == 0) {
    t0 = fn_1_B7C00();
    if ((t0 & 0xFF) == 0) {
    t1 = fn_1_435C(p_lbl_7_bss_0->unk_18);
    fn_1_407C(t1);
    v0 = p_lbl_7_bss_0->unk_4;
    if ((s32)v0 > 0) {
    p_lbl_7_bss_0->unk_4 = (v0 - 1);
    }
    }
    }
    v1 = p_lbl_7_bss_0->unk_8;
    if ((s32)v1 > 0) {
    p_lbl_7_bss_0->unk_8 = (v1 - 1);
    }
    fn_1_3CC4(v1);
    t4 = fn_1_435C(p_lbl_7_bss_0->unk_1C);
    t5 = camera_get_state(t4);
    if ((s8)t5 == -1) {
    fn_1_407C(t5);
    } else {
    t7 = fn_1_5948(0);
    t8 = fn_1_9A770(t7);
    t9 = fn_1_C7224(t8);
    fn_1_407C(t9);
    t11 = fn_1_627C(0);
    fn_1_C6F8C(t11);
    }
}
/* fzgx:end fn_7_25C */

/* fzgx:begin _epilog */
struct _epilog_lbl_7_bss_0 {
    u32 unk_0;
    u8 pad_4[0x14];
    u32 unk_18;
    u32 unk_1C;
};
struct _epilog_lbl_801A6410 {
    u32 unk_0;
};

extern void * fn_1_435C(void *);
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_A8F78(void);

void _epilog(void) {
    struct _epilog_lbl_7_bss_0 *p_lbl_7_bss_0;
    p_lbl_7_bss_0 = (struct _epilog_lbl_7_bss_0 *)&(*(struct _epilog_lbl_7_bss_0 *)&lbl_7_bss_0);
    fn_1_3C78();
    fn_1_A8F78();
    fn_1_46B4((*(struct _epilog_lbl_801A6410 *)&lbl_801A6410).unk_0, p_lbl_7_bss_0->unk_0, (const char *)&(*(u32 *)&lbl_7_data_13A3C), 478);
    fn_1_435C((void *)p_lbl_7_bss_0->unk_18);
    fn_1_41A8();
    fn_1_435C((void *)p_lbl_7_bss_0->unk_1C);
    fn_1_41A8();
    fn_1_4E060();
}
/* fzgx:end _epilog */

/* fzgx:begin fn_7_388 */
typedef u32 (*fn_7_388_Fn0)(void);
struct fn_7_388_lbl_7_data_13A58_0_E44 {
    u8 pad_0[0x20];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
};

void fn_7_388(void) {
    u32 v0;
    u32 v1;
    struct fn_7_388_lbl_7_data_13A58_0_E44 *p;
    s32 index;
    p = (*(struct fn_7_388_lbl_7_data_13A58_0_E44 (*)[])&lbl_7_data_13A58);
    index = lbl_1_bss_962;
    index -= 133;
    p += index;
    v0 = p->unk_24;
    lbl_1_bss_71688 = v0;
    v1 = p->unk_28;
    lbl_1_bss_7168C = v1;
    ((fn_7_388_Fn0)p->unk_20)();
}
/* fzgx:end fn_7_388 */

/* fzgx:begin fn_7_3E4 */
extern const f32 lbl_7_rodata_528;




extern void fn_7_4050(void);
extern void fn_1_4CC0(void);
extern void fn_8006CE1C(f32);
extern s32 fn_1_F9E80(u32, u32);
extern s32 fn_1_F9CA0(u32, u32);
extern void fn_1_F9CD0(u8, u8);

void fn_7_3E4(void) {
    u32 *p;
    u8 *q;
    fn_7_4050();
    fn_1_4CC0();
    fn_8006CE1C(lbl_7_rodata_528);
    p = &(*(u32 *)&lbl_7_bss_10);
    *(u8 *)(*p) = 0;
    *(u16 *)(*p + 4) = 6;
    *(u8 *)(*p + 1) = 0;
    *(s8 *)(*p + 6) = -1;
    *(u8 *)(*p + 7) = 0;
    *(u8 *)(*p) = 0;
    while ((s8)*(u8 *)(*p) <= 10 && fn_1_F9E80(0, *(u8 *)(*p)) != 0 &&
           fn_1_F9CA0(0, (u8)(*(u8 *)(*p) + 1)) != 0) {
        (*(u8 *)(*p))++;
    }
    q = (u8 *)*(u32 *)&(*(u32 *)&lbl_7_bss_10);
    if ((s8)q[0] >= 10) {
        q[0] = 9;
    }
    if (fn_1_F9CA0(0, 0) == 0) {
        fn_1_F9CD0(0, 0);
        *((u8 *)&(*(u32 *)&lbl_1_bss_9C) + 3) = 1;
    }
}
/* fzgx:end fn_7_3E4 */

/* fzgx:begin fn_7_50C */
void fn_7_50C(void) {
    (*(u16 *)&lbl_1_bss_96A) = 135;
}
/* fzgx:end fn_7_50C */

/* fzgx:begin fn_7_51C */
// fn_7_51C: empty in retail (single blr).
void fn_7_51C(void) {
}
/* fzgx:end fn_7_51C */

/* fzgx:begin fn_7_520 noprologue */
#include "types.h"

extern void ** lbl_1_bss_6EAD0;
extern s8 lbl_1_bss_9C[];
extern u32 lbl_801A6410;

struct fn_7_520_fn_7_520_flag {
    u8 pad_0[3];
    s8 unk_3;
};






extern const f32 lbl_7_rodata_528;

extern void fn_7_4050(void);
extern u32 fn_7_4094(void *, u32, u32, u32);
extern void fn_1_4CC0(void);
extern void fn_8006CE1C(f32);
extern void fn_1_A0680(void);
extern void fn_1_47F74(s32);
extern void fn_1_411A4(u32);
extern u32 fn_1_4706C(void);
extern u32 fn_1_46A60(void);
extern u32 fn_1_4404(void);
extern u32 fn_800090A4(u32);
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern u32 fn_1_46BA0(u32, u32);
extern void fn_1_47E54(s32);
extern void fn_1_41104(u32);
extern u32 fn_1_46BFC(void);
extern u32 fn_1_46B44(u32, void *);
extern u32 fn_80008E84(u32);
extern int sprintf(char *, const char *, ...);
extern s32 fn_1_465D0(char *, s32);
extern void fn_1_4A00(s32, u8, u32);
extern u32 fn_1_A1588(void *, u32);

u8 lbl_7_data_0[0x2A0] = {1};
static u8 fzgx_pool_data_gap0[0x12E74 - 0x2A0] = {1};
u32 lbl_7_data_12E70__fzgx_offset_4 = 1;
s32 lbl_7_data_12E78 = 1;
static u8 fzgx_pool_data_gap1[0x13A3C - 0x12E7C] = {1};
char lbl_7_data_13A3C[0xD] = {1};
static u8 fzgx_pool_data_gap2[0x13D9C - 0x13A4C] = {1};
char lbl_7_data_13A58__fzgx_offset_344[0x14] = {1};
char lbl_7_data_13A58__fzgx_offset_358[0x18] = {1};
char lbl_7_data_13A58__fzgx_offset_370[0x18] = {1};

u32 lbl_7_bss_0;
u32 lbl_7_bss_4[2];
u32 lbl_7_bss_C;
u8 *lbl_7_bss_10;
u8 *lbl_7_bss_14;
u32 lbl_7_bss_18;
u32 lbl_7_bss_1C__fzgx_offset_0[2];
u32 lbl_7_bss_1C__fzgx_offset_8;
u32 lbl_7_bss_1C__fzgx_offset_C;
u32 lbl_7_bss_1C__fzgx_offset_10;
u32 lbl_7_bss_1C__fzgx_offset_14;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_7_bss_0;
    s = *(u8 *)&lbl_7_bss_4;
    s = *(u8 *)&lbl_7_bss_C;
    s = *(u8 *)&lbl_7_bss_10;
    s = *(u8 *)&lbl_7_bss_14;
    s = *(u8 *)&lbl_7_bss_18;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_0;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_8;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_C;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_10;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_14;
}
#pragma section code_type ".text"

void fn_7_520(void) {
    u32 size;
    u8 i;
    char buf[56];
    const char * lab_t1;

    fn_7_4050();
    fn_1_4CC0();
    fn_8006CE1C(lbl_7_rodata_528);
    fn_1_A0680();
    fn_1_47F74(0xBA);
    fn_1_47F74(0x9A);
    fn_1_47F74(0x9B);
    fn_1_411A4(1);
    fn_1_411A4(6);
    fn_1_4706C();
    fn_1_46A60();
{
    u32 heap;
    heap = fn_1_4404();
    if ((*(struct fn_7_520_fn_7_520_flag *)&lbl_1_bss_9C).unk_3 != 1) {
        size = fn_800090A4(lbl_801A6410) - 0x10000;
        lbl_7_data_12E70__fzgx_offset_4 = fn_1_45D0(lbl_801A6410, size, lbl_7_data_13A3C, 0x25F);
        /* fzgx: reloaded */
        fn_1_46BA0(*(volatile u32 *)&lbl_7_data_12E70__fzgx_offset_4, size);
    }
    fn_1_47E54(0xBA);
    fn_1_47E54(0x9A);
    fn_1_47E54(0x9B);
    fn_1_41104(1);
    fn_1_41104(6);
    if (lbl_7_data_12E70__fzgx_offset_4 != 0xFFFFFFFF) {
        fn_1_46BFC();
        fn_1_46B44((u32)fn_7_4094, &lbl_7_data_12E70__fzgx_offset_4);
    }
    fn_80008E84(heap);
}
    sprintf(buf, lbl_7_data_13A58__fzgx_offset_344);
    fn_1_465D0(buf, 1);
    for (i = 1; i < 10; i++) {
        sprintf(buf, lbl_7_data_13A58__fzgx_offset_358, i);
        fn_1_465D0(buf, 1);
        lab_t1 = lbl_7_data_13A58__fzgx_offset_370;
        sprintf(buf, lab_t1, i);
        fn_1_465D0(buf, 1);
    }
    lbl_7_bss_1C__fzgx_offset_C = 0;
    lbl_7_bss_1C__fzgx_offset_10 = 10;
    lbl_7_bss_1C__fzgx_offset_14 = 1;
    lbl_7_data_12E78 = -1;
    lbl_7_bss_4[0] = 0;
    fn_1_4A00(1, 0x1E, lbl_7_bss_1C__fzgx_offset_0[0]);
    fn_1_A1588(*lbl_1_bss_6EAD0, 0x2E);
}
/* fzgx:end fn_7_520 */

/* fzgx:begin fn_7_72C noprologue */
#include "types.h"

struct fn_7_520_flag {
    u8 pad_0[3];
    s8 unk_3;
};

extern struct fn_7_520_flag lbl_1_bss_9C;
extern u32 lbl_801A6410;
extern void **lbl_1_bss_6EAD0;
extern const f32 lbl_7_rodata_528;

extern void fn_7_4050(void);
extern u32 fn_7_4094(void *, u32, u32, u32);
extern void fn_1_4CC0(void);
extern void fn_8006CE1C(f32);
extern void fn_1_A0680(void);
extern void fn_1_47F74(s32);
extern void fn_1_411A4(u32);
extern u32 fn_1_4706C(void);
extern u32 fn_1_46A60(void);
extern u32 fn_1_4404(void);
extern u32 fn_800090A4(u32);
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern u32 fn_1_46BA0(u32, u32);
extern void fn_1_47E54(s32);
extern void fn_1_41104(u32);
extern u32 fn_1_46BFC(void);
extern u32 fn_1_46B44(u32, void *);
extern u32 fn_80008E84(u32);
extern int sprintf(char *, const char *, ...);
extern s32 fn_1_465D0(char *, s32);
extern void fn_1_4A00(s32, u8, u32);
extern u32 fn_1_A1588(void *, u32);

u8 lbl_7_data_0[0x2A0] = {1};
static u8 fzgx_pool_data_gap0[0x12E74 - 0x2A0] = {1};
u32 lbl_7_data_12E70__fzgx_offset_4 = 1;
s32 lbl_7_data_12E78 = 1;
static u8 fzgx_pool_data_gap1[0x13A3C - 0x12E7C] = {1};
char lbl_7_data_13A3C[0xD] = {1};
static u8 fzgx_pool_data_gap2[0x13D9C - 0x13A4C] = {1};
char lbl_7_data_13A58__fzgx_offset_344[0x14] = {1};
char lbl_7_data_13A58__fzgx_offset_358[0x18] = {1};
char lbl_7_data_13A58__fzgx_offset_370[0x18] = {1};

u32 lbl_7_bss_0;
s32 lbl_7_bss_4[2];
s32 lbl_7_bss_C;
s8 *lbl_7_bss_10;
u8 *lbl_7_bss_14;
u32 lbl_7_bss_18;
u32 lbl_7_bss_1C__fzgx_offset_0[2];
u32 lbl_7_bss_1C__fzgx_offset_8;
s32 lbl_7_bss_1C__fzgx_offset_C;
s32 lbl_7_bss_1C__fzgx_offset_10;
s32 lbl_7_bss_1C__fzgx_offset_14;
s32 lbl_7_bss_1C__fzgx_offset_18[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_7_bss_0;
    s = *(u8 *)&lbl_7_bss_4;
    s = *(u8 *)&lbl_7_bss_C;
    s = *(u8 *)&lbl_7_bss_10;
    s = *(u8 *)&lbl_7_bss_14;
    s = *(u8 *)&lbl_7_bss_18;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_0;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_8;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_C;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_10;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_14;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_18;
}
#pragma section code_type ".text"


typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} Fn72CPad;
typedef struct {
    u8 pad_0[0x64];
    u16 unk_64;
} Fn72CSave;
extern Fn72CPad lbl_1_bss_9F8[];
extern Fn72CSave lbl_1_bss_7F0C0;
extern u32 lbl_1_bss_6EAB4;
extern u8 lbl_1_bss_8B3A0[];
extern s16 lbl_1_bss_968;
extern u16 lbl_1_bss_96A;
extern void fn_7_2538(void);
extern void fn_1_C2454(void);
extern s32 fn_1_C24A4(void);
extern u8 fn_1_B7C00(void);
extern int fn_1_4C10(void);
extern s32 fn_1_F9CA0(u8, u8);
extern s32 fn_1_F9E80(u8, u8);
extern void fn_1_A2D84(u32);

typedef struct { s8 col, row, port; } StoryCursor;
void fn_7_72C(void) {
    s32 delta;
    s32 v;

    delta = 0;
    fn_7_2538();
    if (lbl_1_bss_9C.unk_3 == 1) {
        fn_1_C2454();
        lbl_1_bss_9C.unk_3 = 2;
    }
    if (lbl_1_bss_9C.unk_3 == 2) {
        if (fn_1_C24A4() == 0 && fn_1_B7C00() == 0) {
            lbl_1_bss_9C.unk_3 = 0;
        } else {
            return;
        }
    }
    if (lbl_7_bss_1C__fzgx_offset_18[0] > 0) {
        lbl_7_bss_1C__fzgx_offset_18[0]--;
    }
    if (lbl_7_bss_1C__fzgx_offset_18[1] > 0) {
        lbl_7_bss_1C__fzgx_offset_18[1]--;
    }
    if (lbl_7_bss_1C__fzgx_offset_10 != 0) {
        lbl_7_bss_1C__fzgx_offset_C += lbl_7_bss_1C__fzgx_offset_10;
        if (lbl_7_bss_1C__fzgx_offset_C > 200) {
            lbl_7_bss_1C__fzgx_offset_C = 200;
            lbl_7_bss_1C__fzgx_offset_10 = 0;
        } else if (lbl_7_bss_1C__fzgx_offset_C < 0) {
            lbl_7_bss_1C__fzgx_offset_C = 0;
            if (lbl_7_data_12E78 != -1) {
                lbl_7_bss_1C__fzgx_offset_10 *= -1;
            } else {
                lbl_7_bss_1C__fzgx_offset_10 = 0;
            }
        } else {
            return;
        }
    }
    if (lbl_7_data_12E78 != -1) {
        lbl_7_bss_1C__fzgx_offset_14 = lbl_7_data_12E78;
        lbl_7_data_12E78 = -1;
    }
    if (fn_1_4C10() != 0) {
        return;
    }
    if (lbl_7_bss_4[0] == 1) {
        switch (lbl_7_bss_1C__fzgx_offset_14) {
        case 4:
            lbl_1_bss_968 = 1;
            break;
        case 3:
            lbl_1_bss_96A = 0x88;
            break;
        }
    } else if (lbl_7_bss_4[0] == 0) {
        switch (lbl_7_bss_1C__fzgx_offset_14) {
        case 1:
            if (((lbl_1_bss_9F8[(*(StoryCursor **)&lbl_7_bss_10)->port].unk_10 >> 1) & 1) || ((lbl_1_bss_9F8[(*(StoryCursor **)&lbl_7_bss_10)->port].unk_12 >> 1) & 1)) {
                lbl_7_bss_1C__fzgx_offset_18[1] = 15;
                delta = 1;
                lbl_7_bss_1C__fzgx_offset_18[0] = 0;
            } else if ((lbl_1_bss_9F8[lbl_7_bss_10[2]].unk_10 & 1) || (lbl_1_bss_9F8[lbl_7_bss_10[2]].unk_12 & 1)) {
                lbl_7_bss_1C__fzgx_offset_18[0] = 15;
                delta = -1;
                lbl_7_bss_1C__fzgx_offset_18[1] = 0;
            }
            v = lbl_7_bss_10[0] + delta;
            if (v < 0 || v > 9) {
                lbl_7_bss_1C__fzgx_offset_18[0] = 0;
                delta = 0;
                lbl_7_bss_1C__fzgx_offset_18[1] = 0;
            }
            if (!(lbl_1_bss_7F0C0.unk_64 & (0x8000 >> (lbl_7_bss_10[0] + delta)))) {
                lbl_7_bss_1C__fzgx_offset_18[0] = 0;
                delta = 0;
                lbl_7_bss_1C__fzgx_offset_18[1] = 0;
            }
            if (delta != 0) {
                fn_1_A2D84(0xA9010000);
            }
            lbl_7_bss_10[0] += delta;
            if (((lbl_1_bss_9F8[lbl_7_bss_10[2]].unk_8 >> 8) & 1) && fn_1_F9CA0(0, lbl_7_bss_10[0]) != 0) {
                if (lbl_7_bss_10[0] > 0 && fn_1_F9CA0(1, lbl_7_bss_10[0]) != 0) {
                    lbl_7_data_12E78 = 2;
                    lbl_7_bss_1C__fzgx_offset_10 = -10;
                    for (lbl_7_bss_10[1] = 0; lbl_7_bss_10[1] < 2 && fn_1_F9E80(lbl_7_bss_10[1], lbl_7_bss_10[0]) != 0; lbl_7_bss_10[1]++) {
                    }
                    fn_1_A2D84(0xA9010100);
                } else {
                    lbl_7_bss_10[1] = 0;
                    lbl_7_bss_1C__fzgx_offset_14 = 3;
                    lbl_7_bss_4[0] = 0x20;
                    lbl_7_bss_1C__fzgx_offset_10 = -10;
                    fn_1_4A00(0, 0x1E, lbl_7_bss_1C__fzgx_offset_0[0]);
                    fn_1_A2D84(0xA9010100);
                    lbl_1_bss_6EAB4 |= 0x24;
                }
            } else if ((lbl_1_bss_9F8[lbl_7_bss_10[2]].unk_8 >> 9) & 1) {
                *(u32 *)(lbl_1_bss_8B3A0 + 0x94) = 0;
                lbl_7_bss_4[0] = 0x20;
                fn_1_4A00(0, 0x1E, lbl_7_bss_1C__fzgx_offset_0[0]);
                lbl_7_data_12E78 = 4;
                fn_1_A2D84(0xA9010200);
                lbl_1_bss_6EAB4 |= 0x24;
            }
            break;
        case 2:
            if ((((lbl_1_bss_9F8[(*(StoryCursor **)&lbl_7_bss_10)->port].unk_10 >> 1) & 1) || ((lbl_1_bss_9F8[(*(StoryCursor **)&lbl_7_bss_10)->port].unk_12 >> 1) & 1))
                && lbl_7_bss_10[1] < 2 && fn_1_F9CA0(lbl_7_bss_10[1] + 1, lbl_7_bss_10[0]) != 0) {
                lbl_7_bss_10[1]++;
                lbl_7_bss_C = 0;
                fn_1_A2D84(0xA9010000);
            } else if (((lbl_1_bss_9F8[(*(StoryCursor **)&lbl_7_bss_10)->port].unk_10 & 1) || (lbl_1_bss_9F8[(*(StoryCursor **)&lbl_7_bss_10)->port].unk_12 & 1))
                && lbl_7_bss_10[1] > 0 && fn_1_F9CA0(lbl_7_bss_10[1] - 1, lbl_7_bss_10[0]) != 0) {
                lbl_7_bss_10[1]--;
                lbl_7_bss_C = 0;
                fn_1_A2D84(0xA9010000);
            }
            if ((lbl_1_bss_9F8[lbl_7_bss_10[2]].unk_8 >> 8) & 1) {
                lbl_7_bss_1C__fzgx_offset_14 = 3;
                lbl_7_bss_4[0] = 0x20;
                lbl_7_bss_1C__fzgx_offset_10 = -10;
                fn_1_4A00(0, 0x1E, lbl_7_bss_1C__fzgx_offset_0[0]);
                fn_1_A2D84(0xA9010100);
                lbl_7_bss_C = 0;
                lbl_1_bss_6EAB4 |= 0x24;
            } else if ((lbl_1_bss_9F8[(*(StoryCursor **)&lbl_7_bss_10)->port].unk_8 >> 9) & 1) {
                lbl_7_bss_1C__fzgx_offset_10 = -10;
                lbl_7_data_12E78 = 1;
                fn_1_A2D84(0xA9010200);
            }
            break;
        }
    }
}
/* fzgx:end fn_7_72C */

/* fzgx:begin fn_7_D20 */
struct fn_7_D20_lbl_7_bss_10 {
    u32 unk_0;
};
struct fn_7_D20_lbl_7_bss_14 {
    u32 unk_0;
};

extern int sprintf(char *, const char *, ...);
extern s32 fn_1_465D0(char *, s32);

extern u32 fn_1_47E54(u32);

extern void fn_7_4050(void);

void fn_7_D20(void) {
    u32 ptr;
    u32 index;
    s32 offset;
    struct { u32 a0, a1, a2, a3, a4, a5, a6, a7, a8, a9; } loc_8;

    fn_1_412A0(6);
    fn_1_412A0(1);
    fn_1_48140(100);
    fn_1_48140(155);
    fn_1_48140(154);
    fn_1_48140(186);

    ptr = (*(struct fn_7_D20_lbl_7_bss_10 *)&lbl_7_bss_10).unk_0;
    (*(struct fn_7_D20_lbl_7_bss_14 *)&lbl_7_bss_14).unk_0 = (u32)((u8 *)lbl_7_rodata_0 + (s8)*(u8 *)ptr * 132);
    fn_7_4050();
    sprintf((char *)&loc_8, (*(char (*)[23])&lbl_7_data_13DE0), *(s8 *)((u8 *)(*(struct fn_7_D20_lbl_7_bss_14 *)&lbl_7_bss_14).unk_0 + 1));
    fn_1_465D0((char *)&loc_8, 1);
    sprintf((char *)&loc_8, (*(char (*)[23])&lbl_7_data_13DF8), *(s8 *)((u8 *)(*(struct fn_7_D20_lbl_7_bss_14 *)&lbl_7_bss_14).unk_0 + 1));
    fn_1_465D0((char *)&loc_8, 1);

    offset = *(s8 *)((u8 *)(*(struct fn_7_D20_lbl_7_bss_14 *)&lbl_7_bss_14).unk_0 + 1) - 0x24;
    if (offset < 0) {
        index = 0;
    } else {
        index = 9;
        if (offset <= 9) {
            index = offset;
        }
    }
    fn_1_47E54((*(u32 (*)[10])&lbl_7_data_13A14)[index]);
    fn_1_A0AA4();
}
/* fzgx:end fn_7_D20 */

/* fzgx:begin fn_7_E50 */
extern u32 fn_1_4A00(u32, u32, u32);

struct fn_7_E50_lbl_7_bss_1C {
    u32 unk_0;
};

void fn_7_E50(void) {
    fn_1_4A00(1, 30, (*(struct fn_7_E50_lbl_7_bss_1C *)&lbl_7_bss_1C).unk_0);
}
/* fzgx:end fn_7_E50 */

/* fzgx:begin fn_7_E84 noprologue */
#include "types.h"

struct fn_7_E84_lbl_7_bss_14 {
    u32 unk_0;
};
struct fn_7_E84_lbl_1_bss_58 {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    f32 unk_C;
    f32 unk_10;
    u8 unk_14;
    u8 pad_15[0x1];
    u8 unk_16;
    s8 unk_17;
    s16 unk_18;
    u8 pad_1A[0x2];
    u32 unk_1C;
};
struct fn_7_E84_lbl_7_bss_10_T {
    s8 unk_0;
    u8 pad_1[0x7];
    u32 unk_8;
};

extern f32 lbl_7_rodata_52C;
extern struct fn_7_E84_lbl_1_bss_58 lbl_1_bss_58;
extern struct fn_7_E84_lbl_7_bss_10_T *lbl_7_bss_10;
extern struct fn_7_E84_lbl_7_bss_14 lbl_7_bss_14;
extern u16 lbl_1_bss_968;
extern u16 lbl_1_bss_96A;
extern u16 lbl_1_data_414;
extern u8 lbl_1_bss_198[];
extern u8 lbl_7_data_13E10[220];
extern u32 lbl_801A66B4;
extern u32 fn_80083DB0(void *, void *);

void fn_7_E84(void) {
    u32 v;
    f32 f0;

    v = *(u32 *)((u8 *)lbl_7_bss_14.unk_0 + 0x18);
    if (v != 0) {
        fn_80083DB0(lbl_1_bss_198, (void *)v);
        fn_80083DB0(lbl_1_bss_198 + 0x40, lbl_7_data_13E10);
        f0 = lbl_7_rodata_52C;
        lbl_1_bss_58.unk_0 = lbl_801A66B4;
        lbl_1_bss_58.unk_14 = 7;
        lbl_1_bss_58.unk_1 = 1;
        lbl_1_bss_58.unk_2 = 0;
        lbl_1_bss_58.unk_3 = 0;
        lbl_1_bss_58.unk_4 = 640;
        lbl_1_bss_58.unk_6 = 336;
        lbl_1_bss_58.unk_8 = 0;
        lbl_1_bss_58.unk_A = 0;
        lbl_1_bss_58.unk_C = f0;
        lbl_1_bss_58.unk_10 = f0;
        lbl_1_bss_58.unk_16 = 0;
        lbl_1_bss_58.unk_17 = -1;
        lbl_1_bss_58.unk_18 = -1;
        lbl_1_bss_58.unk_1C = 0;
        lbl_1_bss_58.unk_14 = 6;
        if ((lbl_1_data_414 & (0x8000 >> lbl_7_bss_10->unk_0)) != 0) {
            lbl_1_bss_58.unk_14 |= 1;
        }
        lbl_1_bss_968 = 8;
        lbl_7_bss_10->unk_8 = 137;
    } else {
        lbl_1_bss_96A = 144;
    }
}
/* fzgx:end fn_7_E84 */

/* fzgx:begin fn_7_FB0 */
// fn_7_FB0: empty in retail (single blr).
void fn_7_FB0(void) {
}
/* fzgx:end fn_7_FB0 */

/* fzgx:begin fn_7_FB4 */
extern void fn_7_4050(void);
extern u32 fn_1_47F74(u32);
extern s32 fn_1_465D0(void *, s32);
extern void fn_1_411A4(u32);
extern void fn_1_12F28C(void *, void *, u32, void *);
extern void fn_1_4A00(s32, u8, void *);
extern u32 fn_1_47E54(u32);
extern void fn_80006E10(u32);
extern u32 fn_1_7FD7C(void *);
extern u8 *fn_1_12D254(s32, s32);
extern u32 fn_1_A0680(void);
extern void fn_1_A1588(void *, u32);


extern u8 lbl_1_bss_8B5F0;
extern u8 lbl_1_bss_8B5F1;

struct fn_7_FB4_state {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x8];
    u32 unk_10;
    s8 *unk_14;
    u8 pad_18[0x4];
    u32 unk_1c;
    u8 pad_20[0x8];
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    u8 pad_34[0x8];
    u32 unk_3c;
    u32 unk_40;
    u8 unk_44[1];
};

struct fn_7_FB4_arg {
    u8 pad_0[2];
    s16 unk_2;
    u32 unk_4;
    u8 unk_8;
    u8 pad_9[0x17];
};

#pragma opt_propagation off
void fn_7_FB4(void) {
    struct fn_7_FB4_state *state;
    struct fn_7_FB4_arg arg;
    s32 offset;
    s32 index;
    u8 *base;
    u32 *tbl;
    void *res;

    base = (*(u8 (*)[])&lbl_7_data_0) + 0x10000;
    state = (struct fn_7_FB4_state *)&lbl_7_bss_0;
    state->unk_4 = 0;
    state->unk_28 = 0;
    state->unk_2c = 10;
    state->unk_3c = 0;
    state->unk_40 = 0;
    state->unk_30 = 0;
    fn_7_4050();
    fn_1_47F74(0xba);
    fn_1_47F74(0x9a);
    fn_1_47F74(0x9b);
    offset = state->unk_14[1] - 0x24;
    index = offset < 0 ? 0 : (offset > 9 ? 9 : offset);
    offset = index * 4;
    tbl = (u32 *)(base + 0x3A14);
    fn_1_47F74(*(u32 *)((u8 *)tbl + offset));
    res = base + 0x3E14;
    fn_1_465D0(res, 1);
    fn_1_411A4(1);
    fn_1_12F28C((void *)state->unk_1c, state->unk_44, 7, state->unk_14 + 1);
    fn_1_4A00(1, 0x1e, (void *)state->unk_1c);
    arg.unk_2 = *(s16 *)(state->unk_10 + 4);
    arg.unk_4 = 2;
    arg.unk_8 = 0x10;
    fn_1_47E54(0x30);
    fn_80006E10((u32)(base + 0x3E30));
    res = base + 0x3E38;
    fn_1_465D0(res, 1);
    fn_1_7FD7C(&arg);
    fn_80006E10((u32)(base + 0x3E48));
    res = fn_1_12D254(arg.unk_2, arg.unk_4);
    fn_1_465D0(res, 1);
    fn_1_A0680();
    fn_1_A1588(*(void **)lbl_1_bss_6EAD0, 0x2e);
    lbl_1_bss_8B5F0 = 0;
    lbl_1_bss_8B5F1 = 0;
}
#pragma opt_propagation reset
/* fzgx:end fn_7_FB4 */

/* fzgx:begin fn_7_1134 noprologue */
#include "types.h"

struct fn_7_1134_state {
    u8 pad_0[0x4];
    s32 unk_4;
    u8 pad_8[0x8];
    s8 *unk_10;
    u8 pad_14[0x8];
    u32 unk_1C;
    u8 pad_20[0x8];
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u8 pad_34[0x8];
    s32 unk_3C;
    s32 unk_40;
};

struct fn_7_1134_entry {
    u8 pad_0[0x8];
    u16 flags;
    u8 pad_A[0xA];
};

extern u32 lbl_7_bss_0[];
extern u16 lbl_1_bss_96A;
extern struct fn_7_1134_entry lbl_1_bss_9F8[];

extern u32 fn_7_33F0(void);
extern int fn_1_4C10(void);
extern u32 fn_1_4A00(u32, u32, u32);
extern void fn_1_A2D84(u32);

void fn_7_1134(void) {
    struct fn_7_1134_state *p;
    s32 sum;
    u32 val;

    p = (struct fn_7_1134_state *)&lbl_7_bss_0;
    fn_7_33F0();

    if (p->unk_2C != 0) {
        sum = p->unk_28 + p->unk_2C;
        p->unk_28 = sum;
        if (sum > 200) {
            p->unk_28 = 200;
            p->unk_2C = 0;
            p->unk_3C = 360;
            p->unk_40 = -4;
        } else if (sum < 0) {
            p->unk_28 = 0;
            p->unk_2C = 0;
        } else {
            return;
        }
    }

    if (p->unk_40 != 0) {
        sum = p->unk_3C + p->unk_40;
        p->unk_3C = sum;
        if (sum < -101) {
            p->unk_3C = -101;
            p->unk_40 = 0;
        }
    }

    if (fn_1_4C10() != 0) {
        return;
    }

    if (p->unk_4 == 1) {
        val = 0x8a;
        if (4 == p->unk_30) {
            val = 0x87;
        }
        lbl_1_bss_96A = val;
        return;
    } else if (p->unk_4 == 0) {
        if (p->unk_3C == -101) {
            if ((lbl_1_bss_9F8[(*((p->unk_10) + (2)))].flags >> 8) & 1) {
                p->unk_4 = 0x20;
                p->unk_2C = -10;
                p->unk_30 = 3;
                fn_1_4A00(0, 0x1e, p->unk_1C);
                fn_1_A2D84(0xa9010100);
                return;
            }
        }
        if ((lbl_1_bss_9F8[(*((p->unk_10) + (2)))].flags >> 9) & 1) {
            p->unk_4 = 0x20;
            p->unk_2C = -10;
            p->unk_30 = 4;
            fn_1_4A00(0, 0x1e, p->unk_1C);
            fn_1_A2D84(0xa9010200);
        }
    }
}
/* fzgx:end fn_7_1134 */

/* fzgx:begin fn_7_12FC */
extern void fn_7_4050(void);

struct fn_7_12FC_state {
    u8 pad_0[0x14];
    s8 *unk_14;
    u8 pad_18[0x4];
    u32 unk_1c;
    u8 pad_20[0x24];
    u8 unk_44[1];
};

void fn_7_12FC(void) {
    struct fn_7_12FC_state *state;
    u32 index;
    s32 offset;

    state = (struct fn_7_12FC_state *)&lbl_7_bss_0;
    fn_7_4050();
    fn_1_12F30C(state->unk_1c, &state->unk_44);
    fn_1_412A0(1);
    offset = state->unk_14[1] - 0x24;
    if (offset < 0) {
        index = 0;
    } else {
        index = 9;
        if (offset <= 9) {
            index = offset;
        }
    }
    fn_1_48140((*(u32 (*)[10])&lbl_7_data_13A14)[index]);
    fn_1_48140(0x9b);
    fn_1_48140(0x9a);
    fn_1_48140(0xba);
}
/* fzgx:end fn_7_12FC */

/* fzgx:begin fn_7_1398 */
extern u32 fn_7_4050(void);
extern u32 lbl_7_bss_4;

void fn_7_1398(void) {
    fn_7_4050();
    fn_1_12F10C(0);
    lbl_7_bss_4 = 0;
}
/* fzgx:end fn_7_1398 */

/* fzgx:begin fn_7_13CC */
struct fn_7_13CC_lbl_1_bss_8B3A0 {
    u8 pad_0[0x94];
    u32 unk_94;
};
struct fn_7_13CC_lbl_7_bss_10_T {
    u8 pad_0[0x8];
    u32 unk_8;
};

void fn_7_13CC(void) {
    (*(struct fn_7_13CC_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0).unk_94 = 0x2000000;
    (*(struct fn_7_13CC_lbl_7_bss_10_T * *)&lbl_7_bss_10)->unk_8 = 139;
    (*(u16 *)&lbl_1_bss_968) = 1;
}
/* fzgx:end fn_7_13CC */

/* fzgx:begin fn_7_13FC */
// fn_7_13FC: empty in retail (single blr).
void fn_7_13FC(void) {
}
/* fzgx:end fn_7_13FC */

/* fzgx:begin fn_7_1400 noprologue */
#include "types.h"

extern s16 lbl_1_bss_96A;
extern u16 lbl_1_data_414;
extern f32 lbl_7_rodata_0[330];

struct Sig_fn_7_2114_fn_7_2114_Arg0 {
    u32 unk_0;
    u8 pad_4[0xA8];
    u32 unk_AC;
    u8 pad_B0[0x18];
    u32 unk_C8;
};

struct fn_7_1400_sub {
    u8 pad_0[0x248];
    u16 unk_248;
};

struct fn_7_1400_lbl_7_bss_0 {
    u8 pad_0[0x10];
    u8 *unk_10;
    u8 *unk_14;
    u8 pad_18[0xC];
    u32 unk_24;
    u8 pad_28[0x20];
    struct fn_7_1400_sub sub;
};

extern struct Sig_fn_7_2114_fn_7_2114_Arg0 * fn_7_2114(struct Sig_fn_7_2114_fn_7_2114_Arg0 *);






extern u32 fn_1_47F74(u32);
extern u32 fn_7_4108(void *, u32, u32);
extern u32 fn_7_41FC(void *);
extern void fn_1_F1B78(u32);
extern void fn_1_3EF8C(u8);
extern void fn_1_3EFF0(u32, u8);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_7_bss_0;
u32 lbl_7_bss_4[2];
u32 lbl_7_bss_C;
u8 *lbl_7_bss_10;
u8 *lbl_7_bss_14;
u32 lbl_7_bss_18;
u32 lbl_7_bss_1C__fzgx_offset_0[2];
u32 lbl_7_bss_1C__fzgx_offset_8;
u32 lbl_7_bss_1C__fzgx_offset_C[8];
struct fn_7_1400_sub lbl_7_bss_48;
u16 lbl_7_bss_48__fzgx_offset_24A;
u32 lbl_7_bss_48__fzgx_offset_24C[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_7_bss_0;
    s = *(u8 *)&lbl_7_bss_4;
    s = *(u8 *)&lbl_7_bss_C;
    s = *(u8 *)&lbl_7_bss_10;
    s = *(u8 *)&lbl_7_bss_14;
    s = *(u8 *)&lbl_7_bss_18;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_0;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_8;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_C;
    s = *(u8 *)&lbl_7_bss_48;
    s = *(u8 *)&lbl_7_bss_48__fzgx_offset_24A;
    s = *(u8 *)&lbl_7_bss_48__fzgx_offset_24C;
}
#pragma section code_type ".text"

void fn_7_1400(void) {
    s8 v0;
    u8 *v1;
    s32 v2;
    s32 v4;

    
    fn_1_47F74(186);
    if (lbl_7_bss_14[0] == 9) {
        v0 = (s8)lbl_7_bss_10[1];
        switch (v0) {
        case 0:
        default:
            fn_1_F1B78(0);
            break;
        case 1:
            fn_1_F1B78(1);
            break;
        case 2:
            fn_1_F1B78(2);
            break;
        }
    } else {
        fn_1_F1B78(-1);
    }
    v1 = lbl_7_bss_10;
    v2 = (0x10000 + -32768);
    v4 = ((s8)v1[0] * 132);
    lbl_7_bss_14 = (u8 *)&lbl_7_rodata_0 + v4;
    lbl_1_data_414 = (lbl_1_data_414 | (v2 >> (s8)v1[0]));
    fn_1_3EF8C(5);
    fn_1_3EFF0((u32)fn_7_2114, 1);
    lbl_7_bss_1C__fzgx_offset_8 = 0;
    lbl_7_bss_48.unk_248 = (s8)lbl_7_bss_10[1];
    fn_7_4108(&lbl_7_bss_48, *(u32 *)(lbl_7_bss_14 + 0x20), 0);
    fn_7_41FC((u8 *)&lbl_7_bss_48);
    (*(u16 *)&lbl_1_bss_96A) = 140;
}
/* fzgx:end fn_7_1400 */

/* fzgx:begin fn_7_1538 */
// fn_7_1538: empty in retail (single blr).
void fn_7_1538(void) {
}
/* fzgx:end fn_7_1538 */

/* fzgx:begin fn_7_153C */
// fn_7_153C: empty in retail (single blr).
void fn_7_153C(void) {
}
/* fzgx:end fn_7_153C */

/* fzgx:begin fn_7_1540 */
// fn_7_1540: empty in retail (single blr).
void fn_7_1540(void) {
}
/* fzgx:end fn_7_1540 */

/* fzgx:begin fn_7_1544 */
extern u32 fn_1_3F0C8(void);

void fn_7_1544(void) {
    u32 v0;
    s16 v1;
    u32 t0, t1;
    t0 = fn_1_3F038();
    v0 = t0;
    if ((s32)t0 != 0) {
    t1 = fn_1_3F0C8();
    v0 = t1;
    v1 = (s16)v0;
    switch (v1) {
    case 42:
    (*(u16 *)&lbl_1_bss_96A) = 141;
    break;
    case 43:
    (*(u16 *)&lbl_1_bss_96A) = 149;
    break;
    default:
    (*(u16 *)&lbl_1_bss_96A) = 135;
    }
    }
}
/* fzgx:end fn_7_1544 */

/* fzgx:begin fn_7_15B8 */
// fn_7_15B8: empty in retail (single blr).
void fn_7_15B8(void) {
}
/* fzgx:end fn_7_15B8 */

/* fzgx:begin fn_7_15BC noprologue */
#include "types.h"

#include "rel/story/story_mode.h"

typedef struct StoryTime {
    u8 min;
    u8 sec;
    u16 ms;
} StoryTime;

typedef struct StoryRecords {
    u8 pad_0[0x6c];
    StoryTime times[8][12];
} StoryRecords;

typedef struct StoryClock {
    u8 pad_0[0x1e0];
    u8 min;
    u8 sec;
    u16 ms;
} StoryClock;

extern s32 fn_1_8623C(void);
extern StoryClock *fn_1_3F0D8(u8, u8 *, f32 *);
extern StoryRecords lbl_1_bss_7F0C0;
extern u8 lbl_1_bss_9C[];

void fn_7_15BC(void) {
    f32 scale;
    u8 name[12];
    StoryClock *clock;
    s32 course;

    clock = fn_1_3F0D8(fn_1_8623C(), name, &scale);
    course = (s8)lbl_7_bss_10->unk_0;
#define REC lbl_1_bss_7F0C0.times[(s8)lbl_7_bss_10->unk_1][course]
    if (REC.min || REC.sec || REC.ms) {
        if (clock->sec * 1000 + clock->min * 60000 + clock->ms >=
            REC.sec * 1000 + REC.min * 60000 + REC.ms) {
            return;
        }
    }
    REC.min = clock->min;
    REC.sec = clock->sec;
    REC.ms = clock->ms;
#undef REC
    lbl_1_bss_9C[3] = 1;
}
/* fzgx:end fn_7_15BC */

/* fzgx:begin fn_7_16FC */
void fn_7_16FC(void) {
    (*(u16 *)&lbl_1_bss_96A) = 144;
}
/* fzgx:end fn_7_16FC */

/* fzgx:begin fn_7_170C */
// fn_7_170C: empty in retail (single blr).
void fn_7_170C(void) {
}
/* fzgx:end fn_7_170C */

/* fzgx:begin fn_7_1710 noprologue */
#include "types.h"

typedef struct {
    s8 a;
    s8 b;
} StoryPos;

struct fn_7_1710_bss_0 {
    u8 pad_0[0x10];
    StoryPos *pos;
    u8 pad_14[0x4];
    void *unk_18;
    void *unk_1C;
};

struct fn_7_1710_bss_5138 {
    u16 unk_0;
    u8 count2;
    u8 count3;
    u8 list[4];
    u16 arr[4];
    u16 unk_10;
    u16 unk_12;
    u8 pad_14[0xD1];
    u8 unk_E5;
};

struct fn_7_1710_bss_9C {
    u8 pad_0[3];
    u8 unk_3;
};

extern struct fn_7_1710_bss_0 lbl_7_bss_0;
extern struct fn_7_1710_bss_5138 lbl_1_bss_5138;
extern struct fn_7_1710_bss_9C lbl_1_bss_9C;
extern u16 lbl_1_bss_96A;

extern void fn_1_4CC0(void);
extern void fn_8006CE1C(f32);
extern u32 fn_1_F9CA0(u32, u32);
extern void fn_1_F9CD0(u8, u8);
extern u32 fn_1_F9E80(u32, u32);
extern u32 fn_1_F9EB0(u32, u32);
extern s32 fn_1_F7EDC(s16);
extern int fn_1_F8334(s16);
extern void fn_1_3FDA8(void *, void *);

/* Layout primer: the story TU's .rodata ahead of this function (0x528 bytes of tables,
 * then the 0.0f / 1.0f literals), so the initializers below land at retail's offsets. */
#define FZGX_Z8 0, 0, 0, 0, 0, 0, 0, 0
#define FZGX_Z32 FZGX_Z8, FZGX_Z8, FZGX_Z8, FZGX_Z8
static const u32 fzgx_pool_table_0[330] = {
    FZGX_Z32, 0, 0x01250000,
    FZGX_Z32, 0x02260000,
    FZGX_Z32, 0x03270000,
    FZGX_Z32, 0x04280000,
    FZGX_Z32, 0x05290000,
    FZGX_Z32, 0x062A0000,
    FZGX_Z32, 0x072B0000,
    FZGX_Z32, 0x082C0000,
    FZGX_Z32, 0x092D0000,
    FZGX_Z32,
};

#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer(void) {
    fn_1_4CC0();
    fn_1_3FDA8((void *)fzgx_pool_table_0, (void *)fzgx_pool_table_0);
    fn_8006CE1C(0.0f);
    fn_8006CE1C(1.0f);
}
#pragma section code_type ".text"

void fn_7_1710(void) {
    struct fn_7_1710_bss_0 *g = (struct fn_7_1710_bss_0 *)&lbl_7_bss_0;
    s16 tblA[9][3] = {
        { 15, 25, 35 }, { 15, 25, 35 }, { 15, 25, 35 },
        { 20, 25, 35 }, { 20, 25, 35 }, { 25, 30, 40 },
        { 25, 30, 40 }, { 30, 35, 45 }, { 30, 35, 45 },
    };
    s16 tblB[9][3] = {
        { 31, 16, 71 }, { 29, 10, 72 }, { 30, 3, 66 },
        { 35, 2, 59 }, { 42, 7, 55 }, { 33, 21, 63 },
        { 27, 5, 51 }, { 40, 15, 68 }, { 43, 4, 56 },
    };
    s16 tblC[9] = { 40, 36, 39, 31, 32, 35, 33, 37, 38 };

    struct fn_7_1710_bss_5138 *st;
    s16 i;
    s32 ok;
    int done;
    StoryPos *pos;

    fn_1_4CC0();
    fn_8006CE1C(0.0f);
    pos = g->pos;
    if (pos->a == 0) {
        if ((s32)fn_1_F9CA0(0, 1) == 0) {
            lbl_1_bss_9C.unk_3 = 1;
        }
        fn_1_F9CD0(0, 1);
        lbl_1_bss_96A = 0x92;
        return;
    }
    done = fn_1_F9E80((u8)pos->b, (u8)pos->a) == 0;
    lbl_1_bss_5138.unk_10 = 320;
    lbl_1_bss_5138.unk_12 = 200;
    st = &lbl_1_bss_5138;
    if (!done) {
        return;
    }
    st->count3 = 0;
    st->count2 = 0;
    st->unk_0 += tblA[g->pos->a - 1][g->pos->b];
    fn_1_F9EB0((u8)g->pos->b, (u8)g->pos->a);
    if (g->pos->b < 2) {
        fn_1_F9CD0(g->pos->b + 1, g->pos->a);
    }
    switch (g->pos->b) {
    case 0:
        if (g->pos->a < 9) {
            lbl_1_bss_5138.unk_E5 = g->pos->a + 1;
        } else if (g->pos->a == 9 && fn_1_F7EDC(30) == 0) {
            lbl_1_bss_5138.list[st->count3] = 30;
            st->count3++;
        }
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            if (fn_1_F8334(tblB[g->pos->a - 1][i]) == 0) {
                lbl_1_bss_5138.arr[st->count2] = tblB[g->pos->a - 1][i];
                st->count2++;
            }
        }
        if (st->count2 == 0) {
            lbl_1_bss_5138.unk_0 += 10;
        }
        ok = 1;
        for (i = 1; i < 10; i++) {
            if ((s32)fn_1_F9E80(1, (u8)i) == 0) {
                ok = 0;
            }
        }
        if ((u8)ok) {
            lbl_1_bss_5138.list[st->count3] = 34;
            st->count3++;
        }
        break;
    case 2:
        if (fn_1_F7EDC(tblC[g->pos->a - 1]) == 0) {
            lbl_1_bss_5138.list[st->count3] = tblC[g->pos->a - 1];
            st->count3++;
        } else {
            lbl_1_bss_5138.unk_0 += 20;
        }
        break;
    }
    fn_1_3FDA8(g->unk_18, g->unk_1C);
    lbl_1_bss_9C.unk_3 = 1;
}
/* fzgx:end fn_7_1710 */

/* fzgx:begin fn_7_1BA8 */
struct StoryState_1BA8 {
    u8 pad_00[0xe0];
    u8 value_e0;
    u8 pad_e1[1];
    u8 flag_e2;
};

struct StoryFlags_1BA8 {
    u8 pad_00[8];
    u16 flags;
};







void fn_7_1BA8(void) {
    u16 flags = (*(struct StoryFlags_1BA8 *)&lbl_1_bss_9F8).flags;
    s32 bit = (flags >> 8) & 1;
    struct StoryState_1BA8 *state = &(*(struct StoryState_1BA8 *)&lbl_1_bss_5138);
    if (state->flag_e2 != 0) {
        if (bit != 0) {
            if (state->value_e0 >= 15 && state->value_e0 <= 120) {
                state->value_e0 = 120;
            }
        }
    }

    if (state->flag_e2 == 0) {
        (*(u16 *)&lbl_1_bss_96A) = 146;
    }
}
/* fzgx:end fn_7_1BA8 */

/* fzgx:begin fn_7_1C0C */
void fn_7_1C0C(void) {
    fn_1_48140(186);
}
/* fzgx:end fn_7_1C0C */

/* fzgx:begin fn_7_1C30 */
struct S58 {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    f32 unk_C;
    f32 unk_10;
    u8 unk_14;
    u8 pad_15;
    u8 unk_16;
    s8 unk_17;
    s16 unk_18;
    u8 pad_1A[2];
    u32 unk_1C;
};

extern f32 lbl_7_rodata_52C;










extern u32 fn_80083DB0(u32, u32);
extern u8 lbl_1_bss_198[];







void fn_7_1C30(void) {
    if ((s8)*(u8 *)(*(u32 *)&(*(u32 *)&lbl_7_bss_10)) == 9) {
        (*(u16 *)&lbl_1_bss_96A) = 147;
    } else {
        u32 off = *(u32 *)(*(u32 *)&(*(u32 *)&lbl_7_bss_14) + 0x1C);
        if (off != 0) {
            u32 p;
            s8 v3;
            fn_80083DB0((u32)&lbl_1_bss_198[0], off);
            fn_80083DB0((u32)&lbl_1_bss_198[0x40], (u32)&(*(u8 (*)[])&lbl_7_data_13E10)[0]);
            p = (*(u32 *)&lbl_7_bss_10);
            if ((s8)*(u8 *)p == 0 && lbl_1_bss_9C[3] == 1) {
                *(u32 *)(p + 8) = 134;
            } else {
                *(u32 *)(p + 8) = 135;
            }
            v3 = lbl_1_bss_9C[3];
            (*(struct S58 *)&lbl_1_bss_58).unk_0 = (*(u32 *)&lbl_801A66B4);
            (*(struct S58 *)&lbl_1_bss_58).unk_14 = 7;
            (*(struct S58 *)&lbl_1_bss_58).unk_1 = 1;
            (*(struct S58 *)&lbl_1_bss_58).unk_2 = 0;
            (*(struct S58 *)&lbl_1_bss_58).unk_3 = 0;
            (*(struct S58 *)&lbl_1_bss_58).unk_4 = 640;
            (*(struct S58 *)&lbl_1_bss_58).unk_6 = 336;
            (*(struct S58 *)&lbl_1_bss_58).unk_8 = 0;
            (*(struct S58 *)&lbl_1_bss_58).unk_A = 0;
            (*(struct S58 *)&lbl_1_bss_58).unk_C = lbl_7_rodata_52C;
            (*(struct S58 *)&lbl_1_bss_58).unk_10 = lbl_7_rodata_52C;
            (*(struct S58 *)&lbl_1_bss_58).unk_16 = 0;
            (*(struct S58 *)&lbl_1_bss_58).unk_17 = -1;
            (*(struct S58 *)&lbl_1_bss_58).unk_18 = -1;
            (*(struct S58 *)&lbl_1_bss_58).unk_1C = 0;
            (*(struct S58 *)&lbl_1_bss_58).unk_14 = 4;
            if (v3 != 1 || *(s8 *)((u8 *)(*(u32 *)&(*(u32 *)&lbl_7_bss_10)) + 1) > 0) {
                (*(struct S58 *)&lbl_1_bss_58).unk_14 |= 1;
            }
            (*(u16 *)&lbl_1_bss_968) = 8;
        } else {
            (*(u16 *)&lbl_1_bss_96A) = 135;
        }
    }
}
/* fzgx:end fn_7_1C30 */

/* fzgx:begin fn_7_1DB4 */
// fn_7_1DB4: empty in retail (single blr).
void fn_7_1DB4(void) {
}
/* fzgx:end fn_7_1DB4 */

/* fzgx:begin fn_7_1DB8 */
// fn_7_1DB8: empty in retail (single blr).
void fn_7_1DB8(void) {
}
/* fzgx:end fn_7_1DB8 */

/* fzgx:begin fn_7_1DBC */
extern f32 lbl_7_rodata_52C;
extern u8 lbl_1_bss_198[];
extern u32 fn_80083DB0(void *, const void *);
struct fn_7_1DBC_lbl_1_bss_58 {
    s8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    f32 unk_C;
    f32 unk_10;
    u8 unk_14;
    u8 pad_15[0x1];
    u8 unk_16;
    s8 unk_17;
    s16 unk_18;
    u8 pad_1A[0x2];
    u32 unk_1C;
};
struct fn_7_1DBC_lbl_7_bss_10_T {
    s8 unk_0;
    s8 unk_1;
    u8 pad_2[0x6];
    u32 unk_8;
};

void fn_7_1DBC(void) {
    struct { const u8 *value; } strs;  // retail addresses the TU's strings off one base (+0x10000)
    f32 half;
    f32 one;

    strs.value = (*(u8 (*)[])&lbl_7_data_0) + 0x10000;
    fn_80083DB0(lbl_1_bss_198 + 0x000, strs.value + 0x3e4c);
    fn_80083DB0(lbl_1_bss_198 + 0x040, strs.value + 0x3e54);
    fn_80083DB0(lbl_1_bss_198 + 0x080, strs.value + 0x395c);
    fn_80083DB0(lbl_1_bss_198 + 0x0c0, strs.value + 0x3e5c);
    fn_80083DB0(lbl_1_bss_198 + 0x100, strs.value + 0x3e64);
    fn_80083DB0(lbl_1_bss_198 + 0x140, strs.value + 0x3e6c);
    fn_80083DB0(lbl_1_bss_198 + 0x180, strs.value + 0x3e78);
    fn_80083DB0(lbl_1_bss_198 + 0x1c0, strs.value + 0x2fa0);
    fn_80083DB0(lbl_1_bss_198 + 0x200, strs.value + 0x3e80);
    fn_80083DB0(lbl_1_bss_198 + 0x240, strs.value + 0x3144);
    fn_80083DB0(lbl_1_bss_198 + 0x280, strs.value + 0x3e78);
    fn_80083DB0(lbl_1_bss_198 + 0x2c0, strs.value + 0x3240);
    fn_80083DB0(lbl_1_bss_198 + 0x300, strs.value + 0x3e88);
    fn_80083DB0(lbl_1_bss_198 + 0x340, strs.value + 0x3324);
    fn_80083DB0(lbl_1_bss_198 + 0x380, strs.value + 0x3e90);
    fn_80083DB0(lbl_1_bss_198 + 0x3c0, strs.value + 0x342c);
    fn_80083DB0(lbl_1_bss_198 + 0x400, strs.value + 0x3e98);
    fn_80083DB0(lbl_1_bss_198 + 0x440, strs.value + 0x35bc);
    fn_80083DB0(lbl_1_bss_198 + 0x480, strs.value + 0x3ea0);
    fn_80083DB0(lbl_1_bss_198 + 0x4c0, strs.value + 0x376c);
    fn_80083DB0(lbl_1_bss_198 + 0x500, strs.value + 0x3ea8);
    fn_80083DB0(lbl_1_bss_198 + 0x540, strs.value + 0x3844);
    fn_80083DB0(lbl_1_bss_198 + 0x580, strs.value + 0x3eb0);
    fn_80083DB0(lbl_1_bss_198 + 0x5c0, strs.value + 0x3ec0);
    fn_80083DB0(lbl_1_bss_198 + 0x600, strs.value + 0x3e10);

    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_0 = (*(u32 *)&lbl_801A66B4);
    one = lbl_7_rodata_52C;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_1 = 1;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_2 = 0;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_3 = 0;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_4 = 640;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_6 = 336;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_8 = 0;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_A = 0;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_C = one;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_10 = one;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_14 = 7;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_16 = 0;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_17 = -1;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_18 = -1;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_1C = 0;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_C = 0.5f;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_10 = 0.5f;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_8 = 136;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_A = 0;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_0 = -1;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_1 = 0;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_3 = 2;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_18 = 0;
    (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_14 = 4;
    if ((lbl_1_bss_9C[3]) != 1 || (*(struct fn_7_1DBC_lbl_7_bss_10_T * *)&lbl_7_bss_10)->unk_1 > 0) {
        (*(struct fn_7_1DBC_lbl_1_bss_58 *)&lbl_1_bss_58).unk_14 |= 1;
    }
    (*(u16 *)&lbl_1_bss_968) = 8;
    (*(struct fn_7_1DBC_lbl_7_bss_10_T * *)&lbl_7_bss_10)->unk_8 = 135;
}
/* fzgx:end fn_7_1DBC */

/* fzgx:begin fn_7_20DC */
// fn_7_20DC: empty in retail (single blr).
void fn_7_20DC(void) {
}
/* fzgx:end fn_7_20DC */

/* fzgx:begin fn_7_20E0 */
// fn_7_20E0: empty in retail (single blr).
void fn_7_20E0(void) {
}
/* fzgx:end fn_7_20E0 */

/* fzgx:begin fn_7_20E4 */
void fn_7_20E4(void) {
    (*(u16 *)&lbl_1_bss_96A) = 135;
}
/* fzgx:end fn_7_20E4 */

/* fzgx:begin fn_7_20F4 */
// fn_7_20F4: empty in retail (single blr).
void fn_7_20F4(void) {
}
/* fzgx:end fn_7_20F4 */

/* fzgx:begin fn_7_20F8 */
// fn_7_20F8: empty in retail (single blr).
void fn_7_20F8(void) {
}
/* fzgx:end fn_7_20F8 */

/* fzgx:begin fn_7_20FC */
// fn_7_20FC: empty in retail (single blr).
void fn_7_20FC(void) {
}
/* fzgx:end fn_7_20FC */

/* fzgx:begin fn_7_2100 */
void fn_7_2100(void) {
    (*(u16 *)&lbl_1_bss_96A) = 135;
}
/* fzgx:end fn_7_2100 */

/* fzgx:begin fn_7_2110 */
// fn_7_2110: empty in retail (single blr).
void fn_7_2110(void) {
}
/* fzgx:end fn_7_2110 */

/* fzgx:begin fn_7_2114 */
struct fn_7_2114_Arg0 {
    u32 unk_0;
    u8 pad_4[0xA8];
    u32 unk_AC;
    u8 pad_B0[0x18];
    u32 unk_C8;
};
struct fn_7_2114_lbl_7_bss_0 {
    u8 pad_0[0x20];
    u32 unk_20;
    u8 pad_24[0x274];
    u32 unk_298;
    u32 unk_29C;
};

extern void fn_7_21C8(void);

u32 fn_7_2114(struct fn_7_2114_Arg0 *arg0) {
    struct fn_7_2114_lbl_7_bss_0 *p_lbl_7_bss_0;
    p_lbl_7_bss_0 = (struct fn_7_2114_lbl_7_bss_0 *)&(*(struct fn_7_2114_lbl_7_bss_0 *)&lbl_7_bss_0);
    p_lbl_7_bss_0->unk_298 = 0;
    p_lbl_7_bss_0->unk_29C = 0;
    arg0->unk_AC = (u32)fn_7_21C8;
    arg0->unk_C8 = (u32)fn_7_2170;
    arg0->unk_0 = (arg0->unk_0 | 0x100000);
    if ((s32)p_lbl_7_bss_0->unk_20 != 0) {
    p_lbl_7_bss_0->unk_20 = 0;
    return (u32)arg0;
    }
    arg0->unk_0 = (arg0->unk_0 | 512);
}
/* fzgx:end fn_7_2114 */

/* fzgx:begin fn_7_2170 */
extern u32 fn_7_4108(void *, u32, u32);
extern u32 fn_7_41FC(void *);

struct fn_7_2170_lbl_7_bss_14 {
    u32 unk_0;
};

s32 fn_7_2170(u32 arg0) {
    if (*(u32 *)((u8 *)(*(struct fn_7_2170_lbl_7_bss_14 *)&lbl_7_bss_14).unk_0 + 36) != 0) {
    fn_7_4108(&(*(u32 *)&lbl_7_bss_48), *(u32 *)((u8 *)(*(struct fn_7_2170_lbl_7_bss_14 *)&lbl_7_bss_14).unk_0 + 36), arg0);
    fn_7_41FC(&(*(u32 *)&lbl_7_bss_48));
    }
    return 0;
}
/* fzgx:end fn_7_2170 */

/* fzgx:begin fn_7_21C8 noprologue */
#include "types.h"

struct fn_7_21C8_Arg0 {
    u32 unk_0;
    u8 pad_4[0xA4];
    u32 unk_A8;
    u32 unk_AC;
    u32 unk_B0;
    u32 unk_B4;
    u32 unk_B8;
    u32 unk_BC;
    u32 unk_C0;
    u32 unk_C4;
    u32 unk_C8;
    u32 unk_CC;
};

struct fn_7_21C8_lbl_7_bss_0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0xC];
    u8 *unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x278];
    u32 unk_298;
    u32 unk_29C;
};

extern struct fn_7_21C8_lbl_7_bss_0 lbl_7_bss_0;
extern u8 lbl_7_data_0[];

extern s32 fn_7_232C(void *);
extern int fn_7_2324(void);
extern s32 fn_7_24D8(void);
extern s32 fn_7_2384(void *);
extern s32 fn_7_2514(void);
extern s32 fn_7_23A8(void);
extern s32 fn_7_235C(void);
extern void fn_1_5370(s8, u32);
extern void fn_7_3FCC(void);
extern u32 fn_7_4108(void *, u32, void *);
extern u32 fn_7_41FC(void *);
extern void *fn_1_435C(void *);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_7_44DC(void);

#pragma opt_common_subs off
#pragma opt_propagation off
s32 fn_7_21C8(struct fn_7_21C8_Arg0 *arg0) {
    struct fn_7_21C8_lbl_7_bss_0 *p;
    u8 *base;
    u32 v;
    s32 t6;
    s32 t8;

    p = &lbl_7_bss_0;
    base = lbl_7_data_0 + 0x10000;
    p->unk_298 = 0;
    p->unk_29C = 0;
    arg0->unk_A8 = (u32)fn_7_232C;
    arg0->unk_C4 = (u32)fn_7_23A8;
    arg0->unk_B0 = (u32)fn_7_2324;
    arg0->unk_BC = (u32)fn_7_2384;
    arg0->unk_B8 = (u32)fn_7_24D8;
    arg0->unk_CC = (u32)fn_7_235C;
    arg0->unk_C0 = (u32)fn_7_2514;
    fn_1_5370(0, 0);
    arg0->unk_0 = (arg0->unk_0 | 8);
    fn_7_3FCC();
    v = *(u32 *)(p->unk_14 + 40);
    if (v != 0) {
        fn_7_4108((u8 *)p + 72, v, arg0);
        fn_7_41FC((u8 *)p + 72);
    }
    fn_7_4108((u8 *)p + 72, *(u32 *)(p->unk_14 + 44), arg0);
    fn_1_435C((void *)p->unk_18);
    t6 = fn_1_3F8C((u32)(base + 16076), (u32)fn_7_41FC, (u32)((u8 *)p + 72), 1);
    *(u32 *)(base + 11880) = t6;
    fn_1_435C((void *)p->unk_1C);
    t8 = fn_1_3F8C((u32)(base + 16092), (u32)fn_7_44DC, (u32)((u8 *)p + 72), 1);
    *(u32 *)(base + 11884) = t8;
    fn_1_435C((void *)p->unk_1C);
    p->unk_4 = 420;
    return 0;
}
#pragma opt_propagation reset

#pragma opt_common_subs reset
/* fzgx:end fn_7_21C8 */

/* fzgx:begin fn_7_2324 */
// fn_7_2324: returns a constant.
int fn_7_2324(void) {
    return 0;
}
/* fzgx:end fn_7_2324 */

/* fzgx:begin fn_7_232C */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_7_bss_0;
u32 fzgx_obj_lbl_7_bss_4[2];
u32 fzgx_obj_lbl_7_bss_C;
u32 fzgx_obj_lbl_7_bss_10;
u32 fzgx_obj_lbl_7_bss_14;
u32 fzgx_obj_lbl_7_bss_18;
u32 fzgx_obj_lbl_7_bss_1C[2];
u32 lbl_7_bss_1C__fzgx_offset_8;
u32 lbl_7_bss_1C__fzgx_offset_C[8];
u32 fzgx_obj_lbl_7_bss_48[148];
s32 lbl_7_bss_48__fzgx_offset_250;
u32 fzgx_obj_lbl_7_bss_29C;
u32 lbl_7_bss_29C__fzgx_offset_4;
u32 lbl_7_bss_29C__fzgx_offset_8[1455];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_7_bss_0;
    s = fzgx_obj_lbl_7_bss_4[0];
    s = fzgx_obj_lbl_7_bss_C;
    s = fzgx_obj_lbl_7_bss_10;
    s = fzgx_obj_lbl_7_bss_14;
    s = fzgx_obj_lbl_7_bss_18;
    s = fzgx_obj_lbl_7_bss_1C[0];
    s = lbl_7_bss_1C__fzgx_offset_8;
    s = lbl_7_bss_1C__fzgx_offset_C[0];
    s = fzgx_obj_lbl_7_bss_48[0];
    s = lbl_7_bss_48__fzgx_offset_250;
    s = fzgx_obj_lbl_7_bss_29C;
    s = lbl_7_bss_29C__fzgx_offset_4;
    s = lbl_7_bss_29C__fzgx_offset_8[0];
}
#pragma section code_type ".text"

s32 fn_7_232C(u32 *arg0) {
    s32 ret = 0;

    lbl_7_bss_29C__fzgx_offset_4 = *arg0;
    lbl_7_bss_1C__fzgx_offset_8 = lbl_7_bss_29C__fzgx_offset_4 & 2;
    if (lbl_7_bss_48__fzgx_offset_250 != 0) {
        ret = 2;
    }
    return ret;
}
/* fzgx:end fn_7_232C */

/* fzgx:begin fn_7_235C */
struct fn_7_235C_lbl_7_bss_48 {
    u8 pad_0[0x244];
    u32 unk_244;
};

s32 fn_7_235C(void) {
    u32 v0;
    v0 = (*(struct fn_7_235C_lbl_7_bss_48 *)&lbl_7_bss_48).unk_244;
    if (((*(struct fn_7_235C_lbl_7_bss_48 *)&lbl_7_bss_48).unk_244 & ~0x7FFFFFFF) != 0) {
    v0 = 1;
    return v0;
    }
    v0 = (-((v0 >> 30) & 0x1));
    return v0;
}
/* fzgx:end fn_7_235C */

/* fzgx:begin fn_7_2384 */
struct fn_7_2384_Arg0 {
    u32 unk_0;
};

s32 fn_7_2384(struct fn_7_2384_Arg0 *arg0) {
    if ((s32)(*(u32 *)&lbl_7_bss_29C) == 0) {
    arg0->unk_0 = (arg0->unk_0 | 0x80000);
    }
    return 0;
}
/* fzgx:end fn_7_2384 */

/* fzgx:begin fn_7_23A8 noprologue */
#include "types.h"

struct fn_7_23A8_bss_0 {
    u8 pad_0[0x8];
    s32 unk_8;
    u8 pad_C[0x4];
    u8 *unk_10;
    u8 pad_14[0x8];
    u32 unk_1C;
};

extern u32 lbl_7_bss_0[];
extern u32 lbl_7_data_12E70[2];
extern u8 lbl_7_data_13EEC[52];
extern u8 lbl_1_bss_9F8[];

extern u8 * fn_1_40B14(void);
extern void * fn_1_435C(void *);
extern u32 fn_7_3AB0(void);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_426C(u32);

#pragma opt_propagation off
#pragma opt_lifetimes off
s32 fn_7_23A8(void) {
    struct fn_7_23A8_bss_0 *p;
    u8 *t0;
    u8 v0;
    u16 v1;
    u32 v2;

    p = (struct fn_7_23A8_bss_0 *)&lbl_7_bss_0;
    t0 = fn_1_40B14();
    v0 = t0[0];
    switch (v0) {
    case 1: {
        s32 res;
        fn_1_435C((void *)p->unk_1C);
        res = fn_1_3F8C((u32)lbl_7_data_13EEC, (u32)fn_7_3AB0, (u32)&p->unk_8, 5);
        p->unk_8 = 10;
        lbl_7_data_12E70[0] = res;
        t0[0] = 2;
        return 4;
    }
    case 2: {
        u8 *tbl;
        tbl = (u8 *)lbl_1_bss_9F8 + 8;
        v2 = (s8)p->unk_10[2] * 20;
        v1 = *(u16 *)(tbl + v2);
        if (((v1 >> 9) & 1) || ((v1 >> 8) & 1) || ((v1 >> 12) & 1)) {
            t0[0] = 3;
            p->unk_8 = 10;
        }
        return 4;
    }
    case 3:
        if (p->unk_8 != 0) {
            return 4;
        }
        fn_1_435C((void *)p->unk_1C);
        fn_1_426C(lbl_7_data_12E70[0]);
        t0[0] = 0;
        break;
    }
    return 0;
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset
/* fzgx:end fn_7_23A8 */

/* fzgx:begin fn_7_24D8 */
struct fn_7_24D8_lbl_7_bss_29C {
    u32 unk_0;
};


extern u32 fn_7_3FCC(void);

s32 fn_7_24D8(void) {
    if ((s32)(*(struct fn_7_24D8_lbl_7_bss_29C *)&lbl_7_bss_29C).unk_0 == 0) {
    (*(struct fn_7_24D8_lbl_7_bss_29C *)&lbl_7_bss_29C).unk_0 = 1;
    fn_7_3FCC();
    }
    return 2;
}
/* fzgx:end fn_7_24D8 */

/* fzgx:begin fn_7_2514 */
extern u32 fn_7_3FCC(void);

s32 fn_7_2514(void) {
    fn_7_3FCC();
    return 0;
}
/* fzgx:end fn_7_2514 */

/* fzgx:begin fn_7_2538 noprologue */
#include "types.h"

#include "font.h"

typedef struct fn_7_2538_Vec { f32 x, y, z; } fn_7_2538_Vec;
typedef struct fn_7_2538_Color { u8 r, g, b, a; } fn_7_2538_Color;
typedef struct fn_7_2538_Row {
    u32 unk_0;
    char *title[4];
    u8 pad_14[0x5C];
    char *desc[4];
    u8 pad_80[0x4];
} fn_7_2538_Row;
typedef struct fn_7_2538_Time { u8 min, sec; u16 ms; } fn_7_2538_Time;
typedef struct fn_7_2538_Times { u8 pad_0[0x6C]; fn_7_2538_Time t[0x20][12]; } fn_7_2538_Times;
typedef struct fn_7_2538_Entry8 { void *unk_0; u32 unk_4; } fn_7_2538_Entry8;
typedef struct fn_7_2538_Res { u8 pad_0[8]; fn_7_2538_Entry8 *unk_8; } fn_7_2538_Res;
typedef struct fn_7_2538_Res38460 { u8 pad_0[0x18]; fn_7_2538_Res *unk_18; } fn_7_2538_Res38460;

extern FontDrawPacket lbl_1_rodata_26F8;
extern fn_7_2538_Res38460 lbl_1_bss_38460;
extern fn_7_2538_Times lbl_1_bss_7F0C0;
extern u16 lbl_1_data_414;
extern s32 lbl_801A66A0;
extern s32 lbl_801A66B4;
extern f32 lbl_8006D188(s32);
extern void fn_1_134AD4(void);
extern void fn_1_13ABA8(u32);
extern void fn_1_1380F0(const char *);
extern void fn_1_133DBC(void *);
extern void fn_8006F038(fn_7_2538_Vec *, fn_7_2538_Vec *, s16);
extern void lbl_8006DCDC(void);
extern void fn_80074D08(u32);
extern void fn_1_520A0(void);
extern void fn_1_52088(void);
extern void fn_1_520CC(void);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern void fn_1_4E724(FontDrawPacket *);
extern void fn_1_A71CC(void);
extern s8 fn_1_A5DC4(void);
extern void fn_1_A7024(f32, f32, f32, f32);
extern void fn_1_56000(u8, u8, u8);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0A4(fn_7_2538_Vec *);
extern void fn_80072558(void);
extern void fn_1_56018(s32);
extern void fn_1_560F0(s32, void *);
extern void fn_1_55FF0(f32);
extern void fn_1_556B8(void *);
extern void fn_1_A722C(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_49514(fn_7_2538_Color *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_495FC(void);
extern void fn_1_4965C(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_5233C(void);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4AF64(const char *, ...);
extern void fn_1_4CF3C(const char *, f32, ...);
extern s32 fn_1_F9CA0(u32, u8);
extern s32 fn_1_F9E80(u8, u8);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_50A90(FontDrawPacket *, u32, u32, u32, u32);
extern void fn_7_31F4(u32, const char *, u8, f32, f32);

#pragma fp_contract off
u8 fzgx_obj_lbl_7_data_0[0x2A0] = {1};
static u8 fzgx_pool_data_gap0[0x13EFC - 0x2A0] = {1};

u32 lbl_7_bss_0;
s32 lbl_7_bss_4[2];
s32 lbl_7_bss_C;
s8 *lbl_7_bss_10;
u32 lbl_7_bss_14;
u32 lbl_7_bss_18;
u32 lbl_7_bss_1C__fzgx_offset_0[2];
u32 lbl_7_bss_1C__fzgx_offset_8;
s32 lbl_7_bss_1C__fzgx_offset_C;
u32 lbl_7_bss_1C__fzgx_offset_10;
s32 lbl_7_bss_1C__fzgx_offset_14;
s32 lbl_7_bss_1C__fzgx_offset_18[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_7_bss_0;
    s = *(u8 *)&lbl_7_bss_4;
    s = *(u8 *)&lbl_7_bss_C;
    s = *(u8 *)&lbl_7_bss_10;
    s = *(u8 *)&lbl_7_bss_14;
    s = *(u8 *)&lbl_7_bss_18;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_0;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_8;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_C;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_10;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_14;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_18;
}
#pragma section code_type ".text"

/* data primer: an earlier function of the retail TU addressed .data off its section base first */
#pragma section RX ".fzgxpool" ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_data(void) {
    fn_1_1380F0("Select a chapter.");
    fn_1_1380F0("Select a level.");
    fn_1_1380F0("%s");
    fn_1_1380F0("NEW!");
    fn_1_1380F0("NORMAL");
    fn_1_1380F0("HARD");
    fn_1_1380F0("VERY HARD");
    fn_1_1380F0("BEST TIME");
    fn_1_1380F0("%2d'%02d\"%03d\n");
    fn_1_1380F0(" -'--\"---\n");
}
#pragma section RX ".text" ".text"
extern u8 lbl_7_data_0__fzgx_offset_0[];
extern u8 lbl_7_data_100A8__fzgx_offset_0[];
extern u8 lbl_7_data_105A0__fzgx_offset_0[];
extern u8 lbl_7_data_108A0__fzgx_offset_0[];
extern u8 lbl_7_data_109C0__fzgx_offset_0[];
extern u8 lbl_7_data_11470__fzgx_offset_0[];
extern u8 lbl_7_data_116E0__fzgx_offset_0[];
extern u8 lbl_7_data_117B8__fzgx_offset_0[];
extern u8 lbl_7_data_12790__fzgx_offset_0[];
extern u8 lbl_7_data_12958__fzgx_offset_0[];
extern u8 lbl_7_data_129A0__fzgx_offset_0[];
extern u8 lbl_7_data_12A00__fzgx_offset_0[];
extern u8 lbl_7_data_12E7C__fzgx_offset_0[];
extern u8 lbl_7_data_12EB8__fzgx_offset_0[];
extern u8 lbl_7_data_12EC8__fzgx_offset_0[];
extern u8 lbl_7_data_12ECC__fzgx_offset_0[];
extern u8 lbl_7_data_12ED4__fzgx_offset_0[];
extern u8 lbl_7_data_12F58__fzgx_offset_0[];
extern u8 lbl_7_data_12F90__fzgx_offset_0[];
extern u8 lbl_7_data_12FA0__fzgx_offset_0[];
extern u8 lbl_7_data_12FB0__fzgx_offset_0[];
extern u8 lbl_7_data_12FCC__fzgx_offset_0[];
extern u8 lbl_7_data_13034__fzgx_offset_0[];
extern u8 lbl_7_data_1309C__fzgx_offset_0[];
extern u8 lbl_7_data_130F4__fzgx_offset_0[];
extern u8 lbl_7_data_13134__fzgx_offset_0[];
extern u8 lbl_7_data_13144__fzgx_offset_0[];
extern u8 lbl_7_data_13154__fzgx_offset_0[];
extern u8 lbl_7_data_13168__fzgx_offset_0[];
extern u8 lbl_7_data_1319C__fzgx_offset_0[];
extern u8 lbl_7_data_131F4__fzgx_offset_0[];
extern u8 lbl_7_data_13230__fzgx_offset_0[];
extern u8 lbl_7_data_13240__fzgx_offset_0[];
extern u8 lbl_7_data_13250__fzgx_offset_0[];
extern u8 lbl_7_data_13268__fzgx_offset_0[];
extern u8 lbl_7_data_132D4__fzgx_offset_0[];
extern u8 lbl_7_data_13314__fzgx_offset_0[];
extern u8 lbl_7_data_13324__fzgx_offset_0[];
extern u8 lbl_7_data_13334__fzgx_offset_0[];
extern u8 lbl_7_data_13384__fzgx_offset_0[];
extern u8 lbl_7_data_133EC__fzgx_offset_0[];
extern u8 lbl_7_data_1341C__fzgx_offset_0[];
extern u8 lbl_7_data_1342C__fzgx_offset_0[];
extern u8 lbl_7_data_1343C__fzgx_offset_0[];
extern u8 lbl_7_data_1348C__fzgx_offset_0[];
extern u8 lbl_7_data_134DC__fzgx_offset_0[];
extern u8 lbl_7_data_1352C__fzgx_offset_0[];
extern u8 lbl_7_data_13574__fzgx_offset_0[];
extern u8 lbl_7_data_135AC__fzgx_offset_0[];
extern u8 lbl_7_data_135BC__fzgx_offset_0[];
extern u8 lbl_7_data_135CC__fzgx_offset_0[];
extern u8 lbl_7_data_1361C__fzgx_offset_0[];
extern u8 lbl_7_data_1366C__fzgx_offset_0[];
extern u8 lbl_7_data_136BC__fzgx_offset_0[];
extern u8 lbl_7_data_13724__fzgx_offset_0[];
extern u8 lbl_7_data_1375C__fzgx_offset_0[];
extern u8 lbl_7_data_1376C__fzgx_offset_0[];
extern u8 lbl_7_data_1377C__fzgx_offset_0[];
extern u8 lbl_7_data_1379C__fzgx_offset_0[];
extern u8 lbl_7_data_137F4__fzgx_offset_0[];
extern u8 lbl_7_data_13834__fzgx_offset_0[];
extern u8 lbl_7_data_13844__fzgx_offset_0[];
extern u8 lbl_7_data_13854__fzgx_offset_0[];
extern u8 lbl_7_data_138A4__fzgx_offset_0[];
extern u8 lbl_7_data_1390C__fzgx_offset_0[];
extern u8 lbl_7_data_1394C__fzgx_offset_0[];
extern u8 lbl_7_data_1395C__fzgx_offset_0[];
extern u8 lbl_7_data_1396C__fzgx_offset_0[];
extern u8 lbl_7_data_139BC__fzgx_offset_0[];
extern u8 lbl_7_data_1FF8__fzgx_offset_0[];
extern u8 lbl_7_data_22C8__fzgx_offset_0[];
extern u8 lbl_7_data_2418__fzgx_offset_0[];
extern u8 lbl_7_data_25B0__fzgx_offset_0[];
extern u8 lbl_7_data_2A0__fzgx_offset_0[];
extern u8 lbl_7_data_2E8__fzgx_offset_0[];
extern u8 lbl_7_data_348__fzgx_offset_0[];
extern u8 lbl_7_data_6618__fzgx_offset_0[];
extern u8 lbl_7_data_6AB0__fzgx_offset_0[];
extern u8 lbl_7_data_6DB0__fzgx_offset_0[];
extern u8 lbl_7_data_6E40__fzgx_offset_0[];
extern u8 lbl_7_data_A98__fzgx_offset_0[];
extern u8 lbl_7_data_BC20__fzgx_offset_0[];
extern u8 lbl_7_data_BEA8__fzgx_offset_0[];
extern u8 lbl_7_data_BF80__fzgx_offset_0[];
extern u8 lbl_7_data_C010__fzgx_offset_0[];
extern u8 lbl_7_data_C90__fzgx_offset_0[];
extern u8 lbl_7_data_C958__fzgx_offset_0[];
extern u8 lbl_7_data_CE80__fzgx_offset_0[];
extern u8 lbl_7_data_CF0__fzgx_offset_0[];
extern u8 lbl_7_data_D450__fzgx_offset_0[];
extern u8 lbl_7_data_D4C8__fzgx_offset_0[];
extern u8 lbl_7_data_DC8__fzgx_offset_0[];
static const union { u32 w[330]; const fn_7_2538_Row v[10]; } fzgx_pool_init_fzgx_story_table = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, (u32)lbl_7_data_12E7C__fzgx_offset_0, (u32)lbl_7_data_12E7C__fzgx_offset_0, (u32)lbl_7_data_12E7C__fzgx_offset_0, (u32)lbl_7_data_12E7C__fzgx_offset_0, (u32)lbl_7_data_12E7C__fzgx_offset_0, 0x0, (u32)lbl_7_data_12EB8__fzgx_offset_0,
    0x0, 0x0, 0x0, 0x0, (u32)lbl_7_data_12EC8__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0,
    (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0,
    (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ED4__fzgx_offset_0, (u32)lbl_7_data_12ED4__fzgx_offset_0, (u32)lbl_7_data_12ED4__fzgx_offset_0, (u32)lbl_7_data_12ED4__fzgx_offset_0,
    (u32)lbl_7_data_12ED4__fzgx_offset_0, 0x1250000, (u32)lbl_7_data_12F58__fzgx_offset_0, (u32)lbl_7_data_12F58__fzgx_offset_0, (u32)lbl_7_data_12F58__fzgx_offset_0, (u32)lbl_7_data_12F58__fzgx_offset_0, (u32)lbl_7_data_12F58__fzgx_offset_0, (u32)lbl_7_data_12F90__fzgx_offset_0,
    (u32)lbl_7_data_12FA0__fzgx_offset_0, (u32)lbl_7_data_0__fzgx_offset_0, (u32)lbl_7_data_2A0__fzgx_offset_0, (u32)lbl_7_data_2E8__fzgx_offset_0, (u32)lbl_7_data_348__fzgx_offset_0, (u32)lbl_7_data_12FB0__fzgx_offset_0, (u32)lbl_7_data_12FCC__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0,
    (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_12FCC__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_12FCC__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_12FCC__fzgx_offset_0,
    (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_12FCC__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_1309C__fzgx_offset_0, (u32)lbl_7_data_1309C__fzgx_offset_0, (u32)lbl_7_data_1309C__fzgx_offset_0,
    (u32)lbl_7_data_1309C__fzgx_offset_0, (u32)lbl_7_data_1309C__fzgx_offset_0, 0x2260000, (u32)lbl_7_data_130F4__fzgx_offset_0, (u32)lbl_7_data_130F4__fzgx_offset_0, (u32)lbl_7_data_130F4__fzgx_offset_0, (u32)lbl_7_data_130F4__fzgx_offset_0, (u32)lbl_7_data_130F4__fzgx_offset_0,
    (u32)lbl_7_data_13134__fzgx_offset_0, (u32)lbl_7_data_13144__fzgx_offset_0, (u32)lbl_7_data_A98__fzgx_offset_0, (u32)lbl_7_data_C90__fzgx_offset_0, (u32)lbl_7_data_CF0__fzgx_offset_0, (u32)lbl_7_data_DC8__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0,
    (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0,
    (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_1319C__fzgx_offset_0, (u32)lbl_7_data_1319C__fzgx_offset_0,
    (u32)lbl_7_data_1319C__fzgx_offset_0, (u32)lbl_7_data_1319C__fzgx_offset_0, (u32)lbl_7_data_1319C__fzgx_offset_0, 0x3270000, (u32)lbl_7_data_131F4__fzgx_offset_0, (u32)lbl_7_data_131F4__fzgx_offset_0, (u32)lbl_7_data_131F4__fzgx_offset_0, (u32)lbl_7_data_131F4__fzgx_offset_0,
    (u32)lbl_7_data_131F4__fzgx_offset_0, (u32)lbl_7_data_13230__fzgx_offset_0, (u32)lbl_7_data_13240__fzgx_offset_0, (u32)lbl_7_data_1FF8__fzgx_offset_0, (u32)lbl_7_data_22C8__fzgx_offset_0, (u32)lbl_7_data_2418__fzgx_offset_0, (u32)lbl_7_data_25B0__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0,
    (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0,
    (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13268__fzgx_offset_0,
    (u32)lbl_7_data_13268__fzgx_offset_0, (u32)lbl_7_data_13268__fzgx_offset_0, (u32)lbl_7_data_13268__fzgx_offset_0, (u32)lbl_7_data_13268__fzgx_offset_0, 0x4280000, (u32)lbl_7_data_132D4__fzgx_offset_0, (u32)lbl_7_data_132D4__fzgx_offset_0, (u32)lbl_7_data_132D4__fzgx_offset_0,
    (u32)lbl_7_data_132D4__fzgx_offset_0, (u32)lbl_7_data_132D4__fzgx_offset_0, (u32)lbl_7_data_13314__fzgx_offset_0, (u32)lbl_7_data_13324__fzgx_offset_0, (u32)lbl_7_data_6618__fzgx_offset_0, (u32)lbl_7_data_6AB0__fzgx_offset_0, (u32)lbl_7_data_6DB0__fzgx_offset_0, (u32)lbl_7_data_6E40__fzgx_offset_0,
    (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0,
    (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0,
    (u32)lbl_7_data_13384__fzgx_offset_0, (u32)lbl_7_data_13384__fzgx_offset_0, (u32)lbl_7_data_13384__fzgx_offset_0, (u32)lbl_7_data_13384__fzgx_offset_0, (u32)lbl_7_data_13384__fzgx_offset_0, 0x5290000, (u32)lbl_7_data_133EC__fzgx_offset_0, (u32)lbl_7_data_133EC__fzgx_offset_0,
    (u32)lbl_7_data_133EC__fzgx_offset_0, (u32)lbl_7_data_133EC__fzgx_offset_0, (u32)lbl_7_data_133EC__fzgx_offset_0, (u32)lbl_7_data_1341C__fzgx_offset_0, (u32)lbl_7_data_1342C__fzgx_offset_0, (u32)lbl_7_data_BC20__fzgx_offset_0, (u32)lbl_7_data_BEA8__fzgx_offset_0, (u32)lbl_7_data_BF80__fzgx_offset_0,
    (u32)lbl_7_data_C010__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_1343C__fzgx_offset_0, (u32)lbl_7_data_1348C__fzgx_offset_0, (u32)lbl_7_data_134DC__fzgx_offset_0, (u32)lbl_7_data_1343C__fzgx_offset_0, (u32)lbl_7_data_1348C__fzgx_offset_0, (u32)lbl_7_data_134DC__fzgx_offset_0,
    (u32)lbl_7_data_1343C__fzgx_offset_0, (u32)lbl_7_data_1348C__fzgx_offset_0, (u32)lbl_7_data_134DC__fzgx_offset_0, (u32)lbl_7_data_1343C__fzgx_offset_0, (u32)lbl_7_data_1348C__fzgx_offset_0, (u32)lbl_7_data_134DC__fzgx_offset_0, (u32)lbl_7_data_1343C__fzgx_offset_0, (u32)lbl_7_data_1348C__fzgx_offset_0,
    (u32)lbl_7_data_134DC__fzgx_offset_0, (u32)lbl_7_data_1352C__fzgx_offset_0, (u32)lbl_7_data_1352C__fzgx_offset_0, (u32)lbl_7_data_1352C__fzgx_offset_0, (u32)lbl_7_data_1352C__fzgx_offset_0, (u32)lbl_7_data_1352C__fzgx_offset_0, 0x62A0000, (u32)lbl_7_data_13574__fzgx_offset_0,
    (u32)lbl_7_data_13574__fzgx_offset_0, (u32)lbl_7_data_13574__fzgx_offset_0, (u32)lbl_7_data_13574__fzgx_offset_0, (u32)lbl_7_data_13574__fzgx_offset_0, (u32)lbl_7_data_135AC__fzgx_offset_0, (u32)lbl_7_data_135BC__fzgx_offset_0, (u32)lbl_7_data_C958__fzgx_offset_0, (u32)lbl_7_data_CE80__fzgx_offset_0,
    (u32)lbl_7_data_D450__fzgx_offset_0, (u32)lbl_7_data_D4C8__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_135CC__fzgx_offset_0, (u32)lbl_7_data_1361C__fzgx_offset_0, (u32)lbl_7_data_1366C__fzgx_offset_0, (u32)lbl_7_data_135CC__fzgx_offset_0, (u32)lbl_7_data_1361C__fzgx_offset_0,
    (u32)lbl_7_data_1366C__fzgx_offset_0, (u32)lbl_7_data_135CC__fzgx_offset_0, (u32)lbl_7_data_1361C__fzgx_offset_0, (u32)lbl_7_data_1366C__fzgx_offset_0, (u32)lbl_7_data_135CC__fzgx_offset_0, (u32)lbl_7_data_1361C__fzgx_offset_0, (u32)lbl_7_data_1366C__fzgx_offset_0, (u32)lbl_7_data_135CC__fzgx_offset_0,
    (u32)lbl_7_data_1361C__fzgx_offset_0, (u32)lbl_7_data_1366C__fzgx_offset_0, (u32)lbl_7_data_136BC__fzgx_offset_0, (u32)lbl_7_data_136BC__fzgx_offset_0, (u32)lbl_7_data_136BC__fzgx_offset_0, (u32)lbl_7_data_136BC__fzgx_offset_0, (u32)lbl_7_data_136BC__fzgx_offset_0, 0x72B0000,
    (u32)lbl_7_data_13724__fzgx_offset_0, (u32)lbl_7_data_13724__fzgx_offset_0, (u32)lbl_7_data_13724__fzgx_offset_0, (u32)lbl_7_data_13724__fzgx_offset_0, (u32)lbl_7_data_13724__fzgx_offset_0, (u32)lbl_7_data_1375C__fzgx_offset_0, (u32)lbl_7_data_1376C__fzgx_offset_0, (u32)lbl_7_data_100A8__fzgx_offset_0,
    (u32)lbl_7_data_105A0__fzgx_offset_0, (u32)lbl_7_data_108A0__fzgx_offset_0, (u32)lbl_7_data_109C0__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0,
    (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0,
    (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1379C__fzgx_offset_0, (u32)lbl_7_data_1379C__fzgx_offset_0, (u32)lbl_7_data_1379C__fzgx_offset_0, (u32)lbl_7_data_1379C__fzgx_offset_0, (u32)lbl_7_data_1379C__fzgx_offset_0,
    0x82C0000, (u32)lbl_7_data_137F4__fzgx_offset_0, (u32)lbl_7_data_137F4__fzgx_offset_0, (u32)lbl_7_data_137F4__fzgx_offset_0, (u32)lbl_7_data_137F4__fzgx_offset_0, (u32)lbl_7_data_137F4__fzgx_offset_0, (u32)lbl_7_data_13834__fzgx_offset_0, (u32)lbl_7_data_13844__fzgx_offset_0,
    (u32)lbl_7_data_11470__fzgx_offset_0, 0x0, (u32)lbl_7_data_116E0__fzgx_offset_0, (u32)lbl_7_data_117B8__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0,
    (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0,
    (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_138A4__fzgx_offset_0, (u32)lbl_7_data_138A4__fzgx_offset_0, (u32)lbl_7_data_138A4__fzgx_offset_0, (u32)lbl_7_data_138A4__fzgx_offset_0,
    (u32)lbl_7_data_138A4__fzgx_offset_0, 0x92D0000, (u32)lbl_7_data_1390C__fzgx_offset_0, (u32)lbl_7_data_1390C__fzgx_offset_0, (u32)lbl_7_data_1390C__fzgx_offset_0, (u32)lbl_7_data_1390C__fzgx_offset_0, (u32)lbl_7_data_1390C__fzgx_offset_0, (u32)lbl_7_data_1394C__fzgx_offset_0,
    (u32)lbl_7_data_1395C__fzgx_offset_0, (u32)lbl_7_data_12790__fzgx_offset_0, (u32)lbl_7_data_12958__fzgx_offset_0, (u32)lbl_7_data_129A0__fzgx_offset_0, (u32)lbl_7_data_12A00__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0,
    (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0,
    (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_139BC__fzgx_offset_0, (u32)lbl_7_data_139BC__fzgx_offset_0, (u32)lbl_7_data_139BC__fzgx_offset_0,
    (u32)lbl_7_data_139BC__fzgx_offset_0, (u32)lbl_7_data_139BC__fzgx_offset_0
}};

/* pool primer: reproduces the TU literal pool ahead of this function */
extern void fzgx_sink_f(f32);
extern void fzgx_sink_p(const void *);

#pragma section RX ".fzgxpool" ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_0(void) { fzgx_sink_f(0.0f); fzgx_sink_f(1.0f); }
__declspec(section ".fzgxpool") void fzgx_pool_1(void) {
    u32 b[33] = {
        0x000F0019, 0x0023000F, 0x00190023, 0x000F0019, 0x00230014, 0x00190023, 0x00140019,
        0x00230019, 0x001E0028, 0x0019001E, 0x0028001E, 0x0023002D, 0x001E0023, 0x002D0000,
        0x001F0010, 0x0047001D, 0x000A0048, 0x001E0003, 0x00420023, 0x0002003B, 0x002A0007,
        0x00370021, 0x0015003F, 0x001B0005, 0x00330028, 0x000F0044, 0x002B0004, 0x00380000,
        0x00280024, 0x0027001F, 0x00200023, 0x00210025, 0x00260000 };
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_2(void) { fzgx_sink_f(0.5f); }
#pragma section RX ".text" ".text"

void fn_7_2538(void) {
    FontDrawPacket pkt1;
    FontDrawPacket pkt2;
    FontDrawPacket pkt3;
    FontDrawPacket pkt4;
    FontDrawPacket pkt5;
    struct { u32 unk_0; fn_7_2538_Vec eye; fn_7_2538_Vec at; u32 unk_1C[2]; } cam;
    s32 hard;
    s32 idx;

    idx = lbl_7_bss_10[0];
    fn_1_134AD4();
    fn_1_13ABA8(0x28000000);
    switch (lbl_7_bss_1C__fzgx_offset_14) {
    case 1:
        fn_1_1380F0("Select a chapter.");
        break;
    case 2:
        fn_1_1380F0("Select a level.");
        break;
    }
    pkt1 = lbl_1_rodata_26F8;
    pkt1.image = 0x10000 - 17898;
    pkt1.x = 167.0f;
    pkt1.y = 38.0f;
    pkt1.z = 90.0f;
    pkt1.flags = 10;
    fn_1_4F734(&pkt1);
    fn_1_133DBC(NULL);
    {
    fn_7_2538_Vec eye0 = { 0.0f, 0.0f, -8.5f };
    fn_7_2538_Vec at0 = { 0.0f, 0.0f, 0.0f };
    cam.eye = eye0;
    cam.at = at0;
    cam.eye.x = 0.0f;
    cam.eye.y = 0.0f;
    cam.eye.z = -8.5f;
    cam.at.x = 0.0f;
    cam.at.y = 0.0f;
    cam.at.z = 0.0f;
    if (lbl_7_bss_1C__fzgx_offset_14 == 3) {
        cam.eye.z = -8.5f + 0.3f * (f32)(30 - lbl_7_bss_4[0]);
    }
    fn_8006F038(&cam.eye, &cam.at, 0);
    }
    lbl_8006DCDC();
    fn_80074D08(0);
    fn_1_520A0();
    {
    static const fn_7_2538_Color fzgx_pool_black = { 0, 0, 0, 0xFF };
    pkt2 = lbl_1_rodata_26F8;
    fn_1_52088();
    pkt2.image = 0x12;
    pkt2.x = 320.0f;
    pkt2.y = 240.0f;
    pkt2.scale_x *= 640.0f / fn_1_48690(0x12);
    pkt2.scale_y *= 480.0f / fn_1_486C4(pkt2.image);
    pkt2.z = 220.0f;
    pkt2.flags = 10;
    *(fn_7_2538_Color *)pkt2.color = fzgx_pool_black;
    pkt2.alpha = 0.3f;
    fn_1_4E724(&pkt2);
    }
    fn_1_520CC();
    fn_1_A71CC();
    if (fn_1_A5DC4()) {
        fn_1_A7024(55.0f, 1.7777778f, 0.1f, 90000.0f);
    } else {
        fn_1_A7024(55.0f, 1.3333334f, 0.1f, 90000.0f);
    }
    fn_1_56000(0, 7, 0);
    {
    s32 courses[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    u8 mtx[0x30];
    fn_7_2538_Vec light = { 0.0f, 0.8f, 0.0f };
    light.x = 0.0f;
    light.y = 0.8f;
    light.z = 0.0f;
    lbl_8006D7F4(0.0f, 0.0f, 0.0f);
    lbl_8006DB74(mtx);
    lbl_8006DCA4();
    lbl_8006E0A4(&light);
    fn_80072558();
    fn_1_56018(1);
    fn_1_560F0(0, mtx);
    fn_1_55FF0(0.5f);
    fn_1_556B8(lbl_1_bss_38460.unk_18->unk_8[(s8)courses[idx]].unk_0);
    fn_1_56018(0);
    fn_1_56000(1, 3, 1);
    fn_1_A722C();
    }

    fn_1_49410();
    fn_1_4965C(2);
    fn_1_495C8(9);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(8.0f);
    fn_1_4955C(1.0f, 1.1666666f);
    fn_1_49590(0.25f);
    fn_1_496FC(320.0f, 200.0f);
    fn_1_4CF3C("%s", 480.0f, fzgx_pool_init_fzgx_story_table.v[idx].title[lbl_801A66B4]);
    if (!(lbl_1_data_414 & (0x8000 >> idx)) && fn_1_F9CA0(0, idx)) {
        fn_1_49410();
        fn_1_4965C(2);
        fn_1_495C8(1);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(2.0f);
        fn_1_4955C(0.75f, 0.75f);
        fn_1_496FC(320.0f, 250.0f);
        fn_1_495A0(0.75f + 0.25f * lbl_8006D188((s32)(65536.0f * (f32)(lbl_801A66A0 % 30) / 30.0f)));
        fn_1_4AE0C("NEW!");
    }
    if (idx > 0) {
        pkt3 = lbl_1_rodata_26F8;
        pkt3.image = 0x10000 - 17917;
        pkt3.x = 40.0f;
        pkt3.y = 200.0f;
        pkt3.flags = 10;
        pkt3.scale_x = pkt3.scale_y = 1.0f + 0.5f * (f32)lbl_7_bss_1C__fzgx_offset_18[0] / 15.0f;
        fn_1_4F734(&pkt3);
    }
    if (idx < 9 && fn_1_F9CA0(0, idx + 1)) {
        pkt4 = lbl_1_rodata_26F8;
        pkt4.image = 0x10000 - 17917;
        pkt4.x = 600.0f;
        pkt4.y = 200.0f;
        pkt4.flags = 10;
        pkt4.rotation_z = -32768;
        pkt4.scale_x = pkt4.scale_y = 1.0f + 0.5f * (f32)lbl_7_bss_1C__fzgx_offset_18[1] / 15.0f;
        fn_1_4F734(&pkt4);
    }
    {
    f32 xs[2][3] = { { 224.0f, 416.0f, 0.0f }, { 184.0f, 320.0f, 456.0f } };
    hard = fn_1_F9CA0(2, idx) ? 1 : 0;
    pkt5 = lbl_1_rodata_26F8;
    pkt5.image = 0x10000 - 17886;
    pkt5.x = 320.0f;
    pkt5.y = 356.0f;
    pkt5.flags = 10;
    if (lbl_7_bss_1C__fzgx_offset_C <= 100) {
        pkt5.scale_x = 80.0f * (f32)lbl_7_bss_1C__fzgx_offset_C / 100.0f;
        pkt5.scale_y = 0.5f;
        fn_1_4F734(&pkt5);
    } else {
        fn_1_50A90(&pkt5, 640, 3, 640, (s32)(82.0f * ((f32)(lbl_7_bss_1C__fzgx_offset_C - 100) / 100.0f)));
    }
    if (lbl_7_bss_1C__fzgx_offset_C != 200) {
        return;
    }
    switch (lbl_7_bss_1C__fzgx_offset_14) {
    case 1:
        fn_1_49410();
        fn_1_495FC();
        fn_1_4965C(2);
        fn_1_495B0(0x80000000);
        fn_1_495C8(1);
        fn_1_4955C(0.75f, 0.8333333f);
        fn_1_4966C(0.0f, 16.0f);
        fn_1_496FC(320.0f, 328.0f);
        fn_1_49590(0.5f);
        fn_1_4AF64("%s", fzgx_pool_init_fzgx_story_table.v[idx].desc[lbl_801A66B4]);
        break;
    case 2:
        if (!hard) {
            fn_7_31F4(0x10000 - 17897, "NORMAL", lbl_7_bss_10[1] == 0, xs[0][0], 345.0f);
            fn_7_31F4(0x10000 - 17896, "HARD", lbl_7_bss_10[1] == 1, xs[0][1], 345.0f);
        } else {
            fn_7_31F4(0x10000 - 17897, "NORMAL", lbl_7_bss_10[1] == 0, xs[1][0], 345.0f);
            fn_7_31F4(0x10000 - 17896, "HARD", lbl_7_bss_10[1] == 1, xs[1][1], 345.0f);
            fn_7_31F4(0x10000 - 17895, "VERY HARD", lbl_7_bss_10[1] == 2, xs[1][2], 345.0f);
        }
        pkt5 = lbl_1_rodata_26F8;
        pkt5.x = xs[hard][lbl_7_bss_10[1]];
        pkt5.y = 345.0f;
        pkt5.z = pkt5.z - 0.003f;
        pkt5.flags = 10;
        pkt5.alpha = 0.5f;
        pkt5.image = 0x10000 - 17892;
        pkt5.color[0] = (s32)(40.0f + 40.0f * lbl_8006D188((s32)(16384.0f + 65536.0f * (f32)(lbl_7_bss_C % 60) / 60.0f)));
        pkt5.color[1] = (s32)(80.0f + 80.0f * lbl_8006D188((s32)(16384.0f + 65536.0f * (f32)(lbl_7_bss_C % 60) / 60.0f)));
        pkt5.color[2] = (s32)(80.0f + 80.0f * lbl_8006D188((s32)(16384.0f + 65536.0f * (f32)(lbl_7_bss_C % 60) / 60.0f)));
        fn_1_50A90(&pkt5, 7, 7, 128, 24);
        if (idx > 0) {
            fn_1_49410();
            fn_1_494DC(5);
            fn_1_495B0(0x80000000);
            fn_1_495C8(2);
            fn_1_496FC(320.0f, 365.0f);
            {
            fn_7_2538_Color yellow = { 0xFF, 0xFF, 0x00, 0x00 };
            fn_1_49514(&yellow);
            }
            fn_1_49590(0.5f);
            fn_1_4AE0C("BEST TIME");
            fn_1_49410();
            fn_1_494DC(5);
            fn_1_496FC(320.0f, 365.0f);
            if (fn_1_F9E80(lbl_7_bss_10[1], idx)) {
                if (lbl_1_bss_7F0C0.t[lbl_7_bss_10[1]][idx].min != 0 ||
                    lbl_1_bss_7F0C0.t[lbl_7_bss_10[1]][idx].sec != 0 ||
                    lbl_1_bss_7F0C0.t[lbl_7_bss_10[1]][idx].ms != 0) {
                    fn_1_4AE0C("%2d'%02d\"%03d\n", lbl_1_bss_7F0C0.t[lbl_7_bss_10[1]][idx].min,
                               lbl_1_bss_7F0C0.t[lbl_7_bss_10[1]][idx].sec,
                               lbl_1_bss_7F0C0.t[lbl_7_bss_10[1]][idx].ms);
                    return;
                }
            }
            fn_1_4AE0C(" -'--\"---\n");
        }
        break;
    }
    }
}
/* fzgx:end fn_7_2538 */

/* fzgx:begin fn_7_31F4 noprologue */
#include "types.h"

#include "font.h"

struct fn_7_31F4_Copy88 { u32 a[22]; };
struct fn_7_31F4_lbl_7_rodata_0 {
    u8 pad_0[0x528];
    f32 unk_528;
    f32 unk_52C;
    u8 pad_530[0x84];
    f32 unk_5B4;
    u8 pad_5B8[0x120];
    f32 unk_6D8;
    f32 unk_6DC;
    f32 unk_6E0;
    f32 unk_6E4;
    f32 unk_6E8;
    f32 unk_6EC;
};

extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_7_31F4_lbl_7_rodata_0 lbl_7_rodata_0;
extern u32 fn_1_49410(void);
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_7_data_13F20;
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_495C8(u8);
extern void fn_1_4965C(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);

void fn_7_31F4(u32 arg0, u32 arg1, u32 arg2, f32 arg3, f32 arg4) {
    struct fn_7_31F4_lbl_7_rodata_0 *p_lbl_7_rodata_0;
    f32 v0;
    FontDrawPacket loc_8;
    /* frame */
    p_lbl_7_rodata_0 = (struct fn_7_31F4_lbl_7_rodata_0 *)&lbl_7_rodata_0;
    v0 = p_lbl_7_rodata_0->unk_52C;
    if ((arg2 & 0xFF) == 0) {
    v0 = p_lbl_7_rodata_0->unk_5B4;
    }
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_8.image = (0x10000 - 17887);
    loc_8.x = arg3;
    loc_8.y = arg4;
    loc_8.z = (loc_8.z - p_lbl_7_rodata_0->unk_6D8);
    loc_8.alpha = v0;
    loc_8.flags = 11;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8.rotation_z = -32768;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_8.image = arg0;
    loc_8.x = arg3;
    loc_8.y = arg4;
    loc_8.z = (loc_8.z - p_lbl_7_rodata_0->unk_6DC);
    loc_8.alpha = v0;
    loc_8.flags = 15;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8.flags = (0x100000 + 7);
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8.rotation_z = -32768;
    loc_8.flags = 15;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8.flags = (0x100000 + 7);
    fn_1_4F734((FontDrawPacket *)&loc_8);
    fn_1_49410();
    fn_1_4965C(2);
    fn_1_495C8(1);
    fn_1_495A0(v0);
    fn_1_4966C(p_lbl_7_rodata_0->unk_6E0, p_lbl_7_rodata_0->unk_528);
    fn_1_4955C(p_lbl_7_rodata_0->unk_5B4, p_lbl_7_rodata_0->unk_6E4);
    fn_1_4954C(p_lbl_7_rodata_0->unk_6E8);
    fn_1_496FC(arg3, (arg4 - p_lbl_7_rodata_0->unk_6EC));
    fn_1_4AE0C((const char *)(u32)&lbl_7_data_13F20, arg1);
}
/* fzgx:end fn_7_31F4 */

/* fzgx:begin fn_7_33F0 noprologue */
#include "types.h"

#include "font.h"
#include "rel/story/story_mode.h"

struct fn_7_33F0_Copy88 { u32 a[22]; };
struct fn_7_33F0_lbl_7_bss_0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u8 pad_14[0x14];
    u32 unk_28;
    u8 pad_2C[0x10];
    u32 unk_3C;
};
struct fn_7_33F0_lbl_7_rodata_0 {
    u8 pad_0[0x528];
    f32 unk_528;
    u8 pad_52C[0x88];
    f32 unk_5B4;
    u8 pad_5B8[0x80];
    f32 unk_638;
    u8 pad_63C[0x44];
    f32 unk_680;
    u8 pad_684[0x4];
    f32 unk_688;
    f32 unk_68C;
    u8 pad_690[0x8];
    f32 unk_698;
    f32 unk_69C;
    u8 pad_6A0[0x4];
    f32 unk_6A4;
    f32 unk_6A8;
    u8 pad_6AC[0x1C];
    f64 unk_6C8;
    u8 pad_6D0[0x28];
    f32 unk_6F8;
    f32 unk_6FC;
    f32 unk_700;
    f32 unk_704;
    f32 unk_708;
    f32 unk_70C;
    f32 unk_710;
    f32 unk_714;
    f32 unk_718;
    f32 unk_71C;
    f32 unk_720;
    f32 unk_724;
    f32 unk_728;
};
struct fn_7_33F0_lbl_801A66A0 { s32 unk_0; };
struct fn_7_33F0_lbl_801A66B4 { s32 unk_0; };

extern f32 lbl_8006D188(u32);
extern int fn_1_4F734(FontDrawPacket *);
#pragma pool_data on
#pragma force_active on
extern u8 lbl_7_data_12E7C[];
extern u8 lbl_7_data_12EB8[];
extern u8 lbl_7_data_12EC8[];
extern u8 lbl_7_data_12ECC[];
extern u8 lbl_7_data_12ED4[];
extern u8 lbl_7_data_12F58[];
extern u8 lbl_7_data_12F90[];
extern u8 lbl_7_data_12FA0[];
extern u8 lbl_7_data_0[];
extern u8 lbl_7_data_2A0[];
extern u8 lbl_7_data_2E8[];
extern u8 lbl_7_data_348[];
extern u8 lbl_7_data_12FB0[];
extern u8 lbl_7_data_12FCC[];
extern u8 lbl_7_data_13034[];
extern u8 lbl_7_data_1309C[];
extern u8 lbl_7_data_130F4[];
extern u8 lbl_7_data_13134[];
extern u8 lbl_7_data_13144[];
extern u8 lbl_7_data_A98[];
extern u8 lbl_7_data_C90[];
extern u8 lbl_7_data_CF0[];
extern u8 lbl_7_data_DC8[];
extern u8 lbl_7_data_13154[];
extern u8 lbl_7_data_13168[];
extern u8 lbl_7_data_1319C[];
extern u8 lbl_7_data_131F4[];
extern u8 lbl_7_data_13230[];
extern u8 lbl_7_data_13240[];
extern u8 lbl_7_data_1FF8[];
extern u8 lbl_7_data_22C8[];
extern u8 lbl_7_data_2418[];
extern u8 lbl_7_data_25B0[];
extern u8 lbl_7_data_13250[];
extern u8 lbl_7_data_13268[];
extern u8 lbl_7_data_132D4[];
extern u8 lbl_7_data_13314[];
extern u8 lbl_7_data_13324[];
extern u8 lbl_7_data_6618[];
extern u8 lbl_7_data_6AB0[];
extern u8 lbl_7_data_6DB0[];
extern u8 lbl_7_data_6E40[];
extern u8 lbl_7_data_13334[];
extern u8 lbl_7_data_13384[];
extern u8 lbl_7_data_133EC[];
extern u8 lbl_7_data_1341C[];
extern u8 lbl_7_data_1342C[];
extern u8 lbl_7_data_BC20[];
extern u8 lbl_7_data_BEA8[];
extern u8 lbl_7_data_BF80[];
extern u8 lbl_7_data_C010[];
extern u8 lbl_7_data_1343C[];
extern u8 lbl_7_data_1348C[];
extern u8 lbl_7_data_134DC[];
extern u8 lbl_7_data_1352C[];
extern u8 lbl_7_data_13574[];
extern u8 lbl_7_data_135AC[];
extern u8 lbl_7_data_135BC[];
extern u8 lbl_7_data_C958[];
extern u8 lbl_7_data_CE80[];
extern u8 lbl_7_data_D450[];
extern u8 lbl_7_data_D4C8[];
extern u8 lbl_7_data_135CC[];
extern u8 lbl_7_data_1361C[];
extern u8 lbl_7_data_1366C[];
extern u8 lbl_7_data_136BC[];
extern u8 lbl_7_data_13724[];
extern u8 lbl_7_data_1375C[];
extern u8 lbl_7_data_1376C[];
extern u8 lbl_7_data_100A8[];
extern u8 lbl_7_data_105A0[];
extern u8 lbl_7_data_108A0[];
extern u8 lbl_7_data_109C0[];
extern u8 lbl_7_data_1377C[];
extern u8 lbl_7_data_1379C[];
extern u8 lbl_7_data_137F4[];
extern u8 lbl_7_data_13834[];
extern u8 lbl_7_data_13844[];
extern u8 lbl_7_data_11470[];
extern u8 lbl_7_data_116E0[];
extern u8 lbl_7_data_117B8[];
extern u8 lbl_7_data_13854[];
extern u8 lbl_7_data_138A4[];
extern u8 lbl_7_data_1390C[];
extern u8 lbl_7_data_1394C[];
extern u8 lbl_7_data_1395C[];
extern u8 lbl_7_data_12790[];
extern u8 lbl_7_data_12958[];
extern u8 lbl_7_data_129A0[];
extern u8 lbl_7_data_12A00[];
extern u8 lbl_7_data_1396C[];
extern u8 lbl_7_data_139BC[];
const u32 lbl_7_rodata_0[330] = {
0x00000000,
(u32)lbl_7_data_12E7C,
(u32)lbl_7_data_12E7C,
(u32)lbl_7_data_12E7C,
(u32)lbl_7_data_12E7C,
(u32)lbl_7_data_12E7C,
0x00000000,
(u32)lbl_7_data_12EB8,
0x00000000,
0x00000000,
0x00000000,
0x00000000,
(u32)lbl_7_data_12EC8,
(u32)lbl_7_data_12ECC,
(u32)lbl_7_data_12ECC,
(u32)lbl_7_data_12ECC,
(u32)lbl_7_data_12ECC,
(u32)lbl_7_data_12ECC,
(u32)lbl_7_data_12ECC,
(u32)lbl_7_data_12ECC,
(u32)lbl_7_data_12ECC,
(u32)lbl_7_data_12ECC,
(u32)lbl_7_data_12ECC,
(u32)lbl_7_data_12ECC,
(u32)lbl_7_data_12ECC,
(u32)lbl_7_data_12ECC,
(u32)lbl_7_data_12ECC,
(u32)lbl_7_data_12ECC,
(u32)lbl_7_data_12ED4,
(u32)lbl_7_data_12ED4,
(u32)lbl_7_data_12ED4,
(u32)lbl_7_data_12ED4,
(u32)lbl_7_data_12ED4,
0x01250000,
(u32)lbl_7_data_12F58,
(u32)lbl_7_data_12F58,
(u32)lbl_7_data_12F58,
(u32)lbl_7_data_12F58,
(u32)lbl_7_data_12F58,
(u32)lbl_7_data_12F90,
(u32)lbl_7_data_12FA0,
(u32)lbl_7_data_0,
(u32)lbl_7_data_2A0,
(u32)lbl_7_data_2E8,
(u32)lbl_7_data_348,
(u32)lbl_7_data_12FB0,
(u32)lbl_7_data_12FCC,
(u32)lbl_7_data_13034,
(u32)lbl_7_data_13034,
(u32)lbl_7_data_12FCC,
(u32)lbl_7_data_13034,
(u32)lbl_7_data_13034,
(u32)lbl_7_data_12FCC,
(u32)lbl_7_data_13034,
(u32)lbl_7_data_13034,
(u32)lbl_7_data_12FCC,
(u32)lbl_7_data_13034,
(u32)lbl_7_data_13034,
(u32)lbl_7_data_12FCC,
(u32)lbl_7_data_13034,
(u32)lbl_7_data_13034,
(u32)lbl_7_data_1309C,
(u32)lbl_7_data_1309C,
(u32)lbl_7_data_1309C,
(u32)lbl_7_data_1309C,
(u32)lbl_7_data_1309C,
0x02260000,
(u32)lbl_7_data_130F4,
(u32)lbl_7_data_130F4,
(u32)lbl_7_data_130F4,
(u32)lbl_7_data_130F4,
(u32)lbl_7_data_130F4,
(u32)lbl_7_data_13134,
(u32)lbl_7_data_13144,
(u32)lbl_7_data_A98,
(u32)lbl_7_data_C90,
(u32)lbl_7_data_CF0,
(u32)lbl_7_data_DC8,
(u32)lbl_7_data_13154,
(u32)lbl_7_data_13168,
(u32)lbl_7_data_13168,
(u32)lbl_7_data_13168,
(u32)lbl_7_data_13168,
(u32)lbl_7_data_13168,
(u32)lbl_7_data_13168,
(u32)lbl_7_data_13168,
(u32)lbl_7_data_13168,
(u32)lbl_7_data_13168,
(u32)lbl_7_data_13168,
(u32)lbl_7_data_13168,
(u32)lbl_7_data_13168,
(u32)lbl_7_data_13168,
(u32)lbl_7_data_13168,
(u32)lbl_7_data_13168,
(u32)lbl_7_data_1319C,
(u32)lbl_7_data_1319C,
(u32)lbl_7_data_1319C,
(u32)lbl_7_data_1319C,
(u32)lbl_7_data_1319C,
0x03270000,
(u32)lbl_7_data_131F4,
(u32)lbl_7_data_131F4,
(u32)lbl_7_data_131F4,
(u32)lbl_7_data_131F4,
(u32)lbl_7_data_131F4,
(u32)lbl_7_data_13230,
(u32)lbl_7_data_13240,
(u32)lbl_7_data_1FF8,
(u32)lbl_7_data_22C8,
(u32)lbl_7_data_2418,
(u32)lbl_7_data_25B0,
(u32)lbl_7_data_13154,
(u32)lbl_7_data_13250,
(u32)lbl_7_data_13250,
(u32)lbl_7_data_13250,
(u32)lbl_7_data_13250,
(u32)lbl_7_data_13250,
(u32)lbl_7_data_13250,
(u32)lbl_7_data_13250,
(u32)lbl_7_data_13250,
(u32)lbl_7_data_13250,
(u32)lbl_7_data_13250,
(u32)lbl_7_data_13250,
(u32)lbl_7_data_13250,
(u32)lbl_7_data_13250,
(u32)lbl_7_data_13250,
(u32)lbl_7_data_13250,
(u32)lbl_7_data_13268,
(u32)lbl_7_data_13268,
(u32)lbl_7_data_13268,
(u32)lbl_7_data_13268,
(u32)lbl_7_data_13268,
0x04280000,
(u32)lbl_7_data_132D4,
(u32)lbl_7_data_132D4,
(u32)lbl_7_data_132D4,
(u32)lbl_7_data_132D4,
(u32)lbl_7_data_132D4,
(u32)lbl_7_data_13314,
(u32)lbl_7_data_13324,
(u32)lbl_7_data_6618,
(u32)lbl_7_data_6AB0,
(u32)lbl_7_data_6DB0,
(u32)lbl_7_data_6E40,
(u32)lbl_7_data_13154,
(u32)lbl_7_data_13334,
(u32)lbl_7_data_13334,
(u32)lbl_7_data_13334,
(u32)lbl_7_data_13334,
(u32)lbl_7_data_13334,
(u32)lbl_7_data_13334,
(u32)lbl_7_data_13334,
(u32)lbl_7_data_13334,
(u32)lbl_7_data_13334,
(u32)lbl_7_data_13334,
(u32)lbl_7_data_13334,
(u32)lbl_7_data_13334,
(u32)lbl_7_data_13334,
(u32)lbl_7_data_13334,
(u32)lbl_7_data_13334,
(u32)lbl_7_data_13384,
(u32)lbl_7_data_13384,
(u32)lbl_7_data_13384,
(u32)lbl_7_data_13384,
(u32)lbl_7_data_13384,
0x05290000,
(u32)lbl_7_data_133EC,
(u32)lbl_7_data_133EC,
(u32)lbl_7_data_133EC,
(u32)lbl_7_data_133EC,
(u32)lbl_7_data_133EC,
(u32)lbl_7_data_1341C,
(u32)lbl_7_data_1342C,
(u32)lbl_7_data_BC20,
(u32)lbl_7_data_BEA8,
(u32)lbl_7_data_BF80,
(u32)lbl_7_data_C010,
(u32)lbl_7_data_13154,
(u32)lbl_7_data_1343C,
(u32)lbl_7_data_1348C,
(u32)lbl_7_data_134DC,
(u32)lbl_7_data_1343C,
(u32)lbl_7_data_1348C,
(u32)lbl_7_data_134DC,
(u32)lbl_7_data_1343C,
(u32)lbl_7_data_1348C,
(u32)lbl_7_data_134DC,
(u32)lbl_7_data_1343C,
(u32)lbl_7_data_1348C,
(u32)lbl_7_data_134DC,
(u32)lbl_7_data_1343C,
(u32)lbl_7_data_1348C,
(u32)lbl_7_data_134DC,
(u32)lbl_7_data_1352C,
(u32)lbl_7_data_1352C,
(u32)lbl_7_data_1352C,
(u32)lbl_7_data_1352C,
(u32)lbl_7_data_1352C,
0x062A0000,
(u32)lbl_7_data_13574,
(u32)lbl_7_data_13574,
(u32)lbl_7_data_13574,
(u32)lbl_7_data_13574,
(u32)lbl_7_data_13574,
(u32)lbl_7_data_135AC,
(u32)lbl_7_data_135BC,
(u32)lbl_7_data_C958,
(u32)lbl_7_data_CE80,
(u32)lbl_7_data_D450,
(u32)lbl_7_data_D4C8,
(u32)lbl_7_data_13154,
(u32)lbl_7_data_135CC,
(u32)lbl_7_data_1361C,
(u32)lbl_7_data_1366C,
(u32)lbl_7_data_135CC,
(u32)lbl_7_data_1361C,
(u32)lbl_7_data_1366C,
(u32)lbl_7_data_135CC,
(u32)lbl_7_data_1361C,
(u32)lbl_7_data_1366C,
(u32)lbl_7_data_135CC,
(u32)lbl_7_data_1361C,
(u32)lbl_7_data_1366C,
(u32)lbl_7_data_135CC,
(u32)lbl_7_data_1361C,
(u32)lbl_7_data_1366C,
(u32)lbl_7_data_136BC,
(u32)lbl_7_data_136BC,
(u32)lbl_7_data_136BC,
(u32)lbl_7_data_136BC,
(u32)lbl_7_data_136BC,
0x072B0000,
(u32)lbl_7_data_13724,
(u32)lbl_7_data_13724,
(u32)lbl_7_data_13724,
(u32)lbl_7_data_13724,
(u32)lbl_7_data_13724,
(u32)lbl_7_data_1375C,
(u32)lbl_7_data_1376C,
(u32)lbl_7_data_100A8,
(u32)lbl_7_data_105A0,
(u32)lbl_7_data_108A0,
(u32)lbl_7_data_109C0,
(u32)lbl_7_data_13154,
(u32)lbl_7_data_1377C,
(u32)lbl_7_data_1377C,
(u32)lbl_7_data_1377C,
(u32)lbl_7_data_1377C,
(u32)lbl_7_data_1377C,
(u32)lbl_7_data_1377C,
(u32)lbl_7_data_1377C,
(u32)lbl_7_data_1377C,
(u32)lbl_7_data_1377C,
(u32)lbl_7_data_1377C,
(u32)lbl_7_data_1377C,
(u32)lbl_7_data_1377C,
(u32)lbl_7_data_1377C,
(u32)lbl_7_data_1377C,
(u32)lbl_7_data_1377C,
(u32)lbl_7_data_1379C,
(u32)lbl_7_data_1379C,
(u32)lbl_7_data_1379C,
(u32)lbl_7_data_1379C,
(u32)lbl_7_data_1379C,
0x082C0000,
(u32)lbl_7_data_137F4,
(u32)lbl_7_data_137F4,
(u32)lbl_7_data_137F4,
(u32)lbl_7_data_137F4,
(u32)lbl_7_data_137F4,
(u32)lbl_7_data_13834,
(u32)lbl_7_data_13844,
(u32)lbl_7_data_11470,
0x00000000,
(u32)lbl_7_data_116E0,
(u32)lbl_7_data_117B8,
(u32)lbl_7_data_13154,
(u32)lbl_7_data_13854,
(u32)lbl_7_data_13854,
(u32)lbl_7_data_13854,
(u32)lbl_7_data_13854,
(u32)lbl_7_data_13854,
(u32)lbl_7_data_13854,
(u32)lbl_7_data_13854,
(u32)lbl_7_data_13854,
(u32)lbl_7_data_13854,
(u32)lbl_7_data_13854,
(u32)lbl_7_data_13854,
(u32)lbl_7_data_13854,
(u32)lbl_7_data_13854,
(u32)lbl_7_data_13854,
(u32)lbl_7_data_13854,
(u32)lbl_7_data_138A4,
(u32)lbl_7_data_138A4,
(u32)lbl_7_data_138A4,
(u32)lbl_7_data_138A4,
(u32)lbl_7_data_138A4,
0x092D0000,
(u32)lbl_7_data_1390C,
(u32)lbl_7_data_1390C,
(u32)lbl_7_data_1390C,
(u32)lbl_7_data_1390C,
(u32)lbl_7_data_1390C,
(u32)lbl_7_data_1394C,
(u32)lbl_7_data_1395C,
(u32)lbl_7_data_12790,
(u32)lbl_7_data_12958,
(u32)lbl_7_data_129A0,
(u32)lbl_7_data_12A00,
(u32)lbl_7_data_13154,
(u32)lbl_7_data_1396C,
(u32)lbl_7_data_1396C,
(u32)lbl_7_data_1396C,
(u32)lbl_7_data_1396C,
(u32)lbl_7_data_1396C,
(u32)lbl_7_data_1396C,
(u32)lbl_7_data_1396C,
(u32)lbl_7_data_1396C,
(u32)lbl_7_data_1396C,
(u32)lbl_7_data_1396C,
(u32)lbl_7_data_1396C,
(u32)lbl_7_data_1396C,
(u32)lbl_7_data_1396C,
(u32)lbl_7_data_1396C,
(u32)lbl_7_data_1396C,
(u32)lbl_7_data_139BC,
(u32)lbl_7_data_139BC,
(u32)lbl_7_data_139BC,
(u32)lbl_7_data_139BC,
(u32)lbl_7_data_139BC
};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_528(f32 *p) { *p = 0.0f; }
const u32 fzgx_pool_table_52c[34] = { 0x3F800000, 0x000F0019, 0x0023000F, 0x00190023, 0x000F0019, 0x00230014, 0x00190023, 0x00140019, 0x00230019, 0x001E0028, 0x0019001E, 0x0028001E, 0x0023002D, 0x001E0023, 0x002D0000, 0x001F0010, 0x0047001D, 0x000A0048, 0x001E0003, 0x00420023, 0x0002003B, 0x002A0007, 0x00370021, 0x0015003F, 0x001B0005, 0x00330028, 0x000F0044, 0x002B0004, 0x00380000, 0x00280024, 0x0027001F, 0x00200023, 0x00210025, 0x00260000 };
static void fzgx_pool_primer_5b4(f32 *p) { *p = 0.5f; }
const u32 fzgx_pool_table_5b8[32] = { 0x00000000, 0x00000000, (u32)(-1056440320) /* f32 -8.5 */, 0x00000000, 0x00000000, 0x00000000, 0x000000FF, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005, 0x00000006, 0x00000007, 0x00000008, 0x00000009, 0x00000000, 0x00000000, 0x3F4CCCCD, 0x00000000, 0x43600000, 0x43D00000, 0x00000000, 0x43380000, 0x43A00000, 0x43E40000, 0xFFFF0000, 0x43270000, 0x42180000, 0x42B40000, (u32)(-1056440320) /* f32 -8.5 */, 0x3E99999A };
static void fzgx_pool_primer_638(f32 *p) { *p = 320.0f; }
const u32 fzgx_pool_table_63c[17] = { 0x43700000, 0x44200000, 0x43F00000, 0x435C0000, 0x425C0000, 0x3FE38E39, 0x3DCCCCCD, 0x47AFC800, 0x3FAAAAAB, 0x3F4CCCCD, 0x41000000, 0x3F955555, 0x3E800000, 0x43480000, 0x40000000, 0x3F400000, 0x437A0000 };
static void fzgx_pool_primer_680(f32 *p) { *p = 65536.0f; }
const u32 fzgx_pool_table_684[1] = { 0x41F00000 };
static void fzgx_pool_primer_688(f32 *p) { *p = 40.0f; }
static void fzgx_pool_primer_68c(f32 *p) { *p = 15.0f; }
const u32 fzgx_pool_table_690[2] = { 0x44160000, 0x43B20000 };
static void fzgx_pool_primer_698(f32 *p) { *p = 80.0f; }
static void fzgx_pool_primer_69c(f32 *p) { *p = 100.0f; }
const u32 fzgx_pool_table_6a0[1] = { 0x42A40000 };
static void fzgx_pool_primer_6a4(f32 *p) { *p = 0.8333333134651184f; }
static void fzgx_pool_primer_6a8(f32 *p) { *p = 16.0f; }
const u32 fzgx_pool_table_6ac[7] = { 0x43A40000, 0x43AC8000, 0x3B449BA6, 0x46800000, 0x42700000, 0x43B68000, 0x00000000 };
static void fzgx_pool_primer_6c8(f64 *p) { *p = 4503601774854144.0; }
const u32 fzgx_pool_table_6d0[10] = { 0x43300000, 0x00000000, 0x3B03126F, 0x3B83126F, 0xBF800000, 0x3F155555, 0x3DB851EC, 0x40E00000, 0xFFFFFF00, 0x43600000 };
static void fzgx_pool_primer_6f8(f32 *p) { *p = 136.0f; }
static void fzgx_pool_primer_6fc(f32 *p) { *p = 0.01f; }
static void fzgx_pool_primer_700(f32 *p) { *p = 0.03f; }
static void fzgx_pool_primer_704(f32 *p) { *p = 0.04f; }
static void fzgx_pool_primer_708(f32 *p) { *p = 1.162162184715271f; }
static void fzgx_pool_primer_70c(f32 *p) { *p = 197.0f; }
static void fzgx_pool_primer_710(f32 *p) { *p = 58.0f; }
static void fzgx_pool_primer_714(f32 *p) { *p = 372.0f; }
static void fzgx_pool_primer_718(f32 *p) { *p = 0.0001f; }
static void fzgx_pool_primer_71c(f32 *p) { *p = 12.0f; }
static void fzgx_pool_primer_720(f32 *p) { *p = 22.0f; }
static void fzgx_pool_primer_724(f32 *p) { *p = 9.0f; }
static void fzgx_pool_primer_728(f32 *p) { *p = 14.0f; }


#pragma force_active reset
extern struct fn_7_33F0_lbl_801A66A0 lbl_801A66A0;
extern struct fn_7_33F0_lbl_801A66B4 lbl_801A66B4;
extern u32 fn_1_50A90(void *, u32, u32, u32, u32);
extern u32 lbl_1_rodata_26F8;
extern u8 *fn_80083970(u8 *, const u8 *);
extern void fn_1_49410(void);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_495FC(void);
extern void fn_1_4965C(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AF64(const char *, ...);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);

struct fn_7_33F0_Row { u8 *name[6][3]; u8 pad_48[60]; };
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_7_bss_0;
u32 lbl_7_bss_4[2];
u32 lbl_7_bss_C;
u32 fzgx_obj_lbl_7_bss_10;
u32 fzgx_obj_lbl_7_bss_14;
u32 lbl_7_bss_18;
u32 fzgx_obj_lbl_7_bss_1C[3];
s32 lbl_7_bss_1C__fzgx_offset_C;
u32 lbl_7_bss_1C__fzgx_offset_10[4];
u32 lbl_7_bss_1C__fzgx_offset_20;
u32 lbl_7_bss_1C__fzgx_offset_24[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_7_bss_0;
    s = *(u8 *)&lbl_7_bss_4;
    s = *(u8 *)&lbl_7_bss_C;
    s = *(u8 *)&fzgx_obj_lbl_7_bss_10;
    s = *(u8 *)&fzgx_obj_lbl_7_bss_14;
    s = *(u8 *)&lbl_7_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_7_bss_1C;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_C;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_10;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_20;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_24;
}
#pragma section code_type ".text"

void fn_7_33F0(void) {
    struct fn_7_33F0_lbl_7_rodata_0 *p_lbl_7_rodata_0;
    s32 v0;
    f32 v14;
    u32 v2;
    struct { s32 progress; u32 value; } img;
    f32 v1;
    f32 v13;
    f32 v47;
    void *v46;
    FontDrawPacket loc_8;
    
    v0 = lbl_7_bss_1C__fzgx_offset_20;
    if (v0 <= 0) {
        v0 += 233;
    } else {
        v0 = 233;
    }
    v1 = (f32)v0;
    {
        loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
        loc_8.image = 0x10000 - 17886;
        loc_8.x = 320.0f;
        loc_8.y = v1;
        loc_8.flags = 10;
        if (lbl_7_bss_1C__fzgx_offset_C <= 100) {
            loc_8.scale_x = 80.0f * (f32)lbl_7_bss_1C__fzgx_offset_C / 100.0f;
            loc_8.scale_y = 0.5f;
            fn_1_4F734(&loc_8);
        } else {
            fn_1_50A90(&loc_8, 640, 3, 640, (s32)(136.0f * ((f32)(lbl_7_bss_1C__fzgx_offset_C - 100) / 100.0f)));
        }
    }
    if ((s32)lbl_7_bss_1C__fzgx_offset_C == 200) {
        loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
        v14 = 16.0f + v1;
        loc_8.image = 0x10000 - 17889;
        loc_8.x = 320.0f;
        loc_8.y = v14;
        loc_8.z = loc_8.z - 0.01f;
        loc_8.flags = 10;
        fn_1_50A90(&loc_8, 7, 7, 474, 90);
        loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
        loc_8.image = 0x10000 - 17892;
        loc_8.x = 320.0f;
        loc_8.y = v14;
        loc_8.z = loc_8.z - 0.03f;
        *(f32 *)((u8 *)&loc_8 + 44) = 0.5f;
        loc_8.image = 0x10000 - 17892;
        v13 = lbl_8006D188((s32)(65536.0f * (f32)(lbl_801A66A0.unk_0 % 15) / 15.0f));
        *(u8 *)((u8 *)&loc_8 + 56) = (s32)(40.0f + (f32)(40.0f * v13));
        v13 = lbl_8006D188((s32)(65536.0f * (f32)(lbl_801A66A0.unk_0 % 15) / 15.0f));
        *(u8 *)((u8 *)&loc_8 + 57) = (s32)(80.0f + (f32)(80.0f * v13));
        v13 = lbl_8006D188((s32)(65536.0f * (f32)(lbl_801A66A0.unk_0 % 15) / 15.0f));
        loc_8.flags = 10;
        *(u8 *)((u8 *)&loc_8 + 58) = (s32)(80.0f + (f32)(80.0f * v13));
        fn_1_50A90(&loc_8, 7, 7, 474, 90);
        loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
        loc_8.image = 0x10000 - 17894;
        loc_8.x = 320.0f;
        loc_8.y = v14;
        loc_8.z = loc_8.z - 0.04f;
        loc_8.scale_y = 1.162162184715271f;
        loc_8.flags = 15;
        fn_1_4F734(&loc_8);
        loc_8.flags = 0x100000 + 7;
        fn_1_4F734(&loc_8);
        loc_8.rotation_z = -32768;
        loc_8.flags = 15;
        fn_1_4F734(&loc_8);
        loc_8.flags = 0x100000 + 7;
        fn_1_4F734(&loc_8);
        loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
        loc_8.image = 0x10000 - 17903;
        loc_8.x = 197.0f;
        loc_8.y = v1 - 58.0f;
        loc_8.z = loc_8.z - 0.01f;
        fn_1_4F734(&loc_8);
        loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
        loc_8.image = 0x10000 - 17902;
        loc_8.x = 372.0f;
        loc_8.y = v1 - 58.0f;
        loc_8.z = loc_8.z - 0.01f;
        fn_1_51678(&loc_8, 0x10000 - 17902, (s16)((s8)*(u8 *)fzgx_obj_lbl_7_bss_10 * 36), 0, 36, 24);
        fn_1_4F734(&loc_8);
        fn_1_49410();
        fn_1_495FC();
        fn_1_4965C(2);
        fn_1_4954C(0.0001f);
        fn_1_495C8(1);
        fn_1_495B0(0x80000000);
        fn_1_4955C(0.8333333134651184f, 0.8333333134651184f);
        fn_1_4966C(0.0f, 12.0f);
        {
            u32 v43;
            s32 v44;
            s32 v45;
            u32 v12;
            u32 v48;
            s32 v49;
            v43 = fzgx_obj_lbl_7_bss_10;
            v44 = lbl_801A66B4.unk_0;
            v12 = (s8)*(u8 *)v43;

            p_lbl_7_rodata_0 = (struct fn_7_33F0_lbl_7_rodata_0 *)&lbl_7_rodata_0;
            v46 = (u8 *)p_lbl_7_rodata_0 + 52;
            v12 = (u32)((struct fn_7_33F0_Row *)v46)[v12].name[v44][(s8)*((u8 *)v43 + 1)];
            if (fn_80083970((u8 *)v12, lbl_7_data_13F70) != 0) {
                v47 = 22.0f;
            } else {
                v47 = 9.0f;
            }
            fn_1_496FC(320.0f, (14.0f + v1) - v47);
            fn_1_49590(0.5f);
            v48 = fzgx_obj_lbl_7_bss_10;
            v44 = lbl_801A66B4.unk_0;
            v12 = (s8)*(u8 *)v48;
            v12 = (u32)((struct fn_7_33F0_Row *)v46)[v12].name[v44][(s8)*((u8 *)v48 + 1)];
            fn_1_4AF64((const char *)lbl_7_data_13F20, v12);
        }
    }
}
/* fzgx:end fn_7_33F0 */

/* fzgx:begin fn_7_3AB0 */
#include "font.h"

typedef struct fn_7_3AB0_Entry {
    u8 pad_0[0x34];
    u32 msg[4][3];
    u8 pad_64[0x20];
} fn_7_3AB0_Entry;

struct fn_7_3AB0_lbl_7_bss_10 {
    s8 *unk_0;
};

extern u32 fn_1_50A90(void *, u32, u32, u32, u32);

extern u8 *fn_1_40B14(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_495FC(void);
extern void fn_1_4965C(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AF64(const char *, ...);

/* story course table: first object of the TU's .rodata */
extern u8 lbl_7_data_0__fzgx_offset_0[];
extern u8 lbl_7_data_100A8__fzgx_offset_0[];
extern u8 lbl_7_data_105A0__fzgx_offset_0[];
extern u8 lbl_7_data_108A0__fzgx_offset_0[];
extern u8 lbl_7_data_109C0__fzgx_offset_0[];
extern u8 lbl_7_data_11470__fzgx_offset_0[];
extern u8 lbl_7_data_116E0__fzgx_offset_0[];
extern u8 lbl_7_data_117B8__fzgx_offset_0[];
extern u8 lbl_7_data_12790__fzgx_offset_0[];
extern u8 lbl_7_data_12958__fzgx_offset_0[];
extern u8 lbl_7_data_129A0__fzgx_offset_0[];
extern u8 lbl_7_data_12A00__fzgx_offset_0[];
extern u8 lbl_7_data_12E7C__fzgx_offset_0[];
extern u8 lbl_7_data_12EB8__fzgx_offset_0[];
extern u8 lbl_7_data_12EC8__fzgx_offset_0[];
extern u8 lbl_7_data_12ECC__fzgx_offset_0[];
extern u8 lbl_7_data_12ED4__fzgx_offset_0[];
extern u8 lbl_7_data_12F58__fzgx_offset_0[];
extern u8 lbl_7_data_12F90__fzgx_offset_0[];
extern u8 lbl_7_data_12FA0__fzgx_offset_0[];
extern u8 lbl_7_data_12FB0__fzgx_offset_0[];
extern u8 lbl_7_data_12FCC__fzgx_offset_0[];
extern u8 lbl_7_data_13034__fzgx_offset_0[];
extern u8 lbl_7_data_1309C__fzgx_offset_0[];
extern u8 lbl_7_data_130F4__fzgx_offset_0[];
extern u8 lbl_7_data_13134__fzgx_offset_0[];
extern u8 lbl_7_data_13144__fzgx_offset_0[];
extern u8 lbl_7_data_13154__fzgx_offset_0[];
extern u8 lbl_7_data_13168__fzgx_offset_0[];
extern u8 lbl_7_data_1319C__fzgx_offset_0[];
extern u8 lbl_7_data_131F4__fzgx_offset_0[];
extern u8 lbl_7_data_13230__fzgx_offset_0[];
extern u8 lbl_7_data_13240__fzgx_offset_0[];
extern u8 lbl_7_data_13250__fzgx_offset_0[];
extern u8 lbl_7_data_13268__fzgx_offset_0[];
extern u8 lbl_7_data_132D4__fzgx_offset_0[];
extern u8 lbl_7_data_13314__fzgx_offset_0[];
extern u8 lbl_7_data_13324__fzgx_offset_0[];
extern u8 lbl_7_data_13334__fzgx_offset_0[];
extern u8 lbl_7_data_13384__fzgx_offset_0[];
extern u8 lbl_7_data_133EC__fzgx_offset_0[];
extern u8 lbl_7_data_1341C__fzgx_offset_0[];
extern u8 lbl_7_data_1342C__fzgx_offset_0[];
extern u8 lbl_7_data_1343C__fzgx_offset_0[];
extern u8 lbl_7_data_1348C__fzgx_offset_0[];
extern u8 lbl_7_data_134DC__fzgx_offset_0[];
extern u8 lbl_7_data_1352C__fzgx_offset_0[];
extern u8 lbl_7_data_13574__fzgx_offset_0[];
extern u8 lbl_7_data_135AC__fzgx_offset_0[];
extern u8 lbl_7_data_135BC__fzgx_offset_0[];
extern u8 lbl_7_data_135CC__fzgx_offset_0[];
extern u8 lbl_7_data_1361C__fzgx_offset_0[];
extern u8 lbl_7_data_1366C__fzgx_offset_0[];
extern u8 lbl_7_data_136BC__fzgx_offset_0[];
extern u8 lbl_7_data_13724__fzgx_offset_0[];
extern u8 lbl_7_data_1375C__fzgx_offset_0[];
extern u8 lbl_7_data_1376C__fzgx_offset_0[];
extern u8 lbl_7_data_1377C__fzgx_offset_0[];
extern u8 lbl_7_data_1379C__fzgx_offset_0[];
extern u8 lbl_7_data_137F4__fzgx_offset_0[];
extern u8 lbl_7_data_13834__fzgx_offset_0[];
extern u8 lbl_7_data_13844__fzgx_offset_0[];
extern u8 lbl_7_data_13854__fzgx_offset_0[];
extern u8 lbl_7_data_138A4__fzgx_offset_0[];
extern u8 lbl_7_data_1390C__fzgx_offset_0[];
extern u8 lbl_7_data_1394C__fzgx_offset_0[];
extern u8 lbl_7_data_1395C__fzgx_offset_0[];
extern u8 lbl_7_data_1396C__fzgx_offset_0[];
extern u8 lbl_7_data_139BC__fzgx_offset_0[];
extern u8 lbl_7_data_1FF8__fzgx_offset_0[];
extern u8 lbl_7_data_22C8__fzgx_offset_0[];
extern u8 lbl_7_data_2418__fzgx_offset_0[];
extern u8 lbl_7_data_25B0__fzgx_offset_0[];
extern u8 lbl_7_data_2A0__fzgx_offset_0[];
extern u8 lbl_7_data_2E8__fzgx_offset_0[];
extern u8 lbl_7_data_348__fzgx_offset_0[];
extern u8 lbl_7_data_6618__fzgx_offset_0[];
extern u8 lbl_7_data_6AB0__fzgx_offset_0[];
extern u8 lbl_7_data_6DB0__fzgx_offset_0[];
extern u8 lbl_7_data_6E40__fzgx_offset_0[];
extern u8 lbl_7_data_A98__fzgx_offset_0[];
extern u8 lbl_7_data_BC20__fzgx_offset_0[];
extern u8 lbl_7_data_BEA8__fzgx_offset_0[];
extern u8 lbl_7_data_BF80__fzgx_offset_0[];
extern u8 lbl_7_data_C010__fzgx_offset_0[];
extern u8 lbl_7_data_C90__fzgx_offset_0[];
extern u8 lbl_7_data_C958__fzgx_offset_0[];
extern u8 lbl_7_data_CE80__fzgx_offset_0[];
extern u8 lbl_7_data_CF0__fzgx_offset_0[];
extern u8 lbl_7_data_D450__fzgx_offset_0[];
extern u8 lbl_7_data_D4C8__fzgx_offset_0[];
extern u8 lbl_7_data_DC8__fzgx_offset_0[];
static const union { u32 w[330]; const fn_7_3AB0_Entry v[10]; } fzgx_pool_init_fzgx_story_table = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, (u32)lbl_7_data_12E7C__fzgx_offset_0, (u32)lbl_7_data_12E7C__fzgx_offset_0, (u32)lbl_7_data_12E7C__fzgx_offset_0, (u32)lbl_7_data_12E7C__fzgx_offset_0, (u32)lbl_7_data_12E7C__fzgx_offset_0, 0x0, (u32)lbl_7_data_12EB8__fzgx_offset_0,
    0x0, 0x0, 0x0, 0x0, (u32)lbl_7_data_12EC8__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0,
    (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0,
    (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ED4__fzgx_offset_0, (u32)lbl_7_data_12ED4__fzgx_offset_0, (u32)lbl_7_data_12ED4__fzgx_offset_0, (u32)lbl_7_data_12ED4__fzgx_offset_0,
    (u32)lbl_7_data_12ED4__fzgx_offset_0, 0x1250000, (u32)lbl_7_data_12F58__fzgx_offset_0, (u32)lbl_7_data_12F58__fzgx_offset_0, (u32)lbl_7_data_12F58__fzgx_offset_0, (u32)lbl_7_data_12F58__fzgx_offset_0, (u32)lbl_7_data_12F58__fzgx_offset_0, (u32)lbl_7_data_12F90__fzgx_offset_0,
    (u32)lbl_7_data_12FA0__fzgx_offset_0, (u32)lbl_7_data_0__fzgx_offset_0, (u32)lbl_7_data_2A0__fzgx_offset_0, (u32)lbl_7_data_2E8__fzgx_offset_0, (u32)lbl_7_data_348__fzgx_offset_0, (u32)lbl_7_data_12FB0__fzgx_offset_0, (u32)lbl_7_data_12FCC__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0,
    (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_12FCC__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_12FCC__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_12FCC__fzgx_offset_0,
    (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_12FCC__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_1309C__fzgx_offset_0, (u32)lbl_7_data_1309C__fzgx_offset_0, (u32)lbl_7_data_1309C__fzgx_offset_0,
    (u32)lbl_7_data_1309C__fzgx_offset_0, (u32)lbl_7_data_1309C__fzgx_offset_0, 0x2260000, (u32)lbl_7_data_130F4__fzgx_offset_0, (u32)lbl_7_data_130F4__fzgx_offset_0, (u32)lbl_7_data_130F4__fzgx_offset_0, (u32)lbl_7_data_130F4__fzgx_offset_0, (u32)lbl_7_data_130F4__fzgx_offset_0,
    (u32)lbl_7_data_13134__fzgx_offset_0, (u32)lbl_7_data_13144__fzgx_offset_0, (u32)lbl_7_data_A98__fzgx_offset_0, (u32)lbl_7_data_C90__fzgx_offset_0, (u32)lbl_7_data_CF0__fzgx_offset_0, (u32)lbl_7_data_DC8__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0,
    (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0,
    (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_1319C__fzgx_offset_0, (u32)lbl_7_data_1319C__fzgx_offset_0,
    (u32)lbl_7_data_1319C__fzgx_offset_0, (u32)lbl_7_data_1319C__fzgx_offset_0, (u32)lbl_7_data_1319C__fzgx_offset_0, 0x3270000, (u32)lbl_7_data_131F4__fzgx_offset_0, (u32)lbl_7_data_131F4__fzgx_offset_0, (u32)lbl_7_data_131F4__fzgx_offset_0, (u32)lbl_7_data_131F4__fzgx_offset_0,
    (u32)lbl_7_data_131F4__fzgx_offset_0, (u32)lbl_7_data_13230__fzgx_offset_0, (u32)lbl_7_data_13240__fzgx_offset_0, (u32)lbl_7_data_1FF8__fzgx_offset_0, (u32)lbl_7_data_22C8__fzgx_offset_0, (u32)lbl_7_data_2418__fzgx_offset_0, (u32)lbl_7_data_25B0__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0,
    (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0,
    (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13268__fzgx_offset_0,
    (u32)lbl_7_data_13268__fzgx_offset_0, (u32)lbl_7_data_13268__fzgx_offset_0, (u32)lbl_7_data_13268__fzgx_offset_0, (u32)lbl_7_data_13268__fzgx_offset_0, 0x4280000, (u32)lbl_7_data_132D4__fzgx_offset_0, (u32)lbl_7_data_132D4__fzgx_offset_0, (u32)lbl_7_data_132D4__fzgx_offset_0,
    (u32)lbl_7_data_132D4__fzgx_offset_0, (u32)lbl_7_data_132D4__fzgx_offset_0, (u32)lbl_7_data_13314__fzgx_offset_0, (u32)lbl_7_data_13324__fzgx_offset_0, (u32)lbl_7_data_6618__fzgx_offset_0, (u32)lbl_7_data_6AB0__fzgx_offset_0, (u32)lbl_7_data_6DB0__fzgx_offset_0, (u32)lbl_7_data_6E40__fzgx_offset_0,
    (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0,
    (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0,
    (u32)lbl_7_data_13384__fzgx_offset_0, (u32)lbl_7_data_13384__fzgx_offset_0, (u32)lbl_7_data_13384__fzgx_offset_0, (u32)lbl_7_data_13384__fzgx_offset_0, (u32)lbl_7_data_13384__fzgx_offset_0, 0x5290000, (u32)lbl_7_data_133EC__fzgx_offset_0, (u32)lbl_7_data_133EC__fzgx_offset_0,
    (u32)lbl_7_data_133EC__fzgx_offset_0, (u32)lbl_7_data_133EC__fzgx_offset_0, (u32)lbl_7_data_133EC__fzgx_offset_0, (u32)lbl_7_data_1341C__fzgx_offset_0, (u32)lbl_7_data_1342C__fzgx_offset_0, (u32)lbl_7_data_BC20__fzgx_offset_0, (u32)lbl_7_data_BEA8__fzgx_offset_0, (u32)lbl_7_data_BF80__fzgx_offset_0,
    (u32)lbl_7_data_C010__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_1343C__fzgx_offset_0, (u32)lbl_7_data_1348C__fzgx_offset_0, (u32)lbl_7_data_134DC__fzgx_offset_0, (u32)lbl_7_data_1343C__fzgx_offset_0, (u32)lbl_7_data_1348C__fzgx_offset_0, (u32)lbl_7_data_134DC__fzgx_offset_0,
    (u32)lbl_7_data_1343C__fzgx_offset_0, (u32)lbl_7_data_1348C__fzgx_offset_0, (u32)lbl_7_data_134DC__fzgx_offset_0, (u32)lbl_7_data_1343C__fzgx_offset_0, (u32)lbl_7_data_1348C__fzgx_offset_0, (u32)lbl_7_data_134DC__fzgx_offset_0, (u32)lbl_7_data_1343C__fzgx_offset_0, (u32)lbl_7_data_1348C__fzgx_offset_0,
    (u32)lbl_7_data_134DC__fzgx_offset_0, (u32)lbl_7_data_1352C__fzgx_offset_0, (u32)lbl_7_data_1352C__fzgx_offset_0, (u32)lbl_7_data_1352C__fzgx_offset_0, (u32)lbl_7_data_1352C__fzgx_offset_0, (u32)lbl_7_data_1352C__fzgx_offset_0, 0x62A0000, (u32)lbl_7_data_13574__fzgx_offset_0,
    (u32)lbl_7_data_13574__fzgx_offset_0, (u32)lbl_7_data_13574__fzgx_offset_0, (u32)lbl_7_data_13574__fzgx_offset_0, (u32)lbl_7_data_13574__fzgx_offset_0, (u32)lbl_7_data_135AC__fzgx_offset_0, (u32)lbl_7_data_135BC__fzgx_offset_0, (u32)lbl_7_data_C958__fzgx_offset_0, (u32)lbl_7_data_CE80__fzgx_offset_0,
    (u32)lbl_7_data_D450__fzgx_offset_0, (u32)lbl_7_data_D4C8__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_135CC__fzgx_offset_0, (u32)lbl_7_data_1361C__fzgx_offset_0, (u32)lbl_7_data_1366C__fzgx_offset_0, (u32)lbl_7_data_135CC__fzgx_offset_0, (u32)lbl_7_data_1361C__fzgx_offset_0,
    (u32)lbl_7_data_1366C__fzgx_offset_0, (u32)lbl_7_data_135CC__fzgx_offset_0, (u32)lbl_7_data_1361C__fzgx_offset_0, (u32)lbl_7_data_1366C__fzgx_offset_0, (u32)lbl_7_data_135CC__fzgx_offset_0, (u32)lbl_7_data_1361C__fzgx_offset_0, (u32)lbl_7_data_1366C__fzgx_offset_0, (u32)lbl_7_data_135CC__fzgx_offset_0,
    (u32)lbl_7_data_1361C__fzgx_offset_0, (u32)lbl_7_data_1366C__fzgx_offset_0, (u32)lbl_7_data_136BC__fzgx_offset_0, (u32)lbl_7_data_136BC__fzgx_offset_0, (u32)lbl_7_data_136BC__fzgx_offset_0, (u32)lbl_7_data_136BC__fzgx_offset_0, (u32)lbl_7_data_136BC__fzgx_offset_0, 0x72B0000,
    (u32)lbl_7_data_13724__fzgx_offset_0, (u32)lbl_7_data_13724__fzgx_offset_0, (u32)lbl_7_data_13724__fzgx_offset_0, (u32)lbl_7_data_13724__fzgx_offset_0, (u32)lbl_7_data_13724__fzgx_offset_0, (u32)lbl_7_data_1375C__fzgx_offset_0, (u32)lbl_7_data_1376C__fzgx_offset_0, (u32)lbl_7_data_100A8__fzgx_offset_0,
    (u32)lbl_7_data_105A0__fzgx_offset_0, (u32)lbl_7_data_108A0__fzgx_offset_0, (u32)lbl_7_data_109C0__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0,
    (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0,
    (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1379C__fzgx_offset_0, (u32)lbl_7_data_1379C__fzgx_offset_0, (u32)lbl_7_data_1379C__fzgx_offset_0, (u32)lbl_7_data_1379C__fzgx_offset_0, (u32)lbl_7_data_1379C__fzgx_offset_0,
    0x82C0000, (u32)lbl_7_data_137F4__fzgx_offset_0, (u32)lbl_7_data_137F4__fzgx_offset_0, (u32)lbl_7_data_137F4__fzgx_offset_0, (u32)lbl_7_data_137F4__fzgx_offset_0, (u32)lbl_7_data_137F4__fzgx_offset_0, (u32)lbl_7_data_13834__fzgx_offset_0, (u32)lbl_7_data_13844__fzgx_offset_0,
    (u32)lbl_7_data_11470__fzgx_offset_0, 0x0, (u32)lbl_7_data_116E0__fzgx_offset_0, (u32)lbl_7_data_117B8__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0,
    (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0,
    (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_138A4__fzgx_offset_0, (u32)lbl_7_data_138A4__fzgx_offset_0, (u32)lbl_7_data_138A4__fzgx_offset_0, (u32)lbl_7_data_138A4__fzgx_offset_0,
    (u32)lbl_7_data_138A4__fzgx_offset_0, 0x92D0000, (u32)lbl_7_data_1390C__fzgx_offset_0, (u32)lbl_7_data_1390C__fzgx_offset_0, (u32)lbl_7_data_1390C__fzgx_offset_0, (u32)lbl_7_data_1390C__fzgx_offset_0, (u32)lbl_7_data_1390C__fzgx_offset_0, (u32)lbl_7_data_1394C__fzgx_offset_0,
    (u32)lbl_7_data_1395C__fzgx_offset_0, (u32)lbl_7_data_12790__fzgx_offset_0, (u32)lbl_7_data_12958__fzgx_offset_0, (u32)lbl_7_data_129A0__fzgx_offset_0, (u32)lbl_7_data_12A00__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0,
    (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0,
    (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_139BC__fzgx_offset_0, (u32)lbl_7_data_139BC__fzgx_offset_0, (u32)lbl_7_data_139BC__fzgx_offset_0,
    (u32)lbl_7_data_139BC__fzgx_offset_0, (u32)lbl_7_data_139BC__fzgx_offset_0
}};

/* pool primer: reproduces the TU literal pool ahead of this function */
extern void fzgx_sink_f(f32);
extern void fzgx_sink_p(const void *);

#pragma section RX ".fzgxpool" ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_0(void) { fzgx_sink_f(0.0f); fzgx_sink_f(1.0f); }
__declspec(section ".fzgxpool") void fzgx_pool_1(void) {
    u32 b[33] = {
        0x000F0019, 0x0023000F, 0x00190023, 0x000F0019, 0x00230014, 0x00190023, 0x00140019,
        0x00230019, 0x001E0028, 0x0019001E, 0x0028001E, 0x0023002D, 0x001E0023, 0x002D0000,
        0x001F0010, 0x0047001D, 0x000A0048, 0x001E0003, 0x00420023, 0x0002003B, 0x002A0007,
        0x00370021, 0x0015003F, 0x001B0005, 0x00330028, 0x000F0044, 0x002B0004, 0x00380000,
        0x00280024, 0x0027001F, 0x00200023, 0x00210025, 0x00260000 };
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_2(void) { fzgx_sink_f(0.5f); }
__declspec(section ".fzgxpool") void fzgx_pool_3(void) {
    u32 b[32] = {
        0, 0, 0xC1080000, 0, 0, 0, 0xFF, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0,  /* fzgx-allow: A1 float bits -8.5f in primer data */
        0x3F4CCCCD, 0, 0x43600000, 0x43D00000, 0, 0x43380000, 0x43A00000, 0x43E40000,
        0xFFFF0000, 0x43270000, 0x42180000, 0x42B40000, 0xC1080000, 0x3E99999A };  /* fzgx-allow: A1 float bits -8.5f in primer data */
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_4(void) { fzgx_sink_f(320.0f); }
__declspec(section ".fzgxpool") void fzgx_pool_5(void) {
    u32 b[9] = { 0x43700000, 0x44200000, 0x43F00000, 0x435C0000, 0x425C0000,
                 0x3FE38E39, 0x3DCCCCCD, 0x47AFC800, 0x3FAAAAAB };
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_6(void) { fzgx_sink_f(0.8f); }
__declspec(section ".fzgxpool") void fzgx_pool_7(void) {
    u32 b[3] = { 0x41000000, 0x3F955555, 0x3E800000 };
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_8(void) { fzgx_sink_f(200.0f); }
__declspec(section ".fzgxpool") void fzgx_pool_9(void) {
    u32 b[13] = { 0x40000000, 0x3F400000, 0x437A0000, 0x47800000, 0x41F00000, 0x42200000,
                  0x41700000, 0x44160000, 0x43B20000, 0x42A00000, 0x42C80000, 0x42A40000,
                  0x3F555555 };
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_10(void) { fzgx_sink_f(16.0f); }
__declspec(section ".fzgxpool") void fzgx_pool_11(void) {
    u32 b[4] = { 0x43A40000, 0x43AC8000, 0x3B449BA6, 0x46800000 };
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_12(void) { fzgx_sink_f(60.0f); }
__declspec(section ".fzgxpool") void fzgx_pool_13(void) {
    u32 b[1] = { 0x43B68000 };
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_14(s32 a, u32 b) { fzgx_sink_f((f32)a); fzgx_sink_f((f32)b); }
__declspec(section ".fzgxpool") void fzgx_pool_15(void) {
    u32 b[2] = { 0x3B03126F, 0x3B83126F };
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_16(void) { fzgx_sink_f(-1.0f); fzgx_sink_f(0.5833333134651184f); }
__declspec(section ".fzgxpool") void fzgx_pool_17(void) {
    u32 b[17] = { 0x3DB851EC, 0x40E00000, 0xFFFFFF00, 0x43600000, 0x43080000, 0x3C23D70A,
                  0x3CF5C28F, 0x3D23D70A, 0x3F94C1BB, 0x43450000, 0x42680000, 0x43BA0000,
                  0x38D1B717, 0x41400000, 0x41B00000, 0x41100000, 0x41600000 };
    fzgx_sink_p(b);
}
#pragma section RX ".text" ".text"

#pragma fp_contract off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s8 *fzgx_obj_lbl_7_bss_10;
u32 fzgx_obj_lbl_7_bss_14;
u32 lbl_7_bss_18;
u32 fzgx_obj_lbl_7_bss_1C[11];
u32 fzgx_obj_lbl_7_bss_48[149];
u32 fzgx_obj_lbl_7_bss_29C[1457];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_7_bss_10;
    s = *(u8 *)&fzgx_obj_lbl_7_bss_14;
    s = *(u8 *)&lbl_7_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_7_bss_1C;
    s = *(u8 *)&fzgx_obj_lbl_7_bss_48;
    s = *(u8 *)&fzgx_obj_lbl_7_bss_29C;
}
#pragma section code_type ".text"

void fn_7_3AB0(s32 *arg0) {
    f32 f;
    FontDrawPacket pkt;
    u8 *state;
    f32 t;
    f32 y;
    s32 n;

    state = fn_1_40B14();
    t = (10.0f - *arg0) / 10.0f;
    if (*state == 3) {
        t = 1.0f - t;
    }
    t = t * t;

    pkt = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.x = 320.0f;
    pkt.y = 200.0f;
    pkt.z = 1e-6f;
    pkt.flags = 10;
    pkt.image = 2;
    pkt.alpha = t;
    n = 3.0f * (45.0f * t);
    if (n > 45) {
        n = 45;
    }
    f = 1.1f;
    f *= t;
    if (f > 1.0f) {
        f = 1.0f;
    }
    fn_1_50A90(&pkt, 18, n, 480, (s32)(188.0f * f));

    pkt = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0xBA11;
    pkt.x = 214.0f;
    y = 200.0f - 60.0f * t;
    pkt.y = y;
    pkt.z = 9e-7f;
    pkt.scale_y = t;
    pkt.alpha = t;
    fn_1_4F734(&pkt);

    pkt = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0xBA12;
    pkt.x = 390.0f;
    pkt.y = y;
    pkt.z = 9e-7f;
    pkt.scale_y = t;
    pkt.alpha = t;
    fn_1_51678(&pkt, 0xBA12, fzgx_obj_lbl_7_bss_10[0] * 36, 0, 36, 24);
    fn_1_4F734(&pkt);

    fn_1_49410();
    fn_1_495FC();
    fn_1_4954C(9e-7f);
    fn_1_495C8(1);
    fn_1_49590(0.4f);
    fn_1_4966C(0.0f, 16.0f);
    fn_1_4965C(2);
    fn_1_495B0(0x80000000);
    fn_1_494DC(42);
    fn_1_4955C(0.8f, 0.8f * t);
    fn_1_495A0(t);
    fn_1_496FC(320.0f, 200.0f + 10.0f * t);
    fn_1_4AF64((*(char (*)[])&lbl_7_data_13F20),
               fzgx_pool_init_fzgx_story_table.v[fzgx_obj_lbl_7_bss_10[0]].msg[(*(u32 *)&lbl_801A66B4)][fzgx_obj_lbl_7_bss_10[1]]);

    if (fzgx_obj_lbl_7_bss_10[1] > 0) {
        u32 images[3] = { 0xBA17, 0xBA18, 0xBA19 };
        char *names[3] = { lbl_7_data_13F2C, lbl_7_data_13F34, lbl_7_data_13F3C };

        pkt = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
        pkt.image = 0xBA21;
        pkt.x = 320.0f;
        y = 200.0f - 20.0f * t;
        pkt.y = y;
        pkt.z = 9e-7f;
        pkt.scale_y = t;
        pkt.alpha = t;
        pkt.flags = 11;
        fn_1_4F734(&pkt);
        pkt.rotation_z = -32768;
        fn_1_4F734(&pkt);

        pkt = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
        pkt.image = images[fzgx_obj_lbl_7_bss_10[1]];
        pkt.x = 320.0f;
        pkt.y = y;
        pkt.z = 8e-7f;
        pkt.scale_y = t;
        pkt.alpha = t;
        pkt.flags = 15;
        fn_1_4F734(&pkt);
        pkt.flags = 0x100007;
        fn_1_4F734(&pkt);
        pkt.rotation_z = -32768;
        pkt.flags = 15;
        fn_1_4F734(&pkt);
        pkt.flags = 0x100007;
        fn_1_4F734(&pkt);

        fn_1_49410();
        fn_1_4965C(2);
        fn_1_495C8(1);
        fn_1_495A0(t);
        fn_1_4966C(-1.0f, 0.0f);
        fn_1_4955C(0.5f, 0.5833333134651184f * t);
        fn_1_4954C(9e-7f);
        fn_1_496FC(320.0f, 200.0f - 27.0f * t);
        fn_1_4AE0C((*(char (*)[])&lbl_7_data_13F20), names[fzgx_obj_lbl_7_bss_10[1]]);
    }
}
/* fzgx:end fn_7_3AB0 */

/* fzgx:begin fn_7_3FCC */
struct fn_7_3FCC_lbl_7_bss_18 {
    u32 unk_0;
};
struct fn_7_3FCC_lbl_7_data_12E68 {
    u32 unk_0;
};
struct fn_7_3FCC_lbl_7_bss_1C {
    u32 unk_0;
};
struct fn_7_3FCC_lbl_7_data_12E6C {
    u32 unk_0;
};

extern struct fn_7_3FCC_lbl_7_bss_18 lbl_7_bss_18;


extern struct fn_7_3FCC_lbl_7_data_12E68 lbl_7_data_12E68;
extern struct fn_7_3FCC_lbl_7_data_12E6C lbl_7_data_12E6C;
extern u32 fn_1_426C(u32);
extern u32 fn_1_435C(u32);

void fn_7_3FCC(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t1, t3;
    fn_1_435C(lbl_7_bss_18.unk_0);
    v0 = lbl_7_data_12E68.unk_0;
    v1 = v0;
    if ((s32)v0 != -1) {
    t1 = fn_1_426C(v1);
    v1 = t1;
    lbl_7_data_12E68.unk_0 = -1;
    }
    fn_1_435C((*(struct fn_7_3FCC_lbl_7_bss_1C *)&lbl_7_bss_1C).unk_0);
    v2 = lbl_7_data_12E6C.unk_0;
    v3 = v2;
    if ((s32)v2 != -1) {
    t3 = fn_1_426C(v3);
    v3 = t3;
    lbl_7_data_12E6C.unk_0 = -1;
    }
}
/* fzgx:end fn_7_3FCC */

/* fzgx:begin fn_7_4050 */
void fn_7_4050(void) {
    while (fn_1_467F4() || fn_1_13018()) {
        fn_1_451E4();
        fn_1_D3214();
        VIWaitForRetrace();
    }
}
/* fzgx:end fn_7_4050 */

/* fzgx:begin fn_7_4094 */
extern u32 fn_1_4404(u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 fn_80008E84(u32);





u32 fn_7_4094(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t0, t1, t2;
    t0 = fn_1_4404(arg0);
    v0 = *(u32 *)((u8 *)arg0 + 0);
    v1 = arg2;
    v2 = t0;
    v3 = arg3;
    if ((v0 + 0x10000) != 65535) {
    v3 = (u32)&lbl_801A6410;
    v1 = (u32)&(*(u32 *)&lbl_7_data_13A3C);
    v2 = *(u32 *)((u8 *)v3 + 0);
    v3 = 2443;
    t1 = fn_1_46B4(v2, v0, (u32)v1, v3);
    v2 = t1;
    *(u32 *)((u8 *)arg0 + 0) = -1;
    }
    v2 = t0;
    t2 = fn_80008E84(v2);
    v2 = t2;
    return v2;
}
/* fzgx:end fn_7_4094 */

/* fzgx:begin fn_7_4108 */
#include "rel/story/story_mode.h"

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

typedef struct {
    u8 unk_0;
    u8 pad_1[0x3];
    Obj_7_bss_1960_At4 *unk_4;
    u8 unk_8;
    u8 pad_9[0x3];
    u32 unk_C;
    Color unk_10[2];
    u8 unk_18[2];
    u8 pad_1A[0x2];
    f32 unk_1C[2];
    f32 unk_24[2];
    u8 unk_2C;
    u8 pad_2D[0x3];
    u32 unk_30;
} StoryReset;

extern const Color lbl_7_rodata_780;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_7_bss_1960;
u8 lbl_7_bss_1960_fill_1961;
u16 lbl_7_bss_1960_fill_1962;
Obj_7_bss_1960_At4 *lbl_7_bss_1960_4;
u8 lbl_7_bss_1960_8;
u8 lbl_7_bss_1960_fill_1969;
u16 lbl_7_bss_1960_fill_196A;
u32 lbl_7_bss_1960_C;
Color lbl_7_bss_1960_10[2];
u8 lbl_7_bss_1960_18[2];
u16 lbl_7_bss_1960_fill_197A;
f32 lbl_7_bss_1960_1C[2];
f32 lbl_7_bss_1960_24[2];
u8 lbl_7_bss_1960_2C;
u8 lbl_7_bss_1960_fill_198D;
u16 lbl_7_bss_1960_fill_198E;
u32 lbl_7_bss_1960_30;
u32 lbl_7_bss_1960_fill_1994[55];
u8 lbl_7_bss_1960_fill_1A70;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_7_bss_1960;
    s = *(u8 *)&lbl_7_bss_1960_fill_1961;
    s = *(u8 *)&lbl_7_bss_1960_fill_1962;
    s = *(u8 *)&lbl_7_bss_1960_4;
    s = *(u8 *)&lbl_7_bss_1960_8;
    s = *(u8 *)&lbl_7_bss_1960_fill_1969;
    s = *(u8 *)&lbl_7_bss_1960_fill_196A;
    s = *(u8 *)&lbl_7_bss_1960_C;
    s = *(u8 *)&lbl_7_bss_1960_10;
    s = *(u8 *)&lbl_7_bss_1960_18;
    s = *(u8 *)&lbl_7_bss_1960_fill_197A;
    s = *(u8 *)&lbl_7_bss_1960_1C;
    s = *(u8 *)&lbl_7_bss_1960_24;
    s = *(u8 *)&lbl_7_bss_1960_2C;
    s = *(u8 *)&lbl_7_bss_1960_fill_198D;
    s = *(u8 *)&lbl_7_bss_1960_fill_198E;
    s = *(u8 *)&lbl_7_bss_1960_30;
    s = *(u8 *)&lbl_7_bss_1960_fill_1994;
    s = *(u8 *)&lbl_7_bss_1960_fill_1A70;
}
#pragma section code_type ".text"

static inline void fn_7_4108_loop1(u32 *flags) {
    u32 *p;
    u8 i;
    for (i = 0, p = flags + 0x88; i < 8; i++, p++) {
        *p = 0;
    }
}

#pragma opt_common_subs off
void fn_7_4108(u32 *flags, u32 arg1, u32 arg2) {
    
    Color color[2];
    Color *p_color;
    f32 *p_f2;
    f32 *p_f1;
    u32 *p;
    u8 i;

    p = flags;
    for (i = 0; i < 128; i++, p++) {
        *p = 0;
    }
    fn_7_4108_loop1(flags);
    {
    u32 * fzgx_loop_p_2379;
for (fzgx_loop_p_2379 = flags + 0x80, i = 0; i < 8; i++, fzgx_loop_p_2379++) {
        *fzgx_loop_p_2379 = -1;
    }
    p = fzgx_loop_p_2379;
}

    p_color = lbl_7_bss_1960_10;
    p_f2 = lbl_7_bss_1960_24;
    p_f1 = lbl_7_bss_1960_1C;

    lbl_7_bss_1960_4 = (Obj_7_bss_1960_At4 *)arg2;
    lbl_7_bss_1960_8 = 0;
    lbl_7_bss_1960_C = 0;
    fzgx_obj_lbl_7_bss_1960 = 0;
    color[0] = lbl_7_rodata_780;
    color[1] = lbl_7_rodata_780;
    for (i = 0; i < 2; i++) {
        p_color[i] = ((i)[color]);
        (lbl_7_bss_1960_18)[i] = 0;
        p_f2[i] = lbl_7_rodata_784;
        p_f1[i] = lbl_7_rodata_784;
    }
    lbl_7_bss_1960_2C = 0;
    lbl_7_bss_1960_30 = arg1;
}
#pragma opt_common_subs reset
/* fzgx:end fn_7_4108 */

/* fzgx:begin fn_7_41FC */
#include "rel/story/story_mode.h"

typedef struct fn_7_41FC_StoryTrigger {
    u16 type;
    u8 pad_2[0x16];
} fn_7_41FC_StoryTrigger;

extern s32 fn_7_4648(u32 *, fn_7_41FC_StoryTrigger *);
extern u32 fn_7_4FD0(u32 *, fn_7_41FC_StoryTrigger *);
extern void OSReport(const char *, ...);

static inline f32 clamp_value(f32 x) {
    if (x < lbl_7_rodata_784) return lbl_7_rodata_784;
    if (x > lbl_7_rodata_788[0]) return lbl_7_rodata_788[0];
    return x;
}

#pragma opt_propagation off
void fn_7_41FC(u32 *flags) {
    Obj_7_bss_1960 *g = &lbl_7_bss_1960;
    fn_7_41FC_StoryTrigger *t;
    s32 *timer;
    u32 i;
    u32 n;
    s32 ok;

    t = (fn_7_41FC_StoryTrigger *)g->unk_30;
    timer = (s32 *)(flags + 0x80);
    for (i = 0; i < 8; i++, timer++) {
        if (!__rlwnm(g->unk_C, (i + 1) & 31, 31, 31) && *timer >= 0) {
            (*timer)--;
        }
    }

    n = 0;
    while (t->type != 5) {
        ok = 1;
        while (t->type <= 3) {
            if (n >= 0x1000) {
                OSReport("Too Many Scenario Trigger\n\n");
                return;
            }
            if (__rlwnm(flags[n >> 5], ((n & 31) + 1) & 31, 31, 31)) {
                ok = 0;
                break;
            }
            if (t->type == 2 || t->type == 3) {
                if (fn_7_4648(flags, t)) {
                    ok = 0;
                    break;
                }
            } else if (!fn_7_4648(flags, t)) {
                ok = 0;
                break;
            }
            t++;
            n++;
        }
        if (ok) {
            fn_7_41FC_StoryTrigger *p = t - 1;
            u32 j = n - 1;
            while (p->type <= 3 && j != -1) {
                if (p->type == 0 || p->type == 2) {
                    flags[j >> 5] |= 0x80000000U >> (j & 31);
                }
                p--;
                j--;
            }
            while (t->type == 4) {
                fn_7_4FD0(flags, t);
                t++;
            }
        } else {
            while (t->type <= 3) {
                t++;
                n++;
            }
            while (t->type == 4) {
                t++;
            }
        }
    }

    {
        u8 *active = &g->unk_18;
        f32 *pos;
        f32 *vel;
        u8 k;
        for (k = 0; k < 2; k++) {
            if (active[k]) {
                pos = &g->unk_1C;
                vel = &g->unk_24;
                pos[k] = pos[k] + vel[k];
                pos[k] = clamp_value(pos[k]);
            }
        }
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_7_41FC */

/* fzgx:begin fn_7_44DC */
#include "font.h"

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_7_bss_1960[4];
u32 lbl_7_bss_1960__fzgx_offset_10[2];
u8 lbl_7_bss_1960__fzgx_offset_18[2];
f32 lbl_7_bss_1960__fzgx_offset_1C[2];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = ((0)[fzgx_obj_lbl_7_bss_1960]);
    s = lbl_7_bss_1960__fzgx_offset_10[0];
    s = lbl_7_bss_1960__fzgx_offset_18[0];
    s = lbl_7_bss_1960__fzgx_offset_1C[0];
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 300.0f;
    s = 640.0f;
    s = 480.0f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"


extern u16 fn_1_48690(u32);
extern int fn_1_4F734(FontDrawPacket *);

#pragma opt_propagation off
#pragma peephole on
#pragma opt_common_subs on
void fn_7_44DC(void) {
    u16 v1;
    u8 i;

    i = 0;
    while (i < 2) {
        v1 = (u16)(i);
        if (lbl_7_bss_1960__fzgx_offset_18[v1] != 0) {
{
    FontDrawPacket loc_8;
            loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            loc_8.image = 18;
            loc_8.x = 0.0f;
            loc_8.y = 0.0f;
            loc_8.z = 300.0f - (f32)i;
            loc_8.flags = 5;
{
    s16 t0;
            loc_8.scale_x = loc_8.scale_x * (640.0f / (f32)(fn_1_48690(18)));
}
{
    u32 t1;
    f32 r;
            r = 480.0f / (f32)fn_1_48690(18);
            loc_8.scale_y = loc_8.scale_y * r;
            *(u32 *)((u8 *)&loc_8 + 0x38) = lbl_7_bss_1960__fzgx_offset_10[v1];
            loc_8.alpha = lbl_7_bss_1960__fzgx_offset_1C[v1];
}
            fn_1_4F734(&loc_8);
}
        }
        i++;
    }
}
#pragma opt_common_subs reset

#pragma peephole reset

#pragma opt_propagation reset
/* fzgx:end fn_7_44DC */

/* fzgx:begin fn_7_4648 noprologue */
#include "types.h"

#include "rel/story/story_mode.h"

typedef struct {
    f32 x, y, z;
} StoryVec;
typedef struct {
    u8 pad_0[0x200];
    s32 unk_200[8];
    s32 unk_220[8];
    u32 unk_240;
    u32 unk_244;
    s16 unk_248;
} StoryTriggerContext;
typedef struct {
    u16 unk_0;
    u16 unk_2;
    s32 unk_4, unk_8, unk_C, unk_10;
    f32 unk_14;
} StoryTrigger;
typedef struct {
    u32 unk_0;
    u8 pad_4[0x78];
    StoryVec unk_7C;
    u8 pad_88[0xF4];
    f32 unk_17C;
    u8 pad_180[4];
    f32 unk_184;
    u8 pad_188[0x2FA];
    u8 unk_482;
} StoryVehicle;
typedef struct {
    u8 pad_0[0x54];
    StoryVec unk_54;
    u8 pad_60[0xD8];
    u64 unk_138;
} StoryEventObject;
typedef struct {
    u8 pad_0[0x1EC];
    u8 unk_1EC;
    u8 unk_1ED;
    u16 unk_1EE;
} StoryTime;
typedef struct {
    u8 pad_0[0x115];
    u8 unk_115;
    u8 pad_116[2];
    s32 unk_118;
} StoryPlayer;
typedef struct {
    u8 pad_0[0x2C];
    StoryPlayer *unk_2C[4];
} StoryPlayerList;
typedef struct {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[0xA];
} StoryInput;
extern StoryInput lbl_1_bss_9F8[];
typedef struct {
    u8 pad_0[8];
    u16 hi : 6;
    u16 b9 : 1;
    u16 b8 : 1;
    u16 lo : 8;
    u8 pad_A[0xA];
} StoryInputBits;
/* view of StoryInput starting at its button word */
typedef struct {
    u16 unk_0;
    u8 pad_2[0x12];
} StoryButtons;
extern s32 fn_7_4E28(s32, s32, s32);
extern s32 fn_7_4EF8(u32, f32, f32);
extern f64 lbl_7_rodata_798[6];
extern s16 fn_1_3F0C8(void);
extern u8 fn_1_86810(int);
extern StoryVehicle *fn_1_86254(s32);
extern void OSReport(const char *, ...);
extern StoryTime *fn_1_8627C(s32);
extern s16 fn_1_E5568(s16);
extern StoryEventObject *fn_1_E54A8(s16, s16);
extern u32 fn_1_E57C4(void *);
extern s16 fn_1_E5430(s16);
extern u32 fn_1_8C66C(u32);
extern f32 fn_1_8C6A0(u32);
extern u32 fn_1_F1B94(void);

#pragma opt_propagation off
static inline s32 storyButtonEither(u16 buttons) {
    switch (__rlwinm(buttons, 24, 31, 31) | __rlwinm(buttons, 23, 31, 31)) {
    default: return 1;
    case 0: return 0;
    }
}

static inline f32 storyDistanceSquared(const StoryVec *a, const StoryVec *b) {
    f32 x = a->x;
    f32 y = a->y;
    f32 z = a->z;
    f32 result;
    x -= b->x;
    y -= b->y;
    z -= b->z;
    result = x*x;
    result += y*y;
    result += z*z;
    return result;
}

#pragma opt_propagation off
#pragma opt_lifetimes off
#pragma opt_common_subs off
s32 fn_7_4648(StoryTriggerContext *context, StoryTrigger *arg1, f32 arg2) {
    Obj_7_bss_1960 *p_lbl_7_bss_1960;
    u16 v0;
    s32 v1;
    f32 v2;
    StoryTrigger *trigger;
    trigger = arg1;
    v0 = arg1->unk_2;
    p_lbl_7_bss_1960 = &lbl_7_bss_1960;
    v1 = 0;
    v2 = arg2;
    switch (v0) {
    case 0: {
        u32 *flags = (u32 *)trigger->unk_4;
        s32 truth;
        switch ((s32)flags) {
        case 0: flags = &context->unk_244; break;
        case 1: flags = &context->unk_240; break;
        }
        if ((u32)flags + 0x10000 == 0xFFFF) {
            v1 = 1;
            break;
        }
        truth = trigger->unk_8;
        if (*flags & trigger->unk_C) v1 = truth;
        else v1 = !truth;
        break;
    }
    case 1:
        v1 = fn_7_4E28(trigger->unk_8, context->unk_220[trigger->unk_4], trigger->unk_C);
        break;
    case 6:
        if (p_lbl_7_bss_1960->unk_4->unk_D == 0) v1 = 1;
        break;
    case 2:
        if (fn_1_3F0C8() == 0x29) v1 = 1;
        break;
    case 3:
        if (p_lbl_7_bss_1960->unk_4->unk_C != 0) v1 = 1;
        break;
    case 4: {
        StoryPlayerList *slot = (StoryPlayerList *)((u8 *)p_lbl_7_bss_1960->unk_4 + fn_1_86810(p_lbl_7_bss_1960->unk_34) * 4);
        if (slot->unk_2C[0]->unk_115 == 0) v1 = 1;
        break;
    }
    case 5: {
        s32 value = trigger->unk_8;
        switch (trigger->unk_4) {
        case 0:
            if (fn_1_86254(value)->unk_0 & 0x80) v1 = 1;
            break;
        case 1:
            if (fn_1_86254(p_lbl_7_bss_1960->unk_34)->unk_482 >= value) v1 = 1;
            break;
        default:
            OSReport((char *)lbl_7_data_13FFC);
            break;
        }
        break;
    }
    case 7: {
        s32 kind = trigger->unk_4;
        s32 op = trigger->unk_8;
        s32 value = trigger->unk_C;
        s32 current;
        if (kind == 8) {
            StoryTime *time = fn_1_8627C(p_lbl_7_bss_1960->unk_34);
            s32 minutes;
            s32 seconds;
            s32 milliseconds = time->unk_1EE;
            seconds = time->unk_1ED * 1000;
            minutes = time->unk_1EC * 60000;
            current = minutes + milliseconds;
            current = seconds + current;
            value = value * 1000 / 60;
        } else {
            current = context->unk_200[kind];
        }
        v1 = fn_7_4E28(op, current, value);
        break;
    }
    case 8: {
        s32 b;
        s32 a;
        s32 c;
        f32 radius;
        a = trigger->unk_8;
        b = trigger->unk_C;
        c = trigger->unk_10;
        radius = trigger->unk_14;
        switch (trigger->unk_4) {
        case 0:
            v1 = fn_7_4E28(b, fn_1_E5568((s16)a), c);
            break;
        case 1:
            if (b == -1) {
                b = (32 - c) & 31;
                for (c = 0; c < fn_1_E5430((s16)a); c++) {
                    if (__rlwnm(fn_1_E57C4(fn_1_E54A8((s16)a, (s16)c)), b, 31, 31)) {
                        v1 = 1;
                        break;
                    }
                }
            } else {
                v1 = __rlwnm(fn_1_E57C4(fn_1_E54A8((s16)a, (s16)b)), (32 - c) & 31, 31, 31) ? 1 : 0;
            }
            break;
        case 2:
            if (b == -1) {
                for (b = 0; b < fn_1_E5430((s16)a); b++) {
                    u32 flags = fn_1_E57C4(fn_1_E54A8((s16)a, (s16)b));
                    if (flags & c) {
                        v1 = 1;
                        break;
                    }
                }
            } else {
                u32 flags = fn_1_E57C4(fn_1_E54A8((s16)a, (s16)b));
                v1 = (flags & c) != 0;
            }
            break;
        case 3: {
            u64 flags = fn_1_E54A8((s16)a, (s16)b)->unk_138;
            if (flags & (s64)c) v1 = 1;
            break;
        }
        case 4: {
            u64 flags = fn_1_E54A8((s16)a, (s16)b)->unk_138;
            if (flags & ((s64)c << 32)) v1 = 1;
            break;
        }
        case 5: {
            StoryEventObject *object = fn_1_E54A8((s16)a, (s16)b);
            StoryVehicle *vehicle = fn_1_86254(c);
            v1 = fn_7_4EF8(4, storyDistanceSquared(&object->unk_54, &vehicle->unk_7C), radius*radius);
            break;
        }
        default:
            OSReport((char *)lbl_7_data_13FFC);
            break;
        }
        break;
    }
    case 9: {
        s32 op = trigger->unk_8;
        f32 value = trigger->unk_14;
        StoryVehicle *vehicle = fn_1_86254(trigger->unk_4);
        v1 = fn_7_4EF8(op, vehicle->unk_17C, value);
        break;
    }
    case 10: {
        s32 id = trigger->unk_4;
        StoryVec *pos = (StoryVec *)trigger->unk_8;
        s32 op = trigger->unk_C;
        f32 radius = trigger->unk_14;
        StoryVehicle *vehicle;
        if ((s32)pos == 0) pos = &fn_1_86254(p_lbl_7_bss_1960->unk_34)->unk_7C;
        vehicle = fn_1_86254(id);
        v1 = fn_7_4EF8(op, storyDistanceSquared(pos, &vehicle->unk_7C), radius*radius);
        break;
    }
    case 11: {
        s32 id;
        s32 op;
        s32 other;
        f32 value;
        s32 current;
        id = trigger->unk_4;
        op = trigger->unk_C;
        value = trigger->unk_14;
        switch (trigger->unk_8) {
        case 0:
            current = fn_1_8C66C(id);
            v1 = fn_7_4E28(op, current, trigger->unk_10);
            break;
        case 1:
            current = fn_1_8C66C(id);
            v1 = fn_7_4E28(op, current, *(s32 *)trigger->unk_10);
            break;
        case 2: {
            other = trigger->unk_10;
            current = fn_1_8C66C(id);
            if (other == current) {
                f32 f = fn_1_8C6A0(id);
                v1 = fn_7_4EF8(op, f, value);
            }
            break;
        }
        default:
            OSReport((char *)lbl_7_data_13FFC);
            break;
        }
        break;
    }
    case 12: {
        s32 kind;
        s32 op;
        s32 id;
        f32 value;
        f32 current;
        StoryVehicle *vehicle;
        id = trigger->unk_4;
        kind = trigger->unk_8;
        op = trigger->unk_C;
        value = trigger->unk_14;
        vehicle = fn_1_86254(id);
        switch (kind) {
        case 0: current = vehicle->unk_184; break;
        case 1: current = (f32)fn_1_86810(id); break;
        default: OSReport((char *)lbl_7_data_13FFC); break;
        }
        v1 = fn_7_4EF8(op, current, value);
        break;
    }
    case 13: {
        s32 truth = trigger->unk_8;
        s32 mask = trigger->unk_C;
        u32 flags = fn_1_86254(trigger->unk_4)->unk_0;
        if (flags & mask) v1 = truth;
        else v1 = !truth;
        break;
    }
    case 14:
        switch (trigger->unk_4) {
        case 0: {
            StoryButtons *buttonBase = (StoryButtons *)&lbl_1_bss_9F8[0].unk_8;
            u16 buttons = buttonBase[p_lbl_7_bss_1960->unk_35].unk_0;
            v1 = storyButtonEither(buttons);
            break;
        }
        case 1: {
            u32 pressed = __rlwinm(lbl_1_bss_9F8[p_lbl_7_bss_1960->unk_35].unk_8, 24, 31, 31);
            v1 = pressed;
            break;
        }
        case 2: {
            u32 pressed = __rlwinm(lbl_1_bss_9F8[p_lbl_7_bss_1960->unk_35].unk_8, 23, 31, 31);
            v1 = pressed;
            break;
        }
        }
        break;
    case 15: {
        s32 op = trigger->unk_8;
        s32 value = trigger->unk_C;
        StoryPlayerList *slot = (StoryPlayerList *)((u8 *)p_lbl_7_bss_1960->unk_4 + fn_1_86810(trigger->unk_4) * 4);
        StoryPlayer *player = slot->unk_2C[0];
        v1 = fn_7_4E28(op, player->unk_118, value);
        break;
    }
    case 16:
        v1 = fn_7_4E28(trigger->unk_4, context->unk_248, trigger->unk_8);
        break;
    case 17: {
        s32 id = trigger->unk_4;
        v1 = (fn_1_F1B94() == id) ? 1 : 0;
        break;
    }
    }
    return v1;
}
/* fzgx:end fn_7_4648 */

/* fzgx:begin fn_7_4E28 */
extern void OSReport(char *, ...);

s32 fn_7_4E28(s32 arg0, s32 arg1, s32 arg2) {
    s32 result;

    result = 0;
    switch (arg0) {
    case 0:
        if (arg1 == arg2) {
            result = 1;
        }
        break;
    case 1:
        if (arg1 != arg2) {
            result = 1;
        }
        break;
    case 2:
        if (arg1 >= arg2) {
            result = 1;
        }
        break;
    case 3:
        if (arg1 > arg2) {
            result = 1;
        }
        break;
    case 4:
        if (arg1 <= arg2) {
            result = 1;
        }
        break;
    case 5:
        if (arg1 < arg2) {
            result = 1;
        }
        break;
    default:
        OSReport((*(char (*)[15])&lbl_7_data_13FFC));
        break;
    }
    return result;
}
/* fzgx:end fn_7_4E28 */

/* fzgx:begin fn_7_4EF8 */
extern void OSReport(char *, ...);

s32 fn_7_4EF8(u32 arg0, f32 arg1, f32 arg2) {
    s32 result;

    result = 0;
    switch ((s32)arg0) {
    case 0:
        if (arg1 == arg2) {
            result = 1;
        }
        break;
    case 1:
        if (arg1 != arg2) {
            result = 1;
        }
        break;
    case 2:
        if (arg1 >= arg2) {
            result = 1;
        }
        break;
    case 3:
        if (arg1 > arg2) {
            result = 1;
        }
        break;
    case 4:
        if (arg1 <= arg2) {
            result = 1;
        }
        break;
    case 5:
        if (arg1 < arg2) {
            result = 1;
        }
        break;
    default:
        OSReport((*(char (*)[15])&lbl_7_data_13FFC));
        break;
    }
    return result;
}
/* fzgx:end fn_7_4EF8 */

/* fzgx:begin fn_7_4FD0 noprologue */
#include "types.h"

#include "rel/story/story_mode.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/globals.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
#include "game/vec3.h"
#include "game/vec3.h"
#include "game/main_rel/adxt_stop_types.h"

#ifndef REL_MAIN_REL_GAME_H
#define REL_MAIN_REL_GAME_H

// lbl_1_bss_6EAD0: .bss size 0x708, 6 refs from game.c
#ifndef FZGX_TYPES_LBL_1_BSS_6EAD0
#define FZGX_TYPES_LBL_1_BSS_6EAD0
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u32 unk_0;  // 23 loads, 0 stores
    u32 unk_4;  // 9 loads, 0 stores
} Obj_1_bss_6EAD0_At0;
typedef struct {
    Obj_1_bss_6EAD0_At0 *unk_0;  // 34 loads, 0 stores
    u8 pad_4[0x704];
} Obj_1_bss_6EAD0;
#endif
extern Obj_1_bss_6EAD0 lbl_1_bss_6EAD0;

// lbl_1_bss_9C: .bss size 0x1, 2 refs from game.c
extern u8 lbl_1_bss_9C;

#endif  // REL_MAIN_REL_GAME_H
#ifndef GAME_MAIN_REL_CAR_TYPES_H
#define GAME_MAIN_REL_CAR_TYPES_H
#ifndef REL_MAIN_REL_CAR_H
#define REL_MAIN_REL_CAR_H

#endif  // REL_MAIN_REL_CAR_H


typedef struct Fn1967A8Resource Fn1967A8Resource;

struct Fn1967A8Resource {
    u8 unk_00;
    u8 unk_01[0x07];
    u32 unk_08;
    u8 unk_0C[0x10];
    u32 unk_1C;
};


typedef struct {
    u8 pad_0[0x118];
    u32 unk_118;
    u32 unk_11C;
    u8 pad_120[0x20];
    s32 unk_140;
    f32 unk_144;
    f32 unk_148;
    f32 unk_14C;
    f32 unk_150;
} CarSound;

typedef struct {
    u32 flags;
    u8 pad_4[0x498];
    CarSound *sound;
} fn_1_85F90_Car;

extern void fn_1_41F58(Fn1967A8Resource *arg0, s32 arg1, void (*arg2)(void), void *arg3);

#endif  // GAME_MAIN_REL_CAR_TYPES_H

/* end game/main_rel/car_types.h */

extern int fn_1_4C10(void);
extern int fn_1_4CAC(void);
extern int fn_1_40F44(void);
extern void OSReport(const char *, ...);
extern u32 fn_1_3ED8C(u32,u32,u32,u32,u32,u32,u32);
extern u32 fn_1_3F4B8(u32,u32,u32,u32,u32,u32);
extern u32 fn_1_3EB78(u32,void *,void *,void *);
extern u32 fn_1_3EA90(u32,void *,void *,void *);
extern void *fn_1_E54A8(s16,s16);
extern s16 fn_1_E5430(s16);
extern void *fn_1_86254(s32);
extern void fn_1_86194(f32);
typedef struct Sig_fn_1_24F10_Fn_1_24F10 {
    int flags; u8 pad04[0x2c]; f32 field30; u8 pad34[0x150]; f32 field184;
    u8 pad188[0x8c]; u16 field214; u8 pad216[0xe]; f32 field224;
    u8 pad228[0x284]; f32 field4ac; u8 pad4b0[0xe3]; u8 field593;
    u8 pad594[0x46]; u16 field5da;
} Sig_fn_1_24F10_Fn_1_24F10;
extern int fn_1_24F10(Sig_fn_1_24F10_Fn_1_24F10 *,f32);
typedef struct { u8 pad[0x3bc]; u32 value; } Sig_fn_1_8E448_fn_1_8E448_Object;
extern Sig_fn_1_8E448_fn_1_8E448_Object *fn_1_868C0(s8);
extern void fn_1_8E448(Sig_fn_1_8E448_fn_1_8E448_Object *,u32);
extern void *fn_1_8627C(s32);
extern u32 fn_1_864E8(s32);
extern void fn_1_85F90(fn_1_85F90_Car *,void *,f32,f32,f32,f32);
extern void fn_1_8B880(void);
extern void *fn_1_214C4(void *,u32,f32);
extern u32 fn_1_17920(void *,u32,f32);
extern u8 *fn_1_14F04(void);
struct Sig_fn_1_207DC_A {
    u8 pad_0[0x30]; f32 unk_30; f32 unk_34; u8 pad_38[4]; f32 unk_3C;
    u8 pad_40[0x28]; f32 unk_68; f32 unk_6C; u8 pad_70[0xC]; u32 unk_7C;
};
extern void fn_1_207DC(struct Sig_fn_1_207DC_A *,void *,f32);
typedef struct Sig_fn_1_25004_Fn_1_25004_Obj {
    u32 flags00; s16 field04; u8 pad06[0x8e]; f32 field94; f32 field98; f32 field9c;
    f32 fielda0; f32 fielda4; f32 fielda8; u8 padac[0xd0]; f32 field17c;
    u8 pad180[4]; f32 field184; u8 pad188[0x9c]; f32 field224;
    u8 pad228[0x24c]; u8 field474; u8 pad475[0x117]; u32 flags58c;
} Sig_fn_1_25004_Fn_1_25004_Obj;
extern void fn_1_25004(Sig_fn_1_25004_Fn_1_25004_Obj *);
extern void fn_1_8D988(void);
extern void fn_1_8DAB4(void);
extern void camera_set_entry_field_0xa8(u8,s16);
extern s32 fn_1_3F1AC(void);
extern void fn_1_A2D84(u32);
extern u32 fn_1_A1588(Sig_ADXT_Stop_ADXTHandle *,u32);

extern void *lbl_1_bss_84[];

extern u32 lbl_1_bss_6F23C;

typedef struct { u8 pad[4]; f32 f4,f8,fc,f10,f14; u8 pad18[8]; f32 f20; u8 pad24[0x1c]; f32 f40; u8 pad44[0x70]; } CarSpec;
extern CarSpec lbl_1_data_28060[];

typedef struct { f32 x,y,z; } ActionVec;
typedef struct { u8 r,g,b,a; } ActionColor;
typedef struct { u32 flags; u8 pad4[0x2e]; u8 mode; } CarControl;
typedef struct {
    u32 flags; s16 field4; s16 field6; f32 field8,fieldc,field10,field14;
    u8 pad18[0x7c]; ActionVec field94,fielda0; u8 padac[0xd0];
    f32 field17c; f32 field180; f32 field184; u8 pad188[0x98];
    f32 field220,field224,field228,field22c; u8 pad230[0xc]; f32 field23c;
    u8 pad240[0x244]; CarControl *field484; u8 pad488[0x14]; void *field49c;
    u8 pad4a0[0x13a]; u16 field5da;
} ActionCar;
typedef struct { u8 pad[0xe]; s16 fieldE; u8 pad10[0x128]; u32 flags138,flags13c; } FlagObject;
typedef struct { u8 pad[0x390]; u32 flags390; } Racer;
typedef struct { u8 pad[0x200]; s32 vars[8]; s32 vars2[8]; u32 flags240,flags244; } ActionState;
typedef struct { u16 unk0,opcode; s32 op,index,value,extra; f32 amount; } ActionCommand;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_7_bss_1960;
u8 lbl_7_bss_1960_fill_1961;
u16 lbl_7_bss_1960_fill_1962;
Obj_7_bss_1960_At4 *lbl_7_bss_1960_4;
u8 lbl_7_bss_1960_8;
u8 lbl_7_bss_1960_fill_1969;
u16 lbl_7_bss_1960_fill_196A;
u32 lbl_7_bss_1960_C;
u32 lbl_7_bss_1960_10;
u32 lbl_7_bss_1960_fill_1974;
u8 lbl_7_bss_1960_18;
u8 lbl_7_bss_1960_fill_1979;
u16 lbl_7_bss_1960_fill_197A;
f32 lbl_7_bss_1960_1C;
u32 lbl_7_bss_1960_fill_1980;
f32 lbl_7_bss_1960_24;
u32 lbl_7_bss_1960_fill_1988;
u8 lbl_7_bss_1960_2C;
u8 lbl_7_bss_1960_fill_198D;
u16 lbl_7_bss_1960_fill_198E;
u32 lbl_7_bss_1960_fill_1990;
u8 lbl_7_bss_1960_34;
u8 lbl_7_bss_1960_35;
u8 lbl_7_bss_1960_36;
u8 lbl_7_bss_1960_37;
u8 lbl_7_bss_1960_38;
u8 lbl_7_bss_1960_39;
u8 lbl_7_bss_1960_3A;
u8 lbl_7_bss_1960_fill_199B;
u32 lbl_7_bss_1960_3C;
/* slot tables: 4 player slots, 30 object slots */
u8 lbl_7_bss_1960_40[4];
u8 lbl_7_bss_1960_44[4];
u32 lbl_7_bss_1960_48[4];
u8 lbl_7_bss_1960_58[30];
u8 lbl_7_bss_1960_78[30];
u32 lbl_7_bss_1960_98[30];
u8 lbl_7_bss_1960_fill_1A70;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_7_bss_1960;
    s = *(u8 *)&lbl_7_bss_1960_fill_1961;
    s = *(u8 *)&lbl_7_bss_1960_fill_1962;
    s = *(u8 *)&lbl_7_bss_1960_4;
    s = *(u8 *)&lbl_7_bss_1960_8;
    s = *(u8 *)&lbl_7_bss_1960_fill_1969;
    s = *(u8 *)&lbl_7_bss_1960_fill_196A;
    s = *(u8 *)&lbl_7_bss_1960_C;
    s = *(u8 *)&lbl_7_bss_1960_10;
    s = *(u8 *)&lbl_7_bss_1960_fill_1974;
    s = *(u8 *)&lbl_7_bss_1960_18;
    s = *(u8 *)&lbl_7_bss_1960_fill_1979;
    s = *(u8 *)&lbl_7_bss_1960_fill_197A;
    s = *(u8 *)&lbl_7_bss_1960_1C;
    s = *(u8 *)&lbl_7_bss_1960_fill_1980;
    s = *(u8 *)&lbl_7_bss_1960_24;
    s = *(u8 *)&lbl_7_bss_1960_fill_1988;
    s = *(u8 *)&lbl_7_bss_1960_2C;
    s = *(u8 *)&lbl_7_bss_1960_fill_198D;
    s = *(u8 *)&lbl_7_bss_1960_fill_198E;
    s = *(u8 *)&lbl_7_bss_1960_fill_1990;
    s = *(u8 *)&lbl_7_bss_1960_34;
    s = *(u8 *)&lbl_7_bss_1960_35;
    s = *(u8 *)&lbl_7_bss_1960_36;
    s = *(u8 *)&lbl_7_bss_1960_37;
    s = *(u8 *)&lbl_7_bss_1960_38;
    s = *(u8 *)&lbl_7_bss_1960_39;
    s = *(u8 *)&lbl_7_bss_1960_3A;
    s = *(u8 *)&lbl_7_bss_1960_fill_199B;
    s = *(u8 *)&lbl_7_bss_1960_3C;
    s = *(u8 *)lbl_7_bss_1960_40;
    s = *(u8 *)lbl_7_bss_1960_44;
    s = *(u8 *)lbl_7_bss_1960_48;
    s = *(u8 *)lbl_7_bss_1960_58;
    s = *(u8 *)lbl_7_bss_1960_78;
    s = *(u8 *)lbl_7_bss_1960_98;
    s = *(u8 *)&lbl_7_bss_1960_fill_1A70;
}
#pragma section code_type ".text"

static const u32 pool_head[1]={0};

#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer(volatile f32 *p,volatile u32 *w,u32 n) { /* fzgx-allow: S2 retail literal-pool layout primer */
    w[0]=pool_head[0];
    p[0]=0.0f; p[1]=1.0f; p[2]=300.0f; p[3]=640.0f; p[4]=480.0f;
    p[5]=(f32)n;
}
#pragma section code_type ".text"

static const u32 pool_color0[1]={0};
static const u32 pool_color1[1]={0};
static const u32 pool_color2[1]={0};
static const u32 pool_color4[1]={0x40000000};
static const u32 pool_color3[1]={0x40000000};

#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer2(volatile f32 *p,volatile u32 *w,s32 sn) { /* fzgx-allow: S2 retail literal-pool layout primer */
    w[1]=pool_color0[0]; w[2]=pool_color1[0]; w[3]=pool_color2[0];
    w[4]=pool_color4[0]; w[5]=pool_color3[0];
    p[6]=100.0f; p[7]=-10000000.0f; p[8]=(f32)sn;
}
#pragma section code_type ".text"

static inline void set_slot(u8 *a,u8 *b,u32 *c,s32 slot,u32 x,u32 y,u32 flags) {
    a[slot]=x;
    b[slot]=y;
    c[slot]=flags;
}
static inline void clear_object_flags(FlagObject *obj,u32 high,u32 low) {
    *(u64 *)&obj->flags138 &= ~(((u64)high << 32) | low);
}
#pragma opt_dead_assignments off
void fn_7_4FD0(ActionState *arg0,ActionCommand *arg1,f32 arg2) {
    s32 i;
    s32 j;
    s32 end;
    s32 first;
    s32 op;
    s32 index;
    s32 value;
    s32 extra;
    s32 fzgx_loop_i_14578;
    s32 fzgx_loop_i_19806;
    s32 fzgx_loop_i_18323;
    s32 fzgx_loop_i_16747;
    if ((fn_1_4C10()!=0 && fn_1_4CAC()==0) || fn_1_40F44()!=0)
        lbl_7_bss_1960_2C=1;
    switch (arg1->opcode) {
    case 0:
        op=arg1->op; index=arg1->index; value=arg1->value;
        switch(op) {
        case 0:
            if(index<8) arg0->vars[index]=value;
            else if(index==9) for(i=0;i<8;i++) arg0->vars[i]=value;
            break;
        case 1:
            if(index<8) arg0->vars[index]+=value;
            else if(index==9) for(i=0;i<8;i++) arg0->vars[i]+=value;
            break;
        case 2:
            if(index<8) {
                if(value) lbl_7_bss_1960_C |= 0x80000000U >> index;
                else lbl_7_bss_1960_C &= ~(0x80000000U >> index);
            } else if(index==9) {
                {
    s32 fzgx_loop_i_9184;
for(fzgx_loop_i_9184=0;fzgx_loop_i_9184<8;fzgx_loop_i_9184++) {
                    if(value) lbl_7_bss_1960_C |= 0x80000000U >> index;
                    else lbl_7_bss_1960_C &= ~(0x80000000U >> index);
                }
    i = fzgx_loop_i_9184;
}
            }
            break;
        default: OSReport((char *)lbl_7_data_14054); break;
        }
        break;
    case 20:
        op=arg1->op; index=arg1->index; value=arg1->value;
        switch(op) {
        case 0:
            if(index<8) arg0->vars2[index]=value;
            else if(index==8) for(i=0;i<8;i++) arg0->vars2[i]=value;
            break;
        case 1:
            if(index<8) arg0->vars2[index]+=value;
            else if(index==8) for(i=0;i<8;i++) arg0->vars2[i]+=value;
            break;
        default: OSReport((char *)lbl_7_data_14054); break;
        }
        break;
    case 1:
        op=arg1->op; index=arg1->index;
        switch(op) {
        case 1: lbl_7_bss_1960_36=index; break;
        case 2: lbl_7_bss_1960_37=index; break;
        case 3: lbl_7_bss_1960_38=index; break;
        case 0: lbl_7_bss_1960_39=index; break;
        case 4: lbl_7_bss_1960_8=index; break;
        case 5: lbl_7_bss_1960_3A=index; break;
        case 6: lbl_7_bss_1960_3C=index; break;
        default: OSReport((char *)lbl_7_data_14054); break;
        }
        break;
    case 2:
        fn_1_3ED8C(0,lbl_7_bss_1960_37,1,lbl_7_bss_1960_36,
            lbl_7_bss_1960_39,lbl_7_bss_1960_38,lbl_7_bss_1960_3C);
        if(lbl_7_bss_1960_8)
            fn_1_3F4B8(lbl_7_bss_1960_8,lbl_7_bss_1960_3A,0,0,0,0);
        break;
    case 3:
        for(i=0;i<4;i++) {
            lbl_7_bss_1960_40[i]=255;
            lbl_7_bss_1960_44[i]=255;
            lbl_7_bss_1960_48[i]=0;
        }
        for(j=0;j<30;j++) {
            lbl_7_bss_1960_58[j]=255;
            lbl_7_bss_1960_78[j]=255;
            lbl_7_bss_1960_98[j]=0;
        }
        break;
    case 4:
        lbl_7_bss_1960_35=*(u8 *)arg1->op;
        break;
    case 5: {
        s32 op,index,value;
        u8 *scan;
        op=arg1->op; index=arg1->index; value=arg1->value;
        switch(op) {
        case 0:
            lbl_7_bss_1960_34=0;
            set_slot(lbl_7_bss_1960_40,lbl_7_bss_1960_44,lbl_7_bss_1960_48,lbl_7_bss_1960_35,index,value,0);
            break;
        case 1:
            {
    s32 fzgx_loop_i_11476;
for(fzgx_loop_i_11476=0,scan=lbl_7_bss_1960_58;fzgx_loop_i_11476<30 && *scan!=255;scan++,fzgx_loop_i_11476++) {}
    i = fzgx_loop_i_11476;
}
            if(i==30) OSReport((char *)lbl_7_data_14064);
            set_slot(lbl_7_bss_1960_58,lbl_7_bss_1960_78,lbl_7_bss_1960_98,i,index,value,0);
            break;
        case 2:
            lbl_7_bss_1960_34=0;
            set_slot(lbl_7_bss_1960_40,lbl_7_bss_1960_44,lbl_7_bss_1960_48,lbl_7_bss_1960_35,index,value,0x100000);
            break;
        case 3:
            {
    s32 fzgx_loop_i_11930;
for(fzgx_loop_i_11930=0,scan=lbl_7_bss_1960_58;fzgx_loop_i_11930<30 && *scan!=255;scan++,fzgx_loop_i_11930++) {}
    i = fzgx_loop_i_11930;
}
            if(i==30) OSReport((char *)lbl_7_data_14064);
            set_slot(lbl_7_bss_1960_58,lbl_7_bss_1960_78,lbl_7_bss_1960_98,i,index,value,0x100000);
            break;
        default: OSReport((char *)lbl_7_data_14054); break;
        }
        break;
    }
    case 6:
        fn_1_3EB78(1,lbl_7_bss_1960_40,lbl_7_bss_1960_44,lbl_7_bss_1960_48);
        fn_1_3EA90((u8)(lbl_7_bss_1960_38-1),lbl_7_bss_1960_58,lbl_7_bss_1960_78,lbl_7_bss_1960_98);
        break;
    case 7: {
        s32 i,op,index;
        u32 value,extra;
        op=arg1->op; index=arg1->index; value=arg1->value; extra=arg1->extra;
        switch(op) {
        case 0:
            if(value!=-1) {
                s32 group=(s16)index;
                FlagObject *obj=fn_1_E54A8(group,(s16)value);
                obj->flags13c |= extra;
            } else {
    s16 fzgx_loop_i_12810;
for(fzgx_loop_i_12810=0;(s16)fzgx_loop_i_12810<(s16)fn_1_E5430((s16)index);fzgx_loop_i_12810++) {
                FlagObject *obj=fn_1_E54A8((s16)index,fzgx_loop_i_12810); obj->flags13c |= extra;
            }
    i = fzgx_loop_i_12810;
}
            break;
        case 1:
            if(value!=-1) {
                s32 group=(s16)index;
                FlagObject *obj=fn_1_E54A8(group,(s16)value);
                obj->flags138 |= extra;
            } else {
    s16 fzgx_loop_i_13145;
for(fzgx_loop_i_13145=0;(s16)fzgx_loop_i_13145<(s16)fn_1_E5430((s16)index);fzgx_loop_i_13145++) {
                FlagObject *obj=fn_1_E54A8((s16)index,fzgx_loop_i_13145); obj->flags138 |= extra;
            }
    i = fzgx_loop_i_13145;
}
            break;
        case 2:
            if(value!=-1) {
                s32 group=(s16)index;
                clear_object_flags(fn_1_E54A8(group,(s16)value),0,extra);
            }
            else {
                s16 k;
                for(k=0;(s16)k<(s16)fn_1_E5430((s16)index);k++)
                    clear_object_flags(fn_1_E54A8((s16)index,k),0,extra);
            }
            break;
        case 3:
            if(value!=-1) {
                s32 group=(s16)index;
                clear_object_flags(fn_1_E54A8(group,(s16)value),extra,0);
            }
            else {
                s16 k;
                for(k=0;(s16)k<(s16)fn_1_E5430((s16)index);k++)
                    clear_object_flags(fn_1_E54A8((s16)index,k),extra,0);
            }
            break;
        case 4: {
            u32 id=(value<<4)|extra;
            {
    s32 fzgx_loop_i_13895;
for(fzgx_loop_i_13895=0;fzgx_loop_i_13895<(s16)fn_1_E5430((s16)index);fzgx_loop_i_13895++) {
                FlagObject *obj=fn_1_E54A8((s16)index,(s16)fzgx_loop_i_13895);
                if(obj->fieldE==id) clear_object_flags(obj,0,0x2000);
            }
    i = fzgx_loop_i_13895;
}
            break;
        }
        default: OSReport((char *)lbl_7_data_14054); break;
        }
        break;
    }
    case 8: {
        s32 first, i, op, index;
        f32 *fp=0;
        u16 *sp=0;
        s32 end;
        f32 amount;
        f32 base;
        first=arg1->op; index=arg1->index; op=arg1->value; amount=arg1->amount;
        if(first==99) {end=lbl_7_bss_1960_38-1;first=0;}
        else if(first==98) {end=lbl_7_bss_1960_38-1;first=1;}
        else end=first;
        {
for(fzgx_loop_i_14578=first;fzgx_loop_i_14578<=end;fzgx_loop_i_14578++) {
            ActionCar *car=fn_1_86254(fzgx_loop_i_14578);
            CarSpec *spec=&lbl_1_data_28060[car->field6];
            switch(index) {
            case 9:
                if(op==1) {base=100.0f;sp=&car->field5da;fp=&car->field184;}
                else {
                    base=(f32)car->field5da; fp=&car->field184; sp=0;
                    if(op==2 && car->field184+amount>(f32)car->field5da)
                        amount=(f32)car->field5da-car->field184;
                }
                break;
            case 0: base=spec->f4; fp=&car->field8; break;
            case 1: base=spec->f8; fp=&car->field220; break;
            case 2: base=spec->fc; fp=&car->field22c; break;
            case 3: op=0; fn_1_86194(amount); break;
            case 4: base=spec->f10; fp=&car->fieldc; break;
            case 5: base=spec->f14; fp=&car->field10; break;
            case 6: op=0; fn_1_24F10((Sig_fn_1_24F10_Fn_1_24F10 *)car,amount); break;
            case 7: base=spec->f20; fp=&car->field14; break;
            case 8: base=spec->f40; fp=&car->field23c; break;
            default: op=0; break;
            }
            if(amount==-10000000.0f) amount=base;
            if(sp) switch(op) {
            case 0: break;
            case 1: *sp=(s32)amount; break;
            case 2: *sp+=(s32)amount; break;
            case 3: *sp-=(s32)amount; break;
            default: OSReport((char *)lbl_7_data_14054); break;
            }
            if(fp) switch(op) {
            case 0: break;
            case 1: *fp=amount; break;
            case 2: *fp+=amount; break;
            case 3: *fp-=amount; break;
            default: OSReport((char *)lbl_7_data_14054); break;
            }
        }
    i = fzgx_loop_i_14578;
}
        break;
    }
    case 9: {
        s32 selector, first, value, op, end;
        u32 notmask,notvalue;
        s32 i;
        u32 mask;
        selector=arg1->op; op=arg1->index; value=arg1->value;
        if(selector==99) {end=lbl_7_bss_1960_38-1;first=0;}
        else if(selector==98) {end=lbl_7_bss_1960_38-1;first=1;}
        else {end=selector;first=selector;}
        mask=0x80000000U>>value; notvalue=~value; notmask=~mask;
        for(i=first;i<=end;i++) {
            ActionCar *car=fn_1_86254(i);
            switch(op) {
            case 0: car->flags=value; break;
            case 1: car->flags|=mask; break;
            case 2: car->flags&=notmask; break;
            case 3: car->flags|=value; break;
            case 4: car->flags&=notvalue; break;
            default: OSReport((char *)lbl_7_data_14054); break;
            }
        }
        break;
    }
    case 10: {
        s32 selector, first, value, op, end;
        u32 notmask,notvalue;
        s32 i;
        u32 mask;
        selector=arg1->op; op=arg1->index; value=arg1->value;
        if(selector==99) {end=lbl_7_bss_1960_38-1;first=0;}
        else if(selector==98) {end=lbl_7_bss_1960_38-1;first=1;}
        else {end=selector;first=selector;}
        mask=0x80000000U>>value; notvalue=~value; notmask=~mask;
        for(i=first;i<=end;i++) {
            Racer *racer=(Racer *)fn_1_868C0((s8)i);
            switch(op) {
            case 0: racer->flags390=value; break;
            case 1: racer->flags390|=mask; break;
            case 2: racer->flags390&=notmask; break;
            case 3: racer->flags390|=value; break;
            case 4: racer->flags390&=notvalue; break;
            default: OSReport((char *)lbl_7_data_14054); break;
            }
        }
        break;
    }
    case 11: {
        u32 value;
        s32 first, end;
        first=arg1->op; value=arg1->index;
        if(first==99) {end=lbl_7_bss_1960_38-1;first=0;}
        else if(first==98) {end=lbl_7_bss_1960_38-1;first=1;}
        else end=first;
        for(i=first;i<=end;i++) {
            Sig_fn_1_8E448_fn_1_8E448_Object *racer=fn_1_868C0((s8)i);
            fn_1_8E448(racer,value);
        }
        break;
    }
    case 12: {
        f32 x=(f32)arg1->index;
        f32 z=arg1->amount;
        f32 y=(f32)arg1->value;
        ActionCar *car;
        u32 flags;
        u32 index;
        index=arg1->op;
        car=fn_1_86254(index);
        fn_1_8627C(index);
        flags=fn_1_864E8(index);
        fn_1_85F90((fn_1_85F90_Car *)car,(void *)-1,y,z,1.0f,x);
        fn_1_8B880();
        car->flags=flags|(car->flags&0x400);
        break;
    }
    case 13: {
        f32 x=(f32)arg1->index;
        f32 z=arg1->amount;
        f32 y=(f32)arg1->value;
        ActionCar *car;
        u32 flags;
        f32 result;
        ActionVec pos;
        void *entry;
        u32 index;
        index=arg1->op;
        car=fn_1_86254(index);
        fn_1_8627C(index);
        flags=fn_1_864E8(index);
        entry=fn_1_214C4(&result,0,x);
        fn_1_17920(entry,0,result);
        fn_1_207DC((struct Sig_fn_1_207DC_A *)(fn_1_14F04()+0x400),&pos,z);
        fn_1_85F90((fn_1_85F90_Car *)car,entry,y,pos.x,pos.y,pos.z);
        fn_1_8B880();
        car->flags=flags|(car->flags&0x400);
        break;
    }
    case 14: {
        s32 first, i, op, value, end;
        first=arg1->op; op=arg1->index; value=arg1->value;
        if(first==99) {end=lbl_7_bss_1960_38-1;first=0;}
        else if(first==98) {end=lbl_7_bss_1960_38-1;first=1;}
        else end=first;
        {
for(fzgx_loop_i_19806=first;fzgx_loop_i_19806<=end;fzgx_loop_i_19806++) {
            CarControl *control=((ActionCar *)fn_1_86254(fzgx_loop_i_19806))->field484;
            switch(op) {
            case -99: control->flags|=value; break;
            case -98: control->flags&=~value; break;
            case 0: control->flags&=~1;control->mode=0;break;
            default: control->flags|=1;control->mode=op;break;
            }
        }
    i = fzgx_loop_i_19806;
}
        break;
    }
    case 15:
        op=arg1->op; index=arg1->index;
        switch(op) {
        case 0: (&lbl_1_bss_9C)[6]=index;break;
        case 1: (&lbl_1_bss_9C)[7]=index;break;
        default: OSReport((char *)lbl_7_data_14054);break;
        }
        break;
    case 16: {
        ActionCar *car=fn_1_86254(arg1->op);
        ActionVec a=car->field94;
        ActionVec b=car->fielda0;
        f32 x=car->field224;
        f32 y=car->field17c;
        fn_1_25004((Sig_fn_1_25004_Fn_1_25004_Obj *)car);
        car->field224=x;car->field17c=y;
        car->field94=a;car->fielda0=b;
        break;
    }
    case 17:
        op=arg1->op; index=arg1->index;
        switch(op) {
        case 0:
            if(index<8) lbl_1_bss_84[0]=&arg0->vars[index];
            else OSReport((char *)lbl_7_data_14054);
            break;
        case 1: lbl_1_bss_84[1]=&((ActionCar *)fn_1_86254(index))->field17c;break;
        case 2: lbl_1_bss_84[2]=((ActionCar *)fn_1_86254(index))->field49c;break;
        case 3: lbl_1_bss_84[3]=lbl_7_bss_1960_4;break;
        case 4: lbl_1_bss_84[4]=(void *)index;break;
        case 5: lbl_1_bss_84[5]=(void *)index;break;
        default: OSReport((char *)lbl_7_data_14054);break;
        }
        break;
    case 18:
        if(arg1->op) fn_1_8D988();
        else fn_1_8DAB4();
        break;
    case 19:
        op=arg1->op; index=arg1->index;
        switch(op) {
        case 0: camera_set_entry_field_0xa8(0,(s16)index);break;
        default: OSReport((char *)lbl_7_data_14054);break;
        }
        break;
    case 21: {
        u32 *flags;
        s32 op,value;
        flags=(u32 *)arg1->index; op=arg1->op; value=arg1->value;
        switch((s32)flags) {
        case 0: flags=&arg0->flags244;break;
        case 1: flags=&arg0->flags240;break;
        case 2: flags=(u32 *)lbl_7_bss_1960_4;break;
        }
        switch(op) {
        case 0: *flags=value;break;
        case 1: *flags|=0x80000000U>>value;break;
        case 2: *flags&=~(0x80000000U>>value);break;
        case 3: *flags|=value;break;
        case 4: *flags&=~value;break;
        default: OSReport((char *)lbl_7_data_14054);break;
        }
        break;
    }
    case 22: {
        u32 handle;
        s32 op, extra, value;
        extra=arg1->value;op=arg1->op;value=arg1->index;
        if(extra==0) handle=lbl_1_bss_6EAD0.unk_0->unk_0;
        else handle=lbl_1_bss_6EAD0.unk_0->unk_4;
        switch(op) {
        case 0:
            if(!lbl_7_bss_1960_2C && !fn_1_3F1AC()) fn_1_A2D84(value);
            break;
        case 1:
            if(!lbl_7_bss_1960_2C && !fn_1_3F1AC()) fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)handle,(u8)value);
            break;
        case 2: lbl_1_bss_6EAB4.unk_0|=value;break;
        }
        break;
    }
    case 23: {
        s32 op;
        f32 amount;
        op=arg1->op;amount=arg1->amount;
        switch(op) {
        case 0: {
            u32 slot=(u8)(fzgx_obj_lbl_7_bss_1960);
            ((ActionColor *)&lbl_7_bss_1960_10)[slot]=*(const ActionColor *)pool_color0;
            (&lbl_7_bss_1960_18)[slot]=0;
            (&lbl_7_bss_1960_24)[slot]=0.0f;
            (&lbl_7_bss_1960_1C)[slot]=0.0f;
            break;
        }
        case 1: {
            u32 slot=(u8)(fzgx_obj_lbl_7_bss_1960);
            ((ActionColor *)&lbl_7_bss_1960_10)[slot]=*(const ActionColor *)pool_color1;
            (&lbl_7_bss_1960_18)[slot]=2;
            (&lbl_7_bss_1960_1C)[slot]=0.0f;
            (&lbl_7_bss_1960_24)[slot]=amount;
            break;
        }
        case 2: {
            u32 slot=(u8)(fzgx_obj_lbl_7_bss_1960);
            ((ActionColor *)&lbl_7_bss_1960_10)[slot]=*(const ActionColor *)pool_color2;
            (&lbl_7_bss_1960_18)[slot]=1;
            (&lbl_7_bss_1960_1C)[slot]=1.0f;
            (&lbl_7_bss_1960_24)[slot]=-amount;
            break;
        }
        case 4: {
            u32 slot=(u8)(fzgx_obj_lbl_7_bss_1960);
            ((ActionColor *)&lbl_7_bss_1960_10)[slot]=*(const ActionColor *)pool_color4;
            (&lbl_7_bss_1960_18)[slot]=1;
            (&lbl_7_bss_1960_1C)[slot]=1.0f;
            (&lbl_7_bss_1960_24)[slot]=-amount;
            break;
        }
        case 3: {
            u32 slot=(u8)(fzgx_obj_lbl_7_bss_1960);
            ((ActionColor *)&lbl_7_bss_1960_10)[slot]=*(const ActionColor *)pool_color3;
            (&lbl_7_bss_1960_18)[slot]=2;
            (&lbl_7_bss_1960_1C)[slot]=0.0f;
            (&lbl_7_bss_1960_24)[slot]=amount;
            break;
        }
        }
        fzgx_obj_lbl_7_bss_1960++;
        if(fzgx_obj_lbl_7_bss_1960>=2) fzgx_obj_lbl_7_bss_1960--;
        break;
    }
    case 24: lbl_1_bss_8B3A0.unk_8=arg1->op;break;
    }
    if(lbl_7_bss_1960_2C) lbl_1_bss_6F23C&=~1;
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_7_4FD0 */
