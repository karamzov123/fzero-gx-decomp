/* Non-matching: best partial attempt (49.28% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/effect.h"

typedef struct { u32 a,b,c; } V3u;
typedef struct { f32 x,y,z,w; } V4;
typedef struct { u8 pad[12]; f32 unk_C; s16 unk_10; u16 unk_12; u32 unk_14; } Spawn;
typedef struct { u8 pad[8]; u32 unk_8; } EffectObj;
typedef struct { u8 pad[0xF90]; u32 seed; } Data;
typedef struct { u8 pad[8]; u32 unk_8; } BssObj;
extern const f32 lbl_1_rodata_2950;
extern void fn_1_8636C(int, void *);
extern u32 fn_1_867CC(u32, V3u *);
extern f32 fn_1_9E14C(u32, void *, f32);
extern void fn_1_57714(u8);
extern void fn_1_57720(u32,u32,u32,u32);
extern u32 fn_1_57A70(u32,void *);
extern s32 fn_1_54E34(void *,f32);
extern void fn_1_9EA94(Spawn *);
extern int fn_1_9F914(const void *,const void *);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D668(V4 *);
extern u32 lbl_8006DCA4(void);
extern void fn_80074788(u32);
extern void fn_80072864(u32);
extern void fn_800745A4(u32,s32,s32,u32,u32,u32);
extern void fn_800734A8(u32,s32,s32,s32);
extern void fn_80072AB0(s32,s32,s32);
extern void fn_800735C8(s32,s32);
extern void fn_80073620(s32,s32);
extern void fn_80073C6C(s32);
extern void fn_80072C24(s32,s32,s32,s32,s32);
extern void fn_80072D64(s32,s32,s32,s32,u8,s32);
extern void fn_80072CC4(s32,s32,s32,s32,s32);
extern void fn_80072E20(s32,s32,s32,s32,u8,s32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80074918(u8,s32,u8);
extern void fn_800720B0(u32);
extern void fn_800728A8(s32,s32,s32,s32);
extern void fn_80073778(void *,s32);
extern void *memset(void *,int,u32);
extern u32 lbl_8006D9D8(u32);
extern void lbl_8006D7B0(void);
extern u32 lbl_8006DB74(u32);
extern void lbl_8006D848(f32);
extern u32 lbl_8006DFC4(u32);
extern void lbl_8006D95C(u32);
extern u32 mathutil_mtxA_rotate_x(u32);

void fn_1_5EB98(void *arg0, u32 arg1, u32 arg2) {
    u8 *obj = *(u8 **)((u8 *)arg0 + 8);
    Data *data = (Data *)lbl_1_data_1C698;
    u8 *pool = (u8 *)&lbl_1_rodata_2950;
    V3u vec;
    V4 delta;
    f32 p[3], q[3], colorScale, falloff, dist, t, a, b, c, alpha;
    u32 i, j, seed, *out, *end;
    EffectObj *manager;
    void *particle, *render, *scene;
    u8 rgba[4];
    u32 pos[3], base[3];
    Spawn spawn;
    u8 matrix[0x40];
    u8 transforms[0x38];
    volatile u8 stackpad[0x190];
    f32 pair[3];
    f64 dval;
    stackpad[0]=0;
    fn_1_8636C(*(s16 *)(obj+0x18), &vec);
    fn_1_867CC(*(s16 *)(obj+0x18), (V3u *)&pos);
    if (*(u16 *)(obj+0xb2)==1) {
        base[0]=*(u32 *)(obj+0x88); base[1]=*(u32 *)(obj+0x8c); base[2]=*(u32 *)(obj+0x90);
    } else { base[0]=pos[0]; base[1]=pos[1]; base[2]=pos[2]; }
    p[0]=*(f32 *)(obj+0x3c); p[1]=*(f32 *)(obj+0x40); p[2]=*(f32 *)(obj+0x44);
    q[0]=*(f32 *)&base[0]; q[1]=*(f32 *)&base[1]; q[2]=*(f32 *)&base[2];
    delta.x=p[0]-q[0]; delta.y=p[1]-q[1]; delta.z=p[2]-q[2];
    dist=lbl_8006D0B4((f32)(delta.x*delta.x)+delta.y*delta.y+delta.z*delta.z);
    seed=(data->seed * 0x41c64e6d)+12345; data->seed=seed;
    dval=(f64)seed; t=(f32)((dval-4503599627370496.0f)/32767.0f);
    falloff=(*(f32 *)(pool+0x84) * *(f32 *)(obj+0xb4));
    colorScale=*(f32 *)(obj+0xb4)*falloff;
    a=*(f32 *)(pool+0x64)+*(f32 *)(pool+0x21c)*t;
    colorScale=colorScale*a;
    if (colorScale>*(f32 *)(pool+0x28)) colorScale=*(f32 *)(pool+0x5c);
    else colorScale*=*(f32 *)(pool+0x5c);
    for(i=0;i<3;i++) rgba[i]=(u8)(colorScale*(*(f32 *)(obj+0x1c+i*4)));
    rgba[3]=255;
    q[0]=*(f32 *)(obj+0x94)-q[0]; q[1]=*(f32 *)(obj+0x98)-q[1]; q[2]=*(f32 *)(obj+0x9c)-q[2];
    delta.x=q[0];delta.y=q[1];delta.z=q[2];
    lbl_8006D668(&delta);
    q[0]*=*(f32 *)(pool+0x28)+*(f32 *)(obj+0xb4);
    q[1]*=*(f32 *)(pool+0x28)+*(f32 *)(obj+0xb4);
    q[2]*=*(f32 *)(pool+0x28)+*(f32 *)(obj+0xb4);
    *(f32 *)((u8 *)data+0x1118)=p[0];
    *(f32 *)((u8 *)data+0x111c)=q[0]; *(f32 *)((u8 *)data+0x1120)=q[0];
    *(f32 *)((u8 *)data+0x112c)=*(f32 *)(obj+0x3c);
    *(f32 *)((u8 *)data+0x1128)=*(f32 *)(obj+0x70)*(*(f32 *)(pool+0x88)*(*(f32 *)(obj+0xb4)));
    *(f32 *)((u8 *)data+0x1138)=p[1];*(f32 *)((u8 *)data+0x1140)=q[1];
    *(f32 *)((u8 *)data+0x114c)=*(f32 *)(obj+0x40);
    *(f32 *)((u8 *)data+0x1148)=*(f32 *)(obj+0x74)*(*(f32 *)(pool+0x88)*(*(f32 *)(obj+0xb4)));
    *(f32 *)((u8 *)data+0x1158)=p[2];*(f32 *)((u8 *)data+0x1160)=q[2];
    *(f32 *)((u8 *)data+0x116c)=*(f32 *)(obj+0x44);
    *(f32 *)((u8 *)data+0x1168)=*(f32 *)(obj+0x78)*(*(f32 *)(pool+0x88)*(*(f32 *)(obj+0xb4)));
    out=(u32 *)((u8 *)data+0x11c); end=out+14;
    for(i=14;i>0;i--) {
        t=*(f32 *)(pool+0x28)-(f32)i*0.0625f;
        a=fn_1_9E14C(2,(u8 *)data+0x1110,t);
        b=fn_1_9E14C(2,(u8 *)data+0x1138,t);
        c=fn_1_9E14C(2,(u8 *)data+0x1160,t);
        alpha=(*(u16 *)(obj+0xb2)==1)?(f32)(*(f32 *)(pool+0x88)*(*(f32 *)(obj+0xb4))):*(f32 *)(pool+0x6c);
        seed=data->seed*0x41c64e6d+12345;data->seed=seed; t=(f32)(((f64)seed-4503601774854144.0)/32767.0f)-0.5f;
        j=seed*0x41c64e6d+12345;data->seed=j;
        *out++=0x43300000; *out++=(j>>16)&0x7fff;
        j=j*0x41c64e6d+12345;data->seed=j;
        *out++=0x43300000;*out++=(j>>16)&0x7fff;
        j=j*0x41c64e6d+12345;data->seed=j;
        *out++=0x43300000;*out++=(j>>16)&0x7fff;
        *out++=0x43300000;*out++=(j>>16)&0x7fff;
        *(f32 *)((u8 *)out-32)=a+alpha*((f32)(((f64)*(out-7)-4503599627370496.0)/32767.0f)-0.5f);
        *(f32 *)((u8 *)out-28)=b+alpha*((f32)(((f64)*(out-5)-4503599627370496.0)/32767.0f)-0.5f);
        *(f32 *)((u8 *)out-24)=c+alpha*((f32)(((f64)*(out-3)-4503599627370496.0)/32767.0f)-0.5f);
        out=(u32 *)((u8 *)out-20);
    }
    out[0]=*(u32 *)&p[0];out[1]=*(u32 *)&p[1];out[2]=*(u32 *)&p[2];out[3]=rgba[0];
    if ((*(u32 *)(obj+0x10)*2+3)>*(s16 *)(obj+0xac)) fn_1_57714((u8)*(s16 *)(obj+0xac));
    else fn_1_57714((u8)(*(u32 *)(obj+0x10)*2+3));
    fn_1_57720(1,1,1,0);lbl_8006DCA4();fn_1_57A70(0,(u8 *)out);
    seed=data->seed*0x41c64e6d+12345; data->seed=seed;
    manager=(EffectObj *)lbl_1_bss_38458->unk_8;
    particle=*(void **)((u8 *)manager+8);
    render=*(void **)((u8 *)particle+0xa0);
    a=*(f32 *)(pool+0x6c)* *(f32 *)(obj+0xb4);
    b=*(f32 *)(pool+0x54);c=*(f32 *)(pool+0x28);
    t=(f32)(((f64)seed-4503599627370496.0)/32767.0f);
    falloff=*(f32 *)(pool+0x5c)*((*(f32 *)(pool+0x94)+b*a)*(c+t));
    fn_80074788(0);fn_80072864(0);fn_800745A4(0,1,4,60,0,125);
    fn_800734A8(0,0,0,255);fn_80072AB0(0,0,0);fn_800735C8(0,12);fn_80073620(0,28);fn_80073C6C(0);
    fn_80072C24(0,15,15,15,14);fn_80072D64(0,0,0,0,1,0);fn_80072CC4(0,7,6,4,7);fn_80072E20(0,0,0,0,1,0);
    fn_80073678(1);fn_80074660(1);fn_80074918(1,3,0);fn_800720B0(0);fn_800728A8(1,4,1,0);
    fn_80073778(*(void **)((u8 *)render+0x24),0);memset(&spawn,0,24);
    spawn.unk_C=*(f32 *)(pool+0x150)*falloff;
    lbl_8006D9D8((u32)p);lbl_8006D7B0();
    if(fn_1_54E34((u8 *)render+8,c+a)) {
        psvec_set(&delta.z,*(f32 *)0xe000002c,*(f32 *)0xe000001c,*(f32 *)0xe000000c);
        dist=lbl_8006D0B4(delta.x*delta.x+delta.y*delta.y+delta.z*delta.z);
        if(dist>*(f32 *)(pool+4)+c+a){lbl_8006DB74((u32)matrix);lbl_8006D848((dist-c-a)/dist);lbl_8006DFC4((u32)matrix);}
        spawn.unk_C=*(f32 *)(pool+0x150)*(c+a);spawn.unk_10=0;fn_1_9EA94(&spawn);
    }
    lbl_8006D9D8((u32)base);lbl_8006D7B0();
    if(fn_1_54E34((u8 *)render+8,c+a)) {
        psvec_set(&delta.z,*(f32 *)0xe000002c,*(f32 *)0xe000001c,*(f32 *)0xe000000c);
        dist=lbl_8006D0B4(delta.x*delta.x+delta.y*delta.y+delta.z*delta.z);
        if(dist>*(f32 *)(pool+4)+c+a){lbl_8006DB74((u32)matrix);lbl_8006D848((dist-c-a)/dist);lbl_8006DFC4((u32)matrix);}
        spawn.unk_C=*(f32 *)(pool+0x150)*(c+a);spawn.unk_10=0;fn_1_9EA94(&spawn);
    }
    if(*(u16 *)(obj+0xb2)==1) {
        void *scene=*(void **)((u8 *)lbl_1_bss_38458->unk_8+8);
        lbl_8006D9D8((u32)&pos);lbl_8006D95C(*(s16 *)(obj+0x56));mathutil_mtxA_rotate_x(*(s16 *)(obj+0x54));
        memset(matrix,0,0x40);lbl_8006DB74((u32)transforms);
        a=*(f32 *)(pool+0x224)**(f32 *)(obj+0x28);b=*(f32 *)(pool+0x150)*a;
        *(f32 *)matrix=b;*(f32 *)(matrix+4)=b;
        *(u32 *)(transforms+0x34)=(u32)(*(f32 *)(pool+0x5c)**(f32 *)(obj+0x1c));
        *(u32 *)(transforms+0x35)=(u32)(*(f32 *)(pool+0x5c)**(f32 *)(obj+0x20));
        *(u32 *)(transforms+0x36)=(u32)(*(f32 *)(pool+0x5c)**(f32 *)(obj+0x24));
        transforms[0x37]=255;fn_1_9F914(matrix,scene);
    }
}
