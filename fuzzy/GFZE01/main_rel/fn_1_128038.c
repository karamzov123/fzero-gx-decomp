/* Non-matching: best partial attempt (98.11% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

struct Sig80077B14Arg {
    u8 pad_00[0x4];
    u32 unk_04;
    u8 pad_08[0x18];
    u32 unk_20;
};

typedef struct AccSig {
    u16 id;
    u8 pad_02[6];
    void *unk_08;
} AccSig;

typedef struct AccItem {
    u8 pad_00[0x88];
    s32 kind;
    u8 pad_8C[0xBC];
    AccSig sig_148;
} AccItem;

typedef struct BoneSet {
    u8 pad_00[2];
    u8 count;
    u8 pad_03[1];
    u16 index[6];
    u8 pad_10[0x18];
    u8 unk_28[0x1C];
} BoneSet;

typedef struct Accessory {
    u8 flag_00;
    u8 pad_01[3];
    u32 pad_04;
    u32 index_08;
    AccItem *item_0C;
    struct Sig80077B14Arg *sig_10;
    u32 pad_14;
    u32 count_18;
    u32 pad_1C[2];
    BoneSet *bones_24;
} Accessory;

typedef struct Mat44 {
    f32 v[12];
} Mat44;

extern void fn_1_1091D4(void);
extern void fn_1_10976C(void);
extern void fn_1_10A43C(void);
extern void fn_1_10A6A0(void);
extern void fn_1_10A8D0(void);
extern void fn_1_10AD18(void);
extern void fn_1_10B344(void);
extern void fn_1_10B5A8(void);
extern void fn_1_10B7D8(void);
extern void fn_1_10B800(void);
extern void fn_1_10BA00(void);
extern void fn_1_10BE3C(void);
extern void fn_1_10C4E4(void);
extern void fn_1_10C7B4(void);
extern void fn_1_10C9B0(void);
extern void fn_1_10CC38(void);
extern void fn_1_10D2F0(void);
extern void fn_1_10D7D4(void);
extern void fn_1_10DDE4(void);
extern void fn_1_10E3B4(void);
extern void fn_1_110008(void);
extern void fn_1_110478(void);
extern void fn_1_111510(void);
extern void fn_1_111980(void);
extern void fn_1_112F40(void);
extern void fn_1_1132E4(void);
extern void fn_1_1137E4(void);
extern void fn_1_113C58(void);
extern void fn_1_1145C8(void);
extern void fn_1_11492C(void);
extern void fn_1_1154D0(void);
extern void fn_1_115560(void);
extern void fn_1_115B58(void);
extern void fn_1_115BE8(void);
extern void fn_1_1166EC(void);
extern void fn_1_11677C(void);
extern void fn_1_1171B8(void);
extern void fn_1_117424(void);
extern void fn_1_1177C4(void);
extern void fn_1_117D5C(void);
extern void fn_1_1185B4(void);
extern void fn_1_1188CC(void);
extern void fn_1_118D90(void);
extern void fn_1_1192D0(void);
extern void fn_1_11A158(void);
extern void fn_1_11A774(void);
extern void fn_1_11B4E4(void);
extern void fn_1_11B958(void);
extern void fn_1_11BFCC(void);
extern void fn_1_11C440(void);
extern void fn_1_11CAB4(void);
extern void fn_1_11CD3C(void);
extern void fn_1_11D1FC(void);
extern void fn_1_11DE2C(void);
extern void fn_1_11ED0C(void);
extern void fn_1_11F250(void);
extern void fn_1_1201E4(void);
extern void fn_1_120804(void);
extern void fn_1_122348(void);
extern void fn_1_12277C(void);
extern void fn_1_12295C(void);
extern void fn_1_123050(void);
extern void fn_1_1244F0(void);
extern void fn_1_124AD4(void);
extern void fn_1_1250D0(void);
extern void fn_1_1256EC(void);
extern void fn_1_125CE8(void);
extern void fn_1_125DF0(void);
extern void fn_1_1262A4(void);
extern void fn_1_126774(void);
extern void fn_1_126DE8(void);
extern void fn_1_12744C(void);
extern void fn_1_127FB8(void);
void fn_1_128038(Accessory *a);
/* file-scope initialized objects of the retail TU, in retail order (off one section base) */
u32 fzgx_obj_lbl_1_data_3F510[26] = {0x00000000, 0x00000000, 0x00000000, 0x40000000, 0xBF800000, 0xBFC00000, 0x878787FF, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x3F733333, 0x00000000, 0x42B40000, 0x00000000, 0x00000000, 0x00000000, 0x40000000, 0xBF800000, 0x3FC00000, 0x878787FF, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x3F733333, 0x00000000, 0x42B40000};
char fzgx_obj_lbl_1_data_3F578[18] = "GORDON_MOMO_R_vtx";
char fzgx_obj_lbl_1_data_3F58C[18] = "GORDON_MOMO_L_vtx";
char fzgx_obj_lbl_1_data_3F5A0[17] = "GORDON_ERI_O_vtx";
char fzgx_obj_lbl_1_data_3F5B4[17] = "GORDON_ERI_U_vtx";
char fzgx_obj_lbl_1_data_3F5C8[17] = "FALCON_ERI_O_vtx";
char fzgx_obj_lbl_1_data_3F5DC[17] = "FALCON_ERI_U_vtx";
char fzgx_obj_lbl_1_data_3F5F0[19] = "FALCON_FRONT_O_vtx";
char fzgx_obj_lbl_1_data_3F604[19] = "FALCON_FRONT_U_vtx";
char fzgx_obj_lbl_1_data_3F618[21] = "FALCON_ACCESSORY_vtx";
char fzgx_obj_lbl_1_data_3F630[19] = "FALCON_KATAATE_vtx";
char fzgx_obj_lbl_1_data_3F644[17] = "JAMES_HAIR_A_vtx";
char fzgx_obj_lbl_1_data_3F658[17] = "JAMES_HAIR_B_vtx";
char fzgx_obj_lbl_1_data_3F66C[17] = "JAMES_HAIR_C_vtx";
char fzgx_obj_lbl_1_data_3F680[17] = "JAMES_JACKET_vtx";
char fzgx_obj_lbl_1_data_3F694[20] = "JAMES_ACCESSORY_vtx";
char fzgx_obj_lbl_1_data_3F6A8[15] = "ARROW_MANT_vtx";
char fzgx_obj_lbl_1_data_3F6B8[16] = "SHADOW_MANT_vtx";
char fzgx_obj_lbl_1_data_3F6C8[14] = "BOSS_MANT_vtx";
char fzgx_obj_lbl_1_data_3F6D8[13] = "BOSS_ERI_vtx";
char fzgx_obj_lbl_1_data_3F6E8[20] = "GUSTER_JACKET_O_vtx";
char fzgx_obj_lbl_1_data_3F6FC[17] = "GUSTER_ERI_O_vtx";
char fzgx_obj_lbl_1_data_3F710[17] = "GUSTER_ERI_U_vtx";
char fzgx_obj_lbl_1_data_3F724[18] = "STEWART_SCARF_vtx";
char fzgx_obj_lbl_1_data_3F738[15] = "GOMA_SCARF_vtx";
char fzgx_obj_lbl_1_data_3F748[17] = "GOMA_KOSHI_R_vtx";
char fzgx_obj_lbl_1_data_3F75C[17] = "GOMA_KOSHI_L_vtx";
char fzgx_obj_lbl_1_data_3F770[15] = "SHIO_SCARF_vtx";
char fzgx_obj_lbl_1_data_3F780[16] = "SHIO_KOSI_R_vtx";
char fzgx_obj_lbl_1_data_3F790[16] = "SHIO_KOSI_L_vtx";
char fzgx_obj_lbl_1_data_3F7A0[16] = "BLOOD_SCARF_vtx";
char fzgx_obj_lbl_1_data_3F7B0[16] = "BLOOD_ERI_O_vtx";
char fzgx_obj_lbl_1_data_3F7C0[16] = "BLOOD_ERI_U_vtx";
char fzgx_obj_lbl_1_data_3F7D0[20] = "BLOOD_KATAATE_2_vtx";
char fzgx_obj_lbl_1_data_3F7E4[18] = "JODY_HAIR_A_U_vtx";
char fzgx_obj_lbl_1_data_3F7F8[18] = "JODY_HAIR_A_B_vtx";
char fzgx_obj_lbl_1_data_3F80C[18] = "JODY_HAIR_B_U_vtx";
char fzgx_obj_lbl_1_data_3F820[18] = "JODY_HAIR_B_B_vtx";
char fzgx_obj_lbl_1_data_3F834[18] = "JODY_HAIR_C_U_vtx";
char fzgx_obj_lbl_1_data_3F848[18] = "JODY_HAIR_C_B_vtx";
char fzgx_obj_lbl_1_data_3F85C[18] = "JODY_HAIR_D_U_vtx";
char fzgx_obj_lbl_1_data_3F870[18] = "JODY_HAIR_D_B_vtx";
char fzgx_obj_lbl_1_data_3F884[18] = "JODY_HAIR_E_U_vtx";
char fzgx_obj_lbl_1_data_3F898[18] = "JODY_HAIR_E_B_vtx";
char fzgx_obj_lbl_1_data_3F8AC[18] = "JODY_HAIR_F_U_vtx";
char fzgx_obj_lbl_1_data_3F8C0[18] = "JODY_HAIR_F_B_vtx";
char fzgx_obj_lbl_1_data_3F8D4[16] = "JODY_HAIR_G_vtx";
char fzgx_obj_lbl_1_data_3F8E4[16] = "JODY_HAIR_H_vtx";
char fzgx_obj_lbl_1_data_3F8F4[16] = "JODY_HAIR_I_vtx";
char fzgx_obj_lbl_1_data_3F904[19] = "JODY_KATAATE_R_vtx";
char fzgx_obj_lbl_1_data_3F918[19] = "JODY_KATAATE_L_vtx";
char fzgx_obj_lbl_1_data_3F92C[19] = "KATE_EARRING_R_vtx";
char fzgx_obj_lbl_1_data_3F940[19] = "KATE_EARRING_L_vtx";
char fzgx_obj_lbl_1_data_3F954[18] = "JACK_HAIR_A_L_vtx";
char fzgx_obj_lbl_1_data_3F968[18] = "JACK_HAIR_A_R_vtx";
char fzgx_obj_lbl_1_data_3F97C[18] = "JACK_HAIR_B_L_vtx";
char fzgx_obj_lbl_1_data_3F990[18] = "JACK_HAIR_B_R_vtx";
char fzgx_obj_lbl_1_data_3F9A4[18] = "JACK_HAIR_C_L_vtx";
char fzgx_obj_lbl_1_data_3F9B8[18] = "JACK_HAIR_C_R_vtx";
char fzgx_obj_lbl_1_data_3F9CC[19] = "JACK__HAIR_MID_vtx";
char fzgx_obj_lbl_1_data_3F9E0[15] = "EAD_HIGE_R_vtx";
char fzgx_obj_lbl_1_data_3F9F0[15] = "EAD_HIGE_L_vtx";
char fzgx_obj_lbl_1_data_3FA00[18] = "NEELSEN_ERI_O_vtx";
char fzgx_obj_lbl_1_data_3FA14[18] = "NEELSEN_ERI_U_vtx";
char fzgx_obj_lbl_1_data_3FA28[19] = "NEELSEN_MOMO_R_vtx";
char fzgx_obj_lbl_1_data_3FA3C[19] = "NEELSEN_MOMO_L_vtx";
char fzgx_obj_lbl_1_data_3FA50[19] = "NEELSEN_CAMERA_vtx";
char fzgx_obj_lbl_1_data_3FA64[19] = "NEELSEN_JACKET_vtx";
char fzgx_obj_lbl_1_data_3FA78[16] = "GOROH_ERI_O_vtx";
char fzgx_obj_lbl_1_data_3FA88[16] = "GOROH_ERI_U_vtx";
char fzgx_obj_lbl_1_data_3FA98[17] = "GOROH_BELT_R_vtx";
char fzgx_obj_lbl_1_data_3FAAC[17] = "GOROH_BELT_L_vtx";
char fzgx_obj_lbl_1_data_3FAC0[17] = "GOROH_JACKET_vtx";
char fzgx_obj_lbl_1_data_3FAD4[16] = "BABA_JACKET_vtx";
char fzgx_obj_lbl_1_data_3FAE4[15] = "MRS_HAIR_R_vtx";
char fzgx_obj_lbl_1_data_3FAF4[17] = "MRS_HAIR_MID_vtx";
char fzgx_obj_lbl_1_data_3FB08[15] = "MRS_HAIR_L_vtx";
char fzgx_obj_lbl_1_data_3FB18[13] = "DON_MANT_vtx";
char fzgx_obj_lbl_1_data_3FB28[19] = "SHERLOK_MANT_U_vtx";
char fzgx_obj_lbl_1_data_3FB3C[19] = "SHERLOK_MANT_O_vtx";
char fzgx_obj_lbl_1_data_3FB50[15] = "SPADE_MANT_vtx";
char fzgx_obj_lbl_1_data_3FB60[14] = "DAI_SCARF_vtx";
char fzgx_obj_lbl_1_data_3FB70[14] = "SAN_SCARF_vtx";
char fzgx_obj_lbl_1_data_3FB80[14] = "GEN_SCARF_vtx";
char fzgx_obj_lbl_1_data_3FB90[17] = "PRISIA_SCARF_vtx";
char fzgx_obj_lbl_1_data_3FBA4[18] = "PLISIA_MOMO_R_vtx";
char fzgx_obj_lbl_1_data_3FBB8[18] = "PLISIA_MOMO_L_vtx";
char fzgx_obj_lbl_1_data_3FBCC[18] = "PLISIA_HAIR_R_vtx";
char fzgx_obj_lbl_1_data_3FBE0[18] = "PLISIA_HAIR_L_vtx";
char fzgx_obj_lbl_1_data_3FBF4[20] = "DAIGOROH_JACKET_vtx";
char fzgx_obj_lbl_1_data_3FC08[20] = "DAIGOROH_BELT_R_vtx";
char fzgx_obj_lbl_1_data_3FC1C[20] = "DAIGOROH_BELT_L_vtx";
char fzgx_obj_lbl_1_data_3FC30[19] = "DIGIBOY_MOMO_R_vtx";
char fzgx_obj_lbl_1_data_3FC44[19] = "DIGIBOY_MOMO_L_vtx";
char fzgx_obj_lbl_1_data_3FC58[16] = "LILY_JACKET_vtx";
char fzgx_obj_lbl_1_data_3FC68[13] = "LILY_ERI_vtx";
char fzgx_obj_lbl_1_data_3FC78[14] = "PJ_SUNE_R_vtx";
char fzgx_obj_lbl_1_data_3FC88[14] = "PJ_SUNE_L_vtx";
char fzgx_obj_lbl_1_data_3FC98[17] = "ROGER_JACKET_vtx";
void *fzgx_obj_lbl_1_data_3FCAC[196] = {(void *)&fzgx_obj_lbl_1_data_3F578, (void *)&fzgx_obj_lbl_1_data_3F58C, (void *)&fzgx_obj_lbl_1_data_3F5A0, (void *)&fzgx_obj_lbl_1_data_3F5B4, (void *)&fzgx_obj_lbl_1_data_3F5C8, (void *)&fzgx_obj_lbl_1_data_3F5DC, (void *)&fzgx_obj_lbl_1_data_3F5F0, (void *)&fzgx_obj_lbl_1_data_3F604, (void *)&fzgx_obj_lbl_1_data_3F618, (void *)&fzgx_obj_lbl_1_data_3F630, (void *)&fzgx_obj_lbl_1_data_3F644, (void *)&fzgx_obj_lbl_1_data_3F658, (void *)&fzgx_obj_lbl_1_data_3F66C, (void *)&fzgx_obj_lbl_1_data_3F680, (void *)&fzgx_obj_lbl_1_data_3F694, (void *)&fzgx_obj_lbl_1_data_3F6A8, (void *)&fzgx_obj_lbl_1_data_3F6B8, (void *)&fzgx_obj_lbl_1_data_3F6C8, (void *)&fzgx_obj_lbl_1_data_3F6D8, (void *)&fzgx_obj_lbl_1_data_3F6E8, (void *)&fzgx_obj_lbl_1_data_3F6FC, (void *)&fzgx_obj_lbl_1_data_3F710, (void *)&fzgx_obj_lbl_1_data_3F724, (void *)&fzgx_obj_lbl_1_data_3F738, (void *)&fzgx_obj_lbl_1_data_3F748, (void *)&fzgx_obj_lbl_1_data_3F75C, (void *)&fzgx_obj_lbl_1_data_3F770, (void *)&fzgx_obj_lbl_1_data_3F780, (void *)&fzgx_obj_lbl_1_data_3F790, (void *)&fzgx_obj_lbl_1_data_3F7A0, (void *)&fzgx_obj_lbl_1_data_3F7B0, (void *)&fzgx_obj_lbl_1_data_3F7C0, (void *)&fzgx_obj_lbl_1_data_3F7D0, (void *)&fzgx_obj_lbl_1_data_3F7E4, (void *)&fzgx_obj_lbl_1_data_3F7F8, (void *)&fzgx_obj_lbl_1_data_3F80C, (void *)&fzgx_obj_lbl_1_data_3F820, (void *)&fzgx_obj_lbl_1_data_3F834, (void *)&fzgx_obj_lbl_1_data_3F848, (void *)&fzgx_obj_lbl_1_data_3F85C, (void *)&fzgx_obj_lbl_1_data_3F870, (void *)&fzgx_obj_lbl_1_data_3F884, (void *)&fzgx_obj_lbl_1_data_3F898, (void *)&fzgx_obj_lbl_1_data_3F8AC, (void *)&fzgx_obj_lbl_1_data_3F8C0, (void *)&fzgx_obj_lbl_1_data_3F8D4, (void *)&fzgx_obj_lbl_1_data_3F8E4, (void *)&fzgx_obj_lbl_1_data_3F8F4, (void *)&fzgx_obj_lbl_1_data_3F904, (void *)&fzgx_obj_lbl_1_data_3F918, (void *)&fzgx_obj_lbl_1_data_3F92C, (void *)&fzgx_obj_lbl_1_data_3F940, (void *)&fzgx_obj_lbl_1_data_3F954, (void *)&fzgx_obj_lbl_1_data_3F968, (void *)&fzgx_obj_lbl_1_data_3F97C, (void *)&fzgx_obj_lbl_1_data_3F990, (void *)&fzgx_obj_lbl_1_data_3F9A4, (void *)&fzgx_obj_lbl_1_data_3F9B8, (void *)&fzgx_obj_lbl_1_data_3F9CC, (void *)&fzgx_obj_lbl_1_data_3F9E0, (void *)&fzgx_obj_lbl_1_data_3F9F0, (void *)&fzgx_obj_lbl_1_data_3FA00, (void *)&fzgx_obj_lbl_1_data_3FA14, (void *)&fzgx_obj_lbl_1_data_3FA28, (void *)&fzgx_obj_lbl_1_data_3FA3C, (void *)&fzgx_obj_lbl_1_data_3FA50, (void *)&fzgx_obj_lbl_1_data_3FA64, (void *)&fzgx_obj_lbl_1_data_3FA78, (void *)&fzgx_obj_lbl_1_data_3FA88, (void *)&fzgx_obj_lbl_1_data_3FA98, (void *)&fzgx_obj_lbl_1_data_3FAAC, (void *)&fzgx_obj_lbl_1_data_3FAC0, (void *)&fzgx_obj_lbl_1_data_3FAD4, (void *)&fzgx_obj_lbl_1_data_3FAE4, (void *)&fzgx_obj_lbl_1_data_3FAF4, (void *)&fzgx_obj_lbl_1_data_3FB08, (void *)&fzgx_obj_lbl_1_data_3FB18, (void *)&fzgx_obj_lbl_1_data_3FB28, (void *)&fzgx_obj_lbl_1_data_3FB3C, (void *)&fzgx_obj_lbl_1_data_3FB50, (void *)&fzgx_obj_lbl_1_data_3FB60, (void *)&fzgx_obj_lbl_1_data_3FB70, (void *)&fzgx_obj_lbl_1_data_3FB80, (void *)&fzgx_obj_lbl_1_data_3FB90, (void *)&fzgx_obj_lbl_1_data_3FBA4, (void *)&fzgx_obj_lbl_1_data_3FBB8, (void *)&fzgx_obj_lbl_1_data_3FBCC, (void *)&fzgx_obj_lbl_1_data_3FBE0, (void *)&fzgx_obj_lbl_1_data_3FBF4, (void *)&fzgx_obj_lbl_1_data_3FC08, (void *)&fzgx_obj_lbl_1_data_3FC1C, (void *)&fzgx_obj_lbl_1_data_3FC30, (void *)&fzgx_obj_lbl_1_data_3FC44, (void *)&fzgx_obj_lbl_1_data_3FC58, (void *)&fzgx_obj_lbl_1_data_3FC68, (void *)&fzgx_obj_lbl_1_data_3FC78, (void *)&fzgx_obj_lbl_1_data_3FC88, (void *)&fzgx_obj_lbl_1_data_3FC98, (void *)0x0000000F, (void *)0x0000000F, (void *)0x0000000F, (void *)0x0000000F, (void *)0x00000006, (void *)0x00000006, (void *)0x00000006, (void *)0x00000006, (void *)0x00000006, (void *)0x00000006, (void *)0x00000009, (void *)0x00000009, (void *)0x00000009, (void *)0x00000009, (void *)0x00000009, (void *)0x00000013, (void *)0x0000001D, (void *)0x0000001E, (void *)0x0000001E, (void *)0x00000010, (void *)0x00000010, (void *)0x00000010, (void *)0x00000002, (void *)0x00000029, (void *)0x00000029, (void *)0x00000029, (void *)0x00000015, (void *)0x00000015, (void *)0x00000015, (void *)0x00000018, (void *)0x00000018, (void *)0x00000018, (void *)0x00000018, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x0000000B, (void *)0x0000000B, (void *)0x0000000D, (void *)0x0000000D, (void *)0x0000000D, (void *)0x0000000D, (void *)0x0000000D, (void *)0x0000000D, (void *)0x0000000D, (void *)0x00000008, (void *)0x00000008, (void *)0x00000016, (void *)0x00000016, (void *)0x00000016, (void *)0x00000016, (void *)0x00000016, (void *)0x00000016, (void *)0x00000004, (void *)0x00000004, (void *)0x00000004, (void *)0x00000004, (void *)0x00000004, (void *)0x00000003, (void *)0x00000014, (void *)0x00000014, (void *)0x00000014, (void *)0x0000001F, (void *)0x00000028, (void *)0x00000028, (void *)0x00000022, (void *)0x00000021, (void *)0x0000002A, (void *)0x0000002B, (void *)0x00000024, (void *)0x00000024, (void *)0x00000024, (void *)0x00000024, (void *)0x00000024, (void *)0x00000023, (void *)0x00000023, (void *)0x00000023, (void *)0x00000020, (void *)0x00000020, (void *)0x00000025, (void *)0x00000025, (void *)0x00000026, (void *)0x00000026, (void *)0x0000001B};
void *fzgx_obj_lbl_1_data_3FFBC[349] = {(void *)0x00000012, (void *)0x00000017, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000010, (void *)0x0000000B, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000001, (void *)0x00000010, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000010, (void *)0x00000010, (void *)0x00000001, (void *)0x00000010, (void *)0x00000010, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x0000000B, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x0000000B, (void *)0x00000006, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000001, (void *)0x00000001, (void *)0x00000012, (void *)0x00000017, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000010, (void *)0x00000010, (void *)0x00000001, (void *)0x00000001, (void *)0x00000005, (void *)0x00000005, (void *)0x00000005, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000010, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000001, (void *)0x00000012, (void *)0x00000017, (void *)0x00000005, (void *)0x00000005, (void *)0x00000001, (void *)0x00000010, (void *)0x00000010, (void *)0x00000012, (void *)0x00000017, (void *)0x00000001, (void *)0x00000001, (void *)0x00000013, (void *)0x00000018, (void *)0x00000001, (void *)0x00010203, (void *)0x00010203, (void *)0x04050001, (void *)0x02030400, (void *)0x00000100, (void *)0x01020000, (void *)0x01020001, (void *)0x02000102, (void *)0x03000102, (void *)0x03040506, (void *)0x0708090A, (void *)0x0B0C0D0E, (void *)0x0F100001, (void *)0x00010203, (void *)0x04050600, (void *)0x01000102, (void *)0x03040500, (void *)0x01020304, (void *)0x00000102, (void *)0x00000100, (void *)0x00000000, (void *)0x01020304, (void *)0x02030400, (void *)0x01000100, (void *)0x01000000, (void *)fn_1_11BFCC, (void *)fn_1_11BFCC, (void *)fn_1_1091D4, (void *)fn_1_10A43C, (void *)fn_1_10A8D0, (void *)fn_1_10B344, (void *)fn_1_10BA00, (void *)fn_1_10C4E4, (void *)fn_1_10B7D8, (void *)fn_1_127FB8, (void *)fn_1_10C9B0, (void *)fn_1_10C9B0, (void *)fn_1_10C9B0, (void *)fn_1_10D2F0, (void *)fn_1_10B7D8, (void *)fn_1_10DDE4, (void *)fn_1_110008, (void *)fn_1_111510, (void *)fn_1_112F40, (void *)fn_1_1137E4, (void *)fn_1_10A8D0, (void *)fn_1_10B344, (void *)fn_1_1145C8, (void *)fn_1_1145C8, (void *)fn_1_118D90, (void *)fn_1_118D90, (void *)fn_1_1145C8, (void *)fn_1_118D90, (void *)fn_1_118D90, (void *)fn_1_1145C8, (void *)fn_1_10A8D0, (void *)fn_1_10B344, (void *)fn_1_127FB8, (void *)fn_1_115B58, (void *)fn_1_1166EC, (void *)fn_1_115B58, (void *)fn_1_1166EC, (void *)fn_1_115B58, (void *)fn_1_1166EC, (void *)fn_1_115B58, (void *)fn_1_1166EC, (void *)fn_1_115B58, (void *)fn_1_1166EC, (void *)fn_1_115B58, (void *)fn_1_1166EC, (void *)fn_1_115B58, (void *)fn_1_115B58, (void *)fn_1_115B58, (void *)fn_1_127FB8, (void *)fn_1_127FB8, (void *)fn_1_1154D0, (void *)fn_1_1154D0, (void *)fn_1_1171B8, (void *)fn_1_1171B8, (void *)fn_1_1171B8, (void *)fn_1_1171B8, (void *)fn_1_1171B8, (void *)fn_1_1171B8, (void *)fn_1_1171B8, (void *)fn_1_1185B4, (void *)fn_1_1185B4, (void *)fn_1_10A8D0, (void *)fn_1_10B344, (void *)fn_1_11B4E4, (void *)fn_1_11B4E4, (void *)fn_1_11D1FC, (void *)fn_1_126DE8, (void *)fn_1_10A8D0, (void *)fn_1_10B344, (void *)fn_1_1145C8, (void *)fn_1_1145C8, (void *)fn_1_126DE8, (void *)fn_1_11A158, (void *)fn_1_11CAB4, (void *)fn_1_11CAB4, (void *)fn_1_11CAB4, (void *)fn_1_11ED0C, (void *)fn_1_1201E4, (void *)fn_1_122348, (void *)fn_1_12295C, (void *)fn_1_1145C8, (void *)fn_1_1145C8, (void *)fn_1_1145C8, (void *)fn_1_1145C8, (void *)fn_1_11BFCC, (void *)fn_1_11BFCC, (void *)fn_1_1177C4, (void *)fn_1_1177C4, (void *)fn_1_1244F0, (void *)fn_1_1145C8, (void *)fn_1_1145C8, (void *)fn_1_1262A4, (void *)fn_1_1262A4, (void *)fn_1_1250D0, (void *)fn_1_125CE8, (void *)fn_1_11BFCC, (void *)fn_1_11BFCC, (void *)fn_1_126DE8, (void *)fn_1_11C440, (void *)fn_1_11C440, (void *)fn_1_10976C, (void *)fn_1_10A6A0, (void *)fn_1_10AD18, (void *)fn_1_10B5A8, (void *)fn_1_10BE3C, (void *)fn_1_10C7B4, (void *)fn_1_10B800, (void *)fn_1_128038, (void *)fn_1_10CC38, (void *)fn_1_10CC38, (void *)fn_1_10CC38, (void *)fn_1_10D7D4, (void *)fn_1_10B800, (void *)fn_1_10E3B4, (void *)fn_1_110478, (void *)fn_1_111980, (void *)fn_1_1132E4, (void *)fn_1_113C58, (void *)fn_1_10AD18, (void *)fn_1_10B5A8, (void *)fn_1_11492C, (void *)fn_1_11492C, (void *)fn_1_1192D0, (void *)fn_1_1192D0, (void *)fn_1_11492C, (void *)fn_1_1192D0, (void *)fn_1_1192D0, (void *)fn_1_11492C, (void *)fn_1_10AD18, (void *)fn_1_10B5A8, (void *)fn_1_128038, (void *)fn_1_115BE8, (void *)fn_1_11677C, (void *)fn_1_115BE8, (void *)fn_1_11677C, (void *)fn_1_115BE8, (void *)fn_1_11677C, (void *)fn_1_115BE8, (void *)fn_1_11677C, (void *)fn_1_115BE8, (void *)fn_1_11677C, (void *)fn_1_115BE8, (void *)fn_1_11677C, (void *)fn_1_115BE8, (void *)fn_1_115BE8, (void *)fn_1_115BE8, (void *)fn_1_128038, (void *)fn_1_128038, (void *)fn_1_115560, (void *)fn_1_115560, (void *)fn_1_117424, (void *)fn_1_117424, (void *)fn_1_117424, (void *)fn_1_117424, (void *)fn_1_117424, (void *)fn_1_117424, (void *)fn_1_117424, (void *)fn_1_1188CC, (void *)fn_1_1188CC, (void *)fn_1_10AD18, (void *)fn_1_10B5A8, (void *)fn_1_11B958, (void *)fn_1_11B958, (void *)fn_1_11DE2C, (void *)fn_1_12744C, (void *)fn_1_10AD18, (void *)fn_1_10B5A8, (void *)fn_1_11492C, (void *)fn_1_11492C, (void *)fn_1_12744C, (void *)fn_1_11A774, (void *)fn_1_11CD3C, (void *)fn_1_11CD3C, (void *)fn_1_11CD3C, (void *)fn_1_11F250, (void *)fn_1_120804, (void *)fn_1_12277C, (void *)fn_1_123050, (void *)fn_1_11492C, (void *)fn_1_11492C, (void *)fn_1_11492C, (void *)fn_1_11492C, (void *)fn_1_11C440, (void *)fn_1_11C440, (void *)fn_1_117D5C, (void *)fn_1_117D5C, (void *)fn_1_124AD4, (void *)fn_1_11492C, (void *)fn_1_11492C, (void *)fn_1_126774, (void *)fn_1_126774, (void *)fn_1_1256EC, (void *)fn_1_125DF0, (void *)fn_1_11C440, (void *)fn_1_11C440, (void *)fn_1_12744C, (void *)0x00000062, (void *)&fzgx_obj_lbl_1_data_3F6E8, (void *)&fzgx_obj_lbl_1_data_3F738, (void *)&fzgx_obj_lbl_1_data_3F770, (void *)&fzgx_obj_lbl_1_data_3F6B8, (void *)&fzgx_obj_lbl_1_data_3FB60, (void *)&fzgx_obj_lbl_1_data_3FB70, (void *)&fzgx_obj_lbl_1_data_3FB80, (void *)&fzgx_obj_lbl_1_data_3FB50, (void *)&fzgx_obj_lbl_1_data_3F6C8, (void *)&fzgx_obj_lbl_1_data_3FA98, (void *)&fzgx_obj_lbl_1_data_3FAAC, (void *)&fzgx_obj_lbl_1_data_3F7A0, (void *)&fzgx_obj_lbl_1_data_3FB28, (void *)&fzgx_obj_lbl_1_data_3FB3C, (void *)&fzgx_obj_lbl_1_data_3FC08, (void *)&fzgx_obj_lbl_1_data_3FC1C, (void *)&fzgx_obj_lbl_1_data_3FB90, (void *)&fzgx_obj_lbl_1_data_3F724, (void *)&fzgx_obj_lbl_1_data_3F6A8, (void *)0x00000013, (void *)0x5F767478, (void *)0x00000000, (void *)0x4E5F2573, (void *)0x00000000, (void *)0x53504144, (void *)0x455F4D41, (void *)0x4E540000, (void *)0x5F4D414E, (void *)0x54000000};
u32 fzgx_obj_lbl_1_data_40530[8] = {0x61636365, 0x73736F72, 0x792E6300, 0x4341525F, 0x53454C00, 0x53454C5F, 0x57414954, 0x00000000};
char lbl_1_data_40530__fzgx_offset_20[8] = "SEL_DEC";
u32 lbl_1_data_40530__fzgx_offset_28[17] = {0x57494E5F, 0x31535400, 0x53454C5F, 0x57414954, 0x5F303100, 0x504C4953, 0x49415F48, 0x4149525F, 0x4C5F2564, 0x5F767478, 0x00000000, 0x504C4953, 0x49415F48, 0x4149525F, 0x525F2564, 0x5F767478, 0x00000000};
u32 fzgx_obj_lbl_1_data_4059C[5] = {0x73746F70, 0x2E2E0000, 0x53454C5F, 0x57414954, 0x5F303200};
char lbl_1_data_4059C__fzgx_offset_14[8] = "WIN_4TH";
char lbl_1_data_4059C__fzgx_offset_1C[8] = "WIN_3RD";

extern f32 lbl_1_rodata_7AB8[9];
extern const char *fn_1_950E8(AccSig *);
extern int fn_80083BCC(const char *, const char *);
extern s32 fn_80077B14(struct Sig80077B14Arg *);
extern u32 fn_1_108EEC(void *, u32, u32, f32, f32, f32, f32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_8006E250(void *, void *);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1B0(void *, void *);

#define SLOT(a) ((s32)((const u32 *)fzgx_obj_lbl_1_data_3FFBC)[(a)->index_08])
#define SLOTPTR(a) ((u8 *)*(u32 *)((u8 *)*(u32 *)((u8 *)(a)->item_0C + 0x150) + 8) + SLOT(a) * 0x18c)

void fn_1_128038(Accessory *a) {
    u32 tmp_call38;
    s32 i;
    u8 * base_2;
    const f32 *ro = lbl_1_rodata_7AB8;
    Mat44 mat;
    u8 *base;
    u8 *entry;
    u32 p30;
    u32 f;
    s32 j;

    if (a != 0 && a->sig_10 != 0) {
        fn_80077B14(a->sig_10);
        if (a->flag_00 & 2) {
            f = a->flag_00;
            f &= ~2;
            a->flag_00 = f;
            lbl_8006DBAC(SLOTPTR(a) + 0x88);
            lbl_8006DAEC();
            base = (u8 *)a->bones_24;
            for (i = 0; i < a->count_18; i++) {
                lbl_8006DBE4();
                lbl_8006E1B0(base + 0x28, base + 0x10);
                base += 0x44;
            }
            lbl_8006DC20();
        }
        entry = SLOTPTR(a);
        if (a->item_0C->kind == 0x18) {
            if (fn_80083BCC(fn_1_950E8(&a->item_0C->sig_148), (const char *)lbl_1_data_4059C__fzgx_offset_14) == 0) {
                lbl_8006D758();
                mathutil_mtxA_rotate_z(0x4000);
                lbl_8006DB74(&mat);
            } else {
                lbl_8006D758();
                lbl_8006DB74(&mat);
            }
        } else if (a->item_0C->kind == 6) {
            if (fn_80083BCC(fn_1_950E8(&a->item_0C->sig_148), (const char *)(char *)lbl_1_data_40530__fzgx_offset_28) == 0 &&
                *(s16 *)&lbl_1_bss_960 != 14) {
                lbl_8006D758();
                mathutil_mtxA_rotate_z(0x4000);
                lbl_8006DB74(&mat);
            } else if (fn_80083BCC(fn_1_950E8(&a->item_0C->sig_148), (const char *)lbl_1_data_4059C__fzgx_offset_1C) == 0) {
                lbl_8006D758();
                mathutil_mtxA_rotate_z(0x2000);
                lbl_8006DB74(&mat);
            } else {
                lbl_8006D758();
                lbl_8006DB74(&mat);
            }
        } else if (a->item_0C->kind == 1) {
            lbl_8006D758();
            lbl_8006DB74(&mat);
        }
        base_2 = (u8 *)a->bones_24;
        for (i = 0; i < a->count_18; i++) {
            lbl_8006DBAC(entry + 0x88);
            lbl_8006DFC4(&mat);
            lbl_8006E1B0(base_2 + 0x28, base_2 + 0x10);
            base_2 += 0x44;
        }
        if (a->item_0C->kind == 0x18) {
            fn_1_108EEC(a, 1, 12, ro[308], ro[193], ro[344], ro[345]);
            if (fn_80083BCC(fn_1_950E8(&a->item_0C->sig_148), (const char *)lbl_1_data_4059C__fzgx_offset_14) != 0) {
                if (fn_80083BCC(fn_1_950E8(&a->item_0C->sig_148), (const char *)lbl_1_data_40530__fzgx_offset_20) != 0) {
                    fn_1_108EEC(a, 12, 12, ro[170], ro[42], ro[137], ro[290]);
                    fn_1_108EEC(a, 12, 12, ro[175], ro[346], ro[105], ro[347]);
                    fn_1_108EEC(a, 12, 12, ro[87], ro[348], ro[349], ro[165]);
                    fn_1_108EEC(a, 13, 12, ro[350], ro[26], ro[105], ro[261]);
                    fn_1_108EEC(a, 13, 12, ro[350], ro[179], ro[214], ro[351]);
                    fn_1_108EEC(a, 13, 12, ro[345], ro[352], ro[214], ro[351]);
                }
            }
        } else if (a->item_0C->kind == 6) {
            fn_1_108EEC(a, 1, 12, ro[308], ro[193], ro[344], ro[345]);
            if (fn_80083BCC(fn_1_950E8(&a->item_0C->sig_148), (const char *)(char *)lbl_1_data_40530__fzgx_offset_28) != 0) {
                fn_1_108EEC(a, 12, 12, ro[170], ro[42], ro[137], ro[290]);
                fn_1_108EEC(a, 12, 12, ro[175], ro[346], ro[105], ro[347]);
                fn_1_108EEC(a, 12, 12, ro[87], ro[348], ro[349], ro[165]);
                fn_1_108EEC(a, 13, 12, ro[350], ro[26], ro[105], ro[261]);
                fn_1_108EEC(a, 13, 12, ro[350], ro[179], ro[214], ro[351]);
                tmp_call38 = fn_1_108EEC(a, 13, 12, ro[345], ro[352], ro[214], ro[351]);
            }
        } else if (a->item_0C->kind == 1) {
            if (SLOT(a) == 11u) {
                fn_1_108EEC(a, 1, 12, ro[263], ro[193], ro[344], ro[345]);
                fn_1_108EEC(a, 12, 12, ro[353], ro[42], ro[137], ro[290]);
                fn_1_108EEC(a, 12, 12, ro[354], ro[346], ro[105], ro[347]);
                fn_1_108EEC(a, 12, 12, ro[104], ro[348], ro[349], ro[165]);
                fn_1_108EEC(a, 13, 12, ro[168], ro[26], ro[105], ro[261]);
                fn_1_108EEC(a, 13, 12, ro[168], ro[179], ro[214], ro[351]);
                fn_1_108EEC(a, 13, 12, ro[355], ro[352], ro[214], ro[351]);
            } else {
                fn_1_108EEC(a, 1, 7, ro[263], ro[193], ro[344], ro[345]);
                fn_1_108EEC(a, 7, 7, ro[353], ro[42], ro[137], ro[290]);
                fn_1_108EEC(a, 7, 7, ro[354], ro[346], ro[105], ro[347]);
                fn_1_108EEC(a, 7, 7, ro[104], ro[348], ro[349], ro[165]);
                fn_1_108EEC(a, 13, 7, ro[168], ro[26], ro[105], ro[261]);
                fn_1_108EEC(a, 13, 7, ro[168], ro[179], ro[214], ro[351]);
                fn_1_108EEC(a, 13, 7, ro[355], ro[352], ro[214], ro[351]);
            }
        }
        p30 = fn_80077B14(a->sig_10);
        lbl_8006DBAC(SLOTPTR(a) + 0x88);
        base_2 = (u8 *)a->bones_24;
        for (j = 0; j < a->count_18; j++) {
            for (i = 0; i < ((BoneSet *)base_2)->count; i++) {
                fn_8006E250(base_2 + 0x10, (u8 *)p30 + ((BoneSet *)base_2)->index[i] * 0x40);
            }
            base_2 += 0x44;
        }
    }
}

