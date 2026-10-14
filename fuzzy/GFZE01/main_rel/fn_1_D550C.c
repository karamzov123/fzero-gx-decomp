/* Non-matching: best partial attempt (33.51% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Pool {
    u8 pad0[0xC]; f32 one;
    u8 pad10[0x20]; f32 half;
    u8 pad34[0x10]; f32 hundred;
    u8 pad48[0x110]; f32 n32767;
    u8 pad15c[4]; f64 magic;
    u8 pad168[0x14];
    u32 seed0, seed1, seed2;
    f32 onehalf, ten, angle136, angle90, frac60, frac40, ninety6;
};
struct Global { u32 value; };
extern struct Pool lbl_1_rodata_6168;
extern struct Global lbl_801A63C0, lbl_801A6D00;
extern void fn_1_681C(u32,u32 *);
extern void fn_1_6898(u32,u32 *);
extern void fn_1_6914(u32,u32 *);
extern void fn_1_6990(u32,u32 *);
extern s16 camera_get_mode(void);
extern void fn_1_8636C(int,void *);
extern u32 lbl_8006E1C0(void *,void *);
extern f32 lbl_8006D668(u32 *);
extern void fn_1_A714C(f32 *,f32 *,f32 *,f32 *);
extern f32 fn_1_8652C(s32);
extern f32 fn_1_A71AC(void);

void fn_1_D550C(void *arg0) {
    struct Pool *pool = &lbl_1_rodata_6168;
    u32 loc60[3];
    u32 loc54[3], loc48[3], loc3c[3];
    f32 loc30[3];
    f32 loc14[7];
    f32 loc10,locc;
    u32 loc8;
    s16 mode;
    u32 n;
    f32 a,b,c,d,e;
    fn_1_681C(0,loc60);
    fn_1_6898(0,loc54);
    fn_1_6914(0,loc48);
    fn_1_6990(0,(u32 *)loc30);
    mode=camera_get_mode();
    if (mode >= 0) {
        loc3c[0]=pool->seed0;
        loc3c[1]=pool->seed1;
        loc3c[2]=pool->seed2;
        fn_1_8636C(mode,(void *)lbl_801A6D00.value);
        lbl_8006E1C0(loc3c,loc3c);
        lbl_8006D668(loc3c);
        fn_1_A714C(loc14,&loc10,&locc,(f32 *)&loc8);
        n=0x676a4b6b;
        n=lbl_801A63C0.value*n+13259;
        loc14[1]=*(f32 *)&loc60[0];
        loc14[2]=*(f32 *)&loc60[1];
        loc14[3]=*(f32 *)&loc60[2];
        a=(f32)((n>>16)&0x7fff);
        a=(f32)(pool->onehalf*(a/pool->n32767))-pool->half;
        lbl_801A63C0.value=n;
        b=fn_1_8652C(mode)/pool->ten;
        n=lbl_801A63C0.value*0x676a4b6b+13259;
        c=pool->hundred-locc;
        d=locc+a*c;
        lbl_801A63C0.value=n;
        e=b+d;
        loc14[1]=loc14[1]+loc3c[0]*e;
        loc14[2]=loc14[2]+loc3c[1]*e;
        loc14[3]=loc14[3]+loc3c[2]*e;
        a=(f32)((n>>16)&0x7fff);
        b=(e/pool->ten)*fn_1_A71AC();
        c=b*((f32)a/pool->n32767-pool->half);
        loc14[4]=loc3c[1]*loc30[2]-loc3c[2]*loc30[1];
        loc14[1]=loc14[1]+loc30[0]*c;
        loc14[2]=loc14[2]+loc30[1]*c;
        loc14[3]=loc14[3]+loc30[2]*c;
        loc14[5]=loc3c[2]*loc30[0]-loc3c[0]*loc30[2];
        loc14[6]=loc3c[0]*loc30[1]-loc3c[1]*loc30[0];
        a=fn_1_A71AC();
        b=pool->angle90+a;
        c=pool->angle136*(pool->one-a);
        d=(loc10*e)*((f32)((u32)(lbl_801A63C0.value*0x676a4b6b+13259)>>16&0x7fff)/pool->n32767-pool->half);
        loc14[1]=loc14[1]+loc14[4]*d;
        loc14[2]=loc14[2]+loc14[5]*d;
        loc14[3]=loc14[3]+loc14[6]*d;
        ((u32 *)arg0)[0]=(u32)loc14[1];
        ((u32 *)arg0)[1]=(u32)loc14[2];
        ((u32 *)arg0)[2]=(u32)loc14[3];
        ((f32 *)arg0)[6]=c;
        ((f32 *)arg0)[7]=c;
        ((f32 *)arg0)[8]=c;
        n=lbl_801A63C0.value*0x676a4b6b+13259;
        lbl_801A63C0.value=n;
        ((f32 *)arg0)[9]=b*(pool->frac60+pool->frac40*((f64)(u32)((n>>16)&0x7fff)-pool->magic)/pool->n32767);
        n=lbl_801A63C0.value*0x676a4b6b+13259;
        lbl_801A63C0.value=n;
        ((u16 *)arg0)[20]=(n>>16)&0x7fff;
        n=lbl_801A63C0.value*0x676a4b6b+13259;
        lbl_801A63C0.value=n;
        ((u16 *)arg0)[21]=(s32)(pool->ninety6*((f32)((f64)(u32)((n>>16)&0x7fff)-pool->magic)/pool->n32767-pool->half));
        ((u16 *)arg0)[22]=20;
    }
}
