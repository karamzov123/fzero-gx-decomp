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
extern u32 memcmp(u32, u32, u32);
extern u32 lbl_80090080[];
extern u32 lbl_80090088[];

void fn_80043460(AdxBasicDecoder *d);
void fn_80043798(AdxBasicDecoder *d);
unsigned char *fn_80043D34(unsigned char *header, int *rate, int *channels, int *bits,
                           int *samples);

void fn_8004342C(AdxBasicDecoder *arg0) {
    if (arg0->field_9A == 1) {
        fn_80043460(arg0);
    } else {
        fn_80043798(arg0);
    }
}

void fn_80043460(AdxBasicDecoder *d) {
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

void fn_80043798(AdxBasicDecoder *d) {
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

int fn_80043B48(AdxBasicDecoder *d, signed char *input, int length) {
    short data_length;
    int samples, bits, channels, rate, result;
    signed char *data;
    d->header_decoded = 1;
    if (length < 4096) {
        data_length = 0;
        result = -1;
    } else {
        data = (signed char *)fn_80043D34((unsigned char *)input, &rate, &channels, &bits, &samples);
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
    d->format_type = 3;
    if (d->bits_per_sample == 8)
        d->field_9A = 1;
    else
        d->field_9A = 0;
    return data_length;
}

s32 fn_80043CCC(u32 arg0) {
    u32 v0;
    if ((s32)memcmp(arg0, (u32)&lbl_80090080, 4) == 0 &&
        (s32)memcmp((arg0 + 8), (u32)&lbl_80090088, 4) == 0) {
        v0 = 1;
    } else {
        v0 = 0;
    }
    return v0;
}

unsigned char *fn_80043D34(unsigned char *header, int *rate, int *channels, int *bits,
                           int *samples) {
    unsigned char *p;
    unsigned char *end;
    unsigned char *data;
    signed long id;
    int size;
    signed long form;
    int have_comm;
    int have_ssnd;
    unsigned short exp;
    unsigned short mant;
    unsigned long offset;
    p = header + 12;
    have_comm = 0;
    have_ssnd = 0;
    data = ((void *)0);
    id = ((unsigned int)(header)[0] | ((unsigned int)(header)[1] << 8) |
          ((unsigned int)(header)[2] << 16) | ((unsigned int)(header)[3] << 24));
    size = ((unsigned int)(header + 4)[0] | ((unsigned int)(header + 4)[1] << 8) |
            ((unsigned int)(header + 4)[2] << 16) | ((unsigned int)(header + 4)[3] << 24));
    size = ((((size) >> 24) & 0xFF) | (((size) >> 8) & 0xFF00) | (((size) << 8) & 0xFF0000) |
            ((size) << 24));
    form = ((unsigned int)(header + 8)[0] | ((unsigned int)(header + 8)[1] << 8) |
            ((unsigned int)(header + 8)[2] << 16) | ((unsigned int)(header + 8)[3] << 24));
    if (id != 0x4D524F46)
        return ((void *)0);
    if (form != 0x46464941)
        return ((void *)0);
    end = p + size - 4;
    while (p < end) {
        id = ((unsigned int)(p)[0] | ((unsigned int)(p)[1] << 8) | ((unsigned int)(p)[2] << 16) |
              ((unsigned int)(p)[3] << 24));
        size = ((unsigned int)(p + 4)[0] | ((unsigned int)(p + 4)[1] << 8) |
                ((unsigned int)(p + 4)[2] << 16) | ((unsigned int)(p + 4)[3] << 24));
        size = ((((size) >> 24) & 0xFF) | (((size) >> 8) & 0xFF00) | (((size) << 8) & 0xFF0000) |
                ((size) << 24));
        p += 8;
        switch (id) {
        case 0x4D4D4F43:
            if (have_comm != 0)
                break;
            if (size < 18)
                return ((void *)0);
            have_comm = 1;
            *channels = (p[0] & 0xFF) | ((p[1] & 0xFFFF) << 8);
            *channels = ((((*channels) >> 8) & 0xFF) | (((*channels) & 0xFF) << 8));
            *samples = ((unsigned int)(p + 2)[0] | ((unsigned int)(p + 2)[1] << 8) |
                        ((unsigned int)(p + 2)[2] << 16) | ((unsigned int)(p + 2)[3] << 24));
            *samples = ((((*samples) >> 24) & 0xFF) | (((*samples) >> 8) & 0xFF00) |
                        (((*samples) << 8) & 0xFF0000) | ((*samples) << 24));
            *bits = (p[6] & 0xFF) | ((p[7] & 0xFFFF) << 8);
            *bits = ((((*bits) >> 8) & 0xFF) | (((*bits) & 0xFF) << 8));
            exp = (((((unsigned short)(p[8] | (p[9] << 8))) >> 8) & 0xFF) |
                   ((((unsigned short)(p[8] | (p[9] << 8))) & 0xFF) << 8));
            mant = (((((unsigned short)(p[10] | (p[11] << 8))) >> 8) & 0xFF) |
                    ((((unsigned short)(p[10] | (p[11] << 8))) & 0xFF) << 8));
            p += 0x12;
            *rate = (signed long)mant >> (0x400E - exp);
            if (have_ssnd != 0)
                return data;
            break;
        case 0x444E5353:
            if (have_ssnd != 0)
                break;
            have_ssnd = 1;
            offset = ((unsigned int)(p)[0] | ((unsigned int)(p)[1] << 8) |
                      ((unsigned int)(p)[2] << 16) | ((unsigned int)(p)[3] << 24));
            offset = ((((offset) >> 24) & 0xFF) | (((offset) >> 8) & 0xFF00) |
                      (((offset) << 8) & 0xFF0000) | ((offset) << 24));
            p += 4;
            data = p + offset;
            if (have_comm != 0)
                return data;
            break;
        default:
            p += (size + 1) & ~1;
            break;
        }
    }
    return data;
}
