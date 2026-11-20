#include "types.h"


/* --- rel/movie_module/fn_12_2B2E4.c --- */
struct MovieModule {
    char pad_44[0x44];
    int value;
    char pad_1ab4[0x1a6c];
    int field_1ab4;
};

extern int fn_12_24990(struct MovieModule *module);
extern int fn_12_24A88(int arg0, u32 arg1);
extern void fn_12_21D40(struct MovieModule *module, int value, int arg2);

int fn_12_2B2E4(struct MovieModule *module) {
    if (fn_12_24990(module)) {
        return fn_12_24A88(0, 0xff000135);
    } else {
        fn_12_21D40(module, module->field_1ab4, 1);
        module->value = 1;
        return 0;
    }
}

/* --- rel/movie_module/fn_12_2B348.c --- */
extern u32 lbl_12_bss_7C64[137];

u32 fn_12_2B348(void) {
    return lbl_12_bss_7C64[127];
}
