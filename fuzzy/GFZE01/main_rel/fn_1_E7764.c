/* Non-matching: best partial attempt (80.60% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/bg_for.h"

extern void fn_1_E1C10(void);
extern void fn_1_E1A00(void *, u8 *);
extern void fn_1_E252C(s32, s32, void *);
extern void fn_80008BA8(void *, void *, u32);

typedef struct {
    u8 pad0[8];
    s16 angle;
    s16 mode;
    u8 padE[0x54 - 0xE];
    f32 value54;
    f32 value58;
    f32 value5C;
    u8 pad60[0x24];
    f32 value84;
    u8 pad88[0x6C];
    f32 valueF4;
    u8 padF8[0x40];
    u64 flags;
} E7764Object;

static s16 get_count(Obj_1_bss_7AE88 *p, s16 group) {
    switch (group) {
    case 0: return p->unk_4;
    case 1: return p->unk_C;
    case 2: return p->unk_14;
    case 3: return p->unk_1C;
    case 4: return p->unk_24;
    case 5: return p->unk_2C;
    default: return -1;
    }
}

static void *get_base(Obj_1_bss_7AE88 *p, s16 group) {
    switch (group) {
    case 0: return (void *)p->unk_0;
    case 1: return (void *)p->unk_8;
    case 2: return (void *)p->unk_10;
    case 3: return (void *)p->unk_18;
    case 4: return (void *)p->unk_20;
    case 5: return (void *)p->unk_28;
    default: return 0;
    }
}

void fn_1_E7764(void) {
    Obj_1_bss_7AE88 *table = &lbl_1_bss_7AE88;
    s16 type = 2;
    s16 count;
    s16 group;
    s16 i;
    s16 modeCount;
    void *base;
    E7764Object *obj;
    u8 *data = lbl_1_data_3DDA8;

    if (lbl_1_bss_9F8.unk_2 & 0x80) type = 0;
    if (lbl_1_bss_9F8.unk_2 & 0x20) type = 1;
    if (lbl_1_bss_9F8.unk_2 & 0x10) type = 2;
    if (lbl_1_bss_9F8.unk_2 & 0x40) type = 4;
    if (lbl_1_bss_9F8.unk_0 & 0x0800) {
        type = 3;
        if (lbl_1_bss_9F8.unk_2 & 0x80) type = 5;
        if (lbl_1_bss_9F8.unk_2 & 0x10) type = 3;
    }

    *(s16 *)((u8 *)table + 0x2F2) = 5;
    if ((*(u16 *)((u8 *)&lbl_1_bss_9F8 + 0x16)) & 0x80) *(s16 *)((u8 *)table + 0x2F2) = 100;
    if ((*(u16 *)((u8 *)&lbl_1_bss_9F8 + 0x16)) & 0x40) *(s16 *)((u8 *)table + 0x2F2) = 1;
    if ((*(u16 *)((u8 *)&lbl_1_bss_9F8 + 0x16)) & 0x10 || (*(u16 *)((u8 *)&lbl_1_bss_9F8 + 0x16)) & 0x20) *(s16 *)((u8 *)table + 0x2F2) = 25;

    *(s16 *)((u8 *)table + 0x2F0) = 0;
    count = *(s16 *)((u8 *)table + 0x2F2);
    switch (type) {
    case 0: table->unk_4 = count; break;
    case 1: table->unk_C = count; break;
    case 2: table->unk_14 = count; break;
    case 3: table->unk_1C = count; break;
    case 4: table->unk_24 = count; break;
    case 5: table->unk_2C = count; break;
    }
    fn_1_E1C10();

    for (group = 0; group < 6; group++) {
        modeCount = get_count(table, group);
        base = get_base(table, group);
        for (i = 0; i < modeCount; i++) {
            fn_1_E1A00((u8 *)base + i * 0x1A8, data);
        }
    }

    for (group = 0; group < 6; group++) {
        modeCount = get_count(table, group);
        base = get_base(table, group);
        for (i = 0; i < modeCount; i++) {
            fn_1_E252C(group, i, (u8 *)base + i * 0x1A8);
        }
    }

    for (group = 0; group < 6; group++) {
        modeCount = get_count(table, group);
        base = get_base(table, group);
        for (i = 0; i < modeCount; i++) {
            s16 angle;
            s32 rem10;
            s32 rem25;
            f32 value;
            f32 scale;
            obj = (E7764Object *)((u8 *)base + i * 0x1A8);
            obj->flags |= 8;
            obj->flags &= ~0x40ULL;
            if (obj->mode == 1) obj->flags |= 0x40;
            obj->flags &= ~1ULL;
            obj->flags &= ~0x200ULL;

            angle = obj->angle;
            value = obj->value84 * obj->valueF4;
            scale = 3.0f * value;
            rem10 = angle - (angle / 10) * 5;
            obj->value54 = scale * (f32)rem10 - (scale * 0.5f) * 5.0f;
            obj->value58 = scale * (f32)(angle / 25);
            rem25 = angle - (angle / 25) * 25;
            obj->value5C = scale * (f32)(rem25 / 10) - (scale * 0.5f) * 5.0f;
            fn_80008BA8((u8 *)obj + 0x60, (u8 *)obj + 0x54, 0xC);
        }
    }
}
