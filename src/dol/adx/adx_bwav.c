#include "types.h"
#include "dol/data/lbl_8012B6F0.h"
#include "dol/data/lbl_8012B6F4.h"

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

typedef struct {
    u16 formatTag;
    u16 channels;
    u32 sampleRate;
    u32 byteRate;
    u16 blockAlign;
    u16 bitsPerSample;
} WavFormat;

extern s32 memcmp(const void *, const void *, u32);
extern u32 lbl_80090070[];
extern u32 lbl_80090078[];
extern int ADXPD_GetStat(AdxXpnd *decoder);

void ADXB_ExecOneWav4(AdxBasicDecoder *decoder);
void ADXB_ExecOneWav8(AdxBasicDecoder *decoder);
void fn_80042D24(AdxBasicDecoder *decoder);
s32 fn_8004313C(u8 *buf, s32 size, s16 *dataOffset, s8 *encoding, s8 *bits, s8 *blockAlign,
                s8 *channels, s32 *sampleRate, s32 *sampleCount, s32 *samplesPerBlock,
                s16 *codec);

void fn_8004251C(AdxBasicDecoder *arg0) {
    if (arg0->field_9A == 2) {
        ADXB_ExecOneWav4(arg0);
    } else if (arg0->field_9A == 1) {
        ADXB_ExecOneWav8(arg0);
    } else if (arg0->field_9A == 0) {
        fn_80042D24(arg0);
    }
}

s32 fn_80042568(const void *arg0) {
    u32 v0;
    if (memcmp(arg0, &lbl_80090070, 4) == 0 &&
        memcmp((const u8 *)arg0 + 8, &lbl_80090078, 4) == 0) {
        v0 = 1;
    } else {
        v0 = 0;
    }
    return v0;
}

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
    if (decoder->status == 1 && ADXPD_GetStat(decoder->expander) == 0) {
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
    if (decoder->status == 1 && ADXPD_GetStat(decoder->expander) == 0) {
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

void fn_80042D24(AdxBasicDecoder *decoder) {
    const unsigned short *input;
    unsigned short *left;
    unsigned short *right;
    int i;
    int count;
    input = decoder->decode.input;
    if (decoder->status == 1 && ADXPD_GetStat(decoder->expander) == 0) {
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

s16 fn_80043050(AdxBasicDecoder *arg0, u8 *arg1, s32 arg2) {
    s16 local;
    s32 result;

    arg0->header_decoded = 1;
    result = fn_8004313C(arg1, arg2, &local, &arg0->encoding, &arg0->bits_per_sample,
                         &arg0->block_length, &arg0->channel_count, (s32 *)&arg0->sample_rate,
                         (s32 *)&arg0->total_samples, (s32 *)&arg0->samples_per_block,
                         &arg0->field_9A);
    if (result < 0) {
        return 0;
    }
    arg0->coefficient = 0;
    arg0->loop_type = 0;
    arg0->loop_count = 0;
    arg0->loop_end_offset = 0;
    arg0->loop_end_sample = 0;
    arg0->loop_start_offset = 0;
    arg0->loop_start_sample = 0;
    arg0->loop_insert_samples = 0;
    arg0->decode.channel_count = arg0->channel_count;
    arg0->decode.block_size = arg0->block_length;
    arg0->decode.samples_per_block = arg0->samples_per_block;
    arg0->decode.pcm_buffer = arg0->pcm_buffer;
    arg0->decode.pcm_size = arg0->pcm_size;
    arg0->decode.pcm_distance = arg0->pcm_distance;
    arg0->current_write_position = 0;
    arg0->total_decoded_samples = 0;
    arg0->format_type = 1;
    return local;
}

#define WAV_SWAP16(x) ((((x) >> 8) & 0xFF) | (((x) & 0xFF) << 8))

/* WARNING: compiler-diff device, not original code: WAV_SWAP32 is a macro rather than a static inline
 * function only because `#pragma opt_dead_assignments off` (below) keeps the inline function's parameter
 * assignment, which changes the scratch registers of the header decode; the macro compiles exactly as the
 * inline function does without the pragma. */
#define WAV_SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | ((x) << 24))

/* WARNING: compiler-diff device, not original code: keeps the dead address compares at the start of
 * fn_8004313C alive until register allocation (see there). The body is exact with the pragma on; whether it has other dead assignments that the pragma also keeps was not checked. */
#pragma opt_dead_assignments off
s32 fn_8004313C(u8 *buf, s32 size, s16 *dataOffset, s8 *encoding, s8 *bits, s8 *blockAlign,
                s8 *channels, s32 *sampleRate, s32 *sampleCount, s32 *samplesPerBlock,
                s16 *codec) {
    WavFormat *fmt;
    s32 i;
    s32 dataSize;
    s16 *cd;
    s32 *perBlock;
    s32 *count;
    int escaped;

    /* WARNING: compiler-diff device, not original code: the three stack-passed parameters are copied into
     * locals (declared in reverse order) because the address compares below make the parameters
     * themselves address-taken; the copies keep the three loads in the entry block with retail's
     * registers (r28-r30). The honest form uses sampleCount, samplesPerBlock and codec directly. */
    count = sampleCount;
    perBlock = samplesPerBlock;
    cd = codec;
    /* WARNING: compiler-diff device, not original code: dead compares of the stack-parameter addresses,
     * kept by `#pragma opt_dead_assignments off` and deleted after register allocation, so nothing of
     * them reaches the object code. A compare of a parameter's address makes MWCC count that stack slot
     * as escaped (worst-case alias), so the final scheduler orders the three parameter loads after the
     * prologue's stmw, as retail does. Comparing two addresses (no other value) leaves the entry
     * schedule and every register as they are. CRI built ADX with a compiler build we do not have,
     * whose loads carry that dependence without help. */
    escaped = &sampleCount == &samplesPerBlock;
    escaped = (void *)&samplesPerBlock == &codec;
    for (i = 0; i < size; i++) {
        if (memcmp(&buf[i], lbl_8012B6F0.at_0, 4) == 0) {
            break;
        }
    }
    if (i == size) {
        return -1;
    }
    if (i % 4 != 0) {
        return -1;
    }
    fmt = (WavFormat *)&buf[i + 8];
    if ((s16)WAV_SWAP16(fmt->formatTag) > 1) {
        return -1;
    }
    for (i = 0; i < size; i++) {
        if (memcmp(&buf[i], lbl_8012B6F4.at_0, 4) == 0) {
            break;
        }
    }
    if (i == size) {
        return -1;
    }
    dataSize = WAV_SWAP32(*(u32 *)&buf[i + 4]);
    *dataOffset = i + 8;
    *encoding = -1;
    *sampleRate = WAV_SWAP32(fmt->sampleRate);
    *channels = WAV_SWAP16(fmt->channels);
    *bits = WAV_SWAP16(fmt->bitsPerSample);
    *blockAlign = WAV_SWAP16(fmt->blockAlign);
    *count = dataSize / *blockAlign;
    *perBlock = 1;
    if (*bits == 16) {
        *cd = 0;
    } else if (*bits == 8) {
        *cd = 1;
    } else if (*bits == 4) {
        *blockAlign = *channels * 2;
        *perBlock = 4;
        *count = dataSize / 2 / *channels;
        *bits = 16;
        *cd = 2;
    }
    if (*bits == 0) {
        return -1;
    }
    if (*blockAlign == 0) {
        return -1;
    }
    if (*channels <= 0 || *channels > 2) {
        return -1;
    }
    return *sampleRate == 0 ? -1 : 0;
}
#pragma opt_dead_assignments reset
