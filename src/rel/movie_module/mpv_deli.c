#include "types.h"

/* --- rel/movie_module/fn_12_A0D8.c --- */
u32 fn_12_A2C4(const u8 *data);

#pragma opt_common_subs off
u8 *fn_12_A0D8(u8 *data, s32 size, u32 mask) {
    u8 *end = data + size;
    u8 c;
    s32 state = 0;

    while (data < end) {
        c = *data++;
        switch (state) {
        case 0:
            if ((s8)c == 0) {
                state = 1;
            }
            break;
        case 1:
            if ((s8)c == 0) {
                state = 2;
            } else {
                state = 0;
            }
            break;
        case 2:
            if ((s8)c == 1) {
                state = 3;
            } else if ((s8)c != 0) {
                state = 0;
            }
            break;
        case 3:
            if (fn_12_A2C4(data - 4) & mask) {
                return data - 4;
            }
            state = 0;
            break;
        default:
            break;
        }
    }
    return 0;
}
#pragma opt_common_subs reset

/* --- rel/movie_module/fn_12_A1C4.c --- */
char *fn_12_A1C4(char *text, s32 length, u32 mask) {
    char *limit = text - length;
    char c;
    s32 state = 0;

    while (limit < text) {
        c = *--text;

        switch (state) {
        case 0:
            state = 1;
            break;
        case 1:
            if (c == 1) {
                state = 2;
            }
            break;
        case 2:
            if (c == 0) {
                state = 3;
            } else if (c != 1) {
                state = 1;
            }
            break;
        case 3:
            if (c == 0) {
                if (mask & fn_12_A2C4((const unsigned char *)text)) {
                    return text;
                }
                state = 0;
            } else if (c != 1) {
                state = 1;
            } else {
                state = 2;
            }
            break;
        }
    }

    return 0;
}

/* --- rel/movie_module/fn_12_A2C4.c --- */
/* --- rel/movie_module/fn_12_A2C4.c --- */
u32 fn_12_A2C4(const u8 *data) {
    s32 value = (data[0] << 8) | data[1];
    u32 result;

    value <<= 8;
    value |= data[2];
    value <<= 8;
    value |= data[3];

    if (value == 0x100) {
        result = 4;
    } else if (value == 0x101) {
        result = 3;
    } else if (value > 0x101 && value <= 0x1AF) {
        result = 1;
    } else if (value == 0x1B2) {
        result = 0x20;
    } else if (value == 0x1B3) {
        result = 0x40;
    } else if (value == 0x1B5) {
        result = 0x10;
    } else if (value == 0x1B7) {
        result = 0x80;
    } else if (value == 0x1B8) {
        result = 8;
    } else {
        result = 0;
    }
    return result;
}

/* --- rel/movie_module/fn_12_A374.c --- */
extern u8 lbl_12_data_68[72];
#define SKIP(n) do { bits += (n); if (bits >= 32) { bits -= 32; current = next << bits; next = *p++; } else current <<= (n); } while(0)
#define PEEK(n, dst) do { dst = current >> (32-(n)); if (bits > 32-(n)) dst |= next >> (64-(n)-bits); } while(0)
#define ONE(dst) do { dst = current >> 31; if (bits == 31) { current = next; next = *p++; bits = 0; } else { current <<= 1; bits++; } } while(0)
s32 fn_12_A374(s32 arg0, s32 length, s32 count);

/* --- rel/movie_module/fn_12_A660.c --- */
extern u32 lbl_12_bss_4E60[6];

typedef void (*MovieCallback)(void *);

typedef struct MovieState {
    u8 pad_0[0x220];
    MovieCallback callback;
    void *callback_arg;
    s32 field_228;
} MovieState;

s32 fn_12_A660(MovieState *movie, s32 state);
