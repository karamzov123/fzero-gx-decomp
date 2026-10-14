/* Non-matching: best partial attempt (98.76% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"
#include "psvec.h"
typedef struct { f32 s,c; } Sig_lbl_8006D1B8_Vec2;
typedef struct { f32 x,y,z; } Sig_fn_8006E7E4_Vec3;
typedef struct { f32 x,y,z,w; } Sig_fn_8006E7E4_Vec4;
typedef struct { f32 m[12]; } Mtx;
struct fn_1_290E8_Arg0 {
 u32 flags; u8 pad_4[4]; f32 unk_8; u8 pad_C[0x88];
 Sig_fn_8006E7E4_Vec3 velocity;
 u8 pad_A0[0x4c]; Mtx matrix;
 u8 pad_11C[0x64]; f32 angle;
 u8 pad_184[0x38]; Sig_fn_8006E7E4_Vec3 direction;
 f32 unk_1C8; u8 pad_1CC[0x50]; u32 flags_21C;
};
extern const struct fn_1_290E8_lbl_1_rodata_840 {
 u8 pad_0[0xC]; f32 unk_C; u8 pad_10[4]; f32 unk_14; f32 unk_18;
 u8 pad_1C[0xC]; f32 unk_28; u8 pad_2C[0xC]; f32 unk_38;
 u8 pad_3C[0x3C]; f32 unk_78; f32 unk_7C; u8 pad_80[4]; f32 unk_84;
 u8 pad_88[0x28]; f32 unk_B0; u8 pad_B4[0xB4]; f32 unk_168;
 u8 pad_16C[0x2C]; f32 unk_198; u8 pad_19C[0x114]; f64 unk_2B0;
 f32 unk_2B8,unk_2BC,unk_2C0,unk_2C4,unk_2C8; u8 pad_2CC[4];
 f64 unk_2D0; f32 unk_2D8,unk_2DC;
} lbl_1_rodata_840;
extern f32 *lbl_801A6D00;
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D6FC(void *,void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DFC4(void *);
extern void fn_8006E7E4(void *,void *,s32);
extern void lbl_8006D1B8(s32,void *);
extern void lbl_8006E1F0(void *,f32,f32,f32);
extern void mathutil_mtxA_from_quat(void *);
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_loop_invariants off
static inline f32 fn_1_290E8_read_pointer(struct fn_1_290E8_lbl_1_rodata_840 * owner) { return owner->unk_28; }
static inline f32 fn_1_290E8_operand(f32 left, f32 right) { return ((((left)) * ((right)))); }
static inline f32 fn_1_290E8_read_pointer_(struct fn_1_290E8_lbl_1_rodata_840 * owner) { return owner->unk_14; }
static inline f32 fn_1_290E8_read_pointer__(Sig_fn_8006E7E4_Vec3 * owner) { return owner->x; }
static inline f32 fn_1_290E8_read_pointer___(struct fn_1_290E8_Arg0 * owner) { return owner->direction.y; }
static inline f32 fn_1_290E8_read_pointer____(struct fn_1_290E8_Arg0 * owner) { return owner->direction.z; }
#pragma opt_strength_reduction on
static inline f32 fn_1_290E8_read_pointer_____(struct fn_1_290E8_Arg0 * owner) { return owner->direction.x; }
#pragma opt_lifetimes off
static inline f32 fn_1_290E8_operand_(f32 right, f32 left) { left *= right; return left; }
void fn_1_290E8(struct fn_1_290E8_Arg0 *arg0) {
    f32 fzgx_live____;
    f32 fzgx_live___;
    f32 fzgx_live__;
    f32 fzgx_live_;
    f32 *fzgx_value;
 Sig_fn_8006E7E4_Vec3 loc_78;
 struct fn_1_290E8_lbl_1_rodata_840 *p_lbl_1_rodata_840=(struct fn_1_290E8_lbl_1_rodata_840 *)&lbl_1_rodata_840;
 Mtx loc_B4;
 Mtx loc_84;
 Sig_fn_8006E7E4_Vec4 loc_68;
    f32 fzgx_live;
 Sig_fn_8006E7E4_Vec3 loc_5C;
 Sig_fn_8006E7E4_Vec3 loc_50;
 Sig_fn_8006E7E4_Vec4 loc_40;
 Sig_fn_8006E7E4_Vec3 loc_34;
 Sig_fn_8006E7E4_Vec3 loc_28;
 Sig_fn_8006E7E4_Vec3 loc_1C;
 Sig_fn_8006E7E4_Vec3 loc_10;
 Sig_lbl_8006D1B8_Vec2 loc_8;
 f32 v0;
    f32 v13_2;
 f32 v1;
    f32 fzgx_live_2;
 f32 v5;
 f32 v13;
 f32 v16;
 f32 v15;
 f32 v24;
 f32 v25;
 f32 v29;
 f32 *v22;
 fzgx_live____ = arg0->unk_8;
 v0=fzgx_live____;
 v5=p_lbl_1_rodata_840->unk_84+v0/p_lbl_1_rodata_840->unk_2C8;
 if(v5<p_lbl_1_rodata_840->unk_7C) v5=p_lbl_1_rodata_840->unk_2D0-v5;
 else if(v5>p_lbl_1_rodata_840->unk_78) v5=p_lbl_1_rodata_840->unk_78;
 if(arg0->flags&2) {
 if(arg0->unk_1C8>p_lbl_1_rodata_840->unk_C) {
 if(arg0->flags&0x200) v5*=p_lbl_1_rodata_840->unk_7C;
 else v5*=p_lbl_1_rodata_840->unk_2D8;
 } else v5*=p_lbl_1_rodata_840->unk_38;
 } else v5*=p_lbl_1_rodata_840->unk_2D8;
 fzgx_live=p_lbl_1_rodata_840->unk_168 * -(p_lbl_1_rodata_840->unk_2DC*v0);
 psvec_scale(&arg0->direction,fzgx_live*v5,&loc_78);
 psvec_add(&arg0->velocity,&loc_78,&arg0->velocity);
 if(arg0->flags&2) {
 lbl_8006D1B8((s32)(p_lbl_1_rodata_840->unk_198*arg0->angle),&loc_8);
 lbl_8006E1F0(&loc_5C,p_lbl_1_rodata_840->unk_C,loc_8.c,loc_8.s);
 v13=lbl_8006D6FC(&loc_5C,&arg0->direction);
 if(v13<p_lbl_1_rodata_840->unk_2B8) {
 v15=v13+p_lbl_1_rodata_840->unk_2BC;
 if(arg0->flags_21C&0x1800000) v16=p_lbl_1_rodata_840->unk_2C0;
 else v16=p_lbl_1_rodata_840->unk_2C4;
 {
 f32 v19;
 f32 v20;
 f32 v21;
 fzgx_live_ = loc_5C.y;
 fzgx_live__ = arg0->direction.z;
 fzgx_live___ = loc_5C.z;
 v19=(f32)(fn_1_290E8_operand((fzgx_live_), (fzgx_live__)))-fzgx_live___*arg0->direction.y;
 fzgx_live_2 = fn_1_290E8_read_pointer_____(arg0);
 fzgx_live__ = arg0->direction.z;
 fzgx_live___ = loc_5C.z;
 v20=(f32)(fn_1_290E8_operand_((fzgx_live_2), (fzgx_live___)))-((fzgx_live__) * (loc_5C.x));
 v13_2=v19*v19;
 loc_50.x=v19;
 fzgx_live_ = loc_5C.y;
 v21=(f32)(loc_5C.x*arg0->direction.y)-fzgx_live_*fn_1_290E8_read_pointer_____(arg0);
 loc_50.y=v20;
 v13_2=v20*v20+v13_2;
 loc_50.z=v21;
 v13_2=v21*v21+v13_2;
 v13_2=lbl_8006D0B4(v13_2);
 }
 if(v13_2<p_lbl_1_rodata_840->unk_18 || v15<p_lbl_1_rodata_840->unk_2BC) {
 lbl_8006E1F0(&loc_1C,p_lbl_1_rodata_840->unk_C,fn_1_290E8_read_pointer_(p_lbl_1_rodata_840),p_lbl_1_rodata_840->unk_C);
 if(!(lbl_8006D6FC(&loc_1C,&arg0->direction)>p_lbl_1_rodata_840->unk_C)) {
 v22=lbl_801A6D00;
 loc_10.x=v22[0];loc_10.y=v22[4];loc_10.z=v22[8];
 loc_50.x=v22[2];loc_50.y=v22[6];loc_50.z=v22[10];
 if(lbl_8006D6FC(&arg0->direction,&loc_10)>p_lbl_1_rodata_840->unk_2B0) {
 loc_50.x=-loc_50.x;loc_50.y=-loc_50.y;loc_50.z=-loc_50.z;
 }
 }
 }
 if(v15<p_lbl_1_rodata_840->unk_2B0) v15=p_lbl_1_rodata_840->unk_C;
 else v15*=v15;
 fn_8006E7E4(&loc_68,&loc_50,(s32)(p_lbl_1_rodata_840->unk_198*(v16*(fn_1_290E8_read_pointer_(p_lbl_1_rodata_840)-v15))));
 lbl_8006DB74(&loc_B4);
 mathutil_mtxA_from_quat(&loc_68);
 lbl_8006DFC4(&loc_B4);
 }
 lbl_8006DB74(&arg0->matrix);
 } else {
 lbl_8006E1F0(&loc_28,p_lbl_1_rodata_840->unk_C,fn_1_290E8_read_pointer_(p_lbl_1_rodata_840),p_lbl_1_rodata_840->unk_C);
 v13_2=lbl_8006D6FC(&loc_28,&arg0->direction);
 if(v13_2<p_lbl_1_rodata_840->unk_B0) {
 v25=p_lbl_1_rodata_840->unk_B0;
 if(v13_2<p_lbl_1_rodata_840->unk_2B0) v25=p_lbl_1_rodata_840->unk_C;
 else v25=v13_2/v25;
 {
 f32 v30;
 f32 v31;
 f32 v32;
 v25=fn_1_290E8_read_pointer_(p_lbl_1_rodata_840)-v25;
 v29=p_lbl_1_rodata_840->unk_198*(fn_1_290E8_read_pointer(p_lbl_1_rodata_840)*v25);
 fzgx_live__ = arg0->direction.z;
 v30=(f32)(loc_28.y*fzgx_live__)-loc_28.z*arg0->direction.y;
 fzgx_live__ = arg0->direction.z;
 v31=(f32)(loc_28.z*fn_1_290E8_read_pointer_____(arg0))-loc_28.x*fzgx_live__;
 v32=(f32)(loc_28.x*arg0->direction.y)-loc_28.y*fn_1_290E8_read_pointer_____(arg0);
 loc_34.x=v30;
 loc_34.y=v31;
 loc_34.z=v32;
 fn_8006E7E4(&loc_40,&loc_34,(s32)v29);
 }
 lbl_8006DB74(&loc_84);
 mathutil_mtxA_from_quat(&loc_40);
 lbl_8006DFC4(&loc_84);
 }
 lbl_8006DB74(&arg0->matrix);
 }
}
#pragma opt_lifetimes reset

#pragma opt_strength_reduction reset

