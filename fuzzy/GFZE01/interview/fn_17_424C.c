/* Non-matching: best partial attempt (86.73% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/interview/interview.h"
typedef struct { f32 x, y; u32 z,w,p,q; } Vertex;
typedef struct { u8 pad_0[0x88]; s32 unk_88; } TypeObj;
typedef struct { u8 pad_0[0x1C]; void *field_1C; } CarObj;
typedef struct { u8 pad_0[0x24]; void *field_24; } EventData;
typedef struct { u8 pad_0[8]; EventData *field_8; void *field_C; } EventObj;
struct InterviewBss {
 u8 pad_0[0x10]; u8 *unk_10; u8 pad_14[0x44]; u32 unk_58;
 u8 pad_5C[0x7C]; TypeObj *unk_D8; u8 pad_DC[0x70]; u32 unk_14C;
 u8 pad_150[0x48]; u32 unk_198; Vertex verts[15];
};
struct InterviewRodata {
    u8 lab_pad[4];
 u8 pad_0[0x3C]; f32 unk_3C; u8 pad_40[0x158];
 Vertex vertex; f32 unk_1B0; f32 unk_1B4;
};
extern struct InterviewRodata lbl_17_rodata_0;
extern u32 lbl_801A63C0;
extern u32 lbl_801A6410;
extern u32 fn_1_4630(u32,u32,u32,u32);
extern u32 fn_1_8F198(u32,u32,u32,u32);
extern u32 fn_1_8F45C(u32,u32,u32,u32);
extern void fn_1_8E728(u32,u8);
extern void fn_1_934CC(CarObj *,EventObj *,u32);
extern void *fn_1_435C(void *);
extern void fn_1_8F62C(u32);
extern void fn_17_4214(TypeObj *);
extern s32 fn_1_3F8C(u32,void *,u32,u32);
#pragma opt_unroll_count 1
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_17_bss_0;
u8 fzgx_obj_lbl_17_bss_1;
u8 lbl_17_bss_2;
u8 lbl_17_bss_3;
u32 lbl_17_bss_3_fill_4[2];
u32 lbl_17_bss_C;
u8 *lbl_17_bss_10;
u32 fzgx_obj_lbl_17_bss_14;
u32 fzgx_obj_lbl_17_bss_18[2];
u32 lbl_17_bss_20;
u32 lbl_17_bss_24[4];
u32 lbl_17_bss_34[8];
u32 fzgx_obj_lbl_17_bss_54;
u32 fzgx_obj_lbl_17_bss_58;
u32 lbl_17_bss_58_fill_5C;
u32 fzgx_obj_lbl_17_bss_60[29];
u16 lbl_17_bss_60_fill_D4;
u16 fzgx_obj_lbl_17_bss_D6;
TypeObj *fzgx_obj_lbl_17_bss_D8;
u32 lbl_17_bss_D8_fill_DC[7];
u16 lbl_17_bss_D8_fill_F8;
u16 lbl_17_bss_FA;
u32 lbl_17_bss_FA_fill_FC[20];
u32 lbl_17_bss_14C;
u32 lbl_17_bss_150[4];
u32 lbl_17_bss_160[4];
u32 fzgx_obj_lbl_17_bss_170[10];
u16 lbl_17_bss_198;
Vertex lbl_17_bss_198_4[15];
u32 lbl_17_bss_198_fill_304[4];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_17_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_1;
    s = *(u8 *)&lbl_17_bss_2;
    s = *(u8 *)&lbl_17_bss_3;
    s = *(u8 *)&lbl_17_bss_3_fill_4;
    s = *(u8 *)&lbl_17_bss_C;
    s = *(u8 *)&lbl_17_bss_10;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_14;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_18;
    s = *(u8 *)&lbl_17_bss_20;
    s = *(u8 *)&lbl_17_bss_24;
    s = *(u8 *)&lbl_17_bss_34;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_54;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_58;
    s = *(u8 *)&lbl_17_bss_58_fill_5C;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_60;
    s = *(u8 *)&lbl_17_bss_60_fill_D4;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_D6;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_D8;
    s = *(u8 *)&lbl_17_bss_D8_fill_DC;
    s = *(u8 *)&lbl_17_bss_D8_fill_F8;
    s = *(u8 *)&lbl_17_bss_FA;
    s = *(u8 *)&lbl_17_bss_FA_fill_FC;
    s = *(u8 *)&lbl_17_bss_14C;
    s = *(u8 *)&lbl_17_bss_150;
    s = *(u8 *)&lbl_17_bss_160;
    s = *(u8 *)&fzgx_obj_lbl_17_bss_170;
    s = *(u8 *)&lbl_17_bss_198;
    s = *(u8 *)&lbl_17_bss_198_4;
    s = *(u8 *)&lbl_17_bss_198_fill_304;
}
#pragma section code_type ".text"

void fn_17_424C(void) {
 
 struct InterviewRodata *rod = &lbl_17_rodata_0;
 u32 slot;
 u8 *tbl = (u8 *)&lbl_17_data_0 + 0x60000;
 u32 color;
 u8 *car;
 u32 seed, a;
 s32 i;
 Vertex v, original, other;
 f32 scale, half, norm;
 if (fzgx_obj_lbl_17_bss_D8->unk_88 != 35 && fzgx_obj_lbl_17_bss_D8->unk_88 != 8) return;
 if (!(fzgx_obj_lbl_17_bss_58 & 0x400000)) return;
 car = (u8 *)fn_1_4630(lbl_801A6410,0x4E0,(u32)(tbl+0x3E50),0xA20);
 lbl_17_bss_198 = (u32)car;
 switch ((s32)((31-__cntlzw(lbl_17_bss_10[6]))&3)) {
 case 0: color=0x80000000; slot=0; break;
 case 1: color=0x40000000; slot=1; break;
 case 2: color=0x20000000; slot=2; break;
 case 3: color=0x10000000; slot=3; break;
 default: color=0x80000000; slot=0; break;
 }
 switch (fzgx_obj_lbl_17_bss_D8->unk_88) {
 case 35:
 fn_1_8F198((u32)car,4,0x40000000,color);
 *(u32 *)(car+0x8C)=1;
 fn_1_934CC((CarObj *)car,(EventObj *)(((0x148) + (car))),(u32)(tbl+0x309C));
 fn_1_435C((void *)lbl_17_bss_14C);
 fn_1_3F8C((u32)(tbl+0x407C),fn_1_8F62C,(u32)car,10);
 fn_1_3F8C((u32)(tbl+0x4084),fn_17_4214,(u32)car,11);
 break;
 case 8:
 fn_1_8F45C((u32)car,8,0x10000000,color);
 *(u32 *)(car+0x8C)=3;
 fn_1_934CC((CarObj *)car,(EventObj *)(car+0x148),(u32)(tbl+0x4094));
 fn_1_435C((void *)lbl_17_bss_14C);
 fn_1_3F8C((u32)(tbl+0x407C),fn_1_8F62C,(u32)car,10);
 break;
 }
 if (*(u8 *)(car+0x98)!=slot) {
 fn_1_8E728((u32)car,(u8)slot);
 *(u8 *)(car+0x98)=slot;
 }
 {
 struct Copy12 { u32 words[3]; };
 struct Copy12 first = *(struct Copy12 *)&rod->vertex;
 struct Copy12 second = *(struct Copy12 *)&rod->vertex.w;
 struct Copy12 temp;
 seed = lbl_801A63C0;
 scale=(3.0f); norm=(32767.0f); half=(0.5f);
 for (i=0;(s16)i<15;i++) {
 temp=first;
 a=seed*0x676A4B6B+0x33CB;
 seed=a*0x676A4B6B+0x33CB;
 *(f32 *)&temp.words[0]=scale*((f32)(s32)((a>>16)&0x7FFF)/norm-half);
 *(f64 *)&temp.words[1]=scale+(f32)(s32)((seed>>16)&0x7FFF)/norm;
 *(struct Copy12 *)&lbl_17_bss_198_4[i]=temp;
 *(struct Copy12 *)&lbl_17_bss_198_4[i].w=second;
 }
 }
 lbl_801A63C0=seed;
}
