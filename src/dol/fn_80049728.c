
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

s32 fn_80049728(AdxSjeHandle *encoder);

void *memcpy(void *destination, const void *source, unsigned long size);

static inline void adxsje_put(SJ *output, void *data, s32 size) {
    SJCK chunk;
    output->interface->get_chunk(output, 0, size, &chunk);
    if (chunk.len < size) {
        output->interface->unget_chunk(output, 0, &chunk);
    } else {
        memcpy(chunk.data, data, size);
        output->interface->put_chunk(output, 1, &chunk);
    }
}

static inline void adxsje_put16(SJ *output, void *data) {
    SJCK chunk;
    output->interface->get_chunk(output, 0, 2, &chunk);
    if (chunk.len < 2) {
        output->interface->unget_chunk(output, 0, &chunk);
    } else {
        s16 *cursor = (s16 *)chunk.data;
        *cursor++ = *(s16 *)data;
        output->interface->put_chunk(output, 1, &chunk);
    }
}

s32 fn_80049728(AdxSjeHandle *encoder) {
    s32 end_size;
    s32 output_size;
    SJ *output;
    s32 output_length;
    s32 index;
    u16 value;
    u8 zero;
    output = encoder->output;
    output_length = encoder->output_length;
    if (encoder->loop_count <= 0) {
        output_size = encoder->block_size;
    } else {
        output_size =
            ((output_length + encoder->block_size + 0x7FF) / 0x800) * 0x800 - output_length;
    }
    end_size = output_size - 4;
    if (output->interface->get_num_data(output, 0) < output_size) {
        return 0;
    }
    value = 0x8001;
    adxsje_put16(output, &value);
    value = end_size;
    adxsje_put16(output, &value);
    zero = 0;
    for (index = 0; index < end_size; index++) {
        adxsje_put(output, &zero, 1);
    }
    return output_size;
}
