#include "types.h"

struct fn_80053DB4_Arg0 {
    u8 pad_0[0xC];
    void *unk_C;
    void *unk_10;
};

extern u32 fn_80053A30(void);
extern void fn_80051F38(u32, void *, void *);
extern u32 lbl_801873C0[6];
extern void (*lbl_80130BC0[16])(void *, void *, void *);

void fn_80053DB4(struct fn_80053DB4_Arg0 *obj, u32 arg1, u32 ch, void *arg3) {
    u32 *p;
    u8 *buf;
    s32 idx;
    void *unkC;
    void *addr;

    p = (u32 *)((u8 *)obj + (ch << 2));
    buf = (u8 *)obj + (ch << 12);
    p[1] = ((*((1) + (p))) - 0x40) & 0x3FF;
    idx = (*((1) + (p)));
    unkC = obj->unk_C;
    addr = buf + 0x14 + (idx << 2);
    lbl_801873C0[0] = fn_80053A30();
    if (((arg1 & 0x1F) != 0) || (((u32)unkC & 0x1F) != 0)) {
        while (1) {
        }
    }
    fn_80051F38(arg1, unkC, addr);
    lbl_801873C0[4] = fn_80053A30();
    idx = (*((1) + (p)));
    lbl_801873C0[0] = fn_80053A30();
    (*((idx >> 6) + (lbl_80130BC0)))((u8 *)((u32 *)(buf + 0x14) + idx), obj->unk_10, arg3);
    lbl_801873C0[4] = fn_80053A30();
}
