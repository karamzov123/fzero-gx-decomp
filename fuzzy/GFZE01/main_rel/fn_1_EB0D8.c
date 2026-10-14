/* Non-matching: best partial attempt (52.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct e12 {
    u8 v[12];
};

struct phys_7B180 {
    u8 pad_0[0x8];
    s32 unk_8;
    u8 pad_C[0x14];
    s32 unk_20;
    u8 pad_24[0x15DC];
    f32 *unk_1600[51];
    u8 unk_16CC;
    u8 pad_16CD[0x81];
    u8 unk_174E;
    u8 pad_174F[0x9];
    struct e12 unk_1758[5];
    u32 unk_1794[5];
    u32 unk_17A8[5];
    u8 pad_17BC[0x44];
    u16 unk_1800[5];
    u8 pad_180A[0x1A];
    u32 unk_1824[5];
};

extern struct phys_7B180 lbl_1_bss_7B180;
extern const f64 lbl_1_rodata_6B68;

void *fn_1_EB0D8(u32 arg0) {
    struct phys_7B180 *b = &lbl_1_bss_7B180;
    u32 count;
    u32 idx;
    f32 *p;
    u32 n;

    if (b->unk_8 == 0) {
        return 0;
    }
    if (b->unk_1794[arg0] == 0 && b->unk_17A8[arg0] == 0) {
        return 0;
    }

    count = b->unk_1800[arg0];
    if (count > 1) {
        idx = b->unk_1824[arg0];
        p = b->unk_1600[arg0];
        if (!(p[idx - 1] > (f64)count)) {
            return 0;
        }

        {
            if (b->unk_20 != 0 && b->unk_16CC != 0xff) {
                n = b->unk_174E;
                if (arg0 == n - 2) {
                    return &b->unk_1758[n - 1];
                }
                if (arg0 == n - 1) {
                    return &b->unk_1758[n - 2];
                }
            }
            return &b->unk_1758[arg0];
        }
    }
}
