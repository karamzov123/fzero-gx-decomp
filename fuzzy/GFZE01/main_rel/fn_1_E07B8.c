/* Non-matching: best partial attempt (92.26% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/bg_for.h"

typedef struct { f32 y; f32 x; f32 z; } E07Vec;
typedef struct {
    u8 pad_0[0xC]; s16 mode; u8 pad_E[0xA]; f32 f18; u8 pad_1C[4]; f32 f20;
    u8 pad_24[0x20]; E07Vec v44; f32 f50; E07Vec v54; E07Vec v60; E07Vec v6c;
    u8 pad_78[0xC]; f32 f84; E07Vec v88; u8 pad_94[0x28]; u32 ubc; u32 uc0;
    E07Vec vc4; u8 pad_D0[0x24]; f32 ff4; f32 ff8; u8 pad_FC[4];
    s32 s100; s32 s104; s32 s108; s32 s10c; E07Vec v110; E07Vec v11c;
    E07Vec v128; u8 pad_134[4]; u64 flags; u8 pad_140[0x60]; f32 f1a0; f32 f1a4;
} E07Obj;
extern const f32 lbl_1_rodata_6780[65];
extern u32 lbl_801A66A0;
extern void *fn_1_14F04(void);
extern void fn_80008BA8(void *, const void *, u32);
extern void fn_80008BEC(void *, int, u32);
extern void lbl_8006D668(void *);
extern f32 lbl_8006D534(void *, void *);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D5F0(void *, void *, f32);
extern void lbl_8006D5A4(void *, void *, void *, f32);
extern int fn_1_20A5C(void *, void *);
extern int fn_1_15578(void *, void *, void *, void *, int, void *, u32, int, int, int);
extern int fn_1_DF2A4(void *, void *, void *, void *, void *, void *, void *, f32, f32);
#define R_M1 (tb[0])
#define R_0 (tb[8])
#define R_1 (tb[10])
#define R_101 (tb[62])
#define R_005 (tb[63])
#define R_1001 (tb[64])
#define E07_CROSS(a,b,out) { f32 cx_=(a)->y*(b)->z-(a)->z*(b)->y; f32 cy_=(a)->z*(b)->x-(a)->x*(b)->z; f32 cz_=(a)->x*(b)->y-(a)->y*(b)->x; (out)->x=cx_; (out)->y=cy_; (out)->z=cz_; }
#define E07_SLIDE(o,n,s) { E07Vec r_,v1_,c_; f32 d_,dd_,sq_,o50_,k_; int clamp_; d_=lbl_8006D534(&(o)->v44,(n)); if (!(d_>R_0)) { dd_=d_*d_; sq_=lbl_8006D0B4(R_1-dd_); o50_=(o)->f50; k_=o50_ * -(o)->f18; fn_80008BA8(&v1_,(n),12); lbl_8006D5F0(&v1_,&v1_,k_*d_); fn_80008BA8(&c_,&(o)->v44,12); E07_CROSS(&c_,(n),&r_) E07_CROSS(&r_,(n),&r_) if (r_.x*r_.x+r_.y*r_.y+r_.z*r_.z>R_0) lbl_8006D668(&r_); if (!(c_.x*r_.x+c_.y*r_.y+c_.z*r_.z>R_0)) psvec_scale(&r_,R_M1,&r_); psvec_scale(&r_,o50_*sq_,&r_); if ((s)<R_0) clamp_=0; else if (v1_.x*v1_.x+v1_.y*v1_.y+v1_.z*v1_.z<=(s)*(s)) { fn_80008BEC(&v1_,0,12); clamp_=1; } else clamp_=0; if (clamp_==1) { (o)->flags|=0x8000; if (!((o)->flags&0x8000000)) (o)->flags|=0x100000000ULL; } psvec_add(&v1_,&r_,&(o)->v44); psvec_scale(&(o)->v6c,R_1-(o)->f20,&(o)->v6c); } }
static inline f32 fn_1_E07B8_read_pointer(E07Obj *owner) { return owner->ff8; }
#pragma opt_lifetimes off
#pragma opt_common_subs off
s32 fn_1_E07B8(E07Obj *o) {
    f32 fzgx_live; const f32 *tb; E07Vec b4,a8,v9c,v90,v84; f32 f14,f10,sc,nsc; u8 *p; s32 ret,r,tmp_ra6;
    ret=0; tb=lbl_1_rodata_6780;
    if ((o->flags&0x20)!=0) return 0;
    sc=(R_101*o->f84)*fn_1_E07B8_read_pointer(o);
    fn_80008BA8(&b4,&o->v54,12); fn_80008BA8(&a8,&o->v60,12); fn_80008BA8(&v9c,&o->v128,12);
    nsc=-sc; psvec_scale(&v9c,nsc,&v9c); psvec_add(&b4,&v9c,&b4); psvec_add(&a8,&v9c,&a8);
    p=fn_1_14F04(); o->s100=fn_1_20A5C(&b4,&f14); o->s104=o->s108=o->s10c=o->s100;
    switch(o->mode) {
    case 1:
      if(o->s100>=0) {
        if(fn_1_15578(&b4,&a8,&f10,&v90,1,&o->s100,*(u32 *)(lbl_1_bss_3BE0->unk_C+o->s100*12),0,0,0)!=0) {
          fn_80008BA8(&o->v11c,&v90,12); lbl_8006D668(&o->v11c);
          if(o->flags&0x10000) fn_80008BA8(&o->v128,&o->v11c,12);
          lbl_8006D5A4(&a8,&b4,&o->v110,f10);
        }
      }
      r=fn_1_DF2A4(&o->v60,&o->v54,&o->vc4,&o->v110,&o->v11c,&v84,&o->v88,o->f1a0*o->ff4,o->f1a4*fn_1_E07B8_read_pointer(o));
      if((s16)r!=0) {
        ret=1; o->flags|=0x40000000; if((s16)r!=3) o->flags|=0x8000000;
        psvec_add(&o->v54,&v84,&o->v54); fzgx_live=o->f18; sc=R_005*fzgx_live;
        if(!(o->flags&0x8000)) E07_SLIDE(o,&o->v11c,sc)
      } break;
    default:
      if(o->s100>=0) {
       if(fn_1_15578(&b4,&a8,&f10,&v90,5,&o->s100,*(u32 *)(lbl_1_bss_3BE0->unk_C+o->s100*12),0,0,0)!=0) {
        if(*(u32 *)(p+0x118)&4) { fzgx_live=o->f18; sc=R_005*fzgx_live; if(!(o->flags&0x8000)) E07_SLIDE(o,&v90,sc) }
        ret=1; o->flags|=0x40000000; fn_80008BA8(&o->v11c,&v90,12);
        if(o->flags&0x10000) fn_80008BA8(&o->v128,&o->v11c,12);
        psvec_scale(&v9c,R_1001,&v9c); psvec_sub(&b4,&v9c,&b4); fn_80008BA8(&o->v54,&b4,12);
        fzgx_live=o->f18; sc=R_005*fzgx_live; if(!(o->flags&0x8000)) E07_SLIDE(o,&o->v11c,sc)
       }
      } break;
    }
    o->flags|=0x10000000000ULL; tmp_ra6=o->flags;
    if(tmp_ra6!=0&&(s32)o->uc0!=-65537&&ret!=0) { u32 t=lbl_801A66A0,d=t-o->uc0; if(d<0x168) { if(d<0x78) o->uc0=t-(o->ubc-0x1E); else o->uc0=t-(o->ubc-0x78); } }
    return ret;
}
#pragma opt_common_subs reset
#pragma opt_lifetimes reset
