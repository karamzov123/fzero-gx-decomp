/* Non-matching: best partial attempt (97.28% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/archive.h"

extern void *lbl_801A6410;

typedef struct ArchiveEntry {
    u8 pad[0x68];
    u32 data;
} ArchiveEntry;

typedef struct ArchiveState {
    s32 count;
    s32 loaded;
    u8 pad[4];
    u8 entries[1];
    u8 pad2[0x1B20 - 0xC - 1];
    volatile u8 scratch[0x20];
} ArchiveState;

extern s32 fn_1_458A0(void *arg0, void *arg1, u32 arg2, u32 arg3);
extern void *fn_1_45D0(void *arg0, u32 arg1, void *arg2, u32 arg3);
extern void fn_1_46B4(void *arg0, void *arg1, u8 *arg2, s32 arg3);
extern s32 fn_1_45850(void *arg0);
extern void *fn_1_45B2C(void *arg0);
extern void fn_1_12FD4(void *arg0, u32 arg1);
extern void DCFlushRange(void *arg0, u32 arg1);
extern void OSPanic(u8 *arg0, s32 arg1, u8 *arg2, ...);

#pragma opt_propagation on
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s32 fzgx_obj_lbl_1_bss_897A0;
u32 lbl_1_bss_897A4;
u32 lbl_1_bss_897A8;
u8 fzgx_obj_lbl_1_bss_897AC[1];
u8 lbl_1_bss_897AC_fill_897AD;
u16 lbl_1_bss_897AC_fill_897AE;
u32 lbl_1_bss_897AC_fill_897B0[1732];
volatile u32 lbl_1_bss_897AC_1B14[0x20];
u32 fzgx_obj_lbl_1_bss_8B2E0[48];
u32 fzgx_obj_lbl_1_bss_8B3A0[83];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_897A0;
    s = *(u8 *)&lbl_1_bss_897A4;
    s = *(u8 *)&lbl_1_bss_897A8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_897AC;
    s = *(u8 *)&lbl_1_bss_897AC_fill_897AD;
    s = *(u8 *)&lbl_1_bss_897AC_fill_897AE;
    s = *(u8 *)&lbl_1_bss_897AC_fill_897B0;
    s = *(u8 *)&lbl_1_bss_897AC_1B14;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8B2E0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8B3A0;
}
#pragma section code_type ".text"

#pragma opt_common_subs off
u32 fn_1_12A4B0(void *arg0, s32 arg1, s16 arg2) {
    s32 tmp2;
    u8 *strings;
    ArchiveEntry * e_2;
    u32 size;
    volatile u8 *hp;
    ArchiveEntry *e;
    u8 *slot;
    u16 idx;
    u32 tmp;
    void * lab_t0;

    
    strings = (u8 *)&lbl_1_data_40600;

    if (arg1 != 0) {
        u32 aligned;

        if (fn_1_458A0(arg0, (void *)lbl_1_bss_897AC_1B14, 0x20, 0) < 0) {
            OSPanic(strings + 8, 0xB9, strings + 0xA8);
        }
        /* header bytes are read one at a time through an index register */
        hp = (volatile u8 *)&lbl_1_bss_897AC_1B14[0];
        (void)((idx)[hp]);
        idx = 4;
        size = ((idx)[hp]);
        aligned = (size + 0x1F) & ~0x1F;
        if (arg2 != 0) {
            tmp = (u32)fn_1_45D0(lbl_801A6410, aligned, strings + 8, 0xC1);
            tmp2 = (u32)fn_1_45D0(lbl_801A6410, aligned, strings + 8, 0xC2);
            e = (ArchiveEntry *)((u8 *)&fzgx_obj_lbl_1_bss_897AC);
            e += fzgx_obj_lbl_1_bss_897A0;
            *(u32 *)((u8 *)e + 0x68) = tmp2;
            fn_1_46B4(lbl_801A6410, (void *)tmp, strings + 8, 0xC3);
        } else {
            tmp = (u32)fn_1_45D0(lbl_801A6410, aligned, strings + 8, 0xC5);
            e = (ArchiveEntry *)((u8 *)&fzgx_obj_lbl_1_bss_897AC);
            e += fzgx_obj_lbl_1_bss_897A0;
            *(u32 *)((u8 *)e + 0x68) = tmp;
        }
        if (fn_1_45850(arg0) == 0) {
            OSPanic(strings + 8, 0xD2, strings + 0xD0);
            return 0;
        }
        slot = (u8 *)((u32)((u8 *)&fzgx_obj_lbl_1_bss_897AC[0]) + 0x68);
        fn_1_12FD4(arg0, *(u32 *)((u8 *)slot + fzgx_obj_lbl_1_bss_897A0 * 0x6C));
        lab_t0 = (void *)(*(u32 *)((u8 *)slot + fzgx_obj_lbl_1_bss_897A0 * 0x6C));
        DCFlushRange(lab_t0, aligned);
    } else {
        u32 aligned;

        aligned = ((u32)fn_1_45B2C(arg0) + 0x1F) & ~0x1F;
        tmp = (u32)fn_1_45D0(lbl_801A6410, (aligned + 0x1F) & ~0x1F, strings + 8, 0xF2);
        e = (ArchiveEntry *)((u8 *)&fzgx_obj_lbl_1_bss_897AC);
        e += fzgx_obj_lbl_1_bss_897A0;
        *(u32 *)((u8 *)e + 0x68) = tmp;
        if (fn_1_458A0(arg0, (void *)(*(u32 *)((u8 *)e + 0x68)), aligned, 0) < 0) {
            OSPanic(strings + 8, 0xF5, strings + 0xF8);
        }
        fn_1_45850(arg0);
    }

    e_2 = (ArchiveEntry *)((u8 *)&fzgx_obj_lbl_1_bss_897AC);
    e_2 += fzgx_obj_lbl_1_bss_897A0;
    return *(u32 *)((u8 *)e_2 + 0x68);
}
#pragma opt_common_subs reset

#pragma opt_propagation reset
