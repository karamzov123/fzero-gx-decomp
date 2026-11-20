#include "types.h"


/* --- rel/movie_module/MPVCDEC_IntraBlocks.c --- */
typedef struct SJCK {
    unsigned char *data;
    int len;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface SJInterface;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface {
    void *reserved[3];
    void (*destroy)(SJ *sj);
    const void *(*get_uuid)(SJ *sj);
    void (*reset)(SJ *sj);
    void (*get_chunk)(SJ *sj, int channel, int max_size, SJCK *chunk);
    void (*unget_chunk)(SJ *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
    int (*get_num_data)(SJ *sj, int channel);
    int (*is_get_chunk)(SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ *sj, SJErrorCallback callback, void *object);
};

struct SJ {
    const SJInterface *interface;
};

typedef union DctFsriBlock {
    s16 samples[64];
    u32 packed[32];
} DctFsriBlock;

typedef struct DctFsriParams {
    union {
        unsigned char padding_extent[84];
        struct {
            s8 block_nonzero[6];
        } view_block_nonzero;
        struct {
            unsigned char padding_coefficients[44];
            float *coefficients;
        } view_coefficients;
    } fields;
} DctFsriParams;

typedef struct MPVContext MPVContext;

typedef void (*MPVErrorCallback)(int object, int error);

typedef struct MPVErrorInfo {
    MPVErrorCallback callback;
    int callback_object;
    int first_error;
    int field_0C;
    int field_10;
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
    u8 field_190[0x0C];
    s32 mc_table;
    s32 field_1A0;
    s32 field_1A4;
    s32 field_1A8;
    s32 field_1AC;
    void (*callback)(void *argument);
    void *callback_argument;
    u8 field_1B8[0x18];
    MPVPictureAttributes picture;
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
    union {
        unsigned char padding_extent[84];
        struct {
            DctFsriParams params;
        } view_params;
    } fields;
} MPVDctState;

typedef union MPVTransformWorkspace {
    union {
        unsigned char padding_extent[2304];
        struct {
            float coefficients[9][64];
        } view_coefficients;
    } fields;
} MPVTransformWorkspace;

typedef struct MPVCodingBlock {
    union {
        unsigned char padding_extent[48];
        struct {
            unsigned char padding_coefficients[28];
            void *coefficients;
        } view_coefficients;
        struct {
            unsigned char padding_quant_matrix[32];
            const u8 *quant_matrix;
        } view_quant_matrix;
        struct {
            unsigned char padding_quantizer_scale[36];
            s32 quantizer_scale;
        } view_quantizer_scale;
        struct {
            unsigned char padding_dc_predictor[40];
            s32 *dc_predictor;
        } view_dc_predictor;
        struct {
            unsigned char padding_dc_size_lut[44];
            const u8 *dc_size_lut;
        } view_dc_size_lut;
    } fields;
} MPVCodingBlock;

typedef struct MPVCodingWorkspace {
    union {
        unsigned char padding_extent[52];
        struct {
            MPVCodingBlock block;
        } view_block;
        struct {
            unsigned char padding_non_intra_mode[48];
            s32 non_intra_mode;
        } view_non_intra_mode;
    } fields;
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
            unsigned char padding_coding[68];
            MPVCodingWorkspace coding;
        } view_coding;
        struct {
            unsigned char padding_dct_state[120];
            MPVDctState dct_state;
        } view_dct_state;
        struct {
            unsigned char padding_quantizer_scale[700];
            u32 quantizer_scale;
        } view_quantizer_scale;
        struct {
            unsigned char padding_dc_predictor_y[792];
            s32 dc_predictor_y;
        } view_dc_predictor_y;
        struct {
            unsigned char padding_dc_predictor_cb[796];
            s32 dc_predictor_cb;
        } view_dc_predictor_cb;
        struct {
            unsigned char padding_dc_predictor_cr[800];
            s32 dc_predictor_cr;
        } view_dc_predictor_cr;
        struct {
            unsigned char padding_transform[832];
            MPVTransformWorkspace transform;
        } view_transform;
        struct {
            unsigned char padding_intra_quant_matrix[3136];
            s8 intra_quant_matrix[64];
        } view_intra_quant_matrix;
        struct {
            unsigned char padding_decode_intra_block[4840];
            int (*decode_intra_block)(void *, void *);
        } view_decode_intra_block;
        struct {
            unsigned char padding_y_dc_size[4856];
            u8 *y_dc_size;
        } view_y_dc_size;
        struct {
            unsigned char padding_chroma_dc_size[4860];
            u8 *chroma_dc_size;
        } view_chroma_dc_size;
    } fields;
};

typedef union MPVCDECIntraCoefficients {
    union {
        unsigned char padding_extent[1536];
        struct {
            f64 pairs[192];
        } view_pairs;
    } fields;
} MPVCDECIntraCoefficients;

extern void fn_12_52C4(DctFsriParams *params);

static inline void MPVCDEC_ClearCoefficients(f64 **cursor) {
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
    *(*cursor)++ = 0.0;
}

s32 MPVCDEC_IntraBlocks(MPVContext *context) {
    MPVCodingBlock *block;
    DctFsriParams *params;
    {
        MPVCDECIntraCoefficients *coefficients =
            (MPVCDECIntraCoefficients *)&context->fields.view_transform.transform.fields
                .view_coefficients.coefficients[3];
        f64 *cursor = coefficients->fields.view_pairs.pairs;
        MPVCDEC_ClearCoefficients(&cursor);
        MPVCDEC_ClearCoefficients(&cursor);
        MPVCDEC_ClearCoefficients(&cursor);
        MPVCDEC_ClearCoefficients(&cursor);
        MPVCDEC_ClearCoefficients(&cursor);
        MPVCDEC_ClearCoefficients(&cursor);
    }
    block = &context->fields.view_coding.coding.fields.view_block.block;
    params = &context->fields.view_dct_state.dct_state.fields.view_params.params;
    block->fields.view_quantizer_scale.quantizer_scale =
        context->fields.view_quantizer_scale.quantizer_scale;
    block->fields.view_quant_matrix.quant_matrix =
        (const u8 *)context->fields.view_intra_quant_matrix.intra_quant_matrix;
    context->fields.view_coding.coding.fields.view_non_intra_mode.non_intra_mode = 0;
    block->fields.view_dc_size_lut.dc_size_lut = context->fields.view_y_dc_size.y_dc_size;
    block->fields.view_dc_predictor.dc_predictor =
        &context->fields.view_dc_predictor_y.dc_predictor_y;
    block->fields.view_coefficients.coefficients =
        context->fields.view_transform.transform.fields.view_coefficients.coefficients[3];
    params->fields.view_block_nonzero.block_nonzero[0] =
        context->fields.view_decode_intra_block.decode_intra_block(context, block);
    block->fields.view_coefficients.coefficients =
        context->fields.view_transform.transform.fields.view_coefficients.coefficients[4];
    params->fields.view_block_nonzero.block_nonzero[1] =
        context->fields.view_decode_intra_block.decode_intra_block(context, block);
    block->fields.view_coefficients.coefficients =
        context->fields.view_transform.transform.fields.view_coefficients.coefficients[5];
    params->fields.view_block_nonzero.block_nonzero[2] =
        context->fields.view_decode_intra_block.decode_intra_block(context, block);
    block->fields.view_coefficients.coefficients =
        context->fields.view_transform.transform.fields.view_coefficients.coefficients[6];
    params->fields.view_block_nonzero.block_nonzero[3] =
        context->fields.view_decode_intra_block.decode_intra_block(context, block);
    block->fields.view_dc_size_lut.dc_size_lut = context->fields.view_chroma_dc_size.chroma_dc_size;
    block->fields.view_dc_predictor.dc_predictor =
        &context->fields.view_dc_predictor_cb.dc_predictor_cb;
    block->fields.view_coefficients.coefficients =
        context->fields.view_transform.transform.fields.view_coefficients.coefficients[7];
    params->fields.view_block_nonzero.block_nonzero[4] =
        context->fields.view_decode_intra_block.decode_intra_block(context, block);
    block->fields.view_dc_predictor.dc_predictor =
        &context->fields.view_dc_predictor_cr.dc_predictor_cr;
    block->fields.view_coefficients.coefficients =
        context->fields.view_transform.transform.fields.view_coefficients.coefficients[8];
    params->fields.view_block_nonzero.block_nonzero[5] =
        context->fields.view_decode_intra_block.decode_intra_block(context, block);
    fn_12_52C4(params);
    return 0;
}

/* --- rel/movie_module/fn_12_77F4.c --- */
typedef struct {
    int first;
    int second;
} FnResult;

typedef struct {
    char pad[0x1d8];
    void *value;
} MovieObject;

typedef struct {
    char pad[0xc];
    s16 x;
    s16 y;
} Scale;

extern FnResult fn_8007E914(void *arg0, void *arg1);

void fn_12_77F4(MovieObject *movie, void *arg1, int *out, const Scale *scale) {
    FnResult result;
    s16 x;
    s16 y;
    int first;
    int second;

    result = fn_8007E914(arg1, movie->value);
    first = result.first;
    second = result.second;
    x = scale->x;
    y = scale->y;
    out[0] = (first << 3) * x + (second << 3);
    out[1] = (first << 4) * y + (second << 4);
}
