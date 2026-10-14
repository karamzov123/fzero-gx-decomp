/* Non-matching: best partial attempt (57.62% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern const f32 lbl_1_rodata_F50;
extern const f32 lbl_1_rodata_F70;
extern const f32 lbl_1_rodata_F74;
extern const f32 lbl_1_rodata_F78;
extern const f32 lbl_1_rodata_F7C;
extern const f64 lbl_1_rodata_F58;
extern const f64 lbl_1_rodata_F60;

typedef struct {
    f32 value[3];
} Fn1442D8Out;

typedef struct {
    u8 pad_0[0xD4];
    u16 count[0x24];
    void *table[0x100];
} Fn1442D8Data;

#define SAMPLE(index, outoff) do { \
    u16 count = data->count[(u16)(index)]; \
    if (count != 0) { \
        u8 *table = (u8 *)data->table[(u16)(index)]; \
        f32 value; \
        u16 first = *(u16 *)(table + 2); \
        if (time < (f32)first) { \
            value = *(f32 *)(table + 4); \
        } else { \
            u8 *last = table + (count << 4); \
            u16 lasttime = *(u16 *)(last - 14); \
            if (time >= (f32)lasttime) { \
                value = *(f32 *)(last - 12); \
            } else { \
                u32 i = 0; \
                u8 *segment; \
                u16 starttime; \
                u16 endtime; \
                s32 duration; \
                u32 mode; \
                f32 start; \
                f32 end; \
                f32 t; \
                while (time >= (f32)(*(u16 *)(table + i * 16 + 18))) \
                    i++; \
                segment = table + i * 16; \
                starttime = *(u16 *)(segment + 2); \
                endtime = *(u16 *)(segment + 18); \
                duration = endtime - starttime; \
                mode = *(u16 *)(segment) & 3; \
                start = *(f32 *)(segment + 4); \
                end = *(f32 *)(segment + 20); \
                t = (time - (f32)starttime) / (f32)duration; \
                if (mode == 1) { \
                    value = start + t * (end - start); \
                } else if (mode == 0) { \
                    f32 t2 = t * t; \
                    f32 t3 = t2 * t; \
                    f32 h0 = 1.0f + (2.0f * t3 - 3.0f * t2); \
                    f32 h1 = -2.0f * t3 + 3.0f * t2; \
                    value = start * h0 + end * h1; \
                    value += (0.03333333507180214f * (f32)duration) * \
                        (*(f32 *)(segment + 12) * (t + (t3 - 2.0f * t2)) + \
                         *(f32 *)(segment + 24) * (t3 - t2)); \
                } \
            } \
        } \
        out->value[outoff] = value; \
        result = 1; \
    } \
} while (0)

s32 fn_1_442D8(Fn1442D8Out *out, Fn1442D8Data *data, u32 index, f32 time) {
    s32 result = 0;
    SAMPLE(index, 0);
    SAMPLE(index + 1, 1);
    SAMPLE(index + 2, 2);
    return result;
}
