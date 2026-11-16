#include "types.h"

struct Block { u8 *data; s32 size; };
typedef void (*Method2)(void *, s32, struct Block *);
typedef void (*Method3)(void *, s32, u32, struct Block *);
struct Stream { u32 *vtable; };
struct fn_800502A0_Arg0 {
    u32 unk_0;
    struct Stream *unk_4;
    u32 unk_8;
    s32 unk_C;
    s32 unk_10;
    u32 unk_14;
    u32 unk_18;
    struct Block unk_1C;
    s32 unk_24;
    u8 *unk_28;
};
extern u32 fn_800589BC(struct Block *, s32, struct Block *, struct Block *);

void fn_800502A0(struct fn_800502A0_Arg0 *arg0) {
    u32 v;
    struct Stream * fzgx_live;
    u32 value;
    s32 count;
    s32 amount;
    struct Block first;
    struct Block second;
    u8 * p;
    count = (32 - arg0->unk_C) / 8;
    if (arg0->unk_24 < 4) {
        first = arg0->unk_1C;
        if (first.size != 0) {
            fn_800589BC(&first, first.size - arg0->unk_24, &first, &second);
            ((Method2)arg0->unk_4->vtable[8])(arg0->unk_4, 0, &first);
            ((Method2)arg0->unk_4->vtable[7])(arg0->unk_4, 1, &second);
        }
        fzgx_live = arg0->unk_4;
        ((Method3)fzgx_live->vtable[6])(fzgx_live, 1, arg0->unk_18, &arg0->unk_1C);
        arg0->unk_28 = arg0->unk_1C.data;
        arg0->unk_24 = arg0->unk_1C.size;
    }
    amount = arg0->unk_24;
    if (count < amount) amount = count;
    if (amount == 3) {
        p = arg0->unk_28;
        v = arg0->unk_8;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        arg0->unk_28 = p;
        arg0->unk_8 = v;
        arg0->unk_C += 24;
        arg0->unk_24 -= 3;
    } else if (amount == 2) {
        p = arg0->unk_28;
        v = arg0->unk_8;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        arg0->unk_28 = p;
        arg0->unk_8 = v;
        arg0->unk_C += 16;
        arg0->unk_24 -= 2;
    } else if (amount == 1) {
        p = arg0->unk_28;
        v = arg0->unk_8;
        v = (v << 8) | *p++;
        arg0->unk_28 = p;
        arg0->unk_8 = v;
        arg0->unk_C += 8;
        arg0->unk_24 -= 1;
    } else if (amount == 4) {
        p = arg0->unk_28;
        v = arg0->unk_8;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        v = (v << 8) | *p++;
        arg0->unk_28 = p;
        arg0->unk_8 = v;
        arg0->unk_C += 32;
        arg0->unk_24 -= 4;
    }
}
