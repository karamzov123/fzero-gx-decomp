/* Non-matching: best partial attempt (12.63% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_lig.h"

extern u32 lbl_1_rodata_6490[4];
extern u32 lbl_801A63C0;
extern u32 lbl_8006D8D8(u32 value);
extern u32 lbl_8006E1C0(void *arg0);

void fn_1_D7758(void *arg0, f32 arg1) {
    s32 i;
    s32 j;
    Obj_1_data_2A7E0_At3C *p = lbl_1_data_2A7E0.unk_3C;
    f32 f100 = 100.0f;
    f32 f3 = 3.0f;
    f32 f31 = f100 * arg1;
    f32 f30 = f3 * arg1;
    f32 f0f;

    for (j = 0; j < 5; j++) {
        for (i = 0; i < 20; i++) {
            if (p->unk_5C > 0) {
                continue;
            }
            lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
            p->unk_30 = *(f32 *)((u8 *)arg0 + 0);
            p->unk_34 = *(f32 *)((u8 *)arg0 + 4);
            p->unk_38 = *(f32 *)((u8 *)arg0 + 8);
            f0f = (f32)(0.7 + 0.3 * ((f32)(4503601774854144.0) - 4503601774854144.0) / 32767.0f);
            p->unk_48 = 235.0f * f0f;
            p->unk_4C = 80.0f * f0f;
            p->unk_50 = 30.0f * f0f;
            p->unk_54 = f31;
            p->unk_58 = 0;
            lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
            p->unk_5A = (s16)(512.0 * ((f32)(4503601774854144.0) - 4503601774854144.0) / 32767.0f - 0.5);
            lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
            p->unk_5C = (s16)(arg1 * 300.0 * (0.7 + 0.3 * ((f32)(4503601774854144.0) - 4503601774854144.0) / 32767.0f));
            p->unk_3C = 0.0f;
            p->unk_40 = (f32)(arg1 * 17.0 * (0.3 + 0.7 * ((f32)(4503601774854144.0) - 4503601774854144.0) / 32767.0f));
            p->unk_44 = f30;
            lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
            lbl_8006D8D8(i);
            lbl_8006E1C0((void *)(u8 *)&p->unk_3C);
        }
        p = (Obj_1_data_2A7E0_At3C *)((u8 *)p + 0x30);
    }
}
