#include "types.h"
#include "sofdec/mpv.h"
#include "sofdec/sj.h"

/* fzgx:begin fn_12_ABDC noprologue */
#include "types.h"
#include "sofdec/mpv.h"
#pragma opt_propagation off

/* --- rel/movie_module/fn_12_ABDC.c --- */
typedef struct Sig_fn_12_ABDC_MPVContext Sig_fn_12_ABDC_MPVContext;
typedef struct Sig_fn_12_ABDC_SJInterface Sig_fn_12_ABDC_SJInterface;
typedef struct Sig_fn_12_ABDC_SJ Sig_fn_12_ABDC_SJ;
typedef struct Sig_fn_12_ABDC_MPVDecoderFields {
 union { unsigned char padding_extent[168]; struct { unsigned char padding_field_1AC[28]; s32 field_1AC; } view_field_1AC; } fields;
} Sig_fn_12_ABDC_MPVDecoderFields;
typedef union Sig_fn_12_ABDC_MPVConditionState {
 union { unsigned char padding_extent[168]; struct { int conditions[17]; } view_conditions; struct { Sig_fn_12_ABDC_MPVDecoderFields decoder; } view_decoder; } fields;
} Sig_fn_12_ABDC_MPVConditionState;
typedef struct Sig_fn_12_ABDC_MPVErrorInfo {
 union { unsigned char padding_extent[20]; struct { unsigned char padding_field_0C[12]; int field_0C; } view_field_0C; struct { unsigned char padding_field_10[16]; int field_10; } view_field_10; } fields;
} Sig_fn_12_ABDC_MPVErrorInfo;
typedef struct Sig_fn_12_ABDC_SJCK {
 union { unsigned char padding_extent[8]; struct { unsigned char *data; } view_data; struct { unsigned char padding_len[4]; int len; } view_len; } fields;
} Sig_fn_12_ABDC_SJCK;
struct Sig_fn_12_ABDC_MPVContext {
 union {
 struct { unsigned char padding_chunk[4808]; Sig_fn_12_ABDC_SJCK chunk; } view_chunk;
 unsigned char padding_extent[4992];
 struct { unsigned char padding_condition_state[400]; Sig_fn_12_ABDC_MPVConditionState condition_state; } view_condition_state;
 struct { unsigned char padding_error_info[544]; Sig_fn_12_ABDC_MPVErrorInfo error_info; } view_error_info;
 struct { unsigned char padding_field_1300[4800]; s32 field_1300; } view_field_1300;
 struct { unsigned char padding_field_1304[4804]; s32 field_1304; } view_field_1304;
 struct { unsigned char padding_field_1324[4852]; s32 field_1324; } view_field_1324;
 } fields;
};
struct Sig_fn_12_ABDC_SJInterface {
 union {
 unsigned char padding_extent[48];
 struct { unsigned char padding_get_chunk[24]; void (*get_chunk)(Sig_fn_12_ABDC_SJ *, int, int, Sig_fn_12_ABDC_SJCK *); } view_get_chunk;
 struct { unsigned char padding_unget_chunk[28]; void (*unget_chunk)(Sig_fn_12_ABDC_SJ *, int, Sig_fn_12_ABDC_SJCK *); } view_unget_chunk;
 struct { unsigned char padding_put_chunk[32]; void (*put_chunk)(Sig_fn_12_ABDC_SJ *, int, Sig_fn_12_ABDC_SJCK *); } view_put_chunk;
 } fields;
};
struct Sig_fn_12_ABDC_SJ {
 union { unsigned char padding_extent[4]; struct { const Sig_fn_12_ABDC_SJInterface *interface; } view_interface; } fields;
};
typedef struct Sig_fn_12_9744_MovieState {
 u8 _pad10[0x10]; s32 field_10; s32 field_14; s32 field_18; s32 field_1c;
} Sig_fn_12_9744_MovieState;
typedef struct Sig_fn_12_9730_MovieModule {
 u8 _pad0[0x318]; u32 field_318; u32 field_31c; u32 field_320;
} Sig_fn_12_9730_MovieModule;
extern void fn_12_9730(Sig_fn_12_9730_MovieModule *);
extern void fn_12_9744(Sig_fn_12_9744_MovieState *);
extern u32 fn_800589BC(Sig_fn_12_ABDC_SJCK *, s32, Sig_fn_12_ABDC_SJCK *, Sig_fn_12_ABDC_SJCK *);
void fn_12_ABDC(Sig_fn_12_ABDC_MPVContext *arg0, Sig_fn_12_ABDC_SJ *arg1, u32 arg2) {
 u32 v0;
 u32 v8;
 u32 v9;
 u32 v2;
 u8 *v1;
 u32 v3;
 u32 v4;
 u32 v5;
 u32 v6;
 u32 v7;
 u32 v10;
 u32 v11;
 u32 v12;
 u32 v13;
 u32 v14;
 u32 v15;
 u32 v16;
 u32 v17;
 u32 v18;
 u32 v19;
 u32 v20;
 Sig_fn_12_ABDC_SJCK chunk;
 arg1->fields.view_interface.interface->fields.view_get_chunk.get_chunk(arg1, 1, 0x7fffffff, &arg0->fields.view_chunk.chunk);
 v0 = *(u32 *)((u8 *)arg0 + 4808);
 v1 = (u8 *)(v0 & ~3);
 v2 = (v0 - (u32)v1) << 3;
 v5 = *(u32 *)v1;
 v6 = *(u32 *)(v1 + 4);
 v1 += 8;
 v5 <<= v2;
 if ((s32)v2 >= 32) {
  v2 -= 32;
  v5 = v6 << v2;
  v6 = *(u32 *)v1;
  v1 += 4;
 }
 if ((s32)v2 != 0) {
  v8 = v6 << v2;
  v0 = v5 | (v6 >> (32 - v2));
 } else {
  v0 = v5;
  v8 = v6;
 }
 v9 = *(u32 *)v1;
 v1 += 4;
 *(u32 *)((u8 *)arg0 + 776) = (((v0 & 0xff) - 1) * *(u32 *)((u8 *)arg0 + 472)) - 1;
 if ((s32)v2 >= 27) {
  v2 -= 27;
  if (v2 != 0) {
   v8 |= v9 >> (5 - v2);
   *(u32 *)((u8 *)arg0 + 700) = v8 >> 27;
   v8 = v9 << v2;
  } else {
   v15 = v8 >> 27;
   v8 = v9;
   *(u32 *)((u8 *)arg0 + 700) = v15;
  }
  v9 = *(u32 *)v1;
  v1 += 4;
 } else {
  v16 = v8 >> 27;
  v8 <<= 5;
  *(u32 *)((u8 *)arg0 + 700) = v16;
  v2 += 5;
 }
 fn_12_9744((Sig_fn_12_9744_MovieState *)((u8 *)arg0 + 704));
 fn_12_9744((Sig_fn_12_9744_MovieState *)((u8 *)arg0 + 740));
 fn_12_9730((Sig_fn_12_9730_MovieModule *)arg0);
 for (;;) {
  if (!(v8 >> 31)) {
   v2 += 1;
   if ((s32)v2 >= 32) {
    v2 -= 32;
    v1 += 4;
   }
   break;
  }
  v2 += 9;
  if ((s32)v2 >= 32) {
   v2 -= 32;
   v8 = v9 << v2;
   v9 = *(u32 *)v1;
   v1 += 4;
  } else {
   v8 <<= 9;
  }
  v0 = (u32)v1 + (((s32)v2 + 7) >> 3);
  v19 = *(u32 *)((u8 *)arg0 + 4812);
  v18 = *(u32 *)((u8 *)arg0 + 4808);
  v20 = v0 - 8 - v18;
  if ((s32)v19 <= (s32)v20) return;
 }
 *(u32 *)((u8 *)arg0 + 4816) = v2 & 7;
 v20 = (u32)v1 + (((s32)(v2 - *(u32 *)((u8 *)arg0 + 4816)) + 7) >> 3);
 v18 = *(u32 *)((u8 *)arg0 + 4808);
 fn_800589BC(&arg0->fields.view_chunk.chunk,
 (s32)(v20 - 8 - v18),
 &arg0->fields.view_chunk.chunk, &chunk);
 arg1->fields.view_interface.interface->fields.view_put_chunk.put_chunk(arg1, 0, &arg0->fields.view_chunk.chunk);
 arg1->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(arg1, 1, &chunk);
 (*(void (**)(Sig_fn_12_ABDC_MPVContext *, Sig_fn_12_ABDC_SJ *))((u8 *)arg0 + 660))(arg0, arg1);
}
/* fzgx:end fn_12_ABDC */

/* fzgx:begin MPV_MoveChunk */

/* --- rel/movie_module/MPV_MoveChunk.c --- */
int MPV_MoveChunk(SJ *stream, int channel, int size) {
    SJCK chunk;
    int source_channel = channel;
    channel = channel == 0;
    stream->interface->get_chunk(stream, source_channel, size, &chunk);
    stream->interface->put_chunk(stream, channel, &chunk);
    return chunk.len;
}
/* fzgx:end MPV_MoveChunk */

/* fzgx:begin fn_12_AE70 noprologue */

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

struct SJInterface {
    union {
        unsigned char padding_extent[48];
        struct {
            unsigned char padding_get_chunk[24];
            void (*get_chunk)(SJ *sj, int channel, int max_size, SJCK *chunk);
        } view_get_chunk;
        struct {
            unsigned char padding_unget_chunk[28];
            void (*unget_chunk)(SJ *sj, int channel, SJCK *chunk);
        } view_unget_chunk;
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

typedef struct MPVContext MPVContext;

typedef struct MPVErrorInfo {
    union {
        unsigned char padding_extent[20];
        struct {
            unsigned char padding_field_0C[12];
            int field_0C;
        } view_field_0C;
        struct {
            unsigned char padding_field_10[16];
            int field_10;
        } view_field_10;
    } fields;
} MPVErrorInfo;

typedef struct MPVDecoderFields {
    union {
        unsigned char padding_extent[168];
        struct {
            unsigned char padding_field_1AC[28];
            s32 field_1AC;
        } view_field_1AC;
    } fields;
} MPVDecoderFields;

typedef union MPVConditionState {
    union {
        unsigned char padding_extent[168];
        struct {
            int conditions[17];
        } view_conditions;
        struct {
            MPVDecoderFields decoder;
        } view_decoder;
    } fields;
} MPVConditionState;

struct MPVContext {
    union {
        unsigned char padding_extent[4992];
        struct {
            unsigned char padding_condition_state[400];
            MPVConditionState condition_state;
        } view_condition_state;
        struct {
            unsigned char padding_error_info[544];
            MPVErrorInfo error_info;
        } view_error_info;
        struct {
            unsigned char padding_field_1300[4800];
            s32 field_1300;
        } view_field_1300;
        struct {
            unsigned char padding_field_1304[4804];
            s32 field_1304;
        } view_field_1304;
        struct {
            unsigned char padding_field_1324[4852];
            s32 field_1324;
        } view_field_1324;
    } fields;
};

void fn_800589BC(const SJCK *source, int nbyte, SJCK *first, SJCK *remainder);

int fn_12_A660(MPVContext *handle, int error);

const unsigned char *fn_12_A0D8(const unsigned char *data, int length, int mask);

int fn_12_A2C4(const unsigned char *data);

void fn_12_ABDC(MPVContext *context, SJ *stream);

static inline int MPV_MoveChunk(SJ *stream, int channel, int size) {
    SJCK chunk;
    int source_channel = channel;
    channel = channel == 0;
    stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(stream, source_channel,
                                                                             size, &chunk);
    stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(stream, channel,
                                                                             &chunk);
    return chunk.fields.view_len.len;
}

static inline int mpvhdec_IsWantedDelim(int delimiter_type, int wanted_mask) {
    return (delimiter_type & wanted_mask) != 0;
}

int fn_12_AE70(MPVContext *context, SJ *stream) {
    unsigned char * fzgx_live;
    SJCK header;
    SJCK remainder;
    SJCK chunk;
    const u8 *delimiter;
    struct { int value; } delimiter_type;
    int error;
    int picture_state;
    context->fields.view_field_1324.field_1324 =
        context->fields.view_condition_state.condition_state.fields.view_decoder.decoder.fields
            .view_field_1AC.field_1AC;
    for (;;) {
        picture_state = context->fields.view_condition_state.condition_state.fields
                            .view_conditions.conditions[1];
        if (context->fields.view_field_1300.field_1300 != 0) {
            context->fields.view_field_1300.field_1300 = 0;
            context->fields.view_field_1304.field_1304++;
            context->fields.view_error_info.error_info.fields.view_field_0C.field_0C++;
            if (picture_state == 0) {
                error = -2;
                goto error_check; /* Keep the verified branch to error_check. */
            }
            context->fields.view_error_info.error_info.fields.view_field_10.field_10++;
        }
        if (picture_state == 0) {
            error = -2;
        } else {
            error = -3;
        }
        for (;;) {
            stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
                stream, 1, 0x7FFFFFFF, &chunk);
            if (chunk.fields.view_len.len < 4) {
                stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(
                    stream, 1, &chunk);
                delimiter_type.value = 0;
            } else {
                fzgx_live = chunk.fields.view_data.data;
                delimiter = fn_12_A0D8(fzgx_live, chunk.fields.view_len.len, -1);
                if (delimiter == 0) {
                    fn_800589BC(&chunk, chunk.fields.view_len.len - 3, &chunk, &remainder);
                    (stream->fields.view_interface.interface)->fields.view_put_chunk.put_chunk(
                        stream, 0, &chunk);
                    stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(
                        stream, 1, &remainder);
                    continue;
                }
                delimiter_type.value = fn_12_A2C4(delimiter);
                fzgx_live = chunk.fields.view_data.data;
                fn_800589BC(&chunk, delimiter - fzgx_live, &chunk, &remainder);
                stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(
                    stream, 0, &chunk);
                stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(
                    stream, 1, &remainder);
            }
            if (delimiter_type.value == 0) {
                break;
            }
            if (mpvhdec_IsWantedDelim(delimiter_type.value, -1)) {
                error = 0;
                break;
            }
            if (MPV_MoveChunk(stream, 1, 4) != 4) {
                break;
            }
        }
    error_check:
        if (error != 0) {
            return fn_12_A660(context, error);
        }
        stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
            stream, 1, 0x7FFFFFFF, &header);
        stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                     &header);
        if (header.fields.view_len.len >= 4 &&
            (fn_12_A2C4(header.fields.view_data.data) & 1) != 0) {
            fn_12_ABDC(context, stream);
        } else {
            return 0;
        }
    }
}

/* fzgx:end fn_12_AE70 */

/* fzgx:begin MPV_GoNextDelimSj noprologue */
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
/* fzgx:end MPV_GoNextDelimSj */

/* fzgx:begin fn_12_B254 noprologue */

/* --- rel/movie_module/fn_12_B254.c --- */
extern const f64 lbl_12_rodata_87C;
extern const f64 lbl_12_rodata_884;

typedef struct MPVContext_u1 MPVContext_u1;

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
/* fzgx:end fn_12_B254 */

/* fzgx:begin fn_12_B3E0 noprologue */
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

typedef struct MPVContext_u0 MPVContext_u0;

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
/* fzgx:end fn_12_B3E0 */

/* fzgx:begin fn_12_B598 noprologue */
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
/* fzgx:end fn_12_B598 */

/* fzgx:begin fn_12_B9E8 noprologue */
#include "types.h"
struct Sig_fn_800589BC_fn_800589BC_Arg2 {
    u32 unk_0;
    u32 unk_4;
};
struct Sig_fn_800589BC_fn_800589BC_Arg3 {
    u32 unk_0;
    u32 unk_4;
};

typedef u32 (*fn_12_B9E8_Fn0)(u32, u32, u32, u32);
typedef u32 (*fn_12_B9E8_Fn1)(u32, u32, u32);
typedef u32 (*fn_12_B9E8_Fn2)(u32, u32, void *);
struct fn_12_B9E8_Arg0 {
    u8 pad_0[0x1ec];
    u32 unk_1ec;
    u32 unk_1f0;
    u32 unk_1f4;
    u32 unk_1f8;
    u32 unk_1fc;
    u32 unk_200;
    u8 pad_204[0x80];
    u32 unk_284;
    u32 unk_288;
    u8 pad_28c[0x103c];
    u32 unk_12c8;
    u32 unk_12cc;
    u32 unk_12d0;
    u8 pad_12d4[0x30];
    u32 unk_1304;
};
typedef struct MovieHdrView {
    u8 pad_0[0x12c8];
    u32 f_12c8;
} MovieHdrView;

extern u32 fn_800589BC(u32, u32, struct Sig_fn_800589BC_fn_800589BC_Arg2 *, struct Sig_fn_800589BC_fn_800589BC_Arg3 *);

#pragma opt_lifetimes off
s32 fn_12_B9E8(struct fn_12_B9E8_Arg0 *arg0, u32 arg1) {
    u32 v5;
    u32 v0;
    u32 v2;
    struct { u32 value; } v4;
    s32 v3;
    u32 v8;
    u32 v6;
    u32 v1;
    u32 v9;
    u32 v10;
    u32 v11;
    struct Sig_fn_800589BC_fn_800589BC_Arg3 loc_8;
    /* frame */
    arg0->unk_1304 = 2;
    *(u32 *)((u8 *)(u32)arg0 + 512) = (arg0->unk_200 + 1);
    v0 = *(u32 *)((u8 *)arg1 + 0);
    ((fn_12_B9E8_Fn0)*(u32 *)((u8 *)v0 + 24))(arg1, 1, (0x80000000 - 1), (u32)&arg0->unk_12c8);
    v1 = (((~0x3) & (arg0->unk_12c8)));
    v2 = *(u32 *)((u8 *)v1 + 4);
    v3 = (s32)((arg0->unk_12c8 - v1) << 3);
    v1 = v1 + 8;
    if (v3 >= 32) {
    v2 = *(u32 *)((u8 *)v1 + 0);
    v1 = v1 + 4;
    v3 -= 32;
    }
    if (v3 != 0) {
    v2 = (v2 << v3);
    }
    v4.value = *(u32 *)((u8 *)v1 + 0);
    v1 = v1 + 4;
    if (v3 >= 7) {
    v3 -= 7;
    if (v3 != 0) {
    v5 = (v2 | ((u32)v4.value >> (25 - v3)));
    v6 = ((u32)v5 >> 7);
    v5 = ((u32)v4.value << v3);
    } else {
    v6 = ((u32)v2 >> 7);
    v5 = v4.value;
    }
    v4.value = *(u32 *)((u8 *)v1 + 0);
    v1 = v1 + 4;
    } else {
    v6 = ((u32)v2 >> 7);
    v5 = (v2 << 25);
    v3 += 25;
    }
    *(u32 *)((u8 *)(u32)arg0 + 508) = (v6 & 0x3F);
    *(u32 *)((u8 *)(u32)arg0 + 504) = ((v6 >> 6) & 0x3F);
    *(u32 *)((u8 *)(u32)arg0 + 500) = ((v6 >> 13) & 0x3F);
    *(u32 *)((u8 *)(u32)arg0 + 496) = ((v6 >> 19) & 0x1F);
    *(u32 *)((u8 *)(u32)arg0 + 492) = ((u32)v6 >> 24);
    *(u32 *)((u8 *)(u32)arg0 + 644) = ((u32)v5 >> 31);
    if (v3 == 31) {
    v5 = v4.value;
    v3 = 0;
    v1 = v1 + 4;
    } else {
    v6 = (v5 << 1);
    v5 = v6;
    v3++;
    }
    *(u32 *)((u8 *)(u32)arg0 + 648) = ((u32)v5 >> 31);
    if (v3 == 31) {
    v3 = 0;
    v1 = ((4) + (v1));
    } else {
    v3++;
    }
    *(u32 *)((u8 *)(u32)arg0 + 4816) = (v3 & 0x7);
    v8 = *(u32 *)((u8 *)arg0 + 4808);
    v9 = (v3 - *(u32 *)((u8 *)arg0 + 4816));
    v1 = (v1 + ((s32)(v9 + 7) >> 3));
    fn_800589BC(((u32)arg0 + 4808), ((v1 - 8) - v8), (struct Sig_fn_800589BC_fn_800589BC_Arg2 *)((u32)arg0 + 4808), (struct Sig_fn_800589BC_fn_800589BC_Arg3 *)&loc_8);
    v8 = *(u32 *)((u8 *)arg1 + 0);
    v10 = v8;
    ((fn_12_B9E8_Fn1)*(u32 *)((u8 *)v10 + 32))(arg1, 0, (u32)&((MovieHdrView *)(u32)arg0)->f_12c8);
    v11 = *(u32 *)((u8 *)arg1 + 0);
    ((fn_12_B9E8_Fn2)*(u32 *)((u8 *)v11 + 28))(arg1, 1, &loc_8);
    return 0;
}
#pragma opt_lifetimes reset

/* fzgx:end fn_12_B9E8 */

/* fzgx:begin fn_12_BBC0 noprologue */
#include "types.h"
#include "sofdec/sj.h"

/* --- rel/movie_module/fn_12_BBC0.c --- */
#pragma use_lmw_stmw on

typedef void (*MPVFunc)();

typedef struct MPVContext {
    u8 pad_0[0x1a8];
    s32 unk_1a8;
    u8 pad_1ac[0x24];
    s32 unk_1d0;
    s32 unk_1d4;
    s32 unk_1d8;
    s32 unk_1dc;
    s32 unk_1e0;
    u8 pad_1e4[0x90];
    s32 unk_274;
    s32 unk_278;
    s32 unk_27c;
    s32 unk_280;
    u8 pad_284[0xc];
    MPVFunc unk_290;
    u8 pad_294[0x78];
    s32 unk_30c;
    u8 pad_310[0x930];
    u8 unk_c40[0x40];
    u8 unk_c80[0x40];
    u8 pad_cc0[0x608];
    SJCK unk_12c8;
    s32 unk_12d0;
    u8 pad_12d4[0x30];
    s32 unk_1304;
    u8 pad_1308[0x3c];
    u8 unk_1344[0x654][2];
} MPVContext;

extern void fn_800589BC(const SJCK *source, int nbyte, SJCK *first, SJCK *remainder);
extern void fn_12_33364(u32 *dst, u32 *src, u32 size);
extern void fn_12_33428(u32 *dst, u32 value, u32 count);
extern u32 lbl_12_bss_4DC0[];
extern s8 lbl_12_bss_4E00[];
extern MPVFunc const lbl_12_rodata_7A4[];
extern MPVFunc const lbl_12_rodata_7AC[];

/* read n bits (n < 32) from the cached big-endian bit window */
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
/* read one bit */
#define GET_BIT(dst)                                            \
    dst = current >> 31;                                        \
    if (shift == 31) {                                          \
        current = next;                                         \
        next = *p++;                                            \
        shift = 0;                                              \
    } else {                                                    \
        current <<= 1;                                          \
        shift++;                                                \
    }
#define SKIP_BITS(n)                                            \
    shift += (n);                                               \
    if (shift >= 32) {                                          \
        shift -= 32;                                            \
        current = next << shift;                                \
        next = *p++;                                            \
    } else {                                                    \
        current <<= (n);                                        \
    }

/* as in fn_12_B598, the end-of-header byte count needs the explicit temporaries kept */
#pragma opt_propagation off
int fn_12_BBC0(MPVContext *context, SJ *stream) {
    SJCK remainder;
    s32 width;
    s32 i;
    s32 j;
    u8 *data;
    s32 whole;
    u32 flag;
    u32 next;
    s32 shift;
    u32 current;
    u32 *p;
    u32 value;
    u32 word;

    context->unk_1304 = 1;
    stream->interface->get_chunk(stream, 1, 0x7FFFFFFF, &context->unk_12c8);
    p = (u32 *)((u32)context->unk_12c8.data & ~3);
    shift = ((u32)context->unk_12c8.data - (u32)p) * 8;
    word = p[1];
    p += 2;
    if (shift >= 32) {
        word = *p++;
        shift -= 32;
    }
    if (shift != 0) {
        word <<= shift;
    }
    next = *p++;
    current = word;

    GET_BITS(12, context->unk_1d0)
    GET_BITS(12, context->unk_1d4)
    GET_BITS(4, context->unk_274)
    GET_BITS(4, value)
    context->unk_1e0 = value;
    GET_BITS(18, context->unk_278)
    SKIP_BITS(1)
    GET_BITS(10, context->unk_27c)
    GET_BIT(context->unk_280)
    GET_BIT(flag)
    if (flag != 0) {
        for (i = 0; i < 64; i++) {
            GET_BITS(8, value)
            context->unk_c40[lbl_12_bss_4E00[i]] = value;
        }
    } else {
        fn_12_33364((u32 *)context->unk_c40, lbl_12_bss_4DC0, 16);
    }
    GET_BIT(flag)
    if (flag != 0) {
        for (j = 0; j < 64; j++) {
            GET_BITS(8, value)
            context->unk_c80[lbl_12_bss_4E00[j]] = value;
        }
    } else {
        fn_12_33428((u32 *)context->unk_c80, 0x10101010, 16);
    }

    context->unk_1d8 = (context->unk_1d0 + 15) >> 4;
    context->unk_1dc = (context->unk_1d4 + 15) >> 4;
    context->unk_30c = context->unk_1dc * context->unk_1d8 - 1;
    /* the bit-window words are dead here and are reused below: next as the table index, current/word as the
     * cursor and end of the 0x654 two-byte entries at 0x1344, j/i as the two counters (retail's register
     * assignment follows that reuse) */
    width = context->unk_1d8;
    next = context->unk_1a8 != 3;
    if (width * context->unk_1dc < 0x654) {
        current = (u32)context->unk_1344[0];
        word = current + 0xca8;
        j = 0;
        i = 0;
        while (current < word) {
            if (i >= width) {
                i = 0;
                j++;
            }
            ((u8 *)current)[0] = j;
            ((u8 *)current)[1] = i;
            current += 2;
            i++;
        }
        context->unk_290 = lbl_12_rodata_7A4[next];
    } else {
        context->unk_290 = lbl_12_rodata_7AC[next];
    }

    context->unk_12d0 = shift & 7;
    data = context->unk_12c8.data;
    whole = shift - context->unk_12d0;
    p = (u32 *)((u32)p + ((whole + 7) >> 3));
    fn_800589BC(&context->unk_12c8, ((u32)p - 8) - (u32)data, &context->unk_12c8, &remainder);
    stream->interface->put_chunk(stream, 0, &context->unk_12c8);
    stream->interface->unget_chunk(stream, 1, &remainder);
    return 0;
}
/* fzgx:end fn_12_BBC0 */

/* fzgx:begin fn_12_C218 noprologue */
#pragma opt_propagation reset

/* --- rel/movie_module/fn_12_C218.c --- */
typedef struct MovieObject_u1 MovieObject_u1;
typedef struct MovieArgs {
    u32 field_0000;
    u32 field_0004;
} MovieArgs;

typedef struct MovieVTable {
    u8 pad_0000[0x0c];
    void (*method_000c)(MovieObject_u1 *);
    u8 pad_0010[0x14];
    s32 (*method_0024)(MovieObject_u1 *, s32);
} MovieVTable;

struct MovieObject_u1 {
    MovieVTable *vtable;
};

extern MovieObject_u1 *fn_80057B9C(u32 arg0, u32 arg1);
extern s32 fn_12_C2C8(void *arg0, MovieObject_u1 *movie);

s32 fn_12_C218(void *arg0, MovieArgs *args, s32 *result) {
    s32 status;
    s32 elapsed;
    MovieObject_u1 *movie;

    movie = fn_80057B9C(args->field_0000, args->field_0004);
    if (movie == 0) {
        return -1;
    }
    status = fn_12_C2C8(arg0, movie);
    elapsed = movie->vtable->method_0024(movie, 1);
    *result = args->field_0004 - elapsed;
    movie->vtable->method_000c(movie);
    return status;
}
/* fzgx:end fn_12_C218 */

/* fzgx:begin fn_12_C2C8 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_C2C8.c --- */
typedef struct SJCK {
    union {
        unsigned char padding_extent[8];
        struct {
            unsigned char *data;
        } view_data;
        struct {
            unsigned char padding_len[4];
            long len;
        } view_len;
    } fields;
} SJCK;

typedef struct SJ_u0 SJ_u0;

typedef struct SJInterface_u0 SJInterface_u0;

struct SJInterface_u0 {
    union {
        unsigned char padding_extent[48];
        struct {
            unsigned char padding_get_chunk[24];
            void (*get_chunk)(SJ_u0 *sj, long channel, long max_size, SJCK *chunk);
        } view_get_chunk;
        struct {
            unsigned char padding_unget_chunk[28];
            void (*unget_chunk)(SJ_u0 *sj, int channel, SJCK *chunk);
        } view_unget_chunk;
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

typedef struct MPVContext_u0 MPVContext_u0;

typedef struct MPVErrorInfo {
    union {
        unsigned char padding_extent[20];
        struct {
            unsigned char padding_field_0C[12];
            int field_0C;
        } view_field_0C;
        struct {
            unsigned char padding_field_10[16];
            int field_10;
        } view_field_10;
    } fields;
} MPVErrorInfo;

typedef struct MPVConditionState {
    union {
        unsigned char padding_extent[192];
        struct {
            int conditions[16];
        } view_conditions;
    } fields;
} MPVConditionState;

typedef struct MPVPictureUserBuffer {
    union {
        unsigned char padding_extent[12];
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
            unsigned char padding_condition_state[400];
            MPVConditionState condition_state;
        } view_condition_state;
        struct {
            unsigned char padding_error_info[544];
            MPVErrorInfo error_info;
        } view_error_info;
        struct {
            unsigned char padding_field_358[4820];
            s32 field_358;
        } view_field_358;
        struct {
            unsigned char padding_field_1300[4800];
            s32 field_1300;
        } view_field_1300;
        struct {
            unsigned char padding_field_1304[4804];
            s32 field_1304;
        } view_field_1304;
        struct {
            unsigned char padding_header_chunk[4808];
            SJCK header_chunk;
        } view_header_chunk;
        struct {
            unsigned char padding_bit_offset[4816];
            s32 bit_offset;
        } view_bit_offset;
        struct {
            unsigned char padding_picture_user[4920];
            MPVPictureUserBuffer picture_user;
        } view_picture_user;
    } fields;
};

void fn_800589BC(const SJCK *source, int nbyte, SJCK *first, SJCK *remainder);

int fn_12_A660(MPVContext_u0 *handle, int error);

int fn_12_CAB4(MPVContext_u0 *handle);

const unsigned char *fn_12_A0D8(const unsigned char *data, int length, int mask);

int fn_12_A2C4(const unsigned char *data);

extern int fn_12_20170(MPVContext_u0 *context, SJ_u0 *stream);

static inline int MPV_MoveChunk(SJ_u0 *stream, int channel, int size) {
    SJCK chunk;
    int source_channel = channel;
    channel = channel == 0;
    stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(stream, source_channel,
                                                                             size, &chunk);
    stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(stream, channel,
                                                                             &chunk);
    return chunk.fields.view_len.len;
}

static inline int mpvhdec_ReadDelimSj(SJ_u0 *stream) {
    SJCK chunk;
    SJCK remainder;
    const u8 *delimiter;
    int delimiter_type;
    for (;;) {
        stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
            stream, 1, 0x7FFFFFFF, &chunk);
        if (chunk.fields.view_len.len < 4) {
            stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                         &chunk);
            return 0;
        }
        delimiter = fn_12_A0D8(chunk.fields.view_data.data, chunk.fields.view_len.len, -1);
        if (delimiter != 0) {
            break;
        }
        fn_800589BC(&chunk, chunk.fields.view_len.len - 3, &chunk, &remainder);
        stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(stream, 0, &chunk);
        stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                     &remainder);
    }
    delimiter_type = fn_12_A2C4(delimiter);
    fn_800589BC(&chunk, delimiter - chunk.fields.view_data.data, &chunk, &remainder);
    stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(stream, 0, &chunk);
    stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                 &remainder);
    return delimiter_type;
}

static inline int mpvhdec_DetectDecoderMode(MPVContext_u0 *context, const u8 *data, int length) {
    const u8 *delimiter;
    int delimiter_type;
    if (context->fields.view_field_358.field_358 != 0) {
        return context->fields.view_field_358.field_358;
    }
    delimiter = fn_12_A0D8(data, length, 0x40);
    if (delimiter == 0) {
        return context->fields.view_field_358.field_358;
    }
    delimiter += 4;
    delimiter = fn_12_A0D8(delimiter, length - (delimiter - data), -1);
    if (delimiter == 0) {
        return context->fields.view_field_358.field_358;
    }
    delimiter_type = fn_12_A2C4(delimiter);
    if (delimiter_type & 0x10) {
        context->fields.view_field_358.field_358 = 2;
    } else if (delimiter_type != 0) {
        context->fields.view_field_358.field_358 = 1;
    }
    return context->fields.view_field_358.field_358;
}

static inline int mpvhdec_SeekPictureData(MPVContext_u0 *context, SJ_u0 *stream, int wanted_mask) {
    int condition;
    int error;
    int delimiter_type;
    condition =
        context->fields.view_condition_state.condition_state.fields.view_conditions.conditions[1];
    if (context->fields.view_field_1300.field_1300 != 0) {
        context->fields.view_field_1300.field_1300 = 0;
        context->fields.view_field_1304.field_1304++;
        context->fields.view_error_info.error_info.fields.view_field_0C.field_0C++;
        if (condition == 0) {
            return -2;
        }
        context->fields.view_error_info.error_info.fields.view_field_10.field_10++;
    }
    if (condition == 0) {
        error = -2;
    } else {
        error = -3;
    }
    for (;;) {
        delimiter_type = mpvhdec_ReadDelimSj(stream);
        if (delimiter_type == 0) {
            break;
        }
        if ((delimiter_type & wanted_mask) != 0) {
            error = 0;
            break;
        }
        if (MPV_MoveChunk(stream, 1, 4) != 4) {
            break;
        }
    }
    return error;
}

static inline int MPV_GoNextDelimSj(SJ_u0 *stream) {
    SJCK chunk;
    SJCK remainder;
    const u8 *delimiter;
    int delimiter_type;
    for (;;) {
        stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
            stream, 1, 0x7FFFFFFF, &chunk);
        if (chunk.fields.view_len.len < 4) {
            stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                         &chunk);
            delimiter_type = 0;
            break;
        }
        delimiter = fn_12_A0D8(chunk.fields.view_data.data, chunk.fields.view_len.len, -1);
        if (delimiter == 0) {
            fn_800589BC(&chunk, chunk.fields.view_len.len - 3, &chunk, &remainder);
            stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(stream, 0,
                                                                                     &chunk);
            stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(
                stream, 1, &remainder);
            continue;
        }
        delimiter_type = fn_12_A2C4(delimiter);
        fn_800589BC(&chunk, delimiter - chunk.fields.view_data.data, &chunk, &remainder);
        stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(stream, 0, &chunk);
        stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                     &remainder);
        break;
    }
    return delimiter_type;
}

static inline void mpvhdec_ConsumeDelim(MPVContext_u0 *context, SJ_u0 *stream) {
    SJCK remainder;
    s32 bits;
    u32 *p;
    u32 initial;
    s32 cnt;
    u8 *cursor;
    stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
        stream, 1, 0x7FFFFFFF, &context->fields.view_header_chunk.header_chunk);
    p = (u32 *)((u32)context->fields.view_header_chunk.header_chunk.fields.view_data.data & ~3);
    initial = p[1];
    bits = ((u32)context->fields.view_header_chunk.header_chunk.fields.view_data.data - (u32)p) * 8;
    p += 2;
    if (bits >= 32) {
        bits -= 32;
        initial = *p++;
    }
    if (bits) {
        initial <<= bits;
    }
    context->fields.view_bit_offset.bit_offset = bits & 7;
    cnt = (bits - context->fields.view_bit_offset.bit_offset + 7) >> 3;
    cursor = (u8 *)(p - 1) + cnt;
    fn_800589BC(&context->fields.view_header_chunk.header_chunk, cursor - context->fields.view_header_chunk.header_chunk.fields.view_data.data, &context->fields.view_header_chunk.header_chunk, &remainder);
    stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(stream, 0, &context->fields.view_header_chunk.header_chunk);
    stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1, &remainder);
    MPV_GoNextDelimSj(stream);
}

int fn_12_B3E0(MPVContext_u0 *context, const u8 *data, long length);

static inline void mpvhdec_ConsumeUserData(MPVContext_u0 *context, SJ_u0 *stream) {
    SJCK remainder;
    s32 bits;
    u32 *p;
    u32 initial;
    s32 cnt;
    u8 *cursor;
    stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
        stream, 1, 0x7FFFFFFF, &context->fields.view_header_chunk.header_chunk);
    p = (u32 *)((u32)context->fields.view_header_chunk.header_chunk.fields.view_data.data & ~3);
    initial = p[1];
    bits = ((u32)context->fields.view_header_chunk.header_chunk.fields.view_data.data - (u32)p) * 8;
    p += 2;
    if (bits >= 32) {
        bits -= 32;
        initial = *p++;
    }
    if (bits) {
        initial <<= bits;
    }
    fn_12_B3E0(context, context->fields.view_header_chunk.header_chunk.fields.view_data.data,
               context->fields.view_header_chunk.header_chunk.fields.view_len.len);
    context->fields.view_bit_offset.bit_offset = bits & 7;
    cnt = (bits - context->fields.view_bit_offset.bit_offset + 7) >> 3;
    cursor = (u8 *)(p - 1) + cnt;
    fn_800589BC(&context->fields.view_header_chunk.header_chunk, cursor - context->fields.view_header_chunk.header_chunk.fields.view_data.data, &context->fields.view_header_chunk.header_chunk, &remainder);
    stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(stream, 0, &context->fields.view_header_chunk.header_chunk);
    stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1, &remainder);
    MPV_GoNextDelimSj(stream);
}

int fn_12_B598(MPVContext_u0 *context, SJ_u0 *stream);

int fn_12_B9E8(MPVContext_u0 *context, SJ_u0 *stream);

int fn_12_BBC0(MPVContext_u0 *context, SJ_u0 *stream);

int fn_12_C2C8(void *handle, SJ_u0 *stream) {
    MPVContext_u0 *context = handle;
    SJCK initial_chunk;
    SJCK chunk;
    const u8 *chunk_data;
    int chunk_len;
    int delimiter_type;
    int error;
    if (fn_12_CAB4(context) != 0) {
        return fn_12_A660(0, 0xFF03020C);
    }
    context->fields.view_picture_user.picture_user.fields.view_size.size = 0;
    stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(stream, 1, 0x7FFFFFFF,
                                                                             &initial_chunk);
    stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                 &initial_chunk);
    chunk_data = initial_chunk.fields.view_data.data;
    chunk_len = initial_chunk.fields.view_len.len;
    if (mpvhdec_DetectDecoderMode(context, chunk_data, chunk_len) == 2) {
        return fn_12_20170(context, stream);
    }
    for (;;) {
        error = mpvhdec_SeekPictureData(context, stream, -1);
        if (error != 0) {
            return fn_12_A660(context, error);
        }
        stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
            stream, 1, 0x7FFFFFFF, &chunk);
        stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                     &chunk);
        delimiter_type =
            chunk.fields.view_len.len < 4 ? 0 : fn_12_A2C4(chunk.fields.view_data.data);
        if (delimiter_type == 0 || (delimiter_type & 3) != 0) {
            break;
        }
        switch (delimiter_type) {
        case 0x40:
            fn_12_BBC0(context, stream);
            break;
        case 8:
            fn_12_B9E8(context, stream);
            break;
        case 4:
            fn_12_B598(context, stream);
            break;
        case 0x10:
            mpvhdec_ConsumeDelim(context, stream);
            break;
        case 0x20:
            mpvhdec_ConsumeUserData(context, stream);
            break;
        }
    }
    return error;
}
/* fzgx:end fn_12_C2C8 */

/* fzgx:begin fn_12_CA60 noprologue */

/* --- rel/movie_module/fn_12_CA60.c --- */
/* --- rel/movie_module/fn_12_CA60.c --- */
/* --- rel/movie_module/fn_12_CA60.c --- */
typedef struct MovieObject {
    u8 pad_0000[0x1338];
    u32 field_1338;
    u32 field_133c;
    u32 field_1340;
} MovieObject;

void fn_12_CA60(MovieObject *self, u32 *value_1338, u32 *value_1340) {
    if (value_1338 != 0) {
        *value_1338 = self->field_1338;
    }
    if (value_1340 != 0) {
        *value_1340 = self->field_1340;
    }
}
/* fzgx:end fn_12_CA60 */

/* fzgx:begin fn_12_CA84 noprologue */

/* --- rel/movie_module/fn_12_CA84.c --- */
void fn_12_CA84(MovieObject *self, u32 value_1338, u32 value_133c) {
    self->field_1338 = value_1338;
    self->field_133c = value_133c;
    self->field_1340 = 0;
}
/* fzgx:end fn_12_CA84 */

/* fzgx:begin fn_12_CA98 noprologue */

/* --- rel/movie_module/fn_12_CA98.c --- */
/* --- rel/movie_module/fn_12_CA98.c --- */
typedef struct MovieEntry {
    u32 field_0;
    u32 field_4;
    u32 field_8;
} MovieEntry;

typedef struct MovieObject_u1 {
    u8 pad_0000[0x1308];
} MovieObject_u1;

void fn_12_CA98(MovieObject_u1 *self, s32 index, u32 value_0, u32 value_4, u32 value_8) {
    MovieEntry *entry = (MovieEntry *)((u8 *)self + index * 12 + 0x1308);
    entry->field_0 = value_0;
    entry->field_4 = value_4;
    entry->field_8 = value_8;
}
/* fzgx:end fn_12_CA98 */
