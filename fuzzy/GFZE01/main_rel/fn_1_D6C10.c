/* Non-matching: best partial attempt (44.59% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/bg_lig.h"

struct Pool_D6C10 {
    u8 pad_0[0x28]; f32 f28; u8 pad_2c[4]; f64 f30;
    f32 f38; f32 f3c; f32 f40; f32 f44; f32 f48; u8 pad_4c[0x14];
    f64 f60; u8 pad_68[0x18]; f32 f80; u8 pad_84[0x1c];
    f32 fa0; u8 pad_a4[0x1c]; f64 fc0; u8 pad_c8[0x14];
    u32 fdc; u32 fe0; u32 fe4; f32 fe8; u8 pad_ec[4];
    f64 ff0; f64 ff8; f32 f100; f32 f104; f32 f108; u8 pad_10c[4];
    f64 f110; f32 f118; u8 pad_11c[4]; f64 f120; f64 f128;
};
struct Lbl_D6C10 { u32 value; };
extern struct Pool_D6C10 lbl_1_rodata_6360;
extern struct Lbl_D6C10 lbl_801A66A0;
extern f32 lbl_8006D0B4(f32);
extern s16 fn_1_58E3C(void *);
extern s32 fn_1_66B8(void *, f32);
extern u32 fn_1_584AC(void);
extern u8 fn_1_58C4(void);
extern void fn_1_681C(u32, u32 *);
extern void *memset(void *, int, u32);

void fn_1_D6C10(void *arg0, f32 arg1) {
    struct Pool_D6C10 *pool = &lbl_1_rodata_6360;
    u32 count, i;
    f32 best, x, y, z, a, b, c;
    f32 rate;
    u32 random;
    u32 rng;
    u32 scratch;
    struct { u16 a[174]; } loc;
    f32 pos[3];
    f32 intensity;
    f32 fade;
    f32 alpha;
    f32 color;
    f32 red;
    f32 green;
    f32 blue;
    f32 d;
    f64 val;
    if (lbl_801A66A0.value - (((u32)(((u64)(u32)(0xCCCD0000 - 13107) * (u64)lbl_801A66A0.value) >> 32) >> 4) * 20) == 0) {
        if (fn_1_66B8(arg0, pool->fe8 * arg1)) {
            count = fn_1_58C4();
            fn_1_681C(0, (u32 *)pos);
            x = *(f32 *)((u8 *)arg0);
            y = *(f32 *)((u8 *)arg0 + 4);
            z = *(f32 *)((u8 *)arg0 + 8);
            a = x - pos[0]; b = y - pos[1]; c = z - pos[2];
            best = lbl_8006D0B4((f32)(a*a) + b*b + c*c);
            for (i = 1; i < count; i++) {
                fn_1_681C(i & 0xff, (u32 *)pos);
                x = *(f32 *)((u8 *)arg0);
                y = *(f32 *)((u8 *)arg0 + 4);
                z = *(f32 *)((u8 *)arg0 + 8);
                d = lbl_8006D0B4((x-pos[0])*(x-pos[0]) + (y-pos[1])*(y-pos[1]) + (z-pos[2])*(z-pos[2]));
                if (best < d) {
                } else {
                    best = lbl_8006D0B4((x-pos[0])*(x-pos[0]) + (y-pos[1])*(y-pos[1]) + (z-pos[2])*(z-pos[2]));
                }
            }
            if (best <= pool->f80) {
                memset(&loc, 0, 232);
                loc.a[12] = 0;
                val = pool->ff0 * arg1;
                loc.a[10] = 13;
                loc.a[13] = 0xffff;
                intensity = pool->ff8 * arg1;
                fade = arg1;
                alpha = (f32)val;
                rng = lbl_1_bss_38458->unk_8;
                color = pool->f28;
                red = pool->f44;
                green = pool->f104;
                blue = pool->fa0;
                rate = pool->f108;
                a = pool->f110;
                b = pool->f3c;
                c = pool->f38;
                d = pool->f118;
                random = pool->f48;
                scratch = pool->f40;
                val = pool->f128;
                *(f64 *)((u8 *)&loc + 332) = pool->f120;
                *(u32 *)((u8 *)&loc + 52) = *(u32 *)((u8 *)rng + 360);
                *(f64 *)((u8 *)&loc + 340) = pool->fc0;
                do {
                    *(u32 *)((u8 *)&loc + 60) = *(u32 *)((u8 *)arg0);
                    *(u32 *)((u8 *)&loc + 64) = *(u32 *)((u8 *)arg0 + 4);
                    *(u32 *)((u8 *)&loc + 68) = *(u32 *)((u8 *)arg0 + 8);
                    random = fn_1_584AC() & 0xffff;
                    *(f32 *)((u8 *)&loc + 60) += (f32)(((f64)random - 4503599627370496.0) / color - 0.5) * 10.0f;
                    random = fn_1_584AC() & 0xffff;
                    *(f32 *)((u8 *)&loc + 64) += (f32)(((f64)random - 4503599627370496.0) / color - 0.5) * 10.0f;
                    random = fn_1_584AC() & 0xffff;
                    *(u32 *)((u8 *)&loc + 72) = pool->fdc;
                    *(u32 *)((u8 *)&loc + 76) = pool->fe0;
                    *(u32 *)((u8 *)&loc + 80) = pool->fe4;
                    *(f32 *)((u8 *)&loc + 68) += (f32)(((f64)random - 4503599627370496.0) / color - 0.5) * 10.0f;
                    random = fn_1_584AC() & 0xffff;
                    *(f32 *)((u8 *)&loc + 16) = (s32)(blue * (pool->f104 + red * ((f32)random / color)));
                    random = fn_1_584AC() & 0xffff;
                    *(f32 *)((u8 *)&loc + 72) += (f32)(((f64)random - 4503599627370496.0) / color - 0.02f) * rate;
                    random = fn_1_584AC() & 0xffff;
                    *(f32 *)((u8 *)&loc + 80) += (f32)(((f64)random - 4503599627370496.0) / color - 0.02f) * rate;
                    random = fn_1_584AC() & 0xffff;
                    *(f32 *)((u8 *)&loc + 60) -= *(f32 *)((u8 *)&loc + 72);
                    *(f32 *)((u8 *)&loc + 40) = fade;
                    *(f32 *)((u8 *)&loc + 44) = alpha;
                    *(f32 *)((u8 *)&loc + 68) -= *(f32 *)((u8 *)&loc + 80);
                    *(f32 *)((u8 *)&loc + 76) = (f32)(a + alpha * ((f32)random / color));
                    *(f32 *)((u8 *)&loc + 64) -= *(f32 *)((u8 *)&loc + 76);
                    random = fn_1_584AC() & 0xffff;
                    d = c + b * ((f32)random / color);
                    *(f32 *)((u8 *)&loc + 32) = d * d;
                    *(f32 *)((u8 *)&loc + 36) = (f32)(255.0f * d) / 255.0f;
                    *(f32 *)((u8 *)&loc + 28) = (f32)(255.0f * (red * (random + d)));
                    random = fn_1_584AC() & 0xffff;
                    *(f32 *)((u8 *)&loc + 140) = blue;
                    *(f32 *)((u8 *)&loc + 136) = (f32)(pool->f120 + val * ((f32)random / color));
                    random = fn_1_584AC() & 0xffff;
                    loc.a[86] = (s32)(pool->fc0 * ((f32)random / color - 0.5f));
                    fn_1_58E3C(&loc);
                } while (0);
            }
        }
    }
}
