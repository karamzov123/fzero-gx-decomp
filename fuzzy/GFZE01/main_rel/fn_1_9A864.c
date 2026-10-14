/* Non-matching: best partial attempt (93.10% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/burner.h"

typedef struct {
    s16 unk_00;
    u8 unk_02[0x36];
    u32 unk_38;
    u32 unk_3C;
    u8 unk_40[0x34];
    u32 unk_74;
    u32 unk_78;
    u8 unk_7C[0x350];
} Burner;

typedef struct {
    u8 unk_00[0x10];
    void (*fn_10)(void);
    u8 unk_14[0x10];
} BurnerVtbl;

typedef struct {
    u8 unk_000[0x720];
    Burner burner;
    BurnerVtbl vtbl[225];
    u8 unk_2A90[0x10];
    char unk_2AA0[0x10];
} Manager;

extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_103054(void);
extern void fn_1_9D2EC(void);
extern u32 lbl_801A6410;

void fn_1_9A864(void)
{
    Manager *mgr = (Manager *)lbl_1_data_2A0C0;
    Burner *b = &mgr->burner;
    BurnerVtbl *tbl = mgr->vtbl;

    if (b->unk_78 != 0) {
        fn_1_46B4(lbl_801A6410, b->unk_78, mgr->unk_2AA0, 0x281);
        b->unk_78 = 0;
    }

    fn_1_103054();

    {
        s16 idx = b->unk_00;

        if (idx > 0) {
            tbl[idx].fn_10();
        }
    }

    if (b->unk_3C != 0) {
        fn_1_46B4(lbl_801A6410, b->unk_3C, mgr->unk_2AA0, 0x28F);
        b->unk_3C = 0;
    }

    if (lbl_1_bss_384B8 != 0 || lbl_1_bss_384B4 != 0) {
        fn_1_9D2EC();
    }

    mgr->burner.unk_00 = -1;
    b->unk_38 = 0;
}
