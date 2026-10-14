/* Non-matching: best partial attempt (36.98% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/effect.h"
#include "psvec.h"

typedef struct { u32 x, y, z; } Triple;
typedef struct { u8 pad[0x18]; s16 unk_18; u8 rest[0x92]; f32 unk_94; u8 pad2[0x14]; s16 unk_ac; } Work;

extern void fn_1_862D4(s16, Triple *);
extern void fn_1_8636C(s16, void *);
extern void fn_1_57714(u8);
extern void fn_1_57720(u32, u32, u32, u32);
extern void fn_1_57A70(u32, void *);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);
extern f32 lbl_8006D188(s32);
extern void lbl_8006DCA4(void);
extern u32 lbl_1_data_1D628;
extern const f32 lbl_1_rodata_2950;

void fn_1_5C058(Work *self) {
    Triple a;
    u8 bytes[4];
    f32 b[3];
    f32 *colors = (f32 *)((u8 *)&lbl_1_data_1D730 + 8);
    u32 rgb[3];
    u32 rgba[3];
    f32 intensity = 0.0f;
    s32 i;
    f32 threshold;
    f32 x, y, z;
    f32 p = 0.0f;

    fn_1_862D4(self->unk_18, &a);
    fn_1_8636C(self->unk_18, bytes + 0x50);
    b[0] = *(f32 *)&a.x;
    b[1] = *(f32 *)&a.y;
    b[2] = *(f32 *)&a.z;
    rgb[0] = *(u32 *)((u8 *)&lbl_1_rodata_2950 + 0x138);
    rgb[1] = *(u32 *)((u8 *)&lbl_1_rodata_2950 + 0x13c);
    rgb[2] = *(u32 *)((u8 *)&lbl_1_rodata_2950 + 0x140);
    lbl_8006DC6C(bytes + 0x50);
    *(f32 *)0xE000000C = b[0];
    *(f32 *)0xE000001C = b[1];
    *(f32 *)0xE000002C = b[2];
    lbl_8006E1B0(rgb, b);
    threshold = 0.05f * (f32)(s32)*(u32 *)((u8 *)self + 0x10);
    if (threshold > 1.0f) {
        u32 r = lbl_1_data_1D628;
        f32 q0, q1, q2;
        r = r * 0x41C64E6D + 0x3039; lbl_1_data_1D628 = r; q0 = (f32)((r >> 16) & 0x7fff);
        r = r * 0x41C64E6D + 0x3039; lbl_1_data_1D628 = r; q1 = (f32)((r >> 16) & 0x7fff);
        r = r * 0x41C64E6D + 0x3039; lbl_1_data_1D628 = r; q2 = (f32)((r >> 16) & 0x7fff);
        x = self->rest[4] * threshold;
        y = self->rest[8] * threshold;
        z = self->rest[12] * threshold;
        x = self->rest[4] * 255.0f * 0.5f + 5.0f * (q0 / 32767.0f - 0.5f);
        y = self->rest[8] * 255.0f * 0.5f + 5.0f * (q1 / 32767.0f - 0.5f);
        z = self->rest[12] * 255.0f * 0.5f + 5.0f * (q2 / 32767.0f - 0.5f);
    } else {
        x = self->rest[4] * threshold * 255.0f;
        y = self->rest[8] * threshold * 255.0f;
        z = self->rest[12] * threshold * 255.0f;
    }
    bytes[0] = (u8)x; bytes[1] = (u8)y; bytes[2] = (u8)z; bytes[3] = 255;
    rgb[0] = a.x; rgb[1] = a.y; rgb[2] = a.z;
    *(f32 *)((u8 *)rgb + 0) = self->unk_94;
    i = 1;
    while (i < self->unk_ac) {
        b[0] = colors[0] * *(f32 *)((u8 *)self + 0x98);
        p = lbl_8006D188((s32)*(f32 *)((u8 *)self + 0x98));
        b[1] = colors[1] * p;
        b[2] = colors[1];
        if (i == 14) {
            u32 r = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
            lbl_1_data_1D628 = r;
            b[2] = 3.0f * ((f32)((r >> 16) & 0x7fff) - 4503599627370496.0f) / 32767.0f + b[2];
        }
        lbl_8006DC6C(bytes + 0x50);
        *(f32 *)0xE000000C = b[0]; *(f32 *)0xE000001C = b[1]; *(f32 *)0xE000002C = b[2];
        lbl_8006E1B0(b, rgb);
        lbl_1_data_1D628 = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        ((f32 *)rgba)[0] += (f32)i * (colors[2] * (0.1f));
        ((f32 *)rgba)[1] += (f32)i * (colors[2] * (0.1f));
        ((f32 *)rgba)[2] += (f32)i * (colors[2] * (0.1f));
        i++;
    }
    if (*(s32 *)((u8 *)self + 0x10) >= 10) {
        u32 r = lbl_1_data_1D628 * 0x41C64E6D + 0x3039; lbl_1_data_1D628 = r;
        i = (s32)(10.0f + 19.0f * (((f32)((r >> 16) & 0x7fff) - 4503599627370496.0f) / 32767.0f - 0.5f));
    } else i = *(s32 *)((u8 *)self + 0x10);
    fn_1_57714((u8)i);
    fn_1_57720(1,1,1,0);
    lbl_8006DCA4();
    if (self->unk_ac > 4) {
        fn_1_57A70((u32)(self->unk_ac - 3), rgb);
        fn_1_57714((u8)i);
        fn_1_57A70(2, rgb);
        fn_1_57714((u8)i);
        fn_1_57A70(2, rgb);
        fn_1_57714((u8)i);
        fn_1_57A70(2, rgb);
    } else fn_1_57A70((u16)self->unk_ac, rgb);
}
