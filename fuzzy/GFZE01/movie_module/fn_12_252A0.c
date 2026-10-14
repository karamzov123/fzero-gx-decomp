/* Non-matching: best partial attempt (97.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MpsHandle MpsHandle;

typedef struct SfmpsValues {
    s32 value_00;
    s32 value_04;
    s32 value_08;
    s32 value_0C;
    s32 value_10;
    s32 value_14;
    s32 value_18;
    s32 value_1C;
} SfmpsValues;

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
    s32 delimiter_state;
    void *element_outputs[0x44];
    void *element_callback;
    void *element_callback_argument;
} SfmpsWork;

typedef struct SfmpsRecordValues {
    s32 value_00;
    s32 value_04;
    s32 value_08;
} SfmpsRecordValues;

typedef struct SfdEntry {
    u8 pad_00[0x115C];
    s32 field_24;
} SfdEntry;

typedef struct SfdRecord {
    s32 flag;
    s32 field_04;
    s32 field_08;
    s32 field_0C;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1C;
    s32 field_20;
} SfdRecord;

typedef struct SfdHandle {
    u8 pad_0000[0x8];
    s32 field_08;
    u8 pad_000C[0x918];
    s32 field_924;
    s32 field_928;
    u8 pad_092C[0x4];
    s32 field_930;
    s32 field_934;
    u8 pad_0938[0xC0];
    s32 field_9F8;
    u8 pad_09FC[0x3D8];
    s32 field_DD4;
    s32 field_DD8;
    u8 pad_0DDC[0x35C];
    u8 pad_1138[0x74];
    u8 pad_11AC[0x940];
    SfmpsWork *work;
    u8 pad_1AF0[0x4];
    s32 field_1AF4;
    s32 field_1AF8;
    s32 field_1AFC;
    s32 field_1B00;
    u8 pad_1B04[0xE04];
    u8 *record_base;
} SfdHandle;

extern int fn_12_696C(MpsHandle *handle, SfmpsValues *values, int index);
extern int fn_12_6A18(MpsHandle *handle, SfmpsRecordValues *values);
extern int fn_12_21D50(SfdHandle *handle, int id);
extern int fn_12_21E94(SfdHandle *handle, int arg);
extern void fn_12_21D60(SfdHandle *handle, int id, int flag);
extern int fn_12_2D73C(SfdHandle *handle, int kind);
extern int fn_12_2F1F0(SfdHandle *handle, u32 kind);
extern void fn_12_2D7DC(SfdHandle *handle, int kind, int flag);

#pragma opt_propagation off
void fn_12_252A0(SfdHandle *handle) {
    MpsHandle * fzgx_live;
    SfmpsRecordValues record_values;
    SfmpsValues probe_values;
    SfmpsValues stream_values;
    s32 index;
    s32 video_bound;
    u32 audio_bound;
    s32 flag_c;
    s32 audio_bound_2;
    MpsHandle *decoder;
    SfmpsWork *work;
    MpsHandle *movie_decoder;
    SfmpsWork *movie;
    SfmpsWork *clip;
    SfmpsWork *archive;
    void *base;
    SfdRecord *record;
    s32 limit;
    struct { s32 value; } flag_a;
    s32 flag_b;
    SfdEntry *entry;
    s32 current;

    audio_bound = 0;
    work = handle->work;
    fzgx_live = work->decoder;
    (void) fzgx_live;  /* fzgx: keeps the web at its definition */
    decoder = fzgx_live;
    video_bound = audio_bound;
    index = audio_bound;
    do {
        fn_12_696C(decoder, &probe_values, index);
        audio_bound_2 = (audio_bound_2 > probe_values.value_08) ? audio_bound_2 : probe_values.value_08;
        video_bound = (video_bound > probe_values.value_0C) ? video_bound : probe_values.value_0C;
        index++;
    } while (index < 3);
    work->max_audio_bound = audio_bound_2;
    work->max_video_bound = video_bound;
    flag_a.value = fn_12_21D50(handle, handle->field_1AFC);
    flag_b = fn_12_21D50(handle, handle->field_1AF8);
    flag_c = fn_12_21D50(handle, handle->field_1B00);
    if (((flag_c | (flag_a.value | flag_b)) != 1) &&
        (fn_12_21D50(handle, handle->field_1AF4) == 1)) {
        index = handle->field_1AF4;
        current = handle->field_08;
        limit = handle->field_9F8;
        entry = (SfdEntry *)((u8 *)handle + index * 0x74);
        if (current <= 0) {
            current = entry->field_24;
        }
        if (current <= 0) {
            current = limit;
        }
        if (current < limit) {
            limit = current;
        }
        if (fn_12_21E94(handle, 0) >= limit) {
            fn_12_21D60(handle, handle->field_1AFC, 1);
            fn_12_21D60(handle, handle->field_1AF8, 1);
            fn_12_21D60(handle, handle->field_1B00, 1);
        }
    }
    movie = handle->work;
    movie_decoder = movie->decoder;
    fn_12_6A18(movie_decoder, &record_values);
    if (record_values.value_08 != -1 && record_values.value_08 > 0) {
        handle->field_924 = record_values.value_08;
    }
    fn_12_696C(movie_decoder, &stream_values, 1);
    if (stream_values.value_10 != -1) {
        handle->field_928 = stream_values.value_10;
    }
    if (handle->field_930 == -1) {
        handle->field_930 = movie->max_audio_bound;
    }
    if (handle->field_934 == -1) {
        handle->field_934 = movie->max_video_bound;
    }
    clip = handle->work;
    if (fn_12_2D73C(handle, 6) == 1 && clip->max_audio_bound == 0 && fn_12_2F1F0(handle, 6) != 0) {
        fn_12_2D7DC(handle, 6, 0);
    }
    if (fn_12_2D73C(handle, 5) == 1 && clip->max_video_bound == 0 && fn_12_2F1F0(handle, 7) != 0) {
        fn_12_2D7DC(handle, 5, 0);
    }
    base = handle->record_base;
    if (base == 0) {
        record = 0;
    } else if (handle->work->concat_count > 0) {
        record = 0;
    } else {
        record = (SfdRecord *)((u8 *)base + 0x8A0);
    }
    if (record != 0) {
        archive = handle->work;
        if (archive->audio_pts_baseline != 0x7FFFFFFF) {
            handle->field_DD8 = archive->audio_pts_baseline - record->field_18;
            if (record->flag == 0) {
                record->field_04 = handle->field_924 * 50;
                record->field_08 = handle->field_928;
                record->field_0C = archive->max_video_bound;
                record->field_10 = archive->max_audio_bound;
                record->field_14 = handle->field_DD4;
                record->field_18 = archive->video_pts_baseline;
                record->field_1C = archive->first_video_stream;
                record->field_20 = archive->first_audio_stream;
            }
        }
    }
}
#pragma opt_propagation reset
