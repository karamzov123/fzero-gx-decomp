#include "types.h"
#include "msl/file_callbacks.h"

typedef u32 AnsiHandle;
typedef struct FileMode {
    u32 open_mode : 2;
    u32 io_mode : 3;
    u32 buffer_mode : 2;
    u32 file_kind : 3;
    u32 file_orientation : 2;
    u32 binary_io : 1;
} FileMode;
typedef struct FileState {
    u32 io_state : 3;
    u32 free_buffer : 1;
    u8 eof;
    u8 error;
} FileState;
typedef void (*IdleProc)(void);
typedef int (*PositionProc)(u32, u32 *, int, IdleProc);
typedef int (*IOProc)(u32, u8 *, size_t *, IdleProc);
typedef int (*CloseProc)(u32);
typedef struct AnsiFile {
    AnsiHandle handle;
    FileMode mode;
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
    struct AnsiFile *next_file;
} AnsiFile;

extern u8 lbl_801A33B8[256];
extern u8 lbl_801A34B8[256];
extern u8 lbl_801A35B8[256];

/* The retail table contains the three console streams and a zeroed spare. */
AnsiFile __files[4] __attribute__((aligned(8))) = {
    {0, {0, 1, 1, 2, 0, 0}, {0}, 0, 0, 0, {0}, {0}, 0,
     lbl_801A35B8, sizeof(lbl_801A35B8), lbl_801A35B8, 0, 0, 0, 0,
     0, fn_8008DCCC, fn_80085814, fn_8008580C, 0, &__files[1]},
    {1, {0, 2, 1, 2, 0, 0}, {0}, 0, 0, 0, {0}, {0}, 0,
     lbl_801A34B8, sizeof(lbl_801A34B8), lbl_801A34B8, 0, 0, 0, 0,
     0, fn_8008DCCC, fn_80085814, fn_8008580C, 0, &__files[2]},
    {2, {0, 2, 0, 2, 0, 0}, {0}, 0, 0, 0, {0}, {0}, 0,
     lbl_801A33B8, sizeof(lbl_801A33B8), lbl_801A33B8, 0, 0, 0, 0,
     0, fn_8008DCCC, fn_80085814, fn_8008580C, 0, &__files[3]},
    {0}
};

extern void __begin_critical_region(s32);
extern void __end_critical_region(s32);
extern void fclose(AnsiFile *);
extern s32 fflush(AnsiFile *);
extern void *fn_8007A1C0(u32);
extern void fn_8007A150(void *);
extern void *memset(void *, int, u32);
extern int setvbuf(AnsiFile *, char *, int, size_t);

s32 fn_8007B028(void);
s32 fn_8007B0B4(void);
void __close_all(void);
void fn_8007B1CC(AnsiFile *file, FileMode mode, char *buf, u32 size);
AnsiFile *fn_8007B2A8(void);

AnsiFile *fn_8007B2A8(void) {
    AnsiFile *file;
    AnsiFile *created;
    AnsiFile *last;

    file = __files[2].next_file;
    while (file != 0) {
        if (!(file->mode.file_kind != 0)) {
            return file;
        } else {
            last = file;
            file = file->next_file;
        }
    }
    created = fn_8007A1C0(0x50);
    if (created != 0) {
        memset(created, 0, 0x50);
        created->is_dynamically_allocated = 1;
        last->next_file = created;
        return created;
    }
    return 0;
}

void fn_8007B1CC(AnsiFile *file, FileMode mode, char *buf, u32 size) {
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

void __close_all(void) {
    AnsiFile *file;

    file = __files;
    __begin_critical_region(2);
    while (file != 0) {
        if (file->mode.file_kind != 0) {
            fclose(file);
        }
        {
            AnsiFile *current;

            current = file;
            file = file->next_file;
            if (current->is_dynamically_allocated != 0) {
                fn_8007A150(current);
            } else {
                current->mode.file_kind = 3;
                if (file != 0 && file->is_dynamically_allocated != 0) {
                    current->next_file = 0;
                }
            }
        }
    }
    __end_critical_region(2);
}

s32 fn_8007B0B4(void) {
    s32 result;
    AnsiFile *file;

    result = 0;
    file = __files;
    while (file != 0) {
        if (file->mode.file_kind != 0) {
            if (fflush(file) != 0) {
                result = -1;
            }
        }
        file = file->next_file;
    }
    return result;
}

s32 fn_8007B028(void) {
    s32 result;
    AnsiFile *file;

    file = __files;
    result = 0;
    while (file != 0) {
        if (file->mode.file_kind != 0 && (file->mode.buffer_mode & 1) && file->state.io_state == 1) {
            if (fflush(file) != 0) {
                result = -1;
            }
        }
        file = file->next_file;
    }
    return result;
}
