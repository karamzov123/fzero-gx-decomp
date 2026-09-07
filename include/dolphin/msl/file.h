#ifndef DOLPHIN_MSL_FILE_H
#define DOLPHIN_MSL_FILE_H

typedef struct FileMode {
    unsigned int open_mode : 2;   /* word bits 31..30 */
    unsigned int io_mode : 3;     /* word bits 29..27 */
    unsigned int buffer_mode : 2; /* word bits 26..25 */
    unsigned int mode : 3;        /* word bits 24..22 (file kind) */
    unsigned int unk20 : 2;       /* word bits 21..20: stream orientation */
    unsigned int binary : 1;      /* word bit 19 */
    unsigned int pad : 19;        /* word bits 18..0 */
} FileMode;

typedef struct FileBuffer {
    unsigned char kind : 3;   /* bits 5..7: buffer kind */
    unsigned char alloc : 1;  /* bit 4: buffer allocated */
    unsigned char pad : 4;    /* bits 0..3 */
} FileBuffer;

typedef struct File {
    unsigned int handle;                     /* +0x00 */
    FileMode open;                           /* +0x04 */
    FileBuffer buffer;                       /* +0x08 */
    unsigned char byte09;                    /* +0x09 */
    unsigned char byte0A;                    /* +0x0A */
    unsigned char byte0B;                    /* +0x0B */
    unsigned char dyn_alloc;                 /* +0x0C: !=0 when dynamically allocated */
    char small_buf[0x0B];                    /* +0x0D..+0x17 */
    unsigned int position;                   /* +0x18 */
    char* buffer_base;                       /* +0x1C */
    unsigned int buffer_size;                /* +0x20 */
    char* buffer_ptr;                        /* +0x24 */
    unsigned int buffer_length;              /* +0x28 */
    unsigned int buffer_mask;                /* +0x2C */
    unsigned int saved_length;               /* +0x30 */
    unsigned int buffer_position;            /* +0x34 */
    int (*position_func)(unsigned int, long*, int, unsigned int); /* +0x38 */
    int (*read_func)(struct File*, char*, unsigned int*); /* +0x3C */
    int (*write_func)(struct File*, char*, unsigned int*);/* +0x40 */
    int (*close_func)(unsigned int);         /* +0x44 */
    unsigned int ref_con;                    /* +0x48 */
    struct File* next;                       /* +0x4C */
} File;

enum {
    FILE_UNORIENTED = 0,
    FILE_CHAR_ORIENTED = 1,
    FILE_WIDE_ORIENTED = 2
};

int fwide(File* file, int mode);

#endif
