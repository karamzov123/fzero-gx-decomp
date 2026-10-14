/* Non-matching: best partial attempt (66.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/emblem.h"
extern void *memset(void *, int, u32);

struct fn_3_152BC_color { u8 r, g, b, a; };

void fn_3_152BC(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, void *arg5) {
    u32 *p_lbl_3_bss_A23E0;
    s16 v0;
    s16 v1;
    u32 v2;
    s16 v3;
    u32 v5;
    s32 v6;
    u32 v7;
    s32 v14;
    s16 v19;
    s16 v21;
    s16 v22;
    s32 v23;
    s16 v17;
    s16 v11;
    s16 v10;
    s16 v27;
    s16 v9;
    u32 v24;
    struct fn_3_152BC_color loc_8;
    p_lbl_3_bss_A23E0 = &lbl_3_bss_A23E0;
    v0 = (s16)arg3;
    v1 = (s16)arg4;
    v2 = arg2;
    while ((s16)v2 < v1) {
        v3 = (s16)v2;
        v14 = v3 / 4;
        v27 = v3 % 4;
        v5 = v3 & 3;
        v6 = v3 >> 2;
        v7 = arg1;
        while ((s16)v7 < v0) {
            loc_8 = *(struct fn_3_152BC_color *)arg5;
            switch (*p_lbl_3_bss_A23E0) {
            case 4:
                v10 = (s16)v7;
                v11 = v10 / 4;
                v17 = v14 + v11 * (s16)(lbl_3_bss_A23D8 / 4);
                v19 = (v17 << 5) + ((v27 + ((s16)(v10 % 4) << 2)) << 1);
                memset((u8 *)arg0 + v19, (((loc_8.r << 8) & 0xF800) | ((loc_8.g << 3) & 0x7E0) | (loc_8.b >> 3)) >> 8, 1);
                memset((u8 *)arg0 + v19 + 1, (u8)(((loc_8.r << 8) & 0xF800) | ((loc_8.g << 3) & 0x7E0) | (loc_8.b >> 3)), 1);
                break;
            case 5:
                v21 = (s16)v7;
                v22 = v21 >> 2;
                v23 = v22 * (s16)((s32)lbl_3_bss_A23D8 >> 2);
                v9 = ((s16)((s16)v6 + v23) << 5) + (((s16)v5 + ((v21 & 3) << 2)) << 1);
                if (loc_8.a >= 224)
                    v24 = 0x8000 | ((loc_8.r << 7) & 0x7C00) | ((loc_8.g << 2) & 0x3E0) | (loc_8.b >> 3);
                else
                    v24 = ((loc_8.a << 7) & 0x7000) | ((loc_8.r << 4) & 0xF00) | (loc_8.g & 0xF0) | (loc_8.b >> 4);
                *((u8 *)arg0 + v9) = v24 >> 8;
                if (loc_8.a >= 224)
                    v24 = 0x8000 | ((loc_8.r << 7) & 0x7C00) | ((loc_8.g << 2) & 0x3E0) | (loc_8.b >> 3);
                else
                    v24 = ((loc_8.a << 7) & 0x7000) | ((loc_8.r << 4) & 0xF00) | (loc_8.g & 0xF0) | (loc_8.b >> 4);
                *((u8 *)arg0 + v9 + 1) = v24;
                break;
            }
            v7++;
        }
        v2++;
    }
}
