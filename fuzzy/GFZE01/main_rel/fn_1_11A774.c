/* Non-matching: best partial attempt (28.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/accessory.h"

extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D0E8(f32);
extern f32 lbl_8006D118(void *);
extern s32 fn_80077B14(void *);
extern u32 fn_1_1286F4(void *);
extern void fn_8006E250(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern void lbl_8006E1B0(void *, void *);

typedef struct { u8 pad0[0x44]; } Particle;
typedef struct { u8 pad0[0x44]; } Point;
typedef struct { u8 pad0[0xC]; } Pair;
typedef struct {
    u8 pad0[8];
    u32 index;
    u8 pad_c[4];
    u32 resource;
    u32 count;
    u32 point_count;
    u8 pad_20[4];
    u32 points;
    u32 pairs;
} Object;
typedef struct { f32 x,y,z; } Vec;

void fn_1_11A774(Object *obj) {
    Particle *p;
    Pair *pair;
    u32 i,j,k;
    u32 *res;
    f32 dx,dy,dz,d2,t,mag,scale,a,b;
    Vec centers[9];
    Point *base;
    Vec *c;
    f32 *constants=(f32 *)((u8 *)0); 
    if (!obj || !obj->resource) return;
    fn_80077B14((void *)obj->resource);
    if (*(u8 *)obj & 2) {
        *(u8 *)obj &= (u8)~2;
        res=(u32 *)&lbl_1_data_3FFBC;
        lbl_8006DBAC((u8 *)(*(u32 *)(*(u32 *)((u8 *)obj+12)+0x150)+8)+res[obj->index]*0x18c+0x88);
        lbl_8006DAEC();
        p=(Particle *)obj->points;
        for(i=0;i<obj->count;i++,p++) {
            lbl_8006DBE4();
            lbl_8006E1B0((u8 *)p+0x28,(u8 *)p+0x10);
        }
        lbl_8006DC20();
    }
    p=(Particle *)obj->points;
    for(i=0;i<obj->count;i++,p++) if (!(*(u8 *)p&1)) {
        *(u32 *)((u8 *)p+0x1c)=*(u32 *)((u8 *)p+0x10);
        *(u32 *)((u8 *)p+0x20)=*(u32 *)((u8 *)p+0x14);
        *(u32 *)((u8 *)p+0x24)=*(u32 *)((u8 *)p+0x18);
        *(f32 *)((u8 *)p+0x10)+=*(f32 *)((u8 *)p+0x34);
        *(f32 *)((u8 *)p+0x14)+=*(f32 *)((u8 *)p+0x38);
        *(f32 *)((u8 *)p+0x18)+=*(f32 *)((u8 *)p+0x3c);
        *(f32 *)((u8 *)p+0x14)-=0.0013611111376020642;
        *(f32 *)((u8 *)p+0x38)-=0.0027222223579883575f;
    }
    res=(u32 *)&lbl_1_data_3FFBC;
    base=(Point *)(*(u32 *)(*(u32 *)((u8 *)obj+12)+0x150)+8+res[obj->index]*0x18c);
    p=(Particle *)obj->points;
    for(i=0;i<obj->count;i++,p++) {
        lbl_8006DBAC((u8 *)base+0x88); lbl_8006DAEC();
        if (*(u8 *)p&1) { lbl_8006DBE4(); lbl_8006E1B0((u8 *)p+0x28,(u8 *)p+0x10); }
        lbl_8006DC20();
    }
    centers[0]=(Vec){.591f,-.018f,-.014f};
    centers[1]=(Vec){.092f,.018f,.062f};
    centers[2]=(Vec){.092f,-.018f,.062f};
    centers[3]=(Vec){.092f,.018f,.062f};
    centers[4]=(Vec){.092f,-.018f,.062f};
    centers[5]=(Vec){.092f,.018f,-.014f};
    centers[6]=(Vec){.092f,-.018f,-.014f};
    centers[7]=(Vec){.092f,.018f,.062f};
    centers[8]=(Vec){.016f,-.024f,-.014f};
    for(k=0;k<8;k++) {
        pair=(Pair *)obj->pairs;
        for(j=0;j<obj->point_count;j++,pair++) {
            Point *q=(Point *)*(u32 *)pair,*r=(Point *)*(u32 *)((u8 *)pair+4);
            if(!q||!r) continue;
            dx=*(f32 *)((u8 *)q+0x10)-*(f32 *)((u8 *)r+0x10);
            dy=*(f32 *)((u8 *)q+0x14)-*(f32 *)((u8 *)r+0x14);
            dz=*(f32 *)((u8 *)q+0x18)-*(f32 *)((u8 *)r+0x18);
            d2=dx*dx+dy*dy+dz*dz;
            if(d2-0.0001f>*(f32 *)((u8 *)pair+8)) {
                mag=lbl_8006D118(&d2);
                t=lbl_8006D0B4(*(f32 *)((u8 *)pair+8));
                t=mag*(d2-t); dx*=t; dy*=t; dz*=t;
                scale=1.0f/(*(f32 *)((u8 *)q+0x40)+*(f32 *)((u8 *)r+0x40));
                a=*(f32 *)((u8 *)q+0x40)*scale; b=*(f32 *)((u8 *)r+0x40)*scale;
                *(f32 *)((u8 *)q+0x10)-=dx*a; *(f32 *)((u8 *)q+0x14)-=dy*a; *(f32 *)((u8 *)q+0x18)-=dz*a;
                *(f32 *)((u8 *)r+0x10)+=dx*b; *(f32 *)((u8 *)r+0x14)+=dy*b; *(f32 *)((u8 *)r+0x18)+=dz*b;
            }
            if(d2+0.001f<*(f32 *)((u8 *)pair+8)) {
                mag=lbl_8006D118(&d2); t=lbl_8006D0B4(*(f32 *)((u8 *)pair+8));
                t=mag*(d2-t); dx*=t; dy*=t; dz*=t;
                scale=1.0f/(*(f32 *)((u8 *)q+0x40)+*(f32 *)((u8 *)r+0x40));
                a=*(f32 *)((u8 *)q+0x40)*scale; b=*(f32 *)((u8 *)r+0x40)*scale;
                *(f32 *)((u8 *)q+0x10)-=dx*a; *(f32 *)((u8 *)q+0x14)-=dy*a; *(f32 *)((u8 *)q+0x18)-=dz*a;
                *(f32 *)((u8 *)r+0x10)+=dx*b; *(f32 *)((u8 *)r+0x14)+=dy*b; *(f32 *)((u8 *)r+0x18)+=dz*b;
            }
        }
        c=&centers[k+1];
        p=(Particle *)obj->points;
        for(j=0;j<obj->count;j++,p++) if(!(*(u8 *)p&1)) {
            dx=*(f32 *)((u8 *)p+0x10)-c->x; dy=*(f32 *)((u8 *)p+0x14)-c->y; dz=*(f32 *)((u8 *)p+0x18)-c->z;
            d2=dx*dx+dy*dy+dz*dz;
            if(d2<0.0036f) { t=lbl_8006D0E8(d2); psvec_sub_scale_add((u8 *)p+0x10,c,0.06f*t,(u8 *)p+0x10,(u8 *)p+0x10); }
        }
    }
    p=(Particle *)obj->points;
    for(i=0;i<obj->count;i++,p++) {
        fn_1_1286F4(centers);
        *(f32 *)((u8 *)p+0x34) *= .8;
        *(f32 *)((u8 *)p+0x38) *= .8;
        *(f32 *)((u8 *)p+0x3c) *= .8;
        *(f32 *)((u8 *)p+0x34)+=.2f*(*(f32 *)((u8 *)p+0x10)-*(f32 *)((u8 *)p+0x1c));
        *(f32 *)((u8 *)p+0x38)+=.2f*(*(f32 *)((u8 *)p+0x14)-*(f32 *)((u8 *)p+0x20));
        *(f32 *)((u8 *)p+0x3c)+=.2f*(*(f32 *)((u8 *)p+0x18)-*(f32 *)((u8 *)p+0x24));
    }
    fn_80077B14((void *)obj->resource);
    lbl_8006DBAC((u8 *)base+0x88);
    p=(Particle *)obj->points;
    for(i=0;i<obj->count;i++,p++) for(j=0;j<*(u8 *)((u8 *)p+2);j++)
        fn_8006E250((u8 *)p+0x10);
}
