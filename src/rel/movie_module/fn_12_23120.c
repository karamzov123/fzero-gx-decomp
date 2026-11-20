#include "types.h"


/* --- rel/movie_module/fn_12_23120.c --- */
extern void fn_12_24970(int *arg0);
extern void fn_12_24950(int *arg0);

typedef struct MovieModuleState {
    u8 pad_000[0x120];
    int field_120;
    int field_124;
    int field_128[32];
} MovieModuleState;

void fn_12_23120(void *arg0, int arg1) {
    MovieModuleState *state = (MovieModuleState *)((u8 *)arg0 + 0xcc0);
    int local;
    int next;
    int total;

    fn_12_24970(&local);
    state->field_120 += arg1;
    next = state->field_124;
    next = next + 1;
    total = state->field_120;
    state->field_128[next % 32] = total;
    state->field_124 = next;
    fn_12_24950(&local);
}

/* --- rel/movie_module/fn_12_231A0.c --- */
extern u32 fn_12_2D73C(u32, u32);

s32 fn_12_231A0(u32 arg0) {
    u32 v0;
    if ((s32)fn_12_2D73C(arg0, 49) != 0 || (s32)fn_12_2D73C(arg0, 57) != 0) {
    v0 = 1;
    } else {
    v0 = 0;
    }
    return v0;
}

/* --- rel/movie_module/fn_12_231F8.c --- */
s32 fn_12_231F8(u32 arg0) {
    u32 v0;
    if ((s32)fn_12_2D73C(arg0, 49) != 0 || (s32)fn_12_2D73C(arg0, 56) != 0) {
    v0 = 1;
    } else {
    v0 = 0;
    }
    return v0;
}

/* --- rel/movie_module/fn_12_23250.c --- */
u32 fn_12_23250(u32 arg0) {
    u32 t0;
    t0 = fn_12_2D73C(arg0, 49);
    return ((u32)((-t0) | t0) >> 31);
}

/* --- rel/movie_module/fn_12_23280.c --- */
extern int fn_12_24990(void);
extern int fn_12_24A88(int arg0, int arg1);
extern void fn_12_2D7DC(void *arg0, int arg1, int arg2);

int fn_12_23280(void *arg0) {
    if (fn_12_24990()) {
        return fn_12_24A88(0, 0xff000161);
    }
    fn_12_2D7DC(arg0, 0x31, 1);
    return 0;
}

/* --- rel/movie_module/fn_12_232DC.c --- */
extern u8 *fn_12_A0D8(u8 *data, int size, int mode);
extern u8 lbl_12_rodata_AB8[36];
extern u8 lbl_12_rodata_BD8[56];

typedef struct MovieInfo {
    u8 unk_000[8];
    u8 *field_008;
    u8 unk_00c[8];
    u32 field_014;
    u32 field_018;
    s32 field_01c;
    u32 field_020;
    u32 field_024;
} MovieInfo;

int fn_12_232DC(u8 *data, int size, MovieInfo *info) {
    u8 *entry;
    u8 b4;
    u8 b7;
    u8 b5;
    u8 b6;
    u8 b8;
    u8 b9;
    u8 b10;
    u8 b11;
    u8 raw[12];

    while (size > 0) {
        entry = fn_12_A0D8(data, size, 0x40);
        if (entry == NULL) {
            return 0;
        }
        b7 = entry[7];
{
    int offset;
        offset = entry - data;
        data = (u8 *)(offset + (u32)data);
        b4 = entry[4];
        b6 = entry[6];
        offset++;
        b5 = entry[5];
        b8 = entry[8];
        data++;
        b9 = entry[9];
        size -= offset;
}
        b10 = entry[10];
        b11 = entry[11];
        if (((0) == ((b7 >> 4)))) {
            continue;
        }
        b7 &= 0xf;
        if (b7 < 1 || b7 > 8) {
            continue;
        }
        if (((b10 >> 5) & 1) == 0) {
            continue;
        }
        info->field_014 = (b4 << 4) | (b5 >> 4);
        info->field_018 = ((b5 & 0xf) << 8) | b6;
        if (info->field_01c == 0) {
            info->field_01c = (((u32)b10 >> 6) | ((b8 << 10) | (b9 << 2))) * 50;
        }
        info->field_020 = *(u32 *)(lbl_12_rodata_AB8 + b7 * 4);
        info->field_024 = (((u32)b10 & 0x1f) << 5 | (b11 >> 3)) << 11;
        info->field_008 = lbl_12_rodata_BD8;
        break;
    }
    return 1;
}
