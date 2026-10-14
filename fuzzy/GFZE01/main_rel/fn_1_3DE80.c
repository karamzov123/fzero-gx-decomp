/* Non-matching: best partial attempt (52.53% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/game.h"
typedef struct { f32 x,y,z; } Vec3;
struct Pool {
 u8 p0[4]; f32 z; u8 p8[4]; f32 one; u8 p10[0x20]; f32 half; u8 p34[4]; f32 sixteen;
 u8 p3c[12]; f32 fifty; u8 p4c[4]; f64 d52; u8 p58[0xd8]; f32 sixty;
 u8 p134[4]; f64 bias; u8 p140[0x18]; f32 quarter; u8 p15c[0x20]; f32 x320,y240;
 u8 p184[8]; f32 forty; f32 thirty; u8 p194[0x48]; f32 three; u8 p1e0[0xa0];
 u32 color1,color2; f32 scale600, neg60, neg1, thirty5, neg11, three5, neg10, width640,height480, six5;
};
extern struct Pool lbl_1_rodata_BD8;
extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_98590(void); extern void fn_1_59290(void); extern void fn_1_3FC68(s32);
extern void fn_1_DCF54(Vec3 *,Vec3 *,Vec3 *);
extern u16 fn_1_48690(u32); extern u16 fn_1_486C4(u32);
extern int fn_1_4F734(FontDrawPacket *); extern int fn_1_402D4(void); extern void fn_1_3F2A0(void);
extern void fn_1_4A00(s32,u8,void *); extern void fn_1_469BC(void); extern void fn_1_8DBA4(u8);
extern u8 lbl_1_data_5B84;
void fn_1_3DE80(void) {
 u8 *base=&lbl_1_bss_3C00;
 u8 *mgr=base+0x20000;
 struct Pool *p=&lbl_1_rodata_BD8;
 u32 n=*(u32 *)(mgr+0x3028), i, j; f32 t, alpha; u16 w, h; Vec3 a,b,c; FontDrawPacket packet; u8 *obj,*entry,*bytes,*index,*record,*tab; u8 count,slot,value;
 fn_1_98590(); fn_1_59290(); fn_1_3FC68(0);
 t=(f32)((s32)*(u32 *)(mgr+0x3028))/p->scale600;
 if(t>p->one)t=p->one;
 a.x=p->thirty+p->neg60*t; a.y=p->three+p->neg1*t; a.z=p->thirty5+p->neg11*t;
 b.x=p->sixteen+p->three5*t; b.y=p->three+p->neg10*t; b.z=p->three+p->neg10*t;
 c.x=p->z; c.y=p->one; c.z=p->z;
 fn_1_DCF54(&a,&b,&c);
 n=*(u32 *)(mgr+0x3028)+1; *(u32 *)(mgr+0x3028)=n; if((s32)n>1200)*(u32 *)(mgr+0x3028)=1200;
 packet=*(FontDrawPacket *)lbl_1_rodata_26F8;
 packet.image=18; packet.x=p->x320; packet.y=p->y240;
 w=fn_1_48690(18); packet.scale_x*=p->width640/(f32)w;
 h=fn_1_486C4(packet.image);
 packet.scale_y*=p->height480/(f32)h;
 alpha=p->quarter*(f32)((s32)*(u32 *)(mgr+0x3028)-240)/p->sixty;
 if(alpha<p->z) alpha=p->z; else if(alpha>p->one) alpha=p->one;
 packet.alpha=alpha; packet.z=p->sixty; packet.flags=10; *(u32 *)((u8 *)&packet+0x40)=p->color1;
 fn_1_4F734(&packet);
 packet=*(FontDrawPacket *)lbl_1_rodata_26F8;
 packet.image=0x8a01; packet.x=p->x320; packet.y=p->y240;
 alpha=p->quarter*(f32)((s32)*(u32 *)(mgr+0x3028)-240)/p->sixty;
 packet.scale_x*=p->six5; packet.scale_y*=p->three;
 if(alpha<p->z)alpha=p->z;else if(alpha>p->one)alpha=p->one;
 packet.alpha=alpha; packet.z=p->fifty; packet.flags=10; *(u32 *)((u8 *)&packet+0x40)=p->color2;
 fn_1_4F734(&packet);
 packet=*(FontDrawPacket *)lbl_1_rodata_26F8;
 packet.image=0x8a00; packet.x=p->x320; packet.y=p->y240;
 alpha=p->half*(f32)((s32)*(u32 *)(mgr+0x3028)-60)/p->sixty;
 if(alpha<p->z)alpha=p->z;else if(alpha>p->one)alpha=p->one;
 packet.alpha=alpha; packet.z=p->forty; packet.flags=10;
 fn_1_4F734(&packet);
 if(*(u32 *)(mgr+0x1fa0)==0 && (s32)*(u32 *)(mgr+0x3028)>60 && fn_1_402D4()!=0 && *(u32 *)(mgr+0x1fa0)==0) {
  obj=base+0x30;
  *(u16 *)(base+0x17f4)=obj[7];
  if(obj[5]==0) {
   count=obj[8];
   for(i=0;i<count;i++) {
    u8 *entry=obj+((*(s16 *)(base+0x2a)>41)?0xdc:0x157)+i*0xa0;
    if(*(u32 *)(entry+0x1480)==0) continue;
    if((*(u32 *)(base+0x30)&0x400000)!=0) break;
    fn_1_3F2A0();
    bytes=base+0x163c;
    index=base+0x165c;
    for(j=0;j<count;j++) {
     slot=entry[(j*0x40)+( *(s16 *)(base+0x2a)>41 ? 0xdc:0x157)];
     value=bytes[j];
     record=base+0x165c+slot*8;
     record[4]=entry[(j*0x40)+0x154]; record[6]=value;
     index[0x194+slot]=(u8)(j+1);
    }
    tab=base+0x165c;
    tab[0x191]|=2; tab[0x192]=count; tab[0x190]=obj[7];
    *(u32 *)(base+0x30)|=0x400000;
    *(u16 *)(base+0x17f4)=14;
    break;
   }
  }
  fn_1_4A00(0,30,*(void **)(base+0x1500));
  *(u32 *)(mgr+0x1fa0)=1;
  lbl_1_bss_6EAB4.unk_0|=0x2c;
  if(obj[5]==0)lbl_1_data_5B84=1;
  fn_1_469BC(); fn_1_8DBA4(0);
 }
}
