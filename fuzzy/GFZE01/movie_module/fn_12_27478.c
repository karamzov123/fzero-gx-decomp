/* Non-matching: best partial attempt (90.41% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "sofdec/sfd.h"
typedef struct Sig_fn_12_A858_MPVMCContext Sig_fn_12_A858_MPVMCContext;
typedef struct Sig_fn_12_A858_SJInterface Sig_fn_12_A858_SJInterface;
typedef struct Sig_fn_12_A858_SJ Sig_fn_12_A858_SJ;
typedef struct Sig_fn_12_A858_MPVContext Sig_fn_12_A858_MPVContext;
typedef struct Sig_fn_12_2AC80_MovieState Sig_fn_12_2AC80_MovieState;
typedef struct Sig_fn_12_2AC80_MovieObject Sig_fn_12_2AC80_MovieObject;
typedef struct Sig_fn_12_A858_MPVBitReader {
    u32 bits;
    u32 next_bits;
    s32 bit_offset;
    const u32 *words;
} Sig_fn_12_A858_MPVBitReader;
typedef struct Sig_fn_12_A858_MPVCodingBlock {
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
} Sig_fn_12_A858_MPVCodingBlock;
typedef struct Sig_fn_12_A858_MPVCodingWorkspace {
    Sig_fn_12_A858_MPVCodingBlock block;
    s32 non_intra_mode;
} Sig_fn_12_A858_MPVCodingWorkspace;
typedef union Sig_fn_12_A858_DctFsriBlock {
    s16 samples[64];
    u32 packed[32];
} Sig_fn_12_A858_DctFsriBlock;
typedef struct Sig_fn_12_A858_DctFsriParams {
    s8 block_nonzero[6];
    u8 field_06[0x22];
    int coded_block_pattern;
    float *coefficients;
    Sig_fn_12_A858_DctFsriBlock **output_blocks;
    u8 field_34[0x14];
    float *workspace;
    u8 field_4C[8];
} Sig_fn_12_A858_DctFsriParams;
typedef struct Sig_fn_12_A858_MPVDctCounters {
    u8 field_078[0x18];
    s32 decoded;
    s32 skipped;
    u8 field_098[0x34];
} Sig_fn_12_A858_MPVDctCounters;
typedef union Sig_fn_12_A858_MPVDctState {
    Sig_fn_12_A858_DctFsriParams params;
    Sig_fn_12_A858_MPVDctCounters counters;
} Sig_fn_12_A858_MPVDctState;
typedef void (*Sig_fn_12_A858_MPVMCFunction)(Sig_fn_12_A858_MPVMCContext *context);
struct Sig_fn_12_A858_MPVMCContext {
    Sig_fn_12_A858_MPVMCFunction functions08[4];
    u8 field_10[8];
    u8 *destination;
    u32 field_1c;
    s32 reference_stride;
    const u8 *reference0;
    const u8 *reference1;
    u8 field_2c[8];
    Sig_fn_12_A858_MPVMCFunction functions16[4];
};
typedef struct Sig_fn_12_A858_MPVMacroblockSources {
    void *field_00;
    s16 *residual;
    u8 *prediction0;
    u8 *prediction1;
} Sig_fn_12_A858_MPVMacroblockSources;
typedef struct Sig_fn_12_A858_MPVOutputBlock {
    u8 *destination;
    s32 stride;
} Sig_fn_12_A858_MPVOutputBlock;
typedef struct Sig_fn_12_A858_MPVOutputBlocks {
    s32 count;
    Sig_fn_12_A858_MPVOutputBlock blocks[6];
} Sig_fn_12_A858_MPVOutputBlocks;
typedef struct Sig_fn_12_A858_MPVPictureAttributes {
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
} Sig_fn_12_A858_MPVPictureAttributes;
typedef struct Sig_fn_12_A858_MPVDecoderFields {
    u8 field_190[0x0C];
    s32 mc_table;
    s32 field_1A0;
    s32 field_1A4;
    s32 field_1A8;
    s32 field_1AC;
    void (*callback)(void *argument);
    void *callback_argument;
    u8 field_1B8[0x18];
    Sig_fn_12_A858_MPVPictureAttributes picture;
} Sig_fn_12_A858_MPVDecoderFields;
typedef union Sig_fn_12_A858_MPVConditionState {
    int conditions[17];
    Sig_fn_12_A858_MPVDecoderFields decoder;
} Sig_fn_12_A858_MPVConditionState;
typedef void (*Sig_fn_12_A858_MPVErrorCallback)(int object, int error);
typedef struct Sig_fn_12_A858_MPVErrorInfo {
    Sig_fn_12_A858_MPVErrorCallback callback;
    int callback_object;
    int first_error;
    int field_0C;
    int field_10;
} Sig_fn_12_A858_MPVErrorInfo;
typedef struct Sig_fn_12_A858_MPVPlaneSet {
    u8 *planes[3];
    s16 chroma_stride;
    s16 luma_stride;
} Sig_fn_12_A858_MPVPlaneSet;
typedef struct Sig_fn_12_A858_MPVPictureInfo {
    Sig_fn_12_A858_MPVPictureAttributes attributes;
    u8 decoder_state[0x18];
} Sig_fn_12_A858_MPVPictureInfo;
typedef struct Sig_fn_12_A858_MPVFrameBuffers {
    Sig_fn_12_A858_MPVPlaneSet forward;
    Sig_fn_12_A858_MPVPlaneSet backward;
    u8 *output_rfb;
    Sig_fn_12_A858_MPVPictureInfo *picture_info;
    s32 decoded_dct_count;
    s32 skipped_dct_count;
} Sig_fn_12_A858_MPVFrameBuffers;
typedef struct Sig_fn_12_A858_MPVYccPlane {
    u8 *chroma0;
    u8 *chroma1;
    u8 *luma;
    s16 chroma_stride;
    s16 luma_stride;
} Sig_fn_12_A858_MPVYccPlane;
typedef struct Sig_fn_12_A858_SJCK {
    unsigned char *data;
    int len;
} Sig_fn_12_A858_SJCK;
typedef void (*Sig_fn_12_A858_SJErrorCallback)(void *object, int error);
struct Sig_fn_12_A858_SJInterface {
    void *reserved[3];
    void (*destroy)(Sig_fn_12_A858_SJ *sj);
    const void *(*get_uuid)(Sig_fn_12_A858_SJ *sj);
    void (*reset)(Sig_fn_12_A858_SJ *sj);
    void (*get_chunk)(Sig_fn_12_A858_SJ *sj, int channel, int max_size, Sig_fn_12_A858_SJCK *chunk);
    void (*unget_chunk)(Sig_fn_12_A858_SJ *sj, int channel, Sig_fn_12_A858_SJCK *chunk);
    void (*put_chunk)(Sig_fn_12_A858_SJ *sj, int channel, Sig_fn_12_A858_SJCK *chunk);
    int (*get_num_data)(Sig_fn_12_A858_SJ *sj, int channel);
    int (*is_get_chunk)(Sig_fn_12_A858_SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(Sig_fn_12_A858_SJ *sj, Sig_fn_12_A858_SJErrorCallback callback, void *object);
};
struct Sig_fn_12_A858_SJ {
    const Sig_fn_12_A858_SJInterface *interface;
};
typedef struct Sig_fn_12_A858_MPVMotionInfo {
    s32 full_pel;
    s32 r_size;
    s32 shift;
    s32 limit;
    s32 previous_horizontal;
    s32 previous_vertical;
    s32 horizontal;
    s32 vertical;
    u8 field_20[4];
} Sig_fn_12_A858_MPVMotionInfo;
typedef union Sig_fn_12_A858_MPVTransformWorkspace {
    float coefficients[9][64];
    Sig_fn_12_A858_DctFsriBlock blocks[6];
} Sig_fn_12_A858_MPVTransformWorkspace;
typedef struct Sig_fn_12_A858_MPVUserStream {
    Sig_fn_12_A858_SJ *stream;
    void (*callback)(void *argument, int index);
    void *callback_argument;
} Sig_fn_12_A858_MPVUserStream;
typedef struct Sig_fn_12_A858_MPVPictureUserBuffer {
    void *buffer;
    s32 capacity;
    s32 size;
} Sig_fn_12_A858_MPVPictureUserBuffer;
struct Sig_fn_12_A858_MPVContext {
    Sig_fn_12_A858_MPVBitReader bit_reader;
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
    Sig_fn_12_A858_MPVCodingWorkspace coding;
    Sig_fn_12_A858_MPVDctState dct_state;
    Sig_fn_12_A858_MPVMCContext mc;
    Sig_fn_12_A858_MPVMacroblockSources sources;
    Sig_fn_12_A858_MPVOutputBlocks output_blocks;
    Sig_fn_12_A858_MPVOutputBlocks secondary_output_blocks;
    s32 state;
    s32 field_18C;
    Sig_fn_12_A858_MPVConditionState condition_state;
    u8 field_238[0x18];
    Sig_fn_12_A858_MPVErrorInfo error_info;
    Sig_fn_12_A858_MPVFrameBuffers frame_buffers;
    Sig_fn_12_A858_MPVYccPlane output;
    u32 field_2A4;
    s32 bit_rate;
    s32 vbv_buffer_units;
    u32 field_2B0;
    s32 link_flag_0;
    s32 link_flag_1;
    s32 vbv_delay;
    void (*decode_macroblock)(Sig_fn_12_A858_MPVContext *, Sig_fn_12_A858_SJ *);
    void (*skip_macroblocks)(Sig_fn_12_A858_MPVContext *, int);
    int (*decode_intra_blocks)(void *);
    int (*decode_nonintra_blocks)(void *);
    void (*motion_intra)(Sig_fn_12_A858_MPVContext *);
    void (*motion_skipped)(Sig_fn_12_A858_MPVContext *);
    void (*motion_backward)(Sig_fn_12_A858_MPVContext *);
    void (*motion_forward)(Sig_fn_12_A858_MPVContext *);
    void (*motion_bidirect)(Sig_fn_12_A858_MPVContext *);
    s32 field_2E4;
    u32 quantizer_scale;
    Sig_fn_12_A858_MPVMotionInfo forward_motion;
    Sig_fn_12_A858_MPVMotionInfo backward_motion;
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
    Sig_fn_12_A858_DctFsriBlock *dct_output_blocks[6];
    Sig_fn_12_A858_MPVTransformWorkspace transform;
    s8 intra_quant_matrix[64];
    s8 nonintra_quant_matrix[64];
    u8 field_D00[0x600];
    s32 field_1300;
    s32 field_1304;
    Sig_fn_12_A858_SJCK header_chunk;
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
    Sig_fn_12_A858_MPVUserStream user_streams[4];
    Sig_fn_12_A858_MPVPictureUserBuffer picture_user;
    u8 field_1374[0x0C];
};
typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);
typedef struct Sig_fn_12_24A88_MovieObject {
    u8 pad_0000[0x48];
    s32 state;
    u8 pad_004c[0x940];
    Sig_fn_12_24A88_MovieCallback callback;
    void *callback_context;
    s32 callback_data;
} Sig_fn_12_24A88_MovieObject;
typedef struct Sig_fn_12_21E20_MovieEntry {
    char unk00[0x2c];
    int value;
    char unk30[0x44];
} Sig_fn_12_21E20_MovieEntry;
typedef struct Sig_fn_12_21E20_MovieModule {
    char unk0000[0x1148];
    Sig_fn_12_21E20_MovieEntry entries[1];
} Sig_fn_12_21E20_MovieModule;
struct Sig_fn_12_2AC80_MovieState {
    u8 _pad_80[0x80];
    int value;
};
struct Sig_fn_12_2AC80_MovieObject {
    u8 _pad_1b30[0x1b30];
    Sig_fn_12_2AC80_MovieState *state;
};
typedef struct Sig_fn_12_CCB0_MovieData {
    u8 unk_90[0x90];
    u32 unk_120;
    u32 unk_124;
} Sig_fn_12_CCB0_MovieData;
typedef void (*Sig_fn_12_2BA6C_MovieCallback)(struct Sig_fn_12_2BA6C_MovieModule *, void *, int *);
struct Sig_fn_12_2BA6C_MovieModule {
    char pad_94c[0x94c];
    int value_94c;
};
typedef void (*Sig_fn_12_2BA6C_MovieCallback)(struct Sig_fn_12_2BA6C_MovieModule *, void *, int *);

typedef struct Rect {
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    s32 width;
    s32 height;
    s32 pad;
} Rect;

typedef struct Buffer {
    void *data;
    u32 size;
} Buffer;

typedef struct Picture {
    s32 field_00;
    s32 field_04;
    s32 field_08;
    s32 field_0c;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1c;
    s32 field_20;
    Buffer *field_24;
} Picture;

typedef struct MovieFrame {
    u32 field_00;
    u32 field_04;
    u32 field_08;
    u32 field_0c;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    u32 field_24;
    s32 field_28;
    s32 field_2c;
    u32 field_30;
    u32 field_34;
    u32 field_38;
} MovieFrame;

typedef struct MovieSub {
    u32 field_00;
    u8 pad_04[0x14];
    s32 field_18;
    u8 pad_1c[0x18];
    s32 field_34;
} MovieSub;

typedef struct MovieStream {
    void *unk_0;
    u8 pad_04[0x70];
    s32 field_74;
    u8 pad_78[0x0c];
    s32 field_84;
    s32 field_88;
    MovieSub sub;
    u8 pad_c4[0x6c];
    u32 field_130;
    u8 pad_134[0x790];
    s32 field_8c4;
    s32 field_8c8;
} MovieStream;

typedef struct MovieObject {
    u8 pad_00[0x38];
    s32 field_38;
    u8 pad_3c[0x918];
    u32 field_954;
    u32 field_958;
    u8 pad_95c[0x3c];
    s32 field_998;
    s32 field_99c;
    u8 pad_9a0[0x10];
    s32 field_9b0;
    u8 pad_9b4[0x3a0];
    s32 field_d54;
    Rect field_d58;
    s32 field_d74;
    s32 field_d78;
    u8 pad_d7c[0x28];
    s32 field_da4;
    Rect field_da8;
    s32 field_dc4;
    s32 field_dc8;
    u8 pad_dcc[0x14];
    s32 field_de0;
    u8 pad_de4[0x118];
    s32 field_efc;
    s32 field_f00;
    s32 field_f04;
    u8 pad_f08[0xb28];
    MovieStream *field_1b30;
    s32 field_1b34;
    s32 field_1b38;
} MovieObject;

extern int fn_12_A858(Sig_fn_12_A858_SJ *, Sig_fn_12_A858_MPVFrameBuffers *, Sig_fn_12_A858_MPVContext *);
extern s32 fn_12_24A88(Sig_fn_12_24A88_MovieObject *, s32);
extern s64 fn_12_335B8(void);
extern int fn_12_27224(MovieObject *, u32 *, MovieFrame *, Picture **);
extern u32 fn_80057D88(u32, u32, u32);
extern void * memcpy(void *, const void *, u32);
extern void fn_12_21E20(Sig_fn_12_21E20_MovieModule *, int, int);
extern void fn_12_2AB2C(int *);
extern void fn_12_2AB40(int *);
extern void fn_12_2AB54(int *);
extern void fn_12_2AC80(Sig_fn_12_2AC80_MovieObject *, int);
extern void fn_12_2BA6C(struct Sig_fn_12_2BA6C_MovieModule *, int, void *);
extern void fn_12_2E374(u32, u32, u32);
extern void fn_12_CCB0(const Sig_fn_12_CCB0_MovieData *, u32 *, u32 *);

s32 fn_12_27478(MovieObject *movie, u32 arg1) {
    MovieStream *stream;
    MovieSub *sub;
    void *stream_data;
    Picture *pic;
    Rect rect;
    MovieFrame frame;
    s32 y;
    s32 x;
    s32 decode_result;
    s32 ticks;
    s32 error;
    s64 start_time;

    stream = movie->field_1b30;
    sub = &stream->sub;
    stream_data = stream->unk_0;

    if (fn_12_27224(movie, &sub->field_00, &frame, &pic) != 0) {
        return 0;
    }

    if (stream->field_8c8 > 0) {
        memcpy(pic->field_24->data, (const void *)stream->field_8c4, stream->field_8c8);
        pic->field_24->size = stream->field_8c8;
    }

    if (movie->field_da4 == 0) {
        int flag = 0;
        rect = movie->field_d58;
        switch (stream->field_74) {
        case 2:
            flag = 1;
            break;
        case 3:
            flag = 1;
            break;
        case 4:
            break;
        }
        if (flag == 0 && movie->field_9b0 != 0) {
            rect.pad = 0;
        }
        fn_12_2E374((u32)&rect, (u32)&x, (u32)&y);
        movie->field_da8 = rect;
        movie->field_dc4 = x - movie->field_efc;
        movie->field_dc8 = y;
        movie->field_da4 = 1;
    }

    start_time = fn_12_335B8();
    ticks = (s32)fn_80057D88(arg1, 0, 1);
    decode_result = fn_12_A858((Sig_fn_12_A858_SJ *)stream_data, (Sig_fn_12_A858_MPVFrameBuffers *)arg1,
                              (Sig_fn_12_A858_MPVContext *)&frame);
    ticks = (s32)fn_80057D88(arg1, 0, 1) - ticks;
    SFTMR_AddTsum((SfdTimerSummary *)((u8 *)movie + 0x2918 + (sub->field_18 << 5)),
                  fn_12_335B8() - start_time);

    movie->field_998 = movie->field_998 + frame.field_28;
    movie->field_99c = movie->field_99c + frame.field_2c;

    switch (decode_result) {
    case 0:
        error = 0;
        break;
    case -2:
        if (ticks > 0) {
            error = 0;
        } else {
            error = fn_12_24A88((Sig_fn_12_24A88_MovieObject *)movie, -2);
        }
        break;
    case -3:
        if (ticks > 0) {
            error = 0;
        } else {
            error = fn_12_24A88((Sig_fn_12_24A88_MovieObject *)movie, -3);
        }
        break;
    default:
        error = fn_12_24A88((Sig_fn_12_24A88_MovieObject *)movie, (s32)0xFF000F06);
        break;
    }

    fn_12_21E20((Sig_fn_12_21E20_MovieModule *)movie, movie->field_1b38, ticks);

    if (error != 0) {
        fn_12_2AB54((int *)pic);
        return error;
    }

    if (ticks > 0) {
        fn_12_2AC80((Sig_fn_12_2AC80_MovieObject *)movie, 0);
        pic->field_0c = movie->field_d78;
        pic->field_08 = (movie->field_d74 - movie->field_dc4) + movie->field_de0;
        pic->field_1c = movie->field_d74;
        pic->field_20 = movie->field_d74 + movie->field_de0;
        if (movie->field_f00 < pic->field_08) {
            movie->field_f00 = pic->field_08;
            movie->field_f04 = pic->field_0c;
        }
        pic->field_18 = stream->field_88;
        pic->field_10 = frame.field_28;
        pic->field_14 = frame.field_2c;
        stream->field_130 = (sub->field_34 == 3 || stream->field_130 != 0) ? 0 : (u32)pic;
        if (stream->field_130 == 0) {
            if (movie->field_38 == 3 && (sub->field_18 == 1 || sub->field_18 == 2)) {
                fn_12_2AB2C((int *)pic);
            } else {
                fn_12_2AB40((int *)pic);
            }
            fn_12_CCB0((Sig_fn_12_CCB0_MovieData *)stream_data, &movie->field_954, &movie->field_958);
            fn_12_2BA6C((struct Sig_fn_12_2BA6C_MovieModule *)movie, 1, (void *)sub->field_18);
            stream->field_84 = 0;
        }
    } else {
        if (stream->field_130 == 0) {
            fn_12_2AB54((int *)pic);
        }
    }

    return 0;
}
