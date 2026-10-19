#include "types.h"

u32 lbl_801878B8[3];
void *lbl_801878C4;
void *lbl_801878C8;
u8 lbl_801878CC[0xFA0];
// Hardware or OS state can change asynchronously.
const char *volatile lbl_801878CC__fzgx_offset_FA0;

extern char lbl_80188870[256];
extern u32 lbl_80132260[];
void *memset(void *dst, int c, u32 n);

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s; // fzgx-allow: S2 BSS primer ordering
    s = *(u8 *)&lbl_801878B8;
    s = *(u8 *)&lbl_801878C4;
    s = *(u8 *)&lbl_801878C8;
    s = *(u8 *)&lbl_801878CC;
    s = *(u8 *)&lbl_801878CC__fzgx_offset_FA0;
}
#pragma section code_type ".text"

void *fn_80056584(void) {
    lbl_801878CC__fzgx_offset_FA0 = lbl_801878CC__fzgx_offset_FA0;
    memset(lbl_80188870, 0, sizeof(lbl_80188870));
    lbl_801878C8 = 0;
    lbl_801878C4 = 0;
    memset(lbl_801878B8, 0, sizeof(lbl_801878B8));
    return &lbl_80132260;
}
