
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

typedef struct DctFsriBlock {
    s16 samples[64];
} DctFsriBlock;

typedef struct DctFsriParams {
    union {
        unsigned char padding_extent[84];
        struct {
            unsigned char padding_field_4C[76];
            u8 field_4C[8];
        } view_field_4C;
    } fields;
} DctFsriParams;

typedef struct MPVContext MPVContext;

typedef void (*MPVErrorCallback)(void *object, int error);

typedef struct MPVErrorInfo {
    MPVErrorCallback callback;
    void *callback_object;
    int first_error;
    int field_0C;
    int field_10;
} MPVErrorInfo;

typedef struct MPVMCContext MPVMCContext;

typedef void (*MPVMCFunction)(MPVMCContext *context);

struct MPVMCContext {
    MPVMCFunction functions08[4];
    u8 field_10[8];
    u8 *destination;
    u32 field_1c;
    s32 reference_stride;
    const u8 *reference0;
    const u8 *reference1;
    u8 field_2c[8];
    MPVMCFunction functions16[4];
};

typedef struct MPVPlaneSet {
    union {
        unsigned char padding_extent[16];
        struct {
            u8 *planes[3];
        } view_planes;
        struct {
            unsigned char padding_chroma_stride[12];
            s16 chroma_stride;
        } view_chroma_stride;
        struct {
            unsigned char padding_luma_stride[14];
            s16 luma_stride;
        } view_luma_stride;
    } fields;
} MPVPlaneSet;

typedef struct MPVOutputBlock {
    u8 *destination;
    s32 stride;
} MPVOutputBlock;

typedef struct MPVOutputBlocks {
    s32 count;
    MPVOutputBlock blocks[6];
} MPVOutputBlocks;

typedef struct MPVMacroblockSources {
    void *field_00;
    s16 *residual;
    u8 *prediction0;
    u8 *prediction1;
} MPVMacroblockSources;

typedef struct MPVYccPlane {
    union {
        unsigned char padding_extent[16];
        struct {
            unsigned char padding_chroma_stride[12];
            s16 chroma_stride;
        } view_chroma_stride;
        struct {
            unsigned char padding_luma_stride[14];
            s16 luma_stride;
        } view_luma_stride;
    } fields;
} MPVYccPlane;

typedef struct MPVMotionInfo {
    s32 full_pel;
    s32 r_size;
    s32 shift;
    s32 limit;
    s32 previous_horizontal;
    s32 previous_vertical;
    s32 horizontal;
    s32 vertical;
    u8 field_20[4];
} MPVMotionInfo;

typedef struct MPVPictureAttributes {
    union {
        unsigned char padding_extent[128];
        struct {
            int width;
        } view_width;
        struct {
            unsigned char padding_height[4];
            int height;
        } view_height;
        struct {
            unsigned char padding_field_40[64];
            int field_40;
        } view_field_40;
        struct {
            unsigned char padding_field_44[68];
            int field_44;
        } view_field_44;
        struct {
            unsigned char padding_field_50[80];
            s16 field_50;
        } view_field_50;
    } fields;
} MPVPictureAttributes;

typedef MPVPictureAttributes MPVPictureInfo;

typedef struct MPVFrameBuffers {
    union {
        unsigned char padding_extent[48];
        struct {
            unsigned char padding_picture_info[36];
            MPVPictureInfo *picture_info;
        } view_picture_info;
    } fields;
} MPVFrameBuffers;

typedef struct MPVBitReader {
    u32 bits;
    u32 next_bits;
    s32 bit_offset;
    const u32 *words;
} MPVBitReader;

typedef struct MPVConditionState {
    int conditions[16];
    MPVPictureAttributes picture;
} MPVConditionState;

typedef struct MPVTransformWorkspace {
    DctFsriBlock blocks[6];
    float coefficients[6][64];
} MPVTransformWorkspace;

typedef struct MPVCodingBlock {
    s32 run;
    s32 level;
    s32 sign;
    u32 code_length;
    s32 first_scan;
    s32 current_scan;
    u8 field_18[4];
    void *coefficients;
    const u8 *quant_matrix;
    s32 quantizer_scale;
    s32 *dc_predictor;
    const u8 *dc_size_lut;
} MPVCodingBlock;

typedef struct MPVCodingWorkspace {
    MPVCodingBlock block;
    s32 non_intra_mode;
} MPVCodingWorkspace;

typedef struct MPVUserStream {
    SJ *stream;
    void (*callback)(void *argument, int index);
    void *callback_argument;
} MPVUserStream;

typedef struct MPVPictureUserBuffer {
    void *buffer;
    s32 capacity;
    s32 size;
} MPVPictureUserBuffer;

struct MPVContext {
    union {
        unsigned char padding_extent[4992];
        struct {
            unsigned char padding_state[392];
            s32 state;
        } view_state;
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
    union {
        unsigned char padding_extent[52];
        struct {
            unsigned char padding_width[8];
            int width;
        } view_width;
        struct {
            unsigned char padding_height[12];
            int height;
        } view_height;
    } fields;
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
    union {
        unsigned char padding_extent[128];
        struct {
            unsigned char padding_display_time_scale[24];
            int display_time_value, display_time_scale;
        } view_display_time_scale;
        struct {
            unsigned char padding_frame_buffer[32];
            void *frame_buffer;
        } view_frame_buffer;
    } fields;
} SfdVideoFrameInfo;

struct SfdVideoFrameState {
    union {
        unsigned char padding_extent[136];
        struct {
            int state;
        } view_state;
    } fields;
};

typedef struct SfdBufferCreateConfig {
    const SfdTransportSetup *transport_setup;
    unsigned char *memory;
    int buffer_sizes[7];
    int field_24;
    int ring_alignment;
} SfdBufferCreateConfig;

typedef struct SfdCreateConfig {
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_video_output_format[56];
            int video_output_format;
        } view_video_output_format;
    } fields;
} SfdCreateConfig;

typedef struct SfdTransportState {
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_context[8];
            void *context;
        } view_context;
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
            SfdCreateConfig create_config;
        } view_create_config;
        struct {
            unsigned char padding_transports[6816];
            SfdTransportState transports[9];
        } view_transports;
    } fields;
};

typedef struct SfdMpvPictureUserData SfdMpvPictureUserData;

typedef struct SfdMpvParameters {
    union {
        unsigned char padding_extent[36];
        struct {
            unsigned char padding_width[8];
            s32 width;
        } view_width;
        struct {
            unsigned char padding_height[12];
            s32 height;
        } view_height;
        struct {
            unsigned char padding_reference_buffer[16];
            s32 reference_buffer;
        } view_reference_buffer;
        struct {
            unsigned char padding_frame_count[28];
            s32 frame_count;
        } view_frame_count;
        struct {
            unsigned char padding_frame_buffer[32];
            s32 frame_buffer;
        } view_frame_buffer;
    } fields;
} SfdMpvParameters;

typedef struct SfdMpvFrame {
    union {
        unsigned char padding_extent[120];
        struct {
            int state;
        } view_state;
        struct {
            unsigned char padding_frame_buffer[4];
            void *frame_buffer;
        } view_frame_buffer;
        struct {
            unsigned char padding_display_time_value[8];
            int display_time_value;
        } view_display_time_value;
        struct {
            unsigned char padding_display_time_scale[12];
            int display_time_scale;
        } view_display_time_scale;
        struct {
            unsigned char padding_field_40[16];
            int field_40;
        } view_field_40;
        struct {
            unsigned char padding_field_44[20];
            int field_44;
        } view_field_44;
        struct {
            unsigned char padding_picture_order[24];
            int picture_order;
        } view_picture_order;
        struct {
            unsigned char padding_field_4C[28];
            int field_4C;
        } view_field_4C;
        struct {
            unsigned char padding_field_50[32];
            int field_50;
        } view_field_50;
        struct {
            unsigned char padding_picture_info[40];
            unsigned int picture_info[20];
        } view_picture_info;
    } fields;
} SfdMpvFrame;

typedef struct SfdMpvFrameWork {
    union {
        unsigned char padding_extent[3968];
        struct {
            unsigned char padding_setup_values[4];
            SfdMpvParameters setup_values;
        } view_setup_values;
        struct {
            unsigned char padding_saved_pair[40];
            void *saved_pair[2];
        } view_saved_pair;
        struct {
            unsigned char padding_address_table[48];
            void *address_table[16];
        } view_address_table;
        struct {
            unsigned char padding_picture_info[140];
            MPVPictureInfo picture_info;
        } view_picture_info;
        struct {
            unsigned char padding_planes[264];
            MPVPlaneSet planes[2];
        } view_planes;
        struct {
            unsigned char padding_reference_frames[296];
            SfdMpvFrame *reference_frames[2];
        } view_reference_frames;
        struct {
            unsigned char padding_frame_count[308];
            int frame_count;
        } view_frame_count;
        struct {
            unsigned char padding_frames[312];
            SfdMpvFrame frames[16];
        } view_frames;
    } fields;
} SfdMpvFrameWork;

struct SfdMpvPictureUserData {
    void *buffer;
    int size;
};

typedef struct SfdMpvPlaybackSettings {
    union {
        unsigned char padding_extent[64];
        struct {
            int width;
        } view_width;
        struct {
            unsigned char padding_height[4];
            int height;
        } view_height;
    } fields;
} SfdMpvPlaybackSettings;

int fn_12_27C58(SfdHandle *handle, SfdMpvPlaybackSettings *settings);

int fn_12_24A88(SfdHandle *handle, int error);

void SFTIM_InitTtu(SfdTimerTimeUnit *unit, int scale);

SfdMpvFrame *fn_12_2AB68(SfdHandle *handle);

void fn_12_33428(unsigned int *destination, unsigned int value, unsigned int count);

static inline void sfmpv_InitFrame(SfdMpvFrame *frame, void **frame_buffer) {
    frame->fields.view_state.state = 0;

    frame->fields.view_frame_buffer.frame_buffer = *frame_buffer;
    frame->fields.view_display_time_value.display_time_value = 0;
    frame->fields.view_display_time_scale.display_time_scale = 1;
    frame->fields.view_field_40.field_40 = 0;
    frame->fields.view_field_44.field_44 = 0;
    frame->fields.view_picture_order.picture_order = 0;
    frame->fields.view_field_4C.field_4C = 0;
    frame->fields.view_field_50.field_50 = 0;
    fn_12_33428(frame->fields.view_picture_info.picture_info, -1, 20);
}

static inline void sfmpv_InitSavedFrames(SfdMpvFrameWork *work, SfdMpvFrame *frame) {
    int i;
    for (i = 0; i < 2; i++, frame++) {
        sfmpv_InitFrame(frame, &work->fields.view_saved_pair.saved_pair[i]);
    }
}

static inline void sfmpv_InitDecodedFrames(SfdMpvFrameWork *work, SfdMpvFrame *frame, int count) {
    int i;
    for (i = 0; i < count; i++, frame++) {
        sfmpv_InitFrame(frame, &work->fields.view_address_table.address_table[i]);
    }
}

static inline int sfmpv_CalcFrameSize(int width, int height) {
    int aligned_width = ((width + 15) / 16) * 16;
    int aligned_height = ((height + 15) / 16) * 16;
    int luma_size = aligned_height * (((aligned_width + 31) / 32) * 32);
    int chroma_size = (aligned_height / 2) * ((((aligned_width / 2) + 31) / 32) * 32);
    return luma_size + chroma_size * 2 + 0x20;
}

static inline void sfmpv_SetPlane(void **buffer, int luma_stride, int chroma_stride, int luma_size,
                                  int chroma_size, MPVPlaneSet *plane) {
    plane->fields.view_luma_stride.luma_stride = luma_stride;
    plane->fields.view_chroma_stride.chroma_stride = chroma_stride;
    plane->fields.view_planes.planes[2] = *buffer;
    plane->fields.view_planes.planes[0] = plane->fields.view_planes.planes[2] + luma_size;
    plane->fields.view_planes.planes[1] = plane->fields.view_planes.planes[0] + chroma_size;
}

int fn_12_27C58(SfdHandle *handle, SfdMpvPlaybackSettings *settings) {
    SfdMpvFrameWork *work =
        handle->fields.view_transports.transports[2].fields.view_context.context;
    unsigned char *frame_buffer;
    int frame_size;
    int configured_width = work->fields.view_setup_values.setup_values.fields.view_width.width;
    int configured_height = work->fields.view_setup_values.setup_values.fields.view_height.height;
    int width;
    int height;
    int aligned_width;
    int aligned_height;
    int luma_stride;
    int chroma_stride;
    int luma_size;
    int chroma_size;
    int configured_size;
    int requested_count =
        work->fields.view_setup_values.setup_values.fields.view_frame_count.frame_count;
    int frame_count;
    int decoded_count;
    int i;
    unsigned char *reference_buffer;
    SfdMpvFrame *frames = work->fields.view_frames.frames;
    width = settings->fields.view_width.width;
    height = settings->fields.view_height.height;
    aligned_width = ((width + 15) / 16) * 16;
    aligned_height = ((height + 15) / 16) * 16;
    luma_stride = ((aligned_width + 31) / 32) * 32;
    chroma_size = (aligned_height / 2) * (chroma_stride = (((aligned_width / 2) + 31) / 32) * 32);
    luma_size = aligned_height * luma_stride;
    frame_size = luma_size + chroma_size * 2 + 0x20;
    configured_size = sfmpv_CalcFrameSize(configured_width, configured_height);
    if (frame_size * 2 > configured_size * 2) {
        return fn_12_24A88(handle, 0xFF000F17);
    }
    frame_buffer =
        (unsigned char *)
            work->fields.view_setup_values.setup_values.fields.view_frame_buffer.frame_buffer;
    if (frame_buffer == 0) {
        frame_count = requested_count;
    } else {
        int available_size = requested_count * configured_size;
        int used_size = frame_size;
        for (frame_count = 1; frame_count <= 16; frame_count++) {
            if (used_size > available_size) {
                frame_count--;
                break;
            }
            used_size += frame_size;
        }
        if (frame_count < requested_count) {
            return fn_12_24A88(handle, 0xFF000F17);
        }
        reference_buffer = (unsigned char *)work->fields.view_setup_values.setup_values.fields
                               .view_reference_buffer.reference_buffer;
        work->fields.view_saved_pair.saved_pair[0] = reference_buffer;
        work->fields.view_saved_pair.saved_pair[1] = reference_buffer + frame_size;
        for (i = 0; i < frame_count; i++) {
            work->fields.view_address_table.address_table[i] = frame_buffer + i * frame_size;
        }
    }
    sfmpv_SetPlane(&work->fields.view_saved_pair.saved_pair[0], luma_stride, chroma_stride,
                   luma_size, chroma_size, &work->fields.view_planes.planes[0]);
    sfmpv_SetPlane(&work->fields.view_saved_pair.saved_pair[1], luma_stride, chroma_stride,
                   luma_size, chroma_size, &work->fields.view_planes.planes[1]);
    if (handle->fields.view_create_config.create_config.fields.view_video_output_format
            .video_output_format == 3) {
        decoded_count = frame_count < 14 ? frame_count : 14;
        work->fields.view_frame_count.frame_count = decoded_count + 2;
        sfmpv_InitSavedFrames(work, frames);
        sfmpv_InitDecodedFrames(work, frames + 2, decoded_count);
        work->fields.view_reference_frames.reference_frames[0] = fn_12_2AB68(handle);
        work->fields.view_reference_frames.reference_frames[1] = fn_12_2AB68(handle);
    } else {
        decoded_count = frame_count < 16 ? frame_count : 16;
        work->fields.view_frame_count.frame_count = decoded_count;
        sfmpv_InitDecodedFrames(work, frames, decoded_count);
    }
    return 0;
}
