/* Non-matching: best partial attempt (0.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80023D00_Arg0 { s32 samples[160]; };
struct fn_80023D00_Arg1 {
    u8 pad0[0x168];
    f32 unk168;
    f32 unk16C[3];
    u8 pad178[0x18];
    f32 unk190[3];
    f32 unk19C;
    f32 unk1A0;
    u32 unk1A4;
    u8 pad1A8[4];
};
struct fn_80023D00_Channel {
    u32 read0;
    u32 read1;
    u32 len0;
    u32 *data0;
    f32 value0;
    u32 read2;
    u32 read3;
    u32 len1;
    u32 *data1;
    f32 value1;
    u32 read4;
    u32 read5;
    u32 len2;
    u32 *data2;
    f32 value2;
};
struct fn_80023D00_State {
    struct fn_80023D00_Channel ch[3];
};
extern const f32 lbl_801A6FB4;
extern const f32 lbl_801A6FB8;
extern const f64 lbl_801A6FA8;

#pragma peephole off
void fn_80023D00(struct fn_80023D00_Arg0 *in, struct fn_80023D00_Arg1 *obj, s32 lane) {
    struct fn_80023D00_Channel *c;
    struct fn_80023D00_Channel *saved;
    f32 a, b, d, x, y, z, q, k, n, t;
    f32 input, old;
    s32 i;
    u32 j, idx;
    c = (struct fn_80023D00_Channel *)((u8 *)obj + lane * 0x3c);
    saved = (struct fn_80023D00_Channel *)((u8 *)obj + 0xb4 + lane * 0x3c);
    a = obj->unk168;
    b = obj->unk1A0;
    d = (f32)(obj->unk19C * lbl_801A6FB8);
    x = lbl_801A6FB8 - d;
    q = obj->unk16C[lane * 3];
    y = obj->unk16C[lane * 3 + 1];
    z = obj->unk16C[lane * 3 + 2];
    k = obj->unk190[lane];
    for (i = 0; i < 160; i++) {
        input = (f32)in->samples[i];
        input = input;
        if (obj->unk1A4 != 0) old = input; else old = input;
        t = q * c[0].value0 + old;
        c[0].data0[c[0].read0] = t;
        c[0].read0 += 4;
        n = c[0].data0[c[0].read1];
        c[0].read1 += 4;
        t = y * c[1].value1 + old;
        c[1].data1[c[1].read2] = t;
        c[1].read2 += 4;
        z = c[2].data2[c[2].read4];
        c[2].read4 += 4;
        d = d;
        a = a;
        b = b;
        c[0].value0 = n;
        c[1].value1 = z;
    }
    saved[0].read0 = c[0].read0;
    saved[0].read1 = c[0].read1;
    saved[1].read2 = c[1].read2;
    saved[2].read4 = c[2].read4;
    obj->unk190[lane] = k;
}
#pragma peephole reset
