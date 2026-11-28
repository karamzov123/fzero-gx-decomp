#include "types.h"

typedef void (*fn_12_6D5C_MovieCallback)(u32);

typedef struct fn_12_6D5C_MovieObject {
    fn_12_6D5C_MovieCallback callback0;
    union {
        u32 callback_arg0;
        fn_12_6D5C_MovieCallback callback1;
    };
    u32 callback_arg1;
    s32 state;
} fn_12_6D5C_MovieObject;

typedef void (*fn_12_6DE8_MovieCallback)(u32);

typedef struct MovieItem {
    s32 state;
    u8 pad_04[0xBC];
} MovieItem;

typedef struct fn_12_6DE8_MovieObject {
    fn_12_6DE8_MovieCallback callback0;
    union {
        u32 callback_arg0;
        fn_12_6DE8_MovieCallback callback1;
    };
    u32 callback_arg1;
    s32 count;
    MovieItem items[];
} fn_12_6DE8_MovieObject;
extern u32 lbl_12_bss_4DB0;
extern u32 lbl_12_bss_4DB8[2];
extern void fn_12_33428(u32 *dst, u32 value, u32 count);
extern void fn_12_6704(void);
extern void fn_12_6A88(void);

/* fzgx:begin fn_12_6A90 */
/* --- rel/movie_module/fn_12_6A90.c --- */
typedef struct fn_12_6A90_MovieModule_u1 {
    s32 state;
} fn_12_6A90_MovieModule_u1;

typedef struct fn_12_6A90_MovieError {
    void (*callback)(void *, s32);
    void *argument;
    s32 error;
} fn_12_6A90_MovieError;


static inline s32 fn_12_6A90_report_error(s32 unused, s32 error) {
    fn_12_6A90_MovieError *handler = (fn_12_6A90_MovieError *)lbl_12_bss_4DB8[0];
    handler->error = error;
    if (handler->callback != 0) {
        handler->callback(handler->argument, error);
    }
    return error;
}

s32 fn_12_6A90(fn_12_6A90_MovieModule_u1 *module) {
    s32 invalid;
    lbl_12_bss_4DB0 = (u32)module;
    if (module == 0) {
        invalid = -1;
    } else if (module->state == 1) {
        invalid = -1;
    } else {
        invalid = 0;
    }
    if (invalid != 0) {
        return fn_12_6A90_report_error(0, 0xff020103);
    }
    module->state = 1;
    return 0;
}
/* fzgx:end fn_12_6A90 */

/* fzgx:begin fn_12_6B28 */
/* --- rel/movie_module/fn_12_6B28.c --- */
/* --- rel/movie_module/fn_12_6B28.c --- */
typedef struct MovieEntry {
    s32 state;
    s32 unk04;
    s32 unk08;
    s32 unk0c;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1c;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2c;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3c;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4c;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5c;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6c;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7c;
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8c;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9c;
    s32 unka0;
    s32 unka4;
    s32 unka8;
    s32 unkac;
    s32 unkb0;
    s32 unkb4;
    s32 unkb8;
    s32 unkbc;
} MovieEntry;

typedef struct MovieModule {
    u8 unk00[0xc];
    s32 count;
    MovieEntry entries[1];
} MovieModule;

static inline MovieEntry *fn_12_6B28_find(MovieModule *module) {
    MovieEntry *entry;
    s32 i;

    entry = module->entries;
    for (i = 0; i < module->count; i++) {
        if (entry->state == 1) {
            return entry;
        }
        entry++;
    }
    return NULL;
}


MovieEntry *fn_12_6B28(void) {
    s32 i;
    MovieModule *module;
    MovieEntry *entry;

    module = (MovieModule *)((lbl_12_bss_4DB8)[0]);
    entry = fn_12_6B28_find(module);
    if (NULL == entry) {
        return NULL;
    }
    fn_12_33428( (u32 *)(void *)(entry), 0, 0x30);
    entry->state = 2;
    entry->unk04 = 0;
    entry->unk08 = 0;
    entry->unk0c = 0;
    entry->unk10 = 2;
    entry->unk14 = -1;
    entry->unk18 = -1;
    entry->unk1c = -1;
    entry->unk20 = -1;
    entry->unk24 = -1;
    entry->unk28 = -1;
    entry->unk2c = -1;
    entry->unk30 = -1;
    entry->unk34 = -1;
    entry->unk38 = -1;
    entry->unk3c = -1;
    entry->unk40 = -1;
    entry->unk44 = -1;
    entry->unk48 = -1;
    entry->unk4c = -1;
    entry->unk50 = -1;
    entry->unk54 = -1;
    entry->unk58 = -1;
    entry->unk5c = -1;
    entry->unk60 = -1;
    entry->unk64 = -1;
    entry->unk68 = -1;
    entry->unk6c = -1;
    entry->unk70 = -1;
    entry->unk74 = -1;
    entry->unk78 = -1;
    entry->unk7c = -1;
    entry->unk80 = -1;
    entry->unk84 = -1;
    entry->unk88 = -1;
    entry->unk8c = -1;
    entry->unk90 = -1;
    entry->unk94 = -1;
    entry->unk98 = -1;
    entry->unk9c = -1;
    entry->unka0 = -1;
    entry->unka4 = -1;
    entry->unka8 = -1;
    entry->unkac = -1;
    entry->unkb0 = -1;
    entry->unkb4 = -1;
    entry->unkb8 = -1;
    entry->unkbc = -1;
    return entry;
}
/* fzgx:end fn_12_6B28 */

/* fzgx:begin fn_12_6C78 */
/* --- rel/movie_module/fn_12_6C78.c --- */

s32 fn_12_6C78(u32 arg0) {
    u32 v0;
    u32 v1;
    lbl_12_bss_4DB0 = arg0;
    v0 = arg0;
    if (arg0 == 0) {
    v0 = -1;
    return v0;
    }
    v1 = *(u32 *)((u8 *)v0 + 0);
    v0 = (v1 - 1);
    v0 = ((s32)(~(v0 | (1 - v1))) >> 31);
    return v0;
}
/* fzgx:end fn_12_6C78 */

/* fzgx:begin fn_12_6CA8 */
/* --- rel/movie_module/fn_12_6CA8.c --- */
typedef void (*fn_12_6CA8_MovieCallback)(void *, s32);

typedef struct fn_12_6CA8_MovieModule_u1 {
    s32 state;
    fn_12_6CA8_MovieCallback callback;
    void *argument;
} fn_12_6CA8_MovieModule_u1;

typedef struct fn_12_6CA8_MovieError {
    fn_12_6CA8_MovieCallback callback;
    void *argument;
    s32 error;
} fn_12_6CA8_MovieError;


static inline s32 check_module(fn_12_6CA8_MovieModule_u1 *module) {
    s32 invalid;
    invalid = -1;
    if (module == NULL) {
        invalid = -1;
    } else if (module->state == 1) {
        invalid = -1;
    } else {
        invalid = 0;
    }
    return invalid;
}

static inline s32 fn_12_6CA8_report_error(s32 unused, s32 error) {
    fn_12_6CA8_MovieError *handler = (fn_12_6CA8_MovieError *)lbl_12_bss_4DB8[0];
    handler->error = error;
    if (handler->callback != 0) {
        handler->callback(handler->argument, error);
    }
    return error;
}

s32 fn_12_6CA8(fn_12_6CA8_MovieModule_u1 *module, fn_12_6CA8_MovieCallback callback, void *argument) {
    s32 invalid;

    if (module == 0) {
        fn_12_6CA8_MovieError *handler = (fn_12_6CA8_MovieError *)lbl_12_bss_4DB8[0];
        handler->callback = callback;
        handler->argument = argument;
    } else {
        lbl_12_bss_4DB0 = (u32)module;

        invalid = check_module(module);
        if (invalid != 0) {
            return fn_12_6CA8_report_error(0, 0xFF020101);
        }

        module->callback = callback;
        module->argument = argument;
    }
    return 0;
}
/* fzgx:end fn_12_6CA8 */

/* fzgx:begin fn_12_6D5C */


s32 fn_12_6D5C(fn_12_6D5C_MovieObject *movie, s32 value) {
    if (movie == 0) {
        movie = (*((fn_12_6D5C_MovieObject * *)&lbl_12_bss_4DB8));
        movie->callback_arg1 = value;
        if (value != 0) {
            if (movie->callback0 != 0) {
                movie->callback0(movie->callback_arg0);
            }
        }
    } else {
        movie->state = value;
        if (value != 0) {
            if (movie->callback1 != 0) {
                movie->callback1(movie->callback_arg1);
            }
        }
    }
    return value;
}
/* fzgx:end fn_12_6D5C */

/* fzgx:begin fn_12_6DE8 */


typedef struct fn_12_6DE8_MovieError {
    void (*callback)(void *, s32);
    void *argument;
    s32 error;
} fn_12_6DE8_MovieError;


static inline s32 fn_12_6DE8_check_item(MovieItem *item) {
    lbl_12_bss_4DB0 = (u32)item;
    if (item == NULL) {
        return -1;
    }
    if (item->state == 1) {
        return -1;
    }
    return 0;
}

static inline void fn_12_6DE8_report_error(s32 unused, s32 error) {
    fn_12_6DE8_MovieError *handler = (fn_12_6DE8_MovieError *)(*((fn_12_6DE8_MovieObject * *)&lbl_12_bss_4DB8));
    handler->error = error;
    if (handler->callback != 0) {
        handler->callback(handler->argument, error);
    }
}

void fn_12_6DE8(void) {
    MovieItem *item;
    s32 i;
    s32 count;
    count = (*((fn_12_6DE8_MovieObject * *)&lbl_12_bss_4DB8))->count;
    item = (*((fn_12_6DE8_MovieObject * *)&lbl_12_bss_4DB8))->items;
    for (i = 0; i < count; item++, i++) {
        if (item->state != 1) {
            if (fn_12_6DE8_check_item(item) != 0) {
                fn_12_6DE8_report_error(0, 0xFF020103);
            } else {
                item->state = 1;
            }
        }
    }
    fn_12_6704();
    fn_12_6A88();
}
/* fzgx:end fn_12_6DE8 */
