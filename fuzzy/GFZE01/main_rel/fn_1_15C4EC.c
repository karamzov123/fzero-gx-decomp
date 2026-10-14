/* Non-matching: best partial attempt (78.26% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_win.h"

extern u32 fn_80074188(u32, u32, u32, u32);

typedef struct {
    u8 pad_0[0x54];
    f32 unk_54;
} ColorInput;

void fn_1_15C4EC(ColorInput *arg) {
    s32 index = (s32)arg->unk_54;
    fn_80074188(*(f32 *)((u8 *)&lbl_1_bss_8FD68 + index * 16),
        *(f32 *)((u8 *)&lbl_1_bss_8FD68.unk_4 + index * 16),
        *(f32 *)((u8 *)&lbl_1_bss_8FD68.unk_8 + index * 16),
        *(f32 *)((u8 *)&lbl_1_bss_8FD68.unk_C + index * 16));
}
