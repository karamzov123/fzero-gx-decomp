#include "types.h"


/* --- rel/movie_module/fn_12_A2C4.c --- */
u32 fn_12_A2C4(const u8 *data);

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

s32 fn_12_A660(MovieState *movie, s32 state) {
    if (movie == 0) {
        lbl_12_bss_4E60[2] = state;
        if (state != 0 && lbl_12_bss_4E60[0] != 0) {
            ((MovieCallback)lbl_12_bss_4E60[0])((void *)lbl_12_bss_4E60[1]);
        }
    } else {
        movie->field_228 = state;
        if (state != 0 && movie->callback != 0) {
            movie->callback(movie->callback_arg);
        }
    }
    return state;
}
