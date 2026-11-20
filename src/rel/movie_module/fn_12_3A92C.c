#include "types.h"


/* --- rel/movie_module/fn_12_3A92C.c --- */
typedef struct MovieObject {
    u8 pad[0x54];
    u32 value;
} MovieObject;

extern MovieObject *fn_12_38DBC(void);

s32 fn_12_3A92C(void) {
    MovieObject *object = fn_12_38DBC();
    return object->value != 1;
}

/* --- rel/movie_module/fn_12_3A960.c --- */
typedef struct Fn12_3A960_Object {
    u8 _pad[0x64];
    u32 value;
} Fn12_3A960_Object;

void fn_12_3A960(Fn12_3A960_Object *object, u32 value) {
    object->value = value;
}
