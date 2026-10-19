#include "types.h"

typedef struct MovieTimeCode {
    u8 pad_0[8];
    s32 hours;
    s32 minutes;
    s32 seconds;
    s32 frames;
    s32 extra_frames;
} MovieTimeCode;

void fn_12_2E128(s32 scale, MovieTimeCode *time, s32 *result, s32 *out_scale) {
    *result = (time->hours * 107892 + time->minutes * 1798 + time->minutes / 10 * 2 + time->seconds * 30 +
               (time->frames + time->extra_frames)) * 1000;
    *out_scale = scale;
}
