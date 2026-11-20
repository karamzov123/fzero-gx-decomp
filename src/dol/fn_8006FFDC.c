#include "types.h"


/* --- dol/fn_8006FFDC.c --- */
/* --- dol/fn_8006FFDC.c --- */
/* --- dol/fn_8006FFDC.c --- */
extern u16 lbl_801A6CC4;

s32 fn_8003401C(u16);                           /* extern */

u16 fn_8006FFDC(void) {
    u16 temp_r31;

    temp_r31 = *(u16 *)((u8 *)(&lbl_801A6CC4) + 0);
    fn_8003401C(*(u16 *)((u8 *)(&lbl_801A6CC4) + 0));
    (*(u16 *)((u8 *)(&lbl_801A6CC4) + 0)) += 1;
    return temp_r31;
}

/* --- dol/fn_8007001C.c --- */
extern u32 GXSetAlphaCompare(u32, u32, u32, u32, u32);
extern u32 fn_80072BD0(u32);
extern u32 fn_80074918(u32, u32, u32);

void fn_8007001C(void) {
    fn_80074918(1, 3, 1);
    GXSetAlphaCompare(7, 0, 0, 7, 0);
    fn_80072BD0(1);
}

/* --- dol/fn_80070068.c --- */
struct fn_80070068_lbl_801A6D30_T {
    u8 pad_0[0x14];
    u32 unk_14;
    u32 unk_18;
};

extern struct fn_80070068_lbl_801A6D30_T *lbl_801A6D30;
extern u32 GXSetCPUFifo(u32);
extern u32 fn_80032360(void);

s32 fn_80070068(void) {
    u32 v0;
    u32 v1;
    u32 t0, t1, t2;
    t0 = fn_80032360();
    v0 = lbl_801A6D30->unk_14;
    v1 = t0;
    if (t0 != v0) {
    v1 = v0;
    t1 = GXSetCPUFifo(v1);
    v1 = t1;
    v1 = 1;
    } else {
    v1 = lbl_801A6D30->unk_18;
    t2 = GXSetCPUFifo(v1);
    v1 = t2;
    v1 = 0;
    }
    return v1;
}

/* --- dol/fn_800700B4.c --- */
extern void GXGetGPStatus(u8 *, u8 *, u8 *, u8 *, u8 *);

void fn_800700B4(void) {
    u8 v3;
    u8 v2;
    u8 v1;
    u8 v0;

    do {
        GXGetGPStatus(&v3, &v3, &v2, &v1, &v0);
    } while (v2 != 1);
}

/* --- dol/fn_800700F4.c --- */
extern u8 lbl_801A6CB4;

void fn_800700F4(void) {
    lbl_801A6CB4 = 1;
}

/* --- dol/fn_80070100.c --- */
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
