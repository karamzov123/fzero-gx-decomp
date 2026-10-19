
#include "types.h"

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
