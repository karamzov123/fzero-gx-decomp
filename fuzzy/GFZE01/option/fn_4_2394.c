/* Non-matching: best partial attempt (98.16% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

#include "dolphin/hw_regs.h"

/* fzgx-allow: A1 GX FIFO write port; retail materialises it as lis 0xcc01/stfs -0x8000 */
#define FIFO(v) (*(volatile f32 *)(GX_FIFO_BASE + 0x0) = (v)) /* Hardware access must remain ordered. */

extern u8 lbl_4_data_0[];
extern f32 lbl_4_rodata_0[0x65];
extern s32 lbl_801A66B4;

extern void fn_1_49410(void);
extern void fn_1_5233C(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_4955C(f32, f32);
extern int sprintf(char *, const char *, ...);
extern f32 fn_1_4B090(const char *);
extern void fn_800371F8(u32, const void *);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800746A8(u8, s32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);

#pragma opt_lifetimes off
#pragma opt_propagation off
void fn_4_2394(s32 arg0, u16 arg1, u16 arg2, s32 *arg3, s32 *arg4, s32 arg5) {
    const char *dfmt;
    struct { const f32 *value; } rod;
    s32 t1;
    s32 t2;
    char buf[0x40];
    f32 lo;
    f32 top;
    f32 mid;
    f32 scale;
    f32 center;
    f32 wid;
    u32 lab_t2;
    u32 lab_t1;

    dfmt = (const char *)lbl_4_data_0;
    rod.value = lbl_4_rodata_0;

    fn_1_49410();
    fn_1_49738(fn_1_5233C);
    fn_1_49748((*((0x12) + (rod.value))));
    fn_1_4955C((*((0x31) + (rod.value))), (*((0x31) + (rod.value))));

    if (lbl_801A66B4 == 5) {
        sprintf(buf, dfmt + 0x14C4, arg0, arg5);
        top = (*((0x5F) + (rod.value)));
    } else {
        sprintf(buf, dfmt + 0x1210, arg0, arg5);
        top = (*((0x60) + (rod.value)));
    }
    center = (*((0x61) + (rod.value)));
    scale = (*((0x2) + (rod.value))) * ((*((0x4A) + (rod.value))) + fn_1_4B090(buf));
    wid = (*((0x46) + (rod.value))) * (f32)arg2;

    if (arg1 != 0) {
        center = center - ((*((0x62) + (rod.value))) + scale);
    } else {
        center = center + ((*((0x62) + (rod.value))) + scale);
    }

    t1 = *arg4;
    fn_800371F8(1, &t1);
    lab_t2 = 4;
    fn_8003462C(0x80, 7, lab_t2);

    lo = center - scale;
    scale = center + scale;
    mid = (*((0x14) + (rod.value))) - top;
    top = (*((0x14) + (rod.value))) + top;

    FIFO(mid);
    FIFO(lo);
    FIFO(wid);
    FIFO(top);
    FIFO(lo);
    FIFO(wid);
    FIFO(top);
    FIFO(scale);
    FIFO(wid);
    FIFO(mid);
    FIFO(scale);
    FIFO(wid);
    fn_800746A8(0xA, 0);

    t2 = *arg3;
    fn_800371F8(1, &t2);
    lab_t2 = 2;
    fn_8003462C(0xA8, 7, lab_t2);
    FIFO(mid);
    FIFO(lo);
    FIFO(wid);
    FIFO(top);
    FIFO(lo);
    FIFO(wid);
    lab_t2 = 2;
    lab_t1 = 7;
    fn_8003462C(0xA8, lab_t1, lab_t2);
    FIFO(top);
    FIFO(lo);
    FIFO(wid);
    FIFO(top);
    FIFO(scale);
    FIFO(wid);
    lab_t2 = 2;
    fn_8003462C(0xA8, 7, lab_t2);
    FIFO(top);
    FIFO(scale);
    FIFO(wid);
    FIFO(mid);
    FIFO(scale);
    FIFO(wid);
    lab_t2 = 2;
    fn_8003462C(0xA8, 7, lab_t2);
    FIFO(mid);
    FIFO(scale);
    FIFO(wid);
    FIFO(mid);
    FIFO(lo);
    FIFO(wid);

    if (lbl_801A66B4 == 5) {
        fn_1_495C8(9);
        fn_1_496FC((*((0x14) + (rod.value))), center);
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590((*((0x2) + (rod.value))));
        }
        fn_1_4A0D8(buf);
    } else {
        fn_1_495C8(8);
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590((*((0x2) + (rod.value))));
        }
        fn_1_496FC((*((0x63) + (rod.value))), center);
        fn_1_4A0D8(buf);
        fn_1_496FC((*((0x64) + (rod.value))), center);
        fn_1_4AE0C(dfmt + 0x14CC, arg5);
    }
}
#pragma opt_propagation reset

#pragma opt_lifetimes reset

