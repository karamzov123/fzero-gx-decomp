#include "types.h"


/* --- rel/movie_module/fn_12_CA98.c --- */
typedef struct MovieEntry {
    u32 field_0;
    u32 field_4;
    u32 field_8;
} MovieEntry;

typedef struct MovieObject {
    u8 pad_0000[0x1308];
} MovieObject;

void fn_12_CA98(MovieObject *self, s32 index, u32 value_0, u32 value_4, u32 value_8) {
    MovieEntry *entry = (MovieEntry *)((u8 *)self + index * 12 + 0x1308);
    entry->field_0 = value_0;
    entry->field_4 = value_4;
    entry->field_8 = value_8;
}

/* --- rel/movie_module/fn_12_CAB4.c --- */
extern u32 lbl_12_bss_5280;

s32 fn_12_CAB4(u32 arg0) {
    u32 v0;
    u32 v1;
    lbl_12_bss_5280 = arg0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = -1;
    return v0;
    }
    v1 = *(u32 *)((u8 *)v0 + 392);
    v0 = (v1 - 2);
    v0 = ((s32)(v0 | (2 - v1)) >> 31);
    return v0;
}
