#include "types.h"


/* --- dol/fn_8000EE50.c --- */
extern u32 lbl_801A67C0;
extern u32 lbl_801A67C4;

void fn_8000EE50(u32 arg0, u32 arg1) {
    lbl_801A67C0 = arg0;
    lbl_801A67C4 = arg1;
}

/* --- dol/fn_8000EE5C.c --- */
extern u32 __OSSavedRegionEnd;
extern u32 __OSSavedRegionStart;

struct fn_8000EE5C_Arg0 {
    u32 unk_0;
};
struct fn_8000EE5C_Arg1 {
    u32 unk_0;
};

void fn_8000EE5C(struct fn_8000EE5C_Arg0 *arg0, struct fn_8000EE5C_Arg1 *arg1) {
    arg0->unk_0 = __OSSavedRegionStart;
    arg1->unk_0 = __OSSavedRegionEnd;
}
