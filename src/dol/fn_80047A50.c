#include "types.h"


/* --- dol/fn_80047A50.c --- */
/* --- dol/fn_80047A50.c --- */
s32 fn_80049728(void *);                            /* extern */
s32 fn_80049958(void *);                            /* extern */

void fn_80047A50(void *arg0) {
    s32 temp_r3;

loop_1:
    if ((s8) (*(u8 *)((u8 *)(arg0) + 3)) == 0) {
loop_2:
        temp_r3 = fn_80049958((void *)(arg0));
        if (temp_r3 != 0) {
            (*(s32 *)((u8 *)(arg0) + 44)) = (s32) ((*(s32 *)((u8 *)(arg0) + 44)) + temp_r3);
            if ((s32) (*(s32 *)((u8 *)(arg0) + 48)) >= (s32) (*(s32 *)((u8 *)(arg0) + 60))) {
                (*(u8 *)((u8 *)(arg0) + 3)) = 1U;
                goto loop_1; /* Preserves the retail branch. */
            }
            goto loop_2; /* Preserves the retail branch. */
        }
    } else if (fn_80049728((void *)(arg0)) > 0) {
        (*(s8 *)((u8 *)(arg0) + 1)) = 3;
    }
}

/* --- dol/fn_80047ADC.c --- */
/* --- dol/fn_80047ADC.c --- */
struct fn_80047ADC_Arg0 {
    u8 pad_0[0x3C];
    u32 unk_3C;
    u8 pad_40[0x8];
    u32 unk_48;
    u8 pad_4C[0xC];
    u32 unk_58;
    u32 unk_5C;
    u32 unk_60;
};

void fn_80047ADC(struct fn_80047ADC_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    arg0->unk_58 = arg1;
    arg0->unk_5C = arg2;
    arg0->unk_3C = arg3;
    arg0->unk_60 = arg3;
    arg0->unk_48 = 284;
}

/* --- dol/fn_80047AF8.c --- */
struct fn_80047AF8_Arg0 {
    u8 pad_0[0x3];
    u8 unk_3;
};

void fn_80047AF8(struct fn_80047AF8_Arg0 *arg0) {
    arg0->unk_3 = 1;
}

/* --- dol/ADXSJE_Start.c --- */
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

enum {
    ADXSJE_MAX_HANDLES = 8,
    ADXSJE_MAX_CHANNELS = 2,
    ADXSJE_MAX_FILTERS = 16,
    ADXSJE_MAX_BLOCK_SAMPLES = 32,
    ADXSJE_BLOCK_BYTES = 18
};

typedef struct AdxSjeIirFilter {
    s8 used;
    u8 reserved_01[3];
    s16 coefficient0;
    s16 coefficient1;
    s16 previous0;
    s16 previous1;
} AdxSjeIirFilter;

typedef struct AdxSjePredictorFilter {
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
    AdxSjeIirFilter *iir_filter;
} AdxSjePredictorFilter;

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
    AdxSjePredictorFilter *filter[ADXSJE_MAX_CHANNELS];
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
    u8 ainf_enabled;
    u8 ainf[16];
    u8 reserved_2E7;
    s16 ainf_front;
    s16 ainf_center;
    s16 ainf_surround;
    u8 cinf_enabled;
    u8 reserved_2EF;
    u8 *cinf;
    s32 cinf_length;
} AdxSjeHandle;

void *memset(void *destination, int value, unsigned long size);

void ADXSJE_Start(AdxSjeHandle *encoder) {
    s32 channel;
    s32 byte_count;
    SJCK chunk;
    for (channel = 0; channel < encoder->channel_count; channel++) {
        byte_count = encoder->alignment_samples * 2;
        if (byte_count > 0) {
            encoder->input[channel]->interface->get_chunk(encoder->input[channel], 0, byte_count,
                                                          &chunk);
            if (chunk.len != byte_count) {
                encoder->input[channel]->interface->unget_chunk(encoder->input[channel], 0, &chunk);
                for (;;) {
                }
            }
            memset(chunk.data, 0, chunk.len);
            encoder->input[channel]->interface->put_chunk(encoder->input[channel], 1, &chunk);
        }
    }
    encoder->data_length = 0;
    encoder->output_length = 0;
    encoder->sample_position = 0;
    encoder->stopped = 0;
    encoder->status = 1;
}
