#include "types.h"

/* --- rel/movie_module/fn_12_B3E0.c --- */
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

typedef struct SJ_u0 SJ_u0;

typedef struct SJInterface_u0 SJInterface_u0;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface_u0 {
    union {
        unsigned char padding_extent[48];
        struct {
            unsigned char padding_get_chunk[24];
            void (*get_chunk)(SJ_u0 *sj, int channel, int max_size, SJCK *chunk);
        } view_get_chunk;
        struct {
            unsigned char padding_put_chunk[32];
            void (*put_chunk)(SJ_u0 *sj, int channel, SJCK *chunk);
        } view_put_chunk;
    } fields;
};

struct SJ_u0 {
    union {
        unsigned char padding_extent[4];
        struct {
            const SJInterface_u0 *interface;
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

typedef struct MPVContext_u0 MPVContext_u0;

typedef void (*MPVErrorCallback)(int object, int error);

typedef struct MPVErrorInfo {
    union {
        unsigned char padding_extent[20];
        struct {
            MPVErrorCallback callback;
        } view_callback;
    } fields;
} MPVErrorInfo;

typedef struct MPVMCContext_u0 MPVMCContext_u0;

typedef void (*MPVMCFunction)(MPVMCContext_u0 *context);

struct MPVMCContext_u0 {
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
            SJ_u0 *stream;
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

struct MPVContext_u0 {
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

int fn_12_B3E0(MPVContext_u0 *context, const u8 *data, int length);

int fn_12_A2C4(const unsigned char *data);

void *memcpy(void *destination, const void *source, unsigned long size);

int fn_12_B254(MPVContext_u0 *context, const u8 *data, int length);

#pragma peephole on
#pragma opt_propagation off
#pragma opt_lifetimes off
int fn_12_B3E0(MPVContext_u0 *context, const u8 *data, int length) {
    SJ_u0 *user_sj;
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

/* --- rel/movie_module/fn_12_B598.c --- */
typedef struct MovieObject_u1 MovieObject_u1;
typedef struct MovieBits { u32 address; s32 limit; s32 bit; } MovieBits;
typedef struct MovieVTable {
    u8 pad[0x18];
    void (*method_0018)(MovieObject_u1 *, s32, s32, MovieBits *);
    void (*method_001c)(MovieObject_u1 *, s32, void *);
    void (*method_0020)(MovieObject_u1 *, s32, MovieBits *);
} MovieVTable;
struct MovieObject_u1 { MovieVTable *vtable; };

typedef void (*MovieFn)();

typedef struct MovieState {
    u8 pad0[0x1a0];
    s32 unk1a0;
    u32 pad1a4;
    s32 unk1a8;
    u8 pad1ac[0x38];
    u32 unk1e4;
    s32 unk1e8;
    u8 pad1ec[0xa0];
    u32 unk28c;
    u32 pad290;
    MovieFn unk294;
    MovieFn unk298;
    MovieFn unk29c;
    MovieFn unk2a0;
    MovieFn unk2a4;
    MovieFn unk2a8;
    MovieFn unk2ac;
    MovieFn unk2b0;
    MovieFn unk2b4;
    u8 pad2b8[8];
    u32 unk2c0;
    u32 unk2c4;
    u32 unk2c8;
    u32 unk2cc;
    u8 pad2d0[0x14];
    u32 unk2e4;
    u32 unk2e8;
    u32 unk2ec;
    u32 unk2f0;
    u8 pad2f4[0xfd4];
    MovieBits bits;
    u8 pad12d4[0x30];
    u32 state;
} MovieState;

extern void MPVCDEC_IntraBlocks();
extern void fn_12_72F4();
extern void fn_12_9D08();
extern void fn_12_975C();
extern void fn_12_8F80();
extern void fn_12_8BD8();
extern void fn_12_11860();
extern void fn_12_11254();
extern void fn_12_7940();
extern void fn_12_78C0();
extern void fn_12_11204();
extern void fn_12_7870();
extern void fn_12_11188();
extern void fn_12_77F4();
extern void fn_12_124A0();
extern void fn_12_8A10();
extern void fn_12_89D4();
extern void fn_12_12270();
extern void fn_12_87FC();
extern void fn_12_879C();
extern void fn_12_121BC();
extern void fn_12_873C();
extern void fn_12_120E4();
extern void fn_12_86B8();
extern u32 fn_800589BC(MovieBits *, s32, MovieBits *, void *);

/* picture-type dispatch tables, indexed [non-intra?][picture type]; the
 * whole cluster is addressed off one section base in retail */
extern u8 fn_12_11188__fzgx_offset_0[];
extern u8 fn_12_11204__fzgx_offset_0[];
extern u8 fn_12_11254__fzgx_offset_0[];
extern u8 fn_12_11860__fzgx_offset_0[];
extern u8 fn_12_120E4__fzgx_offset_0[];
extern u8 fn_12_121BC__fzgx_offset_0[];
extern u8 fn_12_12270__fzgx_offset_0[];
extern u8 fn_12_124A0__fzgx_offset_0[];
extern u8 fn_12_77F4__fzgx_offset_0[];
extern u8 fn_12_7870__fzgx_offset_0[];
extern u8 fn_12_78C0__fzgx_offset_0[];
extern u8 fn_12_7940__fzgx_offset_0[];
extern u8 fn_12_86B8__fzgx_offset_0[];
extern u8 fn_12_873C__fzgx_offset_0[];
extern u8 fn_12_879C__fzgx_offset_0[];
extern u8 fn_12_87FC__fzgx_offset_0[];
extern u8 fn_12_89D4__fzgx_offset_0[];
extern u8 fn_12_8A10__fzgx_offset_0[];
extern u8 fn_12_8BD8__fzgx_offset_0[];
extern u8 fn_12_8F80__fzgx_offset_0[];
extern u8 fn_12_975C__fzgx_offset_0[];
extern u8 fn_12_9D08__fzgx_offset_0[];
static const union { u32 w[5]; MovieFn const v[5]; } fzgx_pool_init_lbl_12_rodata_768 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, (u32)fn_12_9D08__fzgx_offset_0, (u32)fn_12_975C__fzgx_offset_0, (u32)fn_12_8F80__fzgx_offset_0, (u32)fn_12_8BD8__fzgx_offset_0
}};
static const union { u32 w[10]; MovieFn const v[2][5]; } fzgx_pool_init_fzgx_tbl_77C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, (u32)fn_12_11860__fzgx_offset_0, (u32)fn_12_11254__fzgx_offset_0, 0x0, 0x0, 0x0, (u32)fn_12_7940__fzgx_offset_0,
    (u32)fn_12_78C0__fzgx_offset_0, 0x0
}};
static const union { u32 w[2]; MovieFn const v[2]; } fzgx_pool_init_lbl_12_rodata_7A4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)fn_12_11204__fzgx_offset_0, (u32)fn_12_7870__fzgx_offset_0
}};
static const union { u32 w[2]; MovieFn const v[2]; } fzgx_pool_init_lbl_12_rodata_7AC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)fn_12_11188__fzgx_offset_0, (u32)fn_12_77F4__fzgx_offset_0
}};
static const union { u32 w[20]; MovieFn const v[2][2][5]; } fzgx_pool_init_fzgx_tbl_7B4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, (u32)fn_12_124A0__fzgx_offset_0, (u32)fn_12_124A0__fzgx_offset_0, (u32)fn_12_124A0__fzgx_offset_0, (u32)fn_12_124A0__fzgx_offset_0, 0x0, (u32)fn_12_8A10__fzgx_offset_0, (u32)fn_12_8A10__fzgx_offset_0,
    (u32)fn_12_89D4__fzgx_offset_0, (u32)fn_12_8A10__fzgx_offset_0, 0x0, (u32)fn_12_124A0__fzgx_offset_0, (u32)fn_12_124A0__fzgx_offset_0, (u32)fn_12_124A0__fzgx_offset_0, (u32)fn_12_124A0__fzgx_offset_0, 0x0,
    (u32)fn_12_89D4__fzgx_offset_0, (u32)fn_12_89D4__fzgx_offset_0, (u32)fn_12_89D4__fzgx_offset_0, (u32)fn_12_89D4__fzgx_offset_0
}};
static const union { u32 w[10]; MovieFn const v[2][5]; } fzgx_pool_init_fzgx_tbl_804 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, (u32)fn_12_12270__fzgx_offset_0, (u32)fn_12_12270__fzgx_offset_0, 0x0, 0x0, 0x0, (u32)fn_12_87FC__fzgx_offset_0,
    (u32)fn_12_879C__fzgx_offset_0, 0x0
}};
static const union { u32 w[10]; MovieFn const v[2][5]; } fzgx_pool_init_fzgx_tbl_82C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0, (u32)fn_12_121BC__fzgx_offset_0, 0x0, 0x0, 0x0, 0x0,
    (u32)fn_12_873C__fzgx_offset_0, 0x0
}};
static const union { u32 w[10]; MovieFn const v[2][5]; } fzgx_pool_init_fzgx_tbl_854 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0, (u32)fn_12_120E4__fzgx_offset_0, 0x0, 0x0, 0x0, 0x0,
    (u32)fn_12_86B8__fzgx_offset_0, 0x0
}};

/* read N bits (N < 32) from the cached big-endian bit window */
#define GET_BITS(n, dst)                                        \
    if (shift >= 32 - (n)) {                                    \
        shift -= 32 - (n);                                      \
        if (shift != 0) {                                       \
            current |= next >> ((n) - shift);                   \
            dst = current >> (32 - (n));                        \
            current = next << shift;                            \
        } else {                                                \
            dst = current >> (32 - (n));                        \
            current = next;                                     \
        }                                                       \
        next = *p++;                                            \
    } else {                                                    \
        dst = current >> (32 - (n));                            \
        current <<= (n);                                        \
        shift += (n);                                           \
    }

#define SKIP_BIT()                                              \
    if (shift == 31) {                                          \
        current = next;                                         \
        next = *p++;                                            \
        shift = 0;                                              \
    } else {                                                    \
        current <<= 1;                                          \
        shift++;                                                \
    }

#pragma opt_propagation off
s32 fn_12_B598(MovieState *ctx, MovieObject_u1 *movie) {
    u32 result[2];
    u32 word;
    s32 shift;
    u32 next;
    u32 current;
    u32 cur;
    u32 *p;
    u32 value;
    s32 type;
    s32 ne;
    s32 mode;
    u32 base;
    s32 whole;
    u8 *end;

    ctx->state = 3;
    movie->vtable->method_0018(movie, 1, 0x7fffffff, &ctx->bits);
    p = (u32 *)(ctx->bits.address & ~3);
    shift = (ctx->bits.address - (u32)p) * 8;
    word = p[1];
    p += 2;
    if (shift >= 32) { word = *p++; shift -= 32; }
    cur = word;
    if (shift != 0) cur = word << shift;
    next = *p++;
    current = cur;

    GET_BITS(10, ctx->unk1e4)
    GET_BITS(3, value)
    ctx->unk1e8 = value;
    GET_BITS(16, ctx->unk28c)

    type = ctx->unk1e8;
    if (type == 2 || type == 3) {
        ctx->unk2c0 = current >> 31;
        SKIP_BIT()
        GET_BITS(3, value)
        value -= 1;
        ctx->unk2c4 = value;
        ctx->unk2c8 = 27 - value;
        ctx->unk2cc = 1 << value;
    }
    if (type == 3) {
        ctx->unk2e4 = current >> 31;
        SKIP_BIT()
        GET_BITS(3, value)
        value -= 1;
        ctx->unk2e8 = value;
        ctx->unk2ec = 27 - value;
        ctx->unk2f0 = 1 << value;
    }

    ne = ctx->unk1a8 != 3;
    mode = ctx->unk1a0;
    ctx->unk294 = fzgx_pool_init_lbl_12_rodata_768.v[type];
    ctx->unk298 = fzgx_pool_init_fzgx_tbl_77C.v[ne][type];
    ctx->unk29c = MPVCDEC_IntraBlocks;
    ctx->unk2a0 = fn_12_72F4;
    ctx->unk2a4 = fzgx_pool_init_fzgx_tbl_7B4.v[mode][ne][type];
    ctx->unk2ac = fzgx_pool_init_fzgx_tbl_82C.v[ne][type];
    ctx->unk2b0 = fzgx_pool_init_fzgx_tbl_804.v[ne][type];
    ctx->unk2b4 = fzgx_pool_init_fzgx_tbl_854.v[ne][type];
    ctx->unk2a8 = ctx->unk2b0;

    /* skip extra information: 1-bit flag followed by an 8-bit byte */
    for (;;) {
        if ((current >> 31) == 0) {
            shift++;
            if (shift >= 32) {
                shift -= 32;
                p++;
            }
            break;
        }
        shift += 9;
        if (shift >= 32) {
            shift -= 32;
            current = next << shift;
            next = *p++;
        } else {
            current <<= 9;
        }
        end = (u8 *)p + ((shift + 7) >> 3);
        if (ctx->bits.limit <= (s32)(end - 8 - (u8 *)ctx->bits.address)) {
            return -3;
        }
    }

    ctx->bits.bit = shift & 7;
    base = ctx->bits.address;
    whole = shift - ctx->bits.bit;
    p = (u32 *)((u8 *)p + ((whole + 7) >> 3));
    p = (u32 *)((u8 *)p - 8 - (u8 *)base);
    fn_800589BC(&ctx->bits, (s32)p, &ctx->bits, &result);
    movie->vtable->method_0020(movie, 0, &ctx->bits);
    movie->vtable->method_001c(movie, 1, &result);
    return 0;
}
