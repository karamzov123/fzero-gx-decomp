#include "types.h"

/* sfmpv_DoReformTc (sfd_mpv.c, CRI Sofdec), GX version */

typedef struct SfdTimeCode {
    int frame_rate_code;
    int drop_frame;
    int hours;
    int minutes;
    int seconds;
    int frames;
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
    SfdMpvTimeCodeSnapshot maximum;
} SfdMpvDecodeTimer;

typedef struct MPVPictureInfo {
    int width;
    int height;
    int macroblocks_per_row;
    int macroblock_rows;
    int frame_rate_code;
    int temporal_reference;
    int picture_type;
    int drop_frame_flag;
    int time_code_hours;
    int time_code_minutes;
    int time_code_seconds;
    int time_code_pictures;
} MPVPictureInfo;

typedef struct SfdHandle {
    unsigned char reserved_0000[0xCC0];
    SfdMpvDecodeTimer timer_state;
    unsigned char reserved_0D2C[0x1BDC];
    void *seek_work;
} SfdHandle;

extern const int lbl_12_rodata_C10[]; /* sfmpv_fps_round */
extern void fn_12_2814C(int pts, int frame_rate, int drop_frame, int temporal_reference,
                        SfdTimeCode *timecode);

static inline void sfmpv_SetPicTc(MPVPictureInfo *picture, SfdTimeCode *timecode) {
    picture->time_code_hours = timecode->hours;
    picture->time_code_minutes = timecode->minutes;
    picture->time_code_seconds = timecode->seconds;
    picture->time_code_pictures = timecode->frames;
}

void fn_12_28304(SfdHandle *handle, MPVPictureInfo *picture, int pts, int group_changed) {
    int frame_rate;
    int fps_round;
    SfdTimeCode timecode;
    int minutes;
    int frame;
    struct { int value; } seconds;
    SfdTimeCode *source;
    int drop_frame;
    int temporal_reference;
    SfdMpvDecodeTimer *timer;
    int hours;
    int lab_t2;
    timer = &handle->timer_state;
    source = &timer->maximum.timecode;
    frame_rate = picture->frame_rate_code;
    drop_frame = picture->drop_frame_flag;
    temporal_reference = picture->temporal_reference;

    if (group_changed != 0 && pts >= 0) {
        lab_t2 = drop_frame;
        fn_12_2814C(pts, frame_rate, lab_t2, temporal_reference, &timecode);
        sfmpv_SetPicTc(picture, &timecode);
    } else if (timer->maximum.valid == 0) {
        if (handle->seek_work == 0) {
            picture->drop_frame_flag = 0;
            picture->time_code_hours = 0;
            picture->time_code_minutes = 0;
            picture->time_code_seconds = 0;
            picture->time_code_pictures = 0;
        } else {
            return;
        }
    } else if (group_changed != 0) {
        fps_round = lbl_12_rodata_C10[frame_rate];
        lab_t2 = source->frames + source->frame_offset + 1;
        frame = lab_t2;
        hours = source->hours;
        minutes = source->minutes;
        seconds.value = source->seconds;
        seconds.value += frame / fps_round;
        frame %= fps_round;
        minutes += seconds.value / 60;
        seconds.value %= 60;
        hours += minutes / 60;
        minutes %= 60;
        if (drop_frame != 0 && seconds.value == 0 && minutes % 10 != 0 && (frame == 0 || frame == 1)) {
            frame = 2;
        }
        timecode.hours = hours;
        timecode.minutes = minutes;
        timecode.seconds = seconds.value;
        timecode.frames = frame;
        sfmpv_SetPicTc(picture, &timecode);
    } else {
        sfmpv_SetPicTc(picture, source);
    }
}

typedef char HandleCheck[(int)&((SfdHandle *)0)->seek_work == 0x2908 ? 1 : -1];
