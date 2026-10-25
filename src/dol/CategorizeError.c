#include "types.h"

extern u32 lbl_801A68F0;
extern s32 lbl_801A68F4;

struct Executing {
    u8 pad[8];
    u32 state;
};

extern struct Executing *executing_801A68C0;

int CategorizeError(u32 value) {
    u32 masked;
    if (value - 0x20000 == 0x400) {
        lbl_801A68F0 = value;
        return 1;
    }

    masked = value & 0x00ffffff;
    if (masked - 0x60000 == 0x2800 ||
        masked - 0x20000 == 0x3a00 ||
        masked - 0xb0000 == 0x5a01) {
        return 0;
    }

    lbl_801A68F4++;
    if (lbl_801A68F4 == 2) {
        if (masked == lbl_801A68F0) {
            lbl_801A68F0 = masked;
            return 1;
        }
        lbl_801A68F0 = masked;
        return 2;
    }

    lbl_801A68F0 = masked;
    if (masked - 0x30000 == 0x1100 ||
        executing_801A68C0->state == 5) {
        return 2;
    }
    return 3;
}
