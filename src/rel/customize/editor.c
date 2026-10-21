#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/editor.h"


extern struct Obj *fn_3_14074(void);
extern u8 lbl_3_bss_A2408[8];
extern void *fn_1_45D0(void *, u32, char *, u32);
extern void fn_80008BEC(void *, u32, u32);
extern void fn_3_17100(void);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, char *, int);
extern const f32 lbl_3_rodata_5FC[3];

/* fzgx:begin fn_3_1552C */
struct Obj {
    u8 pad[0x10];
    u16 width;
    u16 height;
};

void fn_3_1552C(void) {
    struct Obj *ptr;

    ptr = fn_3_14074();
    ptr->width = 0x20;
    ptr->height = 0x20;
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0xC) = 0x20000000;
    *(u8 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x11) = 1;
    *(u8 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x16) = 0;
    *(u8 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x0) = 0;
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x4) =
        (u32)fn_1_45D0((*(void * *)&lbl_801A6410), 0x2000, (*(char (*)[9])&lbl_3_data_35B0), 0x4A);
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x8) =
        (u32)fn_1_45D0((*(void * *)&lbl_801A6410), 0x2000, (*(char (*)[9])&lbl_3_data_35B0), 0x4B);
    fn_80008BEC(*(void **)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x4), 0, 0x2000);
    fn_80008BEC(*(void **)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x8), 0, 0x2000);
    *lbl_3_bss_A2408 = 0;
}
/* fzgx:end fn_3_1552C */

/* fzgx:begin fn_3_1560C */
void fn_3_1560C(void) {
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0xC) = (u32)1 << 31;
}
/* fzgx:end fn_3_1560C */

/* fzgx:begin fn_3_15620 */
void fn_3_15620(void) {
    *(u8 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x10) = 0;
    *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0xc) = 0x40000000;
}
/* fzgx:end fn_3_15620 */

/* fzgx:begin fn_3_1563C */
void fn_3_1563C(void) {
    fn_1_46B4(lbl_801A6410, *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x4),
              (*(char (*)[9])&lbl_3_data_35B0), 0x71);
    fn_1_46B4(lbl_801A6410, *(u32 *)((*(u8 (*)[28])&lbl_3_bss_A23EC) + 0x8),
              (*(char (*)[9])&lbl_3_data_35B0), 0x72);
}
/* fzgx:end fn_3_1563C */

/* fzgx:begin fn_3_156A8 */
void fn_3_156A8(void) {
    u8 value = ((*(u8 (*)[28])&lbl_3_bss_A23EC)[0x11] & 0x7f) << 1;
    (*(u8 (*)[28])&lbl_3_bss_A23EC)[0x11] = value;
    if (value > 6) {
        (*(u8 (*)[28])&lbl_3_bss_A23EC)[0x11] = 1;
    }
}
/* fzgx:end fn_3_156A8 */

/* fzgx:begin fn_3_1683C noprologue */
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

struct Arg0 {
    u8 pad_0[4];
    f32 unk_4;
    f32 unk_8;
};


void fn_3_1683C(struct Arg0 *arg0, s16 off, s16 size) {
    s16 x;
    s16 y;
    u8 i;
    u8 j;
    Col4 colA;
    Col4 colB;
    Obj_3_bss_A23EC *p = &lbl_3_bss_A23EC;
    x = arg0->unk_4;
    y = arg0->unk_8;
    off = 0;
    size = p->unk_11 << 3;
    colA = lbl_3_rodata_5B8;
    colB = lbl_3_rodata_5BC;
    if ((s8)fn_1_A5DC4()) {
        off = 4 / p->unk_11;
    }
    fn_1_A9868();
    for (i = 0; i < 256 / size; i++) {
        for (j = off; j < 256 / size - off; j++) {
            if (((i % 2) ^ (j % 2)) != 0) {
                Col4 t = colA;
                fn_1_A9FFC(x + size * j, y + size * i, size, size, &t);
            } else {
                Col4 t = colB;
                fn_1_A9FFC(x + size * j, y + size * i, size, size, &t);
            }
        }
    }
    fn_1_AA538();
    fn_1_4E0F4();
}
/* fzgx:end fn_3_1683C */

/* fzgx:begin fn_3_16E14 */
#include "font.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 192.0f;
    s = 105.0f;
    s = 90.0f;
    s = 32.0f;
    s = 0.0f;
    s = 184.0f;
    s = 86.0f;
    s = 100.0f;
    s = 175.0f;
    s = 88.0f;
    s = 0.5f;
    s = 10.0f;
    s = 420.0f;
    s = 334.0f;
    s = 29.0f;
    s = 320.0f;
    s = 232.0f;
    s = 50.0f;
    s = 4.0f;
    s = 480.0f;
    s = 92.0f;
    s = 1.0f;
    s = 1.0714285373687744f;
    s = 64.0f;
    s = 65535.0f;
    s = 119.0f;
    s = 30.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[1] = {0x00000064};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0920546628767624e-05f;
    s = -0.25f;
    s = -0.6000000238418579f;
    s = -0.949999988079071f;
    s = 0.25f;
    s = 0.6000000238418579f;
    s = 0.949999988079071f;
}
static const u32 fzgx_pool_table5[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 28.0f;
    s = 0.05999999865889549f;
    s = 10.680000305175781f;
    s = 0.03999999910593033f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern s32 lbl_1_rodata_26F8;
extern int fn_1_4F734(FontDrawPacket *);

typedef struct {
	s32 unk_0;
	f32 unk_4;
	f32 unk_8;
	f32 unk_C;
	f32 unk_10;
	f32 unk_14;
	u8 pad_18[0x18];
	u32 unk_30;
	u8 pad_34[0x8];
	u32 unk_3C;
	u8 pad_40[0x18];
} DrawPacket;

#pragma opt_dead_assignments off
#pragma opt_propagation on
#pragma opt_common_subs off
#pragma opt_lifetimes on
#pragma opt_loop_invariants off
void fn_3_16E14(void) {
	u32 fzgx_value;
	s32 width;
	s32 hi;
	DrawPacket pkt;
	s32 lo;
	s32 count;
	u32 i;
	u32 n;
	u8 c;

	count = (0x100 / (u16)(0x40 / lbl_3_bss_A23EC.unk_11) - 1) & 0xFF;
	width = (u16)(0x40 / lbl_3_bss_A23EC.unk_11);
	pkt = *(DrawPacket *)&lbl_1_rodata_26F8;
	pkt.unk_0 = 0xC;
	fzgx_value = 5;
	pkt.unk_30 = fzgx_value;
	lo = (count >> 1) & 0x7F;
	hi = lo + 5;
	pkt.unk_C = 28.0f;
	pkt.unk_3C = fzgx_pool_table5[0];
	{
    s32 fzgx_loop_i_3181;
for (fzgx_loop_i_3181 = 0; (u8)fzgx_loop_i_3181 < (u8)count; fzgx_loop_i_3181++) {
		c = (u8)fzgx_loop_i_3181;

		n = ((u8)fzgx_loop_i_3181 + 1) * width;
		pkt.unk_4 = (f32)(s32)(n + 191);
		pkt.unk_8 = 105.0f;
		pkt.unk_10 = 0.06f;
		pkt.unk_14 = 10.68f;
		fn_1_4F734((FontDrawPacket *)&pkt);
		pkt.unk_4 = 192.0f;
		pkt.unk_8 = (f32)(s32)(n + 104);
		pkt.unk_10 = 10.68f;
		if (c >= lo && c < hi) {
			pkt.unk_14 = 0.04f;
		} else {
			pkt.unk_14 = 0.06f;
		}
		fn_1_4F734((FontDrawPacket *)&pkt);
	}
    i = fzgx_loop_i_3181;
}
}
#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset

#pragma opt_common_subs reset

#pragma opt_propagation reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_3_16E14 */

/* fzgx:begin fn_3_16FD0 */
typedef struct BorderColor { u8 r, g, b, a; } BorderColor;
extern BorderColor lbl_3_rodata_5EC;
extern u32 fn_3_14794(u32, s16, s16, void *);

void fn_3_16FD0(u32 arg0) {
    BorderColor color = lbl_3_rodata_5EC;
    u32 i;
    for (i = 0; i < 64; i++) {
        BorderColor top = color;
        fn_3_14794(arg0, (s16)i, 0, &top);
        {
            BorderColor bottom = color;
            fn_3_14794(arg0, (s16)i, 63, &bottom);
        }
    }
    for (i = 0; i < 64; i++) {
        BorderColor left = color;
        fn_3_14794(arg0, 0, (s16)i, &left);
        {
            BorderColor right = color;
            fn_3_14794(arg0, 63, (s16)i, &right);
        }
    }
}
/* fzgx:end fn_3_16FD0 */

/* fzgx:begin fn_3_170E0 */
void fn_3_170E0(void) {
    fn_3_17100();
}
/* fzgx:end fn_3_170E0 */

/* fzgx:begin fn_3_17100 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/editor.h"
#include "types.h"
#include "rel/customize/editor.h"

extern struct Obj *fn_3_14074(void);
extern u8 lbl_3_bss_A2408[8];
extern void *fn_1_45D0(void *, u32, char *, u32);
extern void fn_80008BEC(void *, u32, u32);
extern void fn_3_17100(void);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, char *, int);
extern const f32 lbl_3_rodata_5FC[3];


struct fn_3_17100_lbl_1_bss_BF0_0_E32 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
};
struct fn_3_17100_lbl_3_rodata_5F0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    f32 unk_C;
    f64 unk_10;
};
struct fn_3_17100_lbl_1_bss_BF0 {
    struct fn_3_17100_lbl_1_bss_BF0_0_E32 unk_0[1];
};
struct fn_3_17100_lbl_1_bss_D58 {
    u8 pad_0[0x12];
    u16 unk_12;
};

extern f64 __fabs(f64);
extern struct fn_3_17100_lbl_1_bss_BF0 lbl_1_bss_BF0;
extern struct fn_3_17100_lbl_1_bss_D58 lbl_1_bss_D58;
extern struct fn_3_17100_lbl_3_rodata_5F0 lbl_3_rodata_5F0;
typedef struct {
    u8 pad_0[2];
    u16 unk_2;
    u8 pad_4[0xE];
    u16 unk_12;
} PadInput17100;
extern PadInput17100 lbl_1_bss_9F8[];
extern void fn_1_A2D84(u32);
extern void fn_3_177AC(void *);

void fn_3_17100(void) {
    Obj_3_bss_A2410 *p_lbl_3_bss_A2410;
    struct fn_3_17100_lbl_3_rodata_5F0 *p_lbl_3_rodata_5F0;
    Obj_3_bss_A2410 *branchMain;
    s32 v36;
    s32 v39;
    s32 v0;
    f64 v1;
    void * v2;
    s32 v3;
    s32 v4;
    s32 v5;
    s32 v6;
    u32 v7;
    f32 v8;
    u32 v9;
    u32 v10;
    f32 v11;
    u32 v12;
    f32 v13;
    s32 v14;
    s32 v15;
    void * v16;
    u8 v17;
    s32 v18;
    s32 v19;
    s32 v20;
    s32 v21;
    s32 v22;
    u32 v23;
    s32 v24;
    f32 v25;
    u8 v26;
    u8 v27;
    u16 *v28;
    u8 v29;
    u8 v30;
    u16 v31;
    s16 v32;
    s16 v33;
    s16 v34;
    u32 v35;
    u16 v37;
    u32 v38;
    s16 v40;
    u32 v41;
    union { u32 word; u8 byte[4]; }
        loc_30, loc_2C, loc_28, loc_24, loc_20, loc_1C,
        loc_18, loc_14, loc_10, loc_C, loc_8;
    p_lbl_3_rodata_5F0 = (struct fn_3_17100_lbl_3_rodata_5F0 *)&lbl_3_rodata_5F0;
    if ((lbl_3_bss_A2410.unk_8 & 0x40000000) != 0) {
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 7) & 0x1) != 0) {
    v3 = lbl_3_bss_A2410.unk_C;
    if ((v3 - 4) < 0) {
    lbl_3_bss_A2410.unk_4 = lbl_3_bss_A2410.unk_10;
    lbl_3_bss_A2410.unk_5 = lbl_3_bss_A2410.unk_12;
    lbl_3_bss_A2410.unk_6 = lbl_3_bss_A2410.unk_14;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = ((u32 *)&lbl_3_data_35C0)[v3];
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_E = lbl_3_bss_A2410.unk_C;
    lbl_3_bss_A2410.unk_C = 2;
    lbl_3_bss_A2410.unk_8 = 0x80000000;
    lbl_3_bss_A2410.unk_1C = p_lbl_3_rodata_5F0->unk_C;
    } else {
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = ((u32 *)&lbl_3_data_35C0)[v3];
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_C -= 4;
    lbl_3_bss_A2410.unk_1C = p_lbl_3_rodata_5F0->unk_C;
    loc_30.word = ((u32 *)&lbl_3_data_35C0)[lbl_3_bss_A2410.unk_C];
    fn_3_177AC(&loc_30);
    }
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 6) & 0x1) != 0) {
    v0 = lbl_3_bss_A2410.unk_C;
    if ((s32)(v0 + 4) < 16) {
    v12 = (v0 << 2);
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = *(u32 *)((u8 *)&lbl_3_data_35C0 + v12);
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_C += 4;
    lbl_3_bss_A2410.unk_1C = p_lbl_3_rodata_5F0->unk_C;
    }
    v0 = (u32)&loc_2C;
    loc_2C.word = ((u32 *)&lbl_3_data_35C0)[lbl_3_bss_A2410.unk_C];
    fn_3_177AC((void *)v0);
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 4) & 0x1) != 0) {
    v14 = lbl_3_bss_A2410.unk_C;
    if (v14 % 4 != 0) {
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = ((u32 *)&lbl_3_data_35C0)[v14];
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_1C = p_lbl_3_rodata_5F0->unk_C;
    lbl_3_bss_A2410.unk_C--;
    }
    v0 = (u32)&loc_28;
    loc_28.word = ((u32 *)&lbl_3_data_35C0)[lbl_3_bss_A2410.unk_C];
    fn_3_177AC((void *)v0);
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 5) & 0x1) != 0) {
    v15 = lbl_3_bss_A2410.unk_C;
    if (v15 % 4 != 3) {
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = ((u32 *)&lbl_3_data_35C0)[v15];
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_1C = p_lbl_3_rodata_5F0->unk_C;
    lbl_3_bss_A2410.unk_C++;
    }
    v0 = (u32)&loc_24;
    loc_24.word = ((u32 *)&lbl_3_data_35C0)[lbl_3_bss_A2410.unk_C];
    fn_3_177AC((void *)v0);
    }
    } else {
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 7) & 0x1) != 0) {
    v0 = lbl_3_bss_A2410.unk_C;
    lbl_3_bss_A2410.unk_20 = 0;
    if ((v0 - 1) >= 0) {
    lbl_3_bss_A2410.unk_8 = 0x80000000;
    fn_1_A2D84(0xA9150600);
    v0 = lbl_3_bss_A2410.unk_C;
    lbl_3_bss_A2410.unk_C = (v0 - 1);
    }
    loc_1C.word = p_lbl_3_rodata_5F0->unk_0;
    loc_1C.byte[0] = lbl_3_bss_A2410.unk_10;
    loc_1C.byte[1] = lbl_3_bss_A2410.unk_12;
    loc_1C.byte[2] = lbl_3_bss_A2410.unk_14;
    loc_20.word = loc_1C.word;
    fn_3_177AC(&loc_20);
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 6) & 0x1) != 0) {
    v19 = lbl_3_bss_A2410.unk_C;
    lbl_3_bss_A2410.unk_20 = 0;
    lbl_3_bss_A2410.unk_C = (v19 + 1);
    fn_1_A2D84(0xA9150600);
    if (lbl_3_bss_A2410.unk_C >= 3) {
    lbl_3_bss_A2410.unk_C = lbl_3_bss_A2410.unk_E;
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    lbl_3_bss_A2410.unk_0 = lbl_3_bss_A2410.unk_10;
    lbl_3_bss_A2410.unk_1 = lbl_3_bss_A2410.unk_12;
    lbl_3_bss_A2410.unk_2 = lbl_3_bss_A2410.unk_14;
    lbl_3_bss_A2410.unk_1C = p_lbl_3_rodata_5F0->unk_C;
    loc_18.word = ((u32 *)&lbl_3_data_35C0)[lbl_3_bss_A2410.unk_C];
    fn_3_177AC(&loc_18);
    } else {
    v7 = 0x80000000;
    loc_10.word = p_lbl_3_rodata_5F0->unk_4;
    lbl_3_bss_A2410.unk_8 = v7;
    v26 = lbl_3_bss_A2410.unk_10;
    v27 = lbl_3_bss_A2410.unk_12;
    v24 = lbl_3_bss_A2410.unk_14;
    loc_10.byte[0] = v26;
    loc_10.byte[1] = v27;
    loc_10.byte[2] = v24;
    v0 = loc_10.word;
    loc_14.word = v0;
    fn_3_177AC(&loc_14);
    }
    }
    v0 = (u32)&lbl_1_bss_9F8;
    v0 = (u32)((u8 *)v0 + 2);
    v0 = *(u16 *)((u8 *)v0 + (lbl_3_bss_A2410.unk_D * 20));
    if (((v0 >> 4) & 0x1) != 0 || ((v0 >> 5) & 0x1) != 0) {
    loc_8.word = p_lbl_3_rodata_5F0->unk_8;
    v0 = (u32)&loc_C;
    v30 = lbl_3_bss_A2410.unk_C;
    v29 = lbl_3_bss_A2410.unk_10;
    v32 = (s16)(&lbl_3_bss_A2410.unk_10)[v30];
    loc_8.byte[0] = v29;
    loc_8.byte[1] = lbl_3_bss_A2410.unk_12;
    loc_8.byte[2] = lbl_3_bss_A2410.unk_14;
    loc_C.word = loc_8.word;
    fn_3_177AC((void *)v0);
    v0 = (u32)&lbl_3_bss_A2410;
    if ((*(s16 *)((u8 *)v0 + 32)) > 40) {
    v1 = (f32)(lbl_1_bss_BF0.unk_0[lbl_3_bss_A2410.unk_D].unk_8);
    if (v1 < p_lbl_3_rodata_5F0->unk_C) {
    v34 = -8;
    } else {
    v34 = 8;
    }
    v34 = (s16)v34;
    } else {
    if ((*(s16 *)((u8 *)v0 + 32)) > 20) {
    v1 = (f32)(lbl_1_bss_BF0.unk_0[lbl_3_bss_A2410.unk_D].unk_8);
    if (v1 < p_lbl_3_rodata_5F0->unk_C) {
    v34 = -4;
    } else {
    v34 = 4;
    }
    v34 = (s16)v34;
    } else {
    v1 = (f32)(lbl_1_bss_BF0.unk_0[lbl_3_bss_A2410.unk_D].unk_8);
    if (v1 < p_lbl_3_rodata_5F0->unk_C) {
    v34 = -1;
    } else {
    v34 = 1;
    }
    v34 = (s16)v34;
    }
    }
    if ((*(s16 *)((u8 *)v0 + 32)) >= 20) {
    (&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] = ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34) < 0 ? 0 : ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34) > 255 ? 255 : ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34);
    } else {
    v37 = lbl_1_bss_D58.unk_12;
    if (((v37 >> 5) & 0x1) != 0 || ((v37 >> 4) & 0x1) != 0) {
    (&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] = ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34) < 0 ? 0 : ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34) > 255 ? 255 : ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34);
    }
    }
    v1 = (f32)(lbl_1_bss_BF0.unk_0[lbl_3_bss_A2410.unk_D].unk_8);
    v1 = __fabs(v1);
    if (v1 >= p_lbl_3_rodata_5F0->unk_10) {
    v40 = *(s16 *)((u8 *)v0 + 32);
    *(u16 *)((u8 *)v0 + 32) = (v40 + 1);
    } else {
    *(u16 *)((u8 *)v0 + 32) = 0;
    }
    v41 = (&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C];
    if (v41 != 0 && v41 != 255 && v32 != (s32)v41) {
    fn_1_A2D84(0xA9150700);
    }
    }
    }
}
/* fzgx:end fn_3_17100 */

/* fzgx:begin fn_3_17820 */
u32 fn_3_17820(void) {
    return *(u32 *)&(*(u16 (*)[20])&lbl_3_bss_A2410)[2];
}
/* fzgx:end fn_3_17820 */

/* fzgx:begin fn_3_17830 */
typedef struct CustomizeState {
    u8 _pad0[8];
    u32 flags;
    u8 _pad1[16];
    f32 field_1c;
} CustomizeState;

void fn_3_17830(void) {
    (*(CustomizeState *)&lbl_3_bss_A2410).field_1c = lbl_3_rodata_5FC[0];
    (*(CustomizeState *)&lbl_3_bss_A2410).flags |= 0x20000000u;
}
/* fzgx:end fn_3_17830 */

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
