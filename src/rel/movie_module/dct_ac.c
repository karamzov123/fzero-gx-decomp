#include "types.h"
#include "sofdec/sfx.h"
extern f64 lbl_12_bss_798[8][8];
extern void fn_12_4A38(f64 *arg0, f64 *arg1, f64 (*table)[8]);
extern f64 fn_80087E80(f64 value);
extern const char *fn_12_4E14(void);
extern const double lbl_12_rodata_598;
extern const double lbl_12_rodata_5A8;
extern const double lbl_12_rodata_5B0;

/* fzgx:begin fn_12_4A38 */
/* --- rel/movie_module/fn_12_4A38.c --- */
void fn_12_4A38(f64 *arg0, f64 *arg1, f64 (*arg2)[8]) {
    f64 tmp[64];
    s32 i;
    s32 j;
    s32 k;
    f64 s;

    {
    s32 fzgx_loop_i_142;
for (fzgx_loop_i_142 = 0; fzgx_loop_i_142 < 8; fzgx_loop_i_142++) {
        for (j = 0; j < 8; j++) {
            s = 0.0;
            for (k = 0; k < 8; k++) {
                s += arg2[k][j] * arg0[fzgx_loop_i_142 * 8 + k];
            }
            tmp[fzgx_loop_i_142 * 8 + j] = s;
        }
    }
    i = fzgx_loop_i_142;
}

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            s = 0.0;
            for (k = 0; k < 8; k++) {
                s += arg2[k][j] * tmp[i + k * 8];
            }
            arg1[j * 8 + i] = s;
        }
    }
}
/* fzgx:end fn_12_4A38 */

/* fzgx:begin fn_12_4CEC */

void fn_12_4CEC(void *arg0, void *arg1) {
    fn_12_4A38(arg0, arg1, lbl_12_bss_798);
}
/* fzgx:end fn_12_4CEC */

/* fzgx:begin fn_12_4D14 */
/* DCT_AcInit, from the CC0 MK Deception decomp (dct_ac.c) */

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
/* fzgx:end fn_12_4D14 */
