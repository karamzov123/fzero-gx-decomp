/* Non-matching: best partial attempt (78.19% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_8019F040[240];
extern u32 lbl_801A6D78;
extern u32 lbl_801A6D88[2];
extern u32 lbl_801A6D80;
extern u32 lbl_801A6D84;
extern u32 lbl_801A6D7C;
extern u32 lbl_801A6D48;
extern void GXLoadTexMtxImm(void *, u32, u32);
extern void fn_80075080(void *);
extern void fn_800736C0(int, void *);
extern void fn_800728A8(s32, s32, s32, s32);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006D668(void *);

struct Vec { f32 x,y,z; };
struct State {
    u8 a,b,c,d,e,f,pad[2];
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
struct Mat { u32 flags; u8 pad[8]; u32 vc; u8 pad10[0x30]; u32 v40; };

void fn_800756B0(struct Arg *arg0, struct Mat *arg1) {
    struct Base *base;
    s32 i;
    u32 mtx;
    struct State *s;
    u32 color0;
    u32 color1;
    s32 enabled;
    base = (struct Base *)&lbl_8019F040;
    base->state.a = 1;
    if (arg0->flags4 & 0x18) arg1 = (struct Mat *)((u8 *)arg1 + 0x20);
    if ((s32)lbl_801A6D78) GXLoadTexMtxImm(base->m20, 0x24, 0);
    else GXLoadTexMtxImm(base->identity, 0x24, 0);
    for (i = 0, mtx = 0x33; i < 3; i++, mtx += 3) {
        if (base->enabled[i]) GXLoadTexMtxImm(base->m50[i], mtx, 0);
        else GXLoadTexMtxImm(base->identity, mtx, 0);
    }
    fn_80075080(arg1);
    enabled = lbl_801A6D88[0];
    s = &base->state;
    s->v10 = arg1->vc;
    s->c = 0;
    s->v14 = 15;
    s->v18 = 7;
    s->d = -1;
    s->e = -1;
    s->f = -1;
    s->v8 = 16;
    s->vc = 16;
    if (lbl_801A6D88[0]) {
        color0 = lbl_801A6D80;
        fn_800736C0(2, &color0);
    }
    if (lbl_801A6D84) {
        color1 = lbl_801A6D7C;
        fn_800736C0(3, &color1);
    }
    s->v1c = 4;
    s->v20 = 5;
    if (arg1->flags & 0x20) s->v1c = arg1->v40 & 15;
    if (arg1->flags & 0x40) s->v20 = (arg1->v40 >> 4) & 15;
    fn_800728A8(1, s->v1c, s->v20, 0);
    s->b = -1;
    s->v24 = -1;
    s->v28 = -1;
    s->v2c = -1;
    s->v30 = -1;
    s->v34 = -1;
    s->v36 = -1;
    s->v38 = -1;
    s->v3c = 0;
    s->v40 = 0;
    s->v44 = 0;
    s->v48 = 0;
    s->v4c = 0;
    if (lbl_801A6D48) {
        lbl_8006E1B0(&arg0->v8, &s->v50);
        s->v50.z -= arg0->v14;
    } else {
        s->v50 = *(struct Vec *)(base + 0x100);
    }
    lbl_8006D668(&s->v50);
}
