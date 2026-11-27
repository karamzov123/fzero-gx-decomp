#include "types.h"

/* --- rel/movie_module/fn_12_86B8.c --- */
struct fn_12_86B8_Arg0 {
    u8 pad_0[0x118];
    u32 unk_118;
};
extern u32 fn_12_847C(void *, u32, void *, void *, void *);
extern u32 fn_12_80BC(u32, void *, u32);


void fn_12_86B8(void *arg0) {
    u32 temp_r3;
    s32 sp8;
    void *temp_r31;
    void *temp_r30;
    u32 field_118;
    void * lab_t2;
    void * lab_t2_;

    temp_r31 = (void *)((u8 *)(arg0) + 0x234);
    temp_r30 = (void *)((u8 *)(arg0) + 0x110);
    lab_t2 = (void *)(&sp8);
    lab_t2_ = lab_t2;
    fn_12_847C((void *)(arg0), (u32)(*(u32 *)((u8 *)(arg0) + 280)), lab_t2_, (void *)(temp_r31), (void *)((u8 *)(arg0) + 0x2C0));
    lab_t2 = (void *)(&sp8);
    lab_t2_ = lab_t2;
    fn_12_847C((void *)(arg0), (u32)(*(u32 *)((u8 *)(temp_r30) + 12)), lab_t2_, (void *)((u8 *)(temp_r31) + 0x10), (void *)((u8 *)(arg0) + 0x2E4));
    temp_r3 = *(u32 *)((u8 *)(arg0) + 596);
    (*(u32 *)((u8 *)(arg0) + 596)) = (u32) (temp_r3 + 0x180);
    fn_12_80BC((u32)(temp_r3), (void *)(temp_r30), (u32)(*(u32 *)((u8 *)(arg0) + 788)));
}

/* --- rel/movie_module/fn_12_873C.c --- */
typedef struct MovieModule {
    u8 _pad110[0x110];
    u32 field_110;
    u8 _pad114[4];
    u32 field_118;
    u8 _pad11c[0x128];
    u32 field_244;
    u8 _pad248[0xc];
    u32 field_254;
    u8 _pad258[0x8c];
    u32 field_2e4;
    u8 _pad2e8[0x2c];
    u32 field_314;
} MovieModule;

extern void fn_12_8344(u32, u32 *, u32);

#pragma opt_propagation off
void fn_12_873C(MovieModule *module) {
    u32 *field110 = &module->field_110;
    u32 value;

    fn_12_847C(module, module->field_118, &value, &module->field_244, &module->field_2e4);
    {
        u32 old_value = module->field_254;
        module->field_254 = old_value + 0x180;
        fn_12_8344(old_value, field110, module->field_314);
    }
}
#pragma opt_propagation reset

/* --- rel/movie_module/fn_12_879C.c --- */
typedef struct MovieModule_u2 {
    u8 _pad110[0x110];
    u32 field_110;
    u8 _pad114[4];
    u32 field_118;
    u8 _pad11c[0x118];
    u32 field_234;
    u8 _pad238[0x1c];
    u32 field_254;
    u8 _pad258[0x68];
    u32 field_2c0;
    u8 _pad2c4[0x50];
    u32 field_314;
} MovieModule_u2;


#pragma opt_propagation off
void fn_12_879C(MovieModule_u2 *module) {
    u32 *field110 = &module->field_110;
    u32 value;

    fn_12_847C(module, module->field_118, &value, &module->field_234, &module->field_2c0);
    {
        u32 old_value = module->field_254;
        module->field_254 = old_value + 0x180;
        fn_12_8344(old_value, field110, module->field_314);
    }
}
#pragma opt_propagation reset
