#include "types.h"

typedef struct SFHHandle {
    int state;
    const unsigned char *header;
    int header_size;
    int version;
} SFHHandle;

extern void *memset(void *destination, int value, unsigned long size);
extern void *memcpy(void *destination, const void *source, unsigned long size);
extern const char *fn_80083970(const char *str1, const char *str2);
extern const char lbl_12_rodata_10DC[5];

static inline int sfh_is_valid(const SFHHandle *handle) {
    int valid;

    switch (handle->state) {
    case -1:
    case 0:
    case 1:
        valid = 0;
        break;
    default:
        valid = 1;
        break;
    }
    return valid;
}

static inline int sfh_get_tool_str(SFHHandle *handle, const unsigned char *source, char *output) {
    if (!sfh_is_valid(handle)) return 0;
    memset(output, 0, 0x21);
    memcpy(output, source, 0x20);
    return 1;
}

static inline int sfh_is_digit(int character) {
    int valid = 0;
    if (character >= '0' && character <= '9') valid = 1;
    return valid;
}

static inline int sfh_atoi(const char **text) {
    const char *digit = *text;
    int character;
    int value = 0;

    for (;;) {
        character = *digit;
        if (character == '.' || character == ' ' || character == 0) break;
        if (!sfh_is_digit(character)) break;
        value = value * 10 + character;
        value -= '0';
        digit++;
    }
    *text = digit;
    return value;
}

static inline int sfh_get_str_ver(const char *text, int *major, int *minor) {
    const char *digit = fn_80083970(text, lbl_12_rodata_10DC);

    if (digit == 0) return 0;
    digit += 4;
    *major = sfh_atoi(&digit);
    digit++;
    *minor = sfh_atoi(&digit);
    return 1;
}

int fn_12_328CC(SFHHandle *handle, int *major, int *minor) {
    const unsigned char *header;
    const unsigned char *tool_string;
    char tool_version[33];

    header = handle->header;
    tool_string = header + 0x60;
    if (!sfh_get_tool_str(handle, tool_string, tool_version)) return 0;
    if (!sfh_get_str_ver(tool_version, major, minor)) return 0;
    return 1;
}
