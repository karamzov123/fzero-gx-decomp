
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

typedef struct SJCK {
    union {
        unsigned char padding_extent[8];
        struct {
            unsigned char *data;
        } view_data;
        struct {
            unsigned char padding_len[4];
            long len;
        } view_len;
    } fields;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface SJInterface;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface {
    union {
        unsigned char padding_extent[48];
        struct {
            unsigned char padding_get_chunk[24];
            void (*get_chunk)(SJ *sj, long channel, long max_size, SJCK *chunk);
        } view_get_chunk;
        struct {
            unsigned char padding_put_chunk[32];
            void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
        } view_put_chunk;
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
        struct {
            unsigned char padding_handle_callback[4];
            SfdBufferHandleCallback handle_callback;
        } view_handle_callback;
        struct {
            unsigned char padding_object_callback[8];
            SfdBufferObjectCallback object_callback;
        } view_object_callback;
        struct {
            unsigned char padding_object[12];
            SfdCallbackObject object;
        } view_object;
    } fields;
} SfdBufferChannel;

typedef struct SfdPtsEntry {
    union {
        unsigned char padding_extent[16];
        struct {
            unsigned char padding_data[8];
            unsigned char *data;
        } view_data;
    } fields;
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
    } fields;
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
            unsigned char padding_buffer_output3[28];
            int buffer_output3;
        } view_buffer_output3;
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
            unsigned char padding_transports[6816];
            SfdTransportState transports[9];
        } view_transports;
    } fields;
};

int fn_12_25748(SfdHandle *handle, int stream_index, const unsigned char *data, int size,
                long long pts);

int fn_12_247BC(SfdHandle *handle, int stream_index, const unsigned char *data, int size,
                int *header_flag);

void fn_12_22668(SfdHandle *handle, int buffer_index, int channel, SfdBufferChannel *output);

void *fn_12_57F0(void *destination, const void *source, unsigned long size);

extern int lbl_12_bss_7E88;

static inline int sfmps_CopyToSj(SJ *sj, const unsigned char *data, int size) {
    SJCK second_chunk;
    SJCK first_chunk;
    if (sj->fields.view_interface.interface->fields.view_get_num_data.get_num_data(sj, 0) < size) {
        return 0;
    }
    sj->fields.view_interface.interface->fields.view_get_chunk.get_chunk(sj, 0, size, &first_chunk);
    fn_12_57F0(first_chunk.fields.view_data.data, data, first_chunk.fields.view_len.len);
    sj->fields.view_interface.interface->fields.view_put_chunk.put_chunk(sj, 1, &first_chunk);
    if (first_chunk.fields.view_len.len == 0) {
        return 0;
    }
    size -= first_chunk.fields.view_len.len;
    data += first_chunk.fields.view_len.len;
    if (size > 0) {
        sj->fields.view_interface.interface->fields.view_get_chunk.get_chunk(sj, 0, size,
                                                                             &second_chunk);
        fn_12_57F0(second_chunk.fields.view_data.data, data, second_chunk.fields.view_len.len);
        sj->fields.view_interface.interface->fields.view_put_chunk.put_chunk(sj, 1, &second_chunk);
        if (second_chunk.fields.view_len.len != size) {
            lbl_12_bss_7E88++;
        }
    }
    return 1;
}

static inline int sfmps_CopyUoch(SfdHandle *handle, int stream_index, const unsigned char *data,
                                 int size) {
    SfdBufferChannel channel;
    SfdBufferHandleCallback handle_callback;
    SfdBufferObjectCallback object_callback;
    SfdCallbackObject object;
    SJ *stream_joint;
    int result;
    fn_12_22668(
        handle,
        handle->fields.view_transports.transports[1].fields.view_buffer_output3.buffer_output3,
        stream_index, &channel);
    stream_joint = channel.fields.view_stream_joint.stream_joint;
    handle_callback = channel.fields.view_handle_callback.handle_callback;
    object_callback = channel.fields.view_object_callback.object_callback;
    object = channel.fields.view_object.object;
    if (stream_joint == 0) {
        return 1;
    }
    result = sfmps_CopyToSj(stream_joint, data, size);
    if (result == 1) {
        if (handle_callback != 0) {
            handle_callback(handle, stream_index);
        }
        if (object_callback != 0) {
            object_callback(object, stream_index);
        }
    }
    return result;
}

static inline int sfmps_CopyUo(SfdHandle *handle, int stream_index, const unsigned char *data,
                               int size) {
    if (handle->fields.view_transports.transports[1].fields.view_buffer_output3.buffer_output3 ==
        8) {
        return 1;
    }
    return sfmps_CopyUoch(handle, stream_index, data, size);
}

int fn_12_25748(SfdHandle *handle, int stream_index, const unsigned char *data, int size,
                long long pts) {
    int header_flag;
    if (fn_12_247BC(handle, stream_index, data, size, &header_flag) != 0) {
        if (header_flag != 0) {
            data -= 0x12;
            size += 0x12;
            sfmps_CopyUo(handle, 0, data, size);
        }
        return 1;
    }
    return sfmps_CopyUo(handle, stream_index, data, size);
}
