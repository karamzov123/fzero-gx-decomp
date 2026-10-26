/* Non-matching: best partial attempt (87.27% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 0.0f;
    s = 1.0f;
    s = -5.0f;
    s = 10.0f;
}
#pragma section code_type ".text"

struct fn_1_15248_lbl_1_rodata_6C8 {
    u8 pad_0[0x8]; f32 unk_8; u8 pad_C[0x4]; f32 unk_10; f32 unk_14;
};
struct fn_1_15248_lbl_801A66CC { u32 unk_0; };
extern f32 fn_1_1FFA0(void *, void *, void *, void *, void *, void *);
extern f32 lbl_8006D668(void *);
extern struct fn_1_15248_lbl_1_rodata_6C8 lbl_1_rodata_6C8;
extern struct fn_1_15248_lbl_801A66CC lbl_801A66CC;
extern u32 lbl_801A6D00;
extern void lbl_8006DF44(void);
extern void lbl_8006E1B0(void *, void *);

#pragma opt_common_subs on
#pragma opt_strength_reduction off
s32 fn_1_15248(void *arg0, void *arg1, void *arg2, s16 arg3, f64 arg4) {
    struct fn_1_15248_lbl_1_rodata_6C8 *p_lbl_1_rodata_6C8;
    f32 v5;
    s16 v23;
    f32 v7;
    f32 v8;
    struct { f32 value; } v9;
    f32 v10;
    u32 v0;
    s32 v15;
    f32 v6;
    s32 v37;
    void *v14, *v16, *v22, *v24, *v38;
    f32 v17;
    f32 v35;
    s8 v36;
    struct { f32 a[12]; } loc_50;
    f32 loc_44[3];
    f32 loc_38[3];
    f32 loc_2C[3];
    f32 loc_20[3];
    u32 loc_14[3];
    u32 loc_8[3];
    p_lbl_1_rodata_6C8 = &lbl_1_rodata_6C8;
    if (arg3 > 4) return 0;
    psvec_sub((u8 *)arg2+28, (u8 *)arg2+16, loc_44);
    v5=*(f32 *)((u8 *)arg2+4);
    v6=*(f32 *)((u8 *)arg2+12);
    v7=*(f32 *)((u8 *)arg2+8);
    v8=(f32)(loc_44[2]*v5)-loc_44[0]*v6;
    v9.value=(f32)(loc_44[1]*v6)-loc_44[2]*v7;
    v10=(f32)(loc_44[0]*v7)-loc_44[1]*v5;
    loc_38[1]=v8;
    loc_38[0]=v9.value;
    loc_38[2]=v10;
    loc_44[2]=(f32)(v5*v8)-v7*v9.value;
    loc_44[12]=(f32)(v6*v9.value)-v5*v10;
    loc_44[0]=(f32)(v7*v10)-v6*v8;
    lbl_8006D668(loc_44);
    lbl_8006D668(loc_38);
    v0=lbl_801A6D00;
    *(f32 *)(v0+0)=loc_44[0];
    *(f32 *)(v0+4)=*(f32 *)((u8 *)arg2+4);
    *(f32 *)(v0+8)=loc_38[0];
    *(f32 *)(v0+12)=*(f32 *)arg0;
    *(f32 *)(v0+16)=loc_44[1];
    *(f32 *)(v0+20)=*(f32 *)((u8 *)arg2+8);
    *(f32 *)(v0+24)=loc_38[1];
    *(f32 *)(v0+28)=*(f32 *)((u8 *)arg0+4);
    *(f32 *)(v0+32)=loc_44[2];
    *(f32 *)(v0+36)=*(f32 *)((u8 *)arg2+12);
    *(f32 *)(v0+40)=loc_38[2];
    *(f32 *)(v0+44)=*(f32 *)((u8 *)arg0+8);
    lbl_8006DF44();
{
    s32 v18;
    v18=0;
    v14=(u8 *)arg2+16;
    v16=&loc_50;
    {
    s32 fzgx_loop_v15_2124;
for(fzgx_loop_v15_2124=0;fzgx_loop_v15_2124<arg3;fzgx_loop_v15_2124++) {
      lbl_8006E1B0(v14,v16);
      v17=-*(f32 *)((u8 *)v16+4);
      if(-5.0f<=v17 && v17<=10.0f) v18=1;
      v16=(u8 *)v16+12;
      v14=(u8 *)v14+12;
    }
    v15 = fzgx_loop_v15_2124;
}
    if(!v18) return 0;
}
    v22=(u8 *)arg2+16;
    v24=(u8 *)v22+arg3*12;
    {
    s32 fzgx_loop_v23_2390;
for(fzgx_loop_v23_2390=0;fzgx_loop_v23_2390<arg3;fzgx_loop_v23_2390++) {
      psvec_sub(arg0,v22,(void *)(lbl_801A66CC.unk_0+212));
      v0=lbl_801A66CC.unk_0;
      if (((f32)(*(f32 *)(v0+212)* *(f32 *)v24)+*(f32 *)(v0+216)* *(f32 *)((u8 *)v24+4))+((*(f32 *)((u8 *)v24+8)) * (*(f32 *)(v0+220)))<(0.0f)) break;
      v22=(u8 *)v22+12;
      v24=(u8 *)v24+12;
    }
    v23 = fzgx_loop_v23_2390;
}
    if(v23==arg3) return 1;
    loc_2C[0]=loc_2C[1]=loc_2C[2]=(0.0f);
    lbl_8006E1B0(arg1,loc_20);
    v35=(0.0f);
    arg4=arg4*arg4;
    v36=arg3-1;
    loc_20[1]=v35;
    loc_50.a[1]=v35;
    v38=&loc_50;
    for(v37=0;v37<arg3;v37++) {
      s32 next=(v37+1)&~((s32)~((v37-v36)|(v36-v37))>>31);
      void *v39=(u8 *)&loc_50+next*12;
      *(f32 *)((u8 *)v39+4)=v35;
      if(fn_1_1FFA0(loc_2C,loc_20,v38,v39,loc_14,loc_8)<arg4) return 1;
      v38=(u8 *)v38+12;
    }
    return 0;
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset

