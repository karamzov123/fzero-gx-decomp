#include "types.h"
#include "dolphin/gx.h"

typedef struct AvDispColor {
    u8 r, g, b, a;
} AvDispColor;

typedef struct AvDispEntry8 {
    s8 v[6];
    u8 pad[2];
} AvDispEntry8;

typedef struct AvDispState {
    u8 flags[4];
    f32 unk_4;
    f32 unk_8;
    u32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    AvDispColor unk_20;
    u32 unk_24;
    u32 colorReg;
    u32 unk_2C;
    AvDispColor unk_30;
    AvDispColor unk_34;
} AvDispState;

typedef struct AvDispGXData {
    u16 vNumNot;
    u16 bpSentNot;
} AvDispGXData;

typedef struct AvDispTexObject {
    u32 flags;
    u16 index;
    u16 pad06;
    u32 value;
} AvDispTexObject;

typedef struct AvDispTexEntry {
    u32 pad00;
    u32 data;
} AvDispTexEntry;

typedef struct AvDispFileInfo {
    u8 pad_0[0x34];
    u32 unk_34;
} AvDispFileInfo;

typedef struct AvDispProj {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_c;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
} AvDispProj;

AvDispState lbl_8019E250;
AvDispEntry8 lbl_8019E250__fzgx_offset_38[16];
u8 lbl_8019E308[0xD00];

extern AvDispGXData *gx;
extern u32 lbl_801A6410;
extern u32 lbl_8019E210[];
extern AvDispColor lbl_801A7920;
extern AvDispColor lbl_801A7448;
extern AvDispEntry8 *lbl_801A6D2C;
extern const f32 lbl_801A744C;
extern const f32 lbl_801A7450;
extern const f32 lbl_801A7454;
extern const f32 lbl_801A7458;
extern const f32 lbl_801A745C;
extern const f32 lbl_801A7460;
extern f32 lbl_8019F008[];
extern u32 lbl_8019F024[];
extern u32 lbl_801A6D28;
extern u32 lbl_8015ACBC[21];
extern u32 lbl_8015AC68[21];

extern void fn_800718BC(AvDispTexObject *, void *, AvDispTexEntry *);
extern u32 fn_80008E34(u32, u32);
extern u32 fn_80008E5C(u32, u32);
extern u32 DVDOpen(void);
extern u32 DVDReadPrio(u32, u32, u32, u32, u32);
extern u32 DVDClose(void);
extern u32 fn_800793D4(void *, u32, u32);
extern void fn_800725DC(AvDispColor);
extern void fn_80072614(AvDispColor);
extern u32 fn_800377F8(u32, void *, f32, f32);
extern void C_MTXPerspective(void *, f32, f32, f32, f32);
extern void GXSetProjectionv();
extern u32 memcpy(u32, u32, u32);
extern u32 fn_8003887C(void);
extern u32 fn_80038944(void);
extern void GXClearVtxDesc(u32 value);
extern void GXSetVtxDesc(u32 index, u32 value);

void fn_80071ED4(f32 arg0, f32 arg1, s32 arg2);
void fn_800720B0(s32 arg0);
void fn_800721FC(f32 arg0, f32 arg1, f32 arg2, f32 arg3);

void fn_80071C04(AvDispTexObject *obj, AvDispTexEntry *entry) {
    if (obj->flags & 0x00200000) {
        obj->value = 0;
    } else if (entry == 0) {
        obj->value = 0;
    } else {
        fn_800718BC(obj, (u8 *)entry->data + obj->index * 16, entry);
    }
}

void fn_80071C64(u32 arg0) {
    fn_80008E34(lbl_801A6410, arg0);
}

void fn_80071C8C(u32 arg0) {
    fn_80008E5C(lbl_801A6410, arg0);
}

u32 fn_80071CB4(void) {
    return (u32)&lbl_8019E210;
}

void fn_80071CC0(void) {
    DVDOpen();
}

u32 fn_80071CE0(AvDispFileInfo *arg0) {
    return arg0->unk_34;
}

void fn_80071CE8(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    DVDReadPrio(arg0, arg1, arg2, arg3, 2);
}

void fn_80071D0C(void) {
    DVDClose();
}

void fn_80071D2C(void) {
}

void fn_80071D30(void) {
    AvDispColor c1;
    AvDispColor c0;
    AvDispEntry8 *e;
    s32 i;

    c1 = lbl_801A7920;
    c0 = lbl_801A7448;
    lbl_8019E250.unk_2C = 0;
    lbl_8019E250.flags[0] = 0;
    lbl_8019E250.flags[1] = 0;
    lbl_8019E250.flags[2] = 0;
    lbl_8019E250.flags[3] = 0;
    e = lbl_8019E250__fzgx_offset_38;
    lbl_801A6D2C = e;
    for (i = 2; i != 0; i--, e += 8) {
        e[0].v[0] = -1;
        e[0].v[1] = -1;
        e[0].v[2] = -1;
        e[0].v[3] = -1;
        e[0].v[4] = -1;
        e[0].v[5] = -1;
        e[1].v[0] = -1;
        e[1].v[1] = -1;
        e[1].v[2] = -1;
        e[1].v[3] = -1;
        e[1].v[4] = -1;
        e[1].v[5] = -1;
        e[2].v[0] = -1;
        e[2].v[1] = -1;
        e[2].v[2] = -1;
        e[2].v[3] = -1;
        e[2].v[4] = -1;
        e[2].v[5] = -1;
        e[3].v[0] = -1;
        e[3].v[1] = -1;
        e[3].v[2] = -1;
        e[3].v[3] = -1;
        e[3].v[4] = -1;
        e[3].v[5] = -1;
        e[4].v[0] = -1;
        e[4].v[1] = -1;
        e[4].v[2] = -1;
        e[4].v[3] = -1;
        e[4].v[4] = -1;
        e[4].v[5] = -1;
        e[5].v[0] = -1;
        e[5].v[1] = -1;
        e[5].v[2] = -1;
        e[5].v[3] = -1;
        e[5].v[4] = -1;
        e[5].v[5] = -1;
        e[6].v[0] = -1;
        e[6].v[1] = -1;
        e[6].v[2] = -1;
        e[6].v[3] = -1;
        e[6].v[4] = -1;
        e[6].v[5] = -1;
        e[7].v[0] = -1;
        e[7].v[1] = -1;
        e[7].v[2] = -1;
        e[7].v[3] = -1;
        e[7].v[4] = -1;
        e[7].v[5] = -1;
    }
    fn_800793D4(lbl_8019E308, 0xFF, 0xD00);
    lbl_8019E250.unk_20 = c1;
    lbl_8019E250.unk_30 = c1;
    lbl_8019E250.unk_34 = c1;
    fn_800721FC(lbl_801A744C, lbl_801A7450, lbl_801A7454, lbl_801A7458);
    fn_80071ED4(lbl_801A745C, lbl_801A745C, 4);
    fn_800720B0(0);
    fn_800725DC(c0);
    fn_80072614(c0);
}

void fn_80071ED4(f32 arg0, f32 arg1, s32 arg2) {
    f32 v0;
    f32 v1;
    u32 c;
    u32 b;
    f32 t;
    u32 x;
    u32 w;
    struct { u32 a[2]; } loc_8;

    v0 = lbl_8019E250.unk_4;
    v1 = lbl_8019E250.unk_8;
    if (arg1 == lbl_8019E250.unk_14 && arg0 == lbl_8019E250.unk_10 && v1 == lbl_8019E250.unk_18 && v0 == lbl_8019E250.unk_1C && arg2 == (s32)lbl_8019E250.unk_C) {
        return;
    }
    if (arg2 == 0) {
        fn_800720B0(0);
        return;
    }
    c = lbl_8019E250.unk_2C | 1;
    lbl_8019E250.unk_C = arg2;
    lbl_8019E250.unk_10 = arg0;
    lbl_8019E250.unk_14 = arg1;
    lbl_8019E250.unk_18 = v1;
    lbl_8019E250.unk_1C = v0;
    lbl_8019E250.unk_2C = lbl_8019E250.unk_2C | 1;
    b = *(u32 *)&lbl_8019E250.unk_20;
    loc_8.a[0] = b;
    fn_800377F8(arg2, &loc_8, arg0, arg1);
    if (arg0 == arg1) {
        t = lbl_801A745C;
    } else {
        t = arg0 / (arg1 - arg0);
    }
    *(f32 *)&loc_8.a[1] = t;
    x = loc_8.a[1];
    w = (lbl_8019E250.unk_24 & 0xFFFFF800) | ((x >> 12) & 0x7FF);
    lbl_8019E250.unk_24 = w;
    w = (w & 0xFFF807FF) | (((x >> 23) & 0xFF) << 11);
    lbl_8019E250.unk_24 = w;
    w = (w & 0xFFF7FFFF) | ((x >> 31) << 19);
    lbl_8019E250.unk_24 = w;
    w = w & 0xFFEFFFFF;
    lbl_8019E250.unk_24 = w;
    lbl_8019E250.unk_24 = (lbl_8019E250.unk_24 & 0xFFFFFF) | 0xF1000000;
}

#define SET_REG_FIELD(reg, size, shift, val) ((reg) = ((u32)(val) << (shift)) | ((reg) & ~(((1 << (size)) - 1) << (shift))))

#pragma opt_lifetimes off
#pragma opt_propagation off
static inline void WriteBPReg(u32 value) {
    u8 command = 0x61; /* GX_LOAD_BP_REG */
    gx->bpSentNot = 0;
    GXWGFifo.u8 = command;
    GXWGFifo.u32 = value;
}

void fn_80072014(AvDispColor color) {
    u32 reg;

    if (lbl_8019E250.unk_20.r == color.r && lbl_8019E250.unk_20.g == color.g && lbl_8019E250.unk_20.b == color.b) {
        return;
    }
    lbl_8019E250.unk_20.r = color.r;
    lbl_8019E250.unk_20.g = color.g;
    lbl_8019E250.unk_20.b = color.b;
    reg = color.b;
    SET_REG_FIELD(reg, 8, 8, color.g);
    SET_REG_FIELD(reg, 8, 16, color.r);
    SET_REG_FIELD(reg, 8, 24, 0xF2);
    lbl_8019E250.colorReg = reg;
    WriteBPReg(reg);
}
#pragma opt_propagation reset
#pragma opt_lifetimes reset

#pragma opt_common_subs off
#pragma opt_propagation off
static inline void avdisp_write_bp_impl(u32 value) {
    u32 data = value;
    u32 command = 0x61;
    gx->bpSentNot = 0;
    GXWGFifo.u8 = command;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    GXWGFifo.u32 = data;  /* fzgx-allow: S2 volatile view keeps the verified load order */
}

void fn_800720B0(s32 arg0) {
    u32 flags;
    u32 mode;
    u32 v;
    AvDispState *p;
    if (arg0 != 0) {
        p = &lbl_8019E250;
        flags = p->unk_2C;
        if (flags & 1) {
            return;
        }
        v = p->unk_24;
        mode = p->unk_C;
        p->unk_2C = flags | 1;
        if (((v >> 21) & 7) == mode) {
            return;
        }
        avdisp_write_bp_impl(p->unk_24 = (v & 0xFF1FFFFF) | (mode << 21));
    } else {
        p = &lbl_8019E250;
        if (!(p->unk_2C & 1)) {
            return;
        }
        v = p->unk_24;
        p->unk_2C = p->unk_2C & ~1;
        if (((v >> 21) & 7) == 0) {
            return;
        }
        avdisp_write_bp_impl(p->unk_24 = v & 0xFF1FFFFF);
    }
}
#pragma opt_common_subs reset

void fn_80072168(s32 arg0) {
    u32 mode;
    u32 v;
    AvDispState *p;
    p = &lbl_8019E250;
    if (!(p->unk_2C & 1)) {
        return;
    }
    if (arg0 != 0) {
        v = p->unk_24;
        mode = p->unk_C;
        if (((v >> 21) & 7) == mode) {
            return;
        }
        avdisp_write_bp_impl(p->unk_24 = (v & 0xFF1FFFFF) | (mode << 21));
    } else {
        v = p->unk_24;
        if (((v >> 21) & 7) == 0) {
            return;
        }
        avdisp_write_bp_impl(p->unk_24 = v & 0xFF1FFFFF);
    }
}
#pragma opt_propagation reset

void fn_800721FC(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 v0;
    struct { f32 a[18]; } loc_8;

    lbl_8019E250.unk_4 = arg2;
    lbl_8019E250.unk_8 = arg3;
    C_MTXPerspective(&loc_8, arg0, arg1, arg2, arg3);
    v0 = loc_8.a[0];
    lbl_8019F008[0] = lbl_801A745C;
    lbl_8019F008[1] = v0;
    lbl_8019F008[2] = loc_8.a[2];
    lbl_8019F008[3] = loc_8.a[5];
    lbl_8019F008[4] = loc_8.a[6];
    lbl_8019F008[5] = loc_8.a[10];
    lbl_8019F008[6] = loc_8.a[11];
    GXSetProjectionv();
}

void fn_80072270(AvDispProj *arg0, u32 arg1, f32 arg2, f32 arg3) {
    f32 zero = lbl_801A745C;
    if (zero == arg0->unk_0) {
        lbl_8019E250.unk_4 = __fabs(arg0->unk_18 / (arg0->unk_14 - lbl_801A7460));
    } else {
        lbl_8019E250.unk_4 = __fabs((lbl_801A7460 + arg0->unk_18) / arg0->unk_14);
    }

    lbl_8019E250.unk_8 = arg0->unk_18 / arg0->unk_14;
    lbl_8019F008[0] = arg0->unk_0;
    lbl_8019F008[1] = arg0->unk_4;
    lbl_8019F008[2] = arg0->unk_8;
    lbl_8019F008[3] = arg0->unk_c;
    lbl_8019F008[4] = arg0->unk_10;
    lbl_8019F008[5] = arg0->unk_14;
    lbl_8019F008[6] = arg0->unk_18;
    GXSetProjectionv(lbl_8019F008);
}

void fn_80072344(void) {
    memcpy((u32)&lbl_8019F024, (u32)&lbl_8019F008, 28);
}

void fn_80072378(void) {
    memcpy((u32)&lbl_8019F008, (u32)&lbl_8019F024, 28);
    GXSetProjectionv(&lbl_8019F008);
}

void fn_800723B8(void) {
    fn_8003887C();
}

void fn_800723D8(void) {
    fn_80038944();
}

void fn_800723F8(void) {
    lbl_801A6D28 = 0;
}

u32 fn_80072404(u32 mask, s32 select) {
    u32 *a = lbl_8015ACBC;
    u32 *b = lbl_8015AC68;
    u32 total = 0;
    int i;

    for (i = 0; i < 17; i++) {
        if (mask & 1) {
            if (select != 0) {
                total += *a;
            } else {
                total += *b;
            }
        }
        mask >>= 1;
        a = a + 1;
        b++;
    }
    return total;
}

void fn_8007245C(u32 value) {
    u32 index;

    if (value != lbl_801A6D28) {
        GXClearVtxDesc(value);
        lbl_801A6D28 = value;
        index = 0;
        while (index < 0x1a) {
            if (value & 1) {
                GXSetVtxDesc(index, 1);
            }
            index++;
            value >>= 1;
        }
    }
}

void fn_800724C8(void) {
}
