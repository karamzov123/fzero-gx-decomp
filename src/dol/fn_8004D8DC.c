#include "types.h"


/* --- dol/fn_8004D8DC.c --- */
typedef struct SJCK {
    u8 *data;
    u32 len;
} SJCK;

typedef struct SJ_u0 SJ_u0;

typedef struct SJInterface {
    u8 pad_0[0x18];
    void (*get_chunk)(SJ_u0 *sj, int channel, int max_size, SJCK *chunk);
    void (*unget_chunk)(SJ_u0 *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ_u0 *sj, int channel, SJCK *chunk);
} SJInterface;

struct SJ_u0 {
    const SJInterface *interface;
};

typedef struct AdxSjdHandle AdxSjdHandle;

typedef struct ADXTHandle {
    u8 pad_0[4];
    AdxSjdHandle *decoder;
    u8 pad_8[0xC];
    SJ_u0 *input_sj;
    u8 pad_18[0x30];
    s32 maximum_decode_samples;
    u8 pad_4C[0x4C];
    s8 link_enabled;
    u8 pad_99[0xB];
    s32 linked_decoded_samples;
} ADXTHandle;

extern s32 fn_80046804(void *data, u32 len, s16 *out_len);
extern s32 ADX_ScanInfoCode(signed char *buffer, int buffer_len, short *data_len);
extern void fn_800589BC(const SJCK *source, s32 nbyte, SJCK *first, SJCK *remainder);
extern u32 fn_800416F8(AdxSjdHandle *decoder);
extern void fn_800420F4(AdxSjdHandle *decoder);
extern void fn_8004212C(AdxSjdHandle *decoder);
extern void fn_80041990(AdxSjdHandle *decoder);
extern s32 fn_800421C0(AdxSjdHandle *decoder);
extern void fn_80042170(AdxSjdHandle *decoder, s32 samples);
extern s32 fn_800415F4(AdxSjdHandle *decoder);
extern void fn_800416DC(AdxSjdHandle *decoder, s32 samples);
extern void fn_800416CC(AdxSjdHandle *decoder, s32 enabled);
extern void fn_800416D4(AdxSjdHandle *decoder, s32 length);

void fn_8004D8DC(ADXTHandle *handle) {
    void (* fzgx_live_)(SJ_u0 *sj, int channel, int max_size, SJCK *chunk);
    const SJInterface * fzgx_live;
    AdxSjdHandle *decoder = handle->decoder;
    SJ_u0 *input = handle->input_sj;
    SJCK chunk1;
    SJCK remainder1;
    SJCK chunk2;
    SJCK remainder2;
    s16 info1;
    s16 info2;
    s32 nbyte;
    s32 scan1;
    s32 scan2;
    s32 link_off;

    if (handle->link_enabled == 0) {
        return;
    }
    info2 = 0;
    fzgx_live = input->interface;
    fzgx_live_ = fzgx_live->get_chunk;
    fzgx_live_(input, 1, 0x7FFFFFFF, &chunk1);
    fzgx_live = input->interface;
    fzgx_live_ = fzgx_live->get_chunk;
    fzgx_live_(input, 1, 0x7FFFFFFF, &chunk2);
    if (fn_80046804(chunk1.data, chunk1.len, &info1) != 0) {
        handle->link_enabled = 0;
        fzgx_live = input->interface;
        fzgx_live->unget_chunk(input, 1, &chunk2);
        fzgx_live = input->interface;
        fzgx_live->unget_chunk(input, 1, &chunk1);
        return;
    }
    nbyte = info1;
    scan1 = ADX_ScanInfoCode((signed char *)chunk1.data + nbyte, chunk1.len - nbyte, &info1);
    if (scan1 == 0) {
        scan2 = -1;
    } else {
        scan2 = ADX_ScanInfoCode((signed char *)chunk2.data, chunk2.len, &info2);
    }
    nbyte = nbyte + info1;
    link_off = (s16)(info2);
    if (scan1 != 0 && scan2 != 0) {
        fzgx_live = input->interface;
        fzgx_live->unget_chunk(input, 1, &chunk2);
        fzgx_live = input->interface;
        fzgx_live->unget_chunk(input, 1, &chunk1);
        handle->link_enabled = 0;
        return;
    }
    if (scan1 == 0) {
        fzgx_live = input->interface;
        fzgx_live->unget_chunk(input, 1, &chunk2);
        fn_800589BC(&chunk1, nbyte, &chunk1, &remainder1);
        fzgx_live = input->interface;
        fzgx_live->put_chunk(input, 0, &chunk1);
        fzgx_live = input->interface;
        fzgx_live->unget_chunk(input, 1, &remainder1);
    } else {
        fzgx_live = input->interface;
        fzgx_live->put_chunk(input, 0, &chunk1);
        fn_800589BC(&chunk2, link_off, &chunk2, &remainder2);
        fzgx_live = input->interface;
        fzgx_live->put_chunk(input, 0, &chunk2);
        fzgx_live = input->interface;
        fzgx_live->unget_chunk(input, 1, &remainder2);
    }
    handle->linked_decoded_samples += fn_800416F8(decoder);
    fn_800420F4(decoder);
    fn_8004212C(decoder);
    fn_80041990(decoder);
    if (fn_800421C0(decoder) != 2) {
        handle->link_enabled = 0;
        return;
    }
    fn_80042170(decoder, handle->maximum_decode_samples);
    fn_800416DC(decoder, fn_800415F4(decoder));
    fn_800416CC(decoder, 0);
    fn_800416D4(decoder, 0);
}

/* --- dol/adxt_set_outpan.c --- */
/* --- dol/adxt_set_outpan.c --- */
typedef struct SJCK_u1 {
    unsigned char *data;
    int len;
} SJCK_u1;

typedef struct SJ_u1 SJ_u1;

typedef struct SJInterface_u1 SJInterface_u1;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface_u1 {
    void *reserved[3];
    void (*destroy)(SJ_u1 *sj);
    const void *(*get_uuid)(SJ_u1 *sj);
    void (*reset)(SJ_u1 *sj);
    void (*get_chunk)(SJ_u1 *sj, int channel, int max_size, SJCK_u1 *chunk);
    void (*unget_chunk)(SJ_u1 *sj, int channel, SJCK_u1 *chunk);
    void (*put_chunk)(SJ_u1 *sj, int channel, SJCK_u1 *chunk);
    int (*get_num_data)(SJ_u1 *sj, int channel);
    int (*is_get_chunk)(SJ_u1 *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ_u1 *sj, SJErrorCallback callback, void *object);
};

struct SJ_u1 {
    const SJInterface_u1 *interface;
};


typedef struct ADXStream ADXStream;

typedef struct AXRNAHandle AXRNAHandle;

typedef struct LSCObject LSCObject;

typedef struct ADX_AMP ADX_AMP;

typedef struct ADXTHandle_u1 {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    AdxSjdHandle *decoder;
    ADXStream *stream;
    AXRNAHandle *rna;
    SJ_u1 *stream_sj;
    SJ_u1 *input_sj;
    SJ_u1 *output_sj[2];
    u8 *input_buffer;
    s32 input_buffer_size;
    s32 input_extra_size;
    u8 *output_buffer;
    s32 output_buffer_size;
    s32 output_buffer_distance;
    s32 server_frequency;
    s16 stream_buffer_sectors;
    s16 minimum_buffer_sectors;
    s16 output_volume;
    s16 output_pan[2];
    s16 field_46;
    s32 maximum_decode_samples;
    s32 loop_count;
    s32 link_data_length;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s16 error_code;
    u8 reserved_62[2];
    s32 field_64;
    s16 field_68;
    s16 field_6A;
    s8 stream_loop_enabled;
    s8 auto_receiver;
    u8 reserved_6E[2];
    s8 suppress_playback;
    s8 decoder_ready;
    s8 paused;
    u8 reserved_73;
    ADX_AMP *amplifier;
    SJ_u1 *amplifier_input[2];
    SJ_u1 *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    LSCObject *linked_stream_controller;
    s8 link_enabled;
    u8 reserved_99[3];
    u32 playback_time;
    s32 playback_start_vsync;
    s32 linked_decoded_samples;
    s8 pending_stream_start;
    u8 reserved_A9[3];
    u8 *work_end;
    const char *pending_filename;
    void *pending_directory;
    s32 pending_file_offset;
    s32 pending_file_sectors;
} ADXTHandle_u1;

extern s32 fn_80041660(AdxSjdHandle *decoder);

extern s16 fn_80041460(AdxSjdHandle *decoder, s32 channel);

extern void ADXSJD_EntryTrapFunc(AdxSjdHandle *decoder, void (*callback)(void *object),
                                 void *object);

extern void ADXSTM_EntryEosFunc(ADXStream *stream, void (*callback)(void *object), void *object);

extern void fn_8004EDC4(AXRNAHandle *rna, s32 channel, s32 pan);

void adxt_set_outpan(ADXTHandle_u1 *handle) {
    s32 default_pan[2];
    s32 channel_count;
    s32 channel;
    s32 pan;
    channel_count = fn_80041660(handle->decoder);
    for (channel = 0; channel < 2; channel++) {
        default_pan[channel] = fn_80041460(handle->decoder, channel);
    }
    if (channel_count == 1) {
        pan = handle->output_pan[0];
        if (pan == -128 && default_pan[0] == -128) {
            fn_8004EDC4(handle->rna, 0, 0);
        } else if (pan != -128 && default_pan[0] == -128) {
            fn_8004EDC4(handle->rna, 0, pan);
        } else if (pan == -128 && default_pan[0] != -128) {
            fn_8004EDC4(handle->rna, 0, default_pan[0]);
        } else {
            fn_8004EDC4(handle->rna, 0, pan + default_pan[0]);
        }
        return;
    }
    pan = handle->output_pan[0];
    if (pan == -128 && default_pan[0] == -128) {
        fn_8004EDC4(handle->rna, 0, -15);
    } else if (pan != -128 && default_pan[0] == -128) {
        fn_8004EDC4(handle->rna, 0, pan);
    } else if (pan == -128 && default_pan[0] != -128) {
        fn_8004EDC4(handle->rna, 0, default_pan[0]);
    } else {
        fn_8004EDC4(handle->rna, 0, pan + default_pan[0]);
    }
    pan = handle->output_pan[1];
    if (pan == -128 && default_pan[1] == -128) {
        fn_8004EDC4(handle->rna, 1, 15);
    } else if (pan != -128 && default_pan[1] == -128) {
        fn_8004EDC4(handle->rna, 1, pan);
    } else if (pan == -128 && default_pan[1] != -128) {
        fn_8004EDC4(handle->rna, 1, default_pan[1]);
    } else {
        fn_8004EDC4(handle->rna, 1, pan + default_pan[1]);
    }
}

/* --- dol/adxt_eos_entry.c --- */
enum {
    ADXT_STATUS_DECODING_HEADER = 1,
    ADXT_STATUS_BUFFERING = 2,
    ADXT_STATUS_PLAYING = 3,
    ADXT_STATUS_DRAINING = 4,
    ADXT_STATUS_ERROR = 6,
    ADXT_STREAM_TYPE_FILE = 0,
    ADXT_STREAM_TYPE_RANGE = 1,
    ADXT_STREAM_TYPE_MEMORY = 2,
    ADXT_STREAM_TYPE_LINKED = 3,
    ADXSJD_STATUS_HEADER_READY = 2,
    ADXSJD_STATUS_INPUT_END = 3,
    ADXSTM_STATUS_READING = 2,
    ADXSTM_STATUS_END = 3,
    ADXSTM_STATUS_ERROR = 4,
    ADXT_SECTOR_SIZE = 0x800,
    ADXT_MIN_PLAY_DATA = 0x40
};

extern s32 fn_80041578(AdxSjdHandle *decoder);


extern void ADXSJD_EntryTrapFunc(AdxSjdHandle *decoder, void (*callback)(void *object),
                                 void *object);

extern void fn_8004AC04(ADXStream *stream, s32 sector);


extern s32 fn_8004AE94(ADXStream *stream, s32 sector);

void adxt_eos_entry(void *object) {
    ADXTHandle_u1 *handle = (ADXTHandle_u1 *)object;
    ADXStream *stream = handle->stream;
    AdxSjdHandle *decoder = handle->decoder;
    s32 loop_start_offset;
    if (stream == 0 || decoder == 0) {
        return;
    }
    loop_start_offset = fn_80041578(decoder);
    if (handle->stream_loop_enabled == 0) {
        fn_800416DC(handle->decoder, -1);
        fn_8004AC04(handle->stream, 0x7FFFFFFF);
    } else {
        fn_8004AE94(stream, loop_start_offset / ADXT_SECTOR_SIZE);
    }
}
