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

/* WARNING: compiler-diff device, not original code: keeps the dead address compares at the start of
 * fn_800463E4 alive until register allocation (see there). */
#pragma opt_dead_assignments off
s32 fn_800463E4(SpsdHeader *header, u32 size, s16 *data_offset, s8 *encoding, s8 *bits, s8 *block_align,
                u8 *channels, u32 *sample_rate, s32 *sample_count, u32 *samples_per_block, s16 *codec) {
    s16 *cd;
    u32 *per_block;
    s32 *count;
    int escaped;

    /* WARNING: compiler-diff device, not original code: the three stack-passed parameters are copied into
     * locals (declared in reverse order) because the address compares below make the parameters
     * themselves address-taken; the copies keep the three loads in the entry block with retail's
     * registers (r12, r11, r4). The honest form uses sample_count, samples_per_block and codec directly. */
    count = sample_count;
    per_block = samples_per_block;
    cd = codec;
    /* WARNING: compiler-diff device, not original code: dead compares of the stack-parameter addresses,
     * kept by `#pragma opt_dead_assignments off` and deleted after register allocation, so nothing of
     * them reaches the object code. A compare of a parameter's address makes MWCC count that stack slot
     * as escaped, so the final scheduler orders the three parameter loads as retail does (the same
     * device as fn_8004313C, its WAV sibling). Without it the honest body is 3 rows from exact. */
    escaped = (void *)&sample_count == (void *)&samples_per_block;
    escaped = (void *)&samples_per_block == (void *)&codec;
    *data_offset = header->unk_7 << 4;
    *channels = (header->channel_bits & 3) + 1;
    *sample_rate = header->sample_rate;
    switch (header->format) {
    case 0:
        *bits = 16;
        *block_align = 2 * (s8)*channels;
        *per_block = 1;
        *count = header->data_size / 2;
        *cd = 0;
        break;
    case 1:
        *bits = 8;
        *block_align = *channels;
        *per_block = 1;
        *count = header->data_size;
        *cd = 1;
        break;
    case 2:
    case 3:
        *bits = 4;
        *block_align = *channels;
        *per_block = 2;
        *count = 2 * header->data_size;
        *cd = 2;
        break;
    }
    /* Retail overwrites the per-format results unconditionally (16-bit stereo-sized PCM). */
    *block_align = 2;
    *per_block = 1;
    *count = header->data_size / 2;
    *bits = 16;
    *encoding = -1;
    return 0;
}
#pragma opt_dead_assignments reset
