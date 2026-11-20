#include "types.h"


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

void fn_12_89D4(MovieModule *module) {
    u32 value = module->field_254;

    module->field_254 = value + 0x180;
    fn_12_8878(
        &module->field_340,
        value,
        &module->field_154,
        module->field_40
    );
}

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


void fn_12_8A10(struct fn_12_8A10_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    s16 v3;
    u32 v4;
    struct { u32 a[2]; } loc_8;
    /* frame */
    v0 = ((u32)arg0 + 288);
    v1 = ((u32)arg0 + 580);
    v2 = arg0->unk_254;
    arg0->unk_254 = (v2 + 384);
    ((fn_12_8A10_Fn0)arg0->unk_290)((u32)arg0, arg0->unk_308, &loc_8, v1);
    v3 = *(s16 *)((u8 *)v1 + 14);
    *(u32 *)((u8 *)v0 + 4) = (*(u32 *)((u8 *)v1 + 0) + loc_8.a[0]);
    *(u32 *)((u8 *)v0 + 12) = (*(u32 *)((u8 *)v1 + 4) + loc_8.a[0]);
    v4 = *(u32 *)((u8 *)v1 + 8);
    *(u32 *)((u8 *)v0 + 20) = (v4 + loc_8.a[1]);
    *(u32 *)((u8 *)v0 + 28) = (*(u32 *)((u8 *)v0 + 20) + 8);
    *(u32 *)((u8 *)v0 + 36) = (*(u32 *)((u8 *)v0 + 20) + (v3 << 3));
    *(u32 *)((u8 *)v0 + 44) = (*(u32 *)((u8 *)v0 + 36) + 8);
    fn_12_8878((void *)((u32)arg0 + 832), v2, (void *)v0, (void *)*(u32 *)((u8 *)(u32)arg0 + 64));
}

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
