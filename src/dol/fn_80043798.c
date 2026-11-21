#include "types.h"


/* --- dol/fn_80043798.c --- */
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
    long num_decoded_blocks;
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
    long input_blocks;
    long channel_count;
    long block_size;
    long samples_per_block;
    short *pcm_buffer;
    long pcm_size;
    long pcm_distance;
    long write_position;
    long room;
    long loop_samples;
} AdxDecodeParams;

typedef short *(*AdxGetWriteInfo)(void *, long *, long *, long *);

typedef void (*AdxAddWriteInfo)(void *, long, long);

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
    int loop_insert_samples;
    short loop_count;
    short loop_type;
    int loop_start_sample;
    int loop_start_offset;
    int loop_end_sample;
    int loop_end_offset;
    int max_channels;
    short *pcm_buffer;
    long pcm_size;
    long pcm_distance;
    AdxDecodeParams decode;
    int field_74;
    AdxGetWriteInfo get_write_info;
    void *get_write_object;
    AdxAddWriteInfo add_write_info;
    void *add_write_object;
    long total_decoded_samples;
    long current_write_position;
    long decoded_samples;
    long decoded_data_length;
    short format_type;
    short raw_format_type;
    short codec_type;
} AdxBasicDecoder;

void fn_80043798(AdxBasicDecoder *d);

int fn_8004E270(AdxXpnd *decoder);

void fn_80043798(AdxBasicDecoder *d) {
    AdxDecodeParams *dp;
    unsigned short *pcm, *left, *right;
    unsigned short *input;
    unsigned short sample;
    int i, count;
    dp = &d->decode;
    input = (unsigned short *)dp->input;
    if (d->status == 1 && fn_8004E270(d->expander) == 0) {
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

/* --- dol/fn_80043B48.c --- */
/* --- dol/fn_80043B48.c --- */
typedef struct AdxXpndParams_u1 {
    union {
        unsigned char padding_extent[20];
        struct {
            int channel_count;
        } view_channel_count;
    } fields;
} AdxXpndParams_u1;

typedef struct AdxXpnd_u1 {
    int used;
    int index;
    int mode;
    int status;
    int num_decoded_blocks;
    AdxXpndParams_u1 params;
    short delay[2][2];
    short coefficients[2];
    short random_state;
    short random_multiplier;
    short random_increment;
    short reserved;
} AdxXpnd_u1;

typedef struct AdxDecodeParams_u1 {
    union {
        unsigned char padding_extent[44];
        struct {
            unsigned char padding_channel_count[8];
            int channel_count;
        } view_channel_count;
        struct {
            unsigned char padding_block_size[12];
            int block_size;
        } view_block_size;
        struct {
            unsigned char padding_samples_per_block[16];
            int samples_per_block;
        } view_samples_per_block;
        struct {
            unsigned char padding_pcm_buffer[20];
            short *pcm_buffer;
        } view_pcm_buffer;
        struct {
            unsigned char padding_pcm_size[24];
            int pcm_size;
        } view_pcm_size;
        struct {
            unsigned char padding_pcm_distance[28];
            int pcm_distance;
        } view_pcm_distance;
    } fields;
} AdxDecodeParams_u1;

typedef void (*AdxGetWriteInfo_u1)(void *, int *, int *, int *);

typedef void (*AdxAddWriteInfo_u1)(void *, int, int);

typedef struct AdxBasicDecoder_u1 {
    union {
        unsigned char padding_extent[160];
        struct {
            unsigned char padding_header_decoded[2];
            short header_decoded;
        } view_header_decoded;
        struct {
            unsigned char padding_encoding[12];
            signed char encoding;
        } view_encoding;
        struct {
            unsigned char padding_bits_per_sample[13];
            signed char bits_per_sample;
        } view_bits_per_sample;
        struct {
            unsigned char padding_channel_count[14];
            signed char channel_count;
        } view_channel_count;
        struct {
            unsigned char padding_block_length[15];
            signed char block_length;
        } view_block_length;
        struct {
            unsigned char padding_samples_per_block[16];
            int samples_per_block;
        } view_samples_per_block;
        struct {
            unsigned char padding_sample_rate[20];
            int sample_rate;
        } view_sample_rate;
        struct {
            unsigned char padding_total_samples[24];
            int total_samples;
        } view_total_samples;
        struct {
            unsigned char padding_coefficient[28];
            short coefficient;
        } view_coefficient;
        struct {
            unsigned char padding_loop_insert_samples[52];
            int loop_insert_samples;
        } view_loop_insert_samples;
        struct {
            unsigned char padding_loop_count[36];
            short loop_count;
        } view_loop_count;
        struct {
            unsigned char padding_loop_type[38];
            short loop_type;
        } view_loop_type;
        struct {
            unsigned char padding_loop_start_sample[48];
            int loop_start_sample;
        } view_loop_start_sample;
        struct {
            unsigned char padding_loop_start_offset[44];
            int loop_start_offset;
        } view_loop_start_offset;
        struct {
            unsigned char padding_loop_end_sample[40];
            int loop_end_sample;
        } view_loop_end_sample;
        struct {
            unsigned char padding_loop_end_offset[32];
            int loop_end_offset;
        } view_loop_end_offset;
        struct {
            unsigned char padding_pcm_buffer[60];
            short *pcm_buffer;
        } view_pcm_buffer;
        struct {
            unsigned char padding_pcm_size[64];
            int pcm_size;
        } view_pcm_size;
        struct {
            unsigned char padding_pcm_distance[68];
            int pcm_distance;
        } view_pcm_distance;
        struct {
            unsigned char padding_decode[72];
            AdxDecodeParams_u1 decode;
        } view_decode;
        struct {
            unsigned char padding_decoded_samples[140];
            int decoded_samples;
        } view_decoded_samples;
        struct {
            unsigned char padding_decoded_data_length[136];
            int decoded_data_length;
        } view_decoded_data_length;
        struct {
            unsigned char padding_format_type[152];
            short format_type;
        } view_format_type;
        struct {
            unsigned char padding_codec_type[154];
            short codec_type;
        } view_codec_type;
    } fields;
} AdxBasicDecoder_u1;

int fn_80043B48(AdxBasicDecoder_u1 *d, signed char *input, int length);

void *fn_80043D34(void *, int *, int *, int *, int *);


int fn_80043B48(AdxBasicDecoder_u1 *d, signed char *input, int length) {
    short data_length;
    int samples, bits, channels, rate, result;
    signed char *data;
    d->fields.view_header_decoded.header_decoded = 1;
    if (length < 4096) {
        data_length = 0;
        result = -1;
    } else {
        data = fn_80043D34(input, &rate, &channels, &bits, &samples);
        if (data == ((void *)0)) {
            result = -1;
        } else {
            data_length = data - input;
            if (data_length <= 0) {
                result = -1;
            } else {
                d->fields.view_sample_rate.sample_rate = rate;
                d->fields.view_channel_count.channel_count = channels;
                d->fields.view_bits_per_sample.bits_per_sample = bits;
                d->fields.view_total_samples.total_samples = samples;
                d->fields.view_encoding.encoding = -1;
                d->fields.view_block_length.block_length =
                    d->fields.view_channel_count.channel_count *
                    d->fields.view_bits_per_sample.bits_per_sample / 8;
                d->fields.view_samples_per_block.samples_per_block = 1;
                result = 0;
            }
        }
    }
    if (result < 0)
        return 0;
    d->fields.view_coefficient.coefficient = 0;
    d->fields.view_loop_count.loop_count = d->fields.view_loop_type.loop_type = 0;
    d->fields.view_loop_end_offset.loop_end_offset =
        d->fields.view_loop_end_sample.loop_end_sample =
            d->fields.view_loop_start_offset.loop_start_offset =
                d->fields.view_loop_start_sample.loop_start_sample =
                    d->fields.view_loop_insert_samples.loop_insert_samples = 0;
    d->fields.view_decode.decode.fields.view_channel_count.channel_count =
        d->fields.view_channel_count.channel_count;
    d->fields.view_decode.decode.fields.view_block_size.block_size =
        d->fields.view_block_length.block_length;
    d->fields.view_decode.decode.fields.view_samples_per_block.samples_per_block =
        d->fields.view_samples_per_block.samples_per_block;
    d->fields.view_decode.decode.fields.view_pcm_buffer.pcm_buffer =
        d->fields.view_pcm_buffer.pcm_buffer;
    d->fields.view_decode.decode.fields.view_pcm_size.pcm_size = d->fields.view_pcm_size.pcm_size;
    d->fields.view_decode.decode.fields.view_pcm_distance.pcm_distance =
        d->fields.view_pcm_distance.pcm_distance;
    d->fields.view_decoded_data_length.decoded_data_length =
        d->fields.view_decoded_samples.decoded_samples = 0;
    d->fields.view_format_type.format_type = 3;
    if (d->fields.view_bits_per_sample.bits_per_sample == 8)
        d->fields.view_codec_type.codec_type = 1;
    else
        d->fields.view_codec_type.codec_type = 0;
    return data_length;
}

/* --- dol/fn_80043CCC.c --- */
extern u32 fn_8008023C(u32, u32, u32);
extern u32 lbl_80090080[];
extern u32 lbl_80090088[];

s32 fn_80043CCC(u32 arg0) {
    u32 v0;
    if ((s32)fn_8008023C(arg0, (u32)&lbl_80090080, 4) == 0 && (s32)fn_8008023C((arg0 + 8), (u32)&lbl_80090088, 4) == 0) {
    v0 = 1;
    } else {
    v0 = 0;
    }
    return v0;
}
