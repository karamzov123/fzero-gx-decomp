
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
