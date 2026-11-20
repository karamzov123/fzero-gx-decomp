#include "types.h"


/* --- rel/movie_module/fn_12_21D30.c --- */
struct fn_12_21D30_E116_u32 { u32 unk_0; u8 pad_4[0x70]; };
struct fn_12_21D30_Arg0 {
    u8 pad_0[0x114C];
    struct fn_12_21D30_E116_u32 unk_114C[1];
};

u32 fn_12_21D30(struct fn_12_21D30_Arg0 *arg0, u32 arg1) {
    return arg0->unk_114C[arg1].unk_0;
}

/* --- rel/movie_module/fn_12_21D40.c --- */
void fn_12_21D40(void *base, int index, int value) {
    u8 *p = (u8 *)base;
    int offset = index * 0x74;
    p += offset;
    *(int *)(p + 0x114c) = value;
}

/* --- rel/movie_module/fn_12_21D50.c --- */
typedef struct MovieEntry {
    int value;
    char unk04[0x70];
} MovieEntry;

typedef struct MovieModule {
    char unk0000[0x1148];
    MovieEntry entries[1];
} MovieModule;

int fn_12_21D50(MovieModule *module, int index) {
    return module->entries[index].value;
}
