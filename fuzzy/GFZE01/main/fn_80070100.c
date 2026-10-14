/* Non-matching: best partial attempt (97.27% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
struct Sig_fn_800726C0_fn_800726C0_Entry {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    u8 unk_c;
};

extern u8 lbl_8015A860[];
extern void GXClearVtxDesc(void);
extern void fn_800723F8(void);
extern void fn_800726C0(u32, struct Sig_fn_800726C0_fn_800726C0_Entry *);

void fn_80070100(void) {
    struct { u8 *value; } p_lbl_8015A860;
    p_lbl_8015A860.value = (u8 *)&lbl_8015A860;
    GXClearVtxDesc();
    fn_800723F8();
    fn_800726C0(0, (struct Sig_fn_800726C0_fn_800726C0_Entry *)(p_lbl_8015A860.value + 0));
    fn_800726C0(1, (struct Sig_fn_800726C0_fn_800726C0_Entry *)(p_lbl_8015A860.value + 192));
    fn_800726C0(7, (struct Sig_fn_800726C0_fn_800726C0_Entry *)(p_lbl_8015A860.value + 384));
}
