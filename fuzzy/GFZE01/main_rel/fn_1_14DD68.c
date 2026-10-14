/* Non-matching: best partial attempt (94.29% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

void *fn_1_14DD68(void *arg0)
{
    s16 i;
    u32 result;
    u8 *p;
    u8 *base;

    result = 0;
    i = (s16)(u32)result;
    p = (u8 *)arg0;
    base = (u8 *)arg0;

    for (; (u32)i < 3; i++) {
        if ((s16)fn_1_14F344(*(s16 *)p) == 0) {
            result = (u32)(base + i * 0x360 + 0x23c);
            break;
        }
        p += 0x360;
    }

    return (void *)result;
}
