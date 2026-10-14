/* Non-matching: best partial attempt (96.37% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_1_data_2B80[60];
extern u32 lbl_1_bss_DAC;
extern void OSReport(const char *, ...);
extern void fn_1_4370(void);

struct fn_1_3CF0_Node {
    void (*func)(void);
    u32 unk_4;
    struct fn_1_3CF0_Node *next;
    struct fn_1_3CF0_Node *prev;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
};

struct fn_1_3CF0_Mgr {
    struct fn_1_3CF0_Node *unk_0;
    struct fn_1_3CF0_Node *unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    struct fn_1_3CF0_Node *ptrs[32];
    struct fn_1_3CF0_Node nodes[64];
};

static inline u32 fn_1_3CF0_array_read(s32 index, u32 *array) { return array[index]; }
#pragma opt_dead_assignments off
#pragma opt_loop_invariants off
static inline struct fn_1_3CF0_Node * * fn_1_3CF0_read_pointer(struct fn_1_3CF0_Mgr * owner) { return owner->ptrs; }
void fn_1_3CF0(struct fn_1_3CF0_Mgr *mgr, u32 count) {
    u32 i;
    struct fn_1_3CF0_Node *prev;
    struct fn_1_3CF0_Node *base;
    u32 *tbl = &lbl_1_data_2B80[0];
    struct fn_1_3CF0_Node *n;

    if (count == 0) {
        OSReport((const char *)&tbl[7]);
    }
    lbl_1_bss_DAC = (u32)mgr;
    base = mgr->nodes;
    mgr->unk_8 = 0;
    if (count == 0) {
        mgr->unk_0 = 0;
    } else {
        mgr->unk_0 = base + 32;
    }
    mgr->unk_4 = base;
    mgr->unk_10 = 0;
    mgr->unk_C = count;
    mgr->unk_14 = 0;
    n = base + 32;
    prev = 0;
    for (n = base + 32, i = 32; i < count + 32; i++, n++) {
        n->func = 0;
        n->unk_18 = 0;
        n->unk_4 = 0;
        n->unk_10 = i;
        n->prev = prev;
        n->next = n + 1;
        n->unk_14 = 0;
        n->unk_20 = (u32)(void *)&tbl[0x11];
        prev = n;
    }
    (*((count + 31) + (base))).next = 0;
    for (i = 0; i < 32; i++) {
        fn_1_3CF0_read_pointer(mgr)[i] = &base[i];
        (*((i) + (base))).func = fn_1_4370;
        (*((i) + (base))).unk_18 = 0;
        (*((i) + (base))).next = 0;
        (*((i) + (base))).prev = 0;
        (*((i) + (base))).unk_10 = i;
        (*((i) + (base))).unk_14 = 0;
        (*((i) + (base))).unk_20 = fn_1_3CF0_array_read(6, tbl);
    }
}
#pragma opt_loop_invariants reset

#pragma opt_dead_assignments reset

