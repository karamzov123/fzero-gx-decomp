/* Non-matching: best partial attempt (97.40% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/interview/interview.h"


typedef struct {
    u8 pad_0[6];
    u8 slot_flags;
} InterviewSlot;

typedef struct {
    u8 pad_0[0x88];
    u32 unk_88;
} InterviewEntry;

typedef struct {
    u8 pad_00[0x10];
    InterviewSlot *slots;
    u8 pad_14[0x20];
    s32 results[1];
    u8 pad_38[0xA0];
    InterviewEntry *objects[1];
    u8 pad_DC[0x74];
    void *unk_150;
} InterviewState;

typedef struct {
    u8 pad_0000[0x2C34];
    s16 select_table[0x234];
    u8 default_name[9];
    u8 pad_30A5[0x1B];
    void *slot_name_table[0x364];
    u8 pad_3E50[0x210];
    u8 motion_name[0x10];
    u8 voice_name[0x10];
} InterviewData;

extern void *lbl_801A6410;
extern void *fn_1_4630(void *, u32, u8 *, u32);
extern void fn_1_8F198(void *, s16, u32, u32);
extern u32 fn_1_934CC(void *, void *, void *);
extern void fn_1_12A2B8(u32);
extern s16 fn_1_97F1C(void *, u32);
extern void fn_1_8E728(void *, u8);
extern void *fn_1_435C(void *);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern void fn_1_92530(void);

static inline u32 fzgx_slot_index(u32 mask) {
    return (31 - __cntlzw(mask)) & 3;
}

#pragma opt_lifetimes off
#pragma opt_dead_assignments off
#pragma peephole off
static inline InterviewEntry * *fn_17_3A28_array_read(InterviewEntry * *array) { return array; }
#pragma peephole reset

#pragma opt_strength_reduction off
static inline u32 fn_17_3A28_call_fn_1_934CC(void * a2, void * a1, void * a0) { return fn_1_934CC(a0, a1, a2); }
void fn_17_3A28(u32 arg_a, u32 arg_b, u32 arg_c) {
    InterviewEntry * * fzgx_live_;
    s16 slot_index;
    InterviewState * state;
    InterviewSlot *slot;
    InterviewEntry **objects;
    s32 *results;
    void **names;
    s16 *selections;
    InterviewData * data;
    void *object;
    s16 select;
    u32 bit;
    u32 mode;
    slot_index = (s16)arg_c;
    data = (InterviewData *)((u8 *)&lbl_17_data_0 + 0x60000);
    state = (InterviewState *)&lbl_17_bss_0;

    slot = (InterviewSlot *)((u8 *)state->slots + slot_index * 8);

    switch (fzgx_slot_index(slot->slot_flags)) {
    case 0: bit = 0x80000000; break;
    case 1: bit = 0x40000000; break;
    case 2: bit = 0x20000000; break;
    case 3: bit = 0x10000000; break;
    default: bit = 0x80000000; break;
    }

    object = fn_1_4630(lbl_801A6410, 0x4E0, (u8 *)data + 0x3E50, 0x927);
    objects = (InterviewEntry **)((u8 *)state + 0xd8);
    objects[(s16)arg_b] = (InterviewEntry *)object;
    object = fn_17_3A28_array_read(objects)[(s16)arg_b];
    fn_1_8F198(object, (s16)arg_a, 0x80000000, bit);

    if ((s16)arg_c == 0) {
        names = (void **)((u8 *)data + 0x30c0);
        fn_1_934CC(object, (u8 *)object + 0x148, names[slot_index]);
    } else {
        selections = (s16 *)((u8 *)data + 0x2c34);
        fzgx_live_ = state->objects;
        select = selections[fn_17_3A28_array_read(fzgx_live_)[0]->unk_88];
        switch (select) {
        case 3:
        case 4:
            fn_17_3A28_call_fn_1_934CC(data->motion_name, (u8 *)object + 0x148, object);
            break;
        default:
            fn_1_934CC(object, (u8 *)object + 0x148, (data->default_name));
            break;
        }
    }

    fn_1_12A2B8(1);
    (results = (s32 *)((u8 *)state + 0x34))[(s16)arg_b] = (s16)fn_1_97F1C(fn_17_3A28_array_read(objects)[(s16)arg_b], arg_a);
    fn_1_12A2B8(0);

    slot = (InterviewSlot *)((u8 *)state->slots + slot_index * 8);

    switch (fzgx_slot_index(slot->slot_flags)) {
    case 0: mode = 0; break;
    case 1: mode = 1; break;
    case 2: mode = 2; break;
    case 3: mode = 3; break;
    default: mode = 0; break;
    }

    if (*(u8 *)((u8 *)object + 0x98) != mode) {
        fn_1_8E728(object, mode);
        *(u8 *)((u8 *)object + 0x98) = mode;
    }

    fn_1_435C(state->unk_150);
    fn_1_3F8C((u32)(data->voice_name), (u32)fn_1_92530, (u32)object, 0xA);
    return;
}
#pragma opt_strength_reduction reset

#pragma opt_dead_assignments reset

#pragma opt_lifetimes reset

