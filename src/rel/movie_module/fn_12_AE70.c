
#include "types.h"

typedef struct SJCK {
    union {
        unsigned char padding_extent[8];
        struct {
            unsigned char *data;
        } view_data;
        struct {
            unsigned char padding_len[4];
            int len;
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
            void (*get_chunk)(SJ *sj, int channel, int max_size, SJCK *chunk);
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

typedef union DctFsriBlock {
    s16 samples[64];
    u32 packed[32];
} DctFsriBlock;

typedef struct DctFsriParams {
    s8 block_nonzero[6];
    u8 field_06[0x22];
    int coded_block_pattern;
    float *coefficients;
    DctFsriBlock **output_blocks;
    u8 field_34[0x14];
    float *workspace;
    u8 field_4C[8];
} DctFsriParams;

typedef struct MPVContext MPVContext;

typedef void (*MPVErrorCallback)(int object, int error);

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
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    s16 field_50;
    s16 field_52;
    u8 field_54;
    s8 field_55;
    s8 field_56;
    s8 field_57;
    u8 field_58;
    u8 field_59;
    u8 field_5A;
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
    u8 padding_65[3];
} MPVPictureAttributes;

typedef struct MPVPictureInfo {
    MPVPictureAttributes attributes;
    u8 decoder_state[0x18];
} MPVPictureInfo;

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

typedef struct MPVDecoderFields {
    union {
        unsigned char padding_extent[168];
        struct {
            unsigned char padding_field_1AC[28];
            s32 field_1AC;
        } view_field_1AC;
    } fields;
} MPVDecoderFields;

typedef union MPVConditionState {
    union {
        unsigned char padding_extent[168];
        struct {
            int conditions[17];
        } view_conditions;
        struct {
            MPVDecoderFields decoder;
        } view_decoder;
    } fields;
} MPVConditionState;

typedef struct MPVDctCounters {
    u8 field_078[0x18];
    s32 decoded;
    s32 skipped;
    u8 field_098[0x34];
} MPVDctCounters;

typedef union MPVDctState {
    DctFsriParams params;
    MPVDctCounters counters;
} MPVDctState;

typedef union MPVTransformWorkspace {
    float coefficients[9][64];
    DctFsriBlock blocks[6];
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
    void *buffer;
    s32 capacity;
    s32 size;
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
            unsigned char padding_field_1300[4800];
            s32 field_1300;
        } view_field_1300;
        struct {
            unsigned char padding_field_1304[4804];
            s32 field_1304;
        } view_field_1304;
        struct {
            unsigned char padding_field_1324[4852];
            s32 field_1324;
        } view_field_1324;
    } fields;
};

int fn_12_AE70(MPVContext *context, SJ *stream);

void fn_800589BC(const SJCK *source, int nbyte, SJCK *first, SJCK *remainder);

int fn_12_A660(MPVContext *handle, int error);

const unsigned char *fn_12_A0D8(const unsigned char *data, int length, int mask);

int fn_12_A2C4(const unsigned char *data);

void fn_12_ABDC(MPVContext *context, SJ *stream);

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

static inline int mpvhdec_IsWantedDelim(int delimiter_type, int wanted_mask) {
    return (delimiter_type & wanted_mask) != 0;
}

static inline const SJInterface * fn_12_AE70_read_pointer(SJ * owner) { return owner->fields.view_interface.interface; }
int fn_12_AE70(MPVContext *context, SJ *stream) {
    unsigned char * fzgx_live;
    SJCK header;
    SJCK remainder;
    SJCK chunk;
    const u8 *delimiter;
    struct { int value; } delimiter_type;
    int error;
    int picture_state;
    context->fields.view_field_1324.field_1324 =
        context->fields.view_condition_state.condition_state.fields.view_decoder.decoder.fields
            .view_field_1AC.field_1AC;
    for (;;) {
        picture_state = context->fields.view_condition_state.condition_state.fields
                            .view_conditions.conditions[1];
        if (context->fields.view_field_1300.field_1300 != 0) {
            context->fields.view_field_1300.field_1300 = 0;
            context->fields.view_field_1304.field_1304++;
            context->fields.view_error_info.error_info.fields.view_field_0C.field_0C++;
            if (picture_state == 0) {
                error = -2;
                goto error_check; /* Keep the verified branch to error_check. */
            }
            context->fields.view_error_info.error_info.fields.view_field_10.field_10++;
        }
        if (picture_state == 0) {
            error = -2;
        } else {
            error = -3;
        }
        for (;;) {
            stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
                stream, 1, 0x7FFFFFFF, &chunk);
            if (chunk.fields.view_len.len < 4) {
                stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(
                    stream, 1, &chunk);
                delimiter_type.value = 0;
            } else {
                fzgx_live = chunk.fields.view_data.data;
                delimiter = fn_12_A0D8(fzgx_live, chunk.fields.view_len.len, -1);
                if (delimiter == 0) {
                    fn_800589BC(&chunk, chunk.fields.view_len.len - 3, &chunk, &remainder);
                    fn_12_AE70_read_pointer(stream)->fields.view_put_chunk.put_chunk(
                        stream, 0, &chunk);
                    stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(
                        stream, 1, &remainder);
                    continue;
                }
                delimiter_type.value = fn_12_A2C4(delimiter);
                fzgx_live = chunk.fields.view_data.data;
                fn_800589BC(&chunk, delimiter - fzgx_live, &chunk, &remainder);
                stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(
                    stream, 0, &chunk);
                stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(
                    stream, 1, &remainder);
            }
            if (delimiter_type.value == 0) {
                break;
            }
            if (mpvhdec_IsWantedDelim(delimiter_type.value, -1)) {
                error = 0;
                break;
            }
            if (MPV_MoveChunk(stream, 1, 4) != 4) {
                break;
            }
        }
    error_check:
        if (error != 0) {
            return fn_12_A660(context, error);
        }
        stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
            stream, 1, 0x7FFFFFFF, &header);
        stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                     &header);
        if (header.fields.view_len.len >= 4 &&
            (fn_12_A2C4(header.fields.view_data.data) & 1) != 0) {
            fn_12_ABDC(context, stream);
        } else {
            return 0;
        }
    }
}

