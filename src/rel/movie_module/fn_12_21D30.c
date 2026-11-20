#include "types.h"


/* --- rel/movie_module/fn_12_21D30.c --- */
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

/* --- rel/movie_module/fn_12_21D60.c --- */
typedef struct MovieEntry_u1 {
    int value;
    u8 padding[0x70];
} MovieEntry_u1;

typedef struct MovieModule_u1 {
    u8 padding[0x1148];
    MovieEntry_u1 entries[1];
} MovieModule_u1;

void fn_12_21D60(MovieModule_u1 *module, int index, int value) {
    module->entries[index].value = value;
}

/* --- rel/movie_module/fn_12_21D70.c --- */
typedef struct MovieRecord {
    u8 padding00[0x1144];
    int status;
    u8 padding1148[0x44];
    void *resource;
} MovieRecord;

typedef struct MovieModule_u2 {
    u8 padding00[0x44];
    int active;
} MovieModule_u2;

extern int fn_12_2F210(MovieModule_u2 *module, void *resource, int size, void *argument, int flags);

int fn_12_21D70(MovieModule_u2 *module, int index, void *argument) {
    int result = 0;
    MovieRecord *entry = (MovieRecord *)((u8 *)module + index * 0x74);

    if (entry->status == 0) {
        result = fn_12_2F210(module, entry->resource, 0xc, argument, 0);
    }

    module->active = 1;
    return result;
}
