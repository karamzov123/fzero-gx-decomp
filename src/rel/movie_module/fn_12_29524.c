
#include "types.h"

typedef struct SJCK {
    unsigned char *data;
    long len;
} SJCK;

typedef struct SfdBufferTransfer {
    SJCK chunks[2];
    int reserved[3];
} SfdBufferTransfer;

int fn_12_29524(SfdBufferTransfer *transfer, int current_type, const unsigned char *delimiter);

const unsigned char *fn_12_A0D8(const unsigned char *data, int length, int mask);

int fn_12_A2C4(const unsigned char *data);

void *memcpy(void *destination, const void *source, unsigned long size);

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

int fn_12_29524(SfdBufferTransfer *transfer, int current_type, const unsigned char *delimiter) {
    unsigned char delimiter_bytes[4];
    int type;
    int ignored_code;
    if (delimiter == 0) {
        return 1;
    }
    if (delimiter == transfer->chunks[0].data) {
        return 1;
    }
    if ((unsigned long)delimiter >= (unsigned long)transfer->chunks[0].data &&
        (unsigned long)delimiter <
            (unsigned long)transfer->chunks[0].data + transfer->chunks[0].len) {
        int overflow = (unsigned long)delimiter + 4 -
                       ((unsigned long)transfer->chunks[0].data + transfer->chunks[0].len);
        if (overflow > 0) {
            if (overflow > transfer->chunks[1].len) {
                return 1;
            }
            memcpy(delimiter_bytes, delimiter, 4 - overflow);
            memcpy(delimiter_bytes + 4 - overflow, transfer->chunks[1].data, overflow);
        } else {
            memcpy(delimiter_bytes, delimiter, 4);
        }
    } else if ((unsigned long)delimiter >= (unsigned long)transfer->chunks[1].data &&
               (unsigned long)delimiter <
                   (unsigned long)transfer->chunks[1].data + transfer->chunks[1].len) {
        int overflow = (unsigned long)delimiter + 4 -
                       ((unsigned long)transfer->chunks[1].data + transfer->chunks[1].len);
        if (overflow > 0) {
            return 1;
        }
        memcpy(delimiter_bytes, delimiter, 4);
    } else {
        return 1;
    }
    type = fn_12_A2C4(delimiter_bytes);
    switch (type) {
    case 8:
        if ((current_type & 0x40) != 0) {
            const unsigned char *next = sfmpv_SearchTransferDelimiter(transfer, 8, &ignored_code);
            if (next == 0 || next == delimiter) {
                return 1;
            }
        }
        break;
    case 4:
        if ((current_type & 0x48) != 0) {
            const unsigned char *next = sfmpv_SearchTransferDelimiter(transfer, 4, &ignored_code);
            if (next == 0 || next == delimiter) {
                return 1;
            }
        }
        break;
    case 0x40:
    case 0x80:
        break;
    default:
        return 1;
    }
    return 0;
}
