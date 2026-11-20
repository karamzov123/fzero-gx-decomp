#include "types.h"


/* --- dol/fn_800542B4.c --- */
struct fn_800542B4_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

void fn_800542B4(struct fn_800542B4_Arg0 *arg0, u32 arg1) {
    arg0->unk_C = arg1;
}

/* --- dol/fn_800542BC.c --- */
typedef struct {
    u8 pad[5];
    s8 value;
} Fn800542BC;

int fn_800542BC(Fn800542BC *obj) {
    return obj->value;
}
