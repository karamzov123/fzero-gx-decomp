#include "types.h"


/* --- rel/movie_module/fn_12_CA60.c --- */
/* --- rel/movie_module/fn_12_CA60.c --- */
typedef struct MovieObject {
    u8 pad_0000[0x1338];
    u32 field_1338;
    u32 field_133c;
    u32 field_1340;
} MovieObject;

void fn_12_CA60(MovieObject *self, u32 *value_1338, u32 *value_1340);

/* --- rel/movie_module/fn_12_CA84.c --- */
void fn_12_CA84(MovieObject *self, u32 value_1338, u32 value_133c);

/* --- rel/movie_module/fn_12_CA98.c --- */
/* --- rel/movie_module/fn_12_CA98.c --- */
typedef struct MovieEntry {
    u32 field_0;
    u32 field_4;
    u32 field_8;
} MovieEntry;

typedef struct MovieObject_u1 {
    u8 pad_0000[0x1308];
} MovieObject_u1;

void fn_12_CA98(MovieObject_u1 *self, s32 index, u32 value_0, u32 value_4, u32 value_8);

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
