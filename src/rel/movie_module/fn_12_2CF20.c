#include "types.h"

typedef struct MovieCmd {
    s32 f_0;
    s32 f_4;
    s32 f_8;
} MovieCmd;

typedef struct MovieEntry {
    u8 pad_00[0x1178];
    u8 *buffer;
    s32 capacity;
    s32 used;
    s32 tail;
} MovieEntry;

extern s32 fn_12_24A88(void *movie, s32 message);

s32 fn_12_2CF20(void *movie, s32 index, MovieCmd *cmd) {
    s32 fzgx_value;
    s32 result;
    MovieEntry *entry;
    s32 value;
    s32 v4;
    s32 tail;
    u8 *buffer;
    struct { s32 value; } next;
    s32 cap;
    struct { s32 value; } newtail;

    value = cmd->f_0;
    if (value < 0) {
        return 0;
    }
    entry = (MovieEntry *)((u8 *)movie + index * 0x74);
    buffer = entry->buffer;
    if (buffer == 0) {
        return 0;
    }
    if (entry->used == entry->capacity) {
        result = -1;
    } else {
        tail = entry->tail;
        v4 = cmd->f_4;
        {
            MovieCmd *slot;
            slot = (MovieCmd *)((u8 *)buffer + tail * 0xc);
            fzgx_value = value;
            *slot = *cmd;
        }
        next.value = tail;
        next.value = next.value + 1;
        cap = entry->capacity;
        newtail.value = next.value - cap;
        if (next.value < cap) {
            newtail.value = next.value;
        }
        entry->used = entry->used + 1;
        entry->tail = newtail.value;
        result = 0;
    }
    if (result == -1) {
        return fn_12_24A88(movie, 0xFF000421);
    }
    return 0;
}
