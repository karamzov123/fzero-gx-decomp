#include "dolphin/hw_regs.h"
#include "types.h"

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern u32 lbl_80164D60[];
extern u32 lbl_801A6B60;
extern u32 lbl_801A6B64;
extern u32 lbl_801A6B68;
extern void DCFlushRange(void *, u32);
extern void DCInvalidateRange(void *, u32);


u32 fn_800224E4(void) {
    return lbl_801A6B68;
}

struct fn_800224EC_lbl_80164D60_0_E236 {
    u8 pad_0[0xE];
    u16 unk_E;
    u8 pad_10[0xDC];
};
struct fn_800224EC_Arg0 {
    u8 pad_0[0x18];
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x8];
    u32 unk_28;
};
struct fn_800224EC_Copy16 { u32 a[4]; };
struct fn_800224EC_Copy40 { u32 a[10]; };
struct fn_800224EC_Copy208 { u32 a[52]; };

void fn_800224EC(struct fn_800224EC_Arg0 *arg0) {
    void *v2;
    u32 v1;
    u32 v0;
    u8 *base;
    u32 v4;
    u32 *v5;
    u32 *v6;
    u32 v8;
    u32 *v18;
    u32 *v19;
    u32 v20;
    u32 v22;

    base = (u8 *)lbl_80164D60;
    lbl_801A6B68++;
    v0 = (u32)arg0 + 312;
    v2 = base + arg0->unk_18 * 236;
    v1 = arg0->unk_1C;
    if (v1 == 0) {
    *(u16 *)((u8 *)v0 + 14) = *(u16 *)((u8 *)v2 + 14);
    *(u16 *)((u8 *)v0 + 100) = *(u16 *)((u8 *)v2 + 100);
    *(u16 *)((u8 *)v0 + 122) = *(u16 *)((u8 *)v2 + 122);
    *(u16 *)((u8 *)v0 + 124) = *(u16 *)((u8 *)v2 + 124);
        return;
    }
    if ((v1 & 0x80000000) != 0) {
        *(u32 *)((u8 *)v2 + 0) = *(u32 *)((u8 *)v0 + 0);
        *(u32 *)((u8 *)v2 + 4) = *(u32 *)((u8 *)v0 + 4);
        *(u32 *)((u8 *)v2 + 8) = *(u32 *)((u8 *)v0 + 8);
        *(u32 *)((u8 *)v2 + 12) = *(u32 *)((u8 *)v0 + 12);
        *(u32 *)((u8 *)v2 + 16) = *(u32 *)((u8 *)v0 + 16);
        *(u32 *)((u8 *)v2 + 20) = *(u32 *)((u8 *)v0 + 20);
        *(u32 *)((u8 *)v2 + 24) = *(u32 *)((u8 *)v0 + 24);
        *(u32 *)((u8 *)v2 + 28) = *(u32 *)((u8 *)v0 + 28);
        *(u32 *)((u8 *)v2 + 32) = *(u32 *)((u8 *)v0 + 32);
        *(u32 *)((u8 *)v2 + 36) = *(u32 *)((u8 *)v0 + 36);
        *(u32 *)((u8 *)v2 + 40) = *(u32 *)((u8 *)v0 + 40);
        *(u32 *)((u8 *)v2 + 44) = *(u32 *)((u8 *)v0 + 44);
        *(u32 *)((u8 *)v2 + 48) = *(u32 *)((u8 *)v0 + 48);
        *(u32 *)((u8 *)v2 + 52) = *(u32 *)((u8 *)v0 + 52);
        *(u32 *)((u8 *)v2 + 56) = *(u32 *)((u8 *)v0 + 56);
        *(u32 *)((u8 *)v2 + 60) = *(u32 *)((u8 *)v0 + 60);
        *(u32 *)((u8 *)v2 + 64) = *(u32 *)((u8 *)v0 + 64);
        *(u32 *)((u8 *)v2 + 68) = *(u32 *)((u8 *)v0 + 68);
        *(u32 *)((u8 *)v2 + 72) = *(u32 *)((u8 *)v0 + 72);
        *(u32 *)((u8 *)v2 + 76) = *(u32 *)((u8 *)v0 + 76);
        *(u32 *)((u8 *)v2 + 80) = *(u32 *)((u8 *)v0 + 80);
        *(u32 *)((u8 *)v2 + 84) = *(u32 *)((u8 *)v0 + 84);
        *(u32 *)((u8 *)v2 + 88) = *(u32 *)((u8 *)v0 + 88);
        *(u32 *)((u8 *)v2 + 92) = *(u32 *)((u8 *)v0 + 92);
        *(u32 *)((u8 *)v2 + 96) = *(u32 *)((u8 *)v0 + 96);
        *(u32 *)((u8 *)v2 + 100) = *(u32 *)((u8 *)v0 + 100);
        *(u32 *)((u8 *)v2 + 104) = *(u32 *)((u8 *)v0 + 104);
        *(u32 *)((u8 *)v2 + 108) = *(u32 *)((u8 *)v0 + 108);
        *(u32 *)((u8 *)v2 + 112) = *(u32 *)((u8 *)v0 + 112);
        *(u32 *)((u8 *)v2 + 116) = *(u32 *)((u8 *)v0 + 116);
        *(u32 *)((u8 *)v2 + 120) = *(u32 *)((u8 *)v0 + 120);
        *(u32 *)((u8 *)v2 + 124) = *(u32 *)((u8 *)v0 + 124);
        *(u32 *)((u8 *)v2 + 128) = *(u32 *)((u8 *)v0 + 128);
        *(u32 *)((u8 *)v2 + 132) = *(u32 *)((u8 *)v0 + 132);
        *(u32 *)((u8 *)v2 + 136) = *(u32 *)((u8 *)v0 + 136);
        *(u32 *)((u8 *)v2 + 140) = *(u32 *)((u8 *)v0 + 140);
        *(u32 *)((u8 *)v2 + 144) = *(u32 *)((u8 *)v0 + 144);
        *(u32 *)((u8 *)v2 + 148) = *(u32 *)((u8 *)v0 + 148);
        *(u32 *)((u8 *)v2 + 152) = *(u32 *)((u8 *)v0 + 152);
        *(u32 *)((u8 *)v2 + 156) = *(u32 *)((u8 *)v0 + 156);
        *(u32 *)((u8 *)v2 + 160) = *(u32 *)((u8 *)v0 + 160);
        *(u32 *)((u8 *)v2 + 164) = *(u32 *)((u8 *)v0 + 164);
        *(u32 *)((u8 *)v2 + 168) = *(u32 *)((u8 *)v0 + 168);
        *(u32 *)((u8 *)v2 + 172) = *(u32 *)((u8 *)v0 + 172);
        *(u32 *)((u8 *)v2 + 176) = *(u32 *)((u8 *)v0 + 176);
        *(u32 *)((u8 *)v2 + 180) = *(u32 *)((u8 *)v0 + 180);
        *(u32 *)((u8 *)v2 + 184) = *(u32 *)((u8 *)v0 + 184);
        *(u32 *)((u8 *)v2 + 188) = *(u32 *)((u8 *)v0 + 188);
        *(u32 *)((u8 *)v2 + 192) = *(u32 *)((u8 *)v0 + 192);
        *(u32 *)((u8 *)v2 + 196) = *(u32 *)((u8 *)v0 + 196);
        *(u32 *)((u8 *)v2 + 200) = *(u32 *)((u8 *)v0 + 200);
        *(u32 *)((u8 *)v2 + 204) = *(u32 *)((u8 *)v0 + 204);
        v4 = arg0->unk_28;
        if (v4 == 0) { return; }
        v5 = (u32 *)((u8 *)arg0 + 52);
        v6 = (u32 *)(base + (arg0->unk_18 << 8));
        v6 += 4800;
        for (v8 = v4; v8 != 0; v8--) {
            *v5++ = *v6++;
        }
        return;
    }
    if ((v1 & 0x1) != 0) {
    *(u16 *)((u8 *)v2 + 8) = *(u16 *)((u8 *)v0 + 8);
    *(u16 *)((u8 *)v2 + 10) = *(u16 *)((u8 *)v0 + 10);
    }
    if ((v1 & 0x2) != 0) {
    *(u16 *)((u8 *)v2 + 12) = *(u16 *)((u8 *)v0 + 12);
    }
    if ((v1 & 0x4) != 0) {
    *(u16 *)((u8 *)v2 + 14) = *(u16 *)((u8 *)v0 + 14);
    } else {
    *(u16 *)((u8 *)v0 + 14) = *(u16 *)((u8 *)v2 + 14);
    }
    if ((v1 & 0x8) != 0) {
    *(u16 *)((u8 *)v2 + 16) = *(u16 *)((u8 *)v0 + 16);
    }
    if ((v1 & 0x10) != 0) {
    *(u16 *)((u8 *)v2 + 18) = *(u16 *)((u8 *)v0 + 18);
    *(u16 *)((u8 *)v2 + 20) = *(u16 *)((u8 *)v0 + 20);
    *(u16 *)((u8 *)v2 + 22) = *(u16 *)((u8 *)v0 + 22);
    *(u16 *)((u8 *)v2 + 24) = *(u16 *)((u8 *)v0 + 24);
    *(u16 *)((u8 *)v2 + 26) = *(u16 *)((u8 *)v0 + 26);
    *(u16 *)((u8 *)v2 + 28) = *(u16 *)((u8 *)v0 + 28);
    *(u16 *)((u8 *)v2 + 30) = *(u16 *)((u8 *)v0 + 30);
    *(u16 *)((u8 *)v2 + 32) = *(u16 *)((u8 *)v0 + 32);
    *(u16 *)((u8 *)v2 + 34) = *(u16 *)((u8 *)v0 + 34);
    *(u16 *)((u8 *)v2 + 36) = *(u16 *)((u8 *)v0 + 36);
    *(u16 *)((u8 *)v2 + 38) = *(u16 *)((u8 *)v0 + 38);
    *(u16 *)((u8 *)v2 + 40) = *(u16 *)((u8 *)v0 + 40);
    *(u16 *)((u8 *)v2 + 42) = *(u16 *)((u8 *)v0 + 42);
    *(u16 *)((u8 *)v2 + 44) = *(u16 *)((u8 *)v0 + 44);
    *(u16 *)((u8 *)v2 + 46) = *(u16 *)((u8 *)v0 + 46);
    *(u16 *)((u8 *)v2 + 48) = *(u16 *)((u8 *)v0 + 48);
    *(u16 *)((u8 *)v2 + 50) = *(u16 *)((u8 *)v0 + 50);
    *(u16 *)((u8 *)v2 + 52) = *(u16 *)((u8 *)v0 + 52);
    }
    if ((v1 & 0x40) != 0) {
    *(u16 *)((u8 *)v2 + 64) = *(u16 *)((u8 *)v0 + 64);
    *(u16 *)((u8 *)v2 + 66) = *(u16 *)((u8 *)v0 + 66);
    } else if ((v1 & 0x20) != 0) {
    *(u16 *)((u8 *)v2 + 54) = *(u16 *)((u8 *)v0 + 54);
    *(u16 *)((u8 *)v2 + 56) = *(u16 *)((u8 *)v0 + 56);
    *(u16 *)((u8 *)v2 + 58) = *(u16 *)((u8 *)v0 + 58);
    *(u16 *)((u8 *)v2 + 60) = *(u16 *)((u8 *)v0 + 60);
    *(u16 *)((u8 *)v2 + 62) = *(u16 *)((u8 *)v0 + 62);
    *(u16 *)((u8 *)v2 + 64) = *(u16 *)((u8 *)v0 + 64);
    *(u16 *)((u8 *)v2 + 66) = *(u16 *)((u8 *)v0 + 66);
        v18 = *(u32 **)((u8 *)arg0 + 0x134);
        v18[0] = 0;
        v18[1] = 0;
        v18[2] = 0;
        v18[3] = 0;
        v18[4] = 0;
        v18[5] = 0;
        v18[6] = 0;
        v18[7] = 0;
        v18[8] = 0;
        v18[9] = 0;
        v18[10] = 0;
        v18[11] = 0;
        v18[12] = 0;
        v18[13] = 0;
        v18[14] = 0;
        v18[15] = 0;
    }
    if ((v1 & 0x80) != 0) {
    *(u16 *)((u8 *)v2 + 68) = *(u16 *)((u8 *)v0 + 68);
    *(u16 *)((u8 *)v2 + 70) = *(u16 *)((u8 *)v0 + 70);
    *(u16 *)((u8 *)v2 + 72) = *(u16 *)((u8 *)v0 + 72);
    *(u16 *)((u8 *)v2 + 74) = *(u16 *)((u8 *)v0 + 74);
    *(u16 *)((u8 *)v2 + 76) = *(u16 *)((u8 *)v0 + 76);
        v20 = arg0->unk_28;
        if (v20 != 0) {
            v19 = (u32 *)((u8 *)arg0 + 52);
            v18 = (u32 *)(base + (arg0->unk_18 << 8));
            v18 += 4800;
            for (v22 = v20; v22 != 0; v22--) {
                *v18++ = *v19++;
            }
        }
    }
    if ((v1 & 0x100) != 0) {
    *(u16 *)((u8 *)v2 + 82) = *(u16 *)((u8 *)v0 + 82);
    *(u16 *)((u8 *)v2 + 84) = *(u16 *)((u8 *)v0 + 84);
    *(u16 *)((u8 *)v2 + 86) = *(u16 *)((u8 *)v0 + 86);
    *(u16 *)((u8 *)v2 + 88) = *(u16 *)((u8 *)v0 + 88);
    *(u16 *)((u8 *)v2 + 90) = *(u16 *)((u8 *)v0 + 90);
    *(u16 *)((u8 *)v2 + 92) = *(u16 *)((u8 *)v0 + 92);
    *(u16 *)((u8 *)v2 + 94) = *(u16 *)((u8 *)v0 + 94);
    *(u16 *)((u8 *)v2 + 96) = *(u16 *)((u8 *)v0 + 96);
    *(u16 *)((u8 *)v2 + 98) = *(u16 *)((u8 *)v0 + 98);
    }
    if ((v1 & 0x400) != 0) {
    *(u16 *)((u8 *)v0 + 100) = *(u16 *)((u8 *)v2 + 100);
        *(s16 *)((u8 *)v2 + 102) = *(s16 *)((u8 *)v0 + 102);
    } else if ((v1 & 0x200) != 0) {
    *(u16 *)((u8 *)v2 + 100) = *(u16 *)((u8 *)v0 + 100);
        *(s16 *)((u8 *)v2 + 102) = *(s16 *)((u8 *)v0 + 102);
    }
    if ((v1 & 0x800) != 0) {
    *(u16 *)((u8 *)v2 + 104) = *(u16 *)((u8 *)v0 + 104);
    *(u16 *)((u8 *)v2 + 106) = *(u16 *)((u8 *)v0 + 106);
    *(u16 *)((u8 *)v2 + 108) = *(u16 *)((u8 *)v0 + 108);
    }
    if ((v1 & 0x1E000) != 0) {
        if ((v1 & 0x2000) != 0) {
    *(u16 *)((u8 *)v2 + 110) = *(u16 *)((u8 *)v0 + 110);
        }
        if ((v1 & 0x4000) != 0) {
            *(u32 *)((u8 *)v2 + 114) = *(u32 *)((u8 *)v0 + 114);
        }
        if ((v1 & 0x8000) != 0) {
            *(u32 *)((u8 *)v2 + 118) = *(u32 *)((u8 *)v0 + 118);
        }
        if ((v1 & 0x10000) != 0) {
            *(u32 *)((u8 *)v2 + 122) = *(u32 *)((u8 *)v0 + 122);
        } else {
            *(u32 *)((u8 *)v0 + 122) = *(u32 *)((u8 *)v2 + 122);
        }
    } else if ((v1 & 0x1000) != 0) {
        *(u32 *)((u8 *)v2 + 110) = *(u32 *)((u8 *)v0 + 110);
        *(u32 *)((u8 *)v2 + 114) = *(u32 *)((u8 *)v0 + 114);
        *(u32 *)((u8 *)v2 + 118) = *(u32 *)((u8 *)v0 + 118);
        *(u32 *)((u8 *)v2 + 122) = *(u32 *)((u8 *)v0 + 122);
    } else {
    *(u16 *)((u8 *)v0 + 122) = *(u16 *)((u8 *)v2 + 122);
    *(u16 *)((u8 *)v0 + 124) = *(u16 *)((u8 *)v2 + 124);
    }
    if ((v1 & 0x20000) != 0) {
        *(u32 *)((u8 *)v2 + 126) = *(u32 *)((u8 *)v0 + 126);
        *(u32 *)((u8 *)v2 + 130) = *(u32 *)((u8 *)v0 + 130);
        *(u32 *)((u8 *)v2 + 134) = *(u32 *)((u8 *)v0 + 134);
        *(u32 *)((u8 *)v2 + 138) = *(u32 *)((u8 *)v0 + 138);
        *(u32 *)((u8 *)v2 + 142) = *(u32 *)((u8 *)v0 + 142);
        *(u32 *)((u8 *)v2 + 146) = *(u32 *)((u8 *)v0 + 146);
        *(u32 *)((u8 *)v2 + 150) = *(u32 *)((u8 *)v0 + 150);
        *(u32 *)((u8 *)v2 + 154) = *(u32 *)((u8 *)v0 + 154);
        *(u32 *)((u8 *)v2 + 158) = *(u32 *)((u8 *)v0 + 158);
        *(u32 *)((u8 *)v2 + 162) = *(u32 *)((u8 *)v0 + 162);
    }
    if ((v1 & 0x80000) != 0) {
    *(u16 *)((u8 *)v2 + 166) = *(u16 *)((u8 *)v0 + 166);
    *(u16 *)((u8 *)v2 + 168) = *(u16 *)((u8 *)v0 + 168);
    } else if ((v1 & 0x40000) != 0) {
    *(u16 *)((u8 *)v2 + 166) = *(u16 *)((u8 *)v0 + 166);
    *(u16 *)((u8 *)v2 + 168) = *(u16 *)((u8 *)v0 + 168);
    *(u16 *)((u8 *)v2 + 170) = *(u16 *)((u8 *)v0 + 170);
    *(u16 *)((u8 *)v2 + 172) = *(u16 *)((u8 *)v0 + 172);
    *(u16 *)((u8 *)v2 + 174) = *(u16 *)((u8 *)v0 + 174);
    *(u16 *)((u8 *)v2 + 176) = *(u16 *)((u8 *)v0 + 176);
    *(u16 *)((u8 *)v2 + 178) = *(u16 *)((u8 *)v0 + 178);
    }
    if ((v1 & 0x100000) == 0) { return; }
    *(u16 *)((u8 *)v2 + 180) = *(u16 *)((u8 *)v0 + 180);
    *(u16 *)((u8 *)v2 + 182) = *(u16 *)((u8 *)v0 + 182);
    *(u16 *)((u8 *)v2 + 184) = *(u16 *)((u8 *)v0 + 184);
}

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

extern u8 lbl_80124710[];
extern u32 fn_800207E8(u32);
extern u32 fn_800211F8(void);
extern void fn_80022450(struct Sig_fn_80022450_fn_80022450_Arg0 *);
extern void fn_800209FC(struct Sig_fn_800209FC_fn_800209FC_Arg0 *);
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
                v6 = (((pa->value) + ((pb->value) + ((0x8c)))));
                acc = v6 + acc;
                pc = (struct Table14 *)(tbl + ((f & 15) << 2));
                acc = ((pc->value) + acc);
                if (lbl_801A6B60 > acc) {
                    fn_800224EC((struct fn_800224EC_Arg0 *)node);
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
                fn_800224EC((struct fn_800224EC_Arg0 *)node);
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

#pragma opt_propagation reset
#pragma opt_lifetimes reset

u32 fn_80022E5C(void) {
    return (u32)&lbl_80164D60;
}

struct fn_80022E68_Arg0 {
    u8 pad_0[0x1C];
    u32 unk_1C;
    u8 pad_20[0x4];
    u32 unk_24;
    u32 unk_28;
    u8 pad_2C[0x4];
    u32 unk_30;
    u8 pad_34[0x112];
    u16 unk_146;
    u8 pad_148[0x26];
    u16 unk_16E;
    u8 pad_170[0xC];
    u16 unk_17C;
    u16 unk_17E;
    u16 unk_180;
    u16 unk_182;
    u16 unk_184;
};

void fn_80022E68(struct fn_80022E68_Arg0 *arg0) {
    arg0->unk_146 = 0;
    arg0->unk_16E = 0;
    arg0->unk_1C = 164;
    arg0->unk_28 = 0;
    arg0->unk_24 = 0;
    arg0->unk_30 = ((u32)arg0 + 52);
    arg0->unk_184 = 0;
    arg0->unk_182 = 0;
    arg0->unk_180 = 0;
    arg0->unk_17E = 0;
    arg0->unk_17C = 0;
}

/* one 0xEC-byte entry of the table at lbl_80164D60 */
struct fn_80022EA4_Block {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
    u8 pad_8[0x30];
    u16 unk_38;
    u16 unk_3A;
    u8 pad_3C[0x12];
    u16 unk_4E;
    u16 unk_50;
    u8 pad_52[0x9A];
};

/* one 0x224-byte entry of the table at lbl_80164D60+0x8B00 */
struct fn_80022EA4_Entry {
    u8 pad_0[0xC];
    u32 unk_C;
    u8 pad_10[0x8];
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x4];
    u32 unk_24;
    u32 unk_28;
    u8 pad_2C[0x4];
    void *unk_30;
    u8 unk_34[0x100];
    void *unk_134;
    u16 unk_138;
    u16 unk_13A;
    u16 unk_13C;
    u16 unk_13E;
    u8 pad_140[0x6];
    u16 unk_146;
    u8 pad_148[0x26];
    u16 unk_16E;
    u16 unk_170;
    u16 unk_172;
    u8 pad_174[0x8];
    u16 unk_17C;
    u16 unk_17E;
    u16 unk_180;
    u16 unk_182;
    u16 unk_184;
    u16 unk_186;
    u16 unk_188;
    u8 pad_18A[0x9A];
};

/* lbl_80164D60 is four tables that the retail TU defined, so MWCC addresses them off one section base:
 * 0x40 blocks of 0xEC bytes, 0x40 buffers of 0x40 and of 0x100 bytes, then 0x40 entries of 0x224 bytes */
struct fn_80022EA4_Block fzgx_obj_lbl_80164D60[0x40];
u8 fzgx_obj_lbl_80164D60__fzgx_offset_3B00[0x40][0x40];
u8 fzgx_obj_lbl_80164D60__fzgx_offset_4B00[0x40][0x100];
struct fn_80022EA4_Entry fzgx_obj_lbl_80164D60__fzgx_offset_8B00[0x40];

#pragma section code_type ".fzgxpool"
static void layout____bss_0(void) {
    volatile unsigned char sink; // fzgx-allow: S2 discarded layout primer
    sink = *(unsigned char *)&fzgx_obj_lbl_80164D60;
    sink = *(unsigned char *)&fzgx_obj_lbl_80164D60__fzgx_offset_3B00;
    sink = *(unsigned char *)&fzgx_obj_lbl_80164D60__fzgx_offset_4B00;
    sink = *(unsigned char *)&fzgx_obj_lbl_80164D60__fzgx_offset_8B00;
}
#pragma section code_type ".text"

extern void fn_800209DC(struct fn_80022EA4_Entry *entry);
/* fn_80022E68, which retail inlines here */
static inline void fn_80022E68_inline(struct fn_80022EA4_Entry *entry) {
    entry->unk_146 = 0;
    entry->unk_16E = 0;
    entry->unk_1C = 164;
    entry->unk_28 = 0;
    entry->unk_24 = 0;
    entry->unk_30 = entry->unk_34;
    entry->unk_184 = 0;
    entry->unk_182 = 0;
    entry->unk_180 = 0;
    entry->unk_17E = 0;
    entry->unk_17C = 0;
}

void fn_80022EA4(void) {
    u32 i;
    s32 j;
    struct fn_80022EA4_Block *block;
    u8 *buf40;
    u8 *buf100;
    struct fn_80022EA4_Entry *entry;

    lbl_801A6B60 = OS_BUS_CLOCK / 400;
    lbl_801A6B64 = 0;

    /* a signed index gives retail's eight-store unrolled loops */
    for (j = 0; j < sizeof(fzgx_obj_lbl_80164D60) / 4; j++) {
        ((u32 *)fzgx_obj_lbl_80164D60)[j] = 0;
    }
    for (j = 0; j < sizeof(fzgx_obj_lbl_80164D60__fzgx_offset_3B00) / 4; j++) {
        ((u32 *)fzgx_obj_lbl_80164D60__fzgx_offset_3B00)[j] = 0;
    }
    for (j = 0; j < sizeof(fzgx_obj_lbl_80164D60__fzgx_offset_8B00) / 4; j++) {
        ((u32 *)fzgx_obj_lbl_80164D60__fzgx_offset_8B00)[j] = 0;
    }

    for (i = 0; i < 0x40; i++) {
        block = &fzgx_obj_lbl_80164D60[i];
        buf40 = fzgx_obj_lbl_80164D60__fzgx_offset_3B00[i];
        buf100 = fzgx_obj_lbl_80164D60__fzgx_offset_4B00[i];
        entry = &fzgx_obj_lbl_80164D60__fzgx_offset_8B00[i];

        entry->unk_18 = i;
        entry->unk_30 = entry->unk_34;
        entry->unk_134 = buf40;
        fn_80022E68_inline(entry);

        /* the blocks form a chain: each holds the next one's address as two halves, the last holds 0 */
        if (i == 0x3F) {
            entry->unk_138 = entry->unk_13A = block->unk_0 = block->unk_2 = 0;
        } else {
            entry->unk_138 = (u32)(block + 1) >> 16;
            entry->unk_13A = (u32)(block + 1);
            block->unk_0 = (u32)(block + 1) >> 16;
            block->unk_2 = (u32)(block + 1);
        }
        entry->unk_13C = (u32)block >> 16;
        entry->unk_13E = (u32)block;
        block->unk_4 = (u32)block >> 16;
        block->unk_6 = (u32)block;
        entry->unk_170 = (u32)buf40 >> 16;
        entry->unk_172 = (u32)buf40;
        block->unk_38 = (u32)buf40 >> 16;
        block->unk_3A = (u32)buf40;
        entry->unk_186 = (u32)buf100 >> 16;
        entry->unk_188 = (u32)buf100;
        block->unk_4E = (u32)buf100 >> 16;
        block->unk_50 = (u32)buf100;
        entry->unk_C = 1;
        fn_800209DC(entry);
    }
    DCFlushRange(fzgx_obj_lbl_80164D60, sizeof(fzgx_obj_lbl_80164D60));
}

// fn_800230A0: empty in retail (single blr).
void fn_800230A0(void) {
}

void fn_800230A4(void *arg0, s32 arg1) {
    s32 temp_r3;
    void *temp_r4;

    temp_r3 = OSDisableInterrupts();
    temp_r4 = ((u8 *)(arg0) + 0x138);
    switch (arg1) {                                 /* irregular */
    case 0:
        (*(s16 *)((u8 *)(temp_r4) + 8)) = 2;
        break;
    case 1:
        (*(s16 *)((u8 *)(temp_r4) + 8)) = 1;
        break;
    case 2:
        (*(s16 *)((u8 *)(temp_r4) + 8)) = 0;
        (*(s16 *)((u8 *)(temp_r4) + 10)) = 0;
        break;
    case 3:
        (*(s16 *)((u8 *)(temp_r4) + 8)) = 0;
        (*(s16 *)((u8 *)(temp_r4) + 10)) = 1;
        break;
    case 4:
        (*(s16 *)((u8 *)(temp_r4) + 8)) = 0;
        (*(s16 *)((u8 *)(temp_r4) + 10)) = 2;
        break;
    }
    (*(s32 *)((u8 *)(arg0) + 28)) = ((*(s32 *)((u8 *)(arg0) + 28)) | 1);
    OSRestoreInterrupts(temp_r3);
}

typedef struct Fn80023168State {
    u8 pad_000[0x1c];
    u32 flags;
    u32 state;
    u8 pad_024[0x122];
    u16 value;
} Fn80023168State;

void fn_80023168(Fn80023168State *state, u16 value) {
    u32 level = OSDisableInterrupts();

    state->value = value;
    state->flags |= 4;
    if (value == 0) {
        state->state = 1;
    }

    OSRestoreInterrupts(level);
}

typedef struct Fn800231C4Work {
    u8 _pad0[0x1c];
    u32 flags;
    u8 _pad1[0x14e];
    s16 field_16e;
    u8 _pad2[4];
    s16 field_174;
    s16 field_176;
    s16 field_178;
    s16 field_17a;
} Fn800231C4Work;

void fn_800231C4(Fn800231C4Work *work) {
    u32 interrupts = OSDisableInterrupts();
    work->field_16e = 1;
    work->field_17a = 0;
    work->field_178 = 0;
    work->field_176 = 0;
    work->field_174 = 0;
    work->flags = work->flags & ~0x40;
    work->flags = work->flags | 0x20;
    OSRestoreInterrupts(interrupts);
}

typedef struct Fn80023228Work {
    u8 _pad0[0x1c];
    u32 flags;
    u8 _pad1[0x158];
    s16 field_178;
    s16 field_17a;
} Fn80023228Work;

void fn_80023228(Fn80023228Work *work, s16 field_178, s16 field_17a) {
    u32 interrupts;
    interrupts = OSDisableInterrupts();
    work->field_178 = field_178;
    work->field_17a = field_17a;
    work->flags = work->flags | 0x40;
    OSRestoreInterrupts(interrupts);
}

typedef struct fn_80023284_Work {
    u8 _pad0[0x1c];
    u32 flags;
} fn_80023284_Work;

void fn_80023284(fn_80023284_Work *work, u8 *src) {
    BOOL old;
    u8 *dst;
    dst = (u8 *)work + 0x1a6;
    old = OSDisableInterrupts();

    *(u32 *)(dst + 0x0) = *(u32 *)(src + 0x0);
    *(u32 *)(dst + 0x4) = *(u32 *)(src + 0x4);
    *(u32 *)(dst + 0x8) = *(u32 *)(src + 0x8);
    *(u32 *)(dst + 0xc) = *(u32 *)(src + 0xc);

    switch (*(u16 *)(src + 2)) {
    case 0:
        break;
    case 10:
        *(u32 *)(dst + 0x10) = 0;
        *(u32 *)(dst + 0x14) = 0;
        *(u32 *)(dst + 0x18) = 0;
        *(u32 *)(dst + 0x1c) = 0;
        *(u32 *)(dst + 0x20) = 0;
        *(u32 *)(dst + 0x24) = 0;
        *(u32 *)(dst + 0x28) = 0;
        *(u32 *)(dst + 0x2c) = 0;
        *(u32 *)(dst + 0x30) = 0x08000000;
        *(u32 *)(dst + 0x34) = 0;
        break;
    case 25:
        *(u32 *)(dst + 0x10) = 0;
        *(u32 *)(dst + 0x14) = 0;
        *(u32 *)(dst + 0x18) = 0;
        *(u32 *)(dst + 0x1c) = 0;
        *(u32 *)(dst + 0x20) = 0;
        *(u32 *)(dst + 0x24) = 0;
        *(u32 *)(dst + 0x28) = 0;
        *(u32 *)(dst + 0x2c) = 0;
        *(u32 *)(dst + 0x30) = 0x01000000;
        *(u32 *)(dst + 0x34) = 0;
        break;
    }

    work->flags = work->flags & 0xFFFE1FFF;
    work->flags = (work->flags | 0x20000) | 0x1000;
    OSRestoreInterrupts(old);
}

void fn_80023394(u32 arg0, u32 arg1) {
    BOOL level;
    u32 *v0;
    u32 *v1;

    v0 = (u32 *)(arg0 + 438);
    v1 = (u32 *)arg1;
    level = OSDisableInterrupts();
    v0[0] = v1[0];
    v0[1] = v1[1];
    v0[2] = v1[2];
    v0[3] = v1[3];
    v0[4] = v1[4];
    v0[5] = v1[5];
    v0[6] = v1[6];
    v0[7] = v1[7];
    v0[8] = v1[8];
    v0[9] = v1[9];
    *(u32 *)((u8 *)arg0 + 28) |= 0x20000;
    OSRestoreInterrupts(level);
}

void fn_80023438(u32 arg0, u32 arg1) {
    BOOL level;
    s32 v0;
    u32 v2;
    s32 v1;
    v0 = arg1;
    v1 = arg0;
    v2 = (v1 + 478);
    level = OSDisableInterrupts();
    *(u16 *)((u8 *)v2 + 0) = *(u16 *)((u8 *)v0 + 0);
    *(u16 *)((u8 *)v2 + 2) = *(u16 *)((u8 *)v0 + 2);
    *(u16 *)((u8 *)v2 + 4) = *(u16 *)((u8 *)v0 + 4);
    *(u16 *)((u8 *)v2 + 6) = *(u16 *)((u8 *)v0 + 6);
    *(u16 *)((u8 *)v2 + 8) = *(u16 *)((u8 *)v0 + 8);
    *(u16 *)((u8 *)v2 + 10) = *(u16 *)((u8 *)v0 + 10);
    *(u16 *)((u8 *)v2 + 12) = *(u16 *)((u8 *)v0 + 12);
    *(u32 *)((u8 *)v1 + 28) = (*(u32 *)((u8 *)v1 + 28) & 0xFFF7FFFF);
    *(u32 *)((u8 *)v1 + 28) = (*(u32 *)((u8 *)v1 + 28) | 0x40000);
    OSRestoreInterrupts(level);
}

extern f32 lbl_801A6F78[2];
extern u32 __cvt_fp2unsigned(f32 value);
typedef struct Fn800234D0State {
    u8 pad_000[0x1c];
    u32 flags;
    u8 pad_020[0x1be];
    u16 value_high;
    u16 value_low;
} Fn800234D0State;

void fn_800234D0(Fn800234D0State *state, f32 value) {
    f32 scaled;
    u32 value_high;
    u32 value_low;
    u32 level;

    level = OSDisableInterrupts();
    scaled = lbl_801A6F78[0] * value;
    value_high = __cvt_fp2unsigned(scaled);
    value_low = __cvt_fp2unsigned(scaled);
    if (value_low > 0x40000) {
        value_high = 0x40000;
    }
    state->value_high = (value_high >> 16);
    state->value_low = value_high;
    state->flags |= 0x80000;
    OSRestoreInterrupts(level);
}

void fn_80023568(u32 arg0, u32 arg1) {
    BOOL level;
    s32 v0;
    u32 v2;
    s32 v1;
    v0 = arg1;
    v1 = arg0;
    v2 = (v1 + 492);
    level = OSDisableInterrupts();
    *(u16 *)((u8 *)v2 + 0) = *(u16 *)((u8 *)v0 + 0);
    *(u16 *)((u8 *)v2 + 2) = *(u16 *)((u8 *)v0 + 2);
    *(u16 *)((u8 *)v2 + 4) = *(u16 *)((u8 *)v0 + 4);
    *(u32 *)((u8 *)v1 + 28) = (*(u32 *)((u8 *)v1 + 28) | 0x100000);
    OSRestoreInterrupts(level);
}
