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
extern struct fn_3_1A1D8_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern u32 lbl_3_rodata_744[9];
extern void fn_3_15240(void *, s32, s16, u16, s32, s16);

/* fzgx:begin fn_3_1857C noprologue */
#include "types.h"
#include "rel/customize/toolkit.h"

extern u32 lbl_801A6410;
extern s32 fn_1_45D0();

Obj_3_bss_A2438 lbl_3_bss_A2438;
u32 lbl_3_bss_A2454;
u8 lbl_3_bss_A2458;

static inline void InitCustomizeState(Obj_3_bss_A2438 *p) {
    p->unk_4 = 0x80000000;
    p->unk_C = 2;
    p->unk_12 = 0;
    p->unk_14 = 0;
    p->unk_15 = 0;
    p->unk_D = 0;
    p->unk_E = 0;
    p->unk_F = 0;
    p->unk_10 = 0;
    p->unk_18 = 0;
    p->unk_1A = 0;
}

void fn_3_1857C(void) {
    InitCustomizeState(&lbl_3_bss_A2438);
    lbl_3_bss_A2438.unk_0 = 0;
    lbl_3_bss_A2454 = fn_1_45D0(lbl_801A6410, 0x2000, lbl_3_data_3D14, 0x8C);
    lbl_3_bss_A2458 = 1;
}
/* fzgx:end fn_3_1857C */

/* fzgx:begin fn_3_18614 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/editor.h"
#include "font.h"

typedef struct { u32 c; } Col4;

struct fn_3_156D0_Obj {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    s16 unk_12;
    u8 pad_14[8];
    u8 unk_1C;
    u8 pad_1D[3];
    void *unk_20;
};

typedef struct {
    u32 type;
    f32 x;
    f32 y;
    f32 z;
    f32 a;
    f32 b;
    u8 pad18[0x18];
    u32 mode;
    u8 pad34[8];
    u32 color;
    u8 pad40[0x18];
} Packet16E14;

struct fn_3_1552C_Obj {
    u8 pad[0x10];
    u16 width;
    u16 height;
};

typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} PadInput;

struct Obj {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    s16 unk_12;
    u8 pad_14[8];
    u8 unk_1C;
    u8 pad_1D[3];
    void *unk_20;
};
extern u8 *fn_3_14074(void);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u8 fn_3_19C94(void);
extern void fn_3_169B8(void);
extern u32 fn_3_17820(void);
extern void fn_3_1445C(void);
extern s32 fn_3_14600(void);
extern void fn_3_19F7C();
extern void fn_3_17830(void);
extern void fn_3_177AC(void *);
extern void fn_3_16FD0(u32 arg0);
extern void fn_3_19CA4(void);
extern void fn_3_19CCC(void);
extern void DCInvalidateRange(void *, u32);
extern void DCStoreRange(void *, u32);
extern void fn_1_A2D84(u32 arg0);
extern PadInput lbl_1_bss_9F8[];
extern u8 lbl_3_bss_A2408[8];
extern s32 fn_1_45D0();
extern u32 lbl_801A6410;
extern void fn_3_19CB8(void);
extern void fn_3_15620(void);
extern void fn_3_1560C(void);
extern const Col4 lbl_3_rodata_5B8;
extern const Col4 lbl_3_rodata_5BC;
extern s32 fn_1_A5DC4(void);
extern void fn_1_A9868();
extern u32 fn_1_A9FFC(s16, s16, s16, s16, void *);
extern void fn_1_AA538(void);
extern void fn_1_4E0F4(void);
extern const Packet16E14 lbl_1_rodata_26F8;
extern u8 lbl_3_rodata_538[];
extern Col4 lbl_3_rodata_5EC;
extern u32 fn_3_14794(u32, s16, s16, void *);
extern void fn_3_17100(void);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern const f32 lbl_3_rodata_5FC[3];

typedef struct {
    u32 flags;
    u8 pad_4[0x18];
    u8 unk_1C;
} EditorObj;

typedef struct {
    u8 unk_0;
    u8 pad_1[0x3];
    u32 unk_4;
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
    u8 unk_10;
} EditorState;


typedef struct {
    u16 unk_0;
    u8 pad_2[0xE];
} MenuEntry;

typedef void (*EditorHandler)(EditorObj *);


/* pressed / repeat button words of the current pad slot (0x14-byte rows) */
#define PAD_PRESS() ((&lbl_1_bss_9F8[0].unk_10)[(*((EditorState *)&lbl_3_bss_A2438)).unk_0 * 10])
#define PAD_REPEAT() (lbl_1_bss_9F8[(*((EditorState *)&lbl_3_bss_A2438)).unk_0].unk_12)
#define BIT(word, n) (((word) >> (n)) & 1)

/* entry is within [lo, hi] (unsigned byte range test) */
#define ENTRY_IN(e, lo, hi) ((u8)((e) - (lo)) <= (hi) - (lo))

#pragma opt_propagation off

void fn_3_18614(void) {
    EditorObj *obj;
    EditorState *st;
    s32 mode;
    u8 entry;
    u16 buttons;
    u16 *trig;

    obj = (EditorObj *)fn_3_14074();
    mode = fn_3_19C94();
    obj->unk_1C = mode;
    if ((*((EditorState *)&lbl_3_bss_A2438)).unk_4 & 0x20000000) {
        return;
    }
    switch (mode) {
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
        (((EditorHandler *)&lbl_3_data_3738))[mode](obj);
        return;
    default:
        break;
    }

    trig = &lbl_1_bss_9F8[0].unk_8;
    buttons = trig[(*((EditorState *)&lbl_3_bss_A2438)).unk_0 * 10];
    if (BIT(buttons, 8)) {
        fn_1_A2D84(0xA9150400);
        entry = (((MenuEntry *)&lbl_3_data_3618))[(*((EditorState *)&lbl_3_bss_A2438)).unk_F].unk_0;
        (*((EditorState *)&lbl_3_bss_A2438)).unk_E = entry;
        if (entry == 6) {
            (((EditorHandler *)&lbl_3_data_3738))[(*((EditorState *)&lbl_3_bss_A2438)).unk_F](obj);
            return;
        }
        if (ENTRY_IN(entry, 11, 12) || ENTRY_IN(entry, 14, 17) || entry == 13) {
            return;
        }
        if (entry == 0 || entry == 1) {
            fn_3_19CB8();
            fn_3_15620();
        } else {
            fn_3_19CB8();
            fn_3_1560C();
        }
    } else if (BIT(buttons, 9)) {
        fn_1_A2D84(0xA9150500);
        fn_3_19CCC();
        (*((EditorState *)&lbl_3_bss_A2438)).unk_8 |= 0x40000000;
        obj->flags |= 0x10000000;
        (*((EditorState *)&lbl_3_bss_A2438)).unk_10 = 0;
        (*((EditorState *)&lbl_3_bss_A2438)).unk_E = 0x11;
        return;
    }

    if ((PAD_PRESS() & 1) || (PAD_REPEAT() & 1)) {
        if ((*((EditorState *)&lbl_3_bss_A2438)).unk_F % 3 != 0) {
            (*((EditorState *)&lbl_3_bss_A2438)).unk_F--;
            fn_1_A2D84(0xA9150600);
        }
    }
    if (BIT(PAD_PRESS(), 1) || BIT(PAD_REPEAT(), 1)) {
        st = &(*((EditorState *)&lbl_3_bss_A2438));
        if (st->unk_F % 3 < 2) {
            fn_1_A2D84(0xA9150600);
            st->unk_F++;
        }
    }
    if (BIT(PAD_PRESS(), 3) || BIT(PAD_REPEAT(), 3)) {
        st = &(*((EditorState *)&lbl_3_bss_A2438));
        if (st->unk_F - 3 >= 0) {
            fn_1_A2D84(0xA9150600);
            st->unk_F -= 3;
        }
    }
    if (BIT(PAD_PRESS(), 2) || BIT(PAD_REPEAT(), 2)) {
        st = &(*((EditorState *)&lbl_3_bss_A2438));
        if (st->unk_F + 3 < 18) {
            fn_1_A2D84(0xA9150600);
            st->unk_F += 3;
        }
    }
}

#pragma opt_propagation reset
/* fzgx:end fn_3_18614 */

/* fzgx:begin fn_3_18960 noprologue */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;
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
#pragma section code_type ".text"


/* lbl_3_bss_A2438: .bss size 0x1C, 2 refs from editor.c */
/* one layout for every TU header that declares this symbol (librarian, typedefs.json) */
typedef struct {
u8 unk_0; /* 23 loads, 1 stores */
u8 pad_1[0x3];
u32 unk_4; /* 3 loads, 14 stores */
u32 unk_8; /* 10 loads, 6 stores */
u8 unk_C; /* 13 loads, 2 stores */
u8 unk_D; /* 0 loads, 1 stores */
u8 unk_E; /* 1 loads, 13 stores */
u8 unk_F; /* 13 loads, 5 stores */
u8 unk_10; /* 14 loads, 14 stores */
u8 pad_11[0x1];
s16 unk_12; /* 12 loads, 3 stores */
u8 unk_14; /* 9 loads, 3 stores */
u8 unk_15; /* 11 loads, 5 stores */
s16 unk_16; /* 3 loads, 2 stores */
s16 unk_18; /* 2 loads, 4 stores */
s16 unk_1A; /* 2 loads, 4 stores */
} Obj_3_bss_A2438;
extern Obj_3_bss_A2438 lbl_3_bss_A2438; /* typedefs.json decl override */
/* lbl_3_data_3618: .data size 0x120, 2 refs from editor.c (own data block) */
typedef struct {
u8 pad_0[0x4];
u32 unk_4; /* 1 loads, 0 stores */
u32 unk_8; /* 1 loads, 0 stores */
u16 unk_C; /* 6 loads, 4 stores */
u8 pad_E[0x112];
} Obj_3_data_3618;

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
extern const FontDrawPacket lbl_1_rodata_26F8;
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern u32 fn_1_50A90(void *, u32, u32, u32, u32);
extern s32 fn_1_A5DC4(void);
extern s32 fn_1_4FC50(void *, u32, u16, u16, u32);
extern f32 lbl_8006D188(u32);
extern u8 fn_3_19C94(void);
extern u8 *fn_3_14074(void);
extern u8 lbl_3_bss_A2458[8];
extern s32 lbl_3_bss_A179C;
extern u32 lbl_3_bss_A1798;
extern s32 lbl_801A66B4[1];
#define lbl_801A66B4 (*lbl_801A66B4)
extern u32 fn_3_1402C(u8);
extern u32 fn_3_14064(void);
extern void fn_3_146BC(u32);
typedef struct { u32 id; u32 image; u32 image2; u16 fade_values[1]; u16 pad; } Tool;
#define fade fade_values[0]
extern u8 fn_3_19D14__fzgx_offset_0[];
extern u8 fn_3_19D88__fzgx_offset_0[];
extern u8 fn_3_19DC8__fzgx_offset_0[];
extern u8 fn_3_19E40__fzgx_offset_0[];
extern u8 fn_3_19EB8__fzgx_offset_0[];
extern u8 fn_3_19EFC__fzgx_offset_0[];
extern u8 fn_3_19F40__fzgx_offset_0[];
extern u8 fn_3_19F9C__fzgx_offset_0[];
extern u8 fn_3_19FE0__fzgx_offset_0[];
extern u8 fn_3_1A024__fzgx_offset_0[];
extern u8 fn_3_1A068__fzgx_offset_0[];
extern u8 fn_3_1A0F4__fzgx_offset_0[];
extern u8 fn_3_1A1B8__fzgx_offset_0[];
extern u8 fn_3_1A1D8__fzgx_offset_0[];
extern u8 fn_3_1A264__fzgx_offset_0[];
extern u8 fn_3_1A2EC__fzgx_offset_0[];
extern u8 fn_3_1A488__fzgx_offset_0[];
extern u8 fn_3_1A648__fzgx_offset_0[];
extern u8 lbl_3_data_3780__fzgx_offset_0[];
extern u8 lbl_3_data_3788__fzgx_offset_0[];
extern u8 lbl_3_data_378C__fzgx_offset_0[];
extern u8 lbl_3_data_379C__fzgx_offset_0[];
extern u8 lbl_3_data_37A4__fzgx_offset_0[];
extern u8 lbl_3_data_37B4__fzgx_offset_0[];
extern u8 lbl_3_data_37BC__fzgx_offset_0[];
extern u8 lbl_3_data_37CC__fzgx_offset_0[];
extern u8 lbl_3_data_37D8__fzgx_offset_0[];
extern u8 lbl_3_data_37E8__fzgx_offset_0[];
extern u8 lbl_3_data_37F8__fzgx_offset_0[];
extern u8 lbl_3_data_3808__fzgx_offset_0[];
extern u8 lbl_3_data_381C__fzgx_offset_0[];
extern u8 lbl_3_data_3830__fzgx_offset_0[];
extern u8 lbl_3_data_3848__fzgx_offset_0[];
extern u8 lbl_3_data_3864__fzgx_offset_0[];
extern u8 lbl_3_data_387C__fzgx_offset_0[];
extern u8 lbl_3_data_3898__fzgx_offset_0[];
extern u8 lbl_3_data_38B4__fzgx_offset_0[];
extern u8 lbl_3_data_38D4__fzgx_offset_0[];
extern u8 lbl_3_data_38E4__fzgx_offset_0[];
extern u8 lbl_3_data_38FC__fzgx_offset_0[];
extern u8 lbl_3_data_390C__fzgx_offset_0[];
extern u8 lbl_3_data_3924__fzgx_offset_0[];
extern u8 lbl_3_data_3934__fzgx_offset_0[];
extern u8 lbl_3_data_394C__fzgx_offset_0[];
extern u8 lbl_3_data_395C__fzgx_offset_0[];
extern u8 lbl_3_data_3974__fzgx_offset_0[];
extern u8 lbl_3_data_3984__fzgx_offset_0[];
extern u8 lbl_3_data_3998__fzgx_offset_0[];
extern u8 lbl_3_data_39A8__fzgx_offset_0[];
extern u8 lbl_3_data_39C0__fzgx_offset_0[];
extern u8 lbl_3_data_39CC__fzgx_offset_0[];
extern u8 lbl_3_data_39E8__fzgx_offset_0[];
extern u8 lbl_3_data_39F4__fzgx_offset_0[];
extern u8 lbl_3_data_3A10__fzgx_offset_0[];
extern u8 lbl_3_data_3A24__fzgx_offset_0[];
extern u8 lbl_3_data_3BEC__fzgx_offset_0[];
extern u8 lbl_3_data_3C00__fzgx_offset_0[];
extern u8 lbl_3_data_3C1C__fzgx_offset_0[];
extern u8 lbl_3_data_3C34__fzgx_offset_0[];
extern u8 lbl_3_data_3C58__fzgx_offset_0[];
extern u8 lbl_3_data_3C68__fzgx_offset_0[];
extern u8 lbl_3_data_3C84__fzgx_offset_0[];
extern u8 lbl_3_data_3C88__fzgx_offset_0[];
extern u8 lbl_3_data_3C90__fzgx_offset_0[];
extern u8 lbl_3_data_3C94__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_3_data_3618[72] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x8629, 0x8617, 0x0, 0x10000, 0x8624, 0x8612, 0x0,
    0x20000, 0x8628, 0x8616, 0x0, 0x30000, 0x8625, 0x8613, 0x0,
    0x40000, 0x8620, 0x860E, 0x0, 0x50000, 0x8631, 0x861D, 0x0,
    0x60000, 0x8627, 0x8615, 0x0, 0x70000, 0x8621, 0x860F, 0x0,
    0x80000, 0x8632, 0x861E, 0x0, 0x90000, 0x862E, 0x861A, 0x0,
    0xA0000, 0x862D, 0x8619, 0x0, 0xB0000, 0x862F, 0x861B, 0x0,
    0xC0000, 0x8622, 0x8610, 0x0, 0xD0000, 0x8633, 0x861F, 0x0,
    0xE0000, 0x862C, 0x8618, 0x0, 0xF0000, 0x8626, 0x8614, 0x0,
    0x100000, 0x8630, 0x861C, 0x0, 0x110000, 0x8623, 0x8611, 0x0
};
static u32 fzgx_pool_data_lbl_3_data_3738[] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)fn_3_19D14__fzgx_offset_0, (u32)fn_3_19D88__fzgx_offset_0, (u32)fn_3_19F40__fzgx_offset_0, (u32)fn_3_19F9C__fzgx_offset_0, (u32)fn_3_19FE0__fzgx_offset_0, (u32)fn_3_19EB8__fzgx_offset_0, (u32)fn_3_1A1B8__fzgx_offset_0, (u32)fn_3_1A024__fzgx_offset_0,
    (u32)fn_3_19EFC__fzgx_offset_0, (u32)fn_3_19E40__fzgx_offset_0, (u32)fn_3_19DC8__fzgx_offset_0, (u32)fn_3_1A648__fzgx_offset_0, (u32)fn_3_1A488__fzgx_offset_0, (u32)fn_3_1A1D8__fzgx_offset_0, (u32)fn_3_1A264__fzgx_offset_0, (u32)fn_3_1A0F4__fzgx_offset_0,
    (u32)fn_3_1A068__fzgx_offset_0, (u32)fn_3_1A2EC__fzgx_offset_0, 0x44726177, 0x0, 0x0, 0x935F82F0, 0x82A982AB, 0x82DC82B7,
    0x0, 0x45726173, 0x65000000, 0x935F82F0, 0x8FC182B5, 0x82DC82B7, 0x0, 0x46696C6C,
    0x0, 0x82CA82E8, 0x82C282D4, 0x82B582DC, 0x82B70000, 0x44726177, 0x2061204C, 0x696E6500,
    0x90FC82F0, 0x88F882AB, 0x82DC82B7, 0x0, 0x44726177, 0x20612043, 0x6972636C, 0x65000000,
    0x897E82F0, 0x82A982AB, 0x82DC82B7, 0x0, 0x44726177, 0x20612052, 0x65637461, 0x6E676C65,
    0x0, 0x8E6C8A70, 0x8C6082F0, 0x82A982AB, 0x82DC82B7, 0x0, 0x456E6C61, 0x72676520,
    0x74686520, 0x45646974, 0x20536372, 0x65656E00, 0x83478366, 0x83428362, 0x836789E6, 0x96CA82F0,
    0x8A6791E5, 0x82B582DC, 0x82B70000, 0x44726177, 0x20616E64, 0x2046696C, 0x6C206120, 0x43697263,
    0x6C650000, 0x897E82F0, 0x82A982A2, 0x82C482CA, 0x82E882C2, 0x82D482B5, 0x82DC82B7, 0x0,
    0x44726177, 0x20616E64, 0x2046696C, 0x6C206120, 0x52656374, 0x616E676C, 0x65000000, 0x8E6C8A70,
    0x8C6082F0, 0x82A982A2, 0x82C482CA, 0x82E882C2, 0x82D482B5, 0x82DC82B7, 0x0, 0x526F7461,
    0x74652045, 0x6D626C65, 0x6D000000, 0x83478393, 0x8375838C, 0x838082F0, 0x89F1935D, 0x82B582DC,
    0x82B70000, 0x496E7665, 0x72742045, 0x6D626C65, 0x6D000000, 0x83478393, 0x8375838C, 0x838082F0,
    0x94BD935D, 0x82B582DC, 0x82B70000, 0x4C6F6164, 0x20612053, 0x616D706C, 0x65000000, 0x83548393,
    0x8376838B, 0x82F0838D, 0x815B8368, 0x82B582DC, 0x82B70000, 0x436C6561, 0x7220456D, 0x626C656D,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x83478393, 0x8375838C, 0x838082F0, 0x8FC182B5, 0x82DC82B7, 0x0, 0x556E646F,
    0x204F7065, 0x72617469, 0x6F6E0000, 0x91808DEC, 0x82F08EE6, 0x82E88FC1, 0x82B582DC, 0x82B70000,
    0x5265646F, 0x204F7065, 0x72617469, 0x6F6E0000, 0x91808DEC, 0x8EE682E8, 0x8FC182B5, 0x82F096DF,
    0x82B582DC, 0x82B70000, 0x4C6F6164, 0x20456D62, 0x6C656D00, 0x83478393, 0x8375838C, 0x838082F0,
    0x838D815B, 0x836882B5, 0x82DC82B7, 0x0, 0x53617665, 0x20456D62, 0x6C656D00, 0x83478393,
    0x8375838C, 0x838082F0, 0x835A815B, 0x837582B5, 0x82DC82B7, 0x0, 0x436C6F73, 0x65207468,
    0x65204564, 0x69746F72, 0x0, 0x83478366, 0x8342835E, 0x82F08F49, 0x97B982B5, 0x82DC82B7,
    0x0
};
static u32 fzgx_pool_data_lbl_3_data_3618_424[152] = { /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_3780__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_378C__fzgx_offset_0, (u32)lbl_3_data_379C__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_37A4__fzgx_offset_0, (u32)lbl_3_data_37B4__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_37BC__fzgx_offset_0, (u32)lbl_3_data_37CC__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_37D8__fzgx_offset_0, (u32)lbl_3_data_37E8__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_37F8__fzgx_offset_0, (u32)lbl_3_data_3808__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_381C__fzgx_offset_0, (u32)lbl_3_data_3830__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3848__fzgx_offset_0, (u32)lbl_3_data_3864__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_387C__fzgx_offset_0, (u32)lbl_3_data_3898__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_38B4__fzgx_offset_0, (u32)lbl_3_data_38D4__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_38E4__fzgx_offset_0, (u32)lbl_3_data_38FC__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_390C__fzgx_offset_0, (u32)lbl_3_data_3924__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_3934__fzgx_offset_0, (u32)lbl_3_data_394C__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_395C__fzgx_offset_0, (u32)lbl_3_data_3974__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3984__fzgx_offset_0, (u32)lbl_3_data_3998__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_39A8__fzgx_offset_0, (u32)lbl_3_data_39C0__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_39CC__fzgx_offset_0, (u32)lbl_3_data_39E8__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_39F4__fzgx_offset_0, (u32)lbl_3_data_3A10__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3A24__fzgx_offset_0, 0x49732069, 0x74204F4B, 0x20746F20,
    0x71756974, 0x3F000000, 0x8F4997B9, 0x82B582C4, 0x82E082E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9,
    0x81480000, 0x4F4B2074, 0x6F206572, 0x61736520, 0x74686520, 0x656D626C, 0x656D3F00, 0x83478393,  /* fzgx-allow: A1 retail data bytes */
    0x8375838C, 0x838082F0, 0x8FC182B5, 0x82C482E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x81480000,  /* fzgx-allow: A1 retail data bytes */
    0x4C6F6164, 0x20612073, 0x616D706C, 0x653F0000, 0x83548393, 0x8376838B, 0x82F0838D, 0x815B8368,  /* fzgx-allow: A1 retail data bytes */
    0x82B582DC, 0x82B782A9, 0x81480000, 0x59455300, 0x82CD82A2, 0x0, 0x4E4F0000, 0x82A282A2,  /* fzgx-allow: A1 retail data bytes */
    0x82A60000
};
static u32 fzgx_pool_data_lbl_3_data_3618_684[5][6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_3BEC__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3C00__fzgx_offset_0, (u32)lbl_3_data_3C1C__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3C34__fzgx_offset_0, (u32)lbl_3_data_3C58__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0,
    (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3C68__fzgx_offset_0, (u32)lbl_3_data_3C84__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3C88__fzgx_offset_0,
    (u32)lbl_3_data_3C90__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3788__fzgx_offset_0, (u32)lbl_3_data_3C94__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_3_data_3D14[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x746F6F6C, 0x6B69742E, 0x63000000
};
static u32 fzgx_pool_data_lbl_3_data_3618_708[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25730A00
};
static u32 fzgx_pool_data_lbl_3_data_3618_70C[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x2F626366, 0x66666666, 0x662F0000
};
static u32 fzgx_pool_data_lbl_3_data_3618_718[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x2F626366, 0x66663230, 0x302F0000
};
static u32 fzgx_pool_data_lbl_3_data_3618_724[5] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25732573, 0x25732020, 0x20257325, 0x7325730A, 0x0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_3_data_3618(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3618;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3738;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3618_424;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3618_684;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3D14;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3618_708;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3618_70C;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3618_718;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_3618_724;
}
#pragma section code_type ".text"

static inline int clamp(int v, int max) { return v < 0 ? 0 : v > max ? max : v; }
static inline void fade_set(u16 *value, int updated) { *value = clamp(updated, 40); }
#define fade_add(value, delta) fade_set(value, *(value) + (delta))
typedef struct { char *line[6]; } MessageRow;
typedef struct { char *quit; u8 pad_4[20]; char *erase; u8 pad_1C[20]; char *load; u8 pad_34[20]; char *yes; u8 pad_4C[20]; char *no; } MessageColumn;
void fn_3_18960(u32 arg0) {

Obj_3_bss_A2438 *state;
u8 i, j;
s16 xoff, yoff;
int y0, y1, x0, x1;
Tool *tool;
int x, y;
u16 *fadePtr;
int fullindex;
u8 index;
u32 image;
f32 pulse;
FontDrawPacket p;
if (lbl_3_bss_A2438.unk_4 & 0x20000000)
lbl_3_bss_A2438.unk_16 = clamp(lbl_3_bss_A2438.unk_16 - 1, 10);
else
lbl_3_bss_A2438.unk_16 = clamp(lbl_3_bss_A2438.unk_16 + 1, 10);
p = lbl_1_rodata_26F8 ;
p.image = 0x863e; p.x = 24.0f; p.y = 86.0f; p.z = 100.0f; p.flags = 5; fn_1_4F734(&p) ;
for (i = 0; i < 6; i++) {
p = lbl_1_rodata_26F8 ;
p.image = 0x8608; p.x = 24.0f; p.y = (i * 46 + 113);
p.z = 100.0f; p.flags = 5; fn_1_4F734(&p) ;
}
p = lbl_1_rodata_26F8 ;
p.image = 0x863f; p.x = 24.0f; p.y = 385.0f; p.z = 100.0f; p.flags = 5; fn_1_4F734(&p) ;
p = lbl_1_rodata_26F8 ;
p.image = 0x863b; p.x = 170.0f; p.y = 104.0f; p.z = 100.0f; p.flags = 5; fn_1_4F734(&p) ;
p = lbl_1_rodata_26F8 ;
p.image = 0x860c; p.x = 40.0f; p.y = 96.0f; p.z = 90.0f; p.flags = 5; fn_1_4F734(&p) ;
state = &lbl_3_bss_A2438;
xoff = (state->unk_F % 3) * 48;
p = lbl_1_rodata_26F8 ;
yoff = (state->unk_F / 3) * 46;
p.image = 0x8604;
p.x = xoff + 19; p.y = yoff + 104;
p.alpha = 0.5f + lbl_3_bss_A2438.unk_16 / 20.0f;
p.z = 90.0f; p.flags = 5; fn_1_4F734(&p) ;
p.x = xoff + 51; p.y = yoff + 104; p.z = 90.0f; p.flags = 0x80005; fn_1_4F734(&p) ;
p.x = xoff + 19; p.y = yoff + 136; p.z = 90.0f; p.flags = 0x100005; fn_1_4F734(&p) ;
p.x = xoff + 51; p.y = yoff + 136; p.z = 90.0f; p.flags |= 0x80000; fn_1_4F734(&p) ;
{
u8 i, j;
for (i = 0; i < 6; i++) {
for (j = 0; j < 3; j++) {
fullindex = j + i * 3;
index = fullindex;
p = lbl_1_rodata_26F8 ;
tool = (Tool *)((((u8 (*)[16])fzgx_pool_data_lbl_3_data_3618)[index]));
x = j * 48 + 49; y = i * 46 + 134;
p.image = tool->image; p.x = x; p.y = y; p.z = 60.0f;
if (state->unk_F == index) fade_add(&((Tool *)fzgx_pool_data_lbl_3_data_3618)[index].fade, 4);
else fade_add(&((Tool *)fzgx_pool_data_lbl_3_data_3618)[index].fade, -1);
fadePtr = &((Tool *)fzgx_pool_data_lbl_3_data_3618)[index].fade;
p.alpha = 0.5f + (f32)*fadePtr / 80.0f;
((u8 *)&p.color)[0] = 255; ((u8 *)&p.color)[1] = 255; ((u8 *)&p.color)[2] = 255; ((u8 *)&p.color)[3] = 255;
p.flags = 10; fn_1_4F734(&p) ;
p = lbl_1_rodata_26F8 ;
p.image = tool->image2; p.x = x; p.y = y; p.z = 80.0f;
if ((s16)arg0 > 15) {
if (state->unk_F == index) *fadePtr = clamp(*fadePtr + 4,40);
else *fadePtr = clamp(*fadePtr - 1,40);
p.alpha = 0.5f + (f32)*fadePtr / 80.0f;
} else {
if (state->unk_F == fullindex) p.alpha = (s16)arg0 / 15.0f;
else p.alpha = (s16)arg0 / 30.0f;
}
((u8 *)&p.color)[0] = 0; ((u8 *)&p.color)[1] = 255; ((u8 *)&p.color)[2] = 255; ((u8 *)&p.color)[3] = 255; p.flags = 10; fn_1_4F734(&p) ;
}
}
}
fn_1_49410(); fn_1_495B0(0x80000000); fn_1_495C8(1);
fn_1_496FC(320.0f,372.0f);
if (fn_3_19C94() == 16 || fn_3_19C94() == 15 || fn_3_19C94() == 11 || (__rlwnm(*(u32 *)fn_3_14074(), 7, 31, 31)))
fn_1_4954C(30.0f);
else fn_1_4954C(0.1f);
if (lbl_801A66B4 != 5) {
fn_1_49590(0.5f); fn_1_4955C(0.6f,0.6f); fn_1_496FC(320.0f,375.0f);
} else fn_1_4955C(0.75f,0.75f);
fn_1_4AE0C(((char *)(((u8 *)fzgx_pool_data_lbl_3_data_3618_708))) , ((MessageRow *)fzgx_pool_data_lbl_3_data_3618_424)[state->unk_F].line[lbl_801A66B4] );
if (fn_3_19C94() == 17) {
p = lbl_1_rodata_26F8 ;
p.image = 12; p.x = 320.0f; p.y = 248.0f; p.z = 20.0f; p.alpha = 1.0f; p.flags = 10;
fn_1_50A90(&p,7,7,360,68);
fn_1_49410(); fn_1_4955C(0.8f,0.8f); fn_1_496FC(320.0f,240.0f);
fn_1_495C8(9); fn_1_495B0(0x80000000);
if (lbl_801A66B4 != 5) fn_1_49590(0.5f);
fn_1_4AE0C(((char *)(((u8 *)fzgx_pool_data_lbl_3_data_3618_708))) , ((MessageRow *)fzgx_pool_data_lbl_3_data_3618_684)[0].line[lbl_801A66B4] );
fn_1_4AE0C((char *)fzgx_pool_data_lbl_3_data_3618_724,
lbl_3_bss_A2438.unk_10 ? (char *)fzgx_pool_data_lbl_3_data_3618_718 : (char *)fzgx_pool_data_lbl_3_data_3618_70C,
(char *)fzgx_pool_data_lbl_3_data_3618_684[3][lbl_801A66B4],
(char *)fzgx_pool_data_lbl_3_data_3618_70C,
lbl_3_bss_A2438.unk_10 ? (char *)fzgx_pool_data_lbl_3_data_3618_70C : (char *)fzgx_pool_data_lbl_3_data_3618_718,
(char *)fzgx_pool_data_lbl_3_data_3618_684[4][lbl_801A66B4],
(char *)fzgx_pool_data_lbl_3_data_3618_70C);
}
if (fn_3_19C94() == 12) {
p = lbl_1_rodata_26F8 ;
p.image = 12; p.x = 320.0f; p.y = 248.0f; p.z = 20.0f; p.alpha = 1.0f; p.flags = 10;
fn_1_50A90(&p,7,7,400,68);
fn_1_49410(); fn_1_4955C(0.8f,0.8f); fn_1_496FC(320.0f,240.0f); fn_1_495B0(0x80000000);
if (lbl_801A66B4 != 5) fn_1_49590(0.5f);
fn_1_495C8(9);
fn_1_4AE0C(((char *)(((u8 *)fzgx_pool_data_lbl_3_data_3618_708))) , (char *)fzgx_pool_data_lbl_3_data_3618_684[1][lbl_801A66B4] );
fn_1_4AE0C((char *)fzgx_pool_data_lbl_3_data_3618_724,
lbl_3_bss_A2438.unk_10 ? (char *)fzgx_pool_data_lbl_3_data_3618_718 : (char *)fzgx_pool_data_lbl_3_data_3618_70C,
(char *)fzgx_pool_data_lbl_3_data_3618_684[3][lbl_801A66B4],
(char *)fzgx_pool_data_lbl_3_data_3618_70C,
lbl_3_bss_A2438.unk_10 ? (char *)fzgx_pool_data_lbl_3_data_3618_70C : (char *)fzgx_pool_data_lbl_3_data_3618_718,
(char *)fzgx_pool_data_lbl_3_data_3618_684[4][lbl_801A66B4],
(char *)fzgx_pool_data_lbl_3_data_3618_70C);
}
if (fn_3_19C94() == 15 || fn_3_19C94() == 16) {
if (lbl_3_bss_A2458[0] || lbl_3_bss_A179C) lbl_3_bss_A1798 = 0;
else lbl_3_bss_A1798 = 1;
} else lbl_3_bss_A1798 = 0;
if (fn_3_19C94() == 11) {
p = lbl_1_rodata_26F8 ;
p.image = 12; p.x = 320.0f; p.y = 240.0f; p.z = 25.0f; p.flags = 10;
fn_1_50A90(&p,7,7,429,340);
{
Obj_3_bss_A2438 *state2 = &lbl_3_bss_A2438;
s16 yoff, xoff;
int x0, x1, y0, y1;
for (i = 0; i < 4; i++) {
for (j = 0; j < 5; j++) {
image = fn_3_1402C((state2 ->unk_12 + i * 5 + j));
if (image) {
p = lbl_1_rodata_26F8 ;
p.x = j * 75 + 139; p.y = i * 72 + 100; (*(f32 *)((u8 *)&p + 0x14)) = 1.02f;
if ((s8)fn_1_A5DC4()) (*(f32 *)((u8 *)&p + 0x10)) = 1.01f; else (*(f32 *)((u8 *)&p + 0x10)) = 1.02f;
p.z = 20.0f; p.flags = 5;
fn_1_4FC50(&p,5,64,64,image);
}
}
}
yoff = lbl_3_bss_A2438.unk_15 * 72;
p = lbl_1_rodata_26F8 ;
xoff = lbl_3_bss_A2438.unk_14;
xoff *= 75;
p.image = 0x8604; p.x = xoff + 125; p.y = yoff + 86; p.z = 20.0f; p.flags = 5; fn_1_4F734(&p) ;
p.x = xoff + 188; p.y = yoff + 86; p.z = 20.0f; p.flags = 0x80005; fn_1_4F734(&p) ;
p.x = xoff + 125; p.y = yoff + 151; p.z = 20.0f; p.flags = 0x100005; fn_1_4F734(&p) ;
p.x = xoff + 188; p.y = yoff + 151; p.z = 20.0f; p.flags |= 0x80000; fn_1_4F734(&p) ;
if (state2 ->unk_12 - 5 >= 0) {
pulse = 0.4f * lbl_8006D188((s32)(32768.0f * (lbl_3_bss_A2438.unk_18 / 10.0f)));
p = lbl_1_rodata_26F8 ;
p.scale_y = p.scale_x = 1.0f + pulse; p.alpha = 1.0f - pulse;
p.image = 0x8901; p.x = 320.0f; p.y = 81.0f; p.z = 20.0f; (*(s16 *)((u8 *)&p + 0x28)) = -16384; p.flags = 10; fn_1_4F734(&p) ;
if (lbl_3_bss_A2438.unk_18 < 10) lbl_3_bss_A2438.unk_18++;
}
if (state2 ->unk_12 + 20 < (u8)fn_3_14064()) {
pulse = 0.4f * lbl_8006D188((s32)(32768.0f * (lbl_3_bss_A2438.unk_1A / 10.0f)));
p = lbl_1_rodata_26F8 ;
p.scale_y = p.scale_x = 1.0f + pulse; p.alpha = 1.0f - pulse;
p.image = 0x8901; p.x = 320.0f; p.y = 399.0f; p.z = 20.0f; (*(s16 *)((u8 *)&p + 0x28)) = 16384; p.flags = 10; fn_1_4F734(&p) ;
if (lbl_3_bss_A2438.unk_1A < 10) lbl_3_bss_A2438.unk_1A++;
}
if ((__rlwnm(lbl_3_bss_A2438.unk_8, 32 - (30), 31, 31))) {
p = lbl_1_rodata_26F8 ;
p.image = 12; p.x = 320.0f; p.y = 248.0f; p.z = 18.0f; p.alpha = 1.0f; p.flags = 10;
fn_1_50A90(&p,7,7,360,68);
fn_1_49410(); fn_1_4955C(0.8f,0.8f); fn_1_496FC(320.0f,240.0f); fn_1_4954C(12.0f);
fn_1_495C8(9); fn_1_495B0(0x80000000);
if (lbl_801A66B4 != 5) fn_1_49590(0.5f);
fn_1_4AE0C(((char *)(((u8 *)fzgx_pool_data_lbl_3_data_3618_708))) ,(char *)fzgx_pool_data_lbl_3_data_3618_684[2][lbl_801A66B4] );
fn_1_4AE0C((char *)fzgx_pool_data_lbl_3_data_3618_724,
lbl_3_bss_A2438.unk_10 ? (char *)fzgx_pool_data_lbl_3_data_3618_718 : (char *)fzgx_pool_data_lbl_3_data_3618_70C,
(char *)fzgx_pool_data_lbl_3_data_3618_684[3][lbl_801A66B4],
(char *)fzgx_pool_data_lbl_3_data_3618_70C,
lbl_3_bss_A2438.unk_10 ? (char *)fzgx_pool_data_lbl_3_data_3618_70C : (char *)fzgx_pool_data_lbl_3_data_3618_718,
(char *)fzgx_pool_data_lbl_3_data_3618_684[4][lbl_801A66B4],
(char *)fzgx_pool_data_lbl_3_data_3618_70C);
}
}
}
if (fn_3_19C94() == 13 || fn_3_19C94() == 14) fn_3_146BC(arg0);
}
/* fzgx:end fn_3_18960 */

/* fzgx:begin fn_3_19C50 */
void fn_3_19C50(void) {
    fn_1_46B4(lbl_801A6410, lbl_3_bss_A2454, lbl_3_data_3D14, 0x294);
}
/* fzgx:end fn_3_19C50 */

/* fzgx:begin fn_3_19C94 */
u8 fn_3_19C94(void) {
    return ((u8 *)&lbl_3_bss_A2438)[0xe];
}
/* fzgx:end fn_3_19C94 */

/* fzgx:begin fn_3_19CA4 */
#include "types.h"



void fn_3_19CA4(void) {
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A2438) + 4) = (u32)-2147483648;
}
/* fzgx:end fn_3_19CA4 */

/* fzgx:begin fn_3_19CB8 */
#include "types.h"



void fn_3_19CB8(void) {
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A2438) + 4) = 0x20000000;
}
/* fzgx:end fn_3_19CB8 */

/* fzgx:begin fn_3_19CCC */
#include "types.h"



void fn_3_19CCC(void) {
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A2438) + 4) = 0x40000000;
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

/* fzgx:begin fn_3_19D50 */
#include "types.h"



void fn_3_19D50(void) {
    (*(u8 (*)[28])&lbl_3_bss_A2438)[12] = ((*(u8 (*)[28])&lbl_3_bss_A2438)[12] + 1) % 5;
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
               &value);
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
typedef struct fn_3_19E40_CustomizeData {
    u32 unk_00[2];
    u32 unk_08;
    u8 pad_0c[0x14];
    void *unk_20;
} fn_3_19E40_CustomizeData;

extern void fn_3_1AEE4(void *, u32, u32, u32, u32);
extern void fn_3_1B008(void *, u32, u32, u32, u32);

void fn_3_19E40(fn_3_19E40_CustomizeData *self) {
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

/* fzgx:begin fn_3_1A068 */
#include "types.h"




extern void fn_3_BD98(void);


extern void fn_3_BEF0(void);
extern void fn_3_BE88(void);

void fn_3_1A068(void) {
    if (lbl_3_bss_A2458[0] != 0) {
        fn_3_BD98();
        lbl_3_bss_A2458[0] = 0;
    } else if ((*(s32 *)&lbl_3_bss_A179C) != 0) {
        fn_3_BEF0();
        lbl_3_bss_A2458[0] = 1;
        *(u32 *)&(*(u8 (*)[28])&lbl_3_bss_A2438)[4] = 0x40000000;
        (*(u8 (*)[28])&lbl_3_bss_A2438)[0xE] = 0;
        lbl_3_bss_A179C = 0;
    } else {
        fn_3_BE88();
    }
}
/* fzgx:end fn_3_1A068 */

/* fzgx:begin fn_3_1A0F4 */
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


extern void fn_3_BE10(void);
extern void fn_3_BEF0(void);
extern void fn_3_1445C(void);
extern void fn_3_BE88(void);
extern void fn_80008BA8(u32, u32, u32);
extern s32 memcmp(u32, u32, u32);

void fn_3_1A0F4(u8 *arg0) {
    if (fzgx_obj_lbl_3_bss_A2458 != 0) {
        fn_80008BA8(fzgx_obj_lbl_3_bss_A2454, *(u32 *)(arg0 + 0x20), 0x2000);
        fn_3_BE10();
        fzgx_obj_lbl_3_bss_A2458 = 0;
    } else if ((*(s32 *)&lbl_3_bss_A179C) != 0) {
        fn_3_BEF0();
        fzgx_obj_lbl_3_bss_A2458 = 1;
        fzgx_obj_lbl_3_bss_A2438.unk_4 = 0x40000000;
        fzgx_obj_lbl_3_bss_A2438.unk_E = 0;
        lbl_3_bss_A179C = 0;
        if (memcmp(fzgx_obj_lbl_3_bss_A2454, *(u32 *)(arg0 + 0x20), 0x2000) != 0) {
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
    v0 = (u32)(v0 + ((*(struct fn_3_1A1D8_lbl_3_bss_A2438 *)&lbl_3_bss_A2438).unk_0 * 20));
    if (((*(u16 *)(v0 + 8) >> 9) & 0x1) != 0) {
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

/* fzgx:begin fn_3_1A2EC */
#include "types.h"

typedef struct {
    u16 flags;
    u8 pad[18];
} fn_3_1A2EC_CustomizeEntry;

struct fn_3_1A2EC_QView {
    u8 unk_0;
    u8 pad_1[0x3];
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x2];
    u8 unk_E;
    u8 pad_F[0x1];
    u8 unk_10;
};




extern void fn_1_A2D84(u32);
extern void fn_3_14008(void);

void fn_3_1A2EC(void) {
    fn_3_1A2EC_CustomizeEntry *entries;
    fn_3_1A2EC_CustomizeEntry *entries_alt;
    u8 index;
    u32 flags;
    struct fn_3_1A2EC_QView *st;

    entries = (fn_3_1A2EC_CustomizeEntry *)((*(u8 (*)[])&lbl_1_bss_9F8) + 0x10);
    index = (*(u8 (*)[28])&lbl_3_bss_A2438)[0];
    if ((entries[index].flags & 1) == 0) {
        if ((*(u16 *)((*(u8 (*)[])&lbl_1_bss_9F8) + 0x12 + index * 20) & 1) == 0) {
            goto after_enable; /* Keep the verified branch to after_enable. */
        }
    }

    if ((*(u8 (*)[28])&lbl_3_bss_A2438)[0x10] == 0) {
        fn_1_A2D84(0xA9010000);
    }
    (*(u8 (*)[28])&lbl_3_bss_A2438)[0x10] = 1;

after_enable:
    index = (*(u8 (*)[28])&lbl_3_bss_A2438)[0];
    flags = (entries[index].flags);
    if (((flags >> 1) & 1) == 0 &&
        (((*(u16 *)((*(u8 (*)[])&lbl_1_bss_9F8) + 0x12 + index * 20) >> 1) & 1) == 0)) {
        goto after_disable; /* Keep the verified branch to after_disable. */
    }

    if ((*(u8 (*)[28])&lbl_3_bss_A2438)[0x10] != 0) {
        fn_1_A2D84(0xA9010000);
    }
    (*(u8 (*)[28])&lbl_3_bss_A2438)[0x10] = 0;

after_disable:
    entries_alt = (fn_3_1A2EC_CustomizeEntry *)((*(u8 (*)[])&lbl_1_bss_9F8) + 8);
    index = (*(u8 (*)[28])&lbl_3_bss_A2438)[0];
    flags = (entries_alt[index].flags);
    if (((flags >> 8) & 1) != 0 && (*(u8 (*)[28])&lbl_3_bss_A2438)[0x10] != 0) {
        fn_1_A2D84(0xA9150400);
        *(u32 *)&(*(u8 (*)[28])&lbl_3_bss_A2438)[4] = 0x40000000;
        (*(u8 (*)[28])&lbl_3_bss_A2438)[0xE] = 0;
        fn_3_14008();
        (*(u8 (*)[28])&lbl_3_bss_A2438)[0x10] = 0;
    }

    st = (struct fn_3_1A2EC_QView *)(*(u8 (*)[28])&lbl_3_bss_A2438);
    flags = (u16)(entries_alt[st->unk_0].flags);
    if (((flags >> 9) & 1) != 0 ||
        (st->unk_10 == 0 && ((flags >> 8) & 1) != 0)) {
        fn_1_A2D84(0xA9150500);
        *(u32 *)&(*(u8 (*)[28])&lbl_3_bss_A2438)[4] = 0x40000000;
        (*(u8 (*)[28])&lbl_3_bss_A2438)[0xE] = 0;
        *(u32 *)&(*(u8 (*)[28])&lbl_3_bss_A2438)[8] &= 0xBFFFFFFF;
    }
}
/* fzgx:end fn_3_1A2EC */

/* fzgx:begin fn_3_1A488 */
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


extern u32 fn_3_1401C(void);
extern void fn_3_1445C(void);
extern u32 fn_3_152BC(u32, u32, u32, u32, u32, void *);


extern void fn_1_A2D84(u32);

void fn_3_1A488(void) {
    struct fn_3_1A488_lbl_1_bss_9F8_8_E20 *entries;
    s32 v1;
    u16 v0;
    u32 v2;
    struct { u32 a[4]; } loc_8;
    u32 t3;
    entries = (struct fn_3_1A488_lbl_1_bss_9F8_8_E20 *)((u8 *)&(*(struct fn_3_1A488_lbl_1_bss_9F8 *)&lbl_1_bss_9F8) + 16);
    v0 = lbl_3_bss_A2438.unk_0;
    if ((entries[v0].unk_0 & 1) != 0 ||
        (((1) & (*(u16 *)((u8 *)&(*(struct fn_3_1A488_lbl_1_bss_9F8 *)&lbl_1_bss_9F8) + v0 * 20 + 18)))) != 0) {
        Obj_3_bss_A2438 *st = &lbl_3_bss_A2438;
        if (st->unk_10 == 0) {
            fn_1_A2D84(0xA9010000);
        }
        st->unk_10 = 1;
    }
    v1 = lbl_3_bss_A2438.unk_0;
    if (((entries[v1].unk_0 >> 1) & 1) != 0 ||
        ((*(u16 *)((u8 *)&(*(struct fn_3_1A488_lbl_1_bss_9F8 *)&lbl_1_bss_9F8) + v1 * 20 + 18) >> 1) & 1) != 0) {
        Obj_3_bss_A2438 *st = &lbl_3_bss_A2438;
        if (st->unk_10 != 0) {
            fn_1_A2D84(0xA9010000);
        }
        st->unk_10 = 0;
    }
    entries = (struct fn_3_1A488_lbl_1_bss_9F8_8_E20 *)((u8 *)&(*(struct fn_3_1A488_lbl_1_bss_9F8 *)&lbl_1_bss_9F8) + 8);
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
        v2 = (u16)((st->unk_0)[entries]).unk_0;
        if (((v2 >> 9) & 1) != 0 ||
            (st->unk_10 == 0 && ((v2 >> 8) & 1) != 0)) {
            fn_1_A2D84(0xA9150500);
            lbl_3_bss_A2438.unk_4 = 0x40000000;
            lbl_3_bss_A2438.unk_E = 0;
        }
    }
}
/* fzgx:end fn_3_1A488 */

/* fzgx:begin fn_3_1A648 */
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


extern u8 fn_3_14064(void);
extern u32 fn_3_1401C(void);
extern u32 fn_3_1402C(u8);
extern void fn_3_1445C(void);
extern void fn_1_A2D84(u32);
extern void fn_80008BA8(u32, u32, u32);
extern void fn_80008BEC(void *, int, u32);

void fn_3_1A648(void) {
    struct fn_3_1A648_lbl_1_bss_9F8_8_E20 *entries;
    u32 t3;
    u32 t4;
    struct fn_3_1A648_lbl_1_bss_9F8_8_E20 *entries_2;
    u32 t5;

    entries = (struct fn_3_1A648_lbl_1_bss_9F8_8_E20 *)((u8 *)&(*(struct fn_3_1A648_lbl_1_bss_9F8 *)&lbl_1_bss_9F8) + 0x10);

    if ((entries[lbl_3_bss_A2438.unk_0].unk_0 & 1) != 0 ||
        (*(u16 *)((u8 *)&(*(struct fn_3_1A648_lbl_1_bss_9F8 *)&lbl_1_bss_9F8) + lbl_3_bss_A2438.unk_0 * 0x14 + 0x12) & 1) != 0) {
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
        ((*(u16 *)((u8 *)&(*(struct fn_3_1A648_lbl_1_bss_9F8 *)&lbl_1_bss_9F8) + lbl_3_bss_A2438.unk_0 * 0x14 + 0x12) >> 1) & 1) != 0) {
        if (__rlwnm(lbl_3_bss_A2438.unk_8, 2, 31, 31)) {
            if (lbl_3_bss_A2438.unk_10 != 0) {
                fn_1_A2D84(0xA9010000);
            }
            lbl_3_bss_A2438.unk_10 = 0;
        } else if (lbl_3_bss_A2438.unk_14 < 4) {
            t3 = fn_3_14064();
            if (((1) + (((lbl_3_bss_A2438.unk_14) + ((lbl_3_bss_A2438.unk_15 * 5) + lbl_3_bss_A2438.unk_12)))) < (s32)(t3 & 0xFF)) {
                fn_1_A2D84(0xA9150600);
                lbl_3_bss_A2438.unk_14++;
            }
        }
    }

    if (((entries[lbl_3_bss_A2438.unk_0].unk_0 >> 3) & 1) != 0 ||
        ((*(u16 *)((u8 *)&(*(struct fn_3_1A648_lbl_1_bss_9F8 *)&lbl_1_bss_9F8) + lbl_3_bss_A2438.unk_0 * 0x14 + 0x12) >> 3) & 1) != 0) {
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
        ((*(u16 *)((u8 *)&(*(struct fn_3_1A648_lbl_1_bss_9F8 *)&lbl_1_bss_9F8) + lbl_3_bss_A2438.unk_0 * 0x14 + 0x12) >> 2) & 1) != 0) {
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
                            lbl_3_bss_A2438.unk_12) >= (s32)(t3 & 0xFF)) {
                        lbl_3_bss_A2438.unk_15--;
                    }
                }
            } else if (lbl_3_bss_A2438.unk_15 < 3) {
                t3 = fn_3_14064();
                if (((lbl_3_bss_A2438.unk_12) + (((lbl_3_bss_A2438.unk_15 + 1) * 5) +
                        lbl_3_bss_A2438.unk_14)) < (s32)(t3 & 0xFF)) {
                    fn_1_A2D84(0xA9150600);
                    lbl_3_bss_A2438.unk_15++;
                }
            }
        }
    }

    entries_2 = (struct fn_3_1A648_lbl_1_bss_9F8_8_E20 *)((u8 *)&(*(struct fn_3_1A648_lbl_1_bss_9F8 *)&lbl_1_bss_9F8) + 8);

    if (((entries_2[lbl_3_bss_A2438.unk_0].unk_0 >> 8) & 1) != 0) {
        t4 = fn_3_1401C();
        t5 = fn_3_1402C(((((lbl_3_bss_A2438.unk_12) + lbl_3_bss_A2438.unk_14) +
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

    current = second_a;
    count = 0;
    limit = (second_b - current);
    while (count <= limit) {
        value = *values;
        fn_3_1B4BC(data, first_a, current, first_b, current, &value);
        current++;
        count++;
    }
}
/* fzgx:end fn_3_1ACE4 */

/* fzgx:begin fn_3_1ADA4 */
/* Flips the rectangle vertically by swapping row pairs from the outside in. */
void fn_3_1ADA4(void *canvas, s32 left, s16 top, s16 right, s16 bottom) {
    s32 i;
    s16 half;

    half = (bottom - top) / 2;
    for (i = 0; (s16)i < half; i++) {
        fn_3_15240(canvas, left, top + i, right - (s16)left, left, bottom - i - 1);
    }
}
/* fzgx:end fn_3_1ADA4 */

/* fzgx:begin fn_3_1AE40 */
extern void fn_3_14E18(void *, u32, u32, s16, u32);

void fn_3_1AE40(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    s16 v1;
    u32 v0;
    u32 v3;
    u32 v4;
    s16 v2;

    v0 = (s16)arg3 - (s16)arg1;
    v1 = arg4;
    v2 = ((s32)(((u32)v0 >> 31) + v0) >> 1);
    v3 = arg2;
    while ((s16)v3 < v1) {
        v4 = arg1;
        while ((s16)v4 < v2) {
            fn_3_14E18(arg0, v4, v3, ((v0 - v4) - 1), v3);
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
            fn_3_14794((void *)lbl_3_bss_A2454, y, (last - x), &value1);
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
            fn_3_14794((void *)lbl_3_bss_A2454, destination_x, x, &value);
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

#ifndef GAME_VEC3_H
#define GAME_VEC3_H

#endif  // GAME_VEC3_H

/* end game/vec3.h */

typedef struct fn_3_1B130_Rgba {
    u8 r, g, b, a;
} fn_3_1B130_Rgba;

extern fn_3_1B130_Rgba fn_3_149AC(void *, s16, s16);
extern void fn_3_146C0(void *, s16, s16, s16, fn_3_1B130_Rgba *);
extern void fn_80008BEC(void *, int, u32);

/* Scanline flood fill of the region whose colour equals the pixel at (x, y). */
void fn_3_1B130(void *data, s16 x, s16 y, fn_3_1B130_Rgba color) {
    s16 queue_x[0x1000];
    s16 queue_y[0x1000];
    fn_3_1B130_Rgba pixel;
    fn_3_1B130_Rgba target;
    fn_3_1B130_Rgba fill;
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
            pixel = fn_3_149AC(data, x, ny);
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
            pixel = fn_3_149AC(data, x, ny);
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
        slope = (f32)(y1 - y0) / (x1 - x0);
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

/* fzgx:begin fn_3_1BA20 */
#include "font.h"

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
extern void fn_3_BE10(void);
extern void fn_3_1445C(void);
extern void fn_80008BA8(u32 *, void *, s32);
extern s32 memcmp(u32 arg0, u32 arg1, u32 arg2);
extern u32 fn_3_141A8(u32);
extern u8 fn_3_1443C(void);
extern u32 fn_3_14064(void);
extern u32 fn_3_1401C(void);
extern u32 fn_3_1402C(u8 index);
extern void fn_1_A2D84(u32 arg0);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_3_1B4BC(void *, s16, s16, s16, s16, u32 *);
extern void fn_3_14794(void *, u32, u32, u32 *);
extern void fn_3_146C0(void *arg0, s16 x, s16 y, s16 delta, u32 *arg4);
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
extern u8 fn_3_1441C(void);
extern void fn_3_14008(void);
extern void fn_3_152BC(u32, s32, s32, s32, s32, QColor);
extern void fn_3_14E18(void *arg0, u32 arg1, u32 arg2, s16 arg3, u32 arg4);
extern const f32 lbl_3_rodata_990[297];
extern u32 fn_1_870BC(u32,u32,Sig_fn_1_87610_Fn187610Data*,u32,u32,f32);
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void lbl_8006D7DC(void*);
extern void lbl_8006DFE8(void*);
extern void lbl_8006E14C(f32);
extern s32 fn_3_1EC2C(u32);
extern void fn_3_23724(u32 arg0, u32 arg1, u32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
extern u32 fn_3_21300(u32,u32,u32);
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
extern u8 fn_1_B7C00(void);
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
    v21 = (v10 * t0);
    v19 = (2.0f + (1.0f + ((-2.0f * loc_28) * v10)));
    v18 = (1.0f + (2.0f + ((-4.0f * loc_28) * v10)));
    v20 = 0;
    while ((s16)v21 >= 0) {
        v22 = v20;
        v24 = v21;
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
            v19 = ((s16)v19 + (2.0f + (4.0f * (s16)v20)));
            v18 = ((s16)v18 + (4.0f * (s16)v20));
        } else if ((s16)v18 >= 0) {
            v21--;
            v19 = ((s16)v19 - (4.0f * (s16)v21));
            v18 = ((s16)v18 - ((4.0f * (s16)v21) - 2.0f));
        } else {
            v20++;
            v21--;
            v19 = ((s16)v19 + (2.0f + ((4.0f * (s16)v20) - (4.0f * (s16)v21))));
            v18 = ((s16)v18 + (2.0f + ((4.0f * (s16)v20) - (4.0f * (s16)v21))));
        }
    }
}
/* fzgx:end fn_3_1BA20 */

/* fzgx:begin fn_3_1BF08 */
typedef signed short fn_3_1BF08_s16;
typedef signed long fn_3_1BF08_s32;


typedef unsigned char fn_3_1BF08_u8;
typedef unsigned short fn_3_1BF08_u16;
typedef unsigned long fn_3_1BF08_u32;


typedef float fn_3_1BF08_f32;
typedef double fn_3_1BF08_f64;


typedef struct fn_3_1BF08_FontDrawPacket fn_3_1BF08_FontDrawPacket;
typedef struct fn_3_1BF08_FontVertex {
fn_3_1BF08_f32 x, y, z;
} fn_3_1BF08_FontVertex;
struct fn_3_1BF08_FontDrawPacket {
fn_3_1BF08_u32 image;
fn_3_1BF08_f32 x, y, z;
fn_3_1BF08_f32 scale_x, scale_y;
fn_3_1BF08_f32 u0, v0, u1, v1;
fn_3_1BF08_s16 rotation_z, rotation_y;
fn_3_1BF08_f32 alpha;
fn_3_1BF08_u32 flags;
fn_3_1BF08_f32 depth;
fn_3_1BF08_u8 color[4], color_add[4];
fn_3_1BF08_u32 format;
fn_3_1BF08_u16 width, height;
void* pixels;
fn_3_1BF08_FontDrawPacket* secondary;
void (*vertex_callback)(fn_3_1BF08_FontDrawPacket* packet, fn_3_1BF08_FontVertex* vertices);
fn_3_1BF08_u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(fn_3_1BF08_FontDrawPacket* packet);
void fn_1_4EDAC(fn_3_1BF08_FontDrawPacket* packet, fn_3_1BF08_f32 width, fn_3_1BF08_f32 height);
void fn_1_51678(fn_3_1BF08_FontDrawPacket* packet, fn_3_1BF08_u32 image, fn_3_1BF08_s16 x, fn_3_1BF08_s16 y, fn_3_1BF08_s16 width, fn_3_1BF08_s16 height);
void fn_1_517EC(fn_3_1BF08_FontDrawPacket* packet, fn_3_1BF08_s16 x, fn_3_1BF08_s16 y, fn_3_1BF08_s16 width, fn_3_1BF08_s16 height,
fn_3_1BF08_s16 texture_width, fn_3_1BF08_s16 texture_height);


extern void fn_3_1B4BC(void *, fn_3_1BF08_s16, fn_3_1BF08_s16, fn_3_1BF08_s16, fn_3_1BF08_s16, fn_3_1BF08_u32 *);


extern fn_3_1BF08_f32 lbl_8006D118(fn_3_1BF08_f32 *, fn_3_1BF08_f32);
extern void fzgx_usef(fn_3_1BF08_f32);
extern void fzgx_used(fn_3_1BF08_f64);
extern void fzgx_usep(void *);
extern fn_3_1BF08_s32 fzgx_sink_s;
extern fn_3_1BF08_u32 fzgx_sink_u;


extern void fn_3_1BF08(void *data, fn_3_1BF08_s16 x1, fn_3_1BF08_s16 y1, fn_3_1BF08_s16 x2, fn_3_1BF08_s16 y2, fn_3_1BF08_u32 *color);



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
fzgx_usef((fn_3_1BF08_f32)fzgx_sink_s);
fzgx_usef((fn_3_1BF08_f32)fzgx_sink_u);
}
__declspec(section ".fzgxpool") void fzgx_pool_primer3(void) {
{
fn_3_1BF08_u32 pair[4] = { 0, 0, 0, 0xBF800000 };
fzgx_usep(pair);
}
fzgx_used(0.5);
}

#pragma section RX ".text"

void fn_3_1BF08(void *data, fn_3_1BF08_s16 x1, fn_3_1BF08_s16 y1, fn_3_1BF08_s16 x2, fn_3_1BF08_s16 y2, fn_3_1BF08_u32 *color) {
fn_3_1BF08_s32 dx = x2 - x1;
fn_3_1BF08_s32 dy = y2 - y1;
fn_3_1BF08_s16 radius;
fn_3_1BF08_f32 scale;
fn_3_1BF08_f32 step;
fn_3_1BF08_f32 k;
fn_3_1BF08_s16 x;
fn_3_1BF08_s16 y;
fn_3_1BF08_s16 d1;
fn_3_1BF08_s16 d2;
fn_3_1BF08_u32 c0;
fn_3_1BF08_u32 c1;
radius = __abs(dx) > __abs(dy) ? __abs(dx) : __abs(dy);
k = lbl_8006D118(&scale, 1.0f);
x = radius * k;
d1 = 2.0f + (1.0f + (fn_3_1BF08_f32)((fn_3_1BF08_f32)(-2.0f * scale) * radius));
d2 = 1.0f + (2.0f + (fn_3_1BF08_f32)((fn_3_1BF08_f32)(-4.0f * scale) * radius));
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
d1 = d1 + (2.0f + ((fn_3_1BF08_f32)(4.0f * y) - (fn_3_1BF08_f32)(4.0f * x)));
d2 = d2 + (2.0f + ((fn_3_1BF08_f32)(4.0f * y) - (fn_3_1BF08_f32)(4.0f * x)));
}
}
}
/* fzgx:end fn_3_1BF08 */
