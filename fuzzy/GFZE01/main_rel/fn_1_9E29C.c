/* Non-matching: best partial attempt (97.03% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/background.h"

extern f32 lbl_1_rodata_42C0[4];
extern void fn_80038BFC(f32 *);
extern void fn_80038F10(f32 *);
typedef struct { f32 x, y, z; } Point9E29C;
typedef struct { s16 x,y; u32 status; u8 value; } Entry9E29C;

static inline f32 fn_1_9E29C_operand(f32 left, f32 right) { return left + right; }
static inline f32 fn_1_9E29C_operand_(f32 left, f32 right) { left += right; return left; }
static inline f32 fn_1_9E29C_operand__(f32 left, f32 right) { left += right; return left; }
#pragma opt_lifetimes off
void fn_1_9E29C(s32 count, Point9E29C *src, Entry9E29C *dst) {
    f32 px;
    s32 i;
    f32 zero;
    f32 dx;
    f32 dy;
    f32 cx;
    f32 cy;
    f32 *pool = (f32 *)&lbl_1_rodata_42C0;
    f32 xmax;
    Point9E29C point;
    f32 ymax;
    f32 proj[6];
    f32 view[6];
    fn_80038BFC(proj);
    fn_80038F10(view);
    cx = view[0];
    cx += (f32)((0.5f) * view[2]);
    cy = view[1] + (f32)((0.5f) * view[3]);
    xmax = ((((view[0])) + ((view[2])))) - (1.0f);
    ymax = view[1] + view[3] - (1.0f);
    dx = xmax - cx;
    dy = ymax - cy;
    zero = (0.0f);
    for (i=0; i<count; i++) {
        point = src[i];
        dst[i].status = 0x01000000;
        if (point.z < zero) {
            f32 inv = (1.0f) / point.z;
            f32 py = (f32)(point.y * proj[3]);
            px = (f32)(point.x * proj[1]);
            px = fn_1_9E29C_operand((proj[2]), ((f32)(inv * px)));
            py = proj[4] + (f32)(inv * py);
            point.x = view[0] + (f32)(view[2] * ((1.0f) - (f32)((0.5f) * (fn_1_9E29C_operand_(((1.0f)), (px))))));
            point.y = view[1] + (f32)(view[3] * (f32)((0.5f) * (fn_1_9E29C_operand__(((1.0f)), (py)))));
            if (point.x < view[0]) {
                f32 ratio = (view[0] - cx) / (point.x - cx);
                point.x = view[0];
                point.y = cy + (f32)((((point.y - cy)) * (ratio)));
            } else if (point.x > xmax) {
                f32 ratio = dx / (point.x - cx);
                point.x = xmax;
                point.y = cy + (f32)(ratio * (point.y - cy));
            }
            if (point.y < view[1]) {
                f32 ratio = (view[1] - cy) / (point.y - cy);
                point.y = ((1)[view]);
                point.x = cx + (f32)(ratio * (point.x - cx));
            } else if (point.y > ymax) {
                f32 ratio = dy / (point.y - cy);
                point.y = ymax;
                point.x = cx + (f32)(ratio * (point.x - cx));
            }
            dst[i].x = (s32)point.x;
            dst[i].y = (s32)point.y;
            dst[i].status = 0;
        }
    }
}
#pragma opt_lifetimes reset

