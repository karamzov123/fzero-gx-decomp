#include "types.h"

typedef u32 Sig_setvbuf_file_handle;
typedef struct Sig_setvbuf_FileMode {
    u32 open_mode : 2;
    u32 io_mode : 3;
    u32 buffer_mode : 2;
    u32 file_kind : 3;
    u32 file_orientation : 2;
    u32 binary_io : 1;
} Sig_setvbuf_FileMode;
typedef struct Sig_setvbuf_FileState {
    u32 io_state : 3;
    u32 free_buffer : 1;
    u8 eof;
    u8 error;
} Sig_setvbuf_FileState;
typedef void (*Sig_setvbuf_IdleProc)(void);
typedef s32 (*Sig_setvbuf_PositionProc)(u32, u32, s32);
typedef s32 (*Sig_setvbuf_IOProc)(u32, u32, u32 *);
typedef s32 (*Sig_setvbuf_CloseProc)(u32);
typedef struct Sig_setvbuf_FILE {
    Sig_setvbuf_file_handle handle;
    Sig_setvbuf_FileMode mode;
    Sig_setvbuf_FileState state;
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
    Sig_setvbuf_PositionProc position_proc;
    Sig_setvbuf_IOProc read_proc;
    Sig_setvbuf_IOProc write_proc;
    Sig_setvbuf_CloseProc close_proc;
    Sig_setvbuf_IdleProc idle_proc;
    struct Sig_setvbuf_FILE *next_file;
} Sig_setvbuf_FILE;

extern int setvbuf(Sig_setvbuf_FILE *, char *, int, size_t);
extern s32 fn_8008D7CC(u32, u32, s32);
extern s32 fn_8008DB5C(u32, u32, u32 *);
extern s32 fn_8008DAA8(u32, u32, u32 *);
extern s32 fn_8008D8A8(u32);

void fn_8007B1CC(Sig_setvbuf_FILE *file, Sig_setvbuf_FileMode mode, char *buf, u32 size) {
    file->handle = 0;
    file->mode = mode;
    file->state.io_state = 0;
    file->state.free_buffer = 0;
    file->state.eof = 0;
    file->state.error = 0;
    file->position = 0;
    if (size != 0) {
        setvbuf(file, buf, 2, size);
    } else {
        setvbuf(file, 0, 0, 0);
    }
    file->buffer_ptr = file->buffer;
    file->buffer_length = 0;
    if (file->mode.file_kind == 1) {
        file->position_proc = fn_8008D7CC;
        file->read_proc = fn_8008DB5C;
        file->write_proc = fn_8008DAA8;
        file->close_proc = fn_8008D8A8;
    }
    file->idle_proc = 0;
}


