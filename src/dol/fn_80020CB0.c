#include "types.h"


/* --- dol/fn_80020CB0.c --- */
struct fn_80020CB0_object {
    struct fn_80020CB0_object *next;
    struct fn_80020CB0_object *prev;
    u8 pad_8[4];
    u32 index;
};

extern struct fn_80020CB0_object *lbl_8015D100[];
extern struct fn_80020CB0_object *lbl_8015D180[];
extern u32 OSDisableInterrupts(u32);
extern u32 OSRestoreInterrupts(u32);
extern u32 fn_80020A28(u32);

void fn_80020CB0(struct fn_80020CB0_object *arg0, u32 arg1) {
    u32 v0;
    struct fn_80020CB0_object **slot;

    v0 = OSDisableInterrupts((u32)arg0);
    fn_80020A28((u32)arg0);
    slot = &lbl_8015D100[arg1];
    arg0->next = *slot;
    arg0->prev = 0;
    if (arg0->next != 0) {
        (*slot)->prev = arg0;
        *slot = arg0;
    } else {
        lbl_8015D180[arg1] = arg0;
        *slot = arg0;
    }
    arg0->index = arg1;
    OSRestoreInterrupts(v0);
}
