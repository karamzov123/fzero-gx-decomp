#include "types.h"


/* --- dol/fn_80041BF8.c --- */
/* --- dol/fn_80041BF8.c --- */
typedef struct fn_80041BF8_Obj fn_80041BF8_Obj;
struct fn_80041BF8_Obj {
    void **vtable;
};

struct fn_80041BF8_Arg0 {
    u8 pad_0[0x1];
    u8 unk_1;
    u8 pad_2[0x1];
    s8 unk_3;
    fn_80041BF8_Obj *unk_4;
    fn_80041BF8_Obj *unk_8;
    fn_80041BF8_Obj *unk_C;
    u8 pad_10[0x4];
    void *unk_14;
    s32 unk_18;
    u8 pad_1C[0x18];
    s32 unk_34;
    u8 pad_38[0x4];
    s32 unk_3C;
    s32 unk_40;
    u8 pad_44[0x4];
    void (*unk_48)(u32);
    u32 unk_4C;
};

struct fn_8004550C_Arg {
    u8 pad_0[0x4];
};

struct fn_80045514_Arg {
    u8 pad_0[0x4];
};

extern int fn_8004559C(void *);
extern s32 fn_8004550C(struct fn_8004550C_Arg *);
extern u32 fn_80045514(struct fn_80045514_Arg *);
extern void fn_800453A4(void *, void *, s32);
extern void fn_8004538C(void *);

void fn_80041BF8(struct fn_80041BF8_Arg0 *arg0) {
    fn_80041BF8_Obj *obj4;
    fn_80041BF8_Obj *obj8;
    s32 s;
    s32 t;
    s32 n;

    t = arg0->unk_3C;
    obj4 = arg0->unk_4;
    obj8 = arg0->unk_8;
    if (t >= 0 && arg0->unk_40 >= t) {
        if (arg0->unk_48 != NULL) {
            arg0->unk_48(arg0->unk_4C);
        }
    }
    if (arg0->unk_3 == 1) {
        if (((s32 (*)(fn_80041BF8_Obj *, s32))obj8->vtable[9])(obj8, 1) == 0) {
            arg0->unk_1 = 3;
            return;
        }
    }
    ((u32 (*)(fn_80041BF8_Obj *, s32, u32, void *))obj8->vtable[6])(obj8, 1, 0x7FFFFFFF, &arg0->unk_14);
    if (fn_8004559C(obj4) == 0 && arg0->unk_18 >= 2 && (u16)*(s16 *)arg0->unk_14 == 0x8001) {
        arg0->unk_1 = 3;
        ((u32 (*)(fn_80041BF8_Obj *, s32, void *))obj8->vtable[7])(obj8, 1, &arg0->unk_14);
        return;
    }
    if (arg0->unk_34 >= fn_8004550C((struct fn_8004550C_Arg *)arg0->unk_4)) {
        arg0->unk_1 = 3;
        ((u32 (*)(fn_80041BF8_Obj *, s32, void *))obj8->vtable[7])(obj8, 1, &arg0->unk_14);
        return;
    }
    s = fn_80045514((struct fn_80045514_Arg *)arg0->unk_4);
    {
        fn_80041BF8_Obj *objC = arg0->unk_C;
        n = ((s32 (*)(fn_80041BF8_Obj *, s32))objC->vtable[9])(objC, 0);
    }
    if (n / 2 < s) {
        ((u32 (*)(fn_80041BF8_Obj *, s32, void *))obj8->vtable[7])(obj8, 1, &arg0->unk_14);
        return;
    }
    if (fn_8004559C(obj4) == 0xA) {
        ((u32 (*)(fn_80041BF8_Obj *, s32, void *))obj8->vtable[7])(obj8, 1, &arg0->unk_14);
    }
    fn_800453A4(obj4, arg0->unk_14, arg0->unk_18);
    fn_8004538C(obj4);
}

/* --- dol/adxsjd_get_wr.c --- */
typedef struct AdxXpndParams {
    int channel_count;
    const signed char *input;
    int num_blocks;
    short *output_left;
    short *output_right;
} AdxXpndParams;

typedef struct AdxXpnd {
    int used;
    int index;
    int mode;
    int status;
    int num_decoded_blocks;
    AdxXpndParams params;
    short delay[2][2];
    short coefficients[2];
    short random_state;
    short random_multiplier;
    short random_increment;
    short reserved;
} AdxXpnd;

typedef struct AdxDecodeParams {
    const unsigned short *input;
    int input_blocks;
    int channel_count;
    int block_size;
    int samples_per_block;
    short *pcm_buffer;
    int pcm_size;
    int pcm_distance;
    int write_position;
    int room;
    int loop_samples;
} AdxDecodeParams;

typedef void (*AdxGetWriteInfo)(void *, int *, int *, int *);

typedef void (*AdxAddWriteInfo)(void *, int, int);

typedef struct AdxBasicDecoder {
    short used;
    short header_decoded;
    int status;
    AdxXpnd *expander;
    signed char encoding;
    signed char bits_per_sample;
    signed char channel_count;
    signed char block_length;
    int samples_per_block;
    int sample_rate;
    int total_samples;
    short coefficient;
    short field_1E;
    int loop_insert_samples;
    short loop_count;
    short loop_type;
    int loop_start_sample;
    int loop_start_offset;
    int loop_end_sample;
    int loop_end_offset;
    int max_channels;
    short *pcm_buffer;
    int pcm_size;
    int pcm_distance;
    AdxDecodeParams decode;
    short field_74;
    short field_76;
    AdxGetWriteInfo get_write_info;
    void *get_write_object;
    AdxAddWriteInfo add_write_info;
    void *add_write_object;
    int total_decoded_samples;
    int current_write_position;
    int decoded_samples;
    int decoded_data_length;
    short format_type;
    short field_9A;
    short codec_type;
} AdxBasicDecoder;

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
    ADXSJD_MAX_HANDLES = 16,
    ADXSJD_MAX_CHANNELS = 2,
    ADXSJD_MAX_HEADER_SIZE = 0xC800,
    ADXSJD_MAX_OUTPUT_CHUNK = 0x4000
};

typedef struct AhxDecoder AhxDecoder;

typedef struct AdxBasicDecoderExt {
    AdxBasicDecoder base;
    s16 default_key[3];
    s16 snapshot_key[3];
    s16 delay_left[2];
    s16 delay_right[2];
    AhxDecoder *ahx_decoder;
    s32 ahx_max_decoded_samples;
    s32 ahx_max_decoded_blocks;
    s32 ainf_length;
    u8 ainf[16];
    s16 default_out_volume;
    s16 default_pan[2];
    u8 reserved_DA[2];
    void *pl2_context;
    u8 reserved_E0[8];
    s32 last_notified_data_length;
    s32 field_EC;
    void (*notify)(void *, s32, s32);
    void *notify_object;
} AdxBasicDecoderExt;

typedef void (*AdxSjdTrapCallback)(void *object);

typedef void (*AdxSjdOutputCallback)(void *object, s32 channel, u8 *data, s32 length);

typedef struct AdxSjdHandle {
    s8 used;
    s8 status;
    s8 channel_count;
    s8 wait_for_input;
    AdxBasicDecoderExt *decoder;
    SJ *input;
    SJ *output[ADXSJD_MAX_CHANNELS];
    SJCK input_chunk;
    SJCK output_chunk[ADXSJD_MAX_CHANNELS];
    s32 decoded_samples;
    s32 decoded_data_length;
    s32 decode_position;
    s32 max_decode_samples;
    s32 trap_num_samples;
    s32 trap_count;
    s32 trap_data_length;
    AdxSjdTrapCallback trap_callback;
    void *trap_object;
    AdxSjdOutputCallback output_callback;
    void *output_object;
    u8 spsd_info[0x40];
    s32 header_length;
    s32 link_switch;
    s32 pending_leading_samples;
    s32 pending_trailing_samples;
} AdxSjdHandle;

extern s32 fn_80045588(AdxBasicDecoderExt *decoder);

extern s16 *fn_800455A4(AdxBasicDecoderExt *decoder);

extern u8 *fn_80057DB0(SJ *sj);

void adxsjd_get_wr(void *object, int *write_position, int *writable_samples, int *limit_samples) {
    AdxSjdHandle *handle = object;
    SJ *first_output = handle->output[0];
    s32 channel;
    s32 samples;
    s32 available_samples;
    for (channel = 0; channel < fn_80045588(handle->decoder); channel++) {
        handle->output[channel]->interface->get_chunk(
            handle->output[channel], 0, ADXSJD_MAX_OUTPUT_CHUNK, &handle->output_chunk[channel]);
    }
    *write_position = (handle->output_chunk[0].data - fn_80057DB0(first_output)) / 2;
    samples = handle->max_decode_samples;
    available_samples = handle->output_chunk[0].len / 2;
    if (available_samples < samples) {
        samples = available_samples;
    }
    *writable_samples = samples;
    if (handle->trap_num_samples >= 0) {
        *limit_samples = handle->trap_num_samples - handle->trap_count;
    } else {
        *limit_samples = 0x1FFFFFFF;
    }
    (void)fn_800455A4(handle->decoder);
}

/* --- dol/fn_80041EF8.c --- */
typedef struct fn_80041EF8_Chunk {
    u8 *data;
    s32 len;
} fn_80041EF8_Chunk;

typedef struct fn_80041EF8_SjObj fn_80041EF8_SjObj;

typedef struct fn_80041EF8_SjIf {
    u8 pad_0[0x18];
    void (*GetChunk)(fn_80041EF8_SjObj *sj, s32 id, s32 nbyte, fn_80041EF8_Chunk *ck);
    void (*UngetChunk)(fn_80041EF8_SjObj *sj, s32 id, fn_80041EF8_Chunk *ck);
    void (*PutChunk)(fn_80041EF8_SjObj *sj, s32 id, fn_80041EF8_Chunk *ck);
} fn_80041EF8_SjIf;

struct fn_80041EF8_SjObj {
    fn_80041EF8_SjIf *vtbl;
};

typedef struct fn_80041EF8_Adxt {
    u8 pad_0[0x1];
    s8 stat;
    u8 pad_2[0x1];
    s8 unk_3;
    void *adxb;
    fn_80041EF8_SjObj *sji;
    u8 pad_C[0x4C];
    u8 hdr[0x40];
    s32 hdrlen;
} fn_80041EF8_Adxt;

extern s32 fn_800455B8(void *adxb, u8 *data, s32 len);
extern void fn_80047464(const char *msg1, const char *msg2);
extern void *memcpy(void *, const void *, u32);
extern void fn_800589BC(fn_80041EF8_Chunk *ck, s32 len, fn_80041EF8_Chunk *ck1, fn_80041EF8_Chunk *ck2);

void fn_80041EF8(fn_80041EF8_Adxt *adxt) {
    void *adxb;
    fn_80041EF8_SjObj *sj;
    fn_80041EF8_Chunk ck;
    fn_80041EF8_Chunk ck2;
    s32 hdrlen;
    s32 fmt;

    sj = adxt->sji;
    adxb = adxt->adxb;
    sj->vtbl->GetChunk(sj, 1, 0x1000, &ck);
    if (ck.len < 0x10) {
        sj->vtbl->UngetChunk(sj, 1, &ck);
        return;
    }
    hdrlen = fn_800455B8(adxb, ck.data, ck.len);
    if (hdrlen == 0 || hdrlen > ck.len) {
        sj->vtbl->UngetChunk(sj, 1, &ck);
        return;
    }
    if (hdrlen < 0) {
        sj->vtbl->UngetChunk(sj, 1, &ck);
        fn_80047464("E03010901 ADXB_DecodeHeader: ", "Can not decode this file format.");
        adxt->stat = 4;
        return;
    }
    adxt->hdrlen = hdrlen;
    if (fn_8004559C(adxb) == 4) {
        adxt->unk_3 = 1;
    }
    if (fn_8004559C(adxb) == 2) {
        memcpy(adxt->hdr, ck.data, (ck.len < 0x40) ? ck.len : 0x40);
    }
    fmt = fn_8004559C(adxb);
    if (fmt == 10 || fmt == 11 || fmt == 20 || fmt == 15) {
        sj->vtbl->UngetChunk(sj, 1, &ck);
    } else {
        fn_800589BC(&ck, hdrlen, &ck, &ck2);
        sj->vtbl->PutChunk(sj, 0, &ck);
        sj->vtbl->UngetChunk(sj, 1, &ck2);
    }
    adxt->stat = 2;
}

/* --- dol/fn_800420F4.c --- */
/* --- dol/fn_800420F4.c --- */
/* --- dol/fn_800420F4.c --- */
extern u32 fn_80045354(u32);

struct fn_800420F4_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_800420F4(struct fn_800420F4_Arg0 *arg0) {
    fn_80045354(arg0->unk_4);
    *(u8 *)((u8 *)(u32)arg0 + 1) = 0;
}

/* --- dol/fn_8004212C.c --- */
struct fn_8004212C_Arg0 {
    u8 pad_0[0x1];
    u8 unk_1;
    u8 pad_2[0x1];
    u8 unk_3;
    u8 pad_4[0x28];
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u32 unk_44;
    u8 pad_48[0x50];
    u32 unk_98;
};

void fn_8004212C(struct fn_8004212C_Arg0 *arg0) {
    arg0->unk_98 = 0;
    arg0->unk_2C = 0;
    arg0->unk_30 = 0;
    arg0->unk_34 = 0;
    arg0->unk_38 = (0x80000000 - 1);
    arg0->unk_3C = -1;
    arg0->unk_40 = 0;
    arg0->unk_44 = 0;
    arg0->unk_3 = 0;
    arg0->unk_1 = 1;
}

/* --- dol/fn_8004216C.c --- */
// fn_8004216C: empty in retail (single blr).
void fn_8004216C(void) {
}

/* --- dol/fn_80042170.c --- */
/* --- dol/fn_80042170.c --- */
extern u32 fn_800433D0(u32, u32);

struct fn_80042170_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x30];
    u32 unk_38;
};

void fn_80042170(struct fn_80042170_Arg0 *arg0, u32 arg1) {
    arg0->unk_38 = arg1;
    fn_800433D0(arg0->unk_4, arg1);
}

/* --- dol/fn_80042198.c --- */
extern u32 fn_800433F4(u32, u32);

struct fn_80042198_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
};

void fn_80042198(struct fn_80042198_Arg0 *arg0, u32 arg1) {
    arg0->unk_8 = arg1;
    fn_800433F4(arg0->unk_4, arg1);
}
