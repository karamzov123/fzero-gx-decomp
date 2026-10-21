/* Non-matching: best partial attempt (97.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

/* sfmpv_DecodePicAtr (sfd_mpv.c, CRI Sofdec), GX version */

typedef struct SJ SJ;
typedef struct MPVContext MPVContext;

typedef struct SJCK {
    unsigned char *data;
    int len;
} SJCK;

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
    unsigned char reserved_06C[0x28];
    SfdMpvTimeCodeSnapshot current;
    unsigned char reserved_0BC[0x28];
    SfdMpvTimeCodeSnapshot output_start;
    unsigned char reserved_10C[0x8];
    int initial_pts;
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
    int group_count;
    int field_38;
} MPVPictureInfo;

typedef struct SfdPtsEntry {
    int pts;
    int fields[2];
} SfdPtsEntry;

typedef struct SfdMpvFrameWork {
    MPVContext *decoder;
    unsigned char reserved_004[0x84];
    int field_088;
    MPVPictureInfo picture_info;
    unsigned char reserved_0C4[0x18];
    int field_10C;
    int field_110;
    int active_size_threshold;
    int field_118;
    int field_11C;
    int field_120;
    SfdPtsEntry pts_entry;
    unsigned char reserved_100[0x7C0];
    int picture_buffer_size;
    void *picture_buffer;
    int picture_size;
} SfdMpvFrameWork;

typedef struct SfdMpvPlaybackSettings {
    int width;
    int height;
    int macroblocks_per_row;
    int macroblock_rows;
    int bit_rate;
    int frame_rate_code;
    int fields_18[2];
    int vbv_buffer_size;
} SfdMpvPlaybackSettings;

typedef struct SfdMpvRawHeader {
    unsigned char data[0x200];
    int size;
} SfdMpvRawHeader;

typedef struct SfdMpvSeekCache {
    int valid;
    int byte_rate;
    int byte_rate_valid;
    SfdMpvTimeCodeSnapshot initial;
    SfdMpvRawHeader raw_header;
} SfdMpvSeekCache;

typedef struct SfdHandle {
    unsigned char reserved_0000[0x90C];
    SfdMpvPlaybackSettings playback_settings;
    unsigned char reserved_0930[0x390];
    SfdMpvDecodeTimer timer_state;
    unsigned char reserved_0DD8[0xD58];
    SfdMpvFrameWork *video_work;
    int video_field_1B34;
    int video_parameter;
    unsigned char reserved_1B3C[0xDCC];
    void *seek_work;
} SfdHandle;

extern void fn_12_CA84(MPVContext *decoder, void *buffer, int size);
extern int fn_80057D88(SJ *stream, int channel, int type);
extern int fn_12_C2C8(MPVContext *decoder, SJ *stream);
extern int fn_12_24A88(SfdHandle *handle, int error);
extern void fn_12_21E20(SfdHandle *handle, int parameter, int consumed);
extern void fn_12_CA60(MPVContext *decoder, void **buffer, int *size);
extern int fn_12_AB60(MPVContext *decoder, MPVPictureInfo *picture);
extern const unsigned char *fn_12_A0D8(const unsigned char *data, int length, int mask);
extern void fn_12_2CDD0(SfdHandle *handle, int index, const unsigned char *delimiter, SfdPtsEntry *entry);
extern const int lbl_12_rodata_E10[];
extern int UTY_MulDiv(int value, int multiplier, int divisor);
extern int fn_8008023C(const void *a, const void *b, unsigned long size);
extern int fn_12_2D73C(SfdHandle *handle, int condition);
extern void fn_12_2D7DC(SfdHandle *handle, int condition, int value);
extern void fn_12_2E374(SfdTimeCode *timecode, int *value, int *scale);
extern void fn_12_28304(SfdHandle *handle, MPVPictureInfo *picture, int timestamp, int new_group);
extern int fn_12_AB00(MPVContext *decoder, int *bit_rate);
extern void fn_12_AA38(MPVContext *decoder, int *vbv_buffer_size, int *vbv_delay, int *byte_rate);
extern int fn_12_21F38(SfdHandle *handle, int index);
extern void *fn_12_57F0(void *destination, const void *source, unsigned long size);
extern int fn_12_27C58(SfdHandle *handle, SfdMpvPlaybackSettings *settings);

static inline void sfmpv_GetTc(SfdTimeCode *timecode, MPVPictureInfo *picture) {
    timecode->frame_rate_code = picture->frame_rate_code;
    timecode->drop_frame = picture->drop_frame_flag;
    timecode->hours = picture->time_code_hours;
    timecode->minutes = picture->time_code_minutes;
    timecode->seconds = picture->time_code_seconds;
    timecode->frames = picture->time_code_pictures;
    timecode->frame_offset = picture->temporal_reference;
}

static inline int sfmpv_ChkGopTc(SfdHandle *handle, MPVPictureInfo *picture) {
    SfdMpvDecodeTimer *timer = &handle->timer_state;
    SfdMpvTimeCodeSnapshot *maximum = &timer->maximum;
    SfdTimeCode current_timecode;
    int value;
    int stored_value;
    int scale;
    int window;
    int result;

    if (maximum->valid == 0) {
        result = 0;
    } else {
        sfmpv_GetTc(&current_timecode, picture);
        fn_12_2E374(&current_timecode, &value, &scale);
        fn_12_2E374(&maximum->timecode, &stored_value, &scale);
        window = scale * fn_12_2D73C(handle, 53);
        if (value <= stored_value) {
            result = 1;
        } else if (value >= stored_value + window) {
            result = 1;
        } else {
            result = 0;
        }
    }
    return result;
}

static inline void sfmpv_ReformTc(SfdHandle *handle, SfdMpvFrameWork *work, MPVPictureInfo *picture,
                                  int timestamp) {
    int new_group = work->field_110;
    int mode = fn_12_2D73C(handle, 52);

    if (mode == 0) {
        if (timestamp >= 0 || (new_group != 0 && sfmpv_ChkGopTc(handle, picture) != 0)) {
            fn_12_2D7DC(handle, 52, 1);
            mode = 1;
        }
    }
    if (mode == 1) {
        fn_12_28304(handle, picture, timestamp, new_group);
    }
}

#pragma opt_strength_reduction off
int fn_12_284F8(SfdHandle *handle, const SJCK *header, SJ *stream, int decode_header) {
    int fzgx_value;
    SfdMpvPlaybackSettings *settings;
    SfdMpvFrameWork * fzgx_live_;
    SfdMpvTimeCodeSnapshot *current_snapshot;
    SfdMpvFrameWork *work = handle->video_work;
    SfdMpvDecodeTimer *timer = &handle->timer_state;
    MPVPictureInfo *picture = &work->picture_info;
    SfdTimeCode initial_timecode;
    SfdTimeCode picture_timecode;
    int initial_scale;
    int initial_value;
    int picture_scale;
    int picture_value;
    SJ * stream_local = stream;
    const unsigned char *delimiter;
    SfdPtsEntry pts_entry;
    int timestamp;
    int decode_result;
    int consumed;
    int result;
    int byte_rate;
    int vbv_delay;
    int vbv_buffer_size;
    int bit_rate;
    int cache_bit_rate;
    int published_bit_rate;
    int published_vbv_size;
    int pts_buffer_index;
    SfdMpvFrameWork *pts_work;
    SfdMpvFrameWork * fzgx_live;
    SfdMpvTimeCodeSnapshot *maximum_snapshot;
    SfdMpvFrameWork *cache_work;
    SfdMpvFrameWork *output_work;
    int new_group;

{
    MPVContext *decoder = work->decoder;
    fn_12_CA84(decoder, work->picture_buffer, work->picture_buffer_size);
    decode_result = fn_12_C2C8(decoder, stream_local);
    consumed = fn_80057D88(stream_local, 0, 1) - (fn_80057D88(stream_local, 0, 1));
    switch (decode_result) {
    case 0:
        result = 0;
        break;
    case -2:
        if (consumed > 0) {
            result = 0;
        } else {
            result = fn_12_24A88(handle, -2);
        }
        break;
    case -3:
        if (consumed > 0) {
            result = 0;
        } else {
            result = fn_12_24A88(handle, -3);
        }
        break;
    default:
        result = fn_12_24A88(handle, 0xFF000F04);
        break;
    }
    fn_12_21E20(handle, handle->video_parameter, consumed);
    if (result != 0) {
        return result;
    }

    fn_12_CA60(decoder, 0, &work->picture_size);
    if (fn_12_AB60(decoder, picture) != 0) {
        return fn_12_24A88(handle, 0xFF000F05);
    }
    if (work->field_10C != picture->group_count) {
        fzgx_value = picture->group_count;
        work->field_10C = fzgx_value;
        work->field_110 = 1;
    } else {
        work->field_110 = 0;
    }

    new_group = work->field_110;
    timestamp = -1;
    fzgx_live_ = handle->video_work;
    fzgx_live = fzgx_live_;
    pts_work = fzgx_live;
    pts_buffer_index = handle->video_parameter;
    delimiter = fn_12_A0D8(header->data, header->len, 4);
    if (delimiter != 0) {
        fn_12_2CDD0(handle, pts_buffer_index, delimiter, &pts_entry);
        if (pts_entry.pts >= 0) {
            int rate = lbl_12_rodata_E10[picture->frame_rate_code];
            int temporal_reference = picture->temporal_reference;
            int delta;

            if (handle->timer_state.initial_pts < 0) {
                int initial_pts = pts_entry.pts - UTY_MulDiv(temporal_reference, 22497920, rate);
                initial_pts = initial_pts > 0 ? initial_pts : 0;
                handle->timer_state.initial_pts = initial_pts;
            }
            timestamp = pts_entry.pts - handle->timer_state.initial_pts;
            timestamp = timestamp > 0 ? timestamp : 0;
            if (fn_8008023C(&pts_work->pts_entry, &pts_entry, 4) != 0) {
                pts_work->pts_entry = pts_entry;
                pts_work->field_11C = 0;
                pts_work->field_118 = temporal_reference;
                if (picture->picture_type == 3) {
                    pts_work->field_120 = 1;
                } else {
                    pts_work->field_120 = 0;
                }
            } else {
                if (new_group != 0) {
                    pts_work->field_11C += pts_work->field_120 + 1;
                    pts_work->field_120 = 0;
                    pts_work->field_118 = 0;
                }
                delta = temporal_reference - pts_work->field_118;
                pts_work->field_120 = pts_work->field_120 > delta ? pts_work->field_120 : delta;
                timestamp += UTY_MulDiv(pts_work->field_11C + delta, 90000000, rate);
                timestamp = timestamp > 0 ? timestamp : 0;
            }
        }
    }
    if (decode_header == 0) {
        return 0;
    }

    sfmpv_ReformTc(handle, work, picture, timestamp);

    if (timer->initial.valid == 0) {
        sfmpv_GetTc(&initial_timecode, picture);
        initial_timecode.frame_offset = 0;
        fn_12_2E374(&initial_timecode, &initial_value, &initial_scale);
        timer->initial.timecode = initial_timecode;
        timer->initial.value = initial_value;
        timer->initial.scale = initial_scale;
        timer->initial.valid = 1;
    }
    maximum_snapshot = &timer->maximum;
    current_snapshot = &timer->current;
    {
        sfmpv_GetTc(&picture_timecode, picture);
        fn_12_2E374(&picture_timecode, &picture_value, &picture_scale);
        current_snapshot->timecode = picture_timecode;
        current_snapshot->value = picture_value - timer->initial.value;
        current_snapshot->scale = picture_scale;
        current_snapshot->valid = 1;
    }
    if (maximum_snapshot->value <= current_snapshot->value) {
        *maximum_snapshot = *current_snapshot;
    }

    settings = &handle->playback_settings;
    fzgx_live_ = handle->video_work;
    fzgx_live = fzgx_live_;
    output_work = fzgx_live;
    if (settings->bit_rate != 0) {
        return 0;
    }
    if (fn_12_AB00(decoder, &bit_rate) != 0) {
        return fn_12_24A88(handle, 0xFF000F16);
    }
    fn_12_AA38(decoder, &vbv_buffer_size, &vbv_delay, &byte_rate);
}
    if (fn_12_2D73C(handle, 60) == 0) {
        output_work->active_size_threshold = 0;
    } else {
        int ring_size = fn_12_21F38(handle, 1);
        if (byte_rate == -1) {
            byte_rate = vbv_buffer_size;
        }
        output_work->active_size_threshold = byte_rate < ring_size ? byte_rate : ring_size;
    }

    cache_bit_rate = bit_rate;
    fzgx_live_ = handle->video_work;
    fzgx_live = fzgx_live_;
    cache_work = fzgx_live;
    {
        SfdMpvSeekCache *cache;
        void *seek_work = handle->seek_work;

        if (seek_work == 0) {
            cache = 0;
        } else if (cache_work->field_088 > 0) {
            cache = 0;
        } else {
            cache = (SfdMpvSeekCache *)((unsigned char *)seek_work + 0xAC4);
        }
        if (cache != 0 && cache->valid == 0) {
            SfdMpvRawHeader *raw_header = &cache->raw_header;
            long copy_size;
            long header_size;

            header_size = header->len;
            copy_size = sizeof(raw_header->data);
            if (header_size < copy_size) {
                copy_size = header_size;
            }
            raw_header->size = copy_size;
            fn_12_57F0(raw_header->data, header->data, raw_header->size);
            if (cache_bit_rate == 0x3FFFF) {
                cache->byte_rate = 0;
                cache->byte_rate_valid = 0;
            } else {
                cache->byte_rate = cache_bit_rate * 50;
                cache->byte_rate_valid = 1;
            }
            cache->initial = timer->initial;
            cache->valid = 1;
        }
    }

    published_vbv_size = vbv_buffer_size;
    published_bit_rate = bit_rate;
    settings->width = picture->width;
    settings->height = picture->height;
    settings->macroblocks_per_row = picture->macroblocks_per_row;
    settings->macroblock_rows = picture->macroblock_rows;
    settings->frame_rate_code = picture->frame_rate_code;
    settings->bit_rate = published_bit_rate;
    settings->vbv_buffer_size = published_vbv_size;
    return fn_12_27C58(handle, settings);
}
#pragma opt_strength_reduction reset


typedef char HandleCheck1[(int)&((SfdHandle *)0)->timer_state == 0xCC0 ? 1 : -1];
typedef char HandleCheck2[(int)&((SfdHandle *)0)->seek_work == 0x2908 ? 1 : -1];
typedef char HandleCheck3[(int)&((SfdHandle *)0)->video_work == 0x1B30 ? 1 : -1];
typedef char WorkCheck1[(int)&((SfdMpvFrameWork *)0)->pts_entry == 0xF4 ? 1 : -1];
typedef char WorkCheck2[(int)&((SfdMpvFrameWork *)0)->picture_buffer_size == 0x8C0 ? 1 : -1];
typedef char TimerCheck[(int)&((SfdMpvDecodeTimer *)0)->initial_pts == 0x114 ? 1 : -1];
