#include "types.h"


/* --- dol/fn_80049BF4.c --- */
typedef struct fn_80049BF4_Vtbl {
    u8 pad_0[0x18];
    void (*unk18)(void *, s32, s32, void *);
    void (*unk1C)(void *, s32, void *);
    void (*unk20)(void *, s32, void *);
} fn_80049BF4_Vtbl;

typedef struct fn_80049BF4_Obj {
    fn_80049BF4_Vtbl *vtbl;
} fn_80049BF4_Obj;

typedef struct fn_80049BF4_Buf {
    void *data;
    u32 size;
} fn_80049BF4_Buf;

struct fn_80049BF4_Arg0 {
    u8 pad_0[0xC];
    fn_80049BF4_Obj *unk_C;
};

extern void * memcpy(void *, const void *, u32);

u32 fn_80049BF4(struct fn_80049BF4_Arg0 *arg0) {
    u8 *p1 = (u8 *)arg0;
    u8 *p2 = (u8 *)arg0;
    s32 i = 0;
    u32 sum = 0;
    fn_80049BF4_Obj *v0 = arg0->unk_C;
    s16 v5;
    s16 d;
    s32 x;
    s16 v7;
    fn_80049BF4_Buf b1;
    fn_80049BF4_Buf b2;
    fn_80049BF4_Buf b3;
    u8 b8[4];

    while (i < (s32)*(u32 *)((u8 *)arg0 + 0x58)) {
        v5 = *(s16 *)((u8 *)arg0 + 0x2D0);
        d = *(s16 *)(p1 + 0x290) - 1;
        x = d ^ v5;
        *(s16 *)((u8 *)arg0 + 0x2D0) =
            (s16)(*(s16 *)((u8 *)arg0 + 0x2D4) + v5 * *(s16 *)((u8 *)arg0 + 0x2D2));
        *(s16 *)((u8 *)arg0 + 0x2D0) = *(s16 *)((u8 *)arg0 + 0x2D0) & 0x7FFF;
        if (*(s32 *)(p2 + 0x2A8) == 0 && *(s32 *)(p2 + 0x2AC) == 0 &&
            *(s32 *)(p2 + 0x2B0) == 0 && *(s32 *)(p2 + 0x2B4) == 0) {
            x = 0;
        }
        v7 = (s16)x;
        b8[0] = (s32)v7 >> 8;
        v0->vtbl->unk18(v0, 0, 1, &b1);
        if ((s32)b1.size < 1) {
            v0->vtbl->unk1C(v0, 0, &b1);
        } else {
            memcpy(b1.data, b8, 1);
            v0->vtbl->unk20(v0, 1, &b1);
        }
        b8[0] = v7;
        v0->vtbl->unk18(v0, 0, 1, &b2);
        if ((s32)b2.size < 1) {
            v0->vtbl->unk1C(v0, 0, &b2);
        } else {
            memcpy(b2.data, b8, 1);
            v0->vtbl->unk20(v0, 1, &b2);
        }
        v0->vtbl->unk18(v0, 0, 16, &b3);
        if ((s32)b3.size < 16) {
            v0->vtbl->unk1C(v0, 0, &b3);
        } else {
            memcpy(b3.data, p2 + 0x2A8, 16);
            v0->vtbl->unk20(v0, 1, &b3);
        }
        sum += 18;
        p1 += 2;
        p2 += 0x10;
        i++;
    }
    return sum;
}

/* --- dol/fn_80049E34.c --- */
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
