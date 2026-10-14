/* Non-matching: best partial attempt (38.71% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "font.h"
#include "rel/main_rel/accessory.h"

typedef struct {
    f32 x, y, z;
} Sig_fn_1_862D4_Triple;

typedef struct {
    f32 unk_0;
    u8 pad_4[8];
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
    f32 unk_68;
    f32 unk_6C;
    f32 unk_70;
    f32 unk_74;
} Config;

extern Config lbl_1_rodata_8068;
extern f32 lbl_1_rodata_26F8[22];
extern f32 fn_1_A71BC(void);
extern s16 fn_1_6B48(s32);
extern s32 camera_get_state(void);
extern u32 fn_1_6EC0(u8);
extern u32 fn_1_864E8(int);
extern u32 fn_1_485A8(s32);
extern u8 fn_1_3F7E0(void);
extern u8 fn_1_5910(void);
extern u8 fn_1_86810(int);
extern void *fn_1_8627C(s32);
extern void fn_1_12999C(void);
extern void fn_1_862D4(int, Sig_fn_1_862D4_Triple *);
extern void fn_1_A714C(f32 *, f32 *, f32 *, f32 *);
extern u32 lbl_8006D9D8(u32);
extern void lbl_8006D7B0(void);
extern s32 lbl_8006D24C(f32, f32);
extern int fn_1_4F734(FontDrawPacket *);

void fn_1_12907C(f32 arg0) {
    u32 index = fn_1_5910();
    f32 speed = ((f32 *)&lbl_1_bss_89770)[index];
    u32 object = ((u32 *)&lbl_1_bss_89760)[index];
    s16 player = fn_1_6B48(index);
    void *other, *self;
    f32 delta, a, b, scale, yscale, limit;
    f32 xy[4];
    f32 sx, sy, xpos, ypos, zscale, angleValue;
    f32 maximum, ratio, correction, opacity;
    s16 angle;
    s32 maxPlayers;
    Sig_fn_1_862D4_Triple vec;
    u32 words[22];
    u8 packetData[0x98];
    FontDrawPacket *packet = (FontDrawPacket *)(packetData + 4);
    s32 i, state;

    if (!fn_1_6EC0((u8)index)) return;
    fn_1_12999C();
    if (speed < lbl_1_rodata_8068.unk_C || speed == lbl_1_rodata_8068.unk_0) return;
    if (fn_1_864E8(player) & 0x10880) return;
    if (fn_1_864E8(object) & 0x8000880) return;
    maxPlayers = fn_1_3F7E0();
    if ((s32)(fn_1_86810(player) + 1) >= maxPlayers) return;
    other = fn_1_8627C(object);
    delta = *(f32 *)((u8 *)other + 0x108);
    self = fn_1_8627C(player);
    delta -= *(f32 *)((u8 *)self + 0x108);
    angle = *(s16 *)((u8 *)self + 0x104);
    if (delta > lbl_1_rodata_8068.unk_14 || delta < lbl_1_rodata_8068.unk_18 ||
        angle > 0x3000 || angle < -0x3000) return;

    fn_1_A714C(&a, &b, &a, &a);
    scale = fn_1_A71BC();
    fn_1_862D4(object, &vec);
    lbl_8006D9D8((u32)&vec);
    lbl_8006D7B0();

    {
        volatile f32 *matrix = (volatile f32 *)0xE0000000;
        f32 off = lbl_1_rodata_8068.unk_1C;
        matrix[3] = matrix[1] * off + matrix[3];
        matrix[7] = matrix[5] * off + matrix[7];
        matrix[11] = matrix[9] * off + matrix[11];
        psvec_set(&xy[1], matrix[11], matrix[7], matrix[3]);
    }
    limit = lbl_1_rodata_8068.unk_20;
    if (xy[3] > limit) xy[3] = limit;
    ratio = limit / xy[3];
    sx = (yscale = lbl_1_rodata_8068.unk_10) / xy[0] * (xy[1] * scale) * ratio;
    sy = ratio * (xy[2] * scale);

    state = camera_get_state();
    xpos = 0.0f;
    ypos = 0.0f;
    zscale = 0.5f;
    angleValue = lbl_1_rodata_8068.unk_24;

    switch ((s8)state) {
    case 0:
        xpos = 320.0f + 20.0f * sx;
        if (xpos < 15.0f) xpos = 15.0f;
        else if (xpos > 625.0f) xpos = 625.0f;
        break;
    case 1:
        if (index == 0 || index == 1) {
            xpos = 320.0f + 90.0f * sx;
            if (xpos < 15.0f) xpos = 15.0f;
            else if (xpos > 625.0f) xpos = 625.0f;
            if (index == 0) angleValue = 225.0f;
        }
        break;
    case 2:
        xpos = 10.0f * sx;
        if (index == 0) {
            xpos += 18.0f;
            if (xpos < 10.0f) xpos = 10.0f;
            else if (xpos > 302.0f) xpos = 302.0f;
        } else if (index == 1) {
            xpos += 338.0f;
            if (xpos < 10.0f) xpos = 10.0f;
            else if (xpos > 622.0f) xpos = 622.0f;
        }
        break;
    case 3: case 4: case 5:
        if (index == 0) {
            xpos = 320.0f + 20.0f * sx;
            if (xpos < 15.0f) xpos = 15.0f;
            else if (xpos > 625.0f) xpos = 625.0f;
            angleValue = 225.0f;
        } else if (index == 1) {
            xpos = 160.0f + 10.0f * sx;
            if (xpos < 10.0f) xpos = 10.0f;
            else if (xpos > 310.0f) xpos = 310.0f;
        } else if (index == 2) {
            xpos = 480.0f + 10.0f * sx;
            if (xpos < 330.0f) xpos = 330.0f;
            else if (xpos > 630.0f) xpos = 630.0f;
        }
        break;
    case 6:
        if (index == 0) {
            xpos = 160.0f + 10.0f * sx;
            if (xpos < 10.0f) xpos = 10.0f;
            else if (xpos > 310.0f) xpos = 310.0f;
        } else if (index == 1) {
            xpos = 480.0f + 10.0f * sx;
            if (xpos < 330.0f) xpos = 330.0f;
            else if (xpos > 630.0f) xpos = 630.0f;
        } else {
            xpos = 320.0f + 20.0f * sx;
            if (xpos < 15.0f) xpos = 15.0f;
            else if (xpos > 625.0f) xpos = 625.0f;
            angleValue = 225.0f;
        }
        break;
    case 7: case 8:
        xpos = 0.5f * sx;
        if (index == 0) {
            xpos += 160.0f;
            if (xpos < 10.0f) xpos = 10.0f;
            else if (xpos > 310.0f) xpos = 310.0f;
            angleValue = 225.0f;
        } else if (index == 1) {
            xpos += 330.0f;
            if (xpos < 330.0f) xpos = 330.0f;
            else if (xpos > 630.0f) xpos = 630.0f;
            angleValue = 225.0f;
        } else if (index == 2) {
            xpos += 160.0f;
            if (xpos < 10.0f) xpos = 10.0f;
            else if (xpos > 310.0f) xpos = 310.0f;
        } else if (index == 3) {
            xpos += 330.0f;
            if (xpos < 330.0f) xpos = 330.0f;
            else if (xpos > 630.0f) xpos = 630.0f;
        }
        break;
    }

    maximum = __fabsf(sx);
    correction = __fabsf(sy);
    if (maximum <= correction) maximum = correction;
    if (maximum > 0.8f) {
        ratio = 0.8f / maximum;
        xy[2] *= ratio;
        xy[1] *= ratio;
        correction = xy[2] - 0.2f * ratio;
        angle = (s16)(lbl_8006D24C(xy[1], correction) + 0x4000);
    } else {
        correction = xy[2] - 0.2f * maximum;
        angle = (s16)(lbl_8006D24C(xy[1], correction) + 0x4000);
    }

    for (i = 0; i < 22; i++) words[i] = ((u32 *)lbl_1_rodata_26F8)[i];
    for (i = 0; i < 22; i++) ((u32 *)(packetData))[i] = words[i];
    if (fn_1_485A8(0x94)) *(u32 *)(packetData + 4) = 0x94;
    else if (fn_1_485A8(0x97)) *(u32 *)(packetData + 4) = 0x97;

    opacity = 1.0504201650619507f + -delta * -0.010504201985895634f;
    if (opacity < 0.5f) opacity = 0.5f;
    else if (opacity > 1.0f) opacity = 1.0f;
    opacity *= angleValue;
    *(f32 *)(packetData + 8) = xpos;
    *(f32 *)(packetData + 12) = angleValue;
    *(f32 *)(packetData + 16) = 1.0f;
    *(s16 *)(packetData + 0x2c) = angle;
    *(f32 *)(packetData + 0x14) *= opacity;
    *(f32 *)(packetData + 0x18) *= opacity;
    *(u32 *)(packetData + 0x3c) = ((u32 *)&lbl_1_bss_89760)[2];
    *(u32 *)(packetData + 0x34) = 10;
    (void)ypos; (void)arg0; (void)yscale; (void)scale;
    fn_1_4F734(packet);
}
