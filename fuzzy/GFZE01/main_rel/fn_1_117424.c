/* Non-matching: best partial attempt (99.86% in the project ledger). Scored for the
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
typedef struct { u8 pad[0x150]; Model *model; } Owner;
typedef struct { u8 flags; u8 pad[7]; u32 index; Owner *owner;
 struct Sig_fn_80077B14_fn_80077B14_Arg0 *obj;
 u32 pad14,count,linkCount,pad20; Node *nodes; Link *links; } Work;
#define F(o) (*(const f32 *)(pool+(o)))
#define D(o) (*(const f64 *)(pool+(o)))
extern u8 lbl_1_data_3F510[];
extern u8 *fn_80083970(u8 *, const char *);
#define ACC (data)
#pragma opt_propagation off
static inline u32 *fn_1_117424_indices(u8 *base) {
 u32 *indices = (u32 *)(base + 0xaac);
 return indices;
}
static inline u8 **fn_1_117424_names(u8 *base) {
 u8 **names = (u8 **)(base + 0x79c);
 return names;
}
#define INDEX(i) (fn_1_117424_indices(ACC)[i])
#define MODELB (arg0->owner->model->base+INDEX(arg0->index)*396)
static inline f32 fn_1_117424_read_pointer(Link * owner) { return owner->length; }
extern u8 lbl_1_bss_88B50[0xC00];
#pragma opt_common_subs off
void fn_1_117424(Work *arg0) {
 const u8 *pool=lbl_1_rodata_7AB8;
 u8 *data=lbl_1_data_3F510;
 u8 *fmodel;
 Node *n1;
 u8 *model3;
 u32 fi;
 u32 i1;
 Node *n3;
 u32 fj;
 u32 i3;
 Node *fn;
 u16 *lp;
 u8 *model5;
 u32 i5;
 Node *n5;
 u32 vi;
 Node *vn;
 Node *n2;
 u32 i2;
 u32 i6;
 Node *n6;
 u8 *model6;
 Owner *owner;
 Fn183D28Vec3 diff;
 Fn183D28Vec3 target;
 Fn183D28Vec3 *qp = &diff;
#define dif (*qp)
 if(arg0 && arg0->obj) {
 fn_80077B14(arg0->obj);
 fn_80083970(fn_1_117424_names(ACC)[arg0->index],(const char *)(ACC+0x4bc));
 if(arg0->flags & 2) {
 arg0->flags &= ~2;
 owner=arg0->owner;
 lbl_8006DBAC((Vec3 *)(owner->model->base+INDEX(arg0->index)*396+136));
 lbl_8006DAEC();
 for(i1=0,n1=arg0->nodes;i1<arg0->count;i1++,n1++) {
 lbl_8006DBE4();
 lbl_8006E1B0(&n1->local,&n1->pos);
 }
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
 owner=arg0->owner;
 model3=owner->model->base+INDEX(arg0->index)*396;
 for(i3=0,n3=arg0->nodes;i3<arg0->count;i3++,n3++) {
 lbl_8006DBAC((Vec3 *)(model3+136));
 lbl_8006DAEC();
 if(n3->flags&1) {
 lbl_8006DBE4();
 lbl_8006E1B0(&n3->local,&n3->pos);
 }
 lbl_8006DC20();
 }
 owner=arg0->owner;
 model6=owner->model->base+INDEX(arg0->index)*396;
 for(i6=0,n6=arg0->nodes;i6<arg0->count;i6++,n6++) {
 if(!(n6->flags&1)) {
 f32 kk,x,y,z;
 lbl_8006DBAC((Vec3 *)(model6+136));
 lbl_8006E1B0(&n6->local,&target);
 kk=F(0x3d0)/n6->weight;
 y=D(0x340)*(target.y-n6->pos.y);
 z=kk*(target.z-n6->pos.z);
 x=kk*(target.x-n6->pos.x);
 n6->pos.x+=x;
 n6->pos.y+=y;
 n6->pos.z+=z;
 }
 }
 for(vi=0,vn=arg0->nodes;vi<arg0->count;vi++,vn++) {
 vn->vel.x=F(0x200)*(vn->pos.x-vn->prev.x);
 vn->vel.y=F(0x200)*(vn->pos.y-vn->prev.y);
 vn->vel.z=F(0x200)*(vn->pos.z-vn->prev.z);
 }
 fmodel=(u8 *)fn_80077B14(arg0->obj);
 owner=arg0->owner;
 lbl_8006DBAC((Vec3 *)(owner->model->base+INDEX(arg0->index)*396+136));
 for(fi=0,fn=arg0->nodes;fi<arg0->count;fi++,fn++) {
 for(fj=0,lp=(u16 *)fn;(s32)fj<fn->count;lp++,fj++) {
 fn_8006E250((Vec3f *)&fn->pos,(Vec3f *)(fmodel+(lp[2]<<6)));
 }
 }
 }
}
#pragma opt_common_subs reset
