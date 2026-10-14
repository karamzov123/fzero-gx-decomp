/* Non-matching: best partial attempt (88.90% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"

typedef struct Fn_1_8DBB0_Info {
    u8 pad_00[9];
    u8 unk_09;
    u8 pad_0A[5302];
} Fn_1_8DBB0_Info;

typedef struct Fn_1_8DBB0_Result {
    u16 unk_00[5];
} Fn_1_8DBB0_Result;

typedef struct Fn_1_8DBB0_Entry {
    u8 pad_00[0x32C];
    u8 *unk_32C;
    u8 pad_330[0x5C];
    s8 unk_38C;
    u8 pad_38D[0x2D];
    s16 unk_3BA;
    u8 pad_3BC[0x84];
} Fn_1_8DBB0_Entry;

typedef struct Fn_1_8DBB0_State {
    u8 pad_00[0x1C];
    Fn_1_8DBB0_Entry *unk_1C;
    u8 pad_20[0x0A];
    s8 unk_2A;
    u8 pad_2B[0x1ED];
    u8 unk_218;
    u8 pad_219[0xDF3];
    Fn_1_8DBB0_Result unk_100C[300];
} Fn_1_8DBB0_State;

typedef struct Sig_fn_1_A7E60_FnA7E60Object {
    u8 pad_fc[0xFC];
    s32 unk_fc;
    s32 unk_100;
    s32 unk_104;
    s32 unk_108;
} Sig_fn_1_A7E60_FnA7E60Object;

extern void fn_1_3EF14(void *);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_3BDC(s32);
extern u32 fn_1_3C18(s32);
extern s32 fn_1_84860(void *);
extern f32 lbl_1_rodata_3518[6];
extern const f32 lbl_1_rodata_3E2C;
extern u32 lbl_8006DCA4(void);
extern void lbl_8006DD7C(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006DB74(Sig_fn_1_A7E60_FnA7E60Object *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6D820;
u32 fzgx_obj_lbl_1_bss_6D824;
u32 lbl_1_bss_6D828;
u32 fzgx_obj_lbl_1_bss_6D82C[3];
u32 fzgx_obj_lbl_1_bss_6D838;
Fn_1_8DBB0_Entry *fzgx_obj_lbl_1_bss_6D83C;
u32 lbl_1_bss_6D83C_fill_6D840[2];
u16 lbl_1_bss_6D83C_fill_6D848;
s8 fzgx_obj_lbl_1_bss_6D84A;
u8 lbl_1_bss_6D84A_fill_6D84B;
u32 lbl_1_bss_6D84A_fill_6D84C;
u32 lbl_1_bss_6D850;
u32 lbl_1_bss_6D854[4];
u32 fzgx_obj_lbl_1_bss_6D864;
u8 fzgx_obj_lbl_1_bss_6D868;
u8 lbl_1_bss_6D820_gap_6D869;
u16 lbl_1_bss_6D820_gap_6D869_fill_6D86A;
u32 lbl_1_bss_6D86C[34];
u32 lbl_1_bss_6D8F4[31];
u32 lbl_1_bss_6D970;
u32 lbl_1_bss_6D974;
u32 lbl_1_bss_6D978;
u32 lbl_1_bss_6D97C;
u32 lbl_1_bss_6D980[8];
u32 lbl_1_bss_6D9A0_fill_6D9A0[38];
u8 lbl_1_bss_6D9A0_98;
u8 lbl_1_bss_6D9A0_fill_6DA39;
u16 lbl_1_bss_6D9A0_fill_6DA3A;
u32 lbl_1_bss_6D9A0_fill_6DA3C[8];
u32 lbl_1_bss_6DA5C[7];
u16 lbl_1_bss_6DA5C_fill_6DA78;
u8 lbl_1_bss_6DA7A;
u8 lbl_1_bss_6DA7B;
u32 lbl_1_bss_6DA7B_fill_6DA7C;
u32 lbl_1_bss_6DA80[440];
u32 lbl_1_bss_6E160[435];
u8 lbl_1_bss_6E82C;
u8 lbl_1_bss_6E82C_fill_6E82D;
u16 lbl_1_bss_6E82C_fill_6E82E;
u32 lbl_1_bss_6E82C_fill_6E830[74];
u32 fzgx_obj_lbl_1_bss_6E958[2];
u32 fzgx_obj_lbl_1_bss_6E960[6];
u32 lbl_1_bss_6E978[3];
u32 lbl_1_bss_6E984;
u16 lbl_1_bss_6E988;
u16 lbl_1_bss_6D820_gap_6E98A;
u32 lbl_1_bss_6E98C;
u32 lbl_1_bss_6E990[28];
u32 fzgx_obj_lbl_1_bss_6EA00;
u32 fzgx_obj_lbl_1_bss_6EA04;
u32 fzgx_obj_lbl_1_bss_6EA08;
u32 lbl_1_bss_6EA0C;
u32 lbl_1_bss_6EA10[12];
u32 lbl_1_bss_6EA40[4];
u32 lbl_1_bss_6EA50;
u32 lbl_1_bss_6EA54;
u32 lbl_1_bss_6EA58[4];
u32 lbl_1_bss_6EA68[4];
u32 lbl_1_bss_6EA78;
u32 lbl_1_bss_6EA7C;
u32 fzgx_obj_lbl_1_bss_6EA80;
u32 fzgx_obj_lbl_1_bss_6EA84;
u32 fzgx_obj_lbl_1_bss_6EA88[2];
u32 lbl_1_bss_6EA90;
u16 lbl_1_bss_6EA94;
u16 fzgx_obj_lbl_1_bss_6EA96;
u32 fzgx_obj_lbl_1_bss_6EA98;
u32 fzgx_obj_lbl_1_bss_6EA9C[2];
u8 lbl_1_bss_6EAA4;
u8 lbl_1_bss_6D820_gap_6EAA5;
u8 lbl_1_bss_6EAA6;
u8 lbl_1_bss_6D820_gap_6EAA7;
u32 lbl_1_bss_6EAA8[2];
u8 lbl_1_bss_6EAB0;
u8 lbl_1_bss_6D820_gap_6EAB1;
u16 lbl_1_bss_6D820_gap_6EAB1_fill_6EAB2;
u32 fzgx_obj_lbl_1_bss_6EAB4[4];
u16 lbl_1_bss_6EAB4_fill_6EAC4;
u16 fzgx_obj_lbl_1_bss_6EAC6;
u32 lbl_1_bss_6EAC6_fill_6EAC8[2];
u32 fzgx_obj_lbl_1_bss_6EAD0[450];
u8 fzgx_obj_lbl_1_bss_6F1D8;
u8 lbl_1_bss_6D820_gap_6F1D9;
u16 lbl_1_bss_6D820_gap_6F1D9_fill_6F1DA;
u32 fzgx_obj_lbl_1_bss_6F1DC;
u8 fzgx_obj_lbl_1_bss_6F1E0;
u8 lbl_1_bss_6F1E1;
u16 lbl_1_bss_6D820_gap_6F1E2;
u32 fzgx_obj_lbl_1_bss_6F1E4[21];
u8 lbl_1_bss_6F1E4_fill_6F238;
u8 lbl_1_bss_6F239;
u16 lbl_1_bss_6D820_gap_6F23A;
u32 lbl_1_bss_6F23C;
u16 lbl_1_bss_6F23C_fill_6F240;
u8 lbl_1_bss_6F23C_fill_6F242;
u8 fzgx_obj_lbl_1_bss_6F243;
u32 lbl_1_bss_6F244[32];
u8 lbl_1_bss_6F2C4;
u8 lbl_1_bss_6D820_gap_6F2C5;
u16 lbl_1_bss_6D820_gap_6F2C5_fill_6F2C6;
u32 lbl_1_bss_6F2C8[4];
u32 lbl_1_bss_6F2D8[15];
u16 lbl_1_bss_6F2D8_fill_6F314;
u8 lbl_1_bss_6F316;
u8 lbl_1_bss_6F317;
u16 lbl_1_bss_6D820_gap_6F318;
u16 lbl_1_bss_6F31A;
u32 lbl_1_bss_6F31A_fill_6F31C[34];
u32 lbl_1_bss_6F3A4[30];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D820;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D824;
    s = *(u8 *)&lbl_1_bss_6D828;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D82C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D838;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D83C;
    s = *(u8 *)&lbl_1_bss_6D83C_fill_6D840;
    s = *(u8 *)&lbl_1_bss_6D83C_fill_6D848;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D84A;
    s = *(u8 *)&lbl_1_bss_6D84A_fill_6D84B;
    s = *(u8 *)&lbl_1_bss_6D84A_fill_6D84C;
    s = *(u8 *)&lbl_1_bss_6D850;
    s = *(u8 *)&lbl_1_bss_6D854;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D864;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D868;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6D869;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6D869_fill_6D86A;
    s = *(u8 *)&lbl_1_bss_6D86C;
    s = *(u8 *)&lbl_1_bss_6D8F4;
    s = *(u8 *)&lbl_1_bss_6D970;
    s = *(u8 *)&lbl_1_bss_6D974;
    s = *(u8 *)&lbl_1_bss_6D978;
    s = *(u8 *)&lbl_1_bss_6D97C;
    s = *(u8 *)&lbl_1_bss_6D980;
    s = *(u8 *)&lbl_1_bss_6D9A0_fill_6D9A0;
    s = *(u8 *)&lbl_1_bss_6D9A0_98;
    s = *(u8 *)&lbl_1_bss_6D9A0_fill_6DA39;
    s = *(u8 *)&lbl_1_bss_6D9A0_fill_6DA3A;
    s = *(u8 *)&lbl_1_bss_6D9A0_fill_6DA3C;
    s = *(u8 *)&lbl_1_bss_6DA5C;
    s = *(u8 *)&lbl_1_bss_6DA5C_fill_6DA78;
    s = *(u8 *)&lbl_1_bss_6DA7A;
    s = *(u8 *)&lbl_1_bss_6DA7B;
    s = *(u8 *)&lbl_1_bss_6DA7B_fill_6DA7C;
    s = *(u8 *)&lbl_1_bss_6DA80;
    s = *(u8 *)&lbl_1_bss_6E160;
    s = *(u8 *)&lbl_1_bss_6E82C;
    s = *(u8 *)&lbl_1_bss_6E82C_fill_6E82D;
    s = *(u8 *)&lbl_1_bss_6E82C_fill_6E82E;
    s = *(u8 *)&lbl_1_bss_6E82C_fill_6E830;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6E958;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6E960;
    s = *(u8 *)&lbl_1_bss_6E978;
    s = *(u8 *)&lbl_1_bss_6E984;
    s = *(u8 *)&lbl_1_bss_6E988;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6E98A;
    s = *(u8 *)&lbl_1_bss_6E98C;
    s = *(u8 *)&lbl_1_bss_6E990;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA00;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA04;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA08;
    s = *(u8 *)&lbl_1_bss_6EA0C;
    s = *(u8 *)&lbl_1_bss_6EA10;
    s = *(u8 *)&lbl_1_bss_6EA40;
    s = *(u8 *)&lbl_1_bss_6EA50;
    s = *(u8 *)&lbl_1_bss_6EA54;
    s = *(u8 *)&lbl_1_bss_6EA58;
    s = *(u8 *)&lbl_1_bss_6EA68;
    s = *(u8 *)&lbl_1_bss_6EA78;
    s = *(u8 *)&lbl_1_bss_6EA7C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA80;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA84;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA88;
    s = *(u8 *)&lbl_1_bss_6EA90;
    s = *(u8 *)&lbl_1_bss_6EA94;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA96;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA98;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EA9C;
    s = *(u8 *)&lbl_1_bss_6EAA4;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6EAA5;
    s = *(u8 *)&lbl_1_bss_6EAA6;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6EAA7;
    s = *(u8 *)&lbl_1_bss_6EAA8;
    s = *(u8 *)&lbl_1_bss_6EAB0;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6EAB1;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6EAB1_fill_6EAB2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAB4;
    s = *(u8 *)&lbl_1_bss_6EAB4_fill_6EAC4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAC6;
    s = *(u8 *)&lbl_1_bss_6EAC6_fill_6EAC8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6EAD0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1D8;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6F1D9;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6F1D9_fill_6F1DA;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1DC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E0;
    s = *(u8 *)&lbl_1_bss_6F1E1;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6F1E2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F1E4;
    s = *(u8 *)&lbl_1_bss_6F1E4_fill_6F238;
    s = *(u8 *)&lbl_1_bss_6F239;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6F23A;
    s = *(u8 *)&lbl_1_bss_6F23C;
    s = *(u8 *)&lbl_1_bss_6F23C_fill_6F240;
    s = *(u8 *)&lbl_1_bss_6F23C_fill_6F242;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6F243;
    s = *(u8 *)&lbl_1_bss_6F244;
    s = *(u8 *)&lbl_1_bss_6F2C4;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6F2C5;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6F2C5_fill_6F2C6;
    s = *(u8 *)&lbl_1_bss_6F2C8;
    s = *(u8 *)&lbl_1_bss_6F2D8;
    s = *(u8 *)&lbl_1_bss_6F2D8_fill_6F314;
    s = *(u8 *)&lbl_1_bss_6F316;
    s = *(u8 *)&lbl_1_bss_6F317;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6F318;
    s = *(u8 *)&lbl_1_bss_6F31A;
    s = *(u8 *)&lbl_1_bss_6F31A_fill_6F31C;
    s = *(u8 *)&lbl_1_bss_6F3A4;
}
#pragma section code_type ".text"

#pragma opt_lifetimes off
#pragma opt_common_subs off
void fn_1_8DBB0(void) {
    Fn_1_8DBB0_Info info;
    s32 k;
    s32 i;
    Fn_1_8DBB0_Entry *e;
    s16 idx;
    s8 k_2;
    s32 j;

    
    fn_1_3EF14(&info);
    fn_80008BEC((*(Fn_1_8DBB0_Result (*)[300])&lbl_1_bss_6E82C), 0, 300);
    lbl_1_bss_6D9A0_98 = 1;
    {
    s32 fzgx_loop_i_9124;
for (fzgx_loop_i_9124 = 0; fzgx_loop_i_9124 < (s32)info.unk_09; fzgx_loop_i_9124++) {
        idx = (s8)fzgx_loop_i_9124;
        j = 0;
        while (j < 5) {
            if (idx < fzgx_obj_lbl_1_bss_6D84A && fzgx_obj_lbl_1_bss_6D83C != 0) {
                e = &fzgx_obj_lbl_1_bss_6D83C[idx];
            } else {
                e = 0;
            }
            lbl_8006DCA4();
            lbl_8006DD7C();
            lbl_8006E0B4(lbl_1_rodata_3518[0], lbl_1_rodata_3518[0], lbl_1_rodata_3E2C);
            lbl_8006DB74((Sig_fn_1_A7E60_FnA7E60Object *)((u8 *)e->unk_32C + 0x14C));
            k = (s8)((s8)j);
            if (k == 5) {
                if (k < 0 || k > 5) {
                    k_2 = (k_2 < 0) ? 0 : ((k_2 > 5) ? 5 : k_2);
                } else {
                    for (k_2 = (s8)j; k_2 < 5; k_2++) {
                        if (e->unk_38C & (1 << k_2)) {
                            break;
                        }
                    }
                    k_2 = -1;
                }
            }
            j = k_2;
            if (j == -1) {
                break;
            }
            e->unk_3BA = (s16)j;
            fn_1_3BDC(0);
            fn_1_84860(e);
            (*(Fn_1_8DBB0_Result (*)[300])&lbl_1_bss_6E82C)[fzgx_loop_i_9124].unk_00[j] = fn_1_3C18(0);
            j++;
        }
    }
    i = fzgx_loop_i_9124;
}
    lbl_1_bss_6D9A0_98 = 0;
}
#pragma opt_common_subs reset

#pragma opt_lifetimes reset

