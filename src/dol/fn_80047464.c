#include "types.h"

typedef void (*fn_80047464_Fn0)(u32, void *);

struct fn_80047464_lbl_8017B030 {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8[32];
    u8 unk_28;
};

extern struct fn_80047464_lbl_8017B030 lbl_8017B030[];
extern u32 SVM_CallErr(u32, ...);
extern void fn_80083CF4(void *, u32, u32);
extern void strncpy(void *, void *, int);

void fn_80047464(u32 arg0, u32 arg1) {
    struct fn_80047464_lbl_8017B030 *p_lbl_8017B030;
    p_lbl_8017B030 = (struct fn_80047464_lbl_8017B030 *)&lbl_8017B030;
    strncpy(&p_lbl_8017B030->unk_28, (void *)arg0, 255);
    fn_80083CF4(&p_lbl_8017B030->unk_28, arg1, 255);
    if (p_lbl_8017B030->unk_0 != 0) {
        ((fn_80047464_Fn0)p_lbl_8017B030->unk_0)(
            p_lbl_8017B030->unk_4,
            ((u8 *)p_lbl_8017B030 + 40));
    }
    SVM_CallErr((u32)((u8 *)p_lbl_8017B030 + 40));
}
