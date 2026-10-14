/* Non-matching: best partial attempt (90.34% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/load.h"

extern void fn_1_D3214(void);
extern void DCInvalidateRange(void *, u32);
extern void fn_1_45890(void);

typedef void (*Sig_ARQPostRequest_ARQCallback)(u32 pointerToARQRequest);
typedef struct Sig_ARQPostRequest_ARQRequest {
    struct Sig_ARQPostRequest_ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    Sig_ARQPostRequest_ARQCallback callback;
} Sig_ARQPostRequest_ARQRequest;
extern void ARQPostRequest(Sig_ARQPostRequest_ARQRequest *, u32, u32, u32, u32, void *, u32, Sig_ARQPostRequest_ARQCallback);

typedef struct Sig_fn_8006A3DC_Fn8006A3DCHeader {
    u32 magic;
    u32 data_offset;
    u32 unk_8;
    u32 table_offset;
} Sig_fn_8006A3DC_Fn8006A3DCHeader;

typedef struct Sig_fn_8006A3DC_Fn8006A3DCResult {
    void *header;
    void *data;
    void *table;
    u32 count;
    void *end;
    u32 unk_14;
    u32 unk_18;
} Sig_fn_8006A3DC_Fn8006A3DCResult;
extern s32 fn_8006A3DC(Sig_fn_8006A3DC_Fn8006A3DCHeader *, Sig_fn_8006A3DC_Fn8006A3DCResult *);
extern void OSReport(const char *, ...);
extern u32 fn_8000700C(void *);

typedef struct Fn464BCEntry {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Fn464BCEntry;
typedef struct Fn464BCObject {
    u8 unk_00[4];
    Fn464BCEntry *unk_04;
    u8 unk_08[8];
    u8 *unk_10;
} Fn464BCObject;
extern void fn_1_464BC(Fn464BCObject *, u32, void *, u32);

typedef struct Fn46144Slot {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
} Fn46144Slot;

typedef struct Fn46144State {
    u8 pad_00[0x10];
    s32 unk_10;
    s32 unk_14;
    Fn46144Slot unk_18[0x400];
    u8 pad_4018[0x1808];
    s32 unk_5820;
    s32 unk_5824[0x10];
    u8 pad_5864[8];
    u32 unk_586c;
} Fn46144State;

struct fn_1_46144_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};

static inline int fn_1_46144_busy(Fn46144State *state) {
    s32 * fzgx_live;
    s32 *tbl;
    s8 i;
    if (state->unk_10 != 0) {
        return 1;
    }
    fzgx_live = state->unk_5824;
    tbl = fzgx_live;
    for (i = 0; i < 0x10; i++) {
        if (tbl[i] != 0) {
            return 1;
        }
    }
    return 0;
}

#pragma peephole on
u32 fn_1_46144(struct fn_1_46144_Arg0 *arg0, s16 arg1, s32 arg2) {
    Fn46144State *state = (Fn46144State *)&lbl_1_bss_384C0;
    Sig_ARQPostRequest_ARQRequest req;
    Sig_fn_8006A3DC_Fn8006A3DCResult result;
    struct { char unk_00[0x40]; } name;
    Fn46144Slot *slots;
    u8 *off;
    void *cache;
    u32 aligned;
    u32 base;
    s32 count;
    s32 i;
    s32 scan;
    Fn46144Slot *entry;
    s32 idx;

    base = arg0->unk_8;
    while (fn_1_46144_busy(state)) {
        fn_1_D3214();
    }

    state->unk_10 = 1;
    DCInvalidateRange((void *)(*(u32 volatile *)&(state->unk_586c)) /* Retail reloads this field. */, 0x20);
    ARQPostRequest(&req, 0, 1, 1, base, (void *)(*(u32 volatile *)&(state->unk_586c)) /* Retail reloads this field. */, 0x20, (Sig_ARQPostRequest_ARQCallback)fn_1_45890);

    while (fn_1_46144_busy(state)) {
        fn_1_D3214();
    }

    cache = (void *)(*(u32 volatile *)&(state->unk_586c)) /* Retail reloads this field. */;
    off = (u8 *)(*(u32 *)((u8 *)cache + 4));
    aligned = (*(u32 *)((u8 *)cache + 8) + 0x1f) & 0xFFFFFFE0;
    state->unk_10 = 1;
    arg0->unk_C = aligned + (u32)off;
    DCInvalidateRange((u8 *)(*(u32 volatile *)&(state->unk_586c)) /* Retail reloads this field. */ + (u32)off, aligned);
    ARQPostRequest(&req, 0, 1, 1, base + (u32)off, (void *)((u8 *)(*(u32 volatile *)&(state->unk_586c)) /* Retail reloads this field. */ + (u32)off), aligned, (Sig_ARQPostRequest_ARQCallback)fn_1_45890);

    while (fn_1_46144_busy(state)) {
        fn_1_D3214();
    }

    if (fn_8006A3DC((Sig_fn_8006A3DC_Fn8006A3DCHeader *)cache, &result) == 0) {
        OSReport((const char *)lbl_1_data_67D0);
        return 0;
    }

    off = (u8 *)((*(u32 volatile *)&(state->unk_586c)) /* Retail reloads this field. */ + (u32)off);
    count = *(s32 *)(off + 8);
    for (i = 0; i < count; i++, off += 0xC) {
        if (*(u8 *)off != 0) {
            continue;
        }
        entry = &state->unk_18[state->unk_5820];
        entry->unk_00 = 0x40000000 | (arg1 < 0 ? 0x10000000 : 0);
        entry->unk_08 = base + *(u32 *)(off + 4);
        entry->unk_0C = (*(u32 *)(off + 8) + 0x1f) & 0xFFFFFFE0;
        if (arg2 != 0) {
            fn_1_464BC((Fn464BCObject *)&result, i, &name, 0x40);
            entry->unk_04 = fn_8000700C(&name);
        } else {
            entry->unk_00 |= 0x08000000;
            entry->unk_04 = i;
        }
        slots = state->unk_18;
        idx = state->unk_5820;
        for (scan = 0; scan < 0x400; scan++) {
            idx++;
            if (slots[idx].unk_00 == 0) {
                goto found;
            }
            if (idx >= 0x400) {
                idx = 0;
            }
        }
    found:
        /* one scan of the table finds the next free slot */
        state->unk_5820 = idx;
    }
    return 1;
}
#pragma peephole reset
