#include "types.h"


/* --- rel/movie_module/fn_12_2DFF0.c --- */
typedef struct MovieModule {
    u8 pad_0[0x920];
    s32 movie_index;
    u8 pad_924[0xF24 - 0x924];
    s32 total_a;
    u8 pad_F28[0xF48 - 0xF28];
    s32 total_b;
    u8 pad_F4C[0xF58 - 0xF4C];
    s32 total_c;
    s32 movie_id;
} MovieModule;

extern u32 lbl_12_rodata_E10[9];
extern u32 lbl_12_bss_7C64[137];
extern s32 UTY_MulDiv(s32 arg0, s32 arg1, s32 arg2);

void fn_12_2DFF0(MovieModule *module, s32 mode) {
    s32 value;
    s32 duration;
    s32 result;

    switch (mode) {
    case 0:
    case 1:
        break;
    case 2:
        if (module->movie_index == 0) {
            value = 0;
            duration = 0x7512;
        } else {
            value = 0x3e8;
            duration = lbl_12_rodata_E10[module->movie_index];
        }

        result = UTY_MulDiv(lbl_12_bss_7C64[0x6e], value, duration);
        module->total_a += result;
        module->total_b += result;
        result = UTY_MulDiv(module->movie_id, value, duration);
        module->total_c += result;
        break;
    }
}

/* --- rel/movie_module/fn_12_2E0B0.c --- */
typedef struct MovieTimeCode {
    u8 pad_0[8];
    s32 hours;
    s32 minutes;
    s32 seconds;
    s32 frames;
    s32 extra_frames;
} MovieTimeCode;

void fn_12_2E0B0(s32 scale, MovieTimeCode *time, s32 *result, s32 *out_scale) {
    *result = (time->hours * 215892 + time->minutes * 3598 + time->minutes / 10 * 2 + time->seconds * 60 +
               (time->frames + time->extra_frames)) * 1000;
    *out_scale = scale;
}

/* --- rel/movie_module/fn_12_2E128.c --- */
void fn_12_2E128(s32 scale, MovieTimeCode *time, s32 *result, s32 *out_scale) {
    *result = (time->hours * 107892 + time->minutes * 1798 + time->minutes / 10 * 2 + time->seconds * 30 +
               (time->frames + time->extra_frames)) * 1000;
    *out_scale = scale;
}

/* --- rel/movie_module/fn_12_2E1A0.c --- */
void fn_12_2E1A0(s32 scale, MovieTimeCode *time, s32 *result, s32 *out_scale) {
    *result = (time->hours * 86292 + time->minutes * 1438 + time->minutes / 10 * 2 + time->seconds * 24 +
               (time->frames + time->extra_frames)) * 1000;
    *out_scale = scale;
}

/* --- rel/movie_module/fn_12_2E218.c --- */
typedef struct FnEntry {
    u8 padding[8];
    s32 field_08;
    s32 field_0c;
    s32 field_10;
    s32 field_14;
    s32 field_18;
} FnEntry;

void fn_12_2E218(s32 value, FnEntry *entry, s32 *result, s32 *out) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    a = entry->field_0c * 3600000;
    b = entry->field_08 * 216000000;
    c = entry->field_10 * 60000;
    d = (entry->field_14 + entry->field_18) * 1000;
    *result = a + b + c + d;
    *out = 60000;
    *out = value;
}

/* --- rel/movie_module/fn_12_2E284.c --- */
void fn_12_2E284(s32 value, FnEntry *entry, s32 *result, s32 *out) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    a = entry->field_0c * 1800000;
    b = entry->field_08 * 108000000;
    c = entry->field_10 * 30000;
    d = (entry->field_14 + entry->field_18) * 1000;
    *result = a + b + c + d;
    *out = 30000;
    *out = value;
}

/* --- rel/movie_module/fn_12_2E2DC.c --- */
void fn_12_2E2DC(s32 value, FnEntry *entry, s32 *result, s32 *out) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    a = entry->field_0c * 1440000;
    b = entry->field_08 * 86400000;
    c = entry->field_10 * 24000;
    d = (entry->field_14 + entry->field_18) * 1000;
    *result = a + b + c + d;
    *out = 24000;
    *out = value;
}

/* --- rel/movie_module/fn_12_2E334.c --- */
typedef struct MovieTime {
    u8 padding0[8];
    s32 hours;
    s32 minutes;
    s32 seconds;
    s32 milliseconds;
    s32 extra;
} MovieTime;

void fn_12_2E334(s32 value, MovieTime *time, s32 *result, s32 *out_value) {
    s32 ms;
    s32 total;

    ms = (time->milliseconds + time->extra) * 0x3e8;
    total = time->minutes * 0x3c + time->hours * 0xe10 + time->seconds;
    *result = total * value + ms;
    *out_value = value;
}
