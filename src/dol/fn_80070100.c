#include "types.h"

extern void GXClearVtxDesc(void);
extern void fn_800723F8(void);
struct Sig_fn_800726C0_fn_800726C0_Entry {
    s32 unk_0;  /* GXAttr */
    s32 unk_4;  /* GXAttrType */
    s32 unk_8;  /* component count / type */
    u8 unk_c;   /* fraction bits */
};
extern void fn_800726C0(u32, struct Sig_fn_800726C0_fn_800726C0_Entry *);

/* three vertex-descriptor tables laid out consecutively in this TU's .data
   (retail addresses them off one base register: +0x0, +0xC0, +0x180);
   each list ends with attr 0xFF */
struct Sig_fn_800726C0_fn_800726C0_Entry lbl_8015A860[12] = {
    { 0x09, 1, 4, 0 }, { 0x0A, 0, 4, 0 }, { 0x0B, 1, 5, 0 }, { 0x0D, 1, 4, 0 },
    { 0x0E, 1, 4, 0 }, { 0x0F, 1, 4, 0 }, { 0x10, 1, 4, 0 }, { 0x11, 1, 4, 0 },
    { 0x12, 1, 4, 0 }, { 0x13, 1, 4, 0 }, { 0x14, 1, 4, 0 }, { 0xFF, 1, 4, 0 },
};
struct Sig_fn_800726C0_fn_800726C0_Entry fzgx_pool_fzgx_obj_lbl_8015A920[12] = {
    { 0x09, 1, 3, 13 }, { 0x0A, 0, 3, 14 }, { 0x0B, 1, 5, 0 }, { 0x0D, 1, 3, 13 },
    { 0x0E, 1, 3, 13 }, { 0x0F, 1, 3, 13 }, { 0x10, 1, 4, 0 }, { 0x11, 1, 4, 0 },
    { 0x12, 1, 4, 0 }, { 0x13, 1, 4, 0 }, { 0x14, 1, 4, 0 }, { 0xFF, 1, 4, 0 },
};
struct Sig_fn_800726C0_fn_800726C0_Entry fzgx_pool_fzgx_obj_lbl_8015A9E0[3] = {
    { 0x09, 1, 4, 0 }, { 0x0D, 1, 4, 0 }, { 0xFF, 1, 4, 0 },
};

void fn_80070100(void) {
    GXClearVtxDesc();
    fn_800723F8();
    fn_800726C0(0, lbl_8015A860);
    fn_800726C0(1, fzgx_pool_fzgx_obj_lbl_8015A920);
    fn_800726C0(7, fzgx_pool_fzgx_obj_lbl_8015A9E0);
}
