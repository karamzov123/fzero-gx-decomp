#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/toolkit.h"


extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, int);
extern const f32 lbl_3_rodata_740;
extern void fn_3_1ABD8(void *arg0, s16 x1, s16 y1, s16 x2, s16 y2, u32 *value);
extern void fn_3_1B130(void *, s16, s16, u32 *);
extern void fn_3_149AC(void);
extern void fn_3_1BA20(void *target, s16 x, s16 y, s16 z, s16 w, s32 *value);
extern void fn_3_1BF08(void *, s16, s16, s16, s16, u32 *);
extern u8 lbl_3_bss_A2458[8];
extern void fn_3_BD98(void);
extern void fn_3_BEF0(void);
extern void fn_3_BE88(void);
extern void fn_3_156A8(void);
extern void fn_80074188(s16, s16, s16, s16);
extern void fn_1_5233C(void *, void *);
extern struct fn_3_1A1D8_lbl_1_bss_9F8 lbl_1_bss_9F8;

/* fzgx:begin fn_3_19C50 */
void fn_3_19C50(void) {
    fn_1_46B4(lbl_801A6410, lbl_3_bss_A2454, lbl_3_data_3D14, 0x294);
}
/* fzgx:end fn_3_19C50 */

/* fzgx:begin fn_3_19C94 noprologue */
#include "types.h"

extern u8 lbl_3_bss_A2438[28];

u8 fn_3_19C94(void) {
    return lbl_3_bss_A2438[0xe];
}
/* fzgx:end fn_3_19C94 */

/* fzgx:begin fn_3_19CA4 noprologue */
#include "types.h"

extern u8 lbl_3_bss_A2438[28];

void fn_3_19CA4(void) {
    *(u32 *)(lbl_3_bss_A2438 + 4) = (u32)-2147483648;
}
/* fzgx:end fn_3_19CA4 */

/* fzgx:begin fn_3_19CB8 noprologue */
#include "types.h"

extern u8 lbl_3_bss_A2438[28];

void fn_3_19CB8(void) {
    *(u32 *)(lbl_3_bss_A2438 + 4) = 0x20000000;
}
/* fzgx:end fn_3_19CB8 */

/* fzgx:begin fn_3_19CCC noprologue */
#include "types.h"

extern u8 lbl_3_bss_A2438[28];

void fn_3_19CCC(void) {
    *(u32 *)(lbl_3_bss_A2438 + 4) = 0x40000000;
}
/* fzgx:end fn_3_19CCC */

/* fzgx:begin fn_3_19CE0 */
u32 fn_3_19CE0(void) {
    u32 v0;
    s32 v1;

    v1 = 0;
    v0 = *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A2438) + 4);
    if (v0 == 0x80000000 || v0 == 0x40000000) {
        v1 = 1;
    }
    return (v1 & 0xFF);
}
/* fzgx:end fn_3_19CE0 */

/* fzgx:begin fn_3_19D14 */
typedef struct fn_3_19D14_CustomizeData {
    u8 _pad08[0x08];
    u32 value_08;
    u8 _pad0c[0x04];
    s16 value_10;
    s16 value_12;
    u8 _pad14[0x0c];
    void *value_20;
} fn_3_19D14_CustomizeData;

extern void fn_3_1AB34(void *, s16, s16, u32 *);

void fn_3_19D14(fn_3_19D14_CustomizeData *data) {
    u32 value = data->value_08;
    fn_3_1AB34(data->value_20, data->value_10, data->value_12, &value);
}
/* fzgx:end fn_3_19D14 */

/* fzgx:begin fn_3_19D50 noprologue */
#include "types.h"

extern u8 lbl_3_bss_A2438[28];

void fn_3_19D50(void) {
    lbl_3_bss_A2438[12] = (lbl_3_bss_A2438[12] + 1) % 5;
}
/* fzgx:end fn_3_19D50 */

/* fzgx:begin fn_3_19D88 */
typedef struct Fn319D88Object {
    u8 pad_00[0x10];
    s16 value_10;
    s16 value_12;
    u8 pad_14[0x0c];
    void *value_20;
} Fn319D88Object;

void fn_3_19D88(Fn319D88Object *object) {
    u32 value = *(const u32 *)&lbl_3_rodata_740;
    fn_3_1AB34(object->value_20, object->value_10, object->value_12,
               (const f32 *)&value);
}
/* fzgx:end fn_3_19D88 */

/* fzgx:begin fn_3_19DC8 */
extern u32 fn_3_17820(void *);
extern void fn_3_1ADA4(void *, int, int, int, int);
extern void fn_3_1AE40(void *, int, int, int, int);

typedef struct Fn319DC8Object {
    u8 pad_00[0x04];
    u32 flags_04;
    u32 value_08;
    u8 pad_0c[0x14];
    void *value_20;
} Fn319DC8Object;

void fn_3_19DC8(Fn319DC8Object *object) {
    object->value_08 = fn_3_17820(object);
    if (object->flags_04 & 0xc0000000u) {
        fn_3_1ADA4(object->value_20, 0, 0, 64, 64);
    } else if (object->flags_04 & 0x30000000u) {
        fn_3_1AE40(object->value_20, 0, 0, 64, 64);
    }
}
/* fzgx:end fn_3_19DC8 */

/* fzgx:begin fn_3_19E40 */
typedef struct CustomizeData {
    u32 unk_00[2];
    u32 unk_08;
    u8 pad_0c[0x14];
    void *unk_20;
} CustomizeData;

extern u32 fn_3_17820(CustomizeData *);
extern void fn_3_1AEE4(void *, u32, u32, u32, u32);
extern void fn_3_1B008(void *, u32, u32, u32, u32);

void fn_3_19E40(CustomizeData *self) {
    self->unk_08 = fn_3_17820(self);
    if (self->unk_00[1] & 0x20000000) {
        fn_3_1AEE4(self->unk_20, 0, 0, 0x40, 0x40);
    } else if (self->unk_00[1] & 0x10000000) {
        fn_3_1B008(self->unk_20, 0, 0, 0x40, 0x40);
    }
}
/* fzgx:end fn_3_19E40 */

/* fzgx:begin fn_3_19EB8 */
typedef struct fn_3_19EB8_CustomizeData {
    u32 unk_00[2];
    u32 unk_08;
    s16 unk_0c;
    s16 unk_0e;
    s16 unk_10;
    s16 unk_12;
    u8 unk_14[0x0c];
    void *unk_20;
} fn_3_19EB8_CustomizeData;

void fn_3_19EB8(fn_3_19EB8_CustomizeData *self) {
    u32 local = self->unk_08;
    fn_3_1ABD8(self->unk_20, self->unk_0c, self->unk_0e, self->unk_10, self->unk_12, &local);
}
/* fzgx:end fn_3_19EB8 */

/* fzgx:begin fn_3_19EFC */
typedef struct fn_3_19EFC_CustomizeTool {
    u8 unk00[8];
    u32 unk08;
    s16 unk0c;
    s16 unk0e;
    s16 unk10;
    s16 unk12;
    u8 unk14[12];
    void *unk20;
} fn_3_19EFC_CustomizeTool;

void fn_3_19EFC(fn_3_19EFC_CustomizeTool *self) {
    u32 value = self->unk08;
    fn_3_1ACE4(self->unk20, self->unk0c, self->unk0e, self->unk10, self->unk12, &value);
}
/* fzgx:end fn_3_19EFC */

/* fzgx:begin fn_3_19F40 */
typedef struct fn_3_19F40_CustomizeObject {
    u8 pad08[8];
    u32 value08;
    u8 pad0c[4];
    s16 value10;
    s16 value12;
    u8 pad14[12];
    void *value20;
} fn_3_19F40_CustomizeObject;

void fn_3_19F40(fn_3_19F40_CustomizeObject *self) {
    u32 value;
    value = self->value08;
    fn_3_1B130(self->value20, self->value10, self->value12, &value);
}
/* fzgx:end fn_3_19F40 */

/* fzgx:begin fn_3_19F7C */
void fn_3_19F7C(void) {
    fn_3_149AC();
}
/* fzgx:end fn_3_19F7C */

/* fzgx:begin fn_3_19F9C */
typedef struct fn_3_19F9C_CustomizeTool {
    u8 pad00[8];
    u32 value08;
    s16 value0c;
    s16 value0e;
    s16 value10;
    s16 value12;
    u8 pad14[12];
    void *value20;
} fn_3_19F9C_CustomizeTool;

void fn_3_19F9C(fn_3_19F9C_CustomizeTool *tool) {
    u32 value;

    value = tool->value08;
    fn_3_1B4BC(tool->value20, tool->value0c, tool->value0e,
               tool->value10, tool->value12, &value);
}
/* fzgx:end fn_3_19F9C */

/* fzgx:begin fn_3_19FE0 */
typedef struct Fn319FE0Data {
    u8 _pad0[0x8];
    s32 value;
    s16 x;
    s16 y;
    s16 z;
    s16 w;
    u8 _pad14[0xC];
    void *target;
} Fn319FE0Data;

void fn_3_19FE0(Fn319FE0Data *data) {
    s32 value = data->value;
    fn_3_1BA20(data->target, data->x, data->y, data->z, data->w, &value);
}
/* fzgx:end fn_3_19FE0 */

/* fzgx:begin fn_3_1A024 */
typedef struct Fn3_1A024Data {
    u8 pad_00[8];
    u32 value_08;
    s16 value_0c;
    s16 value_0e;
    s16 value_10;
    s16 value_12;
    u8 pad_14[12];
    void *value_20;
} Fn3_1A024Data;

void fn_3_1A024(Fn3_1A024Data *data) {
    u32 value = data->value_08;
    fn_3_1BF08(data->value_20, data->value_0c, data->value_0e,
               data->value_10, data->value_12, &value);
}
/* fzgx:end fn_3_1A024 */

/* fzgx:begin fn_3_1A068 noprologue */
#include "types.h"

extern u8 lbl_3_bss_A2438[28];
extern u8 lbl_3_bss_A2458[8];
extern void fn_3_BD98(void);
extern s32 lbl_3_bss_A179C;
extern void fn_3_BEF0(void);
extern void fn_3_BE88(void);

void fn_3_1A068(void) {
    if (lbl_3_bss_A2458[0] != 0) {
        fn_3_BD98();
        lbl_3_bss_A2458[0] = 0;
    } else if (lbl_3_bss_A179C != 0) {
        fn_3_BEF0();
        lbl_3_bss_A2458[0] = 1;
        *(u32 *)&lbl_3_bss_A2438[4] = 0x40000000;
        lbl_3_bss_A2438[0xE] = 0;
        lbl_3_bss_A179C = 0;
    } else {
        fn_3_BE88();
    }
}
/* fzgx:end fn_3_1A068 */

/* fzgx:begin fn_3_1A0F4 noprologue */
#include "types.h"

typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    u32 unk_4;
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
    u8 unk_10;
    u8 pad_11[1];
    s16 unk_12;
    u8 unk_14;
    u8 unk_15;
    s16 unk_16;
    s16 unk_18;
    s16 unk_1A;
} Obj_1A0F4;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
Obj_1A0F4 fzgx_obj_lbl_3_bss_A2438;
u32 fzgx_obj_lbl_3_bss_A2454;
u8 fzgx_obj_lbl_3_bss_A2458;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_3_bss_A2438.unk_0;
    s = fzgx_obj_lbl_3_bss_A2454;
    s = fzgx_obj_lbl_3_bss_A2458;
}
#pragma section code_type ".text"
extern s32 lbl_3_bss_A179C;
extern void fn_3_BE10(void);
extern void fn_3_BEF0(void);
extern void fn_3_1445C(void);
extern void fn_3_BE88(void);
extern void fn_80008BA8(u32, u32, u32);
extern s32 fn_8008023C(u32, u32, u32);

void fn_3_1A0F4(u8 *arg0) {
    if (fzgx_obj_lbl_3_bss_A2458 != 0) {
        fn_80008BA8(fzgx_obj_lbl_3_bss_A2454, *(u32 *)(arg0 + 0x20), 0x2000);
        fn_3_BE10();
        fzgx_obj_lbl_3_bss_A2458 = 0;
    } else if (lbl_3_bss_A179C != 0) {
        fn_3_BEF0();
        fzgx_obj_lbl_3_bss_A2458 = 1;
        fzgx_obj_lbl_3_bss_A2438.unk_4 = 0x40000000;
        fzgx_obj_lbl_3_bss_A2438.unk_E = 0;
        lbl_3_bss_A179C = 0;
        if (fn_8008023C(fzgx_obj_lbl_3_bss_A2454, *(u32 *)(arg0 + 0x20), 0x2000) != 0) {
            fn_3_1445C();
        }
    } else {
        fn_3_BE88();
    }
}
/* fzgx:end fn_3_1A0F4 */

/* fzgx:begin fn_3_1A1B8 */
void fn_3_1A1B8(void) {
    fn_3_156A8();
}
/* fzgx:end fn_3_1A1B8 */

/* fzgx:begin fn_3_1A1D8 */
#include "types.h"




extern u32 fn_3_141A8(u32);
extern u32 fn_3_1441C(void);

struct fn_3_1A1D8_lbl_1_bss_9F8_0_E20 {
    u8 pad_0[0x10];
    u16 unk_10;
    u8 pad_12[0x2];
};
struct fn_3_1A1D8_lbl_3_bss_A2438 {
    u8 unk_0;
    u8 pad_1[0x3];
    u32 unk_4;
    u8 pad_8[0x6];
    u8 unk_E;
};
struct fn_3_1A1D8_lbl_1_bss_9F8 {
    struct fn_3_1A1D8_lbl_1_bss_9F8_0_E20 unk_0[1];
};

u32 fn_3_1A1D8(void) {
    u32 v0;
    u32 t0, t1;
    if (((lbl_1_bss_9F8.unk_0[(*(struct fn_3_1A1D8_lbl_3_bss_A2438 *)&lbl_3_bss_A2438).unk_0].unk_10 >> 8) & 0x1) != 0) {
    t0 = fn_3_1441C();
    v0 = t0;
    if ((t0 & 0xFF) == 0) {
    v0 = 0x80000000;
    t1 = fn_3_141A8(v0);
    v0 = t1;
    }
    }
    v0 = (u32)&lbl_1_bss_9F8;
    v0 = (u32)((u8 *)v0 + ((*(struct fn_3_1A1D8_lbl_3_bss_A2438 *)&lbl_3_bss_A2438).unk_0 * 20));
    if (((*(u16 *)((u8 *)v0 + 8) >> 9) & 0x1) != 0) {
    v0 = 0x40000000;
    (*(struct fn_3_1A1D8_lbl_3_bss_A2438 *)&lbl_3_bss_A2438).unk_4 = v0;
    (*(struct fn_3_1A1D8_lbl_3_bss_A2438 *)&lbl_3_bss_A2438).unk_E = 0;
    }
    return v0;
}
/* fzgx:end fn_3_1A1D8 */

/* fzgx:begin fn_3_1A264 noprologue */
#include "types.h"

struct fn_3_1A264_lbl_1_bss_9F8_10_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};
struct fn_3_1A264_lbl_3_bss_A2438 {
    u8 unk_0;
    u8 pad_1[0x3];
    u32 unk_4;
    u8 pad_8[0x6];
    u8 unk_E;
};
struct fn_3_1A264_lbl_1_bss_9F8 {
    u8 pad_0[0x10];
    struct fn_3_1A264_lbl_1_bss_9F8_10_E20 unk_10[1];
};

extern struct fn_3_1A264_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern struct fn_3_1A264_lbl_3_bss_A2438 lbl_3_bss_A2438;
extern u32 fn_3_141A8(u32);
extern u32 fn_3_1443C(void);

void fn_3_1A264(u32 arg0) {
    u32 v0;
    u32 v1;
    u32 t0, t1;
    if (((lbl_1_bss_9F8.unk_10[lbl_3_bss_A2438.unk_0].unk_0 >> 8) & 0x1) != 0) {
    t0 = fn_3_1443C();
    v0 = t0;
    if ((t0 & 0xFF) == 0) {
    v0 = 0x40000000;
    t1 = fn_3_141A8(v0);
    v0 = t1;
    }
    }
    v1 = arg0;
    if (((lbl_1_bss_9F8.unk_10[lbl_3_bss_A2438.unk_0].unk_0 >> 9) & 0x1) != 0) {
    v1 = 0x40000000;
    lbl_3_bss_A2438.unk_4 = v1;
    lbl_3_bss_A2438.unk_E = 0;
    }
}
/* fzgx:end fn_3_1A264 */

/* fzgx:begin fn_3_1A2EC noprologue */
#include "types.h"

typedef struct {
    u16 flags;
    u8 pad[18];
} CustomizeEntry;

struct QView {
    u8 unk_0;
    u8 pad_1[0x3];
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x2];
    u8 unk_E;
    u8 pad_F[0x1];
    u8 unk_10;
};

extern u8 lbl_1_bss_9F8[];
extern u8 lbl_3_bss_A2438[28];
extern void fn_1_A2D84(u32);
extern void fn_3_14008(void);

void fn_3_1A2EC(void) {
    CustomizeEntry *entries;
    CustomizeEntry *entries_alt;
    u8 index;
    u32 flags;
    struct QView *st;

    entries = (CustomizeEntry *)(lbl_1_bss_9F8 + 0x10);
    index = lbl_3_bss_A2438[0];
    if ((entries[index].flags & 1) == 0) {
        if ((*(u16 *)(lbl_1_bss_9F8 + 0x12 + index * 20) & 1) == 0) {
            goto after_enable; /* Keep the verified branch to after_enable. */
        }
    }

    if (lbl_3_bss_A2438[0x10] == 0) {
        fn_1_A2D84(0xA9010000);
    }
    lbl_3_bss_A2438[0x10] = 1;

after_enable:
    index = lbl_3_bss_A2438[0];
    flags = (u16)(entries[index].flags);
    if (((flags >> 1) & 1) == 0 &&
        (((*(u16 *)(lbl_1_bss_9F8 + 0x12 + index * 20) >> 1) & 1) == 0)) {
        goto after_disable; /* Keep the verified branch to after_disable. */
    }

    if (lbl_3_bss_A2438[0x10] != 0) {
        fn_1_A2D84(0xA9010000);
    }
    lbl_3_bss_A2438[0x10] = 0;

after_disable:
    entries_alt = (CustomizeEntry *)(lbl_1_bss_9F8 + 8);
    index = lbl_3_bss_A2438[0];
    flags = (u16)(entries_alt[index].flags);
    if (((flags >> 8) & 1) != 0 && lbl_3_bss_A2438[0x10] != 0) {
        fn_1_A2D84(0xA9150400);
        *(u32 *)&lbl_3_bss_A2438[4] = 0x40000000;
        lbl_3_bss_A2438[0xE] = 0;
        fn_3_14008();
        lbl_3_bss_A2438[0x10] = 0;
    }

    st = (struct QView *)lbl_3_bss_A2438;
    flags = (u16)(entries_alt[st->unk_0].flags);
    if (((flags >> 9) & 1) != 0 ||
        (st->unk_10 == 0 && ((flags >> 8) & 1) != 0)) {
        fn_1_A2D84(0xA9150500);
        *(u32 *)&lbl_3_bss_A2438[4] = 0x40000000;
        lbl_3_bss_A2438[0xE] = 0;
        *(u32 *)&lbl_3_bss_A2438[8] &= 0xBFFFFFFF;
    }
}
/* fzgx:end fn_3_1A2EC */

/* fzgx:begin fn_3_1A488 noprologue */
#include "types.h"
#include "rel/customize/toolkit.h"

struct fn_3_1A488_lbl_1_bss_9F8_8_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};
struct fn_3_1A488_lbl_1_bss_9F8 {
    u8 pad_0[0x8];
    struct fn_3_1A488_lbl_1_bss_9F8_8_E20 unk_8[1];
};
extern struct fn_3_1A488_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern u32 fn_3_1401C(void);
extern void fn_3_1445C(void);
extern u32 fn_3_152BC(u32, u32, u32, u32, u32, void *);
extern u32 lbl_3_rodata_744[9];
extern void fn_1_A2D84(u32);

#pragma opt_pointer_analysis on
#pragma opt_propagation off
void fn_3_1A488(void) {
    struct fn_3_1A488_lbl_1_bss_9F8_8_E20 *entries;
    s32 v1;
    u16 v0;
    u32 v2;
    u32 v3;
    struct { u32 a[4]; } loc_8;
    u32 t3;
    entries = (struct fn_3_1A488_lbl_1_bss_9F8_8_E20 *)((u8 *)&lbl_1_bss_9F8 + 16);
    v0 = *(volatile u8 *)&lbl_3_bss_A2438.unk_0; /* Retail reloads this field. */
    if ((entries[v0].unk_0 & 1) != 0 ||
        (((1) & (*(u16 *)((u8 *)&lbl_1_bss_9F8 + v0 * 20 + 18)))) != 0) {
        Obj_3_bss_A2438 *st = &lbl_3_bss_A2438;
        if (st->unk_10 == 0) {
            fn_1_A2D84(0xA9010000);
        }
        st->unk_10 = 1;
    }
    v1 = lbl_3_bss_A2438.unk_0;
    if (((entries[v1].unk_0 >> 1) & 1) != 0 ||
        ((*(u16 *)((u8 *)&lbl_1_bss_9F8 + v1 * 20 + 18) >> 1) & 1) != 0) {
        Obj_3_bss_A2438 *st = &lbl_3_bss_A2438;
        if (st->unk_10 != 0) {
            fn_1_A2D84(0xA9010000);
        }
        st->unk_10 = 0;
    }
    entries = (struct fn_3_1A488_lbl_1_bss_9F8_8_E20 *)((u8 *)&lbl_1_bss_9F8 + 8);
    {
        Obj_3_bss_A2438 *st = &lbl_3_bss_A2438;
        if (((st->unk_0[entries].unk_0 >> 8) & 1) != 0 &&
            st->unk_10 != 0) {
            loc_8.a[1] = lbl_3_rodata_744[0];
            fn_1_A2D84(0xA9150400);
            lbl_3_bss_A2438.unk_4 = 0x40000000;
            lbl_3_bss_A2438.unk_E = 0;
            loc_8.a[0] = loc_8.a[1];
            t3 = fn_3_1401C();
            fn_3_152BC(t3, 0, 0, 64, 64, &loc_8);
            st->unk_10 = 0;
            fn_3_1445C();
        }
    }
    {
        Obj_3_bss_A2438 *st = &lbl_3_bss_A2438;
        v2 = (u16)((*(volatile u8 *)&st->unk_0 /* Retail reloads this field. */)[entries]).unk_0;
        if (((v2 >> 9) & 1) != 0 ||
            (st->unk_10 == 0 && ((v2 >> 8) & 1) != 0)) {
            fn_1_A2D84(0xA9150500);
            lbl_3_bss_A2438.unk_4 = 0x40000000;
            lbl_3_bss_A2438.unk_E = 0;
        }
    }
}

#pragma opt_propagation reset

#pragma opt_pointer_analysis reset
/* fzgx:end fn_3_1A488 */

/* fzgx:begin fn_3_1A648 noprologue */
#include "types.h"
#include "rel/customize/toolkit.h"

struct fn_3_1A648_lbl_1_bss_9F8_8_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};

struct fn_3_1A648_lbl_1_bss_9F8 {
    u8 pad_0[0x8];
    struct fn_3_1A648_lbl_1_bss_9F8_8_E20 unk_8[1];
};

extern struct fn_3_1A648_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern u8 fn_3_14064(void);
extern u32 fn_3_1401C(void);
extern u32 fn_3_1402C(u8);
extern void fn_3_1445C(void);
extern void fn_1_A2D84(u32);
extern void fn_80008BA8(u32, u32, u32);
extern void fn_80008BEC(void *, int, u32);

#pragma opt_pointer_analysis on
#pragma opt_propagation off
void fn_3_1A648(void) {
    struct fn_3_1A648_lbl_1_bss_9F8_8_E20 *entries;
    u32 t3;
    u32 t4;
    struct fn_3_1A648_lbl_1_bss_9F8_8_E20 *entries_2;
    u32 t5;

    entries = (struct fn_3_1A648_lbl_1_bss_9F8_8_E20 *)((u8 *)&lbl_1_bss_9F8 + 0x10);

    if ((entries[lbl_3_bss_A2438.unk_0].unk_0 & 1) != 0 ||
        (*(u16 *)((u8 *)&lbl_1_bss_9F8 + lbl_3_bss_A2438.unk_0 * 0x14 + 0x12) & 1) != 0) {
        if (__rlwnm(lbl_3_bss_A2438.unk_8, 2, 31, 31)) {
            if (lbl_3_bss_A2438.unk_10 == 0) {
                fn_1_A2D84(0xA9010000);
            }
            lbl_3_bss_A2438.unk_10 = 1;
        } else if (lbl_3_bss_A2438.unk_14 != 0) {
            fn_1_A2D84(0xA9150600);
            lbl_3_bss_A2438.unk_14--;
        }
    }

    if (((entries[lbl_3_bss_A2438.unk_0].unk_0 >> 1) & 1) != 0 ||
        ((*(u16 *)((u8 *)&lbl_1_bss_9F8 + lbl_3_bss_A2438.unk_0 * 0x14 + 0x12) >> 1) & 1) != 0) {
        if (__rlwnm(lbl_3_bss_A2438.unk_8, 2, 31, 31)) {
            if (lbl_3_bss_A2438.unk_10 != 0) {
                fn_1_A2D84(0xA9010000);
            }
            lbl_3_bss_A2438.unk_10 = 0;
        } else if (lbl_3_bss_A2438.unk_14 < 4) {
            t3 = fn_3_14064();
            if (((1) + (((lbl_3_bss_A2438.unk_14) + ((lbl_3_bss_A2438.unk_15 * 5) + (lbl_3_bss_A2438.unk_12))))) < (s32)(t3 & 0xFF)) {
                fn_1_A2D84(0xA9150600);
                lbl_3_bss_A2438.unk_14++;
            }
        }
    }

    if (((entries[lbl_3_bss_A2438.unk_0].unk_0 >> 3) & 1) != 0 ||
        ((*(u16 *)((u8 *)&lbl_1_bss_9F8 + lbl_3_bss_A2438.unk_0 * 0x14 + 0x12) >> 3) & 1) != 0) {
        if (!__rlwnm(lbl_3_bss_A2438.unk_8, 2, 31, 31)) {
            if (lbl_3_bss_A2438.unk_15 != 0) {
                fn_1_A2D84(0xA9150600);
                lbl_3_bss_A2438.unk_15--;
            } else if (lbl_3_bss_A2438.unk_12 - 5 >= 0) {
                fn_1_A2D84(0xA9150600);
                lbl_3_bss_A2438.unk_1A = 10;
                lbl_3_bss_A2438.unk_18 = 0;
                lbl_3_bss_A2438.unk_12 = lbl_3_bss_A2438.unk_12 - 5;
            }
        }
    }

    if (((entries[lbl_3_bss_A2438.unk_0].unk_0 >> 2) & 1) != 0 ||
        ((*(u16 *)((u8 *)&lbl_1_bss_9F8 + lbl_3_bss_A2438.unk_0 * 0x14 + 0x12) >> 2) & 1) != 0) {
        if (!__rlwnm(lbl_3_bss_A2438.unk_8, 2, 31, 31)) {
            t3 = fn_3_14064();
            if (lbl_3_bss_A2438.unk_12 + 20 < (s32)(t3 & 0xFF)) {
                if (lbl_3_bss_A2438.unk_15 < 3) {
                    fn_1_A2D84(0xA9150600);
                    lbl_3_bss_A2438.unk_15++;
                } else {
                    fn_1_A2D84(0xA9150600);
                    lbl_3_bss_A2438.unk_18 = 10;
                    lbl_3_bss_A2438.unk_1A = 0;
                    lbl_3_bss_A2438.unk_12 = lbl_3_bss_A2438.unk_12 + 5;
                    t3 = fn_3_14064();
                    if ((((lbl_3_bss_A2438.unk_14) + (lbl_3_bss_A2438.unk_15 * 5)) +
                            (lbl_3_bss_A2438.unk_12)) >= (s32)(t3 & 0xFF)) {
                        lbl_3_bss_A2438.unk_15--;
                    }
                }
            } else if (lbl_3_bss_A2438.unk_15 < 3) {
                t3 = fn_3_14064();
                if (((lbl_3_bss_A2438.unk_12) + (((lbl_3_bss_A2438.unk_15 + 1) * 5) +
                        (lbl_3_bss_A2438.unk_14))) < (s32)(t3 & 0xFF)) {
                    fn_1_A2D84(0xA9150600);
                    lbl_3_bss_A2438.unk_15++;
                }
            }
        }
    }

    entries_2 = (struct fn_3_1A648_lbl_1_bss_9F8_8_E20 *)((u8 *)&lbl_1_bss_9F8 + 8);

    if (((entries_2[lbl_3_bss_A2438.unk_0].unk_0 >> 8) & 1) != 0) {
        t4 = fn_3_1401C();
        t5 = fn_3_1402C((u8)((((lbl_3_bss_A2438.unk_12) + (lbl_3_bss_A2438.unk_14)) +
                              (lbl_3_bss_A2438.unk_15 * 5))));
        if (!__rlwnm(lbl_3_bss_A2438.unk_8, 2, 31, 31)) {
            lbl_3_bss_A2438.unk_8 = lbl_3_bss_A2438.unk_8 | 0x40000000;
        } else if (lbl_3_bss_A2438.unk_10 != 0) {
            if (t5 != 0) {
                fn_80008BA8(t4, t5, 0x2000);
            } else {
                fn_80008BEC((void *)t4, 0, 1);
            }
            lbl_3_bss_A2438.unk_8 = lbl_3_bss_A2438.unk_8 & ~0x40000000;
            lbl_3_bss_A2438.unk_4 = 0x40000000;
            lbl_3_bss_A2438.unk_E = 0;
            lbl_3_bss_A2438.unk_10 = 0;
            fn_3_1445C();
            fn_1_A2D84(0xA9150400);
        } else {
            lbl_3_bss_A2438.unk_8 = lbl_3_bss_A2438.unk_8 & ~0x40000000;
            lbl_3_bss_A2438.unk_10 = 0;
        }
    }

    if (((entries_2[lbl_3_bss_A2438.unk_0].unk_0 >> 9) & 1) != 0) {
        if (__rlwnm(lbl_3_bss_A2438.unk_8, 2, 31, 31)) {
            lbl_3_bss_A2438.unk_8 = lbl_3_bss_A2438.unk_8 & ~0x40000000;
            lbl_3_bss_A2438.unk_10 = 0;
        } else {
            lbl_3_bss_A2438.unk_10 = 0;
            fn_1_A2D84(0xA9150500);
            lbl_3_bss_A2438.unk_4 = 0x40000000;
            lbl_3_bss_A2438.unk_E = 0;
        }
    }
}
#pragma opt_propagation reset
#pragma opt_pointer_analysis reset
/* fzgx:end fn_3_1A648 */

/* fzgx:begin fn_3_1AB34 */
extern void fn_3_146C0(void *, s16, s16, s16, u32 *);

void fn_3_1AB34(void *obj, s16 start, s16 base, u32 *items) {
    s32 x;
    s16 width;
    s32 y;
    s32 half;
    s16 i;
    u16 size;
    u32 item;

    size = (*(u8 (*)[28])&lbl_3_bss_A2438)[0xc] * 2 + 1;
    half = size >> 1;
    i = -half;
    x = base + i;
    y = start - half;
    width = size;

    while (i <= half) {
        item = *items;
        fn_3_146C0(obj, y, x, width, &item);
        x++;
        i++;
    }
}
/* fzgx:end fn_3_1AB34 */

/* fzgx:begin fn_3_1ABD8 */
extern void fn_3_1B4BC(void *, s16, s16, s16, s16, u32 *);

void fn_3_1ABD8(void *arg0, s16 x1, s16 y1, s16 x2, s16 y2, u32 *value) {
    u32 result1;
    u32 result2;
    u32 result3;
    u32 result4;

    if (x1 > x2) {
        s16 temp = x1;
        x1 = x2;
        x2 = temp;
    }

    if (y1 > y2) {
        s16 temp = y1;
        y1 = y2;
        y2 = temp;
    }

    result1 = *value;
    fn_3_1B4BC(arg0, x1, y1, x2, y1, &result1);
    result2 = *value;
    fn_3_1B4BC(arg0, x1, y2, x2, y2, &result2);
    result3 = *value;
    fn_3_1B4BC(arg0, x1, y1, x1, y2, &result3);
    result4 = *value;
    fn_3_1B4BC(arg0, x2, y1, x2, y2, &result4);
}
/* fzgx:end fn_3_1ABD8 */

/* fzgx:begin fn_3_1ACE4 */
extern void fn_3_1B4BC(void *, s32, s32, s32, s32, u32 *);

void fn_3_1ACE4(void *data, s32 first_a, s32 second_a, s32 first_b, s32 second_b,
                u32 *values) {
    s16 current;
    s16 limit;
    s16 count;
    u32 value;

    if ((s16)first_a > (s16)first_b) {
        s32 temp = first_a;
        first_a = first_b;
        first_b = temp;
    }
    if ((s16)second_a > (s16)second_b) {
        s32 temp = second_a;
        second_a = second_b;
        second_b = temp;
    }

    current = (s16)second_a;
    count = 0;
    limit = (s16)(second_b - current);
    while ((s16)count <= limit) {
        value = *values;
        fn_3_1B4BC(data, first_a, current, first_b, current, &value);
        current++;
        count++;
    }
}
/* fzgx:end fn_3_1ACE4 */

/* fzgx:begin fn_3_1AE40 */
extern void fn_3_14E18(void *, u32, u32, s16, u32);

void fn_3_1AE40(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    s16 v1;
    u32 v0;
    u32 v3;
    u32 v4;
    s16 v2;

    v0 = (s16)arg3 - (s16)arg1;
    v1 = (s16)arg4;
    v2 = (s16)((s32)(((u32)v0 >> 31) + v0) >> 1);
    v3 = arg2;
    while ((s16)v3 < v1) {
        v4 = arg1;
        while ((s16)v4 < v2) {
            fn_3_14E18(arg0, v4, v3, (s16)((v0 - v4) - 1), v3);
            v4++;
        }
        v3++;
    }
}
/* fzgx:end fn_3_1AE40 */

/* fzgx:begin fn_3_1AEE4 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/toolkit.h"

extern u32 fn_3_149AC(void *, u32, u32);
extern void fn_3_14794(void *, u32, s16, u32 *);

void fn_3_1AEE4(void *data, u32 x1, u32 y1, u32 x2, u32 y2) {
    s16 width;
    s16 height;
    u32 copy_x;
    u32 copy_y;
    void *temp;
    s32 last;
    s16 end = y2;
    u32 y = y1;
    u32 x;
    u32 value1;
    u32 value2;

    last = end - 1;

    for (; (s16)y < end; y++) {
        for (x = x1; (s16)x < (s16)x2; x++) {
            value1 = fn_3_149AC(data, x, y);
            fn_3_14794((void *)lbl_3_bss_A2454, y, (s16)(last - x), &value1);
        }
    }
    temp = (void *)lbl_3_bss_A2454;
    height = end - y1;
    width = x2 - x1;
    if (data != 0) {
        for (copy_y = 0; (s16)copy_y < height; copy_y++) {
            for (copy_x = 0; (s16)copy_x < width; copy_x++) {
                value2 = fn_3_149AC(temp, copy_x, copy_y);
                {
                    extern void fn_3_14794(void *, u32, u32, u32 *);
                    fn_3_14794(data, copy_x, copy_y, &value2);
                }
            }
        }
    }
}
/* fzgx:end fn_3_1AEE4 */

/* fzgx:begin fn_3_1B008 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/toolkit.h"

extern u32 fn_3_149AC(void *, u32, u32);
extern void fn_3_14794(void *, s16, u32, u32 *);

void fn_3_1B008(void *data, u32 x1, u32 y1, u32 x2, u32 y2) {
    u32 copy_y;
    s16 width;
    s16 height;
    u32 copy_x;
    u32 buffer;
    u32 value;
    u32 copy_value;
    s32 destination_x;
    s16 right = x2;
    u32 y;
    u32 x;
    void *target = data;
    u32 first_x = x1;

    for (y = y1; (s16)y < (s16)y2; y++) {
        destination_x = right - 1 - (s16)y;
        for (x = first_x; (s16)x < right; x++) {
            value = fn_3_149AC(data, x, y);
            fn_3_14794((void *)lbl_3_bss_A2454, (s16)destination_x, x, &value);
        }
    }
    buffer = lbl_3_bss_A2454;
    height = y2 - y1;
    width = right - x1;
    if (data != 0) {
        for (copy_y = 0; (s16)copy_y < height; copy_y++) {
            for (copy_x = 0; (s16)copy_x < width; copy_x++) {
                copy_value = fn_3_149AC((void *)buffer, copy_x, copy_y);
                {
                    extern void fn_3_14794(void *, u32, u32, u32 *);
                    fn_3_14794(target, copy_x, copy_y, &copy_value);
                }
            }
        }
    }
}
/* fzgx:end fn_3_1B008 */

/* fzgx:begin fn_3_1BF08 */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;
typedef double f64;


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
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);


extern void fn_3_1B4BC(void *, s16, s16, s16, s16, u32 *);


extern f32 lbl_8006D118(f32 *, f32);
extern void fzgx_usef(f32);
extern void fzgx_used(f64);
extern void fzgx_usep(void *);
extern s32 fzgx_sink_s;
extern u32 fzgx_sink_u;


extern void fn_3_1BF08(void *data, s16 x1, s16 y1, s16 x2, s16 y2, u32 *color);



#pragma section RX ".fzgxpool"

__declspec(section ".fzgxpool") void fzgx_pool_primer(void) {
fzgx_usef(24.0f);
fzgx_usef(86.0f);
fzgx_usef(100.0f);
fzgx_usef(385.0f);
fzgx_usef(170.0f);
fzgx_usef(104.0f);
fzgx_usef(40.0f);
fzgx_usef(96.0f);
fzgx_usef(90.0f);
fzgx_usef(0.5f);
fzgx_usef(20.0f);
fzgx_usef(60.0f);
fzgx_usef(80.0f);
fzgx_usef(15.0f);
fzgx_usef(30.0f);
fzgx_usef(320.0f);
fzgx_usef(372.0f);
fzgx_usef(0.1f);
fzgx_usef(0.6f);
fzgx_usef(375.0f);
fzgx_usef(0.75f);
fzgx_usef(248.0f);
fzgx_usef(1.0f);
fzgx_usef(0.8f);
fzgx_usef(240.0f);
fzgx_usef(25.0f);
fzgx_usef(1.02f);
fzgx_usef(1.01f);
fzgx_usef(0.4f);
fzgx_usef(32768.0f);
fzgx_usef(10.0f);
fzgx_usef(81.0f);
fzgx_usef(399.0f);
fzgx_usef(18.0f);
fzgx_usef(12.0f);
fzgx_usef(0.0f);
}
__declspec(section ".fzgxpool") void fzgx_pool_primer2(void) {
fzgx_usef((f32)fzgx_sink_s);
fzgx_usef((f32)fzgx_sink_u);
}
__declspec(section ".fzgxpool") void fzgx_pool_primer3(void) {
{
u32 pair[4] = { 0, 0, 0, 0xBF800000 };
fzgx_usep(pair);
}
fzgx_used(0.5);
}

#pragma section RX ".text"

void fn_3_1BF08(void *data, s16 x1, s16 y1, s16 x2, s16 y2, u32 *color) {
s32 dx = x2 - x1;
s32 dy = y2 - y1;
s16 radius;
f32 scale;
f32 step;
f32 k;
s16 x;
s16 y;
s16 d1;
s16 d2;
u32 c0;
u32 c1;
radius = __abs(dx) > __abs(dy) ? __abs(dx) : __abs(dy);
k = lbl_8006D118(&scale, 1.0f);
x = radius * k;
d1 = 2.0f + (1.0f + (f32)((f32)(-2.0f * scale) * radius));
d2 = 1.0f + (2.0f + (f32)((f32)(-4.0f * scale) * radius));
y = 0;
while (x >= 0) {
c0 = *color;
fn_3_1B4BC(data, x1 - x, y1 - y, x1 + x, y1 - y, &c0);
c1 = *color;
fn_3_1B4BC(data, x1 - x, y1 + y, x1 + x, y1 + y, &c1);
if (d1 < 0) {
y++;
d1 = d1 + (2.0f + 4.0f * y);
d2 = d2 + 4.0f * y;
} else if (d2 >= 0) {
x--;
d1 = d1 - 4.0f * x;
d2 = d2 - (4.0f * x - 2.0f);
} else {
y++;
x--;
d1 = d1 + (2.0f + ((f32)(4.0f * y) - (f32)(4.0f * x)));
d2 = d2 + (2.0f + ((f32)(4.0f * y) - (f32)(4.0f * x)));
}
}
}
/* fzgx:end fn_3_1BF08 */

/* fzgx:begin fn_3_1D338 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table2[6] = {0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0x0000FF00, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4583333432674408f;
    s = 284.0f;
    s = 329.0f;
    s = 100.0f;
    s = 0.9166666865348816f;
    s = 360.0f;
    s = 0.5416666865348816f;
    s = 441.0f;
    s = 332.0f;
    s = 345.0f;
    s = 358.0f;
    s = 0.48749998211860657f;
    s = 395.0f;
    s = 331.0f;
    s = 359.0f;
    s = 320.0f;
    s = 362.0f;
    s = 200.0f;
    s = 323.0f;
    s = 381.0f;
    s = 13.0f;
    s = 0.007843137718737125f;
    s = 6.0f;
    s = 7.0f;
    s = 0.14901961386203766f;
    s = 0.12941177189350128f;
    s = 132.0f;
    s = 150.0f;
    s = 0.800000011920929f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table6[43] = {0x00004A00, 0x00005400, 0x00003800, 0x00003E00, 0x00003700, 0x00005500, 0x00003000, 0x00003500, 0x00003A00, 0x00004000, 0x00004400, 0x00005000, 0x00003300, 0x00002E00, 0x00003100, 0x00004F00, 0x00003900, 0x00003D00, 0x00004C00, 0x00003F00, 0x00004800, 0x00005200, 0x00004500, 0x00005300, 0x00003C00, 0x00005600, 0x00004300, 0x00004200, 0x00003200, 0x00002F00, 0x00003400, 0x00003600, 0x00004D00, 0x00004600, 0x00004100, 0x00005100, 0x00004E00, 0x00004700, 0x00003B00, 0x00004B00, 0x00004900, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 380.0f;
    s = 334.0f;
    s = 0.40625f;
}
static const u32 fzgx_pool_color0[1] = {0x00000000};
static const u32 fzgx_pool_color1[1] = {0x00000000};
static const u32 fzgx_pool_color2[1] = {0x00000000};
static const u32 fzgx_pool_color3[1] = {0x00000000};
static const u32 fzgx_pool_color4[1] = {0x00000000};
static const u32 fzgx_pool_color5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_color0; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 480.0f;
    s = 640.0f;
    s = 62.0f;
    s = 1.3411765098571777f;
    s = 8.0f;
    s = 0.125f;
    s = 1.0f;
    s = 0.5f;
    s = 215.0f;
    s = 3.0f;
    s = 180.0f;
    s = 90.0f;
    s = 240.0f;
    s = 44.0f;
    s = 89.9000015258789f;
    s = 40.0f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 80.0f;
    s = 460.0f;
    s = 0.6666666865348816f;
    s = 0.6078431606292725f;
    s = -3.0f;
    s = 0.0f;
    s = 0.6196078658103943f;
    s = 0.5058823823928833f;
    s = 216.0f;
    s = 0.20000000298023224f;
    s = 140.0f;
    s = 250.0f;
    s = 400.0f;
    s = 550.0f;
    s = 0.46666666865348816f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

struct fn_3_1D338_sprite {
    u32 unk0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u8 color[4];
    u8 pad3C[0x14];
    void (*draw)(void *, void *);
    u8 pad54[4];
};

struct fn_3_1D338_bss_F0 {
    u8 pad0[0xA];
    s16 unkA;
    s16 unkC;
    s16 unkE[11];
    u32 unk24;
    u8 pad28[2];
    s16 unk2A;
};

struct fn_3_1D338_a2460 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
};

extern struct fn_3_1D338_bss_F0 lbl_3_bss_F0;
extern struct fn_3_1D338_a2460 lbl_3_bss_A2460;
extern struct fn_3_1D338_sprite lbl_1_rodata_26F8;
extern u32 lbl_801A66A8;

extern u16 fn_1_A5DB0(void);
extern s8 fn_1_A5DC4(void);
extern f32 lbl_8006D188(s32);
extern void fn_1_50164(f32, f32, f32, f32, void *);
extern void fn_1_49410(void);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495A0(f32);
extern void fn_1_495C8(s32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(void (*)(void *, void *));
extern void fn_1_4AE0C(const char *, ...);
extern u32 fn_3_2B750(s16, s16);
extern void fn_3_2406C(void *, void *);
extern void fn_3_240DC(void *, void *);
extern void fn_1_5233C(void *, void *);



#define SETUP_SPRITE(id, xv, yv, zv)                                          \
    do {                                                                      \
        sprite = lbl_1_rodata_26F8;                                           \
        sprite.unk0 = (id);                                                   \
        sprite.x = (xv);                                                      \
        sprite.y = (yv);                                                      \
        sprite.z = (zv);                                                      \
        sprite.unk30 = 10;                                                    \
        if (!fn_1_A5DC4()) {                                                  \
            sprite.draw = fn_3_2406C;                                         \
            sprite.unk30 |= 0x04000000;                                       \
        }                                                                     \
    } while (0)

#define SET_COLOR()                                                           \
    do {                                                                      \
        v = lbl_8006D188((s32)(16384.0f + 65536.0f *                          \
            (f32)(u32)(lbl_801A66A8 % 60) / 60.0f));                          \
        sprite.color[0] = 40.0f + (f32)(40.0f * v);                                          \
        v = lbl_8006D188((s32)(16384.0f + 65536.0f *                          \
            (f32)(u32)(lbl_801A66A8 % 60) / 60.0f));                          \
        sprite.color[1] = 80.0f + (f32)(80.0f * v);                                          \
        v = lbl_8006D188((s32)(16384.0f + 65536.0f *                          \
            (f32)(u32)(lbl_801A66A8 % 60) / 60.0f));                          \
        sprite.color[2] = 80.0f + (f32)(80.0f * v);                                          \
    } while (0)



#pragma opt_propagation off
static inline f32 fn_3_1D338_operand(f32 right, f32 left) { return left * right; }
static inline f32 fn_3_1D338_operand_(f32 left, f32 right) { return left * right; }
#pragma opt_loop_invariants on
static inline f32 fn_3_1D338_operand__(f32 right, f32 left) { return left * right; }
#pragma opt_strength_reduction on
static inline f32 fn_3_1D338_operand___(f32 left, f32 right) { return left * right; }
void fn_3_1D338(s16 kind) {
    s16 fzgx_value;
    struct fn_3_1D338_sprite sprite;
    u32 v29;
    f32 f31;
    f32 f30;
    f32 f29;
    f32 v;
    f32 w;
    f32 clamped;
    f32 lab_t0;

    v29 = 640;
    f31 = (f32)(u16)fn_1_A5DB0() / 480.0f;
    f30 = 640.0f;
    f29 = 62.0f;
    if (fn_1_A5DC4()) {
        s32 w = 640;
        w *= 1.3411765098571777f; v29 = w; f30 *= 1.3411765098571777f;
    }
    if ((lbl_3_bss_F0.unk24 & 0x80000000) &&
        (lbl_3_bss_F0.unk24 & 0x20000000)) {
        if ((f32)lbl_3_bss_F0.unk2A < 8.0f) {
            f29 = 8.0f;
            v = fn_3_1D338_operand_((((f32)(s16)v29 * (f32)lbl_3_bss_F0.unk2A)), (0.125f));
clamped = 8.0f;
clamped = (v < clamped) ? clamped : (((v) > ( (f32)(s16)v29)) ? ( (f32)(s16)v29) : (v));
f30 = clamped;
        } else if (lbl_3_bss_F0.unk2A < 16) {
            v = fn_3_1D338_operand((0.125f), ((62.0f * ((f32)lbl_3_bss_F0.unk2A - 8.0f))));
clamped = ((v) < ( 8.0f)) ? ( 8.0f) : (((v) > ( 62.0f)) ? ( 62.0f) : (v));
f29 = clamped;
            f30 = (f32)(s16)v29;
        } else {
            f29 = 62.0f;
            f30 = (f32)(s16)v29;
        }
    } else if ((lbl_3_bss_F0.unk24 & 0x80000000) &&
               (lbl_3_bss_F0.unk24 & 0x10000000)) {
        if ((f32)lbl_3_bss_F0.unk2A < 8.0f) {
            v = 62.0f * (1.0f - (f32)((f32)lbl_3_bss_F0.unk2A / 8.0f));
clamped = ((v) < ( 8.0f)) ? ( 8.0f) : (((v) > ( 62.0f)) ? ( 62.0f) : (v));
f29 = clamped;
            f30 = (f32)(s16)v29;
        } else if (lbl_3_bss_F0.unk2A < 16) {
            f29 = 8.0f;
            v = (f32)(s16)v29 * (1.0f - (f32)(((f32)lbl_3_bss_F0.unk2A - 8.0f) / 8.0f));
clamped = ((v) < ( 8.0f)) ? ( 8.0f) : (((v) > ( (f32)(s16)v29)) ? ( (f32)(s16)v29) : (v));
f30 = clamped;
        } else {
            f30 = 8.0f;
            f29 = 8.0f;
        }
    }
    lbl_3_bss_A2460.unk0 = (s16)(320.0f - (f32)(f30 / 2.0f));
    lbl_3_bss_A2460.unk4 = (s16)f30;
    lbl_3_bss_A2460.unk2 = (s16)((215.0f - (f32)(f29 / 2.0f)) * f31);
    lbl_3_bss_A2460.unk6 = (s16)(f29 * f31);

    sprite = lbl_1_rodata_26F8;
    sprite.unk0 = 0x8929;
    sprite.x = 320.0f;
    sprite.y = 215.0f;
    sprite.z = 100.0f;
    sprite.unk30 = 10;
    fn_1_50164(f30, f29, 3.0f, 3.0f, &sprite);

    if (fn_1_A5DC4()) {
        if (lbl_3_bss_F0.unk24 & 0x80000000) {
            if (lbl_3_bss_F0.unk24 & 0x20000000) {
                return;
            }
            if (lbl_3_bss_F0.unk24 & 0x10000000) {
                return;
            }
        }
    } else if (f30 != (f32)(s16)v29) {
        return;
    }

    switch (kind) {
    case 0:
        SETUP_SPRITE(0x8920, 180.0f, 215.0f, 90.0f);
        fn_1_50164(240.0f, 44.0f, 8.0f, 8.0f, &sprite);

        SETUP_SPRITE(0x8913, 180.0f, 215.0f, 89.9f);
        sprite.unk2C = 0.5f;
        if ((*((lbl_3_bss_F0.unkC) + (lbl_3_bss_F0.unkE))) == 0) {
            SET_COLOR();
        } else {
            *(u32 *)sprite.color = (*((0) + (fzgx_pool_color0)));
        }
        fn_1_50164(240.0f, 44.0f, 7.0f, 7.0f, &sprite);

        SETUP_SPRITE(0x8920, 460.0f, 215.0f, 90.0f);
        fn_1_50164(240.0f, 44.0f, 8.0f, 8.0f, &sprite);

        SETUP_SPRITE(0x8913, 460.0f, 215.0f, 89.9f);
        sprite.unk2C = 0.5f;
        if ((*((lbl_3_bss_F0.unkC) + (lbl_3_bss_F0.unkE))) == 1) {
            SET_COLOR();
        } else {
            *(u32 *)sprite.color = (*((0) + (fzgx_pool_color1)));
        }
        fn_1_50164(240.0f, 44.0f, 7.0f, 7.0f, &sprite);

        fn_1_49410();
        fn_1_495C8(9);
        fn_1_4955C(0.6666666865348816f, 0.6666666865348816f);
        switch (lbl_3_bss_F0.unkA) {
        case 5:
            fn_1_4955C(0.6078431606292725f, 0.6078431606292725f);
            break;
        case 0:
        default:
            fn_1_4966C(-3.0f, 0.0f);
            lab_t0 = 0.5f;
            fn_1_49590(lab_t0);
            fn_1_4955C(0.6196078658103943f, 0.5058823823928833f);
            break;
        }
        fn_1_496FC(180.0f, 215.0f);
        fn_1_4954C(80.0f);
        if (!fn_1_A5DC4()) {
            fn_1_49738(fn_3_240DC);
        } else {
            fn_1_49738(fn_1_5233C);
        }
        fn_1_4AE0C((const char *)fn_3_2B750(16, lbl_3_bss_F0.unkA));
        fn_1_496FC(460.0f, 215.0f);
        fn_1_4954C(80.0f);
        if (!fn_1_A5DC4()) {
            fn_1_49738(fn_3_240DC);
        } else {
            fn_1_49738(fn_1_5233C);
        }
        fn_1_4AE0C((const char *)fn_3_2B750(17, lbl_3_bss_F0.unkA));
        break;
    case 1:
    case 2:
        SETUP_SPRITE(0x8920, 100.0f, 216.0f, 90.0f);
        if (kind == 2) {
            sprite.unk2C = 0.20000000298023224f;
        }
        fn_1_50164(140.0f, 44.0f, 8.0f, 8.0f, &sprite);

        SETUP_SPRITE(0x8913, 100.0f, 216.0f, 89.9f);
        sprite.unk2C = 0.5f;
        if (kind == 2) {
            sprite.unk2C = 0.20000000298023224f;
        }
        if ((*((lbl_3_bss_F0.unkC) + (lbl_3_bss_F0.unkE))) == 0) {
            SET_COLOR();
        } else {
            *(u32 *)sprite.color = (*((0) + (fzgx_pool_color2)));
        }
        fn_1_50164(140.0f, 44.0f, 7.0f, 7.0f, &sprite);

        SETUP_SPRITE(0x8920, 250.0f, 216.0f, 90.0f);
        if (kind == 2) {
            sprite.unk2C = 0.20000000298023224f;
        }
        fn_1_50164(140.0f, 44.0f, 8.0f, 8.0f, &sprite);

        SETUP_SPRITE(0x8913, 250.0f, 216.0f, 89.9f);
        sprite.unk2C = 0.5f;
        if (kind == 2) {
            sprite.unk2C = 0.20000000298023224f;
        }
        if ((*((lbl_3_bss_F0.unkC) + (lbl_3_bss_F0.unkE))) == 1) {
            SET_COLOR();
        } else {
            *(u32 *)sprite.color = (*((0) + (fzgx_pool_color3)));
        }
        fn_1_50164(140.0f, 44.0f, 7.0f, 7.0f, &sprite);

        SETUP_SPRITE(0x8920, 400.0f, 216.0f, 90.0f);
        fn_1_50164(140.0f, 44.0f, 8.0f, 8.0f, &sprite);

        SETUP_SPRITE(0x8913, 400.0f, 216.0f, 89.9f);
        sprite.unk2C = 0.5f;
        if ((*((lbl_3_bss_F0.unkC) + (lbl_3_bss_F0.unkE))) == 2) {
            SET_COLOR();
        } else {
            *(u32 *)sprite.color = (*((0) + (fzgx_pool_color4)));
        }
        fn_1_50164(140.0f, 44.0f, 7.0f, 7.0f, &sprite);

        SETUP_SPRITE(0x8920, 550.0f, 216.0f, 90.0f);
        fn_1_50164(140.0f, 44.0f, 8.0f, 8.0f, &sprite);

        SETUP_SPRITE(0x8913, 550.0f, 216.0f, 89.9f);
        sprite.unk2C = 0.5f;
        if ((*((lbl_3_bss_F0.unkC) + (lbl_3_bss_F0.unkE))) == 3) {
            SET_COLOR();
        } else {
            *(u32 *)sprite.color = (*((0) + (fzgx_pool_color5)));
        }
        fn_1_50164(140.0f, 44.0f, 7.0f, 7.0f, &sprite);

        fn_1_49410();
        fn_1_495C8(9);
        fn_1_4955C(0.6666666865348816f, 0.6666666865348816f);
        switch (lbl_3_bss_F0.unkA) {
        case 5:
            break;
        case 0:
        default:
            fn_1_49590(0.5f);
            fn_1_4955C(0.46666666865348816f, 0.6666666865348816f);
            break;
        }
        fn_1_496FC(100.0f, 216.0f);
        fn_1_4954C(80.0f);
        if (!fn_1_A5DC4()) {
            fn_1_49738(fn_3_240DC);
        } else {
            fn_1_49738(fn_1_5233C);
        }
        if (kind == 2) {
            fn_1_495A0(0.20000000298023224f);
        }
        fn_1_4AE0C((const char *)fn_3_2B750(11, lbl_3_bss_F0.unkA));
        if (!fn_1_A5DC4()) {
            fn_1_49738(fn_3_240DC);
        } else {
            fn_1_49738(fn_1_5233C);
        }
        fn_1_496FC(250.0f, 216.0f);
        fn_1_4954C(80.0f);
        if (kind == 2) {
            fn_1_495A0(0.20000000298023224f);
        }
        fn_1_4AE0C((const char *)fn_3_2B750(12, lbl_3_bss_F0.unkA));
        if (!fn_1_A5DC4()) {
            fn_1_49738(fn_3_240DC);
        } else {
            fn_1_49738(fn_1_5233C);
        }
        fn_1_496FC(400.0f, 216.0f);
        fn_1_4954C(80.0f);
        fn_1_495A0(1.0f);
        fn_1_4AE0C((const char *)fn_3_2B750(13, lbl_3_bss_F0.unkA));
        if (!fn_1_A5DC4()) {
            fn_1_49738(fn_3_240DC);
        } else {
            fn_1_49738(fn_1_5233C);
        }
        fn_1_496FC(550.0f, 216.0f);
        fn_1_4954C(80.0f);
        fn_1_495A0(1.0f);
        fn_1_4AE0C((const char *)fn_3_2B750(14, lbl_3_bss_F0.unkA));
    }
}
#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset

#pragma opt_propagation reset
/* fzgx:end fn_3_1D338 */

/* fzgx:begin fn_3_1EC2C noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table2[6] = {0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0x0000FF00, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4583333432674408f;
    s = 284.0f;
    s = 329.0f;
    s = 100.0f;
    s = 0.9166666865348816f;
    s = 360.0f;
    s = 0.5416666865348816f;
    s = 441.0f;
    s = 332.0f;
    s = 345.0f;
    s = 358.0f;
    s = 0.48749998211860657f;
    s = 395.0f;
    s = 331.0f;
    s = 359.0f;
    s = 320.0f;
    s = 362.0f;
    s = 200.0f;
    s = 323.0f;
    s = 381.0f;
    s = 13.0f;
    s = 0.007843137718737125f;
    s = 6.0f;
    s = 7.0f;
    s = 0.14901961386203766f;
    s = 0.12941177189350128f;
    s = 132.0f;
    s = 150.0f;
    s = 0.800000011920929f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table6[43] = {0x00004A00, 0x00005400, 0x00003800, 0x00003E00, 0x00003700, 0x00005500, 0x00003000, 0x00003500, 0x00003A00, 0x00004000, 0x00004400, 0x00005000, 0x00003300, 0x00002E00, 0x00003100, 0x00004F00, 0x00003900, 0x00003D00, 0x00004C00, 0x00003F00, 0x00004800, 0x00005200, 0x00004500, 0x00005300, 0x00003C00, 0x00005600, 0x00004300, 0x00004200, 0x00003200, 0x00002F00, 0x00003400, 0x00003600, 0x00004D00, 0x00004600, 0x00004100, 0x00005100, 0x00004E00, 0x00004700, 0x00003B00, 0x00004B00, 0x00004900, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 380.0f;
    s = 334.0f;
    s = 0.40625f;
}
static const u32 fzgx_pool_table8[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 480.0f;
    s = 640.0f;
    s = 62.0f;
    s = 1.3411765098571777f;
    s = 8.0f;
    s = 0.125f;
    s = 1.0f;
    s = 0.5f;
    s = 215.0f;
    s = 3.0f;
    s = 180.0f;
    s = 90.0f;
    s = 240.0f;
    s = 44.0f;
    s = 89.9000015258789f;
    s = 40.0f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 80.0f;
    s = 460.0f;
    s = 0.6666666865348816f;
    s = 0.6078431606292725f;
    s = -3.0f;
    s = 0.0f;
    s = 0.6196078658103943f;
    s = 0.5058823823928833f;
    s = 216.0f;
    s = 0.20000000298023224f;
    s = 140.0f;
    s = 250.0f;
    s = 400.0f;
    s = 550.0f;
    s = 0.46666666865348816f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Bss20 {
    u8 pad_0[0xC2];
    s16 unk_C2;
} Bss20;

typedef struct Entry7E6F0 {
    s16 unk_0;
    s16 unk_2;
    u8 pad_4[0xC];
} Entry7E6F0;

typedef struct BssA2468 {
    u32 unk_0;
    Vec3 unk_4;
    Vec3 unk_10;
} BssA2468;

typedef struct Light1E5C0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
} Light1E5C0;

extern Bss20 lbl_3_bss_20;
extern Entry7E6F0 lbl_3_bss_7E6F0[];
extern BssA2468 lbl_3_bss_A2468;
extern Light1E5C0 lbl_1_data_1E5C0;
extern u32 lbl_801A66A0;
extern s16 lbl_3_bss_18;
extern u8 lbl_3_bss_6DE20[];
extern u32 lbl_3_bss_20848;

extern void fn_80008BEC(void *, int, u32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_8006F038(Vec3 *, Vec3 *, s16);
extern void lbl_8006DCDC(void);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void fn_1_F7870(Light1E5C0 *);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void fn_3_1F81C(void);
extern void fn_1_55FF0(f32);
extern s16 fn_1_14F118(s16, s16);
extern void fn_1_14DE80(void *, void *, void *, s16, f32);
extern void fn_1_14E054(void *, Vec3 *, s16, f32);
extern void fn_1_14E198(void *, Vec3 *, s16, f32);


static inline void set_eye(void) {
    Vec3 at = {0.0f, 10.0f, -5.0f};
    fn_80008BA8(&lbl_3_bss_A2468.unk_4, &at, 12);
}

static inline void set_target(void) {
    Vec3 up = {0.0f, 0.0f, 0.0f};
    fn_80008BA8(&lbl_3_bss_A2468.unk_10, &up, 12);
}

s32 fn_3_1EC2C(void) {
    Light1E5C0 *src;
    Entry7E6F0 *entry;
    Light1E5C0 light;
    f32 k;
    f32 a;
    f32 b;

    entry = &lbl_3_bss_7E6F0[lbl_3_bss_20.unk_C2];
    fn_80008BEC(&lbl_3_bss_A2468.unk_4, 0, 12);
    fn_80008BEC(&lbl_3_bss_A2468.unk_10, 0, 12);
    set_eye();
    set_target();
    fn_8006F038(&lbl_3_bss_A2468.unk_4, &lbl_3_bss_A2468.unk_10, 0);
    lbl_8006DCDC();

    src = &lbl_1_data_1E5C0;
    k = 0.7f;
    a = src->unk_C * k;
    b = src->unk_10 * k;
    light = *src;
    light.unk_C = a - b;
    light.unk_10 = a + b;
    light.unk_14 = src->unk_14;
    fn_1_F7870(&light);

    lbl_8006DCA4();
    lbl_8006E0B4(0.0f, -0.5f, 0.0f);
    mathutil_mtxA_rotate_x(0x2000);
    mathutil_mtxA_rotate_y(182.04444885253906f * (f32)(360 - lbl_801A66A0 % 360));
    fn_3_1F81C();
    lbl_8006DCA4();
    mathutil_mtxA_rotate_x(0x2000);
    mathutil_mtxA_rotate_y(182.04444885253906f * (f32)(lbl_801A66A0 % 360));
    fn_1_55FF0((f32)lbl_3_bss_18 / 10.0f);

    {
    u32 out1 = 0;
    u32 out0 = 0;
    Vec3 color = {0.0f, 0.0f, 0.0f};
    s16 kind = entry->unk_2;
    switch (kind) {
    case 0:
        fn_1_14DE80(&lbl_3_bss_6DE20[fn_1_14F118(entry->unk_0, kind) * 0xA20], &out1, &out0,
                    lbl_3_bss_20848, 1.0f);
        break;
    case 1:
        fn_1_14E054(&lbl_3_bss_6DE20[fn_1_14F118(entry->unk_0, kind) * 0xA20], &color,
                    lbl_3_bss_20848, 1.0f);
        break;
    case 2:
        fn_1_14E198(&lbl_3_bss_6DE20[fn_1_14F118(entry->unk_0, kind) * 0xA20], &color,
                    lbl_3_bss_20848, 1.0f);
        break;
    }
    }
    return 0;
}
/* fzgx:end fn_3_1EC2C */

/* fzgx:begin fn_3_1F81C */
extern const f32 lbl_3_rodata_8F0[28];
extern const f32 lbl_3_rodata_990[297];
extern u32 lbl_801A66A0;

typedef struct CustomizeObject CustomizeObject;

typedef struct {
    u32 flags;
    u8 pad[0x1c];
} CustomizeEntry;

struct CustomizeObject {
    u8 pad0[0x18];
    u16 count;
    u8 pad1[0x26];
    CustomizeEntry entries[1];
    u8 pad2[0xc];
    f32 value;
};

typedef struct {
    CustomizeObject *object;
} CustomizeSlot;

typedef struct {
    u8 pad0[8];
    CustomizeSlot *slot;
} CustomizeManager;

typedef struct {
    u8 pad0[0xc];
    CustomizeManager *manager;
} CustomizeRoot;

extern CustomizeRoot lbl_1_bss_38460;
extern CustomizeObject *lbl_801A6D00;

extern void fn_1_56018(s32);
extern void lbl_8006D784(void *);
extern f32 lbl_8006D188(s16);
extern void fn_1_560F0(s32, void *);
extern void fn_80072558(void);
extern void fn_1_55210(CustomizeObject *);

void fn_3_1F81C(void) {
    s16 i;
    CustomizeObject *obj;
    CustomizeEntry *entry;
    u32 n;

    i = 0;
    obj = lbl_1_bss_38460.manager->slot->object;
    entry = obj->entries;
    for (; i < obj->count; i++, entry++) {
        if (entry->flags & 0x20000) {
            fn_1_56018(1);
            lbl_8006D784(&lbl_801A6D00->pad2[0]);
            n = lbl_801A66A0;
            lbl_801A6D00->value = lbl_3_rodata_8F0[0] -
                lbl_8006D188((s16)((s32)(lbl_3_rodata_990[0] * (f32)(n % 180)) + 0x4000));
            fn_1_560F0(0, &lbl_801A6D00->pad2[0]);
        }
    }
    fn_80072558();
    fn_1_55210(obj);
}
/* fzgx:end fn_3_1F81C */

/* fzgx:begin fn_3_23724 pool */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table2[6] = {0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0x0000FF00, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4583333432674408f;
    s = 284.0f;
    s = 329.0f;
    s = 100.0f;
    s = 0.9166666865348816f;
    s = 360.0f;
    s = 0.5416666865348816f;
    s = 441.0f;
    s = 332.0f;
    s = 345.0f;
    s = 358.0f;
    s = 0.48749998211860657f;
    s = 395.0f;
    s = 331.0f;
    s = 359.0f;
    s = 320.0f;
    s = 362.0f;
    s = 200.0f;
    s = 323.0f;
    s = 381.0f;
    s = 13.0f;
    s = 0.007843137718737125f;
    s = 6.0f;
    s = 7.0f;
    s = 0.14901961386203766f;
    s = 0.12941177189350128f;
    s = 132.0f;
    s = 150.0f;
    s = 0.800000011920929f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table6[43] = {0x00004A00, 0x00005400, 0x00003800, 0x00003E00, 0x00003700, 0x00005500, 0x00003000, 0x00003500, 0x00003A00, 0x00004000, 0x00004400, 0x00005000, 0x00003300, 0x00002E00, 0x00003100, 0x00004F00, 0x00003900, 0x00003D00, 0x00004C00, 0x00003F00, 0x00004800, 0x00005200, 0x00004500, 0x00005300, 0x00003C00, 0x00005600, 0x00004300, 0x00004200, 0x00003200, 0x00002F00, 0x00003400, 0x00003600, 0x00004D00, 0x00004600, 0x00004100, 0x00005100, 0x00004E00, 0x00004700, 0x00003B00, 0x00004B00, 0x00004900, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 380.0f;
    s = 334.0f;
    s = 0.40625f;
}
static const u32 fzgx_pool_table8[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 480.0f;
    s = 640.0f;
    s = 62.0f;
    s = 1.3411765098571777f;
    s = 8.0f;
    s = 0.125f;
    s = 1.0f;
    s = 0.5f;
    s = 215.0f;
    s = 3.0f;
    s = 180.0f;
    s = 90.0f;
    s = 240.0f;
    s = 44.0f;
    s = 89.9000015258789f;
    s = 40.0f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 80.0f;
    s = 460.0f;
    s = 0.6666666865348816f;
    s = 0.6078431606292725f;
    s = -3.0f;
    s = 0.0f;
    s = 0.6196078658103943f;
    s = 0.5058823823928833f;
    s = 216.0f;
    s = 0.20000000298023224f;
    s = 140.0f;
    s = 250.0f;
    s = 400.0f;
    s = 550.0f;
    s = 0.46666666865348816f;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table10[9] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 182.04444885253906f;
    s = 10.0f;
}
static const u32 fzgx_pool_table12[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.75f;
    s = 3.5f;
    s = 0.05000000074505806f;
}
static const u32 fzgx_pool_table14[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.25f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.5176470279693604f;
    s = 8.79411792755127f;
    s = 10.55294132232666f;
    s = 315.0f;
    s = 2.0f;
    s = 1.2999999523162842f;
    s = 0.6000000238418579f;
    s = 0.6274510025978088f;
    s = 0.7529411911964417f;
    s = 3.5999999046325684f;
    s = 9.0f;
}
static const u32 fzgx_pool_table18[2] = {0x00000000, 0x41200000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -5.0f;
}
static const u32 fzgx_pool_table20[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003, 0x00020001, 0x00000001, 0x00020003, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.211764812469482f;
}
static const u32 fzgx_pool_table22[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.21176470816135406f;
}
static const u32 fzgx_pool_table24[13] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00FFFF00, 0x00FFFF00, 0x00FF0000, 0x00FF0000, 0x00FF0000, 0x00FF0000, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 266.0f;
    s = 120.0f;
    s = 547.0f;
    s = 173.0f;
    s = 23.0f;
    s = 223.0f;
    s = 257.0f;
    s = 20.0f;
    s = 12.0f;
    s = 67.75f;
    s = 2.5f;
    s = 0.3499999940395355f;
    s = 0.15000000596046448f;
    s = 11.0f;
    s = 16.0f;
}
static const u32 fzgx_pool_table26[4] = {0x00FFFF00, 0x00FFFF00, 0x00FF0000, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 286.0f;
    s = 153.0f;
    s = 277.0f;
    s = -71.0f;
    s = 172.0f;
    s = 63.0f;
    s = 4.0f;
    s = 24.0f;
    s = 5.0f;
}
static const u32 fzgx_pool_table28[1] = {0x00170018};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

struct fn_3_23724_Unk88 {
    u32 field00;
    f32 field04;
    f32 field08;
    f32 field0C;
    u32 field10[18];
};
extern u8 lbl_1_rodata_26F8[];
extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);
extern void fn_1_50164(f32, f32, f32, f32, void *);
static f32 fn_3_23724_clamp(f32 x) {
    return x < 0.0f ? 0.0f : x > 1.0f ? 1.0f : x;
}
#pragma opt_lifetimes on
static inline f32 fn_3_23724_operand(f32 right, f32 left) { left += right; return left; }
#pragma opt_strength_reduction off
void fn_3_23724(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    struct fn_3_23724_Unk88 u;
    f32 t0;
    f32 t1;
    f32 t2;
    f32 t3;
    f32 t4;
    f32 t5;
    f32 t6;
    f32 lab_t3;
    t0 = arg4 - 4.0f;
    t1 = t0 - 24.0f;
    u = *(struct fn_3_23724_Unk88 *)(void *)lbl_1_rodata_26F8;
    u.field00 = 0x8921;
    u.field04 = (f32)arg0;
    u.field08 = (f32)arg1;
    u.field0C = (f32)arg2;
    u.field10[8] = 6;
    lab_t3 = 7.0f;
    fn_1_50190(&u, arg3, arg4, lab_t3, 7.0f, 23.0f, 7.0f);
    t2 = t1 * fn_3_23724_clamp(arg6);
    u = *(struct fn_3_23724_Unk88 *)(void *)lbl_1_rodata_26F8;
    u.field00 = 0x8902;
    u.field04 = (f32)arg0;
    t4 = (24.0f + (f32)(t1 * fn_3_23724_clamp(arg5)) < (((f32)(((t2) / 2.0f))) + (24.0f)))
        ? (fn_3_23724_operand(((24.0f)), (((f32)(((t2) / 2.0f))))))
        : ((t3 = 24.0f) + (f32)(t1 * fn_3_23724_clamp(arg5)) > t0 - (f32)(((t2) / 2.0f)))
        ? t0 - (f32)(((t2) / 2.0f))
        : t3 + (f32)(t1 * fn_3_23724_clamp(arg5));
    t5 = (((((f32)arg1)) + ((t4))));
    u.field08 = t5;
    u.field0C = (f32)(arg2 - 1);
    u.field10[8] = 10;
    fn_1_50164(12.0f, t2, 5.0f, 5.0f, &u);
}
#pragma opt_strength_reduction reset

#pragma opt_lifetimes reset
/* fzgx:end fn_3_23724 */

/* fzgx:begin fn_3_2406C noprologue */
#include "types.h"

extern s16 lbl_3_bss_A2460[4];
extern void fn_80074188(s16, s16, s16, s16);

void fn_3_2406C(void) {
    fn_80074188(lbl_3_bss_A2460[0], lbl_3_bss_A2460[1],
                lbl_3_bss_A2460[2], lbl_3_bss_A2460[3]);
}
/* fzgx:end fn_3_2406C */

/* fzgx:begin fn_3_240A4 noprologue */
#include "types.h"

extern void fn_80074188(s16, s16, s16, s16);
extern s16 lbl_3_bss_A248C[21];

void fn_3_240A4(void) {
    fn_80074188(lbl_3_bss_A248C[0], lbl_3_bss_A248C[1],
                lbl_3_bss_A248C[2], lbl_3_bss_A248C[3]);
}
/* fzgx:end fn_3_240A4 */

/* fzgx:begin fn_3_240DC noprologue */
#include "types.h"

extern s16 lbl_3_bss_A2460[4];
extern void fn_80074188(s16, s16, s16, s16);
extern void fn_1_5233C(void *, void *);

void fn_3_240DC(void *arg0, void *arg1) {
    fn_80074188(lbl_3_bss_A2460[0],
                lbl_3_bss_A2460[1],
                lbl_3_bss_A2460[2],
                lbl_3_bss_A2460[3]);
    fn_1_5233C(arg0, arg1);
}
/* fzgx:end fn_3_240DC */

/* fzgx:begin fn_3_268D0 */
extern f32 lbl_3_rodata_768[38];
extern void fn_80008BA8(u32 *, void *, s32);
extern u8 fn_1_151E20(u32, s32);
extern void fn_1_A9868(void);
extern s8 fn_1_A5DC4(void);
extern void fn_1_AA188(s32, s32, s32, s32, void *, void *, void *, void *);
extern void fn_1_AA538(void);
extern void fn_1_4E0F4(void);

typedef struct fn_3_268D0_CustomizeObject {
    u8 pad000[4];
    f32 x;
    f32 y;
    u8 pad00c[0x2c];
    u32 resource;
    u8 pad03c[0x18];
    u8 pad054[0];
} fn_3_268D0_CustomizeObject;

typedef union Color {
    u8 bytes[4];
    u32 word;
} Color;

void fn_3_268D0(fn_3_268D0_CustomizeObject *self) {
    f32 *table = lbl_3_rodata_768;
    Color color;
    u32 value;
    s32 x0;
    s32 y0;

    fn_80008BA8(&value, &self->pad054, 4);
    color.bytes[0] = fn_1_151E20(value, 0);
    color.bytes[1] = fn_1_151E20(value, 1);
    color.bytes[2] = fn_1_151E20(value, 2);
    color.bytes[3] = 0xff;

    if (fn_1_A9868(), fn_1_A5DC4()) {
        u32 a;
        u32 b;
        u32 c;
        u32 d;

        f32 fx = self->x - table[317];
        f32 fy = self->y - table[29];
        d = self->resource;
        c = color.word;
        b = c;
        a = d;
        fn_1_AA188((s32)fx, (s32)fy, 0x81, 0xb, &a, &b, &c, &d);
    } else {
        u32 a;
        u32 b;
        u32 c;
        u32 d;

        f32 fx = self->x - table[338];
        f32 fy = self->y - table[29];
        d = self->resource;
        c = color.word;
        b = c;
        a = d;
        fn_1_AA188((s32)fx, (s32)fy, 0xaa, 0xb, &a, &b, &c, &d);
    }
    fn_1_AA538();
    fn_1_4E0F4();
}
/* fzgx:end fn_3_268D0 */

/* fzgx:begin fn_3_273F4 noprologue */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct {
u8 unk_0;
u8 unk_1;
u8 pad_2[0x2];
s16 unk_4;
s16 unk_6;
s16 unk_8;
s16 unk_A;
s16 unk_C;
s16 unk_E;
u8 pad_10[0x14];
u32 unk_24;
s16 unk_28;
s16 unk_2A;
s16 unk_2C;
u8 pad_2E[0x2];
} Obj_3_bss_F0;
extern Obj_3_bss_F0 lbl_3_bss_F0;


typedef struct {
u8 unk_0;
u8 pad_1[0x3];
u32 unk_4;
u8 unk_8;
u8 pad_9[0x7];
u8 unk_10;
u8 pad_11[0x7];
s16 unk_18;
s16 unk_1A;
s16 unk_1C;
s16 unk_1E;
s16 unk_20;
s16 unk_22;
s16 unk_24;
u8 pad_26[0x4];
s16 unk_2A;
s16 unk_2C;
u8 pad_2E[0xA2];
} Obj_3_bss_20;
extern Obj_3_bss_20 lbl_3_bss_20;


typedef struct {
f32 unk_0;
f32 unk_4;
f32 unk_8;
f32 unk_C;
u8 pad_10[0x10];
f32 unk_20;
f32 unk_24;
u8 pad_28[0x10];
u8 unk_38;
u8 pad_39[0xF];
f32 unk_48;
u8 pad_4C[0xC];
u32 unk_58;
u8 pad_5C[0x134];
} Obj_3_bss_241E0;
extern Obj_3_bss_241E0 lbl_3_bss_241E0;


typedef struct {
u8 pad_0[0x2];
s16 unk_2;
f32 unk_4;
s16 unk_8;
u8 pad_A[0x4A6];
} Obj_3_bss_6D8C0;
extern Obj_3_bss_6D8C0 lbl_3_bss_6D8C0;


extern u8 lbl_3_data_4B84[0x14];


extern u32 lbl_3_data_4B98;


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
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);


typedef struct fn_3_273F4_Pool {
u8 pad_0[0x1c];
f32 unk_1C;
u8 pad_20[0x40];
f32 unk_60;
u8 pad_64[0x11c];
f32 unk_180;
u8 pad_184[0x4];
f32 unk_188;
u8 pad_18C[0x44];
f32 unk_1D0;
u8 pad_1D4[0x58];
f32 unk_22C;
u8 pad_230[0x14c];
f32 unk_37C;
u8 pad_380[0x74];
f32 unk_3F4;
u8 pad_3F8[0xc];
f32 unk_404;
u8 pad_408[0x10];
f32 unk_418;
u8 pad_41C[0xf8];
f32 unk_514;
u8 pad_518[0x4];
f32 unk_51C;
u8 pad_520[0x24];
f32 unk_544;
u8 pad_548[0x1c];
f32 unk_564;
u8 pad_568[0x34];
u32 unk_59C;
u32 unk_5A0;
u32 unk_5A4;
u32 unk_5A8;
f32 unk_5AC;
f32 unk_5B0;
f32 unk_5B4;
f32 unk_5B8;
f32 unk_5BC;
f32 unk_5C0;
f32 unk_5C4;
f32 unk_5C8;
f32 unk_5CC;
} fn_3_273F4_Pool;


extern u32 lbl_1_rodata_26F8;


extern void fn_1_49410(void);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);


extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_49738(u32 value);
extern u32 fn_3_2B750(s16, s16);


extern void fn_1_5233C(void *arg0, void *arg1);


extern void fn_1_50190(void *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5);
extern f32 lbl_3_rodata_768[];
extern s32 fn_3_1FF7C(void);
extern s32 fn_3_837C(s16 arg0);
extern u32 fn_3_23A1C(u32, u32, u32, u32, u32);
extern u32 fn_3_26A34(u32, u32, u32);
extern u32 fn_3_1C278(s16, u8, u8, u8, u32, f32);
extern void fn_1_133DBC(void* arg0);
extern void fn_1_8D1EC(void *, s32 (*)(u32), void *);
extern void fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_138120(void *);
extern void fn_1_495B0(u32 value);
extern void fn_1_4965C(u8 value);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void *fn_1_14EEC4(s16 index, void *obj, s16 subindex);
extern char *fn_1_14EA74(s32, char *, s16);
extern int fn_1_14EE00(s16 arg0, void *arg1, s16 arg2);


struct Sig_fn_1_8D1EC_fn_1_8D210_car;

#pragma opt_propagation off


#pragma opt_common_subs off

void fn_3_273F4(void) {
f32 h;
f32 w;
f32 y;
f32 x;
fn_3_273F4_Pool *pool;
s16 mode;
Obj_3_bss_20 *cfg;
Obj_3_bss_F0 *state;
u32 slot;
s16 value;
Obj_3_bss_6D8C0 *entry;
char buf[64];
FontDrawPacket pkt;
u32 color0;
u32 color1;
u32 color2;
u32 color3;
state = &lbl_3_bss_F0;
mode = state->unk_A;
pool = ((fn_3_273F4_Pool *)&lbl_3_rodata_768);
fn_1_133DBC((void *)1);
x = pool->unk_514;
y = pool->unk_1D0;
w = lbl_3_bss_241E0.unk_20;
h = lbl_3_bss_241E0.unk_24;
lbl_3_bss_241E0.unk_38 = 0;
lbl_3_bss_241E0.unk_58 = 0;
lbl_3_bss_241E0.unk_0 = x;
lbl_3_bss_241E0.unk_4 = y;
lbl_3_bss_241E0.unk_8 = w;
lbl_3_bss_241E0.unk_C = h;
fn_1_8D1EC( (void *)((struct Sig_fn_1_8D1EC_fn_1_8D210_car *)&lbl_3_bss_241E0), (s32 (*)(u32))fn_3_1FF7C, 0);
fn_1_134AD4();
if (fn_3_837C(lbl_3_bss_F0.unk_8) == 1) {
fn_1_13ABA8(0x28100000);
} else {
fn_1_13ABA8(0x28000000);
}
fn_1_138120((void *)fn_3_2B750(45, state->unk_A));
fn_3_23A1C(90, 90, 10, 151, 1);
cfg = &lbl_3_bss_20;
slot = *((u8 *)cfg + cfg->unk_18 * 8);
entry = (Obj_3_bss_6D8C0 *)((u8 *)&lbl_3_bss_6D8C0 + (s16)slot * 16);
{
s16 id;
id = entry->unk_8;
value = entry->unk_4;
pkt = (*((const FontDrawPacket *)&lbl_1_rodata_26F8));
pkt.image = 0x8904;
pkt.x = pool->unk_5AC;
pkt.y = pool->unk_51C;
pkt.z = pool->unk_60;
fn_1_50190(&pkt, pool->unk_3F4, pool->unk_5B0, pool->unk_180, pool->unk_180, pool->unk_564,
pool->unk_180);
fn_1_49410(); fn_1_495B0(0x80000000); fn_1_4965C(2); fn_1_4955C(pool->unk_1C, pool->unk_1C) ;
fn_1_496FC(pool->unk_418, pool->unk_5B4);
fn_1_4954C(pool->unk_5B8); fn_1_49738( (u32)(void *)(fn_1_5233C)); fn_1_49748(pool->unk_188) ;
color0 = pool->unk_59C;
fn_1_49514(&color0);
fn_1_4AE0C((const char *)lbl_3_data_4B84, fn_1_14EEC4(cfg->unk_18, buf, mode));
fn_1_49410(); fn_1_495B0(0x80000000); fn_1_4965C(2); fn_1_4955C(pool->unk_1C, pool->unk_1C) ;
switch (state->unk_A) {
default:
case 5:
fn_1_496FC(pool->unk_5BC, pool->unk_5B4);
break;
case 0:
fn_1_496FC(pool->unk_5C0, pool->unk_5B4);
break;
}
fn_1_4954C(pool->unk_5B8); fn_1_49738( (u32)(void *)(fn_1_5233C)); fn_1_49748(pool->unk_188) ;
color1 = pool->unk_5A0;
fn_1_49514(&color1);
fn_1_4AE0C((const char *)fn_3_2B750(0x20, mode));
fn_1_49410(); fn_1_495B0(0x80000000); fn_1_4965C(2); fn_1_4955C(pool->unk_1C, pool->unk_1C) ;
switch (state->unk_A) {
default:
case 5:
fn_1_496FC(pool->unk_404, pool->unk_5B4);
break;
case 0:
fn_1_496FC(pool->unk_5C4, pool->unk_5B4);
break;
}
fn_1_4954C(pool->unk_5B8); fn_1_49738( (u32)(void *)(fn_1_5233C)); fn_1_49748(pool->unk_188) ;
color2 = pool->unk_5A4;
fn_1_49514(&color2);
fn_1_4AE0C((const char *)fn_3_2B750(0x21, mode));
fn_1_49410(); fn_1_495B0(0x80000000); fn_1_4965C(2); fn_1_4955C(pool->unk_1C, pool->unk_1C) ;
fn_1_496FC(pool->unk_418, pool->unk_5C8);
fn_1_4954C(pool->unk_5B8); fn_1_49738( (u32)(void *)(fn_1_5233C)); fn_1_49748(pool->unk_188) ;
fn_1_4AE0C((const char *)lbl_3_data_4B84, fn_1_14EA74(slot, buf, mode));
fn_1_49410(); fn_1_495B0(0x80000000); fn_1_4965C(2); fn_1_4955C(pool->unk_1C, pool->unk_1C) ;
fn_1_496FC(pool->unk_5BC, pool->unk_5C8);
fn_1_4954C(pool->unk_5B8); fn_1_49738( (u32)(void *)(fn_1_5233C)); fn_1_49748(pool->unk_188) ;
fn_1_4AE0C((const char *)&lbl_3_data_4B98, value);
fn_1_49410(); fn_1_495B0(0x80000000); fn_1_4965C(2); fn_1_4955C(pool->unk_1C, pool->unk_1C) ;
fn_1_496FC(pool->unk_5CC, pool->unk_5C8);
fn_1_4954C(pool->unk_5B8); fn_1_49738( (u32)(void *)(fn_1_5233C)); fn_1_49748(pool->unk_188) ;
color3 = pool->unk_5A8;
fn_1_49514(&color3);
fn_1_4AE0C((const char *)lbl_3_data_4B84, fn_1_14EE00(id, buf, mode));
}
fn_3_26A34(0xa6, 0xf8, 0xc8);
pkt = (*((const FontDrawPacket *)&lbl_1_rodata_26F8));
pkt.image = 0x890c;
pkt.x = pool->unk_544;
pkt.y = pool->unk_37C;
pkt.z = pool->unk_22C;
fn_1_4F734(&pkt);
fn_3_1C278(*(s16 *)((u8 *)&lbl_3_bss_20 + 0xce), lbl_3_bss_20.unk_0, lbl_3_bss_20.unk_8,
lbl_3_bss_20.unk_10, 0, pool->unk_188);
}

#pragma opt_common_subs reset


#pragma opt_propagation reset
/* fzgx:end fn_3_273F4 */

/* fzgx:begin fn_3_28378 */
extern void fn_3_2406C(void);
extern f32 lbl_3_rodata_8F0[28];

typedef struct Packet {
    u32 unk0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x1c];
    f32 unk2c;
    u32 unk30;
    u8 pad34[0x1c];
    void *unk50;
    u8 pad54[4];
} Packet;

extern const Packet lbl_1_rodata_26F8;
extern int fn_1_4F734(Packet *);

#pragma opt_strength_reduction off
#pragma opt_dead_assignments off
#pragma opt_loop_invariants off
void fn_3_28378(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    u32 fzgx_value;
    s16 c = arg2;
    s32 d = arg3;
    void *fnptr = (void *)&fn_3_2406C;
    Packet packet;

    packet = lbl_1_rodata_26F8;
    packet.unk0 = d;
    packet.x = (f32)(arg0 - 8);
    packet.y = (f32)(arg1 - 1);
    packet.z = (f32)c;
    packet.unk30 = 0xf;
    if (fn_3_2406C) {
        packet.unk50 = fnptr;
        packet.unk30 |= 0x4000000;
    }
    packet.unk2c = lbl_3_rodata_8F0[0];
    fn_1_4F734(&packet);

    packet = lbl_1_rodata_26F8;
    packet.unk0 = d;
    packet.x = (f32)(arg0 + 8);
    packet.y = (f32)(arg1 - 1);
    packet.z = (f32)c;
    packet.unk30 = 0x8000d;
    if (fnptr) {
        packet.unk50 = fnptr;
        packet.unk30 |= 0x4000000;
    }
    packet.unk2c = lbl_3_rodata_8F0[0];
    fn_1_4F734(&packet);

    packet = lbl_1_rodata_26F8;
    packet.unk0 = d;
    packet.x = (f32)(arg0 - 8);
    packet.y = (f32)(arg1 + 1);
    packet.z = (f32)c;
    fzgx_value = 0x100007;
    packet.unk30 = fzgx_value;
    if (fnptr) {
        packet.unk50 = fnptr;
        packet.unk30 |= 0x4000000;
    }
    packet.unk2c = lbl_3_rodata_8F0[0];
    fn_1_4F734(&packet);

    packet = lbl_1_rodata_26F8;
    packet.unk0 = d;
    packet.x = (f32)(arg0 + 8);
    packet.y = (f32)(arg1 + 1);
    packet.z = (f32)c;
    packet.unk30 = 0x180005;
    if (fnptr) {
        packet.unk50 = fnptr;
        packet.unk30 |= 0x4000000;
    }
    packet.unk2c = lbl_3_rodata_8F0[0];
    fn_1_4F734(&packet);
}
#pragma opt_loop_invariants reset
#pragma opt_dead_assignments reset
#pragma opt_strength_reduction reset
/* fzgx:end fn_3_28378 */

/* fzgx:begin fn_3_2A2F8 */
#include "font.h"

struct fn_3_2A2F8_Copy88 { u32 a[22]; };
extern s32 lbl_3_bss_24370;
extern f64 lbl_3_rodata_800;
extern u32 lbl_1_rodata_26F8;
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);

void fn_3_2A2F8(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    s32 digit;
    s32 value;
    FontDrawPacket loc_8;

    if (arg4 < 0) {
        value = 0;
    } else {
        value = 0x1869F;
        if (arg4 <= 0x1869F) {
            value = arg4;
        }
    }
    if (lbl_3_bss_24370 - 1 > value) {
        value = lbl_3_bss_24370 - 1;
    }
    lbl_3_bss_24370 = value;

    loc_8 = *(const FontDrawPacket *)((const u8 *)&lbl_1_rodata_26F8);
    loc_8.image = 0xA302;
    loc_8.x = (f32)(arg0 - 0x32);
    loc_8.y = (f32)arg1;
    loc_8.z = (f32)(arg2 - 1);
    fn_1_4F734(&loc_8);

    loc_8 = *(const FontDrawPacket *)((const u8 *)&lbl_1_rodata_26F8);
    loc_8.image = 0xA311;
    loc_8.x = (f32)(arg0 - 0x3F);
    loc_8.y = (f32)(arg1 - 0xF);
    loc_8.z = (f32)arg2;
    fn_1_4F734(&loc_8);

    digit = lbl_3_bss_24370 % 10;
    loc_8 = *(const FontDrawPacket *)((const u8 *)&lbl_1_rodata_26F8);
    loc_8.image = 0xA300;
    loc_8.x = (f32)((((arg3 * 3) + (arg0)) + (3)));
    loc_8.y = (f32)arg1;
    loc_8.z = (f32)(arg2 - 2);
    fn_1_51564(0, 0, 0x10, 0x14, 0xA, 1);
    fn_1_5158C(&loc_8, loc_8.image, (s16)(digit % 10), (s16)(digit / 10));
    fn_1_4F734(&loc_8);

    digit = (lbl_3_bss_24370 / 10) % 10;
    loc_8 = *(const FontDrawPacket *)((const u8 *)&lbl_1_rodata_26F8);
    loc_8.image = 0xA300;
    loc_8.x = (f32)((((arg3 * 2) + (arg0)) + (3)));
    loc_8.y = (f32)arg1;
    loc_8.z = (f32)(arg2 - 2);
    fn_1_51564(0, 0, 0x10, 0x14, 0xA, 1);
    fn_1_5158C(&loc_8, loc_8.image, (s16)(digit % 10), (s16)(digit / 10));
    fn_1_4F734(&loc_8);

    digit = (lbl_3_bss_24370 / 100) % 10;
    loc_8 = *(const FontDrawPacket *)((const u8 *)&lbl_1_rodata_26F8);
    loc_8.image = 0xA300;
    loc_8.x = (f32)((((((arg0)) + ((arg3)))) + (3)));
    loc_8.y = (f32)arg1;
    loc_8.z = (f32)(arg2 - 2);
    fn_1_51564(0, 0, 0x10, 0x14, 0xA, 1);
    fn_1_5158C(&loc_8, loc_8.image, (s16)(digit % 10), (s16)(digit / 10));
    fn_1_4F734(&loc_8);

    digit = (lbl_3_bss_24370 / 1000) % 10;
    loc_8 = *(const FontDrawPacket *)((const u8 *)&lbl_1_rodata_26F8);
    loc_8.image = 0xA300;
    loc_8.x = (f32)(arg0 + 3);
    loc_8.y = (f32)arg1;
    loc_8.z = (f32)(arg2 - 2);
    fn_1_51564(0, 0, 0x10, 0x14, 0xA, 1);
    fn_1_5158C(&loc_8, loc_8.image, (s16)(digit % 10), (s16)(digit / 10));
    fn_1_4F734(&loc_8);

    digit = (lbl_3_bss_24370 / 10000) % 10;
    loc_8 = *(const FontDrawPacket *)((const u8 *)&lbl_1_rodata_26F8);
    loc_8.image = 0xA300;
    loc_8.x = (f32)((arg0 - arg3) + 3);
    loc_8.y = (f32)arg1;
    loc_8.z = (f32)(arg2 - 2);
    fn_1_51564(0, 0, 0x10, 0x14, 0xA, 1);
    fn_1_5158C(&loc_8, loc_8.image, (s16)(digit % 10), (s16)(digit / 10));
    fn_1_4F734(&loc_8);
}
/* fzgx:end fn_3_2A2F8 */

/* fzgx:begin fn_3_2B268 */
#include "font.h"

extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, int);
extern const f32 lbl_3_rodata_740;
extern void fn_3_1ABD8(void *arg0, s16 x1, s16 y1, s16 x2, s16 y2, u32 *value);
extern void fn_3_1B130(void *, s16, s16, u32 *);
extern void fn_3_149AC(void);
extern void fn_3_1BA20(void *target, s16 x, s16 y, s16 z, s16 w, s32 *value);
extern void fn_3_1BF08(void *, s16, s16, s16, s16, u32 *);
extern u8 lbl_3_bss_A2458[8];
extern void fn_3_BD98(void);
extern void fn_3_BEF0(void);
extern void fn_3_BE88(void);
extern void fn_3_156A8(void);
extern void fn_80074188(s16, s16, s16, s16);
extern void fn_1_5233C(void *, void *);
extern struct fn_3_1A1D8_lbl_1_bss_9F8 lbl_1_bss_9F8;



#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table2[6] = {0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0x0000FF00, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4583333432674408f;
    s = 284.0f;
    s = 329.0f;
    s = 100.0f;
    s = 0.9166666865348816f;
    s = 360.0f;
    s = 0.5416666865348816f;
    s = 441.0f;
    s = 332.0f;
    s = 345.0f;
    s = 358.0f;
    s = 0.48749998211860657f;
    s = 395.0f;
    s = 331.0f;
    s = 359.0f;
    s = 320.0f;
    s = 362.0f;
    s = 200.0f;
    s = 323.0f;
    s = 381.0f;
    s = 13.0f;
    s = 0.007843137718737125f;
    s = 6.0f;
    s = 7.0f;
    s = 0.14901961386203766f;
    s = 0.12941177189350128f;
    s = 132.0f;
    s = 150.0f;
    s = 0.800000011920929f;
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table6[43] = {0x00004A00, 0x00005400, 0x00003800, 0x00003E00, 0x00003700, 0x00005500, 0x00003000, 0x00003500, 0x00003A00, 0x00004000, 0x00004400, 0x00005000, 0x00003300, 0x00002E00, 0x00003100, 0x00004F00, 0x00003900, 0x00003D00, 0x00004C00, 0x00003F00, 0x00004800, 0x00005200, 0x00004500, 0x00005300, 0x00003C00, 0x00005600, 0x00004300, 0x00004200, 0x00003200, 0x00002F00, 0x00003400, 0x00003600, 0x00004D00, 0x00004600, 0x00004100, 0x00005100, 0x00004E00, 0x00004700, 0x00003B00, 0x00004B00, 0x00004900, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 380.0f;
    s = 334.0f;
    s = 0.40625f;
}
static const u32 fzgx_pool_table8[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 480.0f;
    s = 640.0f;
    s = 62.0f;
    s = 1.3411765098571777f;
    s = 8.0f;
    s = 0.125f;
    s = 1.0f;
    s = 0.5f;
    s = 215.0f;
    s = 3.0f;
    s = 180.0f;
    s = 90.0f;
    s = 240.0f;
    s = 44.0f;
    s = 89.9000015258789f;
    s = 40.0f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 80.0f;
    s = 460.0f;
    s = 0.6666666865348816f;
    s = 0.6078431606292725f;
    s = -3.0f;
    s = 0.0f;
    s = 0.6196078658103943f;
    s = 0.5058823823928833f;
    s = 216.0f;
    s = 0.20000000298023224f;
    s = 140.0f;
    s = 250.0f;
    s = 400.0f;
    s = 550.0f;
    s = 0.46666666865348816f;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table10[9] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 182.04444885253906f;
    s = 10.0f;
}
static const u32 fzgx_pool_table12[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.75f;
    s = 3.5f;
    s = 0.05000000074505806f;
}
static const u32 fzgx_pool_table14[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.25f;
}
static const u32 fzgx_pool_table16[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.5176470279693604f;
    s = 8.79411792755127f;
    s = 10.55294132232666f;
    s = 315.0f;
    s = 2.0f;
    s = 1.2999999523162842f;
    s = 0.6000000238418579f;
    s = 0.6274510025978088f;
    s = 0.7529411911964417f;
    s = 3.5999999046325684f;
    s = 9.0f;
}
static const u32 fzgx_pool_table18[2] = {0x00000000, 0x41200000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -5.0f;
}
static const u32 fzgx_pool_table20[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003, 0x00020001, 0x00000001, 0x00020003, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.211764812469482f;
}
static const u32 fzgx_pool_table22[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.21176470816135406f;
}
static const u32 fzgx_pool_table24[13] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00FFFF00, 0x00FFFF00, 0x00FF0000, 0x00FF0000, 0x00FF0000, 0x00FF0000, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 266.0f;
    s = 120.0f;
    s = 547.0f;
    s = 173.0f;
    s = 23.0f;
    s = 223.0f;
    s = 257.0f;
    s = 20.0f;
    s = 12.0f;
    s = 67.75f;
    s = 2.5f;
    s = 0.3499999940395355f;
    s = 0.15000000596046448f;
    s = 11.0f;
    s = 16.0f;
}
static const u32 fzgx_pool_table26[4] = {0x00FFFF00, 0x00FFFF00, 0x00FF0000, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 286.0f;
    s = 153.0f;
    s = 277.0f;
    s = -71.0f;
    s = 172.0f;
    s = 63.0f;
    s = 4.0f;
    s = 24.0f;
    s = 5.0f;
}
static const u32 fzgx_pool_table28[4] = {0x00170018, 0x0019001F, 0xFFFFFF00, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 127.0f;
    s = -2.0f;
    s = 15.0f;
    s = 0.4166666567325592f;
}
static const u32 fzgx_pool_table30[6] = {0x19FF1900, 0x19FF1900, 0x19FF1900, 0x00FFFF00, 0x00FFFF00, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 161.0f;
    s = 278.0f;
    s = 184.0f;
    s = 47.0f;
    s = 197.0f;
    s = 269.0f;
    s = 181.0f;
    s = 152.0f;
    s = 297.0f;
    s = 34.25f;
    s = 38.0f;
    s = 198.0f;
    s = 276.0f;
}
static const u32 fzgx_pool_table32[51] = {0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00006500, 0x00006D00, 0x00008000, 0x00005800, 0x00006900, 0x00007500, 0x00006400, 0x00007400, 0x00006300, 0x00006C00, 0x00005A00, 0x00006E00, 0x00008200, 0x00006B00, 0x00007900, 0x00006800, 0x00006A00, 0x00005900, 0x00006F00, 0x00005700, 0x00007200, 0x00007E00, 0x00007300, 0x00007100, 0x00005B00, 0x00008100, 0x00006200, 0x00007A00, 0x00005D00, 0x00007C00, 0x00005C00, 0x00006100, 0x00006000, 0x00005E00, 0x00007F00, 0x00005F00, 0x00007700, 0x00007000, 0x00007600, 0x00007800, 0x00007D00, 0x00006700, 0x00007B00, 0x00006600, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.75f;
    s = 37.0f;
    s = 74.0f;
    s = 26.0f;
    s = 70.0f;
}
static const u32 fzgx_pool_table34[4] = {0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 147.0f;
    s = 317.0f;
    s = 122.0f;
    s = 156.0f;
    s = 304.0f;
    s = 600.0f;
    s = 0.10000002384185791f;
    s = 0.3399999737739563f;
    s = -102.0f;
    s = 102.0f;
    s = 0.8999999761581421f;
    s = 0.6600000262260437f;
    s = 95.0f;
    s = 84.0f;
}
static const u32 fzgx_pool_table36[5] = {0x00230024, 0x00250000, 0xFFFFFF00, 0xFFFF0000, 0xFFF20000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 116.0f;
    s = 30.0f;
    s = 34.0f;
    s = 195.0f;
    s = 270.0f;
    s = 202.0f;
    s = 14.0f;
    s = 204.0f;
    s = 21.5f;
    s = 1.5f;
    s = 48.0f;
    s = 117.0f;
    s = 166.0f;
    s = 255.0f;
    s = 29.0f;
}
static const u32 fzgx_pool_table38[4] = {0x19FF1900, 0x19FF1900, 0x19FF1900, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 27.0f;
    s = 64.0f;
    s = 128.0f;
    s = 199.0f;
    s = 214.0f;
    s = 194.0f;
    s = 249.0f;
    s = 157.0f;
    s = 282.0f;
}
static const u32 fzgx_pool_table40[3] = {0x00000000, 0xC1A00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 76.0f;
    s = 229.0f;
    s = 299.0f;
    s = 1.3333333730697632f;
    s = 69.0f;
    s = 85.0f;
    s = 309.0f;
}
static const u32 fzgx_pool_table42[3] = {0x00000000, 0xC1A00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 308.0f;
}
static const u32 fzgx_pool_table44[6] = {0x00020001, 0xFF000000, 0xFFFFFF00, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep44(void) { const u32 *volatile cp; cp = fzgx_pool_table44; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime45(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -98.0f;
}
static const u32 fzgx_pool_table46[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep46(void) { const u32 *volatile cp; cp = fzgx_pool_table46; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime47(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
}
static const u32 fzgx_pool_table48[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep48(void) { const u32 *volatile cp; cp = fzgx_pool_table48; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime49(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 56.35000228881836f;
    s = 9.449999809265137f;
}
static const u32 fzgx_pool_table50[10] = {0x0000A309, 0x0000A307, 0x0000A308, 0x0000A31C, 0x0000A318, 0x0000A31A, 0x0000A31D, 0x0000A319, 0x0000A31B, 0xFFF200FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep50(void) { const u32 *volatile cp; cp = fzgx_pool_table50; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime51(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 17.0f;
    s = 131.0f;
    s = 190.0f;
    s = 72.0f;
    s = 54.0f;
    s = 167.0f;
    s = 211.0f;
    s = 190.10000610351562f;
    s = 0.48627451062202454f;
    s = 0.6117647290229797f;
}
static const u32 fzgx_pool_table52[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep52(void) { const u32 *volatile cp; cp = fzgx_pool_table52; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime53(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 594.0f;
    s = 124.0f;
    s = 148.0f;
    s = 25.0f;
    s = 300.0f;
    s = 0.0010000000474974513f;
}
#pragma section code_type ".text"
typedef s32 (*Sig_fn_1_8D210_fn_1_8D210_callback)(u32);
typedef struct Sig_fn_1_8D210_fn_1_8D210_car {
    f32 position[6];
    f32 scale_z;
    f32 scale_y;
    f32 scale_x;
    f32 field_24;
    u16 field_28;
    u16 field_2a;
    u16 field_2c;
    u16 field_2e;
    u16 field_30;
    u16 field_32;
    u32 field_34;
    u8 field_38;
    u8 field_39;
    u8 field_3a;
    u8 pad_3b;
    u32 field_3c;
    u8 field_40;
    u8 pad_41[3];
    f32 field_44;
    f32 field_48;
    f32 field_4c;
    f32 field_50;
    s16 field_54;
    u8 pad_56[2];
    s32 field_58;
    u8 field_5c[4];
    u32 field_60;
} Sig_fn_1_8D210_fn_1_8D210_car;
struct fn_3_2B268_Copy88 { u32 a[22]; };
struct fn_3_2B268_lbl_3_rodata_768 {
    u8 pad_0[0x28];
    f32 unk_28;
    u8 pad_2c[0x2c];
    f32 unk_58;
    u8 pad_5c[0x1c];
    f32 unk_78;
    u8 pad_7c[0x1c];
    f64 unk_98;
    u8 pad_a0[0xe8];
    f32 unk_188;
    f32 unk_18C;
    u8 pad_190[0x10];
    f32 unk_1A0;
    u8 pad_1a4[0x2c];
    f32 unk_1D0;
    u8 pad_1d4[0x14];
    f32 unk_1E8;
    u8 pad_1ec[0xc];
    f64 unk_1F8;
    u8 pad_200[0x2c];
    f32 unk_22C;
    u8 pad_230[0x80];
    f32 unk_2B0;
    u8 pad_2b4[0xa0];
    f32 unk_354;
    u8 pad_358[0xc];
    f32 unk_364;
    u8 pad_368[0x14];
    f32 unk_37C;
    u8 pad_380[0x1c];
    f32 unk_39C;
    u8 pad_3a0[0x4];
    f32 unk_3A4;
    u8 pad_3a8[0x4];
    f32 unk_3AC;
    f32 unk_3B0;
    u8 pad_3b4[0x10];
    f32 unk_3C4;
    u8 pad_3c8[0x44];
    f32 unk_40C;
    u8 pad_410[0xe0];
    f32 unk_4F0;
    u8 pad_4f4[0x198];
    u32 unk_68C;
    f32 unk_690;
    f32 unk_694;
    f32 unk_698;
    f32 unk_69C;
    f32 unk_6A0;
    f32 unk_6A4;
};

struct fn_3_2B268_lbl_1_bss_7F0C0 {
    u8 pad_0[0x48F8];
    u32 unk_48F8;
};
extern f32 fn_1_A6FE8(void);
extern struct fn_3_2B268_lbl_1_bss_7F0C0 lbl_1_bss_7F0C0;
extern u32 fn_3_1EFE4(void);
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A66C0[1];
extern void fn_1_133DBC(void *);
extern void fn_1_8D1EC(Sig_fn_1_8D210_fn_1_8D210_car *, Sig_fn_1_8D210_fn_1_8D210_callback, void *);
extern void fn_3_2A2F8(s16, s16, s16, s16, s32);
extern void fn_3_7A08(s16 *, s16 *, int);
extern u32 fn_1_50190(void *, f32, f32, f32, f32, f32, f32);
extern void fn_1_50164(void *, f32, f32, f32, f32, f32, f32);
extern u32 fn_3_225F8(u32, u32, u32);
extern void fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_54278(u32, u32);
extern void fn_1_5428C(f32);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32);
extern void fn_1_4965C(u8);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495A0(f32);
extern void fn_1_4955C(f32, f32);
extern u32 fn_3_2B750(s16, s16);
extern void fn_1_4AE0C(const char *, ...);
#define clamp(value, min, max) ((value) < (min) ? (min) : (value) > (max) ? (max) : (value))
void fn_3_2B268(void) {
    struct fn_3_2B268_lbl_3_rodata_768 *p_lbl_3_rodata_768;
    f32 v0;
    f32 v1;
    f32 v2;
    f32 v3;
    f64 v4;
    f32 v5;
    f32 v6;
    f32 v7;
    f64 v8;
    u32 v9;
    f32 v10;
    u32 v11;
    u32 v12;
    u32 loc_C;
    FontDrawPacket loc_68;
    FontDrawPacket loc_10;
    s16 loc_A;
    s16 loc_8;
    f32 t1;
    f32 width;
    f32 half;
    f32 center;
    f32 fade;
    f32 time;
    fn_1_133DBC((void *)1);
    lbl_3_bss_241E0.unk_38 = 0;
    lbl_3_bss_241E0.unk_58 = 0;
    lbl_3_bss_241E0.unk_0 = 0.0f;
    lbl_3_bss_241E0.unk_4 = -71.0f;
    lbl_3_bss_241E0.unk_8 = lbl_3_bss_241E0.unk_20;
    lbl_3_bss_241E0.unk_C = lbl_3_bss_241E0.unk_24;
    t1 = fn_1_A6FE8();
    lbl_3_bss_241E0.unk_48 = t1;
    fn_1_8D1EC((Sig_fn_1_8D210_fn_1_8D210_car *)&lbl_3_bss_241E0, (Sig_fn_1_8D210_fn_1_8D210_callback)fn_3_1EFE4, (void *)0);
    fn_3_2A2F8(552, 25, 5, 15, lbl_1_bss_7F0C0.unk_48F8);
    v4 = 4503601774854144.0;
    v5 = 5.0f;
    v6 = (f32)(v5 / (f32)(s32)lbl_3_bss_7E23C);
    v7 = clamp(v6, 0.0f, 1.0f);
    fn_3_7A08(&loc_A, &loc_8, 5);
    v8 = 4503601774854144.0;
    v0 = (f32)(s32)(loc_A + loc_8);
    v1 = 0.5f;
    v10 = (f32)((f32)(v0 * v1) / (f32)((f32)(s32)lbl_3_bss_7E23C - 1.0f));
    loc_10 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v3 = 7.0f;
    loc_10.image = 0x8921;
    loc_10.x = 594.0f;
    loc_10.y = 250.0f;
    loc_10.z = 10.0f;
    loc_10.flags = 6;
    fn_1_50190(&loc_10, 16.0f, 152.0f, v3, v3, 23.0f, v3);
    width = 124.0f * clamp(v7, 0.0f, 1.0f);
    loc_10 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_10.image = 0x8902;
    loc_10.x = 594.0f;
    center = clamp(24.0f + (f32)(124.0f * clamp(v10, 0.0f, 1.0f)),
                   24.0f + (half = (f32)(width * (v0 = 0.5f))), 148.0f - half);
    loc_10.y = 250.0f + center;
    loc_10.z = 9.0f;
    loc_10.flags = 10;
    v3 = 5.0f;
    fn_1_50164(&loc_10, 12.0f, width, v3, v3, loc_10.y, center);
    fn_3_225F8(303, 326, 200);
    fn_1_134AD4();
    fn_1_13ABA8(0x28000000);
    loc_68 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_68.image = 0xA310;
    loc_68.x = 63.0f;
    loc_68.y = 16.0f;
    loc_68.z = 10.0f;
    fn_1_4F734(&loc_68);
    if (lbl_3_bss_7E23C == 0) {
        fade = 1.0f;
        v9 = lbl_801A66C0[0];
        if (v9 < 25) {
            time = (f32)v9 / 25.0f;
            v1 = fade - time;
            fn_1_54278((s32)((f32)(320.0f * v1) * v1), 0);
            fade = time * time;
        } else {
            fn_1_54278(0, 0);
        }
        fn_1_5428C(fade);
        loc_C = fzgx_pool_table52[0];
        fn_1_53BD8(&loc_C, 320.0f, 240.0f, 300.0f, 100.0f, 0.1f);
        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_4965C(2);
        fn_1_495C8(9);
        fn_1_496FC(320.0f, 240.0f);
        fn_1_4954C(0.001f);
        fn_1_495A0(fade);
        v1 = 0.75f;
        fn_1_4955C(v1, v1);
        fn_1_4AE0C((const char *)fn_3_2B750(50, lbl_3_bss_F0.unk_A));
        fn_1_54278(0, 0);
    }
}
/* fzgx:end fn_3_2B268 */

/* fzgx:begin fn_3_2B750 noprologue */
#include "types.h"

extern u8 lbl_3_data_4648[1320];

u32 fn_3_2B750(s16 arg0, s16 arg1) {
    return *(u32 *)(lbl_3_data_4648 + arg0 * 0x18 + arg1 * 4);
}
/* fzgx:end fn_3_2B750 */

/* fzgx:begin fn_3_2B774 */
// fn_3_2B774: empty in retail (single blr).
void fn_3_2B774(void) {
}
/* fzgx:end fn_3_2B774 */

/* fzgx:begin fn_3_2BFB4 noprologue */
#include "types.h"
#include "font.h"

struct fn_3_2BFB4_lbl_3_data_3D50 {
    u8 pad_0[0x8F8];
    u8 unk_8F8[0x800];
};
struct fn_3_2BFB4_lbl_3_rodata_768 {
    u8 pad_0[0x22C];
    f32 unk_22C;
    u8 pad_230[0x1E8];
    f32 unk_418;
    u8 pad_41C[0x25C];
    f32 unk_678;
};
struct fn_3_2BFB4_lbl_801A66B4 {
    u32 unk_0;
};

extern int fn_1_4F734(FontDrawPacket *);
extern int sprintf(char *, const char *, ...);
extern struct fn_3_2BFB4_lbl_3_data_3D50 lbl_3_data_3D50;
extern struct fn_3_2BFB4_lbl_3_rodata_768 lbl_3_rodata_768;
extern struct fn_3_2BFB4_lbl_801A66B4 lbl_801A66B4;
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern u32 lbl_1_rodata_26F8;
extern u8 fn_1_B7C00(void);
extern void fn_1_133DBC(void *);
extern void fn_1_138120(void *);

#pragma opt_propagation off
void fn_3_2BFB4(void) {
    struct fn_3_2BFB4_lbl_3_data_3D50 *p_lbl_3_data_3D50;
    struct fn_3_2BFB4_lbl_3_rodata_768 *p_lbl_3_rodata_768;
    struct { u8 * value; } v2;
    u8 t5;
    f32 v4;
    f32 v1;
    f32 v0;
    char * lab_t0;
    struct { u32 a[66]; } loc_60;
    FontDrawPacket loc_8;
    u32 lab_t3;

    p_lbl_3_data_3D50 = (struct fn_3_2BFB4_lbl_3_data_3D50 *)&lbl_3_data_3D50;
    p_lbl_3_rodata_768 = (struct fn_3_2BFB4_lbl_3_rodata_768 *)&lbl_3_rodata_768;
    fn_1_133DBC((void *)1);
    fn_1_134AD4();
    fn_1_13ABA8(0);
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;


    v0 = p_lbl_3_rodata_768->unk_678;
    v1 = p_lbl_3_rodata_768->unk_418;
    v4 = p_lbl_3_rodata_768->unk_22C;
    loc_8.image = (0x10000 - 31485);
    loc_8.x = v0;
    loc_8.y = v1;
    loc_8.z = v4;
    loc_8.flags = 10;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    fn_1_13ABA8(0x28000000);
    if ((s32)lbl_801A66B4.unk_0 == 0) {
    t5 = fn_1_B7C00();
    if ((t5 & 0x1) != 0) {
    { u8 * __reg_value_v2 = (u8 *)p_lbl_3_data_3D50; v2.value = __reg_value_v2; }
    { u8 * __reg_value_v2 = v2.value + 0x8f8; v2.value = __reg_value_v2; }
    { u8 * __reg_value_v2 = v2.value + ((s16)lbl_801A66B4.unk_0 << 2); v2.value = __reg_value_v2; }
    lab_t3 = *(u32 *)(v2.value + 0x4f8);
    sprintf((char *)&loc_60, (const char *)((u8 *)p_lbl_3_data_3D50 + 0xe58), *(u32 *)(v2.value + 0x4e0), lab_t3);
    } else {
    if ((((t5) & ((0xFF) & (0x2)))) != 0) {
    { u8 * __reg_value_v2 = (u8 *)p_lbl_3_data_3D50 + 0x8f8; v2.value = __reg_value_v2; }
    { u8 * __reg_value_v2 = v2.value + ((s16)lbl_801A66B4.unk_0 << 2); v2.value = __reg_value_v2; }
    lab_t3 = *(u32 *)(v2.value + 0x510);
    sprintf(((char *)&loc_60), (const char *)((u8 *)p_lbl_3_data_3D50 + 0xe58), *(u32 *)(v2.value + 0x4e0), lab_t3);
    } else {
    { u8 * __reg_value_v2 = (u8 *)p_lbl_3_data_3D50 + 0x8f8; v2.value = __reg_value_v2; }
    { u8 * __reg_value_v2 = v2.value + ((s16)lbl_801A66B4.unk_0 << 2); v2.value = __reg_value_v2; }
    sprintf((char *)&loc_60, (const char *)((u8 *)p_lbl_3_data_3D50 + 0xe60), *(u32 *)(v2.value + 0x4e0));
    }
    }
    } else {
    { u8 * __reg_value_v2 = (u8 *)p_lbl_3_data_3D50 + 0x8f8; v2.value = __reg_value_v2; }
    { u8 * __reg_value_v2 = v2.value + ((s16)lbl_801A66B4.unk_0 << 2); v2.value = __reg_value_v2; }
    sprintf((char *)&loc_60, (const char *)((u8 *)p_lbl_3_data_3D50 + 0xe60), *(u32 *)(v2.value + 0x4e0));
    }
    fn_1_138120((void *)&loc_60);
}
#pragma opt_propagation reset
/* fzgx:end fn_3_2BFB4 */

/* fzgx:begin fn_3_2C164 noprologue */
#include "types.h"
#include "font.h"

struct fn_3_2C164_Copy88 { u32 a[22]; };
struct fn_3_2C164_lbl_3_bss_F0 {
    u8 pad_0[0x4];
    s16 unk_4;
    u8 pad_6[0x4];
    s16 unk_A;
};
struct fn_3_2C164_lbl_3_rodata_768 {
    u8 pad_0[0x22C];
    f32 unk_22C;
    u8 pad_230[0x1E8];
    f32 unk_418;
    u8 pad_41C[0x25C];
    f32 unk_678;
};
struct fn_3_2C164_lbl_3_data_4648 {
    u8 pad_0[0x498];
    u32 unk_498[1];
};

extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_3_2C164_lbl_3_bss_F0 lbl_3_bss_F0;
extern struct fn_3_2C164_lbl_3_data_4648 lbl_3_data_4648;
extern struct fn_3_2C164_lbl_3_rodata_768 lbl_3_rodata_768;
extern u32 fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern u32 fn_3_2B778(s16, u32, u32, u32, u32);
extern u32 lbl_1_rodata_26F8;
extern void fn_1_133DBC(void *);
extern void fn_1_138120(void *);

void fn_3_2C164(void) {
    f32 fzgx_live;
    struct fn_3_2C164_lbl_3_bss_F0 *p_lbl_3_bss_F0;
    struct fn_3_2C164_lbl_3_rodata_768 *p_lbl_3_rodata_768;
    s32 v0;
    s32 v1;
    f32 v2;
    f32 v3;
    FontDrawPacket loc_8;
    /* frame */
{
    s32 fzgx_loop_v0_1245;
    fzgx_loop_v0_1245 = 0;
    v1 = 128;
    p_lbl_3_rodata_768 = (struct fn_3_2C164_lbl_3_rodata_768 *)&lbl_3_rodata_768;
    p_lbl_3_bss_F0 = (struct fn_3_2C164_lbl_3_bss_F0 *)&lbl_3_bss_F0;
    while ((s16)fzgx_loop_v0_1245 < 3) {
    fn_3_2B778((s16)v1, 236, 10, fzgx_loop_v0_1245, ((u32)__cntlzw(((s16)fzgx_loop_v0_1245 - p_lbl_3_bss_F0->unk_4)) >> 5));
    v1 += 192;
    fzgx_loop_v0_1245++;
    }
    v0 = fzgx_loop_v0_1245;
}
    fn_1_133DBC((void *)1);
    fn_1_134AD4();
    fn_1_13ABA8(0x28000000);
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v2 = p_lbl_3_rodata_768->unk_678;
    fzgx_live = p_lbl_3_rodata_768->unk_418;
    v3 = fzgx_live;
    loc_8.image = (0x10000 - 31485);
    loc_8.x = v2;
    loc_8.y = v3;
    loc_8.z = p_lbl_3_rodata_768->unk_22C;
    loc_8.flags = 10;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    fn_1_138120((void *)lbl_3_data_4648.unk_498[lbl_3_bss_F0.unk_A]);
}
/* fzgx:end fn_3_2C164 */
