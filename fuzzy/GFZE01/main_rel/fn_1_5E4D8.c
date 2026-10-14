/* Non-matching: best partial attempt (20.37% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/effect.h"

typedef struct { f32 x, y, z; } Triple;
extern void fn_1_8636C(s32, void *);
extern void fn_1_862D4(s32, Triple *);
extern void lbl_8006DC6C(void *);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_z(s16);
extern void lbl_8006E1B0(void *, void *);
extern f32 lbl_8006D0B4(f32);
extern u8 lbl_1_bss_6C848;

extern const f32 lbl_1_rodata_2950;

typedef struct {
 u8 pad0[0x10]; s32 unk10; s32 unk14; s16 unk18;
 u8 pad1[0x3e]; s16 unk58; s16 unk5a; s16 unk5c;
 u8 pad2[0x22]; f32 unk28;
} EffectPrefix;

void fn_1_5E4D8(void *arg0)
{
 u8 *e = arg0;
 s32 special = 0;
 s32 *timer = (s32 *)(e+0x10);
 u8 mat1[0x54]; Triple pos;
 f32 trans0[3], trans1[3];
 s32 timerVal;
 f32 t;
 if (*(u16 *)(e+0xb2)==1 && *(u16 *)(*(u32 *)(e+0x38)+0x214)!=0) {
  special=1; ++*timer;
 }
 fn_1_8636C(*(s16 *)(e+0x18), mat1);
 fn_1_862D4(*(s16 *)(e+0x18), &pos);
 lbl_8006DC6C(mat1);
 if (*(u16 *)(e+0xb2)==1 && special) {
  s16 id=*(s16 *)(e+0x58);
  s32 i,j;
  u8 *base;
  s32 n;
  u8 *obj;
  s32 count,done;
  base=*(u8 **)&lbl_1_bss_6C848;
  n=0xbe;
  for (i=0;i<38;i++) {
   if ((s8)base[0] && *(s16 *)(base+4)==id) break;
   if ((s8)base[0xe8] && *(s16 *)(base+0xec)==id) break;
   if ((s8)base[0x1d0] && *(s16 *)(base+0x1d4)==id) break;
   if ((s8)base[0x2b8] && *(s16 *)(base+0x2bc)==id) break;
   if ((s8)base[0x3a0] && *(s16 *)(base+0x3a4)==id) break;
   n-=4; base+=0x488;
  }
  obj=(u8 *)lbl_1_bss_6C84C;
  count=0xc8;
  done=0;
  for (i=0;i<25 && !done;i++) {
   for (j=0;j<8;j++) {
    if ((s8)obj[0] && *(s16 *)(obj+4)==id) { done=1; break; }
    if(j!=7) { obj+=0xe8; count--; }
   }
   if (!done) { count--; obj+=0xe8; }
  }
  if(count==0) obj=0;
  if(obj) {
   lbl_8006DC6C(mat1);
   *(volatile f32 *)0xe000000c=*(f32 *)(obj+0x3c);
   *(volatile f32 *)0xe000001c=*(f32 *)(obj+0x40);
   *(volatile f32 *)0xe000002c=*(f32 *)(obj+0x44);
   switch(*(s32 *)(e+0x14)) {
   case 0: { f32 v[3]={1.2f, -1.2f, 1.2f}; (void)v; break; }
   case 1: { f32 v[3]={1.2f, -1.2f, 1.2f}; (void)v; break; }
   case 2: { f32 v[3]={1.2f, -1.2f, 1.2f}; (void)v; break; }
   }
   mathutil_mtxA_rotate_y(*(s16 *)(obj+0x56));
   mathutil_mtxA_rotate_x(*(s16 *)(obj+0x54));
   mathutil_mtxA_rotate_z(*(s16 *)(obj+0x58));
   trans0[0]=0.0f; trans0[1]=0.0f; trans0[2]=-1.2f;
   lbl_8006E1B0(trans0,e+0x88);
  }
 }
 if(!special) {
  f64 x=(f64)*(s16 *)(e+0x5a);
  *(s16 *)(e+0x5a)=(s16)((x-4503601774854144.0)*0.98f);
  x=(f64)*(s16 *)(e+0x5c);
  *(s16 *)(e+0x5c)=(s16)((x-4503601774854144.0)*0.98f);
 }
 lbl_8006DC6C(mat1);
 *(volatile f32 *)0xe000000c=pos.x;
 *(volatile f32 *)0xe000001c=pos.y;
 *(volatile f32 *)0xe000002c=pos.z;
 *(s16 *)(e+0x54)+=*(s16 *)(e+0x5a);
 *(s16 *)(e+0x56)+=*(s16 *)(e+0x5c);
 *(f32 *)(e+0x28)+=0.01f * (*(f32 *)(e+0x2c)-*(f32 *)(e+0x28));
 mathutil_mtxA_rotate_y(*(s16 *)(e+0x56));
 mathutil_mtxA_rotate_x(*(s16 *)(e+0x54));
 trans1[0]=0.0f; trans1[1]=0.0f; trans1[2]=-*(f32 *)(e+0x28);
 lbl_8006E1B0(trans1,e+0x3c);
 if(!special) {
  *(f32 *)(e+0x94)+=*(f32 *)(e+0xa0);
  *(f32 *)(e+0x98)+=*(f32 *)(e+0xa4);
  *(f32 *)(e+0x9c)+=*(f32 *)(e+0xa8);
 }
 timerVal=*timer;
 t=(f32)timerVal;
 if(t<0.0f)t=0.0f; else if(t>15.0f)t=15.0f;
 *(f32 *)(e+0xb4)=0.5f*t;
 if(timerVal<20 && !special) {
  f32 k=1.0f-(1.0f+(-0.05f*(f32)timerVal));
  *(f32 *)(e+0x1c)*=k; *(f32 *)(e+0x20)*=k; *(f32 *)(e+0x24)*=k;
 }
 if(!special) {
  f32 dx=pos.x-*(f32 *)(e+0x88), dy=pos.y-*(f32 *)(e+0x8c), dz=pos.z-*(f32 *)(e+0x90);
  f32 d=lbl_8006D0B4(dx*dx+dy*dy+dz*dz);
  if(d>50.0f) *(u8 *)e=3;
  else if(d>10.0f) { f32 k=1.0f-0.025f*(d-10.0f); *(f32 *)(e+0x1c)*=k; *(f32 *)(e+0x20)*=k; *(f32 *)(e+0x24)*=k; }
 }
}
