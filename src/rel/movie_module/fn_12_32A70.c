
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

int fn_12_32A70(SFHHandle *handle, unsigned char stream_id, int *result);

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
