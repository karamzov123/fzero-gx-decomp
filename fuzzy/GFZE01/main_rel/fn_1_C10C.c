/* Non-matching: best partial attempt (95.19% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
} CameraSlot;

typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 pad_6[0x2];
    CameraSlot state;
    u8 pad_2C[0x9C];
    CameraSlot slots[4];
} CameraObj;

extern f32 lbl_1_bss_1010;

#pragma opt_propagation off
#pragma peephole off
void fn_1_C10C(u8 index) {
    u32 v0;
    u32 v1;
    struct { u32 value; } v2;
    u32 v4;
    u32 v3;
    u32 v6;
    u32 v5;
    u32 v7;
    u32 v8;
    CameraObj *p;
    CameraSlot *slots;
    CameraSlot *src;

    p = (CameraObj *)&lbl_1_bss_1010;
    slots = (CameraSlot *)((u8 *)p + 0xC8);
    src = slots + index;
    p->unk_5 = 0;

    v0 = src->unk_0;
    v1 = src->unk_4;
    v2.value = src->unk_8;
    v3 = src->unk_C;
    v4 = src->unk_10;
    v5 = src->unk_14;
    v6 = src->unk_18;
    v7 = src->unk_1C;
    v8 = src->unk_20;

    p->state.unk_0 = v0;
    p->state.unk_4 = v1;
    p->state.unk_8 = v2.value;
    p->state.unk_C = v3;
    p->state.unk_10 = v4;
    p->state.unk_14 = v5;
    p->state.unk_18 = v6;
    p->state.unk_1C = v7;
    p->state.unk_20 = v8;
}
#pragma peephole reset

#pragma opt_propagation reset
