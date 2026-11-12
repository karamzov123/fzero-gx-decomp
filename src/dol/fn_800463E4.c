#include "types.h"

/* CRI ADX: decodes the header of an "SPSD" stream (MK Deception's ADX_DecodeInfoSpsd, adx_bsps.c). */
typedef struct {
    u8 pad_0[0x7];
    u8 unk_7;
    u8 format;
    u8 channel_bits;
    u8 pad_A[0x2];
    s32 data_size;
    u8 pad_10[0x1A];
    u16 sample_rate;
} SpsdHeader;

s32 fn_800463E4(SpsdHeader *header, u32 size, s16 *data_offset, s8 *encoding, s8 *bits, s8 *block_align,
                u8 *channels, u32 *sample_rate, s32 *sample_count, u32 *samples_per_block, s16 *codec) {
    *data_offset = header->unk_7 << 4;
    *channels = (header->channel_bits & 3) + 1;
    *sample_rate = header->sample_rate;
    switch (header->format) {
    case 0:
        *bits = 16;
        *block_align = 2 * (s8)*channels;
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
        *sample_count = 2 * header->data_size;
        *codec = 2;
        break;
    }
    /* Retail overwrites the per-format results unconditionally (16-bit stereo-sized PCM). */
    *block_align = 2;
    *samples_per_block = 1;
    *sample_count = header->data_size / 2;
    *bits = 16;
    *encoding = -1;
    return 0;
}
