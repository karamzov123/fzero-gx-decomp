/* Non-matching: best partial attempt (63.63% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
struct fn_1_5233C_Copy88 { u32 a[22]; };
extern u32 lbl_1_rodata_27B0;
extern const f32 lbl_1_rodata_2764;
typedef struct Color { u8 r,g,b,a; } Color;
extern void fn_800371F8(s32, Color);
extern void fn_8003462C(u32,u32,u32);
typedef union Fifo { f32 f; u32 u; } Fifo;
extern volatile Fifo __WGPIPE; /* Hardware write-gather FIFO. */
#define __GXWGFifo __WGPIPE.f
static inline void pos(f32 x, f32 y) { __GXWGFifo=x; __GXWGFifo=y; }
struct Entry { Color color; f32 x,y; };
struct Table { struct Entry e[9]; };
static inline void vertex(f32 x,f32 y,f32 z,f32 u,f32 v) {
    __GXWGFifo=x; __GXWGFifo=y; __GXWGFifo=z; __GXWGFifo=u; __GXWGFifo=v;
}
void fn_1_5233C(void *arg0, void *arg1) {
    struct Table table = *(struct Table *)&lbl_1_rodata_27B0;
    struct fn_1_5233C_Copy88 copy;
    struct Entry *entry = &table.e[(u32)*(f32 *)((u8 *)arg0+0x54)];
    f32 dx,dy,z,u0,v0,u1,v1;
    Color color;
    f32 *p = arg1;
    if (!(*(u32 *)((u8 *)arg0+0x30) & 0x10000000)) {
        copy = *(struct fn_1_5233C_Copy88 *)arg0;
        dx = entry->x;
        dy = entry->y;
        fn_800371F8(2,entry->color);
        fn_8003462C(0x80,7,16);
        pos(p[0],p[1]-dy);
        __GXWGFifo=z=-(lbl_1_rodata_2764 + *(volatile f32 *)((u8 *)&copy+0xc));
        __GXWGFifo=u0=*(volatile f32 *)((u8 *)&copy+0x18);
        __GXWGFifo=v0=*(volatile f32 *)((u8 *)&copy+0x1c);
        pos(p[3],p[4]-dy); __GXWGFifo=z;
        __GXWGFifo=u1=*(volatile f32 *)((u8 *)&copy+0x20); __GXWGFifo=v0;
        pos(p[9],p[10]-dy); __GXWGFifo=z; __GXWGFifo=u1;
        __GXWGFifo=v1=*(volatile f32 *)((u8 *)&copy+0x24);
        vertex(p[6],p[7]-dy,z,u0,v1);
        vertex(p[0],p[1]+dy,z,u0,v0);
        vertex(p[3],p[4]+dy,z,u1,v0);
        vertex(p[9],p[10]+dy,z,u1,v1);
        vertex(p[6],p[7]+dy,z,u0,v1);
        vertex(p[0]-dx,p[1],z,u0,v0);
        vertex(p[3]-dx,p[4],z,u1,v0);
        vertex(p[9]-dx,p[10],z,u1,v1);
        vertex(p[6]-dx,p[7],z,u0,v1);
        vertex(p[0]+dx,p[1],z,u0,v0);
        vertex(p[3]+dx,p[4],z,u1,v0);
        vertex(p[9]+dx,p[10],z,u1,v1);
        vertex(p[6]+dx,p[7],z,u0,v1);
        color.r=*((u8 *)&copy+0x38);
        color.g=*((u8 *)&copy+0x39);
        color.b=*((u8 *)&copy+0x3a);
        color.a=0;
        fn_800371F8(2,color);
    }
}
