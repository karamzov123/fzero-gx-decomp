#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/emblem.h"


extern u32 *lbl_3_bss_A1770;
extern u32 *lbl_3_bss_A1774;
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, s32);
extern u16 lbl_1_bss_96A;
extern u8 lbl_1_bss_9F8[0x50];
extern u8 lbl_1_rodata_26F8[0x58];
extern u8 lbl_3_bss_A17D0[0x2];
extern void fn_1_4CC0(void);
extern f32 lbl_3_rodata_4E0[22];
extern void fn_1_133DBC(void* arg0);
extern void fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern s32 fn_1_1318D4(void);
extern s32 fn_1_B8EDC(u32);
extern u32 fn_3_18960(u32);
extern u32 fn_3_15F44(u32);
extern u32 fn_3_17854(u32);
extern u32 fn_3_BF1C(void);
extern s32 fn_1_45730(void *, void *);
extern u32 fn_1_45B2C(void *);
extern void fn_1_458A0(void *, void *, u32, u32);
extern void fn_1_45850(void *);
extern s32 fn_1_F7BE4(u32);
extern u16 lbl_3_bss_A23D8__fzgx_offset_2[3];
extern void *memset(void *, int, u32);
extern void * memcpy(void *, const void *, u32);
extern u32 fn_3_149AC(u8 *data, s16 x, s16 y);

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

/* fzgx:begin fn_3_1349C */
#include "types.h"

extern s16 lbl_3_bss_A17D2;

void fn_3_1349C(void) {
    fn_1_4CC0();
    if (((*(u32 *)&lbl_3_bss_A17A0) & 0x20000000) != 0) {
        if (lbl_3_bss_A17D2 > 0) {
            lbl_3_bss_A17D2--;
            if (lbl_3_bss_A17D2 == 0) {
                lbl_1_bss_96A = 0x5c;
                (*(u32 *)&lbl_3_bss_A17A0) &= ~0x20000000;
            }
        }
    }
}
/* fzgx:end fn_3_1349C */

/* fzgx:begin fn_3_13508 noprologue */
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
u32 lbl_3_bss_A1778__fzgx_offset_8;
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
    s = *(u8 *)&lbl_3_bss_A1778__fzgx_offset_8;
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
        fn_1_4A00(1, 15, lbl_3_bss_A1778__fzgx_offset_8);
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

/* fzgx:begin fn_3_137AC */
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

extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_3_19C94(void);
extern u32 fn_3_19CE0(void);
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

    pkt = (*(struct fn_3_137AC_FontPacket *)&lbl_1_rodata_26F8);
    pkt.unk_0 = 0x8606;
    pkt.unk_4 = prodata[1];
    pkt.unk_8 = prodata[2];
    pkt.unk_C = prodata[3];
    pkt.unk_30 = 10;
    fn_1_4F734((FontDrawPacket *)&pkt);

    if (fn_1_1318D4() != 0) {
        return;
    }

    if ((*(struct fn_3_137AC_Sel *)&lbl_3_bss_A17D0).unk_0 != 0) {
        if (fn_1_B8EDC(0) != 0) {
            (*(struct fn_3_137AC_Sel *)&lbl_3_bss_A17D0).unk_0 = 0;
        }
    } else if ((*(struct fn_3_137AC_Sel *)&lbl_3_bss_A17D0).unk_1 != 0) {
        if (fn_1_B8EDC(1) != 0) {
            (*(struct fn_3_137AC_Sel *)&lbl_3_bss_A17D0).unk_1 = 0;
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

/* fzgx:begin fn_3_139F0 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/emb_paste_editor.h"


extern u8 lbl_3_bss_8F200[];
extern void fn_1_FC414(void *, int);
extern u8 lbl_3_bss_A1778[12];
extern s16 lbl_1_bss_96A;
extern void fn_1_4A00(int, int, u32);
extern void fn_1_FDFF4(void);
extern void fn_1_435C(u32);
extern void fn_1_426C(s16);
extern void fn_80008BA8(struct Sig_fn_8004E278_fn_8004E278_Arg0 *, u32, u32);
extern void fn_80008BEC(struct Sig_fn_8004E278_fn_8004E278_Arg0 *, int, u32);

extern u8 lbl_3_bss_8F200[];
extern void fn_1_FC414(void *, int);
extern u8 lbl_3_bss_A1778[12];
extern s16 lbl_1_bss_96A;
extern void fn_1_4A00(int, int, u32);
extern void fn_1_FDFF4(void);
extern void fn_1_435C(u32);
extern void fn_1_426C(s16);
extern void fn_80008BA8(struct Sig_fn_8004E278_fn_8004E278_Arg0 *, u32, u32);
extern void fn_80008BEC(struct Sig_fn_8004E278_fn_8004E278_Arg0 *, int, u32);

typedef signed short s16;
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;

typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
extern u8 lbl_3_data_3360__fzgx_offset_0[];
extern u8 lbl_3_data_336C__fzgx_offset_0[];
extern u8 lbl_3_data_3370__fzgx_offset_0[];
extern u8 lbl_3_data_3380__fzgx_offset_0[];
extern u8 lbl_3_data_3388__fzgx_offset_0[];
extern u8 lbl_3_data_3398__fzgx_offset_0[];
extern u8 lbl_3_data_33A8__fzgx_offset_0[];
extern u8 lbl_3_data_33BC__fzgx_offset_0[];
extern u8 lbl_3_data_33CC__fzgx_offset_0[];
extern u8 lbl_3_data_33DC__fzgx_offset_0[];
extern u8 lbl_3_data_33E4__fzgx_offset_0[];
extern u8 lbl_3_data_33F0__fzgx_offset_0[];
extern u8 lbl_3_data_33F8__fzgx_offset_0[];
extern u8 lbl_3_data_3400__fzgx_offset_0[];
extern u8 lbl_3_data_3408__fzgx_offset_0[];
extern u8 lbl_3_data_3410__fzgx_offset_0[];
extern u8 lbl_3_data_3420__fzgx_offset_0[];
extern u8 lbl_3_data_342C__fzgx_offset_0[];
extern u8 lbl_3_data_3444__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_3_data_3360[63] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4D6F7665, 0x20437572, 0x736F7200, 0x0, 0x834A815B, 0x835C838B, 0x82CC88DA, 0x93AE0000,
    0x48656C70, 0x0, 0x90E096BE, 0x95B682CC, 0x955C8EA6, 0x0, 0x4368616E, 0x67652050,
    0x656E2053, 0x697A6500, 0x83798393, 0x83548343, 0x835982CC, 0x95CF8D58, 0x0, 0x44697370,
    0x6C617920, 0x47726964, 0x0, 0x834F838A, 0x83628368, 0x82CC955C, 0x8EA60000, 0x53797269,
    0x6E676500, 0x8358837C, 0x83438367, 0x0, 0x53656C65, 0x63740000, 0x8C8892E8, 0x0,
    0x4261636B, 0x0, 0x82E082C7, 0x82E90000, 0x4368616E, 0x67652043, 0x6F6C6F72, 0x0,
    0x904682CC, 0x95CF8D58, 0x0, 0x5B454D42, 0x4C454D20, 0x45444954, 0x4F525D20, 0x48454C50,
    0x0, 0x5B454D42, 0x4C454D20, 0x45444954, 0x4F525D20, 0x4D414E55, 0x414C0000
};
static u32 fzgx_pool_data_lbl_3_data_3360_FC[70] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_3360__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_3370__fzgx_offset_0, (u32)lbl_3_data_3380__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0,
    (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_3388__fzgx_offset_0, (u32)lbl_3_data_3360__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0,
    (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_3370__fzgx_offset_0, (u32)lbl_3_data_3398__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_33A8__fzgx_offset_0,
    (u32)lbl_3_data_33BC__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_33CC__fzgx_offset_0, (u32)lbl_3_data_33DC__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0,
    (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_33E4__fzgx_offset_0, (u32)lbl_3_data_33F0__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0,
    (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_33F8__fzgx_offset_0, (u32)lbl_3_data_3400__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_3408__fzgx_offset_0,
    (u32)lbl_3_data_3410__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_3420__fzgx_offset_0, (u32)lbl_3_data_342C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0,
    (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_336C__fzgx_offset_0, (u32)lbl_3_data_3444__fzgx_offset_0, 0x656D626C, 0x656D5F6D, 0x616B6572, 0x5F63616C,
    0x63000000, 0x656D626C, 0x656D5F6D, 0x616B6572, 0x5F646973, 0x70000000
};
static u32 fzgx_pool_data_lbl_3_data_3574[13] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x656D626C, 0x656D2E63, 0x0, 0x2E2F656D, 0x626C656D, 0x2F73616D, 0x706C652E, 0x62696E00,
    0x2E2F656D, 0x626C656D, 0x2F636861, 0x72612E62, 0x696E0000
};
static u32 fzgx_pool_data_lbl_3_data_3360_248[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25730A00
};
static u32 fzgx_pool_data_lbl_3_data_3360_24C[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25730000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_3_data_3360(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3360;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3360_FC;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3574;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3360_248;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3360_24C;
}
#pragma section code_type ".text"

void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);

/* lbl_3_data_3360: .data size 0xC, 2 refs from emb_paste_editor.c (own data block) */

extern FontDrawPacket lbl_1_rodata_26F8;
extern s32 lbl_801A66B4;
extern void fn_1_5233C(void);
extern u32 fn_1_50A90(void *, u32, u32, u32, u32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49410(void);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_4954C(f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_494DC(s16);
/* literals of the TU's pool that precede this function's first use */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer(f32 *out) {
out[0] = 0.0f;
out[1] = 165.0f;
out[2] = 38.0f;
out[3] = 50.0f;
}
/* string table: [row][language] */
typedef const char *EmbTextRow[6];
void fn_3_139F0(void) {
FontDrawPacket pkt;

u8 i;
struct { EmbTextRow *value; } tbl;

pkt = lbl_1_rodata_26F8;
pkt.image = 0xc;
pkt.x = 320.0f;
pkt.y = 240.0f;
pkt.z = 10.0f;
pkt.flags = 10;
fn_1_50A90(&pkt, 7, 7, 0x250, 0x136);
fn_1_496FC(320.0f, 90.0f);
fn_1_49410();
fn_1_495C8(1);
fn_1_4955C(0.8f, 0.8f);
pkt = lbl_1_rodata_26F8;
pkt.image = 0x8602;
pkt.x = 148.0f;
pkt.y = 148.0f;
pkt.z = 9.0f;
pkt.flags = 5;
fn_1_4F734(&pkt);
for (i = 0; i < 3; i++) {
fn_1_49410();
fn_1_495C8(0);
fn_1_49738(fn_1_5233C);
fn_1_49748(5.0f);
fn_1_4955C(0.6666667f, 0.6666667f);
fn_1_4954C(7.0f);
fn_1_495B0(0x80000000);
if (lbl_801A66B4 != 5) {
fn_1_49590(0.5f);
fn_1_4955C(0.6f, 0.6f);
fn_1_496FC(49.0f, 0x91 + i * 99 + i * 3);
} else {
fn_1_496FC(49.0f, i * 100 + 0x93);
}
fn_1_4AE0C(((const char *)(((u8 *)fzgx_pool_data_lbl_3_data_3360_248))) , ((EmbTextRow *)fzgx_pool_data_lbl_3_data_3360_FC)[i][lbl_801A66B4] );
}
for (i = 3; i < 9; i++) {
fn_1_49410();
fn_1_495C8(0);
fn_1_49738(fn_1_5233C);
fn_1_49748(8.0f);
fn_1_4955C(0.6666667f, 0.6666667f);
fn_1_495B0(0x80000000);
fn_1_4954C(7.0f);
if (lbl_801A66B4 != 5) {
fn_1_49590(0.5f);
fn_1_4955C(0.6f, 0.6f);
fn_1_496FC(458.0f, 0x91 + (i - 3) * 40 + (i - 3));
} else {
fn_1_496FC(458.0f, 0x8f + (i - 3) * 40 + (i - 3));
}
fn_1_4AE0C(((const char *)(((u8 *)fzgx_pool_data_lbl_3_data_3360_248))) , ((EmbTextRow *)fzgx_pool_data_lbl_3_data_3360_FC)[i][lbl_801A66B4]);
}
fn_1_49410();
fn_1_494DC(5);
fn_1_495C8(1);
fn_1_4954C(7.0f);
fn_1_496FC(320.0f, 110.0f);
tbl.value = (EmbTextRow *)fzgx_pool_data_lbl_3_data_3360_FC;
fn_1_4AE0C(((const char *)(((u8 *)fzgx_pool_data_lbl_3_data_3360_24C))) , tbl.value[9][lbl_801A66B4]);
}
/* fzgx:end fn_3_139F0 */

/* fzgx:begin fn_3_13D98 */
#include "types.h"

extern void *fn_1_45D0(void *source, u32 size, void *data, u32 format);
extern void fn_80008BEC(void *buffer, u32 offset, u32 size);
extern void fn_80008BA8(void *texture, void *buffer, u32 size);

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
                (*(u32 * *)&lbl_3_bss_A176C)[(u8)i] = (u32)fn_1_45D0((*(void * *)&lbl_801A6410), 0x2000,
                                                          (*(u8 (*)[60])&lbl_3_data_3574), 0x236);
                fn_80008BEC((void *)(*(u32 * *)&lbl_3_bss_A176C)[(u8)i], 0, 0x2000);
                fn_1_458A0(header, buffer, 0x2000,
                           ((i << 13) + 0x1f) & ~0x1f);
                fn_80008BA8((void *)(*(u32 * *)&lbl_3_bss_A176C)[(u8)i], buffer, 0x2000);
            }
            fn_1_45850(header);
        }
    }
    return count;
}
/* fzgx:end fn_3_13D98 */

/* fzgx:begin fn_3_13EA4 */
#include "types.h"

extern void *fn_1_45D0(void *, u32, void *, u32);
extern void fn_80008BEC(void *, u32, u32);
extern void fn_80008BA8(void *, void *, u32);

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
                    out[(u8)count] = (u32)fn_1_45D0((*(void * *)&lbl_801A6410), 0x2000,
                                                   (*(u8 (*)[60])&lbl_3_data_3574), 0x27b);
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

/* fzgx:begin fn_3_14008 noprologue */
#include "types.h"

extern u8 lbl_3_bss_A17A0[44];

void fn_3_14008(void) {
    u32 *value = (u32 *)lbl_3_bss_A17A0;
    *value |= 0x40000000;
}
/* fzgx:end fn_3_14008 */

/* fzgx:begin fn_3_1401C noprologue */
#include "types.h"

extern u8 lbl_3_bss_A17A0[44];

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

/* fzgx:begin fn_3_14074 noprologue */
#include "types.h"

extern u8 lbl_3_bss_A17A0[44];

u8 *fn_3_14074(void) {
    return lbl_3_bss_A17A0;
}
/* fzgx:end fn_3_14074 */

/* fzgx:begin fn_3_14080 noprologue */
#include "types.h"
extern u8 lbl_3_bss_A17A0[44];
extern s16 lbl_3_bss_A17CC;
extern u32 lbl_3_bss_A176C;
extern u32 *lbl_3_bss_A1770;
extern u32 *lbl_3_bss_A1774;
extern u8 lbl_3_data_3574[60];
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, s32);

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

/* fzgx:begin fn_3_1441C noprologue */
#include "types.h"

extern u8 lbl_3_bss_A17A0[44];

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

/* fzgx:begin fn_3_1443C noprologue */
#include "types.h"

extern u8 lbl_3_bss_A17A0[44];

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

    if (y <= 0 || y >= lbl_3_bss_A23D8__fzgx_offset_2[0] - 1) {
        return;
    }
    value = *arg4;
    fn_3_14BBC(arg0, x, y, delta, &value);
}
/* fzgx:end fn_3_146C0 */

/* fzgx:begin fn_3_14778 */
#include "rel/customize/emblem.h"

struct fn_3_14778_EmblemState {
    u16 unk_0;
    u16 unk_2;
    u8 unk_4;
    u32 unk_8;
};

#pragma peephole off
void fn_3_14778(u16 arg0, u16 arg1, u8 arg2, u32 arg3) {
    struct fn_3_14778_EmblemState *state = (struct fn_3_14778_EmblemState *)&lbl_3_bss_A23D8;
    state->unk_0 = arg0;
    state->unk_2 = arg1;
    state->unk_4 = arg2;
    state->unk_8 = arg3;
}
/* fzgx:end fn_3_14778 */

/* fzgx:begin fn_3_14794 */
extern u16 lbl_3_bss_A23D8;
extern u32 lbl_3_bss_A23E0;

/* colour c (r, g, b, a bytes) as a texel: RGB565, or RGB5A3 (opaque with 5 bits per colour from alpha 0xE0 up,
 * otherwise 3 bits of alpha and 4 bits per colour) */
#define RGB565(c) ((u16)((((c)[0] & 0xF8) << 8) | (((c)[1] & 0xFC) << 3) | (((c)[2] & 0xF8) >> 3)))
#define RGB5A3(c)                                                                                       \
    ((c)[3] >= 0xE0 ? (((c)[0] & 0xF8) << 7) | (((c)[1] & 0xF8) << 2) | (((c)[2] & 0xF8) >> 3) | 0x8000 \
                    : (((c)[0] & 0xF0) << 4) | ((c)[1] & 0xF0) | (((c)[2] & 0xF0) >> 4) | (((c)[3] & 0xE0) << 7))

/* writes colour (r, g, b, a bytes) into the canvas pixel at (x, y); lbl_3_bss_A23D8 holds the canvas width and
 * lbl_3_bss_A23E0 its texture format (4 RGB565, 5 RGB5A3), pixels in 4 x 4 tiles of 16-bit texels.
 * canvas is __restrict: retail reads the alpha byte again before it stores the texel's high byte */
void fn_3_14794(u8 *__restrict canvas, s16 x, s16 y, const u8 *color) {
    s16 offset;
    s16 bx;
    s16 by;
    s16 bw;
    s16 px;
    s16 py;
    s16 blk;
    u8 hi;
    u8 lo;

    switch (lbl_3_bss_A23E0) {
    case 4:
        bx = x / 4;
        by = y / 4;
        bw = lbl_3_bss_A23D8 / 4;
        px = x % 4;
        py = y % 4;
        blk = bx + by * bw;
        offset = blk * 32 + (px + py * 4) * 2;
        hi = RGB565(color) >> 8;
        lo = RGB565(color) & 0xFF;
        memset(&canvas[offset], hi, 1);
        memset(&canvas[offset + 1], lo, 1);
        break;
    case 5:
        bx = x >> 2;
        by = y >> 2;
        bw = lbl_3_bss_A23D8 >> 2;
        blk = bx + by * bw;
        offset = blk * 32 + ((x & 3) + (y & 3) * 4) * 2;
        canvas[offset] = (u16)RGB5A3(color) >> 8;
        canvas[offset + 1] = RGB5A3(color);
        break;
    case 6: /* empty in retail too: its compare tree tests 4, 5 and 6 */
        break;
    }
}
/* fzgx:end fn_3_14794 */

/* fzgx:begin fn_3_149AC noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "font.h"
#include "rel/customize/emblem.h"

struct fn_3_137AC_lbl_3_bss_A17D0 { u8 unk_0; u8 unk_1; };

struct fn_3_13508_Entry { u16 unk_0; u8 pad_2[0x12]; };

struct fn_3_13508_Table {
    union {
        struct { u8 pad_8[0x8]; struct fn_3_13508_Entry unk_8[1]; };
        struct { u8 pad_0[0x8]; u16 flags; u8 pad_A[0xA]; } e[1];
    };
};

struct fn_3_13508_fn_3_13508_Table {
    union {
        struct { u8 pad_8[0x8]; struct fn_3_13508_Entry unk_8[1]; };
        struct { u8 pad_0[0x8]; u16 flags; u8 pad_A[0xA]; } fn_3_13508_e[1];
    };
};
extern u32 lbl_801A6410;
extern u32 fn_1_435C(u32 value);
extern void fn_1_426C(u32 idx);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_48140(int index);
extern void fn_3_142C4(void);
extern void fn_3_1563C(void);
extern void fn_3_19C50(void);
extern struct fn_3_13508_Table lbl_1_bss_9F8;
extern u8 fn_1_1318B8(void);
extern u8 fn_3_19C94(void);
extern u32 fn_3_19CE0(void);
extern void fn_3_19D50(void);
extern void fn_3_18614(void);
extern void fn_3_170E0(void);
extern void fn_3_156D0(void);
extern void fn_1_4A00(s32 fadeIn, u8 steps, u32 arg);
extern void fn_1_A2D84(u32 arg0);
extern struct fn_3_137AC_lbl_3_bss_A17D0 lbl_3_bss_A17D0;
extern f32 lbl_3_rodata_4E0[22];
extern FontDrawPacket lbl_1_rodata_26F8;
extern void fn_1_133DBC(void* arg0);
extern void fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern s32 fn_1_1318D4(void);
extern s32 fn_1_B8EDC(u32);
extern u32 fn_3_18960(s16);
extern u32 fn_3_15F44(s16);
extern u32 fn_3_17854(s16);
extern u32 fn_3_BF1C(void);
extern u32 fn_3_139F0(void);
extern s32 fn_1_45D0();
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 fn_3_17820(void);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_3_17830(void);
extern void fn_3_177AC(u32 *);
extern u32 *lbl_3_bss_A1770;
extern u32 *lbl_3_bss_A1774;
extern s32 fn_3_14600(void);
extern void fn_1_4CC0(void);
extern s16 lbl_3_bss_A17D2;
extern u16 lbl_1_bss_96A;
extern s32 fn_1_45730(void *, void *);
extern u32 fn_1_45B2C(void *);
extern void fn_1_458A0(void *, void *, u32, u32);
extern void fn_1_45850(void *);
extern s32 fn_1_F7BE4(u32);
extern u16 lbl_3_bss_A23D8__fzgx_offset_2[3];
extern void fn_3_14BBC(void *, s16, s16, s16, u32 *);
extern void fn_3_14E18(void *, s16, void *, s16, void *);

extern void * memcpy(void *, const void *, u32);

typedef struct EmblemColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} EmblemColor;

/* Reads one texel of the emblem texture (4x4 tiles) as an RGBA8 color. */
u32 fn_3_149AC(u8 *data, s16 x, s16 y) {
    u16 pix;
    EmblemColor color;
    s16 tileX;
    s16 tileY;
    s16 tilesW;
    s16 tile;
    s16 px;
    s16 py;
    s16 offset;
    u8 hi;
    u8 lo;

    switch ((s32)lbl_3_bss_A23E0) {
    default:
    case 6:
        /* All unsupported formats share the common return. */
        goto done;
    case 4:
        tileX = x / 4;
        tileY = y / 4;
        tilesW = (lbl_3_bss_A23D8 + 1) / 4;
        tile = tileX + tileY * tilesW;
        px = x % 4;
        py = y % 4;
        hi = data[(offset = (tile << 5) + ((px + (py << 2)) << 1))];
        lo = data[offset + 1];
        pix = hi << 8;
        pix |= lo;
        color.r = ((((pix & 0xF800) >> 8)) | ((pix & 7)));
        color.g = ((pix & 0x7E0) >> 3) | (pix & 3);
        color.b = (pix & 7) | ((pix & 0x1F) << 3);
        break;
    case 5:
        tileX = x / 4;
        tileY = y / 4;
        tilesW = (lbl_3_bss_A23D8 + 1) / 4;
        tile = tileX + tileY * tilesW;
        px = x % 4;
        py = y % 4;
        offset = (tile << 5) + ((px + (py << 2)) << 1);
        memcpy(&pix, data + offset, 2);
        if (pix & 0x8000) {
            color.a = 0xFF;
            color.r = (pix >> 7) & 0xF8;
            color.g = (pix >> 2) & 0xF8;
            color.b = (pix & 0x1F) << 3;
        } else {
            color.a = (pix >> 8) & 0x70;
            color.r = (pix >> 4) & 0xF0;
            color.g = pix & 0xF0;
            color.b = (pix & 0xF) << 4;
        }
        break;
    }
done:
    return *(u32 *)&color;
}
/* fzgx:end fn_3_149AC */

/* fzgx:begin fn_3_14BBC */
extern u16 lbl_3_bss_A23D8;
extern u32 lbl_3_bss_A23E0;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_3_14BBC_Color;

/* colour c as a texel: RGB565, or RGB5A3 (opaque with 5 bits per colour from alpha 0xE0 up, otherwise 3 bits of
 * alpha and 4 bits per colour) */
#define RGB565(c) ((u16)((((c).r & 0xF8) << 8) | (((c).g & 0xFC) << 3) | (((c).b & 0xF8) >> 3)))
#define RGB5A3(c)                                                                                      \
    ((c).a >= 0xE0 ? (((c).r & 0xF8) << 7) | (((c).g & 0xF8) << 2) | (((c).b & 0xF8) >> 3) | 0x8000 \
                   : (((c).r & 0xF0) << 4) | ((c).g & 0xF0) | (((c).b & 0xF0) >> 4) | (((c).a & 0xE0) << 7))

/* writes colour c into the canvas pixel at (x, y); lbl_3_bss_A23D8 holds the canvas width and lbl_3_bss_A23E0 its
 * texture format (4 RGB565, 5 RGB5A3), pixels in 4 x 4 tiles of 16-bit texels */
static inline void put_pixel(u8 *canvas, s16 x, s16 y, fn_3_14BBC_Color c) {
    s16 offset;
    s16 bx;
    s16 by;
    s16 bw;
    s16 px;
    s16 py;
    s16 blk;

    switch (lbl_3_bss_A23E0) {
    case 4:
        bx = x / 4;
        by = y / 4;
        bw = lbl_3_bss_A23D8 / 4;
        px = x % 4;
        py = y % 4;
        blk = bx + by * bw;
        offset = blk * 32 + (px + py * 4) * 2;
        memset(&canvas[offset], (u8)(RGB565(c) >> 8), 1);
        memset(&canvas[offset + 1], (u8)RGB565(c), 1);
        break;
    case 5:
        bx = x >> 2;
        by = y >> 2;
        bw = lbl_3_bss_A23D8 >> 2;
        px = x & 3;
        py = y & 3;
        blk = bx + by * bw;
        offset = blk * 32 + (px + py * 4) * 2;
        canvas[offset] = (u16)RGB5A3(c) >> 8;
        canvas[offset + 1] = RGB5A3(c);
        break;
    case 6: /* empty in retail too: its compare tree tests 4, 5 and 6 */
        break;
    }
}

/* writes *color into n canvas pixels from (x, y) along the row */
void fn_3_14BBC(u8 *canvas, s16 x, s16 y, s16 n, fn_3_14BBC_Color *color) {
    s16 i;

    for (i = 0; i < n; i++) {
        put_pixel(canvas, x + i, y, *color);
    }
}
/* fzgx:end fn_3_14BBC */

/* fzgx:begin fn_3_14E18 */
extern u16 lbl_3_bss_A23D8;
extern u32 lbl_3_bss_A23E0;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_3_14E18_Color;

/* colour c as a texel: RGB565, or RGB5A3 (opaque with 5 bits per colour from alpha 0xE0 up, otherwise 3 bits of
 * alpha and 4 bits per colour) */
#define RGB565(c) ((u16)((((c).r & 0xF8) << 8) | (((c).g & 0xFC) << 3) | (((c).b & 0xF8) >> 3)))
#define RGB5A3(c)                                                                                      \
    ((c).a >= 0xE0 ? (((c).r & 0xF8) << 7) | (((c).g & 0xF8) << 2) | (((c).b & 0xF8) >> 3) | 0x8000 \
                   : (((c).r & 0xF0) << 4) | ((c).g & 0xF0) | (((c).b & 0xF0) >> 4) | (((c).a & 0xE0) << 7))

/* writes colour c into the canvas pixel at (x, y); lbl_3_bss_A23D8 holds the canvas width and lbl_3_bss_A23E0 its
 * texture format (4 RGB565, 5 RGB5A3), pixels in 4 x 4 tiles of 16-bit texels (fn_3_14BBC's helper) */
static inline void put_pixel(u8 *canvas, s16 x, s16 y, fn_3_14E18_Color c) {
    s16 offset;
    s16 bx;
    s16 by;
    s16 bw;
    s16 px;
    s16 py;
    s16 blk;
    u32 texel; /* u32: as u16 the second call keeps it in another register than retail */

    switch (lbl_3_bss_A23E0) {
    case 4:
        bx = x / 4;
        by = y / 4;
        bw = lbl_3_bss_A23D8 / 4;
        px = x % 4;
        py = y % 4;
        blk = bx + by * bw;
        offset = blk * 32 + (px + py * 4) * 2;
        texel = RGB565(c);
        memset(&canvas[offset], (u8)(texel >> 8), 1);
        memset(&canvas[offset + 1], (u8)texel, 1);
        break;
    case 5:
        bx = x >> 2;
        by = y >> 2;
        bw = lbl_3_bss_A23D8 >> 2;
        px = x & 3;
        py = y & 3;
        blk = bx + by * bw;
        offset = blk * 32 + (px + py * 4) * 2;
        canvas[offset] = (u16)RGB5A3(c) >> 8;
        canvas[offset + 1] = RGB5A3(c);
        break;
    case 6: /* empty in retail too: its compare tree tests 4, 5 and 6 */
        break;
    }
}

/* swaps the canvas pixels at (x0, y0) and (x1, y1) */
void fn_3_14E18(u8 *canvas, s16 x0, s16 y0, s16 x1, s16 y1) {
    fn_3_14E18_Color c1;
    fn_3_14E18_Color c0;

    *(u32 *)&c0 = fn_3_149AC(canvas, x0, y0);
    *(u32 *)&c1 = fn_3_149AC(canvas, x1, y1);
    put_pixel(canvas, x0, y0, c1);
    put_pixel(canvas, x1, y1, c0);
}
/* fzgx:end fn_3_14E18 */

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

/* fzgx:begin fn_3_152BC */
extern u16 lbl_3_bss_A23D8;
extern u32 lbl_3_bss_A23E0;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_3_152BC_Color;

/* colour c as a texel: RGB565, or RGB5A3 (opaque with 5 bits per colour from alpha 0xE0 up, otherwise 3 bits of
 * alpha and 4 bits per colour) */
#define RGB565(c) ((u16)((((c).r & 0xF8) << 8) | (((c).g & 0xFC) << 3) | (((c).b & 0xF8) >> 3)))
#define RGB5A3(c)                                                                                      \
    ((c).a >= 0xE0 ? (((c).r & 0xF8) << 7) | (((c).g & 0xF8) << 2) | (((c).b & 0xF8) >> 3) | 0x8000 \
                   : (((c).r & 0xF0) << 4) | ((c).g & 0xF0) | (((c).b & 0xF0) >> 4) | (((c).a & 0xE0) << 7))

/* writes colour c into the canvas pixel at (x, y); lbl_3_bss_A23D8 holds the canvas width and lbl_3_bss_A23E0 its
 * texture format (4 RGB565, 5 RGB5A3), pixels in 4 x 4 tiles of 16-bit texels */
static inline void put_pixel(u8 *canvas, s16 x, s16 y, fn_3_152BC_Color c) {
    s16 offset;
    s16 bx;
    s16 by;
    s16 bw;
    s16 px;
    s16 py;
    s16 blk;

    switch (lbl_3_bss_A23E0) {
    case 4:
        bx = x / 4;
        by = y / 4;
        bw = lbl_3_bss_A23D8 / 4;
        px = x % 4;
        py = y % 4;
        blk = bx + by * bw;
        offset = blk * 32 + (px + py * 4) * 2;
        memset(&canvas[offset], (u8)(RGB565(c) >> 8), 1);
        memset(&canvas[offset + 1], (u8)RGB565(c), 1);
        break;
    case 5:
        bx = x >> 2;
        by = y >> 2;
        bw = lbl_3_bss_A23D8 >> 2;
        px = x & 3;
        py = y & 3;
        blk = bx + by * bw;
        offset = blk * 32 + (px + py * 4) * 2;
        canvas[offset] = (u16)RGB5A3(c) >> 8;
        canvas[offset + 1] = RGB5A3(c);
        break;
    case 6: /* empty in retail too: its compare tree tests 4, 5 and 6 */
        break;
    }
}

/* fills the canvas pixels x0 <= x < x1, y0 <= y < y1 with *color, column by column */
void fn_3_152BC(u8 *canvas, s16 y0, s16 x0, s16 y1, s16 x1, fn_3_152BC_Color *color) {
    s16 x;
    s16 y;

    for (x = x0; x < x1; x++) {
        for (y = y0; y < y1; y++) {
            put_pixel(canvas, x, y, *color);
        }
    }
}
/* fzgx:end fn_3_152BC */
