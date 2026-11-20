#include "types.h"
#pragma use_lmw_stmw on

/* --- rel/movie_module/fn_12_6ECC.c --- */
/* --- rel/movie_module/fn_12_6ECC.c --- */
typedef struct MovieEntry {
    u32 flag;
    u8 pad[0xbc];
} MovieEntry;

typedef struct MovieWorkspace {
    u32 callback_words[3];
    s32 count;
    MovieEntry entries[];
} MovieWorkspace;

extern MovieWorkspace *lbl_12_bss_4DB8;
extern const char *lbl_12_bss_4DB4;
extern const char lbl_12_rodata_668[50];
extern void fn_12_33428(u32 *, u32, u32);
extern void fn_12_6708(void);
extern void fn_12_6A8C(void);

static inline void initialize_entry_range(MovieEntry *entries, s32 count, s32 first) {
    for (; first < count; first++) {
        entries[first].flag = 1;
    }
}

static inline s32 initialize_entries(s32 count, void *memory) {
    MovieWorkspace *workspace;
    u32 word_count;

    lbl_12_bss_4DB4 = lbl_12_rodata_668;
    lbl_12_bss_4DB8 = memory;
    word_count = (u32)((count - 1) * 0xc0 + 0xd0) >> 2;
    fn_12_33428((u32 *)memory, 0, word_count);
    workspace = lbl_12_bss_4DB8;
    workspace->callback_words[0] = 0;
    workspace->callback_words[1] = 0;
    workspace->callback_words[2] = 0;
    lbl_12_bss_4DB8->count = count;
    initialize_entry_range(lbl_12_bss_4DB8->entries, count, 0);
    return 0;
}

s32 fn_12_6ECC(s32 count, void *memory) {
    s32 result = initialize_entries(count, memory);
    if (result != 0) {
        return result;
    }
    fn_12_6708();
    fn_12_6A8C();
    return 0;
}

/* --- rel/movie_module/fn_12_6FEC.c --- */
/* --- rel/movie_module/fn_12_6FEC.c --- */
struct fn_12_6FEC_lbl_12_bss_68F8 {
    u32 unk_0;
};
struct fn_12_6FEC_lbl_12_bss_68FC {
    u32 unk_0;
};
struct fn_12_6FEC_lbl_12_bss_6900 {
    u32 unk_0;
};
struct fn_12_6FEC_lbl_12_bss_6904 {
    u32 unk_0;
};
struct fn_12_6FEC_lbl_12_bss_6908 {
    u32 unk_0;
};

extern struct fn_12_6FEC_lbl_12_bss_68F8 lbl_12_bss_68F8;
extern struct fn_12_6FEC_lbl_12_bss_68FC lbl_12_bss_68FC;
extern struct fn_12_6FEC_lbl_12_bss_6900 lbl_12_bss_6900;
extern struct fn_12_6FEC_lbl_12_bss_6904 lbl_12_bss_6904;
extern struct fn_12_6FEC_lbl_12_bss_6908 lbl_12_bss_6908;
extern u8 lbl_12_bss_4DC0[64];
extern u32 lbl_12_bss_68F4;
extern u8 lbl_12_bss_4E00[64];
extern void * memcpy(void *, const void *, u32);
extern void DCT_FsriInitScanTbl(const signed char *, signed char *);
extern void fn_12_33364(u32 *, u32 *, u32);

/* lbl_12_rodata_6A0: the MPEG tables of this TU, one .rodata section */
static const u16 fzgx_pool_bit_masks[16] = {
    0xFFFF, 0x7FFF, 0x3FFF, 0x1FFF, 0x0FFF, 0x07FF, 0x03FF, 0x01FF,
    0x00FF, 0x007F, 0x003F, 0x001F, 0x000F, 0x0007, 0x0003, 0x0001,
};
static const s8 fzgx_pool_zigzag[64] = {
    0x00, 0x01, 0x08, 0x10, 0x09, 0x02, 0x03, 0x0A, 0x11, 0x18, 0x20, 0x19, 0x12, 0x0B, 0x04, 0x05,
    0x0C, 0x13, 0x1A, 0x21, 0x28, 0x30, 0x29, 0x22, 0x1B, 0x14, 0x0D, 0x06, 0x07, 0x0E, 0x15, 0x1C,
    0x23, 0x2A, 0x31, 0x38, 0x39, 0x32, 0x2B, 0x24, 0x1D, 0x16, 0x0F, 0x17, 0x1E, 0x25, 0x2C, 0x33,
    0x3A, 0x3B, 0x34, 0x2D, 0x26, 0x1F, 0x27, 0x2E, 0x35, 0x3C, 0x3D, 0x36, 0x2F, 0x37, 0x3E, 0x3F,
};
static const u8 fzgx_pool_intra_quant[64] = {
    0x08, 0x10, 0x13, 0x16, 0x1A, 0x1B, 0x1D, 0x22, 0x10, 0x10, 0x16, 0x18, 0x1B, 0x1D, 0x22, 0x25,
    0x13, 0x16, 0x1A, 0x1B, 0x1D, 0x22, 0x22, 0x26, 0x16, 0x16, 0x1A, 0x1B, 0x1D, 0x22, 0x25, 0x28,
    0x16, 0x1A, 0x1B, 0x1D, 0x20, 0x23, 0x28, 0x30, 0x1A, 0x1B, 0x1D, 0x20, 0x23, 0x28, 0x30, 0x3A,
    0x1A, 0x1B, 0x1D, 0x22, 0x26, 0x2E, 0x38, 0x45, 0x1B, 0x1D, 0x23, 0x26, 0x2E, 0x38, 0x45, 0x53,
};
static const u8 fzgx_pool_defaults[32] = {
    5, 4, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
};

void fn_12_6FEC(u8 *arg0) {
    signed char tbl[64];
    signed char scan[64];
    s32 i;
    u32 *q;

    for (i = 0; i < 64; i++) {
        tbl[i] = i;
    }
    DCT_FsriInitScanTbl(tbl, scan);
    for (i = 0; i < 64; i++) {
        lbl_12_bss_4E00[i] = scan[fzgx_pool_zigzag[i]];
        lbl_12_bss_4DC0[scan[i]] = fzgx_pool_intra_quant[i];
    }
    q = (u32 *)(arg0 + 32);
    if (q != 0) {
        fn_12_33364(q, (u32 *)lbl_12_bss_4E00, 16);
    }
    if (arg0 != 0) {
        fn_12_33364((u32 *)arg0, (u32 *)fzgx_pool_bit_masks, 8);
    }
    memcpy(arg0 + 0x160, fzgx_pool_defaults, 32);
    *(u32 *)(arg0 + 0x180) = lbl_12_bss_68F4 - 16;
    *(u32 *)(arg0 + 0x184) = 21;
    *(u32 *)(arg0 + 0x188) = lbl_12_bss_68F8.unk_0 - 32;
    *(u32 *)(arg0 + 0x18c) = 19;
    *(u32 *)(arg0 + 0x190) = lbl_12_bss_68FC.unk_0 - 32;
    *(u32 *)(arg0 + 0x194) = 18;
    *(u32 *)(arg0 + 0x198) = lbl_12_bss_6900.unk_0 - 32;
    *(u32 *)(arg0 + 0x19c) = 17;
    *(u32 *)(arg0 + 0x1a0) = lbl_12_bss_6904.unk_0 - 32;
    *(u32 *)(arg0 + 0x1a4) = 16;
    *(u32 *)(arg0 + 0x1a8) = lbl_12_bss_6908.unk_0 - 32;
    *(u32 *)(arg0 + 0x1ac) = 15;
}

/* --- rel/movie_module/fn_12_72F4.c --- */
typedef struct Sig_fn_12_4F18_MovieModule {
    u8 pad_28[0x28];
    void *field_28;
} Sig_fn_12_4F18_MovieModule;
extern void fn_12_4F18(Sig_fn_12_4F18_MovieModule *);

typedef struct Req {
    u8 pad[0x1c];
    void *buf;
} Req;

typedef struct Obj Obj;
struct Obj {
    u8 pad0[0x44];
    Req req;
    void *f64;
    s32 f68;
    u8 pad2[0x74 - 0x6c];
    s32 f74;
    u8 flags[8];
    u8 pad3[0xa0 - 0x80];
    s32 fa0;
    u8 pad4[0x2bc - 0xa4];
    s32 f2bc;
    u8 pad5[0x314 - 0x2c0];
    s32 f314;
    u8 pad6[0x640 - 0x318];
    s8 bufs[6][0x100];
    u8 pad7[0x12ec - 0xc40];
    u8 (*cb)(Obj *, Req *);
};

s32 fn_12_72F4(Obj *o) {
    u32 mask;
    s32 i;
    Req *req;
    u8 *flags;
    Obj * base;

    flags = (u8 *)((u32)o + 0x78);
    req = &o->req;
    base = o;
    i = 0;
    o->f68 = o->f2bc;
    *(void **)((u8 *)req + 0x20) = (u8 *)o + 0xc80;
    o->f74 = 1;
    mask = o->f314 << 2;
    o->fa0 = mask;
    for (i = 0; i < 6; i++) {
        if ((s32)mask < 0) {
            req->buf = base->bufs[i];
            flags[i] = o->cb(o, req);
        }
        mask <<= 1;
    }
    fn_12_4F18((Sig_fn_12_4F18_MovieModule *)flags);
    return 0;
}

/* --- rel/movie_module/MPVCDEC_IntraBlocks.c --- */
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
