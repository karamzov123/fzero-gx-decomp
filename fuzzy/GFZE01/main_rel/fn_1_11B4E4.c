/* Non-matching: best partial attempt (98.60% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
/* fzgx:begin fn_1_11B4E4 noprologue */
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"
#include "psvec.h"
#include "types.h"

#ifndef GAME_MAIN_REL_ACCESSORY_TYPES_H
#define GAME_MAIN_REL_ACCESSORY_TYPES_H
#ifndef REL_MAIN_REL_GLOBALS_H
#define REL_MAIN_REL_GLOBALS_H

// lbl_1_data_40530: .data size 0x6C, referenced by 26 functions, shape {}
extern char lbl_1_data_40530[0x6C];

#endif  // REL_MAIN_REL_GLOBALS_H
#ifndef REL_MAIN_REL_ACCESSORY_H
#define REL_MAIN_REL_ACCESSORY_H

#endif  // REL_MAIN_REL_ACCESSORY_H
#ifndef REL_MAIN_REL_CLOTH_H
#define REL_MAIN_REL_CLOTH_H

#endif  // REL_MAIN_REL_CLOTH_H

#ifndef GAME_MAIN_REL_SHARED_TYPES_H
#define GAME_MAIN_REL_SHARED_TYPES_H

#endif  // GAME_MAIN_REL_SHARED_TYPES_H

typedef struct Point1024C4 {
    u8 pad[0x10];
    f32 v[3];
} Point1024C4;

extern f32 fn_1_1289BC(const Point1024C4 *a, const Point1024C4 *b);

#endif  // GAME_MAIN_REL_ACCESSORY_TYPES_H

/* end game/main_rel/accessory_types.h */
/* rel/main_rel/accessory.h: inlined above */

typedef struct { f32 x,y,z; } Sig_fn_1_10846C_Vec10846C;
typedef struct { u32 w[3]; } Sig_fn_1_10846C_Word3_10846C;
typedef struct {
 u8 flags, unk_1, count, pad_3;
 u16 idx[4]; u8 pad_C[4];
 Sig_fn_1_10846C_Vec10846C p10,p1C,p28;
 Sig_fn_1_10846C_Word3_10846C c34;
 f32 weight;
} Sig_fn_1_10846C_Group10846C;
typedef struct {
 u8 pad_0[12]; void *config; void *model;
 u8 pad_14[4]; u32 groupCount,unk_1C;
 u8 pad_20[4]; Sig_fn_1_10846C_Group10846C *groups;
 void *unk_28; u8 pad_2C[4]; void *srcModel; u8 pad_34[0x30];
 Sig_fn_1_10846C_Vec10846C *positions;
} Sig_fn_1_10846C_Obj10846C;
extern void fn_1_10846C(Sig_fn_1_10846C_Obj10846C *);
extern void fn_1_128884(void *,void *,s32);
extern f32 fn_1_1289BC(const Point1024C4 *,const Point1024C4 *);
extern const f32 lbl_1_rodata_7B1C;


extern u32 lbl_801A6410;
extern u32 fn_1_4630(u32,u32,const char *,u32);
typedef Sig_fn_1_10846C_Group10846C Group;
typedef struct { Group *a,*b; f32 distance; } Edge;
static inline void fn_1_11B4E4_sort_x(Sig_fn_1_10846C_Obj10846C *obj) {
 u32 i;
 Group *b;
 u32 j;
 Group *a;
 u32 off;
 for (i=0,a=obj->groups,off=i;i<obj->groupCount;off+=0x44,i++,a++) {
  for (j=i+1,b=(Group *)((u8 *)obj->groups+off+0x44);j<obj->groupCount;j++,b++)
   if (a->p10.x>b->p10.x) fn_1_128884(a,b,0x44);
 }
}
static inline void fn_1_11B4E4_sort_y(Group *row) {
 Group *a;
 u32 i;
 Group *b;
 u32 j;
 for (i=0,a=row;i<8;i++,a++) {
  for (j=i+1,b=a+1;j<8;j++,b++)
   if (a->p10.y<b->p10.y) fn_1_128884(a,b,0x44);
 }
}
#pragma opt_propagation off
#pragma opt_loop_invariants off
void fn_1_11B4E4(Sig_fn_1_10846C_Obj10846C *obj) {
 u32 i;
 u32 c;
 Group *p;
 Group *row;
 Group tmp[8];
 u32 k;
 if (obj) {
  fn_1_10846C(obj);
  for (i=0,p=obj->groups;i<obj->groupCount;i++,p++) {
   if (p->flags&1) { p->weight=lbl_1_rodata_7B1C; p->flags=0; }
   else { p->weight=0.0f; p->flags=1; }
  }
  {
  u32 xj;
  Group *xb;
  u32 xi;
  Group *xa;
  for (xi=0,xa=obj->groups;xi<obj->groupCount;xi++,xa++) {
   for (xj=xi+1,xb=&obj->groups[xi]+1;xj<obj->groupCount;xj++,xb++)
    if (xa->p10.x>xb->p10.x) fn_1_128884(xa,xb,0x44);
  }
  }
  for (k=0,row=obj->groups;k<obj->groupCount/8;k++,row+=8) {
   Group *lo;
   Group *hi;
   u32 pi;
   Group *e;
   Group *src;
   u32 ci;
   Group *dst;
   f32 w;
   {
   Group *ya;
   u32 yi;
   u32 yj;
   Group *yb;
   for (yi=0,ya=row;yi<8;yi++,ya++) {
    for (yj=yi+1,yb=ya+1;yj<8;yj++,yb++)
     if (ya->p10.y<yb->p10.y) fn_1_128884(ya,yb,0x44);
   }
   }
   tmp[0]=row[0];
   for (e=row+1,pi=1,lo=&tmp[1],hi=&tmp[7];pi<8;pi++,e++) {
    if (e->p10.z>0.0f) { *lo=*e; lo++; }
    else { *hi=*e; hi--; }
   }
   w=-(f32)k;
   for (ci=0,dst=row,src=tmp;ci<8;ci++,src++,dst++) {
    *dst=*src;
    if (k==obj->groupCount/8-1) dst->weight=0.0f;
    else dst->weight=w/(f32)(obj->groupCount/8-1);
   }
  }
  obj->unk_1C=0x60;
  obj->unk_28=(void *)fn_1_4630(lbl_801A6410,obj->unk_1C*12,lbl_1_data_40530,0x1e57);
  c=0;
  for (k=0,row=obj->groups;k<obj->groupCount/8-1;k++,row+=8) {
   for (i=0,p=row;i<7;i++,p++) {
    ((Edge *)obj->unk_28)[c].a=p;
    ((Edge *)obj->unk_28)[c].b=p+1;
    ((Edge *)obj->unk_28)[c].distance=fn_1_1289BC((Point1024C4 *)p,(Point1024C4 *)(p+1));
    c++;
   }
   ((Edge *)obj->unk_28)[c].a=row+7;
   ((Edge *)obj->unk_28)[c].b=row;
   ((Edge *)obj->unk_28)[c].distance=fn_1_1289BC((Point1024C4 *)(row+7),(Point1024C4 *)row);
   c++;
  }
  {
  u32 i2;
  Group *p2;
  u32 k2;
  Group *row2;
  for (k2=0,row2=obj->groups;k2<obj->groupCount/8-1;k2++,row2+=8) {
   for (i2=0,p2=row2;i2<8;i2++,p2++) {
    ((Edge *)obj->unk_28)[c].a=p2;
    ((Edge *)obj->unk_28)[c].b=p2+8;
    ((Edge *)obj->unk_28)[c].distance=fn_1_1289BC((Point1024C4 *)p2,(Point1024C4 *)(p2+8));
    c++;
   }
  }
  }
 }
}
#pragma opt_loop_invariants reset
#pragma opt_propagation reset
/* fzgx:end fn_1_11B4E4 */
