#include "types.h"


/* --- dol/fn_8004C980.c --- */
typedef void (*fn_8004C980_Fn0)(u32, u32);
struct fn_8004C980_Callback {
    u8 pad_0[20];
    fn_8004C980_Fn0 fn;
};
struct fn_8004C980_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x30];
    s16 unk_3C;
    s16 unk_3E;
};

extern void fn_8004A550(u32, u32, u32);
extern u32 fn_8004AC04(u32, u32);
extern u32 fn_8004AC4C(u32, u32, u32);
extern u32 fn_8004AE94(u32, u32);
extern void fn_8004AD84(u32);
extern void fn_8004B0EC(u32);
extern void fn_8004B180(u32, u32, u32, u32, u32);
extern s32 fn_8004ADF4(u32);
extern u32 fn_80042198(u32, u32);
extern u32 fn_8004212C(u32);
extern u32 ADXAMP_Start(u32);
extern u32 lbl_80178CB8[];

void fn_8004C980(struct fn_8004C980_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    s32 v2;
    u32 v0;
    u32 v1;
    u32 v3;
    u32 v4;

    fn_8004A550(arg0->unk_8, arg0->unk_3E << 11, arg0->unk_3C << 11);
    fn_8004AC04(arg0->unk_8, 25);
    fn_8004AC4C(arg0->unk_8, 0, 0);
    fn_8004AE94(arg0->unk_8, 0);
    fn_8004AD84(arg0->unk_8);
    fn_8004B0EC(arg0->unk_8);
    fn_8004B180(arg0->unk_8, arg1, arg2, arg3, arg4);
    fn_8004ADF4(arg0->unk_8);
    v0 = *(u32 *)((u8 *)arg0 + 16);
    v1 = (u32)arg0;
    v2 = 0;
    while (v2 < (s8)*((u8 *)arg0 + 3)) {
        ((struct fn_8004C980_Callback *)(*(u32 *)((u8 *)*(u32 *)(v1 + 24))))->fn(
            *(u32 *)((u8 *)v1 + 24),
            *(u32 *)((u8 *)*(u32 *)((u8 *)v1 + 24)));
        v1 += 4;
        v2++;
    }
    fn_80042198(*(u32 *)((u8 *)arg0 + 4), v0);
    *(u32 *)((u8 *)arg0 + 20) = v0;
    fn_8004212C(*(u32 *)((u8 *)arg0 + 4));
    *(u8 *)((u8 *)arg0 + 1) = 1;
    v3 = (0x80000000 - 1);
    *(u32 *)((u8 *)arg0 + 76) = 0;
    *(u8 *)((u8 *)arg0 + 113) = 0;
    *(u32 *)((u8 *)arg0 + 140) = v3;
    *(u32 *)((u8 *)arg0 + 144) = -1;
    *(u32 *)((u8 *)arg0 + 156) = 0;
    *(u32 *)((u8 *)arg0 + 164) = 0;
    *(u32 *)((u8 *)arg0 + 160) = lbl_80178CB8[0];
    v4 = *(u32 *)((u8 *)arg0 + 116);
    if (v4 != 0) {
        ADXAMP_Start(v4);
    }
}

/* --- dol/fn_8004CAC8.c --- */
typedef u32 (*fn_8004CAC8_Fn0)(u32);
typedef void (*fn_8004CAC8_Fn1)(u32, u32);
extern u32 lbl_80091014[];
extern u32 lbl_80090FC4[];
extern u32 lbl_8017E58C[];
extern void fn_800474E4(u32);
extern void fn_80046738(void);
extern void fn_80056CD0(u32);
extern void fn_8004EEC4(u32,u32);
extern void fn_8004EEA4(u32,u32);
extern void fn_800420F4(u32);
extern void fn_80046510(u32);
extern void fn_80046718(void);
extern void fn_8004EEE4(u32);
extern void fn_800421CC(u32);
extern void fn_8004B1DC(u32);
extern u32 fn_80057114(u32);
extern u32 fn_800466D4(u32);
extern void *memset(void *,int,u32);
void fn_8004CAC8(u32 arg0) {
 u32 v7;
 u32 v4;
 s32 v6;
 u32 v0;
 u32 v1;
 if (arg0 == 0) { fn_800474E4((u32)lbl_80091014); }
 else {
 v1=lbl_8017E58C[0];
 if(v1) ((fn_8004CAC8_Fn0)v1)(arg0);
 if (*(s8 *)(arg0)==1) {
 if(arg0==0) fn_800474E4((u32)lbl_80090FC4);
 else {
 v0=*(u32 *)(arg0+8);
 if(v0) fn_8004B0EC(v0);
 fn_80046738();
 if(*(s8 *)(arg0+2)==4) {
 fn_80056CD0(*(u32 *)(arg0+148));
 v0=*(u32 *)(arg0+20);
 if(v0) ((fn_8004CAC8_Fn1)*(u32 *)(*(u32 *)v0+20))(v0,*(u32 *)v0);
 }
 fn_80046738();
 fn_8004EEC4(*(u32 *)(arg0+12),0);
 fn_8004EEA4(*(u32 *)(arg0+12),0);
 fn_800420F4(*(u32 *)(arg0+4));
 if(*(s8 *)(arg0+2)==2) {
 v0=*(u32 *)(arg0+20);
 if(v0) {
 *(u32 *)(arg0+20)=0;
 ((fn_8004CAC8_Fn1)*(u32 *)(*(u32 *)v0+12))(v0,*(u32 *)v0);
 }}
 v0=*(u32 *)(arg0+116);
 if(v0) fn_80046510(v0);
 *(u32 *)(arg0+20)=0;
 *(u8 *)(arg0+1)=0;
 *(u8 *)(arg0+168)=0;
 fn_80046718(); fn_80046718();
 }}
 v0=*(u32 *)(arg0+12);
 if(v0) { *(u32 *)(arg0+12)=0; fn_8004EEE4(v0); }
 v0=*(u32 *)(arg0+4);
 if(v0) { *(u32 *)(arg0+4)=0; fn_800421CC(v0); }
 v4=*(u32 *)(arg0+8);
 if(v4) { *(u32 *)(arg0+8)=0; fn_8004AC4C(v4,0,0); fn_8004B1DC(v4); }
 v0=*(u32 *)(arg0+148);
 if(v0) { *(u32 *)(arg0+148)=0; fn_80057114(v0); }
 fn_80046738();
 v0=*(u32 *)(arg0+16);
 if(v0) { *(u32 *)(arg0+16)=0; ((fn_8004CAC8_Fn1)*(u32 *)(*(u32 *)v0+12))(v0,*(u32 *)v0); }
 v6=0; v7=arg0;
 while(v6<(s8)*(u8 *)(arg0+3)) {
 v0=*(u32 *)(v7+24);
 if(v0) { *(u32 *)(v7+24)=0; ((fn_8004CAC8_Fn1)*(u32 *)(*(u32 *)v0+12))(v0,*(u32 *)v0); }
 v0=*(u32 *)(v7+120);
 if(v0) { *(u32 *)(v7+120)=0; ((fn_8004CAC8_Fn1)*(u32 *)(*(u32 *)v0+12))(v0,*(u32 *)v0); }
 v0=*(u32 *)(v7+128);
 if(v0) { *(u32 *)(v7+128)=0; ((fn_8004CAC8_Fn1)*(u32 *)(*(u32 *)v0+12))(v0,*(u32 *)v0); }
 v7+=4; v6++;
 }
 v0=*(u32 *)(arg0+116);
 if(v0) { *(u32 *)(arg0+116)=0; fn_800466D4(v0); }
 memset((void *)arg0,0,192);
 *(u8 *)arg0=0;
 fn_80046718();
 }
}
