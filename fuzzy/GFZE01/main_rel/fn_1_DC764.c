/* Non-matching: best partial attempt (95.54% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 0.6499999761581421f;
    s = 0.75f;
    s = 1.0f;
    s = 0.0f;
    s = 182.04444885253906f;
    d = 0.5;
    d = 2.0;
    d = 4503599627370496.0;
    s = 0.8500000238418579f;
    s = 0.15000000596046448f;
    s = 65536.0f;
    s = 60.0f;
    s = 30.0f;
    s = 5.0f;
    s = -5.0f;
    s = 0.10000000149011612f;
    s = 90000.0f;
    s = -0.10000000149011612f;
    d = 1.0;
    d = 3.0;
    s = 3.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
#pragma section code_type ".text"
struct Sig_fn_1_862A8_fn_1_862A8_Arg1 { u32 unk_0; u32 unk_4; u32 unk_8; };
typedef struct Sig_fn_80015EE8_Fn80015EE8Out { f32 f0,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15; } Sig_fn_80015EE8_Fn80015EE8Out;
struct Sig_fn_800737E4_fn_800737E4_Arg0 { f32 unk_0; u8 pad_4[4]; f32 unk_8,unk_C; u8 pad_10[4]; f32 unk_14,unk_18,unk_1C; u8 pad_20[8]; f32 unk_28,unk_2C; };
struct Sig_fn_80072270_fn_80072270_Arg0 { f32 unk_0,unk_4,unk_8,unk_c,unk_10,unk_14,unk_18; };
struct fn_1_DC764_Arg0 { u8 pad_0[8]; void *unk_8; };
extern f32 lbl_1_rodata_66D0[30];
extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(u32);
extern f32 lbl_8006D6FC(void *,void *);
extern f64 __fabs(f64);
extern void fn_80074A6C(void);
extern s16 camera_get_mode(void);
extern s32 fn_1_5910(void);
extern void fn_1_862A8(u32,struct Sig_fn_1_862A8_fn_1_862A8_Arg1 *);
extern void *fn_1_8627C(s32);
extern void fn_1_869B0(int,u32 *);
extern void fn_1_681C(u32,u32 *);
extern void fn_1_6914(u32,u32 *);
extern void fn_1_556B8(void *);
extern void fn_1_56000(u8,u8,u8);
extern void fn_1_560F0(s32,void *);
extern void fn_1_5621C(f32,f32,f32,f32);
extern void C_MTXOrtho(Sig_fn_80015EE8_Fn80015EE8Out *,f32,f32,f32,f32,f32,f32);
extern void GXGetProjectionv(f32 *);
extern void fn_80072558(void);
extern void fn_80072B7C(u32);
extern void fn_800737E4(struct Sig_fn_800737E4_fn_800737E4_Arg0 *,s32);
extern void fn_80074A60(u32,u32);
extern void lbl_8006DB74(void *);
extern void fn_80072270(struct Sig_fn_80072270_fn_80072270_Arg0 *);
extern void lbl_8006D7F4(f32,f32,f32);
extern void lbl_8006D860(f32,f32,f32);
#pragma opt_common_subs off
void fn_1_DC764(struct fn_1_DC764_Arg0 *arg0) {
    void *v0;
    void *v1;
    s32 t0;
    s32 v2;
    s8 v10;
    f32 v7,v11,v15,v22,v28,v29;
    Sig_fn_80015EE8_Fn80015EE8Out loc_9C;
    struct { u32 a[12]; } loc_6C;
    struct Sig_fn_80072270_fn_80072270_Arg0 loc_50;
    f32 loc_44[3],loc_38[3],loc_2C[3],loc_20[3];
    struct Sig_fn_1_862A8_fn_1_862A8_Arg1 loc_14;
    f32 loc_8[3];
    v0 = arg0->unk_8;
    v1 = *(void **)((u8 *)v0+0x2260);
    t0 = fn_1_5910();
    v2 = camera_get_mode();
    if (v2 != -1 && *(s16 *)((u8 *)(v0 = (u8 *)v0+t0*2)+0x2264)>0) {
        fn_1_869B0(v2,(u32 *)loc_20);
        fn_1_862A8(v2,&loc_14);
        { f32 v9 = (f32)(loc_20[0]* *(f32 *)&loc_14.unk_4) - loc_20[1]* *(f32 *)&loc_14.unk_0;
          f32 v5 = (f32)(loc_20[2]* *(f32 *)&loc_14.unk_0) - loc_20[0]* *(f32 *)&loc_14.unk_8;
          f32 v6 = (f32)(loc_20[1]* *(f32 *)&loc_14.unk_8) - loc_20[2]* *(f32 *)&loc_14.unk_4;
          loc_8[0] = v6;
          loc_8[1] = v5;
          loc_8[2] = v9;
        }
        v7 = *(f32 *)((u8 *)fn_1_8627C(v2)+0x108);
        fn_1_681C((u8)t0,(u32 *)loc_44);
        fn_1_6914((u8)t0,(u32 *)loc_38);
        loc_2C[0]=loc_38[0]-loc_44[0];
        loc_2C[1]=loc_38[1]-loc_44[1];
        loc_2C[2]=loc_38[2]-loc_44[2];
        v11=lbl_8006D6FC(loc_20,loc_2C);
        if(v11>0.0f) v10=1; else v10=-1;
        v15=lbl_8006D6FC(loc_8,loc_2C);
        { f32 v16=0.15f*lbl_8006D188((s32)(65536.0f*(lbl_801A66A0%60)/60.0f));
          f32 v19=(0.85f+v16)*0.5f;
          f32 v21=0.0f+v19*__fabs(v11);
          v22=v21* *(s16 *)((u8 *)v0+0x2264)/30.0f;
        }
        GXGetProjectionv((f32 *)&loc_50);
        C_MTXOrtho(&loc_9C,5.0f,-5.0f,-5.0f,5.0f,0.1f,90000.0f);
        fn_800737E4((struct Sig_fn_800737E4_fn_800737E4_Arg0 *)&loc_9C,1);
        lbl_8006D7F4(0.0f,0.0f,-0.1f);
        fn_80072558();
        fn_1_5621C(v22,v22,v22,1.0f);
        fn_80074A60(1,1);
        v28=-((f32)v10*(v15+v7/60.0f));
        lbl_8006D860(1.0/(1.0+(f64)(3.0*__fabs(v28))),1.0f,1.0f);
        v29=0.0f;
        if(v28>0.0f) {} else v29=-(3.0f*v28);
        { f32 *v4=(f32 *)0xE0000000;
          f32 v30=v4[0]*v29+v4[3];
          f32 v31=v4[4]*v29+v4[7];
          f32 v34=v4[8]*v29+v4[11];
          v4[3]=v30; v4[7]=v31; v4[11]=v34;
        }
        fn_80072B7C(0);
        fn_1_56000(1,3,0);
        lbl_8006DB74(&loc_6C);
        fn_1_560F0(0,&loc_6C);
        fn_1_556B8(v1);
        fn_80072B7C(1);
        fn_1_56000(1,3,1);
        fn_1_5621C(1.0f,1.0f,1.0f,1.0f);
        fn_80074A6C();
        fn_80072270(&loc_50);
    }
}
#pragma opt_common_subs reset

