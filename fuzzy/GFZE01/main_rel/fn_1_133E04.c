/* Non-matching: best partial attempt (50.66% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct { f32 x,y,z; } Vec3;
typedef struct { u8 pad[0x30]; u32 unk30; f32 unk34; u8 tail[0x20]; } Font;
extern u32 lbl_1_rodata_877C[3], lbl_1_rodata_8788[3], lbl_1_bss_38460[21], lbl_801A66A0;
extern f32 lbl_1_rodata_861C,lbl_1_rodata_863C,lbl_1_rodata_8678,lbl_1_rodata_86C4,lbl_1_rodata_86D0,lbl_1_rodata_8770,lbl_1_rodata_87A4,lbl_1_rodata_87A8,lbl_1_rodata_87AC,lbl_1_rodata_87B0,lbl_1_rodata_87B4,lbl_1_rodata_87B8,lbl_1_rodata_87BC,lbl_1_rodata_87C0,lbl_1_rodata_87C4,lbl_1_rodata_87C8,lbl_1_rodata_87CC,lbl_1_rodata_87D0,lbl_1_rodata_87D4,lbl_1_rodata_87D8,lbl_1_rodata_87DC,lbl_1_rodata_87E0,lbl_1_rodata_87E4,lbl_1_rodata_87E8,lbl_1_rodata_87EC,lbl_1_rodata_87F0,lbl_1_rodata_87F4,lbl_1_rodata_87F8,lbl_1_rodata_87FC,lbl_1_rodata_8800,lbl_1_rodata_8804,lbl_1_rodata_8808,lbl_1_rodata_880C,lbl_1_rodata_8818,lbl_1_rodata_881C,lbl_1_rodata_8820,lbl_1_rodata_8824,lbl_1_rodata_8828,lbl_1_rodata_85F0,lbl_1_rodata_8658,lbl_1_rodata_8674;
extern f64 lbl_1_rodata_8600,lbl_1_rodata_8608,lbl_1_rodata_8810;
extern u32 lbl_1_rodata_8794,lbl_1_rodata_8798,lbl_1_rodata_879C,lbl_1_rodata_87A0,lbl_1_rodata_26F8[22];
extern void fn_8006F038(Vec3*,Vec3*,s16),lbl_8006DCDC(void),fn_80074D08(u32),fn_1_A714C(f32*,f32*,f32*,f32*),fn_1_A7024(f32,f32,f32,f32),fn_1_56000(u8,u8,u8),fn_1_55FF0(f32),fn_1_556B8(void*),fn_80072558(void),fn_800749B0(s32,void*),fn_1_4E724(Font*),fn_1_52088(void),fn_1_52070(u32);
extern u32 lbl_8006DCA4(void),lbl_8006E0C8(u32); extern void lbl_8006E0A4(void*),lbl_8006E13C(void*);
extern u32 lbl_8006D7F4(f32,f32,f32),lbl_8006DB74(u32);
extern f32 fn_1_A6FE8(void),fn_80088598(f32,f32);
extern s32 fn_1_A5DC4(void); extern u16 fn_1_48690(u32),fn_1_486C4(u32);
static void draw(f32 *a,f32*b,u32*c,f32 s,void*obj) { lbl_8006DCA4(); lbl_8006E0A4(a); lbl_8006E13C(b); lbl_8006E0C8((u32)c); fn_80072558(); fn_1_55FF0(s); if(obj) fn_1_556B8(obj); }
void fn_1_133E04(void *arg0,u32 arg1) {
 Vec3 a,b; f32 p14,p10,pC,p8,aa[3],bb[3],lim; u32 cc[3],loc[13],t; u32 *base=(u32*)lbl_1_bss_38460,*q; s32 i; Font f; f32 z,v,w,h; *(u32 *)&a.x=lbl_1_rodata_877C[0]; *(u32 *)&a.y=lbl_1_rodata_877C[1]; *(u32 *)&a.z=lbl_1_rodata_877C[2]; *(u32 *)&b.x=lbl_1_rodata_8788[0]; *(u32 *)&b.y=lbl_1_rodata_8788[1]; *(u32 *)&b.z=lbl_1_rodata_8788[2];
 base=(u32*)lbl_1_bss_38460;
 fn_8006F038(&a,&b,0); lbl_8006DCDC(); fn_80074D08(0); fn_1_A714C(&p14,&p10,&pC,&p8); fn_1_A7024(lbl_1_rodata_87A4,lbl_1_rodata_87A8,lbl_1_rodata_87AC,lbl_1_rodata_87B0); fn_1_56000(0,7,0);
 aa[0]=lbl_1_rodata_861C; aa[1]=lbl_1_rodata_87B4; aa[2]=lbl_1_rodata_86D0; bb[0]=bb[1]=bb[2]=lbl_1_rodata_87B8;
 q=(u32*)*(u32*)((u8*)*(u32*)((u8*)*(u32*)(base+1)+8)+8);
 cc[0]=q[2];cc[1]=q[3];cc[2]=q[4]; draw(aa,bb,cc,1.0f,0);
 t=lbl_801A66A0; lbl_8006D7F4((f32)(t-((t+((u32)(t-((t*3001u)>>32))>>1)+((t*3001u)>>32))>>31)*-3000)/lbl_1_rodata_87BC,(f32)(t-(((u32)(((0x10620000u+19923)*t)>>32)>>8)*4000))/lbl_1_rodata_87C0,0); lbl_8006DB74((u32)loc); fn_800749B0(0,loc); fn_1_556B8((void*)q);
 aa[0]=0;aa[1]=lbl_1_rodata_87B4;aa[2]=80;bb[0]=bb[1]=bb[2]=lbl_1_rodata_87C4;
 q=(u32*)*(u32*)((u8*)*(u32*)((u8*)*(u32*)(base+1)+8)+16);cc[0]=q[2];cc[1]=q[3];cc[2]=q[4];draw(aa,bb,cc,1,0);
 fn_1_556B8((void*)q);
 a.y=lbl_1_rodata_87B8;a.z=lbl_1_rodata_87C8;b.y=lbl_1_rodata_87CC;fn_8006F038(&a,&b,0);lbl_8006DCDC();fn_1_A7024(30,fn_1_A6FE8(),.1f,90000);
 aa[0]=0;aa[1]=.06f;bb[0]=bb[1]=.16f;bb[2]=.1f;
 q=(u32*)*(u32*)((u8*)*(u32*)((u8*)*(u32*)(base+1)+8)+0);cc[0]=q[2];cc[1]=q[3];cc[2]=q[4];
 lim=arg1?6:20; for(i=0;i<lim;i++){ aa[2]=((f32)(i-5)*4)-((f32)(lbl_801A66A0%((u32)53))*4/53); draw(aa,bb,cc,.25f,(void*)q); } 
 aa[0]=4.2f;aa[1]=1.8f;bb[0]=bb[1]=bb[2]=.2f;
 q=(u32*)*(u32*)((u8*)*(u32*)((u8*)*(u32*)(base+1)+8)+24);cc[0]=q[2];cc[1]=q[3];cc[2]=q[4];
 lim=arg1?8:25; for(i=0;i<lim;i++){ aa[2]=(f32)(i-5)*3.2f-3.2f*(f32)(lbl_801A66A0%64)*.015625f; draw(aa,bb,cc,.25f,(void*)q);aa[0]=-aa[0];draw(aa,bb,cc,.25f,(void*)q);aa[1]=-aa[1];draw(aa,bb,cc,.25f,(void*)q);aa[0]=-aa[0];draw(aa,bb,cc,.25f,(void*)q);}
 aa[0]=0;aa[1]=-.14f;bb[0]=.56f;bb[1]=.4f;bb[2]=.5f;
 q=(u32*)*(u32*)((u8*)*(u32*)((u8*)*(u32*)(base+1)+8)+32);cc[0]=q[2];cc[1]=q[3];cc[2]=q[4];
 lim=arg1?0:20; for(i=0;i<lim;i++){f32 z=fn_80088598(4,1.5); f32 v=(f32)(lbl_801A66A0%160)/160; aa[2]=fn_80088598(4,1.5)*(f32)(i-5)-160*v;draw(aa,bb,cc,.25f,(void*)q);}
 fn_1_56000(1,3,1);fn_1_A7024(p14,p10,pC,p8);
 if(arg0){ Font f; __builtin_memcpy(&f,lbl_1_rodata_26F8,sizeof(f)); f.unk30=0x100007;f.unk34=.5;fn_1_4E724(&f); __builtin_memcpy(&f,lbl_1_rodata_26F8,sizeof(f));f.unk30=0x180000;f.unk34=.5;fn_1_4E724(&f);__builtin_memcpy(&f,lbl_1_rodata_26F8,sizeof(f));f.unk30=7;f.unk34=.5;fn_1_4E724(&f);__builtin_memcpy(&f,lbl_1_rodata_26F8,sizeof(f));f.unk30=0x80000;f.unk34=.5;fn_1_4E724(&f);}
 if(fn_1_A5DC4()){fn_1_52088();__builtin_memcpy(&f,lbl_1_rodata_26F8,sizeof(f));f.unk30=18; w=(f32)fn_1_48690(18); *(f32*)((u8*)&f+16)*=640/w; h=(f32)fn_1_486C4(18);f.tail[0]=34;f.tail[1]=34;f.tail[2]=98;*(f32*)((u8*)&f+12)=9999;*(f32*)((u8*)&f+20)*=480/h;fn_1_4E724(&f);fn_1_52070(320);}
}
