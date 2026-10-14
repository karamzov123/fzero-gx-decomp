/* Non-matching: best partial attempt (47.66% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

struct Copy3 { u32 x[3]; };
struct Pool {
    u8 pad[0x344];
    u32 a, b, c, d, e;
    u8 pad2[0xC - 0xC]; 
};
extern struct Pool lbl_1_rodata_840;
extern s16 fn_1_7B054(void);
extern u8 *fn_1_14F04(void);
extern u32 fn_1_2ABD4(void *, void *);
extern f32 lbl_8006D668(void *);
extern u32 lbl_801A66CC;

s32 fn_1_2AF0C(void *arg0, void *arg1, f32 arg2) {
    u8 ids[4];
    u32 *saved = (u32 *)&lbl_1_rodata_840;
    u32 masks = 0, valid = 0;
    s32 ok = 1, result = 0, cnt = 0;
    s32 i;
    u32 *pick = 0;
    u32 vals[5];
    u32 chosen=0;
    u8 *sel, *a, *b, *q, *g;
    f32 veca[3], vecb[3], len;
    f32 x, y, z, X, Y, Z;
    for (i=0;i<5;i++) vals[i]=saved[0x344/4+i];
    if (fn_1_7B054()!=36 && fn_1_7B054()!=37) ok=0;
    for (i=0;i<4;i++) {
        u8 *p = (u8 *)arg0 + 0x244 + i*4;
        u8 *entry = (u8 *)arg0 + 0x244 + i*0x5c;
        *(u8 *)((u8 *)ids+i)=4;
        *(u32 *)(fn_1_14F04()+0x700)=*(u32 *)((u8 *)arg0+0x488+i*4);
        fn_1_2ABD4(arg0,p);
        if ((*(u32 *)p & 2)==0 || (ok && ((*(u32 *)p&8)==0) && *(f32 *)((u8 *)arg0+0x1c8)>*((f32 *)((u8 *)&lbl_1_rodata_840+0xc)))) {
            u8 *g=fn_1_14F04();
            if (*(u32 *)((u8 *)&lbl_801A66CC+0) == 0) cnt=(cnt+1)&255;
            if ((*(u32 *)(g+0x118)&0xc00)!=0) result++;
            else if ((*(u32 *)(g+0x118)&0x3e00000)!=0) ids[i]=*(u8 *)(g+0x10c);
            masks |= 1u<<i;
            if ((*(u32 *)p&2)==0) valid|=1u<<i;
        }
    }
    if (valid && cnt==0 && fn_1_7B054()==15) {
        valid=0;
        for (i=0;i<4;i++) {
            u8 *q=(u8 *)arg0+0x244+i*0x5c;
            *(u32 *)q |= 10;
            *(f32 *)(q+0x58)=0.0f; *(f32 *)(q+0x44)=0.0f; *(f32 *)(q+0x2c)=0.0f;
            *(f32 *)(q+0x30)=1.0f; *(f32 *)(q+0x34)=0.0f; *(f32 *)(q+0x38)=0.0f;
            *(f32 *)(q+0x3c)=1.0f; *(f32 *)(q+0x40)=0.0f;
            *(f32 *)(q+0x4c)=0.0f; *(f32 *)(q+0x50)=0.0f; *(f32 *)(q+0x54)=0.0f;
        }
    }
    if(ids[0]==ids[1] && ids[1]==ids[2] && ids[2]==ids[3]) *((u8 *)arg0+0x50c)=ids[0];
    chosen=0;
    switch(valid) { case 15: chosen=0; break; case 14: chosen=1; break; case 13: chosen=2; break; case 11: chosen=3; break; case 7: chosen=4; break; default:
        if(ok) switch(masks) {case 15:chosen=0;break;case 14:chosen=1;break;case 13:chosen=2;break;case 11:chosen=3;break;case 7:chosen=4;break;}
    }
    if(chosen) {
        u8 *sel=(u8 *)&vals[chosen-1];
        u8 *a=(u8 *)arg0+0x264+sel[0]*0x5c;
        u8 *b=(u8 *)arg0+0x264+sel[1]*0x5c;
        psvec_sub(a,b,veca);
        veca[2]=*(f32 *)(b+8)-*(f32 *)(a+8);
        a=(u8 *)arg0+0x264+sel[2]*0x5c;
        b=(u8 *)arg0+0x264+sel[3]*0x5c;
        psvec_sub(a,b,vecb);
        vecb[2]=*(f32 *)(a+8)-*(f32 *)(b+8);
        x=veca[0]; y=veca[1]; z=veca[2]; X=vecb[0]; Y=vecb[1]; Z=vecb[2];
        veca[0]=y*Z-z*Y; veca[1]=z*X-x*Z; veca[2]=x*Y-y*X;
        len=lbl_8006D668(veca);
        if ((*(u32 *)&len & 0x7f800000)!=0x7f800000) {
            u8 *q=(u8 *)arg0+0x244;
            for(i=0;i<2;i++,q+=0xb8) {
                psvec_set(q+0x38,veca[2],veca[1],veca[0]);
                *(struct Copy3 *)arg1=*(struct Copy3 *)(q+0x38);
                if ((*(u32 *)q&8)==0) { psvec_set(q+0x2c,veca[2],veca[1],veca[0]); psvec_scale(q+0x2c,*(f32 *)(q+0x58),q+0x4c); }
                result=1;
                psvec_set(q+0x94,veca[2],veca[1],veca[0]);
                *(struct Copy3 *)arg1=*(struct Copy3 *)(q+0x94);
                if ((*(u32 *)(q+0x5c)&8)==0) { psvec_set(q+0x88,veca[2],veca[1],veca[0]); psvec_scale(q+0x88,*(f32 *)(q+0xb4),q+0xa8); }
            }
        }
    }
    if(result>=3) { *(u32 *)((u8 *)arg0+0x218)|=0x02000000; *(u32 *)((u8 *)arg0+0x58c)|=0x200; }
    return result;
}
