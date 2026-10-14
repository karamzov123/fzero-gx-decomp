/* Non-matching: best partial attempt (35.02% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/effect.h"

extern const f32 lbl_1_rodata_2950;
extern void fn_1_8636C(int, void *);
typedef struct { u32 x,y,z; } Sig_fn_1_862D4_Triple;
extern void fn_1_862D4(int, Sig_fn_1_862D4_Triple *);
struct Sig_fn_1_862A8_fn_1_862A8_Arg1 { u32 unk_0,unk_4,unk_8; };
extern u32 fn_1_862A8(u32, struct Sig_fn_1_862A8_fn_1_862A8_Arg1 *);
typedef struct { u32 x,y,z; } Sig_fn_1_8658C_Vec3U32;
extern void fn_1_8658C(int, Sig_fn_1_8658C_Vec3U32 *);
extern f32 fn_1_8652C(int);
extern u32 fn_1_3FC58(void);
extern f32 lbl_8006D0B4(f32);
extern u32 lbl_8006D5F0(u32, f32);
extern void lbl_8006DC6C(void *);
extern u32 lbl_8006E1B0(u32);
extern f32 lbl_8006D668(f32 *);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern void *memset(void *, int, u32);
extern void *memcpy(void *, const void *, u32);

typedef struct {
 u8 pad0[0x98]; s16 type; u8 pad9a[2]; s16 id; u16 seed; 
 u8 pad_a8[0x18]; f32 a8,b0,b4,b8; u8 pad_bc[4]; u32 c0;
 u8 pad_c4[4]; f32 x,y,z; u8 pad_d4[0x14];
} Packet;
typedef struct { f32 x,y,z; } V3;
static s32 randv(void) { lbl_1_data_1D628=lbl_1_data_1D628*1103515245u+12345u; return (lbl_1_data_1D628>>16)&0x7fff; }
static void submit(Packet *p) {
 int i; u8 *base=*(u8 **)&lbl_1_bss_6C848;
 for(i=0;i<190;i++) if ((s8)base[i*0xe8]==0) { base[i*0xe8]=1; break; }
 if(i==190) return;
 memcpy(base+i*0xe8,p,0xe8); base[i*0xe8]=1; *(s16 *)(base+i*0xe8+2)=i;
 ((void (**)(void *))lbl_1_data_1D1D8)[*(s16 *)(base+i*0xe8+12)](base+i*0xe8);
 *(s16 *)(base+i*0xe8+4)=lbl_1_bss_6C850.unk_0;
 if (++lbl_1_bss_6C850.unk_0<0) lbl_1_bss_6C850.unk_0=0;
}
void fn_1_662D8(void *arg0) {
 s16 id=*(s16 *)((u8 *)arg0+0x18);
 V3 loc5c, loc38, loc44, loc2c, pos, vel;
 f32 rate, mag, f;
 Packet p;
 int n=0;
 fn_1_8636C(id,&loc5c); fn_1_862D4(id,(Sig_fn_1_862D4_Triple *)&loc38);
 fn_1_862A8(id,(struct Sig_fn_1_862A8_fn_1_862A8_Arg1 *)&loc44);
 fn_1_8658C(id,(Sig_fn_1_8658C_Vec3U32 *)&loc2c);
 if (rate<100.0f) { if(randv()%3 != 0) return; } else if(randv()%3 == 0) return;
 *(f32 *)((u8 *)arg0+0x28) += 0.01f * (*(f32 *)((u8 *)arg0+0x2c)-*(f32 *)((u8 *)arg0+0x28));
 mag=lbl_8006D0B4(*(f32 *)((u8 *)arg0+0x94)* *(f32 *)((u8 *)arg0+0x94)+*(f32 *)((u8 *)arg0+0x98)* *(f32 *)((u8 *)arg0+0x98)+*(f32 *)((u8 *)arg0+0x9c)* *(f32 *)((u8 *)arg0+0x9c));
 if(mag<0) mag=0; else if(mag>0.7f) mag=0.7f;
 lbl_8006D5F0((u32)((u8 *)arg0+0x94),mag);
 lbl_8006DC6C(&loc5c);
 *(volatile f32 *)0xe000000c=loc38.x; *(volatile f32 *)0xe000001c=loc38.y; *(volatile f32 *)0xe000002c=loc38.z;
 lbl_8006E1B0((u32)&pos);
 *(V3 *)((u8 *)arg0+0x3c)=pos;
 psvec_sub(&loc38,&loc2c,(u8 *)arg0+0x48);
 if(rate<500.0f)n=1;
 if(rate>=500.0f && rate<800.0f)n=2;
 if(rate>=800.0f && rate<1000.0f)n=2;
 if(rate>=1000.0f)n=2;
 for(;n;n--) {
  memset(&p,0,sizeof(p)); p.type=29; p.id=id; p.seed=0xffff; p.a8=255; p.b0=102; p.b4=0.5f;
  p.c0=lbl_1_bss_38458->unk_8;
  p.x=pos.x; p.y=pos.y; p.z=pos.z;
  f=(f32)randv()/32767.0f;
  vel.x=loc38.x+(f-0.5f)*0.4f; vel.y=loc38.y+(f-0.5f)*0.4f; vel.z=loc38.z+(f-0.5f)*0.4f;
  p.x=vel.x; p.y=vel.y; p.z=vel.z;
  if(!fn_1_3FC58()) submit(&p);
  memset(&p,0,sizeof(p)); p.type=22; p.id=id; p.seed=0xffff; p.c0=lbl_1_bss_38458->unk_8;
  p.x=pos.x; p.y=pos.y; p.z=pos.z;
  if(!fn_1_3FC58()) submit(&p);
 }
 memset(&p,0,sizeof(p));
 lbl_8006DC6C(&loc5c);
 mathutil_mtxA_rotate_y(randv()); mathutil_mtxA_rotate_x(randv());
 p.type=16; p.id=id; p.seed=1; p.x=pos.x; p.y=pos.y; p.z=pos.z;
 if(!fn_1_3FC58()) submit(&p);
}
