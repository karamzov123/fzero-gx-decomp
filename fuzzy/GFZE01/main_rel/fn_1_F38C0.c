/* Non-matching: best partial attempt (98.47% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/replay.h"

extern u8 fn_1_86624(void);
extern void *fn_1_86254(int);
extern void fn_80008BEC(u8 *, int, u32);

void fn_1_F38C0(void) {
    Obj_1_bss_7EFD8 *obj;
    u8 *entries;
    s8 firstCount;
    s32 count;
    u8 *p;
    struct { int i; int zero1; } fzgx_copy_state;
    s32 value;
    u32 zero2;
    obj = (Obj_1_bss_7EFD8 *)&lbl_1_bss_7EFD8;
    entries = (u8 *)obj->unk_40 + 0xa4;
    obj->unk_10 = 9300;
    obj->unk_14 = 0xd9f8;
    fn_80008BEC((u8 *)&obj->unk_28, 0, 16);
    firstCount = (s8)fn_1_86624();
    count = firstCount;
    if ((s8)fn_1_86624() > 4) {
        count = 4;
    }
    for (p = entries; p < entries + count * 7; p += 7) {
        (&lbl_1_bss_7EFD8.unk_28)[*p & 3] = 1;
    }
    fzgx_copy_state.i = 0;
    fzgx_copy_state.zero1 = fzgx_copy_state.i;
    zero2 = fzgx_copy_state.i;
    for (; fzgx_copy_state.i < 4; fzgx_copy_state.i++) {
        if ((s32)(&lbl_1_bss_7EFD8.unk_28)[fzgx_copy_state.i] != 0) {
            value = (s8)obj->unk_40->unk_A0;
            *((s8 *)fn_1_86254(fzgx_copy_state.i) + 0x474) = value;
            obj->unk_40->unk_A0++;
        }
        (&lbl_1_bss_7EFD8.unk_1C)[fzgx_copy_state.i] = fzgx_copy_state.zero1;
        (&lbl_1_bss_7EFD8.unk_20)[fzgx_copy_state.i] = zero2;
    }
    obj->unk_40->unk_A0--;
    lbl_1_bss_7EFD8.unk_1A = 0;
    lbl_1_bss_7EFD8.unk_1B = 0;
}
