
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

s32 fn_80049958(AdxSjeHandle *encoder);

void *memcpy(void *destination, const void *source, unsigned long size);

void *memset(void *destination, int value, unsigned int size);

s32 fn_80049BF4(AdxSjeHandle *encoder);

void fn_80049E34(AdxSjeHandle *encoder, s32 channel);

s32 fn_8004A068(AdxSjeHandle *encoder, s32 channel);

static inline void adxsje_set_hist(AdxSjeHandle *encoder, s32 channel, s16 previous0,
                                   s16 previous1) {
    encoder->previous0[channel] = previous0;
    encoder->previous1[channel] = previous1;
}

static inline s32 adxsje_read_pcm(AdxSjeHandle *encoder, s16 **sample_buffer,
                                  s32 requested_samples) {
    SJ **inputs = encoder->input;
    s32 pcm_samples = 0;
    s32 channel;
    SJCK chunk;
    for (channel = 0; channel < encoder->channel_count; channel++) {
        pcm_samples = inputs[channel]->interface->get_num_data(inputs[channel], 1) / sizeof(s16);
        if (pcm_samples < requested_samples) {
            return 0;
        }
    }
    for (channel = 0; channel < encoder->channel_count; channel++) {
        pcm_samples = 0;
        while (pcm_samples < requested_samples) {
            inputs[channel]->interface->get_chunk(inputs[channel], 1, requested_samples * 2,
                                                  &chunk);
            memcpy(sample_buffer[channel] + pcm_samples, chunk.data, chunk.len);
            pcm_samples += (s16)(chunk.len / sizeof(s16));
            inputs[channel]->interface->put_chunk(inputs[channel], 0, &chunk);
        }
    }
    return pcm_samples;
}

static inline void adxsje_encode_blocks(AdxSjeHandle *encoder) {
    s32 channel;
    struct AdxSjePredictorFilter *filter;
    struct AdxSjeIirFilter *iir_filter;
    for (channel = 0; channel < encoder->channel_count; channel++) {
        fn_8004A068(encoder, channel);
        filter = encoder->filter[channel];
        iir_filter = filter->iir_filter;
        encoder->scale[channel] = filter->scale;
        encoder->gain[channel] = filter->gain;
        adxsje_set_hist(encoder, channel, iir_filter->previous0, iir_filter->previous1);
        fn_80049E34(encoder, channel);
    }
}

static inline void adxsje_pad_pcm(AdxSjeHandle *encoder, s16 **sample_buffer, s32 sample_total) {
    s32 channel;
    for (channel = 0; channel < encoder->channel_count; channel++) {
        if (sample_buffer[channel] != 0) {
            memset(sample_buffer[channel] + sample_total, 0,
                   (encoder->block_samples - sample_total) * 2);
        }
    }
}

s32 fn_80049958(AdxSjeHandle *encoder) {
    s32 total_size;
    SJ *output;
    s32 requested_samples;
    s32 pcm_samples;
    s32 encoded_samples;
    s16 *sample_buffer[ADXSJE_MAX_CHANNELS];
    output = encoder->output;
    total_size = 0;
    do {
        if ((output->interface->get_num_data(output, 0) / ADXSJE_BLOCK_BYTES) /
                encoder->channel_count <=
            0) {
            break;
        }
        sample_buffer[0] = encoder->samples[0];
        sample_buffer[1] = encoder->samples[1];
        requested_samples =
            (encoder->block_samples < encoder->sample_count - encoder->sample_position)
                ? encoder->block_samples
                : encoder->sample_count - encoder->sample_position;
        pcm_samples = adxsje_read_pcm(encoder, sample_buffer, requested_samples);
        if (pcm_samples == 0) {
            encoded_samples = 0;
        } else {
            if (requested_samples < encoder->block_samples) {
                adxsje_pad_pcm(encoder, sample_buffer, requested_samples);
            }
            encoder->sample_position += encoder->block_samples;
            adxsje_encode_blocks(encoder);
            encoded_samples = encoder->block_samples;
        }
        if (encoded_samples == 0) {
            break;
        }
        total_size += fn_80049BF4(encoder);
    } while (encoder->sample_position < encoder->sample_count);
    return total_size;
}
