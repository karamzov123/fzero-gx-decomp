/* Non-matching: best partial attempt (81.85% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

extern u32 lbl_1_rodata_759C[25];

typedef struct {
    s32 unk_0;
    u8 pad_4[0x58];
    s32 unk_5C;
    u8 unk_60;
    u8 unk_61;
    u8 unk_62;
    u8 unk_63;
} Group;

void fn_1_FBA88(int index) {
    Obj_1_bss_84454 *o = (Obj_1_bss_84454 *)((u8 *)&lbl_1_bss_84454.unk_0 + (index & 0xff) * 0x270);
    u32 t[6];
    u32 *p = t;
    u32 *r;
    s8 n = 0;
    s32 c1 = 0;
    s32 c2 = 0;
    s32 c3 = 0;
    s32 c4 = 0;
    Group *g;

    t[0] = lbl_1_rodata_759C[0];
    t[1] = lbl_1_rodata_759C[1];
    t[2] = lbl_1_rodata_759C[2];
    t[3] = lbl_1_rodata_759C[3];
    t[4] = lbl_1_rodata_759C[4];
    t[5] = lbl_1_rodata_759C[5];

    g = (Group *)((u8 *)o + 0x134);
    if (g->unk_0 != 0) {
        g->unk_5C = *p++;
        n++;
        g->unk_60 = c1++;
        g->unk_61 = c2++;
        g->unk_62 = c3++;
        g->unk_63 = c4++;
    }
    g = (Group *)((u8 *)o + 0x194);
    if (g->unk_0 != 0) {
        g->unk_5C = *p++;
        n++;
        g->unk_60 = c1++;
        g->unk_61 = c2++;
        g->unk_62 = c3++;
        g->unk_63 = c4++;
    }
    g = (Group *)((u8 *)o + 0x1F4);
    if (g->unk_0 != 0) {
        g->unk_5C = *p;
        n++;
        g->unk_60 = c1++;
        g->unk_61 = c2++;
        g->unk_62 = c3++;
        g->unk_63 = c4++;
    }
    r = t + n;
    g = (Group *)((u8 *)o + 0x14);
    if (g->unk_0 != 0) {
        g->unk_5C = *r++;
        g->unk_60 = c1++;
        g->unk_61 = -1;
    }
    g = (Group *)((u8 *)o + 0x74);
    if (g->unk_0 != 0) {
        g->unk_5C = *r++;
        g->unk_60 = c1++;
        g->unk_61 = -2;
    }
    g = (Group *)((u8 *)o + 0xd4);
    if (g->unk_0 != 0) {
        g->unk_5C = *r;
        g->unk_60 = c1;
        g->unk_61 = -3;
    }
}
