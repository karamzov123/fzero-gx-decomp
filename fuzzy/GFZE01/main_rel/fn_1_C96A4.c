/* Non-matching: best partial attempt (63.82% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/enemy_ctrl.h"

typedef struct { s32 unk_0; u8 pad[0x7c]; } Sig_fn_1_4DF60_Slot;
typedef struct { u32 unk_0; u8 pad4[4]; f32 x, y, scaleX, scaleY, unk_12; u8 pad24[32]; u8 r, g, b, pad3b; u32 color; u8 tail[36]; } TargetPacket;
typedef TargetPacket FontDrawPacket;
extern void *fn_1_8627C(void *);
extern f32 fn_1_867F8(void *);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern u32 __cvt_fp2unsigned(f32);
extern f32 fn_1_5910(void);
extern s16 fn_1_3F0C8(void);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern u32 fn_1_864E8(void *);
extern Sig_fn_1_4DF60_Slot *fn_1_4DF60(void);
extern const f32 lbl_1_rodata_5CB0, lbl_1_rodata_5CF4, lbl_1_rodata_5CF8, lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5D00, lbl_1_rodata_5D04, lbl_1_rodata_5D08, lbl_1_rodata_5D10;
extern const f32 lbl_1_rodata_5D24, lbl_1_rodata_5D38, lbl_1_rodata_5D20, lbl_1_rodata_5D3C;
extern const f32 lbl_1_rodata_5C80, lbl_1_rodata_5D28, lbl_1_rodata_5D2C, lbl_1_rodata_5CCC;
extern const f64 lbl_1_rodata_5CE8, lbl_1_rodata_5C00;
extern u32 lbl_1_rodata_5D34;
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_801A66A0;
extern u32 lbl_1_bss_4E6A8, lbl_1_bss_4E6AC;
extern void fn_1_CA218(void *);
extern Obj_1_data_3D544 lbl_1_data_3D544;

Sig_fn_1_4DF60_Slot *fn_1_C96A4(void *arg0, u32 arg1, u32 arg2) {
    u8 colors[3];
    u32 timer;
    f32 pct;
    TargetPacket p;
    void *obj;
    s32 start, end, diff;
    u32 frame, mode;
    f32 val, alpha;
    s32 step, rem;
    Sig_fn_1_4DF60_Slot *slot;
    obj = fn_1_8627C(arg0);
    start = (s32)*(u8 *)((u8 *)obj + 0x174) * (0x10000 - 5536);
    start += (s32)*(u8 *)((u8 *)obj + 0x175) * 1000 + *(u16 *)((u8 *)obj + 0x176);
    end = (s32)*(u8 *)((u8 *)obj + 0x1ed) * 1000 + *(u16 *)((u8 *)obj + 0x1ee);
    end += (s32)*(u8 *)((u8 *)obj + 0x1ec) * (0x10000 - 5536);
    diff = end ? end - start : 9999;
    timer = __cvt_fp2unsigned(lbl_1_rodata_5CB0 * (f32)diff);
    pct = (f32)fn_1_48690(0x10000 - 27626) * fn_1_867F8(arg0) / lbl_1_rodata_5CF4;
    val = (f32)timer;
    mode = fn_1_5910();
    if ((((u32 *)&lbl_1_data_3D544)[mode] >> 1) & 1) {
        if (val < 0) colors[0] = colors[1] = 80;
        else colors[0] = colors[1] = 0;
        colors[2] = 0;
        alpha = fn_1_867F8(arg0);
        if (alpha < lbl_1_rodata_5D00 && fn_1_3F0C8() == 41) {
            step = alpha < lbl_1_rodata_5D04 ? 15 : 30;
            rem = lbl_801A66A0 - (lbl_801A66A0 / step) * step;
            val = (f32)rem / (f32)step;
            if (val < lbl_1_rodata_5D08) alpha = lbl_1_rodata_5D08;
            else if (val > 1.0f) alpha = 1.0f;
            else alpha = val;
        }
    }
    p = *(TargetPacket *)(void *)lbl_1_rodata_26F8;
    p.unk_0 = 0x10000 - 27648;
    p.x = (f32)(s32)(arg1 + 89);
    p.y = (f32)(s32)(arg2 + 22);
    fn_1_4F734(&p);
    p = *(FontDrawPacket *)lbl_1_rodata_26F8;
    p.unk_0 = 0x10000 - 27625;
    fn_1_51678(&p, p.unk_0, 0, 0, fn_1_48690(p.unk_0), 10);
    p = *(FontDrawPacket *)lbl_1_rodata_26F8;
    p.x = (f32)(s32)arg1; p.y = (f32)(s32)arg2; p.unk_12 = 50.0f;
    fn_1_4F734(&p);
    p = *(FontDrawPacket *)lbl_1_rodata_26F8;
    p.unk_0 = 0x10000 - 27625;
    fn_1_51678(&p, p.unk_0, 0, 14, fn_1_48690(p.unk_0), 10);
    p = *(FontDrawPacket *)lbl_1_rodata_26F8;
    p.x = (f32)(s32)arg1; p.y = (f32)(s32)(arg2 + 10); p.unk_12 = 51.0f;
    fn_1_4F734(&p);
    if ((s32)(*(u32 *)((u8 *)obj + 0x118) + 1) >= 2) {
        p = *(FontDrawPacket *)lbl_1_rodata_26F8;
        p.unk_0 = 0x10000 - 27626;
        alpha = val;
        if (mode) alpha = ((f32)(timer + 16) * fn_1_867F8(arg0)) / 100.0f;
        fn_1_51678(&p, p.unk_0, 0, 0, (s16)alpha, fn_1_486C4(p.unk_0));
        p.r = (u8)((f32)p.r * pct);
        p.g = (u8)((f32)p.g * pct);
        p.b = (u8)((f32)p.b * pct);
        p.x = (f32)(s32)(arg1 + 4); p.y = (f32)(s32)(arg2 + 4); p.unk_12 = 38.0f;
        val = (f32)fn_1_486C4(p.unk_0);
        p.scaleY = p.scaleY * (12.0f / val);
        fn_1_4F734(&p);
    }
    p = *(FontDrawPacket *)lbl_1_rodata_26F8;
    p.unk_0 = 0x10000 - 27594;
    p.x = (f32)(s32)(arg1 + 4); p.y = (f32)(s32)(arg2 + 4);
    val = (f32)fn_1_48690(p.unk_0);
    p.scaleX *= pct / val;
    p.scaleY *= 12.0f / (f32)fn_1_486C4(p.unk_0);
    p.color = lbl_1_rodata_5D34;
    p.r = p.r + colors[0] > 255 ? 255 : p.r + colors[0];
    p.g = p.g + colors[1] > 255 ? 255 : p.g + colors[1];
    p.b = p.b + colors[2] > 255 ? 255 : p.b + colors[2];
    p.r = (u8)((f32)p.r * alpha);
    p.g = (u8)((f32)p.g * alpha);
    p.b = (u8)((f32)p.b * alpha);
    p.unk_12 = 40.0f;
    fn_1_4F734(&p);
    p = *(FontDrawPacket *)lbl_1_rodata_26F8;
    p.unk_0 = 0x10000 - 27567;
    p.x = (f32)(s32)(arg1 + 4); p.y = (f32)(s32)(arg2 + 4);
    val = (f32)fn_1_48690(p.unk_0);
    p.scaleX *= (s32)(fn_1_48690(0x10000 - 27626) / (u32)val);
    p.unk_12 = 35.0f;
    p.scaleY *= 12.0f / (f32)fn_1_486C4(p.unk_0);
    fn_1_4F734(&p);
    if (mode) {
        p = *(FontDrawPacket *)lbl_1_rodata_26F8;
        p.unk_0 = 0x10000 - 27568;
        p.x = (f32)(arg1 + timer + 4); p.y = (f32)(s32)(arg2 + 4); p.unk_12 = 30.0f;
        p.scaleY *= 12.0f / (f32)fn_1_486C4(p.unk_0);
        fn_1_4F734(&p);
    }
    mode = fn_1_5910();
    if (((lbl_1_data_3D544.unk_0 >> 11) & 1) &&
        (fn_1_864E8(arg0) & 0x40) && !(fn_1_864E8(arg0) & 0x800)) {
        slot = fn_1_4DF60();
        if (slot != 0) {
            slot->unk_0 = 0x10000 - 27632;
            *(f32 *)((u8 *)slot + 12) = (f32)(s32)(arg1 - 8);
            *(f32 *)((u8 *)slot + 16) = (f32)(s32)(arg2 - 12);
            *(f32 *)((u8 *)slot + 20) = 28.0f;
            *(f32 *)((u8 *)slot + 28) *= 0.75f;
            if (lbl_1_bss_4E6A8) {
                *(u32 *)((u8 *)slot + 56) |= 0x08000000;
                *(f32 *)((u8 *)slot + 60) = (f32)(lbl_1_bss_4E6AC);
            }
            *(u16 *)((u8 *)slot + 6) = 0;
            *(void **)((u8 *)slot + 120) = fn_1_CA218;
        }
    }
    return slot;
}
