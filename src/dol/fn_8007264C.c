#include "types.h"

struct fn_8007264C_Entry {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    u8 unk_c;
};

struct fn_8007264C_Table {
    u8 pad_0[0x1a0];
};

extern struct fn_8007264C_Table lbl_8019E308[];
extern void GXSetVtxAttrFmt(u32, s32, s32, s32, u8);

void fn_8007264C(u32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    struct fn_8007264C_Entry *entry;

    entry = (struct fn_8007264C_Entry *)&lbl_8019E308[arg0];
    if (entry->unk_0 != arg1 ||
        entry->unk_4 != arg2 ||
        entry->unk_8 != arg3 ||
        entry->unk_c != arg4) {
        entry->unk_0 = arg1;
        entry->unk_4 = arg2;
        entry->unk_8 = arg3;
        entry->unk_c = arg4;
        GXSetVtxAttrFmt(arg0, arg1, arg2, arg3, arg4);
    }
}
