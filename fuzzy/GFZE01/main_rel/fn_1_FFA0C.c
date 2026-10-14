/* Non-matching: best partial attempt (36.09% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern const f32 lbl_1_rodata_76A8[84];
extern u32 lbl_1_bss_38458;
extern s32 fn_1_54E34(void *, f32);
extern u32 fn_1_584AC(void);
extern void fn_1_1011CC(int, int);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(void *);
extern f32 lbl_8006D848(f32);
extern void lbl_8006DFC4(void *);
extern void *memset(void *, int, u32);
extern void lbl_8006DCA4(f32);
extern void lbl_8006D9D8(void *);
extern void lbl_8006D7B0(void);
extern void mathutil_mtxA_rotate_z(void);

/* fn_1_FFA0C: background/camera update driven by a per-object state block. */
void fn_1_FFA0C(void *arg) {
    u8 *obj = (u8 *)arg + 0x3C;
    const f32 *tbl = lbl_1_rodata_76A8;
    f32 scale;
    f32 len;
    f32 limit;
    u32 rnd;
    s32 count;

    count = *(s32 *)obj;
    if (count <= 0) {
        return;
    }

    scale = *(f32 *)(obj + 0x30);

    lbl_8006DCA4(scale);
    if (fn_1_54E34(obj + 4, scale) == 0) {
        return;
    }

    lbl_8006D9D8(obj + 4);
    lbl_8006D7B0();
    mathutil_mtxA_rotate_z();

    len = lbl_8006D0B4(1.0f);

    limit = tbl[34] + scale;
    if (len > limit) {
        lbl_8006DB74((u8 *)obj + 0x14);
        lbl_8006D848((len - scale) / len);
        lbl_8006DFC4((u8 *)obj + 0x14);
    }

    memset((u8 *)obj + 8, 0, 0x40);
    lbl_8006DB74(obj);

    *(f32 *)(obj + 8) = tbl[50] * scale;

    rnd = fn_1_584AC() & 0xFFFF;
    fn_1_1011CC((s32)rnd, 0xFF);
}
