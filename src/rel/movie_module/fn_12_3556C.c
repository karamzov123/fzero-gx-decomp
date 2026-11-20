#include "types.h"


/* --- rel/movie_module/fn_12_3556C.c --- */
typedef struct MovieModuleState {
    u8 pad_a8[0xa8];
    void *movie;
} MovieModuleState;

extern s32 fn_12_3A36C(MovieModuleState *self);
extern char lbl_12_rodata_18CC[51];
extern void MWSFSVM_Error(const char *format, ...);
extern void fn_12_8B4(void *movie, void *arg1, void *arg2);

void fn_12_3556C(MovieModuleState *self, void *arg1, void *arg2) {
    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(lbl_12_rodata_18CC);
    } else {
        fn_12_8B4(self->movie, arg1, arg2);
    }
}

/* --- rel/movie_module/fn_12_355DC.c --- */
extern char lbl_12_rodata_1900[51];
extern void MWSFSVM_Error(const char *message, ...);
extern void fn_12_8C8(void *movie, void *arg1, void *arg2);

void fn_12_355DC(MovieModuleState *self, void *arg1, void *arg2) {
    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(lbl_12_rodata_1900);
    } else {
        fn_12_8C8(self->movie, arg1, arg2);
    }
}

/* --- rel/movie_module/fn_12_3564C.c --- */
extern void fn_12_750(void *movie);

void fn_12_3564C(MovieModuleState *self) {
    fn_12_750(self->movie);
}

/* --- rel/movie_module/fn_12_35670.c --- */
void fn_12_35670(MovieModuleState *self) {
    fn_12_750(self->movie);
}
