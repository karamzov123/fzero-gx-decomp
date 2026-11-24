#include "types.h"
#include "sofdec/sj.h"

/* A bit reader over an SJ stream. The buffer holds up to 32 bits and refills from the current chunk. */
typedef struct AhxBits {
    s32 used;
    SJ *sj;
    s32 buffer;
    s32 bits_left;
    s32 bit_pos;
    s32 sj_size;
    s32 chunk_size;
    SJCK chunk;
    s32 remaining;
    u8 *cursor;
} AhxBits;

extern u32 lbl_801309C0[];
u32 lbl_80186FA8;
AhxBits lbl_80186FAC[8];
extern u32 lbl_8012D9B8[];
extern u8 lbl_8012D9BC[];

extern void *memset(void *, int, u32);
extern void fn_800589BC(SJCK *, s32, SJCK *, SJCK *);

void fn_800502A0(AhxBits *bits);

static inline void AhxBitsSkip(AhxBits *bits, s32 count) {
    lbl_80186FA8++;
    if (bits->bits_left < count) {
        fn_800502A0(bits);
    }
    if (count > bits->bits_left) {
        bits->bit_pos += bits->bits_left;
        bits->bits_left = 0;
    } else {
        bits->bits_left -= count;
        bits->bit_pos += count;
    }
}

static inline u32 AhxBitsGet(AhxBits *bits, s32 count) {
    u32 value;

    lbl_80186FA8++;
    if (bits->bits_left < count) {
        fn_800502A0(bits);
    }
    if (count > bits->bits_left) {
        bits->bit_pos += bits->bits_left;
        bits->bits_left = 0;
        value = 0;
    } else {
        value = bits->buffer >> (bits->bits_left - count);
        value &= lbl_801309C0[count];
        bits->bits_left -= count;
        bits->bit_pos += count;
    }
    return value;
}

static inline int AhxBitsAtEnd(AhxBits *bits) {
    if (bits->sj->interface->get_num_data(bits->sj, 1) == 0 && bits->bits_left == 0 && bits->remaining == 0) {
        return 1;
    }
    return 0;
}

s32 fn_8004FF68(AhxBits *bits) {
    u32 window;
    u32 mask = lbl_801309C0[12];

    if (bits->bit_pos & 7) {
        AhxBitsSkip(bits, 8 - (bits->bit_pos & 7));
    }
    window = AhxBitsGet(bits, 12);
    while (!AhxBitsAtEnd(bits)) {
        if ((window & mask) == 0xFFF) {
            return 1;
        }
        if (window == 0x8001000C) { /* fzgx-allow: A1 bit pattern of the scan window, not an address */
            return 2;
        }
        window <<= 4;
        window |= AhxBitsGet(bits, 4);
    }
    return 0;
}

s32 fn_80050180(AhxBits *bits) {
    s32 end;

    if (bits->sj->interface->get_num_data(bits->sj, 1) == 0 && bits->bits_left == 0 && bits->remaining == 0) {
        end = 1;
    } else {
        end = 0;
    }
    return end;
}

s32 fn_800501EC(AhxBits *bits) {
    return bits->bit_pos;
}

/* WARNING: compiler-diff device, not original code. Retail keeps the read counter and shift in registers. */
#pragma opt_propagation off
s32 fn_800501F4(AhxBits *bits, s32 count) {
    u32 counter;
    s32 result;
    s32 shift;
    u32 *table;

    {
        u32 *counter_p;

        counter_p = &lbl_80186FA8;
        counter = *counter_p;
        *counter_p = counter + 1;
    }
    if (bits->bits_left < count) {
        fn_800502A0(bits);
    }
    if (count > bits->bits_left) {
        bits->bit_pos += bits->bits_left;
        bits->bits_left = 0;
        return 0;
    }
    table = lbl_801309C0;
    shift = bits->bits_left - count;
    result = (bits->buffer >> shift) & table[count];
    bits->bits_left = shift;
    bits->bit_pos += count;
    return result;
}
#pragma opt_propagation reset

void fn_800502A0(AhxBits *bits) {
    u32 v;
    SJ *sj;
    s32 count;
    s32 amount;
    SJCK first;
    SJCK second;
    u8 *p;

    count = (32 - bits->bits_left) / 8;
    if (bits->remaining < 4) {
        first = bits->chunk;
        if (first.len != 0) {
            fn_800589BC(&first, first.len - bits->remaining, &first, &second);
            bits->sj->interface->put_chunk(bits->sj, 0, &first);
            bits->sj->interface->unget_chunk(bits->sj, 1, &second);
        }
        sj = bits->sj;
        sj->interface->get_chunk(sj, 1, bits->chunk_size, &bits->chunk);
        bits->cursor = bits->chunk.data;
        bits->remaining = bits->chunk.len;
    }
    amount = bits->remaining;
    if (count < amount) amount = count;
    if (amount == 3) {
        p = bits->cursor;
        v = bits->buffer;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        bits->cursor = p;
        bits->buffer = v;
        bits->bits_left += 24;
        bits->remaining -= 3;
    } else if (amount == 2) {
        p = bits->cursor;
        v = bits->buffer;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        bits->cursor = p;
        bits->buffer = v;
        bits->bits_left += 16;
        bits->remaining -= 2;
    } else if (amount == 1) {
        p = bits->cursor;
        v = bits->buffer;
        v = (v << 8) | *p++;
        bits->cursor = p;
        bits->buffer = v;
        bits->bits_left += 8;
        bits->remaining -= 1;
    } else if (amount == 4) {
        p = bits->cursor;
        v = bits->buffer;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        bits->cursor = p;
        bits->buffer = v;
        bits->bits_left += 32;
        bits->remaining -= 4;
    }
}

void fn_800504BC(AhxBits *bits) {
    if (bits != 0) {
        memset(bits, 0, sizeof(AhxBits));
    }
}

AhxBits *fn_800504EC(SJ *sj) {
    AhxBits *bits;
    s32 i;
    u32 a;
    u32 b;

    for (i = 0; i < 8; i++) {
        if (lbl_80186FAC[i].used == 0) {
            break;
        }
    }
    if (i >= 8) {
        return 0;
    }

    bits = &lbl_80186FAC[i];
    memset(bits, 0, sizeof(AhxBits));
    bits->sj = sj;
    bits->bit_pos = 0;
    a = sj->interface->get_num_data(sj, 0);
    b = sj->interface->get_num_data(sj, 1);
    bits->sj_size = b + a;
    bits->chunk_size = bits->sj_size / 4;
    bits->remaining = 0;
    bits->chunk.data = 0;
    bits->chunk.len = 0;
    bits->cursor = 0;
    bits->used = 1;
    return bits;
}

u32 fn_80050670(u32 index, u8 **table) {
    *table = lbl_8012D9BC + index * 12288;
    return lbl_8012D9B8[index];
}
