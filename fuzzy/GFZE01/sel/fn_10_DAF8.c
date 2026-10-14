/* Non-matching: best partial attempt (75.61% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

struct DAF8State {
    u8 pad0[0x92];
    s16 selected;
    u8 pad94[0xAC];
    s32 flags;
    u8 pad144[2];
    s16 value;
    s16 amount;
};
extern struct DAF8State lbl_1_bss_8B3A0;
struct DAF8Pool {
    u8 pad0[0x44];
    f32 one, half, zero;
    u8 pad50[4];
    f32 rate, x, y, z, a, b, c, d, e, f, g, h, j, k;
    f64 conv, tickconv;
    u8 pad98[0x18];
    u32 wordB0, wordB4;
};
extern struct DAF8Pool lbl_10_rodata_158;
extern const u8 lbl_1_rodata_26F8[];
extern u32 lbl_801A66A8;
extern f32 lbl_8006D188(u32);
extern u16 fn_1_48690(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

void fn_10_DAF8(void) {
    f32 alpha = 1.0f;
    u32 flags = lbl_1_bss_8B3A0.flags;

    if ((flags & ~1) && (flags & 0x10)) {
        f32 half = 0.5f;
        f32 zero = 0.0f;
        f32 span = (f32)lbl_1_bss_8B3A0.amount * half;
        f32 diff = (f32)lbl_1_bss_8B3A0.value - span;
        if (flags & 2) {
            f32 n = diff;
            if (n > zero) n = zero;
            n /= span;
            if (n < zero) {
                alpha = zero;
            } else {
                if (diff > zero) {
                    f32 t = diff;
                    if (t > zero) t = zero;
                    t /= span;
                    if (t > 1.0f) alpha = 1.0f;
                    else {
                        f32 q = diff;
                        if (q <= zero) q = zero;
                        alpha = q / span;
                    }
                } else alpha = 1.0f;
            }
        } else if (flags & 1) {
            f32 n = (f32)lbl_1_bss_8B3A0.value / span;
            if (n < zero) n = zero;
            else if (n > alpha) n = alpha;
            alpha = 1.0f - n;
        }
    } else if (*(s16 *)((u8 *)&lbl_1_bss_8B3A0) == -1) {
        return;
    }

    {
        FontDrawPacket packet;
        s16 i;
        f32 width = 0.4f * alpha;
        f32 half = 0.5f * alpha;

        for (i = 0; i < 2; ++i) {
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0xFFFFA12D;
            packet.flags = 10;
            packet.x = 320.0f;
            packet.y = (f32)(218 + i * 40);
            packet.z = 3.0f;
            packet.alpha = alpha;
            fn_1_51678(&packet, packet.image, 0, i * 24, (s16)fn_1_48690(packet.image), 24);
            fn_1_4F734(&packet);

            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0xFFFFA12D;
            packet.flags = 10;
            packet.x = 323.0f;
            packet.y = (f32)(221 + i * 40);
            packet.z = 4.0f;
            packet.alpha = width;
            *(u32 *)((u8 *)&packet + 0x40) = 0;
            fn_1_51678(&packet, packet.image, 0, i * 24, (s16)fn_1_48690(packet.image), 24);
            fn_1_4F734(&packet);

            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0xFFFFA12E;
            packet.flags = 10;
            packet.x = 320.0f;
            packet.y = (f32)(218 + i * 40);
            packet.z = 5.0f;
            packet.alpha = half;
            *(u32 *)((u8 *)&packet + 0x40) = 0;
            fn_1_51678(&packet, packet.image, 0, i * 40, (s16)fn_1_48690(packet.image), 40);
            fn_1_4F734(&packet);

            if (i == lbl_1_bss_8B3A0.value) {
                u32 tick = lbl_801A66A8;
                u32 mins = (u32)(((u64)0x88888889u * tick) >> 32) >> 5;
                u32 sec = tick - mins * 60;
                packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
                packet.image = 0xFFFFA127;
                packet.flags = 10;
                packet.x = 320.0f;
                packet.y = (f32)(218 + i * 40);
                packet.z = 6.0f;
                packet.color[0] = 80;
                packet.color[1] = 160;
                packet.color[2] = 160;
                packet.alpha = (f32)(u32)sec;
                packet.alpha = 16384.0f + (65536.0f * packet.alpha) / 60.0f;
                packet.scale_x *= 1.875f;
                packet.scale_y *= 0.55555558f;
                packet.alpha = alpha * (0.25f + 0.25f * lbl_8006D188((u32)packet.alpha));
                fn_1_4F734(&packet);
            }
        }
    }
}
