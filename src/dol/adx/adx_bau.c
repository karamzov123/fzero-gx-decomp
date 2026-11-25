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

extern int ADXPD_GetStat(AdxXpnd *decoder);
extern short lbl_8012B6F8[256];
extern u32 fn_8008023C(u32, u32, u32);
extern u32 lbl_80090090[];
extern u32 lbl_80090098[];

void ADXB_ExecOneAuUlaw(AdxBasicDecoder *d);
void fn_800443AC(AdxBasicDecoder *d);
void fn_800446E4(AdxBasicDecoder *d);
void *fn_80044C74(void *header, int length, int *rate, int *channels, int *bits, int *samples,
                  int *codec);

void fn_80043FA4(AdxBasicDecoder *arg0) {
    if (arg0->field_9A == 2) {
        ADXB_ExecOneAuUlaw(arg0);
    } else if (arg0->field_9A == 1) {
        fn_800443AC(arg0);
    } else {
        fn_800446E4(arg0);
    }
}

void ADXB_ExecOneAuUlaw(AdxBasicDecoder *d) {
    AdxDecodeParams *dp = &d->decode;
    unsigned char *input = (unsigned char *)dp->input;
    unsigned short *pcm, *left, *right;
    int i, count;
    if (d->status == 1 && ADXPD_GetStat(d->expander) == 0) {
        d->get_write_info(d->get_write_object, &dp->write_position, &dp->room, &dp->loop_samples);
        count = dp->pcm_size - dp->write_position;
        if (count > dp->room)
            count = dp->room;
        if (count > dp->input_blocks)
            count = dp->input_blocks;
        pcm = (unsigned short *)dp->pcm_buffer;
        left = &pcm[dp->write_position];
        if (d->channel_count == 2) {
            right = &pcm[dp->pcm_distance + dp->write_position];
            for (i = 0; i < count; i++) {
                left[i] = lbl_8012B6F8[input[i * 2]];
                right[i] = lbl_8012B6F8[input[i * 2 + 1]];
            }
        } else {
            for (i = 0; i < count; i++)
                left[i] = lbl_8012B6F8[input[i]];
        }
        d->decoded_samples = count;
        d->decoded_data_length = count * d->channel_count;
        d->status = 2;
    }
    if (d->status == 2) {
        d->add_write_info(d->add_write_object, d->decoded_data_length, d->decoded_samples);
        d->status = 3;
    }
}

void fn_800443AC(AdxBasicDecoder *d) {
    AdxDecodeParams *dp;
    unsigned char *input;
    unsigned short *pcm, *left, *right;
    int i, count;
    dp = &d->decode;
    input = (unsigned char *)dp->input;
    if (d->status == 1 && ADXPD_GetStat(d->expander) == 0) {
        d->get_write_info(d->get_write_object, &dp->write_position, &dp->room, &dp->loop_samples);
        count = dp->pcm_size - dp->write_position;
        if (count > dp->room)
            count = dp->room;
        if (count > dp->input_blocks)
            count = dp->input_blocks;
        pcm = (unsigned short *)dp->pcm_buffer;
        left = &pcm[dp->write_position];
        if (d->channel_count == 2) {
            right = &pcm[dp->pcm_distance + dp->write_position];
            for (i = 0; i < count; i++) {
                left[i] = input[i * 2] * 256;
                right[i] = input[i * 2 + 1] * 256;
            }
        } else {
            for (i = 0; i < count; i++)
                left[i] = input[i] * 256;
        }
        d->decoded_samples = count;
        d->decoded_data_length = count * d->channel_count;
        d->status = 2;
    }
    if (d->status == 2) {
        d->add_write_info(d->add_write_object, d->decoded_data_length, d->decoded_samples);
        d->status = 3;
    }
}

void fn_800446E4(AdxBasicDecoder *d) {
    AdxDecodeParams *dp;
    unsigned short *pcm, *left, *right;
    unsigned short *input;
    unsigned short sample;
    int i, count;
    dp = &d->decode;
    input = (unsigned short *)dp->input;
    if (d->status == 1 && ADXPD_GetStat(d->expander) == 0) {
        d->get_write_info(d->get_write_object, &dp->write_position, &dp->room, &dp->loop_samples);
        count = dp->pcm_size - dp->write_position;
        if (count > dp->room)
            count = dp->room;
        if (count > dp->input_blocks)
            count = dp->input_blocks;
        pcm = (unsigned short *)dp->pcm_buffer;
        left = &pcm[dp->write_position];
        if (d->channel_count == 2) {
            right = &pcm[dp->pcm_distance + dp->write_position];
            for (i = 0; i < count; i++) {
                sample = input[i * 2];
                left[i] = (sample << 8) | (sample >> 8);
                sample = input[i * 2 + 1];
                right[i] = (sample << 8) | (sample >> 8);
            }
        } else {
            for (i = 0; i < count; i++) {
                left[i] = input[i] >> 8 | input[i] << 8;
            }
        }
        d->decoded_samples = count;
        d->decoded_data_length = d->channel_count * (count * 2);
        d->status = 2;
    }
    if (d->status == 2) {
        d->add_write_info(d->add_write_object, d->decoded_data_length, d->decoded_samples);
        d->status = 3;
    }
}

int fn_80044A94(AdxBasicDecoder *d, signed char *input, int length) {
    short data_length;
    int codec, samples, bits, channels, rate, result;
    signed char *data;
    d->header_decoded = 1;
    if (length < 8) {
        data_length = 0;
        result = -1;
    } else {
        data = fn_80044C74(input, length, &rate, &channels, &bits, &samples, &codec);
        if (data == ((void *)0)) {
            result = -1;
        } else {
            data_length = data - input;
            if (data_length <= 0) {
                result = -1;
            } else {
                d->sample_rate = rate;
                d->channel_count = channels;
                d->bits_per_sample = bits;
                d->total_samples = samples;
                d->encoding = -1;
                d->block_length = d->channel_count * d->bits_per_sample / 8;
                d->samples_per_block = 1;
                result = 0;
            }
        }
    }
    if (result < 0)
        return 0;
    d->coefficient = 0;
    d->loop_count = d->loop_type = 0;
    d->loop_insert_samples = d->loop_start_sample = d->loop_start_offset = d->loop_end_sample =
        d->loop_end_offset = 0;
    d->decode.channel_count = d->channel_count;
    d->decode.block_size = d->block_length;
    d->decode.samples_per_block = d->samples_per_block;
    d->decode.pcm_buffer = d->pcm_buffer;
    d->decode.pcm_size = d->pcm_size;
    d->decode.pcm_distance = d->pcm_distance;
    d->total_decoded_samples = d->current_write_position = 0;
    d->format_type = 4;
    d->field_9A = codec;
    return data_length;
}

s32 fn_80044C0C(u32 arg0) {
    u32 v0;
    if ((s32)fn_8008023C(arg0, (u32)&lbl_80090090, 4) == 0 ||
        (s32)fn_8008023C(arg0, (u32)&lbl_80090098, 4) == 0) {
        v0 = 1;
    } else {
        v0 = 0;
    }
    return v0;
}

static inline s32 rd32(const unsigned char *p) {
    return p[0] | p[1] << 8 | p[2] << 16 | p[3] << 24;
}

static inline unsigned int sw32(unsigned int v) {
    return v >> 24 | (v >> 8 & 0xFF00) | (v << 8 & 0xFF0000) | v << 24;
}

#pragma opt_common_subs off
void *fn_80044C74(void *header, int length, int *rate, int *channels, int *bits, int *samples,
                  int *codec) {
    unsigned int magic;
    unsigned int header_size;
    int encoding;
    int data_size;
    unsigned char *p = header;
    magic = rd32(p);
    p += 4;
    if (magic != 0x64732E) {
        if (magic != 0x646E732E)
            return ((void *)0);
    }
    header_size = rd32(p);
    header_size = sw32(header_size);
    p += 4;
    if ((int)header_size > length)
        return ((void *)0);
    data_size = rd32(p);
    data_size = sw32(data_size);
    p += 4;
    encoding = rd32(p);
    encoding = sw32(encoding);
    p += 4;
    switch (encoding) {
    case 1:
        *codec = 2;
        *bits = 8;
        break;
    case 2:
        *codec = 1;
        *bits = 8;
        break;
    case 3:
        *codec = 0;
        *bits = 16;
        break;
    default:
        return ((void *)0);
    }
    *rate = rd32(p);
    *rate = sw32(*rate);
    p += 4;
    *channels = rd32(p);
    *channels = sw32(*channels);
    p += 4;
    if (*codec == 2)
        *samples = data_size / *channels;
    else if (*codec == 1)
        *samples = data_size / *channels;
    else if (*codec == 0)
        *samples = (data_size / 2) / *channels;
    else
        *samples = 0x7FFF0000;
    return (unsigned char *)header + header_size;
}
#pragma opt_common_subs reset
