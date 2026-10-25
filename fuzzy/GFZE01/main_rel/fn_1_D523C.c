/* Non-matching: best partial attempt (98.57% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/mdlload.h"

typedef struct {
    u32 unk_0;
    u8 *unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
} Fn1D523CArg;

extern s32 lbl_1_bss_7AD60[6];
extern f32 lbl_1_rodata_6168[112];

extern u32 lbl_801A66A0;
extern u32 fn_1_5910(void);
extern void fn_80072EDC(s32, s32);
extern void fn_800734A8(s32, s32, s32, s32);
extern void fn_800745A4(s32, s32, s32, s32, s32, s32);
extern void fn_80073778(void *, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void GXLoadTexMtxImm(const f32 (*)[4], u32, u32);
extern void fn_800738E0(s32, s32, s32);
extern void fn_80073E8C(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void fn_800739E0(s32, s32, s32);

void fn_1_D523C(Fn1D523CArg *arg0) {
    u8 *entry;
    s32 *state = lbl_1_bss_7AD60;
    struct { f32 *value; } c;
    s32 p10 = arg0->unk_10;
    s32 r10;
    f32 *scales;
    u8 *base;
    s32 q10;
    s32 p18 = arg0->unk_18;
    s32 q18;
    s32 r18;
    s32 q14;
    s32 r14;
    s32 pC = arg0->unk_C;
    u32 index;
    s32 qC;
    s32 p1C = arg0->unk_1C;
    f32 mtx[3][4];
    f32 limit;
    f32 t;
    s8 lab_t4;
    c.value = lbl_1_rodata_6168;

    q10 = p10 + 1;
    r10 = p10 + 2;
    q18 = p18 + 1;
    r18 = p18 + 2;
{
    s32 p14 = arg0->unk_14;
    q14 = p14 + 3;
    r14 = p14 + 6;
}
    qC = pC + 1;
{
    s32 q1C;
    q1C = p1C + 1;
    index = fn_1_5910();
    scales = (f32 *) lbl_1_data_2A7E0.unk_3C;
    base = (u8 *) scales + 0xC140;
    entry = base + index * 2;

    if (*(s16 *) (entry + 0x2630) == -1) {
        return;
    }
    if (arg0->unk_4[0x15] == 2) {
        return;
    }
    if (arg0->unk_4[0x15] != 1) {
        if (state[0] == arg0->unk_10 && state[1] == arg0->unk_18 && state[2] == arg0->unk_14 &&
            state[3] == arg0->unk_C && state[4] == arg0->unk_1C) {
            return;
        }
    }
    state[0] = arg0->unk_10;
    state[1] = arg0->unk_18;
    state[2] = arg0->unk_14;
    state[3] = arg0->unk_C;
    state[4] = arg0->unk_1C;

    fn_80072EDC(pC, 1);
    fn_800734A8(pC, q10, q18, 4);
    fn_800745A4(q10, 1, 4, q14, 0, 0x7D);
    fn_80073778(base, q18);
    fn_80072AB0(pC, 0, 0);

    mtx[0][0] = *(s16 *) (base + 0x2638);
    mtx[0][1] = 0.0f;
    mtx[0][2] = 0.0f;
    mtx[0][3] = *(f32 *) (base + 0x2620);
    mtx[1][0] = 0.0f;
    t = scales[index] < 23.0f ? scales[index] : 23.0f;
    mtx[1][1] = (f32)*(s16 *) (base + 0x263A) * (1.0f - t / 24.0f);
    mtx[1][2] = 0.0f;
    mtx[1][3] = *(f32 *) (base + 0x2624);
    GXLoadTexMtxImm(mtx, q14, 1);

    fn_800738E0(p1C, q10, p18);
    fn_80073778(base + *(s16 *) (entry + 0x2630) * 0x900 + ((lbl_801A66A0 >> 1) & 7) * 0x120 + 0x320, p18);
    lab_t4 = 0x10;
    fn_80073E8C(pC, p1C, 0x10, 0x10, lab_t4, 0x10, 2, 1, 0, 0);
    fn_800739E0(arg0->unk_1C, 4, 4);
    arg0->unk_1C = q1C;
}
    arg0->unk_C = qC;
    arg0->unk_10 = r10;
    arg0->unk_18 = r18;
    arg0->unk_14 = r14;
}
