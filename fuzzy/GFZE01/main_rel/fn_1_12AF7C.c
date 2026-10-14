/* Non-matching: best partial attempt (89.18% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/archive.h"

extern s32 lbl_1_rodata_8160[4];
extern u8 *fn_1_36AD0(void);

#define SRC (*(u32 *)((u8 *)fn_1_36AD0() + 0x81A8 + 0x81C0 * i + 8 * k + 4 * l))

#pragma opt_lifetimes off
void fn_1_12AF7C(void) {
    u32 tab[4];
    s32 v2;
    u32 v3;
    s32 v4;
    u32 acc;
    u32 *d;
    s16 i;
    s16 k;
    s16 l;
    s16 j;

    tab[0] = lbl_1_rodata_8160[0];
    tab[1] = lbl_1_rodata_8160[1];
    tab[2] = lbl_1_rodata_8160[2];
    tab[3] = lbl_1_rodata_8160[3];

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 3; k++) {
                for (l = 0; l < 1; l++) {
{
    u32 v1;
                    v1 = ((0xFF) & ((SRC >> 8)));
                    v2 = (u8)((((SRC >> 24) + (tab[j] >> 24)) >> 8) & 0xFF);
                    v3 = (u8)(((((0xFF) & ((SRC >> 8)))) + ((tab[j] >> 8) & 0xFF)) >> 8);
                    v4 = (u8)(((((0xFFFF) & ((SRC >> 8)))) + ((tab[j] >> 8) & 0xFFFF)) >> 8);
                    acc = (v2 << 24) | (v3 << 16);
                    acc = (((0xFF00FFFF) & (acc))) | ((((0xFF) & (v4))) << 16);
                    acc |= v1;
}
                    d = (u32 *)((u8 *)&lbl_1_bss_8B2E0 + 0x30 * i + 0xC * j + 4 * k + 4 * l);
                    *d = acc;
                }
            }
        }
    }
}
#pragma opt_lifetimes reset

