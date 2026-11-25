#include "types.h"
#include "font.h"
#include "game/pad.h"
#include "dolphin/hw_regs.h"

/* fn_4_250 */
struct fn_4_250_Copy88 { u32 a[22]; };

/* fn_4_250 */
struct fn_4_250_lbl_4_rodata_0 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
};

/* fn_4_2D4 */
typedef struct fn_4_2D4_Color4 {
    u8 c[4];
} fn_4_2D4_Color4;

/* fn_4_2D4 */
typedef struct fn_4_2D4_OptionRow {
    u32 unk_0;
    char *text[6];
} fn_4_2D4_OptionRow;

/* _prolog */
struct _prolog_lbl_4_bss_0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
};

/* _prolog */
struct _prolog_data {
    u8 pad_0[0x1250];
};

/* _prolog */
struct _prolog_lbl_801A6410 {
    u32 unk_0;
};

/* _prolog */
struct _prolog_lbl_1_bss_970 {
    u32 unk_0;
    u8 unk_4;
};

/* _prolog */
struct _prolog_lbl_1_bss_71684 {
    u32 unk_0;
};

/* _prolog */
struct _prolog_lbl_1_bss_6EAD0 {
    u32 unk_0;
};

/* _epilog */
struct OptHandle {
    u32 unk_0;
};

/* _epilog */
struct OptSoundBank {
    u32 unk_0;
    u32 unk_4;
};

/* fn_4_9B0 */
struct fn_4_9B0_lbl_4_data_1260_0_E44 {
    u8 pad_0[0x20];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
};

/* fn_4_9B0 */
struct fn_4_9B0_lbl_4_data_1260 {
    struct fn_4_9B0_lbl_4_data_1260_0_E44 unk_0[1];
};

/* fn_4_A0C */
typedef struct Color4 {
    u8 c[4];
} Color4;

/* fn_4_A0C */
typedef struct OptionRow {
    u32 unk_0;
    char *text[6];
} OptionRow;

/* fn_4_A0C */
struct fn_4_A0C_bss_970 {
    u32 unk_0;
    u8 unk_4;
};

/* fn_4_A0C */
typedef struct RowCounter { u32 value; } RowCounter;

/* fn_4_D10 */
struct fn_4_D10_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
};

/* fn_4_D7C */
struct fn_4_D7C_lbl_1_bss_970 {
    s32 unk_0;
    u8 unk_4;
};

/* fn_4_D7C */
struct fn_4_D7C_lbl_1_bss_6EAB4 {
    u32 unk_0;
};

/* fn_4_D7C */
struct fn_4_D7C_lbl_1_bss_9F8 {
    u8 pad_0[0x8];
    u16 unk_8;
};

/* fn_4_D7C */
struct fn_4_D7C_lbl_4_data_144C {
    s16 unk_0;
    u8 pad_2[0x1A];
};

/* fn_4_EF8 */
typedef struct { s8 x, y; } StickPoint;

/* fn_4_EF8 */
typedef struct { u8 x, y; } CalPair;

/* fn_4_EF8 */
typedef struct { u16 button; s8 stickX; s8 stickY; u8 rest[8]; } CalPad;



/* fn_4_18B8 */
typedef union PPCWGPipe {
    u8 u8;
    u16 u16;
    u32 u32;
    s8 s8;
    s16 s16;
    s32 s32;
    f32 f32;
    f64 f64;
} PPCWGPipe;

/* fn_4_18B8 */
typedef PPCWGPipe WGPipe;

/* fn_4_18B8 */
typedef signed long s32;

/* fn_4_18B8 */
typedef unsigned char u8;

/* fn_4_18B8 */
typedef unsigned short u16;

/* fn_4_18B8 */
typedef unsigned long u32;

/* fn_4_18B8 */
typedef float f32;

/* fn_4_18B8 */
typedef struct {
u8 r, g, b, a;
} GXColor;

/* fn_4_18B8 */
typedef struct {
    u8 x;
    u8 y;
} StickMax;




/* fn_4_3128 */
struct fn_4_3128_Rodata {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x3C];
    f32 unk_48;
    u8 pad_4C[0x4];
    f32 unk_50;
    u8 pad_54[0x4];
    f32 unk_58;
    u8 pad_5C[0x60];
    f32 unk_BC;
    f32 unk_C0;
    f32 unk_C4;
    u8 pad_C8[0x4];
    f32 unk_CC;
    u8 pad_D0[0x1D4 - 0xD0];
    f32 unk_1D4;
    f32 unk_1D8;
    f32 unk_1DC;
    f32 unk_1E0;
};

/* fn_4_347C */
struct fn_4_347C_lbl_1_bss_9C8_0_E12 {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 unk_3;
    u8 pad_4[0x8];
};

/* fn_4_347C */
struct fn_4_347C_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0x46];
    u8 unk_58;
    u8 unk_59;
    u8 unk_5A;
    u8 unk_5B;
    u8 unk_5C;
    u8 unk_5D;
};

/* fn_4_347C */
struct fn_4_347C_lbl_1_bss_9C8 {
    struct fn_4_347C_lbl_1_bss_9C8_0_E12 unk_0[1];
};

/* fn_4_3568 */
typedef volatile u16 vu16;

/* fn_4_3568 */
typedef struct { u32 unk_0; u32 unk_4; } Sig_fn_1_B7F58_Result;

/* fn_4_3568 */
typedef struct { u8 r, g, b, a; } Sig_fn_800081C8_Color;

/* fn_4_3568 */
typedef Sig_fn_800081C8_Color Sig_fn_1_4D4C8_Color4_4D4C8;

/* fn_4_3568 */
struct fn_4_9C14_lbl_4_rodata_0 {
    u8 pad_0[0x8]; f32 unk_8;
    u8 pad_C[0x40]; f32 unk_4C; f32 unk_50;
    u8 pad_54[0x4]; f32 unk_58; u8 pad_5C[0x70]; f32 unk_CC;
    u8 pad_D0[0x58]; f32 unk_128;
    u8 pad_12C[0x10]; f32 unk_13C;
    u8 pad_140[0xD0]; f32 unk_210; u8 pad_214[0x188]; f32 unk_39C; f32 unk_3A0; f32 unk_3A4; f32 unk_3A8;
    u32 unk_3AC; u32 unk_3B0; u32 unk_3B4; u32 unk_3B8; u32 unk_3BC;
    u32 unk_3C0; u32 unk_3C4; u32 unk_3C8; f32 unk_3CC; f32 unk_3D0;
    u8 pad_3D4[8]; f32 unk_3DC; f32 unk_3E0;
    u8 pad_3E4[0xC]; u32 unk_3F0; u32 unk_3F4; f32 unk_3F8;
    f32 unk_3FC; u32 unk_400; u32 unk_404; u32 unk_408; u32 unk_40C;
};

/* fn_4_3568 */
struct fn_4_9C14_Save { u32 words[0x14D8]; };

/* fn_4_3568 */
struct fn_4_9C14_lbl_1_bss_9F8 {
    u8 pad_0[8]; u16 unk_8; u8 pad_A[6]; u16 unk_10; u16 unk_12;
};

/* fn_4_3568 */
struct fn_4_9C14_Request { u8 unk_0; u8 pad_1[3]; u32 unk_4; void *unk_8; void *unk_C; u8 pad_10[0x14]; };

/* fn_4_3568 */
typedef struct { u8 pad_0[8]; u16 unk_8; } CalD58;

/* fn_4_3568 */
typedef struct { u8 pad_0[0xD4]; CalPair d4; u8 p_d6[2]; CalPair d8; u8 p_da[2]; CalPair dc; u8 p_de[2]; struct { CalPair v; u8 p[2]; } oct[8]; } CalRodata;

/* fn_4_3568 */
typedef struct { u16 trig; u8 p_2[6]; u16 rep; u16 unk_A; u8 p_c[8]; } CalPadEnt;

/* fn_4_3568 */
typedef struct { u8 hdr[8]; CalPadEnt e[4]; } CalPads;

/* fn_4_40C4 */
typedef signed short s16;

/* fn_4_40C4 */
typedef double f64;


/* fn_4_40C4 */
struct fn_4_40C4_Copy88 { u32 a[22]; };

/* fn_4_40C4 */
struct fn_4_40C4_lbl_4_rodata_0 {
u8 pad_0[8]; f32 unk_8; u32 color_C; f64 unk_10; f64 unk_18; u8 pad20[8]; f64 unk_28; f64 unk_30; u32 color_38; f32 unk_3C; u32 color_40; f32 unk_44; f32 unk_48; f32 unk_4C; f32 unk_50; f32 unk_54; u8 pad58[8]; f64 unk_60; f64 unk_68; f32 unk_70; u32 pad74; f64 unk_78; u8 pad80[16]; f64 unk_90; u8 pad98[0x2c]; f32 unk_C4; f32 unk_C8; u8 padCC[0x74]; f32 unk_140; u8 pad144[0x54]; f32 unk_198; u32 pad19C; f32 unk_1A0; u8 pad1A4[0x44]; f64 unk_1E8; f32 unk_1F0; f32 unk_1F4; f32 unk_1F8; f32 unk_1FC; f64 unk_200; f64 unk_208; f32 unk_210; f32 unk_214;
};

/* fn_4_40C4 */
struct D { u8 pad[0x20]; char *t20[6]; u8 pad38[0x8e0-0x38]; char *t8E0[8]; char *t900[8]; };

/* fn_4_467C */
struct fn_4_467C_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x2];
    s32 unk_4;
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0xA8];
    u8 unk_BA;
    u8 unk_BB;
    u8 unk_BC;
    u8 unk_BD;
    s8 unk_BE;
    u8 unk_BF;
    u16 unk_C0;
};

/* fn_4_4784 */
struct fn_4_4784_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x2];
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0xA8];
    u8 unk_BA;
    u8 unk_BB;
    u8 pad_BC[0x1];
    u8 unk_BD;
    u8 unk_BE;
    u8 pad_BF[0x1];
    u16 unk_C0;
};

/* fn_4_4834 */
struct fn_4_4834_lbl_4_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x2];
    u8 unk_E;
    u8 pad_F[0x1];
    u16 unk_10;
    u8 pad_12[0xA6];
    u16 unk_B8;
    u8 unk_BA;
    u8 unk_BB;
    u8 unk_BC;
    u8 unk_BD;
    u8 unk_BE;
};

/* fn_4_4834 */
struct fn_4_4834_lbl_1_bss_9F8 {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
};

/* fn_4_4834 */
struct fn_4_4834_lbl_1_bss_718E0 {
    u8 pad_0[0x2];
    u8 unk_2;
};

/* fn_4_4B10 */
struct fn_4_4B10_state {
    u16 unk_0;
    u8 pad_2[0x2];
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0xB4];
    u16 unk_C0;
};

/* fn_4_4B74 */
typedef struct OptionScene {
    char name[32];
    void (*func[3])(void);
} OptionScene;

/* fn_4_4B74 */
typedef struct OptionMenuItem {
    s16 id;
    char *name[6];
} OptionMenuItem;

/* fn_4_4B74 */
typedef struct OptionLabel {
    s16 x, y;
    char *text;
} OptionLabel;

/* fn_4_4B74 */
struct fn_4_4B74_obj {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

/* fn_4_4DF8 */

/* fn_4_4DF8 */
typedef struct fn_4_4DF8_Packet {
    u32 image;
    f32 x, y, z;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 rotation_z, rotation_y;
    f32 alpha;
    u32 flags;
    f32 depth;
    GXColor color, color_add;
    u32 format;
    u16 width, height;
    void *pixels;
    void *secondary;
    void *vertex_callback;
    u32 unk_54;
} fn_4_4DF8_Packet;

/* fn_4_4DF8 */
typedef struct fn_4_4DF8_Bind {
    u16 button[4];
    u32 stick[5];
} fn_4_4DF8_Bind;

/* fn_4_63D4 */
struct fn_4_63D4_bss {
u8 pad_0[0x118];
u8 unk_118;
u8 pad_119[0x2];
u8 unk_11B;
u8 unk_11C;
u8 pad_11D;
u8 unk_11E;
};

/* fn_4_63D4 */
struct fn_4_63D4_rodata {
u8 pad_0[0x8];
f32 unk_8;
u8 pad_C[0x3C];
f32 unk_48;
u8 pad_4C[0x4];
f32 unk_50;
u8 pad_54[0x4];
f32 unk_58;
u8 pad_5C[0x60];
f32 unk_BC;
f32 unk_C0;
f32 unk_C4;
};

/* fn_4_6678 */
struct fn_4_6678_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0x106];
    u8 unk_118;
    u8 pad_119[0x2];
    u8 unk_11B;
    u8 pad_11C[0x2];
    u8 unk_11E;
    u8 pad_11F[0x155];
    u8 unk_274;
};

/* fn_4_6720 */
/* One controller kind's button bindings: four buttons, then five stick/trigger masks. */
typedef struct {
    u16 button[4];
    u32 stick[5];
} PadCfg;

/* fn_4_6720 */
typedef struct {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[0x4];
    u16 trig;    /* 0x08: buttons newly pressed */
    u8 pad_A[0x6];
    u16 rep;     /* 0x10: buttons with auto-repeat */
    u16 unk_12;  /* 0x12: stick directions with auto-repeat */
} PadInput;

/* fn_4_6720 */
typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
} PadD58;

/* fn_4_7C38 */
struct fn_4_7C38_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
};

/* fn_4_7CA4 */
struct fn_4_7CA4_lbl_4_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 unk_C;
    u8 pad_D[0x3];
    u16 unk_10;
};

/* fn_4_80EC */
struct fn_4_80EC_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
};

/* fn_4_8158 */
struct fn_4_8158_lbl_4_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x1];
    u8 unk_D;
    u8 pad_E[0x2];
    u16 unk_10;
};

/* fn_4_82A0 */
struct fn_4_82A0_Bss {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 pad_3[0x27D];
    u8 unk_280;
    u8 unk_281;
    u8 unk_282;
};

/* fn_4_82A0 */
struct fn_4_82A0_Data {
    u8 pad_0[0x2D72];
    u8 unk_2D72;
    u8 pad_2D73;
    s16 unk_2D74;
};

/* fn_4_82A0 */
struct fn_4_82A0_Rodata {
    u8 pad_0[0x8];
    f32 unk_8;
    u32 unk_C;
    f64 unk_10;
    f64 unk_18;
    u8 pad_20[0x8];
    f64 unk_28;
    f64 unk_30;
    u8 pad_38[0xC];
    f32 unk_44;
    f32 unk_48;
    u8 pad_4C[0x4];
    f32 unk_50;
    u8 pad_54[0x4];
    f32 unk_58;
    u8 pad_5C[0x4];
    f64 unk_60;
    f64 unk_68;
    u8 pad_70[0x14];
    f32 unk_84;
    f64 unk_88;
    f64 unk_90;
    f64 unk_98;
    f32 unk_A0;
    u8 pad_A4[0x4];
    f64 unk_A8;
    u8 pad_B0[0x4];
    f32 unk_B4;
    u8 pad_B8[0x4];
    f32 unk_BC;
    f32 unk_C0;
    u8 pad_C4[0x4];
    f32 unk_C8;
    f32 unk_CC;
    u8 pad_D0[0x394 - 0xD0];
    f32 unk_394;
    f32 unk_398;
};

/* fn_4_869C */
struct fn_4_869C_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0x26E];
    u8 unk_280;
    u8 pad_281[0x1];
    u8 unk_282;
    u8 unk_283;
};

/* fn_4_869C */
struct fn_4_869C_lbl_1_bss_718E0 {
    u8 pad_0[0x3];
    u8 unk_3;
};

/* fn_4_8720 */
struct fn_4_8720_lbl_4_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x2];
    u8 unk_E;
    u8 pad_F[0x1];
    u16 unk_10;
    u8 pad_12[0xA6];
    u16 unk_B8;
    u8 pad_BA[0x1C6];
    u8 unk_280;
    u8 unk_281;
    u8 unk_282;
    u8 unk_283;
};

/* fn_4_8720 */
struct fn_4_8720_lbl_1_bss_9F8 {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
};

/* fn_4_8720 */
struct fn_4_8720_lbl_1_bss_718E0 {
    u8 pad_0[0x3];
    u8 unk_3;
};

/* fn_4_89E4 */
struct fn_4_89E4_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
};

/* fn_4_8DC0 */
struct fn_4_8DC0_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0x273];
    u8 unk_285;
    u8 unk_286;
};

/* fn_4_9B20 */
struct fn_4_9B20_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x285];
    u8 unk_291;
    u8 pad_292[0x2];
    u8 unk_294;
    u8 pad_295[0x5383];
    u8 unk_5618;
    u8 unk_5619;
    u8 unk_561A;
    u8 unk_561B;
    u32 unk_561C;
    u8 unk_5620;
    u8 unk_5621;
    u8 unk_5622;
};


extern void ADXT_Stop(u32);
extern int __cntlzw(unsigned int value);
extern void fn_1_1280(u32);
extern s32 fn_1_133DBC;
extern s32 fn_1_134AD4;
extern void fn_1_1380F0(const char *);
extern void fn_1_13ABA8(u32);
extern void fn_1_156884(s32);
extern void fn_1_159440(int, int);
extern void fn_1_1596DC(u32);
extern void fn_1_17C8(s8 *, s8 *, StickPoint *, u8 *);
extern s8 fn_1_1ACC(s8, u8 *, u8 *);
extern u8 fn_1_3BB0(u32);
extern void fn_1_3C78(void);
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_3CF0(u32, u32);
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_407C(u32);
extern void fn_1_411A4(u32);
extern void fn_1_412A0(u32);
extern void fn_1_41A8(void);
extern u32 fn_1_426C(u32);
extern u32 fn_1_435C(u32);
extern s32 fn_1_45D0(u32, u32, u32, u32);
extern u32 fn_1_479F0(s16);
extern void fn_1_47A60(u32);
extern void fn_1_48418(int);
extern void fn_1_484CC(u32);
extern void fn_1_49410(void);
extern void fn_1_49514(GXColor);
extern void fn_1_49528(GXColor);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern u32 fn_1_4A00(u32, u32, u32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4AEB4(f32);
extern u32 fn_1_4AEC0(u32);
extern f32 fn_1_4B040(char *);
extern f32 fn_1_4B068(const char *);
extern f32 fn_1_4B090(const char *);
extern int fn_1_4C10(void);
extern void fn_1_4D0A0(void);
extern void fn_1_4D274(GXColor *, f32);
extern void fn_1_4D2AC(void *, f32, f32);
extern void fn_1_4D494(void);
extern void fn_1_4D4C8(GXColor, f32, f32);
extern void fn_1_4DC20(void);
extern void fn_1_4DC6C(void);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_4FD64(void);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height, s16 texture_width, s16 texture_height);
extern void fn_1_5233C(void);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern void fn_1_53E40(void *, f32, f32, f32, f32, f32, char *);
s32 fn_1_A176C(u32, s32);
extern void fn_1_A2D84(u32);
extern s8 fn_1_A5DC4(void);
extern void fn_1_A6840(u32);
extern void fn_1_AA6D8(u32, u32, void *);
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7C5C(void);
extern int fn_1_B7CD4(void);
extern void fn_1_B7CE4(u32, void *);
extern void fn_1_B7E14(void *);
extern s32 fn_1_B7E98(u32);
extern int fn_1_B7F58(Sig_fn_1_B7F58_Result *);
extern s32 fn_1_B800C(u32);
extern u32 fn_1_B80F0(u32);
extern u32 fn_1_B8170(u32);
extern void fn_1_B9904(u32, u32, u32, u32);
extern u32 fn_1_B9C0C(void);
extern s8 fn_1_BA144(u32 *);
extern u32 fn_1_BC310(void *);
extern u32 fn_1_C0510(u32);
extern u32 fn_1_C1394(void *);
extern void fn_1_C34F0(void);
extern u32 fn_1_C3688(void);
extern u32 fn_1_F70D0(u32);
extern void fn_1_F7128(void);
extern u32 fn_1_F7308(void);
extern void fn_1_F73A8(s32, u32, u32);
extern void fn_1_F755C(u8);
extern u32 fn_1_F7568(void);
extern s32 fn_1_F7954(void);
extern void fn_1_F7A20(void);
extern u32 fn_80007F70(GXColor *, GXColor *, u8, f32);
extern GXColor fn_800081C8(GXColor, GXColor, f32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800371F8(s32, GXColor);
extern void fn_8004BF0C(u32, s32);
extern u32 fn_8004CD70(u32, u32, u32);
extern void fn_8006CD20(f32, f32);
extern void fn_8006CD2C(f32 *, f32 *);
extern void fn_8006CD50(void);
extern void fn_8006CE1C(f32);
extern void fn_80072344(void);
extern void fn_80072378(void);
extern void fn_8007245C(u32);
extern void fn_80072558(void);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_80074660(u32);
extern void fn_800746A8(u8, s32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8, s32, u8);
extern s32 fn_8008023C(void *, void *, u32);
extern char *strcpy(char *, const char *);
extern struct fn_4_D7C_lbl_1_bss_6EAB4 lbl_1_bss_6EAB4;
extern struct _prolog_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern u32 lbl_1_bss_7167C;
extern u32 lbl_1_bss_71680;
extern struct _prolog_lbl_1_bss_71684 lbl_1_bss_71684;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern u32 *lbl_1_bss_718C0;
/* main.rel's save block (0x59E8 bytes): the option settings it keeps. */
typedef struct {
    u16 unk_0;
    u8 unk_2;
    u8 unk_3;
    u8 pad_4[4];
    StickPoint cal_gate[4][8];
    CalPair cal_center[4];
    PadCfg pad_cfg[4][3];
    u8 pad_1A0[0x5382];
    char unk_5522[0x20];
    StickMax cal_max[4];
    StickMax cal_dead[4];
    u8 pad_5552[4];
    u8 rumble[4];
    u8 pad_555A[0x48E];
} OptionSave;
extern OptionSave lbl_1_bss_718E0;
extern u32 lbl_1_bss_7F0C0[0x14D8];
extern u8 lbl_1_bss_8B3A0[];
extern s16 lbl_1_bss_960;
extern s16 lbl_1_bss_962;
extern u16 lbl_1_bss_968;
extern u16 lbl_1_bss_96A;
extern struct fn_4_D7C_lbl_1_bss_970 lbl_1_bss_970;
extern u32 lbl_1_bss_980[4];
extern CalPad lbl_1_bss_9C8[4];
extern PadInput lbl_1_bss_9F8[4];
extern PadCfg lbl_1_bss_AA0[4][3];
extern PadInput lbl_1_bss_D58;
extern StickPoint lbl_1_data_2AC0[4][8];
extern CalPair lbl_1_data_2B40[4];
extern StickMax lbl_1_data_2B50[4];
extern StickMax lbl_1_data_2B58[4];
extern u8 lbl_1_data_2B60[4];
extern PadCfg lbl_1_rodata_108[3];
extern FontDrawPacket lbl_1_rodata_26F8;
extern f32 lbl_8006D188(s16);
extern s32 lbl_8006D24C(f32, f32);
extern void lbl_8006D758(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern u32 lbl_801A6410;
extern s32 lbl_801A66B4;
extern void *memcpy(void *, const void *, u32);
extern int sprintf(char *, const char *, ...);
extern char *strcat(char *, const char *);

void fn_4_250(void);
void fn_4_2D4(u32 arg0, char *arg1);
void _prolog(void);
void fn_4_800(void);
void fn_4_894(void);
void _epilog(void);
void fn_4_9B0(void);
void fn_4_A0C(void);
void fn_4_D10(void);
void fn_4_D7C(void);
void fn_4_EA0(void);
void fn_4_EF8(s32 port);
void fn_4_1444(u16 depth, s32 left, GXColor border, GXColor fill, const char *text);
void fn_4_18B8(void);
void fn_4_2394(char *label, s32 right, u16 depth, GXColor outline, GXColor fill, s32 value);
void fn_4_2700(u16 depth, GXColor outline, GXColor fill, f32 width, f32 height);
void fn_4_28FC(void);
void fn_4_3128(void);
void fn_4_347C(void);
void fn_4_3568(void);
void fn_4_406C(void);
void fn_4_40C4(u32 arg0, char *arg1);
void fn_4_467C(void);
void fn_4_4784(void);
void fn_4_4834(void);
void fn_4_4B10(void);
s32 fn_4_4B74(u32 arg0, u32 arg1);
void fn_4_4CB8(s32 arg0, u32 arg1, u32 arg2);
void fn_4_4DF8(void);
void fn_4_63D4(void);
void fn_4_6678(void);
void fn_4_6720(void);
void fn_4_78E0(void);
void fn_4_7938(void);
void fn_4_7C38(void);
void fn_4_7CA4(void);
void fn_4_7D94(void);
void fn_4_7DEC(void);
void fn_4_80EC(void);
void fn_4_8158(void);
void fn_4_8248(void);
void fn_4_82A0(void);
void fn_4_869C(void);
void fn_4_8720(void);
void fn_4_898C(void);
void fn_4_89E4(void);
void fn_4_8A54(void);
void fn_4_8AE0(void);
void fn_4_8B3C(void);
void fn_4_8DC0(void);
void fn_4_8E38(void);
void fn_4_9A78(void);
void fn_4_9AD0(void);
void fn_4_9B20(void);
void fn_4_9C14(void);
void fn_4_A734(void);
void fn_4_A78C(u8 *arg0);
u8 *fn_4_A82C(u8 *s);

/* name_entry.c (the next translation unit of the module) */
void fn_4_AB30(void);
void fn_4_AB90(void);
u32 fn_4_ABB0(void);
void fn_4_AC58(void);
void fn_4_D1A8(u32 arg0, u32 arg1, u8 arg2);
s32 fn_4_D420(void);
void fn_4_D760(void);
void fn_4_D848(u8 *arg0);
void fn_4_D878(void);
/* .bss, in address order. Zero-initialized definitions keep their source order. */
u16 lbl_4_bss_0 = 0;
u8 lbl_4_bss_2 = 0;
u32 lbl_4_bss_4 = 0;
u32 lbl_4_bss_8 = 0;
u8 lbl_4_bss_C = 0;
u8 lbl_4_bss_D = 0;
u8 lbl_4_bss_E = 0;
u16 lbl_4_bss_10 = 0;
u8 lbl_4_bss_12 = 0;
u8 lbl_4_bss_13 = 0;
CalPair lbl_4_bss_14;
StickMax lbl_4_bss_18;
StickMax lbl_4_bss_1C;
u8 lbl_4_bss_1E;
StickPoint lbl_4_bss_20[8];
StickPoint lbl_4_bss_30[8];
StickPoint lbl_4_bss_40[8];
f32 lbl_4_bss_50;
f32 lbl_4_bss_54;
s8 lbl_4_bss_58;
s8 lbl_4_bss_59;
u8 lbl_4_bss_5A;
u8 lbl_4_bss_5B;
u8 lbl_4_bss_5C;
u8 lbl_4_bss_5D;
StickPoint lbl_4_bss_60[4][8];
CalPair lbl_4_bss_A0[4];
StickMax lbl_4_bss_A8[4];
StickMax lbl_4_bss_B0[4];
u16 lbl_4_bss_B8;
u8 lbl_4_bss_BA;
u8 lbl_4_bss_BB;
u8 lbl_4_bss_BC;
u8 lbl_4_bss_BD;
u8 lbl_4_bss_BE;
u16 lbl_4_bss_C0;
PadCfg lbl_4_bss_C4[3];
u8 lbl_4_bss_118;
u8 lbl_4_bss_119;
u8 lbl_4_bss_11A;
u8 lbl_4_bss_11B;
u8 lbl_4_bss_11C;
u8 lbl_4_bss_11D;
u8 lbl_4_bss_11E;
PadCfg lbl_4_bss_120[4][3];
u8 lbl_4_bss_270[4];
u8 lbl_4_bss_274;
s32 lbl_4_bss_278;
u32 lbl_4_bss_27C;
u8 lbl_4_bss_280;
u8 lbl_4_bss_281;
u8 lbl_4_bss_282;
u8 lbl_4_bss_283;
u8 lbl_4_bss_284;
u8 lbl_4_bss_285;
u8 lbl_4_bss_286;
s32 lbl_4_bss_288;
s32 lbl_4_bss_28C;
u8 lbl_4_bss_290;
u8 lbl_4_bss_291;
u8 lbl_4_bss_294[0x21];
u32 lbl_4_bss_2B8[0x14D8];
u8 lbl_4_bss_5618;
u8 lbl_4_bss_5619;
u8 lbl_4_bss_561A;
u8 lbl_4_bss_561B;
u32 lbl_4_bss_561C;
u8 lbl_4_bss_5620;
u8 lbl_4_bss_5621;
u8 lbl_4_bss_5622;
u32 lbl_4_bss_5624;

/* option .data 0x0-0x2974: the message tables (English, four empty languages,
   Japanese), the scene table and the strings and statics of the functions
   before this one. The retail TU defines them above these functions. */

/* Where a binding row's prompt is printed, and its text. */

char *lbl_4_data_20[6] = {
    "Controller", "", "", "", "", "\203R\203\223\203g\203\215\201[\203\211",
};

char *lbl_4_data_60[6] = {
    "Controller Socket", "", "", "", "", "\203R\203\223\203g\203\215\201[\203\211\203|\201[\203g",
};

char *lbl_4_data_80[2][6] = {
    {"ON", "", "", "", "", "ON"},
    {"OFF", "", "", "", "OFF"},
};

char *lbl_4_data_E8[6] = {
    "Use \203\255 or \203\265 to choose.", "", "", "", "", "\203\255\202\251\203\265\202\305\215\200\226\332\202\360\221I\202\361\202\305\202\255\202\276\202\263\202\242\201B",
};

char *lbl_4_data_158[6] = {
    "Move \203\255 or \203\265 Left or Right to change controls.", "", "", "", "", "\203\255\202\251\203\265\202\314\215\266\211E\202\305\221\200\215\354\202\360\225\317\215X\202\265\202\304\202\255\202\276\202\263\202\242\201B",
};

char *lbl_4_data_1A4[6] = {
    "Please wait a moment...", "", "", "", "", "\202\265\202\316\202\347\202\255\202\250\221\322\202\277\202\255\202\276\202\263\202\242\201B",
};

char *lbl_4_data_23C[6] = {
    "Press the A Button on the Controller to be adjusted. Press the B Button to finish.", "", "", "", "", "\225\317\215X\202\267\202\351\203R\203\223\203g\203\215\201[\203\211\202\305\203\237\202\360\211\237\202\265\202\304\202\255\202\276\202\263\202\242\201B",
};

char *lbl_4_data_2B4[6] = {
    "Rotate the Control Stick one full revolution.", "", "", "", "", "\203R\203\223\203g\203\215\201[\203\213\203X\203e\203B\203b\203N\202\360\210\352\224t\202\311\211\361\202\265\202\304\202\255\202\276\202\263\202\242\201B",
};

char *lbl_4_data_314[6] = {
    "Please adjust the steering wheel.", "", "", "", "", "\203n\203\223\203h\203\213\202\314\222\262\220\256\202\360\215s\202\310\202\301\202\304\202\255\202\276\202\263\202\242\201B",
};

char *lbl_4_data_364[6] = {
    "Return to the default settings?", "", "", "", "", "\217\211\212\372\220\335\222\350\202\311\226\337\202\265\202\334\202\267\202\251\201H",
};

char *lbl_4_data_3E8[6] = {
    "Select the Controller to be changed using either \203\255 or \203\265.", "", "", "", "", "\203\255\202\251\203\265\202\305\225\317\215X\202\267\202\351\203R\203\223\203g\203\215\201[\203\211\202\360\221I\202\361\202\305\202\255\202\276\202\263\202\242\201B",
};

char *lbl_4_data_468[6] = {
    "Move \203\255 or \203\265 Left or Right to change Rumble settings.", "", "", "", "", "\203\255\202\251\203\265\202\314\215\266\211E\202\305\220U\223\256\202\314\220\335\222\350\202\360\225\317\215X\202\265\202\304\202\255\202\276\202\263\202\242\201B",
};

char *lbl_4_data_560[6] = {
    "The Controller has been disconnected.\n Reconnect the Controller in Socket %d or\n press the A Button on another.", "", "", "", "", "\203R\203\223\203g\203\215\201[\203\211\202\252\212O\202\263\202\352\202\334\202\265\202\275\201B\n\203R\203\223\203g\203\215\201[\203\211\203|\201[\203g%d\202\311\202\263\202\265\202\310\202\250\202\267\202\251\201A\n\221\274\202\314\203R\203\223\203g\203\215\201[\203\211\202\305\203\237\203{\203^\203\223\202\360\211\237\202\265\202\304\202\255\202\276\202\263\202\242\201B",
};

char *lbl_4_data_584[6] = {
    "YES", "", "", "", "", "\202\315\202\242",
};

char *lbl_4_data_5A8[6] = {
    "NO", "", "", "", "", "\202\242\202\242\202\246",
};

char *lbl_4_data_5F8[6] = {
    "Change Option Settings", "", "", "", "", "\203I\203v\203V\203\207\203\223\220\335\222\350\202\360\215s\202\310\202\242\202\334\202\267\201B",
};

char *lbl_4_data_6BC[6] = {
    "Adjust the Calibration.\nPress the A Button on the Controller\nyou want adjusted.", "", "", "", "", "\203R\203\223\203g\203\215\201[\203\211\202\314\203L\203\203\203\212\203u\203\214\201[\203V\203\207\203\223\202\360\215s\202\310\202\242\202\334\202\267\201B\n\225\317\215X\202\267\202\351\203R\203\223\203g\203\215\201[\203\211\202\305\203\237\202\360\211\237\202\265\202\304\202\255\202\276\202\263\202\242\201B",
};

char *lbl_4_data_778[6] = {
    "Customize the Controller.\nPress the A Button on the Controller to be adjusted.", "", "", "", "", "\203R\203\223\203g\203\215\201[\203\211\202\314\203J\203X\203^\203}\203C\203Y\202\360\215s\202\310\202\242\202\334\202\267\201B\n\225\317\215X\202\267\202\351\203R\203\223\203g\203\215\201[\203\211\202\305\203\237\202\360\211\237\202\265\202\304\202\255\202\276\202\263\202\242\201B",
};

char *lbl_4_data_82C[6] = {
    "Controller Rumble Settings.\n Press the A Button to select the Controller.", "", "", "", "", "\203R\203\223\203g\203\215\201[\203\211\202\314\220U\223\256\202\314\220\335\222\350\202\360\215s\202\310\202\242\202\334\202\267\201B\n\203R\203\223\203g\203\215\201[\203\211\202\360\221I\202\361\202\305\203\237\202\360\211\237\202\265\202\304\202\255\202\276\202\263\202\242\201B",
};

char *lbl_4_data_844[6] = {
    "Move \203\255 or \203\265 Left or Right to change Rumble settings.", "", "", "", "", "\203\255\202\251\203\265\202\314\215\266\211E\202\305\220U\223\256\202\314\220\335\222\350\202\360\225\317\215X\202\265\202\304\202\255\202\276\202\263\202\242\201B",
};

char *lbl_4_data_884[6] = {
    "Save changes?", "", "", "", "", "\225\317\215X\202\360\225\333\221\266\202\265\202\334\202\267\202\251\201H",
};

char *lbl_4_data_8C0[6] = {
    "Is this OK?", "", "", "", "", "\202\261\202\352\202\305\202\346\202\353\202\265\202\242\202\305\202\267\202\251\201H",
};

char *lbl_4_data_8E0[6] = {
    "\201c\202n\202m", "", "", "", "", "\201c\202n\202m",
};

char *lbl_4_data_900[6] = {
    "\202n\202e\202e", "", "", "", "", "\202n\202e\202e",
};

char *lbl_4_data_958[6] = {
    "Change Controller Settings", "", "", "", "", "\203R\203\223\203g\203\215\201[\203\211\202\314\220\335\222\350\202\360\215s\202\310\202\242\202\334\202\267\201B",
};

char *lbl_4_data_9A8[6] = {
    "Manage Memory Card", "", "", "", "", "\203\201\203\202\203\212\201[\203J\201[\203h\202\314\212\307\227\235\202\360\215s\202\310\202\242\202\334\202\267\201B",
};

char *lbl_4_data_9F8[6] = {
    "Select Screen Settings ", "", "", "", "", "\211\346\226\312\203\202\201[\203h\202\314\220\335\222\350\202\360\215s\202\310\202\242\202\334\202\267\201B",
};

char *lbl_4_data_A58[6] = {
    "Use \203\255 or \203\265 to choose a mode ", "", "", "", "", "\203\255\202\251\203\265\202\314\215\266\211E\202\305\203\202\201[\203h\202\360\221I\202\361\202\305\202\255\202\276\202\263\202\242\201B",
};

char *lbl_4_data_A88[6] = {
    "Normal", "", "", "", "", "\203m\201[\203}\203\213\203e\203\214\203r",
};

char *lbl_4_data_ABC[6] = {
    "Wide Screen", "", "", "", "", "\203\217\203C\203h\203e\203\214\203r",
};

char *lbl_4_data_C00[6] = {
    "Move the Control Stick around in a circle until the figures on the\n left side do not change. Adjust play using the \203\265 Control Pad.\n Press the X Button to return to the default settings.", "", "", "", "", "\215\266\221\244\202\314\220}\214`\202\252\225\317\211\273\202\265\202\310\202\255\202\310\202\351\202\334\202\305\203\255\202\360\210\352\224t\202\311\211\361\202\265\202\304\202\255\202\276\202\263\202\242\201B\n\203\265\202\305\227V\202\321\202\360\222\262\220\256\202\265\202\304\202\255\202\276\202\263\202\242\201B\n\203\264\202\305\217\211\212\372\220\335\222\350\202\311\226\337\202\271\202\334\202\267\201B",
};

char *lbl_4_data_D38[6] = {
    "Turn the steering wheel Left and Right and press\nthe A Button at the point you want to set as the\n limit. Use the L and R Buttons to adjust game play. ", "", "", "", "", "\203n\203\223\203h\203\213\202\360\215\266\211E\202\311\211\361\202\265\201A\214\300\212E\202\306\202\265\202\275\202\242\210\312\222u\202\305\203\237\202\360\211\237\202\265\202\304\202\255\202\276\202\263\202\242\201B\n\202k\201\225\202q\203g\203\212\203K\201[\203{\203^\203\223\202\305\227V\202\321\202\360\222\262\220\256\202\265\202\304\202\255\202\276\202\263\202\242\201B\n\203\264\202\305\217\211\212\372\220\335\222\350\202\311\226\337\202\271\202\334\202\267\201B",
};

char *lbl_4_data_D6C[6] = {
    "Before correction", "", "", "", "", "\225\342\220\263\221O",
};

char *lbl_4_data_DA0[6] = {
    "After correction", "", "", "", "", "\225\342\220\263\214\343",
};

char *lbl_4_data_E30[6] = {
    "Game Data Controls\nInsert a Memory Card into Slot A.", "", "", "", "", "\203Q\201[\203\200\203f\201[\203^\202\314\221\200\215\354\n\203\201\203\202\203\212\201[\203J\201[\203h\202\360\203X\203\215\203b\203g\202`\202\311\223\374\202\352\202\304\202\255\202\276\202\263\202\242\201B",
};

char *lbl_4_data_E70[6] = {
    "Load Game Data", "", "", "", "", "\203Q\201[\203\200\203f\201[\203^\202\314\203\215\201[\203h",
};

char *lbl_4_data_EB0[6] = {
    "Save Game Data", "", "", "", "", "\203Q\201[\203\200\203f\201[\203^\202\314\203Z\201[\203u",
};

char *lbl_4_data_F4C[6] = {
    "There is no Game Data on this Memory Card.\n Saving new data.", "", "", "", "", "\203\201\203\202\203\212\201[\203J\201[\203h\202\311\n\203Q\201[\203\200\203f\201[\203^\202\252\214\251\202\302\202\251\202\350\202\334\202\271\202\361\201B\n\220V\213K\203Z\201[\203u\202\265\202\334\202\267\201B",
};

char *lbl_4_data_1064[6] = {
    "There is no Game Data on the Memory Card.\nIf you save, the Game Data currently loaded\nwill all be lost. Is that OK?", "", "", "", "", "\203\201\203\202\203\212\201[\203J\201[\203h\202\311\203Q\201[\203\200\203f\201[\203^\202\252\214\251\202\302\202\251\202\350\202\334\202\271\202\361\201B\n\220V\213K\203Z\201[\203u\202\267\202\351\202\306\214\273\215\335\203\215\201[\203h\202\263\202\352\202\304\202\242\202\351\203Q\201[\203\200\203f\201[\203^\202\252\n\221S\202\304\217\301\202\246\202\304\202\265\202\334\202\242\202\334\202\267\202\252\201A\202\346\202\353\202\265\202\242\202\305\202\267\202\251?",
};

char *lbl_4_data_10D0[6] = {
    "There is no Memory Card in Slot A.", "", "", "", "", "\203X\203\215\203b\203g\202`\202\311\n\203\201\203\202\203\212\201[\203J\201[\203h\202\252\214\251\202\302\202\251\202\350\202\334\202\271\202\361\201B",
};

char *lbl_4_data_1154[6] = {
    "Register this name on the Memory Card in Slot A.", "", "", "", "", "\202\261\202\314\226\274\221O\202\305\203\201\203\202\203\212\201[\203J\201[\203h\202\311\n\223o\230^\202\265\202\304\202\340\202\346\202\353\202\265\202\242\202\305\202\267\202\251?",
};

char *lbl_4_data_11F4[6] = {
    "There is no Memory Card in Slot A.\n The game cannot be saved.", "", "", "", "", "\203X\203\215\203b\203g\202`\202\311\203\201\203\202\203\212\201[\203J\201[\203h\202\252\214\251\202\302\202\251\202\350\202\334\202\271\202\361\201B\n\203Z\201[\203u\202\305\202\253\202\334\202\271\202\361\202\305\202\265\202\275\201B",
};

u8 lbl_4_data_120C = 0xFFU;

s16 lbl_4_data_120E = -1;

char lbl_4_data_1210[3] = "%s";

u8 lbl_4_data_1213 = 0xFFU;

s16 lbl_4_data_1214 = -1;

/* fzgx:begin fn_4_0 noprologue */
#include "types.h"
#include "game/pad.h"

/* A pad state (0x14 bytes); lbl_1_bss_9F8 holds one per port. */
typedef struct {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[0x4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[0x4];
    u16 unk_10;
    u16 unk_12;
} fn_4_0_Pad;

extern fn_4_0_Pad lbl_1_bss_9F8[4];

extern void fn_1_A2D84(u32);

s32 fn_4_0(u32 out0, u32 a, u32 b, s32 index, u32 select)
{
    u32 x, y;
    s32 n;
    u32 res, mid;

    n = 0;
    res = out0;
    if (index == -1) {
        if (select == 0) {
            x = PAD_BIT(lbl_1_bss_9F8[0].unk_10, 3) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 3);
            y = PAD_BIT(lbl_1_bss_9F8[0].unk_10, 2) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 2);
        } else {
            x = PAD_BIT(lbl_1_bss_9F8[0].unk_10, 0) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 0);
            y = PAD_BIT(lbl_1_bss_9F8[0].unk_10, 1) || PAD_BIT(lbl_1_bss_9F8[0].unk_12, 1);
        }
    } else {
        if (select == 0) {
            x = PAD_BIT(lbl_1_bss_9F8[index].unk_10, 3) || PAD_BIT(lbl_1_bss_9F8[index].unk_12, 3);
            y = PAD_BIT(lbl_1_bss_9F8[index].unk_10, 2) || PAD_BIT(lbl_1_bss_9F8[index].unk_12, 2);
        } else {
            x = PAD_BIT(lbl_1_bss_9F8[index].unk_10, 0) || PAD_BIT(lbl_1_bss_9F8[index].unk_12, 0);
            y = PAD_BIT(lbl_1_bss_9F8[index].unk_10, 1) || PAD_BIT(lbl_1_bss_9F8[index].unk_12, 1);
        }
    }
    if (x) n = -1;
    if (y) n++;
    if ((b - a) == 1) {
        if (n == -1) res = a;
        else if (n == 1) res = b;
    } else {
        mid = out0 + n;
        if ((s32)mid < (s32)a) res = b;
        else if (mid > b) res = a;
        else res = mid;
    }
    if (out0 != res) fn_1_A2D84(0xA9010000);
    return res;
}
/* fzgx:end fn_4_0 */

/* fzgx:begin fn_4_250 */
void fn_4_250(void) {
    f32 v0;
    f32 v1;
    FontDrawPacket loc_8;
    /* frame */
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v0 = (167.0f);
    v1 = (38.0f);
    loc_8.image = (0x10000 - 28668);
    loc_8.x = v0;
    loc_8.y = v1;
    loc_8.z = (0.5f);
    loc_8.flags = 10;
    fn_1_4F734((FontDrawPacket *)&loc_8);
}
/* fzgx:end fn_4_250 */

/* fzgx:begin fn_4_2D4 */
static inline f64 fn_4_2D4_operand(f64 right, f64 left) { return left + right; }

static void option_draw_cursor(f32 x, f32 y, f32 z, f32 w, f32 h, f32 scale) {
    static const fn_4_2D4_Color4 color = {0x00, 0xD0, 0xD0, 0x00};
    FontDrawPacket packet;

    packet = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
    packet.image = 0x12;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.scale_x = (w + 78.0 * scale) / 8.0;
    packet.scale_y = (h + 28.0 * scale) / 8.0;
    packet.flags = 10;
    packet.alpha = 0.3 * (1.0 + lbl_8006D188(((lbl_4_bss_2 << 10) + 0x4000)));
    *(fn_4_2D4_Color4 *)packet.color = color;
    fn_1_4F734(&packet);
}

static void option_draw_cursor_dim(f32 x, f32 y, f32 z, f32 w, f32 h, f32 scale) {
    static const fn_4_2D4_Color4 color = {0x00, 0xD0, 0xD0, 0x00};
    FontDrawPacket packet;

    packet = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
    packet.image = 0x12;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.scale_x = (w + 78.0 * scale) / 8.0;
    packet.scale_y = (h + 28.0 * scale) / 8.0;
    packet.flags = 10;
    packet.alpha = 0.6f;
    *(fn_4_2D4_Color4 *)packet.color = color;
    fn_1_4F734(&packet);
}

static void option_draw_mark(f32 x, f32 y, f32 z, f32 w) {
    static const fn_4_2D4_Color4 color = {0xFF, 0x00, 0x00, 0x00};
    FontDrawPacket packet;

    packet = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
    packet.image = 0x12;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.scale_x = w / 8.0;
    packet.scale_y = 3.5f;
    packet.flags = 9;
    packet.alpha = 0.3 * (1.0 + lbl_8006D188(((lbl_4_bss_2 << 10) + 0x4000)));
    *(fn_4_2D4_Color4 *)packet.color = color;
    fn_1_4F734(&packet);
}

static void option_draw_menu(OptionMenuItem *rows, u32 count, u8 *index) {
    OptionMenuItem *entry;
    u32 row;
    u32 cursor;
    u32 i;
    f32 width;
    f32 w;
    f32 height;

    cursor = *index;
    fn_1_49410();
    fn_1_495C8(9);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    width = 0.0f;
    for (i = 0, row = 0, entry = rows; i < count; i++, row += 2, entry++) {
        fn_1_496FC(320.0f, (row - (count - 1)) * 24 + 240);
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(0.5f);
        }
        fn_1_4AE0C(lbl_4_data_1210, entry->name[lbl_801A66B4]);
        w = fn_1_4B040(entry->name[lbl_801A66B4]);
        if (w > width) {
            width = w;
        }
    }
    if (lbl_4_data_120C != cursor || lbl_4_data_120E != lbl_1_bss_962) {
        lbl_4_bss_2 = 0;
        lbl_4_data_120C = cursor;
        lbl_4_data_120E = lbl_1_bss_962;
    }
    option_draw_cursor(320.0f, (cursor * 2 - (count - 1)) * 24 + 240, 0.15f, width, 0.0f, 1.0f);
    height = (count * 2 - 1) * 24;
    fn_1_53BD8(0, 320.0f, 240.0f, 96.0 + width, 48.0 + height, 0.25f);
}

void fn_4_2D4(u32 arg0, char *arg1) {
    f32 width;
    f32 span;
    f32 left;
    f32 right;
    FontDrawPacket packet;
    f32 height;

    fn_1_49410();
    fn_1_495C8(9);
    fn_1_4954C(0.005f);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    fn_1_496FC(320.0f, 216.0f);
    fn_1_4AE0C(lbl_4_data_1210, arg1);
    width = fn_1_4B040(arg1);
    left = fn_1_4B040(lbl_4_data_584[lbl_801A66B4]);
    right = fn_1_4B040(lbl_4_data_5A8[lbl_801A66B4]);
    if (left > right) {
        right = left;
    }
    span = 90.0 + right;
    fn_1_496FC(320.0 - 0.5 * span, 264.0f);
    fn_1_4AE0C(lbl_4_data_1210, lbl_4_data_584[lbl_801A66B4]);
    fn_1_496FC(320.0 + 0.5 * span, 264.0f);
    fn_1_4AE0C(lbl_4_data_1210, lbl_4_data_5A8[lbl_801A66B4]);
    if (span + right > width) {
        width = span + right;
    }
    if (lbl_4_data_1213 != arg0 || lbl_4_data_1214 != lbl_1_bss_962) {
        lbl_4_bss_2 = 0;
        lbl_4_data_1213 = arg0;
        lbl_4_data_1214 = lbl_1_bss_962;
    }
    option_draw_cursor(320.0 + (f64)(span * (arg0 == 0 ? -0.5 : 0.5)), 264.0f, 0.015f, right, 0.0f, 1.0f);
    height = 72.0f;
    fn_1_53BD8(0, 320.0f, 240.0f, 96.0 + width, 48.0 + height, 0.025f);
}
/* fzgx:end fn_4_2D4 */

/* fzgx:begin _prolog */
void _prolog(void) {
    lbl_4_bss_4 = fn_1_45D0(lbl_801A6410, 0xE3C, (u32)"option.c", 0x320);
    lbl_4_bss_8 = fn_1_45D0(lbl_801A6410, 0xE3C, (u32)"option.c", 0x321);
    fn_1_3CF0(lbl_4_bss_4, 0x40);
    fn_1_3CF0(lbl_4_bss_8, 0x40);
    fn_1_435C(lbl_4_bss_4);
    fn_1_435C(lbl_4_bss_8);
    fn_1_3F8C((u32)"SelS_DispPolygonBG", (u32)&fn_1_133DBC, 0, 0x11);
    fn_1_3F8C((u32)"SelS_DispSpriteBG", (u32)&fn_1_134AD4, 0, 0x11);
    fn_1_3F8C((u32)"option_common_disp", (u32)&fn_4_250, 0, 0x11);
    lbl_1_bss_970.unk_0 = 0;
    lbl_1_bss_970.unk_4 = 0;
    lbl_4_bss_C = 0;
    lbl_4_bss_D = 0;
    lbl_1_bss_96A = 0x4B;
    lbl_4_bss_E = 0;
    lbl_1_bss_7167C = (u32)&fn_4_800;
    lbl_1_bss_71680 = (u32)&fn_4_894;
    lbl_1_bss_71684.unk_0 = (u32)&fn_4_9B0;
    fn_1_411A4(1);
    fn_1_479F0(3);
    fn_1_48418(2);
    fn_1_159440(2, 0);
    if (lbl_1_bss_6EAD0.unk_0 != 0) {
        if (*(u32 *)lbl_1_bss_6EAD0.unk_0 == 0) {
            *(u32 *)lbl_1_bss_6EAD0.unk_0 = fn_8004CD70(2, lbl_1_bss_6EAD0.unk_0 + 0x10, 0x25124);
        }
        if (*(u32 *)(lbl_1_bss_6EAD0.unk_0 + 4) == 0) {
            *(u32 *)(lbl_1_bss_6EAD0.unk_0 + 4) = fn_8004CD70(2, lbl_1_bss_6EAD0.unk_0 + 0x4A258, 0x25124);
        }
        fn_1_A176C(*(u32 *)lbl_1_bss_6EAD0.unk_0, 0x37);
    }
}

OptionScene lbl_4_data_1260[10] = {
    {"SMD_OPTION_MENU", {fn_4_D10, fn_4_D7C, fn_4_EA0}},
    {"SMD_OPTION_SAVE_WAIT", {(void (*)(void))fn_4_9B20, (void (*)(void))fn_4_9C14, fn_4_A734}},
    {"SMD_OPTION_CTRL_MENU", {fn_4_7C38, fn_4_7CA4, fn_4_7D94}},
    {"SMD_OPTION_CARD_MENU", {fn_4_80EC, fn_4_8158, fn_4_8248}},
    {"SMD_OPTION_WIDE", {fn_4_869C, fn_4_8720, fn_4_898C}},
    {"SMD_OPTION_CALIB", {fn_4_347C, fn_4_3568, fn_4_406C}},
    {"SMD_OPTION_RUMBLE", {fn_4_4784, fn_4_4834, fn_4_4B10}},
    {"SMD_OPTION_PCUST", {fn_4_6678, fn_4_6720, fn_4_78E0}},
    {"SMD_OPTION_CARD_MANAGE", {fn_4_89E4, fn_4_8A54, fn_4_8AE0}},
    {"SMD_OPTION_CARD_GDATA", {fn_4_8DC0, fn_4_8E38, fn_4_9A78}},
};
/* fzgx:end _prolog */

/* fzgx:begin fn_4_800 */
void fn_4_800(void) {
    u8 value;

    value = lbl_4_bss_2;
    lbl_4_bss_2 = value + 1;

    switch (lbl_1_bss_970.unk_0) {
    case 0:
        break;
    case 1:
        fn_1_4A00(0, 15, lbl_4_bss_8);
        lbl_1_bss_970.unk_0 = 2;
        break;
    case 2:
        if (fn_1_4C10() == 0) {
            lbl_1_bss_968 = 1;
        }
        break;
    default:
        break;
    }
}
/* fzgx:end fn_4_800 */

/* fzgx:begin fn_4_894 */
// Initializes both option subsystems in sequence.

void fn_4_894(void) {
    u32 first_state;
    u32 second_state;

    first_state = fn_1_435C(lbl_4_bss_4);
    first_state = fn_1_407C(first_state);
    fn_1_3CC4(first_state);

    second_state = fn_1_435C(lbl_4_bss_8);
    fn_1_407C(second_state);
}
/* fzgx:end fn_4_894 */

/* fzgx:begin _epilog */
// Module teardown: fades the overlay, resets the option camera and font state,

// frees both cached fonts, then stops the two sound-bank entries.

void _epilog(void) {
    fn_8006CE1C(0.0f);
    fn_1_1596DC(2);
    fn_1_484CC(2);
    fn_1_47A60(3);
    fn_1_412A0(1);
    fn_1_3C78();
    fn_1_435C(((struct OptHandle *)&lbl_4_bss_4)->unk_0);
    fn_1_41A8();
    fn_1_435C(((struct OptHandle *)&lbl_4_bss_8)->unk_0);
    fn_1_41A8();
    if (((struct OptHandle *)&lbl_1_bss_6EAD0)->unk_0 != 0) {
        fn_8004BF0C(((struct OptSoundBank *)((struct OptHandle *)&lbl_1_bss_6EAD0)->unk_0)->unk_0, -999);
        fn_8004BF0C(((struct OptSoundBank *)((struct OptHandle *)&lbl_1_bss_6EAD0)->unk_0)->unk_4, -999);
        ADXT_Stop(((struct OptSoundBank *)((struct OptHandle *)&lbl_1_bss_6EAD0)->unk_0)->unk_0);
        ADXT_Stop(((struct OptSoundBank *)((struct OptHandle *)&lbl_1_bss_6EAD0)->unk_0)->unk_4);
    }
}
/* fzgx:end _epilog */

/* fzgx:begin fn_4_9B0 */
void fn_4_9B0(void) {
    OptionScene *p;
    s16 idx;

    p = lbl_4_data_1260;
    idx = lbl_1_bss_962;
    p += idx - 75;
    lbl_1_bss_71688 = (u32)p->func[1];
    lbl_1_bss_7168C = (u32)p->func[2];
    p->func[0]();
}
/* fzgx:end fn_4_9B0 */

/* fzgx:begin fn_4_A0C */
OptionMenuItem lbl_4_data_144C[3] = {
    {0x4D, {"Controller", "", "", "", "", "\203R\203\223\203g\203\215\201[\203\211"}},
    {0x4E, {"Memory Card", "", "", "", "", "\203\201\203\202\203\212\201[\203J\201[\203h"}},
    {0x4F, {"Screen Mode", "", "", "", "", "\211\346\226\312\203\202\201[\203h"}},
};

static void option_draw_title(f32 y, f32 scale, char *text) {
    fn_1_53E40(0, 320.0f, y, 0.05f, 48.0f, scale, text);
}

static f32 option_draw_caption(char *text) {
    f32 width;

    fn_1_4955C(0.8f, 0.8f);
    width = fn_1_4B040(text);
    fn_1_496FC(320.0f, 110.0f);
    fn_1_4AE0C(lbl_4_data_1210, text);
    return width;
}

void fn_4_A0C(void) {
    fn_1_49410();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    option_draw_title(110.0f, 1.0f, lbl_4_data_5F8[lbl_801A66B4]);
    option_draw_menu(lbl_4_data_144C, 3, &lbl_1_bss_970.unk_4);
    fn_1_1380F0(lbl_4_data_E8[lbl_801A66B4]);
    fn_1_13ABA8(0x28000000);
}
/* fzgx:end fn_4_A0C */

/* fzgx:begin fn_4_D10 */
void fn_4_D10(void) {
    fn_1_435C(lbl_4_bss_8);
    lbl_4_bss_0 = fn_1_3F8C((u32)"option_menu_disp", (u32)fn_4_A0C, 0, 5);
    lbl_4_bss_10 = 0;
    fn_1_4A00(1, 15, lbl_4_bss_8);
}
/* fzgx:end fn_4_D10 */

/* fzgx:begin fn_4_D7C */
void fn_4_D7C(void) {
    struct fn_4_D7C_lbl_1_bss_970 *p;
    u32 v;
    struct fn_4_D7C_lbl_1_bss_6EAB4 *q;

    p = &lbl_1_bss_970;
    if (p->unk_0 <= 0) {
        if (lbl_4_bss_10 != 0) {
            if (fn_1_4C10() == 0) {
                fn_1_1280(1);
                lbl_1_bss_96A = lbl_4_bss_10;
                lbl_4_bss_10 = 0;
            }
        } else {
            p->unk_4 = fn_4_0(p->unk_4, 0, 2, -1, 0);
            if ((lbl_1_bss_9F8[0].trig >> 9) & 1) {
                fn_1_A2D84(0xA9010200);
                q = (struct fn_4_D7C_lbl_1_bss_6EAB4 *)&lbl_1_bss_6EAB4;
                v = q->unk_0;
                q->unk_0 = v | 0x2C;
                lbl_1_bss_970.unk_0 = 1;
            } else if ((lbl_1_bss_9F8[0].trig >> 8) & 1) {
                fn_1_A2D84(0xA9010100);
                lbl_4_bss_10 = lbl_4_data_144C[p->unk_4].id;
                fn_1_4A00(0, 15, lbl_4_bss_8);
            }
        }
    }
}
/* fzgx:end fn_4_D7C */

/* fzgx:begin fn_4_EA0 */
// Clear the pending option selection after applying its associated value.

void fn_4_EA0(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_EA0 */

/* fzgx:begin fn_4_EF8 */
static void option_cal_kind(s32 port) {
    switch (fn_1_3BB0(port)) {
    default:
    case 1:
        lbl_4_bss_12 = 0;
        break;
    case 2:
    case 3:
    case 4:
        lbl_4_bss_12 = 1;
        break;
    }
}

static void option_cal_set_center(s32 port) {
    option_cal_kind(port);
    switch (lbl_4_bss_12) {
    case 0:
        lbl_4_bss_14 = (CalPair){8, 8};
        break;
    case 1:
        lbl_4_bss_18 = (StickMax){0x78, 0x78};
        lbl_4_bss_1C = (StickMax){6, 6};
        break;
    }
}

/* sound_play (owner's notes) at most once per 3 frames */

static void fn_4_EF8_sound(void) {
    if (lbl_4_bss_1E == 0) {
        fn_1_A2D84(0xA9010300);
        lbl_4_bss_1E = 3;
    }
}

static void option_cal_set_gate(s32 port) {
    option_cal_kind(port);
    switch (lbl_4_bss_12) {
    case 0:
        lbl_4_bss_20[0] = (StickPoint){0x25, 0};
        lbl_4_bss_20[1] = (StickPoint){0x1A, 0x1A};
        lbl_4_bss_20[2] = (StickPoint){0, 0x25};
        lbl_4_bss_20[3] = (StickPoint){-0x1A, 0x1A};
        lbl_4_bss_20[4] = (StickPoint){-0x25, 0};
        lbl_4_bss_20[5] = (StickPoint){-0x1A, -0x1A};
        lbl_4_bss_20[6] = (StickPoint){0, -0x25};
        lbl_4_bss_20[7] = (StickPoint){0x1A, -0x1A};
        lbl_4_bss_14 = lbl_1_data_2B40[port];
        fn_80008BEC(lbl_4_bss_30, 0, 0x10);
        fn_80008BEC(lbl_4_bss_40, 0, 0x10);
        break;
    case 1:
        lbl_4_bss_18 = lbl_1_data_2B50[port];
        lbl_4_bss_1C = lbl_1_data_2B58[port];
        break;
    }
}

static inline void fn_4_EF8_set_gate(s32 k, s32 x, s32 y) {
    fn_4_EF8_sound();
    lbl_4_bss_20[k].x = x;
    lbl_4_bss_20[k].y = y;
}

/* fn_1_17C8 maps the stick position at p through the measured gate (0x20) and dead zone (0x14) */

static inline void fn_4_EF8_remap(s8 *p) {
    fn_1_17C8(p, p + 1, lbl_4_bss_20, &lbl_4_bss_14.x);
}

void fn_4_EF8(s32 port) {
    CalPair prev;
    u16 *rep;
    s32 x;
    s32 y;
    u16 ang;
    s32 i;
    f32 gate_len;
    f32 far_len;
    f32 len;

    if (lbl_4_bss_1E != 0) {
        lbl_4_bss_1E--;
    }
    prev = lbl_4_bss_14;
    /* 0x14-byte pad records; unk_10 (+0x10) is read through the stepped pointer (retail lhzu) */
    rep = &lbl_1_bss_9F8[0].unk_0;
    rep += port * 10;
    if (((*(rep += 8) >> 1) & 1) && lbl_4_bss_14.x < 50) {
        lbl_4_bss_14.x++;
    }
    if ((*rep & 1) && lbl_4_bss_14.x != 0) {
        lbl_4_bss_14.x--;
    }
    if (((*rep >> 3) & 1) && lbl_4_bss_14.y < 50) {
        lbl_4_bss_14.y++;
    }
    if (((*rep >> 2) & 1) && lbl_4_bss_14.y != 0) {
        lbl_4_bss_14.y--;
    }
    if (prev.x != lbl_4_bss_14.x || prev.y != lbl_4_bss_14.y) {
        fn_1_A2D84(0xA9010300);
    }
    x = lbl_1_bss_9C8[port].stickX;
    y = lbl_1_bss_9C8[port].stickY;
    ang = lbl_8006D24C(y, x);
    if ((ang & 0x3FFF) >= 0x1000 && (ang & 0x3FFF) <= 0x3000) {
        /* diagonals: 1, 3, 5, 7 */
        if (y > 0) {
            i = (x > 0) ? 1 : 3;
        } else {
            i = (x < 0) ? 5 : 7;
        }
        {
            /* conversion order sets retail's stack slots */
            f32 gy;
            f32 fy;
            f32 sy;
            gy = lbl_4_bss_20[i].y;
            gate_len = lbl_4_bss_20[i].x;
            fy = lbl_4_bss_30[i].y;
            far_len = lbl_4_bss_30[i].x;
            sy = y;
            len = x;
            gate_len *= gate_len;
            gate_len += gy * gy;
            len *= len;
            len += sy * sy;
            far_len *= far_len;
            far_len += fy * fy;
        }
        if (gate_len < len) {
            fn_4_EF8_set_gate(i, x, y);
        }
        if (far_len < len) {
            lbl_4_bss_30[i].x = x;
            lbl_4_bss_40[i].x = x;
            lbl_4_bss_40[i].y = y;
            lbl_4_bss_30[i].y = y;
            fn_4_EF8_remap(&lbl_4_bss_40[i].x);
        }
        return;
    }
    if (lbl_4_bss_20[0].x < x && (ang > 0xF000 || ang < 0x1000)) {
        fn_4_EF8_set_gate(0, x, y);
    }
    if (lbl_4_bss_20[2].y < y && ang > 0x3000 && ang < 0x5000) {
        fn_4_EF8_set_gate(2, x, y);
    }
    if (lbl_4_bss_20[4].x > x && ang > 0x7000 && ang < 0x9000) {
        fn_4_EF8_set_gate(4, x, y);
    }
    if (lbl_4_bss_20[6].y > y && ang > 0xB000 && ang < 0xD000) {
        fn_4_EF8_set_gate(6, x, y);
    }
    if (lbl_4_bss_30[0].x < x) {
        lbl_4_bss_40[0].x = x;
        lbl_4_bss_30[0].x = x;
        lbl_4_bss_40[0].y = y;
        lbl_4_bss_30[0].y = y;
        fn_4_EF8_remap(&lbl_4_bss_40[0].x);
    }
    if (lbl_4_bss_30[2].y < y) {
        lbl_4_bss_30[2].x = x;
        lbl_4_bss_40[2].x = x;
        lbl_4_bss_40[2].y = y;
        lbl_4_bss_30[2].y = y;
        fn_4_EF8_remap(&lbl_4_bss_40[2].x);
    }
    if (lbl_4_bss_30[4].x > x) {
        lbl_4_bss_30[4].x = x;
        lbl_4_bss_40[4].x = x;
        lbl_4_bss_40[4].y = y;
        lbl_4_bss_30[4].y = y;
        fn_4_EF8_remap(&lbl_4_bss_40[4].x);
    }
    if (lbl_4_bss_30[6].y > y) {
        lbl_4_bss_30[6].x = x;
        lbl_4_bss_40[6].x = x;
        lbl_4_bss_40[6].y = y;
        lbl_4_bss_30[6].y = y;
        fn_4_EF8_remap(&lbl_4_bss_40[6].x);
    }
}
/* fzgx:end fn_4_EF8 */

/* fzgx:begin fn_4_1444 */
/* GX write-gather FIFO: every store is a hardware write */
#define GX_FIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)

#define POS3(px, py, pz) \
    GX_FIFO_F32 = (px);  \
    GX_FIFO_F32 = (py);  \
    GX_FIFO_F32 = (pz)

/* Sets up the 2D projection; widescreen stretches the width by 4/3. */
static void option_begin_2d(void) {
    f32 width;

    fn_80072344();
    fn_8006CD2C(&lbl_4_bss_50, &lbl_4_bss_54);
    width = lbl_4_bss_50;
    if (fn_1_A5DC4()) {
        width *= 1.3333334f;
    }
    fn_8006CD20(width, lbl_4_bss_54);
    fn_8006CD50();
    lbl_8006D758();
    lbl_8006E0B4(0.5f * (width - lbl_4_bss_50), 0.0f, 0.0f);
    fn_80072558();
    fn_80074788(1);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_800747D0(4, 0, 1, 0, 0, 2, 2);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 0xFF, 0xFF, 4);
    fn_80072C24(0, 0xF, 0xF, 0xA, 2);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 5, 1);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_80072864(0);
    fn_80074918(1, 3, 1);
    fn_8007245C(0x200);
}

static void option_end_2d(void) {
    fn_800746A8(6, 0);
    fn_8006CD20(lbl_4_bss_50, lbl_4_bss_54);
    fn_80072378();
}

/* Screen origin of the left or right pad panel, and the depth of layer `depth`. */
static void option_panel_origin(s32 left, u16 depth, f32 *x, f32 *y, f32 *z) {
    if (left) {
        *x = 160.0f;
        *y = 210.0f;
    } else {
        *x = 480.0f;
        *y = 210.0f;
    }
    *z = -0.01f * depth;
}

/* WARNING: compiler-diff device, not original code. Reason: retail .rodata 0x11C-0x120 holds
   1.1f, 1.4f (the stick-to-panel scale of fn_4_18B8) before fn_4_1444's own literals. fn_4_18B8
   scales x by 1.4f and y by 1.1f, but calling this helper there changes its FPR order (lane O).
   Nothing calls it. The out-of-line copy is stripped at link. */
static void option_stick_scale(f32 *x, f32 *y) {
    *y *= 1.1f;
    *x *= 1.4f;
}

// Draw a framed text box (filled quad plus outline) with an inner frame.

void fn_4_1444(u16 depth, s32 left, GXColor border, GXColor fill, const char *text) {
    f32 x;
    f32 y;
    f32 z;
    f32 zz;
    f32 x1;
    f32 halfW;
    f32 x0;
    f32 height;
    f32 frameW;
    f32 frameH;

    option_panel_origin(left, depth, &x, &y, &z);

    fn_1_49410();
    fn_1_495C8(1);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4955C(0.8f, 0.8f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    halfW = 0.5f * (20.0f + fn_1_4B068(text));
    height = 10.0f + fn_1_4B090(text);
    frameW = 140.0f;
    frameH = 110.0f;

    fn_800371F8(1, fill);
    fn_8003462C(0x80, 7, 4);
    x0 = x - halfW;
    /* height becomes the top edge, halfW the right edge */
    height = (y - frameH) - height;
    zz = 0.01f + z;
    x1 = x + halfW;
    POS3(x0, height, zz);
    POS3(x1, height, zz);
    POS3(x1, y - frameH, zz);
    POS3(x0, y - frameH, zz);
    fn_800746A8(10, 0);

    fn_800371F8(1, border);
    fn_8003462C(0xA8, 7, 2);
    POS3(x0, height, zz);
    POS3(x1, height, zz);
    fn_8003462C(0xA8, 7, 2);
    POS3(x1, height, zz);
    POS3(x1, y - frameH, zz);
    fn_8003462C(0xA8, 7, 2);
    POS3(x1, y - frameH, zz);
    POS3(x0, y - frameH, zz);
    fn_8003462C(0xA8, 7, 2);
    POS3(x0, y - frameH, zz);
    POS3(x0, height, zz);
    fn_1_496FC(x, 5.0f + height);
    fn_1_4A0D8(text);

    fn_800371F8(1, fill);
    fn_8003462C(0x80, 7, 4);
    POS3(x - frameW, y - frameH, z - 0.001f);
    POS3(x + frameW, y - frameH, z - 0.001f);
    POS3(x + frameW, y + frameH, z - 0.001f);
    POS3(x - frameW, y + frameH, z - 0.001f);

    fn_800371F8(1, border);
    fn_8003462C(0xA8, 7, 2);
    POS3(x - frameW, y - frameH, z);
    POS3(x + frameW, y - frameH, z);
    fn_8003462C(0xA8, 7, 2);
    POS3(x + frameW, y - frameH, z);
    POS3(x + frameW, y + frameH, z);
    fn_8003462C(0xA8, 7, 2);
    POS3(x + frameW, y + frameH, z);
    POS3(x - frameW, y + frameH, z);
    fn_8003462C(0xA8, 7, 2);
    POS3(x - frameW, y + frameH, z);
    POS3(x - frameW, y - frameH, z);
}

static void option_print_stick(s32 left, s32 vx, s32 vy) {
    fn_1_49410();
    fn_1_4955C(0.5625f, 0.75f);
    fn_1_495B0(0x80000000);
    if (left) {
        fn_1_496FC(24.0f, 105.0f);
    } else {
        fn_1_496FC(345.0f, 105.0f);
    }
    fn_1_4AE0C("X:%4d\n", vx);
    fn_1_4AE0C("Y:%4d", vy);
}
/* fzgx:end fn_4_1444 */

/* fzgx:begin fn_4_18B8 */
/* begin dolphin/gx.h (deltawave784/fzgx, CC0) */

#define DOLPHIN_GX_H

/* The GX write-gather pipe: one memory-mapped port at GX_FIFO_BASE (dolphin/hw_regs.h), written through
   the member whose width the command needs. Declared as an MWCC absolute object: every store is
   emitted in order, addressed by literal (`lis rX, 0xCC01; stb rY, -0x8000(rX)`) with no
   relocation, and the named object cannot alias the `gx` context, which keeps retail's schedule.
   Proven by GXSetViewportJitter (fn_80038DE8) and GXSetFog (fn_800377F8). */

/* FILE-SCOPE */ volatile PPCWGPipe GXWGFifo : GX_FIFO_BASE;

/* volatile: hardware port */

#define GX_WRITE_U8(v) (GXWGFifo.u8 = (u8)(v))

#define GX_WRITE_U16(v) (GXWGFifo.u16 = (u16)(v))

#define GX_WRITE_U32(v) (GXWGFifo.u32 = (u32)(v))

#define GX_WRITE_F32(v) (GXWGFifo.f32 = (f32)(v))

/* BP (raster) register write: command byte 0x61 followed by the register word. */

#define GX_WRITE_RAS_REG(value)  \
    do {                         \
        GXWGFifo.u8 = 0x61;      \
        GXWGFifo.u32 = (value);  \
    } while (0)

/* XF register write: command byte 0x10, then (count - 1) << 16 | address, then the data words. */

#define GX_WRITE_XF_REG_HDR(addr, count) \
    do {                                  \
        GXWGFifo.u8 = 0x10;               \
        GXWGFifo.u32 = (((count) - 1) << 16) | (addr); \
    } while (0)

#define CLAMP(v, lo, hi) ((v) < (lo) ? (lo) : ((v) > (hi) ? (hi) : (v)))

static inline void set_color(GXColor c) {
    fn_800371F8(1, c);
}

static inline void draw_fan(GXColor c, f32 *xs, f32 *ys, f32 z) {
    s32 j;
    f32 cx;
    f32 cy;
    set_color(c);
    fn_8003462C(0xA0, 7, 10);
    cx = 160.0f;
    cy = 210.0f;
    GX_FIFO_F32 = cx;
    GX_FIFO_F32 = cy;
    GX_FIFO_F32 = z;
    for (j = 0; j != 9; j++) {
        GX_FIFO_F32 = cx + 1.4f * xs[j % 8];
        GX_FIFO_F32 = cy - 1.1f * ys[j % 8];
        GX_FIFO_F32 = z;
    }
}

static inline void draw_marker(f32 ox, f32 x, f32 y) {
    FontDrawPacket packet;
    x *= 1.4f;
    y *= 1.1f;
    x = ox + x;
    y = 210.0f - y;
    packet = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
    packet.x = x;
    packet.y = y;
    packet.z = 0.03f;
    packet.flags = 10;
    packet.image = 0;
    fn_1_4F734(&packet);
}


/* WARNING: compiler-diff device, not original code (carried from main). fn_4_18B8 needs fp_contract off.
   It has no reset: fn_4_EF8 (before it) needs fp_contract on and no later function changes with it. */
#pragma fp_contract off

void fn_4_18B8(void) {
    GXColor c0 = {0x00, 0xFF, 0x00, 0xFF};
    GXColor c1 = {0xFF, 0x00, 0x00, 0x80};
    GXColor c2 = {0x00, 0x00, 0xFF, 0x80};
    GXColor c3 = {0x68, 0x7E, 0xA0, 0xFF};
    GXColor c4 = {0x20, 0x20, 0x20, 0xA0};
    GXColor c5 = {0xFF, 0xFF, 0xFF, 0x80};
    f32 rawx[8];
    f32 rawy[8];
    f32 normx[8];
    f32 normy[8];
    f32 maxx;
    f32 maxy;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    u32 i;
    s8 tx;
    s8 ty;
    s8 sx;
    s8 sy;

    option_begin_2d();

    maxx = lbl_4_bss_14.x;
    maxy = lbl_4_bss_14.y;
    if (maxx < 1.0f) {
        maxx = 1.0f;
    }
    if (maxy < 1.0f) {
        maxy = 1.0f;
    }
    for (i = 0; i < 8; i++) {
        x0 = lbl_4_bss_20[(s8)i].x;
        sx = x0;
        y0 = lbl_4_bss_20[(s8)i].y;
        sy = y0;
        x1 = lbl_4_bss_20[(i + 1) & 7].x;
        y1 = lbl_4_bss_20[(i + 1) & 7].y;
        x0 = CLAMP(x0, -125.0f, 125.0f);
        y0 = CLAMP(y0, -125.0f, 125.0f);
        x1 = CLAMP(x1, -125.0f, 125.0f);
        y1 = CLAMP(y1, -125.0f, 125.0f);
        fn_1_17C8(&sx, &sy, lbl_4_bss_20, &lbl_4_bss_14.x);
        x0 *= 0.8f;
        y0 *= 0.8f;
        x1 *= 0.8f;
        y1 *= 0.8f;
        set_color(c0);
        fn_800746A8(6, 0);
        fn_8003462C(0xA8, 7, 2);
        GX_FIFO_F32 = 160.0f + 1.4f * x0;
        GX_FIFO_F32 = 210.0f - 1.1f * y0;
        GX_FIFO_F32 = -0.04f;
        GX_FIFO_F32 = 160.0f + 1.4f * x1;
        GX_FIFO_F32 = 210.0f - 1.1f * y1;
        GX_FIFO_F32 = -0.04f;
        rawx[i] = x0;
        rawy[i] = y0;
        normx[i] = x0 / 100.0f * maxx;
        normy[i] = y0 / 100.0f * maxy;
    }
    draw_fan(c2, normx, normy, -0.04f);
    draw_fan(c1, rawx, rawy, -0.049999997f);
    fn_4_1444(6, 0, c3, c4, lbl_4_data_DA0[lbl_801A66B4]);
    fn_4_1444(6, 1, c3, c4, lbl_4_data_D6C[lbl_801A66B4]);

    tx = CLAMP(lbl_4_bss_58, -125, 125);
    ty = CLAMP(lbl_4_bss_59, -125, 125);
    draw_marker(160.0f, 0.8f * tx, 0.8f * ty);
    option_print_stick(1, tx, ty);

    fn_1_17C8(&tx, &ty, lbl_4_bss_20, &lbl_4_bss_14.x);
    draw_marker(480.0f, tx, ty);
    option_print_stick(0, tx, ty);

    option_end_2d();
}
/* fzgx:end fn_4_18B8 */

/* fzgx:begin fn_4_2394 */
/* begin dolphin/gx.h (deltawave784/fzgx, CC0) */

#define DOLPHIN_GX_H

/* The GX write-gather pipe: one memory-mapped port at GX_FIFO_BASE (dolphin/hw_regs.h), written through
   the member whose width the command needs. Declared as an MWCC absolute object: every store is
   emitted in order, addressed by literal (`lis rX, 0xCC01; stb rY, -0x8000(rX)`) with no
   relocation, and the named object cannot alias the `gx` context, which keeps retail's schedule.
   Proven by GXSetViewportJitter (fn_80038DE8) and GXSetFog (fn_800377F8). */

/* FILE-SCOPE */ volatile PPCWGPipe GXWGFifo : GX_FIFO_BASE;

/* volatile: hardware port */

#define GX_WRITE_U8(v) (GXWGFifo.u8 = (u8)(v))

#define GX_WRITE_U16(v) (GXWGFifo.u16 = (u16)(v))

#define GX_WRITE_U32(v) (GXWGFifo.u32 = (u32)(v))

#define GX_WRITE_F32(v) (GXWGFifo.f32 = (f32)(v))

/* BP (raster) register write: command byte 0x61 followed by the register word. */

#define GX_WRITE_RAS_REG(value)  \
    do {                         \
        GXWGFifo.u8 = 0x61;      \
        GXWGFifo.u32 = (value);  \
    } while (0)

/* XF register write: command byte 0x10, then (count - 1) << 16 | address, then the data words. */

#define GX_WRITE_XF_REG_HDR(addr, count) \
    do {                                  \
        GXWGFifo.u8 = 0x10;               \
        GXWGFifo.u32 = (((count) - 1) << 16) | (addr); \
    } while (0)

/* GX write-gather pipe: every store is a FIFO push, so it must stay volatile. */

static inline void fn_4_2394_shadow(void) {
if ((lbl_801A66B4) != 5) {
fn_1_495B0(0x80000000);
fn_1_49590(0.5f);
}
}

/* WARNING: compiler-diff device, not original code (carried from main). Without it fn_4_2394 differs in 30 words. */
#pragma opt_lifetimes off

void fn_4_2394(char *label, s32 right, u16 depth, GXColor outline, GXColor fill, s32 value) {
char buf[64];
f32 left;
f32 halfH;
f32 top;
f32 halfW;
f32 x;
f32 z;
    f32 lab_t0;

fn_1_49410();
fn_1_49738(fn_1_5233C);
fn_1_49748(5.0f);
fn_1_4955C(0.8f, 0.8f);
if (lbl_801A66B4 == 5) {
sprintf(buf, "%s%4d", label, value);
halfH = 90.0f;
} else {
sprintf(buf, lbl_4_data_1210, label, value);
halfH = 135.0f;
}
x = 300.0f;
halfW = 0.5f * (10.0f + fn_1_4B090(buf));
z = -0.01f * depth;
if (right) {
x -= 50.0f + halfW;
} else {
x += 50.0f + halfW;
}
fn_800371F8(1, fill);
fn_8003462C(0x80, 7, 4);
left = x - halfW;
halfW = x + halfW;
top = 320.0f - halfH;
halfH = 320.0f + halfH;
GXWGFifo.f32 = top;
GXWGFifo.f32 = left;
GXWGFifo.f32 = z;
GXWGFifo.f32 = halfH;
GXWGFifo.f32 = left;
GXWGFifo.f32 = z;
GXWGFifo.f32 = halfH;
GXWGFifo.f32 = halfW;
GXWGFifo.f32 = z;
GXWGFifo.f32 = top;
GXWGFifo.f32 = halfW;
GXWGFifo.f32 = z;
fn_800746A8(10, 0);
fn_800371F8(1, outline);
fn_8003462C(0xA8, 7, 2);
GXWGFifo.f32 = top;
GXWGFifo.f32 = left;
GXWGFifo.f32 = z;
GXWGFifo.f32 = halfH;
GXWGFifo.f32 = left;
GXWGFifo.f32 = z;
fn_8003462C(0xA8, 7, 2);
GXWGFifo.f32 = halfH;
GXWGFifo.f32 = left;
GXWGFifo.f32 = z;
GXWGFifo.f32 = halfH;
GXWGFifo.f32 = halfW;
GXWGFifo.f32 = z;
fn_8003462C(0xA8, 7, 2);
GXWGFifo.f32 = halfH;
GXWGFifo.f32 = halfW;
GXWGFifo.f32 = z;
GXWGFifo.f32 = top;
GXWGFifo.f32 = halfW;
GXWGFifo.f32 = z;
fn_8003462C(0xA8, 7, 2);
GXWGFifo.f32 = top;
GXWGFifo.f32 = halfW;
GXWGFifo.f32 = z;
GXWGFifo.f32 = top;
GXWGFifo.f32 = left;
GXWGFifo.f32 = z;
if (lbl_801A66B4 == 5) {
fn_1_495C8(9);
lab_t0 = 320.0f;
fn_1_496FC(lab_t0, x);
fn_4_2394_shadow();
fn_1_4A0D8(buf);
} else {
fn_1_495C8(8);
fn_4_2394_shadow();
lab_t0 = 192.0f;
fn_1_496FC(lab_t0, x);
fn_1_4A0D8(buf);
lab_t0 = 380.0f;
fn_1_496FC(lab_t0, x);
fn_1_4AE0C("%4d", value);
}
}

#pragma opt_lifetimes reset
/* fzgx:end fn_4_2394 */

/* fzgx:begin fn_4_2700 */
/* GX write-gather pipe: every store is a FIFO push, so it must stay volatile. */
#define GX_FIFO_F32 (*(volatile f32 *)GX_FIFO_BASE)

/* WARNING: compiler-diff device, not original code. Reason: retail .rodata 0x194-0x19C holds
   64.0f, 280.0f, 576.0f (the bar panel of fn_4_28FC) before fn_4_2700's 2.0f. No helper shape
   that places them there was found (lane O). The out-of-line copy is stripped at link. */
static void option_pool_bar_panel(void) {
    fn_1_496FC(64.0f, 280.0f);
    fn_1_496FC(576.0f, 0.0f);
}

// Draws a filled box centred on x=320 with an outline in a second colour.

void fn_4_2700(u16 depth, GXColor outline, GXColor fill, f32 width, f32 height) {
    f32 right;
    f32 left;
    f32 z;
    f32 top;
    f32 bottom;
    f32 zFill;
    f32 scale = 2.0f;

    width = width * scale;
    height = height * scale;
    fn_800371F8(1, fill);
    fn_8003462C(0x80, 7, 4);
    top = 280.0f;
    bottom = 320.0f;
    left = bottom - width;
    right = bottom + height;
    GX_FIFO_F32 = left;
    GX_FIFO_F32 = top;
    z = -0.01f * depth;
    zFill = z - 0.001f;
    GX_FIFO_F32 = zFill;
    GX_FIFO_F32 = right;
    GX_FIFO_F32 = top;
    GX_FIFO_F32 = zFill;
    GX_FIFO_F32 = right;
    GX_FIFO_F32 = bottom;
    GX_FIFO_F32 = zFill;
    GX_FIFO_F32 = left;
    GX_FIFO_F32 = bottom;
    GX_FIFO_F32 = zFill;

    fn_800371F8(1, outline);
    fn_800746A8(10, 0);
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = left;
    GX_FIFO_F32 = top;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = right;
    GX_FIFO_F32 = top;
    GX_FIFO_F32 = z;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = right;
    GX_FIFO_F32 = top;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = right;
    GX_FIFO_F32 = bottom;
    GX_FIFO_F32 = z;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = right;
    GX_FIFO_F32 = bottom;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = left;
    GX_FIFO_F32 = bottom;
    GX_FIFO_F32 = z;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = left;
    GX_FIFO_F32 = bottom;
    GX_FIFO_F32 = z;
    GX_FIFO_F32 = left;
    GX_FIFO_F32 = top;
    GX_FIFO_F32 = z;
}
/* fzgx:end fn_4_2700 */

/* fzgx:begin fn_4_28FC */
/* Tip of a bar marker: above or below the bar at 300, pointing at the bar. */
static void option_marker_pos(f32 pos, s32 below, f32 *x, f32 *y, f32 *d) {
    /* WARNING: compiler-diff device, not original code (carried from main). `pos = pos;` makes MWCC
       number the converted position after the 2.0f and 320.0f loads (retail FPR order). BLOCKED. */
    pos = pos;
    *x = 320.0f + 2.0f * pos;
    *y = 300.0f;
    if (below) {
        *y += 32.0f;
        *d = -10.0f;
    } else {
        *y -= 32.0f;
        *d = 10.0f;
    }
}

static inline void bar_marker(f32 pos, s32 below, GXColor fill, GXColor line) {
    f32 x;
    f32 y;
    f32 d;
    /* WARNING: compiler-diff device, not original code (carried from main). `pos = pos;` makes MWCC
       number the converted position after the 2.0f and 320.0f loads (retail FPR order). BLOCKED. */
    pos = pos;
    x = 320.0f + 2.0f * pos;
    y = 300.0f;
    if (below) {
        y += 32.0f;
        d = -10.0f;
    } else {
        y -= 32.0f;
        d = 10.0f;
    }
    fn_800371F8(1, fill);
    fn_8003462C(0x90, 7, 3);
    GX_FIFO_F32 = x - d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.031f;
    GX_FIFO_F32 = x + d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.031f;
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y + d;
    GX_FIFO_F32 = -0.031f;

    fn_800371F8(1, line);
    fn_800746A8(10, 0);
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x - d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
    GX_FIFO_F32 = x + d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x + d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y + d;
    GX_FIFO_F32 = -0.03f;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y + d;
    GX_FIFO_F32 = -0.03f;
    GX_FIFO_F32 = x - d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
}

static inline void bar_marker2(f32 pos, s32 below, GXColor fill, GXColor line) {
    f32 y;
    f32 x;
    f32 d;
    option_marker_pos(pos, below, &x, &y, &d);
    fn_800371F8(1, fill);
    fn_8003462C(0x90, 7, 3);
    GX_FIFO_F32 = x - d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.031f;
    GX_FIFO_F32 = x + d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.031f;
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y + d;
    GX_FIFO_F32 = -0.031f;

    fn_800371F8(1, line);
    fn_800746A8(10, 0);
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x - d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
    GX_FIFO_F32 = x + d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x + d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y + d;
    GX_FIFO_F32 = -0.03f;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y + d;
    GX_FIFO_F32 = -0.03f;
    GX_FIFO_F32 = x - d;
    GX_FIFO_F32 = y - d;
    GX_FIFO_F32 = -0.03f;
}

static inline void bar_panel(f32 x0, f32 y0, f32 x1, f32 y1, GXColor fill, GXColor line) {
    fn_800371F8(1, fill);
    fn_8003462C(0x80, 7, 4);
    GX_FIFO_F32 = x0;
    GX_FIFO_F32 = y0;
    GX_FIFO_F32 = -0.06f;
    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y0;
    GX_FIFO_F32 = -0.06f;
    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y1;
    GX_FIFO_F32 = -0.06f;
    GX_FIFO_F32 = x0;
    GX_FIFO_F32 = y1;
    GX_FIFO_F32 = -0.06f;

    fn_800371F8(1, line);
    fn_800746A8(10, 0);
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x0;
    GX_FIFO_F32 = y0;
    GX_FIFO_F32 = -0.01f;
    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y0;
    GX_FIFO_F32 = -0.01f;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y0;
    GX_FIFO_F32 = -0.01f;
    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y1;
    GX_FIFO_F32 = -0.01f;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y1;
    GX_FIFO_F32 = -0.01f;
    GX_FIFO_F32 = x0;
    GX_FIFO_F32 = y1;
    GX_FIFO_F32 = -0.01f;
    fn_8003462C(0xA8, 7, 2);
    GX_FIFO_F32 = x0;
    GX_FIFO_F32 = y1;
    GX_FIFO_F32 = -0.01f;
    GX_FIFO_F32 = x0;
    GX_FIFO_F32 = y0;
    GX_FIFO_F32 = -0.01f;

}

void fn_4_28FC(void) {
    GXColor c0 = {0x68, 0x7E, 0xA0, 0xFF};
    GXColor c1 = {0x00, 0xFF, 0x00, 0xFF};
    GXColor c2 = {0x20, 0x20, 0x20, 0xA0};
    GXColor c3 = {0xFF, 0x00, 0x00, 0x80};
    GXColor c4 = {0x00, 0x00, 0xFF, 0x80};
    GXColor c5 = {0xFF, 0xFF, 0x00, 0xFF};
    f32 value;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;

    option_begin_2d();

    x0 = 64.0f;
    y0 = 280.0f;
    x1 = 576.0f;
    y1 = 320.0f;
    bar_panel(x0, y0, x1, y1, c2, c0);

    fn_4_2700(4, c1, c4, lbl_4_bss_1C.y, lbl_4_bss_1C.x);
    fn_4_2700(5, c1, c3, lbl_4_bss_18.y, lbl_4_bss_18.x);

    bar_marker(lbl_4_bss_58, 0, c5, c1);
    fn_4_2394(lbl_4_data_D6C[lbl_801A66B4], 1, 4, c0, c2, lbl_4_bss_58);

    value = fn_1_1ACC(lbl_4_bss_58, &lbl_4_bss_18.x, &lbl_4_bss_1C.x);
    bar_marker2(1.28f * value, 1, c5, c1);
    fn_4_2394(lbl_4_data_DA0[lbl_801A66B4], 0, 4, c0, c2, value);

    option_end_2d();
}
/* fzgx:end fn_4_28FC */

/* fzgx:begin fn_4_3128 */
/* Draws the controller calibration screen. The .bss byte at 0x5A picks the step (retail English texts):
 * 0 "Adjust the Calibration. Press the A Button on the Controller you want adjusted.", 1 "Save changes?",
 * 2 the Control Stick (fn_4_18B8) or steering wheel (fn_4_28FC) adjustment, 3 "Is this OK?",
 * 4 "The Controller has been disconnected. Reconnect the Controller in Socket %d ...", 5 "Return to the default
 * settings?". The guide text and flags go to fn_1_1380F0 and fn_1_13ABA8 at the end. */

void fn_4_3128(void) {
    char *guide;
    u32 flags;
    u8 count;
    char buf[512];

    guide = lbl_4_data_1A4[lbl_801A66B4];
    flags = 0x20000000;
    fn_1_49410();
    fn_1_495C8(1);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    switch (lbl_4_bss_5A) {
    case 0:
        flags = 0x28000000;
        guide = lbl_4_data_23C[lbl_801A66B4];
        option_draw_title(240.0f, 1.0f, lbl_4_data_6BC[lbl_801A66B4]);
        break;
    case 1:
        if (lbl_4_bss_5B == 0) {
            flags = 0;
            guide = lbl_4_data_1A4[lbl_801A66B4];
        } else {
            flags = 0x48000000;
            guide = lbl_4_data_E8[lbl_801A66B4];
            fn_4_2D4(lbl_4_bss_5C & 1, lbl_4_data_884[lbl_801A66B4]);
        }
        break;
    case 2:
        switch (lbl_4_bss_12) {
        case 0:
            flags = 0x48000000;
            guide = lbl_4_data_2B4[lbl_801A66B4];
            fn_1_53E40(0, 320.0f, 368.8f, 0.05f, 38.4f, 0.7f, lbl_4_data_C00[lbl_801A66B4]);
            fn_4_18B8();
            break;
        case 1:
            flags = 0x28000000;
            guide = lbl_4_data_314[lbl_801A66B4];
            fn_1_53E40(0, 320.0f, 136.7f, 0.05f, 38.4f, 0.8f, lbl_4_data_D38[lbl_801A66B4]);
            fn_4_28FC();
            break;
        }
        break;
    case 3:
        flags = 0x48000000;
        guide = lbl_4_data_E8[lbl_801A66B4];
        fn_4_2D4(lbl_4_bss_5C, lbl_4_data_8C0[lbl_801A66B4]);
        switch (lbl_4_bss_12) {
        case 0:
            fn_4_18B8();
            break;
        case 1:
            fn_4_28FC();
            break;
        }
        break;
    case 4:
        count = lbl_4_bss_5D;
        guide = "";
        flags = 0;
        fn_1_49410();
        fn_1_49738(fn_1_5233C);
        fn_1_49748(5.0f);
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(0.5f);
        }
        sprintf(buf, lbl_4_data_560[lbl_801A66B4], count + 1);
        option_draw_title(240.0f, 0.8f, buf);
        break;
    case 5:
        flags = 0x48000000;
        guide = lbl_4_data_E8[lbl_801A66B4];
        fn_4_2D4(lbl_4_bss_5C, lbl_4_data_364[lbl_801A66B4]);
        switch (lbl_4_bss_12) {
        case 0:
            fn_4_18B8();
            break;
        case 1:
            fn_4_28FC();
            break;
        }
        break;
    }
    fn_1_1380F0(guide);
    fn_1_13ABA8(flags);
}
/* fzgx:end fn_4_3128 */

/* fzgx:begin fn_4_347C */
void fn_4_347C(void) {
    fn_1_435C(lbl_4_bss_8);
    lbl_4_bss_0 = fn_1_3F8C((u32)"option_calib_disp", (u32)fn_4_3128, 0, 20);
    fn_80008BA8(lbl_4_bss_60, lbl_1_data_2AC0, sizeof(lbl_4_bss_60));
    fn_80008BA8(lbl_4_bss_A0, lbl_1_data_2B40, sizeof(lbl_4_bss_A0));
    fn_80008BA8(lbl_4_bss_A8, lbl_1_data_2B50, sizeof(lbl_4_bss_A8));
    fn_80008BA8(lbl_4_bss_B0, lbl_1_data_2B58, sizeof(lbl_4_bss_B0));
    lbl_4_bss_5A = 0;
    lbl_4_bss_5C = 0;
    lbl_4_bss_5B = 0;
    lbl_4_bss_10 = 0;
    fn_1_4A00(1, 15, lbl_4_bss_8);
    lbl_4_bss_58 = lbl_1_bss_9C8[lbl_4_bss_5D].stickX;
    lbl_4_bss_59 = lbl_1_bss_9C8[lbl_4_bss_5D].stickY;
}
/* fzgx:end fn_4_347C */

/* fzgx:begin fn_4_3568 */
#define CAL_PADS lbl_1_bss_9F8

void fn_4_3568(void) {
    u32 i;
    s32 v;
    s32 k;
    u16 b;
    u32 type;
    s32 port;

    if (lbl_4_bss_10 != 0) {
        if (fn_1_4C10() == 0) {
            fn_1_1280(1);
            lbl_1_bss_96A = lbl_4_bss_10;
            lbl_4_bss_10 = 0;
        }
        return;
    }
    if (lbl_4_bss_5A != 0 && lbl_4_bss_5A != 1 && lbl_4_bss_5A != 4) {
        if (lbl_1_bss_980[lbl_4_bss_5D] & 0x48) {
            lbl_4_bss_5A = 4;
        }
    }
    switch (lbl_4_bss_5A) {
    case 0:
        if ((CAL_PADS[0].trig >> 9) & 1) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_5C = 0;
            lbl_4_bss_5A = 1;
            return;
        }
        for (i = 0; i < 4; i++) {
            if ((CAL_PADS[i].trig >> 8) & 1) {
                fn_1_A2D84(0xA9010100);
                lbl_4_bss_5D = i;
                lbl_4_bss_5A = 2;
                option_cal_set_gate(lbl_4_bss_5D);
                return;
            }
        }
        break;
    case 1:
        if (lbl_4_bss_5B == 0) {
            lbl_4_bss_10 = 0x4D;
            fn_1_4A00(0, 15, lbl_4_bss_8);
            return;
        }
        lbl_4_bss_5C = fn_4_0(lbl_4_bss_5C, 0, 1, -1, 1);
        if ((CAL_PADS[0].trig >> 9) & 1) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_5A = 0;
            return;
        }
        if (!((CAL_PADS[0].trig >> 8) & 1)) {
            return;
        }
        fn_1_A2D84(0xA9010100);
        switch (lbl_4_bss_5C) {
        case 0:
            lbl_4_bss_E = 1;
            fn_80008BA8(lbl_1_bss_718E0.cal_gate, lbl_1_data_2AC0, sizeof(lbl_1_data_2AC0));
            fn_80008BA8(lbl_1_bss_718E0.cal_center, lbl_1_data_2B40, sizeof(lbl_1_data_2B40));
            fn_80008BA8(lbl_1_bss_718E0.cal_max, lbl_1_data_2B50, sizeof(lbl_1_data_2B50));
            fn_80008BA8(lbl_1_bss_718E0.cal_dead, lbl_1_data_2B58, sizeof(lbl_1_data_2B58));
            break;
        case 1:
            fn_80008BA8(lbl_1_data_2AC0, lbl_4_bss_60, sizeof(lbl_4_bss_60));
            fn_80008BA8(lbl_1_data_2B40, lbl_4_bss_A0, sizeof(lbl_4_bss_A0));
            fn_80008BA8(lbl_1_data_2B50, lbl_4_bss_A8, sizeof(lbl_4_bss_A8));
            fn_80008BA8(lbl_1_data_2B58, lbl_4_bss_B0, sizeof(lbl_4_bss_B0));
            break;
        }
        if (lbl_4_bss_E != 0) {
            lbl_4_bss_B8 = 0x4D;
            lbl_4_bss_10 = 0x4C;
        } else {
            lbl_4_bss_10 = 0x4D;
            fn_1_4A00(0, 15, lbl_4_bss_8);
        }
        break;
    case 2:
        port = lbl_4_bss_5D;
        switch (lbl_4_bss_12) {
        case 0:
            fn_4_EF8(port);
            break;
        case 1:
            v = lbl_1_bss_9C8[port].stickX;
            if ((CAL_PADS[port].trig >> 8) & 1) {
                if (__abs(v) <= 20) {
                    fn_1_A2D84(0xA9010200);
                } else {
                    fn_1_A2D84(0xA9010100);
                    if (v < 0) {
                        lbl_4_bss_18.y = -v;
                    } else {
                        lbl_4_bss_18.x = v;
                    }
                }
            }
            k = lbl_4_bss_1C.x;
            if (PAD_BIT(CAL_PADS[port].unk_12, 9) && k < 20) {
                k++;
                fn_1_A2D84(0xA9010300);
            } else if (PAD_BIT(CAL_PADS[port].unk_12, 8) && k > 0) {
                k--;
                fn_1_A2D84(0xA9010300);
            }
            lbl_4_bss_1C.x = k;
            lbl_4_bss_1C.y = k;
            break;
        }
        if (PAD_BIT(CAL_PADS[lbl_4_bss_5D].trig, 10)) {
            fn_1_A2D84(0xA9010100);
            lbl_4_bss_5C = 1;
            lbl_4_bss_5A = 5;
            return;
        }
        if (lbl_4_bss_12 == 0 && PAD_BIT(CAL_PADS[lbl_4_bss_5D].trig, 8)) {
            fn_1_A2D84(0xA9010100);
            lbl_4_bss_5C = 0;
            lbl_4_bss_5A = 3;
        } else if (lbl_4_bss_12 == 1 && PAD_BIT(CAL_PADS[lbl_4_bss_5D].trig, 9)) {
            fn_1_A2D84(0xA9010100);
            if (lbl_4_bss_18.x == lbl_1_data_2B50[lbl_4_bss_5D].x
             && lbl_4_bss_18.y == lbl_1_data_2B50[lbl_4_bss_5D].y
             && lbl_4_bss_1C.x == lbl_1_data_2B58[lbl_4_bss_5D].x
             && lbl_4_bss_1C.y == lbl_1_data_2B58[lbl_4_bss_5D].y) {
                lbl_4_bss_5A = 0;
            } else {
                lbl_4_bss_5C = 0;
                lbl_4_bss_5A = 3;
            }
        } else if (lbl_4_bss_12 == 0 && PAD_BIT(CAL_PADS[lbl_4_bss_5D].trig, 9)) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_5A = 0;
        }
        lbl_4_bss_58 = lbl_1_bss_9C8[lbl_4_bss_5D].stickX;
        lbl_4_bss_59 = lbl_1_bss_9C8[lbl_4_bss_5D].stickY;
        break;
    case 3:
        lbl_4_bss_5C = fn_4_0(lbl_4_bss_5C, 0, 1, lbl_4_bss_5D, 1);
        if (PAD_BIT(CAL_PADS[lbl_4_bss_5D].trig, 9)) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_5A = 2;
            return;
        }
        if (!((CAL_PADS[lbl_4_bss_5D].trig >> 8) & 1)) {
            return;
        }
        fn_1_A2D84(0xA9010100);
        if (lbl_4_bss_5C == 0) {
            port = lbl_4_bss_5D;
            switch (lbl_4_bss_12) {
            case 0:
                fn_80008BA8(lbl_1_data_2AC0[port], lbl_4_bss_20, sizeof(lbl_4_bss_20));
                lbl_1_data_2B40[port] = lbl_4_bss_14;
                break;
            case 1:
                lbl_1_data_2B50[port] = lbl_4_bss_18;
                lbl_1_data_2B58[port] = lbl_4_bss_1C;
                break;
            }
            lbl_4_bss_5B = 1;
        }
        lbl_4_bss_5A = 0;
        break;
    case 4:
        type = lbl_1_bss_980[lbl_4_bss_5D];
        if (type & 0x48) {
            if ((lbl_1_bss_D58.trig >> 8) & 1) {
                fn_1_A2D84(0xA9010100);
                lbl_4_bss_5A = 0;
            }
            return;
        }
        if (type == 0x09000000 || type == 0x88000000 || type == 0x8B100000 || type == 0x08000000) {
            fn_1_A2D84(0xA9010100);
            lbl_4_bss_5A = 2;
            option_cal_set_gate(lbl_4_bss_5D);
        }
        break;
    case 5:
        lbl_4_bss_5C = fn_4_0(lbl_4_bss_5C, 0, 1, lbl_4_bss_5D, 1);
        if (PAD_BIT(CAL_PADS[lbl_4_bss_5D].trig, 9)) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_5A = 2;
            return;
        }
        if (!((CAL_PADS[lbl_4_bss_5D].trig >> 8) & 1)) {
            return;
        }
        fn_1_A2D84(0xA9010100);
        if (lbl_4_bss_5C == 0) {
            option_cal_set_gate(lbl_4_bss_5D);
            option_cal_set_center(lbl_4_bss_5D);
        }
        lbl_4_bss_5A = 2;
        break;
    }
}
/* fzgx:end fn_4_3568 */

/* fzgx:begin fn_4_406C */
// Finalizes the pending option callback and clears its handle.

void fn_4_406C(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_406C */

/* fzgx:begin fn_4_40C4 */
u8 lbl_4_data_14E2 = 0xFFU;

s16 lbl_4_data_14E4 = -1;

char lbl_4_data_14E8[10] = "%s%d\201c   ";

char lbl_4_data_14F4[9] = "%s%d\201c%s";

void fn_4_40C4(u32 arg0, char *arg1) {
    f32 v0;
    f32 max;
    f32 y;
    s32 i;
    f32 height;
    f32 scale;
    char buf[256];

    fn_1_49410();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_495C8(9);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    v0 = option_draw_caption(arg1);
    height = 24.0f;
    fn_1_53BD8(0, 320.0f, 110.0f, 120.0 + (96.0 + v0), 48.0 + height, 0.25f);
    max = 0.0f;
    fn_1_49410();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_495C8(9);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    for (i = 0; i < 4; i++) {
        char *text;

        y = 280 + (i * 2 - 3) * 24;
        fn_1_496FC(320.0f, y);
        if (__rlwnm(lbl_4_bss_BA, (32 - i) & 31, 31, 31)) {
            text = lbl_4_data_8E0[lbl_801A66B4];
        } else {
            text = lbl_4_data_900[lbl_801A66B4];
        }
        if (lbl_801A66B4 != 5) {
            fn_1_4954C(0.205f);
            sprintf(buf, lbl_4_data_14E8, lbl_4_data_20[lbl_801A66B4], i + 1, text);
            fn_1_4AE0C(lbl_4_data_1210, buf);
            fn_1_4954C(0.105000004f);
            fn_1_496FC(416.0f, y);
            fn_1_4AE0C(lbl_4_data_1210, text);
        } else {
            sprintf(buf, lbl_4_data_14F4, lbl_4_data_20[lbl_801A66B4], i + 1, text);
            fn_1_4AE0C(lbl_4_data_1210, buf);
        }
        v0 = fn_1_4B040(buf);
        if (v0 > max) {
            max = v0;
        }
    }
    if (lbl_4_data_14E2 != arg0 || lbl_4_data_14E4 != lbl_4_bss_BB) {
        lbl_4_bss_2 = 0;
        lbl_4_data_14E2 = arg0;
        lbl_4_data_14E4 = lbl_4_bss_BB;
    }
    if (lbl_4_bss_BB == 1) {
        option_draw_cursor_dim(320.0f, (arg0 * 2 - 3) * 24 + 280, 0.15f, max, 0.0f, 1.0f);
        if (__rlwnm(lbl_4_bss_BA, (32 - arg0) & 31, 31, 31)) {
            scale = 2.0f;
        } else {
            scale = 3.0f;
        }
        option_draw_mark(320.0 + 24.0 * (5.5 - scale), (arg0 * 2 - 3) * 24 + 280, 0.1f, 24.0f * scale);
    } else if (lbl_4_bss_BB == 0) {
        option_draw_cursor(320.0f, (arg0 * 2 - 3) * 24 + 280, 0.15f, max, 0.0f, 1.0f);
    }
    height = 168.0f;
    fn_1_53BD8(0, 320.0f, 280.0f, 96.0 + max, 48.0 + height, 0.25f);
}
/* fzgx:end fn_4_40C4 */

/* fzgx:begin fn_4_467C */
void fn_4_467C(void) {
    char *t0;
    char *t1;
    u32 t2;

    switch (lbl_4_bss_BB) {
    case 0:
    default:
        t0 = lbl_4_data_3E8[lbl_801A66B4];
        t1 = lbl_4_data_82C[lbl_801A66B4];
        t2 = 0x28000000;
        break;
    case 1:
        t0 = lbl_4_data_468[lbl_801A66B4];
        t1 = lbl_4_data_844[lbl_801A66B4];
        t2 = 0x20000000;
        break;
    case 2:
        t0 = lbl_4_data_E8[lbl_801A66B4];
        t1 = lbl_4_data_884[lbl_801A66B4];
        fn_4_2D4(lbl_4_bss_BC, t1);
        t1 = lbl_4_data_82C[lbl_801A66B4];
        t2 = 0x48000000;
        break;
    }

    fn_4_40C4(lbl_4_bss_BD, t1);
    fn_1_1380F0(t0);
    fn_1_13ABA8(t2);
}
/* fzgx:end fn_4_467C */

/* fzgx:begin fn_4_4784 */
void fn_4_4784(void) {
    u32 t0, t1, t3, t5;
    t0 = fn_1_F7568();
    lbl_4_bss_BE = t0;
    lbl_4_bss_BA = t0;
    lbl_4_bss_BD = 0;
    lbl_4_bss_BB = 0;
    t1 = fn_1_435C(lbl_4_bss_4);
    fn_1_F70D0(t1);
    t3 = fn_1_3F8C((u32)"RumbleMain", (u32)fn_1_F7128, 0, 10);
    lbl_4_bss_C0 = t3;
    fn_1_435C(lbl_4_bss_8);
    t5 = fn_1_3F8C((u32)"option_rumble_disp", (u32)fn_4_467C, 0, 5);
    lbl_4_bss_0 = t5;
    lbl_4_bss_10 = 0;
    fn_1_4A00(1, 15, lbl_4_bss_8);
}
/* fzgx:end fn_4_4784 */

/* fzgx:begin fn_4_4834 */
void fn_4_4834(void) {
    int flag = 0;
    u16 state;


    if (lbl_4_bss_10 != 0) {
        if (fn_1_4C10() != 0) {
            return;
        }
        fn_1_1280(1);
        lbl_1_bss_96A = lbl_4_bss_10;
        lbl_4_bss_10 = 0;
        return;
    }

    switch (lbl_4_bss_BB) {
    case 0:
        lbl_4_bss_BD = fn_4_0(lbl_4_bss_BD, 0, 3, -1, 0);
        state = lbl_1_bss_9F8[0].trig;
        if (((state >> 8) & 1) != 0) {
            fn_1_A2D84(0xA9010100);
            lbl_4_bss_BB = 1;
        } else if (((state >> 9) & 1) != 0) {
            fn_1_A2D84(0xA9010200);
            if (lbl_4_bss_BA == lbl_1_bss_718E0.unk_2) {
                fn_1_F755C(lbl_4_bss_BE);
                lbl_4_bss_10 = 0x4D;
                fn_1_4A00(0, 15, lbl_4_bss_8);
            } else {
                lbl_4_bss_BB = 2;
                lbl_4_bss_BC = 0;
            }
        }
        break;
    case 1:
        state = lbl_1_bss_9F8[0].trig;
        if (((state >> 9) & 1) != 0) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_BB = 0;
            break;
        }
        if (((lbl_1_bss_9F8[0].rep >> 1) & 1) || ((lbl_1_bss_9F8[0].unk_12 >> 1) & 1)) {
            lbl_4_bss_BA = (lbl_4_bss_BA &
                ~(0x80000000u >> (31 - lbl_4_bss_BD)));
            fn_1_A2D84(0xA9010000);
        } else if (((lbl_1_bss_9F8[0].rep & 1) != 0) || ((lbl_1_bss_9F8[0].unk_12 & 1) != 0)) {
            fn_1_A2D84(0xA9010000);
            flag = !__rlwnm(lbl_4_bss_BA, (32 - lbl_4_bss_BD) & 31, 31, 31);
            lbl_4_bss_BA = (lbl_4_bss_BA |
                (0x80000000u >> (31 - lbl_4_bss_BD)));
        }
        fn_1_F755C(lbl_4_bss_BA);
        if (flag) {
            fn_1_F73A8(lbl_4_bss_BD, 1, 0x12);
            fn_1_156884(lbl_4_bss_BD);
        }
        break;
    case 2:
        lbl_4_bss_BC = fn_4_0(lbl_4_bss_BC, 0, 1, -1, 1);
        state = lbl_1_bss_9F8[0].trig;
        if (((state >> 9) & 1) != 0) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_BB = 0;
        } else if (((state >> 8) & 1) != 0) {
            fn_1_A2D84(0xA9010100);
            if (lbl_4_bss_BC == 0) {
                lbl_1_bss_718E0.unk_2 = lbl_4_bss_BA;
                lbl_4_bss_E = 1;
                lbl_4_bss_B8 = 0x4D;
                lbl_4_bss_10 = 0x4C;
            } else {
                fn_1_F755C(lbl_4_bss_BE);
                lbl_4_bss_10 = 0x4D;
                fn_1_4A00(0, 15, lbl_4_bss_8);
            }
        }
        break;
    }
}
/* fzgx:end fn_4_4834 */

/* fzgx:begin fn_4_4B10 */
/* Stop active option sounds and clear the pending sound handle. */

void fn_4_4B10(void) {
    struct fn_4_4B10_state *state;

    state = (struct fn_4_4B10_state *)&lbl_4_bss_0;
    fn_1_F7308();
    fn_1_435C(state->unk_4);
    fn_1_426C(state->unk_C0);
    if (state->unk_0 != 0) {
        fn_1_435C(state->unk_8);
        fn_1_426C(state->unk_0);
        state->unk_0 = 0;
    }
}
/* fzgx:end fn_4_4B10 */

/* fzgx:begin fn_4_4B74 */
u16 lbl_4_data_1520[4] = {
    0x81FFU, 0x811FU, 0x831FU, 0x0000U
};

u32 lbl_4_data_1528[3] = {
    0x803FFF1FU, 0x80303F1FU, 0x80F03F1FU
};

char *lbl_4_data_15E8[5][6] = {
    {"Not Connected", "\226\242\220\332\221\261", "\226\242\220\332\221\261", "\226\242\220\332\221\261", "\226\242\220\332\221\261", "\226\242\220\332\221\261"},
    {"Controller", "\203R\203\223\203g\203\215\201[\203\211", "\203R\203\223\203g\203\215\201[\203\211", "\203R\203\223\203g\203\215\201[\203\211", "\203R\203\223\203g\203\215\201[\203\211", "\203R\203\223\203g\203\215\201[\203\211"},
    {"Speed Force", "\203X\203s\201[\203h\203t\203H\201[\203X", "\203X\203s\201[\203h\203t\203H\201[\203X", "\203X\203s\201[\203h\203t\203H\201[\203X", "\203X\203s\201[\203h\203t\203H\201[\203X", "\203X\203s\201[\203h\203t\203H\201[\203X"},
    {"Speed Force and Pedal Unit", "\203X\203s\201[\203h\203t\203H\201[\203X\201\225\203y\203_\203\213\203\206\203j\203b\203g", "\203X\203s\201[\203h\203t\203H\201[\203X\201\225\203y\203_\203\213\203\206\203j\203b\203g", "\203X\203s\201[\203h\203t\203H\201[\203X\201\225\203y\203_\203\213\203\206\203j\203b\203g", "\203X\203s\201[\203h\203t\203H\201[\203X\201\225\203y\203_\203\213\203\206\203j\203b\203g", "\203X\203s\201[\203h\203t\203H\201[\203X\201\225\203y\203_\203\213\203\206\203j\203b\203g"},
    {"Arcade", "\203A\201[\203P\201[\203h" "\203A\201[\203P\201[\203h" "\203A\201[\203P\201[\203h" "\203A\201[\203P\201[\203h" "\203A\201[\203P\201[\203h"},
};

OptionLabel lbl_4_data_16B4[9] = {
    {164, 160, "\201c\201c\201c\201c\201c\201c\201c\201c\201c\201c\201c"},
    {248, 180, "\201c\201c\201c\201c\201c\201c"},
    {332, 200, "\201c"},
    {214, 220, "\201c\201c\201c\201c\201c\201c\201c\201c"},
    {214, 240, "\201c\201c\201c\201c\201c\201c\201c\201c"},
    {198, 260, "\201c\201c\201c\201c\201c\201c\201c\201c\201c"},
    {214, 280, "\201c\201c\201c\201c\201c\201c\201c\201c"},
    {214, 300, "\201c\201c\201c\201c\201c\201c\201c\201c"},
    {164, 320, "\201c\201c\201c\201c\201c\201c\201c\201c\201c\201c\201c"},
};

char *lbl_4_data_182C[9][6] = {
    {"Steer", "", "", "", "", "\203X\203e\203A\203\212\203\223\203O\215\266\211E\201c"},
    {"Slide Left Right", "", "", "", "", "\203X\203\211\203C\203h\215\266\211E\201c\201c\201c"},
    {"Adjust Center of Gravity", "", "", "", "", "\203W\203\203\203\223\203v\217d\220S\210\332\223\256\201c"},
    {"Adjust View", "", "", "", "", "\216\213\223_\225\317\215X\201c\201c\201c\201c\201c"},
    {"Accelerate", "", "", "", "", "\203A\203N\203Z\203\213\201c\201c\201c\201c\201c"},
    {"Air Brake", "", "", "", "", "\203G\203A\203u\203\214\201[\203L\201c\201c\201c"},
    {"Side Attack", "", "", "", "", "\203T\203C\203h\203A\203^\203b\203N\201c\201c"},
    {"Spin Attack", "", "", "", "", "\203X\203s\203\223\203A\203^\203b\203N\201c\201c"},
    {"Boost", "", "", "", "", "\203u\201[\203X\203^\201[\201c\201c\201c\201c"},
};

char *lbl_4_data_1AF8[16][6] = {
    {"\203\265 Control Pad Left and Right", "\203\265 \203\320", "\203\265 \203\320", "\203\265 \203\320", "\203\265 \203\320", "\217\\\216\232\203{\203^\203\223\215\266\211E"},
    {"\203\265 Control Pad Up and Down", "\203\265 \203\317", "\203\265 \203\317", "\203\265 \203\317", "\203\265 \203\317", "\217\\\216\232\203{\203^\203\223\217\343\211\272"},
    {"A and B Button", "\203\237 \203\240", "\203\237 \203\240", "\203\237 \203\240", "\203\237 \203\240", "\202`\201\225\202a\203{\203^\203\223"},
    {"X and Y Button", "\203\264 \203\262", "\203\264 \203\262", "\203\264 \203\262", "\203\264 \203\262", "\202w\201\225\202x\203{\203^\203\223"},
    {"\203\255 Control Stick Left and Right", "\203\255 \203\320", "\203\255 \203\320", "\203\255 \203\320", "\203\255 \203\320", "\203R\203\223\203g\203\215\201[\203\213\203X\203e\203B\203b\203N\215\266\211E"},
    {"\203\255 Control Stick Up and Down", "\203\255 \203\317", "\203\255 \203\317", "\203\255 \203\317", "\203\255 \203\317", "\203R\203\223\203g\203\215\201[\203\213\203X\203e\203B\203b\203N\217\343\211\272"},
    {"\203\246 C Stick Left and Right", "\203\246 \203\320", "\203\246 \203\320", "\203\246 \203\320", "\203\246 \203\320", "\202b\203X\203e\203B\203b\203N\215\266\211E"},
    {"\203\246 C Stick Up and Down", "\203\246 \203\317", "\203\246 \203\317", "\203\246 \203\317", "\203\246 \203\317", "\202b\203X\203e\203B\203b\203N\217\343\211\272"},
    {"L and R Button", "", "", "", "", "\202k\201\225\202q\203g\203\212\203K\201[\203{\203^\203\223"},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"No Quotas", "", "", "", "", "\212\204\202\350\223\226\202\304\202\310\202\265"},
};

char *lbl_4_data_1CE0[16][6] = {
    {"\203\265 Control Pad Left and Right", "\203\265 \203\320", "\203\265 \203\320", "\203\265 \203\320", "\203\265 \203\320", "\217\\\216\232\203{\203^\203\223\215\266\211E"},
    {"\203\265 Control Pad Up and Down", "\203\265 \203\317", "\203\265 \203\317", "\203\265 \203\317", "\203\265 \203\317", "\217\\\216\232\203{\203^\203\223\217\343\211\272"},
    {"A and B Button", "\203\237 \203\240", "\203\237 \203\240", "\203\237 \203\240", "\203\237 \203\240", "\202`\201\225\202a\203{\203^\203\223"},
    {"X and Y Button", "\203\264 \203\262", "\203\264 \203\262", "\203\264 \203\262", "\203\264 \203\262", "\202w\201\225\202x\203{\203^\203\223"},
    {"Steering Wheel Left and Right", "", "", "", "", "\203n\203\223\203h\203\213\215\266\211E"},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"L and R Button", "", "", "", "", "\202k\201\225\202q\203g\203\212\203K\201[\203{\203^\203\223"},
    {"Accelerator and Break Pedal", "", "", "", "", "\203A\203N\203Z\203\213\201\225\203u\203\214\201[\203L\203y\203_\203\213"},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"No Quotas", "", "", "", "", "\212\204\202\350\223\226\202\304\202\310\202\265"},
};

char *lbl_4_data_2180[32][6] = {
    {"\203\265 Control Pad Left", "\203\265 Left", "\203\265 Left", "\203\265 Left", "\203\265 Left", "\217\\\216\232\203{\203^\203\223\215\266"},
    {"\203\265 Control Pad Right", "\203\265 Right", "\203\265 Right", "\203\265 Right", "\203\265 Right", "\217\\\216\232\203{\203^\203\223\211E"},
    {"\203\265 Control Pad Down", "\203\265 Down", "\203\265 Down", "\203\265 Down", "\203\265 Down", "\217\\\216\232\203{\203^\203\223\211\272"},
    {"\203\265 Control Pad Up", "\203\265 Up", "\203\265 Up", "\203\265 Up", "\203\265 Up", "\217\\\216\232\203{\203^\203\223\217\343"},
    {"Z Button", "\203\244 ", "\203\244 ", "\203\244 ", "\203\244 ", "\202y\203{\203^\203\223"},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"A Button", "\203\237", "\203\237", "\203\237", "\203\237", "\202`\203{\203^\203\223"},
    {"B Button", "\203\240 ", "\203\240 ", "\203\240 ", "\203\240 ", "\202a\203{\203^\203\223"},
    {"X Button", "\203\264 ", "\203\264 ", "\203\264 ", "\203\264 ", "\202w\203{\203^\203\223"},
    {"Y Button", "\203\262 ", "\203\262 ", "\203\262 ", "\203\262 ", "\202x\203{\203^\203\223"},
    {"\203\255 Control Stick Left", "", "", "", "", "\203R\203\223\203g\203\215\201[\203\213\203X\203e\203B\203b\203N\215\266"},
    {"\203\255 Control Stick Right", "\203\255 Right", "\203\255 Right", "\203\255 Right", "\203\255 Right", "\203R\203\223\203g\203\215\201[\203\213\203X\203e\203B\203b\203N\211E"},
    {"\203\255 Control Stick Down", "\203\255 Down", "\203\255 Down", "\203\255 Down", "\203\255 Down", "\203R\203\223\203g\203\215\201[\203\213\203X\203e\203B\203b\203N\211\272"},
    {"\203\255 Control Stick Up", "\203\255 Up", "\203\255 Up", "\203\255 Up", "\203\255 Up", "\203R\203\223\203g\203\215\201[\203\213\203X\203e\203B\203b\203N\217\343"},
    {"\203\246 C Stick Left", "\203\255 Left", "\203\255 Left", "\203\255 Left", "\203\255 Left", "\202b\203X\203e\203B\203b\203N\215\266"},
    {"\203\246 C Stick Right", "\203\246 Right", "\203\246 Right", "\203\246 Right", "\203\246 Right", "\202b\203X\203e\203B\203b\203N\211E"},
    {"\203\246 C Stick Down", "\203\246 Down", "\203\246 Down", "\203\246 Down", "\203\246 Down", "\202b\203X\203e\203B\203b\203N\211\272"},
    {"\203\246 C Stick Up", "\203\246 Up", "\203\246 Up", "\203\246 Up", "\203\246 Up", "\202b\203X\203e\203B\203b\203N\217\343"},
    {"L Button", "\203\241 ", "\203\241 ", "\203\241 ", "\203\241 ", "\202k\203g\203\212\203K\201[\203{\203^\203\223"},
    {"R Button", " \203\257 ", " \203\257 ", " \203\257 ", " \203\257 ", "\202q\203g\203\212\203K\201[\203{\203^\203\223"},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"No Quotas", "", "", "", "", "\212\204\202\350\223\226\202\304\202\310\202\265"},
};

char *lbl_4_data_2504[32][6] = {
    {"\203\265 Control Pad Left", "\203\265 Left", "\203\265 Left", "\203\265 Left", "\203\265 Left", "\217\\\216\232\203{\203^\203\223\215\266"},
    {"\203\265 Control Pad Right", "\203\265 Right", "\203\265 Right", "\203\265 Right", "\203\265 Right", "\217\\\216\232\203{\203^\203\223\211E"},
    {"\203\265 Control Pad Down", "\203\265 Down", "\203\265 Down", "\203\265 Down", "\203\265 Down", "\217\\\216\232\203{\203^\203\223\211\272"},
    {"\203\265 Control Pad Up", "\203\265 Up", "\203\265 Up", "\203\265 Up", "\203\265 Up", "\217\\\216\232\203{\203^\203\223\217\343"},
    {"Z Button", "\203\244 ", "\203\244 ", "\203\244 ", "\203\244 ", "\202y\203{\203^\203\223"},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"A Button", "\203\237", "\203\237", "\203\237", "\203\237", "\202`\203{\203^\203\223"},
    {"B Button", "\203\240 ", "\203\240 ", "\203\240 ", "\203\240 ", "\202a\203{\203^\203\223"},
    {"X Button", "\203\264 ", "\203\264 ", "\203\264 ", "\203\264 ", "\202w\203{\203^\203\223"},
    {"Y Button", "\203\262 ", "\203\262 ", "\203\262 ", "\203\262 ", "\202x\203{\203^\203\223"},
    {"Steering Wheel Left", "", "", "", "", "\203n\203\223\203h\203\213\215\266"},
    {"Steering Wheel Right", "", "", "", "", "\203n\203\223\203h\203\213\211E"},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"L Button", "\203\241 ", "\203\241 ", "\203\241 ", "\203\241 ", "\202k\203g\203\212\203K\201[\203{\203^\203\223"},
    {"R Button", " \203\257 ", " \203\257 ", " \203\257 ", " \203\257 ", "\202q\203g\203\212\203K\201[\203{\203^\203\223"},
    {"Accelerator Pedal", "", "", "", "", "\203A\203N\203Z\203\213\203y\203_\203\213"},
    {"Brake Pedal", "", "", "", "", "\203u\203\214\201[\203L\203y\203_\203\213"},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"", "", "", "", "", ""},
    {"No Quotas", "", "", "", "", "\212\204\202\350\223\226\202\304\202\310\202\265"},
};

char *lbl_4_data_281C[6] = {
    "AX Controls", "", "", "", "", "\202`\202w\202\314\221\200\215\354",
};

char *lbl_4_data_2858[6] = {
    "Default Settings", "", "", "", "", "\217\211\212\372\220\335\222\350\202\311\226\337\202\267",
};

char *lbl_4_data_295C[6] = {
    "Side Attack:Quickly press the L or R Button\n               twice.\nSpin Attack:Press the L and R Buttons\n               simultaneously and turn the wheel. ", "", "", "", "", "\203T\203C\203h\203A\203^\203b\203N\201c\203g\203\212\203K\201[\202Q\211\361\210\370\202\253\n\203X\203s\203\223\203A\203^\203b\203N\201c\203g\203\212\203K\201[\202k\202q\227\274\210\370\202\253\201\225\203n\203\223\203h\203\213",
};

/* Which of the three binding sets a controller kind uses. */

static inline s32 option_pad_slot(s32 kind) {
    s32 slot;
    switch (kind) {
    default:
    case 0:
    case 4:
        slot = 0;
        break;
    case 1:
        slot = 0;
        break;
    case 2:
        slot = 1;
        break;
    case 3:
        slot = 2;
        break;
    }
    return slot;
}

s32 fn_4_4B74(u32 arg0, u32 arg1) {
    u32 idx;
    u32 v;

    idx = option_pad_slot(arg0);

    switch (arg1) {
    case 0:
        v = lbl_4_bss_C4[idx].button[0];
        break;
    case 1:
        v = lbl_4_bss_C4[idx].button[1];
        break;
    case 2:
        v = lbl_4_bss_C4[idx].button[2];
        break;
    case 3:
        v = lbl_4_bss_C4[idx].button[3];
        break;
    case 4:
        v = lbl_4_bss_C4[idx].stick[0];
        break;
    case 5:
        v = lbl_4_bss_C4[idx].stick[1];
        break;
    case 6:
        v = lbl_4_bss_C4[idx].stick[2];
        break;
    case 7:
        v = lbl_4_bss_C4[idx].stick[3];
        break;
    case 8:
        v = lbl_4_bss_C4[idx].stick[4];
        break;
    }

    return 31 - __cntlzw(v);
}
/* fzgx:end fn_4_4B74 */

/* fzgx:begin fn_4_4CB8 */
void fn_4_4CB8(s32 arg0, u32 arg1, u32 arg2) {
    u32 mask;
    s32 slot;

    mask = 1 << arg2;
    slot = option_pad_slot(arg0);

    switch (arg1) {
    case 0:
        lbl_4_bss_C4[slot].button[0] = mask;
        break;
    case 1:
        lbl_4_bss_C4[slot].button[1] = mask;
        break;
    case 2:
        lbl_4_bss_C4[slot].button[2] = mask;
        break;
    case 3:
        lbl_4_bss_C4[slot].button[3] = mask;
        break;
    case 4:
        lbl_4_bss_C4[slot].stick[0] = mask;
        break;
    case 5:
        lbl_4_bss_C4[slot].stick[1] = mask;
        break;
    case 6:
        lbl_4_bss_C4[slot].stick[2] = mask;
        break;
    case 7:
        lbl_4_bss_C4[slot].stick[3] = mask;
        break;
    case 8:
        lbl_4_bss_C4[slot].stick[4] = mask;
        break;
    }
}
/* fzgx:end fn_4_4CB8 */

/* fzgx:begin fn_4_4DF8 */
static inline u32 fn_4_4DF8_get(s32 kind, s32 field) {
    s32 slot = option_pad_slot(kind);
    u32 value;
    switch (field) {
    case 0: value = lbl_4_bss_C4[slot].button[0]; break;
    case 1: value = lbl_4_bss_C4[slot].button[1]; break;
    case 2: value = lbl_4_bss_C4[slot].button[2]; break;
    case 3: value = lbl_4_bss_C4[slot].button[3]; break;
    case 4: value = lbl_4_bss_C4[slot].stick[0]; break;
    case 5: value = lbl_4_bss_C4[slot].stick[1]; break;
    case 6: value = lbl_4_bss_C4[slot].stick[2]; break;
    case 7: value = lbl_4_bss_C4[slot].stick[3]; break;
    case 8: value = lbl_4_bss_C4[slot].stick[4]; break;
    }
    return value;
}

/* Icon placement on the controller picture: the GameCube pad is drawn at 1.40625x from (140, 144). */

#define FN_4_4DF8_PLACE_GC(p)                                 \
    (p).x = 140.0 + 1.40625 * (p).x;                          \
    (p).y = 144.0 + 1.40625 * (p).y;                          \
    (p).scale_x = (p).scale_y = 1.40625 * (p).scale_x

#define FN_4_4DF8_PLACE(p, kind)                              \
    if (kind == 2) {                                        \
        (p).x = 192.0 + (p).x;                                \
        (p).y = 142.0 + (p).y;                                \
        (p).scale_y = (p).scale_x;                            \
    } else {                                                  \
        (p).x = 87.125 + 0.85 * (p).x;                        \
        (p).y = 173.0 + 0.85 * (p).y;                         \
        (p).scale_x = (p).scale_y = 0.85 * (p).scale_x;       \
    }

/* Blends two colours with the cursor blink timer. */
static u32 option_blink_color(GXColor from, GXColor to, f32 t) {
    return fn_80007F70(&from, &to, lbl_4_bss_2, t);
}

void fn_4_4DF8(void) {
    u32 i;
    u32 kind;
    u32 v;
    u32 bit;
    char *name;
    u8 sel;
    u32 n;
    s32 draw;
    f32 y;
    char buf[256];
    f32 width;
    FontDrawPacket p;

    {
        GXColor bg = {0xFF, 0xFF, 0xFF, 0xA0};
        fn_1_53BD8(&bg, 320.0f, 274.0f, 573.0f, 271.0f, 0.15f);
    }
    kind = fn_1_3BB0(lbl_4_bss_118);
    fn_1_49410();
    fn_1_4955C(0.8333333f, 0.8333333f);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    sprintf(buf, lbl_4_data_14F4, lbl_4_data_60[lbl_801A66B4], lbl_4_bss_118 + 1,
            lbl_4_data_15E8[kind][lbl_801A66B4]);
    fn_1_53E40(NULL, 320.0f, 100.0f, 0.05f, 48.0f, 0.8333333f, buf);
    fn_1_49410();
    if (lbl_801A66B4 != 5) {
        fn_1_4955C(0.7f, 0.8333333f);
    } else {
        fn_1_4955C(0.8333333f, 0.8333333f);
    }
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    if (lbl_4_bss_119 != lbl_4_bss_11A) {
        lbl_4_bss_119 = lbl_4_bss_11A;
        lbl_4_bss_2 = 0;
    }
    if ((u8)(lbl_4_bss_11B - 2) <= 2 || lbl_4_bss_11B == 5) {
        if (lbl_4_bss_11A < 9) {
            y = 160.0 + 20.0 * (0.5 + lbl_4_bss_11A);
        } else {
            y = 10.0 + (160.0 + 20.0 * (0.5 + lbl_4_bss_11A));
        }
        width = 500.0f;
        if (lbl_4_bss_11B == 2) {
            option_draw_cursor(320.0f, y, 0.1f, width, 0.0f, 0.8333333f);
        } else {
            option_draw_cursor_dim(320.0f, y, 0.1f, width, 0.0f, 0.8333333f);
        }
    }
    fn_1_496FC(62.0f, 160.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    for (i = 0; i < 11; i++) {
        if (i < 9) {
            v = fn_4_4DF8_get(kind, i);
            bit = 31 - __cntlzw(v);
            if (i < 4) {
                if (kind == 1) {
                    name = lbl_4_data_1AF8[bit][lbl_801A66B4];
                } else {
                    name = lbl_4_data_1CE0[bit][lbl_801A66B4];
                }
            } else if (kind == 1) {
                name = lbl_4_data_2180[bit][lbl_801A66B4];
            } else {
                name = lbl_4_data_2504[bit][lbl_801A66B4];
            }
            if (lbl_4_bss_11B == 3 && lbl_4_bss_11A == i) {
                fn_1_49748(3.0f);
                {
                    static const GXColor c = {0xD0, 0x80, 0x80, 0x00};
                    fn_1_49514(c);
                }
            }
            if (lbl_801A66B4 == 5) {
                fn_1_4AE0C("%s%s\n", lbl_4_data_182C[i][lbl_801A66B4], name);
            } else {
                fn_1_4AE0C(lbl_4_data_1210, lbl_4_data_182C[i][lbl_801A66B4], name);
                fn_1_496FC(lbl_4_data_16B4[i].x - 43, lbl_4_data_16B4[i].y);
                fn_1_4AE0C(lbl_4_data_1210, lbl_4_data_16B4[i].text);
                fn_1_4955C(0.7f, 0.8333333f);
                fn_1_4AE0C("%s\n", name);
                fn_1_4955C(0.7f, 0.8333333f);
                fn_1_496FC(62.0f, (i + 1) * 20 + 160);
                fn_1_4954C(0.05f);
            }
            if (lbl_4_bss_11B == 3 && lbl_4_bss_11A == i) {
                fn_1_49748(5.0f);
                {
                    static const GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
                    fn_1_49514(c);
                }
            }
        } else if (i == 9) {
            if (kind == 1) {
                sel = 1;
            } else if (lbl_4_bss_11B == 4) {
                sel = lbl_4_bss_11C;
            } else {
                sel = 1 - lbl_4_bss_11D;
            }
            fn_1_496FC(62.0f, 350.0f);
            if (lbl_801A66B4 != 5) {
                fn_1_495B0(0x80000000);
                fn_1_49590(0.5f);
            }
            if (kind == 1) {
                static const GXColor c = {0x80, 0x80, 0x80, 0x00};
                fn_1_49514(c);
            } else if (lbl_4_bss_11B == 4 && lbl_4_bss_11A == i) {
                fn_1_49748(3.0f);
                {
                    static const GXColor c = {0xD0, 0x80, 0x80, 0x00};
                    fn_1_49514(c);
                }
            }
            fn_1_4AE0C("%s\x81\x63%s", lbl_4_data_281C[lbl_801A66B4], lbl_4_data_80[sel][lbl_801A66B4]);
            if (kind == 1 || (lbl_4_bss_11B == 4 && lbl_4_bss_11A == i)) {
                fn_1_49748(5.0f);
                {
                    static const GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
                    fn_1_49514(c);
                }
            }
            if (sel == 0) {
                fn_1_4DC20();
                fn_1_496FC(248.0f, 350.0f);
                if (lbl_801A66B4 != 5) {
                    fn_1_4955C(0.58f, 0.55f);
                } else {
                    fn_1_4955C(0.63666666f, 0.8333333f);
                }
                fn_1_4954C(0.005f);
                fn_1_4A0D8(lbl_4_data_295C[lbl_801A66B4]);
                fn_1_53BD8(NULL, 434.0f, 377.0f, 400.0f, 75.0f, 0.025f);
                fn_1_4DC6C();
            }
        } else if (i == 10) {
            fn_1_496FC(62.0f, 370.0f);
            if (lbl_4_bss_11B == 5 && lbl_4_bss_11A == i) {
                fn_1_49748(3.0f);
                {
                    static const GXColor c = {0xD0, 0x80, 0x80, 0x00};
                    fn_1_49514(c);
                }
            }
            fn_1_4A0D8(lbl_4_data_2858[lbl_801A66B4]);
            if (lbl_4_bss_11B == 5 && lbl_4_bss_11A == i) {
                fn_1_49748(5.0f);
                {
                    static const GXColor c = {0xFF, 0xFF, 0xFF, 0x00};
                    fn_1_49514(c);
                }
            }
        }
    }

    v = fn_4_4DF8_get(kind, lbl_4_bss_11A);
    bit = 31 - __cntlzw(v);
    n = 31 - bit;
    p = lbl_1_rodata_26F8;
    switch (kind) {
    case 1:
    default:
        p.image = 0x9000;
        p.x = 140.0f;
        p.y = 144.0f;
        p.z = 0.35f;
        p.scale_x = p.scale_y = 1.40625f;
        fn_1_4F734(&p);
        draw = 1;
        p.flags = 10;
        p.scale_x = 1.0f;
        p.z = 0.3f;
        {
            static const GXColor from = {0x00, 0xFF, 0xFF, 0x00};
            static const GXColor to = {0x00, 0x80, 0x80, 0x00};
            *(u32 *)&p.color = option_blink_color(from, to, 1.0f);
        }
        if (lbl_4_bss_11A < 4) {
            switch (n) {
            case 31:
            case 30:
                p.image = 0x9006;
                p.x = 89.0f;
                p.y = 127.0f;
                break;
            case 29:
                p.image = 0x9005;
                p.x = 176.0f;
                p.y = 88.0f;
                p.scale_x = 0.6f;
                break;
            case 28:
                p.image = 0x9008;
                p.x = 231.0f;
                p.y = 67.0f;
                break;
            case 27:
            case 26:
                p.image = 0x9005;
                p.x = 55.0f;
                p.y = 76.0f;
                break;
            case 25:
            case 24:
                p.image = 0x9005;
                p.x = 168.0f;
                p.y = 126.0f;
                break;
            case 23:
                p.image = 0x9007;
                p.x = 47.0f;
                p.y = 24.0f;
                break;
            default:
                draw = 0;
                break;
            }
            if (draw) {
                FN_4_4DF8_PLACE_GC(p);
                fn_1_4F734(&p);
            }
            p.flags = 10;
            draw = 1;
            p.scale_x = 1.0f;
            switch (n) {
            case 29:
                p.image = 0x9005;
                p.x = 204.0f;
                p.y = 74.0f;
                break;
            case 28:
                p.image = 0x9009;
                p.x = 197.0f;
                p.y = 48.0f;
                break;
            case 23:
                p.image = 0x9007;
                p.x = 211.0f;
                p.y = 24.0f;
                p.flags |= 0x80000;
                break;
            default:
                draw = 0;
                break;
            }
            if (draw) {
                FN_4_4DF8_PLACE_GC(p);
                fn_1_4F734(&p);
            }
        } else {
            switch (n) {
            case 31:
            case 30:
            case 29:
            case 28:
                p.image = 0x9006;
                p.x = 89.0f;
                p.y = 127.0f;
                break;
            case 27:
                p.image = 0x900A;
                p.x = 211.0f;
                p.y = 26.0f;
                break;
            case 23:
                p.image = 0x9005;
                p.x = 204.0f;
                p.y = 74.0f;
                break;
            case 22:
                p.image = 0x9005;
                p.x = 176.0f;
                p.y = 88.0f;
                p.scale_x = 0.6f;
                break;
            case 21:
                p.image = 0x9008;
                p.x = 231.0f;
                p.y = 67.0f;
                break;
            case 20:
                p.image = 0x9009;
                p.x = 197.0f;
                p.y = 48.0f;
                break;
            case 19:
            case 18:
            case 17:
            case 16:
                p.image = 0x9005;
                p.x = 55.0f;
                p.y = 76.0f;
                break;
            case 15:
            case 14:
            case 13:
            case 12:
                p.image = 0x9005;
                p.x = 168.0f;
                p.y = 126.0f;
                break;
            case 11:
                p.image = 0x9007;
                p.x = 47.0f;
                p.y = 24.0f;
                break;
            case 10:
                p.image = 0x9007;
                p.x = 211.0f;
                p.y = 24.0f;
                p.flags |= 0x80000;
                break;
            default:
                draw = 0;
                break;
            }
            if (draw) {
                FN_4_4DF8_PLACE_GC(p);
                fn_1_4F734(&p);
            }
        }
        break;
    case 2:
    case 3:
        if (kind == 2) {
            p.image = 0x9002;
            p.x = 192.0f;
            p.y = 142.0f;
            p.z = 0.35f;
            fn_1_4F734(&p);
        } else {
            p.image = 0x9002;
            p.x = 87.125f;
            p.y = 173.0f;
            p.z = 0.35f;
            p.scale_x = p.scale_y = 0.85f;
            fn_1_4F734(&p);
            p.image = 0x9003;
            p.x = 328.515f;
            p.y = 173.0f;
            p.z = 0.35f;
            p.scale_x = p.scale_y = 0.85f;
            fn_1_4F734(&p);
        }
        draw = 1;
        p.flags = 10;
        p.scale_x = 1.0f;
        p.z = 0.3f;
        {
            static const GXColor from = {0x00, 0xFF, 0xFF, 0x00};
            static const GXColor to = {0x00, 0x80, 0x80, 0x00};
            *(u32 *)&p.color = option_blink_color(from, to, 1.0f);
        }
        if (lbl_4_bss_11A < 4) {
            switch (n) {
            case 31:
            case 30:
                p.image = 0x900D;
                p.x = 59.0f;
                p.y = 134.0f;
                break;
            case 27:
                p.image = 0x900C;
                p.x = 128.0f;
                p.y = 128.0f;
                p.flags = 11;
                break;
            case 29:
                p.image = 0x900B;
                p.x = 194.0f;
                p.y = 141.0f;
                p.scale_x = 0.6f;
                break;
            case 28:
                p.image = 0x900F;
                p.x = 189.0f;
                p.y = 108.0f;
                break;
            case 23:
                p.image = 0x900E;
                p.x = 60.0f;
                p.y = 135.0f;
                break;
            default:
                draw = 0;
                break;
            }
            if (draw) {
                FN_4_4DF8_PLACE(p, kind);
                fn_1_4F734(&p);
            }
            p.flags = 10;
            draw = 1;
            p.scale_x = 1.0f;
            switch (n) {
            case 27:
                p.image = 0x900C;
                p.x = 128.0f;
                p.y = 128.0f;
                p.flags = 0x80009;
                break;
            case 29:
                p.image = 0x900B;
                p.x = 189.0f;
                p.y = 123.0f;
                break;
            case 28:
                p.image = 0x900F;
                p.x = 174.0f;
                p.y = 128.0f;
                p.rotation_z = -0x4000;
                break;
            case 23:
                p.image = 0x900E;
                p.x = 196.0f;
                p.y = 135.0f;
                p.flags |= 0x80000;
                break;
            default:
                draw = 0;
                break;
            }
            if (draw) {
                FN_4_4DF8_PLACE(p, kind);
                fn_1_4F734(&p);
            }
        } else {
            switch (n) {
            case 19:
                p.image = 0x900C;
                p.x = 128.0f;
                p.y = 128.0f;
                p.flags = 11;
                break;
            case 18:
                p.image = 0x900C;
                p.x = 128.0f;
                p.y = 128.0f;
                p.flags = 0x80009;
                break;
            case 31:
            case 30:
            case 29:
            case 28:
                p.image = 0x900D;
                p.x = 59.0f;
                p.y = 134.0f;
                break;
            case 27:
                p.image = 0x900B;
                p.x = 63.0f;
                p.y = 111.0f;
                p.scale_x = 0.55f;
                break;
            case 23:
                p.image = 0x900B;
                p.x = 189.0f;
                p.y = 123.0f;
                break;
            case 22:
                p.image = 0x900B;
                p.x = 194.0f;
                p.y = 141.0f;
                p.scale_x = 0.6f;
                break;
            case 21:
                p.image = 0x900F;
                p.x = 189.0f;
                p.y = 108.0f;
                break;
            case 20:
                p.image = 0x900F;
                p.x = 174.0f;
                p.y = 128.0f;
                p.rotation_z = -0x4000;
                break;
            case 11:
                p.image = 0x900E;
                p.x = 60.0f;
                p.y = 135.0f;
                break;
            case 10:
                p.image = 0x900E;
                p.x = 196.0f;
                p.y = 135.0f;
                p.flags |= 0x80000;
                break;
            default:
                draw = 0;
                break;
            }
            if (draw) {
                FN_4_4DF8_PLACE(p, kind);
                fn_1_4F734(&p);
            }
        }
        if (kind != 2) {
            p.flags = 10;
            p.scale_x = p.scale_y = 0.85f;
            if (lbl_4_bss_11A < 4) {
                if (n == 22) {
                    p.image = 0x9011;
                    p.x = 479.815f;
                    p.y = 233.35f;
                    fn_1_4F734(&p);
                    p.image = 0x9010;
                    p.x = 394.815f;
                    p.y = 226.55f;
                    fn_1_4F734(&p);
                }
            } else if (n == 9) {
                p.image = 0x9011;
                p.x = 479.815f;
                p.y = 233.35f;
                fn_1_4F734(&p);
            } else if (n == 8) {
                p.image = 0x9010;
                p.x = 394.815f;
                p.y = 226.55f;
                fn_1_4F734(&p);
            }
        }
        break;
    }
}
/* fzgx:end fn_4_4DF8 */

/* fzgx:begin fn_4_63D4 */
void fn_4_63D4(void) {
char *str;
u32 flags;
u8 count;
char buf[512];
str = lbl_4_data_1A4[lbl_801A66B4];
flags = 0x20000000;
fn_1_49410();
fn_1_495C8(1);
if (lbl_801A66B4 != 5) {
fn_1_495B0(0x80000000);
fn_1_49590(0.5f);
}
switch (lbl_4_bss_11B) {
case 0:
flags = 0x28000000;
str = lbl_4_data_23C[lbl_801A66B4];
fn_1_49738(fn_1_5233C);
fn_1_49748(5.0f);
option_draw_title(240.0f, 0.8f, lbl_4_data_778[lbl_801A66B4]);
break;
case 1:
if (lbl_4_bss_11E == 0) {
flags = 0;
str = lbl_4_data_1A4[lbl_801A66B4];
} else {
flags = 0x48000000;
str = lbl_4_data_E8[lbl_801A66B4];
fn_4_2D4(lbl_4_bss_11C & 1, lbl_4_data_884[lbl_801A66B4]);
}
break;
case 2:
flags = 0x28000000;
str = lbl_4_data_E8[lbl_801A66B4];
fn_4_4DF8();
break;
case 3:
case 4:
flags = 0x48000000;
str = lbl_4_data_158[lbl_801A66B4];
fn_4_4DF8();
break;
case 5:
flags = 0x48000000;
str = lbl_4_data_E8[lbl_801A66B4];
fn_4_2D4(lbl_4_bss_11C, lbl_4_data_364[lbl_801A66B4]);
fn_4_4DF8();
break;
case 6:
flags = 0x48000000;
str = lbl_4_data_E8[lbl_801A66B4];
fn_4_2D4(lbl_4_bss_11C, lbl_4_data_8C0[lbl_801A66B4]);
fn_4_4DF8();
break;
case 7:
count = lbl_4_bss_118;
str = "";
flags = 0;
fn_1_49410();
fn_1_49738(fn_1_5233C);
fn_1_49748(5.0f);
if (lbl_801A66B4 != 5) {
fn_1_495B0(0x80000000);
fn_1_49590(0.5f);
}
sprintf(buf, lbl_4_data_560[lbl_801A66B4], count + 1);
option_draw_title(240.0f, 0.8f, buf);
break;
}
fn_1_1380F0(str);
fn_1_13ABA8(flags);
}
/* fzgx:end fn_4_63D4 */

/* fzgx:begin fn_4_6678 */
void fn_4_6678(void) {
    u32 t1;
    fn_1_435C(lbl_4_bss_8);
    t1 = fn_1_3F8C((u32)"option_pcust_disp", (u32)fn_4_63D4, 0, 5);
    lbl_4_bss_0 = t1;
    fn_80008BA8(lbl_4_bss_120, lbl_1_bss_AA0, sizeof(lbl_4_bss_120));
    memcpy(lbl_4_bss_270, lbl_1_data_2B60, sizeof(lbl_4_bss_270));
    lbl_4_bss_11B = 0;
    lbl_4_bss_274 = 255;
    lbl_4_bss_118 = 0;
    lbl_4_bss_11E = 0;
    lbl_4_bss_10 = 0;
    fn_1_4A00(1, 15, lbl_4_bss_8);
}
/* fzgx:end fn_4_6678 */

/* fzgx:begin fn_4_6720 */
static inline u32 opt_type_index(s32 type) {
    u32 idx;
    switch (type) {
    case 0:
    case 4:
    default:
        idx = 0;
        break;
    case 1:
        idx = 0;
        break;
    case 2:
        idx = 1;
        break;
    case 3:
        idx = 2;
        break;
    }
    return idx;
}

static inline u32 opt_cfg_get_bit(PadCfg *cfg, s32 type, u8 item) {
    u32 v;
    u32 idx = opt_type_index(type);
    switch (item) {
    case 0: v = cfg[idx].button[0]; break;
    case 1: v = cfg[idx].button[1]; break;
    case 2: v = cfg[idx].button[2]; break;
    case 3: v = cfg[idx].button[3]; break;
    case 4: v = cfg[idx].stick[0]; break;
    case 5: v = cfg[idx].stick[1]; break;
    case 6: v = cfg[idx].stick[2]; break;
    case 7: v = cfg[idx].stick[3]; break;
    case 8: v = cfg[idx].stick[4]; break;
    }
    return 31 - __cntlzw(v);
}

static inline void opt_cfg_set_bit(PadCfg *cfg, s32 type, u8 item, u32 bit) {
    u32 v = 1 << bit;
    u32 idx = opt_type_index(type);
    switch (item) {
    case 0: cfg[idx].button[0] = v; break;
    case 1: cfg[idx].button[1] = v; break;
    case 2: cfg[idx].button[2] = v; break;
    case 3: cfg[idx].button[3] = v; break;
    case 4: cfg[idx].stick[0] = v; break;
    case 5: cfg[idx].stick[1] = v; break;
    case 6: cfg[idx].stick[2] = v; break;
    case 7: cfg[idx].stick[3] = v; break;
    case 8: cfg[idx].stick[4] = v; break;
    }
}


void fn_4_6720(void) {
    u32 i;
    u8 port;
    u8 old;
    s32 type;
    u32 v;
    u32 bit;
    u32 idx;

    if (lbl_4_bss_10 != 0) {
        if (fn_1_4C10() == 0) {
            fn_1_1280(1);
            lbl_1_bss_96A = lbl_4_bss_10;
            lbl_4_bss_10 = 0;
        }
        return;
    }
    if (lbl_4_bss_274 != 0xFF) {
        lbl_4_bss_11B = lbl_4_bss_274;
        lbl_4_bss_274 = 0xFF;
    }
    switch (lbl_4_bss_11B) {
    case 0:
        if (PAD_BIT(lbl_1_bss_9F8[0].trig, 9)) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_11C = 0;
            lbl_4_bss_11B = 1;
            return;
        }
        for (i = 0; i < 4; i++) {
            if (PAD_BIT(lbl_1_bss_9F8[i].trig, 8)) {
                fn_1_A2D84(0xA9010100);
                port = i;
                lbl_4_bss_11A = 0;
                lbl_4_bss_118 = i;
                lbl_4_bss_274 = 2;
                fn_80008BA8(lbl_4_bss_C4, lbl_1_bss_AA0[port], sizeof(lbl_4_bss_C4));
                lbl_4_bss_11D = lbl_1_data_2B60[port];
                return;
            }
        }
        break;
    case 1:
        if (lbl_4_bss_11E == 0) {
            lbl_4_bss_10 = 0x4D;
            fn_1_4A00(0, 15, lbl_4_bss_8);
            return;
        }
        lbl_4_bss_11C = fn_4_0(lbl_4_bss_11C, 0, 1, -1, 1);
        if (PAD_BIT(lbl_1_bss_9F8[0].trig, 9)) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_274 = 0;
            return;
        }
        if (!PAD_BIT(lbl_1_bss_9F8[0].trig, 8)) {
            return;
        }
        fn_1_A2D84(0xA9010100);
        switch (lbl_4_bss_11C) {
        case 0:
            lbl_4_bss_E = 1;
            fn_80008BA8(lbl_1_bss_718E0.pad_cfg, lbl_1_bss_AA0, sizeof(lbl_1_bss_AA0));
            memcpy(lbl_1_bss_718E0.rumble, lbl_1_data_2B60, sizeof(lbl_1_data_2B60));
            break;
        case 1:
            lbl_4_bss_11E = 0;
            fn_80008BA8(lbl_1_bss_AA0, lbl_4_bss_120, sizeof(lbl_1_bss_AA0));
            memcpy(lbl_1_data_2B60, lbl_4_bss_270, sizeof(lbl_1_data_2B60));
            break;
        }
        if (lbl_4_bss_E != 0) {
            lbl_4_bss_B8 = 0x4D;
            lbl_4_bss_10 = 0x4C;
        } else {
            lbl_4_bss_10 = 0x4D;
            fn_1_4A00(0, 15, lbl_4_bss_8);
        }
        break;
    case 2:
        if (lbl_1_bss_980[lbl_4_bss_118] & 0x48) {
            lbl_4_bss_274 = 7;
            return;
        }
        old = lbl_4_bss_11A;
        lbl_4_bss_11A = fn_4_0(old, 0, 10, lbl_4_bss_118, 0);
        if (lbl_4_bss_11A == 9 && fn_1_3BB0(lbl_4_bss_118) == 1) {
            if (old > lbl_4_bss_11A) {
                lbl_4_bss_11A--;
            } else {
                lbl_4_bss_11A++;
            }
        }
        if (PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].trig, 8)) {
            fn_1_A2D84(0xA9010100);
            if (lbl_4_bss_11A == 10) {
                lbl_4_bss_11C = 1;
                lbl_4_bss_274 = 5;
                return;
            }
            if (lbl_4_bss_11A == 9) {
                lbl_4_bss_11C = 1 - lbl_4_bss_11D;
                lbl_4_bss_274 = 4;
                return;
            }
            lbl_4_bss_278 = fn_1_3BB0(lbl_4_bss_118);
            lbl_4_bss_27C = opt_cfg_get_bit(lbl_4_bss_C4, lbl_4_bss_278, lbl_4_bss_11A);
            lbl_4_bss_274 = 3;
            return;
        }
        if (PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].trig, 9)) {
            fn_1_A2D84(0xA9010200);
            if (fn_8008023C(lbl_4_bss_C4, lbl_1_bss_AA0[lbl_4_bss_118], sizeof(lbl_4_bss_C4)) == 0 &&
                lbl_4_bss_11D == lbl_1_data_2B60[lbl_4_bss_118]) {
                lbl_4_bss_274 = 0;
                return;
            }
            lbl_4_bss_11C = 0;
            lbl_4_bss_274 = 6;
            return;
        }
        break;
    case 3:
        if (lbl_1_bss_980[lbl_4_bss_118] & 0x48) {
            if (lbl_4_bss_11A != 10 && lbl_4_bss_11A != 9) {
                opt_cfg_set_bit(lbl_4_bss_C4, lbl_4_bss_278, lbl_4_bss_11A, lbl_4_bss_27C);
            }
            lbl_4_bss_274 = 7;
            return;
        }
        type = fn_1_3BB0(lbl_4_bss_118);
        bit = opt_cfg_get_bit(lbl_4_bss_C4, type, lbl_4_bss_11A);
        if (PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].rep, 0) || PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].unk_12, 0)) {
            idx = opt_type_index(type);
            fn_1_A2D84(0xA9010300);
            if (lbl_4_bss_11A < 4) {
                do {
                    bit = bit == 0 ? 15 : bit - 1;
                } while (!(__rlwnm(lbl_4_data_1520[idx], (32 - bit) & 31, 31, 31)));
            } else {
                do {
                    bit = bit == 0 ? 31 : bit - 1;
                } while (!(__rlwnm(lbl_4_data_1528[idx], (32 - bit) & 31, 31, 31)));
            }
            opt_cfg_set_bit(lbl_4_bss_C4, type, lbl_4_bss_11A, bit);
        } else if (PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].rep, 1) || PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].unk_12, 1)) {
            idx = opt_type_index(type);
            fn_1_A2D84(0xA9010300);
            if (lbl_4_bss_11A < 4) {
                do {
                    if (bit == 15) {
                        bit = 0;
                    } else {
                        bit++;
                    }
                } while (!(__rlwnm(lbl_4_data_1520[idx], (32 - bit) & 31, 31, 31)));
            } else {
                do {
                    if (bit == 31) {
                        bit = 0;
                    } else {
                        bit++;
                    }
                } while (!(__rlwnm(lbl_4_data_1528[idx], (32 - bit) & 31, 31, 31)));
            }
            opt_cfg_set_bit(lbl_4_bss_C4, type, lbl_4_bss_11A, bit);
        }
        if (PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].trig, 9)) {
            fn_1_A2D84(0xA9010200);
            opt_cfg_set_bit(lbl_4_bss_C4, type, lbl_4_bss_11A, lbl_4_bss_27C);
            lbl_4_bss_274 = 2;
            return;
        }
        if (PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].trig, 8)) {
            fn_1_A2D84(0xA9010100);
            lbl_4_bss_274 = 2;
        }
        break;
    case 4:
        if (lbl_1_bss_980[lbl_4_bss_118] & 0x48) {
            lbl_4_bss_274 = 7;
            return;
        }
        if ((PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].rep, 0) || PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].unk_12, 0)) && lbl_4_bss_11C == 1) {
            lbl_4_bss_11C = 0;
            fn_1_A2D84(0xA9010000);
        } else if ((PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].rep, 1) || PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].unk_12, 1)) && lbl_4_bss_11C == 0) {
            lbl_4_bss_11C = 1;
            fn_1_A2D84(0xA9010000);
        }
        if (PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].trig, 9)) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_274 = 2;
            return;
        }
        if (PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].trig, 8)) {
            fn_1_A2D84(0xA9010100);
            lbl_4_bss_11D = 1 - lbl_4_bss_11C;
            lbl_4_bss_274 = 2;
        }
        break;
    case 5:
        if (lbl_1_bss_980[lbl_4_bss_118] & 0x48) {
            lbl_4_bss_274 = 7;
            return;
        }
        if ((PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].rep, 0) || PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].unk_12, 0)) && lbl_4_bss_11C == 1) {
            lbl_4_bss_11C = 0;
            fn_1_A2D84(0xA9010000);
        } else if ((PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].rep, 1) || PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].unk_12, 1)) && lbl_4_bss_11C == 0) {
            lbl_4_bss_11C = 1;
            fn_1_A2D84(0xA9010000);
        }
        if (PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].trig, 9)) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_274 = 2;
            return;
        }
        if (PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].trig, 8)) {
            fn_1_A2D84(0xA9010100);
            if (lbl_4_bss_11C == 0) {
                idx = opt_type_index(fn_1_3BB0(lbl_4_bss_118));
                fn_80008BA8(&lbl_4_bss_C4[idx], &lbl_1_rodata_108[idx], sizeof(PadCfg));
                if (idx == 1 || idx == 2) {
                    lbl_4_bss_11D = 1;
                }
            }
            lbl_4_bss_274 = 2;
        }
        break;
    case 6:
        if (lbl_1_bss_980[lbl_4_bss_118] & 0x48) {
            lbl_4_bss_274 = 7;
            return;
        }
        lbl_4_bss_11C = fn_4_0(lbl_4_bss_11C, 0, 1, lbl_4_bss_118, 1);
        if (PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].trig, 9)) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_274 = 2;
            return;
        }
        if (PAD_BIT(lbl_1_bss_9F8[lbl_4_bss_118].trig, 8)) {
            fn_1_A2D84(0xA9010100);
            if (lbl_4_bss_11C == 0) {
                port = lbl_4_bss_118;
                fn_80008BA8(lbl_1_bss_AA0[port], lbl_4_bss_C4, sizeof(lbl_4_bss_C4));
                lbl_1_data_2B60[port] = lbl_4_bss_11D;
                lbl_4_bss_11E = 1;
            }
            lbl_4_bss_274 = 0;
        }
        break;
    case 7:
        v = lbl_1_bss_980[lbl_4_bss_118];
        if (v & 0x48) {
            if (PAD_BIT(lbl_1_bss_D58.trig, 8)) {
                fn_1_A2D84(0xA9010100);
                lbl_4_bss_11B = 0;
            }
            return;
        }
        if (v == 0x09000000 || v == 0x88000000 || v == 0x8B100000 || v == 0x08000000) {
            fn_1_A2D84(0xA9010100);
            lbl_4_bss_11B = 2;
        }
        break;
    }
}
/* fzgx:end fn_4_6720 */

/* fzgx:begin fn_4_78E0 */
/* Clears the pending option state after notifying the option handlers. */

void fn_4_78E0(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_78E0 */

/* fzgx:begin fn_4_7938 */
/* The controller settings menu: Calibration, Customize, Controller Rumble. */

OptionMenuItem lbl_4_data_2C58[3] = {
    {0x50, {"Calibration", "", "", "", "", "\203L\203\203\203\212\203u\203\214\201[\203V\203\207\203\223"}},
    {0x52, {"Customize", "", "", "", "", "\203J\203X\203^\203}\203C\203Y"}},
    {0x51, {"Controller Rumble", "", "", "", "", "\203R\203\223\203g\203\215\201[\203\211\220U\223\256"}},
};

void fn_4_7938(void) {
    fn_1_49410();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    option_draw_title(110.0f, 1.0f, lbl_4_data_958[lbl_801A66B4]);
    option_draw_menu(lbl_4_data_2C58, 3, &lbl_4_bss_C);
    fn_1_1380F0(lbl_4_data_E8[lbl_801A66B4]);
    fn_1_13ABA8(0x28000000);
}
/* fzgx:end fn_4_7938 */

/* fzgx:begin fn_4_7C38 */
void fn_4_7C38(void) {
    fn_1_435C(lbl_4_bss_8);
    lbl_4_bss_0 = fn_1_3F8C((u32)"option_ctrl_menu_disp", (u32)fn_4_7938, 0, 5);
    lbl_4_bss_10 = 0;
    fn_1_4A00(1, 15, lbl_4_bss_8);
}
/* fzgx:end fn_4_7C38 */

/* fzgx:begin fn_4_7CA4 */
void fn_4_7CA4(void) {
    if (lbl_4_bss_10 != 0) {
        if (fn_1_4C10() == 0) {
            fn_1_1280(1);
            lbl_1_bss_96A = lbl_4_bss_10;
            lbl_4_bss_10 = 0;
        }
        return;
    }
    lbl_4_bss_C = fn_4_0(lbl_4_bss_C, 0, 2, -1, 0);
    if ((lbl_1_bss_9F8[0].trig >> 9) & 1) {
        fn_1_A2D84(0xA9010200);
        lbl_4_bss_10 = 75;
    } else if ((lbl_1_bss_9F8[0].trig >> 8) & 1) {
        fn_1_A2D84(0xA9010100);
        lbl_4_bss_10 = lbl_4_data_2C58[lbl_4_bss_C].id;
    } else {
        return;
    }
    fn_1_4A00(0, 15, lbl_4_bss_8);
}
/* fzgx:end fn_4_7CA4 */

/* fzgx:begin fn_4_7D94 */
// Reset the option subsystem after releasing its active resource.

void fn_4_7D94(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_7D94 */

/* fzgx:begin fn_4_7DEC */
/* The memory card menu: Manage All Forms of Game Data, Manage Game Data. */

OptionMenuItem lbl_4_data_2D24[2] = {
    {0x53, {"Manage All Forms of Game Data", "", "", "", "", "\212e\216\355\203Z\201[\203u\203f\201[\203^\212\307\227\235"}},
    {0x54, {"Manage Game Data", "", "", "", "", "\203Q\201[\203\200\203f\201[\203^\212\307\227\235"}},
};

void fn_4_7DEC(void) {
    fn_1_49410();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    option_draw_title(110.0f, 1.0f, lbl_4_data_9A8[lbl_801A66B4]);
    option_draw_menu(lbl_4_data_2D24, 2, &lbl_4_bss_D);
    fn_1_1380F0(lbl_4_data_E8[lbl_801A66B4]);
    fn_1_13ABA8(0x28000000);
}
/* fzgx:end fn_4_7DEC */

/* fzgx:begin fn_4_80EC */
void fn_4_80EC(void) {
    fn_1_435C(lbl_4_bss_8);
    lbl_4_bss_0 = fn_1_3F8C((u32)"option_card_menu_disp", (u32)fn_4_7DEC, 0, 5);
    lbl_4_bss_10 = 0;
    fn_1_4A00(1, 15, lbl_4_bss_8);
}
/* fzgx:end fn_4_80EC */

/* fzgx:begin fn_4_8158 */
void fn_4_8158(void) {
    u32 v0;
    u32 t0, t2, t5;

    if (lbl_4_bss_10 != 0) {
        t0 = fn_1_4C10();
        if ((s32)t0 == 0) {
            fn_1_1280(1);
            lbl_1_bss_96A = lbl_4_bss_10;
            lbl_4_bss_10 = 0;
        }
    } else {
        t2 = fn_4_0(lbl_4_bss_D, 0, 1, -1, 0);
        lbl_4_bss_D = t2;
        v0 = lbl_1_bss_9F8[0].trig;
        if (((v0 >> 9) & 1) != 0) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_10 = 75;
        } else if (((v0 >> 8) & 1) != 0) {
            fn_1_A2D84(0xA9010100);
            lbl_4_bss_10 = lbl_4_data_2D24[lbl_4_bss_D].id;
        } else {
            return;
        }
        fn_1_4A00(0, 15, lbl_4_bss_8);
    }
}
/* fzgx:end fn_4_8158 */

/* fzgx:begin fn_4_8248 */
/* Finalize the pending option state and clear its completion flag. */

void fn_4_8248(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_8248 */

/* fzgx:begin fn_4_82A0 */
u8 lbl_4_data_2D72 = 0xFFU;

s16 lbl_4_data_2D74 = -1;

void fn_4_82A0(void) {
    char *guide;
    u32 flags;
    f32 width;
    f32 span;
    f32 left;
    f32 right;
    f32 height;

    fn_1_49410();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(5.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    option_draw_title(110.0f, 1.0f, lbl_4_data_9F8[lbl_801A66B4]);
    guide = lbl_4_data_E8[lbl_801A66B4];
    if (lbl_4_bss_280 != 0) {
        fn_4_2D4(lbl_4_bss_281, lbl_4_data_884[lbl_801A66B4]);
        flags = 0x48000000;
    } else {
        fn_1_49410();
        fn_1_495C8(9);
        fn_1_4954C(0.05f);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(5.0f);
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(0.5f);
        }
        fn_1_496FC(320.0f, 216.0f);
        fn_1_4AE0C(lbl_4_data_1210, lbl_4_data_A58[lbl_801A66B4]);
        width = fn_1_4B040(lbl_4_data_A58[lbl_801A66B4]);
        left = fn_1_4B040(lbl_4_data_A88[lbl_801A66B4]);
        right = fn_1_4B040(lbl_4_data_ABC[lbl_801A66B4]);
        if (left > right) {
            right = left;
        }
        span = 90.0 + right;
        fn_1_496FC(320.0 - 0.5 * span, 264.0f);
        fn_1_4AE0C(lbl_4_data_1210, lbl_4_data_A88[lbl_801A66B4]);
        fn_1_496FC(320.0 + 0.5 * span, 264.0f);
        fn_1_4AE0C(lbl_4_data_1210, lbl_4_data_ABC[lbl_801A66B4]);
        if (span + right > width) {
            width = span + right;
        }
        if (lbl_4_data_2D72 != lbl_4_bss_282 || lbl_4_data_2D74 != lbl_1_bss_962) {
            lbl_4_bss_2 = 0;
            lbl_4_data_2D72 = lbl_4_bss_282;
            lbl_4_data_2D74 = lbl_1_bss_962;
        }
        option_draw_cursor(320.0 + (f64)(span * (lbl_4_bss_282 == 0 ? -0.5 : 0.5)), 264.0f, 0.060000002f, right, 0.0f, 1.0f);
        height = 72.0f;
        fn_1_53BD8(0, 320.0f, 240.0f, 96.0 + width, 48.0 + height, 0.07f);
        flags = 0x28000000;
    }
    fn_1_1380F0(guide);
    fn_1_13ABA8(flags);
}
/* fzgx:end fn_4_82A0 */

/* fzgx:begin fn_4_869C */
void fn_4_869C(void) {
    u32 t1;
    lbl_4_bss_283 = lbl_1_bss_718E0.unk_3;
    lbl_4_bss_282 = lbl_1_bss_718E0.unk_3;
    fn_1_435C(lbl_4_bss_8);
    t1 = fn_1_3F8C((u32)"option_wide_disp", (u32)fn_4_82A0, 0, 5);
    lbl_4_bss_0 = t1;
    lbl_4_bss_280 = 0;
    lbl_4_bss_10 = 0;
    fn_1_4A00(1, 15, lbl_4_bss_8);
}
/* fzgx:end fn_4_869C */

/* fzgx:begin fn_4_8720 */
void fn_4_8720(void) {
    if (lbl_4_bss_10 != 0) {
        if (fn_1_4C10() == 0) {
            fn_1_1280(1);
            lbl_1_bss_96A = lbl_4_bss_10;
            lbl_4_bss_10 = 0;
        }
    } else if (lbl_4_bss_280 != 0) {
        lbl_4_bss_281 = fn_4_0(lbl_4_bss_281, 0, 1, -1, 1);
        if ((lbl_1_bss_9F8[0].trig >> 9) & 1) {
            fn_1_A2D84(0xA9010200);
            lbl_4_bss_280 = 0;
        } else if ((lbl_1_bss_9F8[0].trig >> 8) & 1) {
            fn_1_A2D84(0xA9010100);
            if (lbl_4_bss_281 == 0) {
                lbl_1_bss_718E0.unk_3 = lbl_4_bss_283;
                lbl_4_bss_E = 1;
            } else if (lbl_1_bss_718E0.unk_3 != lbl_4_bss_283) {
                fn_1_A6840(lbl_1_bss_718E0.unk_3);
            }
            if (lbl_4_bss_E != 0) {
                lbl_4_bss_B8 = 0x4B;
                lbl_4_bss_10 = 0x4C;
            } else {
                lbl_4_bss_10 = 0x4B;
                fn_1_4A00(0, 0xF, lbl_4_bss_8);
            }
        }
    } else {
        if ((PAD_BIT(lbl_1_bss_9F8[0].rep, 0) || (lbl_1_bss_9F8[0].unk_12 & 1)) && lbl_4_bss_282 == 1) {
            lbl_4_bss_282 = 0;
            fn_1_A2D84(0xA9010000);
        } else if ((PAD_BIT(lbl_1_bss_9F8[0].rep, 1) || ((lbl_1_bss_9F8[0].unk_12 >> 1) & 1)) && lbl_4_bss_282 == 0) {
            lbl_4_bss_282 = 1;
            fn_1_A2D84(0xA9010000);
        }
        if (((lbl_1_bss_9F8[0].trig >> 8) & 1) && lbl_4_bss_282 != lbl_4_bss_283) {
            fn_1_A2D84(0xA9010100);
            fn_1_A6840(lbl_4_bss_282);
            lbl_4_bss_283 = lbl_4_bss_282;
        }
        if ((lbl_1_bss_9F8[0].trig >> 9) & 1) {
            fn_1_A2D84(0xA9010200);
            if (lbl_4_bss_283 != lbl_1_bss_718E0.unk_3) {
                lbl_4_bss_280 = 1;
                lbl_4_bss_281 = 0;
            } else {
                lbl_4_bss_10 = 0x4B;
                fn_1_4A00(0, 0xF, lbl_4_bss_8);
            }
        }
    }
}
/* fzgx:end fn_4_8720 */

/* fzgx:begin fn_4_898C */
/* Reset the option state after releasing its active resource. */

void fn_4_898C(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_898C */

/* fzgx:begin fn_4_89E4 */
void fn_4_89E4(void) {
    u32 t2;
    fn_4_AB30();
    lbl_4_bss_10 = 0;
    fn_1_435C(lbl_4_bss_8);
    t2 = fn_1_3F8C((u32)"OptionGhostDisp", (u32)fn_4_AC58, 0, 5);
    lbl_4_bss_0 = t2;
    fn_1_4A00(1, 15, lbl_4_bss_8);
}
/* fzgx:end fn_4_89E4 */

/* fzgx:begin fn_4_8A54 */
/* Advance the option resource state and clear a completed selection. */

void fn_4_8A54(void) {
    u16 value;

    if (lbl_4_bss_10 != 0) {
        if (fn_1_4C10() == 0) {
            fn_1_1280(1);
            value = lbl_4_bss_10;
            lbl_1_bss_96A = value;
            lbl_4_bss_10 = 0;
        }
    } else {
        value = fn_4_ABB0();
        lbl_4_bss_10 = value;
        if (value != 0) {
            fn_1_4A00(0, 15, lbl_4_bss_8);
        }
    }
}
/* fzgx:end fn_4_8A54 */

/* fzgx:begin fn_4_8AE0 */
// Completes the pending option callback and clears its handle.

void fn_4_8AE0(void) {
    fn_4_AB90();

    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_8AE0 */

/* fzgx:begin fn_4_8B3C */
/* Draws the heading of a memory-card prompt. */
static void option_draw_card_heading(char *text, f32 y) {
    f32 scale;

    fn_1_4AEC0(1);
    fn_1_4AEB4(1.5f);
    fn_1_49410();
    scale = 0.75f;
    fn_1_4955C(scale, scale);
    fn_1_4954C(0.009999998f);
    fn_1_495C8(9);
    fn_1_496FC(320.0f, y);
    fn_1_4966C(-1.0f, 8.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
    }
    fn_1_4A0D8(text);
    fn_1_4AEC0(0);
    fn_1_4AEB4(0.0f);
}

/* Draws the yes / no choice of a memory-card prompt. *no selects "no". */
static void option_draw_yes_no(u8 *no) {
    static const GXColor from = {0xA0, 0x50, 0x50, 0x00};
    static const GXColor to = {0xA0, 0xA0, 0xA0, 0x00};
    GXColor color;

    color = fn_800081C8(from, to, 1.0f);
    fn_1_49410();
    fn_1_4955C(0.75f, 0.75f);
    fn_1_4954C(0.009999998f);
    fn_1_495C8(9);
    fn_1_496FC(288.0f, 320.0f);
    fn_1_495C8(10);
    if (*no == 0) {
        static const GXColor white = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_4D494();
        fn_1_49514(white);
        fn_1_4AE0C(lbl_4_data_1210, lbl_4_data_584[lbl_801A66B4]);
        fn_1_4D4C8(color, 0.009999998f, 10.0f);
    } else {
        static const GXColor grey = {0x70, 0x70, 0x70, 0x00};
        static const GXColor black = {0x00, 0x00, 0x00, 0x00};
        fn_1_49514(grey);
        fn_1_49528(black);
        fn_1_4AE0C(lbl_4_data_1210, lbl_4_data_584[lbl_801A66B4]);
    }
    fn_1_496FC(352.0f, 320.0f);
    fn_1_495C8(8);
    if (*no == 0) {
        static const GXColor grey = {0x70, 0x70, 0x70, 0x00};
        static const GXColor black = {0x00, 0x00, 0x00, 0x00};
        fn_1_49514(grey);
        fn_1_49528(black);
        fn_1_4AE0C(lbl_4_data_1210, lbl_4_data_5A8[lbl_801A66B4]);
    } else {
        static const GXColor white = {0xFF, 0xFF, 0xFF, 0x00};
        fn_1_4D494();
        fn_1_49514(white);
        fn_1_4AE0C(lbl_4_data_1210, lbl_4_data_5A8[lbl_801A66B4]);
        fn_1_4D4C8(color, 0.009999998f, 10.0f);
    }
}

/* Restarts the cursor blink when the card-screen selection changes. */
static void option_card_select(u8 *index) {
    if (lbl_4_bss_284 != *index) {
        lbl_4_bss_284 = *index;
        lbl_4_bss_2 = 0;
    }
}

/* Draws the controller-setup option screen: title, instructions, the selection cursor. */

void fn_4_8B3C(void) {
    GXColor color = {0xFF, 0xFF, 0xFF, 0xFF};
    char *message = lbl_4_data_1A4[lbl_801A66B4];
    u32 flags = 0;

    if (lbl_4_bss_10 == 0 && fn_1_B7C00() == 0) {
        if (lbl_4_bss_285 == 3) {
            return;
        }
        if (lbl_4_bss_285 != 4) {
            fn_1_49410();
            fn_1_495C8(9);
            fn_1_49738(fn_1_5233C);
            fn_1_49748(5.0f);
            if (lbl_801A66B4 != 5) {
                fn_1_495B0(0x80000000);
                fn_1_49590(0.5f);
            }
            fn_1_4D0A0();
            fn_1_496FC(320.0f, 110.0f);
            fn_1_4A0D8(lbl_4_data_E30[lbl_801A66B4]);
            {
                GXColor shadow = {0xFF, 0xFF, 0xFF, 0xFF};
                fn_1_4D274(&shadow, 40.0f);
            }
            if (lbl_4_bss_285 == 0) {
                fn_1_496FC(320.0f, 220.0f);
                fn_1_4A0D8(lbl_4_data_E70[lbl_801A66B4]);
                fn_1_496FC(320.0f, 260.0f);
                fn_1_4A0D8(lbl_4_data_EB0[lbl_801A66B4]);
                fn_1_53BD8(&color, 320.0f, 240.0f, 350.0f, 100.0f, 0.1f);
                option_card_select(&lbl_4_bss_286);
                option_draw_cursor(320.0f, lbl_4_bss_286 * 40 + 220, 0.09f, 254.0f, 0.0f, 1.0f);
                message = lbl_4_data_E8[lbl_801A66B4];
                flags = 0x28000000;
            }
        }
    }
    fn_1_1380F0(message);
    fn_1_13ABA8(flags);
}
/* fzgx:end fn_4_8B3C */

/* fzgx:begin fn_4_8DC0 */
void fn_4_8DC0(void) {
    u32 t1;
    lbl_4_bss_286 = 0;
    lbl_4_bss_285 = 0;
    fn_1_435C(lbl_4_bss_8);
    t1 = fn_1_3F8C((u32)"option_card_gdata_disp", (u32)fn_4_8B3C, 0, 5);
    lbl_4_bss_0 = t1;
    lbl_4_bss_10 = 0;
    fn_1_4A00(1, 15, lbl_4_bss_8);
}
/* fzgx:end fn_4_8DC0 */

/* fzgx:begin fn_4_8E38 */
/* Reads the yes / no choice of a memory-card prompt from the first pad. */
static void option_card_yes_no_input(u8 *no) {
    if ((lbl_1_bss_9F8[0].rep & 1) || (lbl_1_bss_9F8[0].unk_12 & 1)) {
        *no = 0;
        fn_1_A2D84(0xA9011300);
    }
    if (((lbl_1_bss_9F8[0].rep >> 1) & 1) || ((lbl_1_bss_9F8[0].unk_12 >> 1) & 1)) {
        *no = 1;
        fn_1_A2D84(0xA9011300);
    }
    if ((lbl_1_bss_9F8[0].trig >> 9) & 1) {
        *no = 1;
        fn_1_A2D84(0xA9011300);
    }
}

/* Runs the controller-setup save screen: checks the memory card and saves the option data. */
void fn_4_8E38(void) {
    struct fn_4_9C14_Request request;
    char comment[0x20];
    Sig_fn_1_B7F58_Result card;

    if (fn_1_B7C00() != 0) {
        return;
    }
    if (lbl_4_bss_10 != 0) {
        if (fn_1_4C10() == 0) {
            fn_1_1280(1);
            lbl_1_bss_96A = lbl_4_bss_10;
            lbl_4_bss_10 = 0;
        }
        return;
    }
    switch (lbl_4_bss_285) {
    case 0:
        lbl_4_bss_286 = fn_4_0(lbl_4_bss_286, 0, 1, -1, 0);
        if ((lbl_1_bss_9F8[0].trig >> 8) & 1) {
            fn_1_A2D84(0xA9010100);
            lbl_4_bss_285 = 1;
        } else {
            if ((lbl_1_bss_9F8[0].trig >> 9) & 1) {
                fn_1_A2D84(0xA9010200);
                lbl_4_bss_285 = 0x63;
            }
            break;
        }
    case 1:
        if (fn_1_B7E98(0) == 0) {
            lbl_4_bss_288 = 0x3C;
            lbl_4_bss_285 = 0x62;
            break;
        }
        if (lbl_4_bss_286 == 0) {
            fn_80008BEC(&request, 0, 0x24);
            request.unk_0 = 1;
            request.unk_4 = 0;
            request.unk_C = &lbl_1_bss_718E0;
            fn_1_AA6D8(2, 0, &request);
            lbl_4_bss_285 = 2;
        } else if (lbl_4_bss_286 == 1) {
            if ((lbl_4_bss_28C = fn_1_B800C(0)) != 0) {
                lbl_4_bss_290 = 1;
                lbl_4_bss_288 = 0x3C;
                lbl_4_bss_285 = 0x61;
            } else if (fn_1_B8170(0) & 2) {
                lbl_4_bss_290 = 0;
                lbl_4_bss_285 = 4;
            } else {
                lbl_4_bss_290 = 1;
                lbl_4_bss_288 = 0x3C;
                lbl_4_bss_285 = 0x61;
            }
            fn_1_B80F0(0);
        }
        break;
    case 2:
        if (fn_1_B7C5C() == 0) {
            fn_1_C34F0();
            lbl_4_bss_285 = 0x63;
        } else {
            lbl_4_bss_285 = 0;
        }
        break;
    case 3:
        if (fn_1_B7E98(0) == 0) {
            fn_4_D760();
            lbl_4_bss_288 = 0x78;
            lbl_4_bss_285 = 0x62;
            break;
        }
        if (fn_4_D420() != 0) {
            option_card_yes_no_input(&lbl_4_bss_291);
            if (((lbl_1_bss_9F8[0].trig >> 8) & 1) || ((lbl_1_bss_9F8[0].trig >> 9) & 1)) {
                if (lbl_4_bss_291 == 0) {
                    fn_1_A2D84(0xA9011100);
                    fn_4_D848(lbl_4_bss_294);
                    fn_4_D760();
                    lbl_4_bss_285 = 4;
                } else {
                    fn_4_D878();
                }
            }
            fn_1_4FD64();
            fn_1_4D0A0();
            option_draw_card_heading(lbl_4_data_1154[lbl_801A66B4], 220.0f);
            option_draw_yes_no(&lbl_4_bss_291);
            {
                GXColor white = {0xFF, 0xFF, 0xFF, 0xFF};
                fn_1_4D2AC(&white, 0.020000003f, 40.0f);
            }
        }
        break;
    case 4:
        *(struct fn_4_9C14_Save *)lbl_4_bss_2B8 = *(struct fn_4_9C14_Save *)lbl_1_bss_7F0C0;
        fn_1_F7954();
        fn_80008BEC(&request, 0, 0x24);
        fn_80008BEC(comment, 0, 0x20);
        request.unk_0 = 1;
        request.unk_8 = comment;
        request.unk_C = &lbl_1_bss_718E0;
        if (lbl_4_bss_290 != 0) {
            if (fn_1_B7F58(&card) != 0) {
                fn_1_F7A20();
                fn_1_F7954();
            }
            fn_4_A78C(lbl_4_bss_294);
            fn_1_B7CE4(1, comment);
            comment[8] = ' ';
            comment[9] = 0;
            strcat(comment, (char *)lbl_4_bss_294);
            strcpy(lbl_1_bss_718E0.unk_5522, (char *)lbl_4_bss_294);
            fn_1_B7E14(comment);
            *lbl_1_bss_718C0 = fn_1_C3688();
            request.unk_4 = 0x10000;
        } else {
            fn_1_B7CE4(1, comment);
            request.unk_4 = 0;
        }
        fn_1_AA6D8(0, 0, &request);
        lbl_4_bss_285 = 5;
        break;
    case 5:
        if (fn_1_B7C5C() == 0) {
            fn_1_C34F0();
            lbl_4_bss_285 = 0x63;
        } else {
            lbl_4_bss_285 = 0;
            *(struct fn_4_9C14_Save *)lbl_1_bss_7F0C0 = *(struct fn_4_9C14_Save *)lbl_4_bss_2B8;
        }
        break;
    case 0x5F:
        fn_4_D1A8(lbl_4_bss_4, lbl_4_bss_8, lbl_1_bss_8B3A0[0x9E]);
        lbl_4_bss_285 = 3;
        break;
    case 0x60:
        fn_1_B9904(0, 0, 1, lbl_4_bss_28C);
        if (lbl_4_bss_288-- < 0) {
            lbl_4_bss_285 = 0;
        }
        break;
    case 0x61:
        fn_1_49410();
        if (lbl_4_bss_290 != 0 && fn_1_B7F58(&card) != 0) {
            option_card_yes_no_input(&lbl_4_bss_291);
            if (((lbl_1_bss_9F8[0].trig >> 8) & 1) || ((lbl_1_bss_9F8[0].trig >> 9) & 1)) {
                if (lbl_4_bss_291 == 0) {
                    fn_1_A2D84(0xA9011100);
                    lbl_4_bss_291 = 1;
                    lbl_4_bss_285 = 0x5F;
                } else {
                    lbl_4_bss_285 = 0;
                }
            }
            fn_1_4D0A0();
            option_draw_card_heading(lbl_4_data_1064[lbl_801A66B4], 220.0f);
            option_draw_yes_no(&lbl_4_bss_291);
            {
                GXColor white = {0xFF, 0xFF, 0xFF, 0xFF};
                fn_1_4D2AC(&white, 0.020000003f, 40.0f);
            }
            break;
        }
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(0.5f);
        }
        fn_1_53E40(NULL, 320.0f, 240.0f, 0.1f, 40.0f, 0.9f, lbl_4_data_F4C[lbl_801A66B4]);
        if (lbl_4_bss_288-- < 0) {
            lbl_4_bss_291 = 1;
            lbl_4_bss_285 = 0x5F;
        }
        break;
    case 0x62:
        fn_1_49410();
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(0.5f);
        }
        fn_1_53E40(NULL, 320.0f, 240.0f, 0.1f, 40.0f, 0.9f, lbl_4_data_10D0[lbl_801A66B4]);
        if (lbl_4_bss_288-- < 0) {
            lbl_4_bss_285 = 0;
        }
        break;
    }
    if (lbl_4_bss_285 == 0x63) {
        lbl_4_bss_10 = 0x4E;
        fn_1_4A00(0, 15, lbl_4_bss_8);
    }
}
/* fzgx:end fn_4_8E38 */

/* fzgx:begin fn_4_9A78 */
// Finalizes the pending option callback and clears its handle.

void fn_4_9A78(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_9A78 */

/* fzgx:begin fn_4_9AD0 */
/* Shows the "saving" message while the option data is written to the memory card. */
void fn_4_9AD0(void) {
    if (lbl_4_bss_5618 != 0) {
        fn_1_1380F0(lbl_4_data_1A4[lbl_801A66B4]);
        fn_1_13ABA8(0);
    }
}
/* fzgx:end fn_4_9AD0 */

/* fzgx:begin fn_4_9B20 */
/* Opens the save screen and checks whether the memory card can take the option data. */
void fn_4_9B20(void) {
    fn_1_435C(lbl_4_bss_8);
    lbl_4_bss_0 = fn_1_3F8C((u32)"option_save_wait_disp", (u32)fn_4_9AD0, 0, 5);
    lbl_4_bss_5618 = 1;
    lbl_4_bss_5619 = 0;
    lbl_4_bss_561A = 0;
    lbl_4_bss_561B = 0;
    lbl_4_bss_294[0] = 0;
    lbl_4_bss_561C = 0;
    if (fn_1_B7E98(0) != 0) {
        if (fn_1_B800C(0) == 0 && (fn_1_B8170(0) & 2) == 0) {
            lbl_4_bss_561B = 1;
            lbl_4_bss_561C = 120;
            lbl_4_bss_5619 = 1;
            lbl_4_bss_291 = 1;
            lbl_4_bss_561A = 1;
        }
        fn_1_B80F0(0);
        lbl_4_bss_5620 = 1;
        lbl_4_bss_5621 = 1;
        lbl_4_bss_5622 = 0;
    } else {
        lbl_4_bss_5620 = 0;
        lbl_4_bss_5621 = 0;
        lbl_4_bss_5622 = 120;
    }
}
/* fzgx:end fn_4_9B20 */

/* fzgx:begin fn_4_9C14 */
/* Runs the save-wait screen: asks to overwrite or create the save file, then writes the option data. */
void fn_4_9C14(void) {
    struct fn_4_9C14_Request request;
    char comment[0x20];
    Sig_fn_1_B7F58_Result card;

    lbl_4_bss_5618 = 1;
    if (lbl_4_bss_5622 != 0) {
        fn_1_4D0A0();
        option_draw_card_heading(lbl_4_data_11F4[lbl_801A66B4], 220.0f);
        {
            GXColor white = {0xFF, 0xFF, 0xFF, 0xFF};
            fn_1_4D2AC(&white, 0.020000003f, 40.0f);
        }
        lbl_4_bss_5622--;
        return;
    }
    if (lbl_4_bss_10 != 0) {
        if (fn_1_4C10() == 0) {
            fn_1_1280(1);
            lbl_1_bss_96A = lbl_4_bss_10;
            lbl_4_bss_10 = 0;
        }
        return;
    }
    if (lbl_4_bss_561B != 0) {
        if (fn_1_B7F58(&card) != 0) {
            if (lbl_4_bss_561A != 0) {
                option_card_yes_no_input(&lbl_4_bss_291);
                if (((lbl_1_bss_9F8[0].trig >> 8) & 1) || ((lbl_1_bss_9F8[0].trig >> 9) & 1)) {
                    if (lbl_4_bss_291 == 0) {
                        fn_1_A2D84(0xA9011100);
                    } else {
                        lbl_4_bss_561B = 0;
                        lbl_4_bss_5620 = 0;
                        lbl_4_bss_294[0] = 0;
                        lbl_4_bss_5619 = 0;
                    }
                    lbl_4_bss_561A = 0;
                }
                fn_1_4D0A0();
                option_draw_card_heading(lbl_4_data_1064[lbl_801A66B4], 220.0f);
                option_draw_yes_no(&lbl_4_bss_291);
                {
                    GXColor white = {0xFF, 0xFF, 0xFF, 0xFF};
                    fn_1_4D2AC(&white, 0.020000003f, 40.0f);
                }
                return;
            }
        } else if (lbl_4_bss_561C != 0) {
            fn_1_4D0A0();
            option_draw_card_heading(lbl_4_data_F4C[lbl_801A66B4], 220.0f);
            {
                GXColor white = {0xFF, 0xFF, 0xFF, 0xFF};
                fn_1_4D2AC(&white, 0.020000003f, 40.0f);
            }
            lbl_4_bss_561C--;
            return;
        }
    }
    if (lbl_4_bss_5619 != 0) {
        lbl_4_bss_5619 = 0;
        fn_4_D1A8(lbl_4_bss_4, lbl_4_bss_8, lbl_1_bss_8B3A0[0x9E]);
    }
    if (lbl_4_bss_561B != 0) {
        if (fn_1_B7E98(0) == 0) {
            fn_4_D760();
            lbl_4_bss_E = 0;
            lbl_4_bss_10 = lbl_4_bss_B8;
            lbl_4_bss_294[0] = 0;
            lbl_4_bss_5620 = 0;
            fn_1_4A00(0, 15, lbl_4_bss_8);
            return;
        }
        if (fn_4_D420() != 0) {
            option_card_yes_no_input(&lbl_4_bss_291);
            if (((lbl_1_bss_9F8[0].trig >> 8) & 1) || ((lbl_1_bss_9F8[0].trig >> 9) & 1)) {
                if (lbl_4_bss_291 == 0) {
                    fn_1_A2D84(0xA9011100);
                    fn_4_D848(lbl_4_bss_294);
                    fn_4_D760();
                    lbl_4_bss_561B = 0;
                } else {
                    fn_4_D878();
                }
            }
            fn_1_4FD64();
            fn_1_4D0A0();
            option_draw_card_heading(lbl_4_data_1154[lbl_801A66B4], 220.0f);
            option_draw_yes_no(&lbl_4_bss_291);
            {
                GXColor white = {0xFF, 0xFF, 0xFF, 0xFF};
                fn_1_4D2AC(&white, 0.020000003f, 40.0f);
            }
        }
        lbl_4_bss_5618 = 0;
        return;
    }
    if (lbl_4_bss_5620 != 0) {
        *(struct fn_4_9C14_Save *)lbl_4_bss_2B8 = *(struct fn_4_9C14_Save *)lbl_1_bss_7F0C0;
        fn_1_F7954();
        fn_80008BEC(&request, 0, 0x24);
        fn_80008BEC(comment, 0, 0x20);
        request.unk_0 = 1;
        request.unk_8 = comment;
        request.unk_C = &lbl_1_bss_718E0;
        if (lbl_4_bss_294[0] != 0) {
            if (fn_1_B7F58(&card) != 0) {
                fn_1_F7A20();
                fn_1_F7954();
            }
            fn_4_A78C(lbl_4_bss_294);
            fn_1_B7CE4(1, comment);
            comment[8] = ' ';
            comment[9] = 0;
            strcat(comment, (char *)lbl_4_bss_294);
            strcpy(lbl_1_bss_718E0.unk_5522, (char *)lbl_4_bss_294);
            fn_1_B7E14(comment);
            *lbl_1_bss_718C0 = fn_1_C3688();
            request.unk_4 = 0x10000;
        } else {
            fn_1_B7CE4(1, comment);
            request.unk_4 = 4;
        }
        fn_1_AA6D8(0, 0, &request);
        lbl_4_bss_5620 = 0;
        lbl_4_bss_10 = 0;
        return;
    }
    if (fn_1_B7C00() == 0) {
        if (lbl_4_bss_5621 != 0 && fn_1_B7CD4() == 0) {
            *(struct fn_4_9C14_Save *)lbl_1_bss_7F0C0 = *(struct fn_4_9C14_Save *)lbl_4_bss_2B8;
        }
        lbl_4_bss_E = 0;
        lbl_4_bss_10 = lbl_4_bss_B8;
        fn_1_4A00(0, 15, lbl_4_bss_8);
    }
}
/* fzgx:end fn_4_9C14 */

/* fzgx:begin fn_4_A734 */
// Finalizes the pending option callback and clears its handle.

void fn_4_A734(void) {
    if (lbl_4_bss_0 != 0) {
        fn_1_435C(lbl_4_bss_8);
        fn_1_426C(lbl_4_bss_0);
        lbl_4_bss_0 = 0;
    }
}
/* fzgx:end fn_4_A734 */

/* fzgx:begin fn_4_A78C */
void fn_4_A78C(u8 *arg0) {
    u8 loc_8[32];
    u8 *p;
    u8 *out;

    if (lbl_801A66B4 != 5) {
        strcpy((char *)loc_8, (char *)arg0);
        p = loc_8;
        out = arg0;
        while (*p != 0) {
            if (*p < 0x80) {
                *out = *p;
                p++;
                out++;
            } else {
                u8 *q = fn_4_A82C(p);
                if (q != 0) {
                    *out = *q;
                    out++;
                }
                p += 2;
            }
        }
        *out = 0;
    }
}
/* fzgx:end fn_4_A78C */

/* fzgx:begin fn_4_A82C */
/* Maps a two-byte (SJIS) character to its one-byte equivalent. */
u8 *fn_4_A82C(u8 *s) {
    static u8 wide_upper[] = "\x82\x60\x82\x61\x82\x62\x82\x63\x82\x64\x82\x65\x82\x66\x82\x67\x82\x68\x82\x69\x82\x6A\x82\x6B\x82\x6C\x82\x6D\x82\x6E\x82\x6F\x82\x70\x82\x71\x82\x72\x82\x73\x82\x74\x82\x75\x82\x76\x82\x77\x82\x78\x82\x79";
    static u8 wide_lower[] = "\x82\x81\x82\x82\x82\x83\x82\x84\x82\x85\x82\x86\x82\x87\x82\x88\x82\x89\x82\x8A\x82\x8B\x82\x8C\x82\x8D\x82\x8E\x82\x8F\x82\x90\x82\x91\x82\x92\x82\x93\x82\x94\x82\x95\x82\x96\x82\x97\x82\x98\x82\x99\x82\x9A";
    static u8 wide_symbol[] = "\x81\x43\x81\x44\x81\x48\x81\x49\x81\x7B\x81\x7C\x81\x5E\x81\x5F\x81\x81\x81\x83\x81\x84\x81\x46\x81\x47\x81\x4C\x81\x4D\x81\x4F\x81\x51\x81\x62\x81\x69\x81\x6A\x81\x6D\x81\x6E\x81\x6F\x81\x70\x81\x90\x81\x93\x81\x94\x81\x95\x81\x96\x81\x97\x81\x40";
    static u8 wide_digit[] = "\x82\x4F\x82\x50\x82\x51\x82\x52\x82\x53\x82\x54\x82\x55\x82\x56\x82\x57\x82\x58";
    static u8 narrow_upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static u8 narrow_lower[] = "abcdefghijklmnopqrstuvwxyz";
    static u8 narrow_symbol[] = ",.?!+-/\\=<>:;'`^_|()[]{}$%#&*@  ";
    static u8 narrow_digit[] = "0123456789";
    s32 i;

    for (i = 0; i < 54; i += 2) {
        if (s[0] == wide_upper[i] && s[1] == wide_upper[i + 1]) {
            return &narrow_upper[i / 2];
        }
    }
    for (i = 0; i < 54; i += 2) {
        if (s[0] == wide_lower[i] && s[1] == wide_lower[i + 1]) {
            return &narrow_lower[i / 2];
        }
    }
    for (i = 0; i < 64; i += 2) {
        if (s[0] == wide_symbol[i] && s[1] == wide_symbol[i + 1]) {
            return &narrow_symbol[i / 2];
        }
    }
    for (i = 0; i < 22; i += 2) {
        if (s[0] == wide_digit[i] && s[1] == wide_digit[i + 1]) {
            return &narrow_digit[i / 2];
        }
    }
    return 0;
}
/* fzgx:end fn_4_A82C */

/* fzgx:begin fn_4_AB30 noprologue */
#include "types.h"

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[0x1D];
    u8 unk_22;
    u8 pad_23[0x25];
} Obj_4_bss_5630;

extern void fn_1_B9BE0(void);
extern void fn_1_B9DE8(u32);
extern u32 fn_1_B9C0C(void);
extern u32 fn_1_1380F0(char *);
extern u32 fn_1_13ABA8(u32);
extern u32 fn_1_B7C00(void);
extern s8 fn_1_BA144(u32 *);
extern u32 fn_1_BC310(void *);
extern u32 fn_1_C0510(u32);
extern u32 fn_1_C1394(void *);
extern s32 lbl_801A66B4;

void fn_4_ACF0(void);
void fn_4_AD78(void);
void fn_4_ADB0(void);
void fn_4_AD44(void);
void fn_4_ADAC(void);
void fn_4_ADF0(void);

/* per state: the update handlers (fn_4_ABB0) and the draw handlers (fn_4_AC58) */
void (*lbl_4_data_2F00[3])(void) = {fn_4_ACF0, fn_4_AD78, fn_4_ADB0};
void (*lbl_4_data_2F0C[3])(void) = {fn_4_AD44, fn_4_ADAC, fn_4_ADF0};
s32 lbl_4_data_2F18 = -1;  /* current state */
s32 lbl_4_data_2F1C = -1;  /* next state */
char *lbl_4_data_2F60[6] = {
    "Use \x83\xad or \x83\xb5 to choose. ", "", "", "", "",
    "\x83\xad\x82\xa9\x83\xb5\x82\xc5\x8d\x80\x96\xda\x82\xf0\x91I\x82\xf1\x82\xc5\x82\xad\x82\xbe\x82\xb3\x82\xa2\x81" "B",
};

u32 lbl_4_bss_5628 = 0;  /* frames left in the current state */
u32 lbl_4_bss_562C = 0;  /* frames of the next state */
Obj_4_bss_5630 lbl_4_bss_5630;
s32 lbl_4_bss_5678;  /* result of the frame */

// Initialize the option state and reset its associated data value.
void fn_4_AB30(void) {
    fn_1_B9BE0();
    fn_1_B9DE8((u32)&lbl_4_bss_5630);
    lbl_4_bss_5630.unk_0 = 4;
    lbl_4_bss_5630.unk_0 |= 0x10;
    lbl_4_bss_5630.unk_0 |= 0x20;
    lbl_4_bss_5630.unk_4 = 0xc;
    lbl_4_data_2F1C = 0;
}
/* fzgx:end fn_4_AB30 */

/* fzgx:begin fn_4_AB90 noprologue */
void fn_4_AB90(void) {
    fn_1_B9C0C();
}
/* fzgx:end fn_4_AB90 */

/* fzgx:begin fn_4_ABB0 noprologue */
u32 fn_4_ABB0(void) {
    lbl_4_bss_5678 = 0;
    if (lbl_4_data_2F1C >= 0 && lbl_4_bss_5628 == 0) {
        lbl_4_data_2F18 = lbl_4_data_2F1C;
        lbl_4_data_2F1C = -1;
        lbl_4_bss_5628 = lbl_4_bss_562C;
        lbl_4_bss_562C = 0;
    }
    if (lbl_4_data_2F18 >= 0) {
        if (lbl_4_bss_5628 != 0) {
            lbl_4_bss_5628--;
        }
        lbl_4_data_2F00[lbl_4_data_2F18]();
    }
    return lbl_4_bss_5678;
}
/* fzgx:end fn_4_ABB0 */

/* fzgx:begin fn_4_AC58 noprologue */
void fn_4_AC58(void) {
    fn_1_1380F0(lbl_4_data_2F60[lbl_801A66B4]);
    if ((u8)fn_1_B7C00() || (s32)lbl_4_bss_5630.unk_22 == 2) {
        fn_1_13ABA8(0);
    } else {
        fn_1_13ABA8(0x28000000);
    }
    if (lbl_4_data_2F18 >= 0) {
        lbl_4_data_2F0C[lbl_4_data_2F18]();
    }
}
/* fzgx:end fn_4_AC58 */

/* fzgx:begin fn_4_ACF0 noprologue */
void fn_4_ACF0(void) {
    u32 v0;
    u32 t0;
    t0 = fn_1_BA144((u32 *)(u32)&lbl_4_bss_5630);
    v0 = t0;
    if (t0 == 0) {
    lbl_4_data_2F1C = 1;
    } else {
    if ((s8)t0 == 1) {
    lbl_4_bss_5678 = 78;
    }
    }
}
/* fzgx:end fn_4_ACF0 */

/* fzgx:begin fn_4_AD44 noprologue */
void fn_4_AD44(void) {
    u32 t0;
    t0 = fn_1_B7C00();
    if ((t0 & 0xFF) == 0) {
    fn_1_BC310(&lbl_4_bss_5630);
    }
}
/* fzgx:end fn_4_AD44 */

/* fzgx:begin fn_4_AD78 noprologue */
void fn_4_AD78(void) {
    fn_1_C0510((u32)&lbl_4_bss_5630);
    lbl_4_data_2F1C = 2;
}
/* fzgx:end fn_4_AD78 */

/* fzgx:begin fn_4_ADAC noprologue */
// fn_4_ADAC: empty in retail (single blr).
void fn_4_ADAC(void) {
}
/* fzgx:end fn_4_ADAC */

/* fzgx:begin fn_4_ADB0 noprologue */
void fn_4_ADB0(void) {
    u32 t0;
    t0 = fn_1_B7C00();
    if ((t0 & 0xFF) == 0) {
    lbl_4_data_2F1C = 0;
    fn_1_C1394(&lbl_4_bss_5630);
    }
}
/* fzgx:end fn_4_ADB0 */

/* fzgx:begin fn_4_ADF0 noprologue */
// fn_4_ADF0: empty in retail (single blr).
void fn_4_ADF0(void) {
}
/* fzgx:end fn_4_ADF0 */
