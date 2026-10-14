/* Non-matching: best partial attempt (33.02% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct { u32 dummy[8]; } TexObj;
typedef struct { u32 dummy[10]; } TexObjLOD;
extern u8 lbl_8019F040[240];
extern const f32 lbl_801A7480, lbl_801A7488, lbl_801A749C;
extern u32 lbl_801A7928, lbl_801A7498;
extern u32 lbl_801A6D74, lbl_801A6D78, lbl_801A6D60, lbl_801A6D5C;
extern f32 lbl_801A6D70, lbl_801A6D6C, lbl_801A6D68;
extern u32 lbl_801A6D64, lbl_801A6D48, lbl_801A6D54, lbl_801A6D50;
extern f32 lbl_801A6D4C;
extern u32 lbl_801A6D40, lbl_801A6D58, lbl_801A6D44;
extern void lbl_8006D7F4(void);
extern void lbl_8006DB74(void *);
extern void GXLoadTexMtxImm(void *, u32, u8);
extern void lbl_8006D668(void *);
extern void *memset(void *, int, u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(TexObj *, void *, u16, u16, u32, u32, u32, u8);
extern void GXInitTexObjLOD(TexObjLOD *, u32, u32, f32, f32, f32, u8, u8, u32);
extern void fn_800728A8(s32,s32,s32,s32);
extern void fn_800729B0(s32,s32,s32,s32,s32);
extern void fn_800736C0(s32, void *);
void fn_80075240(void) {
    u32 words[15];
    u32 a,b,c,d;
    f32 *p;
    u8 *tex;
    u32 i,j,k;
    *(f32 *)(lbl_8019F040+0xf4)=lbl_801A7488;
    *(f32 *)(lbl_8019F040+0xf8)=lbl_801A7488;
    *(f32 *)(lbl_8019F040+0xf0)=lbl_801A7488;
    lbl_801A6D74=1; lbl_801A6D78=0;
    *(u32 *)(lbl_8019F040+0xe0)=0;
    *(u32 *)(lbl_8019F040+0xe4)=0;
    *(u32 *)(lbl_8019F040+0xe8)=0;
    lbl_8006D7F4();
    lbl_8006DB74(lbl_8019F040+0x138);
    GXLoadTexMtxImm(lbl_8019F040+0x138,0x21,0);
    words[2]=0; words[3]=0x3f800000; words[4]=0;
    lbl_801A6D60=0xffffffff; lbl_801A6D5C=0xffffffff;
    *(u32 *)(lbl_8019F040+0x10c)=words[2];
    *(u32 *)(lbl_8019F040+0x110)=words[3];
    *(u32 *)(lbl_8019F040+0x114)=words[4];
    lbl_8006D668(lbl_8019F040+0x10c);
    lbl_801A6D70=1; lbl_801A6D6C=1; lbl_801A6D68=1;
    lbl_801A6D64=1; lbl_801A6D48=0;
    p=(f32 *)(lbl_8019F040+0x100); p[0]=0; p[1]=0; p[2]=-1;
    memset(lbl_8019F040+0x180,255,32);
    memset(lbl_8019F040+0x1a0,0,32);
    DCFlushRange(lbl_8019F040+0x180,64);
    GXInitTexObj((TexObj *)(lbl_8019F040+0x1c0),lbl_8019F040+0x180,16,4,1,0,0,0);
    GXInitTexObjLOD((TexObjLOD *)(lbl_8019F040+0x1c0),1,1,0,0,0,0,0,0);
    tex=lbl_8019F040+0x1e0;
    for(i=0;i<16;i++) for(j=0;j<16;j++) for(k=0;k<64;k++) {
       tex[i*64+j*64+k*2]=0; tex[i*64+j*64+k*2+1]=0;
       tex[i*64+j*64+k*2+32]=((k)&63)<<2;
       tex[i*64+j*64+k*2+33]=j<<2;
    }
    DCFlushRange(lbl_8019F040+0x1e0,0x4000);
    GXInitTexObj((TexObj *)(lbl_8019F040+0x118),lbl_8019F040+0x1e0,64,64,6,2,2,0);
    GXInitTexObjLOD((TexObjLOD *)(lbl_8019F040+0x118),3,1,0,0,0,0,0,0);
    lbl_801A6D54=0; lbl_801A6D50=lbl_801A7498; lbl_801A6D4C=1;
    fn_800728A8(0,1,0,0);
    fn_800729B0(0,0,1,2,3); fn_800729B0(1,0,1,2,0);
    fn_800729B0(2,0,1,2,1); fn_800729B0(3,0,1,2,2);
    a=lbl_801A7928; b=a; fn_800736C0(0,&a);
    b=lbl_801A7928; fn_800736C0(1,&b);
    c=lbl_801A7928; fn_800736C0(2,&c);
    d=lbl_801A7928; fn_800736C0(3,&d);
    lbl_801A6D40=0; lbl_801A6D58=0; lbl_801A6D44=0;
}
