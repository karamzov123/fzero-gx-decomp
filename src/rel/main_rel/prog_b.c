#include "types.h"

/* The perspective of the 3D view. */
typedef struct {
    f32 fovy;
    f32 aspect;
    f32 near;
    f32 far;
    f32 tan;
    f32 invTan;
} Perspective;

extern s8 fn_1_A5DC4(void);
extern f32 lbl_8006D21C(s32 angle);
extern void fn_800721FC(f32 fovy, f32 aspect, f32 near, f32 far);
extern void fn_80072344(void);
extern void fn_80072378(void);

Perspective lbl_1_bss_6F608;
Perspective lbl_1_bss_6F620;

/* fzgx:begin fn_1_A6FE8 */
f32 fn_1_A6FE8(void) {
    if (fn_1_A5DC4()) {
        return 1.7777778f;
    }
    return 1.3333334f;
}
/* fzgx:end fn_1_A6FE8 */

/* fzgx:begin fn_1_A7024 */
void fn_1_A7024(f32 fovy, f32 aspect, f32 near, f32 far) {
    f32 bits;

    fovy = fovy < 0.5 ? 0.5 : (fovy > 135.0 ? 135.0 : fovy);
    bits = fovy;
    if (((*(u32 *)&bits & 0x7F800000) - 0x7F800000) == 0) {
        fovy = 55.0f;
    }
    fn_800721FC(fovy, aspect, near, far);
    lbl_1_bss_6F608.fovy = fovy;
    lbl_1_bss_6F608.near = near;
    lbl_1_bss_6F608.far = far;
    lbl_1_bss_6F608.aspect = aspect;
    lbl_1_bss_6F608.tan = lbl_8006D21C((182.04444885253906 * (0.5 * fovy)));
    lbl_1_bss_6F608.invTan = 1.0 / lbl_1_bss_6F608.tan;
}
/* fzgx:end fn_1_A7024 */

/* fzgx:begin fn_1_A714C */
void fn_1_A714C(f32 *fovy, f32 *aspect, f32 *near, f32 *far) {
    if (fovy != NULL) {
        *fovy = lbl_1_bss_6F608.fovy;
    }
    if (aspect != NULL) {
        *aspect = lbl_1_bss_6F608.aspect;
    }
    if (near != NULL) {
        *near = lbl_1_bss_6F608.near;
    }
    if (far != NULL) {
        *far = lbl_1_bss_6F608.far;
    }
}
/* fzgx:end fn_1_A714C */

/* fzgx:begin fn_1_A71AC */
f32 fn_1_A71AC(void) {
    return lbl_1_bss_6F608.tan;
}
/* fzgx:end fn_1_A71AC */

/* fzgx:begin fn_1_A71BC */
f32 fn_1_A71BC(void) {
    return lbl_1_bss_6F608.invTan;
}
/* fzgx:end fn_1_A71BC */

/* fzgx:begin fn_1_A71CC */
void fn_1_A71CC(void) {
    fn_80072344();
    lbl_1_bss_6F620 = lbl_1_bss_6F608;
}
/* fzgx:end fn_1_A71CC */

/* fzgx:begin fn_1_A722C */
void fn_1_A722C(void) {
    fn_80072378();
    lbl_1_bss_6F608 = lbl_1_bss_6F620;
}
/* fzgx:end fn_1_A722C */

/* fzgx:begin fn_1_A728C */
// fn_1_A728C: returns a constant.
int fn_1_A728C(void) {
    return 0;
}
/* fzgx:end fn_1_A728C */
