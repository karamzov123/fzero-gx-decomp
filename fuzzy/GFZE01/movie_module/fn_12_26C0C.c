/* Non-matching: best partial attempt (50.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieState {
    u8 pad[0x1B30];
    u32 state;
} MovieState;

int fn_12_26C0C(MovieState *arg0) {
    if (arg0->state != 0) {
    }
    return 0;
}
