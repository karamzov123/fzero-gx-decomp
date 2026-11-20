#include "types.h"
typedef u32 Sig_fn_8008D92C_file_handle;
typedef struct Sig_fn_8008D92C_FileMode {
    u32 open_mode : 2;
    u32 io_mode : 3;
    u32 buffer_mode : 2;
    u32 file_kind : 3;
    u32 file_orientation : 2;
    u32 binary_io : 1;
} Sig_fn_8008D92C_FileMode;
typedef union Sig_fn_8008D92C_FileModeWord {
    u32 value;
    Sig_fn_8008D92C_FileMode bits;
    u16 half[2];
} Sig_fn_8008D92C_FileModeWord;
typedef struct Sig_fn_8008D92C_FileState {
    u32 io_state : 3;
    u32 free_buffer : 1;
    u8 eof;
    u8 error;
} Sig_fn_8008D92C_FileState;
typedef u32 Sig_fn_8008D92C_file_position;
typedef void (*Sig_fn_8008D92C_IdleProc)(void);
typedef int (*Sig_fn_8008D92C_PositionProc)(Sig_fn_8008D92C_file_handle handle, Sig_fn_8008D92C_file_position *position, int mode, Sig_fn_8008D92C_IdleProc idle);
typedef int (*Sig_fn_8008D92C_IOProc)(Sig_fn_8008D92C_file_handle handle, u8 *buffer, u32 *count, Sig_fn_8008D92C_IdleProc idle);
typedef int (*Sig_fn_8008D92C_CloseProc)(Sig_fn_8008D92C_file_handle handle);
typedef struct Sig_fn_8008D92C_FILE {
    Sig_fn_8008D92C_file_handle handle;
    Sig_fn_8008D92C_FileModeWord mode;
    Sig_fn_8008D92C_FileState state;
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
    Sig_fn_8008D92C_PositionProc position_proc;
    Sig_fn_8008D92C_IOProc read_proc;
    Sig_fn_8008D92C_IOProc write_proc;
    Sig_fn_8008D92C_CloseProc close_proc;
    Sig_fn_8008D92C_IdleProc idle_proc;
    struct Sig_fn_8008D92C_FILE *next_file;
} Sig_fn_8008D92C_FILE;

extern u32 fn_8008A754(const char *);
extern u32 fn_8008CB28(u32, u32, u32, u32);

s32 fn_8008D92C(const char * arg0, Sig_fn_8008D92C_FileMode * arg1, Sig_fn_8008D92C_FILE * arg2) {
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
