#include "types.h"

struct fn_800726C0_Entry {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    u8 unk_c;
};

/* The linked table contains terminated attribute lists of 12, 12 and 3 entries. */
typedef struct {
    struct fn_800726C0_Entry standard[12];
    struct fn_800726C0_Entry quantized[12];
    struct fn_800726C0_Entry position_texture[3];
} BuiltinVertexFormats;
extern BuiltinVertexFormats lbl_8015A860;
extern void GXClearVtxDesc(void);
extern void fn_800723F8(void);
extern void fn_800726C0(u32, struct fn_800726C0_Entry *);

#pragma opt_propagation off
void fn_80070100(void) {
    BuiltinVertexFormats *formats = &lbl_8015A860;
    GXClearVtxDesc();
    fn_800723F8();
    fn_800726C0(0, formats->standard);
    fn_800726C0(1, formats->quantized);
    fn_800726C0(7, formats->position_texture);
}
#pragma opt_propagation reset
