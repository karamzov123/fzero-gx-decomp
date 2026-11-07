/* Non-matching: best partial attempt (97.31% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/os/OSFastCast.h"
typedef struct { f32 x,y,z; } Vec;
extern u8 lbl_1_bss_6F1E4[85];
extern void fn_1_862D4(u8, Vec *);
extern void fn_1_8658C(u8, Vec *);
extern f32 fn_1_8652C(u8);
extern void fn_1_681C(u32, void *);
extern void fn_1_6898(u32, void *);
extern f32 lbl_8006D0B4(f32);
extern f64 __fabs(f64);
extern s16 camera_get_mode(void);
extern s32 camera_get_state(void);
extern f64 lbl_1_rodata_4598;
extern f32 lbl_1_rodata_4470, lbl_1_rodata_45A0, lbl_1_rodata_45A8;
extern f32 lbl_1_rodata_45AC, lbl_1_rodata_45B0, lbl_1_rodata_45B4;
extern f32 lbl_1_rodata_45C4, lbl_1_rodata_45C8, lbl_1_rodata_45CC;
extern struct { f32 value; } lbl_1_rodata_45A4;
extern struct { f64 value; } lbl_1_rodata_45B8;
extern struct { f32 value; } lbl_1_rodata_45C0;

static inline f32 clamp(f32 x) {
    f32 result = lbl_1_rodata_45C4;

    if (x < result) {
        return result;
    }
    result = lbl_1_rodata_45C8;
    if (x > result) {
        return result;
    }
    return x;
}

typedef struct { u8 flags; u8 id; u8 pad[14]; f32 value; } Rec;
#pragma opt_common_subs off
void fn_1_A47F4(u32 index, u8 speed, u32 object, s8 *whole, s8 *fraction) {
    Vec a;
    Vec b;
    Vec c;
    f32 distB;
    s32 offset;
    u8 byte;
    f32 source;
    f32 distance;
    f32 scaled;
    f32 distA;
    Vec d;
    f32 x;
    f32 y;
    f32 z;
    f32 x2;
    f32 y2;
    f32 z2;
    s32 nearer;
    s32 exceeds;
    u8 id;
    f32 base;
    f32 difference;
    s32 mode;
    s32 state;
    f32 factor;
    f32 output;
    f32 *entry;
    s32 v;

    offset = index * 20;
    byte = speed;
    id = lbl_1_bss_6F1E4[offset + 1];
    fn_1_862D4(id, &a);
    fn_1_8658C(id, &b);
    source = fn_1_8652C(id);
    fn_1_681C(object, &c);
    fn_1_6898(object, &d);

    x = c.x - d.x;
    y = c.y - d.y;
    z = c.z - d.z;
    {
        f32 q;

        q = x * x;
        q += y * y;
        q += z * z;
        distance = lbl_8006D0B4(q);
    }
    scaled = lbl_1_rodata_4598 * distance;
    x = b.x - d.x;
    y = b.y - d.y;
    z = b.z - d.z;
    distA = x * x;
    distA += y * y;
    distA += z * z;
    x2 = a.x - c.x;
    y2 = a.y - c.y;
    z2 = a.z - c.z;
    distB = x2 * x2;
    distB += y2 * y2;
    distB += z2 * z2;
    nearer = (distB <= distA) ? 1 : 0;
    exceeds = (scaled > source) ? 1 : 0;
    base = lbl_1_rodata_45A0 + (f32)(lbl_1_rodata_45A4.value * __OSu8tof32(&byte));
    difference = scaled - source;
    if (source >= lbl_1_rodata_45A8) {
        source = lbl_1_rodata_45A8;
    }
    if (scaled >= lbl_1_rodata_45AC) {
        scaled = lbl_1_rodata_45AC;
    }
    source = lbl_1_rodata_45B0 - source;
    scaled = lbl_1_rodata_45B0 - scaled;

    mode = camera_get_mode();
    state = camera_get_state();
    if (mode == id && (s8)state != 9) {
        factor = lbl_1_rodata_4470;
    } else if (exceeds) {
        factor = lbl_1_rodata_4470;
    } else {
        f32 magnitude = __fabs(difference);

        if (magnitude > lbl_1_rodata_45B4) {
            factor = lbl_1_rodata_45B4 / magnitude;
        } else {
            factor = lbl_1_rodata_4470;
        }
    }
    output = base * (scaled / (source * factor));
    output = (output - base) / lbl_1_rodata_45B8.value;
    output = lbl_1_rodata_45C0.value * output;
    output = clamp(output);
    if (nearer | (lbl_1_bss_6F1E4[offset] & 1)) {
        *(f32 *)&lbl_1_bss_6F1E4[offset + 16] = output;
    } else {
        entry = (f32 *)&lbl_1_bss_6F1E4[offset + 16];
        output = clamp(*entry - lbl_1_rodata_4470);
        *entry = output;
    }
    v = __OSf32tos8(output);
    *whole = v;
    output = (output - __OSs8tof32(whole)) / lbl_1_rodata_45CC;
    v = __OSf32tos8(output);
    *fraction = v;

    v = *whole;
    *whole = (v < -3) ? -3 : ((v > 32) ? 32 : v);
    v = *fraction;
    *fraction = (v < -64) ? -64 : ((v > 63) ? 63 : v);
}
