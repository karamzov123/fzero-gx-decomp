#include "types.h"


/* --- dol/fn_800452FC.c --- */
typedef struct {
    u8 pad[0x90];
    u32 field;
} Fn800452FCObject;

u32 fn_800452FC(Fn800452FCObject *object) {
    return object->field;
}

/* --- dol/fn_80045304.c --- */
struct fn_80045304_Arg0 {
    u8 pad_0[0x94];
    u32 unk_94;
};

u32 fn_80045304(struct fn_80045304_Arg0 *arg0) {
    return arg0->unk_94;
}
