#include "types.h"

struct fn_80065D70_Entry {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 pad_F;
};

struct fn_80065D70_State {
    struct fn_80065D70_Entry entries[16];
    u8 pad_100[4];
    u32 unk104[16];
    u8 pad_144[0x40];
    u8 unk184[16];
    u8 pad_194[0x18];
    u32 unk1ac[16];
    u8 pad_1ec[0x40];
    u8 unk22c[16];
    u8 pad_23c[0x224];
    u8 unk460;
};

extern struct fn_80065D70_State *lbl_801A6C80;
extern u32 fn_8006060C(u32);
extern u32 fn_80064D4C(u8, u32);

static inline struct fn_80065D70_Entry *fn_80065D70_array_read(struct fn_80065D70_Entry *array) { return array; }
s32 fn_80065D70(u32 arg0) {
    s32 ret;
    u32 i;

    ret = 0;
    if (arg0 >= 16) {
        ret = -1;
    } else if (fn_80065D70_array_read(lbl_801A6C80->entries)[arg0].unk0 + 0x10000 != 65535) {
        fn_8006060C(arg0);
        fn_80064D4C(arg0, 0);
        fn_80064D4C(arg0, 1);
        lbl_801A6C80->unk460 -= fn_80065D70_array_read(lbl_801A6C80->entries)[arg0].unkC;
        fn_80065D70_array_read(lbl_801A6C80->entries)[arg0].unk0 = -1;
        fn_80065D70_array_read(lbl_801A6C80->entries)[arg0].unkE = 0xFF;
        fn_80065D70_array_read(lbl_801A6C80->entries)[arg0].unkD = 0xFF;
        fn_80065D70_array_read(lbl_801A6C80->entries)[arg0].unkC = 0;
        for (i = 0; i < 16; i++) {
            if (lbl_801A6C80->unk104[i] == fn_80065D70_array_read(lbl_801A6C80->entries)[arg0].unk8) {
                lbl_801A6C80->unk184[i] = 0;
                fn_80065D70_array_read(lbl_801A6C80->entries)[arg0].unk8 = 0;
            }
            if (lbl_801A6C80->unk1ac[i] == fn_80065D70_array_read(lbl_801A6C80->entries)[arg0].unk4) {
                lbl_801A6C80->unk22c[i] = 0;
                fn_80065D70_array_read(lbl_801A6C80->entries)[arg0].unk4 = 0;
            }
        }
    } else {
        ret = -2;
    }
    return ret;
}
