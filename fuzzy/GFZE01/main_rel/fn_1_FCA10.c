/* Non-matching: best partial attempt (97.46% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_cas.h"

extern const f32 lbl_1_rodata_7600;
extern u32 lbl_801A6D00;

extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern u32 fn_800736C0(u32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073678(u32);
extern void fn_80073778(void *, s32);
extern void fn_80073898(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void lbl_8006D758(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006DBAC(u32);
extern void lbl_8006E14C(f32);

/* Literal pool shared by this module's init routines. */
typedef struct {
    u8 unk_00[0xC];
    f32 unk_0C;
    u8 unk_10[0x4];
    f32 unk_14;
    u8 unk_18[0x4];
    f32 unk_1C;
    u8 unk_20[0x4];
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    f32 unk_34;
} UnkPool_1_rodata_7600;

#pragma opt_lifetimes on
static inline u32 fn_1_FCA10_call_GXLoadTexMtxImm(u32 a2, u32 a1, u32 a0) { return GXLoadTexMtxImm(a0, a1, a2); }
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_dead_assignments off
void fn_1_FCA10(void) {
    UnkPool_1_rodata_7600 * pool = (UnkPool_1_rodata_7600 *)&lbl_1_rodata_7600;
    u32 tmp[4];
    f32 v;
    u32 obj;
    u32 dest;
    s32 i;
    u32 lab_t1_2;
    u32 c;
    u32 b;
    u32 a;
    f32 z;
    f32 one;
    u32 lab_t1;
    u32 lab_t0;
    s32 lab_t5;

    tmp[0] = pool->unk_24;
    lab_t0 = 0;
    fn_800736C0(lab_t0);

    i = 0;
    while ((u16)i < 4) {
        u32 j = (u16)((u16)i);
        fn_800735C8(j, 12);
        fn_80073620(j, 28);
        i++;
    }

    fn_80073778((void *)lbl_1_bss_85224, 0);
    fn_80073778((void *)lbl_1_data_3EFA8, 1);
    fn_80073778((void *)(lbl_1_data_3EFA8 + 0x20), 2);
    fn_80073778((void *)lbl_1_bss_85204, 3);

    lab_t1 = 30;

    GXLoadTexMtxImm(lbl_1_data_3EFA8 + 0x70, lab_t1, 0);
    lab_t1_2 = 33;
    GXLoadTexMtxImm(lbl_1_data_3EFA8 + 0x40, lab_t1_2, 0);

    lbl_8006DAEC();

    a = pool->unk_28;
    b = pool->unk_2C;
    c = pool->unk_30;
    tmp[3] = c;
    tmp[2] = b;
    tmp[1] = a;
    lbl_8006DBAC(lbl_1_data_3EFA8 + 0xA0);
    lbl_8006E14C((pool->unk_34));

    /* FIFO-resident matrix registers (0xE0000000 block). */
    *(volatile f32 *)0xE000000C = *(f32 *)&tmp[1];
    *(volatile f32 *)0xE000001C = *(f32 *)&tmp[2];
    *(volatile f32 *)0xE000002C = *(f32 *)&tmp[3];

    fn_1_FCA10_call_GXLoadTexMtxImm(0, 0x24, lbl_801A6D00);
    lbl_8006D758();

    dest = lbl_801A6D00;
    *(f32 *)dest = (pool->unk_0C);
    obj = *(u32 *)(lbl_1_data_3EFA8 + 0x40F0);
    v = *(f32 *)(obj + 0x10);
    if (v < (*(volatile f32 *)&((*(f32 volatile *)&(pool->unk_14)) /* Retail reloads this field. */)) /* Retail reloads this field. */ || v >= (pool->unk_1C) /* Retail reloads this field. */) {
        *(f32 *)(obj + 0x10) = (*(volatile f32 *)&((*(f32 volatile *)&(pool->unk_14)) /* Retail reloads this field. */)) /* Retail reloads this field. */;
    }

    obj = *(u32 *)(lbl_1_data_3EFA8 + 0x40F0);
    v = *(f32 *)(obj + 0x14);
    if (v <= (pool->unk_0C) || v > (*(volatile f32 *)&((*(f32 volatile *)&(pool->unk_14)) /* Retail reloads this field. */)) /* Retail reloads this field. */) {
        *(f32 *)(obj + 0x14) = (*(volatile f32 *)&((*(f32 volatile *)&(pool->unk_14)) /* Retail reloads this field. */)) /* Retail reloads this field. */;
    }

    *(f32 *)(lbl_801A6D00 + 0x8) =
        *(f32 *)(*(u32 *)(lbl_1_data_3EFA8 + 0x40F0) + 0x10);
    *(f32 *)(lbl_801A6D00 + 0xC) =
        *(f32 *)(*(u32 *)(lbl_1_data_3EFA8 + 0x40F0) + 0x14);
    *(f32 *)(lbl_801A6D00 + 0x14) = (pool->unk_0C);
    *(f32 *)(lbl_801A6D00 + 0x28) = (pool->unk_0C);
    *(f32 *)(lbl_801A6D00 + 0x2C) = (pool->unk_1C) /* Retail reloads this field. */;

    lab_t1_2 = 0x46;

    GXLoadTexMtxImm(lbl_801A6D00, lab_t1_2, 0);
    lbl_8006DB30();

    fn_80074660(4);
    fn_800745A4(0, 0, 0, 30, 0, 125);
    fn_800745A4(1, 0, 0, 33, 0, 125);
    fn_800745A4(2, 0, 0, 33, 0, 125);
    fn_80073678(4);
    fn_80073898(0);
    fn_80073C6C(0);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 0, 0, 0xFF);
    fn_80072C24(0, 0xF, 0xF, 0xF, 0xF);
    lab_t5 = 0;
    fn_80072D64(0, 0, 0, 0, 1, lab_t5);
    fn_80072CC4(0, 7, 7, 7, 4);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073C6C(1);
    fn_80072AB0(1, 0, 0);
    fn_800734A8(1, 1, 1, 0xFF);
    fn_80072C24(1, 0xF, 0xF, 0xF, 0xF);
    fn_80072D64(1, 0, 0, 0, 1, 0);
    fn_80072CC4(1, 4, 0, 6, 7);
    fn_80072E20(1, 14, 0, 0, 0, 0);
    fn_80073C6C(2);
    fn_80072AB0(2, 0, 0);
    fn_800734A8(2, 2, 2, 4);
    fn_80072C24(2, 0xF, 0xF, 0xF, 8);
    fn_80072D64(2, 0, 0, 0, 1, 0);
    fn_80072CC4(2, 7, 0, 4, 7);
    fn_80072E20(2, 0, 0, 1, 1, 0);
    fn_80073C6C(3);
    fn_80072AB0(3, 0, 0);
    fn_800745A4(3, 0, 1, 36, 1, 70);
    fn_800734A8(3, 3, 3, 4);
    fn_80072C24(3, 0xF, 0xF, 0xF, 0);
    fn_80072D64(3, 0, 0, 0, 1, 0);
    fn_80072CC4(3, 7, 4, 0, 7);
    fn_80072E20(3, 0, 0, 0, 1, 0);
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

#pragma opt_propagation reset

#pragma opt_lifetimes reset

