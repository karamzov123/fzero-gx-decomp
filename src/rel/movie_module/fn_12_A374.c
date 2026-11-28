#include "types.h"

extern u8 lbl_12_data_68[72];



#pragma explicit_zero_data on
__declspec(section ".data") u8 lbl_12_data_68[72] __attribute__((aligned(8))) = {
    0x00U, 0x00U, 0x01U, 0x01U, 0x03U, 0x03U, 0x02U, 0x03U, 0x03U, 0x04U, 0x02U, 0x04U, 0x03U, 0x05U, 0x02U, 0x05U, 0x07U, 0x07U, 0x06U, 0x07U, 0x0BU, 0x08U, 0x0AU, 0x08U, 0x09U, 0x08U, 0x08U, 0x08U, 0x07U, 0x08U, 0x06U, 0x08U, 0x17U, 0x0AU, 0x16U, 0x0AU, 0x15U, 0x0AU, 0x14U, 0x0AU, 0x13U, 0x0AU, 0x12U, 0x0AU, 0x23U, 0x0BU, 0x22U, 0x0BU, 0x21U, 0x0BU, 0x20U, 0x0BU, 0x1FU, 0x0BU, 0x1EU, 0x0BU, 0x1DU, 0x0BU, 0x1CU, 0x0BU, 0x1BU, 0x0BU, 0x1AU, 0x0BU, 0x19U, 0x0BU, 0x18U, 0x0BU, 0x0FU, 0x0BU, 0x08U, 0x0BU
};
#pragma explicit_zero_data reset

/* --- rel/movie_module/fn_12_A374.c --- */
extern u8 lbl_12_data_68[72];
#define SKIP(n) do { bits += (n); if (bits >= 32) { bits -= 32; current = next << bits; next = *p++; } else current <<= (n); } while(0)
#define PEEK(n, dst) do { dst = current >> (32-(n)); if (bits > 32-(n)) dst |= next >> (64-(n)-bits); } while(0)
#define ONE(dst) do { dst = current >> 31; if (bits == 31) { current = next; next = *p++; bits = 0; } else { current <<= 1; bits++; } } while(0)
s32 fn_12_A374(s32 arg0, s32 length, s32 count) {
    s32 shift;
    s32 remaining;
    s32 code;
    u32 value;
    u32 lab_v;
    u32 first;
    u32 next;
    #define current buffer.value
    struct { u32 value; } buffer;
    s32 bits;
    u32 *p;
    p = (u32 *)(arg0 & ~3);
    bits = (arg0 - (u32)p) * 8;
    next = p[1];
    first = *p++;
    p++;
    first <<= bits;
    if (bits) { current = next << bits; value = first | (next >> (32-bits)); }
    else { value = first; current = next; }
    next = *p++;
    if (((0x101) != (value))) return 0;
    if (bits >= 27) {
        bits -= 27;
        current = next;
        if (bits) current = next << bits;
        next = *p++;
    } else { current <<= 5; bits += 5; }
    ONE(value);
    if (value != 0) return 0;
    ONE(value);
    if (value == 0) return 0;
    lab_v = code;
    PEEK(6,lab_v);
    switch(lab_v) {
    case 22: case 23: SKIP(5); break;
    case 11: SKIP(6); break;
    default: return 0;
    }
    remaining = count - 1;
    do {
        PEEK(11,value);
        if (value != 8) break;
        SKIP(11);
        remaining -= 33;
    } while (remaining > 33);
    if (remaining <= 0 || remaining > 33) return 0;
{
    s32 entry;
    entry = ((s16 *)lbl_12_data_68)[remaining];
{
    u32 width;
    width = entry & 255;
    shift = 32 - width;
    if (bits >= shift) {
        bits -= shift;
        if (bits) {
            current |= next >> (width-bits);
            value = current >> shift;
            current = next << bits;
        } else {
            remaining = current >> shift;
            value = remaining;
            current = next;
        }
        next = *p++;
    } else {
        value = current >> shift;
        bits += width;
        current <<= width;
}
    }
    if (value != (u32)entry >> 8) return 0;
}
    PEEK(6,lab_v);
    switch(lab_v) {
    case 22: case 23: bits += 5; if(bits >= 32) { bits -= 32; p++; } break;
    case 11: bits += 6; if(bits >= 32) { bits -= 32; p++; } break;
    default: return 0;
    }
    p = (u32 *)((u8 *)p + ((bits + 7) >> 3));
    return length >= (s32)((u32)p - 8 - arg0);
}
