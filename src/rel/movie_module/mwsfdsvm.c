#include "types.h"
#include "runtime/va_list.h"

struct fn_12_34E4C_lbl_12_bss_1B8A0 {
    u8 pad_0[0x100];
    u32 unk_100;
    u32 unk_104;
    u32 unk_108;
    u32 unk_10C;
};

struct fn_12_34CEC_lbl_12_bss_1B9A0 {
    u32 unk_0;
};

struct fn_12_34D50_lbl_12_bss_1B9A4 {
    u32 unk_0;
};

struct fn_12_34DB4_lbl_12_bss_1B9A8 {
    u32 unk_0;
};
extern void fn_80058FE4(int idx);
void* memset(void* destination, int value, size_t size);
extern void fn_800595A4(const char *msg);
extern char lbl_12_bss_1B8A0[256];
extern unsigned int fn_80058A40();
extern void fn_800596D4(void);
extern void fn_80059914(void);
extern void fn_800597F4(void);
extern void fn_800599E4(void);
extern u32 lbl_12_bss_1B9A0;
extern void fn_800592E0(int server_type, int id);
extern u32 fn_80059428(u32, u32, u32);
extern u32 lbl_12_bss_1B9A4;
extern u32 lbl_12_bss_1B9A8[2];
extern void fn_8005912C(u32, void *, void *, void *);
extern void fn_80058B54(void);
extern void fn_80058BFC(void);

/* fzgx:begin fn_12_34B64 */
/* --- rel/movie_module/fn_12_34B64.c --- */

void fn_12_34B64(void) {
    fn_80058FE4(6);
}
/* fzgx:end fn_12_34B64 */

/* fzgx:begin MWSFSVM_Error */
/* --- rel/movie_module/MWSFSVM_Error.c --- */


int fn_8008077C(char *output, const char *format, __va_list args);


void MWSFSVM_Error(const char *format, ...) {
    __va_list arguments;
    memset(lbl_12_bss_1B8A0, 0, sizeof(lbl_12_bss_1B8A0));
    ((void)(format), __builtin_va_info(&(arguments)));
    fn_8008077C(lbl_12_bss_1B8A0, format, arguments);
    fn_800595A4(lbl_12_bss_1B8A0);
    ((void)0);
}
/* fzgx:end MWSFSVM_Error */

/* fzgx:begin fn_12_34C44 */
/* --- rel/movie_module/fn_12_34C44.c --- */

void fn_12_34C44(void) {
    fn_80058A40();
}
/* fzgx:end fn_12_34C44 */

/* fzgx:begin fn_12_34C64 */
/* --- rel/movie_module/fn_12_34C64.c --- */

void fn_12_34C64(void) {
    fn_800596D4();
}
/* fzgx:end fn_12_34C64 */

/* fzgx:begin fn_12_34C84 */
/* --- rel/movie_module/fn_12_34C84.c --- */

int fn_12_34C84(void) {
    fn_80059914();
    return 1;
}
/* fzgx:end fn_12_34C84 */

/* fzgx:begin fn_12_34CA8 */
/* --- rel/movie_module/fn_12_34CA8.c --- */

void fn_12_34CA8(void) {
    fn_800597F4();
}
/* fzgx:end fn_12_34CA8 */

/* fzgx:begin fn_12_34CC8 */
/* --- rel/movie_module/fn_12_34CC8.c --- */

int fn_12_34CC8(void) {
    fn_800599E4();
    return 1;
}
/* fzgx:end fn_12_34CC8 */

/* fzgx:begin fn_12_34CEC */
/* --- rel/movie_module/fn_12_34CEC.c --- */


void fn_12_34CEC(void) {
    fn_800592E0(5, (*((struct fn_12_34CEC_lbl_12_bss_1B9A0 *)&lbl_12_bss_1B9A0)).unk_0);
}
/* fzgx:end fn_12_34CEC */

/* fzgx:begin fn_12_34D1C */
/* --- rel/movie_module/fn_12_34D1C.c --- */

void fn_12_34D1C(u32 arg0, u32 arg1) {
    lbl_12_bss_1B9A0 = fn_80059428(5, arg0, arg1);
}
/* fzgx:end fn_12_34D1C */

/* fzgx:begin fn_12_34D50 */
/* --- rel/movie_module/fn_12_34D50.c --- */


void fn_12_34D50(void) {
    fn_800592E0(6, (*((struct fn_12_34D50_lbl_12_bss_1B9A4 *)&lbl_12_bss_1B9A4)).unk_0);
}
/* fzgx:end fn_12_34D50 */

/* fzgx:begin fn_12_34D80 */
/* --- rel/movie_module/fn_12_34D80.c --- */

void fn_12_34D80(u32 arg0, u32 arg1) {
    lbl_12_bss_1B9A4 = fn_80059428(6, arg0, arg1);
}
/* fzgx:end fn_12_34D80 */

/* fzgx:begin fn_12_34DB4 */
/* --- rel/movie_module/fn_12_34DB4.c --- */


void fn_12_34DB4(void) {
    fn_800592E0(2, (*((struct fn_12_34DB4_lbl_12_bss_1B9A8 *)&lbl_12_bss_1B9A8)).unk_0);
}
/* fzgx:end fn_12_34DB4 */

/* fzgx:begin fn_12_34DE4 */
/* --- rel/movie_module/fn_12_34DE4.c --- */
/* --- rel/movie_module/fn_12_34DE4.c --- */

void fn_12_34DE4(void *arg0, void *arg1, void *arg2) {
    fn_8005912C(2, arg0, arg1, arg2);
    lbl_12_bss_1B9A8[0] = (u32)arg0;
}
/* fzgx:end fn_12_34DE4 */

/* fzgx:begin fn_12_34E2C */
/* --- rel/movie_module/fn_12_34E2C.c --- */

void fn_12_34E2C(void) {
    fn_80058B54();
}
/* fzgx:end fn_12_34E2C */

/* fzgx:begin fn_12_34E4C */
/* --- rel/movie_module/fn_12_34E4C.c --- */


void fn_12_34E4C(void) {
    struct fn_12_34E4C_lbl_12_bss_1B8A0 *p_lbl_12_bss_1B8A0;
    p_lbl_12_bss_1B8A0 = (struct fn_12_34E4C_lbl_12_bss_1B8A0 *)&(*((struct fn_12_34E4C_lbl_12_bss_1B8A0 *)&lbl_12_bss_1B8A0));
    fn_80058BFC();
    p_lbl_12_bss_1B8A0->unk_10C = 0;
    p_lbl_12_bss_1B8A0->unk_108 = 0;
    p_lbl_12_bss_1B8A0->unk_104 = 0;
    p_lbl_12_bss_1B8A0->unk_100 = 0;
}
/* fzgx:end fn_12_34E4C */
