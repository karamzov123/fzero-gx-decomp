/* Non-matching: best partial attempt (87.60% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"
#pragma use_lmw_stmw on
#pragma opt_propagation off
#pragma opt_common_subs off

extern u8 lbl_80092350[52];
extern void strncpy(void *, void *, int);
extern u32 SVM_CallErr(u32, ...);

typedef struct {
    void (*fn)();
    u32 arg;
} Cb5912C;
typedef struct {
    u32 fn;
    u32 arg;
} Entry5912C;

void fn_8005912C(s32 arg0, s32 arg1, u32 arg2, u32 arg3) {
    Obj_8018FEB0 *state;
    u8 *pool;
    Cb5912C *cb;
    u8 *tbl;
    Entry5912C *entry;
    pool = lbl_80092350;
    state = (Obj_8018FEB0 *)&lbl_8018FEB0;
    if (arg1 < 0 || arg1 >= 6) {
        strncpy((u8 *)state + 0x30, pool + 0xD0, 127);
        cb = (Cb5912C *)((u8 *)state + 0xB0);
        if (*(u32 *)((u8 *)state + 0xB0) != 0) {
            cb->fn(cb->arg, (u8 *)state + 0x30);
        }
    }
    if (arg0 < 0 || arg1 >= 8) {
        strncpy((u8 *)state + 0x30, pool + 0xF4, 127);
        cb = (Cb5912C *)((u8 *)state + 0xB0);
        if (*(u32 *)((u8 *)state + 0xB0) != 0) {
            cb->fn(cb->arg, (u8 *)state + 0x30);
        }
    }
    cb = (Cb5912C *)((u8 *)state + 0xC0);
    if (*(u32 *)((u8 *)state + 0xC0) != 0) {
        cb->fn(cb->arg);
        if ((s32)state->unk_4 == 0) {
            state->unk_8 = 1;
        }
        state->unk_4++;
    }
    tbl = (u8 *)state + 0x108;
    entry = (Entry5912C *)(tbl + arg0 * 0x30 + arg1 * 8);
    if (entry->fn != 0) {
        strncpy((u8 *)state + 0x30, pool + 0x11C, 127);
        cb = (Cb5912C *)((u8 *)state + 0xB0);
        if (*(u32 *)((u8 *)state + 0xB0) != 0) {
            cb->fn(cb->arg, (u8 *)state + 0x30);
        }
    }
    entry->fn = arg2;
    entry->arg = arg3;
    cb = (Cb5912C *)((u8 *)state + 0xB8);
    if (*(u32 *)((u8 *)state + 0xB8) != 0) {
        state->unk_4 = state->unk_4 - 1;
        if ((s32)state->unk_4 == 0) {
            if ((s32)state->unk_8 != 1) {
                SVM_CallErr((u32)(pool + 0x34), state->unk_8, 1);
            }
            state->unk_8 = 0;
        }
        cb->fn(cb->arg);
    }
}
