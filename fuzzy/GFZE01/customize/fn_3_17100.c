/* Non-matching: best partial attempt (52.01% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/editor.h"

extern u8 lbl_1_bss_9F8[];
extern u8 lbl_1_bss_BF0[];
extern u8 lbl_1_bss_D58[];
extern const f32 lbl_3_rodata_5F0[3];
extern const f64 lbl_3_rodata_600;

extern void fn_1_A2D84(u32);
extern void fn_3_177AC(void *);

static u32 *table(void) { return (u32 *)&lbl_3_data_35C0; }
static void notify(u32 *p) { fn_3_177AC(p); }
static void sound(void) { fn_1_A2D84(0xA9150600); }

void fn_3_17100(void) {
    Obj_3_bss_A2410 *s = &lbl_3_bss_A2410;
    u16 *flags = (u16 *)(lbl_1_bss_9F8 + 0x12 + s->unk_D * 20);
    u32 *t = table();
    u32 tmp;

    if (s->unk_8 & 0x40000000) {
        if (*flags & 0x80) {
            if (s->unk_C < 4) {
                s->unk_4 = s->unk_10;
                s->unk_5 = s->unk_12;
                s->unk_6 = s->unk_14;
                *(u32 *)s = t[s->unk_C];
                sound();
                s->unk_E = s->unk_C;
                s->unk_C = 2;
                s->unk_8 = 0x80000000;
                s->unk_1C = lbl_3_rodata_5F0[0];
            } else {
                s->unk_8 = 0x40000000;
                s->unk_0 = t[s->unk_C];
                sound();
                s->unk_C -= 4;
                s->unk_1C = lbl_3_rodata_5F0[0];
                tmp = t[s->unk_C];
                notify(&tmp);
            }
        }
        if (*flags & 0x40) {
            if ((u32)s->unk_C + 4 < 16) {
                s->unk_8 = 0x40000000;
                s->unk_0 = t[s->unk_C];
                sound();
                s->unk_C += 4;
                s->unk_1C = lbl_3_rodata_5F0[0];
            }
            tmp = t[s->unk_C];
            notify(&tmp);
        }
        if (*flags & 0x10) {
            if ((s->unk_C % 4) != 0) {
                s->unk_8 = 0x40000000;
                s->unk_0 = t[s->unk_C];
                sound();
                s->unk_1C = lbl_3_rodata_5F0[0];
                s->unk_C--;
            }
            tmp = t[s->unk_C];
            notify(&tmp);
        }
        if (*flags & 0x20) {
            if ((s->unk_C % 4) != 3) {
                s->unk_8 = 0x40000000;
                s->unk_0 = t[s->unk_C];
                sound();
                s->unk_1C = lbl_3_rodata_5F0[0];
                s->unk_C++;
            }
            tmp = t[s->unk_C];
            notify(&tmp);
        }
    } else {
        if (*flags & 0x80) {
            s->unk_20 = 0;
            if (s->unk_C >= 1) {
                s->unk_8 = 0x80000000;
                sound();
                s->unk_C--;
            }
            tmp = *(u32 *)&lbl_3_rodata_5F0[0];
            {
                u8 msg[4];
                *(u32 *)msg = tmp;
                msg[0] = s->unk_10;
                msg[1] = s->unk_12;
                msg[2] = s->unk_14;
                notify((u32 *)msg);
            }
        }
        if (*flags & 0x40) {
            s->unk_20 = 0;
            s->unk_C++;
            sound();
            if (s->unk_C >= 3) {
                s16 n = s->unk_E;
                s->unk_C = n;
                s->unk_8 = 0x40000000;
                s->unk_0 = t[(u8)n];
                s->unk_1 = s->unk_12;
                s->unk_2 = s->unk_14;
                s->unk_1C = lbl_3_rodata_5F0[0];
                tmp = s->unk_0;
                notify(&tmp);
            } else {
                u8 msg[4];
                *(u32 *)msg = *(u32 *)&lbl_3_rodata_5F0[1];
                msg[0] = s->unk_10;
                msg[1] = s->unk_12;
                msg[2] = s->unk_14;
                s->unk_8 = 0x80000000;
                notify((u32 *)msg);
            }
        }
        flags = (u16 *)(lbl_1_bss_9F8 + 2 + s->unk_D * 20);
        if (*flags & 0x30) {
            u16 *vals = &s->unk_10;
            s16 orig = vals[s->unk_C];
            u32 msg = *(u32 *)&lbl_3_rodata_5F0[2];
            notify(&msg);
            {
                s16 step;
                s16 cur = s->unk_20;
                f32 axis = *(f32 *)(lbl_1_bss_BF0 + s->unk_D * 32 + 8);
                if (cur > 40) step = axis < lbl_3_rodata_5F0[0] ? -8 : 8;
                else if (cur > 20) step = axis < lbl_3_rodata_5F0[0] ? -4 : 4;
                else step = axis < lbl_3_rodata_5F0[0] ? -1 : 1;
                if (cur >= 20 || ((*(u16 *)(lbl_1_bss_D58 + 0x12) & 0x30) != 0)) {
                    s32 value = vals[s->unk_C] + step;
                    if (value < 0) value = 0;
                    else if (value > 255) value = 255;
                    vals[s->unk_C] = value;
                }
                axis = *(f32 *)(lbl_1_bss_BF0 + s->unk_D * 32 + 8);
                if (__fabs(axis) >= 0.800000011920929) s->unk_20++;
                else s->unk_20 = 0;
                if (vals[s->unk_C] && vals[s->unk_C] != 255 && orig != vals[s->unk_C])
                    fn_1_A2D84(0xA9150700);
            }
        }
    }
}
