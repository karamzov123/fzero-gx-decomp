#include "types.h"

typedef struct MovieModule {
    u8 pad_00[0x40];
    void *field40;
    u8 pad_44[8];
    void *movies;
    u8 pad_50[0x20];
    s8 state70;
    u8 pad_71[0xb7];
    void *field128;
    void *field12c;
} MovieModule;

extern int fn_12_3A36C(MovieModule *module);
static const char fzgx_pool_strings_lbl_12_rodata_12E0_0[44] = "E1122642: mwPlyLinkStm: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_2C[44] = "E99072101 mwPlyLinkStm: can't link stream";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_58[48] = "E1122637: mwPlyGetSlFname: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_88[40] = "E10821B : Invalid value of stm_no : %d";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_B0[48] = "E1122632: mwPlyStartAfsLp: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_E0[44] = "E1122636: mwPlyEntryAfs: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_10C[52] = "E008311 mwPlyEntryAfs: can't entry pid=%d fid=%d";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_140[44] = "E1122641: mwPlySetLpFlg: handle is invalid.";
static const char fzgx_pool_strings_lbl_12_rodata_12E0_16C[52] = "E1122634: mwPlyStartSeamless: handle is invalid.";

extern void MWSFSVM_Error(const char *message, ...);
extern u8 lbl_12_bss_1B780[288];
extern int fn_80056CD0(void *movies);
extern int fn_8004F818(void *arg0, void *arg1, u8 *buffer, int *a, int *b, int *c);
extern void fn_80056E9C(void *movies, u8 *buffer, int a, int b, int c);
extern void fn_80056730(void *movies, int value);
extern int fn_12_23280(void *value);
extern void fn_12_3916C(MovieModule *module, void *arg);
extern void fn_12_38DC8(MovieModule *module);
extern void LSC_Start(void *movies);
extern void fn_12_3858C(MovieModule *module);

typedef struct MovieVTable {
    void *pad_00[5];
    void (*method14)(void *object);
} MovieVTable;

typedef struct MovieObject {
    MovieVTable *vtable;
} MovieObject;

static inline void * fn_12_34390_read_pointer(MovieModule * owner) { return owner->movies; }
void fn_12_34390(MovieModule *module, void *arg1, void *arg2) {
    void * fzgx_live_;
    MovieVTable * fzgx_live;
    
    void *movies;
    MovieModule *current;
    int z;
    int y;
    int x;
    void *field;

    

    if (!fn_12_3A36C(module)) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_B0));
        return;
    }

    fn_80056CD0(fn_12_34390_read_pointer(module));

    if (!fn_12_3A36C(module)) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_E0));
    } else {
        movies = module->movies;
        if (!fn_8004F818(arg1, arg2, lbl_12_bss_1B780, &x, &y, &z)) {
            fn_80056E9C(movies, lbl_12_bss_1B780, x, y, z);
        } else {
            MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_10C), arg1, arg2);
        }
    }

    if (!fn_12_3A36C(module)) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_140));
    } else {
        fn_80056730(module->movies, 1);
    }

    if (!fn_12_3A36C(module)) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_16C));
        return;
    }

    current = (MovieModule *)module;
    if (!fn_12_3A36C(module)) {
        MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_0));
    } else {
        field = module->field40;
        if (module->state70 == 0 && fn_12_23280(field) != 0) {
            MWSFSVM_Error(((char *)fzgx_pool_strings_lbl_12_rodata_12E0_2C));
        }
        module->state70 = 1;
    }

    fn_12_3916C(current, current->field12c);
    fn_12_38DC8(current);
    fzgx_live_ = current->movies;
    LSC_Start(fzgx_live_);

    if (current->field128 != 0) {
        MovieObject *object = current->field128;
        fzgx_live = object->vtable;
        fzgx_live->method14(object);
    }
    fn_12_3858C(current);
}

