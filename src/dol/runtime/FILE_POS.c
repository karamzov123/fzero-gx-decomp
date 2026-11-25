#include "types.h"

/* --- dol/fseek.c --- */
/* --- dol/fclose.c --- */
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

typedef int (*IOProc)(file_handle handle, u8 *buffer, size_t *count, IdleProc idle);

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

extern int __flush_buffer(FILE *file, u32 *bytes_flushed);
extern void __begin_critical_region(int region);
extern void __end_critical_region(int region);
extern int lbl_801A6DE0;

static inline long _ftell(FILE *file) {
    long position;
    u8 io_state;

    if ((file->mode.bits.file_kind != 1 && file->mode.bits.file_kind != 2) || file->state.error != 0) {
        lbl_801A6DE0 = 0x28;
        return -1;
    }
    io_state = file->state.io_state;
    if (io_state == 0) {
        return file->position;
    }
    position = file->buffer_position + (file->buffer_ptr - file->buffer);
    if (io_state >= 3) {
        position -= io_state - 2;
    }
    return position;
}

long ftell(FILE *file) {
    long retval;

    __begin_critical_region(2);
    retval = _ftell(file);
    __end_critical_region(2);
    return retval;
}

int _fseek(FILE *file, u32 offset, int file_mode) {
    file_position position;

    position = offset;
    if (file->mode.bits.file_kind != 1 || file->state.error != 0) {
        lbl_801A6DE0 = 0x28;
        return -1;
    }
    if (file->state.io_state == 1) {
        if (__flush_buffer(file, 0) != 0) {
            file->state.error = 1;
            file->buffer_length = 0;
            lbl_801A6DE0 = 0x28;
            return -1;
        }
    }
    if (file_mode == 1) {
        file_mode = 0;
        position += _ftell(file);
    }
    if (file_mode != 2 && file->mode.bits.io_mode != 3 &&
        (file->state.io_state == 2 || file->state.io_state == 3)) {
        if (position >= file->position || position < file->buffer_position) {
            file->state.io_state = 0;
        } else {
            file->buffer_ptr = file->buffer + (position - file->buffer_position);
            file->buffer_length = file->position - position;
            file->state.io_state = 2;
        }
    } else {
        file->state.io_state = 0;
    }
    if (file->state.io_state == 0) {
        if (file->position_proc != 0) {
            if (file->position_proc(file->handle, &position, file_mode, file->idle_proc) != 0) {
                file->state.error = 1;
                file->buffer_length = 0;
                lbl_801A6DE0 = 0x28;
                return -1;
            }
        }
        file->state.eof = 0;
        file->position = position;
        file->buffer_length = 0;
    }
    return 0;
}

int fseek(FILE *file, long offset, int file_mode) {
    int retval;

    __begin_critical_region(2);
    retval = _fseek(file, offset, file_mode);
    __end_critical_region(2);
    return retval;
}
