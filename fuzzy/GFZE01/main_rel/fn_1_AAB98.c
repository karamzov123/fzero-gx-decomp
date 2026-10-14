/* Non-matching: best partial attempt (91.78% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/driver.h"

struct fn_1_AAB98_lbl_1_bss_716C0 {
    u8 pad_0[0x1F1];
    u8 unk_1F1;
    u8 unk_1F2;
    u8 pad_1F3[0x5A55];
    u8 unk_5C48;
};
struct fn_1_AAB98_slot {
    u8 pad_0[2]; u8 unk_2; u8 unk_3; u8 unk_4; u8 unk_5;
    u8 unk_6; u8 unk_7; u16 unk_8; u16 unk_A;
    u8 pad_C[0x18]; u32 unk_24; u8 unk_28;
    u8 pad_29[1]; u8 unk_2A; u8 pad_2B[5]; u32 unk_30;
    f32 unk_34; f32 unk_38; s32 unk_3C; s32 unk_40;
    u8 pad_44[0xA0 - 0x44];
};
extern const f32 lbl_1_rodata_4CA8;
extern void fn_1_A2DC4(u32);

void fn_1_AAB98(void) {
    struct fn_1_AAB98_lbl_1_bss_716C0 *p;
    struct fn_1_AAB98_slot *entry;
    struct fn_1_AAB98_slot *reset;
    struct fn_1_AAB98_slot *dst;
    u32 addr;
    u32 off;
    struct fn_1_AAB98_slot *slots;
    s32 v2;
    u8 v0;
    u32 v1;
    u8 v3;
    u32 v4;
    s32 ready;
    u8 idx;
    u8 state;
    u8 flags;
    u32 neg;
    p = (struct fn_1_AAB98_lbl_1_bss_716C0 *)&lbl_1_bss_716C0;
    v2 = 0;
    v0 = p->unk_1F1;
    if (v0 == 0) {
        v1 = (u32)((u8 *)p + 8);
        v1 = *(u32 *)((u8 *)v1 + 36);
        if (v1 != 0) {
            if (*(u8 *)v1 == 1) v2 = 1;
            else v2 = 0;
        }
    }
    if (v0 == 0 && v2 != 0) {
        p->unk_5C48 = 1;
        p->unk_1F2 = 0;
    } else if (p->unk_5C48 == 0) {
        if (((lbl_1_bss_9F8.unk_10 & 1) != 0 || (lbl_1_bss_9F8.unk_12 & 1) != 0) && p->unk_1F2 == 1) {
            fn_1_A2DC4(0xA9011300);
            p->unk_1F2 = 0;
        } else if (((lbl_1_bss_9F8.unk_10 >> 1) & 1) != 0 || ((lbl_1_bss_9F8.unk_12 >> 1) & 1) != 0) {
            if (p->unk_1F2 == 0) {
                fn_1_A2DC4(0xA9011300);
                p->unk_1F2 = 1;
            }
        }
        if (((lbl_1_bss_9F8.unk_8 >> 8) & 1) != 0) {
            fn_1_A2DC4(0xA9011100);
            v2 = 1;
        } else v2 = 0;
        p->unk_5C48 = v2;
    }
    v3 = p->unk_5C48;
    if ((s32)v3 == 1) goto case_one;
    if ((s32)v3 >= 1) goto mode2;
    return;
mode2: /* mode 2 sets up the slot type table before the shared tail */
    if ((s32)v3 >= 3) return;
    {
        addr = (u32)((u8 *)p + 336);
        entry = (struct fn_1_AAB98_slot *)addr;
        switch ((s32)entry->unk_2) {
        case 2: entry->unk_3 = 32; break;
        case 0: case 1: entry->unk_3 = 2; break;
        case 3: case 4: entry->unk_3 = 27; break;
        case 5: entry->unk_3 = 30; break;
        }
        p->unk_1F2 = 0;
        goto case_one;
    }
case_one: /* mode 1 and mode 2 share this transition */
    if (p->unk_5C48 == 1) {
        addr = (u32)((u8 *)p + 336);
        entry = (struct fn_1_AAB98_slot *)addr;
        v4 = entry->unk_2A;
        if ((v4 & 1) == 0) {
            ready = 0;
            entry->unk_28 = 12;
            entry->unk_2A = v4 | 1;
        } else {
            v4 = entry->unk_28;
            if ((s8)v4 > 0) {
                ready = 0;
                entry->unk_28 = v4 - 1;
            } else ready = 1;
        }
        if (ready == 0) return;
    }
    idx = p->unk_1F2;
    addr = (u32)((u8 *)p + 336);
    entry = (struct fn_1_AAB98_slot *)addr;
    state = p->unk_5C48;
    off = idx * 160;
    slots = (struct fn_1_AAB98_slot *)((u8 *)p + 8);
    dst = (struct fn_1_AAB98_slot *)((u8 *)slots + off);
    v4 = entry->unk_2;
    v1 = entry->unk_24;
    slots[idx].unk_2 = v4;
    slots[idx].unk_3 = entry->unk_3;
    slots[idx].unk_4 = 255;
    slots[idx].unk_5 = 255;
    slots[idx].unk_6 = 255;
    slots[idx].unk_7 = 0;
    p->unk_1F1 = idx;
    slots[idx].unk_24 = v1;
    if (state == 2) {
        dst->unk_2A |= 4;
        v1 = dst->unk_24;
        if (v1 != 0) {
            *(u32 *)((u8 *)v1 + 8) &= ~4;
            *(u32 *)((u8 *)*(u32 *)&dst->unk_24 + 4) = -120;
        }
    }
    v1 = entry->unk_24;
    *(u32 *)((u8 *)v1 + 8) &= ~2;
    addr = (u32)((u8 *)p + 336);
    reset = (struct fn_1_AAB98_slot *)addr;
    flags = reset->unk_2A;
    neg = -1;
    entry->unk_24 = 0;
    entry->unk_2 = 255;
    entry->unk_3 = 255;
    reset->unk_4 = 255;
    reset->unk_5 = 255;
    reset->unk_6 = 255;
    reset->unk_7 = 0;
    reset->unk_8 = neg;
    reset->unk_A = neg;
    reset->unk_30 = 0;
    reset->unk_34 = lbl_1_rodata_4CA8;
    reset->unk_38 = lbl_1_rodata_4CA8;
    reset->unk_2A = flags & ~4;
    reset->unk_3C = neg;
    reset->unk_40 = neg;
    p->unk_1F2 = 255;
    return;
}
