#include "types.h"

/* sfadxt_ExcludeHdr, from the CC0 MK Deception decomp (sfd_adxt.c) */

typedef struct SJ SJ;

typedef struct AdxSjdHandle AdxSjdHandle;
typedef struct ADXStream ADXStream;
typedef struct AXRNAHandle AXRNAHandle;
typedef struct LSCObject LSCObject;
typedef struct ADX_AMP ADX_AMP;
typedef struct ADXTHandle {
    s8 used;
    s8 status;
    s8 stream_type;
    s8 maximum_channels;
    AdxSjdHandle *decoder;
    ADXStream *stream;
    AXRNAHandle *rna;
    SJ *stream_sj;
    SJ *input_sj;
    SJ *output_sj[2];
    u8 *input_buffer;
    s32 input_buffer_size;
    s32 input_extra_size;
    u8 *output_buffer;
    s32 output_buffer_size;
    s32 output_buffer_distance;
    s32 server_frequency;
    s16 stream_buffer_sectors;
    s16 reload_threshold_sectors;
    s16 output_volume;
    s16 output_pan[2];
    s16 output_balance;
    s32 maximum_decode_samples;
    s32 loop_count;
    s32 loop_end_sector_bytes;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s16 error_code;
    u8 reserved_62[2];
    s32 field_64;
    s16 field_68;
    s16 field_6A;
    s8 stream_loop_enabled;
    s8 auto_receiver;
    u8 reserved_6E[2];
    s8 suppress_playback;
    s8 decoder_ready;
    s8 paused;
    u8 reserved_73;
    ADX_AMP *amplifier;
    SJ *amplifier_input[2];
    SJ *amplifier_output[2];
    s32 time_offset;
    s32 eos_sector;
    s32 loop_sample_count;
    LSCObject *linked_stream_controller;
    s8 link_enabled;
    u8 reserved_99[3];
    u32 playback_time;
    s32 playback_start_vsync;
    s32 linked_decoded_samples;
    s8 pending_stream_start;
    u8 reserved_A9[3];
    u8 *work_end;
    const char *pending_filename;
    void *pending_directory;
    s32 pending_file_offset;
    s32 pending_file_sectors;
} ADXTHandle;
typedef struct SfdHandle SfdHandle;
int fn_12_24A88(SfdHandle *handle, int error);
typedef struct SfdTransportInterface SfdTransportInterface;
typedef struct SfdTransportState {
    int prepared;
    int terminated;
    void *context;
    const SfdTransportInterface *interface;
    int parameter_10;
    int parameter_14;
    int parameter_18;
    int buffer_output3;
    int state;
    unsigned char unknown_0024[0x20];
} SfdTransportState;
/* GX's player handle predates MK Deception's layout; only the members used here are placed. */
struct SfdHandle {
    unsigned char unknown_0000[0x1AA0];
    SfdTransportState transports[9];
};
typedef struct SfdAdxtParameters {
    int stream_buffer_size;
    int stream_buffer_extra_size;
    void *stream_buffer;
    int maximum_channels;
    int decoder_work_size;
    int decoder_buffer_size;
    void *decoder_buffer;
} SfdAdxtParameters;
typedef void (*SfdAdxtCopyFn)(SfdHandle *handle, const unsigned char *data, int size,
                              int *consumed);
typedef struct SfdAdxtWork {
    ADXTHandle *decoder;
    SJ *stream_joint;
    SfdAdxtParameters para;
    int maximum_time_value;
    int maximum_time_scale;
    int paused;
    int discarded_samples;
    int header_inserted;
    int sample_offset;
    SfdAdxtCopyFn copy;
    int seek_depth;
    int server_frequency;
    int copied_bytes;
    int field_4C;
} SfdAdxtWork;
extern int fn_12_23F34(SfdHandle *handle);
extern int fn_8004B9A4(const unsigned char *data, int size, int *header_size);
extern int fn_8004B974(const unsigned char *data, int size, int *end_size);
extern void fn_12_20CE8(SfdHandle *handle, const unsigned char *data, int size, int *consumed);

static inline SfdAdxtWork *sfadxt_GetWork(SfdHandle *handle) {
    return handle->transports[3].context;
}

static inline int sfadxt_SearchFrmTop(SfdHandle *handle, const unsigned char *data, int size) {
    const unsigned char *offset;
    const unsigned char *position;
    const unsigned char *end;
    const unsigned char *latest_offset;
    unsigned long latest_end_address;
    int found_end;
    const unsigned char *limit;
    found_end = 0;
    offset = data;
    latest_end_address = 0;
    end = data + size;
    latest_offset = 0;
    limit = data + 0x24;
    while (offset < limit) {
        position = offset;
        found_end = 0;
        while (position < end) {
            if ((signed char)*position < 0) {
                int end_size;
                found_end = 1;
                if (fn_8004B974(position, 0x12, &end_size) != 0 &&
                    latest_end_address < (unsigned long)position) {
                    latest_end_address = (unsigned long)position;
                    latest_offset = offset;
                }
                break;
            }
            position += 0x12;
        }
        if (found_end == 0) {
            break;
        }
        offset += 2;
    }
    if (found_end != 0) {
        if (latest_offset == 0) {
            fn_12_24A88(handle, 0xFF000C0A);
            offset = data;
        } else {
            offset = latest_offset;
        }
    }
    return offset - data;
}

#pragma use_lmw_stmw on
void fn_12_20B90(SfdHandle *handle, const unsigned char *data, int size, int *consumed) {
    SfdAdxtWork *work;
    int excluded;
    int header_size;
    *consumed = 0;
    work = sfadxt_GetWork(handle);
    if (size < 0x120) {
        return;
    }
    if (fn_8004B9A4(data, size, &header_size) != 0) {
        excluded = header_size;
    } else if (fn_12_23F34(handle) >= 108) {
        excluded = 0;
    } else {
        excluded = sfadxt_SearchFrmTop(handle, data, size);
    }
    work->copy = fn_12_20CE8;
    *consumed = excluded;

}
