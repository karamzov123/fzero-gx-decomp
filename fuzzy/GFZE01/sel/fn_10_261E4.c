/* Non-matching: best partial attempt (73.36% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/sel/globals.h"
#include "rel/sel/name_entry.h"

extern u8 lbl_10_data_6A48[32];
extern f32 lbl_10_rodata_1D70[7];
extern u32 lbl_801A66B4;

extern u32 fn_800081C8(void *, void *);
extern void fn_1_49410(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4D494(void);
extern void fn_1_49514(u32 *);
extern void fn_1_49528(u32 *);
extern u32 fn_1_4D4C8(void *, f32, f32);
extern void fn_1_4AE0C(const char *, ...);

typedef struct {
    u8 pad0[0x58];
    f32 f58;
    f32 f5c;
    f32 f60;
    u8 pad1[0x14];
    u32 w[8];
    f32 f98;
    f32 f9c;
    f32 fa0;
    f32 fa4;
} fn_10_261E4_Pool;

typedef struct {
    u8 pad[0x128];
    u32 tab1[0x11];
    u32 tab2[0x6];
    char buf[0x100];
} fn_10_261E4_Dlg;

void fn_10_261E4(u32 p0, u32 p1) {
    fn_10_261E4_Dlg *dlg = (fn_10_261E4_Dlg *)&lbl_10_data_6A48;
    const fn_10_261E4_Pool *pl = (const fn_10_261E4_Pool *)&lbl_10_rodata_1D70;
    volatile u32 r; // fzgx-allow: retail holds this result in a frame slot
    u32 vB;
    u32 vA;

    vA = pl->w[1];
    vB = pl->w[0];
    r = fn_800081C8(&vB, &vA);
    fn_1_49410(pl->f98);
    fn_1_4955C(pl->f58, pl->f58);
    fn_1_4954C(pl->f5c);
    fn_1_495C8(9);
    fn_1_495B0(0x80000000);
    fn_1_49590(pl->f60);
    fn_1_496FC(pl->f9c, (f32)(s32)p0);
    fn_1_495C8(10);

    if ((p1 & 0xFF) == 0) {
        u32 a = pl->w[2];
        u32 b;
        u32 *t = dlg->tab1;

        fn_1_49514(&a);
        fn_1_4AE0C(dlg->buf, t[lbl_801A66B4], &lbl_801A66B4);
        b = r;
        fn_1_4D4C8(&b, pl->f5c, pl->fa0);
    } else {
        u32 a = pl->w[3];
        u32 b = pl->w[4];
        u32 *t = dlg->tab1;

        fn_1_49514(&a);
        fn_1_49528(&b);
        fn_1_4AE0C(dlg->buf, t[lbl_801A66B4], &lbl_801A66B4);
    }

    fn_1_496FC(pl->fa4, (f32)(s32)p0);
    fn_1_495C8(8);

    if (!(p1 & 0xFF)) {
        u32 a = pl->w[5];
        u32 b = pl->w[6];
        u32 *t = dlg->tab2;

        fn_1_49514(&a);
        fn_1_49528(&b);
        fn_1_4AE0C(dlg->buf, t[lbl_801A66B4], &lbl_801A66B4);
    } else {
        u32 a;
        u32 b;
        u32 *t = dlg->tab2;

        fn_1_4D494();
        a = pl->w[7];
        fn_1_49514(&a);
        fn_1_4AE0C(dlg->buf, t[lbl_801A66B4], &lbl_801A66B4);
        b = r;
        fn_1_4D4C8(&b, pl->f5c, pl->fa0);
    }
}
