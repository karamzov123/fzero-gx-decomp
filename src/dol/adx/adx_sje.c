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

extern void *memset(void *, int, unsigned long);
extern void *memcpy(void *, const void *, unsigned long);
static inline void *adxsje_memcpy16(void *d, const void *s, u16 n) { return memcpy(d, s, n); }
extern u32 fn_80046718(void);
extern u32 fn_80046738(void);
extern s32 fn_80046768(s32 a, s32 b, s32 c, s32 d);
struct fn_80048340_data;
struct fn_80048340_stream;
s32 fn_80048340(struct fn_80048340_data *, struct fn_80048340_stream *);
s32 fn_80049728(AdxSjeHandle *);
s32 fn_80049958(AdxSjeHandle *);
struct fn_80049BF4_Arg0;
u32 fn_80049BF4(struct fn_80049BF4_Arg0 *);
void fn_800478C0(AdxSjeHandle *encoder);
void fn_80047A50(void *);

/* file-scope objects of the retail TU, in retail order */
u32 lbl_8017B5A8[4];
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


void ADXSJE_ExecServer(void) {
    s32 index;
    for (index = 0; index < ADXSJE_MAX_HANDLES; index++) {
        if (lbl_8017BF78[index].used == 1) {
            fn_800478C0(&lbl_8017BF78[index]);
        }
    }
}

typedef char AdxSjeIirFilterSizeCheck[sizeof(struct AdxSjeIirFilter) == 0x0C ? 1 : -1];

typedef char AdxSjePredictorFilterSizeCheck[sizeof(struct AdxSjePredictorFilter) == 0x90 ? 1 : -1];


void fn_80046D94(int cutoff, int sample_rate, short *coefficient0, short *coefficient1);



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
    header_size = fn_80048340((struct fn_80048340_data *)encoder, (struct fn_80048340_stream *)output);
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

void fn_80047A50(void *arg0) {
    s32 temp_r3;

loop_1:
    if ((s8) (*(u8 *)((u8 *)(arg0) + 3)) == 0) {
loop_2:
        temp_r3 = fn_80049958((AdxSjeHandle *)(arg0));
        if (temp_r3 != 0) {
            (*(s32 *)((u8 *)(arg0) + 44)) = (s32) ((*(s32 *)((u8 *)(arg0) + 44)) + temp_r3);
            if ((s32) (*(s32 *)((u8 *)(arg0) + 48)) >= (s32) (*(s32 *)((u8 *)(arg0) + 60))) {
                (*(u8 *)((u8 *)(arg0) + 3)) = 1U;
                goto loop_1; /* Preserves the retail branch. */
            }
            goto loop_2; /* Preserves the retail branch. */
        }
    } else if (fn_80049728((AdxSjeHandle *)(arg0)) > 0) {
        (*(s8 *)((u8 *)(arg0) + 1)) = 3;
    }
}

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

struct fn_80047AF8_Arg0 {
    u8 pad_0[0x3];
    u8 unk_3;
};

void fn_80047AF8(struct fn_80047AF8_Arg0 *arg0) {
    arg0->unk_3 = 1;
}


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

u32 fn_80047C08(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t0, t1, t2, t3, t4;
    v0 = arg0;
    if (arg0 != 0) {
    t0 = fn_80046738();
    v0 = t0;
    v0 = *(u32 *)(arg0 + 128);
    v1 = arg1;
    v2 = arg2;
    if (v0 != 0) {
    if (v0 != 0) {
    v1 = 0;
    *(u8 *)((u8 *)v0 + 0) = 0;
    v2 = 144;
    t1 = (u32)memset((void *)v0, v1, v2);
    v0 = t1;
    }
    }
    v0 = *(u32 *)(arg0 + 132);
    if (v0 != 0) {
    if (v0 != 0) {
    v1 = 0;
    *(u8 *)((u8 *)v0 + 0) = 0;
    v2 = 144;
    t2 = (u32)memset((void *)v0, v1, v2);
    v0 = t2;
    }
    }
    v0 = arg0;
    v1 = 0;
    v2 = 4;
    t3 = (u32)memset((void *)v0, v1, v2);
    v0 = t3;
    t4 = fn_80046718();
    v0 = t4;
    }
    return v0;
}

/* ADXSJE_Create, from the CC0 MK Deception decomp (adx_sje.c). GX's older SDK has
   no CINF fields, so the handle is 0x2F0 bytes. */


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

void fn_800482B8(void) {
    u32 v0;
    v0 = lbl_8017B5A8[0];
    lbl_8017B5A8[0] = (v0 - 1);
    memset(lbl_8017BF78, 0, 6016);
}

void fn_800482FC(void) {
    u32 v0;
    v0 = lbl_8017B5A8[0];
    lbl_8017B5A8[0] = (v0 + 1);
    memset(lbl_8017BF78, 0, 6016);
}

struct fn_80048340_block {
    /* volatile: destination pointer must be re-read on each stream copy */
    void *volatile ptr; /* volatile: staged destination pointer survives the callbacks */
    u32 size;
};

struct fn_80048340_stream {
    u32 vtable;
};

struct fn_80048340_data {
    u8 pad_00[0x48];
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    u8 pad_80[0x248];
    s16 unk_2c8;
    s16 unk_2ca;
    s16 unk_2cc;
    s16 unk_2ce;
    s16 unk_2d0;
    u8 pad_2d2[0x4];
    s8 unk_2d6;
    u8 unk_2d7[0x10];
    s16 unk_2e8;
    s16 unk_2ea;
    s16 unk_2ec;
};

typedef u32 (*fn_80048340_FnA)(struct fn_80048340_stream *, u32, u32,
                               struct fn_80048340_block *);
typedef u32 (*fn_80048340_FnB)(struct fn_80048340_stream *, u32,
                               struct fn_80048340_block *);
typedef u32 (*fn_80048340_FnC)(struct fn_80048340_stream *, u32,
                               struct fn_80048340_block *);

extern u32 lbl_8012B8FC[];
extern size_t strlen(const char *);

static inline s32 fn_80048340_put8(struct fn_80048340_stream *arg1,
                                   const u8 *p) {
    struct fn_80048340_block blk;

    (*(fn_80048340_FnA *)(arg1->vtable + 24))(arg1, 0, 1, &blk);
    if ((s32)blk.size < 1) {
        (*(fn_80048340_FnB *)(arg1->vtable + 28))(arg1, 0, &blk);
        return 0;
    }
    memcpy(blk.ptr, p, 1);
    (*(fn_80048340_FnC *)(arg1->vtable + 32))(arg1, 1, &blk);
    return 1;
}

static inline s32 fn_80048340_put16(struct fn_80048340_stream *arg1,
                                    const void *p) {
    struct fn_80048340_block blk;
    s16 *dst;

    (*(fn_80048340_FnA *)(arg1->vtable + 24))(arg1, 0, 2, &blk);
    if ((s32)blk.size < 2) {
        (*(fn_80048340_FnB *)(arg1->vtable + 28))(arg1, 0, &blk);
        return 0;
    }
    dst = blk.ptr;
    *dst = *(const s16 *)p;
    (*(fn_80048340_FnC *)(arg1->vtable + 32))(arg1, 1, &blk);
    return 1;
}

static inline s32 fn_80048340_put16n(struct fn_80048340_stream *arg1,
                                     const u16 *p) {
    struct fn_80048340_block blk;
    s16 *dst;

    (*(fn_80048340_FnA *)(arg1->vtable + 24))(arg1, 0, 2, &blk);
    if ((s32)blk.size < 2) {
        (*(fn_80048340_FnB *)(arg1->vtable + 28))(arg1, 0, &blk);
        return 0;
    }
    dst = blk.ptr;
    *dst = *(const s16 *)p;
    (*(fn_80048340_FnC *)(arg1->vtable + 32))(arg1, 1, &blk);
    return 1;
}

static inline s32 fn_80048340_put32(struct fn_80048340_stream *arg1,
                                    const volatile s32 *p) { /* volatile: staged source slot */
    struct fn_80048340_block blk;
    s32 *dst;

    (*(fn_80048340_FnA *)(arg1->vtable + 24))(arg1, 0, 4, &blk);
    if ((s32)blk.size < 4) {
        (*(fn_80048340_FnB *)(arg1->vtable + 28))(arg1, 0, &blk);
        return 0;
    }
    dst = blk.ptr;
    *dst = *p;
    (*(fn_80048340_FnC *)(arg1->vtable + 32))(arg1, 1, &blk);
    return 1;
}

static inline s32 fn_80048340_putBytes(struct fn_80048340_stream *arg1,
                                       const void *src, u32 n) {
    struct fn_80048340_block blk;

    (*(fn_80048340_FnA *)(arg1->vtable + 24))(arg1, 0, n, &blk);
    if ((s32)blk.size < (s32)n) {
        (*(fn_80048340_FnB *)(28 + arg1->vtable))(arg1, 0, &blk);
        return 0;
    }
    adxsje_memcpy16(blk.ptr, src, n);
    (*(fn_80048340_FnC *)(arg1->vtable + 32))(arg1, 1, &blk);
    return n;
}

s32 fn_80048340(struct fn_80048340_data *arg0, struct fn_80048340_stream *arg1) {
    s32 len;
    s32 size;
    s32 count;
    s32 i;
    s32 pad;
    /* WARNING: compiler-diff device, not original code: the remaining volatile
     * block pointer, word-writer reads and word staging retain retail's stack
     * allocation and access ordering. Ordinary halfword staging and writer reads
     * match without qualifiers. Removing the block-pointer qualification still
     * leaves 48 aligned word errors; removing word staging/read qualification
     * leaves 279 (shared repair-engine measurements, not positional counts). */
    u8 b;
    u16 v1;
    u16 v;
    volatile s32 d; /* volatile: staged slot survives the stream callbacks */
    u16 vi;

    len = strlen((const char *)(lbl_8012B8FC)[0]);
{
    struct fn_80048340_block blk;
    (*(fn_80048340_FnA *)(arg1->vtable + 24))(arg1, 0, 0x7fffffff, &blk);
    size = blk.size;
    (*(fn_80048340_FnB *)(((28) + arg1->vtable)))(arg1, 0, &blk);
}
    if (size < arg0->unk_48 + 4) {
        return 0;
    }
    v1 = 0x8000;
    if (fn_80048340_put16(arg1, &v1) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    vi = arg0->unk_48;
    if (fn_80048340_put16(arg1, &vi) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    b = arg0->unk_4c;
    if (fn_80048340_put8(arg1, &b) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    b = arg0->unk_50;
    if (fn_80048340_put8(arg1, &b) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    b = arg0->unk_54;
    if (fn_80048340_put8(arg1, &b) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    b = arg0->unk_58;
    if (fn_80048340_put8(arg1, &b) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    d = arg0->unk_5c;
    if (fn_80048340_put32(arg1, &d) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    d = arg0->unk_60;
    if (fn_80048340_put32(arg1, &d) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    v = arg0->unk_64;
    if (fn_80048340_put16(arg1, &v) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    b = 4;
    if (fn_80048340_put8(arg1, &b) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    if (arg0->unk_2d0 == 0) {
        b = 0;
    } else {
        b = 8;
    }
    if (fn_80048340_put8(arg1, &b) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    d = 0;
    if (fn_80048340_put32(arg1, &d) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    v = arg0->unk_2c8;
    if (fn_80048340_put16(arg1, &v) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    v = arg0->unk_2cc;
    if (fn_80048340_put16(arg1, &v) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    v = arg0->unk_2ca;
    if (fn_80048340_put16(arg1, &v) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    v = arg0->unk_2ce;
    if (fn_80048340_put16(arg1, &v) != 1) {
        goto fail; /* error: single shared failure exit */
    }
    count = 0x1c;
    if (arg0->unk_6c > 0) {
        v = arg0->unk_68;
        if (fn_80048340_put16(arg1, &v) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        v = arg0->unk_6c;
        if (fn_80048340_put16(arg1, &v) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        i = 0;
        count = 0x20;
        while (i < arg0->unk_6c) {
            v = i;
            if (fn_80048340_put16n(arg1, &v) != 1) {
                goto fail; /* error: single shared failure exit */
            }
            v = 1;
            if (fn_80048340_put16(arg1, &v) != 1) {
                goto fail; /* error: single shared failure exit */
            }
            d = arg0->unk_70;
            if (fn_80048340_put32(arg1, &d) != 1) {
                goto fail; /* error: single shared failure exit */
            }
            d = arg0->unk_74;
            if (fn_80048340_put32(arg1, &d) != 1) {
                goto fail; /* error: single shared failure exit */
            }
            d = arg0->unk_78;
            if (fn_80048340_put32(arg1, &d) != 1) {
                goto fail; /* error: single shared failure exit */
            }
            d = arg0->unk_7c;
            if (fn_80048340_put32(arg1, &d) != 1) {
                goto fail; /* error: single shared failure exit */
            }
            count += 0x14;
            i++;
        }
    }
    if (arg0->unk_2d6 == 1) {
        if (arg0->unk_6c == 0) {
            d = 0;
            if (fn_80048340_put32(arg1, &d) != 1) {
                goto fail; /* error: single shared failure exit */
            }
            count += 4;
        }
        d = 0x41494E46;
        if (fn_80048340_put32(arg1, &d) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        d = 0x18;
        if (fn_80048340_put32(arg1, &d) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        if (fn_80048340_putBytes(arg1, arg0->unk_2d7, sizeof(arg0->unk_2d7)) !=
            sizeof(arg0->unk_2d7)) {
            goto fail; /* error: single shared failure exit */
        }
        v = arg0->unk_2e8;
        if (fn_80048340_put16(arg1, &v) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        v = 0;
        if (fn_80048340_put16(arg1, &v) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        v = arg0->unk_2ea;
        if (fn_80048340_put16(arg1, &v) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        v = arg0->unk_2ec;
        if (fn_80048340_put16(arg1, &v) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        count += 0x20;
    }
    b = 0;
    pad = arg0->unk_48 - len;
    while (count < pad) {
        if (fn_80048340_put8(arg1, &b) != 1) {
            goto fail; /* error: single shared failure exit */
        }
        count++;
    }
    if (fn_80048340_putBytes(arg1, (const void *)(lbl_8012B8FC)[0],
                             len) != len) {
        goto fail; /* error: single shared failure exit */
    }
    count += len;
    return count + 4;
fail:
    /* every field write funnels into this single shared failure exit */
    return 0;
}

typedef char AdxSjeIirFilterSizeCheck[sizeof(struct AdxSjeIirFilter) == 0x0C ? 1 : -1];

typedef char AdxSjePredictorFilterSizeCheck[sizeof(struct AdxSjePredictorFilter) == 0x90 ? 1 : -1];



static inline void adxsje_put(SJ *output, void *data, s32 size) {
    SJCK chunk;
    output->interface->get_chunk(output, 0, size, &chunk);
    if (chunk.len < size) {
        output->interface->unget_chunk(output, 0, &chunk);
    } else {
        adxsje_memcpy16(chunk.data, data, size);
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

typedef char AdxSjeIirFilterSizeCheck[sizeof(struct AdxSjeIirFilter) == 0x0C ? 1 : -1];

typedef char AdxSjePredictorFilterSizeCheck[sizeof(struct AdxSjePredictorFilter) == 0x90 ? 1 : -1];





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
        total_size += fn_80049BF4((struct fn_80049BF4_Arg0 *)encoder);
    } while (encoder->sample_position < encoder->sample_count);
    return total_size;
}

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

/* adxsje_calc_rsig, from the CC0 MK Deception decomp (adx_sje.c). GX's older SDK has
   no CINF fields, so the handle is 0x2F0 bytes. */

extern s32 lbl_8012B8F8;


static inline s16 adxsje_clamp_to_s16(s32 value)
{
    return adxsje_clamp_s16_range(value);
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
    return (((value > -0x8000 ? value : -0x8000) < 0x7FFF)
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
        value = ((s16)residual * filter->gain);
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

struct fn_8004A530_Arg0 {
    u8 pad_0[0x2];
    s8 unk_2;
};

s32 fn_8004A530(struct fn_8004A530_Arg0 *arg0) {
    return arg0->unk_2;
}

struct fn_8004A53C_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
};

u32 fn_8004A53C(struct fn_8004A53C_Arg0 *arg0) {
    return arg0->unk_10;
}

struct fn_8004A544_Arg0 {
    u8 pad_0[0x28];
    u32 unk_28;
};

s32 fn_8004A544(struct fn_8004A544_Arg0 *arg0, u32 arg1) {
    arg0->unk_28 = arg1;
    return 1;
}

typedef struct Fn8004A550Data {
    u8 _pad14[0x14];
    s32 field14;
    s32 field18;
} Fn8004A550Data;

s32 fn_8004A550(Fn8004A550Data *data, s32 value4, s32 value5) {
    data->field18 = value4;
    data->field14 = value5;
    return 1;
}

struct fn_8004A560_Arg0 {
    u8 pad_0[0x14];
    u32 unk_14;
    u32 unk_18;
};
struct fn_8004A560_Arg1 {
    u32 unk_0;
};
struct fn_8004A560_Arg2 {
    u32 unk_0;
};

s32 fn_8004A560(struct fn_8004A560_Arg0 *arg0, struct fn_8004A560_Arg1 *arg1, struct fn_8004A560_Arg2 *arg2) {
    arg1->unk_0 = arg0->unk_18;
    arg2->unk_0 = arg0->unk_14;
    return 1;
}
