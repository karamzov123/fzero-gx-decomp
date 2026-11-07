#include "types.h"

typedef struct SJCK {
    unsigned char *data;
    long len;
} SJCK;

typedef struct SJ SJ;

typedef struct SJInterface {
    void *reserved[6];
    void (*get_chunk)(SJ *sj, int channel, int max_size, SJCK *chunk);
    void (*unget_chunk)(SJ *sj, int channel, SJCK *chunk);
    void (*put_chunk)(SJ *sj, int channel, SJCK *chunk);
} SJInterface;

struct SJ {
    const SJInterface *interface;
};
#include "rel/movie_module/data/lbl_12_rodata_A18.h"

/* sfmpv_DecodeOneUnit (CRI Sofdec, sfd_mpv.c), GX version. */

typedef struct SfdTimeCode {
    s32 frame_rate_code;
    s32 drop_frame;
    s32 hours;
    s32 minutes;
    s32 seconds;
    s32 frames;
    s32 frame_offset;
} SfdTimeCode;

typedef struct SfdMpvTimeCodeSnapshot {
    s32 valid;
    SfdTimeCode timecode;
    s32 value;
    s32 scale;
} SfdMpvTimeCodeSnapshot;

typedef struct SfdMpvDecodeTimer {
    u8 reserved_000[0x1C];
    SfdMpvTimeCodeSnapshot initial;
    SfdMpvTimeCodeSnapshot maximum;
    SfdMpvTimeCodeSnapshot reserved_snapshot;
    SfdMpvTimeCodeSnapshot current;
    SfdMpvTimeCodeSnapshot previous;
    u8 reserved_0E4[0x20];
    s32 reference_time_origin;
    u8 reserved_108[0x18];
    s32 reference_time_offset;
    u8 reserved_124[0x88];
    s32 total_samples;
} SfdMpvDecodeTimer;

typedef struct SfdMpvFrameWork {
    void *decoder;
    u8 reserved_004[0x74];
    s32 decode_mode;
    u8 reserved_07C[0xC];
    s32 concat_count;
    u8 reserved_08C[0x18];
    s32 picture_type;
} SfdMpvFrameWork;

typedef struct SfdTransportSetup {
    u8 reserved_00[0xC];
    const void *audio_transport;
} SfdTransportSetup;

typedef struct SfdHandle {
    SfdTransportSetup *transport_setup;
    u8 reserved_0004[0x968];
    s32 decode_wait;
    u8 reserved_0970[0x350];
    SfdMpvDecodeTimer timer;
    u8 reserved_0E70[0xCC0];
    SfdMpvFrameWork *video_work;
    u8 reserved_1B34[0x4];
    s32 video_buffer;
    u8 reserved_1B3C[0xC];
    s32 video_total;
} SfdHandle;

typedef struct SfdBufferTransfer {
    SJCK chunks[2];
    s32 reserved[3];
} SfdBufferTransfer;

extern int fn_12_21E40(SfdHandle *handle, s32 buffer, SJ **stream);
extern void fn_12_2AC80(SfdHandle *handle, s32 status);
extern s32 fn_12_21F28(SfdHandle *handle, s32 buffer);
extern int fn_12_23250(SfdHandle *handle);
extern int fn_12_2D73C(SfdHandle *handle, s32 condition);
extern void fn_12_2E374(SfdTimeCode *timecode, s32 *value, s32 *scale);
extern int fn_12_22FBC(SfdHandle *handle, s32 *samples, s32 *sample_rate);
extern s32 UTY_MulDiv(s32 value, s32 multiplier, s32 divisor);
extern void fn_12_23120(SfdHandle *handle, s32 concat_time);
extern void fn_12_2EE48(SfdMpvTimeCodeSnapshot *snapshot, s32 value);
extern int fn_12_A2C4(const u8 *data);
extern void fn_12_21E20(SfdHandle *handle, s32 buffer, s32 size);
extern int fn_12_231A0(SfdHandle *handle);
extern int fn_12_21D30(SfdHandle *handle, s32 buffer);
extern void fn_12_2AC98(SfdHandle *handle);
extern int fn_12_22390(SfdHandle *handle, s32 buffer, SfdBufferTransfer *transfer);
extern int fn_12_284F8(SfdHandle *handle, SJCK *header, SJ *stream, int decode);
extern int fn_12_27884(SfdHandle *handle, SJCK *chunk);
extern s32 fn_80057D88(SJ *stream, s32 channel, s32 direction);
extern int fn_12_A7B0(void *decoder, SJ *stream);
extern int fn_12_24A88(SfdHandle *handle, s32 error);
extern void fn_12_2B9F8(SfdHandle *handle, s32 count, s32 picture_type);
extern int fn_12_27478(SfdHandle *handle, SJ *stream);
extern const u8 *fn_12_A0D8(const u8 *data, s32 size, u32 mask);
extern void fn_12_22008(SfdHandle *handle, s32 buffer, s32 size);
extern void *memcpy(void *dst, const void *src, u32 size);

static inline void sfmpv_SkipEndcode(SfdHandle *handle, SJ *stream) {
    for (;;) {
        SJCK chunk;

        stream->interface->get_chunk(stream, 1, 4, &chunk);
        if (chunk.len == 4 && fn_12_A2C4(chunk.data) == 0x80) {
            stream->interface->put_chunk(stream, 0, &chunk);
            fn_12_21E20(handle, handle->video_buffer, 4);
        } else {
            stream->interface->unget_chunk(stream, 1, &chunk);
            break;
        }
    }
}

static inline s32 sfmpv_GetAudioConcatTime(SfdHandle *handle) {
    SfdMpvDecodeTimer *timer = &handle->timer;
    s32 samples;
    s32 sample_rate;
    s32 concat_time;

    if (handle->transport_setup->audio_transport != &lbl_12_rodata_A18) {
        samples = 0;
        sample_rate = 44100;
    } else if (fn_12_22FBC(handle, &samples, &sample_rate) == 0) {
        return -1;
    }
    {
        s32 scale = timer->initial.scale;

        timer->total_samples += samples;
        concat_time = UTY_MulDiv(timer->total_samples, scale, sample_rate) - timer->reference_time_offset;
    }
    if (concat_time < 0) {
        concat_time = 0;
    }
    return concat_time;
}

static inline s32 sfmpv_CalcConcatTime(SfdMpvTimeCodeSnapshot *maximum,
                                       SfdMpvTimeCodeSnapshot *initial) {
    SfdTimeCode timecode;
    s32 value;
    s32 scale;

    if (maximum->valid == 0) {
        return 0;
    }
    timecode = maximum->timecode;
    timecode.frame_offset++;
    fn_12_2E374(&timecode, &value, &scale);
    return value - initial->value;
}

static inline int sfmpv_UpdateConcatTime(SfdHandle *handle) {
    SfdMpvFrameWork *work = handle->video_work;
    SfdMpvDecodeTimer *timer = &handle->timer;
    s32 concat_time;

    if (fn_12_2D73C(handle, 6) == 0) {
        concat_time = sfmpv_CalcConcatTime(&timer->maximum, &timer->initial);
    } else {
        concat_time = sfmpv_GetAudioConcatTime(handle);
        if (concat_time < 0) {
            return -1;
        }
    }
    if (concat_time > 0) {
        fn_12_23120(handle, concat_time);
        work->concat_count++;
    }
    fn_12_2EE48(&timer->initial, 0x7FFFFFFF);
    fn_12_2EE48(&timer->maximum, -1);
    work->decode_mode = 0xC0;
    return 0;
}

static inline int sfmpv_Concat(SfdHandle *handle, SJ *stream) {
    if (sfmpv_UpdateConcatTime(handle) == -1) {
        return -1;
    }
    sfmpv_SkipEndcode(handle, stream);
    return 0;
}

static inline int sfmpv_SkipFrm(SfdHandle *handle, SJ *stream) {
    SfdMpvFrameWork *work = handle->video_work;
    SfdMpvDecodeTimer *timer = &handle->timer;
    void *decoder = work->decoder;
    s32 flow_before;
    s32 consumed;
    int result;
    SfdMpvTimeCodeSnapshot *current = &timer->current;
    SfdMpvTimeCodeSnapshot *previous = &timer->previous;

    if (current->value < timer->reference_time_origin) {
        *previous = *current;
    }
    flow_before = fn_80057D88(stream, 0, 1);
    result = fn_12_A7B0(decoder, stream);
    consumed = fn_80057D88(stream, 0, 1) - flow_before;
    switch (result) {
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
        result = fn_12_24A88(handle, 0xFF000F07);
        break;
    }
    fn_12_21E20(handle, handle->video_buffer, consumed);
    if (result != 0) {
        return result;
    }
    fn_12_2B9F8(handle, 1, work->picture_type);
    return 0;
}

static inline int sfmpv_IsTermDec(SfdHandle *handle, s32 active_size, s32 delimiter_type) {
    if (delimiter_type == 0x80) {
        return 1;
    }
    if (active_size <= 4 && fn_12_21D30(handle, handle->video_buffer) == 1) {
        return 1;
    }
    return 0;
}

static inline const u8 *sfmpv_SearchTransferDelimiter(SfdBufferTransfer *transfer,
                                                      int delimiter_mask, int *code) {
    u8 boundary[8];
    const u8 *delimiter;
    long tail;
    long head;
    int i;
    int found_code;
    delimiter = fn_12_A0D8(transfer->chunks[0].data, transfer->chunks[0].len, delimiter_mask);
    if (delimiter != 0) {
        *code = fn_12_A2C4(delimiter);
        return delimiter;
    }
    if (transfer->chunks[1].len == 0) {
        return 0;
    }
    tail = transfer->chunks[0].len < 3 ? transfer->chunks[0].len : 3;
    head = transfer->chunks[1].len < 3 ? transfer->chunks[1].len : 3;
    memcpy(boundary, transfer->chunks[0].data + transfer->chunks[0].len - tail, tail);
    memcpy(boundary + tail, transfer->chunks[1].data, head);
    for (i = 0; i < tail + head - 3; i++) {
        found_code = fn_12_A2C4(boundary + i);
        if ((found_code & delimiter_mask) != 0) {
            *code = found_code;
            return transfer->chunks[0].data + transfer->chunks[0].len - tail + i;
        }
    }
    delimiter = fn_12_A0D8(transfer->chunks[1].data, transfer->chunks[1].len, delimiter_mask);
    if (delimiter != 0) {
        *code = fn_12_A2C4(delimiter);
        return delimiter;
    }
    return 0;
}

static inline int sfmpv_DelimiterOffset(const SfdBufferTransfer *transfer, const u8 *delimiter) {
    if (transfer->chunks[0].data <= delimiter &&
        delimiter < transfer->chunks[0].data + transfer->chunks[0].len) {
        return delimiter - transfer->chunks[0].data;
    }
    if (transfer->chunks[1].data <= delimiter &&
        delimiter < transfer->chunks[1].data + transfer->chunks[1].len) {
        return transfer->chunks[0].len + (delimiter - transfer->chunks[1].data);
    }
    return 0;
}

static inline void sfmpv_GoDdelim(SfdHandle *handle, int delimiter_mask) {
    SfdBufferTransfer transfer;
    const u8 *delimiter;
    int ignored_code;
    s32 consumed;

    if (fn_12_22390(handle, handle->video_buffer, &transfer) != 0 || transfer.chunks[0].len == 0) {
        return;
    }
    delimiter = sfmpv_SearchTransferDelimiter(&transfer, delimiter_mask, &ignored_code);
    if (delimiter == 0) {
        int size = transfer.chunks[0].len + transfer.chunks[1].len;
        size -= 3;
        consumed = size > 0 ? size : 0;
    } else {
        consumed = sfmpv_DelimiterOffset(&transfer, delimiter);
    }
    fn_12_22008(handle, handle->video_buffer, consumed);
}

#pragma use_lmw_stmw on
int fn_12_28CC4(SfdHandle *handle, s32 active_size, s32 delimiter_type, int *processed) {
    SfdMpvFrameWork *work;
    SfdMpvDecodeTimer *timer = &handle->timer;
    SJ *stream;
    SJCK chunk;
    int result;
    s32 buffer;

    *processed = 0;
    work = handle->video_work;
    buffer = handle->video_buffer;
    handle->decode_wait = 0;
    if (work->decode_mode != 0xCC) {
        delimiter_type &= 0xCC;
    }
    result = fn_12_21E40(handle, buffer, &stream);
    if (result != 0) {
        return 0;
    }
    if ((delimiter_type & 0xC8) != 0) {
        fn_12_2AC80(handle, 1);
    }
    if (delimiter_type == 0x80) {
        SfdMpvTimeCodeSnapshot *snapshot = &timer->reserved_snapshot;

        buffer = handle->video_buffer;
        if (handle->video_total < 0) {
            handle->video_total = fn_12_21F28(handle, buffer) + 4;
        }
        if (snapshot->value < 0) {
            *snapshot = timer->maximum;
        }
    }
    if (delimiter_type == 0x80 && fn_12_23250(handle) != 0) {
        if (sfmpv_Concat(handle, stream) == 0) {
            *processed = 1;
        }
    } else if (delimiter_type == 0x80 && fn_12_231A0(handle) != 0) {
        sfmpv_SkipEndcode(handle, stream);
        *processed = 1;
    } else if (sfmpv_IsTermDec(handle, active_size, delimiter_type)) {
        fn_12_2AC98(handle);
    } else if (active_size <= 4) {
        handle->decode_wait = 1;
    } else if ((delimiter_type & 0x4C) != 0) {
        SfdBufferTransfer transfer;

        if (fn_12_22390(handle, handle->video_buffer, &transfer) != 0) {
            chunk.data = NULL;
            chunk.len = 0;
        } else {
            chunk = transfer.chunks[0];
        }
        result = fn_12_284F8(handle, &chunk, stream, (delimiter_type & work->decode_mode) != 0);
        if (result != 0) {
            return result;
        }
        if ((delimiter_type & work->decode_mode) != 0) {
            work->decode_mode = 0xCC;
        }
        *processed = 1;
    } else if ((delimiter_type & 2) != 0) {
        if (timer->reference_time_offset < 0) {
            return 0;
        }
        if (fn_12_27884(handle, &chunk) != 0) {
            result = sfmpv_SkipFrm(handle, stream);
            if (result == 0) {
                *processed = 1;
            }
        } else {
            result = fn_12_27478(handle, stream);
        }
    } else if (delimiter_type != 0x80) {
        sfmpv_GoDdelim(handle, 0xCC);
        *processed = 1;
    }
    return result;
}
