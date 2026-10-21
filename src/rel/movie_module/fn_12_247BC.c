#include "types.h"

extern void *fn_12_3310C(const void *, u32);
extern int fn_12_32EAC(void *, s32 *);
extern void fn_12_330E0(void *);
extern int fn_12_24670(void *, void *, int);

static inline s32 read_bytes(u8 *p, s32 count) {
    s32 value = *p++;
    int i;
    for (i = 1; i < count; i++) {
        value <<= 8;
        value |= *p++;
    }
    return value;
}

static inline s32 get_info(const void *data, u32 size) {
    void *movie;
    s32 result;
    movie = fn_12_3310C(data, size);
    if (movie == 0) return 0;
    if (fn_12_32EAC(movie, &result) == 0) result = 0;
    fn_12_330E0(movie);
    return result;
}

int fn_12_247BC(void *self, s32 type, u8 *data, s32 size, s32 *out) {
    s32 code;
    *out = 0;
    if (type != 2) return 0;
    data -= 6;
    size += 6;
    code = read_bytes(data, 4);
    if (code != 0x1bf) {
        data -= 2;
        size += 2;
        code = read_bytes(data, 4);
        if (code != 0x1bf) return 0;
    }
    if (!get_info(data - 12, size + 12)) return 0;
    *out = fn_12_24670(self, data - 12, size + 12);
    return 1;
}
