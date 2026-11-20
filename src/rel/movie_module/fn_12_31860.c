#include "types.h"


/* --- rel/movie_module/fn_12_31860.c --- */
/* --- rel/movie_module/fn_12_31860.c --- */
typedef struct SFHHandle {
    int state;
    const unsigned char *header;
    int header_size;
    int version;
} SFHHandle;

typedef struct SFHStreamRecord {
    unsigned char reserved[0x18];
    unsigned char id;
    unsigned char codec;
    union {
        unsigned char codec_bytes[2];
        unsigned short codec_word;
    };
    union {
        unsigned char media_bytes[4];
        unsigned int media_word;
    };
    unsigned char effective_features;
    unsigned char color_type;
    unsigned char picture_type;
    unsigned char flags;
    unsigned char expand;
    unsigned char gop_n;
    unsigned char gop_m;
    unsigned char fx_type;
    unsigned char trailing[0x18];
} SFHStreamRecord;

int fn_12_31860(SFHHandle *handle, unsigned char stream_id, int *width, int *height);

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

static inline int sfh_is_version_ok(const SFHHandle *handle) {
    return handle->version == 0x6B || handle->version >= 0x6E;
}

static inline int sfh_is_analyzable(const SFHHandle *handle) {
    if (!sfh_is_valid(handle))
        return 0;
    if (!sfh_is_version_ok(handle))
        return 0;
    return 1;
}

static inline unsigned int sfh_stream_class(unsigned char stream_id) {
    unsigned int type = stream_id;
    if (type >= 0xC0 && type <= 0xDF) {
        type = 0xC0;
    } else if (type >= 0xE0 && type <= 0xEF) {
        type = 0xE0;
    } else if (type == 0xBD || type == 0xBF) {
        type = 0xBD;
    } else {
        type = 0;
    }
    return type;
}


static inline const SFHStreamRecord *sfh_find_handle_stream(const SFHHandle *handle,
                                                            unsigned int stream_id) {
    const unsigned char *header = handle->header;
    int i;
    const SFHStreamRecord *candidate;
    const SFHStreamRecord *stream;
    if (!sfh_is_analyzable(handle))
        return 0;
    stream = 0;
    i = 0;
    for (; i < 26; i++) {
        candidate = (const SFHStreamRecord *)(header + 0x180);
        if (candidate->id == stream_id) {
            stream = candidate;
            break;
        }
        header += sizeof(SFHStreamRecord);
    }
    return stream;
}


int fn_12_31860(SFHHandle *handle, unsigned char stream_id, int *width, int *height) {
    const SFHStreamRecord *stream;
    const unsigned char *dimensions;
    stream = sfh_find_handle_stream(handle, stream_id);
    if (stream == 0) return 0;
    if (sfh_stream_class(stream_id) != 0xE0) return 0;
    dimensions = stream->media_bytes;
    *width = dimensions[0];
    *width = (*width << 4) | ((dimensions[1] >> 4) & 0xF);
    *width &= 0xFFF;
    *height = dimensions[1];
    *height = (*height << 8) | dimensions[2];
    *height &= 0xFFF;
    return 1;
}

/* --- rel/movie_module/fn_12_319EC.c --- */
int fn_12_319EC(SFHHandle *handle, unsigned char stream_id, int *result);








int fn_12_319EC(SFHHandle *handle, unsigned char stream_id, int *result) {
    const SFHStreamRecord *stream;
    int encoded_rate;
    int bit_rate;
    int value;
    stream = sfh_find_handle_stream(handle, stream_id);
    if (stream == 0) return 0;
    if (sfh_stream_class(stream_id) != 0xE0) return 0;
    encoded_rate = stream->codec_word;
    bit_rate = (signed short)(unsigned short)(
        ((encoded_rate << 8) & 0xFF00) |
        (unsigned char)(encoded_rate >> 8));
    value = bit_rate;
    if (bit_rate == 0xFFFF) value = 0;
    *result = value;
    return 1;
}

/* --- rel/movie_module/fn_12_31B5C.c --- */
int fn_12_31B5C(SFHHandle *handle, unsigned char stream_id, int *result);







int fn_12_31B5C(SFHHandle *handle, unsigned char stream_id, int *result) {
    const SFHStreamRecord *stream;
    stream = sfh_find_handle_stream(handle, stream_id);
    if (stream == 0) return 0;
    if (sfh_stream_class(stream_id) != 0xE0) return 0;
    *result = stream->codec;
    return 1;
}

/* --- rel/movie_module/fn_12_31CA4.c --- */
static inline unsigned int sfh_swap_word(unsigned int value) {
    unsigned int low = (unsigned short)value;

    return (low << 24) | ((low << 8) & 0xFF0000) | ((value >> 8) & 0xFF00) | (value >> 24);
}

int fn_12_31CA4(SFHHandle *handle, unsigned char stream_id, unsigned int *result) {
    const SFHStreamRecord *stream;
    stream = sfh_find_handle_stream(handle, stream_id);
    if (stream == 0) return 0;
    if (sfh_stream_class(stream_id) != 0xC0) return 0;
    *result = sfh_swap_word(stream->media_word);
    return 1;
}

/* --- rel/movie_module/fn_12_31DFC.c --- */
/* --- rel/movie_module/fn_12_31DFC.c --- */


int fn_12_31DFC(SFHHandle *handle, unsigned char stream_id, int *result);







int fn_12_31DFC(SFHHandle *handle, unsigned char stream_id, int *result) {
    const SFHStreamRecord *stream;
    stream = sfh_find_handle_stream(handle, stream_id);
    if (stream == 0) return 0;
    if (sfh_stream_class(stream_id) != 0xC0) return 0;
    *result = stream->codec_bytes[1];
    return 1;
}

/* --- rel/movie_module/fn_12_31F44.c --- */
int fn_12_31F44(SFHHandle *handle, unsigned char stream_id, int *result);







int fn_12_31F44(SFHHandle *handle, unsigned char stream_id, int *result) {
    const SFHStreamRecord *stream;
    stream = sfh_find_handle_stream(handle, stream_id);
    if (stream == 0) return 0;
    if (sfh_stream_class(stream_id) != 0xC0) return 0;
    if (stream->codec != 1) return 0;
    *result = stream->codec_bytes[0];
    return 1;
}

/* --- rel/movie_module/fn_12_320A0.c --- */
int fn_12_320A0(SFHHandle *handle, unsigned char stream_id, int *result);







int fn_12_320A0(SFHHandle *handle, unsigned char stream_id, int *result) {
    const SFHStreamRecord *stream;
    stream = sfh_find_handle_stream(handle, stream_id);
    if (stream == 0) return 0;
    if (sfh_stream_class(stream_id) != 0xC0) return 0;
    *result = stream->codec;
    return 1;
}

/* --- rel/movie_module/fn_12_321E8.c --- */
/* --- rel/movie_module/fn_12_321E8.c --- */
typedef struct MovieContext {
    int state;
    void *movie;
    u8 _pad[4];
    int kind;
} MovieContext;

static inline u32 swap_movie_word(u32 value) {
    u32 low = (u16)value;

    return (low << 24) | ((low << 8) & 0xff0000) | ((value >> 8) & 0xff00) | (value >> 24);
}

int fn_12_321E8(MovieContext *self, u32 *result) {
    int kind_ok;
    int kind;
    u8 *movie = (u8 *)self->movie;
    int ok;

    switch (self->state) {
    case -1: case 0: case 1:
        ok = 0;
        break;
    default:
        ok = 1;
        break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        kind = self->kind;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        return 0;
    }

    *result = swap_movie_word(*(u32 *)(movie + 0xc0));
    return 1;
}

/* --- rel/movie_module/fn_12_32280.c --- */
int fn_12_32280(MovieContext *self, u32 *result) {
    int kind_ok;
    int kind;
    u8 *movie = (u8 *)self->movie;
    int ok;

    switch (self->state) {
    case -1: case 0: case 1:
        ok = 0;
        break;
    default:
        ok = 1;
        break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        kind = self->kind;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        return 0;
    }

    *result = swap_movie_word(*(u32 *)(movie + 0xbc));
    return 1;
}

/* --- rel/movie_module/fn_12_32318.c --- */
int fn_12_32318(MovieContext *self, u32 *result) {
    int kind_ok;
    int kind;
    u8 *movie = (u8 *)self->movie;
    int ok;

    switch (self->state) {
    case -1: case 0: case 1:
        ok = 0;
        break;
    default:
        ok = 1;
        break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        kind = self->kind;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        return 0;
    }

    *result = swap_movie_word(*(u32 *)(movie + 0xb8));
    return 1;
}

/* --- rel/movie_module/fn_12_323B0.c --- */
int fn_12_323B0(MovieContext *self, u32 *result) {
    int kind_ok;
    u8 *movie = (u8 *)self->movie;
    int ok;

    switch (self->state) {
    case -1: case 0: case 1:
        ok = 0;
        break;
    default:
        ok = 1;
        break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        int kind = self->kind;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        return 0;
    }

    if (self->kind < 0x6e) {
        return 0;
    }

    *result = swap_movie_word(*(u32 *)(movie + 0xb4));
    return 1;
}

/* --- rel/movie_module/fn_12_3245C.c --- */
/* --- rel/movie_module/fn_12_3245C.c --- */

int fn_12_3245C(MovieContext *self, u32 *result) {
    int kind_ok;
    int kind;
    u8 *movie = (u8 *)self->movie;
    int ok;

    switch (self->state) {
    case -1: case 0: case 1:
        ok = 0;
        break;
    default:
        ok = 1;
        break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        kind = self->kind;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        return 0;
    }

    *result = movie[0xb3];
    return 1;
}

/* --- rel/movie_module/fn_12_324E4.c --- */
int fn_12_324E4(MovieContext *self, u32 *result) {
    int kind_ok;
    int kind;
    u8 *movie = (u8 *)self->movie;
    int ok;

    switch (self->state) {
    case -1: case 0: case 1:
        ok = 0;
        break;
    default:
        ok = 1;
        break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        kind = self->kind;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        return 0;
    }

    *result = movie[0xb2];
    return 1;
}

/* --- rel/movie_module/fn_12_3256C.c --- */
int fn_12_3256C(MovieContext *self, u32 *result) {
    int kind_ok;
    int kind;
    u8 *movie = (u8 *)self->movie;
    int ok;

    switch (self->state) {
case -1: case 0: case 1: {

        ok = 0;
    
} break;
default: {

        ok = 1;
    
} break;
}

    if (ok == 0) {
        ok = 0;
    } else {
        kind = self->kind;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        return 0;
    }

    *result = ((movie)[0xb1]);
    return 1;
}

/* --- rel/movie_module/fn_12_325F4.c --- */
int fn_12_325F4(MovieContext *self, u32 *result) {
    int kind_ok;
    int kind;
    u8 *movie = (u8 *)self->movie;
    int ok;

    switch (self->state) {
case -1: case 0: case 1: {

        ok = 0;
    
} break;
default: {

        ok = 1;
    
} break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        kind = self->kind;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        return 0;
    }

    *result = movie[0xb0];
    return 1;
}

/* --- rel/movie_module/fn_12_3267C.c --- */
int fn_12_3267C(MovieContext *self, u32 *result) {
    int kind_ok;
    int kind;
    u8 *movie = (u8 *)self->movie;
    int ok;

    switch (self->state) {
    case -1: case 0: case 1:
        ok = 0;
        break;
    default:
        ok = 1;
        break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        kind = self->kind;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        return 0;
    }

    *result = swap_movie_word(*(u32 *)(movie + 0x8c));
    return 1;
}

/* --- rel/movie_module/fn_12_32714.c --- */
/* --- rel/movie_module/fn_12_32714.c --- */

static inline s16 swap_movie_value(s16 value) {
    return (s16)(u16)(((((value << 8) & 0xff00)) | (((value >> 8) & 0xff))));
}

int fn_12_32714(MovieContext *self, s32 *result) {
    s32 kind_ok;
    int kind;
    u8 *movie = (u8 *)self->movie;
    int ok;
    s16 value;

    switch (self->state) {
    case -1: case 0: case 1:
        ok = 0;
        break;
    default:
        ok = 1;
        break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        kind = self->kind;
        kind_ok = (s16)(0);
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = (s16)(1);
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        return 0;
    }

    value = *(s16 *)(movie + 0x88);
    *result = swap_movie_value(value);
    return 1;
}

/* --- rel/movie_module/fn_12_327AC.c --- */
int fn_12_327AC(MovieContext *self, u32 *result) {
    int kind_ok;
    int kind;
    u8 *movie = (u8 *)self->movie;
    int ok;

    switch (self->state) {
case -1: case 0: case 1: {

        ok = 0;
    
} break;
default: {

        ok = 1;
    
} break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        kind = self->kind;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        return 0;
    }

    *result = movie[0x84];
    return 1;
}

/* --- rel/movie_module/fn_12_32834.c --- */
int fn_12_32834(MovieContext *self, u32 *result) {
    int kind_ok;
    int kind;
    u8 *movie = (u8 *)self->movie;
    int ok;

    switch (self->state) {
    case -1: case 0: case 1:
        ok = 0;
        break;
    default:
        ok = 1;
        break;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        kind = self->kind;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (ok == 0) {
        return 0;
    }

    *result = swap_movie_word(*(u32 *)(movie + 0x80));
    return 1;
}

/* --- rel/movie_module/fn_12_328CC.c --- */
extern void *memset(void *destination, int value, unsigned long size);
extern void *memcpy(void *destination, const void *source, unsigned long size);
extern const char *fn_80083970(const char *str1, const char *str2);
extern const char lbl_12_rodata_10DC[5];


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

/* --- rel/movie_module/fn_12_32A70.c --- */
/* --- rel/movie_module/fn_12_32A70.c --- */


int fn_12_32A70(SFHHandle *handle, unsigned char stream_id, int *result);




static inline const SFHStreamRecord *sfh_find_stream(const unsigned char *header,
                                                     unsigned int stream_id) {
    long i;
    const SFHStreamRecord *candidate;
    const SFHStreamRecord *stream;
    stream = 0;
    for (i = 0; i < 26; i++) {
        candidate = (const SFHStreamRecord *)(header + 0x180 + i * 0x40);
        if (candidate->id == stream_id) {
            stream = candidate;
            break;
        }
    }
    return stream;
}


static inline const SFHStreamRecord *sfh_feature_stream(const SFHHandle *handle,
                                                        unsigned int stream_id) {
    const unsigned char *header = handle->header;
    const SFHStreamRecord *stream;
    stream = !sfh_is_analyzable(handle) ? 0 : sfh_find_stream(header, stream_id);
    return stream;
}

static inline int sfh_effective_features(const SFHStreamRecord *stream, unsigned int stream_id,
                                         unsigned int expected_class) {
    int valid;
    if (sfh_stream_class(stream_id) != expected_class) {
        valid = 0;
    } else if (stream->effective_features > 1) {
        valid = 0;
    } else if (stream->effective_features == 0) {
        valid = 0;
    } else {
        valid = 1;
    }
    return valid;
}

int fn_12_32A70(SFHHandle *handle, unsigned char stream_id, int *result) {
    const SFHStreamRecord *stream;
    int stream_class;
    unsigned int stream_id_value;
    if (handle->version < 0x6E)
        return 0;
    stream_id_value = stream_id;
    stream_class = sfh_stream_class(stream_id_value);
    switch (stream_class) {
    case 0xC0:
        stream = sfh_feature_stream(handle, stream_id_value);
        if (stream == 0)
            return 0;
        *result = sfh_effective_features(stream, stream_id_value, 0xC0);
        break;
    case 0xE0:
        stream = sfh_feature_stream(handle, stream_id_value);
        if (stream == 0)
            return 0;
        *result = sfh_effective_features(stream, stream_id_value, 0xE0);
        break;
    default:
        return 0;
    }
    return 1;
}

/* --- rel/movie_module/fn_12_32DBC.c --- */
int fn_12_32DBC(SFHHandle *handle, unsigned char stream_id, int *result);





int fn_12_32DBC(SFHHandle *handle, unsigned char stream_id, int *result) {
    const unsigned char *header;
    *result = 0;
    header = handle->header;
    if (!sfh_is_analyzable(handle))
        return 0;
    if (sfh_find_stream(header, stream_id) != 0) {
        *result = 1;
    } else {
        *result = 0;
    }
    return 1;
}
