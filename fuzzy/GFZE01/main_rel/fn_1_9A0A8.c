/* Non-matching: best partial attempt (93.42% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 14.0f;
    s = 0.0f;
    s = 900.0f;
    s = 2.0f;
    s = 10.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0f;
    d = 0.8f;
    d = 0.1f;
    s = 0.003921568859368563f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0f;
    s = 0.15000000596046448f;
    s = 0.10000000149011612f;
    s = 0.10999999940395355f;
    s = 0.11999999731779099f;
    d = 4503601774854144.0f;
    s = 0.5f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 40.0f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 0.800000011920929f;
    s = 1.6000001430511475f;
    s = 0.6000000238418579f;
    s = 0.7071067690849304f;
    s = -1.8000000715255737f;
    s = 1.2000000476837158f;
    s = 0.23999999463558197f;
    s = 0.6399999856948853f;
    s = -0.20000000298023224f;
    s = -2.0999999046325684f;
    s = 32768.0f;
    s = 24576.0f;
    s = 53248.0f;
    s = 40960.0f;
    s = 0.75f;
    s = 0.11313708871603012f;
    s = 80.0f;
    s = 9.999999046325684f;
    s = 0.8999999761581421f;
    s = 0.20000000298023224f;
    s = 32767.0f;
    s = 4.0f;
    s = 0.25f;
    s = 0.4000000059604645f;
    s = 0.949999988079071f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.05f;
    d = 4503599627370496.0f;
    s = 15.0f;
    s = 35.0f;
}
#pragma section code_type ".text"

extern s32 fn_1_6EC0(u8);
extern u32 fn_1_5910(void);
extern void fn_1_681C(u8, u8 *);

static inline f32 fn_1_9A0A8_array_read(f32 *array, s32 index) { return array[index]; }
#pragma peephole off
f32 fn_1_9A0A8(void *object, u32 lab_unused0, u32 lab_unused1) {
    u8 *p;
    f32 result;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 len;
    struct { f32 value; } d;
    f32 t;
    f32 vec[3];

    p = (u8 *)object;
    result = 1.0f;
    if (fn_1_6EC0(*(u8 *)(p + 0x475)) == 0) {
    } else if ((u32)(s8)*(u8 *)(p + 0x475) != fn_1_5910()) {
    } else {
        fn_1_681C(*(u8 *)(p + 0x475), (u8 *)vec);
        dx = fn_1_9A0A8_array_read(vec, 0) - *(f32 *)(p + 0x7c);
        dy = fn_1_9A0A8_array_read(vec, 1);
        dy -= *(f32 *)(p + 0x80);
        dz = fn_1_9A0A8_array_read(vec, 2);
        dz = dz - *(f32 *)(((0x84) + (p)));
        len = (f32)(dx * dx) + dy * dy + dz * dz;
        d.value = len - 15.0f;
        d.value = (d.value > 0.0f) ? d.value : 0.0f;
        t = d.value / 35.0f;
        if (t < 0.0f) {
            result = 0.0f;
        } else {
            d.value = len - 15.0f;
            d.value = (d.value > 0.0f) ? d.value : 0.0f;
            t = d.value / 35.0f;
            if (t > 1.0f) {
                result = 1.0f;
            } else {
                d.value = len - 15.0f;
                d.value = (d.value > 0.0f) ? d.value : 0.0f;
                result = d.value / 35.0f;
            }
        }
    }
    return result;
}
#pragma peephole reset

