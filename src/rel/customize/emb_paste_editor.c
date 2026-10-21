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

/* fzgx:begin fn_3_104C4 noprologue */
#include "types.h"
#include "rel/customize/emb_paste_editor.h"

struct InputEntry { u16 unk_0; u8 pad_2[0x12]; };
struct InputState {
 union {
  struct { u8 pad8[8]; struct InputEntry unk_8[1]; };
  struct { u8 pad10[0x10]; struct InputEntry unk_10[1]; };
  struct { u8 pad12[0x12]; struct InputEntry unk_12[1]; };
 };
};
extern struct InputState lbl_1_bss_9F8;
extern void fn_1_A2D84(u32);
extern void fn_80008BEC(void *, int, u32);
#pragma opt_pointer_analysis on
static inline struct InputEntry *array_read(struct InputEntry *array) { return array; }
static inline void finish(Obj_3_bss_7EDD8 *q, u32 state) {
 q->unk_10 = q->unk_C;
 q->unk_C = state;
 lbl_3_bss_7EDD8.unk_18 = 0;
}
void fn_3_104C4(void) {
 Obj_3_bss_7EDD8 *p;
 u16 v;
 u32 index;
 u32 slot;
 u32 previous;
 u32 state;
 p = (Obj_3_bss_7EDD8 *)&lbl_3_bss_7EDD8;
 if ((array_read(lbl_1_bss_9F8.unk_12)[index = p->unk_14].unk_0 & 1) ||
     (lbl_1_bss_9F8.unk_10[index].unk_0 & 1)) {
  if ((s32)lbl_3_bss_7EDD8.unk_18 == 0) fn_1_A2D84(0xA9010000);
  lbl_3_bss_7EDD8.unk_18 = 1;
 }
 if (((array_read(lbl_1_bss_9F8.unk_12)[index = p->unk_14].unk_0 >> 1) & 1) ||
     ((lbl_1_bss_9F8.unk_10[index].unk_0 >> 1) & 1)) {
  if ((s32)lbl_3_bss_7EDD8.unk_18 == 1) fn_1_A2D84(0xA9010000);
  lbl_3_bss_7EDD8.unk_18 = 0;
 }
 v = lbl_1_bss_9F8.unk_8[*(volatile u8 *)&p->unk_14].unk_0; /* Retail reloads the input selector. */
 if (((v >> 9) & 1) || (((v >> 8) & 1) && (s32)lbl_3_bss_7EDD8.unk_18 == 0)) {
  if ((lbl_1_bss_9F8.unk_8[*(volatile u8 *)&p->unk_14].unk_0 >> 8) & 1) /* Retail reloads the input selector. */
   fn_1_A2D84(0xA9010100);
  else fn_1_A2D84(0xA9010200);
  lbl_3_bss_7EDD8.unk_18 = 0;
  lbl_3_bss_7EDD8.unk_C = 0x40000000;
 }
 if (((lbl_1_bss_9F8.unk_8[*(volatile u8 *)&p->unk_14].unk_0 >> 8) & 1) && (s32)lbl_3_bss_7EDD8.unk_18 != 0) { /* Retail reloads the input selector. */
  fn_1_A2D84(0xA9010100);
  slot = (u32)&lbl_3_bss_7EE40;
  index = lbl_3_bss_7EDD8.unk_15;
  slot += index * 0x2060;
  if (((Obj_3_bss_7EE40 *)slot)->unk_24 & 0x80000000)
   *((u32 *)&lbl_3_bss_7EDD8.unk_2C + index) = 1;
  fn_80008BEC((u8 *)&lbl_3_bss_7EE40 + lbl_3_bss_7EDD8.unk_15 * 0x2060 + 0x20, 0, 0x2060);
  fn_80008BEC((u8 *)&lbl_3_bss_87040 + lbl_3_bss_7EDD8.unk_15 * 0x2060 + 0x20, 0, 0x2060);
  finish(&lbl_3_bss_7EDD8, 0x40000000);
 }
}
#pragma opt_pointer_analysis reset
/* fzgx:end fn_3_104C4 */

/* fzgx:begin fn_3_10B68 noprologue */
#include "types.h"

struct fn_3_10B68_lbl_1_bss_9F8_12_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};
struct fn_3_10B68_lbl_1_bss_9F8_8_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};
struct fn_3_10B68_lbl_3_bss_7EDD8 {
    u8 pad_0[0x14];
    u8 unk_14;
    u8 unk_15;
    u8 pad_16[0x2];
    u32 unk_18;
};
struct fn_3_10B68_lbl_1_bss_9F8 {
    union {
        struct { u8 pad_view_unk_8[0x8]; struct fn_3_10B68_lbl_1_bss_9F8_8_E20 unk_8[1]; };
        struct { u8 pad_view_unk_12[0x12]; struct fn_3_10B68_lbl_1_bss_9F8_12_E20 unk_12[1]; };
    };
};

extern struct fn_3_10B68_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern struct fn_3_10B68_lbl_3_bss_7EDD8 lbl_3_bss_7EDD8;
extern void fn_1_A2D84(u32);

#pragma opt_pointer_analysis on
static inline struct fn_3_10B68_lbl_1_bss_9F8_12_E20 *fn_3_10B68_array_read(struct fn_3_10B68_lbl_1_bss_9F8_12_E20 *array) { return array; }
void fn_3_10B68(void) {
    struct fn_3_10B68_lbl_3_bss_7EDD8 *p_lbl_3_bss_7EDD8;
    u16 v0;
    void * v1;
    p_lbl_3_bss_7EDD8 = (struct fn_3_10B68_lbl_3_bss_7EDD8 *)&lbl_3_bss_7EDD8;
    if ((fn_3_10B68_array_read(lbl_1_bss_9F8.unk_12)[(*(u8 volatile *)&(p_lbl_3_bss_7EDD8->unk_14)) /* Retail reloads this field. */].unk_0 & 0x1) != 0) {
    p_lbl_3_bss_7EDD8->unk_18 = 1;
    fn_1_A2D84(0xA9010000);
    }
    if (((fn_3_10B68_array_read(lbl_1_bss_9F8.unk_12)[(*(u8 volatile *)&(p_lbl_3_bss_7EDD8->unk_14)) /* Retail reloads this field. */].unk_0 >> 1) & 0x1) != 0) {
    lbl_3_bss_7EDD8.unk_18 = 0;
    fn_1_A2D84(0xA9010000);
    }
    v0 = lbl_1_bss_9F8.unk_8[(*(u8 volatile *)&(p_lbl_3_bss_7EDD8->unk_14)) /* Retail reloads this field. */].unk_0;
    if (((v0 >> 9) & 0x1) != 0 || (((v0 >> 8) & 0x1) != 0 && (s32)lbl_3_bss_7EDD8.unk_18 == 0)) {
    if (((lbl_1_bss_9F8.unk_8[(*(u8 volatile *)&(p_lbl_3_bss_7EDD8->unk_14)) /* Retail reloads this field. */].unk_0 >> 8) & 0x1) != 0) {
    fn_1_A2D84((0xA9010000 + 256));
    } else {
    fn_1_A2D84((0xA9010000 + 512));
    }
    v1 = (void *)(((u8 *)&lbl_3_bss_7EDD8 + (lbl_3_bss_7EDD8.unk_15 << 2)));
    *(u32 *)((u8 *)v1 + 44) = 0;
    } else {
    if ((((*(((*(u8 volatile *)&(p_lbl_3_bss_7EDD8->unk_14)) /* Retail reloads this field. */) + (lbl_1_bss_9F8.unk_8))).unk_0 >> 8) & 0x1) != 0 && (s32)lbl_3_bss_7EDD8.unk_18 != 0) {
    fn_1_A2D84((0xA9010000 + 256));
    }
    }
}
#pragma opt_pointer_analysis reset
/* fzgx:end fn_3_10B68 */

/* fzgx:begin fn_3_1180C */
struct Fn3State {
    u8 pad0[4];
    u32 value;
    u8 pad8[2];
    s16 field_a;
    u8 pad_c[0x18];
    s16 mode;
};

void fn_3_1180C(void) {
    if ((*(struct Fn3State *)&lbl_3_bss_7EDD8).mode == 0xf) {
        fn_1_4A00(0, 0xf, (*(struct Fn3State *)&lbl_3_bss_7EDD8).value);
    } else if ((*(struct Fn3State *)&lbl_3_bss_7EDD8).mode == 0) {
        fn_1_FDFF4();
        if ((*(s16 (*)[2])&lbl_3_data_1A40)[0] != -1) {
            fn_1_435C((*(struct Fn3State *)&lbl_3_bss_7EDD8).value);
            fn_1_426C((*(struct Fn3State *)&lbl_3_bss_7EDD8).field_a);
            (*(struct Fn3State *)&lbl_3_bss_7EDD8).field_a = -1;
            lbl_1_bss_96A = (*(s16 (*)[2])&lbl_3_data_1A40)[0];
            (*(s16 (*)[2])&lbl_3_data_1A40)[0] = -1;
        } else {
            (*(s16 (*)[2])&lbl_3_data_1A40)[0] = 0x5f;
        }
    }
}
/* fzgx:end fn_3_1180C */

/* fzgx:begin fn_3_118BC */
extern u32 fn_3_11A38(void);
extern void fn_1_A2D84(u32);

extern u16 lbl_1_bss_9F8[];

static inline u16 *fn_3_118BC_array_read(u16 *array) { return array; }
#pragma opt_propagation off
void fn_3_118BC(void) {
    u16 *p;
    u32 v;

    fn_3_11A38();
    p = lbl_1_bss_9F8;
    p += 4;
    v = fn_3_118BC_array_read(p)[lbl_3_bss_7EDD8.unk_14 * 10];
    if (((v >> 4) & 1) || ((v >> 9) & 1)) {
        fn_1_A2D84(0xa9010200);
        lbl_3_bss_7EDD8.unk_C = lbl_3_bss_7EDD8.unk_10;
        lbl_3_bss_7EDD8.unk_10 = 0x1000000;
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_3_118BC */

/* fzgx:begin fn_3_11930 */
struct PasteEntry {
    u8 pad[0x2c];
    int active;
};

int fn_3_11930(void) {
    u8 i;
    u8 * base;

    for (i = 0; i < 4; i++) {
        struct PasteEntry *entry = (struct PasteEntry *)(((u8 *)(*(u16 (*)[52])&lbl_3_bss_7EDD8)) + i * 4);
        if (entry->active != 0) {
            return 1;
        }
    }
    return 0;
}
/* fzgx:end fn_3_11930 */

/* fzgx:begin fn_3_11974 */
void fn_3_11974(void) {
    u32 *fields = (u32 *)&(*(u16 (*)[52])&lbl_3_bss_7EDD8);
    fields[11] = 0;
    fields[12] = 0;
    fields[13] = 0;
    fields[14] = 0;
}
/* fzgx:end fn_3_11974 */

/* fzgx:begin fn_3_11994 */
struct Sig_fn_8004E278_fn_8004E278_Arg0 {
    u32 unk_0;
};

void fn_3_11994(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg_sp0) {
    s32 temp_r5;
    u8 var_r30;
    void *temp_r4;

    var_r30 = 0;
    while (var_r30 < 4U) {
        if (arg0 != (s32) var_r30) {
            temp_r5 = var_r30 * 0x2060;
            temp_r4 = (void *)(arg2 + temp_r5);
            if (arg1 == (s16) (*(s16 *)((u8 *)(temp_r4) + 0))) {
                if ((*(s32 *)((u8 *)(temp_r4) + 4)) & 0x80000000) {
                    fn_80008BA8((struct Sig_fn_8004E278_fn_8004E278_Arg0 *)(arg3 + temp_r5), (u32)(temp_r4), 0x2060U);
                }
            } else {
                fn_80008BEC((struct Sig_fn_8004E278_fn_8004E278_Arg0 *)(arg3 + temp_r5), 0, 0x2060U);
            }
        }
        var_r30 += 1;
            }
}
/* fzgx:end fn_3_11994 */

/* fzgx:begin fn_3_11F60 */
struct Fn3State {
    u32 value0;
    u32 value1;
};

void fn_3_11F60(u32 value0, u32 value1) {
    (*(struct Fn3State *)&lbl_3_bss_7EDD8).value1 = value1;
    (*(struct Fn3State *)&lbl_3_bss_7EDD8).value0 = value0;
    fn_1_FC414(lbl_3_bss_8F200, 1);
}
/* fzgx:end fn_3_11F60 */

/* fzgx:begin fn_3_11FA0 */
void fn_3_11FA0(void) {
    (*(u32 (*)[26])&lbl_3_bss_7EDD8)[0] = 0;
    (*(u32 (*)[26])&lbl_3_bss_7EDD8)[1] = 0;
}
/* fzgx:end fn_3_11FA0 */

/* fzgx:begin fn_3_11FB4 */
void fn_3_11FB4(u8 value_47, u8 value_46, u32 value_7EDC0) {
    (*(u8 (*)[0x68])&lbl_3_bss_7EDD8)[0x47] = value_47;
    (*(u32 (*)[3])&lbl_3_bss_7EDC0)[0] = value_7EDC0;
    (*(u8 (*)[0x68])&lbl_3_bss_7EDD8)[0x46] = value_46;
}
/* fzgx:end fn_3_11FB4 */

/* fzgx:begin fn_3_1304C */
// fn_3_1304C: empty in retail (single blr).
void fn_3_1304C(void) {
}
/* fzgx:end fn_3_1304C */

/* fzgx:begin fn_3_13050 */
// fn_3_13050: empty in retail (single blr).
void fn_3_13050(void) {
}
/* fzgx:end fn_3_13050 */

/* fzgx:begin fn_3_13054 */
// fn_3_13054: empty in retail (single blr).
void fn_3_13054(void) {
}
/* fzgx:end fn_3_13054 */

/* fzgx:begin fn_3_13058 */
// fn_3_13058: empty in retail (single blr).
void fn_3_13058(void) {
}
/* fzgx:end fn_3_13058 */

/* fzgx:begin fn_3_1305C */
// fn_3_1305C: empty in retail (single blr).
void fn_3_1305C(void) {
}
/* fzgx:end fn_3_1305C */

/* fzgx:begin fn_3_13060 */
// fn_3_13060: empty in retail (single blr).
void fn_3_13060(void) {
}
/* fzgx:end fn_3_13060 */

/* fzgx:begin fn_3_13064 */
// fn_3_13064: empty in retail (single blr).
void fn_3_13064(void) {
}
/* fzgx:end fn_3_13064 */

/* fzgx:begin fn_3_13068 */
// fn_3_13068: empty in retail (single blr).
void fn_3_13068(void) {
}
/* fzgx:end fn_3_13068 */

/* fzgx:begin fn_3_1306C */
// fn_3_1306C: empty in retail (single blr).
void fn_3_1306C(void) {
}
/* fzgx:end fn_3_1306C */

/* fzgx:begin fn_3_13070 */
// fn_3_13070: empty in retail (single blr).
void fn_3_13070(void) {
}
/* fzgx:end fn_3_13070 */

/* fzgx:begin fn_3_13074 */
// fn_3_13074: empty in retail (single blr).
void fn_3_13074(void) {
}
/* fzgx:end fn_3_13074 */

/* fzgx:begin fn_3_13078 */
// fn_3_13078: empty in retail (single blr).
void fn_3_13078(void) {
}
/* fzgx:end fn_3_13078 */

/* fzgx:begin fn_3_1307C */
u8 fn_3_1307C(void) {
    return lbl_3_bss_A1778[0];
}
/* fzgx:end fn_3_1307C */

/* fzgx:begin fn_3_1308C */
typedef struct {
    u8 pad0[4];
    u32 unk4;
    u8 pad8[0xc];
    u32 unk14;
    u32 unk18;
    u32 unk1c;
} Fn3BssA1768;



void fn_3_1308C(u32 arg0, u32 arg1, u32 arg2) {
    (*(Fn3BssA1768 *)&lbl_3_bss_A1768).unk14 = arg1;
    (*(Fn3BssA1768 *)&lbl_3_bss_A1768).unk18 = arg2;
    (*(Fn3BssA1768 *)&lbl_3_bss_A1768).unk4 = arg0;
    (*(Fn3BssA1768 *)&lbl_3_bss_A1768).unk1c = arg0;
}
/* fzgx:end fn_3_1308C */

/* fzgx:begin fn_3_130A8 */
typedef struct {
    u32 value0;
    u8 pad[0x10];
    u32 value14;
    u32 value18;
    u32 value1c;
} CustomizeState;



void fn_3_130A8(void) {
    CustomizeState *state = (CustomizeState *)&lbl_3_bss_A1768;

    state->value14 = 0;
    state->value18 = 0;
    state->value0 = 0;
    state->value1c = 0;
}
/* fzgx:end fn_3_130A8 */

/* fzgx:begin fn_3_139F0 */
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
