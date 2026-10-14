/* Non-matching: best partial attempt (96.82% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_3_bss_7EDC0[0x80];
extern f32 lbl_3_rodata_378[84];
extern u8 lbl_3_bss_7EE40[33216];

typedef struct CustomizeSlot {
    u8 pad[5];
    u8 field5;
    u8 tail[0x81c0 - 6];
} CustomizeSlot;

extern void fn_1_870BC(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, f32 arg5);
extern s16 fn_3_F948(void *arg0);
extern void fn_1_87238(u32 arg0, u32 arg1, f32 arg2);
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);
extern void fn_1_151BDC(void *arg0);
extern void fn_1_14E2DC(u32 arg0, u32 arg1, f32 arg2);

void fn_3_E5D4(void) {
    u8 *base;
    u8 *s;
    u8 work[0x440] __attribute__((aligned(32)));

    base = lbl_3_bss_7EDC0;
    s = base + 0x18;

    if ((*(CustomizeSlot **)base)[*(u8 *)(s + 0x46)].field5 < 0x29) {
        fn_1_870BC(*(u32 *)(base + 0xc), 0, *(u32 *)(base + 0xc), 0, 1, ((0)[lbl_3_rodata_378]));
        if (fn_3_F948(lbl_3_bss_7EE40 + 0x20) && *(s16 *)(s + 0x1c) == 0) {
            fn_1_87238(*(u32 *)(base + 0xc), 0, lbl_3_rodata_378[0]);
        }
    } else {
        fn_80008BEC(work, 0, 0x440);
        *(u32 *)(work + 0x390) |= 0x4000000;
        *(u32 *)(work + 0x3a0) = *(u32 *)(base + 8);
        *(u32 *)(work + 0x3a4) = *(u32 *)(base + 0x10);
        *(u16 *)(work + 0x3ba) = 0;
        fn_1_151BDC(lbl_3_bss_7EE40);
        fn_1_14E2DC(*(u32 *)(base + 8), 0, lbl_3_rodata_378[0]);
    }
}
