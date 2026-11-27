#include "types.h"

/* fzgx:begin fn_12_A660 noprologue */
#include "types.h"

#define SKIP(n) do { bits += (n); if (bits >= 32) { bits -= 32; current = next << bits; next = *p++; } else current <<= (n); } while(0)
#define PEEK(n, dst) do { dst = current >> (32-(n)); if (bits > 32-(n)) dst |= next >> (64-(n)-bits); } while(0)
#define ONE(dst) do { dst = current >> 31; if (bits == 31) { current = next; next = *p++; bits = 0; } else { current <<= 1; bits++; } } while(0)

/* --- rel/movie_module/fn_12_A660.c --- */
extern u32 lbl_12_bss_4E60[6];

typedef void (*MovieCallback)(void *);

typedef struct MovieState {
    u8 pad_0[0x220];
    MovieCallback callback;
    void *callback_arg;
    s32 field_228;
} MovieState;

s32 fn_12_A660(MovieState *movie, s32 state) {
    if (movie == 0) {
        lbl_12_bss_4E60[2] = state;
        if (state != 0 && lbl_12_bss_4E60[0] != 0) {
            ((MovieCallback)lbl_12_bss_4E60[0])((void *)lbl_12_bss_4E60[1]);
        }
    } else {
        movie->field_228 = state;
        if (state != 0 && movie->callback != 0) {
            movie->callback(movie->callback_arg);
        }
    }
    return state;
}
/* fzgx:end fn_12_A660 */

/* fzgx:begin fn_12_A6E8 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_A6E8.c --- */
typedef struct MPVContext MPVContext;

typedef void (*MPVErrorCallback)(int object, int error);

typedef struct MPVErrorInfo {
    union {
        unsigned char padding_extent[20];
        struct {
            MPVErrorCallback callback;
        } view_callback;
        struct {
            unsigned char padding_callback_object[4];
            int callback_object;
        } view_callback_object;
        struct {
            unsigned char padding_first_error[8];
            int first_error;
        } view_first_error;
    } fields;
} MPVErrorInfo;

struct MPVContext {
    union {
        unsigned char padding_extent[4992];
        struct {
            unsigned char padding_error_info[544];
            MPVErrorInfo error_info;
        } view_error_info;
    } fields;
};

int MPVERR_SetCode(MPVContext *handle, int error);

int fn_12_CAB4(MPVContext *handle);

extern int fn_12_CAB4(MPVContext *handle);

extern MPVErrorInfo lbl_12_bss_4E60;

static inline int MPVERR_SetCode(MPVContext *handle, int error) {
    if (handle == 0) {
        lbl_12_bss_4E60.fields.view_first_error.first_error = error;
        if (error != 0 && lbl_12_bss_4E60.fields.view_callback.callback != 0) {
            lbl_12_bss_4E60.fields.view_callback.callback(
                lbl_12_bss_4E60.fields.view_callback_object.callback_object, error);
        }
    } else {
        handle->fields.view_error_info.error_info.fields.view_first_error.first_error = error;
        if (error != 0 &&
            handle->fields.view_error_info.error_info.fields.view_callback.callback != 0) {
            handle->fields.view_error_info.error_info.fields.view_callback.callback(
                handle->fields.view_error_info.error_info.fields.view_callback_object
                    .callback_object,
                error);
        }
    }
    return error;
}

int fn_12_A6E8(MPVContext *handle, MPVErrorCallback callback, int object) {
    if (fn_12_CAB4(handle) != 0) {
        return MPVERR_SetCode(0, 0xFF030203);
    }
    handle->fields.view_error_info.error_info.fields.view_callback.callback = callback;
    handle->fields.view_error_info.error_info.fields.view_callback_object.callback_object = object;
    return 0;
}
/* fzgx:end fn_12_A6E8 */

/* fzgx:begin fn_12_A774 noprologue */

/* --- rel/movie_module/fn_12_A774.c --- */
typedef struct MovieState {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
} MovieState;

void fn_12_A774(MovieState *movie) {
    movie->field_0 = 0;
    movie->field_4 = 0;
    movie->field_8 = 0;
    movie->field_c = 0;
    movie->field_10 = 0;
}
/* fzgx:end fn_12_A774 */

/* fzgx:begin fn_12_A790 noprologue */
#include "types.h"

extern u32 lbl_12_bss_4E60[6];

void fn_12_A790(void) {
    lbl_12_bss_4E60[0] = 0;
    lbl_12_bss_4E60[1] = 0;
    lbl_12_bss_4E60[2] = 0;
    lbl_12_bss_4E60[3] = 0;
    lbl_12_bss_4E60[4] = 0;
}
/* fzgx:end fn_12_A790 */
