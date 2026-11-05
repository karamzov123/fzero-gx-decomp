/* Non-matching: best partial attempt (98.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/toolkit.h"


extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, int);
extern const f32 lbl_3_rodata_740;
extern void fn_3_1ABD8(void *arg0, s16 x1, s16 y1, s16 x2, s16 y2, u32 *value);
extern void fn_3_1B130(void *, s16, s16, u32 *);
extern void fn_3_149AC(void);
extern void fn_3_1BA20(void *target, s16 x, s16 y, s16 z, s16 w, s32 *value);
extern void fn_3_1BF08(void *, s16, s16, s16, s16, u32 *);
extern u8 lbl_3_bss_A2458[8];
extern void fn_3_BD98(void);
extern void fn_3_BEF0(void);
extern void fn_3_BE88(void);
extern void fn_3_156A8(void);
extern void fn_80074188(s16, s16, s16, s16);
extern void fn_1_5233C(void *, void *);
extern struct fn_3_1A1D8_lbl_1_bss_9F8 lbl_1_bss_9F8;

#include "font.h"

extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, int);
extern const f32 lbl_3_rodata_740;
extern void fn_3_1ABD8(void *arg0, s16 x1, s16 y1, s16 x2, s16 y2, u32 *value);
extern void fn_3_1B130(void *, s16, s16, u32 *);
extern void fn_3_149AC(void);
extern void fn_3_1BA20(void *target, s16 x, s16 y, s16 z, s16 w, s32 *value);
extern void fn_3_1BF08(void *, s16, s16, s16, s16, u32 *);
extern u8 lbl_3_bss_A2458[8];
extern void fn_3_BD98(void);
extern void fn_3_BEF0(void);
extern void fn_3_BE88(void);
extern void fn_3_156A8(void);
extern void fn_80074188(s16, s16, s16, s16);
extern void fn_1_5233C(void *, void *);
extern struct fn_3_1A1D8_lbl_1_bss_9F8 lbl_1_bss_9F8;


struct fn_3_225F8_Copy88 { u32 a[22]; };
struct fn_3_225F8_lbl_3_rodata_768 {
    u8 pad_0[0x28]; f32 unk_28;
    u8 pad_2C[0x20]; f32 unk_4C;
    u8 pad_50[0x24]; f32 unk_74; f32 unk_78;
    u8 pad_7C[0x10]; f32 unk_8C;
    u8 pad_90[0x8]; f64 unk_98;
    u8 pad_A0[0xD0]; f32 unk_170;
    u8 pad_174[0x14]; f32 unk_188; f32 unk_18C;
    u8 pad_190[0x8]; f32 unk_198;
    u8 pad_19C[0x10]; f32 unk_1AC; f32 unk_1B0; f32 unk_1B4;
    f32 unk_1B8; f32 unk_1BC;
    u8 pad_1C0[0x38]; f64 unk_1F8;
    u8 pad_200[0x28]; f32 unk_228; f32 unk_22C;
    u8 pad_230[0x11C]; f32 unk_34C;
    u8 pad_350[0x4]; f32 unk_354; f32 unk_358;
    u8 pad_35C[0x4]; f32 unk_360; f32 unk_364; f32 unk_368;
    f32 unk_36C; f32 unk_370; f32 unk_374; f32 unk_378; f32 unk_37C;
    u32 unk_380; u32 unk_384; u32 unk_388; u32 unk_38C;
    f32 unk_390; f32 unk_394; f32 unk_398;
};
extern f32 lbl_3_rodata_768[38];
extern f32 lbl_8006D188(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern u16 fn_1_A5DB0(void);
extern u32 fn_3_2B750(s16, s16);
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A66A8;
extern void fn_1_49410(void);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_4965C(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);
extern void fn_3_7A08(s16 *, s16 *, int);
extern s32 fn_1_F965C(s16);
extern s32 fn_1_F9028(s16);
extern void fn_1_495C8(u8);
extern void fn_1_49738(void *);
extern u32 fn_1_F8DC4(s16, s16, void *);
extern void fn_1_50164(f32, f32, f32, f32, void *);
extern char *fn_1_F8E30(s16, s16, char *);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_3_2406C(void);
extern void fn_3_240DC(void *, void *);

#define PF(off) (*(f32 *)((u8 *)&loc_54 + (off)))
#define PB(off) (*((u8 *)&loc_54 + (off)))
#define PP(off) (*(void **)((u8 *)&loc_54 + (off)))
#define RESET_PACKET() (loc_54 = *(struct fn_3_225F8_Copy88 *)&lbl_1_rodata_26F8)
#define R p_lbl_3_rodata_768
const u32 fzgx_pool_fn_3_225F8_pad0[10] = { 0x3F333333, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0x0000FF00, 0xFFF200FF, 0xFFFF0000, 0x3EEAAAAB, 0x438E0000, 0x43A48000 };
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime28(void) { return 100.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_fn_3_225F8_pad2C[8] = { 0x3F6AAAAB, 0x43B40000, 0x3F0AAAAB, 0x43DC8000, 0x43A60000, 0x43AC8000, 0x43B30000, 0x3EF99999 };
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime4C(void) { return 395.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_fn_3_225F8_pad50[9] = { 0x43A58000, 0x43B38000, 0x43A00000, 0x43B50000, 0x43480000, 0x43A18000, 0x43BE8000, 0x41500000, 0x3C008081 };
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime74(void) { return 6.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime78(void) { return 7.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_fn_3_225F8_pad7C[4] = { 0x3E189899, 0x3E048485, 0x43040000, 0x43160000 };
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime8C(void) { return 0.8f; }
#pragma section code_type ".text"
const u32 fzgx_pool_fn_3_225F8_pad90[2] = { 0x3E99999A, 0x00000000 };
#pragma section code_type ".fzgxpool"
f64 fzgx_fn_3_225F8_prime98(void) { return 4503601774854144.0; }
#pragma section code_type ".text"
const u32 fzgx_pool_fn_3_225F8_padA0[52] = { 0x00004A00, 0x00005400, 0x00003800, 0x00003E00, 0x00003700, 0x00005500, 0x00003000, 0x00003500, 0x00003A00, 0x00004000, 0x00004400, 0x00005000, 0x00003300, 0x00002E00, 0x00003100, 0x00004F00, 0x00003900, 0x00003D00, 0x00004C00, 0x00003F00, 0x00004800, 0x00005200, 0x00004500, 0x00005300, 0x00003C00, 0x00005600, 0x00004300, 0x00004200, 0x00003200, 0x00002F00, 0x00003400, 0x00003600, 0x00004D00, 0x00004600, 0x00004100, 0x00005100, 0x00004E00, 0x00004700, 0x00003B00, 0x00004B00, 0x00004900, 0xFFF200FF, 0xFFFF0000, 0x43BE0000, 0x43A70000, 0x3ED00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime170(void) { return 480.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_fn_3_225F8_pad174[5] = { 0x44200000, 0x42780000, 0x3FABABAC, 0x41000000, 0x3E000000 };
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime188(void) { return 1.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime18C(void) { return 0.5f; }
#pragma section code_type ".text"
const u32 fzgx_pool_fn_3_225F8_pad190[2] = { 0x43570000, 0x40400000 };
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime198(void) { return 180.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_fn_3_225F8_pad19C[4] = { 0x42B40000, 0x43700000, 0x42300000, 0x42B3CCCD };
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime1AC(void) { return 40.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime1B0(void) { return 16384.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime1B4(void) { return 65536.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime1B8(void) { return 60.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime1BC(void) { return 80.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_fn_3_225F8_pad1C0[14] = { 0x43E60000, 0x3F2AAAAB, 0x3F1B9B9C, 0xC0400000, 0x00000000, 0x3F1E9E9F, 0x3F018182, 0x43580000, 0x3E4CCCCD, 0x430C0000, 0x437A0000, 0x43C80000, 0x44098000, 0x3EEEEEEF };  /* fzgx-allow: A1 retail pool bytes */
#pragma section code_type ".fzgxpool"
f64 fzgx_fn_3_225F8_prime1F8(void) { return 4503599627370496.0; }
#pragma section code_type ".text"
const u32 fzgx_pool_fn_3_225F8_pad200[10] = { 0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBF000000 };  /* fzgx-allow: A1 retail pool bytes */
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime228(void) { return 182.04444885253906f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_225F8_prime22C(void) { return 10.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_fn_3_225F8_pad230[62] = { 0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0x40700000, 0x40600000, 0x3D4CCCCD, 0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0x3E800000, 0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0x40612121, 0x410CB4B5, 0x4128D8D9, 0x439D8000, 0x40000000, 0x3FA66666, 0x3F19999A, 0x3F20A0A1, 0x3F40C0C1, 0x40666666, 0x41100000, 0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003, 0x00020001, 0x00000001, 0x00020003, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x00000000, 0x00000000, 0x40A6C6C7, 0x00000000, 0x00000000, 0xBE58D8D9, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };  /* fzgx-allow: A1 retail pool bytes */
#pragma section code_type ".text"
const u32 lbl_3_rodata_990__fzgx_offset_100[1] = { 0x00FFFF00 };
const u32 lbl_3_rodata_990__fzgx_offset_104[1] = { 0x00FFFF00 };
const u32 lbl_3_rodata_990__fzgx_offset_108[1] = { 0x00FF0000 };
const u32 lbl_3_rodata_990__fzgx_offset_10C[1] = { 0x00FF0000 };
const u32 lbl_3_rodata_990__fzgx_offset_110[1] = { 0x00FF0000 };
const u32 lbl_3_rodata_990__fzgx_offset_114[1] = { 0x00FF0000 };
const u32 lbl_3_rodata_990__fzgx_offset_118[1] = { 0xFFFF0000 };
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_21300_prime344(void) { return 266.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_21300_prime348(void) { return 120.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_21300_prime34C(void) { return 547.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_21300_prime350(void) { return 173.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_21300_prime354(void) { return 23.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_21300_prime358(void) { return 223.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_21300_prime35C(void) { return 257.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_21300_prime360(void) { return 20.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_21300_prime364(void) { return 12.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_21300_prime368(void) { return 67.75f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_21300_prime36C(void) { return 2.5f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_21300_prime370(void) { return 0.35f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_21300_prime374(void) { return 0.15f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_21300_prime378(void) { return 11.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_fn_3_21300_prime37C(void) { return 16.0f; }
#pragma section code_type ".text"
#pragma opt_common_subs off
u32 fn_3_21300(s32 arg0, s32 arg1, s32 arg2) {
    s32 weight;
    Obj_3_bss_F0 *p_lbl_3_bss_F0;
    u8 *p_lbl_3_data_3D50;
    struct fn_3_225F8_lbl_3_rodata_768 *p_lbl_3_rodata_768;
    u8 *p_lbl_3_bss_7E6F0;
    f32 v1;
    f32 v2;
    f32 v3;
    f32 v4;
    f32 v5;
    s32 v6;
    f64 v7;
    u32 v8;
    f32 v9;
    f32 v10;
    f32 v11;
    u32 v12;
    u32 v13;
    s16 v14;
    f64 v15;
    f32 v16;
    f32 v17;
    f32 v18;
    f32 v19;
    f32 v20;
    f32 v21;
    f32 v22;
    f32 v23;
    u32 v24;
    u32 v25;
    s16 v26;
    f64 v27;
    f32 v28;
    f32 v29;
    f32 v30;
    f32 v31;
    f32 v32;
    f32 v33;
    f32 v34;
    f32 v35;
    f64 v36;
    f32 v37;
    f32 v38;
    f32 v39;
    s16 v40;
    s16 v41;
    s32 v42;
    struct { s32 value; } v43;
    f64 v44;
    f32 v45;
    s32 v46;
    f64 v47;
    s32 v48;
    s32 v49;
    s32 v50;
    s32 v51;
    s32 v52;
    s32 v53;
    s32 v54;
    struct { s32 value; } v55;
    s16 kind;
    s16 v0;
    u32 v56;
    u32 v57;
    u32 v58;
    u32 v59;
    u32 v60;
    u32 v61;
    struct fn_3_225F8_Copy88 loc_54;
    char loc_20[64];
    u32 loc_1C;
    u32 loc_18;
    u32 loc_14;
    u32 loc_10;
    u32 loc_C;
    s16 loc_A;
    s16 loc_8;
    u16 t0;
    f32 t3;
    f32 t5;
    u32 t15;
    u32 t25;
    s16 id;
    s16 category;
    s16 count;
    s16 available;
    s16 owned;
    f32 textY;
    s16 number;
    s16 digit;
    s16 digit2;
    s32 xHighlight;
    s32 xAvailable;
    s32 xOwned;
    s32 xTens;
    s32 xOnes;
    u32 lab_t1;

    p_lbl_3_bss_F0 = &lbl_3_bss_F0;
    v0 = p_lbl_3_bss_F0->unk_A;
    p_lbl_3_rodata_768 = (struct fn_3_225F8_lbl_3_rodata_768 *)&lbl_3_rodata_768;
    p_lbl_3_data_3D50 = (u8 *)&lbl_3_data_3D50;
    t0 = fn_1_A5DB0();
    v1 = (f32)(u32)(t0 & 0xFFFF);
    v2 = 480.0f;
    v3 = 120.0f;
    v4 = 266.0f;
    v5 = (f32)(v1 / v2);
    lbl_3_bss_A2460.unk_0 = 30;
    lbl_3_bss_A2460.unk_4 = 640;
    lbl_3_bss_A2460.unk_2 = v4 * v5;
    lbl_3_bss_A2460.unk_6 = v3 * v5;
    fn_3_7A08(&loc_A, &loc_8, 6);
    RESET_PACKET();
    v7 = 4503601774854144.0;
    v8 = (0x10000 - 23775);
    v9 = 7.0f;
    v11 = (f32)(s32)(s16)arg1;
    v10 = (f32)(s32)(s16)arg0;
    loc_54.a[0] = v8;
    PF(4) = v10;
    PF(8) = v11;
    PF(12) = (f32)(s32)(s16)arg2;
    loc_54.a[12] = 10;
    fn_1_50190(&loc_54, 547.0f, 173.0f, v9, v9, 23.0f, v9);
    if (loc_A > 0) {
        RESET_PACKET();
        v13 = (0x10000 - 23785);
        loc_54.a[0] = v13;
        PF(4) = 223.0f;
        PF(8) = 257.0f;
        PF(12) = 10.0f;
        loc_54.a[12] = 10;
        loc_54.a[14] = lbl_3_rodata_990__fzgx_offset_100[0];
        v12 = lbl_3_bss_F0.unk_24;
        if ((v12 & ~0x7FFFFFFF) != 0 && (v12 & 0x8000000) != 0) {
            v14 = lbl_3_bss_F0.unk_2C;
            if ((s16)v14 < 0) {
                v15 = 4503601774854144.0;
                v16 = 180.0f;
                v17 = (f32)(s32)lbl_3_bss_F0.unk_2A;
                v18 = 182.04444885253906f;
                t3 = lbl_8006D188((s32)(f32)(v18 * (f32)(v16 * (f32)(v17 / (f32)(s32)v14))));
                v19 = 1.0f;
                v22 = PF(16) * (v21 = (f32)(v19 + (f32)(0.5f * t3)));
                v23 = (f32)(PF(20) * v21);
                PF(44) = (f32)(v19 - (f32)(0.5f * t3));
                PF(16) = v22;
                PF(20) = v23;
            }
        }
        fn_1_4F734((FontDrawPacket *)&loc_54);
    }
    if (loc_8 < (s32)(lbl_3_bss_7EBA0 - 1)) {
        RESET_PACKET();
        v25 = (0x10000 - 23785);
        loc_54.a[0] = v25;
        PF(4) = 223.0f;
        PF(8) = 395.0f;
        PF(12) = 10.0f;
        loc_54.a[12] = (0x100000 + 10);
        loc_54.a[14] = lbl_3_rodata_990__fzgx_offset_104[0];
        v24 = lbl_3_bss_F0.unk_24;
        if ((v24 & ~0x7FFFFFFF) != 0 && (v24 & 0x8000000) != 0) {
            v26 = lbl_3_bss_F0.unk_2C;
            if ((s16)v26 > 0) {
                v27 = 4503601774854144.0;
                v28 = 180.0f;
                v29 = (f32)(s32)lbl_3_bss_F0.unk_2A;
                v30 = 182.04444885253906f;
                t5 = lbl_8006D188((s32)(f32)(v30 * (f32)(v28 * (f32)(v29 / (f32)(s32)v26))));
                v31 = 1.0f;
                v34 = PF(16) * (v33 = (f32)(v31 + (f32)(0.5f * t5)));
                v35 = (f32)(PF(20) * v33);
                PF(44) = (f32)(v31 - (f32)(0.5f * t5));
                PF(16) = v34;
                PF(20) = v35;
            }
        }
        fn_1_4F734((FontDrawPacket *)&loc_54);
    }
    v36 = 4503601774854144.0;
    v37 = 20.0f;
    v38 = (f32)(v37 * (f32)(s32)*(s16 *)((u8 *)&lbl_3_bss_20 + 0xC4));
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    v39 = 0.5f;
    fn_1_4955C(v39, v39);
    v40 = (s16)arg0;
    v41 = (s16)arg1;
    v42 = (v40 - 137);
    v43.value = (v41 - 82);
    v44 = 4503601774854144.0;
    fn_1_496FC((f32)(s32)v42, (f32)(s32)v43.value);
    fn_1_4954C(10.0f);
    fn_1_49748(1.0f);
    loc_1C = lbl_3_rodata_990__fzgx_offset_108[0];
    fn_1_49514(&loc_1C);
    t15 = fn_3_2B750(22, v0);
    fn_1_4AE0C((const char *)t15);
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    v45 = 0.5f;
    fn_1_4955C(v45, v45);
    v42 = (v40 + 41);
    v46 = v42;
    v47 = 4503601774854144.0;
    fn_1_496FC((f32)(s32)v46, (f32)(s32)v43.value);
    fn_1_4954C(10.0f);
    fn_1_49748(1.0f);
    loc_18 = lbl_3_rodata_990__fzgx_offset_10C[0];
    fn_1_49514(&loc_18);
    t25 = fn_3_2B750(32, v0);
    fn_1_4AE0C((const char *)t25);
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_4955C(0.5f, 0.5f);
    switch (p_lbl_3_bss_F0->unk_A) {
    case 5:
    default:
        fn_1_496FC((f32)(s32)(v40 + 98), (f32)(s32)v43.value);
        break;
    case 0:
        fn_1_496FC((f32)(s32)(v40 + 92), (f32)(s32)v43.value);
        break;
    }
    fn_1_4954C(10.0f);
    fn_1_49748(1.0f);
    loc_14 = lbl_3_rodata_990__fzgx_offset_110[0];
    fn_1_49514(&loc_14);
    fn_1_4AE0C((const char *)(p_lbl_3_data_3D50 + 0xe34), fn_3_2B750(33, v0));
    v61 = (u32)&lbl_3_bss_20;
    switch (*(s16 *)((u8 *)&lbl_3_bss_7E6F0 + *(s16 *)((u8 *)v61 + 0xC2) * 16 + 2)) {
    case 0:
        fn_1_4AE0C((const char *)(p_lbl_3_data_3D50 + 0xe38), fn_3_2B750(26, 0));
        break;
    case 1:
        fn_1_4AE0C((const char *)(p_lbl_3_data_3D50 + 0xe38), fn_3_2B750(28, 0));
        break;
    case 2:
        fn_1_4AE0C((const char *)(p_lbl_3_data_3D50 + 0xe38), fn_3_2B750(30, 0));
        break;
    }
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_4955C(0.5f, 0.5f);
    switch (p_lbl_3_bss_F0->unk_A) {
    case 5:
    default:
        fn_1_496FC((f32)(s32)(v40 + 207), (f32)(s32)v43.value);
        break;
    case 0:
        fn_1_496FC((f32)(s32)(v40 + 227), (f32)(s32)v43.value);
        break;
    }
    fn_1_4954C(10.0f);
    fn_1_49748(1.0f);
    loc_10 = lbl_3_rodata_990__fzgx_offset_114[0];
    fn_1_49514(&loc_10);
    fn_1_4AE0C((const char *)fn_3_2B750(34, v0));
    v48 = (v41 - 51);
    p_lbl_3_bss_7E6F0 = (u8 *)&lbl_3_bss_7E6F0;
    xHighlight = v40 - 271;
    v49 = (v41 - 45);
    v50 = (v41 - 40);
    xAvailable = v40 - 269;
    v51 = (v41 - 47);
    v52 = (v41 - 39);
    xOwned = v40 + 233;
    v53 = (v41 - 48);
    v54 = (v40 - 202);
    xTens = v40 + 236;
    xOnes = v40 + 248;
#define xHighlight (v40 - 271)
#define xAvailable (v40 - 269)
#define xOwned (v40 + 233)
#define xTens (v40 + 236)
#define xOnes (v40 + 248)
    v55.value = 0;
    for (; (s16)v55.value < lbl_3_bss_7EBA0; v55.value++) {
        id = *(s16 *)(p_lbl_3_bss_7E6F0 + v55.value * 16);
        category = *(s16 *)(p_lbl_3_bss_7E6F0 + v55.value * 16 + 2);
        weight = (s32)*(f32 *)(p_lbl_3_bss_7E6F0 + v55.value * 16 + 4);
        kind = *(s16 *)(p_lbl_3_bss_7E6F0 + v55.value * 16 + 8);
        count = *(s16 *)(p_lbl_3_bss_7E6F0 + v55.value * 16 + 10);
        available = fn_1_F8158(id);
        owned = fn_1_F809C(id);
        if ((s16)v55.value >= loc_A - 2 && (s16)v55.value <= loc_8 + 2) {
            if ((s16)v55.value == *(s16 *)((u8 *)v61 + 0xC2)) {
                RESET_PACKET();
                loc_54.a[0] = 0xA31E;
                PF(4) = (f32)xHighlight;
                PF(8) = v38 + (f32)((s32)v48 + v55.value * 20);
                PF(12) = 12.0f;
                PF(16) *= 67.75f;
                PF(20) *= 2.5f;
                t3 = lbl_8006D188((s32)(16384.0f + (f32)(65536.0f * (f32)(lbl_801A66A8 % 60)) / 60.0f));
                v56 = lbl_801A66A8 % 60;
                PB(56) = 40.0f + (f32)(40.0f * t3);
                t3 = lbl_8006D188((s32)(16384.0f + (f32)(65536.0f * (f32)v56) / 60.0f));
                v56 = lbl_801A66A8 % 60;
                PB(57) = 80.0f + (f32)(80.0f * t3);
                t3 = lbl_8006D188((s32)(16384.0f + (f32)(65536.0f * (f32)v56) / 60.0f));
                v56 = lbl_801A66A8 % 60;
                PB(58) = 80.0f + (f32)(80.0f * t3);
                PF(44) = 0.35f + (f32)(0.15f * lbl_8006D188((s32)(16384.0f + (f32)(65536.0f * (f32)v56) / 60.0f)));
                fn_1_4F734((FontDrawPacket *)&loc_54);
            }
            if (available) {
                RESET_PACKET();
                loc_54.a[0] = 0xA30B;
                PF(4) = (f32)xAvailable;
                PF(8) = v38 + (f32)((s32)v49 + v55.value * 20);
                PF(12) = 10.0f;
                loc_54.a[12] = 0x04000000;
                PP(80) = fn_3_2406C;
                fn_1_4F734((FontDrawPacket *)&loc_54);
            }
            fn_1_49410();
            fn_1_495B0(0x80000000);
            fn_1_4965C(2);
            fn_1_495C8(9);
            fn_1_4955C(0.5f, 0.5f);
            fn_1_496FC((f32)(s32)v54, textY = v38 + (f32)((s32)v50 + v55.value * 20));
            fn_1_4954C(10.0f);
            fn_1_49738(fn_3_240DC);
            fn_1_49748(1.0f);
            RESET_PACKET();
            switch (category) {
                case 0: loc_54.a[0] = 0xA316; fn_1_4AE0C((const char *)fn_3_2B750(26, v0)); break;
                case 1: loc_54.a[0] = 0xA314; fn_1_4AE0C((const char *)fn_3_2B750(28, v0)); break;
                case 2: loc_54.a[0] = 0xA313; fn_1_4AE0C((const char *)fn_3_2B750(30, v0)); break;
            }
            PF(4) = (f32)(s32)v54;
            PF(8) = textY;
            PF(12) = 11.0f;
            loc_54.a[12] = 0x0400000A;
            PP(80) = fn_3_2406C;
            fn_1_50164(80.0f, 16.0f, 6.0f, 6.0f, &loc_54);
            fn_1_49410();
            fn_1_495B0(0x80000000);
            fn_1_4965C(2);
            fn_1_4955C(0.5f, 0.5f);
            fn_1_496FC((f32)(s32)(v40 - 153), textY = v38 + (f32)((s32)v51 + v55.value * 20));
            fn_1_4954C(10.0f);
            fn_1_49738(fn_3_240DC);
            fn_1_49748(1.0f);
            lab_t1 = fn_1_14EA74(id, loc_20, v0);
            fn_1_4AE0C((const char *)(p_lbl_3_data_3D50 + 0xe34), lab_t1);
            fn_1_49410();
            fn_1_495B0(0x80000000);
            fn_1_4965C(2);
            fn_1_4955C(0.5f, 0.5f);
            fn_1_496FC((f32)(s32)(v40 + 19), textY);
            fn_1_4954C(10.0f);
            fn_1_49738(fn_3_240DC);
            fn_1_49748(1.0f);
            fn_1_4AE0C((const char *)(p_lbl_3_data_3D50 + 0xe40), (s16)weight);
            fn_1_49410();
            fn_1_495B0(0x80000000);
            fn_1_4965C(2);
            fn_1_4955C(0.5f, 0.5f);
            fn_1_496FC((f32)(s32)(v40 + 105), textY);
            fn_1_4954C(10.0f);
            fn_1_49738(fn_3_240DC);
            fn_1_49748(1.0f);
            loc_C = lbl_3_rodata_990__fzgx_offset_118[0];
            fn_1_49514(&loc_C);
            fn_1_4AE0C((const char *)(p_lbl_3_data_3D50 + 0xe34), fn_1_14EE00(kind, loc_20, v0));
            if (owned) {
                RESET_PACKET();
                loc_54.a[0] = 0xA30F;
                PF(4) = (f32)xOwned;
                PF(8) = v38 + (f32)((s32)v52 + v55.value * 20);
                PF(12) = 10.0f;
                loc_54.a[12] = 0x0400000A;
                PP(80) = fn_3_2406C;
                fn_1_4F734((FontDrawPacket *)&loc_54);
            } else {
                RESET_PACKET();
                loc_54.a[0] = 0xA302;
                PF(4) = (f32)(s32)(v40 + 204);
                textY = v38 + (f32)((s32)v53 + v55.value * 20);
                PF(8) = textY;
                PF(12) = 10.0f;
                loc_54.a[12] = 0x04000000;
                PP(80) = fn_3_2406C;
                PF(20) = 0.8f;
                PF(16) = 0.8f;
                fn_1_4F734((FontDrawPacket *)&loc_54);
                number = count < 0 ? 0 : count > 99 ? 99 : count;
                digit = number / 10 % 10;
                RESET_PACKET();
                loc_54.a[0] = 0xA31F;
                PF(8) = textY;
                PF(4) = (f32)xTens;
                PF(12) = 10.0f;
                loc_54.a[12] = 0x04000000;
                PP(80) = fn_3_2406C;
                fn_1_51564(0, 0, 12, 16, 10, 9);
                fn_1_5158C((FontDrawPacket *)&loc_54, loc_54.a[0], (s16)(digit % 10), (s16)(digit / 10));
                fn_1_4F734((FontDrawPacket *)&loc_54);
                RESET_PACKET();
                loc_54.a[0] = 0xA31F;
                PF(8) = textY;
                PF(4) = (f32)xOnes;
                PF(12) = 10.0f;
                loc_54.a[12] = 0x04000000;
                PP(80) = fn_3_2406C;
                fn_1_51564(0, 0, 12, 16, 10, 9);
                digit2 = number % 10;
                fn_1_5158C((FontDrawPacket *)&loc_54, loc_54.a[0], (s16)(digit2 % 10), (s16)(digit2 / 10));
                fn_1_4F734((FontDrawPacket *)&loc_54);
            }
        }
    }
    return (u32)p_lbl_3_data_3D50;
}
#pragma opt_common_subs reset
