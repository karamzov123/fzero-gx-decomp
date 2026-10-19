
#include "types.h"

typedef void *SfdCallbackObject;

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
    long long time_values[12];
    int tail_values[4];
} SfdPlaybackRuntime;

typedef struct SfdTimerTimeUnit {
    union {
        unsigned char padding_extent[44];
        struct {
            unsigned char padding_value[36];
            int value;
        } view_value;
        struct {
            unsigned char padding_scale[40];
            int scale;
        } view_scale;
    } fields;
} SfdTimerTimeUnit;

typedef struct SfdTimerSkipState {
    SfdUserIsSkipFn callback;
    int fields_04[7];
    unsigned short field_20;
    unsigned short field_22;
} SfdTimerSkipState;

typedef struct SfdTimerStreamTimeUnit {
    union {
        unsigned char padding_extent[44];
        struct {
            unsigned char padding_file_size[8];
            int file_size;
        } view_file_size;
        struct {
            unsigned char padding_total_time_value[12];
            int total_time_value;
        } view_total_time_value;
        struct {
            unsigned char padding_total_time_scale[16];
            int total_time_scale;
        } view_total_time_scale;
        struct {
            unsigned char padding_byte_rate[20];
            int byte_rate;
        } view_byte_rate;
        struct {
            unsigned char padding_seek_position[24];
            int seek_position;
        } view_seek_position;
        struct {
            unsigned char padding_value[36];
            int value;
        } view_value;
        struct {
            unsigned char padding_scale[40];
            int scale;
        } view_scale;
    } fields;
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
    union {
        unsigned char padding_extent[16];
        struct {
            long long value;
        } view_value;
        struct {
            unsigned char padding_scale[8];
            long long scale;
        } view_scale;
    } fields;
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
    union {
        unsigned char padding_extent[1504];
        struct {
            unsigned char padding_stream_time[148];
            SfdTimerStreamTimeUnit stream_time;
        } view_stream_time;
    } fields;
} SfdTimerState;

typedef struct SfdSeeWork SfdSeeWork;

typedef struct SfdSeekRequest {
    union {
        unsigned char padding_extent[12];
        struct {
            unsigned char padding_position[4];
            int position;
        } view_position;
    } fields;
} SfdSeekRequest;

typedef struct SfdSeekState {
    union {
        unsigned char padding_extent[16];
        struct {
            SfdSeeWork *work;
        } view_work;
        struct {
            unsigned char padding_request[4];
            SfdSeekRequest request;
        } view_request;
    } fields;
} SfdSeekState;

typedef void (*SfdErrorCallback)(SfdCallbackObject object, int error);

typedef struct SfdErrorInfo {
    SfdErrorCallback callback;
    SfdCallbackObject callback_object;
    int first_error;
    int field_0C;
    int field_10;
} SfdErrorInfo;

typedef struct SJCK {
    unsigned char *data;
    long len;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface SJInterface;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface {
    void *reserved[3];
    void (*destroy)(SJ *sj);
    const void *(*get_uuid)(SJ *sj);
    void (*reset)(SJ *sj);
    void (*get_chunk)(SJ *sj, long channel, long max_size, SJCK *chunk);
    void (*unget_chunk)(SJ *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
    int (*get_num_data)(SJ *sj, int channel);
    int (*is_get_chunk)(SJ *sj, int channel, int size, int *available);
    void (*entry_error_func)(SJ *sj, SJErrorCallback callback, void *object);
};

struct SJ {
    const SJInterface *interface;
};

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
    union {
        unsigned char padding_extent[2196];
        struct {
            unsigned char padding_byte_rate[12];
            int byte_rate;
        } view_byte_rate;
    } fields;
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
    SJ *stream_joint;
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
    SfdVideoFrameState *video_frames;
} SfdBufferVideoWork;

typedef struct SfdBufferAudioWork {
    unsigned char *buffer;
    int buffer_size;
    int reserved[7];
    int reserved_tail[3];
} SfdBufferAudioWork;

typedef union SfdBufferWork {
    SfdBufferRingWork ring;
    SfdBufferVideoWork video;
    SfdBufferAudioWork audio;
    SfdBufferChannel user_channels[3];
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
    union {
        unsigned char padding_extent[116];
        struct {
            unsigned char padding_work[16];
            SfdBufferWork work;
        } view_work;
        struct {
            unsigned char padding_output_transport[80];
            int output_transport;
        } view_output_transport;
    } fields;
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

struct SfdVideoFrameState {
    union {
        unsigned char padding_extent[136];
        struct {
            int state;
        } view_state;
    } fields;
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
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_parameter_14[20];
            int parameter_14;
        } view_parameter_14;
        struct {
            unsigned char padding_state[32];
            int state;
        } view_state;
    } fields;
} SfdTransportState;

typedef struct SfdUserOutputWork {
    union {
        unsigned char padding_extent[52];
        struct {
            int state;
        } view_state;
    } fields;
} SfdUserOutputWork;

struct SfdTransportSetup {
    const SfdTransportInterface *entries[9];
};

typedef struct SfdAudioOutputCallbacks SfdAudioOutputCallbacks;

typedef int (*SfdAudioSetPanFn)(SfdHandle *, int, int, SfdAudioOutputCallbacks *);

typedef int (*SfdAudioGetPanFn)(SfdHandle *, int, SfdAudioOutputCallbacks *);

typedef int (*SfdAudioSetVolumeFn)(SfdHandle *, int, SfdAudioOutputCallbacks *);

typedef int (*SfdAudioGetVolumeFn)(SfdHandle *, SfdAudioOutputCallbacks *);

typedef void (*SfdAudioSetSpeedFn)(SfdHandle *, int);

struct SfdAudioOutputCallbacks {
    void *output_context;
    SfdAudioSetPanFn set_pan;
    SfdAudioGetPanFn get_pan;
    SfdAudioSetVolumeFn set_volume;
    SfdAudioGetVolumeFn get_volume;
    SfdAudioSetSpeedFn set_speed;
    int reserved_18;
};

struct SfdHandle {
    union {
        unsigned char padding_extent[13720];
        struct {
            unsigned char padding_timer_state[3220];
            SfdTimerState timer_state;
        } view_timer_state;
        struct {
            unsigned char padding_buffers[4416];
            SfdBufferState buffers[8];
        } view_buffers;
        struct {
            unsigned char padding_transports[6816];
            SfdTransportState transports[9];
        } view_transports;
        struct {
            unsigned char padding_seek_state[10504];
            SfdSeekState seek_state;
        } view_seek_state;
    } fields;
};

typedef struct SfdSeeSourcePrefix {
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_analyzed_byte_rate[4];
            int analyzed_byte_rate;
        } view_analyzed_byte_rate;
    } fields;
} SfdSeeSourcePrefix;

typedef struct SfdSeeHeadSnapshot {
    union {
        unsigned char padding_extent[12];
        struct {
            unsigned char padding_byte_rate[4];
            int byte_rate;
        } view_byte_rate;
    } fields;
} SfdSeeHeadSnapshot;

typedef struct SfdSeeTiming {
    union {
        unsigned char padding_extent[192];
        struct {
            unsigned char padding_byte_rate[128];
            int byte_rate;
        } view_byte_rate;
        struct {
            unsigned char padding_discovered_file_size[132];
            int discovered_file_size;
        } view_discovered_file_size;
        struct {
            unsigned char padding_discovered_total_time_value[136];
            int discovered_total_time_value;
        } view_discovered_total_time_value;
        struct {
            unsigned char padding_discovered_total_time_scale[140];
            int discovered_total_time_scale;
        } view_discovered_total_time_scale;
        struct {
            unsigned char padding_file_size[156];
            int file_size;
        } view_file_size;
        struct {
            unsigned char padding_total_time_value[160];
            int total_time_value;
        } view_total_time_value;
        struct {
            unsigned char padding_total_time_scale[164];
            int total_time_scale;
        } view_total_time_scale;
        struct {
            unsigned char padding_requested_byte_rate[168];
            int requested_byte_rate;
        } view_requested_byte_rate;
        struct {
            unsigned char padding_seek_position[172];
            int seek_position;
        } view_seek_position;
    } fields;
} SfdSeeTiming;

struct SfdSeeWork {
    union {
        unsigned char padding_extent[4872];
        struct {
            SfdSeeSourcePrefix prefix;
        } view_prefix;
        struct {
            unsigned char padding_timing[3348];
            SfdSeeTiming timing;
        } view_timing;
    } fields;
};

void fn_12_2D288(SfdHandle *handle);

int fn_12_23250(SfdHandle *handle);

unsigned int UTY_MulDiv(int multiplicand, int multiplier, int divisor);

static inline SfdSeeWork *sfsee_GetSource(SfdHandle *handle) {
    return handle->fields.view_seek_state.seek_state.fields.view_work.work;
}

static inline void sfsee_UpdateByteRate(SfdHandle *handle) {
    SfdSeeWork *source = sfsee_GetSource(handle);
    SfdSeeTiming *timing = &source->fields.view_timing.timing;
    int file_size;
    int time_value;
    int time_scale;
    if (timing->fields.view_requested_byte_rate.requested_byte_rate > 0) {
        timing->fields.view_byte_rate.byte_rate =
            timing->fields.view_requested_byte_rate.requested_byte_rate;
        return;
    }
    file_size = timing->fields.view_file_size.file_size;
    time_value = timing->fields.view_total_time_value.total_time_value;
    time_scale = timing->fields.view_total_time_scale.total_time_scale;
    if (file_size > 0 && time_value > 0) {
        timing->fields.view_byte_rate.byte_rate = UTY_MulDiv(file_size, time_scale, time_value);
        return;
    }
    if (source->fields.view_prefix.prefix.fields.view_analyzed_byte_rate.analyzed_byte_rate > 0) {
        timing->fields.view_byte_rate.byte_rate =
            source->fields.view_prefix.prefix.fields.view_analyzed_byte_rate.analyzed_byte_rate;
        return;
    }
    if (file_size <= 0) {
        file_size = timing->fields.view_discovered_file_size.discovered_file_size;
    }
    if (time_value <= 0) {
        time_value = timing->fields.view_discovered_total_time_value.discovered_total_time_value;
        time_scale = timing->fields.view_discovered_total_time_scale.discovered_total_time_scale;
    }
    if (file_size > 0 && time_value > 0) {
        timing->fields.view_byte_rate.byte_rate = UTY_MulDiv(file_size, time_scale, time_value);
    } else {
        SfdSeeWork *fallback_source = sfsee_GetSource(handle);
        timing->fields.view_byte_rate.byte_rate = fallback_source->fields.view_prefix.prefix.fields
                                                      .view_analyzed_byte_rate.analyzed_byte_rate;
    }
}

void fn_12_2D008(SfdHandle *handle);

static inline int sfsee_GetInputEndPosition(SfdHandle *handle) {
    SfdTransportState *transports;
    SfdTransportState *output;
    int position;
    transports = handle->fields.view_transports.transports;
    output = &transports[handle->fields.view_buffers
                             .buffers[transports[0].fields.view_parameter_14.parameter_14]
                             .fields.view_output_transport.output_transport];
    position = output->fields.view_state.state;
    if (position >= 0) {
        return position;
    }
    return -1;
}

static inline void sfsee_ExecEstimate(SfdHandle *handle, SfdSeekState *seek) {
    int changed;
    int position;
    int transport_position;
    SfdSeeWork *source;
    SfdSeekRequest *request;
    SfdTimerStreamTimeUnit *timer;
    source = seek->fields.view_work.work;
    request = &seek->fields.view_request.request;
    if (fn_12_23250(handle) != 0) {
        return;
    }
    changed = 0;
    if (source->fields.view_timing.timing.fields.view_discovered_file_size.discovered_file_size <=
        0) {
        if (request->fields.view_position.position == -3) {
            position = 0;
        } else {
            position = source->fields.view_timing.timing.fields.view_seek_position.seek_position;
        }
        if (position >= 0) {
            transport_position = sfsee_GetInputEndPosition(handle);
            if (transport_position != -1) {
                source->fields.view_timing.timing.fields.view_discovered_file_size
                    .discovered_file_size = position + transport_position;
                changed = 1;
            }
        }
    }
    if (source->fields.view_timing.timing.fields.view_discovered_total_time_value
            .discovered_total_time_value <= 0) {
        timer = &handle->fields.view_timer_state.timer_state.fields.view_stream_time.stream_time;
        if (timer->fields.view_value.value > 0) {
            source->fields.view_timing.timing.fields.view_discovered_total_time_value
                .discovered_total_time_value = timer->fields.view_value.value;
            changed = 1;
            source->fields.view_timing.timing.fields.view_discovered_total_time_scale
                .discovered_total_time_scale = timer->fields.view_scale.scale;
        }
    }
    if (changed != 0) {
        sfsee_UpdateByteRate(handle);
    }
}

void fn_12_2D288(SfdHandle *handle) {
    SfdSeekState *seek = &handle->fields.view_seek_state.seek_state;
    if (seek->fields.view_work.work == 0) {
        return;
    }
    fn_12_2D008(handle);
    sfsee_ExecEstimate(handle, seek);
}
