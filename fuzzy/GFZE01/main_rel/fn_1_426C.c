/* Non-matching: best partial attempt (97.32% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Node {
    u32 field_0;
    u32 field_4;
    u8 pad_8[0x10];
    void (*callback)(u32, u32);
    u8 pad_1c[0x8];
} Node;

typedef struct Manager {
    u32 field_0;
    Node *nodes;
} Manager;

extern Manager *lbl_1_bss_DAC;
extern Manager *lbl_1_bss_DA8;

extern void fn_1_4374(Manager *, Node *);

#pragma opt_propagation off
void fn_1_426C(u32 arg0) {
    Manager *mgr = lbl_1_bss_DAC;
    Node *node = &mgr->nodes[arg0];
    void (*callback)(u32, u32);

    if (arg0 < 32) {
        return;
    }

    if (node->field_0 == 0) {
        return;
    }

    callback = node->callback;
    if (callback != NULL) {
        Manager *saved = lbl_1_bss_DA8;
        lbl_1_bss_DA8 = mgr;
        callback(node->field_4, 1);
        lbl_1_bss_DAC = mgr;
        lbl_1_bss_DA8 = saved;
    }
    fn_1_4374(mgr, node);
}
#pragma opt_propagation reset

