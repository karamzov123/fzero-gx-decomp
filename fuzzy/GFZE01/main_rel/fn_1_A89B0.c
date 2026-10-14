/* Non-matching: best partial attempt (97.40% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -0.10000000149011612f;
    s = 0.10000000149011612f;
    s = 5.0f;
    s = 0.5f;
    s = 50.0f;
    s = 10.0f;
    s = 57.2957763671875f;
    s = -10.0f;
    s = 0.20000000298023224f;
    s = -30.0f;
    s = 1.8518518209457397f;
    s = -1.8518518209457397f;
    s = 4.166666507720947f;
    s = 25.0f;
    s = 30.0f;
    s = 182.04444885253906f;
    s = 0.46296295523643494f;
    s = 1.0f;
    s = 15.0f;
    s = 45.0f;
    s = -45.0f;
    s = 0.75f;
    s = 0.05000000074505806f;
    s = -0.05000000074505806f;
    s = -60.0f;
    s = 0.019999999552965164f;
    s = 2.0f;
}
#pragma section code_type ".text"
struct fn_1_A89B0_Arg1 { u8 pad_0[0x1fc]; f32 unk_1FC; };
struct fn_1_A89B0_lbl_1_rodata_4A28 {
 f32 unk_0; u8 pad_4[0x34]; f32 unk_38; u8 pad_3C[4]; f32 unk_40;
 u8 pad_44[0x18]; f32 unk_5C, unk_60, unk_64, unk_68, unk_6C;
};
extern struct fn_1_A89B0_lbl_1_rodata_4A28 lbl_1_rodata_4A28;
extern void *lbl_801A6D00;
extern void lbl_8006DAEC(void);
extern void mathutil_mtxA_rotate_x(u32);
extern void lbl_8006DFC4(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006D758(void);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006E0B4(f32,f32,f32);
extern void lbl_8006DBAC(void *);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D668(void *);
extern void fn_1_44884(void *);
extern void lbl_8006E1F0(void *, f32, f32, f32);
extern void lbl_8006DB30(void);

#pragma opt_lifetimes on
#pragma opt_common_subs off
#pragma opt_dead_assignments off
#pragma opt_loop_invariants off
void fn_1_A89B0(void *arg0, struct fn_1_A89B0_Arg1 *arg1, s32 arg2) {
 struct fn_1_A89B0_lbl_1_rodata_4A28 *p_lbl_1_rodata_4A28;
 void *v1;
 f32 v2;
 f32 *v3;
 s32 v4;
 struct { f32 value; } v6;
 s32 v5;
 struct { f32 value; } v7;
 struct { f32 a[3], b[3], c[3], d[3]; } vectors;
    f32 lab_t2;
 f32 v29;
 f32 v14;
#define loc_8 vectors.a
#define loc_14 vectors.b
#define loc_20 vectors.c
#define loc_2c vectors.d
 f32 v8;
 f32 v9;
 f32 v10;
 f32 v11;
 f32 v13;
 f32 v15;
 f32 v17;
 f32 v19;
 f32 v18;
 f32 v20;
 f32 v21;
 void *v23;
 void *v24;
 f32 v25;
 f32 v26;
 f32 v27;
 f32 v28;
 f32 v30;
 f32 v31;
 f32 v32;
 f32 v33;
 f32 v34;
 f32 v35;
 f32 v36;
 f32 v38;
 f32 v39;

 f32 t9;
 f32 t12;
 p_lbl_1_rodata_4A28 = &lbl_1_rodata_4A28;
{
 f32 v0;
 if (arg1 != 0) v0 = arg1->unk_1FC;
 else v0 = (0.0f);
 if (arg2 != 0) {
  v8 = (0.0f);
  v1 = (u8 *)arg0 + 48;
  v2 = (0.0500000007f);
  v3 = (f32 *)((u8 *)arg0 + 192);
  v4 = 3; v5 = 4;
  if (v0 > v8) { v6.value=v0; v7.value=v8; }
  else { v6.value=v8; v7.value=v0; }
 } else {
  v9=(0.0f);
  v1=(u8 *)arg0+96;
  v2=(-0.0500000007f);
  v3=(f32 *)((u8 *)arg0+204);
  v4=5; v5=6;
  if (v0 > v9) { v6.value=v9; v7.value=v0; }
  else { v6.value=v0; v7.value=v9; }
 }
 lbl_8006DAEC();
 v10=(182.044449f);
 mathutil_mtxA_rotate_x((s32)(v10*(f32)((25.0f)*v7.value)));
 lbl_8006DFC4(v1);
 v11=(182.044449f);
 mathutil_mtxA_rotate_x((s32)(v11*(f32)((25.0f)*v6.value)));
 v1=(u8 *)arg0+v4*48+300;
 lbl_8006DB74(v1);
 lbl_8006D758();
 v25=v3[0]; v13=v3[1]; v14=v3[2]; v15=(-60.0f);
 *(f32 *)(0xE0000000+0x0C)=v25;
 *(f32 *)(0xE0000000+0x1C)=v13;
 *(f32 *)(0xE0000000+0x2C)=v14;
 {
 struct { f32 x,y,z; } t;
 t.x=*(f32 *)(0xE0000000+0x00);
 t.y=*(f32 *)(0xE0000000+0x10);
 t.z=*(f32 *)(0xE0000000+0x20);
 t.x=t.x*v2+*(f32 *)(0xE0000000+0x0C);
 t.y=t.y*v2+*(f32 *)(0xE0000000+0x1C);
 t.z=t.z*v2+*(f32 *)(0xE0000000+0x2C);
 *(f32 *)(0xE0000000+0x0C)=t.x;
 *(f32 *)(0xE0000000+0x1C)=t.y;
 *(f32 *)(0xE0000000+0x2C)=t.z;
 }
 mathutil_mtxA_rotate_z((s32)(((182.044449f))*(f32)(v15*v0)));
 lbl_8006E0B4(-v2,(0.0f),(0.0199999996f));
 psvec_set(loc_2c,*(f32 *)(((0x2C) + (0xE0000000))),*(f32 *)(0xE0000000+0x1C),*(f32 *)(0xE0000000+0x0C));
 v23=(u8 *)arg0+(((48) * (v5)))+300;
 lbl_8006DBAC(v1);
 v24=lbl_801A6D00;
 v25=loc_2c[0]-*(f32 *)((u8 *)v24+12); loc_20[0]=v25;
 v26=loc_2c[1]-*(f32 *)((u8 *)v24+28); loc_20[1]=v26;
 v27=loc_2c[2]-*(f32 *)((u8 *)v24+44); loc_20[2]=v27;
 v31=(f32)(v25*v25);
 v31=v26*v26+v31;
 v31=v27*v27+v31;
 v0=lbl_8006D0B4(v31);
 lbl_8006D668(loc_20);
 fn_1_44884(loc_20);
 v28=*(f32 *)((u8 *)arg0+268);
 v29=v28*v28;
 v30=v29-(f32)(*(f32 *)((u8 *)arg0+272)**(f32 *)((u8 *)arg0+272));
 v7.value=(f32)(v30+(f32)(v0*v0))/(f32)((2.0f)*v0);
}
 if(v28>v7.value) {
  v32=v29-(f32)(v7.value*v7.value);
  t12=lbl_8006D0B4(v32); v32=t12;
 } else {
  v32=(0.0f); v7.value=v28;
 }
 lab_t2 = -v32;
 lbl_8006E1F0(loc_14, v7.value, lab_t2, (0.0f));
 v35=*(f32 *)((u8 *)v1+12)+loc_14[0];
 v34=*(f32 *)((u8 *)v1+28)+loc_14[1];
 v36=*(f32 *)((u8 *)v1+44)+((2)[loc_14]);
 loc_8[0]=v35; loc_8[1]=v34; loc_8[2]=v36;
 lbl_8006D668(loc_14); fn_1_44884(loc_14);
 lbl_8006DB74(v1);
 v38=loc_2c[0]-loc_8[0]; v39=loc_2c[1]-loc_8[1];
 loc_14[0]=v38; loc_14[1]=v39; loc_14[2]=loc_2c[2]-loc_8[2];
 lbl_8006D668(loc_14); fn_1_44884(loc_14);
 v35=loc_8[0]; v34=loc_8[1];
 *(f32 *)(0xE0000000+0x0C)=v35;
 v36=loc_8[2];
 *(f32 *)(0xE0000000+0x1C)=v34;
 *(f32 *)(0xE0000000+0x2C)=v36;
 lbl_8006DB74(v23); lbl_8006DB30();
}
#pragma opt_loop_invariants reset

#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

#pragma opt_lifetimes reset

