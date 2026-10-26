#include "types.h"
#include "rel/option/globals.h"

extern struct fn_4_347C_lbl_1_bss_9C8 lbl_1_bss_9C8;
extern u32 lbl_1_data_2AC0;
extern u32 lbl_1_data_2B40;
extern u32 lbl_1_data_2B50;
extern u32 lbl_1_data_2B58;
extern u32 lbl_4_data_14D0;
extern void fn_4_3128(void);
extern u32 fn_80008BA8(u32, u32, u32);
extern u32 fn_1_F7308(void);
extern u32 lbl_1_bss_AA0;
extern u32 lbl_1_data_2B60;
extern u32 lbl_4_data_2AE8;
extern u32 memcpy(u32, u32, u32);
extern void fn_4_63D4(void);
extern int fn_1_4C10(void);
extern u16 lbl_1_bss_96A;
extern u32 fn_4_0(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_9F8;
extern u8 lbl_4_data_2C58[84];
extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_4_ABB0(void);
extern u32 fn_1_1380F0(u32);
extern u32 fn_1_13ABA8(u32);
extern u32 lbl_4_data_1A4;
extern s32 lbl_801A66B4;
extern u8 lbl_4_bss_5618;
extern u32 fn_1_B7E98(u32);
extern u32 fn_1_B800C(u32);
extern u32 fn_1_B80F0(u32);
extern u32 fn_1_B8170(u32);
extern u32 lbl_4_data_2DB4;
extern void fn_4_9AD0(void);
extern u8 *fn_4_A82C(u8 *);
extern void fn_80083DB0(u8 *, u32);
extern u32 fn_1_B9C0C(void);
extern s8 fn_1_BA144(u32 *);
extern u32 lbl_4_bss_5678;
extern u32 fn_1_B7C00(void);
extern u32 fn_1_BC310(void *);
extern u32 fn_1_C0510(u32);
extern u32 fn_1_C1394(void *);
extern s16 lbl_1_bss_962;
extern struct fn_4_9B0_lbl_4_data_1260 lbl_4_data_1260;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_426C(u32);
extern void fn_4_AB90(void);
extern struct _prolog_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern struct fn_4_869C_lbl_1_bss_718E0 lbl_1_bss_718E0;
extern s32 lbl_1_bss_970;
extern u8 lbl_4_bss_2;
extern u16 lbl_1_bss_968;

/* fzgx:begin fn_4_0 noprologue */
#include "types.h"

extern u32 lbl_1_bss_9F8;
extern void fn_1_A2D84(u32);

/* Volatile input-state reads preserve the separate repeated halfword loads in retail. */
s32 fn_4_0(u32 out0, u32 a, u32 b, s32 index, u32 select)
{
    u32 x, y;
    s32 n;
    u32 res, mid;
    u8 *p;

    n = 0;
    res = out0;
    if (index == -1) {
        if (select == 0) {
            x = ((*(volatile u16 *)((u8 *)&lbl_1_bss_9F8 + 0x10) >> 3) & 1) /* volatile: preserve repeated input-state reads in retail. */
             || ((*(volatile u16 *)((u8 *)&lbl_1_bss_9F8 + 0x12) >> 3) & 1); /* volatile: preserve repeated input-state reads in retail. */
            y = ((*(volatile u16 *)((u8 *)&lbl_1_bss_9F8 + 0x10) >> 2) & 1) /* volatile: preserve repeated input-state reads in retail. */
             || ((*(volatile u16 *)((u8 *)&lbl_1_bss_9F8 + 0x12) >> 2) & 1); /* volatile: preserve repeated input-state reads in retail. */
        } else {
            x = (*(volatile u16 *)((u8 *)&lbl_1_bss_9F8 + 0x10) & 1) /* volatile: preserve repeated input-state reads in retail. */
             || (*(volatile u16 *)((u8 *)&lbl_1_bss_9F8 + 0x12) & 1); /* volatile: preserve repeated input-state reads in retail. */
            y = ((*(volatile u16 *)((u8 *)&lbl_1_bss_9F8 + 0x10) >> 1) & 1) /* volatile: preserve repeated input-state reads in retail. */
             || ((*(volatile u16 *)((u8 *)&lbl_1_bss_9F8 + 0x12) >> 1) & 1); /* volatile: preserve repeated input-state reads in retail. */
        }
    } else {
        if (select == 0) {
            p = (u8 *)&lbl_1_bss_9F8 + ((0x14) * (index));
            x = ((*(volatile u16 *)(p += 0x10) >> 3) & 1) /* volatile: preserve repeated input-state reads in retail. */
             || ((*(volatile u16 *)((((index * 0x14) + ((u32)&lbl_1_bss_9F8)) + (0x12))) >> 3) & 1); /* volatile: preserve repeated input-state reads in retail. */
            y = ((*(volatile u16 *)p >> 2) & 1) /* volatile: preserve repeated input-state reads in retail. */
             || ((*(volatile u16 *)(((index * 0x14) + ((0x12) + ((u32)&lbl_1_bss_9F8)))) >> 2) & 1); /* volatile: preserve repeated input-state reads in retail. */
        } else {
            p = (u8 *)&lbl_1_bss_9F8 + index * 0x14;
            x = (*(volatile u16 *)(p += 0x10) & 1) /* volatile: preserve repeated input-state reads in retail. */
             || (*(volatile u16 *)(((index * 0x14) + ((0x12) + ((u32)&lbl_1_bss_9F8)))) & 1); /* volatile: preserve repeated input-state reads in retail. */
            y = ((*(volatile u16 *)p >> 1) & 1) /* volatile: preserve repeated input-state reads in retail. */
             || ((*(volatile u16 *)(((index * 0x14) + ((0x12) + ((u32)&lbl_1_bss_9F8)))) >> 1) & 1); /* volatile: preserve repeated input-state reads in retail. */
        }
    }
    if (x) n = -1;
    if (y) n++;
    if ((u32)(b - a) == 1) {
        if (n == -1) res = a;
        else if (n == 1) res = b;
    } else {
        mid = out0 + n;
        if ((s32)mid < (s32)a) res = b;
        else if (mid > b) res = a;
        else res = mid;
    }
    if (out0 != res) fn_1_A2D84(0xA9010000);
    return res;
}
/* fzgx:end fn_4_0 */

/* fzgx:begin fn_4_250 */
#include "font.h"

struct fn_4_250_Copy88 { u32 a[22]; };
struct fn_4_250_lbl_4_rodata_0 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
};

extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_4_250_lbl_4_rodata_0 lbl_4_rodata_0;
extern u32 lbl_1_rodata_26F8;

#pragma opt_lifetimes off
void fn_4_250(void) {
    f32 v0;
    f32 v1;
    FontDrawPacket loc_8;
    /* frame */
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v0 = (167.0f);
    v1 = (38.0f);
    loc_8.image = (0x10000 - 28668);
    loc_8.x = v0;
    loc_8.y = v1;
    loc_8.z = (0.5f);
    loc_8.flags = 10;
    fn_1_4F734((FontDrawPacket *)&loc_8);
}
#pragma opt_lifetimes reset
/* fzgx:end fn_4_250 */

/* fzgx:begin _prolog noprologue */
#include "types.h"

struct _prolog_lbl_4_bss_0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
};
struct _prolog_data {
    u8 pad_0[0x1250];
};
struct _prolog_lbl_801A6410 {
    u32 unk_0;
};
struct _prolog_lbl_1_bss_970 {
    u32 unk_0;
    u8 unk_4;
};
struct _prolog_lbl_1_bss_71684 {
    u32 unk_0;
};
struct _prolog_lbl_1_bss_6EAD0 {
    u32 unk_0;
};
extern struct _prolog_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern struct _prolog_lbl_1_bss_71684 lbl_1_bss_71684;
extern struct _prolog_lbl_1_bss_970 lbl_1_bss_970;
extern struct _prolog_lbl_4_bss_0 lbl_4_bss_0;
extern struct _prolog_lbl_801A6410 lbl_801A6410;
extern u16 lbl_1_bss_96A;
extern u32 lbl_1_bss_7167C;
extern u32 lbl_1_bss_71680;
extern u8 lbl_4_data_0[];
extern s32 fn_1_45D0(u32, u32, u32, u32);
extern u32 fn_1_3CF0(u32, u32);
extern u32 fn_1_435C(u32);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern void fn_1_411A4(u32);
extern u32 fn_1_479F0(s16);
extern void fn_1_48418(int);
extern void fn_1_159440(int, int);
extern u32 fn_8004CD70(u32, u32, u32);

s32 fn_1_A176C(u32, s32);                   /* extern */
extern s32 fn_1_133DBC;
extern s32 fn_1_134AD4;
extern s32 fn_4_250;
extern s32 fn_4_800;
extern s32 fn_4_894;
extern s32 fn_4_9B0;

#pragma opt_common_subs off
#pragma opt_propagation off
void _prolog(void) {
    struct _prolog_lbl_4_bss_0 *bss;
    struct _prolog_data *data;
    u32 lab_t0;
    u32 lab_t0_;

    bss = &lbl_4_bss_0;
    data = (struct _prolog_data *)lbl_4_data_0;

    lab_t0 = lbl_801A6410.unk_0;
    lab_t0_ = lab_t0;
    bss->unk_4 = fn_1_45D0(lab_t0_, 0xE3CU, (u32)((u8 *)data + 0x1218), 0x320U);
    lab_t0 = lbl_801A6410.unk_0;
    lab_t0_ = lab_t0;
    bss->unk_8 = fn_1_45D0(lab_t0_, 0xE3CU, (u32)((u8 *)data + 0x1218), 0x321U);
    fn_1_3CF0(bss->unk_4, 0x40U);
    fn_1_3CF0(bss->unk_8, 0x40U);
    fn_1_435C(bss->unk_4);
    fn_1_435C(bss->unk_8);
    fn_1_3F8C((u32)((u8 *)data + 0x1224), (u32)(&fn_1_133DBC), 0U, 0x11U);
    fn_1_3F8C((u32)((u8 *)data + 0x1238), (u32)(&fn_1_134AD4), 0U, 0x11U);
    fn_1_3F8C((u32)((u8 *)data + 0x124C), (u32)(&fn_4_250), 0U, 0x11U);
    lbl_1_bss_970.unk_0 = 0;
    lbl_1_bss_970.unk_4 = 0;
    bss->unk_C = 0;
    bss->unk_D = 0;
    lbl_1_bss_96A = 0x4B;
    bss->unk_E = 0;
    lbl_1_bss_7167C = (u32)(&fn_4_800);
    lbl_1_bss_71680 = (u32)(&fn_4_894);
    lbl_1_bss_71684.unk_0 = (u32)(&fn_4_9B0);
    fn_1_411A4(1U);
    fn_1_479F0(3);
    fn_1_48418(2);
    fn_1_159440(2, 0);
    if ((u32) lbl_1_bss_6EAD0.unk_0 != 0) {
        if ((u32) (*(u32 *)((u8 *)(lbl_1_bss_6EAD0.unk_0) + 0)) == 0) {
            (*(u32 *)((u8 *)(lbl_1_bss_6EAD0.unk_0) + 0)) = fn_8004CD70(2U, lbl_1_bss_6EAD0.unk_0 + 0x10, 0x25124U);
        }
        if ((u32) (*(u32 *)((u8 *)(lbl_1_bss_6EAD0.unk_0) + 4)) == 0) {
            (*(u32 *)((u8 *)(lbl_1_bss_6EAD0.unk_0) + 4)) = fn_8004CD70(2U, lbl_1_bss_6EAD0.unk_0 + 0x4A258, 0x25124U);
        }
        fn_1_A176C(*(u32 *)((u8 *)(lbl_1_bss_6EAD0.unk_0) + 0), 0x37);
    }
}
#pragma opt_propagation reset

#pragma opt_common_subs reset
/* fzgx:end _prolog */

/* fzgx:begin fn_4_800 */
extern u32 fn_1_4A00(u32, u32, u32);
extern int fn_1_4C10(void);

void fn_4_800(void) {
    u8 value;

    value = lbl_4_bss_2;
    lbl_4_bss_2 = value + 1;

    switch (lbl_1_bss_970) {
    case 0:
        break;
    case 1:
        fn_1_4A00(0, 15, lbl_4_bss_8);
        lbl_1_bss_970 = 2;
        break;
    case 2:
        if (fn_1_4C10() == 0) {
            lbl_1_bss_968 = 1;
        }
        break;
    default:
        break;
    }
}
/* fzgx:end fn_4_800 */

/* fzgx:begin fn_4_894 */
extern u32 fn_1_435C(u32);

// Initializes both option subsystems in sequence.
void fn_4_894(void) {
    u32 first_state;
    u32 second_state;

    first_state = fn_1_435C(lbl_4_bss_4);
    first_state = fn_1_407C(first_state);
    fn_1_3CC4(first_state);

    second_state = fn_1_435C(lbl_4_bss_8);
    fn_1_407C(second_state);
}
/* fzgx:end fn_4_894 */

/* fzgx:begin _epilog */
extern const f32 lbl_4_rodata_4C[45];
extern u32 lbl_4_bss_4;
extern u32 lbl_4_bss_8;
extern struct _prolog_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;

extern void fn_8006CE1C(f32);
extern void fn_1_1596DC(u32);
extern void fn_1_484CC(u32);
extern void fn_1_47A60(u32);
extern void fn_1_412A0(u32);
extern void fn_1_3C78(void);
extern void fn_1_435C(u32);
extern void fn_1_41A8(void);
extern void fn_8004BF0C(u32, s32);
extern void ADXT_Stop(u32);

struct OptHandle {
    u32 unk_0;
};

struct OptSoundBank {
    u32 unk_0;
    u32 unk_4;
};

// Module teardown: fades the overlay, resets the option camera and font state,
// frees both cached fonts, then stops the two sound-bank entries.
void _epilog(void) {
    fn_8006CE1C(lbl_4_rodata_4C[0]);
    fn_1_1596DC(2);
    fn_1_484CC(2);
    fn_1_47A60(3);
    fn_1_412A0(1);
    fn_1_3C78();
    fn_1_435C(((struct OptHandle *)&lbl_4_bss_4)->unk_0);
    fn_1_41A8();
    fn_1_435C(((struct OptHandle *)&lbl_4_bss_8)->unk_0);
    fn_1_41A8();
    if (((struct OptHandle *)&lbl_1_bss_6EAD0)->unk_0 != 0) {
        fn_8004BF0C(((struct OptSoundBank *)((struct OptHandle *)&lbl_1_bss_6EAD0)->unk_0)->unk_0, -999);
        fn_8004BF0C(((struct OptSoundBank *)((struct OptHandle *)&lbl_1_bss_6EAD0)->unk_0)->unk_4, -999);
        ADXT_Stop(((struct OptSoundBank *)((struct OptHandle *)&lbl_1_bss_6EAD0)->unk_0)->unk_0);
        ADXT_Stop(((struct OptSoundBank *)((struct OptHandle *)&lbl_1_bss_6EAD0)->unk_0)->unk_4);
    }
}
/* fzgx:end _epilog */

/* fzgx:begin fn_4_9B0 */
#include "types.h"

extern struct fn_4_9B0_lbl_4_data_1260 lbl_4_data_1260;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;

typedef u32 (*fn_4_9B0_Fn0)(void);
struct fn_4_9B0_lbl_4_data_1260_0_E44 {
    u8 pad_0[0x20];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
};
struct fn_4_9B0_lbl_4_data_1260 {
    struct fn_4_9B0_lbl_4_data_1260_0_E44 unk_0[1];
};

void fn_4_9B0(void) {
    struct fn_4_9B0_lbl_4_data_1260_0_E44 *p;
    s16 idx;
    u32 v0;
    p = (struct fn_4_9B0_lbl_4_data_1260_0_E44 *)&lbl_4_data_1260;
    idx = lbl_1_bss_962;
    p = (struct fn_4_9B0_lbl_4_data_1260_0_E44 *)((u8 *)p + (idx - 75) * 44);
    lbl_1_bss_71688 = p->unk_24;
    lbl_1_bss_7168C = (p->unk_28);
    ((fn_4_9B0_Fn0)p->unk_20)();
}
/* fzgx:end fn_4_9B0 */

/* fzgx:begin fn_4_A0C noprologue */
#include "types.h"
#include "font.h"
#include "rel/option/globals.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 167.0f;
    s = 38.0f;
    s = 0.5f;
}
extern u8 fn_4_347C__fzgx_offset_0[];
extern u8 fn_4_3568__fzgx_offset_0[];
extern u8 fn_4_406C__fzgx_offset_0[];
extern u8 fn_4_4784__fzgx_offset_0[];
extern u8 fn_4_4834__fzgx_offset_0[];
extern u8 fn_4_4B10__fzgx_offset_0[];
extern u8 fn_4_4B74__fzgx_offset_10C[];
extern u8 fn_4_4B74__fzgx_offset_124[];
extern u8 fn_4_4B74__fzgx_offset_68[];
extern u8 fn_4_4B74__fzgx_offset_7C[];
extern u8 fn_4_4B74__fzgx_offset_94[];
extern u8 fn_4_4B74__fzgx_offset_AC[];
extern u8 fn_4_4B74__fzgx_offset_C4[];
extern u8 fn_4_4B74__fzgx_offset_DC[];
extern u8 fn_4_4B74__fzgx_offset_F4[];
extern u8 fn_4_4CB8__fzgx_offset_110[];
extern u8 fn_4_4CB8__fzgx_offset_128[];
extern u8 fn_4_4CB8__fzgx_offset_6C[];
extern u8 fn_4_4CB8__fzgx_offset_80[];
extern u8 fn_4_4CB8__fzgx_offset_98[];
extern u8 fn_4_4CB8__fzgx_offset_B0[];
extern u8 fn_4_4CB8__fzgx_offset_C8[];
extern u8 fn_4_4CB8__fzgx_offset_E0[];
extern u8 fn_4_4CB8__fzgx_offset_F8[];
extern u8 fn_4_4DF8__fzgx_offset_12E4[];
extern u8 fn_4_4DF8__fzgx_offset_1308[];
extern u8 fn_4_4DF8__fzgx_offset_1330[];
extern u8 fn_4_4DF8__fzgx_offset_1350[];
extern u8 fn_4_4DF8__fzgx_offset_1378[];
extern u8 fn_4_4DF8__fzgx_offset_1398[];
extern u8 fn_4_4DF8__fzgx_offset_13C0[];
extern u8 fn_4_4DF8__fzgx_offset_13E0[];
extern u8 fn_4_4DF8__fzgx_offset_1408[];
extern u8 fn_4_4DF8__fzgx_offset_1428[];
extern u8 fn_4_4DF8__fzgx_offset_1454[];
extern u8 fn_4_4DF8__fzgx_offset_3E4[];
extern u8 fn_4_4DF8__fzgx_offset_3F4[];
extern u8 fn_4_4DF8__fzgx_offset_408[];
extern u8 fn_4_4DF8__fzgx_offset_41C[];
extern u8 fn_4_4DF8__fzgx_offset_430[];
extern u8 fn_4_4DF8__fzgx_offset_444[];
extern u8 fn_4_4DF8__fzgx_offset_458[];
extern u8 fn_4_4DF8__fzgx_offset_46C[];
extern u8 fn_4_4DF8__fzgx_offset_480[];
extern u8 fn_4_4DF8__fzgx_offset_930[];
extern u8 fn_4_4DF8__fzgx_offset_940[];
extern u8 fn_4_4DF8__fzgx_offset_954[];
extern u8 fn_4_4DF8__fzgx_offset_968[];
extern u8 fn_4_4DF8__fzgx_offset_97C[];
extern u8 fn_4_4DF8__fzgx_offset_990[];
extern u8 fn_4_4DF8__fzgx_offset_9A4[];
extern u8 fn_4_4DF8__fzgx_offset_9B8[];
extern u8 fn_4_4DF8__fzgx_offset_9CC[];
extern u8 fn_4_4DF8__fzgx_offset_D2C[];
extern u8 fn_4_4DF8__fzgx_offset_D4C[];
extern u8 fn_4_4DF8__fzgx_offset_D6C[];
extern u8 fn_4_4DF8__fzgx_offset_D8C[];
extern u8 fn_4_4DF8__fzgx_offset_DB4[];
extern u8 fn_4_4DF8__fzgx_offset_DD4[];
extern u8 fn_4_4DF8__fzgx_offset_DF4[];
extern u8 fn_4_4DF8__fzgx_offset_E14[];
extern u8 fn_4_4DF8__fzgx_offset_E34[];
extern u8 fn_4_4DF8__fzgx_offset_E54[];
extern u8 fn_4_4DF8__fzgx_offset_E80[];
extern u8 fn_4_63D4__fzgx_offset_150[];
extern u8 fn_4_63D4__fzgx_offset_170[];
extern u8 fn_4_63D4__fzgx_offset_190[];
extern u8 fn_4_63D4__fzgx_offset_1C0[];
extern u8 fn_4_63D4__fzgx_offset_1F0[];
extern u8 fn_4_63D4__fzgx_offset_94[];
extern u8 fn_4_63D4__fzgx_offset_F8[];
extern u8 fn_4_6678__fzgx_offset_0[];
extern u8 fn_4_6720__fzgx_offset_0[];
extern u8 fn_4_6720__fzgx_offset_1038[];
extern u8 fn_4_6720__fzgx_offset_1114[];
extern u8 fn_4_6720__fzgx_offset_148[];
extern u8 fn_4_6720__fzgx_offset_298[];
extern u8 fn_4_6720__fzgx_offset_404[];
extern u8 fn_4_6720__fzgx_offset_414[];
extern u8 fn_4_6720__fzgx_offset_428[];
extern u8 fn_4_6720__fzgx_offset_43C[];
extern u8 fn_4_6720__fzgx_offset_450[];
extern u8 fn_4_6720__fzgx_offset_464[];
extern u8 fn_4_6720__fzgx_offset_478[];
extern u8 fn_4_6720__fzgx_offset_48C[];
extern u8 fn_4_6720__fzgx_offset_4A0[];
extern u8 fn_4_6720__fzgx_offset_540[];
extern u8 fn_4_6720__fzgx_offset_5E4[];
extern u8 fn_4_6720__fzgx_offset_5F4[];
extern u8 fn_4_6720__fzgx_offset_608[];
extern u8 fn_4_6720__fzgx_offset_61C[];
extern u8 fn_4_6720__fzgx_offset_630[];
extern u8 fn_4_6720__fzgx_offset_644[];
extern u8 fn_4_6720__fzgx_offset_658[];
extern u8 fn_4_6720__fzgx_offset_66C[];
extern u8 fn_4_6720__fzgx_offset_680[];
extern u8 fn_4_6720__fzgx_offset_710[];
extern u8 fn_4_6720__fzgx_offset_720[];
extern u8 fn_4_6720__fzgx_offset_734[];
extern u8 fn_4_6720__fzgx_offset_748[];
extern u8 fn_4_6720__fzgx_offset_75C[];
extern u8 fn_4_6720__fzgx_offset_770[];
extern u8 fn_4_6720__fzgx_offset_784[];
extern u8 fn_4_6720__fzgx_offset_798[];
extern u8 fn_4_6720__fzgx_offset_7AC[];
extern u8 fn_4_6720__fzgx_offset_93C[];
extern u8 fn_4_6720__fzgx_offset_94C[];
extern u8 fn_4_6720__fzgx_offset_960[];
extern u8 fn_4_6720__fzgx_offset_974[];
extern u8 fn_4_6720__fzgx_offset_988[];
extern u8 fn_4_6720__fzgx_offset_98[];
extern u8 fn_4_6720__fzgx_offset_99C[];
extern u8 fn_4_6720__fzgx_offset_9B0[];
extern u8 fn_4_6720__fzgx_offset_9C4[];
extern u8 fn_4_6720__fzgx_offset_9D8[];
extern u8 fn_4_6720__fzgx_offset_B48[];
extern u8 fn_4_6720__fzgx_offset_B58[];
extern u8 fn_4_6720__fzgx_offset_B6C[];
extern u8 fn_4_6720__fzgx_offset_B80[];
extern u8 fn_4_6720__fzgx_offset_B94[];
extern u8 fn_4_6720__fzgx_offset_BA8[];
extern u8 fn_4_6720__fzgx_offset_BBC[];
extern u8 fn_4_6720__fzgx_offset_BD0[];
extern u8 fn_4_6720__fzgx_offset_BE4[];
extern u8 fn_4_6720__fzgx_offset_C94[];
extern u8 fn_4_6720__fzgx_offset_CA4[];
extern u8 fn_4_6720__fzgx_offset_CB8[];
extern u8 fn_4_6720__fzgx_offset_CCC[];
extern u8 fn_4_6720__fzgx_offset_CE0[];
extern u8 fn_4_6720__fzgx_offset_CF4[];
extern u8 fn_4_6720__fzgx_offset_D08[];
extern u8 fn_4_6720__fzgx_offset_D1C[];
extern u8 fn_4_6720__fzgx_offset_D30[];
extern u8 fn_4_6720__fzgx_offset_D6C[];
extern u8 fn_4_6720__fzgx_offset_E8C[];
extern u8 fn_4_78E0__fzgx_offset_0[];
extern u8 fn_4_7C38__fzgx_offset_0[];
extern u8 fn_4_7CA4__fzgx_offset_0[];
extern u8 fn_4_7D94__fzgx_offset_0[];
extern u8 fn_4_80EC__fzgx_offset_0[];
extern u8 fn_4_8158__fzgx_offset_0[];
extern u8 fn_4_8248__fzgx_offset_0[];
extern u8 fn_4_869C__fzgx_offset_0[];
extern u8 fn_4_8720__fzgx_offset_0[];
extern u8 fn_4_898C__fzgx_offset_0[];
extern u8 fn_4_89E4__fzgx_offset_0[];
extern u8 fn_4_8A54__fzgx_offset_0[];
extern u8 fn_4_8AE0__fzgx_offset_0[];
extern u8 fn_4_8DC0__fzgx_offset_0[];
extern u8 fn_4_8E38__fzgx_offset_0[];
extern u8 fn_4_9A78__fzgx_offset_0[];
extern u8 fn_4_9B20__fzgx_offset_0[];
extern u8 fn_4_9C14__fzgx_offset_0[];
extern u8 fn_4_A734__fzgx_offset_0[];
extern u8 fn_4_D10__fzgx_offset_0[];
extern u8 fn_4_D7C__fzgx_offset_0[];
extern u8 fn_4_EA0__fzgx_offset_0[];
extern u8 lbl_4_data_0__fzgx_offset_0[];
extern u8 lbl_4_data_100__fzgx_offset_0[];
extern u8 lbl_4_data_107C__fzgx_offset_0[];
extern u8 lbl_4_data_10A0__fzgx_offset_0[];
extern u8 lbl_4_data_10E8__fzgx_offset_0[];
extern u8 lbl_4_data_10__fzgx_offset_0[];
extern u8 lbl_4_data_111C__fzgx_offset_0[];
extern u8 lbl_4_data_116C__fzgx_offset_0[];
extern u8 lbl_4_data_11AC__fzgx_offset_0[];
extern u8 lbl_4_data_130__fzgx_offset_0[];
extern u8 lbl_4_data_1418__fzgx_offset_0[];
extern u8 lbl_4_data_1424__fzgx_offset_0[];
extern u8 lbl_4_data_1434__fzgx_offset_0[];
extern u8 lbl_4_data_1440__fzgx_offset_0[];
extern u8 lbl_4_data_1534__fzgx_offset_0[];
extern u8 lbl_4_data_1544__fzgx_offset_0[];
extern u8 lbl_4_data_154C__fzgx_offset_0[];
extern u8 lbl_4_data_1558__fzgx_offset_0[];
extern u8 lbl_4_data_156C__fzgx_offset_0[];
extern u8 lbl_4_data_1588__fzgx_offset_0[];
extern u8 lbl_4_data_15AC__fzgx_offset_0[];
extern u8 lbl_4_data_15B4__fzgx_offset_0[];
extern u8 lbl_4_data_1660__fzgx_offset_0[];
extern u8 lbl_4_data_1678__fzgx_offset_0[];
extern u8 lbl_4_data_1688__fzgx_offset_0[];
extern u8 lbl_4_data_168C__fzgx_offset_0[];
extern u8 lbl_4_data_16A0__fzgx_offset_0[];
extern u8 lbl_4_data_16FC__fzgx_offset_0[];
extern u8 lbl_4_data_1704__fzgx_offset_0[];
extern u8 lbl_4_data_170__fzgx_offset_0[];
extern u8 lbl_4_data_1718__fzgx_offset_0[];
extern u8 lbl_4_data_172C__fzgx_offset_0[];
extern u8 lbl_4_data_1740__fzgx_offset_0[];
extern u8 lbl_4_data_175C__fzgx_offset_0[];
extern u8 lbl_4_data_1770__fzgx_offset_0[];
extern u8 lbl_4_data_177C__fzgx_offset_0[];
extern u8 lbl_4_data_1790__fzgx_offset_0[];
extern u8 lbl_4_data_179C__fzgx_offset_0[];
extern u8 lbl_4_data_17B0__fzgx_offset_0[];
extern u8 lbl_4_data_17BC__fzgx_offset_0[];
extern u8 lbl_4_data_17D0__fzgx_offset_0[];
extern u8 lbl_4_data_17DC__fzgx_offset_0[];
extern u8 lbl_4_data_17F0__fzgx_offset_0[];
extern u8 lbl_4_data_17FC__fzgx_offset_0[];
extern u8 lbl_4_data_1810__fzgx_offset_0[];
extern u8 lbl_4_data_1818__fzgx_offset_0[];
extern u8 lbl_4_data_188__fzgx_offset_0[];
extern u8 lbl_4_data_1904__fzgx_offset_0[];
extern u8 lbl_4_data_1924__fzgx_offset_0[];
extern u8 lbl_4_data_192C__fzgx_offset_0[];
extern u8 lbl_4_data_193C__fzgx_offset_0[];
extern u8 lbl_4_data_1958__fzgx_offset_0[];
extern u8 lbl_4_data_1960__fzgx_offset_0[];
extern u8 lbl_4_data_1970__fzgx_offset_0[];
extern u8 lbl_4_data_1980__fzgx_offset_0[];
extern u8 lbl_4_data_1988__fzgx_offset_0[];
extern u8 lbl_4_data_1998__fzgx_offset_0[];
extern u8 lbl_4_data_19A8__fzgx_offset_0[];
extern u8 lbl_4_data_19B0__fzgx_offset_0[];
extern u8 lbl_4_data_19C0__fzgx_offset_0[];
extern u8 lbl_4_data_19E0__fzgx_offset_0[];
extern u8 lbl_4_data_19E8__fzgx_offset_0[];
extern u8 lbl_4_data_1A04__fzgx_offset_0[];
extern u8 lbl_4_data_1A24__fzgx_offset_0[];
extern u8 lbl_4_data_1A2C__fzgx_offset_0[];
extern u8 lbl_4_data_1A48__fzgx_offset_0[];
extern u8 lbl_4_data_1A64__fzgx_offset_0[];
extern u8 lbl_4_data_1A6C__fzgx_offset_0[];
extern u8 lbl_4_data_1A80__fzgx_offset_0[];
extern u8 lbl_4_data_1A98__fzgx_offset_0[];
extern u8 lbl_4_data_1AA0__fzgx_offset_0[];
extern u8 lbl_4_data_1AB4__fzgx_offset_0[];
extern u8 lbl_4_data_1AC4__fzgx_offset_0[];
extern u8 lbl_4_data_1ADC__fzgx_offset_0[];
extern u8 lbl_4_data_1AE8__fzgx_offset_0[];
extern u8 lbl_4_data_1BC__fzgx_offset_0[];
extern u8 lbl_4_data_1C78__fzgx_offset_0[];
extern u8 lbl_4_data_1C98__fzgx_offset_0[];
extern u8 lbl_4_data_1CA8__fzgx_offset_0[];
extern u8 lbl_4_data_1CC4__fzgx_offset_0[];
extern u8 lbl_4_data_1E60__fzgx_offset_0[];
extern u8 lbl_4_data_1E74__fzgx_offset_0[];
extern u8 lbl_4_data_1E7C__fzgx_offset_0[];
extern u8 lbl_4_data_1E8C__fzgx_offset_0[];
extern u8 lbl_4_data_1EA4__fzgx_offset_0[];
extern u8 lbl_4_data_1EB0__fzgx_offset_0[];
extern u8 lbl_4_data_1EC0__fzgx_offset_0[];
extern u8 lbl_4_data_1ED4__fzgx_offset_0[];
extern u8 lbl_4_data_1EDC__fzgx_offset_0[];
extern u8 lbl_4_data_1EEC__fzgx_offset_0[];
extern u8 lbl_4_data_1F00__fzgx_offset_0[];
extern u8 lbl_4_data_1F08__fzgx_offset_0[];
extern u8 lbl_4_data_1F18__fzgx_offset_0[];
extern u8 lbl_4_data_1F24__fzgx_offset_0[];
extern u8 lbl_4_data_1F28__fzgx_offset_0[];
extern u8 lbl_4_data_1F34__fzgx_offset_0[];
extern u8 lbl_4_data_1F40__fzgx_offset_0[];
extern u8 lbl_4_data_1F44__fzgx_offset_0[];
extern u8 lbl_4_data_1F50__fzgx_offset_0[];
extern u8 lbl_4_data_1F5C__fzgx_offset_0[];
extern u8 lbl_4_data_1F60__fzgx_offset_0[];
extern u8 lbl_4_data_1F6C__fzgx_offset_0[];
extern u8 lbl_4_data_1F78__fzgx_offset_0[];
extern u8 lbl_4_data_1F7C__fzgx_offset_0[];
extern u8 lbl_4_data_1F88__fzgx_offset_0[];
extern u8 lbl_4_data_1F94__fzgx_offset_0[];
extern u8 lbl_4_data_1F98__fzgx_offset_0[];
extern u8 lbl_4_data_1FA4__fzgx_offset_0[];
extern u8 lbl_4_data_1FBC__fzgx_offset_0[];
extern u8 lbl_4_data_1FD8__fzgx_offset_0[];
extern u8 lbl_4_data_1FF0__fzgx_offset_0[];
extern u8 lbl_4_data_1FFC__fzgx_offset_0[];
extern u8 lbl_4_data_2018__fzgx_offset_0[];
extern u8 lbl_4_data_2030__fzgx_offset_0[];
extern u8 lbl_4_data_2038__fzgx_offset_0[];
extern u8 lbl_4_data_2054__fzgx_offset_0[];
extern u8 lbl_4_data_2068__fzgx_offset_0[];
extern u8 lbl_4_data_2070__fzgx_offset_0[];
extern u8 lbl_4_data_208C__fzgx_offset_0[];
extern u8 lbl_4_data_209C__fzgx_offset_0[];
extern u8 lbl_4_data_20A4__fzgx_offset_0[];
extern u8 lbl_4_data_20B4__fzgx_offset_0[];
extern u8 lbl_4_data_20C8__fzgx_offset_0[];
extern u8 lbl_4_data_20D4__fzgx_offset_0[];
extern u8 lbl_4_data_20E4__fzgx_offset_0[];
extern u8 lbl_4_data_20F4__fzgx_offset_0[];
extern u8 lbl_4_data_20FC__fzgx_offset_0[];
extern u8 lbl_4_data_210C__fzgx_offset_0[];
extern u8 lbl_4_data_210__fzgx_offset_0[];
extern u8 lbl_4_data_211C__fzgx_offset_0[];
extern u8 lbl_4_data_2124__fzgx_offset_0[];
extern u8 lbl_4_data_2134__fzgx_offset_0[];
extern u8 lbl_4_data_2140__fzgx_offset_0[];
extern u8 lbl_4_data_2144__fzgx_offset_0[];
extern u8 lbl_4_data_2158__fzgx_offset_0[];
extern u8 lbl_4_data_2164__fzgx_offset_0[];
extern u8 lbl_4_data_216C__fzgx_offset_0[];
extern u8 lbl_4_data_2480__fzgx_offset_0[];
extern u8 lbl_4_data_2494__fzgx_offset_0[];
extern u8 lbl_4_data_24A0__fzgx_offset_0[];
extern u8 lbl_4_data_24B8__fzgx_offset_0[];
extern u8 lbl_4_data_24C4__fzgx_offset_0[];
extern u8 lbl_4_data_24D8__fzgx_offset_0[];
extern u8 lbl_4_data_24E8__fzgx_offset_0[];
extern u8 lbl_4_data_24F4__fzgx_offset_0[];
extern u8 lbl_4_data_254__fzgx_offset_0[];
extern u8 lbl_4_data_2804__fzgx_offset_0[];
extern u8 lbl_4_data_2810__fzgx_offset_0[];
extern u8 lbl_4_data_2834__fzgx_offset_0[];
extern u8 lbl_4_data_2848__fzgx_offset_0[];
extern u8 lbl_4_data_284__fzgx_offset_0[];
extern u8 lbl_4_data_2870__fzgx_offset_0[];
extern u8 lbl_4_data_290C__fzgx_offset_0[];
extern u8 lbl_4_data_2BF4__fzgx_offset_0[];
extern u8 lbl_4_data_2C00__fzgx_offset_0[];
extern u8 lbl_4_data_2C14__fzgx_offset_0[];
extern u8 lbl_4_data_2C20__fzgx_offset_0[];
extern u8 lbl_4_data_2C30__fzgx_offset_0[];
extern u8 lbl_4_data_2C44__fzgx_offset_0[];
extern u8 lbl_4_data_2CC__fzgx_offset_0[];
extern u8 lbl_4_data_2F0__fzgx_offset_0[];
extern u8 lbl_4_data_32C__fzgx_offset_0[];
extern u8 lbl_4_data_34C__fzgx_offset_0[];
extern u8 lbl_4_data_37C__fzgx_offset_0[];
extern u8 lbl_4_data_38__fzgx_offset_0[];
extern u8 lbl_4_data_3B8__fzgx_offset_0[];
extern u8 lbl_4_data_400__fzgx_offset_0[];
extern u8 lbl_4_data_438__fzgx_offset_0[];
extern u8 lbl_4_data_480__fzgx_offset_0[];
extern u8 lbl_4_data_4C__fzgx_offset_0[];
extern u8 lbl_4_data_4F0__fzgx_offset_0[];
extern u8 lbl_4_data_578__fzgx_offset_0[];
extern u8 lbl_4_data_57C__fzgx_offset_0[];
extern u8 lbl_4_data_59C__fzgx_offset_0[];
extern u8 lbl_4_data_5A0__fzgx_offset_0[];
extern u8 lbl_4_data_5C0__fzgx_offset_0[];
extern u8 lbl_4_data_5D8__fzgx_offset_0[];
extern u8 lbl_4_data_610__fzgx_offset_0[];
extern u8 lbl_4_data_660__fzgx_offset_0[];
extern u8 lbl_4_data_6D4__fzgx_offset_0[];
extern u8 lbl_4_data_724__fzgx_offset_0[];
extern u8 lbl_4_data_78__fzgx_offset_0[];
extern u8 lbl_4_data_790__fzgx_offset_0[];
extern u8 lbl_4_data_7C__fzgx_offset_0[];
extern u8 lbl_4_data_7DC__fzgx_offset_0[];
extern u8 lbl_4_data_85C__fzgx_offset_0[];
extern u8 lbl_4_data_86C__fzgx_offset_0[];
extern u8 lbl_4_data_89C__fzgx_offset_0[];
extern u8 lbl_4_data_8A8__fzgx_offset_0[];
extern u8 lbl_4_data_8D8__fzgx_offset_0[];
extern u8 lbl_4_data_8F8__fzgx_offset_0[];
extern u8 lbl_4_data_918__fzgx_offset_0[];
extern u8 lbl_4_data_934__fzgx_offset_0[];
extern u8 lbl_4_data_970__fzgx_offset_0[];
extern u8 lbl_4_data_984__fzgx_offset_0[];
extern u8 lbl_4_data_9C0__fzgx_offset_0[];
extern u8 lbl_4_data_9D8__fzgx_offset_0[];
extern u8 lbl_4_data_A10__fzgx_offset_0[];
extern u8 lbl_4_data_A30__fzgx_offset_0[];
extern u8 lbl_4_data_A70__fzgx_offset_0[];
extern u8 lbl_4_data_A78__fzgx_offset_0[];
extern u8 lbl_4_data_AA0__fzgx_offset_0[];
extern u8 lbl_4_data_AAC__fzgx_offset_0[];
extern u8 lbl_4_data_AD4__fzgx_offset_0[];
extern u8 lbl_4_data_B0__fzgx_offset_0[];
extern u8 lbl_4_data_B90__fzgx_offset_0[];
extern u8 lbl_4_data_C18__fzgx_offset_0[];
extern u8 lbl_4_data_C8__fzgx_offset_0[];
extern u8 lbl_4_data_CB0__fzgx_offset_0[];
extern u8 lbl_4_data_C__fzgx_offset_0[];
extern u8 lbl_4_data_D50__fzgx_offset_0[];
extern u8 lbl_4_data_D64__fzgx_offset_0[];
extern u8 lbl_4_data_D84__fzgx_offset_0[];
extern u8 lbl_4_data_D98__fzgx_offset_0[];
extern u8 lbl_4_data_DB8__fzgx_offset_0[];
extern u8 lbl_4_data_DF0__fzgx_offset_0[];
extern u8 lbl_4_data_E48__fzgx_offset_0[];
extern u8 lbl_4_data_E58__fzgx_offset_0[];
extern u8 lbl_4_data_E88__fzgx_offset_0[];
extern u8 lbl_4_data_E98__fzgx_offset_0[];
extern u8 lbl_4_data_EC8__fzgx_offset_0[];
extern u8 lbl_4_data_F08__fzgx_offset_0[];
extern u8 lbl_4_data_F64__fzgx_offset_0[];
extern u8 lbl_4_data_FD8__fzgx_offset_0[];
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table2 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xD0D000
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table2.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 78.0;
    d = 0.125;
    s = 2.9375f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table4.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3;
    d = 1.0;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table6 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xD0D000
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table6.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6000000238418579f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFF000000
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table8.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.5f;
    s = 5.0f;
    s = 0.0f;
    s = 320.0f;
    s = 0.15000000596046448f;
    s = 240.0f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table10 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table10.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 96.0;
    d = 48.0;
    s = 0.25f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table12 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table12.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.004999999888241291f;
    s = 216.0f;
    d = 90.0;
    d = 320.0;
    d = 0.5;
    s = 264.0f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table14 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table14.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = -0.5;
    s = 0.014999999664723873f;
    s = 72.0f;
    s = 0.02500000037252903f;
    s = 0.05000000074505806f;
    s = 48.0f;
    s = 0.800000011920929f;
    s = 110.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_120[1] = { 0x42F00000 }; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep120(void) { const u32 *volatile cp; cp = fzgx_pool_120; } /* fzgx-allow: S2 pool primer sink */
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table16 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x8080000
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table16.v; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

/* One menu row: a tag word followed by the row text per language. */

typedef struct Color4 {
    u8 c[4];
} Color4;

/* The module's .data objects, defined here so they share one section base. */
typedef struct OptionRow {
    u32 unk_0;
    char *text[6];
} OptionRow;

static union { u32 w[58]; u8 v[0xE8]; } fzgx_pool_init_fzgx_obj_lbl_4_data_0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x436F6E74, 0x726F6C6C, 0x65720000, 0x0, 0x83528393, 0x8367838D, 0x815B8389, 0x0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, 0x436F6E74, 0x726F6C6C,
    0x65722053, 0x6F636B65, 0x74000000, 0x83528393, 0x8367838D, 0x815B8389, 0x837C815B, 0x83670000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_38__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_4C__fzgx_offset_0, 0x4F4E0000, 0x4F464600,
    (u32)lbl_4_data_78__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_78__fzgx_offset_0, (u32)lbl_4_data_7C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_7C__fzgx_offset_0, 0x0, 0x55736520, 0x83AD206F, 0x722083B5, 0x20746F20,
    0x63686F6F, 0x73652E00, 0x83AD82A9, 0x83B582C5, 0x8D8096DA, 0x82F09149, 0x82F182C5, 0x82AD82BE,
    0x82B382A2, 0x81420000  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[324]; void *v[(0x5F8 - 0xE8) / 4]; } fzgx_pool_init_lbl_4_data_E8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_B0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C8__fzgx_offset_0, 0x4D6F7665, 0x2083AD20  /* fzgx-allow: A1 retail data bytes */,
    0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063, 0x68616E67, 0x6520636F  /* fzgx-allow: A1 retail data bytes */,
    0x6E74726F, 0x6C732E00, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C59180, 0x8DEC82F0, 0x95CF8D58  /* fzgx-allow: A1 retail data bytes */,
    0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_100__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_130__fzgx_offset_0, 0x506C6561, 0x73652077, 0x61697420, 0x61206D6F, 0x6D656E74, 0x2E2E2E00  /* fzgx-allow: A1 retail data bytes */,
    0x82B582CE, 0x82E782AD, 0x82A891D2, 0x82BF82AD, 0x82BE82B3, 0x82A28142, 0x0, (u32)lbl_4_data_170__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_188__fzgx_offset_0, 0x50726573, 0x73207468, 0x65204120  /* fzgx-allow: A1 retail data bytes */,
    0x42757474, 0x6F6E206F, 0x6E207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0x20746F20, 0x62652061  /* fzgx-allow: A1 retail data bytes */,
    0x646A7573, 0x7465642E, 0x20507265, 0x73732074, 0x68652042, 0x20427574, 0x746F6E20, 0x746F2066  /* fzgx-allow: A1 retail data bytes */,
    0x696E6973, 0x682E0000, 0x95CF8D58, 0x82B782E9, 0x83528393, 0x8367838D, 0x815B8389, 0x82C5839F  /* fzgx-allow: A1 retail data bytes */,
    0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_1BC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_210__fzgx_offset_0, 0x526F7461, 0x74652074, 0x68652043, 0x6F6E7472, 0x6F6C2053  /* fzgx-allow: A1 retail data bytes */,
    0x7469636B, 0x206F6E65, 0x2066756C, 0x6C207265, 0x766F6C75, 0x74696F6E, 0x2E000000, 0x83528393  /* fzgx-allow: A1 retail data bytes */,
    0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E82F0, 0x88EA9474, 0x82C989F1, 0x82B582C4  /* fzgx-allow: A1 retail data bytes */,
    0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_254__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_284__fzgx_offset_0, 0x506C6561, 0x73652061, 0x646A7573, 0x74207468, 0x65207374, 0x65657269, 0x6E672077  /* fzgx-allow: A1 retail data bytes */,
    0x6865656C, 0x2E000000, 0x836E8393, 0x8368838B, 0x82CC92B2, 0x90AE82F0, 0x8D7382C8, 0x82C182C4  /* fzgx-allow: A1 retail data bytes */,
    0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_2CC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_2F0__fzgx_offset_0, 0x52657475, 0x726E2074, 0x6F207468, 0x65206465, 0x6661756C, 0x74207365, 0x7474696E  /* fzgx-allow: A1 retail data bytes */,
    0x67733F00, 0x8F898AFA, 0x90DD92E8, 0x82C996DF, 0x82B582DC, 0x82B782A9, 0x81480000, (u32)lbl_4_data_32C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_34C__fzgx_offset_0, 0x53656C65, 0x63742074, 0x68652043  /* fzgx-allow: A1 retail data bytes */,
    0x6F6E7472, 0x6F6C6C65, 0x7220746F, 0x20626520, 0x6368616E, 0x67656420, 0x7573696E, 0x67206569  /* fzgx-allow: A1 retail data bytes */,
    0x74686572, 0x2083AD20, 0x6F722083, 0xB52E0000, 0x83AD82A9, 0x83B582C5, 0x95CF8D58, 0x82B782E9  /* fzgx-allow: A1 retail data bytes */,
    0x83528393, 0x8367838D, 0x815B8389, 0x82F09149, 0x82F182C5, 0x82AD82BE, 0x82B382A2, 0x81420000  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_37C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_3B8__fzgx_offset_0, 0x4D6F7665, 0x2083AD20  /* fzgx-allow: A1 retail data bytes */,
    0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063, 0x68616E67, 0x65205275  /* fzgx-allow: A1 retail data bytes */,
    0x6D626C65, 0x20736574, 0x74696E67, 0x732E0000, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C59055  /* fzgx-allow: A1 retail data bytes */,
    0x93AE82CC, 0x90DD92E8, 0x82F095CF, 0x8D5882B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0x0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_400__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_438__fzgx_offset_0, 0x54686520, 0x436F6E74  /* fzgx-allow: A1 retail data bytes */,
    0x726F6C6C, 0x65722068, 0x61732062, 0x65656E20, 0x64697363, 0x6F6E6E65, 0x63746564, 0x2E0A2052  /* fzgx-allow: A1 retail data bytes */,
    0x65636F6E, 0x6E656374, 0x20746865, 0x20436F6E, 0x74726F6C, 0x6C657220, 0x696E2053, 0x6F636B65  /* fzgx-allow: A1 retail data bytes */,
    0x74202564, 0x206F720A, 0x20707265, 0x73732074, 0x68652041, 0x20427574, 0x746F6E20, 0x6F6E2061  /* fzgx-allow: A1 retail data bytes */,
    0x6E6F7468, 0x65722E00, 0x83528393, 0x8367838D, 0x815B8389, 0x82AA8A4F, 0x82B382EA, 0x82DC82B5  /* fzgx-allow: A1 retail data bytes */,
    0x82BD8142, 0xA835283, 0x93836783, 0x8D815B83, 0x89837C81, 0x5B836725, 0x6482C982, 0xB382B582  /* fzgx-allow: A1 retail data bytes */,
    0xC882A882, 0xB782A981, 0x410A91BC, 0x82CC8352, 0x83938367, 0x838D815B, 0x838982C5, 0x839F837B  /* fzgx-allow: A1 retail data bytes */,
    0x835E8393, 0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_480__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_4F0__fzgx_offset_0, 0x59455300, 0x82CD82A2, 0x0, (u32)lbl_4_data_578__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_57C__fzgx_offset_0, 0x4E4F0000, 0x82A282A2, 0x82A60000  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_59C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_5A0__fzgx_offset_0, 0x4368616E, 0x6765204F  /* fzgx-allow: A1 retail data bytes */,
    0x7074696F, 0x6E205365, 0x7474696E, 0x67730000, 0x83498376, 0x83568387, 0x839390DD, 0x92E882F0  /* fzgx-allow: A1 retail data bytes */,
    0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[216]; void *v[(0x958 - 0x5F8) / 4]; } fzgx_pool_init_lbl_4_data_5F8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_5C0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_5D8__fzgx_offset_0, 0x41646A75, 0x73742074  /* fzgx-allow: A1 retail data bytes */,
    0x68652043, 0x616C6962, 0x72617469, 0x6F6E2E0A, 0x50726573, 0x73207468, 0x65204120, 0x42757474  /* fzgx-allow: A1 retail data bytes */,
    0x6F6E206F, 0x6E207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0xA796F75, 0x2077616E, 0x74206164  /* fzgx-allow: A1 retail data bytes */,
    0x6A757374, 0x65642E00, 0x83528393, 0x8367838D, 0x815B8389, 0x82CC834C, 0x8383838A, 0x8375838C  /* fzgx-allow: A1 retail data bytes */,
    0x815B8356, 0x83878393, 0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420A95, 0xCF8D5882, 0xB782E983  /* fzgx-allow: A1 retail data bytes */,
    0x52839383, 0x67838D81, 0x5B838982, 0xC5839F82, 0xF0899F82, 0xB582C482, 0xAD82BE82, 0xB382A281  /* fzgx-allow: A1 retail data bytes */,
    0x42000000, (u32)lbl_4_data_610__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_660__fzgx_offset_0, 0x43757374  /* fzgx-allow: A1 retail data bytes */,
    0x6F6D697A, 0x65207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0x2E0A5072, 0x65737320, 0x74686520  /* fzgx-allow: A1 retail data bytes */,
    0x41204275, 0x74746F6E, 0x206F6E20, 0x74686520, 0x436F6E74, 0x726F6C6C, 0x65722074, 0x6F206265  /* fzgx-allow: A1 retail data bytes */,
    0x2061646A, 0x75737465, 0x642E0000, 0x83528393, 0x8367838D, 0x815B8389, 0x82CC834A, 0x8358835E  /* fzgx-allow: A1 retail data bytes */,
    0x837D8343, 0x835982F0, 0x8D7382C8, 0x82A282DC, 0x82B78142, 0xA95CF8D, 0x5882B782, 0xE9835283  /* fzgx-allow: A1 retail data bytes */,
    0x93836783, 0x8D815B83, 0x8982C583, 0x9F82F089, 0x9F82B582, 0xC482AD82, 0xBE82B382, 0xA2814200  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_6D4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_724__fzgx_offset_0, 0x436F6E74, 0x726F6C6C  /* fzgx-allow: A1 retail data bytes */,
    0x65722052, 0x756D626C, 0x65205365, 0x7474696E, 0x67732E0A, 0x20507265, 0x73732074, 0x68652041  /* fzgx-allow: A1 retail data bytes */,
    0x20427574, 0x746F6E20, 0x746F2073, 0x656C6563, 0x74207468, 0x6520436F, 0x6E74726F, 0x6C6C6572  /* fzgx-allow: A1 retail data bytes */,
    0x2E000000, 0x83528393, 0x8367838D, 0x815B8389, 0x82CC9055, 0x93AE82CC, 0x90DD92E8, 0x82F08D73  /* fzgx-allow: A1 retail data bytes */,
    0x82C882A2, 0x82DC82B7, 0x81420A83, 0x52839383, 0x67838D81, 0x5B838982, 0xF0914982, 0xF182C583  /* fzgx-allow: A1 retail data bytes */,
    0x9F82F089, 0x9F82B582, 0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_790__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_7DC__fzgx_offset_0, (u32)lbl_4_data_400__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_438__fzgx_offset_0, 0x53617665, 0x20636861, 0x6E676573, 0x3F000000, 0x95CF8D58, 0x82F095DB, 0x91B682B5  /* fzgx-allow: A1 retail data bytes */,
    0x82DC82B7, 0x82A98148, 0x0, (u32)lbl_4_data_85C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_86C__fzgx_offset_0, 0x49732074, 0x68697320, 0x4F4B3F00, 0x82B182EA, 0x82C582E6, 0x82EB82B5, 0x82A282C5  /* fzgx-allow: A1 retail data bytes */,
    0x82B782A9, 0x81480000, (u32)lbl_4_data_89C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8A8__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    0x8163826E, 0x826D0000, (u32)lbl_4_data_8D8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8D8__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    0x826E8265, 0x82650000, (u32)lbl_4_data_8F8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8F8__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    0x4368616E, 0x67652043, 0x6F6E7472, 0x6F6C6C65, 0x72205365, 0x7474696E, 0x67730000, 0x83528393  /* fzgx-allow: A1 retail data bytes */,
    0x8367838D, 0x815B8389, 0x82CC90DD, 0x92E882F0, 0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[557]; void *v[(0x120C - 0x958) / 4]; } fzgx_pool_init_lbl_4_data_958 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_918__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_934__fzgx_offset_0, 0x4D616E61, 0x6765204D,
    0x656D6F72, 0x79204361, 0x72640000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x8AC7979D,
    0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420000, (u32)lbl_4_data_970__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_984__fzgx_offset_0, 0x53656C65, 0x63742053, 0x63726565, 0x6E205365, 0x7474696E, 0x67732000,
    0x89E696CA, 0x8382815B, 0x836882CC, 0x90DD92E8, 0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_9C0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_9D8__fzgx_offset_0, 0x55736520, 0x83AD206F,
    0x722083B5, 0x20746F20, 0x63686F6F, 0x73652061, 0x206D6F64, 0x65200000, 0x83AD82A9, 0x83B582CC,
    0x8DB68945, 0x82C58382, 0x815B8368, 0x82F09149, 0x82F182C5, 0x82AD82BE, 0x82B382A2, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_A10__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_A30__fzgx_offset_0, 0x4E6F726D, 0x616C0000,
    0x836D815B, 0x837D838B, 0x8365838C, 0x83720000, (u32)lbl_4_data_A70__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_A78__fzgx_offset_0, 0x57696465, 0x20536372, 0x65656E00, 0x838F8343, 0x83688365, 0x838C8372,
    0x0, (u32)lbl_4_data_AA0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_AAC__fzgx_offset_0, 0x4D6F7665,
    0x20746865, 0x20436F6E, 0x74726F6C, 0x20537469, 0x636B2061, 0x726F756E, 0x6420696E, 0x20612063,
    0x6972636C, 0x6520756E, 0x74696C20, 0x74686520, 0x66696775, 0x72657320, 0x6F6E2074, 0x68650A20,
    0x6C656674, 0x20736964, 0x6520646F, 0x206E6F74, 0x20636861, 0x6E67652E, 0x2041646A, 0x75737420,
    0x706C6179, 0x20757369, 0x6E672074, 0x68652083, 0xB520436F, 0x6E74726F, 0x6C205061, 0x642E0A20,
    0x50726573, 0x73207468, 0x65205820, 0x42757474, 0x6F6E2074, 0x6F207265, 0x7475726E, 0x20746F20,
    0x74686520, 0x64656661, 0x756C7420, 0x73657474, 0x696E6773, 0x2E000000, 0x8DB691A4, 0x82CC907D,
    0x8C6082AA, 0x95CF89BB, 0x82B582C8, 0x82AD82C8, 0x82E982DC, 0x82C583AD, 0x82F088EA, 0x947482C9,
    0x89F182B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0xA83B582, 0xC5975682, 0xD182F092, 0xB290AE82,
    0xB582C482, 0xAD82BE82, 0xB382A281, 0x420A83B4, 0x82C58F89, 0x8AFA90DD, 0x92E882C9, 0x96DF82B9,
    0x82DC82B7, 0x81420000, (u32)lbl_4_data_AD4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_B90__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x5475726E, 0x20746865, 0x20737465, 0x6572696E, 0x67207768, 0x65656C20, 0x4C656674, 0x20616E64,
    0x20526967, 0x68742061, 0x6E642070, 0x72657373, 0xA746865, 0x20412042, 0x7574746F, 0x6E206174,
    0x20746865, 0x20706F69, 0x6E742079, 0x6F752077, 0x616E7420, 0x746F2073, 0x65742061, 0x73207468,
    0x650A206C, 0x696D6974, 0x2E205573, 0x65207468, 0x65204C20, 0x616E6420, 0x52204275, 0x74746F6E,
    0x7320746F, 0x2061646A, 0x75737420, 0x67616D65, 0x20706C61, 0x792E2000, 0x836E8393, 0x8368838B,
    0x82F08DB6, 0x894582C9, 0x89F182B5, 0x81418CC0, 0x8A4582C6, 0x82B582BD, 0x82A288CA, 0x927582C5,  /* fzgx-allow: A1 retail data bytes */
    0x839F82F0, 0x899F82B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0xA826B81, 0x95827183, 0x67838A83,
    0x4B815B83, 0x7B835E83, 0x9382C597, 0x5682D182, 0xF092B290, 0xAE82B582, 0xC482AD82, 0xBE82B382,
    0xA281420A, 0x83B482C5, 0x8F898AFA, 0x90DD92E8, 0x82C996DF, 0x82B982DC, 0x82B78142, 0x0,
    (u32)lbl_4_data_C18__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_CB0__fzgx_offset_0, 0x4265666F, 0x72652063,
    0x6F727265, 0x6374696F, 0x6E000000, 0x95E290B3, 0x914F0000, (u32)lbl_4_data_D50__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_D64__fzgx_offset_0, 0x41667465, 0x7220636F, 0x72726563, 0x74696F6E, 0x0,
    0x95E290B3, 0x8CE30000, (u32)lbl_4_data_D84__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_D98__fzgx_offset_0,
    0x47616D65, 0x20446174, 0x6120436F, 0x6E74726F, 0x6C730A49, 0x6E736572, 0x74206120, 0x4D656D6F,
    0x72792043, 0x61726420, 0x696E746F, 0x20536C6F, 0x7420412E, 0x0, 0x8351815B, 0x83808366,
    0x815B835E, 0x82CC9180, 0x8DEC0A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F083, 0x58838D83,  /* fzgx-allow: A1 retail data bytes */
    0x62836782, 0x6082C993, 0xFC82EA82, 0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_DB8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_DF0__fzgx_offset_0, 0x4C6F6164, 0x2047616D, 0x65204461, 0x74610000,
    0x8351815B, 0x83808366, 0x815B835E, 0x82CC838D, 0x815B8368, 0x0, (u32)lbl_4_data_E48__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_E58__fzgx_offset_0, 0x53617665, 0x2047616D, 0x65204461, 0x74610000,
    0x8351815B, 0x83808366, 0x815B835E, 0x82CC835A, 0x815B8375, 0x0, (u32)lbl_4_data_E88__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_E98__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20, 0x47616D65,
    0x20446174, 0x61206F6E, 0x20746869, 0x73204D65, 0x6D6F7279, 0x20436172, 0x642E0A20, 0x53617669,
    0x6E67206E, 0x65772064, 0x6174612E, 0x0, 0x83818382, 0x838A815B, 0x834A815B, 0x836882C9,
    0xA835181, 0x5B838083, 0x66815B83, 0x5E82AA8C, 0xA982C282, 0xA982E882, 0xDC82B982, 0xF181420A,
    0x90568B4B, 0x835A815B, 0x837582B5, 0x82DC82B7, 0x81420000, (u32)lbl_4_data_EC8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_F08__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20, 0x47616D65, 0x20446174,
    0x61206F6E, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x2E0A4966, 0x20796F75, 0x20736176,
    0x652C2074, 0x68652047, 0x616D6520, 0x44617461, 0x20637572, 0x72656E74, 0x6C79206C, 0x6F616465,
    0x640A7769, 0x6C6C2061, 0x6C6C2062, 0x65206C6F, 0x73742E20, 0x49732074, 0x68617420, 0x4F4B3F00,
    0x83818382, 0x838A815B, 0x834A815B, 0x836882C9, 0x8351815B, 0x83808366, 0x815B835E, 0x82AA8CA9,  /* fzgx-allow: A1 retail data bytes */
    0x82C282A9, 0x82E882DC, 0x82B982F1, 0x81420A90, 0x568B4B83, 0x5A815B83, 0x7582B782, 0xE982C68C,  /* fzgx-allow: A1 retail data bytes */
    0xBB8DDD83, 0x8D815B83, 0x6882B382, 0xEA82C482, 0xA282E983, 0x51815B83, 0x80836681, 0x5B835E82,  /* fzgx-allow: A1 retail data bytes */
    0xAA0A9153, 0x82C48FC1, 0x82A682C4, 0x82B582DC, 0x82A282DC, 0x82B782AA, 0x814182E6, 0x82EB82B5,  /* fzgx-allow: A1 retail data bytes */
    0x82A282C5, 0x82B782A9, 0x3F000000, (u32)lbl_4_data_F64__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_FD8__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053,
    0x6C6F7420, 0x412E0000, 0x8358838D, 0x83628367, 0x826082C9, 0xA838183, 0x82838A81, 0x5B834A81,
    0x5B836882, 0xAA8CA982, 0xC282A982, 0xE882DC82, 0xB982F181, 0x42000000, (u32)lbl_4_data_107C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10A0__fzgx_offset_0, 0x52656769, 0x73746572, 0x20746869, 0x73206E61,
    0x6D65206F, 0x6E207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20536C6F, 0x7420412E,
    0x0, 0x82B182CC, 0x96BC914F, 0x82C58381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C90A93,  /* fzgx-allow: A1 retail data bytes */
    0x6F985E82, 0xB582C482, 0xE082E682, 0xEB82B582, 0xA282C582, 0xB782A93F, 0x0, (u32)lbl_4_data_10E8__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_111C__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20,
    0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x6C6F7420, 0x412E0A20, 0x54686520, 0x67616D65,
    0x2063616E, 0x6E6F7420, 0x62652073, 0x61766564, 0x2E000000, 0x8358838D, 0x83628367, 0x826082C9,
    0x83818382, 0x838A815B, 0x834A815B, 0x836882AA, 0x8CA982C2, 0x82A982E8, 0x82DC82B9, 0x82F18142,
    0xA835A81, 0x5B837582, 0xC582AB82, 0xDC82B982, 0xF182C582, 0xB582BD81, 0x42000000, (u32)lbl_4_data_116C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_11AC__fzgx_offset_0
}};
u8 lbl_4_data_11AC__fzgx_offset_60 = 0xFF;
s16 lbl_4_data_11AC__fzgx_offset_62 = -1;
static union { u32 w[143]; char v[0x144C - 0x1210]; } fzgx_pool_init_lbl_4_data_1210 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x257300FF, 0xFFFF0000, 0x6F707469, 0x6F6E2E63, 0x0, 0x53656C53, 0x5F446973, 0x70506F6C  /* fzgx-allow: A1 retail data bytes */,
    0x79676F6E, 0x42470000, 0x53656C53, 0x5F446973, 0x70537072, 0x69746542, 0x47000000, 0x6F707469  /* fzgx-allow: A1 retail data bytes */,
    0x6F6E5F63, 0x6F6D6D6F, 0x6E5F6469, 0x73700000, 0x534D445F, 0x4F505449, 0x4F4E5F4D, 0x454E5500  /* fzgx-allow: A1 retail data bytes */,
    0x0, 0x0, 0x0, 0x0, (u32)fn_4_D10__fzgx_offset_0, (u32)fn_4_D7C__fzgx_offset_0, (u32)fn_4_EA0__fzgx_offset_0, 0x534D445F  /* fzgx-allow: A1 retail data bytes */,
    0x4F505449, 0x4F4E5F53, 0x4156455F, 0x57414954, 0x0, 0x0, 0x0, (u32)fn_4_9B20__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_9C14__fzgx_offset_0, (u32)fn_4_A734__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43, 0x54524C5F, 0x4D454E55, 0x0  /* fzgx-allow: A1 retail data bytes */,
    0x0, 0x0, (u32)fn_4_7C38__fzgx_offset_0, (u32)fn_4_7CA4__fzgx_offset_0, (u32)fn_4_7D94__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43  /* fzgx-allow: A1 retail data bytes */,
    0x4152445F, 0x4D454E55, 0x0, 0x0, 0x0, (u32)fn_4_80EC__fzgx_offset_0, (u32)fn_4_8158__fzgx_offset_0, (u32)fn_4_8248__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    0x534D445F, 0x4F505449, 0x4F4E5F57, 0x49444500, 0x0, 0x0, 0x0, 0x0  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_869C__fzgx_offset_0, (u32)fn_4_8720__fzgx_offset_0, (u32)fn_4_898C__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43, 0x414C4942, 0x0  /* fzgx-allow: A1 retail data bytes */,
    0x0, 0x0, 0x0, (u32)fn_4_347C__fzgx_offset_0, (u32)fn_4_3568__fzgx_offset_0, (u32)fn_4_406C__fzgx_offset_0, 0x534D445F, 0x4F505449  /* fzgx-allow: A1 retail data bytes */,
    0x4F4E5F52, 0x554D424C, 0x45000000, 0x0, 0x0, 0x0, (u32)fn_4_4784__fzgx_offset_0, (u32)fn_4_4834__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_4B10__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F50, 0x43555354, 0x0, 0x0, 0x0  /* fzgx-allow: A1 retail data bytes */,
    0x0, (u32)fn_4_6678__fzgx_offset_0, (u32)fn_4_6720__fzgx_offset_0, (u32)fn_4_78E0__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43, 0x4152445F  /* fzgx-allow: A1 retail data bytes */,
    0x4D414E41, 0x47450000, 0x0, 0x0, (u32)fn_4_89E4__fzgx_offset_0, (u32)fn_4_8A54__fzgx_offset_0, (u32)fn_4_8AE0__fzgx_offset_0, 0x534D445F  /* fzgx-allow: A1 retail data bytes */,
    0x4F505449, 0x4F4E5F43, 0x4152445F, 0x47444154, 0x41000000, 0x0, 0x0, (u32)fn_4_8DC0__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_8E38__fzgx_offset_0, (u32)fn_4_9A78__fzgx_offset_0, 0x4D656D6F, 0x72792043, 0x61726400, 0x83818382, 0x838A815B, 0x834A815B  /* fzgx-allow: A1 retail data bytes */,
    0x83680000, 0x53637265, 0x656E204D, 0x6F646500, 0x89E696CA, 0x8382815B, 0x83680000  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[21]; OptionRow v[3]; } fzgx_pool_init_lbl_4_data_144C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4D0000, (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, 0x4E0000  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1418__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1424__fzgx_offset_0, 0x4F0000, (u32)lbl_4_data_1434__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1440__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[1518]; char v[0x2C58 - 0x14A0]; } fzgx_pool_init_lbl_4_data_14A0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6F707469, 0x6F6E5F6D, 0x656E755F, 0x64697370, 0x0, 0x583A2534, 0x640A0000, 0x593A2534  /* fzgx-allow: A1 retail data bytes */,
    0x64000000, 0x25732534, 0x64000000, 0x25346400, 0x6F707469, 0x6F6E5F63, 0x616C6962, 0x5F646973  /* fzgx-allow: A1 retail data bytes */,
    0x7000FF00, 0xFFFF0000, 0x25732564, 0x81632020, 0x20000000, 0x25732564, 0x81632573, 0x0  /* fzgx-allow: A1 retail data bytes */,
    0x52756D62, 0x6C654D61, 0x696E0000, 0x6F707469, 0x6F6E5F72, 0x756D626C, 0x655F6469, 0x73700000  /* fzgx-allow: A1 retail data bytes */,
    0x81FF811F, 0x831F0000, 0x803FFF1F, 0x80303F1F, 0x80F03F1F, 0x4E6F7420, 0x436F6E6E, 0x65637465  /* fzgx-allow: A1 retail data bytes */,
    0x64000000, 0x96A290DA, 0x91B10000, 0x53706565, 0x6420466F, 0x72636500, 0x83588373, 0x815B8368  /* fzgx-allow: A1 retail data bytes */,
    0x83748348, 0x815B8358, 0x0, 0x53706565, 0x6420466F, 0x72636520, 0x616E6420, 0x50656461  /* fzgx-allow: A1 retail data bytes */,
    0x6C20556E, 0x69740000, 0x83588373, 0x815B8368, 0x83748348, 0x815B8358, 0x81958379, 0x835F838B  /* fzgx-allow: A1 retail data bytes */,
    0x8386836A, 0x83628367, 0x0, 0x41726361, 0x64650000, 0x8341815B, 0x8350815B, 0x83688341  /* fzgx-allow: A1 retail data bytes */,
    0x815B8350, 0x815B8368, 0x8341815B, 0x8350815B, 0x83688341, 0x815B8350, 0x815B8368, 0x8341815B  /* fzgx-allow: A1 retail data bytes */,
    0x8350815B, 0x83680000, (u32)lbl_4_data_1534__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_154C__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_156C__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_15AC__fzgx_offset_0, (u32)lbl_4_data_15B4__fzgx_offset_0, 0x0, 0x0, 0x0, 0x0  /* fzgx-allow: A1 retail data bytes */,
    0x81638163, 0x81638163, 0x81638163, 0x81638163, 0x81638163, 0x81630000, 0x81638163, 0x81638163  /* fzgx-allow: A1 retail data bytes */,
    0x81638163, 0x0, 0x81630000, 0x81638163, 0x81638163, 0x81638163, 0x81638163, 0x0  /* fzgx-allow: A1 retail data bytes */,
    0x81638163, 0x81638163, 0x81638163, 0x81638163, 0x81630000, 0xA400A0, (u32)lbl_4_data_1660__fzgx_offset_0, 0xF800B4  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1678__fzgx_offset_0, 0x14C00C8, (u32)lbl_4_data_1688__fzgx_offset_0, 0xD600DC, (u32)lbl_4_data_168C__fzgx_offset_0, 0xD600F0, (u32)lbl_4_data_168C__fzgx_offset_0, 0xC60104  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_16A0__fzgx_offset_0, 0xD60118, (u32)lbl_4_data_168C__fzgx_offset_0, 0xD6012C, (u32)lbl_4_data_168C__fzgx_offset_0, 0xA40140, (u32)lbl_4_data_1660__fzgx_offset_0, 0x53746565  /* fzgx-allow: A1 retail data bytes */,
    0x72000000, 0x83588365, 0x8341838A, 0x8393834F, 0x8DB68945, 0x81630000, 0x536C6964, 0x65204C65  /* fzgx-allow: A1 retail data bytes */,
    0x66742052, 0x69676874, 0x0, 0x83588389, 0x83438368, 0x8DB68945, 0x81638163, 0x81630000  /* fzgx-allow: A1 retail data bytes */,
    0x41646A75, 0x73742043, 0x656E7465, 0x72206F66, 0x20477261, 0x76697479, 0x0, 0x83578383  /* fzgx-allow: A1 retail data bytes */,
    0x83938376, 0x8F649053, 0x88DA93AE, 0x81630000, 0x41646A75, 0x73742056, 0x69657700, 0x8E8B935F  /* fzgx-allow: A1 retail data bytes */,
    0x95CF8D58, 0x81638163, 0x81638163, 0x81630000, 0x41636365, 0x6C657261, 0x74650000, 0x8341834E  /* fzgx-allow: A1 retail data bytes */,
    0x835A838B, 0x81638163, 0x81638163, 0x81630000, 0x41697220, 0x4272616B, 0x65000000, 0x83478341  /* fzgx-allow: A1 retail data bytes */,
    0x8375838C, 0x815B834C, 0x81638163, 0x81630000, 0x53696465, 0x20417474, 0x61636B00, 0x83548343  /* fzgx-allow: A1 retail data bytes */,
    0x83688341, 0x835E8362, 0x834E8163, 0x81630000, 0x5370696E, 0x20417474, 0x61636B00, 0x83588373  /* fzgx-allow: A1 retail data bytes */,
    0x83938341, 0x835E8362, 0x834E8163, 0x81630000, 0x426F6F73, 0x74000000, 0x8375815B, 0x8358835E  /* fzgx-allow: A1 retail data bytes */,
    0x815B8163, 0x81638163, 0x81630000, (u32)lbl_4_data_16FC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1704__fzgx_offset_0, (u32)lbl_4_data_1718__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_172C__fzgx_offset_0, (u32)lbl_4_data_1740__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_175C__fzgx_offset_0, (u32)lbl_4_data_1770__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_177C__fzgx_offset_0, (u32)lbl_4_data_1790__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_179C__fzgx_offset_0, (u32)lbl_4_data_17B0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_17BC__fzgx_offset_0, (u32)lbl_4_data_17D0__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_17DC__fzgx_offset_0, (u32)lbl_4_data_17F0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_17FC__fzgx_offset_0, (u32)lbl_4_data_1810__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1818__fzgx_offset_0, 0x83B52043, 0x6F6E7472, 0x6F6C2050, 0x6164204C, 0x65667420, 0x616E6420, 0x52696768  /* fzgx-allow: A1 retail data bytes */,
    0x74000000, 0x83B52083, 0xD0000000, 0x8F5C8E9A, 0x837B835E, 0x83938DB6, 0x89450000, 0x83B52043  /* fzgx-allow: A1 retail data bytes */,
    0x6F6E7472, 0x6F6C2050, 0x61642055, 0x7020616E, 0x6420446F, 0x776E0000, 0x83B52083, 0xCF000000  /* fzgx-allow: A1 retail data bytes */,
    0x8F5C8E9A, 0x837B835E, 0x83938FE3, 0x89BA0000, 0x4120616E, 0x64204220, 0x42757474, 0x6F6E0000  /* fzgx-allow: A1 retail data bytes */,
    0x839F2083, 0xA0000000, 0x82608195, 0x8261837B, 0x835E8393, 0x0, 0x5820616E, 0x64205920  /* fzgx-allow: A1 retail data bytes */,
    0x42757474, 0x6F6E0000, 0x83B42083, 0xB2000000, 0x82778195, 0x8278837B, 0x835E8393, 0x0  /* fzgx-allow: A1 retail data bytes */,
    0x83AD2043, 0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x204C6566, 0x7420616E, 0x64205269, 0x67687400  /* fzgx-allow: A1 retail data bytes */,
    0x83AD2083, 0xD0000000, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E8DB6  /* fzgx-allow: A1 retail data bytes */,
    0x89450000, 0x83AD2043, 0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x20557020, 0x616E6420, 0x446F776E  /* fzgx-allow: A1 retail data bytes */,
    0x0, 0x83AD2083, 0xCF000000, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362  /* fzgx-allow: A1 retail data bytes */,
    0x834E8FE3, 0x89BA0000, 0x83A62043, 0x20537469, 0x636B204C, 0x65667420, 0x616E6420, 0x52696768  /* fzgx-allow: A1 retail data bytes */,
    0x74000000, 0x83A62083, 0xD0000000, 0x82628358, 0x83658342, 0x8362834E, 0x8DB68945, 0x0  /* fzgx-allow: A1 retail data bytes */,
    0x83A62043, 0x20537469, 0x636B2055, 0x7020616E, 0x6420446F, 0x776E0000, 0x83A62083, 0xCF000000  /* fzgx-allow: A1 retail data bytes */,
    0x82628358, 0x83658342, 0x8362834E, 0x8FE389BA, 0x0, 0x4C20616E, 0x64205220, 0x42757474  /* fzgx-allow: A1 retail data bytes */,
    0x6F6E0000, 0x826B8195, 0x82718367, 0x838A834B, 0x815B837B, 0x835E8393, 0x0, 0x4E6F2051  /* fzgx-allow: A1 retail data bytes */,
    0x756F7461, 0x73000000, 0x8A8482E8, 0x939682C4, 0x82C882B5, 0x0, (u32)lbl_4_data_1904__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_192C__fzgx_offset_0, (u32)lbl_4_data_193C__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1960__fzgx_offset_0, (u32)lbl_4_data_1970__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1988__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1998__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19B0__fzgx_offset_0, (u32)lbl_4_data_19C0__fzgx_offset_0, (u32)lbl_4_data_19E0__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_19E0__fzgx_offset_0, (u32)lbl_4_data_19E0__fzgx_offset_0, (u32)lbl_4_data_19E0__fzgx_offset_0, (u32)lbl_4_data_19E8__fzgx_offset_0, (u32)lbl_4_data_1A04__fzgx_offset_0, (u32)lbl_4_data_1A24__fzgx_offset_0, (u32)lbl_4_data_1A24__fzgx_offset_0, (u32)lbl_4_data_1A24__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1A24__fzgx_offset_0, (u32)lbl_4_data_1A2C__fzgx_offset_0, (u32)lbl_4_data_1A48__fzgx_offset_0, (u32)lbl_4_data_1A64__fzgx_offset_0, (u32)lbl_4_data_1A64__fzgx_offset_0, (u32)lbl_4_data_1A64__fzgx_offset_0, (u32)lbl_4_data_1A64__fzgx_offset_0, (u32)lbl_4_data_1A6C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1A80__fzgx_offset_0, (u32)lbl_4_data_1A98__fzgx_offset_0, (u32)lbl_4_data_1A98__fzgx_offset_0, (u32)lbl_4_data_1A98__fzgx_offset_0, (u32)lbl_4_data_1A98__fzgx_offset_0, (u32)lbl_4_data_1AA0__fzgx_offset_0, (u32)lbl_4_data_1AB4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AC4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1ADC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AE8__fzgx_offset_0, 0x53746565, 0x72696E67  /* fzgx-allow: A1 retail data bytes */,
    0x20576865, 0x656C204C, 0x65667420, 0x616E6420, 0x52696768, 0x74000000, 0x836E8393, 0x8368838B  /* fzgx-allow: A1 retail data bytes */,
    0x8DB68945, 0x0, 0x41636365, 0x6C657261, 0x746F7220, 0x616E6420, 0x42726561, 0x6B205065  /* fzgx-allow: A1 retail data bytes */,
    0x64616C00, 0x8341834E, 0x835A838B, 0x81958375, 0x838C815B, 0x834C8379, 0x835F838B, 0x0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1904__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_192C__fzgx_offset_0, (u32)lbl_4_data_193C__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1960__fzgx_offset_0, (u32)lbl_4_data_1970__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1988__fzgx_offset_0, (u32)lbl_4_data_1998__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19B0__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1C78__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1C98__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1AB4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AC4__fzgx_offset_0, (u32)lbl_4_data_1CA8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1CC4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1ADC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AE8__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    0x83B52043, 0x6F6E7472, 0x6F6C2050, 0x6164204C, 0x65667400, 0x83B5204C, 0x65667400, 0x8F5C8E9A  /* fzgx-allow: A1 retail data bytes */,
    0x837B835E, 0x83938DB6, 0x0, 0x83B52043, 0x6F6E7472, 0x6F6C2050, 0x61642052, 0x69676874  /* fzgx-allow: A1 retail data bytes */,
    0x0, 0x83B52052, 0x69676874, 0x0, 0x8F5C8E9A, 0x837B835E, 0x83938945, 0x0  /* fzgx-allow: A1 retail data bytes */,
    0x83B52043, 0x6F6E7472, 0x6F6C2050, 0x61642044, 0x6F776E00, 0x83B52044, 0x6F776E00, 0x8F5C8E9A  /* fzgx-allow: A1 retail data bytes */,
    0x837B835E, 0x839389BA, 0x0, 0x83B52043, 0x6F6E7472, 0x6F6C2050, 0x61642055, 0x70000000  /* fzgx-allow: A1 retail data bytes */,
    0x83B52055, 0x70000000, 0x8F5C8E9A, 0x837B835E, 0x83938FE3, 0x0, 0x5A204275, 0x74746F6E  /* fzgx-allow: A1 retail data bytes */,
    0x0, 0x83A42000, 0x8279837B, 0x835E8393, 0x0, 0x41204275, 0x74746F6E, 0x0  /* fzgx-allow: A1 retail data bytes */,
    0x839F0000, 0x8260837B, 0x835E8393, 0x0, 0x42204275, 0x74746F6E, 0x0, 0x83A02000  /* fzgx-allow: A1 retail data bytes */,
    0x8261837B, 0x835E8393, 0x0, 0x58204275, 0x74746F6E, 0x0, 0x83B42000, 0x8277837B  /* fzgx-allow: A1 retail data bytes */,
    0x835E8393, 0x0, 0x59204275, 0x74746F6E, 0x0, 0x83B22000, 0x8278837B, 0x835E8393  /* fzgx-allow: A1 retail data bytes */,
    0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x204C6566, 0x74000000, 0x83528393  /* fzgx-allow: A1 retail data bytes */,
    0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E8DB6, 0x0, 0x83AD2043, 0x6F6E7472  /* fzgx-allow: A1 retail data bytes */,
    0x6F6C2053, 0x7469636B, 0x20526967, 0x68740000, 0x83AD2052, 0x69676874, 0x0, 0x83528393  /* fzgx-allow: A1 retail data bytes */,
    0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E8945, 0x0, 0x83AD2043, 0x6F6E7472  /* fzgx-allow: A1 retail data bytes */,
    0x6F6C2053, 0x7469636B, 0x20446F77, 0x6E000000, 0x83AD2044, 0x6F776E00, 0x83528393, 0x8367838D  /* fzgx-allow: A1 retail data bytes */,
    0x815B838B, 0x83588365, 0x83428362, 0x834E89BA, 0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053  /* fzgx-allow: A1 retail data bytes */,
    0x7469636B, 0x20557000, 0x83AD2055, 0x70000000, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365  /* fzgx-allow: A1 retail data bytes */,
    0x83428362, 0x834E8FE3, 0x0, 0x83A62043, 0x20537469, 0x636B204C, 0x65667400, 0x83AD204C  /* fzgx-allow: A1 retail data bytes */,
    0x65667400, 0x82628358, 0x83658342, 0x8362834E, 0x8DB60000, 0x83A62043, 0x20537469, 0x636B2052  /* fzgx-allow: A1 retail data bytes */,
    0x69676874, 0x0, 0x83A62052, 0x69676874, 0x0, 0x82628358, 0x83658342, 0x8362834E  /* fzgx-allow: A1 retail data bytes */,
    0x89450000, 0x83A62043, 0x20537469, 0x636B2044, 0x6F776E00, 0x83A62044, 0x6F776E00, 0x82628358  /* fzgx-allow: A1 retail data bytes */,
    0x83658342, 0x8362834E, 0x89BA0000, 0x83A62043, 0x20537469, 0x636B2055, 0x70000000, 0x83A62055  /* fzgx-allow: A1 retail data bytes */,
    0x70000000, 0x82628358, 0x83658342, 0x8362834E, 0x8FE30000, 0x4C204275, 0x74746F6E, 0x0  /* fzgx-allow: A1 retail data bytes */,
    0x83A12000, 0x826B8367, 0x838A834B, 0x815B837B, 0x835E8393, 0x0, 0x52204275, 0x74746F6E  /* fzgx-allow: A1 retail data bytes */,
    0x0, 0x2083AF20, 0x0, 0x82718367, 0x838A834B, 0x815B837B, 0x835E8393, 0x0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1E60__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E7C__fzgx_offset_0, (u32)lbl_4_data_1E8C__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EB0__fzgx_offset_0, (u32)lbl_4_data_1EC0__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1EDC__fzgx_offset_0, (u32)lbl_4_data_1EEC__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F08__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1F18__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F28__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1F34__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F44__fzgx_offset_0, (u32)lbl_4_data_1F50__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F60__fzgx_offset_0, (u32)lbl_4_data_1F6C__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F7C__fzgx_offset_0, (u32)lbl_4_data_1F88__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F98__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1FA4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1FBC__fzgx_offset_0, (u32)lbl_4_data_1FD8__fzgx_offset_0, (u32)lbl_4_data_1FF0__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1FF0__fzgx_offset_0, (u32)lbl_4_data_1FF0__fzgx_offset_0, (u32)lbl_4_data_1FF0__fzgx_offset_0, (u32)lbl_4_data_1FFC__fzgx_offset_0, (u32)lbl_4_data_2018__fzgx_offset_0, (u32)lbl_4_data_2030__fzgx_offset_0, (u32)lbl_4_data_2030__fzgx_offset_0, (u32)lbl_4_data_2030__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_2030__fzgx_offset_0, (u32)lbl_4_data_2038__fzgx_offset_0, (u32)lbl_4_data_2054__fzgx_offset_0, (u32)lbl_4_data_2068__fzgx_offset_0, (u32)lbl_4_data_2068__fzgx_offset_0, (u32)lbl_4_data_2068__fzgx_offset_0, (u32)lbl_4_data_2068__fzgx_offset_0, (u32)lbl_4_data_2070__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_208C__fzgx_offset_0, (u32)lbl_4_data_209C__fzgx_offset_0, (u32)lbl_4_data_209C__fzgx_offset_0, (u32)lbl_4_data_209C__fzgx_offset_0, (u32)lbl_4_data_209C__fzgx_offset_0, (u32)lbl_4_data_20A4__fzgx_offset_0, (u32)lbl_4_data_20B4__fzgx_offset_0, (u32)lbl_4_data_20C8__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_20C8__fzgx_offset_0, (u32)lbl_4_data_20C8__fzgx_offset_0, (u32)lbl_4_data_20C8__fzgx_offset_0, (u32)lbl_4_data_20D4__fzgx_offset_0, (u32)lbl_4_data_20E4__fzgx_offset_0, (u32)lbl_4_data_20F4__fzgx_offset_0, (u32)lbl_4_data_20F4__fzgx_offset_0, (u32)lbl_4_data_20F4__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_20F4__fzgx_offset_0, (u32)lbl_4_data_20FC__fzgx_offset_0, (u32)lbl_4_data_210C__fzgx_offset_0, (u32)lbl_4_data_211C__fzgx_offset_0, (u32)lbl_4_data_211C__fzgx_offset_0, (u32)lbl_4_data_211C__fzgx_offset_0, (u32)lbl_4_data_211C__fzgx_offset_0, (u32)lbl_4_data_2124__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_2134__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2144__fzgx_offset_0, (u32)lbl_4_data_2158__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_216C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1ADC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AE8__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    0x53746565, 0x72696E67, 0x20576865, 0x656C204C, 0x65667400, 0x836E8393, 0x8368838B, 0x8DB60000  /* fzgx-allow: A1 retail data bytes */,
    0x53746565, 0x72696E67, 0x20576865, 0x656C2052, 0x69676874, 0x0, 0x836E8393, 0x8368838B  /* fzgx-allow: A1 retail data bytes */,
    0x89450000, 0x41636365, 0x6C657261, 0x746F7220, 0x50656461, 0x6C000000, 0x8341834E, 0x835A838B  /* fzgx-allow: A1 retail data bytes */,
    0x8379835F, 0x838B0000, 0x4272616B, 0x65205065, 0x64616C00, 0x8375838C, 0x815B834C, 0x8379835F  /* fzgx-allow: A1 retail data bytes */,
    0x838B0000, (u32)lbl_4_data_1E60__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E7C__fzgx_offset_0, (u32)lbl_4_data_1E8C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EB0__fzgx_offset_0, (u32)lbl_4_data_1EC0__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1EDC__fzgx_offset_0, (u32)lbl_4_data_1EEC__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1F08__fzgx_offset_0, (u32)lbl_4_data_1F18__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F28__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1F34__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F44__fzgx_offset_0, (u32)lbl_4_data_1F50__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F60__fzgx_offset_0, (u32)lbl_4_data_1F6C__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F7C__fzgx_offset_0, (u32)lbl_4_data_1F88__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1F98__fzgx_offset_0, (u32)lbl_4_data_2480__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2494__fzgx_offset_0, (u32)lbl_4_data_24A0__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_24B8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2134__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2144__fzgx_offset_0, (u32)lbl_4_data_2158__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_216C__fzgx_offset_0, (u32)lbl_4_data_24C4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_24D8__fzgx_offset_0, (u32)lbl_4_data_24E8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_24F4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1ADC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_1AE8__fzgx_offset_0, 0x41582043, 0x6F6E7472, 0x6F6C7300, 0x82608277, 0x82CC9180, 0x8DEC0000, (u32)lbl_4_data_2804__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2810__fzgx_offset_0, 0x44656661, 0x756C7420, 0x53657474  /* fzgx-allow: A1 retail data bytes */,
    0x696E6773, 0x0, 0x8F898AFA, 0x90DD92E8, 0x82C996DF, 0x82B70000, (u32)lbl_4_data_2834__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2848__fzgx_offset_0, 0x53696465, 0x20417474, 0x61636B3A, 0x51756963  /* fzgx-allow: A1 retail data bytes */,
    0x6B6C7920, 0x70726573, 0x73207468, 0x65204C20, 0x6F722052, 0x20427574, 0x746F6E0A, 0x20202020  /* fzgx-allow: A1 retail data bytes */,
    0x20202020, 0x20202020, 0x20202074, 0x77696365, 0x2E0A5370, 0x696E2041, 0x74746163, 0x6B3A5072  /* fzgx-allow: A1 retail data bytes */,
    0x65737320, 0x74686520, 0x4C20616E, 0x64205220, 0x42757474, 0x6F6E730A, 0x20202020, 0x20202020  /* fzgx-allow: A1 retail data bytes */,
    0x20202020, 0x20202073, 0x696D756C, 0x74616E65, 0x6F75736C, 0x7920616E, 0x64207475, 0x726E2074  /* fzgx-allow: A1 retail data bytes */,
    0x68652077, 0x6865656C, 0x2E200000, 0x83548343, 0x83688341, 0x835E8362, 0x834E8163, 0x8367838A  /* fzgx-allow: A1 retail data bytes */,
    0x834B815B, 0x825189F1, 0x88F882AB, 0xA835883, 0x73839383, 0x41835E83, 0x62834E81, 0x63836783  /* fzgx-allow: A1 retail data bytes */,
    0x8A834B81, 0x5B826B82, 0x7197BC88, 0xF882AB81, 0x95836E83, 0x93836883, 0x8B000000, (u32)lbl_4_data_2870__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_290C__fzgx_offset_0, (u32)fn_4_4B74__fzgx_offset_68, (u32)fn_4_4B74__fzgx_offset_7C, (u32)fn_4_4B74__fzgx_offset_94  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_4B74__fzgx_offset_AC, (u32)fn_4_4B74__fzgx_offset_C4, (u32)fn_4_4B74__fzgx_offset_DC, (u32)fn_4_4B74__fzgx_offset_F4, (u32)fn_4_4B74__fzgx_offset_10C, (u32)fn_4_4B74__fzgx_offset_124, (u32)fn_4_4CB8__fzgx_offset_6C, (u32)fn_4_4CB8__fzgx_offset_80  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_4CB8__fzgx_offset_98, (u32)fn_4_4CB8__fzgx_offset_B0, (u32)fn_4_4CB8__fzgx_offset_C8, (u32)fn_4_4CB8__fzgx_offset_E0, (u32)fn_4_4CB8__fzgx_offset_F8, (u32)fn_4_4CB8__fzgx_offset_110, (u32)fn_4_4CB8__fzgx_offset_128, 0x25732573  /* fzgx-allow: A1 retail data bytes */,
    0xA000000, 0x25730A00, 0x25738163, 0x25730000, (u32)fn_4_4DF8__fzgx_offset_1428, (u32)fn_4_4DF8__fzgx_offset_1408, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1308, (u32)fn_4_4DF8__fzgx_offset_12E4, (u32)fn_4_4DF8__fzgx_offset_13E0, (u32)fn_4_4DF8__fzgx_offset_13C0  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_4DF8__fzgx_offset_1398, (u32)fn_4_4DF8__fzgx_offset_1378, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1350, (u32)fn_4_4DF8__fzgx_offset_1330, (u32)fn_4_4DF8__fzgx_offset_1330  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_4DF8__fzgx_offset_1330, (u32)fn_4_4DF8__fzgx_offset_1330, (u32)fn_4_4DF8__fzgx_offset_E54, (u32)fn_4_4DF8__fzgx_offset_E34, (u32)fn_4_4DF8__fzgx_offset_E14, (u32)fn_4_4DF8__fzgx_offset_E14, (u32)fn_4_4DF8__fzgx_offset_E14, (u32)fn_4_4DF8__fzgx_offset_E14  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_4DF8__fzgx_offset_DF4, (u32)fn_4_4DF8__fzgx_offset_DF4, (u32)fn_4_4DF8__fzgx_offset_DF4, (u32)fn_4_4DF8__fzgx_offset_DF4, (u32)fn_4_4DF8__fzgx_offset_DD4, (u32)fn_4_4DF8__fzgx_offset_DB4, (u32)fn_4_4DF8__fzgx_offset_D8C, (u32)fn_4_4DF8__fzgx_offset_D6C  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_4DF8__fzgx_offset_E80, (u32)fn_4_4DF8__fzgx_offset_E80, (u32)fn_4_4DF8__fzgx_offset_E80, (u32)fn_4_4DF8__fzgx_offset_D4C, (u32)fn_4_4DF8__fzgx_offset_D2C, (u32)fn_4_4DF8__fzgx_offset_D2C, (u32)fn_4_4DF8__fzgx_offset_D2C, (u32)fn_4_4DF8__fzgx_offset_D2C  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_4DF8__fzgx_offset_930, (u32)fn_4_4DF8__fzgx_offset_940, (u32)fn_4_4DF8__fzgx_offset_954, (u32)fn_4_4DF8__fzgx_offset_968, (u32)fn_4_4DF8__fzgx_offset_97C, (u32)fn_4_4DF8__fzgx_offset_990, (u32)fn_4_4DF8__fzgx_offset_9A4, (u32)fn_4_4DF8__fzgx_offset_9B8  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_4DF8__fzgx_offset_9CC, (u32)fn_4_4DF8__fzgx_offset_3E4, (u32)fn_4_4DF8__fzgx_offset_3F4, (u32)fn_4_4DF8__fzgx_offset_408, (u32)fn_4_4DF8__fzgx_offset_41C, (u32)fn_4_4DF8__fzgx_offset_430, (u32)fn_4_4DF8__fzgx_offset_444, (u32)fn_4_4DF8__fzgx_offset_458  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_4DF8__fzgx_offset_46C, (u32)fn_4_4DF8__fzgx_offset_480, (u32)fn_4_63D4__fzgx_offset_94, (u32)fn_4_63D4__fzgx_offset_F8, (u32)fn_4_63D4__fzgx_offset_150, (u32)fn_4_63D4__fzgx_offset_170, (u32)fn_4_63D4__fzgx_offset_170, (u32)fn_4_63D4__fzgx_offset_190  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_63D4__fzgx_offset_1C0, (u32)fn_4_63D4__fzgx_offset_1F0, 0x6F707469, 0x6F6E5F70, 0x63757374, 0x5F646973, 0x70000000, (u32)fn_4_6720__fzgx_offset_C94  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_6720__fzgx_offset_CA4, (u32)fn_4_6720__fzgx_offset_CB8, (u32)fn_4_6720__fzgx_offset_CCC, (u32)fn_4_6720__fzgx_offset_CE0, (u32)fn_4_6720__fzgx_offset_CF4, (u32)fn_4_6720__fzgx_offset_D08, (u32)fn_4_6720__fzgx_offset_D1C, (u32)fn_4_6720__fzgx_offset_D30  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_6720__fzgx_offset_B48, (u32)fn_4_6720__fzgx_offset_B58, (u32)fn_4_6720__fzgx_offset_B6C, (u32)fn_4_6720__fzgx_offset_B80, (u32)fn_4_6720__fzgx_offset_B94, (u32)fn_4_6720__fzgx_offset_BA8, (u32)fn_4_6720__fzgx_offset_BBC, (u32)fn_4_6720__fzgx_offset_BD0  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_6720__fzgx_offset_BE4, (u32)fn_4_6720__fzgx_offset_93C, (u32)fn_4_6720__fzgx_offset_94C, (u32)fn_4_6720__fzgx_offset_960, (u32)fn_4_6720__fzgx_offset_974, (u32)fn_4_6720__fzgx_offset_988, (u32)fn_4_6720__fzgx_offset_99C, (u32)fn_4_6720__fzgx_offset_9B0  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_6720__fzgx_offset_9C4, (u32)fn_4_6720__fzgx_offset_9D8, (u32)fn_4_6720__fzgx_offset_710, (u32)fn_4_6720__fzgx_offset_720, (u32)fn_4_6720__fzgx_offset_734, (u32)fn_4_6720__fzgx_offset_748, (u32)fn_4_6720__fzgx_offset_75C, (u32)fn_4_6720__fzgx_offset_770  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_6720__fzgx_offset_784, (u32)fn_4_6720__fzgx_offset_798, (u32)fn_4_6720__fzgx_offset_7AC, (u32)fn_4_6720__fzgx_offset_5E4, (u32)fn_4_6720__fzgx_offset_5F4, (u32)fn_4_6720__fzgx_offset_608, (u32)fn_4_6720__fzgx_offset_61C, (u32)fn_4_6720__fzgx_offset_630  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_6720__fzgx_offset_644, (u32)fn_4_6720__fzgx_offset_658, (u32)fn_4_6720__fzgx_offset_66C, (u32)fn_4_6720__fzgx_offset_680, (u32)fn_4_6720__fzgx_offset_404, (u32)fn_4_6720__fzgx_offset_414, (u32)fn_4_6720__fzgx_offset_428, (u32)fn_4_6720__fzgx_offset_43C  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_6720__fzgx_offset_450, (u32)fn_4_6720__fzgx_offset_464, (u32)fn_4_6720__fzgx_offset_478, (u32)fn_4_6720__fzgx_offset_48C, (u32)fn_4_6720__fzgx_offset_4A0, (u32)fn_4_6720__fzgx_offset_98, (u32)fn_4_6720__fzgx_offset_148, (u32)fn_4_6720__fzgx_offset_298  /* fzgx-allow: A1 retail data bytes */,
    (u32)fn_4_6720__fzgx_offset_540, (u32)fn_4_6720__fzgx_offset_D6C, (u32)fn_4_6720__fzgx_offset_E8C, (u32)fn_4_6720__fzgx_offset_1038, (u32)fn_4_6720__fzgx_offset_1114, 0x43616C69, 0x62726174, 0x696F6E00  /* fzgx-allow: A1 retail data bytes */,
    0x834C8383, 0x838A8375, 0x838C815B, 0x83568387, 0x83930000, 0x43757374, 0x6F6D697A, 0x65000000  /* fzgx-allow: A1 retail data bytes */,
    0x834A8358, 0x835E837D, 0x83438359, 0x0, 0x436F6E74, 0x726F6C6C, 0x65722052, 0x756D626C  /* fzgx-allow: A1 retail data bytes */,
    0x65000000, 0x83528393, 0x8367838D, 0x815B8389, 0x905593AE, 0x0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[21]; OptionRow v[3]; } fzgx_pool_init_lbl_4_data_2C58 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x500000, (u32)lbl_4_data_2BF4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2C00__fzgx_offset_0, 0x520000,
    (u32)lbl_4_data_2C14__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2C20__fzgx_offset_0, 0x510000, (u32)lbl_4_data_2C30__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2C44__fzgx_offset_0
}};

/* Screen y of a menu row (rows are 24 pixels apart, centred on 240). */
static inline u32 row_y(u32 row) {
    return (row - 2) * 24 + 240;
}

extern s32 lbl_801A66B4;
struct fn_4_A0C_bss_970 {
    u32 unk_0;
    u8 unk_4;
};
extern struct fn_4_A0C_bss_970 lbl_1_bss_970;
extern s16 lbl_1_bss_962;
extern FontDrawPacket lbl_1_rodata_26F8;

extern void fn_1_49410(void);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_53E40(f32, f32, f32, f32, f32, s32, void *);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern f32 fn_1_4B040(char *);
extern f32 lbl_8006D188(s16);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern void fn_1_1380F0(void *);
extern void fn_1_13ABA8(u32);
extern void fn_1_5233C(void);

/* Draws the option rows from `i` on and returns the widest text. */
typedef struct RowCounter { u32 value; } RowCounter;
static inline f32 draw_rows(u32 i, RowCounter *row, OptionRow **entry) {
    f32 width;
    f32 w;

    width = 0.0f;
    *entry = fzgx_pool_init_lbl_4_data_144C.v;
    for (row->value = i * 2; i < 3; i++, row->value += 2, (*entry)++) {
        fn_1_496FC(320.0f, (f32)row_y(row->value));
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(0.5f);
        }
        fn_1_4AE0C(fzgx_pool_init_lbl_4_data_1210.v, (*entry)->text[lbl_801A66B4]);
        w = fn_1_4B040((*entry)->text[lbl_801A66B4]);
        if (w > width) {
            width = w;
        }
    }
    return width;
}

static inline f64 fn_4_A0C_operand(f32 right, f64 left) { left += right; return left; }
static inline f64 fn_4_A0C_operand_(f64 right, f64 left) { return left + right; }
void fn_4_A0C(void) {
    u32 i;
    RowCounter row;
    struct { u32 value; } cursor;
    OptionRow *entry;
    f32 width;
    f32 w;
    FontDrawPacket packet;
    f32 height;
    f64 base;
    f64 margin;

    fn_1_49410();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    fn_1_53E40(320.0f, 110.0f, 0.05f, 48.0f, 1.0f, 0, fzgx_pool_init_lbl_4_data_5F8.v[lbl_801A66B4]);

    cursor.value = lbl_1_bss_970.unk_4;
    fn_1_49410();
    fn_1_495C8(9);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);

    width = draw_rows(0, &row, &entry);

    if (lbl_4_data_11AC__fzgx_offset_60 != cursor.value || lbl_4_data_11AC__fzgx_offset_62 != lbl_1_bss_962) {
        lbl_4_bss_2 = 0;
        lbl_4_data_11AC__fzgx_offset_60 = cursor.value;
        lbl_4_data_11AC__fzgx_offset_62 = lbl_1_bss_962;
    }

    packet = lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = 320.0f;
    packet.y = (f32)((cursor.value * 2 - 2) * 24 + 240);
    packet.z = 0.15f;
    packet.scale_x = (fn_4_A0C_operand_((78.0), (width))) / 8.0;
    packet.scale_y = 3.5f;
    packet.flags = 10;
    packet.alpha = 0.3 * (1.0 + lbl_8006D188((s16)((lbl_4_bss_2 << 10) + 0x4000)));
    *(Color4 *)packet.color = *(const Color4 *)fzgx_pool_init_fzgx_pool_table2.v;
    fn_1_4F734(&packet);

    height = *(const f32 *)fzgx_pool_120;
    base = 48.0;
    margin = 96.0;
    fn_1_53BD8(0, 320.0f, 240.0f, margin + width, base + height, 0.25f);
    fn_1_1380F0(fzgx_pool_init_lbl_4_data_E8.v[lbl_801A66B4]);
    fn_1_13ABA8(0x28000000);
}
/* fzgx:end fn_4_A0C */

/* fzgx:begin fn_4_D10 noprologue */
#include "types.h"

extern struct fn_4_D10_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 lbl_4_data_14A0;
extern void fn_4_A0C(void);

struct fn_4_D10_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
};

void fn_4_D10(void) {
    struct fn_4_D10_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t1;
    p_lbl_4_bss_0 = (struct fn_4_D10_lbl_4_bss_0 *)&lbl_4_bss_0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_14A0, (u32)fn_4_A0C, 0, 5);
    p_lbl_4_bss_0->unk_0 = t1;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_D10 */

/* fzgx:begin fn_4_D7C */
#include "types.h"
#include "rel/option/globals.h"

extern int fn_1_4C10(void);
extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_4_0(u32, u32, u32, u32, u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u16 lbl_1_bss_96A;

struct fn_4_D7C_lbl_1_bss_970 {
    s32 unk_0;
    u8 unk_4;
};



struct fn_4_D7C_lbl_1_bss_6EAB4 {
    u32 unk_0;
};
extern struct fn_4_D7C_lbl_1_bss_6EAB4 lbl_1_bss_6EAB4;

struct fn_4_D7C_lbl_1_bss_9F8 {
    u8 pad_0[0x8];
    u16 unk_8;
};



struct fn_4_D7C_lbl_4_data_144C {
    s16 unk_0;
    u8 pad_2[0x1A];
};
extern struct fn_4_D7C_lbl_4_data_144C lbl_4_data_144C[];

void fn_4_D7C(void) {
    struct fn_4_D7C_lbl_1_bss_970 *p;
    u32 v;
    struct fn_4_D7C_lbl_1_bss_6EAB4 *q;

    p = (struct fn_4_D7C_lbl_1_bss_970 *)&(*(struct fn_4_D7C_lbl_1_bss_970 *)&lbl_1_bss_970);
    if (p->unk_0 <= 0) {
        if (lbl_4_bss_10.unk_0 != 0) {
            if (fn_1_4C10() == 0) {
                fn_1_1280(1);
                lbl_1_bss_96A = lbl_4_bss_10.unk_0;
                lbl_4_bss_10.unk_0 = 0;
            }
        } else {
            p->unk_4 = fn_4_0(p->unk_4, 0, 2, -1, 0);
            if (((*(struct fn_4_D7C_lbl_1_bss_9F8 *)&lbl_1_bss_9F8).unk_8 >> 9) & 1) {
                fn_1_A2D84(0xA9010200);
                q = (struct fn_4_D7C_lbl_1_bss_6EAB4 *)&lbl_1_bss_6EAB4;
                v = q->unk_0;
                q->unk_0 = v | 0x2C;
                (*(struct fn_4_D7C_lbl_1_bss_970 *)&lbl_1_bss_970).unk_0 = 1;
            } else if (((*(struct fn_4_D7C_lbl_1_bss_9F8 *)&lbl_1_bss_9F8).unk_8 >> 8) & 1) {
                fn_1_A2D84(0xA9010100);
                lbl_4_bss_10.unk_0 = lbl_4_data_144C[p->unk_4].unk_0;
                fn_1_4A00(0, 15, lbl_4_bss_8);
            }
        }
    }
}
/* fzgx:end fn_4_D7C */

/* fzgx:begin fn_4_EA0 */
// Clear the pending option selection after applying its associated value.
void fn_4_EA0(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_EA0 */

/* fzgx:begin fn_4_1444 */
#include "dolphin/hw_regs.h"

extern struct fn_4_347C_lbl_1_bss_9C8 lbl_1_bss_9C8;
extern u32 lbl_1_data_2AC0;
extern u32 lbl_1_data_2B40;
extern u32 lbl_1_data_2B50;
extern u32 lbl_1_data_2B58;
extern u32 lbl_4_data_14D0;
extern void fn_4_3128(void);
extern u32 fn_80008BA8(u32, u32, u32);
extern u32 fn_1_F7308(void);
extern u32 lbl_1_bss_AA0;
extern u32 lbl_1_data_2B60;
extern u32 lbl_4_data_2AE8;
extern u32 memcpy(u32, u32, u32);
extern void fn_4_63D4(void);
extern int fn_1_4C10(void);
extern u16 lbl_1_bss_96A;
extern u32 fn_4_0(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_9F8;
extern u8 lbl_4_data_2C58[84];
extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_4_ABB0(void);
extern u32 fn_1_1380F0(u32);
extern u32 fn_1_13ABA8(u32);
extern u32 lbl_4_data_1A4;
extern s32 lbl_801A66B4;
extern u8 lbl_4_bss_5618;
extern u32 fn_1_B7E98(u32);
extern u32 fn_1_B800C(u32);
extern u32 fn_1_B80F0(u32);
extern u32 fn_1_B8170(u32);
extern u32 lbl_4_data_2DB4;
extern void fn_4_9AD0(void);
extern u8 *fn_4_A82C(u8 *);
extern void fn_80083DB0(u8 *, u32);
extern u32 fn_1_B9C0C(void);
extern s8 fn_1_BA144(u32 *);
extern u32 lbl_4_bss_5678;
extern u32 fn_1_B7C00(void);
extern u32 fn_1_BC310(void *);
extern u32 fn_1_C0510(u32);
extern u32 fn_1_C1394(void *);
extern s16 lbl_1_bss_962;
extern struct fn_4_9B0_lbl_4_data_1260 lbl_4_data_1260;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_426C(u32);
extern void fn_4_AB90(void);
extern struct _prolog_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern struct fn_4_869C_lbl_1_bss_718E0 lbl_1_bss_718E0;
extern s32 lbl_1_bss_970;
extern u8 lbl_4_bss_2;
extern u16 lbl_1_bss_968;


typedef struct {
    u8 r, g, b, a;
} fn_4_1444_Color;

extern void fn_1_49410(void);
extern void fn_1_495C8(u8);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern f32 fn_1_4B068(const char *);
extern f32 fn_1_4B090(const char *);
extern void fn_800371F8(s32, fn_4_1444_Color);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800746A8(u8, s32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_5233C();
extern s32 lbl_801A66B4;

/* Shared literal pool primer: reproduces the TU's retail .rodata layout.
   MWCC emits a function's aggregate initializers, then its literals, then its
   int-to-float constants, so the primer is split at those points. The outputs
   are volatile so that every literal is materialized. */ /* fzgx-allow: S2 pool primer note */
typedef struct {
    u8 b[44];
} fzgx_pool_bytes44;

#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer0(volatile f32 *f) {  /* fzgx-allow: S2 pool primer sink */
    *f = 167.0f;
    *f = 38.0f;
    *f = 0.5f;
}

__declspec(section ".fzgxpool") void fzgx_pool_primer1(volatile f64 *d, fn_4_1444_Color *c) {  /* fzgx-allow: S2 pool primer sink */
    fn_4_1444_Color c0 = {0x00, 0xD0, 0xD0, 0x00};
    *c = c0;
    *d = 78.0;
    *d = 0.125;
    *d = 28.0;
    *d = 0.3;
    *d = 1.0;
}

__declspec(section ".fzgxpool") void fzgx_pool_primer2(volatile f32 *f, fn_4_1444_Color *c) {  /* fzgx-allow: S2 pool primer sink */
    fn_4_1444_Color c1 = {0x00, 0xD0, 0xD0, 0x00};
    *c = c1;
    *f = 0.6f;
}

__declspec(section ".fzgxpool") void fzgx_pool_primer3(volatile f32 *f, volatile f64 *d, fn_4_1444_Color *c, u32 u) {  /* fzgx-allow: S2 pool primer sink */
    fn_4_1444_Color c2 = {0xFF, 0x00, 0x00, 0x00};
    *c = c2;
    *f = 3.5f;
    *f = 5.0f;
    *f = 0.0f;
    *f = 320.0f;
    *f = 0.15f;
    *f = 240.0f;
    *d = 96.0;
    *d = 48.0;
    *f = 0.25f;
    *f = (f32)u;
}

__declspec(section ".fzgxpool") void fzgx_pool_primer4(volatile f32 *f, volatile f64 *d) {  /* fzgx-allow: S2 pool primer sink */
    *f = 0.005f;
    *f = 216.0f;
    *d = 90.0;
    *d = 320.0;
    *d = 0.5;
    *f = 264.0f;
    *d = -0.5;
    *f = 0.015f;
    *f = 72.0f;
    *f = 0.025f;
    *f = 0.05f;
    *f = 48.0f;
    *f = 0.8f;
    *f = 110.0f;
    *f = 1.0f;
    *f = 120.0f;
}

__declspec(section ".fzgxpool") void fzgx_pool_primer5(volatile f32 *f, fzgx_pool_bytes44 *t, s32 s) {  /* fzgx-allow: S2 pool primer sink */
    fzgx_pool_bytes44 t0 = {{
        0x08, 0x08, 0x00, 0x00, 0x78, 0x78, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00,
        0x25, 0x00, 0x00, 0x00, 0x1A, 0x1A, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00,
        0xE6, 0x1A, 0x00, 0x00, 0xDB, 0x00, 0x00, 0x00, 0xE6, 0xE6, 0x00, 0x00,
        0x00, 0xDB, 0x00, 0x00, 0x1A, 0xE6, 0x00, 0x00,
    }};
    *t = t0;
    *f = (f32)s;
}

__declspec(section ".fzgxpool") void fzgx_pool_primer6(volatile f32 *f) {  /* fzgx-allow: S2 pool primer sink */
    *f = 1.3333334f;
    *f = 160.0f;
    *f = 210.0f;
    *f = 480.0f;
    *f = -0.01f;
    *f = 1.1f;
    *f = 1.4f;
    *f = 20.0f;
    *f = 10.0f;
    *f = 0.01f;
    *f = 140.0f;
    *f = 0.001f;
}

/* GX write-gather FIFO: every store is a hardware write */
#define GX_FIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)
#define POS3(px, py, pz) \
    GX_FIFO_F32 = (px);  \
    GX_FIFO_F32 = (py);  \
    GX_FIFO_F32 = (pz)

// Draw a framed text box (filled quad plus outline) with an inner frame.
void fn_4_1444(u16 depth, s32 left, fn_4_1444_Color border, fn_4_1444_Color fill, const char *text) {
    f32 x;
    f32 y;
    f32 z;
    f32 zz;
    f32 x1;
    f32 halfW;
    f32 x0;
    f32 height;
    f32 frameW;
    f32 frameH;

    if (left) {
        x = 160.0f;
        y = 210.0f;
    } else {
        x = 480.0f;
        y = 210.0f;
    }
    z = -0.01f * (f32)depth;

    fn_1_49410();
    fn_1_495C8(1);
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4955C(0.8f, 0.8f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    halfW = 0.5f * (20.0f + fn_1_4B068(text));
    height = 10.0f + fn_1_4B090(text);
    frameW = 140.0f;
    frameH = 110.0f;

    fn_800371F8(1, fill);
    fn_8003462C(0x80, 7, 4);
    x0 = x - halfW;
    /* height becomes the top edge, halfW the right edge */
    height = (y - frameH) - height;
    zz = 0.01f + z;
    x1 = x + halfW;
    POS3(x0, height, zz);
    POS3(x1, height, zz);
    POS3(x1, y - frameH, zz);
    POS3(x0, y - frameH, zz);
    fn_800746A8(10, 0);

    fn_800371F8(1, border);
    fn_8003462C(0xA8, 7, 2);
    POS3(x0, height, zz);
    POS3(x1, height, zz);
    fn_8003462C(0xA8, 7, 2);
    POS3(x1, height, zz);
    POS3(x1, y - frameH, zz);
    fn_8003462C(0xA8, 7, 2);
    POS3(x1, y - frameH, zz);
    POS3(x0, y - frameH, zz);
    fn_8003462C(0xA8, 7, 2);
    POS3(x0, y - frameH, zz);
    POS3(x0, height, zz);
    fn_1_496FC(x, 5.0f + height);
    fn_1_4A0D8(text);

    fn_800371F8(1, fill);
    fn_8003462C(0x80, 7, 4);
    POS3(x - frameW, y - frameH, z - 0.001f);
    POS3(x + frameW, y - frameH, z - 0.001f);
    POS3(x + frameW, y + frameH, z - 0.001f);
    POS3(x - frameW, y + frameH, z - 0.001f);

    fn_800371F8(1, border);
    fn_8003462C(0xA8, 7, 2);
    POS3(x - frameW, y - frameH, z);
    POS3(x + frameW, y - frameH, z);
    fn_8003462C(0xA8, 7, 2);
    POS3(x + frameW, y - frameH, z);
    POS3(x + frameW, y + frameH, z);
    fn_8003462C(0xA8, 7, 2);
    POS3(x + frameW, y + frameH, z);
    POS3(x - frameW, y + frameH, z);
    fn_8003462C(0xA8, 7, 2);
    POS3(x - frameW, y + frameH, z);
    POS3(x - frameW, y - frameH, z);
}
/* fzgx:end fn_4_1444 */

/* fzgx:begin fn_4_2394 noprologue */
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"

/* begin dolphin/gx.h (deltawave784/fzgx, CC0) */
#ifndef DOLPHIN_GX_H
#define DOLPHIN_GX_H


/* The GX write-gather pipe: one memory-mapped port at GX_FIFO_BASE (dolphin/hw_regs.h), written through
   the member whose width the command needs. Declared as an MWCC absolute object: every store is
   emitted in order, addressed by literal (`lis rX, 0xCC01; stb rY, -0x8000(rX)`) with no
   relocation, and the named object cannot alias the `gx` context, which keeps retail's schedule.
   Proven by GXSetViewportJitter (fn_80038DE8) and GXSetFog (fn_800377F8). */
typedef union PPCWGPipe {
    u8 u8;
    u16 u16;
    u32 u32;
    s8 s8;
    s16 s16;
    s32 s32;
    f32 f32;
    f64 f64;
} PPCWGPipe;
typedef PPCWGPipe WGPipe;

volatile PPCWGPipe GXWGFifo : GX_FIFO_BASE; /* volatile: hardware port */

#define GX_WRITE_U8(v) (GXWGFifo.u8 = (u8)(v))
#define GX_WRITE_U16(v) (GXWGFifo.u16 = (u16)(v))
#define GX_WRITE_U32(v) (GXWGFifo.u32 = (u32)(v))
#define GX_WRITE_F32(v) (GXWGFifo.f32 = (f32)(v))

/* BP (raster) register write: command byte 0x61 followed by the register word. */
#define GX_WRITE_RAS_REG(value)  \
    do {                         \
        GXWGFifo.u8 = 0x61;      \
        GXWGFifo.u32 = (value);  \
    } while (0)

/* XF register write: command byte 0x10, then (count - 1) << 16 | address, then the data words. */
#define GX_WRITE_XF_REG_HDR(addr, count) \
    do {                                  \
        GXWGFifo.u8 = 0x10;               \
        GXWGFifo.u32 = (((count) - 1) << 16) | (addr); \
    } while (0)

#endif

/* end dolphin/gx.h */

typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;

 /* fzgx-allow: S2 SDK asynchronous state */
/* FZGX_ADDR_* come from config/GFZE01/ldscript.tpl (generated by configure.py), shared with the link. */
/* Generated from ldscript.tpl by configure.py. */
/* Gekko locked-cache effective-address window. */
/* GX write-gather FIFO address. */
/* OS low-memory globals as MWCC absolute objects (`T name : address;`): a read compiles to
   `lis rX, 0x8000; lwz rY, off(rX)` with no symbol or relocation, and the object is named, so it
   only aliases itself. MWCC accepts an identical redeclaration, so sources that still declare one
   locally keep compiling. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
volatile float s; volatile double d; /* fzgx-allow: S2 pool primer sinks */
s = 167.0f;
s = 38.0f;
s = 0.5f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00D0D000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
volatile float s; volatile double d; /* fzgx-allow: S2 pool primer sinks */
d = 78.0;
d = 0.125;
s = 2.9375f;
s = 0.0f;
d = 0.3;
d = 1.0;
}
static const unsigned long fzgx_pool_table4[1] = {0x00D0D000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
volatile float s; volatile double d; /* fzgx-allow: S2 pool primer sinks */
s = 0.6000000238418579f;
}
static const unsigned long fzgx_pool_table6[1] = {0xFF000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
volatile float s; volatile double d; /* fzgx-allow: S2 pool primer sinks */
s = 3.5f;
s = 5.0f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
volatile float s; volatile double d; /* fzgx-allow: S2 pool primer sinks */
s = 320.0f;
s = 0.15000000596046448f;
s = 240.0f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
volatile float s; volatile double d; /* fzgx-allow: S2 pool primer sinks */
d = 96.0;
d = 48.0;
s = 0.25f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
volatile float s; volatile double d; /* fzgx-allow: S2 pool primer sinks */
d = 4503599627370496.0;
s = 0.004999999888241291f;
s = 216.0f;
d = 90.0;
d = 320.0;
d = 0.5;
s = 264.0f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
volatile float s; volatile double d; /* fzgx-allow: S2 pool primer sinks */
d = -0.5;
s = 0.014999999664723873f;
s = 72.0f;
s = 0.02500000037252903f;
s = 0.05000000074505806f;
s = 48.0f;
s = 0.800000011920929f;
s = 110.0f;
s = 1.0f;
s = 120.0f;
}
static const unsigned long fzgx_pool_table16[11] = {0x08080000, 0x78780000, 0x06060000, 0x25000000, 0x1A1A0000, 0x00250000, 0xE61A0000, 0xDB000000, 0xE6E60000, 0x00DB0000, 0x1AE60000}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
volatile float s; volatile double d; /* fzgx-allow: S2 pool primer sinks */
d = 4503601774854144.0;
s = 1.3333333730697632f;
s = 160.0f;
s = 210.0f;
s = 480.0f;
s = -0.009999999776482582f;
s = 1.100000023841858f;
s = 1.399999976158142f;
s = 20.0f;
s = 10.0f;
s = 0.009999999776482582f;
s = 140.0f;
s = 0.0010000000474974513f;
s = 0.5625f;
s = 0.75f;
s = 24.0f;
s = 105.0f;
s = 345.0f;
}
static const unsigned long fzgx_pool_table18[6] = {0x00FF00FF, 0xFF000080, 0x0000FF80, 0x687EA0FF, 0x202020A0, 0xFFFFFF80}; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; } /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
volatile float s; volatile double d; /* fzgx-allow: S2 pool primer sinks */
s = -125.0f;
s = 125.0f;
s = -0.03999999910593033f;
s = 100.0f;
s = -0.04999999701976776f;
s = 0.029999999329447746f;
s = 90.0f;
s = 135.0f;
s = 300.0f;
s = 50.0f;
s = 192.0f;
s = 380.0f;
}
#pragma section code_type ".text"
typedef struct {
u8 r, g, b, a;
} GXColor;
/* GX write-gather pipe: every store is a FIFO push, so it must stay volatile. */
extern s32 lbl_801A66B4;
extern void fn_1_5233C(void);
extern void fn_1_49410(void);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4955C(f32, f32);
extern int sprintf(char *, const char *, ...);
extern f32 fn_1_4B090(const char *);
extern void fn_800371F8(s32, GXColor);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800746A8(u8, s32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);
static inline void fn_4_2394_shadow(void) {
if (lbl_801A66B4 != 5) {
fn_1_495B0(0x80000000);
fn_1_49590(0.5f);
}
}
/* Draws a labelled box with an outline, placed left or right of the centre line. */
extern u8 fn_4_347C__fzgx_offset_0[];
extern u8 fn_4_3568__fzgx_offset_0[];
extern u8 fn_4_406C__fzgx_offset_0[];
extern u8 fn_4_4784__fzgx_offset_0[];
extern u8 fn_4_4834__fzgx_offset_0[];
extern u8 fn_4_4B10__fzgx_offset_0[];
extern u8 fn_4_6678__fzgx_offset_0[];
extern u8 fn_4_6720__fzgx_offset_0[];
extern u8 fn_4_78E0__fzgx_offset_0[];
extern u8 fn_4_7C38__fzgx_offset_0[];
extern u8 fn_4_7CA4__fzgx_offset_0[];
extern u8 fn_4_7D94__fzgx_offset_0[];
extern u8 fn_4_80EC__fzgx_offset_0[];
extern u8 fn_4_8158__fzgx_offset_0[];
extern u8 fn_4_8248__fzgx_offset_0[];
extern u8 fn_4_869C__fzgx_offset_0[];
extern u8 fn_4_8720__fzgx_offset_0[];
extern u8 fn_4_898C__fzgx_offset_0[];
extern u8 fn_4_89E4__fzgx_offset_0[];
extern u8 fn_4_8A54__fzgx_offset_0[];
extern u8 fn_4_8AE0__fzgx_offset_0[];
extern u8 fn_4_8DC0__fzgx_offset_0[];
extern u8 fn_4_8E38__fzgx_offset_0[];
extern u8 fn_4_9A78__fzgx_offset_0[];
extern u8 fn_4_9B20__fzgx_offset_0[];
extern u8 fn_4_9C14__fzgx_offset_0[];
extern u8 fn_4_A734__fzgx_offset_0[];
extern u8 fn_4_D10__fzgx_offset_0[];
extern u8 fn_4_D7C__fzgx_offset_0[];
extern u8 fn_4_EA0__fzgx_offset_0[];
extern u8 lbl_4_data_0__fzgx_offset_0[];
extern u8 lbl_4_data_100__fzgx_offset_0[];
extern u8 lbl_4_data_107C__fzgx_offset_0[];
extern u8 lbl_4_data_10A0__fzgx_offset_0[];
extern u8 lbl_4_data_10E8__fzgx_offset_0[];
extern u8 lbl_4_data_10__fzgx_offset_0[];
extern u8 lbl_4_data_111C__fzgx_offset_0[];
extern u8 lbl_4_data_116C__fzgx_offset_0[];
extern u8 lbl_4_data_11AC__fzgx_offset_0[];
extern u8 lbl_4_data_130__fzgx_offset_0[];
extern u8 lbl_4_data_1418__fzgx_offset_0[];
extern u8 lbl_4_data_1424__fzgx_offset_0[];
extern u8 lbl_4_data_1434__fzgx_offset_0[];
extern u8 lbl_4_data_1440__fzgx_offset_0[];
extern u8 lbl_4_data_170__fzgx_offset_0[];
extern u8 lbl_4_data_188__fzgx_offset_0[];
extern u8 lbl_4_data_1BC__fzgx_offset_0[];
extern u8 lbl_4_data_210__fzgx_offset_0[];
extern u8 lbl_4_data_254__fzgx_offset_0[];
extern u8 lbl_4_data_284__fzgx_offset_0[];
extern u8 lbl_4_data_2CC__fzgx_offset_0[];
extern u8 lbl_4_data_2F0__fzgx_offset_0[];
extern u8 lbl_4_data_32C__fzgx_offset_0[];
extern u8 lbl_4_data_34C__fzgx_offset_0[];
extern u8 lbl_4_data_37C__fzgx_offset_0[];
extern u8 lbl_4_data_38__fzgx_offset_0[];
extern u8 lbl_4_data_3B8__fzgx_offset_0[];
extern u8 lbl_4_data_400__fzgx_offset_0[];
extern u8 lbl_4_data_438__fzgx_offset_0[];
extern u8 lbl_4_data_480__fzgx_offset_0[];
extern u8 lbl_4_data_4C__fzgx_offset_0[];
extern u8 lbl_4_data_4F0__fzgx_offset_0[];
extern u8 lbl_4_data_578__fzgx_offset_0[];
extern u8 lbl_4_data_57C__fzgx_offset_0[];
extern u8 lbl_4_data_59C__fzgx_offset_0[];
extern u8 lbl_4_data_5A0__fzgx_offset_0[];
extern u8 lbl_4_data_5C0__fzgx_offset_0[];
extern u8 lbl_4_data_5D8__fzgx_offset_0[];
extern u8 lbl_4_data_610__fzgx_offset_0[];
extern u8 lbl_4_data_660__fzgx_offset_0[];
extern u8 lbl_4_data_6D4__fzgx_offset_0[];
extern u8 lbl_4_data_724__fzgx_offset_0[];
extern u8 lbl_4_data_78__fzgx_offset_0[];
extern u8 lbl_4_data_790__fzgx_offset_0[];
extern u8 lbl_4_data_7C__fzgx_offset_0[];
extern u8 lbl_4_data_7DC__fzgx_offset_0[];
extern u8 lbl_4_data_85C__fzgx_offset_0[];
extern u8 lbl_4_data_86C__fzgx_offset_0[];
extern u8 lbl_4_data_89C__fzgx_offset_0[];
extern u8 lbl_4_data_8A8__fzgx_offset_0[];
extern u8 lbl_4_data_8D8__fzgx_offset_0[];
extern u8 lbl_4_data_8F8__fzgx_offset_0[];
extern u8 lbl_4_data_918__fzgx_offset_0[];
extern u8 lbl_4_data_934__fzgx_offset_0[];
extern u8 lbl_4_data_970__fzgx_offset_0[];
extern u8 lbl_4_data_984__fzgx_offset_0[];
extern u8 lbl_4_data_9C0__fzgx_offset_0[];
extern u8 lbl_4_data_9D8__fzgx_offset_0[];
extern u8 lbl_4_data_A10__fzgx_offset_0[];
extern u8 lbl_4_data_A30__fzgx_offset_0[];
extern u8 lbl_4_data_A70__fzgx_offset_0[];
extern u8 lbl_4_data_A78__fzgx_offset_0[];
extern u8 lbl_4_data_AA0__fzgx_offset_0[];
extern u8 lbl_4_data_AAC__fzgx_offset_0[];
extern u8 lbl_4_data_AD4__fzgx_offset_0[];
extern u8 lbl_4_data_B0__fzgx_offset_0[];
extern u8 lbl_4_data_B90__fzgx_offset_0[];
extern u8 lbl_4_data_C18__fzgx_offset_0[];
extern u8 lbl_4_data_C8__fzgx_offset_0[];
extern u8 lbl_4_data_CB0__fzgx_offset_0[];
extern u8 lbl_4_data_C__fzgx_offset_0[];
extern u8 lbl_4_data_D50__fzgx_offset_0[];
extern u8 lbl_4_data_D64__fzgx_offset_0[];
extern u8 lbl_4_data_D84__fzgx_offset_0[];
extern u8 lbl_4_data_D98__fzgx_offset_0[];
extern u8 lbl_4_data_DB8__fzgx_offset_0[];
extern u8 lbl_4_data_DF0__fzgx_offset_0[];
extern u8 lbl_4_data_E48__fzgx_offset_0[];
extern u8 lbl_4_data_E58__fzgx_offset_0[];
extern u8 lbl_4_data_E88__fzgx_offset_0[];
extern u8 lbl_4_data_E98__fzgx_offset_0[];
extern u8 lbl_4_data_EC8__fzgx_offset_0[];
extern u8 lbl_4_data_F08__fzgx_offset_0[];
extern u8 lbl_4_data_F64__fzgx_offset_0[];
extern u8 lbl_4_data_FD8__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_4_data_0[1156] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x436F6E74, 0x726F6C6C, 0x65720000, 0x0, 0x83528393, 0x8367838D, 0x815B8389, 0x0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, 0x436F6E74, 0x726F6C6C,
    0x65722053, 0x6F636B65, 0x74000000, 0x83528393, 0x8367838D, 0x815B8389, 0x837C815B, 0x83670000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_38__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_4C__fzgx_offset_0, 0x4F4E0000, 0x4F464600,
    (u32)lbl_4_data_78__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_78__fzgx_offset_0, (u32)lbl_4_data_7C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_7C__fzgx_offset_0, 0x0, 0x55736520, 0x83AD206F, 0x722083B5, 0x20746F20,
    0x63686F6F, 0x73652E00, 0x83AD82A9, 0x83B582C5, 0x8D8096DA, 0x82F09149, 0x82F182C5, 0x82AD82BE,
    0x82B382A2, 0x81420000, (u32)lbl_4_data_B0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C8__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x4D6F7665, 0x2083AD20, 0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063,
    0x68616E67, 0x6520636F, 0x6E74726F, 0x6C732E00, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C59180,
    0x8DEC82F0, 0x95CF8D58, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_100__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_130__fzgx_offset_0, 0x506C6561, 0x73652077, 0x61697420, 0x61206D6F,
    0x6D656E74, 0x2E2E2E00, 0x82B582CE, 0x82E782AD, 0x82A891D2, 0x82BF82AD, 0x82BE82B3, 0x82A28142,
    0x0, (u32)lbl_4_data_170__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_188__fzgx_offset_0, 0x50726573,
    0x73207468, 0x65204120, 0x42757474, 0x6F6E206F, 0x6E207468, 0x6520436F, 0x6E74726F, 0x6C6C6572,
    0x20746F20, 0x62652061, 0x646A7573, 0x7465642E, 0x20507265, 0x73732074, 0x68652042, 0x20427574,
    0x746F6E20, 0x746F2066, 0x696E6973, 0x682E0000, 0x95CF8D58, 0x82B782E9, 0x83528393, 0x8367838D,
    0x815B8389, 0x82C5839F, 0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_1BC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_210__fzgx_offset_0, 0x526F7461, 0x74652074, 0x68652043,
    0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x206F6E65, 0x2066756C, 0x6C207265, 0x766F6C75, 0x74696F6E,
    0x2E000000, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E82F0, 0x88EA9474,  /* fzgx-allow: A1 retail data bytes */
    0x82C989F1, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_254__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_284__fzgx_offset_0, 0x506C6561, 0x73652061, 0x646A7573, 0x74207468, 0x65207374,
    0x65657269, 0x6E672077, 0x6865656C, 0x2E000000, 0x836E8393, 0x8368838B, 0x82CC92B2, 0x90AE82F0,
    0x8D7382C8, 0x82C182C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_2CC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2F0__fzgx_offset_0, 0x52657475, 0x726E2074, 0x6F207468, 0x65206465, 0x6661756C,
    0x74207365, 0x7474696E, 0x67733F00, 0x8F898AFA, 0x90DD92E8, 0x82C996DF, 0x82B582DC, 0x82B782A9,
    0x81480000, (u32)lbl_4_data_32C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_34C__fzgx_offset_0, 0x53656C65,  /* fzgx-allow: A1 retail data bytes */
    0x63742074, 0x68652043, 0x6F6E7472, 0x6F6C6C65, 0x7220746F, 0x20626520, 0x6368616E, 0x67656420,
    0x7573696E, 0x67206569, 0x74686572, 0x2083AD20, 0x6F722083, 0xB52E0000, 0x83AD82A9, 0x83B582C5,
    0x95CF8D58, 0x82B782E9, 0x83528393, 0x8367838D, 0x815B8389, 0x82F09149, 0x82F182C5, 0x82AD82BE,  /* fzgx-allow: A1 retail data bytes */
    0x82B382A2, 0x81420000, (u32)lbl_4_data_37C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_3B8__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x4D6F7665, 0x2083AD20, 0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063,
    0x68616E67, 0x65205275, 0x6D626C65, 0x20736574, 0x74696E67, 0x732E0000, 0x83AD82A9, 0x83B582CC,
    0x8DB68945, 0x82C59055, 0x93AE82CC, 0x90DD92E8, 0x82F095CF, 0x8D5882B5, 0x82C482AD, 0x82BE82B3,
    0x82A28142, 0x0, (u32)lbl_4_data_400__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_438__fzgx_offset_0,
    0x54686520, 0x436F6E74, 0x726F6C6C, 0x65722068, 0x61732062, 0x65656E20, 0x64697363, 0x6F6E6E65,
    0x63746564, 0x2E0A2052, 0x65636F6E, 0x6E656374, 0x20746865, 0x20436F6E, 0x74726F6C, 0x6C657220,
    0x696E2053, 0x6F636B65, 0x74202564, 0x206F720A, 0x20707265, 0x73732074, 0x68652041, 0x20427574,
    0x746F6E20, 0x6F6E2061, 0x6E6F7468, 0x65722E00, 0x83528393, 0x8367838D, 0x815B8389, 0x82AA8A4F,  /* fzgx-allow: A1 retail data bytes */
    0x82B382EA, 0x82DC82B5, 0x82BD8142, 0xA835283, 0x93836783, 0x8D815B83, 0x89837C81, 0x5B836725,
    0x6482C982, 0xB382B582, 0xC882A882, 0xB782A981, 0x410A91BC, 0x82CC8352, 0x83938367, 0x838D815B,
    0x838982C5, 0x839F837B, 0x835E8393, 0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_480__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_4F0__fzgx_offset_0, 0x59455300, 0x82CD82A2,
    0x0, (u32)lbl_4_data_578__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_57C__fzgx_offset_0, 0x4E4F0000,
    0x82A282A2, 0x82A60000, (u32)lbl_4_data_59C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_5A0__fzgx_offset_0,
    0x4368616E, 0x6765204F, 0x7074696F, 0x6E205365, 0x7474696E, 0x67730000, 0x83498376, 0x83568387,
    0x839390DD, 0x92E882F0, 0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0, (u32)lbl_4_data_5C0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_5D8__fzgx_offset_0, 0x41646A75, 0x73742074, 0x68652043, 0x616C6962,
    0x72617469, 0x6F6E2E0A, 0x50726573, 0x73207468, 0x65204120, 0x42757474, 0x6F6E206F, 0x6E207468,
    0x6520436F, 0x6E74726F, 0x6C6C6572, 0xA796F75, 0x2077616E, 0x74206164, 0x6A757374, 0x65642E00,
    0x83528393, 0x8367838D, 0x815B8389, 0x82CC834C, 0x8383838A, 0x8375838C, 0x815B8356, 0x83878393,  /* fzgx-allow: A1 retail data bytes */
    0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420A95, 0xCF8D5882, 0xB782E983, 0x52839383, 0x67838D81,  /* fzgx-allow: A1 retail data bytes */
    0x5B838982, 0xC5839F82, 0xF0899F82, 0xB582C482, 0xAD82BE82, 0xB382A281, 0x42000000, (u32)lbl_4_data_610__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_660__fzgx_offset_0, 0x43757374, 0x6F6D697A, 0x65207468,
    0x6520436F, 0x6E74726F, 0x6C6C6572, 0x2E0A5072, 0x65737320, 0x74686520, 0x41204275, 0x74746F6E,
    0x206F6E20, 0x74686520, 0x436F6E74, 0x726F6C6C, 0x65722074, 0x6F206265, 0x2061646A, 0x75737465,
    0x642E0000, 0x83528393, 0x8367838D, 0x815B8389, 0x82CC834A, 0x8358835E, 0x837D8343, 0x835982F0,  /* fzgx-allow: A1 retail data bytes */
    0x8D7382C8, 0x82A282DC, 0x82B78142, 0xA95CF8D, 0x5882B782, 0xE9835283, 0x93836783, 0x8D815B83,
    0x8982C583, 0x9F82F089, 0x9F82B582, 0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_6D4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_724__fzgx_offset_0, 0x436F6E74, 0x726F6C6C, 0x65722052, 0x756D626C,
    0x65205365, 0x7474696E, 0x67732E0A, 0x20507265, 0x73732074, 0x68652041, 0x20427574, 0x746F6E20,
    0x746F2073, 0x656C6563, 0x74207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0x2E000000, 0x83528393,
    0x8367838D, 0x815B8389, 0x82CC9055, 0x93AE82CC, 0x90DD92E8, 0x82F08D73, 0x82C882A2, 0x82DC82B7,  /* fzgx-allow: A1 retail data bytes */
    0x81420A83, 0x52839383, 0x67838D81, 0x5B838982, 0xF0914982, 0xF182C583, 0x9F82F089, 0x9F82B582,  /* fzgx-allow: A1 retail data bytes */
    0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_790__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_7DC__fzgx_offset_0, (u32)lbl_4_data_400__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_438__fzgx_offset_0, 0x53617665,
    0x20636861, 0x6E676573, 0x3F000000, 0x95CF8D58, 0x82F095DB, 0x91B682B5, 0x82DC82B7, 0x82A98148,
    0x0, (u32)lbl_4_data_85C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_86C__fzgx_offset_0, 0x49732074,
    0x68697320, 0x4F4B3F00, 0x82B182EA, 0x82C582E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x81480000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_89C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8A8__fzgx_offset_0, 0x8163826E, 0x826D0000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_8D8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8D8__fzgx_offset_0, 0x826E8265, 0x82650000,
    (u32)lbl_4_data_8F8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8F8__fzgx_offset_0, 0x4368616E, 0x67652043,
    0x6F6E7472, 0x6F6C6C65, 0x72205365, 0x7474696E, 0x67730000, 0x83528393, 0x8367838D, 0x815B8389,  /* fzgx-allow: A1 retail data bytes */
    0x82CC90DD, 0x92E882F0, 0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0, (u32)lbl_4_data_918__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_934__fzgx_offset_0, 0x4D616E61, 0x6765204D, 0x656D6F72, 0x79204361,
    0x72640000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x8AC7979D, 0x82F08D73, 0x82C882A2,
    0x82DC82B7, 0x81420000, (u32)lbl_4_data_970__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_984__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x53656C65, 0x63742053, 0x63726565, 0x6E205365, 0x7474696E, 0x67732000, 0x89E696CA, 0x8382815B,
    0x836882CC, 0x90DD92E8, 0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420000, (u32)lbl_4_data_9C0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_9D8__fzgx_offset_0, 0x55736520, 0x83AD206F, 0x722083B5, 0x20746F20,
    0x63686F6F, 0x73652061, 0x206D6F64, 0x65200000, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C58382,
    0x815B8368, 0x82F09149, 0x82F182C5, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_A10__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_A30__fzgx_offset_0, 0x4E6F726D, 0x616C0000, 0x836D815B, 0x837D838B,
    0x8365838C, 0x83720000, (u32)lbl_4_data_A70__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_A78__fzgx_offset_0,
    0x57696465, 0x20536372, 0x65656E00, 0x838F8343, 0x83688365, 0x838C8372, 0x0, (u32)lbl_4_data_AA0__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_AAC__fzgx_offset_0, 0x4D6F7665, 0x20746865, 0x20436F6E,
    0x74726F6C, 0x20537469, 0x636B2061, 0x726F756E, 0x6420696E, 0x20612063, 0x6972636C, 0x6520756E,
    0x74696C20, 0x74686520, 0x66696775, 0x72657320, 0x6F6E2074, 0x68650A20, 0x6C656674, 0x20736964,
    0x6520646F, 0x206E6F74, 0x20636861, 0x6E67652E, 0x2041646A, 0x75737420, 0x706C6179, 0x20757369,
    0x6E672074, 0x68652083, 0xB520436F, 0x6E74726F, 0x6C205061, 0x642E0A20, 0x50726573, 0x73207468,
    0x65205820, 0x42757474, 0x6F6E2074, 0x6F207265, 0x7475726E, 0x20746F20, 0x74686520, 0x64656661,
    0x756C7420, 0x73657474, 0x696E6773, 0x2E000000, 0x8DB691A4, 0x82CC907D, 0x8C6082AA, 0x95CF89BB,
    0x82B582C8, 0x82AD82C8, 0x82E982DC, 0x82C583AD, 0x82F088EA, 0x947482C9, 0x89F182B5, 0x82C482AD,
    0x82BE82B3, 0x82A28142, 0xA83B582, 0xC5975682, 0xD182F092, 0xB290AE82, 0xB582C482, 0xAD82BE82,
    0xB382A281, 0x420A83B4, 0x82C58F89, 0x8AFA90DD, 0x92E882C9, 0x96DF82B9, 0x82DC82B7, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_AD4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_B90__fzgx_offset_0, 0x5475726E, 0x20746865,
    0x20737465, 0x6572696E, 0x67207768, 0x65656C20, 0x4C656674, 0x20616E64, 0x20526967, 0x68742061,
    0x6E642070, 0x72657373, 0xA746865, 0x20412042, 0x7574746F, 0x6E206174, 0x20746865, 0x20706F69,
    0x6E742079, 0x6F752077, 0x616E7420, 0x746F2073, 0x65742061, 0x73207468, 0x650A206C, 0x696D6974,
    0x2E205573, 0x65207468, 0x65204C20, 0x616E6420, 0x52204275, 0x74746F6E, 0x7320746F, 0x2061646A,
    0x75737420, 0x67616D65, 0x20706C61, 0x792E2000, 0x836E8393, 0x8368838B, 0x82F08DB6, 0x894582C9,
    0x89F182B5, 0x81418CC0, 0x8A4582C6, 0x82B582BD, 0x82A288CA, 0x927582C5, 0x839F82F0, 0x899F82B5,  /* fzgx-allow: A1 retail data bytes */
    0x82C482AD, 0x82BE82B3, 0x82A28142, 0xA826B81, 0x95827183, 0x67838A83, 0x4B815B83, 0x7B835E83,
    0x9382C597, 0x5682D182, 0xF092B290, 0xAE82B582, 0xC482AD82, 0xBE82B382, 0xA281420A, 0x83B482C5,
    0x8F898AFA, 0x90DD92E8, 0x82C996DF, 0x82B982DC, 0x82B78142, 0x0, (u32)lbl_4_data_C18__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_CB0__fzgx_offset_0, 0x4265666F, 0x72652063, 0x6F727265, 0x6374696F,
    0x6E000000, 0x95E290B3, 0x914F0000, (u32)lbl_4_data_D50__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_D64__fzgx_offset_0, 0x41667465, 0x7220636F, 0x72726563, 0x74696F6E, 0x0, 0x95E290B3, 0x8CE30000,
    (u32)lbl_4_data_D84__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_D98__fzgx_offset_0, 0x47616D65, 0x20446174,
    0x6120436F, 0x6E74726F, 0x6C730A49, 0x6E736572, 0x74206120, 0x4D656D6F, 0x72792043, 0x61726420,
    0x696E746F, 0x20536C6F, 0x7420412E, 0x0, 0x8351815B, 0x83808366, 0x815B835E, 0x82CC9180,  /* fzgx-allow: A1 retail data bytes */
    0x8DEC0A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F083, 0x58838D83, 0x62836782, 0x6082C993,
    0xFC82EA82, 0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_DB8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_DF0__fzgx_offset_0, 0x4C6F6164, 0x2047616D, 0x65204461, 0x74610000, 0x8351815B, 0x83808366,
    0x815B835E, 0x82CC838D, 0x815B8368, 0x0, (u32)lbl_4_data_E48__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_E58__fzgx_offset_0, 0x53617665, 0x2047616D, 0x65204461, 0x74610000, 0x8351815B, 0x83808366,
    0x815B835E, 0x82CC835A, 0x815B8375, 0x0, (u32)lbl_4_data_E88__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_E98__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20, 0x47616D65, 0x20446174, 0x61206F6E,
    0x20746869, 0x73204D65, 0x6D6F7279, 0x20436172, 0x642E0A20, 0x53617669, 0x6E67206E, 0x65772064,
    0x6174612E, 0x0, 0x83818382, 0x838A815B, 0x834A815B, 0x836882C9, 0xA835181, 0x5B838083,
    0x66815B83, 0x5E82AA8C, 0xA982C282, 0xA982E882, 0xDC82B982, 0xF181420A, 0x90568B4B, 0x835A815B,
    0x837582B5, 0x82DC82B7, 0x81420000, (u32)lbl_4_data_EC8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_F08__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20, 0x47616D65, 0x20446174, 0x61206F6E, 0x20746865,
    0x204D656D, 0x6F727920, 0x43617264, 0x2E0A4966, 0x20796F75, 0x20736176, 0x652C2074, 0x68652047,
    0x616D6520, 0x44617461, 0x20637572, 0x72656E74, 0x6C79206C, 0x6F616465, 0x640A7769, 0x6C6C2061,
    0x6C6C2062, 0x65206C6F, 0x73742E20, 0x49732074, 0x68617420, 0x4F4B3F00, 0x83818382, 0x838A815B,
    0x834A815B, 0x836882C9, 0x8351815B, 0x83808366, 0x815B835E, 0x82AA8CA9, 0x82C282A9, 0x82E882DC,  /* fzgx-allow: A1 retail data bytes */
    0x82B982F1, 0x81420A90, 0x568B4B83, 0x5A815B83, 0x7582B782, 0xE982C68C, 0xBB8DDD83, 0x8D815B83,  /* fzgx-allow: A1 retail data bytes */
    0x6882B382, 0xEA82C482, 0xA282E983, 0x51815B83, 0x80836681, 0x5B835E82, 0xAA0A9153, 0x82C48FC1,  /* fzgx-allow: A1 retail data bytes */
    0x82A682C4, 0x82B582DC, 0x82A282DC, 0x82B782AA, 0x814182E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9,  /* fzgx-allow: A1 retail data bytes */
    0x3F000000, (u32)lbl_4_data_F64__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_FD8__fzgx_offset_0, 0x54686572,
    0x65206973, 0x206E6F20, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x6C6F7420, 0x412E0000,
    0x8358838D, 0x83628367, 0x826082C9, 0xA838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xAA8CA982,
    0xC282A982, 0xE882DC82, 0xB982F181, 0x42000000, (u32)lbl_4_data_107C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10A0__fzgx_offset_0, 0x52656769, 0x73746572, 0x20746869, 0x73206E61, 0x6D65206F, 0x6E207468,
    0x65204D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20536C6F, 0x7420412E, 0x0, 0x82B182CC,
    0x96BC914F, 0x82C58381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C90A93, 0x6F985E82, 0xB582C482,  /* fzgx-allow: A1 retail data bytes */
    0xE082E682, 0xEB82B582, 0xA282C582, 0xB782A93F, 0x0, (u32)lbl_4_data_10E8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_111C__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20, 0x4D656D6F, 0x72792043,
    0x61726420, 0x696E2053, 0x6C6F7420, 0x412E0A20, 0x54686520, 0x67616D65, 0x2063616E, 0x6E6F7420,
    0x62652073, 0x61766564, 0x2E000000, 0x8358838D, 0x83628367, 0x826082C9, 0x83818382, 0x838A815B,
    0x834A815B, 0x836882AA, 0x8CA982C2, 0x82A982E8, 0x82DC82B9, 0x82F18142, 0xA835A81, 0x5B837582,
    0xC582AB82, 0xDC82B982, 0xF182C582, 0xB582BD81, 0x42000000, (u32)lbl_4_data_116C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_11AC__fzgx_offset_0, 0xFF00FFFF
};
static u32 fzgx_pool_data_lbl_4_data_0_1210[20] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x257300FF, 0xFFFF0000, 0x6F707469, 0x6F6E2E63, 0x0, 0x53656C53, 0x5F446973, 0x70506F6C,
    0x79676F6E, 0x42470000, 0x53656C53, 0x5F446973, 0x70537072, 0x69746542, 0x47000000, 0x6F707469,
    0x6F6E5F63, 0x6F6D6D6F, 0x6E5F6469, 0x73700000
};
static u32 fzgx_pool_data_lbl_4_data_1260[153] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x534D445F, 0x4F505449, 0x4F4E5F4D, 0x454E5500, 0x0, 0x0, 0x0, 0x0,
    (u32)fn_4_D10__fzgx_offset_0, (u32)fn_4_D7C__fzgx_offset_0, (u32)fn_4_EA0__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F53, 0x4156455F, 0x57414954,
    0x0, 0x0, 0x0, (u32)fn_4_9B20__fzgx_offset_0, (u32)fn_4_9C14__fzgx_offset_0, (u32)fn_4_A734__fzgx_offset_0, 0x534D445F, 0x4F505449,
    0x4F4E5F43, 0x54524C5F, 0x4D454E55, 0x0, 0x0, 0x0, (u32)fn_4_7C38__fzgx_offset_0, (u32)fn_4_7CA4__fzgx_offset_0,
    (u32)fn_4_7D94__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43, 0x4152445F, 0x4D454E55, 0x0, 0x0,
    0x0, (u32)fn_4_80EC__fzgx_offset_0, (u32)fn_4_8158__fzgx_offset_0, (u32)fn_4_8248__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F57, 0x49444500,
    0x0, 0x0, 0x0, 0x0, (u32)fn_4_869C__fzgx_offset_0, (u32)fn_4_8720__fzgx_offset_0, (u32)fn_4_898C__fzgx_offset_0, 0x534D445F,
    0x4F505449, 0x4F4E5F43, 0x414C4942, 0x0, 0x0, 0x0, 0x0, (u32)fn_4_347C__fzgx_offset_0,
    (u32)fn_4_3568__fzgx_offset_0, (u32)fn_4_406C__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F52, 0x554D424C, 0x45000000, 0x0,
    0x0, 0x0, (u32)fn_4_4784__fzgx_offset_0, (u32)fn_4_4834__fzgx_offset_0, (u32)fn_4_4B10__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F50,
    0x43555354, 0x0, 0x0, 0x0, 0x0, (u32)fn_4_6678__fzgx_offset_0, (u32)fn_4_6720__fzgx_offset_0, (u32)fn_4_78E0__fzgx_offset_0,
    0x534D445F, 0x4F505449, 0x4F4E5F43, 0x4152445F, 0x4D414E41, 0x47450000, 0x0, 0x0,
    (u32)fn_4_89E4__fzgx_offset_0, (u32)fn_4_8A54__fzgx_offset_0, (u32)fn_4_8AE0__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43, 0x4152445F, 0x47444154,
    0x41000000, 0x0, 0x0, (u32)fn_4_8DC0__fzgx_offset_0, (u32)fn_4_8E38__fzgx_offset_0, (u32)fn_4_9A78__fzgx_offset_0, 0x4D656D6F, 0x72792043,
    0x61726400, 0x83818382, 0x838A815B, 0x834A815B, 0x83680000, 0x53637265, 0x656E204D, 0x6F646500,
    0x89E696CA, 0x8382815B, 0x83680000, 0x4D0000, (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, 0x4E0000, (u32)lbl_4_data_1418__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_1424__fzgx_offset_0, 0x4F0000, (u32)lbl_4_data_1434__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1440__fzgx_offset_0,
    0x6F707469, 0x6F6E5F6D, 0x656E755F, 0x64697370, 0x0, 0x583A2534, 0x640A0000, 0x593A2534,
    0x64000000
};
static u32 fzgx_pool_data_lbl_4_data_0_14C4[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25732534, 0x64000000
};
static u32 fzgx_pool_data_lbl_4_data_0_14CC[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25346400
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_4_data_0(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_4_data_0;
    s = *(u8 *)fzgx_pool_data_lbl_4_data_0_1210;
    s = *(u8 *)fzgx_pool_data_lbl_4_data_1260;
    s = *(u8 *)fzgx_pool_data_lbl_4_data_0_14C4;
    s = *(u8 *)fzgx_pool_data_lbl_4_data_0_14CC;
}
#pragma section code_type ".text"

#pragma opt_lifetimes off
void fn_4_2394(s32 index, s32 right, u16 depth, GXColor outline, GXColor fill, s32 value) {
char buf[64];
f32 left;
f32 halfH;
f32 top;
f32 halfW;
f32 x;
f32 z;
    f32 lab_t0;

fn_1_49410();
fn_1_49738((u32)fn_1_5233C);
fn_1_49748(5.0f);
fn_1_4955C(0.8f, 0.8f);
if (lbl_801A66B4 == 5) {
sprintf(buf, ((char *)fzgx_pool_data_lbl_4_data_0_14C4), index, value);
halfH = 90.0f;
} else {
sprintf(buf, ((char *)fzgx_pool_data_lbl_4_data_0_1210), index, value);
halfH = 135.0f;
}
x = 300.0f;
halfW = 0.5f * (10.0f + fn_1_4B090(buf));
z = -0.01f * (f32)depth;
if (right) {
x -= 50.0f + halfW;
} else {
x += 50.0f + halfW;
}
fn_800371F8(1, fill);
fn_8003462C(0x80, 7, 4);
left = x - halfW;
halfW = x + halfW;
top = 320.0f - halfH;
halfH = 320.0f + halfH;
GXWGFifo.f32 = top;
GXWGFifo.f32 = left;
GXWGFifo.f32 = z;
GXWGFifo.f32 = halfH;
GXWGFifo.f32 = left;
GXWGFifo.f32 = z;
GXWGFifo.f32 = halfH;
GXWGFifo.f32 = halfW;
GXWGFifo.f32 = z;
GXWGFifo.f32 = top;
GXWGFifo.f32 = halfW;
GXWGFifo.f32 = z;
fn_800746A8(10, 0);
fn_800371F8(1, outline);
fn_8003462C(0xA8, 7, 2);
GXWGFifo.f32 = top;
GXWGFifo.f32 = left;
GXWGFifo.f32 = z;
GXWGFifo.f32 = halfH;
GXWGFifo.f32 = left;
GXWGFifo.f32 = z;
fn_8003462C(0xA8, 7, 2);
GXWGFifo.f32 = halfH;
GXWGFifo.f32 = left;
GXWGFifo.f32 = z;
GXWGFifo.f32 = halfH;
GXWGFifo.f32 = halfW;
GXWGFifo.f32 = z;
fn_8003462C(0xA8, 7, 2);
GXWGFifo.f32 = halfH;
GXWGFifo.f32 = halfW;
GXWGFifo.f32 = z;
GXWGFifo.f32 = top;
GXWGFifo.f32 = halfW;
GXWGFifo.f32 = z;
fn_8003462C(0xA8, 7, 2);
GXWGFifo.f32 = top;
GXWGFifo.f32 = halfW;
GXWGFifo.f32 = z;
GXWGFifo.f32 = top;
GXWGFifo.f32 = left;
GXWGFifo.f32 = z;
if (lbl_801A66B4 == 5) {
fn_1_495C8(9);
lab_t0 = 320.0f;
fn_1_496FC(lab_t0, x);
fn_4_2394_shadow();
fn_1_4A0D8(buf);
} else {
fn_1_495C8(8);
fn_4_2394_shadow();
lab_t0 = 192.0f;
fn_1_496FC(lab_t0, x);
fn_1_4A0D8(buf);
lab_t0 = 380.0f;
fn_1_496FC(lab_t0, x);
fn_1_4AE0C(((char *)fzgx_pool_data_lbl_4_data_0_14CC), value);
}
}
#pragma opt_lifetimes reset
/* fzgx:end fn_4_2394 */

/* fzgx:begin fn_4_2700 */
#include "dolphin/hw_regs.h"

extern struct fn_4_347C_lbl_1_bss_9C8 lbl_1_bss_9C8;
extern u32 lbl_1_data_2AC0;
extern u32 lbl_1_data_2B40;
extern u32 lbl_1_data_2B50;
extern u32 lbl_1_data_2B58;
extern u32 lbl_4_data_14D0;
extern void fn_4_3128(void);
extern u32 fn_80008BA8(u32, u32, u32);
extern u32 fn_1_F7308(void);
extern u32 lbl_1_bss_AA0;
extern u32 lbl_1_data_2B60;
extern u32 lbl_4_data_2AE8;
extern u32 memcpy(u32, u32, u32);
extern void fn_4_63D4(void);
extern int fn_1_4C10(void);
extern u16 lbl_1_bss_96A;
extern u32 fn_4_0(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_9F8;
extern u8 lbl_4_data_2C58[84];
extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_4_ABB0(void);
extern u32 fn_1_1380F0(u32);
extern u32 fn_1_13ABA8(u32);
extern u32 lbl_4_data_1A4;
extern s32 lbl_801A66B4;
extern u8 lbl_4_bss_5618;
extern u32 fn_1_B7E98(u32);
extern u32 fn_1_B800C(u32);
extern u32 fn_1_B80F0(u32);
extern u32 fn_1_B8170(u32);
extern u32 lbl_4_data_2DB4;
extern void fn_4_9AD0(void);
extern u8 *fn_4_A82C(u8 *);
extern void fn_80083DB0(u8 *, u32);
extern u32 fn_1_B9C0C(void);
extern s8 fn_1_BA144(u32 *);
extern u32 lbl_4_bss_5678;
extern u32 fn_1_B7C00(void);
extern u32 fn_1_BC310(void *);
extern u32 fn_1_C0510(u32);
extern u32 fn_1_C1394(void *);
extern s16 lbl_1_bss_962;
extern struct fn_4_9B0_lbl_4_data_1260 lbl_4_data_1260;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_426C(u32);
extern void fn_4_AB90(void);
extern struct _prolog_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern struct fn_4_869C_lbl_1_bss_718E0 lbl_1_bss_718E0;
extern s32 lbl_1_bss_970;
extern u8 lbl_4_bss_2;
extern u16 lbl_1_bss_968;


#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 167.0f;
    s = 38.0f;
    s = 0.5f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00D0D000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 78.0;
    d = 0.125;
    s = 2.9375f;
    s = 0.0f;
    d = 0.3;
    d = 1.0;
}
static const unsigned long fzgx_pool_table4[1] = {0x00D0D000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6000000238418579f;
}
static const unsigned long fzgx_pool_table6[1] = {0xFF000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.5f;
    s = 5.0f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 0.15000000596046448f;
    s = 240.0f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 96.0;
    d = 48.0;
    s = 0.25f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.004999999888241291f;
    s = 216.0f;
    d = 90.0;
    d = 320.0;
    d = 0.5;
    s = 264.0f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = -0.5;
    s = 0.014999999664723873f;
    s = 72.0f;
    s = 0.02500000037252903f;
    s = 0.05000000074505806f;
    s = 48.0f;
    s = 0.800000011920929f;
    s = 110.0f;
    s = 1.0f;
    s = 120.0f;
}
static const unsigned long fzgx_pool_table16[11] = {0x08080000, 0x78780000, 0x06060000, 0x25000000, 0x1A1A0000, 0x00250000, 0xE61A0000, 0xDB000000, 0xE6E60000, 0x00DB0000, 0x1AE60000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 1.3333333730697632f;
    s = 160.0f;
    s = 210.0f;
    s = 480.0f;
    s = -0.009999999776482582f;
    s = 1.100000023841858f;
    s = 1.399999976158142f;
    s = 20.0f;
    s = 10.0f;
    s = 0.009999999776482582f;
    s = 140.0f;
    s = 0.0010000000474974513f;
    s = 0.5625f;
    s = 0.75f;
    s = 24.0f;
    s = 105.0f;
    s = 345.0f;
}
static const unsigned long fzgx_pool_table18[6] = {0x00FF00FF, 0xFF000080, 0x0000FF80, 0x687EA0FF, 0x202020A0, 0xFFFFFF80};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -125.0f;
    s = 125.0f;
    s = -0.03999999910593033f;
    s = 100.0f;
    s = -0.04999999701976776f;
    s = 0.029999999329447746f;
    s = 90.0f;
    s = 135.0f;
    s = 300.0f;
    s = 50.0f;
    s = 192.0f;
    s = 380.0f;
    s = 64.0f;
    s = 280.0f;
    s = 576.0f;
    s = 2.0f;
    s = 32.0f;
}
#pragma section code_type ".text"

typedef struct {
    u8 r, g, b, a;
} GXColor;

/* GX write-gather pipe: every store is a FIFO push, so it must stay volatile. */
#define GX_FIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)

extern void fn_800371F8(s32, GXColor);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800746A8(u8, s32);

// Draws a filled box centred on x=320 with an outline in a second colour.
void fn_4_2700(u16 depth, GXColor outline, GXColor fill, f32 width, f32 height) {
    f32 right;
    f32 left;
    f32 z;
    f32 top;
    f32 bottom;
    f32 zFill;
    f32 scale = 2.0f;

    width = width * scale;
    height = height * scale;
    fn_800371F8(1, fill);
    fn_8003462C(0x80, 7, 4);
    top = 280.0f;
    bottom = 320.0f;
    left = bottom - width;
    right = bottom + height;
    GX_FIFO_F32 = left;
    GX_FIFO_F32 = top;
    z = -0.01f * (f32)depth;
    zFill = z - 0.001f;
    GX_FIFO_F32 = zFill;
    GX_FIFO_F32 = right;
    GX_FIFO_F32 = top;
    GX_FIFO_F32 = zFill;
    GX_FIFO_F32 = right;
    GX_FIFO_F32 = bottom;
    GX_FIFO_F32 = zFill;
    GX_FIFO_F32 = left;
    GX_FIFO_F32 = bottom;
    GX_FIFO_F32 = zFill;

    fn_800371F8(1, outline);
    fn_800746A8(10, 0);
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = left;
    GX_FIFO_F32 = top;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = right;
    GX_FIFO_F32 = top;
    GX_FIFO_F32 = z;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = right;
    GX_FIFO_F32 = top;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = right;
    GX_FIFO_F32 = bottom;
    GX_FIFO_F32 = z;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = right;
    GX_FIFO_F32 = bottom;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = left;
    GX_FIFO_F32 = bottom;
    GX_FIFO_F32 = z;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = left;
    GX_FIFO_F32 = bottom;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = left;
    GX_FIFO_F32 = top;
    GX_FIFO_F32 = z;
}
/* fzgx:end fn_4_2700 */

/* fzgx:begin fn_4_28FC noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"

#pragma fp_contract off
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 167.0f;
    s = 38.0f;
    s = 0.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00D0D000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 78.0;
    d = 0.125;
    s = 2.9375f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3;
    d = 1.0;
}
static const u32 fzgx_pool_table6[1] = {0x00D0D000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6000000238418579f;
}
static const u32 fzgx_pool_table8[1] = {0xFF000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.5f;
    s = 5.0f;
    s = 0.0f;
    s = 320.0f;
    s = 0.15000000596046448f;
    s = 240.0f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 96.0;
    d = 48.0;
    s = 0.25f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.004999999888241291f;
    s = 216.0f;
    d = 90.0;
    d = 320.0;
    d = 0.5;
    s = 264.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = -0.5;
    s = 0.014999999664723873f;
    s = 72.0f;
    s = 0.02500000037252903f;
    s = 0.05000000074505806f;
    s = 48.0f;
    s = 0.800000011920929f;
    s = 110.0f;
    s = 1.0f;
    s = 120.0f;
}
static const u32 fzgx_pool_table16[11] = {0x08080000, 0x78780000, 0x06060000, 0x25000000, 0x1A1A0000, 0x00250000, 0xE61A0000, 0xDB000000, 0xE6E60000, 0x00DB0000, 0x1AE60000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 1.3333333730697632f;
    s = 160.0f;
    s = 210.0f;
    s = 480.0f;
    s = -0.009999999776482582f;
    s = 1.100000023841858f;
    s = 1.399999976158142f;
    s = 20.0f;
    s = 10.0f;
    s = 0.009999999776482582f;
    s = 140.0f;
    s = 0.0010000000474974513f;
    s = 0.5625f;
    s = 0.75f;
    s = 24.0f;
    s = 105.0f;
    s = 345.0f;
}
static const u32 fzgx_pool_table18[6] = {0x00FF00FF, 0xFF000080, 0x0000FF80, 0x687EA0FF, 0x202020A0, 0xFFFFFF80};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -125.0f;
    s = 125.0f;
    s = -0.03999999910593033f;
    s = 100.0f;
    s = -0.04999999701976776f;
    s = 0.029999999329447746f;
    s = 90.0f;
    s = 135.0f;
    s = 300.0f;
    s = 50.0f;
    s = 192.0f;
    s = 380.0f;
    s = 64.0f;
    s = 280.0f;
    s = 576.0f;
    s = 2.0f;
    s = 32.0f;
    s = -10.0f;
}
#pragma section code_type ".text"

typedef struct {
    u8 r, g, b, a;
} GXColor;

/* GX write-gather FIFO port: every store is a command word */
#define GX_FIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)  /* fzgx-allow: S2 hardware FIFO */

s16 fzgx_obj_lbl_4_bss_0;
u8 fzgx_obj_lbl_4_bss_2;
u32 fzgx_obj_lbl_4_bss_4;
u32 fzgx_obj_lbl_4_bss_8;
u8 fzgx_obj_lbl_4_bss_C;
u8 fzgx_obj_lbl_4_bss_D;
u8 fzgx_obj_lbl_4_bss_10[8];
u8 lbl_4_bss_10__fzgx_offset_8[4];
u8 lbl_4_bss_10__fzgx_offset_C[0x34];
f32 lbl_4_bss_10__fzgx_offset_40;
f32 lbl_4_bss_10__fzgx_offset_44;
s8 lbl_4_bss_10__fzgx_offset_48;
u8 lbl_4_bss_10__fzgx_offset_49;
u8 lbl_4_bss_10__fzgx_offset_4A;
u8 lbl_4_bss_10__fzgx_offset_4B;
u8 lbl_4_bss_10__fzgx_offset_4C[0x68];
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_4_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_2;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_4;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_8;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_C;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_D;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_10;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_8;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_C;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_40;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_44;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_48;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_49;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_4A;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_4B;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_4C;
}
#pragma section code_type ".text"

#define option_width lbl_4_bss_10__fzgx_offset_40
#define option_height lbl_4_bss_10__fzgx_offset_44
#define option_offset lbl_4_bss_10__fzgx_offset_48
#define option_size_a lbl_4_bss_10__fzgx_offset_8
#define option_size_b lbl_4_bss_10__fzgx_offset_C

extern s32 lbl_801A66B4;
extern char *lbl_4_data_D6C[];
extern char *lbl_4_data_DA0[];

extern void fn_4_2700(u16, GXColor, GXColor, f32, f32);
extern void fn_4_2394(char *, s32, u16, GXColor, GXColor, s32);
extern void fn_80072344(void);
extern void fn_8006CD2C(f32 *, f32 *);
extern s8 fn_1_A5DC4(void);
extern void fn_8006CD20(f32, f32);
extern void fn_8006CD50(void);
extern void lbl_8006D758(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void fn_80072558(void);
extern void fn_80074788(u32);
extern void fn_80074660(u32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072864(u32);
extern void fn_80074918(u8, s32, u8);
extern void fn_8007245C(u32);
extern void fn_800371F8(s32, GXColor);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800746A8(u8, s32);
extern s8 fn_1_1ACC(s8, u8 *, u8 *);
extern void fn_80072378(void);

static inline void draw_marker(f32 pos, s32 below, GXColor fill, GXColor line) {
    f32 x;
    f32 y;
    f32 d;
    pos = pos;
    x = 320.0f + 2.0f * pos;
    y = 300.0f;
    if (below) {
        y += 32.0f;
        d = -10.0f;
    } else {
        y -= 32.0f;
        d = 10.0f;
    }
    fn_800371F8(1, fill);
    fn_8003462C(0x90, 7, 3);
    GX_FIFO_F32 = x - d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.031f;
    GX_FIFO_F32 = x + d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.031f;
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y + d;
    GX_FIFO_F32 = -0.031f;

    fn_800371F8(1, line);
    fn_800746A8(10, 0);
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x - d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
    GX_FIFO_F32 = x + d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x + d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y + d;
    GX_FIFO_F32 = -0.03f;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y + d;
    GX_FIFO_F32 = -0.03f;
    GX_FIFO_F32 = x - d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
}


static inline void draw_marker2(f32 pos, s32 below, GXColor fill, GXColor line) {
    f32 y;
    f32 x;
    f32 d;
    pos = pos;
    x = 320.0f + 2.0f * pos;
    y = 300.0f;
    if (below) {
        y += 32.0f;
        d = -10.0f;
    } else {
        y -= 32.0f;
        d = 10.0f;
    }
    fn_800371F8(1, fill);
    fn_8003462C(0x90, 7, 3);
    GX_FIFO_F32 = x - d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.031f;
    GX_FIFO_F32 = x + d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.031f;
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y + d;
    GX_FIFO_F32 = -0.031f;

    fn_800371F8(1, line);
    fn_800746A8(10, 0);
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x - d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
    GX_FIFO_F32 = x + d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x + d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y + d;
    GX_FIFO_F32 = -0.03f;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y + d;
    GX_FIFO_F32 = -0.03f;
    GX_FIFO_F32 = x - d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
}


static inline void draw_panel(f32 x0, f32 y0, f32 x1, f32 y1, GXColor fill, GXColor line) {
    fn_800371F8(1, fill);
    fn_8003462C(0x80, 7, 4);
    GX_FIFO_F32 = x0;
    GX_FIFO_F32 = y0;
    GX_FIFO_F32 = -0.06f;
    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y0;
    GX_FIFO_F32 = -0.06f;
    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y1;
    GX_FIFO_F32 = -0.06f;
    GX_FIFO_F32 = x0;
    GX_FIFO_F32 = y1;
    GX_FIFO_F32 = -0.06f;

    fn_800371F8(1, line);
    fn_800746A8(10, 0);
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x0;
    GX_FIFO_F32 = y0;
    GX_FIFO_F32 = -0.01f;
    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y0;
    GX_FIFO_F32 = -0.01f;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y0;
    GX_FIFO_F32 = -0.01f;
    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y1;
    GX_FIFO_F32 = -0.01f;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y1;
    GX_FIFO_F32 = -0.01f;
    GX_FIFO_F32 = x0;
    GX_FIFO_F32 = y1;
    GX_FIFO_F32 = -0.01f;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x0;
    GX_FIFO_F32 = y1;
    GX_FIFO_F32 = -0.01f;
    GX_FIFO_F32 = x0;
    GX_FIFO_F32 = y0;
    GX_FIFO_F32 = -0.01f;

}

void fn_4_28FC(void) {
    GXColor c0 = {0x68, 0x7E, 0xA0, 0xFF};
    GXColor c1 = {0x00, 0xFF, 0x00, 0xFF};
    GXColor c2 = {0x20, 0x20, 0x20, 0xA0};
    GXColor c3 = {0xFF, 0x00, 0x00, 0x80};
    GXColor c4 = {0x00, 0x00, 0xFF, 0x80};
    GXColor c5 = {0xFF, 0xFF, 0x00, 0xFF};
    f32 width;
    f32 value;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;

    fn_80072344();
    fn_8006CD2C(&option_width, &option_height);
    width = option_width;
    if (fn_1_A5DC4()) {
        width *= 1.3333334f;
    }
    fn_8006CD20(width, option_height);
    fn_8006CD50();
    lbl_8006D758();
    lbl_8006E0B4(0.5f * (width - option_width), 0.0f, 0.0f);
    fn_80072558();
    fn_80074788(1);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_800747D0(4, 0, 1, 0, 0, 2, 2);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 0xFF, 0xFF, 4);
    fn_80072C24(0, 0xF, 0xF, 0xA, 2);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 5, 1);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_80072864(0);
    fn_80074918(1, 3, 1);
    fn_8007245C(0x200);

    x0 = 64.0f;
    y0 = 280.0f;
    x1 = 576.0f;
    y1 = 320.0f;
    draw_panel(x0, y0, x1, y1, c2, c0);

    fn_4_2700(4, c1, c4, option_size_b[1], option_size_b[0]);
    fn_4_2700(5, c1, c3, option_size_a[1], option_size_a[0]);

    draw_marker(option_offset, 0, c5, c1);
    fn_4_2394(lbl_4_data_D6C[lbl_801A66B4], 1, 4, c0, c2, option_offset);

    value = fn_1_1ACC(option_offset, option_size_a, option_size_b);
    draw_marker2(1.28f * value, 1, c5, c1);
    fn_4_2394(lbl_4_data_DA0[lbl_801A66B4], 0, 4, c0, c2, value);

    fn_800746A8(6, 0);
    fn_8006CD20(option_width, option_height);
    fn_80072378();
}
/* fzgx:end fn_4_28FC */

/* fzgx:begin fn_4_347C noprologue */
#include "types.h"

extern struct fn_4_347C_lbl_1_bss_9C8 lbl_1_bss_9C8;
extern u32 lbl_1_data_2AC0;
extern u32 lbl_1_data_2B40;
extern u32 lbl_1_data_2B50;
extern u32 lbl_1_data_2B58;
extern u32 lbl_4_data_14D0;
extern void fn_4_3128(void);
extern u32 fn_80008BA8(u32, u32, u32);

struct fn_4_347C_lbl_1_bss_9C8_0_E12 {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 unk_3;
    u8 pad_4[0x8];
};
struct fn_4_347C_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0x46];
    u8 unk_58;
    u8 unk_59;
    u8 unk_5A;
    u8 unk_5B;
    u8 unk_5C;
    u8 unk_5D;
};
struct fn_4_347C_lbl_1_bss_9C8 {
    struct fn_4_347C_lbl_1_bss_9C8_0_E12 unk_0[1];
};

extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern struct fn_4_347C_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);

void fn_4_347C(void) {
    struct fn_4_347C_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 v0;
    u8 v1;
    u8 v2;
    u32 t1;
    p_lbl_4_bss_0 = (struct fn_4_347C_lbl_4_bss_0 *)&lbl_4_bss_0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_14D0, (u32)fn_4_3128, 0, 20);
    p_lbl_4_bss_0->unk_0 = t1;
    fn_80008BA8((u32)((u8 *)(u32)p_lbl_4_bss_0 + 96), (u32)&lbl_1_data_2AC0, 64);
    fn_80008BA8((u32)((u8 *)(u32)p_lbl_4_bss_0 + 160), (u32)&lbl_1_data_2B40, 8);
    fn_80008BA8((u32)((u8 *)(u32)p_lbl_4_bss_0 + 168), (u32)&lbl_1_data_2B50, 8);
    fn_80008BA8((u32)((u8 *)(u32)p_lbl_4_bss_0 + 176), (u32)&lbl_1_data_2B58, 8);
    v0 = p_lbl_4_bss_0->unk_8;
    p_lbl_4_bss_0->unk_5A = 0;
    p_lbl_4_bss_0->unk_5C = 0;
    p_lbl_4_bss_0->unk_5B = 0;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, v0);
    v1 = lbl_1_bss_9C8.unk_0[p_lbl_4_bss_0->unk_5D].unk_2;
    p_lbl_4_bss_0->unk_58 = v1;
    p_lbl_4_bss_0->unk_59 = (lbl_1_bss_9C8.unk_0[p_lbl_4_bss_0->unk_5D].unk_3);
}
/* fzgx:end fn_4_347C */

/* fzgx:begin fn_4_406C */
// Finalizes the pending option callback and clears its handle.
void fn_4_406C(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_406C */

/* fzgx:begin fn_4_467C noprologue */
#include "types.h"

extern u32 lbl_801A66B4;
extern void fn_4_2D4(u8, u32);
extern void fn_4_40C4(u8, u32);
extern void fn_1_1380F0(u32);
extern void fn_1_13ABA8(u32);


extern u8 fn_4_347C__fzgx_offset_0[];
extern u8 fn_4_3568__fzgx_offset_0[];
extern u8 fn_4_406C__fzgx_offset_0[];
extern u8 fn_4_4784__fzgx_offset_0[];
extern u8 fn_4_4834__fzgx_offset_0[];
extern u8 fn_4_4B10__fzgx_offset_0[];
extern u8 fn_4_4B74__fzgx_offset_10C[];
extern u8 fn_4_4B74__fzgx_offset_124[];
extern u8 fn_4_4B74__fzgx_offset_68[];
extern u8 fn_4_4B74__fzgx_offset_7C[];
extern u8 fn_4_4B74__fzgx_offset_94[];
extern u8 fn_4_4B74__fzgx_offset_AC[];
extern u8 fn_4_4B74__fzgx_offset_C4[];
extern u8 fn_4_4B74__fzgx_offset_DC[];
extern u8 fn_4_4B74__fzgx_offset_F4[];
extern u8 fn_4_4CB8__fzgx_offset_110[];
extern u8 fn_4_4CB8__fzgx_offset_128[];
extern u8 fn_4_4CB8__fzgx_offset_6C[];
extern u8 fn_4_4CB8__fzgx_offset_80[];
extern u8 fn_4_4CB8__fzgx_offset_98[];
extern u8 fn_4_4CB8__fzgx_offset_B0[];
extern u8 fn_4_4CB8__fzgx_offset_C8[];
extern u8 fn_4_4CB8__fzgx_offset_E0[];
extern u8 fn_4_4CB8__fzgx_offset_F8[];
extern u8 fn_4_4DF8__fzgx_offset_12E4[];
extern u8 fn_4_4DF8__fzgx_offset_1308[];
extern u8 fn_4_4DF8__fzgx_offset_1330[];
extern u8 fn_4_4DF8__fzgx_offset_1350[];
extern u8 fn_4_4DF8__fzgx_offset_1378[];
extern u8 fn_4_4DF8__fzgx_offset_1398[];
extern u8 fn_4_4DF8__fzgx_offset_13C0[];
extern u8 fn_4_4DF8__fzgx_offset_13E0[];
extern u8 fn_4_4DF8__fzgx_offset_1408[];
extern u8 fn_4_4DF8__fzgx_offset_1428[];
extern u8 fn_4_4DF8__fzgx_offset_1454[];
extern u8 fn_4_4DF8__fzgx_offset_3E4[];
extern u8 fn_4_4DF8__fzgx_offset_3F4[];
extern u8 fn_4_4DF8__fzgx_offset_408[];
extern u8 fn_4_4DF8__fzgx_offset_41C[];
extern u8 fn_4_4DF8__fzgx_offset_430[];
extern u8 fn_4_4DF8__fzgx_offset_444[];
extern u8 fn_4_4DF8__fzgx_offset_458[];
extern u8 fn_4_4DF8__fzgx_offset_46C[];
extern u8 fn_4_4DF8__fzgx_offset_480[];
extern u8 fn_4_4DF8__fzgx_offset_930[];
extern u8 fn_4_4DF8__fzgx_offset_940[];
extern u8 fn_4_4DF8__fzgx_offset_954[];
extern u8 fn_4_4DF8__fzgx_offset_968[];
extern u8 fn_4_4DF8__fzgx_offset_97C[];
extern u8 fn_4_4DF8__fzgx_offset_990[];
extern u8 fn_4_4DF8__fzgx_offset_9A4[];
extern u8 fn_4_4DF8__fzgx_offset_9B8[];
extern u8 fn_4_4DF8__fzgx_offset_9CC[];
extern u8 fn_4_4DF8__fzgx_offset_D2C[];
extern u8 fn_4_4DF8__fzgx_offset_D4C[];
extern u8 fn_4_4DF8__fzgx_offset_D6C[];
extern u8 fn_4_4DF8__fzgx_offset_D8C[];
extern u8 fn_4_4DF8__fzgx_offset_DB4[];
extern u8 fn_4_4DF8__fzgx_offset_DD4[];
extern u8 fn_4_4DF8__fzgx_offset_DF4[];
extern u8 fn_4_4DF8__fzgx_offset_E14[];
extern u8 fn_4_4DF8__fzgx_offset_E34[];
extern u8 fn_4_4DF8__fzgx_offset_E54[];
extern u8 fn_4_4DF8__fzgx_offset_E80[];
extern u8 fn_4_63D4__fzgx_offset_150[];
extern u8 fn_4_63D4__fzgx_offset_170[];
extern u8 fn_4_63D4__fzgx_offset_190[];
extern u8 fn_4_63D4__fzgx_offset_1C0[];
extern u8 fn_4_63D4__fzgx_offset_1F0[];
extern u8 fn_4_63D4__fzgx_offset_94[];
extern u8 fn_4_63D4__fzgx_offset_F8[];
extern u8 fn_4_6678__fzgx_offset_0[];
extern u8 fn_4_6720__fzgx_offset_0[];
extern u8 fn_4_6720__fzgx_offset_1038[];
extern u8 fn_4_6720__fzgx_offset_1114[];
extern u8 fn_4_6720__fzgx_offset_148[];
extern u8 fn_4_6720__fzgx_offset_298[];
extern u8 fn_4_6720__fzgx_offset_404[];
extern u8 fn_4_6720__fzgx_offset_414[];
extern u8 fn_4_6720__fzgx_offset_428[];
extern u8 fn_4_6720__fzgx_offset_43C[];
extern u8 fn_4_6720__fzgx_offset_450[];
extern u8 fn_4_6720__fzgx_offset_464[];
extern u8 fn_4_6720__fzgx_offset_478[];
extern u8 fn_4_6720__fzgx_offset_48C[];
extern u8 fn_4_6720__fzgx_offset_4A0[];
extern u8 fn_4_6720__fzgx_offset_540[];
extern u8 fn_4_6720__fzgx_offset_5E4[];
extern u8 fn_4_6720__fzgx_offset_5F4[];
extern u8 fn_4_6720__fzgx_offset_608[];
extern u8 fn_4_6720__fzgx_offset_61C[];
extern u8 fn_4_6720__fzgx_offset_630[];
extern u8 fn_4_6720__fzgx_offset_644[];
extern u8 fn_4_6720__fzgx_offset_658[];
extern u8 fn_4_6720__fzgx_offset_66C[];
extern u8 fn_4_6720__fzgx_offset_680[];
extern u8 fn_4_6720__fzgx_offset_710[];
extern u8 fn_4_6720__fzgx_offset_720[];
extern u8 fn_4_6720__fzgx_offset_734[];
extern u8 fn_4_6720__fzgx_offset_748[];
extern u8 fn_4_6720__fzgx_offset_75C[];
extern u8 fn_4_6720__fzgx_offset_770[];
extern u8 fn_4_6720__fzgx_offset_784[];
extern u8 fn_4_6720__fzgx_offset_798[];
extern u8 fn_4_6720__fzgx_offset_7AC[];
extern u8 fn_4_6720__fzgx_offset_93C[];
extern u8 fn_4_6720__fzgx_offset_94C[];
extern u8 fn_4_6720__fzgx_offset_960[];
extern u8 fn_4_6720__fzgx_offset_974[];
extern u8 fn_4_6720__fzgx_offset_988[];
extern u8 fn_4_6720__fzgx_offset_98[];
extern u8 fn_4_6720__fzgx_offset_99C[];
extern u8 fn_4_6720__fzgx_offset_9B0[];
extern u8 fn_4_6720__fzgx_offset_9C4[];
extern u8 fn_4_6720__fzgx_offset_9D8[];
extern u8 fn_4_6720__fzgx_offset_B48[];
extern u8 fn_4_6720__fzgx_offset_B58[];
extern u8 fn_4_6720__fzgx_offset_B6C[];
extern u8 fn_4_6720__fzgx_offset_B80[];
extern u8 fn_4_6720__fzgx_offset_B94[];
extern u8 fn_4_6720__fzgx_offset_BA8[];
extern u8 fn_4_6720__fzgx_offset_BBC[];
extern u8 fn_4_6720__fzgx_offset_BD0[];
extern u8 fn_4_6720__fzgx_offset_BE4[];
extern u8 fn_4_6720__fzgx_offset_C94[];
extern u8 fn_4_6720__fzgx_offset_CA4[];
extern u8 fn_4_6720__fzgx_offset_CB8[];
extern u8 fn_4_6720__fzgx_offset_CCC[];
extern u8 fn_4_6720__fzgx_offset_CE0[];
extern u8 fn_4_6720__fzgx_offset_CF4[];
extern u8 fn_4_6720__fzgx_offset_D08[];
extern u8 fn_4_6720__fzgx_offset_D1C[];
extern u8 fn_4_6720__fzgx_offset_D30[];
extern u8 fn_4_6720__fzgx_offset_D6C[];
extern u8 fn_4_6720__fzgx_offset_E8C[];
extern u8 fn_4_78E0__fzgx_offset_0[];
extern u8 fn_4_7C38__fzgx_offset_0[];
extern u8 fn_4_7CA4__fzgx_offset_0[];
extern u8 fn_4_7D94__fzgx_offset_0[];
extern u8 fn_4_80EC__fzgx_offset_0[];
extern u8 fn_4_8158__fzgx_offset_0[];
extern u8 fn_4_8248__fzgx_offset_0[];
extern u8 fn_4_869C__fzgx_offset_0[];
extern u8 fn_4_8720__fzgx_offset_0[];
extern u8 fn_4_898C__fzgx_offset_0[];
extern u8 fn_4_89E4__fzgx_offset_0[];
extern u8 fn_4_8A54__fzgx_offset_0[];
extern u8 fn_4_8AE0__fzgx_offset_0[];
extern u8 fn_4_8DC0__fzgx_offset_0[];
extern u8 fn_4_8E38__fzgx_offset_0[];
extern u8 fn_4_9A78__fzgx_offset_0[];
extern u8 fn_4_9B20__fzgx_offset_0[];
extern u8 fn_4_9C14__fzgx_offset_0[];
extern u8 fn_4_A734__fzgx_offset_0[];
extern u8 fn_4_D10__fzgx_offset_0[];
extern u8 fn_4_D7C__fzgx_offset_0[];
extern u8 fn_4_EA0__fzgx_offset_0[];
extern u8 lbl_4_data_0__fzgx_offset_0[];
extern u8 lbl_4_data_100__fzgx_offset_0[];
extern u8 lbl_4_data_107C__fzgx_offset_0[];
extern u8 lbl_4_data_10A0__fzgx_offset_0[];
extern u8 lbl_4_data_10E8__fzgx_offset_0[];
extern u8 lbl_4_data_10__fzgx_offset_0[];
extern u8 lbl_4_data_111C__fzgx_offset_0[];
extern u8 lbl_4_data_116C__fzgx_offset_0[];
extern u8 lbl_4_data_11AC__fzgx_offset_0[];
extern u8 lbl_4_data_130__fzgx_offset_0[];
extern u8 lbl_4_data_1418__fzgx_offset_0[];
extern u8 lbl_4_data_1424__fzgx_offset_0[];
extern u8 lbl_4_data_1434__fzgx_offset_0[];
extern u8 lbl_4_data_1440__fzgx_offset_0[];
extern u8 lbl_4_data_1534__fzgx_offset_0[];
extern u8 lbl_4_data_1544__fzgx_offset_0[];
extern u8 lbl_4_data_154C__fzgx_offset_0[];
extern u8 lbl_4_data_1558__fzgx_offset_0[];
extern u8 lbl_4_data_156C__fzgx_offset_0[];
extern u8 lbl_4_data_1588__fzgx_offset_0[];
extern u8 lbl_4_data_15AC__fzgx_offset_0[];
extern u8 lbl_4_data_15B4__fzgx_offset_0[];
extern u8 lbl_4_data_1660__fzgx_offset_0[];
extern u8 lbl_4_data_1678__fzgx_offset_0[];
extern u8 lbl_4_data_1688__fzgx_offset_0[];
extern u8 lbl_4_data_168C__fzgx_offset_0[];
extern u8 lbl_4_data_16A0__fzgx_offset_0[];
extern u8 lbl_4_data_16FC__fzgx_offset_0[];
extern u8 lbl_4_data_1704__fzgx_offset_0[];
extern u8 lbl_4_data_170__fzgx_offset_0[];
extern u8 lbl_4_data_1718__fzgx_offset_0[];
extern u8 lbl_4_data_172C__fzgx_offset_0[];
extern u8 lbl_4_data_1740__fzgx_offset_0[];
extern u8 lbl_4_data_175C__fzgx_offset_0[];
extern u8 lbl_4_data_1770__fzgx_offset_0[];
extern u8 lbl_4_data_177C__fzgx_offset_0[];
extern u8 lbl_4_data_1790__fzgx_offset_0[];
extern u8 lbl_4_data_179C__fzgx_offset_0[];
extern u8 lbl_4_data_17B0__fzgx_offset_0[];
extern u8 lbl_4_data_17BC__fzgx_offset_0[];
extern u8 lbl_4_data_17D0__fzgx_offset_0[];
extern u8 lbl_4_data_17DC__fzgx_offset_0[];
extern u8 lbl_4_data_17F0__fzgx_offset_0[];
extern u8 lbl_4_data_17FC__fzgx_offset_0[];
extern u8 lbl_4_data_1810__fzgx_offset_0[];
extern u8 lbl_4_data_1818__fzgx_offset_0[];
extern u8 lbl_4_data_188__fzgx_offset_0[];
extern u8 lbl_4_data_1904__fzgx_offset_0[];
extern u8 lbl_4_data_1924__fzgx_offset_0[];
extern u8 lbl_4_data_192C__fzgx_offset_0[];
extern u8 lbl_4_data_193C__fzgx_offset_0[];
extern u8 lbl_4_data_1958__fzgx_offset_0[];
extern u8 lbl_4_data_1960__fzgx_offset_0[];
extern u8 lbl_4_data_1970__fzgx_offset_0[];
extern u8 lbl_4_data_1980__fzgx_offset_0[];
extern u8 lbl_4_data_1988__fzgx_offset_0[];
extern u8 lbl_4_data_1998__fzgx_offset_0[];
extern u8 lbl_4_data_19A8__fzgx_offset_0[];
extern u8 lbl_4_data_19B0__fzgx_offset_0[];
extern u8 lbl_4_data_19C0__fzgx_offset_0[];
extern u8 lbl_4_data_19E0__fzgx_offset_0[];
extern u8 lbl_4_data_19E8__fzgx_offset_0[];
extern u8 lbl_4_data_1A04__fzgx_offset_0[];
extern u8 lbl_4_data_1A24__fzgx_offset_0[];
extern u8 lbl_4_data_1A2C__fzgx_offset_0[];
extern u8 lbl_4_data_1A48__fzgx_offset_0[];
extern u8 lbl_4_data_1A64__fzgx_offset_0[];
extern u8 lbl_4_data_1A6C__fzgx_offset_0[];
extern u8 lbl_4_data_1A80__fzgx_offset_0[];
extern u8 lbl_4_data_1A98__fzgx_offset_0[];
extern u8 lbl_4_data_1AA0__fzgx_offset_0[];
extern u8 lbl_4_data_1AB4__fzgx_offset_0[];
extern u8 lbl_4_data_1AC4__fzgx_offset_0[];
extern u8 lbl_4_data_1ADC__fzgx_offset_0[];
extern u8 lbl_4_data_1AE8__fzgx_offset_0[];
extern u8 lbl_4_data_1BC__fzgx_offset_0[];
extern u8 lbl_4_data_1C78__fzgx_offset_0[];
extern u8 lbl_4_data_1C98__fzgx_offset_0[];
extern u8 lbl_4_data_1CA8__fzgx_offset_0[];
extern u8 lbl_4_data_1CC4__fzgx_offset_0[];
extern u8 lbl_4_data_1E60__fzgx_offset_0[];
extern u8 lbl_4_data_1E74__fzgx_offset_0[];
extern u8 lbl_4_data_1E7C__fzgx_offset_0[];
extern u8 lbl_4_data_1E8C__fzgx_offset_0[];
extern u8 lbl_4_data_1EA4__fzgx_offset_0[];
extern u8 lbl_4_data_1EB0__fzgx_offset_0[];
extern u8 lbl_4_data_1EC0__fzgx_offset_0[];
extern u8 lbl_4_data_1ED4__fzgx_offset_0[];
extern u8 lbl_4_data_1EDC__fzgx_offset_0[];
extern u8 lbl_4_data_1EEC__fzgx_offset_0[];
extern u8 lbl_4_data_1F00__fzgx_offset_0[];
extern u8 lbl_4_data_1F08__fzgx_offset_0[];
extern u8 lbl_4_data_1F18__fzgx_offset_0[];
extern u8 lbl_4_data_1F24__fzgx_offset_0[];
extern u8 lbl_4_data_1F28__fzgx_offset_0[];
extern u8 lbl_4_data_1F34__fzgx_offset_0[];
extern u8 lbl_4_data_1F40__fzgx_offset_0[];
extern u8 lbl_4_data_1F44__fzgx_offset_0[];
extern u8 lbl_4_data_1F50__fzgx_offset_0[];
extern u8 lbl_4_data_1F5C__fzgx_offset_0[];
extern u8 lbl_4_data_1F60__fzgx_offset_0[];
extern u8 lbl_4_data_1F6C__fzgx_offset_0[];
extern u8 lbl_4_data_1F78__fzgx_offset_0[];
extern u8 lbl_4_data_1F7C__fzgx_offset_0[];
extern u8 lbl_4_data_1F88__fzgx_offset_0[];
extern u8 lbl_4_data_1F94__fzgx_offset_0[];
extern u8 lbl_4_data_1F98__fzgx_offset_0[];
extern u8 lbl_4_data_1FA4__fzgx_offset_0[];
extern u8 lbl_4_data_1FBC__fzgx_offset_0[];
extern u8 lbl_4_data_1FD8__fzgx_offset_0[];
extern u8 lbl_4_data_1FF0__fzgx_offset_0[];
extern u8 lbl_4_data_1FFC__fzgx_offset_0[];
extern u8 lbl_4_data_2018__fzgx_offset_0[];
extern u8 lbl_4_data_2030__fzgx_offset_0[];
extern u8 lbl_4_data_2038__fzgx_offset_0[];
extern u8 lbl_4_data_2054__fzgx_offset_0[];
extern u8 lbl_4_data_2068__fzgx_offset_0[];
extern u8 lbl_4_data_2070__fzgx_offset_0[];
extern u8 lbl_4_data_208C__fzgx_offset_0[];
extern u8 lbl_4_data_209C__fzgx_offset_0[];
extern u8 lbl_4_data_20A4__fzgx_offset_0[];
extern u8 lbl_4_data_20B4__fzgx_offset_0[];
extern u8 lbl_4_data_20C8__fzgx_offset_0[];
extern u8 lbl_4_data_20D4__fzgx_offset_0[];
extern u8 lbl_4_data_20E4__fzgx_offset_0[];
extern u8 lbl_4_data_20F4__fzgx_offset_0[];
extern u8 lbl_4_data_20FC__fzgx_offset_0[];
extern u8 lbl_4_data_210C__fzgx_offset_0[];
extern u8 lbl_4_data_210__fzgx_offset_0[];
extern u8 lbl_4_data_211C__fzgx_offset_0[];
extern u8 lbl_4_data_2124__fzgx_offset_0[];
extern u8 lbl_4_data_2134__fzgx_offset_0[];
extern u8 lbl_4_data_2140__fzgx_offset_0[];
extern u8 lbl_4_data_2144__fzgx_offset_0[];
extern u8 lbl_4_data_2158__fzgx_offset_0[];
extern u8 lbl_4_data_2164__fzgx_offset_0[];
extern u8 lbl_4_data_216C__fzgx_offset_0[];
extern u8 lbl_4_data_2480__fzgx_offset_0[];
extern u8 lbl_4_data_2494__fzgx_offset_0[];
extern u8 lbl_4_data_24A0__fzgx_offset_0[];
extern u8 lbl_4_data_24B8__fzgx_offset_0[];
extern u8 lbl_4_data_24C4__fzgx_offset_0[];
extern u8 lbl_4_data_24D8__fzgx_offset_0[];
extern u8 lbl_4_data_24E8__fzgx_offset_0[];
extern u8 lbl_4_data_24F4__fzgx_offset_0[];
extern u8 lbl_4_data_254__fzgx_offset_0[];
extern u8 lbl_4_data_2804__fzgx_offset_0[];
extern u8 lbl_4_data_2810__fzgx_offset_0[];
extern u8 lbl_4_data_2834__fzgx_offset_0[];
extern u8 lbl_4_data_2848__fzgx_offset_0[];
extern u8 lbl_4_data_284__fzgx_offset_0[];
extern u8 lbl_4_data_2870__fzgx_offset_0[];
extern u8 lbl_4_data_290C__fzgx_offset_0[];
extern u8 lbl_4_data_2BF4__fzgx_offset_0[];
extern u8 lbl_4_data_2C00__fzgx_offset_0[];
extern u8 lbl_4_data_2C14__fzgx_offset_0[];
extern u8 lbl_4_data_2C20__fzgx_offset_0[];
extern u8 lbl_4_data_2C30__fzgx_offset_0[];
extern u8 lbl_4_data_2C44__fzgx_offset_0[];
extern u8 lbl_4_data_2CC__fzgx_offset_0[];
extern u8 lbl_4_data_2F0__fzgx_offset_0[];
extern u8 lbl_4_data_32C__fzgx_offset_0[];
extern u8 lbl_4_data_34C__fzgx_offset_0[];
extern u8 lbl_4_data_37C__fzgx_offset_0[];
extern u8 lbl_4_data_38__fzgx_offset_0[];
extern u8 lbl_4_data_3B8__fzgx_offset_0[];
extern u8 lbl_4_data_400__fzgx_offset_0[];
extern u8 lbl_4_data_438__fzgx_offset_0[];
extern u8 lbl_4_data_480__fzgx_offset_0[];
extern u8 lbl_4_data_4C__fzgx_offset_0[];
extern u8 lbl_4_data_4F0__fzgx_offset_0[];
extern u8 lbl_4_data_578__fzgx_offset_0[];
extern u8 lbl_4_data_57C__fzgx_offset_0[];
extern u8 lbl_4_data_59C__fzgx_offset_0[];
extern u8 lbl_4_data_5A0__fzgx_offset_0[];
extern u8 lbl_4_data_5C0__fzgx_offset_0[];
extern u8 lbl_4_data_5D8__fzgx_offset_0[];
extern u8 lbl_4_data_610__fzgx_offset_0[];
extern u8 lbl_4_data_660__fzgx_offset_0[];
extern u8 lbl_4_data_6D4__fzgx_offset_0[];
extern u8 lbl_4_data_724__fzgx_offset_0[];
extern u8 lbl_4_data_78__fzgx_offset_0[];
extern u8 lbl_4_data_790__fzgx_offset_0[];
extern u8 lbl_4_data_7C__fzgx_offset_0[];
extern u8 lbl_4_data_7DC__fzgx_offset_0[];
extern u8 lbl_4_data_85C__fzgx_offset_0[];
extern u8 lbl_4_data_86C__fzgx_offset_0[];
extern u8 lbl_4_data_89C__fzgx_offset_0[];
extern u8 lbl_4_data_8A8__fzgx_offset_0[];
extern u8 lbl_4_data_8D8__fzgx_offset_0[];
extern u8 lbl_4_data_8F8__fzgx_offset_0[];
extern u8 lbl_4_data_918__fzgx_offset_0[];
extern u8 lbl_4_data_934__fzgx_offset_0[];
extern u8 lbl_4_data_970__fzgx_offset_0[];
extern u8 lbl_4_data_984__fzgx_offset_0[];
extern u8 lbl_4_data_9C0__fzgx_offset_0[];
extern u8 lbl_4_data_9D8__fzgx_offset_0[];
extern u8 lbl_4_data_A10__fzgx_offset_0[];
extern u8 lbl_4_data_A30__fzgx_offset_0[];
extern u8 lbl_4_data_A70__fzgx_offset_0[];
extern u8 lbl_4_data_A78__fzgx_offset_0[];
extern u8 lbl_4_data_AA0__fzgx_offset_0[];
extern u8 lbl_4_data_AAC__fzgx_offset_0[];
extern u8 lbl_4_data_AD4__fzgx_offset_0[];
extern u8 lbl_4_data_B0__fzgx_offset_0[];
extern u8 lbl_4_data_B90__fzgx_offset_0[];
extern u8 lbl_4_data_C18__fzgx_offset_0[];
extern u8 lbl_4_data_C8__fzgx_offset_0[];
extern u8 lbl_4_data_CB0__fzgx_offset_0[];
extern u8 lbl_4_data_C__fzgx_offset_0[];
extern u8 lbl_4_data_D50__fzgx_offset_0[];
extern u8 lbl_4_data_D64__fzgx_offset_0[];
extern u8 lbl_4_data_D84__fzgx_offset_0[];
extern u8 lbl_4_data_D98__fzgx_offset_0[];
extern u8 lbl_4_data_DB8__fzgx_offset_0[];
extern u8 lbl_4_data_DF0__fzgx_offset_0[];
extern u8 lbl_4_data_E48__fzgx_offset_0[];
extern u8 lbl_4_data_E58__fzgx_offset_0[];
extern u8 lbl_4_data_E88__fzgx_offset_0[];
extern u8 lbl_4_data_E98__fzgx_offset_0[];
extern u8 lbl_4_data_EC8__fzgx_offset_0[];
extern u8 lbl_4_data_F08__fzgx_offset_0[];
extern u8 lbl_4_data_F64__fzgx_offset_0[];
extern u8 lbl_4_data_FD8__fzgx_offset_0[];
static union { u32 w[58]; u8 v[0xE8]; } fzgx_pool_init_fzgx_obj_lbl_4_data_0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x436F6E74, 0x726F6C6C, 0x65720000, 0x0, 0x83528393, 0x8367838D, 0x815B8389, 0x0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, 0x436F6E74, 0x726F6C6C,
    0x65722053, 0x6F636B65, 0x74000000, 0x83528393, 0x8367838D, 0x815B8389, 0x837C815B, 0x83670000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_38__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_4C__fzgx_offset_0, 0x4F4E0000, 0x4F464600,
    (u32)lbl_4_data_78__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_78__fzgx_offset_0, (u32)lbl_4_data_7C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_7C__fzgx_offset_0, 0x0, 0x55736520, 0x83AD206F, 0x722083B5, 0x20746F20,
    0x63686F6F, 0x73652E00, 0x83AD82A9, 0x83B582C5, 0x8D8096DA, 0x82F09149, 0x82F182C5, 0x82AD82BE,
    0x82B382A2, 0x81420000  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[192]; u32 v[192]; } fzgx_pool_init_tab_E8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_B0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C8__fzgx_offset_0, 0x4D6F7665, 0x2083AD20, 0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063, 0x68616E67, 0x6520636F, 0x6E74726F, 0x6C732E00, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C59180, 0x8DEC82F0, 0x95CF8D58, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_100__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, /* fzgx-allow: A1 retail data bytes */     (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_130__fzgx_offset_0, 0x506C6561, 0x73652077, 0x61697420, 0x61206D6F, 0x6D656E74, 0x2E2E2E00, 0x82B582CE, 0x82E782AD, 0x82A891D2, 0x82BF82AD, 0x82BE82B3, 0x82A28142, 0x0, (u32)lbl_4_data_170__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_188__fzgx_offset_0, 0x50726573, 0x73207468, 0x65204120, 0x42757474, 0x6F6E206F, 0x6E207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0x20746F20, 0x62652061, 0x646A7573, 0x7465642E, 0x20507265, 0x73732074, 0x68652042, 0x20427574, 0x746F6E20, 0x746F2066, 0x696E6973, 0x682E0000, 0x95CF8D58, 0x82B782E9, 0x83528393, 0x8367838D, 0x815B8389, 0x82C5839F, /* fzgx-allow: A1 retail data bytes */     0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_1BC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, /* fzgx-allow: A1 retail data bytes */     (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_210__fzgx_offset_0, 0x526F7461, 0x74652074, 0x68652043, 0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x206F6E65, 0x2066756C, 0x6C207265, 0x766F6C75, 0x74696F6E, 0x2E000000, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E82F0, 0x88EA9474, 0x82C989F1, 0x82B582C4, /* fzgx-allow: A1 retail data bytes */     0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_254__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, /* fzgx-allow: A1 retail data bytes */     (u32)lbl_4_data_284__fzgx_offset_0, 0x506C6561, 0x73652061, 0x646A7573, 0x74207468, 0x65207374, 0x65657269, 0x6E672077, 0x6865656C, 0x2E000000, 0x836E8393, 0x8368838B, 0x82CC92B2, 0x90AE82F0, 0x8D7382C8, 0x82C182C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_2CC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, /* fzgx-allow: A1 retail data bytes */     (u32)lbl_4_data_2F0__fzgx_offset_0, 0x52657475, 0x726E2074, 0x6F207468, 0x65206465, 0x6661756C, 0x74207365, 0x7474696E, 0x67733F00, 0x8F898AFA, 0x90DD92E8, 0x82C996DF, 0x82B582DC, 0x82B782A9, 0x81480000, (u32)lbl_4_data_32C__fzgx_offset_0, /* fzgx-allow: A1 retail data bytes */     (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_34C__fzgx_offset_0, 0x53656C65, 0x63742074, 0x68652043, 0x6F6E7472, 0x6F6C6C65, 0x7220746F, 0x20626520, 0x6368616E, 0x67656420, 0x7573696E, 0x67206569, 0x74686572, 0x2083AD20, 0x6F722083, 0xB52E0000, 0x83AD82A9, 0x83B582C5, 0x95CF8D58, 0x82B782E9, 0x83528393, 0x8367838D, 0x815B8389, 0x82F09149, 0x82F182C5, 0x82AD82BE, 0x82B382A2, 0x81420000}};
static union { u32 w[32]; u32 v[32]; } fzgx_pool_init_tab_3E8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    /* fzgx-allow: A1 retail data bytes */     (u32)lbl_4_data_37C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_3B8__fzgx_offset_0, 0x4D6F7665, 0x2083AD20, 0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063, 0x68616E67, 0x65205275, 0x6D626C65, 0x20736574, 0x74696E67, 0x732E0000, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C59055, 0x93AE82CC, 0x90DD92E8, 0x82F095CF, 0x8D5882B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0x0}};
static union { u32 w[241]; u32 v[241]; } fzgx_pool_init_tab_468 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_400__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_438__fzgx_offset_0, 0x54686520, 0x436F6E74, 0x726F6C6C, 0x65722068, 0x61732062, 0x65656E20, 0x64697363, 0x6F6E6E65, 0x63746564, 0x2E0A2052, 0x65636F6E, 0x6E656374, 0x20746865, 0x20436F6E, 0x74726F6C, 0x6C657220, 0x696E2053, 0x6F636B65, 0x74202564, 0x206F720A, 0x20707265, 0x73732074, 0x68652041, 0x20427574, 0x746F6E20, 0x6F6E2061, 0x6E6F7468, 0x65722E00, 0x83528393, 0x8367838D, 0x815B8389, 0x82AA8A4F, 0x82B382EA, 0x82DC82B5, /* fzgx-allow: A1 retail data bytes */     0x82BD8142, 0xA835283, 0x93836783, 0x8D815B83, 0x89837C81, 0x5B836725, 0x6482C982, 0xB382B582, 0xC882A882, 0xB782A981, 0x410A91BC, 0x82CC8352, 0x83938367, 0x838D815B, 0x838982C5, 0x839F837B, 0x835E8393, 0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_480__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, /* fzgx-allow: A1 retail data bytes */     (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_4F0__fzgx_offset_0, 0x59455300, 0x82CD82A2, 0x0, (u32)lbl_4_data_578__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_57C__fzgx_offset_0, 0x4E4F0000, 0x82A282A2, 0x82A60000, (u32)lbl_4_data_59C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_5A0__fzgx_offset_0, 0x4368616E, 0x6765204F, 0x7074696F, 0x6E205365, 0x7474696E, 0x67730000, 0x83498376, 0x83568387, 0x839390DD, 0x92E882F0, 0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0, (u32)lbl_4_data_5C0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_5D8__fzgx_offset_0, 0x41646A75, 0x73742074, 0x68652043, 0x616C6962, 0x72617469, 0x6F6E2E0A, 0x50726573, 0x73207468, 0x65204120, 0x42757474, 0x6F6E206F, 0x6E207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0xA796F75, 0x2077616E, 0x74206164, 0x6A757374, 0x65642E00, 0x83528393, 0x8367838D, 0x815B8389, 0x82CC834C, 0x8383838A, 0x8375838C, 0x815B8356, 0x83878393, 0x82F08D73, 0x82C882A2, /* fzgx-allow: A1 retail data bytes */     0x82DC82B7, 0x81420A95, 0xCF8D5882, 0xB782E983, 0x52839383, 0x67838D81, 0x5B838982, 0xC5839F82, /* fzgx-allow: A1 retail data bytes */     0xF0899F82, 0xB582C482, 0xAD82BE82, 0xB382A281, 0x42000000, (u32)lbl_4_data_610__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_660__fzgx_offset_0, 0x43757374, 0x6F6D697A, 0x65207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0x2E0A5072, 0x65737320, 0x74686520, 0x41204275, 0x74746F6E, 0x206F6E20, 0x74686520, 0x436F6E74, 0x726F6C6C, 0x65722074, 0x6F206265, 0x2061646A, 0x75737465, 0x642E0000, 0x83528393, 0x8367838D, 0x815B8389, 0x82CC834A, 0x8358835E, 0x837D8343, 0x835982F0, 0x8D7382C8, 0x82A282DC, /* fzgx-allow: A1 retail data bytes */     0x82B78142, 0xA95CF8D, 0x5882B782, 0xE9835283, 0x93836783, 0x8D815B83, 0x8982C583, 0x9F82F089, 0x9F82B582, 0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_6D4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_724__fzgx_offset_0, 0x436F6E74, 0x726F6C6C, 0x65722052, 0x756D626C, 0x65205365, 0x7474696E, 0x67732E0A, 0x20507265, 0x73732074, 0x68652041, 0x20427574, 0x746F6E20, 0x746F2073, 0x656C6563, 0x74207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0x2E000000, 0x83528393, 0x8367838D, 0x815B8389, /* fzgx-allow: A1 retail data bytes */     0x82CC9055, 0x93AE82CC, 0x90DD92E8, 0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420A83, 0x52839383, /* fzgx-allow: A1 retail data bytes */     0x67838D81, 0x5B838982, 0xF0914982, 0xF182C583, 0x9F82F089, 0x9F82B582, 0xC482AD82, 0xBE82B382, 0xA2814200}};
static union { u32 w[6]; u32 v[6]; } fzgx_pool_init_tab_82C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_790__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_7DC__fzgx_offset_0}};
static union { u32 w[16]; u32 v[16]; } fzgx_pool_init_tab_844 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_400__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_438__fzgx_offset_0, 0x53617665, 0x20636861, 0x6E676573, 0x3F000000, 0x95CF8D58, 0x82F095DB, 0x91B682B5, 0x82DC82B7, 0x82A98148, 0x0}};
static union { u32 w[53]; u32 v[53]; } fzgx_pool_init_tab_884 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_85C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_86C__fzgx_offset_0, 0x49732074, 0x68697320, 0x4F4B3F00, 0x82B182EA, 0x82C582E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x81480000, (u32)lbl_4_data_89C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, /* fzgx-allow: A1 retail data bytes */     (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8A8__fzgx_offset_0, 0x8163826E, 0x826D0000, (u32)lbl_4_data_8D8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, /* fzgx-allow: A1 retail data bytes */     (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8D8__fzgx_offset_0, 0x826E8265, 0x82650000, (u32)lbl_4_data_8F8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8F8__fzgx_offset_0, 0x4368616E, 0x67652043, 0x6F6E7472, 0x6F6C6C65, 0x72205365, 0x7474696E, 0x67730000, 0x83528393, 0x8367838D, 0x815B8389, 0x82CC90DD, 0x92E882F0, /* fzgx-allow: A1 retail data bytes */     0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0}};
static union { u32 w[557]; void *v[(0x120C - 0x958) / 4]; } fzgx_pool_init_lbl_4_data_958 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_918__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_934__fzgx_offset_0, 0x4D616E61, 0x6765204D,
    0x656D6F72, 0x79204361, 0x72640000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x8AC7979D,
    0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420000, (u32)lbl_4_data_970__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_984__fzgx_offset_0, 0x53656C65, 0x63742053, 0x63726565, 0x6E205365, 0x7474696E, 0x67732000,
    0x89E696CA, 0x8382815B, 0x836882CC, 0x90DD92E8, 0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_9C0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_9D8__fzgx_offset_0, 0x55736520, 0x83AD206F,
    0x722083B5, 0x20746F20, 0x63686F6F, 0x73652061, 0x206D6F64, 0x65200000, 0x83AD82A9, 0x83B582CC,
    0x8DB68945, 0x82C58382, 0x815B8368, 0x82F09149, 0x82F182C5, 0x82AD82BE, 0x82B382A2, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_A10__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_A30__fzgx_offset_0, 0x4E6F726D, 0x616C0000,
    0x836D815B, 0x837D838B, 0x8365838C, 0x83720000, (u32)lbl_4_data_A70__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_A78__fzgx_offset_0, 0x57696465, 0x20536372, 0x65656E00, 0x838F8343, 0x83688365, 0x838C8372,
    0x0, (u32)lbl_4_data_AA0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_AAC__fzgx_offset_0, 0x4D6F7665,
    0x20746865, 0x20436F6E, 0x74726F6C, 0x20537469, 0x636B2061, 0x726F756E, 0x6420696E, 0x20612063,
    0x6972636C, 0x6520756E, 0x74696C20, 0x74686520, 0x66696775, 0x72657320, 0x6F6E2074, 0x68650A20,
    0x6C656674, 0x20736964, 0x6520646F, 0x206E6F74, 0x20636861, 0x6E67652E, 0x2041646A, 0x75737420,
    0x706C6179, 0x20757369, 0x6E672074, 0x68652083, 0xB520436F, 0x6E74726F, 0x6C205061, 0x642E0A20,
    0x50726573, 0x73207468, 0x65205820, 0x42757474, 0x6F6E2074, 0x6F207265, 0x7475726E, 0x20746F20,
    0x74686520, 0x64656661, 0x756C7420, 0x73657474, 0x696E6773, 0x2E000000, 0x8DB691A4, 0x82CC907D,
    0x8C6082AA, 0x95CF89BB, 0x82B582C8, 0x82AD82C8, 0x82E982DC, 0x82C583AD, 0x82F088EA, 0x947482C9,
    0x89F182B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0xA83B582, 0xC5975682, 0xD182F092, 0xB290AE82,
    0xB582C482, 0xAD82BE82, 0xB382A281, 0x420A83B4, 0x82C58F89, 0x8AFA90DD, 0x92E882C9, 0x96DF82B9,
    0x82DC82B7, 0x81420000, (u32)lbl_4_data_AD4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_B90__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x5475726E, 0x20746865, 0x20737465, 0x6572696E, 0x67207768, 0x65656C20, 0x4C656674, 0x20616E64,
    0x20526967, 0x68742061, 0x6E642070, 0x72657373, 0xA746865, 0x20412042, 0x7574746F, 0x6E206174,
    0x20746865, 0x20706F69, 0x6E742079, 0x6F752077, 0x616E7420, 0x746F2073, 0x65742061, 0x73207468,
    0x650A206C, 0x696D6974, 0x2E205573, 0x65207468, 0x65204C20, 0x616E6420, 0x52204275, 0x74746F6E,
    0x7320746F, 0x2061646A, 0x75737420, 0x67616D65, 0x20706C61, 0x792E2000, 0x836E8393, 0x8368838B,
    0x82F08DB6, 0x894582C9, 0x89F182B5, 0x81418CC0, 0x8A4582C6, 0x82B582BD, 0x82A288CA, 0x927582C5,  /* fzgx-allow: A1 retail data bytes */
    0x839F82F0, 0x899F82B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0xA826B81, 0x95827183, 0x67838A83,
    0x4B815B83, 0x7B835E83, 0x9382C597, 0x5682D182, 0xF092B290, 0xAE82B582, 0xC482AD82, 0xBE82B382,
    0xA281420A, 0x83B482C5, 0x8F898AFA, 0x90DD92E8, 0x82C996DF, 0x82B982DC, 0x82B78142, 0x0,
    (u32)lbl_4_data_C18__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_CB0__fzgx_offset_0, 0x4265666F, 0x72652063,
    0x6F727265, 0x6374696F, 0x6E000000, 0x95E290B3, 0x914F0000, (u32)lbl_4_data_D50__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_D64__fzgx_offset_0, 0x41667465, 0x7220636F, 0x72726563, 0x74696F6E, 0x0,
    0x95E290B3, 0x8CE30000, (u32)lbl_4_data_D84__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_D98__fzgx_offset_0,
    0x47616D65, 0x20446174, 0x6120436F, 0x6E74726F, 0x6C730A49, 0x6E736572, 0x74206120, 0x4D656D6F,
    0x72792043, 0x61726420, 0x696E746F, 0x20536C6F, 0x7420412E, 0x0, 0x8351815B, 0x83808366,
    0x815B835E, 0x82CC9180, 0x8DEC0A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F083, 0x58838D83,  /* fzgx-allow: A1 retail data bytes */
    0x62836782, 0x6082C993, 0xFC82EA82, 0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_DB8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_DF0__fzgx_offset_0, 0x4C6F6164, 0x2047616D, 0x65204461, 0x74610000,
    0x8351815B, 0x83808366, 0x815B835E, 0x82CC838D, 0x815B8368, 0x0, (u32)lbl_4_data_E48__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_E58__fzgx_offset_0, 0x53617665, 0x2047616D, 0x65204461, 0x74610000,
    0x8351815B, 0x83808366, 0x815B835E, 0x82CC835A, 0x815B8375, 0x0, (u32)lbl_4_data_E88__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_E98__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20, 0x47616D65,
    0x20446174, 0x61206F6E, 0x20746869, 0x73204D65, 0x6D6F7279, 0x20436172, 0x642E0A20, 0x53617669,
    0x6E67206E, 0x65772064, 0x6174612E, 0x0, 0x83818382, 0x838A815B, 0x834A815B, 0x836882C9,
    0xA835181, 0x5B838083, 0x66815B83, 0x5E82AA8C, 0xA982C282, 0xA982E882, 0xDC82B982, 0xF181420A,
    0x90568B4B, 0x835A815B, 0x837582B5, 0x82DC82B7, 0x81420000, (u32)lbl_4_data_EC8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_F08__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20, 0x47616D65, 0x20446174,
    0x61206F6E, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x2E0A4966, 0x20796F75, 0x20736176,
    0x652C2074, 0x68652047, 0x616D6520, 0x44617461, 0x20637572, 0x72656E74, 0x6C79206C, 0x6F616465,
    0x640A7769, 0x6C6C2061, 0x6C6C2062, 0x65206C6F, 0x73742E20, 0x49732074, 0x68617420, 0x4F4B3F00,
    0x83818382, 0x838A815B, 0x834A815B, 0x836882C9, 0x8351815B, 0x83808366, 0x815B835E, 0x82AA8CA9,  /* fzgx-allow: A1 retail data bytes */
    0x82C282A9, 0x82E882DC, 0x82B982F1, 0x81420A90, 0x568B4B83, 0x5A815B83, 0x7582B782, 0xE982C68C,  /* fzgx-allow: A1 retail data bytes */
    0xBB8DDD83, 0x8D815B83, 0x6882B382, 0xEA82C482, 0xA282E983, 0x51815B83, 0x80836681, 0x5B835E82,  /* fzgx-allow: A1 retail data bytes */
    0xAA0A9153, 0x82C48FC1, 0x82A682C4, 0x82B582DC, 0x82A282DC, 0x82B782AA, 0x814182E6, 0x82EB82B5,  /* fzgx-allow: A1 retail data bytes */
    0x82A282C5, 0x82B782A9, 0x3F000000, (u32)lbl_4_data_F64__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_FD8__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053,
    0x6C6F7420, 0x412E0000, 0x8358838D, 0x83628367, 0x826082C9, 0xA838183, 0x82838A81, 0x5B834A81,
    0x5B836882, 0xAA8CA982, 0xC282A982, 0xE882DC82, 0xB982F181, 0x42000000, (u32)lbl_4_data_107C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10A0__fzgx_offset_0, 0x52656769, 0x73746572, 0x20746869, 0x73206E61,
    0x6D65206F, 0x6E207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20536C6F, 0x7420412E,
    0x0, 0x82B182CC, 0x96BC914F, 0x82C58381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C90A93,  /* fzgx-allow: A1 retail data bytes */
    0x6F985E82, 0xB582C482, 0xE082E682, 0xEB82B582, 0xA282C582, 0xB782A93F, 0x0, (u32)lbl_4_data_10E8__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_111C__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20,
    0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x6C6F7420, 0x412E0A20, 0x54686520, 0x67616D65,
    0x2063616E, 0x6E6F7420, 0x62652073, 0x61766564, 0x2E000000, 0x8358838D, 0x83628367, 0x826082C9,
    0x83818382, 0x838A815B, 0x834A815B, 0x836882AA, 0x8CA982C2, 0x82A982E8, 0x82DC82B9, 0x82F18142,
    0xA835A81, 0x5B837582, 0xC582AB82, 0xDC82B982, 0xF182C582, 0xB582BD81, 0x42000000, (u32)lbl_4_data_116C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_11AC__fzgx_offset_0
}};
u8 lbl_4_data_11AC__fzgx_offset_60 = 0xFF;
s16 lbl_4_data_11AC__fzgx_offset_62 = -1;
static union { u32 w[1682]; char v[0x2C58 - 0x1210]; } fzgx_pool_init_lbl_4_data_1210 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x257300FF, 0xFFFF0000, 0x6F707469, 0x6F6E2E63, 0x0, 0x53656C53, 0x5F446973, 0x70506F6C,
    0x79676F6E, 0x42470000, 0x53656C53, 0x5F446973, 0x70537072, 0x69746542, 0x47000000, 0x6F707469,
    0x6F6E5F63, 0x6F6D6D6F, 0x6E5F6469, 0x73700000, 0x534D445F, 0x4F505449, 0x4F4E5F4D, 0x454E5500,
    0x0, 0x0, 0x0, 0x0, (u32)fn_4_D10__fzgx_offset_0, (u32)fn_4_D7C__fzgx_offset_0, (u32)fn_4_EA0__fzgx_offset_0, 0x534D445F,
    0x4F505449, 0x4F4E5F53, 0x4156455F, 0x57414954, 0x0, 0x0, 0x0, (u32)fn_4_9B20__fzgx_offset_0,
    (u32)fn_4_9C14__fzgx_offset_0, (u32)fn_4_A734__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43, 0x54524C5F, 0x4D454E55, 0x0,
    0x0, 0x0, (u32)fn_4_7C38__fzgx_offset_0, (u32)fn_4_7CA4__fzgx_offset_0, (u32)fn_4_7D94__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43,
    0x4152445F, 0x4D454E55, 0x0, 0x0, 0x0, (u32)fn_4_80EC__fzgx_offset_0, (u32)fn_4_8158__fzgx_offset_0, (u32)fn_4_8248__fzgx_offset_0,
    0x534D445F, 0x4F505449, 0x4F4E5F57, 0x49444500, 0x0, 0x0, 0x0, 0x0,
    (u32)fn_4_869C__fzgx_offset_0, (u32)fn_4_8720__fzgx_offset_0, (u32)fn_4_898C__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43, 0x414C4942, 0x0,
    0x0, 0x0, 0x0, (u32)fn_4_347C__fzgx_offset_0, (u32)fn_4_3568__fzgx_offset_0, (u32)fn_4_406C__fzgx_offset_0, 0x534D445F, 0x4F505449,
    0x4F4E5F52, 0x554D424C, 0x45000000, 0x0, 0x0, 0x0, (u32)fn_4_4784__fzgx_offset_0, (u32)fn_4_4834__fzgx_offset_0,
    (u32)fn_4_4B10__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F50, 0x43555354, 0x0, 0x0, 0x0,
    0x0, (u32)fn_4_6678__fzgx_offset_0, (u32)fn_4_6720__fzgx_offset_0, (u32)fn_4_78E0__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43, 0x4152445F,
    0x4D414E41, 0x47450000, 0x0, 0x0, (u32)fn_4_89E4__fzgx_offset_0, (u32)fn_4_8A54__fzgx_offset_0, (u32)fn_4_8AE0__fzgx_offset_0, 0x534D445F,
    0x4F505449, 0x4F4E5F43, 0x4152445F, 0x47444154, 0x41000000, 0x0, 0x0, (u32)fn_4_8DC0__fzgx_offset_0,
    (u32)fn_4_8E38__fzgx_offset_0, (u32)fn_4_9A78__fzgx_offset_0, 0x4D656D6F, 0x72792043, 0x61726400, 0x83818382, 0x838A815B, 0x834A815B,
    0x83680000, 0x53637265, 0x656E204D, 0x6F646500, 0x89E696CA, 0x8382815B, 0x83680000, 0x4D0000,
    (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, 0x4E0000, (u32)lbl_4_data_1418__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1424__fzgx_offset_0, 0x4F0000, (u32)lbl_4_data_1434__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1440__fzgx_offset_0, 0x6F707469, 0x6F6E5F6D, 0x656E755F, 0x64697370,
    0x0, 0x583A2534, 0x640A0000, 0x593A2534, 0x64000000, 0x25732534, 0x64000000, 0x25346400,
    0x6F707469, 0x6F6E5F63, 0x616C6962, 0x5F646973, 0x7000FF00, 0xFFFF0000, 0x25732564, 0x81632020,  /* fzgx-allow: A1 retail data bytes */
    0x20000000, 0x25732564, 0x81632573, 0x0, 0x52756D62, 0x6C654D61, 0x696E0000, 0x6F707469,  /* fzgx-allow: A1 retail data bytes */
    0x6F6E5F72, 0x756D626C, 0x655F6469, 0x73700000, 0x81FF811F, 0x831F0000, 0x803FFF1F, 0x80303F1F,  /* fzgx-allow: A1 retail data bytes */
    0x80F03F1F, 0x4E6F7420, 0x436F6E6E, 0x65637465, 0x64000000, 0x96A290DA, 0x91B10000, 0x53706565,  /* fzgx-allow: A1 retail data bytes */
    0x6420466F, 0x72636500, 0x83588373, 0x815B8368, 0x83748348, 0x815B8358, 0x0, 0x53706565,  /* fzgx-allow: A1 retail data bytes */
    0x6420466F, 0x72636520, 0x616E6420, 0x50656461, 0x6C20556E, 0x69740000, 0x83588373, 0x815B8368,  /* fzgx-allow: A1 retail data bytes */
    0x83748348, 0x815B8358, 0x81958379, 0x835F838B, 0x8386836A, 0x83628367, 0x0, 0x41726361,  /* fzgx-allow: A1 retail data bytes */
    0x64650000, 0x8341815B, 0x8350815B, 0x83688341, 0x815B8350, 0x815B8368, 0x8341815B, 0x8350815B,  /* fzgx-allow: A1 retail data bytes */
    0x83688341, 0x815B8350, 0x815B8368, 0x8341815B, 0x8350815B, 0x83680000, (u32)lbl_4_data_1534__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0,
    (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_154C__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0,
    (u32)lbl_4_data_156C__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_15AC__fzgx_offset_0, (u32)lbl_4_data_15B4__fzgx_offset_0,
    0x0, 0x0, 0x0, 0x0, 0x81638163, 0x81638163, 0x81638163, 0x81638163,  /* fzgx-allow: A1 retail data bytes */
    0x81638163, 0x81630000, 0x81638163, 0x81638163, 0x81638163, 0x0, 0x81630000, 0x81638163,  /* fzgx-allow: A1 retail data bytes */
    0x81638163, 0x81638163, 0x81638163, 0x0, 0x81638163, 0x81638163, 0x81638163, 0x81638163,  /* fzgx-allow: A1 retail data bytes */
    0x81630000, 0xA400A0, (u32)lbl_4_data_1660__fzgx_offset_0, 0xF800B4, (u32)lbl_4_data_1678__fzgx_offset_0, 0x14C00C8, (u32)lbl_4_data_1688__fzgx_offset_0, 0xD600DC,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_168C__fzgx_offset_0, 0xD600F0, (u32)lbl_4_data_168C__fzgx_offset_0, 0xC60104, (u32)lbl_4_data_16A0__fzgx_offset_0, 0xD60118, (u32)lbl_4_data_168C__fzgx_offset_0, 0xD6012C,
    (u32)lbl_4_data_168C__fzgx_offset_0, 0xA40140, (u32)lbl_4_data_1660__fzgx_offset_0, 0x53746565, 0x72000000, 0x83588365, 0x8341838A, 0x8393834F,
    0x8DB68945, 0x81630000, 0x536C6964, 0x65204C65, 0x66742052, 0x69676874, 0x0, 0x83588389,  /* fzgx-allow: A1 retail data bytes */
    0x83438368, 0x8DB68945, 0x81638163, 0x81630000, 0x41646A75, 0x73742043, 0x656E7465, 0x72206F66,  /* fzgx-allow: A1 retail data bytes */
    0x20477261, 0x76697479, 0x0, 0x83578383, 0x83938376, 0x8F649053, 0x88DA93AE, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x41646A75, 0x73742056, 0x69657700, 0x8E8B935F, 0x95CF8D58, 0x81638163, 0x81638163, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x41636365, 0x6C657261, 0x74650000, 0x8341834E, 0x835A838B, 0x81638163, 0x81638163, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x41697220, 0x4272616B, 0x65000000, 0x83478341, 0x8375838C, 0x815B834C, 0x81638163, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x53696465, 0x20417474, 0x61636B00, 0x83548343, 0x83688341, 0x835E8362, 0x834E8163, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x5370696E, 0x20417474, 0x61636B00, 0x83588373, 0x83938341, 0x835E8362, 0x834E8163, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x426F6F73, 0x74000000, 0x8375815B, 0x8358835E, 0x815B8163, 0x81638163, 0x81630000, (u32)lbl_4_data_16FC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1704__fzgx_offset_0, (u32)lbl_4_data_1718__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_172C__fzgx_offset_0, (u32)lbl_4_data_1740__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_175C__fzgx_offset_0, (u32)lbl_4_data_1770__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_177C__fzgx_offset_0, (u32)lbl_4_data_1790__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_179C__fzgx_offset_0, (u32)lbl_4_data_17B0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_17BC__fzgx_offset_0, (u32)lbl_4_data_17D0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_17DC__fzgx_offset_0, (u32)lbl_4_data_17F0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_17FC__fzgx_offset_0, (u32)lbl_4_data_1810__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1818__fzgx_offset_0, 0x83B52043, 0x6F6E7472, 0x6F6C2050,
    0x6164204C, 0x65667420, 0x616E6420, 0x52696768, 0x74000000, 0x83B52083, 0xD0000000, 0x8F5C8E9A,
    0x837B835E, 0x83938DB6, 0x89450000, 0x83B52043, 0x6F6E7472, 0x6F6C2050, 0x61642055, 0x7020616E,
    0x6420446F, 0x776E0000, 0x83B52083, 0xCF000000, 0x8F5C8E9A, 0x837B835E, 0x83938FE3, 0x89BA0000,
    0x4120616E, 0x64204220, 0x42757474, 0x6F6E0000, 0x839F2083, 0xA0000000, 0x82608195, 0x8261837B,
    0x835E8393, 0x0, 0x5820616E, 0x64205920, 0x42757474, 0x6F6E0000, 0x83B42083, 0xB2000000,
    0x82778195, 0x8278837B, 0x835E8393, 0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053, 0x7469636B,
    0x204C6566, 0x7420616E, 0x64205269, 0x67687400, 0x83AD2083, 0xD0000000, 0x83528393, 0x8367838D,
    0x815B838B, 0x83588365, 0x83428362, 0x834E8DB6, 0x89450000, 0x83AD2043, 0x6F6E7472, 0x6F6C2053,  /* fzgx-allow: A1 retail data bytes */
    0x7469636B, 0x20557020, 0x616E6420, 0x446F776E, 0x0, 0x83AD2083, 0xCF000000, 0x83528393,
    0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E8FE3, 0x89BA0000, 0x83A62043, 0x20537469,  /* fzgx-allow: A1 retail data bytes */
    0x636B204C, 0x65667420, 0x616E6420, 0x52696768, 0x74000000, 0x83A62083, 0xD0000000, 0x82628358,
    0x83658342, 0x8362834E, 0x8DB68945, 0x0, 0x83A62043, 0x20537469, 0x636B2055, 0x7020616E,
    0x6420446F, 0x776E0000, 0x83A62083, 0xCF000000, 0x82628358, 0x83658342, 0x8362834E, 0x8FE389BA,
    0x0, 0x4C20616E, 0x64205220, 0x42757474, 0x6F6E0000, 0x826B8195, 0x82718367, 0x838A834B,
    0x815B837B, 0x835E8393, 0x0, 0x4E6F2051, 0x756F7461, 0x73000000, 0x8A8482E8, 0x939682C4,  /* fzgx-allow: A1 retail data bytes */
    0x82C882B5, 0x0, (u32)lbl_4_data_1904__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_192C__fzgx_offset_0,
    (u32)lbl_4_data_193C__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1960__fzgx_offset_0, (u32)lbl_4_data_1970__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0,
    (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1988__fzgx_offset_0, (u32)lbl_4_data_1998__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0,
    (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19B0__fzgx_offset_0, (u32)lbl_4_data_19C0__fzgx_offset_0, (u32)lbl_4_data_19E0__fzgx_offset_0, (u32)lbl_4_data_19E0__fzgx_offset_0, (u32)lbl_4_data_19E0__fzgx_offset_0, (u32)lbl_4_data_19E0__fzgx_offset_0, (u32)lbl_4_data_19E8__fzgx_offset_0,
    (u32)lbl_4_data_1A04__fzgx_offset_0, (u32)lbl_4_data_1A24__fzgx_offset_0, (u32)lbl_4_data_1A24__fzgx_offset_0, (u32)lbl_4_data_1A24__fzgx_offset_0, (u32)lbl_4_data_1A24__fzgx_offset_0, (u32)lbl_4_data_1A2C__fzgx_offset_0, (u32)lbl_4_data_1A48__fzgx_offset_0, (u32)lbl_4_data_1A64__fzgx_offset_0,
    (u32)lbl_4_data_1A64__fzgx_offset_0, (u32)lbl_4_data_1A64__fzgx_offset_0, (u32)lbl_4_data_1A64__fzgx_offset_0, (u32)lbl_4_data_1A6C__fzgx_offset_0, (u32)lbl_4_data_1A80__fzgx_offset_0, (u32)lbl_4_data_1A98__fzgx_offset_0, (u32)lbl_4_data_1A98__fzgx_offset_0, (u32)lbl_4_data_1A98__fzgx_offset_0,
    (u32)lbl_4_data_1A98__fzgx_offset_0, (u32)lbl_4_data_1AA0__fzgx_offset_0, (u32)lbl_4_data_1AB4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AC4__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1ADC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AE8__fzgx_offset_0, 0x53746565, 0x72696E67, 0x20576865, 0x656C204C, 0x65667420, 0x616E6420,
    0x52696768, 0x74000000, 0x836E8393, 0x8368838B, 0x8DB68945, 0x0, 0x41636365, 0x6C657261,
    0x746F7220, 0x616E6420, 0x42726561, 0x6B205065, 0x64616C00, 0x8341834E, 0x835A838B, 0x81958375,
    0x838C815B, 0x834C8379, 0x835F838B, 0x0, (u32)lbl_4_data_1904__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0,
    (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_192C__fzgx_offset_0, (u32)lbl_4_data_193C__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1960__fzgx_offset_0,
    (u32)lbl_4_data_1970__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1988__fzgx_offset_0, (u32)lbl_4_data_1998__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0,
    (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19B0__fzgx_offset_0, (u32)lbl_4_data_1C78__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1C98__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AB4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AC4__fzgx_offset_0, (u32)lbl_4_data_1CA8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1CC4__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1ADC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AE8__fzgx_offset_0, 0x83B52043, 0x6F6E7472, 0x6F6C2050, 0x6164204C,
    0x65667400, 0x83B5204C, 0x65667400, 0x8F5C8E9A, 0x837B835E, 0x83938DB6, 0x0, 0x83B52043,
    0x6F6E7472, 0x6F6C2050, 0x61642052, 0x69676874, 0x0, 0x83B52052, 0x69676874, 0x0,
    0x8F5C8E9A, 0x837B835E, 0x83938945, 0x0, 0x83B52043, 0x6F6E7472, 0x6F6C2050, 0x61642044,
    0x6F776E00, 0x83B52044, 0x6F776E00, 0x8F5C8E9A, 0x837B835E, 0x839389BA, 0x0, 0x83B52043,
    0x6F6E7472, 0x6F6C2050, 0x61642055, 0x70000000, 0x83B52055, 0x70000000, 0x8F5C8E9A, 0x837B835E,
    0x83938FE3, 0x0, 0x5A204275, 0x74746F6E, 0x0, 0x83A42000, 0x8279837B, 0x835E8393,
    0x0, 0x41204275, 0x74746F6E, 0x0, 0x839F0000, 0x8260837B, 0x835E8393, 0x0,
    0x42204275, 0x74746F6E, 0x0, 0x83A02000, 0x8261837B, 0x835E8393, 0x0, 0x58204275,
    0x74746F6E, 0x0, 0x83B42000, 0x8277837B, 0x835E8393, 0x0, 0x59204275, 0x74746F6E,
    0x0, 0x83B22000, 0x8278837B, 0x835E8393, 0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053,
    0x7469636B, 0x204C6566, 0x74000000, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362,  /* fzgx-allow: A1 retail data bytes */
    0x834E8DB6, 0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x20526967, 0x68740000,
    0x83AD2052, 0x69676874, 0x0, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362,  /* fzgx-allow: A1 retail data bytes */
    0x834E8945, 0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x20446F77, 0x6E000000,
    0x83AD2044, 0x6F776E00, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E89BA,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x20557000, 0x83AD2055, 0x70000000,
    0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E8FE3, 0x0, 0x83A62043,  /* fzgx-allow: A1 retail data bytes */
    0x20537469, 0x636B204C, 0x65667400, 0x83AD204C, 0x65667400, 0x82628358, 0x83658342, 0x8362834E,
    0x8DB60000, 0x83A62043, 0x20537469, 0x636B2052, 0x69676874, 0x0, 0x83A62052, 0x69676874,
    0x0, 0x82628358, 0x83658342, 0x8362834E, 0x89450000, 0x83A62043, 0x20537469, 0x636B2044,
    0x6F776E00, 0x83A62044, 0x6F776E00, 0x82628358, 0x83658342, 0x8362834E, 0x89BA0000, 0x83A62043,
    0x20537469, 0x636B2055, 0x70000000, 0x83A62055, 0x70000000, 0x82628358, 0x83658342, 0x8362834E,
    0x8FE30000, 0x4C204275, 0x74746F6E, 0x0, 0x83A12000, 0x826B8367, 0x838A834B, 0x815B837B,  /* fzgx-allow: A1 retail data bytes */
    0x835E8393, 0x0, 0x52204275, 0x74746F6E, 0x0, 0x2083AF20, 0x0, 0x82718367,
    0x838A834B, 0x815B837B, 0x835E8393, 0x0, (u32)lbl_4_data_1E60__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E7C__fzgx_offset_0, (u32)lbl_4_data_1E8C__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EB0__fzgx_offset_0,
    (u32)lbl_4_data_1EC0__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1EDC__fzgx_offset_0, (u32)lbl_4_data_1EEC__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0,
    (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F08__fzgx_offset_0, (u32)lbl_4_data_1F18__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0,
    (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F28__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1F34__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0,
    (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F44__fzgx_offset_0, (u32)lbl_4_data_1F50__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F60__fzgx_offset_0,
    (u32)lbl_4_data_1F6C__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F7C__fzgx_offset_0, (u32)lbl_4_data_1F88__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0,
    (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F98__fzgx_offset_0, (u32)lbl_4_data_1FA4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1FBC__fzgx_offset_0, (u32)lbl_4_data_1FD8__fzgx_offset_0, (u32)lbl_4_data_1FF0__fzgx_offset_0, (u32)lbl_4_data_1FF0__fzgx_offset_0, (u32)lbl_4_data_1FF0__fzgx_offset_0, (u32)lbl_4_data_1FF0__fzgx_offset_0, (u32)lbl_4_data_1FFC__fzgx_offset_0,
    (u32)lbl_4_data_2018__fzgx_offset_0, (u32)lbl_4_data_2030__fzgx_offset_0, (u32)lbl_4_data_2030__fzgx_offset_0, (u32)lbl_4_data_2030__fzgx_offset_0, (u32)lbl_4_data_2030__fzgx_offset_0, (u32)lbl_4_data_2038__fzgx_offset_0, (u32)lbl_4_data_2054__fzgx_offset_0, (u32)lbl_4_data_2068__fzgx_offset_0,
    (u32)lbl_4_data_2068__fzgx_offset_0, (u32)lbl_4_data_2068__fzgx_offset_0, (u32)lbl_4_data_2068__fzgx_offset_0, (u32)lbl_4_data_2070__fzgx_offset_0, (u32)lbl_4_data_208C__fzgx_offset_0, (u32)lbl_4_data_209C__fzgx_offset_0, (u32)lbl_4_data_209C__fzgx_offset_0, (u32)lbl_4_data_209C__fzgx_offset_0,
    (u32)lbl_4_data_209C__fzgx_offset_0, (u32)lbl_4_data_20A4__fzgx_offset_0, (u32)lbl_4_data_20B4__fzgx_offset_0, (u32)lbl_4_data_20C8__fzgx_offset_0, (u32)lbl_4_data_20C8__fzgx_offset_0, (u32)lbl_4_data_20C8__fzgx_offset_0, (u32)lbl_4_data_20C8__fzgx_offset_0, (u32)lbl_4_data_20D4__fzgx_offset_0,
    (u32)lbl_4_data_20E4__fzgx_offset_0, (u32)lbl_4_data_20F4__fzgx_offset_0, (u32)lbl_4_data_20F4__fzgx_offset_0, (u32)lbl_4_data_20F4__fzgx_offset_0, (u32)lbl_4_data_20F4__fzgx_offset_0, (u32)lbl_4_data_20FC__fzgx_offset_0, (u32)lbl_4_data_210C__fzgx_offset_0, (u32)lbl_4_data_211C__fzgx_offset_0,
    (u32)lbl_4_data_211C__fzgx_offset_0, (u32)lbl_4_data_211C__fzgx_offset_0, (u32)lbl_4_data_211C__fzgx_offset_0, (u32)lbl_4_data_2124__fzgx_offset_0, (u32)lbl_4_data_2134__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0,
    (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2144__fzgx_offset_0, (u32)lbl_4_data_2158__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_216C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1ADC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AE8__fzgx_offset_0, 0x53746565, 0x72696E67, 0x20576865, 0x656C204C,
    0x65667400, 0x836E8393, 0x8368838B, 0x8DB60000, 0x53746565, 0x72696E67, 0x20576865, 0x656C2052,
    0x69676874, 0x0, 0x836E8393, 0x8368838B, 0x89450000, 0x41636365, 0x6C657261, 0x746F7220,
    0x50656461, 0x6C000000, 0x8341834E, 0x835A838B, 0x8379835F, 0x838B0000, 0x4272616B, 0x65205065,
    0x64616C00, 0x8375838C, 0x815B834C, 0x8379835F, 0x838B0000, (u32)lbl_4_data_1E60__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E7C__fzgx_offset_0, (u32)lbl_4_data_1E8C__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0,
    (u32)lbl_4_data_1EB0__fzgx_offset_0, (u32)lbl_4_data_1EC0__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1EDC__fzgx_offset_0, (u32)lbl_4_data_1EEC__fzgx_offset_0,
    (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F08__fzgx_offset_0, (u32)lbl_4_data_1F18__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0,
    (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F28__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1F34__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0,
    (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F44__fzgx_offset_0, (u32)lbl_4_data_1F50__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0,
    (u32)lbl_4_data_1F60__fzgx_offset_0, (u32)lbl_4_data_1F6C__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F7C__fzgx_offset_0, (u32)lbl_4_data_1F88__fzgx_offset_0,
    (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F98__fzgx_offset_0, (u32)lbl_4_data_2480__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2494__fzgx_offset_0, (u32)lbl_4_data_24A0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_24B8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2134__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0,
    (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2144__fzgx_offset_0, (u32)lbl_4_data_2158__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0,
    (u32)lbl_4_data_216C__fzgx_offset_0, (u32)lbl_4_data_24C4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_24D8__fzgx_offset_0, (u32)lbl_4_data_24E8__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_24F4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1ADC__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AE8__fzgx_offset_0, 0x41582043, 0x6F6E7472, 0x6F6C7300,
    0x82608277, 0x82CC9180, 0x8DEC0000, (u32)lbl_4_data_2804__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_2810__fzgx_offset_0, 0x44656661, 0x756C7420, 0x53657474, 0x696E6773, 0x0, 0x8F898AFA, 0x90DD92E8,
    0x82C996DF, 0x82B70000, (u32)lbl_4_data_2834__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2848__fzgx_offset_0,
    0x53696465, 0x20417474, 0x61636B3A, 0x51756963, 0x6B6C7920, 0x70726573, 0x73207468, 0x65204C20,
    0x6F722052, 0x20427574, 0x746F6E0A, 0x20202020, 0x20202020, 0x20202020, 0x20202074, 0x77696365,
    0x2E0A5370, 0x696E2041, 0x74746163, 0x6B3A5072, 0x65737320, 0x74686520, 0x4C20616E, 0x64205220,
    0x42757474, 0x6F6E730A, 0x20202020, 0x20202020, 0x20202020, 0x20202073, 0x696D756C, 0x74616E65,
    0x6F75736C, 0x7920616E, 0x64207475, 0x726E2074, 0x68652077, 0x6865656C, 0x2E200000, 0x83548343,
    0x83688341, 0x835E8362, 0x834E8163, 0x8367838A, 0x834B815B, 0x825189F1, 0x88F882AB, 0xA835883,
    0x73839383, 0x41835E83, 0x62834E81, 0x63836783, 0x8A834B81, 0x5B826B82, 0x7197BC88, 0xF882AB81,
    0x95836E83, 0x93836883, 0x8B000000, (u32)lbl_4_data_2870__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_290C__fzgx_offset_0, (u32)fn_4_4B74__fzgx_offset_68, (u32)fn_4_4B74__fzgx_offset_7C, (u32)fn_4_4B74__fzgx_offset_94, (u32)fn_4_4B74__fzgx_offset_AC, (u32)fn_4_4B74__fzgx_offset_C4, (u32)fn_4_4B74__fzgx_offset_DC, (u32)fn_4_4B74__fzgx_offset_F4,
    (u32)fn_4_4B74__fzgx_offset_10C, (u32)fn_4_4B74__fzgx_offset_124, (u32)fn_4_4CB8__fzgx_offset_6C, (u32)fn_4_4CB8__fzgx_offset_80, (u32)fn_4_4CB8__fzgx_offset_98, (u32)fn_4_4CB8__fzgx_offset_B0, (u32)fn_4_4CB8__fzgx_offset_C8, (u32)fn_4_4CB8__fzgx_offset_E0,
    (u32)fn_4_4CB8__fzgx_offset_F8, (u32)fn_4_4CB8__fzgx_offset_110, (u32)fn_4_4CB8__fzgx_offset_128, 0x25732573, 0xA000000, 0x25730A00, 0x25738163, 0x25730000,
    (u32)fn_4_4DF8__fzgx_offset_1428, (u32)fn_4_4DF8__fzgx_offset_1408, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454,
    (u32)fn_4_4DF8__fzgx_offset_1308, (u32)fn_4_4DF8__fzgx_offset_12E4, (u32)fn_4_4DF8__fzgx_offset_13E0, (u32)fn_4_4DF8__fzgx_offset_13C0, (u32)fn_4_4DF8__fzgx_offset_1398, (u32)fn_4_4DF8__fzgx_offset_1378, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454,
    (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1350, (u32)fn_4_4DF8__fzgx_offset_1330, (u32)fn_4_4DF8__fzgx_offset_1330, (u32)fn_4_4DF8__fzgx_offset_1330, (u32)fn_4_4DF8__fzgx_offset_1330, (u32)fn_4_4DF8__fzgx_offset_E54, (u32)fn_4_4DF8__fzgx_offset_E34,
    (u32)fn_4_4DF8__fzgx_offset_E14, (u32)fn_4_4DF8__fzgx_offset_E14, (u32)fn_4_4DF8__fzgx_offset_E14, (u32)fn_4_4DF8__fzgx_offset_E14, (u32)fn_4_4DF8__fzgx_offset_DF4, (u32)fn_4_4DF8__fzgx_offset_DF4, (u32)fn_4_4DF8__fzgx_offset_DF4, (u32)fn_4_4DF8__fzgx_offset_DF4,
    (u32)fn_4_4DF8__fzgx_offset_DD4, (u32)fn_4_4DF8__fzgx_offset_DB4, (u32)fn_4_4DF8__fzgx_offset_D8C, (u32)fn_4_4DF8__fzgx_offset_D6C, (u32)fn_4_4DF8__fzgx_offset_E80, (u32)fn_4_4DF8__fzgx_offset_E80, (u32)fn_4_4DF8__fzgx_offset_E80, (u32)fn_4_4DF8__fzgx_offset_D4C,
    (u32)fn_4_4DF8__fzgx_offset_D2C, (u32)fn_4_4DF8__fzgx_offset_D2C, (u32)fn_4_4DF8__fzgx_offset_D2C, (u32)fn_4_4DF8__fzgx_offset_D2C, (u32)fn_4_4DF8__fzgx_offset_930, (u32)fn_4_4DF8__fzgx_offset_940, (u32)fn_4_4DF8__fzgx_offset_954, (u32)fn_4_4DF8__fzgx_offset_968,
    (u32)fn_4_4DF8__fzgx_offset_97C, (u32)fn_4_4DF8__fzgx_offset_990, (u32)fn_4_4DF8__fzgx_offset_9A4, (u32)fn_4_4DF8__fzgx_offset_9B8, (u32)fn_4_4DF8__fzgx_offset_9CC, (u32)fn_4_4DF8__fzgx_offset_3E4, (u32)fn_4_4DF8__fzgx_offset_3F4, (u32)fn_4_4DF8__fzgx_offset_408,
    (u32)fn_4_4DF8__fzgx_offset_41C, (u32)fn_4_4DF8__fzgx_offset_430, (u32)fn_4_4DF8__fzgx_offset_444, (u32)fn_4_4DF8__fzgx_offset_458, (u32)fn_4_4DF8__fzgx_offset_46C, (u32)fn_4_4DF8__fzgx_offset_480, (u32)fn_4_63D4__fzgx_offset_94, (u32)fn_4_63D4__fzgx_offset_F8,
    (u32)fn_4_63D4__fzgx_offset_150, (u32)fn_4_63D4__fzgx_offset_170, (u32)fn_4_63D4__fzgx_offset_170, (u32)fn_4_63D4__fzgx_offset_190, (u32)fn_4_63D4__fzgx_offset_1C0, (u32)fn_4_63D4__fzgx_offset_1F0, 0x6F707469, 0x6F6E5F70,
    0x63757374, 0x5F646973, 0x70000000, (u32)fn_4_6720__fzgx_offset_C94, (u32)fn_4_6720__fzgx_offset_CA4, (u32)fn_4_6720__fzgx_offset_CB8, (u32)fn_4_6720__fzgx_offset_CCC, (u32)fn_4_6720__fzgx_offset_CE0,
    (u32)fn_4_6720__fzgx_offset_CF4, (u32)fn_4_6720__fzgx_offset_D08, (u32)fn_4_6720__fzgx_offset_D1C, (u32)fn_4_6720__fzgx_offset_D30, (u32)fn_4_6720__fzgx_offset_B48, (u32)fn_4_6720__fzgx_offset_B58, (u32)fn_4_6720__fzgx_offset_B6C, (u32)fn_4_6720__fzgx_offset_B80,
    (u32)fn_4_6720__fzgx_offset_B94, (u32)fn_4_6720__fzgx_offset_BA8, (u32)fn_4_6720__fzgx_offset_BBC, (u32)fn_4_6720__fzgx_offset_BD0, (u32)fn_4_6720__fzgx_offset_BE4, (u32)fn_4_6720__fzgx_offset_93C, (u32)fn_4_6720__fzgx_offset_94C, (u32)fn_4_6720__fzgx_offset_960,
    (u32)fn_4_6720__fzgx_offset_974, (u32)fn_4_6720__fzgx_offset_988, (u32)fn_4_6720__fzgx_offset_99C, (u32)fn_4_6720__fzgx_offset_9B0, (u32)fn_4_6720__fzgx_offset_9C4, (u32)fn_4_6720__fzgx_offset_9D8, (u32)fn_4_6720__fzgx_offset_710, (u32)fn_4_6720__fzgx_offset_720,
    (u32)fn_4_6720__fzgx_offset_734, (u32)fn_4_6720__fzgx_offset_748, (u32)fn_4_6720__fzgx_offset_75C, (u32)fn_4_6720__fzgx_offset_770, (u32)fn_4_6720__fzgx_offset_784, (u32)fn_4_6720__fzgx_offset_798, (u32)fn_4_6720__fzgx_offset_7AC, (u32)fn_4_6720__fzgx_offset_5E4,
    (u32)fn_4_6720__fzgx_offset_5F4, (u32)fn_4_6720__fzgx_offset_608, (u32)fn_4_6720__fzgx_offset_61C, (u32)fn_4_6720__fzgx_offset_630, (u32)fn_4_6720__fzgx_offset_644, (u32)fn_4_6720__fzgx_offset_658, (u32)fn_4_6720__fzgx_offset_66C, (u32)fn_4_6720__fzgx_offset_680,
    (u32)fn_4_6720__fzgx_offset_404, (u32)fn_4_6720__fzgx_offset_414, (u32)fn_4_6720__fzgx_offset_428, (u32)fn_4_6720__fzgx_offset_43C, (u32)fn_4_6720__fzgx_offset_450, (u32)fn_4_6720__fzgx_offset_464, (u32)fn_4_6720__fzgx_offset_478, (u32)fn_4_6720__fzgx_offset_48C,
    (u32)fn_4_6720__fzgx_offset_4A0, (u32)fn_4_6720__fzgx_offset_98, (u32)fn_4_6720__fzgx_offset_148, (u32)fn_4_6720__fzgx_offset_298, (u32)fn_4_6720__fzgx_offset_540, (u32)fn_4_6720__fzgx_offset_D6C, (u32)fn_4_6720__fzgx_offset_E8C, (u32)fn_4_6720__fzgx_offset_1038,
    (u32)fn_4_6720__fzgx_offset_1114, 0x43616C69, 0x62726174, 0x696F6E00, 0x834C8383, 0x838A8375, 0x838C815B, 0x83568387,
    0x83930000, 0x43757374, 0x6F6D697A, 0x65000000, 0x834A8358, 0x835E837D, 0x83438359, 0x0,
    0x436F6E74, 0x726F6C6C, 0x65722052, 0x756D626C, 0x65000000, 0x83528393, 0x8367838D, 0x815B8389,  /* fzgx-allow: A1 retail data bytes */
    0x905593AE, 0x0
}};
static union { u32 w[21]; u8 v[0x54]; } fzgx_pool_init_lbl_4_data_2C58 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x500000, (u32)lbl_4_data_2BF4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2C00__fzgx_offset_0, 0x520000,
    (u32)lbl_4_data_2C14__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2C20__fzgx_offset_0, 0x510000, (u32)lbl_4_data_2C30__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2C44__fzgx_offset_0
}};
struct fn_4_467C_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x2];
    s32 unk_4;
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0xA8];
    u8 unk_BA;
    u8 unk_BB;
    u8 unk_BC;
    u8 unk_BD;
    s8 unk_BE;
    u8 unk_BF;
    u16 unk_C0;
};

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u16 fzgx_obj_lbl_4_bss_0;
u8 fzgx_obj_lbl_4_bss_2;
u8 fzgx_pool_lbl_4_bss_0_gap_3;
u32 fzgx_obj_lbl_4_bss_4;
u32 fzgx_obj_lbl_4_bss_8;
u8 lbl_4_bss_C;
u8 lbl_4_bss_D;
u16 fzgx_pool_lbl_4_bss_0_gap_E;
u32 lbl_4_bss_10__fzgx_offset_0[42];
u16 lbl_4_bss_10__fzgx_offset_A8;
u8 lbl_4_bss_10__fzgx_offset_AA;
u8 lbl_4_bss_10__fzgx_offset_AB;
u8 lbl_4_bss_10__fzgx_offset_AC;
u8 lbl_4_bss_10__fzgx_offset_AD;
u16 lbl_4_bss_10__fzgx_offset_AE;
u32 lbl_4_bss_10__fzgx_offset_B0;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_data_base_prime(void) {
    const void *volatile s;  /* fzgx-allow: S2 data base primer sink: the retail TU addressed .data off its section base before .bss */
    s = &fzgx_pool_init_fzgx_obj_lbl_4_data_0;
    s = &fzgx_pool_init_tab_E8;
    s = &fzgx_pool_init_tab_3E8;
    s = &fzgx_pool_init_tab_468;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_4_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_2;
    s = *(u8 *)&fzgx_pool_lbl_4_bss_0_gap_3;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_4;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_8;
    s = *(u8 *)&lbl_4_bss_C;
    s = *(u8 *)&lbl_4_bss_D;
    s = *(u8 *)&fzgx_pool_lbl_4_bss_0_gap_E;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_0;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_A8;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_AA;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_AB;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_AC;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_AD;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_AE;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_B0;
}
#pragma section code_type ".text"

void fn_4_467C(void) {
    u32 t0, t1, t2;

    

    switch (lbl_4_bss_10__fzgx_offset_AB) {
    case 0:
    default:
        t0 = fzgx_pool_init_tab_3E8.v[lbl_801A66B4];
        t1 = fzgx_pool_init_tab_82C.v[lbl_801A66B4];
        t2 = 0x28000000;
        break;
    case 1:
        t0 = fzgx_pool_init_tab_468.v[lbl_801A66B4];
        t1 = fzgx_pool_init_tab_844.v[lbl_801A66B4];
        t2 = 0x20000000;
        break;
    case 2:
        t0 = fzgx_pool_init_tab_E8.v[lbl_801A66B4];
        t1 = fzgx_pool_init_tab_884.v[lbl_801A66B4];
        fn_4_2D4(lbl_4_bss_10__fzgx_offset_AC, t1);
        t1 = fzgx_pool_init_tab_82C.v[lbl_801A66B4];
        t2 = 0x48000000;
        break;
    }

    fn_4_40C4(lbl_4_bss_10__fzgx_offset_AD, t1);
    fn_1_1380F0(t0);
    fn_1_13ABA8(t2);
}
/* fzgx:end fn_4_467C */

/* fzgx:begin fn_4_4784 noprologue */
#include "types.h"

extern struct fn_4_4784_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_1_F70D0(u32);
extern u32 fn_1_F7568(void);
extern u32 lbl_4_data_1500;
extern u32 lbl_4_data_150C;
extern void fn_1_F7128(void);
extern void fn_4_467C(void);

struct fn_4_4784_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x2];
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0xA8];
    u8 unk_BA;
    u8 unk_BB;
    u8 pad_BC[0x1];
    u8 unk_BD;
    u8 unk_BE;
    u8 pad_BF[0x1];
    u16 unk_C0;
};

void fn_4_4784(void) {
    struct fn_4_4784_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t0, t1, t3, t5;
    p_lbl_4_bss_0 = (struct fn_4_4784_lbl_4_bss_0 *)&lbl_4_bss_0;
    t0 = fn_1_F7568();
    p_lbl_4_bss_0->unk_BE = t0;
    p_lbl_4_bss_0->unk_BA = t0;
    p_lbl_4_bss_0->unk_BD = 0;
    p_lbl_4_bss_0->unk_BB = 0;
    t1 = fn_1_435C(p_lbl_4_bss_0->unk_4);
    fn_1_F70D0(t1);
    t3 = fn_1_3F8C((u32)&lbl_4_data_1500, (u32)fn_1_F7128, 0, 10);
    p_lbl_4_bss_0->unk_C0 = t3;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t5 = fn_1_3F8C((u32)&lbl_4_data_150C, (u32)fn_4_467C, 0, 5);
    p_lbl_4_bss_0->unk_0 = t5;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_4784 */

/* fzgx:begin fn_4_4834 noprologue */
#include "types.h"

struct fn_4_4834_lbl_4_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x2];
    u8 unk_E;
    u8 pad_F[0x1];
    u16 unk_10;
    u8 pad_12[0xA6];
    u16 unk_B8;
    u8 unk_BA;
    u8 unk_BB;
    u8 unk_BC;
    u8 unk_BD;
    u8 unk_BE;
};

struct fn_4_4834_lbl_1_bss_9F8 {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
};

struct fn_4_4834_lbl_1_bss_718E0 {
    u8 pad_0[0x2];
    u8 unk_2;
};

extern struct fn_4_4834_lbl_4_bss_0 lbl_4_bss_0;
extern struct fn_4_4834_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern struct fn_4_4834_lbl_1_bss_718E0 lbl_1_bss_718E0;
extern u16 lbl_1_bss_96A;
extern int fn_1_4C10(void);
extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);
extern void fn_1_F755C(u8);
extern void fn_1_F73A8(s32, u32, u32);
extern void fn_1_156884(s32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_4_0(u32, u32, u32, u32, u32);

void fn_4_4834(void) {
    struct fn_4_4834_lbl_4_bss_0 *p_lbl_4_bss_0;
    int flag = 0;
    u16 state;

    p_lbl_4_bss_0 = (struct fn_4_4834_lbl_4_bss_0 *)&lbl_4_bss_0;

    if (p_lbl_4_bss_0->unk_10 != 0) {
        if (fn_1_4C10() != 0) {
            return;
        }
        fn_1_1280(1);
        lbl_1_bss_96A = p_lbl_4_bss_0->unk_10;
        p_lbl_4_bss_0->unk_10 = 0;
        return;
    }

    switch (p_lbl_4_bss_0->unk_BB) {
    case 0:
        p_lbl_4_bss_0->unk_BD = (u8)fn_4_0(p_lbl_4_bss_0->unk_BD, 0, 3, -1, 0);
        state = lbl_1_bss_9F8.unk_8;
        if (((state >> 8) & 1) != 0) {
            fn_1_A2D84(0xA9010100);
            p_lbl_4_bss_0->unk_BB = 1;
        } else if (((state >> 9) & 1) != 0) {
            fn_1_A2D84(0xA9010200);
            if (p_lbl_4_bss_0->unk_BA == lbl_1_bss_718E0.unk_2) {
                fn_1_F755C(p_lbl_4_bss_0->unk_BE);
                p_lbl_4_bss_0->unk_10 = 0x4D;
                fn_1_4A00(0, 15, p_lbl_4_bss_0->unk_8);
            } else {
                p_lbl_4_bss_0->unk_BB = 2;
                p_lbl_4_bss_0->unk_BC = 0;
            }
        }
        break;
    case 1:
        state = lbl_1_bss_9F8.unk_8;
        if (((state >> 9) & 1) != 0) {
            fn_1_A2D84(0xA9010200);
            p_lbl_4_bss_0->unk_BB = 0;
            break;
        }
        if (((lbl_1_bss_9F8.unk_10 >> 1) & 1) || ((lbl_1_bss_9F8.unk_12 >> 1) & 1)) {
            p_lbl_4_bss_0->unk_BA = (u8)(p_lbl_4_bss_0->unk_BA &
                ~(0x80000000u >> (31 - p_lbl_4_bss_0->unk_BD)));
            fn_1_A2D84(0xA9010000);
        } else if (((lbl_1_bss_9F8.unk_10 & 1) != 0) || ((lbl_1_bss_9F8.unk_12 & 1) != 0)) {
            fn_1_A2D84(0xA9010000);
            flag = !__rlwnm(p_lbl_4_bss_0->unk_BA, (32 - p_lbl_4_bss_0->unk_BD) & 31, 31, 31);
            p_lbl_4_bss_0->unk_BA = (u8)(p_lbl_4_bss_0->unk_BA |
                (0x80000000u >> (31 - p_lbl_4_bss_0->unk_BD)));
        }
        fn_1_F755C(p_lbl_4_bss_0->unk_BA);
        if (flag) {
            fn_1_F73A8(p_lbl_4_bss_0->unk_BD, 1, 0x12);
            fn_1_156884(p_lbl_4_bss_0->unk_BD);
        }
        break;
    case 2:
        p_lbl_4_bss_0->unk_BC = (u8)fn_4_0(p_lbl_4_bss_0->unk_BC, 0, 1, -1, 1);
        state = lbl_1_bss_9F8.unk_8;
        if (((state >> 9) & 1) != 0) {
            fn_1_A2D84(0xA9010200);
            p_lbl_4_bss_0->unk_BB = 0;
        } else if (((state >> 8) & 1) != 0) {
            fn_1_A2D84(0xA9010100);
            if (p_lbl_4_bss_0->unk_BC == 0) {
                lbl_1_bss_718E0.unk_2 = p_lbl_4_bss_0->unk_BA;
                p_lbl_4_bss_0->unk_E = 1;
                p_lbl_4_bss_0->unk_B8 = 0x4D;
                p_lbl_4_bss_0->unk_10 = 0x4C;
            } else {
                fn_1_F755C(p_lbl_4_bss_0->unk_BE);
                p_lbl_4_bss_0->unk_10 = 0x4D;
                fn_1_4A00(0, 15, p_lbl_4_bss_0->unk_8);
            }
        }
        break;
    }
}
/* fzgx:end fn_4_4834 */

/* fzgx:begin fn_4_4B10 */
extern u32 fn_1_435C(u32);

struct fn_4_4B10_state {
    u16 unk_0;
    u8 pad_2[0x2];
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0xB4];
    u16 unk_C0;
};

/* Stop active option sounds and clear the pending sound handle. */
void fn_4_4B10(void) {
    struct fn_4_4B10_state *state;

    state = (struct fn_4_4B10_state *)&lbl_4_bss_0;
    fn_1_F7308();
    fn_1_435C(state->unk_4);
    fn_1_426C(state->unk_C0);
    if (state->unk_0 != 0) {
        fn_1_435C(state->unk_8);
        fn_1_426C(state->unk_0);
        state->unk_0 = 0;
    }
}
/* fzgx:end fn_4_4B10 */

/* fzgx:begin fn_4_4B74 noprologue */
#include "types.h"

extern u8 jumptable_4_data_2974[36];

struct fn_4_4B74_obj {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

extern struct fn_4_4B74_obj lbl_4_bss_C4[];

s32 fn_4_4B74(u32 arg0, u32 arg1) {
    u32 idx;
    u32 v;

    switch (arg0) {
    case 0:
    case 4:
    default:
        idx = 0;
        break;
    case 1:
        idx = 0;
        break;
    case 2:
        idx = 1;
        break;
    case 3:
        idx = 2;
        break;
    }

    switch (arg1) {
    case 0:
        v = lbl_4_bss_C4[idx].unk_0;
        break;
    case 1:
        v = lbl_4_bss_C4[idx].unk_2;
        break;
    case 2:
        v = lbl_4_bss_C4[idx].unk_4;
        break;
    case 3:
        v = lbl_4_bss_C4[idx].unk_6;
        break;
    case 4:
        v = lbl_4_bss_C4[idx].unk_8;
        break;
    case 5:
        v = lbl_4_bss_C4[idx].unk_C;
        break;
    case 6:
        v = lbl_4_bss_C4[idx].unk_10;
        break;
    case 7:
        v = lbl_4_bss_C4[idx].unk_14;
        break;
    case 8:
        v = lbl_4_bss_C4[idx].unk_18;
        break;
    }

    return 31 - __cntlzw(v);
}
/* fzgx:end fn_4_4B74 */

/* fzgx:begin fn_4_4CB8 noprologue */
#include "types.h"

struct fn_4_4CB8_elt {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

extern struct fn_4_4CB8_elt lbl_4_bss_C4[];

void fn_4_4CB8(s32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    struct { s32 value; } v1;

    v0 = 1 << arg2;

    switch (arg0) {
    case 0:
    case 4:
    default:
        v1.value = 0;
        break;
    case 1:
        v1.value = 0;
        break;
    case 2:
        v1.value = 1;
        break;
    case 3:
        v1.value = 2;
        break;
    }

    switch (arg1) {
    case 0:
        (*((lbl_4_bss_C4) + (v1.value))).unk_0 = v0;
        break;
    case 1:
        lbl_4_bss_C4[v1.value].unk_2 = v0;
        break;
    case 2:
        lbl_4_bss_C4[v1.value].unk_4 = v0;
        break;
    case 3:
        lbl_4_bss_C4[v1.value].unk_6 = v0;
        break;
    case 4:
        (*((v1.value) + (lbl_4_bss_C4))).unk_8 = v0;
        break;
    case 5:
        lbl_4_bss_C4[v1.value].unk_C = v0;
        break;
    case 6:
        lbl_4_bss_C4[v1.value].unk_10 = v0;
        break;
    case 7:
        lbl_4_bss_C4[v1.value].unk_14 = v0;
        break;
    case 8:
        lbl_4_bss_C4[v1.value].unk_18 = v0;
        break;
    }
}
/* fzgx:end fn_4_4CB8 */

/* fzgx:begin fn_4_6678 noprologue */
#include "types.h"

extern u32 fn_80008BA8(u32, u32, u32);
extern u32 lbl_1_bss_AA0;
extern u32 lbl_1_data_2B60;
extern u32 lbl_4_data_2AE8;
extern u32 memcpy(u32, u32, u32);
extern void fn_4_63D4(void);

extern struct fn_4_6678_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);

struct fn_4_6678_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0x106];
    u8 unk_118;
    u8 pad_119[0x2];
    u8 unk_11B;
    u8 pad_11C[0x2];
    u8 unk_11E;
    u8 pad_11F[0x155];
    u8 unk_274;
};

void fn_4_6678(void) {
    struct fn_4_6678_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t1;
    p_lbl_4_bss_0 = (struct fn_4_6678_lbl_4_bss_0 *)&lbl_4_bss_0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_2AE8, (u32)fn_4_63D4, 0, 5);
    p_lbl_4_bss_0->unk_0 = t1;
    fn_80008BA8((u32)((u8 *)p_lbl_4_bss_0 + 288), (u32)&lbl_1_bss_AA0, 336);
    memcpy((u32)((u8 *)p_lbl_4_bss_0 + 624), (u32)&lbl_1_data_2B60, 4);
    p_lbl_4_bss_0->unk_11B = 0;
    p_lbl_4_bss_0->unk_274 = 255;
    p_lbl_4_bss_0->unk_118 = 0;
    p_lbl_4_bss_0->unk_11E = 0;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_6678 */

/* fzgx:begin fn_4_78E0 */
extern u32 fn_1_435C(u32);

/* Clears the pending option state after notifying the option handlers. */
void fn_4_78E0(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_78E0 */

/* fzgx:begin fn_4_7938 noprologue */
#include "types.h"
#include "font.h"
#include "rel/option/globals.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 167.0f;
    s = 38.0f;
    s = 0.5f;
}
extern u8 fn_4_347C__fzgx_offset_0[];
extern u8 fn_4_3568__fzgx_offset_0[];
extern u8 fn_4_406C__fzgx_offset_0[];
extern u8 fn_4_4784__fzgx_offset_0[];
extern u8 fn_4_4834__fzgx_offset_0[];
extern u8 fn_4_4B10__fzgx_offset_0[];
extern u8 fn_4_4B74__fzgx_offset_10C[];
extern u8 fn_4_4B74__fzgx_offset_124[];
extern u8 fn_4_4B74__fzgx_offset_68[];
extern u8 fn_4_4B74__fzgx_offset_7C[];
extern u8 fn_4_4B74__fzgx_offset_94[];
extern u8 fn_4_4B74__fzgx_offset_AC[];
extern u8 fn_4_4B74__fzgx_offset_C4[];
extern u8 fn_4_4B74__fzgx_offset_DC[];
extern u8 fn_4_4B74__fzgx_offset_F4[];
extern u8 fn_4_4CB8__fzgx_offset_110[];
extern u8 fn_4_4CB8__fzgx_offset_128[];
extern u8 fn_4_4CB8__fzgx_offset_6C[];
extern u8 fn_4_4CB8__fzgx_offset_80[];
extern u8 fn_4_4CB8__fzgx_offset_98[];
extern u8 fn_4_4CB8__fzgx_offset_B0[];
extern u8 fn_4_4CB8__fzgx_offset_C8[];
extern u8 fn_4_4CB8__fzgx_offset_E0[];
extern u8 fn_4_4CB8__fzgx_offset_F8[];
extern u8 fn_4_4DF8__fzgx_offset_12E4[];
extern u8 fn_4_4DF8__fzgx_offset_1308[];
extern u8 fn_4_4DF8__fzgx_offset_1330[];
extern u8 fn_4_4DF8__fzgx_offset_1350[];
extern u8 fn_4_4DF8__fzgx_offset_1378[];
extern u8 fn_4_4DF8__fzgx_offset_1398[];
extern u8 fn_4_4DF8__fzgx_offset_13C0[];
extern u8 fn_4_4DF8__fzgx_offset_13E0[];
extern u8 fn_4_4DF8__fzgx_offset_1408[];
extern u8 fn_4_4DF8__fzgx_offset_1428[];
extern u8 fn_4_4DF8__fzgx_offset_1454[];
extern u8 fn_4_4DF8__fzgx_offset_3E4[];
extern u8 fn_4_4DF8__fzgx_offset_3F4[];
extern u8 fn_4_4DF8__fzgx_offset_408[];
extern u8 fn_4_4DF8__fzgx_offset_41C[];
extern u8 fn_4_4DF8__fzgx_offset_430[];
extern u8 fn_4_4DF8__fzgx_offset_444[];
extern u8 fn_4_4DF8__fzgx_offset_458[];
extern u8 fn_4_4DF8__fzgx_offset_46C[];
extern u8 fn_4_4DF8__fzgx_offset_480[];
extern u8 fn_4_4DF8__fzgx_offset_930[];
extern u8 fn_4_4DF8__fzgx_offset_940[];
extern u8 fn_4_4DF8__fzgx_offset_954[];
extern u8 fn_4_4DF8__fzgx_offset_968[];
extern u8 fn_4_4DF8__fzgx_offset_97C[];
extern u8 fn_4_4DF8__fzgx_offset_990[];
extern u8 fn_4_4DF8__fzgx_offset_9A4[];
extern u8 fn_4_4DF8__fzgx_offset_9B8[];
extern u8 fn_4_4DF8__fzgx_offset_9CC[];
extern u8 fn_4_4DF8__fzgx_offset_D2C[];
extern u8 fn_4_4DF8__fzgx_offset_D4C[];
extern u8 fn_4_4DF8__fzgx_offset_D6C[];
extern u8 fn_4_4DF8__fzgx_offset_D8C[];
extern u8 fn_4_4DF8__fzgx_offset_DB4[];
extern u8 fn_4_4DF8__fzgx_offset_DD4[];
extern u8 fn_4_4DF8__fzgx_offset_DF4[];
extern u8 fn_4_4DF8__fzgx_offset_E14[];
extern u8 fn_4_4DF8__fzgx_offset_E34[];
extern u8 fn_4_4DF8__fzgx_offset_E54[];
extern u8 fn_4_4DF8__fzgx_offset_E80[];
extern u8 fn_4_63D4__fzgx_offset_150[];
extern u8 fn_4_63D4__fzgx_offset_170[];
extern u8 fn_4_63D4__fzgx_offset_190[];
extern u8 fn_4_63D4__fzgx_offset_1C0[];
extern u8 fn_4_63D4__fzgx_offset_1F0[];
extern u8 fn_4_63D4__fzgx_offset_94[];
extern u8 fn_4_63D4__fzgx_offset_F8[];
extern u8 fn_4_6678__fzgx_offset_0[];
extern u8 fn_4_6720__fzgx_offset_0[];
extern u8 fn_4_6720__fzgx_offset_1038[];
extern u8 fn_4_6720__fzgx_offset_1114[];
extern u8 fn_4_6720__fzgx_offset_148[];
extern u8 fn_4_6720__fzgx_offset_298[];
extern u8 fn_4_6720__fzgx_offset_404[];
extern u8 fn_4_6720__fzgx_offset_414[];
extern u8 fn_4_6720__fzgx_offset_428[];
extern u8 fn_4_6720__fzgx_offset_43C[];
extern u8 fn_4_6720__fzgx_offset_450[];
extern u8 fn_4_6720__fzgx_offset_464[];
extern u8 fn_4_6720__fzgx_offset_478[];
extern u8 fn_4_6720__fzgx_offset_48C[];
extern u8 fn_4_6720__fzgx_offset_4A0[];
extern u8 fn_4_6720__fzgx_offset_540[];
extern u8 fn_4_6720__fzgx_offset_5E4[];
extern u8 fn_4_6720__fzgx_offset_5F4[];
extern u8 fn_4_6720__fzgx_offset_608[];
extern u8 fn_4_6720__fzgx_offset_61C[];
extern u8 fn_4_6720__fzgx_offset_630[];
extern u8 fn_4_6720__fzgx_offset_644[];
extern u8 fn_4_6720__fzgx_offset_658[];
extern u8 fn_4_6720__fzgx_offset_66C[];
extern u8 fn_4_6720__fzgx_offset_680[];
extern u8 fn_4_6720__fzgx_offset_710[];
extern u8 fn_4_6720__fzgx_offset_720[];
extern u8 fn_4_6720__fzgx_offset_734[];
extern u8 fn_4_6720__fzgx_offset_748[];
extern u8 fn_4_6720__fzgx_offset_75C[];
extern u8 fn_4_6720__fzgx_offset_770[];
extern u8 fn_4_6720__fzgx_offset_784[];
extern u8 fn_4_6720__fzgx_offset_798[];
extern u8 fn_4_6720__fzgx_offset_7AC[];
extern u8 fn_4_6720__fzgx_offset_93C[];
extern u8 fn_4_6720__fzgx_offset_94C[];
extern u8 fn_4_6720__fzgx_offset_960[];
extern u8 fn_4_6720__fzgx_offset_974[];
extern u8 fn_4_6720__fzgx_offset_988[];
extern u8 fn_4_6720__fzgx_offset_98[];
extern u8 fn_4_6720__fzgx_offset_99C[];
extern u8 fn_4_6720__fzgx_offset_9B0[];
extern u8 fn_4_6720__fzgx_offset_9C4[];
extern u8 fn_4_6720__fzgx_offset_9D8[];
extern u8 fn_4_6720__fzgx_offset_B48[];
extern u8 fn_4_6720__fzgx_offset_B58[];
extern u8 fn_4_6720__fzgx_offset_B6C[];
extern u8 fn_4_6720__fzgx_offset_B80[];
extern u8 fn_4_6720__fzgx_offset_B94[];
extern u8 fn_4_6720__fzgx_offset_BA8[];
extern u8 fn_4_6720__fzgx_offset_BBC[];
extern u8 fn_4_6720__fzgx_offset_BD0[];
extern u8 fn_4_6720__fzgx_offset_BE4[];
extern u8 fn_4_6720__fzgx_offset_C94[];
extern u8 fn_4_6720__fzgx_offset_CA4[];
extern u8 fn_4_6720__fzgx_offset_CB8[];
extern u8 fn_4_6720__fzgx_offset_CCC[];
extern u8 fn_4_6720__fzgx_offset_CE0[];
extern u8 fn_4_6720__fzgx_offset_CF4[];
extern u8 fn_4_6720__fzgx_offset_D08[];
extern u8 fn_4_6720__fzgx_offset_D1C[];
extern u8 fn_4_6720__fzgx_offset_D30[];
extern u8 fn_4_6720__fzgx_offset_D6C[];
extern u8 fn_4_6720__fzgx_offset_E8C[];
extern u8 fn_4_78E0__fzgx_offset_0[];
extern u8 fn_4_7C38__fzgx_offset_0[];
extern u8 fn_4_7CA4__fzgx_offset_0[];
extern u8 fn_4_7D94__fzgx_offset_0[];
extern u8 fn_4_80EC__fzgx_offset_0[];
extern u8 fn_4_8158__fzgx_offset_0[];
extern u8 fn_4_8248__fzgx_offset_0[];
extern u8 fn_4_869C__fzgx_offset_0[];
extern u8 fn_4_8720__fzgx_offset_0[];
extern u8 fn_4_898C__fzgx_offset_0[];
extern u8 fn_4_89E4__fzgx_offset_0[];
extern u8 fn_4_8A54__fzgx_offset_0[];
extern u8 fn_4_8AE0__fzgx_offset_0[];
extern u8 fn_4_8DC0__fzgx_offset_0[];
extern u8 fn_4_8E38__fzgx_offset_0[];
extern u8 fn_4_9A78__fzgx_offset_0[];
extern u8 fn_4_9B20__fzgx_offset_0[];
extern u8 fn_4_9C14__fzgx_offset_0[];
extern u8 fn_4_A734__fzgx_offset_0[];
extern u8 fn_4_D10__fzgx_offset_0[];
extern u8 fn_4_D7C__fzgx_offset_0[];
extern u8 fn_4_EA0__fzgx_offset_0[];
extern u8 lbl_4_data_0__fzgx_offset_0[];
extern u8 lbl_4_data_100__fzgx_offset_0[];
extern u8 lbl_4_data_107C__fzgx_offset_0[];
extern u8 lbl_4_data_10A0__fzgx_offset_0[];
extern u8 lbl_4_data_10E8__fzgx_offset_0[];
extern u8 lbl_4_data_10__fzgx_offset_0[];
extern u8 lbl_4_data_111C__fzgx_offset_0[];
extern u8 lbl_4_data_116C__fzgx_offset_0[];
extern u8 lbl_4_data_11AC__fzgx_offset_0[];
extern u8 lbl_4_data_130__fzgx_offset_0[];
extern u8 lbl_4_data_1418__fzgx_offset_0[];
extern u8 lbl_4_data_1424__fzgx_offset_0[];
extern u8 lbl_4_data_1434__fzgx_offset_0[];
extern u8 lbl_4_data_1440__fzgx_offset_0[];
extern u8 lbl_4_data_1534__fzgx_offset_0[];
extern u8 lbl_4_data_1544__fzgx_offset_0[];
extern u8 lbl_4_data_154C__fzgx_offset_0[];
extern u8 lbl_4_data_1558__fzgx_offset_0[];
extern u8 lbl_4_data_156C__fzgx_offset_0[];
extern u8 lbl_4_data_1588__fzgx_offset_0[];
extern u8 lbl_4_data_15AC__fzgx_offset_0[];
extern u8 lbl_4_data_15B4__fzgx_offset_0[];
extern u8 lbl_4_data_1660__fzgx_offset_0[];
extern u8 lbl_4_data_1678__fzgx_offset_0[];
extern u8 lbl_4_data_1688__fzgx_offset_0[];
extern u8 lbl_4_data_168C__fzgx_offset_0[];
extern u8 lbl_4_data_16A0__fzgx_offset_0[];
extern u8 lbl_4_data_16FC__fzgx_offset_0[];
extern u8 lbl_4_data_1704__fzgx_offset_0[];
extern u8 lbl_4_data_170__fzgx_offset_0[];
extern u8 lbl_4_data_1718__fzgx_offset_0[];
extern u8 lbl_4_data_172C__fzgx_offset_0[];
extern u8 lbl_4_data_1740__fzgx_offset_0[];
extern u8 lbl_4_data_175C__fzgx_offset_0[];
extern u8 lbl_4_data_1770__fzgx_offset_0[];
extern u8 lbl_4_data_177C__fzgx_offset_0[];
extern u8 lbl_4_data_1790__fzgx_offset_0[];
extern u8 lbl_4_data_179C__fzgx_offset_0[];
extern u8 lbl_4_data_17B0__fzgx_offset_0[];
extern u8 lbl_4_data_17BC__fzgx_offset_0[];
extern u8 lbl_4_data_17D0__fzgx_offset_0[];
extern u8 lbl_4_data_17DC__fzgx_offset_0[];
extern u8 lbl_4_data_17F0__fzgx_offset_0[];
extern u8 lbl_4_data_17FC__fzgx_offset_0[];
extern u8 lbl_4_data_1810__fzgx_offset_0[];
extern u8 lbl_4_data_1818__fzgx_offset_0[];
extern u8 lbl_4_data_188__fzgx_offset_0[];
extern u8 lbl_4_data_1904__fzgx_offset_0[];
extern u8 lbl_4_data_1924__fzgx_offset_0[];
extern u8 lbl_4_data_192C__fzgx_offset_0[];
extern u8 lbl_4_data_193C__fzgx_offset_0[];
extern u8 lbl_4_data_1958__fzgx_offset_0[];
extern u8 lbl_4_data_1960__fzgx_offset_0[];
extern u8 lbl_4_data_1970__fzgx_offset_0[];
extern u8 lbl_4_data_1980__fzgx_offset_0[];
extern u8 lbl_4_data_1988__fzgx_offset_0[];
extern u8 lbl_4_data_1998__fzgx_offset_0[];
extern u8 lbl_4_data_19A8__fzgx_offset_0[];
extern u8 lbl_4_data_19B0__fzgx_offset_0[];
extern u8 lbl_4_data_19C0__fzgx_offset_0[];
extern u8 lbl_4_data_19E0__fzgx_offset_0[];
extern u8 lbl_4_data_19E8__fzgx_offset_0[];
extern u8 lbl_4_data_1A04__fzgx_offset_0[];
extern u8 lbl_4_data_1A24__fzgx_offset_0[];
extern u8 lbl_4_data_1A2C__fzgx_offset_0[];
extern u8 lbl_4_data_1A48__fzgx_offset_0[];
extern u8 lbl_4_data_1A64__fzgx_offset_0[];
extern u8 lbl_4_data_1A6C__fzgx_offset_0[];
extern u8 lbl_4_data_1A80__fzgx_offset_0[];
extern u8 lbl_4_data_1A98__fzgx_offset_0[];
extern u8 lbl_4_data_1AA0__fzgx_offset_0[];
extern u8 lbl_4_data_1AB4__fzgx_offset_0[];
extern u8 lbl_4_data_1AC4__fzgx_offset_0[];
extern u8 lbl_4_data_1ADC__fzgx_offset_0[];
extern u8 lbl_4_data_1AE8__fzgx_offset_0[];
extern u8 lbl_4_data_1BC__fzgx_offset_0[];
extern u8 lbl_4_data_1C78__fzgx_offset_0[];
extern u8 lbl_4_data_1C98__fzgx_offset_0[];
extern u8 lbl_4_data_1CA8__fzgx_offset_0[];
extern u8 lbl_4_data_1CC4__fzgx_offset_0[];
extern u8 lbl_4_data_1E60__fzgx_offset_0[];
extern u8 lbl_4_data_1E74__fzgx_offset_0[];
extern u8 lbl_4_data_1E7C__fzgx_offset_0[];
extern u8 lbl_4_data_1E8C__fzgx_offset_0[];
extern u8 lbl_4_data_1EA4__fzgx_offset_0[];
extern u8 lbl_4_data_1EB0__fzgx_offset_0[];
extern u8 lbl_4_data_1EC0__fzgx_offset_0[];
extern u8 lbl_4_data_1ED4__fzgx_offset_0[];
extern u8 lbl_4_data_1EDC__fzgx_offset_0[];
extern u8 lbl_4_data_1EEC__fzgx_offset_0[];
extern u8 lbl_4_data_1F00__fzgx_offset_0[];
extern u8 lbl_4_data_1F08__fzgx_offset_0[];
extern u8 lbl_4_data_1F18__fzgx_offset_0[];
extern u8 lbl_4_data_1F24__fzgx_offset_0[];
extern u8 lbl_4_data_1F28__fzgx_offset_0[];
extern u8 lbl_4_data_1F34__fzgx_offset_0[];
extern u8 lbl_4_data_1F40__fzgx_offset_0[];
extern u8 lbl_4_data_1F44__fzgx_offset_0[];
extern u8 lbl_4_data_1F50__fzgx_offset_0[];
extern u8 lbl_4_data_1F5C__fzgx_offset_0[];
extern u8 lbl_4_data_1F60__fzgx_offset_0[];
extern u8 lbl_4_data_1F6C__fzgx_offset_0[];
extern u8 lbl_4_data_1F78__fzgx_offset_0[];
extern u8 lbl_4_data_1F7C__fzgx_offset_0[];
extern u8 lbl_4_data_1F88__fzgx_offset_0[];
extern u8 lbl_4_data_1F94__fzgx_offset_0[];
extern u8 lbl_4_data_1F98__fzgx_offset_0[];
extern u8 lbl_4_data_1FA4__fzgx_offset_0[];
extern u8 lbl_4_data_1FBC__fzgx_offset_0[];
extern u8 lbl_4_data_1FD8__fzgx_offset_0[];
extern u8 lbl_4_data_1FF0__fzgx_offset_0[];
extern u8 lbl_4_data_1FFC__fzgx_offset_0[];
extern u8 lbl_4_data_2018__fzgx_offset_0[];
extern u8 lbl_4_data_2030__fzgx_offset_0[];
extern u8 lbl_4_data_2038__fzgx_offset_0[];
extern u8 lbl_4_data_2054__fzgx_offset_0[];
extern u8 lbl_4_data_2068__fzgx_offset_0[];
extern u8 lbl_4_data_2070__fzgx_offset_0[];
extern u8 lbl_4_data_208C__fzgx_offset_0[];
extern u8 lbl_4_data_209C__fzgx_offset_0[];
extern u8 lbl_4_data_20A4__fzgx_offset_0[];
extern u8 lbl_4_data_20B4__fzgx_offset_0[];
extern u8 lbl_4_data_20C8__fzgx_offset_0[];
extern u8 lbl_4_data_20D4__fzgx_offset_0[];
extern u8 lbl_4_data_20E4__fzgx_offset_0[];
extern u8 lbl_4_data_20F4__fzgx_offset_0[];
extern u8 lbl_4_data_20FC__fzgx_offset_0[];
extern u8 lbl_4_data_210C__fzgx_offset_0[];
extern u8 lbl_4_data_210__fzgx_offset_0[];
extern u8 lbl_4_data_211C__fzgx_offset_0[];
extern u8 lbl_4_data_2124__fzgx_offset_0[];
extern u8 lbl_4_data_2134__fzgx_offset_0[];
extern u8 lbl_4_data_2140__fzgx_offset_0[];
extern u8 lbl_4_data_2144__fzgx_offset_0[];
extern u8 lbl_4_data_2158__fzgx_offset_0[];
extern u8 lbl_4_data_2164__fzgx_offset_0[];
extern u8 lbl_4_data_216C__fzgx_offset_0[];
extern u8 lbl_4_data_2480__fzgx_offset_0[];
extern u8 lbl_4_data_2494__fzgx_offset_0[];
extern u8 lbl_4_data_24A0__fzgx_offset_0[];
extern u8 lbl_4_data_24B8__fzgx_offset_0[];
extern u8 lbl_4_data_24C4__fzgx_offset_0[];
extern u8 lbl_4_data_24D8__fzgx_offset_0[];
extern u8 lbl_4_data_24E8__fzgx_offset_0[];
extern u8 lbl_4_data_24F4__fzgx_offset_0[];
extern u8 lbl_4_data_254__fzgx_offset_0[];
extern u8 lbl_4_data_2804__fzgx_offset_0[];
extern u8 lbl_4_data_2810__fzgx_offset_0[];
extern u8 lbl_4_data_2834__fzgx_offset_0[];
extern u8 lbl_4_data_2848__fzgx_offset_0[];
extern u8 lbl_4_data_284__fzgx_offset_0[];
extern u8 lbl_4_data_2870__fzgx_offset_0[];
extern u8 lbl_4_data_290C__fzgx_offset_0[];
extern u8 lbl_4_data_2BF4__fzgx_offset_0[];
extern u8 lbl_4_data_2C00__fzgx_offset_0[];
extern u8 lbl_4_data_2C14__fzgx_offset_0[];
extern u8 lbl_4_data_2C20__fzgx_offset_0[];
extern u8 lbl_4_data_2C30__fzgx_offset_0[];
extern u8 lbl_4_data_2C44__fzgx_offset_0[];
extern u8 lbl_4_data_2CC__fzgx_offset_0[];
extern u8 lbl_4_data_2F0__fzgx_offset_0[];
extern u8 lbl_4_data_32C__fzgx_offset_0[];
extern u8 lbl_4_data_34C__fzgx_offset_0[];
extern u8 lbl_4_data_37C__fzgx_offset_0[];
extern u8 lbl_4_data_38__fzgx_offset_0[];
extern u8 lbl_4_data_3B8__fzgx_offset_0[];
extern u8 lbl_4_data_400__fzgx_offset_0[];
extern u8 lbl_4_data_438__fzgx_offset_0[];
extern u8 lbl_4_data_480__fzgx_offset_0[];
extern u8 lbl_4_data_4C__fzgx_offset_0[];
extern u8 lbl_4_data_4F0__fzgx_offset_0[];
extern u8 lbl_4_data_578__fzgx_offset_0[];
extern u8 lbl_4_data_57C__fzgx_offset_0[];
extern u8 lbl_4_data_59C__fzgx_offset_0[];
extern u8 lbl_4_data_5A0__fzgx_offset_0[];
extern u8 lbl_4_data_5C0__fzgx_offset_0[];
extern u8 lbl_4_data_5D8__fzgx_offset_0[];
extern u8 lbl_4_data_610__fzgx_offset_0[];
extern u8 lbl_4_data_660__fzgx_offset_0[];
extern u8 lbl_4_data_6D4__fzgx_offset_0[];
extern u8 lbl_4_data_724__fzgx_offset_0[];
extern u8 lbl_4_data_78__fzgx_offset_0[];
extern u8 lbl_4_data_790__fzgx_offset_0[];
extern u8 lbl_4_data_7C__fzgx_offset_0[];
extern u8 lbl_4_data_7DC__fzgx_offset_0[];
extern u8 lbl_4_data_85C__fzgx_offset_0[];
extern u8 lbl_4_data_86C__fzgx_offset_0[];
extern u8 lbl_4_data_89C__fzgx_offset_0[];
extern u8 lbl_4_data_8A8__fzgx_offset_0[];
extern u8 lbl_4_data_8D8__fzgx_offset_0[];
extern u8 lbl_4_data_8F8__fzgx_offset_0[];
extern u8 lbl_4_data_918__fzgx_offset_0[];
extern u8 lbl_4_data_934__fzgx_offset_0[];
extern u8 lbl_4_data_970__fzgx_offset_0[];
extern u8 lbl_4_data_984__fzgx_offset_0[];
extern u8 lbl_4_data_9C0__fzgx_offset_0[];
extern u8 lbl_4_data_9D8__fzgx_offset_0[];
extern u8 lbl_4_data_A10__fzgx_offset_0[];
extern u8 lbl_4_data_A30__fzgx_offset_0[];
extern u8 lbl_4_data_A70__fzgx_offset_0[];
extern u8 lbl_4_data_A78__fzgx_offset_0[];
extern u8 lbl_4_data_AA0__fzgx_offset_0[];
extern u8 lbl_4_data_AAC__fzgx_offset_0[];
extern u8 lbl_4_data_AD4__fzgx_offset_0[];
extern u8 lbl_4_data_B0__fzgx_offset_0[];
extern u8 lbl_4_data_B90__fzgx_offset_0[];
extern u8 lbl_4_data_C18__fzgx_offset_0[];
extern u8 lbl_4_data_C8__fzgx_offset_0[];
extern u8 lbl_4_data_CB0__fzgx_offset_0[];
extern u8 lbl_4_data_C__fzgx_offset_0[];
extern u8 lbl_4_data_D50__fzgx_offset_0[];
extern u8 lbl_4_data_D64__fzgx_offset_0[];
extern u8 lbl_4_data_D84__fzgx_offset_0[];
extern u8 lbl_4_data_D98__fzgx_offset_0[];
extern u8 lbl_4_data_DB8__fzgx_offset_0[];
extern u8 lbl_4_data_DF0__fzgx_offset_0[];
extern u8 lbl_4_data_E48__fzgx_offset_0[];
extern u8 lbl_4_data_E58__fzgx_offset_0[];
extern u8 lbl_4_data_E88__fzgx_offset_0[];
extern u8 lbl_4_data_E98__fzgx_offset_0[];
extern u8 lbl_4_data_EC8__fzgx_offset_0[];
extern u8 lbl_4_data_F08__fzgx_offset_0[];
extern u8 lbl_4_data_F64__fzgx_offset_0[];
extern u8 lbl_4_data_FD8__fzgx_offset_0[];
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table2 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xD0D000
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table2.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 78.0;
    d = 0.125;
    s = 2.9375f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table4.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3;
    d = 1.0;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table6 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xD0D000
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table6.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6000000238418579f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFF000000
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table8.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.5f;
    s = 5.0f;
    s = 0.0f;
    s = 320.0f;
    s = 0.15000000596046448f;
    s = 240.0f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table10 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table10.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 96.0;
    d = 48.0;
    s = 0.25f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table12 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table12.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.004999999888241291f;
    s = 216.0f;
    d = 90.0;
    d = 320.0;
    d = 0.5;
    s = 264.0f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table14 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table14.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = -0.5;
    s = 0.014999999664723873f;
    s = 72.0f;
    s = 0.02500000037252903f;
    s = 0.05000000074505806f;
    s = 48.0f;
    s = 0.800000011920929f;
    s = 110.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_120[1] = { 0x42F00000 }; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep120(void) { const u32 *volatile cp; cp = fzgx_pool_120; } /* fzgx-allow: S2 pool primer sink */
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table16 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x8080000
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table16.v; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

/* One menu row: a tag word followed by the row text per language. */
typedef struct OptionRow {
    u32 unk_0;
    char *text[6];
} OptionRow;

typedef struct Color4 {
    u8 c[4];
} Color4;

/* The module's .data objects, defined here so they share one section base. */
static union { u32 w[58]; u8 v[0xE8]; } fzgx_pool_init_fzgx_obj_lbl_4_data_0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x436F6E74, 0x726F6C6C, 0x65720000, 0x0, 0x83528393, 0x8367838D, 0x815B8389, 0x0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, 0x436F6E74, 0x726F6C6C,
    0x65722053, 0x6F636B65, 0x74000000, 0x83528393, 0x8367838D, 0x815B8389, 0x837C815B, 0x83670000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_38__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_4C__fzgx_offset_0, 0x4F4E0000, 0x4F464600,
    (u32)lbl_4_data_78__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_78__fzgx_offset_0, (u32)lbl_4_data_7C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_7C__fzgx_offset_0, 0x0, 0x55736520, 0x83AD206F, 0x722083B5, 0x20746F20,
    0x63686F6F, 0x73652E00, 0x83AD82A9, 0x83B582C5, 0x8D8096DA, 0x82F09149, 0x82F182C5, 0x82AD82BE,
    0x82B382A2, 0x81420000  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[540]; void *v[(0x958 - 0xE8) / 4]; } fzgx_pool_init_lbl_4_data_E8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_B0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C8__fzgx_offset_0, 0x4D6F7665, 0x2083AD20,
    0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063, 0x68616E67, 0x6520636F,
    0x6E74726F, 0x6C732E00, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C59180, 0x8DEC82F0, 0x95CF8D58,
    0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_100__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_130__fzgx_offset_0, 0x506C6561, 0x73652077, 0x61697420, 0x61206D6F, 0x6D656E74, 0x2E2E2E00,
    0x82B582CE, 0x82E782AD, 0x82A891D2, 0x82BF82AD, 0x82BE82B3, 0x82A28142, 0x0, (u32)lbl_4_data_170__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_188__fzgx_offset_0, 0x50726573, 0x73207468, 0x65204120,
    0x42757474, 0x6F6E206F, 0x6E207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0x20746F20, 0x62652061,
    0x646A7573, 0x7465642E, 0x20507265, 0x73732074, 0x68652042, 0x20427574, 0x746F6E20, 0x746F2066,
    0x696E6973, 0x682E0000, 0x95CF8D58, 0x82B782E9, 0x83528393, 0x8367838D, 0x815B8389, 0x82C5839F,  /* fzgx-allow: A1 retail data bytes */
    0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_1BC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_210__fzgx_offset_0, 0x526F7461, 0x74652074, 0x68652043, 0x6F6E7472, 0x6F6C2053,
    0x7469636B, 0x206F6E65, 0x2066756C, 0x6C207265, 0x766F6C75, 0x74696F6E, 0x2E000000, 0x83528393,
    0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E82F0, 0x88EA9474, 0x82C989F1, 0x82B582C4,  /* fzgx-allow: A1 retail data bytes */
    0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_254__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_284__fzgx_offset_0, 0x506C6561, 0x73652061, 0x646A7573, 0x74207468, 0x65207374, 0x65657269, 0x6E672077,
    0x6865656C, 0x2E000000, 0x836E8393, 0x8368838B, 0x82CC92B2, 0x90AE82F0, 0x8D7382C8, 0x82C182C4,
    0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_2CC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_2F0__fzgx_offset_0, 0x52657475, 0x726E2074, 0x6F207468, 0x65206465, 0x6661756C, 0x74207365, 0x7474696E,
    0x67733F00, 0x8F898AFA, 0x90DD92E8, 0x82C996DF, 0x82B582DC, 0x82B782A9, 0x81480000, (u32)lbl_4_data_32C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_34C__fzgx_offset_0, 0x53656C65, 0x63742074, 0x68652043,
    0x6F6E7472, 0x6F6C6C65, 0x7220746F, 0x20626520, 0x6368616E, 0x67656420, 0x7573696E, 0x67206569,
    0x74686572, 0x2083AD20, 0x6F722083, 0xB52E0000, 0x83AD82A9, 0x83B582C5, 0x95CF8D58, 0x82B782E9,
    0x83528393, 0x8367838D, 0x815B8389, 0x82F09149, 0x82F182C5, 0x82AD82BE, 0x82B382A2, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_37C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_3B8__fzgx_offset_0, 0x4D6F7665, 0x2083AD20,
    0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063, 0x68616E67, 0x65205275,
    0x6D626C65, 0x20736574, 0x74696E67, 0x732E0000, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C59055,
    0x93AE82CC, 0x90DD92E8, 0x82F095CF, 0x8D5882B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0x0,
    (u32)lbl_4_data_400__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_438__fzgx_offset_0, 0x54686520, 0x436F6E74,
    0x726F6C6C, 0x65722068, 0x61732062, 0x65656E20, 0x64697363, 0x6F6E6E65, 0x63746564, 0x2E0A2052,
    0x65636F6E, 0x6E656374, 0x20746865, 0x20436F6E, 0x74726F6C, 0x6C657220, 0x696E2053, 0x6F636B65,
    0x74202564, 0x206F720A, 0x20707265, 0x73732074, 0x68652041, 0x20427574, 0x746F6E20, 0x6F6E2061,
    0x6E6F7468, 0x65722E00, 0x83528393, 0x8367838D, 0x815B8389, 0x82AA8A4F, 0x82B382EA, 0x82DC82B5,  /* fzgx-allow: A1 retail data bytes */
    0x82BD8142, 0xA835283, 0x93836783, 0x8D815B83, 0x89837C81, 0x5B836725, 0x6482C982, 0xB382B582,
    0xC882A882, 0xB782A981, 0x410A91BC, 0x82CC8352, 0x83938367, 0x838D815B, 0x838982C5, 0x839F837B,
    0x835E8393, 0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_480__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_4F0__fzgx_offset_0, 0x59455300, 0x82CD82A2, 0x0, (u32)lbl_4_data_578__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_57C__fzgx_offset_0, 0x4E4F0000, 0x82A282A2, 0x82A60000,
    (u32)lbl_4_data_59C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_5A0__fzgx_offset_0, 0x4368616E, 0x6765204F,
    0x7074696F, 0x6E205365, 0x7474696E, 0x67730000, 0x83498376, 0x83568387, 0x839390DD, 0x92E882F0,
    0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0, (u32)lbl_4_data_5C0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_5D8__fzgx_offset_0, 0x41646A75, 0x73742074, 0x68652043, 0x616C6962, 0x72617469, 0x6F6E2E0A,
    0x50726573, 0x73207468, 0x65204120, 0x42757474, 0x6F6E206F, 0x6E207468, 0x6520436F, 0x6E74726F,
    0x6C6C6572, 0xA796F75, 0x2077616E, 0x74206164, 0x6A757374, 0x65642E00, 0x83528393, 0x8367838D,
    0x815B8389, 0x82CC834C, 0x8383838A, 0x8375838C, 0x815B8356, 0x83878393, 0x82F08D73, 0x82C882A2,  /* fzgx-allow: A1 retail data bytes */
    0x82DC82B7, 0x81420A95, 0xCF8D5882, 0xB782E983, 0x52839383, 0x67838D81, 0x5B838982, 0xC5839F82,  /* fzgx-allow: A1 retail data bytes */
    0xF0899F82, 0xB582C482, 0xAD82BE82, 0xB382A281, 0x42000000, (u32)lbl_4_data_610__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_660__fzgx_offset_0, 0x43757374, 0x6F6D697A, 0x65207468, 0x6520436F, 0x6E74726F,
    0x6C6C6572, 0x2E0A5072, 0x65737320, 0x74686520, 0x41204275, 0x74746F6E, 0x206F6E20, 0x74686520,
    0x436F6E74, 0x726F6C6C, 0x65722074, 0x6F206265, 0x2061646A, 0x75737465, 0x642E0000, 0x83528393,
    0x8367838D, 0x815B8389, 0x82CC834A, 0x8358835E, 0x837D8343, 0x835982F0, 0x8D7382C8, 0x82A282DC,  /* fzgx-allow: A1 retail data bytes */
    0x82B78142, 0xA95CF8D, 0x5882B782, 0xE9835283, 0x93836783, 0x8D815B83, 0x8982C583, 0x9F82F089,
    0x9F82B582, 0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_6D4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_724__fzgx_offset_0, 0x436F6E74, 0x726F6C6C, 0x65722052, 0x756D626C, 0x65205365, 0x7474696E,
    0x67732E0A, 0x20507265, 0x73732074, 0x68652041, 0x20427574, 0x746F6E20, 0x746F2073, 0x656C6563,
    0x74207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0x2E000000, 0x83528393, 0x8367838D, 0x815B8389,  /* fzgx-allow: A1 retail data bytes */
    0x82CC9055, 0x93AE82CC, 0x90DD92E8, 0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420A83, 0x52839383,  /* fzgx-allow: A1 retail data bytes */
    0x67838D81, 0x5B838982, 0xF0914982, 0xF182C583, 0x9F82F089, 0x9F82B582, 0xC482AD82, 0xBE82B382,
    0xA2814200, (u32)lbl_4_data_790__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_7DC__fzgx_offset_0, (u32)lbl_4_data_400__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_438__fzgx_offset_0, 0x53617665, 0x20636861, 0x6E676573,
    0x3F000000, 0x95CF8D58, 0x82F095DB, 0x91B682B5, 0x82DC82B7, 0x82A98148, 0x0, (u32)lbl_4_data_85C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_86C__fzgx_offset_0, 0x49732074, 0x68697320, 0x4F4B3F00,
    0x82B182EA, 0x82C582E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x81480000, (u32)lbl_4_data_89C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8A8__fzgx_offset_0, 0x8163826E, 0x826D0000, (u32)lbl_4_data_8D8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8D8__fzgx_offset_0, 0x826E8265, 0x82650000, (u32)lbl_4_data_8F8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8F8__fzgx_offset_0, 0x4368616E, 0x67652043, 0x6F6E7472, 0x6F6C6C65,
    0x72205365, 0x7474696E, 0x67730000, 0x83528393, 0x8367838D, 0x815B8389, 0x82CC90DD, 0x92E882F0,  /* fzgx-allow: A1 retail data bytes */
    0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0
}};
static union { u32 w[557]; void *v[(0x120C - 0x958) / 4]; } fzgx_pool_init_lbl_4_data_958 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_918__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_934__fzgx_offset_0, 0x4D616E61, 0x6765204D,
    0x656D6F72, 0x79204361, 0x72640000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x8AC7979D,
    0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420000, (u32)lbl_4_data_970__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_984__fzgx_offset_0, 0x53656C65, 0x63742053, 0x63726565, 0x6E205365, 0x7474696E, 0x67732000,
    0x89E696CA, 0x8382815B, 0x836882CC, 0x90DD92E8, 0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_9C0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_9D8__fzgx_offset_0, 0x55736520, 0x83AD206F,
    0x722083B5, 0x20746F20, 0x63686F6F, 0x73652061, 0x206D6F64, 0x65200000, 0x83AD82A9, 0x83B582CC,
    0x8DB68945, 0x82C58382, 0x815B8368, 0x82F09149, 0x82F182C5, 0x82AD82BE, 0x82B382A2, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_A10__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_A30__fzgx_offset_0, 0x4E6F726D, 0x616C0000,
    0x836D815B, 0x837D838B, 0x8365838C, 0x83720000, (u32)lbl_4_data_A70__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_A78__fzgx_offset_0, 0x57696465, 0x20536372, 0x65656E00, 0x838F8343, 0x83688365, 0x838C8372,
    0x0, (u32)lbl_4_data_AA0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_AAC__fzgx_offset_0, 0x4D6F7665,
    0x20746865, 0x20436F6E, 0x74726F6C, 0x20537469, 0x636B2061, 0x726F756E, 0x6420696E, 0x20612063,
    0x6972636C, 0x6520756E, 0x74696C20, 0x74686520, 0x66696775, 0x72657320, 0x6F6E2074, 0x68650A20,
    0x6C656674, 0x20736964, 0x6520646F, 0x206E6F74, 0x20636861, 0x6E67652E, 0x2041646A, 0x75737420,
    0x706C6179, 0x20757369, 0x6E672074, 0x68652083, 0xB520436F, 0x6E74726F, 0x6C205061, 0x642E0A20,
    0x50726573, 0x73207468, 0x65205820, 0x42757474, 0x6F6E2074, 0x6F207265, 0x7475726E, 0x20746F20,
    0x74686520, 0x64656661, 0x756C7420, 0x73657474, 0x696E6773, 0x2E000000, 0x8DB691A4, 0x82CC907D,
    0x8C6082AA, 0x95CF89BB, 0x82B582C8, 0x82AD82C8, 0x82E982DC, 0x82C583AD, 0x82F088EA, 0x947482C9,
    0x89F182B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0xA83B582, 0xC5975682, 0xD182F092, 0xB290AE82,
    0xB582C482, 0xAD82BE82, 0xB382A281, 0x420A83B4, 0x82C58F89, 0x8AFA90DD, 0x92E882C9, 0x96DF82B9,
    0x82DC82B7, 0x81420000, (u32)lbl_4_data_AD4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_B90__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x5475726E, 0x20746865, 0x20737465, 0x6572696E, 0x67207768, 0x65656C20, 0x4C656674, 0x20616E64,
    0x20526967, 0x68742061, 0x6E642070, 0x72657373, 0xA746865, 0x20412042, 0x7574746F, 0x6E206174,
    0x20746865, 0x20706F69, 0x6E742079, 0x6F752077, 0x616E7420, 0x746F2073, 0x65742061, 0x73207468,
    0x650A206C, 0x696D6974, 0x2E205573, 0x65207468, 0x65204C20, 0x616E6420, 0x52204275, 0x74746F6E,
    0x7320746F, 0x2061646A, 0x75737420, 0x67616D65, 0x20706C61, 0x792E2000, 0x836E8393, 0x8368838B,
    0x82F08DB6, 0x894582C9, 0x89F182B5, 0x81418CC0, 0x8A4582C6, 0x82B582BD, 0x82A288CA, 0x927582C5,  /* fzgx-allow: A1 retail data bytes */
    0x839F82F0, 0x899F82B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0xA826B81, 0x95827183, 0x67838A83,
    0x4B815B83, 0x7B835E83, 0x9382C597, 0x5682D182, 0xF092B290, 0xAE82B582, 0xC482AD82, 0xBE82B382,
    0xA281420A, 0x83B482C5, 0x8F898AFA, 0x90DD92E8, 0x82C996DF, 0x82B982DC, 0x82B78142, 0x0,
    (u32)lbl_4_data_C18__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_CB0__fzgx_offset_0, 0x4265666F, 0x72652063,
    0x6F727265, 0x6374696F, 0x6E000000, 0x95E290B3, 0x914F0000, (u32)lbl_4_data_D50__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_D64__fzgx_offset_0, 0x41667465, 0x7220636F, 0x72726563, 0x74696F6E, 0x0,
    0x95E290B3, 0x8CE30000, (u32)lbl_4_data_D84__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_D98__fzgx_offset_0,
    0x47616D65, 0x20446174, 0x6120436F, 0x6E74726F, 0x6C730A49, 0x6E736572, 0x74206120, 0x4D656D6F,
    0x72792043, 0x61726420, 0x696E746F, 0x20536C6F, 0x7420412E, 0x0, 0x8351815B, 0x83808366,
    0x815B835E, 0x82CC9180, 0x8DEC0A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F083, 0x58838D83,  /* fzgx-allow: A1 retail data bytes */
    0x62836782, 0x6082C993, 0xFC82EA82, 0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_DB8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_DF0__fzgx_offset_0, 0x4C6F6164, 0x2047616D, 0x65204461, 0x74610000,
    0x8351815B, 0x83808366, 0x815B835E, 0x82CC838D, 0x815B8368, 0x0, (u32)lbl_4_data_E48__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_E58__fzgx_offset_0, 0x53617665, 0x2047616D, 0x65204461, 0x74610000,
    0x8351815B, 0x83808366, 0x815B835E, 0x82CC835A, 0x815B8375, 0x0, (u32)lbl_4_data_E88__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_E98__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20, 0x47616D65,
    0x20446174, 0x61206F6E, 0x20746869, 0x73204D65, 0x6D6F7279, 0x20436172, 0x642E0A20, 0x53617669,
    0x6E67206E, 0x65772064, 0x6174612E, 0x0, 0x83818382, 0x838A815B, 0x834A815B, 0x836882C9,
    0xA835181, 0x5B838083, 0x66815B83, 0x5E82AA8C, 0xA982C282, 0xA982E882, 0xDC82B982, 0xF181420A,
    0x90568B4B, 0x835A815B, 0x837582B5, 0x82DC82B7, 0x81420000, (u32)lbl_4_data_EC8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_F08__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20, 0x47616D65, 0x20446174,
    0x61206F6E, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x2E0A4966, 0x20796F75, 0x20736176,
    0x652C2074, 0x68652047, 0x616D6520, 0x44617461, 0x20637572, 0x72656E74, 0x6C79206C, 0x6F616465,
    0x640A7769, 0x6C6C2061, 0x6C6C2062, 0x65206C6F, 0x73742E20, 0x49732074, 0x68617420, 0x4F4B3F00,
    0x83818382, 0x838A815B, 0x834A815B, 0x836882C9, 0x8351815B, 0x83808366, 0x815B835E, 0x82AA8CA9,  /* fzgx-allow: A1 retail data bytes */
    0x82C282A9, 0x82E882DC, 0x82B982F1, 0x81420A90, 0x568B4B83, 0x5A815B83, 0x7582B782, 0xE982C68C,  /* fzgx-allow: A1 retail data bytes */
    0xBB8DDD83, 0x8D815B83, 0x6882B382, 0xEA82C482, 0xA282E983, 0x51815B83, 0x80836681, 0x5B835E82,  /* fzgx-allow: A1 retail data bytes */
    0xAA0A9153, 0x82C48FC1, 0x82A682C4, 0x82B582DC, 0x82A282DC, 0x82B782AA, 0x814182E6, 0x82EB82B5,  /* fzgx-allow: A1 retail data bytes */
    0x82A282C5, 0x82B782A9, 0x3F000000, (u32)lbl_4_data_F64__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_FD8__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053,
    0x6C6F7420, 0x412E0000, 0x8358838D, 0x83628367, 0x826082C9, 0xA838183, 0x82838A81, 0x5B834A81,
    0x5B836882, 0xAA8CA982, 0xC282A982, 0xE882DC82, 0xB982F181, 0x42000000, (u32)lbl_4_data_107C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10A0__fzgx_offset_0, 0x52656769, 0x73746572, 0x20746869, 0x73206E61,
    0x6D65206F, 0x6E207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20536C6F, 0x7420412E,
    0x0, 0x82B182CC, 0x96BC914F, 0x82C58381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C90A93,  /* fzgx-allow: A1 retail data bytes */
    0x6F985E82, 0xB582C482, 0xE082E682, 0xEB82B582, 0xA282C582, 0xB782A93F, 0x0, (u32)lbl_4_data_10E8__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_111C__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20,
    0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x6C6F7420, 0x412E0A20, 0x54686520, 0x67616D65,
    0x2063616E, 0x6E6F7420, 0x62652073, 0x61766564, 0x2E000000, 0x8358838D, 0x83628367, 0x826082C9,
    0x83818382, 0x838A815B, 0x834A815B, 0x836882AA, 0x8CA982C2, 0x82A982E8, 0x82DC82B9, 0x82F18142,
    0xA835A81, 0x5B837582, 0xC582AB82, 0xDC82B982, 0xF182C582, 0xB582BD81, 0x42000000, (u32)lbl_4_data_116C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_11AC__fzgx_offset_0
}};
u8 lbl_4_data_11AC__fzgx_offset_60 = 0xFF;
s16 lbl_4_data_11AC__fzgx_offset_62 = -1;
static union { u32 w[1682]; char v[0x2C58 - 0x1210]; } fzgx_pool_init_lbl_4_data_1210 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x257300FF, 0xFFFF0000, 0x6F707469, 0x6F6E2E63, 0x0, 0x53656C53, 0x5F446973, 0x70506F6C,
    0x79676F6E, 0x42470000, 0x53656C53, 0x5F446973, 0x70537072, 0x69746542, 0x47000000, 0x6F707469,
    0x6F6E5F63, 0x6F6D6D6F, 0x6E5F6469, 0x73700000, 0x534D445F, 0x4F505449, 0x4F4E5F4D, 0x454E5500,
    0x0, 0x0, 0x0, 0x0, (u32)fn_4_D10__fzgx_offset_0, (u32)fn_4_D7C__fzgx_offset_0, (u32)fn_4_EA0__fzgx_offset_0, 0x534D445F,
    0x4F505449, 0x4F4E5F53, 0x4156455F, 0x57414954, 0x0, 0x0, 0x0, (u32)fn_4_9B20__fzgx_offset_0,
    (u32)fn_4_9C14__fzgx_offset_0, (u32)fn_4_A734__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43, 0x54524C5F, 0x4D454E55, 0x0,
    0x0, 0x0, (u32)fn_4_7C38__fzgx_offset_0, (u32)fn_4_7CA4__fzgx_offset_0, (u32)fn_4_7D94__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43,
    0x4152445F, 0x4D454E55, 0x0, 0x0, 0x0, (u32)fn_4_80EC__fzgx_offset_0, (u32)fn_4_8158__fzgx_offset_0, (u32)fn_4_8248__fzgx_offset_0,
    0x534D445F, 0x4F505449, 0x4F4E5F57, 0x49444500, 0x0, 0x0, 0x0, 0x0,
    (u32)fn_4_869C__fzgx_offset_0, (u32)fn_4_8720__fzgx_offset_0, (u32)fn_4_898C__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43, 0x414C4942, 0x0,
    0x0, 0x0, 0x0, (u32)fn_4_347C__fzgx_offset_0, (u32)fn_4_3568__fzgx_offset_0, (u32)fn_4_406C__fzgx_offset_0, 0x534D445F, 0x4F505449,
    0x4F4E5F52, 0x554D424C, 0x45000000, 0x0, 0x0, 0x0, (u32)fn_4_4784__fzgx_offset_0, (u32)fn_4_4834__fzgx_offset_0,
    (u32)fn_4_4B10__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F50, 0x43555354, 0x0, 0x0, 0x0,
    0x0, (u32)fn_4_6678__fzgx_offset_0, (u32)fn_4_6720__fzgx_offset_0, (u32)fn_4_78E0__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43, 0x4152445F,
    0x4D414E41, 0x47450000, 0x0, 0x0, (u32)fn_4_89E4__fzgx_offset_0, (u32)fn_4_8A54__fzgx_offset_0, (u32)fn_4_8AE0__fzgx_offset_0, 0x534D445F,
    0x4F505449, 0x4F4E5F43, 0x4152445F, 0x47444154, 0x41000000, 0x0, 0x0, (u32)fn_4_8DC0__fzgx_offset_0,
    (u32)fn_4_8E38__fzgx_offset_0, (u32)fn_4_9A78__fzgx_offset_0, 0x4D656D6F, 0x72792043, 0x61726400, 0x83818382, 0x838A815B, 0x834A815B,
    0x83680000, 0x53637265, 0x656E204D, 0x6F646500, 0x89E696CA, 0x8382815B, 0x83680000, 0x4D0000,
    (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, 0x4E0000, (u32)lbl_4_data_1418__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1424__fzgx_offset_0, 0x4F0000, (u32)lbl_4_data_1434__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1440__fzgx_offset_0, 0x6F707469, 0x6F6E5F6D, 0x656E755F, 0x64697370,
    0x0, 0x583A2534, 0x640A0000, 0x593A2534, 0x64000000, 0x25732534, 0x64000000, 0x25346400,
    0x6F707469, 0x6F6E5F63, 0x616C6962, 0x5F646973, 0x7000FF00, 0xFFFF0000, 0x25732564, 0x81632020,  /* fzgx-allow: A1 retail data bytes */
    0x20000000, 0x25732564, 0x81632573, 0x0, 0x52756D62, 0x6C654D61, 0x696E0000, 0x6F707469,  /* fzgx-allow: A1 retail data bytes */
    0x6F6E5F72, 0x756D626C, 0x655F6469, 0x73700000, 0x81FF811F, 0x831F0000, 0x803FFF1F, 0x80303F1F,  /* fzgx-allow: A1 retail data bytes */
    0x80F03F1F, 0x4E6F7420, 0x436F6E6E, 0x65637465, 0x64000000, 0x96A290DA, 0x91B10000, 0x53706565,  /* fzgx-allow: A1 retail data bytes */
    0x6420466F, 0x72636500, 0x83588373, 0x815B8368, 0x83748348, 0x815B8358, 0x0, 0x53706565,  /* fzgx-allow: A1 retail data bytes */
    0x6420466F, 0x72636520, 0x616E6420, 0x50656461, 0x6C20556E, 0x69740000, 0x83588373, 0x815B8368,  /* fzgx-allow: A1 retail data bytes */
    0x83748348, 0x815B8358, 0x81958379, 0x835F838B, 0x8386836A, 0x83628367, 0x0, 0x41726361,  /* fzgx-allow: A1 retail data bytes */
    0x64650000, 0x8341815B, 0x8350815B, 0x83688341, 0x815B8350, 0x815B8368, 0x8341815B, 0x8350815B,  /* fzgx-allow: A1 retail data bytes */
    0x83688341, 0x815B8350, 0x815B8368, 0x8341815B, 0x8350815B, 0x83680000, (u32)lbl_4_data_1534__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0,
    (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_154C__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0,
    (u32)lbl_4_data_156C__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_15AC__fzgx_offset_0, (u32)lbl_4_data_15B4__fzgx_offset_0,
    0x0, 0x0, 0x0, 0x0, 0x81638163, 0x81638163, 0x81638163, 0x81638163,  /* fzgx-allow: A1 retail data bytes */
    0x81638163, 0x81630000, 0x81638163, 0x81638163, 0x81638163, 0x0, 0x81630000, 0x81638163,  /* fzgx-allow: A1 retail data bytes */
    0x81638163, 0x81638163, 0x81638163, 0x0, 0x81638163, 0x81638163, 0x81638163, 0x81638163,  /* fzgx-allow: A1 retail data bytes */
    0x81630000, 0xA400A0, (u32)lbl_4_data_1660__fzgx_offset_0, 0xF800B4, (u32)lbl_4_data_1678__fzgx_offset_0, 0x14C00C8, (u32)lbl_4_data_1688__fzgx_offset_0, 0xD600DC,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_168C__fzgx_offset_0, 0xD600F0, (u32)lbl_4_data_168C__fzgx_offset_0, 0xC60104, (u32)lbl_4_data_16A0__fzgx_offset_0, 0xD60118, (u32)lbl_4_data_168C__fzgx_offset_0, 0xD6012C,
    (u32)lbl_4_data_168C__fzgx_offset_0, 0xA40140, (u32)lbl_4_data_1660__fzgx_offset_0, 0x53746565, 0x72000000, 0x83588365, 0x8341838A, 0x8393834F,
    0x8DB68945, 0x81630000, 0x536C6964, 0x65204C65, 0x66742052, 0x69676874, 0x0, 0x83588389,  /* fzgx-allow: A1 retail data bytes */
    0x83438368, 0x8DB68945, 0x81638163, 0x81630000, 0x41646A75, 0x73742043, 0x656E7465, 0x72206F66,  /* fzgx-allow: A1 retail data bytes */
    0x20477261, 0x76697479, 0x0, 0x83578383, 0x83938376, 0x8F649053, 0x88DA93AE, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x41646A75, 0x73742056, 0x69657700, 0x8E8B935F, 0x95CF8D58, 0x81638163, 0x81638163, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x41636365, 0x6C657261, 0x74650000, 0x8341834E, 0x835A838B, 0x81638163, 0x81638163, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x41697220, 0x4272616B, 0x65000000, 0x83478341, 0x8375838C, 0x815B834C, 0x81638163, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x53696465, 0x20417474, 0x61636B00, 0x83548343, 0x83688341, 0x835E8362, 0x834E8163, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x5370696E, 0x20417474, 0x61636B00, 0x83588373, 0x83938341, 0x835E8362, 0x834E8163, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x426F6F73, 0x74000000, 0x8375815B, 0x8358835E, 0x815B8163, 0x81638163, 0x81630000, (u32)lbl_4_data_16FC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1704__fzgx_offset_0, (u32)lbl_4_data_1718__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_172C__fzgx_offset_0, (u32)lbl_4_data_1740__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_175C__fzgx_offset_0, (u32)lbl_4_data_1770__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_177C__fzgx_offset_0, (u32)lbl_4_data_1790__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_179C__fzgx_offset_0, (u32)lbl_4_data_17B0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_17BC__fzgx_offset_0, (u32)lbl_4_data_17D0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_17DC__fzgx_offset_0, (u32)lbl_4_data_17F0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_17FC__fzgx_offset_0, (u32)lbl_4_data_1810__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1818__fzgx_offset_0, 0x83B52043, 0x6F6E7472, 0x6F6C2050,
    0x6164204C, 0x65667420, 0x616E6420, 0x52696768, 0x74000000, 0x83B52083, 0xD0000000, 0x8F5C8E9A,
    0x837B835E, 0x83938DB6, 0x89450000, 0x83B52043, 0x6F6E7472, 0x6F6C2050, 0x61642055, 0x7020616E,
    0x6420446F, 0x776E0000, 0x83B52083, 0xCF000000, 0x8F5C8E9A, 0x837B835E, 0x83938FE3, 0x89BA0000,
    0x4120616E, 0x64204220, 0x42757474, 0x6F6E0000, 0x839F2083, 0xA0000000, 0x82608195, 0x8261837B,
    0x835E8393, 0x0, 0x5820616E, 0x64205920, 0x42757474, 0x6F6E0000, 0x83B42083, 0xB2000000,
    0x82778195, 0x8278837B, 0x835E8393, 0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053, 0x7469636B,
    0x204C6566, 0x7420616E, 0x64205269, 0x67687400, 0x83AD2083, 0xD0000000, 0x83528393, 0x8367838D,
    0x815B838B, 0x83588365, 0x83428362, 0x834E8DB6, 0x89450000, 0x83AD2043, 0x6F6E7472, 0x6F6C2053,  /* fzgx-allow: A1 retail data bytes */
    0x7469636B, 0x20557020, 0x616E6420, 0x446F776E, 0x0, 0x83AD2083, 0xCF000000, 0x83528393,
    0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E8FE3, 0x89BA0000, 0x83A62043, 0x20537469,  /* fzgx-allow: A1 retail data bytes */
    0x636B204C, 0x65667420, 0x616E6420, 0x52696768, 0x74000000, 0x83A62083, 0xD0000000, 0x82628358,
    0x83658342, 0x8362834E, 0x8DB68945, 0x0, 0x83A62043, 0x20537469, 0x636B2055, 0x7020616E,
    0x6420446F, 0x776E0000, 0x83A62083, 0xCF000000, 0x82628358, 0x83658342, 0x8362834E, 0x8FE389BA,
    0x0, 0x4C20616E, 0x64205220, 0x42757474, 0x6F6E0000, 0x826B8195, 0x82718367, 0x838A834B,
    0x815B837B, 0x835E8393, 0x0, 0x4E6F2051, 0x756F7461, 0x73000000, 0x8A8482E8, 0x939682C4,  /* fzgx-allow: A1 retail data bytes */
    0x82C882B5, 0x0, (u32)lbl_4_data_1904__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_192C__fzgx_offset_0,
    (u32)lbl_4_data_193C__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1960__fzgx_offset_0, (u32)lbl_4_data_1970__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0,
    (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1988__fzgx_offset_0, (u32)lbl_4_data_1998__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0,
    (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19B0__fzgx_offset_0, (u32)lbl_4_data_19C0__fzgx_offset_0, (u32)lbl_4_data_19E0__fzgx_offset_0, (u32)lbl_4_data_19E0__fzgx_offset_0, (u32)lbl_4_data_19E0__fzgx_offset_0, (u32)lbl_4_data_19E0__fzgx_offset_0, (u32)lbl_4_data_19E8__fzgx_offset_0,
    (u32)lbl_4_data_1A04__fzgx_offset_0, (u32)lbl_4_data_1A24__fzgx_offset_0, (u32)lbl_4_data_1A24__fzgx_offset_0, (u32)lbl_4_data_1A24__fzgx_offset_0, (u32)lbl_4_data_1A24__fzgx_offset_0, (u32)lbl_4_data_1A2C__fzgx_offset_0, (u32)lbl_4_data_1A48__fzgx_offset_0, (u32)lbl_4_data_1A64__fzgx_offset_0,
    (u32)lbl_4_data_1A64__fzgx_offset_0, (u32)lbl_4_data_1A64__fzgx_offset_0, (u32)lbl_4_data_1A64__fzgx_offset_0, (u32)lbl_4_data_1A6C__fzgx_offset_0, (u32)lbl_4_data_1A80__fzgx_offset_0, (u32)lbl_4_data_1A98__fzgx_offset_0, (u32)lbl_4_data_1A98__fzgx_offset_0, (u32)lbl_4_data_1A98__fzgx_offset_0,
    (u32)lbl_4_data_1A98__fzgx_offset_0, (u32)lbl_4_data_1AA0__fzgx_offset_0, (u32)lbl_4_data_1AB4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AC4__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1ADC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AE8__fzgx_offset_0, 0x53746565, 0x72696E67, 0x20576865, 0x656C204C, 0x65667420, 0x616E6420,
    0x52696768, 0x74000000, 0x836E8393, 0x8368838B, 0x8DB68945, 0x0, 0x41636365, 0x6C657261,
    0x746F7220, 0x616E6420, 0x42726561, 0x6B205065, 0x64616C00, 0x8341834E, 0x835A838B, 0x81958375,
    0x838C815B, 0x834C8379, 0x835F838B, 0x0, (u32)lbl_4_data_1904__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0,
    (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_192C__fzgx_offset_0, (u32)lbl_4_data_193C__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1960__fzgx_offset_0,
    (u32)lbl_4_data_1970__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1988__fzgx_offset_0, (u32)lbl_4_data_1998__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0,
    (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19B0__fzgx_offset_0, (u32)lbl_4_data_1C78__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1C98__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AB4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AC4__fzgx_offset_0, (u32)lbl_4_data_1CA8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1CC4__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1ADC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AE8__fzgx_offset_0, 0x83B52043, 0x6F6E7472, 0x6F6C2050, 0x6164204C,
    0x65667400, 0x83B5204C, 0x65667400, 0x8F5C8E9A, 0x837B835E, 0x83938DB6, 0x0, 0x83B52043,
    0x6F6E7472, 0x6F6C2050, 0x61642052, 0x69676874, 0x0, 0x83B52052, 0x69676874, 0x0,
    0x8F5C8E9A, 0x837B835E, 0x83938945, 0x0, 0x83B52043, 0x6F6E7472, 0x6F6C2050, 0x61642044,
    0x6F776E00, 0x83B52044, 0x6F776E00, 0x8F5C8E9A, 0x837B835E, 0x839389BA, 0x0, 0x83B52043,
    0x6F6E7472, 0x6F6C2050, 0x61642055, 0x70000000, 0x83B52055, 0x70000000, 0x8F5C8E9A, 0x837B835E,
    0x83938FE3, 0x0, 0x5A204275, 0x74746F6E, 0x0, 0x83A42000, 0x8279837B, 0x835E8393,
    0x0, 0x41204275, 0x74746F6E, 0x0, 0x839F0000, 0x8260837B, 0x835E8393, 0x0,
    0x42204275, 0x74746F6E, 0x0, 0x83A02000, 0x8261837B, 0x835E8393, 0x0, 0x58204275,
    0x74746F6E, 0x0, 0x83B42000, 0x8277837B, 0x835E8393, 0x0, 0x59204275, 0x74746F6E,
    0x0, 0x83B22000, 0x8278837B, 0x835E8393, 0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053,
    0x7469636B, 0x204C6566, 0x74000000, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362,  /* fzgx-allow: A1 retail data bytes */
    0x834E8DB6, 0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x20526967, 0x68740000,
    0x83AD2052, 0x69676874, 0x0, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362,  /* fzgx-allow: A1 retail data bytes */
    0x834E8945, 0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x20446F77, 0x6E000000,
    0x83AD2044, 0x6F776E00, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E89BA,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x20557000, 0x83AD2055, 0x70000000,
    0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E8FE3, 0x0, 0x83A62043,  /* fzgx-allow: A1 retail data bytes */
    0x20537469, 0x636B204C, 0x65667400, 0x83AD204C, 0x65667400, 0x82628358, 0x83658342, 0x8362834E,
    0x8DB60000, 0x83A62043, 0x20537469, 0x636B2052, 0x69676874, 0x0, 0x83A62052, 0x69676874,
    0x0, 0x82628358, 0x83658342, 0x8362834E, 0x89450000, 0x83A62043, 0x20537469, 0x636B2044,
    0x6F776E00, 0x83A62044, 0x6F776E00, 0x82628358, 0x83658342, 0x8362834E, 0x89BA0000, 0x83A62043,
    0x20537469, 0x636B2055, 0x70000000, 0x83A62055, 0x70000000, 0x82628358, 0x83658342, 0x8362834E,
    0x8FE30000, 0x4C204275, 0x74746F6E, 0x0, 0x83A12000, 0x826B8367, 0x838A834B, 0x815B837B,  /* fzgx-allow: A1 retail data bytes */
    0x835E8393, 0x0, 0x52204275, 0x74746F6E, 0x0, 0x2083AF20, 0x0, 0x82718367,
    0x838A834B, 0x815B837B, 0x835E8393, 0x0, (u32)lbl_4_data_1E60__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E7C__fzgx_offset_0, (u32)lbl_4_data_1E8C__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EB0__fzgx_offset_0,
    (u32)lbl_4_data_1EC0__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1EDC__fzgx_offset_0, (u32)lbl_4_data_1EEC__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0,
    (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F08__fzgx_offset_0, (u32)lbl_4_data_1F18__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0,
    (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F28__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1F34__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0,
    (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F44__fzgx_offset_0, (u32)lbl_4_data_1F50__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F60__fzgx_offset_0,
    (u32)lbl_4_data_1F6C__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F7C__fzgx_offset_0, (u32)lbl_4_data_1F88__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0,
    (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F98__fzgx_offset_0, (u32)lbl_4_data_1FA4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1FBC__fzgx_offset_0, (u32)lbl_4_data_1FD8__fzgx_offset_0, (u32)lbl_4_data_1FF0__fzgx_offset_0, (u32)lbl_4_data_1FF0__fzgx_offset_0, (u32)lbl_4_data_1FF0__fzgx_offset_0, (u32)lbl_4_data_1FF0__fzgx_offset_0, (u32)lbl_4_data_1FFC__fzgx_offset_0,
    (u32)lbl_4_data_2018__fzgx_offset_0, (u32)lbl_4_data_2030__fzgx_offset_0, (u32)lbl_4_data_2030__fzgx_offset_0, (u32)lbl_4_data_2030__fzgx_offset_0, (u32)lbl_4_data_2030__fzgx_offset_0, (u32)lbl_4_data_2038__fzgx_offset_0, (u32)lbl_4_data_2054__fzgx_offset_0, (u32)lbl_4_data_2068__fzgx_offset_0,
    (u32)lbl_4_data_2068__fzgx_offset_0, (u32)lbl_4_data_2068__fzgx_offset_0, (u32)lbl_4_data_2068__fzgx_offset_0, (u32)lbl_4_data_2070__fzgx_offset_0, (u32)lbl_4_data_208C__fzgx_offset_0, (u32)lbl_4_data_209C__fzgx_offset_0, (u32)lbl_4_data_209C__fzgx_offset_0, (u32)lbl_4_data_209C__fzgx_offset_0,
    (u32)lbl_4_data_209C__fzgx_offset_0, (u32)lbl_4_data_20A4__fzgx_offset_0, (u32)lbl_4_data_20B4__fzgx_offset_0, (u32)lbl_4_data_20C8__fzgx_offset_0, (u32)lbl_4_data_20C8__fzgx_offset_0, (u32)lbl_4_data_20C8__fzgx_offset_0, (u32)lbl_4_data_20C8__fzgx_offset_0, (u32)lbl_4_data_20D4__fzgx_offset_0,
    (u32)lbl_4_data_20E4__fzgx_offset_0, (u32)lbl_4_data_20F4__fzgx_offset_0, (u32)lbl_4_data_20F4__fzgx_offset_0, (u32)lbl_4_data_20F4__fzgx_offset_0, (u32)lbl_4_data_20F4__fzgx_offset_0, (u32)lbl_4_data_20FC__fzgx_offset_0, (u32)lbl_4_data_210C__fzgx_offset_0, (u32)lbl_4_data_211C__fzgx_offset_0,
    (u32)lbl_4_data_211C__fzgx_offset_0, (u32)lbl_4_data_211C__fzgx_offset_0, (u32)lbl_4_data_211C__fzgx_offset_0, (u32)lbl_4_data_2124__fzgx_offset_0, (u32)lbl_4_data_2134__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0,
    (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2144__fzgx_offset_0, (u32)lbl_4_data_2158__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_216C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1ADC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AE8__fzgx_offset_0, 0x53746565, 0x72696E67, 0x20576865, 0x656C204C,
    0x65667400, 0x836E8393, 0x8368838B, 0x8DB60000, 0x53746565, 0x72696E67, 0x20576865, 0x656C2052,
    0x69676874, 0x0, 0x836E8393, 0x8368838B, 0x89450000, 0x41636365, 0x6C657261, 0x746F7220,
    0x50656461, 0x6C000000, 0x8341834E, 0x835A838B, 0x8379835F, 0x838B0000, 0x4272616B, 0x65205065,
    0x64616C00, 0x8375838C, 0x815B834C, 0x8379835F, 0x838B0000, (u32)lbl_4_data_1E60__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E7C__fzgx_offset_0, (u32)lbl_4_data_1E8C__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0,
    (u32)lbl_4_data_1EB0__fzgx_offset_0, (u32)lbl_4_data_1EC0__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1EDC__fzgx_offset_0, (u32)lbl_4_data_1EEC__fzgx_offset_0,
    (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F08__fzgx_offset_0, (u32)lbl_4_data_1F18__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0,
    (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F28__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1F34__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0,
    (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F44__fzgx_offset_0, (u32)lbl_4_data_1F50__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0,
    (u32)lbl_4_data_1F60__fzgx_offset_0, (u32)lbl_4_data_1F6C__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F7C__fzgx_offset_0, (u32)lbl_4_data_1F88__fzgx_offset_0,
    (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F98__fzgx_offset_0, (u32)lbl_4_data_2480__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2494__fzgx_offset_0, (u32)lbl_4_data_24A0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_24B8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2134__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0,
    (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2144__fzgx_offset_0, (u32)lbl_4_data_2158__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0,
    (u32)lbl_4_data_216C__fzgx_offset_0, (u32)lbl_4_data_24C4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_24D8__fzgx_offset_0, (u32)lbl_4_data_24E8__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_24F4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1ADC__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AE8__fzgx_offset_0, 0x41582043, 0x6F6E7472, 0x6F6C7300,
    0x82608277, 0x82CC9180, 0x8DEC0000, (u32)lbl_4_data_2804__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_2810__fzgx_offset_0, 0x44656661, 0x756C7420, 0x53657474, 0x696E6773, 0x0, 0x8F898AFA, 0x90DD92E8,
    0x82C996DF, 0x82B70000, (u32)lbl_4_data_2834__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2848__fzgx_offset_0,
    0x53696465, 0x20417474, 0x61636B3A, 0x51756963, 0x6B6C7920, 0x70726573, 0x73207468, 0x65204C20,
    0x6F722052, 0x20427574, 0x746F6E0A, 0x20202020, 0x20202020, 0x20202020, 0x20202074, 0x77696365,
    0x2E0A5370, 0x696E2041, 0x74746163, 0x6B3A5072, 0x65737320, 0x74686520, 0x4C20616E, 0x64205220,
    0x42757474, 0x6F6E730A, 0x20202020, 0x20202020, 0x20202020, 0x20202073, 0x696D756C, 0x74616E65,
    0x6F75736C, 0x7920616E, 0x64207475, 0x726E2074, 0x68652077, 0x6865656C, 0x2E200000, 0x83548343,
    0x83688341, 0x835E8362, 0x834E8163, 0x8367838A, 0x834B815B, 0x825189F1, 0x88F882AB, 0xA835883,
    0x73839383, 0x41835E83, 0x62834E81, 0x63836783, 0x8A834B81, 0x5B826B82, 0x7197BC88, 0xF882AB81,
    0x95836E83, 0x93836883, 0x8B000000, (u32)lbl_4_data_2870__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_290C__fzgx_offset_0, (u32)fn_4_4B74__fzgx_offset_68, (u32)fn_4_4B74__fzgx_offset_7C, (u32)fn_4_4B74__fzgx_offset_94, (u32)fn_4_4B74__fzgx_offset_AC, (u32)fn_4_4B74__fzgx_offset_C4, (u32)fn_4_4B74__fzgx_offset_DC, (u32)fn_4_4B74__fzgx_offset_F4,
    (u32)fn_4_4B74__fzgx_offset_10C, (u32)fn_4_4B74__fzgx_offset_124, (u32)fn_4_4CB8__fzgx_offset_6C, (u32)fn_4_4CB8__fzgx_offset_80, (u32)fn_4_4CB8__fzgx_offset_98, (u32)fn_4_4CB8__fzgx_offset_B0, (u32)fn_4_4CB8__fzgx_offset_C8, (u32)fn_4_4CB8__fzgx_offset_E0,
    (u32)fn_4_4CB8__fzgx_offset_F8, (u32)fn_4_4CB8__fzgx_offset_110, (u32)fn_4_4CB8__fzgx_offset_128, 0x25732573, 0xA000000, 0x25730A00, 0x25738163, 0x25730000,
    (u32)fn_4_4DF8__fzgx_offset_1428, (u32)fn_4_4DF8__fzgx_offset_1408, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454,
    (u32)fn_4_4DF8__fzgx_offset_1308, (u32)fn_4_4DF8__fzgx_offset_12E4, (u32)fn_4_4DF8__fzgx_offset_13E0, (u32)fn_4_4DF8__fzgx_offset_13C0, (u32)fn_4_4DF8__fzgx_offset_1398, (u32)fn_4_4DF8__fzgx_offset_1378, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454,
    (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1350, (u32)fn_4_4DF8__fzgx_offset_1330, (u32)fn_4_4DF8__fzgx_offset_1330, (u32)fn_4_4DF8__fzgx_offset_1330, (u32)fn_4_4DF8__fzgx_offset_1330, (u32)fn_4_4DF8__fzgx_offset_E54, (u32)fn_4_4DF8__fzgx_offset_E34,
    (u32)fn_4_4DF8__fzgx_offset_E14, (u32)fn_4_4DF8__fzgx_offset_E14, (u32)fn_4_4DF8__fzgx_offset_E14, (u32)fn_4_4DF8__fzgx_offset_E14, (u32)fn_4_4DF8__fzgx_offset_DF4, (u32)fn_4_4DF8__fzgx_offset_DF4, (u32)fn_4_4DF8__fzgx_offset_DF4, (u32)fn_4_4DF8__fzgx_offset_DF4,
    (u32)fn_4_4DF8__fzgx_offset_DD4, (u32)fn_4_4DF8__fzgx_offset_DB4, (u32)fn_4_4DF8__fzgx_offset_D8C, (u32)fn_4_4DF8__fzgx_offset_D6C, (u32)fn_4_4DF8__fzgx_offset_E80, (u32)fn_4_4DF8__fzgx_offset_E80, (u32)fn_4_4DF8__fzgx_offset_E80, (u32)fn_4_4DF8__fzgx_offset_D4C,
    (u32)fn_4_4DF8__fzgx_offset_D2C, (u32)fn_4_4DF8__fzgx_offset_D2C, (u32)fn_4_4DF8__fzgx_offset_D2C, (u32)fn_4_4DF8__fzgx_offset_D2C, (u32)fn_4_4DF8__fzgx_offset_930, (u32)fn_4_4DF8__fzgx_offset_940, (u32)fn_4_4DF8__fzgx_offset_954, (u32)fn_4_4DF8__fzgx_offset_968,
    (u32)fn_4_4DF8__fzgx_offset_97C, (u32)fn_4_4DF8__fzgx_offset_990, (u32)fn_4_4DF8__fzgx_offset_9A4, (u32)fn_4_4DF8__fzgx_offset_9B8, (u32)fn_4_4DF8__fzgx_offset_9CC, (u32)fn_4_4DF8__fzgx_offset_3E4, (u32)fn_4_4DF8__fzgx_offset_3F4, (u32)fn_4_4DF8__fzgx_offset_408,
    (u32)fn_4_4DF8__fzgx_offset_41C, (u32)fn_4_4DF8__fzgx_offset_430, (u32)fn_4_4DF8__fzgx_offset_444, (u32)fn_4_4DF8__fzgx_offset_458, (u32)fn_4_4DF8__fzgx_offset_46C, (u32)fn_4_4DF8__fzgx_offset_480, (u32)fn_4_63D4__fzgx_offset_94, (u32)fn_4_63D4__fzgx_offset_F8,
    (u32)fn_4_63D4__fzgx_offset_150, (u32)fn_4_63D4__fzgx_offset_170, (u32)fn_4_63D4__fzgx_offset_170, (u32)fn_4_63D4__fzgx_offset_190, (u32)fn_4_63D4__fzgx_offset_1C0, (u32)fn_4_63D4__fzgx_offset_1F0, 0x6F707469, 0x6F6E5F70,
    0x63757374, 0x5F646973, 0x70000000, (u32)fn_4_6720__fzgx_offset_C94, (u32)fn_4_6720__fzgx_offset_CA4, (u32)fn_4_6720__fzgx_offset_CB8, (u32)fn_4_6720__fzgx_offset_CCC, (u32)fn_4_6720__fzgx_offset_CE0,
    (u32)fn_4_6720__fzgx_offset_CF4, (u32)fn_4_6720__fzgx_offset_D08, (u32)fn_4_6720__fzgx_offset_D1C, (u32)fn_4_6720__fzgx_offset_D30, (u32)fn_4_6720__fzgx_offset_B48, (u32)fn_4_6720__fzgx_offset_B58, (u32)fn_4_6720__fzgx_offset_B6C, (u32)fn_4_6720__fzgx_offset_B80,
    (u32)fn_4_6720__fzgx_offset_B94, (u32)fn_4_6720__fzgx_offset_BA8, (u32)fn_4_6720__fzgx_offset_BBC, (u32)fn_4_6720__fzgx_offset_BD0, (u32)fn_4_6720__fzgx_offset_BE4, (u32)fn_4_6720__fzgx_offset_93C, (u32)fn_4_6720__fzgx_offset_94C, (u32)fn_4_6720__fzgx_offset_960,
    (u32)fn_4_6720__fzgx_offset_974, (u32)fn_4_6720__fzgx_offset_988, (u32)fn_4_6720__fzgx_offset_99C, (u32)fn_4_6720__fzgx_offset_9B0, (u32)fn_4_6720__fzgx_offset_9C4, (u32)fn_4_6720__fzgx_offset_9D8, (u32)fn_4_6720__fzgx_offset_710, (u32)fn_4_6720__fzgx_offset_720,
    (u32)fn_4_6720__fzgx_offset_734, (u32)fn_4_6720__fzgx_offset_748, (u32)fn_4_6720__fzgx_offset_75C, (u32)fn_4_6720__fzgx_offset_770, (u32)fn_4_6720__fzgx_offset_784, (u32)fn_4_6720__fzgx_offset_798, (u32)fn_4_6720__fzgx_offset_7AC, (u32)fn_4_6720__fzgx_offset_5E4,
    (u32)fn_4_6720__fzgx_offset_5F4, (u32)fn_4_6720__fzgx_offset_608, (u32)fn_4_6720__fzgx_offset_61C, (u32)fn_4_6720__fzgx_offset_630, (u32)fn_4_6720__fzgx_offset_644, (u32)fn_4_6720__fzgx_offset_658, (u32)fn_4_6720__fzgx_offset_66C, (u32)fn_4_6720__fzgx_offset_680,
    (u32)fn_4_6720__fzgx_offset_404, (u32)fn_4_6720__fzgx_offset_414, (u32)fn_4_6720__fzgx_offset_428, (u32)fn_4_6720__fzgx_offset_43C, (u32)fn_4_6720__fzgx_offset_450, (u32)fn_4_6720__fzgx_offset_464, (u32)fn_4_6720__fzgx_offset_478, (u32)fn_4_6720__fzgx_offset_48C,
    (u32)fn_4_6720__fzgx_offset_4A0, (u32)fn_4_6720__fzgx_offset_98, (u32)fn_4_6720__fzgx_offset_148, (u32)fn_4_6720__fzgx_offset_298, (u32)fn_4_6720__fzgx_offset_540, (u32)fn_4_6720__fzgx_offset_D6C, (u32)fn_4_6720__fzgx_offset_E8C, (u32)fn_4_6720__fzgx_offset_1038,
    (u32)fn_4_6720__fzgx_offset_1114, 0x43616C69, 0x62726174, 0x696F6E00, 0x834C8383, 0x838A8375, 0x838C815B, 0x83568387,
    0x83930000, 0x43757374, 0x6F6D697A, 0x65000000, 0x834A8358, 0x835E837D, 0x83438359, 0x0,
    0x436F6E74, 0x726F6C6C, 0x65722052, 0x756D626C, 0x65000000, 0x83528393, 0x8367838D, 0x815B8389,  /* fzgx-allow: A1 retail data bytes */
    0x905593AE, 0x0
}};
static union { u32 w[21]; OptionRow v[3]; } fzgx_pool_init_lbl_4_data_2C58 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x500000, (u32)lbl_4_data_2BF4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2C00__fzgx_offset_0, 0x520000,
    (u32)lbl_4_data_2C14__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2C20__fzgx_offset_0, 0x510000, (u32)lbl_4_data_2C30__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2C44__fzgx_offset_0
}};

/* Screen y of a menu row (rows are 24 pixels apart, centred on 240). */
static inline u32 row_y(u32 row) {
    return (row - 2) * 24 + 240;
}

extern s32 lbl_801A66B4;
extern u8 lbl_4_bss_C;
extern s16 lbl_1_bss_962;
extern FontDrawPacket lbl_1_rodata_26F8;

extern void fn_1_49410(void);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_53E40(f32, f32, f32, f32, f32, s32, void *);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern f32 fn_1_4B040(char *);
extern f32 lbl_8006D188(s16);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern void fn_1_1380F0(void *);
extern void fn_1_13ABA8(u32);
extern void fn_1_5233C(void);

/* Draws the option rows from `i` on and returns the widest text. */
typedef struct RowCounter { u32 value; } RowCounter;
static inline f32 draw_rows(u32 i, RowCounter *row, OptionRow **entry) {
    f32 width;
    f32 w;

    width = 0.0f;
    *entry = fzgx_pool_init_lbl_4_data_2C58.v;
    for (row->value = i * 2; i < 3; i++, row->value += 2, (*entry)++) {
        fn_1_496FC(320.0f, (f32)row_y(row->value));
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(0.5f);
        }
        fn_1_4AE0C(fzgx_pool_init_lbl_4_data_1210.v, (*entry)->text[lbl_801A66B4]);
        w = fn_1_4B040((*entry)->text[lbl_801A66B4]);
        if (w > width) {
            width = w;
        }
    }
    return width;
}

static inline f64 fn_4_7938_operand(f32 right, f64 left) { left += right; return left; }
static inline f64 fn_4_7938_operand_(f64 right, f64 left) { return left + right; }
void fn_4_7938(void) {
    u32 i;
    RowCounter row;
    struct { u32 value; } cursor;
    OptionRow *entry;
    f32 width;
    f32 w;
    FontDrawPacket packet;
    f32 height;
    f64 base;
    f64 margin;

    fn_1_49410();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    fn_1_53E40(320.0f, 110.0f, 0.05f, 48.0f, 1.0f, 0, fzgx_pool_init_lbl_4_data_958.v[lbl_801A66B4]);

    cursor.value = lbl_4_bss_C;
    fn_1_49410();
    fn_1_495C8(9);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);

    width = draw_rows(0, &row, &entry);

    if (lbl_4_data_11AC__fzgx_offset_60 != cursor.value || lbl_4_data_11AC__fzgx_offset_62 != lbl_1_bss_962) {
        lbl_4_bss_2 = 0;
        lbl_4_data_11AC__fzgx_offset_60 = cursor.value;
        lbl_4_data_11AC__fzgx_offset_62 = lbl_1_bss_962;
    }

    packet = lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = 320.0f;
    packet.y = (f32)((cursor.value * 2 - 2) * 24 + 240);
    packet.z = 0.15f;
    packet.scale_x = (fn_4_7938_operand_((78.0), (width))) / 8.0;
    packet.scale_y = 3.5f;
    packet.flags = 10;
    packet.alpha = 0.3 * (1.0 + lbl_8006D188((s16)((lbl_4_bss_2 << 10) + 0x4000)));
    *(Color4 *)packet.color = *(const Color4 *)fzgx_pool_init_fzgx_pool_table2.v;
    fn_1_4F734(&packet);

    height = *(const f32 *)fzgx_pool_120;
    base = 48.0;
    margin = 96.0;
    fn_1_53BD8(0, 320.0f, 240.0f, margin + width, base + height, 0.25f);
    fn_1_1380F0(fzgx_pool_init_lbl_4_data_E8.v[lbl_801A66B4]);
    fn_1_13ABA8(0x28000000);
}
/* fzgx:end fn_4_7938 */

/* fzgx:begin fn_4_7C38 noprologue */
#include "types.h"

extern struct fn_4_7C38_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 lbl_4_data_2CAC;
extern void fn_4_7938(void);

struct fn_4_7C38_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
};

void fn_4_7C38(void) {
    struct fn_4_7C38_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t1;
    p_lbl_4_bss_0 = (struct fn_4_7C38_lbl_4_bss_0 *)&lbl_4_bss_0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_2CAC, (u32)fn_4_7938, 0, 5);
    p_lbl_4_bss_0->unk_0 = t1;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_7C38 */

/* fzgx:begin fn_4_7CA4 */
extern int fn_1_4C10(void);
extern u16 lbl_1_bss_96A;
extern u32 fn_4_0(u32, u32, u32, u32, u32);

extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);

struct fn_4_7CA4_lbl_4_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 unk_C;
    u8 pad_D[0x3];
    u16 unk_10;
};

extern u32 fn_1_4A00(u32, u32, u32);

void fn_4_7CA4(void) {
    struct fn_4_7CA4_lbl_4_bss_0 *option_state;
    u32 result;
    u32 availability, selected_mode, notification_result;

    /* Apply pending option changes, then update the active option state. */
    option_state = (struct fn_4_7CA4_lbl_4_bss_0 *)&lbl_4_bss_0;
    if (option_state->unk_10 != 0) {
        availability = fn_1_4C10();
        result = availability;
        if ((s32)result != 0) {
            return;
        }
        result = 1;
        fn_1_1280(result);
        lbl_1_bss_96A = option_state->unk_10;
        option_state->unk_10 = 0;
        return;
    }
    result = option_state->unk_C;
    selected_mode = fn_4_0(result, 0, 2, -1, 0);
    result = selected_mode;
    option_state->unk_C = result;
    result = (u32)&lbl_1_bss_9F8;
    result = *(u16 *)((u8 *)result + 8);
    if (((result >> 9) & 0x1) != 0) {
        result = 0xA9010000;
        result += 512;
        fn_1_A2D84(result);
        option_state->unk_10 = 75;
    } else {
        if (((result >> 8) & 0x1) != 0) {
            result = 0xA9010000;
            result += 256;
            fn_1_A2D84(result);
            result = (u32)&lbl_4_data_2C58;
            option_state->unk_10 = *(s16 *)((u8 *)result + (option_state->unk_C * 28));
        } else {
            return;
        }
    }
    result = 0;
    notification_result = fn_1_4A00(result, 15, option_state->unk_8);
    result = notification_result;
}
/* fzgx:end fn_4_7CA4 */

/* fzgx:begin fn_4_7D94 */
extern u32 fn_1_435C(u32);

// Reset the option subsystem after releasing its active resource.
void fn_4_7D94(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_7D94 */

/* fzgx:begin fn_4_7DEC noprologue */
#include "types.h"
#include "font.h"
#include "rel/option/globals.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 167.0f;
    s = 38.0f;
    s = 0.5f;
}
extern u8 fn_4_347C__fzgx_offset_0[];
extern u8 fn_4_3568__fzgx_offset_0[];
extern u8 fn_4_406C__fzgx_offset_0[];
extern u8 fn_4_4784__fzgx_offset_0[];
extern u8 fn_4_4834__fzgx_offset_0[];
extern u8 fn_4_4B10__fzgx_offset_0[];
extern u8 fn_4_4B74__fzgx_offset_10C[];
extern u8 fn_4_4B74__fzgx_offset_124[];
extern u8 fn_4_4B74__fzgx_offset_68[];
extern u8 fn_4_4B74__fzgx_offset_7C[];
extern u8 fn_4_4B74__fzgx_offset_94[];
extern u8 fn_4_4B74__fzgx_offset_AC[];
extern u8 fn_4_4B74__fzgx_offset_C4[];
extern u8 fn_4_4B74__fzgx_offset_DC[];
extern u8 fn_4_4B74__fzgx_offset_F4[];
extern u8 fn_4_4CB8__fzgx_offset_110[];
extern u8 fn_4_4CB8__fzgx_offset_128[];
extern u8 fn_4_4CB8__fzgx_offset_6C[];
extern u8 fn_4_4CB8__fzgx_offset_80[];
extern u8 fn_4_4CB8__fzgx_offset_98[];
extern u8 fn_4_4CB8__fzgx_offset_B0[];
extern u8 fn_4_4CB8__fzgx_offset_C8[];
extern u8 fn_4_4CB8__fzgx_offset_E0[];
extern u8 fn_4_4CB8__fzgx_offset_F8[];
extern u8 fn_4_4DF8__fzgx_offset_12E4[];
extern u8 fn_4_4DF8__fzgx_offset_1308[];
extern u8 fn_4_4DF8__fzgx_offset_1330[];
extern u8 fn_4_4DF8__fzgx_offset_1350[];
extern u8 fn_4_4DF8__fzgx_offset_1378[];
extern u8 fn_4_4DF8__fzgx_offset_1398[];
extern u8 fn_4_4DF8__fzgx_offset_13C0[];
extern u8 fn_4_4DF8__fzgx_offset_13E0[];
extern u8 fn_4_4DF8__fzgx_offset_1408[];
extern u8 fn_4_4DF8__fzgx_offset_1428[];
extern u8 fn_4_4DF8__fzgx_offset_1454[];
extern u8 fn_4_4DF8__fzgx_offset_3E4[];
extern u8 fn_4_4DF8__fzgx_offset_3F4[];
extern u8 fn_4_4DF8__fzgx_offset_408[];
extern u8 fn_4_4DF8__fzgx_offset_41C[];
extern u8 fn_4_4DF8__fzgx_offset_430[];
extern u8 fn_4_4DF8__fzgx_offset_444[];
extern u8 fn_4_4DF8__fzgx_offset_458[];
extern u8 fn_4_4DF8__fzgx_offset_46C[];
extern u8 fn_4_4DF8__fzgx_offset_480[];
extern u8 fn_4_4DF8__fzgx_offset_930[];
extern u8 fn_4_4DF8__fzgx_offset_940[];
extern u8 fn_4_4DF8__fzgx_offset_954[];
extern u8 fn_4_4DF8__fzgx_offset_968[];
extern u8 fn_4_4DF8__fzgx_offset_97C[];
extern u8 fn_4_4DF8__fzgx_offset_990[];
extern u8 fn_4_4DF8__fzgx_offset_9A4[];
extern u8 fn_4_4DF8__fzgx_offset_9B8[];
extern u8 fn_4_4DF8__fzgx_offset_9CC[];
extern u8 fn_4_4DF8__fzgx_offset_D2C[];
extern u8 fn_4_4DF8__fzgx_offset_D4C[];
extern u8 fn_4_4DF8__fzgx_offset_D6C[];
extern u8 fn_4_4DF8__fzgx_offset_D8C[];
extern u8 fn_4_4DF8__fzgx_offset_DB4[];
extern u8 fn_4_4DF8__fzgx_offset_DD4[];
extern u8 fn_4_4DF8__fzgx_offset_DF4[];
extern u8 fn_4_4DF8__fzgx_offset_E14[];
extern u8 fn_4_4DF8__fzgx_offset_E34[];
extern u8 fn_4_4DF8__fzgx_offset_E54[];
extern u8 fn_4_4DF8__fzgx_offset_E80[];
extern u8 fn_4_63D4__fzgx_offset_150[];
extern u8 fn_4_63D4__fzgx_offset_170[];
extern u8 fn_4_63D4__fzgx_offset_190[];
extern u8 fn_4_63D4__fzgx_offset_1C0[];
extern u8 fn_4_63D4__fzgx_offset_1F0[];
extern u8 fn_4_63D4__fzgx_offset_94[];
extern u8 fn_4_63D4__fzgx_offset_F8[];
extern u8 fn_4_6678__fzgx_offset_0[];
extern u8 fn_4_6720__fzgx_offset_0[];
extern u8 fn_4_6720__fzgx_offset_1038[];
extern u8 fn_4_6720__fzgx_offset_1114[];
extern u8 fn_4_6720__fzgx_offset_148[];
extern u8 fn_4_6720__fzgx_offset_298[];
extern u8 fn_4_6720__fzgx_offset_404[];
extern u8 fn_4_6720__fzgx_offset_414[];
extern u8 fn_4_6720__fzgx_offset_428[];
extern u8 fn_4_6720__fzgx_offset_43C[];
extern u8 fn_4_6720__fzgx_offset_450[];
extern u8 fn_4_6720__fzgx_offset_464[];
extern u8 fn_4_6720__fzgx_offset_478[];
extern u8 fn_4_6720__fzgx_offset_48C[];
extern u8 fn_4_6720__fzgx_offset_4A0[];
extern u8 fn_4_6720__fzgx_offset_540[];
extern u8 fn_4_6720__fzgx_offset_5E4[];
extern u8 fn_4_6720__fzgx_offset_5F4[];
extern u8 fn_4_6720__fzgx_offset_608[];
extern u8 fn_4_6720__fzgx_offset_61C[];
extern u8 fn_4_6720__fzgx_offset_630[];
extern u8 fn_4_6720__fzgx_offset_644[];
extern u8 fn_4_6720__fzgx_offset_658[];
extern u8 fn_4_6720__fzgx_offset_66C[];
extern u8 fn_4_6720__fzgx_offset_680[];
extern u8 fn_4_6720__fzgx_offset_710[];
extern u8 fn_4_6720__fzgx_offset_720[];
extern u8 fn_4_6720__fzgx_offset_734[];
extern u8 fn_4_6720__fzgx_offset_748[];
extern u8 fn_4_6720__fzgx_offset_75C[];
extern u8 fn_4_6720__fzgx_offset_770[];
extern u8 fn_4_6720__fzgx_offset_784[];
extern u8 fn_4_6720__fzgx_offset_798[];
extern u8 fn_4_6720__fzgx_offset_7AC[];
extern u8 fn_4_6720__fzgx_offset_93C[];
extern u8 fn_4_6720__fzgx_offset_94C[];
extern u8 fn_4_6720__fzgx_offset_960[];
extern u8 fn_4_6720__fzgx_offset_974[];
extern u8 fn_4_6720__fzgx_offset_988[];
extern u8 fn_4_6720__fzgx_offset_98[];
extern u8 fn_4_6720__fzgx_offset_99C[];
extern u8 fn_4_6720__fzgx_offset_9B0[];
extern u8 fn_4_6720__fzgx_offset_9C4[];
extern u8 fn_4_6720__fzgx_offset_9D8[];
extern u8 fn_4_6720__fzgx_offset_B48[];
extern u8 fn_4_6720__fzgx_offset_B58[];
extern u8 fn_4_6720__fzgx_offset_B6C[];
extern u8 fn_4_6720__fzgx_offset_B80[];
extern u8 fn_4_6720__fzgx_offset_B94[];
extern u8 fn_4_6720__fzgx_offset_BA8[];
extern u8 fn_4_6720__fzgx_offset_BBC[];
extern u8 fn_4_6720__fzgx_offset_BD0[];
extern u8 fn_4_6720__fzgx_offset_BE4[];
extern u8 fn_4_6720__fzgx_offset_C94[];
extern u8 fn_4_6720__fzgx_offset_CA4[];
extern u8 fn_4_6720__fzgx_offset_CB8[];
extern u8 fn_4_6720__fzgx_offset_CCC[];
extern u8 fn_4_6720__fzgx_offset_CE0[];
extern u8 fn_4_6720__fzgx_offset_CF4[];
extern u8 fn_4_6720__fzgx_offset_D08[];
extern u8 fn_4_6720__fzgx_offset_D1C[];
extern u8 fn_4_6720__fzgx_offset_D30[];
extern u8 fn_4_6720__fzgx_offset_D6C[];
extern u8 fn_4_6720__fzgx_offset_E8C[];
extern u8 fn_4_78E0__fzgx_offset_0[];
extern u8 fn_4_7C38__fzgx_offset_0[];
extern u8 fn_4_7CA4__fzgx_offset_0[];
extern u8 fn_4_7D94__fzgx_offset_0[];
extern u8 fn_4_80EC__fzgx_offset_0[];
extern u8 fn_4_8158__fzgx_offset_0[];
extern u8 fn_4_8248__fzgx_offset_0[];
extern u8 fn_4_869C__fzgx_offset_0[];
extern u8 fn_4_8720__fzgx_offset_0[];
extern u8 fn_4_898C__fzgx_offset_0[];
extern u8 fn_4_89E4__fzgx_offset_0[];
extern u8 fn_4_8A54__fzgx_offset_0[];
extern u8 fn_4_8AE0__fzgx_offset_0[];
extern u8 fn_4_8DC0__fzgx_offset_0[];
extern u8 fn_4_8E38__fzgx_offset_0[];
extern u8 fn_4_9A78__fzgx_offset_0[];
extern u8 fn_4_9B20__fzgx_offset_0[];
extern u8 fn_4_9C14__fzgx_offset_0[];
extern u8 fn_4_A734__fzgx_offset_0[];
extern u8 fn_4_D10__fzgx_offset_0[];
extern u8 fn_4_D7C__fzgx_offset_0[];
extern u8 fn_4_EA0__fzgx_offset_0[];
extern u8 lbl_4_data_0__fzgx_offset_0[];
extern u8 lbl_4_data_100__fzgx_offset_0[];
extern u8 lbl_4_data_107C__fzgx_offset_0[];
extern u8 lbl_4_data_10A0__fzgx_offset_0[];
extern u8 lbl_4_data_10E8__fzgx_offset_0[];
extern u8 lbl_4_data_10__fzgx_offset_0[];
extern u8 lbl_4_data_111C__fzgx_offset_0[];
extern u8 lbl_4_data_116C__fzgx_offset_0[];
extern u8 lbl_4_data_11AC__fzgx_offset_0[];
extern u8 lbl_4_data_130__fzgx_offset_0[];
extern u8 lbl_4_data_1418__fzgx_offset_0[];
extern u8 lbl_4_data_1424__fzgx_offset_0[];
extern u8 lbl_4_data_1434__fzgx_offset_0[];
extern u8 lbl_4_data_1440__fzgx_offset_0[];
extern u8 lbl_4_data_1534__fzgx_offset_0[];
extern u8 lbl_4_data_1544__fzgx_offset_0[];
extern u8 lbl_4_data_154C__fzgx_offset_0[];
extern u8 lbl_4_data_1558__fzgx_offset_0[];
extern u8 lbl_4_data_156C__fzgx_offset_0[];
extern u8 lbl_4_data_1588__fzgx_offset_0[];
extern u8 lbl_4_data_15AC__fzgx_offset_0[];
extern u8 lbl_4_data_15B4__fzgx_offset_0[];
extern u8 lbl_4_data_1660__fzgx_offset_0[];
extern u8 lbl_4_data_1678__fzgx_offset_0[];
extern u8 lbl_4_data_1688__fzgx_offset_0[];
extern u8 lbl_4_data_168C__fzgx_offset_0[];
extern u8 lbl_4_data_16A0__fzgx_offset_0[];
extern u8 lbl_4_data_16FC__fzgx_offset_0[];
extern u8 lbl_4_data_1704__fzgx_offset_0[];
extern u8 lbl_4_data_170__fzgx_offset_0[];
extern u8 lbl_4_data_1718__fzgx_offset_0[];
extern u8 lbl_4_data_172C__fzgx_offset_0[];
extern u8 lbl_4_data_1740__fzgx_offset_0[];
extern u8 lbl_4_data_175C__fzgx_offset_0[];
extern u8 lbl_4_data_1770__fzgx_offset_0[];
extern u8 lbl_4_data_177C__fzgx_offset_0[];
extern u8 lbl_4_data_1790__fzgx_offset_0[];
extern u8 lbl_4_data_179C__fzgx_offset_0[];
extern u8 lbl_4_data_17B0__fzgx_offset_0[];
extern u8 lbl_4_data_17BC__fzgx_offset_0[];
extern u8 lbl_4_data_17D0__fzgx_offset_0[];
extern u8 lbl_4_data_17DC__fzgx_offset_0[];
extern u8 lbl_4_data_17F0__fzgx_offset_0[];
extern u8 lbl_4_data_17FC__fzgx_offset_0[];
extern u8 lbl_4_data_1810__fzgx_offset_0[];
extern u8 lbl_4_data_1818__fzgx_offset_0[];
extern u8 lbl_4_data_188__fzgx_offset_0[];
extern u8 lbl_4_data_1904__fzgx_offset_0[];
extern u8 lbl_4_data_1924__fzgx_offset_0[];
extern u8 lbl_4_data_192C__fzgx_offset_0[];
extern u8 lbl_4_data_193C__fzgx_offset_0[];
extern u8 lbl_4_data_1958__fzgx_offset_0[];
extern u8 lbl_4_data_1960__fzgx_offset_0[];
extern u8 lbl_4_data_1970__fzgx_offset_0[];
extern u8 lbl_4_data_1980__fzgx_offset_0[];
extern u8 lbl_4_data_1988__fzgx_offset_0[];
extern u8 lbl_4_data_1998__fzgx_offset_0[];
extern u8 lbl_4_data_19A8__fzgx_offset_0[];
extern u8 lbl_4_data_19B0__fzgx_offset_0[];
extern u8 lbl_4_data_19C0__fzgx_offset_0[];
extern u8 lbl_4_data_19E0__fzgx_offset_0[];
extern u8 lbl_4_data_19E8__fzgx_offset_0[];
extern u8 lbl_4_data_1A04__fzgx_offset_0[];
extern u8 lbl_4_data_1A24__fzgx_offset_0[];
extern u8 lbl_4_data_1A2C__fzgx_offset_0[];
extern u8 lbl_4_data_1A48__fzgx_offset_0[];
extern u8 lbl_4_data_1A64__fzgx_offset_0[];
extern u8 lbl_4_data_1A6C__fzgx_offset_0[];
extern u8 lbl_4_data_1A80__fzgx_offset_0[];
extern u8 lbl_4_data_1A98__fzgx_offset_0[];
extern u8 lbl_4_data_1AA0__fzgx_offset_0[];
extern u8 lbl_4_data_1AB4__fzgx_offset_0[];
extern u8 lbl_4_data_1AC4__fzgx_offset_0[];
extern u8 lbl_4_data_1ADC__fzgx_offset_0[];
extern u8 lbl_4_data_1AE8__fzgx_offset_0[];
extern u8 lbl_4_data_1BC__fzgx_offset_0[];
extern u8 lbl_4_data_1C78__fzgx_offset_0[];
extern u8 lbl_4_data_1C98__fzgx_offset_0[];
extern u8 lbl_4_data_1CA8__fzgx_offset_0[];
extern u8 lbl_4_data_1CC4__fzgx_offset_0[];
extern u8 lbl_4_data_1E60__fzgx_offset_0[];
extern u8 lbl_4_data_1E74__fzgx_offset_0[];
extern u8 lbl_4_data_1E7C__fzgx_offset_0[];
extern u8 lbl_4_data_1E8C__fzgx_offset_0[];
extern u8 lbl_4_data_1EA4__fzgx_offset_0[];
extern u8 lbl_4_data_1EB0__fzgx_offset_0[];
extern u8 lbl_4_data_1EC0__fzgx_offset_0[];
extern u8 lbl_4_data_1ED4__fzgx_offset_0[];
extern u8 lbl_4_data_1EDC__fzgx_offset_0[];
extern u8 lbl_4_data_1EEC__fzgx_offset_0[];
extern u8 lbl_4_data_1F00__fzgx_offset_0[];
extern u8 lbl_4_data_1F08__fzgx_offset_0[];
extern u8 lbl_4_data_1F18__fzgx_offset_0[];
extern u8 lbl_4_data_1F24__fzgx_offset_0[];
extern u8 lbl_4_data_1F28__fzgx_offset_0[];
extern u8 lbl_4_data_1F34__fzgx_offset_0[];
extern u8 lbl_4_data_1F40__fzgx_offset_0[];
extern u8 lbl_4_data_1F44__fzgx_offset_0[];
extern u8 lbl_4_data_1F50__fzgx_offset_0[];
extern u8 lbl_4_data_1F5C__fzgx_offset_0[];
extern u8 lbl_4_data_1F60__fzgx_offset_0[];
extern u8 lbl_4_data_1F6C__fzgx_offset_0[];
extern u8 lbl_4_data_1F78__fzgx_offset_0[];
extern u8 lbl_4_data_1F7C__fzgx_offset_0[];
extern u8 lbl_4_data_1F88__fzgx_offset_0[];
extern u8 lbl_4_data_1F94__fzgx_offset_0[];
extern u8 lbl_4_data_1F98__fzgx_offset_0[];
extern u8 lbl_4_data_1FA4__fzgx_offset_0[];
extern u8 lbl_4_data_1FBC__fzgx_offset_0[];
extern u8 lbl_4_data_1FD8__fzgx_offset_0[];
extern u8 lbl_4_data_1FF0__fzgx_offset_0[];
extern u8 lbl_4_data_1FFC__fzgx_offset_0[];
extern u8 lbl_4_data_2018__fzgx_offset_0[];
extern u8 lbl_4_data_2030__fzgx_offset_0[];
extern u8 lbl_4_data_2038__fzgx_offset_0[];
extern u8 lbl_4_data_2054__fzgx_offset_0[];
extern u8 lbl_4_data_2068__fzgx_offset_0[];
extern u8 lbl_4_data_2070__fzgx_offset_0[];
extern u8 lbl_4_data_208C__fzgx_offset_0[];
extern u8 lbl_4_data_209C__fzgx_offset_0[];
extern u8 lbl_4_data_20A4__fzgx_offset_0[];
extern u8 lbl_4_data_20B4__fzgx_offset_0[];
extern u8 lbl_4_data_20C8__fzgx_offset_0[];
extern u8 lbl_4_data_20D4__fzgx_offset_0[];
extern u8 lbl_4_data_20E4__fzgx_offset_0[];
extern u8 lbl_4_data_20F4__fzgx_offset_0[];
extern u8 lbl_4_data_20FC__fzgx_offset_0[];
extern u8 lbl_4_data_210C__fzgx_offset_0[];
extern u8 lbl_4_data_210__fzgx_offset_0[];
extern u8 lbl_4_data_211C__fzgx_offset_0[];
extern u8 lbl_4_data_2124__fzgx_offset_0[];
extern u8 lbl_4_data_2134__fzgx_offset_0[];
extern u8 lbl_4_data_2140__fzgx_offset_0[];
extern u8 lbl_4_data_2144__fzgx_offset_0[];
extern u8 lbl_4_data_2158__fzgx_offset_0[];
extern u8 lbl_4_data_2164__fzgx_offset_0[];
extern u8 lbl_4_data_216C__fzgx_offset_0[];
extern u8 lbl_4_data_2480__fzgx_offset_0[];
extern u8 lbl_4_data_2494__fzgx_offset_0[];
extern u8 lbl_4_data_24A0__fzgx_offset_0[];
extern u8 lbl_4_data_24B8__fzgx_offset_0[];
extern u8 lbl_4_data_24C4__fzgx_offset_0[];
extern u8 lbl_4_data_24D8__fzgx_offset_0[];
extern u8 lbl_4_data_24E8__fzgx_offset_0[];
extern u8 lbl_4_data_24F4__fzgx_offset_0[];
extern u8 lbl_4_data_254__fzgx_offset_0[];
extern u8 lbl_4_data_2804__fzgx_offset_0[];
extern u8 lbl_4_data_2810__fzgx_offset_0[];
extern u8 lbl_4_data_2834__fzgx_offset_0[];
extern u8 lbl_4_data_2848__fzgx_offset_0[];
extern u8 lbl_4_data_284__fzgx_offset_0[];
extern u8 lbl_4_data_2870__fzgx_offset_0[];
extern u8 lbl_4_data_290C__fzgx_offset_0[];
extern u8 lbl_4_data_2BF4__fzgx_offset_0[];
extern u8 lbl_4_data_2C00__fzgx_offset_0[];
extern u8 lbl_4_data_2C14__fzgx_offset_0[];
extern u8 lbl_4_data_2C20__fzgx_offset_0[];
extern u8 lbl_4_data_2C30__fzgx_offset_0[];
extern u8 lbl_4_data_2C44__fzgx_offset_0[];
extern u8 lbl_4_data_2CC__fzgx_offset_0[];
extern u8 lbl_4_data_2F0__fzgx_offset_0[];
extern u8 lbl_4_data_32C__fzgx_offset_0[];
extern u8 lbl_4_data_34C__fzgx_offset_0[];
extern u8 lbl_4_data_37C__fzgx_offset_0[];
extern u8 lbl_4_data_38__fzgx_offset_0[];
extern u8 lbl_4_data_3B8__fzgx_offset_0[];
extern u8 lbl_4_data_400__fzgx_offset_0[];
extern u8 lbl_4_data_438__fzgx_offset_0[];
extern u8 lbl_4_data_480__fzgx_offset_0[];
extern u8 lbl_4_data_4C__fzgx_offset_0[];
extern u8 lbl_4_data_4F0__fzgx_offset_0[];
extern u8 lbl_4_data_578__fzgx_offset_0[];
extern u8 lbl_4_data_57C__fzgx_offset_0[];
extern u8 lbl_4_data_59C__fzgx_offset_0[];
extern u8 lbl_4_data_5A0__fzgx_offset_0[];
extern u8 lbl_4_data_5C0__fzgx_offset_0[];
extern u8 lbl_4_data_5D8__fzgx_offset_0[];
extern u8 lbl_4_data_610__fzgx_offset_0[];
extern u8 lbl_4_data_660__fzgx_offset_0[];
extern u8 lbl_4_data_6D4__fzgx_offset_0[];
extern u8 lbl_4_data_724__fzgx_offset_0[];
extern u8 lbl_4_data_78__fzgx_offset_0[];
extern u8 lbl_4_data_790__fzgx_offset_0[];
extern u8 lbl_4_data_7C__fzgx_offset_0[];
extern u8 lbl_4_data_7DC__fzgx_offset_0[];
extern u8 lbl_4_data_85C__fzgx_offset_0[];
extern u8 lbl_4_data_86C__fzgx_offset_0[];
extern u8 lbl_4_data_89C__fzgx_offset_0[];
extern u8 lbl_4_data_8A8__fzgx_offset_0[];
extern u8 lbl_4_data_8D8__fzgx_offset_0[];
extern u8 lbl_4_data_8F8__fzgx_offset_0[];
extern u8 lbl_4_data_918__fzgx_offset_0[];
extern u8 lbl_4_data_934__fzgx_offset_0[];
extern u8 lbl_4_data_970__fzgx_offset_0[];
extern u8 lbl_4_data_984__fzgx_offset_0[];
extern u8 lbl_4_data_9C0__fzgx_offset_0[];
extern u8 lbl_4_data_9D8__fzgx_offset_0[];
extern u8 lbl_4_data_A10__fzgx_offset_0[];
extern u8 lbl_4_data_A30__fzgx_offset_0[];
extern u8 lbl_4_data_A70__fzgx_offset_0[];
extern u8 lbl_4_data_A78__fzgx_offset_0[];
extern u8 lbl_4_data_AA0__fzgx_offset_0[];
extern u8 lbl_4_data_AAC__fzgx_offset_0[];
extern u8 lbl_4_data_AD4__fzgx_offset_0[];
extern u8 lbl_4_data_B0__fzgx_offset_0[];
extern u8 lbl_4_data_B90__fzgx_offset_0[];
extern u8 lbl_4_data_C18__fzgx_offset_0[];
extern u8 lbl_4_data_C8__fzgx_offset_0[];
extern u8 lbl_4_data_CB0__fzgx_offset_0[];
extern u8 lbl_4_data_C__fzgx_offset_0[];
extern u8 lbl_4_data_D50__fzgx_offset_0[];
extern u8 lbl_4_data_D64__fzgx_offset_0[];
extern u8 lbl_4_data_D84__fzgx_offset_0[];
extern u8 lbl_4_data_D98__fzgx_offset_0[];
extern u8 lbl_4_data_DB8__fzgx_offset_0[];
extern u8 lbl_4_data_DF0__fzgx_offset_0[];
extern u8 lbl_4_data_E48__fzgx_offset_0[];
extern u8 lbl_4_data_E58__fzgx_offset_0[];
extern u8 lbl_4_data_E88__fzgx_offset_0[];
extern u8 lbl_4_data_E98__fzgx_offset_0[];
extern u8 lbl_4_data_EC8__fzgx_offset_0[];
extern u8 lbl_4_data_F08__fzgx_offset_0[];
extern u8 lbl_4_data_F64__fzgx_offset_0[];
extern u8 lbl_4_data_FD8__fzgx_offset_0[];
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table2 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xD0D000
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table2.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 78.0;
    d = 0.125;
    s = 2.9375f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table4.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3;
    d = 1.0;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table6 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xD0D000
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table6.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6000000238418579f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFF000000
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table8.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.5f;
    s = 5.0f;
    s = 0.0f;
    s = 320.0f;
    s = 0.15000000596046448f;
    s = 240.0f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table10 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table10.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 96.0;
    d = 48.0;
    s = 0.25f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table12 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table12.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.004999999888241291f;
    s = 216.0f;
    d = 90.0;
    d = 320.0;
    d = 0.5;
    s = 264.0f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table14 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table14.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = -0.5;
    s = 0.014999999664723873f;
    s = 72.0f;
    s = 0.02500000037252903f;
    s = 0.05000000074505806f;
    s = 48.0f;
    s = 0.800000011920929f;
    s = 110.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_120[1] = { 0x42F00000 }; /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep120(void) { const u32 *volatile cp; cp = fzgx_pool_120; } /* fzgx-allow: S2 pool primer sink */
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table16 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x8080000
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table16.v; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

/* One menu row: a tag word followed by the row text per language. */
typedef struct OptionRow {
    u32 unk_0;
    char *text[6];
} OptionRow;

typedef struct Color4 {
    u8 c[4];
} Color4;

/* The module's .data objects, defined here so they share one section base. */
static union { u32 w[58]; u8 v[0xE8]; } fzgx_pool_init_fzgx_obj_lbl_4_data_0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x436F6E74, 0x726F6C6C, 0x65720000, 0x0, 0x83528393, 0x8367838D, 0x815B8389, 0x0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, 0x436F6E74, 0x726F6C6C,  /* fzgx-allow: A1 retail data bytes */
    0x65722053, 0x6F636B65, 0x74000000, 0x83528393, 0x8367838D, 0x815B8389, 0x837C815B, 0x83670000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_38__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_4C__fzgx_offset_0, 0x4F4E0000, 0x4F464600,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_78__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_78__fzgx_offset_0, (u32)lbl_4_data_7C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_7C__fzgx_offset_0, 0x0, 0x55736520, 0x83AD206F, 0x722083B5, 0x20746F20,  /* fzgx-allow: A1 retail data bytes */
    0x63686F6F, 0x73652E00, 0x83AD82A9, 0x83B582C5, 0x8D8096DA, 0x82F09149, 0x82F182C5, 0x82AD82BE,  /* fzgx-allow: A1 retail data bytes */
    0x82B382A2, 0x81420000  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[540]; void *v[(0x958 - 0xE8) / 4]; } fzgx_pool_init_lbl_4_data_E8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_B0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C8__fzgx_offset_0, 0x4D6F7665, 0x2083AD20,  /* fzgx-allow: A1 retail data bytes */
    0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063, 0x68616E67, 0x6520636F,  /* fzgx-allow: A1 retail data bytes */
    0x6E74726F, 0x6C732E00, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C59180, 0x8DEC82F0, 0x95CF8D58,  /* fzgx-allow: A1 retail data bytes */
    0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_100__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_130__fzgx_offset_0, 0x506C6561, 0x73652077, 0x61697420, 0x61206D6F, 0x6D656E74, 0x2E2E2E00,  /* fzgx-allow: A1 retail data bytes */
    0x82B582CE, 0x82E782AD, 0x82A891D2, 0x82BF82AD, 0x82BE82B3, 0x82A28142, 0x0, (u32)lbl_4_data_170__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_188__fzgx_offset_0, 0x50726573, 0x73207468, 0x65204120,  /* fzgx-allow: A1 retail data bytes */
    0x42757474, 0x6F6E206F, 0x6E207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0x20746F20, 0x62652061,  /* fzgx-allow: A1 retail data bytes */
    0x646A7573, 0x7465642E, 0x20507265, 0x73732074, 0x68652042, 0x20427574, 0x746F6E20, 0x746F2066,  /* fzgx-allow: A1 retail data bytes */
    0x696E6973, 0x682E0000, 0x95CF8D58, 0x82B782E9, 0x83528393, 0x8367838D, 0x815B8389, 0x82C5839F,  /* fzgx-allow: A1 retail data bytes */
    0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_1BC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_210__fzgx_offset_0, 0x526F7461, 0x74652074, 0x68652043, 0x6F6E7472, 0x6F6C2053,  /* fzgx-allow: A1 retail data bytes */
    0x7469636B, 0x206F6E65, 0x2066756C, 0x6C207265, 0x766F6C75, 0x74696F6E, 0x2E000000, 0x83528393,  /* fzgx-allow: A1 retail data bytes */
    0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E82F0, 0x88EA9474, 0x82C989F1, 0x82B582C4,  /* fzgx-allow: A1 retail data bytes */
    0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_254__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_284__fzgx_offset_0, 0x506C6561, 0x73652061, 0x646A7573, 0x74207468, 0x65207374, 0x65657269, 0x6E672077,  /* fzgx-allow: A1 retail data bytes */
    0x6865656C, 0x2E000000, 0x836E8393, 0x8368838B, 0x82CC92B2, 0x90AE82F0, 0x8D7382C8, 0x82C182C4,  /* fzgx-allow: A1 retail data bytes */
    0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_2CC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_2F0__fzgx_offset_0, 0x52657475, 0x726E2074, 0x6F207468, 0x65206465, 0x6661756C, 0x74207365, 0x7474696E,  /* fzgx-allow: A1 retail data bytes */
    0x67733F00, 0x8F898AFA, 0x90DD92E8, 0x82C996DF, 0x82B582DC, 0x82B782A9, 0x81480000, (u32)lbl_4_data_32C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_34C__fzgx_offset_0, 0x53656C65, 0x63742074, 0x68652043,  /* fzgx-allow: A1 retail data bytes */
    0x6F6E7472, 0x6F6C6C65, 0x7220746F, 0x20626520, 0x6368616E, 0x67656420, 0x7573696E, 0x67206569,  /* fzgx-allow: A1 retail data bytes */
    0x74686572, 0x2083AD20, 0x6F722083, 0xB52E0000, 0x83AD82A9, 0x83B582C5, 0x95CF8D58, 0x82B782E9,  /* fzgx-allow: A1 retail data bytes */
    0x83528393, 0x8367838D, 0x815B8389, 0x82F09149, 0x82F182C5, 0x82AD82BE, 0x82B382A2, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_37C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_3B8__fzgx_offset_0, 0x4D6F7665, 0x2083AD20,  /* fzgx-allow: A1 retail data bytes */
    0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063, 0x68616E67, 0x65205275,  /* fzgx-allow: A1 retail data bytes */
    0x6D626C65, 0x20736574, 0x74696E67, 0x732E0000, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C59055,  /* fzgx-allow: A1 retail data bytes */
    0x93AE82CC, 0x90DD92E8, 0x82F095CF, 0x8D5882B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0x0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_400__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_438__fzgx_offset_0, 0x54686520, 0x436F6E74,  /* fzgx-allow: A1 retail data bytes */
    0x726F6C6C, 0x65722068, 0x61732062, 0x65656E20, 0x64697363, 0x6F6E6E65, 0x63746564, 0x2E0A2052,  /* fzgx-allow: A1 retail data bytes */
    0x65636F6E, 0x6E656374, 0x20746865, 0x20436F6E, 0x74726F6C, 0x6C657220, 0x696E2053, 0x6F636B65,  /* fzgx-allow: A1 retail data bytes */
    0x74202564, 0x206F720A, 0x20707265, 0x73732074, 0x68652041, 0x20427574, 0x746F6E20, 0x6F6E2061,  /* fzgx-allow: A1 retail data bytes */
    0x6E6F7468, 0x65722E00, 0x83528393, 0x8367838D, 0x815B8389, 0x82AA8A4F, 0x82B382EA, 0x82DC82B5,  /* fzgx-allow: A1 retail data bytes */
    0x82BD8142, 0xA835283, 0x93836783, 0x8D815B83, 0x89837C81, 0x5B836725, 0x6482C982, 0xB382B582,  /* fzgx-allow: A1 retail data bytes */
    0xC882A882, 0xB782A981, 0x410A91BC, 0x82CC8352, 0x83938367, 0x838D815B, 0x838982C5, 0x839F837B,  /* fzgx-allow: A1 retail data bytes */
    0x835E8393, 0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_480__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_4F0__fzgx_offset_0, 0x59455300, 0x82CD82A2, 0x0, (u32)lbl_4_data_578__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_57C__fzgx_offset_0, 0x4E4F0000, 0x82A282A2, 0x82A60000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_59C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_5A0__fzgx_offset_0, 0x4368616E, 0x6765204F,  /* fzgx-allow: A1 retail data bytes */
    0x7074696F, 0x6E205365, 0x7474696E, 0x67730000, 0x83498376, 0x83568387, 0x839390DD, 0x92E882F0,  /* fzgx-allow: A1 retail data bytes */
    0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0, (u32)lbl_4_data_5C0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_5D8__fzgx_offset_0, 0x41646A75, 0x73742074, 0x68652043, 0x616C6962, 0x72617469, 0x6F6E2E0A,  /* fzgx-allow: A1 retail data bytes */
    0x50726573, 0x73207468, 0x65204120, 0x42757474, 0x6F6E206F, 0x6E207468, 0x6520436F, 0x6E74726F,  /* fzgx-allow: A1 retail data bytes */
    0x6C6C6572, 0xA796F75, 0x2077616E, 0x74206164, 0x6A757374, 0x65642E00, 0x83528393, 0x8367838D,  /* fzgx-allow: A1 retail data bytes */
    0x815B8389, 0x82CC834C, 0x8383838A, 0x8375838C, 0x815B8356, 0x83878393, 0x82F08D73, 0x82C882A2,  /* fzgx-allow: A1 retail data bytes */
    0x82DC82B7, 0x81420A95, 0xCF8D5882, 0xB782E983, 0x52839383, 0x67838D81, 0x5B838982, 0xC5839F82,  /* fzgx-allow: A1 retail data bytes */
    0xF0899F82, 0xB582C482, 0xAD82BE82, 0xB382A281, 0x42000000, (u32)lbl_4_data_610__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_660__fzgx_offset_0, 0x43757374, 0x6F6D697A, 0x65207468, 0x6520436F, 0x6E74726F,  /* fzgx-allow: A1 retail data bytes */
    0x6C6C6572, 0x2E0A5072, 0x65737320, 0x74686520, 0x41204275, 0x74746F6E, 0x206F6E20, 0x74686520,  /* fzgx-allow: A1 retail data bytes */
    0x436F6E74, 0x726F6C6C, 0x65722074, 0x6F206265, 0x2061646A, 0x75737465, 0x642E0000, 0x83528393,  /* fzgx-allow: A1 retail data bytes */
    0x8367838D, 0x815B8389, 0x82CC834A, 0x8358835E, 0x837D8343, 0x835982F0, 0x8D7382C8, 0x82A282DC,  /* fzgx-allow: A1 retail data bytes */
    0x82B78142, 0xA95CF8D, 0x5882B782, 0xE9835283, 0x93836783, 0x8D815B83, 0x8982C583, 0x9F82F089,  /* fzgx-allow: A1 retail data bytes */
    0x9F82B582, 0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_6D4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_724__fzgx_offset_0, 0x436F6E74, 0x726F6C6C, 0x65722052, 0x756D626C, 0x65205365, 0x7474696E,  /* fzgx-allow: A1 retail data bytes */
    0x67732E0A, 0x20507265, 0x73732074, 0x68652041, 0x20427574, 0x746F6E20, 0x746F2073, 0x656C6563,  /* fzgx-allow: A1 retail data bytes */
    0x74207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0x2E000000, 0x83528393, 0x8367838D, 0x815B8389,  /* fzgx-allow: A1 retail data bytes */
    0x82CC9055, 0x93AE82CC, 0x90DD92E8, 0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420A83, 0x52839383,  /* fzgx-allow: A1 retail data bytes */
    0x67838D81, 0x5B838982, 0xF0914982, 0xF182C583, 0x9F82F089, 0x9F82B582, 0xC482AD82, 0xBE82B382,  /* fzgx-allow: A1 retail data bytes */
    0xA2814200, (u32)lbl_4_data_790__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_7DC__fzgx_offset_0, (u32)lbl_4_data_400__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_438__fzgx_offset_0, 0x53617665, 0x20636861, 0x6E676573,  /* fzgx-allow: A1 retail data bytes */
    0x3F000000, 0x95CF8D58, 0x82F095DB, 0x91B682B5, 0x82DC82B7, 0x82A98148, 0x0, (u32)lbl_4_data_85C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_86C__fzgx_offset_0, 0x49732074, 0x68697320, 0x4F4B3F00,  /* fzgx-allow: A1 retail data bytes */
    0x82B182EA, 0x82C582E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x81480000, (u32)lbl_4_data_89C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8A8__fzgx_offset_0, 0x8163826E, 0x826D0000, (u32)lbl_4_data_8D8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8D8__fzgx_offset_0, 0x826E8265, 0x82650000, (u32)lbl_4_data_8F8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8F8__fzgx_offset_0, 0x4368616E, 0x67652043, 0x6F6E7472, 0x6F6C6C65,  /* fzgx-allow: A1 retail data bytes */
    0x72205365, 0x7474696E, 0x67730000, 0x83528393, 0x8367838D, 0x815B8389, 0x82CC90DD, 0x92E882F0,  /* fzgx-allow: A1 retail data bytes */
    0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[20]; void *v[20]; } fzgx_pool_init_lbl_4_data_958 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_918__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_934__fzgx_offset_0, 0x4D616E61, 0x6765204D,  /* fzgx-allow: A1 retail data bytes */
    0x656D6F72, 0x79204361, 0x72640000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x8AC7979D,  /* fzgx-allow: A1 retail data bytes */
    0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420000  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[537]; void *v[(0x120C - 0x9A8) / 4]; } fzgx_pool_init_lbl_4_data_9A8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_970__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_984__fzgx_offset_0, 0x53656C65, 0x63742053,  /* fzgx-allow: A1 retail data bytes */
    0x63726565, 0x6E205365, 0x7474696E, 0x67732000, 0x89E696CA, 0x8382815B, 0x836882CC, 0x90DD92E8,  /* fzgx-allow: A1 retail data bytes */
    0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420000, (u32)lbl_4_data_9C0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_9D8__fzgx_offset_0, 0x55736520, 0x83AD206F, 0x722083B5, 0x20746F20, 0x63686F6F, 0x73652061,  /* fzgx-allow: A1 retail data bytes */
    0x206D6F64, 0x65200000, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C58382, 0x815B8368, 0x82F09149,  /* fzgx-allow: A1 retail data bytes */
    0x82F182C5, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_A10__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_A30__fzgx_offset_0, 0x4E6F726D, 0x616C0000, 0x836D815B, 0x837D838B, 0x8365838C, 0x83720000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_A70__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_A78__fzgx_offset_0, 0x57696465, 0x20536372,  /* fzgx-allow: A1 retail data bytes */
    0x65656E00, 0x838F8343, 0x83688365, 0x838C8372, 0x0, (u32)lbl_4_data_AA0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_AAC__fzgx_offset_0, 0x4D6F7665, 0x20746865, 0x20436F6E, 0x74726F6C, 0x20537469,  /* fzgx-allow: A1 retail data bytes */
    0x636B2061, 0x726F756E, 0x6420696E, 0x20612063, 0x6972636C, 0x6520756E, 0x74696C20, 0x74686520,  /* fzgx-allow: A1 retail data bytes */
    0x66696775, 0x72657320, 0x6F6E2074, 0x68650A20, 0x6C656674, 0x20736964, 0x6520646F, 0x206E6F74,  /* fzgx-allow: A1 retail data bytes */
    0x20636861, 0x6E67652E, 0x2041646A, 0x75737420, 0x706C6179, 0x20757369, 0x6E672074, 0x68652083,  /* fzgx-allow: A1 retail data bytes */
    0xB520436F, 0x6E74726F, 0x6C205061, 0x642E0A20, 0x50726573, 0x73207468, 0x65205820, 0x42757474,  /* fzgx-allow: A1 retail data bytes */
    0x6F6E2074, 0x6F207265, 0x7475726E, 0x20746F20, 0x74686520, 0x64656661, 0x756C7420, 0x73657474,  /* fzgx-allow: A1 retail data bytes */
    0x696E6773, 0x2E000000, 0x8DB691A4, 0x82CC907D, 0x8C6082AA, 0x95CF89BB, 0x82B582C8, 0x82AD82C8,  /* fzgx-allow: A1 retail data bytes */
    0x82E982DC, 0x82C583AD, 0x82F088EA, 0x947482C9, 0x89F182B5, 0x82C482AD, 0x82BE82B3, 0x82A28142,  /* fzgx-allow: A1 retail data bytes */
    0xA83B582, 0xC5975682, 0xD182F092, 0xB290AE82, 0xB582C482, 0xAD82BE82, 0xB382A281, 0x420A83B4,  /* fzgx-allow: A1 retail data bytes */
    0x82C58F89, 0x8AFA90DD, 0x92E882C9, 0x96DF82B9, 0x82DC82B7, 0x81420000, (u32)lbl_4_data_AD4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_B90__fzgx_offset_0, 0x5475726E, 0x20746865, 0x20737465, 0x6572696E,  /* fzgx-allow: A1 retail data bytes */
    0x67207768, 0x65656C20, 0x4C656674, 0x20616E64, 0x20526967, 0x68742061, 0x6E642070, 0x72657373,  /* fzgx-allow: A1 retail data bytes */
    0xA746865, 0x20412042, 0x7574746F, 0x6E206174, 0x20746865, 0x20706F69, 0x6E742079, 0x6F752077,  /* fzgx-allow: A1 retail data bytes */
    0x616E7420, 0x746F2073, 0x65742061, 0x73207468, 0x650A206C, 0x696D6974, 0x2E205573, 0x65207468,  /* fzgx-allow: A1 retail data bytes */
    0x65204C20, 0x616E6420, 0x52204275, 0x74746F6E, 0x7320746F, 0x2061646A, 0x75737420, 0x67616D65,  /* fzgx-allow: A1 retail data bytes */
    0x20706C61, 0x792E2000, 0x836E8393, 0x8368838B, 0x82F08DB6, 0x894582C9, 0x89F182B5, 0x81418CC0,  /* fzgx-allow: A1 retail data bytes */
    0x8A4582C6, 0x82B582BD, 0x82A288CA, 0x927582C5, 0x839F82F0, 0x899F82B5, 0x82C482AD, 0x82BE82B3,  /* fzgx-allow: A1 retail data bytes */
    0x82A28142, 0xA826B81, 0x95827183, 0x67838A83, 0x4B815B83, 0x7B835E83, 0x9382C597, 0x5682D182,  /* fzgx-allow: A1 retail data bytes */
    0xF092B290, 0xAE82B582, 0xC482AD82, 0xBE82B382, 0xA281420A, 0x83B482C5, 0x8F898AFA, 0x90DD92E8,  /* fzgx-allow: A1 retail data bytes */
    0x82C996DF, 0x82B982DC, 0x82B78142, 0x0, (u32)lbl_4_data_C18__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_CB0__fzgx_offset_0, 0x4265666F, 0x72652063, 0x6F727265, 0x6374696F, 0x6E000000, 0x95E290B3,  /* fzgx-allow: A1 retail data bytes */
    0x914F0000, (u32)lbl_4_data_D50__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_D64__fzgx_offset_0, 0x41667465,  /* fzgx-allow: A1 retail data bytes */
    0x7220636F, 0x72726563, 0x74696F6E, 0x0, 0x95E290B3, 0x8CE30000, (u32)lbl_4_data_D84__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_D98__fzgx_offset_0, 0x47616D65, 0x20446174, 0x6120436F, 0x6E74726F,  /* fzgx-allow: A1 retail data bytes */
    0x6C730A49, 0x6E736572, 0x74206120, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E746F, 0x20536C6F,  /* fzgx-allow: A1 retail data bytes */
    0x7420412E, 0x0, 0x8351815B, 0x83808366, 0x815B835E, 0x82CC9180, 0x8DEC0A83, 0x81838283,  /* fzgx-allow: A1 retail data bytes */
    0x8A815B83, 0x4A815B83, 0x6882F083, 0x58838D83, 0x62836782, 0x6082C993, 0xFC82EA82, 0xC482AD82,  /* fzgx-allow: A1 retail data bytes */
    0xBE82B382, 0xA2814200, (u32)lbl_4_data_DB8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_DF0__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x4C6F6164, 0x2047616D, 0x65204461, 0x74610000, 0x8351815B, 0x83808366, 0x815B835E, 0x82CC838D,  /* fzgx-allow: A1 retail data bytes */
    0x815B8368, 0x0, (u32)lbl_4_data_E48__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_E58__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x53617665, 0x2047616D, 0x65204461, 0x74610000, 0x8351815B, 0x83808366, 0x815B835E, 0x82CC835A,  /* fzgx-allow: A1 retail data bytes */
    0x815B8375, 0x0, (u32)lbl_4_data_E88__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_E98__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x54686572, 0x65206973, 0x206E6F20, 0x47616D65, 0x20446174, 0x61206F6E, 0x20746869, 0x73204D65,  /* fzgx-allow: A1 retail data bytes */
    0x6D6F7279, 0x20436172, 0x642E0A20, 0x53617669, 0x6E67206E, 0x65772064, 0x6174612E, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x83818382, 0x838A815B, 0x834A815B, 0x836882C9, 0xA835181, 0x5B838083, 0x66815B83, 0x5E82AA8C,  /* fzgx-allow: A1 retail data bytes */
    0xA982C282, 0xA982E882, 0xDC82B982, 0xF181420A, 0x90568B4B, 0x835A815B, 0x837582B5, 0x82DC82B7,  /* fzgx-allow: A1 retail data bytes */
    0x81420000, (u32)lbl_4_data_EC8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_F08__fzgx_offset_0, 0x54686572,  /* fzgx-allow: A1 retail data bytes */
    0x65206973, 0x206E6F20, 0x47616D65, 0x20446174, 0x61206F6E, 0x20746865, 0x204D656D, 0x6F727920,  /* fzgx-allow: A1 retail data bytes */
    0x43617264, 0x2E0A4966, 0x20796F75, 0x20736176, 0x652C2074, 0x68652047, 0x616D6520, 0x44617461,  /* fzgx-allow: A1 retail data bytes */
    0x20637572, 0x72656E74, 0x6C79206C, 0x6F616465, 0x640A7769, 0x6C6C2061, 0x6C6C2062, 0x65206C6F,  /* fzgx-allow: A1 retail data bytes */
    0x73742E20, 0x49732074, 0x68617420, 0x4F4B3F00, 0x83818382, 0x838A815B, 0x834A815B, 0x836882C9,  /* fzgx-allow: A1 retail data bytes */
    0x8351815B, 0x83808366, 0x815B835E, 0x82AA8CA9, 0x82C282A9, 0x82E882DC, 0x82B982F1, 0x81420A90,  /* fzgx-allow: A1 retail data bytes */
    0x568B4B83, 0x5A815B83, 0x7582B782, 0xE982C68C, 0xBB8DDD83, 0x8D815B83, 0x6882B382, 0xEA82C482,  /* fzgx-allow: A1 retail data bytes */
    0xA282E983, 0x51815B83, 0x80836681, 0x5B835E82, 0xAA0A9153, 0x82C48FC1, 0x82A682C4, 0x82B582DC,  /* fzgx-allow: A1 retail data bytes */
    0x82A282DC, 0x82B782AA, 0x814182E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x3F000000, (u32)lbl_4_data_F64__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_FD8__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20,  /* fzgx-allow: A1 retail data bytes */
    0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x6C6F7420, 0x412E0000, 0x8358838D, 0x83628367,  /* fzgx-allow: A1 retail data bytes */
    0x826082C9, 0xA838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xAA8CA982, 0xC282A982, 0xE882DC82,  /* fzgx-allow: A1 retail data bytes */
    0xB982F181, 0x42000000, (u32)lbl_4_data_107C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10A0__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x52656769, 0x73746572, 0x20746869, 0x73206E61, 0x6D65206F, 0x6E207468, 0x65204D65, 0x6D6F7279,  /* fzgx-allow: A1 retail data bytes */
    0x20436172, 0x6420696E, 0x20536C6F, 0x7420412E, 0x0, 0x82B182CC, 0x96BC914F, 0x82C58381,  /* fzgx-allow: A1 retail data bytes */
    0x8382838A, 0x815B834A, 0x815B8368, 0x82C90A93, 0x6F985E82, 0xB582C482, 0xE082E682, 0xEB82B582,  /* fzgx-allow: A1 retail data bytes */
    0xA282C582, 0xB782A93F, 0x0, (u32)lbl_4_data_10E8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_111C__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053,  /* fzgx-allow: A1 retail data bytes */
    0x6C6F7420, 0x412E0A20, 0x54686520, 0x67616D65, 0x2063616E, 0x6E6F7420, 0x62652073, 0x61766564,  /* fzgx-allow: A1 retail data bytes */
    0x2E000000, 0x8358838D, 0x83628367, 0x826082C9, 0x83818382, 0x838A815B, 0x834A815B, 0x836882AA,  /* fzgx-allow: A1 retail data bytes */
    0x8CA982C2, 0x82A982E8, 0x82DC82B9, 0x82F18142, 0xA835A81, 0x5B837582, 0xC582AB82, 0xDC82B982,  /* fzgx-allow: A1 retail data bytes */
    0xF182C582, 0xB582BD81, 0x42000000, (u32)lbl_4_data_116C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_11AC__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */
}};
u8 lbl_4_data_11AC__fzgx_offset_60 = 0xFF;
s16 lbl_4_data_11AC__fzgx_offset_62 = -1;
static union { u32 w[1682]; char v[0x2C58 - 0x1210]; } fzgx_pool_init_lbl_4_data_1210 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x257300FF, 0xFFFF0000, 0x6F707469, 0x6F6E2E63, 0x0, 0x53656C53, 0x5F446973, 0x70506F6C,  /* fzgx-allow: A1 retail data bytes */
    0x79676F6E, 0x42470000, 0x53656C53, 0x5F446973, 0x70537072, 0x69746542, 0x47000000, 0x6F707469,  /* fzgx-allow: A1 retail data bytes */
    0x6F6E5F63, 0x6F6D6D6F, 0x6E5F6469, 0x73700000, 0x534D445F, 0x4F505449, 0x4F4E5F4D, 0x454E5500,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, (u32)fn_4_D10__fzgx_offset_0, (u32)fn_4_D7C__fzgx_offset_0, (u32)fn_4_EA0__fzgx_offset_0, 0x534D445F,  /* fzgx-allow: A1 retail data bytes */
    0x4F505449, 0x4F4E5F53, 0x4156455F, 0x57414954, 0x0, 0x0, 0x0, (u32)fn_4_9B20__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_9C14__fzgx_offset_0, (u32)fn_4_A734__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43, 0x54524C5F, 0x4D454E55, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, (u32)fn_4_7C38__fzgx_offset_0, (u32)fn_4_7CA4__fzgx_offset_0, (u32)fn_4_7D94__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43,  /* fzgx-allow: A1 retail data bytes */
    0x4152445F, 0x4D454E55, 0x0, 0x0, 0x0, (u32)fn_4_80EC__fzgx_offset_0, (u32)fn_4_8158__fzgx_offset_0, (u32)fn_4_8248__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x534D445F, 0x4F505449, 0x4F4E5F57, 0x49444500, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_869C__fzgx_offset_0, (u32)fn_4_8720__fzgx_offset_0, (u32)fn_4_898C__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43, 0x414C4942, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, (u32)fn_4_347C__fzgx_offset_0, (u32)fn_4_3568__fzgx_offset_0, (u32)fn_4_406C__fzgx_offset_0, 0x534D445F, 0x4F505449,  /* fzgx-allow: A1 retail data bytes */
    0x4F4E5F52, 0x554D424C, 0x45000000, 0x0, 0x0, 0x0, (u32)fn_4_4784__fzgx_offset_0, (u32)fn_4_4834__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_4B10__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F50, 0x43555354, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, (u32)fn_4_6678__fzgx_offset_0, (u32)fn_4_6720__fzgx_offset_0, (u32)fn_4_78E0__fzgx_offset_0, 0x534D445F, 0x4F505449, 0x4F4E5F43, 0x4152445F,  /* fzgx-allow: A1 retail data bytes */
    0x4D414E41, 0x47450000, 0x0, 0x0, (u32)fn_4_89E4__fzgx_offset_0, (u32)fn_4_8A54__fzgx_offset_0, (u32)fn_4_8AE0__fzgx_offset_0, 0x534D445F,  /* fzgx-allow: A1 retail data bytes */
    0x4F505449, 0x4F4E5F43, 0x4152445F, 0x47444154, 0x41000000, 0x0, 0x0, (u32)fn_4_8DC0__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_8E38__fzgx_offset_0, (u32)fn_4_9A78__fzgx_offset_0, 0x4D656D6F, 0x72792043, 0x61726400, 0x83818382, 0x838A815B, 0x834A815B,  /* fzgx-allow: A1 retail data bytes */
    0x83680000, 0x53637265, 0x656E204D, 0x6F646500, 0x89E696CA, 0x8382815B, 0x83680000, 0x4D0000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, 0x4E0000, (u32)lbl_4_data_1418__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1424__fzgx_offset_0, 0x4F0000, (u32)lbl_4_data_1434__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1440__fzgx_offset_0, 0x6F707469, 0x6F6E5F6D, 0x656E755F, 0x64697370,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x583A2534, 0x640A0000, 0x593A2534, 0x64000000, 0x25732534, 0x64000000, 0x25346400,  /* fzgx-allow: A1 retail data bytes */
    0x6F707469, 0x6F6E5F63, 0x616C6962, 0x5F646973, 0x7000FF00, 0xFFFF0000, 0x25732564, 0x81632020,  /* fzgx-allow: A1 retail data bytes */
    0x20000000, 0x25732564, 0x81632573, 0x0, 0x52756D62, 0x6C654D61, 0x696E0000, 0x6F707469,  /* fzgx-allow: A1 retail data bytes */
    0x6F6E5F72, 0x756D626C, 0x655F6469, 0x73700000, 0x81FF811F, 0x831F0000, 0x803FFF1F, 0x80303F1F,  /* fzgx-allow: A1 retail data bytes */
    0x80F03F1F, 0x4E6F7420, 0x436F6E6E, 0x65637465, 0x64000000, 0x96A290DA, 0x91B10000, 0x53706565,  /* fzgx-allow: A1 retail data bytes */
    0x6420466F, 0x72636500, 0x83588373, 0x815B8368, 0x83748348, 0x815B8358, 0x0, 0x53706565,  /* fzgx-allow: A1 retail data bytes */
    0x6420466F, 0x72636520, 0x616E6420, 0x50656461, 0x6C20556E, 0x69740000, 0x83588373, 0x815B8368,  /* fzgx-allow: A1 retail data bytes */
    0x83748348, 0x815B8358, 0x81958379, 0x835F838B, 0x8386836A, 0x83628367, 0x0, 0x41726361,  /* fzgx-allow: A1 retail data bytes */
    0x64650000, 0x8341815B, 0x8350815B, 0x83688341, 0x815B8350, 0x815B8368, 0x8341815B, 0x8350815B,  /* fzgx-allow: A1 retail data bytes */
    0x83688341, 0x815B8350, 0x815B8368, 0x8341815B, 0x8350815B, 0x83680000, (u32)lbl_4_data_1534__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_1544__fzgx_offset_0, (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, (u32)lbl_4_data_154C__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0, (u32)lbl_4_data_1558__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_156C__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_1588__fzgx_offset_0, (u32)lbl_4_data_15AC__fzgx_offset_0, (u32)lbl_4_data_15B4__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x0, 0x0, 0x0, 0x81638163, 0x81638163, 0x81638163, 0x81638163,  /* fzgx-allow: A1 retail data bytes */
    0x81638163, 0x81630000, 0x81638163, 0x81638163, 0x81638163, 0x0, 0x81630000, 0x81638163,  /* fzgx-allow: A1 retail data bytes */
    0x81638163, 0x81638163, 0x81638163, 0x0, 0x81638163, 0x81638163, 0x81638163, 0x81638163,  /* fzgx-allow: A1 retail data bytes */
    0x81630000, 0xA400A0, (u32)lbl_4_data_1660__fzgx_offset_0, 0xF800B4, (u32)lbl_4_data_1678__fzgx_offset_0, 0x14C00C8, (u32)lbl_4_data_1688__fzgx_offset_0, 0xD600DC,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_168C__fzgx_offset_0, 0xD600F0, (u32)lbl_4_data_168C__fzgx_offset_0, 0xC60104, (u32)lbl_4_data_16A0__fzgx_offset_0, 0xD60118, (u32)lbl_4_data_168C__fzgx_offset_0, 0xD6012C,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_168C__fzgx_offset_0, 0xA40140, (u32)lbl_4_data_1660__fzgx_offset_0, 0x53746565, 0x72000000, 0x83588365, 0x8341838A, 0x8393834F,  /* fzgx-allow: A1 retail data bytes */
    0x8DB68945, 0x81630000, 0x536C6964, 0x65204C65, 0x66742052, 0x69676874, 0x0, 0x83588389,  /* fzgx-allow: A1 retail data bytes */
    0x83438368, 0x8DB68945, 0x81638163, 0x81630000, 0x41646A75, 0x73742043, 0x656E7465, 0x72206F66,  /* fzgx-allow: A1 retail data bytes */
    0x20477261, 0x76697479, 0x0, 0x83578383, 0x83938376, 0x8F649053, 0x88DA93AE, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x41646A75, 0x73742056, 0x69657700, 0x8E8B935F, 0x95CF8D58, 0x81638163, 0x81638163, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x41636365, 0x6C657261, 0x74650000, 0x8341834E, 0x835A838B, 0x81638163, 0x81638163, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x41697220, 0x4272616B, 0x65000000, 0x83478341, 0x8375838C, 0x815B834C, 0x81638163, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x53696465, 0x20417474, 0x61636B00, 0x83548343, 0x83688341, 0x835E8362, 0x834E8163, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x5370696E, 0x20417474, 0x61636B00, 0x83588373, 0x83938341, 0x835E8362, 0x834E8163, 0x81630000,  /* fzgx-allow: A1 retail data bytes */
    0x426F6F73, 0x74000000, 0x8375815B, 0x8358835E, 0x815B8163, 0x81638163, 0x81630000, (u32)lbl_4_data_16FC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1704__fzgx_offset_0, (u32)lbl_4_data_1718__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_172C__fzgx_offset_0, (u32)lbl_4_data_1740__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_175C__fzgx_offset_0, (u32)lbl_4_data_1770__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_177C__fzgx_offset_0, (u32)lbl_4_data_1790__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_179C__fzgx_offset_0, (u32)lbl_4_data_17B0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_17BC__fzgx_offset_0, (u32)lbl_4_data_17D0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_17DC__fzgx_offset_0, (u32)lbl_4_data_17F0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_17FC__fzgx_offset_0, (u32)lbl_4_data_1810__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1818__fzgx_offset_0, 0x83B52043, 0x6F6E7472, 0x6F6C2050,  /* fzgx-allow: A1 retail data bytes */
    0x6164204C, 0x65667420, 0x616E6420, 0x52696768, 0x74000000, 0x83B52083, 0xD0000000, 0x8F5C8E9A,  /* fzgx-allow: A1 retail data bytes */
    0x837B835E, 0x83938DB6, 0x89450000, 0x83B52043, 0x6F6E7472, 0x6F6C2050, 0x61642055, 0x7020616E,  /* fzgx-allow: A1 retail data bytes */
    0x6420446F, 0x776E0000, 0x83B52083, 0xCF000000, 0x8F5C8E9A, 0x837B835E, 0x83938FE3, 0x89BA0000,  /* fzgx-allow: A1 retail data bytes */
    0x4120616E, 0x64204220, 0x42757474, 0x6F6E0000, 0x839F2083, 0xA0000000, 0x82608195, 0x8261837B,  /* fzgx-allow: A1 retail data bytes */
    0x835E8393, 0x0, 0x5820616E, 0x64205920, 0x42757474, 0x6F6E0000, 0x83B42083, 0xB2000000,  /* fzgx-allow: A1 retail data bytes */
    0x82778195, 0x8278837B, 0x835E8393, 0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053, 0x7469636B,  /* fzgx-allow: A1 retail data bytes */
    0x204C6566, 0x7420616E, 0x64205269, 0x67687400, 0x83AD2083, 0xD0000000, 0x83528393, 0x8367838D,  /* fzgx-allow: A1 retail data bytes */
    0x815B838B, 0x83588365, 0x83428362, 0x834E8DB6, 0x89450000, 0x83AD2043, 0x6F6E7472, 0x6F6C2053,  /* fzgx-allow: A1 retail data bytes */
    0x7469636B, 0x20557020, 0x616E6420, 0x446F776E, 0x0, 0x83AD2083, 0xCF000000, 0x83528393,  /* fzgx-allow: A1 retail data bytes */
    0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E8FE3, 0x89BA0000, 0x83A62043, 0x20537469,  /* fzgx-allow: A1 retail data bytes */
    0x636B204C, 0x65667420, 0x616E6420, 0x52696768, 0x74000000, 0x83A62083, 0xD0000000, 0x82628358,  /* fzgx-allow: A1 retail data bytes */
    0x83658342, 0x8362834E, 0x8DB68945, 0x0, 0x83A62043, 0x20537469, 0x636B2055, 0x7020616E,  /* fzgx-allow: A1 retail data bytes */
    0x6420446F, 0x776E0000, 0x83A62083, 0xCF000000, 0x82628358, 0x83658342, 0x8362834E, 0x8FE389BA,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x4C20616E, 0x64205220, 0x42757474, 0x6F6E0000, 0x826B8195, 0x82718367, 0x838A834B,  /* fzgx-allow: A1 retail data bytes */
    0x815B837B, 0x835E8393, 0x0, 0x4E6F2051, 0x756F7461, 0x73000000, 0x8A8482E8, 0x939682C4,  /* fzgx-allow: A1 retail data bytes */
    0x82C882B5, 0x0, (u32)lbl_4_data_1904__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_192C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_193C__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1960__fzgx_offset_0, (u32)lbl_4_data_1970__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1988__fzgx_offset_0, (u32)lbl_4_data_1998__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19B0__fzgx_offset_0, (u32)lbl_4_data_19C0__fzgx_offset_0, (u32)lbl_4_data_19E0__fzgx_offset_0, (u32)lbl_4_data_19E0__fzgx_offset_0, (u32)lbl_4_data_19E0__fzgx_offset_0, (u32)lbl_4_data_19E0__fzgx_offset_0, (u32)lbl_4_data_19E8__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1A04__fzgx_offset_0, (u32)lbl_4_data_1A24__fzgx_offset_0, (u32)lbl_4_data_1A24__fzgx_offset_0, (u32)lbl_4_data_1A24__fzgx_offset_0, (u32)lbl_4_data_1A24__fzgx_offset_0, (u32)lbl_4_data_1A2C__fzgx_offset_0, (u32)lbl_4_data_1A48__fzgx_offset_0, (u32)lbl_4_data_1A64__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1A64__fzgx_offset_0, (u32)lbl_4_data_1A64__fzgx_offset_0, (u32)lbl_4_data_1A64__fzgx_offset_0, (u32)lbl_4_data_1A6C__fzgx_offset_0, (u32)lbl_4_data_1A80__fzgx_offset_0, (u32)lbl_4_data_1A98__fzgx_offset_0, (u32)lbl_4_data_1A98__fzgx_offset_0, (u32)lbl_4_data_1A98__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1A98__fzgx_offset_0, (u32)lbl_4_data_1AA0__fzgx_offset_0, (u32)lbl_4_data_1AB4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AC4__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1ADC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AE8__fzgx_offset_0, 0x53746565, 0x72696E67, 0x20576865, 0x656C204C, 0x65667420, 0x616E6420,  /* fzgx-allow: A1 retail data bytes */
    0x52696768, 0x74000000, 0x836E8393, 0x8368838B, 0x8DB68945, 0x0, 0x41636365, 0x6C657261,  /* fzgx-allow: A1 retail data bytes */
    0x746F7220, 0x616E6420, 0x42726561, 0x6B205065, 0x64616C00, 0x8341834E, 0x835A838B, 0x81958375,  /* fzgx-allow: A1 retail data bytes */
    0x838C815B, 0x834C8379, 0x835F838B, 0x0, (u32)lbl_4_data_1904__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_1924__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1924__fzgx_offset_0, (u32)lbl_4_data_192C__fzgx_offset_0, (u32)lbl_4_data_193C__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1958__fzgx_offset_0, (u32)lbl_4_data_1960__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1970__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1980__fzgx_offset_0, (u32)lbl_4_data_1988__fzgx_offset_0, (u32)lbl_4_data_1998__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19A8__fzgx_offset_0, (u32)lbl_4_data_19B0__fzgx_offset_0, (u32)lbl_4_data_1C78__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1C98__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AB4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AC4__fzgx_offset_0, (u32)lbl_4_data_1CA8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1CC4__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1ADC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AE8__fzgx_offset_0, 0x83B52043, 0x6F6E7472, 0x6F6C2050, 0x6164204C,  /* fzgx-allow: A1 retail data bytes */
    0x65667400, 0x83B5204C, 0x65667400, 0x8F5C8E9A, 0x837B835E, 0x83938DB6, 0x0, 0x83B52043,  /* fzgx-allow: A1 retail data bytes */
    0x6F6E7472, 0x6F6C2050, 0x61642052, 0x69676874, 0x0, 0x83B52052, 0x69676874, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x8F5C8E9A, 0x837B835E, 0x83938945, 0x0, 0x83B52043, 0x6F6E7472, 0x6F6C2050, 0x61642044,  /* fzgx-allow: A1 retail data bytes */
    0x6F776E00, 0x83B52044, 0x6F776E00, 0x8F5C8E9A, 0x837B835E, 0x839389BA, 0x0, 0x83B52043,  /* fzgx-allow: A1 retail data bytes */
    0x6F6E7472, 0x6F6C2050, 0x61642055, 0x70000000, 0x83B52055, 0x70000000, 0x8F5C8E9A, 0x837B835E,  /* fzgx-allow: A1 retail data bytes */
    0x83938FE3, 0x0, 0x5A204275, 0x74746F6E, 0x0, 0x83A42000, 0x8279837B, 0x835E8393,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x41204275, 0x74746F6E, 0x0, 0x839F0000, 0x8260837B, 0x835E8393, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x42204275, 0x74746F6E, 0x0, 0x83A02000, 0x8261837B, 0x835E8393, 0x0, 0x58204275,  /* fzgx-allow: A1 retail data bytes */
    0x74746F6E, 0x0, 0x83B42000, 0x8277837B, 0x835E8393, 0x0, 0x59204275, 0x74746F6E,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x83B22000, 0x8278837B, 0x835E8393, 0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053,  /* fzgx-allow: A1 retail data bytes */
    0x7469636B, 0x204C6566, 0x74000000, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362,  /* fzgx-allow: A1 retail data bytes */
    0x834E8DB6, 0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x20526967, 0x68740000,  /* fzgx-allow: A1 retail data bytes */
    0x83AD2052, 0x69676874, 0x0, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362,  /* fzgx-allow: A1 retail data bytes */
    0x834E8945, 0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x20446F77, 0x6E000000,  /* fzgx-allow: A1 retail data bytes */
    0x83AD2044, 0x6F776E00, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E89BA,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x83AD2043, 0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x20557000, 0x83AD2055, 0x70000000,  /* fzgx-allow: A1 retail data bytes */
    0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E8FE3, 0x0, 0x83A62043,  /* fzgx-allow: A1 retail data bytes */
    0x20537469, 0x636B204C, 0x65667400, 0x83AD204C, 0x65667400, 0x82628358, 0x83658342, 0x8362834E,  /* fzgx-allow: A1 retail data bytes */
    0x8DB60000, 0x83A62043, 0x20537469, 0x636B2052, 0x69676874, 0x0, 0x83A62052, 0x69676874,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x82628358, 0x83658342, 0x8362834E, 0x89450000, 0x83A62043, 0x20537469, 0x636B2044,  /* fzgx-allow: A1 retail data bytes */
    0x6F776E00, 0x83A62044, 0x6F776E00, 0x82628358, 0x83658342, 0x8362834E, 0x89BA0000, 0x83A62043,  /* fzgx-allow: A1 retail data bytes */
    0x20537469, 0x636B2055, 0x70000000, 0x83A62055, 0x70000000, 0x82628358, 0x83658342, 0x8362834E,  /* fzgx-allow: A1 retail data bytes */
    0x8FE30000, 0x4C204275, 0x74746F6E, 0x0, 0x83A12000, 0x826B8367, 0x838A834B, 0x815B837B,  /* fzgx-allow: A1 retail data bytes */
    0x835E8393, 0x0, 0x52204275, 0x74746F6E, 0x0, 0x2083AF20, 0x0, 0x82718367,  /* fzgx-allow: A1 retail data bytes */
    0x838A834B, 0x815B837B, 0x835E8393, 0x0, (u32)lbl_4_data_1E60__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E7C__fzgx_offset_0, (u32)lbl_4_data_1E8C__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EB0__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1EC0__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1EDC__fzgx_offset_0, (u32)lbl_4_data_1EEC__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F08__fzgx_offset_0, (u32)lbl_4_data_1F18__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F28__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1F34__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F44__fzgx_offset_0, (u32)lbl_4_data_1F50__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F60__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1F6C__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F7C__fzgx_offset_0, (u32)lbl_4_data_1F88__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F98__fzgx_offset_0, (u32)lbl_4_data_1FA4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1FBC__fzgx_offset_0, (u32)lbl_4_data_1FD8__fzgx_offset_0, (u32)lbl_4_data_1FF0__fzgx_offset_0, (u32)lbl_4_data_1FF0__fzgx_offset_0, (u32)lbl_4_data_1FF0__fzgx_offset_0, (u32)lbl_4_data_1FF0__fzgx_offset_0, (u32)lbl_4_data_1FFC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_2018__fzgx_offset_0, (u32)lbl_4_data_2030__fzgx_offset_0, (u32)lbl_4_data_2030__fzgx_offset_0, (u32)lbl_4_data_2030__fzgx_offset_0, (u32)lbl_4_data_2030__fzgx_offset_0, (u32)lbl_4_data_2038__fzgx_offset_0, (u32)lbl_4_data_2054__fzgx_offset_0, (u32)lbl_4_data_2068__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_2068__fzgx_offset_0, (u32)lbl_4_data_2068__fzgx_offset_0, (u32)lbl_4_data_2068__fzgx_offset_0, (u32)lbl_4_data_2070__fzgx_offset_0, (u32)lbl_4_data_208C__fzgx_offset_0, (u32)lbl_4_data_209C__fzgx_offset_0, (u32)lbl_4_data_209C__fzgx_offset_0, (u32)lbl_4_data_209C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_209C__fzgx_offset_0, (u32)lbl_4_data_20A4__fzgx_offset_0, (u32)lbl_4_data_20B4__fzgx_offset_0, (u32)lbl_4_data_20C8__fzgx_offset_0, (u32)lbl_4_data_20C8__fzgx_offset_0, (u32)lbl_4_data_20C8__fzgx_offset_0, (u32)lbl_4_data_20C8__fzgx_offset_0, (u32)lbl_4_data_20D4__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_20E4__fzgx_offset_0, (u32)lbl_4_data_20F4__fzgx_offset_0, (u32)lbl_4_data_20F4__fzgx_offset_0, (u32)lbl_4_data_20F4__fzgx_offset_0, (u32)lbl_4_data_20F4__fzgx_offset_0, (u32)lbl_4_data_20FC__fzgx_offset_0, (u32)lbl_4_data_210C__fzgx_offset_0, (u32)lbl_4_data_211C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_211C__fzgx_offset_0, (u32)lbl_4_data_211C__fzgx_offset_0, (u32)lbl_4_data_211C__fzgx_offset_0, (u32)lbl_4_data_2124__fzgx_offset_0, (u32)lbl_4_data_2134__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2144__fzgx_offset_0, (u32)lbl_4_data_2158__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_216C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1ADC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AE8__fzgx_offset_0, 0x53746565, 0x72696E67, 0x20576865, 0x656C204C,  /* fzgx-allow: A1 retail data bytes */
    0x65667400, 0x836E8393, 0x8368838B, 0x8DB60000, 0x53746565, 0x72696E67, 0x20576865, 0x656C2052,  /* fzgx-allow: A1 retail data bytes */
    0x69676874, 0x0, 0x836E8393, 0x8368838B, 0x89450000, 0x41636365, 0x6C657261, 0x746F7220,  /* fzgx-allow: A1 retail data bytes */
    0x50656461, 0x6C000000, 0x8341834E, 0x835A838B, 0x8379835F, 0x838B0000, 0x4272616B, 0x65205065,  /* fzgx-allow: A1 retail data bytes */
    0x64616C00, 0x8375838C, 0x815B834C, 0x8379835F, 0x838B0000, (u32)lbl_4_data_1E60__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E74__fzgx_offset_0, (u32)lbl_4_data_1E7C__fzgx_offset_0, (u32)lbl_4_data_1E8C__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0, (u32)lbl_4_data_1EA4__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1EB0__fzgx_offset_0, (u32)lbl_4_data_1EC0__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1ED4__fzgx_offset_0, (u32)lbl_4_data_1EDC__fzgx_offset_0, (u32)lbl_4_data_1EEC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F00__fzgx_offset_0, (u32)lbl_4_data_1F08__fzgx_offset_0, (u32)lbl_4_data_1F18__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F24__fzgx_offset_0, (u32)lbl_4_data_1F28__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1F34__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F40__fzgx_offset_0, (u32)lbl_4_data_1F44__fzgx_offset_0, (u32)lbl_4_data_1F50__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0, (u32)lbl_4_data_1F5C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1F60__fzgx_offset_0, (u32)lbl_4_data_1F6C__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F78__fzgx_offset_0, (u32)lbl_4_data_1F7C__fzgx_offset_0, (u32)lbl_4_data_1F88__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F94__fzgx_offset_0, (u32)lbl_4_data_1F98__fzgx_offset_0, (u32)lbl_4_data_2480__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2494__fzgx_offset_0, (u32)lbl_4_data_24A0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_24B8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2134__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2140__fzgx_offset_0, (u32)lbl_4_data_2144__fzgx_offset_0, (u32)lbl_4_data_2158__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0, (u32)lbl_4_data_2164__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_216C__fzgx_offset_0, (u32)lbl_4_data_24C4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_24D8__fzgx_offset_0, (u32)lbl_4_data_24E8__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_24F4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1ADC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_1AE8__fzgx_offset_0, 0x41582043, 0x6F6E7472, 0x6F6C7300,  /* fzgx-allow: A1 retail data bytes */
    0x82608277, 0x82CC9180, 0x8DEC0000, (u32)lbl_4_data_2804__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_2810__fzgx_offset_0, 0x44656661, 0x756C7420, 0x53657474, 0x696E6773, 0x0, 0x8F898AFA, 0x90DD92E8,  /* fzgx-allow: A1 retail data bytes */
    0x82C996DF, 0x82B70000, (u32)lbl_4_data_2834__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2848__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x53696465, 0x20417474, 0x61636B3A, 0x51756963, 0x6B6C7920, 0x70726573, 0x73207468, 0x65204C20,  /* fzgx-allow: A1 retail data bytes */
    0x6F722052, 0x20427574, 0x746F6E0A, 0x20202020, 0x20202020, 0x20202020, 0x20202074, 0x77696365,  /* fzgx-allow: A1 retail data bytes */
    0x2E0A5370, 0x696E2041, 0x74746163, 0x6B3A5072, 0x65737320, 0x74686520, 0x4C20616E, 0x64205220,  /* fzgx-allow: A1 retail data bytes */
    0x42757474, 0x6F6E730A, 0x20202020, 0x20202020, 0x20202020, 0x20202073, 0x696D756C, 0x74616E65,  /* fzgx-allow: A1 retail data bytes */
    0x6F75736C, 0x7920616E, 0x64207475, 0x726E2074, 0x68652077, 0x6865656C, 0x2E200000, 0x83548343,  /* fzgx-allow: A1 retail data bytes */
    0x83688341, 0x835E8362, 0x834E8163, 0x8367838A, 0x834B815B, 0x825189F1, 0x88F882AB, 0xA835883,  /* fzgx-allow: A1 retail data bytes */
    0x73839383, 0x41835E83, 0x62834E81, 0x63836783, 0x8A834B81, 0x5B826B82, 0x7197BC88, 0xF882AB81,  /* fzgx-allow: A1 retail data bytes */
    0x95836E83, 0x93836883, 0x8B000000, (u32)lbl_4_data_2870__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_290C__fzgx_offset_0, (u32)fn_4_4B74__fzgx_offset_68, (u32)fn_4_4B74__fzgx_offset_7C, (u32)fn_4_4B74__fzgx_offset_94, (u32)fn_4_4B74__fzgx_offset_AC, (u32)fn_4_4B74__fzgx_offset_C4, (u32)fn_4_4B74__fzgx_offset_DC, (u32)fn_4_4B74__fzgx_offset_F4,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_4B74__fzgx_offset_10C, (u32)fn_4_4B74__fzgx_offset_124, (u32)fn_4_4CB8__fzgx_offset_6C, (u32)fn_4_4CB8__fzgx_offset_80, (u32)fn_4_4CB8__fzgx_offset_98, (u32)fn_4_4CB8__fzgx_offset_B0, (u32)fn_4_4CB8__fzgx_offset_C8, (u32)fn_4_4CB8__fzgx_offset_E0,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_4CB8__fzgx_offset_F8, (u32)fn_4_4CB8__fzgx_offset_110, (u32)fn_4_4CB8__fzgx_offset_128, 0x25732573, 0xA000000, 0x25730A00, 0x25738163, 0x25730000,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_4DF8__fzgx_offset_1428, (u32)fn_4_4DF8__fzgx_offset_1408, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_4DF8__fzgx_offset_1308, (u32)fn_4_4DF8__fzgx_offset_12E4, (u32)fn_4_4DF8__fzgx_offset_13E0, (u32)fn_4_4DF8__fzgx_offset_13C0, (u32)fn_4_4DF8__fzgx_offset_1398, (u32)fn_4_4DF8__fzgx_offset_1378, (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1454,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_4DF8__fzgx_offset_1454, (u32)fn_4_4DF8__fzgx_offset_1350, (u32)fn_4_4DF8__fzgx_offset_1330, (u32)fn_4_4DF8__fzgx_offset_1330, (u32)fn_4_4DF8__fzgx_offset_1330, (u32)fn_4_4DF8__fzgx_offset_1330, (u32)fn_4_4DF8__fzgx_offset_E54, (u32)fn_4_4DF8__fzgx_offset_E34,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_4DF8__fzgx_offset_E14, (u32)fn_4_4DF8__fzgx_offset_E14, (u32)fn_4_4DF8__fzgx_offset_E14, (u32)fn_4_4DF8__fzgx_offset_E14, (u32)fn_4_4DF8__fzgx_offset_DF4, (u32)fn_4_4DF8__fzgx_offset_DF4, (u32)fn_4_4DF8__fzgx_offset_DF4, (u32)fn_4_4DF8__fzgx_offset_DF4,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_4DF8__fzgx_offset_DD4, (u32)fn_4_4DF8__fzgx_offset_DB4, (u32)fn_4_4DF8__fzgx_offset_D8C, (u32)fn_4_4DF8__fzgx_offset_D6C, (u32)fn_4_4DF8__fzgx_offset_E80, (u32)fn_4_4DF8__fzgx_offset_E80, (u32)fn_4_4DF8__fzgx_offset_E80, (u32)fn_4_4DF8__fzgx_offset_D4C,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_4DF8__fzgx_offset_D2C, (u32)fn_4_4DF8__fzgx_offset_D2C, (u32)fn_4_4DF8__fzgx_offset_D2C, (u32)fn_4_4DF8__fzgx_offset_D2C, (u32)fn_4_4DF8__fzgx_offset_930, (u32)fn_4_4DF8__fzgx_offset_940, (u32)fn_4_4DF8__fzgx_offset_954, (u32)fn_4_4DF8__fzgx_offset_968,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_4DF8__fzgx_offset_97C, (u32)fn_4_4DF8__fzgx_offset_990, (u32)fn_4_4DF8__fzgx_offset_9A4, (u32)fn_4_4DF8__fzgx_offset_9B8, (u32)fn_4_4DF8__fzgx_offset_9CC, (u32)fn_4_4DF8__fzgx_offset_3E4, (u32)fn_4_4DF8__fzgx_offset_3F4, (u32)fn_4_4DF8__fzgx_offset_408,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_4DF8__fzgx_offset_41C, (u32)fn_4_4DF8__fzgx_offset_430, (u32)fn_4_4DF8__fzgx_offset_444, (u32)fn_4_4DF8__fzgx_offset_458, (u32)fn_4_4DF8__fzgx_offset_46C, (u32)fn_4_4DF8__fzgx_offset_480, (u32)fn_4_63D4__fzgx_offset_94, (u32)fn_4_63D4__fzgx_offset_F8,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_63D4__fzgx_offset_150, (u32)fn_4_63D4__fzgx_offset_170, (u32)fn_4_63D4__fzgx_offset_170, (u32)fn_4_63D4__fzgx_offset_190, (u32)fn_4_63D4__fzgx_offset_1C0, (u32)fn_4_63D4__fzgx_offset_1F0, 0x6F707469, 0x6F6E5F70,  /* fzgx-allow: A1 retail data bytes */
    0x63757374, 0x5F646973, 0x70000000, (u32)fn_4_6720__fzgx_offset_C94, (u32)fn_4_6720__fzgx_offset_CA4, (u32)fn_4_6720__fzgx_offset_CB8, (u32)fn_4_6720__fzgx_offset_CCC, (u32)fn_4_6720__fzgx_offset_CE0,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_6720__fzgx_offset_CF4, (u32)fn_4_6720__fzgx_offset_D08, (u32)fn_4_6720__fzgx_offset_D1C, (u32)fn_4_6720__fzgx_offset_D30, (u32)fn_4_6720__fzgx_offset_B48, (u32)fn_4_6720__fzgx_offset_B58, (u32)fn_4_6720__fzgx_offset_B6C, (u32)fn_4_6720__fzgx_offset_B80,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_6720__fzgx_offset_B94, (u32)fn_4_6720__fzgx_offset_BA8, (u32)fn_4_6720__fzgx_offset_BBC, (u32)fn_4_6720__fzgx_offset_BD0, (u32)fn_4_6720__fzgx_offset_BE4, (u32)fn_4_6720__fzgx_offset_93C, (u32)fn_4_6720__fzgx_offset_94C, (u32)fn_4_6720__fzgx_offset_960,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_6720__fzgx_offset_974, (u32)fn_4_6720__fzgx_offset_988, (u32)fn_4_6720__fzgx_offset_99C, (u32)fn_4_6720__fzgx_offset_9B0, (u32)fn_4_6720__fzgx_offset_9C4, (u32)fn_4_6720__fzgx_offset_9D8, (u32)fn_4_6720__fzgx_offset_710, (u32)fn_4_6720__fzgx_offset_720,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_6720__fzgx_offset_734, (u32)fn_4_6720__fzgx_offset_748, (u32)fn_4_6720__fzgx_offset_75C, (u32)fn_4_6720__fzgx_offset_770, (u32)fn_4_6720__fzgx_offset_784, (u32)fn_4_6720__fzgx_offset_798, (u32)fn_4_6720__fzgx_offset_7AC, (u32)fn_4_6720__fzgx_offset_5E4,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_6720__fzgx_offset_5F4, (u32)fn_4_6720__fzgx_offset_608, (u32)fn_4_6720__fzgx_offset_61C, (u32)fn_4_6720__fzgx_offset_630, (u32)fn_4_6720__fzgx_offset_644, (u32)fn_4_6720__fzgx_offset_658, (u32)fn_4_6720__fzgx_offset_66C, (u32)fn_4_6720__fzgx_offset_680,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_6720__fzgx_offset_404, (u32)fn_4_6720__fzgx_offset_414, (u32)fn_4_6720__fzgx_offset_428, (u32)fn_4_6720__fzgx_offset_43C, (u32)fn_4_6720__fzgx_offset_450, (u32)fn_4_6720__fzgx_offset_464, (u32)fn_4_6720__fzgx_offset_478, (u32)fn_4_6720__fzgx_offset_48C,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_6720__fzgx_offset_4A0, (u32)fn_4_6720__fzgx_offset_98, (u32)fn_4_6720__fzgx_offset_148, (u32)fn_4_6720__fzgx_offset_298, (u32)fn_4_6720__fzgx_offset_540, (u32)fn_4_6720__fzgx_offset_D6C, (u32)fn_4_6720__fzgx_offset_E8C, (u32)fn_4_6720__fzgx_offset_1038,  /* fzgx-allow: A1 retail data bytes */
    (u32)fn_4_6720__fzgx_offset_1114, 0x43616C69, 0x62726174, 0x696F6E00, 0x834C8383, 0x838A8375, 0x838C815B, 0x83568387,  /* fzgx-allow: A1 retail data bytes */
    0x83930000, 0x43757374, 0x6F6D697A, 0x65000000, 0x834A8358, 0x835E837D, 0x83438359, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x436F6E74, 0x726F6C6C, 0x65722052, 0x756D626C, 0x65000000, 0x83528393, 0x8367838D, 0x815B8389,  /* fzgx-allow: A1 retail data bytes */
    0x905593AE, 0x0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[21]; OptionRow v[3]; } fzgx_pool_init_lbl_4_data_2C58 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x500000, (u32)lbl_4_data_2BF4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2C00__fzgx_offset_0, 0x520000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_2C14__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2C20__fzgx_offset_0, 0x510000, (u32)lbl_4_data_2C30__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2C44__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */
}};

extern u8 lbl_4_data_2CC4__fzgx_offset_0[];
extern u8 lbl_4_data_2CE4__fzgx_offset_0[];
extern u8 lbl_4_data_2CFC__fzgx_offset_0[];
extern u8 lbl_4_data_2D10__fzgx_offset_0[];
extern u8 lbl_4_data_C__fzgx_offset_0[];

static union { u32 w[30]; u8 v[0x78]; } fzgx_pool_init_lbl_4_data_2CAC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6F707469, 0x6F6E5F63, 0x74726C5F, 0x6D656E75, 0x5F646973, 0x70000000, 0x4D616E61, 0x67652041,  /* fzgx-allow: A1 retail data bytes */
    0x6C6C2046, 0x6F726D73, 0x206F6620, 0x47616D65, 0x20446174, 0x61000000, 0x8A658EED, 0x835A815B,  /* fzgx-allow: A1 retail data bytes */
    0x83758366, 0x815B835E, 0x8AC7979D, 0x0, 0x4D616E61, 0x67652047, 0x616D6520, 0x44617461,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x8351815B, 0x83808366, 0x815B835E, 0x8AC7979D, 0x0  /* fzgx-allow: A1 retail data bytes */
}};

static union { u32 w[14]; OptionRow v[2]; } fzgx_pool_init_lbl_4_data_2D24 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x530000, (u32)lbl_4_data_2CC4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2CE4__fzgx_offset_0, 0x540000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_2CFC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2D10__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */
}};

/* Screen y of a menu row (rows are 24 pixels apart, centred on 240). */
static inline u32 row_y(u32 row) {
    return (row - 1) * 24 + 240;
}

extern s32 lbl_801A66B4;
extern u8 lbl_4_bss_D;
extern s16 lbl_1_bss_962;
extern FontDrawPacket lbl_1_rodata_26F8;

extern void fn_1_49410(void);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_53E40(f32, f32, f32, f32, f32, s32, void *);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern f32 fn_1_4B040(char *);
extern f32 lbl_8006D188(s16);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern void fn_1_1380F0(void *);
extern void fn_1_13ABA8(u32);
extern void fn_1_5233C(void);

/* Draws the option rows from `i` on and returns the widest text. */
typedef struct RowCounter { u32 value; } RowCounter;
static inline f32 draw_rows(u32 i, RowCounter *row, OptionRow **entry) {
    f32 width;
    f32 w;

    width = 0.0f;
    *entry = fzgx_pool_init_lbl_4_data_2D24.v;
    for (row->value = i * 2; i < 2; i++, row->value += 2, (*entry)++) {
        fn_1_496FC(320.0f, (f32)row_y(row->value));
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(0.5f);
        }
        fn_1_4AE0C(fzgx_pool_init_lbl_4_data_1210.v, (*entry)->text[lbl_801A66B4]);
        w = fn_1_4B040((*entry)->text[lbl_801A66B4]);
        if (w > width) {
            width = w;
        }
    }
    return width;
}

static inline f64 fn_4_7DEC_operand(f32 right, f64 left) { left += right; return left; }
static inline f64 fn_4_7DEC_operand_(f64 right, f64 left) { return left + right; }
void fn_4_7DEC(void) {
    u32 i;
    RowCounter row;
    struct { u32 value; } cursor;
    OptionRow *entry;
    f32 width;
    f32 w;
    FontDrawPacket packet;
    f32 height;
    f64 base;
    f64 margin;

    fn_1_49410();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    fn_1_53E40(320.0f, 110.0f, 0.05f, 48.0f, 1.0f, 0, fzgx_pool_init_lbl_4_data_9A8.v[lbl_801A66B4]);

    cursor.value = lbl_4_bss_D;
    fn_1_49410();
    fn_1_495C8(9);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);

    width = draw_rows(0, &row, &entry);

    if (lbl_4_data_11AC__fzgx_offset_60 != cursor.value || lbl_4_data_11AC__fzgx_offset_62 != lbl_1_bss_962) {
        lbl_4_bss_2 = 0;
        lbl_4_data_11AC__fzgx_offset_60 = cursor.value;
        lbl_4_data_11AC__fzgx_offset_62 = lbl_1_bss_962;
    }

    packet = lbl_1_rodata_26F8;
    packet.image = 0x12;
    packet.x = 320.0f;
    packet.y = (f32)((cursor.value * 2 - 1) * 24 + 240);
    packet.z = 0.15f;
    packet.scale_x = (fn_4_7DEC_operand_((78.0), (width))) / 8.0;
    packet.scale_y = 3.5f;
    packet.flags = 10;
    packet.alpha = 0.3 * (1.0 + lbl_8006D188((s16)((lbl_4_bss_2 << 10) + 0x4000)));
    *(Color4 *)packet.color = *(const Color4 *)fzgx_pool_init_fzgx_pool_table2.v;
    fn_1_4F734(&packet);

    height = 72.0f;
    base = 48.0;
    margin = 96.0;
    fn_1_53BD8(0, 320.0f, 240.0f, margin + width, base + height, 0.25f);
    fn_1_1380F0(fzgx_pool_init_lbl_4_data_E8.v[lbl_801A66B4]);
    fn_1_13ABA8(0x28000000);
}
/* fzgx:end fn_4_7DEC */

/* fzgx:begin fn_4_80EC noprologue */
#include "types.h"

extern struct fn_4_80EC_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 lbl_4_data_2D5C;
extern void fn_4_7DEC(void);

struct fn_4_80EC_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
};

void fn_4_80EC(void) {
    struct fn_4_80EC_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t1;
    p_lbl_4_bss_0 = (struct fn_4_80EC_lbl_4_bss_0 *)&lbl_4_bss_0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_2D5C, (u32)fn_4_7DEC, 0, 5);
    p_lbl_4_bss_0->unk_0 = t1;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_80EC */

/* fzgx:begin fn_4_8158 */
#include "types.h"

struct fn_4_8158_lbl_4_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x1];
    u8 unk_D;
    u8 pad_E[0x2];
    u16 unk_10;
};

extern int fn_1_4C10(void);


extern u16 lbl_1_bss_96A;
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_4_0(u32, u32, u32, u32, u32);


extern u8 lbl_4_data_2D24[56];
extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);

void fn_4_8158(void) {
    struct fn_4_8158_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 v0;
    u32 t0, t2, t5;

    p_lbl_4_bss_0 = (struct fn_4_8158_lbl_4_bss_0 *)&(*(struct fn_4_8158_lbl_4_bss_0 *)&lbl_4_bss_0);
    if (p_lbl_4_bss_0->unk_10 != 0) {
        t0 = fn_1_4C10();
        if ((s32)t0 == 0) {
            fn_1_1280(1);
            lbl_1_bss_96A = p_lbl_4_bss_0->unk_10;
            p_lbl_4_bss_0->unk_10 = 0;
        }
    } else {
        t2 = fn_4_0(p_lbl_4_bss_0->unk_D, 0, 1, -1, 0);
        p_lbl_4_bss_0->unk_D = t2;
        v0 = *(u16 *)((u8 *)&lbl_1_bss_9F8 + 8);
        if (((v0 >> 9) & 1) != 0) {
            fn_1_A2D84(0xA9010200);
            p_lbl_4_bss_0->unk_10 = 75;
        } else if (((v0 >> 8) & 1) != 0) {
            fn_1_A2D84(0xA9010100);
            p_lbl_4_bss_0->unk_10 = *(s16 *)((u8 *)&lbl_4_data_2D24 + p_lbl_4_bss_0->unk_D * 28);
        } else {
            return;
        }
        fn_1_4A00(0, 15, p_lbl_4_bss_0->unk_8);
    }
}
/* fzgx:end fn_4_8158 */

/* fzgx:begin fn_4_8248 */
extern u32 fn_1_435C(u32);

/* Finalize the pending option state and clear its completion flag. */
void fn_4_8248(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_8248 */

/* fzgx:begin fn_4_869C noprologue */
#include "types.h"

extern struct fn_4_869C_lbl_1_bss_718E0 lbl_1_bss_718E0;
extern struct fn_4_869C_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 lbl_4_data_2D78;
extern void fn_4_82A0(void);

struct fn_4_869C_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0x26E];
    u8 unk_280;
    u8 pad_281[0x1];
    u8 unk_282;
    u8 unk_283;
};
struct fn_4_869C_lbl_1_bss_718E0 {
    u8 pad_0[0x3];
    u8 unk_3;
};

void fn_4_869C(void) {
    struct fn_4_869C_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t1;
    p_lbl_4_bss_0 = (struct fn_4_869C_lbl_4_bss_0 *)&lbl_4_bss_0;
    p_lbl_4_bss_0->unk_283 = lbl_1_bss_718E0.unk_3;
    p_lbl_4_bss_0->unk_282 = lbl_1_bss_718E0.unk_3;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_2D78, (u32)fn_4_82A0, 0, 5);
    p_lbl_4_bss_0->unk_0 = t1;
    p_lbl_4_bss_0->unk_280 = 0;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_869C */

/* fzgx:begin fn_4_8720 noprologue */
#include "types.h"

struct fn_4_8720_lbl_4_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x2];
    u8 unk_E;
    u8 pad_F[0x1];
    u16 unk_10;
    u8 pad_12[0xA6];
    u16 unk_B8;
    u8 pad_BA[0x1C6];
    u8 unk_280;
    u8 unk_281;
    u8 unk_282;
    u8 unk_283;
};
struct fn_4_8720_lbl_1_bss_9F8 {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
};
struct fn_4_8720_lbl_1_bss_718E0 {
    u8 pad_0[0x3];
    u8 unk_3;
};

extern struct fn_4_8720_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern struct fn_4_8720_lbl_4_bss_0 lbl_4_bss_0;
extern struct fn_4_8720_lbl_1_bss_718E0 lbl_1_bss_718E0;
extern u16 lbl_1_bss_96A;
extern int fn_1_4C10(void);
extern void fn_1_1280(u32);
extern u32 fn_4_0(u32, u32, u32, u32, u32);
extern void fn_1_A2D84(u32);
extern void fn_1_A6840(u32);
extern u32 fn_1_4A00(u32, u32, u32);

void fn_4_8720(void) {
    struct fn_4_8720_lbl_4_bss_0 *p = &lbl_4_bss_0;
    struct fn_4_8720_lbl_1_bss_9F8 *q;
    u16 v;

    if (p->unk_10 != 0) {
        if (fn_1_4C10() == 0) {
            fn_1_1280(1U);
            lbl_1_bss_96A = p->unk_10;
            p->unk_10 = 0;
        }
    } else if (p->unk_280 != 0) {
        p->unk_281 = fn_4_0(p->unk_281, 0U, 1U, -1U, 1U);
        q = &lbl_1_bss_9F8;
        if ((q->unk_8 >> 9U) & 1) {
            fn_1_A2D84(0xA9010200U);
            p->unk_280 = 0;
        } else if ((q->unk_8 >> 8U) & 1) {
            fn_1_A2D84(0xA9010100U);
            if (p->unk_281 == 0) {
                lbl_1_bss_718E0.unk_3 = p->unk_283;
                p->unk_E = 1;
            } else if (lbl_1_bss_718E0.unk_3 != p->unk_283) {
                fn_1_A6840(lbl_1_bss_718E0.unk_3);
            }
            if (p->unk_E != 0) {
                p->unk_B8 = 0x4B;
                p->unk_10 = 0x4C;
            } else {
                p->unk_10 = 0x4B;
                fn_1_4A00(0U, 0xFU, p->unk_8);
            }
        }
    } else {
        q = &lbl_1_bss_9F8;
        if ((((q->unk_10) & 1) || (lbl_1_bss_9F8.unk_12 & 1)) && p->unk_282 == 1) {
            p->unk_282 = 0;
            fn_1_A2D84(0xA9010000U);
        } else if ((((q->unk_10 >> 1U) & 1) || (lbl_1_bss_9F8.unk_12 >> 1U) & 1) && p->unk_282 == 0) {
            p->unk_282 = 1;
            fn_1_A2D84(0xA9010000U);
        }
        q = &lbl_1_bss_9F8;
        if (((q->unk_8 >> 8U) & 1) && p->unk_282 != p->unk_283) {
            fn_1_A2D84(0xA9010100U);
            fn_1_A6840(p->unk_282);
            p->unk_283 = p->unk_282;
        }
        if ((q->unk_8 >> 9U) & 1) {
            fn_1_A2D84(0xA9010200U);
            if (p->unk_283 != lbl_1_bss_718E0.unk_3) {
                p->unk_280 = 1;
                p->unk_281 = 0;
            } else {
                p->unk_10 = 0x4B;
                fn_1_4A00(0U, 0xFU, p->unk_8);
            }
        }
    }
}
/* fzgx:end fn_4_8720 */

/* fzgx:begin fn_4_898C */
extern u32 fn_1_435C(u32);

/* Reset the option state after releasing its active resource. */
void fn_4_898C(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_898C */

/* fzgx:begin fn_4_89E4 noprologue */
#include "types.h"

extern struct fn_4_89E4_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_4_AB30(void);
extern u32 lbl_4_data_2D8C;
extern void fn_4_AC58(void);

struct fn_4_89E4_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
};

void fn_4_89E4(void) {
    struct fn_4_89E4_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t2;
    p_lbl_4_bss_0 = (struct fn_4_89E4_lbl_4_bss_0 *)&lbl_4_bss_0;
    fn_4_AB30();
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t2 = fn_1_3F8C((u32)&lbl_4_data_2D8C, (u32)fn_4_AC58, 0, 5);
    p_lbl_4_bss_0->unk_0 = t2;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_89E4 */

/* fzgx:begin fn_4_8A54 */
extern int fn_1_4C10(void);
extern u16 lbl_1_bss_96A;
extern void fn_1_1280(u32);

extern u32 fn_1_4A00(u32, u32, u32);

/* Advance the option resource state and clear a completed selection. */
void fn_4_8A54(void) {
    u16 value;

    if (lbl_4_bss_10.unk_0 != 0) {
        if (fn_1_4C10() == 0) {
            fn_1_1280(1);
            value = lbl_4_bss_10.unk_0;
            lbl_1_bss_96A = value;
            lbl_4_bss_10.unk_0 = 0;
        }
    } else {
        value = fn_4_ABB0();
        lbl_4_bss_10.unk_0 = value;
        if (value != 0) {
            fn_1_4A00(0, 15, lbl_4_bss_8);
        }
    }
}
/* fzgx:end fn_4_8A54 */

/* fzgx:begin fn_4_8AE0 */
extern u32 fn_1_435C(u32);

// Completes the pending option callback and clears its handle.
void fn_4_8AE0(void) {
    fn_4_AB90();

    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_8AE0 */

/* fzgx:begin fn_4_8B3C noprologue */
#include "types.h"
#include "font.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 167.0f;
    s = 38.0f;
    s = 0.5f;
}
static const unsigned long fzgx_pool_table2[1] = {0x00D0D000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 78.0;
    d = 0.125;
    s = 2.9375f;
    s = 0.0f;
    d = 0.3;
    d = 1.0;
}
static const unsigned long fzgx_pool_table4[1] = {0x00D0D000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6000000238418579f;
}
static const unsigned long fzgx_pool_table6[1] = {0xFF000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.5f;
    s = 5.0f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 0.15000000596046448f;
    s = 240.0f;
}
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 96.0;
    d = 48.0;
    s = 0.25f;
}
static const unsigned long fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 0.004999999888241291f;
    s = 216.0f;
    d = 90.0;
    d = 320.0;
    d = 0.5;
    s = 264.0f;
}
static const unsigned long fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = -0.5;
    s = 0.014999999664723873f;
    s = 72.0f;
    s = 0.02500000037252903f;
    s = 0.05000000074505806f;
    s = 48.0f;
    s = 0.800000011920929f;
    s = 110.0f;
    s = 1.0f;
    s = 120.0f;
}
static const unsigned long fzgx_pool_table16[11] = {0x08080000, 0x78780000, 0x06060000, 0x25000000, 0x1A1A0000, 0x00250000, 0xE61A0000, 0xDB000000, 0xE6E60000, 0x00DB0000, 0x1AE60000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 1.3333333730697632f;
    s = 160.0f;
    s = 210.0f;
    s = 480.0f;
    s = -0.009999999776482582f;
    s = 1.100000023841858f;
    s = 1.399999976158142f;
    s = 20.0f;
    s = 10.0f;
    s = 0.009999999776482582f;
    s = 140.0f;
    s = 0.0010000000474974513f;
    s = 0.5625f;
    s = 0.75f;
    s = 24.0f;
    s = 105.0f;
    s = 345.0f;
}
static const unsigned long fzgx_pool_table18[6] = {0x00FF00FF, 0xFF000080, 0x0000FF80, 0x687EA0FF, 0x202020A0, 0xFFFFFF80};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -125.0f;
    s = 125.0f;
    s = -0.03999999910593033f;
    s = 100.0f;
    s = -0.04999999701976776f;
    s = 0.029999999329447746f;
    s = 90.0f;
    s = 135.0f;
    s = 300.0f;
    s = 50.0f;
    s = 192.0f;
    s = 380.0f;
    s = 64.0f;
    s = 280.0f;
    s = 576.0f;
    s = 2.0f;
    s = 32.0f;
    s = -10.0f;
}
static const unsigned long fzgx_pool_table20[6] = {0x687EA0FF, 0x00FF00FF, 0x202020A0, 0xFF000080, 0x0000FF80, 0xFFFF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.05999999865889549f;
    s = -0.03099999949336052f;
    s = -0.029999999329447746f;
    s = 1.2799999713897705f;
    s = 368.79998779296875f;
    s = 38.400001525878906f;
    s = 0.699999988079071f;
    s = 136.6999969482422f;
}
static const unsigned long fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 120.0;
    s = 0.20499999821186066f;
    s = 0.10500000417232513f;
    s = 416.0f;
    s = 3.0f;
    d = 24.0;
    d = 5.5;
    s = 0.10000000149011612f;
    s = 168.0f;
}
static const unsigned long fzgx_pool_table24[12] = {0xFFFFFFA0, 0xD0808000, 0xFFFFFF00, 0x80808000, 0xD0808000, 0xFFFFFF00, 0xD0808000, 0xFFFFFF00, 0x00FFFF00, 0x00808000, 0x00FFFF00, 0x00808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const unsigned long *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 274.0f;
    s = 573.0f;
    s = 271.0f;
    s = 0.8333333134651184f;
    d = 160.0;
    d = 20.0;
    d = 10.0;
    s = 500.0f;
}
static const unsigned long fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const unsigned long *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 64.99999845027924;
    s = 2.9166665077209473f;
    s = 62.0f;
    s = 350.0f;
    s = 248.0f;
    s = 0.5799999833106995f;
    s = 0.550000011920929f;
    s = 0.6366666555404663f;
    s = 434.0f;
    s = 377.0f;
    s = 400.0f;
    s = 75.0f;
    s = 370.0f;
    s = 144.0f;
    s = 0.3499999940395355f;
    s = 1.40625f;
    s = 0.30000001192092896f;
    s = 89.0f;
    s = 127.0f;
    s = 176.0f;
    s = 88.0f;
    s = 231.0f;
    s = 67.0f;
    s = 55.0f;
    s = 76.0f;
    s = 126.0f;
    s = 47.0f;
    d = 140.0;
    d = 1.40625;
    d = 144.0;
    s = 204.0f;
    s = 74.0f;
    s = 197.0f;
    s = 211.0f;
    s = 26.0f;
    s = 142.0f;
    s = 87.125f;
    s = 173.0f;
    s = 0.8500000238418579f;
    s = 328.5150146484375f;
    s = 59.0f;
    s = 134.0f;
    s = 128.0f;
    s = 194.0f;
    s = 141.0f;
    s = 189.0f;
    s = 108.0f;
    s = 60.0f;
    d = 192.0;
    d = 142.0;
    d = 87.125;
    d = 0.85;
    d = 173.0;
    s = 123.0f;
    s = 174.0f;
    s = 196.0f;
    s = 63.0f;
    s = 111.0f;
    s = 479.81500244140625f;
    s = 233.35000610351562f;
    s = 394.81500244140625f;
    s = 226.5500030517578f;
    s = 0.06000000238418579f;
    s = 0.07000000029802322f;
    s = 1.5f;
    s = 0.009999997913837433f;
    s = -1.0f;
    s = 8.0f;
}
static const unsigned long fzgx_pool_table28[8] = {0xA0505000, 0xA0A0A000, 0xFFFFFF00, 0x70707000, 0x00000000, 0x70707000, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const unsigned long *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 288.0f;
    s = 352.0f;
}
static const unsigned long fzgx_pool_table30[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const unsigned long *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table31[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const unsigned long *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 40.0f;
    s = 220.0f;
    s = 260.0f;
    s = 0.09000000357627869f;
    s = 41.5f;
}
#pragma section code_type ".text"

const u8 fzgx_pool_lbl_4_rodata_0[8] = {0x43,0x27,0x00,0x00,0x42,0x18,0x00,0x00};
const f32 fzgx_pool_lbl_4_rodata_0__fzgx_offset_8 = 0.5f;
const u8 fzgx_pool_lbl_4_rodata_0__fzgx_offset_10[24] = {0x40,0x53,0x80,0x00,0x00,0x00,0x00,0x00,0x3F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x3C,0x00,0x00,0x00,0x00,0x00,0x00};
const f64 fzgx_pool_lbl_4_rodata_0__fzgx_offset_28 = 0.29999999999999999;
const f64 fzgx_pool_lbl_4_rodata_0__fzgx_offset_30 = 1.0;
const u8 fzgx_pool_lbl_4_rodata_0__fzgx_offset_38[12] = {0x00,0xD0,0xD0,0x00,0x3F,0x19,0x99,0x9A,0xFF,0x00,0x00,0x00};
const f32 fzgx_pool_lbl_4_rodata_0__fzgx_offset_44 = 3.5f;
const f32 fzgx_pool_lbl_4_rodata_0__fzgx_offset_48 = 5.0f;
const u8 fzgx_pool_lbl_4_rodata_4C[4] = {0x00,0x00,0x00,0x00};
const f32 fzgx_pool_lbl_4_rodata_4C__fzgx_offset_4 = 320.0f;
const u8 fzgx_pool_lbl_4_rodata_4C__fzgx_offset_8[4] = {0x3E,0x19,0x99,0x9A};
const f32 fzgx_pool_lbl_4_rodata_4C__fzgx_offset_C = 240.0f;
const u8 fzgx_pool_lbl_4_rodata_4C__fzgx_offset_10[108] = {0x00,0x00,0x00,0x00,0x40,0x58,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x48,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x43,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x3B,0xA3,0xD7,0x0A,0x43,0x58,0x00,0x00,0x40,0x56,0x80,0x00,0x00,0x00,0x00,0x00,0x40,0x74,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x43,0x84,0x00,0x00,0x00,0x00,0x00,0x00,0xBF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x75,0xC2,0x8F,0x42,0x90,0x00,0x00,0x3C,0xCC,0xCC,0xCD,0x3D,0x4C,0xCC,0xCD,0x42,0x40,0x00,0x00,0x3F,0x4C,0xCC,0xCD};
const f32 fzgx_pool_lbl_4_rodata_4C__fzgx_offset_7C = 110.0f;
const u8 fzgx_pool_lbl_4_rodata_4C__fzgx_offset_80[52] = {0x3F,0x80,0x00,0x00,0x42,0xF0,0x00,0x00,0x08,0x08,0x00,0x00,0x78,0x78,0x00,0x00,0x06,0x06,0x00,0x00,0x25,0x00,0x00,0x00,0x1A,0x1A,0x00,0x00,0x00,0x25,0x00,0x00,0xE6,0x1A,0x00,0x00,0xDB,0x00,0x00,0x00,0xE6,0xE6,0x00,0x00,0x00,0xDB,0x00,0x00,0x1A,0xE6,0x00,0x00};
const u8 fzgx_pool_lbl_4_rodata_100[112] = {0x43,0x30,0x00,0x00,0x80,0x00,0x00,0x00,0x3F,0xAA,0xAA,0xAB,0x43,0x20,0x00,0x00,0x43,0x52,0x00,0x00,0x43,0xF0,0x00,0x00,0xBC,0x23,0xD7,0x0A,0x3F,0x8C,0xCC,0xCD,0x3F,0xB3,0x33,0x33,0x41,0xA0,0x00,0x00,0x41,0x20,0x00,0x00,0x3C,0x23,0xD7,0x0A,0x43,0x0C,0x00,0x00,0x3A,0x83,0x12,0x6F,0x3F,0x10,0x00,0x00,0x3F,0x40,0x00,0x00,0x41,0xC0,0x00,0x00,0x42,0xD2,0x00,0x00,0x43,0xAC,0x80,0x00,0x00,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x80,0x00,0x00,0xFF,0x80,0x68,0x7E,0xA0,0xFF,0x20,0x20,0x20,0xA0,0xFF,0xFF,0xFF,0x80,0xC2,0xFA,0x00,0x00,0x42,0xFA,0x00,0x00,0xBD,0x23,0xD7,0x0A};
const f32 fzgx_pool_lbl_4_rodata_100__fzgx_offset_70 = 100.0f;
const u8 fzgx_pool_lbl_4_rodata_100__fzgx_offset_74[156] = {0xBD,0x4C,0xCC,0xCC,0x3C,0xF5,0xC2,0x8F,0x42,0xB4,0x00,0x00,0x43,0x07,0x00,0x00,0x43,0x96,0x00,0x00,0x42,0x48,0x00,0x00,0x43,0x40,0x00,0x00,0x43,0xBE,0x00,0x00,0x42,0x80,0x00,0x00,0x43,0x8C,0x00,0x00,0x44,0x10,0x00,0x00,0x40,0x00,0x00,0x00,0x42,0x00,0x00,0x00,0xC1,0x20,0x00,0x00,0x68,0x7E,0xA0,0xFF,0x00,0xFF,0x00,0xFF,0x20,0x20,0x20,0xA0,0xFF,0x00,0x00,0x80,0x00,0x00,0xFF,0x80,0xFF,0xFF,0x00,0xFF,0xBD,0x75,0xC2,0x8F,0xBC,0xFD,0xF3,0xB6,0xBC,0xF5,0xC2,0x8F,0x3F,0xA3,0xD7,0x0A,0x43,0xB8,0x66,0x66,0x42,0x19,0x99,0x9A,0x3F,0x33,0x33,0x33,0x43,0x08,0xB3,0x33,0x00,0x00,0x00,0x00,0x40,0x5E,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x51,0xEB,0x85,0x3D,0xD7,0x0A,0x3E,0x43,0xD0,0x00,0x00,0x40,0x40,0x00,0x00,0x40,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x16,0x00,0x00,0x00,0x00,0x00,0x00};
const f32 fzgx_pool_lbl_4_rodata_100__fzgx_offset_110 = 0.100000001f;
const u8 fzgx_pool_lbl_4_rodata_100__fzgx_offset_114[116] = {0x43,0x28,0x00,0x00,0xFF,0xFF,0xFF,0xA0,0xD0,0x80,0x80,0x00,0xFF,0xFF,0xFF,0x00,0x80,0x80,0x80,0x00,0xD0,0x80,0x80,0x00,0xFF,0xFF,0xFF,0x00,0xD0,0x80,0x80,0x00,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0x80,0x80,0x00,0x00,0xFF,0xFF,0x00,0x00,0x80,0x80,0x00,0x43,0x89,0x00,0x00,0x44,0x0F,0x40,0x00,0x43,0x87,0x80,0x00,0x3F,0x55,0x55,0x55,0x40,0x64,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x43,0xFA,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x50,0x3F,0xFF,0xF9,0x80,0x00,0x00,0x40,0x3A,0xAA,0xAA,0x42,0x78,0x00,0x00};
const f32 fzgx_pool_lbl_4_rodata_100__fzgx_offset_188 = 350.0f;
const u8 fzgx_pool_lbl_4_rodata_100__fzgx_offset_18C[328] = {0x43,0x78,0x00,0x00,0x3F,0x14,0x7A,0xE1,0x3F,0x0C,0xCC,0xCD,0x3F,0x22,0xFC,0x96,0x43,0xD9,0x00,0x00,0x43,0xBC,0x80,0x00,0x43,0xC8,0x00,0x00,0x42,0x96,0x00,0x00,0x43,0xB9,0x00,0x00,0x43,0x10,0x00,0x00,0x3E,0xB3,0x33,0x33,0x3F,0xB4,0x00,0x00,0x3E,0x99,0x99,0x9A,0x42,0xB2,0x00,0x00,0x42,0xFE,0x00,0x00,0x43,0x30,0x00,0x00,0x42,0xB0,0x00,0x00,0x43,0x67,0x00,0x00,0x42,0x86,0x00,0x00,0x42,0x5C,0x00,0x00,0x42,0x98,0x00,0x00,0x42,0xFC,0x00,0x00,0x42,0x3C,0x00,0x00,0x40,0x61,0x80,0x00,0x00,0x00,0x00,0x00,0x3F,0xF6,0x80,0x00,0x00,0x00,0x00,0x00,0x40,0x62,0x00,0x00,0x00,0x00,0x00,0x00,0x43,0x4C,0x00,0x00,0x42,0x94,0x00,0x00,0x43,0x45,0x00,0x00,0x43,0x53,0x00,0x00,0x41,0xD0,0x00,0x00,0x43,0x0E,0x00,0x00,0x42,0xAE,0x40,0x00,0x43,0x2D,0x00,0x00,0x3F,0x59,0x99,0x9A,0x43,0xA4,0x41,0xEC,0x42,0x6C,0x00,0x00,0x43,0x06,0x00,0x00,0x43,0x00,0x00,0x00,0x43,0x42,0x00,0x00,0x43,0x0D,0x00,0x00,0x43,0x3D,0x00,0x00,0x42,0xD8,0x00,0x00,0x42,0x70,0x00,0x00,0x40,0x68,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x61,0xC0,0x00,0x00,0x00,0x00,0x00,0x40,0x55,0xC8,0x00,0x00,0x00,0x00,0x00,0x3F,0xEB,0x33,0x33,0x33,0x33,0x33,0x33,0x40,0x65,0xA0,0x00,0x00,0x00,0x00,0x00,0x42,0xF6,0x00,0x00,0x43,0x2E,0x00,0x00,0x43,0x44,0x00,0x00,0x42,0x7C,0x00,0x00,0x42,0xDE,0x00,0x00,0x43,0xEF,0xE8,0x52,0x43,0x69,0x59,0x9A,0x43,0xC5,0x68,0x52,0x43,0x62,0x8C,0xCD,0x3D,0x75,0xC2,0x90,0x3D,0x8F,0x5C,0x29,0x3F,0xC0,0x00,0x00,0x3C,0x23,0xD7,0x08,0xBF,0x80,0x00,0x00,0x41,0x00,0x00,0x00,0xA0,0x50,0x50,0x00,0xA0,0xA0,0xA0,0x00,0xFF,0xFF,0xFF,0x00,0x70,0x70,0x70,0x00,0x00,0x00,0x00,0x00,0x70,0x70,0x70,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x43,0x90,0x00,0x00,0x43,0xB0,0x00,0x00};
const f32 fzgx_pool_lbl_4_rodata_100__fzgx_offset_2DC = 40.0f;
const f32 fzgx_pool_lbl_4_rodata_100__fzgx_offset_2E0 = 220.0f;
const f32 fzgx_pool_lbl_4_rodata_100__fzgx_offset_2E4 = 260.0f;
const f32 fzgx_pool_lbl_4_rodata_100__fzgx_offset_2E8 = 0.0900000036f;
const f32 fzgx_pool_lbl_4_rodata_100__fzgx_offset_2EC = 41.5f;
const u8 fzgx_pool_lbl_4_rodata_100__fzgx_offset_2F0[32] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x3C,0xA3,0xD7,0x0C,0x3F,0x66,0x66,0x66,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
extern s32 lbl_801A66B4;
extern FontDrawPacket lbl_1_rodata_26F8;

/* The module's .data section, laid out as retail defines it (retail words; string
 * pointers are interior aliases the oracle binds to the retail targets). */
extern u8 lbl_4_data_0__fzgx_offset_0[];
extern u8 lbl_4_data_100__fzgx_offset_0[];
extern u8 lbl_4_data_10__fzgx_offset_0[];
extern u8 lbl_4_data_130__fzgx_offset_0[];
extern u8 lbl_4_data_170__fzgx_offset_0[];
extern u8 lbl_4_data_188__fzgx_offset_0[];
extern u8 lbl_4_data_1BC__fzgx_offset_0[];
extern u8 lbl_4_data_210__fzgx_offset_0[];
extern u8 lbl_4_data_254__fzgx_offset_0[];
extern u8 lbl_4_data_284__fzgx_offset_0[];
extern u8 lbl_4_data_2CC__fzgx_offset_0[];
extern u8 lbl_4_data_2F0__fzgx_offset_0[];
extern u8 lbl_4_data_32C__fzgx_offset_0[];
extern u8 lbl_4_data_34C__fzgx_offset_0[];
extern u8 lbl_4_data_37C__fzgx_offset_0[];
extern u8 lbl_4_data_38__fzgx_offset_0[];
extern u8 lbl_4_data_3B8__fzgx_offset_0[];
extern u8 lbl_4_data_400__fzgx_offset_0[];
extern u8 lbl_4_data_438__fzgx_offset_0[];
extern u8 lbl_4_data_480__fzgx_offset_0[];
extern u8 lbl_4_data_4C__fzgx_offset_0[];
extern u8 lbl_4_data_4F0__fzgx_offset_0[];
extern u8 lbl_4_data_578__fzgx_offset_0[];
extern u8 lbl_4_data_57C__fzgx_offset_0[];
extern u8 lbl_4_data_59C__fzgx_offset_0[];
extern u8 lbl_4_data_5A0__fzgx_offset_0[];
extern u8 lbl_4_data_5C0__fzgx_offset_0[];
extern u8 lbl_4_data_5D8__fzgx_offset_0[];
extern u8 lbl_4_data_610__fzgx_offset_0[];
extern u8 lbl_4_data_660__fzgx_offset_0[];
extern u8 lbl_4_data_6D4__fzgx_offset_0[];
extern u8 lbl_4_data_724__fzgx_offset_0[];
extern u8 lbl_4_data_78__fzgx_offset_0[];
extern u8 lbl_4_data_790__fzgx_offset_0[];
extern u8 lbl_4_data_7C__fzgx_offset_0[];
extern u8 lbl_4_data_7DC__fzgx_offset_0[];
extern u8 lbl_4_data_85C__fzgx_offset_0[];
extern u8 lbl_4_data_86C__fzgx_offset_0[];
extern u8 lbl_4_data_89C__fzgx_offset_0[];
extern u8 lbl_4_data_8A8__fzgx_offset_0[];
extern u8 lbl_4_data_8D8__fzgx_offset_0[];
extern u8 lbl_4_data_8F8__fzgx_offset_0[];
extern u8 lbl_4_data_918__fzgx_offset_0[];
extern u8 lbl_4_data_934__fzgx_offset_0[];
extern u8 lbl_4_data_970__fzgx_offset_0[];
extern u8 lbl_4_data_984__fzgx_offset_0[];
extern u8 lbl_4_data_9C0__fzgx_offset_0[];
extern u8 lbl_4_data_9D8__fzgx_offset_0[];
extern u8 lbl_4_data_A10__fzgx_offset_0[];
extern u8 lbl_4_data_A30__fzgx_offset_0[];
extern u8 lbl_4_data_A70__fzgx_offset_0[];
extern u8 lbl_4_data_A78__fzgx_offset_0[];
extern u8 lbl_4_data_AA0__fzgx_offset_0[];
extern u8 lbl_4_data_AAC__fzgx_offset_0[];
extern u8 lbl_4_data_AD4__fzgx_offset_0[];
extern u8 lbl_4_data_B0__fzgx_offset_0[];
extern u8 lbl_4_data_B90__fzgx_offset_0[];
extern u8 lbl_4_data_C18__fzgx_offset_0[];
extern u8 lbl_4_data_C8__fzgx_offset_0[];
extern u8 lbl_4_data_CB0__fzgx_offset_0[];
extern u8 lbl_4_data_C__fzgx_offset_0[];
extern u8 lbl_4_data_D50__fzgx_offset_0[];
extern u8 lbl_4_data_D64__fzgx_offset_0[];
extern u8 lbl_4_data_D84__fzgx_offset_0[];
extern u8 lbl_4_data_D98__fzgx_offset_0[];
extern u8 lbl_4_data_DB8__fzgx_offset_0[];
extern u8 lbl_4_data_DF0__fzgx_offset_0[];
extern u8 lbl_4_data_E48__fzgx_offset_0[];
extern u8 lbl_4_data_E58__fzgx_offset_0[];
extern u8 lbl_4_data_E88__fzgx_offset_0[];
extern u8 lbl_4_data_E98__fzgx_offset_0[];
/* retail pointer word: address of a string in the same .data section */
#define P(off) ((u32)lbl_4_data_##off##__fzgx_offset_0)

static union { u32 w[58]; void *v[0x3A]; } fzgx_pool_init_lbl_4_data_0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x436F6E74, 0x726F6C6C, 0x65720000, 0x0, 0x83528393, 0x8367838D, 0x815B8389, 0x0,  /* fzgx-allow: A1 retail data bytes */
    P(0), P(C), P(C), P(C), P(C), P(10), 0x436F6E74, 0x726F6C6C,
    0x65722053, 0x6F636B65, 0x74000000, 0x83528393, 0x8367838D, 0x815B8389, 0x837C815B, 0x83670000,  /* fzgx-allow: A1 retail data bytes */
    P(38), P(C), P(C), P(C), P(C), P(4C), 0x4F4E0000, 0x4F464600,
    P(78), P(C), P(C), P(C), P(C), P(78), P(7C), P(C),
    P(C), P(C), P(7C), 0x0, 0x55736520, 0x83AD206F, 0x722083B5, 0x20746F20,
    0x63686F6F, 0x73652E00, 0x83AD82A9, 0x83B582C5, 0x8D8096DA, 0x82F09149, 0x82F182C5, 0x82AD82BE,
    0x82B382A2, 0x81420000  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[47]; void *v[0x2F]; } fzgx_pool_init_lbl_4_data_E8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    P(B0), P(C), P(C), P(C), P(C), P(C8), 0x4D6F7665, 0x2083AD20,
    0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063, 0x68616E67, 0x6520636F,
    0x6E74726F, 0x6C732E00, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C59180, 0x8DEC82F0, 0x95CF8D58,
    0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, P(100), P(C), P(C), P(C),  /* fzgx-allow: A1 retail data bytes */
    P(C), P(130), 0x506C6561, 0x73652077, 0x61697420, 0x61206D6F, 0x6D656E74, 0x2E2E2E00,
    0x82B582CE, 0x82E782AD, 0x82A891D2, 0x82BF82AD, 0x82BE82B3, 0x82A28142, 0x0
}};
static union { u32 w[803]; void *v[0x323]; } fzgx_pool_init_lbl_4_data_1A4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    P(170), P(C), P(C), P(C), P(C), P(188), 0x50726573, 0x73207468,
    0x65204120, 0x42757474, 0x6F6E206F, 0x6E207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0x20746F20,
    0x62652061, 0x646A7573, 0x7465642E, 0x20507265, 0x73732074, 0x68652042, 0x20427574, 0x746F6E20,
    0x746F2066, 0x696E6973, 0x682E0000, 0x95CF8D58, 0x82B782E9, 0x83528393, 0x8367838D, 0x815B8389,  /* fzgx-allow: A1 retail data bytes */
    0x82C5839F, 0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, P(1BC), P(C),  /* fzgx-allow: A1 retail data bytes */
    P(C), P(C), P(C), P(210), 0x526F7461, 0x74652074, 0x68652043, 0x6F6E7472,
    0x6F6C2053, 0x7469636B, 0x206F6E65, 0x2066756C, 0x6C207265, 0x766F6C75, 0x74696F6E, 0x2E000000,
    0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E82F0, 0x88EA9474, 0x82C989F1,  /* fzgx-allow: A1 retail data bytes */
    0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, P(254), P(C), P(C), P(C),  /* fzgx-allow: A1 retail data bytes */
    P(C), P(284), 0x506C6561, 0x73652061, 0x646A7573, 0x74207468, 0x65207374, 0x65657269,
    0x6E672077, 0x6865656C, 0x2E000000, 0x836E8393, 0x8368838B, 0x82CC92B2, 0x90AE82F0, 0x8D7382C8,
    0x82C182C4, 0x82AD82BE, 0x82B382A2, 0x81420000, P(2CC), P(C), P(C), P(C),  /* fzgx-allow: A1 retail data bytes */
    P(C), P(2F0), 0x52657475, 0x726E2074, 0x6F207468, 0x65206465, 0x6661756C, 0x74207365,
    0x7474696E, 0x67733F00, 0x8F898AFA, 0x90DD92E8, 0x82C996DF, 0x82B582DC, 0x82B782A9, 0x81480000,  /* fzgx-allow: A1 retail data bytes */
    P(32C), P(C), P(C), P(C), P(C), P(34C), 0x53656C65, 0x63742074,
    0x68652043, 0x6F6E7472, 0x6F6C6C65, 0x7220746F, 0x20626520, 0x6368616E, 0x67656420, 0x7573696E,
    0x67206569, 0x74686572, 0x2083AD20, 0x6F722083, 0xB52E0000, 0x83AD82A9, 0x83B582C5, 0x95CF8D58,
    0x82B782E9, 0x83528393, 0x8367838D, 0x815B8389, 0x82F09149, 0x82F182C5, 0x82AD82BE, 0x82B382A2,  /* fzgx-allow: A1 retail data bytes */
    0x81420000, P(37C), P(C), P(C), P(C), P(C), P(3B8), 0x4D6F7665,  /* fzgx-allow: A1 retail data bytes */
    0x2083AD20, 0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063, 0x68616E67,
    0x65205275, 0x6D626C65, 0x20736574, 0x74696E67, 0x732E0000, 0x83AD82A9, 0x83B582CC, 0x8DB68945,
    0x82C59055, 0x93AE82CC, 0x90DD92E8, 0x82F095CF, 0x8D5882B5, 0x82C482AD, 0x82BE82B3, 0x82A28142,
    0x0, P(400), P(C), P(C), P(C), P(C), P(438), 0x54686520,
    0x436F6E74, 0x726F6C6C, 0x65722068, 0x61732062, 0x65656E20, 0x64697363, 0x6F6E6E65, 0x63746564,
    0x2E0A2052, 0x65636F6E, 0x6E656374, 0x20746865, 0x20436F6E, 0x74726F6C, 0x6C657220, 0x696E2053,
    0x6F636B65, 0x74202564, 0x206F720A, 0x20707265, 0x73732074, 0x68652041, 0x20427574, 0x746F6E20,
    0x6F6E2061, 0x6E6F7468, 0x65722E00, 0x83528393, 0x8367838D, 0x815B8389, 0x82AA8A4F, 0x82B382EA,  /* fzgx-allow: A1 retail data bytes */
    0x82DC82B5, 0x82BD8142, 0xA835283, 0x93836783, 0x8D815B83, 0x89837C81, 0x5B836725, 0x6482C982,
    0xB382B582, 0xC882A882, 0xB782A981, 0x410A91BC, 0x82CC8352, 0x83938367, 0x838D815B, 0x838982C5,
    0x839F837B, 0x835E8393, 0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, P(480),  /* fzgx-allow: A1 retail data bytes */
    P(C), P(C), P(C), P(C), P(4F0), 0x59455300, 0x82CD82A2, 0x0,
    P(578), P(C), P(C), P(C), P(C), P(57C), 0x4E4F0000, 0x82A282A2,
    0x82A60000, P(59C), P(C), P(C), P(C), P(C), P(5A0), 0x4368616E,
    0x6765204F, 0x7074696F, 0x6E205365, 0x7474696E, 0x67730000, 0x83498376, 0x83568387, 0x839390DD,
    0x92E882F0, 0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0, P(5C0), P(C), P(C),
    P(C), P(C), P(5D8), 0x41646A75, 0x73742074, 0x68652043, 0x616C6962, 0x72617469,
    0x6F6E2E0A, 0x50726573, 0x73207468, 0x65204120, 0x42757474, 0x6F6E206F, 0x6E207468, 0x6520436F,
    0x6E74726F, 0x6C6C6572, 0xA796F75, 0x2077616E, 0x74206164, 0x6A757374, 0x65642E00, 0x83528393,
    0x8367838D, 0x815B8389, 0x82CC834C, 0x8383838A, 0x8375838C, 0x815B8356, 0x83878393, 0x82F08D73,  /* fzgx-allow: A1 retail data bytes */
    0x82C882A2, 0x82DC82B7, 0x81420A95, 0xCF8D5882, 0xB782E983, 0x52839383, 0x67838D81, 0x5B838982,  /* fzgx-allow: A1 retail data bytes */
    0xC5839F82, 0xF0899F82, 0xB582C482, 0xAD82BE82, 0xB382A281, 0x42000000, P(610), P(C),
    P(C), P(C), P(C), P(660), 0x43757374, 0x6F6D697A, 0x65207468, 0x6520436F,
    0x6E74726F, 0x6C6C6572, 0x2E0A5072, 0x65737320, 0x74686520, 0x41204275, 0x74746F6E, 0x206F6E20,
    0x74686520, 0x436F6E74, 0x726F6C6C, 0x65722074, 0x6F206265, 0x2061646A, 0x75737465, 0x642E0000,
    0x83528393, 0x8367838D, 0x815B8389, 0x82CC834A, 0x8358835E, 0x837D8343, 0x835982F0, 0x8D7382C8,  /* fzgx-allow: A1 retail data bytes */
    0x82A282DC, 0x82B78142, 0xA95CF8D, 0x5882B782, 0xE9835283, 0x93836783, 0x8D815B83, 0x8982C583,
    0x9F82F089, 0x9F82B582, 0xC482AD82, 0xBE82B382, 0xA2814200, P(6D4), P(C), P(C),
    P(C), P(C), P(724), 0x436F6E74, 0x726F6C6C, 0x65722052, 0x756D626C, 0x65205365,
    0x7474696E, 0x67732E0A, 0x20507265, 0x73732074, 0x68652041, 0x20427574, 0x746F6E20, 0x746F2073,
    0x656C6563, 0x74207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0x2E000000, 0x83528393, 0x8367838D,
    0x815B8389, 0x82CC9055, 0x93AE82CC, 0x90DD92E8, 0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420A83,  /* fzgx-allow: A1 retail data bytes */
    0x52839383, 0x67838D81, 0x5B838982, 0xF0914982, 0xF182C583, 0x9F82F089, 0x9F82B582, 0xC482AD82,
    0xBE82B382, 0xA2814200, P(790), P(C), P(C), P(C), P(C), P(7DC),
    P(400), P(C), P(C), P(C), P(C), P(438), 0x53617665, 0x20636861,
    0x6E676573, 0x3F000000, 0x95CF8D58, 0x82F095DB, 0x91B682B5, 0x82DC82B7, 0x82A98148, 0x0,
    P(85C), P(C), P(C), P(C), P(C), P(86C), 0x49732074, 0x68697320,
    0x4F4B3F00, 0x82B182EA, 0x82C582E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x81480000, P(89C),  /* fzgx-allow: A1 retail data bytes */
    P(C), P(C), P(C), P(C), P(8A8), 0x8163826E, 0x826D0000, P(8D8),  /* fzgx-allow: A1 retail data bytes */
    P(C), P(C), P(C), P(C), P(8D8), 0x826E8265, 0x82650000, P(8F8),
    P(C), P(C), P(C), P(C), P(8F8), 0x4368616E, 0x67652043, 0x6F6E7472,
    0x6F6C6C65, 0x72205365, 0x7474696E, 0x67730000, 0x83528393, 0x8367838D, 0x815B8389, 0x82CC90DD,  /* fzgx-allow: A1 retail data bytes */
    0x92E882F0, 0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0, P(918), P(C), P(C),
    P(C), P(C), P(934), 0x4D616E61, 0x6765204D, 0x656D6F72, 0x79204361, 0x72640000,
    0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x8AC7979D, 0x82F08D73, 0x82C882A2, 0x82DC82B7,
    0x81420000, P(970), P(C), P(C), P(C), P(C), P(984), 0x53656C65,  /* fzgx-allow: A1 retail data bytes */
    0x63742053, 0x63726565, 0x6E205365, 0x7474696E, 0x67732000, 0x89E696CA, 0x8382815B, 0x836882CC,
    0x90DD92E8, 0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420000, P(9C0), P(C), P(C),  /* fzgx-allow: A1 retail data bytes */
    P(C), P(C), P(9D8), 0x55736520, 0x83AD206F, 0x722083B5, 0x20746F20, 0x63686F6F,
    0x73652061, 0x206D6F64, 0x65200000, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C58382, 0x815B8368,  /* fzgx-allow: A1 retail data bytes */
    0x82F09149, 0x82F182C5, 0x82AD82BE, 0x82B382A2, 0x81420000, P(A10), P(C), P(C),  /* fzgx-allow: A1 retail data bytes */
    P(C), P(C), P(A30), 0x4E6F726D, 0x616C0000, 0x836D815B, 0x837D838B, 0x8365838C,
    0x83720000, P(A70), P(C), P(C), P(C), P(C), P(A78), 0x57696465,
    0x20536372, 0x65656E00, 0x838F8343, 0x83688365, 0x838C8372, 0x0, P(AA0), P(C),
    P(C), P(C), P(C), P(AAC), 0x4D6F7665, 0x20746865, 0x20436F6E, 0x74726F6C,
    0x20537469, 0x636B2061, 0x726F756E, 0x6420696E, 0x20612063, 0x6972636C, 0x6520756E, 0x74696C20,
    0x74686520, 0x66696775, 0x72657320, 0x6F6E2074, 0x68650A20, 0x6C656674, 0x20736964, 0x6520646F,
    0x206E6F74, 0x20636861, 0x6E67652E, 0x2041646A, 0x75737420, 0x706C6179, 0x20757369, 0x6E672074,
    0x68652083, 0xB520436F, 0x6E74726F, 0x6C205061, 0x642E0A20, 0x50726573, 0x73207468, 0x65205820,
    0x42757474, 0x6F6E2074, 0x6F207265, 0x7475726E, 0x20746F20, 0x74686520, 0x64656661, 0x756C7420,
    0x73657474, 0x696E6773, 0x2E000000, 0x8DB691A4, 0x82CC907D, 0x8C6082AA, 0x95CF89BB, 0x82B582C8,
    0x82AD82C8, 0x82E982DC, 0x82C583AD, 0x82F088EA, 0x947482C9, 0x89F182B5, 0x82C482AD, 0x82BE82B3,
    0x82A28142, 0xA83B582, 0xC5975682, 0xD182F092, 0xB290AE82, 0xB582C482, 0xAD82BE82, 0xB382A281,
    0x420A83B4, 0x82C58F89, 0x8AFA90DD, 0x92E882C9, 0x96DF82B9, 0x82DC82B7, 0x81420000, P(AD4),  /* fzgx-allow: A1 retail data bytes */
    P(C), P(C), P(C), P(C), P(B90), 0x5475726E, 0x20746865, 0x20737465,
    0x6572696E, 0x67207768, 0x65656C20, 0x4C656674, 0x20616E64, 0x20526967, 0x68742061, 0x6E642070,
    0x72657373, 0xA746865, 0x20412042, 0x7574746F, 0x6E206174, 0x20746865, 0x20706F69, 0x6E742079,
    0x6F752077, 0x616E7420, 0x746F2073, 0x65742061, 0x73207468, 0x650A206C, 0x696D6974, 0x2E205573,
    0x65207468, 0x65204C20, 0x616E6420, 0x52204275, 0x74746F6E, 0x7320746F, 0x2061646A, 0x75737420,
    0x67616D65, 0x20706C61, 0x792E2000, 0x836E8393, 0x8368838B, 0x82F08DB6, 0x894582C9, 0x89F182B5,
    0x81418CC0, 0x8A4582C6, 0x82B582BD, 0x82A288CA, 0x927582C5, 0x839F82F0, 0x899F82B5, 0x82C482AD,  /* fzgx-allow: A1 retail data bytes */
    0x82BE82B3, 0x82A28142, 0xA826B81, 0x95827183, 0x67838A83, 0x4B815B83, 0x7B835E83, 0x9382C597,
    0x5682D182, 0xF092B290, 0xAE82B582, 0xC482AD82, 0xBE82B382, 0xA281420A, 0x83B482C5, 0x8F898AFA,
    0x90DD92E8, 0x82C996DF, 0x82B982DC, 0x82B78142, 0x0, P(C18), P(C), P(C),
    P(C), P(C), P(CB0), 0x4265666F, 0x72652063, 0x6F727265, 0x6374696F, 0x6E000000,
    0x95E290B3, 0x914F0000, P(D50), P(C), P(C), P(C), P(C), P(D64),
    0x41667465, 0x7220636F, 0x72726563, 0x74696F6E, 0x0, 0x95E290B3, 0x8CE30000, P(D84),
    P(C), P(C), P(C), P(C), P(D98), 0x47616D65, 0x20446174, 0x6120436F,
    0x6E74726F, 0x6C730A49, 0x6E736572, 0x74206120, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E746F,
    0x20536C6F, 0x7420412E, 0x0, 0x8351815B, 0x83808366, 0x815B835E, 0x82CC9180, 0x8DEC0A83,  /* fzgx-allow: A1 retail data bytes */
    0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F083, 0x58838D83, 0x62836782, 0x6082C993, 0xFC82EA82,
    0xC482AD82, 0xBE82B382, 0xA2814200
}};
static union { u32 w[16]; const char *v[0x10]; } fzgx_pool_init_lbl_4_data_E30 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    P(DB8), P(C), P(C), P(C), P(C), P(DF0), 0x4C6F6164, 0x2047616D,
    0x65204461, 0x74610000, 0x8351815B, 0x83808366, 0x815B835E, 0x82CC838D, 0x815B8368, 0x0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[16]; const char *v[0x10]; } fzgx_pool_init_lbl_4_data_E70 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    P(E48), P(C), P(C), P(C), P(C), P(E58), 0x53617665, 0x2047616D,
    0x65204461, 0x74610000, 0x8351815B, 0x83808366, 0x815B835E, 0x82CC835A, 0x815B8375, 0x0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[16]; const char *v[0x10]; } fzgx_pool_init_lbl_4_data_EB0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    P(E88), P(C), P(C), P(C), P(C), P(E98), 0x54686572, 0x65206973,
    0x206E6F20, 0x47616D65, 0x20446174, 0x61206F6E, 0x20746869, 0x73204D65, 0x6D6F7279, 0x20436172
}};
#undef P
#define lbl_4_data_0   (fzgx_pool_init_lbl_4_data_0.v)
#define lbl_4_data_E8  (fzgx_pool_init_lbl_4_data_E8.v)
#define lbl_4_data_1A4 (fzgx_pool_init_lbl_4_data_1A4.v)
#define lbl_4_data_E30 (fzgx_pool_init_lbl_4_data_E30.v)
#define lbl_4_data_E70 (fzgx_pool_init_lbl_4_data_E70.v)
#define lbl_4_data_EB0 (fzgx_pool_init_lbl_4_data_EB0.v)

extern u8 fn_1_B7C00(void);
extern void fn_1_49410(void);
extern void fn_1_495C8(u8);
extern void fn_1_5233C(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4D274(u32 *, f32);
extern void fn_1_53BD8(u32 *, f32, f32, f32, f32, f32);
extern f32 lbl_8006D188(s16);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_1380F0(void *);
extern void fn_1_13ABA8(u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u16 fzgx_obj_lbl_4_bss_0;
u8 fzgx_obj_lbl_4_bss_2;
u8 fzgx_pool_lbl_4_bss_0_gap_3;
u32 fzgx_obj_lbl_4_bss_4;
u32 fzgx_obj_lbl_4_bss_8;
u8 lbl_4_bss_C;
u8 lbl_4_bss_D;
u16 fzgx_pool_lbl_4_bss_0_gap_E;
u16 fzgx_obj_lbl_4_bss_10;
u16 lbl_4_bss_10__fzgx_offset_2;
u32 lbl_4_bss_10__fzgx_offset_4[44];
u32 fzgx_obj_lbl_4_bss_C4[112];
u8 lbl_4_bss_C4__fzgx_offset_1C0;
u8 lbl_4_bss_C4__fzgx_offset_1C1;
u8 lbl_4_bss_C4__fzgx_offset_1C2;
u8 lbl_4_bss_C4__fzgx_offset_1C3;
u32 lbl_4_bss_C4__fzgx_offset_1C4[5348];

#pragma section code_type ".fzgxpool"
static void fzgx_base_order_data(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: the TU references .data before its other sections */
    s = *(u8 *)&lbl_4_data_0;
    s = *(u8 *)&lbl_4_data_E8;
    s = *(u8 *)&lbl_4_data_1A4;
    s = *(u8 *)&lbl_4_data_E30;
    s = *(u8 *)&lbl_4_data_E70;
    s = *(u8 *)&lbl_4_data_EB0;
}
#pragma section code_type ".text"

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_4_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_2;
    s = *(u8 *)&fzgx_pool_lbl_4_bss_0_gap_3;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_4;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_8;
    s = *(u8 *)&lbl_4_bss_C;
    s = *(u8 *)&lbl_4_bss_D;
    s = *(u8 *)&fzgx_pool_lbl_4_bss_0_gap_E;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_10;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_2;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_C4;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1C0;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1C1;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1C2;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1C3;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1C4;
}
#pragma section code_type ".text"

/* Draws the controller-setup option screen: title, instructions, the selection cursor. */
void fn_4_8B3C(void) {
    FontDrawPacket packet;
    u32 color = fzgx_pool_table30[0];
    u32 shadow;
    void *message = lbl_4_data_1A4[lbl_801A66B4];
    u32 flags = 0;

    if (fzgx_obj_lbl_4_bss_10 == 0 && fn_1_B7C00() == 0) {
        if (lbl_4_bss_C4__fzgx_offset_1C1 == 3) {
            return;
        }
        if (lbl_4_bss_C4__fzgx_offset_1C1 != 4) {
            fn_1_49410();
            fn_1_495C8(9);
            fn_1_49738(fn_1_5233C);
            fn_1_49748(fzgx_pool_lbl_4_rodata_0__fzgx_offset_48);
            if (lbl_801A66B4 != 5) {
                fn_1_495B0(0x80000000);
                fn_1_49590(fzgx_pool_lbl_4_rodata_0__fzgx_offset_8);
            }
            fn_1_4D0A0();
            fn_1_496FC(fzgx_pool_lbl_4_rodata_4C__fzgx_offset_4, fzgx_pool_lbl_4_rodata_4C__fzgx_offset_7C);
            fn_1_4A0D8(lbl_4_data_E30[lbl_801A66B4]);
            shadow = fzgx_pool_table31[0];
            fn_1_4D274(&shadow, fzgx_pool_lbl_4_rodata_100__fzgx_offset_2DC);
            if (lbl_4_bss_C4__fzgx_offset_1C1 == 0) {
                fn_1_496FC(fzgx_pool_lbl_4_rodata_4C__fzgx_offset_4, fzgx_pool_lbl_4_rodata_100__fzgx_offset_2E0);
                fn_1_4A0D8(lbl_4_data_E70[lbl_801A66B4]);
                fn_1_496FC(fzgx_pool_lbl_4_rodata_4C__fzgx_offset_4, fzgx_pool_lbl_4_rodata_100__fzgx_offset_2E4);
                fn_1_4A0D8(lbl_4_data_EB0[lbl_801A66B4]);
                fn_1_53BD8(&color, fzgx_pool_lbl_4_rodata_4C__fzgx_offset_4, fzgx_pool_lbl_4_rodata_4C__fzgx_offset_C, fzgx_pool_lbl_4_rodata_100__fzgx_offset_188,
                           fzgx_pool_lbl_4_rodata_100__fzgx_offset_70, fzgx_pool_lbl_4_rodata_100__fzgx_offset_110);
                if (lbl_4_bss_C4__fzgx_offset_1C0 != lbl_4_bss_C4__fzgx_offset_1C2) {
                    lbl_4_bss_C4__fzgx_offset_1C0 = lbl_4_bss_C4__fzgx_offset_1C2;
                    fzgx_obj_lbl_4_bss_2 = 0;
                }
                packet = lbl_1_rodata_26F8;
                packet.image = 18;
                packet.x = fzgx_pool_lbl_4_rodata_4C__fzgx_offset_4;
                packet.y = lbl_4_bss_C4__fzgx_offset_1C2 * 40 + 220;
                packet.z = fzgx_pool_lbl_4_rodata_100__fzgx_offset_2E8;
                packet.scale_x = fzgx_pool_lbl_4_rodata_100__fzgx_offset_2EC;
                packet.scale_y = fzgx_pool_lbl_4_rodata_0__fzgx_offset_44;
                packet.flags = 10;
                /* the cursor pulses: the colour word is written after the alpha is computed */
                packet.alpha = fzgx_pool_lbl_4_rodata_0__fzgx_offset_28 * (fzgx_pool_lbl_4_rodata_0__fzgx_offset_30 + lbl_8006D188((fzgx_obj_lbl_4_bss_2 << 10) + 0x4000));
                *(u32 *)packet.color = fzgx_pool_table2[0];
                fn_1_4F734(&packet);
                message = lbl_4_data_E8[lbl_801A66B4];
                flags = 0x28000000;
            }
        }
    }
    fn_1_1380F0(message);
    fn_1_13ABA8(flags);
}
/* fzgx:end fn_4_8B3C */

/* fzgx:begin fn_4_8DC0 noprologue */
#include "types.h"

extern struct fn_4_8DC0_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 lbl_4_data_2D9C;
extern void fn_4_8B3C(void);

struct fn_4_8DC0_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0x273];
    u8 unk_285;
    u8 unk_286;
};

void fn_4_8DC0(void) {
    struct fn_4_8DC0_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t1;
    p_lbl_4_bss_0 = (struct fn_4_8DC0_lbl_4_bss_0 *)&lbl_4_bss_0;
    p_lbl_4_bss_0->unk_286 = 0;
    p_lbl_4_bss_0->unk_285 = 0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_2D9C, (u32)fn_4_8B3C, 0, 5);
    p_lbl_4_bss_0->unk_0 = t1;
    p_lbl_4_bss_0->unk_10 = 0;
    fn_1_4A00(1, 15, p_lbl_4_bss_0->unk_8);
}
/* fzgx:end fn_4_8DC0 */

/* fzgx:begin fn_4_9A78 */
extern u32 fn_1_435C(u32);

// Finalizes the pending option callback and clears its handle.
void fn_4_9A78(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_9A78 */

/* fzgx:begin fn_4_9AD0 */
void fn_4_9AD0(void) {
    if (lbl_4_bss_5618 != 0) {
    fn_1_1380F0(*(u32 *)((u8 *)&lbl_4_data_1A4 + (lbl_801A66B4 << 2)));
    fn_1_13ABA8(0);
    }
}
/* fzgx:end fn_4_9AD0 */

/* fzgx:begin fn_4_9B20 noprologue */
#include "types.h"

extern u32 fn_1_B7E98(u32);
extern u32 fn_1_B800C(u32);
extern u32 fn_1_B80F0(u32);
extern u32 fn_1_B8170(u32);
extern u32 lbl_4_data_2DB4;
extern void fn_4_9AD0(void);

struct fn_4_9B20_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x285];
    u8 unk_291;
    u8 pad_292[0x2];
    u8 unk_294;
    u8 pad_295[0x5383];
    u8 unk_5618;
    u8 unk_5619;
    u8 unk_561A;
    u8 unk_561B;
    u32 unk_561C;
    u8 unk_5620;
    u8 unk_5621;
    u8 unk_5622;
};

extern struct fn_4_9B20_lbl_4_bss_0 lbl_4_bss_0;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);

s32 fn_4_9B20(void) {
    struct fn_4_9B20_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 v0;
    u32 t1, t2, t3, t4, t5;
    p_lbl_4_bss_0 = (struct fn_4_9B20_lbl_4_bss_0 *)&lbl_4_bss_0;
    fn_1_435C(p_lbl_4_bss_0->unk_8);
    t1 = fn_1_3F8C((u32)&lbl_4_data_2DB4, (u32)fn_4_9AD0, 0, 5);
    p_lbl_4_bss_0->unk_0 = t1;
    p_lbl_4_bss_0->unk_5618 = 1;
    p_lbl_4_bss_0->unk_5619 = 0;
    p_lbl_4_bss_0->unk_561A = 0;
    p_lbl_4_bss_0->unk_561B = 0;
    p_lbl_4_bss_0->unk_294 = 0;
    p_lbl_4_bss_0->unk_561C = 0;
    t2 = fn_1_B7E98(0);
    v0 = t2;
    if ((s32)t2 != 0) {
    v0 = 0;
    v0 = (fn_1_B800C(v0));
    if ((s32)v0 == 0) {
    v0 = 0;
    t4 = fn_1_B8170(v0);
    v0 = t4;
    if ((v0 & 0x2) == 0) {
    v0 = 1;
    p_lbl_4_bss_0->unk_561B = v0;
    p_lbl_4_bss_0->unk_561C = 120;
    p_lbl_4_bss_0->unk_5619 = v0;
    p_lbl_4_bss_0->unk_291 = v0;
    p_lbl_4_bss_0->unk_561A = v0;
    }
    }
    v0 = 0;
    t5 = fn_1_B80F0(v0);
    v0 = t5;
    v0 = 1;
    p_lbl_4_bss_0->unk_5620 = v0;
    p_lbl_4_bss_0->unk_5621 = v0;
    p_lbl_4_bss_0->unk_5622 = 0;
    } else {
    v0 = 0;
    p_lbl_4_bss_0->unk_5620 = v0;
    p_lbl_4_bss_0->unk_5621 = v0;
    p_lbl_4_bss_0->unk_5622 = 120;
    }
    return v0;
}
/* fzgx:end fn_4_9B20 */

/* fzgx:begin fn_4_9C14 noprologue */
#include "types.h"
#include "rel/option/globals.h"

typedef struct { u32 unk_0; u32 unk_4; } Sig_fn_1_B7F58_Result;
typedef struct { u8 r, g, b, a; } Sig_fn_800081C8_Color;
typedef Sig_fn_800081C8_Color Sig_fn_1_4D4C8_Color4_4D4C8;

struct fn_4_9C14_lbl_4_rodata_0 {
    u8 pad_0[0x8]; f32 unk_8;
    u8 pad_C[0x40]; f32 unk_4C; f32 unk_50;
    u8 pad_54[0x78]; f32 unk_CC;
    u8 pad_D0[0x58]; f32 unk_128;
    u8 pad_12C[0x10]; f32 unk_13C;
    u8 pad_140[0x25C]; f32 unk_39C; f32 unk_3A0; f32 unk_3A4; f32 unk_3A8;
    u32 unk_3AC; u32 unk_3B0; u32 unk_3B4; u32 unk_3B8; u32 unk_3BC;
    u32 unk_3C0; u32 unk_3C4; u32 unk_3C8; f32 unk_3CC; f32 unk_3D0;
    u8 pad_3D4[8]; f32 unk_3DC; f32 unk_3E0;
    u8 pad_3E4[0x14]; f32 unk_3F8;
    u8 pad_3FC[4]; u32 unk_400; u32 unk_404; u32 unk_408; u32 unk_40C;
};
struct fn_4_9C14_Save { u32 words[0x14D8]; };
struct fn_4_9C14_lbl_1_bss_9F8 {
    u8 pad_0[8]; u16 unk_8; u8 pad_A[6]; u16 unk_10; u16 unk_12;
};
struct fn_4_9C14_Request { u8 unk_0; u8 pad_1[3]; u32 unk_4; void *unk_8; void *unk_C; u8 pad_10[0x14]; };
extern struct fn_4_9C14_lbl_4_rodata_0 lbl_4_rodata_0;
extern s32 lbl_801A66B4[1];
extern struct fn_4_9C14_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern u16 lbl_1_bss_96A;
extern u8 lbl_1_bss_8B3A0[];
extern u32 lbl_1_bss_7F0C0[0x14D8];
extern u8 lbl_1_bss_718E0[];
extern u32 *lbl_1_bss_718C0;
extern void fn_1_4D0A0(void);
extern u32 fn_1_4AEC0(u32);
extern void fn_1_4AEB4(f32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4D2AC(void *, f32, f32);
extern int fn_1_4C10(void);
extern void fn_1_1280(u32);
extern int fn_1_B7F58(Sig_fn_1_B7F58_Result *);
extern void fn_1_A2D84(u32);
extern u32 fn_800081C8(Sig_fn_800081C8_Color *, Sig_fn_800081C8_Color *, f32);
extern void fn_1_4D494(void);
extern void fn_1_49514(u32 *);
extern void fn_1_49528(u32 *);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D4C8(Sig_fn_1_4D4C8_Color4_4D4C8 *, f32, f32);
extern void fn_4_D1A8(u32, u32, u8);
extern void fn_4_D760(void);
extern s32 fn_4_D420(void);
extern void fn_4_D848(u32);
extern void fn_4_D878(void);
extern void fn_4_A78C(u32);
extern int fn_1_B7E98(int);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_4FD64(void);
extern s32 fn_1_F7954(void);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_F7A20(void);
extern void fn_1_B7CE4(u32, void *);
extern char *strcat(char *, const char *);
extern char *fn_80083DB0(char *, const char *);
extern void fn_1_B7E14(void *);
extern u32 fn_1_C3688(void);
extern void fn_1_AA6D8(u32, u32, void *);
extern u8 fn_1_B7C00(void);
extern int fn_1_B7CD4(void);

/* file-scope .data objects of the retail TU, in retail order (message tables per language) */
extern u8 lbl_4_data_0__fzgx_offset_0[];
extern u8 lbl_4_data_100__fzgx_offset_0[];
extern u8 lbl_4_data_107C__fzgx_offset_0[];
extern u8 lbl_4_data_10A0__fzgx_offset_0[];
extern u8 lbl_4_data_10E8__fzgx_offset_0[];
extern u8 lbl_4_data_10__fzgx_offset_0[];
extern u8 lbl_4_data_111C__fzgx_offset_0[];
extern u8 lbl_4_data_116C__fzgx_offset_0[];
extern u8 lbl_4_data_11AC__fzgx_offset_0[];
extern u8 lbl_4_data_130__fzgx_offset_0[];
extern u8 lbl_4_data_170__fzgx_offset_0[];
extern u8 lbl_4_data_188__fzgx_offset_0[];
extern u8 lbl_4_data_1BC__fzgx_offset_0[];
extern u8 lbl_4_data_210__fzgx_offset_0[];
extern u8 lbl_4_data_254__fzgx_offset_0[];
extern u8 lbl_4_data_284__fzgx_offset_0[];
extern u8 lbl_4_data_2CC__fzgx_offset_0[];
extern u8 lbl_4_data_2F0__fzgx_offset_0[];
extern u8 lbl_4_data_32C__fzgx_offset_0[];
extern u8 lbl_4_data_34C__fzgx_offset_0[];
extern u8 lbl_4_data_37C__fzgx_offset_0[];
extern u8 lbl_4_data_38__fzgx_offset_0[];
extern u8 lbl_4_data_3B8__fzgx_offset_0[];
extern u8 lbl_4_data_400__fzgx_offset_0[];
extern u8 lbl_4_data_438__fzgx_offset_0[];
extern u8 lbl_4_data_480__fzgx_offset_0[];
extern u8 lbl_4_data_4C__fzgx_offset_0[];
extern u8 lbl_4_data_4F0__fzgx_offset_0[];
extern u8 lbl_4_data_578__fzgx_offset_0[];
extern u8 lbl_4_data_57C__fzgx_offset_0[];
extern u8 lbl_4_data_59C__fzgx_offset_0[];
extern u8 lbl_4_data_5A0__fzgx_offset_0[];
extern u8 lbl_4_data_5C0__fzgx_offset_0[];
extern u8 lbl_4_data_5D8__fzgx_offset_0[];
extern u8 lbl_4_data_610__fzgx_offset_0[];
extern u8 lbl_4_data_660__fzgx_offset_0[];
extern u8 lbl_4_data_6D4__fzgx_offset_0[];
extern u8 lbl_4_data_724__fzgx_offset_0[];
extern u8 lbl_4_data_78__fzgx_offset_0[];
extern u8 lbl_4_data_790__fzgx_offset_0[];
extern u8 lbl_4_data_7C__fzgx_offset_0[];
extern u8 lbl_4_data_7DC__fzgx_offset_0[];
extern u8 lbl_4_data_85C__fzgx_offset_0[];
extern u8 lbl_4_data_86C__fzgx_offset_0[];
extern u8 lbl_4_data_89C__fzgx_offset_0[];
extern u8 lbl_4_data_8A8__fzgx_offset_0[];
extern u8 lbl_4_data_8D8__fzgx_offset_0[];
extern u8 lbl_4_data_8F8__fzgx_offset_0[];
extern u8 lbl_4_data_918__fzgx_offset_0[];
extern u8 lbl_4_data_934__fzgx_offset_0[];
extern u8 lbl_4_data_970__fzgx_offset_0[];
extern u8 lbl_4_data_984__fzgx_offset_0[];
extern u8 lbl_4_data_9C0__fzgx_offset_0[];
extern u8 lbl_4_data_9D8__fzgx_offset_0[];
extern u8 lbl_4_data_A10__fzgx_offset_0[];
extern u8 lbl_4_data_A30__fzgx_offset_0[];
extern u8 lbl_4_data_A70__fzgx_offset_0[];
extern u8 lbl_4_data_A78__fzgx_offset_0[];
extern u8 lbl_4_data_AA0__fzgx_offset_0[];
extern u8 lbl_4_data_AAC__fzgx_offset_0[];
extern u8 lbl_4_data_AD4__fzgx_offset_0[];
extern u8 lbl_4_data_B0__fzgx_offset_0[];
extern u8 lbl_4_data_B90__fzgx_offset_0[];
extern u8 lbl_4_data_C18__fzgx_offset_0[];
extern u8 lbl_4_data_C8__fzgx_offset_0[];
extern u8 lbl_4_data_CB0__fzgx_offset_0[];
extern u8 lbl_4_data_C__fzgx_offset_0[];
extern u8 lbl_4_data_D50__fzgx_offset_0[];
extern u8 lbl_4_data_D64__fzgx_offset_0[];
extern u8 lbl_4_data_D84__fzgx_offset_0[];
extern u8 lbl_4_data_D98__fzgx_offset_0[];
extern u8 lbl_4_data_DB8__fzgx_offset_0[];
extern u8 lbl_4_data_DF0__fzgx_offset_0[];
extern u8 lbl_4_data_E48__fzgx_offset_0[];
extern u8 lbl_4_data_E58__fzgx_offset_0[];
extern u8 lbl_4_data_E88__fzgx_offset_0[];
extern u8 lbl_4_data_E98__fzgx_offset_0[];
extern u8 lbl_4_data_EC8__fzgx_offset_0[];
extern u8 lbl_4_data_F08__fzgx_offset_0[];
extern u8 lbl_4_data_F64__fzgx_offset_0[];
extern u8 lbl_4_data_FD8__fzgx_offset_0[];
static union { u32 w[353]; char v[0x584]; } fzgx_pool_init_fzgx_obj_lbl_4_data_0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x436F6E74, 0x726F6C6C, 0x65720000, 0x0, 0x83528393, 0x8367838D, 0x815B8389, 0x0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, 0x436F6E74, 0x726F6C6C,
    0x65722053, 0x6F636B65, 0x74000000, 0x83528393, 0x8367838D, 0x815B8389, 0x837C815B, 0x83670000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_38__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_4C__fzgx_offset_0, 0x4F4E0000, 0x4F464600,
    (u32)lbl_4_data_78__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_78__fzgx_offset_0, (u32)lbl_4_data_7C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_7C__fzgx_offset_0, 0x0, 0x55736520, 0x83AD206F, 0x722083B5, 0x20746F20,
    0x63686F6F, 0x73652E00, 0x83AD82A9, 0x83B582C5, 0x8D8096DA, 0x82F09149, 0x82F182C5, 0x82AD82BE,
    0x82B382A2, 0x81420000, (u32)lbl_4_data_B0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C8__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x4D6F7665, 0x2083AD20, 0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063,
    0x68616E67, 0x6520636F, 0x6E74726F, 0x6C732E00, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C59180,
    0x8DEC82F0, 0x95CF8D58, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_100__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_130__fzgx_offset_0, 0x506C6561, 0x73652077, 0x61697420, 0x61206D6F,
    0x6D656E74, 0x2E2E2E00, 0x82B582CE, 0x82E782AD, 0x82A891D2, 0x82BF82AD, 0x82BE82B3, 0x82A28142,
    0x0, (u32)lbl_4_data_170__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_188__fzgx_offset_0, 0x50726573,
    0x73207468, 0x65204120, 0x42757474, 0x6F6E206F, 0x6E207468, 0x6520436F, 0x6E74726F, 0x6C6C6572,
    0x20746F20, 0x62652061, 0x646A7573, 0x7465642E, 0x20507265, 0x73732074, 0x68652042, 0x20427574,
    0x746F6E20, 0x746F2066, 0x696E6973, 0x682E0000, 0x95CF8D58, 0x82B782E9, 0x83528393, 0x8367838D,
    0x815B8389, 0x82C5839F, 0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_1BC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_210__fzgx_offset_0, 0x526F7461, 0x74652074, 0x68652043,
    0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x206F6E65, 0x2066756C, 0x6C207265, 0x766F6C75, 0x74696F6E,
    0x2E000000, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E82F0, 0x88EA9474,  /* fzgx-allow: A1 retail data bytes */
    0x82C989F1, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_254__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_284__fzgx_offset_0, 0x506C6561, 0x73652061, 0x646A7573, 0x74207468, 0x65207374,
    0x65657269, 0x6E672077, 0x6865656C, 0x2E000000, 0x836E8393, 0x8368838B, 0x82CC92B2, 0x90AE82F0,
    0x8D7382C8, 0x82C182C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_2CC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2F0__fzgx_offset_0, 0x52657475, 0x726E2074, 0x6F207468, 0x65206465, 0x6661756C,
    0x74207365, 0x7474696E, 0x67733F00, 0x8F898AFA, 0x90DD92E8, 0x82C996DF, 0x82B582DC, 0x82B782A9,
    0x81480000, (u32)lbl_4_data_32C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_34C__fzgx_offset_0, 0x53656C65,  /* fzgx-allow: A1 retail data bytes */
    0x63742074, 0x68652043, 0x6F6E7472, 0x6F6C6C65, 0x7220746F, 0x20626520, 0x6368616E, 0x67656420,
    0x7573696E, 0x67206569, 0x74686572, 0x2083AD20, 0x6F722083, 0xB52E0000, 0x83AD82A9, 0x83B582C5,
    0x95CF8D58, 0x82B782E9, 0x83528393, 0x8367838D, 0x815B8389, 0x82F09149, 0x82F182C5, 0x82AD82BE,  /* fzgx-allow: A1 retail data bytes */
    0x82B382A2, 0x81420000, (u32)lbl_4_data_37C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_3B8__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x4D6F7665, 0x2083AD20, 0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063,
    0x68616E67, 0x65205275, 0x6D626C65, 0x20736574, 0x74696E67, 0x732E0000, 0x83AD82A9, 0x83B582CC,
    0x8DB68945, 0x82C59055, 0x93AE82CC, 0x90DD92E8, 0x82F095CF, 0x8D5882B5, 0x82C482AD, 0x82BE82B3,
    0x82A28142, 0x0, (u32)lbl_4_data_400__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_438__fzgx_offset_0,
    0x54686520, 0x436F6E74, 0x726F6C6C, 0x65722068, 0x61732062, 0x65656E20, 0x64697363, 0x6F6E6E65,
    0x63746564, 0x2E0A2052, 0x65636F6E, 0x6E656374, 0x20746865, 0x20436F6E, 0x74726F6C, 0x6C657220,
    0x696E2053, 0x6F636B65, 0x74202564, 0x206F720A, 0x20707265, 0x73732074, 0x68652041, 0x20427574,
    0x746F6E20, 0x6F6E2061, 0x6E6F7468, 0x65722E00, 0x83528393, 0x8367838D, 0x815B8389, 0x82AA8A4F,  /* fzgx-allow: A1 retail data bytes */
    0x82B382EA, 0x82DC82B5, 0x82BD8142, 0xA835283, 0x93836783, 0x8D815B83, 0x89837C81, 0x5B836725,
    0x6482C982, 0xB382B582, 0xC882A882, 0xB782A981, 0x410A91BC, 0x82CC8352, 0x83938367, 0x838D815B,
    0x838982C5, 0x839F837B, 0x835E8393, 0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_480__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_4F0__fzgx_offset_0, 0x59455300, 0x82CD82A2,
    0x0
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_lbl_4_data_584 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_578__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_57C__fzgx_offset_0
}};
static union { u32 w[3]; char v[0xC]; } fzgx_pool_init_lbl_4_data_59C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F0000, 0x82A282A2, 0x82A60000
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_lbl_4_data_5A8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_59C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_5A0__fzgx_offset_0
}};
static union { u32 w[611]; char v[0x98C]; } fzgx_pool_init_lbl_4_data_5C0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4368616E, 0x6765204F, 0x7074696F, 0x6E205365, 0x7474696E, 0x67730000, 0x83498376, 0x83568387,
    0x839390DD, 0x92E882F0, 0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0, (u32)lbl_4_data_5C0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_5D8__fzgx_offset_0, 0x41646A75, 0x73742074, 0x68652043, 0x616C6962,
    0x72617469, 0x6F6E2E0A, 0x50726573, 0x73207468, 0x65204120, 0x42757474, 0x6F6E206F, 0x6E207468,
    0x6520436F, 0x6E74726F, 0x6C6C6572, 0xA796F75, 0x2077616E, 0x74206164, 0x6A757374, 0x65642E00,
    0x83528393, 0x8367838D, 0x815B8389, 0x82CC834C, 0x8383838A, 0x8375838C, 0x815B8356, 0x83878393,  /* fzgx-allow: A1 retail data bytes */
    0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420A95, 0xCF8D5882, 0xB782E983, 0x52839383, 0x67838D81,  /* fzgx-allow: A1 retail data bytes */
    0x5B838982, 0xC5839F82, 0xF0899F82, 0xB582C482, 0xAD82BE82, 0xB382A281, 0x42000000, (u32)lbl_4_data_610__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_660__fzgx_offset_0, 0x43757374, 0x6F6D697A, 0x65207468,
    0x6520436F, 0x6E74726F, 0x6C6C6572, 0x2E0A5072, 0x65737320, 0x74686520, 0x41204275, 0x74746F6E,
    0x206F6E20, 0x74686520, 0x436F6E74, 0x726F6C6C, 0x65722074, 0x6F206265, 0x2061646A, 0x75737465,
    0x642E0000, 0x83528393, 0x8367838D, 0x815B8389, 0x82CC834A, 0x8358835E, 0x837D8343, 0x835982F0,  /* fzgx-allow: A1 retail data bytes */
    0x8D7382C8, 0x82A282DC, 0x82B78142, 0xA95CF8D, 0x5882B782, 0xE9835283, 0x93836783, 0x8D815B83,
    0x8982C583, 0x9F82F089, 0x9F82B582, 0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_6D4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_724__fzgx_offset_0, 0x436F6E74, 0x726F6C6C, 0x65722052, 0x756D626C,
    0x65205365, 0x7474696E, 0x67732E0A, 0x20507265, 0x73732074, 0x68652041, 0x20427574, 0x746F6E20,
    0x746F2073, 0x656C6563, 0x74207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0x2E000000, 0x83528393,
    0x8367838D, 0x815B8389, 0x82CC9055, 0x93AE82CC, 0x90DD92E8, 0x82F08D73, 0x82C882A2, 0x82DC82B7,  /* fzgx-allow: A1 retail data bytes */
    0x81420A83, 0x52839383, 0x67838D81, 0x5B838982, 0xF0914982, 0xF182C583, 0x9F82F089, 0x9F82B582,  /* fzgx-allow: A1 retail data bytes */
    0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_790__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_7DC__fzgx_offset_0, (u32)lbl_4_data_400__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_438__fzgx_offset_0, 0x53617665,
    0x20636861, 0x6E676573, 0x3F000000, 0x95CF8D58, 0x82F095DB, 0x91B682B5, 0x82DC82B7, 0x82A98148,
    0x0, (u32)lbl_4_data_85C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_86C__fzgx_offset_0, 0x49732074,
    0x68697320, 0x4F4B3F00, 0x82B182EA, 0x82C582E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x81480000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_89C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8A8__fzgx_offset_0, 0x8163826E, 0x826D0000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_8D8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8D8__fzgx_offset_0, 0x826E8265, 0x82650000,
    (u32)lbl_4_data_8F8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8F8__fzgx_offset_0, 0x4368616E, 0x67652043,
    0x6F6E7472, 0x6F6C6C65, 0x72205365, 0x7474696E, 0x67730000, 0x83528393, 0x8367838D, 0x815B8389,  /* fzgx-allow: A1 retail data bytes */
    0x82CC90DD, 0x92E882F0, 0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0, (u32)lbl_4_data_918__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_934__fzgx_offset_0, 0x4D616E61, 0x6765204D, 0x656D6F72, 0x79204361,
    0x72640000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x8AC7979D, 0x82F08D73, 0x82C882A2,
    0x82DC82B7, 0x81420000, (u32)lbl_4_data_970__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_984__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x53656C65, 0x63742053, 0x63726565, 0x6E205365, 0x7474696E, 0x67732000, 0x89E696CA, 0x8382815B,
    0x836882CC, 0x90DD92E8, 0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420000, (u32)lbl_4_data_9C0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_9D8__fzgx_offset_0, 0x55736520, 0x83AD206F, 0x722083B5, 0x20746F20,
    0x63686F6F, 0x73652061, 0x206D6F64, 0x65200000, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C58382,
    0x815B8368, 0x82F09149, 0x82F182C5, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_A10__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_A30__fzgx_offset_0, 0x4E6F726D, 0x616C0000, 0x836D815B, 0x837D838B,
    0x8365838C, 0x83720000, (u32)lbl_4_data_A70__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_A78__fzgx_offset_0,
    0x57696465, 0x20536372, 0x65656E00, 0x838F8343, 0x83688365, 0x838C8372, 0x0, (u32)lbl_4_data_AA0__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_AAC__fzgx_offset_0, 0x4D6F7665, 0x20746865, 0x20436F6E,
    0x74726F6C, 0x20537469, 0x636B2061, 0x726F756E, 0x6420696E, 0x20612063, 0x6972636C, 0x6520756E,
    0x74696C20, 0x74686520, 0x66696775, 0x72657320, 0x6F6E2074, 0x68650A20, 0x6C656674, 0x20736964,
    0x6520646F, 0x206E6F74, 0x20636861, 0x6E67652E, 0x2041646A, 0x75737420, 0x706C6179, 0x20757369,
    0x6E672074, 0x68652083, 0xB520436F, 0x6E74726F, 0x6C205061, 0x642E0A20, 0x50726573, 0x73207468,
    0x65205820, 0x42757474, 0x6F6E2074, 0x6F207265, 0x7475726E, 0x20746F20, 0x74686520, 0x64656661,
    0x756C7420, 0x73657474, 0x696E6773, 0x2E000000, 0x8DB691A4, 0x82CC907D, 0x8C6082AA, 0x95CF89BB,
    0x82B582C8, 0x82AD82C8, 0x82E982DC, 0x82C583AD, 0x82F088EA, 0x947482C9, 0x89F182B5, 0x82C482AD,
    0x82BE82B3, 0x82A28142, 0xA83B582, 0xC5975682, 0xD182F092, 0xB290AE82, 0xB582C482, 0xAD82BE82,
    0xB382A281, 0x420A83B4, 0x82C58F89, 0x8AFA90DD, 0x92E882C9, 0x96DF82B9, 0x82DC82B7, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_AD4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_B90__fzgx_offset_0, 0x5475726E, 0x20746865,
    0x20737465, 0x6572696E, 0x67207768, 0x65656C20, 0x4C656674, 0x20616E64, 0x20526967, 0x68742061,
    0x6E642070, 0x72657373, 0xA746865, 0x20412042, 0x7574746F, 0x6E206174, 0x20746865, 0x20706F69,
    0x6E742079, 0x6F752077, 0x616E7420, 0x746F2073, 0x65742061, 0x73207468, 0x650A206C, 0x696D6974,
    0x2E205573, 0x65207468, 0x65204C20, 0x616E6420, 0x52204275, 0x74746F6E, 0x7320746F, 0x2061646A,
    0x75737420, 0x67616D65, 0x20706C61, 0x792E2000, 0x836E8393, 0x8368838B, 0x82F08DB6, 0x894582C9,
    0x89F182B5, 0x81418CC0, 0x8A4582C6, 0x82B582BD, 0x82A288CA, 0x927582C5, 0x839F82F0, 0x899F82B5,  /* fzgx-allow: A1 retail data bytes */
    0x82C482AD, 0x82BE82B3, 0x82A28142, 0xA826B81, 0x95827183, 0x67838A83, 0x4B815B83, 0x7B835E83,
    0x9382C597, 0x5682D182, 0xF092B290, 0xAE82B582, 0xC482AD82, 0xBE82B382, 0xA281420A, 0x83B482C5,
    0x8F898AFA, 0x90DD92E8, 0x82C996DF, 0x82B982DC, 0x82B78142, 0x0, (u32)lbl_4_data_C18__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_CB0__fzgx_offset_0, 0x4265666F, 0x72652063, 0x6F727265, 0x6374696F,
    0x6E000000, 0x95E290B3, 0x914F0000, (u32)lbl_4_data_D50__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_D64__fzgx_offset_0, 0x41667465, 0x7220636F, 0x72726563, 0x74696F6E, 0x0, 0x95E290B3, 0x8CE30000,
    (u32)lbl_4_data_D84__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_D98__fzgx_offset_0, 0x47616D65, 0x20446174,
    0x6120436F, 0x6E74726F, 0x6C730A49, 0x6E736572, 0x74206120, 0x4D656D6F, 0x72792043, 0x61726420,
    0x696E746F, 0x20536C6F, 0x7420412E, 0x0, 0x8351815B, 0x83808366, 0x815B835E, 0x82CC9180,  /* fzgx-allow: A1 retail data bytes */
    0x8DEC0A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F083, 0x58838D83, 0x62836782, 0x6082C993,
    0xFC82EA82, 0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_DB8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_DF0__fzgx_offset_0, 0x4C6F6164, 0x2047616D, 0x65204461, 0x74610000, 0x8351815B, 0x83808366,
    0x815B835E, 0x82CC838D, 0x815B8368, 0x0, (u32)lbl_4_data_E48__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_E58__fzgx_offset_0, 0x53617665, 0x2047616D, 0x65204461, 0x74610000, 0x8351815B, 0x83808366,
    0x815B835E, 0x82CC835A, 0x815B8375, 0x0, (u32)lbl_4_data_E88__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_E98__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20, 0x47616D65, 0x20446174, 0x61206F6E,
    0x20746869, 0x73204D65, 0x6D6F7279, 0x20436172, 0x642E0A20, 0x53617669, 0x6E67206E, 0x65772064,
    0x6174612E, 0x0, 0x83818382, 0x838A815B, 0x834A815B, 0x836882C9, 0xA835181, 0x5B838083,
    0x66815B83, 0x5E82AA8C, 0xA982C282, 0xA982E882, 0xDC82B982, 0xF181420A, 0x90568B4B, 0x835A815B,
    0x837582B5, 0x82DC82B7, 0x81420000  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_lbl_4_data_F4C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_EC8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_F08__fzgx_offset_0
}};
static union { u32 w[64]; char v[0x100]; } fzgx_pool_init_lbl_4_data_F64 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x54686572, 0x65206973, 0x206E6F20, 0x47616D65, 0x20446174, 0x61206F6E, 0x20746865, 0x204D656D,
    0x6F727920, 0x43617264, 0x2E0A4966, 0x20796F75, 0x20736176, 0x652C2074, 0x68652047, 0x616D6520,
    0x44617461, 0x20637572, 0x72656E74, 0x6C79206C, 0x6F616465, 0x640A7769, 0x6C6C2061, 0x6C6C2062,
    0x65206C6F, 0x73742E20, 0x49732074, 0x68617420, 0x4F4B3F00, 0x83818382, 0x838A815B, 0x834A815B,
    0x836882C9, 0x8351815B, 0x83808366, 0x815B835E, 0x82AA8CA9, 0x82C282A9, 0x82E882DC, 0x82B982F1,  /* fzgx-allow: A1 retail data bytes */
    0x81420A90, 0x568B4B83, 0x5A815B83, 0x7582B782, 0xE982C68C, 0xBB8DDD83, 0x8D815B83, 0x6882B382,  /* fzgx-allow: A1 retail data bytes */
    0xEA82C482, 0xA282E983, 0x51815B83, 0x80836681, 0x5B835E82, 0xAA0A9153, 0x82C48FC1, 0x82A682C4,  /* fzgx-allow: A1 retail data bytes */
    0x82B582DC, 0x82A282DC, 0x82B782AA, 0x814182E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x3F000000  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_lbl_4_data_1064 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_F64__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_FD8__fzgx_offset_0
}};
static union { u32 w[54]; char v[0xD8]; } fzgx_pool_init_lbl_4_data_107C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x54686572, 0x65206973, 0x206E6F20, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x6C6F7420,
    0x412E0000, 0x8358838D, 0x83628367, 0x826082C9, 0xA838183, 0x82838A81, 0x5B834A81, 0x5B836882,
    0xAA8CA982, 0xC282A982, 0xE882DC82, 0xB982F181, 0x42000000, (u32)lbl_4_data_107C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10A0__fzgx_offset_0, 0x52656769, 0x73746572, 0x20746869, 0x73206E61, 0x6D65206F,
    0x6E207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420696E, 0x20536C6F, 0x7420412E, 0x0,
    0x82B182CC, 0x96BC914F, 0x82C58381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C90A93, 0x6F985E82,  /* fzgx-allow: A1 retail data bytes */
    0xB582C482, 0xE082E682, 0xEB82B582, 0xA282C582, 0xB782A93F, 0x0
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_lbl_4_data_1154 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_10E8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_111C__fzgx_offset_0
}};
static union { u32 w[34]; char v[0x88]; } fzgx_pool_init_lbl_4_data_116C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x54686572, 0x65206973, 0x206E6F20, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x6C6F7420,
    0x412E0A20, 0x54686520, 0x67616D65, 0x2063616E, 0x6E6F7420, 0x62652073, 0x61766564, 0x2E000000,
    0x8358838D, 0x83628367, 0x826082C9, 0x83818382, 0x838A815B, 0x834A815B, 0x836882AA, 0x8CA982C2,
    0x82A982E8, 0x82DC82B9, 0x82F18142, 0xA835A81, 0x5B837582, 0xC582AB82, 0xDC82B982, 0xF182C582,
    0xB582BD81, 0x42000000
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_lbl_4_data_11F4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_116C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_11AC__fzgx_offset_0
}};
static union { u32 w[1]; char v[4]; } fzgx_pool_init_lbl_4_data_120C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFF00FFFF
}};
static union { u32 w[1]; char v[4]; } fzgx_pool_init_lbl_4_data_1210 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x257300FF
}};

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u16 fzgx_obj_lbl_4_bss_0;
u8 fzgx_obj_lbl_4_bss_2;
u8 fzgx_pool_lbl_4_bss_0_gap_3;
u32 fzgx_obj_lbl_4_bss_4;
u32 fzgx_obj_lbl_4_bss_8;
u8 lbl_4_bss_C;
u8 lbl_4_bss_D;
u8 fzgx_pool_lbl_4_bss_0_gap_E;
u8 fzgx_pool_lbl_4_bss_0_gap_E_fill_F;
u16 fzgx_obj_lbl_4_bss_10;
u16 lbl_4_bss_10__fzgx_offset_2;
u32 lbl_4_bss_10__fzgx_offset_4[41];
u16 lbl_4_bss_10__fzgx_offset_A8;
u16 lbl_4_bss_10__fzgx_offset_AA;
u32 lbl_4_bss_10__fzgx_offset_AC[2];
u32 fzgx_obj_lbl_4_bss_C4[115];
u8 lbl_4_bss_C4__fzgx_offset_1CC;
u8 lbl_4_bss_C4__fzgx_offset_1CD;
u16 lbl_4_bss_C4__fzgx_offset_1CE;
u8 lbl_4_bss_C4__fzgx_offset_1D0;
u8 lbl_4_bss_C4__fzgx_offset_1D1;
u16 lbl_4_bss_C4__fzgx_offset_1D2;
u32 lbl_4_bss_C4__fzgx_offset_1D4[8];
u32 lbl_4_bss_C4__fzgx_offset_1F4[0x14D8];
u8 lbl_4_bss_5618;
u8 lbl_4_bss_5618__fzgx_offset_1;
u8 lbl_4_bss_5618__fzgx_offset_2;
u8 lbl_4_bss_5618__fzgx_offset_3;
u32 lbl_4_bss_5618__fzgx_offset_4;
u8 lbl_4_bss_5618__fzgx_offset_8;
u8 lbl_4_bss_5618__fzgx_offset_9;
u8 lbl_4_bss_5618__fzgx_offset_A;
u8 lbl_4_bss_5618__fzgx_offset_B;
u32 lbl_4_bss_5618__fzgx_offset_C;

#pragma section code_type ".fzgxpool"

#pragma section code_type ".fzgxpool"
static void fzgx_base_order_data(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: the TU references .data in retail order */
    s = *(u8 *)&fzgx_pool_init_fzgx_obj_lbl_4_data_0.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_584.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_59C.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_5A8.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_5C0.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_F4C.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_F64.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_1064.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_107C.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_1154.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_116C.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_11F4.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_120C.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_1210.v;
}
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_4_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_2;
    s = *(u8 *)&fzgx_pool_lbl_4_bss_0_gap_3;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_4;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_8;
    s = *(u8 *)&lbl_4_bss_C;
    s = *(u8 *)&lbl_4_bss_D;
    s = *(u8 *)&fzgx_pool_lbl_4_bss_0_gap_E;
    s = *(u8 *)&fzgx_pool_lbl_4_bss_0_gap_E_fill_F;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_10;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_2;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_4;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_A8;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_AA;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_AC;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_C4;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1CC;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1CD;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1CE;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1D0;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1D1;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1D2;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1D4;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1F4;
    s = *(u8 *)&lbl_4_bss_5618;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_1;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_2;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_3;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_4;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_8;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_9;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_A;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_B;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_C;
}
#pragma section code_type ".text"

#pragma section code_type ".text"

#define RODATA p_lbl_4_rodata_0

void fn_4_9C14(f32 arg0) {
    struct fn_4_9C14_lbl_1_bss_9F8 *p_lbl_1_bss_9F8;
    struct fn_4_9C14_lbl_4_rodata_0 *p_lbl_4_rodata_0;
    u8 v0;
    f32 v2;
    u32 v4;
    struct fn_4_9C14_Request loc_98;
    char loc_78[0x20];
    Sig_fn_1_B7F58_Result loc_70;
    u32 loc_6C, loc_68, loc_64, loc_60;
    u32 loc_5C, loc_58, loc_54, loc_50, loc_4C, loc_48, loc_44, loc_40;
    Sig_fn_800081C8_Color loc_3C, loc_38;
    Sig_fn_800081C8_Color loc_34;
    u32 loc_30, loc_2C, loc_28, loc_24, loc_20, loc_1C, loc_18, loc_14;
    Sig_fn_800081C8_Color loc_10, loc_C;
    Sig_fn_800081C8_Color loc_8;
    p_lbl_4_rodata_0 = (struct fn_4_9C14_lbl_4_rodata_0 *)&lbl_4_rodata_0;

    v0 = lbl_4_bss_5618__fzgx_offset_A;
    lbl_4_bss_5618 = 1;
    if (v0 != 0) {
fn_1_4D0A0();
v4 = (u32)fzgx_pool_init_lbl_4_data_11F4.v[lbl_801A66B4[0]];
fn_1_4AEC0(1);
fn_1_4AEB4(RODATA->unk_39C);
fn_1_49410();
v2 = RODATA->unk_13C;
fn_1_4955C(v2, v2);
fn_1_4954C(RODATA->unk_3A0);
fn_1_495C8(9);
fn_1_496FC(RODATA->unk_50, RODATA->unk_3E0);
fn_1_4966C(RODATA->unk_3A4, RODATA->unk_3A8);
if ((s32)lbl_801A66B4[0] != 5) {
    fn_1_495B0(0x80000000);
    fn_1_49590(RODATA->unk_8);
}
fn_1_4A0D8((const char *)v4);
fn_1_4AEC0(0);
fn_1_4AEB4(RODATA->unk_4C);
        loc_6C = RODATA->unk_400;
        fn_1_4D2AC(&loc_6C, RODATA->unk_3F8, RODATA->unk_3DC);
        lbl_4_bss_5618__fzgx_offset_A--;
        return;
    }
    if (fzgx_obj_lbl_4_bss_10 != 0) {
        if (fn_1_4C10() == 0) {
            fn_1_1280(1);
            lbl_1_bss_96A = fzgx_obj_lbl_4_bss_10;
            fzgx_obj_lbl_4_bss_10 = 0;
        }
        return;
    }
    if (lbl_4_bss_5618__fzgx_offset_3 != 0) {
        if (fn_1_B7F58(&loc_70) != 0) {
            if (lbl_4_bss_5618__fzgx_offset_2 != 0) {
                p_lbl_1_bss_9F8 = &lbl_1_bss_9F8;
if ((p_lbl_1_bss_9F8->unk_10 & 1) || (p_lbl_1_bss_9F8->unk_12 & 1)) {
    lbl_4_bss_C4__fzgx_offset_1CD = 0;
    fn_1_A2D84(0xA9011300);
}
if (((p_lbl_1_bss_9F8->unk_10 >> 1) & 1) || ((lbl_1_bss_9F8.unk_12 >> 1) & 1)) {
    lbl_4_bss_C4__fzgx_offset_1CD = 1;
    fn_1_A2D84(0xA9011300);
}
p_lbl_1_bss_9F8 = &lbl_1_bss_9F8;
if ((p_lbl_1_bss_9F8->unk_8 >> 9) & 1) {
    lbl_4_bss_C4__fzgx_offset_1CD = 1;
    fn_1_A2D84(0xA9011300);
}
                if (((p_lbl_1_bss_9F8->unk_8 >> 8) & 1) || ((p_lbl_1_bss_9F8->unk_8 >> 9) & 1)) {
                    if (lbl_4_bss_C4__fzgx_offset_1CD == 0) {
                        fn_1_A2D84(0xA9011100);
                    } else {
                        lbl_4_bss_5618__fzgx_offset_3 = 0;
                        lbl_4_bss_5618__fzgx_offset_8 = 0;
                        lbl_4_bss_C4__fzgx_offset_1D0 = 0;
                        lbl_4_bss_5618__fzgx_offset_1 = 0;
                    }
                    lbl_4_bss_5618__fzgx_offset_2 = 0;
                }
fn_1_4D0A0();
v4 = (u32)fzgx_pool_init_lbl_4_data_1064.v[lbl_801A66B4[0]];
fn_1_4AEC0(1);
fn_1_4AEB4(RODATA->unk_39C);
fn_1_49410();
v2 = RODATA->unk_13C;
fn_1_4955C(v2, v2);
fn_1_4954C(RODATA->unk_3A0);
fn_1_495C8(9);
fn_1_496FC(RODATA->unk_50, RODATA->unk_3E0);
fn_1_4966C(RODATA->unk_3A4, RODATA->unk_3A8);
if ((s32)lbl_801A66B4[0] != 5) {
    fn_1_495B0(0x80000000);
    fn_1_49590(RODATA->unk_8);
}
fn_1_4A0D8((const char *)v4);
fn_1_4AEC0(0);
fn_1_4AEB4(RODATA->unk_4C);
*(u32 *)&loc_3C = RODATA->unk_3B0;
*(u32 *)&loc_38 = RODATA->unk_3AC;
*(u32 *)&loc_34 = fn_800081C8(&loc_38, &loc_3C, RODATA->unk_CC);
fn_1_49410();
v2 = RODATA->unk_13C;
fn_1_4955C(v2, v2);
fn_1_4954C(RODATA->unk_3A0);
fn_1_495C8(9);
fn_1_496FC(RODATA->unk_3CC, RODATA->unk_50);
fn_1_495C8(10);
if (lbl_4_bss_C4__fzgx_offset_1CD == 0) {
    fn_1_4D494();
    loc_40 = RODATA->unk_3B4;
    fn_1_49514(&loc_40);
    fn_1_4AE0C(fzgx_pool_init_lbl_4_data_1210.v, fzgx_pool_init_lbl_4_data_584.v[lbl_801A66B4[0]]);
    loc_44 = *(u32 *)&loc_34;
    fn_1_4D4C8((Sig_fn_1_4D4C8_Color4_4D4C8 *)&loc_44, RODATA->unk_3A0, RODATA->unk_128);
} else {
    loc_48 = RODATA->unk_3B8;
    fn_1_49514(&loc_48);
    loc_4C = RODATA->unk_3BC;
    fn_1_49528(&loc_4C);
    fn_1_4AE0C(fzgx_pool_init_lbl_4_data_1210.v, fzgx_pool_init_lbl_4_data_584.v[lbl_801A66B4[0]]);
}
fn_1_496FC(RODATA->unk_3D0, RODATA->unk_50);
fn_1_495C8(8);
if (lbl_4_bss_C4__fzgx_offset_1CD == 0) {
    loc_50 = RODATA->unk_3C0;
    fn_1_49514(&loc_50);
    loc_54 = RODATA->unk_3C4;
    fn_1_49528(&loc_54);
    fn_1_4AE0C(fzgx_pool_init_lbl_4_data_1210.v, fzgx_pool_init_lbl_4_data_5A8.v[lbl_801A66B4[0]]);
} else {
    fn_1_4D494();
    loc_58 = RODATA->unk_3C8;
    fn_1_49514(&loc_58);
    fn_1_4AE0C(fzgx_pool_init_lbl_4_data_1210.v, fzgx_pool_init_lbl_4_data_5A8.v[lbl_801A66B4[0]]);
    loc_5C = *(u32 *)&loc_34;
    fn_1_4D4C8((Sig_fn_1_4D4C8_Color4_4D4C8 *)&loc_5C, RODATA->unk_3A0, RODATA->unk_128);
}
                loc_68 = RODATA->unk_404;
                fn_1_4D2AC(&loc_68, RODATA->unk_3F8, RODATA->unk_3DC);
                return;
            }
        } else if (lbl_4_bss_5618__fzgx_offset_4 != 0) {
fn_1_4D0A0();
v4 = (u32)fzgx_pool_init_lbl_4_data_F4C.v[lbl_801A66B4[0]];
fn_1_4AEC0(1);
fn_1_4AEB4(RODATA->unk_39C);
fn_1_49410();
v2 = RODATA->unk_13C;
fn_1_4955C(v2, v2);
fn_1_4954C(RODATA->unk_3A0);
fn_1_495C8(9);
fn_1_496FC(RODATA->unk_50, RODATA->unk_3E0);
fn_1_4966C(RODATA->unk_3A4, RODATA->unk_3A8);
if ((s32)lbl_801A66B4[0] != 5) {
    fn_1_495B0(0x80000000);
    fn_1_49590(RODATA->unk_8);
}
fn_1_4A0D8((const char *)v4);
fn_1_4AEC0(0);
fn_1_4AEB4(RODATA->unk_4C);
            loc_64 = RODATA->unk_408;
            fn_1_4D2AC(&loc_64, RODATA->unk_3F8, RODATA->unk_3DC);
            lbl_4_bss_5618__fzgx_offset_4--;
            return;
        }
    }
    if (lbl_4_bss_5618__fzgx_offset_1 != 0) {
        lbl_4_bss_5618__fzgx_offset_1 = 0;
        fn_4_D1A8(fzgx_obj_lbl_4_bss_4, fzgx_obj_lbl_4_bss_8, lbl_1_bss_8B3A0[0x9E]);
    }
    if (lbl_4_bss_5618__fzgx_offset_3 != 0) {
        if (fn_1_B7E98(0) == 0) {
            fn_4_D760();
            fzgx_pool_lbl_4_bss_0_gap_E = 0;
            fzgx_obj_lbl_4_bss_10 = lbl_4_bss_10__fzgx_offset_A8;
            lbl_4_bss_C4__fzgx_offset_1D0 = 0;
            lbl_4_bss_5618__fzgx_offset_8 = 0;
            fn_1_4A00(0, 15, fzgx_obj_lbl_4_bss_8);
            return;
        }
        if (fn_4_D420() != 0) {
            p_lbl_1_bss_9F8 = &lbl_1_bss_9F8;
if ((p_lbl_1_bss_9F8->unk_10 & 1) || (p_lbl_1_bss_9F8->unk_12 & 1)) {
    lbl_4_bss_C4__fzgx_offset_1CD = 0;
    fn_1_A2D84(0xA9011300);
}
if (((p_lbl_1_bss_9F8->unk_10 >> 1) & 1) || ((lbl_1_bss_9F8.unk_12 >> 1) & 1)) {
    lbl_4_bss_C4__fzgx_offset_1CD = 1;
    fn_1_A2D84(0xA9011300);
}
p_lbl_1_bss_9F8 = &lbl_1_bss_9F8;
if ((p_lbl_1_bss_9F8->unk_8 >> 9) & 1) {
    lbl_4_bss_C4__fzgx_offset_1CD = 1;
    fn_1_A2D84(0xA9011300);
}
            if (((p_lbl_1_bss_9F8->unk_8 >> 8) & 1) || ((p_lbl_1_bss_9F8->unk_8 >> 9) & 1)) {
                if (lbl_4_bss_C4__fzgx_offset_1CD == 0) {
                    fn_1_A2D84(0xA9011100);
                    fn_4_D848((u32)&lbl_4_bss_C4__fzgx_offset_1D0);
                    fn_4_D760();
                    lbl_4_bss_5618__fzgx_offset_3 = 0;
                } else {
                    fn_4_D878();
                }
            }
            fn_1_4FD64();
fn_1_4D0A0();
v4 = (u32)fzgx_pool_init_lbl_4_data_1154.v[lbl_801A66B4[0]];
fn_1_4AEC0(1);
fn_1_4AEB4(RODATA->unk_39C);
fn_1_49410();
v2 = RODATA->unk_13C;
fn_1_4955C(v2, v2);
fn_1_4954C(RODATA->unk_3A0);
fn_1_495C8(9);
fn_1_496FC(RODATA->unk_50, RODATA->unk_3E0);
fn_1_4966C(RODATA->unk_3A4, RODATA->unk_3A8);
if ((s32)lbl_801A66B4[0] != 5) {
    fn_1_495B0(0x80000000);
    fn_1_49590(RODATA->unk_8);
}
fn_1_4A0D8((const char *)v4);
fn_1_4AEC0(0);
fn_1_4AEB4(RODATA->unk_4C);
*(u32 *)&loc_10 = RODATA->unk_3B0;
*(u32 *)&loc_C = RODATA->unk_3AC;
*(u32 *)&loc_8 = fn_800081C8(&loc_C, &loc_10, RODATA->unk_CC);
fn_1_49410();
v2 = RODATA->unk_13C;
fn_1_4955C(v2, v2);
fn_1_4954C(RODATA->unk_3A0);
fn_1_495C8(9);
fn_1_496FC(RODATA->unk_3CC, RODATA->unk_50);
fn_1_495C8(10);
if (lbl_4_bss_C4__fzgx_offset_1CD == 0) {
    fn_1_4D494();
    loc_14 = RODATA->unk_3B4;
    fn_1_49514(&loc_14);
    fn_1_4AE0C(fzgx_pool_init_lbl_4_data_1210.v, fzgx_pool_init_lbl_4_data_584.v[lbl_801A66B4[0]]);
    loc_18 = *(u32 *)&loc_8;
    fn_1_4D4C8((Sig_fn_1_4D4C8_Color4_4D4C8 *)&loc_18, RODATA->unk_3A0, RODATA->unk_128);
} else {
    loc_1C = RODATA->unk_3B8;
    fn_1_49514(&loc_1C);
    loc_20 = RODATA->unk_3BC;
    fn_1_49528(&loc_20);
    fn_1_4AE0C(fzgx_pool_init_lbl_4_data_1210.v, fzgx_pool_init_lbl_4_data_584.v[lbl_801A66B4[0]]);
}
fn_1_496FC(RODATA->unk_3D0, RODATA->unk_50);
fn_1_495C8(8);
if (lbl_4_bss_C4__fzgx_offset_1CD == 0) {
    loc_24 = RODATA->unk_3C0;
    fn_1_49514(&loc_24);
    loc_28 = RODATA->unk_3C4;
    fn_1_49528(&loc_28);
    fn_1_4AE0C(fzgx_pool_init_lbl_4_data_1210.v, fzgx_pool_init_lbl_4_data_5A8.v[lbl_801A66B4[0]]);
} else {
    fn_1_4D494();
    loc_2C = RODATA->unk_3C8;
    fn_1_49514(&loc_2C);
    fn_1_4AE0C(fzgx_pool_init_lbl_4_data_1210.v, fzgx_pool_init_lbl_4_data_5A8.v[lbl_801A66B4[0]]);
    loc_30 = *(u32 *)&loc_8;
    fn_1_4D4C8((Sig_fn_1_4D4C8_Color4_4D4C8 *)&loc_30, RODATA->unk_3A0, RODATA->unk_128);
}
            loc_60 = RODATA->unk_40C;
            fn_1_4D2AC(&loc_60, RODATA->unk_3F8, RODATA->unk_3DC);
        }
        lbl_4_bss_5618 = 0;
        return;
    }
    if (lbl_4_bss_5618__fzgx_offset_8 != 0) {
        *(struct fn_4_9C14_Save *)lbl_4_bss_C4__fzgx_offset_1F4 = *(struct fn_4_9C14_Save *)lbl_1_bss_7F0C0;
        fn_1_F7954();
        fn_80008BEC(&loc_98, 0, 0x24);
        fn_80008BEC(loc_78, 0, 0x20);
        loc_98.unk_0 = 1;
        loc_98.unk_8 = loc_78;
        loc_98.unk_C = lbl_1_bss_718E0;
        if (lbl_4_bss_C4__fzgx_offset_1D0 != 0) {
            if (fn_1_B7F58(&loc_70) != 0) {
                fn_1_F7A20();
                fn_1_F7954();
            }
            fn_4_A78C((u32)&lbl_4_bss_C4__fzgx_offset_1D0);
            fn_1_B7CE4(1, loc_78);
            loc_78[8] = 0x20;
            loc_78[9] = 0;
            strcat(loc_78, (char *)&lbl_4_bss_C4__fzgx_offset_1D0);
            fn_80083DB0((char *)lbl_1_bss_718E0 + 0x5522, (char *)&lbl_4_bss_C4__fzgx_offset_1D0);
            fn_1_B7E14(loc_78);
            *lbl_1_bss_718C0 = fn_1_C3688();
            loc_98.unk_4 = 0x10000;
        } else {
            fn_1_B7CE4(1, loc_78);
            loc_98.unk_4 = 4;
        }
        fn_1_AA6D8(0, 0, &loc_98);
        lbl_4_bss_5618__fzgx_offset_8 = 0;
        fzgx_obj_lbl_4_bss_10 = 0;
        return;
    }
    if (fn_1_B7C00() == 0) {
        if (lbl_4_bss_5618__fzgx_offset_9 != 0 && fn_1_B7CD4() == 0) {
            *(struct fn_4_9C14_Save *)lbl_1_bss_7F0C0 = *(struct fn_4_9C14_Save *)lbl_4_bss_C4__fzgx_offset_1F4;
        }
        fzgx_pool_lbl_4_bss_0_gap_E = 0;
        fzgx_obj_lbl_4_bss_10 = lbl_4_bss_10__fzgx_offset_A8;
        fn_1_4A00(0, 15, fzgx_obj_lbl_4_bss_8);
    }
}
/* fzgx:end fn_4_9C14 */

/* fzgx:begin fn_4_A734 */
// Finalizes the pending option callback and clears its handle.
void fn_4_A734(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_A734 */

/* fzgx:begin fn_4_A78C */
void fn_4_A78C(u32 arg0) {
    u8 loc_8[32];
    u8 *p;
    u8 *out;

    if (lbl_801A66B4 != 5) {
        fn_80083DB0(loc_8, arg0);
        p = loc_8;
        out = (u8 *)arg0;
        while (*p != 0) {
            if (*p < 0x80) {
                *out = *p;
                p++;
                out++;
            } else {
                u8 *q = fn_4_A82C(p);
                if (q != 0) {
                    *out = *q;
                    out++;
                }
                p += 2;
            }
        }
        *out = 0;
    }
}
/* fzgx:end fn_4_A78C */

/* fzgx:begin fn_4_A82C */
extern struct fn_4_347C_lbl_1_bss_9C8 lbl_1_bss_9C8;
extern u32 lbl_1_data_2AC0;
extern u32 lbl_1_data_2B40;
extern u32 lbl_1_data_2B50;
extern u32 lbl_1_data_2B58;
extern u32 lbl_4_data_14D0;
extern void fn_4_3128(void);
extern u32 fn_80008BA8(u32, u32, u32);
extern u32 fn_1_F7308(void);
extern u32 lbl_1_bss_AA0;
extern u32 lbl_1_data_2B60;
extern u32 lbl_4_data_2AE8;
extern u32 memcpy(u32, u32, u32);
extern void fn_4_63D4(void);
extern int fn_1_4C10(void);
extern u16 lbl_1_bss_96A;
extern u32 fn_4_0(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_9F8;
extern u8 lbl_4_data_2C58[84];
extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_4_ABB0(void);
extern u32 fn_1_1380F0(u32);
extern u32 fn_1_13ABA8(u32);
extern u32 lbl_4_data_1A4;
extern s32 lbl_801A66B4;
extern u8 lbl_4_bss_5618;
extern u32 fn_1_B7E98(u32);
extern u32 fn_1_B800C(u32);
extern u32 fn_1_B80F0(u32);
extern u32 fn_1_B8170(u32);
extern u32 lbl_4_data_2DB4;
extern void fn_4_9AD0(void);
extern u8 *fn_4_A82C(u8 *);
extern void fn_80083DB0(u8 *, u32);
extern u32 fn_1_B9C0C(void);
extern s8 fn_1_BA144(u32 *);
extern u32 lbl_4_bss_5678;
extern u32 fn_1_B7C00(void);
extern u32 fn_1_BC310(void *);
extern u32 fn_1_C0510(u32);
extern u32 fn_1_C1394(void *);
extern s16 lbl_1_bss_962;
extern struct fn_4_9B0_lbl_4_data_1260 lbl_4_data_1260;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_426C(u32);
extern void fn_4_AB90(void);
extern struct _prolog_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern struct fn_4_869C_lbl_1_bss_718E0 lbl_1_bss_718E0;
extern s32 lbl_1_bss_970;
extern u8 lbl_4_bss_2;
extern u16 lbl_1_bss_968;

extern struct fn_4_347C_lbl_1_bss_9C8 lbl_1_bss_9C8;
extern u32 lbl_1_data_2AC0;
extern u32 lbl_1_data_2B40;
extern u32 lbl_1_data_2B50;
extern u32 lbl_1_data_2B58;
extern u32 lbl_4_data_14D0;
extern void fn_4_3128(void);
extern u32 fn_80008BA8(u32, u32, u32);
extern u32 fn_1_F7308(void);
extern u32 lbl_1_bss_AA0;
extern u32 lbl_1_data_2B60;
extern u32 lbl_4_data_2AE8;
extern u32 memcpy(u32, u32, u32);
extern void fn_4_63D4(void);
extern int fn_1_4C10(void);
extern u16 lbl_1_bss_96A;
extern u32 fn_4_0(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_9F8;
extern u8 lbl_4_data_2C58[84];
extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_4_ABB0(void);
extern u32 fn_1_1380F0(u32);
extern u32 fn_1_13ABA8(u32);
extern u32 lbl_4_data_1A4;
extern s32 lbl_801A66B4;
extern u8 lbl_4_bss_5618;
extern u32 fn_1_B7E98(u32);
extern u32 fn_1_B800C(u32);
extern u32 fn_1_B80F0(u32);
extern u32 fn_1_B8170(u32);
extern u32 lbl_4_data_2DB4;
extern void fn_4_9AD0(void);
extern u8 *fn_4_A82C(u8 *);
extern void fn_80083DB0(u8 *, u32);
extern u32 fn_1_B9C0C(void);
extern s8 fn_1_BA144(u32 *);
extern u32 lbl_4_bss_5678;
extern u32 fn_1_B7C00(void);
extern u32 fn_1_BC310(void *);
extern u32 fn_1_C0510(u32);
extern u32 fn_1_C1394(void *);
extern s16 lbl_1_bss_962;
extern struct fn_4_9B0_lbl_4_data_1260 lbl_4_data_1260;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_426C(u32);
extern void fn_4_AB90(void);
extern struct _prolog_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern struct fn_4_869C_lbl_1_bss_718E0 lbl_1_bss_718E0;
extern s32 lbl_1_bss_970;
extern u8 lbl_4_bss_2;
extern u16 lbl_1_bss_968;

/* Stand-in for the TU's data that precedes the kana tables (retail begins
 * with the string "Cont..."), so the tables land at their retail offsets. */
static u8 fzgx_obj_lbl_4_data_0[0xC] = { 'C', 'o', 'n', 't' };
static u8 fzgx_pool_fzgx_pad[0x2dcc - 0xC] = { 1 };
static u8 fzgx_pool_wideA[56] = { 1 };
static u8 fzgx_pool_wideB[56] = { 1 };
static u8 fzgx_pool_wideC[64] = { 1 };
static u8 fzgx_pool_wideD[24] = { 1 };
static u8 fzgx_pool_narrowA[28] = { 1 };
static u8 fzgx_pool_narrowB[28] = { 1 };
static u8 fzgx_pool_narrowC[36] = { 1 };
static u8 fzgx_pool_narrowD[12] = { 1 };

/* Maps a two-byte (SJIS) character to its one-byte equivalent. */
u8 *fn_4_A82C(u8 *s) {
    s32 i;

    for (i = 0; i < 54; i += 2) {
        if (s[0] == fzgx_pool_wideA[i] && s[1] == fzgx_pool_wideA[i + 1]) {
            return &fzgx_pool_narrowA[i / 2];
        }
    }
    for (i = 0; i < 54; i += 2) {
        if (s[0] == fzgx_pool_wideB[i] && s[1] == fzgx_pool_wideB[i + 1]) {
            return &fzgx_pool_narrowB[i / 2];
        }
    }
    for (i = 0; i < 64; i += 2) {
        if (s[0] == fzgx_pool_wideC[i] && s[1] == fzgx_pool_wideC[i + 1]) {
            return &fzgx_pool_narrowC[i / 2];
        }
    }
    for (i = 0; i < 22; i += 2) {
        if (s[0] == fzgx_pool_wideD[i] && s[1] == fzgx_pool_wideD[i + 1]) {
            return &fzgx_pool_narrowD[i / 2];
        }
    }
    return 0;
}

#pragma section ".fzgxpool"
__declspec(section ".fzgxpool") u8 *fzgx_primer(void) { return fzgx_pool_fzgx_pad; }
/* fzgx:end fn_4_A82C */

/* fzgx:begin fn_4_AB30 */
// Initialize the option state and reset its associated data value.
void fn_4_AB30(void) {
    fn_1_B9BE0();
    fn_1_B9DE8((u32)&lbl_4_bss_5630);
    lbl_4_bss_5630.unk_0 = 4;
    lbl_4_bss_5630.unk_0 |= 0x10;
    lbl_4_bss_5630.unk_0 |= 0x20;
    lbl_4_bss_5630.unk_4 = 0xc;
    lbl_4_data_2F1C = 0;
}
/* fzgx:end fn_4_AB30 */

/* fzgx:begin fn_4_AB90 */
void fn_4_AB90(void) {
    fn_1_B9C0C();
}
/* fzgx:end fn_4_AB90 */

/* fzgx:begin fn_4_ABB0 noprologue */
#include "types.h"

typedef void (*OptionHandler)(void);

/* retail addresses the whole bss cluster 0x5628..0x5678 off one base */
typedef struct {
    u32 count;      /* 0x00 */
    u32 pending;    /* 0x04 */
    u8 pad_8[0x48];
    u32 result;     /* 0x50 */
} OptionState;

/* retail addresses the handler table, current and next slots off one base */
typedef struct {
    OptionHandler handlers[6];  /* 0x00 */
    s32 current;                /* 0x18 */
    s32 next;                   /* 0x1C */
} OptionTable;

extern OptionTable lbl_4_data_2F00;
extern OptionState lbl_4_bss_5628;

extern u8 fn_4_ACF0__fzgx_offset_0[];
extern u8 fn_4_AD44__fzgx_offset_0[];
extern u8 fn_4_AD78__fzgx_offset_0[];
extern u8 fn_4_ADAC__fzgx_offset_0[];
extern u8 fn_4_ADB0__fzgx_offset_0[];
extern u8 fn_4_ADF0__fzgx_offset_0[];
static OptionHandler fzgx_pool_native_lbl_4_data_2F00_handlers[6] = {(OptionHandler)(u32)fn_4_ACF0__fzgx_offset_0, (OptionHandler)(u32)fn_4_AD78__fzgx_offset_0, (OptionHandler)(u32)fn_4_ADB0__fzgx_offset_0, (OptionHandler)(u32)fn_4_AD44__fzgx_offset_0, (OptionHandler)(u32)fn_4_ADAC__fzgx_offset_0, (OptionHandler)(u32)fn_4_ADF0__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static s32 fzgx_pool_native_lbl_4_data_2F00_current = 0xFFFFFFFF; /* fzgx-allow: A1 measured pool bytes and bindings */
static s32 fzgx_pool_native_lbl_4_data_2F00_next = 0xFFFFFFFF; /* fzgx-allow: A1 measured pool bytes and bindings */

u32 fn_4_ABB0(void) {
    
    OptionState *st = &lbl_4_bss_5628;

    st->result = 0;
    if (fzgx_pool_native_lbl_4_data_2F00_next >= 0 && st->count == 0) {
        fzgx_pool_native_lbl_4_data_2F00_current = fzgx_pool_native_lbl_4_data_2F00_next;
        fzgx_pool_native_lbl_4_data_2F00_next = -1;
        st->count = st->pending;
        st->pending = 0;
    }
    if (fzgx_pool_native_lbl_4_data_2F00_current >= 0) {
        if (st->count != 0) {
            st->count--;
        }
        fzgx_pool_native_lbl_4_data_2F00_handlers[fzgx_pool_native_lbl_4_data_2F00_current]();
    }
    return st->result;
}
/* fzgx:end fn_4_ABB0 */

/* fzgx:begin fn_4_AC58 */
extern struct fn_4_347C_lbl_1_bss_9C8 lbl_1_bss_9C8;
extern u32 lbl_1_data_2AC0;
extern u32 lbl_1_data_2B40;
extern u32 lbl_1_data_2B50;
extern u32 lbl_1_data_2B58;
extern u32 lbl_4_data_14D0;
extern void fn_4_3128(void);
extern u32 fn_80008BA8(u32, u32, u32);
extern u32 fn_1_F7308(void);
extern u32 lbl_1_bss_AA0;
extern u32 lbl_1_data_2B60;
extern u32 lbl_4_data_2AE8;
extern u32 memcpy(u32, u32, u32);
extern void fn_4_63D4(void);
extern int fn_1_4C10(void);
extern u16 lbl_1_bss_96A;
extern u32 fn_4_0(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_9F8;
extern u8 lbl_4_data_2C58[84];
extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_4_ABB0(void);
extern u32 fn_1_1380F0(u32);
extern u32 fn_1_13ABA8(u32);
extern u32 lbl_4_data_1A4;
extern s32 lbl_801A66B4;
extern u8 lbl_4_bss_5618;
extern u32 fn_1_B7E98(u32);
extern u32 fn_1_B800C(u32);
extern u32 fn_1_B80F0(u32);
extern u32 fn_1_B8170(u32);
extern u32 lbl_4_data_2DB4;
extern void fn_4_9AD0(void);
extern u8 *fn_4_A82C(u8 *);
extern void fn_80083DB0(u8 *, u32);
extern u32 fn_1_B9C0C(void);
extern s8 fn_1_BA144(u32 *);
extern u32 lbl_4_bss_5678;
extern u32 fn_1_B7C00(void);
extern u32 fn_1_BC310(void *);
extern u32 fn_1_C0510(u32);
extern u32 fn_1_C1394(void *);
extern s16 lbl_1_bss_962;
extern struct fn_4_9B0_lbl_4_data_1260 lbl_4_data_1260;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_426C(u32);
extern void fn_4_AB90(void);
extern struct _prolog_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern struct fn_4_869C_lbl_1_bss_718E0 lbl_1_bss_718E0;
extern s32 lbl_1_bss_970;
extern u8 lbl_4_bss_2;
extern u16 lbl_1_bss_968;

extern s32 lbl_801A66B4;
extern u32 fn_1_1380F0(u32);
extern u32 fn_1_B7C00(void);
extern u32 fn_1_13ABA8(u32);

#pragma opt_propagation off
void fn_4_AC58(void) {
    Obj_4_data_2F00 *p = &lbl_4_data_2F00;
    u32 *table = (u32 *)&p->pad_0[0x60];
    fn_1_1380F0(table[lbl_801A66B4]);
    if ((u8)fn_1_B7C00() || (s32)lbl_4_bss_5630.unk_22 == 2) {
        fn_1_13ABA8(0);
    } else {
        fn_1_13ABA8(0x28000000);
    }
    if ((s32)p->unk_18 >= 0) {
        u32 offset = p->unk_18 * 4;
        void (**callbacks)(void) = (void (**)(void))&p->pad_0[0xC];
        (*(void (**)(void))((u8 *)callbacks + offset))();
    }
}
/* fzgx:end fn_4_AC58 */

/* fzgx:begin fn_4_ACF0 */
void fn_4_ACF0(void) {
    u32 v0;
    u32 t0;
    t0 = fn_1_BA144((u32 *)(u32)&lbl_4_bss_5630);
    v0 = t0;
    if ((s8)t0 == 0) {
    lbl_4_data_2F1C = 1;
    } else {
    if ((s8)t0 == 1) {
    lbl_4_bss_5678 = 78;
    }
    }
}
/* fzgx:end fn_4_ACF0 */

/* fzgx:begin fn_4_AD44 */
void fn_4_AD44(void) {
    u32 t0;
    t0 = fn_1_B7C00();
    if ((t0 & 0xFF) == 0) {
    fn_1_BC310(&lbl_4_bss_5630);
    }
}
/* fzgx:end fn_4_AD44 */

/* fzgx:begin fn_4_AD78 */
void fn_4_AD78(void) {
    fn_1_C0510((u32)&lbl_4_bss_5630);
    lbl_4_data_2F1C = 2;
}
/* fzgx:end fn_4_AD78 */

/* fzgx:begin fn_4_ADAC */
// fn_4_ADAC: empty in retail (single blr).
void fn_4_ADAC(void) {
}
/* fzgx:end fn_4_ADAC */

/* fzgx:begin fn_4_ADB0 */
void fn_4_ADB0(void) {
    u32 t0;
    t0 = fn_1_B7C00();
    if ((t0 & 0xFF) == 0) {
    lbl_4_data_2F1C = 0;
    fn_1_C1394(&lbl_4_bss_5630);
    }
}
/* fzgx:end fn_4_ADB0 */

/* fzgx:begin fn_4_ADF0 */
// fn_4_ADF0: empty in retail (single blr).
void fn_4_ADF0(void) {
}
/* fzgx:end fn_4_ADF0 */

/* fzgx:begin fn_4_ADF4 */
#include "font.h"

extern struct fn_4_347C_lbl_1_bss_9C8 lbl_1_bss_9C8;
extern u32 lbl_1_data_2AC0;
extern u32 lbl_1_data_2B40;
extern u32 lbl_1_data_2B50;
extern u32 lbl_1_data_2B58;
extern u32 lbl_4_data_14D0;
extern void fn_4_3128(void);
extern u32 fn_80008BA8(u32, u32, u32);
extern u32 fn_1_F7308(void);
extern u32 lbl_1_bss_AA0;
extern u32 lbl_1_data_2B60;
extern u32 lbl_4_data_2AE8;
extern u32 memcpy(u32, u32, u32);
extern void fn_4_63D4(void);
extern int fn_1_4C10(void);
extern u16 lbl_1_bss_96A;
extern u32 fn_4_0(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_9F8;
extern u8 lbl_4_data_2C58[84];
extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_4_ABB0(void);
extern u32 fn_1_1380F0(u32);
extern u32 fn_1_13ABA8(u32);
extern u32 lbl_4_data_1A4;
extern s32 lbl_801A66B4;
extern u8 lbl_4_bss_5618;
extern u32 fn_1_B7E98(u32);
extern u32 fn_1_B800C(u32);
extern u32 fn_1_B80F0(u32);
extern u32 fn_1_B8170(u32);
extern u32 lbl_4_data_2DB4;
extern void fn_4_9AD0(void);
extern u8 *fn_4_A82C(u8 *);
extern void fn_80083DB0(u8 *, u32);
extern u32 fn_1_B9C0C(void);
extern s8 fn_1_BA144(u32 *);
extern u32 lbl_4_bss_5678;
extern u32 fn_1_B7C00(void);
extern u32 fn_1_BC310(void *);
extern u32 fn_1_C0510(u32);
extern u32 fn_1_C1394(void *);
extern s16 lbl_1_bss_962;
extern struct fn_4_9B0_lbl_4_data_1260 lbl_4_data_1260;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_426C(u32);
extern void fn_4_AB90(void);
extern struct _prolog_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern struct fn_4_869C_lbl_1_bss_718E0 lbl_1_bss_718E0;
extern s32 lbl_1_bss_970;
extern u8 lbl_4_bss_2;
extern u16 lbl_1_bss_968;


#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[360] = {0x89709094, 0x00000000, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x00000000, 0x8B4C8D86, 0x00000000, 0x81418142, 0x814C814D, 0x81458143, 0x81448146, 0x81478148, 0x8149817B, 0x817C815E, 0x81818183, 0x8184814F, 0x81518160, 0x81628175, 0x81768169, 0x816A816F, 0x8170816D, 0x816E818F, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x82D082E7, 0x82AA82C8, 0x00000000, 0x82A082A2, 0x82A482A6, 0x82A882A9, 0x82AB82AD, 0x82AF82B1, 0x82B382B5, 0x82B782B9, 0x82BB82BD, 0x82BF82C2, 0x82C482C6, 0x82C882C9, 0x82CA82CB, 0x82CC82CD, 0x82D082D3, 0x82D682D9, 0x82DC82DD, 0x82DE82DF, 0x82E082E2, 0x82E482E6, 0x82E782E8, 0x82E982EA, 0x82EB82ED, 0x82EE82EF, 0x82F082F1, 0x82AA82AC, 0x82AE82B0, 0x82B282B4, 0x82B682B8, 0x82BA82BC, 0x82BE82C0, 0x82C382C5, 0x82C782CE, 0x82D182D4, 0x82D782DA, 0x82CF82D2, 0x82D582D8, 0x82DB829F, 0x82A182A3, 0x82A582A7, 0x82C182E1, 0x82E382E5, 0x82EC81E7, 0x81E80000, 0x829F82A1, 0x82A382A5, 0x82A782AA, 0x82AC82AE, 0x82B082B2, 0x82B482B6, 0x82B882BA, 0x82BC82BE, 0x82C082C1, 0x82C582C7, 0x81408140, 0x81408140, 0x814082CE, 0x82D182D4, 0x82D782DA, 0x81408140, 0x81408140, 0x814082E1, 0x82E382E5, 0x81408140, 0x81408140, 0x814082EC, 0x81408140, 0x81408140, 0x82A982AB, 0x82AD82AF, 0x82B182B3, 0x82B582B7, 0x82B982BB, 0x82BD82BF, 0x82C282C4, 0x82C682CF, 0x82D282D5, 0x82D882DB, 0x82CD82D0, 0x82D382D6, 0x82D982A0, 0x82A282A4, 0x82A682A8, 0x82C282E2, 0x82E482E6, 0x82ED8140, 0x81400000, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x814082C3, 0x81408140, 0x81408140, 0x81408140, 0x814082CF, 0x82D282D5, 0x82D882DB, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x82C18140, 0x814082CD, 0x82D082D3, 0x82D682D9, 0x82CE82D1, 0x82D482D7, 0x82DA8140, 0x81408140, 0x81408140, 0x82C38140, 0x81408140, 0x81408140, 0x81400000, 0x834A835E, 0x834A8369, 0x00000000, 0x83418343, 0x83458347, 0x8349834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x8369836A, 0x836B836C, 0x836D836E, 0x83718374, 0x82D6837A, 0x837D837E, 0x83808381, 0x83828384, 0x83868388, 0x8389838A, 0x838B838C, 0x838D838F, 0x83908391, 0x83928393, 0x8394834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618364, 0x83668368, 0x836F8372, 0x837582D7, 0x837B8370, 0x83738376, 0x82D8837C, 0x83408342, 0x83448346, 0x83488395, 0x83968362, 0x83838385, 0x8387838E, 0x81E781E8, 0x00000000, 0x83408342, 0x83448346, 0x8348834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618362, 0x83668368, 0x81408140, 0x81408140, 0x8140836F, 0x83728375, 0x82D7837B, 0x81408140, 0x81408140, 0x81408383, 0x83858387, 0x81408140, 0x81408140, 0x8140838E, 0x81408140, 0x81408140, 0x8345834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x83708373, 0x837682D8, 0x837C836E, 0x83718374, 0x82D6837A, 0x83418343, 0x83458347, 0x8349834A, 0x83508363, 0x83848386, 0x8388838F, 0x81408140, 0x00000000, 0x81408140, 0x83948140, 0x81408395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408364, 0x81408140, 0x81408140, 0x81408140, 0x81408370, 0x83738376, 0x82D8837C, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x83448395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408362, 0x81408140, 0x836E8371, 0x837482D6, 0x837A836F, 0x83728375, 0x82D7837B, 0x81408140, 0x83948140, 0x8140834B, 0x83518364, 0x81408140, 0x81408140, 0x81408140, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 225.43910217285156f;
}
static const u32 fzgx_pool_table3[65] = {0x74616C20, 0x4C657474, 0x65727300, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81E781E8, 0x00000000, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x81E781E8, 0x00000000, 0x5369676E, 0x73000000, 0x81438144, 0x81488149, 0x817B817C, 0x815E815F, 0x81818183, 0x81848146, 0x8147814C, 0x814D814F, 0x81518162, 0x8169816A, 0x816D816E, 0x816F8170, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x4E756D62, 0x65727300, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.21;
    d = 1.6666666666666667;
    d = 0.5;
    s = 48.0f;
    s = 0.25f;
    d = 1.0;
    s = 0.12999999523162842f;
    s = 0.0f;
    d = 1.5;
    d = 2.0;
    s = 1.6666666269302368f;
    s = 0.0625f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"
struct fn_8_D630_rodata {
u8 pad_0[0x6A8];
f64 unk_6A8;
f64 unk_6B0;
f64 unk_6B8;
f32 unk_6C0;
f32 unk_6C4;
f64 unk_6C8;
f32 unk_6D0;
u8 pad_6D4[0x4];
f64 unk_6D8;
f64 unk_6E0;
f32 unk_6E8;
f32 unk_6EC;
f64 unk_6F0;
f64 unk_6F8;
};
struct fn_8_D630_550 {
u32 unk_0;
};
#pragma pack(1)
struct fn_8_D630_obj {
u8 unk_0;
u8 unk_1;
u8 unk_2;
u8 unk_3;
u16 unk_4;
u16 unk_6;
u16 unk_8;
u16 unk_A;
u8 unk_C;
u32 unk_D;
};
#pragma pack()

extern struct fn_8_D630_rodata lbl_4_rodata_410;
extern u8 lbl_4_data_2F78[];
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A6410;
extern u8 lbl_4_bss_5684;
extern void fn_1_46B4(u32, u32, const char *, int);
extern u32 fn_1_4060(void);
extern s32 strncmp(const char *, const char *, size_t);
extern char * strncpy(char *, const char *, size_t);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_49514(u32 *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_A2D84(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_4A0D8(const char *);
#pragma pool_data on
#pragma fp_contract off
#pragma opt_common_subs off
static inline f64 fn_10_2325C_read_pointer(struct fn_8_D630_rodata * owner) { return owner->unk_6B0; }
static inline s32 fn_4_ADF4_sign(s32 x) { return x < 0 ? -1 : x > 0; }
static inline u8 fn_4_ADF4_blend(u8 c, f32 f) {
    f32 delta = (f32)(255 - c) * f;
    return (s32)((f32)c + delta);
}
void fn_4_ADF4(struct fn_8_D630_obj *arg0)
{
struct fn_8_D630_obj *p;
struct fn_8_D630_rodata *r;
u8 *d;
u8 name[4];
u8 ph[4];
u32 col1;
u32 col2;
u32 col3;
u32 col4;
FontDrawPacket loc_20;
f32 f;
f32 scale;
u32 t;
u32 n2;
s32 e;
p = arg0;
r = &lbl_4_rodata_410;
d = lbl_4_data_2F78;
if (lbl_4_bss_5684 != 0) {
fn_1_46B4(lbl_801A6410, (u32)p, (const char *)(d + 0xA0), 0xFB);
fn_1_4060();
return;
}
n2 = (p->unk_C + 1) & 0x1F;
t = lbl_4_bss_5680->unk_20;
if (__rlwnm(t, n2, 31, 31) != 0) {
if (p->unk_0 != 1 || p->unk_1 != 0x18) {
p->unk_0 = 4;
p->unk_1 = 0x10;
lbl_4_bss_5680->unk_20 &= ~(0x80000000U >> p->unk_C);
if (strncmp((const char *)p + 2, (const char *)(d + 0xB0), 2) == 0) {
strncpy((char *)p + 2, (const char *)(d + 0xB4), 2);
name[0] = p->unk_2;
name[1] = p->unk_3;
}
}
}
name[0] = p->unk_2;
name[1] = p->unk_3;
name[2] = 0;
fn_1_49410();
fn_1_494DC(0x2A);
fn_1_495C8(9);
switch (p->unk_0) {
case 1:
{
u16 c4 = p->unk_4;
s32 t4 = (s32)p->unk_8 - (s32)c4;
f64 dd = 0.21 * (f64)t4;
if ((s32)dd != 0) {
p->unk_4 = (u16)(s32)((f64)(u32)c4 + dd);
} else {
e = fn_4_ADF4_sign(t4);
/* Retail rereads the position after selecting the one-step adjustment. */
p->unk_4 = *(volatile u16 *)&p->unk_4 + e;
}
{
u16 c6 = p->unk_6;
s32 t6 = (s32)p->unk_A - (s32)c6;
dd = 0.21 * (f64)t6;
if ((s32)dd != 0) {
p->unk_6 = (u16)(s32)((f64)(u32)c6 + dd);
} else {
e = fn_4_ADF4_sign(t6);
/* Retail rereads the position after selecting the one-step adjustment. */
p->unk_6 = *(volatile u16 *)&p->unk_6 + e;
}
}
}
col1 = p->unk_D;
fn_1_49514(&col1);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
{
f64 scale_d = 1.6666666666666667 * (0.5 + (f32)(0x18 - p->unk_1) / 48.0f);
fn_1_4955C(scale_d, scale_d);
}
if (p->unk_1 == 1) {
p->unk_0 = 2;
p->unk_4 = p->unk_8;
p->unk_6 = p->unk_A;
}
break;
case 2:
if (p->unk_1 == 0) {
p->unk_1 = 4;
fn_1_A2D84(0xA9010100);
}
*(u32 *)ph = p->unk_D;
{
f32 quarter = 0.25f;
f = (f32)p->unk_1 * quarter;
{
ph[0] += (255 - ph[0]) * f;
ph[1] += (255 - ph[1]) * f;
ph[2] += (255 - ph[2]) * f;
}
}
col2 = *(u32 *)ph;
fn_1_49514(&col2);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
{
f64 scale_d = 1.6666666666666667 * (1.0 + 0.5 * (f64)f);
fn_1_4955C(scale_d, scale_d);
}
loc_20 = *(FontDrawPacket *)(&lbl_1_rodata_26F8);
loc_20.image = 0x8F09;
loc_20.x = (f32)p->unk_4;
loc_20.y = (f32)p->unk_6;
loc_20.z = 0.13f;
loc_20.scale_x = loc_20.scale_y = (1.5 + 2.0 * (f64)f);
loc_20.flags = 0xA;
fn_1_4F734((FontDrawPacket *)&loc_20);
if (p->unk_1 == 1) {
p->unk_0 = 3;
if (strncmp((const char *)p + 2, (const char *)(d + 0xB4), 2) == 0) {
strncpy((char *)p + 2, (const char *)(d + 0xB0), 2);
name[0] = p->unk_2;
name[1] = p->unk_3;
}
}
break;
case 3:
col3 = p->unk_D;
fn_1_49514(&col3);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
fn_1_4955C(1.6666666f, 1.6666666f);
break;
case 4:
if (p->unk_1 == 0) {
fn_1_46B4(lbl_801A6410, (u32)p, (const char *)(d + 0xA0), 0x169);
fn_1_4060();
return;
}
col4 = p->unk_D;
fn_1_49514(&col4);
fn_1_496FC((f32)p->unk_4, (f32)p->unk_6);
{
f64 scale_d = 1.6666666666666667 * (1.0 + 0.5 * (f32)(0x10 - p->unk_1));
fn_1_4955C(scale_d, scale_d);
}
{
f32 alpha = (f32)p->unk_1;
alpha *= 0.0625f;
fn_1_495A0(alpha);
}
break;
}
fn_1_4A0D8((const char *)name);
p->unk_1--;
}
#pragma opt_common_subs reset
/* fzgx:end fn_4_ADF4 */

/* fzgx:begin fn_4_B528 noprologue */
#include "types.h"
#include "font.h"
#include "rel/option/globals.h"

void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);
struct fn_8_DD64_lbl_801A63D0 {
u32 unk_0;
};
struct fn_8_DD64_lbl_8_rodata_408 {
u8 pad_0[0x6F0];
f64 unk_6F0;
f64 unk_6F8;
f32 unk_700;
f32 unk_704;
f32 unk_708;
u32 unk_70C;
u32 unk_710;
u32 unk_714;
u32 unk_718;
u32 unk_71C;
u32 unk_720;
f32 unk_724;
f32 unk_728;
u8 pad_72C[0x4];
f64 unk_730;
f64 unk_738;
f32 unk_740;
u8 pad_744[0x4];
f64 unk_748;
f32 unk_750;
f32 unk_754;
};
extern char * fn_80083CF4(char *, const char *, size_t);
extern char * strcat(char *, const char *);
extern char * strncpy(char *, const char *, size_t);
extern int fn_1_4F734(FontDrawPacket *);
extern int sprintf(char *, const char *, ...);
extern size_t strlen(const char *);
extern struct fn_8_DD64_lbl_801A63D0 lbl_801A63D0;
extern struct fn_8_DD64_lbl_8_rodata_408 lbl_4_rodata_410;
extern u32 fn_1_4060(void);
extern u32 fn_1_49410(void);
typedef struct Sig_fn_800081C8_Color Sig_fn_800081C8_Color;
extern u32 fn_800081C8(Sig_fn_800081C8_Color, Sig_fn_800081C8_Color, f32);
extern u32 fn_800793D4(u8 *, u32, void *);
extern u32 fn_80083DB0(u32, u32);
extern u32 lbl_801A6410;

extern u8 * fn_80083970(u8 *, const u8 *);
extern u8 lbl_1_rodata_26F8[];
extern u8 lbl_4_bss_5684;
extern u8 lbl_4_data_2F78[];
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_494DC(s16);
extern void fn_1_49514(Sig_fn_800081C8_Color);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
struct Sig_fn_800081C8_Color { u8 r, g, b, a; };

#pragma fp_contract off
#pragma opt_common_subs off
#pragma opt_lifetimes off
#pragma opt_loop_invariants off
extern int __abs(int);
#pragma force_active on
static const u32 fzgx_pool_table_0[] = {2305855636u,0u,2187362913u,2187493987u,2187625061u,2187756135u,2187887209u,2188018283u,2188149357u,2188280431u,2188411505u,2188542579u,2188673653u,2188804727u,2188935801u,2189525634u,2189656708u,2189787782u,2189918856u,2190049930u,2190181004u,2190312078u,2190443152u,2190574226u,2190705300u,2190836374u,2190967448u,2191098522u,2186248784u,2186379858u,2186510932u,2186642006u,2186773080u,2179432936u,0u,2189525634u,2189656708u,2189787782u,2189918856u,2190049930u,2190181004u,2190312078u,2190443152u,2190574226u,2190705300u,2190836374u,2190967448u,2191098522u,2187362913u,2187493987u,2187625061u,2187756135u,2187887209u,2188018283u,2188149357u,2188280431u,2188411505u,2188542579u,2188673653u,2188804727u,2188935801u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,0u,2337049990u,0u,2168553794u,2169274701u,2168815939u,2168750406u,2168947016u,2169078139u,2172420446u,2172748163u,2172944719u,2169602400u,2170716533u,2172027241u,2171240815u,2171634029u,2171502991u,2173731219u,2173993365u,2174124439u,2179432936u,0u,2194703079u,2192212680u,0u,2191557282u,2191819430u,2192081577u,2192278189u,2192540337u,2192802485u,2193064633u,2193326781u,2193588930u,2193916614u,2194178761u,2194309835u,2194440909u,2194703059u,2195096281u,2195489501u,2195620575u,2195751650u,2196013798u,2196210408u,2196341482u,2196472557u,2196669167u,2196800241u,2192212652u,2192474800u,2192736948u,2192999096u,2193261244u,2193523392u,2193851077u,2194113230u,2194768596u,2195161818u,2194637522u,2195030744u,2195423903u,2191622819u,2191884967u,2193720033u,2195948261u,2196537831u,2179465216u,2191491745u,2191753893u,2192016042u,2192343726u,2192605874u,2192868022u,2193130170u,2193392318u,2193654465u,2193982151u,2168488256u,2168488256u,2168488654u,2194768596u,2195161818u,2168488256u,2168488256u,2168488673u,2195948261u,2168488256u,2168488256u,2168488684u,2168488256u,2168488256u,2192147115u,2192409263u,2192671411u,2192933559u,2193195707u,2193457855u,2193785540u,2194047695u,2194834133u,2195227355u,2194506448u,2194899670u,2195292832u,2191688356u,2191950504u,2193785570u,2196013798u,2196603200u,2168455168u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488643u,2168488256u,2168488256u,2168488256u,2168488655u,2194834133u,2195227355u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2193719616u,2168488653u,2194703059u,2195096281u,2194571985u,2194965207u,2195358016u,2168488256u,2168488256u,2193850688u,2168488256u,2168488256u,2168455168u,2202698590u,2202698601u,0u,2202108739u,2202370887u,2202633034u,2202829646u,2203091794u,2203353942u,2203616090u,2203878238u,2204140387u,2204468071u,2204730218u,2204861292u,2204992366u,2205254516u,2195096442u,2206040958u,2206237569u,2206368644u,2206630792u,2206827402u,2206958476u,2207089551u,2207286161u,2207417235u,2207548235u,2202895183u,2203157331u,2203419479u,2203681627u,2203943775u,2204205924u,2204533608u,2205123442u,2205516503u,2205909872u,2205385590u,2195227516u,2202043202u,2202305350u,2202567573u,2207679330u,2206434181u,2206696334u,2179432936u,0u,2202043202u,2202305350u,2202567499u,2202895183u,2203157331u,2203419479u,2203681627u,2203943775u,2204205922u,2204533608u,2168488256u,2168488256u,2168488815u,2205320053u,2195161979u,2168488256u,2168488256u,2168488835u,2206565255u,2168488256u,2168488256u,2168488846u,2168488256u,2168488256u,2202370890u,2202829646u,2203091794u,2203353942u,2203616090u,2203878238u,2204140387u,2204468071u,2205188979u,2205582040u,2205975406u,2205254516u,2195096442u,2202108739u,2202370887u,2202633034u,2203091811u,2206499718u,2206761871u,2168488256u,0u,2168488256u,2207547712u,2168488853u,2168488256u,2207678784u,2168488256u,2168488256u,2168488256u,2168488804u,2168488256u,2168488256u,2168488256u,2168488816u,2205385590u,2195227516u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2168488256u,2202305429u,2168488256u,2207678784u,2168488256u,2168488256u,2168488256u,2168488802u,2168488256u,2205057905u,2205450966u,2205844335u,2205320053u,2195161979u,2168488256u,2207547712u,2168488779u,2203157348u,2168488256u,2168488256u,2168488256u,0u,1130459241u,1952541728u,1281717364u,1701999360u,2187362913u,2187493987u,2187625061u,2187756135u,2187887209u,2188018283u,2188149357u,2188280431u,2188411505u,2188542579u,2188673653u,2188804727u,2188935801u,2179432936u,0u,1399677292u,1814056037u,1953785202u,1929379840u,2189525634u,2189656708u,2189787782u,2189918856u,2190049930u,2190181004u,2190312078u,2190443152u,2190574226u,2190705300u,2190836374u,2190967448u,2191098522u,2179432936u,0u,1399416686u,1929379840u,2168684868u,2169012553u,2172354940u,2170454367u,2172748163u,2172944710u,2168947020u,2169340239u,2169602402u,2171175274u,2171437422u,2171568496u,2173731219u,2173993365u,2174124439u,2179432936u,0u,1316318562u,1701999360u,2186248784u,2186379858u,2186510932u,2186642006u,2186773080u,2179432936u,0u,1070260551u,2920577761u,1073392298u,2863311531u,1071644672u,0u,1111490560u,1048576000u,1072693248u,0u,1040522936u,0u,1073217536u,0u,1073741824u,0u,1070945621u,1031798784u};
#pragma force_active reset
#pragma push
#pragma section code_type ".fzgxpool"
static f64 fzgx_signed_double(s32 value) { return (f64)value; }
static f64 fzgx_unsigned_double(u32 value) { return (f64)value; }
static f32 fzgx_glyph_size(s32 index) {
switch(index) {
case 0:return 32.0f;
case 1:return 24.0f;
default:return 18.0f;
}
}
#pragma force_active reset
#pragma pop
void fn_4_B528(u32 arg0) {
u8 *p_lbl_8_data_A1E8;
struct fn_8_DD64_lbl_8_rodata_408 *p_lbl_8_rodata_408;
u8 *p_lbl_1_rodata_26F8;
u32 v0;
s32 v1;
s32 v2;
s32 state_value;
s32 cursor_next;
s32 v3;
u32 v4;
f32 v5;
f64 v6;
f32 v7;
struct OptionNameEntry { u16 cursor, length; char *chars; u8 pad[12]; } *v8;
u32 v9;
s32 v10;
u32 v12;
u32 v13;
u32 v14;
s32 v15;
f32 v16;
u16 v17;
f64 v18;
u32 v19;
u8 * v20;
u32 v21;
u32 v22;
f64 v23;
f32 v24;
f64 v25;
f32 v26;
f32 v27;
struct { u32 a[22]; } loc_18;
Sig_fn_800081C8_Color loc_14;
Sig_fn_800081C8_Color loc_10;
Sig_fn_800081C8_Color loc_C;
u32 loc_8;

u32 lab_t0;
u32 lab_t1;
p_lbl_8_data_A1E8 = lbl_4_data_2F78;
p_lbl_8_rodata_408 = &lbl_4_rodata_410;
fn_800793D4((u8 *)lbl_801A63D0.unk_0, 0, (void *)1024);
v0 = lbl_801A63D0.unk_0;
if (lbl_4_bss_5684 != 0) {
{ s32 __reg_value_v2 = arg0; v2 = __reg_value_v2; }
v1 = (u32)&lbl_801A6410;
v3 = (u32)((u8 *)(u32)p_lbl_8_data_A1E8 + 160);
v1 = *(u32 *)((u8 *)v1 + 0);
v4 = 465;
fn_1_46B4(v1, v2, (const char *)v3, v4);
v1 = fn_1_4060();
} else {
v1 = fn_1_49410();
v1 = 42;
fn_1_494DC(v1);
v1 = 9;
fn_1_495C8(v1);
fn_1_4966C(12.0f, 0.0f);
v1 = lbl_4_bss_5680->unk_3C;
v8 = (struct OptionNameEntry *)v1 + *(u8 *)arg0;
v19 = v8->cursor;
v3 = (v19 - 10);
v1 = (v19 + 11);
if (v3 >= 0 && (s32)(v19 + 11) <= (s32)v8->length) {
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v9 = (v3 << 1);
v3 = 42;
{ s32 __reg_value_v2 = (v2 + v9); v2 = __reg_value_v2; }
v1 = (u32)strncpy((char *)v1, (const char *)v2, v3);
} else if (v19 < 10) {
v10 = v19 - 10;
v10 = v8->length + v10;
if (v10 < 0) {
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
{ s32 __reg_value_v2 = (v2 + (v19 << 1)); v2 = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2;
v1 = fn_80083DB0(lab_t0, lab_t1);
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v1 = (u32)strcat((char *)v1, (const char *)v2);
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v3 = ((v10 + 10) << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
} else {
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
{ s32 __reg_value_v2 = (v2 + (v10 << 1)); v2 = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2;
v1 = fn_80083DB0(lab_t0, lab_t1);
v1 = v8->cursor;
v10 = (v1 + 11);
if ((s32)v10 > (s32)v8->length) {
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v1 = (u32)strcat((char *)v1, (const char *)v2);
v1 = v0;
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v3 = ((v10 - v8->length) << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
} else {
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
v3 = (v10 << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
}
}
} else {
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v1 = v0;
{ s32 __reg_value_v2 = (v2 + (v3 << 1)); v2 = __reg_value_v2; }
lab_t0 = v1;
lab_t1 = v2;
v1 = fn_80083DB0(lab_t0, lab_t1);
{ s32 __reg_value_v2 = v8->cursor; v2 = __reg_value_v2; }
v1 = v0;
v3 = v8->length;
v12 = (v2 + 11);
{ s32 __reg_value_v2 = (u32)v8->chars; v2 = __reg_value_v2; }
v3 = ((v12 - v3) << 1);
v1 = (u32)fn_80083CF4((char *)v1, (const char *)v2, v3);
}
{ s32 __reg_value_v2 = *(u8 *)((u8 *)arg0 + 0); v2 = __reg_value_v2; }
v1 = (u32)lbl_4_bss_5680;
if ((u32)v2 == *(u8 *)((u8 *)v1 + 13)) {
u32 b14;
{ s32 __reg_value_v2 = (v0 + 6); v2 = __reg_value_v2; }
v1 = (u32)&lbl_801A63D0;
v3 = 14;
v1 = *(u32 *)((u8 *)v1 + 0);
v10 = (v1 + 44);
b14 = (v1 + 88);
v1 = v10;
v1 = (u32)strncpy((char *)v1, (const char *)v2, v3);
v1 = b14;
{ s32 __reg_value_v2 = (v0 + 22); v2 = __reg_value_v2; }
v3 = 14;
v1 = (u32)strncpy((char *)v1, (const char *)v2, v3);
v1 = v0;
v3 = v10;
v4 = b14;
{ s32 __reg_value_v2 = (u32)((u8 *)(u32)p_lbl_8_data_A1E8 + 184); v2 = __reg_value_v2; }
v1 = sprintf((char *)v1, (const char *)(u32)v2, v3, v4);
}
v1 = (u32)lbl_4_bss_5680;
v1 = *(u8 *)((u8 *)v1 + 13);
v1 = (*(u8 *)((u8 *)arg0 + 0) - v1);
if (v1 < 0) {
v1 += 4;
}
switch (v1) {
case 0:
v15 = 178;
v16 = fzgx_glyph_size(0);
{ Sig_fn_800081C8_Color color0 = {255, 255, 255, 0}; loc_14 = color0; }
break;
case 1:
v15 = 276;
v16 = fzgx_glyph_size(1);
{ Sig_fn_800081C8_Color color1 = {0, 255, 255, 0}; loc_14 = color1; }
break;
case 2:
v15 = 313;
v16 = fzgx_glyph_size(2);
{ Sig_fn_800081C8_Color color2 = {0, 255, 255, 0}; loc_14 = color2; }
break;
case 3:
v15 = 84;
v16 = fzgx_glyph_size(1);
{ Sig_fn_800081C8_Color color3 = {0, 255, 255, 0}; loc_14 = color3; }
}
state_value = *(u16 *)((u8 *)arg0 + 4);
v3 = v15 - state_value;
v6 = 0.2 * fzgx_signed_double(v3);
if ((s32)v6 != 0) {
*(u16 *)((u8 *)arg0 + 4) = (s32)((f64)(u32)state_value + v6);
} else {
if (v3 < 0) {
v1 = -1;
} else {
v1 = v3 > 0;
}
*(u16 *)((u8 *)arg0 + 4) += v1;
}
v7 = *(f32 *)((u8 *)arg0 + 8);
v6 = 0.2;
*(f32 *)((u8 *)arg0 + 8) = v7 + v6 * (v16 - v7);
v1 = *(u8 *)((u8 *)arg0 + 2);
v13 = v8->cursor;
state_value = v1 + 1;
if (state_value == (s32)v13 || --v1 > (s32)v13) {
*(u8 *)((u8 *)arg0 + 1) = 36;
} else if (v1 == (s32)v13 || state_value < (s32)v13) {
*(s8 *)((u8 *)arg0 + 1) = -36;
}
v2 = (s8)*(u8 *)((u8 *)arg0 + 1);
v3 = -v2;
v6 = 0.2 * fzgx_signed_double(v3);
if ((s32)v6 != 0) {
*(u8 *)((u8 *)arg0 + 1) = (s32)((f64)v2 + v6);
} else {
if (v3 < 0) {
v1 = -1;
} else {
v1 = v3 > 0;
}
*(u8 *)((u8 *)arg0 + 1) += v1;
}
v1 = v0;
v2 = (u32)(p_lbl_8_data_A1E8 + 196);
*(u8 *)((u8 *)arg0 + 2) = v8->cursor;
v1 = (u32)fn_80083970((u8 *)v1, (const u8 *)v2);
p_lbl_1_rodata_26F8 = lbl_1_rodata_26F8;
v15 = 0x10000 - 28914;
v20 = (u8 *)v1;
v24 = 10.1f;
v25 = 24.0;
while (v20 != 0) {
v1 = strlen((const char *)v0);
state_value = v20 - (u8 *)v0;
v3 = v1 - 1;
v1 = (u32)state_value >> 31;
v1 = v1 + state_value;
state_value = (u32)v3 >> 2;
v1 >>= 1;
v3 = (u32)&loc_14;
v2 = v1 - state_value;
state_value = (u32)p_lbl_1_rodata_26F8 - 4;
for (v21 = 11; v21 != 0; v21--) {
v1 = *(u32 *)((u8 *)state_value + 4);
v22 = *(u32 *)((u8 *)state_value + 8);
state_value += 8;
*(u32 *)((u8 *)v3 + 4) = v1;
*(u32 *)((u8 *)v3 + 8) = v22;
v3 += 8;
}
loc_18.a[0] = v15;
v3 = *(u8 *)((u8 *)arg0 + 1);
v1 = (s8)v3;
v26 = (f32)(s32)v2 * *(f32 *)((u8 *)arg0 + 8);
v5 = (f32)(v1 + 320);
*(f32 *)((u8 *)&loc_18 + 4) = v5 + v26;
if (__abs((s32)v2) > 0) {
v3 = 1;
if ((s32)v2 < 0) v3 = -1;
state_value = (s32)v2 >> 31;
v1 = state_value ^ (s32)v2;
v1 -= state_value;
v6 = 12.0;
v7 = *(f32 *)((u8 *)&loc_18 + 4);
*(f32 *)((u8 *)&loc_18 + 4) = v7 + v6 * (v3 * v1);
}
*(f32 *)((u8 *)&loc_18 + 8) = (f32)(u32)*(u16 *)((u8 *)arg0 + 4);
*(f32 *)((u8 *)&loc_18 + 12) = v24;
loc_18.a[12] = 10;
v5 = 1.0f;
v27 = *(f32 *)((u8 *)arg0 + 8) / v25;
*(f32 *)((u8 *)&loc_18 + 20) = v27;
*(f32 *)((u8 *)&loc_18 + 16) = v27;
{
Sig_fn_800081C8_Color black = {0, 0, 0, 255};
Sig_fn_800081C8_Color white = {255, 255, 255, 255};
loc_10 = black;
loc_C = white;
v1 = fn_800081C8(loc_10, loc_C, v5);
}
loc_18.a[14] = v1;
fn_1_4F734((FontDrawPacket *)&loc_18);
v20 = fn_80083970(v20 + 2, p_lbl_8_data_A1E8 + 196);
}
v2 = (s8)*(u8 *)((u8 *)arg0 + 1);
v2 += 320;
v5 = (f32)v2;
v6 = (f32)(u32)*(u16 *)((u8 *)arg0 + 4);
fn_1_496FC(v5, v6);
v18 = *(f32 *)((u8 *)arg0 + 8) / 24.0;
fn_1_4955C(v18, v18);
{
fn_1_49514(loc_14);
}
fn_1_4954C(10.0f);
fn_1_4A0D8((const char *)v0);
}
}
#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset
#pragma opt_common_subs reset
/* fzgx:end fn_4_B528 */

/* fzgx:begin fn_4_BC04 noprologue */
typedef signed char s8;


typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef double f64;


typedef unsigned long size_t;


/* lbl_10_bss_55CD8: .bss size 0x4, 5 refs from sel.c */
typedef struct {
u32 unk_0; /* 12 loads, 7 stores */
u32 unk_4; /* 1 loads, 1 stores */
u32 unk_8; /* 5 loads, 1 stores */
u8 unk_C; /* 8 loads, 1 stores */
u8 unk_D; /* 5 loads, 4 stores */
u8 unk_E; /* 10 loads, 4 stores */
u8 unk_F; /* 3 loads, 12 stores */
u8 unk_10; /* 1 loads, 0 stores */
u8 unk_11; /* 2 loads, 1 stores */
u16 unk_12; /* 3 loads, 3 stores */
u8 unk_14; /* 2 loads, 2 stores */
u8 unk_15; /* 2 loads, 2 stores */
u8 unk_16; /* 2 loads, 2 stores */
u8 unk_17; /* 2 loads, 2 stores */
u32 unk_18; /* 1 loads, 1 stores */
u32 unk_1C; /* 1 loads, 1 stores */
u32 unk_20; /* 3 loads, 2 stores */
u8 pad_24[0x4];
u8 unk_28; /* 2 loads, 0 stores */
u8 pad_29[0xD];
u8 unk_36; /* 2 loads, 1 stores */
u8 unk_37; /* 0 loads, 1 stores */
u8 pad_38[0x2];
u8 unk_3A; /* 2 loads, 2 stores */
u8 unk_3B; /* 5 loads, 2 stores */
u32 unk_3C; /* 4 loads, 2 stores */
} Obj_10_bss_55CD8_Target;
extern Obj_10_bss_55CD8_Target *lbl_4_bss_5680;
/* lbl_10_data_68E0: .data size 0xA0, 5 refs from sel.c (own data block) */
extern u8 lbl_4_data_2F78[0xA0];


extern u8 lbl_4_bss_5685;
extern char *strncpy(char *, const char *, size_t);
extern s32 strncmp(const char *, const char *, size_t);


extern const f64 lbl_4_rodata_B70;
extern const u32 lbl_4_rodata_B68;
extern void *fn_1_45D0(u32, u32, u8 *, u32);
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern void fn_4_ADF4(void);
extern u8 lbl_1_bss_9F8[];
extern u8 lbl_1_bss_A48[];
extern u32 lbl_801A6410;
extern void fn_1_A2D84(u32);
typedef struct { u8 r, g, b, a; } MenuColor;
typedef struct {
u16 cur;
u16 max;
u8 *p4;
u8 *p8;
u8 *pC;
u32 pad;
} MenuEntry;
#pragma opt_common_subs off
void fn_4_BC04(void) {
u8 *p;
void *rp;
u8 *q;
u32 cnt;
s32 flA;
s32 flB;
s32 flC;
u8 buf[2];
s32 i;
u16 *repeat;
u16 *held;
Obj_10_bss_55CD8_Target *state;
u8 *t8;
MenuEntry *e;
s32 inputIndex;
Obj_10_bss_55CD8_Target *active;
Obj_10_bss_55CD8_Target **inputRef;
s32 prev;
u8 *alternate;
MenuColor v68;
p = lbl_4_data_2F78;
flA = 0;
flB = 0;
flC = 0;
if (lbl_4_bss_5680->unk_0 >> 31) {
if (lbl_4_bss_5685 == 0) {
goto end; /* matches retail's single early-exit block */
}
}
state = lbl_4_bss_5680;
e = (MenuEntry *)state->unk_3C + state->unk_D;
t8 = lbl_1_bss_9F8 + 8;
if ((((u16 *)t8)[state->unk_C * 10] >> 12) & 1) {
if (e->cur == e->max - 1) {
lbl_4_bss_5680->unk_0 |= 0x20000000;
fn_1_A2D84(0xA9010F00);
} else {
MenuEntry *z;
lbl_4_bss_5680->unk_F = 0;
z = (MenuEntry *)lbl_4_bss_5680->unk_3C;
for (i = 0; i < lbl_4_bss_5680->unk_3B; i++) {
z->cur = z->max - 1;
z++;
}
fn_1_A2D84(0xA9010F00);
}
} else if (((((u16 *)t8)[state->unk_C * 10] >> 8) & 1) && lbl_4_bss_5685 == 0) {
s32 cur = e->cur;
if (cur == e->max - 1) {
lbl_4_bss_5680->unk_0 |= 0x20000000;
fn_1_A2D84(0xA9010F00);
} else {
cnt = (u8)(state->unk_E);
flA = 1;
if (cnt == 7 && state->unk_36 != 0) {
flB = 1;
}
{
switch (state->unk_F) {
case 0: q = e->p4 + cur * 2; break;
case 1: q = e->p8 + cur * 2; break;
case 2: q = e->pC + cur * 2; break;
}
}
strncpy((char *)buf, (char *)q, 2);
if (strncmp((char *)q, (char *)(p + 0xb4), 2) == 0) {
strncpy((char *)((u8 *)lbl_4_bss_5680 + lbl_4_bss_5680->unk_E * 2 + 0x28), (char *)(p + 0xb0), 2);
} else {
strncpy((char *)((u8 *)lbl_4_bss_5680 + lbl_4_bss_5680->unk_E * 2 + 0x28), (char *)q, 2);
}
{
Obj_10_bss_55CD8_Target **advanceRef = &lbl_4_bss_5680;
Obj_10_bss_55CD8_Target *advance = *advanceRef;
if (advance->unk_E < 7) {
advance->unk_E = advance->unk_E + 1;
} else {
MenuEntry *z;
s32 j;
z = (MenuEntry *)advance->unk_3C;
for (j = 0; j < (*advanceRef)->unk_3B; j++) {
z->cur = z->max - 1;
z++;
}
}
}
lbl_4_bss_5680->unk_F = 0;
}
} else if (((((u16 *)t8) [lbl_4_bss_5680->unk_C * 10] >> 9) & 1) && lbl_4_bss_5685 == 0) {
u32 pos;
state = lbl_4_bss_5680;
pos = state->unk_E;
flB = pos != 0;
if (pos == 7 && state->unk_36 != 0) {
lbl_4_bss_5680->unk_36 = 0;
lbl_4_bss_5680->unk_37 = 0;
} else {
if (pos != 0) {
state->unk_E = state->unk_E - 1;
}
for (i = lbl_4_bss_5680->unk_E; i <= 7; i++) {
if (i < 7) {
u8 *shift = (u8 *)lbl_4_bss_5680 + i * 2;
shift[0x28] = shift[0x2a];
shift = (u8 *)lbl_4_bss_5680 + i * 2;
shift[0x29] = shift[0x2b];
} else {
*((u8 *)lbl_4_bss_5680 + i * 2 + 0x28) = 0;
*((u8 *)lbl_4_bss_5680 + i * 2 + 0x29) = 0;
}
}
}
lbl_4_bss_5680->unk_F = 0;
cnt = (u8)(lbl_4_bss_5680->unk_E);
} else {
held = (u16 *)(lbl_1_bss_9F8 + 0x10);
if (((held[lbl_4_bss_5680->unk_C * 10] >> 3) & 1) || (((repeat = (u16 *)(lbl_1_bss_9F8 + 0x12), repeat[lbl_4_bss_5680->unk_C * 10]) >> 3) & 1)) {
if (lbl_4_bss_5680->unk_D == 0) {
lbl_4_bss_5680->unk_D = lbl_4_bss_5680->unk_3B - 1;
} else {
lbl_4_bss_5680->unk_D = lbl_4_bss_5680->unk_D - 1;
}
lbl_4_bss_5680->unk_F = 0;
} else if (((held[lbl_4_bss_5680->unk_C * 10] >> 2) & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 2) & 1)) {
if (lbl_4_bss_5680->unk_D == lbl_4_bss_5680->unk_3B - 1) {
lbl_4_bss_5680->unk_D = 0;
} else {
lbl_4_bss_5680->unk_D = lbl_4_bss_5680->unk_D + 1;
}
lbl_4_bss_5680->unk_F = 0;
} else if ((held[lbl_4_bss_5680->unk_C * 10] & 1) || (repeat[lbl_4_bss_5680->unk_C * 10] & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 8) & 1)) {
if (e->cur == 0) {
e->cur = e->max - 1;
} else {
e->cur = e->cur - 1;
}
lbl_4_bss_5680->unk_F = 0;
} else if (((held[lbl_4_bss_5680->unk_C * 10] >> 1) & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 1) & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 9) & 1)) {
if (e->cur == e->max - 1) {
e->cur = 0;
} else {
e->cur = e->cur + 1;
}
lbl_4_bss_5680->unk_F = 0;
} else if ((((u16 *)t8)[lbl_4_bss_5680->unk_C * 10] >> 11) & 1) {
flC = 1;
lbl_4_bss_5680->unk_F = lbl_4_bss_5680->unk_F + 1;
if (lbl_4_bss_5680->unk_F > 2) {
lbl_4_bss_5680->unk_F = 0;
} else if (lbl_4_bss_5680->unk_F == 1) {
alternate = e->p8;
if (alternate == 0) {
flC = 0;
lbl_4_bss_5680->unk_F = 0;
} else if (strncmp((char *)(alternate + e->cur * 2), (char *)(p + 0xb0), 2) == 0) {
flC = 0;
lbl_4_bss_5680->unk_F = 0;
}
} else if (lbl_4_bss_5680->unk_F == 2) {
alternate = e->pC;
if (alternate == 0) {
lbl_4_bss_5680->unk_F = 0;
} else if (strncmp((char *)(alternate + e->cur * 2), (char *)(p + 0xb0), 2) == 0) {
lbl_4_bss_5680->unk_F = 0;
}
}
}
}
{
register Obj_10_bss_55CD8_Target **ref = &lbl_4_bss_5680;
/* Observe the shared state pointer independently before this update stage. */
Obj_10_bss_55CD8_Target *before = *(Obj_10_bss_55CD8_Target *volatile *)ref;
Obj_10_bss_55CD8_Target *after;
s32 prev;
prev = *(s8 *)&before->unk_10;
before->unk_10 = ((s8 *)lbl_1_bss_A48)[before->unk_C << 4] >> 2;
after = *ref;
if (*(s8 *)&after->unk_10 == 0) {
u8 t = lbl_1_bss_A48[after->unk_C << 4];
if ((s8)t > 0) {
after->unk_10 = 1;
} else if ((s8)t < 0) {
*(s8 *)&after->unk_10 = -1;
} else {
*(s8 *)&after->unk_10 = prev < 0 ? -1 : 1;
}
}
}
{
register Obj_10_bss_55CD8_Target **smoothRef = &lbl_4_bss_5680;
/* Observe the shared state pointer again for the animation update. */
Obj_10_bss_55CD8_Target *phase = *(Obj_10_bss_55CD8_Target *volatile *)smoothRef;
u32 old12;
s32 x;
f64 d;
Obj_10_bss_55CD8_Target *smooth;
phase->unk_11 = phase->unk_11 - phase->unk_10;
smooth = *smoothRef;
old12 = smooth->unk_12;
x = smooth->unk_E * 56 + 98 - old12;
d = lbl_4_rodata_B70 * (f64)x;
if ((s32)d != 0) {
smooth->unk_12 = (s32)((f64)old12 + d);
} else {
s32 step;
if (x < 0) {
step = -1;
} else {
step = x > 0;
}
smooth->unk_12 += step;
}
}
if (lbl_4_bss_5680->unk_14 != 0) {
lbl_4_bss_5680->unk_14 = lbl_4_bss_5680->unk_14 - 1;
}
if (lbl_4_bss_5680->unk_15 != 0) {
lbl_4_bss_5680->unk_15 = lbl_4_bss_5680->unk_15 - 1;
}
if (lbl_4_bss_5680->unk_16 != 0) {
lbl_4_bss_5680->unk_16 = lbl_4_bss_5680->unk_16 - 1;
}
if (lbl_4_bss_5680->unk_17 != 0) {
lbl_4_bss_5680->unk_17 = lbl_4_bss_5680->unk_17 - 1;
}
q = lbl_1_bss_9F8 + 0x10;
if (((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) >> 3) & 1) || ((*(u16 *)((u32)(lbl_1_bss_9F8 + 0x12) + lbl_4_bss_5680->unk_C * 20) >> 3) & 1)) {
lbl_4_bss_5680->unk_14 = 8;
}
if (((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) >> 2) & 1) || ((*(u16 *)((u32)(lbl_1_bss_9F8 + 0x12) + lbl_4_bss_5680->unk_C * 20) >> 2) & 1)) {
lbl_4_bss_5680->unk_15 = 8;
}
if ((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) & 1) || ((repeat = (u16 *)(lbl_1_bss_9F8 + 0x12), repeat[lbl_4_bss_5680->unk_C * 10]) & 1) ||
((repeat[lbl_4_bss_5680->unk_C * 10] >> 8) & 1)) {
lbl_4_bss_5680->unk_16 = 8;
}
if (((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) >> 1) & 1) || (((repeat = (u16 *)(lbl_1_bss_9F8 + 0x12), repeat[lbl_4_bss_5680->unk_C * 10]) >> 1) & 1) ||
((repeat[lbl_4_bss_5680->unk_C * 10] >> 9) & 1)) {
lbl_4_bss_5680->unk_17 = 8;
}
if (flA != 0) {
v68 = *(const MenuColor *)&lbl_4_rodata_B68;
rp = fn_1_45D0 (*(u32 *)&lbl_801A6410, 0x12, p + 0xa0, 0xd4);
*(u16 *)((u8 *)rp + 8) = (u16)((u32)(cnt & 0xFF) * 56 + 0x7e);
*(u16 *)((u8 *)rp + 10) = 0x17a;
*(u8 *)((u8 *)rp + 0) = 1;
*(u8 *)((u8 *)rp + 1) = 0x18;
*(u16 *)((u8 *)rp + 4) = 0x140;
*(u16 *)((u8 *)rp + 6) = 0xb2;
*(u8 *)((u8 *)rp + 2) = buf[0];
*(u8 *)((u8 *)rp + 3) = buf[1];
*(MenuColor *)((u8 *)rp + 0xd) = v68;
*(u8 *)((u8 *)rp + 0xc) = cnt;
fn_1_435C(lbl_4_bss_5680->unk_8);
fn_1_3F8C((u32)(p + 0xc8), (u32)fn_4_ADF4, (u32)rp, 0xb);
}
if (flB != 0) {
lbl_4_bss_5680->unk_20 |= ((u32)0x80000000 >> cnt);
}
if (flA != 0) {
lbl_4_bss_5680->unk_3A = 12;
}
if (flA != 0) {
fn_1_A2D84(0xA9010F00);
}
if (flB != 0) {
fn_1_A2D84(0xA9010200);
}
if (flC != 0) {
fn_1_A2D84(0xA9010000);
}
if (((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) >> 3) & 1) || (((repeat = (u16 *)(lbl_1_bss_9F8 + 0x12), repeat[lbl_4_bss_5680->unk_C * 10]) >> 3) & 1) ||
((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) >> 2) & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 2) & 1)) {
fn_1_A2D84(0xA9010000);
}
if ((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) & 1) || ((repeat = (u16 *)(lbl_1_bss_9F8 + 0x12), repeat[lbl_4_bss_5680->unk_C * 10]) & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 8) & 1) ||
((*(u16 *)(q + lbl_4_bss_5680->unk_C * 20) >> 1) & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 1) & 1) || ((repeat[lbl_4_bss_5680->unk_C * 10] >> 9) & 1)) {
fn_1_A2D84(0xA9010000);
}
if (lbl_4_bss_5685 != 0) {
fn_1_A2D84(0xA9010200);
lbl_4_bss_5680->unk_0 &= ~0x80000000u;
}
lbl_4_bss_5685 = 0;
end:
return;
}
#pragma opt_common_subs reset
/* fzgx:end fn_4_BC04 */

/* fzgx:begin fn_4_C768 noprologue */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[360] = {0x89709094, 0x00000000, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x00000000, 0x8B4C8D86, 0x00000000, 0x81418142, 0x814C814D, 0x81458143, 0x81448146, 0x81478148, 0x8149817B, 0x817C815E, 0x81818183, 0x8184814F, 0x81518160, 0x81628175, 0x81768169, 0x816A816F, 0x8170816D, 0x816E818F, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x82D082E7, 0x82AA82C8, 0x00000000, 0x82A082A2, 0x82A482A6, 0x82A882A9, 0x82AB82AD, 0x82AF82B1, 0x82B382B5, 0x82B782B9, 0x82BB82BD, 0x82BF82C2, 0x82C482C6, 0x82C882C9, 0x82CA82CB, 0x82CC82CD, 0x82D082D3, 0x82D682D9, 0x82DC82DD, 0x82DE82DF, 0x82E082E2, 0x82E482E6, 0x82E782E8, 0x82E982EA, 0x82EB82ED, 0x82EE82EF, 0x82F082F1, 0x82AA82AC, 0x82AE82B0, 0x82B282B4, 0x82B682B8, 0x82BA82BC, 0x82BE82C0, 0x82C382C5, 0x82C782CE, 0x82D182D4, 0x82D782DA, 0x82CF82D2, 0x82D582D8, 0x82DB829F, 0x82A182A3, 0x82A582A7, 0x82C182E1, 0x82E382E5, 0x82EC81E7, 0x81E80000, 0x829F82A1, 0x82A382A5, 0x82A782AA, 0x82AC82AE, 0x82B082B2, 0x82B482B6, 0x82B882BA, 0x82BC82BE, 0x82C082C1, 0x82C582C7, 0x81408140, 0x81408140, 0x814082CE, 0x82D182D4, 0x82D782DA, 0x81408140, 0x81408140, 0x814082E1, 0x82E382E5, 0x81408140, 0x81408140, 0x814082EC, 0x81408140, 0x81408140, 0x82A982AB, 0x82AD82AF, 0x82B182B3, 0x82B582B7, 0x82B982BB, 0x82BD82BF, 0x82C282C4, 0x82C682CF, 0x82D282D5, 0x82D882DB, 0x82CD82D0, 0x82D382D6, 0x82D982A0, 0x82A282A4, 0x82A682A8, 0x82C282E2, 0x82E482E6, 0x82ED8140, 0x81400000, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x814082C3, 0x81408140, 0x81408140, 0x81408140, 0x814082CF, 0x82D282D5, 0x82D882DB, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x82C18140, 0x814082CD, 0x82D082D3, 0x82D682D9, 0x82CE82D1, 0x82D482D7, 0x82DA8140, 0x81408140, 0x81408140, 0x82C38140, 0x81408140, 0x81408140, 0x81400000, 0x834A835E, 0x834A8369, 0x00000000, 0x83418343, 0x83458347, 0x8349834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x8369836A, 0x836B836C, 0x836D836E, 0x83718374, 0x82D6837A, 0x837D837E, 0x83808381, 0x83828384, 0x83868388, 0x8389838A, 0x838B838C, 0x838D838F, 0x83908391, 0x83928393, 0x8394834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618364, 0x83668368, 0x836F8372, 0x837582D7, 0x837B8370, 0x83738376, 0x82D8837C, 0x83408342, 0x83448346, 0x83488395, 0x83968362, 0x83838385, 0x8387838E, 0x81E781E8, 0x00000000, 0x83408342, 0x83448346, 0x8348834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618362, 0x83668368, 0x81408140, 0x81408140, 0x8140836F, 0x83728375, 0x82D7837B, 0x81408140, 0x81408140, 0x81408383, 0x83858387, 0x81408140, 0x81408140, 0x8140838E, 0x81408140, 0x81408140, 0x8345834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x83708373, 0x837682D8, 0x837C836E, 0x83718374, 0x82D6837A, 0x83418343, 0x83458347, 0x8349834A, 0x83508363, 0x83848386, 0x8388838F, 0x81408140, 0x00000000, 0x81408140, 0x83948140, 0x81408395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408364, 0x81408140, 0x81408140, 0x81408140, 0x81408370, 0x83738376, 0x82D8837C, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x83448395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408362, 0x81408140, 0x836E8371, 0x837482D6, 0x837A836F, 0x83728375, 0x82D7837B, 0x81408140, 0x83948140, 0x8140834B, 0x83518364, 0x81408140, 0x81408140, 0x81408140, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 225.43910217285156f;
}
static const u32 fzgx_pool_table3[65] = {0x74616C20, 0x4C657474, 0x65727300, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81E781E8, 0x00000000, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x81E781E8, 0x00000000, 0x5369676E, 0x73000000, 0x81438144, 0x81488149, 0x817B817C, 0x815E815F, 0x81818183, 0x81848146, 0x8147814C, 0x814D814F, 0x81518162, 0x8169816A, 0x816D816E, 0x816F8170, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x4E756D62, 0x65727300, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.21;
    d = 1.6666666666666667;
    d = 0.5;
    s = 48.0f;
    s = 0.25f;
    d = 1.0;
    s = 0.12999999523162842f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.5;
    d = 2.0;
    s = 1.6666666269302368f;
    s = 0.0625f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 32.0f;
    s = 24.0f;
    s = 18.0f;
}
static const u32 fzgx_pool_table7[6] = {0xFFFFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x000000FF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.0f;
    s = 0.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    d = 12.0;
    s = 10.100000381469727f;
}
static const u32 fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 24.0;
    s = 1.0f;
    s = 10.0f;
}
static const u32 fzgx_pool_table13[2] = {0x00FFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.649999976158142f;
}
static const u32 fzgx_pool_table15[1] = {0x33333333};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table17[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table20[1] = {0x00FFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 6.0;
    d = 20.0;
    s = 167.0f;
    s = 38.0f;
    s = 0.5f;
    s = 68.0f;
    s = 10.199999809265137f;
    s = 320.0f;
    s = 140.0f;
    s = 98.0f;
    s = 0.1899999976158142f;
    s = 178.0f;
    s = 0.18000000715255737f;
    s = 0.17000000178813934f;
    s = 352.0f;
    s = 0.1599999964237213f;
    s = 0.15000000596046448f;
    s = 0.14000000059604645f;
    s = 110.0f;
    s = 250.0f;
    s = 180.0f;
    s = 390.0f;
    s = 378.0f;
}
static const u32 fzgx_pool_table23[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1;
    d = 0.25;
    s = 346.0f;
    s = 0.11999999731779099f;
    s = 397.0f;
    s = 321.0f;
    d = 2.1666666666666665;
    s = 118.0f;
    s = 0.625f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table25[1] = {0x00FFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef int BOOL;
typedef unsigned long size_t;
typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
/* Packed RGBA transfers coexist with channel-level color operations. */
union fn_4_Color { u32 word; u8 channels[4]; };
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
union fn_4_Color color, color_add;
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);
/* Generated by `fzgx headers --module option`: layouts recovered from every access in the */
/* module's disassembly (matched or not). Field names are offsets until the librarian names them; */
/* offsets and widths are facts, names are not. Regenerate rather than hand-edit padding. */
/* lbl_4_bss_0: .bss size 0x2, referenced by 39 functions, shape {'object': 762} */
extern u16 lbl_4_bss_0;
/* lbl_4_data_0: .data size 0xC, referenced by 17 functions, shape {'object': 49} */
extern u8 lbl_4_data_0[0xC];
/* lbl_4_bss_8: .bss size 0x4, referenced by 14 functions, shape {'object': 14} */
extern u32 lbl_4_bss_8;
/* lbl_4_bss_5680: .bss size 0x4, referenced by 8 functions, shape {'object': 112, 'pointer': 28} */
typedef struct {
u32 unk_0; /* 11 loads, 6 stores */
u32 unk_4; /* 1 loads, 1 stores */
u32 unk_8; /* 4 loads, 1 stores */
u8 unk_C; /* 8 loads, 1 stores */
u8 unk_D; /* 5 loads, 4 stores */
u8 unk_E; /* 10 loads, 3 stores */
u8 unk_F; /* 3 loads, 12 stores */
u8 unk_10; /* 1 loads, 0 stores */
u8 unk_11; /* 2 loads, 1 stores */
u16 unk_12; /* 3 loads, 3 stores */
u8 unk_14; /* 2 loads, 2 stores */
u8 unk_15; /* 2 loads, 2 stores */
u8 unk_16; /* 2 loads, 2 stores */
u8 unk_17; /* 2 loads, 2 stores */
u32 unk_18; /* 1 loads, 1 stores */
u32 unk_1C; /* 1 loads, 1 stores */
u32 unk_20; /* 3 loads, 2 stores */
u8 pad_24[0x4];
u8 unk_28; /* 1 loads, 0 stores */
u8 pad_29[0xD];
u8 unk_36; /* 2 loads, 1 stores */
u8 unk_37; /* 0 loads, 1 stores */
u8 pad_38[0x2];
u8 unk_3A; /* 2 loads, 2 stores */
u8 unk_3B; /* 5 loads, 2 stores */
u32 unk_3C; /* 4 loads, 2 stores */
} Obj_4_bss_5680_Target;
extern Obj_4_bss_5680_Target *lbl_4_bss_5680;
/* lbl_4_bss_5630: .bss size 0x48, referenced by 6 functions, shape {'object': 5} */
typedef struct {
u32 unk_0; /* 0 loads, 3 stores */
u8 unk_4; /* 0 loads, 1 stores */
u8 pad_5[0x1D];
u8 unk_22; /* 1 loads, 0 stores */
u8 pad_23[0x25];
} Obj_4_bss_5630;
extern Obj_4_bss_5630 lbl_4_bss_5630;
/* lbl_4_bss_2: .bss size 0x1, referenced by 5 functions, shape {'object': 10} */
extern u8 lbl_4_bss_2;
/* lbl_4_data_2F78: .data size 0xA0, referenced by 5 functions, shape {} */
extern u8 lbl_4_data_2F78[0xA0];
/* lbl_4_data_2F1C: .data size 0x4, referenced by 4 functions, shape {'object': 4} */
extern u32 lbl_4_data_2F1C;
/* lbl_4_bss_5684: .bss size 0x1, referenced by 3 functions, shape {'object': 3} */
extern u8 lbl_4_bss_5684;
/* lbl_4_bss_4: .bss size 0x4, referenced by 2 functions, shape {'object': 2} */
extern u32 lbl_4_bss_4;
/* lbl_4_bss_10: .bss size 0xB4, referenced by 2 functions, shape {'object': 8} */
typedef struct {
u16 unk_0; /* 4 loads, 4 stores */
u8 pad_2[0xB2];
} Obj_4_bss_10;
extern Obj_4_bss_10 lbl_4_bss_10;
/* lbl_4_bss_C4: .bss size 0x5554, referenced by 2 functions, shape {'object': 16} */
typedef struct {
u8 pad_0[0x2];
u16 unk_2; /* 1 loads, 1 stores */
u16 unk_4; /* 1 loads, 1 stores */
u16 unk_6; /* 1 loads, 1 stores */
u32 unk_8; /* 1 loads, 1 stores */
u32 unk_C; /* 1 loads, 1 stores */
u32 unk_10; /* 1 loads, 1 stores */
u32 unk_14; /* 1 loads, 1 stores */
u32 unk_18; /* 1 loads, 1 stores */
u8 pad_1C[0x5538];
} Obj_4_bss_C4;
extern Obj_4_bss_C4 lbl_4_bss_C4;
/* lbl_4_data_2F00: .data size 0x1C, referenced by 2 functions, shape {'object': 6} */
typedef struct {
u8 pad_0[0x18];
u32 unk_18; /* 3 loads, 1 stores */
} Obj_4_data_2F00;
extern Obj_4_data_2F00 lbl_4_data_2F00;
/* lbl_4_bss_5685: .bss size 0x1, referenced by 2 functions, shape {'object': 6} */
extern u8 lbl_4_bss_5685;
struct fn_4_C768_Copy88 { u32 a[22]; };
struct fn_4_C768_Ro410 {
u8 pad_0[0x6B8];
f64 unk_6B8;
u8 pad_6C0[0x8];
f64 unk_6C8;
f32 unk_6D0;
u8 pad_6D4[0x1C];
f64 unk_6F0;
f64 unk_6F8;
u8 pad_700[0x28];
f32 unk_728;
u8 pad_72C[0xC];
f64 unk_738;
u8 pad_740[0x10];
f32 unk_750;
u8 pad_754[0x14];
u32 unk_768;
u32 unk_76C;
u32 unk_770;
u32 unk_774;
u32 unk_778;
u8 pad_77C[0x4];
f64 unk_780;
f64 unk_788;
f32 unk_790;
f32 unk_794;
f32 unk_798;
f32 unk_79C;
f32 unk_7A0;
f32 unk_7A4;
f32 unk_7A8;
f32 unk_7AC;
f32 unk_7B0;
f32 unk_7B4;
f32 unk_7B8;
f32 unk_7BC;
f32 unk_7C0;
f32 unk_7C4;
f32 unk_7C8;
f32 unk_7CC;
f32 unk_7D0;
f32 unk_7D4;
f32 unk_7D8;
f32 unk_7DC;
f32 unk_7E0;
u8 pad_7E4[0x4];
f64 unk_7E8;
f64 unk_7F0;
f32 unk_7F8;
f32 unk_7FC;
f32 unk_800;
f32 unk_804;
f64 unk_808;
f32 unk_810;
f32 unk_814;
f32 unk_818;
};
struct fn_4_C768_lbl_1_data_418D4 {
u32 unk_0[1];
};
/* Retail colors are both packed words and individual byte channels. */
union fn_4_C768_Clr { u32 w; u8 channels[4]; };
struct fn_4_C768_NameRow {
    u16 index;
    u16 unk_2;
    const char *columns[3];
    const char *label;
};
extern s16 lbl_1_bss_960;
extern s32 lbl_801A66B4;
extern struct fn_4_C768_lbl_1_data_418D4 lbl_1_data_418D4;
extern u8 lbl_1_rodata_26F8[];
extern u32 lbl_4_data_3058;
extern u32 lbl_4_data_3070;
extern u32 lbl_801A66A0;
extern u32 fn_1_49410(void);
extern u32 fn_1_134AD4(void);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_1380F0(void *);
extern u32 fn_1_13ABA8(u32);
extern f32 lbl_8006D188(s16);
extern void * memset(void *, int, u32);
extern char * strncpy(char *, const char *, size_t);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_49514(u32 *);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_133DBC(void *);
void fn_4_C768(void) {
FontDrawPacket loc_20;
u8 buf[3];
union fn_4_C768_Clr clr_18;
union fn_4_C768_Clr clr_14;
union fn_4_C768_Clr clr_10;
union fn_4_C768_Clr clr_C;
u32 sp8;
f32 var_f31;
f32 temp_f0;
f32 temp_f0_2;
f32 temp_f0_3;
f32 temp_f0_4;
f32 temp_f0_5;
u32 var_r28;
u32 var_r27;
u32 var_r27_2;
u32 var_r28_2;
const char *var_r4;
fn_1_49410();
{
u8 c = lbl_4_bss_5680->unk_3A;
struct fn_4_C768_NameRow *base = (struct fn_4_C768_NameRow *)lbl_4_bss_5680->unk_3C + lbl_4_bss_5680->unk_D;
if (c != 0) {
if (c > 9) {
var_f31 = (f32)((0.5) + (f64)(f32)(c - 0xA) / (6.0));
} else {
var_f31 = (f32)((0.5) + (f64)(f32)(0xA - c) / (20.0));
}
lbl_4_bss_5680->unk_3A = (*(u8 volatile *)&(lbl_4_bss_5680->unk_3A)) /* Retail reloads this field. */ - 1;
} else {
var_f31 = (1.0f);
}
fn_1_134AD4();
if (lbl_1_bss_960 != 3) {
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F0C;
loc_20.x = (167.0f);
loc_20.y = (38.0f);
loc_20.z = (0.5f);
loc_20.flags = 0xA;
fn_1_4F734(&loc_20);
}
if ((((*(Obj_4_bss_5680_Target **)(void *)&lbl_4_bss_5680)->unk_0) >> 0x1FU) == 0) {
if (lbl_801A66B4 == 5) {
fn_1_1380F0(&lbl_4_data_3058);
} else {
fn_1_1380F0(&lbl_4_data_3070);
}
} else {
fn_1_1380F0((void *)((u32 *)&lbl_1_data_418D4)[lbl_801A66B4]);
}
fn_1_13ABA8(0x18000000U);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F0A;
loc_20.x = (0.0f);
loc_20.y = (68.0f);
loc_20.z = (10.1999998f);
fn_1_4F734(&loc_20);
loc_20.x = (320.0f);
loc_20.flags |= 0x80000;
fn_1_4F734(&loc_20);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F08;
loc_20.x = (140.0f);
loc_20.y = (98.0f);
loc_20.z = (0.189999998f);
fn_1_4F734(&loc_20);
loc_20.x = (320.0f);
loc_20.flags |= 0x80000;
fn_1_4F734(&loc_20);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F05;
loc_20.x = (320.0f);
loc_20.y = (178.0f);
loc_20.z = (0.180000007f);
loc_20.flags = 0xA;
fn_1_4F734(&loc_20);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F06;
loc_20.x = (320.0f);
loc_20.y = (178.0f);
loc_20.z = (0.170000002f);
loc_20.flags = 0xA;
fn_1_4F734(&loc_20);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F0B;
var_r27 = 0;
var_r28 = 0x62;
loc_20.y = (352.0f);
loc_20.z = (0.159999996f);
do {
loc_20.x = (f32)var_r28;
fn_1_4F734(&loc_20);
var_r27 += 1;
var_r28 += 0x38;
} while (var_r27 < 8);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F07;
loc_20.x = (320.0f);
loc_20.y = (178.0f);
loc_20.z = (0.150000006f);
loc_20.flags = 0xA;
loc_20.rotation_z = (s16)(((u32)lbl_4_bss_5680->unk_11 << 24) >> 16);
if ((1.0) != var_f31) {
loc_20.scale_y = var_f31;
loc_20.scale_x = var_f31;
}
fn_1_4F734(&loc_20);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.x = (320.0f);
loc_20.z = (0.140000001f);
loc_20.flags = 0xA;
loc_20.image = 0x8F0D;
loc_20.y = (110.0f);
{
u8 v = lbl_4_bss_5680->unk_14;
u8 *cb = clr_18.channels;
clr_18.w = fzgx_pool_table16[0];
cb[0] = (u8)((v * 0x10) & 0xF0);
cb[1] = (u8)((v * 0x10) & 0xF0);
cb[2] = (u8)((v * 0x10) & 0xF0);
loc_20.color_add.word = clr_18.w;
temp_f0 = (f32)((1.0) + (f64)v / (12.0));
loc_20.scale_y = temp_f0;
loc_20.scale_x = temp_f0;
}
fn_1_4F734(&loc_20);
loc_20.y = (250.0f);
loc_20.image = 0x8F02;
{
u8 v = lbl_4_bss_5680->unk_15;
u8 *cb = clr_14.channels;
clr_14.w = fzgx_pool_table17[0];
cb[0] = (u8)((v * 0x10) & 0xF0);
cb[1] = (u8)((v * 0x10) & 0xF0);
cb[2] = (u8)((v * 0x10) & 0xF0);
loc_20.color_add.word = clr_14.w;
temp_f0_2 = (f32)((1.0) + (f64)v / (12.0));
loc_20.scale_y = temp_f0_2;
loc_20.scale_x = temp_f0_2;
}
fn_1_4F734(&loc_20);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.y = (180.0f);
loc_20.z = (0.140000001f);
loc_20.x = (250.0f);
loc_20.flags = 0xA;
loc_20.image = 0x8F04;
{
u8 v = lbl_4_bss_5680->unk_16;
u8 *cb = clr_10.channels;
clr_10.w = fzgx_pool_table18[0];
cb[0] = (u8)((v * 0x10) & 0xF0);
cb[1] = (u8)((v * 0x10) & 0xF0);
cb[2] = (u8)((v * 0x10) & 0xF0);
loc_20.color_add.word = clr_10.w;
temp_f0_3 = (f32)((1.0) + (f64)v / (12.0));
loc_20.scale_y = temp_f0_3;
loc_20.scale_x = temp_f0_3;
}
fn_1_4F734(&loc_20);
loc_20.x = (390.0f);
loc_20.flags |= 0x80000;
{
u8 v = lbl_4_bss_5680->unk_17;
u8 *cb = clr_C.channels;
clr_C.w = fzgx_pool_table19[0];
cb[0] = (u8)((v * 0x10) & 0xF0);
cb[1] = (u8)((v * 0x10) & 0xF0);
cb[2] = (u8)((v * 0x10) & 0xF0);
loc_20.color_add.word = clr_C.w;
temp_f0_4 = (f32)((1.0) + (f64)v / (12.0));
loc_20.scale_y = temp_f0_4;
loc_20.scale_x = temp_f0_4;
}
fn_1_4F734(&loc_20);
if (lbl_4_bss_5680->unk_E != 7 || lbl_4_bss_5680->unk_36 == 0) {
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.y = (378.0f);
loc_20.image = 0x8F09;
loc_20.z = (0.129999995f);
{
f64 t = (0.25) * lbl_8006D188((s16)((lbl_801A66A0 << 8) & 0xFF00));
loc_20.flags = 0xA;
temp_f0_5 = (f32)((1.1000000000000001) + t);
}
loc_20.scale_y = temp_f0_5;
loc_20.scale_x = temp_f0_5;
var_r27_2 = lbl_4_bss_5680->unk_E;
var_r28_2 = (var_r27_2 * 0x38) + 0x7C;
while (var_r27_2 < 8) {
loc_20.x = (f32)var_r28_2;
fn_1_4F734(&loc_20);
var_r28_2 += 0x38;
var_r27_2 += 1;
}
}
if ((((*(Obj_4_bss_5680_Target **)(void *)&lbl_4_bss_5680)->unk_0) >> 0x1FU) == 0) {
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F00;
loc_20.x = (f32)((*(Obj_4_bss_5680_Target **)(void *)&lbl_4_bss_5680)->unk_12);
loc_20.y = (346.0f);
loc_20.z = (0.119999997f);
fn_1_4F734(&loc_20);
loc_20.image = 0x8F01;
loc_20.y = (397.0f);
fn_1_4F734(&loc_20);
}
memset(buf, 0, 3);
switch (lbl_4_bss_5680->unk_F) {
case 0:
default:
var_r4 = base->columns[0] + base->index * 2;
break;
case 1:
var_r4 = base->columns[1] + base->index * 2;
break;
case 2:
var_r4 = base->columns[2] + base->index * 2;
break;
}
strncpy((char *)buf, (const char *)var_r4, 2);
fn_1_49410();
fn_1_494DC(0x2A);
fn_1_495C8(9);
fn_1_496FC((321.0f), (178.0f));
{
f64 t = (2.1666666666666665) * (f64)var_f31;
fn_1_4955C((f32)t, (f32)t);
}
fn_1_4A0D8((const char *)buf);
loc_20 = *(FontDrawPacket *)lbl_1_rodata_26F8;
loc_20.image = 0x8F03;
loc_20.x = (118.0f);
loc_20.y = (118.0f);
loc_20.z = (0.189999998f);
fn_1_4F734(&loc_20);
fn_1_49410();
fn_1_494DC(0x2A);
fn_1_496FC((140.0f), (118.0f));
sp8 = fzgx_pool_table20[0];
fn_1_49514(&sp8);
if (lbl_801A66B4 == 5) {
fn_1_4955C((0.625f), (0.625f));
} else {
fn_1_4955C((0.5f), (0.5f));
fn_1_49590((0.300000012f));
fn_1_495B0(0x80000000U);
}
fn_1_4A0D8(base->label);
fn_1_133DBC((void *)1);
}
}
/* fzgx:end fn_4_C768 */

/* fzgx:begin fn_4_D1A8 */
extern struct fn_4_347C_lbl_1_bss_9C8 lbl_1_bss_9C8;
extern u32 lbl_1_data_2AC0;
extern u32 lbl_1_data_2B40;
extern u32 lbl_1_data_2B50;
extern u32 lbl_1_data_2B58;
extern u32 lbl_4_data_14D0;
extern void fn_4_3128(void);
extern u32 fn_80008BA8(u32, u32, u32);
extern u32 fn_1_F7308(void);
extern u32 lbl_1_bss_AA0;
extern u32 lbl_1_data_2B60;
extern u32 lbl_4_data_2AE8;
extern u32 memcpy(u32, u32, u32);
extern void fn_4_63D4(void);
extern int fn_1_4C10(void);
extern u16 lbl_1_bss_96A;
extern u32 fn_4_0(u32, u32, u32, u32, u32);
extern u32 lbl_1_bss_9F8;
extern u8 lbl_4_data_2C58[84];
extern void fn_1_1280(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_4_ABB0(void);
extern u32 fn_1_1380F0(u32);
extern u32 fn_1_13ABA8(u32);
extern u32 lbl_4_data_1A4;
extern s32 lbl_801A66B4;
extern u8 lbl_4_bss_5618;
extern u32 fn_1_B7E98(u32);
extern u32 fn_1_B800C(u32);
extern u32 fn_1_B80F0(u32);
extern u32 fn_1_B8170(u32);
extern u32 lbl_4_data_2DB4;
extern void fn_4_9AD0(void);
extern u8 *fn_4_A82C(u8 *);
extern void fn_80083DB0(u8 *, u32);
extern u32 fn_1_B9C0C(void);
extern s8 fn_1_BA144(u32 *);
extern u32 lbl_4_bss_5678;
extern u32 fn_1_B7C00(void);
extern u32 fn_1_BC310(void *);
extern u32 fn_1_C0510(u32);
extern u32 fn_1_C1394(void *);
extern s16 lbl_1_bss_962;
extern struct fn_4_9B0_lbl_4_data_1260 lbl_4_data_1260;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_426C(u32);
extern void fn_4_AB90(void);
extern struct _prolog_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern struct fn_4_869C_lbl_1_bss_718E0 lbl_1_bss_718E0;
extern s32 lbl_1_bss_970;
extern u8 lbl_4_bss_2;
extern u16 lbl_1_bss_968;

struct fn_4_D760_lbl_801A6410 { u32 unk_0; };
extern struct fn_4_D760_lbl_801A6410 lbl_801A6410;
Obj_4_bss_5680_Target *lbl_4_bss_5680;
u8 lbl_4_bss_5684;
u8 lbl_4_bss_5685;
extern s16 lbl_1_bss_960;
extern s32 lbl_801A66B4;
typedef union Word8 {
u32 w;
f32 f;
} Word8;
typedef struct Node {
u8 unk_0;
u8 pad_1[3];
u16 unk_4;
Word8 unk_8;
s8 unk_c;
u8 pad_d[0x5];
u16 unk_12;
u8 pad_14[0x4];
u32 unk_18;
u32 unk_1c;
u8 pad_20[0x1b];
u8 unk_3b;
u32 unk_3c;
} Node;
typedef struct {
u8 pad_0[0x700];
f32 unk_700;
f32 unk_704;
f32 unk_708;
} RData;
extern RData lbl_4_rodata_410;
extern s32 fn_1_45D0(u32, u32, u32, u32);
extern u32 fn_800793D4(u32, s32, u32);
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern void fn_1_47F74(s32);
extern void fn_1_411A4(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_4_BC04;
extern u32 fn_4_C768;
extern u32 fn_4_B528;
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma opt_pointer_analysis off
#pragma opt_strength_reduction on
extern u8 lbl_4_rodata_410__fzgx_offset_0[];
extern u8 lbl_4_rodata_418__fzgx_offset_0[];
extern u8 lbl_4_rodata_49C__fzgx_offset_0[];
extern u8 lbl_4_rodata_520__fzgx_offset_0[];
extern u8 lbl_4_rodata_528__fzgx_offset_0[];
extern u8 lbl_4_rodata_578__fzgx_offset_0[];
extern u8 lbl_4_rodata_584__fzgx_offset_0[];
extern u8 lbl_4_rodata_630__fzgx_offset_0[];
extern u8 lbl_4_rodata_6DC__fzgx_offset_0[];
extern u8 lbl_4_rodata_788__fzgx_offset_0[];
extern u8 lbl_4_rodata_794__fzgx_offset_0[];
extern u8 lbl_4_rodata_848__fzgx_offset_0[];
extern u8 lbl_4_rodata_8FC__fzgx_offset_0[];
extern u8 lbl_4_rodata_9B0__fzgx_offset_0[];
extern u8 lbl_4_rodata_9C0__fzgx_offset_0[];
extern u8 lbl_4_rodata_9FC__fzgx_offset_0[];
extern u8 lbl_4_rodata_A0C__fzgx_offset_0[];
extern u8 lbl_4_rodata_A48__fzgx_offset_0[];
extern u8 lbl_4_rodata_A50__fzgx_offset_0[];
extern u8 lbl_4_rodata_A94__fzgx_offset_0[];
extern u8 lbl_4_rodata_A9C__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_4_data_2F78[20] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x40, (u32)lbl_4_rodata_418__fzgx_offset_0, (u32)lbl_4_rodata_49C__fzgx_offset_0, 0x0, (u32)lbl_4_rodata_410__fzgx_offset_0, 0x26, (u32)lbl_4_rodata_528__fzgx_offset_0, 0x0,
    0x0, (u32)lbl_4_rodata_520__fzgx_offset_0, 0x55, (u32)lbl_4_rodata_584__fzgx_offset_0, (u32)lbl_4_rodata_630__fzgx_offset_0, (u32)lbl_4_rodata_6DC__fzgx_offset_0, (u32)lbl_4_rodata_578__fzgx_offset_0, 0x58,
    (u32)lbl_4_rodata_794__fzgx_offset_0, (u32)lbl_4_rodata_848__fzgx_offset_0, (u32)lbl_4_rodata_8FC__fzgx_offset_0, (u32)lbl_4_rodata_788__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_4_data_2F78_50[20] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x1C, (u32)lbl_4_rodata_9C0__fzgx_offset_0, 0x0, 0x0, (u32)lbl_4_rodata_9B0__fzgx_offset_0, 0x1C, (u32)lbl_4_rodata_A0C__fzgx_offset_0, 0x0,
    0x0, (u32)lbl_4_rodata_9FC__fzgx_offset_0, 0x20, (u32)lbl_4_rodata_A50__fzgx_offset_0, 0x0, 0x0, (u32)lbl_4_rodata_A48__fzgx_offset_0, 0xC,
    (u32)lbl_4_rodata_A9C__fzgx_offset_0, 0x0, 0x0, (u32)lbl_4_rodata_A94__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_4_data_3018[16] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6E616D65, 0x5F656E74, 0x72792E63, 0x0, 0x81400000, 0x81E70000, 0x25738140, 0x81408140,  /* fzgx-allow: A1 retail data bytes */
    0x25730000, 0x81E80000, 0x6E616D65, 0x5F656E74, 0x72795F66, 0x69786564, 0x5F6C6574, 0x74657200
};
static u32 fzgx_pool_data_lbl_4_data_3058[20] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x96BC914F, 0x82F093FC, 0x82EA82C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x506C6561, 0x73652065,  /* fzgx-allow: A1 retail data bytes */
    0x6E746572, 0x20796F75, 0x72206E61, 0x6D652E20, 0x20000000, 0x83478374, 0x835B838D, 0x0,
    0x8265817C, 0x82798264, 0x8271826E, 0x0
};
static u32 fzgx_pool_data_lbl_4_data_2F78_130[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6E616D65, 0x5F656E74, 0x72795F6D, 0x61696E00
};
static u32 fzgx_pool_data_lbl_4_data_2F78_140[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6E616D65, 0x5F656E74, 0x72795F64, 0x6973705F, 0x6D61696E, 0x0
};
static u32 fzgx_pool_data_lbl_4_data_2F78_158[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x6E616D65, 0x5F656E74, 0x72795F6C, 0x696E6500
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_4_data_2F78(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_4_data_2F78;
    s = *(u8 *)fzgx_pool_data_lbl_4_data_2F78_50;
    s = *(u8 *)fzgx_pool_data_lbl_4_data_3018;
    s = *(u8 *)fzgx_pool_data_lbl_4_data_3058;
    s = *(u8 *)fzgx_pool_data_lbl_4_data_2F78_130;
    s = *(u8 *)fzgx_pool_data_lbl_4_data_2F78_140;
    s = *(u8 *)fzgx_pool_data_lbl_4_data_2F78_158;
}
#pragma section code_type ".text"

#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[360] = {0x89709094, 0x00000000, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x00000000, 0x8B4C8D86, 0x00000000, 0x81418142, 0x814C814D, 0x81458143, 0x81448146, 0x81478148, 0x8149817B, 0x817C815E, 0x81818183, 0x8184814F, 0x81518160, 0x81628175, 0x81768169, 0x816A816F, 0x8170816D, 0x816E818F, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x82D082E7, 0x82AA82C8, 0x00000000, 0x82A082A2, 0x82A482A6, 0x82A882A9, 0x82AB82AD, 0x82AF82B1, 0x82B382B5, 0x82B782B9, 0x82BB82BD, 0x82BF82C2, 0x82C482C6, 0x82C882C9, 0x82CA82CB, 0x82CC82CD, 0x82D082D3, 0x82D682D9, 0x82DC82DD, 0x82DE82DF, 0x82E082E2, 0x82E482E6, 0x82E782E8, 0x82E982EA, 0x82EB82ED, 0x82EE82EF, 0x82F082F1, 0x82AA82AC, 0x82AE82B0, 0x82B282B4, 0x82B682B8, 0x82BA82BC, 0x82BE82C0, 0x82C382C5, 0x82C782CE, 0x82D182D4, 0x82D782DA, 0x82CF82D2, 0x82D582D8, 0x82DB829F, 0x82A182A3, 0x82A582A7, 0x82C182E1, 0x82E382E5, 0x82EC81E7, 0x81E80000, 0x829F82A1, 0x82A382A5, 0x82A782AA, 0x82AC82AE, 0x82B082B2, 0x82B482B6, 0x82B882BA, 0x82BC82BE, 0x82C082C1, 0x82C582C7, 0x81408140, 0x81408140, 0x814082CE, 0x82D182D4, 0x82D782DA, 0x81408140, 0x81408140, 0x814082E1, 0x82E382E5, 0x81408140, 0x81408140, 0x814082EC, 0x81408140, 0x81408140, 0x82A982AB, 0x82AD82AF, 0x82B182B3, 0x82B582B7, 0x82B982BB, 0x82BD82BF, 0x82C282C4, 0x82C682CF, 0x82D282D5, 0x82D882DB, 0x82CD82D0, 0x82D382D6, 0x82D982A0, 0x82A282A4, 0x82A682A8, 0x82C282E2, 0x82E482E6, 0x82ED8140, 0x81400000, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x814082C3, 0x81408140, 0x81408140, 0x81408140, 0x814082CF, 0x82D282D5, 0x82D882DB, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x82C18140, 0x814082CD, 0x82D082D3, 0x82D682D9, 0x82CE82D1, 0x82D482D7, 0x82DA8140, 0x81408140, 0x81408140, 0x82C38140, 0x81408140, 0x81408140, 0x81400000, 0x834A835E, 0x834A8369, 0x00000000, 0x83418343, 0x83458347, 0x8349834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x8369836A, 0x836B836C, 0x836D836E, 0x83718374, 0x82D6837A, 0x837D837E, 0x83808381, 0x83828384, 0x83868388, 0x8389838A, 0x838B838C, 0x838D838F, 0x83908391, 0x83928393, 0x8394834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618364, 0x83668368, 0x836F8372, 0x837582D7, 0x837B8370, 0x83738376, 0x82D8837C, 0x83408342, 0x83448346, 0x83488395, 0x83968362, 0x83838385, 0x8387838E, 0x81E781E8, 0x00000000, 0x83408342, 0x83448346, 0x8348834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618362, 0x83668368, 0x81408140, 0x81408140, 0x8140836F, 0x83728375, 0x82D7837B, 0x81408140, 0x81408140, 0x81408383, 0x83858387, 0x81408140, 0x81408140, 0x8140838E, 0x81408140, 0x81408140, 0x8345834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x83708373, 0x837682D8, 0x837C836E, 0x83718374, 0x82D6837A, 0x83418343, 0x83458347, 0x8349834A, 0x83508363, 0x83848386, 0x8388838F, 0x81408140, 0x00000000, 0x81408140, 0x83948140, 0x81408395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408364, 0x81408140, 0x81408140, 0x81408140, 0x81408370, 0x83738376, 0x82D8837C, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x83448395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408362, 0x81408140, 0x836E8371, 0x837482D6, 0x837A836F, 0x83728375, 0x82D7837B, 0x81408140, 0x83948140, 0x8140834B, 0x83518364, 0x81408140, 0x81408140, 0x81408140, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 225.43910217285156f;
}
static const unsigned long fzgx_pool_table3[65] = {0x74616C20, 0x4C657474, 0x65727300, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81E781E8, 0x00000000, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x81E781E8, 0x00000000, 0x5369676E, 0x73000000, 0x81438144, 0x81488149, 0x817B817C, 0x815E815F, 0x81818183, 0x81848146, 0x8147814C, 0x814D814F, 0x81518162, 0x8169816A, 0x816D816E, 0x816F8170, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x4E756D62, 0x65727300, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.21;
    d = 1.6666666666666667;
    d = 0.5;
    s = 48.0f;
    s = 0.25f;
    d = 1.0;
    s = 0.12999999523162842f;
    s = 0.0f;
    d = 1.5;
    d = 2.0;
    s = 1.6666666269302368f;
    s = 0.0625f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 32.0f;
    s = 24.0f;
    s = 18.0f;
}
static const unsigned long fzgx_pool_table5[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"


void fn_4_D1A8(u32 arg0, u32 arg1, u8 arg2) {
f32 fzgx_live_;
f32 fzgx_live;
u8 *data = (u8 *)fzgx_pool_data_lbl_4_data_2F78;

RData *rd = &lbl_4_rodata_410;
Node *n;
u32 i;
struct { u32 value; } j;
u16 *clear;
lbl_4_bss_5680 = (Obj_4_bss_5680_Target *)fn_1_45D0(lbl_801A6410.unk_0, 0x40, (u32)(((u8 *)fzgx_pool_data_lbl_4_data_3018)), 0x4ef);
fn_800793D4((u32)lbl_4_bss_5680, 0, 0x40);
lbl_4_bss_5680->unk_4 = arg0;
lbl_4_bss_5680->unk_8 = arg1;
fn_1_435C(arg0);
lbl_4_bss_5680->unk_18 = fn_1_3F8C((u32)(((u8 *)fzgx_pool_data_lbl_4_data_2F78_130)), (u32)&fn_4_BC04, 0, 0xa);
fn_1_47F74(0x8f);
if (lbl_1_bss_960 != 1) {
fn_1_47F74(0x9a);
fn_1_47F74(0x9e);
fn_1_411A4(1);
}
fn_1_435C(arg1);
lbl_4_bss_5680->unk_1C = fn_1_3F8C((u32)(((u8 *)fzgx_pool_data_lbl_4_data_2F78_140)), (u32)&fn_4_C768, 0, 0xa);
if (lbl_801A66B4 == 5) {
lbl_4_bss_5680->unk_3C = (u32)((u8 *)fzgx_pool_data_lbl_4_data_2F78);
lbl_4_bss_5680->unk_3B = 4;
} else {
lbl_4_bss_5680->unk_3C = (u32)(((u8 *)fzgx_pool_data_lbl_4_data_2F78_50));
lbl_4_bss_5680->unk_3B = 4;
}
i = 0;
while (i < lbl_4_bss_5680->unk_3B) {
n = (Node *)fn_1_45D0(lbl_801A6410.unk_0, 0xc, (u32)(((u8 *)fzgx_pool_data_lbl_4_data_3018)), 0x1a5);
fn_800793D4((u32)n, 0, 0xc);
n->unk_0 = i;
switch ((u8)i) {
case 0:
n->unk_4 = 0xb2;
n->unk_8.f = (32.0f);
break;
case 1:
n->unk_4 = 0x114;
n->unk_8.f = (24.0f);
break;
case 2:
n->unk_4 = 0x139;
fzgx_live_ = (18.0f);
fzgx_live = fzgx_live_;
n->unk_8.f = fzgx_live;
break;
case 3:
n->unk_4 = 0x54;
n->unk_8.f = (24.0f);
break;
}
fn_1_3F8C((u32)(((u8 *)fzgx_pool_data_lbl_4_data_2F78_158)), (u32)&fn_4_B528, (u32)n, 0xb);
i++;
}
lbl_4_bss_5680->unk_C = arg2;
j.value = 0;
clear = (u16 *)lbl_4_bss_5680->unk_3C;
while (j.value < lbl_4_bss_5680->unk_3B) {
*clear = 0;
j.value++;
}
lbl_4_bss_5680->unk_12 = 0x62;
fn_1_A2D84(0xa9100000U);
lbl_4_bss_5684 = 0;
lbl_4_bss_5685 = 0;
}
#pragma opt_strength_reduction reset
#pragma opt_pointer_analysis reset
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
#pragma opt_common_subs reset
/* fzgx:end fn_4_D1A8 */

/* fzgx:begin fn_4_D420 */
extern u32 lbl_4_rodata_C2C;
extern u32 lbl_4_rodata_C30;
extern s32 lbl_801A66B4;
extern struct fn_4_D420_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_435C(u32);
extern s32 fn_1_45D0(u32, u32, u8 *, u32);
extern s32 fn_1_3F8C(u8 *, u32, u32, u32);
extern void fn_1_A2D84(u32);
extern s32 fn_1_14CEB8(u32);
extern void fn_80083DB0(u8 *, u32);
extern void fn_4_ADF4(void);
struct fn_4_D420_lbl_801A6410 {
    u32 unk_0;
};
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    u8 unk_C;
    u8 pad_D[0x3];
    u32 unk_10;
} Entry_4_D420;
typedef struct { u32 v; } Word;

#pragma opt_loop_invariants off
#pragma opt_lifetimes off
s32 fn_4_D420(void) {
    s32 bit;
    u8 *src;
    s32 i;
    Obj_4_bss_5680_Target *maskstate;
    struct { u8 value; } k;
    struct { s32 value; } n;
    s32 res;
    u8 *src2;
    u8 *data;
    Entry_4_D420 *t;
    Word c;
    Word c2;

    res = 0;
    data = lbl_4_data_2F78;
    if ((lbl_4_bss_5680->unk_0 >> 30) & 1) {
        c = *(Word *)&lbl_4_rodata_C30;
        fn_1_435C(lbl_4_bss_5680->unk_8);
        n.value = 0;
        i = 0;
        while (src = (u8 *)lbl_4_bss_5680 + 0x28 + i, src[0] != 0) {
            t = (Entry_4_D420 *)fn_1_45D0(lbl_801A6410.unk_0, 0x12, ((0xA0) + (data)), 0xD4);
            t->unk_8 = (u8)n.value * 0x38 + 0x7E;
            t->unk_A = 0x17A;
            t->unk_0 = 2;
            t->unk_1 = 0;
            t->unk_4 = t->unk_8;
            t->unk_6 = t->unk_A;
            t->unk_2 = src[0];
            t->unk_3 = src[1];
            *(u32 *)((u8 *)t + 0xD) = c.v;
            t->unk_C = n.value;
            fn_1_3F8C(data + 0xC8, (u32)&fn_4_ADF4, (u32)t, 0xB);
            i += 2;
            n.value += 1;
        }
        c2.v = lbl_4_bss_5680->unk_0;
        /* Retail reloads the target pointer after reading its flags. */
        (*(Obj_4_bss_5680_Target * volatile *)&lbl_4_bss_5680)->unk_0 = c2.v & ~0x40000000;
    }
    if (lbl_4_bss_5680->unk_0 >> 31) {
        return 1;
    }
    if (((lbl_4_bss_5680->unk_0 >> 29) & 1) || ((lbl_4_bss_5680->unk_0 >> 28) & 1)) {
        fn_1_A2D84(0xA9010100);
        lbl_4_bss_5680->unk_0 &= ~0x20000000;
        lbl_4_bss_5680->unk_0 &= ~0x10000000;
        lbl_4_bss_5680->unk_0 |= 0x80000000;
        if (fn_1_14CEB8((u32)lbl_4_bss_5680 + 0x28) != 0) {
            bit = 0;
            lbl_4_bss_5680->unk_0 |= 0x40000000;
            while (((u8 *)lbl_4_bss_5680)[0x28 + bit * 2] != 0) {
                lbl_4_bss_5680->unk_20 |= 0x80000000 >> bit;
                bit++;
            }
        }
        if (((u8 *)lbl_4_bss_5680)[0x28] == 0) {
            if (lbl_801A66B4 == 5) {
                fn_80083DB0((u8 *)lbl_4_bss_5680 + 0x28, (u32)(data + 0x114));
            } else {
                fn_80083DB0((u8 *)lbl_4_bss_5680 + 0x28, (u32)(data + 0x120));
            }
            c2 = *(Word *)&lbl_4_rodata_C2C;
            fn_1_435C(lbl_4_bss_5680->unk_8);
            n.value = 0;
            while (src2 = (u8 *)lbl_4_bss_5680 + 0x28 + n.value * 2, src2[0] != 0) {
                k.value = n.value;
                t = (Entry_4_D420 *)fn_1_45D0(lbl_801A6410.unk_0, 0x12, ((0xA0) + (data)), 0xD4);
                t->unk_8 = k.value * 0x38 + 0x7E;
                t->unk_A = 0x17A;
                t->unk_0 = 2;
                t->unk_1 = 0;
                t->unk_4 = t->unk_8;
                t->unk_6 = t->unk_A;
                t->unk_2 = src2[0];
                t->unk_3 = src2[1];
                *(u32 *)((u8 *)t + 0xD) = c2.v;
                t->unk_C = k.value;
                fn_1_3F8C(data + 0xC8, (u32)&fn_4_ADF4, (u32)t, 0xB);
                n.value += 1;
            }
            lbl_4_bss_5680->unk_E = n.value;
        }
        res = 1;
    }
    return res;
}
#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_4_D420 */
