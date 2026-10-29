#include "types.h"

struct Sig_fn_80022450_fn_80022450_Arg0 {
    u8 pad_0[0x52];
    s16 unk_52, unk_54, unk_56, unk_58, unk_5A, unk_5C, unk_5E, unk_60, unk_62;
};
struct Sig_fn_800209FC_fn_800209FC_Arg0 {
    u8 pad_0[8];
    u32 unk_8;
};
struct Table54 { u8 pad[0x54]; u32 value; };
struct Table14 { u8 pad[0x14]; u32 value; };

extern u32 lbl_80164D60[];
extern u8 lbl_80124710[];
extern u32 lbl_801A6B60;
extern u32 lbl_801A6B64;
extern u32 lbl_801A6B68;
extern u32 fn_800207E8(u32);
extern u32 fn_800211F8(void);
extern u32 fn_800224EC(u32);
extern void fn_80022450(struct Sig_fn_80022450_fn_80022450_Arg0 *);
extern void fn_800209FC(struct Sig_fn_800209FC_fn_800209FC_Arg0 *);
extern void DCInvalidateRange(void *, u32);
extern void DCFlushRange(void *, u32);

#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_80022BF4(u32 arg0) {
    struct { u8 *value; } base;
    u32 node2;
    u8 *tbl;
    u32 acc;
    s32 i;
    u32 node;
    u32 v6;
    u32 v9;
    u32 z;
    u16 f;
    struct Table54 *pa;
    struct Table54 *pb;
    struct Table14 *pc;

    base.value = (u8 *)&lbl_80164D60;
    tbl = (u8 *)&lbl_80124710;
    lbl_801A6B68 = 0;
    DCInvalidateRange(base.value, 0x3b00);
    DCInvalidateRange(base.value + 0x3b00, 0x1000);
    acc = fn_800211F8() + 0x10000 + arg0 - 0x55f0;
    for (i = 31; i != 0; i--) {
        node = fn_800207E8(i);
        while (node != 0) {
            if (*(u32 *)(node + 0x20) != 0)
                fn_80022450((struct Sig_fn_80022450_fn_80022450_Arg0 *)(base.value + *(u32 *)(0x18 + node) * 0xec));
            if (*(u16 *)(node + 0x146) == 1 || *(u32 *)(node + 0x28) != 0) {
                if (*(u16 *)(node + 0x140) != 2)
                    acc += ((u32 *)tbl)[*(u16 *)(node + 0x1de)];
                f = *(u16 *)(node + 0x144);
                pa = (struct Table54 *)(tbl + ((f >> 7) & 0x7c));
                pb = (struct Table54 *)(tbl + ((f >> 2) & 0x7c));
                v6 = ((((pa->value)) + (((pb->value)) + ((0x8c)))));
                acc = v6 + acc;
                pc = (struct Table14 *)(tbl + ((f & 15) << 2));
                acc = ((pc->value) + (acc));
                if (lbl_801A6B60 > acc) {
                    fn_800224EC(node);
                } else {
                    u8 *e = base.value + *(u32 *)(node + 0x18) * 0xec;
                    if (*(u16 *)(e + 0xe) == 1)
                        fn_80022450((struct Sig_fn_80022450_fn_80022450_Arg0 *)e);
                    *(u16 *)(e + 0x4c) = 0;
                    *(u16 *)(e + 0x4a) = 0;
                    *(u16 *)(e + 0x48) = 0;
                    *(u16 *)(e + 0x46) = 0;
                    *(u16 *)(e + 0x44) = 0;
                    *(u16 *)(e + 0xe) = 0;
                    *(u16 *)(node + 0x146) = 0;
                    fn_800209FC((struct Sig_fn_800209FC_fn_800209FC_Arg0 *)node);
                }
            } else {
                fn_800224EC(node);
            }
            z = 0;
            *(u32 *)(node + 0x1c) = z;
            v9 = node;
            v9 += 0x34;
            *(u32 *)(node + 0x20) = z;
            *(u32 *)(node + 0x28) = z;
            *(u32 *)(node + 0x24) = z;
            *(u32 *)(node + 0x30) = v9;
            node = *(u32 *)node;
        }
    }
    lbl_801A6B64 = acc;
    v6 = fn_800207E8(0);
    node2 = v6;
    while (node2 != 0) {
        if (*(u32 *)(node2 + 0x20) != 0)
            fn_80022450((struct Sig_fn_80022450_fn_80022450_Arg0 *)(base.value + *(u32 *)(node2 + 0x18) * 0xec));
        *(u32 *)(node2 + 0x20) = 0;
        *(u16 *)((((base.value) + (*(u32 *)(node2 + 0x18) * 0xec)) + (0x4c))) = 0;
        *(u16 *)(base.value + *(u32 *)(node2 + 0x18) * 0xec + 0x4a) = 0;
        *(u16 *)(base.value + *(u32 *)(node2 + 0x18) * 0xec + 0x48) = 0;
        *(u16 *)(base.value + *(u32 *)(node2 + 0x18) * 0xec + 0x46) = 0;
        *(u16 *)(base.value + *(u32 *)(node2 + 0x18) * 0xec + 0x44) = 0;
        *(u16 *)(base.value + *(u32 *)(node2 + 0x18) * 0xec + 0xe) = 0;
        node2 = *(u32 *)node2;
    }
    DCFlushRange(base.value, 0x3b00);
    DCFlushRange(base.value + 0x3b00, 0x1000);
    DCFlushRange(base.value + 0x4b00, 0x4000);
}
#pragma opt_lifetimes reset

