#include "types.h"
#include "sofdec/sj.h"

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
    int unk_30;
} MPVPictureInfo;

/* the 12-byte entry fn_12_2CDD0 fills */
typedef struct Entry {
    int unk_0;
    int unk_4;
    int unk_8;
} Entry;

typedef struct SfdMpvFrameWork {
    void *decoder;
    u8 unk_004[0x84];
    int unk_88;
    MPVPictureInfo picture_info;
    u8 unk_0C0[0x1C];
    int unk_DC;
    int unk_E0;
    int unk_E4;
    int unk_E8;
    int unk_EC;
    int unk_F0;
    Entry unk_F4;
    u8 unk_100[0x7C0];
    void *picture_buffer;
    int picture_buffer_size;
    int unk_8C8;
} SfdMpvFrameWork;

typedef struct SfdPlaybackSettings {
    int unk_0;
    int unk_4;
    int unk_8;
    int unk_C;
    int unk_10;
    int frame_rate_code;
    u8 unk_18[8];
    int unk_20;
} SfdPlaybackSettings;

typedef struct SeekBuffer {
    u8 unk_0[0x200];
    int unk_200;
} SeekBuffer;

typedef struct SeekEntry {
    int unk_0;
    int unk_4;
    int unk_8;
    SfdMpvTimeCodeSnapshot unk_C;
    SeekBuffer unk_34;
} SeekEntry;

typedef struct SeekWork {
    u8 unk_0[0xAC4];
    SeekEntry unk_AC4;
} SeekWork;

typedef struct SfdMpvDecodeTimer {
    u8 unk_000[0x1C];
    SfdMpvTimeCodeSnapshot initial;
    SfdMpvTimeCodeSnapshot maximum;
    u8 unk_06C[0x28];
    SfdMpvTimeCodeSnapshot current;
    u8 unk_0BC[0x58];
} SfdMpvDecodeTimer;

typedef struct SfdHandle {
    u8 unk_0000[0x90C];
    SfdPlaybackSettings playback_settings;
    u8 unk_0930[0x390];
    SfdMpvDecodeTimer timer_state;
    int unk_DD4;
    u8 unk_0DD8[0xD58];
    SfdMpvFrameWork *video_work;
    int unk_1B34;
    int video_parameter;
    u8 unk_1B3C[0xDCC];
    SeekWork *seek_work;
} SfdHandle;

extern void fn_12_CA84(void *decoder, int size, void *buffer);
extern void fn_12_CA60(void *decoder, int *a, int *b);
extern int fn_12_C2C8(void *decoder, SJ *stream);
extern int fn_80057D88(SJ *stream, int channel, int type);
extern int fn_12_24A88(SfdHandle *handle, int error);
extern void fn_12_21E20(SfdHandle *handle, int parameter, int consumed);
extern int fn_12_AB60(void *decoder, MPVPictureInfo *picture);
extern const unsigned char *fn_12_A0D8(const unsigned char *data, int length, int mask);
extern int fn_12_2CDD0(SfdHandle *handle, int parameter, const unsigned char *delimiter, Entry *entry);
extern const int lbl_12_rodata_E10[];
extern unsigned int UTY_MulDiv(int multiplicand, int multiplier, int divisor);
extern int fn_8008023C(const void *a, const void *b, int size);
extern int fn_12_2D73C(SfdHandle *handle, int index);
extern void fn_12_2D7DC(SfdHandle *handle, int index, int value);
extern void fn_12_2E374(SfdTimeCode *timecode, int *value, int *scale);
extern void fn_12_28304(SfdHandle *handle, MPVPictureInfo *picture, int pts, int group_changed);
extern int fn_12_AB00(void *decoder, int *value);
extern int fn_12_AA38(void *decoder, int *a, int *b, int *c);
extern int fn_12_21F38(SfdHandle *handle, int index);
extern void *fn_12_57F0(void *dst, const void *src, u32 size);
extern int fn_12_27C58(SfdHandle *handle, SfdPlaybackSettings *settings);

/* retail saves r21-r31 with stmw/lmw, as movie_module code does throughout */
#pragma use_lmw_stmw on

static inline int check_result(SfdHandle *handle, int result, int consumed, int error_code) {
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

static inline void get_timecode(MPVPictureInfo *picture, SfdTimeCode *timecode) {
    timecode->frame_rate_code = picture->frame_rate_code;
    timecode->drop_frame = picture->drop_frame_flag;
    timecode->hours = picture->time_code_hours;
    timecode->minutes = picture->time_code_minutes;
    timecode->seconds = picture->time_code_seconds;
    timecode->frames = picture->time_code_pictures;
    timecode->frame_offset = picture->temporal_reference;
}

static inline void calc_pts(SfdHandle *handle, MPVPictureInfo *picture, SfdMpvFrameWork *work, Entry *entry,
                            int changed, int *pts) {
    int count;
    int rate;
    int span;

    rate = lbl_12_rodata_E10[picture->frame_rate_code];
    count = picture->temporal_reference;
    if (handle->unk_DD4 < 0) {
        *pts = entry->unk_0 - UTY_MulDiv(count, 22500000, rate);
        handle->unk_DD4 = *pts > 0 ? *pts : 0;
    }
    span = entry->unk_0 - handle->unk_DD4;
    *pts = span > 0 ? span : 0;
    if (fn_8008023C(&work->unk_F4, entry, 4) != 0) {
        work->unk_F4 = *entry;
        work->unk_EC = 0;
        work->unk_E8 = count;
        if (picture->picture_type == 3) {
            work->unk_F0 = 1;
        } else {
            work->unk_F0 = 0;
        }
    } else {
        if (changed != 0) {
            work->unk_EC += work->unk_F0 + 1;
            work->unk_F0 = 0;
            work->unk_E8 = 0;
        }
        span = count - work->unk_E8;
        work->unk_F0 = work->unk_F0 > span ? work->unk_F0 : span;
        *pts += UTY_MulDiv(work->unk_EC + span, 22500000, rate);
        *pts = *pts > 0 ? *pts : 0;
    }
}

static inline int get_pts(SfdHandle *handle, MPVPictureInfo *picture, SJCK *chunk, SfdMpvFrameWork *frame) {
    int pts;
    int changed;
    int parameter;
    const unsigned char *delimiter;
    Entry entry;
    SfdMpvFrameWork *work;

    changed = frame->unk_E0;
    work = handle->video_work;
    pts = -1;
    parameter = handle->video_parameter;
    delimiter = fn_12_A0D8(chunk->data, chunk->len, 4);
    if (delimiter != 0) {
        fn_12_2CDD0(handle, parameter, delimiter, &entry);
        if (entry.unk_0 >= 0) {
            calc_pts(handle, picture, work, &entry, changed, &pts);
        }
    }
    return pts;
}

static inline int is_past_maximum(SfdHandle *handle, MPVPictureInfo *picture) {
    SfdTimeCode timecode;
    int value;
    int maximum;
    int scale;
    int count;

    if (handle->timer_state.maximum.valid == 0) {
        return 0;
    }
    get_timecode(picture, &timecode);
    fn_12_2E374(&timecode, &value, &scale);
    fn_12_2E374(&handle->timer_state.maximum.timecode, &maximum, &scale);
    count = scale * fn_12_2D73C(handle, 0x35);
    if (value <= maximum) {
        return 1;
    }
    if (value >= maximum + count) {
        return 1;
    }
    return 0;
}

static inline SeekEntry *get_seek_entry(SfdHandle *handle) {
    SeekWork *seek = handle->seek_work;
    SfdMpvFrameWork *work = handle->video_work;
    if (seek == 0) {
        return 0;
    }
    if (work->unk_88 > 0) {
        return 0;
    }
    return &seek->unk_AC4;
}

static inline void save_seek_entry(SfdHandle *handle, SJCK *chunk, int code) {
    SeekEntry *entry = get_seek_entry(handle);
    SeekBuffer *buffer;
    if (entry != 0 && entry->unk_0 == 0) {
        buffer = &entry->unk_34;
        buffer->unk_200 = chunk->len < 0x200 ? chunk->len : 0x200;
        fn_12_57F0(buffer->unk_0, chunk->data, buffer->unk_200);
        if (code == 0x3FFFF) {
            entry->unk_4 = 0;
            entry->unk_8 = 0;
        } else {
            entry->unk_4 = code * 50;
            entry->unk_8 = 1;
        }
        entry->unk_C = handle->timer_state.initial;
        entry->unk_0 = 1;
    }
}

static inline void set_settings(SfdPlaybackSettings *settings, MPVPictureInfo *picture, int bit_rate,
                                int value) {
    settings->unk_0 = picture->width;
    settings->unk_4 = picture->height;
    settings->unk_8 = picture->macroblocks_per_row;
    settings->unk_C = picture->macroblock_rows;
    settings->frame_rate_code = picture->frame_rate_code;
    settings->unk_10 = bit_rate;
    settings->unk_20 = value;
}

static inline void start_timecode(SfdHandle *handle, MPVPictureInfo *picture, int pts, int changed) {
    int ready = fn_12_2D73C(handle, 0x34);
    if (ready == 0 && (pts >= 0 || (changed != 0 && is_past_maximum(handle, picture)))) {
        fn_12_2D7DC(handle, 0x34, 1);
        ready = 1;
    }
    if (ready == 1) {
        fn_12_28304(handle, picture, pts, changed);
    }
}

static inline int set_sequence(SfdHandle *handle, void *decoder, MPVPictureInfo *picture, SJCK *chunk) {
    SfdPlaybackSettings *settings;
    SfdMpvFrameWork *work;
    int bit_rate;
    int value_a;
    int value_b;
    int value_c;
    int limit;

    settings = &handle->playback_settings;
    work = handle->video_work;
    if (settings->unk_10 != 0) {
        return 0;
    }
    if (fn_12_AB00(decoder, &bit_rate) != 0) {
        return fn_12_24A88(handle, 0xFF000F16);
    }
    fn_12_AA38(decoder, &value_a, &value_b, &value_c);
    if (fn_12_2D73C(handle, 0x3C) == 0) {
        work->unk_E4 = 0;
    } else {
        limit = fn_12_21F38(handle, 1);
        if (value_c == -1) {
            value_c = value_a;
        }
        work->unk_E4 = value_c < limit ? value_c : limit;
    }
    save_seek_entry(handle, chunk, bit_rate);
    set_settings(settings, picture, bit_rate, value_a);
    return fn_12_27C58(handle, settings);
}

static inline void update_current(SfdHandle *handle, MPVPictureInfo *picture) {
    SfdMpvDecodeTimer *timer;
    SfdMpvTimeCodeSnapshot *maximum;
    SfdMpvTimeCodeSnapshot *current;
    SfdTimeCode timecode;
    int value;
    int scale;

    timer = &handle->timer_state;
    maximum = &timer->maximum;
    current = &timer->current;
    get_timecode(picture, &timecode);
    fn_12_2E374(&timecode, &value, &scale);
    current->timecode = timecode;
    current->value = value - timer->initial.value;
    current->scale = scale;
    current->valid = 1;
    if (maximum->value <= current->value) {
        *maximum = *current;
    }
}

int fn_12_284F8(SfdHandle *handle, SJCK *chunk, SJ *stream, int flag) {
    SfdMpvFrameWork *work;
    void *decoder;
    MPVPictureInfo *picture;
    SfdTimeCode start;
    int before;
    int consumed;
    int error;
    int pts;
    int start_scale;
    int start_value;

    work = handle->video_work;
    decoder = work->decoder;
    picture = &work->picture_info;
    fn_12_CA84(decoder, work->picture_buffer_size, work->picture_buffer);
    before = fn_80057D88(stream, 0, 1);
    error = fn_12_C2C8(decoder, stream);
    consumed = fn_80057D88(stream, 0, 1) - before;
    error = check_result(handle, error, consumed, 0xFF000F04);
    fn_12_21E20(handle, handle->video_parameter, consumed);
    if (error != 0) {
        return error;
    }
    fn_12_CA60(decoder, 0, &work->unk_8C8);
    if (fn_12_AB60(decoder, picture) != 0) {
        return fn_12_24A88(handle, 0xFF000F05);
    }
    if (work->unk_DC != picture->unk_30) {
        work->unk_DC = picture->unk_30;
        work->unk_E0 = 1;
    } else {
        work->unk_E0 = 0;
    }
    pts = get_pts(handle, picture, chunk, work);
    if (flag == 0) {
        return 0;
    }
    start_timecode(handle, picture, pts, work->unk_E0);
    if (handle->timer_state.initial.valid == 0) {
        get_timecode(picture, &start);
        start.frame_offset = 0;
        fn_12_2E374(&start, &start_value, &start_scale);
        handle->timer_state.initial.timecode = start;
        handle->timer_state.initial.value = start_value;
        handle->timer_state.initial.scale = start_scale;
        handle->timer_state.initial.valid = 1;
    }
    update_current(handle, picture);

    return set_sequence(handle, decoder, picture, chunk);
}
