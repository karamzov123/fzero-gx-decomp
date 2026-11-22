#include "types.h"

extern u8 lbl_8015D200[];
extern void (*lbl_801A6AC0)(void *, u32);
extern void (*lbl_801A6AC4)(void *, u32);
extern u32 lbl_801A6AC8;
extern u32 lbl_801A6ACC;
extern u32 lbl_801A6AE0;


struct fn_80020D58_entry_a {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
};

struct fn_80020D58_entry_b {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
};

extern struct fn_80020D58_entry_b lbl_8015E880[];
extern u32 lbl_801A6AE4;
extern u32 lbl_801A6AE8;
extern u32 lbl_801A6AEC;
extern u32 lbl_801A6AF0;

void fn_80020D58(void) {
    struct fn_80020D58_entry_a *entry_a;
    struct fn_80020D58_entry_b *entry_b;
    u32 i;

    lbl_801A6AC0 = 0;
    lbl_801A6AC4 = 0;
    lbl_801A6AC8 = 0;
    lbl_801A6ACC = 0;
    lbl_801A6AE0 = 0;
    lbl_801A6AE4 = 1;
    lbl_801A6AE8 = 0;
    lbl_801A6AEC = 1;
    lbl_801A6AF0 = 2;
    entry_a = (struct fn_80020D58_entry_a *)lbl_8015D200;
    entry_b = lbl_8015E880;
    for (i = 0; i < 30; i++) {
        entry_a->unk_0 = 0;
        entry_b->unk_0 = 0;
        entry_a->unk_4 = 0;
        entry_b->unk_4 = 0;
        entry_a->unk_8 = 0;
        entry_b->unk_8 = 0;
        entry_a->unk_C = 0;
        entry_b->unk_C = 0;
        entry_a->unk_10 = 0;
        entry_b->unk_10 = 0;
        entry_a->unk_14 = 0;
        entry_b->unk_14 = 0;
        entry_a->unk_18 = 0;
        entry_b->unk_18 = 0;
        entry_a->unk_1C = 0;
        entry_b->unk_1C = 0;
        entry_a->unk_20 = 0;
        entry_b->unk_20 = 0;
        entry_a->unk_24 = 0;
        entry_b->unk_24 = 0;
        entry_a->unk_28 = 0;
        entry_b->unk_28 = 0;
        entry_a->unk_2C = 0;
        entry_b->unk_2C = 0;
        entry_a->unk_30 = 0;
        entry_b->unk_30 = 0;
        entry_a->unk_34 = 0;
        entry_b->unk_34 = 0;
        entry_a->unk_38 = 0;
        entry_b->unk_38 = 0;
        entry_a->unk_3C = 0;
        entry_b->unk_3C = 0;
        entry_a++;
        entry_b++;
    }
}

void fn_80020E3C(void) {
    lbl_801A6AC0 = 0;
    lbl_801A6AC4 = 0;
}

struct fn_80020E4C_Arg0 {
    u32 unk_0;
};

u32 fn_80020E4C(struct fn_80020E4C_Arg0 *arg0) {
    if (lbl_801A6AC0 != 0) {
    arg0->unk_0 = (u32)((u8 *)&lbl_8015D200 + (lbl_801A6AE0 * 1920));
    return (u32)arg0;
    }
    arg0->unk_0 = 0;
}


void fn_80020E80(u32 *out) {
    *out = (u32)((u8 *)lbl_8015E880 + lbl_801A6AE0 * 0x780 + 0x500);
}

struct fn_80020EA0_Arg0 {
    u32 unk_0;
};

extern u32 lbl_801A6AE4;

void fn_80020EA0(struct fn_80020EA0_Arg0 *arg0) {
    arg0->unk_0 = (u32)((u8 *)&lbl_8015D200 + (lbl_801A6AE4 * 1920));
}

struct fn_80020EBC_Arg0 {
    u32 unk_0;
};


void fn_80020EBC(struct fn_80020EBC_Arg0 *arg0) {
    arg0->unk_0 = (u32)(((u8 *)&lbl_8015D200 + (lbl_801A6AE4 * 1920)) + 640);
}

struct fn_80020EDC_Arg0 {
    u32 unk_0;
};


void fn_80020EDC(struct fn_80020EDC_Arg0 *arg0) {
    arg0->unk_0 = (u32)(((u8 *)&lbl_8015D200 + (lbl_801A6AE4 * 1920)) + 1280);
}

struct fn_80020EFC_Arg0 {
    u32 unk_0;
};


void fn_80020EFC(struct fn_80020EFC_Arg0 *arg0) {
    arg0->unk_0 = (u32)(((u8 *)&lbl_8015E880 + (lbl_801A6AE4 * 1920)) + 1280);
}

struct fn_80020F1C_Arg0 {
    u32 unk_0;
};

u32 fn_80020F1C(struct fn_80020F1C_Arg0 *arg0) {
    if (lbl_801A6AC4 != 0) {
    arg0->unk_0 = (u32)((u8 *)&lbl_8015E880 + (lbl_801A6AE0 * 1920));
    return (u32)arg0;
    }
    arg0->unk_0 = 0;
}

struct fn_80020F50_Arg0 {
    u32 unk_0;
};


void fn_80020F50(struct fn_80020F50_Arg0 *arg0) {
    arg0->unk_0 = (u32)((u8 *)&lbl_8015E880 + (lbl_801A6AE4 * 1920));
}

struct fn_80020F6C_Arg0 {
    u32 unk_0;
};

extern u32 lbl_801A6AE8;

void fn_80020F6C(struct fn_80020F6C_Arg0 *arg0) {
    arg0->unk_0 = (u32)((u8 *)&lbl_8015E880 + (lbl_801A6AE8 * 1920));
}

struct fn_80020F88_Arg0 {
    u32 unk_0;
};

extern u32 lbl_801A6AEC;

void fn_80020F88(struct fn_80020F88_Arg0 *arg0) {
    arg0->unk_0 = (u32)((u8 *)&lbl_8015E880 + (lbl_801A6AEC * 1920));
}

extern u8 *lbl_801A6AD0;
extern u8 *lbl_801A6AD4;
extern u8 *lbl_801A6AD4__fzgx_offset_4;
extern u32 lbl_801A6ADC;
extern u32 lbl_801A6AE4;
extern u32 lbl_801A6AE8;
extern u32 lbl_801A6AEC;
extern u32 lbl_801A6AF0;
extern u32 lbl_801A6B08;
extern void DCInvalidateRange(void *, u32);
extern void DCFlushRangeNoSync(void *, u32);

#pragma opt_propagation off
void fn_80020FA4(void) {
    u8 *base = (u8 *)&lbl_8015D200;
    u8 *v0;
    u8 *v1;
    u8 *a[4];
    u8 *b[3];
    u8 *c[3];

    v0 = ((base) + (lbl_801A6AE0 * 1920));
    v1 = base + lbl_801A6AE4 * 1920;
    lbl_801A6AD0 = v0;
    lbl_801A6AD4 = v1;
    lbl_801A6AD4__fzgx_offset_4 = v0 + 5760;
    lbl_801A6ADC = (u32)(v1 + 5760);

    if (lbl_801A6AC0 != 0) {
        if (lbl_801A6B08 == 2) {
            u8 *p = base + lbl_801A6AF0 * 1920;
            a[0] = p;
            a[1] = p + 0x280;
            a[2] = ((0x500) + p);
            a[3] = p + 0x1b80;
            DCInvalidateRange(((0)[a]), 0x780);
            DCInvalidateRange(a[3], 0x280);
            lbl_801A6AC0(a, lbl_801A6AC8);
            DCFlushRangeNoSync(a[0], 0x780);
            DCFlushRangeNoSync(a[3], 0x280);
        } else {
            u8 *p = base + lbl_801A6AF0 * 1920;
            b[0] = p;
            b[1] = p + 0x280;
            b[2] = p + 0x500;
            DCInvalidateRange(b[0], 0x780);
            lbl_801A6AC0(b, lbl_801A6AC8);
            DCFlushRangeNoSync(b[0], 0x780);
        }
    }
    if (lbl_801A6AC4 != 0 && lbl_801A6B08 != 2) {
        u8 *p = base + lbl_801A6AF0 * 1920;
        p += 5760;
        c[0] = p;
        c[1] = p + 0x280;
        c[2] = p + 0x500;
        DCInvalidateRange(c[0], 0x780);
        lbl_801A6AC4(c, lbl_801A6ACC);
        DCFlushRangeNoSync(((0)[c]), 0x780);
    }
    lbl_801A6AE0 += 1;
    lbl_801A6AE0 %= 3;
    lbl_801A6AE4 += 1;
    lbl_801A6AE4 %= 3;
    lbl_801A6AE8 += 1;
    lbl_801A6AE8 &= 1;
    lbl_801A6AEC += 1;
    lbl_801A6AEC &= 1;
    lbl_801A6AF0 += 1;
    lbl_801A6AF0 %= 3;
}
#pragma opt_propagation reset

void fn_800211E0(u32 arg0, u32 arg1) {
    lbl_801A6AC0 = (void (*)(void *, u32))arg0;
    lbl_801A6AC8 = arg1;
}

void fn_800211EC(u32 arg0, u32 arg1) {
    lbl_801A6AC4 = (void (*)(void *, u32))arg0;
    lbl_801A6ACC = arg1;
}

extern u32 lbl_801A6B00;

u32 fn_800211F8(void) {
    return lbl_801A6B00;
}

extern u32 lbl_801A6AF8;
extern u8 lbl_8015FF00[1536];
extern u32 lbl_801A6AFC;

u8 *fn_80021200(void) {
    u32 index = lbl_801A6AF8;
    u8 *base = lbl_8015FF00;
    u8 *old = base;

    lbl_801A6AF8 = index + 1;
    old += index * 0x300;
    lbl_801A6AF8 &= 1;
    lbl_801A6AFC = (u32)(base + lbl_801A6AF8 * 0x300);
    return old;
}
