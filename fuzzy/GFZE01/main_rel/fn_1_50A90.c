/* Non-matching: best partial attempt (24.70% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

struct fn_1_50A90_Copy88 { u32 a[22]; };
struct fn_1_50A90_lbl_1_rodata_2758 { f64 unk_0; };
struct fn_1_50A90_lbl_1_rodata_2778 { f64 unk_0; };
extern struct fn_1_50A90_lbl_1_rodata_2758 lbl_1_rodata_2758;
extern struct fn_1_50A90_lbl_1_rodata_2778 lbl_1_rodata_2778;
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

#define DRAW(SX,SY,DW,DH,X,Y) do { \
 copy = *(struct fn_1_50A90_Copy88 *)arg0; \
 fn_1_51678((FontDrawPacket *)((u8 *)&copy+4), *(u32 *)arg0, (s16)(SX), (s16)(SY), (s16)(DW), (s16)(DH)); \
 *(f32 *)((u8 *)&copy+8) = (X); \
 *(f32 *)((u8 *)&copy+12) = (Y); \
 *(u32 *)((u8 *)&copy+0x34) &= ~0xFu; \
 fn_1_4F734((FontDrawPacket *)((u8 *)&copy+4)); \
} while (0)

void fn_1_50A90(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
 struct fn_1_50A90_Copy88 copy;
 s32 dx,dy,m1,m2,ww,hh,w,h,i,nx,ny;
 f32 tw,th,ex,ey,fw,fh,x,y,x2,y2,edgeX,edgeY;
 f32 stepX,stepY,endX,endY;
 u32 fl;
 m1=((s32)((-arg1)&~arg1)>>31);
 m2=((s32)((-arg2)&~arg2)>>31);
 dx=(s32)(arg1&(u32)m1);
 dy=(s32)(arg2&(u32)m2);
 ww=dx*2; hh=dy*2;
 w=(s32)arg3>ww?(s32)arg3:ww;
 h=(s32)arg4>hh?(s32)arg4:hh;
 tw=(f32)fn_1_48690(*(u32*)arg0)-(f32)ww;
 th=(f32)fn_1_486C4(*(u32*)arg0)-(f32)hh;
 ex=(f32)(w-ww); ey=(f32)(h-hh);
 fw=tw-ex; fh=th-ey;
 fl=*(u32*)((u8*)arg0+48);
 x=*(f32*)((u8*)arg0+4); y=*(f32*)((u8*)arg0+8);
 if((fl&3)==2) x-=(f32)((w+1)/2);
 else if((fl&3)==3) x-=(f32)w;
 if(((fl>>2)&3)==2) y-=(f32)((h+1)/2);
 else if(((fl>>2)&3)==3) y-=(f32)h;
 x2=x+(f32)dx; y2=y+(f32)dy;
 edgeX=tw-(f32)(dx-1);
 edgeY=th-(f32)(dy-1);
 DRAW(0,0,dx,dy,x,y);
 DRAW(edgeX,0,dx,dy,x2,y);
 DRAW(0,edgeY,dx,dy,x,y2);
 DRAW(edgeX,edgeY,dx,dy,x2,y2);
 if(tw!=0.0f) {
   stepX=(f32)dx;
   nx=(s16)fw;
   for(i=0;i<nx;i++) {
     f32 pos=x+(f32)i*stepX;
     DRAW(fw,0,dx,dy,pos,y);
     DRAW(fw,0,dx,dy,pos,y2);
   }
   endX=x+(f32)nx*stepX;
   DRAW(fw,0,dx,dy,endX,y);
   DRAW(fw,0,dx,dy,endX,y2);
 }
 if(th!=0.0f) {
   stepY=(f32)dy;
   ny=(s16)fh;
   for(i=0;i<ny;i++) {
     f32 pos=y+(f32)i*stepY;
     DRAW(0,fh,dx,dy,x,pos);
     DRAW(0,fh,dx,dy,x2,pos);
   }
   endY=y+(f32)ny*stepY;
   DRAW(0,fh,dx,dy,x,endY);
   DRAW(0,fh,dx,dy,x2,endY);
 }
}
