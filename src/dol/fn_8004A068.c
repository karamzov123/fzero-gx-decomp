#include "types.h"

/* adxsje_calc_rsig, from the CC0 MK Deception decomp (adx_sje.c). GX's older SDK has
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

extern s32 lbl_8012B8F8;

static inline s32 adxsje_clamp_s16_range(s32 value)
{
    return (value < -0x8000 ? -0x8000 : value) > 0x7FFF
               ? 0x7FFF
               : (value < -0x8000 ? -0x8000 : value);
}

static inline s16 adxsje_clamp_to_s16(s32 value)
{
    return adxsje_clamp_s16_range(value);
}

static inline s32 adxsje_clamp_code(s32 value)
{
    return (value < -8 ? -8 : value) < 7
               ? (value < -8 ? -8 : value)
               : 7;
}

static inline void adxsje_prdflt_set_hist(
    struct AdxSjePredictorFilter* filter, s16 previous0, s16 previous1)
{
    filter->previous0 = previous0;
    filter->previous1 = previous1;
}

static inline void adxsje_prdflt_exec(
    struct AdxSjePredictorFilter* filter, s16 sample, s32 index)
{
    s32 value;
    s16 residual;

    if (index == 0) {
        s32 clear_index;

        for (clear_index = 0; clear_index < filter->sample_count;
             clear_index++) {
            filter->residual[clear_index] = 0;
        }
        filter->maximum = 0;
    }
    if (filter != 0) {
        value = sample -
            ((filter->coefficient0 * filter->previous0) >> 12) -
            ((filter->coefficient1 * filter->previous1) >> 12);
        residual = adxsje_clamp_to_s16(value);
        filter->residual[index] = residual;
        if (__abs(residual) > filter->maximum) {
            filter->maximum = __abs(residual);
        }
        filter->previous1 = filter->previous0;
        filter->previous0 = sample;
    }
}

static inline void adxsje_iirflt_set_hist(
    struct AdxSjeIirFilter* filter, s16 previous0, s16 previous1)
{
    filter->previous0 = previous0;
    filter->previous1 = previous1;
}

static inline s16 adxsje_clamp_iir_s16(s32 value)
{
    return (s16)(((value > -0x8000 ? value : -0x8000) < 0x7FFF)
                     ? (value > -0x8000 ? value : -0x8000)
                     : 0x7FFF);
}

static inline void adxsje_iirflt_exec(struct AdxSjeIirFilter* filter, s32 sample)
{
    s32 value;
    s16 output_sample;

    if (filter == 0) {
        return;
    }
    value = sample +
        ((filter->coefficient0 * filter->previous0 +
          filter->coefficient1 * filter->previous1) >> 12);
    output_sample = adxsje_clamp_iir_s16(value);
    filter->previous1 = filter->previous0;
    filter->previous0 = output_sample;
}

s32 fn_8004A068(AdxSjeHandle* encoder, s32 channel)
{
    s16 sample;
    s16* samples;
    s32 index;
    s32 value;
    s32 code;
    s32 residual;
    s16 clipped;
    s16 initial_previous0;
    s16 initial_previous1;
    struct AdxSjePredictorFilter* filter;
    struct AdxSjeIirFilter* iir_filter;

    initial_previous0 = encoder->previous0[channel];
    initial_previous1 = encoder->previous1[channel];
    filter = encoder->filter[channel];
    iir_filter = filter->iir_filter;
    adxsje_prdflt_set_hist(
        filter, initial_previous0, initial_previous1);
    samples = encoder->samples[channel];
    for (index = 0; index < encoder->block_samples; index++) {
        sample = samples[index];
        adxsje_prdflt_exec(filter, sample, index);
    }

    value = ((filter->maximum - 1) / 7) + 1;
    value = (value < lbl_8012B8F8 ? value : lbl_8012B8F8) > 1
                ? (value < lbl_8012B8F8 ? value : lbl_8012B8F8)
                : 1;
    filter->scale = value;
    if (filter->maximum == 0) {
        filter->gain = 32767.0;
    } else {
        filter->gain = 32767.0 / filter->maximum;
    }

    adxsje_iirflt_set_hist(
        filter->iir_filter, encoder->previous0[channel], encoder->previous1[channel]);
    samples = encoder->samples[channel];
    for (index = 0; index < encoder->block_samples; samples++, index++) {
        sample = *samples;
        adxsje_prdflt_set_hist(
            filter, iir_filter->previous0, iir_filter->previous1);
        adxsje_prdflt_exec(filter, sample, index);

        residual = filter == 0 ? 0 : filter->residual[index];
        value = (s32)((s16)residual * filter->gain);
        clipped = adxsje_clamp_to_s16(value);
        if (clipped < 0) {
            code = (clipped - 0x924) / 4681;
        } else {
            code = (clipped + 0x924) / 4681;
        }
        code = adxsje_clamp_code(code);
        filter->code[index] = code;
        adxsje_iirflt_exec(filter->iir_filter,
                           adxsje_clamp_to_s16(code * filter->scale));
    }
    return 0;
}

