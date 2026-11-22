#include "types.h"

typedef void (*AdxErrCallback)(u32, void *);

struct AdxErrState {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8[32];
    u8 unk_28[256];
};

extern struct AdxErrState lbl_8017B030[];
extern u32 lbl_8017B034[];
extern u32 SVM_CallErr(u32, ...);
extern void fn_80083CF4(void *, u32, u32);
extern void strncpy(void *, void *, int);
extern u32 fn_80058EF4(u32, u32);
extern u32 memset(u32, u32, u32);

void fn_80047464(u32 arg0, u32 arg1) {
    struct AdxErrState *p_lbl_8017B030;
    p_lbl_8017B030 = (struct AdxErrState *)&lbl_8017B030;
    strncpy(&p_lbl_8017B030->unk_28, (void *)arg0, 255);
    fn_80083CF4(&p_lbl_8017B030->unk_28, arg1, 255);
    if (p_lbl_8017B030->unk_0 != 0) {
        ((AdxErrCallback)p_lbl_8017B030->unk_0)(
            p_lbl_8017B030->unk_4,
            ((u8 *)p_lbl_8017B030 + 40));
    }
    SVM_CallErr((u32)((u8 *)p_lbl_8017B030 + 40));
}

void fn_800474E4(u32 arg0) {
    struct AdxErrState *p_lbl_8017B030;
    p_lbl_8017B030 = (struct AdxErrState *)&lbl_8017B030;
    strncpy(p_lbl_8017B030->unk_28, (void *)arg0, 255);
    if (p_lbl_8017B030->unk_0 != 0) {
        ((AdxErrCallback)p_lbl_8017B030->unk_0)(
            p_lbl_8017B030->unk_4,
            &p_lbl_8017B030->unk_28[0]);
    }
    SVM_CallErr((u32)((u8 *)p_lbl_8017B030 + 40));
}

void fn_80047548(u32 arg0, u32 arg1) {
    ((u32 *)&lbl_8017B030)[0] = arg0;
    lbl_8017B034[0] = arg1;
    fn_80058EF4(arg0, arg1);
}

void fn_80047578(void) {
    struct AdxErrState *p_lbl_8017B030;
    p_lbl_8017B030 = (struct AdxErrState *)&lbl_8017B030;
    memset((u32)((u8 *)p_lbl_8017B030 + 40), 0, 256);
    p_lbl_8017B030->unk_0 = 0;
    p_lbl_8017B030->unk_4 = 0;
}

void fn_800475C0(void) {
    struct AdxErrState *p_lbl_8017B030;
    p_lbl_8017B030 = (struct AdxErrState *)&lbl_8017B030;
    memset((u32)((u8 *)(u32)p_lbl_8017B030 + 40), 0, 256);
    p_lbl_8017B030->unk_0 = 0;
    p_lbl_8017B030->unk_4 = 0;
}
