#include "types.h"


/* --- rel/movie_module/fn_12_3901C.c --- */
extern s32 fn_12_3A36C(void);
extern char lbl_12_rodata_2558[39];
extern void MWSFSVM_Error(const void *, ...);
extern void fn_12_3A888(void *);
extern s32 fn_12_2B358(void *);
extern void fn_12_38A0C(s32);
extern u8 lbl_12_rodata_2580[240];
extern void fn_12_3B540(void *);
extern void fn_12_34EB0(void *);
extern void fn_12_341E4(void *, s32);
extern void fn_80056CD0(void *);

typedef struct MovieModule {
    u8 pad0[0x8];
    void *field8;
    u8 padc[0x34];
    void *field40;
    void *field44;
    void *field48;
    void *field4c;
    u8 pad50[0x24];
    u32 field74;
    u8 pad78[0x174];
    u8 field1ec;
} MovieModule;

void fn_12_3901C(MovieModule *module) {
    void *movie;

    if (fn_12_3A36C() == 0) {
        MWSFSVM_Error(lbl_12_rodata_2558);
    } else {
        movie = module->field40;
        if (movie != 0) {
            fn_12_3A888(module);
            module->field8 = 0;
            if (fn_12_2B358(movie) != 0) {
                fn_12_38A0C(-0x134);
                MWSFSVM_Error(lbl_12_rodata_2580);
            }
            fn_12_3B540(&module->field1ec);
            movie = module->field44;
            if (movie != 0) {
                fn_12_34EB0(movie);
            }
        }
        fn_12_341E4(module, 0);
        module->field74 = 0;
        fn_80056CD0(module->field4c);
    }
}

/* --- rel/movie_module/fn_12_390E4.c --- */
typedef struct MovieModule_u1 {
    u8 pad0[0x8];
    void *field8;
    u8 padc[0x34];
    void *field40;
    void *field44;
    u8 pad48[0x1a4];
    u8 field1ec;
} MovieModule_u1;

void fn_12_390E4(MovieModule_u1 *module) {
    void *movie;

    movie = module->field40;
    if (movie != 0) {
        fn_12_3A888(module);
        module->field8 = 0;
        if (fn_12_2B358(movie) != 0) {
            fn_12_38A0C(-0x134);
            MWSFSVM_Error(lbl_12_rodata_2580);
        }
        fn_12_3B540(&module->field1ec);
        movie = module->field44;
        if (movie != 0) {
            fn_12_34EB0(movie);
        }
    }
}
