#include "types.h"

/* fzgx:begin fn_12_20284 noprologue */
#include "types.h"

extern void fn_12_24A88(u32, u32);

void fn_12_20284(u32 value) {
    fn_12_24A88(value, 0xff000c03);
}
/* fzgx:end fn_12_20284 */

/* fzgx:begin fn_12_202AC noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_202AC.c --- */
/* --- rel/movie_module/fn_12_202AC.c --- */
extern void fn_12_24A88(void *arg0, s32 arg1);

void fn_12_202AC(void *arg0) {
    fn_12_24A88(arg0, 0xff000c03);
}
/* fzgx:end fn_12_202AC */

/* fzgx:begin fn_12_202D4 noprologue */

/* --- rel/movie_module/fn_12_202D4.c --- */
void fn_12_202D4(void *arg) {
    fn_12_24A88(arg, 0xFF000C03);
}
/* fzgx:end fn_12_202D4 */

/* fzgx:begin fn_12_202FC noprologue */

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

typedef struct SfdTransportState {
    union {
        unsigned char padding_extent[68];
        struct {
            unsigned char padding_context[8];
            void *context;
        } view_context;
    } fields;
} SfdTransportState;

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
/* fzgx:end fn_12_202FC */

/* fzgx:begin fn_12_20448 noprologue */

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
/* fzgx:end fn_12_20448 */

/* fzgx:begin fn_12_20474 noprologue */

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
/* fzgx:end fn_12_20474 */

/* fzgx:begin fn_12_204D4 noprologue */

/* --- rel/movie_module/fn_12_204D4.c --- */
// fn_12_204D4: returns a constant.
int fn_12_204D4(void) {
    return 0;
}
/* fzgx:end fn_12_204D4 */

/* fzgx:begin fn_12_204DC noprologue */

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
/* fzgx:end fn_12_204DC */

/* fzgx:begin fn_12_205BC noprologue */

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
/* fzgx:end fn_12_205BC */

/* fzgx:begin fn_12_206B8 noprologue */

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
/* fzgx:end fn_12_206B8 */

/* fzgx:begin fn_12_208C4 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_208C4.c --- */
extern int fn_12_2D73C(void *, int);
extern int fn_12_206B8(void *, void *);
extern u32 fn_12_2B348(void);
extern u32 lbl_12_bss_7C64[137];
extern int fn_12_24A88(void *, int);
extern void fn_8004BE90(void *, int);
extern void fn_8004ED18(void *, int);
extern void *fn_8004CD70(u32, u32, u32);
extern void *fn_80058498(u32, u32, u32);
extern void fn_8004C794(void *, void *);
extern void ADXT_Pause(void *, int);
extern void fn_12_309B8(void *, int);
extern void fn_12_205BC(void);
extern void fn_12_2E41C(void *, void (*)(void), int);
extern void fn_12_2D7DC(void *, int, int);
extern void fn_12_215CC(void);
extern void fn_12_215A4(void);
extern void fn_12_2157C(void);
extern void fn_12_21554(void);
extern void fn_12_214B0(void);

typedef struct MovieData {
    void *movie;
    void *field_0004;
    u32 field_0008;
    u32 field_000c;
    u32 field_0010;
    u32 field_0014;
    u32 field_0018;
    u32 field_001c;
    u32 field_0020;
} MovieData;

typedef struct Movie {
    u8 pad_0000[0xc];
    u32 field_000c;
} Movie;

typedef struct MovieModule {
    u8 pad_0000[0x50];
    int field_0050;
    u8 pad_0054[0xf0c];
    u8 field_0f60[1];
    u8 pad_0f61[0xc13];
    MovieData *field_1b74;
    u8 pad_1b78[0x10c];
    void *field_1c84;
    u8 pad_1c88[0xb84];
    MovieData field_280c;
    u8 pad_2830[0x88];
    void *field_28b8;
    void *field_28bc;
    void *field_28c0;
    void *field_28c4;
    void *field_28c8;
    void *field_28cc;
} MovieModule;

#pragma opt_propagation off
int fn_12_208C4(MovieModule *arg0) {
    void **fzgx_value;
    struct { Movie *value; } movie;
    struct { MovieData *value; } movie_data;
    void *movie_handle;
    int result;

    if (fn_12_2D73C(arg0, 6) == 0) {
        return 0;
    }
    movie_data.value = &arg0->field_280c;
    arg0->field_1b74 = movie_data.value;
    result = fn_12_206B8(arg0, movie_data.value);
    if (result != 0) {
        return result;
    }
    if ((int)fn_12_2B348() != 1) {
        movie.value = (Movie *)fn_8004CD70(movie_data.value->field_0014,
                                     movie_data.value->field_0020,
                                     movie_data.value->field_001c);
    } else {
        movie.value = (Movie *)((u32 *)(lbl_12_bss_7C64))[128];
    }
    if (movie.value == 0) {
        movie.value = 0;
    } else {
        fn_8004BE90(movie.value, 0);
        fn_8004ED18(movie.value, 1);
    }
    if (movie.value == 0) {
        return fn_12_24A88(arg0, 0xff000c04);
    }
    movie_handle = fn_80058498(movie_data.value->field_0010,
                               movie_data.value->field_0008,
                               movie_data.value->field_000c);
    if (movie_handle == 0) {
        return fn_12_24A88(arg0, 0xff000c05);
    }
    movie_data.value->movie = movie.value;
    movie_data.value->field_0004 = movie_handle;
    arg0->field_1c84 = &arg0->field_28b8;
    fzgx_value = &arg0->field_28b8;
    *fzgx_value = (void *)movie.value->field_000c;
    arg0->field_28bc = (void *)fn_12_215CC;
    arg0->field_28c0 = (void *)fn_12_215A4;
    arg0->field_28c4 = (void *)fn_12_2157C;
    arg0->field_28c8 = (void *)fn_12_21554;
    arg0->field_28cc = (void *)fn_12_214B0;
    fn_8004C794(movie.value, movie_handle);
    movie_data.value = arg0->field_1b74;
    movie_handle = movie_data.value->movie;
    *(u32 *)((u8 *)movie_data.value + 0x2c) = 1;
    ADXT_Pause(movie_handle, 1);
    fn_12_309B8(arg0->field_0f60, 1);
    fn_12_2E41C(arg0, fn_12_205BC, 2);
    fn_12_2D7DC(arg0, 15, 2);
    return 0;
}
/* fzgx:end fn_12_208C4 */

/* fzgx:begin fn_12_20A7C noprologue */
#pragma opt_propagation reset

/* --- rel/movie_module/fn_12_20A7C.c --- */
extern int fn_12_23F34(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_12_20B90(void);
extern int memcmp(u32 arg0, u32 arg1, u32 arg2);
extern u8 lbl_12_rodata_A50[20];

typedef struct Movie_u1 {
    u8 pad_0000[0x38];
    void *field_0038;
    void (*field_003c)(void);
    int field_0040;
} Movie_u1;

typedef struct MovieData_u1 {
    u8 pad_0000[0xcfc];
    void *field_0cfc;
} MovieData_u1;

typedef struct MovieModule_u1 {
    u8 pad_0000[0x1b74];
    Movie_u1 *field_1b74;
    u8 pad_1b78[0xd90];
    MovieData_u1 *field_2908;
} MovieModule_u1;

void fn_12_20A7C(MovieModule_u1 *arg0, u8 *arg1, s32 arg2, s32 *arg3) {
    Movie_u1 *movie;
    s32 i;
    u8 *buf;
    s32 count;
    Movie_u1 *m;
    MovieData_u1 *data;
    void *entry;
    s32 result;

    *arg3 = 0;
    movie = arg0->field_1b74;
    if (fn_12_23F34((u32)arg0, (u32)arg1, (u32)arg2, (u32)arg3) >= 0x6c) {
        movie->field_003c = fn_12_20B90;
        return;
    } else {
        buf = arg1;
        i = 0;
        while (i < arg2 - 0x12) {
            if (memcmp((u32)buf, (u32)lbl_12_rodata_A50, 0x12) != 0) {
                movie->field_003c = fn_12_20B90;
                break;
            }
            buf += 0x12;
            i += 0x12;
        }
        *arg3 = i;
    }

    data = arg0->field_2908;
    m = arg0->field_1b74;
    if (data == 0) {
        entry = 0;
    } else if (m->field_0040 > 0) {
        entry = 0;
    } else {
        entry = (u8 *)data + 0xcfc;
    }
    if (entry == 0) {
        result = -1;
    } else {
        count = *(s32 *)((u8 *)entry + 0xc);
        result = 0;
    }
    if (result == 0) {
        movie->field_0038 = (u8 *)movie->field_0038
            + (i / (count * 0x12)) * 0x20;
    }
}
/* fzgx:end fn_12_20A7C */

/* fzgx:begin fn_12_20B90 noprologue */
#include "types.h"

/* sfadxt_ExcludeHdr, from the CC0 MK Deception decomp (sfd_adxt.c) */

typedef struct SJ SJ;

typedef struct AdxSjdHandle AdxSjdHandle;
typedef struct ADXStream ADXStream;
typedef struct AXRNAHandle AXRNAHandle;
typedef struct LSCObject LSCObject;
typedef struct ADX_AMP ADX_AMP;
typedef struct ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    AdxSjdHandle *decoder;
    ADXStream *stream;
    AXRNAHandle *rna;
    SJ *stream_sj;
    SJ *input_sj;
    SJ *output_sj[2];
    u8 *input_buffer;
    s32 input_buffer_size;
    s32 input_extra_size;
    u8 *output_buffer;
    s32 output_buffer_size;
    s32 output_buffer_distance;
    s32 server_frequency;
    s16 stream_buffer_sectors;
    s16 reload_threshold_sectors;
    s16 output_volume;
    s16 output_pan[2];
    s16 output_balance;
    s32 maximum_decode_samples;
    s32 loop_count;
    s32 loop_end_sector_bytes;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s16 error_code;
    u8 reserved_62[2];
    s32 field_64;
    s16 field_68;
    s16 field_6A;
    s8 stream_loop_enabled;
    s8 auto_receiver;
    u8 reserved_6E[2];
    s8 suppress_playback;
    s8 decoder_ready;
    s8 paused;
    u8 reserved_73;
    ADX_AMP *amplifier;
    SJ *amplifier_input[2];
    SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    LSCObject *linked_stream_controller;
    s8 link_enabled;
    u8 reserved_99[3];
    u32 playback_time;
    s32 playback_start_vsync;
    s32 linked_decoded_samples;
    s8 pending_stream_start;
    u8 reserved_A9[3];
    u8 *work_end;
    const char *pending_filename;
    void *pending_directory;
    s32 pending_file_offset;
    s32 pending_file_sectors;
} ADXTHandle;
typedef struct SfdHandle SfdHandle;
int fn_12_24A88(SfdHandle *handle, int error);
typedef struct SfdTransportInterface SfdTransportInterface;
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
/* GX's player handle predates MK Deception's layout; only the members used here are placed. */
struct SfdHandle {
    unsigned char unknown_0000[0x1AA0];
    SfdTransportState transports[9];
};
typedef struct SfdAdxtParameters {
    int stream_buffer_size;
    int stream_buffer_extra_size;
    void *stream_buffer;
    int maximum_channels;
    int decoder_work_size;
    int decoder_buffer_size;
    void *decoder_buffer;
} SfdAdxtParameters;
typedef void (*SfdAdxtCopyFn)(SfdHandle *handle, const unsigned char *data, int size,
                              int *consumed);
typedef struct SfdAdxtWork {
    ADXTHandle *decoder;
    SJ *stream_joint;
    SfdAdxtParameters para;
    int maximum_time_value;
    int maximum_time_scale;
    int paused;
    int discarded_samples;
    int header_inserted;
    int sample_offset;
    SfdAdxtCopyFn copy;
    int seek_depth;
    int server_frequency;
    int copied_bytes;
    int field_4C;
} SfdAdxtWork;
extern int fn_12_23F34(SfdHandle *handle);
extern int ADXT_IsHeader(const unsigned char *data, int size, int *header_size);
extern int ADXT_IsEndcode(const unsigned char *data, int size, int *end_size);
extern void fn_12_20CE8(SfdHandle *handle, const unsigned char *data, int size, int *consumed);

static inline SfdAdxtWork *sfadxt_GetWork(SfdHandle *handle) {
    return handle->transports[3].context;
}

static inline int sfadxt_SearchFrmTop(SfdHandle *handle, const unsigned char *data, int size) {
    const unsigned char *offset;
    const unsigned char *position;
    const unsigned char *end;
    const unsigned char *latest_offset;
    unsigned long latest_end_address;
    int found_end;
    const unsigned char *limit;
    found_end = 0;
    offset = data;
    latest_end_address = 0;
    end = data + size;
    latest_offset = 0;
    limit = data + 0x24;
    while (offset < limit) {
        position = offset;
        found_end = 0;
        while (position < end) {
            if ((signed char)*position < 0) {
                int end_size;
                found_end = 1;
                if (ADXT_IsEndcode(position, 0x12, &end_size) != 0 &&
                    latest_end_address < (unsigned long)position) {
                    latest_end_address = (unsigned long)position;
                    latest_offset = offset;
                }
                break;
            }
            position += 0x12;
        }
        if (found_end == 0) {
            break;
        }
        offset += 2;
    }
    if (found_end != 0) {
        if (latest_offset == 0) {
            fn_12_24A88(handle, 0xFF000C0A);
            offset = data;
        } else {
            offset = latest_offset;
        }
    }
    return offset - data;
}

#pragma use_lmw_stmw on
void fn_12_20B90(SfdHandle *handle, const unsigned char *data, int size, int *consumed) {
    SfdAdxtWork *work;
    int excluded;
    int header_size;
    *consumed = 0;
    work = sfadxt_GetWork(handle);
    if (size < 0x120) {
        return;
    }
    if (ADXT_IsHeader(data, size, &header_size) != 0) {
        excluded = header_size;
    } else if (fn_12_23F34(handle) >= 108) {
        excluded = 0;
    } else {
        excluded = sfadxt_SearchFrmTop(handle, data, size);
    }
    work->copy = fn_12_20CE8;
    *consumed = excluded;

}
/* fzgx:end fn_12_20B90 */

/* fzgx:begin fn_12_20CE8 noprologue */
#include "types.h"

/* sfadxt_AdjustSync, from the CC0 MK Deception decomp (sfd_adxt.c) */

typedef struct SJ SJ;

typedef struct AdxSjdHandle AdxSjdHandle;
typedef struct ADXStream ADXStream;
typedef struct AXRNAHandle AXRNAHandle;
typedef struct LSCObject LSCObject;
typedef struct ADX_AMP ADX_AMP;
typedef struct ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    AdxSjdHandle *decoder;
    ADXStream *stream;
    AXRNAHandle *rna;
    SJ *stream_sj;
    SJ *input_sj;
    SJ *output_sj[2];
    u8 *input_buffer;
    s32 input_buffer_size;
    s32 input_extra_size;
    u8 *output_buffer;
    s32 output_buffer_size;
    s32 output_buffer_distance;
    s32 server_frequency;
    s16 stream_buffer_sectors;
    s16 reload_threshold_sectors;
    s16 output_volume;
    s16 output_pan[2];
    s16 output_balance;
    s32 maximum_decode_samples;
    s32 loop_count;
    s32 loop_end_sector_bytes;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s16 error_code;
    u8 reserved_62[2];
    s32 field_64;
    s16 field_68;
    s16 field_6A;
    s8 stream_loop_enabled;
    s8 auto_receiver;
    u8 reserved_6E[2];
    s8 suppress_playback;
    s8 decoder_ready;
    s8 paused;
    u8 reserved_73;
    ADX_AMP *amplifier;
    SJ *amplifier_input[2];
    SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    LSCObject *linked_stream_controller;
    s8 link_enabled;
    u8 reserved_99[3];
    u32 playback_time;
    s32 playback_start_vsync;
    s32 linked_decoded_samples;
    s8 pending_stream_start;
    u8 reserved_A9[3];
    u8 *work_end;
    const char *pending_filename;
    void *pending_directory;
    s32 pending_file_offset;
    s32 pending_file_sectors;
} ADXTHandle;
typedef void *SfdCallbackObject;
typedef int SfdConditionValue;
typedef struct SfdHandle SfdHandle;
typedef int (*SfdUserIsSkipFn)(SfdHandle *handle, int picture_type, int value, int scale);
typedef int (*SfdTimeSourceFn)(SfdHandle *handle, int *value, int *scale);
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
    volatile int field_02CC; // fzgx-allow: S2 SDK state shared with the decoder/interrupt context
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
void fn_12_2E9E4(SfdTimerState *state, int value, int scale);
int fn_12_2E9F0(SfdTimerState *state, int sample_rate, int *using_time_unit);
unsigned int fn_12_2EA6C(SfdTimerState *state, int sample_rate);
typedef struct SfdTransportInterface SfdTransportInterface;
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
/* GX's player handle predates MK Deception's layout; only the members used here are placed. */
struct SfdHandle {
    unsigned char unknown_0000[0xCC0];
    SfdTimerState timer_state;
    unsigned char unknown_12A0[0x1AA0 - 0x12A0];
    SfdTransportState transports[9];
    unsigned char unknown_1D04[0x2908 - 0x1D04];
    SfdSeekState seek_state;
};
void fn_12_2D7DC(SfdHandle *handle, int condition, SfdConditionValue value);
SfdConditionValue fn_12_2D73C(SfdHandle *handle, int condition);
typedef struct SfdAdxtParameters {
    int stream_buffer_size;
    int stream_buffer_extra_size;
    void *stream_buffer;
    int maximum_channels;
    int decoder_work_size;
    int decoder_buffer_size;
    void *decoder_buffer;
} SfdAdxtParameters;
SfdConditionValue fn_12_2D73C(SfdHandle *handle, int condition);
typedef struct SfdAdxtSeekInfo {
    int ready;
    int byte_rate;
    int field_08;
    int channels;
    int sample_rate;
    int sample_count;
} SfdAdxtSeekInfo;
typedef void (*SfdAdxtCopyFn)(SfdHandle *handle, const unsigned char *data, int size,
                              int *consumed);
typedef struct SfdAdxtWork {
    ADXTHandle *decoder;
    SJ *stream_joint;
    SfdAdxtParameters para;
    int maximum_time_value;
    int maximum_time_scale;
    int paused;
    int discarded_samples;
    int header_inserted;
    int sample_offset;
    SfdAdxtCopyFn copy;
    int seek_depth;
    int server_frequency;
    int copied_bytes;
    int field_4C;
} SfdAdxtWork;
extern int ADXT_IsEndcode(const unsigned char *data, int size, int *end_size);
extern int ADXT_InsertSilence(ADXTHandle *decoder, int channels, int samples);
extern void fn_12_20F4C(SfdHandle *handle, const unsigned char *data, int size, int *consumed);

static inline SfdAdxtWork *sfadxt_GetWork(SfdHandle *handle) {
    return handle->transports[3].context;
}

static inline SfdAdxtSeekInfo *sfadxt_GetSeekInfo(SfdHandle *handle, SfdAdxtWork *work) {
    if (handle->seek_state.work == 0) {
        return 0;
    }
    if (work->seek_depth > 0) {
        return 0;
    }
    return (SfdAdxtSeekInfo *)((unsigned char *)handle->seek_state.work + 0xCFC);
}

static inline int sfadxt_GetAudioInf(SfdHandle *handle, int *channels, int *sample_rate) {
    SfdAdxtSeekInfo *seek = sfadxt_GetSeekInfo(handle, sfadxt_GetWork(handle));
    if (seek == 0) {
        return -1;
    }
    *channels = seek->channels;
    *sample_rate = seek->sample_rate;
    return 0;
}

static inline int sfadxt_SearchEndcode(const unsigned char *data, int limit, int *found_end) {
    const unsigned char *position;
    int scanned;
    int end_size;
    position = data;
    *found_end = 0;
    for (scanned = 0; scanned < limit; scanned += 0x12) {
        if (ADXT_IsEndcode(position, 0x12, &end_size) != 0) {
            *found_end = 1;
            break;
        }
        position += 0x12;
    }
    return scanned;
}

#pragma use_lmw_stmw on
void fn_12_20CE8(SfdHandle *handle, const unsigned char *data, int size, int *consumed) {
    int block_size;
    int bytes_per_frame;
    int excluded;
    int bytes_remaining;
    int channels;
    int found_end;
    SfdTimerState *timer;
    int video_start;
    int audio_start;
    int sample_rate;
    int scan_bytes;
    int available;
    int end_size;
    int using_time_unit;
    int difference;
    SfdAdxtWork *work;
    int inserted;
    int samples_remaining;
    *consumed = 0;
    timer = &handle->timer_state;
    work = sfadxt_GetWork(handle);
    if (sfadxt_GetAudioInf(handle, &channels, &sample_rate) != 0) {
        work->copy = fn_12_20F4C;
        return;
    }
    audio_start = fn_12_2EA6C(timer, sample_rate);
    if (audio_start < 0) {
        return;
    }
    if (fn_12_2D73C(handle, 5) == 0) {
        fn_12_2E9E4(timer, audio_start, sample_rate);
        work->copy = fn_12_20F4C;
        return;
    }
    video_start = fn_12_2E9F0(timer, sample_rate, &using_time_unit);
    if (video_start < 0) {
        return;
    }
    fn_12_2E9E4(timer, video_start, sample_rate);
    excluded = 0;
    difference = (video_start - audio_start) - work->sample_offset;
    if (difference >= 0) {
        found_end = 0;
        bytes_remaining = difference / 0x20 * channels * 0x12;
        if (bytes_remaining > 0) {
            bytes_per_frame = channels * 0x12;
            block_size = bytes_remaining;
            available = size / bytes_per_frame * channels * 0x12;
            if (available < bytes_remaining) {
                block_size = available;
            }
            scan_bytes = sfadxt_SearchEndcode(data, block_size, &found_end);
            work->sample_offset = work->sample_offset + scan_bytes / bytes_per_frame * 0x20;
            excluded = scan_bytes;
            bytes_remaining -= block_size;
        }
        if (bytes_remaining <= 0 && using_time_unit != 0) {
            work->copy = fn_12_20F4C;
            found_end = ADXT_IsEndcode(data, size, &end_size);
        }
        if (found_end != 0) {
            fn_12_2D7DC(handle, 6, 0);
        }
    } else {
        if (using_time_unit != 0) {
            samples_remaining = (-difference) / 0x20 * 0x20;
            if (samples_remaining > 0) {
                inserted =
                    ADXT_InsertSilence(sfadxt_GetWork(handle)->decoder, channels, samples_remaining);
                samples_remaining -= inserted;
                work->sample_offset -= inserted;
            }
            if (samples_remaining <= 0) {
                work->copy = fn_12_20F4C;
            }
        }
    }
    *consumed = excluded;
}
/* fzgx:end fn_12_20CE8 */

/* fzgx:begin fn_12_20F4C noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_20F4C.c --- */
extern void *fn_12_57F0(void *value, const void *unused, u32 frames);
extern void fn_800589BC(int *a, int frames, int *b, int *c);

typedef void (*MoviePrepareFn)(void *, int, int, void *);
typedef void (*MovieUpdateFn)(void *, int, void *);
typedef void (*MovieProcessFn)(void *, int, void *);

typedef struct MovieVTable {
    void *unused[6];
    MoviePrepareFn prepare;
    MovieUpdateFn update;
    MovieProcessFn process;
} MovieVTable;

typedef struct MovieData {
    MovieVTable *vtable;
} MovieData;

typedef struct MovieState {
    char pad0000[4];
    MovieData *movie;
    int field8;
    char pad000c[0x3c];
    int elapsed;
} MovieState;

typedef struct MovieModule {
    char pad0000[0x1b74];
    MovieState *state;
} MovieModule;

void fn_12_20F4C(MovieModule *module, void *unused, int frames, int *result) {
    int local8;
    f64 local10;
    int frame_count = frames;
    MovieState *state = module->state;
    MovieData *movie = state->movie;
    int duration;
    void *value;
    int *words;

    movie->vtable->prepare(movie, 0, state->field8, &local10);
    words = (int *)&local10;
    value = (void *)words[0];
    duration = words[1];
    if (frame_count < duration) {
        duration = frame_count;
    }
    frame_count = 0x19000;
    if (duration < frame_count) {
        frame_count = duration;
    }

    fn_12_57F0(value, unused, frame_count);
    if (frame_count == 0) {
        movie->vtable->update(movie, 0, &local10);
    } else {
        fn_800589BC((int *)&local10, frame_count, (int *)&local10, &local8);
        movie->vtable->process(movie, 1, &local10);
        movie->vtable->update(movie, 0, &local8);
    }
    state->elapsed += frame_count;
    *result = frame_count;
}
/* fzgx:end fn_12_20F4C */

/* fzgx:begin fn_12_2105C noprologue */

/* --- rel/movie_module/fn_12_2105C.c --- */
typedef struct MovieModule_u1 MovieModule_u1;
typedef void (*MovieReadFn)(MovieModule_u1 *, int, int, int *);

typedef struct MovieState_u1 {
    void *movie;
    u8 pad04[0x38];
    MovieReadFn read;
    int field40;
    int field44;
    int field48;
} MovieState_u1;

typedef struct MovieInfo {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
} MovieInfo;

struct MovieModule_u1 {
    u8 pad0000[0xe70];
    int fieldE70;
    int fieldE74;
    u8 padE78[0x1b74 - 0xe78];
    MovieState_u1 *state;
    int field1b78;
    int field1b7c;
    int field1b80;
    u8 pad1b84[0x2908 - 0x1b84];
    u8 *field2908;
};

extern int fn_12_2D73C(MovieModule_u1 *, int);
extern int fn_12_21D30(MovieModule_u1 *, int);
extern int fn_12_22390(MovieModule_u1 *, int, int *);
extern int fn_12_22008(MovieModule_u1 *, int, int);
extern int fn_12_21D50(MovieModule_u1 *, int);
extern void fn_12_21D60(MovieModule_u1 *, int, int);
extern int lbl_12_bss_698C;
extern int fn_12_24A88(MovieModule_u1 *, int);
extern void fn_12_309B0(void *, int);
extern void fn_12_21D40(MovieModule_u1 *, int, int);
extern int fn_12_23078(MovieModule_u1 *, int, int);
extern int fn_8004C658(void *);
extern int fn_8004BD9C(void *);
extern int fn_8004C0B4(void *);
extern int fn_8004C10C(void *);
extern int fn_8004C05C(void *);
extern int fn_8004BE98(void *, int);

static inline int step1(MovieModule_u1 *m, int *out) {
    MovieState_u1 *s = m->state;
    int pair[6];
    int loc8;
    int r;
    int a;
    int b;

    *out = 0;
    r = fn_12_22390(m, m->field1b7c, pair);
    a = pair[0];
    b = pair[1];
    if (r != 0) {
        return r;
    }
    *out = b;
    s->read(m, a, b, &loc8);
    r = fn_12_22008(m, m->field1b7c, loc8);
    a = 0;
    if (r != 0) {
        a = r;
    }
    if (a != 0) {
        return a;
    }
    return a;
}

static inline int isThree(MovieModule_u1 *m) {
    return fn_8004C658(m->state->movie) == 3;
}

static inline void step2(MovieModule_u1 *m) {
    int b;
    int a;

    a = m->field1b80;
    b = m->field1b7c;
    if (fn_12_21D50(m, a) != 1 && fn_12_21D50(m, b) == 1) {
        int three = isThree(m);
        if (three) {
            fn_12_21D60(m, a, 1);
        }
    }
}

static inline void step3(MovieModule_u1 *m, int flag) {
    MovieState_u1 *s = m->state;
    void *movie = s->movie;
    int st;
    int err;
    void *obj = (u8 *)m + 0xf60;

    st = fn_8004C658(movie);
    err = fn_8004BD9C(movie);
    (void) err;  /* fzgx: keeps the web at its definition */
    if (err != 0) {
        lbl_12_bss_698C = err;
    }
    if (fn_12_2D73C(m, 0x1a) == 0) {
        err = 0;
    }
    switch (err) {
    case -1:
        fn_12_24A88(m, 0xff000c08);
        break;
    case -2:
        fn_12_24A88(m, 0xff000c09);
        break;
    case 0:
        break;
    default:
        fn_12_24A88(m, 0xff000c07);
        break;
    }
    if (st == 4 || st == 5) {
        fn_12_309B0(obj, 0);
    }
    if (st == 5 || err != 0) {
        fn_12_21D40(m, m->field1b80, 1);
    }
    if (fn_12_21D30(m, m->field1b7c) == 1 && flag == 0 && s->field48 == 0) {
        fn_12_21D40(m, m->field1b80, 1);
    }
}

static inline MovieInfo *getInfo(MovieModule_u1 *m, MovieState_u1 *s) {
    if (m->field2908 == 0) {
        return 0;
    }
    if (s->field40 > 0) {
        return 0;
    }
    return (MovieInfo *)(m->field2908 + 0xcfc);
}

static inline int isPlaying(void *movie) {
    int t = fn_8004C658(movie);
    if (t == 0 || t == 1) {
        return 0;
    }
    return 1;
}

static inline void step4(MovieModule_u1 *m) {
    MovieState_u1 *s = m->state;
    MovieInfo *p = getInfo(m, s);

    if (p != 0 && p->field0 == 0) {
        void *movie = s->movie;
        if (isPlaying(movie)) {
            p->field10 = fn_8004C0B4(movie);
            p->field14 = fn_8004C10C(movie);
            p->fieldC = fn_8004C05C(movie);
            p->field4 = p->field10 * p->fieldC * 9 / 16;
            p->field8 = 1;
            p->field0 = 1;
        }
    }
}

static inline void step5(MovieModule_u1 *m) {
    MovieState_u1 *s = m->state;
    void *movie = s->movie;
    int v = fn_12_2D73C(m, 0x1b);

    if (s->field44 != v) {
        s->field44 = v;
        fn_8004BE98(movie, v);
    }
}

static inline void step6(MovieModule_u1 *m) {
    void *movie = m->state->movie;

    if (m->fieldE70 == m->fieldE74) {
        int h = fn_8004C10C(movie);
        int w = fn_8004C0B4(movie);
        if (h > 0 && w > 0) {
            fn_12_23078(m, h, w);
        }
    }
}

#pragma opt_common_subs off
int fn_12_2105C(MovieModule_u1 *m) {
    int flag;
    int result;

    if (fn_12_2D73C(m, 6) == 0) {
        return 0;
    }
    if (fn_12_21D30(m, m->field1b80) == 1) {
        return 0;
    }
    result = step1(m, &flag);
    if (result != 0) {
    }
    step2(m);
    step3(m, flag);
    step4(m);
    step5(m);
    step6(m);
    return result;
}
#pragma opt_common_subs reset
/* fzgx:end fn_12_2105C */

/* fzgx:begin fn_12_213D8 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_213D8.c --- */
extern void fn_12_2105C(void);

void fn_12_213D8(void) {
    fn_12_2105C();
}
/* fzgx:end fn_12_213D8 */

/* fzgx:begin fn_12_213F8 noprologue */

/* --- rel/movie_module/fn_12_213F8.c --- */
extern void fn_80047834(void);
extern void ADXT_Finish(void);

int fn_12_213F8(void) {
    fn_80047834();
    ADXT_Finish();
    return 0;
}
/* fzgx:end fn_12_213F8 */

/* fzgx:begin fn_12_21420 noprologue */

/* --- rel/movie_module/fn_12_21420.c --- */
extern void fn_800411F4(void);
extern void fn_8004784C(void);
extern u32 lbl_12_bss_6990[8];
extern void fn_12_33428(u32 *, int, int);

int fn_12_21420(void) {
    fn_800411F4();
    fn_8004784C();
    fn_12_33428(lbl_12_bss_6990, 0, 7);
    return 0;
}
/* fzgx:end fn_12_21420 */

/* fzgx:begin fn_12_2145C noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_2145C.c --- */
extern struct fn_12_2145C_lbl_12_bss_6990 lbl_12_bss_6990;

struct fn_12_2145C_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};
struct fn_12_2145C_lbl_12_bss_6990 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

u32 fn_12_2145C(struct fn_12_2145C_Arg0 *arg0) {
    lbl_12_bss_6990.unk_0 = arg0->unk_0;
    lbl_12_bss_6990.unk_4 = arg0->unk_4;
    lbl_12_bss_6990.unk_8 = ((arg0->unk_8 + 31) & ~0x1F);
    lbl_12_bss_6990.unk_C = arg0->unk_C;
    lbl_12_bss_6990.unk_10 = arg0->unk_10;
    lbl_12_bss_6990.unk_14 = arg0->unk_14;
    lbl_12_bss_6990.unk_18 = ((arg0->unk_18 + 31) & ~0x1F);
    return arg0->unk_18;
}
/* fzgx:end fn_12_2145C */

/* fzgx:begin fn_12_214B0 noprologue */

/* --- rel/movie_module/fn_12_214B0.c --- */
typedef struct MovieInner {
    void *value;
} MovieInner;

typedef struct Movie {
    u8 pad_0000[0x1b74];
    MovieInner *inner;
} Movie;
extern const f32 lbl_12_rodata_A68;
extern const f32 lbl_12_rodata_A64;
extern const f32 lbl_12_rodata_A6C;

extern f64 fn_80088558(Movie *movie, f64 value);
extern void fn_8004BBC8(void *value, int minutes, int seconds);

void fn_12_214B0(Movie *movie, int value) {
    f32 elapsed;
    f32 scaled;
    int minutes;
    int seconds;

    elapsed = (f32)fn_80088558(movie, (f64)value);
    scaled = elapsed - lbl_12_rodata_A68;
    scaled = lbl_12_rodata_A64 * scaled;
    minutes = (int)(lbl_12_rodata_A6C * scaled);
    seconds = (int)scaled - minutes * 100;
    fn_8004BBC8(movie->inner->value, minutes, seconds);
}
/* fzgx:end fn_12_214B0 */

/* fzgx:begin fn_12_21554 noprologue */

/* --- rel/movie_module/fn_12_21554.c --- */
/* --- rel/movie_module/fn_12_21554.c --- */

extern void fn_8004BED0(void *value);

void fn_12_21554(Movie *movie) {
    fn_8004BED0(movie->inner->value);
}
/* fzgx:end fn_12_21554 */

/* fzgx:begin fn_12_2157C noprologue */

/* --- rel/movie_module/fn_12_2157C.c --- */
typedef struct MovieModule {
    char _pad[0x1b74];
    void *movie;
} MovieModule;

extern void fn_8004BF0C(void *movie);

void fn_12_2157C(MovieModule *self) {
    fn_8004BF0C(*(void **)self->movie);
}
/* fzgx:end fn_12_2157C */

/* fzgx:begin fn_12_215A4 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_215A4.c --- */
typedef struct MovieModule {
    u8 pad_0[0x1b74];
    void **movie;
} MovieModule;

extern void fn_8004BF68(void *);

void fn_12_215A4(MovieModule *this) {
    fn_8004BF68(*this->movie);
}
/* fzgx:end fn_12_215A4 */

/* fzgx:begin fn_12_215CC noprologue */

/* --- rel/movie_module/fn_12_215CC.c --- */
/* --- rel/movie_module/fn_12_215CC.c --- */
typedef struct MovieModule_u1 {
    u8 pad_0[0x1b74];
    void *field_1b74;
} MovieModule_u1;

extern void ADXT_SetOutPan(void *);

void fn_12_215CC(MovieModule_u1 *movie) {
    ADXT_SetOutPan(*(void **)movie->field_1b74);
}
/* fzgx:end fn_12_215CC */

/* fzgx:begin fn_12_215F4 noprologue */

/* --- rel/movie_module/fn_12_215F4.c --- */
extern u32 lbl_12_rodata_A78;
extern u32 strncmp(u32, void *, u32);

struct fn_12_215F4_Arg2 {
    u32 unk_0;
};

u32 fn_12_215F4(u32 arg0, u32 arg1, struct fn_12_215F4_Arg2 *arg2) {
    u32 v0;
    u32 t0;
    arg2->unk_0 = 288;
    v0 = arg0;
    if ((s32)arg1 < 288) {
    v0 = 0;
    } else {
    if (*(u8 *)((u8 *)v0 + 0) != 128) {
    v0 = 0;
    } else {
    if (*(u8 *)((u8 *)v0 + 1) != 0) {
    v0 = 0;
    } else {
    v0 += 282;
    t0 = strncmp(v0, &lbl_12_rodata_A78, 6);
    v0 = t0;
    v0 = ((u32)__cntlzw(v0) >> 5);
    }
    }
    }
    return v0;
}
/* fzgx:end fn_12_215F4 */
