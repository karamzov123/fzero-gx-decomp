/* Non-matching: best partial attempt (31.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/enemy_ctrl.h"

extern u32 lbl_1_rodata_5E28[10];
extern u32 lbl_1_rodata_5E50[12];
extern f32 lbl_1_rodata_26F8[22];
extern f32 fn_1_519FC(f32);
extern f32 fn_1_51AC0(f32);
extern u8 fn_1_58C4(void);
extern u32 fn_1_5910(void);
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5E0C;
extern const f32 lbl_1_rodata_5E90;
extern const f32 lbl_1_rodata_5E94;
extern u32 lbl_1_rodata_5E80;
extern u32 lbl_1_rodata_5E84;
extern int fn_1_4F734(void *);
extern const f32 lbl_1_rodata_5DC8;
extern u32 lbl_1_rodata_5E88;
extern const f64 lbl_1_rodata_5CE8;
extern const f32 lbl_1_rodata_5CD8;
extern u32 fn_1_51E60(void *);
extern u32 lbl_1_rodata_5E8C;

struct Cb6Arg {
    f32 x;
    f32 y;
    f32 sx;
    f32 sy;
    f32 z;
    u32 unk14;
    s32 id;
    u32 unk1C;
    u32 unk20;
    u8 unk24[4];
};
struct Cb6Packet {
    union { u32 word; f32 value; } w0;
    f32 x, y, a, sx, sy;
    u32 w18[5];
    f32 alpha;
    u32 w30[11];
};

struct Cb6Work { u32 table[22]; struct Cb6Packet packet; };
#define packet work.packet
void fn_1_CB6D8(struct Cb6Arg *arg) {
    struct Cb6Work work;
    u32 *colors = &work.table[0];
    u32 *strings = &work.table[12];
    s32 id = arg->id;
    u32 i;
    u32 color = arg->unk14;
    f32 x;
    f32 y;
    f32 scale;
    s32 low = 0;
    u32 r = color & 0xFF0;
    u32 g = (color >> 12) & 0xFF;
    u32 b = (color >> 4) & 0xFF;
    u32 n = (u32)(id + 1);

    for (i = 0; i < 10; i++) strings[i] = lbl_1_rodata_5E28[i];
    for (i = 0; i < 12; i++) colors[i] = lbl_1_rodata_5E50[i];
    packet = *(struct Cb6Packet *)lbl_1_rodata_26F8;

    packet.x = x;
    packet.y = y;
    if (fn_1_58C4() == 1) scale = lbl_1_rodata_5CFC;
    else scale = lbl_1_rodata_5E0C;
    packet.sx = arg->sx * arg->sy * scale;
    if (fn_1_58C4() == 1) scale = lbl_1_rodata_5CFC;
    else scale = lbl_1_rodata_5E0C;
    packet.sy = arg->sy * scale;
    packet.alpha = arg->sx;
    packet.w30[0] = 5;
    packet.w30[3] = arg->unk1C;

    if (fn_1_58C4() > 1) {
        if (fn_1_5910() & 1) x -= lbl_1_rodata_5E90;
        else x += lbl_1_rodata_5E94;
    }
    packet.x = x;
    if (id == -1) low = 3;
    else if (id < 9) low = 1;

    for (i = 11; (s32)i >= low; i--) {
        u32 j;
        u32 text = 0;
        u32 alpha;
        u32 rem = ((n / 10) % 10) * 4;
        (void)rem;
        if (i == 2) continue;
        if (i == 0) { text = lbl_1_rodata_5E80; packet.w0.word = strings[0]; }
        else if (i == 1) { text = lbl_1_rodata_5E84; packet.w0.word = strings[1]; }
        else if (i == 3) packet.w0.word = strings[2];
        else if (i == 4) packet.w0.word = strings[3];
        else if (i == 5) { packet.w0.word = 0x943E; text = lbl_1_rodata_5E80; }
        else if (i == 6) packet.w0.word = strings[4];
        else if (i == 7) packet.w0.word = strings[5];
        else if (i == 8) { packet.w0.word = 0x943F; text = lbl_1_rodata_5E84; }
        else if (i == 9) packet.w0.word = strings[6];
        else if (i == 10) packet.w0.word = strings[7];
        else if (i == 11) packet.w0.word = strings[8];
        if (text) packet.w30[7] = text;
        packet.alpha = arg->sx;
        packet.w30[2] = arg->unk20;
        fn_1_4F734(&packet);
        if (packet.w0.word == 0x943E || packet.w0.word == 0x943F) {
            packet.w30[2] = arg->unk20;
            packet.alpha = arg->sx;
            alpha = arg->unk24[3];
            packet.alpha = (f32)alpha;
            fn_1_51E60(&packet);
        }
        (void)j;
    }
}
