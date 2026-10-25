/* Non-matching: best partial attempt (93.94% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_common.h"

extern s32 fn_1_106CAC(void);
extern s32 OSIsThreadTerminated(void *arg0);
extern u32 OSCreateThread(void *arg0, void *arg1, void *arg2, void *arg3, u32 arg4, u32 arg5, u32 arg6);
extern long OSResumeThread(void *arg0);

#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_branch off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_85280[2];
u32 lbl_1_bss_85288[2];
u32 fzgx_obj_lbl_1_bss_85290;
u32 lbl_1_bss_85294;
u32 lbl_1_bss_85298[136];
u32 lbl_1_bss_854B8__fzgx_offset_0[4];
u8 lbl_1_bss_854B8__fzgx_offset_10;
u8 lbl_1_bss_854B8__fzgx_offset_11;
u16 lbl_1_bss_854B8__fzgx_offset_12;
u32 lbl_1_bss_854B8__fzgx_offset_14[435];
u8 lbl_1_bss_854B8__fzgx_offset_6E0;
u8 lbl_1_bss_854B8__fzgx_offset_6E1;
u16 lbl_1_bss_854B8__fzgx_offset_6E2;
u32 lbl_1_bss_854B8__fzgx_offset_6E4[201];
u8 lbl_1_bss_854B8__fzgx_offset_A08;
u8 lbl_1_bss_854B8__fzgx_offset_A09;
u16 lbl_1_bss_854B8__fzgx_offset_A0A;
u32 lbl_1_bss_854B8__fzgx_offset_A0C[1023];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_85280;
    s = *(u8 *)&lbl_1_bss_85288;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_85290;
    s = *(u8 *)&lbl_1_bss_85294;
    s = *(u8 *)&lbl_1_bss_85298;
    s = *(u8 *)&lbl_1_bss_854B8__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_854B8__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_854B8__fzgx_offset_11;
    s = *(u8 *)&lbl_1_bss_854B8__fzgx_offset_12;
    s = *(u8 *)&lbl_1_bss_854B8__fzgx_offset_14;
    s = *(u8 *)&lbl_1_bss_854B8__fzgx_offset_6E0;
    s = *(u8 *)&lbl_1_bss_854B8__fzgx_offset_6E1;
    s = *(u8 *)&lbl_1_bss_854B8__fzgx_offset_6E2;
    s = *(u8 *)&lbl_1_bss_854B8__fzgx_offset_6E4;
    s = *(u8 *)&lbl_1_bss_854B8__fzgx_offset_A08;
    s = *(u8 *)&lbl_1_bss_854B8__fzgx_offset_A09;
    s = *(u8 *)&lbl_1_bss_854B8__fzgx_offset_A0A;
    s = *(u8 *)&lbl_1_bss_854B8__fzgx_offset_A0C;
}
#pragma section code_type ".text"

void fn_1_106D30(s32 lab_unused0, s32 lab_unused1) {
    

    if (OSIsThreadTerminated((void *)((u8 *)&lbl_1_bss_854B8__fzgx_offset_6E0))) {
        if (((2) != (*(s32 *)((u8 *)&lbl_1_bss_854B8__fzgx_offset_10)))) {
            return;
        }
        *(s32 *)((u8 *)&lbl_1_bss_854B8__fzgx_offset_10) = 0;
        OSCreateThread((void *)((u8 *)&lbl_1_bss_854B8__fzgx_offset_6E0), (void *)fn_1_106CAC, 0,
                       ((u8 *)&lbl_1_bss_854B8__fzgx_offset_A08) + 0x1000, 0x1000, 0x1E, 1);
        OSResumeThread((void *)((u8 *)&lbl_1_bss_854B8__fzgx_offset_6E0));
    }
}
