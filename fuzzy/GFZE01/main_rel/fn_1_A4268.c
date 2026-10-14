/* Non-matching: best partial attempt (81.17% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sound.h"

extern u32 fn_1_58C4(void);
extern u32 fn_1_864E8(u32);
extern u8 *fn_1_86254(u32);
extern f32 fn_1_8652C(u32);
extern s32 fn_1_3F864(void);
extern s32 fn_80063094(s32, u32, s32);
extern s32 fn_80067344(u32, u32, u32, u32);
extern s32 fn_80067898(u32);
extern const f32 lbl_1_rodata_454C;
extern const f32 lbl_1_rodata_4474;
extern const f32 lbl_1_rodata_458C;
extern const f32 lbl_1_rodata_4588;
extern const f32 lbl_1_rodata_4590;
extern const f32 lbl_1_rodata_4564;

void fn_1_A4268(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u8 *base;
    u8 *x;
    u8 *e;
    u8 *p;
    u8 *q;
    u8 a;
    u8 b;
    u32 n;
    u8 i1;
    u8 i2;
    u32 j;
    u32 k;
    u8 c;
    u32 m;
    u32 f;

    base = (u8 *)&lbl_1_bss_6EA98;
    a = 0;
    b = 0;
    n = fn_1_58C4();
    if (base[0x2E] == 0) {
        return;
    }
    i1 = 0;
    i2 = 0;
    if (n > 1) {
        p = base + 0x74C;
        q = p;
        for (j = 0; j < n; j++, q += 0x14) {
            if (q[1] != 0xFF && (fn_1_864E8(q[1]) & 2)) {
                i1 = j;
                break;
            }
        }
        for (k = 0; k < n; k++, p += 0x14) {
            if (p[1] != 0xFF) {
                u8 t = 0;
                u8 *y = fn_1_86254(p[1]);
                if (*(u32 *)(y + 0x244) & 4) t = 1;
                if (*(u32 *)(y + 0x2A0) & 4) t++;
                if (*(u32 *)(y + 0x2FC) & 4) t++;
                if (*(u32 *)(y + 0x358) & 4) t++;
                if (t != 0) {
                    i2 = k;
                    break;
                }
            }
        }
    }
    if (i1 == arg2) a = 1;
    if (i2 == arg2) b = 1;
    x = fn_1_86254(arg0);
    if (a != 0) {
        if (fn_1_8652C(arg0) > lbl_1_rodata_454C && fn_1_3F864() != 0 && (arg1 & 0x880) == 0 && (arg1 & 2)) {
            f32 v = *(f32 *)(x + 0x180);
            f32 r;
            u8 t;
            if (v < lbl_1_rodata_4474) {
                r = lbl_1_rodata_4588 - (f32)(lbl_1_rodata_458C * v);
            } else {
                r = lbl_1_rodata_4588 + (f32)(lbl_1_rodata_4590 * v);
            }
            t = (u8)r;
            if (base[0x2E] != 0) fn_80063094(6, 0xA6000000, t);
            if (base[0x2E] != 0) fn_80063094(6, 0xA5100000, arg3 & 0xFF);
            base[0x74C + arg2 * 0x14] |= 8;
        }
        f = *(u32 *)(base + 0x830 + arg2 * 4);
        if (!(f & 2) || ((arg1 & 0x80) && !(f & 0x80)) || ((arg1 & 0x800) && !(f & 0x800))) {
            u8 *pp = base + 0x74C;
            u32 o = arg2 * 0x14;
            if (pp[o] & 8) {
                if (base[0x2E] != 0) fn_80063094(6, 0xA6000000, 0);
                if (base[0x2E] != 0) fn_80063094(6, 0xA5100000, 0);
                pp[o] &= ~8;
            }
        }
    }
    m = arg1 & 0x80;
    if (m) {
        return;
    }
    c = 0;
    if (*(u32 *)(x + 0x244) & 4) c = 1;
    if (*(u32 *)(x + 0x2A0) & 4) c++;
    if (*(u32 *)(x + 0x2FC) & 4) c++;
    if (*(u32 *)(x + 0x358) & 4) c++;
    if (c != 0) {
        u8 tg = (u8)(lbl_1_rodata_4564 * *(f32 *)(base + 0x90C + arg0 * 4));
        u8 cur;
        e = base + 0x74C + arg2 * 0x14 + 3;
        cur = *e;
        if (cur < tg) cur++;
        else if (cur > tg) cur--;
        *e = (cur <= 127) ? cur : 127;
        if (base[0x79C + arg2] == 0) {
            fn_80067344(1, 0x10, 0xB0270000, e[-1]);
            if (base[0x740] == 0 && *(u32 *)(base + 0x744) <= 0x2D) {
                fn_80067898(0xA9092900);
            }
        }
        base[0x79C + arg2] = c;
    } else {
        s8 v = 0;
        e = base + 0x74C + arg2 * 0x14 + 3;
        *e = 0;
        if (v > 0) v--;
        *e = v;
    }
    if (b == 0) {
        return;
    }
    if (c != 0) {
        s32 t = (arg3 & 0xFF) + 0x32;
        u8 val;
        u8 *pp;
        u32 o;
        if (t < 1) t = 1;
        else if (t > 0x7F) t = 0x7F;
        val = t;
        o = arg2 * 0x14;
        pp = base + 0x74C;
        if (m != 0 && (pp[o] & 0x10)) {
            if (base[0x2E] != 0) fn_80063094(7, 0xA6000000, 0);
            if (base[0x2E] != 0) fn_80063094(7, 0xA5100000, 0);
            pp[o] &= ~0x10;
        } else {
            if (base[0x2E] != 0) fn_80063094(7, 0xA6000000, (base + 0x74C + o)[3]);
            if (base[0x2E] != 0) fn_80063094(7, 0xA5100000, val);
            pp[o] |= 0x10;
        }
    } else {
        u8 *pp = base + 0x74C;
        u32 o = arg2 * 0x14;
        if (pp[o] & 0x10) {
            if (base[0x2E] != 0) fn_80063094(7, 0xA6000000, 0);
            if (base[0x2E] != 0) fn_80063094(7, 0xA5100000, 0);
            pp[o] &= ~0x10;
        }
    }
}
