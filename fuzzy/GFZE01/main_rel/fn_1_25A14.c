/* Non-matching: best partial attempt (8.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/stcoli.h"
typedef struct V3 { f32 x,y,z,pad; } V3;
typedef struct V4 { V3 v[4]; } V4;
typedef struct Obj { u8 bytes[0x488]; } Obj;
extern int fn_1_2A694(void *, void *, V3 *, u32, V3 *, V3 *);
extern u32 fn_1_8C704(u32);
extern u32 fn_1_8C6D4(u32);
extern s16 fn_1_7B054(void);
extern int fn_1_2A8D0(void *, void *, u32 *, u32, void *, void *, u32 *, u32);
extern f32 lbl_1_rodata_84C[];
extern f32 lbl_1_rodata_954[];
extern void lbl_8006DAEC(void);
extern void lbl_8006DF44(void);
extern void *lbl_801A66CC;
extern void lbl_8006DB30(void);
extern void lbl_8006E1C0(void *, void *);
int fn_1_25A14(Obj *p) {
    V3 a,b;
    V4 out,in;
    u32 flags[4];
    u32 mask;
    int got,id,x,y,mode1,active,i,j,chr;
    u32 *q,*meta;
    flags[0]=flags[1]=flags[2]=flags[3]=0;
    mask=0x01020005;
    got=fn_1_2A694(p,(u8 *)p+0x3c0,0,((p->bytes[0]&2)?0x1700:0)|0x2800,&a,&b);
    id=*(s16 *)((u8 *)p+4);
    x=fn_1_8C704(id);
    y=fn_1_8C6D4(id);
    if ((s32)x<0 || x==y) mask|=0x02000000;
    mode1=fn_1_7B054();
    switch(mode1) {
    case 8:
        chr=**(u32 **)(*(u32 *)((u8 *)p+0x49c)+0x90);
        if ((chr>=0x22 && chr<=0x24)||(chr>=0x2d && chr<=0x2f)) mask|=0x80000000>>p->bytes[0x50c];
        break;
    case 16:
        chr=*(u32 *)*(u32 **)((u8 *)*(u32 *)((u8 *)p+0x49c)+0x90);
        if (chr>=0x62 && chr<=0x77) mask|=0x80000000>>p->bytes[0x50c];
        break;
    case 28:
        chr=**(u32 **)(*(u32 *)((u8 *)p+0x49c)+0x90);
        if ((chr>=0x77 && chr<=0x8e)||(chr>=0xaa && chr<=0xc4)) mask|=0x80000000>>p->bytes[0x50c];
        break;
    case 24:
        i=p->bytes[0x50c];
        if (i<4) mask|=0x80000000>>i;
        break;
    default: break;
    }
    for(i=0;i<4;i++)
        fn_1_2A8D0(p,(void *)((u8 *)p+0x3b4+i*0x30),(u32 *)((u8 *)p+0x488+i*4),mask,&out.v[i],&in.v[i],flags,1u<<(31-i));
    if(got) {
        for(i=0;i<4;i++) {
            q=*(u32 **)((u8 *)p+0x488+i*4); q=(u32 *)((u8 *)q+4);
            q[3]=*(u32 *)&a; q[4]=*(u32 *)((u8 *)&a+4); q[5]=*(u32 *)((u8 *)&a+8);
        }
    } else {
        for(i=0;i<4;i++) {
            q=*(u32 **)((u8 *)p+0x488+i*4); q=(u32 *)((u8 *)q+4);
            q[3]=0; q[4]=0; q[5]=0;
        }
    }
    if(p->bytes[0x1c8]<=lbl_1_rodata_954[0] ||
       ((*(u32 *)((u8 *)p+0x61c)&0x180)==0 && (p->bytes[0]&2))) p->bytes[0x50f]=0;
    active=0;
    mode1=fn_1_7B054();
    if(mode1!=0x1d && fn_1_7B054()!=0x27) {
        for(i=0;i<4;i++) {
            q=*(u32 **)((u8 *)p+0x488+i*4);
            if(!p->bytes[0x50f] && (*(u32 *)((u8 *)q+4)&0xf0000000)==0) continue;
            if(!(p->bytes[0]&2) && p->bytes[0x1c8]>lbl_1_rodata_954[0]) p->bytes[0x50f]=1;
            active=1; break;
        }
    }
    if(active) {
        for(i=0;i<4;i++) {
            meta=(u32 *)((u8 *)p+0x244+i*0x5c);
            *meta|=0x20;
            out.v[i].x=0; out.v[i].y=0; out.v[i].z=0;
        }
    }
    return 0;
}
