
#include "types.h"

enum ScanArgumentOption {
    SCAN_NORMAL,
    SCAN_CHAR,
    SCAN_SHORT,
    SCAN_LONG,
    SCAN_LONG_LONG,
    SCAN_DOUBLE,
    SCAN_LONG_DOUBLE,
    SCAN_WCHAR
};

typedef unsigned char ScanCharacterMap[32];

typedef struct ScanFormat {
    unsigned char suppress_assignment;
    unsigned char field_width_specified;
    unsigned char argument_option;
    unsigned char conversion;
    int field_width;
    ScanCharacterMap character_set;
} ScanFormat;

const char *fn_80083428(const char *format_string, ScanFormat *format);

extern unsigned char lbl_8015B100[];

static inline int isdigit(int c) { return (lbl_8015B100[(unsigned char)c] & 0x10); }

const char *fn_80083428(const char *format_string, ScanFormat *format) {
    const char *cursor = format_string;
    int character;
    int flag_found;
    int invert;
    ScanFormat parsed = {0, 0, SCAN_NORMAL, 0, 0x7FFFFFFF, {0}};
    cursor++;
    character = *cursor;
    if (character == '%') {
        parsed.conversion = character;
        *format = parsed;
        return cursor + 1;
    }
    if (character == '*') {
        parsed.suppress_assignment = 1;
        character = *++cursor;
    }
    if (isdigit(character)) {
        parsed.field_width = 0;
        do {
            parsed.field_width = (parsed.field_width * 10) + (character - '0');
            character = *++cursor;
        } while (isdigit(character));
        if (parsed.field_width == 0) {
            parsed.conversion = 0xFF;
            *format = parsed;
            return cursor + 1;
        }
        parsed.field_width_specified = 1;
    }
    flag_found = 1;
    switch (character) {
    case 'h':
        parsed.argument_option = SCAN_SHORT;
        if (cursor[1] == 'h') {
            parsed.argument_option = SCAN_CHAR;
            character = *++cursor;
        }
        break;
    case 'l':
        parsed.argument_option = SCAN_LONG;
        if (cursor[1] == 'l') {
            parsed.argument_option = SCAN_LONG_LONG;
            character = *++cursor;
        }
        break;
    case 'L':
        parsed.argument_option = SCAN_LONG_DOUBLE;
        break;
    default:
        flag_found = 0;
        break;
    }
    if (flag_found)
        character = *++cursor;
    parsed.conversion = character;
    switch (character) {
    case 'd':
    case 'i':
    case 'u':
    case 'o':
    case 'x':
    case 'X':
        if (parsed.argument_option == SCAN_LONG_DOUBLE)
            parsed.conversion = 0xFF;
        break;
    case 'a':
    case 'f':
    case 'e':
    case 'E':
    case 'g':
    case 'G':
        if (parsed.argument_option == SCAN_CHAR || parsed.argument_option == SCAN_SHORT ||
            parsed.argument_option == SCAN_LONG_LONG) {
            parsed.conversion = 0xFF;
        } else if (parsed.argument_option == SCAN_LONG) {
            parsed.argument_option = SCAN_DOUBLE;
        }
        break;
    case 'p':
        parsed.argument_option = SCAN_LONG;
        parsed.conversion = 'x';
        break;
    case 'c':
        if (parsed.argument_option == SCAN_LONG)
            parsed.argument_option = SCAN_WCHAR;
        else if (parsed.argument_option != SCAN_NORMAL)
            parsed.conversion = 0xFF;
        break;
    case 's': {
        int index;
        unsigned char *entry;
        if (parsed.argument_option == SCAN_LONG)
            parsed.argument_option = SCAN_WCHAR;
        else if (parsed.argument_option != SCAN_NORMAL)
            parsed.conversion = 0xFF;
        for (index = sizeof(parsed.character_set), entry = parsed.character_set; index != 0;
             --index)
            *entry++ = 0xFF;
        parsed.character_set[1] = 0xC1;
        parsed.character_set[4] = 0xFE;
        break;
    }
    case 'n':
        break;
    case '[':
        if (parsed.argument_option == SCAN_LONG)
            parsed.argument_option = SCAN_WCHAR;
        else if (parsed.argument_option != SCAN_NORMAL)
            parsed.conversion = 0xFF;
        character = *++cursor;
        invert = 0;
        if (character == '^') {
            invert = 1;
            character = *++cursor;
        }
        if (character == ']') {
            ((parsed.character_set)[(unsigned char)(']') >> 3] |=
             (1 << ((unsigned char)(']') & 7)));
            character = *++cursor;
        }
        while (character != 0 && character != ']') {
            int range_end;
            ((parsed.character_set)[(unsigned char)(character) >> 3] |=
             (1 << ((unsigned char)(character) & 7)));
            if (cursor[1] == '-' && (range_end = cursor[2]) != 0 && range_end != ']') {
                while (++character <= range_end)
                    ((parsed.character_set)[(unsigned char)(character) >> 3] |=
                     (1 << ((unsigned char)(character) & 7)));
                cursor += 3;
                character = *cursor;
            } else {
                character = *++cursor;
            }
        }
        if (character == 0) {
            parsed.conversion = 0xFF;
        } else if (invert) {
            int index;
            unsigned char *entry = parsed.character_set;
            for (index = sizeof(parsed.character_set); index != 0; --index, ++entry)
                *entry = ~*entry;
        }
        break;
    default:
        parsed.conversion = 0xFF;
        break;
    }
    *format = parsed;
    return cursor + 1;
}
