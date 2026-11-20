#include "types.h"


/* --- dol/fn_8004E2B0.c --- */
typedef struct {
    u8 _pad[0x34];
    s16 field_34;
    s16 field_36;
    s16 field_38;
} Fn8004E2B0Data;

void fn_8004E2B0(Fn8004E2B0Data* data, s16* value_1, s16* value_2, s16* value_3) {
    *value_1 = data->field_34;
    *value_2 = data->field_36;
    *value_3 = data->field_38;
}

/* --- dol/fn_8004E2CC.c --- */
struct fn_8004E2CC_Arg0 {
    u8 pad_0[0x34];
    u16 unk_34;
    u16 unk_36;
    u16 unk_38;
};

void fn_8004E2CC(struct fn_8004E2CC_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    arg0->unk_34 = arg1;
    arg0->unk_36 = arg2;
    arg0->unk_38 = arg3;
}
