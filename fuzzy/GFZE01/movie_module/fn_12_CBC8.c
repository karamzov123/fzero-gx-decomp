/* Non-matching: best partial attempt (62.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef void (*Sig_fn_12_A660_MovieCallback)(void *);
typedef struct Sig_fn_12_A660_MovieState {
    u8 pad_0[0x220];
    Sig_fn_12_A660_MovieCallback callback;
    void *callback_arg;
    s32 field_228;
} Sig_fn_12_A660_MovieState;

extern s32 fn_12_A660(Sig_fn_12_A660_MovieState *, s32);
extern u32 lbl_12_bss_5280[3];
extern u32 lbl_12_bss_528C[25];
extern void fn_12_20178(void *);

s32 fn_12_CBC8(u32 arg0) {
    u32 v0;
    u32 v2;
    s32 t0;
    lbl_12_bss_5280[0] = arg0;
    if (arg0 == 0) {
        t0 = -1;
    } else if (*(s32 *)((u8 *)arg0 + 392) != 2) {
        t0 = -1;
    } else {
        t0 = 0;
    }
    if (t0 != 0) {
        return fn_12_A660(0, 0xFF030201);
    } else {
        fn_12_20178((void *)arg0);
        if ((lbl_12_bss_528C[18] & 0x10000000) != 0) {
            v0 = 0;
            for (v2 = 32; v2 != 0; v2--) {
                __dcbi((void *)arg0, v0); v0 += 32;
                __dcbi((void *)arg0, v0); v0 += 32;
                __dcbi((void *)arg0, v0); v0 += 32;
                __dcbi((void *)arg0, v0); v0 += 32;
                __dcbi((void *)arg0, v0); v0 += 32;
                __dcbi((void *)arg0, v0); v0 += 32;
                __dcbi((void *)arg0, v0); v0 += 32;
                __dcbi((void *)arg0, v0); v0 += 32;
            }
        }
        *(s32 *)((u8 *)arg0 + 392) = 1;
        return 0;
    }
}
