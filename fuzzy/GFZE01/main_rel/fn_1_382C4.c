/* Non-matching: best partial attempt (86.21% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/game.h"

typedef struct Sig_ADXT_Stop_ADXTHandle Sig_ADXT_Stop_ADXTHandle;

struct fn_1_382C4_V {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u8 unk_8;
};

struct fn_1_382C4_S {
    u8 pad_0[0x30];
    u32 unk_30;
    u8 pad_34[0x14F8 - 0x34];
    u32 unk_14F8;
    u8 pad_14FC[4];
    u32 unk_1500;
    s8 unk_1504;
};
struct fn_1_382C4_T {
    u8 pad_0[0x1F88];
    u32 unk_1F88;
    u8 pad_1F8C[0x20A4 - 0x1F8C];
    u32 unk_20A4;
    u8 pad_20A8[0x20CC - 0x20A8];
    u32 unk_20CC;
    u8 pad_20D0[0x2278 - 0x20D0];
    u32 unk_2278;
    u8 pad_227C[0x3028 - 0x227C];
    u32 unk_3028;
    u8 pad_302C[0x306C - 0x302C];
    u32 unk_306C;
};

extern f32 lbl_1_rodata_BDC[2];
extern void fn_1_A8F78(void);
extern void *fn_1_3F1F8(void);
extern void fn_8006CE1C(f32);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_59290(void);
extern void fn_1_87074(void);
extern void fn_1_98590(void);
extern void *fn_1_435C(void *);
extern void fn_1_4310(u32);
extern void fn_1_D0790(void);
extern void *fn_1_86254(int);
extern s8 fn_1_86624(void);
extern void fn_1_5370(s8, s32);
extern void fn_1_3F75C(void);
extern u32 fn_1_4706C(void);
extern void fn_1_46A60(void);
extern void fn_1_47E54(s32);
extern void fn_1_41104(void *);
extern void fn_1_47F74(s16);
extern s16 fn_1_402A4(u32);
extern void fn_1_411A4(u32);
extern void fn_1_12F28C(void *, void **, void *, u8 *);
extern void fn_1_159478(int, int, int);
extern u32 fn_1_3F5F8(void);
extern u32 fn_1_A1588(Sig_ADXT_Stop_ADXTHandle *, u32);
extern void fn_1_A0C68(void);
extern u32 fn_80008E84(u32);
extern u8 lbl_1_bss_8B5F0;
extern u8 lbl_1_bss_8B5F1;

void fn_1_382C4(void) {
    struct fn_1_382C4_S *p = (struct fn_1_382C4_S *)&lbl_1_bss_3C00;
    struct fn_1_382C4_T *q = (struct fn_1_382C4_T *)((u8 *)p + 0x20000);
    u8 *w;
    u8 *bp;
    s32 v = 0;
    s16 i;
    s32 t;
    u32 f;

    fn_1_A8F78();
    w = (u8 *)fn_1_3F1F8();
    bp = &((struct fn_1_382C4_V *)((u8 *)w + 0x30))->unk_6;
    *bp = (u8)(u32)w;
    fn_8006CE1C(lbl_1_rodata_BDC[0]);
    fn_1_4A00(1, 30, (void *)p->unk_1500);
    fn_1_59290();
    fn_1_87074();
    fn_1_98590();
    q->unk_3028 = 0;
    fn_1_435C((void *)q->unk_1F88);
    fn_1_4310(0xBFFFFEu);
    fn_1_435C((void *)q->unk_20A4);
    fn_1_4310(0xBFFFFFF6u);
    fn_1_D0790();
    f = p->unk_30 & 0xFFFF87FFu;
    p->unk_30 = f;
    p->unk_1504 = -1;
    q->unk_2278 = v;
    p->unk_14F8 = v;
    p->unk_30 = f & 0xFFF7BF59u;
    if (((struct fn_1_382C4_V *)((u8 *)p + 0x30))->unk_5 == 1) {
        *(u8 *)((u8 *)fn_1_86254(0) + 0x475) = (u8)v;
        v = -1;
        for (i = 1; i < fn_1_86624(); i++) {
            *(u8 *)((u8 *)fn_1_86254(i) + 0x475) = (u8)v;
        }
    }
    fn_1_5370(3, 0);
    fn_1_3F75C();
    fn_1_4706C();
    fn_1_46A60();
    fn_1_47E54(0x9A);
    fn_1_47E54(0x9B);
    fn_1_47E54(0xA1);
    fn_1_41104((void *)1);
    fn_1_3F75C();
    t = (s32)fn_80008E84(q->unk_20CC);
    fn_1_47F74(0x9A);
    if (((struct fn_1_382C4_V *)((u8 *)p + 0x30))->unk_8 == 1) {
        fn_1_47F74(0x9B);
    } else {
        fn_1_47F74(0x9D);
    }
    fn_1_47F74(0xA1);
    fn_1_47F74(fn_1_402A4(*bp));
    fn_1_411A4(1);
    fn_1_12F28C((void *)q->unk_20A4, (void **)&q->unk_306C, (void *)7, bp);
    fn_80008E84(t);
    fn_1_159478(2, 0, 1);
    fn_1_4310(0xFFFFFF77u);
    fn_1_3F5F8();
    fn_1_A1588((Sig_ADXT_Stop_ADXTHandle *)lbl_1_bss_6EAD0.unk_0->unk_0, 0x2D);
    fn_1_A0C68();
    lbl_1_bss_8B5F0 = 0;
    lbl_1_bss_8B5F1 = 0;
}
