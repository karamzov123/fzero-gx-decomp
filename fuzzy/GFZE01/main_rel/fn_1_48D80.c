/* Non-matching: best partial attempt (28.76% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/font.h"

struct RenderArg {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    s16 unk_28;
    u16 unk_2A;
    f32 unk_2C;
    u32 unk_30;
    f32 unk_34;
    u8 unk_38, unk_39, unk_3A, unk_3B;
    u32 unk_3C;
    u8 unk_40[0x10];
    void (*callback)(struct RenderArg *, void *);
};
struct Pool {
    u8 pad[0xF0];
    f32 zero;
    u8 padF4[4];
    f64 half;
    f32 three_quarters;
    f32 one;
    f32 byte_scale;
    u8 pad10C[4];
    f64 two52;
};
extern struct Pool lbl_1_rodata_FD0;
extern u8 lbl_1_bss_40C6C[];
extern void fn_1_4E638(s32);
extern u32 fn_1_A6F1C(void);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E1B0(void *);
extern void fn_1_492F0(struct RenderArg *, void *);
extern void fn_80073778(void *, s32);
extern void fn_800371F8(s32, void *);
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_8003462C(u32, u32, u32);
extern void fn_1_4E0F4(void);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern void fn_80074188(u32, u32, u32, u32);
extern void mathutil_mtxA_rotate_z(s32);
extern volatile f32 *__WGRegs;

void fn_1_48D80(struct RenderArg *arg) {
    f32 v[4][3];
    u32 color1, color2, selector;
    f32 x, y, nx, ny;
    u32 index;
    u8 *entry;
    u32 flags;
    u32 *fifo = (u32 *)__WGRegs;
    fn_1_4E638(arg->unk_30 & 0x40000);
    selector = arg->unk_0;
    index = selector & 0xffff;
    entry = (u8 *)&lbl_1_data_1A3B8 + 0xaf0 + (((selector >> 16) & 0xff) * 0x38);
    color1 = ((u32)entry[4] << 24) | ((u32)entry[5] << 16);
    color2 = 0;
    x = (f32)entry[4] - 4503599627370496.0;
    y = (f32)entry[5] - 4503599627370496.0;
    flags = arg->unk_30 & 3;
    nx = -arg->unk_C;
    if (flags == 2) {
        v[3][0] = nx * lbl_1_rodata_FD0.half;
        v[2][0] = -nx * lbl_1_rodata_FD0.half;
    } else if (flags == 3) {
        v[3][0] = 0.0f;
        v[2][0] = -nx;
    } else {
        v[3][0] = nx;
        v[2][0] = 0.0f;
    }
    v[0][0] = v[2][0];
    v[1][0] = v[3][0];
    flags = (arg->unk_30 >> 2) & 3;
    if (flags == 2) {
        v[3][1] = y * lbl_1_rodata_FD0.half;
        v[2][1] = -y * lbl_1_rodata_FD0.half;
    } else if (flags == 3) {
        v[3][1] = 0.0f;
        v[2][1] = -y;
    } else {
        v[3][1] = y;
        v[2][1] = 0.0f;
    }
    v[0][1] = v[2][1];
    v[1][1] = v[3][1];
    v[0][2] = v[1][2] = v[2][2] = v[3][2] = 0.0f;
    if ((arg->unk_30 & 0x8000000) && (fn_1_A6F1C() == 1 || fn_1_A6F1C() == 2)) {
        lbl_8006D7F4(arg->unk_34, 0.0f, 0.0f);
        lbl_8006E15C(0.75f, 1.0f, 1.0f);
        {
            f32 z = -arg->unk_34;
            f32 *m = (f32 *)0xE0000000;
            m[3] = m[0] * z + m[3];
            m[7] = m[4] * z + m[7];
            m[11] = m[8] * z + m[11];
        }
        lbl_8006E0B4(arg->unk_4, arg->unk_8, 0.0f);
    } else {
        lbl_8006D7F4(arg->unk_4, arg->unk_8, 0.0f);
    }
    mathutil_mtxA_rotate_z(-(s32)arg->unk_34);
    lbl_8006E15C(arg->unk_10, arg->unk_14, 1.0f);
    lbl_8006E1B0(&v[0]);
    lbl_8006E1B0(&v[1]);
    lbl_8006E1B0(&v[2]);
    lbl_8006E1B0(&v[3]);
    fn_1_492F0(arg, v);
    fn_80073778(&lbl_1_bss_40C6C[index * 0x20], 0);
    if (arg->unk_30 & 0x10000000) {
        u32 c = ((u32)arg->unk_38 << 24) | ((u32)arg->unk_39 << 16) |
                ((u32)arg->unk_3A << 8) | (u32)(u8)(255.0f * arg->unk_2C);
        fn_800371F8(1, &c);
        fn_800371F8(2, &arg->unk_3C);
    } else {
        u32 c1 = (u32)(u8)(255.0f * arg->unk_2C);
        u32 c2 = ((u32)(u8)(arg->unk_38 + ((u8 *)&arg->unk_3C)[0]) << 24) |
                 ((u32)(u8)(arg->unk_39 + ((u8 *)&arg->unk_3C)[1]) << 16) |
                 ((u32)(u8)(arg->unk_3A + ((u8 *)&arg->unk_3C)[2]) << 8);
        fn_800371F8(1, &c1);
        fn_800371F8(2, &c2);
    }
    if (arg->unk_30 & 0x4000000) {
        if (arg->callback != 0) {
            arg->callback(arg, v);
        } else {
            OSPanic((char *)&lbl_1_data_1A3B8 + 0x1910, 0x2e4,
                    (char *)&lbl_1_data_1A3B8 + 0x199c);
        }
    }
    fn_8003462C(0x80, 7, 4);
    *fifo++ = *(u32 *)&v[0][0]; *fifo++ = *(u32 *)&v[0][1];
    *fifo++ = *(u32 *)&nx; *fifo++ = *(u32 *)&arg->unk_18; *fifo++ = *(u32 *)&arg->unk_1C;
    *fifo++ = *(u32 *)&v[1][0]; *fifo++ = *(u32 *)&v[1][1];
    *fifo++ = *(u32 *)&nx; *fifo++ = *(u32 *)&arg->unk_20; *fifo++ = *(u32 *)&arg->unk_1C;
    *fifo++ = *(u32 *)&v[3][0]; *fifo++ = *(u32 *)&v[3][1];
    *fifo++ = *(u32 *)&nx; *fifo++ = *(u32 *)&arg->unk_20; *fifo++ = *(u32 *)&arg->unk_24;
    *fifo++ = *(u32 *)&v[2][0]; *fifo++ = *(u32 *)&v[2][1];
    *fifo++ = *(u32 *)&nx; *fifo++ = *(u32 *)&arg->unk_18; *fifo++ = *(u32 *)&arg->unk_24;
    if (arg->unk_30 & 0x4000000) {
        fn_1_4E0F4();
        color1 = fn_1_A5DB0();
        color2 = fn_1_A5D88();
        fn_80074188(0, 0, color2, color1);
    }
}
