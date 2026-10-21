/* Non-matching: best partial attempt (56.18% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_801A6C8C;
extern void fn_8006C7E8(void *arg0, void *arg1);
extern void fn_8006B99C(void);

void fn_8006B92C(void *arg0) {
    u32 i;
    u32 count;
    u32 zero;

    fn_8006C7E8(arg0, arg0);
    i = 0;
    *(u32 *)((u8 *)arg0 + 0x11F4) = 0xFF;
    count = 64;
    zero = i;
    do {
        *(u32 *)((u8 *)arg0 + i + 0xF4) = zero;
        i += 4;
    } while (--count != 0);
    if ((s32)lbl_801A6C8C == 0) {
        fn_8006B99C();
        lbl_801A6C8C = 1;
    }
}
