#include "types.h"
#include "sofdec/sj.h"

/* --- rel/movie_module/fn_12_A7B0.c --- */
extern s32 fn_12_CAB4(void *movie);
extern s32 fn_12_A660(void *movie, s32 code);
extern int MPV_GoNextDelimSj(SJ *sj);
extern int MPV_MoveChunk(SJ *sj, int count, int size);

#pragma opt_propagation off
void fn_12_A7B0(void *movie, SJ *sj) {
    s32 tmp_fn_12_A660;
    void *movie_local = movie;
    u32 state;
    s32 lab_t1;

    if (fn_12_CAB4(movie_local)) {
        lab_t1 = 0xFF03020A;
        tmp_fn_12_A660 = fn_12_A660(0, lab_t1);
        tmp_fn_12_A660;
        return;
    }

    state = 0xFF030305;
    for (;;) {
        int r = MPV_GoNextDelimSj(sj);

        if (r == 0) {
            break;
        }
        if (r & 0xcc) {
            state = 0;
            break;
        }
        if (MPV_MoveChunk(sj, 1, 4) != 4) {
            break;
        }
    }

    lab_t1 = state;
    tmp_fn_12_A660 = fn_12_A660(movie_local, lab_t1);
    tmp_fn_12_A660;
}
#pragma opt_propagation reset

/* --- rel/movie_module/fn_12_A858.c --- */
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
    MPVBitReader bit_reader;
    u32 *run_level_8;
    s16 *run_level_4;
    s16 *run_level_2;
    s16 *run_level_1;
    s16 *run_level_0a;
    s16 *run_level_0b;
    s16 *run_level_0c;
    void *index_1120;
    void *index_1100;
    void *index_1160;
    void *index_1260;
    void *index_1280;
    u8 *clip_base;
    MPVCodingWorkspace coding;
    MPVDctState dct_state;
    MPVMCContext_u1 mc;
    MPVMacroblockSources sources;
    MPVOutputBlocks output_blocks;
    MPVOutputBlocks secondary_output_blocks;
    s32 state;
    s32 field_18C;
    MPVConditionState condition_state;
    u8 field_238[0x18];
    MPVErrorInfo error_info;
    MPVFrameBuffers frame_buffers;
    MPVYccPlane output;
    u32 field_2A4;
    s32 bit_rate;
    s32 vbv_buffer_units;
    u32 field_2B0;
    s32 link_flag_0;
    s32 link_flag_1;
    s32 vbv_delay;
    void (*decode_macroblock)(MPVContext_u1 *, SJ_u1 *);
    void (*skip_macroblocks)(MPVContext_u1 *, int);
    int (*decode_intra_blocks)(void *);
    int (*decode_nonintra_blocks)(void *);
    void (*motion_intra)(MPVContext_u1 *);
    void (*motion_skipped)(MPVContext_u1 *);
    void (*motion_backward)(MPVContext_u1 *);
    void (*motion_forward)(MPVContext_u1 *);
    void (*motion_bidirect)(MPVContext_u1 *);
    s32 field_2E4;
    u32 quantizer_scale;
    MPVMotionInfo forward_motion;
    MPVMotionInfo backward_motion;
    s32 macroblock_index;
    s32 macroblock_row;
    s32 macroblock_column;
    s32 last_macroblock_index;
    u32 field_344;
    s32 cbp_mask;
    s32 dc_predictor_y;
    s32 dc_predictor_cb;
    s32 dc_predictor_cr;
    s32 field_358;
    s32 stc_code_0;
    s32 stc_code_1;
    s32 stc_code_2;
    DctFsriBlock *dct_output_blocks[6];
    MPVTransformWorkspace transform;
    s8 intra_quant_matrix[64];
    s8 nonintra_quant_matrix[64];
    u8 field_D00[0x600];
    s32 field_1300;
    s32 field_1304;
    SJCK header_chunk;
    s32 field_1310;
    s32 field_1314;
    int (*decode_intra_block)(void *, void *);
    int (*decode_nonintra_block)(void *, void *);
    u8 field_1320[4];
    s32 field_1324;
    u8 *y_dc_size;
    u8 *chroma_dc_size;
    void *m2v_handle;
    s32 user_data_index;
    MPVUserStream user_streams[4];
    MPVPictureUserBuffer picture_user;
    u8 field_1374[0x0C];
};

typedef struct MPVFrameCopy {
    u32 a[12];
} MPVFrameCopy;

typedef struct MPVPictureCopy {
    u32 a[20];
} MPVPictureCopy;

extern int fn_12_AE70(MPVContext_u1 *context, SJ_u1 *stream);

extern int fn_12_20168(MPVContext_u1 *context, SJ_u1 *stream, MPVFrameBuffers *buffers);

extern void fn_12_12564(void);

extern void fn_12_52E8(void);

extern void fn_12_12590(MPVContext_u1 *context);

extern void fn_12_8B0C(MPVContext_u1 *context);

extern void fn_12_8AEC(MPVContext_u1 *context);

extern void fn_12_1258C(MPVContext_u1 *context);

extern void fn_12_33698(u32 saved[8]);

extern void fn_12_33664(u32 saved[8]);

#pragma peephole off
int fn_12_A858(SJ_u1 *context_arg, MPVFrameBuffers *stream_arg, MPVContext_u1 *buffers_arg) {
    u32 saved_gqr[8];
    int result;
    register MPVContext_u1 *context;
    int initial_decoded;
    int initial_skipped;
    register MPVFrameBuffers *buffers;
    register SJ_u1 *stream;

    stream = (SJ_u1 *)stream_arg;
    buffers = (MPVFrameBuffers *)buffers_arg;
    context = (MPVContext_u1 *)context_arg;
    if (fn_12_CAB4(context) != 0) {
        return fn_12_A660(0, 0xFF030209);
    }
    fn_12_33698(saved_gqr);
    fn_12_12564();
    fn_12_52E8();
    if (*(s32 *)((u8 *)context + 0x12d4) == 2) {
        return fn_12_20168(context, stream, buffers);
    }
    initial_decoded = *(s32 *)((u8 *)context + 0x22c);
    initial_skipped = *(s32 *)((u8 *)context + 0x230);
    *(MPVFrameCopy *)((u8 *)context + 0x234) = *(MPVFrameCopy *)buffers;
    fn_12_12590(context);
    fn_12_8B0C(context);
    fn_12_8AEC(context);

    result = fn_12_AE70(context, stream);
    fn_12_1258C(context);
    *(MPVPictureCopy *)buffers->picture_info =
        *(MPVPictureCopy *)((u8 *)context + 0x1d0);
    buffers->decoded_dct_count = *(s32 *)((u8 *)context + 0x22c) - initial_decoded;
    buffers->skipped_dct_count = *(s32 *)((u8 *)context + 0x230) - initial_skipped;
    fn_12_33664(saved_gqr);
    return result;
}
#pragma peephole reset

/* --- rel/movie_module/fn_12_A9C0.c --- */
/* --- rel/movie_module/fn_12_A9C0.c --- */
// fn_12_A9C0: empty in retail (single blr).
void fn_12_A9C0(void) {
}
