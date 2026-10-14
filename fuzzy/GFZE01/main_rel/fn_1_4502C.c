/* Non-matching: best partial attempt (62.63% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_1_bss_384C0;
extern u32 lbl_1_bss_958[2];
extern void fn_1_46EB4(u32 arg0, u32 arg1);

typedef struct {
    u32 a;
    u8 pad[0xC];
} Rec16;

typedef struct {
    Rec16 f[8];
} Rec128;

typedef struct {
    u32 a;
    u8 pad[8];
} Rec12;

typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[4];
    Rec128 arr1[0x80];
    Rec12 arr2[0x200];
    u32 unk_5818;
    u32 unk_581C;
    u32 unk_5820;
    u32 arr3[0x10];
    u32 unk_5864;
    u32 unk_5868;
    u32 unk_586C;
    u32 unk_5870;
} State;

void fn_1_4502C(void) {
    State *s = (State *)&lbl_1_bss_384C0;
    Rec128 *p1 = s->arr1;
    Rec12 *p2 = s->arr2;
    u32 *p3 = s->arr3;
    s32 i;
    s32 j;
    u32 v;

    for (i = 0; i < 0x80; i++, p1++) {
        for (j = 0; j < 8; j++) {
            p1->f[j].a = 0;
        }
    }

    for (i = 0; i < 0x200; i++) {
        p2[i].a = 0;
    }

    fn_1_46EB4(0x704000, 0xF23FFF);

    v = s->unk_581C;
    s->unk_8 = 0;
    s->unk_10 = 0;
    s->unk_5818 = v;
    s->unk_5820 = 0;
    s->unk_C = 0;

    for (i = 0; i < 0x10; i++) {
        p3[i] = 0;
    }

    s->unk_5864 = 0;
    s->unk_5868 = 0;
    s->unk_586C = lbl_1_bss_958[0];
    s->unk_5870 = 0x20000 - 0x2000;
}
