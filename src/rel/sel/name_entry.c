#include "types.h"
#include "rel/sel/globals.h"
#include "rel/sel/name_entry.h"


extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);
extern s32 lbl_801A66B4;
extern u8 lbl_10_data_68E0[];
extern u32 lbl_10_rodata_1D64;
extern char * fn_80083DB0(char *, const char *);
extern u32 fn_10_2325C(void);
extern s32 fn_1_3F8C(void *, u32, void *, u32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4D494(void);
extern void fn_1_4AE0C(const char *, ...);
extern void fzgx_pool_use(void *);

/* fzgx:begin fn_10_25BC8 */
typedef struct fn_10_25BC8_NameEntryState {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u8 _pad0c[0x0c];
    u32 unk18;
    u32 unk1c;
} fn_10_25BC8_NameEntryState;

extern void fn_1_46B4(u32 arg0, fn_10_25BC8_NameEntryState *arg1, u8 *arg2, int arg3);

void fn_10_25BC8(void) {
    lbl_10_bss_55CDC = 1;
    fn_1_435C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk04);
    fn_1_426C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk18);
    fn_1_A8F78();
    fn_1_48140(0x8f);

    if (lbl_1_bss_960 != 1) {
        if (lbl_1_bss_960 != 3) {
            fn_1_412A0(1);
            fn_1_48140(0x9a);
        }
        fn_1_48140(0x9e);
    }

    fn_1_435C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk08);
    fn_1_426C(((fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8)->unk1c);
    fn_1_46B4(lbl_801A6410, (fn_10_25BC8_NameEntryState *)lbl_10_bss_55CD8,
              lbl_10_data_6980, 0x562);
    lbl_10_bss_55CD8 = 0;
}
/* fzgx:end fn_10_25BC8 */

/* fzgx:begin fn_10_25CB0 */
typedef struct fn_10_25CB0_Entry {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    u8 unk_C;
} fn_10_25CB0_Entry;

typedef struct fn_10_25CB0_Pair {
    u8 unk_0;
    u8 unk_1;
} fn_10_25CB0_Pair;

extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern fn_10_25CB0_Entry * fn_1_45D0(u32, u32, const char *, u32);

#pragma opt_loop_invariants off
#pragma opt_propagation on
void fn_10_25CB0(u32 arg0) {
    u8 *ptr;
    fn_10_25CB0_Entry *e;
    u8 *data;
    struct { u8 value; } c;
    struct { u32 value; } i;
    fn_10_25CB0_Pair *p;
    u32 v;
    const char * lab_t1;

    data = lbl_10_data_68E0;
    ptr = &lbl_10_bss_55CD8->unk_28;
    if (*ptr == 0) {
        if (lbl_801A66B4 == 5) {
            fn_80083DB0((char *)ptr, (const char *)data + 0x114);
        } else {
            lab_t1 = (const char *)data + 0x120;
            fn_80083DB0((char *)ptr, lab_t1);
        }
        *(u32 *)&v = lbl_10_rodata_1D64;
        fn_1_435C(lbl_10_bss_55CD8->unk_8);
        i.value = 0;
        while ((p = (fn_10_25CB0_Pair *)((u8 *)lbl_10_bss_55CD8 + 0x28 + i.value * 2))->unk_0 != 0) {
            c.value = (u8)i.value;
            e = fn_1_45D0(lbl_801A6410, 0x12, (const char *)data + 0xA0, 0xD4);
            e->unk_8 = c.value * 0x38 + 0x7E;
            e->unk_A = 0x17A;
            e->unk_0 = 2;
            e->unk_1 = 0;
            e->unk_4 = e->unk_8;
            e->unk_6 = e->unk_A;
            e->unk_2 = p->unk_0;
            e->unk_3 = p->unk_1;
            *(u32 *)((u8 *)e + 0xD) = v;
            e->unk_C = c.value;
            fn_1_3F8C(data + 0xC8, (u32)fn_10_2325C, e, 0xB);
            i.value++;
        }
        lbl_10_bss_55CD8->unk_E = (u8)i.value;
    }
    lbl_10_bss_55CD8->unk_0 |= 0x10000000;
}
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
/* fzgx:end fn_10_25CB0 */

/* fzgx:begin fn_10_25E1C */
#include "types.h"

typedef struct {
    u8 pad[0x8c];
    s16 value;
} fn_10_25E1C_NameEntryState;

typedef struct {
    s16 v[14];
} fn_10_25E1C_SndTable;

extern fn_10_25E1C_SndTable lbl_10_rodata_1D70;
extern u8 lbl_10_bss_55CE0;
extern u8 lbl_10_bss_55CE1;

void fn_10_25E1C(void) {
    fn_10_25E1C_NameEntryState *state = &(*(fn_10_25E1C_NameEntryState *)&lbl_1_bss_8B3A0);
    s32 i;
    s16 result;

    for (i = 0; i < 6; i++) {
        result = fn_1_12EF24(state->value, i);
        if (state->value == 5) {
            if (i == 5) {
                if (fn_1_F89E4(0) == 0) {
                    goto set_neg; // shared tail: retail merges both -1 arms
                }
            }
            if (i != 5) {
                if (fn_1_F89E4((u8)(i + 1)) == 0) {
                    goto set_neg; // shared tail: retail merges both -1 arms
                }
            }
            goto after_neg; // skip the merged -1 arm
        set_neg:
            result = -1;
        after_neg: ;
        }
        if (result != -1) {
            break;
        }
    }

    if (result != -1) {
        lbl_10_bss_55CE0 = (u8)result;
    } else {
        lbl_10_bss_55CE0 = (u8)fn_1_12EF24(state->value, 0);
    }

    fn_1_14A1AC(lbl_1_bss_8E51D);
    fn_1_14BC40();
    fn_1_1554D0();
    fn_1_1555B0(lbl_10_bss_55CE0);
    fn_1_47F74(0x91);
    fn_1_47F74(0x97);
    fn_1_47F74(0x99);

    for (i = 0; i < 6; i++) {
        result = fn_1_12EF24(state->value, i);
        if (result != -1) {
            u8 key = lbl_1_data_2B0D4[result];
            fn_10_25E1C_SndTable table = lbl_10_rodata_1D70;
            s16 index = lbl_1_data_2B144[key] - 1;

            if ((((u32)index > 13) ? 0 : (index >= 0)) && table.v[index] != -1) {
                fn_1_47F74(table.v[index]);
            }
        }
    }
    lbl_10_bss_55CE1 = 0;
}
/* fzgx:end fn_10_25E1C */

/* fzgx:begin fn_10_26000 */
u8 fn_10_26000(void) {
    u8 result;
    u16 flags;

    if (fn_1_B7C00()) {
        return 0;
    }

    if (lbl_10_bss_55CE1 != 0) {
        result = fn_10_26434();
        if (result == 1) {
            fn_10_26554();
            fn_1_14BD94(&lbl_10_bss_55CE0);
        }
        if (result != 0) {
            lbl_10_bss_55CE1 = 0;
        }
        return result;
    }

    flags = lbl_1_bss_9F8[4];
    if (((flags >> 11) & 1) != 0) {
        // fzgx-allow: A1 target hardware address
        fn_1_A2D84((void *)0xA9011100); // fzgx-allow: A2 target hardware address
        fn_10_26424();
        lbl_10_bss_55CE1 = 1;
    }
    fn_1_14BCBC(&lbl_10_bss_55CE0, lbl_1_bss_8B3A0[0x9e]);
    return 0;
}
/* fzgx:end fn_10_26000 */

/* fzgx:begin fn_10_260D4 */
#include "types.h"

typedef struct {
    u8 pad[0x8c];
    s16 value;
} fn_10_260D4_NameEntryState;

typedef struct {
    s16 v[14];
} fn_10_260D4_SndTable;

extern fn_10_260D4_SndTable lbl_10_rodata_1D8C;

extern void fn_1_48140(int);

void fn_10_260D4(void) {
    fn_10_260D4_NameEntryState *state = &(*(fn_10_260D4_NameEntryState *)&lbl_1_bss_8B3A0);
    s32 i;

    for (i = 5; i >= 0; i--) {
        s16 result = fn_1_12EF24(state->value, i);
        if (result != -1) {
            u8 key = lbl_1_data_2B0D4[result];
            fn_10_260D4_SndTable table = lbl_10_rodata_1D8C;
            s16 index = lbl_1_data_2B144[key] - 1;

            if ((((u32)index > 13) ? 0 : (index >= 0)) && table.v[index] != -1) {
                fn_1_48140(table.v[index]);
            }
        }
    }
    fn_1_48140(0x99);
    fn_1_48140(0x97);
    fn_1_48140(0x91);
    fn_1_15555C();
    fn_1_14BD74();
}
/* fzgx:end fn_10_260D4 */

/* fzgx:begin fn_10_261E4 */
#include "dolphin/hw_regs.h"

extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);

extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);

typedef struct { u8 r, g, b, a; } Sig_fn_800081C8_Color;
typedef Sig_fn_800081C8_Color Color;

extern Color fn_800081C8(Color, Color, f32);
extern void fn_1_49514(Color);
extern u32 fn_1_4D4C8(Color, f32, f32);
extern void fn_1_49528(Color);

/*
 * Layout stand-in for the TU's .data block at lbl_10_data_6A48: the erase-dialog
 * strings and the per-language pointer tables (question, YES, NO). The pointer
 * tables are relocations in retail; here they are zero words so the private
 * section's bytes can be proven equal and bound to the retail objects at submit.
 */
#pragma explicit_zero_data on
static char fzgx_pool_sQuestionEn[32] = "OK to erase this course record?";
static char fzgx_pool_sQuestionGe[36] = "GER OK to erase this course record?";
static char fzgx_pool_sQuestionFr[36] = "FRE OK to erase this course record?";
static char fzgx_pool_sQuestionSp[36] = "SPA OK to erase this course record?";
static char fzgx_pool_sQuestionIt[36] = "ITA OK to erase this course record?";
static char fzgx_pool_sQuestionJp[52] =
    "\x82\xB1\x82\xCC\x83\x52\x81\x5B\x83\x58\x82\xCC\x83\x8C\x83\x52\x81\x5B\x83\x68\x82\xF0\x0A"
    "\x83\x4E\x83\x8A\x83\x41\x82\xB5\x82\xC4\x82\xE0\x82\xE6\x82\xEB\x82\xB5\x82\xA2\x82\xC5\x82\xB7\x82\xA9\x3F";
static char *fzgx_pool_sEraseQuestion[6] = {0};
static char fzgx_pool_sYesEn[4] = "YES";
static char fzgx_pool_sYesGe[8] = "GER YES";
static char fzgx_pool_sYesFr[8] = "FRE YES";
static char fzgx_pool_sYesSp[8] = "SPA YES";
static char fzgx_pool_sYesIt[8] = "ITA YES";
static char fzgx_pool_sYesJp[8] = "\x82\xCD\x82\xA2";
static char *fzgx_pool_sEraseYes[6] = {0};
static char fzgx_pool_sNoEn[4] = "NO";
static char fzgx_pool_sNoGe[8] = "GER NO";
static char fzgx_pool_sNoFr[8] = "FRE NO";
static char fzgx_pool_sNoSp[8] = "SPA NO";
static char fzgx_pool_sNoIt[8] = "ITA NO";
static char fzgx_pool_sNoJp[8] = "\x82\xA2\x82\xA2\x82\xA6";
static char *fzgx_pool_sEraseNo[6] = {0};
#pragma explicit_zero_data reset

/* Literal-pool primer: reproduces the order of the TU's shared .rodata pool. */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_fn_10_261E4(s32 x) {
    s16 t0[14] = {0xB5, 0xB6, 0xAD, 0xB3, 0xB8, 0xB2, 0xB1, 0xAE, 0xB4, 0xB9, 0xB0, 0xAF, 0xB7, -1};
    s16 t1[14] = {0xB5, 0xB6, 0xAD, 0xB3, 0xB8, 0xB2, 0xB1, 0xAE, 0xB4, 0xB9, 0xB0, 0xAF, 0xB7, -1};
    fzgx_pool_use(t0);
    fzgx_pool_use(t1);
    fzgx_pool_use(fzgx_pool_sEraseQuestion);
    fn_1_4955C(320.0f, 240.0f);
    fn_1_4955C(0.1f, 400.0f);
    fn_1_4955C(200.0f, 13.0f);
    fn_1_4955C(26.0f, 1.5f);
    fn_1_4955C(0.75f, 0.09f);
    fn_1_4955C(0.5f, -1.0f);
    fn_1_4955C(8.0f, 0.0f);
    fn_1_4954C(x);
}

void fn_10_261E4(s32 arg0, u8 arg1) {
    Color col = fn_800081C8((Color){0xA0, 0x50, 0x50, 0x00}, (Color){0xA0, 0xA0, 0xA0, 0x00}, 1.0f);

    fn_1_49410();
    fn_1_4955C(0.75f, 0.75f);
    fn_1_4954C(0.09f);
    fn_1_495C8(9);
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_496FC(288.0f, arg0);
    fn_1_495C8(10);
    if (!arg1) {
        fn_1_4D494();
        fn_1_49514((Color){0xFF, 0xFF, 0xFF, 0x00});
        fn_1_4AE0C("%s", fzgx_pool_sEraseYes[(*(u32 *)&lbl_801A66B4)]);
        fn_1_4D4C8(col, 0.09f, 10.0f);
    } else {
        fn_1_49514((Color){0x70, 0x70, 0x70, 0x00});
        fn_1_49528((Color){0x00, 0x00, 0x00, 0x00});
        fn_1_4AE0C("%s", fzgx_pool_sEraseYes[(*(u32 *)&lbl_801A66B4)]);
    }
    fn_1_496FC(352.0f, arg0);
    fn_1_495C8(8);
    if (!arg1) {
        fn_1_49514((Color){0x70, 0x70, 0x70, 0x00});
        fn_1_49528((Color){0x00, 0x00, 0x00, 0x00});
        fn_1_4AE0C("%s", fzgx_pool_sEraseNo[(*(u32 *)&lbl_801A66B4)]);
    } else {
        fn_1_4D494();
        fn_1_49514((Color){0xFF, 0xFF, 0xFF, 0x00});
        fn_1_4AE0C("%s", fzgx_pool_sEraseNo[(*(u32 *)&lbl_801A66B4)]);
        fn_1_4D4C8(col, 0.09f, 10.0f);
    }
}
/* fzgx:end fn_10_261E4 */

/* fzgx:begin fn_10_26424 */
void fn_10_26424(void) {
    lbl_10_bss_55CE2 = 1;
}
/* fzgx:end fn_10_26424 */

/* fzgx:begin fn_10_26434 noprologue */
#include "types.h"

extern u16 lbl_1_bss_9F8[5];

typedef struct SelState {
    u8 pad0[8];
    u16 flags8;
    u8 padA[6];
    u16 flags10;
    u16 flags12;
} SelState;


extern u8 lbl_10_bss_55CE2;
extern void fn_1_A2D84(int arg);

int fn_10_26434(void) {
    if (((*(SelState *)&lbl_1_bss_9F8).flags10 & 1) ||
        ((*(SelState *)&lbl_1_bss_9F8).flags12 & 1)) {
        if (lbl_10_bss_55CE2 == 1) {
            lbl_10_bss_55CE2 = 0;
            fn_1_A2D84(0xA9011300);
        }
    }

    if (((((*(SelState *)&lbl_1_bss_9F8).flags10 >> 1) & 1)) ||
        ((((*(SelState *)&lbl_1_bss_9F8).flags12 >> 1) & 1))) {
        if (lbl_10_bss_55CE2 == 0) {
            lbl_10_bss_55CE2 = 1;
            fn_1_A2D84(0xA9011300);
        }
    }

    if ((((*(SelState *)&lbl_1_bss_9F8).flags8 >> 8) & 1)) {
        fn_1_A2D84(0xA9011100);
        if (lbl_10_bss_55CE2 == 0) {
            return 1;
        }
        if (lbl_10_bss_55CE2 == 1) {
            return 2;
        }
    }

    if ((((*(SelState *)&lbl_1_bss_9F8).flags8 >> 9) & 1)) {
        fn_1_A2D84(0xA9011000);
        return 2;
    }

    return 0;
}
/* fzgx:end fn_10_26434 */
