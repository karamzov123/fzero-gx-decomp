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

/* --- rel/movie_module/fn_12_34C44.c --- */
extern void fn_80058A40(void);

void fn_12_34C44(void) {
    fn_80058A40();
}

/* --- rel/movie_module/fn_12_34C64.c --- */
extern void fn_800596D4(void);

void fn_12_34C64(void) {
    fn_800596D4();
}

/* --- rel/movie_module/fn_12_34C84.c --- */
extern void fn_80059914(void);

int fn_12_34C84(void) {
    fn_80059914();
    return 1;
}

/* --- rel/movie_module/fn_12_34CA8.c --- */
extern void fn_800597F4(void);

void fn_12_34CA8(void) {
    fn_800597F4();
}

/* --- rel/movie_module/fn_12_34CC8.c --- */
extern void fn_800599E4(void);

int fn_12_34CC8(void) {
    fn_800599E4();
    return 1;
}

/* --- rel/movie_module/fn_12_34CEC.c --- */
extern struct fn_12_34CEC_lbl_12_bss_1B9A0 lbl_12_bss_1B9A0;
extern u32 fn_800592E0(u32, u32);

struct fn_12_34CEC_lbl_12_bss_1B9A0 {
    u32 unk_0;
};

void fn_12_34CEC(void) {
    fn_800592E0(5, lbl_12_bss_1B9A0.unk_0);
}
