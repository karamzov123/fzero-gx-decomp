/* Non-matching: best partial attempt (95.62% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/interview/interview.h"
typedef struct {
 u8 pad_0[8]; s16 unk_8; u8 pad_A[2]; s16 unk_C; u8 pad_E[2]; u32 unk_10; u32 unk_14; u8 pad_18[0x5C];
} Obj_17_bss_60_Local;
typedef struct {
 u8 pad_0[0xC]; u32 unk_C; u8 *unk_10; u8 pad_14[0x4C];
 Obj_17_bss_60_Local unk_60; s16 unk_D4; s16 unk_D6; u8 pad_D8[0x54];
 u32 unk_12C,unk_130,unk_134,unk_138,unk_13C,unk_140,unk_144,unk_148,unk_14C,unk_150;
 struct VecWords {u32 x,y,z;} unk_154,unk_160;
 s16 unk_16C,unk_16E;
} InterviewBss;
extern struct VecWords lbl_17_rodata_D4;
extern f32 lbl_17_rodata_E0[54];
extern u32 lbl_801A6410[1];
extern u32 lbl_1_bss_6EAB4;
extern u8 *lbl_1_bss_6EAD0[1];
extern u32 fn_1_A0680(void);
extern void fn_1_41048(void);
extern u32 fn_17_3C5C(void);
extern u32 fn_17_424C(void);
extern u32 fn_1_7BA08(u32,u32,u32);
extern s32 fn_1_45D0(u32,void *,void *,u32);
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(void *,void *,u32,u32);
extern u32 fn_1_7BA48(u32);
extern void fn_1_7BAF8(void);
extern u32 fn_17_3090(void);
extern void fn_17_71DC(void);
extern u32 fn_17_3160(void);
extern void fn_17_72BC(void);
extern void fn_17_38C4(void);
extern void fn_17_334C(void);
extern void fn_17_48D0(void);
extern u32 fn_17_49DC(void);
extern void lbl_8006D758(void);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern void lbl_8006E1B0(void *,void *);
extern void fn_80074CF4(f32,f32,f32);
extern void camera_set_state_flag(u8);
extern u32 fn_17_7F94(void);
extern u32 fn_8004CD70(u32,void *,u32);
extern u32 fn_80051E64(u32,void *,u32);
extern u32 fn_1_A1588(u32,u32);
extern u32 fn_8004BF0C(u32,u32);
extern void fn_1_154E4C(void);
extern void fn_1_C2454(void);
extern void *memset(void *,int,u32);
extern void fn_17_71C0(void *);
extern u32 fn_17_72C0(u32);

static inline void iv_set_id(Obj_17_bss_60_Local *S, s16 id) {
    S->unk_8 = id;
    S->unk_C = 0;
}
static inline void iv_set_ref(Obj_17_bss_60_Local *S, u32 v) {
    S->unk_10 = v;
    S->unk_14 = v;
}

#pragma opt_propagation off
void fn_17_2D5C(u32 arg0,u32 arg1) {
    u32 fzgx_value;
 InterviewBss *B=(InterviewBss *)&lbl_17_bss_0;
 u8 *r30;
 u8 *data=(u8 *)&lbl_17_data_0+0x60000;
    void * lab_t0;
 fzgx_value = 0;
 B->unk_12C = fzgx_value;
 B->unk_130=0; B->unk_134=0; B->unk_138=0; B->unk_13C=0; B->unk_140=0; B->unk_148=0; B->unk_144=0;
 fn_1_A0680(); fn_1_41048();
 B->unk_14C=arg0; B->unk_150=arg1;
 fn_17_3C5C(); fn_17_424C();
 r30=B->unk_10;
 B->unk_C=fn_1_45D0(*lbl_801A6410,(void *)fn_1_7BA08(0x20,0x20,0x40),data+0x3E50,0x758);
 fn_1_435C(arg0);
 lab_t0 = data+0x4004;
 fn_1_3F8C(lab_t0, (void *)fn_17_3090, 0, 5);
 fn_1_435C(arg1); fn_1_7BA48(B->unk_C);
 fn_1_3F8C(data+0x4014,(void *)fn_1_7BAF8,B->unk_C,3);
 fn_1_3F8C(data+0x4020,(void *)fn_17_71DC,0,5);
 fn_1_3F8C(data+0x4030,(void *)fn_17_3160,0,0xB);
 fn_1_3F8C(data+0x4040,(void *)fn_17_72BC,0,0xC);
 fn_1_3F8C(data+0x4050,(void *)fn_17_38C4,0,0x1C);
 fn_17_334C(); fn_17_48D0(); fn_17_49DC();
 B->unk_160=lbl_17_rodata_D4;
 B->unk_154=lbl_17_rodata_D4;
 B->unk_16C=-0x2000; B->unk_16E=0x2000;
 lbl_8006D758(); mathutil_mtxA_rotate_y(B->unk_16E); mathutil_mtxA_rotate_x(B->unk_16C);
 lbl_8006E1B0(&B->unk_154,&B->unk_160);
 fn_80074CF4(lbl_17_rodata_E0[0],lbl_17_rodata_E0[0],lbl_17_rodata_E0[0]);
 camera_set_state_flag(1); fn_17_7F94();
 { s16 v1=-0x4B; s16 v2=-0x14; B->unk_D4=v1; B->unk_D6=v2; }
 if (*(u32 *)*lbl_1_bss_6EAD0==0) {
  *(u32 *)*lbl_1_bss_6EAD0=fn_8004CD70(2,*lbl_1_bss_6EAD0+0x10,0x4A248);
 }
 if (*(u32 *)(*lbl_1_bss_6EAD0+4)==0) {
  *(u32 *)(*lbl_1_bss_6EAD0+4)=fn_8004CD70(2,*lbl_1_bss_6EAD0+0x4A258,0x4A248);
 }
 fn_80051E64(*(u32 *)(*lbl_1_bss_6EAD0+4),*lbl_1_bss_6EAD0+0x944A0,0x3000);
 lbl_1_bss_6EAB4 &= 0xFFFFFFD3;
 fn_1_A1588(*(u32 *)*lbl_1_bss_6EAD0,0x12);
 fn_8004BF0C(*(u32 *)*lbl_1_bss_6EAD0,B->unk_D4);
 fn_8004BF0C(*(u32 *)(*lbl_1_bss_6EAD0+4),B->unk_D6);
 memset(&B->unk_60,0,0x74); fn_17_71C0(&B->unk_60);
 { s16 id=r30[5];
   iv_set_id((Obj_17_bss_60_Local *)((u8 *)B+0x60), id);
   { u32 v=fn_17_72C0(id);
     iv_set_ref((Obj_17_bss_60_Local *)((u8 *)B+0x60), v); } }
 fn_1_154E4C(); fn_1_C2454();
}
#pragma opt_propagation reset
