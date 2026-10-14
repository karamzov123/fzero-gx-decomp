/* Non-matching: best partial attempt (98.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_32DBC_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x4];
    u32 unk_C;
};
struct fn_12_32DBC_Arg2 {
    u32 unk_0;
};

static inline s32 type_ok(s32 type) {
    s32 ok = 0;
    if (type == 107 || type >= 110) ok = 1;
    return ok;
}
static inline s32 ready(struct fn_12_32DBC_Arg0 *arg0) {
    s32 flag = 0;
    switch ((s32)arg0->unk_0) {
    case -1: case 0: case 1: flag = 0; break;
    default: flag = 1; break;
    }
    if (!flag) return 0;
    if (!type_ok(arg0->unk_C)) return 0;
    return 1;
}

static inline u8 *find(u32 v1, u32 arg1) {
    s32 v5;
    u8 * entry_2;
    u8 *v7 = 0;
    u8 *entry;
    for (v5 = 0; v5 < 13; v5++) {
        entry = (u8 *)v1;
        entry_2 = entry_2 + v5 * 1 + 384;
{
    u32 v3 = arg1 & 0xFF;
        if (entry_2[24] == v3) { v7 = entry_2; break; }
        entry_2 = ((v5 * 128) + ((u8 *)v1)) + 448;
        if (entry_2[24] == v3) { v7 = entry_2; break; }
}
    }
    return v7;
}
s32 fn_12_32DBC(struct fn_12_32DBC_Arg0 *arg0, u32 arg1, struct fn_12_32DBC_Arg2 *arg2) {
    u32 v0;
    u32 v1;
    s32 v2;
    u32 v3;
    u32 v4;
    s32 v5;
    u32 v6;
    u8 *v7;
    u8 *entry;
    v2 = 0;
    arg2->unk_0 = v2;
    v1 = arg0->unk_4;
    if (!ready(arg0)) return 0;
    v7 = find(v1, arg1);
    (void) v7;  /* fzgx: keeps the web at its definition */
    if (v7 != 0) arg2->unk_0 = 1;
    else arg2->unk_0 = 0;
    return 1;
}
