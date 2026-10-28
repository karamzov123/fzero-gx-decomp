/* Non-matching: best partial attempt (97.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/option/globals.h"

typedef struct { u32 unk_0; u32 unk_4; } Sig_fn_1_B7F58_Result;
typedef struct { u8 x, y; } CalPair;
typedef struct { u8 r, g, b, a; } Sig_fn_800081C8_Color;
typedef Sig_fn_800081C8_Color Sig_fn_1_4D4C8_Color4_4D4C8;

struct fn_4_9C14_lbl_4_rodata_0 {
    u8 pad_0[0x8]; f32 unk_8;
    u8 pad_C[0x40]; f32 unk_4C; f32 unk_50;
    u8 pad_54[0x4]; f32 unk_58; u8 pad_5C[0x70]; f32 unk_CC;
    u8 pad_D0[0x58]; f32 unk_128;
    u8 pad_12C[0x10]; f32 unk_13C;
    u8 pad_140[0xD0]; f32 unk_210; u8 pad_214[0x188]; f32 unk_39C; f32 unk_3A0; f32 unk_3A4; f32 unk_3A8;
    u32 unk_3AC; u32 unk_3B0; u32 unk_3B4; u32 unk_3B8; u32 unk_3BC;
    u32 unk_3C0; u32 unk_3C4; u32 unk_3C8; f32 unk_3CC; f32 unk_3D0;
    u8 pad_3D4[8]; f32 unk_3DC; f32 unk_3E0;
    u8 pad_3E4[0xC]; u32 unk_3F0; u32 unk_3F4; f32 unk_3F8;
    f32 unk_3FC; u32 unk_400; u32 unk_404; u32 unk_408; u32 unk_40C;
};
struct fn_4_9C14_Save { u32 words[0x14D8]; };
struct fn_4_9C14_lbl_1_bss_9F8 {
    u8 pad_0[8]; u16 unk_8; u8 pad_A[6]; u16 unk_10; u16 unk_12;
};
struct fn_4_9C14_Request { u8 unk_0; u8 pad_1[3]; u32 unk_4; void *unk_8; void *unk_C; u8 pad_10[0x14]; };
extern struct fn_4_9C14_lbl_4_rodata_0 lbl_4_rodata_0;
extern s32 lbl_801A66B4[1];

extern u16 lbl_1_bss_96A;
extern u8 lbl_1_bss_8B3A0[];
extern u32 lbl_1_bss_7F0C0[0x14D8];
extern u8 lbl_1_bss_718E0[];
extern u32 *lbl_1_bss_718C0;
extern void fn_1_4D0A0(void);
extern u32 fn_1_4AEC0(u32);
extern void fn_1_4AEB4(f32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4D2AC(void *, f32, f32);
extern int fn_1_4C10(void);
extern void fn_1_1280(u32);
extern int fn_1_B7F58(Sig_fn_1_B7F58_Result *);
extern void fn_1_A2D84(u32);
extern u32 fn_800081C8(Sig_fn_800081C8_Color *, Sig_fn_800081C8_Color *, f32);
extern void fn_1_4D494(void);
extern void fn_1_49514(u32 *);
extern void fn_1_49528(u32 *);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D4C8(Sig_fn_1_4D4C8_Color4_4D4C8 *, f32, f32);
extern void fn_4_D1A8(u32, u32, u8);
extern void fn_4_D760(void);
extern s32 fn_4_D420(void);
extern void fn_4_D848(u32);
extern void fn_4_D878(void);
extern void fn_4_A78C(u32);
extern int fn_1_B7E98(int);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_4FD64(void);
extern s32 fn_1_F7954(void);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_F7A20(void);
extern void fn_1_B7CE4(u32, void *);
extern char *strcat(char *, const char *);
extern char *fn_80083DB0(char *, const char *);
extern void fn_1_B7E14(void *);
extern u32 fn_1_C3688(void);
extern void fn_1_AA6D8(u32, u32, void *);
extern u8 fn_1_B7C00(void);
extern u32 fn_4_0(u32, u32, u32, u32, u32);
extern s32 fn_1_B800C(u32);
extern u32 fn_1_B8170(u32);
extern u32 fn_1_B80F0(u32);
extern s32 fn_1_B7C5C(void);
extern void fn_1_C34F0(void);
extern void fn_1_B9904(u32, u32, u32, u32);
extern void fn_1_53E40(f32, f32, f32, f32, f32, s32, void *);
extern int fn_1_B7CD4(void);

/* file-scope .data objects of the retail TU, in retail order (message tables per language) */
extern u8 lbl_4_data_0__fzgx_offset_0[];
extern u8 lbl_4_data_100__fzgx_offset_0[];
extern u8 lbl_4_data_107C__fzgx_offset_0[];
extern u8 lbl_4_data_10A0__fzgx_offset_0[];
extern u8 lbl_4_data_10E8__fzgx_offset_0[];
extern u8 lbl_4_data_10__fzgx_offset_0[];
extern u8 lbl_4_data_111C__fzgx_offset_0[];
extern u8 lbl_4_data_116C__fzgx_offset_0[];
extern u8 lbl_4_data_11AC__fzgx_offset_0[];
extern u8 lbl_4_data_130__fzgx_offset_0[];
extern u8 lbl_4_data_170__fzgx_offset_0[];
extern u8 lbl_4_data_188__fzgx_offset_0[];
extern u8 lbl_4_data_1BC__fzgx_offset_0[];
extern u8 lbl_4_data_210__fzgx_offset_0[];
extern u8 lbl_4_data_254__fzgx_offset_0[];
extern u8 lbl_4_data_284__fzgx_offset_0[];
extern u8 lbl_4_data_2CC__fzgx_offset_0[];
extern u8 lbl_4_data_2F0__fzgx_offset_0[];
extern u8 lbl_4_data_32C__fzgx_offset_0[];
extern u8 lbl_4_data_34C__fzgx_offset_0[];
extern u8 lbl_4_data_37C__fzgx_offset_0[];
extern u8 lbl_4_data_38__fzgx_offset_0[];
extern u8 lbl_4_data_3B8__fzgx_offset_0[];
extern u8 lbl_4_data_400__fzgx_offset_0[];
extern u8 lbl_4_data_438__fzgx_offset_0[];
extern u8 lbl_4_data_480__fzgx_offset_0[];
extern u8 lbl_4_data_4C__fzgx_offset_0[];
extern u8 lbl_4_data_4F0__fzgx_offset_0[];
extern u8 lbl_4_data_578__fzgx_offset_0[];
extern u8 lbl_4_data_57C__fzgx_offset_0[];
extern u8 lbl_4_data_59C__fzgx_offset_0[];
extern u8 lbl_4_data_5A0__fzgx_offset_0[];
extern u8 lbl_4_data_5C0__fzgx_offset_0[];
extern u8 lbl_4_data_5D8__fzgx_offset_0[];
extern u8 lbl_4_data_610__fzgx_offset_0[];
extern u8 lbl_4_data_660__fzgx_offset_0[];
extern u8 lbl_4_data_6D4__fzgx_offset_0[];
extern u8 lbl_4_data_724__fzgx_offset_0[];
extern u8 lbl_4_data_78__fzgx_offset_0[];
extern u8 lbl_4_data_790__fzgx_offset_0[];
extern u8 lbl_4_data_7C__fzgx_offset_0[];
extern u8 lbl_4_data_7DC__fzgx_offset_0[];
extern u8 lbl_4_data_85C__fzgx_offset_0[];
extern u8 lbl_4_data_86C__fzgx_offset_0[];
extern u8 lbl_4_data_89C__fzgx_offset_0[];
extern u8 lbl_4_data_8A8__fzgx_offset_0[];
extern u8 lbl_4_data_8D8__fzgx_offset_0[];
extern u8 lbl_4_data_8F8__fzgx_offset_0[];
extern u8 lbl_4_data_918__fzgx_offset_0[];
extern u8 lbl_4_data_934__fzgx_offset_0[];
extern u8 lbl_4_data_970__fzgx_offset_0[];
extern u8 lbl_4_data_984__fzgx_offset_0[];
extern u8 lbl_4_data_9C0__fzgx_offset_0[];
extern u8 lbl_4_data_9D8__fzgx_offset_0[];
extern u8 lbl_4_data_A10__fzgx_offset_0[];
extern u8 lbl_4_data_A30__fzgx_offset_0[];
extern u8 lbl_4_data_A70__fzgx_offset_0[];
extern u8 lbl_4_data_A78__fzgx_offset_0[];
extern u8 lbl_4_data_AA0__fzgx_offset_0[];
extern u8 lbl_4_data_AAC__fzgx_offset_0[];
extern u8 lbl_4_data_AD4__fzgx_offset_0[];
extern u8 lbl_4_data_B0__fzgx_offset_0[];
extern u8 lbl_4_data_B90__fzgx_offset_0[];
extern u8 lbl_4_data_C18__fzgx_offset_0[];
extern u8 lbl_4_data_C8__fzgx_offset_0[];
extern u8 lbl_4_data_CB0__fzgx_offset_0[];
extern u8 lbl_4_data_C__fzgx_offset_0[];
extern u8 lbl_4_data_D50__fzgx_offset_0[];
extern u8 lbl_4_data_D64__fzgx_offset_0[];
extern u8 lbl_4_data_D84__fzgx_offset_0[];
extern u8 lbl_4_data_D98__fzgx_offset_0[];
extern u8 lbl_4_data_DB8__fzgx_offset_0[];
extern u8 lbl_4_data_DF0__fzgx_offset_0[];
extern u8 lbl_4_data_E48__fzgx_offset_0[];
extern u8 lbl_4_data_E58__fzgx_offset_0[];
extern u8 lbl_4_data_E88__fzgx_offset_0[];
extern u8 lbl_4_data_E98__fzgx_offset_0[];
extern u8 lbl_4_data_EC8__fzgx_offset_0[];
extern u8 lbl_4_data_F08__fzgx_offset_0[];
extern u8 lbl_4_data_F64__fzgx_offset_0[];
extern u8 lbl_4_data_FD8__fzgx_offset_0[];
static union { u32 w[353]; char v[0x584]; } fzgx_pool_init_fzgx_obj_lbl_4_data_0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x436F6E74, 0x726F6C6C, 0x65720000, 0x0, 0x83528393, 0x8367838D, 0x815B8389, 0x0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10__fzgx_offset_0, 0x436F6E74, 0x726F6C6C,
    0x65722053, 0x6F636B65, 0x74000000, 0x83528393, 0x8367838D, 0x815B8389, 0x837C815B, 0x83670000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_38__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_4C__fzgx_offset_0, 0x4F4E0000, 0x4F464600,
    (u32)lbl_4_data_78__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_78__fzgx_offset_0, (u32)lbl_4_data_7C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_7C__fzgx_offset_0, 0x0, 0x55736520, 0x83AD206F, 0x722083B5, 0x20746F20,
    0x63686F6F, 0x73652E00, 0x83AD82A9, 0x83B582C5, 0x8D8096DA, 0x82F09149, 0x82F182C5, 0x82AD82BE,
    0x82B382A2, 0x81420000, (u32)lbl_4_data_B0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C8__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x4D6F7665, 0x2083AD20, 0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063,
    0x68616E67, 0x6520636F, 0x6E74726F, 0x6C732E00, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C59180,
    0x8DEC82F0, 0x95CF8D58, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_100__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_130__fzgx_offset_0, 0x506C6561, 0x73652077, 0x61697420, 0x61206D6F,
    0x6D656E74, 0x2E2E2E00, 0x82B582CE, 0x82E782AD, 0x82A891D2, 0x82BF82AD, 0x82BE82B3, 0x82A28142,
    0x0, (u32)lbl_4_data_170__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_188__fzgx_offset_0, 0x50726573,
    0x73207468, 0x65204120, 0x42757474, 0x6F6E206F, 0x6E207468, 0x6520436F, 0x6E74726F, 0x6C6C6572,
    0x20746F20, 0x62652061, 0x646A7573, 0x7465642E, 0x20507265, 0x73732074, 0x68652042, 0x20427574,
    0x746F6E20, 0x746F2066, 0x696E6973, 0x682E0000, 0x95CF8D58, 0x82B782E9, 0x83528393, 0x8367838D,
    0x815B8389, 0x82C5839F, 0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_1BC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_210__fzgx_offset_0, 0x526F7461, 0x74652074, 0x68652043,
    0x6F6E7472, 0x6F6C2053, 0x7469636B, 0x206F6E65, 0x2066756C, 0x6C207265, 0x766F6C75, 0x74696F6E,
    0x2E000000, 0x83528393, 0x8367838D, 0x815B838B, 0x83588365, 0x83428362, 0x834E82F0, 0x88EA9474,  /* fzgx-allow: A1 retail data bytes */
    0x82C989F1, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_254__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_284__fzgx_offset_0, 0x506C6561, 0x73652061, 0x646A7573, 0x74207468, 0x65207374,
    0x65657269, 0x6E672077, 0x6865656C, 0x2E000000, 0x836E8393, 0x8368838B, 0x82CC92B2, 0x90AE82F0,
    0x8D7382C8, 0x82C182C4, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_2CC__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_2F0__fzgx_offset_0, 0x52657475, 0x726E2074, 0x6F207468, 0x65206465, 0x6661756C,
    0x74207365, 0x7474696E, 0x67733F00, 0x8F898AFA, 0x90DD92E8, 0x82C996DF, 0x82B582DC, 0x82B782A9,
    0x81480000, (u32)lbl_4_data_32C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_34C__fzgx_offset_0, 0x53656C65,  /* fzgx-allow: A1 retail data bytes */
    0x63742074, 0x68652043, 0x6F6E7472, 0x6F6C6C65, 0x7220746F, 0x20626520, 0x6368616E, 0x67656420,
    0x7573696E, 0x67206569, 0x74686572, 0x2083AD20, 0x6F722083, 0xB52E0000, 0x83AD82A9, 0x83B582C5,
    0x95CF8D58, 0x82B782E9, 0x83528393, 0x8367838D, 0x815B8389, 0x82F09149, 0x82F182C5, 0x82AD82BE,  /* fzgx-allow: A1 retail data bytes */
    0x82B382A2, 0x81420000, (u32)lbl_4_data_37C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_3B8__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x4D6F7665, 0x2083AD20, 0x6F722083, 0xB5204C65, 0x6674206F, 0x72205269, 0x67687420, 0x746F2063,
    0x68616E67, 0x65205275, 0x6D626C65, 0x20736574, 0x74696E67, 0x732E0000, 0x83AD82A9, 0x83B582CC,
    0x8DB68945, 0x82C59055, 0x93AE82CC, 0x90DD92E8, 0x82F095CF, 0x8D5882B5, 0x82C482AD, 0x82BE82B3,
    0x82A28142, 0x0, (u32)lbl_4_data_400__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_438__fzgx_offset_0,
    0x54686520, 0x436F6E74, 0x726F6C6C, 0x65722068, 0x61732062, 0x65656E20, 0x64697363, 0x6F6E6E65,
    0x63746564, 0x2E0A2052, 0x65636F6E, 0x6E656374, 0x20746865, 0x20436F6E, 0x74726F6C, 0x6C657220,
    0x696E2053, 0x6F636B65, 0x74202564, 0x206F720A, 0x20707265, 0x73732074, 0x68652041, 0x20427574,
    0x746F6E20, 0x6F6E2061, 0x6E6F7468, 0x65722E00, 0x83528393, 0x8367838D, 0x815B8389, 0x82AA8A4F,  /* fzgx-allow: A1 retail data bytes */
    0x82B382EA, 0x82DC82B5, 0x82BD8142, 0xA835283, 0x93836783, 0x8D815B83, 0x89837C81, 0x5B836725,
    0x6482C982, 0xB382B582, 0xC882A882, 0xB782A981, 0x410A91BC, 0x82CC8352, 0x83938367, 0x838D815B,
    0x838982C5, 0x839F837B, 0x835E8393, 0x82F0899F, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_480__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_4F0__fzgx_offset_0, 0x59455300, 0x82CD82A2,
    0x0
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_lbl_4_data_584 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_578__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_57C__fzgx_offset_0
}};
static union { u32 w[3]; char v[0xC]; } fzgx_pool_init_lbl_4_data_59C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F0000, 0x82A282A2, 0x82A60000
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_lbl_4_data_5A8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_59C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_5A0__fzgx_offset_0
}};
static union { u32 w[611]; char v[0x98C]; } fzgx_pool_init_lbl_4_data_5C0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4368616E, 0x6765204F, 0x7074696F, 0x6E205365, 0x7474696E, 0x67730000, 0x83498376, 0x83568387,
    0x839390DD, 0x92E882F0, 0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0, (u32)lbl_4_data_5C0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_5D8__fzgx_offset_0, 0x41646A75, 0x73742074, 0x68652043, 0x616C6962,
    0x72617469, 0x6F6E2E0A, 0x50726573, 0x73207468, 0x65204120, 0x42757474, 0x6F6E206F, 0x6E207468,
    0x6520436F, 0x6E74726F, 0x6C6C6572, 0xA796F75, 0x2077616E, 0x74206164, 0x6A757374, 0x65642E00,
    0x83528393, 0x8367838D, 0x815B8389, 0x82CC834C, 0x8383838A, 0x8375838C, 0x815B8356, 0x83878393,  /* fzgx-allow: A1 retail data bytes */
    0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420A95, 0xCF8D5882, 0xB782E983, 0x52839383, 0x67838D81,  /* fzgx-allow: A1 retail data bytes */
    0x5B838982, 0xC5839F82, 0xF0899F82, 0xB582C482, 0xAD82BE82, 0xB382A281, 0x42000000, (u32)lbl_4_data_610__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_660__fzgx_offset_0, 0x43757374, 0x6F6D697A, 0x65207468,
    0x6520436F, 0x6E74726F, 0x6C6C6572, 0x2E0A5072, 0x65737320, 0x74686520, 0x41204275, 0x74746F6E,
    0x206F6E20, 0x74686520, 0x436F6E74, 0x726F6C6C, 0x65722074, 0x6F206265, 0x2061646A, 0x75737465,
    0x642E0000, 0x83528393, 0x8367838D, 0x815B8389, 0x82CC834A, 0x8358835E, 0x837D8343, 0x835982F0,  /* fzgx-allow: A1 retail data bytes */
    0x8D7382C8, 0x82A282DC, 0x82B78142, 0xA95CF8D, 0x5882B782, 0xE9835283, 0x93836783, 0x8D815B83,
    0x8982C583, 0x9F82F089, 0x9F82B582, 0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_6D4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_724__fzgx_offset_0, 0x436F6E74, 0x726F6C6C, 0x65722052, 0x756D626C,
    0x65205365, 0x7474696E, 0x67732E0A, 0x20507265, 0x73732074, 0x68652041, 0x20427574, 0x746F6E20,
    0x746F2073, 0x656C6563, 0x74207468, 0x6520436F, 0x6E74726F, 0x6C6C6572, 0x2E000000, 0x83528393,
    0x8367838D, 0x815B8389, 0x82CC9055, 0x93AE82CC, 0x90DD92E8, 0x82F08D73, 0x82C882A2, 0x82DC82B7,  /* fzgx-allow: A1 retail data bytes */
    0x81420A83, 0x52839383, 0x67838D81, 0x5B838982, 0xF0914982, 0xF182C583, 0x9F82F089, 0x9F82B582,  /* fzgx-allow: A1 retail data bytes */
    0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_790__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_7DC__fzgx_offset_0, (u32)lbl_4_data_400__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_438__fzgx_offset_0, 0x53617665,
    0x20636861, 0x6E676573, 0x3F000000, 0x95CF8D58, 0x82F095DB, 0x91B682B5, 0x82DC82B7, 0x82A98148,
    0x0, (u32)lbl_4_data_85C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_86C__fzgx_offset_0, 0x49732074,
    0x68697320, 0x4F4B3F00, 0x82B182EA, 0x82C582E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x81480000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_89C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8A8__fzgx_offset_0, 0x8163826E, 0x826D0000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_8D8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8D8__fzgx_offset_0, 0x826E8265, 0x82650000,
    (u32)lbl_4_data_8F8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_8F8__fzgx_offset_0, 0x4368616E, 0x67652043,
    0x6F6E7472, 0x6F6C6C65, 0x72205365, 0x7474696E, 0x67730000, 0x83528393, 0x8367838D, 0x815B8389,  /* fzgx-allow: A1 retail data bytes */
    0x82CC90DD, 0x92E882F0, 0x8D7382C8, 0x82A282DC, 0x82B78142, 0x0, (u32)lbl_4_data_918__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_934__fzgx_offset_0, 0x4D616E61, 0x6765204D, 0x656D6F72, 0x79204361,
    0x72640000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x8AC7979D, 0x82F08D73, 0x82C882A2,
    0x82DC82B7, 0x81420000, (u32)lbl_4_data_970__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_984__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    0x53656C65, 0x63742053, 0x63726565, 0x6E205365, 0x7474696E, 0x67732000, 0x89E696CA, 0x8382815B,
    0x836882CC, 0x90DD92E8, 0x82F08D73, 0x82C882A2, 0x82DC82B7, 0x81420000, (u32)lbl_4_data_9C0__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_9D8__fzgx_offset_0, 0x55736520, 0x83AD206F, 0x722083B5, 0x20746F20,
    0x63686F6F, 0x73652061, 0x206D6F64, 0x65200000, 0x83AD82A9, 0x83B582CC, 0x8DB68945, 0x82C58382,
    0x815B8368, 0x82F09149, 0x82F182C5, 0x82AD82BE, 0x82B382A2, 0x81420000, (u32)lbl_4_data_A10__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_A30__fzgx_offset_0, 0x4E6F726D, 0x616C0000, 0x836D815B, 0x837D838B,
    0x8365838C, 0x83720000, (u32)lbl_4_data_A70__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_A78__fzgx_offset_0,
    0x57696465, 0x20536372, 0x65656E00, 0x838F8343, 0x83688365, 0x838C8372, 0x0, (u32)lbl_4_data_AA0__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_AAC__fzgx_offset_0, 0x4D6F7665, 0x20746865, 0x20436F6E,
    0x74726F6C, 0x20537469, 0x636B2061, 0x726F756E, 0x6420696E, 0x20612063, 0x6972636C, 0x6520756E,
    0x74696C20, 0x74686520, 0x66696775, 0x72657320, 0x6F6E2074, 0x68650A20, 0x6C656674, 0x20736964,
    0x6520646F, 0x206E6F74, 0x20636861, 0x6E67652E, 0x2041646A, 0x75737420, 0x706C6179, 0x20757369,
    0x6E672074, 0x68652083, 0xB520436F, 0x6E74726F, 0x6C205061, 0x642E0A20, 0x50726573, 0x73207468,
    0x65205820, 0x42757474, 0x6F6E2074, 0x6F207265, 0x7475726E, 0x20746F20, 0x74686520, 0x64656661,
    0x756C7420, 0x73657474, 0x696E6773, 0x2E000000, 0x8DB691A4, 0x82CC907D, 0x8C6082AA, 0x95CF89BB,
    0x82B582C8, 0x82AD82C8, 0x82E982DC, 0x82C583AD, 0x82F088EA, 0x947482C9, 0x89F182B5, 0x82C482AD,
    0x82BE82B3, 0x82A28142, 0xA83B582, 0xC5975682, 0xD182F092, 0xB290AE82, 0xB582C482, 0xAD82BE82,
    0xB382A281, 0x420A83B4, 0x82C58F89, 0x8AFA90DD, 0x92E882C9, 0x96DF82B9, 0x82DC82B7, 0x81420000,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_AD4__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_B90__fzgx_offset_0, 0x5475726E, 0x20746865,
    0x20737465, 0x6572696E, 0x67207768, 0x65656C20, 0x4C656674, 0x20616E64, 0x20526967, 0x68742061,
    0x6E642070, 0x72657373, 0xA746865, 0x20412042, 0x7574746F, 0x6E206174, 0x20746865, 0x20706F69,
    0x6E742079, 0x6F752077, 0x616E7420, 0x746F2073, 0x65742061, 0x73207468, 0x650A206C, 0x696D6974,
    0x2E205573, 0x65207468, 0x65204C20, 0x616E6420, 0x52204275, 0x74746F6E, 0x7320746F, 0x2061646A,
    0x75737420, 0x67616D65, 0x20706C61, 0x792E2000, 0x836E8393, 0x8368838B, 0x82F08DB6, 0x894582C9,
    0x89F182B5, 0x81418CC0, 0x8A4582C6, 0x82B582BD, 0x82A288CA, 0x927582C5, 0x839F82F0, 0x899F82B5,  /* fzgx-allow: A1 retail data bytes */
    0x82C482AD, 0x82BE82B3, 0x82A28142, 0xA826B81, 0x95827183, 0x67838A83, 0x4B815B83, 0x7B835E83,
    0x9382C597, 0x5682D182, 0xF092B290, 0xAE82B582, 0xC482AD82, 0xBE82B382, 0xA281420A, 0x83B482C5,
    0x8F898AFA, 0x90DD92E8, 0x82C996DF, 0x82B982DC, 0x82B78142, 0x0, (u32)lbl_4_data_C18__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_CB0__fzgx_offset_0, 0x4265666F, 0x72652063, 0x6F727265, 0x6374696F,
    0x6E000000, 0x95E290B3, 0x914F0000, (u32)lbl_4_data_D50__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_D64__fzgx_offset_0, 0x41667465, 0x7220636F, 0x72726563, 0x74696F6E, 0x0, 0x95E290B3, 0x8CE30000,
    (u32)lbl_4_data_D84__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_D98__fzgx_offset_0, 0x47616D65, 0x20446174,
    0x6120436F, 0x6E74726F, 0x6C730A49, 0x6E736572, 0x74206120, 0x4D656D6F, 0x72792043, 0x61726420,
    0x696E746F, 0x20536C6F, 0x7420412E, 0x0, 0x8351815B, 0x83808366, 0x815B835E, 0x82CC9180,  /* fzgx-allow: A1 retail data bytes */
    0x8DEC0A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F083, 0x58838D83, 0x62836782, 0x6082C993,
    0xFC82EA82, 0xC482AD82, 0xBE82B382, 0xA2814200, (u32)lbl_4_data_DB8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_DF0__fzgx_offset_0, 0x4C6F6164, 0x2047616D, 0x65204461, 0x74610000, 0x8351815B, 0x83808366,
    0x815B835E, 0x82CC838D, 0x815B8368, 0x0, (u32)lbl_4_data_E48__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_E58__fzgx_offset_0, 0x53617665, 0x2047616D, 0x65204461, 0x74610000, 0x8351815B, 0x83808366,
    0x815B835E, 0x82CC835A, 0x815B8375, 0x0, (u32)lbl_4_data_E88__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_E98__fzgx_offset_0, 0x54686572, 0x65206973, 0x206E6F20, 0x47616D65, 0x20446174, 0x61206F6E,
    0x20746869, 0x73204D65, 0x6D6F7279, 0x20436172, 0x642E0A20, 0x53617669, 0x6E67206E, 0x65772064,
    0x6174612E, 0x0, 0x83818382, 0x838A815B, 0x834A815B, 0x836882C9, 0xA835181, 0x5B838083,
    0x66815B83, 0x5E82AA8C, 0xA982C282, 0xA982E882, 0xDC82B982, 0xF181420A, 0x90568B4B, 0x835A815B,
    0x837582B5, 0x82DC82B7, 0x81420000  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_lbl_4_data_F4C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_EC8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_F08__fzgx_offset_0
}};
static union { u32 w[64]; char v[0x100]; } fzgx_pool_init_lbl_4_data_F64 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x54686572, 0x65206973, 0x206E6F20, 0x47616D65, 0x20446174, 0x61206F6E, 0x20746865, 0x204D656D,
    0x6F727920, 0x43617264, 0x2E0A4966, 0x20796F75, 0x20736176, 0x652C2074, 0x68652047, 0x616D6520,
    0x44617461, 0x20637572, 0x72656E74, 0x6C79206C, 0x6F616465, 0x640A7769, 0x6C6C2061, 0x6C6C2062,
    0x65206C6F, 0x73742E20, 0x49732074, 0x68617420, 0x4F4B3F00, 0x83818382, 0x838A815B, 0x834A815B,
    0x836882C9, 0x8351815B, 0x83808366, 0x815B835E, 0x82AA8CA9, 0x82C282A9, 0x82E882DC, 0x82B982F1,  /* fzgx-allow: A1 retail data bytes */
    0x81420A90, 0x568B4B83, 0x5A815B83, 0x7582B782, 0xE982C68C, 0xBB8DDD83, 0x8D815B83, 0x6882B382,  /* fzgx-allow: A1 retail data bytes */
    0xEA82C482, 0xA282E983, 0x51815B83, 0x80836681, 0x5B835E82, 0xAA0A9153, 0x82C48FC1, 0x82A682C4,  /* fzgx-allow: A1 retail data bytes */
    0x82B582DC, 0x82A282DC, 0x82B782AA, 0x814182E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x3F000000  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_lbl_4_data_1064 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_F64__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_FD8__fzgx_offset_0
}};
static union { u32 w[21]; char v[0x54]; } fzgx_pool_init_lbl_4_data_107C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x54686572, 0x65206973, 0x206E6F20, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x6C6F7420  /* fzgx-allow: A1 retail data bytes */,
    0x412E0000, 0x8358838D, 0x83628367, 0x826082C9, 0xA838183, 0x82838A81, 0x5B834A81, 0x5B836882  /* fzgx-allow: A1 retail data bytes */,
    0xAA8CA982, 0xC282A982, 0xE882DC82, 0xB982F181, 0x42000000  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_lbl_4_data_10D0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_107C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_10A0__fzgx_offset_0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[27]; char v[0x6C]; } fzgx_pool_init_lbl_4_data_10E8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x52656769, 0x73746572, 0x20746869, 0x73206E61, 0x6D65206F, 0x6E207468, 0x65204D65, 0x6D6F7279  /* fzgx-allow: A1 retail data bytes */,
    0x20436172, 0x6420696E, 0x20536C6F, 0x7420412E, 0x0, 0x82B182CC, 0x96BC914F, 0x82C58381  /* fzgx-allow: A1 retail data bytes */,
    0x8382838A, 0x815B834A, 0x815B8368, 0x82C90A93, 0x6F985E82, 0xB582C482, 0xE082E682, 0xEB82B582  /* fzgx-allow: A1 retail data bytes */,
    0xA282C582, 0xB782A93F, 0x0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_lbl_4_data_1154 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_10E8__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_111C__fzgx_offset_0
}};
static union { u32 w[34]; char v[0x88]; } fzgx_pool_init_lbl_4_data_116C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x54686572, 0x65206973, 0x206E6F20, 0x4D656D6F, 0x72792043, 0x61726420, 0x696E2053, 0x6C6F7420,
    0x412E0A20, 0x54686520, 0x67616D65, 0x2063616E, 0x6E6F7420, 0x62652073, 0x61766564, 0x2E000000,
    0x8358838D, 0x83628367, 0x826082C9, 0x83818382, 0x838A815B, 0x834A815B, 0x836882AA, 0x8CA982C2,
    0x82A982E8, 0x82DC82B9, 0x82F18142, 0xA835A81, 0x5B837582, 0xC582AB82, 0xDC82B982, 0xF182C582,
    0xB582BD81, 0x42000000
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_lbl_4_data_11F4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_4_data_116C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_C__fzgx_offset_0, (u32)lbl_4_data_11AC__fzgx_offset_0
}};
static union { u32 w[1]; char v[4]; } fzgx_pool_init_lbl_4_data_120C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFF00FFFF
}};
static union { u32 w[1]; char v[4]; } fzgx_pool_init_lbl_4_data_1210 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x257300FF
}};

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u16 fzgx_obj_lbl_4_bss_0;
u8 fzgx_obj_lbl_4_bss_2;
u8 fzgx_pool_lbl_4_bss_0_gap_3;
u32 fzgx_obj_lbl_4_bss_4;
u32 fzgx_obj_lbl_4_bss_8;
u8 lbl_4_bss_C;
u8 lbl_4_bss_D;
u8 fzgx_pool_lbl_4_bss_0_gap_E;
u8 fzgx_pool_lbl_4_bss_0_gap_E_fill_F;
u16 fzgx_obj_lbl_4_bss_10;
/* volatile */
volatile u8 lbl_4_bss_10__fzgx_offset_2;
u8 lbl_4_bss_10__fzgx_offset_3;
CalPair lbl_4_bss_10__fzgx_offset_4;
CalPair lbl_4_bss_10__fzgx_offset_8;
CalPair lbl_4_bss_10__fzgx_offset_C;
CalPair lbl_4_bss_10__fzgx_offset_10[8];
u8 lbl_4_bss_10__fzgx_offset_20[16];
u8 lbl_4_bss_10__fzgx_offset_30[16];
u8 lbl_4_bss_10__fzgx_offset_40[8];
u8 lbl_4_bss_10__fzgx_offset_48;
u8 lbl_4_bss_10__fzgx_offset_49;
u8 lbl_4_bss_10__fzgx_offset_4A;
u8 lbl_4_bss_10__fzgx_offset_4B;
u8 lbl_4_bss_10__fzgx_offset_4C;
u8 lbl_4_bss_10__fzgx_offset_4D;
CalPair lbl_4_bss_10__fzgx_offset_50[4][8];
CalPair lbl_4_bss_10__fzgx_offset_90[4];
CalPair lbl_4_bss_10__fzgx_offset_98[4];
CalPair lbl_4_bss_10__fzgx_offset_A0[4];
u16 lbl_4_bss_10__fzgx_offset_A8;
u16 lbl_4_bss_10__fzgx_offset_AA;
u32 lbl_4_bss_10__fzgx_offset_AC[2];
u8 fzgx_obj_lbl_4_bss_C4[0x1C1];
u8 lbl_4_bss_C4__fzgx_offset_1C1;
u8 lbl_4_bss_C4__fzgx_offset_1C2;
s32 lbl_4_bss_C4__fzgx_offset_1C4;
s32 lbl_4_bss_C4__fzgx_offset_1C8;
u8 lbl_4_bss_C4__fzgx_offset_1CC;
u8 lbl_4_bss_C4__fzgx_offset_1CD;
u16 lbl_4_bss_C4__fzgx_offset_1CE;
u8 lbl_4_bss_C4__fzgx_offset_1D0;
u8 lbl_4_bss_C4__fzgx_offset_1D1;
u16 lbl_4_bss_C4__fzgx_offset_1D2;
u32 lbl_4_bss_C4__fzgx_offset_1D4[8];
u32 lbl_4_bss_C4__fzgx_offset_1F4[0x14D8];
u8 lbl_4_bss_5618;
u8 lbl_4_bss_5618__fzgx_offset_1;
u8 lbl_4_bss_5618__fzgx_offset_2;
u8 lbl_4_bss_5618__fzgx_offset_3;
u32 lbl_4_bss_5618__fzgx_offset_4;
u8 lbl_4_bss_5618__fzgx_offset_8;
u8 lbl_4_bss_5618__fzgx_offset_9;
u8 lbl_4_bss_5618__fzgx_offset_A;
u8 lbl_4_bss_5618__fzgx_offset_B;
u32 lbl_4_bss_5618__fzgx_offset_C;

#pragma section code_type ".fzgxpool"

#pragma section code_type ".fzgxpool"
static void fzgx_base_order_data(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: the TU references .data in retail order */
    s = *(u8 *)&fzgx_pool_init_fzgx_obj_lbl_4_data_0.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_584.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_59C.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_5A8.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_5C0.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_F4C.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_F64.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_1064.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_107C.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_10D0.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_10E8.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_1154.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_116C.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_11F4.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_120C.v;
    s = *(u8 *)&fzgx_pool_init_lbl_4_data_1210.v;
}
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_4_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_2;
    s = *(u8 *)&fzgx_pool_lbl_4_bss_0_gap_3;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_4;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_8;
    s = *(u8 *)&lbl_4_bss_C;
    s = *(u8 *)&lbl_4_bss_D;
    s = *(u8 *)&fzgx_pool_lbl_4_bss_0_gap_E;
    s = *(u8 *)&fzgx_pool_lbl_4_bss_0_gap_E_fill_F;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_10;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_2;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_3;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_4;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_8;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_C;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_10;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_20;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_30;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_40;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_48;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_49;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_4A;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_4B;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_4C;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_4D;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_50;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_90;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_98;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_A0;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_A8;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_AA;
    s = *(u8 *)&lbl_4_bss_10__fzgx_offset_AC;
    s = *(u8 *)&fzgx_obj_lbl_4_bss_C4;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1C1;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1C2;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1C4;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1C8;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1CC;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1CD;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1CE;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1D0;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1D1;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1D2;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1D4;
    s = *(u8 *)&lbl_4_bss_C4__fzgx_offset_1F4;
    s = *(u8 *)&lbl_4_bss_5618;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_1;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_2;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_3;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_4;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_8;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_9;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_A;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_B;
    s = *(u8 *)&lbl_4_bss_5618__fzgx_offset_C;
}
#pragma section code_type ".text"

#pragma section code_type ".text"

#define RODATA p_lbl_4_rodata_0

typedef struct { u16 button; s8 stickX; s8 stickY; u8 rest[8]; } CalPad;
typedef struct { u8 pad_0[8]; u16 unk_8; } CalD58;
typedef struct { u8 pad_0[0xD4]; CalPair d4; u8 p_d6[2]; CalPair d8; u8 p_da[2]; CalPair dc; u8 p_de[2]; struct { CalPair v; u8 p[2]; } oct[8]; } CalRodata;
#define CALRO ro
extern CalPair lbl_1_data_2AC0[4][8];
extern CalPair lbl_1_data_2B40[4];
extern CalPair lbl_1_data_2B50[4];
extern CalPair lbl_1_data_2B58[4];
extern u32 lbl_1_bss_980[4];
extern CalPad lbl_1_bss_9C8[4];
extern CalD58 lbl_1_bss_D58;
extern u8 fn_1_3BB0(u8);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_4_EF8(u8);

typedef struct { u16 trig; u8 p_2[6]; u16 rep; u16 unk_A; u8 p_c[8]; } CalPadEnt;
typedef struct { u8 hdr[8]; CalPadEnt e[4]; } CalPads;
extern CalPads lbl_1_bss_9F8;
#define CAL_PADS (lbl_1_bss_9F8.e)

static inline void fn_4_3568_kind(s32 port) {
    switch (fn_1_3BB0(port)) {
    default:
    case 1:
        lbl_4_bss_10__fzgx_offset_2 = 0;
        break;
    case 2:
    case 3:
    case 4:
        lbl_4_bss_10__fzgx_offset_2 = 1;
        break;
    }
}

static inline void fn_4_3568_setup(const CalRodata *ro, s32 port) {
    fn_4_3568_kind(port);
    switch (lbl_4_bss_10__fzgx_offset_2) {
    case 0:
        lbl_4_bss_10__fzgx_offset_10[0] = CALRO->oct[0].v;
        lbl_4_bss_10__fzgx_offset_10[1] = CALRO->oct[1].v;
        lbl_4_bss_10__fzgx_offset_10[2] = CALRO->oct[2].v;
        lbl_4_bss_10__fzgx_offset_10[3] = CALRO->oct[3].v;
        lbl_4_bss_10__fzgx_offset_10[4] = CALRO->oct[4].v;
        lbl_4_bss_10__fzgx_offset_10[5] = CALRO->oct[5].v;
        lbl_4_bss_10__fzgx_offset_10[6] = CALRO->oct[6].v;
        lbl_4_bss_10__fzgx_offset_10[7] = CALRO->oct[7].v;
        lbl_4_bss_10__fzgx_offset_4 = lbl_1_data_2B40[port];
        fn_80008BEC(lbl_4_bss_10__fzgx_offset_20, 0, 0x10);
        fn_80008BEC(lbl_4_bss_10__fzgx_offset_30, 0, 0x10);
        break;
    case 1:
        lbl_4_bss_10__fzgx_offset_8 = lbl_1_data_2B50[port];
        lbl_4_bss_10__fzgx_offset_C = lbl_1_data_2B58[port];
        break;
    }
}

static inline void fn_4_3568_defaults(const CalRodata *ro, s32 port) {
    fn_4_3568_kind(port);
    switch (lbl_4_bss_10__fzgx_offset_2) {
    case 0:
        lbl_4_bss_10__fzgx_offset_4 = CALRO->d4;
        break;
    case 1:
        lbl_4_bss_10__fzgx_offset_8 = CALRO->d8;
        lbl_4_bss_10__fzgx_offset_C = CALRO->dc;
        break;
    }
}

void fn_4_3568(void) {
    const CalRodata *ro;
    u32 i;
    s32 v;
    s32 k;
    u16 b;
    u32 type;
    s32 port;
    ro = (const CalRodata *)&lbl_4_rodata_0;

    if (fzgx_obj_lbl_4_bss_10 != 0) {
        if (fn_1_4C10() == 0) {
            fn_1_1280(1);
            lbl_1_bss_96A = fzgx_obj_lbl_4_bss_10;
            fzgx_obj_lbl_4_bss_10 = 0;
        }
        return;
    }
    if (lbl_4_bss_10__fzgx_offset_4A != 0 && lbl_4_bss_10__fzgx_offset_4A != 1 && lbl_4_bss_10__fzgx_offset_4A != 4) {
        if (lbl_1_bss_980[lbl_4_bss_10__fzgx_offset_4D] & 0x48) {
            lbl_4_bss_10__fzgx_offset_4A = 4;
        }
    }
    switch (lbl_4_bss_10__fzgx_offset_4A) {
    case 0:
        if ((CAL_PADS[0].trig >> 9) & 1) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_10__fzgx_offset_4C = 0;
            lbl_4_bss_10__fzgx_offset_4A = 1;
            return;
        }
        for (i = 0; i < 4; i++) {
            if ((CAL_PADS[i].trig >> 8) & 1) {
                fn_1_A2D84(0xA9010100);
                lbl_4_bss_10__fzgx_offset_4D = i;
                lbl_4_bss_10__fzgx_offset_4A = 2;
                fn_4_3568_setup(ro, lbl_4_bss_10__fzgx_offset_4D);
                return;
            }
        }
        break;
    case 1:
        if (lbl_4_bss_10__fzgx_offset_4B == 0) {
            fzgx_obj_lbl_4_bss_10 = 0x4D;
            fn_1_4A00(0, 15, fzgx_obj_lbl_4_bss_8);
            return;
        }
        lbl_4_bss_10__fzgx_offset_4C = fn_4_0(lbl_4_bss_10__fzgx_offset_4C, 0, 1, -1, 1);
        if ((CAL_PADS[0].trig >> 9) & 1) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_10__fzgx_offset_4A = 0;
            return;
        }
        if (!((CAL_PADS[0].trig >> 8) & 1)) {
            return;
        }
        fn_1_A2D84(0xA9010100);
        switch (lbl_4_bss_10__fzgx_offset_4C) {
        case 0:
            fzgx_pool_lbl_4_bss_0_gap_E = 1;
            fn_80008BA8(lbl_1_bss_718E0 + 0x8, lbl_1_data_2AC0, 0x40);
            fn_80008BA8(lbl_1_bss_718E0 + 0x48, lbl_1_data_2B40, 8);
            fn_80008BA8(lbl_1_bss_718E0 + 0x5542, lbl_1_data_2B50, 8);
            fn_80008BA8(lbl_1_bss_718E0 + 0x554A, lbl_1_data_2B58, 8);
            break;
        case 1:
            fn_80008BA8(lbl_1_data_2AC0, lbl_4_bss_10__fzgx_offset_50, 0x40);
            fn_80008BA8(lbl_1_data_2B40, lbl_4_bss_10__fzgx_offset_90, 8);
            fn_80008BA8(lbl_1_data_2B50, lbl_4_bss_10__fzgx_offset_98, 8);
            fn_80008BA8(lbl_1_data_2B58, lbl_4_bss_10__fzgx_offset_A0, 8);
            break;
        }
        if (fzgx_pool_lbl_4_bss_0_gap_E != 0) {
            lbl_4_bss_10__fzgx_offset_A8 = 0x4D;
            fzgx_obj_lbl_4_bss_10 = 0x4C;
        } else {
            fzgx_obj_lbl_4_bss_10 = 0x4D;
            fn_1_4A00(0, 15, fzgx_obj_lbl_4_bss_8);
        }
        break;
    case 2:
        port = lbl_4_bss_10__fzgx_offset_4D;
        switch (lbl_4_bss_10__fzgx_offset_2) {
        case 0:
            fn_4_EF8(port);
            break;
        case 1:
            v = lbl_1_bss_9C8[port].stickX;
            if ((CAL_PADS[port].trig >> 8) & 1) {
                if (__abs(v) <= 20) {
                    fn_1_A2D84(0xA9010200);
                } else {
                    fn_1_A2D84(0xA9010100);
                    if (v < 0) {
                        lbl_4_bss_10__fzgx_offset_8.y = -v;
                    } else {
                        lbl_4_bss_10__fzgx_offset_8.x = v;
                    }
                }
            }
            k = lbl_4_bss_10__fzgx_offset_C.x;
            if (((CAL_PADS[port].unk_A >> 9) & 1) && k < 20) {
                k++;
                fn_1_A2D84(0xA9010300);
            } else if (((CAL_PADS[port].unk_A >> 8) & 1) && k > 0) {
                k--;
                fn_1_A2D84(0xA9010300);
            }
            lbl_4_bss_10__fzgx_offset_C.x = k;
            lbl_4_bss_10__fzgx_offset_C.y = k;
            break;
        }
        if ((CAL_PADS[lbl_4_bss_10__fzgx_offset_4D].trig >> 10) & 1) {
            fn_1_A2D84(0xA9010100);
            lbl_4_bss_10__fzgx_offset_4C = 1;
            lbl_4_bss_10__fzgx_offset_4A = 5;
            return;
        }
        if (lbl_4_bss_10__fzgx_offset_2 == 0 && ((CAL_PADS[lbl_4_bss_10__fzgx_offset_4D].trig >> 8) & 1)) {
            fn_1_A2D84(0xA9010100);
            lbl_4_bss_10__fzgx_offset_4C = 0;
            lbl_4_bss_10__fzgx_offset_4A = 3;
        } else if (lbl_4_bss_10__fzgx_offset_2 == 1 && ((CAL_PADS[lbl_4_bss_10__fzgx_offset_4D].trig >> 9) & 1)) {
            fn_1_A2D84(0xA9010100);
            if (lbl_4_bss_10__fzgx_offset_8.x == lbl_1_data_2B50[lbl_4_bss_10__fzgx_offset_4D].x
             && lbl_4_bss_10__fzgx_offset_8.y == lbl_1_data_2B50[lbl_4_bss_10__fzgx_offset_4D].y
             && lbl_4_bss_10__fzgx_offset_C.x == lbl_1_data_2B58[lbl_4_bss_10__fzgx_offset_4D].x
             && lbl_4_bss_10__fzgx_offset_C.y == lbl_1_data_2B58[lbl_4_bss_10__fzgx_offset_4D].y) {
                lbl_4_bss_10__fzgx_offset_4A = 0;
            } else {
                lbl_4_bss_10__fzgx_offset_4C = 0;
                lbl_4_bss_10__fzgx_offset_4A = 3;
            }
        } else if (lbl_4_bss_10__fzgx_offset_2 == 0 && ((CAL_PADS[lbl_4_bss_10__fzgx_offset_4D].trig >> 9) & 1)) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_10__fzgx_offset_4A = 0;
        }
        lbl_4_bss_10__fzgx_offset_48 = lbl_1_bss_9C8[lbl_4_bss_10__fzgx_offset_4D].stickX;
        lbl_4_bss_10__fzgx_offset_49 = lbl_1_bss_9C8[lbl_4_bss_10__fzgx_offset_4D].stickY;
        break;
    case 3:
        lbl_4_bss_10__fzgx_offset_4C = fn_4_0(lbl_4_bss_10__fzgx_offset_4C, 0, 1, lbl_4_bss_10__fzgx_offset_4D, 1);
        if ((CAL_PADS[lbl_4_bss_10__fzgx_offset_4D].trig >> 9) & 1) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_10__fzgx_offset_4A = 2;
            return;
        }
        if (!((CAL_PADS[lbl_4_bss_10__fzgx_offset_4D].trig >> 8) & 1)) {
            return;
        }
        fn_1_A2D84(0xA9010100);
        if (lbl_4_bss_10__fzgx_offset_4C == 0) {
            port = lbl_4_bss_10__fzgx_offset_4D;
            switch (lbl_4_bss_10__fzgx_offset_2) {
            case 0:
                fn_80008BA8(lbl_1_data_2AC0[port], lbl_4_bss_10__fzgx_offset_10, 0x10);
                lbl_1_data_2B40[port] = lbl_4_bss_10__fzgx_offset_4;
                break;
            case 1:
                lbl_1_data_2B50[port] = lbl_4_bss_10__fzgx_offset_8;
                lbl_1_data_2B58[port] = lbl_4_bss_10__fzgx_offset_C;
                break;
            }
            lbl_4_bss_10__fzgx_offset_4B = 1;
        }
        lbl_4_bss_10__fzgx_offset_4A = 0;
        break;
    case 4:
        type = lbl_1_bss_980[lbl_4_bss_10__fzgx_offset_4D];
        if (type & 0x48) {
            if ((lbl_1_bss_D58.unk_8 >> 8) & 1) {
                fn_1_A2D84(0xA9010100);
                lbl_4_bss_10__fzgx_offset_4A = 0;
            }
            return;
        }
        if (type == 0x09000000 || type == 0x88000000 || type == 0x8B100000 || type == 0x08000000) {
            fn_1_A2D84(0xA9010100);
            lbl_4_bss_10__fzgx_offset_4A = 2;
            fn_4_3568_setup(ro, lbl_4_bss_10__fzgx_offset_4D);
        }
        break;
    case 5:
        lbl_4_bss_10__fzgx_offset_4C = fn_4_0(lbl_4_bss_10__fzgx_offset_4C, 0, 1, lbl_4_bss_10__fzgx_offset_4D, 1);
        if ((CAL_PADS[lbl_4_bss_10__fzgx_offset_4D].trig >> 9) & 1) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_10__fzgx_offset_4A = 2;
            return;
        }
        if (!((CAL_PADS[lbl_4_bss_10__fzgx_offset_4D].trig >> 8) & 1)) {
            return;
        }
        fn_1_A2D84(0xA9010100);
        if (lbl_4_bss_10__fzgx_offset_4C == 0) {
            fn_4_3568_setup(ro, lbl_4_bss_10__fzgx_offset_4D);
            fn_4_3568_defaults(ro, lbl_4_bss_10__fzgx_offset_4D);
        }
        lbl_4_bss_10__fzgx_offset_4A = 2;
        break;
    }
}
