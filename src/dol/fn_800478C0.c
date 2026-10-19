
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

void fn_800478C0(AdxSjeHandle *encoder);

void fn_80046D94(int cutoff, int sample_rate, short *coefficient0, short *coefficient1);

void fn_80047A50(AdxSjeHandle *encoder);

s32 fn_80048340(AdxSjeHandle *encoder, SJ *output);

static inline void adxsje_prdflt_set_coef(struct AdxSjePredictorFilter *filter, s16 coefficient0,
                                          s16 coefficient1) {
    filter->coefficient0 = coefficient0;
    filter->coefficient1 = coefficient1;
}

static inline void adxsje_iirflt_set_coef(struct AdxSjeIirFilter *filter, s16 coefficient0,
                                          s16 coefficient1) {
    filter->coefficient0 = coefficient0;
    filter->coefficient1 = coefficient1;
}

static inline void adxsje_initialize_filter_coefficients(AdxSjeHandle *encoder,
                                                         struct AdxSjePredictorFilter *filter) {
    s16 coefficient0;
    s16 coefficient1;
    fn_80046D94((s16)encoder->cutoff_frequency, encoder->sample_rate, &coefficient0, &coefficient1);
    adxsje_prdflt_set_coef(filter, coefficient0, coefficient1);
    adxsje_iirflt_set_coef(filter->iir_filter, coefficient0, coefficient1);
}

static inline void adxsje_header_exec(AdxSjeHandle *encoder) {
    SJ *output;
    s32 channel;
    s32 header_size;
    SJCK chunk;
    s16 sample;
    output = encoder->output;
    for (channel = 0; channel < encoder->channel_count; channel++) {
        encoder->input[channel]->interface->get_chunk(encoder->input[channel], 1, 2, &chunk);
        if (chunk.len == 0) {
            break;
        }
        sample = *(s16 *)chunk.data;
        encoder->initial_previous1[channel] = sample;
        encoder->initial_previous0[channel] = sample;
        encoder->input[channel]->interface->unget_chunk(encoder->input[channel], 1, &chunk);
    }
    if (channel < encoder->channel_count) {
        return;
    }
    for (channel = 0; channel < encoder->channel_count; channel++) {
        encoder->previous0[channel] = encoder->initial_previous0[channel];
        encoder->previous1[channel] = encoder->initial_previous1[channel];
    }
    header_size = fn_80048340(encoder, output);
    if (header_size == 0) {
        return;
    }
    encoder->output_length += header_size;
    for (channel = 0; channel < encoder->channel_count; channel++) {
        adxsje_initialize_filter_coefficients(encoder, encoder->filter[channel]);
    }
    encoder->status = 2;
}

void fn_800478C0(AdxSjeHandle *encoder) {
    if (encoder->status == 1) {
        adxsje_header_exec(encoder);
    } else if (encoder->status == 2) {
        fn_80047A50(encoder);
    }
}
