
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

void fn_80042D24(AdxBasicDecoder *decoder);

int fn_8004E270(AdxXpnd *decoder);

void fn_80042D24(AdxBasicDecoder *decoder) {
    const unsigned short *input;
    unsigned short *left;
    unsigned short *right;
    int i;
    int count;
    input = decoder->decode.input;
    if (decoder->status == 1 && fn_8004E270(decoder->expander) == 0) {
        decoder->get_write_info(decoder->get_write_object, &decoder->decode.write_position,
                                &decoder->decode.room, &decoder->decode.loop_samples);
        count = decoder->decode.pcm_size - decoder->decode.write_position;
        if (count > decoder->decode.room) {
            count = decoder->decode.room;
        }
        if (count > decoder->decode.input_blocks) {
            count = decoder->decode.input_blocks;
        }
        left = (unsigned short *)decoder->decode.pcm_buffer + decoder->decode.write_position;
        if (decoder->channel_count == 2) {
            right = (unsigned short *)decoder->decode.pcm_buffer +
                    (decoder->decode.pcm_distance + decoder->decode.write_position);
            for (i = 0; i < count; i++) {
                left[i] = ((((input[i * 2]) >> 8) & 0xFF) | (((input[i * 2]) & 0xFF) << 8));
                right[i] =
                    ((((input[i * 2 + 1]) >> 8) & 0xFF) | (((input[i * 2 + 1]) & 0xFF) << 8));
            }
        } else {
            for (i = 0; i < count; i++) {
                left[i] = ((((input[i]) >> 8) & 0xFF) | (((input[i]) & 0xFF) << 8));
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
