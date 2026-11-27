#include "types.h"

/* --- rel/movie_module/fn_12_34A8.c --- */
/* --- rel/movie_module/fn_12_34A8.c --- */
typedef struct MovieState {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
} MovieState;

void fn_12_34A8(MovieState *self, u32 *value_c, u32 *value_10, u32 *value_8) {
    *value_8 = self->unk8;
    *value_c = self->unkC;
    *value_10 = self->unk10;
}

/* --- rel/movie_module/fn_12_34C4.c --- */
/* --- rel/movie_module/fn_12_34C4.c --- */
typedef struct MovieState_u1 {
    u32 unk0;
    u32 active;
    u32 unk8;
    u32 value4;
    u32 value5;
} MovieState_u1;

void fn_12_34C4(MovieState_u1 *self, u32 value4, u32 value5, u32 value8) {
    self->unk8 = value8;
    self->value4 = value4;
    self->value5 = value5;
    self->active = 1;
}

/* --- rel/movie_module/fn_12_34DC.c --- */
typedef struct MovieModuleObject {
    int field_0;
    int field_4;
} MovieModuleObject;

int fn_12_34DC(MovieModuleObject *module) {
    return module->field_4;
}

/* --- rel/movie_module/fn_12_34E4.c --- */
extern void fn_12_3B65C(void *);

void fn_12_34E4(void *arg0, void *arg1, void *arg2) {
    fn_12_3B65C(arg2);
}

/* --- rel/movie_module/fn_12_3508.c --- */
typedef struct MovieModuleObject_u2 {
    int field_0;
    int field_4;
    void *field_8;
    void *field_C;
    void *field_10;
    int field_14;
} MovieModuleObject_u2;

extern void fn_12_3BEF0(void *, void *, void *, void *);

void fn_12_3508(MovieModuleObject_u2 *module, void *arg1, void *arg2) {
    fn_12_3BEF0(module->field_8, module->field_C, module->field_10, arg2);
    module->field_4 = 0;
}

/* --- rel/movie_module/fn_12_354C.c --- */
typedef struct MovieModuleObject_u3 {
    u32 field_0;
} MovieModuleObject_u3;

extern u32 lbl_12_bss_4C0[42];

void fn_12_354C(MovieModuleObject_u3 *module) {
    if (module != 0) {
        module->field_0 = 0;
        lbl_12_bss_4C0[0] -= 1;
    }
}

/* --- rel/movie_module/fn_12_3570.c --- */
typedef struct MovieModuleObject_u1 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
} MovieModuleObject_u1;


static inline MovieModuleObject_u1 *find_object(void) {
    MovieModuleObject_u1 *cur = (MovieModuleObject_u1 *)(lbl_12_bss_4C0 + 2);
    int i;
    for (i = 0; i < (int)lbl_12_bss_4C0[1]; i++) {
        if (cur->field_0 == 0) {
            return cur;
        }
        cur++;
    }
    return 0;
}

#pragma opt_dead_assignments off
MovieModuleObject_u1 *fn_12_3570(void) {
    int fzgx_value;
    MovieModuleObject_u1 *obj = find_object();
    if (obj != 0) {
        obj->field_8 = 0;
        fzgx_value = 0x1f;
        obj->field_C = fzgx_value;
        obj->field_10 = 0x64;
        obj->field_4 = 1;
        lbl_12_bss_4C0[0] += 1;
        obj->field_0 = 1;
    }
    return obj;
}
#pragma opt_dead_assignments reset
