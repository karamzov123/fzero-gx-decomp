#include "types.h"
struct fn_12_2B358_Copy64 { u32 a[17]; };
typedef struct Sig_fn_12_248D4_MovieModule {
 u32 unk_00; u8 pad_04[8]; u32 unk_0c; u8 pad_10[0x80]; u32 unk_90;
} Sig_fn_12_248D4_MovieModule;
struct Sig_fn_12_2F210_fn_12_2F210_Arg0;
struct Sig_fn_12_2F264_Movie;
extern int fn_12_24990(u32);
extern int fn_12_24A88(void *, u32);
extern int fn_12_2F210(struct Sig_fn_12_2F210_fn_12_2F210_Arg0 *, int, int, void *, int);
extern int fn_12_2F264(struct Sig_fn_12_2F264_Movie *, int);
extern void fn_12_24970(void *);
extern void fn_12_24950(void *);
extern u32 lbl_12_bss_7C64[137];
extern void fn_12_248D4(Sig_fn_12_248D4_MovieModule *);
extern void fn_12_22888(u32);
extern void *fn_12_57F0(void *, const void *, u32);
extern s32 fn_12_2BAE0(void *, s32);
extern void fn_12_21D40(void *, int, int);
static inline s32 reset_state(u32 arg0) {
 s32 result;
 if (*(s32 *)(arg0+0x48)==4) {
  result=fn_12_2F210((void *)arg0,7,7,0,0);
  if(result) return result;
 }
 *(s32 *)(arg0+0x48)=1;
 *(s32 *)(arg0+0x4c)=1;
 return 0;
}
#pragma opt_propagation off
static inline s32 reset_body(u32 arg0) {
 u32 *p_lbl_12_bss_7C64;
 s32 v0;
 s32 v6;
 s32 v3;
 struct { s32 value; } saved;
 s32 final_result;
#define v4 saved.value
 struct { u32 a[100]; } loc_6C;
 struct fn_12_2B358_Copy64 loc_28;
 struct { u32 a[7]; } loc_C;
 u32 loc_8;
 if (*(s32 *)(arg0+0x48)==1) return 0;
 v0=reset_state(arg0);
 if(v0) return v0;
 fn_12_24970(&loc_8);
 lbl_12_bss_7C64[127]=1;
 p_lbl_12_bss_7C64=lbl_12_bss_7C64;
 v4=0;
 loc_28=*(struct fn_12_2B358_Copy64 *)arg0;
 v3=*(s32 *)(arg0+0x9c0);
 if(v3) {
  if(fn_12_24990(arg0)) fn_12_24A88(0,0xff000134);
  else fn_12_2F210((void *)arg0,0,9,&loc_C,0);
  v4=loc_C.a[5];
 }
 fn_12_248D4((void *)(arg0+0x78));
 fn_12_22888(arg0);
 *(s32 *)(arg0+0x48)=0;
 *(s32 *)(arg0+0x4c)=0;
#undef v4
#define v4 final_result
 v0=fn_12_2F264((void *)arg0,4);
 if(v0) { v4=v0; goto cleanup; } /* Shared cleanup restores the module lock. */
 fn_12_57F0(&loc_6C,(void *)(arg0+0xb30),0x190);
 v6=fn_12_2BAE0(&loc_28,0);
 if(!v6) { v4=fn_12_24A88(0,0xff000202); goto cleanup; } /* Shared cleanup restores the module lock. */
 fn_12_57F0((void *)(v6+0x9a0),&loc_6C,0x190);
 fn_12_57F0((void *)(v6+0xb30),&loc_6C,0x190);
 if(v3) {
  if(fn_12_24990(v6)) v0=fn_12_24A88(0,0xff000134);
  else v0=fn_12_2F210((void *)v6,0,9,&loc_C,0);
  if(v0) { v4=v0; goto cleanup; } /* Shared cleanup restores the module lock. */
  v3=loc_C.a[5];
  if(fn_12_24990(v6)) v0=fn_12_24A88(0,0xff000135);
  else v0=fn_12_2F210((void *)v6,0,10,(void *)saved.value,v3);
  if(v0) { v4=v0; goto cleanup; } /* Shared cleanup restores the module lock. */
  if(fn_12_24990(v6)) fn_12_24A88(0,0xff000135);
  else {
   fn_12_21D40((void *)v6,*(s32 *)(v6+0x1ab4),1);
   *(s32 *)(v6+0x44)=1;
  }
 }
 v4=0;
cleanup:
 p_lbl_12_bss_7C64[127]=0;
 fn_12_24950(&loc_8);
 if(v4) return v4;
 return 0;
}
s32 fn_12_2B358(u32 arg0) {
 s32 result;
 if(fn_12_24990(arg0)) return fn_12_24A88(0,0xff000133);
 result=reset_body(arg0);
 *(s32 *)(arg0+0x44)=1;
 return result;
}
