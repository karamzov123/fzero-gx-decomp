/* Non-matching: best partial attempt (93.29% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/phys.h"

typedef struct {
    u8 pad_0[0x24];
    f32 unk_24;   /* 5.0 */
    u8 pad_28[0xC];
    f32 unk_34;   /* 0.5 */
    f32 unk_38;   /* 10.0 */
    u8 pad_3C[0x4C];
    f32 unk_88;   /* 60.0 */
    u8 pad_8C[0x4C];
    f64 unk_D8;   /* 216.0 */
    u8 pad_E0[0x250];
    u32 unk_330;
    u32 unk_334;
    u32 unk_338;
    u32 unk_33C;
    u32 unk_340;
    u32 unk_344;
    u32 unk_348;
    f32 unk_34C;  /* 450.0 */
} Pool_1_rodata_6780;

typedef struct {
    u8 pad_0[0x2C4];
    s16 unk_2C4;
    u8 pad_2C6[0x1A];
    f32 unk_2E0;
    u8 pad_2E4[0xC];
    s16 unk_2F0;
} Obj_1_bss_7AE88_Flags;

typedef struct {
    u8 pad_0[0xA];
    s16 unk_A;
    u8 pad_C[0xC];
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
} Obj_1_E7524_Param;

extern Pool_1_rodata_6780 lbl_1_rodata_6780;
extern void fn_1_4955C(f32, f32, u32, u32, u32, u32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_49514(u32 *);

static inline u32 fn_1_E7524_array_read(s32 index, u32 *array) { return array[index]; }
#pragma opt_propagation off
extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("PYLON");
}
#pragma section code_type ".text"

#pragma opt_common_subs off
void fn_1_E7524(Obj_1_E7524_Param *arg0)
{
    f32 fzgx_live;
    char *data = (char *)"PYLON";
    Obj_1_bss_7AE88_Flags *bss = (Obj_1_bss_7AE88_Flags *)&lbl_1_bss_7AE88;
    struct { Pool_1_rodata_6780 *value; } pool;
    struct { u32 *base; } tblptr;
    u32 vC;
    u32 v8;
    u32 tbl[5];
    s16 i;

    pool.value = &lbl_1_rodata_6780;
    tbl[0] = pool.value->unk_330;
    tbl[1] = pool.value->unk_334;
    tbl[2] = pool.value->unk_338;
    tbl[3] = pool.value->unk_33C;
    tbl[4] = pool.value->unk_340;
    fn_1_4955C(pool.value->unk_34, pool.value->unk_34, pool.value->unk_33C, pool.value->unk_338, pool.value->unk_334, pool.value->unk_330);
    fn_1_496FC(pool.value->unk_38, pool.value->unk_38);
    fn_1_4AE0C(data + 0x514);
    fn_1_4AE0C(data + 0x524);
    fn_1_4AE0C(data + 0x548);
    fn_1_4AE0C(data + 0x578);
    fn_1_4AE0C(data + 0x594);
    fn_1_4AE0C(data + 0x5B4, bss->unk_2F0);
    fn_1_4AE0C(data + 0x5D0);
    fn_1_4AE0C(data + 0x5EC);
    fn_1_4AE0C(data + 0x60C, pool.value->unk_D8 * bss->unk_2E0);
    fn_1_4AE0C(data + 0x634);
    fn_1_496FC(pool.value->unk_34C, pool.value->unk_24);
    tblptr.base = (u32 *)(data + 0x30);
    fn_1_4AE0C(data + 0x65C, tblptr.base[arg0->unk_A]);

    for (i = 0; i < 5; i++) {
        if (i == bss->unk_2C4) {
            vC = pool.value->unk_344;
            fn_1_49514(&vC);
        }
        fn_1_4AE0C(data + 0x66C, fn_1_E7524_array_read(i, tbl));
        switch (i) {
        case 0:
            fn_1_4AE0C(data + 0x230, arg0->unk_18);
            break;
        case 1:
            fzgx_live = arg0->unk_1C;
            fn_1_4AE0C(data + 0x230, fzgx_live);
            break;
        case 2:
            fn_1_4AE0C(data + 0x230, arg0->unk_20);
            break;
        case 3:
            fn_1_4AE0C(data + 0x230, arg0->unk_24);
            break;
        case 4:
            fn_1_4AE0C(data + 0x230, pool.value->unk_88 * arg0->unk_28);
            break;
        default:
            fn_1_4AE0C(data + 0x2CC);
            break;
        }
        v8 = pool.value->unk_348;
        fn_1_49514(&v8);
    }
}
#pragma opt_common_subs reset

#pragma opt_propagation reset

