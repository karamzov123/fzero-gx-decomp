#include "types.h"
#include "dolphin/hw_regs.h"
#include "dol/av_vertex_format.h"
typedef struct { u8 r, g, b, a; } AvDispCacheColor;
struct AvDispCache {
    u8 pad_0[0x670];
    s32 unk_670[16];
    s32 unk_6B0[16];
    u8 pad_6F0[0x4];
    s32 unk_6F4[4];
    AvDispCacheColor unk_704[4];
    u8 pad_714[0x40C];
    AvDispCacheColor unk_B20;
    u32 unk_B24;
};
extern u8 lbl_8019E250[];
extern u8 lbl_8019E308[];
extern struct AvDispCache *lbl_801A6D38;
extern void *memset(void *, int, u32);
extern void GXSetTevSwapModeTable();
extern void GXSetTevIndirect(s32, s32, s32, s32, s32, s32, s32, u8, u8, s32);
extern void fn_800794F0(void *, void *, int);
extern int memcmp(void *, void *, int);
extern void fn_80072A50(u32, u32, u32, u32, u32);

/* === dol/fn_800725DC.c === */

struct fn_800725DC_lbl_8019E250 {
    u8 pad_0[0x30];
    u32 unk_30;
};


/* WARNING: compiler-diff device, not original code: without opt_dead_assignments off fn_800725DC differs by 5 instructions (lis of the FIFO is hoisted above the early return in retail); GXWGFifo stores, fifo assigned first or at its declaration all give 5 */
#pragma opt_dead_assignments off
void fn_800725DC(u32 *arg0) {
    u32 value;
    u32 fifo;
    struct fn_800725DC_lbl_8019E250 *p;

    p = &(*(struct fn_800725DC_lbl_8019E250 *)lbl_8019E250);
    value = *arg0;
    fifo = GX_FIFO_BASE;
    if (p->unk_30 == value) {
        return;
    }
    p->unk_30 = value;
    *(volatile u8 *)fifo = 16; /* Hardware access must remain ordered. */
    *(volatile u32 *)fifo = 0x100c; /* Hardware access must remain ordered. */
    *(volatile u32 *)fifo = value; /* Hardware access must remain ordered. */
}
#pragma opt_dead_assignments reset

/* === dol/fn_80072614.c === */

struct fn_80072614_lbl_8019E250 {
    u8 pad_0[0x34];
    u32 unk_34;
};


/* WARNING: compiler-diff device, not original code: without opt_dead_assignments off fn_80072614 differs by 5 instructions (same as fn_800725DC) */
#pragma opt_dead_assignments off
void fn_80072614(u32 *arg0) {
    u32 value;
    u32 fifo;
    struct fn_80072614_lbl_8019E250 *p;

    p = &(*(struct fn_80072614_lbl_8019E250 *)lbl_8019E250);
    value = *arg0;
    fifo = GX_FIFO_BASE;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    if (p->unk_34 == value) {
        return;
    }
    p->unk_34 = value;
    *(volatile u8 *)fifo = 16; /* Hardware access must remain ordered. */
    *(volatile u32 *)fifo = 0x100a; /* Hardware access must remain ordered. */
    *(volatile u32 *)fifo = value; /* Hardware access must remain ordered. */
}
#pragma opt_dead_assignments reset


/* === dol/fn_8007264C.c === */

extern void GXSetVtxAttrFmt(u32, s32, s32, s32, u8);

void fn_8007264C(u32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    AvVertexAttrFormat *entry = ((AvVertexAttrFormat (*)[26])lbl_8019E308)[arg0];

    if (entry->attr != arg1 ||
        entry->componentCount != arg2 ||
        entry->componentType != arg3 ||
        entry->fractionalBits != arg4) {
        entry->attr = arg1;
        entry->componentCount = arg2;
        entry->componentType = arg3;
        entry->fractionalBits = arg4;
        GXSetVtxAttrFmt(arg0, arg1, arg2, arg3, arg4);
    }
}

/* === dol/fn_800726C0.c === */


/* --- dol/fn_800726C0.c --- */
void fn_800726C0(u32 arg0, AvVertexAttrFormat *arg1) {
    AvVertexAttrFormat *entry;
    s32 value0;
    s32 value1;
    s32 value2;
    u8 value3;

    entry = ((AvVertexAttrFormat (*)[26])lbl_8019E308)[arg0];
    while (arg1->attr < 0x1a) {
        value0 = arg1->attr;
        value3 = arg1->fractionalBits;
        value2 = arg1->componentType;
        value1 = arg1->componentCount;
        if (entry->attr != value0 ||
            entry->componentCount != value1 ||
            entry->componentType != value2 ||
            entry->fractionalBits != value3) {
            entry->attr = value0;
            entry->componentCount = value1;
            entry->componentType = value2;
            entry->fractionalBits = value3;
            GXSetVtxAttrFmt(arg0, value0, value1, value2, value3);
        }
        arg1++;
    }
}

/* --- dol/fn_80072778.c --- */

s32 fn_80072778(void) {
    memset(((u8 *)lbl_801A6D38), 255, 3232);
    fn_80072A50(0, 0, 1, 2, 3);
    fn_80072A50(1, 0, 1, 2, 0);
    fn_80072A50(2, 0, 1, 2, 1);
    fn_80072A50(3, 0, 1, 2, 2);
    return 1;
}

/* --- dol/fn_80072808.c --- */
void fn_80072808(void) {
    memset(((u8 *)lbl_801A6D38), 255, 3232);
    fn_80072A50(0, 0, 1, 2, 3);
    fn_80072A50(1, 0, 1, 2, 0);
}

/* === dol/fn_80072864.c === */

struct fn_80072864_lbl_801A6D38_T {
    u8 pad_0[0x18];
    u32 unk_18;
};

extern u32 fn_80034890(u32);

void fn_80072864(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if ((s32)arg0 != (s32)((struct fn_80072864_lbl_801A6D38_T *)lbl_801A6D38)->unk_18) {
    t0 = fn_80034890(v0);
    v0 = t0;
    v0 = (u32)((struct fn_80072864_lbl_801A6D38_T *)lbl_801A6D38);
    *(u32 *)((u8 *)v0 + 24) = arg0;
    }
}

/* === dol/fn_800728A8.c === */


/* --- dol/fn_800728A8.c --- */
extern void fn_80037B14(s32, s32, s32, s32);

void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (2 == arg0) {
        if (*(s32 *)(((u8 *)lbl_801A6D38) + 0x1c) == 2 &&
            *(s32 *)(((u8 *)lbl_801A6D38) + 0x28) == arg3) {
            return;
        }

        fn_80037B14(2, arg1, arg2, arg3);
        *(s32 *)(((u8 *)lbl_801A6D38) + 0x1c) = 2;
        *(s32 *)(((u8 *)lbl_801A6D38) + 0x20) = arg1;
        *(s32 *)(((u8 *)lbl_801A6D38) + 0x24) = arg2;
        *(s32 *)(((u8 *)lbl_801A6D38) + 0x28) = arg3;
        return;
    }

    if (*(s32 *)(((u8 *)lbl_801A6D38) + 0x1c) == arg0 &&
        *(s32 *)(((u8 *)lbl_801A6D38) + 0x20) == arg1 &&
        *(s32 *)(((u8 *)lbl_801A6D38) + 0x24) == arg2) {
        return;
    }

    fn_80037B14(arg0, arg1, arg2, arg3);
    *(s32 *)(((u8 *)lbl_801A6D38) + 0x1c) = arg0;
    *(s32 *)(((u8 *)lbl_801A6D38) + 0x20) = arg1;
    *(s32 *)(((u8 *)lbl_801A6D38) + 0x24) = arg2;
    *(s32 *)(((u8 *)lbl_801A6D38) + 0x28) = arg3;
}

/* --- dol/fn_800729B0.c --- */

void fn_800729B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *p;

    p = (u8 *)((u8 *)lbl_801A6D38) + arg0 * 16 + 0x2c;
    if (*(s32 *)(p) == arg1 &&
        *(s32 *)(p + 4) == arg2 &&
        *(s32 *)(p + 8) == arg3 &&
        *(s32 *)(p + 0xc) == arg4) {
        return;
    }

    GXSetTevSwapModeTable(arg0, arg1, arg2, arg3, arg4);
    *(s32 *)(p + 0) = arg1;
    *(s32 *)(p + 4) = arg2;
    *(s32 *)(p + 8) = arg3;
    *(s32 *)(p + 0xc) = arg4;
}

/* === dol/fn_80072A50.c === */


/* --- dol/fn_80072A50.c --- */

void fn_80072A50(u32 index, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u32 *entry = (u32 *)(((u8 *)lbl_801A6D38) + (index << 4) + 0x2c);

    GXSetTevSwapModeTable(index);
    entry[0] = arg1;
    entry[1] = arg2;
    entry[2] = arg3;
    entry[3] = arg4;
}

/* --- dol/fn_80072AB0.c --- */
extern void GXSetTevSwapMode(s32, s32, s32);

void fn_80072AB0(s32 arg0, s32 arg1, s32 arg2) {
    s32 *entry;

    entry = (s32 *)(((u8 *)lbl_801A6D38) + (arg0 << 3) + 0x6c);
    if (entry[0] != arg1 || entry[1] != arg2) {
        GXSetTevSwapMode(arg0, arg1, arg2);
        entry[0] = arg1;
        entry[1] = arg2;
    }
}

/* --- dol/fn_80072B28.c --- */
extern void fn_80037B68(u32);

void fn_80072B28(u32 arg0) {
    if (*(u8 *)(((u8 *)lbl_801A6D38) + 0xec) != 0xff &&
        *(u8 *)(((u8 *)lbl_801A6D38) + 0xec) == (u8)arg0) {
        return;
    }

    fn_80037B68(arg0);
    *(u8 *)(((u8 *)lbl_801A6D38) + 0xec) = arg0;
}

/* --- dol/fn_80072B7C.c --- */
extern void fn_80037B94(u32);

void fn_80072B7C(u32 arg0) {
    if (*(u8 *)(((u8 *)lbl_801A6D38) + 0xed) != 0xff &&
        *(u8 *)(((u8 *)lbl_801A6D38) + 0xed) == (u8)arg0) {
        return;
    }

    fn_80037B94(arg0);
    *(u8 *)(((u8 *)lbl_801A6D38) + 0xed) = (u8)arg0;
}

/* --- dol/fn_80072BD0.c --- */
extern void GXSetZCompLoc(u32);

void fn_80072BD0(u32 arg0) {
    u8 value;

    value = *(u8 *)(((u8 *)lbl_801A6D38) + 0xee);
    if (value == 0xff || value != (u8)arg0) {
        GXSetZCompLoc(arg0);
        *(u8 *)(((u8 *)lbl_801A6D38) + 0xee) = arg0;
    }
}

/* --- dol/fn_80072C24.c --- */
extern void fn_800370A0(s32, s32, s32, s32, s32);

void fn_80072C24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 *entry;

    entry = (u32 *)(((u8 *)lbl_801A6D38) + (arg0 << 4) + 0xf0);
    if ((s32)entry[0] == arg1 &&
        (s32)entry[1] == arg2 &&
        (s32)entry[2] == arg3 &&
        (s32)entry[3] == arg4) {
        return;
    }

    fn_800370A0(arg0, arg1, arg2, arg3, arg4);
    entry[0] = arg1;
    entry[1] = arg2;
    entry[2] = arg3;
    entry[3] = arg4;
}

/* --- dol/fn_80072CC4.c --- */
extern void fn_800370E4(s32, s32, s32, s32, s32);

void fn_80072CC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 *entry;

    entry = (u32 *)(((u8 *)lbl_801A6D38) + (arg0 << 4) + 0x1f0);
    if ((s32)entry[0] == arg1 &&
        (s32)entry[1] == arg2 &&
        (s32)entry[2] == arg3 &&
        (s32)entry[3] == arg4) {
        return;
    }

    fn_800370E4(arg0, arg1, arg2, arg3, arg4);
    entry[0] = arg1;
    entry[1] = arg2;
    entry[2] = arg3;
    entry[3] = arg4;
}

/* --- dol/fn_80072D64.c --- */
extern void fn_80037128(s32, s32, s32, s32, u8, s32);

void fn_80072D64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    u8 *entry;

    entry = (u8 *)((u8 *)lbl_801A6D38) + arg0 * 0x14 + 0x2F0;
    if (*(s32 *)(entry + 0x10) == arg5 &&
        *(s32 *)(entry + 0x8) == arg3 &&
        *(u8 *)(entry + 0xc) == arg4 &&
        *(s32 *)(entry + 0x0) == arg1 &&
        *(s32 *)(entry + 0x4) == arg2) {
        return;
    }

    fn_80037128(arg0, arg1, arg2, arg3, arg4, arg5);
    *(s32 *)(entry + 0x0) = arg1;
    *(s32 *)(entry + 0x4) = arg2;
    *(s32 *)(entry + 0x8) = arg3;
    *(u8 *)(entry + 0xc) = arg4;
    *(s32 *)(entry + 0x10) = arg5;
}

/* --- dol/fn_80072E20.c --- */
extern void fn_80037190(s32, s32, s32, s32, u8, s32);

void fn_80072E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    u8 *entry;

    entry = (u8 *)((u8 *)lbl_801A6D38) + arg0 * 0x14 + 0x430;
    if (*(s32 *)(entry + 0x10) == arg5 &&
        *(s32 *)(entry + 0x8) == arg3 &&
        *(u8 *)(entry + 0xc) == arg4 &&
        *(s32 *)(entry + 0x0) == arg1 &&
        *(s32 *)(entry + 0x4) == arg2) {
        return;
    }

    fn_80037190(arg0, arg1, arg2, arg3, arg4, arg5);
    *(s32 *)(entry + 0x0) = arg1;
    *(s32 *)(entry + 0x4) = arg2;
    *(s32 *)(entry + 0x8) = arg3;
    *(u8 *)(entry + 0xc) = arg4;
    *(s32 *)(entry + 0x10) = arg5;
}

/* --- dol/fn_80072EDC.c --- */

static inline void set_table_a(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 *entry;
    entry = (u32 *)(((u8 *)lbl_801A6D38) + (arg0 << 4) + 0xf0);
    if ((s32)entry[0] == arg1 &&
        (s32)entry[1] == arg2 &&
        (s32)entry[2] == arg3 &&
        (s32)entry[3] == arg4) {
        return;
    }
    fn_800370A0(arg0, arg1, arg2, arg3, arg4);
    entry[0] = arg1;
    entry[1] = arg2;
    entry[2] = arg3;
    entry[3] = arg4;
}

static inline void set_table_b(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 *entry;
    entry = (u32 *)(((u8 *)lbl_801A6D38) + (arg0 << 4) + 0x1f0);
    if ((s32)entry[0] == arg1 &&
        (s32)entry[1] == arg2 &&
        (s32)entry[2] == arg3 &&
        (s32)entry[3] == arg4) {
        return;
    }
    fn_800370E4(arg0, arg1, arg2, arg3, arg4);
    entry[0] = arg1;
    entry[1] = arg2;
    entry[2] = arg3;
    entry[3] = arg4;
}

static inline void set_table_c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    u8 *entry;
    entry = (u8 *)((u8 *)lbl_801A6D38) + arg0 * 0x14 + 0x2f0;
    if (*(s32 *)(entry + 0x10) == arg5 &&
        *(s32 *)(entry + 0x8) == arg3 &&
        *(u8 *)(entry + 0xc) == arg4 &&
        *(s32 *)(entry + 0x0) == arg1 &&
        *(s32 *)(entry + 0x4) == arg2) {
        return;
    }
    fn_80037128(arg0, arg1, arg2, arg3, arg4, arg5);
    *(s32 *)(entry + 0x0) = arg1;
    *(s32 *)(entry + 0x4) = arg2;
    *(s32 *)(entry + 0x8) = arg3;
    *(u8 *)(entry + 0xc) = arg4;
    *(s32 *)(entry + 0x10) = arg5;
}

static inline void set_table_d(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    u8 *entry;
    entry = (u8 *)((u8 *)lbl_801A6D38) + arg0 * 0x14 + 0x430;
    if (*(s32 *)(entry + 0x10) == arg5 &&
        *(s32 *)(entry + 0x8) == arg3 &&
        *(u8 *)(entry + 0xc) == arg4 &&
        *(s32 *)(entry + 0x0) == arg1 &&
        *(s32 *)(entry + 0x4) == arg2) {
        return;
    }
    fn_80037190(arg0, arg1, arg2, arg3, arg4, arg5);
    *(s32 *)(entry + 0x0) = arg1;
    *(s32 *)(entry + 0x4) = arg2;
    *(s32 *)(entry + 0x8) = arg3;
    *(u8 *)(entry + 0xc) = arg4;
    *(s32 *)(entry + 0x10) = arg5;
}

void fn_80072EDC(s32 arg0, s32 arg1) {
    s32 v0;
    s32 v1;
    if (arg0 == 0) { v0=10; v1=5; } else { v0=0; v1=0; }
    switch (arg1) {
case 1:
set_table_a(arg0, v0, 8, 9, 15);
set_table_b(arg0, 7, 7, 7, v1);
break;
case 0:
set_table_a(arg0, 15, 8, v0, 15);
set_table_b(arg0, 7, 4, v1, 7);
break;
case 3:
set_table_a(arg0, 15, 15, 15, 8);
set_table_b(arg0, 7, 7, 7, 4);
break;
case 4:
set_table_a(arg0, 15, 15, 15, v0);
set_table_b(arg0, 7, 7, 7, v1);
break;
case 2:
set_table_a(arg0, v0, 15, 8, 8);
set_table_b(arg0, 7, 4, v1, 7);
break;
}
set_table_c(arg0, 0, 0, 0, 1, 0);
set_table_d(arg0, 0, 0, 0, 1, 0);
}

/* --- dol/fn_800734A8.c --- */
extern void GXSetTevOrder(s32, s32, s32, s32);

void fn_800734A8(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p;
    u8 *q;

    p = (u8 *)((u8 *)lbl_801A6D38) + (arg0 << 4) + 0x570;
    if (arg2 >= 8) {
        if (*(s32 *)(p) != arg1 || *(s32 *)(p + 4) != 0xff ||
            *(s32 *)(p + 8) != arg3) {
            GXSetTevOrder(arg0, arg1, arg2, arg3);
            *(s32 *)(p + 0) = arg1;
            *(s32 *)(p + 4) = 0xff;
            *(s32 *)(p + 8) = arg3;
            *(u16 *)(p + 0xc) = 0;
            *(u16 *)(p + 0xe) = 0;
        }
    } else {
        q = (u8 *)((u8 *)lbl_801A6D38) + arg2 * 36 + 0x720;
        if (*(s32 *)(p) != arg1 || *(s32 *)(p + 4) != arg2 ||
            *(s32 *)(p + 8) != arg3 ||
            *(u16 *)(p + 0xc) != *(u16 *)(q + 0x20) ||
            *(u16 *)(p + 0xe) != *(u16 *)(q + 0x22)) {
            GXSetTevOrder(arg0, arg1, arg2, arg3);
            *(s32 *)(p + 0) = arg1;
            *(s32 *)(p + 4) = arg2;
            *(s32 *)(p + 8) = arg3;
            *(u16 *)(p + 0xc) = *(u16 *)(q + 0x20);
            *(u16 *)(p + 0xe) = *(u16 *)(q + 0x22);
        }
    }
}

/* === dol/fn_800735C8.c === */

struct fn_800735C8_entry {
    u8 pad_0[0x670];
    s32 unk_670[1];
};

extern void GXSetTevKColorSel(s32, s32);

void fn_800735C8(s32 index, s32 value) {
    if (lbl_801A6D38->unk_670[index] != value) {
        GXSetTevKColorSel(index, value);
        lbl_801A6D38->unk_670[index] = value;
    }
}

/* === dol/fn_80073620.c === */

struct fn_80073620_entry {
    u8 pad_0[0x6B0];
    s32 unk_6B0[1];
};

extern void GXSetTevKAlphaSel(s32, s32);

void fn_80073620(s32 index, s32 value) {
    if (lbl_801A6D38->unk_6B0[index] != value) {
        GXSetTevKAlphaSel(index, value);
        lbl_801A6D38->unk_6B0[index] = value;
    }
}

/* === dol/fn_80073678.c === */

struct fn_80073678_lbl_801A6D38_T {
    u8 pad_0[0x6F0];
    u8 unk_6F0;
};

extern u32 GXSetNumTevStages(u32);

void fn_80073678(u32 arg0) {
    u32 v0;
    u8 v1;
    u32 v2;
    u32 t0;
    v0 = (arg0 & 0xFF);
    v1 = ((struct fn_80073678_lbl_801A6D38_T *)lbl_801A6D38)->unk_6F0;
    v2 = arg0;
    if (v1 != v0) {
    t0 = GXSetNumTevStages(v2);
    v2 = t0;
    v2 = (u32)((struct fn_80073678_lbl_801A6D38_T *)lbl_801A6D38);
    *(u8 *)((u8 *)v2 + 1776) = arg0;
    }
}

/* === dol/fn_800736C0.c === */

typedef struct {
    u8 r, g, b, a;
} fn_800736C0_Color;

struct fn_800736C0_entry {
    u8 pad_0[0x6F4];
    s32 unk_6F4[4];
    fn_800736C0_Color unk_704[4];
};

extern void fn_800372E0(s32, AvDispCacheColor);

/* Set TEV constant color INDEX through the per-slot cache, skipping redundant GX calls. */
void fn_800736C0(s32 index, AvDispCacheColor color) {
    if (lbl_801A6D38->unk_704[index].r != color.r || lbl_801A6D38->unk_704[index].g != color.g ||
        lbl_801A6D38->unk_704[index].b != color.b || lbl_801A6D38->unk_704[index].a != color.a ||
        lbl_801A6D38->unk_6F4[index] != 0) {
        fn_800372E0(index, color);
        lbl_801A6D38->unk_6F4[index] = 0;
        lbl_801A6D38->unk_704[index] = color;
    }
}

/* === dol/fn_80073778.c === */


/* --- dol/fn_80073778.c --- */
typedef struct {
    u8 pad_00[0x20];
    u16 width;
    u16 height;
} TexEntry;

extern u16 GXGetTexObjWidth(void *obj);
extern u16 GXGetTexObjHeight(void *obj);
extern void GXLoadTexObj(void *obj, s32 index);

void fn_80073778(void *obj, s32 index) {
    TexEntry *entry;

    entry = (TexEntry *)(((u8 *)lbl_801A6D38) + index * 0x24 + 0x720);
    entry->width = GXGetTexObjWidth(obj);
    entry->height = GXGetTexObjHeight(obj);
    GXLoadTexObj(obj, index);
}

/* --- dol/fn_800737E4.c --- */
struct fn_800737E4_Arg0 {
    f32 unk_0;
    u8 pad_4[0x4];
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x4];
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x8];
    f32 unk_28;
    f32 unk_2C;
};

struct fn_800737E4_Local {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
};

extern f64 lbl_801A7468;
extern void fn_80072270(void *);

void fn_800737E4(struct fn_800737E4_Arg0 *arg0, s32 arg1) {
    struct fn_800737E4_Local local;

    local.unk_0 = arg1;
    switch (arg1) {
    case 0:
        local.unk_4 = arg0->unk_0;
        local.unk_8 = arg0->unk_8;
        local.unk_C = arg0->unk_14;
        local.unk_10 = arg0->unk_18;
        local.unk_14 = arg0->unk_28;
        local.unk_18 = arg0->unk_2C;
        break;
    default:
        local.unk_4 = arg0->unk_0;
        local.unk_8 = arg0->unk_C;
        local.unk_C = arg0->unk_14;
        local.unk_10 = arg0->unk_1C;
        local.unk_14 = arg0->unk_28;
        local.unk_18 = arg0->unk_2C;
        break;
    }
    fn_80072270(&local);
}

/* === dol/fn_80073898.c === */

struct fn_80073898_lbl_801A6D38_T {
    u8 pad_0[0x840];
    u8 unk_840;
};

extern u32 GXSetNumIndStages(u32);

void fn_80073898(u32 arg0) {
    u32 v0;
    u8 v1;
    u32 v2;
    u32 t0;
    v0 = (arg0 & 0xFF);
    v1 = ((struct fn_80073898_lbl_801A6D38_T *)lbl_801A6D38)->unk_840;
    v2 = arg0;
    if (v1 != v0) {
    t0 = GXSetNumIndStages(v2);
    v2 = t0;
    v2 = (u32)((struct fn_80073898_lbl_801A6D38_T *)lbl_801A6D38);
    *(u8 *)((u8 *)v2 + 2112) = arg0;
    }
}

/* === dol/fn_800738E0.c === */


/* --- dol/fn_800738E0.c --- */
typedef struct {
    s32 unk_00;
    s32 unk_04;
    u16 unk_08;
    u16 unk_0A;
} Entry_u13;

typedef struct {
    u8 pad_00[0x20];
    u16 unk_20;
    u16 unk_22;
} Sub;

extern void GXSetIndTexOrder(s32, s32, s32);

void fn_800738E0(s32 arg0, s32 arg1, s32 arg2) {
    Entry_u13 *entry = (Entry_u13 *)(((u8 *)lbl_801A6D38) + arg0 * 12 + 0x844);

    if (arg2 >= 8) {
        if (entry->unk_00 != arg0 || entry->unk_04 != arg2) {
            GXSetIndTexOrder(arg0, arg1, arg2);
            entry->unk_00 = arg1;
            entry->unk_04 = arg2;
            entry->unk_08 = 0;
            entry->unk_0A = 0;
        }
    } else {
        Sub *sub = (Sub *)(((u8 *)lbl_801A6D38) + arg2 * 36 + 0x720);

        if (entry->unk_00 != arg0 || entry->unk_04 != arg2 ||
            entry->unk_08 != sub->unk_20 || entry->unk_0A != sub->unk_22) {
            GXSetIndTexOrder(arg0, arg1, arg2);
            entry->unk_00 = arg1;
            entry->unk_04 = arg2;
            entry->unk_08 = sub->unk_20;
            entry->unk_0A = sub->unk_22;
        }
    }
}

/* --- dol/fn_800739E0.c --- */
typedef struct {
    s32 unk_00;
    s32 unk_04;
} Entry_u1;

extern void GXSetIndTexCoordScale(s32, s32, s32);

void fn_800739E0(s32 index, s32 arg1, s32 arg2) {
    Entry_u1 *entry;

    entry = (Entry_u1 *)(((u8 *)lbl_801A6D38) + (index << 3) + 0x874);
    if (entry->unk_00 != arg1 || entry->unk_04 != arg2) {
        GXSetIndTexCoordScale(index, arg1, arg2);
        entry->unk_00 = arg1;
        entry->unk_04 = arg2;
    }
}

/* --- dol/fn_80073A58.c --- */
typedef struct Entry_u2 {
    u8 unk_00[0x18];
    s8 unk_18;
    u8 unk_19[0x03];
} Entry_u2;

extern void fn_80036AC4(int index, void *arg, s8 value);

void fn_80073A58(int index, void *arg, s8 value) {
    Entry_u2 *entry;

    if (index == 0) {
        return;
    }

    if (index <= 3) {
        entry = (Entry_u2 *)(((u8 *)lbl_801A6D38) + (index - 1) * 0x1c + 0x894);
    } else if (index <= 7) {
        entry = (Entry_u2 *)(((u8 *)lbl_801A6D38) + (index - 5) * 0x1c + 0x894);
    } else if (index <= 11) {
        entry = (Entry_u2 *)(((u8 *)lbl_801A6D38) + (index - 9) * 0x1c + 0x894);
    }

    if (entry->unk_18 == value) {
        if (memcmp(entry, arg, 0x18) == 0) {
            return;
        }
    }

    fn_80036AC4(index, arg, value);
    fn_800794F0(entry, arg, 0x18);
    entry->unk_18 = value;
}

/* --- dol/fn_80073B50.c --- */
typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18;
    u8 unk_19;
    u8 _pad_1A[2];
    s32 unk_1C;
} Entry_u3;


void fn_80073B50(u32 index, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u8 arg7, u8 arg8, s32 arg9) {
    Entry_u3 *entry;

    entry = (Entry_u3 *)(((u8 *)lbl_801A6D38) + (index << 5) + 0x8E8);
    if (entry->unk_00 != arg1 ||
        entry->unk_04 != arg2 ||
        entry->unk_08 != arg3 ||
        entry->unk_0C != arg4 ||
        entry->unk_10 != arg5 ||
        entry->unk_14 != arg6 ||
        entry->unk_18 != arg7 ||
        entry->unk_19 != arg8 ||
        entry->unk_1C != arg9) {
        GXSetTevIndirect(index, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
        entry->unk_00 = arg1;
        entry->unk_04 = arg2;
        entry->unk_08 = arg3;
        entry->unk_0C = arg4;
        entry->unk_10 = arg5;
        entry->unk_14 = arg6;
        entry->unk_18 = arg7;
        entry->unk_19 = arg8;
        entry->unk_1C = arg9;
    }
}

/* --- dol/fn_80073C6C.c --- */
typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18;
    u8 unk_19;
    u8 _pad_1A[2];
    s32 unk_1C;
} Entry_u4;


void fn_80073C6C(s32 index) {

{
    Entry_u4 *entry;
    entry = (Entry_u4 *)(((u8 *)lbl_801A6D38) + (index << 5) + 0x8E8);
    if (entry->unk_00 != 0 ||
        entry->unk_04 != 0 ||
        entry->unk_08 != 0 ||
        entry->unk_0C != 0 ||
        entry->unk_10 != 0 ||
        entry->unk_14 != 0 ||
        entry->unk_18 != 0 ||
        entry->unk_19 != 0 ||
        entry->unk_1C != 0) {
        GXSetTevIndirect(index, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        entry->unk_00 = 0;
        entry->unk_04 = 0;
        entry->unk_08 = 0;
        entry->unk_0C = 0;
        entry->unk_10 = 0;
        entry->unk_14 = 0;
        entry->unk_18 = 0;
        entry->unk_19 = 0;
        entry->unk_1C = 0;
}
    }
}

/* === dol/fn_80073D60.c === */

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18;
    u8 unk_19;
    u8 _pad_1A[2];
    s32 unk_1C;
} Entry_u14;


/* WARNING: compiler-diff device, not original code: without opt_propagation off fn_80073D60 differs by 36 instructions; direct v0/v1 assignments give 19 (27 with v0 declared first), ternaries 42 */
#pragma opt_propagation off
void fn_80073D60(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Entry_u14 *entry;
    s32 v1;
    s32 v0;
    s32 t;

    t = 0;
    if (arg3 & 0xFF) {
        t = 6;
    }
    v0 = t;
    t = 0;
    if (arg2 & 0xFF) {
        t = 7;
    }
    v1 = t;

    entry = (Entry_u14 *)(((u8 *)lbl_801A6D38) + (arg0 << 5) + 0x8E8);
    if (entry->unk_00 != arg1 ||
        entry->unk_04 != 0 ||
        entry->unk_08 != v1 ||
        entry->unk_0C != arg4 ||
        entry->unk_10 != v0 ||
        entry->unk_14 != v0 ||
        entry->unk_18 != 0 ||
        entry->unk_19 != 0 ||
        entry->unk_1C != 0) {
        GXSetTevIndirect(arg0, arg1, 0, v1, arg4, v0, v0, 0, 0, 0);
        entry->unk_00 = arg1;
        entry->unk_04 = 0;
        entry->unk_08 = v1;
        entry->unk_0C = arg4;
        entry->unk_10 = v0;
        entry->unk_14 = v0;
        entry->unk_18 = 0;
        entry->unk_19 = 0;
        entry->unk_1C = 0;
    }
}
#pragma opt_propagation reset


/* === dol/fn_80073E8C.c === */

typedef struct Entry_u15 {
    u8 unk_00[0x18];
    s8 unk_18;
    u8 unk_19[3];
} Entry_u15;

typedef struct TevEntry {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18;
    u8 unk_19;
    u8 pad_1A[2];
    s32 unk_1C;
} TevEntry;

typedef struct Matrix {
    f32 a, b, c, d, e, f;
} Matrix;

extern const f32 lbl_801A7474;
extern const f32 lbl_801A7470;

/* WARNING: compiler-diff device, not original code: without opt_common_subs off fn_80073E8C no longer matches (MWCC renumbers its literals; the function differs) */
#pragma opt_common_subs off
void fn_80073E8C(s32 arg0, s32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    Entry_u15 *entry;
    u32 v1;
    Matrix matrix;
    TevEntry *tev;
    u32 v0;
    s32 wrap2;

    v0 = arg2 & 0xFFFF;
    switch (v0) {
    case 256: v1 = 1; break;
    case 128: v1 = 2; break;
    case 64: v1 = 3; break;
    case 32: v1 = 4; break;
    case 16: v1 = 5; break;
    default: v1 = 0; break;
    }
    switch ((arg3 & 0xFFFF)) {
    case 256: wrap2 = 1; break;
    case 128: wrap2 = 2; break;
    case 64: wrap2 = 3; break;
    case 32: wrap2 = 4; break;
    case 16: wrap2 = 5; break;
    default: wrap2 = 0; break;
    }
    matrix.a = (arg4 & 0xFFFF) * lbl_801A7470;
    matrix.b = lbl_801A7474;
    matrix.c = lbl_801A7474;
    matrix.d = lbl_801A7474;
    matrix.e = (arg5 & 0xFFFF) * lbl_801A7470;
    matrix.f = lbl_801A7474;
    if (arg7 != 0) {
        if (arg7 <= 3) {
            entry = (Entry_u15 *)(((u8 *)lbl_801A6D38) + (arg7 - 1) * 0x1C + 0x894);
        } else if (arg7 <= 7) {
            entry = (Entry_u15 *)(((u8 *)lbl_801A6D38) + (arg7 - 5) * 0x1C + 0x894);
        } else if (arg7 <= 11) {
            entry = (Entry_u15 *)(((u8 *)lbl_801A6D38) + (arg7 - 9) * 0x1C + 0x894);
        }
        if (entry->unk_18 != 10 || memcmp(entry, &matrix, 0x18) != 0) {
            fn_80036AC4(arg7, &matrix, 10);
            fn_800794F0(entry, &matrix, 0x18);
            entry->unk_18 = 10;
        }
    }
    tev = (TevEntry *)(((u8 *)lbl_801A6D38) + (arg0 << 5) + 0x8E8);
    if (tev->unk_00 != arg1 ||
        tev->unk_04 != arg6 ||
        tev->unk_08 != arg8 ||
        tev->unk_0C != arg7 ||
        tev->unk_10 != (s32)v1 ||
        tev->unk_14 != wrap2 ||
        tev->unk_18 != 0 ||
        tev->unk_19 != 1 ||
        tev->unk_1C != arg9) {
        GXSetTevIndirect(arg0, arg1, arg6, arg8, arg7, v1, wrap2, 0, 1, arg9);
        tev->unk_00 = arg1;
        tev->unk_04 = arg6;
        tev->unk_08 = arg8;
        tev->unk_0C = arg7;
        tev->unk_10 = v1;
        tev->unk_14 = wrap2;
        tev->unk_18 = 0;
        tev->unk_19 = 1;
        tev->unk_1C = arg9;
    }
}
#pragma opt_common_subs reset


/* === dol/fn_80074188.c === */

struct fn_80074188_lbl_801A6D38_T {
    u8 pad_0[0xAE8];
    u32 unk_AE8;
    u32 unk_AEC;
    u32 unk_AF0;
    u32 unk_AF4;
};

extern u32 GXSetScissor(u32, u32, u32, u32);

u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (((struct fn_80074188_lbl_801A6D38_T *)lbl_801A6D38)->unk_AE8 != arg0 || ((struct fn_80074188_lbl_801A6D38_T *)lbl_801A6D38)->unk_AEC != arg1 || ((struct fn_80074188_lbl_801A6D38_T *)lbl_801A6D38)->unk_AF0 != arg2 || ((struct fn_80074188_lbl_801A6D38_T *)lbl_801A6D38)->unk_AF4 != arg3) {
    v0 = arg0;
    t0 = GXSetScissor(v0, arg1, arg2, arg3);
    v0 = t0;
    v0 = (u32)((struct fn_80074188_lbl_801A6D38_T *)lbl_801A6D38);
    *(u32 *)((u8 *)v0 + 2792) = arg0;
    v0 = (u32)((struct fn_80074188_lbl_801A6D38_T *)lbl_801A6D38);
    *(u32 *)((u8 *)v0 + 2796) = arg1;
    v0 = (u32)((struct fn_80074188_lbl_801A6D38_T *)lbl_801A6D38);
    *(u32 *)((u8 *)v0 + 2800) = arg2;
    v0 = (u32)((struct fn_80074188_lbl_801A6D38_T *)lbl_801A6D38);
    *(u32 *)((u8 *)v0 + 2804) = arg3;
    }
    return v0;
}

/* === dol/fn_8007423C.c === */

struct fn_8007423C_lbl_801A6D38_T {
    u8 pad_0[0xAFC];
    u16 unk_AFC;
    u16 unk_AFE;
    u16 unk_B00;
    u16 unk_B02;
};

extern u32 GXSetDispCopySrc(u32, u32, u32, u32);

void fn_8007423C(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 v1;
    u32 t0;
    v0 = (arg0 & 0xFFFF);
    v1 = ((struct fn_8007423C_lbl_801A6D38_T *)lbl_801A6D38)->unk_B02;
    if (((struct fn_8007423C_lbl_801A6D38_T *)lbl_801A6D38)->unk_AFC != v0 || ((struct fn_8007423C_lbl_801A6D38_T *)lbl_801A6D38)->unk_AFE != (arg1 & 0xFFFF) || ((struct fn_8007423C_lbl_801A6D38_T *)lbl_801A6D38)->unk_B00 != (arg2 & 0xFFFF) || ((struct fn_8007423C_lbl_801A6D38_T *)lbl_801A6D38)->unk_B02 != (arg3 & 0xFFFF)) {
    v1 = arg0;
    t0 = GXSetDispCopySrc(v1, arg1, arg2, arg3);
    v1 = t0;
    v1 = (u32)((struct fn_8007423C_lbl_801A6D38_T *)lbl_801A6D38);
    *(u16 *)((u8 *)v1 + 2812) = arg0;
    *(u16 *)((u8 *)((u32)((struct fn_8007423C_lbl_801A6D38_T *)lbl_801A6D38)) + 2814) = arg1;
    *(u16 *)((u8 *)((u32)((struct fn_8007423C_lbl_801A6D38_T *)lbl_801A6D38)) + 2816) = arg2;
    *(u16 *)((u8 *)((u32)((struct fn_8007423C_lbl_801A6D38_T *)lbl_801A6D38)) + 2818) = arg3;
    }
}

/* === dol/fn_80074300.c === */

typedef struct {
    u8 pad[0xb08];
    u16 unk_b08;
    u16 unk_b0a;
    u16 unk_b0c;
    u16 unk_b0e;
} Fn80074300State;

extern void GXSetTexCopySrc(u16, u16, u16, u16);

void fn_80074300(u16 arg0, u16 arg1, u16 arg2, u16 arg3, u32 lab_unused0) {
    if (((Fn80074300State *)((u8 *)lbl_801A6D38))->unk_b08 != arg0 ||
        ((Fn80074300State *)((u8 *)lbl_801A6D38))->unk_b0a != arg1 ||
        ((Fn80074300State *)((u8 *)lbl_801A6D38))->unk_b0c != arg2 ||
        ((Fn80074300State *)((u8 *)lbl_801A6D38))->unk_b0e != arg3) {
        GXSetTexCopySrc(arg0, arg1, arg2, arg3);
        ((Fn80074300State *)((u8 *)lbl_801A6D38))->unk_b08 = arg0;
        ((Fn80074300State *)((u8 *)lbl_801A6D38))->unk_b0a = arg1;
        ((Fn80074300State *)((u8 *)lbl_801A6D38))->unk_b0c = arg2;
        ((Fn80074300State *)((u8 *)lbl_801A6D38))->unk_b0e = arg3;
    }
}

/* === dol/fn_800743C4.c === */

typedef struct {
    u8 pad[0xB04];
    u16 unk_B04;
    u16 unk_B06;
} State_u19;

extern void fn_80034B7C(u32, u32);

void fn_800743C4(s32 a, u32 b) {
    if (((State_u19 *)lbl_801A6D38)->unk_B04 != (u16)a ||
        ((State_u19 *)lbl_801A6D38)->unk_B06 != (u16)b) {
        fn_80034B7C(a, b);
        ((State_u19 *)lbl_801A6D38)->unk_B04 = a;
        ((State_u19 *)lbl_801A6D38)->unk_B06 = b;
    }
}

/* === dol/fn_80074438.c === */

struct fn_80074438_lbl_801A6D38_T {
    u8 pad_0[0xB10];
    u16 unk_B10;
    u16 unk_B12;
    u32 unk_B14;
    u8 unk_B18;
};

extern u32 fn_80034BB8(u32, u32, u32, u32);

void fn_80074438(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 v1;
    u32 t0;
    v0 = (arg0 & 0xFFFF);
    v1 = ((struct fn_80074438_lbl_801A6D38_T *)lbl_801A6D38)->unk_B18;
    if (((struct fn_80074438_lbl_801A6D38_T *)lbl_801A6D38)->unk_B10 != v0 || ((struct fn_80074438_lbl_801A6D38_T *)lbl_801A6D38)->unk_B12 != (arg1 & 0xFFFF) || (s32)((struct fn_80074438_lbl_801A6D38_T *)lbl_801A6D38)->unk_B14 != (s32)arg2 || ((struct fn_80074438_lbl_801A6D38_T *)lbl_801A6D38)->unk_B18 != (arg3 & 0xFF)) {
    v1 = arg0;
    t0 = fn_80034BB8(v1, arg1, arg2, arg3);
    v1 = t0;
    v1 = (u32)((struct fn_80074438_lbl_801A6D38_T *)lbl_801A6D38);
    *(u16 *)((u8 *)v1 + 2832) = arg0;
    *(u16 *)((u8 *)((u32)((struct fn_80074438_lbl_801A6D38_T *)lbl_801A6D38)) + 2834) = arg1;
    *(u32 *)((u8 *)((u32)((struct fn_80074438_lbl_801A6D38_T *)lbl_801A6D38)) + 2836) = arg2;
    *(u8 *)((u8 *)((u32)((struct fn_80074438_lbl_801A6D38_T *)lbl_801A6D38)) + 2840) = arg3;
    }
}

/* === dol/fn_800744F8.c === */
typedef struct Sig_GXSetCopyClear__GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Sig_GXSetCopyClear_GXColor;
struct fn_800744F8_Arg0 {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
};
struct fn_800744F8_lbl_801A6D38_T {
    u8 pad_0[0xB20];
    Sig_GXSetCopyClear_GXColor unk_B20;
    u32 unk_B24;
};
extern void GXSetCopyClear(Sig_GXSetCopyClear_GXColor, u32);
void fn_800744F8(AvDispCacheColor arg0, u32 arg1) {
    u8 r = arg0.r;
    if (lbl_801A6D38->unk_B20.r != r ||
        lbl_801A6D38->unk_B20.g != arg0.g ||
        lbl_801A6D38->unk_B20.b != arg0.b ||
        lbl_801A6D38->unk_B20.a != arg0.a ||
        lbl_801A6D38->unk_B24 != arg1) {
        GXSetCopyClear(*(Sig_GXSetCopyClear_GXColor *)&arg0, arg1);
        lbl_801A6D38->unk_B20 = arg0;
        lbl_801A6D38->unk_B24 = arg1;
    }
}

/* === dol/fn_800745A4.c === */

struct fn_800745A4_lbl_801A6D38_T {
    s32 unk_00;
    s32 unk_04;
    u32 unk_08;
    u8 unk_0C;
    u8 pad_0D[3];
    u32 unk_10;
};

extern void GXSetTexCoordGen2(u32, u32, u32, u32, u32, u32);

void fn_800745A4(u32 arg0, s32 arg1, s32 arg2, u32 arg3, u32 arg4, u32 arg5) {
    struct fn_800745A4_lbl_801A6D38_T *p;
    p = (struct fn_800745A4_lbl_801A6D38_T *)((u8 *)((struct fn_800745A4_lbl_801A6D38_T *)lbl_801A6D38) + (arg0 << 5) + 0xB28);
    if (p->unk_00 != arg1 || p->unk_04 != arg2 || p->unk_08 != arg3 ||
        p->unk_0C != (arg4 & 0xFF) || p->unk_10 != arg5) {
        GXSetTexCoordGen2(arg0, arg1, arg2, arg3, arg4, arg5);
        p->unk_00 = arg1;
        p->unk_04 = arg2;
        p->unk_08 = arg3;
        p->unk_0C = arg4;
        p->unk_10 = arg5;
    }
}

/* === dol/fn_80074660.c === */

struct fn_80074660_lbl_801A6D38_T {
    u8 pad_0[0xC28];
    u8 unk_C28;
};

extern u32 GXSetNumTexGens(u32);

void fn_80074660(u32 arg0) {
    u32 v0;
    u8 v1;
    u32 v2;
    u32 t0;
    v0 = (arg0 & 0xFF);
    v1 = ((struct fn_80074660_lbl_801A6D38_T *)lbl_801A6D38)->unk_C28;
    v2 = arg0;
    if (v1 != v0) {
    t0 = GXSetNumTexGens(v2);
    v2 = t0;
    v2 = (u32)((struct fn_80074660_lbl_801A6D38_T *)lbl_801A6D38);
    *(u8 *)((u8 *)v2 + 3112) = arg0;
    }
}

/* === dol/fn_800746A8.c === */

typedef struct GlobalState_u24 {
    u8 unk_00[9];
    u8 unk_09;
    u8 unk_0A[2];
    s32 unk_0C;
} GlobalState_u24;

extern void GXSetLineWidth(u8, s32);

void fn_800746A8(u8 value, s32 arg, u32 lab_unused0) {
    if (((GlobalState_u24 *)lbl_801A6D38)->unk_09 != value || ((GlobalState_u24 *)lbl_801A6D38)->unk_0C != arg) {
        GXSetLineWidth(value, arg);
        ((GlobalState_u24 *)lbl_801A6D38)->unk_09 = value;
        ((GlobalState_u24 *)lbl_801A6D38)->unk_0C = arg;
    }
}

/* === dol/fn_80074718.c === */

typedef struct GlobalState_u25 {
    u8 unk_00[0x10];
    u8 unk_10;
    u8 unk_11[3];
    s32 unk_14;
} GlobalState_u25;

extern void GXSetPointSize(u8, s32);

void fn_80074718(u8 value, s32 arg) {
    if (((GlobalState_u25 *)lbl_801A6D38)->unk_10 != value || ((GlobalState_u25 *)lbl_801A6D38)->unk_14 != arg) {
        GXSetPointSize(value, arg);
        ((GlobalState_u25 *)lbl_801A6D38)->unk_10 = value;
        ((GlobalState_u25 *)lbl_801A6D38)->unk_14 = arg;
    }
}

/* === dol/fn_80074788.c === */

struct fn_80074788_lbl_801A6D38_T {
    u8 pad_0[0xC2E];
    u8 unk_C2E;
};

extern u32 fn_8003591C(u32);

void fn_80074788(u32 arg0) {
    u32 v0;
    u8 v1;
    u32 v2;
    u32 t0;
    v0 = (arg0 & 0xFF);
    v1 = ((struct fn_80074788_lbl_801A6D38_T *)lbl_801A6D38)->unk_C2E;
    v2 = arg0;
    if (v1 != v0) {
    t0 = fn_8003591C(v2);
    v2 = t0;
    v2 = (u32)((struct fn_80074788_lbl_801A6D38_T *)lbl_801A6D38);
    *(u8 *)((u8 *)v2 + 3118) = arg0;
    }
}
