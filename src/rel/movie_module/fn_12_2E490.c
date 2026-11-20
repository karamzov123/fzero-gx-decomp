#include "types.h"


/* --- rel/movie_module/fn_12_2E490.c --- */
typedef s32 (*MovieModuleCb)(void *self, u32 *out1, u32 *out2);

typedef struct MovieModuleEntry {
    u8 pad_0[0x48];
    s32 value;
    u8 pad_4c[4];
    s32 unk_50;
    u8 pad_54[0x910];
    s32 unk_964;
    u8 pad_968[0x5e8];
    MovieModuleCb unk_f50;
    volatile s32 unk_f54; /* retail emits a fresh load here instead of reusing the value compared against -5 */
    volatile s32 unk_f58; /* same: loaded in source order before the subtract, matching retail register order */
    s32 unk_f5c;
} MovieModuleEntry;

struct fn_12_2E490_Arg1 {
    u32 unk_0;
};
struct fn_12_2E490_Arg2 {
    u32 unk_0;
};

s32 fn_12_2E490(MovieModuleEntry *arg0, struct fn_12_2E490_Arg1 *arg1, struct fn_12_2E490_Arg2 *arg2) {
    u32 o2;
    u32 o1;
    s32 v;
    s32 w;
    s32 ret;
    if ((s32)arg0->value != 4 && (s32)arg0->value != -4 && (s32)arg0->value != 6 && (s32)arg0->value != -6) {
        arg1->unk_0 = -1;
        arg2->unk_0 = 1;
        v = 0;
    } else {
        v = 1;
    }
    if (v == 0) {
        return 0;
    }
    if (arg0->unk_f50 == 0) {
        arg1->unk_0 = -2;
        arg2->unk_0 = 1;
        return 0;
    }
    ret = arg0->unk_f50(arg0, &o2, &o1);
    if ((s32)arg0->value != 4) {
        w = 0;
    } else if (arg0->unk_50 != 0) {
        w = 0;
    } else if (arg0->unk_964 != 0) {
        w = 0;
    } else {
        w = 1;
    }
    if (w != 0) {
        if (arg0->unk_f54 != -5) {
            arg0->unk_f58 = arg0->unk_f58 + (o2 - arg0->unk_f54);
        }
    }
    arg0->unk_f54 = o2;
    arg0->unk_f5c = o1;
    arg1->unk_0 = arg0->unk_f58;
    arg2->unk_0 = arg0->unk_f5c;
    return ret;
}

/* --- rel/movie_module/fn_12_2E5E4.c --- */
struct fn_12_2E5E4_Arg0 {
    u8 pad_0[0x48];
    u32 unk_48;
};
struct fn_12_2E5E4_Arg1 {
    u32 unk_0;
};
struct fn_12_2E5E4_Arg2 {
    u32 unk_0;
};


s32 fn_12_2E5E4(struct fn_12_2E5E4_Arg0 *arg0, struct fn_12_2E5E4_Arg1 *arg1, struct fn_12_2E5E4_Arg2 *arg2) {
    u32 v0;
    s32 v1;
    v0 = arg0->unk_48;
    v1 = (u32)arg0;
    if ((s32)v0 != 4 && (s32)v0 != -4 && (s32)v0 != 6 && (s32)v0 != -6) {
    v1 = -1;
    arg1->unk_0 = v1;
    v1 = 0;
    arg2->unk_0 = 1;
    } else {
    v1 = 1;
    }
    if (v1 == 0) {
    v1 = 0;
    return v1;
    }
    v1 = 0;
    return v1;
}

/* --- rel/movie_module/fn_12_2E63C.c --- */
struct fn_12_2E63C_Arg0 {
    u8 pad_0[0x48];
    u32 unk_48;
};
struct fn_12_2E63C_Arg1 {
    u32 unk_0;
};
struct fn_12_2E63C_Arg2 {
    u32 unk_0;
};
struct fn_12_2E63C_lbl_12_bss_7C64 {
    u8 pad_0[0x1B8];
    u32 unk_1B8;
};

extern struct fn_12_2E63C_lbl_12_bss_7C64 lbl_12_bss_7C64;

s32 fn_12_2E63C(struct fn_12_2E63C_Arg0 *arg0, struct fn_12_2E63C_Arg1 *arg1, struct fn_12_2E63C_Arg2 *arg2, u32 arg3) {
    u32 v0;
    s32 v1;
    u32 v2;
    v0 = arg0->unk_48;
    v1 = arg3;
    if ((s32)v0 != 4 && (s32)v0 != -4 && (s32)v0 != 6 && (s32)v0 != -6) {
    v1 = -1;
    arg1->unk_0 = v1;
    v1 = 0;
    arg2->unk_0 = 1;
    } else {
    v1 = 1;
    }
    v2 = (u32)arg0;
    if (v1 == 0) {
    v2 = 0;
    return v2;
    }
    arg1->unk_0 = *(u32 *)((u8 *)v2 + 3876);
    arg2->unk_0 = lbl_12_bss_7C64.unk_1B8;
    return 0;
}

/* --- rel/movie_module/fn_12_2E6AC.c --- */
typedef struct MovieModuleState {
    u8 padding[0x48];
    s32 state;
} MovieModuleState;

s32 fn_12_2E6AC(MovieModuleState *movie, s32 *result, s32 *flag) {
    s32 valid;
    s32 state = movie->state;

    if (state != 4 && state != -4 && state != 6 && state != -6) {
        *result = -1;
        valid = 0;
        *flag = 1;
    } else {
        valid = 1;
    }

    if (valid == 0) {
        return 0;
    }

    *result = -2;
    valid = 0;
    *flag = 1;
    return valid;
}
