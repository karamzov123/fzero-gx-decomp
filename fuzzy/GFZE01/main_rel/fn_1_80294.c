/* Non-matching: best partial attempt (36.47% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct { u8 pad[0x320]; } Display;
typedef struct { u8 pad[0x360]; } DisplaySlot;
typedef struct { u32 count; void *items; } TextureList;
typedef struct { u8 pad[0x18]; u16 count; u8 pad2[0xA]; u32 field; } Entry;
typedef struct { s32 count; u8 pad[4]; Entry **entries; } Table;
typedef struct { u8 pad[4]; u32 field; } EntryArg;
typedef struct { u16 key,value; } Pair;
extern u8 lbl_1_bss_6D820;
extern u8 lbl_1_data_1F1D8[];
extern u8 lbl_1_rodata_3508[];
extern u32 lbl_801A6410;
extern void fn_1_12AB38(void *);
extern u32 fn_1_12AC00(void *, u32);
extern void *fn_1_12AC28(void *, void **, void **, u32);
extern void *fn_1_12ADA0(void *, void *);
extern void *fn_1_12ADC8(void *, void *, void *, void *);
extern void fn_1_12A7C4(void *, void *, u32);
extern void fn_1_14D728(void *, void *);
extern u32 fn_80077D40(TextureList *);
extern u32 fn_80077BD4(void *);
extern u32 OSGetArenaHi(void);
extern void *OSGetArenaLo(void);
extern char *fn_80083DB0(char *, const char *);
extern int sprintf(char *, const char *, ...);
extern void *fn_1_45D0(u32, u32);
extern void fn_800712E4(Table *, EntryArg *, Pair *);

#define B(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define H(p,o) (*(s16 *)((u8 *)(p)+(o)))
#define W(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define P(p,o) (*(void **)((u8 *)(p)+(o)))
#define S(p,o,v) (*(u32 *)((u8 *)(p)+(o))=(u32)(v))
#define F(p,o,v) (*(f32 *)((u8 *)(p)+(o))=(v))
static void ratio(void *obj, int field, u32 amount) {
    f64 conv, arena;
    u32 hi = OSGetArenaHi() - (u32)OSGetArenaLo();
    conv = (f64)amount;
    arena = (f64)hi;
    F(obj, field, 100.0f * (f32)(conv - 2147483648.0) / (f32)(arena - 4503599627370496.0));
}
void fn_1_80294(void *src, void *obj, s32 arg2, u32 arg3, u32 arg4) {
    int flag, i, j, k;
    s16 kind;
    char name[8][4];
    char text[8][4];
    char end[8][4];
    u32 pair_copy[62];
    void *current;
    u32 size;
    flag = (W(src,12) & 0x100000) != 0;
    if ((W(obj,0x390) & 0x400000) == 0) {
        H(obj,0x320)=H(src,0);
        W(obj,0x390) |= W(src,12) & 0xF0000000;
        H(obj,0x33c)=H(lbl_1_rodata_3508,0x54c);
        H(obj,0x348)=H(lbl_1_rodata_3508,0x550);
        H(obj,0x354)=H(lbl_1_rodata_3508,0x554);
        H(obj,0x360)=H(lbl_1_rodata_3508,0x558);
        H(obj,0x36c)=H(lbl_1_rodata_3508,0x55c);
        H(obj,0x378)=H(lbl_1_rodata_3508,0x560);
        W(obj,0x3bc)=0xffffffff;
    }
    if (W(obj,0x390)&0x4000000) {
        fn_1_12AB38(lbl_1_data_1F1D8+0xe20);
        fn_1_12AB38(lbl_1_data_1F1D8+0x13fc);
        W(src,0x18)=W(src,4);
        B(obj,0x38c)=W(src,4);
        fn_1_14D728((u8*)src+0x10,P(obj,0x3a0));
        W(obj,0x3a8)=0; W(obj,0x3b0)=0;
        for(i=0;i<3;i++) {
            void **base=(void **)((u8*)P(obj,0x3a0)+i*0x360);
            if(base[0]) W(obj,0x3a8)+=fn_80077D40((TextureList*)base[0]);
            for(j=0;j<6;j++) if(W(src,0x18)&(1<<j))
                W(&lbl_1_bss_6D820,0x10)+=fn_80077BD4(base[1+j]);
        }
        W(&lbl_1_bss_6D820,0x14)+=W(obj,0x3a8);
        ratio(obj,0x3ac,W(obj,0x3a8));
        ratio(obj,0x3b4,W(obj,0x3b0));
        fn_1_12AB38(lbl_1_data_1F1D8+0xe20);
        fn_1_12AB38(lbl_1_data_1F1D8+0xe0c);
        for(i=0;i<8;i++) if ((B(src,8)&(1<<i)) && !(W(obj,0x390)&0x400000)) H(obj,0x3b8)=i;
        return;
    }
    kind=H(src,2);
    if(kind<0 || kind>=0x29) return;
    if(!W(&lbl_1_bss_6D820,0xc)) W(&lbl_1_bss_6D820,0xc)=fn_1_12AC00(lbl_1_data_1F1D8+0x140c,0);
    if(W(src,12)&0x100000){flag=1;W(obj,0x390)|=0x100000;}
    fn_80083DB0(name[0],*(char **)(lbl_1_data_1F1D8+0x324+kind*4));
    if(flag && kind==6) fn_80083DB0(name[0],(char*)lbl_1_data_1F1D8+0x13e4);
    if(flag && kind==0) fn_80083DB0(name[0],(char*)lbl_1_data_1F1D8+0x13ec);
    if(flag && kind==1) fn_80083DB0(name[0],(char*)lbl_1_data_1F1D8+0x13f4);
    fn_1_12AB38(name[0]);
    for(i=0;i<8;i++) if(B(src,8)&(1<<i)) {
        int off=0x37c+i*4;
        current=P(obj,off);
        if(!current) {
            if(!(W(obj,0x390)&0x400000)) H(obj,0x3b8)=i;
            fn_80083DB0(text[0],*(char **)(lbl_1_data_1F1D8+0x324+kind*4));
            if(i>=4) sprintf(text[0],(char*)lbl_1_data_1F1D8+0x1358,text[0],i-4);
            else if(i) sprintf(text[0],(char*)lbl_1_data_1F1D8+0x1364,text[0],i);
            else sprintf(text[0],(char*)lbl_1_data_1F1D8+0x1370,text[0]);
            if(arg2) current=fn_1_12AC28(text[0],(void**)((u8*)obj+0x3c0+i*4),(void**)((u8*)obj+0x3e0+i*4),0);
            else {P(obj,0x3c0+i*4)=0;current=(void*)fn_1_12AC00(text[0],0);}
            P(obj,off)=current;
            size=fn_80077D40((TextureList*)current); W(obj,0x3a8)=size;
            W(&lbl_1_bss_6D820,0x14)+=size; ratio(obj,0x3ac,size);
        }
    }
    for(i=0;i<5;i++) if((W(src,4)&(1<<i)) && !P(obj,0x338+i*12)) {
        B(obj,0x38c)|=1<<i;
        fn_80083DB0(text[0],*(char **)(lbl_1_data_1F1D8+0x324+kind*4));
        if(i==0) sprintf(text[0],(char*)lbl_1_data_1F1D8+0x1378,text[0]);
        else if(i==4) sprintf(text[0],(char*)lbl_1_data_1F1D8+0x1380,text[0]);
        else sprintf(text[0],(char*)lbl_1_data_1F1D8+0x1390,text[0],i+1);
        if(arg2) current=fn_1_12ADC8(text[0],current,(u8*)obj+0x400+i*4,(u8*)obj+0x414+i*4);
        else {P(obj,0x400+i*4)=0;current=fn_1_12ADA0(text[0],current);}
        size=fn_80077BD4(current); W(&lbl_1_bss_6D820,0x10)+=size;
        W(obj,0x3b0)=fn_80077BD4(current); ratio(obj,0x3b4,W(obj,0x3b0));
        size=(u32)fn_1_45D0(W(&lbl_801A6410,0), (u32)(s8)B(current,0)<<2);
        for(j=0;j<(s8)B(current,0);j++) ((u32*)size)[j]=W(current,8);
        for(k=0;k<58;k++) pair_copy[k]=W(lbl_1_rodata_3508,0x45c+k*4);
        fn_800712E4((Table*)W(&lbl_1_bss_6D820,0xc),(EntryArg*)current,(Pair*)pair_copy);
        H(obj,0x328)=kind; P(obj,0x338+i*12)=current; P(obj,0x334+i*12)=(void*)size;
    }
    if(!(W(obj,0x390)&0x400000)) {
        fn_80083DB0(end[0],*(char **)(lbl_1_data_1F1D8+0x324+kind*4));
        sprintf(end[0],(char*)lbl_1_data_1F1D8+0x139c,end[0]);
        fn_1_12A7C4(end[0],obj,0x320);
    }
    if(B(obj,2) && !P(obj,0x330)) P(obj,0x330)=fn_1_45D0(W(&lbl_801A6410,0),(s8)B(obj,2)*0x30);
    fn_1_12AB38(lbl_1_data_1F1D8+0xe20);
    W(obj,0x390)|=0x400000;
}
