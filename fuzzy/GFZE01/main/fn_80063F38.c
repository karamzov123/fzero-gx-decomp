/* Non-matching: best partial attempt (95.70% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

#pragma opt_propagation off
static inline u8 fn_80063F38_array_read(u8 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments off
void fn_80063F38(void *arg0, u32 arg1) {
    u32 idx4;
    u32 idx5;
    s8 delta;
    u8 j;
    u32 i;
    struct { u8 value; } val;
    struct { u32 value; } a;

    idx5 = (arg1 & 0xFF) << 6;
    idx4 = (arg1 & 0xFF) << 4;
    delta = (s8)((*(u32 *)((u8 *)lbl_801A6C80 + 0x444) >> 17) & 0x7F) - 0x40;

    for (i = 0; (u8)i < 0x10; i++) {
        for (j = 0; (u8)j < 4; j++) {
            val.value = *(((idx5) + ((u8 *)lbl_801A6C80 + 0xd88)) + ((u8)i) * 4 + j);
            if (val.value == 0xFF) {
                continue;
            }
            switch ((u16)arg0) {
            case 1:
            case 0x11: {
                u8 *e = (u8 *)lbl_801A6C80 + ((u32)val.value << 5);
                u8 *src;

                if (fn_80063F38_array_read(e, 0x589) & 1) {
                    break;
                }
                e[0x599] = 0x40;
                ((u8 *)lbl_801A6C80)[((u32)val.value << 5) + 0x59a] = 0;
                ((u8 *)lbl_801A6C80)[((u32)val.value << 5) + 0x59b] = 0;
                ((u8 *)lbl_801A6C80)[((u32)val.value << 5) + 0x59c] = 0;
                ((u8 *)lbl_801A6C80)[((u32)val.value << 5) + 0x59d] = 0;
                src = *(u8 **)((u8 *)lbl_801A6C80 + ((u32)val.value << 5) + 0x5a0);
                *((u8 *)lbl_801A6C80 + ((u32)val.value << 5) + 0x590) = fn_80063F38_array_read(src, 0xB);
                ((u8 *)lbl_801A6C80)[((u32)val.value << 5) + 0x596] = fn_80063F38_array_read(src, 0xD);
                ((u8 *)lbl_801A6C80)[((u32)val.value << 5) + 0x597] = fn_80063F38_array_read(src, 0xE);
                break;
            }
            case 0xA004: {
                u8 *e = (u8 *)lbl_801A6C80 + ((u32)val.value << 5);
                u32 b;
                s8 t;
                s16 v;

                t = 0;
                if (fn_80063F38_array_read(e, 0x589) & 2) {
                    b = *((u8 *)lbl_801A6C80 + idx4 + 0x495);
                    a.value = *((u8 *)lbl_801A6C80 + idx4 + 0x493);
                    if (b != 0x40) {
                        t = ((s8)b - 0x40) * 2;
                    }
                } else {
                    b = *((u8 *)lbl_801A6C80 + idx4 + 0x494);
                    a.value = *((u8 *)lbl_801A6C80 + idx4 + 0x492);
                    if (b != 0x40) {
                        t = ((s8)b - 0x40) * 2;
                    }
                }
                v = (s8)a.value + t;
                if (v < 0) {
                    v = 0;
                } else if (v > 0x7F) {
                    v = 0x7F;
                }
                e[0x598] = v;
                break;
            }
            case 0xA007: {
                u8 *e = (u8 *)lbl_801A6C80 + ((u32)val.value << 5);

                if (fn_80063F38_array_read(e, 0x589) & 1) {
                    break;
                }
                e[0x596] = fn_80063F38_array_read(e, 0x595) + delta;
                break;
            }
            }
        }
    }
}
#pragma opt_dead_assignments reset

#pragma opt_propagation reset

