/* Non-matching: best partial attempt (90.30% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_30D8C_Node {
    u8 pad_0[0x18];
    u8 code_18;
    u8 pad_19[7];
    u8 flag_20;
    u8 pad_21[4];
    u8 value_25;
    u8 pad_26[0x1A];
};

struct fn_12_30D8C_Entry {
    struct fn_12_30D8C_Node first;
    struct fn_12_30D8C_Node second;
};

struct fn_12_30D8C_Table {
    u8 pad_0[0x180];
    struct fn_12_30D8C_Entry table[13];
};

struct fn_12_30D8C_Arg0 {
    s32 unk_0;
    struct fn_12_30D8C_Table *unk_4;
    s32 unk_8;
    s32 unk_C;
};

static inline struct fn_12_30D8C_Table * fn_12_30D8C_read_pointer(struct fn_12_30D8C_Arg0 * owner) { return owner->unk_4; }
#pragma opt_lifetimes off
#pragma peephole off
s8 fn_12_30D8C(struct fn_12_30D8C_Arg0 *arg0, u32 arg1, s32 *arg2) {
    struct fn_12_30D8C_Node *node;
    s32 i;
    struct fn_12_30D8C_Table *p = fn_12_30D8C_read_pointer(arg0);
    u32 c;
    s32 t1;
    s32 t;
    u32 cls;
    s32 ok;

    if (arg0->unk_0 < 2) {
        if (!(arg0->unk_0 >= -1)) {
            t1 = 0;
        } else {
            t1 = 0;
        }
    } else {
        t1 = 1;
    }
    t = t1 ? (((arg0->unk_C == 107) || (arg0->unk_C >= 110)) ? 1 : 0) : 0;
    if (!(t)) {
        node = 0;
    } else {
        node = 0;
        c = arg1 & 0xFF;
        for (i = 0; i < 13; i++) {
            struct fn_12_30D8C_Node *n = &p->table[i].first;
            if (n->code_18 == c) {
                node = n;
                break;
            }
            n = &p->table[i].second;
            if (n->code_18 == c) {
                node = n;
                break;
            }
        }
    }
    if (node == 0) {
        return 0;
    }
    if ((arg1 & 0xFF) >= 0xC0 && (arg1 & 0xFF) <= 0xDF) {
        cls = 0xC0;
    } else if ((arg1 & 0xFF) >= 0xE0 && (arg1 & 0xFF) <= 0xEF) {
        cls = 0xE0;
    } else if ((arg1 & 0xFF) == 0xBD || (arg1 & 0xFF) == 0xBF) {
        cls = 0xBD;
    } else {
        cls = 0;
    }
    if (cls != 0xE0) {
        ok = 0;
    } else if (node->flag_20 > 1) {
        ok = 0;
    } else if (node->flag_20 == 0) {
        ok = 0;
    } else {
        ok = 1;
    }
    if (ok == 0) {
        return 0;
    }
    *arg2 = node->value_25;
    if (*arg2 > 63) {
        *arg2 = -1;
    }
    return 1;
}
#pragma peephole reset

#pragma opt_lifetimes reset
