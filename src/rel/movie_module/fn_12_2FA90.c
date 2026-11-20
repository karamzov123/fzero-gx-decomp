#include "types.h"


/* --- rel/movie_module/fn_12_2FA90.c --- */
typedef struct MovieEntry {
    u32 unk00;
    void *unk04;
    void *unk08;
    u32 unk0c;
} MovieEntry;

typedef struct MovieModule {
    u8 unk0000[0x1cc8];
    MovieEntry *entries;
    u8 unk1ccc[4];
    int count;
} MovieModule;

extern int fn_12_24990(MovieModule *);
extern void fn_12_24A88(void *, int);
extern void fn_12_2269C(MovieModule *, int, int, void *);

int fn_12_2FA90(MovieModule *module, int index, void *arg1, void *arg2) {
    int count;
    MovieEntry *entries;

    if (fn_12_24990(module) != 0) {
        fn_12_24A88(0, 0xff000191);
    } else {
        count = module->count;
        entries = module->entries;
        if (count == 8) {
            fn_12_24A88(module, 0xff000602);
        } else {
            entries[index].unk04 = arg1;
            entries[index].unk08 = arg2;
            entries[index].unk0c = 0;
            entries[index + 1].unk00 = 0;
            fn_12_2269C(module, count, index, &entries[index].unk04);
            return 0;
        }
    }
}

/* --- rel/movie_module/fn_12_2FB54.c --- */
// fn_12_2FB54: returns a constant.
int fn_12_2FB54(void) {
    return 0;
}
