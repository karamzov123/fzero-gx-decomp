/* Non-matching: best partial attempt (77.25% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef enum Sig_GXInitTexObj__GXTexFmt {
 Sig_GXInitTexObj_GX_TF_I4=0, Sig_GXInitTexObj_GX_TF_I8=1,
 Sig_GXInitTexObj_GX_TF_IA4=2, Sig_GXInitTexObj_GX_TF_IA8=3,
 Sig_GXInitTexObj_GX_TF_RGB565=4, Sig_GXInitTexObj_GX_TF_RGB5A3=5,
 Sig_GXInitTexObj_GX_TF_RGBA8=6, Sig_GXInitTexObj_GX_TF_CMPR=14
} Sig_GXInitTexObj_GXTexFmt;
typedef struct Sig_GXInitTexObj__GXTexObj { u32 dummy[8]; } Sig_GXInitTexObj_GXTexObj;
typedef enum Sig_GXInitTexObj__GXTexWrapMode {
 Sig_GXInitTexObj_GX_CLAMP, Sig_GXInitTexObj_GX_REPEAT,
 Sig_GXInitTexObj_GX_MIRROR, Sig_GXInitTexObj_GX_MAX_TEXWRAPMODE
} Sig_GXInitTexObj_GXTexWrapMode;
typedef enum Sig_GXInitTexObjLOD__GXAnisotropy {
 Sig_GXInitTexObjLOD_GX_ANISO_1, Sig_GXInitTexObjLOD_GX_ANISO_2,
 Sig_GXInitTexObjLOD_GX_ANISO_4, Sig_GXInitTexObjLOD_GX_MAX_ANISOTROPY
} Sig_GXInitTexObjLOD_GXAnisotropy;
typedef u8 Sig_GXInitTexObjLOD_GXBool;
typedef enum Sig_GXInitTexObjLOD__GXTexFilter {
 Sig_GXInitTexObjLOD_GX_NEAR, Sig_GXInitTexObjLOD_GX_LINEAR,
 Sig_GXInitTexObjLOD_GX_NEAR_MIP_NEAR, Sig_GXInitTexObjLOD_GX_LIN_MIP_NEAR,
 Sig_GXInitTexObjLOD_GX_NEAR_MIP_LIN, Sig_GXInitTexObjLOD_GX_LIN_MIP_LIN
} Sig_GXInitTexObjLOD_GXTexFilter;
typedef struct Sig_GXInitTexObjLOD__GXTexObj {
 u32 texture_filter; u32 texture_lod; u32 texture_size; u32 texture_address;
 u32 user_data; u32 texture_format; u32 tlut_name;
 u16 texture_time_count; u8 texture_tile_type; u8 texture_flags;
} Sig_GXInitTexObjLOD_GXTexObj;
struct fn_800718BC_Arg2 { u8 pad_0[8]; u32 unk_8; };
extern const f32 lbl_801A7428;
extern const f32 lbl_801A7438;
extern const f64 lbl_801A7430;
extern const f64 lbl_801A7440;
extern char lbl_8015AC08[18];
extern char lbl_8015AC1C[69];
extern void OSReport(const char *, ...);
extern void GXInitTexObj(Sig_GXInitTexObj_GXTexObj *, void *, u16, u16, Sig_GXInitTexObj_GXTexFmt, Sig_GXInitTexObj_GXTexWrapMode, Sig_GXInitTexObj_GXTexWrapMode, u8);
extern void GXInitTexObjLOD(Sig_GXInitTexObjLOD_GXTexObj *, Sig_GXInitTexObjLOD_GXTexFilter, Sig_GXInitTexObjLOD_GXTexFilter, f32, f32, f32, Sig_GXInitTexObjLOD_GXBool, Sig_GXInitTexObjLOD_GXBool, Sig_GXInitTexObjLOD_GXAnisotropy);

static inline u32 fn_800717BC(u32 arg0, u32 arg1) {
 s32 i; s32 c0; s32 c1; s32 v; s32 n;
 c1=0; c0=0;
 for(i=0;i<10;i++) {
  if(arg0 & (1u<<i)) c0++;
  if(arg1 & (1u<<i)) c1++;
 }
 v=(s32)arg0;
 if(c0>1 || c1>1) return -1;
 if(v>(s32)arg1) v=(s32)arg1;
 n=0;
 while(v>4) { v=v>>1; n++; }
 return n;
}
void fn_800718BC(u32 arg0, u32 arg1, struct fn_800718BC_Arg2 *arg2) {
 u32 v1;
 u32 v2;
 s32 v5;
 s32 v7;
 u8 v10;
 u8 v23;
 u32 v25;
 s32 v29;
 s32 v30;
 v1=arg2->unk_8 + *(u32 *)((u8 *)arg1+4);
 if(*(u32 *)((u8 *)arg1+0)&0x100) {
  OSReport(lbl_8015AC08);
  *(u32 *)((u8 *)arg0+8)=0;
 } else {
  v2=*(u32 *)((u8 *)arg0+0);
  switch((s32)((v2>>2)&3)) {
   case 2: v5=2; break;
   case 1: v5=1; break;
   default: v5=0;
  }
  switch((s32)((v2>>4)&3)) {
   case 2: v7=2; break;
   case 1: v7=1; break;
   default: v7=0;
  }
  {
  u32 v8 = *(u16 *)((u8 *)arg1+8);
  u32 v9;
  s32 i, c0, c1, v, n;
  v10=(v2>>7)&15;
  v9 = *(u16 *)((u8 *)arg1+10);
  c1=0; c0=0;
  v=(s32)v8;
  for(i=0;i<10;i++) {
   if(v & (1u<<i)) c0++;
   if(v9 & (1u<<i)) c1++;
  }
  if(c0>1 || c1>1) n=-1;
  else {
   if(v>(s32)v9) v=(s32)v9;
   n=0;
   while(v>4) { v>>=1; n++; }
  }
  v23=n;
  }
  if(v23==255) {
   if(v7!=0 || v5!=0) OSReport(lbl_8015AC1C);
   v5=0; v7=0; v10=0;
  } else {
   if(v10==15 || v23<v10) v10=v23;
  }
  v2=*(u16 *)((u8 *)arg1+12);
  if((s32)v2!=-1 && (s32)v2<v10) v10=v2;
  v25=*(u32 *)((u8 *)arg1+0)&31;
  switch((s32)v25) {
   case 14: case 0: if(v10) v10--; break;
  }
  GXInitTexObj((Sig_GXInitTexObj_GXTexObj *)*(u32 *)((u8 *)arg0+8), (void *)v1, *(u16 *)((u8 *)arg1+8), *(u16 *)((u8 *)arg1+10), v25, v5, v7, v10!=0);
  *(u32 *)((u8 *)arg0+20)=v1;
  v2=*(u32 *)((u8 *)arg0+0);
  if(v2&0x800) {
   v29=0;
   if(v10) v30=4; else v30=2;
  } else {
   v29=1;
   if(v10) v30=5; else v30=3;
  }
  GXInitTexObjLOD((Sig_GXInitTexObjLOD_GXTexObj *)*(u32 *)((u8 *)arg0+8), v30, v29, lbl_801A7428, (f32)(u32)v10, (f32)(s32)*(s8 *)((u8 *)arg0+6)/lbl_801A7438, 0, (v2>>6)&1, *(u8 *)((u8 *)arg0+7));
 }
}
