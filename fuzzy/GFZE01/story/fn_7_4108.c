/* Non-matching: best partial attempt (78.41% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/story/story_mode.h"

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

typedef struct {
    u8 unk_0;
    u8 pad_1[0x3];
    Obj_7_bss_1960_At4 *unk_4;
    u8 unk_8;
    u8 pad_9[0x3];
    u32 unk_C;
    Color unk_10[2];
    u8 unk_18[2];
    u8 pad_1A[0x2];
    f32 unk_1C[2];
    f32 unk_24[2];
    u8 unk_2C;
    u8 pad_2D[0x3];
    u32 unk_30;
} StoryReset;

extern const Color lbl_7_rodata_780;
extern const f32 lbl_7_rodata_784;

void fn_7_4108(u32 *flags, u32 arg1, u32 arg2) {
    StoryReset *s = (StoryReset *)&lbl_7_bss_1960;
    Color color[2];
    u32 *p;
    u32 i;

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

    s->unk_4 = (Obj_7_bss_1960_At4 *)arg2;
    s->unk_8 = 0;
    s->unk_C = 0;
    s->unk_0 = 0;
    color[0] = lbl_7_rodata_780;
    color[1] = lbl_7_rodata_780;
    s->unk_10[0] = color[0];
    s->unk_10[1] = color[1];
    s->unk_18[0] = 0;
    s->unk_18[1] = 0;
    s->unk_1C[0] = lbl_7_rodata_784;
    s->unk_1C[1] = lbl_7_rodata_784;
    s->unk_24[0] = lbl_7_rodata_784;
    s->unk_24[1] = lbl_7_rodata_784;
    s->unk_2C = 0;
    s->unk_30 = arg1;
}
