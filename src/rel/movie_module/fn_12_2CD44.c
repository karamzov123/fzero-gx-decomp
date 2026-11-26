#include "types.h"


/* --- rel/movie_module/fn_12_2CD44.c --- */
/* --- rel/movie_module/fn_12_2CD44.c --- */
typedef struct MovieModuleState {
    u8 _pad_0[0x44];
    u32 field_44;
    u32 field_48;
} MovieModuleState;

u32 fn_12_2CD44(MovieModuleState *state) {
    if (state->field_48 - 1 > 3) {
        return 1;
    }
    return state->field_44 == 0;
}

/* --- rel/movie_module/fn_12_2CD6C.c --- */
extern void fn_12_2EBAC(void);

void fn_12_2CD6C(void) {
    fn_12_2EBAC();
}

/* --- rel/movie_module/fn_12_2CD8C.c --- */
extern const u32 lbl_12_rodata_C78[102];
extern s32 fn_12_24A88(void *, s32);

void fn_12_2CD8C(void) {
    if (lbl_12_rodata_C78[73] != 0x5A5A5A5A) {
        fn_12_24A88(0, 0xFF000201);
    }
}

/* --- rel/movie_module/fn_12_2CDD0.c --- */
struct fn_12_2CDD0_Arg3 { u32 unk_0; };
struct fn_12_2CDD0_Copy12 { u32 a[3]; };

static inline s32 find_entry(u32 v1, u32 v2, u32 v3, u32 arg2, s32 v8, s32 v9, s32 v7, u32 v5) {
    struct { s32 value; } result;
#define v12 result.value
    struct { u32 value; } entry;
    s32 v11 = v8;
    u32 v4, v14;
    s32 v15;
    for (v12 = 0; v12 < v7; v12++) {
        entry.value = v1 + v11 * 12;
        v4 = *(u32 *)((u8 *)entry.value + 4);
        v14 = v4 + *(u32 *)((u8 *)entry.value + 8);
        if (v14 <= v5) {
            if (v4 <= arg2 && arg2 < v14) return v12;
        } else {
            if ((v4 <= arg2 && arg2 < v5) ||
                (v2 <= arg2 && arg2 < v14 - v3)) return v12;
        }
        v15 = v11 + 1;
        v11 = v15 - v9;
        if (v15 < v9) v11 = v15;
    }
    return -1;
}
#undef v12

s32 fn_12_2CDD0(void *arg0, s32 arg1, u32 arg2, struct fn_12_2CDD0_Arg3 *arg3) {
    u32 v4;
    s32 v11;
    struct { u32 value; } base;
#define v0 base.value
    s32 v12;
    u32 v13;
    u32 v5;
    u32 v1;
    s32 v8;
    s32 v9;
    u32 v2;
    u32 v3;
    s32 v7;
    u32 v14;
    s32 v15;
    s32 v16;
    s32 v17;
    u32 v18;
    arg3->unk_0 = -1;
    v0 = (u32)((u8 *)arg0 + arg1 * 116);
    v1 = *(u32 *)((u8 *)v0 + 4472);
    v2 = *(u32 *)((u8 *)v0 + 4440);
    v3 = *(u32 *)((u8 *)v0 + 4444);
    if (v1 == 0) return 0;
    v5 = v2 + v3;
    if (arg2 >= v5) arg2 -= v3;
    v7 = *(s32 *)((u8 *)v0 + 4480);
    if (v7 != 0) {
        v8 = *(s32 *)((u8 *)v0 + 4488);
        v9 = *(s32 *)((u8 *)v0 + 4476);
        v12 = find_entry(v1, v2, v3, arg2, v8, v9, v7, v5);
        if (v12 != -1) {
            v16 = v8 + v12;
            v17 = v16 - v9;
            if (v16 < v9) v17 = v16;
            *(s32 *)((u8 *)v0 + 4480) -= v12;
            *(s32 *)((u8 *)v0 + 4488) = v17;
            v18 = *(u32 *)((u8 *)v0 + 4472) + v17 * 12;
            *(struct fn_12_2CDD0_Copy12 *)arg3 = *(struct fn_12_2CDD0_Copy12 *)v18;
        }
    }
    return 0;
}

/* --- rel/movie_module/fn_12_2CF20.c --- */
typedef struct MovieCmd {
    s32 f_0;
    s32 f_4;
    s32 f_8;
} MovieCmd;

typedef struct MovieEntry {
    u8 pad_00[0x1178];
    u8 *buffer;
    s32 capacity;
    s32 used;
    s32 tail;
} MovieEntry;


s32 fn_12_2CF20(void *movie, s32 index, MovieCmd *cmd) {
    s32 result;
    MovieEntry *entry;
    s32 value;
    s32 v4;
    s32 tail;
    u8 *buffer;
    s32 next;
    s32 cap;
    struct { s32 value; } newtail;

    value = cmd->f_0;
    if (value < 0) {
        return 0;
    }
    entry = (MovieEntry *)((u8 *)movie + index * 0x74);
    buffer = entry->buffer;
    if (buffer == 0) {
        return 0;
    }
    if (entry->used == entry->capacity) {
        result = -1;
    } else {
        tail = entry->tail;
        v4 = cmd->f_4;
        {
            MovieCmd *slot;
            slot = (MovieCmd *)((u8 *)buffer + tail * 0xc);
            *slot = *cmd;
        }
        next = tail;
        next = next + 1;
        cap = entry->capacity;
        newtail.value = next - cap;
        if (next < cap) {
            newtail.value = next;
        }
        entry->used = entry->used + 1;
        entry->tail = newtail.value;
        result = 0;
    }
    if (result == -1) {
        return fn_12_24A88(movie, 0xFF000421);
    }
    return 0;
}

/* --- rel/movie_module/fn_12_2CFEC.c --- */
/* --- rel/movie_module/fn_12_2CFEC.c --- */
typedef struct MovieModuleState_u1 {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
} MovieModuleState_u1;

void fn_12_2CFEC(MovieModuleState_u1 *state) {
    state->field_0 = 0;
    state->field_4 = 0;
    state->field_8 = 0;
    state->field_c = 0;
    state->field_10 = 0;
}

/* --- rel/movie_module/fn_12_2D008.c --- */
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
    union {
        unsigned char padding_extent[13720];
        struct {
            unsigned char padding_seek_state[10504];
            SfdSeekState seek_state;
        } view_seek_state;
    } fields;
};

typedef struct SfdSeeSourcePrefix {
    int analyzed;
    int analyzed_byte_rate;
    int field_08;
    int field_0C;
    int fields_10[2];
    int field_18;
    unsigned char unknown_001C[0x24];
    int field_40;
} SfdSeeSourcePrefix;

typedef struct SfdSeeHeadSnapshot {
    int active;
    int byte_rate;
    int field_08;
} SfdSeeHeadSnapshot;

typedef struct SfdSeeTiming {
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
} SfdSeeTiming;

typedef struct SfdSeeSeekSource {
    SfdSeeSourcePrefix prefix;
    unsigned char unknown_0044[0x85C];
    SfdSeeHeadSnapshot system;
    unsigned char unknown_08AC[536];
    SfdSeeHeadSnapshot video;
    unsigned char unknown_0ADC[556];
    SfdSeeHeadSnapshot audio;
    unsigned char unknown_0D18[0x10];
    SfdSeeTiming timing;
    unsigned char unknown_0DE8[0x520];
} SfdSeeSeekSource;

void fn_12_2D008(SfdHandle *handle);

SfdConditionValue fn_12_2D73C(SfdHandle *handle, int condition);

int fn_12_2F1B4(SfdHandle *handle, int transport_index);

unsigned int UTY_MulDiv(int multiplicand, int multiplier, int divisor);

extern int fn_12_23F34(SfdHandle *handle);

static inline SfdSeeSeekSource *sfsee_GetSource(SfdHandle *handle) {
    return (SfdSeeSeekSource *)handle->fields.view_seek_state.seek_state.source_handle;
}

static inline void sfsee_UpdateByteRate(SfdHandle *handle) {
    SfdSeeSeekSource *source = sfsee_GetSource(handle);
    SfdSeeTiming *timing = &source->timing;
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
        timing->byte_rate = *(volatile int *)&source->prefix.analyzed_byte_rate; /* source metadata can change during analysis */
    }
}

void fn_12_2D008(SfdHandle *handle) {
    SfdSeeSeekSource *source = sfsee_GetSource(handle);
    SfdSeeTiming *timing;
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
