#include "types.h"
extern const s32 lbl_12_rodata_E10[9];
extern const s32 lbl_12_rodata_C10[9];
extern s32 fn_12_334FC(s32, s32, s32);
extern u32 lbl_12_rodata_C54[9];
extern u32 lbl_12_rodata_C34[8];

void fn_12_2814C(s32 value, s32 index, s32 drop, s32 offset, s32 *out) {
    s32 rate;
    s32 scale;
    s32 frames;
    s32 fraction;
    s32 seconds;
    s32 rem;
    s32 minutes;
    s32 hours;
    s32 blocks;
    rate = ((s32 *)lbl_12_rodata_C10)[index];
    scale = ((s32 *)lbl_12_rodata_E10)[index];
    frames = fn_12_334FC(value, scale, 22500000) - offset;
    frames = frames > 0 ? frames : 0;
    if (drop && (scale == 29970 || scale == 59940)) {
        s32 *table = scale == 29970 ? (s32 *)lbl_12_rodata_C34 : (s32 *)lbl_12_rodata_C54;
        hours = frames / table[0];
        rem = frames % table[0];
        blocks = rem / table[1];
        rem %= table[1];
        if (rem < table[2]) {
            minutes = 0;
            seconds = rem / table[5];
            fraction = rem % table[5];
        } else {
            rem -= table[2];
            minutes = rem / table[3] + 1;
            rem %= table[3];
            if (rem < table[4]) {
                seconds = 0;
                fraction = rem + table[7];
            } else {
                rem -= table[4];
                seconds = rem / table[5] + 1;
                fraction = rem % table[5];
            }
        }
        minutes += table[6] * blocks;
    } else {
        seconds = frames / rate;
        fraction = frames % rate;
        minutes = seconds / 60;
        seconds %= 60;
        hours = minutes / 60;
        minutes %= 60;
    }
    out[2] = hours;
    out[3] = minutes;
    out[4] = seconds;
    out[5] = fraction;
}
