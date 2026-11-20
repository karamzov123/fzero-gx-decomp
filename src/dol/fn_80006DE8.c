#include "types.h"


/* --- dol/fn_80006DE8.c --- */
struct fn_80006DE8_Arg0 {
    u32 unk_0;
    u8 pad_4[0x34];
    u32 unk_38;
};

u32 fn_80006DE8(struct fn_80006DE8_Arg0 *arg0) {
    if ((s32)arg0->unk_0 == 1) { return (u32)arg0; }
    return arg0->unk_38;
}

/* --- dol/fn_80006DFC.c --- */
typedef struct Fn80006DFCObject {
    s32 state;
    u8 pad[0x30];
    void *value;
} Fn80006DFCObject;

void *fn_80006DFC(Fn80006DFCObject *object) {
    if (object->state != 1) {
        object = object->value;
    }
    return object;
}
