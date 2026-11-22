#include "sofdec/mpv.h"
#include "types.h"


/* --- rel/movie_module/MPV_GoNextDelimSj.c --- */
void fn_800589BC(const SJCK *source, int nbyte, SJCK *first, SJCK *remainder);

const unsigned char *fn_12_A0D8(const unsigned char *data, int length, int mask);

int fn_12_A2C4(const unsigned char *data);

int MPV_GoNextDelimSj(SJ *stream) {
    SJCK chunk;
    SJCK remainder;
    const u8 *delimiter;
    int delimiter_type;
    for (;;) {
        stream->interface->get_chunk(stream, 1, 0x7FFFFFFF, &chunk);
        if (chunk.len < 4) {
            stream->interface->unget_chunk(stream, 1, &chunk);
            delimiter_type = 0;
            break;
        }
        delimiter = fn_12_A0D8(chunk.data, chunk.len, -1);
        if (delimiter == 0) {
            fn_800589BC(&chunk, chunk.len - 3, &chunk, &remainder);
            stream->interface->put_chunk(stream, 0, &chunk);
            stream->interface->unget_chunk(stream, 1, &remainder);
            continue;
        }
        delimiter_type = fn_12_A2C4(delimiter);
        fn_800589BC(&chunk, delimiter - chunk.data, &chunk, &remainder);
        stream->interface->put_chunk(stream, 0, &chunk);
        stream->interface->unget_chunk(stream, 1, &remainder);
        break;
    }
    return delimiter_type;
}

/* --- rel/movie_module/fn_12_B254.c --- */
extern const f64 lbl_12_rodata_87C;
extern const f64 lbl_12_rodata_884;


typedef struct SJ_u1 SJ_u1;

typedef struct SJInterface_u1 SJInterface_u1;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface_u1 {
    void *reserved[3];
    void (*destroy)(SJ_u1 *sj);
    const void *(*get_uuid)(SJ_u1 *sj);
    void (*reset)(SJ_u1 *sj);
    void (*get_chunk)(SJ_u1 *sj, int channel, int max_size, SJCK *chunk);
    void (*unget_chunk)(SJ_u1 *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ_u1 *sj, int channel, SJCK *chunk);
    int (*get_num_data)(SJ_u1 *sj, int channel);
    int (*is_get_chunk)(SJ_u1 *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ_u1 *sj, SJErrorCallback callback, void *object);
};

struct SJ_u1 {
    const SJInterface_u1 *interface;
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

typedef struct MPVContext_u1 MPVContext_u1;

typedef void (*MPVErrorCallback)(int object, int error);

typedef struct MPVErrorInfo {
    MPVErrorCallback callback;
    int callback_object;
    int first_error;
    int field_0C;
    int field_10;
} MPVErrorInfo;

typedef struct MPVMCContext_u1 MPVMCContext_u1;

typedef void (*MPVMCFunction)(MPVMCContext_u1 *context);

struct MPVMCContext_u1 {
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
    SJ_u1 *stream;
    void (*callback)(void *argument, int index);
    void *callback_argument;
} MPVUserStream;

typedef struct MPVPictureUserBuffer {
    void *buffer;
    s32 capacity;
    s32 size;
} MPVPictureUserBuffer;

struct MPVContext_u1 {
    union {
        unsigned char padding_extent[4992];
        struct {
            unsigned char padding_stc_code_0[4824];
            s32 stc_code_0;
        } view_stc_code_0;
        struct {
            unsigned char padding_stc_code_1[4828];
            s32 stc_code_1;
        } view_stc_code_1;
        struct {
            unsigned char padding_stc_code_2[4832];
            s32 stc_code_2;
        } view_stc_code_2;
        struct {
            unsigned char padding_field_1314[4836];
            s32 field_1314;
        } view_field_1314;
        struct {
            unsigned char padding_decode_intra_block[4840];
            int (*decode_intra_block)(void *, void *);
        } view_decode_intra_block;
        struct {
            unsigned char padding_decode_nonintra_block[4844];
            int (*decode_nonintra_block)(void *, void *);
        } view_decode_nonintra_block;
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

int fn_12_B254(MPVContext_u1 *context, const u8 *data, int length);


int atoi(const char *str);

int strncmp(const char *lhs, const char *rhs, unsigned long count);

extern u8 *lbl_12_bss_6918;

extern u8 *lbl_12_bss_6914;

extern u8 *lbl_12_bss_6910;

extern u8 *lbl_12_bss_690C;

extern int MPVABDEC_IntraBlock(void *context, void *block);

extern int MPVABDEC_IntraBlockDc11(void *context, void *block);

extern int MPVABDEC_NintraBlock(void *context, void *block);

int fn_12_B254(MPVContext_u1 *context, const u8 *data, int length) {
    const u8 *current;
    int offset;
    int result;
    result = 0;
    offset = 0;
    while (offset < length - 4) {
        current = data + offset;
        if (strncmp((const char *)(current += 4), (const char *)&lbl_12_rodata_87C, 7) == 0) {
            if (atoi((const char *)current + 0x10) == 0) {
                context->fields.view_field_1314.field_1314 = 0;
            } else {
                context->fields.view_field_1314.field_1314 = 3;
            }
        }
        if (strncmp((const char *)current, (const char *)&lbl_12_rodata_884, 7) == 0) {
            context->fields.view_stc_code_0.stc_code_0 = atoi((const char *)current + 0x10);
            context->fields.view_stc_code_1.stc_code_1 = atoi((const char *)current + 0x18);
            context->fields.view_stc_code_2.stc_code_2 = atoi((const char *)current + 0x20);
        }
        if (fn_12_A2C4(current) != 0) {
            break;
        }
        offset++;
    }
    if (context->fields.view_field_1314.field_1314 == 0) {
        context->fields.view_decode_intra_block.decode_intra_block = MPVABDEC_IntraBlock;
        context->fields.view_y_dc_size.y_dc_size = lbl_12_bss_6918;
        context->fields.view_chroma_dc_size.chroma_dc_size = lbl_12_bss_6914;
    } else {
        context->fields.view_decode_intra_block.decode_intra_block = MPVABDEC_IntraBlockDc11;
        context->fields.view_y_dc_size.y_dc_size = lbl_12_bss_6910;
        context->fields.view_chroma_dc_size.chroma_dc_size = lbl_12_bss_690C;
    }
    if (context->fields.view_stc_code_0.stc_code_0 == 8) {
        result = -1;
    } else {
        if (context->fields.view_field_1314.field_1314 == 0) {
            context->fields.view_decode_intra_block.decode_intra_block = MPVABDEC_IntraBlock;
        } else {
            context->fields.view_decode_intra_block.decode_intra_block = MPVABDEC_IntraBlockDc11;
        }
        context->fields.view_decode_nonintra_block.decode_nonintra_block = MPVABDEC_NintraBlock;
    }
    return result;
}
