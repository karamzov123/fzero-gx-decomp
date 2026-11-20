#include "types.h"


/* --- rel/movie_module/fn_12_26C1C.c --- */
// fn_12_26C1C: returns a constant.
int fn_12_26C1C(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_26C24.c --- */
// fn_12_26C24: returns a constant.
int fn_12_26C24(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_26C2C.c --- */
extern u32 lbl_12_bss_96A0[28];

struct Copy8 {
    u32 a[2];
};

struct Copy28 {
    u32 a[7];
};

typedef struct MovieEntry {
    void *data;
    u32 field04;
    u32 field08;
    u32 field0c;
    u32 field10;
    u32 field14;
    u32 field18;
    u32 field1c;
    u32 field20;
    u32 field24;
    u32 field28;
    u32 field2c;
    u8 payload[0x40];
} MovieEntry;

typedef struct MovieModule {
    u8 pad[0x1b30];
    MovieEntry *entry;
} MovieModule;

extern void *memcpy(void *dst, const void *src, u32 size);
extern int fn_12_CBC8(void *movie);
extern int fn_12_24A88(MovieModule *module, u32 code);

int fn_12_26C2C(MovieModule *module) {
    u32 *globals;
    MovieEntry *entry;
    void *movie;
    u32 value1;
    u32 value0;

    globals = lbl_12_bss_96A0;
    entry = module->entry;
    movie = entry->data;
    if (movie == 0) {
        return 0;
    }

    *(struct Copy8 *)&globals[19] = *(struct Copy8 *)&entry->field04;
    *(struct Copy28 *)&globals[21] = *(struct Copy28 *)&entry->field0c;
    memcpy(&globals[17], &entry->field28, 8);
    memcpy(&globals[1], entry->payload, 0x40);

    if (fn_12_CBC8(movie) != 0) {
        return fn_12_24A88(module, 0xff000f0c);
    } else {
        entry->data = 0;
        return 0;
    }
}
