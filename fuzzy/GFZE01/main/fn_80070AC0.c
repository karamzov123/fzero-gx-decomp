/* Non-matching: best partial attempt (95.09% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80070AC0_lbl_801A6D00_T {
    u8 pad_0[0x90];
    u32 unk_90;
    u32 unk_94;
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

void fn_80070AC0(u32 arg0, s32 arg1) {
    
    u32 v7;
    s32 i;
    struct { u32 value; } j;
    struct { u32 value; } n;
    u32 v1;
    s32 k;

    
    if (arg0 == 0) {
        OSPanic(((char *)fzgx_pool_strings_lbl_8015AA78_0), 514, ((char *)fzgx_pool_strings_lbl_8015AA78_CC));
    }
    lbl_8006D758();
    lbl_8006DCDC();
    if (arg1 != 0 && (lbl_801A6CE0 & 2) == 0) {
        arg1 = 0;
    }
    if (arg1 != 0) {
        v1 = (arg0 * 48 + 1023) >> 10;
        v7 = 16;
        for (i = 0; i < 16; i++) {
            if ((*((i) + (lbl_8019E140))) == 0) {
                n.value = v1 - 1;
                j.value = i + 1;
                while (n.value != 0 && j.value < 16) {
                    if (lbl_8019E140[j.value] != 0) {
                        break;
                    }
                    n.value--;
                    j.value++;
                }
                if (n.value == 0) {
                    v7 = lbl_801A6CF0 + (i << 10);
                    for (k = 0; k < v1; k++) {
                        lbl_8019E140[i + k] = v1 - k;
                    }
                    break;
                }
            }
        }
        if (0 == v7) {
            OSPanic(((char *)fzgx_pool_strings_lbl_8015AA78_0), 158, ((char *)fzgx_pool_strings_lbl_8015AA78_C));
        }
        lbl_801A6D00->unk_90 = v7;
    } else {
        lbl_801A6D00->unk_90 = fn_80070CF8(arg0 * 48);
    }
    lbl_801A6D00->unk_94 = lbl_801A6D00->unk_90 + arg0 * 48;
}
