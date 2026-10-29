/* Non-matching: best partial attempt (97.62% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MpsHandle MpsHandle;

typedef struct MpsValues {
    s32 value_00;
    s32 value_04;
    s32 value_08;
    s32 value_0c;
    s32 value_10;
    s32 value_14;
    s32 value_18;
    s32 value_1c;
} MpsValues;

typedef struct SfmpsWork {
    MpsHandle *decoder;
    s32 max_video_bound;
    s32 max_audio_bound;
    s32 video_pts_baseline;
    s32 audio_pts_baseline;
    s32 concat_count;
    s32 previous_video_stream;
    s32 previous_audio_stream;
    s32 first_video_stream;
    s32 first_audio_stream;
    s32 selected_video_id;
    s32 selected_audio_id;
} SfmpsWork;

typedef struct SfdHandle {
    u8 pad_0000[0x1AEC];
    SfmpsWork *work;
    u8 pad_1AF0[0x8];
    void *stream;
} SfdHandle;

typedef struct RingInfo {
    u8 *ptr0;
    s32 len0;
    u8 *ptr1;
    s32 len1;
    s32 unk10;
    s32 unk14;
} RingInfo;

typedef struct PtsInfo {
    s32 pts;
    u8 *ptr;
    s32 len;
} PtsInfo;

extern s32 fn_12_2D73C(SfdHandle *, int);
extern int fn_12_696C(MpsHandle *, MpsValues *, int);
extern s32 fn_12_224FC(SfdHandle *, void *, RingInfo *);
extern void *fn_12_57F0(void *, const void *, u32);
extern s32 fn_12_22254(SfdHandle *, void *, s32, s32);
extern s32 fn_12_2CF20(SfdHandle *, void *, PtsInfo *);

static inline s32 select_stream(SfdHandle *handle, s32 id) {
    SfmpsWork *work = handle->work;
    MpsHandle *dec;
    s32 maxA = 0;
    s32 maxV = 0;
    s32 i;
    MpsValues vals;

    dec = work->decoder;
    for (i = 0; i < 3; i++) {
        fn_12_696C(dec, &vals, i);
        maxA = (maxA > vals.value_08) ? maxA : vals.value_08;
        maxV = (maxV > vals.value_0c) ? maxV : vals.value_0c;
    }
    work->max_audio_bound = maxA;
    work->max_video_bound = maxV;
    if (work->max_video_bound >= 2) {
        return 2;
    }
    return id;
}

static inline s32 choose_stream(SfdHandle *handle, s32 id) {
    switch (fn_12_2D73C(handle, 0x3B)) {
    case 1:
        return id;
    case 2:
        return select_stream(handle, id);
    case 0:
    default:
        return id;
    }
    return id;
}

static inline s32 is_seq_start(u8 *buf, s32 len) {
    u8 c;

    if (len < 4) {
        return 0;
    }
    if (buf[0] != 0) {
        return 0;
    }
    if (buf[1] != 0) {
        return 0;
    }
    if (buf[2] != 1) {
        return 0;
    }
    c = buf[3];
    if (c == 0xB3) {
        return 1;
    }
    return c == 0xB8;
}

static inline s32 is_changed(SfdHandle *handle, SfmpsWork *work, s32 id) {
    if (fn_12_2D73C(handle, 0x37) != 0) {
        return id < work->previous_video_stream;
    }
    return id == work->first_video_stream;
}

static inline s32 write_data(SfdHandle *handle, u8 *buf, s32 len, s32 pts) {
    PtsInfo pi;
    void *stream;
    s32 err;
    RingInfo info;
    u8 *ptr0;
    s32 len0;
    u8 *ptr1;
    s32 extra;

    stream = handle->stream;
    err = fn_12_224FC(handle, stream, &info);
    if (err != 0) {
        return err;
    }
    len0 = info.len0;
    ptr0 = info.ptr0;
    ptr1 = info.ptr1;
    extra = info.unk14;
    if (len > len0 + info.len1) {
        return 0;
    }
    if (len <= len0) {
        fn_12_57F0(ptr0, buf, len);
    } else {
        fn_12_57F0(ptr0, buf, len0);
        fn_12_57F0(ptr1, buf + len0, len - len0);
    }
    err = fn_12_22254(handle, stream, len, extra);
    if (err != 0) {
        return err;
    }
    if (pts >= 0) {
        pi.pts = pts;
        pi.ptr = ptr0;
        pi.len = len;
        err = fn_12_2CF20(handle, stream, &pi);
        if (err != 0) {
            return err;
        }
    }
    return 1;
}

s32 fn_12_25AAC(SfdHandle *handle, s32 id, u8 *buf, s32 len, s32 pts) {
    SfmpsWork *work;
    s32 next;

    if (fn_12_2D73C(handle, 5) == 0) {
        return 1;
    }
    work = handle->work;
    if (work->selected_video_id == -1) {
        work->selected_video_id = choose_stream(handle, id);
    }
    if (work->first_video_stream == -1) {
        work->first_video_stream = id;
    }
    next = fn_12_2D73C(handle, 0x1D);
    if (next != -1) {
        if (is_changed(handle, work, id) && work->selected_video_id != next) {
            if (is_seq_start(buf, len)) {
                work->selected_video_id = next;
            }
        }
    }
    work->previous_video_stream = id;
    if (work->selected_video_id != id) {
        return 1;
    }
    return write_data(handle, buf, len, pts);
}
