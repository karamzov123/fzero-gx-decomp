#include "types.h"

/* ADXSJE_Create, from the CC0 MK Deception decomp (adx_sje.c). GX's older SDK has
   no CINF fields, so the handle is 0x2F0 bytes. */

enum {
    ADXSJE_MAX_HANDLES = 8,
    ADXSJE_MAX_CHANNELS = 2,
    ADXSJE_MAX_FILTERS = 16,
    ADXSJE_MAX_BLOCK_SAMPLES = 32,
    ADXSJE_BLOCK_BYTES = 18
};

struct AdxSjeIirFilter {
    s8 used;
    u8 reserved_01[3];
    s16 coefficient0;
    s16 coefficient1;
    s16 previous0;
    s16 previous1;
};

struct AdxSjePredictorFilter {
    s8 used;
    u8 reserved_01[3];
    s16 coefficient0;
    s16 coefficient1;
    s16 previous0;
    s16 previous1;
    u8 reserved_0C[8];
    s32 sample_count;
    s16 residual[ADXSJE_MAX_BLOCK_SAMPLES];
    s8 code[ADXSJE_MAX_BLOCK_SAMPLES];
    s32 maximum;
    s16 scale;
    u8 reserved_7E[2];
    f64 gain;
    struct AdxSjeIirFilter* iir_filter;
};

typedef struct AdxSjeHandle {
    s8 used;
    s8 status;
    s8 input_count;
    s8 stopped;
    struct SJ* input[ADXSJE_MAX_CHANNELS];
    struct SJ* output;
    u8 reserved_10[0x18];
    s32 data_length;
    s32 output_length;
    s32 sample_position;
    s32 maximum_length;
    s32 field_38;
    s32 sample_count;
    s32 padded_sample_count;
    s32 block_samples;
    s32 header_length;
    s32 encoding_type;
    s32 block_size;
    s32 bits_per_sample;
    s32 channel_count;
    s32 sample_rate;
    s32 total_samples;
    s32 cutoff_frequency;
    s32 alignment_samples;
    s32 loop_count;
    s32 loop_start_sample;
    s32 loop_start_offset;
    s32 loop_end_sample;
    s32 loop_end_offset;
    struct AdxSjePredictorFilter* filter[ADXSJE_MAX_CHANNELS];
    s16 previous0[ADXSJE_MAX_CHANNELS];
    s16 previous1[ADXSJE_MAX_CHANNELS];
    s16 samples[ADXSJE_MAX_CHANNELS][ADXSJE_MAX_BLOCK_SAMPLES];
    s16 residual[ADXSJE_MAX_CHANNELS][ADXSJE_MAX_BLOCK_SAMPLES];
    s16 scaled[ADXSJE_MAX_CHANNELS][ADXSJE_MAX_BLOCK_SAMPLES];
    s16 reconstructed[ADXSJE_MAX_CHANNELS][ADXSJE_MAX_BLOCK_SAMPLES];
    s16 scale[ADXSJE_MAX_CHANNELS];
    u8 reserved_294[4];
    f64 gain[ADXSJE_MAX_CHANNELS];
    u8 encoded[ADXSJE_MAX_CHANNELS][16];
    s16 initial_previous0[ADXSJE_MAX_CHANNELS];
    s16 initial_previous1[ADXSJE_MAX_CHANNELS];
    s16 random_seed;
    s16 random_multiplier;
    s16 random_increment;
    s8 ainf_enabled;
    u8 ainf[16];
    u8 reserved_2E7;
    s16 ainf_front;
    s16 ainf_center;
    s16 ainf_surround;
    s8 cinf_enabled;
    u8 reserved_2EF;
} AdxSjeHandle;

typedef char AdxSjeHandleSizeCheck[sizeof(AdxSjeHandle) == 0x2F0 ? 1 : -1];

extern s32 fn_80046768(s32 a, s32 b, s32 c, s32 d);
extern void *memset(void *destination, int value, unsigned long size);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
char lbl_8017B5A8[16];
struct AdxSjePredictorFilter lbl_8017B5A8__fzgx_offset_10[ADXSJE_MAX_FILTERS];
struct AdxSjeIirFilter lbl_8017B5A8__fzgx_offset_910[ADXSJE_MAX_FILTERS];
AdxSjeHandle lbl_8017BF78[ADXSJE_MAX_HANDLES];

#define adxsje_prdflt_obj lbl_8017B5A8__fzgx_offset_10
#define adxsje_iirflt_obj lbl_8017B5A8__fzgx_offset_910
#define adxsje_obj lbl_8017BF78

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s; /* fzgx-allow: S2 BSS primer ordering */
    s = *(u8 *)&lbl_8017B5A8;
    s = *(u8 *)&lbl_8017B5A8__fzgx_offset_10;
    s = *(u8 *)&lbl_8017B5A8__fzgx_offset_910;
    s = *(u8 *)&lbl_8017BF78;
}
#pragma section code_type ".text"

static inline struct AdxSjeIirFilter* adxsje_alloc_iir(void)
{
    s32 index;
    struct AdxSjeIirFilter* filter;

    for (index = 0; index < ADXSJE_MAX_FILTERS; index++) {
        filter = &adxsje_iirflt_obj[index];
        if (filter->used == 0) {
            break;
        }
    }
    return index < ADXSJE_MAX_FILTERS ? filter : 0;
}

static inline struct AdxSjePredictorFilter* adxsje_create_filter(s32 sample_count)
{
    struct AdxSjePredictorFilter* filter;
    struct AdxSjeIirFilter* iir_filter;
    s32 index;

    iir_filter = adxsje_alloc_iir();
    if (iir_filter == 0) {
        return 0;
    }
    for (index = 0; index < ADXSJE_MAX_FILTERS; index++) {
        filter = &adxsje_prdflt_obj[index];
        if (filter->used == 0) {
            break;
        }
    }
    filter->sample_count = sample_count;
    filter->iir_filter = iir_filter;
    if (index < ADXSJE_MAX_FILTERS) {
        filter->used = 1;
    } else {
        filter = 0;
    }
    return filter;
}

AdxSjeHandle* fn_80047C94(s32 input_count, struct SJ** input, struct SJ* output)
{
    s32 index;
    AdxSjeHandle* encoder;

    for (index = 0; index < ADXSJE_MAX_HANDLES; index++) {
        if (adxsje_obj[index].used == 0) {
            break;
        }
    }
    if (index == ADXSJE_MAX_HANDLES) {
        return 0;
    }
    encoder = &adxsje_obj[index];
    encoder->input_count = input_count;
    for (index = 0; index < input_count; index++) {
        encoder->input[index] = input[index];
    }
    encoder->output = output;
    encoder->status = 0;
    encoder->data_length = 0;
    encoder->output_length = 0;
    encoder->sample_position = 0;
    encoder->maximum_length = 0x7FFF0000;
    encoder->header_length = fn_80046768(0, 0, 4, 4);
    encoder->encoding_type = 3;
    encoder->channel_count = input_count;
    encoder->sample_rate = 44100;
    encoder->bits_per_sample = 4;
    encoder->block_size = ADXSJE_BLOCK_BYTES;
    encoder->block_samples =
        ((encoder->block_size - 2) * 8) / encoder->bits_per_sample;
    encoder->total_samples = 0x7FFF0000;
    encoder->cutoff_frequency = 500;
    encoder->alignment_samples = 0;
    encoder->loop_count = 0;
    encoder->loop_start_sample = 0;
    encoder->loop_start_offset = 0;
    encoder->loop_end_sample = 0;
    encoder->loop_end_offset = 0;
    encoder->field_38 = 0;
    encoder->sample_count = 0;
    encoder->padded_sample_count = encoder->block_samples *
        (((encoder->total_samples - 1) / encoder->block_samples) + 1);
    encoder->filter[0] = adxsje_create_filter(encoder->block_samples);
    encoder->filter[1] = adxsje_create_filter(encoder->block_samples);
    encoder->initial_previous1[0] = 0;
    encoder->initial_previous0[0] = 0;
    encoder->initial_previous1[1] = 0;
    encoder->initial_previous0[1] = 0;
    encoder->ainf_enabled = 0;
    encoder->ainf_front = 0;
    encoder->ainf_center = -0x80;
    encoder->ainf_surround = -0x80;
    memset(encoder->ainf, 0, sizeof(encoder->ainf));
    encoder->used = 1;
    return encoder;
}
