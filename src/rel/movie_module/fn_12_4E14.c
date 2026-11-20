#include "types.h"


/* --- rel/movie_module/fn_12_4E14.c --- */
extern u32 lbl_12_bss_BA0;
extern u32 lbl_12_rodata_5B8;

void * fn_12_4E14(void) {
    lbl_12_bss_BA0 = (u32)&lbl_12_rodata_5B8;
    return &lbl_12_rodata_5B8;
}

/* --- rel/movie_module/DCT_FsriInitScanTbl.c --- */
static inline int dctFsriScanIndex(int index) {
    int row = index / 8;
    int offset = index % 8;
    int result;
    if ((row % 2) == 0) {
        offset *= 2;
    } else {
        row--;
        offset = offset * 2 + 1;
    }
    result = offset + row * 8;
    if ((result < 0) || (result >= 256)) {
        while (1) {
        }
    }
    return result;
}

void DCT_FsriInitScanTbl(const signed char source[64], signed char destination[64]) {
    int index;
    for (index = 0; index < 64; index++) {
        destination[index] = (signed char)dctFsriScanIndex(source[index]);
    }
}

/* --- rel/movie_module/fn_12_4F18.c --- */
typedef struct MovieModule {
    u8 pad_28[0x28];
    void *field_28;
} MovieModule;

extern void fn_12_4F3C(MovieModule *module, void *arg);

void fn_12_4F18(MovieModule *module) {
    fn_12_4F3C(module, module->field_28);
}
