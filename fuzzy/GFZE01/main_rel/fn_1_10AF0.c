/* Non-matching: best partial attempt (65.84% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct { u32 x, y, z; } Triple;
struct BSS {
    u8 pad_0[0x66C]; u8 unk_66C; u8 pad_66D[3];
    u32 unk_670, unk_674; u8 pad_678[8]; u32 unk_680, unk_684;
};
struct Data { u8 pad_0[0xCC]; s16 unk_CC; u8 pad_CE[0x72]; u32 unk_140, unk_144; };
struct Keys { u8 pad[0xA]; u16 unk_A; };
struct RNG { u32 unk_0; };
extern struct BSS lbl_1_bss_1148;
extern struct Data lbl_1_data_43B8;
extern struct Keys lbl_1_bss_9F8;
extern struct RNG lbl_801A63C0;
extern u8 lbl_1_rodata_4E0[];
extern u8 fn_1_40BB4(void);
extern void fn_1_862D4(int, Triple *);
extern void fn_1_8840(void);
extern s8 fn_1_86624(void);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D5F0(void *, void *, f32);
extern void lbl_8006D5A4(void *, void *, void *);
extern void live_camera_set_shake(s32, const f32 *);
extern void fn_1_10AF0(void *arg0) {
    struct BSS *mgr = &lbl_1_bss_1148;
    struct Data *data = &lbl_1_data_43B8;
    u8 *obj = (u8 *)arg0;
    u8 *vehicles;
    f32 *points;
    s32 i, j, best, changed, found, count;
    u32 n, seed, random;
    s16 max;
    Triple a, b, target;
    f32 bestdist, d, dx, dy, dz;
    f32 x, y, z, amount, t, factor, delta;
    f32 vals[3];
    s32 shake;
    u32 indices[40];
    u8 type;
    vehicles = (u8 *)mgr->unk_680 + (*(s16 *)(obj + 4) * 40);
    mgr->unk_66C = vehicles[0x24];
    type = obj[0];
    switch (type) {
    case 3:
        max = (s16)data->unk_140;
        if (fn_1_40BB4() == 0) {
            if ((lbl_1_bss_9F8.unk_A >> 1) & 1)
                *(s16 *)(obj + 0x14) += 1;
            if (lbl_1_bss_9F8.unk_A & 1)
                *(s16 *)(obj + 0x14) -= 1;
            i = max - 1;
            if (*(s16 *)(obj + 0x14) > i)
                *(s16 *)(obj + 0x14) = 0;
            if (*(s16 *)(obj + 0x14) < 0)
                *(s16 *)(obj + 0x14) = i;
        }
    case 1:
    case 2:
    case 4:
    case 5: {
        if (*(u16 *)(obj + 0x66) != 0) {
            *(u16 *)(obj + 0x66) -= data->unk_CC;
            if (*(u16 *)(obj + 0x66) == 0)
                *(u32 *)(obj + 0xC) &= 0xFFDFFFFF;
        }
        n = data->unk_140;
        fn_1_862D4(*(s16 *)(obj + 6), &a);
        count = data->unk_144;
        points = (f32 *)mgr->unk_684;
        fn_1_862D4(*(s16 *)(obj + 6), &b);
        dx = points[0] - ((f32 *)&b)[0];
        dy = points[1] - ((f32 *)&b)[1];
        dz = points[2] - ((f32 *)&b)[2];
        bestdist = (f32)(dx * dx) + dy * dy + dz * dz;
        best = 0;
        for (i = 1; i < count; i++) {
            f32 *p = (f32 *)(mgr->unk_684 + 12 + (i - 1) * 12);
            dx = p[0] - ((f32 *)&b)[0];
            dy = p[1] - ((f32 *)&b)[1];
            dz = p[2] - ((f32 *)&b)[2];
            d = (f32)(dx * dx) + dy * dy + dz * dz;
            if (bestdist >= d) {
                bestdist = d;
                best = i;
            }
        }
        changed = 0;
        if (mgr->unk_670 != best) {
            mgr->unk_670 = best;
            changed = 1;
        }
        if (changed) {
            found = 0;
            j = 0;
            count = 0;
            for (i = 0; i < (s32)n; i++) {
                if ((u32)best == *(u32 *)((u8 *)mgr->unk_680 + i * 40)) {
                    indices[count++] = i;
                    found = 1;
                }
            }
            if (!found) {
                mgr->unk_674 = 0;
            } else {
                seed = lbl_801A63C0.unk_0;
                random = seed * 0x676A4B6B + 0x33CB;
                j = (random >> 16) & 0x7FFF;
                lbl_801A63C0.unk_0 = random;
                mgr->unk_674 = indices[j % count];
            }
            *(u32 *)(obj + 0x18) = 1;
        }
        if ((u16)mgr->unk_674 != *(s16 *)(obj + 4) &&
            !(*(u32 *)(obj + 0xC) & 0x00080000))
            *(s16 *)(obj + 0x14) = (u16)mgr->unk_674;
    }
    }
    fn_1_862D4(*(s16 *)(obj + 6), &target);
    if (vehicles[0x24] == 0) {
        fn_1_8840();
        *(u32 *)(obj + 0x4C) = target.x;
        *(u32 *)(obj + 0x50) = target.y;
        *(u32 *)(obj + 0x54) = target.z;
        dx = *(f32 *)(obj + 0x1C) - *(f32 *)&target.x;
        dy = *(f32 *)(obj + 0x20) - *(f32 *)&target.y;
        dz = *(f32 *)(obj + 0x24) - *(f32 *)&target.z;
        d = (f32)(dx * dx) + dy * dy + dz * dz;
        if (d > *(f32 *)((u8 *)mgr + 0x6A0)) {
            f32 t = *(f32 *)(obj + 0x58);
            t += (65.0 - t) * 0.02 * (f32)(s16)data->unk_CC;
            *(f32 *)(obj + 0x58) = t;
        } else if (d != *(f32 *)((u8 *)mgr + 0x6A0)) {
            f32 t = *(f32 *)(obj + 0x58);
            t += (10.0 - t) * 0.05 * (f32)(s16)data->unk_CC;
            *(f32 *)(obj + 0x58) = t;
        }
        *(f32 *)((u8 *)mgr + 0x6A0) = d;
    } else if (vehicles[0x24] == 3) {
        f31:
        for (i = 0; i < fn_1_86624(); i++) {
            Triple t;
            fn_1_862D4(i, &t);
            dx = *(f32 *)(obj + 0x1C) - *(f32 *)&t.x;
            dy = *(f32 *)(obj + 0x20) - *(f32 *)&t.y;
            dz = *(f32 *)(obj + 0x24) - *(f32 *)&t.z;
            d = lbl_8006D0B4((f32)(dx * dx) + dy * dy + dz * dz);
            if (d < 7.0f) {
                seed = lbl_801A63C0.unk_0;
                random = seed * 0x676A4B6B + 0x33CB;
                lbl_801A63C0.unk_0 = random;
                vals[0] = ((f32)((random >> 16) & 0x7FFF) / 32767.0f);
                random = random * 0x676A4B6B + 0x33CB;
                lbl_801A63C0.unk_0 = random;
                vals[1] = ((f32)((random >> 16) & 0x7FFF) / 32767.0f);
                random = random * 0x676A4B6B + 0x33CB;
                lbl_801A63C0.unk_0 = random;
                vals[2] = ((f32)((random >> 16) & 0x7FFF) / 32767.0f);
                amount = 0.875f + -0.125f * d;
                if (amount < 0.0f) amount = 0.0f;
                else if (amount > 0.5f) amount = 0.5f;
                lbl_8006D5F0(vals, vals, amount);
                seed = lbl_801A63C0.unk_0;
                random = seed * 0x676A4B6B + 0x33CB;
                lbl_801A63C0.unk_0 = random;
                shake = (s32)(30.0f * (1.0f + (f32)((random >> 16) & 0x7FFF) / 32767.0f));
                live_camera_set_shake(shake, vals);
            }
        }
    } else if (vehicles[0x24] == 1 || vehicles[0x24] == 2 || vehicles[0x24] == 4 || vehicles[0x24] == 5) {
        fn_1_8840();
        if (vehicles[0x24] == 4) {
            f32 *c = (f32 *)((u8 *)mgr + 0x688);
            c[2] -= 1.0f;
            if (c[2] < c[3] * 0.5f) c[4] -= c[5];
            else c[4] += c[5];
            c[0] += c[4];
            lbl_8006D5A4(vehicles + 4, vehicles + 16, obj + 0x1C);
        } else {
            f32 factor = 0.01f * (f32)(s16)data->unk_CC;
            f32 delta = ((f32 *)(vehicles + 16))[0] - *(f32 *)(obj + 0x1C);
            *(f32 *)(obj + 0x1C) += factor * delta;
            delta = ((f32 *)(vehicles + 16))[1] - *(f32 *)(obj + 0x20);
            *(f32 *)(obj + 0x20) += factor * delta;
            delta = ((f32 *)(vehicles + 16))[2] - *(f32 *)(obj + 0x24);
            *(f32 *)(obj + 0x24) += factor * delta;
        }
        *(u32 *)(obj + 0x4C) = target.x;
        *(u32 *)(obj + 0x50) = target.y;
        *(u32 *)(obj + 0x54) = target.z;
        dx = *(f32 *)(obj + 0x1C) - *(f32 *)&target.x;
        dy = *(f32 *)(obj + 0x20) - *(f32 *)&target.y;
        dz = *(f32 *)(obj + 0x24) - *(f32 *)&target.z;
        d = (f32)(dx * dx) + dy * dy + dz * dz;
        if (d < *(f32 *)((u8 *)mgr + 0x6A4)) d = *(f32 *)((u8 *)mgr + 0x6A4);
        *(f32 *)((u8 *)mgr + 0x6A4) = d;
        if (vehicles[0x24] != 5) {
            if (vehicles[0x24] == 1) {
                f32 t = *(f32 *)(obj + 0x58);
                t += (4.0f - t) * 0.05f * (f32)(s16)data->unk_CC;
                *(f32 *)(obj + 0x58) = t;
                if (t <= 4.0f) *(f32 *)(obj + 0x58) = 4.0f;
            } else if (d > *(f32 *)((u8 *)mgr + 0x6A4)) {
                f32 t = *(f32 *)(obj + 0x58);
                t += (65.0f - t) * 0.05f * (f32)(s16)data->unk_CC;
                *(f32 *)(obj + 0x58) = t;
            } else {
                f32 t = *(f32 *)(obj + 0x58);
                t += (10.0f - t) * 0.05f * (f32)(s16)data->unk_CC;
                *(f32 *)(obj + 0x58) = t;
            }
        }
    }
}
