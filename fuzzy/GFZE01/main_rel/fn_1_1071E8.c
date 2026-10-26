/* Non-matching: best partial attempt (59.80% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct {
    u8 pad00[0x30];
    f32 field30, field34;
    u8 pad38[4];
    f32 field3c;
    f32 field40;
    u8 pad44[0x24];
    f32 field68, field6c;
    u8 pad70[0xc];
    u32 flags;
    u32 field80;
    u32 field84;
    u32 field88;
} BgPart;

struct Pool { u8 pad[0x68]; f64 d68; };
extern struct Pool lbl_1_rodata_7A48;
extern f32 lbl_1_bss_7AC88;
extern u8 lbl_1_bss_86EC7;
extern u32 lbl_1_bss_86EC0;
extern f32 fn_1_20258(BgPart *, f32 *);
extern void fn_1_214C4(void *, u32, f32);
extern void fn_1_17920(f32, u32);
extern void *lbl_8006DC6C(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_z(s32);
extern f32 mathutil_mtxA[12];

void fn_1_1071E8(u8 *arg0, u32 arg1, void *arg2, void *arg3, f32 *arg4) {
    f32 loc8;
    f32 locC[13];
    s32 n, angle;
    u32 flags;
    s32 index;
    s32 step;
    f32 t, theta, x, y, z;
    BgPart *p;
    f32 *m = mathutil_mtxA;

    fn_1_214C4(&loc8, 0, (f32)arg1 * lbl_1_bss_7AC88);
    fn_1_17920(loc8, 0);
    if (*(u32 *)(arg0 + 0x1c) == 1)
        n = 0;
    else
        n = (lbl_1_bss_86EC7 % (*(s32 *)(arg0 + 0x1c) - 1)) + 1;
    p = (BgPart *)(arg0 + (n << 7) + 0x400);
    t = fn_1_20258(p, locC);
    index = arg1 + ((u32)lbl_1_bss_86EC7 << 9);
    step = (s8)*(u8 *)(lbl_1_bss_86EC0 + index);
    if (step == -128) {
        u8 *q = (u8 *)(lbl_1_bss_86EC0 + index);
        while (arg1 != 0 && (s8)*q == -128) {
            --q;
            --arg1;
        }
        step = (s8)*q;
    }
    if (locC[0] == 0.0f) {
        lbl_8006DC6C(p);
        m[3] = p->field30;
        m[7] = p->field34;
        m[11] = p->field3c;
    } else {
        lbl_8006DBAC(p);
    }
    flags = p->flags;
    if (flags & 1)
        locC[0] = -locC[0];

    if (flags & 0x220) {
        f32 q = (f32)(s8)*(u8 *)(lbl_1_bss_86EC0 + index) * (1.0f / 256.0f) * t;
        m[3] = m[0] * q + m[3];
        m[7] = m[4] * q + m[7];
        m[11] = m[8] * q + m[11];
        theta = 0.0f;
    } else if (flags & 0x180) {
        if (locC[0] != 1.0f)
            lbl_8006E15C(locC[0], 1.0f, 1.0f);
        angle = (s32)((f64)(s8)*(u8 *)(lbl_1_bss_86EC0 + index) * (1.0 / 128.0) *
                      p->field6c * 32768.0);
        mathutil_mtxA_rotate_z(angle);
        theta = -(p->field68 * 0.5f);
        m[3] = m[1] * theta + m[3];
        m[7] = m[5] * theta + m[7];
        m[11] = m[9] * theta + m[11];
        theta = p->field68 * 0.5f;
    } else {
        f32 speed = p->field3c / t;
        f32 wrap = (f32)(s8)*(u8 *)(lbl_1_bss_86EC0 + index) * (1.0 / 128.0);
        f32 half;
        f32 limit;
        f32 remain;
        if (wrap > 0.0f) half = 1.0f;
        else half = -1.0f;
        if (locC[0] != 1.0f)
            lbl_8006E15C(locC[0], 1.0f, 1.0f);
        if (__fabsf(wrap) < speed) {
            lbl_8006E0B4(wrap * t, -p->field40, 0.0f);
        } else if (__fabsf(wrap) > 0.5f - speed) {
            lbl_8006E0B4((0.5f - wrap) * t, p->field40, 0.0f);
        } else {
            remain = (wrap - speed * half) / (0.5f - speed);
            m[3] = m[0] * (0.5f * speed * p->field3c) + m[3];
            m[7] = m[4] * (0.5f * speed * p->field3c) + m[7];
            m[11] = m[8] * (0.5f * speed * p->field3c) + m[11];
            angle = (s32)(32768.0f * remain);
            mathutil_mtxA_rotate_z(angle);
            theta = -p->field40 * 0.5f;
            m[3] = m[1] * theta + m[3];
            m[7] = m[5] * theta + m[7];
            m[11] = m[9] * theta + m[11];
        }
        theta = p->field40 * 0.5f;
    }

    if (arg4 != 0)
        *arg4 = theta;
    if (arg3 != 0) {
        if ((flags & 0x140) || (((flags & 0x80000001) == 0x80000001) && __fabsf(locC[0]) > 0.5f)) {
            f32 s = (flags & 1) ? -1.0f : 1.0f;
            ((f32 *)arg3)[0] = m[1] * s;
            ((f32 *)arg3)[1] = m[5] * s;
            ((f32 *)arg3)[2] = m[9] * s;
        } else {
            ((u32 *)arg3)[0] = *(u32 *)((u8 *)p + 0x5c);
            ((u32 *)arg3)[1] = *(u32 *)((u8 *)p + 0x60);
            ((u32 *)arg3)[2] = *(u32 *)((u8 *)p + 0x64);
        }
    }
    psvec_set(arg2, m[3], m[7], m[11]);
    return;
}
