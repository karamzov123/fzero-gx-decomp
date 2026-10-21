#include "types.h"

typedef struct MovieInner {
    u32 unk0;
    u32 unk4;
    u32 pad8[3];
    u32 unk14;
} MovieInner;

typedef struct MovieBss {
    s32 count;
    u32 unk4;
    MovieInner inner;
    u8 pad[0x4a8 - sizeof(MovieInner)];
    const void *unk4B0;
} MovieBss;

extern u8 lbl_12_rodata_448[160];
extern void fn_12_3D624(MovieInner *);
extern void fn_12_4A18(void);
extern void fn_12_4938(void);
extern void fn_12_35F0(void);
extern void *memset(void *, int, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s32 lbl_12_bss_8;
u32 lbl_12_bss_C;
MovieInner lbl_12_bss_10;
u32 lbl_12_bss_10_fill_28[292];
const void *lbl_12_bss_10_4A8;
u32 lbl_12_bss_10_fill_4BC;
u32 lbl_12_bss_4C0[42];
u32 lbl_12_bss_568[140];
u32 lbl_12_bss_798[258];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_12_bss_8;
    s = *(u8 *)&lbl_12_bss_C;
    s = *(u8 *)&lbl_12_bss_10;
    s = *(u8 *)&lbl_12_bss_10_fill_28;
    s = *(u8 *)&lbl_12_bss_10_4A8;
    s = *(u8 *)&lbl_12_bss_10_fill_4BC;
    s = *(u8 *)&lbl_12_bss_4C0;
    s = *(u8 *)&lbl_12_bss_568;
    s = *(u8 *)&lbl_12_bss_798;
}
#pragma section code_type ".text"

void fn_12_341C(void) {
    
    if (lbl_12_bss_8 < 1) {
        lbl_12_bss_10_4A8 = lbl_12_rodata_448;
        memset(&lbl_12_bss_10, 0, 0x4a8);
        lbl_12_bss_10.unk4 = 8;
        lbl_12_bss_10.unk14 = 1;
        fn_12_3D624(&lbl_12_bss_10);
        fn_12_4A18();
        fn_12_4938();
        fn_12_35F0();
        lbl_12_bss_C = 0;
        lbl_12_bss_8++;
    }
}
