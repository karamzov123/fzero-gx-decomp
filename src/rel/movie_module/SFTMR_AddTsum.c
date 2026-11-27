#include "types.h"
#include "sofdec/sfd.h"

/* --- rel/movie_module/SFTMR_AddTsum.c --- */
void SFTMR_AddTsum(SfdTimerSummary *summary, long long elapsed) {
    long long minimum;
    long long maximum;
    summary->total += elapsed;
    minimum = summary->minimum;
    if (elapsed < minimum) {
        minimum = elapsed;
    }
    summary->minimum = minimum;
    maximum = summary->maximum;
    elapsed = maximum < elapsed ? elapsed : maximum;
    summary->maximum = elapsed;
    summary->count++;
}

/* --- rel/movie_module/fn_12_2FE30.c --- */
struct fn_12_2FE30_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

void fn_12_2FE30(struct fn_12_2FE30_Arg0 *arg0) {
    arg0->unk_4 = 0;
    arg0->unk_0 = 0;
    arg0->unk_C = -1;
    arg0->unk_8 = (0x80000000 - 1);
    arg0->unk_14 = 0;
    arg0->unk_10 = 0;
    arg0->unk_18 = 0;
}
