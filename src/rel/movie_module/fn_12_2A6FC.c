#include "types.h"

typedef struct MovieParams {
    u32 field0;
    u32 field1;
    u32 field2;
    u32 field3;
    u32 field4;
    u32 field5;
    u32 field6;
    s32 field7;
    u32 field8;
} MovieParams;

typedef struct MovieSize {
    u32 width;
    u32 height;
} MovieSize;


/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_12_bss_96A0;
u32 lbl_12_bss_96A0__fzgx_offset_4[16];
MovieSize lbl_12_bss_96A0__fzgx_offset_44;
MovieParams lbl_12_bss_96A0__fzgx_offset_4C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_12_bss_96A0;
    s = *(u8 *)&lbl_12_bss_96A0__fzgx_offset_4;
    s = *(u8 *)&lbl_12_bss_96A0__fzgx_offset_44;
    s = *(u8 *)&lbl_12_bss_96A0__fzgx_offset_4C;
}
#pragma section code_type ".text"

void fn_12_2A6FC(MovieParams *arg0, MovieSize *arg1, u32 *arg2) {
    MovieParams *params = &lbl_12_bss_96A0__fzgx_offset_4C;
    MovieSize *size = &lbl_12_bss_96A0__fzgx_offset_44;
    u32 *dst = lbl_12_bss_96A0__fzgx_offset_4;
    u32 *src = arg2;
    s32 i;

    lbl_12_bss_96A0__fzgx_offset_4C = *arg0;
    params->field4 = 0;
    params->field8 = 0;
    lbl_12_bss_96A0__fzgx_offset_44.width = (arg1->width + 31) & ~31;
    size->height = (arg1->height + 31) & ~31;

    for (i = 0; i < 16; i++) {
        if (i < arg0->field7) {
            dst[0] = (src[0] + 31) & ~31;
        } else {
            dst[0] = 0;
        }
        src++;
        dst++;
    }
}
