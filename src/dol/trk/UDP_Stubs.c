#include "msl/file_callbacks.h"
#include "types.h"

typedef u32 file_handle;
typedef u32 file_position;

typedef struct FileMode {
    u32 open_mode : 2;
    u32 io_mode : 3;
    u32 buffer_mode : 2;
    u32 file_kind : 3;
    u32 file_orientation : 2;
    u32 binary_io : 1;
} FileMode;

typedef union FileModeWord {
    u32 value;
    FileMode bits;
    u16 half[2];
} FileModeWord;

typedef struct FileState {
    u32 io_state : 3;
    u32 free_buffer : 1;
    u8 eof;
    u8 error;
} FileState;

typedef void (*IdleProc)(void);
typedef int (*PositionProc)(file_handle handle, file_position *position, int mode, IdleProc idle);
typedef int (*IOProc)(file_handle handle, u8 *buffer, u32 *count, IdleProc idle);
typedef int (*CloseProc)(file_handle handle);

typedef struct FILE {
    file_handle handle;
    FileModeWord mode;
    FileState state;
    u8 is_dynamically_allocated;
    u8 char_buffer;
    u8 char_buffer_overflow;
    u8 ungetc_buffer[2];
    u16 ungetc_wide_buffer[2];
    u32 position;
    u8 *buffer;
    u32 buffer_size;
    u8 *buffer_ptr;
    u32 buffer_length;
    u32 buffer_alignment;
    u32 saved_buffer_length;
    u32 buffer_position;
    PositionProc position_proc;
    IOProc read_proc;
    IOProc write_proc;
    CloseProc close_proc;
    IdleProc idle_proc;
    struct FILE *next_file;
} FILE;

extern u8 lbl_801A5650[];
extern s32 fn_8008A754();
extern u8 fn_8008CB38(u32 arg0, u32 arg1, u32 arg2, u8 arg3);
extern u32 fn_8008CB30(u32, u32);
extern u32 fn_8008CB28(u32, u32, u32, u32);
extern u32 fn_8008CB20(u32, u32, u32 *, u32);
#pragma dont_inline on
u8 fn_8008D7B0(void) {
    return lbl_801A5650[0];
}
#pragma dont_inline reset

void fn_8008D7C0(u32 arg0) {
    lbl_801A5650[0] = arg0;
}

int fn_8008D7CC(u32 arg0, u32 *arg1, int arg2, void (*idle)(void)) {
    s32 mode;
    u8 value;

    mode = 0;
    if (fn_8008A754(arg0) == 0) {
        return 1;
    }

    if (arg2 == 0) {
        mode = 0;
    } else if (arg2 == 1) {
        mode = 1;
    } else if (arg2 == 2) {
        mode = 2;
    }

    value = fn_8008CB38(0xD4, arg0, (u32)arg1, mode);
    switch (value) {
    case 0:
        return 0;
    case 2:
        return 2;
    case 1:
    default:
        return 1;
    }
}

int fn_8008D8A8(u32 arg0) {
    u32 v0;
    u32 v1;
    u32 t0, t1;
    t0 = fn_8008A754(arg0);
    v0 = t0;
    if ((s32)t0 == 0) {
        v0 = 1;
    } else {
        v0 = 211;
        t1 = fn_8008CB30(v0, arg0);
        v0 = t1;
        v1 = (v0 & 0xFF);
        switch (v1) {
        case 0:
            v0 = 0;
            break;
        case 2:
            v0 = 2;
            break;
        default:
            v0 = 1;
        }
    }
    return v0;
}

s32 fn_8008D92C(const char *arg0, FileMode *arg1, FILE *arg2) {
    u32 v0;
    u8 v1;
    u32 v2;
    u32 v3;
    u32 v7;
    u32 t0;
    u32 t1;

    t0 = fn_8008A754(arg0);
    v0 = t0;
    if ((s32)t0 == 0) {
        v0 = 1;
    } else {
        u8 v5;
        v1 = *(u8 *)(arg1);
        v0 = *((u8 *)arg1 + 1);
        v2 = ((v1 >> 6) & 0x3);
        v3 = ((v1 >> 3) & 0x7);
        v0 = ((v0 >> 3) & 0x1);
        v5 = 0;
        switch (v2) {
        case 0:
            v5 |= 1;
            break;
        case 2:
            v5 |= 2;
            break;
        case 1:
            v5 |= 4;
            break;
        }
        switch (v3) {
        case 1:
            v5 |= 1;
            break;
        case 2:
            v5 |= 2;
            break;
        case 6:
            v5 |= 4;
            break;
        case 3:
            v5 |= 18;
            break;
        case 7:
            v5 |= 7;
            break;
        }
        if (v0 == 1) {
            v5 |= 8;
        }
        v0 = 210;
        t1 = fn_8008CB28(v0, (u32)arg0, v5, (u32)arg2);
        v0 = t1;
        v7 = (v0 & 0xFF);
        switch (v7) {
        case 0:
            v0 = 0;
            break;
        case 2:
            v0 = 2;
            break;
        default:
            v0 = 1;
            break;
        }
    }
    return v0;
}

int fn_8008DAA8(u32 arg0, u8 *arg1, size_t *arg2, void (*idle)(void)) {
    u32 v0;
    u32 v1;

    if (fn_8008A754(arg0) == 0) {
        return 1;
    }
    v0 = *arg2;
    v1 = fn_8008CB20(0xd0, arg0, &v0, (u32)arg1);
    *arg2 = v0;
    switch ((v1 & 0xff)) {
    case 0:
        return 0;
    case 2:
        return 2;
    default:
        return 1;
    }
}

int fn_8008DB5C(u32 arg0, u8 *arg1, size_t *arg2, void (*idle)(void)) {
    u32 v0;
    u32 v1;

    if (fn_8008A754(arg0) == 0) {
        return 1;
    }
    v0 = *arg2;
    v1 = fn_8008CB20(0xd1, arg0, &v0, (u32)arg1);
    *arg2 = v0;
    switch ((v1 & 0xff)) {
    case 0:
        return 0;
    case 2:
        return 2;
    default:
        return 1;
    }
}

s32 fn_8008DC10(void *arg0, void *arg1, u32 *arg2) {
    u32 v0;
    u32 v1;

    if (!fn_8008D7B0()) {
        return 1;
    }
    if (fn_8008A754() == 0) {
        return 1;
    }
    v0 = *arg2;
    v1 = fn_8008CB20(0xd0, 1, &v0, (u32)arg1);
    *arg2 = v0;
    switch ((v1 & 0xff)) {
    case 0:
        return 0;
    case 2:
        return 2;
    default:
        return 1;
    }
}



/* --- dol/fn_8008DCCC.c --- */
/* --- dol/fn_8008DCCC.c --- */

int fn_8008DCCC(u32 arg0, u8 *arg1, size_t *arg2, void (*idle)(void)) {
    u32 v0;
    u32 v1;

    if (fn_8008D7B0() == 0) {
        return 1;
    }
    if (fn_8008A754() == 0) {
        return 1;
    }
    v0 = *arg2;
    v1 = fn_8008CB20(0xd1, 0, &v0, (u32)arg1);
    *arg2 = v0;
    switch ((v1 & 0xff)) {
    case 0:
        return 0;
    case 2:
        return 2;
    default:
        return 1;
    }
}

/* --- dol/udp_cc_post_stop.c --- */
/* --- dol/udp_cc_post_stop.c --- */
// udp_cc_post_stop: returns a constant.
int udp_cc_post_stop(void) {
    return -1;
}

/* --- dol/udp_cc_pre_continue.c --- */
// udp_cc_pre_continue: returns a constant.
int udp_cc_pre_continue(void) {
    return -1;
}

/* --- dol/udp_cc_peek.c --- */
// udp_cc_peek: returns a constant.
int udp_cc_peek(void) {
    return 0;
}

/* --- dol/udp_cc_write.c --- */
// udp_cc_write: returns a constant.
int udp_cc_write(void) {
    return 0;
}

/* --- dol/udp_cc_read.c --- */
// udp_cc_read: returns a constant.
int udp_cc_read(void) {
    return 0;
}

/* --- dol/udp_cc_close.c --- */
// udp_cc_close: returns a constant.
int udp_cc_close(void) {
    return -1;
}

/* --- dol/udp_cc_open.c --- */
// udp_cc_open: returns a constant.
int udp_cc_open(void) {
    return -1;
}

/* --- dol/udp_cc_shutdown.c --- */
// udp_cc_shutdown: returns a constant.
int udp_cc_shutdown(void) {
    return -1;
}

/* --- dol/udp_cc_initialize.c --- */
// udp_cc_initialize: returns a constant.
int udp_cc_initialize(void) {
    return -1;
}
