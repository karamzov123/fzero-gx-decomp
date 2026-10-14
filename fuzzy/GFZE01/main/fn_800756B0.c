/* Non-matching: best partial attempt (95.34% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_8019F040[240];
extern s32 lbl_801A6D78;
extern s32 lbl_801A6D88[2];
extern u32 lbl_801A6D80;
extern s32 lbl_801A6D84;
extern u32 lbl_801A6D7C;
extern s32 lbl_801A6D48;
extern void GXLoadTexMtxImm(void *, u32, u32);
extern void fn_80075080(void *);
extern void fn_800736C0(int, void *);
extern void fn_800728A8(s32, s32, s32, s32);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006D668(void *);

struct Vec {
    u8 lab_pad[4]; f32 x,y,z; };
struct State {
    s8 a,b,c,d,e,f,pad[2];
    u32 v8,vc,v10,v14,v18,v1c,v20,v24,v28,v2c,v30;
    u16 v34,v36,v38,p3a;
    u32 v3c,v40,v44,v48,v4c;
    struct Vec v50;
};
struct Base {
    u8 pad0[0x20];
    f32 m20[12];
    f32 m50[3][12];
    s32 enabled[3];
    u8 pad_ec[0x14];
    struct Vec v100;
    u8 pad10c[0x2c];
    f32 identity[12];
    u8 pad168[0x4078];
    struct State state;
};
struct Arg { u32 flags; u32 flags4; struct Vec v8; f32 v14; };
struct Mat { u32 flags; u8 pad[8]; s32 vc; u8 pad10[0x30]; u32 v40; };

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_8019F040_fill_8019F040[8];
f32 lbl_8019F040_20[12];
f32 lbl_8019F040_50[3][12];
s32 lbl_8019F040_E0[3];
u32 lbl_8019F040_fill_8019F12C;
u32 lbl_8019F130_fill_8019F130[4];
struct Vec lbl_8019F130_10;
u32 lbl_8019F14C[3];
u32 lbl_8019F158_fill_8019F158[8];
f32 lbl_8019F158_20[12];
u32 lbl_8019F158_fill_8019F1A8[22];
u32 lbl_8019F200[4104];
struct State lbl_801A3220;
u32 lbl_801A3220_fill_801A327C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_8019F040_fill_8019F040;
    s = *(u8 *)&lbl_8019F040_20;
    s = *(u8 *)&lbl_8019F040_50;
    s = *(u8 *)&lbl_8019F040_E0;
    s = *(u8 *)&lbl_8019F040_fill_8019F12C;
    s = *(u8 *)&lbl_8019F130_fill_8019F130;
    s = *(u8 *)&lbl_8019F130_10;
    s = *(u8 *)&lbl_8019F14C;
    s = *(u8 *)&lbl_8019F158_fill_8019F158;
    s = *(u8 *)&lbl_8019F158_20;
    s = *(u8 *)&lbl_8019F158_fill_8019F1A8;
    s = *(u8 *)&lbl_8019F200;
    s = *(u8 *)&lbl_801A3220;
    s = *(u8 *)&lbl_801A3220_fill_801A327C;
}
#pragma section code_type ".text"

void fn_800756B0(struct Arg *arg0, struct Mat *arg1) {
    u32 color0;
    s32 mtx;
    s32 i;
    u32 color1;

    
    lbl_801A3220.a = 1;
    if (arg0->flags4 & 0x18) arg1 = (struct Mat *)((u8 *)arg1 + 0x20);
    if (lbl_801A6D78 != 0) GXLoadTexMtxImm(lbl_8019F040_20, 0x24, 0);
    else GXLoadTexMtxImm(lbl_8019F158_20, 0x24, 0);
    {
        f32 (*m50)[12] = lbl_8019F040_50;
        s32 *enabled = lbl_8019F040_E0;
        for (i = 0, mtx = 0x33; i < 3; i++, mtx += 3) {
            if (enabled[i] != 0) GXLoadTexMtxImm(m50[i], mtx, 0);
            else GXLoadTexMtxImm(lbl_8019F158_20, mtx, 0);
        }
    }
    fn_80075080(arg1);
    lbl_801A3220.v10 = arg1->vc;
    lbl_801A3220.c = 0;
    lbl_801A3220.v14 = 15;
    lbl_801A3220.v18 = 7;
    lbl_801A3220.d = -1;
    lbl_801A3220.e = -1;
    lbl_801A3220.f = -1;
    lbl_801A3220.v8 = 16;
    lbl_801A3220.vc = 16;
    if (lbl_801A6D88[0] != 0) {
        color0 = lbl_801A6D80;
        fn_800736C0(2, &color0);
    }
    if (lbl_801A6D84 != 0) {
        color1 = lbl_801A6D7C;
        fn_800736C0(3, &color1);
    }
    lbl_801A3220.v1c = 4;
    lbl_801A3220.v20 = 5;
    if (arg1->flags & 0x20) lbl_801A3220.v1c = arg1->v40 & 15;
    if (arg1->flags & 0x40) lbl_801A3220.v20 = (arg1->v40 >> 4) & 15;
    fn_800728A8(1, lbl_801A3220.v1c, lbl_801A3220.v20, 0);
    lbl_801A3220.b = -1;
    lbl_801A3220.v24 = -1;
    lbl_801A3220.v28 = -1;
    lbl_801A3220.v2c = -1;
    lbl_801A3220.v30 = -1;
    lbl_801A3220.v34 = -1;
    lbl_801A3220.v36 = -1;
    lbl_801A3220.v38 = -1;
    lbl_801A3220.v3c = 0;
    lbl_801A3220.v40 = 0;
    lbl_801A3220.v44 = 0;
    lbl_801A3220.v48 = 0;
    lbl_801A3220.v4c = 0;
    if (lbl_801A6D48 != 0) {
        lbl_8006E1B0(&arg0->v8, &lbl_801A3220.v50);
        lbl_801A3220.v50.z -= arg0->v14;
    } else {
        lbl_801A3220.v50 = lbl_8019F130_10;
    }
    lbl_8006D668(&lbl_801A3220.v50);
}
