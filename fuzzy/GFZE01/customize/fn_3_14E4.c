/* Non-matching: best partial attempt (87.76% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"

extern char lbl_3_data_15D8[21];
extern void fn_3_2BFB4(void);
extern u32 lbl_3_data_BC[2];
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_130EE8(u32, u32);
extern u32 fn_1_435C(u32);
extern s32 fn_1_3F8C(char *, void *, u32, u32);
extern void fn_1_47F74(s32);
extern void fn_1_A176C(void *, u32);
extern u32 lbl_1_bss_6EAD0[450];

void fn_3_14E4(void) {
    u8 * base;
    u32 zero = 0;
    void * lab_t0;
    u32 lab_t0_;
    base = (u8 *)&lbl_3_bss_0 + 0x20000;

    fn_1_4A00(1, 0xf, *(u32 *)(base + 0x850));
    lab_t0_ = *(u32 *)(base + 0x84c);
    fn_1_130EE8(lab_t0_, *(u32 *)(base + 0x850));
    fn_1_435C(*(u32 *)(base + 0x850));
    lbl_3_data_BC[0] = fn_1_3F8C("CustomizeMemcardDisp", (void *)fn_3_2BFB4, 0, 8);
    fn_1_47F74(0x85);
    fn_1_47F74(0xa1);
    *(u8 *)(base + 0x437d) = zero;
    lab_t0 = (void *)*(u32 *)lbl_1_bss_6EAD0;
    *(u8 *)(base + 0x437e) = 0xff;
    *(u32 *)(base + 0x4380) = zero;
    fn_1_A176C(*(void **)lab_t0, 8);
    *(u32 *)(base + 0x4384) = zero;
}
