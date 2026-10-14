/* Non-matching: best partial attempt (94.42% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/effect.h"
typedef union { f32 f; u32 u; } F32U;
typedef struct { F32U x,y,z; } Vec3;
typedef struct {
 u8 pad_0[8]; u32 unk_8; u8 pad_C[4]; s32 unk_10; u8 pad_14[4]; s16 unk_18; u8 pad_1A[2];
 F32U unk_1C,unk_20,unk_24,unk_28; u8 pad_2C[16]; Vec3 unk_3C; u8 pad_48[12];
 s16 unk_54,unk_56,unk_58,unk_5A,unk_5C; u8 pad_5E[0x56]; F32U unk_B4;
} Arg0;
typedef struct { u8 pad[0x475]; u8 unk_475; } T1;
extern const u32 lbl_1_rodata_2950;
#define PF(off) ((off)==8 ? 32767.0f : (off)==0x28 ? 1.0f : (off)==0x50 ? 0.0f : (off)==0x54 ? 0.5f : (off)==0x5c ? 255.0f : (off)==0x64 ? 0.2f : (off)==0x70 ? 0.98f : (off)==0x19c ? 85.0f : (off)==0x1a0 ? -0.05f : (off)==0x21c ? 0.8f : -3.0f)
#define PD(off) (0.5)
extern u32 fn_1_86514(int);
extern T1 *fn_1_86254(int);
extern void fn_1_862D4(int,Vec3 *);
extern void fn_1_8636C(int,void *);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(Vec3 *,Vec3 *);
extern int fn_1_6EC0(u8);
extern s16 camera_get_entry_field_0xa4(u32);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
static void set_translation(Vec3 *v) {
 f32 z=v->z.f,y=v->y.f,x=v->x.f;
 *(f32 *)(0xE0000000+12)=x;
 *(f32 *)(0xE0000000+28)=y;
 *(f32 *)(0xE0000000+44)=z;
}
void fn_1_5F654(Arg0 *arg0) {
 const u32 *pool=&lbl_1_rodata_2950;
 T1 *t1;
 Vec3 loc_38;
 u8 loc_44[0x34];
 Vec3 loc_2C,loc_20;
 if (((fn_1_86514(arg0->unk_18)>>27)&1) && ((arg0->unk_8>>18)&1)) arg0->unk_10++;
 else {
  arg0->unk_5A=(s16)((f32)arg0->unk_5A*PF(0x70));
  arg0->unk_5C=(s16)((f32)arg0->unk_5C*PF(0x70));
  arg0->unk_8 &= ~0x40000;
 }
 t1=fn_1_86254(arg0->unk_18);
 fn_1_862D4(arg0->unk_18,&loc_38);
 fn_1_8636C(arg0->unk_18,loc_44);
 lbl_8006DC6C(loc_44);
 set_translation(&loc_38);
 if ((s8)t1->unk_475!=-1 && fn_1_6EC0(t1->unk_475)!=0 && camera_get_entry_field_0xa4(t1->unk_475)==0) {
  Vec3 t;
  t.x.u=pool[0x228/4]; t.y.u=pool[0x22c/4]; t.z.u=pool[0x230/4];
  t.z.f=PF(0x240); loc_20=t;
  lbl_8006E1B0(&loc_20,&loc_20);
  set_translation(&loc_20);
 }
 arg0->unk_54+=arg0->unk_5A;
 arg0->unk_56+=arg0->unk_5C;
 mathutil_mtxA_rotate_y(arg0->unk_56);
 mathutil_mtxA_rotate_x(arg0->unk_54);
 {
  Vec3 t;
  t.x.u=pool[0x234/4]; t.y.u=pool[0x238/4]; t.z.u=pool[0x23c/4];
  t.z.f=PD(0x48)*-arg0->unk_28.f;
  loc_2C=t;
 }
 lbl_8006E1B0(&loc_2C,&arg0->unk_3C);
 {
  u32 r; f32 f;
  arg0->unk_B4.f=PF(0x54)*(f32)arg0->unk_10;
  r=lbl_1_data_1D628*0x41C64E6D+0x3039; lbl_1_data_1D628=r;
  r=(r>>16)&0x7fff;
  f=PF(0x21c)+(f32)(PF(0x64)*((f32)r/PF(8)));
  arg0->unk_1C.f=(PF(0x5c)*(PF(0x54)*(PF(0x28)+f)))/PF(0x5c);
  arg0->unk_20.f=(PF(0x19c)*f)/PF(0x5c);
  arg0->unk_24.f=PF(0x50);
  if (lbl_1_data_2A7E0.unk_0==6) {
   arg0->unk_1C.f*=PF(0x64); arg0->unk_20.f*=PF(0x64); arg0->unk_24.f*=PF(0x64);
  }
  if(arg0->unk_10<20) {
   f32 sc=PF(0x28)-(PF(0x28)+(f32)(PF(0x1a0)*(f32)arg0->unk_10));
   arg0->unk_1C.f*=sc; arg0->unk_20.f*=sc; arg0->unk_24.f*=sc;
  }
 }
}
