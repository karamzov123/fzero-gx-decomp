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
    short codec_type;
} AdxBasicDecoder;

typedef struct SpsdHeader {
    u8 pad_0[0x7];
    u8 data_offset;
    u8 bit_size;
    u8 channel_flags;
    u8 pad_A[0x2];
    s32 data_size;
    u8 pad_10[0x1A];
    u16 sample_rate;
} SpsdHeader;

extern int fn_8008023C(const void *a, const void *b, u32 size);
extern int ADXPD_GetStat(AdxXpnd *expander);

int ADX_DecodeInfoSpsd(SpsdHeader *header, int size, short *data_offset, signed char *encoding, signed char *bits,
                signed char *block_align, signed char *channels, int *sample_rate, int *sample_count,
                int *samples_per_block, short *codec);

int ADXB_CheckSpsd(const signed char *input) {
    return fn_8008023C(input, "SPSD", 4) == 0;
}

void ADXB_ExecOneSpsd(AdxBasicDecoder *decoder) {
    AdxDecodeParams *params;
    short *pcm;
    short *left;
    short *right;
    const unsigned short *input;
    int i;
    int count;

    params = &decoder->decode;
    input = params->input;
    if (decoder->status == 1 && ADXPD_GetStat(decoder->expander) == 0) {
        decoder->get_write_info(decoder->get_write_object, &params->write_position, &params->room,
                                &params->loop_samples);
        count = params->pcm_size - params->write_position;
        if (count > params->room) count = params->room;
        if (count > params->input_blocks) count = params->input_blocks;
        pcm = params->pcm_buffer;
        left = &pcm[params->write_position];
        if (decoder->channel_count == 2) {
            right = &pcm[params->pcm_distance + params->write_position];
            for (i = 0; i < count; i++) {
                left[i] = input[i * 2];
                right[i] = input[i * 2 + 1];
            }
        } else {
            for (i = 0; i < count; i++) left[i] = input[i];
        }
        decoder->decoded_samples = count;
        decoder->decoded_data_length = decoder->channel_count * (count << 1);
        decoder->status = 2;
    }
    if (decoder->status == 2) {
        decoder->add_write_info(decoder->add_write_object, decoder->decoded_data_length,
                                decoder->decoded_samples);
        decoder->status = 3;
    }
}

int ADXB_DecodeHeaderSpsd(AdxBasicDecoder *decoder, SpsdHeader *input, u32 input_length) {
    short data_length;

    decoder->header_decoded = 1;
    if (ADX_DecodeInfoSpsd(input, input_length, &data_length, &decoder->encoding, &decoder->bits_per_sample,
                    &decoder->block_length, &decoder->channel_count, &decoder->sample_rate,
                    &decoder->total_samples, &decoder->samples_per_block, &decoder->codec_type) < 0) {
        return 0;
    }
    decoder->coefficient = 0;
    decoder->loop_type = 0;
    decoder->loop_count = 0;
    decoder->loop_end_offset = 0;
    decoder->loop_end_sample = 0;
    decoder->loop_start_offset = 0;
    decoder->loop_start_sample = 0;
    decoder->loop_insert_samples = 0;
    decoder->decode.channel_count = decoder->channel_count;
    decoder->decode.block_size = decoder->block_length;
    decoder->decode.samples_per_block = decoder->samples_per_block;
    decoder->decode.pcm_buffer = decoder->pcm_buffer;
    decoder->decode.pcm_size = decoder->pcm_size;
    decoder->decode.pcm_distance = decoder->pcm_distance;
    decoder->current_write_position = 0;
    decoder->total_decoded_samples = 0;
    decoder->format_type = 2;
    return data_length;
}

/* WARNING: compiler-diff device, not original code: the 7450 scheduling model orders the stack
   argument loads before the data offset store as retail does; no source order found reproduces it. */
#pragma scheduling 7450
int ADX_DecodeInfoSpsd(SpsdHeader *header, int size, short *data_offset, signed char *encoding, signed char *bits,
                signed char *block_align, signed char *channels, int *sample_rate, int *sample_count,
                int *samples_per_block, short *codec) {
    unsigned char bit_size;

    *data_offset = header->data_offset * 16;
    *channels = (header->channel_flags & 3) + 1;
    *sample_rate = header->sample_rate;
    bit_size = header->bit_size;
    switch (bit_size) {
    case 0:
        *bits = 16;
        *block_align = *channels * 2;
        *samples_per_block = 1;
        *sample_count = header->data_size / 2;
        *codec = 0;
        break;
    case 1:
        *bits = 8;
        *block_align = *channels;
        *samples_per_block = 1;
        *sample_count = header->data_size;
        *codec = 1;
        break;
    case 2:
    case 3:
        *bits = 4;
        *block_align = *channels;
        *samples_per_block = 2;
        *sample_count = header->data_size * 2;
        *codec = 2;
        break;
    }
    *block_align = 2;
    *samples_per_block = 1;
    *sample_count = header->data_size / 2;
    *bits = 16;
    *encoding = -1;
    return 0;
}
#pragma scheduling reset
