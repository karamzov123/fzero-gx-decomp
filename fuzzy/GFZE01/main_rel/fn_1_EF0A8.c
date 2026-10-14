/* Non-matching: best partial attempt (94.89% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct { f32 x,y,z; } Sig_fn_1_F143C_Vec3;
typedef struct {
 u32 field_0; s16 field_4,field_6; u8 _pad8[0x74];
 Sig_fn_1_F143C_Vec3 field_7c; u8 _pad88[0x64]; u8 _pad_ec[0x60];
 u8 field_14c[0xb4]; f32 field_200; u8 _pad204[0x20]; f32 field_224;
 u8 _pad228[0x24d]; u8 field_475;
} Sig_fn_1_F143C_FnObject;
struct fn_1_EF0A8_Copy16 { u32 a[4]; };
struct fn_1_EF0A8_State {
    u8 pad_0[18]; u16 v; };
struct fn_1_EF0A8_lbl_1_bss_7B180 {
 u8 pad_0[0x10]; s32 unk_10; u8 pad_14[4]; u32 unk_18;
 u8 pad_1C[0x16c8]; u32 unk_16E4,unk_16E8;
 u8 pad_16EC[0x62]; u8 unk_174E; u8 pad_174F[0xd1]; u32 unk_1820;
};
extern struct fn_1_EF0A8_lbl_1_bss_7B180 lbl_1_bss_7B180;
extern u32 lbl_1_data_3E52C;
extern s16 lbl_1_bss_960;
extern s32 fn_1_3F164(void);
extern const f64 lbl_1_rodata_6B68;
extern void fn_1_159440(s32,s32);
extern void fn_1_48418(s32);
extern void fn_1_EE530(void);
extern void fn_1_F0B5C(u32,void *);
extern void fn_1_F0D10(u32,u32);
extern void fn_1_F0E00(u32,void *);
extern void fn_1_F143C(Sig_fn_1_F143C_FnObject *,s32,const f32 *,const f32 *,void *);
extern void fn_1_F190C(s32);
extern void fn_80008BEC(void *,int,u32);
#pragma opt_dead_assignments off
static inline f32 * *fn_1_EF0A8_array_read(f32 * *array) { return array; }
void fn_1_EF0A8(void) {
 struct fn_1_EF0A8_lbl_1_bss_7B180 *p_lbl_1_bss_7B180 = (struct fn_1_EF0A8_lbl_1_bss_7B180 *)&lbl_1_bss_7B180;
 u8 *v18=(u8 *)p_lbl_1_bss_7B180+0x38c4;
 u8 *v17=(u8 *)p_lbl_1_bss_7B180+0x39b4;
 u8 *v16=((0x39f0) + ((u8 *)p_lbl_1_bss_7B180));
 u16 *v13=(u16 *)((u8 *)p_lbl_1_bss_7B180+0x1800);
 u8 *v12=(u8 *)p_lbl_1_bss_7B180+0x3a04;
 u8 *v11=(u8 *)p_lbl_1_bss_7B180+0x3af4;
 u8 *v10=(u8 *)p_lbl_1_bss_7B180+0x19c8;
 struct { u32 value; } v9;
 u32 v29;
 u32 v25;
 u32 v30;
 struct { u32 value; } v34;
 struct fn_1_EF0A8_Copy16 *v35;
 u32 v36;
 u32 v32;
 struct { u32 value; } v39;
 u8 *v24;
 struct { u32 value; } v33;
 for(v9.value=0; v9.value<p_lbl_1_bss_7B180->unk_174E; v9.value++) {
  fn_1_F0D10(v9.value,(u32)(v18+v9.value*48));
  fn_1_F0B5C(v9.value,v17+v9.value*12);
  fn_1_F0E00(v9.value,v16+v9.value*4);
  if(fn_1_3F164()==0) {
   u16 v19=v13[v9.value];
{
 f32 **v15=(f32 **)((u8 *)p_lbl_1_bss_7B180+0x1600);
{
 u32 *v14=(u32 *)((u8 *)p_lbl_1_bss_7B180+0x1824);
   if((f32)(u32)v19 < fn_1_EF0A8_array_read(v15)[v9.value][v14[v9.value]-1]) v13[v9.value]=v19+1;
}
}
  }
  fn_1_F0D10(v9.value,(u32)(v12+v9.value*48));
  fn_1_F0B5C(v9.value,((v9.value*12) + (v11)));
  fn_1_F143C((Sig_fn_1_F143C_FnObject *)(v10+v9.value*0x620),v9.value,(f32 *)(v11+v9.value*12),(f32 *)(v17+v9.value*12),v12+v9.value*48);
 }
 fn_1_EE530();
{
 u32 v23;
 v23=p_lbl_1_bss_7B180->unk_1820;
 v25=0;
 v24=(u8 *)p_lbl_1_bss_7B180->unk_16E8;
 for(v34.value=0;v34.value<v23;v34.value++) {
  if(*v24!=0) v25++;
  v24++;
 }
 v29=v23+1;
}
 for(v30=1;v30<=40;v29++,v30++) {
  u32 v27=v25+v29/v30;
  if(((v27+1)*16)<16000) break;
 }
 if(v30>40) p_lbl_1_bss_7B180->unk_10=1;
 else if(v30!=1) {
  v34.value=0; v33.value=0; v36=0; v32=0;
  v35=(struct fn_1_EF0A8_Copy16 *)p_lbl_1_bss_7B180->unk_16E4;
  while(v34.value<p_lbl_1_bss_7B180->unk_1820) {
   if(v34.value%v30==0 || ((u8 *)p_lbl_1_bss_7B180->unk_16E8)[v34.value]!=0) {
    v32++;
    *v35=*(struct fn_1_EF0A8_Copy16 *)((u8 *)p_lbl_1_bss_7B180->unk_16E4+v33.value);
    *(u8 *)v35=v36;
    v36=0;
    v35++;
   }
   v34.value++;
   v36+=*((u8 *)p_lbl_1_bss_7B180->unk_16E4+v33.value);
   v33.value+=16;
  }
  for(v39.value=0;v39.value<p_lbl_1_bss_7B180->unk_1820;v39.value++) ((u8 *)p_lbl_1_bss_7B180->unk_16E8)[v39.value]=0;
  p_lbl_1_bss_7B180->unk_1820=v32;
 }
 {
  p_lbl_1_bss_7B180->unk_18=0;
  if((p_lbl_1_bss_7B180->unk_10)!=0) lbl_1_data_3E52C=9;
  else {
  fn_80008BEC((u8 *)p_lbl_1_bss_7B180+0x3b34,0,72);
  fn_1_F190C(0); fn_1_F190C(1);
  {
  struct fn_1_EF0A8_State *v42=(struct fn_1_EF0A8_State *)((u8 *)p_lbl_1_bss_7B180+0x3b34);
  s16 mode=lbl_1_bss_960;
  v42->v=0;
  lbl_1_data_3E52C=12;
  if(mode!=2) {
   fn_1_48418(2); fn_1_159440(2,0);
  }
  }
 }
 }
}
#pragma opt_dead_assignments reset
