#include "types.h"

/* --- rel/movie_module/fn_12_22954.c --- */
typedef struct SJCK {
    unsigned char *data;
    long len;
} SJCK;

typedef struct SJ_u0 SJ_u0;

typedef struct SJInterface_u0 SJInterface_u0;

typedef void (*SJErrorCallback)(void *object, int error);

struct SJInterface_u0 {
    union {
        unsigned char padding_extent[48];
        struct {
            void *reserved[3];
        } view_reserved;
    } fields;
};

struct SJ_u0 {
    const SJInterface_u0 *interface;
};

typedef void *SfdCallbackObject;

typedef int SfdConditionValue;

typedef int SfdTransportValue;

typedef struct SfdHandle_u0 SfdHandle_u0;

typedef int (*SfdUserIsSkipFn)(SfdHandle_u0 *handle, int picture_type, int value, int scale);

typedef int (*SfdTimeSourceFn)(SfdHandle_u0 *handle, int *value, int *scale);

typedef struct SfdPlaybackSettings {
    int values_00[5];
    int frame_rate_code;
    int values_18[10];
} SfdPlaybackSettings;

typedef struct SfdPlaybackRuntime {
    union {
        unsigned char padding_extent[160];
        struct {
            unsigned char padding_field_14[20];
            int field_14;
        } view_field_14;
    } fields;
} SfdPlaybackRuntime;

typedef struct SfdTimerTimeUnit {
    union {
        unsigned char padding_extent[44];
        struct {
            int active;
        } view_active;
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
            int active;
        } view_active;
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
    union {
        unsigned char padding_extent[2196];
        struct {
            unsigned char padding_audio[76];
            SfdHeaderAudioInfo audio;
        } view_audio;
        struct {
            unsigned char padding_video[92];
            SfdHeaderVideoInfo video;
        } view_video;
    } fields;
} SfdHeaderState;

typedef struct SfdTimerSummary {
    long long total;
    long long minimum;
    long long maximum;
    int count;
    int field_1C;
} SfdTimerSummary;

typedef struct SfdTransportInterface_u0 SfdTransportInterface_u0;

typedef struct SfdTransportSetup_u0 SfdTransportSetup_u0;

typedef struct SfdVideoFrameState_u0 SfdVideoFrameState_u0;

typedef void (*SfdBufferHandleCallback)(SfdHandle_u0 *handle, int stream_index);

typedef void (*SfdBufferObjectCallback)(SfdCallbackObject object, int stream_index);

typedef struct SfdBufferChannel {
    union {
        unsigned char padding_extent[16];
        struct {
            SJ_u0 *stream_joint;
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
            int kind;
        } view_kind;
        struct {
            unsigned char padding_stream_joint[4];
            SJ_u0 *stream_joint;
        } view_stream_joint;
        struct {
            unsigned char padding_buffer[8];
            unsigned char *buffer;
        } view_buffer;
        struct {
            unsigned char padding_buffer_size[12];
            int buffer_size;
        } view_buffer_size;
        struct {
            unsigned char padding_extra_size[16];
            int extra_size;
        } view_extra_size;
        struct {
            unsigned char padding_field_14[20];
            int field_14;
        } view_field_14;
    } fields;
} SfdBufferSupply;

typedef struct SfdBufferRingWork {
    union {
        unsigned char padding_extent[60];
        struct {
            SfdBufferSupply supply;
        } view_supply;
        struct {
            unsigned char padding_delimiter_position[24];
            unsigned char *delimiter_position;
        } view_delimiter_position;
        struct {
            unsigned char padding_delimiter_end[28];
            unsigned char *delimiter_end;
        } view_delimiter_end;
        struct {
            unsigned char padding_write_total[32];
            int write_total;
        } view_write_total;
        struct {
            unsigned char padding_read_total[36];
            int read_total;
        } view_read_total;
        struct {
            unsigned char padding_pts_queue[40];
            SfdPtsQueue pts_queue;
        } view_pts_queue;
    } fields;
} SfdBufferRingWork;

typedef struct SfdBufferVideoWork {
    union {
        unsigned char padding_extent[20];
        struct {
            unsigned char *buffer;
        } view_buffer;
        struct {
            unsigned char padding_buffer_size[4];
            int buffer_size;
        } view_buffer_size;
        struct {
            unsigned char padding_reserved_08[8];
            int reserved_08;
        } view_reserved_08;
        struct {
            unsigned char padding_reserved_0C[12];
            int reserved_0C;
        } view_reserved_0C;
        struct {
            unsigned char padding_video_frames[16];
            SfdVideoFrameState_u0 *video_frames;
        } view_video_frames;
    } fields;
} SfdBufferVideoWork;

typedef struct SfdBufferAudioWork {
    union {
        unsigned char padding_extent[48];
        struct {
            unsigned char *buffer;
        } view_buffer;
        struct {
            unsigned char padding_buffer_size[4];
            int buffer_size;
        } view_buffer_size;
        struct {
            unsigned char padding_reserved[8];
            int reserved[7];
        } view_reserved;
        struct {
            unsigned char padding_reserved_tail[36];
            int reserved_tail[3];
        } view_reserved_tail;
    } fields;
} SfdBufferAudioWork;

typedef union SfdBufferWork {
    union {
        unsigned char padding_extent[60];
        struct {
            SfdBufferRingWork ring;
        } view_ring;
        struct {
            SfdBufferVideoWork video;
        } view_video;
        struct {
            SfdBufferAudioWork audio;
        } view_audio;
        struct {
            SfdBufferChannel user_channels[3];
        } view_user_channels;
    } fields;
} SfdBufferWork;

typedef int (*SfdTransportLifecycleFn)(SfdHandle_u0 *handle);

typedef int (*SfdTransportPauseFn)(SfdHandle_u0 *handle, int state);

typedef int (*SfdTransportTransferFn)(SfdHandle_u0 *handle, SfdTransportValue parameter, int value);

typedef int (*SfdTransportBufferFn)(SfdHandle_u0 *handle, void *buffer);

struct SfdTransportInterface_u0 {
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
            int storage_mode;
        } view_storage_mode;
        struct {
            unsigned char padding_active[4];
            int active;
        } view_active;
        struct {
            unsigned char padding_prepared[8];
            int prepared;
        } view_prepared;
        struct {
            unsigned char padding_terminated[12];
            int terminated;
        } view_terminated;
        struct {
            unsigned char padding_work[16];
            SfdBufferWork work;
        } view_work;
        struct {
            unsigned char padding_input_transport[76];
            int input_transport;
        } view_input_transport;
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

struct SfdVideoFrameState_u0 {
    union {
        unsigned char padding_extent[92];
        struct {
            int state;
        } view_state;
    } fields;
};

typedef struct SfdBufferCreateConfig {
    union {
        unsigned char padding_extent[44];
        struct {
            unsigned char padding_memory[4];
            unsigned char *memory;
        } view_memory;
        struct {
            unsigned char padding_buffer_sizes[8];
            int buffer_sizes[7];
        } view_buffer_sizes;
        struct {
            unsigned char padding_ring_alignment[40];
            int ring_alignment;
        } view_ring_alignment;
    } fields;
} SfdBufferCreateConfig;

typedef struct SfdCreateConfig {
    union {
        unsigned char padding_extent[68];
        struct {
            SfdBufferCreateConfig buffer;
        } view_buffer;
    } fields;
} SfdCreateConfig;

typedef struct SfdTransportState {
    union {
        unsigned char padding_extent[68];
        struct {
            int prepared;
        } view_prepared;
        struct {
            unsigned char padding_terminated[4];
            int terminated;
        } view_terminated;
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

struct SfdTransportSetup_u0 {
    const SfdTransportInterface_u0 *entries[9];
};

typedef struct SfdAudioOutputCallbacks_u0 SfdAudioOutputCallbacks_u0;

typedef int (*SfdAudioSetPanFn)(SfdHandle_u0 *, int, int, SfdAudioOutputCallbacks_u0 *);

typedef int (*SfdAudioGetPanFn)(SfdHandle_u0 *, int, SfdAudioOutputCallbacks_u0 *);

typedef int (*SfdAudioSetVolumeFn)(SfdHandle_u0 *, int, SfdAudioOutputCallbacks_u0 *);

typedef int (*SfdAudioGetVolumeFn)(SfdHandle_u0 *, SfdAudioOutputCallbacks_u0 *);

typedef void (*SfdAudioSetSpeedFn)(SfdHandle_u0 *, int);

struct SfdAudioOutputCallbacks_u0 {
    void *output_context;
    SfdAudioSetPanFn set_pan;
    SfdAudioGetPanFn get_pan;
    SfdAudioSetVolumeFn set_volume;
    SfdAudioGetVolumeFn get_volume;
    SfdAudioSetSpeedFn set_speed;
    int reserved_18;
};

struct SfdHandle_u0 {
    union {
        unsigned char padding_extent[13720];
        struct {
            unsigned char padding_video_frames[5344];
            SfdVideoFrameState_u0 video_frames[16];
        } view_video_frames;
    } fields;
};

int fn_12_22954(SfdHandle_u0 *handle, SfdBufferState *buffers, SfdBufferCreateConfig *create);

SJ_u0 *fn_80058498(void *buffer, int buffer_size, int extra_size);

int fn_12_24A88(SfdHandle_u0 *handle, int error);

void fn_12_24970(int *token);

void fn_12_24950(int *token);

void fn_12_2CFEC(SfdPtsQueue *queue);

static inline void sfbuf_SetSupply(SfdBufferState *buffer, SfdBufferRingWork *ring,
                                   SfdBufferSupply *supply, int active) {
    int token;
    fn_12_24970(&token);
    buffer->fields.view_active.active = active;
    ring->fields.view_supply.supply = *supply;
    ring->fields.view_delimiter_position.delimiter_position = 0;
    ring->fields.view_delimiter_end.delimiter_end = 0;
    ring->fields.view_write_total.write_total = 0;
    ring->fields.view_read_total.read_total = 0;
    fn_12_2CFEC(&ring->fields.view_pts_queue.pts_queue);
    fn_12_24950(&token);
}

static inline SJ_u0 *sfbuf_CreateStreamJoint(SfdBufferSupply *supply, unsigned int address,
                                          int buffer_size, int extra_size) {
    if (buffer_size <= 0) {
        return 0;
    }
    supply->fields.view_extra_size.extra_size = extra_size;
    supply->fields.view_field_14.field_14 = 0;
    supply->fields.view_stream_joint.stream_joint = fn_80058498((unsigned char *)address, buffer_size, extra_size);
    return supply->fields.view_stream_joint.stream_joint;
}

static inline int sfbuf_InitRing(SfdBufferState *buffer, unsigned int *address, int size,
                                 int extra_size) {
    int active;
    int storage_mode;
    SfdBufferSupply supply;
    int result;
    if (size == 0) {
        active = 0;
        storage_mode = 4;
    } else {
        active = 1;
        storage_mode = 5;
        supply.fields.view_kind.kind = 0;
        supply.fields.view_buffer.buffer = (unsigned char *)*address;
        supply.fields.view_buffer_size.buffer_size = size - extra_size;
        if (sfbuf_CreateStreamJoint(&supply, *address,
                                    supply.fields.view_buffer_size.buffer_size, extra_size) == 0) {
            return -1;
        }
        sfbuf_SetSupply(buffer, &buffer->fields.view_work.work.fields.view_ring.ring, &supply, 1);
    }
    buffer->fields.view_storage_mode.storage_mode = storage_mode;
    buffer->fields.view_active.active = active;
    buffer->fields.view_prepared.prepared = 0;
    buffer->fields.view_terminated.terminated = 0;
    buffer->fields.view_input_transport.input_transport = 9;
    buffer->fields.view_output_transport.output_transport = 9;
    return 0;
}

static inline void sfbuf_InitVideo(SfdHandle_u0 *handle, SfdBufferState *buffer, unsigned int *address,
                                   int *size) {
    long index;
    int active;
    active = *size != 0;
    buffer->fields.view_storage_mode.storage_mode = 1;
    buffer->fields.view_active.active = active;
    buffer->fields.view_prepared.prepared = 0;
    buffer->fields.view_terminated.terminated = 0;
    buffer->fields.view_input_transport.input_transport = 9;
    buffer->fields.view_output_transport.output_transport = 9;
    buffer->fields.view_work.work.fields.view_video.video.fields.view_buffer.buffer =
        (unsigned char *)*address;
    buffer->fields.view_work.work.fields.view_video.video.fields.view_buffer_size.buffer_size =
        *size;
    buffer->fields.view_work.work.fields.view_video.video.fields.view_reserved_08.reserved_08 = 0;
    buffer->fields.view_work.work.fields.view_video.video.fields.view_reserved_0C.reserved_0C = 0;
    buffer->fields.view_work.work.fields.view_video.video.fields.view_video_frames.video_frames =
        handle->fields.view_video_frames.video_frames;
    for (index = 0; index < 16; index++) {
        buffer->fields.view_work.work.fields.view_video.video.fields.view_video_frames
            .video_frames[index]
            .fields.view_state.state = 0;
    }
}

static inline void sfbuf_InitAudio(SfdBufferState *buffer, unsigned int *address, int *size) {
    int index;
    int active;
    active = *size != 0;
    buffer->fields.view_storage_mode.storage_mode = 2;
    buffer->fields.view_active.active = active;
    buffer->fields.view_prepared.prepared = 0;
    buffer->fields.view_terminated.terminated = 0;
    buffer->fields.view_input_transport.input_transport = 9;
    buffer->fields.view_output_transport.output_transport = 9;
    buffer->fields.view_work.work.fields.view_audio.audio.fields.view_buffer.buffer =
        (unsigned char *)*address;
    buffer->fields.view_work.work.fields.view_audio.audio.fields.view_buffer_size.buffer_size =
        *size;
    for (index = 0; index < 7; index++) {
        buffer->fields.view_work.work.fields.view_audio.audio.fields.view_reserved.reserved[index] =
            0;
    }
    buffer->fields.view_work.work.fields.view_audio.audio.fields.view_reserved_tail
        .reserved_tail[0] = 0;
    buffer->fields.view_work.work.fields.view_audio.audio.fields.view_reserved_tail
        .reserved_tail[1] = 0;
    buffer->fields.view_work.work.fields.view_audio.audio.fields.view_reserved_tail
        .reserved_tail[2] = 0;
}

int fn_12_22954(SfdHandle_u0 *handle, SfdBufferState *buffers, SfdBufferCreateConfig *create) {
    unsigned int addresses[9];
    int remainder;
    int result0;
    int result1;
    int result2;
    int index;
    unsigned int *cursor;
    unsigned int current;
    current = (unsigned int)create->fields.view_memory.memory;
    cursor = addresses;
    for (index = 0; index < 7; index++) {
        *cursor++ = current;
        current += create->fields.view_buffer_sizes.buffer_sizes[index];
    }
    *cursor = current;
    remainder = create->fields.view_buffer_sizes.buffer_sizes[0] %
                create->fields.view_ring_alignment.ring_alignment;
    result0 = sfbuf_InitRing(&buffers[0], &addresses[0],
                             create->fields.view_buffer_sizes.buffer_sizes[0], remainder);
    result1 = sfbuf_InitRing(&buffers[1], &addresses[1],
                             create->fields.view_buffer_sizes.buffer_sizes[1], 0x800);
    result2 = sfbuf_InitRing(&buffers[2], &addresses[2],
                             create->fields.view_buffer_sizes.buffer_sizes[2], 0);
    if (result0 != 0 || result1 != 0 || result2 != 0) {
        return fn_12_24A88(handle, 0xFF00040A);
    }
    sfbuf_InitVideo(handle, &buffers[3], &addresses[3],
                    &create->fields.view_buffer_sizes.buffer_sizes[3]);
    sfbuf_InitAudio(&buffers[4], &addresses[4], &create->fields.view_buffer_sizes.buffer_sizes[4]);
    sfbuf_InitVideo(handle, &buffers[5], &addresses[5],
                    &create->fields.view_buffer_sizes.buffer_sizes[5]);
    sfbuf_InitAudio(&buffers[6], &addresses[6], &create->fields.view_buffer_sizes.buffer_sizes[6]);
    buffers[7].fields.view_storage_mode.storage_mode = 3;
    buffers[7].fields.view_active.active = 1;
    buffers[7].fields.view_prepared.prepared = 0;
    buffers[7].fields.view_terminated.terminated = 0;
    buffers[7].fields.view_input_transport.input_transport = 9;
    buffers[7].fields.view_output_transport.output_transport = 9;
    for (index = 0; index < 3; index++) {
        buffers[7]
            .fields.view_work.work.fields.view_user_channels.user_channels[index]
            .fields.view_stream_joint.stream_joint = 0;
        buffers[7]
            .fields.view_work.work.fields.view_user_channels.user_channels[index]
            .fields.view_handle_callback.handle_callback = 0;
        buffers[7]
            .fields.view_work.work.fields.view_user_channels.user_channels[index]
            .fields.view_object_callback.object_callback = 0;
        buffers[7]
            .fields.view_work.work.fields.view_user_channels.user_channels[index]
            .fields.view_object.object = 0;
    }
    return 0;
}

/* --- rel/movie_module/fn_12_22FB4.c --- */
/* --- rel/movie_module/fn_12_22FB4.c --- */
/* --- rel/movie_module/fn_12_22FB4.c --- */
// fn_12_22FB4: empty in retail (single blr).
void fn_12_22FB4(void) {
}

/* --- rel/movie_module/fn_12_22FB8.c --- */
// fn_12_22FB8: empty in retail (single blr).
void fn_12_22FB8(void) {
}

/* --- rel/movie_module/fn_12_22FBC.c --- */
typedef struct MovieState {
    u8 pad_0[0x1a8];
    s32 value_1a8;
    u8 pad_1ac[4];
    s32 count_1b0;
    s32 index_1b4;
    s32 entries_1b8[1];
} MovieState;

typedef struct MovieModule {
    u8 pad_cc0[0xcc0];
    MovieState state;
} MovieModule;


s32 fn_12_22FBC(MovieModule *module, s32 *out_entry, s32 *out_value);

/* --- rel/movie_module/fn_12_23078.c --- */
typedef struct MovieState_u1 {
    u8 unk_000[0x1a8];
    int pending;
    u8 unk_1ac[4];
    s32 head;
    s32 tail;
    void *entries[0x20];
} MovieState_u1;

typedef struct MovieModule_u1 {
    u8 unk_000[0xcc0];
    MovieState_u1 state;
} MovieModule_u1;

int fn_12_23078(MovieModule_u1 *module, void *entry, int value);

/* --- rel/movie_module/fn_12_23120.c --- */
/* --- rel/movie_module/fn_12_23120.c --- */

typedef struct MovieModuleState {
    u8 pad_000[0x120];
    int field_120;
    int field_124;
    int field_128[32];
} MovieModuleState;

void fn_12_23120(void *arg0, int arg1);

/* --- rel/movie_module/fn_12_231A0.c --- */
extern u32 fn_12_2D73C(u32, u32);

s32 fn_12_231A0(u32 arg0);

/* --- rel/movie_module/fn_12_231F8.c --- */
s32 fn_12_231F8(u32 arg0);

/* --- rel/movie_module/fn_12_23250.c --- */
u32 fn_12_23250(u32 arg0);

/* --- rel/movie_module/fn_12_23280.c --- */
extern int fn_12_24990(void);
extern void fn_12_2D7DC(void *arg0, int arg1, int arg2);

int fn_12_23280(void *arg0);

/* --- rel/movie_module/fn_12_232DC.c --- */
extern u8 *fn_12_A0D8(u8 *data, int size, int mode);
extern u8 lbl_12_rodata_AB8[36];
extern u8 lbl_12_rodata_BD8[56];

typedef struct MovieInfo {
    u8 unk_000[8];
    u8 *field_008;
    u8 unk_00c[8];
    u32 field_014;
    u32 field_018;
    s32 field_01c;
    u32 field_020;
    u32 field_024;
} MovieInfo;

int fn_12_232DC(u8 *data, int size, MovieInfo *info);
