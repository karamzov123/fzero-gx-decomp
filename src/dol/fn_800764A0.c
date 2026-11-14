#include "types.h"
struct fn_800764A0_Arg0 { u32 unk_0; };
struct fn_800764A0_lbl_801A3220 { u8 pad_0[0x3C]; s32 unk_3C; s32 unk_40; };
struct fn_800764A0_lbl_801A6D00_T {
 u8 pad_0[0xC]; f32 unk_C; f32 unk_10; f32 unk_14; f32 unk_18;
 f32 unk_1C; f32 unk_20; f32 unk_24; f32 unk_28; f32 unk_2C;
};
extern f32 lbl_801A7480;
extern f32 lbl_801A7488;
extern f32 lbl_801A748C;
extern f32 lbl_801A749C;
extern struct fn_800764A0_lbl_801A3220 lbl_801A3220;
extern struct fn_800764A0_lbl_801A6D00_T *lbl_801A6D00;
extern u32 lbl_8015AD28[];
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E14C(f32);
extern void GXLoadTexMtxImm(void *, u32, u32);
extern void fn_8006F120(void *, void *);
extern void fn_80072AB0(s32,s32,s32);
extern void fn_80072C24(s32,s32,s32,s32,s32);
extern void fn_80072CC4(s32,s32,s32,s32,s32);
extern void fn_80072D64(s32,s32,s32,s32,u8,s32);
extern void fn_80072E20(s32,s32,s32,s32,u8,s32);
extern void fn_800734A8(u32,s32,s32,s32);
extern void fn_800735C8(s32,s32);
extern void fn_80073C6C(s32);
extern void fn_800736C0(u32,void *);
extern void fn_800745A4(u32,s32,s32,u32,u32,u32);
static inline f32 fn_800764A0_operand(f32 left, f32 right) { left *= right; return left; }
static inline f32 fn_800764A0_operand_(f32 right, f32 left) { return left * right; }
static inline f32 fn_800764A0_operand__(f32 right, f32 left) { left *= right; return left; }
static inline f32 fn_800764A0_read_pointer(struct fn_800764A0_lbl_801A6D00_T *owner) { return owner->unk_10; }
void fn_800764A0(struct fn_800764A0_Arg0 *arg0, void *arg1, u32 arg2) {
 struct fn_800764A0_lbl_801A3220 *p_lbl_801A3220;
 f32 v2;
 struct { volatile u8 a[8]; } loc_8; /* Preserve the ordered byte stores interleaved with state reads. */
 s32 lab_t2;
 u32 color_arg0;
 u32 color_arg1;
 fn_80073C6C(arg0->unk_0);
 fn_80072AB0(arg0->unk_0,0,0);
 p_lbl_801A3220 = &lbl_801A3220;
 if (p_lbl_801A3220->unk_3C == 0) {
 lbl_8006DAEC();
 lbl_801A6D00->unk_C = 0.0f;
 lbl_801A6D00->unk_1C = 0.0f;
 lbl_801A6D00->unk_2C = 0.0f;
 GXLoadTexMtxImm(lbl_801A6D00,30,0);
 lbl_8006DB30();
 p_lbl_801A3220->unk_3C = 1;
 }
 p_lbl_801A3220 = &lbl_801A3220;
 if (p_lbl_801A3220->unk_40 == 0) {
 lbl_8006DAEC();
 fn_8006F120(lbl_8015AD28,(void *)((u8 *)&lbl_801A3220+0x50));
 lbl_801A6D00->unk_C = 0.5f;
 lbl_801A6D00->unk_10 = fn_800764A0_operand_(-1.0f,fn_800764A0_read_pointer(lbl_801A6D00));
 lbl_801A6D00->unk_14 = fn_800764A0_operand(lbl_801A6D00->unk_14,-1.0f);
 v2 = fn_800764A0_operand__(-1.0f,lbl_801A6D00->unk_18);
 lbl_801A6D00->unk_18 = v2;
 lbl_801A6D00->unk_1C = 0.5f;
 lbl_801A6D00->unk_20 = 0.0f;
 lbl_801A6D00->unk_24 = 0.0f;
 lbl_801A6D00->unk_28 = 0.0f;
 lbl_801A6D00->unk_2C = 1.0f;
 lbl_8006E14C(0.5f);
 GXLoadTexMtxImm(lbl_801A6D00,64,0);
 lbl_8006DB30();
 p_lbl_801A3220->unk_40 = 1;
 }
 loc_8.a[4] = arg2;
 color_arg0 = *(volatile u32 *)((u8 *)arg0+0); /* Preserve state read ordering relative to the color byte stores. */
 loc_8.a[5] = arg2;
 color_arg1 = *(volatile u32 *)((u8 *)arg0+4); /* Preserve state read ordering relative to the color byte stores. */
 loc_8.a[6] = arg2;
 lab_t2 = *(volatile u32 *)((u8 *)arg0+12); /* Preserve state read ordering relative to the color byte stores. */
 loc_8.a[7] = arg2;
 fn_800734A8(color_arg0,color_arg1,lab_t2,4);
 *(u32 *)((u8 *)&loc_8+0) = *(u32 *)((u8 *)&loc_8+4);
 fn_800736C0(0,(void *)&loc_8);
 fn_800735C8(*(u32 *)((u8 *)arg0+0),12);
 fn_800745A4(*(u32 *)((u8 *)arg0+4),0,1,30,1,64);
 fn_80072C24(*(u32 *)((u8 *)arg0+0),15,8,14,15);
 fn_80072D64(*(u32 *)((u8 *)arg0+0),0,0,0,1,2);
 fn_80072CC4(*(u32 *)((u8 *)arg0+0),7,7,7,*(u32 *)((u8 *)arg1+12));
 fn_80072E20(*(u32 *)((u8 *)arg0+0),0,0,0,1,2);
 (*(u32 *)((u8 *)arg0+0))++;
 (*(u32 *)((u8 *)arg0+4))++;
 fn_80073C6C(*(u32 *)((u8 *)arg0+0));
 fn_80072AB0(*(u32 *)((u8 *)arg0+0),0,0);
 lab_t2 = 255;
 fn_800734A8(*(u32 *)((u8 *)arg0+0),255,lab_t2,255);
 fn_80072C24(*(u32 *)((u8 *)arg0+0),15,4,10,*(u32 *)((u8 *)arg1+8));
 fn_80072D64(*(u32 *)((u8 *)arg0+0),0,0,0,1,0);
 fn_80072CC4(*(u32 *)((u8 *)arg0+0),7,7,7,2);
 fn_80072E20(*(u32 *)((u8 *)arg0+0),0,0,0,1,0);
 { u32 v3; v3=*(u32 *)((u8 *)arg0+0); *(u32 *)((u8 *)arg0+0)=v3+1; }
}
