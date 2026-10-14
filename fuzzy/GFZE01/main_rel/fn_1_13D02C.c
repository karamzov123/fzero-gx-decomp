/* Non-matching: best partial attempt (80.59% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

extern u32 fn_1_12F258(void);
extern u32 lbl_1_rodata_8DA0;
extern u32 lbl_1_rodata_8DA4;
extern u32 lbl_1_rodata_8DA8;
extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_8B2C;
extern const f32 lbl_1_rodata_8838;
extern s16 lbl_1_bss_962;
extern const f32 lbl_1_rodata_863C;
extern u32 fn_1_539CC(void *, void *, f32);
extern f32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_8DAC;
extern const f32 lbl_1_rodata_8B84;
extern const f32 lbl_1_rodata_8DB0;
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_49410(void);
extern const f32 lbl_1_rodata_8DB4;
extern const f32 lbl_1_rodata_8D94;
extern void fn_1_496FC(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_494DC(s16);
extern void fn_1_49514(void *);
extern const f32 lbl_1_rodata_8C9C;
extern void fn_1_4954C(f32);
extern void fn_1_4AE0C(const char *, ...);
extern const f32 lbl_1_rodata_8A2C;
extern const f32 lbl_1_rodata_8808;
extern const f32 lbl_1_rodata_87B4;
extern void fn_1_495A0(f32);
extern const f32 lbl_1_rodata_8DB8;
extern f32 lbl_8006D188(s32);

static inline u32 lerp_color(u32 a, u32 b, f32 t) {
    fn_1_539CC(&a, &b, t);
    return;
}

static inline void set_color(u32 color) {
    fn_1_49514(&color);
}

static inline u8 fn_1_13D02C_array_read(u16 *array, s32 index) { return array[index]; }
#pragma opt_propagation off
#pragma opt_lifetimes on
#pragma opt_dead_assignments off
void fn_1_13D02C(void) {
    s32 count;
    u16 colors[4];
    f32 f31;
    s32 flag;
    FontDrawPacket packet;
    u8 ones;
    u16 tens;
    u32 flag_2;

    if (fn_1_12F258() != 0xFFFFFFFF) {
        count = (fn_1_12F258() / 60) + 1;
    } else {
        count = 0;
    }

    colors[2] = lbl_1_rodata_8DA0;
    colors[1] = lbl_1_rodata_8DA4;
    colors[0] = lbl_1_rodata_8DA8;

    {
        s32 t = (s32)fn_1_12F258();
        s32 rem = (t % 60) % 120;
        f31 = lbl_8006D188((s32)(((f32)rem * lbl_1_rodata_8B2C) / lbl_1_rodata_8838));
        (void) f31;  /* fzgx: keeps the web at its definition */
    }

    if (lbl_1_bss_8B3A0.unk_94 & 0x40000000) {
        if (count > 99) {
            tens = 9;
            ones = 9;
        } else {
            tens = count / 10;
            (void) tens;  /* fzgx: keeps the web at its definition */
            ones = count % 10;
        }

        flag = 0;
        switch (lbl_1_bss_962) {
        case 16:
        case 24:
            if (count < 10) {
                flag_2 = 1;
            }
            break;
        case 15:
        case 18:
        case 19:
        case 23:
            if (count < 6) {
                flag_2 = 1;
            }
            break;
        case 14:
            if (count < 4) {
                flag_2 = 1;
            }
            break;
        default:
            break;
        }

        if (flag_2 != 0) {
            colors[3] = lerp_color(fn_1_13D02C_array_read(colors, 0), fn_1_13D02C_array_read(colors, 1), lbl_1_rodata_863C - f31);
        } else {
            colors[3] = lerp_color(fn_1_13D02C_array_read(colors, 2), fn_1_13D02C_array_read(colors, 1), lbl_1_rodata_863C - f31);
        }

        packet = *(FontDrawPacket *)&lbl_1_rodata_26F8;
        packet.image = 0x9E18;
        packet.x = lbl_1_rodata_8DAC;
        packet.y = lbl_1_rodata_8B84;
        packet.z = lbl_1_rodata_8DB0;
        fn_1_4F734(&packet);

        fn_1_49410();
        fn_1_496FC(lbl_1_rodata_8DB4, lbl_1_rodata_8D94);
        fn_1_495C8(9);
        fn_1_494DC(0x25);
        set_color(fn_1_13D02C_array_read(colors, 3));
        fn_1_4954C(lbl_1_rodata_8C9C);
        fn_1_4AE0C((const char *)&lbl_1_data_41DEC, tens);
        fn_1_494DC(0x26);
        fn_1_496FC(lbl_1_rodata_8DB4, lbl_1_rodata_8D94);
        set_color(fn_1_13D02C_array_read(colors, 2));
        fn_1_4954C(lbl_1_rodata_8A2C);
        f31 = lbl_1_rodata_87B4 + (f32)(lbl_1_rodata_8808 * f31);
        fn_1_495A0(f31);
        fn_1_4AE0C((const char *)&lbl_1_data_41DEC, tens);

        fn_1_49410();
        fn_1_496FC(lbl_1_rodata_8DB8, lbl_1_rodata_8D94);
        fn_1_495C8(9);
        fn_1_494DC(0x25);
        set_color(fn_1_13D02C_array_read(colors, 3));
        fn_1_4954C(lbl_1_rodata_8C9C);
        fn_1_4AE0C((const char *)&lbl_1_data_41DEC, ones);
        fn_1_494DC(0x26);
        fn_1_496FC(lbl_1_rodata_8DB8, lbl_1_rodata_8D94);
        set_color(fn_1_13D02C_array_read(colors, 2));
        fn_1_4954C(lbl_1_rodata_8A2C);
        fn_1_495A0(f31);
        fn_1_4AE0C((const char *)&lbl_1_data_41DEC, ones);
    }
}
#pragma opt_dead_assignments reset

#pragma opt_lifetimes reset

#pragma opt_propagation reset

