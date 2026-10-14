/* Non-matching: best partial attempt (45.24% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/option/globals.h"
#include "font.h"

struct fn_4_40C4_Copy88 { u32 a[22]; };
struct fn_4_40C4_rodata {
    u8 pad_0[0x8]; f32 f8;
    u8 pad_C[4]; f64 f10;
    f64 f18;
    u8 pad_20[8]; f64 f28; f64 f30;
    u32 w38; f32 f3c; u32 w40; f32 f44; f32 f48; f32 f4c;
    f32 f50; f32 f54; u8 pad_58[8]; f64 f60; f64 f68; f32 f70;
    u8 pad_74[4]; f64 f78; u8 pad_80[0x10]; f64 f90;
    u8 pad_98[0x2c]; f32 fc4; f32 fc8;
    u8 pad_cc[0x34]; f32 f100;
    u8 pad_104[0x3c]; f32 f140;
    u8 pad_144[0x54]; f32 f198; u8 pad_19c[4]; f32 f1a0;
    u8 pad_1a4[0x40]; f64 f1e8; f32 f1f0; f32 f1f4; f32 f1f8; f32 f1fc;
    f64 f200; f64 f208; f32 f210; f32 f214;
};
struct fn_4_40C4_bss { u8 pad[0xba]; u8 unk_ba; u8 unk_bb; u8 unk_bc[0x48]; };
struct fn_4_40C4_data { u8 pad[0x1500]; };
extern struct fn_4_40C4_rodata lbl_4_rodata_0;
extern u16 lbl_4_bss_0;
extern u8 lbl_4_data_0[0xC];
extern s32 lbl_801A66B4;
extern struct fn_4_40C4_Copy88 lbl_1_rodata_26F8;
extern void fn_1_49410(void);
extern u32 fn_1_5233C(void);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32,f32);
extern f32 fn_1_4B040(s32);
extern void fn_1_496FC(f32,f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_53BD8(void *,f32,f32,f32,f32,f32);
extern void fn_1_4954C(f32);
extern int sprintf(char *,const char *,...);
extern int fn_1_4F734(FontDrawPacket *);
extern f32 lbl_8006D188(s16);
extern void _savegpr_23(void);
extern void _restgpr_23(void);

void fn_4_40C4(u32 arg0,u32 arg1,f32 arg2) {
    struct fn_4_40C4_bss *b=(struct fn_4_40C4_bss *)&lbl_4_bss_0;
    u8 *d=(u8 *)&lbl_4_data_0;
    struct fn_4_40C4_rodata *p=&lbl_4_rodata_0;
    f32 width, maxv, val;
    s32 i, step, idx, angle;
    u32 *names;
    char buf[256];
    struct fn_4_40C4_Copy88 copy;
    struct fn_4_40C4_Copy88 packet1, packet2;
    fn_1_49410();
    fn_1_49738(fn_1_5233C());
    fn_1_49748(p->f48);
    fn_1_495C8(9);
    if (lbl_801A66B4!=5) { fn_1_495B0(0x80000000); fn_1_49590(p->f8); }
    fn_1_4955C(p->fc4,p->fc4);
    width=fn_1_4B040(arg1);
    fn_1_496FC(p->f50,p->fc8);
    fn_1_4AE0C((char *)d+0x1210,arg1);
    fn_1_53BD8(0,p->f50,p->fc8,(f32)(p->f60+width+p->f1e8),(f32)(p->f68+p->f140),p->f70);
    maxv=0.0f;
    fn_1_49410();
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(p->f48);
    fn_1_495C8(9);
    if (lbl_801A66B4!=5) { fn_1_495B0(0x80000000); fn_1_49590(p->f8); }
    for(i=0,step=-0x48;i<4;i++,step+=0x30) {
        val=(f32)(s32)(step+0x118);
        fn_1_496FC(p->f50,val);
        if ((b->unk_ba >> ((0x20-i)&31))&1) names=*(u32 **)((u8 *)&lbl_4_data_0+0x8e0)+lbl_801A66B4;
        else names=*(u32 **)((u8 *)&lbl_4_data_0+0x900)+lbl_801A66B4;
        if(lbl_801A66B4!=5) {
            fn_1_4954C(p->f1f0);
            sprintf(buf,(char *)d+0x14e8, *(char **)((u8 *)d+0x20+4*lbl_801A66B4),i+1,names);
            fn_1_4AE0C((char *)d+0x1210,buf);
            fn_1_4954C(p->f1f4);
            fn_1_496FC(p->f1f8,val);
            fn_1_4AE0C((char *)d+0x1210,names);
        } else {
            sprintf(buf,(char *)d+0x14f4, *(char **)((u8 *)d+0x20+4*lbl_801A66B4),i+1,names);
            fn_1_4AE0C((char *)d+0x1210,buf);
        }
        val=fn_1_4B040((s32)buf);
        if(val>maxv) maxv=val;
    }
    if (*(u8 *)(d+0x14e2)!=arg0 || *(s16 *)(d+0x14e4)!=b->unk_bb) {
        *(u8 *)(d+0x14e2)=arg0; *(s16 *)(d+0x14e4)=b->unk_bb; *(u8 *)((u8 *)b+2)=0;
    }
    if(b->unk_bb==1) {
        copy=lbl_1_rodata_26F8;
        angle=(s32)(arg0*2-3)*0x18+0x118;
        packet1.a[0]=0x12;
        packet1.a[1]=0x43a00000; packet1.a[2]=0; packet1.a[3]=0x3e19999a;
        packet1.a[4]=(u32)((f32)(angle)-p->f78);
        packet1.a[5]=0x40600000;
        packet1.a[12]=10; packet1.a[11]=0x3f19999a; packet1.a[14]=p->w38;
        fn_1_4F734((FontDrawPacket *)&packet1);
        val=((b->unk_ba >> ((0x20-arg0)&31))&1)?2.0f:3.0f;
        packet2.a[0]=0x12; packet2.a[1]=0x40400000;
        packet2.a[2]=0; packet2.a[3]=0x3dcccccd; packet2.a[4]=0;
        packet2.a[5]=0x3e800000; packet2.a[6]=0x41c00000;
        packet2.a[7]=(u32)(f32)(val*p->f18);
        packet2.a[8]=0x40600000; packet2.a[12]=9; packet2.a[14]=p->w40;
        angle=((s32)*(u8 *)((u8 *)b+2)<<10)+0x4000;
        packet2.a[15]=(u32)(f32)((p->f90+((f64)angle-p->f78)*p->f200));
        fn_1_4F734((FontDrawPacket *)&packet2);
    } else if(b->unk_bb==0) {
        copy=lbl_1_rodata_26F8;
        angle=(s32)(arg0*2-3)*0x18+0x118;
        packet2.a[0]=0x12; packet2.a[1]=0x43a00000;
        packet2.a[2]=0; packet2.a[3]=0x3e19999a;
        packet2.a[4]=(u32)(f32)((f64)angle-p->f78);
        packet2.a[5]=0x40600000; packet2.a[12]=10;
        angle=((s32)*(u8 *)((u8 *)b+2)<<10)+0x4000;
        packet2.a[15]=(u32)(f32)((p->f90+((f64)angle-p->f78)*p->f200));
        fn_1_4F734((FontDrawPacket *)&packet2);
    }
    fn_1_53BD8(0,p->f50,p->fc8,(f32)(p->f60+maxv),(f32)(p->f68+p->f214),p->f70);
}
