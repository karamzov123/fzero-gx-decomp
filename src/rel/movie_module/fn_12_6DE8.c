#include "types.h"

typedef void (*MovieCallback)(u32);

typedef struct MovieItem {
    s32 state;
    u8 pad_04[0xBC];
} MovieItem;

typedef struct MovieObject {
    MovieCallback callback0;
    union {
        u32 callback_arg0;
        MovieCallback callback1;
    };
    u32 callback_arg1;
    s32 count;
    MovieItem items[];
} MovieObject;

typedef struct MovieError {
    void (*callback)(void *, s32);
    void *argument;
    s32 error;
} MovieError;

extern MovieObject *lbl_12_bss_4DB8;
extern u32 lbl_12_bss_4DB0;
extern void fn_12_6704(void);
extern void fn_12_6A88(void);

static inline s32 fn_12_6C78(MovieItem *item) {
    lbl_12_bss_4DB0 = (u32)item;
    if (item == NULL) {
        return -1;
    }
    if (item->state == 1) {
        return -1;
    }
    return 0;
}

static inline s32 fn_12_6D5C(MovieObject *movie, s32 value) {
    if (movie == NULL) {
        movie = lbl_12_bss_4DB8;
        movie->callback_arg1 = value;
        if (value != 0) {
            if (movie->callback0 != NULL) {
                movie->callback0(movie->callback_arg0);
            }
        }
    } else {
        movie->count = value;
        if (value != 0) {
            if (movie->callback1 != NULL) {
                movie->callback1(movie->callback_arg1);
            }
        }
    }
    return value;
}

static inline void report_error(s32 unused, s32 error) {
    MovieError *handler = (MovieError *)lbl_12_bss_4DB8;
    handler->error = error;
    if (handler->callback != 0) {
        handler->callback(handler->argument, error);
    }
}

void fn_12_6DE8(void) {
    MovieItem *item;
    s32 i;
    s32 count;
    count = lbl_12_bss_4DB8->count;
    item = lbl_12_bss_4DB8->items;
    for (i = 0; i < count; item++, i++) {
        if (item->state != 1) {
            if (fn_12_6C78(item) != 0) {
                report_error(0, 0xFF020103);
            } else {
                item->state = 1;
            }
        }
    }
    fn_12_6704();
    fn_12_6A88();
}
