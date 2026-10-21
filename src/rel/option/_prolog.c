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
