#include "sofdec/mpv.h"

extern void *memcpy(void *dst, const void *src, u32 count);
extern int fn_12_A2C4(const unsigned char *data);
extern const unsigned char *fn_12_A0D8(const unsigned char *data, int length, int mask);

typedef struct {
    const u8 *data;
    s32 len;
    const u8 *data2;
    s32 len2;
} MPVChunks;

/* Search both chunks and the delimiter spanning their boundary. */
static inline const u8 *find_delimiter(MPVChunks *chunks, int mask, u8 *buffer) {
    s32 tail;
    s32 head;
    s32 i;
    const u8 *scan;
    s32 count;
    const u8 *found;

    found = fn_12_A0D8(chunks->data, chunks->len, mask);
    if (found != 0) {
        fn_12_A2C4(found);
        return found;
    }
    if (chunks->len2 == 0) return 0;
    head = chunks->len < 3 ? chunks->len : 3;
    tail = chunks->len2 < 3 ? chunks->len2 : 3;
    memcpy(buffer, chunks->data + chunks->len - head, head);
    memcpy(buffer + head, chunks->data2, tail);
    count = head + tail - 3;
    for (i = 0, scan = buffer; i < count; scan++, i++) {
        if (fn_12_A2C4(scan) & mask) {
            const u8 *result;
            result = chunks->data + chunks->len - head;
            return result + i;
        }
    }
    found = fn_12_A0D8(chunks->data2, chunks->len2, mask);
    if (found != 0) {
        fn_12_A2C4(found);
        return found;
    }
    return 0;
}

#pragma opt_propagation off
int fn_12_29524(MPVChunks *chunks, u32 flags, const u8 *pos) {
    u8 boundary8[6];
    u8 boundary4[6];
    u32 header;
    s32 remain;
    const u8 *found;
    const u8 *second;

    if (pos == 0) return 1;
    if (pos == chunks->data) return 1;
    if (pos >= chunks->data && pos < chunks->data + chunks->len) {
        remain = (pos + 4) - (chunks->data + chunks->len);
        if (remain > 0) {
            if (remain > chunks->len2) return 1;
            memcpy(&header, pos, 4 - remain);
            memcpy((u8 *)&header + 4 - remain, chunks->data2, remain);
        } else {
            memcpy(&header, pos, 4);
        }
    } else {
        if (pos >= (second = chunks->data2) && pos < second + chunks->len2) {
            remain = (pos + 4) - (chunks->data2 + chunks->len2);
            if (remain > 0) return 1;
            memcpy(&header, pos, 4);
        } else {
            return 1;
        }
    }
    switch (fn_12_A2C4((const u8 *)&header)) {
    case 0x40:
    case 0x80:
        break;
    case 8:
        if (flags & 0x40) {
            found = find_delimiter(chunks, 8, boundary8);
            if (found == 0 || found == pos) return 1;
        }
        break;
    case 4:
        if (flags & 0x48) {
            found = find_delimiter(chunks, 4, boundary4);
            if (found == 0 || found == pos) return 1;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
