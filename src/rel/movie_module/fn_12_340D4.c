#include "types.h"


/* --- rel/movie_module/fn_12_340D4.c --- */
typedef struct MovieModule {
    u8 pad_00[0x54];
    void *field_54;
} MovieModule;

extern int fn_12_3A36C(MovieModule *, void *);
extern char lbl_12_rodata_12B0[46];
extern void MWSFSVM_Error(char *, ...);

void fn_12_340D4(MovieModule *self, void *value) {
    if (fn_12_3A36C(self, value) == 0) {
        MWSFSVM_Error(lbl_12_rodata_12B0);
    } else {
        self->field_54 = value;
    }
}

/* --- rel/movie_module/fn_12_3412C.c --- */
extern void fn_12_21AE4(void *);

typedef struct MovieModule_u1 {
    u8 pad_00[0x40];
    void *field_40;
} MovieModule_u1;

void fn_12_3412C(MovieModule_u1 *self) {
    fn_12_21AE4(self->field_40);
}

/* --- rel/movie_module/fn_12_34150.c --- */
typedef struct MovieModule_u2 {
    u8 pad[0x40];
    void *movie;
} MovieModule_u2;

extern void fn_12_21B70(void *movie);

void fn_12_34150(MovieModule_u2 *module) {
    fn_12_21B70(module->movie);
}
