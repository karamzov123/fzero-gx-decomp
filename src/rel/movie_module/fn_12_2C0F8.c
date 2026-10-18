
#include "types.h"

typedef struct SJCK {
    unsigned char *data;
    long len;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface SJInterface;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface {
    union {
        unsigned char padding_extent[48];
        struct {
            unsigned char padding_get_num_data[36];
            int (*get_num_data)(SJ *sj, int channel);
        } view_get_num_data;
    } fields;
};

struct SJ {
    union {
        unsigned char padding_extent[4];
        struct {
            const SJInterface *interface;
        } view_interface;
    } fields;
};

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
    union {
        unsigned char padding_extent[160];
        struct {
            unsigned char padding_field_1C[28];
            int field_1C;
        } view_field_1C;
        struct {
            unsigned char padding_field_20[32];
            int field_20;
        } view_field_20;
    } fields;
} SfdPlaybackRuntime;

typedef struct SfdTimerTimeUnit {
    union {
        unsigned char padding_extent[44];
        struct {
            unsigned char padding_field_20[32];
            unsigned short field_20;
        } view_field_20;
    } fields;
} SfdTimerTimeUnit;

typedef struct SfdTimerSkipState {
    union {
        unsigned char padding_extent[36];
        struct {
            unsigned char padding_field_20[32];
            unsigned short field_20;
        } view_field_20;
    } fields;
} SfdTimerSkipState;

typedef struct SfdTimerStreamTimeUnit {
    union {
        unsigned char padding_extent[44];
        struct {
            unsigned char padding_field_1C[28];
            int field_1C;
        } view_field_1C;
        struct {
            unsigned char padding_field_20[32];
            unsigned short field_20;
        } view_field_20;
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
    union {
        unsigned char padding_extent[1504];
        struct {
            unsigned char padding_field_0284[644];
            int field_0284;
        } view_field_0284;
        struct {
            unsigned char padding_field_0288[648];
            int field_0288;
        } view_field_0288;
    } fields;
} SfdTimerState;

typedef struct SfdSeeWork SfdSeeWork;

typedef struct SfdSeekRequest {
    int field_00;
    int position;
    int field_08;
} SfdSeekRequest;

typedef struct SfdSeekState {
    union {
        unsigned char padding_extent[16];
        struct {
            SfdSeeWork *work;
        } view_work;
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
    union {
        unsigned char padding_extent[32];
        struct {
            unsigned char padding_field_1C[28];
            int field_1C;
        } view_field_1C;
    } fields;
} SfdTimerSummary;

typedef struct SfdTransportInterface SfdTransportInterface;

typedef struct SfdTransportSetup SfdTransportSetup;

typedef struct SfdVideoFrameState SfdVideoFrameState;

typedef void (*SfdBufferHandleCallback)(SfdHandle *handle, int stream_index);

typedef void (*SfdBufferObjectCallback)(SfdCallbackObject object, int stream_index);

typedef struct SfdBufferChannel {
    union {
        unsigned char padding_extent[16];
        struct {
            SJ *stream_joint;
        } view_stream_joint;
    } fields;
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
    union {
        unsigned char padding_extent[24];
        struct {
            unsigned char padding_stream_joint[4];
            SJ *stream_joint;
        } view_stream_joint;
        struct {
            unsigned char padding_buffer_size[12];
            int buffer_size;
        } view_buffer_size;
    } fields;
} SfdBufferSupply;

typedef struct SfdBufferRingWork {
    union {
        unsigned char padding_extent[60];
        struct {
            SfdBufferSupply supply;
        } view_supply;
    } fields;
} SfdBufferRingWork;

typedef struct SfdBufferVideoWork {
    union {
        unsigned char padding_extent[20];
        struct {
            unsigned char padding_buffer_size[4];
            int buffer_size;
        } view_buffer_size;
    } fields;
} SfdBufferVideoWork;

typedef struct SfdBufferAudioWork {
    union {
        unsigned char padding_extent[48];
        struct {
            unsigned char padding_buffer_size[4];
            int buffer_size;
        } view_buffer_size;
    } fields;
} SfdBufferAudioWork;

typedef union SfdBufferWork {
    union {
        unsigned char padding_extent[60];
        struct {
            SfdBufferRingWork ring;
        } view_ring;
    } fields;
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
    int state;
    int field_04;
    SfdVideoFrameInfo info;
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
            unsigned char padding_interface[12];
            const SfdTransportInterface *interface;
        } view_interface;
        struct {
            unsigned char padding_parameter_10[16];
            int parameter_10;
        } view_parameter_10;
    } fields;
} SfdTransportState;

typedef struct SfdUserOutputWork {
    int state;
    SfdBufferChannel channels[3];
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
            unsigned char padding_playback_state[72];
            int playback_state;
        } view_playback_state;
        struct {
            unsigned char padding_requested_state[76];
            int requested_state;
        } view_requested_state;
        struct {
            unsigned char padding_field_0050[80];
            int field_0050;
        } view_field_0050;
        struct {
            unsigned char padding_playback_runtime[2376];
            SfdPlaybackRuntime playback_runtime;
        } view_playback_runtime;
        struct {
            unsigned char padding_conditions_primary[2464];
            SfdConditionValue conditions_primary[100];
        } view_conditions_primary;
        struct {
            unsigned char padding_timer_state[3196];
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
    } fields;
};

int fn_12_2C0F8(SfdHandle *handle);

void fn_12_24970(int *token);

void fn_12_24950(int *token);

int fn_12_2E714(SfdHandle *handle, int *seconds, int *subsecond);

int fn_12_2E7C8(SfdHandle *handle, int *seconds, int *subsecond);

int fn_12_2EAC4(SfdHandle *handle);

int fn_12_2E42C(int lhs_seconds, int lhs_subsecond, int rhs_seconds, int rhs_subsecond);

SfdConditionValue fn_12_2D73C(SfdHandle *handle, int condition);

int fn_12_21D30(SfdHandle *handle, int buffer_index);

int fn_12_2F1D0(SfdHandle *handle, int transport_index);

int fn_12_2F210(SfdHandle *handle, int transport_index, int callback_index,
                SfdTransportValue parameter, int value);

int fn_12_2ADDC(SfdHandle *handle, int paused);

unsigned int UTY_MulDiv(int multiplicand, int multiplier, int divisor);

int fn_12_332DC(int lhs_value, int lhs_scale, int rhs_value, int rhs_scale);

static inline int sfply_StopTr(SfdHandle *handle) {
    int result;
    if (handle->fields.view_playback_state.playback_state == 4) {
        result = fn_12_2F210(handle, 7, 7, 0, 0);
        if (result != 0) {
            return result;
        }
    }
    handle->fields.view_playback_state.playback_state = 1;
    handle->fields.view_requested_state.requested_state = 1;
    return 0;
}

static inline int sfply_IsVidBufFull(SfdHandle *handle) {
    int buffer_index =
        handle->fields.view_transports.transports[2].fields.view_parameter_10.parameter_10;
    SfdBufferRingWork *ring = &handle->fields.view_buffers.buffers[buffer_index]
                                   .fields.view_work.work.fields.view_ring.ring;
    int data_size =
        ring->fields.view_supply.supply.fields.view_stream_joint.stream_joint->fields.view_interface
            .interface->fields.view_get_num_data.get_num_data(
                ring->fields.view_supply.supply.fields.view_stream_joint.stream_joint, 1);
    if (data_size >=
            (ring->fields.view_supply.supply.fields.view_buffer_size.buffer_size * 80) / 100 ||
        data_size >= fn_12_2D73C(handle, 0x46)) {
        return 1;
    }
    return 0;
}

int fn_12_2BE3C(SfdHandle *handle);

static inline int sfply_IsEndTime(SfdHandle *handle) {
    int current_seconds;
    int current_subsecond;
    int end_seconds = handle->fields.view_conditions_primary.conditions_primary[20];
    int end_subsecond = handle->fields.view_conditions_primary.conditions_primary[21];
    if (end_seconds == -4)
        return 0;
    fn_12_2E714(handle, &current_seconds, &current_subsecond);
    if (current_seconds < 0)
        return 0;
    if (fn_12_332DC(current_seconds, current_subsecond, end_seconds, end_subsecond) != 0)
        return 0;
    return 1;
}

static inline int sfply_IsTermAll(SfdHandle *handle) {
    int video_terminated;
    int audio_terminated;
    int terminated;
    if (handle->fields.view_conditions_primary.conditions_primary[6] == 0 &&
        handle->fields.view_conditions_primary.conditions_primary[5] == 0)
        return 1;
    terminated = 0;
    video_terminated = fn_12_2F1D0(handle, 6);
    audio_terminated = fn_12_2F1D0(handle, 7);
    switch (fn_12_2D73C(handle, 0x19)) {
    case 1:
        terminated = audio_terminated;
        break;
    case 2:
        terminated = video_terminated;
        break;
    case 3:
        terminated = audio_terminated | video_terminated;
        break;
    case 0:
        terminated = audio_terminated & video_terminated;
        break;
    }
    return terminated;
}

static inline int sfply_IsStagnant(SfdHandle *handle) {
    if (handle->fields.view_playback_state.playback_state != 4 ||
        handle->fields.view_field_0050.field_0050 == 1 ||
        handle->fields.view_playback_runtime.playback_runtime.fields.view_field_1C.field_1C == 1)
        return 0;
    if (fn_12_2EAC4(handle) != 0)
        return 1;
    return 0;
}

static inline int sfply_IsOverTime(SfdHandle *handle) {
    int current_seconds;
    int current_subsecond;
    int stop_seconds;
    if (handle->fields.view_playback_state.playback_state != 4 ||
        handle->fields.view_field_0050.field_0050 == 1 ||
        handle->fields.view_playback_runtime.playback_runtime.fields.view_field_1C.field_1C == 1)
        return 0;
    if (fn_12_2E7C8(handle, &current_seconds, &current_subsecond) != 0)
        return 0;
    if (current_seconds < 0)
        return 0;
    stop_seconds = fn_12_2D73C(handle, 0x36);
    if (fn_12_2E42C(stop_seconds, 1000, current_seconds, current_subsecond) != 0)
        return 1;
    return 0;
}

static inline int sfply_StopPlay(SfdHandle *handle) {
    int result = sfply_StopTr(handle);
    if (result != 0)
        return result;
    handle->fields.view_requested_state.requested_state = 6;
    return 0;
}

static inline int sfply_IsTermAny(SfdHandle *handle) {
    int buffer_index;
    if (fn_12_2D73C(handle, 5) != 0 && fn_12_2F1D0(handle, 6) != 0)
        return 1;
    if (fn_12_2D73C(handle, 6) != 0 && fn_12_2F1D0(handle, 7) != 0)
        return 1;
    for (buffer_index = 0; buffer_index < 8; buffer_index++) {
        if (fn_12_21D30(handle, buffer_index) != 0)
            return 1;
    }
    return 0;
}

static inline int sfply_IsAudBufFull(SfdHandle *handle) {
    int buffer_index =
        handle->fields.view_transports.transports[3].fields.view_parameter_10.parameter_10;
    SfdBufferRingWork *ring = &handle->fields.view_buffers.buffers[buffer_index]
                                   .fields.view_work.work.fields.view_ring.ring;
    int data_size =
        ring->fields.view_supply.supply.fields.view_stream_joint.stream_joint->fields.view_interface
            .interface->fields.view_get_num_data.get_num_data(
                ring->fields.view_supply.supply.fields.view_stream_joint.stream_joint, 1);
    return data_size >=
           (ring->fields.view_supply.supply.fields.view_buffer_size.buffer_size * 80) / 100;
}

static inline int sfply_IsBpaOff(SfdHandle *handle) {
    int current_seconds;
    int current_subsecond;
    int reference_seconds;
    int reference_scale;
    if (sfply_IsTermAny(handle) != 0)
        return 1;
    if (fn_12_2D73C(handle, 5) == 1) {
        if (sfply_IsVidBufFull(handle) != 0)
            return 1;
    }
    if (fn_12_2D73C(handle, 6) == 1) {
        if (sfply_IsAudBufFull(handle) != 0)
            return 1;
    }
    fn_12_2E714(handle, &current_seconds, &current_subsecond);
    reference_seconds =
        handle->fields.view_timer_state.timer_state.fields.view_field_0284.field_0284;
    reference_scale = handle->fields.view_timer_state.timer_state.fields.view_field_0288.field_0288;
    reference_seconds -= UTY_MulDiv(fn_12_2D73C(handle, 0x45), reference_scale, 1000000);
    if (fn_12_2E42C(current_seconds, current_subsecond, reference_seconds, reference_scale) != 0)
        return 1;
    return 0;
}

int fn_12_2C0F8(SfdHandle *handle) {
    int result;
    int state;
    int token;
    if (sfply_IsEndTime(handle) != 0 || sfply_IsTermAll(handle) != 0 ||
        sfply_IsStagnant(handle) != 0 || sfply_IsOverTime(handle) != 0) {
        result = sfply_StopPlay(handle);
    } else {
        result = 0;
    }
    if (result != 0) {
        return handle->fields.view_playback_state.playback_state;
    }
    fn_12_24970(&token);
    result = 0;
    if (handle->fields.view_playback_runtime.playback_runtime.fields.view_field_1C.field_1C == 0) {
        if (fn_12_2BE3C(handle) != 0) {
            handle->fields.view_playback_runtime.playback_runtime.fields.view_field_1C.field_1C = 1;
            handle->fields.view_playback_runtime.playback_runtime.fields.view_field_20.field_20++;
            result = fn_12_2ADDC(handle, 1);
        }
    } else {
        if (sfply_IsBpaOff(handle) != 0) {
            handle->fields.view_playback_runtime.playback_runtime.fields.view_field_1C.field_1C = 0;
            result = fn_12_2ADDC(handle, 0);
        }
    }
    fn_12_24950(&token);
    if (result != 0) {
        return handle->fields.view_playback_state.playback_state;
    }
    state = handle->fields.view_playback_state.playback_state;
    if (handle->fields.view_requested_state.requested_state != 5) {
        if (handle->fields.view_requested_state.requested_state < 5) {
            return state;
        }
        if (handle->fields.view_requested_state.requested_state < 7) {
            state = 6;
        }
    }
    return state;
}
