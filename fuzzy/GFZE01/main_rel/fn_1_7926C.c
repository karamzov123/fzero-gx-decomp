/* Non-matching: best partial attempt (98.56% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/screen_effect.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x04050000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -200.0f;
    s = 1000.0f;
}
static const u32 fzgx_pool_table3[3] = {0x006E9600, 0x08050000, 0xC3480000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2000.0f;
}
static const u32 fzgx_pool_table5[3] = {0x0A0A2800, 0x07040000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3000.0f;
}
static const u32 fzgx_pool_table7[3] = {0x171A1D00, 0x0C020000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 820.0f;
}
static const u32 fzgx_pool_table9[3] = {0x6E787900, 0xFF040000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
}
static const u32 fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.03125f;
    s = 1.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 0.01666666753590107f;
}
static const u32 fzgx_pool_table13[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f32 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 640.0f;
    s = 480.0f;
    s = 320.0f;
    s = 240.0f;
    s = 0.029999999329447746f;
    s = 0.75f;
    s = 0.019999999552965164f;
    s = 1.5f;
    s = 360.0f;
    s = 128.0f;
    s = 0.5f;
    s = 8.0f;
    s = 408.0f;
}
#pragma section code_type ".text"
typedef struct Sig_fn_80036070_Fn80036070Data {
 u32 flags; u8 pad_04[4]; u32 dimensions; u32 scaled_value;
 u8 pad_10[4]; u32 value_14; u8 pad_18[7]; u8 enabled;
} Sig_fn_80036070_Fn80036070Data;
typedef struct { u32 words[22]; } Sig_fn_1_51914_fn_1_51914_state;
struct fn_1_7926C_lbl_1_data_1DFB0_0_E28 { f32 unk_0; u8 pad_4[0x18]; };
struct fn_1_7926C_lbl_1_rodata_3278 {
 u8 pad_0[0x54]; f32 unk_54; u8 pad_58[8]; f64 unk_60;
 u8 pad_68[4]; u32 unk_6C;
 f32 unk_70;
 f32 unk_74;
 f32 unk_78;
 f32 unk_7C;
 f32 unk_80;
 f32 unk_84;
 f32 unk_88;
 f32 unk_8C;
 f32 unk_90;
 f32 unk_94;
 f32 unk_98;
 f32 unk_9C;
 f32 unk_A0;
 f32 unk_A4;
};
const u8 lbl_1_rodata_3278[80] = {0x04,0x05,0x00,0x00,0xC3,0x48,0x00,0x00,0x44,0x7A,0x00,0x00,0x00,0x6E,0x96,0x00,0x08,0x05,0x00,0x00,0xC3,0x48,0x00,0x00,0x44,0xFA,0x00,0x00,0x0A,0x0A,0x28,0x00,0x07,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x45,0x3B,0x80,0x00,0x17,0x1A,0x1D,0x00,0x0C,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x4D,0x00,0x00,0x6E,0x78,0x79,0x00,0xFF,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x42,0xC8,0x00,0x00,0x00,0x00,0x00,0x00};
const u8 lbl_1_rodata_32C8[4] = {0x3D,0x00,0x00,0x00};
const f32 lbl_1_rodata_32CC = 1.0f;
const u8 lbl_1_rodata_32D0[8] = {0x43,0x30,0x00,0x00,0x80,0x00,0x00,0x00};
const f64 lbl_1_rodata_32D8 = 4503599627370496.0;
const u8 lbl_1_rodata_32E0[4] = {0x3C,0x88,0x88,0x89};
const f32 lbl_1_rodata_32E0__fzgx_offset_8 = 0.0f;
const f32 lbl_1_rodata_32E0__fzgx_offset_C = 640.0f;
const f32 lbl_1_rodata_32E0__fzgx_offset_10 = 480.0f;
const f32 lbl_1_rodata_32E0__fzgx_offset_14 = 320.0f;
const f32 lbl_1_rodata_32E0__fzgx_offset_18 = 240.0f;
const f32 lbl_1_rodata_32E0__fzgx_offset_1C = 0.0299999993f;
const f32 lbl_1_rodata_32E0__fzgx_offset_20 = 0.75f;
const f32 lbl_1_rodata_32E0__fzgx_offset_24 = 0.0199999996f;
const f32 lbl_1_rodata_32E0__fzgx_offset_28 = 1.5f;
const f32 lbl_1_rodata_32E0__fzgx_offset_2C = 360.0f;
const f32 lbl_1_rodata_32E0__fzgx_offset_30 = 128.0f;
const f32 lbl_1_rodata_32E0__fzgx_offset_34 = 0.5f;
const f32 lbl_1_rodata_32E0__fzgx_offset_38 = 8.0f;
const f32 lbl_1_rodata_32E0__fzgx_offset_3C = 408.0f;
const u8 lbl_1_rodata_32E0__fzgx_offset_40[12] = {0x42,0xC8,0x00,0x00,0x34,0x00,0x00,0x00,0x40,0x00,0x00,0x00};
extern u32 lbl_1_rodata_26F8;
extern f32 fn_8006F774(f32,f32);
extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_1_D07E0(f32,f32,f32);
extern u32 fn_80038EEC(f32,f32,f32,f32,f32,f32);
extern u8 fn_80074188(u32,u32,u32,u32);
extern void fn_1_4E638(s32);
extern void fn_1_51914(const Sig_fn_1_51914_fn_1_51914_state *);
extern void fn_1_51990(void *);
extern void fn_80036070(const Sig_fn_80036070_Fn80036070Data *,u32 *,u16 *,u16 *,u32 *,u32 *,u32 *,u8 *);
extern void fn_8006F120(void *,void *);
#pragma opt_propagation off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Obj_1_bss_6D778_At0 *fzgx_obj_lbl_1_bss_6D778;
u32 lbl_1_bss_6D778_fill_6D77C[11];
u32 fzgx_obj_lbl_1_bss_6D7A8[6];
u32 lbl_1_bss_6D7C0[10];
u32 fzgx_obj_lbl_1_bss_6D7E8[2];
u8 fzgx_obj_lbl_1_bss_6D7F0;
u8 lbl_1_bss_6D778_gap_6D7F1;
u16 lbl_1_bss_6D778_gap_6D7F1_fill_6D7F2;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D778;
    s = *(u8 *)&lbl_1_bss_6D778_fill_6D77C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7A8;
    s = *(u8 *)&lbl_1_bss_6D7C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7E8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7F0;
    s = *(u8 *)&lbl_1_bss_6D778_gap_6D7F1;
    s = *(u8 *)&lbl_1_bss_6D778_gap_6D7F1_fill_6D7F2;
}
#pragma section code_type ".text"

f32 fn_1_7926C(u32 arg0) {
 struct fn_1_7926C_lbl_1_rodata_3278 *p_lbl_1_rodata_3278;
 f32 v0;
 f32 v2;
 f32 v3;
 f32 v1;
 f32 v5;
 Obj_1_bss_6D778_At0 *v4;
 f32 v6;
 f32 v7;
 f32 v8;
 f32 v9;
 f32 v12;
 f32 v13;
 f32 v14;
 f32 v15;
 f32 v16;
 f32 v17;
 struct { s16 value; } v18;
 struct fn_1_7926C_lbl_1_data_1DFB0_0_E28 *entry;
 FontDrawPacket loc_7C;
 Sig_fn_1_51914_fn_1_51914_state loc_24;
 u32 loc_20;
 u32 loc_1C;
 u32 loc_18;
 u32 loc_14;
 u32 loc_10;
 u16 loc_C;
 u16 loc_A;
 u16 loc_8;
 
 v0=lbl_1_rodata_32E0__fzgx_offset_8;
 fn_80038EEC(v0,v0,lbl_1_rodata_32E0__fzgx_offset_C,lbl_1_rodata_32E0__fzgx_offset_10,v0,lbl_1_rodata_32CC);
 fn_80074188(0,0,640,480);
 fn_1_4E638(0);
 if ((s32)arg0 != 0) {
 loc_7C=*(FontDrawPacket *)&lbl_1_rodata_26F8;
 v1=lbl_1_rodata_32E0__fzgx_offset_14;
 v2=loc_7C.z+lbl_1_rodata_32E0__fzgx_offset_1C;
 v3=lbl_1_rodata_32E0__fzgx_offset_18;
 loc_7C.image=0x9458;
 loc_7C.x=v1; loc_7C.y=v3; loc_7C.z=v2;
 loc_7C.alpha=lbl_1_rodata_32E0__fzgx_offset_20;
 fn_1_4F734(&loc_7C);
 }
 v4=fzgx_obj_lbl_1_bss_6D778;
 if (v4->unk_18>1) {
 fn_80036070((const Sig_fn_80036070_Fn80036070Data *)(v4->unk_24+32),&loc_1C,&loc_C,&loc_A,&loc_18,&loc_14,&loc_10,(u8 *)&loc_8);
 loc_1C+=0x80000000;
 loc_24=*(Sig_fn_1_51914_fn_1_51914_state *)&lbl_1_rodata_26F8;
 v5=lbl_1_rodata_32E0__fzgx_offset_8;
 *(f32 *)((u8 *)&loc_24+4)=v5;
 *(f32 *)((u8 *)&loc_24+8)=v5;
 *(f32 *)((u8 *)&loc_24+12)+=lbl_1_rodata_32E0__fzgx_offset_24;
 loc_24.words[12]|=0x800000;
 loc_24.words[16]=loc_18;
 *(u16 *)((u8 *)&loc_24+68)=loc_C;
 *(u16 *)((u8 *)&loc_24+70)=loc_A;
 loc_24.words[18]=loc_1C;
 }
 fn_80036070((const Sig_fn_80036070_Fn80036070Data *)fzgx_obj_lbl_1_bss_6D778->unk_24,&loc_20,&loc_C,&loc_A,&loc_18,&loc_14,&loc_10,(u8 *)&loc_8);
 loc_20+=0x80000000;
 loc_7C=*(FontDrawPacket *)&lbl_1_rodata_26F8;
 if ((s32)arg0!=0) {
 v8=lbl_1_rodata_32E0__fzgx_offset_28;
 loc_7C.scale_x=v8;
 v6=lbl_1_rodata_32E0__fzgx_offset_10;
 loc_7C.scale_y=v8;
 v7=lbl_1_rodata_32E0__fzgx_offset_2C+(f32)(lbl_1_rodata_32E0__fzgx_offset_30*(f32)(lbl_1_rodata_32E0__fzgx_offset_34*v8));
 } else {
 v9=lbl_1_rodata_32CC;
 loc_7C.scale_x=v9;
 v7=lbl_1_rodata_32E0__fzgx_offset_3C;
 loc_7C.scale_y=v9;
 v6=(lbl_1_rodata_32E0__fzgx_offset_C-(f32)(lbl_1_rodata_32E0__fzgx_offset_30*(f32)(lbl_1_rodata_32E0__fzgx_offset_34*v9)))-lbl_1_rodata_32E0__fzgx_offset_38;
 }
 v12=lbl_1_rodata_32E0__fzgx_offset_34*(f32)(u32)loc_C;
 v13=(f32)(u32)loc_A;
 v14=v12*loc_7C.scale_x;
 v15=v13*loc_7C.scale_y;
 v6=v6-v14;
 v7=v7-v15;
 loc_7C.x=v6; loc_7C.y=v7;
 loc_7C.z+=lbl_1_rodata_32E0__fzgx_offset_24;
 loc_7C.flags=(loc_7C.flags|0x800000);
 loc_7C.format=loc_18;
 loc_7C.width=loc_C; loc_7C.height=loc_A;
 loc_7C.pixels=(void *)loc_20;
 *(u32 *)((u8 *)&loc_7C+56)=fzgx_pool_table13[0];
 if(fzgx_obj_lbl_1_bss_6D778->unk_18>1) {
 fn_1_51914(&loc_24); fn_1_51990(&loc_7C);
 }
 fn_1_4F734(&loc_7C);
 v18.value=lbl_1_data_1DFA4.unk_8;
 entry=(struct fn_1_7926C_lbl_1_data_1DFB0_0_E28 *)((u8 *)&lbl_1_data_1DFB0+(((u32)v18.value<46?(u32)v18.value:0)*28));
 fn_8006F120((u8 *)entry+4,(u8 *)entry+16);
 fn_8006F774((f32)(u32)loc_C*loc_7C.scale_x,(f32)(u32)loc_A*loc_7C.scale_y);
 fn_1_D07E0(entry->unk_0,v6,v7);
 return fn_8006F774(lbl_1_rodata_32E0__fzgx_offset_C,lbl_1_rodata_32E0__fzgx_offset_10);
}
#pragma opt_propagation reset

