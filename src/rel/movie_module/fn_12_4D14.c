#include "types.h"

/* DCT_AcInit, from the CC0 MK Deception decomp (dct_ac.c) */

extern double fn_80087E80(double);
extern const char *fn_12_4E14(void);
extern const double lbl_12_rodata_598;
extern const double lbl_12_rodata_5A8;
extern const double lbl_12_rodata_5B0;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
double lbl_12_bss_798[8][8];
double lbl_12_bss_798__fzgx_offset_200[8][8];
const char *lbl_12_bss_798__fzgx_offset_400;

#define dctac_i_const lbl_12_bss_798
#define dctac_f_const lbl_12_bss_798__fzgx_offset_200
#define dctac_version_dummy lbl_12_bss_798__fzgx_offset_400

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s; /* fzgx-allow: S2 BSS primer ordering */
    s = *(u8 *)&lbl_12_bss_798;
    s = *(u8 *)&lbl_12_bss_798__fzgx_offset_200;
    s = *(u8 *)&lbl_12_bss_798__fzgx_offset_400;
}
#pragma section code_type ".text"

static inline double dctac_Cos(double angle, int column) {
    return fn_80087E80(angle * (lbl_12_rodata_598 + (double)column));
}

void fn_12_4D14(void) {
    double* inverse_element;
    double* forward_element;
    double* inverse_row;
    double* forward_column;
    int row;
    int column;
    double scale;
    double angle;

    dctac_version_dummy = fn_12_4E14();
    inverse_row = &dctac_i_const[0][0];
    forward_column = &dctac_f_const[0][0];
    for (row = 0; row < 8; row++, inverse_row += 8, forward_column++) {
        if (row == 0) {
            scale = lbl_12_rodata_5A8;
        } else {
            scale = lbl_12_rodata_598;
        }
        angle = lbl_12_rodata_5B0 * row;
        inverse_element = inverse_row;
        forward_element = forward_column;
        for (column = 0; column < 8;
             column++, inverse_element++, forward_element += 8) {
            double value = scale * dctac_Cos(angle, column);
            *inverse_element = value;
            *forward_element = value;
        }
    }
}

