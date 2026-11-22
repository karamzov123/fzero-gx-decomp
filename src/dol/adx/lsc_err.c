#include "types.h"

typedef struct {
    u8 gpr;
    u8 fpr;
    u8 reserved[2];
    u8 *input_arg_area;
    u8 *reg_save_area;
} va_list_t;

extern u32 lbl_80188970[];
extern u32 lbl_80188974[65];
extern void fn_8008077C(char *, const char *, void *);

#pragma opt_propagation off
void fn_800565FC(const char *fmt, ...) {
    u32 *p = lbl_80188970;
    void (*cb)(u32, char *);
    va_list_t ap;

    __builtin_va_info(&ap);
    fn_8008077C((char *)(p + 2), fmt, &ap);
    cb = (void (*)(u32, char *))p[0];
    if (cb != 0) {
        cb(p[1], (char *)(p + 2));
    }
}
#pragma opt_propagation reset

void fn_800566BC(u32 arg0, u32 arg1) {
    if (arg0 == 0) {
        lbl_80188970[0] = 0;
        lbl_80188974[0] = 0;
    } else {
        lbl_80188970[0] = arg0;
        lbl_80188974[0] = arg1;
    }
}
