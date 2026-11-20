#include "types.h"


/* --- rel/movie_module/fn_12_338C4.c --- */
extern int fn_12_3A36C(void *);
extern char lbl_12_rodata_114C[50];
extern void MWSFSVM_Error(const char *, ...);
extern int fn_12_3A7D8(void *);
extern int fn_12_2A508(int);

int fn_12_338C4(void *self) {
    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(lbl_12_rodata_114C);
        return 0;
    }
    return fn_12_2A508(fn_12_3A7D8(self));
}

/* --- rel/movie_module/fn_12_3391C.c --- */
extern char lbl_12_rodata_1180[136];
extern int fn_12_2B1E8(int, s32);

typedef struct MovieState {
    u8 field_00[0x78];
    s32 field_78;
    s32 field_7C;
    s32 field_80;
} MovieState;

void fn_12_3391C(MovieState *self) {
    s32 field_78;
    s32 field_7C;
    s32 field_80;
    int result;

    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(lbl_12_rodata_1180);
        return;
    }

    field_78 = self->field_78;
    field_7C = self->field_7C;
    field_80 = self->field_80;
    result = fn_12_3A7D8(self);
    if (field_7C > field_80) {
        fn_12_2B1E8(result, field_78);
        self->field_80 = self->field_80 + 1;
        self->field_7C = self->field_80;
    }
}

/* --- rel/movie_module/fn_12_339B4.c --- */
extern void fn_12_2A674(u32, u32, u32, void *);

typedef struct MovieResult {
    u32 field_00;
    u32 field_04;
    u32 field_08;
    s16 field_0C;
    s16 field_0E;
} MovieResult;

typedef struct MovieOutput {
    u32 field_00;
    u32 field_04;
    u32 field_08;
    u32 field_0C;
    u32 field_10;
    u32 field_14;
} MovieOutput;

void fn_12_339B4(u32 arg0, u32 arg1, u32 arg2, MovieOutput *out) {
    MovieResult result;
    fn_12_2A674(arg0, arg1, arg2, &result);
    out->field_00 = result.field_08;
    out->field_04 = result.field_00;
    out->field_08 = result.field_04;
    out->field_0C = result.field_0E;
    out->field_10 = result.field_0C;
    out->field_14 = result.field_0C;
}

/* --- rel/movie_module/fn_12_33A14.c --- */
extern u32 fn_12_35670(u32, u32);

struct fn_12_33A14_Arg0 {
    u8 pad_0[0xB4];
    u32 unk_B4;
    u32 unk_B8;
};

void fn_12_33A14(struct fn_12_33A14_Arg0 *arg0) {
    arg0->unk_B4 = 0;
    arg0->unk_B8 = 0;
    fn_12_35670((u32)arg0, 0);
}
