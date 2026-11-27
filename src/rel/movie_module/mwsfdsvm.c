#include "types.h"
#include "runtime/va_list.h"

/* fzgx:begin fn_12_34B64 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_34B64.c --- */
extern void fn_80058FE4(int);

void fn_12_34B64(void) {
    fn_80058FE4(6);
}
/* fzgx:end fn_12_34B64 */

/* fzgx:begin MWSFSVM_Error noprologue */
#include "types.h"
#include "runtime/va_list.h"


/* --- rel/movie_module/MWSFSVM_Error.c --- */
void* memset(void* destination, int value, size_t size);

void fn_800595A4(const char *message);

int fn_8008077C(char *output, const char *format, __va_list args);

extern char lbl_12_bss_1B8A0[256];

void MWSFSVM_Error(const char *format, ...) {
    __va_list arguments;
    memset(lbl_12_bss_1B8A0, 0, sizeof(lbl_12_bss_1B8A0));
    ((void)(format), __builtin_va_info(&(arguments)));
    fn_8008077C(lbl_12_bss_1B8A0, format, arguments);
    fn_800595A4(lbl_12_bss_1B8A0);
    ((void)0);
}
/* fzgx:end MWSFSVM_Error */

/* fzgx:begin fn_12_34C44 noprologue */

/* --- rel/movie_module/fn_12_34C44.c --- */
extern void fn_80058A40(void);

void fn_12_34C44(void) {
    fn_80058A40();
}
/* fzgx:end fn_12_34C44 */

/* fzgx:begin fn_12_34C64 noprologue */

/* --- rel/movie_module/fn_12_34C64.c --- */
extern void fn_800596D4(void);

void fn_12_34C64(void) {
    fn_800596D4();
}
/* fzgx:end fn_12_34C64 */

/* fzgx:begin fn_12_34C84 noprologue */

/* --- rel/movie_module/fn_12_34C84.c --- */
extern void fn_80059914(void);

int fn_12_34C84(void) {
    fn_80059914();
    return 1;
}
/* fzgx:end fn_12_34C84 */

/* fzgx:begin fn_12_34CA8 noprologue */

/* --- rel/movie_module/fn_12_34CA8.c --- */
extern void fn_800597F4(void);

void fn_12_34CA8(void) {
    fn_800597F4();
}
/* fzgx:end fn_12_34CA8 */

/* fzgx:begin fn_12_34CC8 noprologue */

/* --- rel/movie_module/fn_12_34CC8.c --- */
extern void fn_800599E4(void);

int fn_12_34CC8(void) {
    fn_800599E4();
    return 1;
}
/* fzgx:end fn_12_34CC8 */

/* fzgx:begin fn_12_34CEC noprologue */

/* --- rel/movie_module/fn_12_34CEC.c --- */
extern struct fn_12_34CEC_lbl_12_bss_1B9A0 lbl_12_bss_1B9A0;
extern u32 fn_800592E0(u32, u32);

struct fn_12_34CEC_lbl_12_bss_1B9A0 {
    u32 unk_0;
};

void fn_12_34CEC(void) {
    fn_800592E0(5, lbl_12_bss_1B9A0.unk_0);
}
/* fzgx:end fn_12_34CEC */

/* fzgx:begin fn_12_34D1C noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_34D1C.c --- */
extern u32 lbl_12_bss_1B9A0;
extern u32 fn_80059428(u32, u32, u32);

void fn_12_34D1C(u32 arg0, u32 arg1) {
    lbl_12_bss_1B9A0 = fn_80059428(5, arg0, arg1);
}
/* fzgx:end fn_12_34D1C */

/* fzgx:begin fn_12_34D50 noprologue */

/* --- rel/movie_module/fn_12_34D50.c --- */
extern struct fn_12_34D50_lbl_12_bss_1B9A4 lbl_12_bss_1B9A4;
extern u32 fn_800592E0(u32, u32);

struct fn_12_34D50_lbl_12_bss_1B9A4 {
    u32 unk_0;
};

void fn_12_34D50(void) {
    fn_800592E0(6, lbl_12_bss_1B9A4.unk_0);
}
/* fzgx:end fn_12_34D50 */

/* fzgx:begin fn_12_34D80 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_34D80.c --- */
extern u32 lbl_12_bss_1B9A4;
extern u32 fn_80059428(u32, u32, u32);

void fn_12_34D80(u32 arg0, u32 arg1) {
    lbl_12_bss_1B9A4 = fn_80059428(6, arg0, arg1);
}
/* fzgx:end fn_12_34D80 */

/* fzgx:begin fn_12_34DB4 noprologue */

/* --- rel/movie_module/fn_12_34DB4.c --- */
extern struct fn_12_34DB4_lbl_12_bss_1B9A8 lbl_12_bss_1B9A8;
extern u32 fn_800592E0(u32, u32);

struct fn_12_34DB4_lbl_12_bss_1B9A8 {
    u32 unk_0;
};

void fn_12_34DB4(void) {
    fn_800592E0(2, lbl_12_bss_1B9A8.unk_0);
}
/* fzgx:end fn_12_34DB4 */

/* fzgx:begin fn_12_34DE4 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_34DE4.c --- */
/* --- rel/movie_module/fn_12_34DE4.c --- */
extern void fn_8005912C(u32, void *, void *, void *);
extern u32 lbl_12_bss_1B9A8[2];

void fn_12_34DE4(void *arg0, void *arg1, void *arg2) {
    fn_8005912C(2, arg0, arg1, arg2);
    lbl_12_bss_1B9A8[0] = (u32)arg0;
}
/* fzgx:end fn_12_34DE4 */

/* fzgx:begin fn_12_34E2C noprologue */

/* --- rel/movie_module/fn_12_34E2C.c --- */
extern void fn_80058B54(void);

void fn_12_34E2C(void) {
    fn_80058B54();
}
/* fzgx:end fn_12_34E2C */

/* fzgx:begin fn_12_34E4C noprologue */

/* --- rel/movie_module/fn_12_34E4C.c --- */
extern struct fn_12_34E4C_lbl_12_bss_1B8A0 lbl_12_bss_1B8A0;
extern u32 fn_80058BFC(void);

struct fn_12_34E4C_lbl_12_bss_1B8A0 {
    u8 pad_0[0x100];
    u32 unk_100;
    u32 unk_104;
    u32 unk_108;
    u32 unk_10C;
};

void fn_12_34E4C(void) {
    struct fn_12_34E4C_lbl_12_bss_1B8A0 *p_lbl_12_bss_1B8A0;
    p_lbl_12_bss_1B8A0 = (struct fn_12_34E4C_lbl_12_bss_1B8A0 *)&lbl_12_bss_1B8A0;
    fn_80058BFC();
    p_lbl_12_bss_1B8A0->unk_10C = 0;
    p_lbl_12_bss_1B8A0->unk_108 = 0;
    p_lbl_12_bss_1B8A0->unk_104 = 0;
    p_lbl_12_bss_1B8A0->unk_100 = 0;
}
/* fzgx:end fn_12_34E4C */
