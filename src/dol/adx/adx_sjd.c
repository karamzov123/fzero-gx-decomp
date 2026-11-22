#include "types.h"

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
    s32 len;
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
} AdxSjdHandle;

extern AdxSjdHandle lbl_801798C0[ADXSJD_MAX_HANDLES];

extern void *memset(void *, int, u32);
extern void *memcpy(void *, const void *, u32);
extern u32 fn_8004541C(void *);
extern u32 fn_80045468(void *);
extern u32 fn_800454B4(void *, u32);
extern u32 fn_800454C4(void *);
extern u32 fn_800454CC(void *);
extern u32 fn_800454D4(void *);
extern u32 fn_800454DC(void *);
extern u32 fn_800454E4(void *);
extern u32 fn_800454FC(void *);
extern u32 fn_80045504(void *);
extern u32 fn_8004550C(void *);
extern u32 fn_80045514(void *);
extern u32 fn_8004551C(void *);
extern s32 fn_80045588(void *);
extern u32 fn_80045594(void *);
extern s32 fn_8004559C(void *);
extern s16 *fn_800455A4(void *);
extern void fn_800455AC(AdxBasicDecoderExt *decoder, AdxGetWriteInfo function, void *object);
extern s32 fn_800455B8(void *adxb, u8 *data, s32 len);
extern s32 fn_80045414(void *);
extern void fn_80044E7C(void *);
extern u32 fn_80045304(void *);
extern u32 fn_800452FC(void *);
extern void fn_8004530C(void *);
extern void fn_80045354(void *);
extern void fn_8004538C(void *);
extern void fn_800453A4(void *, void *, s32);
extern u32 fn_80045D3C(void *);
extern u32 fn_80045FA4(void);
extern AdxBasicDecoderExt *ADXB_Create(s32 max_channels, s16 *pcm_buffer, s32 pcm_size,
                                       s32 pcm_distance);
extern u32 fn_800589BC(void *, u32, SJCK *, SJCK *);
extern u8 *fn_80057DB0(SJ *sj);
extern s32 fn_80057DA8(SJ *sj);
extern s32 fn_80057DA0(SJ *sj);
extern void fn_80047464(const char *msg1, const char *msg2);
extern u32 fn_800433D0(void *, u32);
extern u32 fn_800433F4(void *, u32);
extern void fn_80046718(void);
extern void fn_80046738(void);

void fn_80041BF8(AdxSjdHandle *arg0);
void fn_80041EF8(AdxSjdHandle *adxt);
void adxsjd_get_wr(void *object, int *write_position, int *writable_samples, int *limit_samples);

void fn_80041410(AdxSjdHandle *arg0) {
    fn_8004541C(arg0->decoder);
}

void fn_80041434(AdxSjdHandle *arg0) {
    fn_80045468(arg0->decoder);
}

void *fn_80041458(void *ptr) {
    return (u8 *)ptr + 0x58;
}

s32 fn_80041460(AdxSjdHandle *arg0, u32 arg1) {
    u32 v0;
    u32 t0, t1;
    t0 = fn_800454CC(arg0->decoder);
    v0 = t0;
    if ((s32)t0 > 0 && (arg0->status == 2 || arg0->status == 3)) {
        t1 = fn_800454B4(arg0->decoder, arg1);
        v0 = t1;
    } else {
        v0 = -128;
    }
    return v0;
}

s32 fn_800414D0(AdxSjdHandle *arg0) {
    u32 v0;
    u32 t0, t1;
    t0 = fn_800454CC(arg0->decoder);
    v0 = t0;
    if ((s32)t0 > 0 && (arg0->status == 2 || arg0->status == 3)) {
        t1 = fn_800454C4(arg0->decoder);
        v0 = t1;
    } else {
        v0 = 0;
    }
    return v0;
}

void fn_80041530(AdxSjdHandle *arg0) {
    fn_800454D4(arg0->decoder);
}

void fn_80041554(AdxSjdHandle *arg0) {
    fn_800454DC(arg0->decoder);
}

u32 fn_80041578(AdxSjdHandle *arg0) {
    u32 v0;
    if (arg0 == 0) {
        v0 = 0;
    } else {
        v0 = fn_800454E4(arg0->decoder);
    }
    return v0;
}

void fn_800415AC(AdxSjdHandle *arg0) {
    fn_800454FC(arg0->decoder);
}

void fn_800415D0(AdxSjdHandle *arg0) {
    fn_80045504(arg0->decoder);
}

void fn_800415F4(AdxSjdHandle *arg0) {
    fn_8004550C(arg0->decoder);
}

void fn_80041618(AdxSjdHandle *arg0) {
    fn_80045514(arg0->decoder);
}

void fn_8004163C(AdxSjdHandle *arg0) {
    fn_8004551C(arg0->decoder);
}

void fn_80041660(AdxSjdHandle *arg0) {
    fn_80045588(arg0->decoder);
}

void fn_80041684(AdxSjdHandle *arg0) {
    fn_80045594(arg0->decoder);
}

void fn_800416A8(AdxSjdHandle *arg0) {
    fn_8004559C(arg0->decoder);
}

void fn_800416CC(AdxSjdHandle *arg0, u32 arg1) {
    arg0->trap_data_length = arg1;
}

void fn_800416D4(AdxSjdHandle *arg0, u32 arg1) {
    arg0->trap_count = arg1;
}

void fn_800416DC(AdxSjdHandle *arg0, u32 arg1) {
    arg0->trap_num_samples = arg1;
}

void fn_800416E4(AdxSjdHandle *arg0, AdxSjdTrapCallback arg1, void *arg2) {
    arg0->trap_callback = arg1;
    arg0->trap_object = arg2;
}

void fn_800416F0(AdxSjdHandle *arg0, u32 arg1) {
    arg0->decode_position = arg1;
}

u32 fn_800416F8(AdxSjdHandle *arg0) {
    return arg0->decoded_samples;
}

void fn_80041700(void) {
    struct { AdxBasicDecoderExt *value; } voice;
    struct { s32 value; } len;
    struct { AdxBasicDecoderExt *value; } v;
    AdxSjdHandle *ch;
    s32 count;
    s32 i;
    struct { s32 value; } j;
    struct { SJ *value; } main;
    struct { AdxBasicDecoderExt *value; } v2;
    s32 avail;
    s32 len2;
    s32 n;
    s32 lim;
    s16 state;
    SJCK b;
    SJCK a;

    for (i = 0; i < 16; i++) {
        ch = &lbl_801798C0[i];
        if ((s32)(u8)ch->used != 1) {
            continue;
        }
        if (ch->status == 2) {
            voice.value = ch->decoder;
            if (fn_80045414(voice.value) == 0) {
                fn_80041BF8(ch);
            }
            fn_80044E7C(voice.value);
            if (fn_80045414(voice.value) == 3) {
                len.value = 0;
                v.value = ch->decoder;
                main.value = ch->input;
                count = fn_8004550C(v.value);
                len.value = fn_80045304(v.value);
                lim = fn_800452FC(v.value);
                count -= ch->decode_position;
                if (lim < count) {
                    count = lim;
                }
                fn_800589BC(&ch->input_chunk, len.value, &a, &b);
                main.value->interface->put_chunk(main.value, 0, &a);
                main.value->interface->unget_chunk(main.value, 1, &b);
                for (j.value = 0; j.value < fn_80045588(ch->decoder); j.value++) {
                    fn_800589BC(&ch->output_chunk[j.value], count * 2, &a, &b);
                    if (ch->output_callback != NULL) {
                        ch->output_callback(ch->output_object, j.value, a.data, a.len);
                    }
                    ch->output[j.value]->interface->put_chunk(ch->output[j.value], 1, &a);
                    ch->output[j.value]->interface->unget_chunk(ch->output[j.value], 0, &b);
                }
                ch->decoded_samples += count;
                ch->decoded_data_length += len.value;
                ch->decode_position += count;
                ch->trap_count += count;
                ch->trap_data_length += len.value;
                fn_8004530C(v.value);
            }
            if (voice.value->base.format_type == 10 || voice.value->base.format_type == 20 ||
                voice.value->base.format_type == 11 || voice.value->base.format_type == 15) {
                v2.value = ch->decoder;
                avail = fn_8004550C(v2.value);
                len2 = fn_80045304(v2.value);
                lim = fn_800452FC(v2.value);
                n = avail - ch->decode_position;
                if (lim < n) {
                    n = lim;
                }
                ch->decoded_samples += n;
                ch->decoded_data_length += len2;
                ch->decode_position += n;
            }
        } else if (ch->status == 1) {
            fn_80041EF8(ch);
        }
    }
}

typedef u32 (*fn_80041990_Fn0)(u32, u32, void *);
typedef u32 (*fn_80041990_Fn1)(u32, u32, void *);
typedef u32 (*fn_80041990_Fn2)(u32, u32, u32, u32);
typedef u32 (*fn_80041990_Fn3)(u32, u32, void *);
typedef u32 (*fn_80041990_Fn4)(u32, u32, void *);

void fn_80041990(AdxSjdHandle *arg0) {
    struct { u32 value; } v1;
    u32 v2;
    struct { u32 value; } v3;
    register AdxSjdHandle *v10;
    struct { u32 value; } v5;
    u32 v6;
    register AdxSjdHandle *v9;
    u32 v4;
    struct { s32 value; } v11;
    u32 doubled;
    u32 limit;
    s16 v15;
    struct { u32 value; } v16;
    u32 v17;
    u32 v18;
    u32 v19;
    struct { u32 unk_0; u32 unk_4; } loc_10;
    struct { u32 unk_0; u32 unk_4; } loc_8;
    if ((s8)*((u8 *)arg0 + 1) == 2) {
        v1.value = *(u32 *)((u8 *)arg0 + 4);
        if ((s32)fn_80045414((void *)v1.value) == 0)
            fn_80041BF8(arg0);
        fn_80044E7C((void *)v1.value);
        if ((s32)fn_80045414((void *)v1.value) == 3) {
            v2 = *(u32 *)((u8 *)arg0 + 4);
            v3.value = *(u32 *)((u8 *)arg0 + 8);
            v4 = fn_8004550C((void *)v2);
            v5.value = fn_80045304((void *)v2);
            limit = fn_800452FC((void *)v2);
            v6 = v4 - *(u32 *)((u8 *)arg0 + 52);
            if ((s32)limit < (s32)v6) v6 = limit;
            fn_800589BC((u8 *)arg0 + 20, v5.value, (SJCK *)&loc_8, (SJCK *)&loc_10);
            ((fn_80041990_Fn0)*(u32 *)(*(u32 *)v3.value + 32))(v3.value, 0, &loc_8);
            ((fn_80041990_Fn1)*(u32 *)(*(u32 *)v3.value + 28))(v3.value, 1, &loc_10);
            v10 = arg0;
            v9 = arg0;
            doubled = v6 << 1;
            for (v11.value = 0; v11.value < fn_80045588((void *)*(u32 *)((u8 *)arg0 + 4)); v11.value++) {
                u32 obj;
                fn_800589BC((u8 *)v10 + 28, doubled, (SJCK *)&loc_8, (SJCK *)&loc_10);
                if (*(u32 *)((u8 *)arg0 + 80) != 0)
                    ((fn_80041990_Fn2)*(u32 *)((u8 *)arg0 + 80))(*(u32 *)((u8 *)arg0 + 84), v11.value, loc_8.unk_0, loc_8.unk_4);
                obj = *(u32 *)((u8 *)v9 + 12);
                ((fn_80041990_Fn3)*(u32 *)(*(u32 *)obj + 32))(obj, 1, &loc_8);
                obj = *(u32 *)((u8 *)v9 + 12);
                ((fn_80041990_Fn4)*(u32 *)(*(u32 *)obj + 28))(obj, 0, &loc_10);
                v10 = (AdxSjdHandle *)((u8 *)v10 + 8);
                v9 = (AdxSjdHandle *)((u8 *)v9 + 4);
            }
            *(u32 *)((u8 *)arg0 + 44) += v6;
            *(u32 *)((u8 *)arg0 + 48) += v5.value;
            *(u32 *)((u8 *)arg0 + 52) += v6;
            *(u32 *)((u8 *)arg0 + 64) += v6;
            *(u32 *)((u8 *)arg0 + 68) += v5.value;
            fn_8004530C((void *)v2);
        }
        v15 = *(s16 *)(v1.value + 152);
        if ((s32)v15 == 10 || v15 == 20 || v15 == 11 || v15 == 15) {
            v16.value = *(u32 *)((u8 *)arg0 + 4);
            v17 = fn_8004550C((void *)v16.value);
            v18 = fn_80045304((void *)v16.value);
            limit = fn_800452FC((void *)v16.value);
            v19 = v17 - *(u32 *)((u8 *)arg0 + 52);
            if ((s32)limit < (s32)v19) v19 = limit;
            *(u32 *)((u8 *)arg0 + 44) += v19;
            *(u32 *)((u8 *)arg0 + 48) += v18;
            *(u32 *)((u8 *)arg0 + 52) += v19;
        }
    } else if ((s8)*((u8 *)arg0 + 1) == 1) {
        fn_80041EF8(arg0);
    }
}

void fn_80041BF8(AdxSjdHandle *arg0) {
    AdxBasicDecoderExt *obj4;
    SJ *obj8;
    s32 s;
    s32 t;
    s32 n;

    t = arg0->trap_num_samples;
    obj4 = arg0->decoder;
    obj8 = arg0->input;
    if (t >= 0 && arg0->trap_count >= t) {
        if (arg0->trap_callback != NULL) {
            arg0->trap_callback(arg0->trap_object);
        }
    }
    if (arg0->wait_for_input == 1) {
        if (obj8->interface->get_num_data(obj8, 1) == 0) {
            arg0->status = 3;
            return;
        }
    }
    obj8->interface->get_chunk(obj8, 1, 0x7FFFFFFF, &arg0->input_chunk);
    if (fn_8004559C(obj4) == 0 && arg0->input_chunk.len >= 2 &&
        (u16)*(s16 *)arg0->input_chunk.data == 0x8001) {
        arg0->status = 3;
        obj8->interface->unget_chunk(obj8, 1, &arg0->input_chunk);
        return;
    }
    if (arg0->decode_position >= (s32)fn_8004550C(arg0->decoder)) {
        arg0->status = 3;
        obj8->interface->unget_chunk(obj8, 1, &arg0->input_chunk);
        return;
    }
    s = fn_80045514(arg0->decoder);
    {
        SJ *objC = arg0->output[0];
        n = objC->interface->get_num_data(objC, 0);
    }
    if (n / 2 < s) {
        obj8->interface->unget_chunk(obj8, 1, &arg0->input_chunk);
        return;
    }
    if (fn_8004559C(obj4) == 0xA) {
        obj8->interface->unget_chunk(obj8, 1, &arg0->input_chunk);
    }
    fn_800453A4(obj4, arg0->input_chunk.data, arg0->input_chunk.len);
    fn_8004538C(obj4);
}

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

void fn_80041EF8(AdxSjdHandle *adxt) {
    void *adxb;
    SJ *sj;
    SJCK ck;
    SJCK ck2;
    s32 hdrlen;
    s32 fmt;

    sj = adxt->input;
    adxb = adxt->decoder;
    sj->interface->get_chunk(sj, 1, 0x1000, &ck);
    if (ck.len < 0x10) {
        sj->interface->unget_chunk(sj, 1, &ck);
        return;
    }
    hdrlen = fn_800455B8(adxb, ck.data, ck.len);
    if (hdrlen == 0 || hdrlen > ck.len) {
        sj->interface->unget_chunk(sj, 1, &ck);
        return;
    }
    if (hdrlen < 0) {
        sj->interface->unget_chunk(sj, 1, &ck);
        fn_80047464("E03010901 ADXB_DecodeHeader: ", "Can not decode this file format.");
        adxt->status = 4;
        return;
    }
    adxt->header_length = hdrlen;
    if (fn_8004559C(adxb) == 4) {
        adxt->wait_for_input = 1;
    }
    if (fn_8004559C(adxb) == 2) {
        memcpy(adxt->spsd_info, ck.data, (ck.len < 0x40) ? ck.len : 0x40);
    }
    fmt = fn_8004559C(adxb);
    if (fmt == 10 || fmt == 11 || fmt == 20 || fmt == 15) {
        sj->interface->unget_chunk(sj, 1, &ck);
    } else {
        fn_800589BC(&ck, hdrlen, &ck, &ck2);
        sj->interface->put_chunk(sj, 0, &ck);
        sj->interface->unget_chunk(sj, 1, &ck2);
    }
    adxt->status = 2;
}

void fn_800420F4(AdxSjdHandle *arg0) {
    fn_80045354(arg0->decoder);
    arg0->status = 0;
}

void fn_8004212C(AdxSjdHandle *arg0) {
    arg0->header_length = 0;
    arg0->decoded_samples = 0;
    arg0->decoded_data_length = 0;
    arg0->decode_position = 0;
    arg0->max_decode_samples = (0x80000000 - 1);
    arg0->trap_num_samples = -1;
    arg0->trap_count = 0;
    arg0->trap_data_length = 0;
    arg0->wait_for_input = 0;
    arg0->status = 1;
}

// fn_8004216C: empty in retail (single blr).
void fn_8004216C(void) {
}

void fn_80042170(AdxSjdHandle *arg0, u32 arg1) {
    arg0->max_decode_samples = arg1;
    fn_800433D0(arg0->decoder, arg1);
}

void fn_80042198(AdxSjdHandle *arg0, u32 arg1) {
    arg0->input = (SJ *)arg1;
    fn_800433F4(arg0->decoder, arg1);
}

s32 fn_800421C0(AdxSjdHandle *arg0) {
    return arg0->status;
}

void fn_800421CC(AdxSjdHandle *arg0) {
    AdxBasicDecoderExt *v0;
    if (arg0 != 0) {
        v0 = arg0->decoder;
        if (v0 != 0) {
            arg0->decoder = 0;
            fn_80045D3C(v0);
        }
        fn_80046738();
        memset(arg0, 0, 156);
        fn_80046718();
    }
}

AdxSjdHandle *fn_80042228(SJ *input, s32 channel_count, SJ **output) {
    u8 *pcm_buffer;
    s32 pcm_size;
    s32 index;
    SJ *first_output;
    s32 pcm_extra;
    AdxSjdHandle *handle;
    first_output = output[0];
    for (index = 0; index < ADXSJD_MAX_HANDLES; index++) {
        if (lbl_801798C0[index].used == 0) {
            break;
        }
    }
    if (index == ADXSJD_MAX_HANDLES) {
        return 0;
    }
    handle = &lbl_801798C0[index];
    pcm_buffer = fn_80057DB0(first_output);
    pcm_size = fn_80057DA8(first_output) / 2;
    pcm_extra = fn_80057DA0(first_output) / 2;
    handle->decoder =
        ADXB_Create(channel_count, (s16 *)pcm_buffer, pcm_size, pcm_size + pcm_extra);
    if (handle->decoder == 0) {
        return 0;
    }
    fn_800455AC(handle->decoder, adxsjd_get_wr, handle);
    handle->input = input;
    handle->channel_count = channel_count;
    for (index = 0; index < channel_count; index++) {
        handle->output[index] = output[index];
    }
    handle->status = 0;
    handle->header_length = 0;
    handle->decoded_samples = 0;
    handle->decoded_data_length = 0;
    handle->decode_position = 0;
    handle->max_decode_samples = 0x7FFFFFFF;
    handle->trap_num_samples = -1;
    handle->trap_count = 0;
    handle->trap_data_length = 0;
    handle->wait_for_input = 0;
    handle->trap_callback = 0;
    handle->trap_object = 0;
    handle->output_callback = 0;
    handle->output_object = 0;
    handle->used = 1;
    return handle;
}

void fn_800424B8(void) {
    memset(&lbl_801798C0, 0, 2496);
}

void fn_800424E8(void) {
    fn_80045FA4();
    memset(&lbl_801798C0, 0, 2496);
}
