/* Non-matching: best partial attempt (15.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect_car.h"

typedef struct { f32 x, y, z; } Vec3;
typedef struct { u8 pad[0xE8]; } Shape;
typedef struct { u8 pad[0x3DC]; } Pool;
typedef struct { f32 x,y,z; } VOut;
extern Pool lbl_1_rodata_2D70;
extern void *fn_1_86254(int);
extern void *fn_1_868C0(s8);
extern void fn_1_862D4(int, VOut *);
extern void fn_1_8658C(int, VOut *);
extern void fn_1_8636C(int, void *);
extern void fn_1_862A8(int, Vec3 *);
extern void fn_1_A33F0(s32, f32);
extern f32 lbl_8006D668(void *);
extern void lbl_8006D5F0(void *, f32);
extern void lbl_8006DD14(void *, void *);
extern f32 lbl_8006D0B4(f32);
extern void fn_1_6CF3C(Shape *, Vec3 *, f32, f32);
extern u32 fn_1_584AC(void);
extern s16 fn_1_58F50(const void *);
extern s16 camera_get_entry_field_0xa4(u32);
extern void fn_1_6E140(VOut *, Vec3 *, f32);
extern void *memset(void *, int, u32);

void fn_1_68B6C(s8 arg0, s8 arg1, f32 arg2) {
    Shape shape;
    Vec3 a,b,c,d,e,f,g;
    VOut v0,v1,v2,v3;
    f32 x,y,z,xx,yy,zz,scale,randScale,q;
    void *cam0,*cam1;
    s32 id0=(s8)arg0, id1=(s8)arg1;
    f32 *p=(f32 *)&lbl_1_rodata_2D70;
    cam0=fn_1_86254(id0);
    cam1=fn_1_86254(id1);
    if ((*(u32 *)((u8 *)fn_1_868C0(arg0)+0x390)&0x01000000) ||
        (*(u32 *)((u8 *)fn_1_868C0(arg1)+0x390)&0x01000000) ||
        (*(s16 *)((u8 *)fn_1_868C0(arg0)+0x3ba)>=3 &&
         (s8)*(u8 *)((u8 *)cam0+0x475)==-1)) return;
    memset(&shape,0,0xe8);
    *(u16 *)((u8 *)&shape+0x1a)=0xffff;
    *(f32 *)((u8 *)&shape+0x1c)=255.0f;
    *(f32 *)((u8 *)&shape+0x20)=102.0f;
    *(f32 *)((u8 *)&shape+0x24)=0.0f;
    fn_1_862D4(id0,&v0); fn_1_862D4(id1,&v1);
    fn_1_8658C(id0,&v2); fn_1_8658C(id1,&v3);
    fn_1_8636C(id0,&a); fn_1_8636C(id1,&b);
    x=v0.x-v2.x; y=v0.y-v2.y; z=v0.z-v2.z;
    xx=v1.x-v3.x; yy=v1.y-v3.y; zz=v1.z-v3.z;
    c.x=v1.x-v0.x; c.y=v1.y-v0.y; c.z=v1.z-v0.z;
    d.x=v1.x-v3.x; d.y=v1.y-v3.y; d.z=v1.z-v3.z;
    e.x=xx-x; e.y=yy-y; e.z=zz-z;
    f.x=v1.x-v0.x; f.y=v1.y-v0.y; f.z=v1.z-v0.z;
    g.x=v1.x-v0.x; g.y=v1.y-v0.y; g.z=v1.z-v0.z;
    /* Geometry outputs */
    a.x=v1.x-v2.x; a.y=v1.y-v2.y; a.z=v1.z-v2.z;
    b.x=v1.x-v2.x; b.y=v1.y-v2.y; b.z=v1.z-v2.z;
    x=(v1.x-v3.x)- (v0.x-v2.x);
    y=(v1.y-v3.y)- (v0.y-v2.y);
    z=(v1.z-v3.z)- (v0.z-v2.z);
    c.x=v1.x-v3.x; c.y=v1.y-v3.y; c.z=v1.z-v3.z;
    fn_1_862A8(id0,&a); fn_1_862A8(id1,&b);
    fn_1_862D4(id0,&v0); fn_1_862D4(id1,&v1);
    fn_1_862A8(id0,&c); fn_1_862A8(id1,&d);
}
