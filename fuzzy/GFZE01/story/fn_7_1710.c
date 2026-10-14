/* Non-matching: best partial attempt (56.66% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct R {
    u8 pad0[0x528]; f32 f528; u8 pad52c[4];
    u32 f530,f534,f538,f53c,f540,f544,f548,f54c,f550,f554,f558,f55c,f560;
    u16 f564; u8 pad566[2]; u32 f568,f56c,f570,f574,f578,f57c,f580,f584,f588,f58c,f590,f594,f598;
    u16 f59c; u8 pad59e[2]; u32 f5a0,f5a4,f5a8,f5ac; u16 f5b0;
};
struct B { u8 pad[0x10]; void *p10; u8 pad14[4]; void *p18; void *p1c; };
struct G { u16 unk0; u8 unk2,unk3; u8 pad4[12]; u16 w10,w12; };
extern struct R lbl_7_rodata_0;
extern struct B lbl_7_bss_0;
extern struct G lbl_1_bss_5138;
extern u16 lbl_1_bss_96A;
extern u8 lbl_1_bss_9C[];
extern void fn_1_4CC0(void);
extern void fn_8006CE1C(f32);
extern u32 fn_1_F9CA0(u32,u32);
extern void fn_1_F9CD0(u8,u8);
extern u32 fn_1_F9E80(u32,u32);
extern u32 fn_1_F9EB0(u32,u32);
extern s32 fn_1_F7EDC(s16);
extern int fn_1_F8334(s16);
extern void fn_1_3FDA8(void *,void *);

void fn_7_1710(void) {
    struct R *r = &lbl_7_rodata_0;
    struct B *b = &lbl_7_bss_0;
    struct G *g = &lbl_1_bss_5138;
    u32 init[40];
    s16 a[12];
    s16 q[5];
    s32 i, j;
    u32 ok;
    u8 x,y;
    s16 value;

    *(u32*)((u8*)init+86)=r->f598;
    init[10]=r->f590;
    *(u32*)((u8*)init+62)=r->f59c;
    init[12]=*(u32*)((u8*)init+86);
    *(u32*)((u8*)init+66)=r->f5a0;
    *(u16*)((u8*)q+2)=*(u32*)((u8*)init+62);
    *(u32*)((u8*)init+70)=r->f5a4;
    *(u32*)((u8*)q+6)=*(u32*)((u8*)init+66);
    *(u32*)((u8*)init+74)=r->f5a8;
    *(u32*)((u8*)q+10)=*(u32*)((u8*)init+70);
    *(u32*)((u8*)init+78)=r->f5ac;
    x=r->f5b0;
    *(u32*)((u8*)q+14)=*(u32*)((u8*)init+74);
    y=r->f570;
    value=r->f574;
    init[1]=r->f578; init[2]=r->f57c; init[3]=r->f580; init[4]=r->f584;
    init[5]=r->f588; init[6]=r->f58c;
    *(u32*)((u8*)q+18)=x;
    *(u32*)((u8*)init+6)=r->f530; *(u32*)((u8*)init+10)=r->f534;
    *(u32*)((u8*)init+14)=r->f538; *(u32*)((u8*)init+18)=r->f53c;
    *(u32*)((u8*)init+22)=r->f540; *(u32*)((u8*)init+26)=r->f544;
    *(u32*)((u8*)init+30)=r->f548; *(u32*)((u8*)init+34)=r->f54c;
    *(u32*)((u8*)init+38)=r->f550; *(u32*)((u8*)init+42)=r->f554;
    *(u32*)((u8*)init+46)=r->f558; *(u32*)((u8*)init+50)=r->f55c;
    *(u32*)((u8*)init+54)=r->f560; *(u16*)((u8*)init+58)=r->f564;
    a[0]=r->f568; a[1]=r->f56c; a[2]=y; a[3]=value;
    a[4]=r->f578; a[5]=r->f57c; a[6]=r->f580; a[7]=r->f584;
    a[8]=r->f588; a[9]=r->f58c; a[10]=r->f590; a[11]=r->f594;
    fn_1_4CC0();
    fn_8006CE1C(r->f528);
    if (*(s8*)b->p10 == 0) {
        if (fn_1_F9CA0(0,1)==0) lbl_1_bss_9C[3]=1;
        fn_1_F9CD0(0,1);
        lbl_1_bss_96A=146;
    } else {
        if (fn_1_F9E80(*(u8*)((u8*)b->p10+1),*(u8*)b->p10)==0) {
            g->w10=320; g->w12=200;
            g->unk3=0; g->unk2=0;
            x=*(u8*)b->p10; y=*((u8*)b->p10+1);
            g->unk0 += *(s16*)((u8*)init+((s8)x*6+((s8)y<<1)));
            fn_1_F9EB0(y,x);
            if ((s8)*((u8*)b->p10+1)<2)
                fn_1_F9CD0((u8)(*((u8*)b->p10+1)+1),*(u8*)b->p10);
            switch ((s8)*((u8*)b->p10+1)) {
            case 0:
                x=*(u8*)b->p10;
                if ((s8)x<9) g->pad4[0]=(u8)(x+1);
                else if ((s8)x==9 && fn_1_F7EDC(30)==0) {
                    g->pad4[g->unk3]=30; g->unk3++;
                }
                break;
            case 1:
                for(i=0,j=0;i<3;i++,j+=2) {
                    if(fn_1_F8334(*(s16*)((u8*)a+((s8)*(u8*)b->p10*6+j)-6))==0) {
                        *(s16*)((u8*)g+8+g->unk2*2)=*(s16*)((u8*)a+((s8)*(u8*)b->p10*6+j)-6);
                        g->unk2++;
                    }
                }
                if(g->unk2==0) g->unk0+=10;
                ok=1;
                for(i=1;i<10;i++) if(fn_1_F9E80(1,(u8)i)==0) ok=0;
                if((ok&0xff)!=0) { g->pad4[g->unk3]=34; g->unk3++; }
                break;
            case 2:
                x=*(u8*)b->p10;
                value=*(s16*)((u8*)q+((s8)x<<1));
                if(fn_1_F7EDC(value)==0) {
                    g->pad4[g->unk3]=(u8)*(s16*)((u8*)q+((s8)x<<1));
                    g->unk3++;
                } else g->unk0+=20;
                break;
            }
        }
        fn_1_3FDA8(b->p18,b->p1c);
        lbl_1_bss_9C[3]=1;
    }
}
