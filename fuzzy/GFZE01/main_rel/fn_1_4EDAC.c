/* Non-matching: best partial attempt (95.18% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "psvec.h"

typedef struct PacketVec {
    f32 x, y, z;
} PacketVec;

typedef struct PacketColor {
    u8 r, g, b, a;
} PacketColor;

struct Struct_801A6D00 {
    u8 pad_0[0x98];
    PacketVec points[4];
    u8 unk_c8[0xce];
    u8 unk_197;
};

struct fn_1_4EDAC_lbl_801A6D00 {
    struct Struct_801A6D00 *unk_0;
};

extern struct fn_1_4EDAC_lbl_801A6D00 lbl_801A6D00;

struct FontDrawPacketOffsets {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_c;
    f32 scale_x;
    f32 scale_y;
    f32 tex_u0;
    f32 tex_v0;
    f32 tex_u1;
    f32 tex_v1;
    s16 rot_z;
    s16 rot_y;
    f32 alpha;
    u32 flags;
    f32 unk_34;
    u8  color1_r;
    u8  color1_g;
    u8  color1_b;
    u8  pad_3b;
    PacketColor color2;
    u8  pad_40[0xc];
    void *unk_4c;
    void (*callback)(void *, void *);
};

extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(void *, f32, f32, f32, f32);
extern void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_80074660(u32);
extern void fn_80073678(u32);
extern void fn_1_4E220(void *, u32, u32, u32, u32);
extern s32 fn_1_A6F1C(void);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E0B4(f32, f32, f32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void lbl_8006E1B0(void *, void *);
extern u32 fn_1_492F0(void *, void *);
extern s32 fn_1_486F8(u32);
extern void fn_800371F8(s32, PacketColor);
extern void fn_8003462C(u32, u32, u32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800724C8(void);
extern void fn_8007245C(u32);
extern void fn_80074788(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800728A8(s32, s32, s32, s32);
extern u32 fn_800720B0(u32);
extern void fn_80072864(u32);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern u32 fn_80074188(u32, u32, u32, u32);

static inline void GXPosition3f32(f32 x, f32 y, f32 z) {
    *(volatile f32 *)0xCC008000 = x;
    *(volatile f32 *)0xCC008000 = y;
    *(volatile f32 *)0xCC008000 = z;
}

static inline void GXTexCoord2f32(f32 s, f32 t) {
    *(volatile f32 *)0xCC008000 = s;
    *(volatile f32 *)0xCC008000 = t;
}

void fn_1_4EDAC(FontDrawPacket *packet_arg, f32 arg1, f32 arg2) {
    #define packet ((struct FontDrawPacketOffsets *)packet_arg)
    PacketColor c2;
    PacketColor c1;
    u32 is_perspective;
    PacketVec *points;
    f32 pos_x;
    f32 pos_y;
    f32 neg_c;
    f32 tex_u0;
    f32 tex_u1;
    f32 tex_v0;
    f32 tex_v1;

    points = lbl_801A6D00.unk_0->points;
    is_perspective = (packet->flags >> 18) & 1;

    points[0].x = 0.0f; points[0].y = 0.0f; points[0].z = 0.0f;
    points[1].x = 0.0f; points[1].y = 0.0f; points[1].z = 0.0f;
    points[2].x = 0.0f; points[2].y = 0.0f; points[2].z = 0.0f;
    points[3].x = 0.0f; points[3].y = 0.0f; points[3].z = 0.0f;

    if (is_perspective) {
        C_MTXPerspective(&lbl_801A6D00.unk_0->unk_c8, 55.0f, fn_1_A6FE8(), 0.1f, 90000.0f);
        fn_800737E4(&lbl_801A6D00.unk_0->unk_c8, 0);
    } else {
        C_MTXOrtho(&lbl_801A6D00.unk_0->unk_c8, 0.0f, 480.0f, 0.0f, 640.0f, 0.0f, 90000.0f);
        fn_800737E4(&lbl_801A6D00.unk_0->unk_c8, 1);
    }

    lbl_801A6D00.unk_0->unk_197 = is_perspective;
    if ((packet->flags & 0x01000000) && packet->unk_4c != 0) {
        fn_80074660(2);
        fn_80073678(2);
        fn_1_4E220(packet->unk_4c, 1, 1, 1, 0x21);
    } else {
        fn_80073678(1);
    }

    pos_x = packet->unk_4;
    pos_y = packet->unk_8;
    neg_c = -packet->unk_c;
    tex_u0 = packet->tex_u0;
    tex_u1 = packet->tex_u1;
    tex_v0 = packet->tex_v0;
    tex_v1 = packet->tex_v1;

    switch (packet->flags & 3) {
    default:
        points[2].x = 0.0f;
        points[0].x = 0.0f;
        points[3].x = arg1;
        points[1].x = arg1;
        break;
    case 2:
        points[2].x = -arg1 * 0.5;
        points[0].x = -arg1 * 0.5;
        points[3].x = arg1 * 0.5;
        points[1].x = arg1 * 0.5;
        break;
    case 3:
        points[2].x = -arg1;
        points[0].x = -arg1;
        points[3].x = 0.0f;
        points[1].x = 0.0f;
        break;
    }

    switch ((packet->flags >> 2) & 3) {
    default:
        points[1].y = 0.0f;
        points[0].y = 0.0f;
        points[3].y = arg2;
        points[2].y = arg2;
        break;
    case 2:
        points[1].y = -arg2 * 0.5;
        points[0].y = -arg2 * 0.5;
        points[3].y = arg2 * 0.5;
        points[2].y = arg2 * 0.5;
        break;
    case 3:
        points[1].y = -arg2;
        points[0].y = -arg2;
        points[3].y = 0.0f;
        points[2].y = 0.0f;
        break;
    }

    if ((packet->flags & 0x08000000) && (fn_1_A6F1C() == 1 || fn_1_A6F1C() == 2)) {
        lbl_8006D7F4(packet->unk_34, 0.0f, 0.0f);
        lbl_8006E15C(0.75f, 1.0f, 1.0f);
        lbl_8006E0B4(pos_x - packet->unk_34, pos_y, 0.0f);
    } else {
        lbl_8006D7F4(pos_x, pos_y, 0.0f);
    }

    if (packet->rot_z != 0) {
        mathutil_mtxA_rotate_z((s16)-packet->rot_z);
    }
    if (packet->rot_y != 0) {
        mathutil_mtxA_rotate_y((s16)-packet->rot_y);
    }

    lbl_8006E15C(packet->scale_x, packet->scale_y, 1.0f);
    lbl_8006E1B0(&points[0], &points[0]);
    lbl_8006E1B0(&points[1], &points[1]);
    lbl_8006E1B0(&points[2], &points[2]);
    lbl_8006E1B0(&points[3], &points[3]);
    fn_1_492F0(packet, points);

    if (is_perspective) {
        f32 scale = packet->unk_c * 0.002405626;
        points[0].x = (points[0].x - 320.0f) * scale;
        points[0].y = -((points[0].y - 240.0f) * scale);
        points[1].x = (points[1].x - 320.0f) * scale;
        points[1].y = -((points[1].y - 240.0f) * scale);
        points[2].x = (points[2].x - 320.0f) * scale;
        points[2].y = -((points[2].y - 240.0f) * scale);
        points[3].x = (points[3].x - 320.0f) * scale;
        points[3].y = -((points[3].y - 240.0f) * scale);
    }

    if (packet->flags & 0x00080000) {
        tex_u0 = packet->tex_u1;
        tex_u1 = packet->tex_u0;
    }
    if (packet->flags & 0x00100000) {
        tex_v0 = packet->tex_v1;
        tex_v1 = packet->tex_v0;
    }

    if (!(packet->flags & 0x00800000) && !(packet->flags & 0x10000000) && (fn_1_486F8(packet->unk_0) == 0 || fn_1_486F8(packet->unk_0) == 1)) {
        s32 sum;

        c1.r = 0;
        c1.g = 0;
        c1.b = 0;
        c1.a = packet->alpha * 255.0f;

        sum = packet->color1_r + packet->color2.r;
        c2.r = (sum < 255) ? sum : 255;

        sum = packet->color1_g + packet->color2.g;
        c2.g = (sum < 255) ? sum : 255;

        sum = packet->color1_b + packet->color2.b;
        c2.b = (sum < 255) ? sum : 255;

        c2.a = 0;

        fn_800371F8(1, c1);
        fn_800371F8(2, c2);
    } else {
        c1.r = packet->color1_r;
        c1.g = packet->color1_g;
        c1.b = packet->color1_b;
        c1.a = packet->alpha * 255.0f;

        fn_800371F8(1, c1);
        fn_800371F8(2, packet->color2);
    }

    if ((packet->flags & 0x04000000) && packet->callback != 0) {
        packet->callback(packet, points);
    }

    if (!is_perspective) {
        points[3].z = neg_c;
        points[2].z = neg_c;
        points[1].z = neg_c;
        points[0].z = neg_c;
    }

    fn_8003462C(0x80, 7, 4);

    GXPosition3f32(points[0].x, points[0].y, points[0].z);
    GXTexCoord2f32(tex_u0, tex_v0);

    GXPosition3f32(points[1].x, points[1].y, points[1].z);
    GXTexCoord2f32(tex_u1, tex_v0);

    GXPosition3f32(points[3].x, points[3].y, points[3].z);
    GXTexCoord2f32(tex_u1, tex_v1);

    GXPosition3f32(points[2].x, points[2].y, points[2].z);
    GXTexCoord2f32(tex_u0, tex_v1);

    fn_80072AB0(1, 0, 0);

    if ((packet->flags & 0x01000000) && packet->unk_4c != 0) {
        fn_800724C8();
        fn_8007245C(0x2200);
        fn_80074788(0);
        fn_80074660(1);
        fn_80073678(1);
        fn_80073898(0);
        fn_80073C6C(0);
        fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
        fn_800734A8(0, 0, 0, 0xff);
        fn_80072AB0(0, 0, 0);
        fn_80072C24(0, 0xf, 2, 8, 4);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 1, 4, 2);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        fn_80074918(1, 7, 0);
        fn_800728A8(1, 4, 5, 0);
        fn_800720B0(0);
        fn_80072864(2);
        fn_80074660(1);
        fn_80072AB0(1, 0, 0);
    }

    if (packet->flags & 0x04000000) {
        u32 v1;
        fn_800724C8();
        fn_8007245C(0x2200);
        fn_80074788(0);
        fn_80074660(1);
        fn_80073678(1);
        fn_80073898(0);
        fn_80073C6C(0);
        fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
        fn_800734A8(0, 0, 0, 0xff);
        fn_80072AB0(0, 0, 0);
        fn_80072C24(0, 0xf, 2, 8, 4);
        fn_80072D64(0, 0, 0, 0, 1, 0);
        fn_80072CC4(0, 7, 1, 4, 2);
        fn_80072E20(0, 0, 0, 0, 1, 0);
        fn_80074918(1, 7, 0);
        fn_800728A8(1, 4, 5, 0);
        fn_800720B0(0);
        fn_80072864(2);
        v1 = fn_1_A5DB0();
        fn_80074188(0, 0, fn_1_A5D88(), v1);
    }
    #undef packet
}
