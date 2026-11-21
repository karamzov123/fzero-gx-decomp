#include "types.h"


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

int __flush_buffer(FILE *file, size_t *bytes_flushed);

int fn_8007B0B4(void);

long fn_8007FE70(FILE *file);

void fn_8007A150(void *allocation);

extern unsigned long __strtoul(int base, int max_width, int (*read_proc)(void *, int, int),
                                 void *read_context, int *chars_scanned, int *negative,
                                 int *overflow);

extern unsigned long long __strtoull(int base, int max_width, int (*read_proc)(void *, int, int),
                                      void *read_context, int *chars_scanned, int *negative,
                                      int *overflow);

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
        position = fn_8007FE70(file);
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

int fclose(FILE *file);

/* --- dol/fseek.c --- */
extern u32 __begin_critical_region(u32);
extern u32 __end_critical_region(u32);
extern u32 fn_8007FC34(u32, u32, u32);

u32 fseek(u32 arg0, u32 arg1, u32 arg2) {
    u32 result;

    __begin_critical_region(2);
    result = fn_8007FC34(arg0, arg1, arg2);
    __end_critical_region(2);
    return result;
}
