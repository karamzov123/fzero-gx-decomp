/* Non-matching: best partial attempt (88.24% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_12_rodata_C78[102];

typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);

typedef struct Sig_fn_12_24A88_MovieObject {
    u8 pad_0000[0x48];
    s32 state;
    u8 pad_004c[0x940];
    Sig_fn_12_24A88_MovieCallback callback;
    void *callback_context;
    s32 callback_data;
} Sig_fn_12_24A88_MovieObject;

extern s32 fn_12_24A88(Sig_fn_12_24A88_MovieObject *, s32);

void fn_12_2CD8C(void) {
    if (lbl_12_rodata_C78[73] != 0x5A5A5A5AU) {
        fn_12_24A88((Sig_fn_12_24A88_MovieObject *)0, 0xFF000201);
    }
}
