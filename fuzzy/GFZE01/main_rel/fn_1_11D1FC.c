/* Non-matching: best partial attempt (43.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

typedef struct Item {
    u8 type, category;
    u8 pad02[0x0E];
    f32 x, y, z;
    u8 pad1C[0x24];
    f32 score;
} Item;
typedef struct Manager {
    u8 pad00[0x18];
    u32 count;
    u32 lineCount;
    u32 itemCount;
    Item *items;
    void *lines;
    void *points;
} Manager;
typedef struct Point {
    u8 pad[0x10];
    f32 x,y,z;
} Point;
typedef struct Line { Point *a,*b; f32 length; } Line;
typedef struct Pool {
    u8 pad[0x20]; f32 threshold; u8 p24[0x24]; f32 quarter; u8 p4c[4];
    f64 bias; u8 p58[0xc]; f32 minusOne, zero;
    u8 p6c[0x20c]; f32 high;
    u8 p27c[0x2c]; f32 low;
    u8 p2ac[0x19c]; f32 init[15];
} Pool;
typedef struct Alloc { u32 value; } Alloc;
extern Pool lbl_1_rodata_7AB8;
extern Alloc lbl_801A6410;
extern u32 fn_1_10846C(Manager *);
extern void *fn_1_4630(u32, u32, const char *, int);
extern void fn_1_128884(void *, void *, int);
extern f32 fn_1_1289BC(const Point *, const Point *);
extern void OSPanic(const char *, int, const char *, ...);

void fn_1_11D1FC(Manager *m) {
    u32 i,j;
    Item *a,*b;
    Point *pts, *p;
    Line *lines;
    f32 x,y,z;
    u32 n0,n1,n2,n3,n4;
    if (m == 0) return;
    fn_1_10846C(m);
    a=m->items;
    for(i=0;i<m->count;i++,a++) {
        if(a->type&1) { a->score=lbl_1_rodata_7AB8.minusOne; a->type=0; a->category=1; }
        else if(a->x>lbl_1_rodata_7AB8.high) { a->score=0; a->type=1; a->category=0; }
        else if(a->x<lbl_1_rodata_7AB8.low && a->z>lbl_1_rodata_7AB8.threshold) { a->score=0; a->type=1; a->category=4; }
        else if(a->x<lbl_1_rodata_7AB8.low && a->y<lbl_1_rodata_7AB8.threshold) { a->score=0; a->type=1; a->category=5; }
        else if(a->y>0) { a->score=0; a->type=1; a->category=2; }
        else { a->score=0; a->type=1; a->category=3; }
    }
    for(i=0;i<m->count;i++) for(j=i+1;j<m->count;j++) {
        a=&m->items[i]; b=&m->items[j];
        if(a->category>b->category) fn_1_128884(a,b,0x44);
    }
    for(i=0;i<m->count;i++) for(j=i+1;j<m->count;j++) {
        a=&m->items[i]; b=&m->items[j];
        if(a->category==b->category && a->x<b->x) fn_1_128884(a,b,0x44);
    }
    for(i=0;i<m->count;i++) for(j=i+1;j<m->count;j++) {
        a=&m->items[i]; b=&m->items[j];
        if(a->category==0 && b->category==0 && a->y<b->y) fn_1_128884(a,b,0x44);
    }
    for(i=0;i<m->count;i+=8) for(j=0;j<8;j++) {
        u32 k;
        for(k=j+1;k<8;k++) {
            a=&m->items[i+j]; b=&m->items[i+k];
            if(a->category==1 && b->category==1 && a->y<b->y) fn_1_128884(a,b,0x44);
        }
    }
    m->itemCount=14;
    pts=fn_1_4630(lbl_801A6410.value,14*0x44,(const char *)&lbl_1_data_40530,0x215a);
    m->points=pts;
    ((u8 *)pts)[0]=1; ((u8 *)pts)[0x44]=1;
    a=m->items; p=pts+1;
    for(i=0;i<m->count;i++,a+=4) {
        if(a[0].category==0 || a[0].category==1) {
            x=lbl_1_rodata_7AB8.init[0]; y=lbl_1_rodata_7AB8.init[1]; z=lbl_1_rodata_7AB8.init[2];
            for(j=0;j<4;j++) { x+=a[j].x; y+=a[j].y; z+=a[j].z; }
            for(j=0;j<4;j++) { x+=a[j].score; y+=a[j].score; z+=a[j].score; }
            x*=lbl_1_rodata_7AB8.quarter; y*=lbl_1_rodata_7AB8.quarter; z*=lbl_1_rodata_7AB8.quarter;
            p->x=x;p->y=y;p->z=z;p->pad[0]=0;
            p->x=x;p->y=y;p->z=z;p++;
        }
    }
    x=lbl_1_rodata_7AB8.init[3]; y=lbl_1_rodata_7AB8.init[4]; z=lbl_1_rodata_7AB8.init[5]; n0=0;
    for(i=0;i<m->count;i++) if(m->items[i].category==2) {x+=m->items[i].x;y+=m->items[i].y;z+=m->items[i].z;n0++;}
    p=pts+1+n0; p->x=x/(f32)n0;p->y=y/(f32)n0;p->z=z/(f32)n0;
    x=lbl_1_rodata_7AB8.init[6]; y=lbl_1_rodata_7AB8.init[7]; z=lbl_1_rodata_7AB8.init[8]; n1=0;
    for(i=0;i<m->count;i++) if(m->items[i].category==3) {x+=m->items[i].x;y+=m->items[i].y;z+=m->items[i].z;n1++;}
    p++; p->x=x/(f32)n1;p->y=y/(f32)n1;p->z=z/(f32)n1;
    x=lbl_1_rodata_7AB8.init[9]; y=lbl_1_rodata_7AB8.init[10]; z=lbl_1_rodata_7AB8.init[11]; n2=0;
    for(i=0;i<m->count;i++) if(m->items[i].category==4) {x+=m->items[i].x;y+=m->items[i].y;z+=m->items[i].z;n2++;}
    p++; p->x=x/(f32)n2;p->y=y/(f32)n2;p->z=z/(f32)n2;
    x=lbl_1_rodata_7AB8.init[12]; y=lbl_1_rodata_7AB8.init[13]; z=lbl_1_rodata_7AB8.init[14]; n3=0;
    for(i=0;i<m->count;i++) if(m->items[i].category==5) {x+=m->items[i].x;y+=m->items[i].y;z+=m->items[i].z;n3++;}
    p++; p->x=x/(f32)n3;p->y=y/(f32)n3;p->z=z/(f32)n3;
    m->lineCount=16;
    lines=fn_1_4630(lbl_801A6410.value,16*12,(const char *)&lbl_1_data_40530,0x21c1);
    m->lines=lines;
    p=pts;
    for(i=0;i<16;i++) { lines[i].a=p+i; lines[i].b=p+i+2; lines[i].length=fn_1_1289BC(p+i,p+i+2); }
}
