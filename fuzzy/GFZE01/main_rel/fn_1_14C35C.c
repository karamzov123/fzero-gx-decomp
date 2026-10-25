/* Non-matching: best partial attempt (72.58% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"
#include "rel/main_rel/memcard.h"

typedef struct { u32 a,b; } Pair;
typedef struct {
 u8 pad0[0x600];
 u16 t0[29]; u8 p0[2];
 u16 t1[29]; u8 p1[2];
 u16 t2[33]; u8 p2[2];
 u16 t3[13]; u8 p3[2];
 u8 k0[29]; u8 p4[3];
 u8 k1[29]; u8 p5[3];
 u8 k2[33]; u8 p6[3];
 u8 k3[13]; u8 p7[3];
 Pair a; u8 p8[0x1c]; Pair b; u8 p9[0x1c]; char text[4];
} Data;
/* Extended view: the shared header currently exposes only the initial fields. */
typedef struct {
 u8 p0[8]; s32 unk_8; u8 p1[0xc]; f32 unk_18;
 u32 unk_1c; s32 unk_20; u8 p2[0xc]; u8 unk_30;
 u8 p3[0xf]; u8 unk_40,unk_41; u8 p4[0xa];
 s32 unk_4c; Pair pair; s32 unk_58,unk_5c;
 u8 text[20]; s32 unk_74,unk_78;
} State;
extern void fn_1_1556B4(u8,u8);
extern s32 fn_1_155F7C(void);
extern u32 fn_1_155F8C(void);
extern void fn_1_155FB4(char *);
extern char *fn_80083DB0(char *,const char *);
extern char *strncpy(char *,const char *,size_t);
extern size_t strlen(const char *);
extern u32 lbl_801A66B4;
static inline void clear(u8 *p) {
 u32 i;
 for(i=0;i<19;i++) *p++=0;
}
#pragma opt_propagation off
static inline u16 *lookup(Data *d,u32 c) {
 u8 *k;
 u16 *t;
 k=d->k0;
 { u32 i;
 for(i=0;i<29;i++,k++) if(c==*k) { t=d->t0; return t+i; }
 k=d->k1;
 for(i=0;i<29;i++,k++) if(c==*k) { t=d->t1; return t+i; }
 k=d->k2;
 for(i=0;i<33;i++,k++) if(c==*k) { t=d->t2; return t+i; }
 k=d->k3;
 for(i=0;i<13;i++,k++) if(c==*k) { t=d->t3; return t+i; }
 }
 return 0;
}
#pragma opt_propagation off
static inline void fn_1_14C35C_call_fn_1_1556B4(u8 a0, s8 a1) { fn_1_1556B4(a0, a1); }
void fn_1_14C35C(void) {
    u8 fzgx_value;
 State *s=(State *)&lbl_1_bss_8E518;
 Data *d=(Data *)&lbl_1_data_42878;
 u8 *src;
 u8 *dst;
 u32 buf[8];
 u32 c;
 u16 *res;
 struct {s32 value;} value;
 fzgx_value = 0;
 s->unk_40 = fzgx_value;
 s->unk_41=0;
 fn_1_14C35C_call_fn_1_1556B4(0, 0);
 s->unk_4c=0;
 if((s32)lbl_801A66B4==5) s->pair=d->a;
 else s->pair=d->b;
 clear(s->text);
 s->unk_5c=s->pair.b-1;
 s->unk_58=0;
 strncpy((char *)s->text,(char *)lbl_1_bss_718E0.pad_5522,strlen((char *)lbl_1_bss_718E0.pad_5522));
 s->unk_4c=strlen((char *)lbl_1_bss_718E0.pad_5522)>>1;
 if((s32)lbl_801A66B4!=5) {
  s->unk_4c=strlen((char *)lbl_1_bss_718E0.pad_5522);
  fn_80083DB0((char *)buf,(char *)s->text);
  src=(u8 *)buf;
  dst=s->text;
  while((c=*src)!=0) {
   if(c<128) {
    res=lookup(d,c);
    if(res) {strncpy((char *)dst,(char *)res,2); dst+=2;}
    src++;
   } else {strncpy((char *)dst,(char *)src,2); dst+=2; src+=2;}
  }
  *dst=0;
 }
 if(s->unk_4c==0) s->unk_5c=0;
 if(s->unk_8!=0) {
  if(fn_1_155F7C()!=0) {
   s->unk_8=0; s->unk_74=1;
   s->unk_78=fn_1_155F8C();
   fn_1_155FB4(d->text);
   { s32 original=s->unk_78;
   s32 test=original-2;
   lbl_1_bss_3C04=0x744;
   if(test<0) value.value=0;
   else { value.value=original-2;
    if(test>10-s->unk_30) value.value=10-s->unk_30;
   }
   }
   s->unk_20=value.value;
   s->unk_18=value.value;
  } else {
   s->unk_8=0; s->unk_74=0; lbl_1_bss_3C04=0x294;
  }
 }
}
