/* Non-matching: best partial attempt (95.54% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"

struct fn_3_4380_lbl_3_data_0 {
    u8 pad_0[0xB8];
    s32 unk_B8;
    u8 pad_BC[0x8];
    s16 unk_C4;
};
struct fn_3_4380_lbl_1_bss_8B3A0 {
    u8 pad_0[0x9E];
    u8 unk_9E;
};
typedef struct {
    s16 key;
    u16 pad;
    u32 mask;
} Sig_fn_1_152970_Fn152970Entry;
extern s16 lbl_1_bss_966;
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern s32 fn_8006FDEC(void);
extern struct fn_3_4380_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern u32 fn_1_152208(void *, u32, void *, u32, u32);
extern u32 lbl_3_bss_2C584[98];
extern void fn_1_4A00(s32, u8, void *);
extern void fn_3_29508(void);
extern void fn_3_4218(void);
extern void fn_3_7A08(s16 *, s16 *, int);
extern s32 fn_1_152970(s16 *, s16 *, s16, u32, Sig_fn_1_152970_Fn152970Entry *, s16, s16);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_3_bss_0[2];
u32 lbl_3_bss_8;
u32 lbl_3_bss_C[3];
u32 fzgx_obj_lbl_3_bss_18[2];
u8 fzgx_obj_lbl_3_bss_20;
u8 lbl_3_bss_20_fill_21;
u16 lbl_3_bss_20_fill_22;
u32 lbl_3_bss_20_fill_24[51];
u8 fzgx_obj_lbl_3_bss_F0;
u8 lbl_3_bss_F0_fill_F1;
u16 lbl_3_bss_F0_fill_F2;
u32 lbl_3_bss_F0_fill_F4[11];
s32 lbl_3_bss_120;
u32 lbl_3_bss_120_fill_124[7];
u32 lbl_3_bss_140_fill_140[32688];
u8 lbl_3_bss_140_1FEC0;
u8 lbl_3_bss_140_fill_20001;
u16 lbl_3_bss_140_fill_20002;
u32 lbl_3_bss_140_fill_20004[528];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_0;
    s = *(u8 *)&lbl_3_bss_8;
    s = *(u8 *)&lbl_3_bss_C;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20;
    s = *(u8 *)&lbl_3_bss_20_fill_21;
    s = *(u8 *)&lbl_3_bss_20_fill_22;
    s = *(u8 *)&lbl_3_bss_20_fill_24;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_F0;
    s = *(u8 *)&lbl_3_bss_F0_fill_F1;
    s = *(u8 *)&lbl_3_bss_F0_fill_F2;
    s = *(u8 *)&lbl_3_bss_F0_fill_F4;
    s = *(u8 *)&lbl_3_bss_120;
    s = *(u8 *)&lbl_3_bss_120_fill_124;
    s = *(u8 *)&lbl_3_bss_140_fill_140;
    s = *(u8 *)&lbl_3_bss_140_1FEC0;
    s = *(u8 *)&lbl_3_bss_140_fill_20001;
    s = *(u8 *)&lbl_3_bss_140_fill_20002;
    s = *(u8 *)&lbl_3_bss_140_fill_20004;
}
#pragma section code_type ".text"

void fn_3_4380(u32 arg0, u32 lab_unused0, u32 lab_unused1) {
    u8 *v4;
    struct { u8 *value; } p_lbl_3_bss_2C584;
    s32 v3;
    struct fn_3_4380_lbl_3_data_0 *p_lbl_3_data_0;
    u32 v0;
    s16 value, unused, lower, upper;
    s32 t2;
    s16 v1;
    s32 v2;
    p_lbl_3_data_0 = (struct fn_3_4380_lbl_3_data_0 *)&lbl_3_data_0;
    v0 = (u32)&fzgx_obj_lbl_3_bss_0 + 0x20000;
    v1 = *(s16 *)((u8 *)&fzgx_obj_lbl_3_bss_F0 + 6);
    if (lbl_1_bss_966 != 93) {
        fn_1_4A00(1, 15, (void *)*(u32 *)(v0 + 2128));
        v2 = p_lbl_3_data_0->unk_B8;
        *(u32 *)(v0 + 17320) = 0;
        if (v2 + 1 == 0) {
            fn_8006FDEC();
            t2 = fn_1_3F8C((u32)p_lbl_3_data_0 + 5768, (u32)fn_3_29508, 0, 8);
            p_lbl_3_data_0->unk_B8 = t2;
        }
        fn_3_4218();
        *(s16 *)((u8 *)&fzgx_obj_lbl_3_bss_20 + 196) = 0;
    }
    v3 = *(s16 *)((u8 *)&fzgx_obj_lbl_3_bss_F0 + 8) * 0x81C0;
    *(u32 *)((u8 *)&lbl_3_bss_140 + v3) |= 0x80000000;
    *(u32 *)((u8 *)&lbl_3_bss_140 + v3) &= 0xBFFFFFFF;
    fn_1_152208((u8 *)p_lbl_3_data_0 + 84, 42, lbl_3_bss_2C584, 7, 7);
    v2 = p_lbl_3_data_0->unk_C4;
    lbl_1_bss_8B3A0.unk_9E = v1;
    if (v2 == -1) {
        p_lbl_3_data_0->unk_C4 = 6;
    } else {
        p_lbl_3_bss_2C584.value = (u8 *)lbl_3_bss_2C584;
        v4 = (u8 *)&fzgx_obj_lbl_3_bss_20;
        do {
            fn_1_152970(&value, &unused, p_lbl_3_data_0->unk_C4, 0, (Sig_fn_1_152970_Fn152970Entry *)p_lbl_3_bss_2C584.value, 7, 7);
            fn_3_7A08(&lower, &upper, 3);
            if (value < lower || value > upper) {
                --*(s16 *)(v4 + 196);
            }
        } while (value < lower || value > upper);
    }
    lbl_3_bss_120 = -1;
}
