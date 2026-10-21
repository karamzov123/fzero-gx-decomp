#include "types.h"

/* sfadxt_AdjustSync, from the CC0 MK Deception decomp (sfd_adxt.c) */

typedef struct SJ SJ;

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
    s16 reload_threshold_sectors;
    s16 output_volume;
    s16 output_pan[2];
    s16 output_balance;
    s32 maximum_decode_samples;
    s32 loop_count;
    s32 loop_end_sector_bytes;
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
typedef void *SfdCallbackObject;
typedef int SfdConditionValue;
typedef struct SfdHandle SfdHandle;
typedef int (*SfdUserIsSkipFn)(SfdHandle *handle, int picture_type, int value, int scale);
typedef int (*SfdTimeSourceFn)(SfdHandle *handle, int *value, int *scale);
typedef struct SfdTimerTimeUnit {
    int active;
    int fields_04[7];
    unsigned short field_20;
    unsigned short field_22;
    int value;
    int scale;
} SfdTimerTimeUnit;
typedef struct SfdTimerSkipState {
    SfdUserIsSkipFn callback;
    int fields_04[7];
    unsigned short field_20;
    unsigned short field_22;
} SfdTimerSkipState;
typedef struct SfdTimerStreamTimeUnit {
    int active;
    int field_04;
    int file_size;
    int total_time_value;
    int total_time_scale;
    int byte_rate;
    int seek_position;
    int field_1C;
    unsigned short field_20;
    unsigned short field_22;
    int value;
    int scale;
} SfdTimerStreamTimeUnit;
typedef struct SfdTimerSampleHistory {
    int fields_00[3];
    int samples[32];
} SfdTimerSampleHistory;
typedef struct SfdTimerSampleWindow {
    int enabled;
    int fields_04[3];
    int samples[32];
} SfdTimerSampleWindow;
typedef struct SfdPtsManager {
    void *field_00;
    int field_04;
    int field_08;
} SfdPtsManager;
typedef struct SfdTimerTestTime {
    long long value;
    long long scale;
} SfdTimerTestTime;
typedef struct SfdTimerTestWork {
    int test_enabled;
    int paused;
    int reset_history;
    int adjust_enabled;
    int average_count;
    int average_index;
    int errors[60];
    SfdTimerTestTime input_time;
    SfdTimerTestTime sample_time;
    SfdTimerTestTime output_time;
    SfdTimerTestTime tolerance;
    SfdTimerTestTime excess_error;
    SfdTimerTestTime adjustment_start;
    SfdTimerTestTime adjustment_offset;
    long long previous_sample;
    long long adjusted_time;
    long long maximum_time;
    int adjustment_count;
    int positive_adjustments;
    int negative_adjustments;
    int history_resets;
    int excess_resets;
    int average;
    int adjusted_average;
    int front_max;
    int front_min;
    int rear_max;
    int rear_min;
    int field_0x1BC;
} SfdTimerTestWork;
typedef int (*SfdExternalClockFn)(SfdCallbackObject object, int *value, int *scale);
typedef struct SfdTimerState {
    SfdTimeSourceFn time_sources[6];
    SfdTimerSkipState skip_state;
    SfdTimerTimeUnit field_003C;
    SfdTimerTimeUnit field_0068;
    SfdTimerStreamTimeUnit stream_time;
    SfdTimerTimeUnit field_00C0;
    SfdTimerTimeUnit video_start_time;
    SfdTimerTimeUnit elapsed_time;
    int start_time_value;
    int start_time_scale;
    int field_014C;
    long long field_0150;
    long long audio_start_pts;
    SfdTimerSampleHistory sample_history;
    SfdTimerSampleWindow sample_window;
    int video_end_time_value;
    int video_end_time_scale;
    int field_0284;
    int field_0288;
    int current_time_value;
    int current_time_scale;
    int interval_time_last;
    int interval_time_estimate;
    int interval_time_max;
    int interval_time_min;
    int field_02A4;
    int video_clock_sample;
    int speed;
    int field_02B0;
    int field_02B4;
    int field_02B8;
    int frame_time_repeat_count;
    float previous_frame_time;
    int previous_frame_ready;
    float last_frame_time;
    volatile int field_02CC; // fzgx-allow: S2 SDK state shared with the decoder/interrupt context
    int previous_clock_sample;
    SfdExternalClockFn external_clock_callback;
    int previous_external_sample;
    int current_clock_sample;
    int clock_sample_scale;
    int external_clock_wrap;
    SfdCallbackObject external_clock_object;
    int field_02EC;
    SfdTimerTestWork test_work;
    unsigned char unknown_04B0[0x100];
    SfdPtsManager video_pts;
    unsigned char unknown_05BC[0x24];
} SfdTimerState;
typedef struct SfdSeeWork SfdSeeWork;
typedef struct SfdSeekRequest {
    int field_00;
    int position;
    int field_08;
} SfdSeekRequest;
typedef struct SfdSeekState {
    SfdSeeWork *work;
    SfdSeekRequest request;
} SfdSeekState;
void fn_12_2E9E4(SfdTimerState *state, int value, int scale);
int fn_12_2E9F0(SfdTimerState *state, int sample_rate, int *using_time_unit);
unsigned int fn_12_2EA6C(SfdTimerState *state, int sample_rate);
typedef struct SfdTransportInterface SfdTransportInterface;
typedef struct SfdTransportState {
    int prepared;
    int terminated;
    void *context;
    const SfdTransportInterface *interface;
    int parameter_10;
    int parameter_14;
    int parameter_18;
    int buffer_output3;
    int state;
    unsigned char unknown_0024[0x20];
} SfdTransportState;
/* GX's player handle predates MK Deception's layout; only the members used here are placed. */
struct SfdHandle {
    unsigned char unknown_0000[0xCC0];
    SfdTimerState timer_state;
    unsigned char unknown_12A0[0x1AA0 - 0x12A0];
    SfdTransportState transports[9];
    unsigned char unknown_1D04[0x2908 - 0x1D04];
    SfdSeekState seek_state;
};
void fn_12_2D7DC(SfdHandle *handle, int condition, SfdConditionValue value);
SfdConditionValue fn_12_2D73C(SfdHandle *handle, int condition);
typedef struct SfdAdxtParameters {
    int stream_buffer_size;
    int stream_buffer_extra_size;
    void *stream_buffer;
    int maximum_channels;
    int decoder_work_size;
    int decoder_buffer_size;
    void *decoder_buffer;
} SfdAdxtParameters;
SfdConditionValue fn_12_2D73C(SfdHandle *handle, int condition);
typedef struct SfdAdxtSeekInfo {
    int ready;
    int byte_rate;
    int field_08;
    int channels;
    int sample_rate;
    int sample_count;
} SfdAdxtSeekInfo;
typedef void (*SfdAdxtCopyFn)(SfdHandle *handle, const unsigned char *data, int size,
                              int *consumed);
typedef struct SfdAdxtWork {
    ADXTHandle *decoder;
    SJ *stream_joint;
    SfdAdxtParameters para;
    int maximum_time_value;
    int maximum_time_scale;
    int paused;
    int discarded_samples;
    int header_inserted;
    int sample_offset;
    SfdAdxtCopyFn copy;
    int seek_depth;
    int server_frequency;
    int copied_bytes;
    int field_4C;
} SfdAdxtWork;
extern int fn_8004B974(const unsigned char *data, int size, int *end_size);
extern int fn_8004B7F4(ADXTHandle *decoder, int channels, int samples);
extern void fn_12_20F4C(SfdHandle *handle, const unsigned char *data, int size, int *consumed);

static inline SfdAdxtWork *sfadxt_GetWork(SfdHandle *handle) {
    return handle->transports[3].context;
}

static inline SfdAdxtSeekInfo *sfadxt_GetSeekInfo(SfdHandle *handle, SfdAdxtWork *work) {
    if (handle->seek_state.work == 0) {
        return 0;
    }
    if (work->seek_depth > 0) {
        return 0;
    }
    return (SfdAdxtSeekInfo *)((unsigned char *)handle->seek_state.work + 0xCFC);
}

static inline int sfadxt_GetAudioInf(SfdHandle *handle, int *channels, int *sample_rate) {
    SfdAdxtSeekInfo *seek = sfadxt_GetSeekInfo(handle, sfadxt_GetWork(handle));
    if (seek == 0) {
        return -1;
    }
    *channels = seek->channels;
    *sample_rate = seek->sample_rate;
    return 0;
}

static inline int sfadxt_SearchEndcode(const unsigned char *data, int limit, int *found_end) {
    const unsigned char *position;
    int scanned;
    int end_size;
    position = data;
    *found_end = 0;
    for (scanned = 0; scanned < limit; scanned += 0x12) {
        if (fn_8004B974(position, 0x12, &end_size) != 0) {
            *found_end = 1;
            break;
        }
        position += 0x12;
    }
    return scanned;
}

#pragma use_lmw_stmw on
void fn_12_20CE8(SfdHandle *handle, const unsigned char *data, int size, int *consumed) {
    int block_size;
    int bytes_per_frame;
    int excluded;
    int bytes_remaining;
    int channels;
    int found_end;
    SfdTimerState *timer;
    int video_start;
    int audio_start;
    int sample_rate;
    int scan_bytes;
    int available;
    int end_size;
    int using_time_unit;
    int difference;
    SfdAdxtWork *work;
    int inserted;
    int samples_remaining;
    *consumed = 0;
    timer = &handle->timer_state;
    work = sfadxt_GetWork(handle);
    if (sfadxt_GetAudioInf(handle, &channels, &sample_rate) != 0) {
        work->copy = fn_12_20F4C;
        return;
    }
    audio_start = fn_12_2EA6C(timer, sample_rate);
    if (audio_start < 0) {
        return;
    }
    if (fn_12_2D73C(handle, 5) == 0) {
        fn_12_2E9E4(timer, audio_start, sample_rate);
        work->copy = fn_12_20F4C;
        return;
    }
    video_start = fn_12_2E9F0(timer, sample_rate, &using_time_unit);
    if (video_start < 0) {
        return;
    }
    fn_12_2E9E4(timer, video_start, sample_rate);
    excluded = 0;
    difference = (video_start - audio_start) - work->sample_offset;
    if (difference >= 0) {
        found_end = 0;
        bytes_remaining = difference / 0x20 * channels * 0x12;
        if (bytes_remaining > 0) {
            bytes_per_frame = channels * 0x12;
            block_size = bytes_remaining;
            available = size / bytes_per_frame * channels * 0x12;
            if (available < bytes_remaining) {
                block_size = available;
            }
            scan_bytes = sfadxt_SearchEndcode(data, block_size, &found_end);
            work->sample_offset = work->sample_offset + scan_bytes / bytes_per_frame * 0x20;
            excluded = scan_bytes;
            bytes_remaining -= block_size;
        }
        if (bytes_remaining <= 0 && using_time_unit != 0) {
            work->copy = fn_12_20F4C;
            found_end = fn_8004B974(data, size, &end_size);
        }
        if (found_end != 0) {
            fn_12_2D7DC(handle, 6, 0);
        }
    } else {
        if (using_time_unit != 0) {
            samples_remaining = (-difference) / 0x20 * 0x20;
            if (samples_remaining > 0) {
                inserted =
                    fn_8004B7F4(sfadxt_GetWork(handle)->decoder, channels, samples_remaining);
                samples_remaining -= inserted;
                work->sample_offset -= inserted;
            }
            if (samples_remaining <= 0) {
                work->copy = fn_12_20F4C;
            }
        }
    }
    *consumed = excluded;
}
