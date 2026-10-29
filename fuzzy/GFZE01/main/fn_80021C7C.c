/* Non-matching: best partial attempt (97.38% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_801A6B10;
extern u32 lbl_801A6B2C;
extern u8 lbl_80160500[];
extern u16 lbl_801A6B14[];
extern u32 lbl_801A6B20;

extern void DCFlushRange(void *, u32);
extern void fn_80021BB0(void);
extern void fn_80021AB8(void);
extern s32 fn_8001DF00(u32);
extern u32 fn_8002123C(u32, u32);
extern void AIInitDMA(u32, u32);
extern void AIStartDMA(void);

#define Z80(q, v) \
    q[0] = v; q[1] = v; q[2] = v; q[3] = v; q[4] = v; q[5] = v; q[6] = v; q[7] = v; \
    q[8] = v; q[9] = v; q[10] = v; q[11] = v; q[12] = v; q[13] = v; q[14] = v; q[15] = v; \
    q[16] = v; q[17] = v; q[18] = v; q[19] = v; q[20] = v; q[21] = v; q[22] = v; q[23] = v; \
    q[24] = v; q[25] = v; q[26] = v; q[27] = v; q[28] = v; q[29] = v; q[30] = v; q[31] = v; \
    q[32] = v; q[33] = v; q[34] = v; q[35] = v; q[36] = v; q[37] = v; q[38] = v; q[39] = v; \
    q[40] = v; q[41] = v; q[42] = v; q[43] = v; q[44] = v; q[45] = v; q[46] = v; q[47] = v; \
    q[48] = v; q[49] = v; q[50] = v; q[51] = v; q[52] = v; q[53] = v; q[54] = v; q[55] = v; \
    q[56] = v; q[57] = v; q[58] = v; q[59] = v; q[60] = v; q[61] = v; q[62] = v; q[63] = v; \
    q[64] = v; q[65] = v; q[66] = v; q[67] = v; q[68] = v; q[69] = v; q[70] = v; q[71] = v; \
    q[72] = v; q[73] = v; q[74] = v; q[75] = v; q[76] = v; q[77] = v; q[78] = v; q[79] = v;

#pragma opt_common_subs off
#pragma opt_propagation on
void fn_80021C7C(s16 fill) {
    u32 * q;
    struct { u8 *value; } p;
    u32 i;

    p.value = lbl_80160500;
    lbl_801A6B10 = fill;
    lbl_801A6B2C = fill;
    for (i = 0; i < 4; i++) {
        q = (u32 *)(p.value + 0) + i * 0x50;
        Z80(q, fill)
    }
    DCFlushRange(p.value, 0x500);
    for (i = 0; i < 2; i++) {
        q = (u32 *)(p.value + 0x500) + i * 0x50;
        Z80(q, 2)
    }
    DCFlushRange(p.value + 0x500, 0x280);
    fn_80021BB0();
    fn_8001DF00((u32)fn_80021AB8);
    fn_8002123C((u32)(p.value + 0x500), (u32)(p.value + 0x280));
    lbl_801A6B14[0] = 1;
    lbl_801A6B20 = 0;
    AIInitDMA((u32)(p.value + lbl_801A6B10 * 0x280), 0x280);
    AIStartDMA();
}
#pragma opt_propagation reset

#pragma opt_common_subs reset

