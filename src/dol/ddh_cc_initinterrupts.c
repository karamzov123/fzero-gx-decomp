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
u8 fn_8008D7B0(void);
#pragma dont_inline reset

void fn_8008D7C0(u32 arg0);

s32 fn_8008D7CC(u32 arg0, u32 arg1, s32 arg2);

s32 fn_8008D8A8(u32 arg0);

s32 fn_8008D92C(const char *arg0, FileMode *arg1, FILE *arg2);

s32 fn_8008DAA8(u32 arg0, u32 arg1, u32 *arg2);

s32 fn_8008DB5C(u32 arg0, u32 arg1, u32 *arg2);

s32 fn_8008DC10(void *arg0, void *arg1, u32 *arg2);



/* --- dol/fn_8008DCCC.c --- */
/* --- dol/fn_8008DCCC.c --- */

s32 fn_8008DCCC(u32 arg0, u32 arg1, u32 *arg2);

/* --- dol/udp_cc_post_stop.c --- */
/* --- dol/udp_cc_post_stop.c --- */
// udp_cc_post_stop: returns a constant.
int udp_cc_post_stop(void);

/* --- dol/udp_cc_pre_continue.c --- */
// udp_cc_pre_continue: returns a constant.
int udp_cc_pre_continue(void);

/* --- dol/udp_cc_peek.c --- */
// udp_cc_peek: returns a constant.
int udp_cc_peek(void);

/* --- dol/udp_cc_write.c --- */
// udp_cc_write: returns a constant.
int udp_cc_write(void);

/* --- dol/udp_cc_read.c --- */
// udp_cc_read: returns a constant.
int udp_cc_read(void);

/* --- dol/udp_cc_close.c --- */
// udp_cc_close: returns a constant.
int udp_cc_close(void);

/* --- dol/udp_cc_open.c --- */
// udp_cc_open: returns a constant.
int udp_cc_open(void);

/* --- dol/udp_cc_shutdown.c --- */
// udp_cc_shutdown: returns a constant.
int udp_cc_shutdown(void);

/* --- dol/udp_cc_initialize.c --- */
// udp_cc_initialize: returns a constant.
int udp_cc_initialize(void);

/* --- dol/ddh_cc_initinterrupts.c --- */
/* --- dol/ddh_cc_initinterrupts.c --- */
extern u32 fn_8008EEAC(void);

s32 ddh_cc_initinterrupts(void) {
    fn_8008EEAC();
    return 0;
}

/* --- dol/ddh_cc_peek.c --- */
extern s32 fn_8008EED8(void);
extern s32 fn_8008EFE0(void *data, s32 value);
extern u8 lbl_801A5E58[32];
extern void fn_8008E21C(u8 *table, void *data, s32 value);

s32 ddh_cc_peek(void) {
    u8 data[0x800];
    s32 value;
    
    value = fn_8008EED8();
    if (value <= 0) {
        return 0;
    }
    if (fn_8008EFE0(data, value) == 0) {
        fn_8008E21C(lbl_801A5E58, data, value);
    } else {
        return -0x2719;
    }
    return value;
}

/* --- dol/ddh_cc_post_stop.c --- */
extern u32 fn_8008F44C(void);

s32 ddh_cc_post_stop(void) {
    fn_8008F44C();
    return 0;
}

/* --- dol/ddh_cc_pre_continue.c --- */
extern u32 fn_8008F450(void);

s32 ddh_cc_pre_continue(void) {
    fn_8008F450();
    return 0;
}

/* --- dol/ddh_cc_write.c --- */
extern s32 lbl_801A6E08[2];
extern void MWTRACE(s32 level, const char *format, ...);
extern s32 fn_8008F29C(u8 *dst, s32 size);

s32 ddh_cc_write(u8 *dst, s32 size) {
    s32 left = size;
    u8 *current = dst;

    if (!lbl_801A6E08[0]) {
        MWTRACE(8, "cc not initialized\n");
        return -10001;
    }

    MWTRACE(8, "cc_write : Output data 0x%08x %ld bytes\n\000\000\000", dst, size);
    while (left > 0) {
        s32 written;

        MWTRACE(1, "cc_write sending %ld bytes\n", left);
        written = fn_8008F29C(current, left);
        if (written == 0) {
            break;
        }
        current += written;
        left -= written;
    }

    return 0;
}
