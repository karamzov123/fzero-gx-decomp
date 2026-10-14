/* Non-matching: best partial attempt (92.65% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieState MovieState;
typedef struct MovieTrack MovieTrack;
typedef struct MovieResource MovieResource;
typedef struct MovieModule MovieModule;

struct MovieState {
    u8 pad_00[0x118];
    s32 field_118;
};

struct MovieResource {
    u8 pad_00[0xc];
    s32 count;
    s32 value;
};

struct MovieTrack {
    void *iface;
    u8 pad_04[0x34];
    u8 *cursor;
    void (*callback)();
    s32 field_40;
};

struct MovieModule {
    u8 pad_00[0xcc0];
    MovieState state;
    u8 pad_ddc[0x1b74 - 0xddc];
    MovieTrack *track;
    u8 pad_1b78[0x2908 - 0x1b78];
    u8 *resource;
};

extern s32 fn_12_2EA6C(MovieState *, s32);
extern void fn_12_2E9E4(MovieState *, u32, u32);
extern s32 fn_12_2E9F0(MovieState *, s32, s32 *);
extern s32 fn_12_2D73C(u8 *, s32);
extern void fn_12_2D7DC(u8 *, s32, s32);
extern s32 fn_8004B974(u8 *, s32, u32 *);
extern s32 fn_8004B7F4(void *, s32, s32);
extern void fn_12_20F4C(MovieModule *, void *, int, int *);

static inline MovieTrack * fn_12_20CE8_read_pointer(MovieModule * owner) { return owner->track; }
#pragma opt_common_subs off
void fn_12_20CE8(MovieModule *module, u8 *arg1, s32 arg2, u32 *arg3) {
    u8 *ptr;
    struct { s32 value; } seek;
    s32 bytes;
    s32 offset;
    s32 limit;
    s32 stride;
    s32 remaining;
    struct {
    u8 lab_pad[8]; s32 value; } span;
    s32 end;
    s32 start;
    s32 value;
    s32 count;
    s32 status;
    MovieResource *res;
    s32 found;
    MovieState *state = &module->state;
    u32 tmp10;
    s32 tmpC;
    u32 tmp8;

    *arg3 = 0;

{
    MovieResource *res = (MovieResource *)module->resource;
    MovieTrack *track = fn_12_20CE8_read_pointer(module);

    if (res != 0 && track->field_40 <= 0) {
        res = (MovieResource *)((u8 *)res + 0xcfc);
    }

    if (res == 0) {
        status = -1;
    } else {
        count = res->count;
        value = res->value;
        status = 0;
    }

    if (status != 0) {
        track->callback = fn_12_20F4C;
        goto done;
    }

    start = fn_12_2EA6C(state, value);
    if (start < 0) {
        goto done;
    }

    if (fn_12_2D73C((u8 *)module, 5) == 0) {
        fn_12_2E9E4(state, start, value);
        track->callback = fn_12_20F4C;
        goto done;
    }

    end = fn_12_2E9F0(state, value, &tmpC);
    if (end < 0) {
        goto done;
    }
    fn_12_2E9E4(state, end, value);

    offset = 0;
    span.value = (end - start) - (s32)track->cursor;
    if (span.value < 0) {
        goto rewind;
    }

    found = 0;
    remaining = (span.value / 32) * count * 18;
    if (remaining > 0) {
        stride = count * 18;
        limit = remaining;
        if ((arg2 / stride) * count * 18 < limit) {
            limit = (arg2 / stride) * count * 18;
        }
{
    u8 * fzgx_loop_ptr_2570;
    s32 fzgx_loop_offset_2570;
        fzgx_loop_ptr_2570 = arg1;
        found = 0;
        fzgx_loop_offset_2570 = 0;
        while (fzgx_loop_offset_2570 < limit) {
            if (fn_8004B974(fzgx_loop_ptr_2570, 0x12, &tmp8) != 0) {
                found = 1;
                break;
            }
            fzgx_loop_ptr_2570 += 0x12;
            fzgx_loop_offset_2570 += 0x12;
        }
    ptr = fzgx_loop_ptr_2570;
    offset = fzgx_loop_offset_2570;
}
        track->cursor = track->cursor + (offset / stride) * 32;
        remaining = remaining - limit;
    }

    if (remaining > 0) {
        goto check;
    }
    if (((0) == (tmpC))) {
        goto check;
    }
    track->callback = fn_12_20F4C;
    found = fn_8004B974(arg1, arg2, &tmp10);

check:
    if (found != 0) {
        fn_12_2D7DC((u8 *)module, 6, 0);
    }
    goto done;

rewind:
    if (tmpC != 0) {
        bytes = ((32) * ((-span.value / 32)));
        if (bytes > 0) {
            seek.value = fn_8004B7F4(fn_12_20CE8_read_pointer(module)->iface, count, bytes);
            bytes = bytes - seek.value;
            track->cursor = track->cursor - seek.value;
        }
        if (bytes <= 0) {
            track->callback = fn_12_20F4C;
}
        }
    }

done:
    *arg3 = offset;
}
#pragma opt_common_subs reset
