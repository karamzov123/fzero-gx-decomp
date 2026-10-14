/* Non-matching: best partial attempt (88.36% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/replay.h"

#define K (0x90000 - 0x4000)

extern void fn_1_78950(void);
extern void fn_1_3EF14(u32 *);
extern void fn_1_F43F0(u8 *, u32 *, u32, u32, u32);
extern s32 fn_1_7B054(void);
extern u8 *fn_1_36AD0(void);
extern void fn_1_F444C(u8 *, u32 *, u32, f32);
extern void fn_1_154CD0(u32, u32);
extern void fn_1_7899C(void);
extern void fn_80008BEC(u8 *, int, u32);
extern u32 OSGetTick(void);
extern void OSReport(const char *, ...);
extern u32 lbl_801A63D0;

void fn_1_F3BC0(void) {
    u32 counter;
    u8 buf[0x14E0];
    u8 *mgr;
    u32 i;
    u32 j;
    u32 k;
    u32 off;
    u32 total;
    u32 n;
    u32 v;
    u32 flag;
    u8 *rec;

    fn_1_78950();
    mgr = (u8 *)lbl_801A63D0;
    fn_80008BEC(mgr, 0, K);
    counter = 0;
    fn_1_3EF14((u32 *)buf);

    fn_1_F43F0(mgr, &counter, OSGetTick() & 0xFF, 8, K);
    fn_1_F43F0(mgr, &counter, 5, 7, K);
    fn_1_F43F0(mgr, &counter, (u32)(s16)fn_1_7B054(), 6, K);
    fn_1_F43F0(mgr, &counter, lbl_1_bss_7EFD8.unk_40->unk_98, 32, K);
    fn_1_F43F0(mgr, &counter, lbl_1_bss_7EFD8.unk_40->unk_9C, 32, K);
    fn_1_F43F0(mgr, &counter, buf[0x19], 5, K);
    fn_1_F43F0(mgr, &counter, (u32)lbl_1_bss_8B3A0.unk_8, 3, K);
    fn_1_F43F0(mgr, &counter, buf[0x15], 2, K);
    fn_1_F43F0(mgr, &counter, (*(u32 *)buf >> 14) & 1, 1, K);
    fn_1_F43F0(mgr, &counter, buf[0x14], 7, K);

    total = 0;
    off = 0;
    for (i = 0; i < buf[0x19]; i++) {
        rec = (u8 *)lbl_1_bss_7EFD8.unk_40 + i * 5;
        fn_1_F43F0(mgr, &counter, rec[0], 1, K);
        fn_1_F43F0(mgr, &counter, rec[1], 6, K);
        fn_1_F43F0(mgr, &counter, rec[4], 5, K);
        fn_1_F43F0(mgr, &counter, rec[3], 7, K);
        if (rec[0] != 0) {
            fn_1_F43F0(mgr, &counter, rec[2], 2, K);
            v = *(u32 *)(fn_1_36AD0() + off);
            OSReport((const char *)lbl_1_data_3E8D4, *(u32 *)(fn_1_36AD0() + off), 0x80000000, v);
            flag = v >> 31;
            fn_1_F43F0(mgr, &counter, flag, 1, K);
            if (flag != 0) {
                for (j = 0; j < 0x81C0; j++) {
                    fn_1_F43F0(mgr, &counter, *(u8 *)(fn_1_36AD0() + off + j), 8, K);
                }
            }
            total++;
        }
        off += 0x81C0;
    }

    n = total & 0xFF;
    for (i = 0; i < n; i++) {
        fn_1_F43F0(mgr, &counter, ((u8 *)&lbl_1_bss_7EFD8)[0x3C + i], 1, K);
    }
    for (i = 0; i < n; i++) {
        fn_1_F43F0(mgr, &counter, ((u8 *)&lbl_1_bss_7EFD8)[0x38 + i] - 1, 2, K);
    }

    fn_1_F43F0(mgr, &counter, lbl_1_bss_7EFD8.unk_8, 20, K);
    fn_1_F43F0(mgr, &counter, *(u16 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + 0xFEF0), 8, K);

    for (i = 0; i < *(u16 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + 0xFEF0); i++) {
        fn_1_F43F0(mgr, &counter, (*(u16 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + 0xF4C) >> 1) & 0x7FFF, 14, K);
        fn_1_F43F0(mgr, &counter, (*(u16 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + 0xF490) >> 1) & 0x7FFF, 14, K);
        fn_1_F43F0(mgr, &counter, (*(u32 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + 0xF4C) >> 14) & 7, 4, K);
        fn_1_F43F0(mgr, &counter, (*(u8 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + 0xF4E) >> 1) & 0x1F, 5, K);
        fn_1_F43F0(mgr, &counter, (*(u16 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + 0xF4E) >> 4) & 0x1F, 5, K);
        fn_1_F43F0(mgr, &counter, (*(u32 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + 0xF490) >> 12) & 0x1F, 5, K);
        fn_1_F43F0(mgr, &counter, (*(u16 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + 0xF492) >> 7) & 0x1F, 5, K);
        fn_1_F43F0(mgr, &counter, (*(u8 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + 0xF493) >> 2) & 0x1F, 5, K);
        for (k = 0; k < lbl_1_bss_7EFD8.unk_18; k++) {
            fn_1_F444C(mgr, &counter, K, *(f32 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + k * 0xC + 0xF554));
            fn_1_F444C(mgr, &counter, K, *(f32 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + k * 0xC + 0xF558));
            fn_1_F444C(mgr, &counter, K, *(f32 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + k * 0xC + 0xF55C));
            fn_1_F444C(mgr, &counter, K, *(f32 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + k * 0xC + 0xF584));
            fn_1_F444C(mgr, &counter, K, *(f32 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + k * 0xC + 0xF588));
            fn_1_F444C(mgr, &counter, K, *(f32 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + k * 0xC + 0xF58C));
        }
        fn_1_F444C(mgr, &counter, K, *(f32 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + 0xF5B4));
        fn_1_F444C(mgr, &counter, K, *(f32 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + 0xF5B8));
        fn_1_F444C(mgr, &counter, K, *(f32 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + 0xF5BC));
        fn_1_F444C(mgr, &counter, K, *(f32 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + 0xF5C0));
        fn_1_F444C(mgr, &counter, K, *(f32 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + 0xF5C4));
        fn_1_F444C(mgr, &counter, K, *(f32 *)((u8 *)lbl_1_bss_7EFD8.unk_40 + i * 0x80 + 0xF5C8));
    }

    lbl_1_bss_7EFD8.unk_40->unk_A0 = lbl_1_bss_7EFD8.unk_40->unk_A2;
    fn_1_F43F0(mgr, &counter, lbl_1_bss_7EFD8.unk_40->unk_A0, 14, K);

    for (i = 0; i <= lbl_1_bss_7EFD8.unk_40->unk_A0; i++) {
        fn_1_F43F0(mgr, &counter, ((u8 *)lbl_1_bss_7EFD8.unk_40)[i * 7 + 0xA4], 8, K);
        fn_1_F43F0(mgr, &counter, (u32)(s8)((u8 *)lbl_1_bss_7EFD8.unk_40)[i * 7 + 0xA7], 8, K);
        fn_1_F43F0(mgr, &counter, ((u8 *)lbl_1_bss_7EFD8.unk_40)[i * 7 + 0xA8], 7, K);
        fn_1_F43F0(mgr, &counter, ((u8 *)lbl_1_bss_7EFD8.unk_40)[i * 7 + 0xA9], 7, K);
        fn_1_F43F0(mgr, &counter, ((u8 *)lbl_1_bss_7EFD8.unk_40)[i * 7 + 0xAA], 8, K);
        fn_1_F43F0(mgr, &counter, (u32)(s8)((u8 *)lbl_1_bss_7EFD8.unk_40)[i * 7 + 0xA5], 8, K);
        fn_1_F43F0(mgr, &counter, (u32)(s8)((u8 *)lbl_1_bss_7EFD8.unk_40)[i * 7 + 0xA6], 8, K);
    }

    fn_1_154CD0((u32)mgr, ((((counter + 7) >> 3) + 0x1F) & ~0x1F));
    fn_1_7899C();
}
