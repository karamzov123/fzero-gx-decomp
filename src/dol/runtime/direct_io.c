#include "types.h"

/* --- dol/runtime/direct_io.c --- */
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

void __stdio_atexit(void);
void __prep_buffer(FILE *file);
int __flush_buffer(FILE *file, size_t *bytes_flushed);
int fseek(FILE *file, u32 offset, int origin);
int fwide(FILE *file, int mode);
void *memcpy(void *destination, const void *source, unsigned long size);
extern void *__memrchr(const void *memory, int character, size_t count);
extern void __begin_critical_region(int);
extern void __end_critical_region(int);
extern s32 fn_8007B028(void);
extern s32 fn_8007EC80(FILE *, unsigned int *, s32);

size_t __fwrite(const void *data, size_t member_size, size_t member_count, FILE *file) {
    const u8 *current;
    size_t remaining;
    size_t transferred;
    size_t count;
    int buffered;
    if (fwide(file, 0) == 0) {
        fwide(file, -1);
    }
    remaining = member_size * member_count;
    if (remaining == 0 || file->state.error || file->mode.bits.file_kind == 0) {
        return 0;
    }
    if (file->mode.bits.file_kind == 2) {
        __stdio_atexit();
    }
    buffered = !file->mode.bits.binary_io || file->mode.bits.buffer_mode == 2 ||
               file->mode.bits.buffer_mode == 1;
    if (file->state.io_state == 0 && (file->mode.bits.io_mode & 2)) {
        if ((file->mode.bits.io_mode & 4) && fseek(file, 0, 2) != 0) {
            return 0;
        }
        file->state.io_state = 1;
        __prep_buffer(file);
    }
    if (file->state.io_state != 1) {
        file->state.error = 1;
        file->buffer_length = 0;
        return 0;
    }
    current = data;
    transferred = 0;
    if (remaining != 0 && (file->buffer_ptr != file->buffer || buffered)) {
        file->buffer_length = file->buffer_size - (file->buffer_ptr - file->buffer);
        do {
            const u8 *newline = 0;
            count = file->buffer_length;
            if (count > remaining) {
                count = remaining;
            }
            if (file->mode.bits.buffer_mode == 1 && count != 0) {
                newline = __memrchr(current, '\n', count);
                if (newline != 0) {
                    count = newline + 1 - current;
                }
            }
            if (count != 0) {
                memcpy(file->buffer_ptr, current, count);
                current += count;
                transferred += count;
                remaining -= count;
                file->buffer_ptr += count;
                file->buffer_length -= count;
            }
            if ((file->buffer_length == 0 || newline != 0 || file->mode.bits.buffer_mode == 0) &&
                __flush_buffer(file, 0) != 0) {
                file->state.error = 1;
                file->buffer_length = 0;
                remaining = 0;
                break;
            }
        } while (remaining != 0 && buffered);
    }
    if (remaining != 0 && !buffered) {
        u8 *saved_buffer = file->buffer;
        size_t saved_size = file->buffer_size;
        file->buffer = (u8 *)current;
        file->buffer_size = remaining;
        file->buffer_ptr = (u8 *)current + remaining;
        if (__flush_buffer(file, &count) != 0) {
            file->state.error = 1;
            file->buffer_length = 0;
        }
        transferred += count;
        file->buffer = saved_buffer;
        file->buffer_size = saved_size;
        __prep_buffer(file);
        file->buffer_length = 0;
    }
    if (file->mode.bits.buffer_mode != 2) {
        file->buffer_length = 0;
    }
    return (transferred + member_size - 1) / member_size;
}

size_t fwrite(const void *ptr, size_t size, size_t count, FILE *file) {
    size_t retval;
    __begin_critical_region(2);
    retval = __fwrite(ptr, size, count, file);
    __end_critical_region(2);
    return retval;
}

int fn_8007F13C(void *dst, unsigned long size, unsigned long count, FILE *file) {
    int flag;
    char *cursor;
    unsigned long total;
    unsigned long red;
    unsigned long savedbase;
    unsigned long savedsize;
    unsigned int chunk;
    int r;

    if (fwide(file, 0) == 0) {
        fwide(file, -1);
    }

    total = size * count;
    if (total == 0 || file->state.error != 0 || file->mode.bits.file_kind == 0) {
        return 0;
    }

    flag = 1;
    if (file->mode.bits.binary_io != 0 && file->mode.bits.buffer_mode != 2) {
        flag = 0;
    }

    if (file->state.io_state == 0 && (file->mode.bits.io_mode & 1) != 0) {
        file->state.io_state = 2;
        file->buffer_length = 0;
    }

    if (file->state.io_state < 2) {
        file->state.error = 1;
        file->buffer_length = 0;
        return 0;
    }

    if ((file->mode.bits.buffer_mode & 1) != 0 && fn_8007B028() != 0) {
        file->state.error = 1;
        file->buffer_length = 0;
        return 0;
    }

    cursor = (char *)dst;
    red = 0;

    if (total != 0 && file->state.io_state >= 3) {
        do {
            if (fwide(file, 0) == 1) {
                red += 2;
                total -= 2;
                *(unsigned short *)cursor =
                    *(unsigned short *)((char *)file + file->state.io_state * 2 + 0xC);
                cursor += 2;
            } else {
                red += 1;
                total -= 1;
                *cursor = *((char *)file + file->state.io_state + 0xC);
                cursor += 1;
            }
            file->state.io_state = file->state.io_state - 1;
        } while (total != 0 && file->state.io_state >= 3);

        if (file->state.io_state == 2) {
            file->buffer_length = file->saved_buffer_length;
        }
    }

    if (total != 0 && (file->buffer_length != 0 || flag != 0)) {
        do {
            if (file->buffer_length == 0) {
                r = fn_8007EC80(file, 0, 0);
                if (r != 0) {
                    if (r == 1) {
                        file->state.error = 1;
                        file->buffer_length = 0;
                    } else {
                        file->state.io_state = 0;
                        file->state.eof = 1;
                        file->buffer_length = 0;
                    }
                    total = 0;
                    break;
                }
            }
            chunk = file->buffer_length;
            if (chunk > total) {
                chunk = total;
            }
            memcpy(cursor, file->buffer_ptr, chunk);
            total -= chunk;
            cursor += chunk;
            red += chunk;
            file->buffer_ptr += chunk;
            file->buffer_length -= chunk;
        } while (total != 0 && flag != 0);
    }

    if (total != 0 && flag == 0) {
        savedbase = (unsigned long)file->buffer;
        savedsize = file->buffer_size;
        file->buffer = (u8 *)cursor;
        file->buffer_size = total;
        r = fn_8007EC80(file, &chunk, 1);
        if (r != 0) {
            if (r == 1) {
                file->state.error = 1;
                file->buffer_length = 0;
            } else {
                file->state.io_state = 0;
                file->state.eof = 1;
                file->buffer_length = 0;
            }
        }
        red += chunk;
        file->buffer = (u8 *)savedbase;
        file->buffer_size = savedsize;
        __prep_buffer(file);
        file->buffer_length = 0;
    }

    return red / size;
}

int fn_8007F48C(void *dst, unsigned long size, unsigned long count, FILE *file) {
    int result;

    __begin_critical_region(2);
    result = fn_8007F13C(dst, size, count, file);
    __end_critical_region(2);
    return result;
}
