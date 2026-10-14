/* Non-matching: best partial attempt (66.49% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

#define GX_FIFO_ADDRESS 0xCC008000
#define GXWGFifo (*(volatile f32 *)GX_FIFO_ADDRESS)

extern u8 lbl_80178118[648];
extern const f32 lbl_801A7130;
extern const f32 lbl_801A7134;
extern const f32 lbl_801A7138;
extern const f32 lbl_801A713C;
extern const f32 lbl_801A7140;
extern const f64 lbl_801A7148;
extern const f64 lbl_801A7150;
extern void fn_80032EB8(u32);
extern void GXGetVtxAttrFmtv(u32, void *);
extern void GXClearVtxDesc(void);
extern void GXSetVtxDesc(u32, u32);
extern void GXSetVtxAttrFmt(u32, u32, u32, u32, u8);
extern f32 fn_80088624(f32);
extern f32 fn_80088600(f32);
extern void fn_8003462C(u32, u32, u32);
extern void GXSetVtxDescv(void *);
extern void GXSetVtxAttrFmtv(u32, void *);

void fn_80037E30(u32 arg0) {
    f32 sn[105], cs[100];
    f32 negone = -lbl_801A7134;
    s32 i;
    u32 n = arg0;

    fn_80032EB8((u32)lbl_80178118);
    GXGetVtxAttrFmtv(3, lbl_80178118 + 0xd8);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(10, 1);
    GXSetVtxAttrFmt(3, 9, 1, 4, 0);
    GXSetVtxAttrFmt(3, 10, 0, 4, 0);

    for (i = 0; i <= (s32)n; i++) {
        f32 a = (lbl_801A7138 * (lbl_801A713C * (f32)i)) / (f32)n;
        sn[i] = fn_80088624(a);
        cs[i] = fn_80088600(a);
    }

    fn_8003462C(0x98, 3, (n + 1) << 1);
    if ((s32)n >= 0) {
        for (i = 0; i <= (s32)n; i++) {
            f32 x = sn[i], y = cs[i];
            GXWGFifo=x; GXWGFifo=y; GXWGFifo=negone;
            GXWGFifo=x; GXWGFifo=y; GXWGFifo=lbl_801A7130;
            GXWGFifo=x; GXWGFifo=y; GXWGFifo=lbl_801A7134;
            GXWGFifo=x; GXWGFifo=y; GXWGFifo=lbl_801A7130;
        }
    }

    fn_8003462C(0xa0, 3, n + 2);
    GXWGFifo=lbl_801A7130; GXWGFifo=lbl_801A7130; GXWGFifo=lbl_801A7134;
    GXWGFifo=lbl_801A7130; GXWGFifo=lbl_801A7130; GXWGFifo=lbl_801A7134;
    if ((s32)n >= 0) {
        for (i=0; i <= (s32)n; i++) {
            GXWGFifo=sn[i]; GXWGFifo=-cs[i]; GXWGFifo=lbl_801A7134;
            GXWGFifo=lbl_801A7130; GXWGFifo=lbl_801A7130; GXWGFifo=lbl_801A7134;
        }
    }

    fn_8003462C(0xa0, 3, n + 2);
    GXWGFifo=lbl_801A7130; GXWGFifo=lbl_801A7130; GXWGFifo=negone;
    GXWGFifo=lbl_801A7130; GXWGFifo=lbl_801A7130; GXWGFifo=lbl_801A7140;
    if ((s32)n >= 0) {
        for (i=0; i <= (s32)n; i++) {
            GXWGFifo=sn[i]; GXWGFifo=cs[i]; GXWGFifo=negone;
            GXWGFifo=lbl_801A7130; GXWGFifo=lbl_801A7130; GXWGFifo=lbl_801A7140;
        }
    }
    GXSetVtxDescv(lbl_80178118);
    GXSetVtxAttrFmtv(3, lbl_80178118 + 0xd8);
}
