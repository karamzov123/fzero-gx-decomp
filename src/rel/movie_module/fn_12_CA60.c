#include "types.h"


/* --- rel/movie_module/fn_12_CA60.c --- */
typedef struct MovieObject {
    u8 pad_0000[0x1338];
    u32 field_1338;
    u32 field_133c;
    u32 field_1340;
} MovieObject;

void fn_12_CA60(MovieObject *self, u32 *value_1338, u32 *value_1340) {
    if (value_1338 != 0) {
        *value_1338 = self->field_1338;
    }
    if (value_1340 != 0) {
        *value_1340 = self->field_1340;
    }
}

/* --- rel/movie_module/fn_12_CA84.c --- */
void fn_12_CA84(MovieObject *self, u32 value_1338, u32 value_133c) {
    self->field_1338 = value_1338;
    self->field_133c = value_133c;
    self->field_1340 = 0;
}
