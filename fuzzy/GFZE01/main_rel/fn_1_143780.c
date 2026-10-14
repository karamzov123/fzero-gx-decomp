/* Non-matching: best partial attempt (63.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

struct Pool {
    u8 pad0[0x11c]; f32 f11c; u8 pad120[8]; f64 f128;
    u8 pad130[0x60]; f32 f190; u8 pad194[0x2c]; f64 f1c0;
    u8 pad1c8[0x20]; u32 c1e8,c1ec,c1f0,c1f4,c1f8,c1fc,c200,c204,c208,c20c,c210,c214,c218,c21c;
    f32 f220,f224,f228,f22c,f230,f234,f238;
};
struct Copy22 { u32 a[22]; };
struct Color { u8 a[4]; };
extern struct Pool lbl_1_rodata_92C0;
extern struct Copy22 lbl_1_rodata_26F8;
extern struct { u32 value; } lbl_801A66A4;
extern u8 lbl_1_data_424A0[0xC];
extern f32 lbl_8006D188(u32);
extern u32 fn_1_144A5C(void *);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern u8 fn_1_3F114(void);
extern void fn_1_143E7C(u32,u32,u32,u32,u32,u32,void *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_496FC(f32,f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4955C(f32,f32);
extern void fn_1_4AE0C(const char *,...);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);

void fn_1_143780(u32 arg0,u32 arg1,u32 arg2) {
    struct Pool *p = &lbl_1_rodata_92C0;
    u32 a[10], b[9], c[6], d[4];
    FontDrawPacket packet;
    u32 tmp;
    s32 i;
    u32 count;
    u32 *obj;
    f32 t;
    a[0]=arg0; a[1]=arg1; a[2]=354; a[3]=222; a[4]=340; a[5]=208;
    a[6]=(u32)&d[0]; a[7]=4; a[8]=(u32)&c[0]; a[9]=6;
    d[0]=p->c1f8; d[1]=p->c1fc; d[2]=p->c200; d[3]=p->c204;
    b[0]=p->c1e8; b[1]=p->c1f4; b[2]=p->c1ec; b[3]=p->c1e8;
    b[4]=p->c1f0; b[5]=p->c1f4; b[6]=p->c1f0; b[7]=p->c1ec; b[8]=p->c1e8;
    c[0]=p->c208; c[1]=p->c20c; c[2]=p->c210; c[3]=p->c214; c[4]=p->c218; c[5]=p->c21c;
    fn_1_144A5C(a);
    packet=*(FontDrawPacket *)&lbl_1_rodata_26F8;
    packet.image=0x10000-26365;
    fn_1_51678(&packet,packet.image,0,108,96,36);
    packet.x=(f32)(s32)(arg0+22); packet.y=(f32)(s32)(arg1+179);
    packet.z=p->f220; packet.scale_x=packet.scale_x*p->f224; packet.scale_y=packet.scale_y*p->f224;
    fn_1_4F734(&packet);
    obj=(u32 *)((u8 *)&lbl_1_bss_26314+arg2*0x1fc);
    count=fn_1_3F114()&0xff;
    if(count<=5) {
        for(i=0;i<(s32)count;i++) {
            u8 *entry=(u8 *)obj+(((count-1-i)*12)+0x16c);
            if(*(u32 *)entry==obj[0x1cc/4] && *(f32 *)(entry+4)==*(f32 *)((u8 *)obj+0x1d0)) b[0]=b[5];
            else b[0]=b[8];
            fn_1_143E7C(arg0+332,arg1+18,arg2,entry[8],entry[9],*(u16 *)(entry+10),b);
            packet=*(FontDrawPacket *)&lbl_1_rodata_26F8;
            packet.image=0x10000-26365;
            fn_1_51678(&packet,packet.image,0,36,96,36);
            packet.x=(f32)(s32)(arg0+22); packet.y=(f32)(s32)(arg1+16+i*32);
            packet.z=p->f220; packet.scale_x=packet.scale_x*p->f224; packet.scale_y=packet.scale_y*p->f224;
            *(u32 *)((u8 *)&packet+56)=b[0];
            fn_1_4F734(&packet); fn_1_49410(); fn_1_494DC(19);
            fn_1_496FC((f32)(s32)(arg0+80),(f32)(s32)(arg1+18+i*32));
            tmp=b[0]; fn_1_49514(&tmp);
            fn_1_4955C(p->f224,p->f224);
            fn_1_4AE0C((const char *)lbl_1_data_424A0,i+1);
        }
    } else {
        packet=*(FontDrawPacket *)&lbl_1_rodata_26F8;
        packet.image=0x10000-26368;
        packet.x=(f32)(s32)(arg0+22); packet.y=(f32)(s32)(arg1+7); packet.z=p->f220;
        fn_1_4F734(&packet);
        tmp=c[0];
        fn_1_143E7C(arg0+332,arg1+18,arg2,*((u8 *)obj+0x1d4),*((u8 *)obj+0x1d5),*(u16 *)((u8 *)obj+0x1e2),&tmp);
    }
    tmp=b[3];
    fn_1_143E7C(arg0+332,arg1+179,arg2,*((u8 *)obj+0x1e0),*((u8 *)obj+0x1e1),*(u16 *)((u8 *)obj+0x1e2),&tmp);
    packet=*(FontDrawPacket *)&lbl_1_rodata_26F8;
    packet.image=18; packet.x=(f32)(s32)(arg0+1); packet.y=(f32)(s32)(arg1+176); packet.z=p->f228;
    *(u32 *)((u8 *)&packet+56)=b[2];
    packet.scale_x=packet.scale_x*(p->f22c/(f32)fn_1_48690(18));
    t=(f32)fn_1_486C4(packet.image);
    packet.scale_y=packet.scale_y*(p->f220/t);
    t=(f32)(lbl_801A66A4.value-(((lbl_801A66A4.value/120)*120)));
    t=p->f230*t/p->f234;
    t=lbl_8006D188((u32)(s32)t);
    {
        f32 q=(p->f190+t)*p->f11c, r=p->f190-(p->f190+t)*p->f11c;
        u8 *color=(u8 *)&b[0]+24;
        packet.color[0]=(s32)((f32)color[1]*r+(f32)color[0]*q);
        packet.color[1]=(s32)((f32)color[2]*r+(f32)color[1]*q);
        packet.color[2]=(s32)((f32)color[3]*r+(f32)color[2]*q);
        packet.alpha=p->f238;
    }
    fn_1_4F734(&packet);
}
