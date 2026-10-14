/* Non-matching: best partial attempt (19.85% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

static u32 read_bit(const u8 *src, u32 bit) {
    return (src[bit >> 3] >> (bit & 7)) & 1;
}

static u32 read_code(const u8 *src, u32 *bit, u32 count) {
    u32 value = 0;
    u32 i;
    for (i = 0; i < count; i++) {
        value |= read_bit(src, *bit) << (count - 1 - i);
        (*bit)++;
    }
    return value;
}

void fn_1_F4810(const u8 *src, u8 *head, u8 *out, u8 *out_count,
                u8 *a, u8 *b, u8 *c, u8 *run_count, u8 *tail) {
    u8 table[0x81c0];
    u32 bit = 8;
    u32 first = read_code(src, &bit, 7);
    u32 second, i, j;
    *head = first;
    bit += 4 * 8;
    bit += 4 * 8;
    second = read_code(src, &bit, 5);
    *c = second;
    *b = read_code(src, &bit, 3);
    *a = read_code(src, &bit, 2);
    *run_count = read_code(src, &bit, 2);
    bit += 9;
    for (i = 0; i < *run_count; i++) {
        u32 flag = read_code(src, &bit, 1);
        u32 code = read_code(src, &bit, 7);
        if (first >= 3) bit += 5;
        if (first >= 2) bit += 7;
        if (flag) {
            out[0] = (u8)code;
            out++;
            bit += 2;
            if (first < 2) bit += 7;
            *tail++ = (u8)read_code(src, &bit, 1);
            if (tail[-1]) {
                for (j = 0; j < 0x81c0; j++)
                    table[j] = (u8)read_code(src, &bit, 8);
                *out++ = table[0x81c0 - 12];
                *out++ = table[0x81c0 - 4];
                *out++ = table[0x81c0 - 8];
            }
            out -= 1;
        }
    }
    *out_count = (u8)i;
}
