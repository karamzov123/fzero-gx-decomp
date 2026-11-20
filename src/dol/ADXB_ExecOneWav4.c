#include "types.h"


/* --- dol/ADXB_ExecOneWav4.c --- */
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

void ADXB_ExecOneWav4(AdxBasicDecoder *decoder) {
    AdxDecodeParams *params;
    unsigned short *pcm;
    unsigned short *left;
    unsigned short *right;
    const unsigned char *input;
    int i;
    int count;
    params = &decoder->decode;
    input = (const unsigned char *)params->input;
    if (decoder->status == 1 && fn_8004E270(decoder->expander) == 0) {
        decoder->get_write_info(decoder->get_write_object, &params->write_position, &params->room,
                                &params->loop_samples);
        count = params->pcm_size - params->write_position;
        if (count > params->room) {
            count = params->room;
        }
        if (count > params->input_blocks) {
            count = params->input_blocks;
        }
        pcm = (unsigned short *)params->pcm_buffer;
        left = &pcm[params->write_position];
        if (decoder->channel_count == 2) {
            right = &pcm[params->pcm_distance + params->write_position];
            for (i = 0; i < count; i++) {
                left[i] = input[i * 4] | input[i * 4 + 2] * 256;
                right[i] = input[i * 4 + 1] | input[i * 4 + 3] * 256;
            }
        } else {
            for (i = 0; i < count; i++) {
                left[i] = input[i * 2] | input[i * 2 + 1] * 256;
            }
        }
        decoder->decoded_samples = count;
        decoder->decoded_data_length = count * 2 * decoder->channel_count;
        decoder->status = 2;
    }
    if (decoder->status == 2) {
        decoder->add_write_info(decoder->add_write_object, decoder->decoded_data_length,
                                decoder->decoded_samples);
        decoder->status = 3;
    }
}

/* --- dol/ADXB_ExecOneWav8.c --- */
int fn_8004E270(AdxXpnd *decoder);

void ADXB_ExecOneWav8(AdxBasicDecoder *decoder) {
    AdxDecodeParams *params;
    unsigned short *pcm;
    unsigned short *left;
    unsigned short *right;
    const unsigned char *input;
    int i;
    int count;
    params = &decoder->decode;
    input = (const unsigned char *)params->input;
    if (decoder->status == 1 && fn_8004E270(decoder->expander) == 0) {
        decoder->get_write_info(decoder->get_write_object, &params->write_position, &params->room,
                                &params->loop_samples);
        count = params->pcm_size - params->write_position;
        if (count > params->room) {
            count = params->room;
        }
        if (count > params->input_blocks) {
            count = params->input_blocks;
        }
        pcm = (unsigned short *)params->pcm_buffer;
        left = &pcm[params->write_position];
        if (decoder->channel_count == 2) {
            right = &pcm[params->pcm_distance + params->write_position];
            for (i = 0; i < count; i++) {
                left[i] = (input[i * 2] - 128) * 256;
                right[i] = (input[i * 2 + 1] - 128) * 256;
            }
        } else {
            for (i = 0; i < count; i++) {
                left[i] = (input[i] - 128) * 256;
            }
        }
        decoder->decoded_samples = count;
        decoder->decoded_data_length = count * decoder->channel_count;
        decoder->status = 2;
    }
    if (decoder->status == 2) {
        decoder->add_write_info(decoder->add_write_object, decoder->decoded_data_length,
                                decoder->decoded_samples);
        decoder->status = 3;
    }
}
