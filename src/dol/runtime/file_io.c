#include "types.h"

typedef struct FileMode {
    u32 open_mode : 2;
    u32 io_mode : 3;
    u32 buffer_mode : 2;
    u32 file_kind : 3;
    u32 file_orientation : 2;
    u32 binary_io : 1;
} FileMode;

/* MSL file_io.c: __get_file_modes */

enum { __must_exist, __create_if_necessary, __create_or_truncate };
enum { __read = 1, __write = 2, __read_write = 3, __append = 4 };
enum { __disk_file = 1 };
enum { __unoriented = 0 };

int fn_8007F508(const char *mode, FileMode *modes) {
    int ch;
    unsigned char open_mode;
    int io_mode;
    struct { const char *value; } next;

    modes->file_kind = __disk_file;
    modes->file_orientation = __unoriented;
    modes->binary_io = 0;

    switch (ch = *mode++) {
    case 'r':
        open_mode = __must_exist;
        break;
    case 'w':
        open_mode = __create_or_truncate;
        break;
    case 'a':
        open_mode = __create_if_necessary;
        break;
    default:
        return 0;
    }
    modes->open_mode = open_mode;

    next.value = mode;
    switch (*next.value++) {
    case 'b':
        modes->binary_io = 1;
        if (*next.value == '+') {
            ch = (ch << 8) | '+';
        }
        break;
    case '+':
        ch = (ch << 8) | '+';
        if (*next.value == 'b') {
            modes->binary_io = 1;
        }
        break;
    }

    switch (ch) {
    case 'r':
        io_mode = __read;
        break;
    case 'w':
        io_mode = __write;
        break;
    case 'a':
        io_mode = __write | __append;
        break;
    case ('r' << 8) | '+':
        io_mode = __read_write;
        break;
    case ('w' << 8) | '+':
        io_mode = __read_write;
        break;
    case ('a' << 8) | '+':
        io_mode = __read_write | __append;
        break;
    }
    modes->io_mode = io_mode;

    return 1;
}

/* --- dol/runtime/file_io.c --- */
typedef u32 file_handle;
typedef u32 file_position;

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

enum {
    FILE_KIND_CLOSED,
    FILE_KIND_DISK,
};

enum {
    IO_MODE_READ = 1,
    IO_MODE_WRITE = 2,
    IO_MODE_READ_WRITE = 3,
    IO_MODE_APPEND = 4,
};

enum {
    IO_STATE_NEUTRAL,
    IO_STATE_WRITING,
    IO_STATE_READING,
    IO_STATE_REREADING,
};

void __stdio_atexit(void);
int __flush_buffer(FILE *file, size_t *bytes_flushed);
int fn_8007B0B4(void);
void fn_8007B1CC(FILE *file, const FileMode *mode, char *buffer, size_t buffer_size);
FILE *fn_8007B2A8(void);
int fn_8008D92C(const char *name, FileMode *mode, FILE *file);
int fseek(FILE *file, u32 offset, int origin);
long ftell(FILE *file);
void fn_8008068C(FILE *file);
void fn_8007A150(void *allocation);

static inline int flush_file(FILE *file) {
    int position;
    if (file == 0) {
        return fn_8007B0B4();
    }
    if (file->state.error || file->mode.bits.file_kind == FILE_KIND_CLOSED) {
        return -1;
    }
    if (file->mode.bits.io_mode == IO_MODE_READ) {
        return 0;
    }
    if (file->state.io_state >= IO_STATE_REREADING) {
        file->state.io_state = IO_STATE_READING;
    }
    if (file->state.io_state == IO_STATE_READING) {
        file->buffer_length = 0;
    }
    if (file->state.io_state != IO_STATE_WRITING) {
        file->state.io_state = IO_STATE_NEUTRAL;
        return 0;
    }
    if (file->mode.bits.file_kind != FILE_KIND_DISK) {
        position = 0;
    } else {
        position = ftell(file);
    }
    if (__flush_buffer(file, 0) != 0) {
        file->state.error = 1;
        file->buffer_length = 0;
        return -1;
    }
    file->state.io_state = IO_STATE_NEUTRAL;
    file->position = position;
    file->buffer_length = 0;
    return 0;
}

static inline int close_file(FILE *file) {
    int flush_result;
    int close_result;
    if (file == 0) {
        return -1;
    }
    if (file->mode.bits.file_kind == FILE_KIND_CLOSED) {
        return 0;
    }
    flush_result = flush_file(file);
    close_result = file->close_proc(file->handle);
    file->mode.bits.file_kind = FILE_KIND_CLOSED;
    file->handle = 0;
    if (file->state.free_buffer) {
        fn_8007A150(file->buffer);
    }
    return flush_result || close_result ? -1 : 0;
}

FILE *fopen(const char *name, const char *mode_string) {
    FILE *file;
    FileMode open_mode;
    FileMode init_mode;
    FileMode mode;
    __begin_critical_region(2);
    file = fn_8007B2A8();
    __stdio_atexit();
    if (file == 0) {
        file = 0;
    } else {
        close_file(file);
        fn_8008068C(file);
        if (!fn_8007F508(mode_string, &mode)) {
            file = 0;
        } else {
            init_mode = mode;
            fn_8007B1CC(file, &init_mode, 0, 0x400);
            open_mode = mode;
            if (fn_8008D92C(name, &open_mode, file) != 0) {
                file->mode.bits.file_kind = FILE_KIND_CLOSED;
                if (file->state.free_buffer) {
                    fn_8007A150(file->buffer);
                }
                file = 0;
            } else if (mode.io_mode & IO_MODE_APPEND) {
                fseek(file, 0, 2);
            }
        }
    }
    __end_critical_region(2);
    return file;
}

int fflush(FILE *file) {
    int position;
    if (file == 0) {
        return fn_8007B0B4();
    }
    if (file->state.error || file->mode.bits.file_kind == FILE_KIND_CLOSED) {
        return -1;
    }
    if (file->mode.bits.io_mode == IO_MODE_READ) {
        return 0;
    }
    if (file->state.io_state >= IO_STATE_REREADING) {
        file->state.io_state = IO_STATE_READING;
    }
    if (file->state.io_state == IO_STATE_READING) {
        file->buffer_length = 0;
    }
    if (file->state.io_state != IO_STATE_WRITING) {
        file->state.io_state = IO_STATE_NEUTRAL;
        return 0;
    }
    if (file->mode.bits.file_kind != FILE_KIND_DISK) {
        position = 0;
    } else {
        position = ftell(file);
    }
    if (__flush_buffer(file, 0) != 0) {
        file->state.error = 1;
        file->buffer_length = 0;
        return -1;
    }
    file->state.io_state = IO_STATE_NEUTRAL;
    file->position = position;
    file->buffer_length = 0;
    return 0;
}

int fclose(FILE *file) {
    return close_file(file);
}
