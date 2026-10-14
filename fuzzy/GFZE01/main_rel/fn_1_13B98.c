/* Non-matching: best partial attempt (96.64% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/som.h"
extern f32 lbl_1_rodata_6B0[];
extern u8 lbl_1_bss_3BC0[32];
extern void *lbl_801A6410[];
extern u32 lbl_1_bss_3BE4[];
extern f32 lbl_1_bss_7AC88;
extern f32 lbl_1_bss_7AC9C;
extern int sprintf(char *, const char *, ...);
extern int fn_1_45730(void *, void *);
extern int fn_1_458A0(void *, void *, u32, u32);
extern int fn_1_45850(void *);
extern void *fn_1_45D0(void *, u32, void *, u32);
extern void fn_1_46B4(void *, void *, void *, u32);
extern void fn_1_12860(void *, void *);
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_1_13A28(void *, s32);
extern void fn_800793D4(void *, int, u32);
extern void fn_80008BEC(void *, int, u32);
extern void lbl_8006D758(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006E0C8(void *);
extern void fn_1_9D420(void *, u32);
extern void fn_1_14DE8(u32);
#define W(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define F(p,o) (*(f32 *)((u8 *)(p)+(o)))
#define H(p,o) (*(s16 *)((u8 *)(p)+(o)))
#define FIX(p,o,b) if(W(p,o)!=0) W(p,o) += (u32)(b)
#define GF(f) if(lbl_1_bss_3BE0->unk_##f != 0) lbl_1_bss_3BE0->unk_##f += (u32)lbl_1_bss_3BE0
#pragma opt_propagation off
#pragma opt_common_subs on
#pragma opt_strength_reduction off
void fn_1_13B98(u32 arg0, s32 arg1) {
 s32 tmp_call71;
 s32 tmp_call72;
 u8 *p;
 char path[32];
 s32 tmp_call75;
 u32 size;
 u32 size2;
 Obj_1_bss_3BE0_Target *root;
 u8 * p_2_2;
 u8 * p_2;
 f32 zero;
 void *raw;
 void *data;
 u8 load[0x5c];
 u8 *q;
 u32 previous;
    u32 lab_t3;
    u32 lab_v;
 s32 i,j,k;
 u32 offset;
 u32 saved;
 u8 *runtime;
 s8 *strings = (s8 *)&lbl_1_data_5190;
 f32 *floats = lbl_1_rodata_6B0;
 if((s8)*strings != -1) { arg0=(s8)*strings; *strings=-1; }
 sprintf(path,(char *)(strings+4),arg0);
 if(fn_1_45730(path,load)==0) fn_1_45730(strings+0x20,load);
 fn_1_458A0(load,lbl_1_bss_3BC0,32,0);
 size=(__lwbrx((void *)lbl_1_bss_3BC0,0)+39)&~31;
 size2=(__lwbrx((void *)lbl_1_bss_3BC0,4)+31)&~31;
 lab_t3 = 0x181;
 data=fn_1_45D0(lbl_801A6410[0], size2, strings+0x38, lab_t3);
 lab_t3 = 0x182;
 raw=fn_1_45D0(lbl_801A6410[0], size, strings+0x38, lab_t3);
 if(fn_1_458A0(load,raw,size,0)<0) OSPanic((char *)strings+0x38,0x184,(char *)strings+0x44);
 if(fn_1_45850(load)==0) OSPanic((char *)strings+0x38,0x185,(char *)strings+0x50);
 fn_1_12860(raw,data);
 fn_1_46B4(lbl_801A6410[0],raw,strings+0x38,0x189);
 lbl_1_bss_3BE0=data;
 if(lbl_1_bss_3BE0->unk_C!=0) {
 previous=0;
 GF(C);
 p=(u8 *)lbl_1_bss_3BE0->unk_C;
 for(i=0;(root=lbl_1_bss_3BE0),i<(s32)root->unk_8;i++,p+=12) {
 FIX(p,4,root);
 FIX(p,8,lbl_1_bss_3BE0);
 if(previous!=W(p,8)) fn_1_13A28((void *)W(p,8),(s32)lbl_1_bss_3BE0);
 previous=W(p,8);
 }
 }
 GF(14);
 lbl_1_bss_3BE0->unk_1C += (u32)lbl_1_bss_3BE0;
 p_2=(u8 *)lbl_1_bss_3BE0->unk_1C;
 zero=(0.0f);
 for(i=0;(root=lbl_1_bss_3BE0),i<(s32)root->unk_18;i++,p_2+=0x4b0) {
 if(zero==F(p_2,0x108) && zero==F(p_2,0x10c)) {
 F(p_2,0x108)=F(root,0);
 F(p_2,0x10c)=lbl_1_bss_3BE0->unk_4;
 }
 if(W(p_2,0x14)!=0) {
 u32 base=(u32)lbl_1_bss_3BE0;
 W(p_2,0x14)+=base;
 FIX((void *)W(p_2,0x14),4,base);
 FIX((void *)W(p_2,0x14),12,base);
 FIX((void *)W(p_2,0x14),20,base);
 FIX((void *)W(p_2,0x14),28,base);
 FIX((void *)W(p_2,0x14),36,base);
 FIX((void *)W(p_2,0x14),44,base);
 }
 FIX(p_2,0x24,lbl_1_bss_3BE0);
 for(j=0;j<7;j++) {
 if(W(p_2,40+j*8)!=0) {
 W(p_2,40+j*8)+=(u32)lbl_1_bss_3BE0;
 q=(u8 *)W(p_2,40+j*8);
 for(k=0;k<(s32)(W(p_2,0x70)*W(p_2,0x74));k++,q+=4) { FIX(q,0,lbl_1_bss_3BE0); }
 }
 if(W(p_2,44+j*8)!=0) {
 W(p_2,44+j*8)+=(u32)lbl_1_bss_3BE0;
 q=(u8 *)W(p_2,44+j*8);
 for(k=0;k<(s32)(W(p_2,0x70)*W(p_2,0x74));k++,q+=4) { FIX(q,0,lbl_1_bss_3BE0); }
 }
 }
 FIX(p_2,0x78,lbl_1_bss_3BE0);
 for(j=0;j<7;j++) {
 if(W(p_2,124+j*8)!=0) {
 W(p_2,124+j*8)+=(u32)lbl_1_bss_3BE0;
 q=(u8 *)W(p_2,124+j*8);
 for(k=0;k<(s32)(W(p_2,0x70)*W(p_2,0x74));k++,q+=4) { FIX(q,0,lbl_1_bss_3BE0); }
 }
 if(W(p_2,128+j*8)!=0) {
 W(p_2,128+j*8)+=(u32)lbl_1_bss_3BE0;
 q=(u8 *)W(p_2,128+j*8);
 for(k=0;k<(s32)(W(p_2,0x70)*W(p_2,0x74));k++,q+=4) { FIX(q,0,lbl_1_bss_3BE0); }
 }
 }
 FIX(p_2,184,lbl_1_bss_3BE0);
 FIX(p_2,192,lbl_1_bss_3BE0);
 FIX(p_2,200,lbl_1_bss_3BE0);
 FIX(p_2,208,lbl_1_bss_3BE0);
 FIX(p_2,216,lbl_1_bss_3BE0);
 FIX(p_2,224,lbl_1_bss_3BE0);
 FIX(p_2,244,lbl_1_bss_3BE0);
 FIX(p_2,232,lbl_1_bss_3BE0);
 FIX(p_2,272,lbl_1_bss_3BE0);
 FIX(p_2,276,lbl_1_bss_3BE0);
 FIX(p_2,280,lbl_1_bss_3BE0);
 FIX(p_2,284,lbl_1_bss_3BE0);
 }
 if(W(lbl_1_bss_3BE0,0x20)!=0) W(lbl_1_bss_3BE0,0x20)+=(u32)lbl_1_bss_3BE0;
 GF(24); GF(2C); GF(3C); GF(44); GF(60);
 for(i=0,offset=0;(root=lbl_1_bss_3BE0),i<(s32)root->unk_5C;i++,offset+=0x24)
 W((void *)lbl_1_bss_3BE0->unk_60,offset)+=(u32)lbl_1_bss_3BE0;
 GF(70);
 for(i=0,offset=0;(root=lbl_1_bss_3BE0),i<(s32)root->unk_6C;i++,offset+=4)
 W((void *)lbl_1_bss_3BE0->unk_70,offset)+=(u32)lbl_1_bss_3BE0;
 if(lbl_1_bss_3BE0->unk_80!=0) {
 lbl_1_bss_3BE0->unk_80+=(u32)lbl_1_bss_3BE0;
 p_2_2=(u8 *)lbl_1_bss_3BE0->unk_80;
 W(p_2_2,4)+=(u32)lbl_1_bss_3BE0;
 W(p_2_2,12)+=(u32)lbl_1_bss_3BE0;
 W(p_2_2,20)+=(u32)lbl_1_bss_3BE0;
 W(p_2_2,28)+=(u32)lbl_1_bss_3BE0;
 W(p_2_2,36)+=(u32)lbl_1_bss_3BE0;
 W(p_2_2,44)+=(u32)lbl_1_bss_3BE0;
 }
 GF(84); GF(8C);
 for(i=0,offset=0;(root=lbl_1_bss_3BE0),i<(s32)root->unk_88;offset+=0xa0,i++) {
 p_2_2=(u8 *)lbl_1_bss_3BE0->unk_8C+offset;
 FIX(p_2_2,12,lbl_1_bss_3BE0); FIX(p_2_2,20,lbl_1_bss_3BE0); FIX(p_2_2,28,lbl_1_bss_3BE0);
 }
 GF(78);
 for(i=0,offset=0;(root=lbl_1_bss_3BE0),i<(s32)root->unk_74;offset+=0x70,i++) {
 p_2_2=(u8 *)lbl_1_bss_3BE0->unk_78+offset;
 W(p_2_2,0)+=(u32)lbl_1_bss_3BE0;
 FIX(p_2_2,36,lbl_1_bss_3BE0);
 FIX(p_2_2,44,lbl_1_bss_3BE0);
 FIX(p_2_2,52,lbl_1_bss_3BE0);
 FIX(p_2_2,60,lbl_1_bss_3BE0);
 FIX(p_2_2,68,lbl_1_bss_3BE0);
 FIX(p_2_2,76,lbl_1_bss_3BE0);
 FIX(p_2_2,84,lbl_1_bss_3BE0);
 if(W(p_2_2,0x4c)!=0) W(p_2_2,0x5c)+=(u32)lbl_1_bss_3BE0;
 }
 GF(90); GF(98); GF(A0); GF(A8); GF(B0);
    lab_v = lbl_1_bss_3BE0->unk_B8;
 if(lab_v!=0) {
 lab_v+=(u32)lbl_1_bss_3BE0;
 p_2_2=(u8 *)lab_v;
 for(i=0;(root=lbl_1_bss_3BE0),i<(s32)root->unk_B4;i++,p_2_2+=0x38) {
 if(W(p_2_2,0x10)!=0) { u32 base=(u32)lbl_1_bss_3BE0;
 W(p_2_2,0x10)+=base;
 FIX((void *)W(p_2_2,0x10),4,base);
 FIX((void *)W(p_2_2,0x10),12,base);
 FIX((void *)W(p_2_2,0x10),20,base);
 FIX((void *)W(p_2_2,0x10),28,base);
 FIX((void *)W(p_2_2,0x10),36,base);
 FIX((void *)W(p_2_2,0x10),44,base);
 } } }
 if(lbl_1_bss_3BE0->unk_BC!=0) {
 lbl_1_bss_3BE0->unk_BC+=(u32)lbl_1_bss_3BE0;
 p_2_2=(u8 *)lbl_1_bss_3BE0->unk_BC;
 for(i=0;i<(s32)(lbl_1_bss_3BE0->unk_D0*lbl_1_bss_3BE0->unk_D4);i++,p_2_2+=4) { FIX(p_2_2,0,lbl_1_bss_3BE0); }
 }
 if(lbl_1_bss_3BE0->unk_54!=0) {
 lbl_1_bss_3BE0->unk_54+=(u32)lbl_1_bss_3BE0;
 p_2_2=(u8 *)lbl_1_bss_3BE0->unk_54;
 for(i=0;(root=lbl_1_bss_3BE0),i<(s32)root->unk_48;i++,p_2_2+=0x40) {
 if(W(p_2_2,0x30)!=0) { u32 base=(u32)lbl_1_bss_3BE0;
 W(p_2_2,0x30)+=base;
 FIX((void *)W(p_2_2,0x30),48,base);
 FIX((void *)W(p_2_2,0x30),72,base);
 FIX((void *)W(p_2_2,0x30),96,base);
 FIX((void *)W(p_2_2,0x30),120,base);
 FIX((void *)W(p_2_2,0x30),144,base);
 FIX((void *)W(p_2_2,0x30),168,base);
 FIX((void *)W(p_2_2,0x30),192,base);
 FIX((void *)W(p_2_2,0x30),216,base);
 FIX((void *)W(p_2_2,0x30),240,base);
 FIX((void *)W(p_2_2,0x30),264,base);
 FIX((void *)W(p_2_2,0x30),288,base);
 }
 if(W(p_2_2,0x34)!=0) { u32 base=(u32)lbl_1_bss_3BE0;
 W(p_2_2,0x34)+=base;
 if(W((void *)W(p_2_2,0x34),0)!=0) W((void *)W(p_2_2,0x34),0)=base+W((void *)W(p_2_2,0x34),0);
 if(W((void *)W(p_2_2,0x34),4)!=0) W((void *)W(p_2_2,0x34),4)=base+W((void *)W(p_2_2,0x34),4);
 if(W((void *)W(p_2_2,0x34),8)!=0) W((void *)W(p_2_2,0x34),8)=base+W((void *)W(p_2_2,0x34),8);
 if(W((void *)W(p_2_2,0x34),12)!=0) W((void *)W(p_2_2,0x34),12)=base+W((void *)W(p_2_2,0x34),12);
 }
 if(W(p_2_2,0x38)!=0) { u32 base=(u32)lbl_1_bss_3BE0;
 W(p_2_2,0x38)+=base; FIX((void *)W(p_2_2,0x38),12,base); }
 FIX(p_2_2,0x3c,lbl_1_bss_3BE0);
 W(p_2_2,8)+=(u32)lbl_1_bss_3BE0;
 } }
 if((s32)lbl_1_bss_3BE0->unk_64>0) {
 lbl_1_bss_3BE0->unk_68+=(u32)lbl_1_bss_3BE0;
 p_2_2=(u8 *)lbl_1_bss_3BE0->unk_68;
 for(i=0;(root=lbl_1_bss_3BE0),i<(s32)root->unk_64;i++,p_2_2+=16) {
 W(p_2_2,8)+=(u32)lbl_1_bss_3BE0;
 q=(u8 *)W(p_2_2,8);
 for(j=0;j<(s32)W(p_2_2,4);j++,q+=16) W(q,4)+=(u32)lbl_1_bss_3BE0;
 tmp_call71 = W(p_2_2,12);
 if(tmp_call71!=0) {
 tmp_call72 = W(p_2_2,12);
 tmp_call72+=(u32)lbl_1_bss_3BE0;
 q=(u8 *)W(p_2_2,12);
 FIX(q,28,lbl_1_bss_3BE0); FIX(q,32,lbl_1_bss_3BE0);
 } } }
 lbl_1_bss_3BE4[0]=(u32)fn_1_45D0(lbl_801A6410[0],lbl_1_bss_3BE0->unk_18*0xa0,strings+0x38,0x2a7);
 fn_800793D4((void *)lbl_1_bss_3BE4[0],0,lbl_1_bss_3BE0->unk_18*0xa0);
 runtime=(u8 *)lbl_1_bss_3BE4[0];
 p_2_2=(u8 *)lbl_1_bss_3BE0->unk_1C;
 for(i=0;(root=lbl_1_bss_3BE0),i<(s32)root->unk_18;i++,p_2_2+=0x4b0,runtime+=0xa0) {
 tmp_call75 = W(runtime,0x9c);
 saved=tmp_call75;
 fn_80008BEC(runtime,0,0xa0);
 W(runtime,0x9c)=saved;
 F(runtime,8)=F(p_2_2,0);
 F(runtime,12)=F(p_2_2,4);
 F(runtime,16)=F(p_2_2,8);
 F(runtime,20)=F(p_2_2,0)-F(p_2_2,24);
 F(runtime,24)=F(p_2_2,4)-F(p_2_2,28);
 F(runtime,28)=F(p_2_2,8)-F(p_2_2,32);
 H(runtime,32)=H(p_2_2,12);
 H(runtime,34)=H(p_2_2,14);
 H(runtime,36)=H(p_2_2,16);
 H(runtime,38)=H(p_2_2,12);
 H(runtime,40)=H(p_2_2,14);
 H(runtime,42)=H(p_2_2,16);
 lbl_8006D758();
 lbl_8006DB74(runtime+0x2c);
 lbl_8006E0C8(p_2_2+0x18);
 lbl_8006DB74(runtime+0x5c);
 if(W(p_2_2,0xf4)!=0) F(runtime,0x98)=F((void *)W(p_2_2,0xf4),12);
 W(runtime,0)|=W(p_2_2,0x104);
 }
 if(arg1!=0 && lbl_1_bss_3BE0->unk_54!=0) fn_1_9D420((void *)lbl_1_bss_3BE0->unk_54,lbl_1_bss_3BE0->unk_48);
 lbl_1_bss_7AC88=F((void *)lbl_1_bss_3BE0->unk_90,0)*(0.001953125f);
 lbl_1_bss_7AC9C=(512.0f)/F((void *)lbl_1_bss_3BE0->unk_90,0);
 if(lbl_1_bss_3BE0->unk_C!=0) fn_1_14DE8(arg0);
}
#pragma opt_strength_reduction reset

