#include "types.h"
typedef struct MPVContext MPVContext;
#include "sofdec/sj.h"

typedef void (*fn1_t)(void *);

typedef void (*fn0_t)(u32);

typedef struct fn_12_8F80_SJCK {
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
} fn_12_8F80_SJCK;

typedef struct fn_12_8F80_SJInterface fn_12_8F80_SJInterface;

typedef struct fn_12_8F80_SJ fn_12_8F80_SJ;

struct fn_12_8F80_SJInterface {
    union {
        unsigned char padding_extent[48];
        struct {
            unsigned char padding_get_chunk[24];
            void (*get_chunk)(fn_12_8F80_SJ *sj, int channel, int max_size, fn_12_8F80_SJCK *chunk);
        } view_get_chunk;
        struct {
            unsigned char padding_unget_chunk[28];
            void (*unget_chunk)(fn_12_8F80_SJ *sj, int channel, fn_12_8F80_SJCK *chunk);
        } view_unget_chunk;
        struct {
            unsigned char padding_put_chunk[32];
            void (*put_chunk)(fn_12_8F80_SJ *sj, int channel, fn_12_8F80_SJCK *chunk);
        } view_put_chunk;
    } fields;
};

struct fn_12_8F80_SJ {
    union {
        unsigned char padding_extent[4];
        struct {
            const fn_12_8F80_SJInterface *interface;
        } view_interface;
    } fields;
};

struct Sig_fn_800589BC_fn_800589BC_Arg2 { u8 lab_pad[8]; u32 unk_0, unk_4; };

struct Sig_fn_800589BC_fn_800589BC_Arg3 { u32 unk_0, unk_4; };

typedef struct MovieBits {
    s32 field_0;
    u32 field_4;
    s32 field_8;
    u32 *field_c;
} MovieBits;

typedef struct MovieCode {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_c;
} MovieCode;
extern void fn_800589BC(const SJCK *, s32, SJCK *, SJCK *);
extern s16 *lbl_12_bss_6934;
extern s16 *lbl_12_bss_6930;
extern s16 *lbl_12_bss_6928;
extern s16 *lbl_12_bss_691C;
extern int MPV_GoNextDelimSj(SJ *stream);
extern s32 fn_12_9594(MovieBits *state, MovieCode *code, s32 *out, s32 *base);
extern s16 *lbl_12_bss_6944;
extern s16 *lbl_12_bss_6940;
extern u32 lbl_12_bss_6924;
extern u32 lbl_12_bss_6920;

/* fzgx:begin fn_12_8BD8 */
typedef void (*fn1_t)(void *);
typedef void (*fn0_t)(u32);

struct fn_12_8BD8_ctx {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_c;
    u32 pad1[103];
    u32 unk_1ac;
    fn0_t unk_1b0;
    u32 unk_1b4;
    u32 pad2[57];
    fn1_t unk_29c;
    u32 pad3;
    fn1_t unk_2a4;
    u32 pad4[5];
    u32 unk_2bc;
    u32 pad5[18];
    s32 unk_308;
    s32 unk_30c;
    s32 unk_310;
    u32 pad6[1005];
    /* The buffered input chunk and bit offset within its first byte. */
    SJCK chunk;
    s32 unk_12d0;
    u32 pad7[8];
    s32 unk_12f4;
};


#pragma opt_propagation off
void fn_12_8BD8(struct fn_12_8BD8_ctx *arg0, SJ *arg1) {
    SJCK localA;
    SJCK localB;
    s32 sh8;
    u32 w0;
    u32 w1;
    s32 sh;
    u32 *ptr;
    u32 v_2;
    u32 v;
    u32 code;
    u32 t;
    s32 len;
    u8 run_code;
    s32 old;
    s32 n;
    u32 lab_t1;

    arg1->interface->get_chunk(arg1, 1, 0x7FFFFFFF, &arg0->chunk);

    ptr = (u32 *)((u32)arg0->chunk.data & ~3);
    sh = ((u32)arg0->chunk.data - (u32)ptr) * 8;
    w0 = ptr[0] << sh;
    w1 = ptr[1];
    ptr += 2;
    sh += arg0->unk_12d0;
    if (sh >= 32) {
        sh -= 32;
        w0 = w1 << sh;
        w1 = ptr[0];
        ptr++;
    } else {
        w0 <<= arg0->unk_12d0;
    }

    for (;;) {
        v = w0 >> 9;
        if (sh > 9) {
            v |= w1 >> (41 - sh);
        }
        if (v == 0) {
            break;
        }
        old = arg0->unk_308;
        /* Stuffing and escape codes retry without testing the start delimiter. */
        for (;;) {
            code = w0 >> 20;
            if (sh > 20) {
                code |= w1 >> (52 - sh);
            }
            if ((code >> 8) == 0) {
                t = lbl_12_bss_6944[code];
            } else {
                t = lbl_12_bss_6940[code >> 6];
            }
            v_2 = t & 0xF;
            sh += v_2;
            if (sh >= 32) {
                sh -= 32;
                w0 = w1 << sh;
                w1 = ptr[0];
                ptr++;
            } else {
                w0 <<= v_2;
            }
            run_code = (t >> 2) & 0xFF;
            len = run_code >> 2;
            if (len == 0x22) {
                continue;
            }
            if (len == 0x23) {
                arg0->unk_308 += 0x21;
                continue;
            }
            break;
        }
        if (len == 0x24) {
            v_2 = -2;
        } else {
            arg0->unk_308 += len;
            arg0->unk_310 = t >> 10;
            if (arg0->unk_308 > arg0->unk_30c) {
                v_2 = -2;
            } else {
                v_2 = arg0->unk_308 - old;
            }
        }
        v_2 = v_2 + 0x10000;
        if ((u32)v_2 == 0xFFFE) {
            break;
        }
        arg0->unk_0 = w0;
        arg0->unk_4 = w1;
        arg0->unk_8 = sh;
        arg0->unk_c = (u32)ptr;
        arg0->unk_29c(arg0);
        arg0->unk_2a4(arg0);
        if (--arg0->unk_12f4 <= 0) {
            arg0->unk_12f4 = arg0->unk_1ac;
            arg0->unk_1b0(arg0->unk_1b4);
        }
        w0 = arg0->unk_0;
        w1 = arg0->unk_4;
        sh = arg0->unk_8;
        ptr = (u32 *)arg0->unk_c;
        /* This variant reads one continuation bit after each decoded block. */
        v_2 = w0 >> 31;
        if (sh == 31) {
            w0 = w1;
            w1 = *ptr++;
            sh = 0;
        } else {
            w0 <<= 1;
            sh++;
        }
        if (v_2 != 1) {
            break;
        }
        sh8 = sh & 7;
        n = (u32)ptr;
        n += ((sh - sh8 + 7) >> 3);
        n -= 8;
        n -= (u32)arg0->chunk.data;
        /* Split off the consumed prefix when fewer than 2 KiB remain. */
        if (arg0->chunk.len - n > 0x800) {
            continue;
        }
        fn_800589BC(&arg0->chunk, n, &arg0->chunk, &localA);
        arg1->interface->put_chunk(arg1, 0, &arg0->chunk);
        arg1->interface->unget_chunk(arg1, 1, &localA);
        arg1->interface->get_chunk(arg1, 1, 0x7FFFFFFF, &arg0->chunk);
        ptr = (u32 *)((u32)arg0->chunk.data & ~3);
        sh = ((u32)arg0->chunk.data - (u32)ptr) * 8;
        w0 = ptr[0] << sh;
        w1 = ptr[1];
        ptr += 2;
        sh += sh8;
        if (sh >= 32) {
            sh -= 32;
            w0 = w1 << sh;
            w1 = ptr[0];
            ptr++;
        } else {
            w0 <<= sh8;
        }
    }

    arg0->unk_12d0 = sh & 7;
    ptr = (u32 *)((u8 *)ptr + ((sh - arg0->unk_12d0 + 7) >> 3));
    ptr = (u32 *)((u8 *)ptr - 8);
    lab_t1 = (u32)arg0->chunk.data;
    fn_800589BC(&arg0->chunk, ((u32)ptr - lab_t1), &arg0->chunk, &localB);
    arg1->interface->put_chunk(arg1, 0, &arg0->chunk);
    arg1->interface->unget_chunk(arg1, 1, &localB);
    MPV_GoNextDelimSj( (SJ *)((fn_12_8F80_SJ *)(SJ *)(arg1)));
}
#pragma opt_propagation reset
/* fzgx:end fn_12_8BD8 */

/* fzgx:begin fn_12_8F80 noprologue */
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

typedef struct MPVMotionInfo {
    union {
        unsigned char padding_extent[36];
        struct {
            unsigned char padding_previous_horizontal[16];
            s32 previous_horizontal;
        } view_previous_horizontal;
        struct {
            unsigned char padding_previous_vertical[20];
            s32 previous_vertical;
        } view_previous_vertical;
        struct {
            unsigned char padding_horizontal[24];
            s32 horizontal;
        } view_horizontal;
        struct {
            unsigned char padding_vertical[28];
            s32 vertical;
        } view_vertical;
    } fields;
} MPVMotionInfo;

typedef struct MPVPictureAttributes {
    union {
        unsigned char padding_extent[104];
        struct {
            unsigned char padding_macroblocks_per_row[8];
            int macroblocks_per_row;
        } view_macroblocks_per_row;
    } fields;
} MPVPictureAttributes;

typedef struct MPVBitReader {
    union {
        unsigned char padding_extent[16];
        struct {
            u32 bits;
        } view_bits;
        struct {
            unsigned char padding_next_bits[4];
            u32 next_bits;
        } view_next_bits;
        struct {
            unsigned char padding_bit_offset[8];
            s32 bit_offset;
        } view_bit_offset;
        struct {
            unsigned char padding_words[12];
            const u32 *words;
        } view_words;
    } fields;
} MPVBitReader;

typedef struct MPVDecoderFields {
    union {
        unsigned char padding_extent[168];
        struct {
            unsigned char padding_field_1AC[28];
            s32 field_1AC;
        } view_field_1AC;
        struct {
            unsigned char padding_callback[32];
            void (*callback)(void *argument);
        } view_callback;
        struct {
            unsigned char padding_callback_argument[36];
            void *callback_argument;
        } view_callback_argument;
        struct {
            unsigned char padding_picture[64];
            MPVPictureAttributes picture;
        } view_picture;
    } fields;
} MPVDecoderFields;

typedef union MPVConditionState {
    union {
        unsigned char padding_extent[168];
        struct {
            MPVDecoderFields decoder;
        } view_decoder;
    } fields;
} MPVConditionState;

struct MPVContext {
    union {
        unsigned char padding_extent[4992];
        struct {
            MPVBitReader bit_reader;
        } view_bit_reader;
        struct {
            unsigned char padding_condition_state[400];
            MPVConditionState condition_state;
        } view_condition_state;
        struct {
            unsigned char padding_skip_macroblocks[664];
            void (*skip_macroblocks)(MPVContext *, int);
        } view_skip_macroblocks;
        struct {
            unsigned char padding_decode_intra_blocks[668];
            int (*decode_intra_blocks)(void *);
        } view_decode_intra_blocks;
        struct {
            unsigned char padding_decode_nonintra_blocks[672];
            int (*decode_nonintra_blocks)(void *);
        } view_decode_nonintra_blocks;
        struct {
            unsigned char padding_motion_intra[676];
            void (*motion_intra)(MPVContext *);
        } view_motion_intra;
        struct {
            unsigned char padding_motion_skipped[680];
            void (*motion_skipped)(MPVContext *);
        } view_motion_skipped;
        struct {
            unsigned char padding_quantizer_scale[700];
            u32 quantizer_scale;
        } view_quantizer_scale;
        struct {
            unsigned char padding_forward_motion[704];
            MPVMotionInfo forward_motion;
        } view_forward_motion;
        struct {
            unsigned char padding_backward_motion[740];
            MPVMotionInfo backward_motion;
        } view_backward_motion;
        struct {
            unsigned char padding_macroblock_index[776];
            s32 macroblock_index;
        } view_macroblock_index;
        struct {
            unsigned char padding_macroblock_row[824];
            s32 macroblock_row;
        } view_macroblock_row;
        struct {
            unsigned char padding_macroblock_column[828];
            s32 macroblock_column;
        } view_macroblock_column;
        struct {
            unsigned char padding_last_macroblock_index[780];
            s32 last_macroblock_index;
        } view_last_macroblock_index;
        struct {
            unsigned char padding_field_344[784];
            u32 field_344;
        } view_field_344;
        struct {
            unsigned char padding_cbp_mask[788];
            s32 cbp_mask;
        } view_cbp_mask;
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
            unsigned char padding_header_chunk[4808];
            SJCK header_chunk;
        } view_header_chunk;
        struct {
            unsigned char padding_field_12d0[4816];
            s32 field_12d0;
        } view_field_12d0;
        struct {
            unsigned char padding_field_1310[4880];
            s32 field_1310;
        } view_field_1310;
        struct {
            unsigned char padding_field_1324[4852];
            s32 field_1324;
        } view_field_1324;
    } fields;
};

void fn_800589BC(const SJCK *source, int nbyte, SJCK *first, SJCK *remainder);

extern s16 *lbl_12_bss_6934;

extern s16 *lbl_12_bss_6930;

extern s16 *lbl_12_bss_6928;

extern s16 *lbl_12_bss_691C;

extern int MPV_GoNextDelimSj(SJ *stream);

int fn_12_9594(MPVBitReader *reader, MPVMotionInfo *motion, s32 *output, s32 *predictor);

static inline void mpvdec_InitMacroblockReader(const u8 *data, int extra_offset, const u32 **words,
                                               u32 *bits, u32 *next_bits, int *bit_offset) {
    *words = (const u32 *)((unsigned long)data & ~3UL);
    *bit_offset = (int)(data - (const u8 *)*words) * 8;
    *bits = (*words)[0];
    *next_bits = (*words)[1];
    *bits <<= *bit_offset;
    *words += 2;
    *bit_offset += extra_offset;
    if (*bit_offset >= 32) {
        *bit_offset -= 32;
        *bits = *next_bits << *bit_offset;
        *next_bits = *(*words)++;
    } else {
        *bits <<= extra_offset;
    }
}

#pragma opt_common_subs off
void fn_12_8F80(MPVContext *context, SJ *stream) {
    SJCK refill_remainder;
    SJCK final_remainder;
    int bit_offset;
    u32 bits;
    u32 next_bits;
    const u32 *words;
    u32 peek;
    u32 delta;
    u32 quantizer;
    int residual_offset;
    int consumed;
    int first_macroblock = 1;
    stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
        stream, 1, 0x7FFFFFFF, &context->fields.view_header_chunk.header_chunk);
    mpvdec_InitMacroblockReader(
        context->fields.view_header_chunk.header_chunk.fields.view_data.data,
        context->fields.view_field_12d0.field_12d0, &words, &bits, &next_bits, &bit_offset);
    for (;;) {
        int old_index;
        s16 descriptor;
        peek = bits;
        peek = peek >> 9;
        if (bit_offset > 9) {
            peek |= next_bits >> (41 - bit_offset);
        }
        if (((0) == (peek))) {
            break;
        }
        old_index = context->fields.view_macroblock_index.macroblock_index;
        for (;;) {
            int descriptor;
            u8 code_length;
            u8 encoded_increment;
            int increment;
            peek = bits >> 21;
            if (bit_offset > 21) {
                peek |= next_bits >> (53 - bit_offset);
            }
            if ((peek >> 7) == 0) {
                descriptor = lbl_12_bss_6934[peek];
            } else {
                descriptor = lbl_12_bss_6930[peek >> 6];
            }
            code_length = descriptor & 0xF;
            bit_offset += code_length;
            if (bit_offset >= 32) {
                bit_offset -= 32;
                bits = next_bits << bit_offset;
                next_bits = *words++;
            } else {
                bits <<= code_length;
            }
            encoded_increment = (u32)descriptor >> 2;
            increment = encoded_increment >> 2;
            if (increment == 34) {
                continue;
            }
            if (increment == 35) {
                context->fields.view_macroblock_index.macroblock_index += 33;
                continue;
            }
            if (increment == 36) {
                delta = (u32)-2;
            } else {
                context->fields.view_macroblock_index.macroblock_index += increment;
                context->fields.view_field_344.field_344 = (u32)descriptor >> 10;
                if (context->fields.view_macroblock_index.macroblock_index >
                    context->fields.view_last_macroblock_index.last_macroblock_index) {
                    delta = (u32)-2;
                } else {
                    delta = context->fields.view_macroblock_index.macroblock_index - old_index;
                }
            }
            break;
        }
        if (delta == (u32)-2) {
            break;
        }
        if (!first_macroblock && delta > 1) {
            context->fields.view_skip_macroblocks.skip_macroblocks(context, delta);
            context->fields.view_dc_predictor_y.dc_predictor_y = 0x400;
            context->fields.view_dc_predictor_cr.dc_predictor_cr = 0x400;
            context->fields.view_dc_predictor_cb.dc_predictor_cb = 0x400;
        }
        if ((context->fields.view_field_344.field_344 & 0x20) == 0) {
            int descriptor;
            peek = bits >> 26;
            if (bit_offset > 26) {
                peek |= next_bits >> (58 - bit_offset);
            }
            descriptor = lbl_12_bss_6928[peek];
            context->fields.view_field_344.field_344 = (u32)descriptor >> 8;
            bit_offset += ((0xff) & (descriptor));
            if (bit_offset >= 32) {
                bit_offset -= 32;
                bits = next_bits << bit_offset;
                next_bits = *words++;
            } else {
                bits <<= descriptor & 0xff;
            }
        }
        if ((context->fields.view_field_344.field_344 & 0x10) != 0) {
            if (bit_offset >= 27) {
                bit_offset -= 27;
                if (bit_offset != 0) {
                    bits |= next_bits >> (5 - bit_offset);
                    quantizer = bits >> 27;
                    bits = next_bits << bit_offset;
                } else {
                    quantizer = bits >> 27;
                    bits = next_bits;
                }
                next_bits = *words++;
            } else {
                quantizer = bits >> 27;
                bits <<= 5;
                bit_offset += 5;
            }
            context->fields.view_quantizer_scale.quantizer_scale = quantizer;
        }
        if ((context->fields.view_field_344.field_344 & 8) != 0) {
            int horizontal_result;
            int vertical_result;
            context->fields.view_bit_reader.bit_reader.fields.view_bits.bits = bits;
            context->fields.view_bit_reader.bit_reader.fields.view_next_bits.next_bits = next_bits;
            context->fields.view_bit_reader.bit_reader.fields.view_bit_offset.bit_offset =
                bit_offset;
            context->fields.view_bit_reader.bit_reader.fields.view_words.words = words;
            horizontal_result =
                fn_12_9594(&context->fields.view_bit_reader.bit_reader,
                           &context->fields.view_forward_motion.forward_motion,
                           &context->fields.view_forward_motion.forward_motion.fields
                                .view_horizontal.horizontal,
                           &context->fields.view_forward_motion.forward_motion.fields
                                .view_previous_horizontal.previous_horizontal);
            vertical_result = fn_12_9594(
                &context->fields.view_bit_reader.bit_reader,
                &context->fields.view_forward_motion.forward_motion,
                &context->fields.view_forward_motion.forward_motion.fields.view_vertical.vertical,
                &context->fields.view_forward_motion.forward_motion.fields.view_previous_vertical
                     .previous_vertical);
            bits = context->fields.view_bit_reader.bit_reader.fields.view_bits.bits;
            next_bits = context->fields.view_bit_reader.bit_reader.fields.view_next_bits.next_bits;
            bit_offset =
                context->fields.view_bit_reader.bit_reader.fields.view_bit_offset.bit_offset;
            words = context->fields.view_bit_reader.bit_reader.fields.view_words.words;
            if ((horizontal_result | vertical_result) != 0) {
                break;
            }
        }
        if ((context->fields.view_field_344.field_344 & 4) != 0) {
            int horizontal_result;
            int vertical_result;
            context->fields.view_bit_reader.bit_reader.fields.view_bits.bits = bits;
            context->fields.view_bit_reader.bit_reader.fields.view_next_bits.next_bits = next_bits;
            context->fields.view_bit_reader.bit_reader.fields.view_bit_offset.bit_offset =
                bit_offset;
            context->fields.view_bit_reader.bit_reader.fields.view_words.words = words;
            horizontal_result =
                fn_12_9594(&context->fields.view_bit_reader.bit_reader,
                           &context->fields.view_backward_motion.backward_motion,
                           &context->fields.view_backward_motion.backward_motion.fields
                                .view_horizontal.horizontal,
                           &context->fields.view_backward_motion.backward_motion.fields
                                .view_previous_horizontal.previous_horizontal);
            vertical_result = fn_12_9594(
                &context->fields.view_bit_reader.bit_reader,
                &context->fields.view_backward_motion.backward_motion,
                &context->fields.view_backward_motion.backward_motion.fields.view_vertical.vertical,
                &context->fields.view_backward_motion.backward_motion.fields.view_previous_vertical
                     .previous_vertical);
            bits = context->fields.view_bit_reader.bit_reader.fields.view_bits.bits;
            next_bits = context->fields.view_bit_reader.bit_reader.fields.view_next_bits.next_bits;
            bit_offset =
                context->fields.view_bit_reader.bit_reader.fields.view_bit_offset.bit_offset;
            words = context->fields.view_bit_reader.bit_reader.fields.view_words.words;
            if ((horizontal_result | vertical_result) != 0) {
                break;
            }
        }
        if ((context->fields.view_field_344.field_344 & 2) != 0) {
            s16 descriptor;
            u8 code_length;
            peek = bits >> 23;
            if (bit_offset > 23) {
                peek |= next_bits >> (55 - bit_offset);
            }
            descriptor = lbl_12_bss_691C[peek];
            context->fields.view_cbp_mask.cbp_mask = ((u32)(u16)descriptor << 16) & 0xFFF00000;
            bit_offset += ((0xff) & (descriptor));
            if (bit_offset >= 32) {
                bit_offset -= 32;
                bits = next_bits << bit_offset;
                next_bits = *words++;
            } else {
                bits <<= ((0xff) & (descriptor));
            }
        } else {
            context->fields.view_cbp_mask.cbp_mask = 0;
        }
        context->fields.view_bit_reader.bit_reader.fields.view_bits.bits = bits;
        context->fields.view_bit_reader.bit_reader.fields.view_next_bits.next_bits = next_bits;
        context->fields.view_bit_reader.bit_reader.fields.view_bit_offset.bit_offset = bit_offset;
        context->fields.view_bit_reader.bit_reader.fields.view_words.words = words;
        if ((context->fields.view_field_344.field_344 & 1) != 0) {
            context->fields.view_decode_intra_blocks.decode_intra_blocks(context);
            context->fields.view_motion_intra.motion_intra(context);
            context->fields.view_forward_motion.forward_motion.fields.view_previous_horizontal
                .previous_horizontal = 0;
            context->fields.view_forward_motion.forward_motion.fields.view_previous_vertical
                .previous_vertical = 0;
            context->fields.view_forward_motion.forward_motion.fields.view_horizontal.horizontal =
                0;
            context->fields.view_forward_motion.forward_motion.fields.view_vertical.vertical = 0;
            context->fields.view_backward_motion.backward_motion.fields.view_previous_horizontal
                .previous_horizontal = 0;
            context->fields.view_backward_motion.backward_motion.fields.view_previous_vertical
                .previous_vertical = 0;
            context->fields.view_backward_motion.backward_motion.fields.view_horizontal.horizontal =
                0;
            context->fields.view_backward_motion.backward_motion.fields.view_vertical.vertical = 0;
        } else {
            void (**motion_modes)(MPVContext *) =
                &context->fields.view_motion_skipped.motion_skipped;
            context->fields.view_motion_skipped.motion_skipped =
                motion_modes[(context->fields.view_field_344.field_344 & 0xC) >> 2];
            if (context->fields.view_cbp_mask.cbp_mask != 0) {
                context->fields.view_decode_nonintra_blocks.decode_nonintra_blocks(context);
            }
            context->fields.view_motion_skipped.motion_skipped(context);
            context->fields.view_dc_predictor_y.dc_predictor_y = 0x400;
            context->fields.view_dc_predictor_cr.dc_predictor_cr = 0x400;
            context->fields.view_dc_predictor_cb.dc_predictor_cb = 0x400;
        }
        if (--context->fields.view_field_1324.field_1324 <= 0) {
            context->fields.view_field_1324.field_1324 =
                context->fields.view_condition_state.condition_state.fields.view_decoder.decoder
                    .fields.view_field_1AC.field_1AC;
            context->fields.view_condition_state.condition_state.fields.view_decoder.decoder.fields
                .view_callback.callback(
                    context->fields.view_condition_state.condition_state.fields.view_decoder.decoder
                        .fields.view_callback_argument.callback_argument);
        }
        bits = context->fields.view_bit_reader.bit_reader.fields.view_bits.bits;
        next_bits = context->fields.view_bit_reader.bit_reader.fields.view_next_bits.next_bits;
        bit_offset = context->fields.view_bit_reader.bit_reader.fields.view_bit_offset.bit_offset;
        words = context->fields.view_bit_reader.bit_reader.fields.view_words.words;
        residual_offset = ((7) & (bit_offset));
        consumed = ((const u8 *)(words - 2) + ((bit_offset - residual_offset + 7) >> 3)) -
                   (const u8 *)context->fields.view_header_chunk.header_chunk.fields.view_data.data;
        if (context->fields.view_header_chunk.header_chunk.fields.view_len.len - consumed <=
            0x800) {
            fn_800589BC(&context->fields.view_header_chunk.header_chunk, consumed,
                        &context->fields.view_header_chunk.header_chunk, &refill_remainder);
            stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(
                stream, 0, &context->fields.view_header_chunk.header_chunk);
            stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(
                stream, 1, &refill_remainder);
            stream->fields.view_interface.interface->fields.view_get_chunk.get_chunk(
                stream, 1, 0x7FFFFFFF, &context->fields.view_header_chunk.header_chunk);
            mpvdec_InitMacroblockReader(
                context->fields.view_header_chunk.header_chunk.fields.view_data.data,
                residual_offset, &words, &bits, &next_bits, &bit_offset);
        }
        first_macroblock = 0;
    }
    context->fields.view_field_12d0.field_12d0 = ((7) & (bit_offset));
    consumed = ((const u8 *)(words - 2) +
                ((bit_offset - context->fields.view_field_12d0.field_12d0 + 7) >> 3)) -
               (const u8 *)context->fields.view_header_chunk.header_chunk.fields.view_data.data;
    fn_800589BC(&context->fields.view_header_chunk.header_chunk, consumed,
                &context->fields.view_header_chunk.header_chunk, &final_remainder);
    stream->fields.view_interface.interface->fields.view_put_chunk.put_chunk(
        stream, 0, &context->fields.view_header_chunk.header_chunk);
    stream->fields.view_interface.interface->fields.view_unget_chunk.unget_chunk(stream, 1,
                                                                                 &final_remainder);
    MPV_GoNextDelimSj(stream);
}
#pragma opt_common_subs reset
/* fzgx:end fn_12_8F80 */

/* fzgx:begin fn_12_9594 */
/* --- rel/movie_module/fn_12_9594.c --- */



#pragma opt_lifetimes off
s32 fn_12_9594(MovieBits *state, MovieCode *code, s32 *out, s32 *base) {
    u32 bits;
    s32 count;
    u32 word;
    u32 *ptr;
    s32 ret;
    s32 value;
    s32 index;
    s32 shift;
    s32 nb;
    ret = 0;
    bits = state->field_0;
    count = state->field_8;
    word = state->field_4;
    ptr = (state->field_c);
    nb = code->field_4;
{
    s32 sg;
    sg = code->field_8;
    index = bits >> 21;
    if (count > 21)
        index |= word >> (53 - count);

    if (((u32)index >> 7) == 0)
        value = *(s16 *)(*(u32 *)&lbl_12_bss_6924 + ((u32)index << 1));
    else
        value = *(s16 *)(*(u32 *)&lbl_12_bss_6920 + (((u32)index >> 6) << 1));

{
    s32 token;
    token = (s8)value;
    index = token;
    if (token == 0x7f) {
        ret = -1;
    } else {
        shift = (u16)value >> 8;
        count += shift;
        if (count >= 0x20) {
            count -= 0x20;
            bits = word << count;
            word = *ptr++;
        } else {
            bits <<= shift;
        }
        if (index == 0) {
            *out = *base;
        } else {
            if (nb != 0) {
                if (count >= 0x20 - nb) {
                    count -= 0x20 - nb;
                    if (count != 0) {
                        bits |= word >> (nb - count);
                        value = bits >> (0x20 - nb);
                        bits = word << count;
                    } else {
                        value = bits >> (0x20 - nb);
                        bits = word;
                    }
                    shift = *ptr++;
                    word = shift;
                } else {
                    value = bits >> (0x20 - nb);
                    count += nb;
                    bits <<= nb;
                }
                token = code->field_c - 1 - value;
                index <<= nb;
                if (index > 0)
                    index -= token;
                else
                    index += token;
            }
            index += *base;
            *out = (index << sg) >> sg;
            *base = *out;
        }
        if (code->field_0 != 0)
            *out <<= 1;
    }
}
    }
    state->field_0 = bits;
    state->field_4 = word;
    state->field_8 = count;
    state->field_c = ptr;
    return ret;
}
/* fzgx:end fn_12_9594 */

/* fzgx:begin fn_12_9730 */
#pragma opt_lifetimes reset

/* --- rel/movie_module/fn_12_9730.c --- */
/* --- rel/movie_module/fn_12_9730.c --- */
typedef struct MovieModule {
    u8 _pad0[0x318];
    u32 field_318;
    u32 field_31c;
    u32 field_320;
} MovieModule;

void fn_12_9730(MovieModule *module) {
    module->field_318 = 0x400;
    module->field_320 = 0x400;
    module->field_31c = 0x400;
}
/* fzgx:end fn_12_9730 */

/* fzgx:begin fn_12_9744 */
/* --- rel/movie_module/fn_12_9744.c --- */
typedef struct MovieState {
    u8 _pad10[0x10];
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1c;
} MovieState;

void fn_12_9744(MovieState *movie) {
    movie->field_10 = 0;
    movie->field_14 = 0;
    movie->field_18 = 0;
    movie->field_1c = 0;
}
/* fzgx:end fn_12_9744 */

/* fzgx:begin fn_12_975C noprologue */
#include "types.h"
#include "sofdec/sj.h"
typedef struct Sig_fn_12_9594_MPVBitReader {
 u32 bits; u32 next_bits; s32 bit_offset; const u32 *words;
} Sig_fn_12_9594_MPVBitReader;
typedef struct Sig_fn_12_9594_MPVMotionInfo {
 u8 padding[12]; s32 previous_horizontal, previous_vertical, horizontal, vertical; u32 extent;
} Sig_fn_12_9594_MPVMotionInfo;
struct Sig_fn_800589BC_fn_800589BC_Arg2 { u8 lab_pad[8]; u32 unk_0, unk_4; };
struct Sig_fn_800589BC_fn_800589BC_Arg3 { u32 unk_0, unk_4; };
struct fn_12_975C_Arg1 { u32 unk_0; };
extern u32 lbl_12_bss_693C, lbl_12_bss_6938, lbl_12_bss_692C, lbl_12_bss_691C;
extern int fn_12_9594(Sig_fn_12_9594_MPVBitReader *, Sig_fn_12_9594_MPVMotionInfo *, s32 *, s32 *);
extern u32 fn_800589BC(u32, u32, struct Sig_fn_800589BC_fn_800589BC_Arg2 *, struct Sig_fn_800589BC_fn_800589BC_Arg3 *);
extern int MPV_GoNextDelimSj(SJ *);
typedef u32 (*fn_12_975C_Fn0)(struct fn_12_975C_Arg1 *,u32,u32,u32);
typedef u32 (*fn_12_975C_Fn1)(u32);
typedef u32 (*fn_12_975C_Fn7)(struct fn_12_975C_Arg1 *,u32,u32);
typedef u32 (*fn_12_975C_Fn8)(struct fn_12_975C_Arg1 *,u32,void *);
#define W(o) (*(u32 *)((u8 *)arg0+(o)))
#define S(o) (*(s32 *)((u8 *)arg0+(o)))
#define CALL(o) (((fn_12_975C_Fn1)W(o))(arg0))
#define SJGET() (((fn_12_975C_Fn0)*(u32 *)(arg1->unk_0+24))(arg1,1,0x7fffffff,arg0+4808))
#define SJPUT() (((fn_12_975C_Fn7)*(u32 *)(arg1->unk_0+32))(arg1,0,arg0+4808))
#define SJRET(p) (((fn_12_975C_Fn8)*(u32 *)(arg1->unk_0+28))(arg1,1,p))
#define ADV(n) { v11 += (n); if(v11>=32) { v11-=32; v12=v13<<v11; v13=*(u32 *)v14; v14+=4; } else v12<<=(n); }
#pragma opt_propagation off
#pragma opt_lifetimes off
static inline u32 fn_12_975C_call_fn_800589BC(s32 a0, u32 a1, struct Sig_fn_800589BC_fn_800589BC_Arg2 *a2, struct Sig_fn_800589BC_fn_800589BC_Arg3 *a3) { return fn_800589BC(a0,a1,a2,a3); }
void fn_12_975C(u32 arg0, struct fn_12_975C_Arg1 *arg1) {
 s32 v11;
 u32 v12;
 u32 v13;
 u32 v35_2;
 u32 v14;
 s32 v15=1;
 u32 lab_t0, v0, v2, v10, v16, v18, v19, v22, v23, v25, v28, v32, v34, v35, v40;
 s32 v20;
 u32 v21;
 s32 v24, v33;
 int t3;
 struct Sig_fn_800589BC_fn_800589BC_Arg3 loc_10;
 struct Sig_fn_800589BC_fn_800589BC_Arg3 loc_8;
 SJGET();
 {
 u32 v1;
 v0=W(4808); v1=W(4816); v14=v0&~3;
 v12=*(u32 *)v14; v11=(v0-v14)<<3; v13=*(u32 *)(v14+4);
 v12<<=v11; v14+=8; v11+=v1;
 if(v11>=32) {v11-=32; v12=v13<<v11; v13=*(u32 *)v14; v14+=4;}
 else v12<<=v1;
 }
 for(;;) {
 v10=v12>>9; if(v11>9) v10|=v13>>(41-v11);
 if(!v10) break;
 v21=W(776);
 for(;;) {
 v16=v12>>21; if(v11>21) v16|=v13>>(53-v11);
 if((v16>>7)==0) v18=*(s16 *)(lbl_12_bss_693C+(v16<<1));
 else v18=*(s16 *)(lbl_12_bss_6938+((v16>>5)&0x7fffffe));
 v19=v18&15; ADV(v19);
 v20=(s32)((v18>>2)&255)>>2;
 if(v20==34) continue;
 if(v20==35) { W(776)+=33; continue; }
 break;
 }
 if(v20==36) v22=-2;
 else {
 W(776)=W(776)+v20;
 W(784)=v18>>10;
 v22=W(776);
 if((s32)v22>S(780)) v22=-2; else v22-=v21;
 }
 if(v22==0xfffffffe) break;
 if(v15==0 && v22>1) {
 CALL(664); W(720)=0; W(724)=0; W(728)=0; W(732)=0;
 W(792)=1024; W(800)=1024; W(796)=1024;
 }
 if(!(W(784)&32)) {
 v23=v12>>27; if(v11>27) v23|=v13>>(59-v11);
 v24=*(s16 *)(lbl_12_bss_692C+(v23<<1));
 v25=v24&255; v24=(u32)v24>>8; v11+=v25; W(784)=v24;
 if(v11>=32) {v11-=32; v12=v13<<v11; v13=*(u32 *)v14; v14+=4;}
 else v12<<=v25;
 }
 if(W(784)&16) {
 if(v11>=27) {
 v11-=27;
 if(v11!=0) {v12|=v13>>(5-v11); v28=v12>>27; v12=v13<<v11;}
 else {v28=v12>>27; v12=v13;}
 v13=*(u32 *)v14; v14+=4;
 } else {v28=v12>>27; v12<<=5; v11+=5; }
 W(700)=v28;
 }
 if(W(784)&8) {
 W(0)=v12; W(4)=v13; W(8)=v11; W(12)=v14;
 v15=fn_12_9594((Sig_fn_12_9594_MPVBitReader *)arg0,(Sig_fn_12_9594_MPVMotionInfo *)(arg0+704),(s32 *)(arg0+728),(s32 *)(arg0+720));
 t3=fn_12_9594((Sig_fn_12_9594_MPVBitReader *)arg0,(Sig_fn_12_9594_MPVMotionInfo *)(arg0+704),(s32 *)(arg0+732),(s32 *)(arg0+724));
 v12=W(0); v13=W(4); v11=W(8); v14=W(12);
 if(v15|t3) break;
 } else {W(720)=0;W(724)=0;W(728)=0;W(732)=0;}
 if(W(784)&2) {
 v32=v12>>23; if(v11>23) v32|=v13>>(55-v11);
 v33=*(s16 *)(lbl_12_bss_691C+(v32<<1));
 v34=v33&255; v33=(u32)v33<<16; v33&=0xfff00000; v11+=v34; W(788)=v33;
 if(v11>=32) {v11-=32;v12=v13<<v11;v13=*(u32 *)v14;v14+=4;}
 else v12<<=v34;
 } else W(788)=0;
 W(0)=v12;W(4)=v13;W(8)=v11;W(12)=v14;
 if(W(784)&1) {CALL(668);CALL(676);}
 else {if(S(788)!=0) CALL(672);CALL(688);W(792)=1024;W(800)=1024;W(796)=1024;}
 if(--S(4852)<=0) {W(4852)=W(428);((fn_12_975C_Fn1)W(432))(W(436));}
 v11=W(8);v14=W(12);v15=v11&7;
 v12=W(0);v13=W(4);
 {
 u32 end;
 end=v14+((v11-v15+7)>>3);
 v2=W(4808);
 end-=8;
 v2=end-v2;
 }
 if((s32)((W(4812))-v2)<=2048) {
 v40=arg0+4808;
 lab_t0=v40;
 fn_12_975C_call_fn_800589BC(lab_t0,v2,(struct Sig_fn_800589BC_fn_800589BC_Arg2 *)v40,&loc_10);
 SJPUT();SJRET(&loc_10);SJGET();
 v0=W(4808);v14=v0&~3;
 v12=*(u32 *)v14;v11=(v0-v14)<<3;v13=*(u32 *)(v14+4);
 v12<<=v11;v14+=8;v11+=v15;
 if(v11>=32) {v11-=32;v12=v13<<v11;v13=*(u32 *)v14;v14+=4;}
 else v12<<=v15;
 }
 v15=0;
 }
 W(4816)=v11&7;v40=arg0+4808;
 lab_t0=v40;
 v0=W(4816);
 {
 u32 v21_2;
 v21_2=W(4808);
 v35=v11-v0;
 v0=(s32)(v35+7)>>3;
 v35=v14+v0;
 v0=v35-8;
 v35_2=v0-v21_2;
 }
 fn_800589BC(lab_t0,v35_2,(struct Sig_fn_800589BC_fn_800589BC_Arg2 *)v40,&loc_8);
 SJPUT();SJRET(&loc_8);MPV_GoNextDelimSj((SJ *)arg1);
}
#pragma opt_lifetimes reset
#pragma opt_propagation reset
/* fzgx:end fn_12_975C */

/* fzgx:begin fn_12_9D08 */
typedef void (*fn1_t)(void *);
typedef void (*fn0_t)(u32);

struct fn_12_9D08_ctx {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_c;
    u32 pad1[103];
    u32 unk_1ac;
    fn0_t unk_1b0;
    u32 unk_1b4;
    u32 pad2[57];
    fn1_t unk_29c;
    u32 pad3;
    fn1_t unk_2a4;
    u32 pad4[5];
    u32 unk_2bc;
    u32 pad5[18];
    s32 unk_308;
    s32 unk_30c;
    s32 unk_310;
    u32 pad6[1005];
    /* The buffered input chunk and bit offset within its first byte. */
    SJCK chunk;
    s32 unk_12d0;
    u32 pad7[8];
    s32 unk_12f4;
};


#pragma opt_propagation off
void fn_12_9D08(struct fn_12_9D08_ctx *arg0, SJ *arg1) {
    SJCK localA;
    SJCK localB;
    s32 sh8;
    u32 w0;
    u32 w1;
    s32 sh;
    u32 *ptr;
    u32 v_2;
    u32 v;
    u32 code;
    u32 t;
    s32 len;
    u8 run_code;
    s32 old;
    s32 n;
    u32 lab_t1;

    arg1->interface->get_chunk(arg1, 1, 0x7FFFFFFF, &arg0->chunk);

    ptr = (u32 *)((u32)arg0->chunk.data & ~3);
    sh = ((u32)arg0->chunk.data - (u32)ptr) * 8;
    w0 = ptr[0] << sh;
    w1 = ptr[1];
    ptr += 2;
    sh += arg0->unk_12d0;
    if (sh >= 32) {
        sh -= 32;
        w0 = w1 << sh;
        w1 = ptr[0];
        ptr++;
    } else {
        w0 <<= arg0->unk_12d0;
    }

    for (;;) {
        v = w0 >> 9;
        if (sh > 9) {
            v |= w1 >> (41 - sh);
        }
        if (v == 0) {
            break;
        }
        old = arg0->unk_308;
        /* Stuffing and escape codes retry without testing the start delimiter. */
        for (;;) {
            code = w0 >> 20;
            if (sh > 20) {
                code |= w1 >> (52 - sh);
            }
            if ((code >> 8) == 0) {
                t = lbl_12_bss_6944[code];
            } else {
                t = lbl_12_bss_6940[code >> 6];
            }
            v_2 = t & 0xF;
            sh += v_2;
            if (sh >= 32) {
                sh -= 32;
                w0 = w1 << sh;
                w1 = ptr[0];
                ptr++;
            } else {
                w0 <<= v_2;
            }
            run_code = (t >> 2) & 0xFF;
            len = run_code >> 2;
            if (len == 0x22) {
                continue;
            }
            if (len == 0x23) {
                arg0->unk_308 += 0x21;
                continue;
            }
            break;
        }
        if (len == 0x24) {
            v_2 = -2;
        } else {
            arg0->unk_308 += len;
            arg0->unk_310 = t >> 10;
            if (arg0->unk_308 > arg0->unk_30c) {
                v_2 = -2;
            } else {
                v_2 = arg0->unk_308 - old;
            }
        }
        v_2 = v_2 + 0x10000;
        if ((u32)v_2 == 0xFFFE) {
            break;
        }
        if (arg0->unk_310 & 0x10) {
            if (sh >= 27) {
                sh -= 27;
                if (sh != 0) {
                    w0 |= w1 >> (5 - sh);
                    v_2 = w0 >> 27;
                    w0 = w1 << sh;
                } else {
                    v_2 = w0 >> 27;
                    w0 = w1;
                }
                w1 = ptr[0];
                ptr++;
            } else {
                v_2 = w0 >> 27;
                w0 <<= 5;
                sh += 5;
            }
            arg0->unk_2bc = v_2;
        }
        arg0->unk_0 = w0;
        arg0->unk_4 = w1;
        arg0->unk_8 = sh;
        arg0->unk_c = (u32)ptr;
        arg0->unk_29c(arg0);
        arg0->unk_2a4(arg0);
        if (--arg0->unk_12f4 <= 0) {
            arg0->unk_12f4 = arg0->unk_1ac;
            arg0->unk_1b0(arg0->unk_1b4);
        }
        w0 = arg0->unk_0;
        w1 = arg0->unk_4;
        sh = arg0->unk_8;
        ptr = (u32 *)arg0->unk_c;
        sh8 = sh & 7;
        n = (u32)ptr;
        n += ((sh - sh8 + 7) >> 3);
        n -= 8;
        n -= (u32)arg0->chunk.data;
        /* Split off the consumed prefix when fewer than 2 KiB remain. */
        if (arg0->chunk.len - n > 0x800) {
            continue;
        }
        fn_800589BC(&arg0->chunk, n, &arg0->chunk, &localA);
        arg1->interface->put_chunk(arg1, 0, &arg0->chunk);
        arg1->interface->unget_chunk(arg1, 1, &localA);
        arg1->interface->get_chunk(arg1, 1, 0x7FFFFFFF, &arg0->chunk);
        ptr = (u32 *)((u32)arg0->chunk.data & ~3);
        sh = ((u32)arg0->chunk.data - (u32)ptr) * 8;
        w0 = ptr[0] << sh;
        w1 = ptr[1];
        ptr += 2;
        sh += sh8;
        if (sh >= 32) {
            sh -= 32;
            w0 = w1 << sh;
            w1 = ptr[0];
            ptr++;
        } else {
            w0 <<= sh8;
        }
    }

    arg0->unk_12d0 = sh & 7;
    ptr = (u32 *)((u8 *)ptr + ((sh - arg0->unk_12d0 + 7) >> 3));
    ptr = (u32 *)((u8 *)ptr - 8);
    lab_t1 = (u32)arg0->chunk.data;
    fn_800589BC(&arg0->chunk, ((u32)ptr - lab_t1), &arg0->chunk, &localB);
    arg1->interface->put_chunk(arg1, 0, &arg0->chunk);
    arg1->interface->unget_chunk(arg1, 1, &localB);
    MPV_GoNextDelimSj( (SJ *)((fn_12_8F80_SJ *)(SJ *)(arg1)));
}
#pragma opt_propagation reset
/* fzgx:end fn_12_9D08 */
