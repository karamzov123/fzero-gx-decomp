/* Non-matching: best partial attempt (74.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/os.h"
typedef struct { f32 x,y,z; } Sig_fn_1_862D4_Triple;
typedef Sig_fn_1_862D4_Triple Sig_fn_1_8658C_Vec3U32;
struct fn_1_A47F4_lbl_1_rodata_45A4 { f32 unk_0; };
struct fn_1_A47F4_lbl_1_rodata_45B8 { f64 unk_0; };
struct fn_1_A47F4_lbl_1_rodata_45C0 { f32 unk_0; };
extern u8 lbl_1_bss_6F1E4[85];
extern f32 fn_1_8652C(u8);
extern f32 lbl_1_rodata_4470, lbl_1_rodata_45A0, lbl_1_rodata_45A8;
extern f32 lbl_1_rodata_45AC, lbl_1_rodata_45B0, lbl_1_rodata_45B4;
extern f32 lbl_1_rodata_45C4, lbl_1_rodata_45C8, lbl_1_rodata_45CC;
extern f32 lbl_8006D0B4(f32);
extern f64 __fabs(f64);
extern f64 lbl_1_rodata_4598;
extern s16 camera_get_mode(void);
extern s32 camera_get_state(void);
extern struct fn_1_A47F4_lbl_1_rodata_45A4 lbl_1_rodata_45A4;
extern struct fn_1_A47F4_lbl_1_rodata_45B8 lbl_1_rodata_45B8;
extern struct fn_1_A47F4_lbl_1_rodata_45C0 lbl_1_rodata_45C0;
extern void fn_1_681C(u32, void *);
extern void fn_1_6898(u32, void *);
extern void fn_1_862D4(u8, Sig_fn_1_862D4_Triple *);
extern void fn_1_8658C(u8, Sig_fn_1_8658C_Vec3U32 *);
void fn_1_A47F4(u32 arg0, u8 arg1, u32 arg2, s8 *arg3, s8 *arg4) {
    s32 v0;
    u8 v1;
    f32 v2,v3,v4,v5,v6,v7,v8,v9;
    u32 v10,v11;
    f32 unk_2,v13,v14,v15,v16;
    s16 v17;
    s32 state;
    f32 v18,v19,v20,v21,v22,unk_6,v24;
    s8 v25;
    s32 v26;
    s8 v27;
    s32 v28;
    Sig_fn_1_862D4_Triple loc_38;
    Sig_fn_1_8658C_Vec3U32 loc_2C;
    f32 loc_20[3];
    f32 loc_14[3];
    s8 loc_10,loc_C;
    u8 loc_8;
    f32 t2,t5;
    v0 = arg0 * 20;
    loc_8 = arg1;
    v1 = lbl_1_bss_6F1E4[v0+1];
    fn_1_862D4(v1, &loc_38);
    fn_1_8658C(v1, &loc_2C);
    t2 = fn_1_8652C(v1);
    fn_1_681C(arg2, loc_20);
    fn_1_6898(arg2, loc_14);
    v2 = loc_20[1] - loc_14[1];
    v3 = loc_20[2] - loc_14[2];
    t5 = lbl_8006D0B4((f32)((loc_20[0]-loc_14[0])*(loc_20[0]-loc_14[0])) + v2*v2 + v3*v3);
    v4 = loc_2C.y - loc_14[1];
    v5 = loc_38.y - loc_20[1];
    v6 = loc_2C.z - loc_14[2];
    v7 = (f32)((loc_2C.x-loc_14[0])*(loc_2C.x-loc_14[0])) + v4*v4 + v6*v6;
    v8 = lbl_1_rodata_4598 * t5;
    v9 = (f32)((loc_38.x-loc_20[0])*(loc_38.x-loc_20[0])) + v5*v5 + (loc_38.z-loc_20[2])*(loc_38.z-loc_20[2]);
    if (v9 <= v7) v10=1; else v10=0;
    if (v8 > t2) v11=1; else v11=0;
    OSu8tof32(&loc_8, &unk_2);
    v13 = lbl_1_rodata_45A4.unk_0 * unk_2;
    v14 = lbl_1_rodata_45A0 + v13;
    v18 = v8 - t2;
    v15=t2;
    if(t2 >= lbl_1_rodata_45A8) v15=lbl_1_rodata_45A8;
    v16=v8;
    if(v8 >= lbl_1_rodata_45AC) v16=lbl_1_rodata_45AC;
    v15=lbl_1_rodata_45B0-v15;
    v16=lbl_1_rodata_45B0-v16;
    v17=camera_get_mode();
    state=camera_get_state();
    if(v17==(s32)v1 && (s8)state!=9) v19=lbl_1_rodata_4470;
    else if(v11) v19=lbl_1_rodata_4470;
    else {
        v18=(f32)__fabs(v18);
        if(v18>lbl_1_rodata_45B4) v19=lbl_1_rodata_45B4/v18;
        else v19=lbl_1_rodata_4470;
    }
    v20=v14*(v16/(v15*v19));
    v20=v20-v14;
    v20=lbl_1_rodata_45C0.unk_0*(f32)(v20/lbl_1_rodata_45B8.unk_0);
    if(v20<lbl_1_rodata_45C4) v21=lbl_1_rodata_45C4;
    else if(v20>lbl_1_rodata_45C8) v21=lbl_1_rodata_45C8;
    else v21=v20;
    v22=v21;
    if(v10 | (lbl_1_bss_6F1E4[v0]&1)) *(f32 *)(lbl_1_bss_6F1E4+v0+16)=v21;
    else {
        v22=*(f32 *)(lbl_1_bss_6F1E4+v0+16)-lbl_1_rodata_4470;
        if(v22<lbl_1_rodata_45C4) v22=lbl_1_rodata_45C4;
        else if(v22>lbl_1_rodata_45C8) v22=lbl_1_rodata_45C8;
        *(f32 *)(lbl_1_bss_6F1E4+v0+16)=v22;
    }
    OSf32tos8(&v22,&loc_10);
    *arg3=loc_10;
    OSs8tof32(arg3,&unk_6);
    v24=(v22-unk_6)/lbl_1_rodata_45CC;
    OSf32tos8(&v24,&loc_C);
    *arg4=loc_C;
    v25=*arg3;
    if(v25<-3) v26=-3;
    else {v26=32; if(v25<=32) v26=v25;}
    *arg3=v26;
    v27=*arg4;
    if(v27<-64) v28=-64;
    else {v28=63; if(v27<=63) v28=v27;}
    *arg4=v28;
}
