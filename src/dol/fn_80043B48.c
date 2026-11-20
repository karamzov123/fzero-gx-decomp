#include "types.h"


/* --- dol/fn_80043B48.c --- */
typedef struct AdxXpndParams {
    union {
        unsigned char padding_extent[20];
        struct {
            int channel_count;
        } view_channel_count;
    } fields;
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
} AdxDecodeParams;

typedef void (*AdxGetWriteInfo)(void *, int *, int *, int *);

typedef void (*AdxAddWriteInfo)(void *, int, int);

typedef struct AdxBasicDecoder {
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
            AdxDecodeParams decode;
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
} AdxBasicDecoder;

int fn_80043B48(AdxBasicDecoder *d, signed char *input, int length);

void *fn_80043D34(void *, int *, int *, int *, int *);

void *fn_80043D34(void *header, int *rate, int *channels, int *bits, int *samples);

int fn_80043B48(AdxBasicDecoder *d, signed char *input, int length) {
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
