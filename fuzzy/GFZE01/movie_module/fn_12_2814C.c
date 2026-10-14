/* Non-matching: best partial attempt (94.55% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_12_rodata_E10[36];
extern u8 lbl_12_rodata_C10[36];
extern s32 fn_12_334FC(s32, s32, s32);
extern u32 lbl_12_rodata_C54[9];
extern u32 lbl_12_rodata_C34[8];

typedef struct MovieTime {
    s32 pad[2];
    s32 hours;
    s32 minutes;
    s32 seconds;
    s32 frames;
} MovieTime;

void fn_12_2814C(s32 value, s32 index, s32 drop, s32 offset, MovieTime *out) {
    s32 rate;
    s32 divisor = ((s32 *)lbl_12_rodata_C10)[index];
    s32 count;
    s32 remainder;
    s32 minutes;
    s32 seconds;
    s32 frames;
    s32 *table;
    s32 hours;
    s32 blocks;
    rate = ((s32 *)lbl_12_rodata_E10)[index];

    count = fn_12_334FC(value, rate, 22500000) - offset;
    count = count > 0 ? count : 0;
    if (drop && (rate == 29970 || rate == 59940)) {
        table = rate == 29970 ? (s32 *)lbl_12_rodata_C34 : (s32 *)lbl_12_rodata_C54;
        hours = count / table[0];
        remainder = count % table[0];
        blocks = remainder / table[1];
        remainder %= table[1];
        if (remainder < table[2]) {
            minutes = 0;
            seconds = remainder / table[5];
            frames = remainder % table[5];
        } else {
            remainder -= (*((2) + (table)));
            minutes = remainder / table[3] + 1;
            remainder %= table[3];
            if (remainder < table[4]) {
                seconds = 0;
                frames = remainder + table[7];
            } else {
                remainder -= table[4];
                seconds = remainder / table[5] + 1;
                frames = remainder % table[5];
            }
        }
        minutes += table[6] * blocks;
    } else {
        s32 total = count / divisor;
        s32 totalMinutes = total / 60;
        frames = count % divisor;
        seconds = total % 60;
        hours = totalMinutes / 60;
        minutes = totalMinutes % 60;
    }
    out->hours = hours;
    out->minutes = minutes;
    out->seconds = seconds;
    out->frames = frames;
}
