
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

int fn_12_32DBC(SFHHandle *handle, unsigned char stream_id, int *result);

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
