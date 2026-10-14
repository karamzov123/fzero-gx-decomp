/* Non-matching: best partial attempt (92.02% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

struct fn_14_D2EC_Copy88 {
    u8 f_04;
    f32 f_08;
    f32 f_0c;
    f32 f_10;
    f32 f_14;
    f32 f_18;
    u8 pad_18[0x14];
    f32 f_30;
    u32 f_34;
    u8 pad_38[0x24];
};

extern struct fn_14_D2EC_Copy88 lbl_1_rodata_26F8;
extern u8 lbl_14_rodata_0[];
extern void *lbl_14_data_BD4[6];
extern u32 lbl_801A66B4;

extern void fn_1_50164(void *, f32, f32, f32, f32, f32);
extern u16 fn_1_A2D84(u32);
extern u8 fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_5233C(void);

#define PF32(off) (*(f32 *)(pool + (off)))
#define PF64(off) (*(f64 *)(pool + (off)))

#pragma opt_propagation off
#pragma opt_dead_assignments off
u16 fn_14_D2EC(u32 arg0) {
    f32 fzgx_value_;
    f32 fzgx_value;
    u8 *pool = (u8 *)&lbl_14_rodata_0;
    struct fn_14_D2EC_Copy88 local;
    f32 s;
    struct { f32 value; } t;
    f32 v;

    local = lbl_1_rodata_26F8;
    local.f_04 = 0x9E2B;
    local.f_34 = 10;
    fzgx_value = PF32(0x35c);
    local.f_10 = fzgx_value;

    if ((f64)(s32)arg0 > PF64(0x4a0)) {
        local.f_08 = PF32(0x10);
        local.f_0c = PF32(0x460);
        s = (f32)((f32)(s32)(0xF0 - arg0) / PF64(0xc8));
        local.f_30 = s;
        local.f_30 = s * s;
        fn_1_50164(&local.f_04, PF32(0xdc) * (s * s), PF32(0x4a8) * (s * s), PF32(0x18),
                   PF32(0x18), s);
    } else {
        if ((f64)(s32)arg0 > PF64(0xc8)) {
            if ((f64)(s32)arg0 == PF64(0x4a0)) {
                return fn_1_A2D84(0xA9110300);
            }
            local.f_08 = PF32(0x10);
            local.f_0c = PF32(0x460);
            fn_1_50164(&local.f_04, PF32(0xdc), PF32(0x4a8), PF32(0x18), PF32(0x18), s);
            fn_1_49410();
            fn_1_495FC();
            fn_1_495B0(0x80000000);
            fn_1_49590(PF32(0xb0));
            fn_1_495C8(9);
            fn_1_4955C(PF32(0x330), PF32(0x330));
            fn_1_496FC(PF32(0x10), PF32(0x4f0));
            fn_1_4AE0C(lbl_14_data_BD4[lbl_801A66B4]);
            fn_1_49738(fn_1_5233C);
            fn_1_49748(PF32(0x1e4));

            local = lbl_1_rodata_26F8;
            local.f_04 = 0x9200;
            local.f_10 = PF32(0x374);
            local.f_08 = PF32(0x10);
            local.f_0c = PF32(0x4e0);
            t.value = (f32)((f32)((f64)(s32)arg0 - PF64(0x4e8)) / PF64(0xc8));
            if (t.value < PF32(0x0)) {
                t.value = PF32(0x0);
            } else if (t.value > PF32(0x30)) {
                t.value = PF32(0x30);
            }
            local.f_34 = 10;
            fzgx_value_ = (PF32(0x30) - t.value) * (PF32(0x30) - t.value);
            local.f_30 = fzgx_value_;
            v = PF32(0x30) + (f32)(PF32(0x220) * t.value);
            local.f_14 = v;
            local.f_18 = v;
            fn_1_4F734((FontDrawPacket *)&local.f_04);
        } else {
            s = (f32)((f32)(s32)arg0 / PF64(0xc8));
            local.f_08 = PF32(0x10);
            local.f_0c = PF32(0x460);
            local.f_30 = s;
            local.f_30 = s * s;
            fn_1_50164(&local.f_04, PF32(0xdc) * (s * s), PF32(0x4a8) * (s * s), PF32(0x18),
                       PF32(0x18), s);
        }
    }
    return (u32)pool;
}
#pragma opt_dead_assignments reset

#pragma opt_propagation reset

