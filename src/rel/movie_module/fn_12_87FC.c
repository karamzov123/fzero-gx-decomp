#include "types.h"

/* --- rel/movie_module/fn_12_87FC.c --- */
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

/* --- rel/movie_module/fn_12_8878.c --- */
static inline void decode8(u8 *dst, const s16 *source, const u8 *table) {
    dst[0] = table[source[0]];
    dst[1] = table[source[1]];
    dst[2] = table[source[2]];
    dst[3] = table[source[3]];
    dst[4] = table[source[4]];
    dst[5] = table[source[5]];
    dst[6] = table[source[6]];
    dst[7] = table[source[7]];
}

void fn_12_8878(s16 *source, f64 *output, u32 *entries, const u8 *table) {
    u32 *p;
    s32 groups;
    u8 *base;
    s32 stride;
    u8 *dst;
    s32 rows;
    s32 i;

    p = entries + 1;
    for (groups = 6; groups > 0; groups--) {
        dst = (u8 *)p[0];
        stride = (s32)p[1];
        p += 2;
        base = dst;
        for (rows = 8; rows != 0; rows--) {
            decode8(dst, source, table);
            dst += stride;
            source += 8;
        }
        stride &= ~7;
        for (rows = 0; rows < 8; rows++) {
            *output++ = *(f64 *)base;
            base += stride;
        }
    }
}
