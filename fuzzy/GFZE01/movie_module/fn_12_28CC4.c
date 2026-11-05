/* Non-matching: best partial attempt (99.92% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#pragma use_lmw_stmw on
#include "types.h"
#include "sofdec/sj.h"

/* sfmpv_DecodeOneUnit, older GX Sofdec layout. Adapted from the licensed
 * MK Deception sfd_mpv.c donor; widths/offsets and older control flow follow GX. */
typedef struct TimeCode { int fields[6]; int frame_offset; } TimeCode;
typedef struct Snapshot { int valid; TimeCode timecode; int value; int scale; } Snapshot;
typedef struct VideoWork {
    void *decoder;
    u8 unknown_004[0x74];
    int decode_mode;
    u8 unknown_07C[0xC];
    int concat_count;
    u8 unknown_08C[0x18];
    int picture_type;
} VideoWork;
typedef struct Timer { u8 reserved_000[0x1C]; TimeCode current_timecode; Snapshot initial; Snapshot maximum; Snapshot total; Snapshot current; Snapshot previous; } Timer;
typedef struct TimerState { u8 raw[0x100]; } TimerState;
typedef struct TransportSetup { const void *entries[4]; } TransportSetup;
typedef struct Handle {
    TransportSetup *setup;
    u8 unknown_004[0x968];
    int need_data;
    u8 unknown_970[0x334];
    TimerState timer_state;
    u8 unknown_DA4[0x20];
    int reference_origin;
    u8 unknown_DC8[0x18];
    int reference_offset;
    u8 unknown_DE4[0x88];
    int samples;
    u8 unknown_E70[0xCC0];
    VideoWork *video;
    int video_field_1B34;
    int video_parameter;
    u8 unknown_1B3C[0xC];
    int video_state;
} Handle;
typedef struct Transfer { SJCK chunks[2]; int reserved[3]; } Transfer;

extern const u8 lbl_12_rodata_A18[];
extern int fn_12_21E40(Handle *, int, SJ **);
extern void fn_12_2AC80(Handle *, int);
extern int fn_12_21F28(Handle *, int);
extern int fn_12_23250(Handle *);
extern int fn_12_2D73C(Handle *, int);
extern void fn_12_2E374(TimeCode *, int *, int *);
extern int fn_12_22FBC(Handle *, int *, int *);
extern int UTY_MulDiv(int, int, int);
extern void fn_12_23120(Handle *, int);
extern void fn_12_2EE48(Snapshot *, int);
extern int fn_12_A2C4(const u8 *);
extern void fn_12_21E20(Handle *, int, int);
extern int fn_12_231A0(Handle *);
extern int fn_12_21D30(Handle *, int);
extern void fn_12_2AC98(Handle *);
extern int fn_12_22390(Handle *, int, Transfer *);
extern int fn_12_284F8(Handle *, const SJCK *, SJ *, int);
extern int fn_12_27884(Handle *, const SJCK *);
extern int fn_80057D88(SJ *, int, int);
extern int fn_12_A7B0(void *, SJ *);
extern int fn_12_24A88(Handle *, int);
extern void fn_12_2B9F8(Handle *, int, int);
extern int fn_12_27478(Handle *, SJ *);
extern const u8 *fn_12_A0D8(const u8 *, int, int);
extern void fn_12_22008(Handle *, int, int);
extern void *memcpy(void *, const void *, unsigned long);

static inline void skip_endcode(Handle *handle, SJ *stream) {
    SJCK chunk;
    for (;;) {
        stream->interface->get_chunk(stream, 1, 4, &chunk);
        if (chunk.len != 4) break;
        if (fn_12_A2C4(chunk.data) != 0x80) break;
        stream->interface->put_chunk(stream, 0, &chunk);
        fn_12_21E20(handle, handle->video_parameter, 4);
    }
    stream->interface->unget_chunk(stream, 1, &chunk);
}

static inline int calc_time(Snapshot *maximum, Snapshot *initial, int *value, int *scale) {
    if (maximum->valid == 0) {
        return 0;
    } else {
        TimeCode timecode = maximum->timecode;
        timecode.frame_offset++;
        fn_12_2E374(&timecode, value, scale);
        return *value - initial->value;
    }
}
static inline int concat(Handle *handle, SJ *stream, VideoWork *work) {
    int concat_time;
    int samples;
    int sample_rate;
    int value;
    int scale;
    int result;
    int time_unit;
    if (fn_12_2D73C(handle, 6) == 0) {
        Timer *timer = (Timer *)&handle->timer_state;
        concat_time = calc_time(&timer->maximum, &timer->initial, &value, &scale);
    } else {
        if (handle->setup->entries[3] != lbl_12_rodata_A18) {
            samples = 0;
            sample_rate = 44100;
        } else if (fn_12_22FBC(handle, &samples, &sample_rate) == 0) {
            concat_time = -1;
            goto check_sample_time; /* donor sfmpv_Concat flow */
        }
        time_unit = ((Timer *)&handle->timer_state)->initial.scale;
        handle->samples += samples;
        concat_time = UTY_MulDiv(handle->samples, time_unit, sample_rate) - handle->reference_offset;
        if (concat_time < 0) {
            concat_time = 0;
        }
    check_sample_time:
        if (concat_time < 0) {
            result = -1;
            goto check_status; /* donor sfmpv_Concat flow */
        }
    }
    if (concat_time > 0) {
        fn_12_23120(handle, concat_time);
        work->concat_count++;
    }
    fn_12_2EE48(&((Timer *)&handle->timer_state)->initial, 0x7FFFFFFF);
    fn_12_2EE48(&((Timer *)&handle->timer_state)->maximum, -1);
    work->decode_mode = 0xC0;
    result = 0;
check_status:
    if (result == -1) {
        return -1;
    }
    skip_endcode(handle, stream);
    return 0;
}

static inline int is_term(Handle *handle, int size, int code) {
    if (code == 0x80) return 1;
    if (size <= 4 && fn_12_21D30(handle, handle->video_parameter) == 1) return 1;
    return 0;
}

static inline int check_decode(Handle *handle, int result, int consumed) {
    int error;
    switch (result) {
    case 0: error = 0; break;
    case -2:
        if (consumed > 0) error = 0;
        else error = fn_12_24A88(handle, -2);
        break;
    case -3:
        if (consumed > 0) error = 0;
        else error = fn_12_24A88(handle, -3);
        break;
    case -1:
    default: error = fn_12_24A88(handle, 0xFF000F07); break;
    }
    return error;
}

static inline int skip_picture(Handle *handle, SJ *stream, VideoWork *work) {
    Timer *timer = (Timer *)&handle->timer_state;
    Snapshot *current = &timer->current;
    Snapshot *previous = &timer->previous;
    void *decoder = work->decoder;
    int before;
    int consumed;
    int result;
    if (current->value < handle->reference_origin) *previous = *current;
    before = fn_80057D88(stream, 0, 1);
    result = fn_12_A7B0(decoder, stream);
    consumed = fn_80057D88(stream, 0, 1) - before;
    result = check_decode(handle, result, consumed);
    fn_12_21E20(handle, handle->video_parameter, consumed);
    switch (result) {
    case 0:
        fn_12_2B9F8(handle, 1, work->picture_type);
        result = 0;
        break;
    }
    return result;
}

static inline const u8 *search_transfer(Transfer *transfer, int mask, int *code) {
    u8 boundary[8];
    const u8 *delimiter;
    long tail;
    long head;
    int i;
    int found_code;
    delimiter = fn_12_A0D8(transfer->chunks[0].data, transfer->chunks[0].len, mask);
    if (delimiter != 0) {
        *code = fn_12_A2C4(delimiter);
        return delimiter;
    }
    head = transfer->chunks[1].len;
    if (head == 0) {
        return 0;
    }
    tail = transfer->chunks[0].len < 3 ? transfer->chunks[0].len : 3;
    head = head < 3 ? transfer->chunks[1].len : 3;
    memcpy(boundary, transfer->chunks[0].data + transfer->chunks[0].len - tail, tail);
    memcpy(boundary + tail, transfer->chunks[1].data, head);
    for (i = 0; i < tail + head - 3; i++) {
        found_code = fn_12_A2C4(boundary + i);
        if ((found_code & mask) != 0) {
            *code = found_code;
            return transfer->chunks[0].data + transfer->chunks[0].len - tail + i;
        }
    }
    delimiter = fn_12_A0D8(transfer->chunks[1].data, transfer->chunks[1].len, mask);
    if (delimiter != 0) {
        *code = fn_12_A2C4(delimiter);
        return delimiter;
    }
    return 0;
}

static inline void go_delimiter(Handle *handle, int mask) {
    Transfer transfer;
    const u8 *delimiter;
    int consumed;
    int code;
    if (fn_12_22390(handle, handle->video_parameter, &transfer) != 0) return;
    if (transfer.chunks[0].len == 0) return;
    delimiter = search_transfer(&transfer, mask, &code);
    if (delimiter == 0) {
        int remaining = transfer.chunks[0].len + transfer.chunks[1].len;
        consumed = (remaining -= 3) > 0 ? remaining : 0;
    } else if ((u32)transfer.chunks[0].data <= (u32)delimiter &&
               (u32)delimiter < (u32)(transfer.chunks[0].data + transfer.chunks[0].len)) {
        consumed = delimiter - transfer.chunks[0].data;
    } else if ((u32)transfer.chunks[1].data <= (u32)delimiter &&
               (u32)delimiter < (u32)(transfer.chunks[1].data + transfer.chunks[1].len)) {
        consumed = transfer.chunks[0].len + (delimiter - transfer.chunks[1].data);
    } else consumed = 0;
    fn_12_22008(handle, handle->video_parameter, consumed);
}

#pragma opt_common_subs off
int fn_12_28CC4(Handle *handle, int active_size, int delimiter_type, int *processed) {
    VideoWork *work;
    Snapshot *total;
    int result;
    Timer *timer = (Timer *)&handle->timer_state;
    int buffer_index;
    SJ *stream;
    SJCK chunk;
    Transfer header;
    *processed = 0;
    work = handle->video;
    buffer_index = handle->video_parameter;
    handle->need_data = 0;
    if (work->decode_mode != 0xCC) delimiter_type &= 0xCC;
    result = fn_12_21E40(handle, buffer_index, &stream);
    if (result != 0) return 0;
    if ((delimiter_type & 0xC8) != 0) fn_12_2AC80(handle, 1);
    if (delimiter_type == 0x80) {
        int index = handle->video_parameter;
        total = &timer->total;
        if (handle->video_state < 0) handle->video_state = fn_12_21F28(handle, index) + 4;
        if (total->value < 0) *total = timer->maximum;
    }
    if (delimiter_type == 0x80 && fn_12_23250(handle) != 0) {
        if (concat(handle, stream, handle->video) == 0) *processed = 1;
    } else if (delimiter_type == 0x80 && fn_12_231A0(handle) != 0) {
        skip_endcode(handle, stream);
        *processed = 1;
    } else if (is_term(handle, active_size, delimiter_type)) {
        fn_12_2AC98(handle);
    } else if (active_size <= 4) {
        handle->need_data = 1;
    } else if ((delimiter_type & 0x4C) != 0) {
        if (fn_12_22390(handle, handle->video_parameter, &header) != 0) {
            chunk.data = 0;
            chunk.len = 0;
        } else chunk = header.chunks[0];
        result = fn_12_284F8(handle, &chunk, stream, (delimiter_type & work->decode_mode) != 0);
        if (result != 0) return result;
        if ((delimiter_type & work->decode_mode) != 0) work->decode_mode = 0xCC;
        *processed = 1;
    } else if ((delimiter_type & 2) != 0) {
        if (handle->reference_offset < 0) return 0;
        if (fn_12_27884(handle, &chunk) != 0) {
            result = skip_picture(handle, stream, handle->video);
            if (result == 0) *processed = 1;
        } else result = fn_12_27478(handle, stream);
    } else if (delimiter_type != 0x80) {
        go_delimiter(handle, 0xCC);
        *processed = 1;
    }
    return result;
}
