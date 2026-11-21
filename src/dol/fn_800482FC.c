#include "types.h"
#pragma use_lmw_stmw on

/* --- dol/fn_800482FC.c --- */
/* --- dol/fn_800482FC.c --- */
struct fn_800482FC_lbl_8017B5A8 {
    u32 unk_0;    u8 pad_4[0x9CC];
};

extern struct fn_800482FC_lbl_8017B5A8 lbl_8017B5A8[];
extern u32 lbl_8017BF78[];
extern u32 memset(u32, u32, u32);

void fn_800482FC(void) {
    u32 v0;
    v0 = lbl_8017B5A8[0].unk_0;
    lbl_8017B5A8[0].unk_0 = (v0 + 1);
    memset((u32)&lbl_8017BF78, 0, 6016);
}

/* --- dol/fn_80048340.c --- */
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
extern void *memcpy(void *, const void *, u16);

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
    memcpy(blk.ptr, src, n & 0xffff);
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

/* --- dol/fn_80049728.c --- */
typedef struct SJCK {
    unsigned char *data;
    long len;
} SJCK;

typedef struct SJ_u1 SJ_u1;

typedef struct SJInterface_u1 SJInterface_u1;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface_u1 {
    void *reserved[3];
    void (*destroy)(SJ_u1 *sj);
    const void *(*get_uuid)(SJ_u1 *sj);
    void (*reset)(SJ_u1 *sj);
    void (*get_chunk)(SJ_u1 *sj, long channel, long max_size, SJCK *chunk);
    void (*unget_chunk)(SJ_u1 *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ_u1 *sj, int channel, SJCK *chunk);
    int (*get_num_data)(SJ_u1 *sj, int channel);
    int (*is_get_chunk)(SJ_u1 *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ_u1 *sj, SJErrorCallback callback, void *object);
};

struct SJ_u1 {
    const SJInterface_u1 *interface;
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
    SJ_u1 *input[ADXSJE_MAX_CHANNELS];
    SJ_u1 *output;
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


static inline void adxsje_put(SJ_u1 *output, void *data, s32 size) {
    SJCK chunk;
    output->interface->get_chunk(output, 0, size, &chunk);
    if (chunk.len < size) {
        output->interface->unget_chunk(output, 0, &chunk);
    } else {
        memcpy(chunk.data, data, size);
        output->interface->put_chunk(output, 1, &chunk);
    }
}

static inline void adxsje_put16(SJ_u1 *output, void *data) {
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
    SJ_u1 *output;
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
