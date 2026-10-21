/* Non-matching: best partial attempt (74.37% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

/* fn_12_B598, from the CC0 MK Deception decomp (mpv_hdec.c) */

typedef struct SJCK {
    unsigned char *data;
    long len;
} SJCK;
void SJRBF_Init(void);
void SJRBF_Finish(void);
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
SJ *SJRBF_Create(void *buffer, int buffer_size, int extra_size);
int SJRBF_GetFlowCnt(SJ *sj, int channel, int counter);
SJ *SJMEM_Create(void *buffer, int buffer_size);
int SJMEM_GetBufSize(SJ *sj);
unsigned char *SJ_SearchTag(SJCK *source, const char *tag, const char *terminator, SJCK *result);
void SJ_SplitChunk(const SJCK *source, int nbyte, SJCK *first, SJCK *remainder);
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
void DCT_FsriInitPa(DctFsriParams *params);
void DCT_FsriInit(void);
void DCT_FsriInitScaleTbl(float scale_table[64]);
typedef struct MPVContext MPVContext;
typedef void (*MPVErrorCallback)(void *object, int error);
typedef struct MPVErrorInfo {
    MPVErrorCallback callback;
    void *callback_object;
    int first_error;
    int field_0C;
    int field_10;
} MPVErrorInfo;
int MPVERR_SetCode(MPVContext *handle, int error);
int MPV_SetErrFunc(MPVContext *handle, MPVErrorCallback callback, void *object);
void MPVERR_InitErrInf(MPVErrorInfo *info);
void MPVERR_Init(void);
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
typedef struct MPVBlockOffsets {
    s32 chroma;
    s32 luma;
} MPVBlockOffsets;
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
    int conditions[16];
    MPVPictureAttributes picture;
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
    void *buffer;
    s32 capacity;
    s32 size;
} MPVPictureUserBuffer;
typedef struct MPVContext MPVContext;
struct MPVContext {
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
    DctFsriParams dct_state;
    MPVMCContext mc;
    MPVMacroblockSources sources;
    MPVOutputBlocks output_blocks;
    MPVOutputBlocks secondary_output_blocks;
    s32 state;
    s32 field_18C;
    MPVConditionState condition_state;
    MPVErrorInfo error_info;
    MPVFrameBuffers frame_buffers;
    MPVYccPlane output;
    u32 aspect_ratio;
    s32 bit_rate;
    s32 vbv_buffer_units;
    u32 constrained_parameters;
    s32 link_flag_0;
    s32 link_flag_1;
    s32 vbv_delay;
    void (*decode_macroblock)(MPVContext *, SJ *);
    void (*skip_macroblocks)(MPVContext *, int);
    s32 (*decode_intra_blocks)(MPVContext *);
    s32 (*decode_nonintra_blocks)(MPVContext *);
    void (*motion_intra)(MPVContext *);
    void (*motion_skipped)(MPVContext *);
    void (*motion_backward)(MPVContext *);
    void (*motion_forward)(MPVContext *);
    void (*motion_bidirect)(MPVContext *);
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
    s32 (*decode_intra_block)(void *, void *);
    s32 (*decode_nonintra_block)(void *, void *);
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
int MPV_GetCond(MPVContext *handle, int index, int *value);
int MPV_SetCond(MPVContext *handle, int index, int value);
int MPVLIB_CheckHn(MPVContext *handle);
s32 MPVCDEC_IntraBlocks(MPVContext *context);
s32 MPVCDEC_NintraBlocks(MPVContext *context);
int MPV_Init(int handle_count, void *work);
MPVContext *MPV_Create(void);
int MPV_Destroy(MPVContext *handle);
void MPV_Finish(void);
int MPV_DecodePicAtrSj(void *handle, SJ *stream);
int MPV_DecodePicAtr(MPVContext *handle, SJCK *input, int *consumed_size);
int MPV_GetPicAtr(MPVContext *handle, MPVPictureInfo *picture);
void MPV_GetPicUsr(MPVContext *handle, void **buffer, int *size);
void MPV_SetPicUsrBuf(MPVContext *handle, void *buffer, int capacity);
int MPV_GetBitRate(MPVContext *handle, int *bit_rate);
int MPV_GetVbvBufSiz(MPVContext *handle, int *buffer_size, int *delay, int *byte_rate);
int MPV_DecodeFrmSj(void *handle, SJ *stream, MPVFrameBuffers *buffers);
int MPV_SkipFrmSj(void *handle, SJ *stream);
void MPV_GetDctCnt(MPVContext *handle, int *decoded, int *skipped);
int MPV_GetLinkFlg(MPVContext *handle, int *first, int *second);
void MPVMC08_OneRef1p_TuneC(MPVMCContext *context);
void MPVMC08_OneRefH2_TuneC(MPVMCContext *context);
void MPVMC08_OneRefV2_TuneC(MPVMCContext *context);
void MPVMC08_OneRef4p_TuneC(MPVMCContext *context);
void MPVMC08_Init(MPVMCFunction functions[4]);
void MPVMC16_OneRef1p_TuneC(MPVMCContext *context);
void MPVMC16_OneRefH2_TuneC(MPVMCContext *context);
void MPVMC16_OneRefV2_TuneC(MPVMCContext *context);
void MPVMC16_OneRef4p_TuneC(MPVMCContext *context);
void MPVMC16_Init(MPVMCContext *context);
s32 MPVABDEC_NintraBlock(void *context, void *coding_block);
s32 MPVABDEC_IntraBlock(void *context, void *coding_block);
s32 MPVABDEC_IntraBlockDc11(void *context, void *coding_block);
const unsigned char *MPV_SearchDelim(const unsigned char *data, int length, int mask);
void *MPV_BsearchDelim(const unsigned char *data, int length, int mask);
int MPV_CheckDelim(const unsigned char *data);
int MPV_IsEmptyPpic(const unsigned char *data, int length, int macroblock_count);
int MPV_IsEmptyBpic(const unsigned char *data, int length, int macroblock_count);
void exit(int code);
void *malloc(unsigned long size);
void *calloc(unsigned long count, unsigned long size);
void *realloc(void *allocation, unsigned long size);
void free(void *allocation);
void qsort(void *base, unsigned long count, unsigned long size,
           int (*compare)(const void *, const void *));
void *__sys_alloc(unsigned long size);
void __sys_free(void *allocation);
int __abs(int value);
int atoi(const char *str);
unsigned long strtoul(const char *str, char **end, int base);
unsigned long __strtoul(int base, int max_width, int (*read_proc)(void *, int, int),
                        void *read_context, int *chars_scanned, int *negative, int *overflow);
unsigned long long __strtoull(int base, int max_width, int (*read_proc)(void *, int, int),
                              void *read_context, int *chars_scanned, int *negative, int *overflow);
void *memcpy(void *destination, const void *source, unsigned long size);
void *memset(void *destination, int value, unsigned int size);
int memcmp(const void *lhs, const void *rhs, unsigned long size);
char *strcpy(char *destination, const char *source);
char *strncpy(char *destination, const char *source, unsigned long count);
char *strcat(char *destination, const char *source);
char *strncat(char *destination, const char *source, unsigned long count);
char *strchr(const char *string, int character);
char *strrchr(const char *string, int character);
char *strstr(const char *string, const char *substring);
unsigned long strlen(const char *string);
int strcmp(const char *lhs, const char *rhs);
int strncmp(const char *lhs, const char *rhs, unsigned long count);
int stricmp(const char *lhs, const char *rhs);
int strnicmp(const char *lhs, const char *rhs, unsigned long count);
char *strtok(char *string, const char *delimiters);
char *strupr(char *string);
void UTY_MemcpyDword(unsigned int *destination, unsigned int *source, unsigned int count);
void UTY_MemsetDword(unsigned int *destination, unsigned int value, unsigned int count);
void *MEM_Copy(void *destination, const void *source, unsigned long size);
extern u8 *mpvvlc_y_dcsiz;
extern u8 *mpvvlc_c_dcsiz;
extern u8 *mpvvlc2_y_dcsiz;
extern u8 *mpvvlc2_c_dcsiz;
typedef void (*MPVMacroblockDecodeFunction)(MPVContext *context, SJ *stream);
typedef void (*MPVMotionFunction)(MPVContext *context);
typedef void (*MPVSkipFunction)(MPVContext *context, int count);
extern void MPVDEC_DecIpicMb(MPVContext *context, SJ *stream);
extern void MPVDEC_DecPpicMb(MPVContext *context, SJ *stream);
extern void MPVDEC_DecBpicMb(MPVContext *context, SJ *stream);
extern void MPVDEC_DecDpicMb(MPVContext *context, SJ *stream);
extern void MPVUMC_PpicSkipped(MPVContext *context, int count);
extern void MPVUMC_BpicSkipped(MPVContext *context, int count);
extern void MPVUMC_Intra(MPVContext *context);
extern void MPVUMC_Forward(MPVContext *context);
extern void MPVUMC_Backward(MPVContext *context);
extern void MPVUMC_BiDirect(MPVContext *context);
extern u8 mpvbdec_dfl_iqm[64];
extern u8 mpvbdec_zigzag[64];
extern void MPVDEC_ResetDc(MPVContext *context);
extern void MPVDEC_ResetMv(MPVMotionInfo *motion);
extern int MPVM2V_DecodePicAtr(MPVContext *context, SJ *stream);
extern const MPVMacroblockDecodeFunction dec_mbs_func[5];
extern MPVMotionFunction mc_bidirect_func[2][5];
extern MPVMotionFunction mc_backward_func[2][5];
extern MPVMotionFunction mc_forward_func[2][5];
extern MPVMotionFunction mc_intra_func[2][2][5];
extern MPVSkipFunction skip_func[2][5];

static inline u32 mpvhdec_AlignSequenceWindow(u32 bits, int bit_offset) {
    if (bit_offset != 0) {
        bits <<= bit_offset;
    }
    return bits;
}

int fn_12_B598(MPVContext *context, SJ *stream) {
    SJCK remainder;
    u32 next_bits;
    int bit_offset;
    u32 bits;
    const u32 *words;
    u32 value;
    int f_code;
    int picture_type;
    int condition_index;
    int motion_mode;
    int consumed;
    context->user_data_index = 3;
    stream->interface->get_chunk(stream, 1, 0x7FFFFFFF, &context->header_chunk);
    words = (const u32 *)((unsigned long)context->header_chunk.data & ~3UL);
    bit_offset = (context->header_chunk.data - (const u8 *)words) * 8;
    bits = mpvhdec_AlignSequenceWindow(words[1], bit_offset);
    next_bits = words[2];
    words += 3;
    do {
        int split = 32 - (10);
        if (bit_offset >= split) {
            bit_offset -= split;
            if (bit_offset != 0) {
                bits |= next_bits >> ((10) - bit_offset);
                (context->condition_state.picture.temporal_reference) = bits >> split;
                bits = next_bits << bit_offset;
            } else {
                (context->condition_state.picture.temporal_reference) = bits >> split;
                bits = next_bits;
            }
            next_bits = *words++;
        } else {
            (context->condition_state.picture.temporal_reference) = bits >> split;
            bit_offset += (10);
            bits <<= (10);
        }
    } while (0);
    do {
        int split = 32 - (3);
        if (bit_offset >= split) {
            bit_offset -= split;
            if (bit_offset != 0) {
                bits |= next_bits >> ((3) - bit_offset);
                (value) = bits >> split;
                bits = next_bits << bit_offset;
            } else {
                (value) = bits >> split;
                bits = next_bits;
            }
            next_bits = *words++;
        } else {
            (value) = bits >> split;
            bit_offset += (3);
            bits <<= (3);
        }
    } while (0);
    context->condition_state.picture.picture_type = value;
    do {
        int split = 32 - (16);
        if (bit_offset >= split) {
            bit_offset -= split;
            if (bit_offset != 0) {
                bits |= next_bits >> ((16) - bit_offset);
                (context->vbv_delay) = bits >> split;
                bits = next_bits << bit_offset;
            } else {
                (context->vbv_delay) = bits >> split;
                bits = next_bits;
            }
            next_bits = *words++;
        } else {
            (context->vbv_delay) = bits >> split;
            bit_offset += (16);
            bits <<= (16);
        }
    } while (0);
    picture_type = context->condition_state.picture.picture_type;
    if (picture_type == 2 || picture_type == 3) {
        do {
            (context->forward_motion.full_pel) = bits >> 31;
            if (bit_offset == 31) {
                bits = next_bits;
                next_bits = *words++;
                bit_offset = 0;
            } else {
                bits <<= 1;
                bit_offset++;
            }
        } while (0);
        do {
            int split = 32 - (3);
            if (bit_offset >= split) {
                bit_offset -= split;
                if (bit_offset != 0) {
                    bits |= next_bits >> ((3) - bit_offset);
                    (f_code) = bits >> split;
                    bits = next_bits << bit_offset;
                } else {
                    (f_code) = bits >> split;
                    bits = next_bits;
                }
                next_bits = *words++;
            } else {
                (f_code) = bits >> split;
                bit_offset += (3);
                bits <<= (3);
            }
        } while (0);
        context->forward_motion.r_size = --f_code;
        context->forward_motion.shift = 27 - f_code;
        context->forward_motion.limit = 1 << f_code;
    }
    if (picture_type == 3) {
        do {
            (context->backward_motion.full_pel) = bits >> 31;
            if (bit_offset == 31) {
                bits = next_bits;
                next_bits = *words++;
                bit_offset = 0;
            } else {
                bits <<= 1;
                bit_offset++;
            }
        } while (0);
        do {
            int split = 32 - (3);
            if (bit_offset >= split) {
                bit_offset -= split;
                if (bit_offset != 0) {
                    bits |= next_bits >> ((3) - bit_offset);
                    (f_code) = bits >> split;
                    bits = next_bits << bit_offset;
                } else {
                    (f_code) = bits >> split;
                    bits = next_bits;
                }
                next_bits = *words++;
            } else {
                (f_code) = bits >> split;
                bit_offset += (3);
                bits <<= (3);
            }
        } while (0);
        context->backward_motion.r_size = --f_code;
        context->backward_motion.shift = 27 - f_code;
        context->backward_motion.limit = 1 << f_code;
    }
    motion_mode = context->condition_state.conditions[4];
    condition_index = context->condition_state.conditions[6] == 3 ? 0 : 1;
    context->decode_intra_blocks = MPVCDEC_IntraBlocks;
    context->decode_nonintra_blocks = MPVCDEC_NintraBlocks;
    context->decode_macroblock = dec_mbs_func[picture_type];
    context->skip_macroblocks = skip_func[condition_index][picture_type];
    context->motion_intra = mc_intra_func[motion_mode][condition_index][picture_type];
    context->motion_backward = mc_backward_func[condition_index][picture_type];
    context->motion_forward = mc_forward_func[condition_index][picture_type];
    context->motion_bidirect = mc_bidirect_func[condition_index][picture_type];
    context->motion_skipped = context->motion_forward;
    for (;;) {
        if ((bits >> 31) == 0) {
            bit_offset++;
            if (bit_offset >= 32) {
                bit_offset -= 32;
                words++;
            }
            break;
        }
        bit_offset += 9;
        if (bit_offset >= 32) {
            bit_offset -= 32;
            bits = next_bits << bit_offset;
            next_bits = *words++;
        } else {
            bits <<= 9;
        }
        consumed = ((const u8 *)(words - 2) + ((bit_offset + 7) >> 3)) - context->header_chunk.data;
        if (context->header_chunk.len <= consumed) {
            return -3;
        }
    }
    consumed = ((const u8 *)(words - 2) + ((bit_offset + 7) >> 3)) - context->header_chunk.data;
    SJ_SplitChunk(&context->header_chunk, consumed, &context->header_chunk, &remainder);
    stream->interface->put_chunk(stream, 0, &context->header_chunk);
    stream->interface->unget_chunk(stream, 1, &remainder);
    return 0;
}
