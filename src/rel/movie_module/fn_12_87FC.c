#include "types.h"

typedef struct MovieModule {
    u8 _pad0[0x110];
    u32 field_110;
    u8 _pad114[0x4];
    u32 field_118;
    u8 _pad11c[0x118];
    u8 field_234[0x20];
    u32 field_254;
    u8 _pad258[0x68];
    u8 field_2c0[0x54];
    u32 field_314;
} MovieModule;

extern void fn_12_847C(void *, u32, void *, void *, void *);
extern void fn_12_8344(u32, void *, u32);
extern void fn_12_7E58(void *, void *, void *);

#pragma opt_dead_assignments off
void fn_12_87FC(MovieModule *module) {
    u8 local[8];
    u8 *field_234 = module->field_234;
    u8 *field_110 = (u8 *)module + 0x110;
    void * lab_t2;
    lab_t2 = local;
    fn_12_847C(module, module->field_118, lab_t2, field_234, (u8 *)module + 0x2c0);
    {
        u32 value = module->field_254;
        module->field_254 = value + 0x180;
        fn_12_8344(value, field_110, module->field_314);
    }
    fn_12_7E58(*(void **)(field_110 + 8), local, field_234 + 0x10);
}
#pragma opt_dead_assignments reset

