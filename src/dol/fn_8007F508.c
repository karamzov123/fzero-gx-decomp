#include "types.h"

/* MSL file_io.c: __get_file_modes */
typedef struct {
    unsigned int open_mode : 2;
    unsigned int io_mode : 3;
    unsigned int buffer_mode : 2;
    unsigned int file_kind : 3;
    unsigned int file_orientation : 2;
    unsigned int binary_io : 1;
} __file_modes;

enum { __must_exist, __create_if_necessary, __create_or_truncate };
enum { __read = 1, __write = 2, __read_write = 3, __append = 4 };
enum { __disk_file = 1 };
enum { __unoriented = 0 };

int fn_8007F508(const char *mode, __file_modes *modes) {
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
