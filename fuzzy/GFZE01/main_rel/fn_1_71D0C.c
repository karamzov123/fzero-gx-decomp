/* Non-matching: best partial attempt (60.98% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/effect.h"

typedef struct { u32 x, y, z; } Sig_fn_1_862D4_Triple;
struct Arg0 { u8 pad[0x18]; s16 mode; };
struct Pool {
    u8 pad0[0x3ac];
    u32 c0, c1, c2;
    u32 d0, d1, d2;
    u32 e0, e1, e2;
    u32 f0, f1, f2;
    u32 g0, g1, g2;
    u32 h0, h1, h2;
    u32 i0, i1, i2;
    u32 j0, j1, j2;
    u32 k0, k1, k2;
    u32 m0, m1, m2;
};
struct Vec { f32 x, y, z; };
struct Obj { u8 bytes[0xe8]; };
struct State { u32 value; };
extern struct Pool lbl_1_rodata_2D70;
extern struct State lbl_801A63C0;
extern void fn_1_862D4(s16, Sig_fn_1_862D4_Triple *);
extern u8 fn_1_58C4(void);
extern s16 camera_get_mode(void);
extern u32 fn_1_584AC(void);
extern void *memset(void *, int, u32);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern f32 lbl_8006D668(void *);
extern s16 fn_1_59078(Obj_1_bss_6C84C_Target *);

void fn_1_71D0C(struct Arg0 *arg0, void *arg1) {
    struct Pool *pool = &lbl_1_rodata_2D70;
    struct State *state = &lbl_801A63C0;
    Sig_fn_1_862D4_Triple pos;
    struct Obj obj;
    struct Vec vec;
    struct Vec out;
    struct Vec axis;
    struct Vec cross;
    struct Vec jitter;
    s16 mode;
    s32 count;
    u32 a, b, c, d, e;
    u32 random;
    f64 conv;
    f32 angle, scale, radius, height, width, length;
    u32 stateval;
    fn_1_862D4(arg0->mode, &pos);
    memset(&obj, 0, 0xe8);
    *(s16 *)(obj.bytes + 0x18) = arg0->mode;
    *(s16 *)(obj.bytes + 0x0c) = 16;
    *(u32 *)(obj.bytes + 0x38) = *(u32 *)((u8 *)arg0 + 0x38);
    *(s16 *)(obj.bytes + 0x1a) = -1;
    *(s16 *)(obj.bytes + 0x58) = *(s16 *)((u8 *)arg0 + 0x58);
    mode = fn_1_58C4();
    count = 9;
    if (mode >= 2 || arg0->mode != camera_get_mode()) count = 3;
    do {
        u32 n = (u8)count;
        *(s16 *)(obj.bytes + 0xb2) = 1;
        *(u32 *)(obj.bytes + 0x14) = n % 3;
        lbl_8006DC6C((u8 *)arg0 + 0xb8);
        *(f32 *)0xE000000C = *(f32 *)&pos.x;
        *(f32 *)0xE000001C = *(f32 *)&pos.y;
        *(f32 *)0xE000002C = *(f32 *)&pos.z;
        switch (*(u32 *)(obj.bytes + 0x14)) {
        case 0:
            vec.x = *(f32 *)((u8 *)pool + 0x3ac);
            vec.y = *(f32 *)((u8 *)pool + 0x3b0);
            vec.z = *(f32 *)((u8 *)pool + 0x3b4);
            break;
        case 1:
            vec.x = *(f32 *)((u8 *)pool + 0x3b8);
            vec.y = *(f32 *)((u8 *)pool + 0x3bc);
            vec.z = *(f32 *)((u8 *)pool + 0x3c0);
            break;
        default:
            vec.x = *(f32 *)((u8 *)pool + 0x3c4);
            vec.y = *(f32 *)((u8 *)pool + 0x3c8);
            vec.z = *(f32 *)((u8 *)pool + 0x3cc);
            break;
        }
        lbl_8006E1B0(&vec);
        a = fn_1_584AC();
        b = fn_1_584AC();
        c = fn_1_584AC();
        random = c & 0xffff;
        conv = (f64)(0x43300000 | random) - 4503599627370496.0;
        *(s16 *)(obj.bytes + 0x54) = (s16)(16.0f + 4096.0f * ((f32)random / 32767.0f));
        d = fn_1_584AC();
        stateval = state->value * (0x676a4b6b) + 0x33cb;
        state->value = stateval;
        *(f32 *)(obj.bytes + 0x64) = 1.5f;
        *(s16 *)(obj.bytes + 0x56) = (s16)(16.0f + 4096.0f * ((f32)(d & 0xffff) / 32767.0f));
        *(f32 *)(obj.bytes + 0x60) = 2.0f * (0.4f + 0.6f * (f32)(((f64)(stateval & 0x7fff) - 4503601774854144.0) / 32767.0f));
        mathutil_mtxA_rotate_y(*(s16 *)(obj.bytes + 0x56));
        mathutil_mtxA_rotate_x(*(s16 *)(obj.bytes + 0x54));
        vec.x = *(f32 *)((u8 *)pool + 0x3d0);
        vec.y = *(f32 *)((u8 *)pool + 0x3d4);
        vec.z = -(*(f32 *)((u8 *)pool + 0x3d8));
        lbl_8006E1B0(&vec);
        out.x = 0.5f * (vec.x + pos.x);
        out.y = 0.5f * (vec.y + pos.y);
        out.z = 0.5f * (vec.z + pos.z);
        *(f32 *)(obj.bytes + 0x68) = *(f32 *)((u8 *)arg0 + 0x48);
        *(f32 *)(obj.bytes + 0x6c) = *(f32 *)((u8 *)arg0 + 0x4c);
        *(f32 *)(obj.bytes + 0x70) = *(f32 *)((u8 *)arg0 + 0x50);
        a = fn_1_584AC();
        *(f32 *)(obj.bytes + 0x68) += 0.25f * ((f32)(a & 0xffff) / 32767.0f - 0.5f);
        b = fn_1_584AC();
        *(f32 *)(obj.bytes + 0x6c) += 0.25f * ((f32)(b & 0xffff) / 32767.0f - 0.5f);
        c = fn_1_584AC();
        *(f32 *)(obj.bytes + 0x70) += 0.25f * ((f32)(c & 0xffff) / 32767.0f - 0.5f);
        d = fn_1_584AC();
        angle = 0.5f + 0.2f * ((f32)(d & 0xffff) / 32767.0f);
        *(f32 *)(obj.bytes + 0x2c) = 128.0f * (0.5f + angle) / 255.0f;
        *(f32 *)(obj.bytes + 0x30) = 224.0f * (0.5f + angle) / 255.0f;
        *(f32 *)(obj.bytes + 0x34) = 255.0f * (0.5f * (1.0f + angle)) / 255.0f;
        axis.x = *(f32 *)((u8 *)arg0 + 0x48);
        axis.y = *(f32 *)((u8 *)arg0 + 0x4c);
        axis.z = *(f32 *)((u8 *)arg0 + 0x50);
        cross.x = axis.y * *(f32 *)(obj.bytes + 0x70) - axis.z * *(f32 *)(obj.bytes + 0x6c);
        cross.y = axis.z * *(f32 *)(obj.bytes + 0x68) - axis.x * *(f32 *)(obj.bytes + 0x70);
        cross.z = axis.x * *(f32 *)(obj.bytes + 0x6c) - axis.y * *(f32 *)(obj.bytes + 0x68);
        e = fn_1_584AC();
        jitter.x = cross.x + 0.4f * ((f32)(e & 0xffff) / 32767.0f - 0.5f);
        a = fn_1_584AC();
        jitter.y = cross.y + 0.4f * ((f32)(a & 0xffff) / 32767.0f - 0.5f);
        b = fn_1_584AC();
        jitter.z = cross.z + 0.4f * ((f32)(b & 0xffff) / 32767.0f - 0.5f);
        lbl_8006D668(&jitter);
        *(s16 *)(obj.bytes + 0xac) = 24;
        fn_1_59078((Obj_1_bss_6C84C_Target *)&obj);
        count--;
    } while ((u8)count != 0);
}
