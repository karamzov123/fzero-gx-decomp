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

void __end_critical_region(int region) {
    (void)region;
}

void __begin_critical_region(int region) {
    (void)region;
}

void __kill_critical_regions(void) {
}
