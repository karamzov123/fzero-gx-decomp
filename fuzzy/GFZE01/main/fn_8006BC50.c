/* Non-matching: best partial attempt (0.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Fn8006BC50Data {
    u8 _pad[0xf4];
    void *items[64];
} Fn8006BC50Data;

#pragma unroll off
s32 fn_8006BC50(Fn8006BC50Data *data) {
    u32 i;
    for (i = 0; i < 256; i += 4) {
        if (*(void **)((u8 *)data + i + 0xf4) != 0) {
            *(void **)((u8 *)data + i + 0xf4) = 0;
        }
    }
    return 0;
}
