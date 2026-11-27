#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/objput.h"

extern u32 lbl_1_bss_6C79C;
extern void fn_80037D40(u8);

extern void *lbl_801A6410;
extern void fn_1_45D0(void *, void *, char *, int);
extern void fn_1_46B4(void *, void *, char *, int);

/* fzgx:begin fn_1_56664 */
// Register the object-put callback using the shared object table and command ID.
void fn_1_56664(void *arg) {
    fn_1_45D0(lbl_801A6410, arg, lbl_1_data_1C650, 0x4f9);
}
/* fzgx:end fn_1_56664 */

/* fzgx:begin fn_1_566A0 */
// Register the object with its data label and resource identifier.
void fn_1_566A0(void *arg) {
    fn_1_46B4(lbl_801A6410, arg, lbl_1_data_1C650, 0x501);
}
/* fzgx:end fn_1_566A0 */

/* fzgx:begin fn_1_566DC */
u32 fn_1_566DC(void) {
    return lbl_1_bss_6C79C;
}
/* fzgx:end fn_1_566DC */

/* fzgx:begin fn_1_566EC */
void fn_1_566EC(int arg0, int arg1) {
    lbl_1_bss_6C7A4.unk_10 = arg0;
    lbl_1_bss_6C7A4.unk_11 = arg1;
    fn_80037D40(arg0);
}
/* fzgx:end fn_1_566EC */

/* fzgx:begin fn_1_56724 */
// fn_1_56724: returns a constant.
int fn_1_56724(void) {
    return 1;
}
/* fzgx:end fn_1_56724 */
