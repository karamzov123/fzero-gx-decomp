/* Non-matching: best partial attempt (93.75% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/screen_effect.h"
typedef struct { u8 pad_0[0x70]; f32 unk_70; u8 pad_74[0x34]; f32 unk_A8; } Rodata3278;
typedef struct { s8 unk_0; u8 unk_1; f32 unk_4; f32 unk_8; u8 unk_C, unk_D, unk_E, unk_F; } Entry;
typedef struct { u32 unk_0, unk_4, unk_8, unk_C, unk_10, unk_14; } Rec;
typedef struct { u8 pad_0[0x20]; Rec rec[12]; Entry ent0; u8 pad_150[8]; Rec ent1; } Bss6D600;
Obj_1_bss_6D600 fzgx_obj_lbl_1_bss_6D600;
Rec fzgx_obj_lbl_1_bss_6D600__fzgx_offset_20[4];
Rec fzgx_obj_lbl_1_bss_6D600__fzgx_offset_80[4];
Rec fzgx_obj_lbl_1_bss_6D600__fzgx_offset_E0[4];
Entry fzgx_obj_lbl_1_bss_6D600__fzgx_offset_140;
u8 fzgx_obj_lbl_1_bss_6D600__fzgx_offset_150[8];
Rec fzgx_obj_lbl_1_bss_6D600__fzgx_offset_158;
#pragma section code_type ".fzgxpool"
void primer(void) {
 volatile u32 x; /* Keep pool layout reads. */
 x=fzgx_obj_lbl_1_bss_6D600.unk_0;
 x=(*((fzgx_obj_lbl_1_bss_6D600__fzgx_offset_20) + (0))).unk_0;
 x=(*((fzgx_obj_lbl_1_bss_6D600__fzgx_offset_80) + (0))).unk_0;
 x=(*((fzgx_obj_lbl_1_bss_6D600__fzgx_offset_E0) + (0))).unk_0;
 x=fzgx_obj_lbl_1_bss_6D600__fzgx_offset_140.unk_0;
 x=(*((fzgx_obj_lbl_1_bss_6D600__fzgx_offset_150) + (0)));
 x=fzgx_obj_lbl_1_bss_6D600__fzgx_offset_158.unk_0;
}
#pragma section code_type ".text"
extern Rodata3278 lbl_1_rodata_3278;
extern u32 fn_1_7AA50(f32);
extern u32 fn_1_7E8F4(void);
#define SRC fzgx_obj_lbl_1_bss_6D600__fzgx_offset_158
#define E1B ((Entry *)&SRC)
#define b_ent0 fzgx_obj_lbl_1_bss_6D600__fzgx_offset_140
#define CP(D) (D).unk_0=SRC.unk_0; (D).unk_4=SRC.unk_4; (D).unk_8=SRC.unk_8; (D).unk_C=SRC.unk_C; (D).unk_14=(u32)&SRC; (D).unk_10=0x20;
#pragma opt scheduling off
#define CE(D) (D).unk_10=SRC.unk_10; (D).unk_14=SRC.unk_14;
#define CV(D) (D).unk_0=SRC.unk_0; (D).unk_4=SRC.unk_4; (D).unk_8=SRC.unk_8; (D).unk_C=SRC.unk_C; (D).unk_10=SRC.unk_10; (D).unk_14=SRC.unk_14;
#pragma opt_propagation off
void fn_1_79948(u32 arg0) {
 Rodata3278 *ro=&lbl_1_rodata_3278;
 Obj_1_bss_3BE0_Target *g=lbl_1_bss_3BE0;
#define e0 (&b_ent0)
#define e1 E1B
#define q fzgx_obj_lbl_1_bss_6D600__fzgx_offset_20
#define r fzgx_obj_lbl_1_bss_6D600__fzgx_offset_80
#define s fzgx_obj_lbl_1_bss_6D600__fzgx_offset_E0
 Entry *e;
 Rec t4;
 Rec t3;
 Rec t0;
 Rec t2;
 Rec t1;
#define b ((Bss6D600 *)((u8 *)&b_ent0-0x140))
 if(g!=0 && g->unk_80!=0) {
 e1->unk_F=1;
 E1B->unk_0=g->unk_84 ? *(s8 *)g->unk_84 : 4;
 fn_1_7AA50(ro->unk_70);
 } else {
 e1->unk_F=0; E1B->unk_0=5; e1->unk_4=ro->unk_70; e1->unk_8=ro->unk_A8; e1->unk_C=0; e1->unk_D=0; e1->unk_E=0;
 }
 e0->unk_F=0; b->ent0.unk_0=5; e0->unk_4=ro->unk_70; e0->unk_8=ro->unk_A8; e0->unk_C=0; e0->unk_D=0; e0->unk_E=0;
 e=(Entry *)ro;
 while(e->unk_0!=-1) {
 if(e->unk_0==lbl_1_data_2A7E0.unk_0) { e0->unk_F=1; b->ent0.unk_0=e->unk_1; e0->unk_4=e->unk_4; e0->unk_8=e->unk_8; e0->unk_C=e->unk_C; e0->unk_D=e->unk_D; e0->unk_E=e->unk_E; }
 e++;
 }
 q[0]=SRC; (*((q) + (0))).unk_14=(u32)&SRC; (*((q) + (0))).unk_10=0x20; t4=(*((q) + (0))); r[0]=t4; s[0]=t4;
 q[1]=SRC; (*((q) + (1))).unk_14=(u32)&SRC; (*((q) + (1))).unk_10=0x20; t2=(*((q) + (1))); r[1]=t2; s[1]=t2;
 q[2]=SRC; (*((q) + (2))).unk_14=(u32)&SRC; (*((q) + (2))).unk_10=0x20; t1=(*((q) + (2))); r[2]=t1; s[2]=t1;
 q[3]=SRC; (*((q) + (3))).unk_14=(u32)&SRC; (*((q) + (3))).unk_10=0x20; t0=(*((q) + (3))); r[3]=t0; s[3]=t0;
 fn_1_7E8F4();
}
#pragma opt_propagation reset

