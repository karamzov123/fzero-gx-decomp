#include "types.h"

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
