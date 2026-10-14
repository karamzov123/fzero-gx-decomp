/* Non-matching: best partial attempt (44.39% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/effect_car.h"

typedef struct { u8 pad[0x18]; s16 mode; } Car;
typedef struct {
 u8 pad0[0x1c]; f32 f1c; u8 p20[4]; f32 f24; u8 p28[0x10]; f64 f38,f40; f32 f48; u8 p4c[4]; f64 f50; u8 p58[0x1c]; f32 f74; u8 p78[0x18]; f32 f90,f94; u8 p98[0x14]; f32 fac; u8 pb0[8]; f32 fb8; u8 pbc[0x14]; f64 fd0; u8 pd8[0xc]; f32 fe4; u8 pe8[8]; f32 ff0; u8 pf4[0x14]; f64 f108; u8 p110[0x10]; f64 f120; u8 p128[0x38]; f64 f160; u8 p168[0xc]; u32 f174,f178,f17c; f32 f180,f184; f64 f188,f190,f198,f1a0,f1a8,f1b0; f32 f1b8; u8 p1bc[4]; f64 f1c0; f32 f1c8; u8 p1cc[4]; f64 f1d0; f32 f1d8,f1dc; f64 f1e0,f1e8,f1f0,f1f8;
} Pool;
extern Pool lbl_1_rodata_2D70;
extern u8 fn_1_8652C(s16);
extern u32 fn_1_584AC(void);
extern u8 fn_1_58C4(void);
extern s16 camera_get_mode(void);
extern s16 fn_1_58F50(const void *);
extern u32 lbl_801A66A0;
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *);
extern void _savegpr_27(void);
extern void _restgpr_27(void);

void fn_1_6C87C(Car *car, f32 *delta, f32 arg2) {
 Pool *p = &lbl_1_rodata_2D70;
 u8 buf[0xe8]; u32 loc[3], rnd, n, r;
 f32 speed, t, a, bound, div, other, prev, step, z2, z;
 f64 low, high, init, x, y, q, k;

 speed = fn_1_8652C(car->mode);
 rnd = fn_1_584AC() & 0xffff;
 if (rnd % 3 == 0) {
  if (fn_1_58C4() < 2 && car->mode != camera_get_mode() && (lbl_801A66A0 & 1)) goto done;
  if (speed < p->fac) { if ((fn_1_584AC() & 0xffff) % 3 != 0) goto done; }
  else if (((fn_1_584AC() << 30) & 0xffffffff) == 0) goto done;
  __builtin_memset(buf,0,sizeof(buf));
  *(s16 *)(buf+0x18)=car->mode; *(s16 *)(buf+0xc)=13; *(s16 *)(buf+0x1a)=-1;
  loc[0]=p->f174; loc[1]=p->f178; loc[2]=p->f17c;
  *(u32 *)(buf+0x34)=lbl_1_bss_38458->unk_8;
  lbl_8006DC6C((u8 *)car+0xb8);
  *(f32 *)0xE000000c=*(f32 *)((u8 *)car+0x3c);
  *(f32 *)0xE000001c=*(f32 *)((u8 *)car+0x40);
  *(f32 *)0xE000002c=*(f32 *)((u8 *)car+0x44);
  lbl_8006E1B0(loc);
  n=0;
  if(speed<p->fe4)n=1;
  if(speed>=p->fe4 && speed<p->f180)n=2;
  if(speed>=p->f180 && speed<p->f184)n=3;
  if(speed>=p->f184)n=5;
  t=speed/p->f1b8; a=arg2/p->f1c8;
  low=p->f1b0; high=p->f1b0; bound=speed/p->f1b8;
  div=speed/p->f1dc; other=speed/p->f1d8;
  prev=(f32)(p->f1a0-p->f1a8*arg2);
  init=(f32)(p->f1f8+speed/p->f184);
  x=p->f190+p->f198*arg2; y=p->f1b0-speed/p->f1b8;
  q=p->f188*speed; k=p->f1b0;
  while(n--) {
   *(u32 *)(buf+0x3c)=loc[0]; *(u32 *)(buf+0x40)=loc[1]; *(u32 *)(buf+0x44)=loc[2];
   *(u32 *)(buf+0x48)=*(u32 *)((u8 *)car+0x48);
   *(u32 *)(buf+0x4c)=*(u32 *)((u8 *)car+0x4c);
   *(u32 *)(buf+0x50)=*(u32 *)((u8 *)car+0x50);
   r=fn_1_584AC()&0xffff;
   *(s32 *)(buf+0x10)=(s32)(p->fb8*(p->f74+p->ff0*((f32)r/p->f24)));
   z=y; if(z<low)z=low; else if(z>high)z=high;
   *(s32 *)(buf+0x10)=(s32)(p->f24*z);
   z2=bound;
   if(z2<0.2f)z2=0.2f; else if(z2>p->f50){} else {}
   step=(f32)(-a+z2);
   *(f32 *)(buf+0x48)+=step*((f32)(fn_1_584AC()&0xffff)/p->f24-(f32)p->fd0);
   *(f32 *)(buf+0x50)+=step*((f32)(fn_1_584AC()&0xffff)/p->f24-(f32)p->fd0);
   *(f32 *)(buf+0x48)+=delta[0]*other;
   *(f32 *)(buf+0x4c)+=delta[1]*other;
   *(f32 *)(buf+0x50)+=delta[2]*other;
   *(f32 *)(buf+0x3c)-=*(f32 *)(buf+0x48);
   *(f32 *)(buf+0x40)-=*(f32 *)(buf+0x4c);
   *(f32 *)(buf+0x44)-=*(f32 *)(buf+0x50);
   *(f32 *)(buf+0x34)=prev+0.5f;
   *(f32 *)(buf+0x28)=speed*(p->f1c*0.5f)/p->f48;
   *(f32 *)(buf+0x2c)=*(f32 *)(buf+0x28);
   *(f32 *)(buf+0x30)=speed*(p->f90+p->f94)/p->f48;
   *(f32 *)(buf+0x9c)=p->f1f0*((f32)(fn_1_584AC()&0xffff)/p->f24);
   *(s16 *)(buf+0xac)=0x222;
   fn_1_58F50(buf);
  }
 }
done:;
}
