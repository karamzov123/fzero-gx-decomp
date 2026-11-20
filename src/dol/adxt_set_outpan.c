#include "types.h"


/* --- dol/adxt_set_outpan.c --- */
typedef struct SJCK {
    unsigned char *data;
    int len;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface SJInterface;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface {
    void *reserved[3];
    void (*destroy)(SJ *sj);
    const void *(*get_uuid)(SJ *sj);
    void (*reset)(SJ *sj);
    void (*get_chunk)(SJ *sj, int channel, int max_size, SJCK *chunk);
    void (*unget_chunk)(SJ *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
    int (*get_num_data)(SJ *sj, int channel);
    int (*is_get_chunk)(SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ *sj, SJErrorCallback callback, void *object);
};

struct SJ {
    const SJInterface *interface;
};

typedef struct AdxSjdHandle AdxSjdHandle;

typedef struct ADXStream ADXStream;

typedef struct AXRNAHandle AXRNAHandle;

typedef struct LSCObject LSCObject;

typedef struct ADX_AMP ADX_AMP;

typedef struct ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    AdxSjdHandle *decoder;
    ADXStream *stream;
    AXRNAHandle *rna;
    SJ *stream_sj;
    SJ *input_sj;
    SJ *output_sj[2];
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
    SJ *amplifier_input[2];
    SJ *amplifier_output[2];
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
} ADXTHandle;

extern s32 fn_80041660(AdxSjdHandle *decoder);

extern s16 fn_80041460(AdxSjdHandle *decoder, s32 channel);

extern void ADXSJD_EntryTrapFunc(AdxSjdHandle *decoder, void (*callback)(void *object),
                                 void *object);

extern void ADXSTM_EntryEosFunc(ADXStream *stream, void (*callback)(void *object), void *object);

extern void fn_8004EDC4(AXRNAHandle *rna, s32 channel, s32 pan);

void adxt_set_outpan(ADXTHandle *handle) {
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

extern void fn_800416DC(AdxSjdHandle *decoder, s32 samples);

extern void ADXSJD_EntryTrapFunc(AdxSjdHandle *decoder, void (*callback)(void *object),
                                 void *object);

extern void fn_8004AC04(ADXStream *stream, s32 sector);


extern s32 fn_8004AE94(ADXStream *stream, s32 sector);

void adxt_eos_entry(void *object) {
    ADXTHandle *handle = (ADXTHandle *)object;
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
