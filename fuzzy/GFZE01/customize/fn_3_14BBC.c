/* Non-matching: best partial attempt (20.88% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_3_14BBC_color;

typedef struct {
    u16 r : 5;
    u16 g : 5;
    u16 b : 5;
    u16 a : 1;
} fn_3_14BBC_op;

typedef struct {
    u16 r : 4;
    u16 g : 4;
    u16 b : 4;
    u16 a : 3;
} fn_3_14BBC_bl;

typedef union {
    u16 value;
    fn_3_14BBC_op op;
    fn_3_14BBC_bl bl;
} fn_3_14BBC_px;

extern u32 lbl_3_bss_A23E0;
extern u16 lbl_3_bss_A23D8;
extern void *memset(void *, int, u32);

void fn_3_14BBC(u8 *buf, s16 px, s16 py, s16 n, u32 *arg4) {
    fn_3_14BBC_color *color = (fn_3_14BBC_color *)arg4;
    s16 i;
    s16 off;

    for (i = 0; i < n; i++) {
        if (lbl_3_bss_A23E0 == 5) {
            off = (s16)(px / 4 + (s16)((u16)lbl_3_bss_A23D8 / 4) * (py / 4));
            off = (s16)(off * 32 + (px % 4 + (py % 4) * 4) * 2);
            {
                fn_3_14BBC_px v;

                if (color->a >= 224) {
                    v.op.r = color->r;
                    v.op.g = color->g;
                    v.op.b = color->b;
                    v.op.a = 1;
                } else {
                    v.bl.r = color->r;
                    v.bl.g = color->g;
                    v.bl.b = color->b;
                    v.bl.a = color->a;
                }
                buf[off] = v.value >> 8;
                buf[off + 1] = v.value;
            }
        } else if (lbl_3_bss_A23E0 == 4) {
            off = (s16)((px / 4 + py / 4) * 2 + (px / 4 + (s16)((u16)lbl_3_bss_A23D8 / 4) * (py / 4)) * 32);
            {
                fn_3_14BBC_px v;

                v.op.r = color->r;
                v.op.g = color->g;
                v.op.b = color->b;
                v.op.a = 0;
                memset(&buf[off], v.value >> 8, 1);
                memset(&buf[off + 1], v.value, 1);
            }
        }
        px++;
    }
}
