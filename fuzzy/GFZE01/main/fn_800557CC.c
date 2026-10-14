/* Non-matching: best partial attempt (86.63% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

typedef u32 (*fn_800557CC_Fn0)(u32, u32, u32);
typedef u32 (*fn_800557CC_Fn1)(u32, u32, u32);
typedef u32 (*fn_800557CC_Fn2)(u32, u32, u32);

struct fn_800557CC_lbl_801878B8 {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[3];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
};

struct fn_800557CC_h {
    u8 pad_0[2];
    s8 unk_2;
    u8 pad_3[9];
    s32 unk_C;
    u8 pad_10[0x18];
    u32 unk_28;
};

extern struct fn_800557CC_lbl_801878B8 lbl_801878B8;
extern char lbl_80091F50[];
extern u32 DVDGetCommandBlockStatus(u32);
extern s32 DVDGetDriveStatus(void);
extern s32 fn_80019B78(u32);
extern u32 OSGetTick(void);

#pragma opt_common_subs off
void fn_800557CC(struct fn_800557CC_h *h) {
    u32 tmp_call4;
    char *ro = lbl_80091F50;
    struct fn_800557CC_lbl_801878B8 *p = (struct fn_800557CC_lbl_801878B8 *)&lbl_801878B8;
    u32 *q = &p->unk_0;
    u32 t1;
    u32 t0;
    u8 *pb = (u8 *)&p->unk_0;
    s32 r;
    u32 lab_t0;

    if (h == 0) {
        if (p->unk_10 == 0) {
            ((fn_800557CC_Fn0)p->unk_10)(p->unk_C, (u32)(((0x2c) + (ro))), 0);
        }
        return;
    }
    if (h->unk_2 != 1) {
        return;
    }
    if (h->unk_2 != 0) {
        return;
    }
    lab_t0 = (u32)&h->unk_28;
    DVDGetCommandBlockStatus(lab_t0);
    DVDGetDriveStatus();
    q[2] = 1;
    r = fn_80019B78((u32)&h->unk_28);
    q[2] = 0;
    if (r < 0) {
        if (p->unk_10 != 0) {
            ((fn_800557CC_Fn1)p->unk_10)(p->unk_C, (u32)(((0x90) + (ro))), (u32)h);
        }
        return;
    }
    t0 = OSGetTick() / ((*(vu32 *)0x800000F8 >> 2) / 1000);
    while ((h->unk_C == 0 || h->unk_C == 10) == 0) {
        h->unk_C = (s32)DVDGetCommandBlockStatus((u32)&h->unk_28);
        p->unk_0 = h->unk_C;
        tmp_call4 = OSGetTick();
        t1 = tmp_call4 / ((*(vu32 *)0x800000F8 >> 2) / 1000);
        if (((t1 >= t0) ? (t1 - t0) : ((((-1 - t0)) + (t1)))) > 2000) {
            if (p->unk_10 != 0) {
                ((fn_800557CC_Fn2)p->unk_10)(p->unk_C, (u32)(((0xac) + (ro))), (u32)h);
            }
            break;
        }
    }
    h->unk_2 = 0;
    pb[4] = 0;
    lab_t0 = (u32)&h->unk_28;
    DVDGetCommandBlockStatus(lab_t0);
    DVDGetDriveStatus();
}
#pragma opt_common_subs reset

