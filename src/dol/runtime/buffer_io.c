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

extern int fflush(FILE *file);
extern void *fn_8007A1C0(unsigned long size);
extern void fn_8007A150(void *allocation);
extern u8 lbl_8015B200[256];

void __begin_critical_region(int region);
void __end_critical_region(int region);

int setvbuf(FILE *file, char *buffer, int mode, size_t size);
int __flush_buffer(FILE *file, size_t *bytes_flushed);
s32 fn_8007EC80(FILE *arg0, u32 *arg1, s32 arg2);
void __prep_buffer(FILE *buffer);

void __prep_buffer(FILE *buffer) {
    buffer->buffer_ptr = buffer->buffer;
    buffer->buffer_length = buffer->buffer_size;
    buffer->buffer_length -= buffer->position & buffer->buffer_alignment;
    buffer->buffer_position = buffer->position;
}

s32 fn_8007EC80(FILE *arg0, u32 *arg1, s32 arg2) {
    s32 result;

    arg0->buffer_ptr = arg0->buffer;
    arg0->buffer_length = arg0->buffer_size;
    arg0->buffer_length -= arg0->position & arg0->buffer_alignment;
    arg0->buffer_position = arg0->position;
    if (arg2 == 1) {
        arg0->buffer_length = arg0->buffer_size;
    }
    result = arg0->read_proc(arg0->handle, arg0->buffer, &arg0->buffer_length, arg0->idle_proc);
    if (result == 2) {
        arg0->buffer_length = 0;
    }
    if (arg1 != 0) {
        *arg1 = arg0->buffer_length;
    }
    if (result != 0) {
        return result;
    }
    arg0->position += arg0->buffer_length;
    return 0;
}

int __flush_buffer(FILE *file, size_t *bytes_flushed) {
    size_t buffer_len;
    int io_result;
    buffer_len = file->buffer_ptr - file->buffer;
    if (buffer_len != 0) {
        file->buffer_length = buffer_len;
        io_result =
            file->write_proc(file->handle, file->buffer, &file->buffer_length, file->idle_proc);
        if (bytes_flushed != 0)
            *bytes_flushed = file->buffer_length;
        if (io_result != 0)
            return io_result;
        file->position += file->buffer_length;
    }
    file->buffer_ptr = file->buffer;
    file->buffer_length = file->buffer_size;
    file->buffer_length -= file->position & file->buffer_alignment;
    file->buffer_position = file->position;
    return 0;
}

int setvbuf(FILE *file, char *buffer, int mode, size_t size) {
    int io_mode;
    io_mode = (file->mode.half[0] >> 6) & 7;
    if (mode == 0)
        fflush(file);
    if (file->state.io_state != 0 || io_mode == 0)
        return -1;
    if (mode != 0 && mode != 1 && mode != 2)
        return -1;
    if (file->buffer != 0 && file->state.free_buffer)
        fn_8007A150(file->buffer);
    __begin_critical_region(2);
    file->mode.bits.buffer_mode = mode;
    file->state.free_buffer = 0;
    file->buffer = (u8 *)&file->char_buffer;
    file->buffer_ptr = (u8 *)&file->char_buffer;
    file->buffer_size = 1;
    file->buffer_length = 0;
    file->buffer_alignment = 0;
    if (mode == 0 || size < 1) {
        *file->buffer_ptr = 0;
        __end_critical_region(2);
        return 0;
    }
    if (buffer == 0) {
        buffer = fn_8007A1C0(size);
        if (buffer == 0) {
            __end_critical_region(2);
            return -1;
        }
        file->state.free_buffer = 1;
    }
    file->buffer = (u8 *)buffer;
    file->buffer_ptr = file->buffer;
    file->buffer_size = size;
    file->buffer_alignment = 0;
    __end_critical_region(2);
    return 0;
}
