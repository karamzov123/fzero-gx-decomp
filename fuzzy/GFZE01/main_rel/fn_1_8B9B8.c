/* Non-matching: best partial attempt (6.19% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"
#include "psvec.h"

extern const f32 lbl_1_rodata_3508[];
extern const f64 lbl_1_rodata_3508_d[];
extern u32 lbl_801A6D00;
extern void lbl_8006DC6C(void *);
extern void lbl_8006DB74(void *);
extern void *lbl_8006DBAC(void *);
extern void lbl_8006DF44(void);
extern void lbl_8006DFC4(void *);
extern u32 fn_8006F394(void);
extern s32 lbl_8006D46C(void);
extern void lbl_8006D6FC(void *, void *);
extern Obj_1_data_20664 lbl_1_data_20664;

typedef struct { u8 pad[0x940]; } G820;
typedef struct { u8 pad[0x620]; } Car620;
typedef struct { u8 pad[0x20]; f32 x,y,z; } VecTmp;
static f32 rf32(s32 off) { return *(const f32 *)((const u8 *)lbl_1_rodata_3508 + off); }
static f64 rf64(s32 off) { return *(const f64 *)((const u8 *)lbl_1_rodata_3508 + off); }
static Car620 *car_at(void *base, int i) { return (Car620 *)((u8 *)base + i * 0x620 + 0x49c); }
static f32 *cf(Car620 *c, int off) { return (f32 *)((u8 *)c + off); }
static u32 *cw(Car620 *c, int off) { return (u32 *)((u8 *)c + off); }

void fn_1_8B9B8(void *out) {
    G820 *g = (G820 *)&lbl_1_bss_6D820;
    void *cars = *(void **)((u8 *)g + 0x18);
    s8 n = *(s8 *)((u8 *)g + 0x2a);
    s8 *ids = (s8 *)((u8 *)g + 0x23c);
    s32 state[43];
    s32 i,j,k;
    u8 counts[4];
    f32 values[30];
    s16 order[15];
    u8 *slot = (u8 *)((u8 *)g + 0x21c);
    if (lbl_1_bss_3BE0 == 0 || lbl_1_bss_3BE0->unk_8 == 0) return;
    *(u8 *)((u8 *)g + 0x2b)=0; *(u8 *)((u8 *)g + 0x2c)=0;
    for(i=0;i<n;i++) {
        u32 flags=*(u32 *)((u8 *)cars+(s8)ids[i]*0x620);
        if(flags & 4) state[i]=3;
        else if(flags & 0x8000) { state[i]=0; ++*(u8 *)((u8 *)g+0x2b); ++*(u8 *)((u8 *)g+0x2c); }
        else if ((out && (*(u32 *)out & 0x10000)) || (flags & 0x10)) { state[i]=1; ++*(u8 *)((u8 *)g+0x2b); }
        else state[i]=2;
    }
    if(out) { ((u8 *)out)[10]=*(u8 *)((u8 *)g+0x2b); ((u8 *)out)[11]=*(u8 *)((u8 *)g+0x2c); }
    for(i=0;i<4;i++) {
        counts[i]=0;
        for(j=0;j<n;j++) if(state[j]==i) {
            Car620 *c=car_at(cars,(s8)ids[j]);
            if(i==0) values[counts[i]]=*(f32 *)((u8 *)c+0x1dc)+(f32)(*(s32 *)((u8 *)c+0x1d8));
            else values[counts[i]]=*(f32 *)((u8 *)c+0xf8);
            order[counts[i]++]=(s8)ids[j];
        }
    }
    for(k=0;k<4;k++) for(i=0;i<(s8)counts[k];i++) {
        for(j=i+1;j<(s8)counts[k];j++) {
            f32 tv; s16 tord;
            if(k==0 ? values[j]<values[i] : values[j]>values[i]) {
                tv=values[i]; values[i]=values[j]; values[j]=tv;
                tord=order[i]; order[i]=order[j]; order[j]=tord;
            }
        }
    }
    if(out) {
        for(i=0;i<n;i++) { Car620 *c=car_at(cars,(s8)ids[i]); *(u8 *)((u8 *)c+0x115)=i; slot[(s8)ids[i]]=i; ((u32 *)out)[i+11]=(u32)c; }
    } else for(i=0;i<n;i++) { Car620 *c=car_at(cars,(s8)ids[i]); *(u8 *)((u8 *)c+0x115)=i; slot[(s8)ids[i]]=i; }
    *(u8 *)((u8 *)g+0x25a)=0xff; *(u8 *)((u8 *)g+0x25b)=0;
    for(i=0;i<4;i++) {
        s8 id=lbl_1_data_20664.unk_0;
        if(id!=-1) { u8 x=*(u8 *)((u8 *)car_at(cars,id)+0x115); if(x<*(u8 *)((u8 *)g+0x25a)){*(u8 *)((u8 *)g+0x25a)=x;*(u8 *)((u8 *)g+0x25c)=id;} if(x>*(u8 *)((u8 *)g+0x25b)){*(u8 *)((u8 *)g+0x25b)=x;*(u8 *)((u8 *)g+0x25d)=id;} }
    }
    if(*(u8 *)((u8 *)g+0x25a)==0xff){*(u8 *)((u8 *)g+0x25c)=0;*(u8 *)((u8 *)g+0x25d)=0;*(u8 *)((u8 *)g+0x25a)=1;*(u8 *)((u8 *)g+0x25b)=1;}
    for(i=0;i<n;i++) {
        Car620 *c=car_at(cars,i); void *mesh=(void *)((u8 *)c+0xec);
        lbl_8006DC6C(mesh);
        *(f32 *)0xe000000c=*(f32 *)((u8 *)c+0x7c); *(f32 *)0xe000001c=*(f32 *)((u8 *)c+0x80); *(f32 *)0xe000002c=*(f32 *)((u8 *)c+0x84);
        lbl_8006DB74((void *)(*(u32 *)&lbl_801A6D00+0x60)); lbl_8006DBAC((u8 *)c); lbl_8006DF44();
        *(s16 *)((u8 *)c+0x104)=fn_8006F394();
        *(f32 *)((u8 *)c+0x84)=*(f32 *)((u8 *)c+0x68);
    }
}
