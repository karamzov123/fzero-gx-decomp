#include "types.h"


/* --- dol/fn_8004ECF4.c --- */
extern u32 fn_800474E4(u32, u32);

void fn_8004ECF4(u32 arg0, u32 arg1);

/* --- dol/fn_8004ED18.c --- */
extern u32 fn_8004ED3C(u32);

struct fn_8004ED18_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

void fn_8004ED18(struct fn_8004ED18_Arg0 *arg0) {
    fn_8004ED3C(arg0->unk_C);
}
