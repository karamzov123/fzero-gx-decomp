/* Non-matching: best partial attempt (65.14% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

typedef struct {
    u8 flags;
    u8 unk1;
    u8 childCount;
    u8 unk3;
    u16 children[30];
    u8 pad40[0x44-0x40];
} Node;
typedef struct { Node *a; Node *b; f32 threshold; } Pair;
typedef struct {
    u8 flags;
    u8 pad1[7];
    u32 index;
    u8 padc[0x10-0xc];
    void *resource;
    u8 pad14[4];
    u32 count;
    u8 pad1c[8];
    Node *nodes;
    Pair *pairs;
} Manager;
extern f32 lbl_8006D118(f32);
extern f32 lbl_8006D0B4(f32);
extern void *fn_80077B14(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern void lbl_8006E1B0(void *, void *);
extern void fn_8006E250(void *, void *);
extern void fn_1_1286F4(void *);
extern u8 lbl_1_rodata_7AB8[];
extern Obj_1_data_3FFBC lbl_1_data_3FFBC;

void fn_1_10D7D4(Manager *m) {
    u32 i;
    Node *n;
    Pair *p;
    void *asset;
    f32 dx, dy, dz, d2, scale;
    f32 *impulse;
    if (m == 0 || m->resource == 0) return;
    fn_80077B14(m->resource);
    if (m->flags & 2) {
        m->flags &= (u8)~2;
        asset = *(void **)((u8 *)*(u32 *)((u8 *)m->resource + 0x150) + 8);
        asset = (u8 *)asset + ((u32 *)&lbl_1_data_3FFBC)[m->index] * 0x18c + 0x88;
        lbl_8006DBAC(asset);
        lbl_8006DAEC();
        for (i=0,n=m->nodes;i<m->count;i++,n++) {
            lbl_8006DBE4();
            lbl_8006E1B0((u8 *)n+0x28, (u8 *)n+0x10);
        }
        lbl_8006DC20();
    }
    for (i=0,n=m->nodes;i<m->count;i++,n++) {
        if (!(n->flags & 1)) {
            *(u32 *)((u8 *)n+0x1c)=*(u32 *)((u8 *)n+0x10);
            *(u32 *)((u8 *)n+0x20)=*(u32 *)((u8 *)n+0x14);
            *(u32 *)((u8 *)n+0x24)=*(u32 *)((u8 *)n+0x18);
            *(f32 *)((u8 *)n+0x10)+=*(f32 *)((u8 *)n+0x34);
            *(f32 *)((u8 *)n+0x14)+=*(f32 *)((u8 *)n+0x38)*-*(f32 *)((u8 *)n+0x40);
            *(f32 *)((u8 *)n+0x18)+=*(f32 *)((u8 *)n+0x3c);
            *(f32 *)((u8 *)n+0x14)-=*(f64 *)(lbl_1_rodata_7AB8+0x58);
            *(f32 *)((u8 *)n+0x38)-=*(f32 *)(lbl_1_rodata_7AB8+0x60);
        }
    }
    asset = *(void **)((u8 *)*(u32 *)((u8 *)m->resource+0x150)+8);
    asset = (u8 *)asset + ((u32 *)&lbl_1_data_3FFBC)[m->index]*0x18c;
    for (i=0,n=m->nodes;i<m->count;i++,n++) {
        lbl_8006DBAC((u8 *)asset+0x88);
        lbl_8006DAEC();
        if(n->flags&1) { lbl_8006DBE4(); lbl_8006E1B0((u8 *)n+0x28, (u8 *)n+0x10); }
        lbl_8006DC20();
    }
    for(i=0,p=m->pairs;i<*(u32 *)((u8 *)m+0x1c);i++,p++) {
        Node *a=p->a,*b=p->b;
        if(a && b) {
            dx=*(f32 *)((u8 *)a+0x10)-*(f32 *)((u8 *)b+0x10);
            dy=*(f32 *)((u8 *)a+0x14)-*(f32 *)((u8 *)b+0x14);
            dz=*(f32 *)((u8 *)a+0x18)-*(f32 *)((u8 *)b+0x18);
            d2=dx*dx+dy*dy+dz*dz;
            if(d2-*(f32 *)(lbl_1_rodata_7AB8+0x9c)>p->threshold) {
                scale=lbl_8006D118(d2);
                scale*=d2-lbl_8006D0B4(p->threshold);
                dx*=scale; dy*=scale; dz*=scale;
                *(f32 *)((u8 *)a+0x10)-=dx*(*(f32 *)((u8 *)a+0x40)*(*(f32 *)(lbl_1_rodata_7AB8+0xa0)/(*(f32 *)((u8 *)a+0x40)+*(f32 *)((u8 *)b+0x40))));
                *(f32 *)((u8 *)a+0x14)-=dy*(*(f32 *)((u8 *)a+0x40)*(*(f32 *)(lbl_1_rodata_7AB8+0xa0)/(*(f32 *)((u8 *)a+0x40)+*(f32 *)((u8 *)b+0x40))));
                *(f32 *)((u8 *)a+0x18)-=dz*(*(f32 *)((u8 *)a+0x40)*(*(f32 *)(lbl_1_rodata_7AB8+0xa0)/(*(f32 *)((u8 *)a+0x40)+*(f32 *)((u8 *)b+0x40))));
            }
        }
    }
    asset = *(void **)((u8 *)*(u32 *)((u8 *)m->resource+0x150)+8);
    asset = (u8 *)asset+((u32 *)&lbl_1_data_3FFBC)[m->index]*0x18c;
    for(i=0,n=m->nodes;i<m->count;i++,n++) {
        lbl_8006DBAC((u8 *)asset+0x88);
        lbl_8006E1B0(&n->children[0],(void *)((u8 *)&impulse));
        dx=*(f32 *)((u8 *)n+0x10)-impulse[0];
        dy=*(f32 *)((u8 *)n+0x14)-impulse[1];
        dz=*(f32 *)((u8 *)n+0x18)-impulse[2];
        d2=dx*dx+dy*dy+dz*dz;
        if(d2>*(f32 *)(lbl_1_rodata_7AB8+0x180)) {
            scale=lbl_8006D0B4(*(f32 *)(lbl_1_rodata_7AB8+0x180)/d2);
            *(f32 *)((u8 *)n+0x10)=impulse[0]+dx*scale;
            *(f32 *)((u8 *)n+0x14)=impulse[1]+dy*scale;
            *(f32 *)((u8 *)n+0x18)=impulse[2]+dz*scale;
            *(u32 *)((u8 *)n+0x1c)=*(u32 *)((u8 *)n+0x10);
            *(u32 *)((u8 *)n+0x20)=*(u32 *)((u8 *)n+0x14);
            *(u32 *)((u8 *)n+0x24)=*(u32 *)((u8 *)n+0x18);
        }
    }
    for(i=0,n=m->nodes;i<m->count;i++,n++) {
        fn_1_1286F4(&impulse);
        *(f32 *)((u8 *)n+0x34)=(f32)(*(f32 *)((u8 *)n+0x34)*0.2);
        *(f32 *)((u8 *)n+0x38)=(f32)(*(f32 *)((u8 *)n+0x38)*0.2);
        *(f32 *)((u8 *)n+0x3c)=(f32)(*(f32 *)((u8 *)n+0x3c)*0.2);
        *(f32 *)((u8 *)n+0x34)+=0.8f*(*(f32 *)((u8 *)n+0x10)-*(f32 *)((u8 *)n+0x1c));
        *(f32 *)((u8 *)n+0x38)+=0.8f*(*(f32 *)((u8 *)n+0x14)-*(f32 *)((u8 *)n+0x20));
        *(f32 *)((u8 *)n+0x3c)+=0.8f*(*(f32 *)((u8 *)n+0x18)-*(f32 *)((u8 *)n+0x24));
        *(f32 *)((u8 *)n+0x34)+=0.5f*impulse[0];
        *(f32 *)((u8 *)n+0x38)+=0.5f*impulse[1];
        *(f32 *)((u8 *)n+0x3c)+=0.5f*impulse[2];
    }
    asset=fn_80077B14(m->resource);
    asset=*(void **)((u8 *)*(u32 *)((u8 *)m->resource+0x150)+8);
    asset=(u8 *)asset+((u32 *)&lbl_1_data_3FFBC)[m->index]*0x18c+0x88;
    lbl_8006DBAC(asset);
    for(i=0,n=m->nodes;i<m->count;i++,n++) {
        u32 j;
        for(j=0;j<n->childCount;j++)
            fn_8006E250((u8 *)n+0x10, (u8 *)asset+(*(u16 *)((u8 *)n+4+j*2)<<6));
    }
}
