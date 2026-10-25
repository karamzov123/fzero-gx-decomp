/* Non-matching: best partial attempt (98.28% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
typedef struct Vec { f32 x,y,z; } Vec;
struct fn_1_2ABD4_Arg0 {
 u8 pad_0[4]; s16 id; u8 pad_6[2]; f32 rate;
 u8 pad_C[0x1BC]; f32 speed;
 u8 pad_1CC[0x2B5]; u8 unk_481; u8 pad_482[0x16]; u32 unk_498;
};
struct Obj {
 u32 flags; u32 unk4; Vec pos; u8 pad14[0xC]; Vec hit; Vec normal; Vec surface;
 f32 height,scale; Vec force; f32 magnitude;
};
struct Track { u8 pad[0x98]; u32 count; u8 data[4]; };
extern struct Track *fn_1_8627C(s32);
extern void lbl_8006E1B0(void *,void *);
extern void lbl_8006E1D8(void *,f32,f32,f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern f32 lbl_8006D0B4(f32);
extern s32 fn_1_15578(void *,void *,void *,void *,u32,void *,u32,u32,u32,void *);

void fn_1_2ABD4(struct fn_1_2ABD4_Arg0 *a, void *arg1) {
 struct Obj *b = arg1;
 f32 force;
 f32 max;
 f32 depth;
 f32 distance;
 s32 found;
 struct Track *track;
 Vec start;
 Vec end;
 f32 fraction;
 max = 0.1f + (f32)(u32)a->unk_481 / 90.0f;
 if(max > 0.5f) max = 0.5f;
 max *= 2.0f * b->scale;
 lbl_8006E1B0(&b->pos,&start);
 lbl_8006E1D8(&b->hit,b->pos.x,b->pos.y-2000.0f,b->pos.z);
 if ((b->flags & 0x20) || (a->speed <= 0.0f && (b->flags & 2))) {
  b->flags |= 8;
  depth=0.0f;
 } else {
  track=fn_1_8627C(a->id);
  lbl_8006DAEC();
  end=b->hit;
  if(fn_1_15578(&end,&start,&fraction,&b->surface,0x60005,track->data,track->count,0,a->unk_498,a)) {
   f32 x=b->hit.x-start.x;
   f32 y=b->hit.y-start.y;
   f32 z=b->hit.z-start.z;
   distance=lbl_8006D0B4((f32)(x*x)+y*y+z*z);
   distance=(1.0f-fraction)*distance;
   b->hit=end;
   found=1;
  } else {
   distance=0.0f;
   found=0;
  }
  lbl_8006DB30();
  if(found) {
   b->flags &= ~8;
   depth=(distance-2000.0f)+max;
  } else {
   b->flags |= 8;
   depth=0.0f;
  }
 }
 if(depth<=0.0f) {
  b->flags |= 2;
  force=0.0f;
  b->height=0.0f;
  b->normal.x=0.0f; b->normal.y=1.0f; b->normal.z=0.0f;
  if(b->flags&8) {
   b->surface.x=0.0f; b->surface.y=1.0f; b->surface.z=0.0f;
  }
 } else {
  f32 step,old;
  b->flags &= ~2;
  if(depth>max) {
   force=(0.5f*(depth-b->height))*a->rate;
   depth=max;
  } else force=0.0f;
  step=a->rate/1200.0f;
  old=b->height;
  b->height=depth;
  b->normal=b->surface;
  force += (f32)((f32)(0.00900000054f*(f32)(9000.0f*depth))*step);
  force -= (f32)(step*(f32)(10000.0f*(f32)(0.00900000054f*(old-depth))));
 }
 b->magnitude=force;
 psvec_scale(&b->normal,force,&b->force);
}
