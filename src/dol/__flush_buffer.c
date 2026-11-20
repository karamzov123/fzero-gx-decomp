#include "types.h"


/* --- dol/__flush_buffer.c --- */
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

extern unsigned long __strtoul(int base, int max_width, int (*read_proc)(void *, int, int),
                                 void *read_context, int *chars_scanned, int *negative,
                                 int *overflow);

extern unsigned long long __strtoull(int base, int max_width, int (*read_proc)(void *, int, int),
                                      void *read_context, int *chars_scanned, int *negative,
                                      int *overflow);

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

/* --- dol/fn_8007EC80.c --- */
/* --- dol/fn_8007EC80.c --- */
typedef s32 (*fn_8007EC80_Fn0)(u32, u32, u32 *, u32);

struct fn_8007EC80_Arg0 {
    u32 unk_0;
    u8 pad_4[0x14];
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x04];
    fn_8007EC80_Fn0 unk_3C;
    u8 pad_40[0x08];
    u32 unk_48;
};

s32 fn_8007EC80(struct fn_8007EC80_Arg0 *arg0, u32 *arg1, s32 arg2) {
    s32 result;

    arg0->unk_24 = arg0->unk_1C;
    arg0->unk_28 = arg0->unk_20;
    arg0->unk_28 -= arg0->unk_18 & arg0->unk_2C;
    arg0->unk_34 = arg0->unk_18;
    if (arg2 == 1) {
        arg0->unk_28 = arg0->unk_20;
    }
    result = arg0->unk_3C(arg0->unk_0, arg0->unk_1C, &arg0->unk_28, arg0->unk_48);
    if (result == 2) {
        arg0->unk_28 = 0;
    }
    if (arg1 != 0) {
        *arg1 = arg0->unk_28;
    }
    if (result != 0) {
        return result;
    }
    arg0->unk_18 += arg0->unk_28;
    return 0;
}

/* --- dol/__prep_buffer.c --- */
/* --- dol/__prep_buffer.c --- */
typedef struct PrepBuffer {
    u8 pad[0x18];
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    u32 field_24;
    u32 field_28;
    u32 field_2c;
    u32 field_30;
    u32 field_34;
} PrepBuffer;

void __prep_buffer(PrepBuffer* buffer) {
    buffer->field_24 = buffer->field_1c;
    buffer->field_28 = buffer->field_20;
    buffer->field_28 -= buffer->field_18 & buffer->field_2c;
    buffer->field_34 = buffer->field_18;
}

/* --- dol/__end_critical_region.c --- */
// __end_critical_region: empty in retail (single blr).
void __end_critical_region(void) {
}

/* --- dol/__begin_critical_region.c --- */
// __begin_critical_region: empty in retail (single blr).
void __begin_critical_region(void) {
}

/* --- dol/__kill_critical_regions.c --- */
// __kill_critical_regions: empty in retail (single blr).
void __kill_critical_regions(void) {
}

/* --- dol/fn_8007ED90.c --- */
extern u8 lbl_8015B200[256];

s32 fn_8007ED90(s32 value) {
    if (value == -1) {
        return -1;
    }
    return lbl_8015B200[(u8)value];
}
