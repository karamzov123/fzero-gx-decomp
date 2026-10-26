/* Non-matching: best partial attempt (97.31% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */






#include "types.h"
#include "psvec.h"
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"

#ifndef GAME_MAIN_REL_CAR_TEST_TYPES_H
#define GAME_MAIN_REL_CAR_TEST_TYPES_H
#ifndef REL_MAIN_REL_GLOBALS_H
#define REL_MAIN_REL_GLOBALS_H

// lbl_1_data_3FFBC: .data size 0x574, referenced by 31 functions, shape {}
extern u8 lbl_1_data_3FFBC[0x574];

#endif  // REL_MAIN_REL_GLOBALS_H
#ifndef REL_MAIN_REL_CAR_TEST_H
#define REL_MAIN_REL_CAR_TEST_H

#endif  // REL_MAIN_REL_CAR_TEST_H

/* end rel/main_rel/car_test.h */

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn183D28Vec3;

extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);

#endif  // GAME_MAIN_REL_CAR_TEST_TYPES_H

/* end game/main_rel/car_test_types.h */
/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,
// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,
// stcoli). Hand-owned (librarian).


typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;
#endif  // GAME_VEC3_H
#ifndef REL_MAIN_REL_ACCESSORY_H
#define REL_MAIN_REL_ACCESSORY_H

#endif  // REL_MAIN_REL_ACCESSORY_H

/* end rel/main_rel/accessory.h */

struct Sig_fn_80077B14_fn_80077B14_Arg0 {
 u8 pad_0[4]; u32 unk_4; u8 pad_8[0x18]; u32 unk_20;
};
typedef struct { f32 x,y,z; } Sig_fn_1_1286F4_Vec3f;
extern s32 fn_80077B14(struct Sig_fn_80077B14_fn_80077B14_Arg0 *);
extern void fn_1_1286F4(Sig_fn_1_1286F4_Vec3f *);
extern void lbl_8006DBAC(Vec3 *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern f32 lbl_8006D118(f32, f32 *);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D0E8(f32);
extern void fn_8006E250(Vec3f *, Vec3f *);
extern const u8 lbl_1_rodata_7AB8[];
typedef struct Node {
 u8 flags, pad1, count, pad3;
 u16 links[6];
 Fn183D28Vec3 pos,prev,local,vel;
 f32 weight;
} Node;
typedef struct { Node *a,*b; f32 length; } Link;
typedef struct { u8 pad[8]; u8 *base; } Model;
typedef struct { u8 pad[0x88]; s32 kind; u8 pad8c[0x148 - 0x8c]; u8 unk148[8]; Model *model; } Owner;
typedef struct { u8 flags; u8 pad[7]; u32 index; Owner *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0 *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work;
#define F(o) (*(const f32 *)(pool+(o)))
#define D(o) (*(const f64 *)(pool+(o)))
extern u8 lbl_1_data_3F510[];
extern u32 lbl_801A63C0;
extern const char *fn_1_950E8(void *);
extern int fn_80083BCC(const char *, const char *);
extern void fn_1_108128(void *, s32);
extern f32 lbl_8006D188(s32);
#pragma opt_propagation off
static inline u32 *fn_1_110478_indices(u8 *base) {
 u32 *indices = (u32 *)(base + 0xaac);
 return indices;
}
#define INDEX(i) (fn_1_110478_indices(data)[i])
static inline f32 fn_1_110478_read_pointer(Link * owner) { return owner->length; }
#define SPHERE(BASE, CX, CY, CZ, RADIUS, STRENGTH) { \
 Fn183D28Vec3 diff; \
 Fn183D28Vec3 center; \
 f32 scale; \
 f32 cx,cy,cz; \
 cz=CZ; cy=CY; cx=CX; \
 center.x=cx; center.y=cy; center.z=cz; \
 lbl_8006DBAC((Vec3 *)(arg0->owner->model->base+BASE)); \
 lbl_8006E1B0(&center,&center); \
 for(ki=0,kn=arg0->nodes;ki<arg0->count;ki++,kn++) { \
 if(!(kn->flags&1)) { \
 f32 x,z,y,r; \
 x=kn->pos.x; y=kn->pos.y; z=kn->pos.z; \
 x-=center.x; y-=center.y; z-=center.z; \
 r=(f32)(x*x)+y*y+z*z; \
 if(r<RADIUS) { \
 psvec_sub_scale_add(&kn->pos,&center,STRENGTH*lbl_8006D0E8(r),&diff,&kn->pos); \
 } \
 } \
 } \
}


extern u32 lbl_801A66A0;
extern f32 lbl_8006D668(void *);
static inline f32 fn_1_110478_measure(Node *a, Node *b, Fn183D28Vec3 *dp) {
 f32 x;
 f32 y;
 f32 z;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 (*dp).x=x; (*dp).y=y; (*dp).z=z;
 { f32 d; d=x*x; d+=y*y; d+=z*z; return d; }
}
#define delta (*dp)
static inline void fn_1_110478_constrain(const u8 *pool, Node *a, Node *b, Link *l, f32 *len, Fn183D28Vec3 *dp) {
 f32 wb;
 f32 inv;
 f32 s;
 f32 wa;
 f32 fb;
 f32 r;
 f32 fa;
 f32 cx;
 f32 cy;
 f32 cz;
 f32 x;
 inv=lbl_8006D118(*len,len);
 r=lbl_8006D0B4(l->length);
 s=inv*(*len-r);
 *len=s;
 cx=delta.x*s; cy=delta.y*s; cz=delta.z*s;
 wa=a->weight; wb=b->weight;
 x=a->pos.x;
 delta.x=cx; delta.y=cy; delta.z=cz;
 r=F(0xa0)/(wa+wb);
 fa=wa*r; fb=wb*r;
 a->pos.x=x-(f32)(cx*fa);
 a->pos.y-=(f32)(cy*fa);
 a->pos.z-=(f32)(cz*fa);
 b->pos.x+=(f32)(cx*fb);
 b->pos.y+=(f32)(cy*fb);
 b->pos.z+=(f32)(cz*fb);
}
#define LINKFIX { fn_1_110478_constrain(pool,a,b,l,&len,dp); }
#undef delta
#define RAND() ((s32)(((lbl_801A63C0=lbl_801A63C0*0x676A4B6B+13259)>>16)&0x7FFF))
#pragma opt_common_subs off
static inline void fn_1_110478_loop0(Work *arg0) {
 u32 i1;
 Node *n1;
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0(&n1->local,&n1->pos);
 }
}

void fn_1_110478(Work *arg0) {
 const u8 *pool=lbl_1_rodata_7AB8;
 u8 *data=lbl_1_data_3F510;
 u8 *fmodel;
 u32 i3;
 u32 k;
 Link *l;
 Node *kn;
 Node *fn;
 Node *n3;
 Node *a;
 u32 fj;
 u8 *model3;
 u32 ki;
 Node *vn;
 u32 fi;
 u32 li;
 u32 vi;
 u16 *lp;
 Node *n2;
 u32 i2;
 f32 c68;
 f32 c1a8;
 f32 c1d0;
 f32 c1dc;
 u32 i6;
 Node *n6;
 u8 *model6;
 Node *b;
 u32 wi;
 Node *wn;
 Fn183D28Vec3 deltav;
 Fn183D28Vec3 random;
 Fn183D28Vec3 push;
 Fn183D28Vec3 target;
 Fn183D28Vec3 *dp = &deltav;
#define delta (*dp)
 f32 len;
 if(arg0 && arg0->obj) {
 fn_80077B14(arg0->obj);
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 lbl_8006DBAC((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136));
 lbl_8006DAEC();
 fn_1_110478_loop0(arg0);
 lbl_8006DC20();
 }
 for(i2=0,n2=arg0->nodes;i2<arg0->count;i2++,n2++) {
 if(!(n2->flags&1)) {
 n2->prev=n2->pos;
 n2->pos.x+=n2->vel.x;
 n2->pos.y+=n2->vel.y;
 n2->pos.z+=n2->vel.z;
 n2->pos.y-=D(0x58);
 n2->vel.y-=F(0x60);
 }
 }
 model3=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((Vec3 *)(model3+136));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0(&n3->local,&n3->pos);
 }
 lbl_8006DC20();
 }
 for(k=0;k<4;k++) {
 c68=F(0x68); c1a8=F(0x1a8); c1d0=F(0x1d0); c1dc=F(0x1dc);
 for(li=0,l=arg0->links;li<arg0->linkCount;li++,l++) {
 a=l->a; b=l->b;
 if(a && b) {
 f32 y;
 f32 wa;
 f32 x;
 f32 inv;
 f32 s;
 f32 cz;
 f32 cy;
 f32 r;
 f32 cx;
 f32 fa;
 f32 wb;
 f32 z;
 f32 fb;
 x=a->pos.x-b->pos.x;
 y=a->pos.y-b->pos.y;
 z=a->pos.z-b->pos.z;
 delta.x=x; delta.y=y; delta.z=z;
 len=(f32)(x*x)+y*y+z*z;
 if(len-F(0x9c)>fn_1_110478_read_pointer(l)) LINKFIX
 if((y=a->pos.y)<F(0x68) || b->pos.y<F(0x68)) {
 if(y<F(0x68)) a->pos.y=F(0x248);
 if(b->pos.y<F(0x68)) b->pos.y=F(0x248);
 len=fn_1_110478_measure(a,b,dp);
 LINKFIX
 }
 }
 }
 SPHERE(532,c1a8,c68,c68,F(0x1ac),F(0x1b0))
 SPHERE(0x1948,c68,c68,c68,F(0x1b4),F(0x1b8))
 SPHERE(0x1c60,c1d0,c68,c68,F(0x1d4),F(0x1d8))
 SPHERE(0x1c60,c1dc,c68,c68,F(0x1e0),F(0x1e4))
 SPHERE(0x241c,c1d0,c68,c68,F(0x1d4),F(0x1d8))
 SPHERE(0x241c,c1dc,c68,c68,F(0x1e0),F(0x1e4))
 }
 if(fn_80083BCC(fn_1_950E8(&arg0->owner->unk148),(const char *)(data+0x1040))!=0 && fn_80083BCC(fn_1_950E8(&arg0->owner->unk148),(const char *)(data+0x1048))!=0) {
 for(wi=0,wn=arg0->nodes;wi<arg0->count;wi++,wn++) {
 f32 w1,w2;
 u32 m;
 wn->vel.x*=D(0x190); wn->vel.y*=D(0x190); wn->vel.z*=D(0x190);
 m=wi%9;
 w1=F(0x1c8)+(F(0x200)*(f32)(9-m))/F(0x204);
 w2=F(0x1c8)+(F(0x200)*(f32)m)/F(0x204);
 wn->vel.x+=(f64)(D(0x188)*(wn->pos.x-wn->prev.x));
 wn->vel.y+=(f64)(D(0x188)*(wn->pos.y-wn->prev.y));
 wn->vel.z+=(f64)(D(0x188)*(wn->pos.z-wn->prev.z));
 wn->vel.x-=(f32)(w1*(F(0x208)*((f32)RAND()/F(0x20c))));
 wn->vel.y+=(f32)(w1*(F(0x24c)*((f32)RAND()/F(0x20c))));
 wn->vel.z+=(f32)(w1*(F(0x214)*lbl_8006D188((s32)(F(0x218)+(F(0x21c)*(f32)((lbl_801A66A0+wi)%39))/F(0x220)))));
 wn->vel.z+=(f32)(w2*(F(0x208)*((f32)RAND()/F(0x20c))));
 wn->vel.y+=(f32)(w2*(F(0x250)*((f32)RAND()/F(0x20c))));
 wn->vel.x+=(f32)(w2*(F(0x214)*lbl_8006D188((s32)(F(0x218)+(F(0x21c)*(f32)((lbl_801A66A0+wi)%29))/F(0x228)))));
 }
 } else {
 if(lbl_801A66A0%60<20) {
 model6=arg0->owner->model->base+INDEX(arg0->index)*396;
 for(i6=0,n6=arg0->nodes;i6<arg0->count;i6++,n6++) {
 lbl_8006DBAC((Vec3 *)(model6+136));
 lbl_8006E1B0(&n6->local,&target);
 push.x=n6->pos.x-target.x;
 push.y=n6->pos.y-target.y;
 push.z=n6->pos.z-target.z;
 lbl_8006D668(&push);
 n6->vel.x-=(f32)(F(0x1a4)*push.x);
 n6->vel.y-=(f32)(F(0x1a4)*push.y);
 n6->vel.z-=(f32)(F(0x1a4)*push.z);
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 fn_1_1286F4((Sig_fn_1_1286F4_Vec3f *)&random);
 vn->vel.x*=D(0x190); vn->vel.y*=D(0x190); vn->vel.z*=D(0x190);
 vn->vel.x+=(f64)(D(0x188)*(vn->pos.x-vn->prev.x));
 vn->vel.y+=(f64)(D(0x188)*(vn->pos.y-vn->prev.y));
 vn->vel.z+=(f64)(D(0x188)*(vn->pos.z-vn->prev.z));
 vn->vel.x+=(f64)(D(0x198)*random.x); vn->vel.y+=(f64)(D(0x198)*random.y); vn->vel.z+=(f64)(D(0x198)*random.z);
 }
 }
 fn_1_108128(arg0,9);
 fmodel=(u8 *)fn_80077B14(arg0->obj);
 lbl_8006DBAC((Vec3 *)(arg0->owner->model->base+INDEX(arg0->index)*396+136));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((Vec3f *)&fn->pos,(Vec3f *)(fmodel+(lp[2]<<6)));
 }
 }
 }
}
#pragma opt_common_subs reset
