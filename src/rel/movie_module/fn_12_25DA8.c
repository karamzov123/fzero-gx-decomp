#include "types.h"

typedef struct MovieState {
    u8 pad_0000[0x0c];
    int start;
    int high;
    u8 pad_0014[0x08];
    int low;
    u8 pad_0020[0x04];
    int selected;
    u8 pad_0028[0x04];
    int current;
} MovieState;

typedef struct MovieModule {
    u8 pad_0000[0x1aec];
    MovieState *state;
    u8 pad_1af0[0x0c];
    void *stream;
} MovieModule;

typedef struct MovieResult {
    void *buffer;
    int start;
    void *second;
    int end;
    u32 unk10;
    int index;
    u8 pad_0018[0x08];
} MovieResult;

extern int fn_12_2D73C(MovieModule *, int);
extern int fn_12_224FC(MovieModule *, void *, MovieResult *);
extern void fn_12_57F0(void *, int, int);
extern int fn_12_22254(MovieModule *, void *, int, int);
extern int fn_12_2CF20(MovieModule *, void *, int *);

#pragma opt_dead_assignments off
static inline u32 fn_12_25DA8_operand(u32 right, u32 left) { return left & right; }
int fn_12_25DA8(MovieModule *module, int track, int offset, int length, int limit) {
    void * fzgx_live;
    MovieState *state;
    int delta;
    int index;
    MovieResult result;
    int status;
    void *result_second;
    int result_start;
    void *result_buffer;
    void *stream;
    int args[3];

    if (fn_12_2D73C(module, 6) == 0) {
        return 1;
    }

    state = module->state;
    if (state->current == -1) {
        state->current = track;
    }
    if (state->selected == -1) {
        state->selected = track;
    }

    index = fn_12_2D73C(module, 0x1e);
    if (index != -1) {
        if (fn_12_2D73C(module, 0x37) != 0) {
            { int __reg_value_delta = (state->low ^ track) >> 1; delta = __reg_value_delta; }
            delta -= fn_12_25DA8_operand((state->low), ((state->low ^ track)));
            { int __reg_value_delta = (u32)delta >> 31; delta = __reg_value_delta; }
        } else {
            { int __reg_value_delta = (state->selected - track) == 0; delta = __reg_value_delta; }
        }
        if (delta != 0) {
            state->current = index;
        }
    }

    state->low = track;
    if (state->current != track) {
        return 1;
    }

    if (limit >= 0) {
        int tmp = state->start;
        if (limit < tmp) {
            tmp = limit;
        }
        state->start = tmp;
        tmp = state->high;
        if (limit < tmp) {
            tmp = limit;
        }
        state->high = tmp;
        limit -= state->start;
    }

    stream = module->stream;
    status = fn_12_224FC(module, stream, &result);
    if (status != 0) {
        return status;
    }
    result_start = result.start;
    result_buffer = result.buffer;
    fzgx_live = result.second;
    result_second = fzgx_live;
    index = result.index;
    if (length > result_start + result.end) {
        return 0;
    }

    if (length <= result_start) {
        fn_12_57F0(result_buffer, offset, length);
    } else {
        fn_12_57F0(result_buffer, offset, result_start);
        fn_12_57F0(result_second, offset + result_start,
                   length - result_start);
    }

    status = fn_12_22254(module, stream, length, index);
    if (status != 0) {
        return status;
    }

    if (limit >= 0) {
        args[0] = limit;
        args[1] = (int)result_buffer;
        args[2] = length;
        status = fn_12_2CF20(module, stream, args);
        if (status != 0) {
            return status;
        }
    }
    return 1;
}
#pragma opt_dead_assignments reset

