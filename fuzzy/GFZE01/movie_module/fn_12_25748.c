/* Non-matching: best partial attempt (98.73% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct SfdHandle SfdHandle;
typedef struct SfdObject SfdObject;
typedef struct SfdRange SfdRange;
typedef struct SfdRanges SfdRanges;
typedef struct SfdVtbl SfdVtbl;

typedef void (*SfdCallback)(void *object, s32 value);
typedef s32 (*SfdSizeQuery)(void *object, s32 index);
typedef void (*SfdRangeQuery)(void *object, s32 index, s32 count, SfdRange *range);
typedef void (*SfdRangeCommit)(void *object, s32 flag, SfdRange *range);

struct SfdVtbl {
    void *unknown_00[6];
    SfdRangeQuery range_query;
    void *unknown_1C;
    SfdRangeCommit range_commit;
    SfdSizeQuery size_query;
};

struct SfdObject {
    SfdVtbl *vtbl;
};

struct SfdRange {
    void *data;
    s32 length;
};

struct SfdRanges {
    SfdObject *object;
    SfdCallback begin;
    SfdCallback end;
    void *end_object;
};

struct SfdHandle {
    u8 pad_0000[0x1B00];
    s32 stream_index;
};

extern s32 fn_12_247BC(SfdHandle *handle, s32 arg1, s32 arg2, s32 arg3, s32 *out);
extern void fn_12_22668(SfdHandle *handle, s32 stream, s32 arg, SfdRanges *out);
extern void *fn_12_57F0(void *data, void *dst, u32 length);
extern u32 lbl_12_bss_7E88;

#pragma opt_common_subs off
s32 fn_12_25748(SfdHandle *handle, s32 arg1, s32 arg2, s32 arg3) {
    SfdObject * fzgx_live;
    SfdRanges ranges;
    SfdRange range;
    SfdRange range_tail;
    SfdRanges out_ranges;
    SfdRange out_range;
    SfdRange out_tail;
    SfdObject *object_2;
    s32 result;
    SfdCallback begin_cb;
    SfdCallback end_cb;
    void *end_object;
    s32 count;
    void *offset;
    s32 left;
    s32 status;
    SfdObject *object;
    s32 out;

    if (fn_12_247BC(handle, arg1, arg2, arg3, &out) != 0) {
        if (out != 0 && handle->stream_index != 8) {
            fn_12_22668(handle, handle->stream_index, 0, &ranges);
            object = ranges.object;
            begin_cb = ranges.begin;
            end_cb = ranges.end;
            end_object = ranges.end_object;
            if (object != 0) {
                count = arg3 + 0x12;
                offset = (void *)(arg2 - 0x12);
                if (object->vtbl->size_query(object, 0) < count) {
                    status = 0;
                } else {
                    object->vtbl->range_query(object, 0, count, &range);
                    fn_12_57F0(range.data, offset, range.length);
                    object->vtbl->range_commit(object, 1, &range);
                    if (range.length == 0) {
                        status = 0;
                    } else {
                        count = count - range.length;
                        offset = (u8 *)offset + range.length;
                        if (count > 0) {
                            object->vtbl->range_query(object, 0, count, &range_tail);
                            fn_12_57F0(range_tail.data, offset, range_tail.length);
                            object->vtbl->range_commit(object, 1, &range_tail);
                            if (range_tail.length != count) {
                                lbl_12_bss_7E88++;
                            }
                        }
                        status = 1;
                    }
                }
                if (status == 1) {
                    if (begin_cb != 0) {
                        begin_cb(handle, 0);
                    }
                    if (end_cb != 0) {
                        end_cb(end_object, 0);
                    }
                }
            }
        }
        return 1;
    }

    if (handle->stream_index == 8) {
        result = 1;
    } else {
        fn_12_22668(handle, handle->stream_index, arg1, &out_ranges);
        fzgx_live = out_ranges.object;
        object_2 = fzgx_live;
        begin_cb = out_ranges.begin;
        end_cb = out_ranges.end;
        end_object = out_ranges.end_object;
        if (object_2 == 0) {
            result = 1;
        } else {
            result = 0;
            left = arg3;
            if (object_2->vtbl->size_query(object_2, 0) < left) {
                result = 0;
            } else {
                object_2->vtbl->range_query(object_2, 0, left, &out_range);
                fn_12_57F0(out_range.data, (void *)arg2, out_range.length);
                object_2->vtbl->range_commit(object_2, 1, &out_range);
                if (out_range.length == 0) {
                    result = 0;
                } else {
                    left = left - out_range.length;
                    offset = (u8 *)arg2 + out_range.length;
                    if (left > 0) {
                        object_2->vtbl->range_query(object_2, 0, left, &out_tail);
                        fn_12_57F0(out_tail.data, offset, out_tail.length);
                        object_2->vtbl->range_commit(object_2, 1, &out_tail);
                        if (out_tail.length != left) {
                            lbl_12_bss_7E88++;
                        }
                    }
                    result = 1;
                }
            }
            if (result == 1) {
                if (begin_cb != 0) {
                    begin_cb(handle, arg1);
                }
                if (end_cb != 0) {
                    end_cb(end_object, arg1);
                }
            }
        }
    }
    return result;
}
#pragma opt_common_subs reset
