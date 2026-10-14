/* Non-matching: best partial attempt (93.30% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern s32 fn_1_F9FEC(void);
extern u32 lbl_801A66A8;
extern void fn_1_12F128(s16);
extern void fn_1_A2D84(u32);

typedef struct {
    u8 pad[0x98];
    s32 flags;
} SelState;

typedef struct {
    u8 pad[0xa];
    s8 kind;
    u8 tail[1];
} SelCtl;

typedef struct {
    u8 pad[0x10];
    u16 a;
    u16 b;
} SelEntry;

typedef struct {
    u8 pad[8];
    s16 value;
    s16 last;
} SelArg;

extern SelState lbl_1_bss_8B3A0;
extern SelCtl lbl_1_bss_9C8[];
extern SelEntry lbl_1_bss_9F8[];

#pragma opt_dead_assignments off
void fn_10_A634(SelArg *arg0) {
    SelState *g;
    s32 flag;
    SelCtl *ctl;
    SelEntry *ent;
    s16 count;
    s16 i;

    flag = (fn_1_F9FEC() != 0);
    ctl = (SelCtl *)&lbl_1_bss_9C8;
    ent = (SelEntry *)&lbl_1_bss_9F8;
    g = &lbl_1_bss_8B3A0;
    count = 0;

    for (i = 0; i < 4; i++) {
        if (ctl->kind != -1 && __rlwnm((u32)g->flags, (u32)(i + 1) & 31, 31, 31) != 0) {
            if (((u32)(*(u16 volatile *)&(ent->a)) & 0x1000) != 0 || ((u32)ent->b & 0x1000) != 0) {
                count--;
            }

            if (((u32)(*(u16 volatile *)&(ent->a)) & 0x2000) != 0 || ((u32)ent->b & 0x2000) != 0) {
                count++;
            }

            if (((u32)ent->a & 0x2000) != 0 || ((u32)ent->b & 0x2000) != 0) {
                fn_1_12F128(i);
            } else if (((u32)ent->a & 0x1000) != 0 || ((u32)ent->b & 0x1000) != 0) {
                fn_1_12F128(i);
            }
        }

        ctl = (SelCtl *)((u8 *)ctl + 0xc);
        ent = (SelEntry *)((u8 *)ent + 0x14);
    }

    if (flag != 0) {
        arg0->value = (arg0->value + count > 3) ? 0 :
                      ((arg0->value + count < 0) ? 3 : arg0->value + count);
    } else {
        arg0->value = (arg0->value + count > 2) ? 0 :
                      ((arg0->value + count < 0) ? 2 : arg0->value + count);
    }

    arg0->last = arg0->value;

    if (count != 0) {
        fn_1_A2D84(0xA9010000);
        lbl_801A66A8 = 0;
    }
}
#pragma opt_dead_assignments reset
