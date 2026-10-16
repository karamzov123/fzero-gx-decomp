/* Non-matching: best partial attempt (99.88% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[0x1F8];
} fn_1_707C_Entry;

typedef struct {
    u8 pad_0[0x6];
    s16 unk_6;
} fn_1_707C_Flag;

typedef struct {
    u8 lab_pad[4];
    fn_1_707C_Entry *entries;
    fn_1_707C_Flag *flags;
    Obj_1_bss_F68_Target *obj;
} fn_1_707C_Head;

#pragma peephole on
static inline fn_1_707C_Flag * fn_1_707C_read_pointer(fn_1_707C_Head * owner) { return owner->flags; }
#pragma opt_dead_assignments off
s32 fn_1_707C(u8 arg0) {
    u32 i;
    s32 value;
    fn_1_707C_Entry *cur;
    u32 count;
    u32 id;
    fn_1_707C_Entry *entries;
    fn_1_707C_Flag *flags;
    fn_1_707C_Head *head = (fn_1_707C_Head *)&lbl_1_bss_F68;
    Obj_1_bss_F68_Target *obj;
    fn_1_707C_Entry * fzgx_live;

    if ((obj = head->obj) == 0) {
        return 0;
    }

    fzgx_live = head->entries;
    entries = fzgx_live;
    i = 0;
    id = arg0;
    count = obj->unk_49;
    flags = fn_1_707C_read_pointer(head);
    cur = entries;

    {
    u32 fzgx_loop_i_1063;
for (fzgx_loop_i_1063 = 0; fzgx_loop_i_1063 < count; fzgx_loop_i_1063++) {
        if ((fzgx_loop_i_1063 == 0 && ((s8)obj->unk_48 == 9 || (s8)obj->unk_48 == 10)) ||
            (fzgx_loop_i_1063 == 3 && (s8)obj->unk_48 == 6)) {
            value = flags->unk_6;
        } else if (fzgx_loop_i_1063 == 1 && (s8)obj->unk_48 == 10) {
            value = entries->unk_2;
        } else {
            value = cur->unk_2;
        }
        if ((u32)value == id) {
            return 1;
        }
        cur = (fn_1_707C_Entry *)((u8 *)cur + 0x1FC);
    }
    i = fzgx_loop_i_1063;
}
    return 0;
}
#pragma opt_dead_assignments reset

#pragma peephole reset
