#include "types.h"

extern u32 lbl_801A6628[2];
extern u32 fn_80071794(u32);
extern u32 fn_80078F0C(u32, void *, u8 *, u32);

struct fn_80078DA8_entry { u32 unk_0; u32 unk_4; };
struct fn_80078DA8_in { u32 unk_0; u32 unk_4; };
struct fn_80078DA8_out {
    u32 unk_0;
    u32 unk_4;
    struct fn_80078DA8_entry *unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
};

static inline void fn_80078DA8_load(struct fn_80078DA8_out *out, void *p2, u32 total) {
    struct fn_80078DA8_entry *e;
    u8 *cur;
    u32 i;
    u32 off;
    cur = (u8 *)out->unk_14;
    for (i = 0, off = 0; i < out->unk_0; off += 8, i++) {
        e = (struct fn_80078DA8_entry *)((u8 *)out->unk_8 + off);
        if (e->unk_0 == 0) {
            continue;
        }
        fn_80078F0C(e->unk_0, p2, cur, e->unk_4);
        if (total != 0) {
            cur += *(u16 *)(e->unk_0 + 0x18) * 32;
        }
    }
}

void fn_80078DA8(struct fn_80078DA8_out *out, struct fn_80078DA8_in *in, void *arg2) {
    u32 total = 0;
    void *p2 = arg2;
    u32 i;
    u32 base;

    out->unk_0 = in->unk_0;
    out->unk_4 = (u32)in + in->unk_4;
    out->unk_8 = (struct fn_80078DA8_entry *)((u8 *)in + 8);
    out->unk_C = ((in->unk_0 * 8) + ((u32)out->unk_8));
    out->unk_10 = 0;
    out->unk_14 = 0;
    for (i = 0; i < out->unk_0; i++) {
        struct fn_80078DA8_entry *en = &out->unk_8[i];
        u32 v = en->unk_0;
        if (v + 0x10000 == 0xFFFF) {
            en->unk_0 = 0;
            en->unk_4 = lbl_801A6628[0];
        } else {
            base = out->unk_4 + v;
            en->unk_0 = base;
            en->unk_4 = out->unk_C + en->unk_4;
            total += *(u16 *)(base + 0x18);
        }
    }
    if (p2 != 0 && total != 0) {
        out->unk_14 = fn_80071794(total * 32);
    } else {
        total = 0;
    }
    fn_80078DA8_load(out, p2, total);
}
