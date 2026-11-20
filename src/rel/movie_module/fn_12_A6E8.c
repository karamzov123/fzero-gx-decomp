#include "types.h"


/* --- rel/movie_module/fn_12_A6E8.c --- */
typedef struct MPVContext MPVContext;

typedef void (*MPVErrorCallback)(int object, int error);

typedef struct MPVErrorInfo {
    union {
        unsigned char padding_extent[20];
        struct {
            MPVErrorCallback callback;
        } view_callback;
        struct {
            unsigned char padding_callback_object[4];
            int callback_object;
        } view_callback_object;
        struct {
            unsigned char padding_first_error[8];
            int first_error;
        } view_first_error;
    } fields;
} MPVErrorInfo;

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
    s8 block_nonzero[6];
    u8 field_06[0x22];
    int coded_block_pattern;
    float *coefficients;
    DctFsriBlock **output_blocks;
    u8 field_34[0x14];
    float *workspace;
    u8 field_4C[8];
} DctFsriParams;

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
            unsigned char padding_callback[4];
            void (*callback)(void *argument, int index);
        } view_callback;
    } fields;
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
            unsigned char padding_error_info[544];
            MPVErrorInfo error_info;
        } view_error_info;
    } fields;
};

int fn_12_A6E8(MPVContext *handle, MPVErrorCallback callback, int object);

int MPVERR_SetCode(MPVContext *handle, int error);

int fn_12_CAB4(MPVContext *handle);

extern int fn_12_CAB4(MPVContext *handle);

extern MPVErrorInfo lbl_12_bss_4E60;

static inline int MPVERR_SetCode(MPVContext *handle, int error) {
    if (handle == 0) {
        lbl_12_bss_4E60.fields.view_first_error.first_error = error;
        if (error != 0 && lbl_12_bss_4E60.fields.view_callback.callback != 0) {
            lbl_12_bss_4E60.fields.view_callback.callback(
                lbl_12_bss_4E60.fields.view_callback_object.callback_object, error);
        }
    } else {
        handle->fields.view_error_info.error_info.fields.view_first_error.first_error = error;
        if (error != 0 &&
            handle->fields.view_error_info.error_info.fields.view_callback.callback != 0) {
            handle->fields.view_error_info.error_info.fields.view_callback.callback(
                handle->fields.view_error_info.error_info.fields.view_callback_object
                    .callback_object,
                error);
        }
    }
    return error;
}

int fn_12_A6E8(MPVContext *handle, MPVErrorCallback callback, int object) {
    if (fn_12_CAB4(handle) != 0) {
        return MPVERR_SetCode(0, 0xFF030203);
    }
    handle->fields.view_error_info.error_info.fields.view_callback.callback = callback;
    handle->fields.view_error_info.error_info.fields.view_callback_object.callback_object = object;
    return 0;
}

/* --- rel/movie_module/fn_12_A774.c --- */
typedef struct MovieState {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
} MovieState;

void fn_12_A774(MovieState *movie) {
    movie->field_0 = 0;
    movie->field_4 = 0;
    movie->field_8 = 0;
    movie->field_c = 0;
    movie->field_10 = 0;
}
