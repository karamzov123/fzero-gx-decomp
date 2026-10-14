/* Non-matching: best partial attempt (78.17% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"

extern s16 fn_1_80CC4(u8, s32, s32, void *);
extern s16 lbl_1_bss_966;
extern u32 fn_3_0(u32, u32);
extern u32 lbl_1_bss_6D82C;
extern void fn_1_12AB38(void *);
extern u32 fn_1_D3884(void *);
extern void fn_80008BA8(void *, const void *, u32);
extern void fn_1_14DB48(u32 *, void *, u32);
extern s32 fn_8006FDEC(void);
extern void fn_3_273F4(void);
extern s32 fn_1_3F8C(void *, void (*)(void), u32, u32);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_151BDC(void *);
extern u32 lbl_801A6410;
extern void *fn_1_45D0(u32, u32, void *, u32);
extern void fn_80008BEC(void *, int, u32);
extern void *fn_1_7F254(void *, u32);
extern u32 lbl_3_bss_7EBA4;
extern u32 lbl_3_bss_7EBA8;
extern u32 lbl_3_bss_2C7C0[66624];
extern void fn_1_FDC00(void);
extern void fn_1_FDEC8(void);
extern void fn_1_FD324(void);
extern void fn_1_FD844(void *);
extern void fn_1_FE004(void);
typedef struct { u8 pad[8]; s16 unk_8; } Obj_F0;
typedef struct { u8 pad[0x324]; s32 value; } Entry;

#pragma opt_propagation off
void fn_3_990C(u32 arg0) {
    u8 *p_lbl_3_bss_0;
    u8 *p_lbl_3_data_0;
    Obj_F0 *v0;
    s16 v1;
    s32 v2;
    u8 *v3;
    s32 v4;
    s16 v5;
    s32 v6;
    u32 v7;
    s32 v8;
    u32 v9;
    s32 *v10;
    u8 *meta;
    u8 index;
    u8 *entry;
    p_lbl_3_bss_0 = (u8 *)&lbl_3_bss_0;
    v0 = (Obj_F0 *)((u32)p_lbl_3_bss_0 + 240);
    v1 = v0->unk_8;
    p_lbl_3_bss_0[0x1a] = 0;
    v2 = v1 * 0x81c0;
    p_lbl_3_data_0 = (u8 *)&lbl_3_data_0;
    p_lbl_3_bss_0[0x1b] = 0;
    v3 = (u8 *)((u32)p_lbl_3_bss_0 + 0x20000);
    p_lbl_3_bss_0[0x1c] = 0;
    *(u32 *)((u8 *)&lbl_3_bss_140 + v2) |= 0x80000000;
    *(u32 *)((u8 *)&lbl_3_bss_140 + v2) |= 0x40000000;
    fn_3_0(v1, 0);
    v4 = v0->unk_8 * 0x81c0;
    fn_80008BA8((u8 *)&lbl_3_bss_140 + v4 + 0x81a4, p_lbl_3_bss_0 + 32, 24);
    v5 = v0->unk_8;
    v6 = v5 * 0x81c0;
    *((u8 *)((u32)&lbl_3_bss_140 + 0x10000) + v6 - 32352) = *(s16 *)(p_lbl_3_bss_0 + 32 + 206);
    if (lbl_1_bss_966 != 93) {
        meta = (u8 *)&lbl_3_bss_140 + v6;
        v7 = (u32)(v3 + 0x860);
        v8 = v5 * 0x440;
        v9 = *(u32 *)meta;
        v10 = (s32 *)(v7 + v8 + 0x324);
        *v10 = -1;
        if (v9 & 0x80000000) {
            if (!(v9 & 0x40000000)) {
                *v10 = fn_1_80CC4(meta[5], 1, 0, (void *)(v7 + v8));
            } else {
                if (lbl_1_bss_6D82C == 0) {
                    fn_1_12AB38(p_lbl_3_data_0 + 0x18a4);
                    lbl_1_bss_6D82C = fn_1_D3884(p_lbl_3_data_0 + 0x18b0);
                    fn_1_12AB38(p_lbl_3_data_0 + 0x18c0);
                }
                fn_1_14DB48((u32 *)meta, (u8 *)((u32)v3 + 0x1960) + v5 * 0xa20, 1U << *(u32 *)(v3 + 0x848));
            }
        }
        if (*(s32 *)(p_lbl_3_data_0 + 0xb8) == -1) {
            fn_8006FDEC();
            *(s32 *)(p_lbl_3_data_0 + 0xb8) = fn_1_3F8C(p_lbl_3_data_0 + 0x1678, fn_3_273F4, 0, 8);
        }
        fn_1_4A00(1, 15, *(void **)(v3 + 0x850));
        *(u32 *)(v3 + 0x43a8) = 0;
    }
    v4 = v0->unk_8 * 0x81c0;
    *(s16 *)(p_lbl_3_data_0 + 0xa8) = -1;
    *(s16 *)(p_lbl_3_bss_0 + 32 + 0x18) = 0;
    *(s16 *)(p_lbl_3_bss_0 + 32 + 0xcc) = 0;
    *(s16 *)(p_lbl_3_bss_0 + 32 + 0xc6) = 0;
    *(s16 *)(p_lbl_3_bss_0 + 32 + 0xc8) = 0;
    *(s16 *)(p_lbl_3_bss_0 + 32 + 0xca) = 0;
    fn_1_151BDC((u8 *)&lbl_3_bss_140 + v4);
    index = v0->unk_8;
    *(s32 *)(p_lbl_3_bss_0 + 0x120) = -1;
    lbl_3_bss_7EBA4 = (u32)fn_1_45D0(lbl_801A6410, 0x440, p_lbl_3_data_0 + 0x11dc, 0x108f);
    lbl_3_bss_7EBA8 = (u32)fn_1_45D0(lbl_801A6410, 0xa20, p_lbl_3_data_0 + 0x11dc, 0x1090);
    fn_80008BEC((void *)lbl_3_bss_7EBA4, 0, 0x440);
    fn_80008BEC((void *)lbl_3_bss_7EBA8, 0, 0xa20);
    *(u32 *)(lbl_3_bss_7EBA4 + 0x3a0) = lbl_3_bss_7EBA8;
    fn_80008BA8(*(void **)(lbl_3_bss_7EBA4 + 0x3a0), (u8 *)((u32)v3 + 0x1960) + index * 0xa20, 0xa20);
    *(u32 *)(lbl_3_bss_7EBA4 + 0x390) = 0x4000000;
    meta = (u8 *)&lbl_3_bss_140 + index * 0x81c0;
    *(void **)(lbl_3_bss_7EBA4 + 0x3a4) = fn_1_7F254(meta, 2);
    entry = (u8 *)lbl_3_bss_2C7C0 + index * 0x10440;
    entry[4] = 4;
    *(s16 *)(lbl_3_bss_7EBA4 + 0x3ba) = 1;
    *(u32 *)entry = lbl_3_bss_7EBA4;
    *(void (**)(void))(entry + 0x10428) = fn_1_FDC00;
    *(void (**)(void))(entry + 0x1042c) = fn_1_FDEC8;
    *(void (**)(void))(entry + 0x10424) = fn_1_FD324;
    *(u32 *)(entry + 0x10420) = 0;
    *(u32 *)(entry + 12) = 0x20000000;
    fn_1_FD844(meta);
    fn_1_FE004();
}
