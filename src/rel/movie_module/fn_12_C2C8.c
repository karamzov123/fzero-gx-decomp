
#include "types.h"

typedef struct SJCK {
    union {
        unsigned char padding_extent[8];
        struct {
            unsigned char *data;
        } view_data;
        struct {
            unsigned char padding_len[4];
            long len;
        } view_len;
    } fields;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface SJInterface;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface {
    union {
        unsigned char padding_extent[48];
        struct {
            unsigned char padding_get_chunk[24];
            void (*get_chunk)(SJ *sj, long channel, long max_size, SJCK *chunk);
        } view_get_chunk;
        struct {
            unsigned char padding_unget_chunk[28];
            void (*unget_chunk)(SJ *sj, int channel, SJCK *chunk);
        } view_unget_chunk;
        struct {
            unsigned char padding_put_chunk[32];
            void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
        } view_put_chunk;
    } fields;
};

struct SJ {
    union {
        unsigned char padding_extent[4];
        struct {
            const SJInterface *interface;
        } view_interface;
    } fields;
};

typedef struct DctFsriBlock {
    s16 samples[64];
} DctFsriBlock;

typedef struct DctFsriParams {
    s8 block_nonzero[6];
    u8 field_06[0x12];
    s32 decoded;
    s32 skipped;
    u8 field_20[8];
    int coded_block_pattern;
    float *coefficients;
    DctFsriBlock **output_blocks;
    u8 field_34[0x14];
    float *workspace;
    u8 field_4C[8];
} DctFsriParams;

typedef struct MPVContext MPVContext;

typedef void (*MPVErrorCallback)(void *object, int error);

typedef struct MPVErrorInfo {
    union {
        unsigned char padding_extent[20];
        struct {
            unsigned char padding_field_0C[12];
            int field_0C;
        } view_field_0C;
        struct {
            unsigned char padding_field_10[16];
            int field_10;
        } view_field_10;
    } fields;
} MPVErrorInfo;

typedef struct MPVMCContext MPVMCContext;

typedef void (*MPVMCFunction)(MPVMCContext *context);

struct MPVMCContext {
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_field_10[16];
            u8 field_10[8];
        } view_field_10;
    } fields;
};

typedef struct MPVPlaneSet {
    u8 *planes[3];
    s16 chroma_stride;
    s16 luma_stride;
} MPVPlaneSet;

typedef struct MPVOutputBlock {
    u8 *destination;
    s32 stride;
} MPVOutputBlock;

typedef struct MPVOutputBlocks {
    s32 count;
    MPVOutputBlock blocks[6];
} MPVOutputBlocks;

typedef struct MPVMacroblockSources {
    void *field_00;
    s16 *residual;
    u8 *prediction0;
    u8 *prediction1;
} MPVMacroblockSources;

typedef struct MPVYccPlane {
    u8 *chroma0;
    u8 *chroma1;
    u8 *luma;
    s16 chroma_stride;
    s16 luma_stride;
} MPVYccPlane;

typedef struct MPVMotionInfo {
    s32 full_pel;
    s32 r_size;
    s32 shift;
    s32 limit;
    s32 previous_horizontal;
    s32 previous_vertical;
    s32 horizontal;
    s32 vertical;
    u8 field_20[4];
} MPVMotionInfo;

typedef struct MPVPictureAttributes {
    int width;
    int height;
    int macroblocks_per_row;
    int macroblock_rows;
    int frame_rate_code;
    int temporal_reference;
    int picture_type;
    int drop_frame_flag;
    int time_code_hours;
    int time_code_minutes;
    int time_code_seconds;
    int time_code_pictures;
    int group_count;
    int sequence_header_count;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int bit_rate;
    int vbv_buffer_size;
    s16 field_50;
    s16 field_52;
    u8 field_54;
    s8 field_55;
    s8 field_56;
    s8 field_57;
    u8 field_58;
    u8 aspect_ratio;
    u8 constrained_parameters;
    u8 field_5B;
    u8 field_5C;
    u8 field_5D;
    s8 field_5E;
    s8 field_5F;
    s8 field_60;
    u8 field_61;
    u8 field_62;
    u8 field_63;
    u8 field_64;
    u8 padding_65[0x1B];
} MPVPictureAttributes;

typedef MPVPictureAttributes MPVPictureInfo;

typedef struct MPVFrameBuffers {
    MPVPlaneSet forward;
    MPVPlaneSet backward;
    u8 *output_rfb;
    MPVPictureInfo *picture_info;
    s32 decoded_dct_count;
    s32 skipped_dct_count;
} MPVFrameBuffers;

typedef struct MPVBitReader {
    u32 bits;
    u32 next_bits;
    s32 bit_offset;
    const u32 *words;
} MPVBitReader;

typedef struct MPVConditionState {
    union {
        unsigned char padding_extent[192];
        struct {
            int conditions[16];
        } view_conditions;
    } fields;
} MPVConditionState;

typedef struct MPVTransformWorkspace {
    DctFsriBlock blocks[6];
    float coefficients[6][64];
} MPVTransformWorkspace;

typedef struct MPVCodingBlock {
    s32 run;
    s32 level;
    s32 sign;
    u32 code_length;
    s32 first_scan;
    s32 current_scan;
    u8 field_18[4];
    void *coefficients;
    const u8 *quant_matrix;
    s32 quantizer_scale;
    s32 *dc_predictor;
    const u8 *dc_size_lut;
} MPVCodingBlock;

typedef struct MPVCodingWorkspace {
    MPVCodingBlock block;
    s32 non_intra_mode;
} MPVCodingWorkspace;

typedef struct MPVUserStream {
    SJ *stream;
    void (*callback)(void *argument, int index);
    void *callback_argument;
} MPVUserStream;

typedef struct MPVPictureUserBuffer {
    union {
        unsigned char padding_extent[12];
        struct {
            unsigned char padding_size[8];
            s32 size;
        } view_size;
    } fields;
} MPVPictureUserBuffer;

struct MPVContext {
    union {
        unsigned char padding_extent[4992];
        struct {
            unsigned char padding_condition_state[400];
            MPVConditionState condition_state;
        } view_condition_state;
        struct {
            unsigned char padding_error_info[544];
            MPVErrorInfo error_info;
        } view_error_info;
        struct {
            unsigned char padding_field_358[4820];
            s32 field_358;
        } view_field_358;
        struct {
            unsigned char padding_field_1300[4800];
            s32 field_1300;
        } view_field_1300;
        struct {
            unsigned char padding_field_1304[4804];
            s32 field_1304;
        } view_field_1304;
        struct {
            unsigned char padding_header_chunk[4808];
            SJCK header_chunk;
        } view_header_chunk;
        struct {
            unsigned char padding_bit_offset[4816];
            s32 bit_offset;
        } view_bit_offset;
        struct {
            unsigned char padding_picture_user[4920];
            MPVPictureUserBuffer picture_user;
        } view_picture_user;
    } fields;
};

int fn_12_C2C8(void *handle, SJ *stream);

void fn_800589BC(const SJCK *source, int nbyte, SJCK *first, SJCK *remainder);

int fn_12_A660(MPVContext *handle, int error);

int fn_12_CAB4(MPVContext *handle);

const unsigned char *fn_12_A0D8(const unsigned char *data, int length, int mask);

int fn_12_A2C4(const unsigned char *data);

extern int fn_12_20170(MPVContext *context, SJ *stream);

static inline int MPV_MoveChunk(SJ *stream, int channel, int size) {
    SJCK chunk;
    int source_channel = channel;
    channel = channel == 0;
    stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(stream, source_channel,
                                                                             size, &chunk);
    stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(stream, channel,
                                                                             &chunk);
    return chunk.fields.view_len.len;
}

static inline int mpvhdec_ReadDelimSj(SJ *stream) {
    SJCK chunk;
    SJCK remainder;
    const u8 *delimiter;
    int delimiter_type;
    for (;;) {
        stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
            stream, 1, 0x7FFFFFFF, &chunk);
        if (chunk.fields.view_len.len < 4) {
            stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                         &chunk);
            return 0;
        }
        delimiter = fn_12_A0D8(chunk.fields.view_data.data, chunk.fields.view_len.len, -1);
        if (delimiter != 0) {
            break;
        }
        fn_800589BC(&chunk, chunk.fields.view_len.len - 3, &chunk, &remainder);
        stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(stream, 0, &chunk);
        stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                     &remainder);
    }
    delimiter_type = fn_12_A2C4(delimiter);
    fn_800589BC(&chunk, delimiter - chunk.fields.view_data.data, &chunk, &remainder);
    stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(stream, 0, &chunk);
    stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                 &remainder);
    return delimiter_type;
}

static inline int mpvhdec_DetectDecoderMode(MPVContext *context, const u8 *data, int length) {
    const u8 *delimiter;
    int delimiter_type;
    if (context->fields.view_field_358.field_358 != 0) {
        return context->fields.view_field_358.field_358;
    }
    delimiter = fn_12_A0D8(data, length, 0x40);
    if (delimiter == 0) {
        return context->fields.view_field_358.field_358;
    }
    delimiter += 4;
    delimiter = fn_12_A0D8(delimiter, length - (delimiter - data), -1);
    if (delimiter == 0) {
        return context->fields.view_field_358.field_358;
    }
    delimiter_type = fn_12_A2C4(delimiter);
    if (delimiter_type & 0x10) {
        context->fields.view_field_358.field_358 = 2;
    } else if (delimiter_type != 0) {
        context->fields.view_field_358.field_358 = 1;
    }
    return context->fields.view_field_358.field_358;
}

static inline int mpvhdec_SeekPictureData(MPVContext *context, SJ *stream, int wanted_mask) {
    int condition;
    int error;
    int delimiter_type;
    condition =
        context->fields.view_condition_state.condition_state.fields.view_conditions.conditions[1];
    if (context->fields.view_field_1300.field_1300 != 0) {
        context->fields.view_field_1300.field_1300 = 0;
        context->fields.view_field_1304.field_1304++;
        context->fields.view_error_info.error_info.fields.view_field_0C.field_0C++;
        if (condition == 0) {
            return -2;
        }
        context->fields.view_error_info.error_info.fields.view_field_10.field_10++;
    }
    if (condition == 0) {
        error = -2;
    } else {
        error = -3;
    }
    for (;;) {
        delimiter_type = mpvhdec_ReadDelimSj(stream);
        if (delimiter_type == 0) {
            break;
        }
        if ((delimiter_type & wanted_mask) != 0) {
            error = 0;
            break;
        }
        if (MPV_MoveChunk(stream, 1, 4) != 4) {
            break;
        }
    }
    return error;
}

static inline int MPV_GoNextDelimSj(SJ *stream) {
    SJCK chunk;
    SJCK remainder;
    const u8 *delimiter;
    int delimiter_type;
    for (;;) {
        stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
            stream, 1, 0x7FFFFFFF, &chunk);
        if (chunk.fields.view_len.len < 4) {
            stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                         &chunk);
            delimiter_type = 0;
            break;
        }
        delimiter = fn_12_A0D8(chunk.fields.view_data.data, chunk.fields.view_len.len, -1);
        if (delimiter == 0) {
            fn_800589BC(&chunk, chunk.fields.view_len.len - 3, &chunk, &remainder);
            stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(stream, 0,
                                                                                     &chunk);
            stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(
                stream, 1, &remainder);
            continue;
        }
        delimiter_type = fn_12_A2C4(delimiter);
        fn_800589BC(&chunk, delimiter - chunk.fields.view_data.data, &chunk, &remainder);
        stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(stream, 0, &chunk);
        stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                     &remainder);
        break;
    }
    return delimiter_type;
}

static inline void mpvhdec_ConsumeDelim(MPVContext *context, SJ *stream) {
    SJCK remainder;
    s32 bits;
    u32 *p;
    u32 initial;
    s32 cnt;
    u8 *cursor;
    stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
        stream, 1, 0x7FFFFFFF, &context->fields.view_header_chunk.header_chunk);
    p = (u32 *)((u32)context->fields.view_header_chunk.header_chunk.fields.view_data.data & ~3);
    initial = p[1];
    bits = ((u32)context->fields.view_header_chunk.header_chunk.fields.view_data.data - (u32)p) * 8;
    p += 2;
    if (bits >= 32) {
        bits -= 32;
        initial = *p++;
    }
    if (bits) {
        initial <<= bits;
    }
    context->fields.view_bit_offset.bit_offset = bits & 7;
    cnt = (bits - context->fields.view_bit_offset.bit_offset + 7) >> 3;
    cursor = (u8 *)(p - 1) + cnt;
    fn_800589BC(&context->fields.view_header_chunk.header_chunk, cursor - context->fields.view_header_chunk.header_chunk.fields.view_data.data, &context->fields.view_header_chunk.header_chunk, &remainder);
    stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(stream, 0, &context->fields.view_header_chunk.header_chunk);
    stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1, &remainder);
    MPV_GoNextDelimSj(stream);
}

int fn_12_B3E0(MPVContext *context, const u8 *data, long length);

static inline void mpvhdec_ConsumeUserData(MPVContext *context, SJ *stream) {
    SJCK remainder;
    s32 bits;
    u32 *p;
    u32 initial;
    s32 cnt;
    u8 *cursor;
    stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
        stream, 1, 0x7FFFFFFF, &context->fields.view_header_chunk.header_chunk);
    p = (u32 *)((u32)context->fields.view_header_chunk.header_chunk.fields.view_data.data & ~3);
    initial = p[1];
    bits = ((u32)context->fields.view_header_chunk.header_chunk.fields.view_data.data - (u32)p) * 8;
    p += 2;
    if (bits >= 32) {
        bits -= 32;
        initial = *p++;
    }
    if (bits) {
        initial <<= bits;
    }
    fn_12_B3E0(context, context->fields.view_header_chunk.header_chunk.fields.view_data.data,
               context->fields.view_header_chunk.header_chunk.fields.view_len.len);
    context->fields.view_bit_offset.bit_offset = bits & 7;
    cnt = (bits - context->fields.view_bit_offset.bit_offset + 7) >> 3;
    cursor = (u8 *)(p - 1) + cnt;
    fn_800589BC(&context->fields.view_header_chunk.header_chunk, cursor - context->fields.view_header_chunk.header_chunk.fields.view_data.data, &context->fields.view_header_chunk.header_chunk, &remainder);
    stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(stream, 0, &context->fields.view_header_chunk.header_chunk);
    stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1, &remainder);
    MPV_GoNextDelimSj(stream);
}

int fn_12_B598(MPVContext *context, SJ *stream);

int fn_12_B9E8(MPVContext *context, SJ *stream);

int fn_12_BBC0(MPVContext *context, SJ *stream);

int fn_12_C2C8(void *handle, SJ *stream) {
    MPVContext *context = handle;
    SJCK initial_chunk;
    SJCK chunk;
    const u8 *chunk_data;
    int chunk_len;
    int delimiter_type;
    int error;
    if (fn_12_CAB4(context) != 0) {
        return fn_12_A660(0, 0xFF03020C);
    }
    context->fields.view_picture_user.picture_user.fields.view_size.size = 0;
    stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(stream, 1, 0x7FFFFFFF,
                                                                             &initial_chunk);
    stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                 &initial_chunk);
    chunk_data = initial_chunk.fields.view_data.data;
    chunk_len = initial_chunk.fields.view_len.len;
    if (mpvhdec_DetectDecoderMode(context, chunk_data, chunk_len) == 2) {
        return fn_12_20170(context, stream);
    }
    for (;;) {
        error = mpvhdec_SeekPictureData(context, stream, -1);
        if (error != 0) {
            return fn_12_A660(context, error);
        }
        stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
            stream, 1, 0x7FFFFFFF, &chunk);
        stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                     &chunk);
        delimiter_type =
            chunk.fields.view_len.len < 4 ? 0 : fn_12_A2C4(chunk.fields.view_data.data);
        if (delimiter_type == 0 || (delimiter_type & 3) != 0) {
            break;
        }
        switch (delimiter_type) {
        case 0x40:
            fn_12_BBC0(context, stream);
            break;
        case 8:
            fn_12_B9E8(context, stream);
            break;
        case 4:
            fn_12_B598(context, stream);
            break;
        case 0x10:
            mpvhdec_ConsumeDelim(context, stream);
            break;
        case 0x20:
            mpvhdec_ConsumeUserData(context, stream);
            break;
        }
    }
    return error;
}
