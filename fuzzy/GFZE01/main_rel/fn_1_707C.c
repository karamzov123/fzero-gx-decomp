/* Non-matching: best partial attempt (99.23% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

typedef struct {
    u8 lab_pad[4];
    u32 unk_0;
    u32 unk_8;
    u32 unk_4;
} fn_1_707C_Head;

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[0x1F8];
} fn_1_707C_Entry;

typedef struct {
    u8 lab_pad[4];
    u8 pad_0[0x2];
    s16 unk_6;
} fn_1_707C_Flag;

#pragma peephole on
#pragma opt_loop_invariants off
s32 fn_1_707C(u8 arg0) {
    s32 count;
    s32 value;
    fn_1_707C_Flag *flags;
    fn_1_707C_Entry *cur;
    fn_1_707C_Entry *entries;
    u32 i_2;
    Obj_1_bss_F68_Target *obj;
    u32 i;
    u32 id;
    fn_1_707C_Head *head = (fn_1_707C_Head *)(void *)&lbl_1_bss_F68;

    if ((obj = (Obj_1_bss_F68_Target *)(void *)head->unk_0) == 0) {
        return 0;
    }
    entries = (fn_1_707C_Entry *)(void *)head->unk_4;
    count = obj->unk_49;
    cur = entries;
    id = arg0;
    i = 0;
    flags = (fn_1_707C_Flag *)(void *)head->unk_8;

    {
    u32 fzgx_loop_i_899;
for (fzgx_loop_i_899 = 0; fzgx_loop_i_899 < count; fzgx_loop_i_899++) {
        if ((((0) == (fzgx_loop_i_899)) && ((s8)obj->unk_48 == 9 || (s8)obj->unk_48 == 10)) ||
            (((3) == (fzgx_loop_i_899)) && ((6) == ((s32)obj->unk_48)))) {
            value = flags->unk_6;
        } else if (((1) == (fzgx_loop_i_899)) && ((10) == ((s32)obj->unk_48))) {
            value = entries->unk_2;
        } else {
            value = cur->unk_2;
        }
        if ((((((u32)value)) == ((id))))) {
            return 1;
        }
        cur = (fn_1_707C_Entry *)(((0x1FC) + ((u8 *)cur)));
    }
    i_2 = fzgx_loop_i_899;
}
    return 0;
}
#pragma opt_loop_invariants reset

#pragma peephole reset
