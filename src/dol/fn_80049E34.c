
#include "types.h"

typedef struct SJCK {
    unsigned char *data;
    long len;
} SJCK;

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
    struct AdxSjeIirFilter *iir_filter;
};

typedef struct AdxSjeHandle {
    s8 used;
    s8 status;
    s8 input_count;
    s8 stopped;
    SJ *input[ADXSJE_MAX_CHANNELS];
    SJ *output;
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
    struct AdxSjePredictorFilter *filter[ADXSJE_MAX_CHANNELS];
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
    u8 *cinf;
    s32 cinf_length;
} AdxSjeHandle;

typedef char AdxSjeIirFilterSizeCheck[sizeof(struct AdxSjeIirFilter) == 0x0C ? 1 : -1];

typedef char AdxSjePredictorFilterSizeCheck[sizeof(struct AdxSjePredictorFilter) == 0x90 ? 1 : -1];

void fn_80049E34(AdxSjeHandle *encoder, s32 channel);

static inline s32 adxsje_clamp_s16_range(s32 value) {
    return (value < -0x8000 ? -0x8000 : value) > 0x7FFF ? 0x7FFF
                                                        : (value < -0x8000 ? -0x8000 : value);
}

static inline s32 adxsje_clamp_code(s32 value) {
    return (value < -8 ? -8 : value) < 7 ? (value < -8 ? -8 : value) : 7;
}

void fn_80049E34(AdxSjeHandle *encoder, s32 channel) {
    s32 index;
    s32 code;
    s32 bit_index;
    s32 samples_per_byte;
    s32 output_index;
    s32 scaled_value;
    s32 reconstructed_value;
    s16 sample;
    s32 clipped;
    struct AdxSjePredictorFilter *filter;
    s16 *residual;
    s16 *scaled;
    s16 *reconstructed;
    u8 *encoded;
    residual = encoder->residual[channel];
    scaled = encoder->scaled[channel];
    reconstructed = encoder->reconstructed[channel];
    encoded = encoder->encoded[channel];
    output_index = -1;
    samples_per_byte = 8 / encoder->bits_per_sample;
    filter = encoder->filter[channel];
    bit_index = 0;
    for (index = 0; index < encoder->block_samples; index++) {
        s32 code_shift;
        sample = filter == 0 ? 0 : filter->residual[index];
        residual[index] = sample;
        scaled_value = (s32)(filter->gain * residual[index]);
        clipped = adxsje_clamp_s16_range(scaled_value);
        scaled[index] = clipped;
        if (scaled[index] < 0) {
            code = (clipped - 0x924) / 4681;
        } else {
            code = (clipped + 0x924) / 4681;
        }
        code = adxsje_clamp_code(code);
        reconstructed_value = (s32)(filter->gain * (code * filter->scale));
        reconstructed[index] = adxsje_clamp_s16_range(reconstructed_value);
        if ((index % samples_per_byte) == 0) {
            bit_index = 1;
            encoded[++output_index] = 0;
        }
        code_shift = encoder->bits_per_sample;
        code_shift = 8 - code_shift;
        code = (u8)((u32)code << code_shift) >> code_shift;
        encoded[output_index] |=
            (s8)(code << (encoder->bits_per_sample * (samples_per_byte - bit_index)));
        bit_index++;
    }
}
