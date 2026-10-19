
#include "types.h"

typedef struct SJCK {
    unsigned char *data;
    long len;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface SJInterface;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface {
    void *reserved[3];
    void (*destroy)(SJ *sj);
    const void *(*get_uuid)(SJ *sj);
    void (*reset)(SJ *sj);
    void (*get_chunk)(SJ *sj, long channel, long max_size, SJCK *chunk);
    void (*unget_chunk)(SJ *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
    int (*get_num_data)(SJ *sj, int channel);
    int (*is_get_chunk)(SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ *sj, SJErrorCallback callback, void *object);
};

struct SJ {
    const SJInterface *interface;
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
    MPVErrorCallback callback;
    void *callback_object;
    int first_error;
    int field_0C;
    int field_10;
} MPVErrorInfo;

typedef struct MPVMCContext MPVMCContext;

typedef void (*MPVMCFunction)(MPVMCContext *context);

struct MPVMCContext {
    union {
        unsigned char padding_extent[68];
        struct {
            MPVMCFunction functions08[4];
        } view_functions08;
        struct {
            unsigned char padding_destination[24];
            u8 *destination;
        } view_destination;
    } fields;
};

typedef struct MPVPlaneSet {
    u8 *planes[3];
    s16 chroma_stride;
    s16 luma_stride;
} MPVPlaneSet;

typedef struct MPVOutputBlock {
    union {
        unsigned char padding_extent[8];
        struct {
            u8 *destination;
        } view_destination;
        struct {
            unsigned char padding_stride[4];
            s32 stride;
        } view_stride;
    } fields;
} MPVOutputBlock;

typedef struct MPVOutputBlocks {
    union {
        unsigned char padding_extent[52];
        struct {
            s32 count;
        } view_count;
        struct {
            unsigned char padding_blocks[4];
            MPVOutputBlock blocks[6];
        } view_blocks;
    } fields;
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
    union {
        unsigned char padding_extent[2304];
        struct {
            DctFsriBlock blocks[6];
        } view_blocks;
    } fields;
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
            unsigned char padding_mc[204];
            MPVMCContext mc;
        } view_mc;
        struct {
            unsigned char padding_secondary_output_blocks[340];
            MPVOutputBlocks secondary_output_blocks;
        } view_secondary_output_blocks;
        struct {
            unsigned char padding_condition_state[400];
            MPVConditionState condition_state;
        } view_condition_state;
        struct {
            unsigned char padding_field_D00[3264];
            u8 field_D00[0x600];
        } view_field_D00;
    } fields;
};

void fn_12_8B4C(MPVContext *object);

void fn_12_E0C8(MPVMCFunction functions[4]);

void fn_12_2013C(MPVMCContext *context);

void fn_12_8B4C(MPVContext *object) {
    u8 *destination;
    MPVOutputBlocks *output_blocks;
    MPVOutputBlock *blocks;
    s32 count;
    s32 i;
    fn_12_E0C8(object->fields.view_mc.mc.fields.view_functions08.functions08);
    fn_12_2013C(&object->fields.view_mc.mc);
    output_blocks = &object->fields.view_secondary_output_blocks.secondary_output_blocks;
    blocks = output_blocks->fields.view_blocks.blocks;
    destination = object->fields.view_field_D00.field_D00;
    if (object->fields.view_condition_state.condition_state.fields.view_conditions.conditions[5] ==
        0) {
        count = -1;
    } else {
        count = 4;
    }
    output_blocks->fields.view_count.count = count;
    for (i = 0; i < 6; i++) {
        blocks[i].fields.view_destination.destination = destination;
    }
    for (i = 0; i < 6; i++) {
        blocks[i].fields.view_stride.stride = 8;
    }
}
