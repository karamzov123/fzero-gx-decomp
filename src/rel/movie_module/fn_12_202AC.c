#include "types.h"


/* --- rel/movie_module/fn_12_202AC.c --- */
/* --- rel/movie_module/fn_12_202AC.c --- */
extern void fn_12_24A88(void *arg0, s32 arg1);

void fn_12_202AC(void *arg0) {
    fn_12_24A88(arg0, 0xff000c03);
}

/* --- rel/movie_module/fn_12_202D4.c --- */
void fn_12_202D4(void *arg) {
    fn_12_24A88(arg, 0xFF000C03);
}

/* --- rel/movie_module/fn_12_202FC.c --- */
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
} SfdTimerSkipState;

typedef struct SfdTimerCompactTimeUnit {
    union {
        unsigned char padding_extent[36];
        struct {
            unsigned char padding_value[28];
            int value;
        } view_value;
        struct {
            unsigned char padding_scale[32];
            int scale;
        } view_scale;
    } fields;
} SfdTimerCompactTimeUnit;

typedef struct SfdTimerStreamTimeUnit {
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
    union {
        unsigned char padding_extent[1504];
        struct {
            unsigned char padding_unknown_02EC[748];
            unsigned char unknown_02EC[0x2C4];
        } view_unknown_02EC;
    } fields;
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
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_context[8];
            void *context;
        } view_context;
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
            unsigned char padding_timer_state[3184];
            SfdTimerState timer_state;
        } view_timer_state;
        struct {
            unsigned char padding_transports[6816];
            SfdTransportState transports[9];
        } view_transports;
    } fields;
};

typedef struct AdxtHandle AdxtHandle;

typedef struct SfdTestWork SfdTestWork;

typedef struct SfdTestTime {
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
} SfdTestTime;

typedef void (*SfdAdxtCopyFn)(SfdHandle *handle, const unsigned char *data, int size,
                              int *consumed);

typedef struct SfdAdxtWork {
    union {
        unsigned char padding_extent[80];
        struct {
            AdxtHandle *decoder;
        } view_decoder;
        struct {
            unsigned char padding_paused[44];
            int paused;
        } view_paused;
        struct {
            unsigned char padding_discarded_samples[48];
            int discarded_samples;
        } view_discarded_samples;
    } fields;
} SfdAdxtWork;

struct AdxtHandle {
    unsigned char unknown_00[0x0C];
    int field_0C;
};

int fn_12_202FC(SfdHandle *handle, int state);

void SFTIM_GetTimeOneFrmVideo(SfdHandle *handle, int *value, int *scale);

unsigned int UTY_MulDiv(int multiplicand, int multiplier, int divisor);

extern void ADXT_Pause(AdxtHandle *decoder, int paused);

extern int fn_8004C658(AdxtHandle *decoder);

extern int fn_8004C0B4(AdxtHandle *decoder);

extern int fn_8004BA40(AdxtHandle *decoder, int samples);

extern void fn_12_30930(SfdTestWork *work, const SfdTestTime *elapsed);

extern void fn_12_309B8(SfdTestWork *work, int value);

static inline SfdAdxtWork *sfadxt_GetWork(SfdHandle *handle) {
    return handle->fields.view_transports.transports[3].fields.view_context.context;
}

static inline SfdTestWork *sfadxt_GetTestWork(SfdHandle *handle) {
    return (SfdTestWork *)(handle->fields.view_timer_state.timer_state.fields.view_unknown_02EC
                               .unknown_02EC +
                           4);
}

int fn_12_202FC(SfdHandle *handle, int state) {
    SfdAdxtWork *work = sfadxt_GetWork(handle);
    AdxtHandle *decoder = work->fields.view_decoder.decoder;
    switch (state) {
    case 0: {
        SfdTestWork *test_work = sfadxt_GetTestWork(handle);
        AdxtHandle *decoder0;
        sfadxt_GetWork(handle)->fields.view_discarded_samples.discarded_samples = 0;
        decoder0 = sfadxt_GetWork(handle)->fields.view_decoder.decoder;
        if (sfadxt_GetWork(handle)->fields.view_paused.paused != 1) {
            ADXT_Pause(decoder0, 0);
            fn_12_309B8(test_work, 0);
        }
        break;
    }
    case 1:
        ADXT_Pause(decoder, 1);
        fn_12_309B8(sfadxt_GetTestWork(handle), 1);
        break;
    case 2: {
        int status = fn_8004C658(decoder);
        int is_active;
        if (status == 0 || status == 1) {
            is_active = 0;
        } else {
            is_active = 1;
        }
        if (is_active) {
            int sample_rate = fn_8004C0B4(decoder);
            int scale;
            int value;
            int samples;
            int requested;
            SfdTestTime elapsed;
            SFTIM_GetTimeOneFrmVideo(handle, &value, &scale);
            samples = UTY_MulDiv(sample_rate, value, scale);
            requested = samples + work->fields.view_discarded_samples.discarded_samples;
            work->fields.view_discarded_samples.discarded_samples =
                requested - fn_8004BA40(decoder, requested);
            elapsed.fields.view_value.value = samples;
            elapsed.fields.view_scale.scale = sample_rate;
            fn_12_30930(sfadxt_GetTestWork(handle), &elapsed);
        }
        break;
    }
    }
    return 0;
}

/* --- rel/movie_module/fn_12_20448.c --- */
/* --- rel/movie_module/fn_12_20448.c --- */
extern void ADXT_Stop(void *arg0);

typedef struct MovieModule {
    u8 pad_0000[0x1b74];
    void *field_1b74;
} MovieModule;

int fn_12_20448(MovieModule *arg0) {
    ADXT_Stop(*(void **)arg0->field_1b74);
    return 0;
}

/* --- rel/movie_module/fn_12_20474.c --- */
/* --- rel/movie_module/fn_12_20474.c --- */

typedef struct MovieModule_u1 {
    u8 pad_0000[0x50];
    int field_0050;
    u8 pad_0054[0xf0c];
    u8 field_0f60[1];
    u8 pad_0f61[0xc13];
    void *field_1b74;
} MovieModule_u1;

int fn_12_20474(MovieModule_u1 *arg0) {
    void *movie_module = (u8 *)arg0 + 0xf60;
    void *movie;
    void *movie_data;

    movie_data = arg0->field_1b74;
    movie = *(void **)movie_data;
    *(int *)((u8 *)movie_data + 0x2c) = 0;
    if (arg0->field_0050 != 1) {
        ADXT_Pause(movie, 0);
        fn_12_309B8(movie_module, 0);
    }
    return 0;
}

/* --- rel/movie_module/fn_12_204D4.c --- */
// fn_12_204D4: returns a constant.
int fn_12_204D4(void) {
    return 0;
}

/* --- rel/movie_module/fn_12_204DC.c --- */
extern u32 lbl_12_bss_6990[8];
extern u32 fn_12_2B348(void);
extern u32 lbl_12_bss_7C64[137];
extern void fn_8004CAC8(void *arg0);

typedef struct MovieModule_u2 {
    u8 pad_0000[0x1b74];
    void *movie_data;
} MovieModule_u2;

typedef struct MovieData {
    void *movie;
    void *movie_controller;
    u32 field_0008;
    u32 field_000c;
    u32 field_0010;
    u32 field_0014;
    u32 field_0018;
    u32 field_001c;
    u32 field_0020;
} MovieData;

typedef struct MovieHeader {
    u32 field_0008;
    u32 field_000c;
    u32 field_0010;
    u32 field_0014;
    u32 field_0018;
    u32 field_001c;
    u32 field_0020;
} MovieHeader;

typedef struct MovieControllerVtable {
    u8 pad_0000[0xc];
    void (*field_000c)(void *self);
} MovieControllerVtable;

typedef struct MovieController {
    MovieControllerVtable *vtable;
} MovieController;

int fn_12_204DC(MovieModule_u2 *arg0) {
    MovieData *movie_data;
    void *movie;
    MovieController *movie_controller;
    int result;

    movie_data = (MovieData *)arg0->movie_data;
    movie = movie_data->movie;
    movie_controller = (MovieController *)movie_data->movie_controller;
    if (movie == 0) {
        return 0;
    }

    *(MovieHeader *)lbl_12_bss_6990 = *(MovieHeader *)((u8 *)movie_data + 8);

    result = fn_12_2B348();
    if (result != 1) {
        fn_8004CAC8(movie);
        result = 0;
    } else {
        ADXT_Stop(*(void **)arg0->movie_data);
        lbl_12_bss_7C64[128] = (u32)movie;
        result = 0;
    }

    movie_controller->vtable->field_000c(movie_controller);
    return result;
}

/* --- rel/movie_module/fn_12_205BC.c --- */
typedef struct MovieData_u3 {
    void *movie;
    u8 pad_4[0x20];
    s32 unk_24;
    s32 unk_28;
} MovieData_u3;

typedef struct MovieModule_u3 {
    u8 pad_0[0x48];
    s32 unk_48;
    u8 pad_4C[0xF60 - 0x4C];
    u8 unk_F60[0x1B74 - 0xF60];
    MovieData_u3 *movie_data;
} MovieModule_u3;

typedef struct Pair64 {
    s64 a;
    s64 b;
} Pair64;

extern s32 fn_12_2E44C(MovieModule_u3 *, s32 *, s32 *);
extern u32 lbl_12_bss_6988;
extern s64 fn_12_335B8(void);
extern s64 fn_12_335A4(void);
extern void fn_12_2FE60(void *, Pair64 *, Pair64 *, Pair64 *);
extern void fn_8004C164(void *, s32 *, s32 *);

s32 fn_12_205BC(MovieModule_u3 *arg0, s32 *arg1, s32 *arg2) {
    Pair64 out;
    Pair64 scale;
    Pair64 in;
    s32 y;
    s32 x;
    s32 ra;
    s32 rb;
    MovieData_u3 *md;
    void *movie;
    void *obj;

    obj = arg0->unk_F60;
    md = arg0->movie_data;
    movie = md->movie;

    if (fn_12_2E44C(arg0, arg1, arg2) == 0) {
        return 0;
    }
    if (arg0->unk_48 == 4) {
        lbl_12_bss_6988 = fn_8004C658(movie);
        fn_8004C164(movie, &x, &y);
        in.a = x;
        in.b = y;
        scale.a = fn_12_335B8();
        scale.b = fn_12_335A4();
        fn_12_2FE60(obj, &in, &scale, &out);
        ra = (s32)out.a;
        rb = (s32)out.b;
        if (md->unk_24 < ra) {
            md->unk_24 = ra;
            md->unk_28 = rb;
        }
    }
    *arg1 = md->unk_24;
    *arg2 = md->unk_28;
    return 0;
}
