#include "types.h"
#pragma use_lmw_stmw on
typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);
typedef struct Sig_fn_12_24A88_MovieObject {
 u8 pad_0000[0x48]; s32 state; u8 pad_004c[0x940];
 Sig_fn_12_24A88_MovieCallback callback; void *callback_context; s32 callback_data;
} Sig_fn_12_24A88_MovieObject;
struct fn_12_2B6B0_Copy64 { u32 a[17]; };
extern int fn_12_24990(u32);
extern int fn_12_24A88(void *, u32);
extern int fn_12_2F210(void *, int, int, u32, u32);
extern void fn_12_24970(void *);
extern void fn_12_24950(void *);
extern void fn_12_248D4(void *);
extern void fn_12_22888(u32);
extern int fn_12_2F264(void *, int);
extern void *fn_12_57F0(void *, const void *, u32);
extern u32 fn_12_2BAE0(void *, int);
extern void fn_12_21D40(void *, int, int);
extern u32 lbl_12_bss_7C64[137];

#pragma opt_propagation on
static inline void setFlag(int value) { lbl_12_bss_7C64[127]=value; }
static inline int prepare(u32 arg0) {
 if (*(int *)(arg0+0x48)==4) {
  int result=fn_12_2F210((void *)arg0,7,7,0,0);
  if (result!=0) return result;
 }
 *(int *)(arg0+0x48)=1;
 *(int *)(arg0+0x4c)=1;
 return 0;
}
int fn_12_2B6B0(u32 arg0) {
 u8 loc_6C[400];
 struct fn_12_2B6B0_Copy64 loc_28;
 u32 loc_C[7];
 u32 loc_8;
 u32 current;
 u32 *p_lbl_12_bss_7C64;
 u32 v3;
 struct { u32 value; } saved;
 u32 v5;
 u32 v6;
 u32 zero;
 int result;
 int i;
 if (fn_12_24990(arg0)) {
  return fn_12_24A88(0,0xff000131);
 }
 if (*(int *)(arg0+0x48)!=1) {
  result=prepare(arg0);
  if (result==0) {
   fn_12_24970(&loc_8);
   setFlag(1);
   p_lbl_12_bss_7C64=lbl_12_bss_7C64;
   saved.value=0;
   loc_28=*(struct fn_12_2B6B0_Copy64 *)arg0;
   v3=*(u32 *)(arg0+0x9c0);
   if ((int)v3!=0) {
    if (fn_12_24990(arg0)) fn_12_24A88(0,0xff000134);
    else fn_12_2F210((void *)arg0,0,9,(u32)loc_C,0);
    saved.value=loc_C[5];
   }
   fn_12_248D4((void *)(arg0+0x78));
   fn_12_22888(arg0);
   *(int *)(arg0+0x48)=0;
   *(int *)(arg0+0x4c)=0;
   if (fn_12_2F264((void *)arg0,4)==0) {
    fn_12_57F0(loc_6C,(void *)(arg0+0xb30),400);
    v5=fn_12_2BAE0(&loc_28,0);
    if (!v5) fn_12_24A88(0,0xff000202);
    else {
     fn_12_57F0((void *)(v5+0x9a0),loc_6C,400);
     fn_12_57F0((void *)(v5+0xb30),loc_6C,400);
     if ((int)v3!=0) {
      if (fn_12_24990(v5)) result=fn_12_24A88(0,0xff000134);
      else result=fn_12_2F210((void *)v5,0,9,(u32)loc_C,0);
      if (!result) {
       v3=loc_C[5];
       if (fn_12_24990(v5)) result=fn_12_24A88(0,0xff000135);
       else result=fn_12_2F210((void *)v5,0,10,saved.value,v3);
       if (!result) {
        if (fn_12_24990(v5)) fn_12_24A88(0,0xff000135);
        else {
         fn_12_21D40((void *)v5,*(int *)(v5+0x1ab4),1);
         *(int *)(v5+0x44)=1;
        }
       }
      }
     }
    }
   }
   p_lbl_12_bss_7C64[127]=0;
   fn_12_24950(&loc_8);
  }
 }
 fn_12_248D4((void *)(arg0+0x78));
 fn_12_22888(arg0);
 *(int *)(arg0+0x48)=0;
 *(int *)(arg0+0x4c)=0;
 result=fn_12_2F264((void *)arg0,4);
 p_lbl_12_bss_7C64=lbl_12_bss_7C64+129;
 zero=0;
 for (i=0;i<8;i++) {
  current=*p_lbl_12_bss_7C64;
  if (current==arg0) *p_lbl_12_bss_7C64=zero;
  p_lbl_12_bss_7C64++;
 }
 return result;
}
