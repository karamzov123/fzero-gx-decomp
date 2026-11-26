#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_common.h"

extern u8 lbl_1_bss_86EC4;
extern void lbl_8006DBAC(void *arg);

/* one line entry; fn_1_20258 measures it */
typedef struct LineEntry {
    u8 pad_0[0x30];
    f32 unk_30;
    f32 unk_34;
    u8 pad_38[0x4];
    f32 scl_x;
    f32 scl_y;
    u8 pad_44[0x24];
    f32 unk_68;
    f32 hcylin;
    u8 pad_70[0xC];
    u32 flags;
    u8 pad_80[0x80];
    f32 unk_100;
    u8 pad_104[0x4];
    f32 rel_xpos;
} LineEntry;

extern f32 fn_1_20258(LineEntry *, f32 *);

/* fzgx:begin fn_1_106EB0 */
#include "fpscr.h"


typedef struct fn_1_106EB0_Obj {
    u32 flags;
    u8 pad_4[0x498];
    LineEntry *line;
} fn_1_106EB0_Obj;

extern f32 lbl_1_bss_7AC9C;
extern void OSPanic(const char *, int, const char *, ...);
extern u8 *fn_1_C6F70(void);
extern void fn_1_A8EB0(s32, s32);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_A8E78(const char *);

s16 fzgx_obj_lbl_1_data_3F428 = -1;

u8 *fzgx_obj_lbl_1_bss_86EC0;
u8 fzgx_obj_lbl_1_bss_86EC4;
u8 fzgx_pad_86EC5;
u8 fzgx_pad_86EC6;
u8 fzgx_obj_lbl_1_bss_86EC7;
f32 fzgx_pad_86EC8;
s16 fzgx_obj_lbl_1_bss_86ECC;
u8 fzgx_pad_86ECE;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_86EC0;
    s = fzgx_obj_lbl_1_bss_86EC4;
    s = fzgx_pad_86EC5;
    s = fzgx_pad_86EC6;
    s = fzgx_obj_lbl_1_bss_86EC7;
    s = *(u8 *)&fzgx_pad_86EC8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_86ECC;
    s = fzgx_pad_86ECE;
}
#pragma section code_type ".text"

static inline void fn_1_106EB0_init(fn_1_106EB0_Obj *obj) {
    LineEntry *first;

    first = obj->line;
    if (fzgx_obj_lbl_1_bss_86EC0 != NULL) {
        OSPanic("get_line.c", 0x3b, "get_line.c: il is already used.");
    }
    fzgx_obj_lbl_1_bss_86EC0 = fn_1_C6F70();
    fzgx_pad_86EC5 = 0;
    fzgx_pad_86EC6 = 0;
    fzgx_obj_lbl_1_bss_86EC7 = 0;
    fzgx_pad_86EC8 = fpscr_floor(first->unk_100 * lbl_1_bss_7AC9C);
    fzgx_obj_lbl_1_bss_86ECC = 0;
    fzgx_obj_lbl_1_data_3F428 = -1;
    fzgx_obj_lbl_1_bss_86EC4 = 1;
}

void fn_1_106EB0(fn_1_106EB0_Obj *obj) {
    f32 pos;
    f32 scale;
    s8 val;
    LineEntry *line;
    f32 width;


    if (!fzgx_obj_lbl_1_bss_86EC4) {
        fn_1_106EB0_init(obj);
    }
    if (obj->flags & 0x04000000) {
        return;
    }
    line = obj->line;
    width = fn_1_20258(line, &scale);
    val = (f32)fpscr_floor(256.0 * (line->rel_xpos / width));
    fn_1_A8EB0(1, 0x1e);
    fn_1_A8DD4("rel_xpos: %6.2f\n", line->rel_xpos);
    fn_1_A8DD4("   scale: %6.2f\n", scale);
    fn_1_A8DD4("   width: %6.2f\n", width);
    fn_1_A8DD4("    OUT?: %s\n", (line->flags & 1) ? "TRUE " : "FALSE");
    if ((line->flags & 0x02200000) || 0.0f == scale) {
        fn_1_A8E78("\n\n");
    } else if (line->flags & 0x01800000) {
        fn_1_A8DD4("  hcylin: %6.2f\n\n", line->hcylin);
    } else if (line->flags & 0x00400000) {
        fn_1_A8DD4("   scl_x: %6.2f\n", line->scl_x);
        fn_1_A8DD4("   scl_y: %6.2f\n", line->scl_y);
    } else {
        OSPanic("get_line.c", 0x6f, "???\n");
    }
    fn_1_A8DD4("     val: %4d\n", val);
    pos = fpscr_floor(line->unk_100 * lbl_1_bss_7AC9C);
    if (pos != fzgx_pad_86EC8) {
        fzgx_pad_86EC8 = pos;
        fzgx_obj_lbl_1_bss_86ECC = pos;
        fzgx_obj_lbl_1_bss_86EC0[(u16)fzgx_obj_lbl_1_bss_86ECC + (fzgx_obj_lbl_1_bss_86EC7 << 9)] = val;
        fzgx_pad_86ECE = val;
    }
}
/* fzgx:end fn_1_106EB0 */

/* fzgx:begin fn_1_1071C0 */
void fn_1_1071C0(void) {
    if (lbl_1_bss_86EC4 != 0) {
        lbl_1_bss_86EC4 = 0;
        lbl_1_bss_86EC0 = 0;
    }
}
/* fzgx:end fn_1_1071C0 */

/* fzgx:begin fn_1_1071E8 */
#include "dolphin/hw_regs.h"
#include "psvec.h"

/* begin game/vec3.h (fork-deltawave784/windows-and-types@b1e6f2df) */
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

#endif  // GAME_VEC3_H

/* end game/vec3.h */

extern f32 lbl_1_bss_7AC88[2];
extern u8 lbl_1_bss_86EC4__fzgx_offset_3[5];
extern u32 fn_1_17920(u32, void *, f32);
extern u32 fn_1_214C4(void *, u32, f32);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E15C(f32,f32,f32);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006E0B4(f32,f32,f32);
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer(volatile f64 *d, volatile f32 *f) {  /* fzgx-allow: S2 volatile keeps the verified access order */
 *d=4503601774854144.0; *d=256.0; *f=0.0f; *d=0.0;
 *d=0.00390625; *d=1.0; *f=1.0f; *d=32768.0; *d=0.0078125;
 *d=0.5; *d=-1.0; *d=2.0; *f=32768.0f; *f=-1.0f;
 *d=4503599627370496.0;
}
#pragma section code_type ".text"
#define normal_out(dst, factor) do { \
 f32 z,y,x,s; \
 Vec3 *out=dst; \
 f32 (*a)[4]=(void*)LC_BASE; \
 s=factor; \
 x=a[0][1]; y=a[1][1]; z=a[2][1]; \
 x*=s; y*=s; z*=s; \
 out->x=x; out->y=y; out->z=z; \
} while (0)
/* Translate the locked-cache matrix along one of its columns. */
#define TRANSLATE_COL(p, c, sc) \
 p##x=m[0][c]; p##y=m[1][c]; p##z=m[2][c]; \
 p##wz=m[2][3]; p##wy=m[1][3]; p##wx=m[0][3]; \
 p##s=sc; \
 p##z=p##z*p##s+p##wz; p##y=p##y*p##s+p##wy; p##x=p##x*p##s+p##wx; \
 m[0][3]=p##x; m[1][3]=p##y; m[2][3]=p##z
#pragma opt_lifetimes off
#pragma opt_dead_assignments off
u32 fn_1_1071E8(u8 *arg0,u32 arg1,void *arg2,void *arg3,void *arg4) {
 f32 az,ay,ax,awz,awy,awx,as;
 f32 bz,by,bx,bwz,bwy,bwx,bs;
 f32 f;
 f32 cz,cy,cx,cwz,cwy,cwx,cs;
 f32 dz,dy,dx,dwy,dwz,dwx,ds;
 f32 loc_C,loc_8;
 s32 v1,v2;
 u32 v6,v5;
 LineEntry *v4;
 f32 t2;
 f32 pos,sign,width,half;
 f32 (*m)[4]=(void*)LC_BASE;
 u32 t0;
 t0=fn_1_214C4(&loc_8,0,arg1*lbl_1_bss_7AC88[0]);
 fn_1_17920(t0,0,loc_8);
 v1=*(s32*)(arg0+28);
 if(v1==1) v2=0;
 else v2=lbl_1_bss_86EC4__fzgx_offset_3[0]%(v1-1)+1;
 v4=(void*)(arg0+(v2<<7)+1024);
 t2=fn_1_20258(v4,&loc_C);
 if(*(s8*)(lbl_1_bss_86EC0+(arg1+(lbl_1_bss_86EC4__fzgx_offset_3[0]<<9)))==-128) {
  while(arg1!=0 && *(s8*)(lbl_1_bss_86EC0+(arg1+(lbl_1_bss_86EC4__fzgx_offset_3[0]<<9)))==-128) --arg1;
 }
 if(0.0==loc_C) {
  f32 z,y,x;
  lbl_8006DC6C(v4);
  x=*(volatile f32*)((u8*)v4+0x70);  /* fzgx-allow: S2 volatile view keeps the verified load order */
  y=*(f32*)((u8*)v4+0x74); z=*(f32*)((u8*)v4+0x78);
  m[0][3]=x;m[1][3]=y;m[2][3]=z;
 } else lbl_8006DBAC(v4);
 if(v4->flags&1) loc_C=-loc_C;
 if(v4->flags&0x02200000) {
  TRANSLATE_COL(a, 0, (t2*(*(s8*)((u8*)lbl_1_bss_86EC0+arg1+(lbl_1_bss_86EC4__fzgx_offset_3[0]<<9))/256.0)));
  half=0.0f;
 } else if(v4->flags&0x01800000) {
  if(1.0!=loc_C) lbl_8006E15C(1.0f,loc_C,1.0f);
  mathutil_mtxA_rotate_z((32768.0*(v4->hcylin*(*(s8*)((u8*)lbl_1_bss_86EC0+arg1+(lbl_1_bss_86EC4__fzgx_offset_3[0]<<9))/128.0))));
  TRANSLATE_COL(b, 1, (0.5*-v4->unk_68));
  half=0.5*v4->unk_68;
 } else {
  width=0.5*(v4->scl_x/t2);
  pos=*(s8*)((u8*)lbl_1_bss_86EC0+arg1+(lbl_1_bss_86EC4__fzgx_offset_3[0]<<9))/256.0;
  sign=pos>0.0f?1.0:-1.0;
  if(1.0!=loc_C) lbl_8006E15C(1.0f,loc_C,1.0f);
  if(__fabs(pos)<width) {
   lbl_8006E0B4(pos*t2,(0.5*-*(f32*)((u8*)v4+0x40)),0.0f);
  } else if(__fabs(pos)>0.5-width) {
   lbl_8006E0B4((t2*((f64)(0.5*sign)-pos)),(0.5**(f32*)((u8*)v4+0x40)),0.0f);
  } else {
   f=(pos-(f32)(sign*width))/(0.5-(f64)(2.0*width));
   TRANSLATE_COL(c, 0, (0.5*(sign*v4->scl_x)));
   mathutil_mtxA_rotate_z((32768.0f*f));
   TRANSLATE_COL(d, 1, (0.5*-*(f32*)((u8*)v4+0x40)));
  }
  half=0.5**(f32*)((u8*)v4+0x40);
 }
 if(arg4) *(f32*)arg4=half;
 if(arg3) {
  if((v4->flags&0x01400000) || ((v4->flags&0x00800001)==0x00800001 && __fabs(loc_C)>0.5)) {
   if(v4->flags&1) normal_out(arg3,-1.0f);
   else normal_out(arg3,1.0f);
  } else *(Vec3*)arg3=*(Vec3*)((u8*)v4+0x5c);
 }
 psvec_set(arg2,m[2][3],m[1][3],m[0][3]);
 return v4->flags;
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_1071E8 */

/* fzgx:begin fn_1_10780C */
#include "psvec.h"

extern f32 lbl_8006D668(u32 *);
extern u16 lbl_1_bss_86ECC;
extern u32 fn_1_1071E8(u8 *, u32, void *, void *, void *);
extern u8 *fn_1_14F04(void);

void fn_1_10780C(void *arg0, void *arg1, u32 *arg2, void *arg3) {
    u8 *t0;
    struct { u32 a[3]; } loc_14;
    u32 loc_8[3];
    s32 v1;
    s32 v0;
    t0 = fn_1_14F04();
    v0 = lbl_1_bss_86ECC - 1;
    v0 = v0 < 0 ? 511 : v0;
    fn_1_1071E8(t0, v0, &loc_14, 0, 0);
    v1 = lbl_1_bss_86ECC + 1;
    fn_1_1071E8(t0, v1 < 512 ? v1 : 0, loc_8, 0, 0);
    psvec_sub(loc_8, &loc_14, arg2);
    lbl_8006D668(arg2);
    fn_1_1071E8(t0, lbl_1_bss_86ECC, arg0, arg1, arg3);
}
/* fzgx:end fn_1_10780C */
