#include "types.h"
extern s32 lbl_3_bss_120;
extern u32 lbl_3_bss_F0[12];
extern s32 fn_1_4C10(void);
extern s16 fn_3_B270(void);
extern u16 lbl_1_bss_96A;
extern u32 lbl_3_bss_20850;
extern u32 lbl_3_bss_243A8[6];
extern void fn_1_4A00(s32, s32, u32);
extern u16 lbl_3_bss_20[104];
extern u32 lbl_3_bss_2C7C0[66624];
extern void fn_80008BEC(void *, s32, s32);
extern void fn_1_FDFF4(void);
extern void fn_1_FC4E0(void *, s32);
extern u32 lbl_3_bss_7EBA4;
extern u32 lbl_3_bss_7EBA8;
extern u8 lbl_3_data_11DC[84];
extern u32 lbl_801A6410;
extern void fn_1_7F3AC(u32);
extern void fn_1_46B4(u32, u32, u8 *, s32);
extern void fn_1_BC29C(u32 *arg0);
extern void fn_1_B9C0C(void);
extern char lbl_3_data_1A1C[17];
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char *, ...);
extern u32 lbl_3_bss_A179C;
extern u32 lbl_3_data_1A14;

/* fzgx:begin fn_3_ACF4 noprologue */
#include "types.h"

typedef struct {
    u8 pad[0x324];
    s32 value;
    u8 tail[0x118];
} CustomizeEntry;

extern u32 lbl_3_bss_F0[12];
extern CustomizeEntry lbl_3_bss_20860[4];
extern u8 lbl_3_bss_21960[10368];
extern s32 lbl_3_data_B8;
extern u32 lbl_3_bss_20850;
extern u32 lbl_1_bss_6D82C;
typedef struct {
    u8 pad[0x3a4];
    u32 field_3a4;
} CustomizeObject;

extern CustomizeObject *lbl_3_bss_7EBA4;
extern u8 lbl_3_data_11DC[84];
extern u32 lbl_3_bss_7EBA8;
extern u32 lbl_801A6410;

extern void fn_1_80F1C(s32, CustomizeEntry *);
extern void fn_1_14DBCC(void *);
extern void fn_80071718(u32);
extern void fn_1_151BDC(s32);
extern void fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_1_46B4(u32, u32, u8 *, s32);
extern void fn_1_7F3AC(CustomizeObject *);

void fn_3_ACF4(void) {
    s16 index;

    if ((lbl_3_bss_F0[0] & 0x20000000) == 0) {
        index = *(s16 *)((u8 *)lbl_3_bss_F0 + 8);
        if (lbl_3_bss_20860[index].value != -1) {
            fn_1_80F1C((s16)lbl_3_bss_20860[index].value, &lbl_3_bss_20860[index]);
            lbl_3_bss_20860[index].value = -1;
        }
        fn_1_14DBCC((u8 *)lbl_3_bss_21960 + index * 0xa20);
        if (lbl_1_bss_6D82C != 0) {
            fn_80071718(lbl_1_bss_6D82C);
            lbl_1_bss_6D82C = 0;
        }
        fn_1_151BDC(0);
        if (lbl_3_data_B8 != -1) {
            fn_1_435C(lbl_3_bss_20850);
            fn_1_426C(lbl_3_data_B8);
            lbl_3_data_B8 = -1;
        }
    }
    if (lbl_3_bss_7EBA4->field_3a4 != 0) {
        fn_1_7F3AC(lbl_3_bss_7EBA4);
    }
    if (lbl_3_bss_7EBA4 != 0) {
        fn_1_46B4(lbl_801A6410, (u32)lbl_3_bss_7EBA4, lbl_3_data_11DC, 0x11b3);
    }
    if (lbl_3_bss_7EBA8 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_3_bss_7EBA8, lbl_3_data_11DC, 0x11b5);
    }
    lbl_3_bss_7EBA4 = 0;
    lbl_3_bss_7EBA8 = 0;
}
/* fzgx:end fn_3_ACF4 */

/* fzgx:begin fn_3_AE74 */
typedef struct {
    s16 id;
    u8 pad_2[0x2];
    u32 mask;
    u8 flags;
    u8 pad_9[0x17];
} CustomizeSlot;

typedef struct {
    u8 pad[0x324];
    u32 value;
    u8 tail[0x118];
} CustomizeEntry;

typedef struct {
    u8 pad_0[0xC4];
    s16 unk_C4;
    u8 pad_C6[0xA];
} fzgx_obj_lbl_3_bss_20_t;

typedef struct {
    u8 pad_0[0x6];
    s16 unk_6;
    u8 pad_8[0x28];
} fzgx_obj_lbl_3_bss_F0_t;

typedef struct {
    u8 pad_0[0x9E];
    u8 unk_9E;
} Bss8B3A0;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base. */
u32 fzgx_obj_lbl_3_bss_0[2];
u32 fzgx_obj_lbl_3_bss_8;
s32 fzgx_obj_lbl_3_bss_C[3];
u16 fzgx_obj_lbl_3_bss_18[4];
fzgx_obj_lbl_3_bss_20_t fzgx_obj_lbl_3_bss_20;
fzgx_obj_lbl_3_bss_F0_t fzgx_obj_lbl_3_bss_F0;
s32 fzgx_obj_lbl_3_bss_120[8];
u32 fzgx_obj_lbl_3_bss_140[0x81C1];
u16 fzgx_obj_lbl_3_bss_20844;
u32 fzgx_obj_lbl_3_bss_20848;
u32 fzgx_obj_lbl_3_bss_2084C;
u32 fzgx_obj_lbl_3_bss_20850;
CustomizeEntry *fzgx_obj_lbl_3_bss_20854[3];
u32 fzgx_obj_lbl_3_bss_20860[0x440];
u32 fzgx_obj_lbl_3_bss_21960[0xA20];
u32 fzgx_obj_lbl_3_bss_241E0[0x64];
u32 fzgx_obj_lbl_3_bss_24370[3];
u32 fzgx_obj_lbl_3_bss_2437C[0xB];
s32 fzgx_obj_lbl_3_bss_243A8[6];

/* .data: the objects this function touches plus the filler between them (message tables, strings). */
extern u8 fn_1_12B4__fzgx_offset_0[];
extern u8 fn_1_12FC__fzgx_offset_0[];
extern u8 fn_1_1300__fzgx_offset_0[];
extern u8 fn_3_11FF0__fzgx_offset_0[];
extern u8 fn_3_12910__fzgx_offset_0[];
extern u8 fn_3_12B14__fzgx_offset_0[];
extern u8 fn_3_1304C__fzgx_offset_0[];
extern u8 fn_3_13050__fzgx_offset_0[];
extern u8 fn_3_13054__fzgx_offset_0[];
extern u8 fn_3_13058__fzgx_offset_0[];
extern u8 fn_3_1305C__fzgx_offset_0[];
extern u8 fn_3_13060__fzgx_offset_0[];
extern u8 fn_3_13064__fzgx_offset_0[];
extern u8 fn_3_13068__fzgx_offset_0[];
extern u8 fn_3_1306C__fzgx_offset_0[];
extern u8 fn_3_13070__fzgx_offset_0[];
extern u8 fn_3_13074__fzgx_offset_0[];
extern u8 fn_3_13078__fzgx_offset_0[];
extern u8 fn_3_130C8__fzgx_offset_0[];
extern u8 fn_3_1338C__fzgx_offset_0[];
extern u8 fn_3_1349C__fzgx_offset_0[];
extern u8 fn_3_14E4__fzgx_offset_0[];
extern u8 fn_3_15A0__fzgx_offset_0[];
extern u8 fn_3_15A0__fzgx_offset_10B4[];
extern u8 fn_3_15A0__fzgx_offset_10DC[];
extern u8 fn_3_15A0__fzgx_offset_1110[];
extern u8 fn_3_15A0__fzgx_offset_1130[];
extern u8 fn_3_15A0__fzgx_offset_114[];
extern u8 fn_3_15A0__fzgx_offset_12D8[];
extern u8 fn_3_15A0__fzgx_offset_12F8[];
extern u8 fn_3_15A0__fzgx_offset_1570[];
extern u8 fn_3_15A0__fzgx_offset_158[];
extern u8 fn_3_15A0__fzgx_offset_1720[];
extern u8 fn_3_15A0__fzgx_offset_1738[];
extern u8 fn_3_15A0__fzgx_offset_1934[];
extern u8 fn_3_15A0__fzgx_offset_1ACC[];
extern u8 fn_3_15A0__fzgx_offset_574[];
extern u8 fn_3_15A0__fzgx_offset_580[];
extern u8 fn_3_15A0__fzgx_offset_61C[];
extern u8 fn_3_15A0__fzgx_offset_644[];
extern u8 fn_3_15A0__fzgx_offset_8EC[];
extern u8 fn_3_15A0__fzgx_offset_90C[];
extern u8 fn_3_15A0__fzgx_offset_AFC[];
extern u8 fn_3_15A0__fzgx_offset_B1C[];
extern u8 fn_3_15A0__fzgx_offset_CCC[];
extern u8 fn_3_15A0__fzgx_offset_CE4[];
extern u8 fn_3_15A0__fzgx_offset_D14[];
extern u8 fn_3_15A0__fzgx_offset_D3C[];
extern u8 fn_3_15A0__fzgx_offset_D88[];
extern u8 fn_3_15A0__fzgx_offset_D98[];
extern u8 fn_3_15A0__fzgx_offset_DB0[];
extern u8 fn_3_15A0__fzgx_offset_DEC[];
extern u8 fn_3_15A0__fzgx_offset_E0C[];
extern u8 fn_3_33A0__fzgx_offset_0[];
extern u8 fn_3_368C__fzgx_offset_0[];
extern u8 fn_3_381C__fzgx_offset_0[];
extern u8 fn_3_39F0__fzgx_offset_0[];
extern u8 fn_3_3E58__fzgx_offset_0[];
extern u8 fn_3_3F20__fzgx_offset_0[];
extern u8 fn_3_41B0__fzgx_offset_0[];
extern u8 fn_3_4380__fzgx_offset_0[];
extern u8 fn_3_48E0__fzgx_offset_0[];
extern u8 fn_3_4BEC__fzgx_offset_0[];
extern u8 fn_3_4F08__fzgx_offset_0[];
extern u8 fn_3_5500__fzgx_offset_0[];
extern u8 fn_3_5B9C__fzgx_offset_0[];
extern u8 fn_3_5C4C__fzgx_offset_0[];
extern u8 fn_3_5C8C__fzgx_offset_0[];
extern u8 fn_3_5CBC__fzgx_offset_0[];
extern u8 fn_3_61B8__fzgx_offset_0[];
extern u8 fn_3_6270__fzgx_offset_0[];
extern u8 fn_3_6540__fzgx_offset_0[];
extern u8 fn_3_65B0__fzgx_offset_10C[];
extern u8 fn_3_65B0__fzgx_offset_128[];
extern u8 fn_3_65B0__fzgx_offset_144[];
extern u8 fn_3_65B0__fzgx_offset_160[];
extern u8 fn_3_65B0__fzgx_offset_17C[];
extern u8 fn_3_65B0__fzgx_offset_198[];
extern u8 fn_3_65B0__fzgx_offset_1BC[];
extern u8 fn_3_65B0__fzgx_offset_30[];
extern u8 fn_3_65B0__fzgx_offset_3C[];
extern u8 fn_3_65B0__fzgx_offset_48[];
extern u8 fn_3_680C__fzgx_offset_0[];
extern u8 fn_3_6D2C__fzgx_offset_0[];
extern u8 fn_3_6E14__fzgx_offset_0[];
extern u8 fn_3_7038__fzgx_offset_0[];
extern u8 fn_3_7594__fzgx_offset_0[];
extern u8 fn_3_7688__fzgx_offset_0[];
extern u8 fn_3_7770__fzgx_offset_0[];
extern u8 fn_3_77B0__fzgx_offset_0[];
extern u8 fn_3_7864__fzgx_offset_0[];
extern u8 fn_3_7868__fzgx_offset_0[];
extern u8 fn_3_786C__fzgx_offset_0[];
extern u8 fn_3_7870__fzgx_offset_0[];
extern u8 fn_3_7E5C__fzgx_offset_0[];
extern u8 fn_3_8A90__fzgx_offset_0[];
extern u8 fn_3_9710__fzgx_offset_0[];
extern u8 fn_3_990C__fzgx_offset_0[];
extern u8 fn_3_A12C__fzgx_offset_0[];
extern u8 fn_3_ACF4__fzgx_offset_0[];
extern u8 fn_3_AE74__fzgx_offset_0[];
extern u8 fn_3_B5FC__fzgx_offset_0[];
extern u8 fn_3_B6E4__fzgx_offset_0[];
extern u8 lbl_3_data_100__fzgx_offset_0[];
extern u8 lbl_3_data_1018__fzgx_offset_0[];
extern u8 lbl_3_data_103C__fzgx_offset_0[];
extern u8 lbl_3_data_104__fzgx_offset_0[];
extern u8 lbl_3_data_1060__fzgx_offset_0[];
extern u8 lbl_3_data_1084__fzgx_offset_0[];
extern u8 lbl_3_data_10A8__fzgx_offset_0[];
extern u8 lbl_3_data_10F0__fzgx_offset_0[];
extern u8 lbl_3_data_1134__fzgx_offset_0[];
extern u8 lbl_3_data_178__fzgx_offset_0[];
extern u8 lbl_3_data_1C0__fzgx_offset_0[];
extern u8 lbl_3_data_240__fzgx_offset_0[];
extern u8 lbl_3_data_288__fzgx_offset_0[];
extern u8 lbl_3_data_2FC__fzgx_offset_0[];
extern u8 lbl_3_data_318__fzgx_offset_0[];
extern u8 lbl_3_data_374__fzgx_offset_0[];
extern u8 lbl_3_data_3B4__fzgx_offset_0[];
extern u8 lbl_3_data_404__fzgx_offset_0[];
extern u8 lbl_3_data_420__fzgx_offset_0[];
extern u8 lbl_3_data_460__fzgx_offset_0[];
extern u8 lbl_3_data_554__fzgx_offset_0[];
extern u8 lbl_3_data_648__fzgx_offset_0[];
extern u8 lbl_3_data_684__fzgx_offset_0[];
extern u8 lbl_3_data_6B8__fzgx_offset_0[];
extern u8 lbl_3_data_6F0__fzgx_offset_0[];
extern u8 lbl_3_data_754__fzgx_offset_0[];
extern u8 lbl_3_data_784__fzgx_offset_0[];
extern u8 lbl_3_data_7D4__fzgx_offset_0[];
extern u8 lbl_3_data_818__fzgx_offset_0[];
extern u8 lbl_3_data_870__fzgx_offset_0[];
extern u8 lbl_3_data_8A0__fzgx_offset_0[];
extern u8 lbl_3_data_8F8__fzgx_offset_0[];
extern u8 lbl_3_data_93C__fzgx_offset_0[];
extern u8 lbl_3_data_974__fzgx_offset_0[];
extern u8 lbl_3_data_9D0__fzgx_offset_0[];
extern u8 lbl_3_data_A10__fzgx_offset_0[];
extern u8 lbl_3_data_A78__fzgx_offset_0[];
extern u8 lbl_3_data_A94__fzgx_offset_0[];
extern u8 lbl_3_data_AD8__fzgx_offset_0[];
extern u8 lbl_3_data_AF8__fzgx_offset_0[];
extern u8 lbl_3_data_B44__fzgx_offset_0[];
extern u8 lbl_3_data_BE8__fzgx_offset_0[];
extern u8 lbl_3_data_C8__fzgx_offset_0[];
extern u8 lbl_3_data_CA4__fzgx_offset_0[];
extern u8 lbl_3_data_CEC__fzgx_offset_0[];
extern u8 lbl_3_data_D50__fzgx_offset_0[];
extern u8 lbl_3_data_D70__fzgx_offset_0[];
extern u8 lbl_3_data_DC0__fzgx_offset_0[];
extern u8 lbl_3_data_DDC__fzgx_offset_0[];
extern u8 lbl_3_data_E10__fzgx_offset_0[];
extern u8 lbl_3_data_E14__fzgx_offset_0[];
extern u8 lbl_3_data_E34__fzgx_offset_0[];
extern u8 lbl_3_data_E38__fzgx_offset_0[];
extern u8 lbl_3_data_E58__fzgx_offset_0[];
extern u8 lbl_3_data_E60__fzgx_offset_0[];
extern u8 lbl_3_data_E6C__fzgx_offset_0[];
extern u8 lbl_3_data_E74__fzgx_offset_0[];
extern u8 lbl_3_data_EB0__fzgx_offset_0[];
extern u8 lbl_3_data_ECC__fzgx_offset_0[];
extern u8 lbl_3_data_F18__fzgx_offset_0[];
extern u8 lbl_3_data_F60__fzgx_offset_0[];
extern u8 lbl_3_data_FA4__fzgx_offset_0[];
extern u8 lbl_3_data_FF4__fzgx_offset_0[];
static union { u32 w[42]; s16 v[0x54]; } fzgx_pool_init_fzgx_obj_lbl_3_data_0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x10000, 0x30007, 0x80009, 0xA000B, 0xC000D, 0xE000F, 0x100011, 0x120013,
    0x140015, 0x160017, 0x180019, 0x1A001B, 0x1C001D, 0x1E001F, 0x200021, 0x220023,
    0x240025, 0x260027, 0x28FFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60002, 0x50004, 0x10000,
    0x30007, 0x80009, 0xA000B, 0xC000D, 0xE000F, 0x100011, 0x120013, 0x140015,
    0x160017, 0x180019, 0x1A001B, 0x1C001D, 0x1E001F, 0x200021, 0x220023, 0x240025,
    0x260027, 0x28FFFF
}};
static union { u32 w[3]; u32 v[3]; } fzgx_pool_init_fzgx_obj_lbl_3_data_A8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFF0000, 0xFFFFFFFF, 0xFFFFFFFF
}};
static union { u32 w[1]; u32 v; } fzgx_pool_init_fzgx_obj_lbl_3_data_B4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF
}};
static union { u32 w[1]; s32 v; } fzgx_pool_init_fzgx_obj_lbl_3_data_B8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF
}};
static union { u32 w[2]; u32 v[2]; } fzgx_pool_init_fzgx_obj_lbl_3_data_BC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF, 0xFFFFFFFF
}};
static union { u32 w[1]; s16 v[2]; } fzgx_pool_init_fzgx_obj_lbl_3_data_C4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFF0000
}};
static union { u32 w[1063]; u8 v[0x1164 - 0xC8]; } fzgx_pool_init_fzgx_obj_lbl_3_data_C8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x52657475, 0x726E2074, 0x6F207072, 0x6576696F, 0x75732073, 0x63726565, 0x6E0A7769, 0x74686F75,
    0x74207361, 0x76696E67, 0x20636861, 0x6E676573, 0x2E204F4B, 0x3F000000, 0x0, 0x8CBB5B82,
    0xB082F15D, 0x8DDD5B82, 0xB482A25D, 0x82CC95CF, 0x5B82D682, 0xF15D8D58, 0x5B82B182, 0xA45D82F0,
    0x835A815B, 0x837582B9, 0x82B882C9, 0xA914F82, 0xCC89E696, 0xCA82C996, 0xDF5B82E0, 0x82C75D82,
    0xE882DC82, 0xB7814282, 0xE682EB82, 0xB582A282, 0xC582B782, 0xA93F0A00, (u32)lbl_3_data_C8__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_104__fzgx_offset_0, 0x53656C65, 0x63746564, 0x20706172, 0x74732061,
    0x6E642070, 0x696C6F74, 0x2E0A5361, 0x76652061, 0x6E642072, 0x65747572, 0x6E20746F, 0xA746865,
    0x20707265, 0x76696F75, 0x73207363, 0x7265656E, 0x2E204F4B, 0x3F000000, 0x8CBB5B82, 0xB082F15D,
    0x8DDD5B82, 0xB482A25D, 0x82CC8370, 0x815B8363, 0x81418370, 0x8343838D, 0x83628367, 0x82C98C88,  /* fzgx-allow: A1 retail data bytes */
    0x92E882B5, 0x82DC82B7, 0x81420A83, 0x5A815B83, 0x7582B582, 0xC4914F82, 0xCC89E696, 0xCA82C996,  /* fzgx-allow: A1 retail data bytes */
    0xDF5B82E0, 0x82C75D82, 0xE882DC82, 0xB7814282, 0xE682EB82, 0xB582A282, 0xC582B782, 0xA93F0A00,
    (u32)lbl_3_data_178__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_1C0__fzgx_offset_0, 0x53656C65, 0x63742074,
    0x68652063, 0x75727265, 0x6E742063, 0x6F6C6F72, 0x2E0A5361, 0x76652061, 0x6E642072, 0x65747572,
    0x6E20746F, 0xA746865, 0x20707265, 0x76696F75, 0x73207363, 0x7265656E, 0x2E204F4B, 0x3F000000,
    0x8CBB5B82, 0xB082F15D, 0x8DDD5B82, 0xB482A25D, 0x82CC834A, 0x8389815B, 0x82C98C88, 0x92E882B5,
    0x82DC82B7, 0x81420A83, 0x5A815B83, 0x7582B582, 0xC4914F82, 0xCC89E696, 0xCA82C996, 0xDF5B82E0,  /* fzgx-allow: A1 retail data bytes */
    0x82C75D82, 0xE882DC82, 0xB7814282, 0xE682EB82, 0xB582A282, 0xC582B782, 0xA93F0A00, (u32)lbl_3_data_240__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_288__fzgx_offset_0, 0x53617665, 0x20637572, 0x72656E74,
    0x20636861, 0x6E676573, 0x2E204F4B, 0x3F000000, 0x8CBB5B82, 0xB082F15D, 0x8DDD5B82, 0xB482A25D,
    0x82CC95CF, 0x5B82D682, 0xF15D8D58, 0x5B82B182, 0xA45D82F0, 0x835A815B, 0x837582B5, 0x82DC82B7,
    0x81420A82, 0xE682EB82, 0xB582A282, 0xC582B782, 0xA93F0000, (u32)lbl_3_data_2FC__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_318__fzgx_offset_0, 0x54686572, 0x65206172, 0x65202564, 0x20667265, 0x6520626C,
    0x6F636B73, 0x206F6620, 0x73706163, 0x650A6F6E, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264,
    0x20696E20, 0x534C4F54, 0x2E000000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368,  /* fzgx-allow: A1 retail data bytes */
    0x82CD0A25, 0x64837583, 0x8D836283, 0x4E82CC8B, 0xF35B82A0, 0x5D82AB82, 0xAA82A082, 0xE882DC82,
    0xB7000000, (u32)lbl_3_data_374__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_3B4__fzgx_offset_0, 0x47617261,
    0x67652044, 0x61746120, 0x77617320, 0x6E6F7420, 0x73617665, 0x642E0000, 0x834B838C, 0x815B8357,  /* fzgx-allow: A1 retail data bytes */
    0x8366815B, 0x835E82CD, 0x835A815B, 0x837582B3, 0x82EA82DC, 0x82B982F1, 0x82C582B5, 0x82BD0000,
    (u32)lbl_3_data_404__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_420__fzgx_offset_0, 0x54686572, 0x65206973,
    0x206E6F74, 0x20656E6F, 0x75676820, 0x66726565, 0x20737061, 0x6365206F, 0x6E207468, 0x65204D65,
    0x6D6F7279, 0x20436172, 0x6420696E, 0x20534C4F, 0x542E0A54, 0x6F207361, 0x76652046, 0x2D5A4552,
    0x4F204758, 0x20476172, 0x61676520, 0x44617461, 0x2C20796F, 0x75206E65, 0x65642061, 0x74206C65,
    0x61737420, 0x31206672, 0x65652066, 0x696C6520, 0x616E640A, 0x31382066, 0x72656520, 0x626C6F63,
    0x6B732E20, 0x28546F20, 0x6D616E61, 0x67652066, 0x696C6573, 0x206F6E20, 0x74686520, 0x4D656D6F,
    0x72792043, 0x6172642C, 0x20706C65, 0x61736520, 0x676F2074, 0x6F0A7468, 0x65204E69, 0x6E74656E,
    0x646F2047, 0x616D6543, 0x75626520, 0x4D656D6F, 0x72792043, 0x61726420, 0x6D616E61, 0x67656D65,
    0x6E742073, 0x63726565, 0x6E2E2900, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368,  /* fzgx-allow: A1 retail data bytes */
    0x82C982CD, 0x8BF382AB, 0x976597CA, 0x82AA82C8, 0x82A282A9, 0x81418374, 0x83408343, 0x838B9094,  /* fzgx-allow: A1 retail data bytes */
    0x82CC90A7, 0x8CC082F0, 0xA897A82, 0xA682C482, 0xB582DC82, 0xA282DC82, 0xB7814283, 0x5A815B83,
    0x7582B782, 0xE982C982, 0xCD8FAD82, 0xC882AD82, 0xC682E083, 0x74834083, 0x43838B31, 0x82C282C6,
    0xA313883, 0x75838D83, 0x62834E95, 0x4B977682, 0xC582B781, 0x42288381, 0x8382838A, 0x815B834A,  /* fzgx-allow: A1 retail data bytes */
    0x815B8368, 0x82CC93E0, 0x976582F0, 0x90AE979D, 0x82B782E9, 0x82C982CD, 0x81410A96, 0x7B91CC82,  /* fzgx-allow: A1 retail data bytes */
    0xCC838183, 0x82838A81, 0x5B834A81, 0x5B836889, 0xE696CA82, 0xC58D7382, 0xC882C182, 0xC482AD82,
    0xBE82B382, 0xA2290000, (u32)lbl_3_data_460__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_554__fzgx_offset_0,
    0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x4C4F540A, 0x69732063, 0x6F727275,
    0x70746564, 0x20616E64, 0x2063616E, 0x6E6F7420, 0x62652075, 0x7365642E, 0x0, 0x83478393,
    0x8352815B, 0x836882AA, 0x82A882A9, 0x82B582A2, 0x82C582B7, 0x82E60000, (u32)lbl_3_data_648__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_684__fzgx_offset_0, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420,
    0x696E2053, 0x4C4F540A, 0x69732064, 0x616D6167, 0x65642061, 0x6E642063, 0x616E6E6F, 0x74206265,
    0x20757365, 0x642E0000, 0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CD8141,  /* fzgx-allow: A1 retail data bytes */
    0x8366815B, 0x835E82AA, 0xA82B182, 0xED82EA82, 0xC482A282, 0xE982CC82, 0xC58E675B, 0x82B55D97,
    0x705B82E6, 0x82A45D82, 0xC582AB82, 0xDC82B982, 0xF1814200, (u32)lbl_3_data_6B8__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_6F0__fzgx_offset_0, 0x506C6561, 0x73652069, 0x6E736572, 0x74206120, 0x66756E63,
    0x74696F6E, 0x616C204D, 0x656D6F72, 0x79204361, 0x72642069, 0x6E20534C, 0x4F542E00, 0x534C4F54,
    0x82C98E67, 0x5B82B55D, 0x97705B82, 0xE682A45D, 0x82B782E9, 0x83818382, 0x838A815B, 0x834A815B,
    0x836882F0, 0x82B382B5, 0x82C482AD, 0x82BE82B3, 0x82A20000, (u32)lbl_3_data_754__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_784__fzgx_offset_0, 0x54686520, 0x64657669, 0x63652069, 0x6E20534C, 0x4F542069,
    0x73206E6F, 0x74207375, 0x70706F72, 0x7465642E, 0xA506C65, 0x61736520, 0x696E7365, 0x72742061,
    0x204D656D, 0x6F727920, 0x43617264, 0x2E000000, 0x534C4F54, 0x82C982CD, 0x83818382, 0x838A815B,
    0x834A815B, 0x836888C8, 0x5B82A25D, 0x8A4F5B82, 0xAA82A25D, 0x82CC82E0, 0x82CC82AA, 0xA82B382,
    0xB382C182, 0xC482A282, 0xDC82B781, 0x42000000, (u32)lbl_3_data_7D4__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_818__fzgx_offset_0, 0x506C6561, 0x73652073, 0x656C6563, 0x74207468, 0x65204D65, 0x6D6F7279,
    0x20436172, 0x6420536C, 0x6F742074, 0x6F206265, 0x20757365, 0x642E0000, 0x8E675B82, 0xB55D9770,
    0x5B82E682, 0xA45D82B7, 0x82E98381, 0x8382838A, 0x815B834A, 0x815B8368, 0x8358838D, 0x83628367,  /* fzgx-allow: A1 retail data bytes */
    0x82F00A91, 0x495B82A6, 0x82E75D82, 0xF182C582, 0xAD82BE82, 0xB382A200, (u32)lbl_3_data_870__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_8A0__fzgx_offset_0, 0x839F8163, 0x436F6E74, 0x696E7565, 0x20776974,
    0x686F7574, 0x20736176, 0x696E670A, 0x83B28163, 0x54727920, 0x61676169, 0x6E000000, (u32)lbl_3_data_8F8__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, 0x47617261, 0x67652044, 0x61746120,
    0x63616E6E, 0x6F742062, 0x65207361, 0x7665642E, 0xA436F6E, 0x74696E75, 0x65207769, 0x74686F75,
    0x74207361, 0x76696E67, 0x3F000000, 0x82B182CC, 0x82DC82DC, 0x82C582CD, 0x8141834B, 0x838C815B,  /* fzgx-allow: A1 retail data bytes */
    0x83578366, 0x815B835E, 0x82F00A83, 0x5A815B83, 0x7582C582, 0xAB82DC82, 0xB982F182, 0xAA82E682,  /* fzgx-allow: A1 retail data bytes */
    0xEB82B582, 0xA282C582, 0xB782A93F, 0x0, (u32)lbl_3_data_93C__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_974__fzgx_offset_0, 0x4E6F204D, 0x656D6F72, 0x79204361, 0x72642077, 0x61732064, 0x65746563,
    0x7465642E, 0xA476172, 0x61676520, 0x44617461, 0x20636F75, 0x6C64206E, 0x6F742062, 0x65206C6F,
    0x61646564, 0x2E000000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882AA, 0x8CA95B82, 0xDD5D82C2,
    0x82A982E8, 0x82DC82B9, 0x82F18142, 0xA834B83, 0x8C815B83, 0x57836681, 0x5B835E82, 0xF0838D81,
    0x5B836882, 0xC582AB82, 0xDC82B982, 0xF182C582, 0xB582BD81, 0x42000000, (u32)lbl_3_data_9D0__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_A10__fzgx_offset_0, 0x47617261, 0x67652044, 0x61746120, 0x77617320,
    0x6E6F7420, 0x6C6F6164, 0x65642E00, 0x834B838C, 0x815B8357, 0x8366815B, 0x835E82CD, 0x838D815B,  /* fzgx-allow: A1 retail data bytes */
    0x836882B3, 0x82EA82DC, 0x82B982F1, 0x82C582B5, 0x82BD8142, 0x0, (u32)lbl_3_data_A78__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_A94__fzgx_offset_0, 0x47617261, 0x67652044, 0x61746120, 0x77617320,
    0x6E6F7420, 0x63726561, 0x7465642E, 0x0, 0x834B838C, 0x815B8357, 0x8366815B, 0x835E82CD,  /* fzgx-allow: A1 retail data bytes */
    0x8DEC5B82, 0xB382AD5D, 0x90AC5B82, 0xB982A25D, 0x82B382EA, 0x82DC82B9, 0x82F182C5, 0x82B582BD,
    0x81420000, (u32)lbl_3_data_AD8__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_AF8__fzgx_offset_0, 0x54686572,  /* fzgx-allow: A1 retail data bytes */
    0x65206973, 0x206E6F20, 0x47617261, 0x67652044, 0x61746120, 0x6F6E2074, 0x6865204D, 0x656D6F72,
    0x790A4361, 0x72642069, 0x6E20534C, 0x4F542E20, 0x576F756C, 0x6420796F, 0x75206C69, 0x6B652074,
    0x6F206372, 0x65617465, 0xA476172, 0x61676520, 0x44617461, 0x206F6E20, 0x74686520, 0x4D656D6F,
    0x72792043, 0x61726420, 0x696E2053, 0x4C4F543F, 0xA283120, 0x66726565, 0x2066696C, 0x6520616E,
    0x64203138, 0x20667265, 0x6520626C, 0x6F636B73, 0x20617265, 0x20726571, 0x75697265, 0x642E2900,
    0x534C4F54, 0x82CC8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82C982CD, 0x834B838C, 0x815B8357,  /* fzgx-allow: A1 retail data bytes */
    0x8366815B, 0x835E82AA, 0xA82A082, 0xE882DC82, 0xB982F181, 0x42534C4F, 0x5482CC83, 0x81838283,
    0x8A815B83, 0x4A815B83, 0x6882C90A, 0x834B838C, 0x815B8357, 0x8366815B, 0x835E82F0, 0x8DEC5B82,  /* fzgx-allow: A1 retail data bytes */
    0xB382AD5D, 0x90AC5B82, 0xB982A25D, 0x82B582C4, 0x82E082E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9,
    0x3F0A2831, 0x38837583, 0x8D836283, 0x4E8E675B, 0x82B55D97, 0x705B82E6, 0x82A45D82, 0xB582DC82,
    0xB7290000, (u32)lbl_3_data_B44__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_BE8__fzgx_offset_0, 0x4F6E6365,
    0x20796F75, 0x27726520, 0x72656164, 0x792C2070, 0x72657373, 0x20746865, 0x20839F20, 0x42757474,
    0x6F6E2E0A, 0x50726573, 0x73207468, 0x652083A0, 0x20427574, 0x746F6E20, 0x746F2063, 0x616E6365,
    0x6C2E0000, 0x8F805B82, 0xB682E35D, 0x94F55B82, 0xF182D15D, 0x82AA82C5, 0x82AB82BD, 0x82E7839F,
    0x82F0899F, 0x5B82A85D, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420A83, 0xA082C583, 0x4C838383,  /* fzgx-allow: A1 retail data bytes */
    0x93835A83, 0x8B82B582, 0xDC82B781, 0x42000000, (u32)lbl_3_data_CA4__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_CEC__fzgx_offset_0, 0x43616E63, 0x656C204D, 0x656D6F72, 0x79204361, 0x7264206F, 0x70657261,
    0x74696F6E, 0x732E0000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x8DEC5B82, 0xB382AC5D,
    0x8BC65B82, 0xE582A45D, 0x82F0834C, 0x83838393, 0x835A838B, 0x82B582DC, 0x82B582BD, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_3_data_D50__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_D70__fzgx_offset_0, 0x506C6561, 0x73652050,
    0x72657373, 0x20746865, 0x20839F20, 0x42757474, 0x6F6E2E00, 0x839F82F0, 0x899F5B82, 0xA85D82B5,
    0x82C482AD, 0x82BE82B3, 0x82A28142, 0x0, (u32)lbl_3_data_DC0__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_DDC__fzgx_offset_0, 0x59455300, 0x82CD82A2, 0x0, (u32)lbl_3_data_E10__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_E14__fzgx_offset_0, 0x4E4F0000, 0x82A282A2, 0x82A60000, (u32)lbl_3_data_E34__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_E38__fzgx_offset_0, 0x536C6F74, 0x20410000, 0x8358838D, 0x83628367,
    0x41000000, 0x536C6F74, 0x20420000, 0x8358838D, 0x83628367, 0x42000000, (u32)lbl_3_data_E58__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_E60__fzgx_offset_0, (u32)lbl_3_data_E6C__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_E74__fzgx_offset_0, 0x436C6561, 0x72696E67, 0x20726567, 0x69737472, 0x6174696F, 0x6E2E204F,
    0x4B3F0000, 0x936F5B82, 0xC682A45D, 0x985E5B82, 0xEB82AD5D, 0x82F0834E, 0x838A8341, 0x82B582DC,
    0x82B78142, 0xA82E682, 0xEB82B582, 0xA282C582, 0xB782A93F, 0x0, (u32)lbl_3_data_EB0__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0,
    (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_100__fzgx_offset_0, (u32)lbl_3_data_ECC__fzgx_offset_0, 0x1000021, 0x1000041, 0x1000081, 0x1000101,
    0x1000011, 0x1000011, 0x1000101, 0x1000081, 0x1000041, 0x1000021, 0x1000011, 0x1000011,
    0x1000041, 0x1000041, 0x1000101, 0x1000101, 0x1000101, 0xFFFFFFFF, 0x1000011, 0x1000011,
    0x1000011, 0x1000021, 0x1000021, 0x1000021, 0x1000021, 0x1000041, 0x1000041, 0x1000081,
    0x1000081, 0x1000101, 0x1000101, 0x1000101, 0x1000041, 0x1000041, 0xFFFFFFFF, 0x1000021,
    0x1000021, 0x1000081, 0x1000101, 0x1000041, 0x1000011, 0x1000011, 0x1000041, 0x1000081,
    0x1000101, 0x1000021, 0x1000081, 0x1000101, 0x1000011, 0x1000021, 0x1000101, 0x1000081,
    0x1000041, 0x1000041, 0xFFFFFFFF, 0x100002F, 0x100001F, 0x100004F, 0x100001F, 0x100002F,
    0x100001F, 0x100004F, 0x100002F, 0xFFFFFFFF, 0x100002F, 0x100010F, 0x100002F, 0x100001F,
    0x100004F, 0x100008F, 0x100008F, 0x100001F, 0xFFFFFFFF, 0x100008F, 0x100010F, 0x100001F,
    0x100010F, 0x100008F, 0x100002F, 0x100010F, 0x100001F, 0xFFFFFFFF, 0x100004F, 0x100004F,
    0x100001F, 0x100010F, 0x100008F, 0x100001F, 0x100002F, 0x100004F, 0xFFFFFFFF, 0x100010F,
    0x100001F, 0x100002F, 0x100008F, 0x100008F, 0x100010F, 0x100001F, 0x100002F, 0xFFFFFFFF,
    0x1000011, 0x1000081, 0x1000101, 0x1000081, 0x1000011, 0x1000041, 0x1000021, 0x1000011,
    0x1000081, 0x1000101, 0x1000081, 0x1000101, 0x1000011, 0x1000021, 0x1000011, 0x1000021,
    0x1000011, 0xFFFFFFFF, 0x1000021, 0x1000021, 0x1000021, 0x1000041, 0x1000021, 0x1000021,
    0x1000021, 0x1000041, 0x1000011, 0x1000011, 0x1000081, 0x1000101, 0x1000081, 0x1000101,
    0x1000081, 0x1000101, 0xFFFFFFFF, (u32)lbl_3_data_F18__fzgx_offset_0, (u32)lbl_3_data_F60__fzgx_offset_0, (u32)lbl_3_data_FA4__fzgx_offset_0, (u32)lbl_3_data_FF4__fzgx_offset_0, (u32)lbl_3_data_1018__fzgx_offset_0,
    (u32)lbl_3_data_103C__fzgx_offset_0, (u32)lbl_3_data_1060__fzgx_offset_0, (u32)lbl_3_data_1084__fzgx_offset_0, (u32)lbl_3_data_10A8__fzgx_offset_0, (u32)lbl_3_data_10F0__fzgx_offset_0, 0xA, (u32)lbl_3_data_1134__fzgx_offset_0
}};
static union { u32 w[27]; u8 v[0x6C]; } fzgx_pool_init_fzgx_obj_lbl_3_data_1164 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x76656869, 0x636C652F, 0x76656869, 0x636C655F, 0x73656C2E, 0x6172632E, 0x6C7A0000, 0x76656869,
    0x636C655F, 0x70617274, 0x732F7061, 0x7274735F, 0x616C6C2E, 0x6172632E, 0x6C7A0000, 0x25732F73,
    0x656C7374, 0x25303264, 0x2E74706C, 0x2E6C7A00, 0x73746167, 0x65000000, 0x25732F73, 0x656C7374,
    0x25303264, 0x2E676D61, 0x2E6C7A00
}};
static union { u32 w[1]; s16 v[2]; } fzgx_pool_init_fzgx_obj_lbl_3_data_11D0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x10000
}};
static union { u32 w[1]; u32 v; } fzgx_pool_init_fzgx_obj_lbl_3_data_11D4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF
}};
static union { u32 w[476]; u8 v[0x1948 - 0x11D8]; } fzgx_pool_init_fzgx_obj_lbl_3_data_11D8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF, 0x63757374, 0x6F6D697A, 0x652E6300, 0x44726177, 0x4F726453, 0x79730000, 0x53746172,
    0x74204375, 0x73746F6D, 0x697A6520, 0x3A202564, 0xA000000, 0x4C696768, 0x744D6169, 0x6E000000,
    0x456E6420, 0x20204375, 0x73746F6D, 0x697A6520, 0x3A202564, 0xA000000, 0x534D445F, 0x43555354,
    0x5F544F50, 0x0, 0x0, 0x0, 0x0, 0x0, (u32)fn_1_12B4__fzgx_offset_0, (u32)fn_1_12FC__fzgx_offset_0,
    (u32)fn_1_1300__fzgx_offset_0, 0x534D445F, 0x43555354, 0x5F4D454E, 0x55000000, 0x0, 0x0, 0x0,
    0x0, (u32)fn_3_3E58__fzgx_offset_0, (u32)fn_3_3F20__fzgx_offset_0, (u32)fn_3_41B0__fzgx_offset_0, 0x534D445F, 0x43555354, 0x5F4D454D, 0x43415244,
    0x5F534156, 0x45000000, 0x0, 0x0, (u32)fn_3_368C__fzgx_offset_0, (u32)fn_3_381C__fzgx_offset_0, (u32)fn_3_39F0__fzgx_offset_0, 0x534D445F,
    0x43555354, 0x5F4D454D, 0x43415244, 0x5F4C4F41, 0x44000000, 0x0, 0x0, (u32)fn_3_14E4__fzgx_offset_0,
    (u32)fn_3_15A0__fzgx_offset_0, (u32)fn_3_33A0__fzgx_offset_0, 0x534D445F, 0x43555354, 0x5F474152, 0x41474500, 0x0, 0x0,
    0x0, 0x0, (u32)fn_3_4F08__fzgx_offset_0, (u32)fn_3_5500__fzgx_offset_0, (u32)fn_3_5B9C__fzgx_offset_0, 0x534D445F, 0x43555354, 0x5F465A43,
    0x41525F53, 0x454C0000, 0x0, 0x0, 0x0, (u32)fn_3_4380__fzgx_offset_0, (u32)fn_3_48E0__fzgx_offset_0, (u32)fn_3_4BEC__fzgx_offset_0,
    0x534D445F, 0x43555354, 0x5F474152, 0x4147455F, 0x4D454E55, 0x0, 0x0, 0x0,
    (u32)fn_3_5C4C__fzgx_offset_0, (u32)fn_3_5C8C__fzgx_offset_0, (u32)fn_3_5CBC__fzgx_offset_0, 0x534D445F, 0x43555354, 0x5F454D42, 0x5F544F50, 0x4D454E55,
    0x0, 0x0, 0x0, (u32)fn_3_1304C__fzgx_offset_0, (u32)fn_3_13050__fzgx_offset_0, (u32)fn_3_13054__fzgx_offset_0, 0x534D445F, 0x43555354,
    0x5F454D42, 0x5F4D454E, 0x55000000, 0x0, 0x0, 0x0, (u32)fn_3_13058__fzgx_offset_0, (u32)fn_3_1305C__fzgx_offset_0,
    (u32)fn_3_13060__fzgx_offset_0, 0x534D445F, 0x43555354, 0x5F454D42, 0x5F4D414B, 0x45520000, 0x0, 0x0,
    0x0, (u32)fn_3_130C8__fzgx_offset_0, (u32)fn_3_1349C__fzgx_offset_0, (u32)fn_3_1338C__fzgx_offset_0, 0x534D445F, 0x43555354, 0x5F454D42, 0x5F50524F,
    0x0, 0x0, 0x0, 0x0, (u32)fn_3_13064__fzgx_offset_0, (u32)fn_3_13068__fzgx_offset_0, (u32)fn_3_1306C__fzgx_offset_0, 0x534D445F,
    0x43555354, 0x5F454D42, 0x5F4D454D, 0x0, 0x0, 0x0, 0x0, (u32)fn_3_13070__fzgx_offset_0,
    (u32)fn_3_13074__fzgx_offset_0, (u32)fn_3_13078__fzgx_offset_0, 0x534D445F, 0x43555354, 0x5F53484F, 0x505F4D45, 0x4E550000, 0x0,
    0x0, 0x0, (u32)fn_3_7038__fzgx_offset_0, (u32)fn_3_7594__fzgx_offset_0, (u32)fn_3_7688__fzgx_offset_0, 0x534D445F, 0x43555354, 0x5F504153,
    0x54450000, 0x0, 0x0, 0x0, 0x0, (u32)fn_3_11FF0__fzgx_offset_0, (u32)fn_3_12910__fzgx_offset_0, (u32)fn_3_12B14__fzgx_offset_0,
    0x534D445F, 0x43555354, 0x5F4D4143, 0x48494E45, 0x5F4E414D, 0x45000000, 0x0, 0x0,
    (u32)fn_3_7770__fzgx_offset_0, (u32)fn_3_77B0__fzgx_offset_0, (u32)fn_3_7864__fzgx_offset_0, 0x534D445F, 0x43555354, 0x5F50494C, 0x4F545F53, 0x454C0000,
    0x0, 0x0, 0x0, (u32)fn_3_7868__fzgx_offset_0, (u32)fn_3_786C__fzgx_offset_0, (u32)fn_3_7870__fzgx_offset_0, 0x534D445F, 0x43555354,
    0x5F504152, 0x54535F43, 0x55535400, 0x0, 0x0, 0x0, (u32)fn_3_7E5C__fzgx_offset_0, (u32)fn_3_8A90__fzgx_offset_0,
    (u32)fn_3_9710__fzgx_offset_0, 0x534D445F, 0x43555354, 0x5F434F4C, 0x43485F4D, 0x454E5500, 0x0, 0x0,
    0x0, (u32)fn_3_990C__fzgx_offset_0, (u32)fn_3_A12C__fzgx_offset_0, (u32)fn_3_ACF4__fzgx_offset_0, 0x534D445F, 0x43555354, 0x5F434152, 0x5F53484F,
    0x505F4D45, 0x4E550000, 0x0, 0x0, (u32)fn_3_AE74__fzgx_offset_0, (u32)fn_3_B5FC__fzgx_offset_0, (u32)fn_3_B6E4__fzgx_offset_0, 0x534D445F,
    0x43555354, 0x5F53484F, 0x505F544F, 0x50000000, 0x0, 0x0, 0x0, (u32)fn_3_61B8__fzgx_offset_0,
    (u32)fn_3_6270__fzgx_offset_0, (u32)fn_3_6540__fzgx_offset_0, 0x534D445F, 0x43555354, 0x5F495445, 0x4D5F5348, 0x4F500000, 0x0,
    0x0, 0x0, (u32)fn_3_680C__fzgx_offset_0, (u32)fn_3_6D2C__fzgx_offset_0, (u32)fn_3_6E14__fzgx_offset_0, 0x534C4F54, 0x0, 0x25730000,
    0x43757374, 0x6F6D697A, 0x654D656D, 0x63617264, 0x44697370, 0x0, (u32)fn_3_15A0__fzgx_offset_114, (u32)fn_3_15A0__fzgx_offset_158,
    (u32)fn_3_15A0__fzgx_offset_574, (u32)fn_3_15A0__fzgx_offset_580, (u32)fn_3_15A0__fzgx_offset_CCC, (u32)fn_3_15A0__fzgx_offset_CE4, (u32)fn_3_15A0__fzgx_offset_AFC, (u32)fn_3_15A0__fzgx_offset_B1C, (u32)fn_3_15A0__fzgx_offset_D14, (u32)fn_3_15A0__fzgx_offset_D3C,
    (u32)fn_3_15A0__fzgx_offset_D88, (u32)fn_3_15A0__fzgx_offset_D98, (u32)fn_3_15A0__fzgx_offset_DB0, (u32)fn_3_15A0__fzgx_offset_DEC, (u32)fn_3_15A0__fzgx_offset_E0C, (u32)fn_3_15A0__fzgx_offset_12D8, (u32)fn_3_15A0__fzgx_offset_12F8, (u32)fn_3_15A0__fzgx_offset_1570,
    (u32)fn_3_15A0__fzgx_offset_10B4, (u32)fn_3_15A0__fzgx_offset_10DC, (u32)fn_3_15A0__fzgx_offset_1110, (u32)fn_3_15A0__fzgx_offset_1130, (u32)fn_3_15A0__fzgx_offset_1720, (u32)fn_3_15A0__fzgx_offset_1738, (u32)fn_3_15A0__fzgx_offset_1934, (u32)fn_3_15A0__fzgx_offset_1ACC,
    (u32)fn_3_15A0__fzgx_offset_61C, (u32)fn_3_15A0__fzgx_offset_644, (u32)fn_3_15A0__fzgx_offset_8EC, (u32)fn_3_15A0__fzgx_offset_90C, 0x43445F50, 0x61727473, 0x53656C44, 0x69737000,
    0x43445F43, 0x6F6C4368, 0x67446973, 0x70000000, 0x43445F46, 0x5A436172, 0x53656C44, 0x69737000,
    0x43445F53, 0x6176654E, 0x6F53656C, 0x0, 0x43445F53, 0x686F7054, 0x6F704469, 0x73700000,
    0x203005F, 0x834B838C, 0x815B8357, 0x0, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x2040064, 0x83478393, 0x8375838C, 0x83800000, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x205006E, 0x83568387, 0x83628376, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xFFFF, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2030061, 0x83478366, 0x83428362, 0x8367834A,
    0x815B8250, 0x0, 0x0, 0x0, 0x0, 0x2040061, 0x83478366, 0x83428362,  /* fzgx-allow: A1 retail data bytes */
    0x8367834A, 0x815B8251, 0x0, 0x0, 0x0, 0x0, 0x2050061, 0x83478366,  /* fzgx-allow: A1 retail data bytes */
    0x83428362, 0x8367834A, 0x815B8252, 0x0, 0x0, 0x0, 0x0, 0x2060061,  /* fzgx-allow: A1 retail data bytes */
    0x83478366, 0x83428362, 0x8367834A, 0x815B8253, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0xFFFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x81840000, 0x43757374, 0x6F6D697A, 0x65546F70, 0x44697370, 0x0, 0x203006C,
    0x834A8389, 0x815B8360, 0x83468393, 0x83570000, 0x0, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x204006B, 0x837D8356, 0x8393834A, 0x8358835E, 0x837D8343, 0x83590000, 0x0, 0x0,
    0x0, 0x2050068, 0x83478393, 0x8375838C, 0x838082CC, 0x82CD82E8, 0x82C282AF, 0x0,
    0x0, 0x0, 0xFFFF, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x76656869, 0x636C652F, 0x0, 0x63617263, 0x6D6E7465,
    0x782E7470, 0x6C000000, 0x2E2E0000, 0x63686172, 0x61000000, 0x25735F66, 0x6163652E, 0x74706C00,
    0x25735F66, 0x6163652E, 0x676D6100, (u32)fn_3_65B0__fzgx_offset_30, (u32)fn_3_65B0__fzgx_offset_3C, (u32)fn_3_65B0__fzgx_offset_48, (u32)fn_3_65B0__fzgx_offset_10C, (u32)fn_3_65B0__fzgx_offset_128,
    (u32)fn_3_65B0__fzgx_offset_144, (u32)fn_3_65B0__fzgx_offset_160, (u32)fn_3_65B0__fzgx_offset_17C, (u32)fn_3_65B0__fzgx_offset_198, (u32)fn_3_65B0__fzgx_offset_1BC, 0x43445F49, 0x74656D53, 0x686F7044,
    0x69737000, 0x43445F50, 0x61727473, 0x53686F70, 0x44697370, 0x0, 0x82C882DC, 0x82A682F0,
    0x82AB82DF, 0x82C482AD, 0x82BE82B3, 0x82A20A00
}};
static union { u32 w[4]; u8 v[0x10]; } fzgx_pool_init_fzgx_obj_lbl_3_data_1948 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x43445F43, 0x61725368, 0x6F704469, 0x73700000
}};

#pragma section code_type ".fzgxpool"

#pragma section code_type ".fzgxpool"
static void fzgx_base_order_data(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: the TU references .data in retail order */
    s = *(u8 *)&fzgx_pool_init_fzgx_obj_lbl_3_data_0.v;
    s = *(u8 *)&fzgx_pool_init_fzgx_obj_lbl_3_data_A8.v;
    s = *(u8 *)&fzgx_pool_init_fzgx_obj_lbl_3_data_B4.v;
    s = *(u8 *)&fzgx_pool_init_fzgx_obj_lbl_3_data_B8.v;
    s = *(u8 *)&fzgx_pool_init_fzgx_obj_lbl_3_data_BC.v;
    s = *(u8 *)&fzgx_pool_init_fzgx_obj_lbl_3_data_C4.v;
    s = *(u8 *)&fzgx_pool_init_fzgx_obj_lbl_3_data_C8.v;
    s = *(u8 *)&fzgx_pool_init_fzgx_obj_lbl_3_data_1164.v;
    s = *(u8 *)&fzgx_pool_init_fzgx_obj_lbl_3_data_11D0.v;
    s = *(u8 *)&fzgx_pool_init_fzgx_obj_lbl_3_data_11D4.v;
    s = *(u8 *)&fzgx_pool_init_fzgx_obj_lbl_3_data_11D8.v;
    s = *(u8 *)&fzgx_pool_init_fzgx_obj_lbl_3_data_1948.v;
}
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_8;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_C;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_F0;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_120;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_140;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20844;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20848;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_2084C;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20850;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20854;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20860;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_21960;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_241E0;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_24370;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_2437C;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_243A8;
}
#pragma section code_type ".text"

#pragma section code_type ".text"

extern CustomizeSlot lbl_3_bss_7DB60[41];
extern u8 lbl_3_bss_2C584[];
extern Bss8B3A0 lbl_1_bss_8B3A0;

extern void fn_3_286BC(void);
extern void fn_1_80058(s8, CustomizeSlot *);
extern u32 fn_1_12A32C(void *);
extern void fn_1_12A2B8(u32);
extern void fn_1_80C18(CustomizeEntry *, CustomizeSlot *, s8);
extern s32 fn_8006FDEC(void);
extern s32 fn_1_3F8C(void *, void (*)(void), s32, s32);
extern void fn_1_4A00(s32, s32, u32);
extern void fn_1_152510(void *, s32, void *, s32, s32);
extern s32 fn_1_152970(s16 *, s16 *, s16, s32, void *, s32, s32);
extern void fn_1_47F74(s32);

void fn_3_AE74(void) {
    s16 saved;
    struct { s16 value; } i;
    s16 lo;
    s16 hi;
    s16 a;
    s16 b;

    saved = fzgx_obj_lbl_3_bss_F0.unk_6;
    for (i.value = 0; i.value < 41; i.value++) {
        fn_1_80058(i.value, &lbl_3_bss_7DB60[i.value]);
        lbl_3_bss_7DB60[i.value].id = i.value;
        lbl_3_bss_7DB60[i.value].flags = 0;
        lbl_3_bss_7DB60[i.value].flags |= 0x10;
        lbl_3_bss_7DB60[i.value].mask = 1 << fzgx_pool_init_fzgx_obj_lbl_3_data_11D0.v[0];
    }
    fzgx_pool_init_fzgx_obj_lbl_3_data_11D4.v = fn_1_12A32C(fzgx_pool_init_fzgx_obj_lbl_3_data_1164.v);
    fn_1_12A2B8(1);
    fn_1_80C18(fzgx_obj_lbl_3_bss_20854[0], lbl_3_bss_7DB60, 41);
    fn_1_12A2B8(0);
    for (i.value = 0; i.value < 41; i.value++) {
        fzgx_obj_lbl_3_bss_20854[0][i.value].value = fzgx_pool_init_fzgx_obj_lbl_3_data_11D4.v;
    }

    if (fzgx_pool_init_fzgx_obj_lbl_3_data_B8.v == -1) {
        fn_8006FDEC();
        fzgx_pool_init_fzgx_obj_lbl_3_data_B8.v = fn_1_3F8C(fzgx_pool_init_fzgx_obj_lbl_3_data_1948.v, fn_3_286BC, 0, 8);
    }
    fn_1_4A00(1, 15, fzgx_obj_lbl_3_bss_20850);
    fzgx_obj_lbl_3_bss_243A8[0] = 0;
    fn_1_152510(fzgx_pool_init_fzgx_obj_lbl_3_data_0.v, 42, lbl_3_bss_2C584, 7, 7);
    lbl_1_bss_8B3A0.unk_9E = saved;
    fzgx_obj_lbl_3_bss_20.unk_C4 = 0;
    if (fzgx_pool_init_fzgx_obj_lbl_3_data_C4.v[0] == -1) {
        fzgx_pool_init_fzgx_obj_lbl_3_data_C4.v[0] = 1;
    } else {
        do {
            fn_1_152970(&a, &b, fzgx_pool_init_fzgx_obj_lbl_3_data_C4.v[0], 0, lbl_3_bss_2C584, 7, 7);
            lo = -fzgx_obj_lbl_3_bss_20.unk_C4;
            hi = lo + 2;
            if (a < lo || a > hi) {
                fzgx_obj_lbl_3_bss_20.unk_C4--;
            }
        } while (a < lo || a > hi);
    }

    fzgx_obj_lbl_3_bss_120[0] = -1;
    fn_1_47F74(0x4A);
    fn_1_47F74(0x54);
    fn_1_47F74(0x38);
    fn_1_47F74(0x3E);
    fn_1_47F74(0x37);
    fn_1_47F74(0x55);
    fn_1_47F74(0x30);
    fn_1_47F74(0x35);
    fn_1_47F74(0x3A);
    fn_1_47F74(0x40);
    fn_1_47F74(0x44);
    fn_1_47F74(0x50);
    fn_1_47F74(0x33);
    fn_1_47F74(0x2E);
    fn_1_47F74(0x31);
    fn_1_47F74(0x4F);
    fn_1_47F74(0x39);
    fn_1_47F74(0x3D);
    fn_1_47F74(0x4C);
    fn_1_47F74(0x3F);
    fn_1_47F74(0x48);
    fn_1_47F74(0x52);
    fn_1_47F74(0x45);
    fn_1_47F74(0x53);
    fn_1_47F74(0x3C);
    fn_1_47F74(0x56);
    fn_1_47F74(0x43);
    fn_1_47F74(0x42);
    fn_1_47F74(0x32);
    fn_1_47F74(0x2F);
    fn_1_47F74(0x34);
    fn_1_47F74(0x36);
    fn_1_47F74(0x4D);
    fn_1_47F74(0x46);
    fn_1_47F74(0x41);
    fn_1_47F74(0x51);
    fn_1_47F74(0x4E);
    fn_1_47F74(0x47);
    fn_1_47F74(0x3B);
    fn_1_47F74(0x4B);
    fn_1_47F74(0x49);
    fn_1_47F74(0xA3);
    fzgx_obj_lbl_3_bss_C[0] = 0;
}
/* fzgx:end fn_3_AE74 */

/* fzgx:begin fn_3_B270 noprologue */
#include "types.h"

typedef struct Sig_fn_1_152CB4_Fn152CB4Cell {
    s16 id;
    u8 pad[2];
    u32 flags;
} Sig_fn_1_152CB4_Fn152CB4Cell;

typedef struct {
    u8 pad_0[0x8];
    u16 hold;    /* 0x08 */
    u8 pad_A[0x6];
    volatile u16 trig;    /* 0x10 */  /* fzgx-allow: S2 retail rereads the trigger word at every test */
    u16 rept;    /* 0x12 */
} fn_3_B270_Pad;

typedef struct {
    u32 unk_0;
    u32 unk_4;
} fn_3_B270_Obj0;

typedef struct {
    u8 pad_0[0xC4];
    s16 scroll;  /* 0xC4 */
    u8 pad_C6[0xA];
} fn_3_B270_List;

typedef struct {
    u8 pad_0[0x6];
    s16 port;    /* 0x06 */
} fn_3_B270_Input;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
fn_3_B270_Obj0 fzgx_obj_lbl_3_bss_0;
s32 fzgx_obj_lbl_3_bss_8;
s32 fzgx_obj_lbl_3_bss_C;
u32 lbl_3_bss_C__fzgx_offset_4[2];
u32 lbl_3_bss_18__fzgx_offset_0[2];
fn_3_B270_List fzgx_obj_lbl_3_bss_20;
fn_3_B270_Input fzgx_obj_lbl_3_bss_F0;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_8;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_C;
    s = *(u8 *)&lbl_3_bss_C__fzgx_offset_4;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_3_bss_18__fzgx_offset_0;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_F0;
}
#pragma section code_type ".text"

typedef struct {
    u8 pad_0[0x48F8];
    u32 unk_48F8;
} fn_3_B270_lbl_1_bss_7F0C0;

extern s16 lbl_3_data_C4;
extern fn_3_B270_Pad lbl_1_bss_9F8[];
extern fn_3_B270_lbl_1_bss_7F0C0 lbl_1_bss_7F0C0;
extern Sig_fn_1_152CB4_Fn152CB4Cell lbl_3_bss_2C584[][7];

extern u32 fn_1_8D5F0(s16);
extern s32 fn_1_F7EDC(s16);
extern s16 fn_1_152CB4(s16, s16, s16, Sig_fn_1_152CB4_Fn152CB4Cell *, s16, s16);
extern void fn_1_A2D84(u32);
extern s32 fn_1_152970(s16 *, s16 *, s16, u32, Sig_fn_1_152CB4_Fn152CB4Cell *, s16, s16);
extern s16 fn_1_8D640(s16);
extern s32 fn_1_F7BE4(s16);
extern void fn_1_F7CAC(s16);
extern void fn_3_BD00(s16, s16, s16, u32);

s32 fn_3_B270(void) {
    s16 port;
    s16 dx;
    s16 dy;
    s16 prev;
    s32 found;
    s16 i;
    s16 row;
    s16 col;
    s16 sel;
    s16 lo;
    s16 hi;
    u32 money;
    s16 id;
    s16 cost;
    s16 row2;
    s16 col2;
    u16 *trig;

    port = fzgx_obj_lbl_3_bss_F0.port;
    prev = lbl_3_data_C4;
    dx = 0;
    dy = 0;
    found = 0;
    for (i = 0; i < 41; i++) {
        if ((fn_1_8D5F0(i) & 0x10000000) && fn_1_F7EDC(i)) {
            found = 1;
            break;
        }
    }

    if (((lbl_1_bss_9F8[port].trig >> 3) & 1) || ((lbl_1_bss_9F8[port].rept >> 3) & 1)) {
        dx = -1;
    }
    if (((lbl_1_bss_9F8[port].trig >> 2) & 1) || ((lbl_1_bss_9F8[port].rept >> 2) & 1)) {
        dx++;
    }
    if ((lbl_1_bss_9F8[port].trig & 1) || (lbl_1_bss_9F8[port].rept & 1)) {
        dy = -1;
    }
    if (((lbl_1_bss_9F8[port].trig >> 1) & 1) || ((lbl_1_bss_9F8[port].rept >> 1) & 1)) {
        dy++;
    }

    if (dy != 0 || dx != 0) {
        lbl_3_data_C4 = fn_1_152CB4(lbl_3_data_C4, dx, dy, &lbl_3_bss_2C584[0][0], 7, 7);
        if (!found) {
            if (lbl_3_data_C4 == 24 && dx > 0 && prev == lbl_3_data_C4) {
                lbl_3_data_C4 = 30;
            }
        } else {
            if (((u16)(lbl_3_data_C4 - 34) <= 3 || lbl_3_data_C4 == 38) && dx > 0 && prev == lbl_3_data_C4) {
                lbl_3_data_C4 = 40;
            }
        }
    }

    if (prev != lbl_3_data_C4) {
        fn_1_A2D84(0xA9010000);
    }
    fn_1_152970(&row, &col, lbl_3_data_C4, 0, &lbl_3_bss_2C584[0][0], 7, 7);
    lo = -fzgx_obj_lbl_3_bss_20.scroll;
    hi = lo + 2;
    if (row < lo || row > hi) {
        fn_3_BD00(dx, 0, dx * 10, 0x800000);
        fzgx_obj_lbl_3_bss_20.scroll -= dx;
    }

    if ((lbl_1_bss_9F8[port].hold >> 8) & 1) {
        id = lbl_3_data_C4;
        cost = fn_1_8D640(id);
        if (fn_1_F7EDC(id) != 0 && fn_1_F7BE4(id) == 0 &&
            (money = lbl_1_bss_7F0C0.unk_48F8) >= cost) {
            lbl_1_bss_7F0C0.unk_48F8 = money - cost;
            fn_1_F7CAC(id);
            fzgx_obj_lbl_3_bss_8 = 1;
            fn_1_152970(&row2, &col2, id, 0, &lbl_3_bss_2C584[0][0], 7, 7);
            lbl_3_bss_2C584[row2][col2].flags |= 0x8000000;
            fn_1_A2D84(0xA9010100);
            fzgx_obj_lbl_3_bss_C = 1;
        } else {
            fn_1_A2D84(0xA9011400);
        }
    }

    if ((lbl_1_bss_9F8[port].hold >> 9) & 1) {
        fn_1_A2D84(0xA9010200);
        return -1;
    }
    return 0;
}
/* fzgx:end fn_3_B270 */

/* fzgx:begin fn_3_B5FC */
void fn_3_B5FC(void) {
    u32 flags;
    s32 ready;

    if (lbl_3_bss_120 == -1) {
        fn_1_4C10();
    }

    flags = lbl_3_bss_F0[9];
    if ((flags & (~((u32)-1 >> 1))) != 0 &&
        (flags & 1) == 0 &&
        (lbl_3_bss_F0[0] & 2) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }

    if (ready == 0) {
        if (lbl_3_bss_120 != -1) {
            s32 value = lbl_3_bss_120;
            lbl_3_bss_120 = -1;
            lbl_1_bss_96A = (u16)value;
        } else if (fn_3_B270() == (s16)-1) {
            fn_1_4A00(0, 15, lbl_3_bss_20850);
            lbl_3_bss_243A8[0] = 0;
            lbl_3_bss_120 = 110;
        }
    }
}
/* fzgx:end fn_3_B5FC */

/* fzgx:begin fn_3_B6E4 noprologue */
#include "types.h"

typedef struct Sig_fn_1_A7728_FnA7728Resource {
    u8 pad_104[0x104];
    void *field_104;
    void *field_108;
} Sig_fn_1_A7728_FnA7728Resource;
typedef struct Sig_fn_1_A7728_FnA7728Object {
    u8 pad_394[0x394];
    Sig_fn_1_A7728_FnA7728Resource *field_394;
} Sig_fn_1_A7728_FnA7728Object;
struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct fn_3_B6E4_lbl_3_data_11D4 {
    u32 unk_0;
};
struct fn_3_B6E4_lbl_3_bss_20854 {
    u32 unk_0;
};
struct fn_3_B6E4_lbl_1_bss_6D82C {
    u32 unk_0;
};
struct fn_3_B6E4_lbl_3_data_B8 {
    u32 unk_0;
};
struct fn_3_B6E4_lbl_3_bss_20850 {
    u32 unk_0;
};

extern struct fn_3_B6E4_lbl_1_bss_6D82C lbl_1_bss_6D82C;
extern struct fn_3_B6E4_lbl_3_bss_20850 lbl_3_bss_20850;
extern struct fn_3_B6E4_lbl_3_bss_20854 lbl_3_bss_20854;
extern struct fn_3_B6E4_lbl_3_data_11D4 lbl_3_data_11D4;
extern struct fn_3_B6E4_lbl_3_data_B8 lbl_3_data_B8;
extern u32 fn_1_12A734(u32);
extern u32 lbl_3_bss_8;
extern u32 lbl_3_bss_C;
extern void * fn_1_435C(void *);
extern void fn_1_12A2B8(u32);
extern void fn_1_12A2D0(s32);
extern void fn_1_426C(u32);
extern void fn_1_48140(int);
extern void fn_1_7F934(Sig_fn_1_A7728_FnA7728Object *);
extern void fn_1_F8030(void);
extern void fn_80071718(struct Sig_fn_80071718_fn_80071718_Arg0 *);

#pragma opt_propagation on

void fn_3_B6E4(void) {
    struct { s32 value; } v1;
    u32 v2;
    u32 v3;
    if ((s32)lbl_3_bss_8 != 0 && (s32)lbl_3_bss_C != 0) {
    fn_1_F8030();
    }
    if ((s32)lbl_3_data_11D4.unk_0 != -1) {
    fn_1_12A2B8(1);
    fn_1_12A2D0(lbl_3_data_11D4.unk_0);
    } else {
    fn_1_12A2B8(0);
    }
    for (v1.value = 0; (s16)v1.value < 41; v1.value++) {
    fn_1_7F934((Sig_fn_1_A7728_FnA7728Object *)(((struct fn_3_B6E4_lbl_3_bss_20854 *)&lbl_3_bss_20854)->unk_0 + v1.value * 1088));
    }
    v2 = lbl_1_bss_6D82C.unk_0;
    if (v2 != 0) {
    fn_80071718((struct Sig_fn_80071718_fn_80071718_Arg0 *)v2);
    lbl_1_bss_6D82C.unk_0 = 0;
    }
    v3 = lbl_3_data_11D4.unk_0;
    if ((s32)v3 != -1) {
    fn_1_12A734(v3);
    }
    lbl_3_data_11D4.unk_0 = -1;
    fn_1_12A2B8(0);
    if ((s32)lbl_3_data_B8.unk_0 != -1) {
    fn_1_435C((void *)lbl_3_bss_20850.unk_0);
    fn_1_426C(lbl_3_data_B8.unk_0);
    lbl_3_data_B8.unk_0 = -1;
    }
    fn_1_48140(74);
    fn_1_48140(84);
    fn_1_48140(56);
    fn_1_48140(62);
    fn_1_48140(55);
    fn_1_48140(85);
    fn_1_48140(48);
    fn_1_48140(53);
    fn_1_48140(58);
    fn_1_48140(64);
    fn_1_48140(68);
    fn_1_48140(80);
    fn_1_48140(51);
    fn_1_48140(46);
    fn_1_48140(49);
    fn_1_48140(79);
    fn_1_48140(57);
    fn_1_48140(61);
    fn_1_48140(76);
    fn_1_48140(63);
    fn_1_48140(72);
    fn_1_48140(82);
    fn_1_48140(69);
    fn_1_48140(83);
    fn_1_48140(60);
    fn_1_48140(86);
    fn_1_48140(67);
    fn_1_48140(66);
    fn_1_48140(50);
    fn_1_48140(47);
    fn_1_48140(52);
    fn_1_48140(54);
    fn_1_48140(77);
    fn_1_48140(70);
    fn_1_48140(65);
    fn_1_48140(81);
    fn_1_48140(78);
    fn_1_48140(71);
    fn_1_48140(59);
    fn_1_48140(75);
    fn_1_48140(73);
    fn_1_48140(163);
}
/* fzgx:end fn_3_B6E4 */

/* fzgx:begin fn_3_B984 */
void fn_3_B984(void *entries, u8 *table) {
    u8 i;
    u8 j;
    u32 offset;

    for (i = 0; i < 3; i++) {
        offset = ((u32)i) << 3;
        if (table[offset + 0x81a4] != ((u8 *)lbl_3_bss_20)[offset]) {
            for (j = 0; j < 4; j++) {
                u8 *entry = (u8 *)entries + (u32)j * 0x2060;
                if ((*(u32 *)(entry + 0x24) & ((u32)1 << 31)) != 0) {
                    s16 *field = (s16 *)(entry + 0x20);
                    if (*field == i) {
                        fn_80008BEC(field, 0, 0x2060);
                    }
                }
            }
            fn_1_FDFF4();
            fn_1_FC4E0((u8 *)lbl_3_bss_2C7C0 +
                (s32)((s16 *)lbl_3_bss_F0)[4] * 0x10440, 1);
        }
    }
}
/* fzgx:end fn_3_B984 */

/* fzgx:begin fn_3_BA74 noprologue */
#include "rel/customize/customize.h"

extern u8 lbl_3_bss_6DE20[64832];
extern void *lbl_801A6410;
extern void *fn_1_45D0(void *, u32, void *, u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80008BA8(void *, void *, u32);
extern void *fn_1_7F254(void *, s32);
extern void fn_1_FDC00(void);
extern void fn_1_FE014(void);
extern void fn_1_FD324(void);
extern int fn_1_FD844(void *, void *);

/* 0x10440-byte per-slot context in lbl_3_bss_2C7C0 */
typedef struct {
    void *obj;
    u8 unk_4;
    u8 pad_5[7];
    u32 unk_C;
    u8 pad_10[0x10420 - 0x10];
    u32 unk_10420;
    void *unk_10424;
    void *unk_10428;
    void *unk_1042C;
    u8 pad_10430[0x10];
} CtxSlot;

/* lbl_3_bss_2C7C0 is four slots */
#define SLOTS (*(CtxSlot (*)[4])&lbl_3_bss_2C7C0)

/* callback block at +0x10420 of each slot */
typedef struct {
    u32 unk_0;
    void *unk_4;
    void *unk_8;
    void *unk_C;
    u8 pad_10[sizeof(CtxSlot) - 0x10];
} CtxSlotHi;
#define HI ((CtxSlotHi *)((u8 *)&lbl_3_bss_2C7C0 + 0x10420))

#pragma opt_common_subs off
typedef struct lbl_3_bss_F0_t {
    u8 pad_0[0x8];
    s16 unk_8;
    u8 pad_A[0x26];
} lbl_3_bss_F0_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_3_bss_F0_t fzgx_obj_lbl_3_bss_F0;
u32 lbl_3_bss_120[8];
u32 fzgx_obj_lbl_3_bss_140[33217];
u16 lbl_3_bss_20844;
u16 fzgx_pool_lbl_3_bss_F0_gap_20846;
u32 fzgx_obj_lbl_3_bss_20848;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_F0;
    s = *(u8 *)&lbl_3_bss_120;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_140;
    s = *(u8 *)&lbl_3_bss_20844;
    s = *(u8 *)&fzgx_pool_lbl_3_bss_F0_gap_20846;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20848;
}
#pragma section code_type ".text"

void fn_3_BA74(void)
{
    s32 tmp_cse1;
    u32 *buf;
    u8 *base;
    u8 idx;
    CtxSlot *ctx;
    u8 i;
    u32 off;

    idx = fzgx_obj_lbl_3_bss_F0.unk_8;
    lbl_3_bss_7EBA4 = fn_1_45D0(lbl_801A6410, 0x440, lbl_3_data_11DC, 0x1281);
    lbl_3_bss_7EBA8 = (u32)fn_1_45D0(lbl_801A6410, 0xA20, lbl_3_data_11DC, 0x1282);
    fn_80008BEC(lbl_3_bss_7EBA4, 0, 0x440);
    fn_80008BEC((void *)lbl_3_bss_7EBA8, 0, 0xA20);
    buf = &lbl_3_bss_7EBA8;
    lbl_3_bss_7EBA4->unk_3A0 = *buf;
    base = (u8 *)&fzgx_obj_lbl_3_bss_140 + idx * 0x81C0;
    for (i = 0; i < 3; i++) {
        tmp_cse1 = i * 0x360;
        fn_80008BA8((u8 *)*buf + tmp_cse1,
                    lbl_3_bss_6DE20 + ((*((0x81A4 + i * 8) + (base))) - i * 25) * 0xA20 + tmp_cse1,
                    0x360);
    }
    lbl_3_bss_7EBA4->unk_390 = 0x4000000;
    lbl_3_bss_7EBA4->unk_3A4 = (u32)fn_1_7F254(base, 2);
    off = idx * sizeof(CtxSlot);
    ctx = (CtxSlot *)((u8 *)&lbl_3_bss_2C7C0 + off);
    ctx->unk_4 = 4;
    lbl_3_bss_7EBA4->unk_3BA = 1;
    ctx->obj = lbl_3_bss_7EBA4;
    ((CtxSlotHi *)((u8 *)HI + off))->unk_8 = fn_1_FDC00;
    ((CtxSlotHi *)((u8 *)HI + off))->unk_C = fn_1_FE014;
    ((CtxSlotHi *)((u8 *)HI + off))->unk_4 = fn_1_FD324;
    ((CtxSlotHi *)((u8 *)HI + off))->unk_0 = 0;
    ctx->unk_C = 0x20000000;
    fn_1_FD844(base, ctx);
}
#pragma opt_common_subs reset
/* fzgx:end fn_3_BA74 */

/* fzgx:begin fn_3_BC60 */
void fn_3_BC60(void) {
    u32 *value;

    value = &lbl_3_bss_7EBA4;
    if (*value != 0) {
        fn_1_7F3AC(*value);
    }
    if (lbl_3_bss_7EBA8 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_3_bss_7EBA8, lbl_3_data_11DC, 0x12ad);
    }
    if (lbl_3_bss_7EBA4 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_3_bss_7EBA4, lbl_3_data_11DC, 0x12af);
    }
    lbl_3_bss_7EBA4 = 0;
    lbl_3_bss_7EBA8 = 0;
}
/* fzgx:end fn_3_BC60 */

/* fzgx:begin fn_3_BD00 noprologue */
#include "types.h"

extern u16 lbl_3_bss_F0[24];

void fn_3_BD00(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    *(u32 *)&lbl_3_bss_F0[18] = 0;
    *(u32 *)&lbl_3_bss_F0[18] |= 0x80000000;
    *(u32 *)&lbl_3_bss_F0[18] |= arg3;
    *(s16 *)&lbl_3_bss_F0[20] = arg0;
    *(s16 *)&lbl_3_bss_F0[21] = arg1;
    *(s16 *)&lbl_3_bss_F0[22] = arg2;
}
/* fzgx:end fn_3_BD00 */

/* fzgx:begin fn_3_BD30 noprologue */
#include "types.h"

extern u16 lbl_3_bss_F0[24];

void fn_3_BD30(void) {
    s16 current;
    s16 value;

    if ((*(u32 *)&lbl_3_bss_F0[18] & 0x80000000) == 0) {
        return;
    }
    value = *(s16 *)&lbl_3_bss_F0[20];
    current = *(s16 *)&lbl_3_bss_F0[21];
    current += value;
    *(s16 *)&lbl_3_bss_F0[21] = current;
    if (value <= 0 || current < *(s16 *)&lbl_3_bss_F0[22]) {
        if (value >= 0) {
            return;
        }
        if (*(s16 *)&lbl_3_bss_F0[21] > *(s16 *)&lbl_3_bss_F0[22]) {
            return;
        }
    }
    *(u32 *)&lbl_3_bss_F0[18] = 0;
}
/* fzgx:end fn_3_BD30 */

/* fzgx:begin fn_3_BD98 */
struct CustomizeState {
    u32 flags;
    u8 unk4;
};

extern struct CustomizeState lbl_3_bss_7ED58;
extern u32 lbl_3_data_1A18;
extern void fn_1_B9BE0(void);
extern void fn_1_B9DE8(struct CustomizeState *);

extern u32 fn_3_1307C(void);
extern u32 lbl_3_bss_A1784[5];
extern u32 lbl_3_data_1A10;
extern u32 lbl_3_bss_7EDA0[8];

void fn_3_BD98(void) {
    fn_1_B9BE0();
    fn_1_B9DE8(&lbl_3_bss_7ED58);
    lbl_3_bss_7ED58.flags |= 0x10;
    lbl_3_bss_7ED58.unk4 = 9;
    lbl_3_data_1A18 = 0;
    lbl_3_data_1A10 = fn_3_1307C() & 0xff;
    lbl_3_bss_7EDA0[0] = lbl_3_bss_A1784[0];
}
/* fzgx:end fn_3_BD98 */

/* fzgx:begin fn_3_BE10 */
extern struct fn_3_BE10_lbl_3_bss_7ED58 lbl_3_bss_7ED58;
extern struct fn_3_BE10_lbl_3_bss_A1784 lbl_3_bss_A1784;
extern u32 fn_1_B9BE0(void);
extern u32 fn_1_B9DE8(u32);
extern u32 fn_3_1307C(void);
extern u32 lbl_3_bss_7EDA0;
extern u32 lbl_3_data_1A10;
extern u32 lbl_3_data_1A18;

struct fn_3_BE10_lbl_3_bss_7ED58 {
    u32 unk_0;
    u8 unk_4;
};
struct fn_3_BE10_lbl_3_bss_A1784 {
    u32 unk_0;
};

void fn_3_BE10(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t2;
    fn_1_B9BE0();
    fn_1_B9DE8((u32)&lbl_3_bss_7ED58);
    v0 = lbl_3_bss_7ED58.unk_0;
    v1 = (v0 | 16);
    lbl_3_bss_7ED58.unk_4 = 10;
    lbl_3_bss_7ED58.unk_0 = v1;
    lbl_3_data_1A18 = 0;
    t2 = fn_3_1307C();
    v2 = lbl_3_bss_A1784.unk_0;
    lbl_3_data_1A10 = (t2 & 0xFF);
    lbl_3_bss_7EDA0 = v2;
}
/* fzgx:end fn_3_BE10 */

/* fzgx:begin fn_3_BE88 noprologue */
#include "types.h"

extern int fn_1_4C10(void);
extern void fn_3_C128(void);
extern void fn_3_C188(void);
extern void fn_3_C234(void);
extern void fn_3_C28C(void);
extern void fn_3_C328(void);
extern void fn_3_C3B4(void);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
void (*fzgx_obj_lbl_3_data_1958[6])(void) = {
    fn_3_C128, fn_3_C188, fn_3_C234, fn_3_C28C, fn_3_C328, fn_3_C3B4,
};
char fzgx_obj_lbl_3_data_1970[] = "EMB_MEMCARD_WAIT";
char fzgx_obj_lbl_3_data_1984[] = "EMB_MEMCARD_ACTION_INIT";
char fzgx_obj_lbl_3_data_199C[] = "EMB_MEMCARD_SAVE_PROC";
char fzgx_obj_lbl_3_data_19B4[] = "EMB_MEMCARD_LOAD_PROC";
char fzgx_obj_lbl_3_data_19CC[] = "EMB_MEMCARD_DEL_PROC";
char fzgx_obj_lbl_3_data_19E4[] = "EMB_MEMCARD_FINISH";
char *fzgx_pool_gap_04_000019F7_data__fzgx_offset_1[6] = {
    fzgx_obj_lbl_3_data_1970,
    fzgx_obj_lbl_3_data_1984,
    fzgx_obj_lbl_3_data_199C,
    fzgx_obj_lbl_3_data_19B4,
    fzgx_obj_lbl_3_data_19CC,
    fzgx_obj_lbl_3_data_19E4,
};
s32 fzgx_obj_lbl_3_data_1A10 = -1;
s32 fzgx_obj_lbl_3_data_1A14 = -1;
s32 fzgx_obj_lbl_3_data_1A18 = -1;

void fn_3_BE88(void) {
    s32 v0;

    if (fn_1_4C10() == 0) {
        v0 = fzgx_obj_lbl_3_data_1A18;
        if (v0 >= 0) {
            fzgx_obj_lbl_3_data_1A14 = v0;
            fzgx_obj_lbl_3_data_1A18 = -1;
        }
        fzgx_obj_lbl_3_data_1958[fzgx_obj_lbl_3_data_1A14]();
    }
}
/* fzgx:end fn_3_BE88 */

/* fzgx:begin fn_3_BEF0 */
extern u32 lbl_3_bss_7ED58[18];
extern void fn_1_BC29C(u32 *);
extern void fn_1_B9C0C(void);

void fn_3_BEF0(void) {
    fn_1_BC29C(lbl_3_bss_7ED58);
    fn_1_B9C0C();
}
/* fzgx:end fn_3_BEF0 */

/* fzgx:begin fn_3_BF1C */
#include "sdk_addresses.h"

extern s32 lbl_3_bss_120;
extern u32 lbl_3_bss_F0[12];
extern s32 fn_1_4C10(void);
extern s16 fn_3_B270(void);
extern u16 lbl_1_bss_96A;
extern u32 lbl_3_bss_20850;
extern u32 lbl_3_bss_243A8[6];
extern void fn_1_4A00(s32, s32, u32);
extern u16 lbl_3_bss_20[104];
extern u32 lbl_3_bss_2C7C0[66624];
extern void fn_80008BEC(void *, s32, s32);
extern void fn_1_FDFF4(void);
extern void fn_1_FC4E0(void *, s32);
extern u32 lbl_3_bss_7EBA4;
extern u32 lbl_3_bss_7EBA8;
extern u8 lbl_3_data_11DC[84];
extern u32 lbl_801A6410;
extern void fn_1_7F3AC(u32);
extern void fn_1_46B4(u32, u32, u8 *, s32);
extern void fn_1_BC29C(u32 *arg0);
extern void fn_1_B9C0C(void);
extern char lbl_3_data_1A1C[17];
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char *, ...);
extern u32 lbl_3_bss_A179C;
extern u32 lbl_3_data_1A14;


typedef struct Fn3_BF1C_Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Fn3_BF1C_Color;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    u64 u64;
    s8 s8;
    s16 s16;
    s32 s32;
    s64 s64;
    f32 f32;
    f64 f64;
} PPCWGPipe;

// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

extern s32 lbl_3_bss_A1798;

extern u8 lbl_3_bss_7ED58[];
extern void fn_1_4FD64(void);
extern void fn_80074918(s32, s32, s32);
extern void fn_80074788(s32);
extern void fn_80074660(s32);
extern void fn_80073678(s32);
extern void fn_80073C6C(s32);
extern void fn_800747D0(s32, s32, s32, s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800734A8(s32, s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, s32, s32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072864(s32);
extern void fn_8007245C(s32);
extern void fn_800371F8(s32, Fn3_BF1C_Color);
extern void fn_8003462C(s32, s32, s32);
extern u8 fn_1_B7C00(void);
extern void fn_1_BC310(void *);

void fn_3_BF1C(void) {
    s32 mode;

    if (lbl_3_bss_A1798 == 0) {
        return;
    }
    fn_1_4FD64();
    fn_80074918(0, 7, 0);
    fn_80074788(1);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 0xFF, 0xFF, 4);
    fn_80072C24(0, 0xF, 0xF, 0xF, 2);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 1);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_80072864(2);
    fn_8007245C(0x200);
    {
        Fn3_BF1C_Color color = {0x00, 0x00, 0x00, 0xA0};

        fn_800371F8(1, color);
    }
    fn_8003462C(0x80, 7, 4);
    GXFIFO.f32 = 0.0f;
    GXFIFO.f32 = 0.0f;
    GXFIFO.f32 = -1.0f;
    GXFIFO.f32 = 640.0f;
    GXFIFO.f32 = 0.0f;
    GXFIFO.f32 = -1.0f;
    GXFIFO.f32 = 640.0f;
    GXFIFO.f32 = 480.0f;
    GXFIFO.f32 = -1.0f;
    GXFIFO.f32 = 0.0f;
    GXFIFO.f32 = 480.0f;
    GXFIFO.f32 = -1.0f;
    if (fn_1_B7C00() != 0) {
        return;
    }
    mode = (s32)lbl_3_data_1A14;
    if (mode == 5 || (u32)(mode - 2) <= 1 || mode == 4) {
        return;
    }
    fn_1_BC310(lbl_3_bss_7ED58);
}
/* fzgx:end fn_3_BF1C */

/* fzgx:begin fn_3_C128 */
extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_3_bss_A179C;
extern u32 lbl_3_data_1A18;

extern s8 fn_1_BA144(u32 *);

void fn_3_C128(void) {
    s16 result;

    lbl_3_bss_A179C = 0;
    result = fn_1_BA144(lbl_3_bss_7ED58);
    if (result == 0) {
        lbl_3_data_1A18 = 1;
    } else if (result == 1) {
        lbl_3_bss_A179C = 1;
    }
}
/* fzgx:end fn_3_C128 */

/* fzgx:begin fn_3_C188 */
extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_3_data_1A10;
extern u32 *lbl_3_bss_7EDA0;
extern u32 lbl_3_data_1A18;

extern void fn_1_C0510(u32 *arg0);

void fn_3_C188(void) {
    s8 status;

    status = ((s8 *)lbl_3_bss_7ED58)[0x14];
    if (status == 1) {
        lbl_3_bss_7ED58[2] = lbl_3_bss_7EDA0[lbl_3_data_1A10];
        lbl_3_bss_7ED58[3] = 0x2000;
        lbl_3_bss_7ED58[4] = 4;
        lbl_3_data_1A18 = 2;
    } else if (status == 2) {
        lbl_3_data_1A18 = 3;
    } else if (status == 8) {
        lbl_3_data_1A18 = 4;
    }
    fn_1_C0510(lbl_3_bss_7ED58);
}
/* fzgx:end fn_3_C188 */

/* fzgx:begin fn_3_C234 */
extern char lbl_3_data_1A1C[17];
extern u32 lbl_3_data_1A18;

extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char *, ...);

void fn_3_C234(void) {
    if (!fn_1_B7C00()) {
        if (fn_1_B7CD4() == 0) {
            OSReport(lbl_3_data_1A1C, fn_1_B7C5C());
        }
        lbl_3_data_1A18 = 5;
    }
}
/* fzgx:end fn_3_C234 */

/* fzgx:begin fn_3_C28C noprologue */
#include "types.h"

extern u32 lbl_3_bss_7EDA0[8];
extern u32 lbl_3_data_1958[6];
extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410[1];

extern void fn_80008BA8(u32, u32, u32);
extern void fn_1_46B4(u32, u32, void *, u32);

typedef struct CustomizeData {
    u8 pad0[0xb8];
    u32 index;
    u8 padbc[4];
    u32 state;
    u8 padc4[0x14];
    u8 tail[0xd8 - 0xd8];
} CustomizeData;

void fn_3_C28C(void) {
    CustomizeData *data = (CustomizeData *)lbl_3_data_1958;
    u32 *table = (u32 *)lbl_3_bss_7EDA0[0];
    u32 *work = lbl_3_bss_7ED58;
    fn_80008BA8(table[data->index], work[2], work[3]);
    if (work[2] != 0) {
        fn_1_46B4(lbl_801A6410[0], work[2], &data->tail[0], 0x13c);
        work[2] = 0;
        work[3] = 0;
    }
    data->state = 5;
}
/* fzgx:end fn_3_C28C */

/* fzgx:begin fn_3_C3B4 */
extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_3_bss_A179C;
extern u32 lbl_3_data_1A14;
extern u32 lbl_3_data_1A18;

extern void fn_1_BC29C(u32 *arg0);
extern void fn_1_B9C0C(void);

void fn_3_C3B4(void) {
    fn_1_BC29C(lbl_3_bss_7ED58);
    fn_1_B9C0C();
    lbl_3_bss_A179C = 1;
    lbl_3_data_1A14 = -1;
    lbl_3_data_1A18 = -1;
}
/* fzgx:end fn_3_C3B4 */
