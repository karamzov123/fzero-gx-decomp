/* Non-matching: best partial attempt (80.16% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

extern u32 fn_1_584AC(void);
extern void lbl_8006D5F0(void *, f32);
extern void lbl_8006D8D8(s32);
extern void lbl_8006E1C0(void *, void *);
extern const f32 lbl_1_rodata_76A8;

typedef struct {
    u32 a[3];
    u8 pad_C[2];
    s16 pitch;
    s16 heading;
    u8 pad_10[4];
    f32 x2;
    f32 y2;
    f32 z2;
} Record;

void fn_1_FE7D8(u8 *arg0, s32 arg1) {
    const f32 *pool = &lbl_1_rodata_76A8;
    Record *record;
    u8 *records = (u8 *)lbl_1_bss_3BE0->unk_A8;
    u32 rand;
    s32 index;

    rand = (u16)fn_1_584AC();
    index = (s32)rand % (s32)lbl_1_bss_3BE0->unk_A4;
    record = (Record *)(records + index * 0x24);
    *(s32 *)arg0 = arg1;

    if (arg1 != 0) {
        rand = (u16)fn_1_584AC();
        *(s32 *)(arg0 + 4) = (s32)(300.0f + 100.0f * ((f32)rand / 32767.0f));
        *(u32 *)(arg0 + 8) = record->a[0];
        *(u32 *)(arg0 + 12) = record->a[1];
        *(u32 *)(arg0 + 16) = record->a[2];
        *(u32 *)(arg0 + 20) = *(u32 *)(arg0 + 8);
        *(u32 *)(arg0 + 24) = *(u32 *)(arg0 + 12);
        *(u32 *)(arg0 + 28) = *(u32 *)(arg0 + 16);

        {
            f32 v[3];
            v[0] = record->x2 - *(f32 *)&record->a[0];
            v[1] = record->y2 - *(f32 *)&record->a[1];
            v[2] = record->z2 - *(f32 *)&record->a[2];
            rand = (u16)fn_1_584AC();
            lbl_8006D5F0(v, (f32)(((f32)((s32)(record->heading >> 7) * (15.0f + 4.0f * ((f32)rand / 32767.0f))) / 10.0f)));
        }
        rand = (u16)fn_1_584AC();
        *(f32 *)(arg0 + 56) = 2.0f + 2.0f * ((f32)rand / 32767.0f);
        *(f32 *)(arg0 + 56) = *(f32 *)(arg0 + 56) * ((f32)((f64)((f32)rand / 32767.0f) - 0.5 - 5.0) / 10.0f);
    } else {
        rand = (u16)fn_1_584AC();
        *(s32 *)(arg0 + 4) = (s32)(200.0f + 400.0f * ((f32)rand / 32767.0f));
        {
            f32 v[3];
            v[0] = 2500.0f;
            v[1] = 1000.0f;
            v[2] = 1400.0f;
            rand = (u16)fn_1_584AC();
            lbl_8006D8D8((s16)rand);
            lbl_8006E1C0(v, v);
            rand = (u16)fn_1_584AC();
            lbl_8006D5F0(v, 2500.0f + 1000.0f * ((f32)rand / 32767.0f));
        }
        rand = (u16)fn_1_584AC();
        *(f32 *)(arg0 + 12) = 1400.0f + 300.0f * ((f32)rand / 32767.0f);
        rand = (u16)fn_1_584AC();
        *(f32 *)(arg0 + 32) = (f32)((f64)((f32)rand / 32767.0f) - 0.5 - 5.0);
        rand = (u16)fn_1_584AC();
        *(f32 *)(arg0 + 36) = -(4.0f + 7.0f * ((f32)rand / 32767.0f));
        rand = (u16)fn_1_584AC();
        *(f32 *)(arg0 + 40) = (f32)((f64)((f32)rand / 32767.0f) - 0.5);
        rand = (u16)fn_1_584AC();
        *(f32 *)(arg0 + 56) = 2.0f + 2.5f * ((f32)rand / 32767.0f);
    }

    *(u16 *)(arg0 + 44) = fn_1_584AC();
    *(u16 *)(arg0 + 46) = fn_1_584AC();
    rand = (u16)fn_1_584AC();
    *(u16 *)(arg0 + 48) = (s32)(768.0f * ((f32)rand / 32767.0f)) + 256;
    rand = (u16)fn_1_584AC();
    *(u16 *)(arg0 + 50) = (s32)(768.0f * ((f32)rand / 32767.0f)) + 256;
    *(f32 *)(arg0 + 52) = 0.0f;
}
