/* Non-matching: best partial attempt (96.84% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "font.h"

extern u16 fn_1_486C4(u32);
extern u16 fn_1_48690(u32 unused);
extern f64 lbl_1_rodata_2778[2];
extern const f32 lbl_1_rodata_2754;
extern const f32 lbl_1_rodata_2868;
extern int fn_1_4F734(FontDrawPacket *);

typedef struct NumberPacket {
    u32 font;
    u8 pad[0xC];
    f32 width;
    f32 height;
    f32 digit1_x;
    f32 digit2_x;
    f32 next1_x;
    f32 next2_x;
} NumberPacket;

#pragma opt_dead_assignments off
#pragma opt_lifetimes off
#pragma opt_strength_reduction off
u16 fn_1_53FE4(NumberPacket *arg0, s32 arg1)
{
    s16 ones = ((20) * ((u8)arg1 % 10));
    s32 tens = (u8)arg1 / 10 * 20;
    s32 font = arg0->font;
    s16 wa = (s16)fn_1_486C4(font);
    s16 wb = (s16)fn_1_48690(font);
    f32 sy;
    f32 sx = lbl_1_rodata_2754 / (f32)wb;
    sy = lbl_1_rodata_2754 / (f32)wa;

    arg0->width = arg0->width * (lbl_1_rodata_2868 * sx);
    arg0->height = arg0->height * (lbl_1_rodata_2868 * sy);
    arg0->digit1_x = (f32)ones * sx;
    arg0->digit2_x = (f32)tens * sy;
    arg0->next1_x = sx * (ones + 20);
    arg0->next2_x = sy * (tens + 20);
    fn_1_4F734((FontDrawPacket *)arg0);
    return (u32)ones;
}
#pragma opt_strength_reduction reset

#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

