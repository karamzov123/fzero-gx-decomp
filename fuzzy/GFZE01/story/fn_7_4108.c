/* Non-matching: best partial attempt (72.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/story/story_mode.h"

typedef struct { u8 r, g, b, a; } Color;

extern const Color lbl_7_rodata_780;
extern const f32 lbl_7_rodata_784;

void fn_7_4108(u32 *flags, u32 triggers, Obj_7_bss_1960_At4 *arg2) {
    u32 *p;
    u32 i;
    Obj_7_bss_1960 *s = &lbl_7_bss_1960;

    p = flags;
    for (i = 0; (u8)i < 128; i++, p++) {
        *p = 0;
    }
    p = flags + 0x88;
    for (i = 0; (u8)i < 8; i++, p++) {
        *p = 0;
    }
    p = flags + 0x80;
    for (i = 0; (u8)i < 8; i++, p++) {
        *p = -1;
    }
    s->unk_4 = arg2;
    s->unk_8 = 0;
    s->unk_C = 0;
    s->unk_0 = 0;
    for (i = 0; i < 2; i++) {
        ((Color *)&s->unk_10)[i] = lbl_7_rodata_780;
        (&s->unk_18)[i] = 0;
        (&s->unk_24)[i] = lbl_7_rodata_784;
        (&s->unk_1C)[i] = lbl_7_rodata_784;
    }
    s->unk_2C = 0;
    s->unk_30 = triggers;
}
