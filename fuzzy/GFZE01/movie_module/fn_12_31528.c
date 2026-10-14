/* Non-matching: best partial attempt (94.01% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_31528_Node {
    u8 pad_0[0x18];
    u8 key;
    u8 pad_19[0x7];
    u8 unk_20;
    u8 unk_21;
    u8 pad_22[0x1E];
};

struct fn_12_31528_Arg0 {
    s32 unk_0;
    struct fn_12_31528_Node *unk_4;
    u32 unk_8;
    s32 unk_C;
};

s32 fn_12_31528(struct fn_12_31528_Arg0 *arg0, u32 arg1, s32 *arg2) {
    s32 ok;
    s32 sub;
    u32 kind;
    struct fn_12_31528_Node *a;
    struct fn_12_31528_Node *found;
    struct fn_12_31528_Node *p;
    s32 i;

    p = arg0->unk_4;
    ok = arg0->unk_0;
    if (ok >= 2 || ok < -1) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (ok == 0) {
        ok = 0;
    } else {
        sub = (arg0->unk_C == 107) || (arg0->unk_C >= 110);
        if (sub == 0) {
            ok = 0;
        } else {
            ok = 1;
        }
    }
    if (ok == 0) {
        found = 0;
    } else {
        found = 0;
        for (i = 0; i < 13; i++) {
            a = &p[6];
            if (a->key == (arg1 & 0xFF)) {
                found = a;
                break;
            }
            a = &p[7];
            if (a->key == (arg1 & 0xFF)) {
                found = a;
                break;
            }
            p += 2;
        }
    }
    if (found == 0) {
        return 0;
    }
    if ((arg1 & 0xFF) >= 0xC0 && (arg1 & 0xFF) <= 0xDF) {
        kind = 0xC0;
    } else if ((arg1 & 0xFF) >= 0xE0 && (arg1 & 0xFF) <= 0xEF) {
        kind = 0xE0;
    } else if ((arg1 & 0xFF) == 0xBD || (arg1 & 0xFF) == 0xBF) {
        kind = 0xBD;
    } else {
        kind = 0;
    }
    if (kind != 0xE0) {
        ok = 0;
    } else if (found->unk_20 > 1) {
        ok = 0;
    } else if (found->unk_20 == 0) {
        ok = 0;
    } else {
        ok = 1;
    }
    if (ok == 0) {
        return 0;
    } else {
        *arg2 = found->unk_21;
        return 1;
    }
}
