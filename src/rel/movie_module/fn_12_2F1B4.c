#include "types.h"
#pragma opt_propagation off

/* --- rel/movie_module/fn_12_2EDAC.c --- */
typedef struct MovieModuleState {
    u8 padding_000[0x250];
    int field_250;
    int field_254;
    int field_258;
    int field_25C;
} MovieModuleState;

void fn_12_2EDAC(MovieModuleState *state, int value);

/* --- rel/movie_module/fn_12_2EE48.c --- */
/* --- rel/movie_module/fn_12_2EE48.c --- */
typedef struct MovieModuleState_u1 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
} MovieModuleState_u1;

void fn_12_2EE48(MovieModuleState_u1 *state, int value);

/* --- rel/movie_module/fn_12_2EE7C.c --- */
extern s32 fn_12_2E6AC();
extern s32 fn_12_2E63C();
extern s32 fn_12_2E5E4();
extern u32 fn_12_2E490();
extern const f32 lbl_12_rodata_E8C;
struct fn_12_2EE7C_Arg0 { u8 pad_0[0xCC0]; u32 unk_CC0, unk_CC4, unk_CC8, unk_CCC, unk_CD0, unk_CD4; };
struct fn_12_2EE7C_Arg1 { u8 pad_0[0x18];
u32 unk_18;
u32 unk_1C;
u32 unk_20;
u32 unk_24;
u32 unk_28;
u32 unk_2C;
u32 unk_30;
u32 unk_34;
u32 unk_38;
u32 unk_3C;
u32 unk_40;
u32 unk_44;
u32 unk_48;
u32 unk_4C;
u32 unk_50;
u32 unk_54;
u32 unk_58;
u32 unk_5C;
u32 unk_60;
u32 unk_64;
u32 unk_68;
u32 unk_6C;
u32 unk_70;
u32 unk_74;
u32 unk_78;
u32 unk_7C;
u32 unk_80;
u32 unk_84;
u32 unk_88;
u32 unk_8C;
u32 unk_90;
u32 unk_94;
u32 unk_98;
u32 unk_9C;
u32 unk_A0;
u32 unk_A4;
u32 unk_A8;
u32 unk_AC;
u32 unk_B0;
u32 unk_B4;
u32 unk_B8;
u32 unk_BC;
u32 unk_C0;
u32 unk_C4;
u32 unk_C8;
u32 unk_CC;
u32 unk_D0;
u32 unk_D4;
u32 unk_D8;
u32 unk_DC;
u32 unk_E0;
u32 unk_E4;
u32 unk_E8;
u32 unk_EC;
u32 unk_F0;
u32 unk_F4;
u32 unk_F8;
u32 unk_FC;
u32 unk_100;
u32 unk_104;
u32 unk_108;
u32 unk_10C;
u32 unk_110;
u32 unk_114;
u32 unk_118;
u32 unk_11C;
u32 unk_120;
u32 unk_124;
u32 array_128[32];
u32 unk_1A8;
u32 unk_1AC;
u32 unk_1B0;
u32 unk_1B4;
u32 array_1B8[32];
u32 unk_238;
u32 unk_23C;
u32 unk_240;
u32 unk_244;
u32 unk_248;
u32 unk_24C;
u32 unk_250;
u32 unk_254;
u32 unk_258;
u32 unk_25C;
u32 unk_260;
u32 unk_264;
u32 unk_268;
u32 unk_26C;
u32 unk_270;
u32 unk_274;
u32 unk_278;
f32 unk_27C;
u32 unk_280;
f32 unk_284;
u32 unk_288;
u32 unk_28C;
u32 unk_290;
u32 unk_294;
u32 unk_298;
u32 unk_29C;
};
void fn_12_2EE7C(struct fn_12_2EE7C_Arg0 *arg0, struct fn_12_2EE7C_Arg1 *arg1);

/* --- rel/movie_module/fn_12_2F19C.c --- */
// fn_12_2F19C: empty in retail (single blr).
void fn_12_2F19C(void);

/* --- rel/movie_module/fn_12_2F1A0.c --- */
typedef struct MovieModuleState_u2 {
    int field_0;
    int field_4;
    int field_8;
} MovieModuleState_u2;

void fn_12_2F1A0(MovieModuleState_u2 *state, int value);

/* --- rel/movie_module/fn_12_2F1B4.c --- */
/* --- rel/movie_module/fn_12_2F1B4.c --- */
typedef struct MovieEntry {
    int field_0;
    char unk_4[0x40];
} MovieEntry;

typedef struct MovieModuleState_u3 {
    char unk_0[0x1aac];
    MovieEntry entries[1];
} MovieModuleState_u3;

int fn_12_2F1B4(MovieModuleState_u3 *state, int index) {
    return state->entries[index].field_0 != 0;
}

/* --- rel/movie_module/fn_12_2F1D0.c --- */
struct fn_12_2F1D0_E68_u32 { u32 unk_0; u8 pad_4[0x40]; };
struct fn_12_2F1D0_Arg0 {
    u8 pad_0[0x1AA4];
    struct fn_12_2F1D0_E68_u32 unk_1AA4[1];
};

u32 fn_12_2F1D0(struct fn_12_2F1D0_Arg0 *arg0, u32 arg1) {
    return arg0->unk_1AA4[arg1].unk_0;
}

/* --- rel/movie_module/fn_12_2F1E0.c --- */
struct MovieSlot {
    int value;
    char pad[0x40];
};

struct Movie {
    char pad[0x1aa4];
    struct MovieSlot slots[1];
};

void fn_12_2F1E0(struct Movie *movie, int index, int value) {
    movie->slots[index].value = value;
}

/* --- rel/movie_module/fn_12_2F1F0.c --- */
struct fn_12_2F1F0_E68_u32 { u32 unk_0; u8 pad_4[0x40]; };
struct fn_12_2F1F0_Arg0 {
    u8 pad_0[0x1AA0];
    struct fn_12_2F1F0_E68_u32 unk_1AA0[1];
};

u32 fn_12_2F1F0(struct fn_12_2F1F0_Arg0 *arg0, u32 arg1) {
    return arg0->unk_1AA0[arg1].unk_0;
}

/* --- rel/movie_module/fn_12_2F200.c --- */
/* --- rel/movie_module/fn_12_2F200.c --- */
struct MovieItem {
    int value;
    char pad[0x40];
};

struct Movie_u4 {
    char pad[0x1aa0];
    struct MovieItem items[1];
};

void fn_12_2F200(struct Movie_u4 *movie, int index, int value) {
    movie->items[index].value = value;
}

/* --- rel/movie_module/fn_12_2F210.c --- */
typedef u32 (*fn_12_2F210_Fn0)(u32, u32, u32, u32);

struct fn_12_2F210_arg0_1A90_E68 {
    u8 pad_0[0x1C];
    fn_12_2F210_Fn0 *unk_1C;
    u8 pad_20[0x24];
};

struct fn_12_2F210_Arg0 {
    u8 pad_0[0x1A90];
    struct fn_12_2F210_arg0_1A90_E68 unk_1A90[1];
};

u32 fn_12_2F210(struct fn_12_2F210_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    fn_12_2F210_Fn0 *callbacks;

    callbacks = arg0->unk_1A90[arg1].unk_1C;
    if (callbacks == 0) {
        return 0;
    }
    return callbacks[arg2]((u32)arg0, arg3, arg4, 0);
}

/* --- rel/movie_module/fn_12_2F264.c --- */
struct Movie_u5;

typedef int (*MovieHandler)(struct Movie_u5 *, int, int, int);

struct MovieItem_u5 {
    char pad0[0xc];
    MovieHandler *handlers;
    char pad1[0x30];
    char pad2[4];
};

struct Movie_u5 {
    char pad0[0x1aa0];
    struct MovieItem_u5 items[1];
};

int fn_12_2F264(struct Movie_u5 *movie, int index) {
    int i;
    int result;
    struct MovieItem_u5 *item;

    result = 0;
    item = movie->items;
    for (i = 0; i < 9; i++, item++) {
        if (item->handlers != 0) {
            result = item->handlers[index](movie, 0, 0, 0);
            if (result != 0) {
                break;
            }
        }
    }
    return result;
}

/* --- rel/movie_module/fn_12_2F2F4.c --- */
extern void fn_12_2D7DC(void *, int, int);

struct MovieItem_u6 {
    char pad0[8];
    void *field8;
    void *fieldC;
    void *field10;
    void *field14;
    char pad1[8];
    void *field20;
};

struct Movie_u6 {
    char pad0[0xB44];
    int fieldB44;
    int fieldB48;
    char pad1[0x644];
    int field1190;
    char pad2[0x6C];
    int field1200;
    int field1204;
    char pad3[0x6C];
    int field1274;
    int field1278;
    char pad4[0x6C];
    int field12E8;
    int field12EC;
    char pad5[0x6C];
    int field135C;
    int field1360;
    char pad6[0x6C];
    int field13D0;
    int field13D4;
    char pad7[0x6C];
    int field1444;
    int field1448;
    char pad8[0x6C];
    int field14B8;
    int field14BC;
    char pad9[0x634];
    int field1AF4;
    int field1AF8;
    int field1AFC;
    int field1B00;
    char pad10[0x34];
    int field1B38;
    int field1B3C;
    char pad11[0x3C];
    int field1B7C;
    int field1B80;
    char pad12[0x3C];
    int field1BC0;
    int field1BC4;
    char pad13[0x3C];
    int field1C04;
    int field1C08;
    char pad14[0x3C];
    int field1C48;
    char pad15[0x40];
    int field1C8C;
    char pad16[0x40];
    int field1CD0;
};

void fn_12_2F2F4(struct Movie_u6 *movie, struct MovieItem_u6 *item) {
    movie->field1190 = 1;
    movie->field1AF4 = 0;
    if (item->field8 != 0) {
        movie->field1AF8 = 1;
        movie->field1200 = 1;
        movie->field1204 = 2;
        movie->field1B38 = 1;
        movie->field1B3C = 3;
        movie->field12E8 = 2;
        if (item->field10 != 0) {
            movie->field12EC = 4;
            movie->field1BC0 = 3;
            movie->field1BC4 = 5;
            movie->field13D0 = 4;
            movie->field13D4 = 6;
            movie->field1C48 = 5;
        } else {
            movie->field12EC = 6;
            movie->field1C48 = 3;
        }
    } else {
        fn_12_2D7DC(movie, 5, 0);
        movie->fieldB44 = 0;
    }
    if (item->fieldC != 0) {
        movie->field1AFC = 2;
        movie->field1274 = 1;
        movie->field1278 = 3;
        movie->field1B7C = 2;
        movie->field1B80 = 4;
        movie->field135C = 3;
        if (item->field14 != 0) {
            movie->field1360 = 5;
            movie->field1C04 = 4;
            movie->field1C08 = 6;
            movie->field1444 = 5;
            movie->field1448 = 7;
            movie->field1C8C = 6;
        } else {
            movie->field1360 = 7;
            movie->field1C8C = 4;
        }
    } else {
        fn_12_2D7DC(movie, 6, 0);
        movie->fieldB48 = 0;
    }
    if (item->field20 != 0) {
        movie->field1B00 = 7;
        movie->field14B8 = 1;
        movie->field14BC = 8;
        movie->field1CD0 = 7;
    }
}
