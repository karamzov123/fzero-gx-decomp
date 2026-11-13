#include "types.h"
#include "rel/sel/globals.h"

extern int fn_1_152970(int, int, int, int, struct Fn10Data *, int, int);
extern u32 lbl_10_bss_49384;
extern void fn_1_435C(u32);
extern void fn_1_407C(void);
extern void fn_1_3CC4(void);
extern int fn_1_4C10(void);
extern struct Fn10834State lbl_1_bss_8B3A0;
extern struct Fn10834Status lbl_1_bss_962;
extern u16 lbl_1_bss_968;
extern void fn_10_CFDC(void);
extern void fn_1_12C060(void *);
extern void fn_1_A266C(void);
extern u32 lbl_10_bss_14;
extern struct Fn10834Event lbl_1_bss_9C;
extern u8 lbl_1_bss_8CA28;
extern void fn_1_A2D84(u32);

/* fzgx:begin fn_10_0 */
#include "types.h"


extern int fn_1_152970(int, int, int, int, struct Fn10Data *, int, int);

struct Fn10Data {
    u8 pad[0x18];
    s16 value_18;
    s16 value_1a;
};

s16 fn_10_0(int first, int second, int third, int fourth) {
    return (s16)fn_1_152970(second, first, third, fourth,
        (struct Fn10Data *)((u8 *)&(*(struct Fn10Data *)&lbl_10_bss_0) + 0x1c),
        (*(struct Fn10Data *)&lbl_10_bss_0).value_1a, (*(struct Fn10Data *)&lbl_10_bss_0).value_18);
}
/* fzgx:end fn_10_0 */

/* fzgx:begin _prolog noprologue */
#include "types.h"

typedef struct {
    u8 pad_0[0x58];
    void *value;
} SelArcInfo;

typedef struct {
    u8 pad_0[0x324];
    s32 unk_324;
    u8 pad_328[0x440 - 0x328];
} SelCarEntry;

typedef struct {
    u8 pad_0[0x2];
    s16 car;
    u8 pad_4[0x4];
    u8 unk_8;
    u8 pad_9[0x17];
} SelPlayer;

typedef struct {
    s16 unk_0;
    u8 pad_2[0x2];
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
    s16 unk_A;
    SelPlayer players[4];
    s16 unk_8C;
    s16 unk_8E;
    s16 unk_90;
    u8 pad_92[0x2];
    u32 unk_94;
    u32 unk_98;
    u8 pad_9C[0x2];
    u8 unk_9E;
    u8 unk_9F[4];
    u8 pad_A3[0x1];
    s16 *unk_A4;
    u8 pad_A8[0x81];
    u8 unk_129;
    u8 unk_12A;
    u8 unk_12B;
    u8 pad_12C[0x14];
    u8 unk_140[0xC];
} SelState;

typedef struct {
    u32 unk_0;
    u8 unk_4;
} SelLight;

extern SelState lbl_1_bss_8B3A0;
extern volatile u32 lbl_1_bss_8B5F4[8];  /* fzgx-allow: S2 handle slots: fn_10_C654 callbacks queued through fn_1_46B44 write them later */
extern s16 lbl_1_bss_960;
extern s16 lbl_1_bss_96A;
extern SelLight lbl_1_bss_970;
extern s16 lbl_1_bss_8CA26;
extern void *lbl_1_bss_7167C;
extern void *lbl_1_bss_71680;
extern void *lbl_1_bss_71684;
extern u32 lbl_801A6410;

extern void fn_10_C654(void *);
extern void fn_10_C5E0(void *);
extern void fn_10_5780(SelState *);
extern void fn_10_834(void);
extern void fn_10_AB8(void);
extern void fn_10_CF50(void);
extern s32 fn_1_45730(const char *, SelArcInfo *);
extern void OSPanic(const char *, int, const char *, ...);
extern void *fn_1_45B2C(SelArcInfo *);
extern void fn_1_45850(SelArcInfo *);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_A0680(void);
extern void *fn_1_4630(u32, u32, const char *, s32);
extern void *fn_1_45D0(u32, u32, const char *, s32);
extern u32 fn_1_7BA08(u16, u16, u16);
extern void fn_1_7BA48(void *);
extern void fn_1_3CF0(void *, u32);
extern void fn_1_5124(void *, void *);
extern void fn_1_411A4(u32);
extern void fn_1_48418(int);
extern void fn_1_479F0(s16);
extern void fn_1_469BC(void);
extern void fn_1_4706C(void);
extern void fn_1_46A60(void);
extern void fn_1_159440(int, int);
extern void fn_1_47F74(s32);
extern void fn_1_52070(u32);
extern u32 fn_1_4404(void);
extern u32 fn_800090A4(u32);
extern void fn_1_46BA0(void *, u32);
extern u32 fn_1_46ED8(void);
extern void fn_1_46A8C(u32);
extern void fn_1_465D0(const char *, s32);
extern void fn_1_46B44(void *, volatile void *);  /* fzgx-allow: S2 the queued callback writes its argument later (the two handle slots below) */
extern void fn_1_41104(u32);
extern void fn_1_47E54(s32);
extern void fn_1_46BFC(void);
extern void fn_80008E84(u32);
extern void fn_8006CE1C(f32);
extern void fn_1_435C(void *);
extern void fn_1_3F8C(const char *, void *, void *, u32);
extern void fn_1_7BAF8(void);
extern void fn_1_A5330(u8, s16);
extern s16 fn_1_12EF24(s16, s16);
extern s16 fn_1_8D7C8(void);
extern void fn_1_12F17C(void);
extern void fn_1_36ADC(void);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
void *fzgx_obj_lbl_10_bss_0;
void *fzgx_obj_lbl_10_bss_4;
u8 fzgx_pool_gap_8[4];
u8 lbl_10_bss_0__fzgx_offset_C;
u8 fzgx_pool_gap_D;
u16 fzgx_pool_gap_E;
u32 fzgx_obj_lbl_10_bss_10;
u32 fzgx_obj_lbl_10_bss_14;
s16 fzgx_obj_lbl_10_bss_18;
s16 fzgx_obj_lbl_10_bss_1A;
u8 fzgx_obj_lbl_10_bss_1C[0x3A4];
u8 fzgx_obj_lbl_10_bss_3C0[0x48FC0];
SelCarEntry *fzgx_obj_lbl_10_bss_49380;
void *fzgx_obj_lbl_10_bss_49384;
void *fzgx_obj_lbl_10_bss_49388;
s16 fzgx_obj_lbl_10_bss_4938C;
u8 fzgx_obj_lbl_10_bss_4938E;
u8 fzgx_obj_lbl_10_bss_4938F;
u8 fzgx_obj_lbl_10_bss_49390;
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_10_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_4;
    s = *(u8 *)&fzgx_pool_gap_8;
    s = *(u8 *)&lbl_10_bss_0__fzgx_offset_C;
    s = *(u8 *)&fzgx_pool_gap_D;
    s = *(u8 *)&fzgx_pool_gap_E;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_10;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_14;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_1A;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_1C;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_3C0;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_49380;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_49384;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_49388;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_4938C;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_4938E;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_4938F;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_49390;
}
#pragma section code_type ".text"

/* the retail TU's .data objects this function uses, at their retail offsets */
u32 fzgx_obj_lbl_10_data_0 = 0x4E4F4E00;
u8 fzgx_pool_gap_data_4[0x458] = {1};
u32 fzgx_obj_lbl_10_data_45C = 0x40000000;
u8 fzgx_pool_gap_data_460[0x118] = {1};
void *volatile fzgx_obj_lbl_10_data_578 = (void *)0xFFFFFFFF;  /* fzgx-allow: S2,A2 heap handle, -1 means no heap: fn_10_C5E0 (queued through fn_1_46B44) frees the heap and writes -1 here */
char fzgx_obj_lbl_10_data_57C[8] = "sel.c";
char fzgx_pool_gap_data_584[0x18] = "Wrong CarMap col row\n";

#pragma section code_type ".fzgxpool"
static void fzgx_data_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .data objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_10_data_0;
    s = *(u8 *)&fzgx_pool_gap_data_4;
    s = *(u8 *)&fzgx_obj_lbl_10_data_45C;
    s = *(u8 *)&fzgx_pool_gap_data_460;
    s = *(u8 *)&fzgx_obj_lbl_10_data_578;
    s = *(u8 *)&fzgx_obj_lbl_10_data_57C;
    s = *(u8 *)&fzgx_pool_gap_data_584;
}
#pragma section code_type ".text"

static inline void sel_reset_players(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        lbl_1_bss_8B3A0.players[i].car = -1;
        lbl_1_bss_8B3A0.unk_9F[i] = 50;
        fn_1_A5330(50, i);
    }
}

void _prolog(void) {
    SelArcInfo info;
    SelState *state;
    u32 heap;
    u32 size;
    s16 i;

    if (lbl_1_bss_8B3A0.unk_A != -1) {
        lbl_1_bss_8B3A0.unk_8 = lbl_1_bss_8B3A0.unk_A;
    }
    state = &lbl_1_bss_8B3A0;
    state->unk_9E = 0;
    state->unk_94 &= ~0x200;
    if (!(state->unk_94 & 0x40000000)) {
        state->unk_94 |= 0x100;
    }
    if (fn_1_45730("vehicle/vehicle_sel.arc.lz", &info) == 0) {
        OSPanic(fzgx_obj_lbl_10_data_57C, 0x298, "vehicle archive file is nothing");
    }
    fzgx_obj_lbl_10_bss_10 = ((u32)fn_1_45B2C(&info) + 0x1F) & ~0x1F;
    fn_1_45850(&info);
    lbl_1_bss_8B5F4[0] = 0;
    lbl_1_bss_8B5F4[1] = 0;
    lbl_1_bss_8B5F4[2] = 0;
    lbl_1_bss_8B5F4[3] = 0;
    lbl_1_bss_8B5F4[4] = 0;
    lbl_1_bss_8B5F4[5] = 0;
    lbl_1_bss_8B5F4[6] = 0;
    lbl_1_bss_8B5F4[7] = 0;
    fn_80008BEC(fzgx_obj_lbl_10_bss_3C0, 0, sizeof(fzgx_obj_lbl_10_bss_3C0));
    fn_1_A0680();
    fzgx_obj_lbl_10_bss_4 = fn_1_4630(lbl_801A6410, 0xC24, fzgx_obj_lbl_10_data_57C, 0x2A9);
    fzgx_obj_lbl_10_bss_49380 = fn_1_4630(lbl_801A6410, 41 * sizeof(SelCarEntry), fzgx_obj_lbl_10_data_57C, 0x2AA);
    for (i = 0; i < 41; i++) {
        fzgx_obj_lbl_10_bss_49380[i].unk_324 = -1;
    }
    fzgx_obj_lbl_10_bss_0 = fn_1_45D0(lbl_801A6410, fn_1_7BA08(32, 32, 64), fzgx_obj_lbl_10_data_57C, 0x2AC);
    fn_1_7BA48(fzgx_obj_lbl_10_bss_0);
    fzgx_obj_lbl_10_bss_49384 = fn_1_45D0(lbl_801A6410, 0x173C, fzgx_obj_lbl_10_data_57C, 0x2AD);
    fn_1_3CF0(fzgx_obj_lbl_10_bss_49384, 0x80);
    fzgx_obj_lbl_10_bss_49388 = fn_1_45D0(lbl_801A6410, 0x173C, fzgx_obj_lbl_10_data_57C, 0x2AE);
    fn_1_3CF0(fzgx_obj_lbl_10_bss_49388, 0x80);
    fn_1_5124(fzgx_obj_lbl_10_bss_49384, fzgx_obj_lbl_10_bss_49388);
    fn_1_411A4(1);
    if (state->unk_94 & 0x40000000) {
        fn_1_48418(2);
        fn_1_479F0(lbl_1_bss_960);
        fn_1_469BC();
        fn_1_4706C();
        fn_1_46A60();
        fn_1_159440(1, 0);
        fn_1_159440(2, 0);
        fn_1_159440(3, 0);
    } else if (state->unk_94 & 0x02000000) {
        fn_1_47F74(0x9A);
        fn_1_47F74(0x9B);
        fn_1_47F74(0x30);
    } else {
        fn_1_48418(2);
        fn_1_47F74(0x9A);
        fn_1_47F74(0x9B);
        fn_1_47F74(0x9D);
        fn_1_47F74(0xA1);
        fn_1_47F74(0x9C);
        fn_1_47F74(0xA2);
        fn_1_469BC();
        fn_1_4706C();
        fn_1_46A60();
        fn_1_159440(2, 1);
    }
    fn_1_52070(0x140);
    if (!(state->unk_94 & 0x02000000) && !(state->unk_94 & 0x80000000)) {
        heap = fn_1_4404();
        size = fn_800090A4(lbl_801A6410) - 0x10000;
        fzgx_obj_lbl_10_data_578 = fn_1_45D0(lbl_801A6410, size, fzgx_obj_lbl_10_data_57C, 0x2ED);
        fn_1_46BA0(fzgx_obj_lbl_10_data_578, size);
        fn_1_46A8C((fn_1_46ED8() & ~0x1F) - fzgx_obj_lbl_10_bss_10);
        fn_1_465D0("vehicle/vehicle_sel.arc.lz", 2);
        fn_1_46B44(fn_10_C654, lbl_1_bss_8B5F4);
        if (!(state->unk_94 & 0x20)) {
            fn_1_41104(1);
            fn_1_41104(6);
            fn_1_47E54(0x9A);
            fn_1_47E54(0x9B);
            fn_1_47E54(0xBA);
            fn_1_47E54(0xA0);
        }
        fn_1_46BFC();
        lbl_10_bss_0__fzgx_offset_C = 1;
        fn_1_46B44(fn_10_C5E0, &fzgx_obj_lbl_10_data_578);
        fn_80008E84(heap);
    }
    lbl_1_bss_970.unk_0 = 0;
    lbl_1_bss_970.unk_4 = 13;
    fn_8006CE1C(0.0f);
    fn_1_435C(fzgx_obj_lbl_10_bss_49388);
    fn_1_3F8C("LightMain", fn_1_7BAF8, fzgx_obj_lbl_10_bss_0, 2);
    lbl_1_bss_8B3A0.unk_129 = 1;
    lbl_1_bss_8B3A0.unk_A4 = fzgx_obj_lbl_10_bss_4;
    if (!(state->unk_94 & 0x30)) {
        lbl_1_bss_8B3A0.unk_0 = -1;
    }
    state->unk_94 &= ~0x08000000;
    state->unk_94 &= ~0x04000000;
    state->unk_94 &= ~0x01000000;
    state->unk_94 &= ~0x00200000;
    state->unk_94 &= ~0x00100000;
    state->unk_94 &= ~0x00080000;
    state->unk_94 &= ~0x80;
    state->unk_94 &= ~0x40;
    if (state->unk_94 & 0x40000000) {
        s16 mode;

        mode = 0x1A;
        if (state->unk_94 & 0x2000) {
            mode = 0x16;
        }
        lbl_1_bss_96A = mode;
        for (i = 0; i < 4; i++) {
            lbl_1_bss_8B3A0.unk_9F[i] = 50;
            fn_1_A5330(50, i);
        }
        lbl_1_bss_8B3A0.unk_0 = 9;
        lbl_1_bss_8B3A0.unk_4 = 1;
        lbl_1_bss_8B3A0.unk_6 = 30;
        lbl_1_bss_8B3A0.unk_8 = 1;
        sel_reset_players();
        lbl_1_bss_8B3A0.players[0].car = 6;
        lbl_1_bss_8B3A0.unk_8C = 6;
        lbl_1_bss_8B3A0.unk_8E = 0;
        lbl_1_bss_8B3A0.unk_90 = fn_1_12EF24(6, 0);
        lbl_1_bss_8B3A0.unk_12A = 1;
        lbl_1_bss_8B3A0.unk_12B = 0;
        lbl_1_bss_8CA26 = 0;
        fzgx_obj_lbl_10_bss_18 = 0x13;
        fzgx_obj_lbl_10_bss_1A = 2;
        fzgx_obj_lbl_10_bss_4938C = 0xF;
    } else {
        lbl_1_bss_96A = 0xE;
        fzgx_obj_lbl_10_bss_18 = 0x13;
        fzgx_obj_lbl_10_bss_1A = 6;
        fzgx_obj_lbl_10_bss_4938C = 0xF;
        if (state->unk_94 & 0x20) {
            lbl_1_bss_96A = 0xF;
        } else if (state->unk_94 & 0x10) {
            lbl_1_bss_96A = 0x10;
        } else {
            *lbl_1_bss_8B3A0.unk_A4 = -1;
            fn_10_5780(&lbl_1_bss_8B3A0);
        }
    }
    if ((state->unk_94 & 0x40000000) || (state->unk_94 & 0x02000000)) {
        state->unk_94 |= 0x20000000;
    }
    lbl_1_bss_8B3A0.unk_98 = 0;
    lbl_1_bss_8B3A0.unk_98 |= 0x80000000 >> state->unk_9E;
    fzgx_obj_lbl_10_bss_4938E = fn_1_8D7C8() < 30 ? fn_1_8D7C8() : 30;
    lbl_1_bss_7167C = fn_10_834;
    lbl_1_bss_71680 = fn_10_AB8;
    lbl_1_bss_71684 = fn_10_CF50;
    if (state->unk_94 & 0x02000000) {
        s16 player = state->unk_9E;

        lbl_1_bss_8B3A0.unk_0 = 4;
        lbl_1_bss_8B3A0.unk_4 = 1;
        lbl_1_bss_8B3A0.unk_6 = 1;
        for (i = 0; i < 4; i++) {
            lbl_1_bss_8B3A0.players[i].car = -1;
        }
        lbl_1_bss_8B3A0.players[player].car = 6;
        lbl_1_bss_8B3A0.players[player].unk_8 = 1;
        lbl_1_bss_8B3A0.unk_9F[player] = 50;
        lbl_1_bss_8B3A0.unk_90 = 1;
        lbl_1_bss_8B3A0.unk_8C = 1;
        lbl_1_bss_8B3A0.unk_8E = 0;
        fn_1_A5330(50, player);
        fzgx_obj_lbl_10_data_45C = 0x80000000;
        lbl_1_bss_96A = 0x12;
    }
    fn_1_12F17C();
    fn_1_36ADC();
    fn_80008BEC(lbl_1_bss_8B3A0.unk_140, 0, sizeof(lbl_1_bss_8B3A0.unk_140));
    fzgx_obj_lbl_10_bss_49390 = 0;
    fzgx_obj_lbl_10_bss_4938F = 0;
}
/* fzgx:end _prolog */

/* fzgx:begin fn_10_834 */
struct Fn10834State {
    u8 pad_0[0x94];
    u32 flags;
    u8 pad_98[0xC];
    u32 entries;
    u8 pad_A8[0x7C];
    u32 countdown;
    u8 ready;
    u8 pad_129[0x17];
    u32 mode;
};
struct Fn10834Status { s16 value; };
struct Fn10834Event {
    u8 pad_0[2];
    u8 value_2;
    u8 pad_3[1];
    u16 value_4;
    u8 pad_6[2];
    u32 value_8;
};

void fn_10_834(void) {
    struct Fn10834State *state;
    u8 *entry;
    s16 i;

    fn_10_CFDC();
    lbl_1_bss_8CA28 = 0;
    if ((lbl_1_bss_8B3A0.countdown + 0x10000) != 65535 &&
        lbl_1_bss_8B3A0.ready == 0) {
        lbl_1_bss_8B3A0.countdown -= 1;
    }

    state = &lbl_1_bss_8B3A0;
    if (((state->flags >> 11) & 1) == 0 && lbl_1_bss_8B3A0.countdown <= 300) {
        if (lbl_1_bss_8B3A0.countdown % 60 == 0 && lbl_1_bss_8B3A0.countdown != 0 &&
            (s32)fn_1_4C10() == 0) {
            fn_1_A2D84(0xA9010C00);
        }
    }
    if ((s32)lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }

    {
        int active;
        if ((lbl_1_bss_8B3A0.mode & 0x80000000) != 0 &&
            (lbl_1_bss_8B3A0.mode & 0x40000000) == 0 &&
            (state->flags & 0x8) == 0) {
            active = 1;
        } else {
            if (fn_1_4C10()) active = 1;
            else active = 0;
        }
        if (active == 0) {
            entry = (u8 *)lbl_1_bss_8B3A0.entries +
                (s16)(lbl_1_bss_962.value - 14) * 148;
            for (i = 0; i < 4; i++) {
                fn_1_12C060(entry + 36);
                entry += 28;
            }
            if (lbl_1_bss_962.value != 20) {
                if ((s32)fn_1_4C10() == 0) {
                    if ((state->flags & 0x8000000) != 0) {
                        if ((state->flags & 0x200000) != 0) {
                            lbl_1_bss_9C.value_2 = lbl_1_bss_8B3A0.pad_0[0x9e];
                            lbl_1_bss_9C.value_4 = 6;
                            lbl_1_bss_9C.value_8 = 134;
                            lbl_1_bss_968 = 9;
                        } else if ((state->flags & 0x100000) != 0) {
                            lbl_1_bss_968 = 3;
                        } else if ((state->flags & 0x80000) != 0) {
                            lbl_1_bss_968 = 5;
                        } else if ((state->flags & 0x80) != 0) {
                            lbl_1_bss_968 = 12;
                        } else if ((state->flags & 0x40) != 0) {
                            lbl_1_bss_968 = 15;
                        } else {
                            lbl_1_bss_968 = 2;
                        }
                    } else if ((state->flags & 0x4000000) != 0) {
                        lbl_1_bss_968 = 10;
                    } else if ((state->flags & 0x1000000) != 0) {
                        lbl_1_bss_968 = 9;
                    }
                }
                fn_1_A266C();
            }
        }
    }
}
/* fzgx:end fn_10_834 */

/* fzgx:begin fn_10_AB8 */
void fn_10_AB8(void) {
    fn_1_435C(lbl_10_bss_49384);
    fn_1_407C();
    fn_1_3CC4();
    fn_1_435C(lbl_10_bss_49388);
    fn_1_407C();
}
/* fzgx:end fn_10_AB8 */
