#include "types.h"

/* sfmpv_GetActiveSize, from the CC0 MK Deception decomp (sfd_mpv.c). GX's version has no
   has_data output. */

typedef struct SJCK {
    unsigned char *data;
    long len;
} SJCK;
const unsigned char *fn_12_A0D8(const unsigned char *data, int length, int mask);
void *fn_12_A1C4(const unsigned char *data, int length, int mask);
int fn_12_A2C4(const unsigned char *data);
typedef struct SfdHandle SfdHandle;
int fn_12_24A88(SfdHandle *handle, int error);
typedef struct SfdTransportInterface SfdTransportInterface;
typedef struct SfdBufferTransfer {
    SJCK chunks[2];
    int reserved[3];
} SfdBufferTransfer;
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
/* GX's player handle predates MK Deception's layout; only the fields used here are placed. */
struct SfdHandle {
    unsigned char unknown_0000[0x28];
    int ring_alignment;
    unsigned char unknown_002C[0x1AA0 - 0x2C];
    SfdTransportState transports[9];
};
int fn_12_21C00(SfdHandle *handle, int buffer_index);
int fn_12_22390(SfdHandle *handle, int buffer_index, SfdBufferTransfer *transfer);
void fn_12_21F48(SfdHandle *handle, int buffer_index, unsigned char *position,
                 unsigned char *end_position);
void fn_12_21FA4(SfdHandle *handle, int buffer_index, unsigned char **position,
                 unsigned char **end_position);
int fn_12_21F38(SfdHandle *handle, int buffer_index);
void *memcpy(void *destination, const void *source, unsigned long size);
extern int fn_12_29524(SfdBufferTransfer *transfer, int current_type,
                       const unsigned char *delimiter);

int fn_12_29524(SfdBufferTransfer *transfer, int current_type, const unsigned char *delimiter);

static inline const unsigned char *sfmpv_SearchTransferDelimiter(SfdBufferTransfer *transfer,
                                                                 int delimiter_mask, int *code) {
    unsigned char boundary[8];
    const unsigned char *delimiter;
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

static inline int sfmpv_DelimiterOffset(const SfdBufferTransfer *transfer,
                                        const unsigned char *delimiter) {
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

static inline const unsigned char *sfmpv_BsearchTransferDelimiter(const SfdBufferTransfer *transfer,
                                                                  int delimiter_mask, int *code) {
    const unsigned char *delimiter;
    if (transfer->chunks[1].len != 0) {
        unsigned char boundary[8];
        long tail;
        long head;
        int i;
        delimiter = fn_12_A1C4(transfer->chunks[1].data + transfer->chunks[1].len,
                               transfer->chunks[1].len, delimiter_mask);
        if (delimiter != 0) {
            *code = fn_12_A2C4(delimiter);
            return delimiter;
        }
        tail = transfer->chunks[0].len < 3 ? transfer->chunks[0].len : 3;
        head = transfer->chunks[1].len < 3 ? transfer->chunks[1].len : 3;
        memcpy(boundary, transfer->chunks[0].data + transfer->chunks[0].len - tail, tail);
        memcpy(boundary + tail, transfer->chunks[1].data, head);
        for (i = 0; i < tail + head - 3; i++) {
            int found_code = fn_12_A2C4(boundary + i);
            if ((found_code & delimiter_mask) != 0) {
                *code = found_code;
                return transfer->chunks[0].data + transfer->chunks[0].len - tail + i;
            }
        }
    }
    delimiter = fn_12_A1C4(transfer->chunks[0].data + transfer->chunks[0].len,
                           transfer->chunks[0].len, delimiter_mask);
    if (delimiter != 0) {
        *code = fn_12_A2C4(delimiter);
        return delimiter;
    }
    return 0;
}

static inline int sfmpv_ChkRingSpace(SfdHandle *handle) {
    int buffer_index = handle->transports[2].parameter_10;
    if (fn_12_21F38(handle, buffer_index) - fn_12_21C00(handle, buffer_index) <
        handle->ring_alignment) {
        return fn_12_24A88(handle, 0xFF000F1C);
    }
    return 0;
}

#pragma use_lmw_stmw on
int fn_12_298AC(SfdHandle *handle, int *active_size, int *delimiter_type) {
    int buffer_index = handle->transports[2].parameter_10;
    SfdBufferTransfer transfer;
    const unsigned char *delimiter;
    unsigned char *cached_delimiter;
    unsigned char *cached_end;
    unsigned char *transfer_end;
    int type;
    int result;
    int ignored_code;
    *active_size = 0;
    *delimiter_type = 0;
    result = fn_12_22390(handle, buffer_index, &transfer);
    if (result != 0) {
        return result;
    }
    if (transfer.chunks[0].len == 0) {
        return 0;
    }
    type = 0;
    delimiter = sfmpv_SearchTransferDelimiter(&transfer, 0xCE, &type);
    if (delimiter != transfer.chunks[0].data) {
        if (delimiter != 0) {
            *active_size = sfmpv_DelimiterOffset(&transfer, delimiter);
        } else {
            int size = transfer.chunks[0].len + transfer.chunks[1].len - 3;
            *active_size = size < 0 ? 0 : size;
        }
        return 0;
    }
    *delimiter_type = type;
    *active_size = 4;
    if ((type & 0x80) != 0) {
        return 0;
    }
    fn_12_21FA4(handle, buffer_index, &cached_delimiter, &cached_end);
    if (fn_12_29524(&transfer, type, cached_delimiter) != 0) {
        cached_delimiter = 0;
        if (transfer.chunks[1].len == 0) {
            transfer_end = transfer.chunks[0].data + transfer.chunks[0].len;
        } else {
            transfer_end = transfer.chunks[1].data + transfer.chunks[1].len;
        }
        if (cached_end != transfer_end) {
            cached_end = transfer_end;
            cached_delimiter =
                (unsigned char *)sfmpv_BsearchTransferDelimiter(&transfer, 0xCC, &ignored_code);
            fn_12_21F48(handle, buffer_index, cached_delimiter, cached_end);
        }
    }
    if (cached_delimiter == 0) {
        return sfmpv_ChkRingSpace(handle);
    }
    switch (fn_12_A2C4(cached_delimiter)) {
    case 8:
        if ((type & 0x40) != 0) {
            const unsigned char *next = sfmpv_SearchTransferDelimiter(&transfer, 8, &ignored_code);
            if (next == 0 || next == cached_delimiter) {
                return sfmpv_ChkRingSpace(handle);
            }
        }
        break;
    case 4:
        if ((type & 0x48) != 0) {
            const unsigned char *next = sfmpv_SearchTransferDelimiter(&transfer, 4, &ignored_code);
            if (next == 0 || next == cached_delimiter) {
                return sfmpv_ChkRingSpace(handle);
            }
        }
        break;
    case 0x40:
    case 0x80:
    default:
        break;
    }
    *active_size = sfmpv_DelimiterOffset(&transfer, cached_delimiter);
    return 0;
}
