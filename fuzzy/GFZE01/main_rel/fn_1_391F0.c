/* Non-matching: best partial attempt (95.63% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/game.h"
struct Sig_fn_8004BD5C_fn_8004BD5C_Arg0 { u8 pad_0[0x71]; s8 unk_71; };
typedef struct Sig_ADXT_Pause_ADXTHandle Sig_ADXT_Pause_ADXTHandle;
extern s32 fn_8004BD5C(struct Sig_fn_8004BD5C_fn_8004BD5C_Arg0 *);
extern void ADXT_Pause(Sig_ADXT_Pause_ADXTHandle *, s32);
extern u8 lbl_1_bss_6F31A[138];
extern void *fn_1_435C(void *);
extern void fn_1_4310(u32);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_5370(s8, s32);
extern u32 fn_1_101C0(void);
extern void fn_1_3F4FC(void);
extern u32 fn_1_467F4(void);
extern int fn_1_EB200(void);
extern int fn_1_4C10(void);
struct fn_1_391F0_lbl_1_bss_3C00 {
 u8 pad_0[0x30]; struct { u8 pad_0[5]; u8 unk_5; u8 unk_6; } unk_30;
 u8 pad_37[0x14E8-0x37]; u16 unk_14E8;
 u8 pad_14EA[0x16]; void *unk_1500;
};
#define unk_35 unk_30.unk_5
#define unk_36 unk_30.unk_6
void fn_1_391F0(void) {
 struct fn_1_391F0_lbl_1_bss_3C00 *p_lbl_1_bss_3C00;
 u8 *v0;
 s32 v1;
 u32 v3;
 s32 v4;
 s32 v8;
 s32 v9;
 u16 v10;
 p_lbl_1_bss_3C00 = (struct fn_1_391F0_lbl_1_bss_3C00 *)&lbl_1_bss_3C00;
 v0 = (u8 *)p_lbl_1_bss_3C00 + 0x20000;
 if (lbl_1_bss_6F31A[0] != 0) v1 = 1;
 else v1 = fn_8004BD5C((struct Sig_fn_8004BD5C_fn_8004BD5C_Arg0 *)lbl_1_bss_6EAD0.unk_0->unk_0);
 if (v1 == 0 && (s8)lbl_1_bss_381F5 != 0) return;
 if ((s8)lbl_1_bss_381F5 != 0) {
 switch (p_lbl_1_bss_3C00->unk_36) {
 case 31: case 32: case 33: case 34: case 35: case 36: v3 = 1; break;
 default: v3 = 0; break;
 }
 ADXT_Pause((Sig_ADXT_Pause_ADXTHandle *)lbl_1_bss_6EAD0.unk_0->unk_0, 0);
 fn_1_435C(*(void **)(v0+0x1f88));
 fn_1_4310(0);
 fn_1_435C(*(void **)(v0+0x20a4));
 fn_1_4310(0);
 fn_1_4310(0x10020000);
 fn_1_435C(*(void **)(v0+0x1f88));
 fn_1_4310(707);
 lbl_1_bss_381F5 = 0;
 fn_1_4A00(1,142,p_lbl_1_bss_3C00->unk_1500);
 fn_1_5370(4,0);
 if ((v3 & 0xff) != 0) v4 = 350;
 else v4 = fn_1_101C0();
 *(s32 *)(v0+0x3028) = v4;
 if (p_lbl_1_bss_3C00->unk_35 != 1) fn_1_3F4FC();
 }
 --*(s32 *)(v0+0x3028);
 { u32 v6 = !fn_1_467F4();
 v8 = 0;
 if (v6 && fn_1_EB200() == 0) v8 = 1;
 }
 v9 = 0;
 if (v8 != 0 && fn_1_4C10() == 0) v9 = 1;
 if (v9 != 0) {
 v10 = *(u16 *)((u8 *)&lbl_1_bss_9F8.unk_8 + v0[0x2298]*20);
 if (((v10 >> 8)&1) != 0 || ((v10 >> 12)&1) != 0) {
 if (*(s32 *)(v0+0x3028) > 30) *(s32 *)(v0+0x3028) = 30;
 }
 }
 if (*(s32 *)(v0+0x3028) == 30) {
 fn_1_4A00(0,30,p_lbl_1_bss_3C00->unk_1500);
 lbl_1_bss_6EAB4.unk_0 |= 12;
 }
 if (*(s32 *)(v0+0x3028) == 0) p_lbl_1_bss_3C00->unk_14E8 = 40;
}
