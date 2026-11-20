#include "types.h"


/* --- dol/fn_80046AC0.c --- */
struct fn_80046AC0_Arg0 {
    u16 unk_0;
    s16 unk_2;
    u8 unk_4[0xE];
    u8 unk_12;
};

s32 fn_80046AC0(struct fn_80046AC0_Arg0 *arg0, s32 arg1, u16 *arg2, u16 *arg3) {
    u8 v1;
    s32 v0;

    if (arg1 < 20) {
        v0 = -1;
    } else {
        if (arg0->unk_0 != 32768) {
            v0 = -2;
        } else {
            if (arg0->unk_2 < 16) {
                v0 = -1;
            } else {
                v1 = arg0->unk_12;
                v0 = 0;
            }
        }
    }
    if (v0 != 0) {
        return -1;
    }
    if (v1 >= 4) {
        if (arg1 < 32) {
            return -1;
        }
        if (arg0->unk_0 != 32768) {
            return -2;
        }
        if (arg0->unk_2 < 28) {
            return -1;
        }
        arg2[0] = *(u16 *)((u8 *)arg0 + 0x18);
        arg3[0] = *(u16 *)((u8 *)arg0 + 0x1A);
        arg2[1] = *(u16 *)((u8 *)arg0 + 0x1C);
        arg3[1] = *(u16 *)((u8 *)arg0 + 0x1E);
    } else {
        arg3[1] = 0;
        arg2[1] = 0;
        arg3[0] = 0;
        arg2[0] = 0;
    }
    return 0;
}

/* --- dol/fn_80046B90.c --- */
struct fn_80046B90_Arg2 {
    u8 unk_0;
};
struct fn_80046B90_Arg3 {
    u8 unk_0;
};


s32 fn_80046B90(u32 arg0, u32 arg1, struct fn_80046B90_Arg2 *arg2, struct fn_80046B90_Arg3 *arg3) {
    u32 v0;
    u8 v1;
    v0 = arg0;
    if ((s32)arg1 < 20) {
    v0 = -1;
    return v0;
    }
    if (*(u16 *)((u8 *)v0 + 0) != 32768) {
    v0 = -2;
    return v0;
    }
    if (*(s16 *)((u8 *)v0 + 2) < 16) {
    v0 = -1;
    return v0;
    }
    arg2->unk_0 = *(u8 *)((u8 *)v0 + 18);
    v1 = *(u8 *)((u8 *)v0 + 19);
    v0 = 0;
    arg3->unk_0 = v1;
    return v0;
}

/* --- dol/fn_80046BE0.c --- */
struct fn_80046BE0_Arg2 {
    u16 unk_0;
};


s32 fn_80046BE0(u32 arg0, u32 arg1, struct fn_80046BE0_Arg2 *arg2) {
    u32 v0;
    u16 v1;
    v0 = arg0;
    if ((s32)arg1 < 18) {
    v0 = -1;
    return v0;
    }
    if (*(u16 *)((u8 *)v0 + 0) != 32768) {
    v0 = -2;
    return v0;
    }
    if (*(s16 *)((u8 *)v0 + 2) < 14) {
    v0 = -1;
    return v0;
    }
    v1 = *(u16 *)((u8 *)v0 + 16);
    v0 = 0;
    arg2->unk_0 = v1;
    return v0;
}
