#include "types.h"

typedef int SfdConditionValue;

typedef struct fn_12_2D008_SfdHandle fn_12_2D008_SfdHandle;

typedef struct fn_12_2D008_SfdSeekState {
    fn_12_2D008_SfdHandle *source_handle;
    int field_04;
    int field_08;
    int field_0C;
} fn_12_2D008_SfdSeekState;

struct fn_12_2D008_SfdHandle {
    union {
        unsigned char padding_extent[13720];
        struct {
            unsigned char padding_seek_state[10504];
            fn_12_2D008_SfdSeekState seek_state;
        } view_seek_state;
    } fields;
};

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

typedef struct SfdTimerState {
    union {
        unsigned char padding_extent[1504];
        struct {
            unsigned char padding_stream_time[148];
            SfdTimerStreamTimeUnit stream_time;
        } view_stream_time;
    } fields;
} SfdTimerState;

typedef struct SJCK {
    unsigned char *data;
    long len;
} SJCK;

typedef void (*SJErrorCallback)(void *object, int error);

typedef struct SJInterface SJInterface;

typedef struct SJ SJ;

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

typedef struct SfdBufferSupply {
    int kind;
    SJ *stream_joint;
    unsigned char *buffer;
    int buffer_size;
    int extra_size;
    int field_14;
} SfdBufferSupply;

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
    SfdBufferSupply supply;
    unsigned char *delimiter_position;
    unsigned char *delimiter_end;
    int write_total;
    int read_total;
    SfdPtsQueue pts_queue;
} SfdBufferRingWork;

typedef struct SfdVideoFrameState SfdVideoFrameState;

struct SfdVideoFrameState {
    union {
        unsigned char padding_extent[136];
        struct {
            int state;
        } view_state;
    } fields;
};

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

typedef struct fn_12_2D288_SfdHandle fn_12_2D288_SfdHandle;

typedef void (*SfdBufferHandleCallback)(fn_12_2D288_SfdHandle *handle, int stream_index);

typedef void *SfdCallbackObject;

typedef void (*SfdBufferObjectCallback)(SfdCallbackObject object, int stream_index);

typedef struct SfdBufferChannel {
    SJ *stream_joint;
    SfdBufferHandleCallback handle_callback;
    SfdBufferObjectCallback object_callback;
    SfdCallbackObject object;
} SfdBufferChannel;

typedef union SfdBufferWork {
    SfdBufferRingWork ring;
    SfdBufferVideoWork video;
    SfdBufferAudioWork audio;
    SfdBufferChannel user_channels[3];
} SfdBufferWork;

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

typedef struct fn_12_2D288_SfdSeeSourcePrefix {
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_analyzed_byte_rate[4];
            int analyzed_byte_rate;
        } view_analyzed_byte_rate;
    } fields;
} fn_12_2D288_SfdSeeSourcePrefix;

typedef struct fn_12_2D288_SfdSeeTiming {
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
} fn_12_2D288_SfdSeeTiming;

typedef struct SfdSeeWork SfdSeeWork;

struct SfdSeeWork {
    union {
        unsigned char padding_extent[4872];
        struct {
            fn_12_2D288_SfdSeeSourcePrefix prefix;
        } view_prefix;
        struct {
            unsigned char padding_timing[3348];
            fn_12_2D288_SfdSeeTiming timing;
        } view_timing;
    } fields;
};

typedef struct SfdSeekRequest {
    union {
        unsigned char padding_extent[12];
        struct {
            unsigned char padding_position[4];
            int position;
        } view_position;
    } fields;
} SfdSeekRequest;

typedef struct fn_12_2D288_SfdSeekState {
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
} fn_12_2D288_SfdSeekState;

struct fn_12_2D288_SfdHandle {
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
            fn_12_2D288_SfdSeekState seek_state;
        } view_seek_state;
    } fields;
};

typedef struct MovieModuleState_u2 {
    u8 pad_0[0x78];
    s32 field_78;
    u8 pad_7c[0x8c];
    s32 field_108;
    u8 field_10c[1];
} MovieModuleState_u2;
SfdConditionValue fn_12_2D73C(fn_12_2D008_SfdHandle *handle, int condition);
int fn_12_2F1B4(fn_12_2D008_SfdHandle *handle, int transport_index);
extern unsigned int UTY_MulDiv(int multiplicand, int multiplier, int divisor);
extern int fn_12_23F34(fn_12_2D008_SfdHandle *handle);
extern u32 fn_12_23250(u32 arg0);
extern void fn_12_2D008(fn_12_2D008_SfdHandle *handle);
extern s32 fn_12_24990(u32 arg0);
extern s32 fn_12_24A88(s32 arg0, u32 arg1);

/* fzgx:begin fn_12_2D008 */
#undef v12

typedef struct fn_12_2D008_SfdSeeSourcePrefix {
    int analyzed;
    int analyzed_byte_rate;
    int field_08;
    int field_0C;
    int fields_10[2];
    int field_18;
    unsigned char unknown_001C[0x24];
    int field_40;
} fn_12_2D008_SfdSeeSourcePrefix;

typedef struct SfdSeeHeadSnapshot {
    int active;
    int byte_rate;
    int field_08;
} SfdSeeHeadSnapshot;

typedef struct fn_12_2D008_SfdSeeTiming {
    unsigned char unknown_0000[124];
    int byte_rate;
    int discovered_file_size;
    int discovered_total_time_value;
    int discovered_total_time_scale;
    int video_enabled;
    int audio_enabled;
    int field_98;
    int file_size;
    int total_time_value;
    int total_time_scale;
    int requested_byte_rate;
    int seek_position;
    int field_B0;
    int field_B4;
    int current_total_time_value;
    int current_total_time_scale;
} fn_12_2D008_SfdSeeTiming;

typedef struct SfdSeeSeekSource {
    fn_12_2D008_SfdSeeSourcePrefix prefix;
    unsigned char unknown_0044[0x85C];
    SfdSeeHeadSnapshot system;
    unsigned char unknown_08AC[536];
    SfdSeeHeadSnapshot video;
    unsigned char unknown_0ADC[556];
    SfdSeeHeadSnapshot audio;
    unsigned char unknown_0D18[0x10];
    fn_12_2D008_SfdSeeTiming timing;
    unsigned char unknown_0DE8[0x520];
} SfdSeeSeekSource;





static inline SfdSeeSeekSource *sfsee_GetSource(fn_12_2D008_SfdHandle *handle) {
    return (SfdSeeSeekSource *)handle->fields.view_seek_state.seek_state.source_handle;
}

static inline void sfsee_UpdateByteRate(fn_12_2D008_SfdHandle *handle) {
    SfdSeeSeekSource *source = sfsee_GetSource(handle);
    fn_12_2D008_SfdSeeTiming *timing = &source->timing;
    int file_size;
    int time_value;
    int time_scale;
    if (timing->requested_byte_rate > 0) {
        timing->byte_rate = timing->requested_byte_rate;
        return;
    }
    file_size = timing->file_size;
    time_value = timing->total_time_value;
    time_scale = timing->total_time_scale;
    if (file_size > 0 && time_value > 0) {
        timing->byte_rate = UTY_MulDiv(file_size, time_scale, time_value);
        return;
    }
    if (source->prefix.analyzed_byte_rate > 0) {
        timing->byte_rate = source->prefix.analyzed_byte_rate;
        return;
    }
    if (file_size <= 0) {
        file_size = timing->discovered_file_size;
    }
    if (time_value <= 0) {
        time_value = timing->discovered_total_time_value;
        time_scale = timing->discovered_total_time_scale;
    }
    if (file_size > 0 && time_value > 0) {
        timing->byte_rate = UTY_MulDiv(file_size, time_scale, time_value);
    } else {
        /* WARNING: compiler-diff device, not original code: volatile view of analyzed_byte_rate; plain read 39 diff lines */
        timing->byte_rate = *(volatile int *)&source->prefix.analyzed_byte_rate; /* source metadata can change during analysis */
    }
}

void fn_12_2D008(fn_12_2D008_SfdHandle *handle) {
    SfdSeeSeekSource *source = sfsee_GetSource(handle);
    fn_12_2D008_SfdSeeTiming *timing;
    int audio_ready;
    int video_ready;
    int system_ready;
    int analysis_pending;
    int byte_rate;
    int field_08;
    int duration;
    if (source->prefix.analyzed != 0) {
        return;
    }
    if (fn_12_2F1B4(handle, 3) != 0 && fn_12_2D73C(handle, 6) == 1) {
        audio_ready = 1;
        if (source->audio.active == 0) {
            analysis_pending = 1;
        } else {
            analysis_pending = 0;
        }
    } else {
        audio_ready = 0;
        analysis_pending = 0;
    }
    if (analysis_pending != 0) {
        return;
    }
    if (fn_12_2F1B4(handle, 2) != 0 && fn_12_2D73C(handle, 5) == 1) {
        video_ready = 1;
        if (source->video.active == 0) {
            analysis_pending = 1;
        } else {
            analysis_pending = 0;
        }
    } else {
        video_ready = 0;
        analysis_pending = 0;
    }
    if (analysis_pending != 0) {
        return;
    }
    system_ready = fn_12_2F1B4(handle, 1) != 0;
    if (system_ready != 0) {
        source->system.active = 1;
        /* WARNING: compiler-diff device, not original code: volatile view of field_18 forces the reload in the else branch (retail lwz 24(r31)); plain read reuses r0, 2 diff lines */
        if (source->prefix.field_0C != 0 && *(volatile int *)&source->prefix.field_18 > 0) { /* field metadata may be updated externally */
            timing = &source->timing;
            duration = source->prefix.field_40;
            if (timing->file_size > 0 && duration > 0) {
                byte_rate = UTY_MulDiv(timing->file_size, 1000, duration);
            } else {
                byte_rate = source->prefix.field_18;
            }
        } else if (source->prefix.field_0C != 0 && fn_12_23F34(handle) < 108) {
            byte_rate = (source->system.byte_rate * 2048) / 2018;
        } else {
            byte_rate = source->system.byte_rate;
        }
        field_08 = source->system.field_08;
    } else if (video_ready != 0) {
        byte_rate = source->video.byte_rate;
        field_08 = source->video.field_08;
    } else if (audio_ready != 0) {
        byte_rate = source->audio.byte_rate;
        field_08 = source->audio.field_08;
    } else {
        return;
    }
    source->prefix.analyzed_byte_rate = byte_rate;
    source->prefix.field_08 = field_08;
    source->prefix.analyzed = 1;
    sfsee_UpdateByteRate(handle);
}
/* fzgx:end fn_12_2D008 */

/* fzgx:begin fn_12_2D288 */
/* --- rel/movie_module/fn_12_2D288.c --- */


static inline SfdSeeWork *sfsee_GetSource(fn_12_2D288_SfdHandle *handle) {
    return handle->fields.view_seek_state.seek_state.fields.view_work.work;
}

static inline void sfsee_UpdateByteRate(fn_12_2D288_SfdHandle *handle) {
    SfdSeeWork *source = sfsee_GetSource(handle);
    fn_12_2D288_SfdSeeTiming *timing = &source->fields.view_timing.timing;
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


static inline int sfsee_GetInputEndPosition(fn_12_2D288_SfdHandle *handle) {
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

static inline void sfsee_ExecEstimate(fn_12_2D288_SfdHandle *handle, fn_12_2D288_SfdSeekState *seek) {
    int changed;
    int position;
    int transport_position;
    SfdSeeWork *source;
    SfdSeekRequest *request;
    SfdTimerStreamTimeUnit *timer;
    source = seek->fields.view_work.work;
    request = &seek->fields.view_request.request;
    if (((int)fn_12_23250( (u32)(fn_12_2D288_SfdHandle *)(handle))) != 0) {
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

void fn_12_2D288(fn_12_2D288_SfdHandle *handle) {
    fn_12_2D288_SfdSeekState *seek = &handle->fields.view_seek_state.seek_state;
    if (seek->fields.view_work.work == 0) {
        return;
    }
    fn_12_2D008( (fn_12_2D008_SfdHandle *)(fn_12_2D288_SfdHandle *)(handle));
    sfsee_ExecEstimate(handle, seek);
}
/* fzgx:end fn_12_2D288 */

/* fzgx:begin fn_12_2D420 */
/* --- rel/movie_module/fn_12_2D420.c --- */
/* --- rel/movie_module/fn_12_2D420.c --- */
typedef struct MovieModuleSubState {
    u8 pad_0[0xda4];
    s32 field_da4;
    s32 field_da8;
} MovieModuleSubState;

typedef struct MovieModuleState {
    u8 pad_0[0x2908];
    MovieModuleSubState *field_2908;
} MovieModuleState;

void fn_12_2D420(MovieModuleState *arg0, u32 arg1, u32 arg2) {
    MovieModuleSubState *state;

    state = arg0->field_2908;
    if (state == 0) {
        return;
    }
    if (state->field_da4 < 0) {
        state->field_da4 = arg1;
    }
    if (state->field_da8 >= 0) {
        return;
    }
    state->field_da8 = arg2;
}
/* fzgx:end fn_12_2D420 */

/* fzgx:begin fn_12_2D450 */
/* --- rel/movie_module/fn_12_2D450.c --- */
typedef struct MovieModuleState_u1 {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_c;
} MovieModuleState_u1;

void fn_12_2D450(MovieModuleState_u1 *state) {
    state->field_0 = 0;
    state->field_4 = 0;
    state->field_8 = -3;
    state->field_c = 1;
}
/* fzgx:end fn_12_2D450 */

/* fzgx:begin fn_12_2D470 */
/* --- rel/movie_module/fn_12_2D470.c --- */


s32 fn_12_2D470(MovieModuleState_u2 *state, void **out0, u32 *out1) {
    if (fn_12_24990( (u32)(MovieModuleState_u2 *)(state))) {
        return fn_12_24A88(0, 0xff00011c);
    }
    if (state->field_78) {
        *out0 = &state->field_10c[0];
        *out1 = state->field_108;
    } else {
        *out0 = 0;
        *out1 = 0;
    }
    return 0;
}
/* fzgx:end fn_12_2D470 */
