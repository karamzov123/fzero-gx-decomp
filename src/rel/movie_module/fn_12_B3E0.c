
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
            MPVErrorCallback callback;
        } view_callback;
    } fields;
} MPVErrorInfo;

typedef struct MPVMCContext MPVMCContext;

typedef void (*MPVMCFunction)(MPVMCContext *context);

struct MPVMCContext {
    MPVMCFunction functions08[4];
    u8 field_10[8];
    u8 *destination;
    u32 field_1c;
    s32 reference_stride;
    const u8 *reference0;
    const u8 *reference1;
    u8 field_2c[8];
    MPVMCFunction functions16[4];
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
            unsigned char padding_callback[32];
            void (*callback)(void *argument);
        } view_callback;
        struct {
            unsigned char padding_callback_argument[36];
            void *callback_argument;
        } view_callback_argument;
    } fields;
} MPVDecoderFields;

typedef union MPVConditionState {
    int conditions[17];
    MPVDecoderFields decoder;
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
    union {
        unsigned char padding_extent[12];
        struct {
            SJ *stream;
        } view_stream;
        struct {
            unsigned char padding_callback[4];
            void (*callback)(void *argument, int index);
        } view_callback;
        struct {
            unsigned char padding_callback_argument[8];
            void *callback_argument;
        } view_callback_argument;
    } fields;
} MPVUserStream;

typedef struct MPVPictureUserBuffer {
    union {
        unsigned char padding_extent[12];
        struct {
            void *buffer;
        } view_buffer;
        struct {
            unsigned char padding_capacity[4];
            s32 capacity;
        } view_capacity;
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
            unsigned char padding_user_data_index[0x1304];
            s32 user_data_index;
        } view_user_data_index;
        struct {
            unsigned char padding_user_streams[0x1308];
            MPVUserStream user_streams[4];
        } view_user_streams;
        struct {
            unsigned char padding_picture_user[0x1338];
            MPVPictureUserBuffer picture_user;
        } view_picture_user;
    } fields;
};

int fn_12_B3E0(MPVContext *context, const u8 *data, int length);

int fn_12_A2C4(const unsigned char *data);

void *memcpy(void *destination, const void *source, unsigned long size);

int fn_12_B254(MPVContext *context, const u8 *data, int length);

#pragma peephole on
#pragma opt_propagation off
#pragma opt_lifetimes off
int fn_12_B3E0(MPVContext *context, const u8 *data, int length) {
    SJ *user_sj;
    SJCK first;
    SJCK second;
    int delimiter_result;
    int sequence_result;
    int index;
    int delimiter_offset;
    int scan_index;
    int picture_copy_size;
    sequence_result = 0;
    delimiter_result = 0;
    delimiter_offset = length - 3;
    scan_index = 4;
    index = context->fields.view_user_data_index.user_data_index;
    while (scan_index < delimiter_offset) {
        if (fn_12_A2C4(data + scan_index) != 0) {
            break;
        }
        scan_index++;
    }
    if (scan_index == length - 3) {
        delimiter_result = -1;
    }
    delimiter_offset = scan_index;
    if (index == 1) {
        sequence_result = fn_12_B254(context, data, scan_index);
    }
    user_sj = ((index)[context->fields.view_user_streams.user_streams]).fields.view_stream.stream;
    if (user_sj != 0) {
        (user_sj->fields.view_interface.interface)->fields.view_get_chunk.get_chunk(
            user_sj, 0, delimiter_offset, &first);
        memcpy(first.fields.view_data.data, data, first.fields.view_len.len);
        (user_sj->fields.view_interface.interface)->fields.view_put_chunk.put_chunk(user_sj, 1,
                                                                                  &first);
        if (first.fields.view_len.len < delimiter_offset) {
            (user_sj->fields.view_interface.interface)->fields.view_get_chunk.get_chunk(
                user_sj, 0, delimiter_offset - first.fields.view_len.len, &second);
            memcpy(second.fields.view_data.data, data + first.fields.view_len.len,
                   second.fields.view_len.len);
            (user_sj->fields.view_interface.interface)->fields.view_put_chunk.put_chunk(user_sj, 1,
                                                                                      &second);
        }
        if (((index)[context->fields.view_user_streams.user_streams]).fields.view_callback.callback !=
            0) {
            ((index)[context->fields.view_user_streams.user_streams]).fields.view_callback.callback(
                ((index)[context->fields.view_user_streams.user_streams])
                    .fields.view_callback_argument.callback_argument,
                index);
        }
    }
    if (index == 3 &&
        context->fields.view_picture_user.picture_user.fields.view_buffer.buffer != 0) {
        picture_copy_size =
            context->fields.view_picture_user.picture_user.fields.view_capacity.capacity;
        if (delimiter_offset < picture_copy_size) {
            picture_copy_size = delimiter_offset;
        }
        context->fields.view_picture_user.picture_user.fields.view_size.size = picture_copy_size;
        memcpy((context->fields.view_picture_user.picture_user.fields.view_buffer.buffer), data,
               context->fields.view_picture_user.picture_user.fields.view_size.size);
    }
    if (sequence_result != 0) {
        return sequence_result;
    }
    return delimiter_result;
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset

#pragma peephole reset

