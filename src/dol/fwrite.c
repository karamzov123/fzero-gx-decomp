#include "types.h"


/* --- dol/fwrite.c --- */
extern u32 __begin_critical_region(u32);
extern u32 __fwrite(u32, u32, u32, u32);
extern u32 __end_critical_region(u32);

u32 fwrite(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t0;
    u32 t1;

    v0 = arg0;
    v1 = arg1;
    v2 = arg2;
    v3 = arg3;
    t0 = __begin_critical_region(2);
    t1 = __fwrite(v0, v1, v2, v3);
    v0 = t1;
    __end_critical_region(2);
    return v0;
}

/* --- dol/fn_8007F13C.c --- */
typedef struct {
    unsigned int unused_open : 2;
    unsigned int io_mode : 3;
    unsigned int buffer_mode : 2;
    unsigned int mode : 3;
    unsigned int orientation : 2;
    unsigned int binary : 1;
} FileMode;
typedef struct {
    unsigned int kind : 3;
    unsigned int free_buffer : 1;
    unsigned char eof;
    unsigned char error;
} FileState;
typedef struct {
    u32 handle;
    FileMode open;
    FileState buffer;
    u8 pad0C[0x10];
    char *buffer_base;
    unsigned long buffer_size;
    char *buffer_ptr;
    unsigned long buffer_length;
    unsigned long alignment;
    unsigned long saved_length;
} File;
#define byte0A buffer.error
#define byte09 buffer.eof
extern int fwide(File *, int);
extern s32 fn_8007B028(void);
extern s32 fn_8007EC80(File *, unsigned int *, s32);
extern void *memcpy(void *, const void *, u32);
extern void __prep_buffer(File *);

// Donor seed for fn_8007F13C (addr 0x8007F13C)
// Extracted from stdio_8007A060.c (original name: fn_8007F13C)

int fn_8007F13C(void* dst, unsigned long size, unsigned long count, File* file)
{
    int flag;
    char* cursor;
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
    if (total == 0 || file->byte0A != 0 || file->open.mode == 0) {
        return 0;
    }

    flag = 1;
    if (file->open.binary != 0 && file->open.buffer_mode != 2) {
        flag = 0;
    }

    if (file->buffer.kind == 0 && (file->open.io_mode & 1) != 0) {
        file->buffer.kind = 2;
        file->buffer_length = 0;
    }

    if (file->buffer.kind < 2) {
        file->byte0A = 1;
        file->buffer_length = 0;
        return 0;
    }

    if ((file->open.buffer_mode & 1) != 0 && fn_8007B028() != 0) {
        file->byte0A = 1;
        file->buffer_length = 0;
        return 0;
    }

    cursor = (char*)dst;
    red = 0;

    if (total != 0 && file->buffer.kind >= 3) {
        do {
            if (fwide(file, 0) == 1) {
                red += 2;
                total -= 2;
                *(unsigned short*)cursor =
                    *(unsigned short*)((char*)file + file->buffer.kind * 2 + 0xC);
                cursor += 2;
            } else {
                red += 1;
                total -= 1;
                *cursor = *((char*)file + file->buffer.kind + 0xC);
                cursor += 1;
            }
            file->buffer.kind = file->buffer.kind - 1;
        } while (total != 0 && file->buffer.kind >= 3);

        if (file->buffer.kind == 2) {
            file->buffer_length = file->saved_length;
        }
    }

    if (total != 0 && (file->buffer_length != 0 || flag != 0)) {
        do {
            if (file->buffer_length == 0) {
                r = fn_8007EC80(file, 0, 0);
                if (r != 0) {
                    if (r == 1) {
                        file->byte0A = 1;
                        file->buffer_length = 0;
                    } else {
                        file->buffer.kind = 0;
                        file->byte09 = 1;
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
        savedbase = (unsigned long)file->buffer_base;
        savedsize = file->buffer_size;
        file->buffer_base = cursor;
        file->buffer_size = total;
        r = fn_8007EC80(file, &chunk, 1);
        if (r != 0) {
            if (r == 1) {
                file->byte0A = 1;
                file->buffer_length = 0;
            } else {
                file->buffer.kind = 0;
                file->byte09 = 1;
                file->buffer_length = 0;
            }
        }
        red += chunk;
        file->buffer_base = (char*)savedbase;
        file->buffer_size = savedsize;
        __prep_buffer(file);
        file->buffer_length = 0;
    }

    return red / size;
}
