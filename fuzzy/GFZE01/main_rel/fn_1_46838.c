/* Non-matching: best partial attempt (96.02% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/dvd.h"

extern u32 lbl_1_bss_384C0[];

typedef struct {
    u32 flag;
    s32 id;
    u32 value;
    u32 unk_0C;
} fn_1_46838_entry;

typedef struct {
    u8 lab_pad[4];
    u32 busy;
    DVDCommandBlock block;
} fn_1_46838_queue;

typedef struct {
    u32 unk_00[6];
    fn_1_46838_entry entries[0x400];
    s32 states[0x200][3];
    u32 mirror;
    u32 unk_581C[0x16];
    fn_1_46838_queue queue;
} fn_1_46838_ctx;

static inline fn_1_46838_entry * fn_1_46838_read_pointer(fn_1_46838_ctx * owner) { return owner->entries; }
#pragma opt_propagation off
s32 fn_1_46838(u32 arg0) {
    u32 *fzgx_value;
    fn_1_46838_ctx *ctx = (fn_1_46838_ctx *)lbl_1_bss_384C0;
    s32 *state = (s32 *)((u8 *)ctx + 0x4018);
    u32 i;
    fn_1_46838_entry *entry;
    s32 v;
    DVDCommandBlock *cmd;

    state += arg0 * 3;
    v = state[0];
    switch (v) {
    case 1:
    case 2:
    case 0xB:
    case 0xD:
        state[0] = 0xE;
        state[1] = -1;
        break;
    case 7:
    case 8:
    case 9:
    case 0xA:
        cmd = (DVDCommandBlock *)((u8 *)ctx + 0x5874);
        entry = fn_1_46838_read_pointer(ctx);
        if (*(u32 *)((u8 *)cmd + 4) == 0) {
            DVDCancelAsync((DVDCommandBlock *)((u8 *)cmd + 8), NULL);
        }
        for (i = 0; i < 0x400; i++, entry++) {
            if (entry->flag != 0 && entry->id == state[1]) {
                fzgx_value = &(entry->flag);
                *fzgx_value = 0;
                ctx->mirror = entry->value;
            }
        }
        break;
    default:
        return 0;
    }
    return 1;
}
#pragma opt_propagation reset
