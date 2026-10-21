/* Non-matching: best partial attempt (97.18% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80070AC0_lbl_801A6D00_T {
    u8 pad_0[0x90];
    u32 unk_90;
    s32 unk_94;
};

extern struct fn_80070AC0_lbl_801A6D00_T *lbl_801A6D00;
extern u32 fn_80070CF8(u32);
extern u8 lbl_8019E140[16];
extern u32 lbl_801A6CE0;
extern u32 lbl_801A6CF0;
static char fzgx_pool_strings_lbl_8015AA78_0[12] = "avsystem.c";
static char fzgx_pool_strings_lbl_8015AA78_C[32] = "\n\n... Not enough Locked Cache.\n";
static char fzgx_pool_strings_lbl_8015AA78_2C[48] = "ArenaAllocateDirection: no effect this call.\n";
static char fzgx_pool_strings_lbl_8015AA78_5C[40] = "SetSimulate24MB: no effect this call.\n";
static char fzgx_pool_strings_lbl_8015AA78_84[40] = "SetAbsolute24MB: no effect this call.\n";
static char fzgx_pool_strings_lbl_8015AA78_AC[32] = "init_system: invalid TV format\n";
static char fzgx_pool_strings_lbl_8015AA78_CC[40] = "Matrix Stack is 0.\nnot support system.\n";

extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006D758(void);
extern void lbl_8006DCDC(void);

static inline u32 fn_80070AC0_scan(s32 i, u32 blocks)
{
    u32 n;
    s32 j;

    n = blocks - 1;
    j = i + 1;
    while (n != 0 && j < 16) {
        if (lbl_8019E140[j] != 0) {
            break;
        }
        n--;
        j++;
    }
    return n;
}

static inline u32 fn_80070AC0_loop0(u32 count) {
    u32 k;
    u32 addr;
    s32 i;
    u32 blocks;
        blocks = (count * 48 + 1023) >> 10;
        addr = 0;
        {
    s32 fzgx_loop_i_1461;
for (fzgx_loop_i_1461 = 0; fzgx_loop_i_1461 < 16; fzgx_loop_i_1461++) {
            if (lbl_8019E140[fzgx_loop_i_1461] == 0) {
                if (fn_80070AC0_scan(fzgx_loop_i_1461, blocks) == 0) {
                    addr = lbl_801A6CF0 + (fzgx_loop_i_1461 << 10);
                    for (k = 0; k < blocks; k++) {
                        lbl_8019E140[fzgx_loop_i_1461 + k] = blocks - k;
                    }
                    break;
                }
            }
        }
    i = fzgx_loop_i_1461;
}
    return addr;
}

void fn_80070AC0(u32 count, s32 locked)
{
    u32 addr;

    if (count == 0) {
        OSPanic(fzgx_pool_strings_lbl_8015AA78_0, 514, fzgx_pool_strings_lbl_8015AA78_CC);
    }
    lbl_8006D758();
    lbl_8006DCDC();
    if (locked != 0 && (lbl_801A6CE0 & 2) == 0) {
        locked = 0;
    }
    if (locked != 0) {
        addr = fn_80070AC0_loop0(count);
        if (addr == 0) {
            OSPanic(fzgx_pool_strings_lbl_8015AA78_0, 158, fzgx_pool_strings_lbl_8015AA78_C);
        }
        lbl_801A6D00->unk_90 = addr;
    } else {
        lbl_801A6D00->unk_90 = fn_80070CF8(count * 48);
    }
    lbl_801A6D00->unk_94 = lbl_801A6D00->unk_90 + count * 48;
}
