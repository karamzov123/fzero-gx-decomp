
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

typedef int SfdConditionValue;

typedef struct SfdHandle SfdHandle;

typedef struct SfdTimerState {
    union {
        unsigned char padding_extent[1504];
        struct {
            unsigned char padding_unknown_02EC[748];
            unsigned char unknown_02EC[0x2C4];
        } view_unknown_02EC;
    } fields;
} SfdTimerState;

struct SfdHandle {
    union {
        unsigned char padding_extent[13720];
        struct {
            unsigned char padding_timer_state[3184];
            SfdTimerState timer_state;
        } view_timer_state;
    } fields;
};

typedef struct SfdAdxtParameters {
    union {
        unsigned char padding_extent[28];
        struct {
            int stream_buffer_size;
        } view_stream_buffer_size;
        struct {
            unsigned char padding_stream_buffer_extra_size[4];
            int stream_buffer_extra_size;
        } view_stream_buffer_extra_size;
        struct {
            unsigned char padding_stream_buffer[8];
            void *stream_buffer;
        } view_stream_buffer;
        struct {
            unsigned char padding_maximum_channels[12];
            int maximum_channels;
        } view_maximum_channels;
        struct {
            unsigned char padding_decoder_work_size[16];
            int decoder_work_size;
        } view_decoder_work_size;
        struct {
            unsigned char padding_decoder_buffer_size[20];
            int decoder_buffer_size;
        } view_decoder_buffer_size;
        struct {
            unsigned char padding_decoder_buffer[24];
            void *decoder_buffer;
        } view_decoder_buffer;
    } fields;
} SfdAdxtParameters;

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
            unsigned char padding_stream_joint[4];
            SJ *stream_joint;
        } view_stream_joint;
        struct {
            unsigned char padding_stream_buffer_size[8];
            int stream_buffer_size;
        } view_stream_buffer_size;
        struct {
            unsigned char padding_stream_buffer_extra_size[8];
            int stream_buffer_extra_size;
        } view_stream_buffer_extra_size;
        struct {
            unsigned char padding_stream_buffer[12];
            void *stream_buffer;
        } view_stream_buffer;
        struct {
            unsigned char padding_maximum_channels[20];
            int maximum_channels;
        } view_maximum_channels;
        struct {
            unsigned char padding_decoder_work_size[24];
            int decoder_work_size;
        } view_decoder_work_size;
        struct {
            unsigned char padding_decoder_buffer_size[28];
            int decoder_buffer_size;
        } view_decoder_buffer_size;
        struct {
            unsigned char padding_decoder_buffer[32];
            void *decoder_buffer;
        } view_decoder_buffer;
        struct {
            unsigned char padding_maximum_time_value[36];
            int maximum_time_value;
        } view_maximum_time_value;
        struct {
            unsigned char padding_maximum_time_scale[40];
            int maximum_time_scale;
        } view_maximum_time_scale;
        struct {
            unsigned char padding_paused[44];
            int paused;
        } view_paused;
        struct {
            unsigned char padding_discarded_samples[48];
            int discarded_samples;
        } view_discarded_samples;
        struct {
            unsigned char padding_header_inserted[52];
            int header_inserted;
        } view_header_inserted;
        struct {
            unsigned char padding_sample_offset[56];
            int sample_offset;
        } view_sample_offset;
        struct {
            unsigned char padding_copy[60];
            SfdAdxtCopyFn copy;
        } view_copy;
        struct {
            unsigned char padding_seek_depth[64];
            int seek_depth;
        } view_seek_depth;
        struct {
            unsigned char padding_server_frequency[68];
            int server_frequency;
        } view_server_frequency;
        struct {
            unsigned char padding_copied_bytes[72];
            int copied_bytes;
        } view_copied_bytes;
        struct {
            unsigned char padding_field_4C[72];
            int field_4C;
        } view_field_4C;
        struct {
            unsigned char padding_params[8];
            SfdAdxtParameters params;
        } view_params;
    } fields;
} SfdAdxtWork;

struct AdxtHandle {
    unsigned char unknown_00[0x0C];
    int field_0C;
};

int fn_12_24A88(SfdHandle *handle, int error);

SfdConditionValue fn_12_2D73C(SfdHandle *handle, int condition);

void fn_12_33604(int channel);

extern void SFTST_Create(SfdTestWork *work);

extern void fn_12_309C0(SfdTestWork *work, int value);

extern void fn_12_309D0(SfdTestWork *work, const SfdTestTime *value);

extern void fn_12_309E4(SfdTestWork *work, const SfdTestTime *value);

extern void fn_12_309F8(SfdTestWork *work, const SfdTestTime *value);

extern void fn_12_30A0C(SfdTestWork *work, const SfdTestTime *value);

extern void fn_12_30A20(SfdTestWork *work, int value);

extern void fn_12_33604(int channel);

extern SfdAdxtParameters lbl_12_bss_6990;

static inline SfdTestWork *sfadxt_GetTestWork(SfdHandle *handle) {
    return (SfdTestWork *)(handle->fields.view_timer_state.timer_state.fields.view_unknown_02EC
                               .unknown_02EC +
                           4);
}

void fn_12_20F4C(SfdHandle *handle, const unsigned char *data, int size, int *consumed);

int fn_12_206B8(SfdHandle *handle, SfdAdxtWork *work) {
    SfdTestWork *test_work;
    SfdTestTime tolerance;
    SfdTestTime excess_error;
    SfdTestTime adjustment_start;
    SfdTestTime adjustment_offset;
    if (lbl_12_bss_6990.fields.view_stream_buffer.stream_buffer == 0 ||
        lbl_12_bss_6990.fields.view_decoder_buffer.decoder_buffer == 0) {
        return fn_12_24A88(handle, 0xFF000C06);
    }
    work->fields.view_params.params = lbl_12_bss_6990;
    work->fields.view_decoder.decoder = 0;
    work->fields.view_stream_joint.stream_joint = 0;
    work->fields.view_maximum_time_value.maximum_time_value = -1;
    work->fields.view_maximum_time_scale.maximum_time_scale = 1;
    work->fields.view_paused.paused = 0;
    work->fields.view_discarded_samples.discarded_samples = 0;
    work->fields.view_header_inserted.header_inserted = 0;
    work->fields.view_sample_offset.sample_offset = 0;
    work->fields.view_copy.copy = fn_12_20F4C;
    work->fields.view_seek_depth.seek_depth = 0;
    work->fields.view_server_frequency.server_frequency = -1;
    work->fields.view_copied_bytes.copied_bytes = 0;
    test_work = sfadxt_GetTestWork(handle);
    tolerance.fields.view_value.value = fn_12_2D73C(handle, 0x3F);
    tolerance.fields.view_scale.scale = 1000000;
    excess_error.fields.view_value.value = fn_12_2D73C(handle, 0x40);
    excess_error.fields.view_scale.scale = 1000000;
    adjustment_start.fields.view_value.value = fn_12_2D73C(handle, 0x41);
    adjustment_start.fields.view_scale.scale = 1000000;
    adjustment_offset.fields.view_value.value = fn_12_2D73C(handle, 0x42);
    adjustment_offset.fields.view_scale.scale = 1000000;
    SFTST_Create(test_work);
    fn_12_30A20(test_work, fn_12_2D73C(handle, 0x48));
    fn_12_30A0C(test_work, &tolerance);
    fn_12_309F8(test_work, &excess_error);
    fn_12_309E4(test_work, &adjustment_start);
    fn_12_309D0(test_work, &adjustment_offset);
    fn_12_309C0(test_work, fn_12_2D73C(handle, 0x3E));
    fn_12_33604(fn_12_2D73C(handle, 0x3D));
    return 0;
}
