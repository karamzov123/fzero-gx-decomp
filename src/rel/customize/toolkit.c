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

/* fzgx:begin fn_3_1B130 noprologue */
#include "types.h"
#include "font.h"
#include "types.h"

#ifndef GAME_VEC3_H
#define GAME_VEC3_H

#endif  // GAME_VEC3_H

/* end game/vec3.h */

typedef struct Rgba {
    u8 r, g, b, a;
} Rgba;

extern Rgba fn_3_149AC(void *, s16, s16);
extern void fn_3_146C0(void *, s16, s16, s16, Rgba *);
extern void fn_80008BEC(void *, int, u32);

/* Scanline flood fill of the region whose colour equals the pixel at (x, y). */
void fn_3_1B130(void *data, s16 x, s16 y, Rgba color) {
    s16 queue_x[0x1000];
    s16 queue_y[0x1000];
    Rgba pixel;
    Rgba target;
    Rgba fill;
    s16 left;
    s16 right;
    s16 head = 0;
    s16 tail = 1;

    target = fn_3_149AC(data, x, y);
    fn_80008BEC(queue_x, 0xff, 0x2000);
    fn_80008BEC(queue_y, 0xff, 0x2000);
    queue_x[0] = x;
    queue_y[0] = y;
    if ((target.r >> 3) == (color.r >> 3) && (target.g >> 3) == (color.g >> 3) &&
        (target.b >> 3) == (color.b >> 3) && target.a == color.a) {
        return;
    }

    while (head != tail) {
        for (x = queue_x[head]; x >= 0; x--) {
            pixel = fn_3_149AC(data, x, queue_y[head]);
            if (pixel.r != target.r || pixel.g != target.g || pixel.b != target.b ||
                pixel.a != target.a) {
                left = x + 1;
                break;
            }
        }
        if (x == -1) {
            left = 1;
        }
        for (x = queue_x[head] + 1; x < 0x3f; x++) {
            pixel = fn_3_149AC(data, x, queue_y[head]);
            if (pixel.r != target.r || pixel.g != target.g || pixel.b != target.b ||
                pixel.a != target.a) {
                right = x;
                break;
            }
        }
        if (x == 0x3f) {
            right = 0x3f;
        }
        fill = color;
        fn_3_146C0(data, left, queue_y[head], right - left, &fill);

        for (x = left, y = right; x < y; x++) {
            s32 ny = queue_y[head] - 1;
            if (ny < 1) {
                break;
            }
            pixel = fn_3_149AC(data, x, (s16)ny);
            if (pixel.r == target.r && pixel.g == target.g && pixel.b == target.b &&
                pixel.a == target.a) {
                queue_x[tail] = x;
                queue_y[tail] = queue_y[head] - 1;
                tail = (tail + 1) % 0x1000;
            }
        }
        for (x = left, y = right; x < y; x++) {
            s32 ny = queue_y[head] + 1;
            if (ny >= 0x3f) {
                break;
            }
            pixel = fn_3_149AC(data, x, (s16)ny);
            if (pixel.r == target.r && pixel.g == target.g && pixel.b == target.b &&
                pixel.a == target.a) {
                queue_x[tail] = x;
                queue_y[tail] = queue_y[head] + 1;
                tail = (tail + 1) % 0x1000;
            }
        }
        head = (head + 1) % 0x1000;
    }
}
/* fzgx:end fn_3_1B130 */

/* fzgx:begin fn_3_1B4BC */
extern void fn_3_146C0(void *, s16, s16, s16, u32 *);

#pragma section code_type ".fzgxpool"
/* Primes the unit's literal pool in retail first-use order so the shared
 * pool offsets line up; mwld ignores this section. */
static void fzgx_pool_primer(volatile f32 *f, volatile f64 *d, s32 i, u32 u) { /* volatile: keeps every literal store so the pool order is fixed */
    *f=24.0f; *f=86.0f; *f=100.0f; *f=385.0f;
    *f=170.0f; *f=104.0f; *f=40.0f; *f=96.0f;
    *f=90.0f; *f=0.5f; *f=20.0f; *f=60.0f;
    *f=80.0f; *f=15.0f; *f=30.0f; *f=320.0f;
    *f=372.0f; *f=0.1f; *f=0.6f; *f=375.0f;
    *f=0.75f; *f=248.0f; *f=1.0f; *f=0.8f;
    *f=240.0f; *f=25.0f; *f=1.02f; *f=1.01f;
    *f=0.4f; *f=32768.0f; *f=10.0f; *f=81.0f;
    *f=399.0f; *f=18.0f; *f=12.0f;
    *d=4503601774854144.0; *d=4503599627370496.0; *d=0.0;
    *f=0.0f; *f=-1.0f; *d=0.5;
}
#pragma section code_type ".text"
typedef struct { u32 rgba; } LineColor;
static inline void line_point(void *dst, s16 x, s16 y, LineColor color) {
    s16 i;
    s32 radius;
    u16 width;
    width = lbl_3_bss_A2438.unk_C * 2 + 1;
    radius = width;
    radius = radius >> 1;
    for (i = -radius; i <= radius; i++) {
        LineColor c = color;
        fn_3_146C0(dst, x - radius, y + i, width, &c.rgba);
    }
}

void fn_3_1B4BC(void *dst, s16 x0, s16 y0, s16 x1, s16 y1, LineColor *color) {
    s16 start;
    s16 hi;
    s16 tmp;
    s16 lo;
    f32 slope;
    f32 error;
    if (x1 == x0) {
        if (y1 > y0) { start = y0; hi = y1; }
        else { start = y1; hi = y0; }
        for (lo = start; lo <= hi; lo++) line_point(dst, x0, lo, *color);
    } else if (y1 == y0) {
        if (x1 > x0) { start = x0; hi = x1; }
        else { start = x1; hi = x0; }
        for (lo = start; lo <= hi; lo++) line_point(dst, lo, y0, *color);
    } else {
        slope = (f32)(y1 - y0) / (f32)(x1 - x0);
        error = 0.0f;
        line_point(dst, x0, y0, *color);
        if (slope < 0.0f) {
            if (x0 > x1) { tmp = x0; x0 = x1; x1 = tmp; y0 = y1; }
            while (x0 < x1) {
                if (slope > -1.0f) line_point(dst, x0, y0, *color);
                error -= slope;
                x0++;
                while (error > 0.5) {
                    error -= 1.0f;
                    y0--;
                    line_point(dst, x0, y0, *color);
                }
            }
        } else {
            if (x0 > x1) { tmp = x0; x0 = x1; x1 = tmp; }
            if (y0 > y1) y0 = y1;
            while (x0 < x1) {
                if (slope < 1.0f) line_point(dst, x0, y0, *color);
                error += slope;
                x0++;
                while (error > 0.5) {
                    error -= 1.0f;
                    y0++;
                    line_point(dst, x0, y0, *color);
                }
            }
        }
    }
}
/* fzgx:end fn_3_1B4BC */

/* fzgx:begin fn_3_1BA20 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/toolkit.h"
#include "font.h"
#include "types.h"

/* begin game/vec3.h (deltawave784/fzgx, CC0) */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,
// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,
// stcoli). Hand-owned (librarian).


typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

#endif  // GAME_VEC3_H

/* end game/vec3.h */





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

typedef struct CustomizeData {
    u32 unk_00[2];
    u32 unk_08;
    u8 pad_0c[0x14];
    void *unk_20;
} CustomizeData;

struct fn_3_1A1D8_lbl_1_bss_9F8_0_E20 {
    u8 pad_0[0x10];
    u16 unk_10;
    u8 pad_12[0x2];
};

struct fn_3_1A1D8_lbl_1_bss_9F8 {
    struct fn_3_1A1D8_lbl_1_bss_9F8_0_E20 unk_0[1];
};

struct fn_3_1A264_lbl_1_bss_9F8_10_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};

struct fn_3_1A264_lbl_1_bss_9F8 {
    u8 pad_0[0x10];
    struct fn_3_1A264_lbl_1_bss_9F8_10_E20 unk_10[1];
};

typedef struct {
    u8 r, g, b, a;
} QColor;

typedef struct { u32 id; f32 x,y,z; u32 rest[18]; } Packet23524;

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

struct fn_3_23724_Copy88 {
    u32 flags;
    f32 x, y, z;
    u32 pad[8];
    u32 mode;
    u32 tail[9];
};

typedef struct {
    u32 flags;
    u8 pad[0x1c];
} fn_3_1F81C_CustomizeEntry;

typedef struct CustomizeObject CustomizeObject;

struct CustomizeObject {
    u8 pad0[0x18];
    u16 count;
    u8 pad1[0x26];
    fn_3_1F81C_CustomizeEntry entries[1];
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

struct fn_3_20374_lbl_1_data_1E5C0 {
u32 unk_0,unk_4,unk_8; f32 unk_C,unk_10,unk_14; u32 unk_18,unk_1C,unk_20,unk_24,unk_28,unk_2C,unk_30;
};

struct fn_3_23724_lbl_3_rodata_768 {
    u8 pad_0[0x78];
    f32 seven;
    u8 pad_7C[0x10C];
    f32 one;
    f32 half;
    u8 pad_190[0x40];
    f32 zero;
    u8 pad_1D4[0x180];
    f32 twentythree;
    u8 pad_358[0xC];
    f32 twelve;
    u8 pad_368[0x40];
    f32 unk_3A8;
    f32 unk_3AC;
    f32 five;
};

struct fn_3_2BFB4_lbl_3_rodata_768 {
    u8 pad_0[0x22C];
    f32 unk_22C;
    u8 pad_230[0x1E8];
    f32 unk_418;
    u8 pad_41C[0x25C];
    f32 unk_678;
};

struct fn_3_2C164_lbl_3_rodata_768 {
    u8 pad_0[0x22C];
    f32 unk_22C;
    u8 pad_230[0x1E8];
    f32 unk_418;
    u8 pad_41C[0x25C];
    f32 unk_678;
};

struct fn_3_20374_lbl_3_rodata_768 {
f32 unk_0; u8 pad_4[0x94]; f64 unk_98; u8 pad_A0[0xE8]; f32 unk_188;
u8 pad_18C[0x6C]; f64 unk_1F8; u8 pad_200[0x28]; f32 unk_228;
u8 pad_22C[0x5C]; f32 unk_288,unk_28C,unk_290,unk_294,unk_298,unk_29C,unk_2A0,unk_2A4,unk_2A8;
};

typedef struct Sig_fn_1_87610_Fn187610Data {
u8 pad_000[2]; s8 field_002; u8 pad_003[0x205]; u8 field_208[0x120];
} Sig_fn_1_87610_Fn187610Data;

typedef struct Sig_fn_8006F038_Vec3 { f32 x,y,z; } Sig_fn_8006F038_Vec3;

struct fn_3_2B268_lbl_1_bss_7F0C0 {
    u8 pad_0[0x48F8];
    u32 unk_48F8;
};

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

typedef s32 (*Sig_fn_1_8D210_fn_1_8D210_callback)(u32);

struct fn_3_2BFB4_lbl_801A66B4 {
    u32 unk_0;
};

typedef struct Rgba {
    u8 r, g, b, a;
} Rgba;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    Vec3 pos;
    u32 unk_18[7];
} Fn3_1FF7C_Camera;

typedef struct {
    u8 pad_0[0x60];
    Vec3 pos;
    f32 unk_6C;
} Fn3_1FF7C_Mtx;

typedef struct {
    u32 flags;
    u8 pad_4[0x1C];
} Fn3_1FF7C_Entry;

typedef struct {
    u8 pad_0[0x18];
    u16 count;
    u8 pad_1A[0x26];
    Fn3_1FF7C_Entry entries[1];
} Fn3_1FF7C_Model;


typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} fn_3_1A648_Pad;

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
extern const f32 lbl_3_rodata_740;
extern void fn_3_1B130(void *data, s16 x, s16 y, Rgba color);
extern void fn_3_BE10(void);
extern void fn_3_BEF0(void);
extern void fn_3_1445C(void);
extern void fn_3_BE88(void);
extern void fn_80008BA8(u32 *, void *, s32);
extern s32 fn_8008023C(u32 arg0, u32 arg1, u32 arg2);
extern struct fn_3_1A1D8_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern u32 fn_3_141A8(u32);
extern u8 fn_3_1443C(void);
extern u32 fn_3_14064(void);
extern u32 fn_3_1401C(void);
extern u32 fn_3_1402C(u8 index);
extern void fn_1_A2D84(u32 arg0);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_3_1B4BC(void *, s16, s16, s16, s16, u32 *);
extern void fn_3_149AC();
extern void fn_3_14794(void *, u32, u32, u32 *);
extern void fn_3_146C0(void *arg0, s16 x, s16 y, s16 delta, u32 *arg4);
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A66A8;
extern u16 fn_1_A5DB0(void);
extern s32 fn_1_A5DC4(void);
extern f32 lbl_8006D188(s32);
extern void fn_1_50164();
extern void fn_1_49410(void);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49590(f32 value);
extern void fn_1_495A0(f32 value);
extern void fn_1_495C8(u8 value);
extern void fn_1_4966C(f32 value1, f32 value2);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_49738(u32 value);
extern u32 fn_3_2B750(s16, s16);
extern void fn_3_2406C(void);
extern void fn_3_240DC(void *, void *);
extern void fn_1_5233C(void *arg0, void *arg1);
extern struct fn_3_20374_lbl_1_data_1E5C0 lbl_1_data_1E5C0;
extern u32 lbl_801A66A0;
extern CustomizeObject *lbl_801A6D00;
extern void fn_8006F038(Vec3 *arg0, Vec3 *arg1, s16 arg2);
extern void lbl_8006DCDC(void);
extern void fn_1_F7870(u32 value);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern u32 fn_1_56018(s32 value);
extern void lbl_8006D784(void *);
extern void fn_1_560F0(s32 index, void *arg);
extern void fn_80072558(void);
extern void fn_1_55210(CustomizeObject *);
extern void lbl_8006DB74(void*);
extern void fn_1_151BDC(u32 value);
extern void fn_1_14E2DC(void *, s16, f32);
extern void lbl_8006DBAC(Vec3 *);
extern void fn_1_FCFA4(void *);
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
extern f32 fn_1_A6FE8(void);
extern u8 lbl_1_bss_7F0C0[];
extern u32 fn_3_1EFE4(void);
extern u32 lbl_801A66C0[1];
extern void fn_3_2A2F8(s16, s16, s16, s16, s32);
extern void fn_3_7A08(s16 *arg0, s16 *arg1, int arg2);
extern u32 fn_3_225F8(u32, u32, u32);
extern void fn_1_54278(u32 arg0, u32 arg1);
extern void fn_1_5428C(f32 value);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern void fn_1_495FC(void);
extern u32 fn_3_2B778(s16, u32, u32, u32, u32);
extern f32 lbl_8006D118(f32 *, f32);
extern void fzgx_usef(f32);
extern void fzgx_used(f64);
extern void fzgx_usep(void *);
extern s32 fzgx_sink_s;
extern u32 fzgx_sink_u;
extern void fn_3_1AB34(void *obj, s16 start, s16 base, u32 *items);
extern u32 fn_3_17820();
extern void fn_3_1ADA4(void *, int, int, int, int);
extern void fn_3_1AE40(void *data, u32 x1, u32 y1, s16 x2, s16 y2);
extern void fn_3_1AEE4(void *data, u32 x1, u32 y1, u32 x2, u32 y2);
extern void fn_3_1B008(void *data, u32 x1, u32 y1, u32 x2, u32 y2);
extern u8 lbl_3_bss_A2458[8];
extern void fn_3_BD98(void);
extern u8 fn_3_1441C(void);
extern void fn_3_14008(void);
extern const QColor lbl_3_rodata_744[9];
extern void fn_3_152BC(u32, s32, s32, s32, s32, QColor);
extern void fn_3_14E18(void *arg0, u32 arg1, u32 arg2, s16 arg3, u32 arg4);
extern const f32 lbl_3_rodata_8F0;
extern const f32 lbl_3_rodata_990[297];
extern CustomizeRoot lbl_1_bss_38460;
extern u32 fn_1_870BC(u32,u32,Sig_fn_1_87610_Fn187610Data*,u32,u32,f32);
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void lbl_8006D7DC(void*);
extern void lbl_8006DFE8(void*);
extern void lbl_8006E14C(f32);
extern s32 fn_3_1EC2C(u32);
extern void fn_3_23724(u32 arg0, u32 arg1, u32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
extern u32 fn_3_21300(u32,u32,u32);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern u32 fn_1_151E20(u32 value, s16 index);
extern void fn_1_A9868();
extern void fn_1_AA188(s32, s32, s32, s32, void *, void *, void *, void *);
extern void fn_1_AA538(void);
extern void fn_1_4E0F4(void);
extern s32 lbl_3_bss_24370;
extern f64 lbl_3_rodata_800;
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern int sprintf(char *s, const char *format, ...);
extern struct fn_3_2BFB4_lbl_801A66B4 lbl_801A66B4;
extern u8 fn_1_B7C00(void);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_3_1ABD8(void *arg0, s16 x1, s16 y1, s16 x2, s16 y2, u32 *value);
extern void fn_3_1BA20(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 *arg5);
extern void fn_3_1BF08(void *data, s16 x1, s16 y1, s16 x2, s16 y2, u32 *color);
extern void fn_3_156A8(void);
extern void fn_3_1ACE4(void *data, s32 first_a, s32 second_a, s32 first_b, s32 second_b, u32 *values);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 24.0f;
    s = 86.0f;
    s = 100.0f;
    s = 385.0f;
    s = 170.0f;
    s = 104.0f;
    s = 40.0f;
    s = 96.0f;
    s = 90.0f;
    s = 0.5f;
    s = 20.0f;
    s = 60.0f;
    s = 80.0f;
    s = 15.0f;
    s = 30.0f;
    s = 320.0f;
    s = 372.0f;
    s = 0.10000000149011612f;
    s = 0.6000000238418579f;
    s = 375.0f;
    s = 0.75f;
    s = 248.0f;
    s = 1.0f;
    s = 0.800000011920929f;
    s = 240.0f;
    s = 25.0f;
    s = 1.0199999809265137f;
    s = 1.0099999904632568f;
    s = 0.4000000059604645f;
    s = 32768.0f;
    s = 10.0f;
    s = 81.0f;
    s = 399.0f;
    s = 18.0f;
    s = 12.0f;
    s = 0.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table2[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.0f;
    d = 0.5;
    s = 2.0f;
    s = -2.0f;
    s = -4.0f;
    s = 4.0f;
}
#pragma section code_type ".text"

static inline int abs(int x) {
    return __abs(x);
}

typedef struct { u32 value; } DrawColor;
static inline void draw(void *obj, s16 start, s16 base, DrawColor *items) {
    s32 half;
    s32 y;
    s16 width;
    s32 x;
    s16 i;
    u16 size;
    u32 item;

    size = lbl_3_bss_A2438.unk_C * 2 + 1;
    half = size >> 1;
    i = -half;
    x = base + i;
    y = start - half;
    width = size;
    while (i <= half) {
        item = items->value;
        fn_3_146C0(obj, y, x, width, &item);
        x++;
        i++;
    }
}

#pragma opt_propagation off
void fn_3_1BA20(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 *arg5) {
    s32 v7, v1, v4, v3, v5;
    s16 v10;
    f32 loc_28;
    f32 t0;
    s16 v24, v22;
    s32 v21, v20, v19, v18;
    s16 v27, v28, v36, v44;
    s32 v26, v35, v43, v51;
    u16 v25, v34, v42, v50;
    s16 v32, v39, v47, v55;
    s32 v31, v40, v48, v54;
    u32 v23, v33, v41, v49;
    DrawColor loc_14, loc_10, loc_C, loc_8;
    f32 v59, v62, v68;

    v1 = arg3 - arg1;
    v4 = arg4 - arg2;
    v10 = __abs(v1) > __abs(v4) ? __abs(v1) : __abs(v4);
    t0 = lbl_8006D118(&loc_28, 1.0f);
    v21 = (s32)((f32)v10 * t0);
    v19 = (s32)(2.0f + (1.0f + (f32)((f32)(-2.0f * loc_28) * (f32)v10)));
    v18 = (s32)(1.0f + (2.0f + (f32)((f32)(-4.0f * loc_28) * (f32)v10)));
    v20 = 0;
    while ((s16)v21 >= 0) {
        v22 = (s16)v20;
        v24 = (s16)v21;
        loc_14 = *(DrawColor *)arg5;
        draw(arg0, arg1 + v24, arg2 + v22, &loc_14);
        loc_10 = *(DrawColor *)arg5;
        draw(arg0, arg1 - v24, arg2 + v22, &loc_10);
        loc_C = *(DrawColor *)arg5;
        draw(arg0, arg1 + v24, arg2 - v22, &loc_C);
        loc_8 = *(DrawColor *)arg5;
        draw(arg0, arg1 - v24, arg2 - v22, &loc_8);
        if ((s16)v19 < 0) {
            v20++;
            v19 = (s32)((f32)(s16)v19 + (2.0f + (f32)(4.0f * (f32)(s16)v20)));
            v18 = (s32)((f32)(s16)v18 + (f32)(4.0f * (f32)(s16)v20));
        } else if ((s16)v18 >= 0) {
            v21--;
            v19 = (s32)((f32)(s16)v19 - (f32)(4.0f * (f32)(s16)v21));
            v18 = (s32)((f32)(s16)v18 - ((f32)(4.0f * (f32)(s16)v21) - 2.0f));
        } else {
            v20++;
            v21--;
            v19 = (s32)((f32)(s16)v19 + (2.0f + ((f32)(4.0f * (f32)(s16)v20) - (f32)(4.0f * (f32)(s16)v21))));
            v18 = (s32)((f32)(s16)v18 + (2.0f + ((f32)(4.0f * (f32)(s16)v20) - (f32)(4.0f * (f32)(s16)v21))));
        }
    }
}
/* fzgx:end fn_3_1BA20 */

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

/* fzgx:begin fn_3_1C278 */
#include "font.h"

/* Sprite packet as used here: the word at 0x50 carries the colour pointer. */
typedef struct {
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
    void *pixels;
    void *secondary;
    void *color_ptr;
    u32 unk_54;
} Fn3_1C278_Packet;

/* 16-byte records of lbl_3_bss_6D8C0, viewed from their field at +8. */
typedef struct {
    s16 name;
    u8 pad_2[14];
} Fn3_1C278_Entry;

typedef struct {
    u8 r, g, b, a;
} Fn3_1C278_Rgba;

extern Fn3_1C278_Packet lbl_1_rodata_26F8;
extern u32 fn_3_1C8D0(s16, void *, f32);
extern char *fn_3_2B750(s16, s16);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32);
extern void fn_1_4965C(u8);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_49738(void *);
extern void fn_1_495A0(f32);
extern char *fn_1_14FEAC(s16, s16, s16, char *, s16);
extern void fn_1_494DC(s16);
extern void fn_1_4962C(void);
extern void fn_1_49514(Fn3_1C278_Rgba *);
extern char *fn_1_14EE00(s16, char *, s16);
extern s16 fn_1_14EF40(s16, s16, s16);
extern void fn_1_14F6F8(s16, s16, s16, char *);
extern void fn_1_136714(f32, f32, f32, s32, s32, s32, s32, void *);
extern void fn_1_51914(Fn3_1C278_Packet *);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(Fn3_1C278_Packet *, u32, s16, s16);
extern void fn_1_51990(Fn3_1C278_Packet *);
extern u32 fn_1_13EF64(u32, u32, u32, char *, u32, Fn3_1C278_Rgba *, void *, f32);

#pragma section code_type ".fzgxpool"
/* Literals the TU pooled before this function (retail lbl_3_rodata_768 +0x0..+0x18). */
void fzgx_pool_fn_3_1C278(f32 *out) {
    *out = 0.7f;
}

void fzgx_pool_fn_3_1C278_colors(Fn3_1C278_Rgba *c) {
    Fn3_1C278_Rgba c1 = {0xFF, 0xFF, 0xFF, 0x00};
    Fn3_1C278_Rgba c2 = {0xFF, 0xFF, 0x00, 0x00};
    Fn3_1C278_Rgba c3 = {0xFF, 0x00, 0x00, 0x00};
    Fn3_1C278_Rgba c4 = {0x00, 0x00, 0xFF, 0x00};
    c[0] = c1;
    c[1] = c2;
    c[2] = c3;
    c[3] = c4;
}
#pragma section code_type ".text"

void fn_3_1C278(s16 id, s16 a, s16 b, s16 c, void *color, f32 alpha) {
    char text[0x40];
    Fn3_1C278_Packet packet;
    Fn3_1C278_Packet icon;
    char desc[0xB8];
    Fn3_1C278_Entry *table;
    s16 mode;
    s16 count;
    s32 col;
    s32 row;

    if (a == -1 || b == -1 || c == -1) {
        fn_3_1C8D0(id, color, alpha);
        return;
    }

    mode = lbl_3_bss_F0.unk_A;
    if (lbl_3_bss_F0.unk_A == 5) {
        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_4965C(2);
        fn_1_495C8(1);
        fn_1_4955C(0.45833334f, 0.45833334f);
        fn_1_496FC(284.0f, 329.0f);
        fn_1_4954C(100.0f);
        if (color != NULL) {
            fn_1_49738(color);
        }
        fn_1_495A0(alpha);
        fn_1_4AE0C((const char *)&lbl_3_data_4B70, fn_1_14FEAC(a, b, c, text, mode));
    }

    fn_1_49410();
    fn_1_495C8(9);
    fn_1_494DC(0x23);
    fn_1_4962C();
    fn_1_4955C(0.9166667f, 0.9166667f);
    fn_1_496FC(284.0f, 360.0f);
    fn_1_4954C(100.0f);
    if (color != NULL) {
        fn_1_49738(color);
    }
    fn_1_495A0(alpha);
    fn_1_4AE0C((const char *)&lbl_3_data_4B70, fn_1_14FEAC(a, b, c, text, 0));

    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_4954C(100.0f);
    fn_1_4955C(0.5416667f, 0.5416667f);
    {
        Fn3_1C278_Rgba color0 = {0xFF, 0xF2, 0x00, 0xFF};
        fn_1_49514(&color0);
    }
    if (color != NULL) {
        fn_1_49738(color);
    }
    fn_1_495A0(alpha);

    fn_1_496FC(441.0f, 332.0f);
    table = (Fn3_1C278_Entry *)((u8 *)&lbl_3_bss_6D8C0 + 8);
    fn_1_4AE0C((const char *)&lbl_3_data_4B70, fn_1_14EE00(table[a].name, text, mode));
    fn_1_496FC(441.0f, 345.0f);
    fn_1_4AE0C((const char *)&lbl_3_data_4B70, fn_1_14EE00(table[c].name, text, mode));
    fn_1_496FC(441.0f, 358.0f);
    fn_1_4AE0C((const char *)&lbl_3_data_4B70, fn_1_14EE00(table[b].name, text, mode));

    count = fn_1_14EF40(a, b, c);
    fn_1_14F6F8(a, b, c, desc);

    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_4954C(100.0f);
    fn_1_4955C(0.48749998f, 0.5416667f);
    if (color != NULL) {
        fn_1_49738(color);
    }
    fn_1_495A0(alpha);
    fn_1_496FC(395.0f, 331.0f);
    fn_1_4AE0C(fn_3_2B750(0x1A, 0));
    fn_1_496FC(395.0f, 345.0f);
    fn_1_4AE0C(fn_3_2B750(0x1D, 0));
    fn_1_496FC(395.0f, 359.0f);
    fn_1_4AE0C(fn_3_2B750(0x1B, 0));

    packet = lbl_1_rodata_26F8;
    packet.image = 0x8903;
    packet.x = 320.0f;
    packet.y = 362.0f;
    packet.z = 200.0f;
    packet.flags = 10;
    if (color != NULL) {
        packet.color_ptr = color;
        packet.flags |= 0x04000000;
    }
    packet.alpha = alpha;
    fn_1_4F734((FontDrawPacket *)&packet);

    fn_1_49410();
    fn_1_495FC();
    fn_1_495B0(0x80000000);
    fn_1_4965C(2);
    fn_1_496FC(323.0f, 381.0f);
    fn_1_4954C(100.0f);
    fn_1_4955C(0.5416667f, 0.5416667f);
    if (color != NULL) {
        fn_1_49738(color);
    }
    fn_1_495A0(alpha);
    fn_1_4AE0C((const char *)lbl_3_data_4B74, count);
    fn_1_136714(100.0f, 13.0f, alpha, count, 300, 381, 2, color);

    icon = lbl_1_rodata_26F8;
    icon.image = 0x890F;
    row = id / 6;
    col = id % 6;
    icon.x = 0.007843138f + (f32)col / 6.0f;
    icon.y = 0.007843138f + (f32)row / 7.0f;
    icon.scale_x *= 0.14901961f;
    icon.scale_y *= 0.12941177f;
    fn_1_51914(&icon);

    packet = lbl_1_rodata_26F8;
    packet.image = 0xA000;
    packet.flags = 10;
    fn_1_51564(0, 0, 0x78, 0x78, 6, 7);
    fn_1_5158C(&packet, packet.image, col, row);
    packet.x = 132.0f;
    packet.y = 362.0f;
    packet.z = 150.0f;
    packet.scale_x *= 0.8f;
    packet.scale_y *= 0.8f;
    fn_1_51990(&packet);
    if (color != NULL) {
        packet.color_ptr = color;
        packet.flags |= 0x04000000;
    }
    packet.alpha = alpha;
    fn_1_4F734((FontDrawPacket *)&packet);

    {
        Fn3_1C278_Rgba color1 = {0xFF, 0xFF, 0x00, 0x00};
        fn_1_13EF64(0x1FB, 0x16A, 100, desc, 0x8906, &color1, color, 0.3f * alpha);
    }
}
/* fzgx:end fn_3_1C278 */

/* fzgx:begin fn_3_1C8D0 */
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
    s = 0.0f;
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

/* Sprite packet as used here: the word at 0x50 carries the colour pointer. */
typedef struct {
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
    void *pixels;
    void *secondary;
    void *color_ptr;
    u32 unk_54;
} Fn3_1C278_Packet;

/* 16-byte records of lbl_3_bss_6D8C0, viewed from their field at +8. */
typedef struct {
    s16 name;
    u8 pad_2[14];
} Fn3_1C278_Entry;

typedef struct {
    u8 r, g, b, a;
} Fn3_1C278_Rgba;

extern Fn3_1C278_Packet lbl_1_rodata_26F8;
extern char *fn_3_2B750(s16, s16);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495B0(u32);
extern void fn_1_4965C(u8);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_49738(void *);
extern void fn_1_495A0(f32);
extern char *fn_1_14FEAC(s16, s16, s16, char *, s16);
extern void fn_1_494DC(s16);
extern void fn_1_4962C(void);
extern void fn_1_49514(Fn3_1C278_Rgba *);
extern char *fn_1_14EE00(s16, char *, s16);
extern s16 fn_1_14EF40(s16, s16, s16);
extern void fn_1_14F6F8(s16, s16, s16, char *);
extern void fn_1_136714(f32, f32, f32, s32, s32, s32, s32, void *);
extern void fn_1_51914(Fn3_1C278_Packet *);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(Fn3_1C278_Packet *, u32, s16, s16);
extern void fn_1_51990(Fn3_1C278_Packet *);
extern u32 fn_1_13EF64(u32, u32, u32, char *, u32, Fn3_1C278_Rgba *, void *, f32);

typedef struct {
    u8 pad_0[4];
    f32 unk_4;
    u8 pad_8[0xAC];
} Fn3_1C8D0_Entry;
extern Fn3_1C8D0_Entry lbl_1_data_28060[];
extern s32 lbl_1_data_416B8[][3];
extern char *fn_1_7F49C(s16, s16, char *);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_3_240A4(void);

#define SWAP_KIND(v) \
    switch (v) { \
    case 0: kind = 1; break; \
    case 1: kind = 1; break; \
    case 2: kind = 3; break; \
    case 3: kind = 5; break; \
    case 4: kind = 7; break; \
    case 5: kind = 9; break; \
    }

#define BAR(IMG, X, Y, Z, FLAGS) \
    packet = lbl_1_rodata_26F8; \
    packet.image = IMG; \
    packet.x = X; \
    packet.y = Y; \
    packet.z = Z; \
    packet.flags = FLAGS; \
    if (color != NULL) { \
        packet.color_ptr = color; \
        packet.flags |= 0x04000000; \
    } \
    packet.alpha = alpha; \
    fn_1_4F734((FontDrawPacket *)&packet);

void fn_3_1C8D0(s16 id, void *color, f32 alpha) {
    char desc[0xB4];
    Fn3_1C278_Packet packet;
    Fn3_1C278_Packet icon;
    char text[0x40];
    s16 mode;
    s16 level;
    s16 kind;
    s32 idx;
    s32 col;
    s32 row;

    mode = lbl_3_bss_F0.unk_A;
    if (id == -1) {
        if (lbl_3_bss_F0.unk_A == 5) {
            fn_1_49410();
            fn_1_495FC();
            fn_1_495B0(0x80000000);
            fn_1_4965C(2);
            fn_1_495C8(1);
            fn_1_4955C(0.45833334f, 0.45833334f);
            fn_1_496FC(320.0f, 380.0f);
            fn_1_4954C(100.0f);
            if (color != NULL) {
                fn_1_49738(color);
            }
            fn_1_495A0(alpha);
            fn_1_4AE0C(fn_3_2B750(0xF, mode));
        }
        BAR(0x891F, 320.0f, 362.0f, 200.0f, 0xF)
        BAR(0x891F, 320.0f, 362.0f, 200.0f, 0x8000D)
        BAR(0x891F, 320.0f, 362.0f, 200.0f, 0x100007)
        BAR(0x891F, 320.0f, 362.0f, 200.0f, 0x180005)
        BAR(0x890A, 320.0f, 334.0f, 100.0f, 6)
    } else {
        u32 images[41] = {
            0x4A00, 0x5400, 0x3800, 0x3E00, 0x3700, 0x5500, 0x3000, 0x3500,
            0x3A00, 0x4000, 0x4400, 0x5000, 0x3300, 0x2E00, 0x3100, 0x4F00,
            0x3900, 0x3D00, 0x4C00, 0x3F00, 0x4800, 0x5200, 0x4500, 0x5300,
            0x3C00, 0x5600, 0x4300, 0x4200, 0x3200, 0x2F00, 0x3400, 0x3600,
            0x4D00, 0x4600, 0x4100, 0x5100, 0x4E00, 0x4700, 0x3B00, 0x4B00,
            0x4900,
        };

        if (lbl_3_bss_F0.unk_A == 5) {
            fn_1_49410();
            fn_1_495FC();
            fn_1_495B0(0x80000000);
            fn_1_4965C(2);
            fn_1_495C8(1);
            fn_1_4955C(0.45833334f, 0.45833334f);
            fn_1_496FC(284.0f, 329.0f);
            fn_1_4954C(100.0f);
            if (color != NULL) {
                fn_1_49738(color);
            }
            fn_1_495A0(alpha);
            fn_1_4AE0C((const char *)&lbl_3_data_4B70, fn_1_7F49C(id, mode, text));
        }

        packet = lbl_1_rodata_26F8;
        idx = id;
        packet.image = images[idx];
        packet.x = 284.0f;
        packet.y = 360.0f;
        packet.z = 100.0f;
        packet.flags = 10;
        if (color != NULL) {
            packet.flags |= 0x04000000;
            packet.color_ptr = (void *)fn_3_240A4;
        }
        packet.alpha = alpha;
        fn_1_4F734((FontDrawPacket *)&packet);

        fn_80008BA8(desc, &lbl_1_data_28060[idx], 0xB4);
        level = lbl_1_data_28060[idx].unk_4;

        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_4965C(2);
        fn_1_4954C(100.0f);
        fn_1_4955C(0.5416667f, 0.5416667f);
        {
            Fn3_1C278_Rgba color0 = {0xFF, 0xF2, 0x00, 0xFF};
            fn_1_49514(&color0);
        }
        if (color != NULL) {
            fn_1_49738(color);
        }
        fn_1_495A0(alpha);

        SWAP_KIND(lbl_1_data_416B8[idx][0])
        fn_1_496FC(441.0f, 331.0f);
        fn_1_4AE0C((const char *)&lbl_3_data_4B70, fn_1_14EE00(kind, text, mode));
        SWAP_KIND(lbl_1_data_416B8[idx][1])
        fn_1_496FC(441.0f, 345.0f);
        fn_1_4AE0C((const char *)&lbl_3_data_4B70, fn_1_14EE00(kind, text, mode));
        SWAP_KIND(lbl_1_data_416B8[idx][2])
        fn_1_496FC(441.0f, 359.0f);
        fn_1_4AE0C((const char *)&lbl_3_data_4B70, fn_1_14EE00(kind, text, mode));

        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_4965C(2);
        fn_1_4954C(100.0f);
        fn_1_4955C(0.40625f, 0.5416667f);
        if (color != NULL) {
            fn_1_49738(color);
        }
        fn_1_495A0(alpha);
        fn_1_496FC(395.0f, 331.0f);
        fn_1_4AE0C(fn_3_2B750(0x1A, 0));
        fn_1_496FC(395.0f, 345.0f);
        fn_1_4AE0C(fn_3_2B750(0x1D, 0));
        fn_1_496FC(395.0f, 359.0f);
        fn_1_4AE0C(fn_3_2B750(0x1B, 0));

        BAR(0x8903, 320.0f, 362.0f, 200.0f, 10)

        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_4965C(2);
        fn_1_496FC(323.0f, 381.0f);
        fn_1_4954C(100.0f);
        fn_1_4955C(0.5416667f, 0.5416667f);
        if (color != NULL) {
            fn_1_49738(color);
        }
        fn_1_495A0(alpha);
        fn_1_4AE0C((const char *)lbl_3_data_4B74, level);
        fn_1_136714(100.0f, 13.0f, alpha, level, 300, 381, 2, color);

        icon = lbl_1_rodata_26F8;
        icon.image = 0x890F;
        col = id % 6;
        row = id / 6;
        icon.x = 0.007843138f + (f32)col / 6.0f;
        icon.y = 0.007843138f + (f32)row / 7.0f;
        icon.scale_x *= 0.14901961f;
        icon.scale_y *= 0.12941177f;
        fn_1_51914(&icon);

        packet = lbl_1_rodata_26F8;
        packet.image = 0xA000;
        packet.flags = 10;
        fn_1_51564(0, 0, 0x78, 0x78, 6, 7);
        fn_1_5158C(&packet, packet.image, col, row);
        packet.x = 132.0f;
        packet.y = 362.0f;
        packet.z = 150.0f;
        packet.scale_x *= 0.8f;
        packet.scale_y *= 0.8f;
        fn_1_51990(&packet);
        if (color != NULL) {
            packet.color_ptr = color;
            packet.flags |= 0x04000000;
        }
        packet.alpha = alpha;
        fn_1_4F734((FontDrawPacket *)&packet);

        {
            Fn3_1C278_Rgba color1 = {0xFF, 0xFF, 0x00, 0x00};
            fn_1_13EF64(0x1FB, 0x16A, 100, desc, 0x8906, &color1, color, 0.3f * alpha);
        }
    }
}
/* fzgx:end fn_3_1C8D0 */

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

/* fzgx:begin fn_3_1EFE4 noprologue */
#include "types.h"
#include "rel/customize/toolkit.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/shadowmap.h"
#include "psvec.h"

/* begin game/main_rel/shadowmap_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_SHADOWMAP_TYPES_H
#define GAME_MAIN_REL_SHADOWMAP_TYPES_H

// Types (and the externs that name them) of shadowmap.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct fn_1_568F8_Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_1_568F8_Color;

typedef struct fn_1_568F8_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} fn_1_568F8_Vec3;

typedef struct fn_1_568F8_Pool {
    fn_1_568F8_Color tev_color;  // 0x00
    f32 zero;                    // 0x04
    fn_1_568F8_Vec3 axis_x;      // 0x08
    fn_1_568F8_Vec3 axis_y;      // 0x14
    fn_1_568F8_Vec3 axis_z;      // 0x20
    fn_1_568F8_Vec3 up;          // 0x2c
    fn_1_568F8_Color clear_color;  // 0x38
    fn_1_568F8_Color chan_color;   // 0x3c
    f32 neg_three;               // 0x40
    f32 one;                     // 0x44
    f32 twenty;                  // 0x48
    f32 three;                   // 0x4c
    f32 hundred;                 // 0x50
    f32 size;                    // 0x54
} fn_1_568F8_Pool;

typedef struct fn_1_568F8_Data {
    u8 pad_0[0x38c];
    u8 light_mask;               // 0x38c
    u8 pad_38d[0x2b];
    s16 light_param;             // 0x3b8
} fn_1_568F8_Data;

typedef struct fn_1_568F8_Mtx44 {
    f32 m[4][4];
} fn_1_568F8_Mtx44;

extern fn_1_568F8_Pool lbl_1_rodata_28B0;
extern void fn_1_870BC(fn_1_568F8_Data *, s8, fn_1_568F8_Data *, s32, u8, f32);
extern void C_MTXOrtho(fn_1_568F8_Mtx44 *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(fn_1_568F8_Mtx44 *, s32);
extern void fn_800744F8(fn_1_568F8_Color, u32);
extern void fn_800725DC(fn_1_568F8_Color);
extern void fn_80072614(fn_1_568F8_Color);

#endif  // GAME_MAIN_REL_SHADOWMAP_TYPES_H

/* end game/main_rel/shadowmap_types.h */

typedef struct Sig_fn_8006F038_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_8006F038_Vec3;
typedef struct {
    u8 pad_00[0x1a];
    u16 count_b;
    u16 count_c;
} Sig_fn_1_55210_Fn55210Arg;
typedef struct {
    u8 pad_00[0x1a];
    u16 unk_1a;
    u16 unk_1c;
} Sig_fn_1_553C4_Fn1_553C4Input;

struct fn_3_1EFE4_lbl_3_rodata_768 {
    f32 unk_0;
    u8 pad_4[0x184];
    f32 unk_188;
    f32 unk_18C;
    u8 pad_190[0x28];
    f32 unk_1B8;
    u8 pad_1BC[0x14];
    f32 unk_1D0;
    u8 pad_1D4[0xC];
    f32 unk_1E0;
    u8 pad_1E4[0x14];
    f64 unk_1F8;
    u8 pad_200[0x24];
    f32 unk_224;
    f32 unk_228;
    u8 pad_22C[0x4];
    u32 unk_230;
    u32 unk_234;
    u32 unk_238;
    u32 unk_23C;
    u32 unk_240;
    u32 unk_244;
    f32 unk_248;
    f32 unk_24C;
    f32 unk_250;
};
struct fn_3_1EFE4_lbl_1_data_1E5C0 {
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
};
struct fn_3_1EFE4_lbl_801A66A0 {
    u32 unk_0;
};
struct fn_3_1EFE4_lbl_1_bss_38460 {
    u8 pad_0[0xC];
    u32 unk_C;
};
struct fn_3_1EFE4_lbl_801A6D00 {
    u32 unk_0;
};

extern f32 lbl_8006D188(u32);
extern s16 fn_1_F22E4(s32);
extern struct fn_3_1EFE4_lbl_1_bss_38460 lbl_1_bss_38460;
extern struct fn_3_1EFE4_lbl_1_data_1E5C0 lbl_1_data_1E5C0;
extern struct fn_3_1EFE4_lbl_3_rodata_768 lbl_3_rodata_768;
extern struct fn_3_1EFE4_lbl_801A66A0 lbl_801A66A0;
extern struct fn_3_1EFE4_lbl_801A6D00 lbl_801A6D00;
extern u32 fn_1_56018(s32);
extern u32 fn_1_7B558(u32, u32, u32, u32, u32, u32, f32);
extern u32 lbl_8006D784(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void fn_1_55210(Sig_fn_1_55210_Fn55210Arg *);
extern void fn_1_553C4(Sig_fn_1_553C4_Fn1_553C4Input *, void *);
extern void fn_1_560F0(s32, void *);
extern void fn_1_F7870(u32);
extern void fn_3_1F81C(void);
extern void fn_80008BA8(u32, u32, u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_8006F038(Sig_fn_8006F038_Vec3 *, Sig_fn_8006F038_Vec3 *, s16);
extern void fn_80072558(void);
extern void lbl_8006DCA4(void);
extern void lbl_8006DCDC(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E14C(f32);
extern void fn_1_870BC(fn_1_568F8_Data *, s8, fn_1_568F8_Data *, s32, u8, f32);

#pragma section code_type ".fzgxpool"
/* Volatile stores preserve the retail shared literal-pool order. */
void fzgx_pool_primer_0(volatile f32 *p, volatile f64 *d) {
    *p = 0.69999998807907104f;
}
#pragma section code_type ".text"
const u32 fzgx_pool_table_4[1] = {0xffffff00};
const u32 fzgx_pool_table_8[1] = {0xffff0000};
const u32 fzgx_pool_table_C[1] = {0xff000000};
const u32 fzgx_pool_table_10[1] = {0x0000ff00};
const u32 fzgx_pool_table_14[1] = {0xfff200ff};
const u32 fzgx_pool_table_18[1] = {0xffff0000};
#pragma section code_type ".fzgxpool"
/* Volatile stores preserve the retail shared literal-pool order. */
void fzgx_pool_primer_1(volatile f32 *p, volatile f64 *d) {
    *p = 0.45833334326744080f;
    *p = 284.00000000000000f;
    *p = 329.00000000000000f;
    *p = 100.00000000000000f;
    *p = 0.91666668653488159f;
    *p = 360.00000000000000f;
    *p = 0.54166668653488159f;
    *p = 441.00000000000000f;
    *p = 332.00000000000000f;
    *p = 345.00000000000000f;
    *p = 358.00000000000000f;
    *p = 0.48749998211860657f;
    *p = 395.00000000000000f;
    *p = 331.00000000000000f;
    *p = 359.00000000000000f;
    *p = 320.00000000000000f;
    *p = 362.00000000000000f;
    *p = 200.00000000000000f;
    *p = 323.00000000000000f;
    *p = 381.00000000000000f;
    *p = 13.000000000000000f;
    *p = 0.0078431377187371254f;
    *p = 6.0000000000000000f;
    *p = 7.0000000000000000f;
    *p = 0.14901961386203766f;
    *p = 0.12941177189350128f;
    *p = 132.00000000000000f;
    *p = 150.00000000000000f;
    *p = 0.80000001192092896f;
    *p = 0.30000001192092896f;
    *d = 4503601774854144.0;
}
#pragma section code_type ".text"
const u32 fzgx_pool_table_A0[41] = {0x00004a00, 0x00005400, 0x00003800, 0x00003e00, 0x00003700, 0x00005500, 0x00003000, 0x00003500, 0x00003a00, 0x00004000, 0x00004400, 0x00005000, 0x00003300, 0x00002e00, 0x00003100, 0x00004f00, 0x00003900, 0x00003d00, 0x00004c00, 0x00003f00, 0x00004800, 0x00005200, 0x00004500, 0x00005300, 0x00003c00, 0x00005600, 0x00004300, 0x00004200, 0x00003200, 0x00002f00, 0x00003400, 0x00003600, 0x00004d00, 0x00004600, 0x00004100, 0x00005100, 0x00004e00, 0x00004700, 0x00003b00, 0x00004b00, 0x00004900};
const u32 fzgx_pool_table_144[1] = {0xfff200ff};
const u32 fzgx_pool_table_148[1] = {0xffff0000};
#pragma section code_type ".fzgxpool"
/* Volatile stores preserve the retail shared literal-pool order. */
void fzgx_pool_primer_2(volatile f32 *p, volatile f64 *d) {
    *p = 380.00000000000000f;
    *p = 334.00000000000000f;
    *p = 0.40625000000000000f;
}
#pragma section code_type ".text"
const u32 fzgx_pool_table_158[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
#pragma section code_type ".fzgxpool"
/* Volatile stores preserve the retail shared literal-pool order. */
void fzgx_pool_primer_3(volatile f32 *p, volatile f64 *d) {
    *p = 480.00000000000000f;
    *p = 640.00000000000000f;
    *p = 62.000000000000000f;
    *p = 1.3411765098571777f;
    *p = 8.0000000000000000f;
    *p = 0.12500000000000000f;
    *p = 1.0000000000000000f;
    *p = 0.50000000000000000f;
    *p = 215.00000000000000f;
    *p = 3.0000000000000000f;
    *p = 180.00000000000000f;
    *p = 90.000000000000000f;
    *p = 240.00000000000000f;
    *p = 44.000000000000000f;
    *p = 89.900001525878906f;
    *p = 40.000000000000000f;
    *p = 16384.000000000000f;
    *p = 65536.000000000000f;
    *p = 60.000000000000000f;
    *p = 80.000000000000000f;
    *p = 460.00000000000000f;
    *p = 0.66666668653488159f;
    *p = 0.60784316062927246f;
    *p = -3.0000000000000000f;
    *p = 0.0000000000000000f;
    *p = 0.61960786581039429f;
    *p = 0.50588238239288330f;
    *p = 216.00000000000000f;
    *p = 0.20000000298023224f;
    *p = 140.00000000000000f;
    *p = 250.00000000000000f;
    *p = 400.00000000000000f;
    *p = 550.00000000000000f;
    *p = 0.46666666865348816f;
    *d = 4503599627370496.0;
}
#pragma section code_type ".text"
const f32 fzgx_pool_table_200[9] = {0.0f, 10.0f, -5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
#pragma section code_type ".fzgxpool"
/* Volatile stores preserve the retail shared literal-pool order. */
void fzgx_pool_primer_4(volatile f32 *p, volatile f64 *d) {
    *p = -0.50000000000000000f;
    *p = 182.04444885253906f;
    *p = 10.000000000000000f;
}
#pragma section code_type ".text"

s32 fn_3_1EFE4(void) {
    struct fn_3_1EFE4_lbl_3_rodata_768 *p_lbl_3_rodata_768;
    struct fn_3_1EFE4_lbl_1_data_1E5C0 *p_lbl_1_data_1E5C0;
    void *v0;
    u32 v1, v2, v3, v4;
    f32 v5, v6, v7;
    f32 v9, v10;
    f32 v17;
    u32 v18;
    s16 v23;
    u32 v24, v25, v26;
    f32 v27;
    u32 v28;
    f32 v30;
    u32 v31;
    f32 v32;
    u32 v33;
    f32 v34;
    u32 v35;
    f32 v37;
    u32 v38;
    f32 v40;
    u32 v41;
    f32 v43;
    u32 v44;
    s16 part;
    f32 t28;
    struct fn_3_1EFE4_lbl_1_data_1E5C0 loc_20;
    u32 loc_14[3];
    u32 loc_8[3];
    p_lbl_3_rodata_768 = &lbl_3_rodata_768;
    v0 = (void *)((u8 *)&lbl_3_bss_7E084 + (*(s16 *)((u8 *)&lbl_3_bss_20 + 0xc2) * 10));
    fn_80008BEC((void *)((u8 *)&lbl_3_bss_A2468 + 4), 0, 12);
    fn_80008BEC((void *)((u8 *)&lbl_3_bss_A2468 + 16), 0, 12);
    {
        Sig_fn_8006F038_Vec3 loc_14 = {0.0f, 10.0f, -5.0f};
        fn_80008BA8((u32)((u8 *)&lbl_3_bss_A2468 + 4), (u32)&loc_14, 12);
    }
    {
        Sig_fn_8006F038_Vec3 loc_8 = {0.0f, 0.0f, 0.0f};
        fn_80008BA8((u32)((u8 *)&lbl_3_bss_A2468 + 16), (u32)&loc_8, 12);
    }
    fn_8006F038((Sig_fn_8006F038_Vec3 *)((u8 *)&lbl_3_bss_A2468 + 4), (Sig_fn_8006F038_Vec3 *)((u8 *)&lbl_3_bss_A2468 + 16), 0);
    lbl_8006DCDC();
    v5 = 0.7f;
    p_lbl_1_data_1E5C0 = &lbl_1_data_1E5C0;
    v6 = p_lbl_1_data_1E5C0->unk_C * v5;
    v7 = p_lbl_1_data_1E5C0->unk_10 * v5;
    v9 = v6 - v7;
    v10 = v6 + v7;
    loc_20 = *p_lbl_1_data_1E5C0;
    loc_20.unk_C = v9;
    loc_20.unk_10 = v10;
    loc_20.unk_14 = p_lbl_1_data_1E5C0->unk_14;
    fn_1_F7870((u32)&loc_20);
    lbl_8006DCA4();
    v17 = 0.0f;
    lbl_8006E0B4(v17, -0.5f, v17);
    mathutil_mtxA_rotate_x(8192);
    v18 = lbl_801A66A0.unk_0;
    mathutil_mtxA_rotate_y((s32)(182.04444885253906f * (f32)(u32)(360 - (v18 % 360))));
    fn_3_1F81C();
    if (lbl_3_bss_7E23C > 0) {
        v23 = *(s16 *)((u8 *)v0 + 2);
        switch (v23) {
        case 0:
            v24 = *(u32 *)((u8 *)lbl_1_bss_38460.unk_C + 8);
            v25 = *(u32 *)((u8 *)v24 + 32);
            fn_1_56018(1);
            lbl_8006D784(lbl_801A6D00.unk_0 + 96);
            v26 = lbl_801A66A0.unk_0;
            v27 = 60.0f;
            *(f32 *)((u8 *)lbl_801A6D00.unk_0 + 108) = (v27 - (f32)(u32)(v26 % 120)) / v27;
            fn_1_560F0(0, (void *)(lbl_801A6D00.unk_0 + 96));
            fn_1_56018(1);
            lbl_8006D784(lbl_801A6D00.unk_0 + 96);
            v28 = lbl_801A66A0.unk_0;
            v30 = 3.75f;
            *(f32 *)((u8 *)lbl_801A6D00.unk_0 + 124) = (v30 - (f32)(u32)((v28 % 60) >> 3)) / 3.5f;
            fn_1_560F0(1, (void *)(lbl_801A6D00.unk_0 + 96));
            fn_1_56018(1);
            lbl_8006D784(lbl_801A6D00.unk_0 + 96);
            v31 = lbl_801A66A0.unk_0;
            v32 = 60.0f;
            *(f32 *)((u8 *)lbl_801A6D00.unk_0 + 108) = (v32 - (f32)(u32)(v31 % 120)) / v32;
            fn_1_560F0(2, (void *)(lbl_801A6D00.unk_0 + 96));
            fn_1_56018(1);
            lbl_8006D784(lbl_801A6D00.unk_0 + 96);
            v33 = lbl_801A66A0.unk_0;
            v34 = 60.0f;
            *(f32 *)((u8 *)lbl_801A6D00.unk_0 + 108) = -((v34 - (f32)(u32)(v33 % 120)) / v34);
            fn_1_560F0(3, (void *)(lbl_801A6D00.unk_0 + 96));
            lbl_8006DCA4();
            mathutil_mtxA_rotate_x(8192);
            v35 = lbl_801A66A0.unk_0;
            mathutil_mtxA_rotate_y((s32)(182.04444885253906f * (f32)(u32)(v35 % 360)));
            lbl_8006E14C(0.5f);
            v38 = lbl_801A66A0.unk_0 << 2;
            v40 = 182.04444885253906f;
            t28 = lbl_8006D188((s32)(v40 * (f32)(u32)(v38 % 360)));
            t28 = 0.2f * t28;
            lbl_8006E0B4(0.0f, t28, 0.0f);
            fn_80072558();
            fn_1_55210((Sig_fn_1_55210_Fn55210Arg *)v25);
            break;
        case 1:
            lbl_8006DCA4();
            mathutil_mtxA_rotate_x(8192);
            fn_1_7B558(1, 1, 210, 17, 208, 208, 1.0f);
            break;
        case 2:
            lbl_8006DCA4();
            mathutil_mtxA_rotate_x(8192);
            v41 = lbl_801A66A0.unk_0;
            v43 = 182.04444885253906f;
            mathutil_mtxA_rotate_y((s32)(v43 * (f32)(u32)(v41 % 360)));
            fn_80072558();
            part = fn_1_F22E4(*(s16 *)((u8 *)v0 + 8));
            v44 = lbl_3_bss_20854.unk_0 + part * 1088;
            if (part < 0 || part > 40)
                v44 = 0;
            if (v44 == 0)
                return 0;
            fn_1_870BC((fn_1_568F8_Data *)v44, 1, (fn_1_568F8_Data *)v44, 0, 4, 0.5f);
            break;
        case 3:
            lbl_8006DCA4();
            mathutil_mtxA_rotate_x(8192);
            mathutil_mtxA_rotate_y(32768);
            v38 = lbl_801A66A0.unk_0 << 2;
            t28 = lbl_8006D188((s32)(182.04444885253906f * (f32)(u32)(v38 % 360)));
            t28 = 0.05f * t28;
            lbl_8006E14C(1.0f + t28);
            lbl_8006E14C(0.5f);
            v38 = lbl_801A66A0.unk_0 << 2;
            t28 = lbl_8006D188((s32)(182.04444885253906f * (f32)(u32)(v38 % 360)));
            t28 = 0.2f * t28;
            lbl_8006E0B4(0.0f, t28, 0.0f);
            fn_80072558();
            fn_1_55210((Sig_fn_1_55210_Fn55210Arg *)*(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_38460.unk_C + 8) + 16));
            lbl_8006DCA4();
            mathutil_mtxA_rotate_x(8192);
            v38 = lbl_801A66A0.unk_0 * 3;
            mathutil_mtxA_rotate_y((s32)(182.04444885253906f * (f32)(u32)(v38 % 360)));
            lbl_8006E14C(0.5f);
            fn_80072558();
            fn_1_553C4((Sig_fn_1_553C4_Fn1_553C4Input *)*(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_38460.unk_C + 8) + 24), (void *)1);
            break;
        }
    }
    return 0;
}
/* fzgx:end fn_3_1EFE4 */

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

/* fzgx:begin fn_3_1F958 noprologue */
#include "types.h"
#include "rel/customize/toolkit.h"

typedef struct Sig_fn_8006F038_Vec3 { f32 x,y,z; } Sig_fn_8006F038_Vec3;
struct fn_3_1F958_lbl_3_rodata_768 {
 f32 unk_0; u8 pad_4[0x94]; f64 unk_98; u8 pad_A0[0xE8];
 f32 unk_188; u8 pad_18C[0x44]; f32 unk_1D0; u8 pad_1D4[0x24];
 f64 unk_1F8; u8 pad_200[0x24]; f32 unk_224,unk_228,unk_22C;
 u8 pad_230[0x24]; u32 unk_254,unk_258,unk_25C,unk_260,unk_264,unk_268;
 f32 unk_26C;
};
struct fn_3_1F958_lbl_1_data_1E5C0 {
 u32 unk_0,unk_4,unk_8; f32 unk_C,unk_10,unk_14;
 u32 unk_18,unk_1C,unk_20,unk_24,unk_28,unk_2C,unk_30;
};
struct fn_3_1F958_lbl_801A66A0 {u32 unk_0;};
struct fn_3_1F958_lbl_1_bss_38460 {u8 pad_0[12]; u32 unk_C;};
extern struct fn_3_1F958_lbl_1_bss_38460 lbl_1_bss_38460;
extern struct fn_3_1F958_lbl_1_data_1E5C0 lbl_1_data_1E5C0;
extern struct fn_3_1F958_lbl_3_rodata_768 lbl_3_rodata_768;
extern struct fn_3_1F958_lbl_801A66A0 lbl_801A66A0;
extern u32 lbl_801A6D00;
extern u32 lbl_3_bss_7EC04;

extern u8 lbl_1_bss_9F8[];
extern void fn_80008BEC(void *,int,u32);
extern void fn_80008BA8(void *,void *,u32);
extern void fn_8006F038(Sig_fn_8006F038_Vec3 *,Sig_fn_8006F038_Vec3 *,s16);
extern void lbl_8006DCDC(void);
extern void fn_1_F7870(void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0B4(f32,f32,f32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 fn_1_56018(s32);
extern u32 lbl_8006D784(u32);
extern f32 lbl_8006D188(s16);
extern void fn_1_560F0(s32,void *);
extern void fn_80072558(void);
extern void fn_1_55210(void *);
extern void lbl_8006DB74(void *);
extern void fn_1_151BDC(void *);
extern void fn_1_14DEA4(void *,void **,void **,s16,f32);
extern void lbl_8006DAEC(void);
extern void fn_1_14E078(void *,void *,s16,f32);
extern void lbl_8006DB30(void);
extern void fn_1_14E1BC(void *,void *,s16,f32);
extern void lbl_8006DBAC(void *);
extern void fn_1_FCFA4(void *);
static inline f32 uint_float(u32 x, f64 bias) {
 union { f64 d; struct { u32 hi,lo; } w; } v;
 v.w.hi=0x43300000;
 v.w.lo=x;
 return (f32)(v.d-bias);
}
#pragma force_active on
/* Preserve the shared retail literal-pool order; volatile keeps these primer reads. */
#pragma section code_type ".fzgxpool"
#pragma section code_type ".text"
__declspec(section ".fzgxpool") static void fzgx_pool_primer_0(void) {
 volatile f32 p = 0.7f; /* Volatile retains this shared literal-pool initializer and its layout. */
}
__declspec(section ".fzgxpool") static void fzgx_pool_primer_4(void) {
 volatile u32 p[37] = {0xFFFFFF00,0xFFFF0000,0xFF000000,0x0000FF00,0xFFF200FF,0xFFFF0000,0x3EEAAAAB,0x438E0000,0x43A48000,0x42C80000,0x3F6AAAAB,0x43B40000,0x3F0AAAAB,0x43DC8000,0x43A60000,0x43AC8000,0x43B30000,0x3EF99999,0x43C58000,0x43A58000,0x43B38000,0x43A00000,0x43B50000,0x43480000,0x43A18000,0x43BE8000,0x41500000,0x3C008081,0x40C00000,0x40E00000,0x3E189899,0x3E048485,0x43040000,0x43160000,0x3F4CCCCD,0x3E99999A,0x00000000}; /* Volatile retains this shared literal-pool initializer and its layout. */
}
__declspec(section ".fzgxpool") static void fzgx_pool_primer_98(void) {
 volatile f64 p = 4503601774854144.0; /* Volatile retains this shared literal-pool initializer and its layout. */
}
__declspec(section ".fzgxpool") static void fzgx_pool_primer_a0(void) {
 volatile u32 p[58] = {0x00004A00,0x00005400,0x00003800,0x00003E00,0x00003700,0x00005500,0x00003000,0x00003500,0x00003A00,0x00004000,0x00004400,0x00005000,0x00003300,0x00002E00,0x00003100,0x00004F00,0x00003900,0x00003D00,0x00004C00,0x00003F00,0x00004800,0x00005200,0x00004500,0x00005300,0x00003C00,0x00005600,0x00004300,0x00004200,0x00003200,0x00002F00,0x00003400,0x00003600,0x00004D00,0x00004600,0x00004100,0x00005100,0x00004E00,0x00004700,0x00003B00,0x00004B00,0x00004900,0xFFF200FF,0xFFFF0000,0x43BE0000,0x43A70000,0x3ED00000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x43F00000,0x44200000,0x42780000,0x3FABABAC,0x41000000,0x3E000000}; /* Volatile retains this shared literal-pool initializer and its layout. */
}
__declspec(section ".fzgxpool") static void fzgx_pool_primer_188(void) {
 volatile f32 p = 1.0f; /* Volatile retains this shared literal-pool initializer and its layout. */
}
__declspec(section ".fzgxpool") static void fzgx_pool_primer_18c(void) {
 volatile f32 p[17] = {0.5f,215.0f,3.0f,180.0f,90.0f,240.0f,44.0f,89.9000015258789f,40.0f,16384.0f,65536.0f,60.0f,80.0f,460.0f,0.6666666865348816f,0.6078431606292725f,-3.0f}; /* Volatile retains this shared literal-pool initializer and its layout. */
}
__declspec(section ".fzgxpool") static void fzgx_pool_primer_1d0(void) {
 volatile f32 p = 0.0f; /* Volatile retains this shared literal-pool initializer and its layout. */
}
__declspec(section ".fzgxpool") static void fzgx_pool_primer_1d4(void) {
 volatile u32 p[9] = {0x3F1E9E9F,0x3F018182,0x43580000,0x3E4CCCCD,0x430C0000,0x437A0000,0x43C80000,0x44098000,0x3EEEEEEF}; /* Volatile retains this shared literal-pool initializer and its layout. */
}
__declspec(section ".fzgxpool") static void fzgx_pool_primer_1f8(void) {
 volatile f64 p = 4503599627370496.0; /* Volatile retains this shared literal-pool initializer and its layout. */
}
__declspec(section ".fzgxpool") static void fzgx_pool_primer_200(void) {
 volatile f32 p[9] = {0.0f,10.0f,-5.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f}; /* Volatile retains this shared literal-pool initializer and its layout. */
}
__declspec(section ".fzgxpool") static void fzgx_pool_primer_224(void) {
 volatile f32 p = -0.5f; /* Volatile retains this shared literal-pool initializer and its layout. */
}
__declspec(section ".fzgxpool") static void fzgx_pool_primer_228(void) {
 volatile f32 p = 182.04444885253906f; /* Volatile retains this shared literal-pool initializer and its layout. */
}
__declspec(section ".fzgxpool") static void fzgx_pool_primer_22c(void) {
 volatile f32 p = 10.0f; /* Volatile retains this shared literal-pool initializer and its layout. */
}
__declspec(section ".fzgxpool") static void fzgx_pool_primer_230(void) {
 volatile f32 p[9] = {0.0f,10.0f,-5.0f,0.0f,0.0f,0.0f,3.75f,3.5f,0.05000000074505806f}; /* Volatile retains this shared literal-pool initializer and its layout. */
}
#pragma force_active reset
int fn_3_1F958(void) {
 u8 *v25;
 u32 v23;
 s32 v27;
 Obj_3_bss_20 *state;
 struct fn_3_1F958_lbl_3_rodata_768 *p_lbl_3_rodata_768;
 s16 v1;
 s32 special;
 u8 *key0;
 u8 *key1;
 u8 *key2;
 u8 *entry;
 struct fn_3_1F958_lbl_1_data_1E5C0 *p_lbl_1_data_1E5C0;
 s32 i;
 s16 v0;
 s32 enabled;
 s32 flag;
 u32 v2;
 u32 v3;
 u32 v4;
 u32 v5;
 f32 v6;
 f32 v7;
 f32 v8;
 f32 v10;
 f32 v11;
 u32 v12,v13,v14,v15,v16,v17;
 f32 v18;
 u32 v19;
 f32 amount,alpha;
 f32 matrix[12];
 struct fn_3_1F958_lbl_1_data_1E5C0 loc_28;
 void *part1,*part2;
 v0=lbl_3_bss_F0.unk_8;
 v1=lbl_3_bss_F0.unk_6;
 fn_80008BEC((u8 *)&lbl_3_bss_A2468+4,0,12);
 fn_80008BEC((u8 *)&lbl_3_bss_A2468+16,0,12);
 {
  f32 loc_1C[3]={0.0f,10.0f,-5.0f};
  fn_80008BA8((u8 *)&lbl_3_bss_A2468+4,loc_1C,12);
  {
   f32 loc_10[3]={0.0f,0.0f,0.0f};
   fn_80008BA8((u8 *)&lbl_3_bss_A2468+16,loc_10,12);
  }
 }
 fn_8006F038((Sig_fn_8006F038_Vec3 *)((u8 *)&lbl_3_bss_A2468+4),(Sig_fn_8006F038_Vec3 *)((u8 *)&lbl_3_bss_A2468+16),0);
 lbl_8006DCDC();
 v6=0.7f;
 p_lbl_1_data_1E5C0=(struct fn_3_1F958_lbl_1_data_1E5C0 *)&lbl_1_data_1E5C0;
 v7=p_lbl_1_data_1E5C0->unk_C*v6;
 v8=p_lbl_1_data_1E5C0->unk_10*v6;
 v10=v7-v8;v11=v7+v8;
 loc_28=*p_lbl_1_data_1E5C0;
 loc_28.unk_C=v10;loc_28.unk_10=v11;loc_28.unk_14=p_lbl_1_data_1E5C0->unk_14;
 fn_1_F7870(&loc_28);
 lbl_8006DCA4();
 v18=0.0f;
 lbl_8006E0B4(v18,-0.5f,v18);
 mathutil_mtxA_rotate_x(8192);
 v19=lbl_801A66A0.unk_0;
 mathutil_mtxA_rotate_y((s32)(182.04444885253906f*(f32)(360-v19%360)));
 v23=*(u32 *)(*(u32 *)(lbl_1_bss_38460.unk_C+8));
 v25=(u8 *)(v23+64);
 v27=0;
 while((s16)v27<*(u16 *)(v23+24)) {
  if((*(u32 *)v25&0x20000)!=0) {
   fn_1_56018(1);
   lbl_8006D784(lbl_801A6D00+96);
   v18=lbl_8006D188((s16)((s32)(182.04444885253906f*(f32)(lbl_801A66A0.unk_0%180))+0x4000));
   *(f32 *)(lbl_801A6D00+108)=1.0f-v18;
   fn_1_560F0(0,(void *)(lbl_801A6D00+96));
  }
  v27++;v25+=32;
 }
 fn_80072558();
 fn_1_55210((void *)v23);
 lbl_8006DCA4();
 mathutil_mtxA_rotate_x(8192);
 mathutil_mtxA_rotate_y((s32)(182.04444885253906f*(f32)(lbl_801A66A0.unk_0%360)));
 lbl_8006DB74(matrix);
 state=(Obj_3_bss_20 *)&lbl_3_bss_20;
 entry=(u8 *)&lbl_3_bss_140+v0*0x81C0;
 key0=entry+0x81A4;key1=entry+0x81AC;key2=entry+0x81B4;
 for(i=0;(s16)i<25;i++) {
  if(state->unk_1A==(s16)i) {
   enabled=0;
   amount=(f32)lbl_3_bss_18/10.0f;
   flag=0;
   if(((*(u16 *)(lbl_1_bss_9F8+v1*20)>>10)&1)!=0 && (s32)lbl_3_bss_7EC04==0) flag=1;
   special=flag!=0;
   part1=0;part2=0;
   if((*(u32 *)entry&(3U << 30))!=0) enabled=1;
   fn_1_151BDC(0);
   if(enabled==1 && lbl_3_bss_20.unk_0==*key0) fn_1_151BDC(entry);
   if(state->unk_18==0) alpha=amount;
   else if(special) alpha=1.0f;
   else alpha=0.25f;
   fn_1_14DEA4(lbl_3_bss_6DE20+state->unk_1A*0xA20,&part1,&part2,(s16)lbl_3_bss_20848,alpha);
   lbl_8006DAEC();
   fn_1_151BDC(0);
   if(enabled==1 && state->unk_8==*key1) fn_1_151BDC(entry);
   if(state->unk_18==1) alpha=amount;
   else if(special) alpha=1.0f;
   else alpha=0.25f;
   fn_1_14E078(lbl_3_bss_6DE20+state->unk_1C*0xA20,part1,(s16)lbl_3_bss_20848,alpha);
   lbl_8006DB30();
   fn_1_151BDC(0);
   if(enabled==1 && state->unk_10==*key2) fn_1_151BDC(entry);
   if(state->unk_18==2) alpha=amount;
   else if(special) alpha=1.0f;
   else alpha=0.25f;
   fn_1_14E1BC(lbl_3_bss_6DE20+state->unk_1E*0xA20,part2,(s16)lbl_3_bss_20848,alpha);
  }
 }
 if(state->unk_18<3) {
  lbl_8006DBAC(matrix);fn_80072558();
  fn_1_FCFA4((u8 *)&lbl_3_bss_2C7C0+v0*0x10440);
 }
 return 0;
}
/* fzgx:end fn_3_1F958 */

/* fzgx:begin fn_3_1FF7C */
/* begin game/vec3.h (deltawave784/fzgx, CC0) */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,
// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,
// stcoli). Hand-owned (librarian).


typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

#endif  // GAME_VEC3_H

/* end game/vec3.h */

/* Primer: reproduces the TU literal pool (lbl_3_rodata_768) up to 0x270, where this
   function's own aggregate initializers start. */
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
#pragma section code_type ".text"

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    Vec3 pos;
    u32 unk_18[7];
} Fn3_1FF7C_Camera;

typedef struct {
    u32 flags;
    u8 pad_4[0x1C];
} Fn3_1FF7C_Entry;

typedef struct {
    u8 pad_0[0x18];
    u16 count;
    u8 pad_1A[0x26];
    Fn3_1FF7C_Entry entries[1];
} Fn3_1FF7C_Model;

typedef struct {
    u8 pad_0[0x60];
    Vec3 pos;
    f32 unk_6C;
} Fn3_1FF7C_Mtx;

extern Fn3_1FF7C_Camera lbl_1_data_1E5C0;
extern u32 lbl_801A66A0;
extern Fn3_1FF7C_Mtx *lbl_801A6D00;
extern struct { u8 pad_0[0xC]; u8 *unk_C; } lbl_1_bss_38460;

extern void fn_80008BEC(void *, int, u32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_8006F038(Vec3 *, Vec3 *, s16);
extern void lbl_8006DCDC(void);
extern void fn_1_F7870(Fn3_1FF7C_Camera *);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void fn_1_56018(s32);
extern void lbl_8006D784(Vec3 *);
extern f32 lbl_8006D188(s16);
extern void fn_1_560F0(s32, Vec3 *);
extern void fn_80072558(void);
extern void fn_1_55210(Fn3_1FF7C_Model *);
extern void lbl_8006DB74(Vec3 *);
extern void fn_1_151BDC(void *);
extern void fn_1_14E2DC(void *, s16, f32);
extern void lbl_8006DBAC(Vec3 *);
extern void fn_1_FCFA4(void *);

s32 fn_3_1FF7C(void) {
    Obj_3_bss_F0 *state = &lbl_3_bss_F0;
    Fn3_1FF7C_Camera cam;
    Fn3_1FF7C_Camera *src;
    f32 k;
    f32 x;
    f32 y;
    Fn3_1FF7C_Entry *entries;
    Fn3_1FF7C_Model *model;
    s16 i;
    s16 idx;

    idx = state->unk_8;

    fn_80008BEC(&lbl_3_bss_A2468.pad_0[4], 0, 12);
    fn_80008BEC(&lbl_3_bss_A2468.pad_0[0x10], 0, 12);
    {
        Vec3 a = {0.0f, 10.0f, -5.0f};
        fn_80008BA8(&lbl_3_bss_A2468.pad_0[4], &a, 12);
    }
    {
        Vec3 b = {0.0f, 0.0f, 0.0f};
        fn_80008BA8(&lbl_3_bss_A2468.pad_0[0x10], &b, 12);
    }
    fn_8006F038((Vec3 *)&lbl_3_bss_A2468.pad_0[4], (Vec3 *)&lbl_3_bss_A2468.pad_0[0x10], 0);

    lbl_8006DCDC();
    src = &lbl_1_data_1E5C0;
    k = 0.7f;
    x = src->pos.x * k;
    y = src->pos.y * k;
    cam = *src;
    cam.pos.x = x - y;
    cam.pos.y = x + y;
    cam.pos.z = src->pos.z;
    fn_1_F7870(&cam);

    lbl_8006DCA4();
    lbl_8006E0B4(0.0f, -0.5f, 0.0f);
    mathutil_mtxA_rotate_x(0x2000);
    mathutil_mtxA_rotate_y(182.04444885253906f * (f32)(360 - lbl_801A66A0 % 360));

    model = *(Fn3_1FF7C_Model **)(*(u8 **)(lbl_1_bss_38460.unk_C + 8));
    entries = model->entries;
    for (i = 0; i < model->count; i++, entries++) {
        if (entries->flags & 0x20000) {
            fn_1_56018(1);
            lbl_8006D784(&lbl_801A6D00->pos);
            lbl_801A6D00->unk_6C = 1.0f -
                lbl_8006D188((s32)(182.04444885253906f * (f32)(lbl_801A66A0 % 180)) + 0x4000);
            fn_1_560F0(0, &lbl_801A6D00->pos);
        }
    }
    fn_80072558();
    fn_1_55210(model);

    lbl_8006DCA4();
    mathutil_mtxA_rotate_x(0x2000);
    mathutil_mtxA_rotate_y(182.04444885253906f * (f32)(lbl_801A66A0 % 360));
    lbl_8006DB74(&lbl_801A6D00->pos);
    fn_1_151BDC((u8 *)&lbl_3_bss_140 + idx * 0x81C0);
    fn_1_14E2DC(lbl_3_bss_21960 + idx * 0xA20, lbl_3_bss_20848, 1.0f);
    lbl_8006DBAC(&lbl_801A6D00->pos);
    fn_80072558();
    fn_1_FCFA4((u8 *)&lbl_3_bss_2C7C0 + state->unk_8 * 0x10440);
    return 0;
}
/* fzgx:end fn_3_1FF7C */

/* fzgx:begin fn_3_20374 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/toolkit.h"
#include "font.h"
#include "types.h"

/* begin game/vec3.h (deltawave784/fzgx, CC0) */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,
// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,
// stcoli). Hand-owned (librarian).


typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

#endif  // GAME_VEC3_H

/* end game/vec3.h */





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

typedef struct CustomizeData {
    u32 unk_00[2];
    u32 unk_08;
    u8 pad_0c[0x14];
    void *unk_20;
} CustomizeData;

struct fn_3_1A1D8_lbl_1_bss_9F8_0_E20 {
    u8 pad_0[0x10];
    u16 unk_10;
    u8 pad_12[0x2];
};

struct fn_3_1A1D8_lbl_1_bss_9F8 {
    struct fn_3_1A1D8_lbl_1_bss_9F8_0_E20 unk_0[1];
};

struct fn_3_1A264_lbl_1_bss_9F8_10_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};

struct fn_3_1A264_lbl_1_bss_9F8 {
    u8 pad_0[0x10];
    struct fn_3_1A264_lbl_1_bss_9F8_10_E20 unk_10[1];
};

typedef struct {
    u8 r, g, b, a;
} QColor;

typedef struct { u32 id; f32 x,y,z; u32 rest[18]; } Packet23524;

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

struct fn_3_23724_Copy88 {
    u32 flags;
    f32 x, y, z;
    u32 pad[8];
    u32 mode;
    u32 tail[9];
};

typedef struct {
    u32 flags;
    u8 pad[0x1c];
} fn_3_1F81C_CustomizeEntry;

typedef struct CustomizeObject CustomizeObject;

struct CustomizeObject {
    u8 pad0[0x18];
    u16 count;
    u8 pad1[0x26];
    fn_3_1F81C_CustomizeEntry entries[1];
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

struct fn_3_20374_lbl_1_data_1E5C0 {
u32 unk_0,unk_4,unk_8; f32 unk_C,unk_10,unk_14; u32 unk_18,unk_1C,unk_20,unk_24,unk_28,unk_2C,unk_30;
};

struct fn_3_23724_lbl_3_rodata_768 {
    u8 pad_0[0x78];
    f32 seven;
    u8 pad_7C[0x10C];
    f32 one;
    f32 half;
    u8 pad_190[0x40];
    f32 zero;
    u8 pad_1D4[0x180];
    f32 twentythree;
    u8 pad_358[0xC];
    f32 twelve;
    u8 pad_368[0x40];
    f32 unk_3A8;
    f32 unk_3AC;
    f32 five;
};

struct fn_3_2BFB4_lbl_3_rodata_768 {
    u8 pad_0[0x22C];
    f32 unk_22C;
    u8 pad_230[0x1E8];
    f32 unk_418;
    u8 pad_41C[0x25C];
    f32 unk_678;
};

struct fn_3_2C164_lbl_3_rodata_768 {
    u8 pad_0[0x22C];
    f32 unk_22C;
    u8 pad_230[0x1E8];
    f32 unk_418;
    u8 pad_41C[0x25C];
    f32 unk_678;
};

struct fn_3_20374_lbl_3_rodata_768 {
f32 unk_0; u8 pad_4[0x94]; f64 unk_98; u8 pad_A0[0xE8]; f32 unk_188;
u8 pad_18C[0x6C]; f64 unk_1F8; u8 pad_200[0x28]; f32 unk_228;
u8 pad_22C[0x5C]; f32 unk_288,unk_28C,unk_290,unk_294,unk_298,unk_29C,unk_2A0,unk_2A4,unk_2A8;
};

typedef struct Sig_fn_1_87610_Fn187610Data {
u8 pad_000[2]; s8 field_002; u8 pad_003[0x205]; u8 field_208[0x120];
} Sig_fn_1_87610_Fn187610Data;

typedef struct Sig_fn_8006F038_Vec3 { f32 x,y,z; } Sig_fn_8006F038_Vec3;

struct fn_3_2B268_lbl_1_bss_7F0C0 {
    u8 pad_0[0x48F8];
    u32 unk_48F8;
};

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

typedef s32 (*Sig_fn_1_8D210_fn_1_8D210_callback)(u32);

struct fn_3_2BFB4_lbl_801A66B4 {
    u32 unk_0;
};

typedef struct Rgba {
    u8 r, g, b, a;
} Rgba;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    Vec3 pos;
    u32 unk_18[7];
} Fn3_1FF7C_Camera;

typedef struct {
    u8 pad_0[0x60];
    Vec3 pos;
    f32 unk_6C;
} Fn3_1FF7C_Mtx;

typedef struct {
    u32 flags;
    u8 pad_4[0x1C];
} Fn3_1FF7C_Entry;

typedef struct {
    u8 pad_0[0x18];
    u16 count;
    u8 pad_1A[0x26];
    Fn3_1FF7C_Entry entries[1];
} Fn3_1FF7C_Model;


typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} fn_3_1A648_Pad;

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
extern const f32 lbl_3_rodata_740;
extern void fn_3_1B130(void *data, s16 x, s16 y, Rgba color);
extern void fn_3_BE10(void);
extern void fn_3_BEF0(void);
extern void fn_3_1445C(void);
extern void fn_3_BE88(void);
extern void fn_80008BA8(u32 *, void *, s32);
extern s32 fn_8008023C(u32 arg0, u32 arg1, u32 arg2);
extern struct fn_3_1A1D8_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern u32 fn_3_141A8(u32);
extern u8 fn_3_1443C(void);
extern u32 fn_3_14064(void);
extern u32 fn_3_1401C(void);
extern u32 fn_3_1402C(u8 index);
extern void fn_1_A2D84(u32 arg0);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_3_1B4BC(void *, s16, s16, s16, s16, u32 *);
extern void fn_3_149AC();
extern void fn_3_14794(void *, u32, u32, u32 *);
extern void fn_3_146C0(void *arg0, s16 x, s16 y, s16 delta, u32 *arg4);
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A66A8;
extern u16 fn_1_A5DB0(void);
extern s32 fn_1_A5DC4(void);
extern f32 lbl_8006D188(s32);
extern void fn_1_50164();
extern void fn_1_49410(void);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49590(f32 value);
extern void fn_1_495A0(f32 value);
extern void fn_1_495C8(u8 value);
extern void fn_1_4966C(f32 value1, f32 value2);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_49738(u32 value);
extern u32 fn_3_2B750(s16, s16);
extern void fn_3_2406C(void);
extern void fn_3_240DC(void *, void *);
extern void fn_1_5233C(void *arg0, void *arg1);
extern struct fn_3_20374_lbl_1_data_1E5C0 lbl_1_data_1E5C0;
extern u32 lbl_801A66A0;
extern CustomizeObject *lbl_801A6D00;
extern void fn_8006F038(Vec3 *arg0, Vec3 *arg1, s16 arg2);
extern void lbl_8006DCDC(void);
extern void fn_1_F7870(u32 value);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern u32 fn_1_56018(s32 value);
extern void lbl_8006D784(void *);
extern void fn_1_560F0(s32 index, void *arg);
extern void fn_80072558(void);
extern void fn_1_55210(CustomizeObject *);
extern void lbl_8006DB74(void*);
extern void fn_1_151BDC(u32 value);
extern void fn_1_14E2DC(void *, s16, f32);
extern void lbl_8006DBAC(Vec3 *);
extern void fn_1_FCFA4(void *);
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
extern f32 fn_1_A6FE8(void);
extern u8 lbl_1_bss_7F0C0[];
extern u32 fn_3_1EFE4(void);
extern u32 lbl_801A66C0[1];
extern void fn_3_2A2F8(s16, s16, s16, s16, s32);
extern void fn_3_7A08(s16 *arg0, s16 *arg1, int arg2);
extern u32 fn_3_225F8(u32, u32, u32);
extern void fn_1_54278(u32 arg0, u32 arg1);
extern void fn_1_5428C(f32 value);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern void fn_1_495FC(void);
extern u32 fn_3_2B778(s16, u32, u32, u32, u32);
extern f32 lbl_8006D118(f32 *, f32);
extern void fzgx_usef(f32);
extern void fzgx_used(f64);
extern void fzgx_usep(void *);
extern s32 fzgx_sink_s;
extern u32 fzgx_sink_u;
extern void fn_3_1AB34(void *obj, s16 start, s16 base, u32 *items);
extern u32 fn_3_17820();
extern void fn_3_1ADA4(void *, int, int, int, int);
extern void fn_3_1AE40(void *data, u32 x1, u32 y1, s16 x2, s16 y2);
extern void fn_3_1AEE4(void *data, u32 x1, u32 y1, u32 x2, u32 y2);
extern void fn_3_1B008(void *data, u32 x1, u32 y1, u32 x2, u32 y2);
extern u8 lbl_3_bss_A2458[8];
extern void fn_3_BD98(void);
extern u8 fn_3_1441C(void);
extern void fn_3_14008(void);
extern const QColor lbl_3_rodata_744[9];
extern void fn_3_152BC(u32, s32, s32, s32, s32, QColor);
extern void fn_3_14E18(void *arg0, u32 arg1, u32 arg2, s16 arg3, u32 arg4);
extern const f32 lbl_3_rodata_8F0;
extern const f32 lbl_3_rodata_990[297];
extern CustomizeRoot lbl_1_bss_38460;
extern u32 fn_1_870BC(u32,u32,Sig_fn_1_87610_Fn187610Data*,u32,u32,f32);
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void lbl_8006D7DC(void*);
extern void lbl_8006DFE8(void*);
extern void lbl_8006E14C(f32);
extern s32 fn_3_1EC2C(u32);
extern void fn_3_23724(u32 arg0, u32 arg1, u32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
extern u32 fn_3_21300(u32,u32,u32);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern u32 fn_1_151E20(u32 value, s16 index);
extern void fn_1_A9868();
extern void fn_1_AA188(s32, s32, s32, s32, void *, void *, void *, void *);
extern void fn_1_AA538(void);
extern void fn_1_4E0F4(void);
extern s32 lbl_3_bss_24370;
extern f64 lbl_3_rodata_800;
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern int sprintf(char *s, const char *format, ...);
extern struct fn_3_2BFB4_lbl_801A66B4 lbl_801A66B4;
extern u8 fn_1_B7C00(void);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_3_1ABD8(void *arg0, s16 x1, s16 y1, s16 x2, s16 y2, u32 *value);
extern void fn_3_1BA20(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 *arg5);
extern void fn_3_1BF08(void *data, s16 x1, s16 y1, s16 x2, s16 y2, u32 *color);
extern void fn_3_156A8(void);
extern void fn_3_1ACE4(void *data, s32 first_a, s32 second_a, s32 first_b, s32 second_b, u32 *values);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
}
static const unsigned long fzgx_pool_table2[6] = {0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0x0000FF00, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
    s = 0.0f;
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table4[43] = {0x00004A00, 0x00005400, 0x00003800, 0x00003E00, 0x00003700, 0x00005500, 0x00003000, 0x00003500, 0x00003A00, 0x00004000, 0x00004400, 0x00005000, 0x00003300, 0x00002E00, 0x00003100, 0x00004F00, 0x00003900, 0x00003D00, 0x00004C00, 0x00003F00, 0x00004800, 0x00005200, 0x00004500, 0x00005300, 0x00003C00, 0x00005600, 0x00004300, 0x00004200, 0x00003200, 0x00002F00, 0x00003400, 0x00003600, 0x00004D00, 0x00004600, 0x00004100, 0x00005100, 0x00004E00, 0x00004700, 0x00003B00, 0x00004B00, 0x00004900, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 380.0f;
    s = 334.0f;
    s = 0.40625f;
}
static const unsigned long fzgx_pool_table6[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
static const unsigned long fzgx_pool_table10[9] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 182.04444885253906f;
    s = 10.0f;
}
static const unsigned long fzgx_pool_table12[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.75f;
    s = 3.5f;
    s = 0.05000000074505806f;
}
static const unsigned long fzgx_pool_table14[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.25f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
}
#pragma section code_type ".text"
struct fn_3_20374_Arg0 { u32 unk_0, unk_4, unk_8; };
typedef struct { s16 unk_0; u16 pad; u32 unk_4; } Entry;
s32 fn_3_20374(struct fn_3_20374_Arg0 *arg0) {
const struct fn_3_20374_lbl_3_rodata_768 *p_lbl_3_rodata_768;
struct fn_3_20374_lbl_1_data_1E5C0 *p_lbl_1_data_1E5C0;
Entry *v14,*v16;
s16 v13,v15,v17;
s32 v20;
u32 v19,v28,v25;
f32 v1,v2,v3,v18;

f32 loc_54[12];
struct fn_3_20374_lbl_1_data_1E5C0 loc_20;
struct fn_3_20374_Arg0 loc_14;
f32 loc_8[3];
loc_14=*arg0;
p_lbl_3_rodata_768=&(*((const struct fn_3_20374_lbl_3_rodata_768 *)&lbl_3_rodata_768));
fn_80008BEC(&lbl_3_bss_A2468.pad_0[4],0,12);
fn_80008BEC(&lbl_3_bss_A2468.pad_0[16],0,12);
lbl_3_bss_A2468.unk_14=*(f32*)&loc_14.unk_4;
fn_8006F038( (Vec3 *)((Sig_fn_8006F038_Vec3*)&lbl_3_bss_A2468.pad_0[4]), (Vec3 *)((Sig_fn_8006F038_Vec3*)&lbl_3_bss_A2468.pad_0[16]),0);
lbl_8006DCDC();
v1=0.7f;
p_lbl_1_data_1E5C0=&lbl_1_data_1E5C0;
v2=(f32)(p_lbl_1_data_1E5C0->unk_C*v1);
v3=(f32)(p_lbl_1_data_1E5C0->unk_10*v1);
loc_20=*p_lbl_1_data_1E5C0;
loc_20.unk_C=v2-v3;
loc_20.unk_10=v2+v3;
loc_20.unk_14=p_lbl_1_data_1E5C0->unk_14;
fn_1_F7870( (u32)(void*)(&loc_20));
for(v13=0;v13<7;v13++) {
f32 row;
f32 index=(f32)v13;
f32 spacing=3.5176470279693604f;
row=(f32)(index*spacing)-8.79411792755127f;
v14=(Entry*)((u8*)&lbl_3_bss_2C584+v13*56);
for(v15=0;v15<7;v15++) {
v16=&v14[v15];
v17=v16->unk_0;
v20=0;
if(v17==-1) continue;
v19=v16->unk_4;
if(v19&0x40000000) continue;
if(v19&0x80000000) continue;
if(v19&0x08000000) v20=1;
fn_80008BA8( (u32 *)(void*)(loc_8),&loc_14,12);
{
f32 step, column;
step=3.5176470279693604f;
v18=10.55294132232666f;
column=(f32)v15;
loc_8[0]+=(f32)(column*step)-v18;
loc_8[2]+=row;
}
lbl_8006D7DC(loc_8);
mathutil_mtxA_rotate_x((s32)(182.04444885253906f*(315.0f-(f32)(2.0f*loc_8[2]))));
if(lbl_3_data_C4==v17 && v20!=1) {
v25=lbl_801A66A0;
mathutil_mtxA_rotate_y((s32)(182.04444885253906f*(f32)(v25%360)));
lbl_8006E14C(1.2999999523162842f);
} else mathutil_mtxA_rotate_y(0x6000);
lbl_8006E14C(0.6000000238418579f);
lbl_8006DB74(loc_54);
lbl_8006DFE8(loc_54);
fn_80072558();
v28=lbl_3_bss_20854.unk_0+v17*0x440;
if(v28==0) return 0;
if(v20==1) {
v18=0.6274510025978088f;
fn_1_5621C(v18,v18,v18,0.7529411911964417f);
}
v18=1.0f;
fn_1_870BC(v28,1,(Sig_fn_1_87610_Fn187610Data*)v28,0,4,v18);
v18=1.0f;
fn_1_5621C(v18,v18,v18,v18);
}
}
return 0;
}
/* fzgx:end fn_3_20374 */

/* fzgx:begin fn_3_20748 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/toolkit.h"
#include "font.h"
#include "types.h"

/* begin game/vec3.h (deltawave784/fzgx, CC0) */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,
// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,
// stcoli). Hand-owned (librarian).


typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

#endif  // GAME_VEC3_H

/* end game/vec3.h */





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

typedef struct CustomizeData {
    u32 unk_00[2];
    u32 unk_08;
    u8 pad_0c[0x14];
    void *unk_20;
} CustomizeData;

struct fn_3_1A1D8_lbl_1_bss_9F8_0_E20 {
    u8 pad_0[0x10];
    u16 unk_10;
    u8 pad_12[0x2];
};

struct fn_3_1A1D8_lbl_1_bss_9F8 {
    struct fn_3_1A1D8_lbl_1_bss_9F8_0_E20 unk_0[1];
};

struct fn_3_1A264_lbl_1_bss_9F8_10_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};

struct fn_3_1A264_lbl_1_bss_9F8 {
    u8 pad_0[0x10];
    struct fn_3_1A264_lbl_1_bss_9F8_10_E20 unk_10[1];
};

typedef struct {
    u8 r, g, b, a;
} QColor;

typedef struct { u32 id; f32 x,y,z; u32 rest[18]; } Packet23524;

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

struct fn_3_23724_Copy88 {
    u32 flags;
    f32 x, y, z;
    u32 pad[8];
    u32 mode;
    u32 tail[9];
};

typedef struct {
    u32 flags;
    u8 pad[0x1c];
} fn_3_1F81C_CustomizeEntry;

typedef struct CustomizeObject CustomizeObject;

struct CustomizeObject {
    u8 pad0[0x18];
    u16 count;
    u8 pad1[0x26];
    fn_3_1F81C_CustomizeEntry entries[1];
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

struct fn_3_20374_lbl_1_data_1E5C0 {
u32 unk_0,unk_4,unk_8; f32 unk_C,unk_10,unk_14; u32 unk_18,unk_1C,unk_20,unk_24,unk_28,unk_2C,unk_30;
};

struct fn_3_23724_lbl_3_rodata_768 {
    u8 pad_0[0x78];
    f32 seven;
    u8 pad_7C[0x10C];
    f32 one;
    f32 half;
    u8 pad_190[0x40];
    f32 zero;
    u8 pad_1D4[0x180];
    f32 twentythree;
    u8 pad_358[0xC];
    f32 twelve;
    u8 pad_368[0x40];
    f32 unk_3A8;
    f32 unk_3AC;
    f32 five;
};

struct fn_3_2BFB4_lbl_3_rodata_768 {
    u8 pad_0[0x22C];
    f32 unk_22C;
    u8 pad_230[0x1E8];
    f32 unk_418;
    u8 pad_41C[0x25C];
    f32 unk_678;
};

struct fn_3_2C164_lbl_3_rodata_768 {
    u8 pad_0[0x22C];
    f32 unk_22C;
    u8 pad_230[0x1E8];
    f32 unk_418;
    u8 pad_41C[0x25C];
    f32 unk_678;
};

struct fn_3_20374_lbl_3_rodata_768 {
f32 unk_0; u8 pad_4[0x94]; f64 unk_98; u8 pad_A0[0xE8]; f32 unk_188;
u8 pad_18C[0x6C]; f64 unk_1F8; u8 pad_200[0x28]; f32 unk_228;
u8 pad_22C[0x5C]; f32 unk_288,unk_28C,unk_290,unk_294,unk_298,unk_29C,unk_2A0,unk_2A4,unk_2A8;
};

typedef struct Sig_fn_1_87610_Fn187610Data {
u8 pad_000[2]; s8 field_002; u8 pad_003[0x205]; u8 field_208[0x120];
} Sig_fn_1_87610_Fn187610Data;

typedef struct Sig_fn_8006F038_Vec3 { f32 x,y,z; } Sig_fn_8006F038_Vec3;

struct fn_3_2B268_lbl_1_bss_7F0C0 {
    u8 pad_0[0x48F8];
    u32 unk_48F8;
};

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

typedef s32 (*Sig_fn_1_8D210_fn_1_8D210_callback)(u32);

struct fn_3_2BFB4_lbl_801A66B4 {
    u32 unk_0;
};

typedef struct Rgba {
    u8 r, g, b, a;
} Rgba;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    Vec3 pos;
    u32 unk_18[7];
} Fn3_1FF7C_Camera;

typedef struct {
    u8 pad_0[0x60];
    Vec3 pos;
    f32 unk_6C;
} Fn3_1FF7C_Mtx;

typedef struct {
    u32 flags;
    u8 pad_4[0x1C];
} Fn3_1FF7C_Entry;

typedef struct {
    u8 pad_0[0x18];
    u16 count;
    u8 pad_1A[0x26];
    Fn3_1FF7C_Entry entries[1];
} Fn3_1FF7C_Model;


typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} fn_3_1A648_Pad;

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
extern const f32 lbl_3_rodata_740;
extern void fn_3_1B130(void *data, s16 x, s16 y, Rgba color);
extern void fn_3_BE10(void);
extern void fn_3_BEF0(void);
extern void fn_3_1445C(void);
extern void fn_3_BE88(void);
extern void fn_80008BA8(u32 *, void *, s32);
extern s32 fn_8008023C(u32 arg0, u32 arg1, u32 arg2);
extern struct fn_3_1A1D8_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern u32 fn_3_141A8(u32);
extern u8 fn_3_1443C(void);
extern u32 fn_3_14064(void);
extern u32 fn_3_1401C(void);
extern u32 fn_3_1402C(u8 index);
extern void fn_1_A2D84(u32 arg0);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_3_1B4BC(void *, s16, s16, s16, s16, u32 *);
extern void fn_3_149AC();
extern void fn_3_14794(void *, u32, u32, u32 *);
extern void fn_3_146C0(void *arg0, s16 x, s16 y, s16 delta, u32 *arg4);
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A66A8;
extern u16 fn_1_A5DB0(void);
extern s32 fn_1_A5DC4(void);
extern f32 lbl_8006D188(s32);
extern void fn_1_50164();
extern void fn_1_49410(void);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49590(f32 value);
extern void fn_1_495A0(f32 value);
extern void fn_1_495C8(u8 value);
extern void fn_1_4966C(f32 value1, f32 value2);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_49738(u32 value);
extern u32 fn_3_2B750(s16, s16);
extern void fn_3_2406C(void);
extern void fn_3_240DC(void *, void *);
extern void fn_1_5233C(void *arg0, void *arg1);
extern struct fn_3_20374_lbl_1_data_1E5C0 lbl_1_data_1E5C0;
extern u32 lbl_801A66A0;
extern CustomizeObject *lbl_801A6D00;
extern void fn_8006F038(Vec3 *arg0, Vec3 *arg1, s16 arg2);
extern void lbl_8006DCDC(void);
extern void fn_1_F7870(u32 value);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern u32 fn_1_56018(s32 value);
extern void lbl_8006D784(void *);
extern void fn_1_560F0(s32 index, void *arg);
extern void fn_80072558(void);
extern void fn_1_55210(CustomizeObject *);
extern void lbl_8006DB74(void*);
extern void fn_1_151BDC(u32 value);
extern void fn_1_14E2DC(void *, s16, f32);
extern void lbl_8006DBAC(Vec3 *);
extern void fn_1_FCFA4(void *);
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
extern f32 fn_1_A6FE8(void);
extern u8 lbl_1_bss_7F0C0[];
extern u32 fn_3_1EFE4(void);
extern u32 lbl_801A66C0[1];
extern void fn_3_2A2F8(s16, s16, s16, s16, s32);
extern void fn_3_7A08(s16 *arg0, s16 *arg1, int arg2);
extern u32 fn_3_225F8(u32, u32, u32);
extern void fn_1_54278(u32 arg0, u32 arg1);
extern void fn_1_5428C(f32 value);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern void fn_1_495FC(void);
extern u32 fn_3_2B778(s16, u32, u32, u32, u32);
extern f32 lbl_8006D118(f32 *, f32);
extern void fzgx_usef(f32);
extern void fzgx_used(f64);
extern void fzgx_usep(void *);
extern s32 fzgx_sink_s;
extern u32 fzgx_sink_u;
extern void fn_3_1AB34(void *obj, s16 start, s16 base, u32 *items);
extern u32 fn_3_17820();
extern void fn_3_1ADA4(void *, int, int, int, int);
extern void fn_3_1AE40(void *data, u32 x1, u32 y1, s16 x2, s16 y2);
extern void fn_3_1AEE4(void *data, u32 x1, u32 y1, u32 x2, u32 y2);
extern void fn_3_1B008(void *data, u32 x1, u32 y1, u32 x2, u32 y2);
extern u8 lbl_3_bss_A2458[8];
extern void fn_3_BD98(void);
extern u8 fn_3_1441C(void);
extern void fn_3_14008(void);
extern const QColor lbl_3_rodata_744[9];
extern void fn_3_152BC(u32, s32, s32, s32, s32, QColor);
extern void fn_3_14E18(void *arg0, u32 arg1, u32 arg2, s16 arg3, u32 arg4);
extern const f32 lbl_3_rodata_8F0;
extern const f32 lbl_3_rodata_990[297];
extern CustomizeRoot lbl_1_bss_38460;
extern u32 fn_1_870BC(u32,u32,Sig_fn_1_87610_Fn187610Data*,u32,u32,f32);
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void lbl_8006D7DC(void*);
extern void lbl_8006DFE8(void*);
extern void lbl_8006E14C(f32);
extern s32 fn_3_1EC2C(u32);
extern void fn_3_23724(u32 arg0, u32 arg1, u32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
extern u32 fn_3_21300(u32,u32,u32);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern u32 fn_1_151E20(u32 value, s16 index);
extern void fn_1_A9868();
extern void fn_1_AA188(s32, s32, s32, s32, void *, void *, void *, void *);
extern void fn_1_AA538(void);
extern void fn_1_4E0F4(void);
extern s32 lbl_3_bss_24370;
extern f64 lbl_3_rodata_800;
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern int sprintf(char *s, const char *format, ...);
extern struct fn_3_2BFB4_lbl_801A66B4 lbl_801A66B4;
extern u8 fn_1_B7C00(void);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_3_1ABD8(void *arg0, s16 x1, s16 y1, s16 x2, s16 y2, u32 *value);
extern void fn_3_1BA20(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 *arg5);
extern void fn_3_1BF08(void *data, s16 x1, s16 y1, s16 x2, s16 y2, u32 *color);
extern void fn_3_156A8(void);
extern void fn_3_1ACE4(void *data, s32 first_a, s32 second_a, s32 first_b, s32 second_b, u32 *values);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
}
static const unsigned long fzgx_pool_table2[6] = {0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0x0000FF00, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
    s = 0.0f;
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table4[43] = {0x00004A00, 0x00005400, 0x00003800, 0x00003E00, 0x00003700, 0x00005500, 0x00003000, 0x00003500, 0x00003A00, 0x00004000, 0x00004400, 0x00005000, 0x00003300, 0x00002E00, 0x00003100, 0x00004F00, 0x00003900, 0x00003D00, 0x00004C00, 0x00003F00, 0x00004800, 0x00005200, 0x00004500, 0x00005300, 0x00003C00, 0x00005600, 0x00004300, 0x00004200, 0x00003200, 0x00002F00, 0x00003400, 0x00003600, 0x00004D00, 0x00004600, 0x00004100, 0x00005100, 0x00004E00, 0x00004700, 0x00003B00, 0x00004B00, 0x00004900, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 380.0f;
    s = 334.0f;
    s = 0.40625f;
}
static const unsigned long fzgx_pool_table6[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
static const unsigned long fzgx_pool_table10[9] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 182.04444885253906f;
    s = 10.0f;
}
static const unsigned long fzgx_pool_table12[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.75f;
    s = 3.5f;
    s = 0.05000000074505806f;
}
static const unsigned long fzgx_pool_table14[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.25f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
}
#pragma section code_type ".text"
struct fn_3_20748_Arg0 { u32 unk_0, unk_4, unk_8; };
typedef struct { s16 unk_0; u16 pad; u32 unk_4; } fn_3_20748_Entry;
s32 fn_3_20748(struct fn_3_20748_Arg0 *arg0) {
const struct fn_3_20374_lbl_3_rodata_768 *p_lbl_3_rodata_768;
struct fn_3_20374_lbl_1_data_1E5C0 *p_lbl_1_data_1E5C0;
fn_3_20748_Entry *v14,*v16;
s16 v13,v15,v17;
u32 v19,v28,v25;
f32 v1,v2,v3,v18;
f32 loc_54[12];
struct fn_3_20374_lbl_1_data_1E5C0 loc_20;
struct fn_3_20748_Arg0 loc_14;
f32 loc_8[3];
s16 lo, hi;
loc_14=*arg0;
p_lbl_3_rodata_768=&(*((const struct fn_3_20374_lbl_3_rodata_768 *)&lbl_3_rodata_768));
fn_80008BEC(&lbl_3_bss_A2468.pad_0[4],0,12);
fn_80008BEC(&lbl_3_bss_A2468.pad_0[16],0,12);
lbl_3_bss_A2468.unk_14=*(f32*)&loc_14.unk_4;
fn_8006F038( (Vec3 *)((Sig_fn_8006F038_Vec3*)&lbl_3_bss_A2468.pad_0[4]), (Vec3 *)((Sig_fn_8006F038_Vec3*)&lbl_3_bss_A2468.pad_0[16]),0);
lbl_8006DCDC();
v1=0.7f;
p_lbl_1_data_1E5C0=&lbl_1_data_1E5C0;
v2=(f32)(p_lbl_1_data_1E5C0->unk_C*v1);
v3=(f32)(p_lbl_1_data_1E5C0->unk_10*v1);
loc_20=*p_lbl_1_data_1E5C0;
loc_20.unk_C=v2-v3;
loc_20.unk_10=v2+v3;
loc_20.unk_14=p_lbl_1_data_1E5C0->unk_14;
fn_1_F7870( (u32)(void*)(&loc_20));
for(v13=0;v13<7;v13++) {
f32 index=(f32)v13;
f32 spacing=3.5999999046325684f;
v14=(fn_3_20748_Entry*)((u8*)&lbl_3_bss_2C584+v13*56);
for(v15=0;v15<7;v15++) {
v16=&v14[v15];
v17=v16->unk_0;
if(v17==-1) continue;
v19=v16->unk_4;
if(v19&0x40000000) continue;
if(v19&0x80000000) continue;
fn_3_7A08(&lo,&hi,3);
if((lbl_3_bss_F0.unk_24&0x80000000) && (lbl_3_bss_F0.unk_24&0x00800000)) {
if(v13<lo-1 || v13>hi+1) continue;
} else {
if(v13<lo || v13>hi) continue;
}
fn_80008BA8( (u32 *)(void*)(loc_8),&loc_14,12);
{
f32 step, column;
step=3.5176470279693604f;
v18=10.55294132232666f;
column=(f32)v15;
loc_8[0]+=(f32)(column*step)-v18;
loc_8[2]+=((f32)(index*spacing)-9.0f);
}
lbl_8006D7DC(loc_8);
mathutil_mtxA_rotate_x((s32)(182.04444885253906f*(315.0f-(f32)(2.0f*loc_8[2]))));
if(lbl_3_data_C4==v17) {
v25=lbl_801A66A0;
mathutil_mtxA_rotate_y((s32)(182.04444885253906f*(f32)(v25%360)));
lbl_8006E14C(1.2999999523162842f);
} else mathutil_mtxA_rotate_y(0x6000);
lbl_8006E14C(0.6000000238418579f);
lbl_8006DB74(loc_54);
lbl_8006DFE8(loc_54);
fn_80072558();
v28=lbl_3_bss_20854.unk_0+v17*0x440;
if(v28==0) return 0;
v18=1.0f;
fn_1_870BC(v28,1,(Sig_fn_1_87610_Fn187610Data*)v28,0,4,v18);
}
}
return 0;
}
/* fzgx:end fn_3_20748 */

/* fzgx:begin fn_3_23524 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/toolkit.h"
#include "font.h"
#include "types.h"

/* begin game/vec3.h (deltawave784/fzgx, CC0) */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,
// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,
// stcoli). Hand-owned (librarian).


typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

#endif  // GAME_VEC3_H

/* end game/vec3.h */





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

typedef struct CustomizeData {
    u32 unk_00[2];
    u32 unk_08;
    u8 pad_0c[0x14];
    void *unk_20;
} CustomizeData;

struct fn_3_1A1D8_lbl_1_bss_9F8_0_E20 {
    u8 pad_0[0x10];
    u16 unk_10;
    u8 pad_12[0x2];
};

struct fn_3_1A1D8_lbl_1_bss_9F8 {
    struct fn_3_1A1D8_lbl_1_bss_9F8_0_E20 unk_0[1];
};

struct fn_3_1A264_lbl_1_bss_9F8_10_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};

struct fn_3_1A264_lbl_1_bss_9F8 {
    u8 pad_0[0x10];
    struct fn_3_1A264_lbl_1_bss_9F8_10_E20 unk_10[1];
};

typedef struct {
    u8 r, g, b, a;
} QColor;

typedef struct { u32 id; f32 x,y,z; u32 rest[18]; } Packet23524;

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

struct fn_3_23724_Copy88 {
    u32 flags;
    f32 x, y, z;
    u32 pad[8];
    u32 mode;
    u32 tail[9];
};

typedef struct {
    u32 flags;
    u8 pad[0x1c];
} fn_3_1F81C_CustomizeEntry;

typedef struct CustomizeObject CustomizeObject;

struct CustomizeObject {
    u8 pad0[0x18];
    u16 count;
    u8 pad1[0x26];
    fn_3_1F81C_CustomizeEntry entries[1];
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

struct fn_3_20374_lbl_1_data_1E5C0 {
u32 unk_0,unk_4,unk_8; f32 unk_C,unk_10,unk_14; u32 unk_18,unk_1C,unk_20,unk_24,unk_28,unk_2C,unk_30;
};

struct fn_3_23724_lbl_3_rodata_768 {
    u8 pad_0[0x78];
    f32 seven;
    u8 pad_7C[0x10C];
    f32 one;
    f32 half;
    u8 pad_190[0x40];
    f32 zero;
    u8 pad_1D4[0x180];
    f32 twentythree;
    u8 pad_358[0xC];
    f32 twelve;
    u8 pad_368[0x40];
    f32 unk_3A8;
    f32 unk_3AC;
    f32 five;
};

struct fn_3_2BFB4_lbl_3_rodata_768 {
    u8 pad_0[0x22C];
    f32 unk_22C;
    u8 pad_230[0x1E8];
    f32 unk_418;
    u8 pad_41C[0x25C];
    f32 unk_678;
};

struct fn_3_2C164_lbl_3_rodata_768 {
    u8 pad_0[0x22C];
    f32 unk_22C;
    u8 pad_230[0x1E8];
    f32 unk_418;
    u8 pad_41C[0x25C];
    f32 unk_678;
};

struct fn_3_20374_lbl_3_rodata_768 {
f32 unk_0; u8 pad_4[0x94]; f64 unk_98; u8 pad_A0[0xE8]; f32 unk_188;
u8 pad_18C[0x6C]; f64 unk_1F8; u8 pad_200[0x28]; f32 unk_228;
u8 pad_22C[0x5C]; f32 unk_288,unk_28C,unk_290,unk_294,unk_298,unk_29C,unk_2A0,unk_2A4,unk_2A8;
};

typedef struct Sig_fn_1_87610_Fn187610Data {
u8 pad_000[2]; s8 field_002; u8 pad_003[0x205]; u8 field_208[0x120];
} Sig_fn_1_87610_Fn187610Data;

typedef struct Sig_fn_8006F038_Vec3 { f32 x,y,z; } Sig_fn_8006F038_Vec3;

struct fn_3_2B268_lbl_1_bss_7F0C0 {
    u8 pad_0[0x48F8];
    u32 unk_48F8;
};

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

typedef s32 (*Sig_fn_1_8D210_fn_1_8D210_callback)(u32);

struct fn_3_2BFB4_lbl_801A66B4 {
    u32 unk_0;
};

typedef struct Rgba {
    u8 r, g, b, a;
} Rgba;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    Vec3 pos;
    u32 unk_18[7];
} Fn3_1FF7C_Camera;

typedef struct {
    u8 pad_0[0x60];
    Vec3 pos;
    f32 unk_6C;
} Fn3_1FF7C_Mtx;

typedef struct {
    u32 flags;
    u8 pad_4[0x1C];
} Fn3_1FF7C_Entry;

typedef struct {
    u8 pad_0[0x18];
    u16 count;
    u8 pad_1A[0x26];
    Fn3_1FF7C_Entry entries[1];
} Fn3_1FF7C_Model;


typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} fn_3_1A648_Pad;

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
extern const f32 lbl_3_rodata_740;
extern void fn_3_1B130(void *data, s16 x, s16 y, Rgba color);
extern void fn_3_BE10(void);
extern void fn_3_BEF0(void);
extern void fn_3_1445C(void);
extern void fn_3_BE88(void);
extern void fn_80008BA8(u32 *, void *, s32);
extern s32 fn_8008023C(u32 arg0, u32 arg1, u32 arg2);
extern struct fn_3_1A1D8_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern u32 fn_3_141A8(u32);
extern u8 fn_3_1443C(void);
extern u32 fn_3_14064(void);
extern u32 fn_3_1401C(void);
extern u32 fn_3_1402C(u8 index);
extern void fn_1_A2D84(u32 arg0);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_3_1B4BC(void *, s16, s16, s16, s16, u32 *);
extern void fn_3_149AC();
extern void fn_3_14794(void *, u32, u32, u32 *);
extern void fn_3_146C0(void *arg0, s16 x, s16 y, s16 delta, u32 *arg4);
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A66A8;
extern u16 fn_1_A5DB0(void);
extern s32 fn_1_A5DC4(void);
extern f32 lbl_8006D188(s32);
extern void fn_1_50164();
extern void fn_1_49410(void);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49590(f32 value);
extern void fn_1_495A0(f32 value);
extern void fn_1_495C8(u8 value);
extern void fn_1_4966C(f32 value1, f32 value2);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_49738(u32 value);
extern u32 fn_3_2B750(s16, s16);
extern void fn_3_2406C(void);
extern void fn_3_240DC(void *, void *);
extern void fn_1_5233C(void *arg0, void *arg1);
extern struct fn_3_20374_lbl_1_data_1E5C0 lbl_1_data_1E5C0;
extern u32 lbl_801A66A0;
extern CustomizeObject *lbl_801A6D00;
extern void fn_8006F038(Vec3 *arg0, Vec3 *arg1, s16 arg2);
extern void lbl_8006DCDC(void);
extern void fn_1_F7870(u32 value);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern u32 fn_1_56018(s32 value);
extern void lbl_8006D784(void *);
extern void fn_1_560F0(s32 index, void *arg);
extern void fn_80072558(void);
extern void fn_1_55210(CustomizeObject *);
extern void lbl_8006DB74(void*);
extern void fn_1_151BDC(u32 value);
extern void fn_1_14E2DC(void *, s16, f32);
extern void lbl_8006DBAC(Vec3 *);
extern void fn_1_FCFA4(void *);
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
extern f32 fn_1_A6FE8(void);
extern u8 lbl_1_bss_7F0C0[];
extern u32 fn_3_1EFE4(void);
extern u32 lbl_801A66C0[1];
extern void fn_3_2A2F8(s16, s16, s16, s16, s32);
extern void fn_3_7A08(s16 *arg0, s16 *arg1, int arg2);
extern u32 fn_3_225F8(u32, u32, u32);
extern void fn_1_54278(u32 arg0, u32 arg1);
extern void fn_1_5428C(f32 value);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern void fn_1_495FC(void);
extern u32 fn_3_2B778(s16, u32, u32, u32, u32);
extern f32 lbl_8006D118(f32 *, f32);
extern void fzgx_usef(f32);
extern void fzgx_used(f64);
extern void fzgx_usep(void *);
extern s32 fzgx_sink_s;
extern u32 fzgx_sink_u;
extern void fn_3_1AB34(void *obj, s16 start, s16 base, u32 *items);
extern u32 fn_3_17820();
extern void fn_3_1ADA4(void *, int, int, int, int);
extern void fn_3_1AE40(void *data, u32 x1, u32 y1, s16 x2, s16 y2);
extern void fn_3_1AEE4(void *data, u32 x1, u32 y1, u32 x2, u32 y2);
extern void fn_3_1B008(void *data, u32 x1, u32 y1, u32 x2, u32 y2);
extern u8 lbl_3_bss_A2458[8];
extern void fn_3_BD98(void);
extern u8 fn_3_1441C(void);
extern void fn_3_14008(void);
extern const QColor lbl_3_rodata_744[9];
extern void fn_3_152BC(u32, s32, s32, s32, s32, QColor);
extern void fn_3_14E18(void *arg0, u32 arg1, u32 arg2, s16 arg3, u32 arg4);
extern const f32 lbl_3_rodata_8F0;
extern const f32 lbl_3_rodata_990[297];
extern CustomizeRoot lbl_1_bss_38460;
extern u32 fn_1_870BC(u32,u32,Sig_fn_1_87610_Fn187610Data*,u32,u32,f32);
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void lbl_8006D7DC(void*);
extern void lbl_8006DFE8(void*);
extern void lbl_8006E14C(f32);
extern s32 fn_3_1EC2C(u32);
extern void fn_3_23724(u32 arg0, u32 arg1, u32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
extern u32 fn_3_21300(u32,u32,u32);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern u32 fn_1_151E20(u32 value, s16 index);
extern void fn_1_A9868();
extern void fn_1_AA188(s32, s32, s32, s32, void *, void *, void *, void *);
extern void fn_1_AA538(void);
extern void fn_1_4E0F4(void);
extern s32 lbl_3_bss_24370;
extern f64 lbl_3_rodata_800;
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern int sprintf(char *s, const char *format, ...);
extern struct fn_3_2BFB4_lbl_801A66B4 lbl_801A66B4;
extern u8 fn_1_B7C00(void);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_3_1ABD8(void *arg0, s16 x1, s16 y1, s16 x2, s16 y2, u32 *value);
extern void fn_3_1BA20(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 *arg5);
extern void fn_3_1BF08(void *data, s16 x1, s16 y1, s16 x2, s16 y2, u32 *color);
extern void fn_3_156A8(void);
extern void fn_3_1ACE4(void *data, s32 first_a, s32 second_a, s32 first_b, s32 second_b, u32 *values);

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
}
#pragma section code_type ".text"
#define F(off) ((off)==0x74 ? 6.0f : (off)==0x188 ? 1.0f : (off)==0x18c ? 0.5f : (off)==0x1d0 ? 0.0f : (off)==0x22c ? 10.0f : (off)==0x37c ? 16.0f : (off)==0x39c ? -71.0f : (off)==0x3a0 ? 172.0f : 63.0f)
void fn_3_23524(void) {
    Packet23524 packet;
    s16 a,b;
    f32 scale;
    f32 t;
    f32 *pool = lbl_3_rodata_768;
    fn_1_133DBC((void *)1);
    lbl_3_bss_241E0.unk_38 = 0;
    lbl_3_bss_241E0.unk_58 = 0;
    lbl_3_bss_241E0.unk_0 = F(0x1d0);
    lbl_3_bss_241E0.unk_4 = F(0x39c);
    lbl_3_bss_241E0.unk_8 = lbl_3_bss_241E0.unk_20;
    lbl_3_bss_241E0.unk_C = lbl_3_bss_241E0.unk_24;
    lbl_3_bss_241E0.unk_48 = fn_1_A6FE8();
    fn_1_8D1EC(&lbl_3_bss_241E0, fn_3_1EC2C, 0);
    fn_3_2A2F8(0x228,0x19,5,15,*(s32 *)(lbl_1_bss_7F0C0+0x48f8));
    t = F(0x74)/(f32)lbl_3_bss_7EBA0;
    scale = t < F(0x1d0) ? F(0x1d0) : t > F(0x188) ? F(0x188) : t;
    fn_3_7A08(&a,&b,6);
    t = (f32)(a+b)/2.0f;
    fn_3_23724(0x252,0xe6,10,F(0x37c),F(0x3a0),
        t/((f32)lbl_3_bss_7EBA0-F(0x188)),scale);
    fn_3_21300(0x12f,0x13c,0xc8);
    fn_1_134AD4();
    fn_1_13ABA8(0x28000000);
    packet = (*((const Packet23524 *)&lbl_1_rodata_26F8));
    packet.id = 0xa310;
    packet.x = F(0x3a4);
    packet.y = F(0x37c);
    packet.z = F(0x22c);
    fn_1_4F734((FontDrawPacket *)&packet);
}
/* fzgx:end fn_3_23524 */

/* fzgx:begin fn_3_23724 */
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
static inline f32 fn_3_23724_clamp(f32 x) {
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

/* fzgx:begin fn_3_23A1C */
#pragma pool_data on

struct fn_3_23A1C_Copy88 {
 u32 id; f32 x,y,z; u8 pad_10[0x1c]; f32 alpha; u32 count;
 u8 pad_34[4]; u8 r,g,b,a; u8 pad_3C[0x1c];
};
struct fn_3_23A1C_lbl_3_rodata_768 {
 u8 pad_0[0x98]; f64 unk_98; u8 pad_A0[0xE8]; f32 unk_188;
 u8 pad_18C[0x224]; f32 unk_3B0; u32 unk_3B4; u32 unk_3B8;
 u32 unk_3BC,unk_3C0; f32 unk_3C4; f32 unk_3C8,unk_3CC,unk_3D0,unk_3D4;
};
extern struct fn_3_23A1C_lbl_3_rodata_768 lbl_3_rodata_768;
const u32 fzgx_pool_table_0[7] = {0x3F333333,0xFFFFFF00,0xFFFF0000,0xFF000000,0x0000FF00,0xFFF200FF,0xFFFF0000};
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_1c(void) { return 0.4583333432674408f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_20[5] = {0x438E0000,0x43A48000,0x42C80000,0x3F6AAAAB,0x43B40000};
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_34(void) { return 0.5416666865348816f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_38[16] = {0x43DC8000,0x43A60000,0x43AC8000,0x43B30000,0x3EF99999,0x43C58000,0x43A58000,0x43B38000,0x43A00000,0x43B50000,0x43480000,0x43A18000,0x43BE8000,0x41500000,0x3C008081,0x40C00000};
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_78(void) { return 7.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_7c[7] = {0x3E189899,0x3E048485,0x43040000,0x43160000,0x3F4CCCCD,0x3E99999A,0x00000000};
#pragma section code_type ".fzgxpool"
f64 fzgx_pool_primer_98(void) { return 4503601774854144.0; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_a0[56] = {0x00004A00,0x00005400,0x00003800,0x00003E00,0x00003700,0x00005500,0x00003000,0x00003500,0x00003A00,0x00004000,0x00004400,0x00005000,0x00003300,0x00002E00,0x00003100,0x00004F00,0x00003900,0x00003D00,0x00004C00,0x00003F00,0x00004800,0x00005200,0x00004500,0x00005300,0x00003C00,0x00005600,0x00004300,0x00004200,0x00003200,0x00002F00,0x00003400,0x00003600,0x00004D00,0x00004600,0x00004100,0x00005100,0x00004E00,0x00004700,0x00003B00,0x00004B00,0x00004900,0xFFF200FF,0xFFFF0000,0x43BE0000,0x43A70000,0x3ED00000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x43F00000,0x44200000,0x42780000,0x3FABABAC};
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_180(void) { return 8.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_184[1] = {0x3E000000};
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_188(void) { return 1.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_18c(void) { return 0.5f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_190[7] = {0x43570000,0x40400000,0x43340000,0x42B40000,0x43700000,0x42300000,0x42B3CCCD};
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_1ac(void) { return 40.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_1b0(void) { return 16384.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_1b4(void) { return 65536.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_1b8(void) { return 60.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_1bc(void) { return 80.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_1c0[4] = {0x43E60000,0x3F2AAAAB,0x3F1B9B9C,3225419776u /* -3.0f */};
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_1d0(void) { return 0.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_1d4[3] = {0x3F1E9E9F,0x3F018182,0x43580000};
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_1e0(void) { return 0.20000000298023224f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_1e4[5] = {0x430C0000,0x437A0000,0x43C80000,0x44098000,0x3EEEEEEF};
#pragma section code_type ".fzgxpool"
f64 fzgx_pool_primer_1f8(void) { return 4503599627370496.0; }
#pragma section code_type ".text"
/* 3231711232u is -5.0f, 3245342720u is -15.0f (decimal so they are not read as addresses) */
const u32 fzgx_pool_table_200[108] = {0x00000000,0x41200000,3231711232u,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0xBF000000,0x43360B61,0x41200000,0x00000000,0x41200000,3231711232u,0x00000000,0x00000000,0x00000000,0x40700000,0x40600000,0x3D4CCCCD,0x00000000,0x41200000,3231711232u,0x00000000,0x00000000,0x00000000,0x3E800000,0x00000000,0x41200000,3231711232u,0x00000000,0x00000000,0x00000000,0x40612121,0x410CB4B5,0x4128D8D9,0x439D8000,0x40000000,0x3FA66666,0x3F19999A,0x3F20A0A1,0x3F40C0C1,0x40666666,0x41100000,0x00000000,0x41200000,3231711232u,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000003,0x00020001,0x00000001,0x00020003,0x00000000,0x40A00000,3245342720u,0x00000000,0x00000000,0x00000000,0x40A6C6C7,0x00000000,0x00000000,0xBE58D8D9,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00FFFF00,0x00FFFF00,0x00FF0000,0x00FF0000,0x00FF0000,0x00FF0000,0xFFFF0000,0x43850000,0x42F00000,0x4408C000,0x432D0000,0x41B80000,0x435F0000,0x43808000,0x41A00000,0x41400000,0x42878000,0x40200000,0x3EB33333,0x3E19999A,0x41300000,0x41800000,0x00FFFF00,0x00FFFF00,0x00FF0000,0x00FF0000,0x438F0000,0x43190000,0x438A8000,0xC28E0000,0x432C0000,0x427C0000,0x40800000,0x41C00000};
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_3b0(void) { return 5.0f; }
#pragma section code_type ".text"
/* volatile: keeps each pooled word a real lwz from the pool instead of a folded li */
const volatile u32 fzgx_pool_table_3b4[1] = {0x00170018}; /* volatile: pool word load */
const volatile u32 fzgx_pool_table_3b8[1] = {0x0019001F}; /* volatile: pool word load */
const volatile u32 fzgx_pool_table_3bc[1] = {0xFFFFFF00}; /* volatile: pool word load */
const volatile u32 fzgx_pool_table_3c0[1] = {0xFFFF0000}; /* volatile: pool word load */
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_3c4(void) { return 0.10000000149011612f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_3c8(void) { return 127.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_3cc(void) { return -2.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_3d0(void) { return 15.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
f32 fzgx_pool_primer_3d4(void) { return 0.4166666567325592f; }
#pragma section code_type ".text"

extern struct fn_3_23A1C_Copy88 lbl_1_rodata_26F8;
extern u32 lbl_801A66A8;
extern char *lbl_1_data_21078[], *lbl_1_data_212A8[];
extern void fn_1_5233C(void *, void *);
extern void fn_1_50164(f32,f32,f32,f32,void *);
extern f32 lbl_8006D188(u32);
extern void fn_1_49410(void);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32,f32);
extern void fn_1_4966C(f32,f32);
extern void fn_1_49514(u32 *);
extern void fn_1_496FC(f32,f32);
extern void fn_1_4954C(f32);
extern void fn_1_49738(void *);
extern void fn_1_495A0(f32);
extern void fn_1_49590(f32);
extern void fn_1_4AE0C(const char *,...);
extern void fn_1_495B0(u32);
extern void fn_1_4965C(u8);
extern void fn_1_49748(f32);
extern s16 fn_1_12C930(s16);
extern char *fn_1_14EA74(s16,char *,s16);
extern u32 fn_3_2B750(s16,s16);

void fn_3_23A1C(s16 arg0,u32 arg1,u32 arg2,s16 arg3,s32 arg4) {
 struct fn_3_23A1C_lbl_3_rodata_768 *p_lbl_3_rodata_768 = &lbl_3_rodata_768;
 Obj_3_bss_F0 *p_lbl_3_bss_F0 = &lbl_3_bss_F0;
 Obj_3_bss_20 *p_lbl_3_bss_20 = &lbl_3_bss_20;
 struct fn_3_23A1C_Copy88 *p_lbl_1_rodata_26F8 = &lbl_1_rodata_26F8;
 s32 xBase;
 s32 x;
 s32 v3;
 s32 v4=0;
 s32 v1 = p_lbl_3_bss_F0->unk_A;
 f32 v11 = (f32)(s16)arg2 - 0.1f;
 f32 v12 = 15.0f;
 f32 v2 = 1.0f;
 f32 v13 = 5.0f;
 s32 v7=0;
 struct fn_3_23A1C_Copy88 loc_58;
 char buffer[64];
 struct { u32 a[2]; } loc_10;
 u32 color1,color2;
 v3=arg3;
 while ((s16)v4 < 4) {
  loc_10.a[0]=fzgx_pool_table_3b4[0];
  loc_10.a[1]=fzgx_pool_table_3b8[0];
  loc_58=lbl_1_rodata_26F8;
  xBase=arg0;
  x=xBase+v4*v3;
  loc_58.id=0x8904;
  loc_58.x=(f32)x;
  loc_58.y=(f32)(s16)arg1;
  loc_58.z=(f32)(s16)arg2;
  loc_58.count=10;
  if(arg4==1 && (s16)v4==3) loc_58.alpha=0.2f;
  fn_1_50164(127.0f,40.0f,8.0f,8.0f,&loc_58);
  if(p_lbl_3_bss_20->unk_18==(s16)v4) {
   loc_58=lbl_1_rodata_26F8;
   loc_58.id=0x8913;
   loc_58.x=(f32)x;
   loc_58.y=(f32)(s16)arg1;
   loc_58.z=v11;
   loc_58.count=10;
   loc_58.alpha=0.5f;
   if(arg4==1 && (s16)v4==3) loc_58.alpha=0.2f;
   loc_58.r=(40.0f+(f32)(40.0f*lbl_8006D188((s32)(16384.0f+(65536.0f*(f32)(lbl_801A66A8%60))/60.0f))));
   loc_58.g=(80.0f+(f32)(80.0f*lbl_8006D188((s32)(16384.0f+(65536.0f*(f32)(lbl_801A66A8%60))/60.0f))));
   loc_58.b=(80.0f+(f32)(80.0f*lbl_8006D188((s32)(16384.0f+(65536.0f*(f32)(lbl_801A66A8%60))/60.0f))));
   fn_1_50164(127.0f,40.0f,7.0f,7.0f,&loc_58);
  }
  fn_1_49410();
  fn_1_495C8(1);
  switch(p_lbl_3_bss_F0->unk_A) {
  case 5: default: fn_1_4955C(0.5416666865348816f,0.5416666865348816f); break;
  case 0: fn_1_4955C(0.4583333432674408f,0.5416666865348816f); break;
  }
  fn_1_4966C(-2.0f,0.0f);
  color1=fzgx_pool_table_3bc[0];
  fn_1_49514(&color1);
  fn_1_496FC(loc_58.x,loc_58.y-v12);
  fn_1_4954C(loc_58.z-v2);
  fn_1_49738(fn_1_5233C);
  if(arg4==1 && (s16)v4==3) fn_1_495A0(0.2f);
  switch(p_lbl_3_bss_F0->unk_A) {
  case 0: default: fn_1_49590(0.5f); break;
  case 5: break;
  }
  fn_1_4AE0C((char *)fn_3_2B750(((s16 *)loc_10.a)[v4],v1));
  fn_1_49410();
  fn_1_495C8(1);
  fn_1_495B0(0x80000000);
  fn_1_4965C(2);
  fn_1_4955C(0.4166666567325592f,0.5f);
  color2=fzgx_pool_table_3c0[0];
  fn_1_49514(&color2);
  fn_1_496FC(loc_58.x,(v13+loc_58.y)-v2);
  fn_1_4954C(loc_58.z-v2);
  fn_1_49738(fn_1_5233C);
  fn_1_49748(1.0f);
  if(arg4==1 && (s16)v4==3) fn_1_495A0(0.2f);
  switch(p_lbl_3_bss_F0->unk_A) {
  case 0: default: fn_1_49590(0.5f); break;
  case 5: break;
  }
  if((s16)v4==3) {
   s16 id=*(s16 *)((u8 *)p_lbl_3_bss_20+0xce);
   switch(p_lbl_3_bss_F0->unk_A) {
   case 5: fn_1_4AE0C((char *)&lbl_3_data_4B70,lbl_1_data_21078[fn_1_12C930(id)]); break;
   default: fn_1_4AE0C((char *)&lbl_3_data_4B70,lbl_1_data_212A8[fn_1_12C930(id)]); break;
   }
  } else {
   fn_1_4AE0C((char *)lbl_3_data_4B84,fn_1_14EA74(((s16 (*)[8])&lbl_3_bss_6D8C0)[((u8 *)p_lbl_3_bss_20)[v4*8]][0],buffer,v1));
  }
  v7+=v3;
  v4++;
 }
}
/* fzgx:end fn_3_23A1C */

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

/* fzgx:begin fn_3_24BC0 */
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


struct fn_3_24BC0_Copy88 { u32 a[22]; };
struct fn_3_24BC0_Copy176 { u32 a[44]; };

extern u32 lbl_1_rodata_26F8;
const u32 fzgx_pool_lbl_3_rodata_768[38] = {0x3F333333,0xFFFFFF00,0xFFFF0000,0xFF000000,0x0000FF00,0xFFF200FF,0xFFFF0000,0x3EEAAAAB,0x438E0000,0x43A48000,0x42C80000,0x3F6AAAAB,0x43B40000,0x3F0AAAAB,0x43DC8000,0x43A60000,0x43AC8000,0x43B30000,0x3EF99999,0x43C58000,0x43A58000,0x43B38000,0x43A00000,0x43B50000,0x43480000,0x43A18000,0x43BE8000,0x41500000,0x3C008081,0x40C00000,0x40E00000,0x3E189899,0x3E048485,0x43040000,0x43160000,0x3F4CCCCD,0x3E99999A,0x00000000};
#pragma section code_type ".fzgxpool"
f64 fzgx_pool_98(void) { return 4503601774854144.0; }
const u32 fzgx_pool_pool_a0[58] = {0x00004A00,0x00005400,0x00003800,0x00003E00,0x00003700,0x00005500,0x00003000,0x00003500,0x00003A00,0x00004000,0x00004400,0x00005000,0x00003300,0x00002E00,0x00003100,0x00004F00,0x00003900,0x00003D00,0x00004C00,0x00003F00,0x00004800,0x00005200,0x00004500,0x00005300,0x00003C00,0x00005600,0x00004300,0x00004200,0x00003200,0x00002F00,0x00003400,0x00003600,0x00004D00,0x00004600,0x00004100,0x00005100,0x00004E00,0x00004700,0x00003B00,0x00004B00,0x00004900,0xFFF200FF,0xFFFF0000,0x43BE0000,0x43A70000,0x3ED00000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x43F00000,0x44200000,0x42780000,0x3FABABAC,0x41000000,0x3E000000};
f32 fzgx_pool_188(void) { return 1.0f; }
const u32 fzgx_pool_pool_18c[134] = {0x3F000000,0x43570000,0x40400000,0x43340000,0x42B40000,0x43700000,0x42300000,0x42B3CCCD,0x42200000,0x46800000,0x47800000,0x42700000,0x42A00000,0x43E60000,0x3F2AAAAB,0x3F1B9B9C,3225419776U,0x00000000,0x3F1E9E9F,0x3F018182,0x43580000,0x3E4CCCCD,0x430C0000,0x437A0000,0x43C80000,0x44098000,0x3EEEEEEF,0x43300000,0x00000000,0x00000000,0x41200000,3231711232U,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0xBF000000,0x43360B61,0x41200000,0x00000000,0x41200000,3231711232U,0x00000000,0x00000000,0x00000000,0x40700000,0x40600000,0x3D4CCCCD,0x00000000,0x41200000,3231711232U,0x00000000,0x00000000,0x00000000,0x3E800000,0x00000000,0x41200000,3231711232U,0x00000000,0x00000000,0x00000000,0x40612121,0x410CB4B5,0x4128D8D9,0x439D8000,0x40000000,0x3FA66666,0x3F19999A,0x3F20A0A1,0x3F40C0C1,0x40666666,0x41100000,0x00000000,0x41200000,3231711232U,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000003,0x00020001,0x00000001,0x00020003,0x00000000,0x40A00000,3245342720U,0x00000000,0x00000000,0x00000000,0x40A6C6C7,0x00000000,0x00000000,0xBE58D8D9,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00FFFF00,0x00FFFF00,0x00FF0000,0x00FF0000,0x00FF0000,0x00FF0000,0xFFFF0000,0x43850000,0x42F00000,0x4408C000,0x432D0000,0x41B80000,0x435F0000,0x43808000,0x41A00000,0x41400000,0x42878000,0x40200000,0x3EB33333,0x3E19999A,0x41300000,0x41800000,0x00FFFF00,0x00FFFF00,0x00FF0000,0x00FF0000,0x438F0000,0x43190000,0x438A8000,0xC28E0000,0x432C0000};
f32 fzgx_pool_3a4(void) { return 63.0f; }
const u32 fzgx_pool_pool_3a8[31] = {0x40800000,0x41C00000,0x40A00000,0x00170018,0x0019001F,0xFFFFFF00,0xFFFF0000,0x3DCCCCCD,0x42FE0000,3221225472U,0x41700000,0x3ED55555,0x19FF1900,0x19FF1900,0x19FF1900,0x00FFFF00,0x00FFFF00,0xFFFF0000,0x43210000,0x438B0000,0x43380000,0x423C0000,0x43450000,0x43868000,0x43350000,0x43180000,0x43948000,0x42090000,0x42180000,0x43460000,0x438A0000};
const u32 fzgx_pool_pool_424[1] = {0x00FFFF00};
const u32 fzgx_pool_pool_428[1] = {0x00FFFF00};
const u32 fzgx_pool_pool_42c[1] = {0x00FFFF00};
const u32 fzgx_pool_pool_430[1] = {0x00FFFF00};
const struct fn_3_24BC0_Copy176 fzgx_pool_pool_434 = {{0x00006500,0x00006D00,0x00008000,0x00005800,0x00006900,0x00007500,0x00006400,0x00007400,0x00006300,0x00006C00,0x00005A00,0x00006E00,0x00008200,0x00006B00,0x00007900,0x00006800,0x00006A00,0x00005900,0x00006F00,0x00005700,0x00007200,0x00007E00,0x00007300,0x00007100,0x00005B00,0x00008100,0x00006200,0x00007A00,0x00005D00,0x00007C00,0x00005C00,0x00006100,0x00006000,0x00005E00,0x00007F00,0x00005F00,0x00007700,0x00007000,0x00007600,0x00007800,0x00007D00,0x00006700,0x00007B00,0x00006600}};
const u32 fzgx_pool_pool_4e4[1] = {0x00FFFF00};
const u32 fzgx_pool_pool_4e8[1] = {0x00FFFF00};
const u32 fzgx_pool_pool_4ec[1] = {0x00FFFF00};
f32 fzgx_pool_4f0(void) { return 0.75f; }
f32 fzgx_pool_4f4(void) { return 37.0f; }
f32 fzgx_pool_4f8(void) { return 74.0f; }
f32 fzgx_pool_4fc(void) { return 26.0f; }
f32 fzgx_pool_500(void) { return 70.0f; }
#pragma section code_type ".text"

extern s16 lbl_1_bss_962;
extern char *lbl_1_data_212A8[];
extern void fn_3_2406C(void);
extern int fn_1_4F734(FontDrawPacket *);
extern s16 fn_1_12C930(s16);
extern void fn_1_51564(u16,u16,u16,u16,u16,u16);
extern void fn_1_5158C(FontDrawPacket *,u32,s16,s16);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32,f32);
extern void fn_1_4954C(f32);
extern void fn_1_4962C(void);
extern void fn_1_495A0(f32);
extern void fn_1_49514(u32 *);
extern void fn_1_49738(void *);
extern u32 strlen(const char *);
extern f32 fn_1_4B040(const char *);
extern void fn_1_4955C(f32,f32);
extern void fn_1_4AE0C(const char *,...);

#define PF(n) (*(f32 *)&packet.a[(n)/4])
#define PW(n) (packet.a[(n)/4])
#define RF(n) (*(f32 *)(p_lbl_3_rodata_768+(n)))
#define RW(n) (*(u32 *)(p_lbl_3_rodata_768+(n)))

static inline f32 fn_3_24BC0_float(s16 value) { return value; }

static inline s32 fn_3_24BC0_number(s16 arg) {
    return arg==30 ? 0 : (arg>30 ? arg : arg+1);
}

static inline void fn_3_24BC0_digits(FontDrawPacket *packet, u32 code, s32 number, int tens) {
    s16 digit = tens ? number/10 : number%10;
    fn_1_5158C(packet, code, (s16)(digit%10), (s16)(digit/10));
}

void fn_3_24BC0(s16 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    u8 *p_lbl_3_rodata_768;
    s32 number;
    s16 digit;
    s16 i;
    f32 y;
    f32 ratio;
    u32 color;
    char buffer[64];
    struct fn_3_24BC0_Copy88 packet;
    struct fn_3_24BC0_Copy176 table;
    p_lbl_3_rodata_768 = (u8 *)&fzgx_pool_lbl_3_rodata_768;
    packet = *(struct fn_3_24BC0_Copy88 *)&lbl_1_rodata_26F8;
    PW(0)=0x8919;
    PF(4)=(s16)arg1; PF(8)=(s16)arg2; PF(12)=(s16)arg3;
    PF(0x2c)=arg4; PW(0x30)=0x0400000f; (*(void (**)(void))&PW(0x50))=fn_3_2406C;
    PW(0x38)=fzgx_pool_pool_424[0]; PF(0x10)*=arg5; PF(0x14)*=arg5;
    fn_1_4F734((FontDrawPacket *)&packet);
    packet = *(struct fn_3_24BC0_Copy88 *)&lbl_1_rodata_26F8;
    PW(0)=0x8919;
    PF(4)=(s16)arg1; PF(8)=(s16)arg2; PF(12)=(s16)arg3;
    PF(0x2c)=arg4; PW(0x30)=0x0408000d; (*(void (**)(void))&PW(0x50))=fn_3_2406C;
    PW(0x38)=fzgx_pool_pool_428[0]; PF(0x10)*=arg5; PF(0x14)*=arg5;
    fn_1_4F734((FontDrawPacket *)&packet);
    packet = *(struct fn_3_24BC0_Copy88 *)&lbl_1_rodata_26F8;
    PW(0)=0x8919;
    PF(4)=(s16)arg1; PF(8)=(s16)arg2; PF(12)=(s16)arg3;
    PF(0x2c)=arg4; PW(0x30)=0x04100007; (*(void (**)(void))&PW(0x50))=fn_3_2406C;
    PW(0x38)=fzgx_pool_pool_42c[0]; PF(0x10)*=arg5; PF(0x14)*=arg5;
    fn_1_4F734((FontDrawPacket *)&packet);
    packet = *(struct fn_3_24BC0_Copy88 *)&lbl_1_rodata_26F8;
    PW(0)=0x8919;
    PF(4)=(s16)arg1; PF(8)=(s16)arg2; PF(12)=(s16)arg3;
    PF(0x2c)=arg4; PW(0x30)=0x04180005; (*(void (**)(void))&PW(0x50))=fn_3_2406C;
    PW(0x38)=fzgx_pool_pool_430[0]; PF(0x10)*=arg5; PF(0x14)*=arg5;
    fn_1_4F734((FontDrawPacket *)&packet);
    table = fzgx_pool_pool_434;
    packet = *(struct fn_3_24BC0_Copy88 *)&lbl_1_rodata_26F8;
    PW(0)=table.a[fn_1_12C930(arg0)];
    PF(4)=(s16)arg1; PF(8)=(s16)arg2; PF(12)=(s16)arg3-1;
    PF(0x2c)=arg4; PW(0x30)=0x0400000a; (*(void (**)(void))&PW(0x50))=fn_3_2406C;
    PF(0x10)*=0.75f; PF(0x14)*=0.75f;
    PF(0x10)*=arg6; PF(0x14)*=arg6;
    fn_1_4F734((FontDrawPacket *)&packet);
    number=fn_3_24BC0_number(arg0);
    packet = *(struct fn_3_24BC0_Copy88 *)&lbl_1_rodata_26F8;
    PW(0)=0x891a;
    PF(4)=fn_3_24BC0_float(arg1)-(f32)(37.0f*arg5);
    y=fn_3_24BC0_float(arg2)-(f32)(74.0f*arg5);
    PF(8)=y; PF(12)=fn_3_24BC0_float(arg3);
    PF(0x2c)=arg4; PW(0x30)=0x04000005; (*(void (**)(void))&PW(0x50))=fn_3_2406C;
    PW(0x38)=fzgx_pool_pool_4e4[0]; PF(0x10)*=arg5; PF(0x14)*=arg5;
    fn_1_51564(0,0,12,16,10,1);
    fn_3_24BC0_digits((FontDrawPacket *)&packet,PW(0),number,1);
    fn_1_4F734((FontDrawPacket *)&packet);
    number=fn_3_24BC0_number(arg0);
    packet = *(struct fn_3_24BC0_Copy88 *)&lbl_1_rodata_26F8;
    PW(0)=0x891a;
    PF(4)=(s16)arg1-(f32)(26.0f*arg5); PF(8)=y; PF(12)=(s16)arg3;
    PF(0x2c)=arg4; PW(0x30)=0x04000005; (*(void (**)(void))&PW(0x50))=fn_3_2406C;
    PW(0x38)=fzgx_pool_pool_4e8[0]; PF(0x10)*=arg5; PF(0x14)*=arg5;
    fn_1_51564(0,0,12,16,10,1);
    fn_3_24BC0_digits((FontDrawPacket *)&packet,PW(0),number,0);
    fn_1_4F734((FontDrawPacket *)&packet);
    if (lbl_1_bss_962 != 93) {
        fn_1_49410(); fn_1_494DC(9); fn_1_495C8(1);
        fn_1_496FC((s16)arg1,(s16)arg2+(f32)(63.0f*arg5));
        fn_1_4954C((s16)arg3);
        fn_1_4962C(); fn_1_495A0(arg4);
        color=fzgx_pool_pool_4ec[0]; fn_1_49514(&color); fn_1_49738(fn_3_2406C);
        for(i=0;i<strlen(lbl_1_data_212A8[fn_1_12C930(arg0)]);i++) {
            if ((u8)lbl_1_data_212A8[fn_1_12C930(arg0)][i]=='&') buffer[i]='_';
            else if ((u8)lbl_1_data_212A8[fn_1_12C930(arg0)][i]==0x8145U) buffer[i]='^';
            else if ((u8)lbl_1_data_212A8[fn_1_12C930(arg0)][i]=='-') buffer[i]='\\';
            else if ((u8)lbl_1_data_212A8[fn_1_12C930(arg0)][i]=='.') buffer[i]='[';
            else buffer[i]=lbl_1_data_212A8[fn_1_12C930(arg0)][i];
        }
        buffer[i]=0;
        ratio=70.0f/fn_1_4B040(buffer);
        if (ratio<1.0f) ratio=70.0f/fn_1_4B040(buffer); else ratio=1.0f;
        fn_1_4955C(ratio,1.0f);
        fn_1_4AE0C((const char *)&lbl_3_data_4B70,buffer);
    }
}
/* fzgx:end fn_3_24BC0 */

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

/* fzgx:begin fn_3_26A34 */
#include "font.h"

/* Primer: reproduces the TU literal pool (lbl_3_rodata_768) up to 0x54C, where this
   function's own aggregate initializers start. */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[38] = {
    0x3F333333, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0x0000FF00, 0xFFF200FF, 0xFFFF0000, 0x3EEAAAAB,
    0x438E0000, 0x43A48000, 0x42C80000, 0x3F6AAAAB, 0x43B40000, 0x3F0AAAAB, 0x43DC8000, 0x43A60000,
    0x43AC8000, 0x43B30000, 0x3EF99999, 0x43C58000, 0x43A58000, 0x43B38000, 0x43A00000, 0x43B50000,
    0x43480000, 0x43A18000, 0x43BE8000, 0x41500000, 0x3C008081, 0x40C00000, 0x40E00000, 0x3E189899,
    0x3E048485, 0x43040000, 0x43160000, 0x3F4CCCCD, 0x3E99999A, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table3[56] = {
    0x00004A00, 0x00005400, 0x00003800, 0x00003E00, 0x00003700, 0x00005500, 0x00003000, 0x00003500,
    0x00003A00, 0x00004000, 0x00004400, 0x00005000, 0x00003300, 0x00002E00, 0x00003100, 0x00004F00,
    0x00003900, 0x00003D00, 0x00004C00, 0x00003F00, 0x00004800, 0x00005200, 0x00004500, 0x00005300,
    0x00003C00, 0x00005600, 0x00004300, 0x00004200, 0x00003200, 0x00002F00, 0x00003400, 0x00003600,
    0x00004D00, 0x00004600, 0x00004100, 0x00005100, 0x00004E00, 0x00004700, 0x00003B00, 0x00004B00,
    0x00004900, 0xFFF200FF, 0xFFFF0000, 0x43BE0000, 0x43A70000, 0x3ED00000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x43F00000, 0x44200000, 0x42780000, 0x3FABABAC};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 8.0f;
}
static const u32 fzgx_pool_table5[1] = {0x3E000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.5f;
}
static const u32 fzgx_pool_table7[1] = {0x43570000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.0f;
}
static const u32 fzgx_pool_table9[5] = {0x43340000, 0x42B40000, 0x43700000, 0x42300000, 0x42B3CCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 40.0f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 80.0f;
}
static const u32 fzgx_pool_table11[4] = {0x43E60000, 0x3F2AAAAB, 0x3F1B9B9C, 0xC0400000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
static const u32 fzgx_pool_table13[9] = {0x3F1E9E9F, 0x3F018182, 0x43580000, 0x3E4CCCCD, 0x430C0000, 0x437A0000, 0x43C80000, 0x44098000, 0x3EEEEEEF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table15[89] = {
    0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,  /* fzgx-allow: A1 retail pool bytes */
    0x00000000, 0xBF000000, 0x43360B61, 0x41200000, 0x00000000, 0x41200000, 0xC0A00000, 0x00000000,  /* fzgx-allow: A1 retail pool bytes */
    0x00000000, 0x00000000, 0x40700000, 0x40600000, 0x3D4CCCCD, 0x00000000, 0x41200000, 0xC0A00000,  /* fzgx-allow: A1 retail pool bytes */
    0x00000000, 0x00000000, 0x00000000, 0x3E800000, 0x00000000, 0x41200000, 0xC0A00000, 0x00000000,  /* fzgx-allow: A1 retail pool bytes */
    0x00000000, 0x00000000, 0x40612121, 0x410CB4B5, 0x4128D8D9, 0x439D8000, 0x40000000, 0x3FA66666,
    0x3F19999A, 0x3F20A0A1, 0x3F40C0C1, 0x40666666, 0x41100000, 0x00000000, 0x41200000, 0xC0A00000,  /* fzgx-allow: A1 retail pool bytes */
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003, 0x00020001,
    0x00000001, 0x00020003, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x00000000, 0x00000000,  /* fzgx-allow: A1 retail pool bytes */
    0x40A6C6C7, 0x00000000, 0x00000000, 0xBE58D8D9, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00FFFF00, 0x00FFFF00, 0x00FF0000, 0x00FF0000, 0x00FF0000, 0x00FF0000,
    0xFFFF0000, 0x43850000, 0x42F00000, 0x4408C000, 0x432D0000, 0x41B80000, 0x435F0000, 0x43808000,
    0x41A00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.0f;
}
static const u32 fzgx_pool_table17[1] = {0x42878000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 0.3499999940395355f;
    s = 0.15000000596046448f;
}
static const u32 fzgx_pool_table19[10] = {0x41300000, 0x41800000, 0x00FFFF00, 0x00FFFF00, 0x00FF0000, 0x00FF0000, 0x438F0000, 0x43190000, 0x438A8000, 0xC28E0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 172.0f;
}
static const u32 fzgx_pool_table21[20] = {
    0x427C0000, 0x40800000, 0x41C00000, 0x40A00000, 0x00170018, 0x0019001F, 0xFFFFFF00, 0xFFFF0000,
    0x3DCCCCCD, 0x42FE0000, 0xC0000000, 0x41700000, 0x3ED55555, 0x19FF1900, 0x19FF1900, 0x19FF1900,  /* fzgx-allow: A1 retail pool bytes */
    0x00FFFF00, 0x00FFFF00, 0xFFFF0000, 0x43210000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 278.0f;
}
static const u32 fzgx_pool_table23[7] = {0x43380000, 0x423C0000, 0x43450000, 0x43868000, 0x43350000, 0x43180000, 0x43948000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.25f;
}
static const u32 fzgx_pool_table25[73] = {
    0x42180000, 0x43460000, 0x438A0000, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00006500,
    0x00006D00, 0x00008000, 0x00005800, 0x00006900, 0x00007500, 0x00006400, 0x00007400, 0x00006300,
    0x00006C00, 0x00005A00, 0x00006E00, 0x00008200, 0x00006B00, 0x00007900, 0x00006800, 0x00006A00,
    0x00005900, 0x00006F00, 0x00005700, 0x00007200, 0x00007E00, 0x00007300, 0x00007100, 0x00005B00,
    0x00008100, 0x00006200, 0x00007A00, 0x00005D00, 0x00007C00, 0x00005C00, 0x00006100, 0x00006000,
    0x00005E00, 0x00007F00, 0x00005F00, 0x00007700, 0x00007000, 0x00007600, 0x00007800, 0x00007D00,
    0x00006700, 0x00007B00, 0x00006600, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x3F400000, 0x42140000,
    0x42940000, 0x41D00000, 0x428C0000, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x43130000,
    0x439E8000, 0x42F40000, 0x431C0000, 0x43980000, 0x44160000, 0x3DCCCCD0, 0x3EAE147A, 0xC2CC0000,
    0x42CC0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8999999761581421f;
}
static const u32 fzgx_pool_table27[3] = {0x3F28F5C3, 0x42BE0000, 0x42A80000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const u32 *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct fn_3_26A34_Rgba {
    u8 r, g, b, a;
} fn_3_26A34_Rgba;

extern u32 lbl_801A66A8;
extern u8 lbl_1_rodata_26F8[];
extern u8 lbl_3_data_4BA0[];
extern u32 fn_1_151E20(u32, s16);
extern void fn_1_151E74(u32 *, s16, int);
extern f32 lbl_8006D188(s32);
extern u32 fn_3_2B750(s16, s16);
extern void fn_1_49410(void);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_495FC(void);
extern void fn_1_4965C(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_50164(void *, f32, f32, f32, f32);
extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);
extern void fn_3_268D0(FontDrawPacket *, FontVertex *);
extern void fn_80008BA8(void *, void *, u32);

#pragma fp_contract off
void fn_3_26A34(s16 x, s16 y, s16 z) {
    FontDrawPacket pkt;
    u32 color;
    s16 i;
    s16 idx;
    u32 obj;
    Obj_3_bss_20 *st;
    f32 depth2;
    f32 depth;
    u32 value;

    depth = z - 10;
    obj = *(u32 *)((u8 *)&lbl_3_bss_20 + (lbl_3_bss_20.unk_18 << 3) +
                   (((s16 *)((u8 *)&lbl_3_bss_20 + 0xC6))[lbl_3_bss_20.unk_18] << 2) + 4);

    pkt = *(FontDrawPacket *)lbl_1_rodata_26F8;
    pkt.image = 0x8904;
    pkt.x = x;
    pkt.y = y;
    pkt.z = z;
    pkt.flags = 10;
    fn_1_50190(&pkt, 278.0f, 116.0f, 8.0f, 8.0f, 30.0f, 8.0f);

    pkt = *(FontDrawPacket *)lbl_1_rodata_26F8;
    pkt.image = 0x8910;
    pkt.x = 34.0f;
    pkt.y = 195.0f;
    pkt.z = z - 10;
    pkt.scale_y *= 0.9f;
    fn_1_4F734(&pkt);

    pkt = *(FontDrawPacket *)lbl_1_rodata_26F8;
    pkt.image = 0x8912;
    pkt.x = 270.0f;
    pkt.y = 202.0f;
    pkt.z = depth;
    pkt.flags = 10;
    fn_1_50164(&pkt, 40.0f, 14.0f, 3.0f, 3.0f);

    pkt = *(FontDrawPacket *)lbl_1_rodata_26F8;
    depth2 = 1.0f + depth;
    pkt.image = 0x12;
    pkt.x = 270.0f;
    pkt.y = 202.0f;
    pkt.z = depth2;
    pkt.color[0] = fn_1_151E20(obj, 0);
    pkt.color[1] = fn_1_151E20(obj, 1);
    pkt.color[2] = fn_1_151E20(obj, 2);
    pkt.flags = 10;
    fn_1_50164(&pkt, 40.0f, 14.0f, 3.0f, 3.0f);

    for (i = 0; i < 3; i++) {
        value = fn_1_151E20(obj, i);
        {
        s16 names[3] = {35, 36, 37};

        pkt = *(FontDrawPacket *)lbl_1_rodata_26F8;
        pkt.image = 0x8912;
        pkt.x = 204.0f;
        pkt.y = i * 24 + 238;
        pkt.z = depth;
        pkt.flags = 10;
        fn_1_50164(&pkt, 172.0f, 12.0f, 3.0f, 3.0f);

        pkt = *(FontDrawPacket *)lbl_1_rodata_26F8;
        pkt.image = 0x12;
        pkt.x = 204.0f;
        pkt.y = i * 24 + 238;
        pkt.z = depth2;
        pkt.flags = 0x400000A;
        pkt.alpha = 0.0f;
        pkt.scale_x *= 21.5f;
        pkt.scale_y *= 1.5f;
        pkt.color[0] = fn_1_151E20(obj, 0);
        pkt.color[1] = fn_1_151E20(obj, 1);
        pkt.color[2] = fn_1_151E20(obj, 2);
        pkt.color[3] = 255;
        fn_1_151E74(&color, 0, pkt.color[0]);
        fn_1_151E74(&color, 1, pkt.color[1]);
        fn_1_151E74(&color, 2, pkt.color[2]);
        switch (i) {
        case 0:
            pkt.color[0] = 0;
            fn_1_151E74(&color, 0, 255);
            break;
        case 1:
            pkt.color[1] = 0;
            fn_1_151E74(&color, 1, 255);
            break;
        case 2:
            pkt.color[2] = 0;
            fn_1_151E74(&color, 2, 255);
            break;
        }
        fn_80008BA8(&pkt.unk_54, &color, 4);
        pkt.vertex_callback = fn_3_268D0;
        fn_1_4F734(&pkt);

        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_4965C(2);
        fn_1_4955C(0.5f, 0.5f);
        fn_1_496FC(48.0f, i * 24 + 232);
        fn_1_4954C(depth);
        {
            fn_3_26A34_Rgba white = {255, 255, 255, 0};
            fn_1_49514((u32 *)&white);
        }
        if (i == *(s16 *)((u8 *)&lbl_3_bss_20 + 0xCC)) {
            fn_3_26A34_Rgba yellow = {255, 255, 0, 0};
            fn_1_49514((u32 *)&yellow);
        }
        fn_1_4AE0C((const char *)fn_3_2B750(names[i], lbl_3_bss_F0.unk_A));
        fn_1_4AE0C((const char *)lbl_3_data_4BA0, value);

        {
        fn_3_26A34_Rgba bar = {255, 242, 0, 0};
        pkt = *(FontDrawPacket *)lbl_1_rodata_26F8;
        pkt.image = 0x8911;
        pkt.x = 117.0f + 166.0f * (f32)value / 255.0f;
        pkt.y = i * 24 + 244;
        pkt.z = depth;
        *(fn_3_26A34_Rgba *)pkt.color = bar;
        fn_1_4F734(&pkt);
        }

        if (i == *(s16 *)((u8 *)&lbl_3_bss_20 + 0xCC)) {
            pkt = *(FontDrawPacket *)lbl_1_rodata_26F8;
            pkt.image = 0x891E;
            pkt.x = 29.0f;
            pkt.y = i * 24 + 228;
            pkt.z = z - 1;
            pkt.color[0] = 40.0f + 40.0f * lbl_8006D188(16384.0f + 65536.0f * (f32)(lbl_801A66A8 % 60) / 60.0f);
            pkt.color[1] = 80.0f + 80.0f * lbl_8006D188(16384.0f + 65536.0f * (f32)(lbl_801A66A8 % 60) / 60.0f);
            pkt.color[2] = 80.0f + 80.0f * lbl_8006D188(16384.0f + 65536.0f * (f32)(lbl_801A66A8 % 60) / 60.0f);
            pkt.scale_x = 34.25f;
            pkt.scale_y = 2.5f;
            pkt.alpha = 0.35f + 0.15f * lbl_8006D188(16384.0f + 65536.0f * (f32)(lbl_801A66A8 % 60) / 60.0f);
            fn_1_4F734(&pkt);
        }
        }
    }
}
/* fzgx:end fn_3_26A34 */

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

/* fzgx:begin fn_3_2AAF4 */
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


struct fn_3_2AAF4_Copy88 { u32 a[22]; };
struct fn_3_2AAF4_Color { u8 r, g, b, a; };
struct fn_3_2AAF4_lbl_3_rodata_768 {
    u8 pad_0[0x60]; f32 unk_60;
    u8 pad_64[0x34]; f64 unk_98;
    u8 pad_A0[0xE0]; f32 unk_180;
    u8 pad_184[8]; f32 unk_18C;
    u8 pad_190[8]; f32 unk_198;
    u8 pad_19C[0x10]; f32 unk_1AC;
    f32 unk_1B0, unk_1B4, unk_1B8, unk_1BC;
    u8 pad_1C0[0x10]; f32 unk_1D0;
    u8 pad_1D4[0x24]; f64 unk_1F8;
    u8 pad_200[0x2C]; f32 unk_22C;
    u8 pad_230[0x174]; f32 unk_3A4;
    u8 pad_3A8[0x24]; f32 unk_3CC;
    u8 pad_3D0[0x148]; f32 unk_518;
    u8 pad_51C[0x9C]; f32 unk_5B8;
    u8 pad_5BC[0x74]; u32 unk_630;
    f32 unk_634, unk_638;
    u32 unk_63C, unk_640, unk_644, unk_648, unk_64C, unk_650, unk_654, unk_658, unk_65C, unk_660;
    f32 unk_664, unk_668, unk_66C, unk_670, unk_674, unk_678, unk_67C, unk_680, unk_684, unk_688;
};
struct fn_3_2AAF4_lbl_1_bss_7F0C0 {
    u8 pad_0[0x48F8]; u32 unk_48F8;
};
extern struct fn_3_2AAF4_lbl_1_bss_7F0C0 lbl_1_bss_7F0C0;
extern s16 lbl_3_bss_20844;
extern struct fn_3_2AAF4_lbl_3_rodata_768 lbl_3_rodata_768;
extern u8 lbl_1_rodata_26F8[];
extern u32 lbl_801A66A8;
extern void fn_3_2A2F8(s16, s16, s16, s16, s32);
extern u32 fn_3_2B750(s16, s16);
extern f32 lbl_8006D188(u32);
extern u32 fn_1_50A90(void *, u32, u32, u32, u32);
extern void fn_1_50164(f32, f32, f32, f32, void *);
extern void fn_1_49410(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_133DBC(void *);
extern void fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
#define FLT(p,n) (*(f32 *)((u8 *)(p) + (n)))
#define BYTE(p,n) (*(u8 *)((u8 *)(p) + (n)))

/* Shared retail literal-pool layout. */
const u32 fzgx_pool_table_0[24] = {0x3F333333, 0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0x0000FF00, 0xFFF200FF, 0xFFFF0000, 0x3EEAAAAB, 0x438E0000, 0x43A48000, 0x42C80000, 0x3F6AAAAB, 0x43B40000, 0x3F0AAAAB, 0x43DC8000, 0x43A60000, 0x43AC8000, 0x43B30000, 0x3EF99999, 0x43C58000, 0x43A58000, 0x43B38000, 0x43A00000, 0x43B50000};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_60(f32 *out) { *out = 200.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_64[13] = {0x43A18000, 0x43BE8000, 0x41500000, 0x3C008081, 0x40C00000, 0x40E00000, 0x3E189899, 0x3E048485, 0x43040000, 0x43160000, 0x3F4CCCCD, 0x3E99999A, 0x00000000};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_98(f64 *out) { *out = 4503601774854144.0; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_a0[56] = {0x00004A00, 0x00005400, 0x00003800, 0x00003E00, 0x00003700, 0x00005500, 0x00003000, 0x00003500, 0x00003A00, 0x00004000, 0x00004400, 0x00005000, 0x00003300, 0x00002E00, 0x00003100, 0x00004F00, 0x00003900, 0x00003D00, 0x00004C00, 0x00003F00, 0x00004800, 0x00005200, 0x00004500, 0x00005300, 0x00003C00, 0x00005600, 0x00004300, 0x00004200, 0x00003200, 0x00002F00, 0x00003400, 0x00003600, 0x00004D00, 0x00004600, 0x00004100, 0x00005100, 0x00004E00, 0x00004700, 0x00003B00, 0x00004B00, 0x00004900, 0xFFF200FF, 0xFFFF0000, 0x43BE0000, 0x43A70000, 0x3ED00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x43F00000, 0x44200000, 0x42780000, 0x3FABABAC};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_180(f32 *out) { *out = 8.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_184[2] = {0x3E000000, 0x3F800000};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_18c(f32 *out) { *out = 0.5f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_190[2] = {0x43570000, 0x40400000};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_198(f32 *out) { *out = 180.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_19c[4] = {0x42B40000, 0x43700000, 0x42300000, 0x42B3CCCD};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_1ac(f32 *out) { *out = 40.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_1b0(f32 *out) { *out = 16384.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_1b4(f32 *out) { *out = 65536.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_1b8(f32 *out) { *out = 60.0f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_1bc(f32 *out) { *out = 80.0f; }
#pragma section code_type ".text"
/* These u32 tables hold IEEE-754 literal-pool bits, not addresses. */
const u32 fzgx_pool_table_1c0[4] = {0x43E60000, 0x3F2AAAAB, 0x3F1B9B9C, 3225419776U};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_1d0(f32 *out) { *out = 0.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_1d4[9] = {0x3F1E9E9F, 0x3F018182, 0x43580000, 0x3E4CCCCD, 0x430C0000, 0x437A0000, 0x43C80000, 0x44098000, 0x3EEEEEEF};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_1f8(f64 *out) { *out = 4503599627370496.0; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_200[11] = {0x00000000, 0x41200000, 3231711232U, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBF000000, 0x43360B61};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_22c(f32 *out) { *out = 10.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_230[93] = {0x00000000, 0x41200000, 3231711232U, 0x00000000, 0x00000000, 0x00000000, 0x40700000, 0x40600000, 0x3D4CCCCD, 0x00000000, 0x41200000, 3231711232U, 0x00000000, 0x00000000, 0x00000000, 0x3E800000, 0x00000000, 0x41200000, 3231711232U, 0x00000000, 0x00000000, 0x00000000, 0x40612121, 0x410CB4B5, 0x4128D8D9, 0x439D8000, 0x40000000, 0x3FA66666, 0x3F19999A, 0x3F20A0A1, 0x3F40C0C1, 0x40666666, 0x41100000, 0x00000000, 0x41200000, 3231711232U, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003, 0x00020001, 0x00000001, 0x00020003, 0x00000000, 0x40A00000, 3245342720U, 0x00000000, 0x00000000, 0x00000000, 0x40A6C6C7, 0x00000000, 0x00000000, 0xBE58D8D9, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00FFFF00, 0x00FFFF00, 0x00FF0000, 0x00FF0000, 0x00FF0000, 0x00FF0000, 0xFFFF0000, 0x43850000, 0x42F00000, 0x4408C000, 0x432D0000, 0x41B80000, 0x435F0000, 0x43808000, 0x41A00000, 0x41400000, 0x42878000, 0x40200000, 0x3EB33333, 0x3E19999A, 0x41300000, 0x41800000, 0x00FFFF00, 0x00FFFF00, 0x00FF0000, 0x00FF0000, 0x438F0000, 0x43190000, 0x438A8000, 0xC28E0000, 0x432C0000};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_3a4(f32 *out) { *out = 63.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_3a8[9] = {0x40800000, 0x41C00000, 0x40A00000, 0x00170018, 0x0019001F, 0xFFFFFF00, 0xFFFF0000, 0x3DCCCCCD, 0x42FE0000};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_3cc(f32 *out) { *out = -2.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_3d0[82] = {0x41700000, 0x3ED55555, 0x19FF1900, 0x19FF1900, 0x19FF1900, 0x00FFFF00, 0x00FFFF00, 0xFFFF0000, 0x43210000, 0x438B0000, 0x43380000, 0x423C0000, 0x43450000, 0x43868000, 0x43350000, 0x43180000, 0x43948000, 0x42090000, 0x42180000, 0x43460000, 0x438A0000, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00006500, 0x00006D00, 0x00008000, 0x00005800, 0x00006900, 0x00007500, 0x00006400, 0x00007400, 0x00006300, 0x00006C00, 0x00005A00, 0x00006E00, 0x00008200, 0x00006B00, 0x00007900, 0x00006800, 0x00006A00, 0x00005900, 0x00006F00, 0x00005700, 0x00007200, 0x00007E00, 0x00007300, 0x00007100, 0x00005B00, 0x00008100, 0x00006200, 0x00007A00, 0x00005D00, 0x00007C00, 0x00005C00, 0x00006100, 0x00006000, 0x00005E00, 0x00007F00, 0x00005F00, 0x00007700, 0x00007000, 0x00007600, 0x00007800, 0x00007D00, 0x00006700, 0x00007B00, 0x00006600, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x3F400000, 0x42140000, 0x42940000, 0x41D00000, 0x428C0000, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x43130000};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_518(f32 *out) { *out = 317.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_51c[39] = {0x42F40000, 0x431C0000, 0x43980000, 0x44160000, 0x3DCCCCD0, 0x3EAE147A, 0xC2CC0000, 0x42CC0000, 0x3F666666, 0x3F28F5C3, 0x42BE0000, 0x42A80000, 0x00230024, 0x00250000, 0xFFFFFF00, 0xFFFF0000, 0xFFF20000, 0x42E80000, 0x41F00000, 0x42080000, 0x43430000, 0x43870000, 0x434A0000, 0x41600000, 0x434C0000, 0x41AC0000, 0x3FC00000, 0x42400000, 0x42EA0000, 0x43260000, 0x437F0000, 0x41E80000, 0x19FF1900, 0x19FF1900, 0x19FF1900, 0xFFFF0000, 0x41D80000, 0x42800000, 0x43000000};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_5b8(f32 *out) { *out = 199.0f; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_5bc[29] = {0x43560000, 0x43420000, 0x43790000, 0x431D0000, 0x438D0000, 0x00000000, 0xC1A00000, 0x00000000, 0x42980000, 0x43650000, 0x43958000, 0x3FAAAAAB, 0x428A0000, 0x42AA0000, 0x439A8000, 0x00000000, 0xC1A00000, 0x00000000, 0x439A0000, 0x00020001, 0xFF000000, 0xFFFFFF00, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0xC2C40000, 0x00000000, 0x40568000, 0x00000000};
const struct fn_3_2AAF4_Color fzgx_pool_black = {0, 0, 0, 0};
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_634(f32 *out) { *out = 56.35000228881836f; }
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_prime_638(f32 *out) { *out = 9.449999809265137f; }
#pragma section code_type ".text"
void fn_3_2AAF4(void) {
    Obj_3_bss_F0 *p_lbl_3_bss_F0;
    struct fn_3_2AAF4_lbl_3_rodata_768 *p_lbl_3_rodata_768;
    s16 *p_lbl_3_bss_20844;
    u8 *p_lbl_1_rodata_26F8;
    f32 v1;
    f32 v2;
    f32 v3;
    f64 v4;
    f32 v5;
    u32 v6;
    f32 v7;
    f32 v8;
    s32 v9;
    s16 v0;
    s32 v10;
    void *v11;
    s32 v12;
    void *v13;
    s32 v14;
    void *v15;
    s32 v16;
    s32 v17;
    u32 v18;
    u32 v19;
    u32 v20;
    u32 v21;
    u32 v22;
    u32 v23;
    u32 v24;
    u32 v25;
    u32 v26;
    f32 v27;
    f32 v28;
    f32 v29;
    f32 v30;
    f32 v31;
    f32 v32;
    f32 v33;
    f32 v34;
    s32 v35;
    u32 v36;
    struct fn_3_2AAF4_Copy88 loc_84;
    struct fn_3_2AAF4_Copy88 loc_28;
    u32 loc_20[3];
    u32 loc_14[3];
    u32 loc_8[3];

    p_lbl_3_bss_F0 = (Obj_3_bss_F0 *)&lbl_3_bss_F0;
    p_lbl_3_rodata_768 = (struct fn_3_2AAF4_lbl_3_rodata_768 *)&lbl_3_rodata_768;
    v0 = p_lbl_3_bss_F0->unk_A;
    loc_84 = *(struct fn_3_2AAF4_Copy88 *)&lbl_1_rodata_26F8;
    v1 = 63.0f;
    v2 = 17.0f;
    loc_84.a[0] = 0xA310;
    FLT(&loc_84, 4) = v1;
    FLT(&loc_84, 8) = v2;
    FLT(&loc_84, 12) = 10.0f;
    fn_1_4F734((FontDrawPacket *)&loc_84);
    fn_3_2A2F8(552, 25, 5, 15, lbl_1_bss_7F0C0.unk_48F8);
    v3 = 317.0f;
    v4 = 4503601774854144.0;
    v27 = 200.0f;
    v28 = 56.35000228881836f;
    v29 = 9.449999809265137f;
    p_lbl_3_bss_20844 = (s16 *)&lbl_3_bss_20844;
    p_lbl_1_rodata_26F8 = (u8 *)&lbl_1_rodata_26F8;
    v5 = 0.5f;
    v6 = 0xA30A;
    v30 = 199.0f;
    v31 = 131.0f;
    v7 = 190.0f;
    v36 = 0xA320;
    v32 = 167.0f;
    v33 = 180.0f;
    v8 = 211.0f;
    v34 = 190.10000610351562f;
    v9 = 0;
    while ((s16)v9 < 3) {
        u32 loc_20[3] = {0xA309, 0xA307, 0xA308};
        u32 loc_14[3] = {0xA31C, 0xA318, 0xA31A};
        u32 loc_8[3] = {0xA31D, 0xA319, 0xA31B};
        v35 = ((s16)lbl_3_bss_20844 == (s16)v9);
        loc_28 = *(struct fn_3_2AAF4_Copy88 *)&lbl_1_rodata_26F8;
        loc_28.a[0] = 0xA31E;
        FLT(&loc_28, 4) = v3;
        FLT(&loc_28, 8) = (s16)(138 + v9 * 98);
        FLT(&loc_28, 12) = v27;
        FLT(&loc_28, 16) *= v28;
        FLT(&loc_28, 20) *= v29;
        loc_28.a[12] = 10;
        if (v35) {
            BYTE(&loc_28, 0x38) = (u8)(40.0f + (f32)(40.0f * lbl_8006D188((s32)(16384.0f + 65536.0f * (f32)(lbl_801A66A8 % 60) / 60.0f))));
            BYTE(&loc_28, 0x39) = (u8)(80.0f + (f32)(80.0f * lbl_8006D188((s32)(16384.0f + 65536.0f * (f32)(lbl_801A66A8 % 60) / 60.0f))));
            BYTE(&loc_28, 0x3A) = (u8)(80.0f + (f32)(80.0f * lbl_8006D188((s32)(16384.0f + 65536.0f * (f32)(lbl_801A66A8 % 60) / 60.0f))));
        } else {
            *(struct fn_3_2AAF4_Color *)&loc_28.a[14] = fzgx_pool_black;
        }
        FLT(&loc_28, 0x2C) = v5;
        fn_1_4F734((FontDrawPacket *)&loc_28);
        loc_28 = *(struct fn_3_2AAF4_Copy88 *)&lbl_1_rodata_26F8;
        loc_28.a[0] = v6;
        FLT(&loc_28, 4) = v3;
        FLT(&loc_28, 8) = (s16)(138 + v9 * 98);
        FLT(&loc_28, 12) = v30;
        loc_28.a[12] = 10;
        fn_1_50A90(&loc_28, 30, 28, 460, 84);
        loc_84 = *(struct fn_3_2AAF4_Copy88 *)&lbl_1_rodata_26F8;
        loc_84.a[0] = v36;
        FLT(&loc_84, 4) = v31;
        FLT(&loc_84, 8) = 112 + v9 * 98;
        FLT(&loc_84, 12) = v7;
        fn_1_50164(72.0f, 54.0f, 8.0f, 8.0f, &loc_84);
        loc_84 = *(struct fn_3_2AAF4_Copy88 *)&lbl_1_rodata_26F8;
        loc_84.a[0] = loc_20[v9];
        FLT(&loc_84, 4) = v32;
        FLT(&loc_84, 8) = 139 + v9 * 98;
        FLT(&loc_84, 12) = v33;
        loc_84.a[12] = 10;
        fn_1_4F734((FontDrawPacket *)&loc_84);
        loc_84 = *(struct fn_3_2AAF4_Copy88 *)&lbl_1_rodata_26F8;
        loc_84.a[0] = loc_14[v9];
        FLT(&loc_84, 4) = v8;
        FLT(&loc_84, 8) = 119 + v9 * 98;
        FLT(&loc_84, 12) = v7;
        fn_1_4F734((FontDrawPacket *)&loc_84);
        loc_84 = *(struct fn_3_2AAF4_Copy88 *)&lbl_1_rodata_26F8;
        loc_84.a[0] = loc_8[v9];
        FLT(&loc_84, 4) = v8;
        FLT(&loc_84, 8) = 119 + v9 * 98;
        FLT(&loc_84, 12) = v34;
        {
            struct fn_3_2AAF4_Color color = {255, 242, 0, 255};
            *(struct fn_3_2AAF4_Color *)&loc_84.a[14] = color;
        }
        FLT(&loc_84, 0x2C) = v5;
        fn_1_4F734((FontDrawPacket *)&loc_84);
        fn_1_49410();
        fn_1_496FC(211.0f, 149 + v9 * 98);
        fn_1_4954C(190.0f);
        switch (p_lbl_3_bss_F0->unk_A) {
        default:
        case 5:
            fn_1_4955C(0.5f, 0.5f);
            break;
        case 0:
            fn_1_49590(0.5f);
            fn_1_4966C(-2.0f, 0.0f);
            fn_1_4955C(0.48627451062202454f, 0.6117647290229797f);
            break;
        }
        switch ((s16)v9) {
        case 0: fn_1_4AE0C((const char *)fn_3_2B750(18, v0)); break;
        case 1: fn_1_4AE0C((const char *)fn_3_2B750(19, v0)); break;
        case 2: fn_1_4AE0C((const char *)fn_3_2B750(20, v0)); break;
        }
        v9++;
    }
    fn_1_133DBC((void *)1);
    fn_1_134AD4();
    fn_1_13ABA8(0x28000000);
}
/* fzgx:end fn_3_2AAF4 */

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

/* fzgx:begin fn_3_2B778 */
#include "font.h"

struct fn_3_2B778_Color { u8 r, g, b, a; };
#pragma pool_data on
#pragma force_active on
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table_0[10] = {
    0x3F333333, 4294967040u, 4294901760u, 4278190080u,
    0x0000FF00, 4294050047u, 4294901760u, 0x3EEAAAAB,
    0x438E0000, 0x43A48000
};
static f32 fzgx_pool_primer_28(void) { return 100.0f; }
static const u32 fzgx_pool_table_2C[27] = {
    0x3F6AAAAB, 0x43B40000, 0x3F0AAAAB, 0x43DC8000,
    0x43A60000, 0x43AC8000, 0x43B30000, 0x3EF99999,
    0x43C58000, 0x43A58000, 0x43B38000, 0x43A00000,
    0x43B50000, 0x43480000, 0x43A18000, 0x43BE8000,
    0x41500000, 0x3C008081, 0x40C00000, 0x40E00000,
    0x3E189899, 0x3E048485, 0x43040000, 0x43160000,
    0x3F4CCCCD, 0x3E99999A, 0x00000000
};
static f32 fzgx_pool_primer_98(s32 x) { return (f32)x; }
static const u32 fzgx_pool_table_A0[56] = {
    0x00004A00, 0x00005400, 0x00003800, 0x00003E00,
    0x00003700, 0x00005500, 0x00003000, 0x00003500,
    0x00003A00, 0x00004000, 0x00004400, 0x00005000,
    0x00003300, 0x00002E00, 0x00003100, 0x00004F00,
    0x00003900, 0x00003D00, 0x00004C00, 0x00003F00,
    0x00004800, 0x00005200, 0x00004500, 0x00005300,
    0x00003C00, 0x00005600, 0x00004300, 0x00004200,
    0x00003200, 0x00002F00, 0x00003400, 0x00003600,
    0x00004D00, 0x00004600, 0x00004100, 0x00005100,
    0x00004E00, 0x00004700, 0x00003B00, 0x00004B00,
    0x00004900, 4294050047u, 4294901760u, 0x43BE0000,
    0x43A70000, 0x3ED00000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x43F00000, 0x44200000, 0x42780000, 0x3FABABAC
};
static f32 fzgx_pool_primer_180(void) { return 8.0f; }
static const u32 fzgx_pool_table_184[2] = {
    0x3E000000, 0x3F800000
};
static f32 fzgx_pool_primer_18C(void) { return 0.5f; }
static const u32 fzgx_pool_table_190[7] = {
    0x43570000, 0x40400000, 0x43340000, 0x42B40000,
    0x43700000, 0x42300000, 0x42B3CCCD
};
static f32 fzgx_pool_primer_1AC(f32 x) { x += 40.0f; x += 16384.0f; x += 65536.0f; x += 60.0f; x += 80.0f; return x; }
static const u32 fzgx_pool_table_1C0[14] = {
    0x43E60000, 0x3F2AAAAB, 0x3F1B9B9C, 3225419776u,
    0x00000000, 0x3F1E9E9F, 0x3F018182, 0x43580000,
    0x3E4CCCCD, 0x430C0000, 0x437A0000, 0x43C80000,
    0x44098000, 0x3EEEEEEF
};
static f32 fzgx_pool_primer_1F8(u32 x) { return (f32)x; }
static const u32 fzgx_pool_table_200[88] = {
    0x00000000, 0x41200000, 3231711232u, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 3204448256u, 0x43360B61, 0x41200000,
    0x00000000, 0x41200000, 3231711232u, 0x00000000,
    0x00000000, 0x00000000, 0x40700000, 0x40600000,
    0x3D4CCCCD, 0x00000000, 0x41200000, 3231711232u,
    0x00000000, 0x00000000, 0x00000000, 0x3E800000,
    0x00000000, 0x41200000, 3231711232u, 0x00000000,
    0x00000000, 0x00000000, 0x40612121, 0x410CB4B5,
    0x4128D8D9, 0x439D8000, 0x40000000, 0x3FA66666,
    0x3F19999A, 0x3F20A0A1, 0x3F40C0C1, 0x40666666,
    0x41100000, 0x00000000, 0x41200000, 3231711232u,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000003, 0x00020001,
    0x00000001, 0x00020003, 0x00000000, 0x40A00000,
    3245342720u, 0x00000000, 0x00000000, 0x00000000,
    0x40A6C6C7, 0x00000000, 0x00000000, 3193493721u,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00FFFF00, 0x00FFFF00,
    0x00FF0000, 0x00FF0000, 0x00FF0000, 0x00FF0000,
    4294901760u, 0x43850000, 0x42F00000, 0x4408C000,
    0x432D0000, 0x41B80000, 0x435F0000, 0x43808000
};
static f32 fzgx_pool_primer_360(void) { return 20.0f; }
static const u32 fzgx_pool_table_364[146] = {
    0x41400000, 0x42878000, 0x40200000, 0x3EB33333,
    0x3E19999A, 0x41300000, 0x41800000, 0x00FFFF00,
    0x00FFFF00, 0x00FF0000, 0x00FF0000, 0x438F0000,
    0x43190000, 0x438A8000, 3264086016u, 0x432C0000,
    0x427C0000, 0x40800000, 0x41C00000, 0x40A00000,
    0x00170018, 0x0019001F, 4294967040u, 4294901760u,
    0x3DCCCCCD, 0x42FE0000, 3221225472u, 0x41700000,
    0x3ED55555, 0x19FF1900, 0x19FF1900, 0x19FF1900,
    0x00FFFF00, 0x00FFFF00, 4294901760u, 0x43210000,
    0x438B0000, 0x43380000, 0x423C0000, 0x43450000,
    0x43868000, 0x43350000, 0x43180000, 0x43948000,
    0x42090000, 0x42180000, 0x43460000, 0x438A0000,
    0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00,
    0x00006500, 0x00006D00, 0x00008000, 0x00005800,
    0x00006900, 0x00007500, 0x00006400, 0x00007400,
    0x00006300, 0x00006C00, 0x00005A00, 0x00006E00,
    0x00008200, 0x00006B00, 0x00007900, 0x00006800,
    0x00006A00, 0x00005900, 0x00006F00, 0x00005700,
    0x00007200, 0x00007E00, 0x00007300, 0x00007100,
    0x00005B00, 0x00008100, 0x00006200, 0x00007A00,
    0x00005D00, 0x00007C00, 0x00005C00, 0x00006100,
    0x00006000, 0x00005E00, 0x00007F00, 0x00005F00,
    0x00007700, 0x00007000, 0x00007600, 0x00007800,
    0x00007D00, 0x00006700, 0x00007B00, 0x00006600,
    0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x3F400000,
    0x42140000, 0x42940000, 0x41D00000, 0x428C0000,
    0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00,
    0x43130000, 0x439E8000, 0x42F40000, 0x431C0000,
    0x43980000, 0x44160000, 0x3DCCCCD0, 0x3EAE147A,
    3268149248u, 0x42CC0000, 0x3F666666, 0x3F28F5C3,
    0x42BE0000, 0x42A80000, 0x00230024, 0x00250000,
    4294967040u, 4294901760u, 4294049792u, 0x42E80000,
    0x41F00000, 0x42080000, 0x43430000, 0x43870000,
    0x434A0000, 0x41600000, 0x434C0000, 0x41AC0000,
    0x3FC00000, 0x42400000, 0x42EA0000, 0x43260000,
    0x437F0000, 0x41E80000, 0x19FF1900, 0x19FF1900,
    0x19FF1900, 4294901760u
};
static f32 fzgx_pool_primer_5AC(void) { return 27.0f; }
static const u32 fzgx_pool_table_5B0[63] = {
    0x42800000, 0x43000000, 0x43470000, 0x43560000,
    0x43420000, 0x43790000, 0x431D0000, 0x438D0000,
    0x00000000, 3248488448u, 0x00000000, 0x42980000,
    0x43650000, 0x43958000, 0x3FAAAAAB, 0x428A0000,
    0x42AA0000, 0x439A8000, 0x00000000, 3248488448u,
    0x00000000, 0x439A0000, 0x00020001, 4278190080u,
    4294967040u, 4294967040u, 0x00FF0000, 4294967040u,
    3267624960u, 0x00000000, 0x40568000, 0x00000000,
    0x00000000, 0x42616667, 0x41173333, 0x0000A309,
    0x0000A307, 0x0000A308, 0x0000A31C, 0x0000A318,
    0x0000A31A, 0x0000A31D, 0x0000A319, 0x0000A31B,
    4294050047u, 0x41880000, 0x43030000, 0x433E0000,
    0x42900000, 0x42580000, 0x43270000, 0x43530000,
    0x433E199A, 0x3EF8F8F9, 0x3F1C9C9D, 4294967295u,
    0x44148000, 0x42F80000, 0x43140000, 0x41C80000,
    0x43960000, 0x3A83126F, 0x00000000
};
static const struct fn_3_2B778_Color fzgx_pool_color_6AC = {0, 0, 0, 0};
static const struct fn_3_2B778_Color fzgx_pool_color_6B0 = {255, 208, 0, 0};
static f32 fzgx_pool_primer_6B4(void) { return 136.0f; }
#pragma section code_type ".text"
#pragma force_active reset

struct fn_3_2B778_lbl_801A66A8 {
    u32 unk_0;
};

extern f32 lbl_8006D188(u32);
extern struct fn_3_2B778_lbl_801A66A8 lbl_801A66A8;
extern u32 fn_1_50A90(void *, u32, u32, u32, u32);
extern u32 lbl_1_rodata_26F8;
extern u8 fn_1_B7C00(void);
extern void fn_1_49410(void);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_495FC(void);
extern void fn_1_4965C(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_50164(f32, f32, f32, f32, void *);

/* Pulsing colour channel: base + base * sin(phase of a 60-frame cycle). */
#define PULSE(base) \
    (u8)((base) + (f32)((base) * lbl_8006D188((s32)(16384.0f + 65536.0f * (f32)(lbl_801A66A8.unk_0 % 60) / 60.0f))))

void fn_3_2B778(s32 x, s32 y, s16 z, s16 idx, s32 selected) {
    s16 sel;
    s16 bx;
    s16 by;
    FontDrawPacket pkt;

    bx = x - 90;
    by = y - 112;
    if (fn_1_B7C00() != 0) {
        return;
    }
    pkt = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    pkt.image = 18;
    pkt.x = (s16)x;
    pkt.y = (s16)y;
    pkt.z = (s16)z;
    pkt.flags = 10;
    if (selected == 1) {
        pkt.color[0] = PULSE(40.0f);
        pkt.color[1] = PULSE(80.0f);
        pkt.color[2] = PULSE(80.0f);
    } else {
        *(struct fn_3_2B778_Color *)pkt.color = fzgx_pool_color_6AC;
    }
    pkt.alpha = 0.5f;
    pkt.scale_x = 20.0f;
    pkt.scale_y = 27.0f;
    fn_1_4F734(&pkt);

    {
    s16 zz;
    pkt = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    zz = z;
    pkt.image = 0xA109;
    pkt.x = (s16)x;
    pkt.y = (s16)y;
    pkt.z = zz - 1;
    pkt.flags = 10;
    fn_1_50A90(&pkt, 30, 28, 180, 224);

    pkt = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    sel = idx;
    switch (sel) {
    case 0:
        pkt.image = 0x8506;
        break;
    case 1:
        pkt.image = 0x8504;
        break;
    case 2:
        pkt.image = 0x8508;
        break;
    default:
        pkt.image = 0x8506;
        break;
    }
    pkt.x = bx + 90;
    pkt.y = by + 53;
    pkt.z = zz - 3;
    pkt.flags = 10;
    fn_1_4F734(&pkt);

    pkt = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    switch (sel) {
    case 0:
        pkt.image = 0x8507;
        break;
    case 1:
        pkt.image = 0x8505;
        break;
    case 2:
        pkt.image = 0x8509;
        break;
    default:
        pkt.image = 0x8507;
        break;
    }
    pkt.x = bx + 90;
    pkt.y = by + 53;
    pkt.z = zz - 2;
    *(struct fn_3_2B778_Color *)pkt.color = fzgx_pool_color_6B0;
    pkt.flags = 10;
    pkt.alpha = 0.5f;
    fn_1_4F734(&pkt);

    if (lbl_3_bss_F0.unk_A == 5) {
        fn_1_49410();
        fn_1_495FC();
        fn_1_495B0(0x80000000);
        fn_1_4965C(2);
        fn_1_495C8(9);
        fn_1_4955C(0.5f, 0.5f);
        fn_1_496FC(bx + 90, by + 92);
        fn_1_4954C(zz - 2);
        switch (sel) {
        case 0:
            fn_1_4AE0C((const char *)(&lbl_3_data_4648.unk_0)[276 + lbl_3_bss_F0.unk_A]);
            break;
        case 1:
            fn_1_4AE0C((const char *)(&lbl_3_data_4648.unk_0)[282 + lbl_3_bss_F0.unk_A]);
            break;
        case 2:
            fn_1_4AE0C((const char *)(&lbl_3_data_4648.unk_0)[288 + lbl_3_bss_F0.unk_A]);
            break;
        default:
            fn_1_4AE0C((const char *)(&lbl_3_data_4648.unk_0)[276 + lbl_3_bss_F0.unk_A]);
            break;
        }
    }

    pkt = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    switch (sel) {
    case 0:
        pkt.image = 0x8501;
        break;
    case 1:
        pkt.image = 0x8500;
        break;
    case 2:
        pkt.image = 0x8502;
        break;
    default:
        pkt.image = 0x8501;
        break;
    }
    pkt.x = bx + 90;
    pkt.y = by + 154;
    pkt.z = zz - 3;
    pkt.flags = 10;
    fn_1_4F734(&pkt);

    pkt = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    pkt.image = 12;
    pkt.x = bx + 90;
    pkt.y = by + 154;
    pkt.z = zz - 2;
    pkt.flags = 10;
    fn_1_50164(136.0f, 100.0f, 8.0f, 8.0f, &pkt);
    }
}
/* fzgx:end fn_3_2B778 */

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

/* fzgx:begin fn_3_2C290 noprologue */
#include "types.h"
#include "types.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/shadowmap.h"
#include "psvec.h"

/* begin game/vec3.h (deltawave784/fzgx, CC0) */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,
// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,
// stcoli). Hand-owned (librarian).


typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

#endif  // GAME_VEC3_H

/* end game/vec3.h */
/* begin game/main_rel/shadowmap_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_SHADOWMAP_TYPES_H
#define GAME_MAIN_REL_SHADOWMAP_TYPES_H

// Types (and the externs that name them) of shadowmap.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct fn_1_568F8_Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_1_568F8_Color;

typedef struct fn_1_568F8_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} fn_1_568F8_Vec3;

typedef struct fn_1_568F8_Pool {
    fn_1_568F8_Color tev_color;  // 0x00
    f32 zero;                    // 0x04
    fn_1_568F8_Vec3 axis_x;      // 0x08
    fn_1_568F8_Vec3 axis_y;      // 0x14
    fn_1_568F8_Vec3 axis_z;      // 0x20
    fn_1_568F8_Vec3 up;          // 0x2c
    fn_1_568F8_Color clear_color;  // 0x38
    fn_1_568F8_Color chan_color;   // 0x3c
    f32 neg_three;               // 0x40
    f32 one;                     // 0x44
    f32 twenty;                  // 0x48
    f32 three;                   // 0x4c
    f32 hundred;                 // 0x50
    f32 size;                    // 0x54
} fn_1_568F8_Pool;

typedef struct fn_1_568F8_Data {
    u8 pad_0[0x38c];
    u8 light_mask;               // 0x38c
    u8 pad_38d[0x2b];
    s16 light_param;             // 0x3b8
} fn_1_568F8_Data;

typedef struct fn_1_568F8_Mtx44 {
    f32 m[4][4];
} fn_1_568F8_Mtx44;

extern fn_1_568F8_Pool lbl_1_rodata_28B0;
extern void fn_1_870BC(fn_1_568F8_Data *, s8, fn_1_568F8_Data *, s32, u8, f32);
extern void C_MTXOrtho(fn_1_568F8_Mtx44 *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(fn_1_568F8_Mtx44 *, s32);
extern void fn_800744F8(fn_1_568F8_Color, u32);
extern void fn_800725DC(fn_1_568F8_Color);
extern void fn_80072614(fn_1_568F8_Color);

#endif  // GAME_MAIN_REL_SHADOWMAP_TYPES_H

/* end game/main_rel/shadowmap_types.h */

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
}
static const unsigned long fzgx_pool_table2[6] = {0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0x0000FF00, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table6[43] = {0x00004A00, 0x00005400, 0x00003800, 0x00003E00, 0x00003700, 0x00005500, 0x00003000, 0x00003500, 0x00003A00, 0x00004000, 0x00004400, 0x00005000, 0x00003300, 0x00002E00, 0x00003100, 0x00004F00, 0x00003900, 0x00003D00, 0x00004C00, 0x00003F00, 0x00004800, 0x00005200, 0x00004500, 0x00005300, 0x00003C00, 0x00005600, 0x00004300, 0x00004200, 0x00003200, 0x00002F00, 0x00003400, 0x00003600, 0x00004D00, 0x00004600, 0x00004100, 0x00005100, 0x00004E00, 0x00004700, 0x00003B00, 0x00004B00, 0x00004900, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 380.0f;
    s = 334.0f;
    s = 0.40625f;
}
static const unsigned long fzgx_pool_table8[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
static const unsigned long fzgx_pool_table10[9] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 182.04444885253906f;
    s = 10.0f;
}
static const unsigned long fzgx_pool_table12[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.75f;
    s = 3.5f;
    s = 0.05000000074505806f;
}
static const unsigned long fzgx_pool_table14[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.25f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
static const unsigned long fzgx_pool_table18[2] = {0x00000000, 0x41200000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -5.0f;
}
static const unsigned long fzgx_pool_table20[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003, 0x00020001, 0x00000001, 0x00020003, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.211764812469482f;
}
static const unsigned long fzgx_pool_table22[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.21176470816135406f;
}
static const unsigned long fzgx_pool_table24[13] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00FFFF00, 0x00FFFF00, 0x00FF0000, 0x00FF0000, 0x00FF0000, 0x00FF0000, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const unsigned long *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
static const unsigned long fzgx_pool_table26[4] = {0x00FFFF00, 0x00FFFF00, 0x00FF0000, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const unsigned long *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
static const unsigned long fzgx_pool_table28[4] = {0x00170018, 0x0019001F, 0xFFFFFF00, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const unsigned long *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 127.0f;
    s = -2.0f;
    s = 15.0f;
    s = 0.4166666567325592f;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} fn_3_2C290_Vec;

typedef struct {
    u32 unk_0[3];
    f32 x;
    f32 y;
    f32 z;
    u32 unk_18[7];
} fn_3_2C290_Light;

typedef struct {
    u8 pad_0[0x34];
    s16 unk_34;
    u8 pad_36[2];
    fn_3_2C290_Vec unk_38;
    fn_3_2C290_Vec unk_44;
} fn_3_2C290_State;

typedef struct {
    u32 flags;
    u8 pad_4[0x1C];
} fn_3_2C290_Entry;

typedef struct {
    u8 pad_0[0x18];
    u16 count;
    u8 pad_1A[0x26];
    fn_3_2C290_Entry entries[1];
} fn_3_2C290_Model;

typedef struct {
    u8 pad_0[0x8];
    fn_3_2C290_Model **model;
} fn_3_2C290_Holder;

typedef struct {
    u8 pad_0[0xC];
    fn_3_2C290_Holder *holder;
} fn_3_2C290_Bss38460;

typedef struct {
    u8 pad_0[0x60];
    u8 unk_60[0xC];
    f32 unk_6C;
} fn_3_2C290_Fx;

typedef struct {
    u8 pad_0[0x390];
    u32 flags;
    u8 pad_394[0xC];
    u32 unk_3A0;
} fn_3_2C290_Racer;

typedef struct {
    fn_3_2C290_Racer *racer;
} fn_3_2C290_Arg;

typedef struct {
    f32 m[3][4];
} fn_3_2C290_Mtx;

extern fn_3_2C290_Light lbl_1_data_1E5C0;
extern fn_3_2C290_Bss38460 lbl_1_bss_38460;
extern u32 lbl_801A66A0;
extern fn_3_2C290_Fx *lbl_801A6D00;

extern void fn_8006F038(fn_3_2C290_Vec *, fn_3_2C290_Vec *, s16);
extern void lbl_8006DCDC(void);
extern void fn_1_F7870(fn_3_2C290_Light *);
extern f32 lbl_8006D188(s16);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0A4(fn_3_2C290_Vec *);
extern void mathutil_mtxA_rotate_y(s16);
extern void fn_80077B04(f32);
extern u32 fn_1_56018(s32);
extern void lbl_8006D784(void *);
extern void fn_1_560F0(s32, void *);
extern void fn_80072558(void);
extern void fn_1_55210(fn_3_2C290_Model *);
extern void lbl_8006DB74(fn_3_2C290_Mtx *);
extern void fn_1_14E2DC(u32, u32, f32);
extern void lbl_8006DBAC(fn_3_2C290_Mtx *);
extern void fn_1_FCFA4(void *);
extern void fn_1_870BC(fn_1_568F8_Data *, s8, fn_1_568F8_Data *, s32, u8, f32);

#pragma opt_propagation off
extern const f32 lbl_3_rodata_A68;
static inline void fn_3_2C290_place(fn_3_2C290_Vec *pos) {
    f32 angle;
    s32 deg;

    deg = 0;
    pos->y = 0.0f;
    angle = 182.04445f * (f32)(s16)(deg % 360);
    {
        f32 radius;
        f32 sine = lbl_8006D188(angle);
        radius = 5.2117648f;
        radius = -radius;
        pos->x = radius * sine;
        pos->z = radius * lbl_8006D188((s32)angle + 0x4000);
    }
    lbl_8006DCA4();
    pos->y -= 0.5f;
    lbl_8006E0A4(pos);
}



/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_3_bss_A2460[2];
u32 fzgx_obj_lbl_3_bss_A2468[9];
u32 fzgx_obj_lbl_3_bss_A248C[2];
s16 lbl_3_bss_A248C__fzgx_offset_8;
u16 lbl_3_bss_A248C__fzgx_offset_A;
fn_3_2C290_Vec lbl_3_bss_A248C__fzgx_offset_C;
fn_3_2C290_Vec lbl_3_bss_A248C__fzgx_offset_18;
u32 lbl_3_bss_A248C__fzgx_offset_24;
u16 lbl_3_bss_A248C__fzgx_offset_28;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_A2460;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_A2468;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_A248C;
    s = *(u8 *)&lbl_3_bss_A248C__fzgx_offset_8;
    s = *(u8 *)&lbl_3_bss_A248C__fzgx_offset_A;
    s = *(u8 *)&lbl_3_bss_A248C__fzgx_offset_C;
    s = *(u8 *)&lbl_3_bss_A248C__fzgx_offset_18;
    s = *(u8 *)&lbl_3_bss_A248C__fzgx_offset_24;
    s = *(u8 *)&lbl_3_bss_A248C__fzgx_offset_28;
}
#pragma section code_type ".text"

static inline fn_3_2C290_Entry *fn_3_2C290_array_read(fn_3_2C290_Entry *array) { return array; }
#pragma opt_dead_assignments off
void fn_3_2C290(fn_3_2C290_Arg *arg0) {
    fn_3_2C290_Mtx mtx;
    fn_3_2C290_Entry *entry;
    fn_3_2C290_Model *model;
    s16 i;
    fn_3_2C290_Vec pos;
    f32 angle;
    f32 factor;
    f32 sourceX;
    f32 a;
    f32 b;
    s32 fade;
    fn_3_2C290_Racer *racer;

    racer = arg0->racer;
    fn_8006F038(&lbl_3_bss_A248C__fzgx_offset_C, &lbl_3_bss_A248C__fzgx_offset_18, 0);
    lbl_8006DCDC();

{
    fn_3_2C290_Light light;
    /* rotate the light direction by 45 degrees */
    light = lbl_1_data_1E5C0;
    {
        factor = 0.7f;
        sourceX = lbl_1_data_1E5C0.x;
        a = sourceX * factor;
        b = lbl_1_data_1E5C0.y * factor;
    }
    light.x = a - b;
    light.y = a + b;
    light.z = lbl_1_data_1E5C0.z;
    fn_1_F7870(&light);
}

    fn_3_2C290_place(&pos);
    mathutil_mtxA_rotate_y(182.04445f * (f32)(u32)(360 - lbl_801A66A0 % 360));

    fade = -lbl_3_bss_A248C__fzgx_offset_8;
    fade = (fade < 0) ? 0 : ((fade > 15) ? 15 : fade);
    fn_80077B04(1.0f - (f32)fade / 15.0f);

    if (lbl_3_bss_A248C__fzgx_offset_8 >= -1) {
        model = *lbl_1_bss_38460.holder->model;
        entry = model->entries;
        for (i = 0; i < model->count; i++, entry++) {
            if (entry->flags & 0x20000) {
                fn_1_56018(1);
                lbl_8006D784(lbl_801A6D00->unk_60);
                lbl_801A6D00->unk_6C = 1.0f - lbl_8006D188((s32)(182.04445f * (f32)(lbl_801A66A0 % 180)) + 0x4000);
                fn_1_560F0(0, lbl_801A6D00->unk_60);
            }
        }
        fn_80072558();
        fn_1_55210(model);
    }

    fn_80077B04(1.0f);
    lbl_8006DCA4();
    lbl_8006E0A4(&pos);
    if (racer->flags & 0x04000000) {
        mathutil_mtxA_rotate_y(182.04445f * (f32)(lbl_801A66A0 % 360));
        lbl_8006DB74(&mtx);
        fn_1_14E2DC(racer->unk_3A0, 0, 1.0f);
        lbl_8006DBAC(&mtx);
        fn_1_FCFA4(arg0);
    } else {
        mathutil_mtxA_rotate_y(182.04445f * (f32)(lbl_801A66A0 % 360));
        fn_1_870BC((fn_1_568F8_Data *)racer, 0, (fn_1_568F8_Data *)racer, 0, 4, 1.0f);
        fn_1_FCFA4(arg0);
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_3_2C290 */
