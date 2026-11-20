#include "types.h"
#pragma dont_inline on

/* --- rel/movie_module/fn_12_3515C.c --- */
typedef struct MovieModule {
    u8 pad[0xa8];
    void *movie;
} MovieModule;

extern void fn_12_7C4(void *movie);

void fn_12_3515C(MovieModule *module) {
    fn_12_7C4(module->movie);
}

/* --- rel/movie_module/mwsftag_GetAinfFromSj.c --- */
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

typedef struct SfxEffect SfxEffect;

typedef struct SfxTagInfo {
    int field_0x00;
    int composition_mode;
    int effect_type;
    int output_buffer_size;
    int output_buffer_count;
    int unit_width;
    int tag_info_set;
    union {
        int tag_start;
        void *tag_data;
    };
    int tag_size;
    char pad24[4];
    SfxEffect *effect;
    char pad2C[0x0C];
    int color_adjustment;
} SfxTagInfo;

typedef int SfdCallbackObject;

typedef int SfdConditionValue;

typedef int SfdTransportValue;

typedef struct SfdHandle SfdHandle;

typedef int (*SfdUserIsSkipFn)(SfdHandle *handle, int picture_type, int value, int scale);

typedef int (*SfdTimeSourceFn)(SfdHandle *handle, int *value, int *scale);

typedef struct SfdPlaybackSettings {
    int values_00[5];
    int frame_rate_code;
    int values_18[10];
} SfdPlaybackSettings;

typedef struct SfdPlaybackRuntime {
    int decoded_pictures;
    int skipped_pictures;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    int frame_outstanding;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    union {
        long long time_values[12];
        struct {
            long long reserved_time_values[3];
            struct {
                int high;
                unsigned int low;
            } input_flow;
            long long remaining_time_values[8];
        } timing;
    };
    int tail_values[4];
} SfdPlaybackRuntime;

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
    int value;
    int scale;
} SfdTimerSkipState;

typedef struct SfdTimerCompactTimeUnit {
    int fields_00[6];
    unsigned short field_18;
    unsigned short field_1A;
    int value;
    int scale;
} SfdTimerCompactTimeUnit;

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

typedef int (*SfdExternalClockFn)(SfdCallbackObject object, int *value, int *scale);

typedef struct SfdTimerState {
    SfdTimeSourceFn time_sources[6];
    SfdTimerSkipState skip_state;
    SfdTimerCompactTimeUnit compact_time;
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
    int field_02CC;
    int previous_clock_sample;
    SfdExternalClockFn external_clock_callback;
    int previous_external_sample;
    int current_clock_sample;
    int clock_sample_scale;
    int external_clock_wrap;
    SfdCallbackObject external_clock_object;
    unsigned char unknown_02EC[0x2C4];
    unsigned int video_pts[3];
    unsigned char unknown_05BC[0x24];
} SfdTimerState;

typedef struct SfdSeekState {
    SfdHandle *source_handle;
    int field_04;
    int field_08;
    int field_0C;
} SfdSeekState;

typedef void (*SfdErrorCallback)(SfdCallbackObject object, int error);

typedef struct SfdErrorInfo {
    SfdErrorCallback callback;
    SfdCallbackObject callback_object;
    int first_error;
    int field_0C;
    int field_10;
} SfdErrorInfo;

typedef struct SfdHeaderState {
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    unsigned char unknown_0010[0x6C];
    int field_7C;
    unsigned char unknown_0080[0x10];
    int field_90;
} SfdHeaderState;

typedef struct SfdTimerSummary {
    long long total;
    long long minimum;
    long long maximum;
    int count;
    int field_1C;
} SfdTimerSummary;

typedef struct SfdTransportInterface SfdTransportInterface;

typedef struct SfdTransportSetup SfdTransportSetup;

typedef struct SfdVideoFrameState SfdVideoFrameState;

typedef void (*SfdBufferHandleCallback)(SfdHandle *handle, int stream_index);

typedef void (*SfdBufferObjectCallback)(SfdCallbackObject object, int stream_index);

typedef struct SfdBufferChannel {
    SJ *stream_joint;
    SfdCallbackObject object;
    SfdBufferHandleCallback handle_callback;
    SfdBufferObjectCallback object_callback;
} SfdBufferChannel;

typedef struct SfdPtsEntry {
    long long pts;
    unsigned char *data;
    int size;
} SfdPtsEntry;

typedef struct SfdPtsQueue {
    SfdPtsEntry *entries;
    int capacity;
    int count;
    int write_index;
    int read_index;
} SfdPtsQueue;

typedef struct SfdBufferRingWork {
    int field_00;
    SJ *stream_joint;
    unsigned char *buffer;
    int buffer_size;
    int field_10;
    int field_14;
    unsigned char *delimiter_position;
    unsigned char *delimiter_end;
    int write_total;
    int read_total;
    SfdPtsQueue pts_queue;
} SfdBufferRingWork;

typedef struct SfdBufferLinearWork {
    unsigned char *buffer;
    int buffer_size;
    int field_08;
    int field_0C;
    SfdVideoFrameState *video_frames;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
} SfdBufferLinearWork;

typedef union SfdBufferWork {
    SfdBufferRingWork ring;
    SfdBufferLinearWork linear;
    SfdBufferChannel user_channels[3];
    unsigned char raw[0x3C];
} SfdBufferWork;

typedef int (*SfdTransportLifecycleFn)(SfdHandle *handle);

typedef int (*SfdTransportPauseFn)(SfdHandle *handle, int state);

typedef int (*SfdTransportTransferFn)(SfdHandle *handle, SfdTransportValue parameter, int value);

typedef int (*SfdTransportBufferFn)(SfdHandle *handle, void *buffer);

struct SfdTransportInterface {
    SfdTransportLifecycleFn init;
    SfdTransportLifecycleFn finish;
    SfdTransportLifecycleFn exec_server;
    SfdTransportLifecycleFn create;
    SfdTransportLifecycleFn destroy;
    SfdTransportLifecycleFn standby;
    SfdTransportLifecycleFn start;
    SfdTransportLifecycleFn stop;
    SfdTransportPauseFn pause;
    SfdTransportBufferFn get_write;
    SfdTransportTransferFn add_write;
    SfdTransportBufferFn get_read;
    SfdTransportTransferFn add_read;
    SfdTransportTransferFn seek;
};

typedef struct SfdBufferState {
    int storage_mode;
    int active;
    int prepared;
    int terminated;
    SfdBufferWork work;
    int input_transport;
    int output_transport;
    unsigned char unknown_0054[0x20];
} SfdBufferState;

typedef struct SfdVideoFrameInfo {
    int width, height, macroblocks_per_row, macroblock_rows;
    int picture_type;
    int display_time_value, display_time_scale;
    int output_format;
    void *frame_buffer;
    int field_24, field_28, picture_order, field_30, field_34;
    void *picture_user_buffer;
    int field_3C, field_40, reserved_44, display_mode, reserved_4C;
    int field_50, field_54, field_58, field_5C, field_60, field_64;
    short field_68, field_6A;
    unsigned char fields_6C[0x0F];
    unsigned char reserved_7B[5];
} SfdVideoFrameInfo;

struct SfdVideoFrameState {
    int state;
    int field_04;
    union {
        unsigned char payload[0x80];
        SfdVideoFrameInfo info;
    } data;
};

typedef struct SfdBufferCreateConfig {
    const SfdTransportSetup *transport_setup;
    unsigned char *memory;
    int buffer_sizes[7];
    int field_24;
    int ring_alignment;
} SfdBufferCreateConfig;

typedef struct SfdCreateConfig {
    SfdBufferCreateConfig buffer;
    int picture_user_buffer_minimum;
    int maximum_width;
    int maximum_height;
    int video_output_format;
    unsigned char *handle_memory;
    int handle_memory_size;
} SfdCreateConfig;

typedef struct SfdTransportState {
    int prepared;
    int terminated;
    void *context;
    const SfdTransportInterface *interface;
    int parameter_10;
    int parameter_14;
    int parameter_18;
    int parameter_1C;
    int state;
    unsigned char unknown_0024[0x20];
} SfdTransportState;

typedef struct SfdUserOutputWork {
    int state;
    SfdBufferChannel channels[3];
} SfdUserOutputWork;

struct SfdTransportSetup {
    const SfdTransportInterface *entries[9];
};

typedef struct SfdAudioOutputCallbacks SfdAudioOutputCallbacks;

typedef void (*SfdAudioSetPanFn)(SfdHandle *, int, int, SfdAudioOutputCallbacks *);

typedef int (*SfdAudioGetPanFn)(SfdHandle *, int, SfdAudioOutputCallbacks *);

typedef void (*SfdAudioSetVolumeFn)(SfdHandle *, int, SfdAudioOutputCallbacks *);

typedef int (*SfdAudioGetVolumeFn)(SfdHandle *, SfdAudioOutputCallbacks *);

typedef void (*SfdAudioSetSpeedFn)(SfdHandle *, int);

struct SfdAudioOutputCallbacks {
    int reserved_00;
    SfdAudioSetPanFn set_pan;
    SfdAudioGetPanFn get_pan;
    SfdAudioSetVolumeFn set_volume;
    SfdAudioGetVolumeFn get_volume;
    SfdAudioSetSpeedFn set_speed;
    int reserved_18;
};

struct SfdHandle {
    SfdCreateConfig create_config;
    int field_0044;
    int playback_state;
    int requested_state;
    int field_0050;
    int field_0054;
    unsigned char unknown_0058[0x20];
    SfdHeaderState header_state;
    unsigned char unknown_010C[0x800];
    SfdPlaybackSettings playback_settings;
    int field_094C;
    SfdPlaybackRuntime playback_runtime;
    SfdErrorInfo error_info;
    SfdConditionValue conditions_primary[100];
    SfdConditionValue conditions_secondary[100];
    int field_0D24;
    SfdTimerState timer_state;
    SfdBufferState buffers[8];
    SfdVideoFrameState video_frames[16];
    SfdTransportState transports[9];
    unsigned char unknown_218C[4];
    unsigned char mps_work_storage[0x168];
    unsigned char unknown_22F8[0xA8];
    unsigned char mpv_work_storage[0xF80];
    unsigned char unknown_3320[0x154];
    SfdAudioOutputCallbacks audio_output_callbacks;
    SfdUserOutputWork user_output_work;
    int field_34C4;
    SfdSeekState seek_state;
    SfdTimerSummary timer_summaries[6];
};

typedef struct MwsSfxHandleView {
    SfxTagInfo tag_info;
    unsigned char reserved_03C[0x24];
    const char *picture_user_data;
    int picture_user_size;
} MwsSfxHandleView;

typedef struct MwsPlayer {
    unsigned char reserved_000[0x0C];
    int playback_state;
    unsigned char reserved_010[0x10];
    int field_020;
    unsigned char reserved_024[8];
    int field_02C;
    unsigned char reserved_030[0x10];
    SfdHandle *sfd;
    unsigned char reserved_044[0x0C];
    int composition_initialized;
    int composition_mode;
    unsigned char reserved_058[0x34];
    int picture_structure;
    int chroma_format;
    int field_094;
    int field_098;
    int field_09C;
    int chroma_position_0;
    int chroma_position_1;
    unsigned char reserved_0A8[4];
    MwsSfxHandleView *sfx;
    unsigned char reserved_0B0[56];
    SJ *additional_info_sj;
    void *additional_info_buffer;
    int additional_info_buffer_size;
    void *additional_info_copy;
    unsigned char reserved_1A0[4];
    int previous_tag_number;
    int tag_state;
    unsigned char *tag_data;
    int tag_size;
} MwsPlayer;

unsigned char *SJ_SearchTag(const SJCK *source, const char *tag, const char *terminator,
                           SJCK *result);

void *memcpy(void *destination, const void *source, unsigned long size);

int fn_12_2FA90(SfdHandle *handle, int channel, SJ *stream_joint, SfdCallbackObject object);

extern const char lbl_12_rodata_17C0[8];

extern const char lbl_12_rodata_17C8[8];

void mwsftag_GetAinfFromSj(MwsPlayer *player) {
    SJCK source;
    SJCK result;
    SJCK consumed;
    SJ *sj = player->additional_info_sj;
    int num_data;
    int stopped;
    num_data = sj->interface->get_num_data(sj, 1);
    if (num_data == 0) {
        player->tag_data = 0;
        player->tag_size = 0;
        player->tag_state = 1;
        return;
    }
    source.data = player->additional_info_buffer;
    source.len = num_data;
    if (SJ_SearchTag(&source, lbl_12_rodata_17C0, lbl_12_rodata_17C8, &result) == 0) {
        player->tag_data = 0;
        player->tag_size = 0;
        player->tag_state = 1;
        return;
    }
    if (player->additional_info_copy != 0) {
        memcpy(player->additional_info_copy, result.data, result.len);
        player->tag_data = player->additional_info_copy;
        player->tag_size = result.len;
        player->tag_state = 1;
        sj->interface->get_chunk(sj, 1, 0x7FFFFFFF, &consumed);
        sj->interface->put_chunk(sj, 0, &consumed);
        sj->interface->reset(sj);
        return;
    }
    player->tag_data = result.data;
    player->tag_size = result.len;
    player->tag_state = 1;
    if (player->playback_state == 2) {
        stopped = 1;
    } else {
        stopped = 0;
    }
    if (stopped != 1 && player->additional_info_sj != 0) {
        fn_12_2FA90(player->sfd, 2, 0, 0);
    }
}
