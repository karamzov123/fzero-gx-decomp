#include "types.h"

/* --- rel/movie_module/fn_12_27478.c --- */
/* sfmpv_DecodeFrm (sfd_mpv.c, CRI Sofdec), GX layout */

typedef struct SJ SJ;
typedef struct MPVContext MPVContext;

typedef struct SfdTimeCode {
    int fields[6];
    int frame_offset;
} SfdTimeCode;

typedef struct SfdMpvTimeCodeSnapshot {
    int valid;
    SfdTimeCode timecode;
    int value;
    int scale;
} SfdMpvTimeCodeSnapshot;

typedef struct SfdMpvDecodeTimer {
    unsigned char reserved_000[0x1C];
    SfdMpvTimeCodeSnapshot initial;
    unsigned char reserved_044[0x50];
    SfdMpvTimeCodeSnapshot current;
    unsigned char reserved_0BC[0x28];
    SfdMpvTimeCodeSnapshot output_start;
    unsigned char reserved_10C[0x14];
    int field_120;
} SfdMpvDecodeTimer;

typedef struct SfdMpvPictureUserData {
    void *buffer;
    int size;
} SfdMpvPictureUserData;

typedef struct SfdMpvFrame {
    int state;
    void *frame_buffer;
    int display_time_value;
    int display_time_scale;
    int field_40;
    int field_44;
    int picture_order;
    int field_4C;
    int field_50;
    SfdMpvPictureUserData *picture_user_buffer;
    unsigned int picture_info[20];
} SfdMpvFrame;

typedef struct MPVPictureInfo {
    int fields_00[6];
    int picture_type;
    int fields_1C[6];
    int field_38;
} MPVPictureInfo;

typedef struct MPVFrameBuffers {
    int planes[10];
    int decoded_dct_count;
    int skipped_dct_count;
} MPVFrameBuffers;

typedef struct SfdMpvFrameWork {
    MPVContext *decoder;
    unsigned char reserved_004[0x70];
    int decode_state;
    unsigned char reserved_078[0xC];
    int field_084;
    int field_088;
    MPVPictureInfo picture_info;
    unsigned char reserved_0C4[0x6C];
    SfdMpvFrame *pending_frame;
    unsigned char reserved_134[0x790];
    void *picture_buffer;
    int picture_buffer_size;
} SfdMpvFrameWork;

typedef struct SfdTimerSummary {
    int fields[8];
} SfdTimerSummary;

typedef struct SfdHandle {
    unsigned char reserved_0000[0x38];
    int video_output_format;
    unsigned char reserved_003C[0x918];
    int runtime_field_08;
    int runtime_field_0C;
    unsigned char reserved_095C[0x3C];
    int error_field_0C;
    int error_field_10;
    unsigned char reserved_09A0[0x10];
    int conditions_primary_4;
    unsigned char reserved_09B4[0x30C];
    SfdMpvDecodeTimer timer_state;
    unsigned char reserved_0DE4[0x11C];
    int latest_time_value;
    int latest_time_scale;
    unsigned char reserved_0F08[0xC28];
    SfdMpvFrameWork *video_work;
    int video_field_1B34;
    int video_parameter;
    unsigned char reserved_1B3C[0xDDC];
    SfdTimerSummary timer_summaries[4];
} SfdHandle;

extern int fn_12_27224(SfdHandle *handle, MPVPictureInfo *picture, MPVFrameBuffers *buffers,
                       SfdMpvFrame **frame);
extern void *memcpy(void *, const void *, unsigned long);
extern void fn_12_2E374(SfdTimeCode *timecode, int *value, int *scale);
extern unsigned long long fn_12_335B8(void);
extern int fn_80057D88(SJ *stream, int channel, int type);
extern int fn_12_A858(MPVContext *decoder, SJ *stream, MPVFrameBuffers *buffers);
extern void SFTMR_AddTsum(SfdTimerSummary *summary, unsigned long long time);
extern int fn_12_24A88(SfdHandle *handle, int error);
extern void fn_12_21E20(SfdHandle *handle, int parameter, int consumed);
extern void fn_12_2AB54(SfdMpvFrame *frame);
extern void fn_12_2AC80(SfdHandle *handle, int state);
extern void fn_12_2AB2C(SfdMpvFrame *frame);
extern void fn_12_2AB40(SfdMpvFrame *frame);
extern void fn_12_CCB0(MPVContext *decoder, int *decoded, int *skipped);
extern void fn_12_2BA6C(SfdHandle *handle, int count, int picture_type);

static inline void sfmpv_SetVofst(SfdHandle *handle) {
    SfdMpvDecodeTimer *timer = &handle->timer_state;
    SfdMpvTimeCodeSnapshot *initial = &timer->initial;
    SfdMpvTimeCodeSnapshot *output_start = &timer->output_start;
    int mode;
    SfdMpvTimeCodeSnapshot *current = &timer->current;

    if (output_start->valid == 0) {
        SfdTimeCode timecode = current->timecode;
        SfdMpvFrameWork *work = handle->video_work;
        int value;
        int scale;

        mode = 0;
        switch (work->decode_state) {
        case 2:
            mode = 1;
            break;
        case 3:
            mode = 1;
            break;
        case 4:
            mode = 0;
            break;
        case 5:
            break;
        default:
            break;
        }
        if (mode == 0 && handle->conditions_primary_4 != 0) {
            timecode.frame_offset = 0;
        }
        fn_12_2E374(&timecode, &value, &scale);
        output_start->timecode = timecode;
        output_start->value = value - initial->value;
        output_start->scale = scale;
        output_start->valid = 1;
    }
}

static inline int sfmpv_ChkDecRet(SfdHandle *handle, int result, int consumed, int error_code) {
    int error;
    switch (result) {
    case 0:
        error = 0;
        break;
    case -2:
        if (consumed > 0) {
            error = 0;
        } else {
            error = fn_12_24A88(handle, -2);
        }
        break;
    case -3:
        if (consumed > 0) {
            error = 0;
        } else {
            error = fn_12_24A88(handle, -3);
        }
        break;
    case -1:
    default:
        error = fn_12_24A88(handle, error_code);
        break;
    }
    return error;
}

static inline void sfmpv_SetFrmTime(SfdHandle *handle, SfdMpvFrame *frame) {
    SfdMpvDecodeTimer *timer = &handle->timer_state;
    frame->display_time_scale = timer->current.scale;
    frame->display_time_value = timer->field_120 + (timer->current.value - timer->output_start.value);
    frame->field_4C = timer->current.value;
    frame->field_50 = timer->current.value + timer->field_120;
    if (handle->latest_time_value < frame->display_time_value) {
        handle->latest_time_value = frame->display_time_value;
        handle->latest_time_scale = frame->display_time_scale;
    }
}

int fn_12_27478(SfdHandle *handle, SJ *stream) {
    int result;
    int flow_before;
    int consumed;
    SfdMpvFrameWork *work;
    MPVContext *decoder;
    MPVPictureInfo *picture;
    MPVFrameBuffers buffers;
    SfdMpvFrame *frame;
    unsigned long long start;
    int error;

    work = handle->video_work;
    picture = &work->picture_info;
    decoder = work->decoder;
    if (fn_12_27224(handle, picture, &buffers, &frame) != 0) {
        return 0;
    }
    if (work->picture_buffer_size > 0) {
        memcpy(frame->picture_user_buffer->buffer, work->picture_buffer, work->picture_buffer_size);
        frame->picture_user_buffer->size = work->picture_buffer_size;
    }
    sfmpv_SetVofst(handle);

    start = fn_12_335B8();
    flow_before = fn_80057D88(stream, 0, 1);
    result = fn_12_A858(decoder, stream, &buffers);
    consumed = fn_80057D88(stream, 0, 1) - flow_before;
    SFTMR_AddTsum(&handle->timer_summaries[picture->picture_type], fn_12_335B8() - start);
    handle->error_field_0C += buffers.decoded_dct_count;
    handle->error_field_10 += buffers.skipped_dct_count;
    error = sfmpv_ChkDecRet(handle, result, consumed, 0xFF000F06);
    fn_12_21E20(handle, handle->video_parameter, consumed);
    if (error != 0) {
        fn_12_2AB54(frame);
        return error;
    }
    if (consumed > 0) {
        fn_12_2AC80(handle, 0);
        sfmpv_SetFrmTime(handle, frame);
        frame->picture_order = work->field_088;
        frame->field_40 = buffers.decoded_dct_count;
        frame->field_44 = buffers.skipped_dct_count;
        if (picture->field_38 != 3 && work->pending_frame == 0) {
            work->pending_frame = frame;
        } else {
            work->pending_frame = 0;
        }
        if (work->pending_frame == 0) {
            if (handle->video_output_format == 3 &&
                (picture->picture_type == 1 || picture->picture_type == 2)) {
                fn_12_2AB2C(frame);
            } else {
                fn_12_2AB40(frame);
            }
            fn_12_CCB0(decoder, &handle->runtime_field_08, &handle->runtime_field_0C);
            fn_12_2BA6C(handle, 1, picture->picture_type);
            work->field_084 = 0;
        }
    } else if (work->pending_frame == 0) {
        fn_12_2AB54(frame);
    }
    return 0;
}

typedef char SfdHandleCheck[(int)&((SfdHandle *)0)->timer_summaries == 0x2918 ? 1 : -1];
typedef char SfdWorkCheck[(int)&((SfdMpvFrameWork *)0)->picture_buffer == 0x8C4 ? 1 : -1];

/* --- rel/movie_module/fn_12_27884.c --- */
typedef struct MovieTimeCode {
    int valid;
    u8 pad_04[0x1C];
    int value;
    int scale;
} MovieTimeCode;
typedef struct MovieDecodeTimer {
    u8 pad_00[0x94];
    MovieTimeCode current;
    u8 pad_bc[0x28];
    MovieTimeCode output_start;
} MovieDecodeTimer;
struct fn_12_27884_Arg0 {
    u8 pad_0[0xCC0];
    MovieDecodeTimer timer;
    u8 pad_dcc[0x1B30 - 0xDCC];
    u32 unk_1B30;
};
typedef struct fn_12_27884_Arg0 MovieModule;
#define I(p, o) (*(int *)((u8 *)(p) + (o)))
#define U(p, o) (*(u32 *)((u8 *)(p) + (o)))
extern int fn_12_332DC(int, int, int, int);
extern u32 fn_12_2D73C(u8 *, int);
extern int fn_12_A374(int, int, int);
extern void fn_12_2EDAC(void *, int);
extern int fn_12_2ED74(void *, int);
extern int fn_12_2DAB4(MovieModule *);
extern int fn_12_2E714(MovieModule *, int *, int *);
extern int fn_12_A9C4(void *, int *, int *);
typedef int (*MovieCallback)(MovieModule *, int, int, int);

static inline int ready(MovieModule *movie) {
    MovieDecodeTimer *timer = &movie->timer;
    MovieTimeCode *current = &timer->current;
    MovieTimeCode *output_start = &timer->output_start;
    if (I(movie, 0x2910) < 0) return 0;
    if (output_start->valid != 0) return 0;
    if (fn_12_332DC(I(movie, 0x2910), I(movie, 0x2914), current->value, current->scale) != 0) return 0;
    return 1;
}
#pragma peephole off
static inline int missing(MovieModule *movie, int mode) {
    int value;
    switch (mode) {
    case 1: value = I(movie, 0x9a8); break;
    case 2: value = I(movie, 0x9ac); break;
    case 3: value = I(movie, 0x9b0); break;
    default: return 1;
    }
    if (value == 0) return 1;
    return 0;
}
#pragma peephole reset

static inline int check_input(MovieModule *movie, int *input, int mode) {
    int result;
    if (mode != 3) return 0;
    if ((int)fn_12_2D73C((u8 *)movie, 7) != 0) return 0;
    result = fn_12_A374(input[0], input[1], I(movie, 0x914) * I(movie, 0x918));
    if (0 != result) I(movie, 0x95c)++;
    return result;
}
static inline int check_state(MovieModule *movie, int mode) {
    void *work = (void *)movie->unk_1B30;
    int state = I(work, 0x74);
    int result = 0;
    switch (state) {
    case 2:
        if (mode == 2 || mode == 3) result = 1;
        break;
    case 3:
        if (mode == 3) result = 1;
        break;
    case 4:
        result = 0;
        break;
    case 5:
    default:
        break;
    }
    return result;
}
static inline int check_time(MovieModule *movie, int mode) {
    void *data = (void *)movie->unk_1B30;
    int time;
    int duration;
    u8 *p = (u8 *)movie + 0xcc0;
    MovieCallback callback;
    struct { int value; } state;
    int value;
    if (I(p, 0xe4) == 0) time = 0;
    else time = I(p, 0x120) + (I(p, 0xb4) - I(p, 0x104));
    callback = *(MovieCallback *)(p + 0x18);
    duration = I(p, 0xb8);
    if (callback != 0) return callback(movie, mode, time, duration);
    if (mode == 1) fn_12_2EDAC(p, time);
    if (mode == 1 || mode == 2) time = fn_12_2ED74(p, time);
    if (fn_12_2DAB4(movie) <= 1000 && I(data, 0x84) >= I(movie, 0xa38)) return 0;
    fn_12_2E714(movie, &state.value, &value);
    if (state.value < 0) return 0;
    time -= duration * I(movie, 0xa48) / I(movie, 0xa4c);
    if (fn_12_332DC(state.value, value, time, duration) != 0) return 0;
    I(data, 0x84)++;
    return 1;
}
static inline void update_pic_stat(MovieModule *movie, void *v0, int skip) {
    void *work = (void *)movie->unk_1B30;
    void *decoder = *(void **)work;
    int state = I(work, 0x74);
    if (I(work, 0xe0) != 0) {
        int a;
        int b;
        fn_12_A9C4(decoder, &a, &b);
        if (a == 0 && b == 1) state = 2;
        if (a == 1) state = 5;
    }
    if (skip == 1) {
        if (I(v0, 0xa4) == 1 || I(v0, 0xa4) == 2) state = 2;
    } else {
        if (state == 2) state = 3;
        else if (state == 3) state = 5;
    }
    I(work, 0x74) = state;
}

#pragma opt_propagation off
int fn_12_27884(MovieModule *arg0, int *arg1) {
    void *v0;
    int v4;
    int v3;
    v0 = (void *)arg0->unk_1B30;
    if ((int)fn_12_2D73C((u8 *)arg0, 47) == 1) return 1;
    if ((int)fn_12_2D73C((u8 *)arg0, 39) == 1) return 0;
    if (U(v0, 0x130) != 0) return 0;
    v3 = I(v0, 0xa4);
    if (ready(arg0)) v4 = 1;
    else if (missing(arg0, v3)) v4 = 1;
    else if (check_input(arg0, arg1, v3)) v4 = 1;
    else if (check_state(arg0, v3)) v4 = 1;
    else if (check_time(arg0, v3)) v4 = 1;
    else v4 = 0;
    update_pic_stat(arg0, v0, v4);
    return v4;
}
#pragma opt_propagation reset
