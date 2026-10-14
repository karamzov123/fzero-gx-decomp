/* Non-matching: best partial attempt (75.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

typedef struct { u8 pad[0x150]; u32 *unk_150; } Manager;
typedef struct { u8 pad[0x10]; f32 x,y,z; } Vec;
typedef struct { u8 flag; u8 pad[15]; Vec pos; u8 pad2[0x28]; } Entry;
typedef struct { u8 pad[0x10]; u32 pad10; u32 unk_18; u8 pad2[4]; Entry *entries; u32 n; } Object;
typedef struct { u8 pad[0x58]; f64 grav; f32 decel; u8 pad64[0x38]; f32 eps; f32 one; u8 padA4[0xE4]; f32 zero; } RData;
extern RData lbl_1_rodata_7AB8;
extern u32 lbl_801A6410;
extern u32 fn_1_4630(u32,u32,const char*,int);
extern void fn_1_46B4(u32,u32,const char*,int);
extern s32 fn_80077B14(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006E1B0(void *,void *);
extern void lbl_8006DC20(void);
extern f32 lbl_8006D118(f32 *);
extern f32 lbl_8006D0B4(f32);
extern void fn_1_108A90(void *,s32,f32,f32,f32,f32);
extern void fn_1_109114(void *);

typedef struct { f32 a,b,c; } V3;
typedef struct { void *a,*b; } Pair;
#define DRAW(id,x,y,z,w) fn_1_108A90(o,(id),(x),(y),(z),(w))

void fn_1_113C58(Object *o) {
    u32 i,j,k;
    Entry *e;
    u32 *sort, *pairs;
    f32 *vals;
    u32 *p, *q;
    u32 *table, model, mode;
    u8 *base;
    if (!o || !*(u32 *)((u8 *)o+0x10)) return;
    fn_80077B14(*(void **)((u8 *)o+0x10));
    if (*(u8 *)o & 2) {
        *(u8 *)o &= ~2;
        lbl_8006DBAC((u8 *)(*(u32 *)(*(u32 *)((u8 *)o+12)+0x150)+8)
           + (*(u32 *)((u8 *)o+8), 0));
        /* Select the model using the accessory table. */
        lbl_8006DAEC();
        e=o->entries;
        for(i=0;i<o->n;i++,e++) {
            lbl_8006DBE4();
            lbl_8006E1B0((u8 *)e+0x28,(u8 *)e+0x10);
        }
        lbl_8006DC20();
    }
    e=o->entries;
    for(i=0;i<o->n;i++,e++) if (!(e->flag&1)) {
        *(u32 *)((u8 *)e+0x1c)=*(u32 *)((u8 *)e+0x10);
        *(u32 *)((u8 *)e+0x20)=*(u32 *)((u8 *)e+0x14);
        *(u32 *)((u8 *)e+0x24)=*(u32 *)((u8 *)e+0x18);
        e->pos.x += *(f32 *)((u8 *)e+0x34);
        e->pos.y += *(f32 *)((u8 *)e+0x38);
        e->pos.z += *(f32 *)((u8 *)e+0x3c);
        e->pos.y = (f32)((f64)e->pos.y-lbl_1_rodata_7AB8.grav);
        *(f32 *)((u8 *)e+0x38) -= lbl_1_rodata_7AB8.decel;
    }
    /* Build and sort collision pairs by combined mass. */
    table=(u32 *)&lbl_1_data_3FFBC;
    model=table[*(u32 *)((u8 *)o+8)];
    base=(u8 *)*(u32 *)(*(u32 *)((u8 *)o+12)+0x150)+model*0x18c;
    e=o->entries;
    for(i=0;i<o->n;i++,e++) {
        lbl_8006DBAC(base+0x88); lbl_8006DAEC();
        if(e->flag&1) { lbl_8006DBE4(); lbl_8006E1B0((u8 *)e+0x28,(u8 *)e+0x10); }
        lbl_8006DC20();
    }
    sort=(u32 *)fn_1_4630(lbl_801A6410, o->unk_18*4, (const char *)&lbl_1_data_40530,0x147c);
    vals=(f32 *)fn_1_4630(lbl_801A6410, o->unk_18*4, (const char *)&lbl_1_data_40530,0x147d);
    pairs=(u32 *)((u8 *)o+0x28);
    for(i=0;i<o->unk_18;i++) {
        vals[i]=*(f32 *)(pairs[2*i]+0x40)+*(f32 *)(pairs[2*i+1]+0x40);
        sort[i]=(u32)(pairs+3*i);
    }
    for(i=0;i<o->unk_18;i++) for(j=i;j<o->unk_18;j++)
        if(vals[i]<vals[j]) { f32 t; u32 z; t=vals[i]; vals[i]=vals[j]; vals[j]=t; z=sort[i];sort[i]=sort[j];sort[j]=z; }
    mode=*(u32 *)(*(u32 *)((u8 *)o+12)+0x8c);
    for(k=0;k<((mode==2||mode==3)?2:4);k++) {
        for(i=0;i<o->unk_18;i++) {
            Pair *pr=(Pair *)sort[i]; u8 *a=pr->a,*b=pr->b;
            if(a&&b) {
                V3 d; f32 dist,amount,ratio,wa,wb;
                d.a=*(f32 *)(a+0x10)-*(f32 *)(b+0x10); d.b=*(f32 *)(a+0x14)-*(f32 *)(b+0x14); d.c=*(f32 *)(a+0x18)-*(f32 *)(b+0x18);
                dist=d.a*d.a+d.b*d.b+d.c*d.c;
                if(dist-0.0001f>*(f32 *)((u8 *)pr+8)) {
                    amount=lbl_8006D118(&dist)*(dist-lbl_8006D0B4(*(f32 *)((u8 *)pr+8)));
                    d.a*=amount;d.b*=amount;d.c*=amount;
                    ratio=1.0f/(*(f32 *)(a+0x40)+*(f32 *)(b+0x40));
                    wa=-*(f32 *)(a+0x40)*ratio; wb=*(f32 *)(b+0x40)*ratio;
                    *(f32 *)(a+0x10)+=d.a*wa;*(f32 *)(a+0x14)+=d.b*wa;*(f32 *)(a+0x18)+=d.c*wa;
                    *(f32 *)(b+0x10)+=d.a*wb;*(f32 *)(b+0x14)+=d.b*wb;*(f32 *)(b+0x18)+=d.c*wb;
                }
            }
        }
        if(mode==2||mode==3) {
            DRAW(1,.12f,.115f,0,0); DRAW(16,.12f,0,0,0);
            DRAW(18,.07f,-.037f,0,0); DRAW(18,.09f,.077f,0,0); DRAW(18,.112f,.18f,-.013f,0);
            DRAW(23,.07f,-.037f,0,0); DRAW(23,.09f,.077f,0,0); DRAW(23,.112f,.18f,-.013f,0);
            DRAW(19,.069f,.051f,0,0); DRAW(19,.065f,.183f,0,0);
            DRAW(24,.069f,.051f,0,0); DRAW(24,.065f,.183f,0,0);
        } else {
            DRAW(1,.1f,.115f,0,0); DRAW(16,.1f,0,0,0);
            DRAW(16,.1f,.049f,-.002f,.021f); DRAW(16,.1f,.049f,-.002f,-.021f);
            DRAW(18,.06f,-.037f,0,0); DRAW(18,.07f,.027f,0,0); DRAW(18,.075f,.077f,0,0); DRAW(18,.085f,.119f,0,0); DRAW(18,.092f,.18f,-.013f,0);
            DRAW(23,.06f,-.037f,0,0); DRAW(23,.07f,.027f,0,0); DRAW(23,.075f,.077f,0,0); DRAW(23,.085f,.119f,0,0); DRAW(23,.092f,.18f,-.013f,0);
            DRAW(19,.059f,.051f,0,0); DRAW(19,.059f,.115f,0,0); DRAW(19,.055f,.183f,0,0);
            DRAW(24,.059f,.051f,0,0); DRAW(24,.059f,.115f,0,0); DRAW(24,.055f,.183f,0,0);
        }
    }
    if(sort) fn_1_46B4(lbl_801A6410,(u32)sort,(const char *)&lbl_1_data_40530,0x14f8);
    if(vals) fn_1_46B4(lbl_801A6410,(u32)vals,(const char *)&lbl_1_data_40530,0x14f9);
    e=o->entries;
    for(i=0;i<o->n;i++,e++) {
        f32 noise[3]; fn_1_1286F4(noise);
        *(f32 *)((u8 *)e+0x34)=*(f32 *)((u8 *)e+0x34)*.8f+(*(f32 *)((u8 *)e+0x10)-*(f32 *)((u8 *)e+0x1c))*.2f+noise[0]*.5f;
        *(f32 *)((u8 *)e+0x38)=*(f32 *)((u8 *)e+0x38)*.8f+(*(f32 *)((u8 *)e+0x14)-*(f32 *)((u8 *)e+0x20))*.2f+noise[1]*.5f;
        *(f32 *)((u8 *)e+0x3c)=*(f32 *)((u8 *)e+0x3c)*.8f+(*(f32 *)((u8 *)e+0x18)-*(f32 *)((u8 *)e+0x24))*.2f+noise[2]*.5f;
    }
    fn_1_109114(o);
}
