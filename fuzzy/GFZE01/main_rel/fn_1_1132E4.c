/* Non-matching: best partial attempt (70.32% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"
extern f32 lbl_1_rodata_7AB8[];

extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D118(f32);
extern s32 fn_80077B14(struct Sig_fn_80077B14_fn_80077B14_Arg0 *);
extern void fn_8006E250(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern void lbl_8006E1B0(void *, void *);

typedef struct { u8 b[0x44]; } Particle;
typedef struct { u8 b[0x0c]; } Pair;

void fn_1_1132E4(void *arg0) {
    struct Sig_fn_80077B14_fn_80077B14_Arg0 *resource;
    Particle *particles;
    Pair *pairs;
    u8 *pool;
    u32 i, j;
    u32 index;
    u8 *object;
    u8 *manager;
    f32 delta[3];
    f32 distance;
    f32 factor;
    f32 ratio;
    f32 inverse;
    f32 x, y, z;
    pool = (u8 *)lbl_1_rodata_7AB8;
    if (arg0 == 0) return;
    resource = *(struct Sig_fn_80077B14_fn_80077B14_Arg0 **)((u8 *)arg0 + 0x10);
    if (resource == 0) return;
    fn_80077B14(resource);
    pool = (u8 *)lbl_1_rodata_7AB8;
    if ((*(u8 *)arg0 & 2) != 0) {
        *(u8 *)arg0 = *(u8 *)arg0 & 0xFFFFFFFD;
        index = *(u32 *)((u8 *)&lbl_1_data_3FFBC + (*(u32 *)((u8 *)arg0 + 8) << 2));
        object = *(u8 **)(*(u8 **)((u8 *)arg0 + 0xc) + 0x150);
        lbl_8006DBAC((u8 *)(*(u32 *)(object + 8) + index * 0x18c + 0x88));
        lbl_8006DAEC();
        particles = *(Particle **)((u8 *)arg0 + 0x24);
        for (i=0; i<*(u32 *)((u8 *)arg0+0x18); i++,particles++) {
            lbl_8006DBE4();
            lbl_8006E1B0(particles->b+0x28,particles->b+0x10);
        }
        lbl_8006DC20();
    }
    particles = *(Particle **)((u8 *)arg0 + 0x24);
    for (i=0; i<*(u32 *)((u8 *)arg0+0x18); i++,particles++) {
        if ((particles->b[0]&1)==0) {
            *(u32 *)(particles->b+0x1c)=*(u32 *)(particles->b+0x10);
            *(u32 *)(particles->b+0x20)=*(u32 *)(particles->b+0x14);
            *(u32 *)(particles->b+0x24)=*(u32 *)(particles->b+0x18);
            *(f32 *)(particles->b+0x14)=(f32)(*(f32 *)(particles->b+0x14) +
                (*(f32 *)(particles->b+0x38)-*(f64 *)(pool+0x58)));
            *(f32 *)(particles->b+0x38)-=*(f32 *)(pool+0x60);
        }
    }
    index=*(u32 *)((u8 *)&lbl_1_data_3FFBC + (*(u32 *)((u8 *)arg0+8) << 2));
    object=*(u8 **)(*(u8 **)((u8 *)*(u8 **)((u8 *)arg0+0xc)+0x150)+8)+index*0x18c;
    particles=*(Particle **)((u8 *)arg0+0x24);
    for(i=0;i<*(u32 *)((u8 *)arg0+0x18);i++,particles++) {
        lbl_8006DBAC(object+0x88);
        lbl_8006DAEC();
        if(particles->b[0]&1) {
            lbl_8006DBE4();
            lbl_8006E1B0(particles->b+0x28,particles->b+0x10);
        }
        lbl_8006DC20();
    }
    pairs=*(Pair **)((u8 *)arg0+0x28);
    for(i=0;i<*(u32 *)((u8 *)arg0+0x1c);i++,pairs++) {
        u8 *a=*(u8 **)pairs->b, *b=*(u8 **)(pairs->b+4);
        if(a && b) {
            delta[0]=*(f32 *)(a+0x10)-*(f32 *)(b+0x10);
            delta[1]=*(f32 *)(a+0x14)-*(f32 *)(b+0x14);
            delta[2]=*(f32 *)(a+0x18)-*(f32 *)(b+0x18);
            distance=delta[0]*delta[0]+delta[1]*delta[1]+delta[2]*delta[2];
            if(distance-*(f32 *)(pool+0x9c)>*(f32 *)(pairs->b+8)) {
                factor=lbl_8006D118(distance);
                factor*=distance-lbl_8006D0B4(*(f32 *)(pairs->b+8));
                *(f32 *)(a+0x40); *(f32 *)(b+0x40);
                ratio=*(f32 *)(pool+0xa0)/(*(f32 *)(a+0x40)+*(f32 *)(b+0x40));
                x=*(f32 *)(a+0x10); y=*(f32 *)(a+0x14); z=*(f32 *)(a+0x18);
                *(f32 *)(a+0x10)=x-delta[0]*factor*(*(f32 *)(a+0x40)*ratio);
                *(f32 *)(a+0x14)=y-delta[1]*factor*(*(f32 *)(a+0x40)*ratio);
                *(f32 *)(a+0x18)=z-delta[2]*factor*(*(f32 *)(a+0x40)*ratio);
                *(f32 *)(b+0x10)=*(f32 *)(b+0x10)+delta[0]*factor*(*(f32 *)(b+0x40)*ratio);
                *(f32 *)(b+0x14)=*(f32 *)(b+0x14)+delta[1]*factor*(*(f32 *)(b+0x40)*ratio);
                *(f32 *)(b+0x18)=*(f32 *)(b+0x18)+delta[2]*factor*(*(f32 *)(b+0x40)*ratio);
            }
        }
    }
    index=*(u32 *)((u8 *)&lbl_1_data_3FFBC + (*(u32 *)((u8 *)arg0+8) << 2));
    object=*(u8 **)(*(u8 **)((u8 *)*(u8 **)((u8 *)arg0+0xc)+0x150)+8)+index*0x18c;
    particles=*(Particle **)((u8 *)arg0+0x24);
    factor=*(f32 *)(pool+0xa4);
    for(i=0;i<*(u32 *)((u8 *)arg0+0x18);i++,particles++) {
        lbl_8006DBAC(object+0x88);
        lbl_8006E1B0(particles->b+0x28,(u8 *)&distance+4);
        delta[0]=*(f32 *)(particles->b+0x10)-*(f32 *)((u8 *)&distance+4);
        delta[1]=*(f32 *)(particles->b+0x14)-*(f32 *)((u8 *)&distance+8);
        delta[2]=*(f32 *)(particles->b+0x18)-*(f32 *)((u8 *)&distance+12);
        distance=delta[0]*delta[0]+delta[1]*delta[1]+delta[2]*delta[2];
        if(distance>factor) {
            inverse=lbl_8006D0B4(factor/distance);
            *(f32 *)(particles->b+0x10)=*(f32 *)((u8 *)&distance+4)+delta[0]*inverse;
            *(f32 *)(particles->b+0x14)=*(f32 *)((u8 *)&distance+8)+delta[1]*inverse;
            *(f32 *)(particles->b+0x18)=*(f32 *)((u8 *)&distance+12)+delta[2]*inverse;
            *(u32 *)(particles->b+0x1c)=*(u32 *)(particles->b+0x10);
            *(u32 *)(particles->b+0x20)=*(u32 *)(particles->b+0x14);
            *(u32 *)(particles->b+0x24)=*(u32 *)(particles->b+0x18);
        }
    }
    particles=*(Particle **)((u8 *)arg0+0x24);
    for(i=0;i<*(u32 *)((u8 *)arg0+0x18);i++,particles++) {
        *(f32 *)(particles->b+0x34)=*(f32 *)(particles->b+0x10)-*(f32 *)(particles->b+0x1c);
        *(f32 *)(particles->b+0x38)=*(f32 *)(particles->b+0x14)-*(f32 *)(particles->b+0x20);
        *(f32 *)(particles->b+0x3c)=*(f32 *)(particles->b+0x18)-*(f32 *)(particles->b+0x24);
    }
    fn_80077B14(resource);
    index=*(u32 *)((u8 *)&lbl_1_data_3FFBC + (*(u32 *)((u8 *)arg0+8) << 2));
    object=*(u8 **)(*(u8 **)((u8 *)*(u8 **)((u8 *)arg0+0xc)+0x150)+8)+index*0x18c;
    lbl_8006DBAC(object+0x88);
    particles=*(Particle **)((u8 *)arg0+0x24);
    for(i=0;i<*(u32 *)((u8 *)arg0+0x18);i++,particles++) {
        for(j=0;j<particles->b[2];j++)
            fn_8006E250(particles->b+0x10);
    }
}
