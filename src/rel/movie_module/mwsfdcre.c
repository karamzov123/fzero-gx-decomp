#include "types.h"

/* fzgx:begin fn_12_35E34 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_35DDC.c --- */
extern void MWSFSVM_Error(void*, ...);

/* --- rel/movie_module/fn_12_35E34.c --- */
extern void* fn_12_38DBC(void*);

void* fn_12_35E34(void* arg0, void* arg1, void* arg2) {
    void* result;

    result = fn_12_38DBC(arg0);
    *(void**)((u8*)result + 0x28) = arg0;
    *(void**)((u8*)result + 0x2C) = arg1;
    *(void**)((u8*)result + 0x30) = arg2;
    return result;
}
/* fzgx:end fn_12_35E34 */

/* fzgx:begin fn_12_35E84 noprologue */

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

void fn_12_35E84(u32 arg0, s32 arg1, void *arg2) {
    u32 x;
    OutBlock loc_8;
    u8 loc_28[0x48];
    s32 flag;
    s32 valid;

    x = arg0;
    if (x == 0 || arg2 == 0) {
        MWSFSVM_Error(lbl_12_rodata_1E18);
    } else if (arg1 <= 0) {
        MWSFSVM_Error(lbl_12_rodata_1E40);
    } else {
        memset(&loc_8, 0, sizeof(loc_8));
        fn_12_23E0C((void *)arg0, (void *)arg1, (Sig_fn_12_23E0C_MovieState *)loc_28);
        if ((s8)loc_28[0x00] == 0 || (s8)loc_28[0x01] == 0) {
            *(OutBlock *)arg2 = loc_8;
            ((OutBlock *)arg2)->f0 = 0;
        } else {
            flag = 0;
            if (*(u32 *)(loc_28 + 0x04) == 0) {
                if (*(u32 *)(loc_28 + 0x08) != 0) {
                    if (*(u32 *)(loc_28 + 0x0c) == 0) {
                        flag = 2;
                    }
                }
            } else {
                if (*(u32 *)(loc_28 + 0x0c) == 0) {
                    flag = 3;
                } else {
                    flag = 1;
                }
            }
            loc_8.f1 = flag;
            loc_8.f2 = *(s32 *)(loc_28 + 0x14);
            loc_8.f3 = *(s32 *)(loc_28 + 0x18);
            loc_8.f4 = *(s32 *)(loc_28 + 0x20);
            loc_8.f5 = *(s32 *)(loc_28 + 0x2c);
            loc_8.f6 = (s8)loc_28[0x28];
            fn_12_336CC((const void *)arg0, arg1, &loc_8);
            if (loc_8.f1 == 0) {
                valid = 0;
            } else {
                if (loc_8.f2 * loc_8.f3 > 0x65400) {
                    valid = 0;
                } else {
                    valid = 1;
                }
            }
            loc_8.f0 = valid;
            *(OutBlock *)arg2 = loc_8;
        }
    }
}
/* fzgx:end fn_12_35E84 */

/* fzgx:begin mwSfdDestroy noprologue */

#include "types.h"

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

typedef struct LSC LSC;

typedef struct SFXHandle SFXHandle;

typedef struct MwsPlayer MwsPlayer;

typedef void *(*MwsMallocFn)(void *, int);

typedef void (*MwsFreeFn)(void *, void *);

typedef struct MwsStHandle {
    int active;
    unsigned char reserved_004[8];
    SJ *stream;
    int element_id;
    void *backend;
} MwsStHandle;

typedef struct MwsPictureUserConfig {
    void *buffer;
    int buffer_size;
    int element_size;
} MwsPictureUserConfig;

struct MwsPlayer {
    const void *interface;
    int active;
    int status;
    int file_type;
    int maximum_bps;
    int width;
    int height;
    int frame_count;
    int decoder_count;
    void *create_work;
    int create_work_size;
    int composition_mode;
    int buffer_format;
    int create_field_28;
    int create_field_2C;
    int playback_mode;
    SfdHandle *sfd;
    void *stream;
    void *transport;
    LSC *loader;
    int field_050;
    int field_054;
    int field_058;
    int flow_limit;
    int field_060;
    unsigned char reserved_064[8];
    int field_06C;
    int field_070;
    signed char concat_play;
    signed char concat_stopped;
    signed char paused;
    unsigned char field_077;
    int entry_count;
    unsigned char reserved_07C[12];
    int field_088;
    unsigned char reserved_08C[28];
    SFXHandle *sfx;
    void *composition_work;
    int composition_work_size;
    unsigned char reserved_0B8[8];
    MwsPictureUserConfig internal_picture_user;
    unsigned char reserved_170[12];
    MwsPictureUserConfig *picture_user;
    void *picture_user_work;
    int picture_user_header_size;
    int picture_user_write;
    int picture_user_read;
    SJ *additional_info_sj;
    void *additional_info_buffer;
    int additional_info_buffer_size;
    unsigned char reserved_19C[0x1C];
    char *filename;
    int filename_capacity;
    int start_requested;
    int file_offset;
    int file_length;
    int file_end_position;
    SJ *supply_sj;
    SJ *input_sj;
    void *input_buffer;
    int input_buffer_size;
    int input_buffer_extra_size;
    int supply_mode;
    void *supply_buffer;
    int supply_buffer_size;
    int supply_buffer_extra_size;
    SJ *memory_sj;
    void *memory_buffer;
    int memory_buffer_size;
    void *arena;
    unsigned int arena_size;
    unsigned char *arena_cursor;
    unsigned int arena_used;
    int allocation_count;
    void *allocations[32];
    MwsStHandle sound;
    unsigned char reserved_2AC[32];
    int sound_state;
};

typedef struct MwsLibraryWork {
    int field_00;
    float frame_rate;
    int maximum_width;
    int decoder_count;
    int field_10;
    unsigned char reserved_014[0x14];
    MwsMallocFn malloc_fn;
    MwsFreeFn free_fn;
    void *allocator_object;
    unsigned char reserved_034[4];
    int use_picture_user_data;
    int pause_border;
    unsigned char reserved_040[0x1C];
    int field_5C;
    unsigned char reserved_060[8];
    int error_code;
    MwsPlayer players[8];
} MwsLibraryWork;

typedef struct MwsPlayerInterface {
    void *reserved[3];
    void (*vsync)(void);
    int (*exec_server)(MwsPlayer *);
    void (*destroy)(MwsPlayer *);
    void (*start_filename)(MwsPlayer *, const char *);
    void (*stop)(MwsPlayer *);
    int (*get_status)(MwsPlayer *);
    void (*get_time)(MwsPlayer *, int *, int *);
    void (*pause)(MwsPlayer *, int);
    void (*set_volume)(MwsPlayer *, int);
    int (*get_volume)(MwsPlayer *);
    void (*set_pan)(MwsPlayer *, int);
    int (*get_pan)(MwsPlayer *);
    void (*start_sj)(MwsPlayer *, SJ *);
    void (*start_memory)(MwsPlayer *, void *, int);
} MwsPlayerInterface;

void *memset(void *destination, int value, unsigned long size);

int fn_12_2B6B0(SfdHandle *handle);

extern MwsLibraryWork *fn_12_38DBC(void);

extern int fn_12_38A0C(int);

extern void MWSFSVM_Error(const char *, ...);

extern void fn_12_390E4(MwsPlayer *);

extern void fn_12_35484(MwsPlayer *);

extern void fn_12_3B15C(MwsStHandle *);

extern void fn_12_35D74(SFXHandle *);

extern void fn_12_34F64(void *);

extern void fn_80057114(LSC *);

extern const char lbl_12_rodata_1E6C[0x20];

extern const char lbl_12_rodata_1E8C[];

extern MwsPlayerInterface lbl_12_data_D38;

static inline void mwsfcre_FreeAll(MwsPlayer *player) {
    MwsLibraryWork *work;
    int index;
    void *memory;
    for (index = 0; index < 32; index++) {
        int reverse_index = 31 - index;
        memory = player->allocations[reverse_index];
        if (memory != 0) {
            if (player->arena == 0) {
                work = fn_12_38DBC();
                work->free_fn(work->allocator_object, memory);
            }
            player->allocation_count--;
            player->allocations[reverse_index] = 0;
        }
    }
}

void mwSfdDestroy(MwsPlayer *player) {
    if (player != 0) {
        fn_12_390E4(player);
        player->active = 0;
        fn_12_35484(player);
        if (player->sfx != 0)
            fn_12_35D74(player->sfx);
        if (player->loader != 0)
            fn_80057114(player->loader);
        if (player->stream != 0)
            fn_12_34F64(player->stream);
        if (player->input_sj != 0)
            player->input_sj->interface->destroy(player->input_sj);
        if (player->memory_sj != 0)
            player->memory_sj->interface->destroy(player->memory_sj);
        if (player->sfd != 0 && fn_12_2B6B0(player->sfd) != 0) {
            fn_12_38A0C(-0x132);
            MWSFSVM_Error(lbl_12_rodata_1E6C);
        }
        fn_12_3B15C(&player->sound);
        mwsfcre_FreeAll(player);
        if (player->allocation_count != 0)
            MWSFSVM_Error(lbl_12_rodata_1E8C);
        memset(player, 0, sizeof(*player));
        player->active = 0;
        player->interface = &lbl_12_data_D38;
    }
}
/* fzgx:end mwSfdDestroy */

/* fzgx:begin fn_12_36208 noprologue */
#include "types.h"

extern char lbl_12_rodata_1D88[];
extern void MWSFSVM_Error(const char *, ...);

typedef u32 (*FnAlloc)(void *, s32);
typedef void (*FnFree)(void *, u32);

typedef struct AllocCtx {
    u8 pad_0[0x28];
    FnAlloc alloc;
    FnFree free_fn;
    void *data;
} AllocCtx;

typedef struct MovieState {
    u8 pad_20[0x20];
    s32 state;
} MovieState;

typedef struct MovieModule {
    u8 pad_0[0x14];
    u32 field_14;
    u32 field_18;
    u8 pad_1c[0x90];
    u32 field_ac;
    u32 field_b0;
    u8 pad_b4[0x38];
    u32 field_ec;
    u32 field_f0;
    u8 pad_f4[0x64];
    u32 field_158;
    u32 field_15c;
    u32 field_160;
    u32 field_164;
    s32 count;
    u32 arr[32];
} MovieModule;

typedef struct { MovieModule *value; } ModRef;
typedef struct { const char *value; } MsgRef;

extern s32 fn_12_35DB4(u32, u32);
extern AllocCtx *fn_12_38DBC(void);
extern s32 fn_12_35548(MovieState *);

static inline FnFree fn_12_36208_read_pointer(AllocCtx * owner) { return owner->free_fn; }
#pragma opt_dead_assignments off
s32 fn_12_36208(MovieModule *m) {
    FnAlloc fzgx_live_;
    void * fzgx_live;
    MovieState *st;
    u32 p = 0;
    AllocCtx *ctx;
    u32 *slot_2;
    u32 *slot;
    u32 ptr2;
    u32 ptr;
    s32 off;
    s32 i = 0;
    const char *base = lbl_12_rodata_1D88;
    MsgRef msg;
    ModRef mm;
    const char * lab_t0;

    msg.value = base;
    mm.value = m;
    st = (MovieState *)((u8 *)mm.value + 0xc);

    off = fn_12_35DB4(mm.value->field_14, mm.value->field_18);

    if (mm.value->count >= 32) {
        lab_t0 = msg.value + 0x6c;
        MWSFSVM_Error(lab_t0);
        ptr = 0;
    } else if (off < 0) {
        ptr = 0;
    } else {
        if (mm.value->field_158 != 0) {
            if (mm.value->field_164 + off > mm.value->field_15c) {
                ptr = 0;
            } else {
                ptr = mm.value->field_160;
                mm.value->field_160 = ptr + off;
                mm.value->field_164 = mm.value->field_164 + off;
            }
        } else {
            ctx = fn_12_38DBC();
            fzgx_live_ = ctx->alloc;
            ptr = fzgx_live_((ctx->data), off);
        }
        if (ptr != 0) {
            mm.value->arr[mm.value->count] = ptr;
            mm.value->count++;
        }
    }

    if (ptr == 0) {
        lab_t0 = msg.value + 0x11c;
        MWSFSVM_Error(lab_t0);
        for (i = 0; i < 32; i++) {
            slot = &mm.value->arr[31 - i];
            p = *slot;
            if (((0) != (p))) {
                if (mm.value->field_158 == 0) {
                    ctx = fn_12_38DBC();
                    fzgx_live = ctx->data;
                    fn_12_36208_read_pointer(ctx)(fzgx_live, p);
                }
                mm.value->count--;
                *slot = 0;
            }
        }
        return -1;
    }

    mm.value->field_ac = ptr;
    mm.value->field_b0 = off;

    if (fn_12_35548(st) == 1) {
        if (mm.value->count >= 32) {
            lab_t0 = msg.value + 0x6c;
            MWSFSVM_Error(lab_t0);
            ptr2 = 0;
        } else {
            if (mm.value->field_158 != 0) {
                if (mm.value->field_164 + 0x20000 > mm.value->field_15c) {
                    ptr2 = 0;
                } else {
                    ptr2 = mm.value->field_160;
                    mm.value->field_160 = ptr2 + 0x20000;
                    mm.value->field_164 = mm.value->field_164 + 0x20000;
                }
            } else {
                ctx = fn_12_38DBC();
                fzgx_live = ctx->data;
                fzgx_live_ = ctx->alloc;
                ptr2 = fzgx_live_(fzgx_live, 0x20000);
            }
            if (ptr2 != 0) {
                mm.value->arr[mm.value->count] = ptr2;
                mm.value->count++;
            }
        }

        if (ptr2 == 0) {
            lab_t0 = msg.value + 0x140;
            MWSFSVM_Error(lab_t0);
            for (i = 0; i < 32; i++) {
                slot_2 = &mm.value->arr[31 - i];
                p = *slot_2;
                if (((0) != (p))) {
                    if (mm.value->field_158 == 0) {
                        ctx = fn_12_38DBC();
                        fzgx_live = ctx->data;
                        fn_12_36208_read_pointer(ctx)(fzgx_live, p);
                    }
                    mm.value->count--;
                    *slot_2 = 0;
                }
            }
            return -1;
        }

        mm.value->field_ec = ptr2;
        mm.value->field_f0 = 0x20000;
    } else {
        mm.value->field_ec = 0;
        mm.value->field_f0 = 0;
    }

    return 0;
}
#pragma opt_dead_assignments reset


/* fzgx:end fn_12_36208 */

/* fzgx:begin fn_12_364CC noprologue */
#include "types.h"
#pragma readonly_strings on

typedef struct SJ SJ;
typedef struct SJInterface {
    void *reserved[3];
    void (*destroy)(SJ *sj);
} SJInterface;
struct SJ {
    const SJInterface *interface;
};

typedef struct SfdHandle SfdHandle;
typedef struct LSC LSC;
typedef struct SFXHandle SFXHandle;
typedef struct ADXStream ADXStream;
typedef struct SfdTransportInterface SfdTransportInterface;

typedef struct SfdTransportSetup {
    const SfdTransportInterface *entries[9];
} SfdTransportSetup;

typedef struct MwsCreateParams {
    int file_type;
    int maximum_bps;
    int width;
    int height;
    int frame_count;
    int decoder_count;
    void *work;
    int work_size;
    int composition_mode;
    int buffer_format;
    int field_28;
    int field_2C;
} MwsCreateParams;

typedef struct MwsPictureUserConfig {
    void *buffer;
    int buffer_size;
    int element_size;
} MwsPictureUserConfig;

typedef struct MwsStHandle {
    int active;
    unsigned char reserved_004[8];
    SJ *stream;
    int element_id;
    void *backend;
} MwsStHandle;

typedef struct MwsPlayer {
    const void *interface;
    int active;
    int status;
    MwsCreateParams create;
    int playback_mode;
    SfdHandle *sfd;
    ADXStream *stream;
    void *transport;
    LSC *loader;
    int field_050;
    int field_054;
    int flow_limit;
    int field_05C;
    unsigned char reserved_060[8];
    int field_068;
    int field_06C;
    signed char concat_play;
    signed char concat_stopped;
    signed char paused;
    unsigned char field_073;
    int entry_count;
    unsigned char reserved_078[12];
    int field_084;
    unsigned char reserved_088[0x20];
    SFXHandle *sfx;
    void *composition_work;
    int composition_work_size;
    unsigned char reserved_0B4[0x20];
    MwsPictureUserConfig *picture_user;
    unsigned char reserved_0D8[0x10];
    SJ *additional_info_sj;
    unsigned char reserved_0EC[0x40];
    SJ *input_sj;
    void *input_buffer;
    int input_buffer_size;
    int input_buffer_extra_size;
    unsigned char reserved_13C[0x10];
    SJ *memory_sj;
    unsigned char reserved_150[8];
    void *arena;
    unsigned int arena_size;
    unsigned char *arena_cursor;
    unsigned int arena_used;
    int allocation_count;
    void *allocations[32];
    MwsStHandle sound;
    unsigned char reserved_204[0x24];
} MwsPlayer;

typedef void *(*MwsMallocFn)(void *object, long size);
typedef void (*MwsFreeFn)(void *object, void *memory);

typedef struct MwsLibraryWork {
    int field_00;
    float frame_rate;
    int video_frequency;
    int frame_pool;
    int field_10;
    unsigned char reserved_014[0x14];
    MwsMallocFn malloc_fn;
    MwsFreeFn free_fn;
    void *allocator_object;
    unsigned char reserved_034[0x34];
    MwsPlayer players[8];
} MwsLibraryWork;

typedef struct MW_PLY_OBJ {
    struct MwsPlayerInterface *interface;
} MW_PLY_OBJ;
typedef MW_PLY_OBJ *MWPLY;

typedef struct MwsPlayerInterface {
    void *reserved[3];
} MwsPlayerInterface;

extern void MWSFSVM_Error(const char *, ...);
extern MwsLibraryWork *fn_12_38DBC(void);
extern int fn_12_38A0C(int);
extern SfdHandle *fn_12_3763C(MwsPlayer *, MwsCreateParams *);
extern void fn_12_390E4(MwsPlayer *);
extern void fn_12_35484(MwsPlayer *);
extern void fn_12_35D74(SFXHandle *);
extern void fn_80057114(LSC *);
extern void fn_12_34F64(ADXStream *);
extern int fn_12_2B6B0(SfdHandle *);
extern void fn_12_3B15C(MwsStHandle *);
extern void *memset(void *, int, unsigned long);
extern int fn_12_38AE0(void);
extern int fn_12_2A434(SfdHandle *, void *, int, int);
extern int fn_12_2D888(SfdHandle *, int, int);
extern int fn_12_2A5C8(SfdHandle *, int, int);
extern SJ *fn_80058498(void *, int, int);
extern SJ *fn_80057B9C(void *, int);
extern int fn_12_2D500(SfdHandle *, int, void **);
extern void fn_12_3A968(MwsPlayer *, int);
extern void fn_12_3A960(MwsPlayer *, int);
extern ADXStream *fn_12_34F84(SJ *);
extern void fn_12_38DC8(MwsPlayer *);
extern LSC *fn_800571EC(SJ *);
extern void fn_8005710C(LSC *, ADXStream *);
extern int fn_12_36208(MwsPlayer *);
extern SFXHandle *fn_12_35D94(void *, int, int, int);
extern void fn_12_356E8(MwsPlayer *, int);
extern SJ *fn_12_354BC(MwsPlayer *);
extern int fn_12_35418(MwsPlayer *);
extern void fn_12_353FC(MwsPlayer *);

extern MwsPlayerInterface lbl_12_data_D38;
extern const SfdTransportInterface lbl_12_rodata_A18;
extern const SfdTransportInterface lbl_12_rodata_A80;
extern const SfdTransportInterface lbl_12_rodata_B58;
extern const SfdTransportInterface lbl_12_rodata_B90;
extern const SfdTransportInterface lbl_12_rodata_BD8;
extern const SfdTransportInterface lbl_12_rodata_E90;
extern const SfdTransportInterface lbl_12_rodata_EC8;

static const SfdTransportSetup lbl_12_rodata_1D88 = {{
    &lbl_12_rodata_B58, &lbl_12_rodata_B90, &lbl_12_rodata_BD8, &lbl_12_rodata_A18,
    0, 0, &lbl_12_rodata_EC8, &lbl_12_rodata_A80, &lbl_12_rodata_E90}};
static const SfdTransportSetup lbl_12_rodata_1DAC = {{
    &lbl_12_rodata_B58, 0, &lbl_12_rodata_BD8, 0, 0, 0, &lbl_12_rodata_EC8, 0, 0}};
static const SfdTransportSetup lbl_12_rodata_1DD0 = {{
    &lbl_12_rodata_B58, &lbl_12_rodata_B90, &lbl_12_rodata_BD8, 0, 0, 0,
    &lbl_12_rodata_EC8, 0, &lbl_12_rodata_E90}};
static const char lbl_12_rodata_1DF4[] = "E2053001 MWSFD_Malloc: cnt over.";
static const char lbl_12_rodata_1E18[0x28] = "E204161: mwPlyGetHdrInf(): NULL pointer";
static const char lbl_12_rodata_1E40[] = "E204162: mwPlyGetHdrInf(): bufsize error";
static const char lbl_12_rodata_1E6C[0x20] = "E20010703E MWSFCRE_DestroySfd: ";
static const char lbl_12_rodata_1E8C[] = "E2053005: forgot free.";
static const char lbl_12_rodata_1E8C__fzgx_offset_18[0x24] = "E2053003: not enough work: sfx_wk";
static const char lbl_12_rodata_1E8C__fzgx_offset_3C[0x28] = "E2053004: not enough work: ainfsj_buf";
static const char lbl_12_rodata_1E8C__fzgx_offset_64[0x24] = "E3012102: Buffer format is invalid.";
static const char lbl_12_rodata_1E8C__fzgx_offset_88[] = "E1122612 mwPlyCreateSofdec : cprm is NULL.";
static const char lbl_12_rodata_1E8C__fzgx_offset_B4[] = "W2000 mwPlyCreateSofdec:can't create handle";
static const char lbl_12_rodata_1E8C__fzgx_offset_E0[] = "E2053006 mwPlyCreateSofdec: Didn't set malloc/free func.";
static const char lbl_12_rodata_1E8C__fzgx_offset_11C[] = "E2012 mwPlyCreate:can't create SFD";
static const char lbl_12_rodata_1E8C__fzgx_offset_140[] = "E02120501: Internal Error: mwsfcre_AttachPicUsrBuf().";
static const char lbl_12_rodata_1E8C__fzgx_offset_178[] = "E02120502: mwsfcre_AttachPicUsrBuf(): usrdatbuf is short.";

#pragma section code_type ".fzgxpool"
static void mwsfdcre_layout(void) {
    const void *volatile object; /* fzgx-allow: S2 readonly object first-access order */
    object = &lbl_12_rodata_1D88;
    object = &lbl_12_rodata_1DAC;
    object = &lbl_12_rodata_1DD0;
    object = lbl_12_rodata_1DF4;
    object = lbl_12_rodata_1E18;
    object = lbl_12_rodata_1E40;
    object = lbl_12_rodata_1E6C;
    object = lbl_12_rodata_1E8C;
    object = lbl_12_rodata_1E8C__fzgx_offset_18;
    object = lbl_12_rodata_1E8C__fzgx_offset_3C;
    object = lbl_12_rodata_1E8C__fzgx_offset_64;
    object = lbl_12_rodata_1E8C__fzgx_offset_88;
    object = lbl_12_rodata_1E8C__fzgx_offset_B4;
    object = lbl_12_rodata_1E8C__fzgx_offset_E0;
    object = lbl_12_rodata_1E8C__fzgx_offset_11C;
    object = lbl_12_rodata_1E8C__fzgx_offset_140;
    object = lbl_12_rodata_1E8C__fzgx_offset_178;
}
#pragma section code_type ".text"

static inline void mwsfcre_FreeAll(MwsPlayer *player) {
    MwsLibraryWork *work;
    int index;
    void *memory;
    for (index = 0; index < 32; index++) {
        int reverse_index = 31 - index;
        memory = player->allocations[reverse_index];
        if (memory != 0) {
            if (player->arena == 0) {
                work = fn_12_38DBC();
                work->free_fn(work->allocator_object, memory);
            }
            player->allocation_count--;
            player->allocations[reverse_index] = 0;
        }
    }
}

static inline void MWSFCRE_DestroySfd(MwsPlayer *player) {
    if (player->loader != 0) fn_80057114(player->loader);
    if (player->stream != 0) fn_12_34F64(player->stream);
    if (player->input_sj != 0)
        player->input_sj->interface->destroy(player->input_sj);
    if (player->memory_sj != 0)
        player->memory_sj->interface->destroy(player->memory_sj);
    if (player->sfd != 0) {
        if (fn_12_2B6B0(player->sfd) != 0) {
            fn_12_38A0C(-0x132);
            MWSFSVM_Error(lbl_12_rodata_1E6C);
        }
    }
    fn_12_3B15C(&player->sound);
    mwsfcre_FreeAll(player);
    if (player->allocation_count != 0) MWSFSVM_Error(lbl_12_rodata_1E8C);
    memset(player, 0, sizeof(*player));
    player->active = 0;
    player->interface = &lbl_12_data_D38;
}

static inline void mwSfdDestroy(MWPLY handle) {
    MwsPlayer *player = (MwsPlayer *)handle;
    if (player == 0) {
        return;
    }
    fn_12_390E4(player);
    player->active = 0;
    fn_12_35484(player);
    if (player->sfx != 0) fn_12_35D74(player->sfx);
    MWSFCRE_DestroySfd(player);
}

static inline int mwsfcre_IsValidBufFmt(const MwsCreateParams *params) {
    int valid = 1;
    if (params->buffer_format != 0 && params->buffer_format != 3) {
        MWSFSVM_Error(lbl_12_rodata_1E8C__fzgx_offset_64);
        valid = 0;
    }
    return valid;
}

static inline int mwsfcre_ChkMallocFn(const MwsCreateParams *params) {
    MwsLibraryWork *work = fn_12_38DBC();
    int result = 0;
    if (params->work == 0) {
        if (work->malloc_fn == 0) result = -1;
        if (work->free_fn == 0) result = -1;
    }
    return result;
}

static inline void mwsfcre_InitCompoWork(MwsPlayer *player, const MwsCreateParams *params) {
    long index;
    player->arena = params->work;
    player->arena_size = params->work_size;
    player->arena_cursor = params->work;
    player->arena_used = 0;
    player->allocation_count = 0;
    for (index = 0; index < 32; index++) {
        player->allocations[index] = 0;
    }
}

static inline void mwsfcre_AttachPictureUser(MwsPlayer *player, const char *short_error) {
    MwsPictureUserConfig *config = player->picture_user;
    void *buffer;
    int element_size;
    int skip_count;
    if (config == 0) {
        MWSFSVM_Error(lbl_12_rodata_1E8C__fzgx_offset_140);
    } else {
        skip_count = player->create.frame_count;
        element_size = config->element_size;
        buffer = config->buffer;
        if (config->buffer_size < (skip_count + 3) * element_size) {
            MWSFSVM_Error(short_error);
        } else if (fn_12_38AE0() == 1) {
            fn_12_2A434(player->sfd, buffer, skip_count + 3, element_size);
        }
    }
}

static inline void mwsfcre_SetSfdCond(MwsPlayer *player, MwsLibraryWork *work) {
    double frame_time;
    int frames;
    int pool;
    int frequency;
    SfdHandle *sfd;

    sfd = player->sfd;
    pool = work->frame_pool;
    frequency = work->video_frequency;
    fn_12_2D888(sfd, 8, 0);
    fn_12_2D888(sfd, 1, 1);
    fn_12_2D888(sfd, 0, 0);
    fn_12_2D888(sfd, 0x17, 4);
    frame_time = 0.5 + (double)(frequency * pool * 1000);
    if ((double)(int)frame_time > frame_time) frames = (int)frame_time - 1;
    else frames = (int)frame_time;
    fn_12_2D888(sfd, 0x2D, frames);
    fn_12_2D888(sfd, 0x2C, frames);
    fn_12_2D888(sfd, 0x2A, frames);
    fn_12_2D888(sfd, 0xF, 2);
    fn_12_2D888(sfd, 0x33, 0);
    fn_12_2D888(sfd, 0xE, 0);
    fn_12_2D888(sfd, 0x1C, 0);
    fn_12_2A5C8(sfd, 5, 0);
}

MwsPlayer *fn_12_364CC(MwsCreateParams *params) {
    MwsLibraryWork *work;
    MwsPlayer *player;
    SfdHandle *sfd;
    SFXHandle *sfx;
    int flow_limit;
    int index;
    int sector_count;
    int maximum_bps;
    int file_type;

    if (params == 0) {
        MWSFSVM_Error(lbl_12_rodata_1E8C__fzgx_offset_88);
        return 0;
    }
    if (mwsfcre_IsValidBufFmt(params) != 1) {
        return 0;
    }
    work = fn_12_38DBC();
    for (index = 0; index < 8; index++) {
        player = &work->players[index];
        if (player->active == 0) break;
    }
    if (index == 8) {
        fn_12_38A0C(-0xB);
        MWSFSVM_Error(lbl_12_rodata_1E8C__fzgx_offset_B4);
        return 0;
    }
    if (mwsfcre_ChkMallocFn(params) == -1) {
        MWSFSVM_Error(lbl_12_rodata_1E8C__fzgx_offset_E0);
        return 0;
    }

    if (player != 0) memset(player, 0, sizeof(*player));
    mwsfcre_InitCompoWork(player, params);

    sfd = fn_12_3763C(player, params);
    player->sfd = sfd;
    if (player->sfd == 0) {
        MWSFSVM_Error(lbl_12_rodata_1E8C__fzgx_offset_11C);
        mwSfdDestroy((MWPLY)player);
        return 0;
    }
    mwsfcre_AttachPictureUser(player, lbl_12_rodata_1E8C__fzgx_offset_178);

    sector_count = params->decoder_count;
    file_type = params->file_type;
    maximum_bps = params->maximum_bps;
    if (sector_count <= 0) {
        sector_count = 1;
    }
    if (file_type == 2) {
        flow_limit = sector_count * (maximum_bps / 8 / 0x800 * 0x800);
    } else if (file_type == 3) {
        flow_limit = sector_count * (maximum_bps / 8 / 0x800 * 0x800);
    } else {
        flow_limit = sector_count * (maximum_bps / 8 / 0x800 * 0x800);
    }
    mwsfcre_SetSfdCond(player, work);

    player->input_sj = fn_80058498(player->input_buffer, player->input_buffer_size,
                                   player->input_buffer_extra_size);
    if (player->input_sj == 0) {
        MWSFSVM_Error("E2013 mwPlyCreate:can't create SJ");
        mwSfdDestroy((MWPLY)player);
        return 0;
    }
    player->memory_sj = fn_80057B9C(0, 0);
    if (player->memory_sj == 0) {
        MWSFSVM_Error("E2020 mwPlyCreate:can't create SJ");
        mwSfdDestroy((MWPLY)player);
        return 0;
    }
    player->interface = &lbl_12_data_D38;
    player->flow_limit = flow_limit;
    player->create = *params;
    player->playback_mode = 1;
    player->field_068 = 0;
    player->status = 0;
    player->field_050 = params->composition_mode;
    if (fn_12_2D500(sfd, 3, &player->transport) != 0) player->transport = 0;
    player->field_06C = 1;
    player->concat_play = 0;
    player->concat_stopped = 0;
    player->paused = 0;
    player->field_073 = 0;
    player->field_05C = 0;
    fn_12_3A968(player, 0);
    fn_12_3A960(player, 0);
    player->field_054 = 0;
    player->field_084 = 0;

    player->stream = fn_12_34F84(player->input_sj);
    if (player->stream == 0) {
        mwSfdDestroy((MWPLY)player);
        return 0;
    }
    fn_12_38DC8(player);
    player->loader = fn_800571EC(player->input_sj);
    player->entry_count = 0;
    fn_8005710C(player->loader, player->stream);
    if (fn_12_36208(player) == -1) {
        mwSfdDestroy((MWPLY)player);
        return 0;
    }
    sfx = fn_12_35D94(player->composition_work, player->composition_work_size,
                      params->width, params->height);
    if (sfx == 0) {
        MWSFSVM_Error("E201185: can't create SfxHn");
        mwSfdDestroy((MWPLY)player);
        return 0;
    }
    player->sfx = sfx;
    fn_12_356E8(player, player->create.composition_mode);
    player->additional_info_sj = fn_12_354BC(player);
    if (fn_12_35418(player) != 0) {
        MWSFSVM_Error("E201212 mwPlyCreate: can't set AddInfSJ");
        mwSfdDestroy((MWPLY)player);
        return 0;
    }
    fn_12_353FC(player);
    player->active = 1;
    return player;
}
/* fzgx:end fn_12_364CC */

/* fzgx:begin MWSFCRE_ResetSfdHn noprologue */

#include "types.h"

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

typedef struct LSC LSC;

typedef struct SFXHandle SFXHandle;

typedef struct MwsPlayer MwsPlayer;

typedef struct MwsStHandle {
    int active;
    unsigned char reserved_004[8];
    SJ *stream;
    int element_id;
    void *backend;
} MwsStHandle;

typedef struct MwsPictureUserConfig {
    void *buffer;
    int buffer_size;
    int element_size;
} MwsPictureUserConfig;

struct MwsPlayer {
    const void *interface;
    int active;
    int status;
    int file_type;
    int maximum_bps;
    int width;
    int height;
    int frame_count;
    int decoder_count;
    void *create_work;
    int create_work_size;
    int composition_mode;
    int buffer_format;
    int create_field_28;
    int create_field_2C;
    int playback_mode;
    SfdHandle *sfd;
    void *stream;
    void *transport;
    LSC *loader;
    int field_050;
    int field_054;
    int field_058;
    int flow_limit;
    int field_060;
    unsigned char reserved_064[8];
    int field_06C;
    int field_070;
    signed char concat_play;
    signed char concat_stopped;
    signed char paused;
    unsigned char field_077;
    int entry_count;
    unsigned char reserved_07C[12];
    int field_088;
    unsigned char reserved_08C[0x20];
    SFXHandle *sfx;
    void *composition_work;
    int composition_work_size;
    unsigned char reserved_0B8[4];
    MwsPictureUserConfig internal_picture_user;
    unsigned char reserved_170[12];
    MwsPictureUserConfig *picture_user;
    void *picture_user_work;
    int picture_user_header_size;
    int picture_user_write;
    int picture_user_read;
    SJ *additional_info_sj;
    void *additional_info_buffer;
    int additional_info_buffer_size;
    unsigned char reserved_19C[0x1C];
    char *filename;
    int filename_capacity;
    int start_requested;
    int file_offset;
    int file_length;
    int file_end_position;
    SJ *supply_sj;
    SJ *input_sj;
    void *input_buffer;
    int input_buffer_size;
    int input_buffer_extra_size;
    int supply_mode;
    void *supply_buffer;
    int supply_buffer_size;
    int supply_buffer_extra_size;
    SJ *memory_sj;
    void *memory_buffer;
    int memory_buffer_size;
    void *arena;
    unsigned int arena_size;
    unsigned char *arena_cursor;
    unsigned int arena_used;
    int allocation_count;
    void *allocations[32];
    MwsStHandle sound;
    unsigned char reserved_2AC[8];
    int sound_state;
};

int fn_12_249BC(SfdHandle *handle, SfdErrorCallback callback, SfdCallbackObject object);

int fn_12_2B358(SfdHandle *handle);

extern int fn_12_38A0C(int);

extern void fn_12_388C4(SfdCallbackObject, int);

extern void MWSFSVM_Error(const char *, ...);

extern int fn_12_38AE0(void);

extern int fn_12_2A434(SfdHandle *, void *, int, int);

struct mwsfdcre____rodata_0 {
    unsigned char padding_0[580];
    const char picture_user_internal_error[54];
    unsigned char padding_670[2];
    const char create_picture_short_message[58];
    unsigned char padding_730[162];
    const char reset_stop_failed[49];
    unsigned char padding_937[3];
    const char reset_error_callback_failed[53];
};
extern struct mwsfdcre____rodata_0 lbl_12_rodata_1D88;

int MWSFCRE_ResetSfdHn(MwsPlayer *player) {
    struct mwsfdcre____rodata_0 *data = &lbl_12_rodata_1D88;

    MwsPictureUserConfig *config;
    int frame_count;
    int element_size;
    void *buffer;
    SfdHandle *sfd;
    sfd = player->sfd;
    if (fn_12_2B358(sfd) != 0) {
        MWSFSVM_Error((data->reset_stop_failed));
        return -1;
    }
    if (fn_12_249BC(sfd, fn_12_388C4, (SfdCallbackObject)player) != 0) {
        fn_12_38A0C(-0x12F);
        MWSFSVM_Error((data->reset_error_callback_failed));
        return -1;
    }
    config = player->picture_user;
    if (config == 0) {
        MWSFSVM_Error((data->picture_user_internal_error));
    } else {
        frame_count = player->frame_count;
        element_size = config->element_size;
        buffer = config->buffer;
        if (config->buffer_size < (frame_count + 3) * element_size) {
            MWSFSVM_Error((data->create_picture_short_message));
        } else if (fn_12_38AE0() == 1) {
            fn_12_2A434(player->sfd, buffer, frame_count + 3, element_size);
        }
    }
    return 0;
}
/* fzgx:end MWSFCRE_ResetSfdHn */

/* fzgx:begin fn_12_3763C noprologue */
#include "types.h"
#pragma readonly_strings on

typedef struct SJ SJ;
typedef struct SJInterface {
    void *reserved[3];
    void (*destroy)(SJ *sj);
} SJInterface;
struct SJ {
    const SJInterface *interface;
};

typedef struct SfdHandle SfdHandle;
typedef struct LSC LSC;
typedef struct SFXHandle SFXHandle;
typedef struct ADXStream ADXStream;
typedef struct SfdTransportInterface SfdTransportInterface;

typedef struct SfdTransportSetup {
    const SfdTransportInterface *entries[9];
} SfdTransportSetup;

typedef struct MwsCreateParams {
    int file_type;
    int maximum_bps;
    int width;
    int height;
    int frame_count;
    int decoder_count;
    void *work;
    int work_size;
    int composition_mode;
    int buffer_format;
    int field_28;
    int field_2C;
} MwsCreateParams;

typedef struct MwsPictureUserConfig {
    void *buffer;
    int buffer_size;
    int element_size;
} MwsPictureUserConfig;

typedef struct MwsStHandle {
    int active;
    unsigned char reserved_004[8];
    SJ *stream;
    int element_id;
    void *backend;
} MwsStHandle;

typedef struct MwsPlayer {
    const void *interface;
    int active;
    int status;
    MwsCreateParams create;
    int playback_mode;
    SfdHandle *sfd;
    ADXStream *stream;
    void *transport;
    LSC *loader;
    int field_050;
    int field_054;
    int flow_limit;
    int field_05C;
    unsigned char reserved_060[8];
    int field_068;
    int field_06C;
    signed char concat_play;
    signed char concat_stopped;
    signed char paused;
    unsigned char field_073;
    int entry_count;
    unsigned char reserved_078[12];
    int field_084;
    unsigned char reserved_088[0x20];
    SFXHandle *sfx;
    void *composition_work;
    int composition_work_size;
    unsigned char reserved_0B4[8];
    MwsPictureUserConfig internal_picture_user;
    unsigned char reserved_0C8[12];
    MwsPictureUserConfig *picture_user;
    void *picture_user_work;
    int picture_user_header_size;
    int picture_user_write;
    int picture_user_read;
    SJ *additional_info_sj;
    unsigned char reserved_0EC[0x24];
    char *filename;
    int filename_capacity;
    unsigned char reserved_118[0x14];
    SJ *input_sj;
    void *input_buffer;
    int input_buffer_size;
    int input_buffer_extra_size;
    unsigned char reserved_13C[0x10];
    SJ *memory_sj;
    unsigned char reserved_150[8];
    void *arena;
    unsigned int arena_size;
    unsigned char *arena_cursor;
    unsigned int arena_used;
    int allocation_count;
    void *allocations[32];
    MwsStHandle sound;
    unsigned char reserved_204[0x24];
} MwsPlayer;

typedef void *(*MwsMallocFn)(void *object, long size);
typedef void (*MwsFreeFn)(void *object, void *memory);

typedef struct MwsLibraryWork {
    int field_00;
    float frame_rate;
    int video_frequency;
    int frame_pool;
    int field_10;
    unsigned char reserved_014[0x14];
    MwsMallocFn malloc_fn;
    MwsFreeFn free_fn;
    void *allocator_object;
    unsigned char reserved_034[0x34];
    MwsPlayer players[8];
} MwsLibraryWork;

typedef struct MW_PLY_OBJ {
    struct MwsPlayerInterface *interface;
} MW_PLY_OBJ;
typedef MW_PLY_OBJ *MWPLY;

typedef struct MwsPlayerInterface {
    void *reserved[3];
} MwsPlayerInterface;

extern void MWSFSVM_Error(const char *, ...);
extern MwsLibraryWork *fn_12_38DBC(void);
extern int fn_12_38A0C(int);
extern void fn_12_390E4(MwsPlayer *);
extern void fn_12_35484(MwsPlayer *);
extern void fn_12_35D74(SFXHandle *);
extern void fn_80057114(LSC *);
extern void fn_12_34F64(ADXStream *);
extern int fn_12_2B6B0(SfdHandle *);
extern void fn_12_3B15C(MwsStHandle *);
extern void *memset(void *, int, unsigned long);
extern int fn_12_38AE0(void);
extern int fn_12_2A434(SfdHandle *, void *, int, int);
extern int fn_12_2D888(SfdHandle *, int, int);
extern int fn_12_2A5C8(SfdHandle *, int, int);
extern SJ *fn_80058498(void *, int, int);
extern SJ *fn_80057B9C(void *, int);
extern int fn_12_2D500(SfdHandle *, int, void **);
extern void fn_12_3A968(MwsPlayer *, int);
extern void fn_12_3A960(MwsPlayer *, int);
extern ADXStream *fn_12_34F84(SJ *);
extern void fn_12_38DC8(MwsPlayer *);
extern LSC *fn_800571EC(SJ *);
extern void fn_8005710C(LSC *, ADXStream *);
extern int fn_12_36208(MwsPlayer *);
extern SFXHandle *fn_12_35D94(void *, int, int, int);
extern void fn_12_356E8(MwsPlayer *, int);
extern SJ *fn_12_354BC(MwsPlayer *);
extern int fn_12_35418(MwsPlayer *);
extern void fn_12_353FC(MwsPlayer *);

extern const SfdTransportInterface lbl_12_rodata_A18;
extern const SfdTransportInterface lbl_12_rodata_A80;
extern const SfdTransportInterface lbl_12_rodata_B58;
extern const SfdTransportInterface lbl_12_rodata_B90;
extern const SfdTransportInterface lbl_12_rodata_BD8;
extern const SfdTransportInterface lbl_12_rodata_E90;
extern const SfdTransportInterface lbl_12_rodata_EC8;

static const SfdTransportSetup lbl_12_rodata_1D88 = {{
    &lbl_12_rodata_B58, &lbl_12_rodata_B90, &lbl_12_rodata_BD8, &lbl_12_rodata_A18,
    0, 0, &lbl_12_rodata_EC8, &lbl_12_rodata_A80, &lbl_12_rodata_E90}};
static const SfdTransportSetup lbl_12_rodata_1DAC = {{
    &lbl_12_rodata_B58, 0, &lbl_12_rodata_BD8, 0, 0, 0, &lbl_12_rodata_EC8, 0, 0}};
static const SfdTransportSetup lbl_12_rodata_1DD0 = {{
    &lbl_12_rodata_B58, &lbl_12_rodata_B90, &lbl_12_rodata_BD8, 0, 0, 0,
    &lbl_12_rodata_EC8, 0, &lbl_12_rodata_E90}};
static const char lbl_12_rodata_1DF4[] = "E2053001 MWSFD_Malloc: cnt over.";
static const char lbl_12_rodata_1E18[0x28] = "E204161: mwPlyGetHdrInf(): NULL pointer";
static const char lbl_12_rodata_1E40[] = "E204162: mwPlyGetHdrInf(): bufsize error";
static const char lbl_12_rodata_1E6C[0x20] = "E20010703E MWSFCRE_DestroySfd: ";
static const char lbl_12_rodata_1E8C[] = "E2053005: forgot free.";
static const char lbl_12_rodata_1E8C__fzgx_offset_18[0x24] = "E2053003: not enough work: sfx_wk";
static const char lbl_12_rodata_1E8C__fzgx_offset_3C[0x28] = "E2053004: not enough work: ainfsj_buf";
static const char lbl_12_rodata_1E8C__fzgx_offset_64[0x24] = "E3012102: Buffer format is invalid.";
static const char lbl_12_rodata_1E8C__fzgx_offset_88[] = "E1122612 mwPlyCreateSofdec : cprm is NULL.";
static const char lbl_12_rodata_1E8C__fzgx_offset_B4[] = "W2000 mwPlyCreateSofdec:can't create handle";
static const char lbl_12_rodata_1E8C__fzgx_offset_E0[] = "E2053006 mwPlyCreateSofdec: Didn't set malloc/free func.";
static const char lbl_12_rodata_1E8C__fzgx_offset_11C[] = "E2012 mwPlyCreate:can't create SFD";
static const char lbl_12_rodata_1E8C__fzgx_offset_140[] = "E02120501: Internal Error: mwsfcre_AttachPicUsrBuf().";
static const char lbl_12_rodata_1E8C__fzgx_offset_178[] = "E02120502: mwsfcre_AttachPicUsrBuf(): usrdatbuf is short.";


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

typedef struct SfdMpvParameters {
    s32 chroma_width;
    s32 chroma_height;
    s32 width;
    s32 height;
    s32 reference_buffer;
    s32 maximum_width;
    int maximum_height;
    s32 frame_count;
    s32 frame_buffer;
} SfdMpvParameters;

typedef struct SfdAdxtParameters {
    int stream_buffer_size;
    int stream_buffer_extra_size;
    void *stream_buffer;
    int maximum_channels;
    int decoder_work_size;
    int decoder_buffer_size;
    void *decoder_buffer;
} SfdAdxtParameters;

typedef struct MwsReferenceBuffers { void *buffers[2]; } MwsReferenceBuffers;

typedef struct MwsPictureUserWork {
    unsigned char header[0x40];
    unsigned char element_buffer[0x7C0];
} MwsPictureUserWork;


extern void fn_12_3ABE0(void);
extern void fn_12_3AA58(void);
extern void mwSfdDestroy(void);
extern void fn_12_39930(void);
extern void fn_12_3901C(void);
extern void fn_12_3A264(void);
extern void fn_12_39F48(void);
extern void mwSfdPause(void);
extern void fn_12_39EF8(void);
extern void fn_12_39EA4(void);
extern void fn_12_39E54(void);
extern void fn_12_39E00(void);
extern void fn_12_3916C(void);
extern void fn_12_393F0(void);

typedef struct MwsPlayerInterfaceTable {
    void *reserved[3];
    void (*functions[14])(void);
} MwsPlayerInterfaceTable;

static MwsPlayerInterfaceTable lbl_12_data_D38 = {
    {0, 0, 0},
    {fn_12_3ABE0, fn_12_3AA58, mwSfdDestroy, fn_12_39930, fn_12_3901C, fn_12_3A264, fn_12_39F48,
     mwSfdPause, fn_12_39EF8, fn_12_39EA4, fn_12_39E54, fn_12_39E00, fn_12_3916C, fn_12_393F0}};
static SfdCreateConfig lbl_12_data_D38__fzgx_offset_44 = {
    {&lbl_12_rodata_1D88, 0, {0x10000, 0x50800, 0x12000, 0, 0, 0, 0}, 0, 0x800},
    3, 0x2D0, 0x240, 3, 0, 0};
static SfdCreateConfig lbl_12_data_D38__fzgx_offset_88 = {
    {&lbl_12_rodata_1DAC, 0, {0x10000, 0x50800, 0x12000, 0, 0, 0, 0}, 0, 0x800},
    3, 0x2D0, 0x240, 3, 0, 0};
static SfdCreateConfig lbl_12_data_D38__fzgx_offset_CC = {
    {&lbl_12_rodata_1DD0, 0, {0x10000, 0x50800, 0x12000, 0, 0, 0, 0}, 0, 0x800},
    3, 0x2D0, 0x240, 3, 0, 0};
static SfdMpvParameters lbl_12_data_D38__fzgx_offset_110 = {0xC0, 0xF0, 0x160, 0x1E0, 0, 0x160, 0x1E0, 4, 0};
static SfdAdxtParameters lbl_12_data_D38__fzgx_offset_134 = {0x5DCC, 0x120, 0, 2, 0xBB80, 0xC1C0, 0};
static long lbl_12_data_D38__fzgx_offset_150 = 0x800;

static int lbl_12_bss_1B9B0;
static int lbl_12_bss_1B9B0__fzgx_offset_4;
static int lbl_12_bss_1B9B0__fzgx_offset_8;
static int lbl_12_bss_1B9B0__fzgx_offset_C;
static int lbl_12_bss_1B9B0__fzgx_offset_10;
static int lbl_12_bss_1B9B0__fzgx_offset_14;
static long lbl_12_bss_1B9B0__fzgx_offset_18;
static int lbl_12_bss_1B9B0__fzgx_offset_1C;
static unsigned char *lbl_12_bss_1B9B0__fzgx_offset_20;

extern int fn_12_38340(MwsPlayer *, MwsCreateParams *, MwsReferenceBuffers *);
extern void fn_12_2A6FC(SfdMpvParameters *, void **, void **);
extern void fn_12_2145C(SfdAdxtParameters *);
extern SfdHandle *fn_12_2BCF4(SfdCreateConfig *, int);
extern int fn_12_249BC(SfdHandle *, void (*)(int, int), MwsPlayer *);
extern void fn_12_388C4(int, int);

static const u32 lbl_12_rodata_1E8C__fzgx_offset_1B4[2] = {0x3FE00000, 0}; /* 0.5 */
static const char lbl_12_rodata_1E8C__fzgx_offset_1BC[] = "E2013 mwPlyCreate:can't create SJ";
static const char lbl_12_rodata_1E8C__fzgx_offset_1E0[] = "E2020 mwPlyCreate:can't create SJ";
static const char lbl_12_rodata_1E8C__fzgx_offset_204[] = "E201185: can't create SfxHn";
static const char lbl_12_rodata_1E8C__fzgx_offset_220[] = "E201212 mwPlyCreate: can't set AddInfSJ";
static const u32 lbl_12_rodata_1E8C__fzgx_offset_248[3] = {0, 0x43300000, 0x80000000}; /* pad + int-to-double bias */
static const char lbl_12_rodata_1E8C__fzgx_offset_254[] = "E0203261: MWSFCRE_ResetSfdHn: SFD_Stop() failed.";
static const char lbl_12_rodata_1E8C__fzgx_offset_288[] = "E0203262: MWSFCRE_ResetSfdHn: SFD_SetErrFn() failed.";
static const char lbl_12_rodata_1E8C__fzgx_offset_2C0[0x38] = "E02120503: mwPlyAttachPicUsrBuf(): bufsize is short.";
static const char lbl_12_rodata_2184[0x28] = "E206011: MwsfdCrePrm: illigal buffmt.";
static const char lbl_12_rodata_2184__fzgx_offset_28[0x1C] = "E2053002: not enough work";
static const char lbl_12_rodata_2184__fzgx_offset_44[0x2C] = "E20010703C mwPlyCreateSofdec: create error";
static const char lbl_12_rodata_2184__fzgx_offset_70[0x28] = "E20010703D mwPlyCreateSofdec: set errcb";

#pragma section code_type ".fzgxpool"
static void mwsfdcre_layout(void) {
    const void *volatile object; /* fzgx-allow: S2 readonly object first-access order */
    object = &lbl_12_rodata_1D88;
    object = &lbl_12_rodata_1DAC;
    object = &lbl_12_rodata_1DD0;
    object = lbl_12_rodata_1DF4;
    object = lbl_12_rodata_1E18;
    object = lbl_12_rodata_1E40;
    object = lbl_12_rodata_1E6C;
    object = lbl_12_rodata_1E8C;
    object = lbl_12_rodata_1E8C__fzgx_offset_18;
    object = lbl_12_rodata_1E8C__fzgx_offset_3C;
    object = lbl_12_rodata_1E8C__fzgx_offset_64;
    object = lbl_12_rodata_1E8C__fzgx_offset_88;
    object = lbl_12_rodata_1E8C__fzgx_offset_B4;
    object = lbl_12_rodata_1E8C__fzgx_offset_E0;
    object = lbl_12_rodata_1E8C__fzgx_offset_11C;
    object = lbl_12_rodata_1E8C__fzgx_offset_140;
    object = lbl_12_rodata_1E8C__fzgx_offset_178;
    object = lbl_12_rodata_1E8C__fzgx_offset_1B4;
    object = lbl_12_rodata_1E8C__fzgx_offset_1BC;
    object = lbl_12_rodata_1E8C__fzgx_offset_1E0;
    object = lbl_12_rodata_1E8C__fzgx_offset_204;
    object = lbl_12_rodata_1E8C__fzgx_offset_220;
    object = lbl_12_rodata_1E8C__fzgx_offset_248;
    object = lbl_12_rodata_1E8C__fzgx_offset_254;
    object = lbl_12_rodata_1E8C__fzgx_offset_288;
    object = lbl_12_rodata_1E8C__fzgx_offset_2C0;
    object = lbl_12_rodata_2184;
    object = lbl_12_rodata_2184__fzgx_offset_28;
    object = lbl_12_rodata_2184__fzgx_offset_44;
    object = lbl_12_rodata_2184__fzgx_offset_70;
    object = &lbl_12_bss_1B9B0;
    object = &lbl_12_bss_1B9B0__fzgx_offset_4;
    object = &lbl_12_bss_1B9B0__fzgx_offset_8;
    object = &lbl_12_bss_1B9B0__fzgx_offset_C;
    object = &lbl_12_bss_1B9B0__fzgx_offset_10;
    object = &lbl_12_bss_1B9B0__fzgx_offset_14;
    object = &lbl_12_bss_1B9B0__fzgx_offset_18;
    object = &lbl_12_bss_1B9B0__fzgx_offset_1C;
    object = &lbl_12_bss_1B9B0__fzgx_offset_20;
    object = &lbl_12_data_D38;
    object = &lbl_12_data_D38__fzgx_offset_44;
    object = &lbl_12_data_D38__fzgx_offset_88;
    object = &lbl_12_data_D38__fzgx_offset_CC;
    object = &lbl_12_data_D38__fzgx_offset_110;
    object = &lbl_12_data_D38__fzgx_offset_134;
    object = &lbl_12_data_D38__fzgx_offset_150;
}
#pragma section code_type ".text"

static inline void *mwsfcre_Alloc(MwsPlayer *player, long size) {
    MwsLibraryWork *work;
    void *memory;
    if (player->allocation_count >= 32) {
        MWSFSVM_Error(lbl_12_rodata_1DF4);
        return 0;
    }
    if (size < 0) return 0;
    if (player->arena != 0) {
        if (player->arena_used + size > player->arena_size) {
            memory = 0;
        } else {
            memory = player->arena_cursor;
            player->arena_cursor += size;
            player->arena_used += size;
        }
    } else {
        work = fn_12_38DBC();
        memory = work->malloc_fn(work->allocator_object, size);
    }
    if (memory != 0) {
        player->allocations[player->allocation_count] = memory;
        player->allocation_count++;
    }
    return memory;
}

static inline void mwsfcre_FreeAll(MwsPlayer *player) {
    MwsLibraryWork *work;
    int index;
    void *memory;
    for (index = 0; index < 32; index++) {
        int reverse_index = 31 - index;
        memory = player->allocations[reverse_index];
        if (memory != 0) {
            if (player->arena == 0) {
                work = fn_12_38DBC();
                work->free_fn(work->allocator_object, memory);
            }
            player->allocation_count--;
            player->allocations[reverse_index] = 0;
        }
    }
}

static inline int mwsfcre_CalcFrameSize(int source_width, int source_height) {
    int height;
    int width;
    int luma_size;
    int chroma_size;

    width = (source_width + 15) / 16 * 16;
    height = (source_height + 15) / 16 * 16;
    luma_size = height * ((width + 31) / 32 * 32);
    chroma_size = (height / 2) * ((width / 2 + 31) / 32 * 32);
    return luma_size + chroma_size * 2 + 0x20;
}

static inline int mwsfcre_CnvBufFmt(int format) {
    int result;
    switch (format) {
    case 0: result = 3; break;
    case 1: result = 1; break;
    case 2: result = 2; break;
    case 3: result = 3; break;
    default:
        MWSFSVM_Error(lbl_12_rodata_2184);
        result = 3;
        break;
    }
    return result;
}

static inline int mwsfcre_MallocFrmTbl(MwsPlayer *player, const MwsCreateParams *params, void **frame_buffers) {
    int result = 0;
    int frame_count = params->frame_count;
    int frame_size;
    int index;
    int width;
    int height;

    width = params->width;
    height = params->height;
    if (params->buffer_format >= 4 || params->buffer_format < 0)
        MWSFSVM_Error(lbl_12_rodata_2184);
    frame_size = mwsfcre_CalcFrameSize(width, height);
    for (index = 0; index < frame_count; index++) {
        frame_buffers[index] = mwsfcre_Alloc(player, frame_size);
        if (frame_buffers[index] == 0) result = -1;
    }
    return result;
}

static inline void *mwsfcre_MallocWk(MwsPlayer *player, long work_size) {
    long size = work_size;
    return mwsfcre_Alloc(player, size);
}

static inline void *mwsfcre_MallocX(MwsPlayer *player, int size) {
    return mwsfcre_Alloc(player, size);
}

#pragma opt_dead_assignments off
SfdHandle *fn_12_3763C(MwsPlayer *player, MwsCreateParams *params) {
    int frame_height;
    int frame_width;
    int table_frames;
    void *shared_work;
    void *stream_work;
    int frame_result;
    MwsPictureUserWork *picture_user_work;
    void *decoder_work;
    void *video_work;
    void *filename_work;
    int file_type;
    void *audio_stream_buffer;
    void *audio_decoder_work;
    int frame_count;
    int width;
    int height;
    MwsReferenceBuffers references;
    void *frame_buffers[16];
    SfdCreateConfig create;
    SfdHandle *sfd;
    int frame_size;
    int rfb_result;
    int output_format;
    int allocation_size;
    MwsPictureUserConfig *picture_user;
    int current_height;
    int current_width;
    int sector_count;
    int bps;

    file_type = params->file_type;
    frame_count = params->frame_count;
    width = params->width;
    height = params->height;
    sector_count = params->decoder_count;

    bps = params->maximum_bps;
    if (sector_count <= 0) {
        sector_count = 1;
    }
    if (file_type == 2) {
        lbl_12_bss_1B9B0__fzgx_offset_1C = sector_count * (bps / 8 / 0x800 * 0x800);
        lbl_12_bss_1B9B0__fzgx_offset_18 = 0;
        lbl_12_bss_1B9B0__fzgx_offset_14 = 0;
        lbl_12_bss_1B9B0__fzgx_offset_10 = 0;
        lbl_12_bss_1B9B0 = 0;
        lbl_12_bss_1B9B0__fzgx_offset_4 = 0;
    } else if (file_type == 3) {
        lbl_12_bss_1B9B0__fzgx_offset_1C = sector_count * (bps / 8 / 0x800 * 0x800);
        lbl_12_bss_1B9B0__fzgx_offset_14 = bps / 8 / 0x800 * 0x800 / 2 + 0x800;
        lbl_12_bss_1B9B0__fzgx_offset_18 = 0;
        lbl_12_bss_1B9B0__fzgx_offset_10 = 0;
        lbl_12_bss_1B9B0 = 0;
        lbl_12_bss_1B9B0__fzgx_offset_4 = 0;
    } else {
        lbl_12_bss_1B9B0__fzgx_offset_1C = sector_count * (bps / 8 / 0x800 * 0x800);
        lbl_12_bss_1B9B0__fzgx_offset_14 = bps / 8 / 0x800 * 0x800 / 2 + 0x800;
        lbl_12_bss_1B9B0__fzgx_offset_18 = 0;
        lbl_12_bss_1B9B0__fzgx_offset_10 = 0x5DCC;
        lbl_12_bss_1B9B0 = 0x5F0C;
        lbl_12_bss_1B9B0__fzgx_offset_4 = 0xC1C0;
    }

    table_frames = params->frame_count;
    frame_width = params->width;
    frame_height = params->height;
    if (params->buffer_format >= 4 || params->buffer_format < 0) {
        MWSFSVM_Error(lbl_12_rodata_2184);
    }
    frame_size = mwsfcre_CalcFrameSize(frame_width, frame_height);
    lbl_12_bss_1B9B0__fzgx_offset_C = frame_size * 2;
    lbl_12_bss_1B9B0__fzgx_offset_8 = table_frames * frame_size;

    allocation_size = lbl_12_bss_1B9B0__fzgx_offset_18 + lbl_12_bss_1B9B0__fzgx_offset_14 + lbl_12_bss_1B9B0__fzgx_offset_10 + 0x20;
    shared_work = mwsfcre_Alloc(player, allocation_size);
    allocation_size = lbl_12_bss_1B9B0__fzgx_offset_1C + 0x40;
    stream_work = mwsfcre_Alloc(player, allocation_size);
    rfb_result = fn_12_38340(player, params, &references);
    frame_result = mwsfcre_MallocFrmTbl(player, params, frame_buffers);

    allocation_size = lbl_12_bss_1B9B0;
    audio_stream_buffer = mwsfcre_Alloc(player, allocation_size);
    allocation_size = lbl_12_bss_1B9B0__fzgx_offset_4;
    audio_decoder_work = mwsfcre_Alloc(player, allocation_size);
    picture_user_work = mwsfcre_MallocX(player, sizeof(*picture_user_work));
    decoder_work = mwsfcre_MallocWk(player, 0x4000);
    video_work = mwsfcre_MallocWk(player, 0x700);
    filename_work = mwsfcre_MallocX(player, 0x100);
    if (shared_work == 0 || stream_work == 0 || rfb_result != 0 ||
        frame_result != 0 || audio_stream_buffer == 0 || audio_decoder_work == 0 ||
        picture_user_work == 0 || decoder_work == 0 ||
        filename_work == 0 || video_work == 0) {
        MWSFSVM_Error(lbl_12_rodata_2184__fzgx_offset_28);
        mwsfcre_FreeAll(player);
        return 0;
    }

    lbl_12_bss_1B9B0__fzgx_offset_20 = (unsigned char *)(((unsigned int)stream_work + 0x3F) & ~0x3F);
    current_width = params->width;
    current_height = params->height;
    lbl_12_data_D38__fzgx_offset_110.chroma_width = (((current_width / 2) + 31) / 32) * 32;
    lbl_12_data_D38__fzgx_offset_110.chroma_height = current_height / 2;
    lbl_12_data_D38__fzgx_offset_110.width = current_width;
    lbl_12_data_D38__fzgx_offset_110.height = current_height;
    lbl_12_data_D38__fzgx_offset_110.reference_buffer = 0;
    lbl_12_data_D38__fzgx_offset_110.maximum_width = current_width;
    lbl_12_data_D38__fzgx_offset_110.maximum_height = current_height;
    lbl_12_data_D38__fzgx_offset_110.frame_count = frame_count;
    lbl_12_data_D38__fzgx_offset_110.frame_buffer = 0;
    lbl_12_data_D38__fzgx_offset_134.stream_buffer = audio_stream_buffer;
    lbl_12_data_D38__fzgx_offset_134.decoder_buffer = audio_decoder_work;

    switch (file_type) {
    case 1:
        create = lbl_12_data_D38__fzgx_offset_44;
        player->input_buffer = lbl_12_bss_1B9B0__fzgx_offset_20;
        player->input_buffer_size = lbl_12_bss_1B9B0__fzgx_offset_1C - 0x800;
        player->input_buffer_extra_size = 0x800;
        break;
    case 2:
        create = lbl_12_data_D38__fzgx_offset_88;
        player->input_buffer = lbl_12_bss_1B9B0__fzgx_offset_20;
        player->input_buffer_size = lbl_12_bss_1B9B0__fzgx_offset_1C - 0x800;
        player->input_buffer_extra_size = 0x800;
        break;
    case 3:
        create = lbl_12_data_D38__fzgx_offset_CC;
        player->input_buffer = lbl_12_bss_1B9B0__fzgx_offset_20;
        player->input_buffer_size = lbl_12_bss_1B9B0__fzgx_offset_1C - 0x800;
        player->input_buffer_extra_size = 0x800;
        break;
    }
    create.buffer.ring_alignment = lbl_12_data_D38__fzgx_offset_150;
    if (lbl_12_bss_1B9B0__fzgx_offset_18 != 0) {
        lbl_12_bss_1B9B0__fzgx_offset_18 = lbl_12_bss_1B9B0__fzgx_offset_18 - lbl_12_bss_1B9B0__fzgx_offset_18 % lbl_12_data_D38__fzgx_offset_150;
    }

    output_format = mwsfcre_CnvBufFmt(params->buffer_format);
    create.buffer.memory = shared_work;
    create.buffer.buffer_sizes[0] = lbl_12_bss_1B9B0__fzgx_offset_18;
    create.buffer.buffer_sizes[1] = lbl_12_bss_1B9B0__fzgx_offset_14;
    create.buffer.buffer_sizes[2] = lbl_12_bss_1B9B0__fzgx_offset_10;
    create.picture_user_buffer_minimum = frame_count;
    create.maximum_width = width;
    create.maximum_height = height;
    create.video_output_format = output_format;
    create.handle_memory = decoder_work;
    create.handle_memory_size = 0x4000;
    fn_12_2A6FC(&lbl_12_data_D38__fzgx_offset_110, references.buffers, frame_buffers);
    switch (file_type) {
    case 1:
        fn_12_2145C(&lbl_12_data_D38__fzgx_offset_134);
        break;
    case 2:
    case 3:
        break;
    }
    sfd = fn_12_2BCF4(&create, 0);
    if (sfd == 0) {
        fn_12_38A0C(-0x131);
        MWSFSVM_Error(lbl_12_rodata_2184__fzgx_offset_44);
        return 0;
    }
    if (fn_12_249BC(sfd, fn_12_388C4, player) != 0) {
        fn_12_38A0C(-0x12F);
        MWSFSVM_Error(lbl_12_rodata_2184__fzgx_offset_70);
        return 0;
    }
    player->filename = filename_work;
    player->filename_capacity = 0x100;
    player->picture_user_work = picture_user_work;
    player->picture_user_header_size = sizeof(picture_user_work->header);
    player->picture_user_write = 0;
    player->picture_user_read = 0;
    picture_user = &player->internal_picture_user;
    picture_user->buffer = picture_user_work->element_buffer;
    picture_user->buffer_size = sizeof(picture_user_work->element_buffer);
    picture_user->element_size = 0x40;
    player->picture_user = picture_user;
    return sfd;
}
#pragma opt_dead_assignments reset

/* fzgx:end fn_12_3763C */

/* fzgx:begin fn_12_38340 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_38340.c --- */
typedef u32 (*fn_12_38340_Fn0)(u32, u32);
struct fn_12_38340_Arg0 {
 u8 pad_0[0x158];
 u32 arena;
 u32 capacity;
 u32 current;
 u32 used;
 s32 count;
 u32 unk_16C[32];
};
struct fn_12_38340_Arg1 {
 u8 pad_0[8];
 s32 unk_8;
 s32 unk_C;
};
extern u32 *fn_12_38DBC(void);
extern char lbl_12_rodata_1DF4[33];
extern void MWSFSVM_Error(const char *, ...);
static inline u32 allocate(struct fn_12_38340_Arg0 *arg0, s32 size) {
 u32 result;
 u32 *manager;
 if (arg0->count >= 32) {
  MWSFSVM_Error(lbl_12_rodata_1DF4);
  return 0;
 }
 if (size < 0) return 0;
 if (arg0->arena != 0) {
  if (arg0->used + size > arg0->capacity) result = 0;
  else {
   result = arg0->current;
   arg0->current = result + size;
   arg0->used = arg0->used + size;
  }
 } else {
  manager = fn_12_38DBC();
  result = ((fn_12_38340_Fn0)manager[10])(manager[12], size);
 }
 if (result != 0) {
  arg0->unk_16C[arg0->count] = result;
  arg0->count++;
 }
 return result;
}
s32 fn_12_38340(struct fn_12_38340_Arg0 *arg0, struct fn_12_38340_Arg1 *arg1, u32 *arg2) {
 s32 v0;
 s32 v1;
 s32 v2;
 s32 v3;
 s32 v5;
 s32 v6;
 s32 v7;
 s32 v13 = 0;
 v0 = (arg1->unk_8 + 15) / 16;
 v1 = (arg1->unk_C + 15) / 16;
 v2 = v0 << 4;
 v3 = v1 << 4;
 v5 = v3 / 2;
 v6 = ((v2 + 31) / 32) << 5;
 v7 = v3 * v6 + ((v5 * (((v2 / 2 + 31) / 32) << 5)) << 1) + 32;
 arg2[0] = allocate(arg0, v7);
 arg2[1] = allocate(arg0, v7);
 if (arg2[0] == 0 || arg2[1] == 0) v13 = -1;
 return v13;
}
/* fzgx:end fn_12_38340 */

/* fzgx:begin fn_12_3858C noprologue */

/* --- rel/movie_module/fn_12_3858C.c --- */
typedef struct MovieModule {
    u8 pad_0x00[0x40];
    void* player;
    u8 pad_0x44[0xE4];
    void* movie;
    void* movie_data_alt;
    u32 movie_data_alt_1;
    u32 movie_data_alt_2;
    u32 movie_data_alt_3;
    u32 movie_data_1;
    u32 movie_data_2;
    u32 movie_data_3;
    u32 movie_data_4;
    void* movie_data;
    u32 movie_data_5;
    u32 movie_data_6;
} MovieModule;

typedef struct MovieRequest {
    u32 flags;
    void* movie;
    u32 data;
    u32 data_size;
    u32 data_type;
    u32 data_flags;
} MovieRequest;

extern s32 fn_12_2B188(void*, MovieRequest*);
extern void fn_12_38A0C(s32);
extern char lbl_12_rodata_221C[33];

void fn_12_3858C(MovieModule* module) {
    void* movie;
    void* player;
    MovieRequest request;

    movie = module->movie;
    player = module->player;
    if (movie != NULL) {
        if (movie == module->movie_data) {
            request.flags = 1;
            request.movie = movie;
            request.data = module->movie_data_5;
            request.data_size = module->movie_data_6;
            request.data_type = 0;
            request.data_flags = 0;
        } else if (movie == module->movie_data_alt) {
            request.flags = 0;
            request.movie = movie;
            request.data = module->movie_data_alt_1;
            request.data_size = module->movie_data_alt_2;
            request.data_type = module->movie_data_alt_3;
            request.data_flags = 0;
        } else {
            request.flags = module->movie_data_1;
            request.movie = movie;
            request.data = module->movie_data_2;
            request.data_size = module->movie_data_3;
            request.data_type = module->movie_data_4;
            request.data_flags = 0;
        }
        if (fn_12_2B188(player, &request) != 0) {
            fn_12_38A0C(-0x138);
            MWSFSVM_Error(lbl_12_rodata_221C);
        }
    }
}
/* fzgx:end fn_12_3858C */

/* fzgx:begin fn_12_38680 noprologue */

/* --- rel/movie_module/fn_12_38680.c --- */
extern char lbl_12_rodata_2240[45];
extern u32 fn_12_38704(void);
extern u32 fn_12_35DB4(u32, u32);
extern s32 fn_12_35548(void *);

typedef struct MovieResource {
    u8 pad[8];
    u32 field_8;
    u32 field_c;
} MovieResource;

static inline u32 resource_offset(MovieResource *movie) {
    u32 offset;

    offset = fn_12_35DB4(movie->field_8, movie->field_c);
    if (fn_12_35548(movie) == 1) {
        offset += 0x20000;
    }
    return offset;
}

u32 fn_12_38680(MovieResource *movie) {
    u32 base;

    if (movie == 0) {
        MWSFSVM_Error(lbl_12_rodata_2240);
        return 0;
    }

    base = fn_12_38704();
    return base + resource_offset(movie);
}
/* fzgx:end fn_12_38680 */

/* fzgx:begin fn_12_38704 noprologue */
#include "types.h"

/* the create parameters fn_12_3763C reads (its MwsCreateParams); 0x24 is the buffer format its error string names */
typedef struct MwsCreateParams {
    int file_type;
    int maximum_bps;
    int width;
    int height;
    int frame_count;
    int decoder_count;
    void *work;
    int work_size;
    int composition_mode;
    int buffer_format;
} MwsCreateParams;

extern void MWSFSVM_Error(const char *, ...);
extern const char lbl_12_rodata_2184[];

static inline int mwsfcre_CalcFrameSize(int source_width, int source_height) {
    int height;
    int width;
    int luma_size;
    int chroma_size;

    width = (source_width + 15) / 16 * 16;
    height = (source_height + 15) / 16 * 16;
    luma_size = height * ((width + 31) / 32 * 32);
    chroma_size = (height / 2) * ((width / 2 + 31) / 32 * 32);
    return luma_size + chroma_size * 2 + 0x20;
}

#pragma use_lmw_stmw on
#pragma opt_propagation off

/* Adds up the sizes fn_12_3763C allocates for these parameters; work_<off> are the sizes fn_12_3763C keeps at
 * lbl_12_bss_1B9B0+<off>. MWCC folds a sum's constants only within one type, so the int, long and u32 terms keep
 * retail's three separate constants (0x20, 0x840, 0x4800). */
int fn_12_38704(MwsCreateParams *params) {
    int frame_count;
    long work_1C;
    int work_18;
    int work_10;
    u32 work_00;
    u32 work_04;
    int height;
    int width;
    int work_14;
    int bps;
    int file_type;
    int sector_count;
    int frame_size;
    int work_08;
    int work_0C;

    sector_count = params->decoder_count;
    file_type = params->file_type;
    bps = params->maximum_bps;
    if (sector_count <= 0) {
        sector_count = 1;
    }
    if (file_type == 2) {
        work_1C = sector_count * (bps / 8 / 0x800 * 0x800);
        work_18 = 0;
        work_14 = 0;
        work_10 = 0;
        work_00 = 0;
        work_04 = 0;
    } else if (file_type == 3) {
        work_1C = sector_count * (bps / 8 / 0x800 * 0x800);
        work_14 = bps / 8 / 0x800 * 0x800 / 2 + 0x800;
        work_18 = 0;
        work_10 = 0;
        work_00 = 0;
        work_04 = 0;
    } else {
        work_1C = sector_count * (bps / 8 / 0x800 * 0x800);
        work_14 = bps / 8 / 0x800 * 0x800 / 2 + 0x800;
        work_18 = 0;
        work_10 = 0x5DCC;
        work_00 = 0x5F0C;
        work_04 = 0xC1C0;
    }

    frame_count = params->frame_count;
    width = params->width;
    height = params->height;
    if (params->buffer_format >= 4 || params->buffer_format < 0) {
        MWSFSVM_Error(lbl_12_rodata_2184);
    }
    frame_size = mwsfcre_CalcFrameSize(width, height);
    work_0C = frame_size * 2;
    work_08 = frame_count * frame_size;
    return work_18 + work_14 + work_10 + 0x20 + work_1C + 0x40 + 0x800 + work_0C + work_08 + work_00 + work_04 + 0x4000 +
           0x700 + 0x100;
}
#pragma opt_propagation reset
/* fzgx:end fn_12_38704 */
