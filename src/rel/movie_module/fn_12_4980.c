#include "types.h"
#include "sofdec/sfx.h"

/* --- rel/movie_module/fn_12_4980.c --- */
extern u32 fn_12_59C(u32, u32);

struct fn_12_4980_Arg0 {
    u8 pad_0[0x58];
    u32 unk_58;
};

void fn_12_4980(struct fn_12_4980_Arg0 *arg0) {
    fn_12_59C(arg0->unk_58, *(u32 *)((u8 *)arg0 + 92));
}

/* --- rel/movie_module/fn_12_49AC.c --- */
extern u32 fn_12_5EC(u32, u32);

struct fn_12_49AC_Arg0 {
    u8 pad_0[0x58];
    u32 unk_58;
};

void fn_12_49AC(struct fn_12_49AC_Arg0 *arg0) {
    fn_12_5EC(arg0->unk_58, *(u32 *)((u8 *)arg0 + 92));
}

/* --- rel/movie_module/fn_12_49D8.c --- */
typedef struct MovieState {
    u8 pad[0x58];
    s32 value;
} MovieState;

int fn_12_49D8(MovieState *state) {
    return state->value != 0;
}

/* --- rel/movie_module/fn_12_49EC.c --- */
typedef struct Fn1249EC {
    u8 _pad58[0x58];
    u32 field_58;
    u32 field_5c;
} Fn1249EC;

void fn_12_49EC(Fn1249EC *self, u32 value_58, u32 value_5c) {
    self->field_58 = value_58;
    self->field_5c = value_5c;
}

/* --- rel/movie_module/fn_12_49F8.c --- */
extern void fn_12_63C(void);

void fn_12_49F8(void) {
    fn_12_63C();
}

/* --- rel/movie_module/fn_12_4A18.c --- */
extern void fn_12_65C(void);

void fn_12_4A18(void) {
    fn_12_65C();
}
