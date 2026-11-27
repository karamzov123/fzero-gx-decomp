#include "types.h"

typedef struct MovieModule_u2 {
    u8 pad[0xa8];
    void *movie;
} MovieModule_u2;

typedef struct SJCK {
    unsigned char *data;
    int len;
} SJCK;

typedef struct MovieModule_u1 {
    u8 pad[0xa8];
    void *field_a8;
} MovieModule_u1;

typedef struct SfdHandle SfdHandle;

typedef int (*SfdTransportLifecycleFn)(SfdHandle *handle);

typedef int (*SfdTransportPauseFn)(SfdHandle *handle, int state);

typedef int (*SfdTransportBufferFn)(SfdHandle *handle, void *buffer);

typedef int SfdTransportValue;

typedef int (*SfdTransportTransferFn)(SfdHandle *handle, SfdTransportValue parameter, int value);

typedef struct SfdTransportInterface SfdTransportInterface;

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

typedef struct SfdTransportSetup SfdTransportSetup;

struct SfdTransportSetup {
    const SfdTransportInterface *entries[9];
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

typedef int SfdCallbackObject;

typedef void (*SfdErrorCallback)(SfdCallbackObject object, int error);

typedef struct SfdErrorInfo {
    SfdErrorCallback callback;
    SfdCallbackObject callback_object;
    int first_error;
    int field_0C;
    int field_10;
} SfdErrorInfo;

typedef int SfdConditionValue;

typedef int (*SfdTimeSourceFn)(SfdHandle *handle, int *value, int *scale);

typedef int (*SfdUserIsSkipFn)(SfdHandle *handle, int picture_type, int value, int scale);

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

typedef struct SfdTimerTimeUnit {
    int active;
    int fields_04[7];
    unsigned short field_20;
    unsigned short field_22;
    int value;
    int scale;
} SfdTimerTimeUnit;

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

typedef void (*SJErrorCallback)(void *object, int error);

typedef struct SJInterface SJInterface;

typedef struct SJ SJ;

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

typedef struct SfdVideoFrameState SfdVideoFrameState;

struct SfdVideoFrameState {
    int state;
    int field_04;
    union {
        unsigned char payload[0x80];
        SfdVideoFrameInfo info;
    } data;
};

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

typedef void (*SfdBufferHandleCallback)(SfdHandle *handle, int stream_index);

typedef void (*SfdBufferObjectCallback)(SfdCallbackObject object, int stream_index);

typedef struct SfdBufferChannel {
    SJ *stream_joint;
    SfdCallbackObject object;
    SfdBufferHandleCallback handle_callback;
    SfdBufferObjectCallback object_callback;
} SfdBufferChannel;

typedef union SfdBufferWork {
    SfdBufferRingWork ring;
    SfdBufferLinearWork linear;
    SfdBufferChannel user_channels[3];
    unsigned char raw[0x3C];
} SfdBufferWork;

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

typedef struct SfdUserOutputWork {
    int state;
    SfdBufferChannel channels[3];
} SfdUserOutputWork;

typedef struct SfdSeekState {
    SfdHandle *source_handle;
    int field_04;
    int field_08;
    int field_0C;
} SfdSeekState;

typedef struct SfdTimerSummary {
    long long total;
    long long minimum;
    long long maximum;
    int count;
    int field_1C;
} SfdTimerSummary;

struct SfdHandle {
    SfdCreateConfig create_config;
    int field_0044;
    int playback_state;
    int requested_state;
    int field_0050;
    int field_0054;
    unsigned char unknown_0058[0x20];
    SfdHeaderState header_state;
    unsigned char unknown_010C[0x800];
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

typedef struct SfxEffect SfxEffect;

typedef struct SfxTagInfo {
    int field_0x00;
    int composition_mode;
    int effect_type;
    int output_buffer_size;
    int output_buffer_count;
    int unit_width;
    int tag_info_set;
    union {
        int tag_start;
        void *tag_data;
    };
    int tag_size;
    char pad24[4];
    SfxEffect *effect;
    char pad2C[0x0C];
    int color_adjustment;
} SfxTagInfo;

typedef struct MwsSfxHandleView {
    SfxTagInfo tag_info;
    unsigned char reserved_03C[0x24];
    const char *picture_user_data;
    int picture_user_size;
} MwsSfxHandleView;

typedef struct MwsPlayer {
    unsigned char reserved_000[0x0C];
    int playback_state;
    unsigned char reserved_010[0x10];
    int field_020;
    unsigned char reserved_024[8];
    int field_02C;
    unsigned char reserved_030[0x10];
    SfdHandle *sfd;
    unsigned char reserved_044[0x0C];
    int composition_initialized;
    int composition_mode;
    unsigned char reserved_058[0x34];
    int picture_structure;
    int chroma_format;
    int field_094;
    int field_098;
    int field_09C;
    int chroma_position_0;
    int chroma_position_1;
    unsigned char reserved_0A8[4];
    MwsSfxHandleView *sfx;
    unsigned char reserved_0B0[56];
    SJ *additional_info_sj;
    void *additional_info_buffer;
    int additional_info_buffer_size;
    void *additional_info_copy;
    unsigned char reserved_1A0[4];
    int previous_tag_number;
    int tag_state;
    unsigned char *tag_data;
    int tag_size;
} MwsPlayer;

typedef struct fn_12_354BC_MovieModuleState_u1 {
    u8 pad_2c[0x2c];
    s32 state;
    u8 pad_30[0xbc];
    void *resource;
    void *resource_end;
} fn_12_354BC_MovieModuleState_u1;

typedef struct fn_12_3556C_MovieModuleState {
    u8 pad_a8[0xa8];
    void *movie;
} fn_12_3556C_MovieModuleState;

typedef struct fn_12_35868_MovieModuleState {
    u8 pad_a8[0xa8];
    void *value_a8;
} fn_12_35868_MovieModuleState;

typedef struct fn_12_35914_MovieModuleState {
    u8 pad_a8[0xa8];
    void *movie;
} fn_12_35914_MovieModuleState;

typedef struct fn_12_359B0_MovieModuleState {
    u8 pad_a8[0xa8];
    void *value_a8;
} fn_12_359B0_MovieModuleState;

typedef struct fn_12_357BC_MovieModuleState {
    u8 pad_a8[0xa8];
    void *value_a8;
} fn_12_357BC_MovieModuleState;

typedef struct MovieContext {
    u8 pad[0xa8];
    void* movie;
} MovieContext;

typedef struct MovieData {
    void* data;
} MovieData;

typedef struct Sig_fn_12_339B4_MovieOutput {
    u32 field_00;
    u32 field_04;
    u32 field_08;
    u32 field_0C;
    u32 field_10;
    u32 field_14;
} Sig_fn_12_339B4_MovieOutput;

struct Sig_fn_12_7E8_fn_12_7E8_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

struct Sig_fn_12_7E8_fn_12_7E8_Arg1 { u32 unk_0; };

struct Sig_fn_12_7E8_fn_12_7E8_Arg2 { u32 unk_0; };

typedef struct Sig_fn_12_23E0C_MovieState {
    u8 unk_00;
    u8 unk_01;
    u8 pad_02[0x06];
    void *unk_08;
    void *unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} Sig_fn_12_23E0C_MovieState;
extern void fn_12_49EC(void *);
extern void fn_12_758();
extern void fn_12_77C();
extern void fn_12_7A0(void *arg);
extern void fn_12_7C4(void *movie);
extern unsigned char *SJ_SearchTag(const SJCK *source, const char *tag, const char *terminator, SJCK *result);
void *memcpy(void *destination, const void *source, unsigned long size);
extern int fn_12_2FA90(MovieModule_u1 *module, int index, void *arg1, void *arg2);
extern const char lbl_12_rodata_17C0[8];
extern const char lbl_12_rodata_17C8[8];
extern void mwsftag_GetAinfFromSj(MwsPlayer *player);
extern void fn_12_818(void *resource, u32 value0, u32 value1);
extern const f64 lbl_12_rodata_1778;
extern u8 lbl_12_rodata_1780[64];
extern u8 lbl_12_rodata_17D0[252];
extern void *fn_80058498(void *resource, void *resource_end, s32 arg2);
extern void MWSFSVM_Error(...);
extern void mwSfdDestroy(MwsPlayer *player);
extern int fn_12_3A36C();
extern char lbl_12_rodata_18CC[51];
extern void fn_12_8B4(void *movie, void *arg1, void *arg2);
extern char lbl_12_rodata_1900[51];
extern void fn_12_8C8(void *movie, void *arg1, void *arg2);
extern void fn_12_750(void *movie);
extern u32 fn_12_8D4(u32);
extern u32 lbl_12_rodata_1934;
extern void fn_12_8DC();
extern u8 lbl_12_rodata_15D0[];
extern void fn_12_35B08(MovieContext*, MovieData*, void*);
extern void fn_12_D38(u32 arg0, u32 arg1, u32 arg2);
extern char lbl_12_rodata_1A30[47];
extern char lbl_12_rodata_1A60[46];
extern char lbl_12_rodata_1A90[47];
extern u8 lbl_12_rodata_1AC0[256];
extern void fn_12_D60(void *arg0, void *arg1, void *arg2);
extern char lbl_12_rodata_1BC0[49];
extern char lbl_12_rodata_1BF4[49];
extern void fn_12_D88(void *movie_data, void *out, s32 arg2, s32 arg3);
extern char lbl_12_rodata_1C28[49];
extern char lbl_12_rodata_1C5C[48];
extern void fn_12_147C(void *value, void *arg, void *extra);
extern char lbl_12_rodata_1C8C[51];
extern u8 lbl_12_rodata_1CC0[200];
extern void fn_12_3054();
extern void fn_12_339B4(u32, u32, u32, Sig_fn_12_339B4_MovieOutput *);
extern u32 fn_12_7E8(struct Sig_fn_12_7E8_fn_12_7E8_Arg0 *, struct Sig_fn_12_7E8_fn_12_7E8_Arg1 *, struct Sig_fn_12_7E8_fn_12_7E8_Arg2 *);
extern void fn_12_30E8(void);
extern MovieModule_u1 * fn_12_3148();
extern void fn_12_33D0(void);
extern void fn_12_33BC(u32 a, u32 b);
extern void fn_12_341C(void);
extern u32 *fn_12_38DBC(void);
extern void* fn_12_35E34(void* arg0, void* arg1, void* arg2);
extern char lbl_12_rodata_1E18[40];
extern char lbl_12_rodata_1E40[41];
extern void * memset(void *, int, u32);
extern void fn_12_23E0C(void *, void *, Sig_fn_12_23E0C_MovieState *);
extern void fn_12_336CC(const void *data, u32 size, void *out);
void fn_12_35E84(u32 arg0, s32 arg1, void *arg2);

/* fzgx:begin fn_12_35060 */
#pragma dont_inline on

/* --- rel/movie_module/fn_12_35060.c --- */
/* --- rel/movie_module/fn_12_35060.c --- */


void fn_12_35060(MovieModule_u1 *self) {
    fn_12_49EC(self->field_a8);
}
/* fzgx:end fn_12_35060 */

/* fzgx:begin fn_12_35084 */
/* --- rel/movie_module/fn_12_35084.c --- */

void fn_12_35084(MovieModule_u1 *self, int *out_a, int *out_b, int *out_c) {
    int value_a;
    int value_b;
    int value_c;

    fn_12_758(self->field_a8, &value_a, &value_b, &value_c);
    if (value_c == 1) {
        *out_c = 1;
    } else {
        *out_c = 0;
    }
    *out_a = value_a;
    *out_b = value_b;
}
/* fzgx:end fn_12_35084 */

/* fzgx:begin fn_12_35108 */
/* --- rel/movie_module/fn_12_35108.c --- */

struct fn_12_35108_Arg0 {
    u8 pad_0[0xA8];
    u32 unk_A8;
};

void fn_12_35108(struct fn_12_35108_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    fn_12_77C(arg0->unk_A8, arg1, arg2, ((u32)__cntlzw((1 - arg3)) >> 5));
}
/* fzgx:end fn_12_35108 */

/* fzgx:begin fn_12_35138 */
/* --- rel/movie_module/fn_12_35138.c --- */

void fn_12_35138(MovieModule_u1 *self) {
    fn_12_7A0(self->field_a8);
}
/* fzgx:end fn_12_35138 */

/* fzgx:begin fn_12_3515C */
/* --- rel/movie_module/fn_12_3515C.c --- */
/* --- rel/movie_module/fn_12_3515C.c --- */


void fn_12_3515C(MovieModule_u2 *module) {
    fn_12_7C4(module->movie);
}
/* fzgx:end fn_12_3515C */

/* fzgx:begin mwsftag_GetAinfFromSj */
/* --- rel/movie_module/mwsftag_GetAinfFromSj.c --- */









void mwsftag_GetAinfFromSj(MwsPlayer *player) {
    SJCK source;
    SJCK result;
    SJCK consumed;
    SJ *sj = player->additional_info_sj;
    int num_data;
    int stopped;
    num_data = sj->interface->get_num_data(sj, 1);
    if (num_data == 0) {
        player->tag_data = 0;
        player->tag_size = 0;
        player->tag_state = 1;
        return;
    }
    source.data = player->additional_info_buffer;
    source.len = num_data;
    if (SJ_SearchTag(&source, lbl_12_rodata_17C0, lbl_12_rodata_17C8, &result) == 0) {
        player->tag_data = 0;
        player->tag_size = 0;
        player->tag_state = 1;
        return;
    }
    if (player->additional_info_copy != 0) {
        memcpy(player->additional_info_copy, result.data, result.len);
        player->tag_data = player->additional_info_copy;
        player->tag_size = result.len;
        player->tag_state = 1;
        sj->interface->get_chunk(sj, 1, 0x7FFFFFFF, &consumed);
        sj->interface->put_chunk(sj, 0, &consumed);
        sj->interface->reset(sj);
        return;
    }
    player->tag_data = result.data;
    player->tag_size = result.len;
    player->tag_state = 1;
    if (player->playback_state == 2) {
        stopped = 1;
    } else {
        stopped = 0;
    }
    if (stopped != 1 && player->additional_info_sj != 0) {
        fn_12_2FA90( (MovieModule_u1 *)(SfdHandle *)(player->sfd), 2, (void *)(SJ *)(0), 0);
    }
}
/* fzgx:end mwsftag_GetAinfFromSj */

/* fzgx:begin fn_12_3530C */
/* --- rel/movie_module/fn_12_3530C.c --- */
typedef struct fn_12_3530C_MovieModuleState {
    u8 pad_a8[0xa8];
    void *movie_resource;
    u8 pad_ac[0x3c];
    u8 *movie_data;
    u8 pad_ec[0x18];
    u32 value_104;
    u32 value_108;
} fn_12_3530C_MovieModuleState;


void fn_12_3530C(fn_12_3530C_MovieModuleState *self) {
    u32 output[2];
    u32 input[2];
    void *resource;

    if (self->movie_data != 0) {
        mwsftag_GetAinfFromSj( (MwsPlayer *)(fn_12_3530C_MovieModuleState *)(self));
        resource = self->movie_resource;
        if (self->value_104 == 0) {
            fn_12_818(resource, 0, 0);
        } else {
            input[0] = self->value_104;
            input[1] = self->value_108;
            if (((void *)SJ_SearchTag( (const SJCK *)(void *)(input), (const char *)(const f64 *)(&lbl_12_rodata_1778), (const char *)(u8 *)(lbl_12_rodata_1780), (SJCK *)(void *)(output))) == 0) {
                fn_12_818(resource, 0, 0);
            } else {
                fn_12_818(resource, output[0], output[1]);
            }
        }
    }
}
/* fzgx:end fn_12_3530C */

/* fzgx:begin fn_12_353C4 */
/* --- rel/movie_module/fn_12_353C4.c --- */
typedef struct fn_12_353C4_Movie fn_12_353C4_Movie;
typedef struct fn_12_353C4_MovieVTable fn_12_353C4_MovieVTable;

struct fn_12_353C4_MovieVTable {
    u8 pad_00[0x14];
    void (*method_14)(fn_12_353C4_Movie *self);
};

struct fn_12_353C4_Movie {
    fn_12_353C4_MovieVTable *vtable;
};

typedef struct fn_12_353C4_MovieModuleState_u1 {
    u8 pad_e8[0xe8];
    fn_12_353C4_Movie *movie;
} fn_12_353C4_MovieModuleState_u1;

void fn_12_353C4(fn_12_353C4_MovieModuleState_u1 *self) {
    fn_12_353C4_Movie *movie = self->movie;

    if (movie != 0) {
        movie->vtable->method_14(movie);
    }
}
/* fzgx:end fn_12_353C4 */

/* fzgx:begin fn_12_353FC */
/* --- rel/movie_module/fn_12_353FC.c --- */
typedef struct fn_12_353FC_MovieModuleState_u2 {
    u8 pad_fc[0xfc];
    s32 status;
    s32 value_100;
    s32 value_104;
    s32 value_108;
} fn_12_353FC_MovieModuleState_u2;

void fn_12_353FC(fn_12_353FC_MovieModuleState_u2 *self) {
    self->value_100 = 0;
    self->value_104 = 0;
    self->value_108 = 0;
    self->status = -1;
}
/* fzgx:end fn_12_353FC */

/* fzgx:begin fn_12_35418 */
/* --- rel/movie_module/fn_12_35418.c --- */
typedef struct MovieModuleState_u3 {
    u8 pad_0c[0x0c];
    s32 status;
    u8 pad_10[0x30];
    s32 value_40;
    u8 pad_44[0xa4];
    void *movie;
} MovieModuleState_u3;


s32 fn_12_35418(MovieModuleState_u3 *self) {
    s32 status_eq;

    status_eq = self->status == 2;
    if (status_eq == 1) {
        return 0;
    }

    if (self->movie == 0) {
        return 0;
    }

    return fn_12_2FA90( (MovieModule_u1 *)(s32)(self->value_40), 2, self->movie, (void *)(s32)(0)) ? -1 : 0;
}
/* fzgx:end fn_12_35418 */

/* fzgx:begin fn_12_35484 */
/* --- rel/movie_module/fn_12_35484.c --- */
typedef struct fn_12_35484_Movie fn_12_35484_Movie;
typedef void (*MovieCallback)(fn_12_35484_Movie *);

typedef struct fn_12_35484_MovieVTable {
    u8 pad_0c[0x0c];
    MovieCallback callback;
} fn_12_35484_MovieVTable;

struct fn_12_35484_Movie {
    fn_12_35484_MovieVTable *vtable;
};

typedef struct fn_12_35484_MovieModuleState {
    u8 pad_e8[0xe8];
    fn_12_35484_Movie *movie;
} fn_12_35484_MovieModuleState;

void fn_12_35484(fn_12_35484_MovieModuleState *self) {
    fn_12_35484_Movie *movie = self->movie;

    if (movie != 0) {
        movie->vtable->callback(movie);
    }
}
/* fzgx:end fn_12_35484 */

/* fzgx:begin fn_12_354BC */
/* --- rel/movie_module/fn_12_354BC.c --- */


u32 fn_12_354BC(fn_12_354BC_MovieModuleState_u1 *self) {
    s32 valid;

    if (self->state == 0 || self->state == 0x101) {
        valid = 1;
    } else {
        valid = 0;
    }

    if (valid == 0) {
        return 0;
    }

    if (fn_80058498(self->resource, self->resource_end, 0) == 0) {
        MWSFSVM_Error(lbl_12_rodata_17D0);
        mwSfdDestroy( (MwsPlayer *)(fn_12_354BC_MovieModuleState_u1 *)(self));
        return 0;
    }
}
/* fzgx:end fn_12_354BC */

/* fzgx:begin fn_12_35548 */
/* --- rel/movie_module/fn_12_35548.c --- */
typedef struct fn_12_35548_MovieModuleState_u2 {
    u8 pad_20[0x20];
    s32 state;
} fn_12_35548_MovieModuleState_u2;

u32 fn_12_35548(fn_12_35548_MovieModuleState_u2 *self) {
    if (self->state == 0 || self->state == 0x101) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_12_35548 */

/* fzgx:begin fn_12_3556C */
/* --- rel/movie_module/fn_12_3556C.c --- */


void fn_12_3556C(fn_12_3556C_MovieModuleState *self, void *arg1, void *arg2) {
    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(lbl_12_rodata_18CC);
    } else {
        fn_12_8B4(self->movie, arg1, arg2);
    }
}
/* fzgx:end fn_12_3556C */

/* fzgx:begin fn_12_355DC */
/* --- rel/movie_module/fn_12_355DC.c --- */

void fn_12_355DC(fn_12_3556C_MovieModuleState *self, void *arg1, void *arg2) {
    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(lbl_12_rodata_1900);
    } else {
        fn_12_8C8(self->movie, arg1, arg2);
    }
}
/* fzgx:end fn_12_355DC */

/* fzgx:begin fn_12_3564C */
/* --- rel/movie_module/fn_12_3564C.c --- */

void fn_12_3564C(fn_12_3556C_MovieModuleState *self) {
    fn_12_750(self->movie);
}
/* fzgx:end fn_12_3564C */

/* fzgx:begin fn_12_35670 */
/* --- rel/movie_module/fn_12_35670.c --- */
void fn_12_35670(fn_12_3556C_MovieModuleState *self) {
    fn_12_750(self->movie);
}
/* fzgx:end fn_12_35670 */

/* fzgx:begin fn_12_35694 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_35694.c --- */
extern u32 MWSFSVM_Error(u32, ...);
extern u32 fn_12_3A36C(u32);
extern u32 fn_12_8D4(u32);
extern u32 lbl_12_rodata_1934;

u32 fn_12_35694(u32 arg0) {
    u32 v0;
    u32 t0, t1, t2;
    t0 = fn_12_3A36C(arg0);
    v0 = t0;
    if ((s32)t0 == 0) {
    v0 = (u32)&lbl_12_rodata_1934;
    t1 = MWSFSVM_Error((u32)v0);
    v0 = t1;
    v0 = 0;
    } else {
    v0 = *(u32 *)((u8 *)arg0 + 168);
    t2 = fn_12_8D4(v0);
    v0 = t2;
    }
    return v0;
}
/* fzgx:end fn_12_35694 */

/* fzgx:begin fn_12_356E8 noprologue */
/* --- rel/movie_module/fn_12_356E8.c --- */
typedef struct MovieModuleState {
    u8 pad_a8[0xa8];
    void *value_a8;
} MovieModuleState;

extern void fn_12_8DC(void *);

void fn_12_356E8(MovieModuleState *self) {
    fn_12_8DC(self->value_a8);
}
/* fzgx:end fn_12_356E8 */

/* fzgx:begin fn_12_3570C */
typedef struct fn_12_3570C_MovieModuleState {
    u8 pad_a8[0xa8];
    void *movie;
    u8 pad_ac[0x3c];
    void *value_e8;
} fn_12_3570C_MovieModuleState;


void fn_12_3570C(fn_12_3570C_MovieModuleState *self, int mode) {
    const u8 *text = lbl_12_rodata_15D0;

    if (fn_12_3A36C() == 0) {
        MWSFSVM_Error((const char *)(text + 0x398));
    } else if (self->value_e8 == 0 && mode == 0x101) {
        MWSFSVM_Error((const char *)(text + 0x3cc));
    } else if (self->value_e8 == 0 && mode == 0) {
        MWSFSVM_Error((const char *)(text + 0x414));
    } else {
        fn_12_8DC(self->movie, mode);
    }
}
/* fzgx:end fn_12_3570C */

/* fzgx:begin fn_12_357BC */


void fn_12_357BC(fn_12_357BC_MovieModuleState *self, void *arg, void *value) {
    u8 local[0x88];
    void *movie;

    if (fn_12_3A36C(self, arg, value) == 0) {
        MWSFSVM_Error(lbl_12_rodata_1A30);
    } else if (*(void **)arg == 0) {
        MWSFSVM_Error(lbl_12_rodata_1A60);
    } else {
        movie = self->value_a8;
        fn_12_35B08( (MovieContext*)(fn_12_357BC_MovieModuleState *)(self), (MovieData*)(void *)(arg), local);
        fn_12_D38( (u32)(void *)(movie), (u32)(void *)(local), (u32)(void *)(value));
    }
}
/* fzgx:end fn_12_357BC */

/* fzgx:begin fn_12_35868 */


void fn_12_35868(fn_12_35868_MovieModuleState *self, void *movie, void *arg) {
    u8 result[0x80];

    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(lbl_12_rodata_1A90);
    } else if (*(void **)movie == 0) {
        MWSFSVM_Error((const char *)lbl_12_rodata_1AC0);
    } else {
        void *value = self->value_a8;
        fn_12_35B08( (MovieContext*)(fn_12_35868_MovieModuleState *)(self), (MovieData*)(void *)(movie), result);
        fn_12_D60(value, result, arg);
    }
}
/* fzgx:end fn_12_35868 */

/* fzgx:begin fn_12_35914 */
typedef struct fn_12_35914_Movie {
    void *value;
} fn_12_35914_Movie;



void fn_12_35914(fn_12_35914_MovieModuleState *self, fn_12_35914_Movie *movie, s32 arg2, s32 arg3) {
    void *movie_data;
    u8 local[0x90];

    if (!fn_12_3A36C(self)) {
        MWSFSVM_Error(lbl_12_rodata_1BC0);
    } else if (movie->value == 0) {
        MWSFSVM_Error(lbl_12_rodata_1BF4);
    } else {
        movie_data = self->movie;
        fn_12_35B08( (MovieContext*)(fn_12_35914_MovieModuleState *)(self), (MovieData*)(fn_12_35914_Movie *)(movie), local);
        fn_12_D88(movie_data, local, arg2, arg3);
    }
}
/* fzgx:end fn_12_35914 */

/* fzgx:begin fn_12_359B0 */


void fn_12_359B0(fn_12_359B0_MovieModuleState *self, void *arg, void *extra) {
    u8 local[0x80];
    void *value_a8;

    if (fn_12_3A36C(self) == 0) {
        MWSFSVM_Error(lbl_12_rodata_1C28);
    } else if (*(void **)arg == 0) {
        MWSFSVM_Error(lbl_12_rodata_1C5C);
    } else {
        value_a8 = self->value_a8;
        fn_12_35B08( (MovieContext*)(fn_12_359B0_MovieModuleState *)(self), (MovieData*)(void *)(arg), local);
        fn_12_147C(value_a8, local, extra);
    }
}
/* fzgx:end fn_12_359B0 */

/* fzgx:begin fn_12_35A5C */



void fn_12_35A5C(MovieContext* context, MovieData* data, void* arg) {
    u8 local[0x88];
    void* movie;

    if (fn_12_3A36C() == 0) {
        MWSFSVM_Error(lbl_12_rodata_1C8C);
    } else if (data->data == 0) {
        MWSFSVM_Error((const char*)lbl_12_rodata_1CC0);
    } else {
        movie = context->movie;
        fn_12_35B08(context, data, local);
        fn_12_3054(movie, local, arg);
    }
}
/* fzgx:end fn_12_35A5C */

/* fzgx:begin fn_12_35B08 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_35B08.c --- */
static const char lbl_12_rodata_15D0[424] = "E211054: MWSFD_CnvFrmLowHalfARGB8888: handle is invalid.\000\000\000\000E211055: MWSFD_CnvFrmLow"
    "HalfARGB8888: getfrm is failed.\000E211052: MWSFD_CnvFrmLowHalfARGB8888: handle is invalid.\000"
    "\000\000\000E211053: MWSFD_CnvFrmLowHalfARGB8888: getfrm is failed.\000E202285: MWSFD_MakeTblZ32"
    ": handle is invalid.\000\000\000E202286: MWSFD_MakeTblZ32: getfrm is failed.\000\000\000\000E202"
    "283: MWSFD_MakeTblZ16: handle is invalid.\000\000\000E202284: MWSFD_MakeTblZ16: getfrm is failed"
    ".\000\000\000\000";
static const char lbl_12_rodata_1778[8] = "SFXINFS\000";
static const char lbl_12_rodata_1780[64] = "SFXINFE\000W2121001 : mwPlyAttachAddInfBuf(): bufsize is short.\000\000\000\000";
static const char lbl_12_rodata_17C0[8] = "CRITAGS\000";
static const char lbl_12_rodata_17C8[8] = "CRITAGE\000";
static const char lbl_12_rodata_17D0[252] = "E201211 mwPlyCreate: can't create AddInfSJ\000\000E2011921: mwPlyFxGetOutZoffset: handle is inva"
    "lid.\000\000E2011920: mwPlyFxSetOutZoffset: handle is invalid.\000\000E2011919: mwPlyFxGetOutZsc"
    "ale: handle is invalid.\000\000\000E2011918: mwPlyFxSetOutZscale: handle is invalid.\000\000\000";
static const char lbl_12_rodata_18CC[51] = "E2011917: mwPlyFxGetOutBufSize: handle is invalid.\000";
static const char lbl_12_rodata_1900[51] = "E2011916: mwPlyFxSetOutBufSize: handle is invalid.\000";
static const char lbl_12_rodata_1934[252] = "E2011915: mwPlyFxGetCompoMode: handle is invalid.\000\000\000E201214: mwPlyFxSetCompoMode: handl"
    "e is invalid.\000\000\000\000E204011: mwPlyFxSetCompoMode: COMPO_Z needs setting in MWPLY Creati"
    "on.\000\000E204012: mwPlyFxSetCompoMode: COMPO_AUTO needs setting in MWPLY Creation.\000\000\000";
static const char lbl_12_rodata_1A30[47] = "E2011913: mwPlyFxCnvFrmZ32: handle is invalid.\000";
static const char lbl_12_rodata_1A60[46] = "E2011914: mwPlyFxCnvFrmZ32: getfrm is failed.\000";
static const char lbl_12_rodata_1A90[47] = "E2011911: mwPlyFxCnvFrmZ16: handle is invalid.\000";
static const char lbl_12_rodata_1AC0[256] = "E2011912: mwPlyFxCnvFrmZ16: getfrm is failed.\000\000\000E301284: mwPlyFxCnvFrmRGB888: handle is"
    " invalid.\000\000\000\000E301285: mwPlyFxCnvFrmRGB888: getfrm is failed.\000E212176: mwPlyFxCnvF"
    "rmMbARGB8888: handle is invalid.\000\000\000\000E212177: mwPlyFxCnvFrmMbARGB8888: getfrm is fail"
    "ed.\000";
static const char lbl_12_rodata_1BC0[49] = "E201199: mwPlyFxCnvFrmYUV422: handle is invalid.\000";
static const char lbl_12_rodata_1BF4[49] = "E2011910: mwPlyFxCnvFrmYUV422: getfrm is failed.\000";
static const char lbl_12_rodata_1C28[49] = "E201197: mwPlyFxCnvFrmYUV422: handle is invalid.\000";
static const char lbl_12_rodata_1C5C[48] = "E201198: mwPlyFxCnvFrmYUV422: getfrm is failed.\000";
static const char lbl_12_rodata_1C8C[51] = "E201195: mwPlyFxCnvFrmARGB8888: handle is invalid.\000";
static const char lbl_12_rodata_1CC0[52] = "E201196: mwPlyFxCnvFrmARGB8888: getfrm is failed.\000\000\000";
static const char lbl_12_rodata_1CC0__fzgx_offset_34[32] = "E301274 : chromapos is invalid.\000";
static const char lbl_12_rodata_1CC0__fzgx_offset_54[36] = "E301273 : chroma_format is invalid.\000";
static const char lbl_12_rodata_1CC0__fzgx_offset_78[40] = "E301272 : picture_structure is invalid.\000";
static const char lbl_12_rodata_1CC0__fzgx_offset_A0[40] = "E201184 : MwsfdBufFmt value is invalid.\000";
#pragma section code_type ".fzgxpool"
static void movie_format_literal_layout(void) {
    const void * volatile object; /* fzgx-allow: S2 byte-proven readonly object first-access order */
    object = lbl_12_rodata_15D0;
    object = lbl_12_rodata_1778;
    object = lbl_12_rodata_1780;
    object = lbl_12_rodata_17C0;
    object = lbl_12_rodata_17C8;
    object = lbl_12_rodata_17D0;
    object = lbl_12_rodata_18CC;
    object = lbl_12_rodata_1900;
    object = lbl_12_rodata_1934;
    object = lbl_12_rodata_1A30;
    object = lbl_12_rodata_1A60;
    object = lbl_12_rodata_1A90;
    object = lbl_12_rodata_1AC0;
    object = lbl_12_rodata_1BC0;
    object = lbl_12_rodata_1BF4;
    object = lbl_12_rodata_1C28;
    object = lbl_12_rodata_1C5C;
    object = lbl_12_rodata_1C8C;
    object = lbl_12_rodata_1CC0;
    object = lbl_12_rodata_1CC0__fzgx_offset_34;
    object = lbl_12_rodata_1CC0__fzgx_offset_54;
    object = lbl_12_rodata_1CC0__fzgx_offset_78;
    object = lbl_12_rodata_1CC0__fzgx_offset_A0;
}
#pragma section code_type ".text"

extern void MWSFSVM_Error(const char *, ...);
typedef struct Sig_fn_12_339B4_MovieOutput {
    u32 field_00;
    u32 field_04;
    u32 field_08;
    u32 field_0C;
    u32 field_10;
    u32 field_14;
} Sig_fn_12_339B4_MovieOutput;
extern void fn_12_339B4(u32, u32, u32, Sig_fn_12_339B4_MovieOutput *);
struct Sig_fn_12_7E8_fn_12_7E8_Arg0 {
    u8 pad_0[0x10];
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};
struct Sig_fn_12_7E8_fn_12_7E8_Arg1 { u32 unk_0; };
struct Sig_fn_12_7E8_fn_12_7E8_Arg2 { u32 unk_0; };
extern u32 fn_12_7E8(struct Sig_fn_12_7E8_fn_12_7E8_Arg0 *, struct Sig_fn_12_7E8_fn_12_7E8_Arg1 *, struct Sig_fn_12_7E8_fn_12_7E8_Arg2 *);

#pragma opt_propagation off
static inline s32 movie_buffer_format(s32 value) {
    s32 result;
    switch (value) {
    case 1: result = 1; break;
    case 2: result = 2; break;
    case 3: result = 3; break;
    default:
        MWSFSVM_Error(lbl_12_rodata_1CC0__fzgx_offset_A0);
        result = 3;
        break;
    }
    return result;
}

static inline s32 movie_picture_structure(s32 value) {
    s32 result = 3;
    switch (value) {
    case 1: result = 1; break;
    case 2: result = 2; break;
    case 3: result = 3; break;
    default: MWSFSVM_Error(lbl_12_rodata_1CC0__fzgx_offset_78); break;
    }
    return result;
}

static inline s32 movie_chroma_format(s32 value) {
    s32 result = 1;
    switch (value) {
    case 1: result = 1; break;
    case 2: result = 2; break;
    case 3: result = 3; break;
    default: MWSFSVM_Error(lbl_12_rodata_1CC0__fzgx_offset_54); break;
    }
    return result;
}

static inline s32 movie_chroma_position(s32 value) {
    s32 result = 1;
    switch (value) {
    case 0: result = 0; break;
    case 1: result = 1; break;
    default: MWSFSVM_Error(lbl_12_rodata_1CC0__fzgx_offset_34); break;
    }
    return result;
}

void fn_12_35B08(u32 input0, u32 arg1, u32 input2) {
    u32 arg2 = input2;
    u32 arg0 = input0;
    u32 v0;
    u32 width;
    u32 height;
    s32 mode;
    Sig_fn_12_339B4_MovieOutput planes;
    struct Sig_fn_12_7E8_fn_12_7E8_Arg2 b;
    struct Sig_fn_12_7E8_fn_12_7E8_Arg1 a;
    v0 = movie_buffer_format(*(s32 *)((u8 *)arg1 + 4));
    *(u32 *)arg2 = v0;
    width = *(u32 *)((u8 *)arg1 + 8);
    height = *(u32 *)((u8 *)arg1 + 12);
    *(u32 *)((u8 *)arg2 + 0x44) = width;
    *(u32 *)((u8 *)arg2 + 0x48) = height;
    if (*(s32 *)((u8 *)arg1 + 4) != 3) {
    *(u32 *)((u8 *)arg2 + 4) = *(u32 *)arg1;
    *(u32 *)((u8 *)arg2 + 8) = width;
    *(u32 *)((u8 *)arg2 + 12) = height;
    } else {
    fn_12_339B4(*(u32 *)arg1, width, height, &planes);
    width = planes.field_0C;
    *(u32 *)((u8 *)arg2 + 4) = planes.field_00;
    *(u32 *)((u8 *)arg2 + 8) = width;
    *(u32 *)((u8 *)arg2 + 12) = height;
    v0 = planes.field_04;
    width = planes.field_10;
    *(u32 *)((u8 *)arg2 + 0x14) = v0;
    *(u32 *)((u8 *)arg2 + 0x18) = width;
    *(u32 *)((u8 *)arg2 + 0x1c) = height;
    width = planes.field_14;
    *(u32 *)((u8 *)arg2 + 0x24) = planes.field_08;
    *(u32 *)((u8 *)arg2 + 0x28) = width;
    *(u32 *)((u8 *)arg2 + 0x2c) = height;
    }
    *(u32 *)((u8 *)arg2 + 0x4c) = *(u32 *)((u8 *)arg1 + 0x30);
    fn_12_7E8(*(struct Sig_fn_12_7E8_fn_12_7E8_Arg0 **)((u8 *)arg0 + 0xa8), &a, &b);
    *(u32 *)((u8 *)arg2 + 0x50) = a.unk_0;
    *(u32 *)((u8 *)arg2 + 0x54) = b.unk_0;
    *(u32 *)((u8 *)arg2 + 0x58) = 0;
    *(u32 *)((u8 *)arg2 + 0x5c) = 0;
    mode = movie_picture_structure(*(s32 *)((u8 *)arg0 + 0x88));
    *(u32 *)((u8 *)arg2 + 0x60) = mode;
    mode = movie_chroma_format(*(s32 *)((u8 *)arg0 + 0x8c));
    *(u32 *)((u8 *)arg2 + 0x64) = mode;
    *(u32 *)((u8 *)arg2 + 0x68) = *(u32 *)((u8 *)arg0 + 0x90);
    *(u32 *)((u8 *)arg2 + 0x6c) = *(u32 *)((u8 *)arg0 + 0x94);
    *(u32 *)((u8 *)arg2 + 0x70) = *(u32 *)((u8 *)arg0 + 0x98);
    mode = movie_chroma_position(*(s32 *)((u8 *)arg0 + 0x9c));
    *(u32 *)((u8 *)arg2 + 0x74) = mode;
    mode = movie_chroma_position(*(s32 *)((u8 *)arg0 + 0xa0));
    *(u32 *)((u8 *)arg2 + 0x78) = mode;
}
/* fzgx:end fn_12_35B08 */

/* fzgx:begin fn_12_35D74 noprologue */
#pragma opt_propagation reset

/* --- rel/movie_module/fn_12_35D74.c --- */
/* --- rel/movie_module/fn_12_35D74.c --- */
/* --- rel/movie_module/fn_12_35D74.c --- */
extern void fn_12_30E8(void);

void fn_12_35D74(void) {
    fn_12_30E8();
}
/* fzgx:end fn_12_35D74 */

/* fzgx:begin fn_12_35D94 noprologue */
/* --- rel/movie_module/fn_12_35D94.c --- */
extern void fn_12_3148(void);

void fn_12_35D94(void) {
    fn_12_3148();
}
/* fzgx:end fn_12_35D94 */

/* fzgx:begin fn_12_35DB4 noprologue */
/* --- rel/movie_module/fn_12_35DB4.c --- */
// fn_12_35DB4: returns a constant.
int fn_12_35DB4(void) {
    return 12319;
}
/* fzgx:end fn_12_35DB4 */

/* fzgx:begin fn_12_35DBC noprologue */
/* --- rel/movie_module/fn_12_35DBC.c --- */
extern void fn_12_33D0(void);

void fn_12_35DBC(void) {
    fn_12_33D0();
}
/* fzgx:end fn_12_35DBC */

/* fzgx:begin fn_12_35DDC noprologue */
/* --- rel/movie_module/fn_12_35DDC.c --- */

void fn_12_35DDC(void* arg0, void* arg1) {
    MWSFSVM_Error(arg1);
}
/* fzgx:end fn_12_35DDC */

/* fzgx:begin fn_12_35E04 noprologue */
/* --- rel/movie_module/fn_12_35E04.c --- */
/* --- rel/movie_module/fn_12_35E04.c --- */
extern u32 fn_12_33BC(u32, u32);
extern u32 fn_12_341C(void);

u32 fn_12_35E04(void) {
    fn_12_341C();
    return fn_12_33BC((u32)fn_12_35DDC, 0);
}

/* --- rel/movie_module/fn_12_35E34.c --- */
extern void* fn_12_38DBC(void*);

void* fn_12_35E34(void* arg0, void* arg1, void* arg2);

/* --- rel/movie_module/fn_12_35E84.c --- */
typedef struct Sig_fn_12_23E0C_MovieState {
    u8 unk_00;
    u8 unk_01;
    u8 pad_02[0x06];
    void *unk_08;
    void *unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} Sig_fn_12_23E0C_MovieState;

typedef struct OutBlock {
    s32 f0;
    s32 f1;
    s32 f2;
    s32 f3;
    s32 f4;
    s32 f5;
    s32 f6;
    s32 f7;
} OutBlock;

extern char lbl_12_rodata_1E18[40];
extern char lbl_12_rodata_1E40[41];
extern void * memset(void *, int, u32);
extern void fn_12_23E0C(void *, void *, Sig_fn_12_23E0C_MovieState *);
extern void fn_12_336CC(const void *, u32, void *);

void fn_12_35E84(u32 arg0, s32 arg1, void *arg2);
/* fzgx:end fn_12_35E04 */
