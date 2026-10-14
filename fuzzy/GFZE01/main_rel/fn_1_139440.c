/* Non-matching: best partial attempt (68.75% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/burner.h"

typedef struct {
    f32 field_0;
    f32 divisor;
    f32 x;
    f32 y;
    u8 pad_10[0x30];
    f32 limit;
} Sig_fn_1_229EC_fn_1_229EC_ctrl;

extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_87DC;
extern const f32 lbl_1_rodata_88B8;
extern const f32 lbl_1_rodata_8B98;
extern const f64 lbl_1_rodata_8600;
extern u32 lbl_1_rodata_8B88, lbl_1_rodata_8B8C, lbl_1_rodata_8B90, lbl_1_rodata_8B94;
extern u32 lbl_801A66A0;
extern Obj_1_data_28060 lbl_1_data_28060;

extern int fn_1_139A3C(int);
extern u8 *fn_1_36AD0(void);
extern void fn_1_14FC80(s16, void *);
extern void *fn_1_22B10(void *, f32);
extern void fn_1_229EC(Sig_fn_1_229EC_fn_1_229EC_ctrl *, f32 *, f32 *);
extern u32 fn_1_539CC(void *, void *, f32);
extern void fn_1_A9868(void);
extern void fn_1_AA350(void *, void *, void *, u32);
extern void fn_1_AA538(void);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_800724C8(void);
extern void fn_8007245C(u32);
extern void fn_80074788(u32);
extern void fn_80074660(u32);
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800720B0(u32);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);

void fn_1_139440(u32 arg0, u32 arg1, u32 arg2, u32 arg3, s16 arg4, s16 arg5, f32 arg6) {
    s16 id = arg5;
    s16 active_id;
    s32 valid;
    s32 i;
    s32 offset;
    s32 value;
    s32 rem;
    s32 out_value;
    u8 selected;
    f32 frac;
    f32 time;
    f32 result;
    f32 input0 = lbl_1_rodata_861C;
    f32 input1 = lbl_1_rodata_861C;
    Sig_fn_1_229EC_fn_1_229EC_ctrl ctl;
    s32 colors[2];
    s32 data0[2];
    s32 data1[2];
    s32 data2[2];
    struct { u32 a[183]; } output_id;
    struct { u32 a[151]; } output_time;
    struct { u32 a[602]; } output;
    
    active_id = id;
    if ((lbl_1_bss_8B3A0.unk_94 & 0x40000000) != 0)
        active_id = 0;
    valid = fn_1_139A3C((s16)active_id);
    if (arg4 < 41) {
        fn_80008BA8(&ctl, (u8 *)&lbl_1_data_28060 + arg4 * 180, 180);
    } else {
        s32 index = (s32)id * (0x10000 - 32320);
        if ((*(u32 *)(fn_1_36AD0() + index) & 0x40000000) == 0) {
            selected = *(u8 *)(fn_1_36AD0() + index + 0x10000 - 32352);
            fn_80008BA8(&ctl, (u8 *)&lbl_1_data_28060 + selected * 180, 180);
        } else {
            fn_1_14FC80(arg5, &ctl);
        }
    }
    fn_1_22B10(&ctl, arg6);

    for (i = 0, offset = 0; i < 750; i++, offset += arg2) {
        s32 point;
        s32 remainder;
        f32 fraction;
        s32 interpolation;
        s32 adjusted;

        colors[0] = lbl_1_rodata_8B88;
        colors[1] = lbl_1_rodata_8B8C;
        data0[0] = lbl_1_rodata_8B90;
        data0[1] = lbl_1_rodata_8B94;
        point = lbl_801A66A0;
        fn_1_229EC(&ctl, &input0, &input1);

        if (i % 10 == 0 || i == 749) {
            s32 quotient = point / 220;
            f32 base = (f32)i / lbl_1_rodata_8B98;
            f32 tmp = (f32)(lbl_1_rodata_863C + lbl_1_rodata_85F0 * base)
                    - (f32)(point - quotient * 220) / lbl_1_rodata_88B8;
            fraction = tmp - (s32)tmp;
            if (valid != 0) {
                s32 threshold = i / 30;
                if ((point - *(s32 *)((u8 *)&lbl_1_bss_8B3A0 + (active_id << 2) + 0xF0) > threshold) ||
                    *(s32 *)((u8 *)&lbl_1_bss_8B3A0 + (active_id << 2) + 0x100) == 9) {
                    if (fraction < lbl_1_rodata_85F0) {
                        s32 pair[2];
                        pair[0] = data0[1];
                        pair[1] = data0[0];
                        interpolation = fn_1_539CC(pair, &pair[0], lbl_1_rodata_863C - lbl_1_rodata_8638 * fraction);
                    } else {
                        s32 pair[2];
                        pair[0] = data0[0];
                        pair[1] = data0[1];
                        interpolation = fn_1_539CC(&pair[1], &pair[0], lbl_1_rodata_863C - (lbl_1_rodata_8638 * fraction - lbl_1_rodata_863C));
                    }
                } else {
                    interpolation = colors[0];
                }
            } else {
                if (fraction < lbl_1_rodata_85F0) {
                    s32 pair[2];
                    pair[0] = data0[0];
                    pair[1] = data0[1];
                    interpolation = fn_1_539CC(&pair[1], &pair[0], lbl_1_rodata_863C - lbl_1_rodata_8638 * fraction);
                } else {
                    s32 pair[2];
                    pair[0] = data0[1];
                    pair[1] = data0[0];
                    interpolation = fn_1_539CC(&pair[0], &pair[1], lbl_1_rodata_863C - (lbl_1_rodata_8638 * fraction - lbl_1_rodata_863C));
                }
            }
            output.a[i / 10] = interpolation;
            ((s16 *)output_id.a)[(i / 10) * 2] = arg0 + (offset / 15);
            ((s16 *)output_id.a)[(i / 10) * 2 + 1] = arg0 + (offset / 15);
            ((s16 *)output_time.a)[(i / 10) * 2] = arg1 + arg3;
            ((s16 *)output_time.a)[(i / 10) * 2 + 1] = (s32)((f32)(s32)(arg1 + arg3) -
                (f32)((f32)(s32)arg3 * input0) / lbl_1_rodata_87DC);
        }
    }
    fn_800728A8(1, 4, 5, 0);
    fn_1_A9868();
    fn_1_AA350(&output_id, &output_time, &output, 152);
    fn_1_AA538();
    fn_800724C8();
    fn_8007245C(0x2200);
    fn_80074788(0);
    fn_80074660(1);
    fn_80073678(1);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_80072AB0(0, 0, 0);
    fn_80072C24(0, 15, 2, 8, 4);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 1, 4, 2);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    fn_80074918(1, 7, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_800720B0(0);
    fn_80072864(2);
}
