#include "types.h"

// Hardware or OS state can change asynchronously.
extern const char *const volatile lbl_800927BC;

u32 axrna_init_cnt;
u8 *lbl_80190C7C;
int lbl_80190C80;
int lbl_80190C80__fzgx_offset_4;
int axrna_update_pos;
int axrna_update_hist[32];
u8 lbl_80190C8C__fzgx_offset_80[0x103E];
u8 axrna_obj[0xE80];

void fn_8005C120(void);
void *memset(void *dst, int c, u32 n);

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s; // fzgx-allow: S2 BSS primer ordering
    s = *(u8 *)&axrna_init_cnt;
    s = *(u8 *)&lbl_80190C7C;
    s = *(u8 *)&lbl_80190C80;
    s = *(u8 *)&lbl_80190C80__fzgx_offset_4;
    s = *(u8 *)&axrna_update_pos;
    s = *(u8 *)&axrna_update_hist;
    s = *(u8 *)&lbl_80190C8C__fzgx_offset_80;
    s = *(u8 *)&axrna_obj;
}
#pragma section code_type ".text"

void AXRNA_Init(void) {
    lbl_800927BC;
    if (axrna_init_cnt == 0) {
        fn_8005C120();
        memset(axrna_obj, 0, sizeof(axrna_obj));
        lbl_80190C7C = (u8 *)(((unsigned long)lbl_80190C8C__fzgx_offset_80 + 31) & ~31UL);
    }
    axrna_init_cnt++;
}
