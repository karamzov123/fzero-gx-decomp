/* Non-matching: best partial attempt (89.62% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_17_8B44_lbl_17_rodata_0 {
    u8 pad_0[0x3C];
    f32 unk_3C;
    u8 pad_40[0x60];
    f32 unk_A0;
    u8 pad_A4[0x144];
    f32 unk_1E8;
    u8 pad_1EC[0x8C];
    f32 unk_278;
    u8 pad_27C[0x34];
    f32 unk_2B0;
    u8 pad_2B4[0x14];
    f32 unk_2C8;
    f32 unk_2CC;
    f32 unk_2D0;
};

struct fn_17_8B44_ent16 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    const char *unk_C;
};

struct fn_17_8B44_lbl_17_data_0 {
    u8 pad_0[0x282C];
    const char *tbl_282C[0x18];
    const char *tbl_288C[0x4B];
    struct fn_17_8B44_ent16 tbl_29B8[0x1B0];
    u8 pad_44B8[0x1C];
    s8 buf_44D4[12];
    char buf_44E0[512];
};

struct fn_17_8B44_tab2 { const char **base; };
struct fn_17_8B44_tab16 { struct fn_17_8B44_ent16 *base; };

extern struct fn_17_8B44_lbl_17_rodata_0 lbl_17_rodata_0;
extern u8 lbl_17_data_0[];
extern s8 lbl_801A66B4;
extern void fn_1_49410(void *);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495A0(f32);
extern int fn_1_4AE0C(const char *, ...);

#pragma opt_propagation off
static inline const char * fn_17_8B44_array_read(const char * *array, s32 index) { return array[index]; }
#pragma opt_strength_reduction on
typedef struct lbl_17_bss_54_t {
    u8 lab_pad[4];
    u8 fzgx_u8_0;
    u8 pad_1[0x3];
} lbl_17_bss_54_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_17_bss_54_t fzgx_obj_lbl_17_bss_54;
u32 fzgx_obj_lbl_17_bss_58[2];
u32 fzgx_obj_lbl_17_bss_60[29];
u16 lbl_17_bss_60_fill_D4;
u16 fzgx_obj_lbl_17_bss_D6;
u32 fzgx_obj_lbl_17_bss_D8[8];
u16 lbl_17_bss_D8_fill_F8;
u16 lbl_17_bss_FA;
u32 lbl_17_bss_FA_fill_FC[20];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_17_bss_54;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_58;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_60;
    s = *(u8 *)&lbl_17_bss_60_fill_D4;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_D6;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_D8;
    s = *(u8 *)&lbl_17_bss_D8_fill_F8;
    s = *(u8 *)&lbl_17_bss_FA;
    s = *(u8 *)&lbl_17_bss_FA_fill_FC;
}
#pragma section code_type ".text"

static inline const char * * fn_17_8B44_read_pointer(struct fn_17_8B44_lbl_17_data_0 * owner) { return owner->tbl_282C; }
#pragma opt_common_subs off
u16 fn_17_8B44(f32 arg0) {
    struct fn_17_8B44_lbl_17_rodata_0 *p_rodata;
    struct fn_17_8B44_lbl_17_data_0 *p_data;
    struct fn_17_8B44_tab2 t1s;
    struct fn_17_8B44_tab2 t2s;
    struct fn_17_8B44_tab16 t3s;
    f32 v;

    p_rodata = (struct fn_17_8B44_lbl_17_rodata_0 *)&lbl_17_rodata_0;
    p_data = (struct fn_17_8B44_lbl_17_data_0 *)((u8 *)&lbl_17_data_0 + 0x60000);
    fn_1_49410(&lbl_17_data_0);
    fn_1_494DC(6);
    fn_1_495B0(0xC0000000);
    fn_1_495C8(1);
    fn_1_49590(p_rodata->unk_3C);
    v = p_rodata->unk_2B0;
    fn_1_4955C(v, v);
    fn_1_496FC(p_rodata->unk_A0, p_rodata->unk_2C8);
    fn_1_495A0(arg0);
    t1s.base = fn_17_8B44_read_pointer(p_data);
    fn_1_4AE0C((const char *)p_data->buf_44D4, fn_17_8B44_array_read(t1s.base, lbl_801A66B4), &lbl_801A66B4);
    fn_1_496FC(p_rodata->unk_A0, p_rodata->unk_2CC);
    v = p_rodata->unk_278;
    fn_1_4955C(v, v);
    t2s.base = p_data->tbl_288C;
    fn_1_4AE0C((const char *)p_data->buf_44D4, fn_17_8B44_array_read(t2s.base, lbl_801A66B4), &lbl_801A66B4);
    fn_1_496FC(p_rodata->unk_A0, p_rodata->unk_2D0);
    v = p_rodata->unk_1E8;
    fn_1_4955C(v, v);
    t3s.base = p_data->tbl_29B8;
    fn_1_4AE0C((const char *)p_data->buf_44E0, t3s.base[(*(u32 volatile *)(u32 *)&fzgx_obj_lbl_17_bss_54.fzgx_u8_0) /* Retail reloads this object. */].unk_C, (u32 *)&fzgx_obj_lbl_17_bss_54.fzgx_u8_0);
    return (u32)p_data;
}
#pragma opt_common_subs reset

#pragma opt_strength_reduction reset

