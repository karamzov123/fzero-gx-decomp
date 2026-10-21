#include "types.h"

typedef struct {
    u8 pad[0x3c];
    u32 f3c;
    u32 f40;
    u32 f44;
} Obj_80091198;
extern u8 lbl_80091198__fzgx_offset_0[];
static const u32 fzgx_pool_rodata_lbl_80091198[15] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xA414458, 0x47435344, 0x4B205665, 0x722E3035, 0x53657032, 0x30303250, 0x61746368, 0x32204275,
    0x696C643A, 0x4D617920, 0x20392032, 0x30303320, 0x31373A31, 0x313A3138, 0xA000000
};
static const u32 fzgx_pool_rodata_lbl_80091198_3C[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_80091198__fzgx_offset_0
};
static const u32 fzgx_pool_rodata_lbl_80091198_40[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4D465300
};
static const u32 fzgx_pool_rodata_lbl_80091198_44[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x47434400
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_80091198(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_80091198;
    s = *(u8 *)fzgx_pool_rodata_lbl_80091198_3C;
    s = *(u8 *)fzgx_pool_rodata_lbl_80091198_40;
    s = *(u8 *)fzgx_pool_rodata_lbl_80091198_44;
}
#pragma section code_type ".text"


extern void fn_8004ECF4(u32, u32);
extern void fn_8005466C(void (*)(u32, u32), u32);
extern u8 *fn_8005A5A8(void);
extern u32 fn_80056584(void);
extern void fn_80055304(u32 *, void *, u32);
extern void fn_800551D0(u32 *);
extern void fn_800565F0(u32, u32, u32, u32);

void fn_8004EC34(u32 *p) {
    

    /* retail keeps this dead load of f3c (lwz r0, 0x3c): a volatile read reproduces it */
    *(volatile u32 *)&(*(u32 *)(((u8 *)fzgx_pool_rodata_lbl_80091198_3C)));
    fn_8005466C(fn_8004ECF4, 0);
    fn_80055304(&(*(u32 *)(((u8 *)fzgx_pool_rodata_lbl_80091198_40))), fn_8005A5A8, 0);
    fn_8005466C(fn_8004ECF4, 0);
    fn_80055304(&(*(u32 *)(((u8 *)fzgx_pool_rodata_lbl_80091198_44))), fn_80056584, 0);
    fn_800551D0(&(*(u32 *)(((u8 *)fzgx_pool_rodata_lbl_80091198_44))));
    if (p) {
        fn_800565F0(0, 0, 0, *p);
    } else {
        fn_800565F0(0, 0, 0, 0);
    }
}
