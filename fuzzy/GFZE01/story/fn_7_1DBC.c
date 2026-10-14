/* Non-matching: best partial attempt (96.38% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct S58 {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    f32 unk_C;
    f32 unk_10;
    u8 unk_14;
    u8 pad_15;
    u8 unk_16;
    u8 unk_17;
    s16 unk_18;
    u8 pad_1A[2];
    u32 unk_1C;
};

extern char *fn_80083DB0(char *dst, const char *src);
extern char lbl_1_bss_198[];
extern s8 lbl_1_bss_9C[];
extern struct S58 lbl_1_bss_58;
extern u16 lbl_1_bss_968;
extern struct fn_7_E84_lbl_7_bss_10_T *lbl_7_bss_10;
extern u32 lbl_801A66B4;
extern f32 lbl_7_rodata_52C;
extern f32 lbl_7_rodata_5B4;

// All the string arguments live in one span of .data; retail forms every address
// from a single hoisted section base, so they are declared as one object.
extern char lbl_7_data_0[0x14000];

static inline s8 *fn_7_1DBC_array_read(s8 *array) { return array; }
#pragma opt_loop_invariants off
void fn_7_1DBC(u32 lab_unused0, u32 lab_unused1, u32 lab_unused2) {
    u8 fzgx_value;
    s8 v;
    // Every string argument lives above 0x10000 in this section; retail keeps one
    // base register for the whole run of calls, so the base is a named object.
    const char *base = &lbl_7_data_0[0x10000];

    fn_80083DB0(&lbl_1_bss_198[0x000], base + 0x3E4C);
    fn_80083DB0(&lbl_1_bss_198[0x040], base + 0x3E54);
    fn_80083DB0(&lbl_1_bss_198[0x080], base + 0x395C);
    fn_80083DB0(&lbl_1_bss_198[0x0C0], base + 0x3E5C);
    fn_80083DB0(&lbl_1_bss_198[0x100], base + 0x3E64);
    fn_80083DB0(&lbl_1_bss_198[0x140], base + 0x3E6C);
    fn_80083DB0(&lbl_1_bss_198[0x180], base + 0x3E78);
    fn_80083DB0(&lbl_1_bss_198[0x1C0], base + 0x2FA0);
    fn_80083DB0(&lbl_1_bss_198[0x200], base + 0x3E80);
    fn_80083DB0(&lbl_1_bss_198[0x240], base + 0x3144);
    fn_80083DB0(&lbl_1_bss_198[0x280], base + 0x3E78);
    fn_80083DB0(&lbl_1_bss_198[0x2C0], base + 0x3240);
    fn_80083DB0(&lbl_1_bss_198[0x300], base + 0x3E88);
    fn_80083DB0(&lbl_1_bss_198[0x340], base + 0x3324);
    fn_80083DB0(&lbl_1_bss_198[0x380], base + 0x3E90);
    fn_80083DB0(&lbl_1_bss_198[0x3C0], base + 0x342C);
    fn_80083DB0(&lbl_1_bss_198[0x400], base + 0x3E98);
    fn_80083DB0(&lbl_1_bss_198[0x440], base + 0x35BC);
    fn_80083DB0(&lbl_1_bss_198[0x480], base + 0x3EA0);
    fn_80083DB0(&lbl_1_bss_198[0x4C0], base + 0x376C);
    fn_80083DB0(&lbl_1_bss_198[0x500], base + 0x3EA8);
    fn_80083DB0(&lbl_1_bss_198[0x540], base + 0x3844);
    fn_80083DB0(&lbl_1_bss_198[0x580], base + 0x3EB0);
    fn_80083DB0(&lbl_1_bss_198[0x5C0], base + 0x3EC0);
    fn_80083DB0(&lbl_1_bss_198[0x600], base + 0x3E10);

    // Retail executes both store groups; the second pass overrides the first.
    v = fn_7_1DBC_array_read(lbl_1_bss_9C)[3];
    lbl_1_bss_58.unk_0 = lbl_801A66B4;
    lbl_1_bss_58.unk_2 = 0;
    lbl_1_bss_58.unk_14 = 7;
    lbl_1_bss_58.unk_1 = 1;
    lbl_1_bss_58.unk_3 = 0;
    lbl_1_bss_58.unk_4 = 640;
    lbl_1_bss_58.unk_6 = 640;
    lbl_1_bss_58.unk_8 = 0;
    lbl_1_bss_58.unk_A = 0;
    lbl_1_bss_58.unk_C = lbl_7_rodata_52C;
    lbl_1_bss_58.unk_10 = lbl_7_rodata_52C;
    lbl_1_bss_58.unk_16 = 0;
    lbl_1_bss_58.unk_18 = -1;
    lbl_1_bss_58.unk_17 = -1;
    lbl_1_bss_58.unk_1C = 0;
    lbl_1_bss_58.unk_C = lbl_7_rodata_5B4;
    lbl_1_bss_58.unk_10 = lbl_7_rodata_5B4;
    lbl_1_bss_58.unk_8 = 136;
    lbl_1_bss_58.unk_A = 0;
    lbl_1_bss_58.unk_0 = -1;
    fzgx_value = 0;
    lbl_1_bss_58.unk_1 = fzgx_value;
    lbl_1_bss_58.unk_3 = 2;
    lbl_1_bss_58.unk_18 = 0;
    lbl_1_bss_58.unk_14 = 4;
    if (v != 1 || *(s8 *)((u8 *)(*(u32 *)&lbl_7_bss_10) + 1) > 0) {
        lbl_1_bss_58.unk_14 |= 1;
    }
    lbl_1_bss_968 = 8;
    *(u32 *)((u8 *)lbl_7_bss_10 + 8) = 135;
}
#pragma opt_loop_invariants reset

