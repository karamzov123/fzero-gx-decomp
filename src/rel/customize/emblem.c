#include "types.h"
extern u8 lbl_3_bss_A17A0[44];
extern s16 lbl_3_bss_A17CC;
extern u32 lbl_3_bss_A176C;
extern u32 *lbl_3_bss_A1770;
extern u32 *lbl_3_bss_A1774;
extern u8 lbl_3_data_3574[60];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, s32);

/* fzgx:begin fn_3_1338C noprologue */
#include "types.h"

extern void fn_1_426C(u32);
extern void fn_1_435C(u32);
extern void fn_1_46B4(u32, u32, u8 *, s32);
extern void fn_1_48140(s32);
extern void fn_3_142C4(void);
extern void fn_3_1563C(void);
extern void fn_3_19C50(void);

extern u32 lbl_801A6410;

typedef struct {
    u8 pad00[4];
    u32 *unk04;
    u8 pad08[0xC];
    u32 unk14;
    u32 unk18;
    u8 pad1C[4];
    u32 unk20;
    u32 unk24[5];
    u32 unk38[11];
    s16 unk64;
} EmblemState;


#pragma opt_propagation off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_3_bss_A1768;
u32 *fzgx_obj_lbl_3_bss_A176C;
u32 lbl_3_bss_A1770;
u32 lbl_3_bss_A1774;
u32 lbl_3_bss_A1778__fzgx_offset_0;
u32 lbl_3_bss_A1778__fzgx_offset_4;
u32 lbl_3_bss_A1778__fzgx_offset_8;
u32 lbl_3_bss_A1784__fzgx_offset_0;
u32 lbl_3_bss_A1784__fzgx_offset_4;
u8 lbl_3_bss_A1784__fzgx_offset_8;
u8 lbl_3_bss_A1784__fzgx_offset_9;
u16 lbl_3_bss_A1784__fzgx_offset_A;
u32 lbl_3_bss_A1784__fzgx_offset_C[2];
u32 lbl_3_bss_A1798;
u32 fzgx_obj_lbl_3_bss_A179C;
u32 fzgx_obj_lbl_3_bss_A17A0[11];
s16 fzgx_obj_lbl_3_bss_A17CC;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_A1768;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_A176C;
    s = *(u8 *)&lbl_3_bss_A1770;
    s = *(u8 *)&lbl_3_bss_A1774;
    s = *(u8 *)&lbl_3_bss_A1778__fzgx_offset_0;
    s = *(u8 *)&lbl_3_bss_A1778__fzgx_offset_4;
    s = *(u8 *)&lbl_3_bss_A1778__fzgx_offset_8;
    s = *(u8 *)&lbl_3_bss_A1784__fzgx_offset_0;
    s = *(u8 *)&lbl_3_bss_A1784__fzgx_offset_4;
    s = *(u8 *)&lbl_3_bss_A1784__fzgx_offset_8;
    s = *(u8 *)&lbl_3_bss_A1784__fzgx_offset_9;
    s = *(u8 *)&lbl_3_bss_A1784__fzgx_offset_A;
    s = *(u8 *)&lbl_3_bss_A1784__fzgx_offset_C;
    s = *(u8 *)&lbl_3_bss_A1798;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_A179C;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_A17A0;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_A17CC;
}
#pragma section code_type ".text"

extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("emblem.c");
}
#pragma section code_type ".text"

void fn_3_1338C(void) {
    u8 i;
    u32 v;

    
    fn_1_435C(lbl_3_bss_A1778__fzgx_offset_4);
    fn_1_426C(lbl_3_bss_A1784__fzgx_offset_4);
    fn_1_435C(lbl_3_bss_A1778__fzgx_offset_8);
    fn_1_426C((*(u32 (*)[5])&lbl_3_bss_A1784__fzgx_offset_8)[1]);
    fn_3_1563C();
    fn_3_19C50();
    fn_3_142C4();
    fn_1_46B4(lbl_801A6410, fzgx_obj_lbl_3_bss_A17A0[8], (u8 *)"emblem.c", 0xd1);
    for (i = 0; i < fzgx_obj_lbl_3_bss_A17CC; i++) {
        v = fzgx_obj_lbl_3_bss_A176C[i];
        if (v != 0) {
            fn_1_46B4(lbl_801A6410, v, (u8 *)"emblem.c", 0xd6);
        }
    }
    fn_1_46B4(lbl_801A6410, (u32)fzgx_obj_lbl_3_bss_A176C, (u8 *)"emblem.c", 0xd8);
    fn_1_48140(0x86);
}
/* fzgx:end fn_3_1338C */

/* fzgx:begin fn_3_1349C noprologue */
#include "types.h"

extern void fn_1_4CC0(void);
extern u32 lbl_3_bss_A17A0;
extern s16 lbl_3_bss_A17D2;
extern u16 lbl_1_bss_96A;

void fn_3_1349C(void) {
    fn_1_4CC0();
    if ((lbl_3_bss_A17A0 & 0x20000000) != 0) {
        if (lbl_3_bss_A17D2 > 0) {
            lbl_3_bss_A17D2--;
            if (lbl_3_bss_A17D2 == 0) {
                lbl_1_bss_96A = 0x5c;
                lbl_3_bss_A17A0 &= ~0x20000000;
            }
        }
    }
}
/* fzgx:end fn_3_1349C */

/* fzgx:begin fn_3_13508 pool noprologue */
#include "types.h"

/* lbl_1_bss_9F8: table of 0x14-byte entries with a u16 flag word at +8 */
struct fn_3_13508_Entry { u16 unk_0; u8 pad_2[0x12]; };
struct fn_3_13508_Table {
    union {
        struct { u8 pad_8[0x8]; struct fn_3_13508_Entry unk_8[1]; };
        struct { u8 pad_0[0x8]; u16 flags; u8 pad_A[0xA]; } e[1];
    };
};
extern struct fn_3_13508_Table lbl_1_bss_9F8;

typedef struct lbl_3_bss_A17A0_t {
    u32 flags;
    u8 pad_4[0x10];
    s16 unk_14;
    u8 pad_16[0x12];
    u8 unk_28;
    u8 pad_29[0x3];
} lbl_3_bss_A17A0_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_3_bss_A1768;
u32 lbl_3_bss_A176C;
u32 lbl_3_bss_A1770;
u32 lbl_3_bss_A1774;
u8 lbl_3_bss_A1778[8];
u32 lbl_3_bss_A1780;
u8 lbl_3_bss_A1784[0x14];
u32 lbl_3_bss_A1798;
u32 lbl_3_bss_A179C;
lbl_3_bss_A17A0_t lbl_3_bss_A17A0;
s16 lbl_3_bss_A17CC;
u8 lbl_3_bss_A17D0[2];
s16 lbl_3_bss_A17D2;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_3_bss_A1768;
    s = *(u8 *)&lbl_3_bss_A176C;
    s = *(u8 *)&lbl_3_bss_A1770;
    s = *(u8 *)&lbl_3_bss_A1774;
    s = *(u8 *)&lbl_3_bss_A1778;
    s = *(u8 *)&lbl_3_bss_A1780;
    s = *(u8 *)&lbl_3_bss_A1784;
    s = *(u8 *)&lbl_3_bss_A1798;
    s = *(u8 *)&lbl_3_bss_A179C;
    s = *(u8 *)&lbl_3_bss_A17A0;
    s = *(u8 *)&lbl_3_bss_A17CC;
    s = *(u8 *)&lbl_3_bss_A17D0;
    s = *(u8 *)&lbl_3_bss_A17D2;
}
#pragma section code_type ".text"

extern s32 fn_1_1318B8(void);
extern u8 fn_3_19C94(void);
extern u32 fn_3_19CE0(void);
extern void fn_3_19D50(void);
extern void fn_3_18614(void);
extern void fn_3_170E0(void);
extern void fn_3_156D0(void);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_A2D84(u32);

void fn_3_13508(void) {
    u32 flags;
    s32 v;
    u32 saved;

    if (fn_1_1318B8() != 0) return;
    if (lbl_3_bss_A17D0[0] != 0) return;
    if (lbl_3_bss_A17D0[1] != 0) return;

    if (lbl_3_bss_A17A0.flags & 0x40000000) {
        fn_1_4A00(1, 15, lbl_3_bss_A1780);
        lbl_3_bss_A17A0.flags &= ~0x40000000;
        lbl_3_bss_A17D2 = 15;
        lbl_3_bss_A17A0.flags |= 0x20000000;
        return;
    }

    if (fn_3_19C94() != 16 && fn_3_19C94() != 15 && fn_3_19C94() != 11) {
        flags = lbl_3_bss_A17A0.flags;
        if (!__rlwnm(flags, 7, 31, 31)) {
            if ((lbl_1_bss_9F8.unk_8[lbl_3_bss_A17A0.unk_28].unk_0 >> 11) & 1) {
                if (flags & 0x80000000) {
                    lbl_3_bss_A17A0.flags = flags & 0x7FFFFFFF;
                } else {
                    lbl_3_bss_A17A0.flags = flags | 0x80000000;
                }
            }
            if ((lbl_1_bss_9F8.unk_8[lbl_3_bss_A17A0.unk_28].unk_0 >> 4) & 1) {
                fn_1_A2D84(0xA9150600);
                fn_3_19D50();
            }
        }
    }

    flags = lbl_3_bss_A17A0.flags;
    if (__rlwnm(flags, 7, 31, 31)) {
        if ((lbl_1_bss_9F8.e[lbl_3_bss_A17A0.unk_28].flags >> 9) & 1) {
            lbl_3_bss_A17A0.flags = flags & ~0x02000000;
        }
        return;
    }

    if (((lbl_1_bss_9F8.e[lbl_3_bss_A17A0.unk_28].flags >> 12) & 1) &&
        fn_3_19C94() != 16 && fn_3_19C94() != 15 &&
        fn_3_19C94() != 17 && fn_3_19C94() != 12) {
        lbl_3_bss_A17A0.flags |= 0x02000000;
        return;
    }

    v = lbl_3_bss_A17A0.unk_14 + 1;
    lbl_3_bss_A17A0.unk_14 = (v < 0) ? 0 : (v > 120 ? 120 : v);
    if (lbl_3_bss_A17A0.flags & 0x60000000) return;

    saved = fn_3_19CE0();
    fn_3_18614();
    if (fn_3_19C94() == 16 || fn_3_19C94() == 15 || fn_3_19C94() == 12 ||
        fn_3_19C94() == 17 || fn_3_19C94() == 11) {
        return;
    }
    if ((u8)saved != 0 && (u8)fn_3_19CE0() == 0) {
        fn_3_170E0();
    } else {
        fn_3_156D0();
        fn_3_170E0();
    }
}
/* fzgx:end fn_3_13508 */

/* fzgx:begin fn_3_137AC noprologue */
#include "types.h"
#include "font.h"
#include "rel/customize/emblem.h"

struct fn_3_137AC_FontPacket {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x20];
    u32 unk_30;
    u8 pad_34[0x24];
};

struct fn_3_137AC_Sel {
    u8 unk_0;
    u8 unk_1;
};

extern struct fn_3_137AC_FontPacket lbl_1_rodata_26F8;
extern f32 lbl_3_rodata_4E0[22];
extern struct fn_3_137AC_Sel lbl_3_bss_A17D0;

extern void fn_1_133DBC(void *);
extern void fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_1318D4(void);
extern s32 fn_1_B8EDC(u32);
extern u32 fn_3_19C94(void);
extern u32 fn_3_19CE0(void);
extern u32 fn_3_18960(u32);
extern u32 fn_3_15F44(u32);
extern u32 fn_3_17854(u32);
extern u32 fn_3_BF1C(void);
extern u32 fn_3_139F0(void);

void fn_3_137AC(void) {
    struct fn_3_137AC_FontPacket pkt;
    f32 *prodata;
    s32 c;
    s32 n;

    prodata = lbl_3_rodata_4E0;
    fn_1_133DBC((void *)1);
    fn_1_134AD4();

    if (__rlwnm(lbl_3_bss_A17A0.unk_0, 7, 31, 31)) {
        fn_1_13ABA8(0x20000000);
    } else {
        if ((u8)fn_3_19C94() == 9) {
            if ((u8)fn_3_19CE0() == 0) {
                fn_1_13ABA8(0x2A200000);
            } else {
                fn_1_13ABA8(0x28200000);
            }
        } else if ((u8)fn_3_19C94() == 10) {
            if ((u8)fn_3_19CE0() == 0) {
                fn_1_13ABA8(0x29200000);
            } else {
                fn_1_13ABA8(0x28200000);
            }
        } else if ((u8)fn_3_19C94() == 16 || (u8)fn_3_19C94() == 15
                   || (u8)fn_3_19C94() == 12 || (u8)fn_3_19C94() == 17) {
            fn_1_13ABA8(0x28000000);
        } else {
            fn_1_13ABA8(0x28200000);
        }
    }

    pkt = lbl_1_rodata_26F8;
    pkt.unk_0 = 0x8606;
    pkt.unk_4 = prodata[1];
    pkt.unk_8 = prodata[2];
    pkt.unk_C = prodata[3];
    pkt.unk_30 = 10;
    fn_1_4F734((FontDrawPacket *)&pkt);

    if (fn_1_1318D4() != 0) {
        return;
    }

    if (lbl_3_bss_A17D0.unk_0 != 0) {
        if (fn_1_B8EDC(0) != 0) {
            lbl_3_bss_A17D0.unk_0 = 0;
        }
    } else if (lbl_3_bss_A17D0.unk_1 != 0) {
        if (fn_1_B8EDC(1) != 0) {
            lbl_3_bss_A17D0.unk_1 = 0;
        }
    } else {
        n = lbl_3_bss_A17A0.unk_14 - 15;
        if (n < 0) {
            c = 0;
        } else {
            c = 15;
            if (n <= 15) {
                c = n;
            }
        }
        fn_3_18960((s16)c);
        fn_3_15F44(lbl_3_bss_A17A0.unk_14);
        fn_3_17854(lbl_3_bss_A17A0.unk_14);
        fn_3_BF1C();
        if (__rlwnm(lbl_3_bss_A17A0.unk_0, 7, 31, 31)) {
            fn_3_139F0();
        }
    }
}
/* fzgx:end fn_3_137AC */

/* fzgx:begin fn_3_13D98 noprologue */
#include "types.h"

extern u8 lbl_3_data_3574[60];
extern void *lbl_801A6410;
extern u32 *lbl_3_bss_A176C;

extern int fn_1_45730(void *arg, void *buffer);
extern u32 fn_1_45B2C(void *buffer);
extern void *fn_1_45D0(void *source, u32 size, void *data, u32 format);
extern void fn_80008BEC(void *buffer, u32 offset, u32 size);
extern void fn_1_458A0(void *buffer, void *output, u32 size, u32 alignment);
extern void fn_80008BA8(void *texture, void *buffer, u32 size);
extern void fn_1_45850(void *buffer);

u32 fn_3_13D98(void *arg) {
    u8 header[0x60];
    u8 buffer[0x2000] __attribute__((aligned(32)));
    u8 i;
    u32 count;
    u32 size;

    if (fn_1_45730(arg, header) != 0) {
        size = fn_1_45B2C(header);
        count = size >> 13;
        if (count >= 0xc2) {
            count = 0xc2;
        }
        if (size != 0) {
            for (i = 0; i < count; i++) {
                lbl_3_bss_A176C[(u8)i] = (u32)fn_1_45D0(lbl_801A6410, 0x2000,
                                                          lbl_3_data_3574, 0x236);
                fn_80008BEC((void *)lbl_3_bss_A176C[(u8)i], 0, 0x2000);
                fn_1_458A0(header, buffer, 0x2000,
                           ((i << 13) + 0x1f) & ~0x1f);
                fn_80008BA8((void *)lbl_3_bss_A176C[(u8)i], buffer, 0x2000);
            }
            fn_1_45850(header);
        }
    }
    return count;
}
/* fzgx:end fn_3_13D98 */

/* fzgx:begin fn_3_13EA4 noprologue */
#include "types.h"

extern u8 lbl_3_data_3574[60];
extern void *lbl_801A6410;
extern s32 fn_1_45730(void *, void *);
extern u32 fn_1_45B2C(void *);
extern s32 fn_1_F7BE4(u32);
extern void *fn_1_45D0(void *, u32, void *, u32);
extern void fn_80008BEC(void *, u32, u32);
extern void fn_1_458A0(void *, void *, u32, u32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_1_45850(void *);

u32 fn_3_13EA4(void *arg, u32 *output) {
    u8 header[0x60];
    u8 buffer[0x2000] __attribute__((aligned(32)));
    u32 *out;
    u8 i;
    u32 count;
    u32 limit;
    u32 size;

    out = output;
    count = 0;
    if (fn_1_45730(arg, header) != 0) {
        size = fn_1_45B2C(header);
        limit = size >> 13;
        if (limit >= 0x2c) {
            limit = 0x2c;
        }
        if (size != 0) {
            for (i = 0; i < limit; i++) {
                if ((i == limit - 3 && fn_1_F7BE4(0x15) != 0) ||
                    (i == limit - 2 && fn_1_F7BE4(0x21) != 0) ||
                    (i == limit - 1 && fn_1_F7BE4(0x21) != 0) ||
                    (fn_1_F7BE4(i) != 0)) {
                    out[(u8)count] = (u32)fn_1_45D0(lbl_801A6410, 0x2000,
                                                   lbl_3_data_3574, 0x27b);
                    fn_80008BEC((void *)out[(u8)count], 0, 0x2000);
                    fn_1_458A0(header, buffer, 0x2000,
                               ((i << 13) + 0x1f) & ~0x1f);
                    fn_80008BA8((void *)out[(u8)count], buffer, 0x2000);
                    count++;
                }
            }
        }
        fn_1_45850(header);
    }
    return (u8)count;
}
/* fzgx:end fn_3_13EA4 */

/* fzgx:begin fn_3_14008 */
void fn_3_14008(void) {
    u32 *value = (u32 *)lbl_3_bss_A17A0;
    *value |= 0x40000000;
}
/* fzgx:end fn_3_14008 */

/* fzgx:begin fn_3_1401C */
u32 fn_3_1401C(void) {
    return *(u32 *)(lbl_3_bss_A17A0 + 0x20);
}
/* fzgx:end fn_3_1401C */

/* fzgx:begin fn_3_1402C */
u32 fn_3_1402C(u8 index) {
    if (lbl_3_bss_A17CC <= index) {
        return 0;
    }
    return ((u32 *)lbl_3_bss_A176C)[index];
}
/* fzgx:end fn_3_1402C */

/* fzgx:begin fn_3_14064 */
u32 fn_3_14064(void) {
    return lbl_3_bss_A17CC & 0xff;
}
/* fzgx:end fn_3_14064 */

/* fzgx:begin fn_3_14074 */
u8 *fn_3_14074(void) {
    return lbl_3_bss_A17A0;
}
/* fzgx:end fn_3_14074 */

/* fzgx:begin fn_3_14080 */
extern u8 lbl_3_data_3574[60];
extern u32 lbl_801A6410;

typedef struct EmblemEntry {
    u8 unk00[6];
    u8 unk06;
    u8 unk07;
    void *unk08;
    u32 unk0c;
    u32 unk10;
    void *unk14;
} EmblemEntry;

typedef struct EmblemState {
    u8 unk00[8];
    void **allocs;
    void **sizes;
    u8 unk14[0x5c];
    EmblemEntry entries[0x80];
} EmblemState;

extern EmblemState lbl_3_bss_A1768;
extern void *fn_1_45D0(u32, u32, void *, u32);
extern void fn_80008BEC(void *, u32, u32);
extern void *fn_3_17820(void);

#pragma opt_propagation off
void fn_3_14080(void) {
    u8 i;
    EmblemState *state;
    EmblemEntry *entry;

    state = &lbl_3_bss_A1768;
    i = 0;
    state->allocs = fn_1_45D0(lbl_801A6410, 0x200, lbl_3_data_3574, 0x2d1);
    state->sizes = fn_1_45D0(lbl_801A6410, 0x200, lbl_3_data_3574, 0x2d2);
    for (; i < 0x80; i++) {
        state->allocs[i] = fn_1_45D0(lbl_801A6410, 0x2000, lbl_3_data_3574, 0x2d6);
        state->sizes[i] = 0;
        fn_80008BEC(state->allocs[i], 0, 0x2000);
        entry = state->entries;
        entry += i;
        fn_80008BEC(entry, 0, 0x18);
        entry->unk14 = state->allocs[i];
        entry->unk06 = 0x1f;
        entry->unk07 = 0x1f;
        entry->unk08 = fn_3_17820();
        entry->unk10 = 0;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_3_14080 */

/* fzgx:begin fn_3_141A8 noprologue */
#include "types.h"

typedef struct {
    u8 pad0[0x10];
    s16 width;
    s16 height;
    u8 pad14[0x6];
    s16 index;
    u8 pad1c[0x4];
    void *data;
} EmblemState;

typedef struct {
    u32 flags;
    u8 pad4[0x2];
    u8 width;
    u8 height;
    u32 unk8;
    u8 pad0c[0x8];
    void *resource;
} EmblemEntry;

extern EmblemState lbl_3_bss_A17A0;
extern EmblemEntry lbl_3_bss_A17D4[128];
extern void fn_80008BA8(void *, void *, u32);
extern void fn_3_17830(void);
extern void fn_3_177AC(u32 *);

void fn_3_141A8(u32 flags) {
    u32 value;

    if ((flags & ~0x3fffffffU) == 0) {
        return;
    }
    if (flags & 0x40000000U) {
        flags = 0; /* directions are exclusive: consume the mask */
        if (lbl_3_bss_A17A0.index + 1 == 0x80) {
            lbl_3_bss_A17A0.index = 0;
        } else {
            lbl_3_bss_A17A0.index += 1;
        }
    }
    if (flags & 0x80000000U) {
        if (lbl_3_bss_A17A0.index - 1 < 0) {
            lbl_3_bss_A17A0.index = 0x7f;
        } else {
            lbl_3_bss_A17A0.index -= 1;
        }
    }
    if (lbl_3_bss_A17D4[lbl_3_bss_A17A0.index].flags & 0x20000000U) {
        return;
    }
    fn_80008BA8(lbl_3_bss_A17A0.data,
                lbl_3_bss_A17D4[lbl_3_bss_A17A0.index].resource, 0x2000);
    lbl_3_bss_A17A0.width = lbl_3_bss_A17D4[lbl_3_bss_A17A0.index].width;
    lbl_3_bss_A17A0.height = lbl_3_bss_A17D4[lbl_3_bss_A17A0.index].height;
    fn_3_17830();
    value = lbl_3_bss_A17D4[lbl_3_bss_A17A0.index].unk8;
    fn_3_177AC(&value);
}
/* fzgx:end fn_3_141A8 */

/* fzgx:begin fn_3_142C4 */
void fn_3_142C4(void) {
    u8 i;

    for (i = 0; i < 0x80; i++) {
        if (lbl_3_bss_A1770[i] != 0) {
            fn_1_46B4(lbl_801A6410, lbl_3_bss_A1770[i],
                       lbl_3_data_3574, 0x321);
            lbl_3_bss_A1770[i] = 0;
        }

        if (lbl_3_bss_A1774[i] != 0) {
            fn_1_46B4(lbl_801A6410, lbl_3_bss_A1774[i],
                       lbl_3_data_3574, 0x326);
            lbl_3_bss_A1774[i] = 0;
        }
    }

    if (lbl_3_bss_A1774 != 0) {
        fn_1_46B4(lbl_801A6410, (u32)lbl_3_bss_A1774,
                   lbl_3_data_3574, 0x32e);
        lbl_3_bss_A1774 = 0;
    }

    if (lbl_3_bss_A1770 != 0) {
        fn_1_46B4(lbl_801A6410, (u32)lbl_3_bss_A1770,
                   lbl_3_data_3574, 0x334);
        lbl_3_bss_A1770 = 0;
    }
}
/* fzgx:end fn_3_142C4 */

/* fzgx:begin fn_3_1441C */
typedef struct fn_3_1441C_EmblemState {
    u8 pad[0x18];
    s16 field_18;
    s16 field_1a;
} fn_3_1441C_EmblemState;

u8 fn_3_1441C(void) {
    fn_3_1441C_EmblemState *state = (fn_3_1441C_EmblemState *)lbl_3_bss_A17A0;
    return state->field_1a == state->field_18;
}
/* fzgx:end fn_3_1441C */

/* fzgx:begin fn_3_1443C */
typedef struct {
    u8 pad16[0x16];
    s16 value16;
    u8 pad18[2];
    s16 value1a;
} fn_3_1443C_EmblemState;

u8 fn_3_1443C(void) {
    fn_3_1443C_EmblemState *state = (fn_3_1443C_EmblemState *)lbl_3_bss_A17A0;
    return state->value1a == state->value16;
}
/* fzgx:end fn_3_1443C */

/* fzgx:begin fn_3_1445C noprologue */
#include "types.h"

typedef struct {
    u32 flags;
    u8 pad04[0x0c];
    s16 field_10;
    s16 field_12;
    u8 pad14[2];
    s16 field_16;
    s16 field_18;
    s16 field_1a;
    u8 pad1c[4];
    u32 field_20;
} EmblemState;

typedef struct {
    u32 field_00;
    u8 field_04;
    u8 field_05;
    u8 field_06;
    u8 field_07;
    u32 field_08;
    u32 field_0c;
    u8 pad10[4];
    u32 field_14;
} EmblemEntry;

extern EmblemState lbl_3_bss_A17A0;
extern EmblemEntry lbl_3_bss_A17D4[128];

extern u8 fn_3_14600(void);
extern u32 fn_3_17820(u8 *);
extern u8 fn_3_19C94(void);
extern void fn_80008BA8(u32, u32, u32);

static inline EmblemEntry *fn_3_1445C_array_read(EmblemEntry *array) { return array; }
void fn_3_1445C(void) {
    s32 next;
    EmblemState *state2;
    s32 flags;

    if ((lbl_3_bss_A17A0.flags & 0x04000000) == 0) {
        if (fn_3_14600() != 0)
            return;
    } else {
        lbl_3_bss_A17A0.flags &= ~0x04000000;
    }

    flags = lbl_3_bss_A17A0.flags;
    flags |= 0x10000000;
    lbl_3_bss_A17A0.flags = flags;
    flags = lbl_3_bss_A17A0.field_1a;
    next = flags;
    next = next + 1;
    if (((0x80) == (next)))
        lbl_3_bss_A17A0.field_1a = 0;
    else
        lbl_3_bss_A17A0.field_1a = next;

    if (lbl_3_bss_A17A0.field_1a == lbl_3_bss_A17A0.field_16) {
        flags = lbl_3_bss_A17A0.field_16 + 1;
        next = flags;
        if (((0x80) == (next)))
            lbl_3_bss_A17A0.field_16 = 0;
        else
            lbl_3_bss_A17A0.field_16 = next;
    }

    if (lbl_3_bss_A17A0.field_1a != lbl_3_bss_A17A0.field_16)
        lbl_3_bss_A17A0.field_16 = lbl_3_bss_A17A0.field_1a;

    state2 = &lbl_3_bss_A17A0;
    if (state2->field_18 == state2->field_16) {
        state2->field_18 = state2->field_18 + 1;
    }

    if (state2->field_18 == 0x7f)
        lbl_3_bss_A17A0.field_18 = 0;

    if (fn_3_1445C_array_read(lbl_3_bss_A17D4)[lbl_3_bss_A17A0.field_1a].field_0c < 0x2000 &&
        fn_3_1445C_array_read(lbl_3_bss_A17D4)[lbl_3_bss_A17A0.field_1a].field_0c != 0)
        fn_3_1445C_array_read(lbl_3_bss_A17D4)[lbl_3_bss_A17A0.field_1a].field_00 = 0x20000000;

    fn_3_1445C_array_read(lbl_3_bss_A17D4)[lbl_3_bss_A17A0.field_1a].field_06 =
        (u8)lbl_3_bss_A17A0.field_10;
    fn_3_1445C_array_read(lbl_3_bss_A17D4)[lbl_3_bss_A17A0.field_1a].field_07 =
        (u8)lbl_3_bss_A17A0.field_12;
    fn_3_1445C_array_read(lbl_3_bss_A17D4)[lbl_3_bss_A17A0.field_1a].field_08 =
        fn_3_17820((u8 *)&lbl_3_bss_A17D4[lbl_3_bss_A17A0.field_1a]);
    fn_3_1445C_array_read(lbl_3_bss_A17D4)[lbl_3_bss_A17A0.field_1a].field_04 = fn_3_19C94();
    fn_80008BA8(fn_3_1445C_array_read(lbl_3_bss_A17D4)[lbl_3_bss_A17A0.field_1a].field_14,
                 lbl_3_bss_A17A0.field_20, 0x2000);
}
/* fzgx:end fn_3_1445C */

/* fzgx:begin fn_3_14600 noprologue */
#include "types.h"

struct fn_3_14600_lbl_3_bss_A17D4_0_E24 {
    u8 pad_0[0x4];
    u8 unk_4;
    u8 pad_5[0x1];
    u8 unk_6;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
    u8 pad_C[0xC];
};
struct fn_3_14600_lbl_3_bss_A17A0 {
    u8 pad_0[0x8];
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
    u8 pad_C[0x4];
    s16 unk_10;
    s16 unk_12;
    u8 pad_14[0x6];
    s16 unk_1A;
    u8 unk_1C;
};
struct fn_3_14600_lbl_3_bss_A17D4 {
    struct fn_3_14600_lbl_3_bss_A17D4_0_E24 unk_0[1];
};

extern struct fn_3_14600_lbl_3_bss_A17A0 lbl_3_bss_A17A0;
extern struct fn_3_14600_lbl_3_bss_A17D4 lbl_3_bss_A17D4;

s32 fn_3_14600(void) {
    u8 v0;
    u32 v1;
    u8 v2;
    v0 = lbl_3_bss_A17A0.unk_1C;
    if (v0 == 11 || v0 == 16 || v0 == 15) {
    v1 = 0;
    return v1;
    }
    v2 = lbl_3_bss_A17A0.unk_B;
    if (lbl_3_bss_A17A0.unk_10 == (s32)lbl_3_bss_A17D4.unk_0[lbl_3_bss_A17A0.unk_1A].unk_6 && lbl_3_bss_A17A0.unk_12 == (s32)lbl_3_bss_A17D4.unk_0[lbl_3_bss_A17A0.unk_1A].unk_7 && lbl_3_bss_A17A0.unk_8 == lbl_3_bss_A17D4.unk_0[lbl_3_bss_A17A0.unk_1A].unk_8 && lbl_3_bss_A17A0.unk_9 == lbl_3_bss_A17D4.unk_0[lbl_3_bss_A17A0.unk_1A].unk_9 && lbl_3_bss_A17A0.unk_A == lbl_3_bss_A17D4.unk_0[lbl_3_bss_A17A0.unk_1A].unk_A && lbl_3_bss_A17A0.unk_B == lbl_3_bss_A17D4.unk_0[lbl_3_bss_A17A0.unk_1A].unk_B && v0 == lbl_3_bss_A17D4.unk_0[lbl_3_bss_A17A0.unk_1A].unk_4) {
    v2 = 1;
    return v2;
    }
    return 0;
}
/* fzgx:end fn_3_14600 */

/* fzgx:begin fn_3_146BC */
// fn_3_146BC: empty in retail (single blr).
void fn_3_146BC(void) {
}
/* fzgx:end fn_3_146BC */

/* fzgx:begin fn_3_146C0 */
extern u16 lbl_3_bss_A23D8;
extern u16 lbl_3_bss_A23DA[3];
extern void fn_3_14BBC(void *, s16, s16, s16, u32 *);

void fn_3_146C0(void *arg0, s16 x, s16 y, s16 delta, u32 *arg4) {
    s32 offset;
    u32 value;
    s16 adjusted_delta;

    if (x <= 0) {
        adjusted_delta = delta;
        if (x + adjusted_delta <= 0) {
            return;
        }
        offset = x - 1;
        offset = ((offset >> 31) ^ offset) - (offset >> 31);
        delta = adjusted_delta - offset;
        x = 1;
    } else {
        if (x + delta >= lbl_3_bss_A23D8 - 1) {
            delta = lbl_3_bss_A23D8 - 1 - x;
        }
    }

    if (y <= 0 || y >= lbl_3_bss_A23DA[0] - 1) {
        return;
    }
    value = *arg4;
    fn_3_14BBC(arg0, x, y, delta, &value);
}
/* fzgx:end fn_3_146C0 */

/* fzgx:begin fn_3_14778 noprologue */
#include "rel/customize/emblem.h"

struct EmblemState {
    u16 unk_0;
    u16 unk_2;
    u8 unk_4;
    u32 unk_8;
};

#pragma peephole off
void fn_3_14778(u16 arg0, u16 arg1, u8 arg2, u32 arg3) {
    struct EmblemState *state = (struct EmblemState *)&lbl_3_bss_A23D8;
    state->unk_0 = arg0;
    state->unk_2 = arg1;
    state->unk_4 = arg2;
    state->unk_8 = arg3;
}
/* fzgx:end fn_3_14778 */

/* fzgx:begin fn_3_15240 */
extern void fn_3_14E18(void *, s16, void *, s16, void *);

void fn_3_15240(void *arg0, s16 arg1, void *arg2, u16 arg3, s16 arg4, void *arg5) {
    s32 i;
    s32 j;
    s32 n;
    s16 k;

    i = arg4;
    j = arg1;
    n = arg3;
    k = 0;
    while (k < n) {
        fn_3_14E18(arg0, j, arg2, i, arg5);
        i++;
        j++;
        k++;
    }
}
/* fzgx:end fn_3_15240 */
