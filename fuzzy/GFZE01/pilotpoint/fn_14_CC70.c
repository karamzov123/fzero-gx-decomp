/* Non-matching: best partial attempt (50.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/pilotpoint/pilotpoint.h"

struct fn_14_CC70_Copy88 { u32 a[22]; };

extern u32 lbl_1_rodata_26F8;
extern const f32 lbl_14_rodata_0;
extern u8 lbl_14_data_B4C[24];
extern u8 lbl_14_data_300C[0x1C];
extern u32 lbl_801A66B4;

extern void fn_1_50164(void *, f32, f32, f32, f32);
extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(void *, u32, s16, s16);
extern void fn_1_4965C(u8);
extern void fn_1_49514(u32 *);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_5233C(void);

#define F(off) (*(const f32 *)(pool + (off)))
#define D(off) (*(const f64 *)(pool + (off)))

void fn_14_CC70(u32 arg0) {
    struct fn_14_CC70_Copy88 p;
    u32 i;
    u32 *bss;
    u8 *pool;
    f64 t;
    f32 x;
    f32 y;
    u32 v;

    bss = (u32 *)&lbl_14_bss_0;
    pool = (u8 *)&lbl_14_rodata_0;
    p = *(struct fn_14_CC70_Copy88 *)&lbl_1_rodata_26F8;

    t = (f64)(s32)arg0 - D(0x60);
    *(u32 *)((u8 *)&p + 0x34) = 10;
    *(f32 *)((u8 *)&p + 0x10) = F(0x35c);
    if (t > D(0x4a0)) {
        x = (f32)((f64)(240 - arg0) - D(0x60)) / F(0x10);
        x = x * x;
        *(f32 *)((u8 *)&p + 0x14) = F(0x10);
        *(f32 *)((u8 *)&p + 0x18) = F(0x460);
        fn_1_50164(&p, F(0xdc) * x, F(0x4a8) * x, F(0x18), F(0x18));
        goto done;
    }
    if (t > D(0xc8)) {
        if (D(0x4a0) == (f64)(s32)arg0 - D(0x60))
            fn_1_A2D84(0xA9110100);
        *(f32 *)((u8 *)&p + 0x14) = F(0x10);
        *(f32 *)((u8 *)&p + 0x18) = F(0x460);
        fn_1_50164(&p, F(0xdc), F(0x4a8), F(0x18), F(0x18));
        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_49590(F(0xb0));
        fn_1_495C8(9);
        fn_1_4955C(F(0x158), F(0x158));
        fn_1_496FC(F(0x10), F(0x4ac));
        fn_1_4AE0C((const char *)lbl_14_data_300C, lbl_14_data_B4C[4 * lbl_801A66B4]);

        if ((f64)(s32)arg0 - D(0x60) < D(0x4b0) &&
            (f64)(s32)arg0 - D(0x60) > D(0x4b8)) {
            p = *(struct fn_14_CC70_Copy88 *)&lbl_1_rodata_26F8;
            t = (f64)(s32)arg0 - D(0x60) - D(0x4b8);
            x = (f32)(t / D(0x100)) - F(0xb0);
            x = (F(0x4c0) - x) * F(0x220);
            *(u32 *)((u8 *)&p + 0x10) = 0x0000942d;
            *(f32 *)((u8 *)&p + 0x14) = F(0x10);
            *(f32 *)((u8 *)&p + 0x18) = x * F(0x1e4) * x;
            *(f32 *)((u8 *)&p + 0x1c) = F(0x4cc);
            *(u32 *)((u8 *)&p + 0x40) = 10;
            fn_1_4F734((FontDrawPacket *)&p);
        }
    }

    if ((f64)(s32)arg0 - D(0x60) > D(0x4d0)) {
        fn_1_4955C(F(0x158), F(0x158));
        fn_1_496FC(F(0x10), F(0x4c8));
        fn_1_4AE0C((const char *)lbl_14_data_300C, (const char *)bss + 0x6c);
        p = *(struct fn_14_CC70_Copy88 *)&lbl_1_rodata_26F8;
        *(u32 *)((u8 *)&p + 0x10) = 0x000094fd;
        fn_1_51564(0, 0, 0x14, 0x14, 10, 4);
        v = bss[0x104 / 4];
        x = (f32)(v % 10);
        y = (f32)(v / 10);
        fn_1_5158C(&p, *(u32 *)((u8 *)&p + 0x10), (s16)x, (s16)y);
        *(f32 *)((u8 *)&p + 0x14) = F(0x4d8);
        *(f32 *)((u8 *)&p + 0x18) = F(0x4c8);
        *(f32 *)((u8 *)&p + 0x1c) = F(0xf0);
        *(u32 *)((u8 *)&p + 0x40) = 10;
        fn_1_4F734((FontDrawPacket *)&p);
        *(f32 *)((u8 *)&p + 0x14) = F(0x4dc);
        fn_1_4F734((FontDrawPacket *)&p);
    } else {
        fn_1_4965C(2);
        fn_1_496FC(F(0x10), F(0x4c8));
        fn_1_4955C(F(0x158), F(0x158));
        v = *(u32 *)((u8 *)&lbl_14_rodata_0 + 0x498);
        fn_1_49514(&v);
        fn_1_4AE0C((const char *)lbl_14_data_300C, (const char *)bss + 0xac);
        fn_1_4965C(0);
        v = *(u32 *)((u8 *)&lbl_14_rodata_0 + 0x49c);
        fn_1_49514(&v);
        p = *(struct fn_14_CC70_Copy88 *)&lbl_1_rodata_26F8;
        *(u32 *)((u8 *)&p + 0x10) = 0x00009400;
        fn_1_51564(0, 0, 0x14, 0x14, 10, 4);
        v = bss[0x108 / 4];
        x = (f32)(v % 10);
        y = (f32)(v / 10);
        fn_1_5158C(&p, *(u32 *)((u8 *)&p + 0x10), (s16)x, (s16)y);
        *(f32 *)((u8 *)&p + 0x14) = F(0x4d8);
        *(f32 *)((u8 *)&p + 0x18) = F(0x4c8);
        *(f32 *)((u8 *)&p + 0x1c) = F(0xf0);
        *(u32 *)((u8 *)&p + 0x40) = 10;
        fn_1_4F734((FontDrawPacket *)&p);
        *(f32 *)((u8 *)&p + 0x14) = F(0x4dc);
        fn_1_4F734((FontDrawPacket *)&p);
    }
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(F(0x1e4));
    p = *(struct fn_14_CC70_Copy88 *)&lbl_1_rodata_26F8;
    *(u32 *)((u8 *)&p + 0x10) = 0x00009202;
    x = (f32)(((f64)(s32)arg0 - D(0x60) - D(0x4e8)) / D(0xc8));
    if (x < F(0)) x = F(0);
    else if (x > F(0x30)) x = F(0x30);
    y = F(0x30) - x;
    *(u32 *)((u8 *)&p + 0x40) = 10;
    *(f32 *)((u8 *)&p + 0x20) = F(0x30) + F(0x220) * x;
    *(f32 *)((u8 *)&p + 0x24) = F(0x30) + F(0x220) * x;
    *(f32 *)((u8 *)&p + 0x3c) = y * y;
    fn_1_4F734((FontDrawPacket *)&p);
    goto done;

done:
    return;
}
