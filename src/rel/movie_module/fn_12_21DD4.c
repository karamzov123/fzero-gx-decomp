#include "types.h"


/* --- rel/movie_module/fn_12_21DD4.c --- */
/* --- rel/movie_module/fn_12_21DD4.c --- */
/* --- rel/movie_module/fn_12_21DD4.c --- */
extern int fn_12_2F210(void *module, void *movie, int command, int value, int flags);

int fn_12_21DD4(void *module, int index, int value) {
    u8 *entry = (u8 *)module + index * 0x74;

    if (*(s32 *)(entry + 0x1144) == 0) {
        return fn_12_2F210(module, *(void **)(entry + 0x118c), 0xb, value, 0);
    }
    return 0;
}

/* --- rel/movie_module/fn_12_21E20.c --- */
typedef struct MovieEntry {
    char unk00[0x2c];
    int value;
    char unk30[0x44];
} MovieEntry;

typedef struct MovieModule {
    char unk0000[0x1148];
    MovieEntry entries[1];
} MovieModule;

void fn_12_21E20(MovieModule *module, int index, int delta) {
    if (module->entries[index].value < 0) {
        return;
    }
    module->entries[index].value += delta;
}

/* --- rel/movie_module/fn_12_21E40.c --- */
extern int fn_12_24A88(void *module, int movie);

int fn_12_21E40(void *module, int index, int *movie_id) {
    u8 *entry = (u8 *)module + index * 0x74;

    *movie_id = 0;
    if (*(s32 *)(entry + 0x1144) == 0) {
        return fn_12_24A88(module, 0xff000000 + 0x401);
    }

    *movie_id = *(s32 *)(entry + 0x1154);
    return 0;
}

/* --- rel/movie_module/fn_12_21E94.c --- */
typedef struct MovieObject_u0 MovieObject_u0;
typedef int (*MovieCallback)(MovieObject_u0 *, int);

typedef struct MovieVtable {
    char padding[0x24];
    MovieCallback callback;
} MovieVtable;

struct MovieObject_u0 {
    MovieVtable *vtable;
};

typedef struct MovieModule_u1 {
    char padding0[0x1154];
    MovieObject_u0 *object;
    char padding1[0x18];
    int value;
    int delta;
} MovieModule_u1;

extern void fn_12_24970(void *movie);
extern void fn_12_24950(void *movie);

int fn_12_21E94(MovieModule_u1 *module, int index) {
    char movie[8];
    MovieModule_u1 *entry;
    int value;
    int delta;

    entry = (MovieModule_u1 *)((char *)module + index * 0x74);
    fn_12_24970(movie);
    value = entry->value;
    delta = entry->delta;
    if (value == 0 && delta != 0) {
        value = delta + entry->object->vtable->callback(entry->object, 1);
    }
    if (value < 0) {
        value = 0x7fffffff;
    }
    fn_12_24950(movie);
    return value;
}

/* --- rel/movie_module/fn_12_21F28.c --- */
struct MovieEntry_u2 {
    int value;
    char padding[0x70];
};

struct MovieModule_u2 {
    char padding[0x1174];
    struct MovieEntry_u2 entries[1];
};

int fn_12_21F28(struct MovieModule_u2 *module, int index) {
    return module->entries[index].value;
}

/* --- rel/movie_module/fn_12_21F38.c --- */
/* --- rel/movie_module/fn_12_21F38.c --- */
typedef struct MovieEntry_u3 {
    int value;
    u8 pad[0x70];
} MovieEntry_u3;

typedef struct MovieModule_u3 {
    u8 pad[0x115c];
    MovieEntry_u3 entries[1];
} MovieModule_u3;

int fn_12_21F38(MovieModule_u3 *module, int index) {
    return module->entries[index].value;
}

/* --- rel/movie_module/fn_12_21F48.c --- */
typedef struct MovieObject_u3 {
    u8 pad[0x1168];
    void *movie;
    void *stream;
} MovieObject_u3;

typedef struct MovieState {
    u8 data[4];
} MovieState;


void fn_12_21F48(u8 *module, int index, void *movie, void *stream) {
    MovieState state;
    MovieObject_u3 *entry;

    entry = (MovieObject_u3 *)(module + index * 0x74);
    fn_12_24970(&state);
    entry->movie = movie;
    entry->stream = stream;
    fn_12_24950(&state);
}

/* --- rel/movie_module/fn_12_21FA4.c --- */
typedef struct MovieEntry_u4 {
    u8 pad[0x1168];
    int value1;
    int value2;
} MovieEntry_u4;

typedef struct MovieModule_u4 {
    u8 pad[1];
} MovieModule_u4;


void fn_12_21FA4(MovieModule_u4 *module, int index, int *value1, int *value2) {
    MovieEntry_u4 *entry = (MovieEntry_u4 *)((u8 *)module + index * 0x74);
    u8 movie_data[8];

    fn_12_24970(movie_data);
    *value1 = entry->value1;
    *value2 = entry->value2;
    fn_12_24950(movie_data);
}

/* --- rel/movie_module/fn_12_22008.c --- */
typedef struct SJCK {
    unsigned char *data;
    long len;
} SJCK;

typedef struct SJ_u1 SJ_u1;

typedef struct SJInterface_u1 SJInterface_u1;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface_u1 {
    void *reserved[3];
    void (*destroy)(SJ_u1 *sj);
    const void *(*get_uuid)(SJ_u1 *sj);
    void (*reset)(SJ_u1 *sj);
    void (*get_chunk)(SJ_u1 *sj, long channel, long max_size, SJCK *chunk);
    void (*unget_chunk)(SJ_u1 *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ_u1 *sj, int channel, SJCK *chunk);
    int (*get_num_data)(SJ_u1 *sj, int channel);
    int (*is_get_chunk)(SJ_u1 *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ_u1 *sj, SJErrorCallback callback, void *object);
};

struct SJ_u1 {
    const SJInterface_u1 *interface;
};

typedef void *SfdCallbackObject;

typedef int SfdConditionValue;

typedef int SfdTransportValue;

typedef struct SfdHandle_u1 SfdHandle_u1;

typedef int (*SfdUserIsSkipFn)(SfdHandle_u1 *handle, int picture_type, int value, int scale);

typedef int (*SfdTimeSourceFn)(SfdHandle_u1 *handle, int *value, int *scale);

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
    long long time_values[12];
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
// Hardware or OS state can change asynchronously.
    volatile int field_02CC;
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

typedef void (*SfdErrorCallback)(SfdCallbackObject object, int error);

typedef struct SfdErrorInfo {
    SfdErrorCallback callback;
    SfdCallbackObject callback_object;
    int first_error;
    int field_0C;
    int field_10;
} SfdErrorInfo;

typedef struct SfdHeaderAudioInfo {
    int codec;
    int layer;
    int channel_count;
    int sample_rate;
} SfdHeaderAudioInfo;

typedef struct SfdHeaderVideoInfo {
    int codec;
    int bit_rate;
    int width;
    int height;
    int picture_rate;
    int has_effective_features;
    int color_type;
    int picture_type;
    int fixed_flag;
    int sequence_header_fixed_flag;
    int expand;
    int gop_n;
    int gop_m;
} SfdHeaderVideoInfo;

typedef struct SfdHeaderState {
    int processed;
    int mux_version_major;
    int mux_version_minor;
    int byte_rate;
    int header_size;
    int pack_type;
    int packet_size_length;
    int pack_size;
    int element_count;
    int audio_element_count;
    int video_element_count;
    int private_element_count;
    int maximum_audio_length;
    int maximum_video_length;
    int maximum_frame_count;
    int private_stream_1;
    int private_stream_2;
    int audio_stream;
    int video_stream;
    SfdHeaderAudioInfo audio;
    SfdHeaderVideoInfo video;
    int raw_header_size;
    unsigned char raw_header[0x800];
} SfdHeaderState;

typedef struct SfdTimerSummary {
    long long total;
    long long minimum;
    long long maximum;
    int count;
    int field_1C;
} SfdTimerSummary;

typedef struct SfdTransportInterface_u1 SfdTransportInterface_u1;

typedef struct SfdTransportSetup_u1 SfdTransportSetup_u1;

typedef struct SfdVideoFrameState_u1 SfdVideoFrameState_u1;

typedef void (*SfdBufferHandleCallback)(SfdHandle_u1 *handle, int stream_index);

typedef void (*SfdBufferObjectCallback)(SfdCallbackObject object, int stream_index);

typedef struct SfdBufferChannel {
    SJ_u1 *stream_joint;
    SfdBufferHandleCallback handle_callback;
    SfdBufferObjectCallback object_callback;
    SfdCallbackObject object;
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

typedef struct SfdBufferSupply {
    int kind;
    SJ_u1 *stream_joint;
    unsigned char *buffer;
    int buffer_size;
    int extra_size;
    int field_14;
} SfdBufferSupply;

typedef struct SfdBufferRingWork {
    SfdBufferSupply supply;
    unsigned char *delimiter_position;
    unsigned char *delimiter_end;
    int write_total;
    int read_total;
    SfdPtsQueue pts_queue;
} SfdBufferRingWork;

typedef struct SfdBufferVideoWork {
    unsigned char *buffer;
    int buffer_size;
    int reserved_08;
    int reserved_0C;
    SfdVideoFrameState_u1 *video_frames;
} SfdBufferVideoWork;

typedef struct SfdBufferAudioWork {
    unsigned char *buffer;
    int buffer_size;
    int reserved[7];
    int reserved_tail[3];
} SfdBufferAudioWork;

typedef union SfdBufferWork {
    SfdBufferRingWork ring;
    unsigned char extent[0x3C];
} SfdBufferWork;

typedef int (*SfdTransportLifecycleFn)(SfdHandle_u1 *handle);

typedef int (*SfdTransportPauseFn)(SfdHandle_u1 *handle, int state);

typedef int (*SfdTransportTransferFn)(SfdHandle_u1 *handle, SfdTransportValue parameter, int value);

typedef int (*SfdTransportBufferFn)(SfdHandle_u1 *handle, void *buffer);

struct SfdTransportInterface_u1 {
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
    int reserved_54[8];
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
    long long picture_pts;
    int field_58, field_5C, field_60, field_64;
    short field_68, field_6A;
    unsigned char fields_6C[0x0F];
    unsigned char reserved_7B[5];
} SfdVideoFrameInfo;

struct SfdVideoFrameState_u1 {
    int state;
    int field_04;
    SfdVideoFrameInfo info;
};

typedef struct SfdBufferCreateConfig {
    const SfdTransportSetup_u1 *transport_setup;
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
    const SfdTransportInterface_u1 *interface;
    int parameter_10;
    int parameter_14;
    int parameter_18;
    int buffer_output3;
    int state;
    unsigned char unknown_0024[0x20];
} SfdTransportState;

typedef struct SfdUserOutputWork {
    int state;
    SfdBufferChannel channels[3];
} SfdUserOutputWork;

struct SfdTransportSetup_u1 {
    const SfdTransportInterface_u1 *entries[9];
};

typedef struct SfdAudioOutputCallbacks_u1 SfdAudioOutputCallbacks_u1;

typedef int (*SfdAudioSetPanFn)(SfdHandle_u1 *, int, int, SfdAudioOutputCallbacks_u1 *);

typedef int (*SfdAudioGetPanFn)(SfdHandle_u1 *, int, SfdAudioOutputCallbacks_u1 *);

typedef int (*SfdAudioSetVolumeFn)(SfdHandle_u1 *, int, SfdAudioOutputCallbacks_u1 *);

typedef int (*SfdAudioGetVolumeFn)(SfdHandle_u1 *, SfdAudioOutputCallbacks_u1 *);

typedef void (*SfdAudioSetSpeedFn)(SfdHandle_u1 *, int);

struct SfdAudioOutputCallbacks_u1 {
    void *output_context;
    SfdAudioSetPanFn set_pan;
    SfdAudioGetPanFn get_pan;
    SfdAudioSetVolumeFn set_volume;
    SfdAudioGetVolumeFn get_volume;
    SfdAudioSetSpeedFn set_speed;
    int reserved_18;
};

struct SfdHandle_u1 {
    SfdCreateConfig create_config;
    int field_0044;
    int playback_state;
    int requested_state;
    int field_0050;
    int field_0054;
    unsigned char unknown_0058[0x20];
    SfdHeaderState header_state;
    SfdPlaybackSettings playback_settings;
    int field_094C;
    SfdPlaybackRuntime playback_runtime;
    SfdErrorInfo error_info;
    SfdConditionValue conditions_primary[100];
    SfdConditionValue conditions_secondary[100];
    int field_0D24;
    SfdTimerState timer_state;
    SfdBufferState buffers[8];
    SfdVideoFrameState_u1 video_frames[16];
    SfdTransportState transports[9];
    unsigned char unknown_218C[4];
    unsigned char mps_work_storage[0x168];
    unsigned char unknown_22F8[0xA8];
    unsigned char mpv_work_storage[0xF80];
    unsigned char unknown_3320[0x154];
    SfdAudioOutputCallbacks_u1 audio_output_callbacks;
    SfdUserOutputWork user_output_work;
    int field_34C4;
    SfdSeekState seek_state;
    SfdTimerSummary timer_summaries[6];
};

typedef struct SfdBufferHn {
    unsigned char pad[0x1140];
    SfdBufferState buffer;
} SfdBufferHn;

int fn_12_22008(SfdHandle_u1 *handle, int buffer_index, int amount);


static inline void sfbuf_RingGetChunks(SJ_u1 *sj, int channel, SJCK *first, SJCK *second) {
    int size;
    size = sj->interface->get_num_data(sj, channel);
    sj->interface->get_chunk(sj, channel, 0x7FFFFFFF, first);
    if (first->len < size) {
        sj->interface->get_chunk(sj, channel, 0x7FFFFFFF, second);
        sj->interface->unget_chunk(sj, channel, second);
    } else {
        second->data = 0;
        second->len = 0;
    }
    sj->interface->unget_chunk(sj, channel, first);
}

static inline int sfbuf_RingAddReadSub(SfdHandle_u1 *handle, int buffer_index, int amount) {
    int lock;
    SJCK first;
    SJCK wrap;
    int result = 0;
    int needed;
    SJCK remainder;
    SJCK chunk;
    SJ_u1 *source;
    SJ_u1 *sj;
    SfdBufferRingWork *ring;
    SfdBufferState *buffer;
    SfdBufferHn *hn;
    hn = (SfdBufferHn *)((unsigned char *)handle + buffer_index * sizeof(SfdBufferState));
    buffer = &hn->buffer;
    ring = &buffer->work.ring;
    sj = hn->buffer.work.ring.supply.stream_joint;
    if (amount == 0) {
        result = 0;
    } else if (buffer->active == 0 || sj == 0) {
        result = 0;
    } else {
        fn_12_24970(&lock);
        sj->interface->get_chunk(sj, 1, amount, &chunk);
        sj->interface->put_chunk(sj, 0, &chunk);
        if (chunk.len < amount) {
            needed = amount - chunk.len;
            sj->interface->get_chunk(sj, 1, needed, &remainder);
            sj->interface->put_chunk(sj, 0, &remainder);
            if (remainder.len < needed) {
                result = fn_12_24A88(handle, 0xFF00040B);
            }
        }
        if (buffer_index == 1) {
            source = ring->supply.stream_joint;
            sfbuf_RingGetChunks(source, 1, &first, &wrap);
            if ((ring->delimiter_position < first.data ||
                 ring->delimiter_position >= first.data + first.len) &&
                (ring->delimiter_position < wrap.data ||
                 ring->delimiter_position >= wrap.data + wrap.len)) {
                ring->delimiter_position = 0;
                ring->delimiter_end = 0;
            }
        }
        if (ring->read_total >= 0) {
            ring->read_total += amount;
        }
        handle->field_0044 = 1;
        fn_12_24950(&lock);
    }
    return result;
}

int fn_12_22008(SfdHandle_u1 *handle, int buffer_index, int amount) {
    return sfbuf_RingAddReadSub(handle, buffer_index, amount);
}
typedef char SfdBufferStateSize[sizeof(SfdBufferState) == 0x74 ? 1 : -1];
