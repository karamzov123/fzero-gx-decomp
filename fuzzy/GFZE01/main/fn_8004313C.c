/* Non-matching: best partial attempt (96.10% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

/* ADX_DecodeInfoWav, from the CC0 MK Deception decomp (adx_bwav.c) */

typedef struct WaveFormatEx {
    unsigned short format_tag;
    unsigned short channel_count;
    unsigned int samples_per_second;
    unsigned int average_bytes_per_second;
    unsigned short block_align;
    unsigned short bits_per_sample;
    unsigned short extra_size;
} WaveFormatEx;

extern int fn_8008023C(const void *a, const void *b, unsigned long n);
extern signed char *lbl_8012B6F0[];
extern signed char *lbl_8012B6F4[];

#define ADXB_SWAP_WAV16(value) \
    ((((value) >> 8) & 0xFF) | (((value) & 0xFF) << 8))

static inline unsigned int ADXB_SwapWav32(unsigned int value)
{
    return value >> 24 | (value >> 8 & 0xFF00) |
           (value << 8 & 0xFF0000) | value << 24;
}

#pragma use_lmw_stmw on
int fn_8004313C(unsigned char* input, int input_length,
                short* data_length, signed char* encoding,
                signed char* bits_per_sample, signed char* block_length,
                signed char* channel_count, int* sample_rate,
                int* total_samples, int* samples_per_block,
                short* codec_type)
{
    WaveFormatEx* format;
    int i;
    int wav_size;

    for (i = 0; i < input_length; i++) {
        if (fn_8008023C(&input[i], lbl_8012B6F0[0], 4) == 0) {
            break;
        }
    }

    if (i == input_length) {
        return -1;
    }

    if (i % 4 != 0) {
        return -1;
    }

    format = (WaveFormatEx*)&input[i + 8];

    if ((short)ADXB_SWAP_WAV16(format->format_tag) > 1) {
        return -1;
    }

    for (i = 0; i < input_length; i++) {
        if (fn_8008023C(&input[i], lbl_8012B6F4[0], 4) == 0) {
            break;
        }
    }

    if (i == input_length) {
        return -1;
    }

    wav_size = ADXB_SwapWav32(
        *(unsigned int*)&input[i + 4]);

    *data_length = i + 8;
    *encoding = -1;

    *sample_rate = ADXB_SwapWav32(format->samples_per_second);
    *channel_count = ADXB_SWAP_WAV16(format->channel_count);
    *bits_per_sample = ADXB_SWAP_WAV16(format->bits_per_sample);
    *block_length = ADXB_SWAP_WAV16(format->block_align);
    *total_samples = wav_size / *block_length;
    *samples_per_block = 1;

    if (*bits_per_sample == 16) {
        *codec_type = 0;
    } else if (*bits_per_sample == 8) {
        *codec_type = 1;
    } else if (*bits_per_sample == 4) {
        *block_length = *channel_count * 2;
        *samples_per_block = 4;
        *total_samples = (wav_size / 2) / *channel_count;
        *bits_per_sample = 16;
        *codec_type = 2;
    }

    if (*bits_per_sample == 0) {
        return -1;
    }

    if (*block_length == 0) {
        return -1;
    }

    if (*channel_count <= 0 || *channel_count > 2) {
        return -1;
    }

    return *sample_rate == 0 ? -1 : 0;
}
