#include "types.h"

/* --- rel/movie_module/fn_12_8AEC.c --- */
/* --- rel/movie_module/fn_12_89D4.c --- */
/* --- rel/movie_module/fn_12_89D4.c --- */
typedef struct MovieModule {
    u8 _pad0[0x40];
    void *field_40;
    u8 _pad44[0x110];
    u8 field_154;
    u8 _pad155[0xff];
    u32 field_254;
    u8 _pad258[0xe8];
    u8 field_340;
} MovieModule;

extern void fn_12_8878(void *arg0, u32 arg1, void *arg2, void *arg3);

void fn_12_89D4(MovieModule *module);

/* --- rel/movie_module/fn_12_8A10.c --- */
typedef u32 (*fn_12_8A10_Fn0)(u32, u32, void *, u32);
struct fn_12_8A10_Arg0 {
    u8 pad_0[0x254];
    u32 unk_254;
    u8 pad_258[0x38];
    u32 unk_290;
    u8 pad_294[0x74];
    u32 unk_308;
};


void fn_12_8A10(struct fn_12_8A10_Arg0 *arg0);

/* --- rel/movie_module/fn_12_8AEC.c --- */
typedef struct MovieModule_u1 {
    u8 _pad120[0x120];
    s32 field_120;
    u8 _pad124[0x30];
    s32 field_154;
    u8 _pad158[0x4c];
    s32 field_1a4;
} MovieModule_u1;

void fn_12_8AEC(MovieModule_u1 *module) {
    s32 value = 4;

    if (module->field_1a4 == 0) {
        value = -1;
    }
    module->field_154 = value;
    module->field_120 = value;
}

/* --- rel/movie_module/fn_12_8B0C.c --- */
struct fn_12_8B0C_Arg0 {
    u8 pad_0[0x120];
    u32 unk_120;
    s32 values[12];
    u8 pad_154[0x50];
    s32 unk_1a4;
    u8 pad_1a8[0xa8];
    s16 unk_250;
    s16 unk_252;
};

void fn_12_8B0C(struct fn_12_8B0C_Arg0 *arg0) {
    s32 value = 4;
    s32 *values = &arg0->values[0];
    s16 sample;

    if (arg0->unk_1a4 == 0) {
        value = -1;
    }
    arg0->unk_120 = value;
    sample = arg0->unk_250;
    values[1] = sample;
    values[3] = sample;
    sample = arg0->unk_252;
    values[5] = sample;
    values[7] = sample;
    values[9] = sample;
    values[11] = sample;
}
