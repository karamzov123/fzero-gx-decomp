#include "types.h"
#include "rel/sel/globals.h"
#include "rel/sel/name_entry.h"


extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);

/* fzgx:begin fn_10_24BD0 noprologue */
#include "font.h"

/* Reproduce the shared constant-pool layout; .fzgxpool is excluded at integration. */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[360] = {0x89709094, 0x00000000, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x00000000, 0x8B4C8D86, 0x00000000, 0x81418142, 0x814C814D, 0x81458143, 0x81448146, 0x81478148, 0x8149817B, 0x817C815E, 0x81818183, 0x8184814F, 0x81518160, 0x81628175, 0x81768169, 0x816A816F, 0x8170816D, 0x816E818F, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x82D082E7, 0x82AA82C8, 0x00000000, 0x82A082A2, 0x82A482A6, 0x82A882A9, 0x82AB82AD, 0x82AF82B1, 0x82B382B5, 0x82B782B9, 0x82BB82BD, 0x82BF82C2, 0x82C482C6, 0x82C882C9, 0x82CA82CB, 0x82CC82CD, 0x82D082D3, 0x82D682D9, 0x82DC82DD, 0x82DE82DF, 0x82E082E2, 0x82E482E6, 0x82E782E8, 0x82E982EA, 0x82EB82ED, 0x82EE82EF, 0x82F082F1, 0x82AA82AC, 0x82AE82B0, 0x82B282B4, 0x82B682B8, 0x82BA82BC, 0x82BE82C0, 0x82C382C5, 0x82C782CE, 0x82D182D4, 0x82D782DA, 0x82CF82D2, 0x82D582D8, 0x82DB829F, 0x82A182A3, 0x82A582A7, 0x82C182E1, 0x82E382E5, 0x82EC81E7, 0x81E80000, 0x829F82A1, 0x82A382A5, 0x82A782AA, 0x82AC82AE, 0x82B082B2, 0x82B482B6, 0x82B882BA, 0x82BC82BE, 0x82C082C1, 0x82C582C7, 0x81408140, 0x81408140, 0x814082CE, 0x82D182D4, 0x82D782DA, 0x81408140, 0x81408140, 0x814082E1, 0x82E382E5, 0x81408140, 0x81408140, 0x814082EC, 0x81408140, 0x81408140, 0x82A982AB, 0x82AD82AF, 0x82B182B3, 0x82B582B7, 0x82B982BB, 0x82BD82BF, 0x82C282C4, 0x82C682CF, 0x82D282D5, 0x82D882DB, 0x82CD82D0, 0x82D382D6, 0x82D982A0, 0x82A282A4, 0x82A682A8, 0x82C282E2, 0x82E482E6, 0x82ED8140, 0x81400000, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x814082C3, 0x81408140, 0x81408140, 0x81408140, 0x814082CF, 0x82D282D5, 0x82D882DB, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x82C18140, 0x814082CD, 0x82D082D3, 0x82D682D9, 0x82CE82D1, 0x82D482D7, 0x82DA8140, 0x81408140, 0x81408140, 0x82C38140, 0x81408140, 0x81408140, 0x81400000, 0x834A835E, 0x834A8369, 0x00000000, 0x83418343, 0x83458347, 0x8349834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x8369836A, 0x836B836C, 0x836D836E, 0x83718374, 0x82D6837A, 0x837D837E, 0x83808381, 0x83828384, 0x83868388, 0x8389838A, 0x838B838C, 0x838D838F, 0x83908391, 0x83928393, 0x8394834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618364, 0x83668368, 0x836F8372, 0x837582D7, 0x837B8370, 0x83738376, 0x82D8837C, 0x83408342, 0x83448346, 0x83488395, 0x83968362, 0x83838385, 0x8387838E, 0x81E781E8, 0x00000000, 0x83408342, 0x83448346, 0x8348834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618362, 0x83668368, 0x81408140, 0x81408140, 0x8140836F, 0x83728375, 0x82D7837B, 0x81408140, 0x81408140, 0x81408383, 0x83858387, 0x81408140, 0x81408140, 0x8140838E, 0x81408140, 0x81408140, 0x8345834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x83708373, 0x837682D8, 0x837C836E, 0x83718374, 0x82D6837A, 0x83418343, 0x83458347, 0x8349834A, 0x83508363, 0x83848386, 0x8388838F, 0x81408140, 0x00000000, 0x81408140, 0x83948140, 0x81408395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408364, 0x81408140, 0x81408140, 0x81408140, 0x81408370, 0x83738376, 0x82D8837C, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x81408140, 0x83448395, 0x81408140, 0x83968140, 0x81408140, 0x81408140, 0x81408140, 0x81408362, 0x81408140, 0x836E8371, 0x837482D6, 0x837A836F, 0x83728375, 0x82D7837B, 0x81408140, 0x83948140, 0x8140834B, 0x83518364, 0x81408140, 0x81408140, 0x81408140, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 225.43910217285156f;
}
static const u32 fzgx_pool_table3[65] = {0x74616C20, 0x4C657474, 0x65727300, 0x82608261, 0x82628263, 0x82648265, 0x82668267, 0x82688269, 0x826A826B, 0x826C826D, 0x826E826F, 0x82708271, 0x82728273, 0x82748275, 0x82768277, 0x82788279, 0x81E781E8, 0x00000000, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x82818282, 0x82838284, 0x82858286, 0x82878288, 0x8289828A, 0x828B828C, 0x828D828E, 0x828F8290, 0x82918292, 0x82938294, 0x82958296, 0x82978298, 0x8299829A, 0x81E781E8, 0x00000000, 0x5369676E, 0x73000000, 0x81438144, 0x81488149, 0x817B817C, 0x815E815F, 0x81818183, 0x81848146, 0x8147814C, 0x814D814F, 0x81518162, 0x8169816A, 0x816D816E, 0x816F8170, 0x81908193, 0x81948195, 0x81968197, 0x81E781E8, 0x00000000, 0x4E756D62, 0x65727300, 0x824F8250, 0x82518252, 0x82538254, 0x82558256, 0x82578258, 0x81E781E8, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.21;
    d = 1.6666666666666667;
    d = 0.5;
    s = 48.0f;
    s = 0.25f;
    d = 1.0;
    s = 0.12999999523162842f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.5;
    d = 2.0;
    s = 1.6666666269302368f;
    s = 0.0625f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 32.0f;
    s = 24.0f;
    s = 18.0f;
}
static const u32 fzgx_pool_table7[6] = {0xFFFFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x000000FF, 0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.0f;
    s = 0.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    d = 12.0;
    s = 10.100000381469727f;
}
static const u32 fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 24.0;
    s = 1.0f;
    s = 10.0f;
}
static const u32 fzgx_pool_table13[2] = {0x00FFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.649999976158142f;
}
static const u32 fzgx_pool_table15[1] = {0x33333333};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table17[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table20[1] = {0x00FFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 6.0;
    d = 20.0;
    s = 167.0f;
    s = 38.0f;
    s = 0.5f;
    s = 68.0f;
    s = 10.199999809265137f;
    s = 320.0f;
    s = 140.0f;
    s = 98.0f;
    s = 0.1899999976158142f;
    s = 178.0f;
    s = 0.18000000715255737f;
    s = 0.17000000178813934f;
    s = 352.0f;
    s = 0.1599999964237213f;
    s = 0.15000000596046448f;
    s = 0.14000000059604645f;
    s = 110.0f;
    s = 250.0f;
    s = 180.0f;
    s = 390.0f;
    s = 378.0f;
}
static const u32 fzgx_pool_table23[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1;
    d = 0.25;
    s = 346.0f;
    s = 0.11999999731779099f;
    s = 397.0f;
    s = 321.0f;
    d = 2.1666666666666665;
    s = 118.0f;
    s = 0.625f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table25[1] = {0x00FFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct NameEntryAlphabet {
    u16 selected_character;
    u16 reserved;
    const char *capital;
    const char *small;
    const char *signs;
    const char *label;
} NameEntryAlphabet;

typedef struct {
    u32 flags;  /* 11 loads, 6 stores */
    u32 unk_4;  /* 1 loads, 1 stores */
    u32 unk_8;  /* 4 loads, 1 stores */
    u8 unk_C;   /* 8 loads, 1 stores */
    u8 alphabet_index;   /* 5 loads, 4 stores */
    u8 name_length;   /* 10 loads, 3 stores */
    u8 letter_case;   /* 3 loads, 12 stores */
    u8 unk_10;  /* 1 loads, 0 stores */
    u8 rotation;  /* 2 loads, 1 stores */
    u16 selection_x; /* 3 loads, 3 stores */
    u8 tab_pulse;  /* 2 loads, 2 stores */
    u8 up_pulse;  /* 2 loads, 2 stores */
    u8 left_pulse;  /* 2 loads, 2 stores */
    u8 right_pulse;  /* 2 loads, 2 stores */
    u32 unk_18; /* 1 loads, 1 stores */
    u32 unk_1C; /* 1 loads, 1 stores */
    u32 unk_20; /* 3 loads, 2 stores */
    u8 pad_24[0x4];
    u8 unk_28; /* 1 loads, 0 stores */
    u8 pad_29[0xD];
    u8 name_complete; /* 2 loads, 1 stores */
    u8 unk_37; /* 0 loads, 1 stores */
    u8 pad_38[0x2];
    u8 pulse_ticks;  /* 2 loads, 2 stores */
    u8 unk_3B;  /* 5 loads, 2 stores */
    NameEntryAlphabet *alphabets; /* 4 loads, 2 stores */
} NameEntryState;
extern NameEntryState *lbl_10_bss_55CD8;
const u8 fzgx_pool_lbl_10_rodata_1548[8] = {0x89, 0x70, 0x90, 0x94, 0x00, 0x00, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1550[132] = {
    0x82, 0x60, 0x82, 0x61, 0x82, 0x62, 0x82, 0x63, 0x82, 0x64, 0x82, 0x65, 0x82, 0x66, 0x82,
    0x67, 0x82, 0x68, 0x82, 0x69, 0x82, 0x6A, 0x82, 0x6B, 0x82, 0x6C, 0x82, 0x6D, 0x82, 0x6E,
    0x82, 0x6F, 0x82, 0x70, 0x82, 0x71, 0x82, 0x72, 0x82, 0x73, 0x82, 0x74, 0x82, 0x75, 0x82,
    0x76, 0x82, 0x77, 0x82, 0x78, 0x82, 0x79, 0x82, 0x81, 0x82, 0x82, 0x82, 0x83, 0x82, 0x84,
    0x82, 0x85, 0x82, 0x86, 0x82, 0x87, 0x82, 0x88, 0x82, 0x89, 0x82, 0x8A, 0x82, 0x8B, 0x82,
    0x8C, 0x82, 0x8D, 0x82, 0x8E, 0x82, 0x8F, 0x82, 0x90, 0x82, 0x91, 0x82, 0x92, 0x82, 0x93,
    0x82, 0x94, 0x82, 0x95, 0x82, 0x96, 0x82, 0x97, 0x82, 0x98, 0x82, 0x99, 0x82, 0x9A, 0x82,
    0x4F, 0x82, 0x50, 0x82, 0x51, 0x82, 0x52, 0x82, 0x53, 0x82, 0x54, 0x82, 0x55, 0x82, 0x56,
    0x82, 0x57, 0x82, 0x58, 0x81, 0xE7, 0x81, 0xE8, 0x00, 0x00, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_15D4[132] = {
    0x82, 0x81, 0x82, 0x82, 0x82, 0x83, 0x82, 0x84, 0x82, 0x85, 0x82, 0x86, 0x82, 0x87, 0x82,
    0x88, 0x82, 0x89, 0x82, 0x8A, 0x82, 0x8B, 0x82, 0x8C, 0x82, 0x8D, 0x82, 0x8E, 0x82, 0x8F,
    0x82, 0x90, 0x82, 0x91, 0x82, 0x92, 0x82, 0x93, 0x82, 0x94, 0x82, 0x95, 0x82, 0x96, 0x82,
    0x97, 0x82, 0x98, 0x82, 0x99, 0x82, 0x9A, 0x82, 0x60, 0x82, 0x61, 0x82, 0x62, 0x82, 0x63,
    0x82, 0x64, 0x82, 0x65, 0x82, 0x66, 0x82, 0x67, 0x82, 0x68, 0x82, 0x69, 0x82, 0x6A, 0x82,
    0x6B, 0x82, 0x6C, 0x82, 0x6D, 0x82, 0x6E, 0x82, 0x6F, 0x82, 0x70, 0x82, 0x71, 0x82, 0x72,
    0x82, 0x73, 0x82, 0x74, 0x82, 0x75, 0x82, 0x76, 0x82, 0x77, 0x82, 0x78, 0x82, 0x79, 0x81,
    0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40,
    0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x00, 0x00, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1658[8] = {0x8B, 0x4C, 0x8D, 0x86, 0x00, 0x00, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1660[80] = {
    0x81, 0x41, 0x81, 0x42, 0x81, 0x4C, 0x81, 0x4D, 0x81, 0x45, 0x81, 0x43, 0x81, 0x44, 0x81, 0x46,
    0x81, 0x47, 0x81, 0x48, 0x81, 0x49, 0x81, 0x7B, 0x81, 0x7C, 0x81, 0x5E, 0x81, 0x81, 0x81, 0x83,
    0x81, 0x84, 0x81, 0x4F, 0x81, 0x51, 0x81, 0x60, 0x81, 0x62, 0x81, 0x75, 0x81, 0x76, 0x81, 0x69,
    0x81, 0x6A, 0x81, 0x6F, 0x81, 0x70, 0x81, 0x6D, 0x81, 0x6E, 0x81, 0x8F, 0x81, 0x90, 0x81, 0x93,
    0x81, 0x94, 0x81, 0x95, 0x81, 0x96, 0x81, 0x97, 0x81, 0xE7, 0x81, 0xE8, 0x00, 0x00, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_16B0[12] = {0x82, 0xD0, 0x82, 0xE7, 0x82, 0xAA,
                                   0x82, 0xC8, 0x00, 0x00, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_16BC[172] = {
    0x82, 0xA0, 0x82, 0xA2, 0x82, 0xA4, 0x82, 0xA6, 0x82, 0xA8, 0x82, 0xA9, 0x82, 0xAB, 0x82, 0xAD,
    0x82, 0xAF, 0x82, 0xB1, 0x82, 0xB3, 0x82, 0xB5, 0x82, 0xB7, 0x82, 0xB9, 0x82, 0xBB, 0x82, 0xBD,
    0x82, 0xBF, 0x82, 0xC2, 0x82, 0xC4, 0x82, 0xC6, 0x82, 0xC8, 0x82, 0xC9, 0x82, 0xCA, 0x82, 0xCB,
    0x82, 0xCC, 0x82, 0xCD, 0x82, 0xD0, 0x82, 0xD3, 0x82, 0xD6, 0x82, 0xD9, 0x82, 0xDC, 0x82, 0xDD,
    0x82, 0xDE, 0x82, 0xDF, 0x82, 0xE0, 0x82, 0xE2, 0x82, 0xE4, 0x82, 0xE6, 0x82, 0xE7, 0x82, 0xE8,
    0x82, 0xE9, 0x82, 0xEA, 0x82, 0xEB, 0x82, 0xED, 0x82, 0xEE, 0x82, 0xEF, 0x82, 0xF0, 0x82, 0xF1,
    0x82, 0xAA, 0x82, 0xAC, 0x82, 0xAE, 0x82, 0xB0, 0x82, 0xB2, 0x82, 0xB4, 0x82, 0xB6, 0x82, 0xB8,
    0x82, 0xBA, 0x82, 0xBC, 0x82, 0xBE, 0x82, 0xC0, 0x82, 0xC3, 0x82, 0xC5, 0x82, 0xC7, 0x82, 0xCE,
    0x82, 0xD1, 0x82, 0xD4, 0x82, 0xD7, 0x82, 0xDA, 0x82, 0xCF, 0x82, 0xD2, 0x82, 0xD5, 0x82, 0xD8,
    0x82, 0xDB, 0x82, 0x9F, 0x82, 0xA1, 0x82, 0xA3, 0x82, 0xA5, 0x82, 0xA7, 0x82, 0xC1, 0x82, 0xE1,
    0x82, 0xE3, 0x82, 0xE5, 0x82, 0xEC, 0x81, 0xE7, 0x81, 0xE8, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1768[172] = {
    0x82, 0x9F, 0x82, 0xA1, 0x82, 0xA3, 0x82, 0xA5, 0x82, 0xA7, 0x82, 0xAA, 0x82, 0xAC, 0x82, 0xAE,
    0x82, 0xB0, 0x82, 0xB2, 0x82, 0xB4, 0x82, 0xB6, 0x82, 0xB8, 0x82, 0xBA, 0x82, 0xBC, 0x82, 0xBE,
    0x82, 0xC0, 0x82, 0xC1, 0x82, 0xC5, 0x82, 0xC7, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40,
    0x81, 0x40, 0x82, 0xCE, 0x82, 0xD1, 0x82, 0xD4, 0x82, 0xD7, 0x82, 0xDA, 0x81, 0x40, 0x81, 0x40,
    0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x82, 0xE1, 0x82, 0xE3, 0x82, 0xE5, 0x81, 0x40, 0x81, 0x40,
    0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x82, 0xEC, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40,
    0x82, 0xA9, 0x82, 0xAB, 0x82, 0xAD, 0x82, 0xAF, 0x82, 0xB1, 0x82, 0xB3, 0x82, 0xB5, 0x82, 0xB7,
    0x82, 0xB9, 0x82, 0xBB, 0x82, 0xBD, 0x82, 0xBF, 0x82, 0xC2, 0x82, 0xC4, 0x82, 0xC6, 0x82, 0xCF,
    0x82, 0xD2, 0x82, 0xD5, 0x82, 0xD8, 0x82, 0xDB, 0x82, 0xCD, 0x82, 0xD0, 0x82, 0xD3, 0x82, 0xD6,
    0x82, 0xD9, 0x82, 0xA0, 0x82, 0xA2, 0x82, 0xA4, 0x82, 0xA6, 0x82, 0xA8, 0x82, 0xC2, 0x82, 0xE2,
    0x82, 0xE4, 0x82, 0xE6, 0x82, 0xED, 0x81, 0x40, 0x81, 0x40, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1814[172] = {
    0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40,
    0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40,
    0x81, 0x40, 0x82, 0xC3, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40,
    0x81, 0x40, 0x82, 0xCF, 0x82, 0xD2, 0x82, 0xD5, 0x82, 0xD8, 0x82, 0xDB, 0x81, 0x40, 0x81, 0x40,
    0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40,
    0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40,
    0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40,
    0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x82, 0xC1, 0x81, 0x40, 0x81, 0x40, 0x82, 0xCD,
    0x82, 0xD0, 0x82, 0xD3, 0x82, 0xD6, 0x82, 0xD9, 0x82, 0xCE, 0x82, 0xD1, 0x82, 0xD4, 0x82, 0xD7,
    0x82, 0xDA, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x82, 0xC3, 0x81, 0x40,
    0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_18C0[12] = {0x83, 0x4A, 0x83, 0x5E, 0x83, 0x4A,
                                   0x83, 0x69, 0x00, 0x00, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_18CC[180] = {
    0x83, 0x41, 0x83, 0x43, 0x83, 0x45, 0x83, 0x47, 0x83, 0x49, 0x83, 0x4A, 0x83, 0x4C, 0x83,
    0x4E, 0x83, 0x50, 0x83, 0x52, 0x83, 0x54, 0x83, 0x56, 0x83, 0x58, 0x83, 0x5A, 0x83, 0x5C,
    0x83, 0x5E, 0x83, 0x60, 0x83, 0x63, 0x83, 0x65, 0x83, 0x67, 0x83, 0x69, 0x83, 0x6A, 0x83,
    0x6B, 0x83, 0x6C, 0x83, 0x6D, 0x83, 0x6E, 0x83, 0x71, 0x83, 0x74, 0x82, 0xD6, 0x83, 0x7A,
    0x83, 0x7D, 0x83, 0x7E, 0x83, 0x80, 0x83, 0x81, 0x83, 0x82, 0x83, 0x84, 0x83, 0x86, 0x83,
    0x88, 0x83, 0x89, 0x83, 0x8A, 0x83, 0x8B, 0x83, 0x8C, 0x83, 0x8D, 0x83, 0x8F, 0x83, 0x90,
    0x83, 0x91, 0x83, 0x92, 0x83, 0x93, 0x83, 0x94, 0x83, 0x4B, 0x83, 0x4D, 0x83, 0x4F, 0x83,
    0x51, 0x83, 0x53, 0x83, 0x55, 0x83, 0x57, 0x83, 0x59, 0x83, 0x5B, 0x83, 0x5D, 0x83, 0x5F,
    0x83, 0x61, 0x83, 0x64, 0x83, 0x66, 0x83, 0x68, 0x83, 0x6F, 0x83, 0x72, 0x83, 0x75, 0x82,
    0xD7, 0x83, 0x7B, 0x83, 0x70, 0x83, 0x73, 0x83, 0x76, 0x82, 0xD8, 0x83, 0x7C, 0x83, 0x40,
    0x83, 0x42, 0x83, 0x44, 0x83, 0x46, 0x83, 0x48, 0x83, 0x95, 0x83, 0x96, 0x83, 0x62, 0x83,
    0x83, 0x83, 0x85, 0x83, 0x87, 0x83, 0x8E, 0x81, 0xE7, 0x81, 0xE8, 0x00, 0x00, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1980[180] = {
    0x83, 0x40, 0x83, 0x42, 0x83, 0x44, 0x83, 0x46, 0x83, 0x48, 0x83, 0x4B, 0x83, 0x4D, 0x83,
    0x4F, 0x83, 0x51, 0x83, 0x53, 0x83, 0x55, 0x83, 0x57, 0x83, 0x59, 0x83, 0x5B, 0x83, 0x5D,
    0x83, 0x5F, 0x83, 0x61, 0x83, 0x62, 0x83, 0x66, 0x83, 0x68, 0x81, 0x40, 0x81, 0x40, 0x81,
    0x40, 0x81, 0x40, 0x81, 0x40, 0x83, 0x6F, 0x83, 0x72, 0x83, 0x75, 0x82, 0xD7, 0x83, 0x7B,
    0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x83, 0x83, 0x83, 0x85, 0x83,
    0x87, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x83, 0x8E, 0x81, 0x40,
    0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x83, 0x45, 0x83, 0x4A, 0x83, 0x4C, 0x83, 0x4E, 0x83,
    0x50, 0x83, 0x52, 0x83, 0x54, 0x83, 0x56, 0x83, 0x58, 0x83, 0x5A, 0x83, 0x5C, 0x83, 0x5E,
    0x83, 0x60, 0x83, 0x63, 0x83, 0x65, 0x83, 0x67, 0x83, 0x70, 0x83, 0x73, 0x83, 0x76, 0x82,
    0xD8, 0x83, 0x7C, 0x83, 0x6E, 0x83, 0x71, 0x83, 0x74, 0x82, 0xD6, 0x83, 0x7A, 0x83, 0x41,
    0x83, 0x43, 0x83, 0x45, 0x83, 0x47, 0x83, 0x49, 0x83, 0x4A, 0x83, 0x50, 0x83, 0x63, 0x83,
    0x84, 0x83, 0x86, 0x83, 0x88, 0x83, 0x8F, 0x81, 0x40, 0x81, 0x40, 0x00, 0x00, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1A34[180] = {
    0x81, 0x40, 0x81, 0x40, 0x83, 0x94, 0x81, 0x40, 0x81, 0x40, 0x83, 0x95, 0x81, 0x40, 0x81,
    0x40, 0x83, 0x96, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40,
    0x81, 0x40, 0x81, 0x40, 0x83, 0x64, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81,
    0x40, 0x81, 0x40, 0x81, 0x40, 0x83, 0x70, 0x83, 0x73, 0x83, 0x76, 0x82, 0xD8, 0x83, 0x7C,
    0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81,
    0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40,
    0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x83, 0x44, 0x83, 0x95, 0x81, 0x40, 0x81, 0x40, 0x83,
    0x96, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40,
    0x81, 0x40, 0x83, 0x62, 0x81, 0x40, 0x81, 0x40, 0x83, 0x6E, 0x83, 0x71, 0x83, 0x74, 0x82,
    0xD6, 0x83, 0x7A, 0x83, 0x6F, 0x83, 0x72, 0x83, 0x75, 0x82, 0xD7, 0x83, 0x7B, 0x81, 0x40,
    0x81, 0x40, 0x83, 0x94, 0x81, 0x40, 0x81, 0x40, 0x83, 0x4B, 0x83, 0x51, 0x83, 0x64, 0x81,
    0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x00, 0x00, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1AE8[16] = {0x43, 0x61, 0x70, 0x69, 0x74, 0x61, 0x6C, 0x20,
                                   0x4C, 0x65, 0x74, 0x74, 0x65, 0x72, 0x73, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1AF8[60] = {
    0x82, 0x60, 0x82, 0x61, 0x82, 0x62, 0x82, 0x63, 0x82, 0x64, 0x82, 0x65, 0x82, 0x66, 0x82,
    0x67, 0x82, 0x68, 0x82, 0x69, 0x82, 0x6A, 0x82, 0x6B, 0x82, 0x6C, 0x82, 0x6D, 0x82, 0x6E,
    0x82, 0x6F, 0x82, 0x70, 0x82, 0x71, 0x82, 0x72, 0x82, 0x73, 0x82, 0x74, 0x82, 0x75, 0x82,
    0x76, 0x82, 0x77, 0x82, 0x78, 0x82, 0x79, 0x81, 0xE7, 0x81, 0xE8, 0x00, 0x00, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1B34[14] = {0x53, 0x6D, 0x61, 0x6C, 0x6C, 0x20, 0x4C,
                                   0x65, 0x74, 0x74, 0x65, 0x72, 0x73, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1B44[60] = {
    0x82, 0x81, 0x82, 0x82, 0x82, 0x83, 0x82, 0x84, 0x82, 0x85, 0x82, 0x86, 0x82, 0x87, 0x82,
    0x88, 0x82, 0x89, 0x82, 0x8A, 0x82, 0x8B, 0x82, 0x8C, 0x82, 0x8D, 0x82, 0x8E, 0x82, 0x8F,
    0x82, 0x90, 0x82, 0x91, 0x82, 0x92, 0x82, 0x93, 0x82, 0x94, 0x82, 0x95, 0x82, 0x96, 0x82,
    0x97, 0x82, 0x98, 0x82, 0x99, 0x82, 0x9A, 0x81, 0xE7, 0x81, 0xE8, 0x00, 0x00, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1B80[6] = {0x53, 0x69, 0x67, 0x6E, 0x73, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1B88[68] = {
    0x81, 0x43, 0x81, 0x44, 0x81, 0x48, 0x81, 0x49, 0x81, 0x7B, 0x81, 0x7C, 0x81, 0x5E,
    0x81, 0x5F, 0x81, 0x81, 0x81, 0x83, 0x81, 0x84, 0x81, 0x46, 0x81, 0x47, 0x81, 0x4C,
    0x81, 0x4D, 0x81, 0x4F, 0x81, 0x51, 0x81, 0x62, 0x81, 0x69, 0x81, 0x6A, 0x81, 0x6D,
    0x81, 0x6E, 0x81, 0x6F, 0x81, 0x70, 0x81, 0x90, 0x81, 0x93, 0x81, 0x94, 0x81, 0x95,
    0x81, 0x96, 0x81, 0x97, 0x81, 0xE7, 0x81, 0xE8, 0x00, 0x00, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1BCC[8] = {0x4E, 0x75, 0x6D, 0x62, 0x65, 0x72, 0x73, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1BD4[44] = {
    0x82, 0x4F, 0x82, 0x50, 0x82, 0x51, 0x82, 0x52, 0x82, 0x53, 0x82, 0x54, 0x82, 0x55, 0x82,
    0x56, 0x82, 0x57, 0x82, 0x58, 0x81, 0xE7, 0x81, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xCA,
    0xE1, 0x47, 0xAE, 0x14, 0x7A, 0xE1, 0x3F, 0xFA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAB};
const f64 fzgx_pool_lbl_10_rodata_1BD4__fzgx_offset_2C = 0.5;
const u8 fzgx_pool_lbl_10_rodata_1BD4__fzgx_offset_34[8] = {0x42, 0x40, 0x00, 0x00, 0x3E, 0x80, 0x00, 0x00};
const f64 fzgx_pool_lbl_10_rodata_1BD4__fzgx_offset_3C = 1.0;
const f32 fzgx_pool_lbl_10_rodata_1BD4__fzgx_offset_44 = 0.129999995f;
const u8 fzgx_pool_lbl_10_rodata_1BD4__fzgx_offset_48[28] = {
    0x00, 0x00, 0x00, 0x00, 0x3F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xD5, 0x55, 0x55, 0x3D, 0x80, 0x00, 0x00};
const f64 fzgx_pool_lbl_10_rodata_1C38 = 4503601774854144.0;
const f64 fzgx_pool_lbl_10_rodata_1C40 = 4503599627370496.0;
const u8 fzgx_pool_lbl_10_rodata_1C40__fzgx_offset_8[40] = {
    0x42, 0x00, 0x00, 0x00, 0x41, 0xC0, 0x00, 0x00, 0x41, 0x90, 0x00, 0x00, 0xFF, 0xFF,
    0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00,
    0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x41, 0x40, 0x00, 0x00};
const f32 fzgx_pool_lbl_10_rodata_1C40__fzgx_offset_30 = 0.0f;
const u8 fzgx_pool_lbl_10_rodata_1C40__fzgx_offset_34[12] = {0x00, 0x00, 0x00, 0x00, 0x3F, 0xC9,
                                                   0x99, 0x99, 0x99, 0x99, 0x99, 0x9A};
const f64 fzgx_pool_lbl_10_rodata_1C40__fzgx_offset_40 = 12.0;
const u8 fzgx_pool_lbl_10_rodata_1C40__fzgx_offset_48[16] = {0x41, 0x21, 0x99, 0x9A, 0x00, 0x00, 0x00, 0x00,
                                                   0x40, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const f32 fzgx_pool_lbl_10_rodata_1C40__fzgx_offset_58 = 1.0f;
const u8 fzgx_pool_lbl_10_rodata_1C40__fzgx_offset_5C[4] = {0x41, 0x20, 0x00, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1CA0[4] = {0x00, 0xFF, 0xFF, 0x00};
const u8 fzgx_pool_lbl_10_rodata_1CA8[8] = {0x3F, 0xD3, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33};
const u8 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_1C[4] = {0x00, 0x00, 0x00, 0x00};
const f64 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_20 = 6.0;
const f64 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_28 = 20.0;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_30 = 167.0f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_34 = 38.0f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_38 = 0.5f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_3C = 68.0f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_40 = 10.1999998f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_44 = 320.0f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_48 = 140.0f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_4C = 98.0f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_50 = 0.189999998f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_54 = 178.0f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_58 = 0.180000007f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_5C = 0.170000002f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_60 = 352.0f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_64 = 0.159999996f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_68 = 0.150000006f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_6C = 0.140000001f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_70 = 110.0f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_74 = 250.0f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_78 = 180.0f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_7C = 390.0f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_80 = 378.0f;
const u8 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_84[4] = {0x00, 0x00, 0x00, 0x00};
const f64 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_88 = 1.1000000000000001;
const f64 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_90 = 0.25;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_98 = 346.0f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_9C = 0.119999997f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_A0 = 397.0f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_A4 = 321.0f;
const f64 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_A8 = 2.1666666666666665;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_B0 = 118.0f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_B4 = 0.625f;
const f32 fzgx_pool_lbl_10_rodata_1CA8__fzgx_offset_B8 = 0.300000012f;
/* Packet templates are copied in full, including the callback and texture fields. */
struct NameEntryPacketWords {
    u32 words[22];
};
/* Colors use a packed word at the font boundary and signed byte channels internally. */
struct NameEntryColor {
    s8 channels[4];
};
extern u32 lbl_10_data_69C0;
extern void *lbl_1_data_418D4[];
extern u32 lbl_10_data_69D8;
extern s16 lbl_1_bss_960;
extern s32 lbl_801A66B4;
extern u32 lbl_801A66A0;
extern u8 lbl_1_rodata_26F8[];
extern u32 fn_1_49410(void);
extern u32 fn_1_134AD4(void);
extern void fn_1_133DBC(void *);
extern void fn_1_1380F0(void *);
extern u32 fn_1_13ABA8(u32);
extern f32 lbl_8006D188(s16);
extern void *memset(void *, int, u32);
extern char *strncpy(char *, const char *, size_t);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49514(u32 *);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);

static inline f32 name_entry_pulse_scale(u8 c) {
    if (c > 9) {
        return (f32)(0.5 + (f64)(f32)(c - 10) / 6.0);
    }
    return (f32)(0.5 + (f64)(f32)(10 - c) / 20.0);
}
void fn_10_24BD0(void) {
    struct fn_4_C768_Ro410 *rd;

    FontDrawPacket packet;
    u8 buf[3];
    struct NameEntryColor tab_color;
    struct NameEntryColor left_color;
    struct NameEntryColor right_color;
    struct NameEntryColor cursor_color;
    u32 sp8;
    f32 pulse_scale;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 cursor_scale;
    u32 char_index;
    u32 empty_index;
    u32 text_index;
    u32 cursor_x;
    u8 *text;
    NameEntryAlphabet *alphabet;
    fn_1_49410();
    {
        u8 c = lbl_10_bss_55CD8->pulse_ticks;
        alphabet = &lbl_10_bss_55CD8->alphabets[lbl_10_bss_55CD8->alphabet_index];
        if (c != 0) {
            pulse_scale = name_entry_pulse_scale(c);
            lbl_10_bss_55CD8->pulse_ticks--;
        } else {
            pulse_scale = 1.0f;
        }
        fn_1_134AD4();
        if (lbl_1_bss_960 != 3) {
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x8F0C;
            packet.x = (167.0f);
            packet.y = (38.0f);
            packet.z = (0.5f);
            packet.flags = 0xA;
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        if (((lbl_10_bss_55CD8->flags) >> 0x1FU) == 0) {
            if (lbl_801A66B4 == 5) {
                fn_1_1380F0(&lbl_10_data_69C0);
            } else {
                fn_1_1380F0(&lbl_10_data_69D8);
            }
        } else {
            fn_1_1380F0(lbl_1_data_418D4[lbl_801A66B4]);
        }
        fn_1_13ABA8(0x18000000U);
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x8F0A;
        packet.x = (0.0f);
        packet.y = (68.0f);
        packet.z = (10.1999998f);
        fn_1_4F734((FontDrawPacket *)&packet);
        packet.x = (320.0f);
        packet.flags |= 0x80000;
        fn_1_4F734((FontDrawPacket *)&packet);
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x8F08;
        packet.x = (140.0f);
        packet.y = (98.0f);
        packet.z = (0.189999998f);
        fn_1_4F734((FontDrawPacket *)&packet);
        packet.x = (320.0f);
        packet.flags |= 0x80000;
        fn_1_4F734((FontDrawPacket *)&packet);
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x8F05;
        packet.x = (320.0f);
        packet.y = (178.0f);
        packet.z = (0.180000007f);
        packet.flags = 0xA;
        fn_1_4F734((FontDrawPacket *)&packet);
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x8F06;
        packet.x = (320.0f);
        packet.y = (178.0f);
        packet.z = (0.170000002f);
        packet.flags = 0xA;
        fn_1_4F734((FontDrawPacket *)&packet);
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x8F0B;
        empty_index = 0;
        char_index = 0x62;
        packet.y = (352.0f);
        packet.z = (0.159999996f);
        do {
            packet.x = (f32)char_index;
            fn_1_4F734((FontDrawPacket *)&packet);
            empty_index += 1;
            char_index += 0x38;
        } while (empty_index < 8);
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x8F07;
        packet.x = (320.0f);
        packet.y = (178.0f);
        packet.z = (0.150000006f);
        packet.flags = 0xA;
        packet.rotation_z = (s16)((lbl_10_bss_55CD8->rotation << 8) & 0xFF00);
        if ((1.0) != pulse_scale) {
            packet.scale_y = pulse_scale;
            packet.scale_x = pulse_scale;
        }
        fn_1_4F734((FontDrawPacket *)&packet);
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.x = (320.0f);
        packet.z = (0.140000001f);
        packet.flags = 0xA;
        packet.image = 0x8F0D;
        packet.y = (110.0f);
        {
            u32 v = lbl_10_bss_55CD8->tab_pulse;
            tab_color = *(const struct NameEntryColor *)&(fzgx_pool_table16[0]);
            tab_color.channels[0] = (u8)((v * 0x10) & 0xF0);
            tab_color.channels[1] = (u8)((v * 0x10) & 0xF0);
            tab_color.channels[2] = (u8)((v * 0x10) & 0xF0);
            *(u32 *)packet.color_add = *(u32 *)&tab_color;
            temp_f0 = (f32)((1.0) + (f64)v / (12.0));
            packet.scale_y = temp_f0;
            packet.scale_x = temp_f0;
        }
        fn_1_4F734((FontDrawPacket *)&packet);
        packet.y = (250.0f);
        packet.image = 0x8F02;
        {
            u32 v = lbl_10_bss_55CD8->up_pulse;
            left_color = *(const struct NameEntryColor *)&(fzgx_pool_table17[0]);
            left_color.channels[0] = (u8)((v * 0x10) & 0xF0);
            left_color.channels[1] = (u8)((v * 0x10) & 0xF0);
            left_color.channels[2] = (u8)((v * 0x10) & 0xF0);
            *(u32 *)packet.color_add = *(u32 *)&left_color;
            temp_f0_2 = (f32)((1.0) + (f64)v / (12.0));
            packet.scale_y = temp_f0_2;
            packet.scale_x = temp_f0_2;
        }
        fn_1_4F734((FontDrawPacket *)&packet);
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.y = (180.0f);
        packet.z = (0.140000001f);
        packet.x = (250.0f);
        packet.flags = 0xA;
        packet.image = 0x8F04;
        {
            u32 v = lbl_10_bss_55CD8->left_pulse;
            right_color = *(const struct NameEntryColor *)&(fzgx_pool_table18[0]);
            right_color.channels[0] = (u8)((v * 0x10) & 0xF0);
            right_color.channels[1] = (u8)((v * 0x10) & 0xF0);
            right_color.channels[2] = (u8)((v * 0x10) & 0xF0);
            *(u32 *)packet.color_add = *(u32 *)&right_color;
            temp_f0_3 = (f32)((1.0) + (f64)v / (12.0));
            packet.scale_y = temp_f0_3;
            packet.scale_x = temp_f0_3;
        }
        fn_1_4F734((FontDrawPacket *)&packet);
        packet.x = (390.0f);
        packet.flags |= 0x80000;
        {
            u32 v = lbl_10_bss_55CD8->right_pulse;
            cursor_color = *(const struct NameEntryColor *)&(fzgx_pool_table19[0]);
            cursor_color.channels[0] = (u8)((v * 0x10) & 0xF0);
            cursor_color.channels[1] = (u8)((v * 0x10) & 0xF0);
            cursor_color.channels[2] = (u8)((v * 0x10) & 0xF0);
            *(u32 *)packet.color_add = *(u32 *)&cursor_color;
            temp_f0_4 = (f32)((1.0) + (f64)v / (12.0));
            packet.scale_y = temp_f0_4;
            packet.scale_x = temp_f0_4;
        }
        fn_1_4F734((FontDrawPacket *)&packet);
        if (lbl_10_bss_55CD8->name_length != 7 || lbl_10_bss_55CD8->name_complete == 0) {
            packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
            packet.y = (378.0f);
            packet.image = 0x8F09;
            packet.z = (0.129999995f);
            {
                f64 t = (0.25) * lbl_8006D188((s16)((lbl_801A66A0 << 8) & 0xFF00));
                cursor_scale = (f32)((1.1000000000000001) + t);
            }
            packet.flags = 0xA;
            packet.scale_y = cursor_scale;
            packet.scale_x = cursor_scale;
            text_index = lbl_10_bss_55CD8->name_length;
            cursor_x = (text_index * 0x38) + 0x7C;
            while (text_index < 8) {
                packet.x = (f32)cursor_x;
                fn_1_4F734((FontDrawPacket *)&packet);
                cursor_x += 0x38;
                text_index += 1;
            }
        }
        if (((lbl_10_bss_55CD8->flags) >> 0x1FU) == 0) {
            *(struct NameEntryPacketWords *)&packet =
                *(struct NameEntryPacketWords *)lbl_1_rodata_26F8;
            packet.image = 0x8F00;
            packet.x = (f32)(lbl_10_bss_55CD8->selection_x);
            packet.y = (346.0f);
            packet.z = (0.119999997f);
            fn_1_4F734((FontDrawPacket *)&packet);
            packet.image = 0x8F01;
            packet.y = (397.0f);
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        memset(buf, 0, 3);
        switch (lbl_10_bss_55CD8->letter_case) {
        case 0:
        default:
            text = (u8 *)(alphabet->capital + alphabet->selected_character * 2);
            break;
        case 1:
            text = (u8 *)(alphabet->small + alphabet->selected_character * 2);
            break;
        case 2:
            text = (u8 *)(alphabet->signs + alphabet->selected_character * 2);
            break;
        }
        strncpy((char *)buf, (const char *)text, 2);
        fn_1_49410();
        fn_1_494DC(0x2A);
        fn_1_495C8(9);
        fn_1_496FC((321.0f), (178.0f));
        {
            f64 t = (2.1666666666666665) * (f64)pulse_scale;
            fn_1_4955C((f32)t, (f32)t);
        }
        fn_1_4A0D8((const char *)buf);
        packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x8F03;
        packet.x = (118.0f);
        packet.y = (118.0f);
        packet.z = (0.189999998f);
        fn_1_4F734((FontDrawPacket *)&packet);
        fn_1_49410();
        fn_1_494DC(0x2A);
        fn_1_496FC((140.0f), (118.0f));
        sp8 = fzgx_pool_table20[0];
        fn_1_49514(&sp8);
        if (lbl_801A66B4 == 5) {
            fn_1_4955C((0.625f), (0.625f));
        } else {
            fn_1_4955C((0.5f), (0.5f));
            fn_1_49590((0.300000012f));
            fn_1_495B0(0x80000000U);
        }
        fn_1_4A0D8(alphabet->label);
        fn_1_133DBC((void *)1);
    }
}
/* fzgx:end fn_10_24BD0 */

/* fzgx:begin fn_10_25BC8 */
typedef struct fn_10_25BC8_NameEntryState {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u8 _pad0c[0x0c];
    u32 unk18;
    u32 unk1c;
} fn_10_25BC8_NameEntryState;

extern void fn_1_46B4(u32 arg0, fn_10_25BC8_NameEntryState *arg1, u8 *arg2, int arg3);

void fn_10_25BC8(void) {
    lbl_10_bss_55CDC = 1;
    fn_1_435C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk04);
    fn_1_426C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk18);
    fn_1_A8F78();
    fn_1_48140(0x8f);

    if (lbl_1_bss_960 != 1) {
        if (lbl_1_bss_960 != 3) {
            fn_1_412A0(1);
            fn_1_48140(0x9a);
        }
        fn_1_48140(0x9e);
    }

    fn_1_435C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk08);
    fn_1_426C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk1c);
    fn_1_46B4(lbl_801A6410, (fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8,
              lbl_10_data_6980, 0x562);
    lbl_10_bss_55CD8 = 0;
}
/* fzgx:end fn_10_25BC8 */

/* fzgx:begin fn_10_25CB0 */
typedef struct fn_10_25CB0_Entry {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    u8 unk_C;
} fn_10_25CB0_Entry;

typedef struct fn_10_25CB0_Pair {
    u8 unk_0;
    u8 unk_1;
} fn_10_25CB0_Pair;

extern u8 lbl_10_data_68E0[];
extern u32 lbl_10_rodata_1D64;
extern s32 lbl_801A66B4;
extern u32 lbl_801A6410;
extern char * fn_80083DB0(char *, const char *);
extern void fn_1_435C(u32 value);
extern u32 fn_10_2325C(void);
extern fn_10_25CB0_Entry * fn_1_45D0(u32, u32, const char *, u32);
extern s32 fn_1_3F8C(void *, u32, void *, u32);

#pragma opt_loop_invariants off
#pragma opt_propagation on
void fn_10_25CB0(u32 arg0) {
    u8 *ptr;
    fn_10_25CB0_Entry *e;
    u8 *data;
    struct { u8 value; } c;
    struct { u32 value; } i;
    fn_10_25CB0_Pair *p;
    u32 v;
    const char * lab_t1;

    data = lbl_10_data_68E0;
    ptr = &lbl_10_bss_55CD8->unk_28;
    if (*ptr == 0) {
        if (lbl_801A66B4 == 5) {
            fn_80083DB0((char *)ptr, (const char *)data + 0x114);
        } else {
            lab_t1 = (const char *)data + 0x120;
            fn_80083DB0((char *)ptr, lab_t1);
        }
        *(u32 *)&v = lbl_10_rodata_1D64;
        fn_1_435C(lbl_10_bss_55CD8->unk_8);
        i.value = 0;
        while ((p = (fn_10_25CB0_Pair *)((u8 *)lbl_10_bss_55CD8 + 0x28 + i.value * 2))->unk_0 != 0) {
            c.value = (u8)i.value;
            e = fn_1_45D0(lbl_801A6410, 0x12, (const char *)data + 0xA0, 0xD4);
            e->unk_8 = c.value * 0x38 + 0x7E;
            e->unk_A = 0x17A;
            e->unk_0 = 2;
            e->unk_1 = 0;
            e->unk_4 = e->unk_8;
            e->unk_6 = e->unk_A;
            e->unk_2 = p->unk_0;
            e->unk_3 = p->unk_1;
            *(u32 *)((u8 *)e + 0xD) = v;
            e->unk_C = c.value;
            fn_1_3F8C(data + 0xC8, (u32)fn_10_2325C, e, 0xB);
            i.value++;
        }
        lbl_10_bss_55CD8->unk_E = (u8)i.value;
    }
    lbl_10_bss_55CD8->unk_0 |= 0x10000000;
}
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
/* fzgx:end fn_10_25CB0 */

/* fzgx:begin fn_10_25E1C */
#include "types.h"

typedef struct {
    u8 pad[0x8c];
    s16 value;
} fn_10_25E1C_NameEntryState;

typedef struct {
    s16 v[14];
} fn_10_25E1C_SndTable;

extern fn_10_25E1C_SndTable lbl_10_rodata_1D70;
extern u8 lbl_10_bss_55CE0;
extern u8 lbl_10_bss_55CE1;

void fn_10_25E1C(void) {
    fn_10_25E1C_NameEntryState *state = &(*(fn_10_25E1C_NameEntryState *)&lbl_1_bss_8B3A0);
    s32 i;
    s16 result;

    for (i = 0; i < 6; i++) {
        result = fn_1_12EF24(state->value, i);
        if (state->value == 5) {
            if (i == 5) {
                if (fn_1_F89E4(0) == 0) {
                    goto set_neg; // shared tail: retail merges both -1 arms
                }
            }
            if (i != 5) {
                if (fn_1_F89E4((u8)(i + 1)) == 0) {
                    goto set_neg; // shared tail: retail merges both -1 arms
                }
            }
            goto after_neg; // skip the merged -1 arm
        set_neg:
            result = -1;
        after_neg: ;
        }
        if (result != -1) {
            break;
        }
    }

    if (result != -1) {
        lbl_10_bss_55CE0 = (u8)result;
    } else {
        lbl_10_bss_55CE0 = (u8)fn_1_12EF24(state->value, 0);
    }

    fn_1_14A1AC(lbl_1_bss_8E51D);
    fn_1_14BC40();
    fn_1_1554D0();
    fn_1_1555B0(lbl_10_bss_55CE0);
    fn_1_47F74(0x91);
    fn_1_47F74(0x97);
    fn_1_47F74(0x99);

    for (i = 0; i < 6; i++) {
        result = fn_1_12EF24(state->value, i);
        if (result != -1) {
            u8 key = lbl_1_data_2B0D4[result];
            fn_10_25E1C_SndTable table = lbl_10_rodata_1D70;
            s16 index = lbl_1_data_2B144[key] - 1;

            if ((((u32)index > 13) ? 0 : (index >= 0)) && table.v[index] != -1) {
                fn_1_47F74(table.v[index]);
            }
        }
    }
    lbl_10_bss_55CE1 = 0;
}
/* fzgx:end fn_10_25E1C */

/* fzgx:begin fn_10_26000 */
u8 fn_10_26000(void) {
    u8 result;
    u16 flags;

    if (fn_1_B7C00()) {
        return 0;
    }

    if (lbl_10_bss_55CE1 != 0) {
        result = fn_10_26434();
        if (result == 1) {
            fn_10_26554();
            fn_1_14BD94(&lbl_10_bss_55CE0);
        }
        if (result != 0) {
            lbl_10_bss_55CE1 = 0;
        }
        return result;
    }

    flags = lbl_1_bss_9F8[4];
    if (((flags >> 11) & 1) != 0) {
        // fzgx-allow: A1 target hardware address
        fn_1_A2D84((void *)0xA9011100); // fzgx-allow: A2 target hardware address
        fn_10_26424();
        lbl_10_bss_55CE1 = 1;
    }
    fn_1_14BCBC(&lbl_10_bss_55CE0, lbl_1_bss_8B3A0[0x9e]);
    return 0;
}
/* fzgx:end fn_10_26000 */

/* fzgx:begin fn_10_260D4 */
#include "types.h"

typedef struct {
    u8 pad[0x8c];
    s16 value;
} fn_10_260D4_NameEntryState;

typedef struct {
    s16 v[14];
} fn_10_260D4_SndTable;

extern fn_10_260D4_SndTable lbl_10_rodata_1D8C;

extern void fn_1_48140(int);

void fn_10_260D4(void) {
    fn_10_260D4_NameEntryState *state = &(*(fn_10_260D4_NameEntryState *)&lbl_1_bss_8B3A0);
    s32 i;

    for (i = 5; i >= 0; i--) {
        s16 result = fn_1_12EF24(state->value, i);
        if (result != -1) {
            u8 key = lbl_1_data_2B0D4[result];
            fn_10_260D4_SndTable table = lbl_10_rodata_1D8C;
            s16 index = lbl_1_data_2B144[key] - 1;

            if ((((u32)index > 13) ? 0 : (index >= 0)) && table.v[index] != -1) {
                fn_1_48140(table.v[index]);
            }
        }
    }
    fn_1_48140(0x99);
    fn_1_48140(0x97);
    fn_1_48140(0x91);
    fn_1_15555C();
    fn_1_14BD74();
}
/* fzgx:end fn_10_260D4 */

/* fzgx:begin fn_10_261E4 */
#include "dolphin/hw_regs.h"

extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);


extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);


typedef struct { u8 r, g, b, a; } Sig_fn_800081C8_Color;
typedef Sig_fn_800081C8_Color Color;

extern u32 lbl_801A66B4;

extern Color fn_800081C8(Color, Color, f32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4D494(void);
extern void fn_1_49514(Color);
extern void fn_1_4AE0C(const char *, ...);
extern u32 fn_1_4D4C8(Color, f32, f32);
extern void fn_1_49528(Color);

/*
 * Layout stand-in for the TU's .data block at lbl_10_data_6A48: the erase-dialog
 * strings and the per-language pointer tables (question, YES, NO). The pointer
 * tables are relocations in retail; here they are zero words so the private
 * section's bytes can be proven equal and bound to the retail objects at submit.
 */
#pragma explicit_zero_data on
static char fzgx_pool_sQuestionEn[32] = "OK to erase this course record?";
static char fzgx_pool_sQuestionGe[36] = "GER OK to erase this course record?";
static char fzgx_pool_sQuestionFr[36] = "FRE OK to erase this course record?";
static char fzgx_pool_sQuestionSp[36] = "SPA OK to erase this course record?";
static char fzgx_pool_sQuestionIt[36] = "ITA OK to erase this course record?";
static char fzgx_pool_sQuestionJp[52] =
    "\x82\xB1\x82\xCC\x83\x52\x81\x5B\x83\x58\x82\xCC\x83\x8C\x83\x52\x81\x5B\x83\x68\x82\xF0\x0A"
    "\x83\x4E\x83\x8A\x83\x41\x82\xB5\x82\xC4\x82\xE0\x82\xE6\x82\xEB\x82\xB5\x82\xA2\x82\xC5\x82\xB7\x82\xA9\x3F";
static char *fzgx_pool_sEraseQuestion[6] = {0};
static char fzgx_pool_sYesEn[4] = "YES";
static char fzgx_pool_sYesGe[8] = "GER YES";
static char fzgx_pool_sYesFr[8] = "FRE YES";
static char fzgx_pool_sYesSp[8] = "SPA YES";
static char fzgx_pool_sYesIt[8] = "ITA YES";
static char fzgx_pool_sYesJp[8] = "\x82\xCD\x82\xA2";
static char *fzgx_pool_sEraseYes[6] = {0};
static char fzgx_pool_sNoEn[4] = "NO";
static char fzgx_pool_sNoGe[8] = "GER NO";
static char fzgx_pool_sNoFr[8] = "FRE NO";
static char fzgx_pool_sNoSp[8] = "SPA NO";
static char fzgx_pool_sNoIt[8] = "ITA NO";
static char fzgx_pool_sNoJp[8] = "\x82\xA2\x82\xA2\x82\xA6";
static char *fzgx_pool_sEraseNo[6] = {0};
#pragma explicit_zero_data reset

/* Literal-pool primer: reproduces the order of the TU's shared .rodata pool. */
extern void fzgx_pool_use(void *);
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_fn_10_261E4(s32 x) {
    s16 t0[14] = {0xB5, 0xB6, 0xAD, 0xB3, 0xB8, 0xB2, 0xB1, 0xAE, 0xB4, 0xB9, 0xB0, 0xAF, 0xB7, -1};
    s16 t1[14] = {0xB5, 0xB6, 0xAD, 0xB3, 0xB8, 0xB2, 0xB1, 0xAE, 0xB4, 0xB9, 0xB0, 0xAF, 0xB7, -1};
    fzgx_pool_use(t0);
    fzgx_pool_use(t1);
    fzgx_pool_use(fzgx_pool_sEraseQuestion);
    fn_1_4955C(320.0f, 240.0f);
    fn_1_4955C(0.1f, 400.0f);
    fn_1_4955C(200.0f, 13.0f);
    fn_1_4955C(26.0f, 1.5f);
    fn_1_4955C(0.75f, 0.09f);
    fn_1_4955C(0.5f, -1.0f);
    fn_1_4955C(8.0f, 0.0f);
    fn_1_4954C(x);
}

void fn_10_261E4(s32 arg0, u8 arg1) {
    Color col = fn_800081C8((Color){0xA0, 0x50, 0x50, 0x00}, (Color){0xA0, 0xA0, 0xA0, 0x00}, 1.0f);

    fn_1_49410();
    fn_1_4955C(0.75f, 0.75f);
    fn_1_4954C(0.09f);
    fn_1_495C8(9);
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_496FC(288.0f, arg0);
    fn_1_495C8(10);
    if (!arg1) {
        fn_1_4D494();
        fn_1_49514((Color){0xFF, 0xFF, 0xFF, 0x00});
        fn_1_4AE0C("%s", fzgx_pool_sEraseYes[lbl_801A66B4]);
        fn_1_4D4C8(col, 0.09f, 10.0f);
    } else {
        fn_1_49514((Color){0x70, 0x70, 0x70, 0x00});
        fn_1_49528((Color){0x00, 0x00, 0x00, 0x00});
        fn_1_4AE0C("%s", fzgx_pool_sEraseYes[lbl_801A66B4]);
    }
    fn_1_496FC(352.0f, arg0);
    fn_1_495C8(8);
    if (!arg1) {
        fn_1_49514((Color){0x70, 0x70, 0x70, 0x00});
        fn_1_49528((Color){0x00, 0x00, 0x00, 0x00});
        fn_1_4AE0C("%s", fzgx_pool_sEraseNo[lbl_801A66B4]);
    } else {
        fn_1_4D494();
        fn_1_49514((Color){0xFF, 0xFF, 0xFF, 0x00});
        fn_1_4AE0C("%s", fzgx_pool_sEraseNo[lbl_801A66B4]);
        fn_1_4D4C8(col, 0.09f, 10.0f);
    }
}
/* fzgx:end fn_10_261E4 */

/* fzgx:begin fn_10_26424 */
void fn_10_26424(void) {
    lbl_10_bss_55CE2 = 1;
}
/* fzgx:end fn_10_26424 */

/* fzgx:begin fn_10_26434 noprologue */
#include "types.h"

extern u16 lbl_1_bss_9F8[5];

typedef struct SelState {
    u8 pad0[8];
    u16 flags8;
    u8 padA[6];
    u16 flags10;
    u16 flags12;
} SelState;


extern u8 lbl_10_bss_55CE2;
extern void fn_1_A2D84(int arg);

int fn_10_26434(void) {
    if (((*(SelState *)&lbl_1_bss_9F8).flags10 & 1) ||
        ((*(SelState *)&lbl_1_bss_9F8).flags12 & 1)) {
        if (lbl_10_bss_55CE2 == 1) {
            lbl_10_bss_55CE2 = 0;
            fn_1_A2D84(0xA9011300);
        }
    }

    if (((((*(SelState *)&lbl_1_bss_9F8).flags10 >> 1) & 1)) ||
        ((((*(SelState *)&lbl_1_bss_9F8).flags12 >> 1) & 1))) {
        if (lbl_10_bss_55CE2 == 0) {
            lbl_10_bss_55CE2 = 1;
            fn_1_A2D84(0xA9011300);
        }
    }

    if ((((*(SelState *)&lbl_1_bss_9F8).flags8 >> 8) & 1)) {
        fn_1_A2D84(0xA9011100);
        if (lbl_10_bss_55CE2 == 0) {
            return 1;
        }
        if (lbl_10_bss_55CE2 == 1) {
            return 2;
        }
    }

    if ((((*(SelState *)&lbl_1_bss_9F8).flags8 >> 9) & 1)) {
        fn_1_A2D84(0xA9011000);
        return 2;
    }

    return 0;
}
/* fzgx:end fn_10_26434 */

/* fzgx:begin fn_10_266AC */
#include "font.h"

struct fn_10_266AC_pool {
    u8 pad_0[0x38];
    f32 unk_38, unk_3C, unk_40, unk_44, unk_48, unk_4C, unk_50;
    f32 unk_54, unk_58, unk_5C, unk_60, unk_64, unk_68, unk_6C;
    u8 pad_70[0x38];
    u32 unk_A8;
    f32 unk_AC, unk_B0, unk_B4;
};
extern struct fn_10_266AC_pool lbl_10_rodata_1D70;
extern FontDrawPacket lbl_1_rodata_26F8;
extern u32 lbl_801A66B4;
extern u32 fn_10_261E4(u32, u32);
extern u32 fn_1_4AEC0(u32);
extern u8 fn_1_B7C00(void);
extern void fn_1_49410(void);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AEB4(f32);
extern void fn_1_4FD64(void);
extern void fn_1_50164(void *, f32, f32, f32, f32);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800371F8(s32, void *);
extern void fn_8007245C(u32);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8, s32, u8);

void fn_10_266AC(void) {
    FontDrawPacket packet;
    u32 color;
    struct fn_10_266AC_pool *p = &lbl_10_rodata_1D70;
    u32 str;
    if (fn_1_B7C00() != 0 || lbl_10_bss_55CE1 != 0) {
    fn_1_4FD64();
    fn_80074918(0, 7, 0);
    fn_80074788(1);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 255, 255, 4);
    fn_80072C24(0, 15, 15, 15, 2);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 1);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_80072864(2);
    fn_8007245C(512);
    color = p->unk_A8;
    fn_800371F8(1, (void *)&color);
    fn_8003462C(128, 7, 4);
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_6C;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_6C;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_64;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_AC;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_6C;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_64;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_AC;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_B0;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_64;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_6C;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_B0;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_64;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    }
    if (lbl_10_bss_55CE1 != 0) {
    packet = lbl_1_rodata_26F8;
    packet.image = 2;
    packet.x = p->unk_38;
    packet.y = p->unk_3C;
    packet.z = p->unk_40;
    packet.flags = 10;
    fn_1_50164((void *)&packet, p->unk_44, p->unk_48, p->unk_4C, p->unk_50);
    str = ((u32 *)lbl_10_data_6B2C)[lbl_801A66B4];
    fn_1_4AEC0(1);
    fn_1_4AEB4(p->unk_54);
    fn_1_49410();
    fn_1_4955C(p->unk_58, p->unk_58);
    fn_1_4954C(p->unk_5C);
    fn_1_495B0(0x80000000);
    fn_1_49590(p->unk_60);
    fn_1_495C8(9);
    fn_1_496FC(p->unk_38, p->unk_B4);
    fn_1_4966C(p->unk_64, p->unk_68);
    fn_1_4A0D8((const char *)str);
    fn_1_4AEC0(0);
    fn_1_4AEB4(p->unk_6C);
    fn_10_261E4(0x118, lbl_10_bss_55CE2);
    }
}
/* fzgx:end fn_10_266AC */
