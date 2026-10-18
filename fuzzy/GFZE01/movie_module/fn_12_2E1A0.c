/* Non-matching: best partial attempt (99.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieTimeCode {
    u8 pad_0[8];
    s32 hours;
    s32 minutes;
    s32 seconds;
    s32 frames;
    s32 extra_frames;
} MovieTimeCode;

static inline s32 minute_frame_count(s32 minutes) {
    return minutes * 1438 + (minutes / 10) * 2;
}

#pragma opt_propagation off
#pragma opt_strength_reduction off
void fn_12_2E1A0(s32 scale, MovieTimeCode *time, s32 *result, s32 *out_scale) {
    s32 seconds;
    s32 extra;
    s32 frames;
    s32 minutes;
    s32 hour_frames;
    s32 minute_frames;
    s32 correction;
    s32 second_frames;
    s32 total;

    minutes = time->minutes;
    seconds = time->seconds;
    extra = time->extra_frames;
    frames = time->frames;
    correction = minutes / 10;
    hour_frames = time->hours * 86292;
    minute_frames = minutes * 1438;
    second_frames = seconds * 24;
    total = minute_frames + correction * 2;
    total += second_frames;
    total = hour_frames + total;
    total += extra;
    total = frames + total;
    *result = total * 1000;
    *out_scale = scale;
}
#pragma opt_strength_reduction reset
#pragma opt_propagation reset
