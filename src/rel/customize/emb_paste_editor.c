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
extern u16 lbl_1_bss_9F8[];
extern u8 lbl_3_rodata_4C8[0xc];
extern u8 lbl_3_rodata_4D4[0xc];
extern u32 lbl_801A6410;
extern u32 lbl_801A66B4;
extern u8 lbl_3_data_3234[168];
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

/* fzgx:begin fn_3_F984 noprologue */
#include "types.h"

/* lbl_3_bss_7EDD8: only the word this function writes */
typedef struct {
    u8 pad_0[0xC];
    u32 unk_C;
} View_3_bss_7EDD8;

typedef struct {
    u8 pad_0[0x40];
} View_3_bss_87000;

extern View_3_bss_7EDD8 lbl_3_bss_7EDD8;
extern View_3_bss_87000 lbl_3_bss_87000;
extern u8 lbl_3_data_32DC[0x13];
/* the two card rows' states: retail reads and writes 0x32F0 and 0x32F1, though symbols.txt sizes
 * lbl_3_data_32F0 as one byte; as an array the reset stores schedule as retail's do */
extern u8 lbl_3_data_32F0[2];

/* lbl_1_bss_77380: two rows of 128 0x30-byte entries */
typedef struct {
    u8 pad_0[0x24];
    u32 unk_24;
    u8 pad_28[0x4];
    void *unk_2C;
} Entry_1_bss_77380;

/* lbl_3_bss_87000 in 0xC-byte parts, one per row of lbl_1_bss_77380 */
typedef struct {
    s16 unk_0;
    u8 *unk_4;
    void **unk_8;
} Part_3_bss_87000;

extern Entry_1_bss_77380 lbl_1_bss_77380[2][128];
extern u8 lbl_3_bss_9F664;
extern u8 lbl_3_bss_9F664__fzgx_offset_1[43];
extern u32 lbl_801A6410;

extern void fn_1_B9BE0(void);
extern u8 fn_1_B7C00(void);
extern int fn_1_B7E98(s32);
extern void fn_1_B9CCC(s32, u32);
extern int fn_1_B7CD4(void);
extern void *fn_1_45D0(u32, u32, char *, u32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_1_B9C0C(void);
extern void fn_1_FE004(void);

#define PART(row) (((Part_3_bss_87000 *)&lbl_3_bss_87000)[row])

/* card row `row`: on its first pass fn_1_B9CCC(row, 16); once fn_1_B7CD4 reports done, copies each
 * lbl_1_bss_77380 entry's 0x2000-byte block into a new allocation and stores the clamped count; returns the
 * row's next state */
static inline u8 copy_row(s32 row, u8 *state) {
    u8 i;
    u8 count;
    u8 next;

    if (fn_1_B7E98(row) != 0) {
        if (*state == 0) {
            fn_1_B9CCC(row, 16);
            *state = 1;
            next = 1;
        } else if (fn_1_B7CD4() != 0 && *state == 1) {
            count = 0;
            for (i = 0; i < 128; i++) {
                if (lbl_1_bss_77380[row][i].unk_24 == 0 || lbl_1_bss_77380[row][i].unk_2C == NULL) {
                    PART(row).unk_8[i] = NULL;
                } else {
                    PART(row).unk_8[i] = fn_1_45D0(lbl_801A6410, 0x2000, (char *)lbl_3_data_32DC, 0x61B);
                    fn_80008BA8(PART(row).unk_8[i], lbl_1_bss_77380[row][i].unk_2C, 0x2000);
                    PART(row).unk_4[i] = 1;
                    count++;
                }
            }
            PART(row).unk_0 = count < 9 ? 9 : count > 128 ? 128 : count;
            *state = 2;
            next = 2;
        } else {
            PART(row).unk_0 = 9;
            return 2;
        }
        return next;
    } else {
        return 2;
    }
}

void fn_3_F984(void) {
    if (lbl_3_bss_9F664 == 0) {
        fn_1_B9BE0();
        lbl_3_bss_9F664 = 1;
    } else if (fn_1_B7C00() == 0) {
        if (lbl_3_data_32F0[0] < 2) {
            lbl_3_data_32F0[0] = copy_row(0, &lbl_3_data_32F0[0]);
        } else if (lbl_3_data_32F0[1] < 2) {
            lbl_3_data_32F0[1] = copy_row(1, &lbl_3_data_32F0[1]);
        } else if (lbl_3_bss_9F664__fzgx_offset_1[0] == 0) {
            fn_1_B9C0C();
            lbl_3_bss_9F664__fzgx_offset_1[0] = 1;
        } else {
            lbl_3_data_32F0[1] = 0;
            lbl_3_data_32F0[0] = 0;
            lbl_3_bss_7EDD8.unk_C = 0x40000000;
            lbl_3_bss_9F664 = 0;
            lbl_3_bss_9F664__fzgx_offset_1[0] = 0;
            fn_1_FE004();
        }
    }
}
/* fzgx:end fn_3_F984 */

/* fzgx:begin fn_3_FD30 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 50.0f;
    s = 500.0f;
    s = 31.200000762939453f;
    s = 312.0f;
    s = 68.0f;
    s = 20.0f;
    s = 96.0f;
    s = 1.3600000143051147f;
    s = 161.0f;
    s = 1.015625f;
    s = 129.0f;
    s = 15.0f;
    s = 10.0f;
    s = 0.0f;
    s = 86.0f;
    s = 0.5f;
    s = 139.0f;
    s = 75.0f;
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table2[3] = {0xFFFF0000, 0xFFFF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 185.0f;
    s = 180.0f;
    s = 276.0f;
    s = 116.0f;
    s = 7.0f;
    s = 205.0f;
    s = 11.399999618530273f;
    s = 40.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 80.0f;
    s = 274.0f;
    s = 0.5833333134651184f;
    s = 0.5416666865348816f;
    s = 0.4583333432674408f;
    d = 4503599627370496.0;
    s = 320.0f;
    s = 240.0f;
    s = 5.0f;
    s = 6.099999904632568f;
    s = 0.800000011920929f;
    s = 228.0f;
    s = 252.0f;
    s = 0.10000000149011612f;
    s = -30.0f;
    s = 750.0f;
    s = 48.0f;
    s = 660.0f;
    s = 44.0f;
    s = 24.0f;
    s = 302.0f;
    s = 70.0f;
    s = 330.0f;
    s = 1.2699999809265137f;
    s = 390.0f;
    s = 308.0f;
    s = 1.0f;
    s = 368.0f;
    s = 360.0f;
    s = 30.0f;
    s = 0.4000000059604645f;
    s = 32768.0f;
    s = 0.90625f;
    s = 0.921875f;
    s = 0.9375f;
}
static const unsigned long fzgx_pool_table4[25] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x40200000, 0xC1700000, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x40200000, 0xC1700000, 0x00000000, 0x00000000, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x40200000, 0xC1700000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 55.0f;
    s = 90000.0f;
    s = 95.0f;
    s = 17.0f;
    s = 354.0f;
    s = 310.0f;
    s = 365.0f;
    s = 143.0f;
    s = 19.29990005493164f;
    s = 0.009999999776482582f;
    s = 0.75f;
    s = 351.0f;
    s = 387.0f;
    s = 0.6000000238418579f;
    s = 0.699999988079071f;
    s = 348.0f;
    s = 384.0f;
}
static const unsigned long fzgx_pool_table6[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 200.0f;
    s = 0.05000000074505806f;
}
#pragma section code_type ".text"

struct InputEntry { u16 unk_0; u8 pad_2[6]; u16 unk_8; u16 unk_A; u8 pad_C[8]; };
struct InputState {
 union {
  struct { u8 pad8[8]; struct InputEntry unk_8[1]; };
  struct { u8 pad10[0x10]; struct InputEntry unk_10[1]; };
  struct { u8 pad12[0x12]; struct InputEntry unk_12[1]; };
 };
};

/* Three halfwords copied as one block (retail moves them with lwz/lhz). */
typedef struct { s16 v[3]; } PasteTri;
/* Six words copied as one block. */
typedef struct { f32 v[6]; } PasteSix;

/* One 0x2060-byte entry of a paste slot. */
typedef struct {
    s16 unk_0;
    u8 pad_2[0x2];
    u32 flags;
    PasteTri unk_8;
    u8 pad_E[0x2];
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x10];
    PasteSix unk_28;
    u8 pad_40[0x2020];
} PasteEntry;

/* One paste slot (0x81C0 bytes). */
typedef struct {
    u8 pad_0[0x7];
    u8 unk_7;
    u8 pad_8[0x18];
    PasteEntry e[4];
    u8 pad_81A0[0x20];
} PasteSlot;

typedef struct {
    u8 pad_0[0x8];
    u8 unk_8;
    u8 pad_9[0x81B7];
} SlotHeader;

typedef struct {
    SlotHeader *unk_0;
    u8 pad_4[0x8];
} EditorSlots;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x4];
    u32 unk_C;
    u32 unk_10;
    u8 unk_14;
    u8 unk_15;
    u8 pad_16[0x2];
    u32 unk_18;
    s16 unk_1C;
    u8 pad_1E[0x8];
    PasteTri unk_26;
    u32 unk_2C[4];
    u8 pad_3C[0xA];
    u8 unk_46;
    u8 unk_47;
    u8 pad_48[0x20];
} EditorSave;

typedef struct {
    u32 w[9];
} EditorView;

typedef struct {
    u32 unk_0;
    PasteSix unk_4;
    u8 pad_1C[0x8];
} EditorLight;

typedef struct {
    u8 pad_0[0x34];
    f32 unk_34;
    u8 pad_38[0xB8];
    f32 unk_F0;
    u8 pad_F4[0xA8];
    f32 unk_19C;
    u8 pad_1A0[0x24];
    f32 unk_1C4;
} EditorConsts;

extern struct InputState lbl_1_bss_9F8;
extern PasteSlot lbl_3_bss_7EE40;
extern u32 lbl_3_rodata_288[60];

extern void fn_1_A2D84(u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_1_FC414(void *, void *);
extern void fn_3_11994(u8, s16, PasteEntry *, PasteEntry *);
extern void fn_3_12FD4(u32, u8, u32, f32 *, f32 *);
extern int fn_3_11930(void);

static EditorSlots lbl_3_bss_7EDC0;
static u8 *lbl_3_bss_7EDCC;
static u8 fzgx_pool_fzgx_bss_gap_7EDD0[0x4];
static u8 fzgx_pool_lbl_3_bss_7EDD4;
static u8 fzgx_pool_lbl_3_bss_7EDD5;
static u8 lbl_3_bss_7EDCC__fzgx_offset_A;
static EditorSave lbl_3_bss_7EDD8;
static u8 fzgx_pool_fzgx_bss_gap_7EE40[0x8200];
static PasteSlot lbl_3_bss_87040;
static u8 lbl_3_bss_8F200[0x10440];
static EditorView lbl_3_bss_9F640;
static u8 fzgx_pool_fzgx_bss_gap_9F664[0x4];
static f32 lbl_3_bss_9F665__fzgx_offset_3;
static EditorView lbl_3_bss_9F665__fzgx_offset_7;
static EditorLight lbl_3_bss_9F690;
static u8 lbl_3_bss_9F690__fzgx_offset_24;

#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_3_bss_7EDC0(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .bss objects in retail order */
    s = *(u8 *)&lbl_3_bss_7EDC0;
    s = *(u8 *)&lbl_3_bss_7EDCC;
    s = *(u8 *)fzgx_pool_fzgx_bss_gap_7EDD0;
    s = fzgx_pool_lbl_3_bss_7EDD4;
    s = fzgx_pool_lbl_3_bss_7EDD5;
    s = lbl_3_bss_7EDCC__fzgx_offset_A;
    s = *(u8 *)&lbl_3_bss_7EDD8;
    s = *(u8 *)fzgx_pool_fzgx_bss_gap_7EE40;
    s = *(u8 *)&lbl_3_bss_87040;
    s = *(u8 *)lbl_3_bss_8F200;
    s = *(u8 *)&lbl_3_bss_9F640;
    s = *(u8 *)fzgx_pool_fzgx_bss_gap_9F664;
    s = *(u8 *)&lbl_3_bss_9F665__fzgx_offset_3;
    s = *(u8 *)&lbl_3_bss_9F665__fzgx_offset_7;
    s = *(u8 *)&lbl_3_bss_9F690;
    s = lbl_3_bss_9F690__fzgx_offset_24;
}
#pragma section code_type ".text"

/* Same body as fn_3_F948 (emb_memcard.c): number of occupied entries. */
static inline s16 count_used(PasteSlot *slot) {
    s16 i;
    s16 count = 0;

    for (i = 0; i < 4; i++) {
        if (slot->e[i].flags & 0x80000000) {
            count++;
        }
    }
    return count;
}

#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))

static inline f32 clamp_blend(f32 value, const EditorConsts *limits) {
    return CLAMP(value, limits->unk_34, limits->unk_F0);
}

static inline void initialize_entry(PasteSlot *slot, EditorSave *state, u8 *character) {
    state->unk_C = 0x8000000;
    fn_3_12FD4(0, (u8)state->unk_1C, character[0x328], &slot->e[0].unk_10, &slot->e[0].unk_14);
}

void fn_3_FD30(void) {
    struct { EditorSave *value; } pw;
#define p pw.value
    register const EditorConsts *c;
    u32 sel;
    s32 next;
    register u32 idx;
    s16 i;
    s16 count;
    PasteEntry *entry;
    struct { struct InputState *base; } input;

    c = (const EditorConsts *)lbl_3_rodata_288;
    p = &lbl_3_bss_7EDD8;
    lbl_3_bss_9F665__fzgx_offset_3 += (0.00999999978f);

    if ((lbl_1_bss_9F8.unk_8[p->unk_14].unk_0 >> 4) & 1) {
        p->unk_10 = p->unk_C;
        p->unk_C = 0x1000000;
        lbl_3_bss_9F665__fzgx_offset_7 = lbl_3_bss_9F640;
    }

    input.base = &lbl_1_bss_9F8;
    if ((input.base->unk_12[p->unk_14].unk_0 & 1) || ((input.base = (struct InputState *)((u8 *)input.base + p->unk_14 * sizeof(struct InputEntry))), (input.base->unk_10[0].unk_0 & 1))) {
        sel = (u8)(lbl_3_bss_7EDD8.unk_15);
        next = sel - 1;
        lbl_3_bss_7EDD8.unk_15 = CLAMP(next, 0, 3);
        if (sel != lbl_3_bss_7EDD8.unk_15) {
            lbl_3_bss_9F665__fzgx_offset_3 = (0.00999999978f);
            fn_1_A2D84(0xA9010000);
        }
    }

    if (((lbl_1_bss_9F8.unk_12[p->unk_14].unk_0 >> 1) & 1) || ((lbl_1_bss_9F8.unk_10[p->unk_14].unk_0 >> 1) & 1)) {
        sel = (u8)(lbl_3_bss_7EDD8.unk_15);
        next = sel + 1;
        lbl_3_bss_7EDD8.unk_15 = CLAMP(next, 0, 3);
        if (sel != lbl_3_bss_7EDD8.unk_15) {
            lbl_3_bss_9F665__fzgx_offset_3 = (0.0500000007f);
            fn_1_A2D84(0xA9010000);
        }
    }

    {
        struct { f32 result; f32 value; } blend;
        blend.value = lbl_3_bss_9F665__fzgx_offset_3;
        if (blend.value < (0.0f)) {
            blend.result = (0.0f);
        } else if (blend.value > (1.0f)) {
            blend.result = (1.0f);
        } else {
            blend.result = blend.value;
        }
        lbl_3_bss_9F665__fzgx_offset_3 = blend.result;
    }

    if (lbl_3_bss_7EE40.e[lbl_3_bss_7EDD8.unk_15].flags & 0x80000000) {
        lbl_3_bss_7EDD8.unk_1C = lbl_3_bss_7EE40.e[lbl_3_bss_7EDD8.unk_15].unk_0;
    }

    if ((lbl_1_bss_9F8.unk_8[p->unk_14].unk_0 >> 8) & 1) {
        fn_1_A2D84(0xA9010100);
        fn_80008BEC(&lbl_3_bss_87040, 0, 0x8180);
        idx = lbl_3_bss_7EDD8.unk_15;
        if (lbl_3_bss_7EE40.e[idx].flags & 0x80000000) {
            fn_80008BA8(&lbl_3_bss_87040.e[idx], &lbl_3_bss_7EE40.e[idx], 0x2060);
            lbl_3_bss_7EDD8.unk_C = 0x2000000;
            lbl_3_bss_7EDD8.unk_10 = 0;
            fn_3_11994(lbl_3_bss_7EDD8.unk_15, lbl_3_bss_7EDD8.unk_1C, lbl_3_bss_7EE40.e, lbl_3_bss_87040.e);
            idx = lbl_3_bss_7EDD8.unk_15;
            lbl_3_bss_9F690.unk_4 = lbl_3_bss_87040.e[idx].unk_28;
            lbl_3_bss_7EDD8.unk_26 = lbl_3_bss_87040.e[idx].unk_8;
        } else if (lbl_3_bss_7EDC0.unk_0[lbl_3_bss_7EDD8.unk_46].unk_8 > 1) {
            lbl_3_bss_7EDD8.unk_C = 0x10000000;
        } else {
            initialize_entry((PasteSlot *)((u8 *)&lbl_3_bss_87040 + idx * sizeof(PasteEntry)), &lbl_3_bss_7EDD8, lbl_3_bss_7EDCC);
        }
    }

    if (((lbl_1_bss_9F8.unk_8[p->unk_14].unk_0 >> 11) & 1) && fn_3_11930() != 0) {
        fn_1_A2D84(0xA9010200);
        lbl_3_bss_7EDD8.unk_C = 0x400000;
        lbl_3_bss_9F690__fzgx_offset_24 = 1;
        lbl_3_bss_7EDCC__fzgx_offset_A = 1;
    }

    if ((lbl_1_bss_9F8.unk_8[p->unk_14].unk_0 >> 9) & 1) {
        fn_1_A2D84(0xA9010200);
        lbl_3_bss_7EDD8.unk_C = 0x400000;
        lbl_3_bss_9F690__fzgx_offset_24 = 1;
        if (fn_3_11930() != 0) {
            lbl_3_bss_7EDCC__fzgx_offset_A = 2;
        } else {
            lbl_3_bss_7EDCC__fzgx_offset_A = 4;
        }
    }

    if ((lbl_1_bss_9F8.unk_8[p->unk_14].unk_0 >> 10) & 1) {
        if (lbl_3_bss_7EE40.e[lbl_3_bss_7EDD8.unk_15].flags & 0x80000000) {
            if ((lbl_3_bss_7EDD8.unk_10 & 0x20000000) && (s32)lbl_3_bss_7EDD8.unk_18 != 0) {
                lbl_3_bss_7EE40.unk_7 = count_used(&lbl_3_bss_7EE40);
                fn_1_A2D84(0xA9010000);
                fn_80008BEC((u8 *)&lbl_3_bss_7EE40 + lbl_3_bss_7EDD8.unk_15 * 0x2060 + 0x20, 0, 0x2060);
                fn_80008BEC(&lbl_3_bss_87040.e[lbl_3_bss_7EDD8.unk_15], 0, 0x2060);
                fn_1_FC414(lbl_3_bss_8F200, (void *)1);
                lbl_3_bss_7EDD8.unk_2C[lbl_3_bss_7EDD8.unk_15] = 1;
            } else {
                lbl_3_bss_7EDD8.unk_10 = lbl_3_bss_7EDD8.unk_C;
                lbl_3_bss_7EDD8.unk_C = 0x20000000;
            }
        }
        lbl_3_bss_7EDD8.unk_18 = 0;
    }
}
/* fzgx:end fn_3_FD30 */

/* fzgx:begin fn_3_10260 noprologue */
#include "types.h"

/* lbl_1_bss_9F8: one 0x14-byte button record per pad */
typedef struct {
    u16 unk_0;
    u8 pad_2[0x6];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} PadButtons;

typedef struct {
    u8 pad_0[0x328];
    s8 unk_328; /* signed: as u8 the else call's registers differ from retail */
    u8 pad_329[0x67];
    u32 unk_390;
} Obj_3_bss_7EDCC_At0;

typedef struct {
    u8 unk_0;
    u8 pad_1[0x7];
} Obj_3_bss_7EDC0_Sel;

typedef struct {
    u8 pad_0[0x81A4];
    Obj_3_bss_7EDC0_Sel unk_81A4[3];
    u8 pad_81BC[0x4];
} Obj_3_bss_7EDC0_At0;

typedef struct {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u8 unk_14;
    u8 unk_15;
    u8 pad_16[0x6];
    s16 unk_1C;
    u8 pad_1E[0x28];
    u8 unk_46;
    u8 pad_47[0x21];
} Obj_3_bss_7EDD8;

typedef struct {
    u8 pad_0[0x8];
    u8 unk_8;
} Obj_3_bss_7EE40;

/* lbl_3_bss_87040 in 0x2060-byte parts */
typedef struct {
    u8 pad_0[0x30];
    f32 unk_30;
    f32 unk_34;
    u8 pad_38[0x2028];
} Obj_3_bss_87040_Part;

extern PadButtons lbl_1_bss_9F8[4];
extern Obj_3_bss_7EE40 lbl_3_bss_7EE40;
extern Obj_3_bss_87040_Part lbl_3_bss_87040[];

extern void fn_1_A2D84(u32);
extern void fn_3_12FD4(s32, u8, u8, f32 *, f32 *);

/* the retail TU's .bss objects this function uses, at their retail offsets, so MWCC addresses them off one
 * section base; the fzgx_pool_gap_ objects span the parts this function does not touch */
Obj_3_bss_7EDC0_At0 *fzgx_obj_lbl_3_bss_7EDC0;
u8 fzgx_pool_gap_7EDC4[0x8];
Obj_3_bss_7EDCC_At0 *fzgx_obj_lbl_3_bss_7EDCC;
u8 fzgx_pool_gap_7EDD0[0x8];
Obj_3_bss_7EDD8 fzgx_obj_lbl_3_bss_7EDD8;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7EDC0;
    s = *fzgx_pool_gap_7EDC4;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7EDCC;
    s = *fzgx_pool_gap_7EDD0;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7EDD8;
}
#pragma section code_type ".text"

void fn_3_10260(void) {
    u32 index;

    if ((lbl_1_bss_9F8[fzgx_obj_lbl_3_bss_7EDD8.unk_14].unk_8 >> 4) & 1) {
        fzgx_obj_lbl_3_bss_7EDD8.unk_10 = fzgx_obj_lbl_3_bss_7EDD8.unk_C;
        fzgx_obj_lbl_3_bss_7EDD8.unk_C = 0x01000000;
    }
    /* step unk_1C down or up, wrapping at lbl_3_bss_7EE40.unk_8 */
    if (((lbl_1_bss_9F8[index = fzgx_obj_lbl_3_bss_7EDD8.unk_14].unk_10 >> 3) & 1) ||
        ((lbl_1_bss_9F8[index].unk_12 >> 3) & 1)) {
        fzgx_obj_lbl_3_bss_7EDD8.unk_1C = (fzgx_obj_lbl_3_bss_7EDD8.unk_1C - 1 + lbl_3_bss_7EE40.unk_8) %
                                          lbl_3_bss_7EE40.unk_8;
        fn_1_A2D84(0xA9010000);
    }
    if (((lbl_1_bss_9F8[index = fzgx_obj_lbl_3_bss_7EDD8.unk_14].unk_10 >> 2) & 1) ||
        ((lbl_1_bss_9F8[index].unk_12 >> 2) & 1)) {
        fzgx_obj_lbl_3_bss_7EDD8.unk_1C = (fzgx_obj_lbl_3_bss_7EDD8.unk_1C + 1) % lbl_3_bss_7EE40.unk_8;
        fn_1_A2D84(0xA9010000);
    }
    fzgx_obj_lbl_3_bss_7EDD8.unk_1C = fzgx_obj_lbl_3_bss_7EDD8.unk_1C > lbl_3_bss_7EE40.unk_8 - 1 ? 0
                                      : fzgx_obj_lbl_3_bss_7EDD8.unk_1C < 0 ? lbl_3_bss_7EE40.unk_8 - 1
                                                                             : fzgx_obj_lbl_3_bss_7EDD8.unk_1C;
    if ((lbl_1_bss_9F8[fzgx_obj_lbl_3_bss_7EDD8.unk_14].unk_8 >> 8) & 1) {
        fn_1_A2D84(0xA9010100);
        fzgx_obj_lbl_3_bss_7EDD8.unk_C = 0x08000000;
        /* retail tests the flag with a register rotate, as fn_3_106FC does */
        if (__rlwnm(fzgx_obj_lbl_3_bss_7EDCC->unk_390, 6, 31, 31)) {
            fn_3_12FD4(5, fzgx_obj_lbl_3_bss_7EDD8.unk_1C,
                       fzgx_obj_lbl_3_bss_7EDC0[fzgx_obj_lbl_3_bss_7EDD8.unk_46].unk_81A4[fzgx_obj_lbl_3_bss_7EDD8.unk_1C].unk_0,
                       &lbl_3_bss_87040[fzgx_obj_lbl_3_bss_7EDD8.unk_15].unk_30,
                       &lbl_3_bss_87040[fzgx_obj_lbl_3_bss_7EDD8.unk_15].unk_34);
        } else {
            fn_3_12FD4(0, fzgx_obj_lbl_3_bss_7EDD8.unk_1C, fzgx_obj_lbl_3_bss_7EDCC->unk_328,
                       &lbl_3_bss_87040[fzgx_obj_lbl_3_bss_7EDD8.unk_15].unk_30,
                       &lbl_3_bss_87040[fzgx_obj_lbl_3_bss_7EDD8.unk_15].unk_34);
        }
    }
    if ((lbl_1_bss_9F8[fzgx_obj_lbl_3_bss_7EDD8.unk_14].unk_8 >> 9) & 1) {
        fn_1_A2D84(0xA9010200);
        fzgx_obj_lbl_3_bss_7EDD8.unk_C = 0x40000000;
    }
}
/* fzgx:end fn_3_10260 */

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

/* fzgx:begin fn_3_106FC noprologue */
#include "types.h"
#include "types.h"
#include "rel/customize/globals.h"

/* begin rel/customize/emb_paste_editor.h (deltawave784/fzgx@13b0aeca (CC0)) */
#ifndef REL_CUSTOMIZE_EMB_PASTE_EDITOR_H
#define REL_CUSTOMIZE_EMB_PASTE_EDITOR_H


// Generated by `fzgx headers --module customize --tu emb_paste_editor.c`: globals of emb_paste_editor.c (referenced by its
// functions or living in its .data block), layouts recovered from every access in the module.

// lbl_3_bss_7EDD8: .bss size 0x68, 12 refs from emb_paste_editor.c
#ifndef FZGX_TYPES_LBL_3_BSS_7EDD8
#define FZGX_TYPES_LBL_3_BSS_7EDD8
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u32 unk_0;  // 0 loads, 2 stores
    u32 unk_4;  // 2 loads, 1 stores
    u8 pad_8[0x2];
    s16 unk_A;  // 1 loads, 1 stores
    u32 unk_C;  // 14 loads, 8 stores
    u32 unk_10;  // 2 loads, 4 stores
    u8 unk_14;  // 23 loads, 0 stores
    u8 unk_15;  // 11 loads, 0 stores
    u8 pad_16[0x2];
    u32 unk_18;  // 6 loads, 6 stores
    s16 unk_1C;  // 4 loads, 0 stores
    u8 unk_1E;  // 9 loads, 3 stores
    u8 unk_1F;  // 9 loads, 2 stores
    u8 unk_20;  // 2 loads, 3 stores
    u8 unk_21;  // 2 loads, 3 stores
    s16 unk_22;  // 2 loads, 2 stores
    s16 unk_24;  // 13 loads, 5 stores
    s16 unk_26;  // 3 loads, 2 stores
    s16 unk_28;  // 2 loads, 2 stores
    u16 unk_2A;  // 1 loads, 0 stores
    u32 unk_2C;  // 0 loads, 3 stores
    u32 unk_30;  // 0 loads, 1 stores
    u32 unk_34;  // 0 loads, 1 stores
    u32 unk_38;  // 0 loads, 1 stores
    u8 unk_3C;  // 12 loads, 2 stores
    u8 pad_3D[0x9];
    u8 unk_46;  // 2 loads, 1 stores
    u8 unk_47;  // 0 loads, 1 stores
    s16 unk_48;  // 2 loads, 2 stores
    u8 pad_4A[0x2];
    s16 unk_4C;  // 2 loads, 2 stores
    s16 unk_4E;  // 2 loads, 2 stores
    u8 pad_50[0x1];
    u8 unk_51;  // 1 loads, 2 stores
    u8 pad_52[0x16];
} Obj_3_bss_7EDD8;
#endif
extern Obj_3_bss_7EDD8 lbl_3_bss_7EDD8;
  // typedefs.json decl override

// lbl_3_bss_7EE40: .bss size 0x81C0, 7 refs from emb_paste_editor.c
#ifndef FZGX_TYPES_LBL_3_BSS_7EE40
#define FZGX_TYPES_LBL_3_BSS_7EE40
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u32 unk_0;  // 1 loads, 0 stores
    u8 pad_4[0x3];
    u8 unk_7;  // 0 loads, 5 stores
    u8 unk_8;  // 4 loads, 3 stores
    u8 pad_9[0x17];
    s16 unk_20;  // 1 loads, 0 stores
    u8 pad_22[0x2];
    u32 unk_24;  // 14 loads, 2 stores
    u32 unk_28;  // 1 loads, 0 stores
    u16 unk_2C;  // 1 loads, 0 stores
    u8 pad_2E[0x2];
    f32 unk_30;  // 0 loads, 1 stores
    f32 unk_34;  // 0 loads, 1 stores
    u8 pad_38[0x28];
    f32 unk_60;  // 0 loads, 1 stores
    f32 unk_64;  // 0 loads, 1 stores
    u8 pad_68[0x8158];
} Obj_3_bss_7EE40;
#endif
extern Obj_3_bss_7EE40 lbl_3_bss_7EE40;  // typedefs.json decl override

// lbl_3_bss_87040: .bss size 0x81C0, 5 refs from emb_paste_editor.c
typedef struct {
    u8 pad_0[0x24];
    u32 unk_24;  // 1 loads, 1 stores
    u32 unk_28;  // 0 loads, 2 stores
    u16 unk_2C;  // 0 loads, 2 stores
    u8 pad_2E[0x17];
    u8 unk_45;  // 1 loads, 0 stores
    u8 pad_46[0x2];
    u32 unk_48;  // 0 loads, 2 stores
    u32 unk_4C;  // 0 loads, 2 stores
    u32 unk_50;  // 0 loads, 2 stores
    u32 unk_54;  // 0 loads, 2 stores
    u32 unk_58;  // 0 loads, 2 stores
    u32 unk_5C;  // 0 loads, 2 stores
    f32 unk_60;  // 1 loads, 2 stores
    f32 unk_64;  // 1 loads, 2 stores
    u8 pad_68[0x8158];
} Obj_3_bss_87040;
extern Obj_3_bss_87040 lbl_3_bss_87040;

// lbl_3_bss_87000: .bss size 0x40, 2 refs from emb_paste_editor.c
#ifndef FZGX_TYPES_LBL_3_BSS_87000
#define FZGX_TYPES_LBL_3_BSS_87000
// librarian 2026-10-14: two 0xC-byte banks lead the object (fn_3_F984 indexes them; emb_paste_editor.c's Pool/Entry agree)
typedef struct {
    u16 count;
    u8 pad_2[0x2];
    void *data;
    void **items;
} Obj_3_bss_87000_Bank;
typedef struct {
    Obj_3_bss_87000_Bank banks[2];
    u8 pad_18[0x4];
    u8 *flags;
    void **items;
    u8 pad_24[0x1C];
} Obj_3_bss_87000;
#endif
extern Obj_3_bss_87000 lbl_3_bss_87000;

// lbl_3_bss_9F640: .bss size 0x24, 2 refs from emb_paste_editor.c
typedef struct {
    u8 pad_0[0x4];
    f32 unk_4;  // 1 loads, 2 stores
    f32 unk_8;  // 1 loads, 2 stores
    f32 unk_C;  // 4 loads, 3 stores
    u32 unk_10;  // 1 loads, 1 stores
    u32 unk_14;  // 1 loads, 1 stores
    u32 unk_18;  // 1 loads, 1 stores
    u8 pad_1C[0x8];
} Obj_3_bss_9F640;
extern Obj_3_bss_9F640 lbl_3_bss_9F640;

// lbl_3_bss_9F690: .bss size 0x20D8, 2 refs from emb_paste_editor.c
typedef struct {
    u8 pad_0[0x4];
    f32 unk_4;  // 0 loads, 2 stores
    f32 unk_8;  // 0 loads, 2 stores
    f32 unk_C;  // 0 loads, 2 stores
    f32 unk_10;  // 0 loads, 1 stores
    f32 unk_14;  // 0 loads, 1 stores
    f32 unk_18;  // 1 loads, 1 stores
    u8 pad_1C[0x20BC];
} Obj_3_bss_9F690;
extern Obj_3_bss_9F690 lbl_3_bss_9F690;

  // typedefs.json decl override

#endif  // REL_CUSTOMIZE_EMB_PASTE_EDITOR_H

/* end rel/customize/emb_paste_editor.h */

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 50.0f;
    s = 500.0f;
    s = 31.200000762939453f;
    s = 312.0f;
    s = 68.0f;
    s = 20.0f;
    s = 96.0f;
    s = 1.3600000143051147f;
    s = 161.0f;
    s = 1.015625f;
    s = 129.0f;
    s = 15.0f;
    s = 10.0f;
    s = 0.0f;
    s = 86.0f;
    s = 0.5f;
    s = 139.0f;
    s = 75.0f;
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table2[3] = {0xFFFF0000, 0xFFFF0000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 185.0f;
    s = 180.0f;
    s = 276.0f;
    s = 116.0f;
    s = 7.0f;
    s = 205.0f;
    s = 11.399999618530273f;
    s = 40.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 80.0f;
    s = 274.0f;
    s = 0.5833333134651184f;
    s = 0.5416666865348816f;
    s = 0.4583333432674408f;
    d = 4503599627370496.0;
    s = 320.0f;
    s = 240.0f;
    s = 5.0f;
    s = 6.099999904632568f;
    s = 0.800000011920929f;
    s = 228.0f;
    s = 252.0f;
    s = 0.10000000149011612f;
    s = -30.0f;
    s = 750.0f;
    s = 48.0f;
    s = 660.0f;
    s = 44.0f;
    s = 24.0f;
    s = 302.0f;
    s = 70.0f;
    s = 330.0f;
    s = 1.2699999809265137f;
    s = 390.0f;
    s = 308.0f;
    s = 1.0f;
    s = 368.0f;
    s = 360.0f;
    s = 30.0f;
    s = 0.4000000059604645f;
    s = 32768.0f;
    s = 0.90625f;
    s = 0.921875f;
    s = 0.9375f;
}
static const unsigned long fzgx_pool_table4[25] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x40200000, 0xC1700000, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x40200000, 0xC1700000, 0x00000000, 0x00000000, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x40200000, 0xC1700000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 55.0f;
    s = 90000.0f;
    s = 95.0f;
    s = 17.0f;
    s = 354.0f;
    s = 310.0f;
    s = 365.0f;
    s = 143.0f;
    s = 19.29990005493164f;
    s = 0.009999999776482582f;
    s = 0.75f;
    s = 351.0f;
    s = 387.0f;
    s = 0.6000000238418579f;
    s = 0.699999988079071f;
    s = 348.0f;
    s = 384.0f;
}
static const unsigned long fzgx_pool_table6[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 200.0f;
    s = 0.05000000074505806f;
    s = 0.3499999940395355f;
    s = 0.0005000000237487257f;
}
#pragma section code_type ".text"

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
extern void fn_80008BA8(void *, void *, u32);
extern void fn_3_11994(s32, s32, void *, void *);

static inline struct InputEntry *array_read(struct InputEntry *array) { return array; }

typedef struct { f32 x, y, z; } ViewVec;
typedef struct { ViewVec eye; ViewVec at; } ViewVecs;

/* Editor setup context: members stay register variables (constants assigned
 * to plain locals would be folded into their uses). */
typedef struct {
    Obj_3_bss_87040 *slot;
    u32 state;
    u8 *slots;
    u32 zero;
    ViewVecs *view;
    Obj_3_bss_9F690 *cam;
} EditSetup;

#define BANK_COUNT(p) (lbl_3_bss_87000.banks[(p)->unk_3C].count)
#define CLAMP(x, lo, hi) (((x) < (lo)) ? (lo) : (((x) > (hi)) ? (hi) : (x)))

#pragma opt_dead_assignments off
static inline struct InputEntry *fn_3_106FC_array_read(struct InputEntry *array) { return array; }
#pragma opt_propagation off
void fn_3_106FC(void) {
    struct InputEntry *buttons;
    Obj_3_bss_7EDD8 *q;
    u32 index;
    Obj_3_bss_7EDD8 *p;
    s32 next;
    u8 row;
    u8 top;

    p = &lbl_3_bss_7EDD8;
    top = p->unk_1E;
    next = top + 1;
    row = p->unk_1F;
    if (row + next > BANK_COUNT(p)) {
        p->unk_1E = CLAMP(top - 1, 0, BANK_COUNT(p) - 1);
    }

    buttons = fn_3_106FC_array_read(lbl_1_bss_9F8.unk_8);
    q = &lbl_3_bss_7EDD8;
    if ((buttons[q->unk_14].unk_0 >> 4) & 1) {
        q->unk_10 = q->unk_C;
        q->unk_C = 0x1000000;
    }
    if ((fn_3_106FC_array_read(lbl_1_bss_9F8.unk_10)[index = q->unk_14].unk_0 & 1) || (fn_3_106FC_array_read(lbl_1_bss_9F8.unk_12)[index].unk_0 & 1)) {
        if (p->unk_1F == 0) {
            if (p->unk_1E != 0) {
                lbl_3_bss_7EDD8.unk_21 = 10;
                lbl_3_bss_7EDD8.unk_20 = 0;
                p->unk_1E--;
                fn_1_A2D84(0xA9010000);
            }
        } else {
            p->unk_1F--;
            fn_1_A2D84(0xA9010000);
        }
    }
    index = q->unk_14;
    if (((fn_3_106FC_array_read(lbl_1_bss_9F8.unk_10)[index].unk_0 >> 1) & 1) || ((fn_3_106FC_array_read(lbl_1_bss_9F8.unk_12)[index].unk_0 >> 1) & 1)) {
        if (p->unk_1F > 7) {
            if (p->unk_1E + 9 < lbl_3_bss_87000.banks[p->unk_3C].count) {
                lbl_3_bss_7EDD8.unk_20 = 10;
                lbl_3_bss_7EDD8.unk_21 = 0;
                p->unk_1E++;
                fn_1_A2D84(0xA9010000);
            }
        } else {
            p->unk_1F++;
            fn_1_A2D84(0xA9010000);
        }
    }
    if ((fn_3_106FC_array_read(lbl_1_bss_9F8.unk_12)[q->unk_14].unk_0 >> 8) & 1) {
        p->unk_3C = (p->unk_3C + 2) % 3;
        fn_1_A2D84(0xA9010000);
    }
    if ((fn_3_106FC_array_read(lbl_1_bss_9F8.unk_12)[q->unk_14].unk_0 >> 9) & 1) {
        p->unk_3C = (p->unk_3C + 1) % 3;
        fn_1_A2D84(0xA9010000);
    }
    if ((fn_3_106FC_array_read(lbl_1_bss_9F8.unk_8)[q->unk_14].unk_0 >> 8) & 1) {
        u32 bank = p->unk_3C;
        if (lbl_3_bss_87000.banks[bank].items != NULL) {
            if (lbl_3_bss_87000.banks[bank].items[p->unk_1E + p->unk_1F] != NULL &&
                ((u8 *)lbl_3_bss_87000.banks[bank].data)[p->unk_1E + p->unk_1F] != 0) {
                Obj_3_bss_7EDD8 *r;
                u8 *recs;
                EditSetup e;
                fn_1_A2D84(0xA9010100);
                r = &lbl_3_bss_7EDD8;
                e.slots = (u8 *)&lbl_3_bss_87040;
                recs = e.slots + 0x20;
                e.slot = (Obj_3_bss_87040 *)(e.slots + r->unk_15 * 0x2060);
                e.state = 0x2000000;
                e.zero = 0;
                e.view = (ViewVecs *)&lbl_3_bss_9F640.unk_4;
                e.cam = &lbl_3_bss_9F690;
                r->unk_26 = 0x3FFF;
                r->unk_28 = e.zero;
                e.slot->unk_24 |= 0x80000000;
                e.slot->unk_28 = *(u32 *)&r->unk_26;
                e.slot->unk_2C = r->unk_2A;
                e.view->eye.z = 5.0f;
                e.view->eye.x = 0.0f;
                e.view->eye.y = 0.0f;
                e.view->at.x = 0.0f;
                e.view->at.y = 0.0f;
                e.view->at.z = 0.0f;
                e.slot->unk_60 = e.slot->unk_64 = 0.35f;
                *(ViewVecs *)&e.slot->unk_48 = *e.view;
                r->unk_10 = e.zero;
                r->unk_C = e.state;
                e.cam->unk_4 = 0.0f;
                e.cam->unk_8 = 0.0f;
                e.cam->unk_C = 5.0f;
                e.cam->unk_10 = 0.0f;
                e.cam->unk_14 = 0.0f;
                e.cam->unk_18 = 0.0f;
                *(s16 *)(recs + r->unk_15 * 0x2060) = r->unk_1C;
                fn_80008BA8((u8 *)e.slot + 0x80,
                            lbl_3_bss_87000.banks[p->unk_3C].items[p->unk_1E + p->unk_1F], 0x2000);
                fn_3_11994(r->unk_15, r->unk_1C, (u8 *)&lbl_3_bss_7EE40 + 0x20, recs);
            }
        }
    }
    if ((fn_3_106FC_array_read(lbl_1_bss_9F8.unk_8)[q->unk_14].unk_0 >> 9) & 1) {
        fn_1_A2D84(0xA9010200);
        /* Retail tests the flag with a register rotate. */
        if (!__rlwnm(lbl_3_bss_7EE40.unk_0, 2, 31, 31)) {
            lbl_3_bss_7EDD8.unk_C = 0x40000000;
        } else {
            lbl_3_bss_7EDD8.unk_C = 0x10000000;
        }
    }
}
#pragma opt_propagation reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_3_106FC */

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

/* fzgx:begin fn_3_10CB8 noprologue */
#include "types.h"

/* Layouts of the emb_paste_editor.c objects this function touches. */
typedef struct { s16 x, y, z; } Pos3;
typedef struct { f32 x, y, z; } Vec;
typedef struct { Vec a; Vec b; } View;
typedef struct {
    u32 unk_0;
    View view;
    u32 unk_1C;
    u32 unk_20;
} Cam;

typedef struct {
    u8 pad_0[0x4];
    u32 unk_4;
    Pos3 unk_8;
    u8 pad_E[0x1A];
    View unk_28;
    f32 unk_40;
    f32 unk_44;
    u8 pad_48[0x2018];
} PasteEntry;

typedef struct {
    u8 pad_0[0x7];
    u8 unk_7;
    u8 pad_8[0x18];
    PasteEntry unk_20[4];
    u8 pad_81A0[0x20];
} PasteSlot;

typedef struct {
    PasteSlot *unk_0;
    u8 pad_4[0x8];
} Obj7EDC0;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x2];
    s16 unk_A;
    u32 unk_C;
    u32 unk_10;
    u8 unk_14;
    u8 unk_15;
    u8 pad_16[0x2];
    u32 unk_18;
    s16 unk_1C;
    u8 unk_1E;
    u8 unk_1F;
    u8 unk_20;
    u8 unk_21;
    s16 unk_22;
    s16 unk_24;
    Pos3 unk_26;
    u32 unk_2C[4];
    u8 unk_3C;
    u8 pad_3D[0x9];
    u8 unk_46;
    u8 unk_47;
    s16 unk_48;
    u8 pad_4A[0x2];
    s16 unk_4C;
    s16 unk_4E;
    u8 unk_50;
    u8 unk_51;
    u8 pad_52[0x16];
} EditorState;

typedef struct { u16 unk_0; u8 pad_2[0x12]; } InputEntry;
typedef struct {
    union {
        InputEntry unk_0[1];
        struct { u8 pad8[8]; InputEntry unk_8[1]; };
    };
} InputState;

extern InputState lbl_1_bss_9F8;
extern PasteSlot lbl_3_bss_7EE40;
extern PasteSlot lbl_3_bss_87040;
extern void lbl_8006D5A4(Vec *a, Vec *b, Vec *out, f32 t);
extern void fn_1_A2D84(u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80008BA8(void *, void *, u32);
extern u32 camera_update_state(void *);
extern u32 fn_3_11A38(void);
extern void fzgx_touch(void *);

/* The TU's .bss from lbl_3_bss_7EDC0 to lbl_3_bss_9F6BC: retail addresses these off one base. */
Obj7EDC0 fzgx_obj_lbl_3_bss_7EDC0;
u8 fzgx_obj_lbl_3_bss_7EDCC[0xC];
EditorState fzgx_obj_lbl_3_bss_7EDD8;
u8 fzgx_pad_7EE40[0x20800];
Cam fzgx_obj_lbl_3_bss_9F640;
u8 fzgx_pad_9F664[0x8];
Cam fzgx_obj_lbl_3_bss_9F66C;
Cam fzgx_obj_lbl_3_bss_9F690;
u8 fzgx_pad_9F6B4[0x4];
f32 fzgx_obj_lbl_3_bss_9F6B8;
Pos3 fzgx_obj_lbl_3_bss_9F6BC;

/* Retail lbl_3_rodata_288 pool, in order: words this function does not read are tables. */
static const union { u32 w[13]; const u32 v[13]; } fzgx_pool_init_fzgx_pool_table_0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42480000, 0x43FA0000, 0x41F9999A, 0x439C0000, 0x42880000, 0x41A00000, 0x42C00000, 0x3FAE147B,
    0x43210000, 0x3F820000, 0x43010000, 0x41700000, 0x41200000
}};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_0(f32 *o) {
    fzgx_touch((void *)fzgx_pool_init_fzgx_pool_table_0.v);
    o[0] = 0.0f;
}
#pragma section code_type ".text"
static const union { u32 w[4]; const u32 v[4]; } fzgx_pool_init_fzgx_pool_table_38 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42AC0000, 0x3F000000, 0x430B0000, 0x42960000
}};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_38(f64 *d) {
    fzgx_touch((void *)fzgx_pool_init_fzgx_pool_table_38.v);
    d[0] = 4503601774854144.0;
}
#pragma section code_type ".text"
static const union { u32 w[27]; const u32 v[27]; } fzgx_pool_init_fzgx_pool_table_50 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFF0000, 0xFFFF0000, 0xFFFFFF00, 0x43390000, 0x43340000, 0x438A0000, 0x42E80000, 0x40E00000,
    0x434D0000, 0x41366666, 0x42200000, 0x47800000, 0x42700000, 0x42A00000, 0x43890000, 0x3F155555,
    0x3F0AAAAB, 0x3EEAAAAB, 0x43300000, 0x0, 0x43A00000, 0x43700000, 0x40A00000, 0x40C33333,
    0x3F4CCCCD, 0x43640000, 0x437C0000
}};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_50(f32 *o) {
    fzgx_touch((void *)fzgx_pool_init_fzgx_pool_table_50.v);
    o[0] = 0.1f;
}
#pragma section code_type ".text"
static const union { u32 w[12]; const u32 v[12]; } fzgx_pool_init_fzgx_pool_table_C0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xC1F00000, 0x443B8000, 0x42400000, 0x44250000, 0x42300000, 0x41C00000, 0x43970000, 0x428C0000,
    0x43A50000, 0x3FA28F5C, 0x43C30000, 0x439A0000
}};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_C0(f32 *o) {
    fzgx_touch((void *)fzgx_pool_init_fzgx_pool_table_C0.v);
    o[0] = 1.0f;
}
#pragma section code_type ".text"
static const union { u32 w[52]; const u32 v[52]; } fzgx_pool_init_fzgx_pool_table_F4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x43B80000, 0x43B40000, 0x41F00000, 0x3ECCCCCD, 0x47000000, 0x3F680000, 0x3F6C0000, 0x3F700000,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40A00000, 0xC1700000,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x40200000, 0xC1700000, 0x0, 0x40A00000, 0xC1700000, 0x0, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0xC1700000, 0x0, 0x0, 0x0, 0x40A00000, 0xC1700000, 0x0, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0xC1700000, 0x425C0000, 0x47AFC800, 0x42BE0000, 0x41880000, 0x43B10000, 0x439B0000, 0x43B68000,  /* fzgx-allow: A1 retail data bytes */
    0x430F0000, 0x419A6632, 0x3C23D70A, 0x3F400000, 0x43AF8000, 0x43C18000, 0x3F19999A, 0x3F333333,
    0x43AE0000, 0x43C00000, 0xFFFFFFFF, 0x43480000
}};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_F4(f32 *o) {
    fzgx_touch((void *)fzgx_pool_init_fzgx_pool_table_F4.v);
    o[0] = 0.05f;
    o[1] = 0.35f;
    o[2] = 0.0005f;
    o[3] = 0.002f;
    o[4] = 0.005f;
}
void fzgx_bss_primer(void) {
    fzgx_touch(&fzgx_obj_lbl_3_bss_7EDC0);
    fzgx_touch(fzgx_obj_lbl_3_bss_7EDCC);
    fzgx_touch(&fzgx_obj_lbl_3_bss_7EDD8);
    fzgx_touch(fzgx_pad_7EE40);
    fzgx_touch(&fzgx_obj_lbl_3_bss_9F640);
    fzgx_touch(fzgx_pad_9F664);
    fzgx_touch(&fzgx_obj_lbl_3_bss_9F66C);
    fzgx_touch(&fzgx_obj_lbl_3_bss_9F690);
    fzgx_touch(fzgx_pad_9F6B4);
    fzgx_touch(&fzgx_obj_lbl_3_bss_9F6B8);
    fzgx_touch(&fzgx_obj_lbl_3_bss_9F6BC);
}
#pragma section code_type ".text"

#define STATE fzgx_obj_lbl_3_bss_7EDD8
#define CAM fzgx_obj_lbl_3_bss_9F640
#define CAM_TARGET fzgx_obj_lbl_3_bss_9F66C
#define VIEW fzgx_obj_lbl_3_bss_9F690
#define BLEND fzgx_obj_lbl_3_bss_9F6B8
#define POS_TARGET fzgx_obj_lbl_3_bss_9F6BC

#define CLAMP(v, lo, hi) ((v) < (lo) ? (lo) : ((v) > (hi) ? (hi) : (v)))

static inline void count_active(void) {
    s16 i;
    s16 n = 0;
    for (i = 0; i < 4; i++) {
        if (lbl_3_bss_7EE40.unk_20[i].unk_4 & 0x80000000) {
            n++;
        }
    }
    lbl_3_bss_7EE40.unk_7 = n;
}

static inline void set_vec(Vec *v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline f32 clamp_blend(f32 *bound, f32 blend) {
    *bound = 0.0f;
    if (blend < *bound) {
        return *bound;
    }
    *bound = 1.0f;
    if (blend > *bound) {
        return *bound;
    }
    *bound = blend;
    return *bound;
}

#pragma fp_contract off
void fn_3_10CB8(void) {
    PasteEntry *cur;
    PasteEntry *bak;
    u8 active;
    s32 n;

    cur = &lbl_3_bss_7EE40.unk_20[STATE.unk_15];
    bak = &lbl_3_bss_87040.unk_20[STATE.unk_15];
    active = __rlwnm(cur->unk_4, 1, 31, 31);

    if (__rlwnm(STATE.unk_10, 8, 31, 31) && BLEND < 1.0f) {
        f32 r;
        STATE.unk_26.x = STATE.unk_26.x + BLEND * (POS_TARGET.x - STATE.unk_26.x);
        STATE.unk_26.y = STATE.unk_26.y + BLEND * (POS_TARGET.y - STATE.unk_26.y);
        CAM.view.a.z = CAM.view.a.z + BLEND * (CAM_TARGET.view.a.z - CAM.view.a.z);
        lbl_8006D5A4(&VIEW.view.a, &CAM_TARGET.view.a, &VIEW.view.a, BLEND);
        lbl_8006D5A4(&VIEW.view.b, &CAM_TARGET.view.b, &VIEW.view.b, BLEND);
        {
            volatile Cam *snapshot = &VIEW; /* Retail snapshot loads. */
            f32 bound, blend;
            set_vec(&CAM.view.a, snapshot->view.a.x, snapshot->view.a.y,
                    ((volatile Cam *)&CAM)->view.a.z);  /* fzgx-allow: S2 volatile view keeps the verified load order */
            set_vec(&CAM.view.b, snapshot->view.b.x, snapshot->view.b.y, snapshot->view.b.z);
            blend = 0.1f + BLEND;
            BLEND = clamp_blend(&bound, blend);
        }
        return;
    }

    if ((lbl_1_bss_9F8.unk_8[STATE.unk_14].unk_0 >> 4) & 1) {
        BLEND = 0.0f;
        STATE.unk_10 = STATE.unk_C;
        STATE.unk_C = 0x1000000;
        CAM_TARGET = CAM;
        POS_TARGET = STATE.unk_26;
        return;
    }

    fn_3_11A38();
    if ((lbl_1_bss_9F8.unk_8[STATE.unk_14].unk_0 >> 8) & 1) {
        fn_1_A2D84(0xA9010100);
        if (active) {
            fn_80008BEC(cur, 0, 0x2060);
            count_active();
        } else {
            cur->unk_4 = 0x80000000;
            fn_80008BA8(cur, bak, 0x2060);
            count_active();
        }
    }

    if ((lbl_1_bss_9F8.unk_8[STATE.unk_14].unk_0 >> 9) & 1) {
        PasteEntry *saved = &fzgx_obj_lbl_3_bss_7EDC0.unk_0[STATE.unk_46].unk_20[STATE.unk_15];
        fn_1_A2D84(0xA9010200);
        if (active) {
            fn_80008BEC(cur, 0, 0x2060);
            STATE.unk_2C[STATE.unk_15] = 0;
            fn_80008BA8(cur, bak, 0x2060);
            cur->unk_4 |= 0x80000000;
            STATE.unk_C = 0x40000000;
            STATE.unk_2C[STATE.unk_15] = 1;
            count_active();
        } else {
            fn_80008BEC(bak, 0, 0x2060);
            fn_80008BEC(cur, 0, 0x2060);
            if (saved->unk_4 & 0x80000000) {
                STATE.unk_2C[STATE.unk_15] = 1;
                STATE.unk_C = 0x40000000;
            } else {
                STATE.unk_2C[STATE.unk_15] = 0;
                STATE.unk_C = 0x8000000;
            }
            camera_update_state(&VIEW);
        }
    } else {
        s16 dir;
        EditorState *s = &STATE;
        PasteEntry *e = &lbl_3_bss_87040.unk_20[STATE.unk_15];
        f32 step;
        s16 held;
        step = 0.0f;
        held = s->unk_50;
        dir = 0;
        if ((lbl_1_bss_9F8.unk_0[STATE.unk_14].unk_0 >> 10) & 1) {
            dir = 1;
        }
        /* Retail reloads the input selector. */
        if ((lbl_1_bss_9F8.unk_0[*(volatile u8 *)&STATE.unk_14].unk_0 >> 11) & 1) {
            dir = -1;
        }
        if (dir) {
            n = (s16)held + 1;
            s->unk_50 = CLAMP(n, 0, 255);
        } else {
            s->unk_50 = 0;
        }
        step += 0.0005f * dir;
        if (s->unk_50 >= 15) {
            step += 0.002f * dir;
        }
        if (s->unk_50 >= 30) {
            step += 0.005f * dir;
        }
        e->unk_40 = CLAMP(e->unk_40 + step, 0.05f, 0.35f);
        e->unk_44 = CLAMP(e->unk_44 + step, 0.05f, 0.35f);
        if (!active) {
            PasteEntry *out = &lbl_3_bss_87040.unk_20[STATE.unk_15];
            out->unk_8 = STATE.unk_26;
            out->unk_28 = VIEW.view;
            camera_update_state(&CAM);
        }
    }
}
#pragma fp_contract reset
/* fzgx:end fn_3_10CB8 */

/* fzgx:begin fn_3_113AC noprologue */
#include "types.h"

/* One 0x2060-byte entry of a saved paste slot. */
typedef struct {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x2058];
} PasteEntry;

/* One saved paste slot (0x81C0 bytes). */
typedef struct {
    u8 pad_0[0x7];
    u8 unk_7;
    u8 pad_8[0x18];
    PasteEntry unk_20[4];
    u8 pad_81A0[0x20];
} PasteSlot;

typedef struct {
    PasteSlot *unk_0;
    u8 pad_4[0x8];
} EditorSlots;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x4];
    u32 unk_C;
    u8 pad_10[0x36];
    u8 unk_46;
    u8 unk_47;
    u8 pad_48[0x20];
} EditorSave;

typedef struct {
    u16 unk_0;
    u8 pad_2[0x6];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} PadInput;

typedef struct {
    u8 pad_0[0x6];
    s16 unk_6;
} PadSelect;

extern PadInput lbl_1_bss_9F8[];
extern PadSelect lbl_3_bss_F0;
extern PasteSlot lbl_3_bss_7EE40;
extern PasteSlot lbl_3_bss_87040;
extern u32 lbl_801A66B4;

extern s32 fn_1_1310E0(void);
extern s32 fn_1_B7F08(void);
extern u32 fn_3_12D4(void);
extern void fn_1_130EE8(u32, u32);
extern void fn_1_130F98(void);
extern void fn_1_131004(void);
extern void fn_1_131050(PasteSlot *, u32);
extern void fn_1_A2D84(u32);
extern void fn_3_11974(void);
extern void fn_3_131C(s32, const char *);
extern void fn_3_14C4(void *);
extern void fn_80008BA8(void *, void *, u32);

static EditorSlots lbl_3_bss_7EDC0;
static u8 lbl_3_bss_7EDCC__fzgx_offset_0[0x8];
static u8 lbl_3_bss_7EDCC__fzgx_offset_8;
static u8 lbl_3_bss_7EDCC__fzgx_offset_9;
static u8 lbl_3_bss_7EDCC__fzgx_offset_A;
static EditorSave lbl_3_bss_7EDD8;
static u8 fzgx_pool_fzgx_bss_gap_7EE40[0x208F4 - 0x80];
static u8 lbl_3_bss_9F690__fzgx_offset_24;
static u8 lbl_3_bss_9F690__fzgx_offset_28[0xC];
static u32 lbl_3_bss_9F690__fzgx_offset_34;

extern u8 lbl_3_data_1A44__fzgx_offset_0[];
extern u8 lbl_3_data_1A6C__fzgx_offset_0[];
extern u8 lbl_3_data_1A70__fzgx_offset_0[];
extern u8 lbl_3_data_1ACC__fzgx_offset_0[];
extern u8 lbl_3_data_1B24__fzgx_offset_0[];
extern u8 lbl_3_data_1BB4__fzgx_offset_0[];
extern u8 lbl_3_data_1C04__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_3_data_1A40[29] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFF0000, 0x53617669, 0x6E672063, 0x75727265, 0x6E742063, 0x68616E67, 0x65732E0A, 0x20497320,
    0x74686973, 0x204F4B3F, 0x20000000, 0x0, 0x8CBB5B82, 0xB082F15D, 0x8DDD5B82, 0xB482A25D,
    0x82CC95CF, 0x5B82D682, 0xF15D8D58, 0x5B82B182, 0xA45D82F0, 0x835A815B, 0x837582B5, 0x82DC82B7,
    0x81420A82, 0xE682EB82, 0xB582A282, 0xC582B782, 0xA93F0000  /* fzgx-allow: A1 retail data bytes */
};
static u32 fzgx_pool_data_lbl_3_data_1A40_74[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1A44__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A70__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_3_data_1ACC[52] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x50617374, 0x6564206F, 0x626A6563, 0x74732068, 0x61766520, 0x6368616E, 0x6765642E, 0xA205072,
    0x65706172, 0x696E6720, 0x746F2073, 0x61766520, 0x616E6420, 0x72657475, 0x726E2074, 0x6F207468,
    0x65204761, 0x72616765, 0x2E0A4973, 0x20746869, 0x73204F4B, 0x3F200000, 0x935C5B82, 0xCD5D82E8,
    0x95745B82, 0xC25D82AF, 0x82AA95CF, 0x5B82D682, 0xF15D8D58, 0x5B82B182, 0xA45D82B3, 0x82EA82C4,
    0x82A282DC, 0x82B78142, 0xA835A81, 0x5B837582, 0xB582C491, 0x4F5B82DC, 0x82A65D82, 0xCC89E65B,
    0x82AA5D96, 0xCA5B82DF, 0x82F15D82, 0xC996DF5B, 0x82E082C7, 0x5D82E882, 0xDC82B781, 0x420A82E6,
    0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x3F000000
};
static u32 fzgx_pool_data_lbl_3_data_1A40_15C[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1ACC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1B24__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_3_data_1BB4[38] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x52657475, 0x726E696E, 0x6720746F, 0x20746865, 0x20707265, 0x76696F75, 0x73207363, 0x7265656E,
    0xA207769, 0x74686F75, 0x74207361, 0x76696E67, 0x20637572, 0x72656E74, 0x20636861, 0x6E676573,
    0x2E0A2049, 0x73207468, 0x6973204F, 0x4B3F2000, 0x835A815B, 0x837582B9, 0x82B882C9, 0x914F5B82,
    0xDC82A65D, 0x82CC89E6, 0x5B82AA5D, 0x96CA5B82, 0xDF82F15D, 0x82C996DF, 0x5B82E082, 0xC75D82E8,
    0x82DC82B7, 0x81420A82, 0xE682EB82, 0xB582A282, 0xC582B782, 0xA93F0000  /* fzgx-allow: A1 retail data bytes */
};
static u32 fzgx_pool_data_lbl_3_data_1A40_20C[6] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1BB4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1C04__fzgx_offset_0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_3_data_1A40(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data/.bss objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_3_data_1A40;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_1A40_74;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_1ACC;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_1A40_15C;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_1BB4;
    s = *(u8 *)fzgx_pool_data_lbl_3_data_1A40_20C;
    s = *(u8 *)&lbl_3_bss_7EDC0;
    s = *(u8 *)lbl_3_bss_7EDCC__fzgx_offset_0;
    s = lbl_3_bss_7EDCC__fzgx_offset_8;
    s = lbl_3_bss_7EDCC__fzgx_offset_9;
    s = lbl_3_bss_7EDCC__fzgx_offset_A;
    s = *(u8 *)&lbl_3_bss_7EDD8;
    s = *(u8 *)fzgx_pool_fzgx_bss_gap_7EE40;
    s = lbl_3_bss_9F690__fzgx_offset_24;
    s = *(u8 *)lbl_3_bss_9F690__fzgx_offset_28;
    s = *(u8 *)&lbl_3_bss_9F690__fzgx_offset_34;
}
#pragma section code_type ".text"

#define SLOT_SIZE sizeof(PasteSlot)

void fn_3_113AC(void) {
    s32 idx;
    struct { s16 value; } count;
    struct { s16 value; } i;
    u8 j;
    u16 v;
    u16 *btn;

    if (fn_1_1310E0() != 0) {
        return;
    }
    if (lbl_3_bss_7EDCC__fzgx_offset_A != 0) {
        idx = lbl_3_bss_F0.unk_6;
        if (lbl_3_bss_7EDCC__fzgx_offset_A == 4) {
            lbl_3_bss_7EDCC__fzgx_offset_A = 0;
            lbl_3_bss_7EDD8.unk_C |= 0x800000;
            return;
        }
        if ((lbl_1_bss_9F8[idx].unk_10 & 1) || (lbl_1_bss_9F8[idx].unk_12 & 1)) {
            lbl_3_bss_9F690__fzgx_offset_24 = 0;
            fn_1_A2D84(0xA9011300);
        }
        if (((lbl_1_bss_9F8[idx].unk_10 >> 1) & 1) || ((lbl_1_bss_9F8[idx].unk_12 >> 1) & 1)) {
            lbl_3_bss_9F690__fzgx_offset_24 = 1;
            fn_1_A2D84(0xA9011300);
        }
        btn = &lbl_1_bss_9F8[idx].unk_8;
        if ((*btn >> 9) & 1) {
            lbl_3_bss_9F690__fzgx_offset_24 = 1;
        }
        v = *btn;
        if (((v >> 8) & 1) || ((v >> 9) & 1)) {
            if (lbl_3_bss_7EDCC__fzgx_offset_A == 1) {
                if (lbl_3_bss_9F690__fzgx_offset_24 == 0) {
                    fn_1_A2D84(0xA9010100);
                    lbl_3_bss_9F690__fzgx_offset_34 = 0x40000000;
                } else {
                    fn_1_A2D84(0xA9010200);
                    lbl_3_bss_7EDD8.unk_C = 0x40000000;
                }
                lbl_3_bss_7EDCC__fzgx_offset_A = 0;
            } else if (lbl_3_bss_7EDCC__fzgx_offset_A == 2) {
                if (lbl_3_bss_9F690__fzgx_offset_24 == 0) {
                    fn_1_A2D84(0xA9010100);
                    lbl_3_bss_9F690__fzgx_offset_34 = 0x800000;
                    lbl_3_bss_7EDCC__fzgx_offset_A = 0;
                } else {
                    fn_1_A2D84(0xA9010200);
                    lbl_3_bss_7EDCC__fzgx_offset_A = 3;
                }
            } else if (lbl_3_bss_7EDCC__fzgx_offset_A == 3) {
                if (lbl_3_bss_9F690__fzgx_offset_24 == 0) {
                    fn_1_A2D84(0xA9010100);
                    lbl_3_bss_7EDD8.unk_C |= 0x800000;
                } else {
                    fn_1_A2D84(0xA9010200);
                    lbl_3_bss_7EDD8.unk_C = 0x40000000;
                }
                lbl_3_bss_7EDCC__fzgx_offset_A = 0;
            }
        } else {
            fn_3_12D4();
            fn_3_14C4(&lbl_3_bss_9F690__fzgx_offset_24);
            if (lbl_3_bss_7EDCC__fzgx_offset_A == 1) {
                fn_3_131C(0xDC, ((const char **)fzgx_pool_data_lbl_3_data_1A40_74)[lbl_801A66B4]);
            } else if (lbl_3_bss_7EDCC__fzgx_offset_A == 2) {
                fn_3_131C(0xDC, ((const char **)fzgx_pool_data_lbl_3_data_1A40_15C)[lbl_801A66B4]);
            } else if (lbl_3_bss_7EDCC__fzgx_offset_A == 3) {
                fn_3_131C(0xDC, ((const char **)fzgx_pool_data_lbl_3_data_1A40_20C)[lbl_801A66B4]);
            }
        }
    } else if (lbl_3_bss_7EDCC__fzgx_offset_8 == 0) {
        fn_80008BA8(&lbl_3_bss_87040, &lbl_3_bss_7EDC0.unk_0[lbl_3_bss_7EDD8.unk_46], SLOT_SIZE);
        count.value = 0;
        for (i.value = count.value; i.value < 4; i.value++) {
            if (lbl_3_bss_7EE40.unk_20[i.value].unk_4 & 0x80000000) {
                count.value++;
            }
        }
        lbl_3_bss_7EDC0.unk_0[lbl_3_bss_7EDD8.unk_46].unk_7 = count.value;
        lbl_3_bss_7EE40.unk_7 = count.value;
        for (j = 0; j < 4; j++) {
            fn_80008BA8(&lbl_3_bss_7EDC0.unk_0[lbl_3_bss_7EDD8.unk_46].unk_20[j], &lbl_3_bss_7EE40.unk_20[j],
                        sizeof(PasteEntry));
        }
        fn_1_130EE8(lbl_3_bss_7EDD8.unk_0, lbl_3_bss_7EDD8.unk_4);
        fn_1_131050(lbl_3_bss_7EDC0.unk_0, lbl_3_bss_7EDD8.unk_47);
        lbl_3_bss_7EDCC__fzgx_offset_8 = 1;
    } else if (lbl_3_bss_7EDCC__fzgx_offset_9 != 0) {
        if (fn_1_B7F08() != 0) {
            fn_80008BA8(&lbl_3_bss_7EDC0.unk_0[lbl_3_bss_7EDD8.unk_46], &lbl_3_bss_87040, SLOT_SIZE);
        } else {
            fn_3_11974();
        }
        fn_1_131004();
        lbl_3_bss_7EDCC__fzgx_offset_8 = 0;
        lbl_3_bss_7EDCC__fzgx_offset_9 = 0;
        if (lbl_3_bss_9F690__fzgx_offset_34 == 0x800000) {
            lbl_3_bss_7EDD8.unk_C |= 0x800000;
        } else {
            lbl_3_bss_7EDD8.unk_C = lbl_3_bss_9F690__fzgx_offset_34;
        }
    } else {
        fn_1_130F98();
        lbl_3_bss_7EDCC__fzgx_offset_9 = 1;
    }
}
/* fzgx:end fn_3_113AC */

/* fzgx:begin fn_3_1180C */
struct fn_3_1180C_Fn3State {
    u8 pad0[4];
    u32 value;
    u8 pad8[2];
    s16 field_a;
    u8 pad_c[0x18];
    s16 mode;
};

void fn_3_1180C(void) {
    if ((*(struct fn_3_1180C_Fn3State *)&lbl_3_bss_7EDD8).mode == 0xf) {
        fn_1_4A00(0, 0xf, (*(struct fn_3_1180C_Fn3State *)&lbl_3_bss_7EDD8).value);
    } else if ((*(struct fn_3_1180C_Fn3State *)&lbl_3_bss_7EDD8).mode == 0) {
        fn_1_FDFF4();
        if ((*(s16 (*)[2])&lbl_3_data_1A40)[0] != -1) {
            fn_1_435C((*(struct fn_3_1180C_Fn3State *)&lbl_3_bss_7EDD8).value);
            fn_1_426C((*(struct fn_3_1180C_Fn3State *)&lbl_3_bss_7EDD8).field_a);
            (*(struct fn_3_1180C_Fn3State *)&lbl_3_bss_7EDD8).field_a = -1;
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
struct fn_3_11930_PasteEntry {
    u8 pad[0x2c];
    int active;
};

int fn_3_11930(void) {
    u8 i;
    u8 * base;

    for (i = 0; i < 4; i++) {
        struct fn_3_11930_PasteEntry *entry = (struct fn_3_11930_PasteEntry *)(((u8 *)(*(u16 (*)[52])&lbl_3_bss_7EDD8)) + i * 4);
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

/* fzgx:begin fn_3_11994 noprologue */
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

/* fzgx:begin fn_3_11A38 noprologue */
#include "types.h"
#include "psvec.h"

typedef struct { f32 x, y, z; } fn_3_11A38_Vec;
typedef struct { fn_3_11A38_Vec a; fn_3_11A38_Vec b; } fn_3_11A38_View;
typedef struct {
    u32 unk_0;
    fn_3_11A38_View view;
    u32 unk_1C;
    u32 unk_20;
} fn_3_11A38_Cam;

/* One controller's analog state (lbl_1_bss_BF0[port]). */
typedef struct {
    f32 stick_x;
    f32 stick_y;
    f32 substick_x;
    f32 substick_y;
    f32 trigger_l;
    f32 trigger_r;
    u8 pad_18[0x8];
} AnalogPad;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x2];
    s16 unk_A;
    u32 unk_C;
    u32 unk_10;
    u8 unk_14;
    u8 unk_15;
    u8 pad_16[0x2];
    u32 unk_18;
    s16 unk_1C;
    u8 unk_1E;
    u8 unk_1F;
    u8 unk_20;
    u8 unk_21;
    s16 unk_22;
    s16 unk_24;
    s16 unk_26;
    s16 unk_28;
    u16 unk_2A;
    u32 unk_2C[4];
    u8 unk_3C;
    u8 pad_3D[0x9];
    u8 unk_46;
    u8 unk_47;
    s16 unk_48;
    u8 pad_4A[0x2];
    s16 unk_4C;
    s16 unk_4E;
    u8 unk_50;
    u8 unk_51;
    u8 pad_52[0x16];
} fn_3_11A38_EditorState;

typedef struct fn_3_11A38_Customize fn_3_11A38_Customize;

extern AnalogPad lbl_1_bss_BF0[];
extern fn_3_11A38_EditorState lbl_3_bss_7EDD8;
extern fn_3_11A38_Customize *lbl_3_bss_7EDCC;
extern fn_3_11A38_Cam lbl_3_bss_9F640;
extern fn_3_11A38_Cam lbl_3_bss_9F690;

extern void fn_3_12E4C(fn_3_11A38_Customize *self, u8 index, fn_3_11A38_Vec *lo, fn_3_11A38_Vec *hi);
extern void lbl_8006D758(void);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void fn_80072558(void);
extern void lbl_8006E1B0(void *, void *);
extern void fn_8006E250(void *, void *);
extern void fn_80008BA8(void *, void *, u32);
extern f64 __fabs(f64);
extern void fzgx_touch(void *);

/* Retail lbl_3_rodata_288 pool up to this function's literals: words read only by other
 * functions are tables, the ones it reads are native literals. */
static const union { u32 w[12]; const u32 v[12]; } fzgx_pool_init_fzgx_pool_table_0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42480000, 0x43FA0000, 0x41F9999A, 0x439C0000, 0x42880000, 0x41A00000, 0x42C00000, 0x3FAE147B,
    0x43210000, 0x3F820000, 0x43010000, 0x41700000
}};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_0(f32 *o) {
    fzgx_touch((void *)fzgx_pool_init_fzgx_pool_table_0.v);
    o[0] = 10.0f;
    o[1] = 0.0f;
}
#pragma section code_type ".text"
static const union { u32 w[4]; const u32 v[4]; } fzgx_pool_init_fzgx_pool_table_38 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42AC0000, 0x3F000000, 0x430B0000, 0x42960000
}};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_38(f64 *d) {
    fzgx_touch((void *)fzgx_pool_init_fzgx_pool_table_38.v);
    d[0] = 4503601774854144.0;
}
#pragma section code_type ".text"
static const union { u32 w[7]; const u32 v[7]; } fzgx_pool_init_fzgx_pool_table_50 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFF0000, 0xFFFF0000, 0xFFFFFF00, 0x43390000, 0x43340000, 0x438A0000, 0x42E80000
}};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_50(f32 *o) {
    fzgx_touch((void *)fzgx_pool_init_fzgx_pool_table_50.v);
    o[0] = 7.0f;
}
#pragma section code_type ".text"
static const union { u32 w[14]; const u32 v[14]; } fzgx_pool_init_fzgx_pool_table_70 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x434D0000, 0x41366666, 0x42200000, 0x47800000, 0x42700000, 0x42A00000, 0x43890000, 0x3F155555,
    0x3F0AAAAB, 0x3EEAAAAB, 0x43300000, 0x0, 0x43A00000, 0x43700000
}};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_70(f32 *o) {
    fzgx_touch((void *)fzgx_pool_init_fzgx_pool_table_70.v);
    o[0] = 5.0f;
}
#pragma section code_type ".text"
static const union { u32 w[4]; const u32 v[4]; } fzgx_pool_init_fzgx_pool_table_AC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x40C33333, 0x3F4CCCCD, 0x43640000, 0x437C0000
}};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_AC(f32 *o) {
    fzgx_touch((void *)fzgx_pool_init_fzgx_pool_table_AC.v);
    o[0] = 0.1f;
}
#pragma section code_type ".text"
static const union { u32 w[55]; const u32 v[55]; } fzgx_pool_init_fzgx_pool_table_C0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xC1F00000, 0x443B8000, 0x42400000, 0x44250000, 0x42300000, 0x41C00000, 0x43970000, 0x428C0000,
    0x43A50000, 0x3FA28F5C, 0x43C30000, 0x439A0000, 0x3F800000,
    0x43B80000, 0x43B40000, 0x41F00000, 0x3ECCCCCD, 0x47000000, 0x3F680000, 0x3F6C0000, 0x3F700000,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40A00000, 0xC1700000,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x40200000, 0xC1700000, 0x0, 0x40A00000, 0xC1700000, 0x0, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0xC1700000, 0x0, 0x0, 0x0, 0x40A00000, 0xC1700000, 0x0, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0xC1700000, 0x425C0000, 0x47AFC800, 0x42BE0000, 0x41880000, 0x43B10000, 0x439B0000, 0x43B68000,  /* fzgx-allow: A1 retail data bytes */
    0x430F0000, 0x419A6632
}};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_C0(f32 *o) {
    fzgx_touch((void *)fzgx_pool_init_fzgx_pool_table_C0.v);
    o[0] = 0.01f;
}
#pragma section code_type ".text"
static const union { u32 w[9]; const u32 v[9]; } fzgx_pool_init_fzgx_pool_table_1A0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F400000, 0x43AF8000, 0x43C18000, 0x3F19999A, 0x3F333333, 0x43AE0000, 0x43C00000, 0xFFFFFFFF,
    0x43480000
}};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_1A0(f32 *o) {
    fzgx_touch((void *)fzgx_pool_init_fzgx_pool_table_1A0.v);
    o[0] = 0.05f;
}
#pragma section code_type ".text"
static const union { u32 w[4]; const u32 v[4]; } fzgx_pool_init_fzgx_pool_table_1C8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3EB33333, 0x3A03126F, 0x3B03126F, 0x3BA3D70A
}};
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_1C8(f32 *o) {
    fzgx_touch((void *)fzgx_pool_init_fzgx_pool_table_1C8.v);
}
#pragma section code_type ".text"


#define STATE lbl_3_bss_7EDD8
#define CAM lbl_3_bss_9F640
#define VIEW lbl_3_bss_9F690

#define CLAMP(v, lo, hi) ((v) < (lo) ? (lo) : ((v) > (hi) ? (hi) : (v)))

static inline void set_vec(fn_3_11A38_Vec *v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

#pragma fp_contract off
#pragma opt_dead_assignments off
void fn_3_11A38(void) {
    fn_3_11A38_Vec hi;
    fn_3_11A38_Vec lo;
    fn_3_11A38_Vec pos;
    fn_3_11A38_Vec move;
    f32 stick_y;
    f32 stick_x;
    f32 yaw;
    f32 pitch;
    f32 trigger;
    f32 rate;
    f32 speed;

    stick_x = lbl_1_bss_BF0[STATE.unk_14].stick_x;
    stick_y = lbl_1_bss_BF0[STATE.unk_14].stick_y;
    yaw = 0.0f;
    pitch = 0.0f;

    if (__fabs(stick_y) >= 0.75) {
        if (STATE.unk_4E > 40) {
            pitch = 256.0f * stick_y;
        } else {
            pitch = 128.0f * stick_y;
        }
        STATE.unk_4E++;
    } else {
        STATE.unk_4E = 0;
    }

    if (__fabs(stick_x) >= 0.75) {
        if (STATE.unk_4C > 40) {
            yaw = 512.0f * stick_x;
        } else {
            yaw = 256.0f * stick_x;
        }
        STATE.unk_4C++;
    } else {
        STATE.unk_4C = 0;
    }

    STATE.unk_26 = CLAMP(STATE.unk_26 + pitch, 2048.0f, 16383.0f);
    STATE.unk_28 = STATE.unk_28 + yaw;

    trigger = lbl_1_bss_BF0[STATE.unk_14].trigger_l - lbl_1_bss_BF0[STATE.unk_14].trigger_r;
    rate = 0.0f;
    if (trigger != 0.0f) {
        s32 n = STATE.unk_51 + 1;
        STATE.unk_51 = CLAMP(n, 0, 255);
    } else {
        STATE.unk_51 = 0;
    }
    rate += 0.1f;

    if (__rlwnm(STATE.unk_C, 7, 31, 31)) {
        CAM.view.a.z = CLAMP(CAM.view.a.z + trigger * rate, 4.5f, 7.0f);
    } else if (__rlwnm(STATE.unk_C, 8, 31, 31)) {
        CAM.view.a.z = CLAMP(CAM.view.a.z + trigger * rate, 4.5f, 10.0f);
    }

    move.z = move.y = move.x = speed = 0.0f;
    if (__fabs(lbl_1_bss_BF0[STATE.unk_14].substick_x) <= 0.1f &&
        __fabs(lbl_1_bss_BF0[STATE.unk_14].substick_y) <= 0.1f) {
        STATE.unk_48 = 0;
    } else {
        STATE.unk_48++;
    }
    if (STATE.unk_48) {
        if (STATE.unk_48 > 40) {
            speed = 0.05f;
        } else if (STATE.unk_48 > 20) {
            speed = 0.025f;
        } else {
            speed = 0.01f;
        }
    }
    if (__fabs(lbl_1_bss_BF0[STATE.unk_14].substick_x) >= 0.5) {
        move.x = lbl_1_bss_BF0[STATE.unk_14].substick_x;
    }
    if (__fabs(lbl_1_bss_BF0[STATE.unk_14].substick_y) >= 0.5) {
        move.y = lbl_1_bss_BF0[STATE.unk_14].substick_y;
    }
    psvec_scale_add(&VIEW.view.b, &move, speed, &pos);

    lbl_8006D758();
    mathutil_mtxA_rotate_y(STATE.unk_28);
    mathutil_mtxA_rotate_x(STATE.unk_26);
    fn_80072558();
    lbl_8006E1B0(&pos, &pos);
    fn_3_12E4C(lbl_3_bss_7EDCC, STATE.unk_1C, &lo, &hi);
    set_vec(&pos, CLAMP(pos.x, lo.x, hi.x), CLAMP(pos.y, lo.y, hi.y), CLAMP(pos.z, lo.z, hi.z));
    fn_8006E250(&pos, &pos);
    pos.z = 0.0f;
    fn_80008BA8(&CAM.view.b, &pos, sizeof(fn_3_11A38_Vec));
    fn_80008BA8(&VIEW.view.b, &pos, sizeof(fn_3_11A38_Vec));
    {
        f32 eye_z = CAM.view.a.z;
        f32 dist = 5.0f;
        set_vec(&CAM.view.a, pos.x, pos.y, eye_z);
        set_vec(&VIEW.view.a, pos.x, pos.y, dist);
    }
}
#pragma fp_contract reset
#pragma opt_dead_assignments reset
/* fzgx:end fn_3_11A38 */

/* fzgx:begin fn_3_11F60 */
struct fn_3_11F60_Fn3State {
    u32 value0;
    u32 value1;
};

void fn_3_11F60(u32 value0, u32 value1) {
    (*(struct fn_3_11F60_Fn3State *)&lbl_3_bss_7EDD8).value1 = value1;
    (*(struct fn_3_11F60_Fn3State *)&lbl_3_bss_7EDD8).value0 = value0;
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

/* fzgx:begin fn_3_11FD0 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/emb_memcard.h"


extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;
extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_C1394(u32 *arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, u32 arg3);
extern u32 lbl_3_rodata_288[60];
extern void lbl_8006DCA4(void);
extern void lbl_8006E1D8(struct Vec3 *, f32, f32, f32);
extern void fn_1_7BCCC(struct Vec3 *);
extern void fn_80035680(struct GXLightObj *, f32, f32, f32);
extern void fn_80035690(struct GXLightObj *, f32, f32, f32);
extern void fn_80035420(struct GXLightObj *, f32, int);
extern void fn_800356AC(struct GXLightObj *, u32 *);
extern void GXInitLightDistAttn(struct GXLightObj *, f32, f32, int);
extern void fn_1_7BB80(struct GXLightObj *, int);
extern void fn_1_7BD6C(int);
extern void fn_80074CF4(f32, f32, f32);

u32 fn_3_11FD0(u32 index, u32 value) {
    return ((u32 *)(lbl_3_data_2F78 + (__cntlzw(value) * 24)))[index];
}
/* fzgx:end fn_3_11FD0 */

/* fzgx:begin fn_3_11FF0 noprologue */
#include "types.h"
#include "rel/main_rel/game.h"

typedef struct Vec3 { f32 x, y, z; } Vec3;
typedef struct Triple { u16 a, b, c; } Triple;

typedef struct Part {
    u32 flags;
    u8 pad_4;
    u8 unk_5;
    u8 pad_6[2];
    u8 unk_8;
    u8 pad_9[0x17];
    s16 unk_20;
    u8 pad_22[6];
    Triple unk_28;
    u8 pad_2E[2];
    f32 unk_30;
    f32 unk_34;
    u8 pad_38[0x2028];
} Part;

typedef struct PartSel {
    u8 id;
    u8 pad[7];
} PartSel;

typedef struct Entry {
    Part parts[4];
    u8 pad_8180[0x20];
    u8 kind;
    u8 pad_81A1[3];
    PartSel sel[3];
    u8 pad_81BC[4];
} Entry;

typedef struct Model {
    u8 pad_0[0x390];
    u32 unk_390;
    u8 pad_394[0xC];
    void *unk_3A0;
    void *unk_3A4;
} Model;

typedef struct EditorState {
    u32 unk_0;
    u32 unk_4;
    u16 unk_8;
    s16 unk_A;
    u32 unk_C;
    u32 unk_10;
    u8 unk_14;
    u8 unk_15;
    u8 pad_16[2];
    u32 unk_18;
    u16 unk_1C;
    u8 unk_1E;
    u8 unk_1F;
    u8 unk_20;
    u8 unk_21;
    u16 unk_22;
    s16 unk_24;
    Triple unk_26;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u8 unk_3C;
    u8 pad_3D[3];
    u32 unk_40;
    s16 unk_44;
    u8 unk_46;
    u8 unk_47;
    u16 unk_48;
    u16 unk_4A;
    u16 unk_4C;
    u16 unk_4E;
    u8 unk_50;
    u8 unk_51;
    u8 pad_52[0x16];
} EditorState;

typedef struct Bank {
    u16 unk_0;
    u8 pad_2[2];
    void *unk_4;
    u32 *unk_8;
} Bank;

typedef struct Slots {
    Bank banks[2];
    u16 count;
    u8 pad_1A[2];
    u8 *flags;
    void **items;
    u8 pad_24[0x1C];
} Slots;

typedef struct Work {
    Model *model;
    u8 unk_4;
    u8 pad_5[7];
    u32 unk_C;
    u8 pad_10[0x10410];
    u32 unk_10420;
    void (*unk_10424)(void);
    void (*unk_10428)(void);
    void (*unk_1042C)(void);
    u8 pad_10430[0x10];
} Work;

typedef struct Camera {
    u32 unk_0;
    Vec3 unk_4;
    Vec3 unk_10;
    u8 pad_1C[4];
    u16 unk_20;
    u8 pad_22[2];
} Camera;

typedef struct Camera2 {
    u32 unk_0;
    Vec3 unk_4;
    Vec3 unk_10;
    u8 pad_1C[4];
    u16 unk_20;
    u8 pad_22[0x20B6];
} Camera2;

/* .data of emb_paste_editor.c, from lbl_3_data_1A40 */
typedef struct DataSec {
    u8 pad_0[0x189C];
    char file[0x2C];
    void *tbl1[11];
    void *tbl2[6];
    u8 unk_190C[4];
} DataSec;

typedef struct LoadResult { u8 bytes[0x5C]; } LoadResult;

typedef struct Parts {
    s16 a, b, c, pad;
    s32 flag, pad_C;
} Parts;

/* .bss of emb_paste_editor.c: static objects are addressed off the section base */
static Entry *lbl_3_bss_7EDC0;
#define s_entries lbl_3_bss_7EDC0
static u32 fzgx_pool_s_unk_7EDC4;
static void *lbl_3_bss_7EDC0__fzgx_offset_8;          /* 0x7EDC8 */
static Model *lbl_3_bss_7EDCC__fzgx_offset_0;            /* lbl_3_bss_7EDCC */
static void *lbl_3_bss_7EDCC__fzgx_offset_4;
static u16 fzgx_pool_s_unk_7EDD4;
static u8 lbl_3_bss_7EDCC__fzgx_offset_A;
static EditorState lbl_3_bss_7EDD8;
Entry lbl_3_bss_7EE40;
static Slots lbl_3_bss_87000;
static Entry lbl_3_bss_87040;
static Work lbl_3_bss_8F200;
static Camera lbl_3_bss_9F640;
static u8 fzgx_pool_lbl_3_bss_9F664[0x2C];
static Camera2 lbl_3_bss_9F690;

extern u32 lbl_3_rodata_288[60];
extern u16 lbl_3_data_1A40;
extern u32 lbl_801A6410[];
extern u32 lbl_801A66B4[];
extern void fn_3_E6F8(void);
extern void fn_1_FD324(void);
extern void fn_1_FDC00(void);
extern void fn_1_FD27C(void);
extern void fn_3_12FD4(u32, u32, u32, f32 *, f32 *);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_A176C(void *, u32);
extern void fn_80008BA8(void *, const void *, u32);
extern u32 camera_update_state(void *);
extern u32 fn_1_435C(u32);
extern s32 fn_1_3F8C(void *, void (*)(void), u32, u32);
extern void *fn_1_45D0(u32, u32, const char *, s32);
extern void fn_80008BEC(void *, int, u32);
extern s32 fn_1_80CC4(u32, u32, u32, void *);
extern void fn_1_14D8DC(void *, void *, s16);
extern void *fn_1_7F254(void *, s32);
extern int fn_1_45730(void *, LoadResult *);
extern u32 fn_1_45B2C(LoadResult *);
extern void fn_1_458A0(LoadResult *, void *, u32, u32);
extern void fn_1_45850(LoadResult *);
extern s32 fn_1_F7BE4(s16);

#pragma section code_type ".fzgxpool"
/* the TU's .rodata literal pool, in retail order, ahead of this function's initializers */

#pragma section code_type ".text"

#define CUR (s_entries[lbl_3_bss_7EDD8.unk_46])
#define HEAP (lbl_801A6410[0])

extern u8 fn_3_10260__fzgx_offset_0[];
extern u8 fn_3_104C4__fzgx_offset_0[];
extern u8 fn_3_106FC__fzgx_offset_0[];
extern u8 fn_3_10B68__fzgx_offset_0[];
extern u8 fn_3_10CB8__fzgx_offset_0[];
extern u8 fn_3_113AC__fzgx_offset_0[];
extern u8 fn_3_1180C__fzgx_offset_0[];
extern u8 fn_3_118BC__fzgx_offset_0[];
extern u8 fn_3_F984__fzgx_offset_0[];
extern u8 fn_3_FD30__fzgx_offset_0[];
extern u8 lbl_3_data_1A44__fzgx_offset_0[];
extern u8 lbl_3_data_1A6C__fzgx_offset_0[];
extern u8 lbl_3_data_1A70__fzgx_offset_0[];
extern u8 lbl_3_data_1ACC__fzgx_offset_0[];
extern u8 lbl_3_data_1B24__fzgx_offset_0[];
extern u8 lbl_3_data_1BB4__fzgx_offset_0[];
extern u8 lbl_3_data_1C04__fzgx_offset_0[];
extern u8 lbl_3_data_1C64__fzgx_offset_0[];
extern u8 lbl_3_data_1C70__fzgx_offset_0[];
extern u8 lbl_3_data_1C98__fzgx_offset_0[];
extern u8 lbl_3_data_1CA8__fzgx_offset_0[];
extern u8 lbl_3_data_1CD4__fzgx_offset_0[];
extern u8 lbl_3_data_1CE4__fzgx_offset_0[];
extern u8 lbl_3_data_1D10__fzgx_offset_0[];
extern u8 lbl_3_data_1D24__fzgx_offset_0[];
extern u8 lbl_3_data_1D5C__fzgx_offset_0[];
extern u8 lbl_3_data_1D74__fzgx_offset_0[];
extern u8 lbl_3_data_1DAC__fzgx_offset_0[];
extern u8 lbl_3_data_1DC4__fzgx_offset_0[];
extern u8 lbl_3_data_1DFC__fzgx_offset_0[];
extern u8 lbl_3_data_1E14__fzgx_offset_0[];
extern u8 lbl_3_data_1E50__fzgx_offset_0[];
extern u8 lbl_3_data_1E68__fzgx_offset_0[];
extern u8 lbl_3_data_1EA4__fzgx_offset_0[];
extern u8 lbl_3_data_1EA8__fzgx_offset_0[];
extern u8 lbl_3_data_1EB0__fzgx_offset_0[];
extern u8 lbl_3_data_1EB4__fzgx_offset_0[];
extern u8 lbl_3_data_2DCC__fzgx_offset_0[];
extern u8 lbl_3_data_2DE0__fzgx_offset_0[];
extern u8 lbl_3_data_2DFC__fzgx_offset_0[];
extern u8 lbl_3_data_2E24__fzgx_offset_0[];
extern u8 lbl_3_data_2E54__fzgx_offset_0[];
extern u8 lbl_3_data_2E64__fzgx_offset_0[];
extern u8 lbl_3_data_2E80__fzgx_offset_0[];
extern u8 lbl_3_data_2E90__fzgx_offset_0[];
extern u8 lbl_3_data_2EAC__fzgx_offset_0[];
extern u8 lbl_3_data_2EC0__fzgx_offset_0[];
extern u8 lbl_3_data_2EE0__fzgx_offset_0[];
extern u8 lbl_3_data_2EF4__fzgx_offset_0[];
extern u8 lbl_3_data_2F04__fzgx_offset_0[];
extern u8 lbl_3_data_2F20__fzgx_offset_0[];
extern u8 lbl_3_data_2F3C__fzgx_offset_0[];
extern u8 lbl_3_data_2F50__fzgx_offset_0[];
extern u8 lbl_3_data_2F64__fzgx_offset_0[];
extern u8 lbl_3_data_3068__fzgx_offset_0[];
extern u8 lbl_3_data_307C__fzgx_offset_0[];
extern u8 lbl_3_data_309C__fzgx_offset_0[];
extern u8 lbl_3_data_30AC__fzgx_offset_0[];
extern u8 lbl_3_data_30C8__fzgx_offset_0[];
extern u8 lbl_3_data_30D4__fzgx_offset_0[];
extern u8 lbl_3_data_30E0__fzgx_offset_0[];
extern u8 lbl_3_data_30EC__fzgx_offset_0[];
extern u8 lbl_3_data_30FC__fzgx_offset_0[];
extern u8 lbl_3_data_3120__fzgx_offset_0[];
extern u8 lbl_3_data_315C__fzgx_offset_0[];
extern u8 lbl_3_data_3168__fzgx_offset_0[];
extern u8 lbl_3_data_3174__fzgx_offset_0[];
extern u8 lbl_3_data_3180__fzgx_offset_0[];
extern u8 lbl_3_data_32F4__fzgx_offset_0[];
extern u8 lbl_3_data_3320__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_3_data_1A40_gap_0[1575] = {0xFFFF0000, 0x53617669, 0x6E672063, 0x75727265, 0x6E742063, 0x68616E67, 0x65732E0A, 0x20497320, 0x74686973, 0x204F4B3F, 0x20000000, 0x00000000, 0x8CBB5B82, 0xB082F15D, 0x8DDD5B82, 0xB482A25D, 0x82CC95CF, 0x5B82D682, 0xF15D8D58, 0x5B82B182, 0xA45D82F0, 0x835A815B, 0x837582B5, 0x82DC82B7, 0x81420A82, 0xE682EB82, 0xB582A282, 0xC582B782, 0xA93F0000, (u32)lbl_3_data_1A44__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A70__fzgx_offset_0, 0x50617374, 0x6564206F, 0x626A6563, 0x74732068, 0x61766520, 0x6368616E, 0x6765642E, 0x0A205072, 0x65706172, 0x696E6720, 0x746F2073, 0x61766520, 0x616E6420, 0x72657475, 0x726E2074, 0x6F207468, 0x65204761, 0x72616765, 0x2E0A4973, 0x20746869, 0x73204F4B, 0x3F200000, 0x935C5B82, 0xCD5D82E8, 0x95745B82, 0xC25D82AF, 0x82AA95CF, 0x5B82D682, 0xF15D8D58, 0x5B82B182, 0xA45D82B3, 0x82EA82C4, 0x82A282DC, 0x82B78142, 0x0A835A81, 0x5B837582, 0xB582C491, 0x4F5B82DC, 0x82A65D82, 0xCC89E65B, 0x82AA5D96, 0xCA5B82DF, 0x82F15D82, 0xC996DF5B, 0x82E082C7, 0x5D82E882, 0xDC82B781, 0x420A82E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x3F000000, (u32)lbl_3_data_1ACC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1B24__fzgx_offset_0, 0x52657475, 0x726E696E, 0x6720746F, 0x20746865, 0x20707265, 0x76696F75, 0x73207363, 0x7265656E, 0x0A207769, 0x74686F75, 0x74207361, 0x76696E67, 0x20637572, 0x72656E74, 0x20636861, 0x6E676573, 0x2E0A2049, 0x73207468, 0x6973204F, 0x4B3F2000, 0x835A815B, 0x837582B9, 0x82B882C9, 0x914F5B82, 0xDC82A65D, 0x82CC89E6, 0x5B82AA5D, 0x96CA5B82, 0xDF82F15D, 0x82C996DF, 0x5B82E082, 0xC75D82E8, 0x82DC82B7, 0x81420A82, 0xE682EB82, 0xB582A282, 0xC582B782, 0xA93F0000, (u32)lbl_3_data_1BB4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1C04__fzgx_offset_0, 0x426F6479, 0x20506172, 0x74730000, 0x837B8366, 0x83428370, 0x815B8363, 0x00000000, (u32)lbl_3_data_1C64__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1C70__fzgx_offset_0, 0x436F636B, 0x70697420, 0x50617274, 0x73000000, 0x8352834E, 0x83728362, 0x83678370, 0x815B8363, 0x00000000, (u32)lbl_3_data_1C98__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1CA8__fzgx_offset_0, 0x426F6F73, 0x74657220, 0x50617274, 0x73000000, 0x8375815B, 0x8358835E, 0x815B8370, 0x815B8363, 0x00000000, (u32)lbl_3_data_1CD4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1CE4__fzgx_offset_0, 0x46697265, 0x20537469, 0x6E677261, 0x7920426F, 0x64790000, 0x83748340, 0x83438341, 0x83588365, 0x83428393, 0x834F838C, 0x834382CC, 0x837B8366, 0x83420000, (u32)lbl_3_data_1D10__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1D24__fzgx_offset_0, 0x46697265, 0x20537469, 0x6E677261, 0x79205061, 0x72747320, 0x31000000, 0x83748340, 0x83438341, 0x83588365, 0x83428393, 0x834F838C, 0x834382CC, 0x8370815B, 0x83630000, (u32)lbl_3_data_1D5C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1D74__fzgx_offset_0, 0x5261696E, 0x626F7720, 0x50686F65, 0x6E697820, 0x426F6479, 0x00000000, 0x838C8343, 0x8393837B, 0x815B8374, 0x8346836A, 0x8362834E, 0x835882CC, 0x837B8366, 0x83420000, (u32)lbl_3_data_1DAC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1DC4__fzgx_offset_0, 0x5261696E, 0x626F7720, 0x50686F65, 0x6E697820, 0x50617274, 0x73203100, 0x838C8343, 0x8393837B, 0x815B8374, 0x8346836A, 0x8362834E, 0x835882CC, 0x8370815B, 0x83638250, 0x00000000, (u32)lbl_3_data_1DFC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1E14__fzgx_offset_0, 0x5261696E, 0x626F7720, 0x50686F65, 0x6E697820, 0x50617274, 0x73203200, 0x838C8343, 0x8393837B, 0x815B8374, 0x8346836A, 0x8362834E, 0x835882CC, 0x8370815B, 0x83638251, 0x00000000, (u32)lbl_3_data_1E50__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1E68__fzgx_offset_0, 0x4E4F0000, 0x82A282A2, 0x82A60000, 0x59455300, 0x82CD82A2, 0x00000000, (u32)lbl_3_data_1EA4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1EA8__fzgx_offset_0, (u32)lbl_3_data_1EB0__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1EB4__fzgx_offset_0, 0x3F000000, 0x3ECCCCCD, 0xC0200000, 0xBF800000, 0xC0400000, 0x40200000, 0x40000000, 0x40600000, 0x3F19999A, 0x3ECCCCCD, 0xBFCCCCCD, 0xBF4CCCCD, 0xC02CCCCD, 0x3FCCCCCD, 0x3FCCCCCD, 0x4019999A, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x3FCCCCCD, 0x402CCCCD, 0x3F000000, 0x3ED70A3D, 0xBFE66666, 0xBF4CCCCD, 0xC0400000, 0x3FE66666, 0x3FCCCCCD, 0x40400000, 0x3F000000, 0x3E800000, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666, 0x3FCCCCCD, 0x40400000, 0x3F19999A, 0x3ED70A3D, 0xC0200000, 0xBF4CCCCD, 0xC0266666, 0x40200000, 0x40000000, 0x40266666, 0x3F266666, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666, 0x40000000, 0x40266666, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666, 0x3FCCCCCD, 0x40266666, 0x3F000000, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666, 0x40000000, 0x40266666, 0x3F000000, 0x3F000000, 0xC0000000, 0xBF4CCCCD, 0xC0333333, 0x40000000, 0x400CCCCD, 0x40333333, 0x3F19999A, 0x3ECCCCCD, 0xC0000000, 0xBF4CCCCD, 0xC0333333, 0x40000000, 0x400CCCCD, 0x40333333, 0x3F000000, 0x3EE66666, 0xC0000000, 0xBF4CCCCD, 0xC00CCCCD, 0x40000000, 0x40000000, 0x40333333, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666, 0x40200000, 0x404CCCCD, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666, 0x3FE66666, 0x40333333, 0x3F19999A, 0x3EB33333, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666, 0x3FE66666, 0x40333333, 0x3F19999A, 0x3EB33333, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666, 0x3FCCCCCD, 0x40333333, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x3FCCCCCD, 0x402CCCCD, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x3FCCCCCD, 0x40400000, 0x3F000000, 0x3EC28F5C, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x40133333, 0x40400000, 0x3F266666, 0x3EF5C28F, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x400CCCCD, 0x40400000, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x400CCCCD, 0x40400000, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x40000000, 0x40400000, 0x3F000000, 0x3E0F5C29, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x3FE66666, 0x40400000, 0x3F19999A, 0x3F000000, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000, 0x4019999A, 0x40400000, 0x3F000000, 0x3E4CCCCD, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000, 0x40000000, 0x40400000, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000, 0x40000000, 0x402CCCCD, 0x3F000000, 0x3EB33333, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000, 0x40000000, 0x402CCCCD, 0x3F000000, 0x3EB33333, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000, 0x40000000, 0x402CCCCD, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000, 0x400CCCCD, 0x40400000, 0x3F19999A, 0x3E99999A, 0xC0133333, 0xBF4CCCCD, 0xC0533333, 0x40133333, 0x40333333, 0x40400000, 0x3F19999A, 0x3E99999A, 0xC0133333, 0xBF4CCCCD, 0xC0400000, 0x40133333, 0x40133333, 0x40400000, 0x3F000000, 0x3E19999A, 0xC0133333, 0xBF4CCCCD, 0xC0200000, 0x4019999A, 0x40133333, 0x40333333, 0x3F19999A, 0x3E4CCCCD, 0xBFF33333, 0xBF4CCCCD, 0xC0200000, 0x3FF33333, 0x40333333, 0x40533333, 0x3ECCCCCD, 0x3E19999A, 0xC0200000, 0xBF4CCCCD, 0xC039999A, 0x40200000, 0x40133333, 0x40533333, 0x3F000000, 0x3E4CCCCD, 0xC0200000, 0xBF4CCCCD, 0xC039999A, 0x40200000, 0x40133333, 0x40533333, 0x3F000000, 0x3E19999A, 0xBFCCCCCD, 0xBF4CCCCD, 0xBFE66666, 0x3FCCCCCD, 0x3FE66666, 0x40000000, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC0200000, 0x40000000, 0x40000000, 0x40200000, 0x3F000000, 0x3EB33333, 0xC0000000, 0xBF4CCCCD, 0xC0133333, 0x40000000, 0x400CCCCD, 0x4019999A, 0x3F000000, 0x3F000000, 0xC0000000, 0xBF4CCCCD, 0xC0400000, 0x40000000, 0x400CCCCD, 0x404CCCCD, 0x3F000000, 0x3ECCCCCD, 0xC0000000, 0xBF4CCCCD, 0xC039999A, 0x40000000, 0x40200000, 0x40333333, 0x3F266666, 0x3E99999A, 0xC0200000, 0xBF4CCCCD, 0xC0400000, 0x40200000, 0x400CCCCD, 0x40333333, 0x3F000000, 0x3F000000, 0xBF4CCCCD, 0xBF800000, 0xC0000000, 0x3FF33333, 0x3F4CCCCD, 0x3F800000, 0x3F000000, 0x3F000000, 0xBFF33333, 0xBF800000, 0xC0000000, 0x3F4CCCCD, 0x3F4CCCCD, 0x3F800000, 0x3F000000, 0x3F000000, 0xBF000000, 0xBF4CCCCD, 0xBFE66666, 0x3F000000, 0x3FE66666, 0x3F666666, 0x3F000000, 0x3EAE147B, 0xC0133333, 0xBF333333, 0xC0000000, 0x40133333, 0x3FF33333, 0x3FC00000, 0x3F000000, 0x3ECCCCCD, 0xC0266666, 0xBF333333, 0xBFC00000, 0x40266666, 0x3FA66666, 0x40133333, 0x3F000000, 0x3F000000, 0xC0133333, 0xBF800000, 0xC0133333, 0x40133333, 0x40000000, 0x40133333, 0x3F000000, 0x3F000000, 0xBFB33333, 0xBF800000, 0xC0133333, 0x3FB33333, 0x3FC00000, 0x40266666, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC0000000, 0x40000000, 0x3F99999A, 0x40266666, 0x3F000000, 0x3E99999A, 0xC0200000, 0xBF666666, 0xC00CCCCD, 0x40200000, 0x3FE66666, 0x40000000, 0x3F000000, 0x3E99999A, 0xC0066666, 0xBF8CCCCD, 0xBFB33333, 0x40066666, 0x40066666, 0x40200000, 0x3EE66666, 0x3F000000, 0xC0133333, 0xBF800000, 0xC0200000, 0x40133333, 0x40000000, 0x40200000, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC0133333, 0x40000000, 0x3FC00000, 0x402CCCCD, 0x3F000000, 0x3E4CCCCD, 0xC0333333, 0xBF000000, 0xBFE66666, 0x40266666, 0x3FC00000, 0x3FE66666, 0x3F000000, 0x3DCCCCCD, 0xC0333333, 0xBF4CCCCD, 0xBFD9999A, 0x40333333, 0x3FD9999A, 0x40133333, 0x3F000000, 0x3E800000, 0xC0000000, 0xBF4CCCCD, 0xC0200000, 0x40000000, 0x3FC00000, 0x40200000, 0x3F000000, 0x3E4CCCCD, 0xC0000000, 0xBF4CCCCD, 0xBFE66666, 0x3FE66666, 0x3FE66666, 0x40133333, 0x3F000000, 0x3E800000, 0xC0200000, 0xBF333333, 0xC0133333, 0x40200000, 0x40000000, 0x40333333, 0x3F000000, 0x3E800000, 0xC019999A, 0xBF666666, 0xC0333333, 0x4019999A, 0x3FCCCCCD, 0x40333333, 0x3F000000, 0x3E4CCCCD, 0xBFC00000, 0xBF99999A, 0xC019999A, 0x3FC00000, 0x40200000, 0x4019999A, 0x3F000000, 0x3E4CCCCD, 0xBFF33333, 0xBF333333, 0xC0000000, 0x3FF33333, 0x400CCCCD, 0x40800000, 0x3F000000, 0x3E4CCCCD, 0xC0066666, 0xBF333333, 0xC0000000, 0x40066666, 0x3FE66666, 0x40400000, 0x3F000000, 0x3DCCCCCD, 0xBFD9999A, 0xBF000000, 0xC019999A, 0x3FD9999A, 0x40200000, 0x40400000, 0x3F000000, 0x3EB851EC, 0xC0000000, 0xBF4CCCCD, 0xBFC00000, 0x40000000, 0x3FF33333, 0x40333333, 0x3F000000, 0x3E19999A, 0xC0000000, 0xBF4CCCCD, 0xC0200000, 0x40000000, 0x3FF33333, 0x400CCCCD, 0x3F000000, 0x3E4CCCCD, 0xC019999A, 0xBF666666, 0xC019999A, 0x4019999A, 0x40000000, 0x4019999A, 0x3F000000, 0x3E4CCCCD, 0xC00CCCCD, 0xBF800000, 0xBFE66666, 0x400CCCCD, 0x40000000, 0x402CCCCD, 0x3F000000, 0x3E19999A, 0xC0466666, 0xBF333333, 0xC00CCCCD, 0x40466666, 0x40000000, 0x4079999A, 0x3F000000, 0x3E99999A, 0xC0466666, 0xBF19999A, 0xC0000000, 0x40466666, 0x40000000, 0x40266666, 0x3F000000, 0x3ECCCCCD, 0xBFA66666, 0xBF333333, 0xBFB33333, 0x3FA66666, 0x3FC00000, 0x3FB33333, 0x3F4CCCCD, 0x3C23D70A, 0xBFA66666, 0xBF333333, 0xBFC00000, 0x3FA66666, 0x3FA66666, 0x3FC00000, 0x3F000000, 0x3F000000, 0xBFB33333, 0xBF666666, 0xC0000000, 0x3FB33333, 0x3FC00000, 0x40200000, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF800000, 0xBFC00000, 0x3FB33333, 0x3FC00000, 0x3FC00000, 0x3F000000, 0x3E99999A, 0xBFC00000, 0xBF4CCCCD, 0xBFC00000, 0x3FC00000, 0x3FCCCCCD, 0x3FC00000, 0x3F000000, 0x3E99999A, 0xBFA66666, 0xBECCCCCD, 0xBFC00000, 0x3FA66666, 0x3FA66666, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xC0066666, 0xBF4CCCCD, 0xBFA66666, 0x40066666, 0x3F8CCCCD, 0x3FC00000, 0x3F19999A, 0x3ECCCCCD, 0xBFC00000, 0xBF800000, 0xBFCCCCCD, 0x3FC00000, 0x3FC00000, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xC02CCCCD, 0xBF666666, 0xBFE66666, 0x402CCCCD, 0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xC0000000, 0xBF4CCCCD, 0xBFCCCCCD, 0x40000000, 0x3FC00000, 0x3FCCCCCD, 0x3F000000, 0x3DCCCCCD, 0xC0000000, 0xBF4CCCCD, 0xBFCCCCCD, 0x40000000, 0x40000000, 0x400CCCCD, 0x3F000000, 0x3E800000, 0xC019999A, 0xBF4CCCCD, 0xBFCCCCCD, 0x4019999A, 0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3EE66666, 0xBFD9999A, 0xBF666666, 0xBFD9999A, 0x3FD9999A, 0x3FCCCCCD, 0x40400000, 0x3F000000, 0x3E800000, 0xBFD9999A, 0xBF666666, 0xBFCCCCCD, 0x3FCCCCCD, 0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3E800000, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333, 0x3FB33333, 0x40000000, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333, 0x3F99999A, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333, 0x3F99999A, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFF33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FF33333, 0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xBFD9999A, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FD9999A, 0x3FB33333, 0x3FF33333, 0x3F000000, 0x3E800000, 0xBFF33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FF33333, 0x3FCCCCCD, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333, 0x3FC00000, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333, 0x40000000, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333, 0x3FD9999A, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xBFCCCCCD, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FCCCCCD, 0x3FD9999A, 0x3FCCCCCD, 0x3F000000, 0x3EAE147B, 0xBFC00000, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FC00000, 0x3FD9999A, 0x3FCCCCCD, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF333333, 0xBFC00000, 0x3FE66666, 0x3F4CCCCD, 0x3F666666, 0x3F000000, 0x3EE66666, 0xBFA66666, 0xBF800000, 0xBF4CCCCD, 0x3FA66666, 0x3F99999A, 0x3F4CCCCD, 0x3F000000, 0x3EE66666, 0xBFB33333, 0xBF800000, 0xBFCCCCCD, 0x3FB33333, 0x3FC00000, 0x3F333333, 0x3F000000, 0x3E99999A, 0xBFB33333, 0xBFC00000, 0xBFCCCCCD, 0x3FB33333, 0x3FC00000, 0x3F19999A, 0x3F000000, 0x3ECCCCCD, 0xBF99999A, 0xBF666666, 0xBFC00000, 0x3F99999A, 0x3FC00000, 0x3F666666, 0x3F000000, 0x3E99999A, 0xBFA66666, 0xBF8CCCCD, 0xBFB33333, 0x3FA66666, 0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xBFC00000, 0xBF4CCCCD, 0xBFA66666, 0x3FC00000, 0x3F8CCCCD, 0x3FC00000, 0x3F19999A, 0x3ECCCCCD, 0xBFB33333, 0xBFA66666, 0xC019999A, 0x3FB33333, 0x3FA66666, 0x3F800000, 0x3F000000, 0x3E4CCCCD, 0xBFCCCCCD, 0xBFB33333, 0xBF4CCCCD, 0x3FCCCCCD, 0x3FCCCCCD, 0x3FC00000, 0x3F000000, 0x3E4CCCCD, 0xBFD9999A, 0xBF99999A, 0xBF99999A, 0x3FD9999A, 0x3F99999A, 0x3F4CCCCD, 0x3F000000, 0x3DCCCCCD, 0xC0066666, 0xBF4CCCCD, 0xC0000000, 0x40066666, 0x3FC00000, 0x3F4CCCCD, 0x3F000000, 0x3E800000, 0xBFE66666, 0xBF8CCCCD, 0xBFE66666, 0x3FE66666, 0x3FE66666, 0x3F666666, 0x3F000000, 0x3E99999A, 0xBFF33333, 0xBF8CCCCD, 0xBFD9999A, 0x3FF33333, 0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3EE66666, 0xC00CCCCD, 0xBFA66666, 0xBFE66666, 0x400CCCCD, 0x3F8CCCCD, 0x3F333333, 0x3F000000, 0x3E4CCCCD, 0xBF99999A, 0xBF4CCCCD, 0xC0200000, 0x3F99999A, 0x3FCCCCCD, 0x3F666666, 0x3F000000, 0x3E4CCCCD, 0xC00CCCCD, 0xBF99999A, 0xC0000000, 0x400CCCCD, 0x3F800000, 0x3F4CCCCD, 0x3F000000, 0x3E4CCCCD, 0xC00CCCCD, 0xBF99999A, 0xBFCCCCCD, 0x400CCCCD, 0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xC00CCCCD, 0xBF99999A, 0xBFCCCCCD, 0x400CCCCD, 0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xBFCCCCCD, 0xBFC00000, 0xC0000000, 0x3FCCCCCD, 0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E800000, 0xBFCCCCCD, 0xBF8CCCCD, 0xBFF33333, 0x3FCCCCCD, 0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF8CCCCD, 0xBFC00000, 0x40000000, 0x3FB33333, 0x3F4CCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFC00000, 0xBF99999A, 0xBFC00000, 0x3FC00000, 0x40066666, 0x3F4CCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFCCCCCD, 0xBFB33333, 0xBFC00000, 0x3FCCCCCD, 0x3FA66666, 0x3F4CCCCD, 0x3F000000, 0x3E19999A, 0xBFF33333, 0xBF99999A, 0xC0000000, 0x3FF33333, 0x3F99999A, 0x3F800000, 0x3F000000, 0x3EAE147B, 0xBFF33333, 0xBF800000, 0xBFD9999A, 0x3FF33333, 0x3F800000, 0x3F333333, 0x4C6F6164, 0x696E6720, 0x456D626C, 0x656D2E2E, 0x2E000000, 0x83478393, 0x8375838C, 0x838082F0, 0x838D815B, 0x83689286, 0x82C582B7, 0x81420000, 0x53656C65, 0x63742061, 0x20506C61, 0x63652074, 0x6F205265, 0x67697374, 0x65722074, 0x68652045, 0x6D626C65, 0x6D2E2000, 0x83478393, 0x8375838C, 0x838082F0, 0x936F985E, 0x82B782E9, 0x8FEA8F8A, 0x82F09149, 0x91F082B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0x00000000, 0x52656D6F, 0x76652045, 0x6D626C65, 0x6D3F0000, 0x83478393, 0x8375838C, 0x838082F0, 0x82CD82AA, 0x82B582DC, 0x82B782A9, 0x81480000, 0x53656C65, 0x63742050, 0x61727473, 0x2E200000, 0x8370815B, 0x836382F0, 0x914991F0, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x53656C65, 0x63742061, 0x6E20456D, 0x626C656D, 0x2E200000, 0x83478393, 0x8375838C, 0x838082F0, 0x914991F0, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x8FE38F91, 0x82AB8A6D, 0x94469286, 0x82C582B7, 0x81420000, 0x4170706C, 0x7920456D, 0x626C656D, 0x2E200000, 0x83478393, 0x8375838C, 0x838082F0, 0x935C82E8, 0x957482AF, 0x82DC82B7, 0x81420000, 0x436F6D70, 0x6C657469, 0x6E672070, 0x726F6365, 0x7373696E, 0x672E2E2E, 0x00000000, 0x8F4997B9, 0x8F88979D, 0x928682C5, 0x82B78142, 0x00000000, 0x436F6E66, 0x69726D69, 0x6E672073, 0x6176652E, 0x2E2E0000, 0x835A815B, 0x83758A6D, 0x94469286, 0x82C582B7, 0x81420000, (u32)lbl_3_data_2DCC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2DE0__fzgx_offset_0, (u32)lbl_3_data_2DFC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2E24__fzgx_offset_0, (u32)lbl_3_data_2E54__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2E64__fzgx_offset_0, (u32)lbl_3_data_2E80__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2E90__fzgx_offset_0, (u32)lbl_3_data_2EAC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2EC0__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2EE0__fzgx_offset_0, (u32)lbl_3_data_2EF4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2F04__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2F20__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2F3C__fzgx_offset_0, (u32)lbl_3_data_2F50__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2F64__fzgx_offset_0, 0x83AD2052, 0x6F746174, 0x65204D61, 0x6368696E, 0x65000000, 0x83AD208E, 0xD45B82AD, 0x82E982DC, 0x5D82CC89, 0xF15B82A9, 0x82A25D93, 0x5D5B82C4, 0x82F15D00, 0x83A6204D, 0x6F766520, 0x43616D65, 0x72610000, 0x83A62083, 0x4A838183, 0x8982CC88, 0xDA5B82A2, 0x5D93AE5B, 0x82C782A4, 0x5D000000, 0x83A183AF, 0x205A6F6F, 0x6D000000, 0x83A183AF, 0x20835981, 0x5B838000, 0x83A42050, 0x72657669, 0x65770000, 0x83A42083, 0x76838C83, 0x72838581, 0x5B000000, 0x83B283B4, 0x20496E63, 0x72656173, 0x652F5265, 0x64756365, 0x20456D62, 0x6C656D20, 0x53697A65, 0x00000000, 0x83B283B4, 0x20834783, 0x93837583, 0x8C838082, 0xCC8A675B, 0x82A982AD, 0x5D91E55B, 0x82BE82A2, 0x5D81458F, 0x6B5B82B5, 0x82E382AD, 0x205D8FAC, 0x5B2082B5, 0x82E582A4, 0x5D000000, 0x839F2050, 0x61737465, 0x00000000, 0x839F2093, 0x5C5B82CD, 0x5D82E900, 0x839F2050, 0x65656C20, 0x6F666600, 0x839F2082, 0xCD82AA82, 0xB7000000, (u32)lbl_3_data_3068__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_307C__fzgx_offset_0, (u32)lbl_3_data_309C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_30AC__fzgx_offset_0, (u32)lbl_3_data_30C8__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_30D4__fzgx_offset_0, (u32)lbl_3_data_30E0__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_30EC__fzgx_offset_0, (u32)lbl_3_data_30FC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_3120__fzgx_offset_0, (u32)lbl_3_data_315C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_3168__fzgx_offset_0, (u32)lbl_3_data_3174__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_3180__fzgx_offset_0, 0x00000000, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_F984__fzgx_offset_0, 0x00000001, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_FD30__fzgx_offset_0, 0x00000002, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_104C4__fzgx_offset_0, 0x00000003, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_10260__fzgx_offset_0, 0x00000004, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_106FC__fzgx_offset_0, 0x00000005, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_10B68__fzgx_offset_0, 0x00000006, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_10CB8__fzgx_offset_0, 0x00000007, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_118BC__fzgx_offset_0, 0x00000008, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_1180C__fzgx_offset_0, 0x00000009, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_113AC__fzgx_offset_0, 0x25730A00, 0x2F626366, 0x66666666, 0x662F0000, 0x2F626366, 0x66663230, 0x302F0000, 0x25732573, 0x25732020, 0x20202573, 0x25732573, 0x0A000000}; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_3_data_1A40_file[0x2C] = {0x65, 0x6D, 0x62, 0x5F, 0x70, 0x61, 0x73, 0x74, 0x65, 0x5F, 0x65, 0x64, 0x69, 0x74, 0x6F, 0x72, 0x2E, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2E, 0x2F, 0x65, 0x6D, 0x62, 0x6C, 0x65, 0x6D, 0x2F, 0x73, 0x61, 0x6D, 0x70, 0x6C, 0x65, 0x2E, 0x62, 0x69, 0x6E, 0x00}; /* fzgx-allow: A1 measured pool bytes and bindings */
static union {u32 words[11]; void *view[11];} fzgx_pool_native_lbl_3_data_1A40_tbl1 = {{(u32)lbl_3_data_32F4__fzgx_offset_0, (u32)lbl_3_data_32F4__fzgx_offset_0, (u32)lbl_3_data_32F4__fzgx_offset_0, (u32)lbl_3_data_32F4__fzgx_offset_0, (u32)lbl_3_data_32F4__fzgx_offset_0, (u32)lbl_3_data_32F4__fzgx_offset_0, 0x2E2F656D, 0x626C656D, 0x2F636861, 0x72612E62, 0x696E0000}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static void *fzgx_pool_native_lbl_3_data_1A40_tbl2[6] = {(void *)(u32)lbl_3_data_3320__fzgx_offset_0, (void *)(u32)lbl_3_data_3320__fzgx_offset_0, (void *)(u32)lbl_3_data_3320__fzgx_offset_0, (void *)(u32)lbl_3_data_3320__fzgx_offset_0, (void *)(u32)lbl_3_data_3320__fzgx_offset_0, (void *)(u32)lbl_3_data_3320__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u8 fzgx_pool_native_lbl_3_data_1A40_unk_190C[4] = {0x65, 0x6D, 0x62, 0x6C};

/* the TU's .rodata literal pool, in retail order, ahead of this function's initializers */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 50.0f;
    s = 500.0f;
    s = 31.200000762939453f;
    s = 312.0f;
    s = 68.0f;
    s = 20.0f;
    s = 96.0f;
    s = 1.3600000143051147f;
    s = 161.0f;
    s = 1.015625f;
    s = 129.0f;
    s = 15.0f;
    s = 10.0f;
    s = 0.0f;
    s = 86.0f;
    s = 0.5f;
    s = 139.0f;
    s = 75.0f;
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table2[3] = {0xFFFF0000, 0xFFFF0000, 0xFFFFFF00};
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 185.0f;
    s = 180.0f;
    s = 276.0f;
    s = 116.0f;
    s = 7.0f;
    s = 205.0f;
    s = 11.399999618530273f;
    s = 40.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 80.0f;
    s = 274.0f;
    s = 0.5833333134651184f;
    s = 0.5416666865348816f;
    s = 0.4583333432674408f;
    d = 4503599627370496.0;
    s = 320.0f;
    s = 240.0f;
    s = 5.0f;
    s = 6.099999904632568f;
    s = 0.800000011920929f;
    s = 228.0f;
    s = 252.0f;
    s = 0.10000000149011612f;
    s = -30.0f;
    s = 750.0f;
    s = 48.0f;
    s = 660.0f;
    s = 44.0f;
    s = 24.0f;
    s = 302.0f;
    s = 70.0f;
    s = 330.0f;
    s = 1.2699999809265137f;
    s = 390.0f;
    s = 308.0f;
    s = 1.0f;
    s = 368.0f;
    s = 360.0f;
    s = 30.0f;
    s = 0.4000000059604645f;
    s = 32768.0f;
    s = 0.90625f;
    s = 0.921875f;
    s = 0.9375f;
}
static const unsigned long fzgx_pool_table4[25] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x40200000, 0xC1700000, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x40200000, 0xC1700000, 0x00000000, 0x00000000, 0x00000000, 0x40A00000, 0xC1700000, 0x00000000, 0x40200000, 0xC1700000};  /* fzgx-allow: A1 float bit patterns (5.0f, -15.625f, 2.5f) in retail pool table, not addresses */
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 55.0f;
    s = 90000.0f;
    s = 95.0f;
    s = 17.0f;
    s = 354.0f;
    s = 310.0f;
    s = 365.0f;
    s = 143.0f;
    s = 19.29990005493164f;
    s = 0.009999999776482582f;
    s = 0.75f;
    s = 351.0f;
    s = 387.0f;
    s = 0.6000000238418579f;
    s = 0.699999988079071f;
    s = 348.0f;
    s = 384.0f;
}
static const unsigned long fzgx_pool_table6[1] = {0xFFFFFFFF};
  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 200.0f;
    s = 0.05000000074505806f;
    s = 0.3499999940395355f;
    s = 0.0005000000237487257f;
    s = 0.0020000000949949026f;
    s = 0.004999999888241291f;
    d = 0.75;
    s = 256.0f;
    s = 128.0f;
    s = 512.0f;
    s = 2048.0f;
    s = 16383.0f;
    s = 4.5f;
    d = 0.100000001490116119384765625;
    s = 0.02500000037252903f;
    d = 0.5;
}

#pragma section code_type ".fzgxpool"
static void fzgx_base_order_data(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: the TU references .data in retail order */
    s = *(u8 *)&fzgx_pool_native_lbl_3_data_1A40_gap_0;
    s = *(u8 *)&fzgx_pool_native_lbl_3_data_1A40_file;
    s = *(u8 *)&fzgx_pool_native_lbl_3_data_1A40_tbl2;
    s = *(u8 *)&fzgx_pool_native_lbl_3_data_1A40_unk_190C;
}
/* fixes the .bss layout: objects are emitted in first-access order */
void fzgx_bss_order(void) {
    fn_80008BEC(&s_entries, 0, 0);
    fn_80008BEC(&fzgx_pool_s_unk_7EDC4, 0, 0);
    fn_80008BEC(&lbl_3_bss_7EDC0__fzgx_offset_8, 0, 0);
    fn_80008BEC(&lbl_3_bss_7EDCC__fzgx_offset_0, 0, 0);
    fn_80008BEC(&lbl_3_bss_7EDCC__fzgx_offset_4, 0, 0);
    fn_80008BEC(&fzgx_pool_s_unk_7EDD4, 0, 0);
    fn_80008BEC(&lbl_3_bss_7EDCC__fzgx_offset_A, 0, 0);
    fn_80008BEC(&lbl_3_bss_7EDD8, 0, 0);
    fn_80008BEC(&lbl_3_bss_7EE40, 0, 0);
    fn_80008BEC(&lbl_3_bss_87000, 0, 0);
    fn_80008BEC(&lbl_3_bss_87040, 0, 0);
    fn_80008BEC(&lbl_3_bss_8F200, 0, 0);
    fn_80008BEC(&lbl_3_bss_9F640, 0, 0);
    fn_80008BEC(&fzgx_pool_lbl_3_bss_9F664, 0, 0);
    fn_80008BEC(&lbl_3_bss_9F690, 0, 0);
}
#pragma section code_type ".text"

 /* fzgx-allow: A1 measured pool bytes and bindings */

void fn_3_11FF0(void) {
    u8 buffer1[0x2000] __attribute__((aligned(32)));
    u8 buffer2[0x2000] __attribute__((aligned(32)));
    LoadResult file1;
    LoadResult file2;
    Vec3 pos = {0.0f, 0.0f, 5.0f};
    Vec3 target = {0.0f, 0.0f, 0.0f};
    Vec3 up = {0.0f, 1.0f, 0.0f};
    Parts parts;
    
    s8 mode;
    u8 i, j;
    s32 oldCount;
    s32 count;
    u32 packed;

    fn_1_4A00(1, 15, lbl_3_bss_7EDD8.unk_4);
    fn_1_A176C((void *)lbl_1_bss_6EAD0.unk_0->unk_0, 8);
    fn_80008BA8(&lbl_3_bss_7EE40, &CUR, sizeof(Entry));
    fn_80008BA8(&lbl_3_bss_87040, &CUR, sizeof(Entry));
    lbl_3_bss_9F640.unk_4 = pos;
    lbl_3_bss_9F690.unk_10 = target;
    lbl_3_bss_9F640.unk_10 = target;
    {
        Vec3 eye = {0.0f, 0.0f, 5.0f};
        lbl_3_bss_9F690.unk_4 = eye;
    }
    lbl_3_bss_9F690.unk_20 = 0;
    camera_update_state(&lbl_3_bss_9F690);
    lbl_3_bss_7EDD8.unk_C = 0;
    lbl_3_bss_7EDD8.unk_10 = 0;
    lbl_3_bss_7EDD8.unk_26 = lbl_3_bss_7EE40.parts[0].unk_28;
    lbl_3_bss_7EDD8.unk_14 = 0;
    lbl_3_bss_7EDD8.unk_24 = -1;
    lbl_3_bss_7EDD8.unk_22 = 0;
    lbl_3_bss_7EDD8.unk_15 = 0;
    lbl_3_bss_7EDD8.unk_18 = 0;
    lbl_3_bss_7EDD8.unk_1C = 0;
    lbl_3_bss_7EDD8.unk_1F = 4;
    lbl_3_bss_7EDD8.unk_A = -1;
    lbl_3_bss_7EDD8.unk_1E = 0;
    lbl_3_bss_7EDD8.unk_40 = 0;
    lbl_3_bss_7EDD8.unk_C = 0x80000000;
    lbl_3_bss_7EDD8.unk_21 = 10;
    lbl_3_bss_7EDD8.unk_20 = 10;
    lbl_3_bss_7EDD8.unk_3C = 2;
    lbl_3_bss_7EDD8.unk_48 = 0;
    lbl_3_bss_7EDD8.unk_4A = 0;
    lbl_3_bss_7EDD8.unk_4C = 0;
    lbl_3_bss_7EDD8.unk_4E = 0;
    lbl_3_bss_7EDD8.unk_50 = 0;
    lbl_3_bss_7EDD8.unk_51 = 0;
    lbl_3_bss_7EDD8.unk_2C = 0;
    lbl_3_bss_7EDD8.unk_30 = 0;
    lbl_3_bss_7EDD8.unk_34 = 0;
    lbl_3_bss_7EDD8.unk_38 = 0;
    fn_1_435C(lbl_3_bss_7EDD8.unk_4);
    lbl_3_bss_7EDD8.unk_A = fn_1_3F8C(fzgx_pool_native_lbl_3_data_1A40_unk_190C, fn_3_E6F8, 0, 6);
    lbl_3_bss_7EDCC__fzgx_offset_0 = fn_1_45D0(HEAP, 0x440, fzgx_pool_native_lbl_3_data_1A40_file, 0xA3B);
    fn_80008BEC(lbl_3_bss_7EDCC__fzgx_offset_0, 0, 0x440);
    if (!(CUR.parts[0].flags & 0x40000000)) {
        lbl_3_bss_7EDD8.unk_44 = fn_1_80CC4(CUR.parts[0].unk_5, 0, 0, lbl_3_bss_7EDCC__fzgx_offset_0);
        mode = 1;
        if (CUR.kind == 4) {
            CUR.parts[0].unk_8 = 2;
            lbl_3_bss_7EE40.parts[0].unk_8 = 2;
        } else if (CUR.kind == 40) {
            CUR.parts[0].unk_8 = 3;
            lbl_3_bss_7EE40.parts[0].unk_8 = 3;
        } else {
            CUR.parts[0].unk_8 = 1;
            lbl_3_bss_7EE40.parts[0].unk_8 = 1;
        }
        for (i = 0; i < 4; i++) {
            fn_3_12FD4(0, (u8)CUR.parts[i].unk_20, CUR.kind, &CUR.parts[i].unk_30, &CUR.parts[i].unk_34);
            lbl_3_bss_7EE40.parts[i].unk_30 = CUR.parts[i].unk_30;
            lbl_3_bss_7EE40.parts[i].unk_34 = CUR.parts[i].unk_34;
            lbl_3_bss_87040.parts[i].unk_30 = CUR.parts[i].unk_30;
            lbl_3_bss_87040.parts[i].unk_34 = CUR.parts[i].unk_34;
        }
    } else {
        lbl_3_bss_7EDC0__fzgx_offset_8 = fn_1_45D0(HEAP, 0xA20, fzgx_pool_native_lbl_3_data_1A40_file, 0xA5F);
        fn_80008BEC(lbl_3_bss_7EDC0__fzgx_offset_8, 0, 0xA20);
        fn_80008BEC(&parts, 0, sizeof(Parts));
        {
            for (j = 0; j < 3; j++) {
                ((s16 *)&parts)[j] = CUR.sel[j].id;
            }
            parts.flag = 1;
            mode = 1;
            fn_1_14D8DC(&parts, lbl_3_bss_7EDC0__fzgx_offset_8, 1);
        }
        lbl_3_bss_7EDCC__fzgx_offset_0->unk_3A0 = lbl_3_bss_7EDC0__fzgx_offset_8;
        lbl_3_bss_7EDCC__fzgx_offset_0->unk_390 |= 0x04000000;
        for (i = 0; i < 4; i++) {
            fn_3_12FD4(5, (u8)CUR.parts[i].unk_20, CUR.sel[CUR.parts[i].unk_20].id, &CUR.parts[i].unk_30, &CUR.parts[i].unk_34);
        }
    }
    lbl_3_bss_7EDCC__fzgx_offset_4 = fn_1_7F254(&CUR, mode);
    lbl_3_bss_7EDCC__fzgx_offset_0->unk_3A4 = lbl_3_bss_7EDCC__fzgx_offset_4;
    lbl_3_bss_8F200.unk_4 = 4;
    lbl_3_bss_8F200.model = lbl_3_bss_7EDCC__fzgx_offset_0;
    lbl_3_bss_8F200.unk_10424 = fn_1_FD324;
    lbl_3_bss_8F200.unk_10428 = fn_1_FDC00;
    lbl_3_bss_8F200.unk_1042C = fn_1_FD27C;
    lbl_3_bss_8F200.unk_10420 = 0;
    lbl_3_bss_8F200.unk_C = 0x20000000;
    for (i = 0; i < 2; i++) {
        lbl_3_bss_87000.banks[i].unk_8 = fn_1_45D0(HEAP, 0x200, fzgx_pool_native_lbl_3_data_1A40_file, 0xA87);
        lbl_3_bss_87000.banks[i].unk_4 = fn_1_45D0(HEAP, 0x80, fzgx_pool_native_lbl_3_data_1A40_file, 0xA88);
        for (j = 0; j < 0x80; j++) {
            lbl_3_bss_87000.banks[i].unk_8[j] = 0;
        }
        lbl_3_bss_87000.banks[i].unk_0 = 9;
    }
    if (fn_1_45730(fzgx_pool_native_lbl_3_data_1A40_tbl1.view[lbl_801A66B4[0]], &file1)) {
        packed = fn_1_45B2C(&file1);
        lbl_3_bss_87000.count = packed >> 13;
        if (packed != 0) {
            lbl_3_bss_87000.flags = fn_1_45D0(HEAP, 0x100, fzgx_pool_native_lbl_3_data_1A40_file, 0xAA3);
            fn_80008BEC(lbl_3_bss_87000.flags, 0, 0xEE);
            lbl_3_bss_87000.items = fn_1_45D0(HEAP, 0x3C0, fzgx_pool_native_lbl_3_data_1A40_file, 0xAA5);
            for (i = 0; i < lbl_3_bss_87000.count; i++) {
                if (lbl_3_bss_87000.count > i) {
                    lbl_3_bss_87000.flags[i] = 1;
                    lbl_3_bss_87000.items[i] = fn_1_45D0(HEAP, 0x2000, fzgx_pool_native_lbl_3_data_1A40_file, 0xAAB);
                    fn_80008BEC(lbl_3_bss_87000.items[i], 0, 0x2000);
                    fn_1_458A0(&file1, buffer1, 0x2000, ((i << 13) + 31) & ~31);
                    fn_80008BA8(lbl_3_bss_87000.items[i], buffer1, 0x2000);
                } else {
                    lbl_3_bss_87000.flags[i] = 0;
                    lbl_3_bss_87000.items[i] = 0;
                }
            }
        }
        fn_1_45850(&file1);
    }
    if (fn_1_45730(fzgx_pool_native_lbl_3_data_1A40_tbl2[lbl_801A66B4[0]], &file2)) {
        oldCount = lbl_3_bss_87000.count;
        count = oldCount;
        packed = fn_1_45B2C(&file2);
        if (packed != 0) {
            for (i = oldCount; i < oldCount + (packed >> 13); i++) {
                if ((i == oldCount + (packed >> 13) - 3 && fn_1_F7BE4(0x15)) ||
                    (i == oldCount + (packed >> 13) - 2 && fn_1_F7BE4(0x21)) ||
                    (i == oldCount + (packed >> 13) - 1 && fn_1_F7BE4(0x21)) ||
                    fn_1_F7BE4((s16)(i - oldCount))) {
                    lbl_3_bss_87000.flags[count] = 1;
                    lbl_3_bss_87000.items[count] = fn_1_45D0(HEAP, 0x2000, fzgx_pool_native_lbl_3_data_1A40_file, 0xAE3);
                    fn_80008BEC(lbl_3_bss_87000.items[count], 0, 0x2000);
                    fn_1_458A0(&file2, buffer2, 0x2000, (((i - oldCount) << 13) + 31) & ~31);
                    fn_80008BA8(lbl_3_bss_87000.items[count], buffer2, 0x2000);
                    count++;
                }
            }
            for (; i < 0xEE; i++) {
                lbl_3_bss_87000.items[i] = 0;
                lbl_3_bss_87000.flags[i] = 0;
            }
            lbl_3_bss_87000.count = count;
        }
        fn_1_45850(&file2);
    }
    lbl_3_bss_7EDCC__fzgx_offset_A = 0;
}
/* fzgx:end fn_3_11FF0 */

/* fzgx:begin fn_3_12910 */
#include "types.h"

struct fn_3_12910_tbl_ent {
    u8 pad_0[0x8];
    u32 unk_8;
};
struct fn_3_12910_glb {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[0xE];
    s16 unk_22;
    s16 unk_24;
};

#pragma opt_dead_assignments off
void fn_3_12910(void) {
    struct fn_3_12910_glb *p;
    struct fn_3_12910_tbl_ent *t;
    u32 f;
    u32 idx;

    t = (struct fn_3_12910_tbl_ent *)lbl_3_data_3234;
    p = (struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8);
    idx = __cntlzw(p->unk_C);
    ((void (*)(void))(*(u32 *)((u8 *)lbl_3_data_3234 + idx * 12 + 8)))();

    f = p->unk_C;
    if (!(f & 0x80000000)) {
        if (f & 0x2000000) {
            s32 v = ((struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8))->unk_24 - 1;

            ((struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8))->unk_24 = (v < -15) ? -15 : ((v > 30) ? 30 : v);
        } else if (f & 0x1000000) {
            if (((struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8))->unk_10 & 0x2000000) {
                s32 v = ((struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8))->unk_24 + 1;

                ((struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8))->unk_24 = (v < -15) ? -15 : ((v > 0) ? 0 : v);
            } else {
                s32 v = ((struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8))->unk_24 - 1;

                ((struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8))->unk_24 = (v < 0) ? 0 : ((v > 30) ? 30 : v);
            }
        } else if (f & 0x400000) {
            s32 v = ((struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8))->unk_24 - 1;

            ((struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8))->unk_24 = (v < 0) ? 0 : ((v > 30) ? 30 : v);
        } else if (!(f & 0x800000)) {
            s32 v = ((struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8))->unk_24 + 1;

            ((struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8))->unk_24 = (v < -15) ? -15 : ((v > 30) ? 30 : v);
        }

        f = p->unk_C;
        if (f & 0x40000000) {
            s32 v = ((struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8))->unk_22 - 1;

            ((struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8))->unk_22 = (v < 0) ? 0 : ((v > 10) ? 10 : v);
        } else if (f & 0x20000000) {
            s32 v = ((struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8))->unk_22 + 1;

            ((struct fn_3_12910_glb *)(*(u8 (*)[52])&lbl_3_bss_7EDD8))->unk_22 = (v < 0) ? 0 : ((v > 10) ? 10 : v);
        }
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_3_12910 */

/* fzgx:begin fn_3_12B14 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/emb_paste_editor.h"

struct InputEntry { u16 unk_0; u8 pad_2[0x12]; };

struct InputState {
 union {
  struct { u8 pad8[8]; struct InputEntry unk_8[1]; };
  struct { u8 pad10[0x10]; struct InputEntry unk_10[1]; };
  struct { u8 pad12[0x12]; struct InputEntry unk_12[1]; };
 };
};

struct fn_3_10B68_lbl_1_bss_9F8_8_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};

struct fn_3_10B68_lbl_1_bss_9F8_12_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};

struct fn_3_10B68_lbl_1_bss_9F8 {
    union {
        struct { u8 pad_view_unk_8[0x8]; struct fn_3_10B68_lbl_1_bss_9F8_8_E20 unk_8[1]; };
        struct { u8 pad_view_unk_12[0x12]; struct fn_3_10B68_lbl_1_bss_9F8_12_E20 unk_12[1]; };
    };
};

struct Sig_fn_8004E278_fn_8004E278_Arg0 {
    u32 unk_0;
};

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec3u;

typedef struct {
    u16 unk_0;
    u8 pad_2[0x6];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} PadInput;

typedef struct {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x2058];
} fn_3_113AC_PasteEntry;

typedef struct {
    u8 pad_0[0x7];
    u8 unk_7;
    u8 pad_8[0x18];
    fn_3_113AC_PasteEntry unk_20[4];
    u8 pad_81A0[0x20];
} PasteSlot;
extern struct fn_3_10B68_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern void fn_1_A2D84(u32 arg0);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 lbl_801A66B4;
extern s32 fn_1_1310E0(void);
extern u32 fn_1_B7F08(void);
extern u32 fn_3_12D4(void);
extern void fn_1_130EE8(u32 arg0, u32 arg1);
extern void fn_1_130F98(void);
extern void fn_1_131004(void);
extern void fn_1_131050(u32 value, u32 state);
extern void fn_3_11974(void);
extern void fn_3_131C(s32 y, void *source);
extern void fn_3_14C4();
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_3_data_1A44__fzgx_offset_0[];
extern u8 lbl_3_data_1A6C__fzgx_offset_0[];
extern u8 lbl_3_data_1A70__fzgx_offset_0[];
extern u8 lbl_3_data_1ACC__fzgx_offset_0[];
extern u8 lbl_3_data_1B24__fzgx_offset_0[];
extern u8 lbl_3_data_1BB4__fzgx_offset_0[];
extern u8 lbl_3_data_1C04__fzgx_offset_0[];
extern const Vec3u lbl_3_rodata_4C8;
extern const Vec3u lbl_3_rodata_4D4;
extern u32 lbl_801A6410[];
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 camera_update_state(void *);
extern void fn_1_14DC68(void *, s16);
extern void fn_1_7F3AC(void *);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_80F1C(s32 arg0, void *arg1);
extern u32 fn_1_435C(u32 value);
extern void fn_1_426C(u32 idx);
extern void fn_1_FDFF4(void);
extern void fzgx_touch(void *);
extern void fn_3_13508(void);
extern void fn_3_137AC(void);
extern void fn_3_14778(u16 width, u16 height, u8 format, u32 data);
extern void fn_3_1857C(void);
extern void fn_3_1552C(void);
extern void fn_3_17098(void);
extern void fn_3_14080(void);
extern u32 fn_3_13D98();
extern u32 fn_3_13EA4(void *arg, u32 *output);
extern void fn_8006CE1C(f32 arg0);
extern s32 fn_1_3F8C(u32 arg3, u32 arg0, u32 arg1, u32 index);
extern void fn_1_47F74(s32 index);
extern void fn_1_A176C(u32, u32);
extern s32 fn_1_45D0();
extern int fn_1_B7E98(int index);
extern u8 fn_1_B8338(int);
extern void fn_1_1317C4(void);
extern u32 *lbl_1_bss_6EAD0[];
extern u32 fn_3_11A38(void);
extern u8 lbl_3_bss_8F200[];
extern u8 lbl_3_bss_A1778[12];
extern s16 lbl_1_bss_96A;
extern void fn_1_4A00(s32 fadeIn, u8 steps, u32 arg);

typedef struct {
    u8 pad_0[0x390];
    u32 flags;
    u8 pad_394[0xC];
    void *disp;
} Car;

typedef struct {
    u8 pad_0[0x4];
    u32 handle;
    u8 pad_8[0x2];
    s16 id;
    u8 pad_C[0x38];
    s16 unk_44;
    u8 pad_46[0x22];
} Sound;

typedef struct {
    u16 count;
    void *data;
    void **items;
} Entry;

typedef struct {
    Entry entries[2];
    u8 pad_18[0x4];
    u8 *flags;
    void **items;
    u8 pad_24[0x1C];
} Pool;

typedef struct {
    u8 pad_0[0x4];
    Vec3u eye;
    Vec3u at;
    u8 pad_1C[0x4];
    s16 unk_20;
    u8 pad_22[0x2];
} Cam;

/* The TU's .bss objects in retail order, addressed off one section base. */
static void *fzgx_obj_lbl_3_bss_7EDC0;
static u32 lbl_3_bss_7EDC0__fzgx_offset_4;
static u32 lbl_3_bss_7EDC0__fzgx_offset_8;
static Car *fzgx_obj_lbl_3_bss_7EDCC;
static u32 lbl_3_bss_7EDCC__fzgx_offset_4;
static u32 lbl_3_bss_7EDCC__fzgx_offset_8;
static Sound fzgx_obj_lbl_3_bss_7EDD8;
static u8 fzgx_obj_lbl_3_bss_7EE40[0x81C0];
static Pool fzgx_obj_lbl_3_bss_87000;
static u8 fzgx_obj_lbl_3_bss_87040[0x81C0];
static u8 fzgx_obj_lbl_3_bss_8F200[0x10440];
static Cam fzgx_obj_lbl_3_bss_9F640;
static u8 lbl_3_bss_9F664__fzgx_offset_0[1];
static u8 lbl_3_bss_9F665__fzgx_offset_0;
static u8 lbl_3_bss_9F665__fzgx_offset_1;
static u8 lbl_3_bss_9F665__fzgx_offset_2;
static u8 lbl_3_bss_9F665__fzgx_offset_3[40];
static Cam fzgx_obj_lbl_3_bss_9F690;
static u8 lbl_3_bss_9F690__fzgx_offset_24[0x14];
static Vec3u lbl_3_bss_9F690__fzgx_offset_38;
static Vec3u lbl_3_bss_9F690__fzgx_offset_44;




/* Fixes the .bss emission order (first access order); dropped at integration. */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_bss_primer(void) {
    fzgx_touch(&fzgx_obj_lbl_3_bss_7EDC0);
    fzgx_touch(&lbl_3_bss_7EDC0__fzgx_offset_4);
    fzgx_touch(&lbl_3_bss_7EDC0__fzgx_offset_8);
    fzgx_touch(&fzgx_obj_lbl_3_bss_7EDCC);
    fzgx_touch(&lbl_3_bss_7EDCC__fzgx_offset_4);
    fzgx_touch(&lbl_3_bss_7EDCC__fzgx_offset_8);
    fzgx_touch(&fzgx_obj_lbl_3_bss_7EDD8);
    fzgx_touch(fzgx_obj_lbl_3_bss_7EE40);
    fzgx_touch(&fzgx_obj_lbl_3_bss_87000);
    fzgx_touch(fzgx_obj_lbl_3_bss_87040);
    fzgx_touch(fzgx_obj_lbl_3_bss_8F200);
    fzgx_touch(&fzgx_obj_lbl_3_bss_9F640);
    fzgx_touch(lbl_3_bss_9F664__fzgx_offset_0);
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_3_bss_9F665__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_3_bss_9F665__fzgx_offset_1;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_3_bss_9F665__fzgx_offset_2;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_3_bss_9F665__fzgx_offset_3;
    fzgx_touch(&fzgx_obj_lbl_3_bss_9F690);
    fzgx_touch(lbl_3_bss_9F690__fzgx_offset_24);
    fzgx_touch(&lbl_3_bss_9F690__fzgx_offset_38);
    fzgx_touch(&lbl_3_bss_9F690__fzgx_offset_44);
}

#define FILE_NAME (((char *)&lbl_3_data_32DC))

void fn_3_12B14(void) {
    Vec3u eye;
    Vec3u at;
    Sound *snd;
    Entry *e;
    void ***items;
    u8 k;
    void **data;
    u32 off;
    Pool *pool;
    u8 i;
    u8 j;

    fn_1_FC414(fzgx_obj_lbl_3_bss_8F200, (void *)(s32)(1));
    eye = lbl_3_bss_9F690__fzgx_offset_38 = lbl_3_rodata_4C8;
    at = lbl_3_bss_9F690__fzgx_offset_44 = lbl_3_rodata_4D4;
    fzgx_obj_lbl_3_bss_9F690.eye = eye;
    fzgx_obj_lbl_3_bss_9F640.eye = eye;
    fzgx_obj_lbl_3_bss_9F690.at = at;
    fzgx_obj_lbl_3_bss_9F640.at = at;
    fzgx_obj_lbl_3_bss_9F640.unk_20 = 0;
    camera_update_state(&fzgx_obj_lbl_3_bss_9F640);

    if (fzgx_obj_lbl_3_bss_7EDCC->flags & 0x04000000) {
        fn_1_14DC68(fzgx_obj_lbl_3_bss_7EDCC->disp, 1);
        fn_1_7F3AC(fzgx_obj_lbl_3_bss_7EDCC);
        fn_1_46B4(lbl_801A6410[0], (u32)(void *)(fzgx_obj_lbl_3_bss_7EDCC->disp), FILE_NAME, 0xB46);
        fn_1_46B4(lbl_801A6410[0], (u32)(void *)(fzgx_obj_lbl_3_bss_7EDCC), FILE_NAME, 0xB47);
    } else {
        fn_1_7F3AC(fzgx_obj_lbl_3_bss_7EDCC);
        fn_1_80F1C(fzgx_obj_lbl_3_bss_7EDD8.unk_44, fzgx_obj_lbl_3_bss_7EDCC);
        fn_1_46B4(lbl_801A6410[0], (u32)(void *)(fzgx_obj_lbl_3_bss_7EDCC), FILE_NAME, 0xB4D);
    }

    if (fzgx_obj_lbl_3_bss_7EDD8.id != -1) {
        fn_1_435C(fzgx_obj_lbl_3_bss_7EDD8.handle);
        fn_1_426C(fzgx_obj_lbl_3_bss_7EDD8.id);
        fzgx_obj_lbl_3_bss_7EDD8.id = -1;
    }

    for (i = 0; i < 2; i++) {
        data = &fzgx_obj_lbl_3_bss_87000.entries[i].data;
        fn_1_46B4(lbl_801A6410[0], (u32)(void *)(*data), FILE_NAME, 0xB5A);
        items = &fzgx_obj_lbl_3_bss_87000.entries[i].items;
        for (j = 0; j < fzgx_obj_lbl_3_bss_87000.entries[i].count; j++) {
            if ((*items)[j] != NULL) {
                fn_1_46B4(lbl_801A6410[0], (u32)(void *)((*items)[j]), FILE_NAME, 0xB5F);
                (*items)[j] = NULL;
            }
        }
        fn_1_46B4(lbl_801A6410[0], (u32)(void *)(*items), FILE_NAME, 0xB63);
        *data = NULL;
        *items = NULL;
    }

    pool = &fzgx_obj_lbl_3_bss_87000;
    for (k = 0; k < 0xEE; k++) {
        off = k * 4;
        if (*(void **)((u8 *)pool->items + off) != NULL && pool->flags[k] != 0) {
            fn_1_46B4(lbl_801A6410[0], (u32)(void *)(*(void **)((u8 *)pool->items + off)), FILE_NAME, 0xB6C);
        }
        *(void **)((u8 *)pool->items + off) = NULL;
    }
    fn_1_46B4(lbl_801A6410[0], (u32)(void *)(pool->items), FILE_NAME, 0xB71);
    fn_1_46B4(lbl_801A6410[0], (u32)(void *)(pool->flags), FILE_NAME, 0xB72);
    pool->flags = NULL;
    pool->items = NULL;
    fzgx_obj_lbl_3_bss_7EDCC = NULL;
    lbl_3_bss_7EDC0__fzgx_offset_8 = 0;
    lbl_3_bss_7EDCC__fzgx_offset_4 = 0;
    fn_1_FDFF4();
}
/* fzgx:end fn_3_12B14 */

/* fzgx:begin fn_3_12E4C noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/emb_memcard.h"


extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;
extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_C1394(u32 *arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, u32 arg3);
extern u32 lbl_3_rodata_288[60];
extern void lbl_8006DCA4(void);
extern void lbl_8006E1D8(struct Vec3 *, f32, f32, f32);
extern void fn_1_7BCCC(struct Vec3 *);
extern void fn_80035680(struct GXLightObj *, f32, f32, f32);
extern void fn_80035690(struct GXLightObj *, f32, f32, f32);
extern void fn_80035420(struct GXLightObj *, f32, int);
extern void fn_800356AC(struct GXLightObj *, u32 *);
extern void GXInitLightDistAttn(struct GXLightObj *, f32, f32, int);
extern void fn_1_7BB80(struct GXLightObj *, int);
extern void fn_1_7BD6C(int);
extern void fn_80074CF4(f32, f32, f32);

typedef struct { u32 x; u32 y; u32 z; } Vec3;
typedef struct { u32 unused0; u32 unused1; Vec3 first; Vec3 second; } Data;
typedef struct { u8 pad_000[0x508]; Vec3 first; Vec3 second; } SpecialData;
typedef struct {
    u8 pad_000[0x328];
    s8 state;
    u8 pad_329[0x67];
    u32 flags;
    u8 pad_394[0xc];
    s16 *indices;
} Customize;

void fn_3_12E4C(Customize *self, u8 index, Vec3 *first, Vec3 *second) {
    Data *data;
    SpecialData *special;
    u8 state;

    if (self->flags & 0x04000000) {
        data = (Data *)(*(u8 (*)[2400])&lbl_3_data_246C);
        data = (Data *)((u8 *)data +
                        ((u8)((self->indices)[(u32)index * 0x1b0]) << 5));
        *first = data->first;
        *second = data->second;
        return;
    }

    state = self->state;
    if (state == 4) {
        if (index != 0) {
            data = (Data *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + 0x560);
            *first = data->first;
            *second = data->second;
            return;
        }
        data = (Data *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + ((u8)state << 5));
        *first = data->first;
        *second = data->second;
        return;
    }

    if ((u8)state == 0x28) {
        special = (SpecialData *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + ((u8)index << 5));
        *first = special->first;
        *second = special->second;
        return;
    }

    data = (Data *)((u8 *)(*(u32 (*)[352])&lbl_3_data_1EEC) + (state << 5));
    *first = data->first;
    *second = data->second;
}
/* fzgx:end fn_3_12E4C */

/* fzgx:begin fn_3_12FD4 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/emb_memcard.h"


extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;
extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_C1394(u32 *arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, u32 arg3);
extern u32 lbl_3_rodata_288[60];
extern void lbl_8006DCA4(void);
extern void lbl_8006E1D8(struct Vec3 *, f32, f32, f32);
extern void fn_1_7BCCC(struct Vec3 *);
extern void fn_80035680(struct GXLightObj *, f32, f32, f32);
extern void fn_80035690(struct GXLightObj *, f32, f32, f32);
extern void fn_80035420(struct GXLightObj *, f32, int);
extern void fn_800356AC(struct GXLightObj *, u32 *);
extern void GXInitLightDistAttn(struct GXLightObj *, f32, f32, int);
extern void fn_1_7BB80(struct GXLightObj *, int);
extern void fn_1_7BD6C(int);
extern void fn_80074CF4(f32, f32, f32);

struct fn_3_12FD4_Arg3 {
    f32 unk_0;
};
struct fn_3_12FD4_Arg4 {
    f32 unk_0;
};

struct fn_3_12FD4_Record {
    f32 x;
    f32 y;
    u8 pad[24];
};

void fn_3_12FD4(u32 arg0, u32 arg1, u32 arg2, struct fn_3_12FD4_Arg3 *arg3, struct fn_3_12FD4_Arg4 *arg4) {
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    if (__rlwnm(arg0, 6, 31, 31)) {
        v1 = ((arg2 & 0xFF) << 5);
        arg3->unk_0 = *(f32 *)((u8 *)&lbl_3_data_246C + v1);
        arg4->unk_0 = *(f32 *)((u32)&lbl_3_data_246C + v1 + 4);
        return;
    }
    v2 = (arg2 & 0xFF);
    v3 = arg2;
    if (v2 == 4) {
        v3 = 43;
    } else {
        if (v2 == 40) {
            v3 = ((arg1 + 40) & 0xFF);
        }
    }
    v4 = ((v3 & 0xFF) << 5);
    arg3->unk_0 = *(f32 *)((u8 *)&lbl_3_data_1EEC + v4);
    arg4->unk_0 = *(f32 *)((u32)&lbl_3_data_1EEC + v4 + 4);
    return;
}
/* fzgx:end fn_3_12FD4 */

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

/* fzgx:begin fn_3_130C8 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/emb_paste_editor.h"

struct InputEntry { u16 unk_0; u8 pad_2[0x12]; };

struct InputState {
 union {
  struct { u8 pad8[8]; struct InputEntry unk_8[1]; };
  struct { u8 pad10[0x10]; struct InputEntry unk_10[1]; };
  struct { u8 pad12[0x12]; struct InputEntry unk_12[1]; };
 };
};

struct fn_3_10B68_lbl_1_bss_9F8_8_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};

struct fn_3_10B68_lbl_1_bss_9F8_12_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};

struct fn_3_10B68_lbl_1_bss_9F8 {
    union {
        struct { u8 pad_view_unk_8[0x8]; struct fn_3_10B68_lbl_1_bss_9F8_8_E20 unk_8[1]; };
        struct { u8 pad_view_unk_12[0x12]; struct fn_3_10B68_lbl_1_bss_9F8_12_E20 unk_12[1]; };
    };
};

struct Sig_fn_8004E278_fn_8004E278_Arg0 {
    u32 unk_0;
};

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec3u;

typedef struct {
    u16 unk_0;
    u8 pad_2[0x6];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} PadInput;

typedef struct {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x2058];
} fn_3_113AC_PasteEntry;

typedef struct {
    u8 pad_0[0x7];
    u8 unk_7;
    u8 pad_8[0x18];
    fn_3_113AC_PasteEntry unk_20[4];
    u8 pad_81A0[0x20];
} PasteSlot;
extern struct fn_3_10B68_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern void fn_1_A2D84(u32 arg0);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern u32 lbl_801A66B4;
extern s32 fn_1_1310E0(void);
extern u32 fn_1_B7F08(void);
extern u32 fn_3_12D4(void);
extern void fn_1_130EE8(u32 arg0, u32 arg1);
extern void fn_1_130F98(void);
extern void fn_1_131004(void);
extern void fn_1_131050(u32 value, u32 state);
extern void fn_3_11974(void);
extern void fn_3_131C(s32 y, void *source);
extern void fn_3_14C4();
extern void fn_80008BA8(void *, void *, u32);
extern u8 lbl_3_data_1A44__fzgx_offset_0[];
extern u8 lbl_3_data_1A6C__fzgx_offset_0[];
extern u8 lbl_3_data_1A70__fzgx_offset_0[];
extern u8 lbl_3_data_1ACC__fzgx_offset_0[];
extern u8 lbl_3_data_1B24__fzgx_offset_0[];
extern u8 lbl_3_data_1BB4__fzgx_offset_0[];
extern u8 lbl_3_data_1C04__fzgx_offset_0[];
extern const Vec3u lbl_3_rodata_4C8;
extern const Vec3u lbl_3_rodata_4D4;
extern u32 lbl_801A6410[];
extern void fn_1_FC414(void *arg0, void *arg1);
extern u32 camera_update_state(void *);
extern void fn_1_14DC68(void *, s16);
extern void fn_1_7F3AC(void *);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_1_80F1C(s32 arg0, void *arg1);
extern u32 fn_1_435C(u32 value);
extern void fn_1_426C(u32 idx);
extern void fn_1_FDFF4(void);
extern void fzgx_touch(void *);
extern void fn_3_13508(void);
extern void fn_3_137AC(void);
extern void fn_3_14778(u16 width, u16 height, u8 format, u32 data);
extern void fn_3_1857C(void);
extern void fn_3_1552C(void);
extern void fn_3_17098(void);
extern void fn_3_14080(void);
extern u32 fn_3_13D98();
extern u32 fn_3_13EA4(void *arg, u32 *output);
extern void fn_8006CE1C(f32 arg0);
extern s32 fn_1_3F8C(u32 arg3, u32 arg0, u32 arg1, u32 index);
extern void fn_1_47F74(s32 index);
extern void fn_1_A176C(u32, u32);
extern s32 fn_1_45D0();
extern int fn_1_B7E98(int index);
extern u8 fn_1_B8338(int);
extern void fn_1_1317C4(void);
extern u32 *lbl_1_bss_6EAD0[];
extern u32 fn_3_11A38(void);
extern u8 lbl_3_bss_8F200[];
extern u8 lbl_3_bss_A1778[12];
extern s16 lbl_1_bss_96A;
extern void fn_1_4A00(s32 fadeIn, u8 steps, u32 arg);

typedef struct {
    u32 unk0;
    u32 unk4;
    u16 unk8;
    u16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    u8 pad1C[4];
    u32 unk20;
    u8 pad24[4];
    u8 unk28;
    u8 pad29[3];
} EditSub;

typedef struct {
    u32 unk0;
    u32 unk4;
} EditPair;

typedef struct {
    u8 pad[0x1ec];
    char unk1ec[0x14];
    char unk200[0x14];
    char unk214[0xc];
    char unk220[0x14];
    char unk234[1];
} EditStrings;


/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_3_bss_A1768;
u32 *lbl_3_bss_A176C__fzgx_offset_0;
u8 lbl_3_bss_A1770__fzgx_offset_0[4];
u8 lbl_3_bss_A1774__fzgx_offset_0[4];
u8 lbl_3_bss_A1778__fzgx_offset_0;
u32 lbl_3_bss_A1778__fzgx_offset_4;
u32 lbl_3_bss_A1778__fzgx_offset_8;
u32 *lbl_3_bss_A1784__fzgx_offset_0;
u32 lbl_3_bss_A1784__fzgx_offset_4;
EditPair lbl_3_bss_A1784__fzgx_offset_8;
u32 lbl_3_bss_A1784__fzgx_offset_10;
u32 lbl_3_bss_A1798__fzgx_offset_0;
u32 lbl_3_bss_A179C__fzgx_offset_0;
EditSub lbl_3_bss_A17A0__fzgx_offset_0;
s16 lbl_3_bss_A17CC__fzgx_offset_0;
u8 lbl_3_bss_A17D0__fzgx_offset_0[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_A1768;
    s = *(u8 *)&lbl_3_bss_A176C__fzgx_offset_0;
    s = *(u8 *)&lbl_3_bss_A1770__fzgx_offset_0;
    /* Native section-order primer. */ (void)*(volatile u8 *)&lbl_3_bss_A1774__fzgx_offset_0;
    s = *(u8 *)&lbl_3_bss_A1778__fzgx_offset_0;
    s = *(u8 *)&lbl_3_bss_A1778__fzgx_offset_4;
    s = *(u8 *)&lbl_3_bss_A1778__fzgx_offset_8;
    s = *(u8 *)&lbl_3_bss_A1784__fzgx_offset_0;
    s = *(u8 *)&lbl_3_bss_A1784__fzgx_offset_4;
    s = *(u8 *)&lbl_3_bss_A1784__fzgx_offset_8;
    s = *(u8 *)&lbl_3_bss_A1784__fzgx_offset_10;
    s = *(u8 *)&lbl_3_bss_A1798__fzgx_offset_0;
    s = *(u8 *)&lbl_3_bss_A179C__fzgx_offset_0;
    s = *(u8 *)&lbl_3_bss_A17A0__fzgx_offset_0;
    s = *(u8 *)&lbl_3_bss_A17CC__fzgx_offset_0;
    s = *(u8 *)&lbl_3_bss_A17D0__fzgx_offset_0;
}
#pragma section code_type ".text"

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

u32 fzgx_obj_lbl_3_data_3360[3] = {
    0x4D6F7665,
    0x20437572,
    0x736F7200
};
static u32 fzgx_pool_editor_data_rest[120] = {
    0x00000000,
    0x834A815B,
    0x835C838B,
    0x82CC88DA,
    0x93AE0000,
    0x48656C70,
    0x00000000,
    0x90E096BE,
    0x95B682CC,
    0x955C8EA6,
    0x00000000,
    0x4368616E,
    0x67652050,
    0x656E2053,
    0x697A6500,
    0x83798393,
    0x83548343,
    0x835982CC,
    0x95CF8D58,
    0x00000000,
    0x44697370,
    0x6C617920,
    0x47726964,
    0x00000000,
    0x834F838A,
    0x83628368,
    0x82CC955C,
    0x8EA60000,
    0x53797269,
    0x6E676500,
    0x8358837C,
    0x83438367,
    0x00000000,
    0x53656C65,
    0x63740000,
    0x8C8892E8,
    0x00000000,
    0x4261636B,
    0x00000000,
    0x82E082C7,
    0x82E90000,
    0x4368616E,
    0x67652043,
    0x6F6C6F72,
    0x00000000,
    0x904682CC,
    0x95CF8D58,
    0x00000000,
    0x5B454D42,
    0x4C454D20,
    0x45444954,
    0x4F525D20,
    0x48454C50,
    0x00000000,
    0x5B454D42,
    0x4C454D20,
    0x45444954,
    0x4F525D20,
    0x4D414E55,
    0x414C0000,
    (u32)(lbl_3_data_3360__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_3370__fzgx_offset_0),
    (u32)(lbl_3_data_3380__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_3388__fzgx_offset_0),
    (u32)(lbl_3_data_3360__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_3370__fzgx_offset_0),
    (u32)(lbl_3_data_3398__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_33A8__fzgx_offset_0),
    (u32)(lbl_3_data_33BC__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_33CC__fzgx_offset_0),
    (u32)(lbl_3_data_33DC__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_33E4__fzgx_offset_0),
    (u32)(lbl_3_data_33F0__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_33F8__fzgx_offset_0),
    (u32)(lbl_3_data_3400__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_3408__fzgx_offset_0),
    (u32)(lbl_3_data_3410__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_3420__fzgx_offset_0),
    (u32)(lbl_3_data_342C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_336C__fzgx_offset_0),
    (u32)(lbl_3_data_3444__fzgx_offset_0)
};
u32 lbl_3_data_3444__fzgx_offset_108[5] = {
    0x656D626C,
    0x656D5F6D,
    0x616B6572,
    0x5F63616C,
    0x63000000
};
u32 lbl_3_data_3444__fzgx_offset_11C[5] = {
    0x656D626C,
    0x656D5F6D,
    0x616B6572,
    0x5F646973,
    0x70000000
};
u32 lbl_3_data_3574__fzgx_offset_0[3] = {
    0x656D626C,
    0x656D2E63,
    0x00000000
};
u32 lbl_3_data_3574__fzgx_offset_C[5] = {
    0x2E2F656D,
    0x626C656D,
    0x2F73616D,
    0x706C652E,
    0x62696E00
};
u32 lbl_3_data_3574__fzgx_offset_20[1] = {
    0x2E2F656D
};

#define lbl_3_data_3360_unk1ec lbl_3_data_3444__fzgx_offset_108
#define lbl_3_data_3360_unk200 lbl_3_data_3444__fzgx_offset_11C
#define lbl_3_data_3360_unk214 lbl_3_data_3574__fzgx_offset_0
#define lbl_3_data_3360_unk220 lbl_3_data_3574__fzgx_offset_C
#define lbl_3_data_3360_unk234 lbl_3_data_3574__fzgx_offset_20
#define STR(f) (lbl_3_data_3360_##f)

void fn_3_130C8(void) {
    s32 n;
    u8 i;

    fn_8006CE1C(0.0f);
    fn_1_435C(lbl_3_bss_A1778__fzgx_offset_4);
    lbl_3_bss_A1784__fzgx_offset_4 = (u32)fn_1_3F8C( (u32)(void *)(STR(unk1ec)), (u32)(void *)(fn_3_13508), 0, 5);
    fn_1_435C(lbl_3_bss_A1778__fzgx_offset_8);
    lbl_3_bss_A1784__fzgx_offset_8.unk4 = (u32)fn_1_3F8C( (u32)(void *)(STR(unk200)), (u32)(void *)(fn_3_137AC), 0, 5);
    lbl_3_bss_A1778__fzgx_offset_0 = 0;
    lbl_3_bss_A1798__fzgx_offset_0 = 0;
    lbl_3_bss_A179C__fzgx_offset_0 = 0;
    fn_3_14778(0x40, 0x40, 0x10, 5);
    fn_3_1857C();
    fn_3_1552C();
    fn_3_17098();
    fn_3_14080();
    lbl_3_bss_A1784__fzgx_offset_0 = &lbl_3_bss_A17A0__fzgx_offset_0.unk20;
    fn_1_47F74(0x86);
    fn_1_A176C(*lbl_1_bss_6EAD0[0], 8);
    lbl_3_bss_A17A0__fzgx_offset_0.unk20 = (u32)fn_1_45D0((*((void * *)&lbl_801A6410)), 0x2000, STR(unk214), 0x94);
    fn_80008BEC((void *)lbl_3_bss_A17A0__fzgx_offset_0.unk20, 0, 0x2000);
    lbl_3_bss_A17A0__fzgx_offset_0.unkC = 0;
    lbl_3_bss_A17A0__fzgx_offset_0.unkE = 0;
    lbl_3_bss_A17A0__fzgx_offset_0.unk10 = 0x20;
    lbl_3_bss_A17A0__fzgx_offset_0.unk12 = 0x20;
    lbl_3_bss_A17A0__fzgx_offset_0.unk4 = 0;
    lbl_3_bss_A17A0__fzgx_offset_0.unk0 = 0;
    lbl_3_bss_A17A0__fzgx_offset_0.unk18 = 0;
    lbl_3_bss_A17A0__fzgx_offset_0.unk16 = 0;
    lbl_3_bss_A17A0__fzgx_offset_0.unk1A = 0;
    lbl_3_bss_A17A0__fzgx_offset_0.unk14 = 0;
    lbl_3_bss_A17A0__fzgx_offset_0.unk28 = 0;
    lbl_3_bss_A17CC__fzgx_offset_0 = 0;
    lbl_3_bss_A176C__fzgx_offset_0 = (void *)fn_1_45D0((*((void * *)&lbl_801A6410)), 0x3b8, STR(unk214), 0xa6);
    n = (s16)fn_3_13D98(STR(unk220), lbl_3_bss_A176C__fzgx_offset_0);
    lbl_3_bss_A17CC__fzgx_offset_0 = n + fn_3_13EA4(STR(unk234), lbl_3_bss_A176C__fzgx_offset_0 + n);
    for (i = lbl_3_bss_A17CC__fzgx_offset_0; i < 0xee; i++) {
        lbl_3_bss_A176C__fzgx_offset_0[i] = 0;
    }
    lbl_3_bss_A17D0__fzgx_offset_0[0] = fn_1_B7E98(0) ? fn_1_B8338(0) : 0;
    if (fn_1_B7E98(1)) {
        lbl_3_bss_A17D0__fzgx_offset_0[1] = fn_1_B8338(1);
    } else {
        lbl_3_bss_A17D0__fzgx_offset_0[1] = 0;
    }
    fn_1_1317C4();
}
/* fzgx:end fn_3_130C8 */
