/* Non-matching: best partial attempt (40.58% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/enemy_ctrl.h"

extern f32 fn_1_867F8(void *);
extern const f32 lbl_1_rodata_5CB0;
extern const f32 lbl_1_rodata_5CF8;
extern const f64 lbl_1_rodata_5CE8;
extern const f32 lbl_1_rodata_5CF4;
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern u32 __cvt_fp2unsigned(f32);
extern void *fn_1_8627C(void *);
extern u32 fn_1_5910(void);
extern s16 fn_1_3F0C8(void);
extern void fn_1_51E60(FontDrawPacket *);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern u32 fn_1_864E8(void *);
typedef struct { s32 unk_0; u8 pad[0x7c]; } Slot; extern Slot *fn_1_4DF60(void);
extern u8 fn_1_58C4(void);
typedef struct { u32 value; u8 pad4[2]; s16 state; u32 action; } Ctrl;
typedef struct { u8 pad0[0xc]; f32 x,y; u8 pad1[4]; f32 z,w; } FontData;
extern void fn_1_CA218(Ctrl *);
extern void fn_1_51C74(FontData *);
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_1_rodata_5CF0;
extern f32 lbl_1_rodata_5D00, lbl_1_rodata_5D04, lbl_1_rodata_5D08;
extern f32 lbl_1_rodata_5D0C, lbl_1_rodata_5D10, lbl_1_rodata_5D14, lbl_1_rodata_5D18;
extern f32 lbl_1_rodata_5D1C, lbl_1_rodata_5D20, lbl_1_rodata_5D24, lbl_1_rodata_5D28;
extern f32 lbl_1_rodata_5D2C, lbl_1_rodata_5D30, lbl_1_rodata_5C80, lbl_1_rodata_5CCC, lbl_1_rodata_5CD4;
extern f64 lbl_1_rodata_5C00;
extern u32 lbl_801A66A0;

void fn_1_C8DC0(void *arg0) {
    void *obj = fn_1_8627C(arg0);
    u32 pad;
    FontDrawPacket p;
    void *arg = arg0;
    u8 *o = (u8 *)obj;
    s32 t0 = (o[0x175] * 1000 + *(u16 *)(o + 0x176)) + o[0x174] * 0xea60;
    s32 t1 = (o[0x1ed] * 1000 + *(u16 *)(o + 0x1ee)) + o[0x1ec] * 0xea60;
    s32 enabled = 0;
    s32 elapsed;
    u32 ticks, len;
    f32 speed, progress, amount, alpha = 1.0f;
    s32 mode;
    u32 index;
    if (t0 != 0 && (lbl_1_bss_3C30.unk_0 & 0x10) == 0) enabled = 1;
    elapsed = enabled ? t1 - t0 : 9999;
    ticks = __cvt_fp2unsigned(lbl_1_rodata_5CB0 * (f32)(u32)elapsed);
    speed = fn_1_867F8(arg0);
    len = fn_1_48690(0x9416);
    progress = ((f32)(u32)(len & 0xffff) * speed) / lbl_1_rodata_5CF4;
    amount = (f32)(u32)ticks;
    mode = amount < (progress - lbl_1_rodata_5CF8);
    index = fn_1_5910();
    if (((*(u32 *)((u8 *)&lbl_1_data_3D544 + index * 4) >> 30) & 1) && obj != 0) {
        u8 c = mode ? 0x50 : 0;
        u32 interval;
        speed = fn_1_867F8(arg0);
        if (speed < lbl_1_rodata_5D00 && fn_1_3F0C8() == 0x29) {
            interval = speed < lbl_1_rodata_5D04 ? 15 : 30;
            {
                u32 total = lbl_801A66A0;
                u32 rem = total % interval;
                f32 v = (f32)rem / (f32)interval;
                if (v < lbl_1_rodata_5D08) alpha = 0.0f;
                else if (v > 1.0f) alpha = 1.0f;
                else alpha = v;
            }
        }
        p = *(const FontDrawPacket *)&lbl_1_rodata_26F8;
        *(u32 *)((u8 *)&p + 0x0c) = 0x9400;
        *(f32 *)((u8 *)&p + 0x10) = lbl_1_rodata_5D0C;
        *(f32 *)((u8 *)&p + 0x14) = lbl_1_rodata_5D10;
        fn_1_51E60(&p);
        p = *(const FontDrawPacket *)&lbl_1_rodata_26F8;
        *(u32 *)((u8 *)&p + 0x0c) = 0x9417;
        *(f32 *)((u8 *)&p + 0x10) = lbl_1_rodata_5D14;
        *(f32 *)((u8 *)&p + 0x14) = lbl_1_rodata_5D18;
        *(f32 *)((u8 *)&p + 0x18) = lbl_1_rodata_5D10;
        fn_1_51E60(&p);
        if (*(s32 *)(o + 0x118) + 1 >= 2 || (lbl_1_bss_3C30.unk_0 & 0x10)) {
            p = *(const FontDrawPacket *)&lbl_1_rodata_26F8;
            *(u32 *)((u8 *)&p + 0x0c) = 0x9416;
            if (mode) {
                speed = fn_1_867F8(arg0);
                *(f32 *)((u8 *)&p + 0x10) = ((f32)(u32)(ticks + 0x10) * speed) / lbl_1_rodata_5CF4;
            } else *(f32 *)((u8 *)&p + 0x10) = progress;
            {
                s16 height = (s16)fn_1_486C4(0x9416);
                fn_1_51678(&p, 0x9416, 0, 0,
                           (s16)(s32)*(f32 *)((u8 *)&p + 0x10), height);
            }
            {
                u8 *color = (u8 *)&p + 0x44;
                s32 k;
                for (k = 0; k < 3; k++)
                    color[k] = (u8)(s32)((f32)color[k] * alpha);
            }
            *(f32 *)((u8 *)&p + 0x10) = lbl_1_rodata_5D1C;
            *(f32 *)((u8 *)&p + 0x14) = lbl_1_rodata_5D20;
            *(f32 *)((u8 *)&p + 0x18) = lbl_1_rodata_5D24;
            fn_1_51E60(&p);
        }
        p = *(const FontDrawPacket *)&lbl_1_rodata_26F8;
        *(u32 *)((u8 *)&p + 0x0c) = 0x9436;
        *(f32 *)((u8 *)&p + 0x10) = lbl_1_rodata_5D1C;
        *(f32 *)((u8 *)&p + 0x14) = lbl_1_rodata_5D20;
        len = fn_1_48690(0x9436);
        *(f32 *)((u8 *)&p + 0x1c) *= amount / (f32)(u32)len;
        *(f32 *)((u8 *)&p + 0x20) *= lbl_1_rodata_5CD4;
        {
            u8 *color = (u8 *)&p + 0x44;
            s32 k;
            for (k = 0; k < 3; k++) {
                u32 q = color[k] + c;
                q = q >= 255 ? 255 : q;
                color[k] = (u8)(s32)((f32)q * alpha);
            }
        }
        fn_1_51E60(&p);
        p = *(const FontDrawPacket *)&lbl_1_rodata_26F8;
        *(u32 *)((u8 *)&p + 0x0c) = 0x9451;
        *(f32 *)((u8 *)&p + 0x10) = lbl_1_rodata_5D1C;
        *(f32 *)((u8 *)&p + 0x14) = lbl_1_rodata_5D20;
        fn_1_48690(0x9451);
        len = fn_1_48690(0x9416);
        *(f32 *)((u8 *)&p + 0x1c) *= (f32)(len / 2) - 1.0f;
        *(f32 *)((u8 *)&p + 0x18) = lbl_1_rodata_5D2C;
        fn_1_51E60(&p);
        if (mode) {
            p = *(const FontDrawPacket *)&lbl_1_rodata_26F8;
            *(u32 *)((u8 *)&p + 0x0c) = 0x9450;
            *(f32 *)((u8 *)&p + 0x10) = (f32)(ticks + 0x1e4) - (f32)lbl_1_rodata_5CE8;
            *(f32 *)((u8 *)&p + 0x14) = lbl_1_rodata_5D20;
            *(f32 *)((u8 *)&p + 0x18) = lbl_1_rodata_5CCC;
            fn_1_51E60(&p);
        }
    }
    if (((*(u32 *)((u8 *)&lbl_1_data_3D544 + fn_1_5910() * 4) >> 20) & 1) &&
        (fn_1_864E8(arg0) & 0x40) && !(fn_1_864E8(arg0) & 0x800)) {
        Slot *ctrl = fn_1_4DF60();
        if (ctrl) {
            *(u32 *)((u8 *)ctrl + 8) = 0x9410;
            *(f32 *)((u8 *)ctrl + 0xc) = lbl_1_rodata_5D30;
            *(f32 *)((u8 *)ctrl + 0x10) = lbl_1_rodata_5C80;
            *(f32 *)((u8 *)ctrl + 0x14) = lbl_1_rodata_5D20;
            if (fn_1_58C4() == 1 && lbl_1_bss_4E6A8) {
                *(u32 *)((u8 *)ctrl + 0x38) |= 0x800;
                *(f32 *)((u8 *)ctrl + 0x3c) = (f32)lbl_1_bss_4E6AC;
            }
            *(u16 *)((u8 *)ctrl + 6) = 0;
            fn_1_CA218((Ctrl *)ctrl);
            fn_1_51C74((FontData *)ctrl);
        }
    }
}
