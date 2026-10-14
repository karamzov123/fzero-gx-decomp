/* Non-matching: best partial attempt (92.46% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_win.h"

extern void *fn_1_435C(void *arg);
extern void fn_1_15E1E8(u8 *value);
extern void fn_1_3F8C(void *arg0, void *arg1, u8 *arg2, s32 arg3);

typedef struct {
    u8 unk_0;
    u8 pad_1[8];
    u8 name[0x2B];
} WinEnt;

typedef struct {
    u8 pad_0[0x40];
    WinEnt ents[4];
    u8 pad_110[4];
    u8 flag;
    u8 pad_115[3];
    s32 table[4];
    u8 pad_128[0x10];
    void *arg;
} Win8FD68;

#pragma opt_strength_reduction off
#pragma opt_dead_assignments off
static inline void * fn_1_15E44C_read_pointer(Win8FD68 * owner) { return owner->arg; }
#pragma opt_dead_assignments reset

static inline WinEnt *fn_1_15E44C_entries(Win8FD68 *owner) { return owner->ents; }
#pragma opt_strength_reduction reset

#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_15E44C(void) {
    Win8FD68 *m = (Win8FD68 *)&lbl_1_bss_8FD68;
    s32 *table = m->table;
    WinEnt *e;
    u8 a = lbl_1_bss_3C30.unk_13F5;
    void *arg = fn_1_15E44C_read_pointer(m);
    s32 v = *(s32 *)((u8 *)table + ((a - 1) % 4) * 4);
    void *res;
    s32 off;
    s16 b;

    if (m->flag == 0) {
        return;
    }
    b = lbl_1_bss_3C30.unk_13F4;
    m->flag = 0;
    if (b - a >= 4) {
        return;
    }
    if (v == -1) {
        return;
    }
    off = v * 0x34;
    e = (WinEnt *)((u8 *)fn_1_15E44C_entries(m) + off);
    e->unk_0 |= 0x10;
    res = fn_1_435C(arg);
    fn_1_3F8C("count_down_event", fn_1_15E1E8, e->name, 0xd);
    ((WinEnt *)((u8 *)fn_1_15E44C_entries(m) + off))->name[0] = 0x3c;
    fn_1_435C(res);
}
#pragma opt_propagation reset

#pragma opt_common_subs reset

