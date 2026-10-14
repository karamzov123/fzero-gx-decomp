/* Non-matching: best partial attempt (55.52% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/spline.h"

extern const f32 lbl_1_rodata_6D88[];
extern s32 fn_1_54E34(void *, f32);
extern void fn_80073778(void *, s32);
extern void fn_800728A8(s32,s32,s32,s32);
extern void fn_80074918(u8,s32,u8);
extern void fn_800720B0(u32);
extern void fn_80072864(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32,s32,s32,u32,u32,u32);
extern void fn_800734A8(u32,s32,s32,s32);
extern void fn_800735C8(s32,s32);
extern void fn_80073620(s32,s32);
extern void fn_80072C24(s32,s32,s32,s32,s32);
extern void fn_80072D64(s32,s32,s32,s32,u8,s32);
extern void fn_80072CC4(s32,s32,s32,s32,s32);
extern void fn_80072E20(s32,s32,s32,s32,u8,s32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80073898(u32);
extern void fn_80074788(u32);
extern void fn_800724C8(void);
extern void fn_8007245C(u32);
extern void lbl_8006D758(void);
extern void GXLoadPosMtxImm(u32,u32);
extern void fn_800736C0(u32,void *);
extern void fn_8003462C(u32,u32,u32);
extern void *lbl_8006DBAC(void *);
extern void fn_8006E294(void *);
extern void lbl_8006E0A4(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006E1B0(void *,void *);
extern f64 lbl_8006D0B4(f32);
extern f32 lbl_8006D668(void *);
extern s32 lbl_8006D24C(f32,f64);
extern void lbl_8006D7DC(void *);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006E15C(f32,f32,f32);
extern void lbl_8006E0C8(void *);
extern u32 lbl_801A6D00;
extern u32 lbl_801A66CC;

void fn_1_F65A0(Obj_1_data_2A7E0_At3C *obj) {
    f32 z;
    f32 scale = lbl_1_rodata_6D88[24];
    volatile f32 delta, factor;
    /* assignments follow declarations below */
    f32 v[3], p[3], q[3], d[3], n[3], verts[4][3];
    f32 f, t, radius, height;
    f32 color[4];
    s32 i,j,k,index,angle;
    u8 rgba[4];
    volatile f32 *fifo = (volatile f32 *)0xCC008000;
    delta = *(f32 *)((u8 *)obj + 8) - lbl_1_rodata_6D88[4];
    factor = delta * lbl_1_rodata_6D88[25];
    z = lbl_1_rodata_6D88[4] - factor;
    if (z >= scale) {
        if (z > lbl_1_rodata_6D88[4]) scale = lbl_1_rodata_6D88[4];
        else scale = z;
    }
    fn_80073778(*(void **)obj,0);
    fn_800728A8(1,1,1,0); fn_80074918(1,3,0);
    fn_800720B0(0); fn_80072864(0); fn_80073C6C(0);
    fn_800745A4(0,1,4,60,0,125); fn_800734A8(0,0,0,255);
    fn_800735C8(0,12); fn_80073620(0,28);
    fn_80072C24(0,15,8,14,15); fn_80072D64(0,0,0,0,1,0);
    fn_80072CC4(0,7,4,6,7); fn_80072E20(0,0,0,0,1,0);
    fn_80073678(1); fn_80074660(1); fn_80073898(0); fn_80074788(0);
    fn_800724C8(); fn_8007245C(0x2200); lbl_8006D758();
    GXLoadPosMtxImm(*(u32 *)lbl_801A6D00,0);
    rgba[0]=216; rgba[1]=122; rgba[2]=76; rgba[3]=255;
    fn_800736C0(0,rgba); fn_8003462C(0x90,0,8);
    *fifo = 0;
    *fifo = 0;
    *fifo = -10;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = -10;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = -10;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = -10;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = -10;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = -10;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = -10;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    *fifo = -10;
    *fifo = 0;
    *fifo = 0;
    *fifo = 0;
    lbl_8006DBAC((void *)(lbl_801A6D00+0x30));
    fn_8006E294(v);
    for(i=0;i<3;i++) if(v[i]<0) v[i]-=6;
    for(i=0;i<3;i++) v[i]=(f32)(s32)(v[i]*lbl_1_rodata_6D88[27])*6.0f;
    lbl_8006E0A4(v); lbl_8006DB74((void *)((u8 *)fifo+0xdc));
    lbl_8006DBAC((void *)*(u32 *)lbl_801A66CC); lbl_8006E0A4(v);
    lbl_8006DB74((void *)((u8 *)fifo+0xac));
    for(i=-1;i<=1;i++) for(j=-1;j<=1;j++) for(k=-1;k<=1;k++) {
        f32 r=(f32)k*6.0f, s=(f32)j*6.0f, u=(f32)i*6.0f;
        lbl_8006DBAC((void *)((u8 *)fifo+0xdc));
        p[0]=u;p[1]=s;p[2]=r; lbl_8006E0A4(p); lbl_8006DB74((void *)((u8 *)fifo+0x7c));
        lbl_8006DBAC((void *)((u8 *)fifo+0xac)); lbl_8006E0A4(p);
        lbl_8006DB74((void *)((u8 *)fifo+0x4c));
        for(index=0;index<36;index++) {
            Obj_1_data_2A7E0_At3C *o=obj;
            f32 *entry=(f32 *)((u8 *)o+0x14+index*0x34);
            radius=entry[9]*scale;
            if(radius<=0) continue;
            f=entry[10]*lbl_1_rodata_6D88[29]+lbl_1_rodata_6D88[4];
            if(f<lbl_1_rodata_6D88[4]) {}
            else if(f>lbl_1_rodata_6D88[28]) {}
            else f=f;
            lbl_8006DBAC((void *)((u8 *)fifo+0x7c));
            if(!fn_1_54E34(entry,entry[10]*f)) continue;
            lbl_8006E1B0(entry,d);
            if(d[2]>=-0.1) continue;
            t=lbl_8006D0B4(d[0]*d[0]+d[1]*d[1]+d[2]*d[2]);
            if(t>10) continue;
            if(t>9) radius*=10-t;
            else if(t<1) radius*=t;
            lbl_8006DBAC((void *)((u8 *)fifo+0x4c));
            q[0]=entry[0]-entry[6];q[1]=entry[1]-entry[7];q[2]=entry[2]-entry[8];
            lbl_8006E1B0(q,n);
            if(n[2]>=-0.1) continue;
            d[0]*=1.0f/d[2]; d[1]*=1.0f/d[2];
            verts[0][0]=d[0]-radius; verts[0][1]=d[1]-radius;
            verts[1][0]=d[0]+radius; verts[1][1]=d[1]-radius;
            verts[2][0]=d[0]+radius; verts[2][1]=d[1]+radius;
            verts[3][0]=d[0]-radius; verts[3][1]=d[1]+radius;
            for(angle=0;angle<4;angle++) { verts[angle][2]=d[2]; }
            lbl_8006D668(p);
            fn_8003462C(0x80,0,4);
        }
    }
}
