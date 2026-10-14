/* Non-matching: best partial attempt (69.44% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/stcoli.h"

typedef struct {
    f32 x, y, z;
} Vec3;

struct Elem_224F8 {
    u8 pad_0[0xC];
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    u8 pad_12[0x2];
    f32 unk_14;
    f32 unk_18;
    u8 pad_1C[0x4];
    u32 unk_20;
};

extern s16 fn_1_7B054(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006D7DC(void *);
extern u32 mathutil_mtxA_rotate_z(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern void lbl_8006DF44(void);
extern void lbl_8006E1B0(void *, Vec3 *);
extern void lbl_8006DB30(void);

s32 fn_1_224F8(void *arg0, void *arg1, u32 *arg2) {
    s32 best = -1;
    s32 i, start, pos;
    f32 t, s, sx, sy;
    Vec3 v1, v2, delta, res;
    struct Elem_224F8 *e;

    if (fn_1_7B054() == -1) {
        return -1;
    }
    if (!lbl_1_bss_3BE0) {
        return -1;
    }
    start = __cntlzw(*arg2);
    i = start;
    lbl_8006DAEC();
    e = (struct Elem_224F8 *)((u8 *)lbl_1_bss_3BE0->unk_B0 + i * 0x24);
    while (i < (s32)lbl_1_bss_3BE0->unk_AC) {
        if (__rlwnm(*arg2, (u32)(i + 1), 31, 31) == 0) {
            continue;
        }
        lbl_8006D7DC(e);
        if (e->unk_10) {
            mathutil_mtxA_rotate_z(e->unk_10);
        }
        if (e->unk_E) {
            mathutil_mtxA_rotate_y(e->unk_E);
        }
        if (e->unk_C) {
            mathutil_mtxA_rotate_x(e->unk_C);
        }
        lbl_8006DF44();
        lbl_8006E1B0(arg0, &v1);
        lbl_8006E1B0(arg1, &v2);
        delta.z = v1.z - v2.z;
        t = v1.z / delta.z;
        s = -t;
        sy = 0.5f * (10.0f * e->unk_18);
        sx = 0.5f * (10.0f * e->unk_14);
        v1.y /= sy;
        v2.y /= sy;
        v1.x /= sx;
        v2.x /= sx;
        psvec_sub_scale_add(&v1, &v2, s, &delta, &res);
        if (e->unk_20) {
            if (res.x * res.x + res.y * res.y <= 1.0f) {
                best = i;
                break;
            }
        }
        else if (-1.0f <= res.x && res.x <= 1.0f && -1.0f <= res.y && res.y <= 1.0f) {
            best = i;
            break;
        }
        i++;
        e++;
    }
    lbl_8006DB30();
    if (best >= 0) {
        *arg2 &= 0xFFFFFFFFu >> (best + 1);
    }
    return best;
}
