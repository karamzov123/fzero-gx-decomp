/* Non-matching: best partial attempt (98.26% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/archive.h"

extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);
extern s32 fn_8006A480(void *arg0, void *arg1, void *arg2);
extern u32 fn_8006A998(void *arg0);
extern u32 fn_8006A9AC(void *arg0);
extern u32 fn_1_4630(u32 arg0, u32 arg1, u8 *arg2, u32 arg3);
extern s32 fn_1_D35B0(void *arg0, u32 arg1, void *arg2);
extern s32 fn_1_D358C(void *arg0, void *arg1);
extern void fn_80008BA8(u32 arg0, u32 arg1, u32 arg2);
extern u32 lbl_801A6410;

struct Obj_897AC {
    u8 pad_0[0x4C];
    u8 body[0x20];
};

struct Lbl_1_bss_897A0 {
    u32 unk_0;
    s32 unk_4;
    s32 unk_8;
    struct Obj_897AC entries[1];
};

s32 fn_1_12ADC8(void *arg0, void *arg1, void *arg2, void *arg3) {
    u32 loc_14[11];
    u32 loc_8[3];
    struct Lbl_1_bss_897A0 *p = (struct Lbl_1_bss_897A0 *)&lbl_1_bss_897A0;
    void *a3 = arg3;
    void *a2 = arg2;
    void *a1 = arg1;
    u32 v0;
    u32 v26;

    if (p->unk_4 != 0) {
        struct Obj_897AC *tbl = p->entries;
        if (fn_8006A480(tbl[p->unk_0].body, arg0, loc_14) != 0) {
            v0 = fn_8006A998(loc_14);
        } else {
            v0 = 0;
        }
        v26 = v0;
        if (v0 != 0) {
            if ((a2 != 0) && (a3 != 0)) {
                if (fn_8006A480(tbl[p->unk_0].body, arg0, loc_8) == 0) {
                    OSPanic(lbl_1_data_40608, 0x1BE, lbl_1_data_4076C);
                }
                *(u32 *)a3 = fn_8006A9AC(loc_8);
                if (*(u32 *)a3 != 0) {
                    *(u32 *)a2 = fn_1_4630(lbl_801A6410, *(u32 *)a3, lbl_1_data_40608, 0x22A);
                    fn_80008BA8(*(u32 *)a2, v0, *(u32 *)a3);
                    v26 = *(u32 *)a2;
                }
                return fn_1_D35B0((void *)v26, 0, a1);
            }
            return fn_1_D35B0((void *)v0, 0, a1);
        }
        if (p->unk_8 != 0) {
            return fn_1_D358C(arg0, a1);
        }
        return 0;
    }
    return fn_1_D358C(arg0, a1);
}
