#include "types.h"

typedef struct MovieModuleState MovieModuleState;
typedef s32 (*MovieCallback)(MovieModuleState *, s32 *, s32 *);

/* the block at handle+0xda4 (timer+0xe4): flag, then value and scale at +0x20/+0x24 */
typedef struct MovieModuleSnapshot {
    s32 unk_00;
    u8 unk_04[0x1c];
    s32 unk_20;
    s32 unk_24;
} MovieModuleSnapshot;

/* the timer block at handle+0xcc0 (fn_12_27478 reads the same block) */
typedef struct MovieModuleTimer {
    u8 unk_000[0xe4];
    MovieModuleSnapshot unk_e4;
    s32 unk_10c;
    s32 unk_110;
} MovieModuleTimer;

struct MovieModuleState {
    u8 unk_000[0xcc0];
    union {
        MovieCallback callbacks[1];
        MovieModuleTimer timer_state;
    } unk_cc0;
    u8 unk_dd4[0x134];
    s32 unk_f08;
    s32 unk_f0c;
};

extern void fn_12_24970(s32 *);
extern s32 fn_12_2D73C(MovieModuleState *, s32);
extern s32 fn_12_24950(s32 *);
extern s32 fn_12_2E6AC(MovieModuleState *, s32 *, s32 *);
unsigned int UTY_MulDiv(int multiplicand, int multiplier, int divisor);

#pragma use_lmw_stmw on

s32 fn_12_2E7C8(MovieModuleState *movie, s32 *time, s32 *unit) {
    s32 local;
    s32 state;
    s32 result;
    s32 index;
    struct { MovieCallback value; } callback;
    MovieModuleTimer *timer = &movie->unk_cc0.timer_state;
    MovieModuleSnapshot *snapshot = &timer->unk_e4;

    state = movie->unk_f08;
    if (state == -5) {
        fn_12_24970(&local);
        index = fn_12_2D73C(movie, 15);
        callback.value = movie->unk_cc0.callbacks[index];
        if (callback.value == 0) {
            callback.value = fn_12_2E6AC;
        }
        result = callback.value(movie, time, unit);
        fn_12_24950(&local);
    } else {
        *time = state;
        result = 0;
        *unit = movie->unk_f0c;
    }
    if (*unit == 1) {
        return result;
    }
    if (*unit == timer->unk_110) {
        *time += timer->unk_10c;
    } else if (snapshot->unk_00 != 0) {
        *time += UTY_MulDiv(snapshot->unk_20, *unit, snapshot->unk_24);
    }
    return result;
}
