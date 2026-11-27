#include "types.h"

/* fzgx:begin fn_12_21C00 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_21C00.c --- */
typedef struct MovieModule_u1_u0 MovieModule_u1_u0;
typedef struct MovieObject_u0 MovieObject_u0;
typedef struct MovieObjectVtable_u0 MovieObjectVtable_u0;

struct MovieObjectVtable_u0 {
    u8 _pad0[0x18];
    int (*read)(MovieObject_u0 *, int, u32, void *);
    int (*get)(MovieObject_u0 *, int, void *);
    u8 _pad1[4];
    int (*read_count)(MovieObject_u0 *, int);
};

struct MovieObject_u0 {
    MovieObjectVtable_u0 *vtable;
};

struct MovieModule_u1_u0 {
    u8 _pad0[0x1144];
    int enabled;
    u8 _pad1[0xc];
    MovieObject_u0 *movie;
};

extern void fn_12_24970(u32 *);
extern void fn_12_24950(u32 *);

int fn_12_21C00(MovieModule_u1_u0 *modules, int index) {
    int (*fzgx_live)(MovieObject_u0 *, int);
    u32 state;
    int out2[2];
    int out1[2];
    int result;
    MovieObject_u0 *movie;
    u32 extra;
    MovieModule_u1_u0 *module;

    module = (MovieModule_u1_u0 *)((u8 *)modules + index * 0x74);
    extra = result = 0;
    movie = module->movie;
    if (module->enabled != 0 && movie != 0) {
        fn_12_24970(&state);
        fzgx_live = movie->vtable->read_count;
        result = fzgx_live(movie, 1);
        movie->vtable->read(movie, 1, 0x7fffffff, out1);
        if (out1[1] < result) {
            movie->vtable->read(movie, 1, 0x7fffffff, out2);
            movie->vtable->get(movie, 1, out2);
        } else {
            out2[0] = 0;
            out2[1] = 0;
        }
        movie->vtable->get(movie, 1, out1);
        result = out1[1];
        extra = out2[1];
        fn_12_24950(&state);
    }
    return result + (int)extra;
}
/* fzgx:end fn_12_21C00 */

/* fzgx:begin fn_12_21D30 noprologue */

/* --- rel/movie_module/fn_12_21D30.c --- */
/* --- rel/movie_module/fn_12_21D30.c --- */
/* --- rel/movie_module/fn_12_21D30.c --- */
struct fn_12_21D30_E116_u32 { u32 unk_0; u8 pad_4[0x70]; };
struct fn_12_21D30_Arg0 {
    u8 pad_0[0x114C];
    struct fn_12_21D30_E116_u32 unk_114C[1];
};

u32 fn_12_21D30(struct fn_12_21D30_Arg0 *arg0, u32 arg1) {
    return arg0->unk_114C[arg1].unk_0;
}
/* fzgx:end fn_12_21D30 */

/* fzgx:begin fn_12_21D40 */

/* --- rel/movie_module/fn_12_21D40.c --- */
void fn_12_21D40(void *base, int index, int value) {
    u8 *p = (u8 *)base;
    int offset = index * 0x74;
    p += offset;
    *(int *)(p + 0x114c) = value;
}
/* fzgx:end fn_12_21D40 */

/* fzgx:begin fn_12_21D50 noprologue */

/* --- rel/movie_module/fn_12_21D50.c --- */
typedef struct MovieEntry {
    int value;
    char unk04[0x70];
} MovieEntry;

typedef struct MovieModule_u1 {
    char unk0000[0x1148];
    MovieEntry entries[1];
} MovieModule_u1;

int fn_12_21D50(MovieModule_u1 *module, int index) {
    return module->entries[index].value;
}
/* fzgx:end fn_12_21D50 */

/* fzgx:begin fn_12_21D60 noprologue */

/* --- rel/movie_module/fn_12_21D60.c --- */
typedef struct MovieEntry_u1 {
    int value;
    u8 padding[0x70];
} MovieEntry_u1;

typedef struct MovieModule_u1_u1 {
    u8 padding[0x1148];
    MovieEntry_u1 entries[1];
} MovieModule_u1_u1;

void fn_12_21D60(MovieModule_u1_u1 *module, int index, int value) {
    module->entries[index].value = value;
}
/* fzgx:end fn_12_21D60 */

/* fzgx:begin fn_12_21D70 noprologue */

/* --- rel/movie_module/fn_12_21D70.c --- */
typedef struct MovieRecord {
    u8 padding00[0x1144];
    int status;
    u8 padding1148[0x44];
    void *resource;
} MovieRecord;

typedef struct MovieModule_u2 {
    u8 padding00[0x44];
    int active;
} MovieModule_u2;

extern int fn_12_2F210(MovieModule_u2 *module, void *resource, int size, void *argument, int flags);

int fn_12_21D70(MovieModule_u2 *module, int index, void *argument) {
    int result = 0;
    MovieRecord *entry = (MovieRecord *)((u8 *)module + index * 0x74);

    if (entry->status == 0) {
        result = fn_12_2F210(module, entry->resource, 0xc, argument, 0);
    }

    module->active = 1;
    return result;
}
/* fzgx:end fn_12_21D70 */

/* fzgx:begin fn_12_21DD4 noprologue */
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
/* fzgx:end fn_12_21DD4 */

/* fzgx:begin fn_12_21E20 noprologue */

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
/* fzgx:end fn_12_21E20 */

/* fzgx:begin fn_12_21E40 noprologue */

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
/* fzgx:end fn_12_21E40 */

/* fzgx:begin fn_12_21E94 noprologue */

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
/* fzgx:end fn_12_21E94 */

/* fzgx:begin fn_12_21F28 noprologue */

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
/* fzgx:end fn_12_21F28 */

/* fzgx:begin fn_12_21F38 noprologue */

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
/* fzgx:end fn_12_21F38 */

/* fzgx:begin fn_12_21F48 noprologue */

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
/* fzgx:end fn_12_21F48 */

/* fzgx:begin fn_12_21FA4 noprologue */

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
/* fzgx:end fn_12_21FA4 */

/* fzgx:begin fn_12_22008 noprologue */

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
/* fzgx:end fn_12_22008 */

/* fzgx:begin fn_12_22254 noprologue */

#include "types.h"

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

typedef union SfdBufferWork {
    SfdBufferRingWork ring;
    unsigned char extent[0x3C];
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

typedef struct SfdBufferHn {
    unsigned char pad[0x1140];
    SfdBufferState buffer;
} SfdBufferHn;

int fn_12_24A88(SfdHandle *handle, int error);
extern void fn_12_24970(int *lock);
extern void fn_12_24950(int *lock);

static inline int sfbuf_RingAddWriteSub(SfdHandle *handle, int buffer_index, int amount) {
    int lock;
    int needed;
    int result = 0;
    SJCK remainder;
    SJCK chunk;
    SfdBufferRingWork *ring;
    SJ *sj;
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
        sj->interface->get_chunk(sj, 0, amount, &chunk);
        sj->interface->put_chunk(sj, 1, &chunk);
        if (chunk.len < amount) {
            needed = amount - chunk.len;
            sj->interface->get_chunk(sj, 0, needed, &remainder);
            sj->interface->put_chunk(sj, 1, &remainder);
            if (remainder.len < needed) {
                result = fn_12_24A88(handle, 0xFF00040B);
            }
        }
        if (ring->write_total >= 0) {
            ring->write_total += amount;
        }
        handle->field_0044 = 1;
        fn_12_24950(&lock);
    }
    return result;
}

int fn_12_22254(SfdHandle *handle, int buffer_index, int amount, int value) {
    return sfbuf_RingAddWriteSub(handle, buffer_index, amount);
}
/* fzgx:end fn_12_22254 */

/* fzgx:begin fn_12_22390 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_22390.c --- */
typedef struct MovieObject MovieObject;

typedef struct MovieVtable {
    char padding[0x18];
    u32 (*fn18)(MovieObject *, int, int, void *);
    u32 (*fn1c)(MovieObject *, int, void *);
    char padding2[4];
    u32 (*fn24)(MovieObject *, int);
} MovieVtable;

struct MovieObject {
    MovieVtable *vtable;
};

typedef struct MovieEntry {
    char padding0[0x1144];
    int field;
    char padding1[0xc];
    MovieObject *obj;
} MovieEntry;

typedef struct MovieState {
    u8 data[4];
} MovieState;

extern void fn_12_24970(MovieState *state);
extern void fn_12_24950(MovieState *state);

int fn_12_22390(u8 *module, int index, u32 *out) {
    MovieState state;
    u32 w[2];
    u32 v[2];
    MovieEntry *entry;
    MovieObject *obj;
    int result;

    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0;
    out[4] = 0;
    out[5] = 0;
    out[6] = 0;
    entry = (MovieEntry *)(module + index * 0x74);
    obj = entry->obj;
    if (entry->field == 0 || obj == 0) {
        return 0;
    }
    fn_12_24970(&state);
    result = obj->vtable->fn24(obj, 1);
    obj->vtable->fn18(obj, 1, 0x7fffffff, v);
    if ((int)v[1] < result) {
        obj->vtable->fn18(obj, 1, 0x7fffffff, w);
        obj->vtable->fn1c(obj, 1, w);
    } else {
        w[0] = 0;
        w[1] = 0;
    }
    obj->vtable->fn1c(obj, 1, v);
    out[0] = v[0];
    out[1] = v[1];
    out[2] = w[0];
    out[3] = w[1];
    fn_12_24950(&state);
    return 0;
}
/* fzgx:end fn_12_22390 */

/* fzgx:begin fn_12_224FC */

/* --- rel/movie_module/fn_12_224FC.c --- */
s32 fn_12_224FC(u8 *arg0, int arg1, u32 *arg2) {
    MovieState loc_8;
    MovieEntry *v0;
    struct { u32 a[2]; } loc_14;
    u32 loc_C[2];
    MovieObject *v1;
    int v4;
    arg2[0] = 0;
    v0 = (MovieEntry *)(arg0 + arg1 * 116);
    arg2[1] = 0;
    arg2[2] = 0;
    arg2[3] = 0;
    arg2[4] = 0;
    arg2[5] = 0;
    arg2[6] = 0;
    v1 = v0->obj;
    if (v0->field == 0 || v1 == 0) {
        return 0;
    }
    fn_12_24970(&loc_8);
    v4 = v1->vtable->fn24(v1, 0);
    v1->vtable->fn18(v1, 0, 0x7fffffff, loc_C);
    if ((s32)loc_C[1] < v4) {
        v1->vtable->fn18(v1, 0, 0x7fffffff, &loc_14);
        v1->vtable->fn1c(v1, 0, &loc_14);
    } else {
        loc_14.a[0] = 0;
        loc_14.a[1] = 0;
    }
    v1->vtable->fn1c(v1, 0, loc_C);
    arg2[0] = loc_C[0];
    arg2[1] = loc_C[1];
    arg2[2] = loc_14.a[0];
    arg2[3] = loc_14.a[1];
    fn_12_24950(&loc_8);
    return 0;
}
/* fzgx:end fn_12_224FC */

/* fzgx:begin fn_12_22668 noprologue */

/* --- rel/movie_module/fn_12_22668.c --- */
struct fn_12_22668_Copy16 {
    u32 a[4];
};

struct fn_12_22668_Entry {
    u8 pad[0x1150];
};

void fn_12_22668(u8 *module, int index, int subindex, struct fn_12_22668_Copy16 *dst) {
    struct fn_12_22668_Entry *entry;

    entry = (struct fn_12_22668_Entry *)(module + index * 0x74);
    entry = (struct fn_12_22668_Entry *)((u8 *)entry + subindex * 0x10);
    *dst = *(struct fn_12_22668_Copy16 *)((u8 *)entry + 0x1150);
}
/* fzgx:end fn_12_22668 */

/* fzgx:begin fn_12_2269C noprologue */

/* --- rel/movie_module/fn_12_2269C.c --- */
struct fn_12_2269C_Copy16 {
    u32 a[4];
};

struct fn_12_2269C_Entry {
    u8 pad[0x1150];
};

void fn_12_2269C(u8 *module, int index, int subindex,
                 struct fn_12_2269C_Copy16 *src) {
    struct fn_12_2269C_Entry *entry;

    entry = (struct fn_12_2269C_Entry *)(module + index * 0x74);
    entry = (struct fn_12_2269C_Entry *)((u8 *)entry + subindex * 0x10);
    *(struct fn_12_2269C_Copy16 *)((u8 *)entry + 0x1150) = *src;
}
/* fzgx:end fn_12_2269C */

/* fzgx:begin fn_12_226D0 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_226D0.c --- */
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

typedef struct SfdBufferHn {
    unsigned char pad[4416];
    SfdBufferState buffer;
} SfdBufferHn;

int fn_12_24A88(SfdHandle *handle, int error);

void fn_12_24970(int *token);

void fn_12_24950(int *token);

void fn_12_2CFEC(SfdPtsQueue *queue);

int fn_12_2F1B4(SfdHandle *handle, int transport_index);

static inline int sfbuf_CheckSupply(SfdBufferSupply *supply) {
    if (supply->stream_joint == 0) {
        return -1;
    }
    if (supply->kind == 0) {
        if (supply->buffer == 0) {
            return -1;
        }
        if (supply->buffer_size <= 0) {
            return -1;
        }
        if (supply->field_14 > 0) {
            return -1;
        }
    }
    return 0;
}

static inline void sfbuf_SetSupply(SfdBufferState *buffer, SfdBufferRingWork *ring,
                                   SfdBufferSupply *supply, int active) {
    int token;
    fn_12_24970(&token);
    buffer->active = active;
    ring->supply = *supply;
    ring->delimiter_position = 0;
    ring->delimiter_end = 0;
    ring->write_total = 0;
    ring->read_total = 0;
    fn_12_2CFEC(&ring->pts_queue);
    fn_12_24950(&token);
}

int fn_12_226D0(SfdHandle *handle, SfdBufferSupply *supply) {
    int buffer_index;
    SfdBufferRingWork *ring;
    SfdBufferState *buffer;
    SfdBufferHn *hn;
    if (sfbuf_CheckSupply(supply) != 0) {
        return fn_12_24A88(handle, 0xFF000408);
    }
    if (fn_12_2F1B4(handle, 1) != 0) {
        buffer_index = 0;
    } else if (fn_12_2F1B4(handle, 2) != 0) {
        buffer_index = 1;
    } else if (fn_12_2F1B4(handle, 3) != 0) {
        buffer_index = 2;
    } else {
        buffer_index = 0;
    }
    hn = (SfdBufferHn *)((unsigned char *)handle + buffer_index * sizeof(SfdBufferState));
    buffer = &hn->buffer;
    ring = &buffer->work.ring;
    if (hn->buffer.storage_mode != 4) {
        return fn_12_24A88(handle, 0xFF000409);
    }
    sfbuf_SetSupply(buffer, ring, supply, supply->stream_joint != 0);
    return 0;
}
/* fzgx:end fn_12_226D0 */

/* fzgx:begin fn_12_22888 noprologue */

/* --- rel/movie_module/fn_12_22888.c --- */
typedef struct MovieObject MovieObject;

typedef struct MovieVtable {
    u32 pad[3];
    void (*fn0c)(MovieObject *);
} MovieVtable;

struct MovieObject {
    MovieVtable *vtable;
};

typedef struct MovieSub {
    u32 pad;
    MovieObject *obj;
} MovieSub;

typedef struct MovieEntry {
    int field;
    u8 pad[0xC];
    MovieSub sub;
    u8 pad2[0x5C];
} MovieEntry;

void fn_12_22888(u8 *module) {
    MovieEntry *entries = (MovieEntry *)(module + 0x1140);
    MovieSub *s;
    MovieObject *o;

    s = &entries[0].sub;
    if (entries[0].field == 5 && (o = s->obj) != 0) {
        o->vtable->fn0c(o);
        s->obj = 0;
    }
    s = &entries[1].sub;
    if (entries[1].field == 5 && (o = s->obj) != 0) {
        o->vtable->fn0c(o);
        s->obj = 0;
    }
    s = &entries[2].sub;
    if (entries[2].field == 5 && (o = s->obj) != 0) {
        o->vtable->fn0c(o);
        s->obj = 0;
    }
}
/* fzgx:end fn_12_22888 */

/* fzgx:begin fn_12_22954 noprologue */
#include "types.h"

typedef struct SJ_u0 SJ_u0;

typedef struct SJInterface_u0 SJInterface_u0;

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

typedef struct SfdHandle_u0 SfdHandle_u0;

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

struct SfdHandle_u0 {
    union {
        unsigned char padding_extent[13720];
        struct {
            unsigned char padding_video_frames[5344];
            SfdVideoFrameState_u0 video_frames[16];
        } view_video_frames;
    } fields;
};

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
/* fzgx:end fn_12_22954 */

/* fzgx:begin fn_12_22FB4 */

/* --- rel/movie_module/fn_12_22FB4.c --- */
/* --- rel/movie_module/fn_12_22FB4.c --- */
/* --- rel/movie_module/fn_12_22FB4.c --- */
// fn_12_22FB4: empty in retail (single blr).
void fn_12_22FB4(void) {
}
/* fzgx:end fn_12_22FB4 */

/* fzgx:begin fn_12_22FB8 */

/* --- rel/movie_module/fn_12_22FB8.c --- */
// fn_12_22FB8: empty in retail (single blr).
void fn_12_22FB8(void) {
}
/* fzgx:end fn_12_22FB8 */
