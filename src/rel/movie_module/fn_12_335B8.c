#include "types.h"
#include "ppc_ops.h"

extern s64 lbl_12_bss_1B778;

s64 fn_12_335B8(void) {
    if (lbl_12_bss_1B778 == 1) {
        return 0;
    }
    return ppc_get_time_base();
}
