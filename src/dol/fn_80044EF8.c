#include "types.h"

#pragma use_lmw_stmw on

typedef void (*AdxGetWriteInfo)(void *, s32 *, s32 *, s32 *);
typedef void (*AdxAddWriteInfo)(void *, s32, s32);

typedef struct AdxDecodeParams {
    const u16 *input;
    s32 input_blocks;
    s32 channel_count;
    s32 block_size;
    s32 samples_per_block;
    s16 *pcm_buffer;
    s32 pcm_size;
    s32 pcm_distance;
    s32 write_position;
    s32 room;
    s32 loop_samples;
} AdxDecodeParams;

typedef struct AdxBasicDecoder {
    s16 used;
    s16 header_decoded;
    s32 status;
    void *expander;
    u8 pad_c[0x3c - 0xc];
    s16 *pcm_buffer;
    s32 pcm_size;
    s32 pcm_distance;
    AdxDecodeParams decode;
    s32 field_74;
    AdxGetWriteInfo get_write_info;
    void *get_write_object;
    AdxAddWriteInfo add_write_info;
    void *add_write_object;
    s32 total_decoded_samples;
    s32 current_write_position;
    s32 decoded_samples;
    s32 decoded_data_length;
} AdxBasicDecoder;

extern s32 fn_8004E270(void *xpd);
extern void fn_8004E204(void *xpd, const u16 *input, s32 blocks, s16 *left, s16 *right);
extern void fn_8004E1E4(void *xpd);
extern void fn_8004E238(void *xpd, const u16 *input, s32 blocks, s16 *output);
extern void ADXPD_ExecHndl(void *xpd);
extern s32 fn_8004E190(void *xpd);
extern void fn_8004E198(void *xpd);

static inline void adxb_CopySamples(s16 *output, const s16 *extra, s32 count)
{
    for (; count > 0; count--) {
        *output++ = *extra++;
    }
}

static inline void adxb_EntrySte(AdxBasicDecoder *base, s32 blocks)
{
    AdxDecodeParams *params = &base->decode;
    s16 *output;
    void *expander;

    output = params->pcm_buffer;
    output += params->write_position;
    expander = base->expander;
    fn_8004E204(expander, params->input, blocks * 2, output, &output[params->pcm_distance]);
    fn_8004E1E4(expander);
}

static inline void adxb_EntryMono(AdxBasicDecoder *base, s32 blocks)
{
    AdxDecodeParams *params = &base->decode;
    s16 *output;
    void *expander;

    output = params->pcm_buffer;
    output += params->write_position;
    expander = base->expander;
    fn_8004E238(expander, params->input, blocks, output);
    fn_8004E1E4(expander);
}

static inline void adxb_EvokeDecode(AdxBasicDecoder *base)
{
    AdxDecodeParams *params;
    s32 loop_position;
    s32 delete_samples;
    s32 room;
    s32 end_blocks;
    s32 end_samples;
    s32 write_position;
    s32 input_blocks;
    s32 block_samples;
    s32 end_capacity;

    params = &base->decode;
    block_samples = params->samples_per_block;
    write_position = params->write_position;
    room = params->room;
    input_blocks = params->input_blocks / params->channel_count;
    loop_position = params->loop_samples;

    delete_samples = (loop_position + block_samples - 1) / block_samples;
    end_samples = loop_position + block_samples - 1;
    end_samples %= block_samples;
    end_samples = block_samples - 1 - end_samples;
    end_blocks = (params->pcm_size - write_position + block_samples - 1) / block_samples;
    end_capacity = end_blocks * block_samples;
    if (delete_samples < end_blocks && write_position + end_capacity - end_samples < params->pcm_size) {
        end_blocks++;
    }
    if (loop_position < room) {
        room += end_samples;
    }
    if (input_blocks > room / block_samples) {
        input_blocks = room / block_samples;
    }
    if (input_blocks > delete_samples) input_blocks = delete_samples;
    if (input_blocks > end_blocks) input_blocks = end_blocks;

    if (base->decode.channel_count == 2) {
        adxb_EntrySte(base, input_blocks);
    } else {
        adxb_EntryMono(base, input_blocks);
    }
}

static inline void adxb_FinishDecode(AdxBasicDecoder *base)
{
    AdxDecodeParams *params = &base->decode;
    s32 block_samples;
    s32 block_size;
    s32 loop_samples;
    s16 *pcm_buffer;
    s32 write_position;
    s32 pcm_size;
    s32 pcm_distance;
    s32 decoded_blocks;
    s32 decoded_samples;
    s32 trailing_samples;
    s32 copy_count;
    s16 *copy_source;

    block_samples = params->samples_per_block;
    block_size = params->block_size;
    loop_samples = params->loop_samples;
    write_position = params->write_position;
    pcm_buffer = params->pcm_buffer;
    pcm_size = base->pcm_size;
    pcm_distance = base->pcm_distance;

    trailing_samples = block_samples - 1 - (loop_samples + block_samples - 1) % block_samples;
    loop_samples = (loop_samples + block_samples - 1) / block_samples;
    decoded_blocks = fn_8004E190(base->expander);
    decoded_samples = decoded_blocks * block_samples / params->channel_count;
    if (loop_samples * params->channel_count <= decoded_blocks) {
        decoded_samples -= trailing_samples;
    }
    base->decoded_samples = decoded_samples;
    base->decoded_data_length = decoded_blocks * block_size;
    write_position += decoded_samples;
    if (write_position >= pcm_size) {
        write_position -= pcm_size;
        if (params->channel_count == 2) {
            adxb_CopySamples(pcm_buffer, &pcm_buffer[pcm_size], write_position);
            adxb_CopySamples(&pcm_buffer[pcm_distance], &pcm_buffer[pcm_distance + pcm_size], write_position);
        } else {
            copy_count = write_position;
            copy_source = &pcm_buffer[pcm_size];
            while (copy_count-- > 0) {
                *pcm_buffer++ = *copy_source++;
            }
        }
    }
    fn_8004E198(base->expander);
    base->add_write_info(base->add_write_object, base->decoded_data_length, base->decoded_samples);
    base->status = 3;
}

void fn_80044EF8(AdxBasicDecoder *base)
{
    AdxDecodeParams *params = &base->decode;

    if (base->status == 1 && fn_8004E270(base->expander) == 0) {
        base->get_write_info(base->get_write_object, &params->write_position, &params->room,
                             &params->loop_samples);
        adxb_EvokeDecode(base);
        base->status = 2;
    }
    if (base->status == 2) {
        ADXPD_ExecHndl(base->expander);
        if (fn_8004E270(base->expander) == 3) {
            adxb_FinishDecode(base);
        }
    }
}
