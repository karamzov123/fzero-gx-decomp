#include "types.h"


/* --- dol/ADXB_ExecOneAuUlaw.c --- */
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

int fn_8004E270(AdxXpnd *decoder);

extern short lbl_8012B6F8[256];

void ADXB_ExecOneAuUlaw(AdxBasicDecoder *d) {
    AdxDecodeParams *dp = &d->decode;
    unsigned char *input = (unsigned char *)dp->input;
    unsigned short *pcm, *left, *right;
    int i, count;
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

/* --- dol/fn_800443AC.c --- */
int fn_8004E270(AdxXpnd *decoder);

void fn_800443AC(AdxBasicDecoder *d) {
    AdxDecodeParams *dp;
    unsigned char *input;
    unsigned short *pcm, *left, *right;
    int i, count;
    dp = &d->decode;
    input = (unsigned char *)dp->input;
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
