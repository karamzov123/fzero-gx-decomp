#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_800756B0_Vec;

typedef struct {
    u8 unk_0;
    s8 unk_1;
    u8 unk_2;
    s8 unk_3;
    s8 unk_4;
    s8 unk_5;
    u8 pad_6[2];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u16 unk_34;
    u16 unk_36;
    u16 unk_38;
    u8 pad_3A[2];
    u32 unk_3C;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4C;
    fn_800756B0_Vec unk_50;
} fn_800756B0_State;

typedef struct {
    u8 pad_0[4];
    u32 flags;
    fn_800756B0_Vec pos;
    f32 unk_14;
} fn_800756B0_Arg0;

typedef struct {
    u32 flags;
    u8 pad_4[8];
    u32 unk_C;
    u8 pad_10[0x30];
    u32 unk_40;
} fn_800756B0_Arg1;

/* This TU's .bss cluster, laid out in retail order (addressed off one base). */
u8 lbl_8019F040[0x20];
f32 lbl_8019F040__fzgx_offset_20[3][4];
f32 lbl_8019F040__fzgx_offset_50[3][3][4];
s32 lbl_8019F040__fzgx_offset_E0[3];
u8 fzgx_pool_lbl_8019F12C[0x14];
fn_800756B0_Vec lbl_8019F130__fzgx_offset_10;
u8 fzgx_pool_lbl_8019F14C[0x2C];
f32 lbl_8019F158__fzgx_offset_20[3][4];
u8 fzgx_pool_lbl_8019F1A8[0x41E0 - 0x168];
fn_800756B0_State lbl_801A3220;

extern s32 lbl_801A6D78;
extern s32 lbl_801A6D88[2];
extern u32 lbl_801A6D80;
extern s32 lbl_801A6D84;
extern u32 lbl_801A6D7C;
extern s32 lbl_801A6D48;

extern void GXLoadTexMtxImm(f32 mtx[][4], u32 id, s32 type);
extern void fn_80075080(void *);
extern void fn_800736C0(s32, u32 *);
extern void fn_800728A8(s32, s32, s32, s32);
extern void lbl_8006E1B0(fn_800756B0_Vec *, fn_800756B0_Vec *);
extern void lbl_8006D668(fn_800756B0_Vec *);

/* Layout primer (dropped at integration): first use fixes the .bss order. */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fn_800756B0_primer(void) {
    fn_80075080(lbl_8019F040);
    fn_80075080(lbl_8019F040__fzgx_offset_20);
    fn_80075080(lbl_8019F040__fzgx_offset_50);
    fn_80075080(lbl_8019F040__fzgx_offset_E0);
    fn_80075080(fzgx_pool_lbl_8019F12C);
    fn_80075080(&lbl_8019F130__fzgx_offset_10);
    fn_80075080(fzgx_pool_lbl_8019F14C);
    fn_80075080(lbl_8019F158__fzgx_offset_20);
    fn_80075080(fzgx_pool_lbl_8019F1A8);
    fn_80075080(&lbl_801A3220);
}

static inline void fn_800756B0_store(fn_800756B0_State *state, u32 value) {
    state->unk_10 = value;
    state->unk_2 = 0;
    state->unk_14 = 15;
    state->unk_18 = 7;
    state->unk_3 = 0xFF;
    state->unk_4 = 0xFF;
    state->unk_5 = 0xFF;
    state->unk_8 = 16;
    state->unk_C = 16;
}

void fn_800756B0(fn_800756B0_Arg0 *arg0, fn_800756B0_Arg1 *arg1) {
    s32 i;
    u32 color0;
    u32 color1;

    lbl_801A3220.unk_0 = 1;
    if (arg0->flags & 0x18) {
        arg1 = (fn_800756B0_Arg1 *)((u8 *)arg1 + 0x20);
    }
    if (lbl_801A6D78 != 0) {
        GXLoadTexMtxImm(lbl_8019F040__fzgx_offset_20, 0x24, 0);
    } else {
        GXLoadTexMtxImm(lbl_8019F158__fzgx_offset_20, 0x24, 0);
    }
    for (i = 0; i < 3; i++) {
        if (lbl_8019F040__fzgx_offset_E0[i] != 0) {
            GXLoadTexMtxImm(lbl_8019F040__fzgx_offset_50[i], 0x33 + i * 3, 0);
        } else {
            GXLoadTexMtxImm(lbl_8019F158__fzgx_offset_20, 0x33 + i * 3, 0);
        }
    }
    fn_80075080(arg1);
    { struct CopyWord { u32 value; };
    *(struct CopyWord *)&lbl_801A3220.unk_10 = *(struct CopyWord *)&arg1->unk_C;
    lbl_801A3220.unk_2 = 0;
    lbl_801A3220.unk_14 = 15;
    lbl_801A3220.unk_18 = 7;
    lbl_801A3220.unk_3 = 0xFF;
    lbl_801A3220.unk_4 = 0xFF;
    lbl_801A3220.unk_5 = 0xFF;
    lbl_801A3220.unk_8 = 16;
    lbl_801A3220.unk_C = 16;
    }
    if (lbl_801A6D88[0] != 0) {
        color0 = lbl_801A6D80;
        fn_800736C0(2, &color0);
    }
    if (lbl_801A6D84 != 0) {
        color1 = lbl_801A6D7C;
        fn_800736C0(3, &color1);
    }
    lbl_801A3220.unk_1C = 4;
    lbl_801A3220.unk_20 = 5;
    if (arg1->flags & 0x20) {
        lbl_801A3220.unk_1C = arg1->unk_40 & 0xF;
    }
    if (arg1->flags & 0x40) {
        lbl_801A3220.unk_20 = (arg1->unk_40 >> 4) & 0xF;
    }
    fn_800728A8(1, lbl_801A3220.unk_1C, lbl_801A3220.unk_20, 0);
    lbl_801A3220.unk_1 = 0xFF;
    lbl_801A3220.unk_24 = -1;
    lbl_801A3220.unk_28 = -1;
    lbl_801A3220.unk_2C = -1;
    lbl_801A3220.unk_30 = -1;
    lbl_801A3220.unk_34 = 0xFFFF;
    lbl_801A3220.unk_36 = 0xFFFF;
    lbl_801A3220.unk_38 = 0xFFFF;
    lbl_801A3220.unk_3C = 0;
    lbl_801A3220.unk_40 = 0;
    lbl_801A3220.unk_44 = 0;
    lbl_801A3220.unk_48 = 0;
    lbl_801A3220.unk_4C = 0;
    if (lbl_801A6D48 != 0) {
        lbl_8006E1B0(&arg0->pos, &lbl_801A3220.unk_50);
        lbl_801A3220.unk_50.z = lbl_801A3220.unk_50.z - arg0->unk_14;
    } else {
        lbl_801A3220.unk_50 = lbl_8019F130__fzgx_offset_10;
    }
    lbl_8006D668(&lbl_801A3220.unk_50);
}
