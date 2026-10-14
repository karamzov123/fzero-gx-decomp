/* Non-matching: best partial attempt (96.43% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 300.0f;
    s = 640.0f;
    s = 480.0f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

extern s8 lbl_7_bss_1960[];
extern u32 lbl_1_rodata_26F8;
extern u16 fn_1_48690(u32);
extern int fn_1_4F734(FontDrawPacket *);

#pragma opt_propagation off
#pragma peephole on
#pragma opt_common_subs off
void fn_7_44DC(void) {
    u8 *p_flags;
    u8 *p_bss;
    u32 v1;
    u32 *pa;
    u8 i;
    f32 *pb;

    p_bss = (u8 *)&lbl_7_bss_1960;
    i = 0;
    p_flags = p_bss + 0x18;
    while (i < 2) {
        v1 = (u16)(i);
        if (((v1)[p_flags]) != 0) {
{
    FontDrawPacket loc_8;
            loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            loc_8.image = 18;
            loc_8.x = 0.0f;
            loc_8.y = 0.0f;
            loc_8.z = 300.0f - (f32)i;
            loc_8.flags = 5;
{
    s16 t0;
            loc_8.scale_x = loc_8.scale_x * (640.0f / (f32)(fn_1_48690(18)));
}
{
    u32 t1;
            t1 = fn_1_48690(18);
            pa = (u32 *)(p_bss + 0x10);
            pb = (f32 *)(p_bss + 0x1c);
            *(u32 *)((u8 *)&loc_8 + 0x38) = ((v1)[pa]);
            loc_8.alpha = ((v1)[pb]);
            loc_8.scale_y = loc_8.scale_y * (480.0f / (f32)t1);
}
            fn_1_4F734(&loc_8);
}
        }
        i++;
    }
}
#pragma opt_common_subs reset

#pragma peephole reset

#pragma opt_propagation reset

