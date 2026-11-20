#include "types.h"
#pragma inline_max_size(10000)
#pragma inline_max_total_size(10000)

/* --- rel/movie_module/fn_12_250F0.c --- */
typedef struct MpsHandle MpsHandle;

typedef struct SfmpsWork {
    MpsHandle *decoder;
    s32 max_video_bound;
    s32 max_audio_bound;
    s32 video_pts_baseline;
    s32 audio_pts_baseline;
    s32 concat_count;
    s32 previous_video_stream;
    s32 previous_audio_stream;
    s32 first_video_stream;
    s32 first_audio_stream;
    s32 selected_video_id;
    s32 selected_audio_id;
    s32 delimiter_state;
    void *element_outputs[0x44];
    void *element_callback;
    void *element_callback_argument;
} SfmpsWork;

typedef struct SfdHandle {
    u8 pad_0000[0x1AEC];
    SfmpsWork *work;
    u8 pad_1AF0[0x214];
    SfmpsWork mps_work_storage;
} SfdHandle;

typedef void (*MpsErrorCallback)(void *object, s32 error);

extern MpsHandle *fn_12_6B28(void);
extern int fn_12_6A90(MpsHandle *handle);
extern int fn_12_6CA8(MpsHandle *handle, MpsErrorCallback callback, void *object);
extern int fn_12_24A88(SfdHandle *handle, s32 error);
extern void fn_12_250D0(void *object, s32 error);

s32 fn_12_250F0(SfdHandle *handle) {
    SfmpsWork *work;
    MpsHandle *decoder;
    struct { int value; } i;

    work = &handle->mps_work_storage;
    handle->work = work;
    work->decoder = 0;
    work->max_video_bound = 0;
    work->max_audio_bound = 0;
    work->video_pts_baseline = 0x7FFFFFFF;
    work->audio_pts_baseline = 0x7FFFFFFF;
    work->concat_count = 0;
    work->previous_video_stream = 0x7FFFFFFF;
    work->previous_audio_stream = 0x7FFFFFFF;
    work->first_video_stream = -1;
    work->first_audio_stream = -1;
    work->selected_video_id = -1;
    work->selected_audio_id = -1;
    work->delimiter_state = 0;
    for (i.value = 0; i.value < 0x44; i.value++) {
        work->element_outputs[i.value] = 0;
    }
    work->element_callback = 0;
    work->element_callback_argument = 0;
    decoder = fn_12_6B28();
    if (decoder == 0) {
        return fn_12_24A88(handle, 0xFF000D08);
    }
    if (fn_12_6CA8(decoder, fn_12_250D0, handle) != 0) {
        fn_12_6A90(decoder);
        return fn_12_24A88(handle, 0xFF000D09);
    }
    work->decoder = decoder;
    return 0;
}

/* --- rel/movie_module/fn_12_252A0.c --- */
/* --- rel/movie_module/fn_12_252A0.c --- */
struct Sig_fn_12_252A0_Movie {
    u8 pad0[0x48];
    int state;
    u8 pad4C[0x1AF4-0x4C];
    int stream;
    int field1AF8;
    int field1AFC;
    int field1B00;
};
typedef struct Sig_fn_12_696C_MovieValues {
    u32 value_00, value_04, value_08, value_0c;
    u32 value_10, value_14, value_18, value_1c;
} Sig_fn_12_696C_MovieValues;
typedef struct Sig_fn_12_696C_MovieModule {
    u8 _pad00[0x40];
    Sig_fn_12_696C_MovieValues values[1];
} Sig_fn_12_696C_MovieModule;
typedef struct Sig_fn_12_6A18_MovieValues {
    u32 value_14, value_18, value_1c;
} Sig_fn_12_6A18_MovieValues;
struct fn_12_252A0_arg0_1138_E116 {
    u8 pad_0[0x24];
    u32 unk_24;
    u8 pad_28[0x4C];
};
struct fn_12_252A0_Arg0 {
    u8 pad_0[0x1138];
    struct fn_12_252A0_arg0_1138_E116 unk_1138[1];
};
extern int fn_12_21D50(void *, int);
extern int fn_12_21E94(void *, int);
extern int fn_12_696C(Sig_fn_12_696C_MovieModule *, Sig_fn_12_696C_MovieValues *, int);
extern int fn_12_6A18(void *, Sig_fn_12_6A18_MovieValues *);
extern s32 fn_12_2D73C(void *, int);
extern s32 fn_12_2F1F0(void *, u32);
extern void fn_12_21D60(void *, int, int);
extern void fn_12_2D7DC(void *, int, int);
#define FIELD(p,n) (*(s32 *)((u8 *)(p)+(n)))
#define WORK(p) (*(s32 **)((u8 *)(p)+0x1aec))
static inline void update(struct fn_12_252A0_Arg0 *arg0, s32 zero) {
    s32 v5;
    s32 *v9;
    void *v10;
    s32 *v11;
    s32 *v0;
    void *decoder;
    u32 v1;
    s32 v3;
    s32 v2;
    s32 v4;
    s32 v6;
    s32 *v13;
    s32 *v14;
    s32 *v17;
    int a,b,c;
    Sig_fn_12_696C_MovieValues loc_14;
    Sig_fn_12_696C_MovieValues loc_34;
    Sig_fn_12_6A18_MovieValues loc_8;
    v0 = WORK(arg0);
    v1 = zero;
    v3 = zero;
    v2 = zero;
    decoder = (void *)v0[0];
    do {
        fn_12_696C(decoder, &loc_34, v2);
        { s32 t = loc_34.value_08;
          if ((s32)v1 > t) t = v1;
          v1 = t;
        }
        v4 = loc_34.value_0c;
        if (v3 > v4) v4 = v3;
        v2++;
        v3 = v4;
    } while (v2 < 3);
    v0[2] = v1;
    v0[1] = v4;
    a = fn_12_21D50(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1AFC);
    b = fn_12_21D50(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1AF8);
    c = fn_12_21D50(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1B00);
    if ((c | (a | b)) != 1 && fn_12_21D50(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->stream) == 1) {
        struct fn_12_252A0_Arg0 *entry = (struct fn_12_252A0_Arg0 *)((u8 *)arg0 + ((struct Sig_fn_12_252A0_Movie *)arg0)->stream * 0x74);
        v5 = FIELD(arg0,0x9f8);
        v6 = FIELD(arg0,8);
        if (v6 <= 0) v6 = entry->unk_1138[0].unk_24;
        if (v6 <= 0) v6 = v5;
        if (v6 < v5) v5 = v6;
        if (fn_12_21E94(arg0,0) >= v5) {
            fn_12_21D60(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1AFC,1);
            fn_12_21D60(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1AF8,1);
            fn_12_21D60(arg0, ((struct Sig_fn_12_252A0_Movie *)arg0)->field1B00,1);
        }
    }
    v9 = WORK(arg0);
    v10 = (void *)v9[0];
    fn_12_6A18(v10,&loc_8);
    if ((s32)loc_8.value_1c != -1 && (s32)loc_8.value_1c > 0) FIELD(arg0,0x924) = loc_8.value_1c;
    fn_12_696C(v10,&loc_14,1);
    if ((s32)loc_14.value_10 != -1) FIELD(arg0,0x928) = loc_14.value_10;
    if (FIELD(arg0,0x930) == -1) FIELD(arg0,0x930) = v9[2];
    if (FIELD(arg0,0x934) == -1) FIELD(arg0,0x934) = v9[1];
    v11 = WORK(arg0);
    if (fn_12_2D73C(arg0,6) == 1 && v11[2] == 0 && fn_12_2F1F0(arg0,6) != 0) fn_12_2D7DC(arg0,6,0);
    if (fn_12_2D73C(arg0,5) == 1 && v11[1] == 0 && fn_12_2F1F0(arg0,7) != 0) fn_12_2D7DC(arg0,5,0);
    v13 = *(s32 **)((u8 *)arg0+0x2908);
    if (v13 == 0) v14 = 0;
    else {
        if ((s32)WORK(arg0)[5] > 0) v14 = 0;
        else v14 = (s32 *)((u8 *)v13+0x8a0);
    }
    if (v14 != 0) {
        v17 = WORK(arg0);
        if (v17[4] != 0x7fffffff) {
            FIELD(arg0,0xdd8) = v17[4] - v14[6];
            if (v14[0] == 0) {
                v14[1] = FIELD(arg0,0x924)*50;
                v14[2] = FIELD(arg0,0x928);
                v14[3] = v17[1];
                v14[4] = v17[2];
                v14[5] = FIELD(arg0,0xdd4);
                v14[6] = v17[3];
                v14[7] = v17[8];
                v14[8] = v17[9];
            }
        }
    }
}
void fn_12_252A0(struct fn_12_252A0_Arg0 *arg0) {
    update(arg0, 0);
}

/* --- rel/movie_module/fn_12_2559C.c --- */
struct Sig_fn_12_21F28_MovieEntry {
    int value;
    char padding[0x70];
};
struct Sig_fn_12_21F28_MovieModule {
    char padding[0x1174];
    struct Sig_fn_12_21F28_MovieEntry entries[1];
};
struct Sig_fn_12_21D30_fn_12_21D30_E116_u32 { u32 unk_0; u8 pad_4[0x70]; };
struct Sig_fn_12_21D30_fn_12_21D30_Arg0 {
    u8 pad_0[0x114C];
    struct Sig_fn_12_21D30_fn_12_21D30_E116_u32 unk_114C[1];
};
struct fn_12_2559C_Arg0 {
    u8 pad_0[0x28];
    u32 unk_28;
    u8 pad_2C[0x1AC0];
    u32 unk_1AEC;
    u8 pad_1AF0[0x4];
    u32 unk_1AF4;
};
extern int fn_12_21F28(struct Sig_fn_12_21F28_MovieModule *, int);
extern s32 fn_12_231F8(u32);
extern u32 fn_12_21D30(struct Sig_fn_12_21D30_fn_12_21D30_Arg0 *, u32);
extern u32 fn_12_23250(u32);
extern u32 fn_12_67A4(const u8 *);
extern void fn_12_21D40(void *, int, int);
s32 fn_12_2559C(struct fn_12_2559C_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v2;
    u32 v0;
    u32 v1;
    s32 v4;
    u32 v3;
    u32 t0;
    int t1;
    u32 t7;
    v0 = arg0->unk_1AEC;
    v1 = arg0->unk_1AF4;
    v2 = arg0->unk_28;
    if ((s32)arg2 >= 4) {
        v3 = fn_12_67A4((const u8 *)arg1);
        if (v3 == 0x80000) {
            if ((s32)*(u32 *)((u8 *)arg0 + 6916) < 0) {
                t1 = fn_12_21F28((struct Sig_fn_12_21F28_MovieModule *)arg0, v1);
                *(u32 *)((u8 *)arg0 + 6916) = t1 + 4;
            }
            *(u32 *)((u8 *)v0 + 48) = 1;
        } else if ((s32)v3 != 0) {
            *(u32 *)((u8 *)v0 + 48) = 0;
        }
    } else {
        v3 = 0;
    }
    if (v3 != 0x80000) {
        v4 = 0;
    } else if ((s32)fn_12_23250((u32)arg0) != 0 || fn_12_231F8((u32)arg0) != 0) {
        v4 = 0;
    } else {
        v4 = 1;
    }
    if (v4 != 0) {
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6908), 1);
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6904), 1);
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6912), 1);
        return 0;
    }
    if ((s32)arg3 < 4 && (s32)fn_12_21D30((struct Sig_fn_12_21D30_fn_12_21D30_Arg0 *)arg0, v1) == 1) {
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6908), 1);
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6904), 1);
        fn_12_21D40(arg0, *(u32 *)((u8 *)arg0 + 6912), 1);
        return 0;
    }
    if ((s32)arg2 < (s32)v2) {
        if ((v3 - 0x10000) == 0) {
            v4 = 0;
        } else {
            v4 = 1;
            if ((v3 - 0x40000) == 0) {
                v4 = 1;
            }
            return v4;
        }
    } else {
        v4 = 1;
    }
done:
    return v4;
}

/* --- rel/movie_module/fn_12_25740.c --- */
// fn_12_25740: returns a constant.
int fn_12_25740(void) {
    return 1;
}

/* --- rel/movie_module/fn_12_25748.c --- */
typedef void *SfdCallbackObject;

typedef int SfdConditionValue;

typedef int SfdTransportValue;

typedef struct SfdHandle_u3 SfdHandle_u3;

typedef int (*SfdUserIsSkipFn)(SfdHandle_u3 *handle, int picture_type, int value, int scale);

typedef int (*SfdTimeSourceFn)(SfdHandle_u3 *handle, int *value, int *scale);

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

typedef void (*SfdBufferHandleCallback)(SfdHandle_u3 *handle, int stream_index);

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

typedef int (*SfdTransportLifecycleFn)(SfdHandle_u3 *handle);

typedef int (*SfdTransportPauseFn)(SfdHandle_u3 *handle, int state);

typedef int (*SfdTransportTransferFn)(SfdHandle_u3 *handle, SfdTransportValue parameter, int value);

typedef int (*SfdTransportBufferFn)(SfdHandle_u3 *handle, void *buffer);

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

typedef int (*SfdAudioSetPanFn)(SfdHandle_u3 *, int, int, SfdAudioOutputCallbacks *);

typedef int (*SfdAudioGetPanFn)(SfdHandle_u3 *, int, SfdAudioOutputCallbacks *);

typedef int (*SfdAudioSetVolumeFn)(SfdHandle_u3 *, int, SfdAudioOutputCallbacks *);

typedef int (*SfdAudioGetVolumeFn)(SfdHandle_u3 *, SfdAudioOutputCallbacks *);

typedef void (*SfdAudioSetSpeedFn)(SfdHandle_u3 *, int);

struct SfdAudioOutputCallbacks {
    void *output_context;
    SfdAudioSetPanFn set_pan;
    SfdAudioGetPanFn get_pan;
    SfdAudioSetVolumeFn set_volume;
    SfdAudioGetVolumeFn get_volume;
    SfdAudioSetSpeedFn set_speed;
    int reserved_18;
};

struct SfdHandle_u3 {
    union {
        unsigned char padding_extent[13720];
        struct {
            unsigned char padding_transports[6816];
            SfdTransportState transports[9];
        } view_transports;
    } fields;
};

int fn_12_25748(SfdHandle_u3 *handle, int stream_index, const unsigned char *data, int size,
                long long pts);

int fn_12_247BC(SfdHandle_u3 *handle, int stream_index, const unsigned char *data, int size,
                int *header_flag);

void fn_12_22668(SfdHandle_u3 *handle, int buffer_index, int channel, SfdBufferChannel *output);

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

static inline int sfmps_CopyUoch(SfdHandle_u3 *handle, int stream_index, const unsigned char *data,
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

static inline int sfmps_CopyUo(SfdHandle_u3 *handle, int stream_index, const unsigned char *data,
                               int size) {
    if (handle->fields.view_transports.transports[1].fields.view_buffer_output3.buffer_output3 ==
        8) {
        return 1;
    }
    return sfmps_CopyUoch(handle, stream_index, data, size);
}

int fn_12_25748(SfdHandle_u3 *handle, int stream_index, const unsigned char *data, int size,
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
