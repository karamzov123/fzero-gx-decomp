/* Non-matching: best partial attempt (61.73% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

struct Copy88 { u32 a[22]; };
struct State {
    s16 unk0;
    u8 pad2[0x13e];
    u32 flags;
    u8 pad144[2];
    s16 value146;
    s16 value148;
};
struct Pool {
    u8 pad[0x3c];
    u32 word3c, word40;
    f32 v44, v48, v4c, v50, v54, v58, v5c, v60, v64, v68, v6c, v70, v74, v78, v7c, v80, v84;
    f64 v88, v90;
};
struct Color { u32 v; };
extern struct Pool lbl_10_rodata_158;
extern struct State lbl_1_bss_8B3A0;
extern u8 lbl_1_rodata_26F8[];
extern struct Color lbl_801A66A8;
extern f32 lbl_8006D188(u32);
extern int fn_10_91E8(void);
extern u16 fn_1_48690(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

void fn_10_D044(void) {
    struct Pool *pool = &lbl_10_rodata_158;
    struct State *state = (struct State *)&lbl_1_bss_8B3A0;
    f32 alpha = pool->v44;
    f32 t, d, h;
    f32 w1, w2, w3;
    s32 i, x, x2, idx, idx2;
    u32 flags = state->flags;
    FontDrawPacket packet;
    s16 textLen, row;

    if ((flags & 1) && (flags & 8)) {
        f64 bias = pool->v88;
        f64 n1 = (f64)state->value148;
        f32 scale = (f32)((n1 - bias) * pool->v48);
        if (flags & 2) {
            f64 n2 = (f64)state->value146;
            d = (f32)(n2 - bias) - scale;
            t = pool->v4c;
            if (d > t) t = d;
            t /= scale;
            if (t < pool->v4c) {
                alpha = pool->v4c;
                goto begin;
            }
            h = d;
            if (h > pool->v4c) h = pool->v4c;
            h /= scale;
            if (h > pool->v44) {
                alpha = pool->v44;
                goto begin;
            }
            h = d;
            if (h <= pool->v4c) h = pool->v4c;
            alpha = h / scale;
        } else if (flags & 1) {
            f64 n2 = (f64)state->value146;
            t = (f32)(((n2 - bias) - scale) / scale);
            if (t >= pool->v4c) {
                if (t > alpha) t = alpha;
            } else t = pool->v4c;
            alpha = pool->v44 - t;
        }
    } else if (state->unk0 == -1) {
        return;
    }
begin:
    w1 = pool->v50 * alpha;
    w2 = pool->v54 * alpha;
    w3 = pool->v48 * alpha;
    x = 0;
    x2 = 0;
    idx = 198;
    idx2 = 201;
    for (i = 0; i < 3; i++) {
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x10000 - 24279;
        packet.flags = 10;
        packet.x = pool->v58;
        packet.y = (f32)idx;
        packet.z = pool->v5c;
        packet.alpha = alpha;
        textLen = fn_1_48690(packet.image);
        fn_1_51678(&packet, packet.image, 0, (s16)x, textLen, 24);
        row = (s16)fn_10_91E8();
        if (i + 1 > row - 1) packet.alpha = w1;
        fn_1_4F734(&packet);

        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x10000 - 24279;
        packet.flags = 10;
        packet.x = pool->v60;
        packet.y = (f32)idx2;
        packet.z = pool->v64;
        packet.alpha = w2;
        packet.color[0] = pool->word3c;
        textLen = fn_1_48690(packet.image);
        fn_1_51678(&packet, packet.image, 0, (s16)x, textLen, 24);
        row = (s16)fn_10_91E8();
        if (i + 1 > row - 1) packet.alpha = w1;
        fn_1_4F734(&packet);

        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x10000 - 24278;
        packet.flags = 10;
        packet.x = pool->v58;
        packet.y = (f32)idx;
        packet.z = pool->v68;
        packet.color[0] = pool->word40;
        packet.alpha = w3;
        textLen = fn_1_48690(packet.image);
        fn_1_51678(&packet, packet.image, 0, (s16)x2, textLen, 40);
        fn_1_4F734(&packet);

        if (i + 1 == state->value146 - 1) {
            u32 ticks = lbl_801A66A8.v;
            u32 seconds = ticks - (((ticks * 0x8889u) >> 32) >> 5) * 60;
            f32 time = pool->v78 * (f32)seconds;
            f32 angle = pool->v74 + time / pool->v7c;
            f32 phase;
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x10000 - 24281;
            packet.flags = 10;
            packet.x = pool->v58;
            packet.y = (f32)idx;
            packet.z = pool->v6c;
            packet.alpha = alpha;
            packet.color[0] = 80;
            packet.color[1] = 160;
            packet.color[2] = 160;
            packet.color[3] = (u32)angle;
            phase = lbl_8006D188((u32)angle);
            packet.scale_x *= pool->v80;
            packet.scale_y *= pool->v84;
            packet.alpha = alpha * (pool->v70 + pool->v70 * phase);
            fn_1_4F734(&packet);
        }
        idx += 40;
        x += 24;
        idx2 += 40;
        x2 += 40;
    }
}
