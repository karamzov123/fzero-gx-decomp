#include "types.h"

/* --- rel/movie_module/fn_12_9594.c --- */
typedef struct MovieBits {
    s32 field_0;
    u32 field_4;
    s32 field_8;
    u32 *field_c;
} MovieBits;

typedef struct MovieCode {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_c;
} MovieCode;

extern u32 lbl_12_bss_6924;
extern u32 lbl_12_bss_6920;

#pragma opt_lifetimes off
s32 fn_12_9594(MovieBits *state, MovieCode *code, s32 *out, s32 *base) {
    u32 bits;
    s32 count;
    u32 word;
    u32 *ptr;
    s32 ret;
    s32 value;
    s32 index;
    s32 shift;
    s32 nb;
    ret = 0;
    bits = state->field_0;
    count = state->field_8;
    word = state->field_4;
    ptr = (state->field_c);
    nb = code->field_4;
{
    s32 sg;
    sg = code->field_8;
    index = bits >> 21;
    if (count > 21)
        index |= word >> (53 - count);

    if (((u32)index >> 7) == 0)
        value = *(s16 *)(*(u32 *)&lbl_12_bss_6924 + ((u32)index << 1));
    else
        value = *(s16 *)(*(u32 *)&lbl_12_bss_6920 + (((u32)index >> 6) << 1));

{
    s32 token;
    token = (s8)value;
    index = token;
    if (token == 0x7f) {
        ret = -1;
    } else {
        shift = (u16)value >> 8;
        count += shift;
        if (count >= 0x20) {
            count -= 0x20;
            bits = word << count;
            word = *ptr++;
        } else {
            bits <<= shift;
        }
        if (index == 0) {
            *out = *base;
        } else {
            if (nb != 0) {
                if (count >= 0x20 - nb) {
                    count -= 0x20 - nb;
                    if (count != 0) {
                        bits |= word >> (nb - count);
                        value = bits >> (0x20 - nb);
                        bits = word << count;
                    } else {
                        value = bits >> (0x20 - nb);
                        bits = word;
                    }
                    shift = *ptr++;
                    word = shift;
                } else {
                    value = bits >> (0x20 - nb);
                    count += nb;
                    bits <<= nb;
                }
                token = code->field_c - 1 - value;
                index <<= nb;
                if (index > 0)
                    index -= token;
                else
                    index += token;
            }
            index += *base;
            *out = (index << sg) >> sg;
            *base = *out;
        }
        if (code->field_0 != 0)
            *out <<= 1;
    }
}
    }
    state->field_0 = bits;
    state->field_4 = word;
    state->field_8 = count;
    state->field_c = ptr;
    return ret;
}

#pragma opt_lifetimes reset

/* --- rel/movie_module/fn_12_9730.c --- */
/* --- rel/movie_module/fn_12_9730.c --- */
typedef struct MovieModule {
    u8 _pad0[0x318];
    u32 field_318;
    u32 field_31c;
    u32 field_320;
} MovieModule;

void fn_12_9730(MovieModule *module) {
    module->field_318 = 0x400;
    module->field_320 = 0x400;
    module->field_31c = 0x400;
}

/* --- rel/movie_module/fn_12_9744.c --- */
typedef struct MovieState {
    u8 _pad10[0x10];
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1c;
} MovieState;

void fn_12_9744(MovieState *movie) {
    movie->field_10 = 0;
    movie->field_14 = 0;
    movie->field_18 = 0;
    movie->field_1c = 0;
}
