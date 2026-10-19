#include "types.h"

// Hardware or OS state can change asynchronously.
extern const char *const volatile lbl_800927BC;

u32 lbl_80190C78;
u8 *lbl_80190C7C;
int lbl_80190C80;
int lbl_80190C80__fzgx_offset_4;
int lbl_80190C88;
int lbl_80190C8C[32];
u8 lbl_80190C8C__fzgx_offset_80[0x103E];
u8 lbl_80191D4C[0xE80];

void fn_8005C120(void);
void *memset(void *dst, int c, u32 n);

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s; // fzgx-allow: S2 BSS primer ordering
    s = *(u8 *)&lbl_80190C78;
    s = *(u8 *)&lbl_80190C7C;
    s = *(u8 *)&lbl_80190C80;
    s = *(u8 *)&lbl_80190C80__fzgx_offset_4;
    s = *(u8 *)&lbl_80190C88;
    s = *(u8 *)&lbl_80190C8C;
    s = *(u8 *)&lbl_80190C8C__fzgx_offset_80;
    s = *(u8 *)&lbl_80191D4C;
}
#pragma section code_type ".text"

void fn_8005BDD4(void) {
    lbl_800927BC;
    if (lbl_80190C78 == 0) {
        fn_8005C120();
        memset(lbl_80191D4C, 0, sizeof(lbl_80191D4C));
        lbl_80190C7C = (u8 *)(((unsigned long)lbl_80190C8C__fzgx_offset_80 + 31) & ~31UL);
    }
    lbl_80190C78++;
}
