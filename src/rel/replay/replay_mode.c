#include "types.h"

/* replay_mode.c: the replay scene (fze.replay.rel, one translation unit) */

typedef struct GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

/* one racer of the replay (12 bytes) */
typedef struct ReplayRacer {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6[5];
    u8 unk_B;
} ReplayRacer;

/* one machine slot of lbl_1_bss_26B80 (5 bytes) */
typedef struct ReplaySlot {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
} ReplaySlot;

/* one ghost buffer (0x81C0 bytes) */
typedef struct ReplayGhost {
    u8 unk_0[4];
    u8 unk_4[0x81BC];
} ReplayGhost;

typedef struct ReplayEntry {
    u32 a : 15;
    u32 c : 3;
    u32 d : 5;
    u32 e : 5;
    u32 pad0 : 4;
    u32 b : 15;
    u32 f : 5;
    u32 g : 5;
    u32 h : 5;
    u32 pad1 : 2;
    Vec3 pos[4];
    Vec3 rot[4];
    Vec3 v68;
    Vec3 v74;
} ReplayEntry;

typedef struct ReplayData {
    u8 pad0[0xA0];
    u16 count;
    u16 padA2;
    u8 rec[(0xFEF0 - 0xA4) / 7][7];
    u16 numEntries;
    u8 padF2[0x5A];
    ReplayEntry entries[1];
} ReplayData;

typedef struct ReplayState {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0xC];
    u8 unk_18;
    u8 pad_19[0x1F];
    u8 unk_38[4];
    u8 unk_3C[4];
    ReplayData *unk_40;
} ReplayState;

typedef struct ReplayRace {
    u8 pad_0[0x8];
    u16 unk_8;
} ReplayRace;

typedef struct SystemCursor {
    u32 unk_0;
    u8 unk_4;
} SystemCursor;

/* the menu panel template of lbl_1_rodata_26F8 (0x58 bytes) */
typedef struct PanelTemplate {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x20];
    u32 unk_30;
    u8 pad_34[0x24];
} PanelTemplate;

typedef struct ReplayScene {
    char *name;
    void (*init)(void);
    void (*main)(void);
    void (*disp)(void);
} ReplayScene;

typedef struct ReplayCallbacks {
    u8 pad_0[0xAC];
    u32 unk_AC;
    u8 pad_B0[0x1C];
    u32 unk_CC;
} ReplayCallbacks;

extern ReplayState lbl_1_bss_7EFD8;
extern ReplayRace lbl_1_bss_8B3A0;
extern ReplaySlot lbl_1_bss_26B80[];
extern u32 lbl_801A63C0;
extern u32 lbl_801A63D0;
extern u32 lbl_801A6410;
extern u32 lbl_801A66B4;
extern void (*lbl_1_bss_7167C)(void);
extern void (*lbl_1_bss_71680)(void);
extern void (*lbl_1_bss_71684)(void);
extern void (*lbl_1_bss_71688)(void);
extern void (*lbl_1_bss_7168C)(void);
extern void (*lbl_1_bss_26C60)(void);
extern u16 lbl_1_bss_96A;
extern s16 lbl_1_bss_968;
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_960;
extern SystemCursor lbl_1_bss_970;
extern u32 *lbl_1_bss_6EAD0;
extern u32 lbl_1_bss_6EAB4;
extern const PanelTemplate lbl_1_rodata_26F8;

extern u32 fn_1_F453C(u32 stream, u32 *pos, u32 bits);
extern ReplayGhost *fn_1_36AD0(void);
extern void fn_1_F47A0(u32);
extern void fn_1_F4794(u16 count);
extern void fn_80008BA8(void *dst, void *src, u32 size);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_12F10C(ReplayGhost *);
extern void fn_1_3EF8C(int);
extern void fn_1_3ED8C(int, u8, int, u8, int, u8, int);
extern void fn_1_3EB78(int, u8 *, u8 *, int);
extern void fn_1_3EC88(int, void *);
extern void fn_1_3EFF0(void *, int);
extern void fn_1_3FCB0(s32);
extern void fn_1_3FCD4(s32);
extern void fn_1_3EF14(void *header);
extern u32 fn_1_D0790(void);
extern void fn_1_A8F78(void);
extern u32 fn_1_3F038(void);
extern u32 fn_1_45D0(u32, u32, const char *, s32);
extern void fn_1_3CF0(u32, u32);
extern void fn_1_49F0(GXColor color);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_154708(u32);
extern void fn_1_154CC4(u32);
extern void fn_1_411A4(u32);
extern void fn_1_479F0(s16);
extern void fn_1_A0680(void);
extern void fn_1_A1588(u32, u32);
extern void fn_1_48418(u32);
extern void fn_1_159440(u32, u32);
extern void fn_1_133DBC(void *);
extern u32 fn_1_134AD4(void);
extern void fn_1_4F734(void *);
extern void fn_1_1380F0(char *);
extern void fn_1_13ABA8(u32);
extern u32 fn_1_435C(u32);
extern void fn_1_407C(void);
extern s32 fn_1_154C84(void);
extern u8 fn_1_154E24(void);
extern int fn_1_4C10(void);
extern void fn_1_3CC4(void);
extern void fn_1_1596DC(u32);
extern u32 fn_1_484CC(u32);
extern void fn_1_A0AA4(u32);
extern void fn_1_47A60(s16);
extern void fn_1_412A0(u32);
extern u32 fn_1_154D84(u32);
extern void fn_1_1547FC(u32);
extern void fn_1_41A8(void);
extern void fn_1_46B4(u32, u32, const char *, int);

void fn_13_A6C(ReplayCallbacks *callbacks);
void fn_13_AFC(void);
void fn_13_B00(void);
void fn_13_B08(void);
void fn_13_B64(void);
void fn_13_B78(void);
void fn_13_B7C(void);
void fn_13_BCC(void);
void fn_13_CDC(void);
void fn_13_E8C(void);
void fn_13_EF0(void);
void fn_13_F00(void);
void fn_13_FA8(void);

/* fzgx:begin fn_13_0 */
u32 lbl_13_bss_0;
u32 lbl_13_bss_4;
ReplayRacer lbl_13_bss_8[4];
u32 lbl_13_bss_38;
u8 lbl_13_bss_3C;
s32 lbl_13_bss_40;
u32 lbl_13_bss_44;
s8 lbl_13_bss_48;
u32 lbl_13_bss_4C;
s32 lbl_13_bss_50;
u8 lbl_13_bss_54[10];

/* WARNING: compiler-diff device, not original code: #pragma opt_dead_assignments off (as main has it).
   Without it the racer index idx becomes a compiler temporary and takes r31. */
#pragma opt_dead_assignments off
void fn_13_0(void) {
    /* WARNING: compiler-diff device, not original code: fzgx_value holds the machine id for one store */
    u8 fzgx_value;
    u8 idx;
    u32 count;
    u32 i;
    int n;
    u32 t2;
    u8 unk22;
    u8 flag;
    u8 ver;
    int k;
    u32 j;
    /* WARNING: compiler-diff device, not original code: one-field carrier of the ghost byte */
    struct { u8 value; } b;
    u8 locC[4];
    u8 loc8[4];
    ReplayRacer *e;
    u8 *src;
    lbl_13_bss_0 = lbl_801A63D0;
    lbl_13_bss_4 = 0;
    fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 8);
    ver = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 7);
    t2 = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 6);
    fn_1_F47A0(fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 32));
    lbl_801A63C0 = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 32);
    count = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 5);
    lbl_1_bss_8B3A0.unk_8 = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 3);
    fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 2);
    flag = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 1);
    unk22 = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 7);
    n = 0;
    for (i = 0; i < count; i++) {
        lbl_1_bss_26B80[i].unk_0 = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 1);
        lbl_1_bss_26B80[i].unk_1 = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 6);
        if (ver >= 3) {
            lbl_1_bss_26B80[i].unk_4 = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 5);
        }
        if (ver >= 2) {
            lbl_1_bss_26B80[i].unk_3 = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 7);
        }
        if (lbl_1_bss_26B80[i].unk_0 != 0) {
            lbl_1_bss_26B80[i].unk_2 = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 2);
            if (ver < 2) {
                lbl_1_bss_26B80[i].unk_3 = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 7);
            }
            idx = (u8)n;
            locC[idx] = lbl_1_bss_26B80[i].unk_1;
            loc8[idx] = lbl_1_bss_26B80[i].unk_2;
            if ((u8)fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 1) != 0) {
                for (j = 0; j < 0x81C0; j++) {
                    b.value = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 8);
                    ((u8 *)&fn_1_36AD0()[i])[j] = b.value;
                }
                src = fn_1_36AD0()[i].unk_4;
                fn_80008BA8(&lbl_13_bss_8[idx], src, 0xC);
                fn_1_12F10C(fn_1_36AD0());
            } else {
                e = &lbl_13_bss_8[idx];
                fzgx_value = lbl_1_bss_26B80[i].unk_1;
                e->unk_1 = fzgx_value;
                e->unk_2 = 1 << lbl_1_bss_26B80[i].unk_2;
                e->unk_B = lbl_1_bss_26B80[i].unk_3;
                e->unk_4 = 0;
                e->unk_3 = 0;
                e->unk_5 = 0;
                e->unk_0 = 0;
                fn_80008BEC(lbl_13_bss_8[i].unk_6, 0x41, 5);
            }
            n++;
        } else {
            lbl_1_bss_26B80[i].unk_2 = 0;
            lbl_1_bss_26B80[i].unk_3 = 0;
        }
    }
    if (ver >= 4) {
        for (k = 0; k < (u8)n; k++) {
            lbl_1_bss_7EFD8.unk_3C[k] = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 1);
        }
    }
    for (k = 0; k < (u8)n; k++) {
        lbl_1_bss_7EFD8.unk_38[k] = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 2) + 1;
    }
    if (ver >= 5) {
        lbl_1_bss_7EFD8.unk_8 = fn_1_F453C(lbl_13_bss_0, &lbl_13_bss_4, 20);
    }
    fn_1_3EF8C(6);
    fn_1_3ED8C(0, unk22, 1, t2, 10, count, 0);
    fn_1_3EB78(n, locC, loc8, 0);
    fn_1_3EC88(n, lbl_13_bss_8);
    fn_1_3EFF0(fn_13_A6C, 1);
    if (flag != 0) {
        fn_1_3FCB0(0x20000);
    } else {
        fn_1_3FCD4(0x20000);
    }
    fn_1_3FCB0(0x800000);
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_13_0 */

/* fzgx:begin fn_13_3FC */
static inline u32 replay_read(u32 bits) {
    u32 *pos = &lbl_13_bss_4;
    return fn_1_F453C(lbl_13_bss_0, pos, bits);
}

static inline f32 replay_read_f32(void) {
    u32 raw;
    f32 value;
    raw = replay_read(32);
    fn_80008BA8(&value, &raw, 4);
    return value;
}

#define REPLAY (lbl_1_bss_7EFD8.unk_40)

void fn_13_3FC(void) {
    u8 header[0x14B8];
    s32 i;
    s32 j;

    fn_1_3EF14(header);
    REPLAY->numEntries = replay_read(8);
    lbl_1_bss_7EFD8.unk_18 = header[8];
    for (i = 0; i < REPLAY->numEntries; i++) {
        REPLAY->entries[i].a = replay_read(14);
        REPLAY->entries[i].b = replay_read(14);
        REPLAY->entries[i].c = replay_read(4);
        REPLAY->entries[i].d = replay_read(5);
        REPLAY->entries[i].e = replay_read(5);
        REPLAY->entries[i].f = replay_read(5);
        REPLAY->entries[i].g = replay_read(5);
        REPLAY->entries[i].h = replay_read(5);
        for (j = 0; j < lbl_1_bss_7EFD8.unk_18; j++) {
            REPLAY->entries[i].pos[j].x = replay_read_f32();
            REPLAY->entries[i].pos[j].y = replay_read_f32();
            REPLAY->entries[i].pos[j].z = replay_read_f32();
            REPLAY->entries[i].rot[j].x = replay_read_f32();
            REPLAY->entries[i].rot[j].y = replay_read_f32();
            REPLAY->entries[i].rot[j].z = replay_read_f32();
        }
        REPLAY->entries[i].v68.x = replay_read_f32();
        REPLAY->entries[i].v68.y = replay_read_f32();
        REPLAY->entries[i].v68.z = replay_read_f32();
        REPLAY->entries[i].v74.x = replay_read_f32();
        REPLAY->entries[i].v74.y = replay_read_f32();
        REPLAY->entries[i].v74.z = replay_read_f32();
    }
    REPLAY->count = replay_read(14);
    for (i = 0; i <= REPLAY->count; i++) {
        REPLAY->rec[i][0] = replay_read(8);
        REPLAY->rec[i][3] = replay_read(8);
        REPLAY->rec[i][4] = replay_read(7);
        REPLAY->rec[i][5] = replay_read(7);
        REPLAY->rec[i][6] = replay_read(8);
        REPLAY->rec[i][1] = replay_read(8);
        REPLAY->rec[i][2] = replay_read(8);
    }
    fn_1_F4794(REPLAY->count);
    REPLAY->count = 0;
}
/* fzgx:end fn_13_3FC */

/* fzgx:begin fn_13_A40 */
// fn_13_A40: returns a constant.
int fn_13_A40(void) {
    return 0;
}
/* fzgx:end fn_13_A40 */

/* fzgx:begin fn_13_A48 */
s32 fn_13_A48(void) {
    fn_1_D0790();
    return 0;
}
/* fzgx:end fn_13_A48 */

/* fzgx:begin fn_13_A6C */
void fn_13_A6C(ReplayCallbacks *callbacks) {
    callbacks->unk_CC = (u32)fn_13_A40;
    callbacks->unk_AC = (u32)fn_13_A48;
    lbl_13_bss_38 = 0;
}
/* fzgx:end fn_13_A6C */

/* fzgx:begin _prolog */
void _prolog(void) {
    lbl_1_bss_7167C = fn_13_AFC;
    lbl_1_bss_71680 = fn_13_B00;
    lbl_1_bss_71684 = fn_13_B08;
    lbl_1_bss_96A = 0xA7;
    fn_1_A8F78();
    lbl_13_bss_3C = 0;
}
/* fzgx:end _prolog */

/* fzgx:begin fn_13_AFC */
// fn_13_AFC: empty in retail (single blr).
void fn_13_AFC(void) {
}
/* fzgx:end fn_13_AFC */

/* fzgx:begin fn_13_B00 */
// fn_13_B00: empty in retail (single blr).
void fn_13_B00(void) {
}
/* fzgx:end fn_13_B00 */

/* fzgx:begin _epilog */
// _epilog: empty in retail (single blr).
void _epilog(void) {
}
/* fzgx:end _epilog */

/* fzgx:begin fn_13_B08 */
ReplayScene lbl_13_data_18[3] = {
    {"menu", fn_13_BCC, fn_13_CDC, fn_13_E8C},
    {"watch", fn_13_B64, fn_13_B7C, fn_13_B78},
    {"wait", fn_13_EF0, fn_13_F00, fn_13_FA8},
};

void fn_13_B08(void) {
    ReplayScene *scene = lbl_13_data_18;

    scene += lbl_1_bss_962 - 0xA7;
    lbl_1_bss_71688 = scene->main;
    lbl_1_bss_7168C = scene->disp;
    scene->init();
}
/* fzgx:end fn_13_B08 */

/* fzgx:begin fn_13_B64 */
void fn_13_B64(void) {
    lbl_1_bss_26C60 = fn_13_3FC;
}
/* fzgx:end fn_13_B64 */

/* fzgx:begin fn_13_B78 */
// fn_13_B78: empty in retail (single blr).
void fn_13_B78(void) {
}
/* fzgx:end fn_13_B78 */

/* fzgx:begin fn_13_B7C */
void fn_13_B7C(void) {
    if ((s32)fn_1_3F038() != 0) {
        lbl_13_bss_3C = 1;
        lbl_1_bss_96A = 0xA9;
        lbl_13_bss_40 = 0xA7;
    }
}
/* fzgx:end fn_13_B7C */

/* fzgx:begin fn_13_BCC */
/* The panel of the replay menu. MWCC inlines it in fn_13_CDC and the link removes this copy.
   Its float literals are made here: they are at .rodata 0x0, before the colours of fn_13_BCC. */
static void menu_panel(void) {
    PanelTemplate panel;

    panel = lbl_1_rodata_26F8;
    panel.unk_0 = 0x9604;
    panel.unk_4 = 167.0f;
    panel.unk_8 = 38.0f;
    panel.unk_C = 90.0f;
    panel.unk_30 = 10;
    fn_1_4F734(&panel);
}

void fn_13_BCC(void) {
    lbl_13_bss_44 = fn_1_45D0(lbl_801A6410, 0x173C, "replay_mode.c", 0x244);
    fn_1_3CF0(lbl_13_bss_44, 0x80);
    fn_1_A8F78();
    if (lbl_13_bss_3C != 0) {
        fn_1_49F0((GXColor){0xFF, 0xFF, 0xFF, 0xFF});
    } else {
        fn_1_49F0((GXColor){0x00, 0x00, 0x00, 0x00});
    }
    fn_1_4A00(1, 0x1E, lbl_13_bss_44);
    lbl_1_bss_970.unk_0 = 0x4B0;
    fn_1_154708(lbl_13_bss_44);
    fn_1_154CC4(0);
    fn_1_411A4(1);
    fn_1_479F0(lbl_1_bss_960);
    fn_1_A0680();
    fn_1_A1588(*lbl_1_bss_6EAD0, 0x2E);
    lbl_13_bss_48 = 0xF;
    fn_1_48418(2);
    fn_1_159440(2, 0);
}
/* fzgx:end fn_13_BCC */

/* fzgx:begin fn_13_CDC */
/* the help line of each replay menu row */
char *lbl_13_data_98[6] = {
    "Use \x83\xAD or \x83\xB5 to choose. ",
    "",
    "",
    "",
    "",
    /* "choose an item with <button> or <button>." */
    "\x83\xAD\x82\xA9\x83\xB5\x82\xC5\x8D\x80\x96\xDA\x82\xF0\x91I\x82\xF1\x82\xC5\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B",
};

void fn_13_CDC(void) {
    fn_1_133DBC(NULL);
    fn_1_134AD4();
    menu_panel();
    fn_1_1380F0(lbl_13_data_98[lbl_801A66B4]);
    fn_1_13ABA8(0x28000000);
    fn_1_435C(lbl_13_bss_44);
    fn_1_407C();
    if (fn_1_154C84() == 0) {
        if (fn_1_154E24() != 0) {
            fn_1_49F0((GXColor){0x00, 0x00, 0x00, 0x00});
            fn_1_4A00(0, 15, lbl_13_bss_44);
            lbl_1_bss_6EAB4 |= 0x24;
            if (fn_1_4C10() == 0) {
                lbl_1_bss_968 = 1;
            }
        } else if (lbl_13_bss_48 == 15) {
            fn_1_49F0((GXColor){0x00, 0x00, 0x00, 0x00});
            fn_1_4A00(0, 15, lbl_13_bss_44);
            lbl_13_bss_48 -= 1;
        } else if (lbl_13_bss_48 > 0) {
            lbl_13_bss_48 -= 1;
            return;
        } else {
            lbl_1_bss_96A = 0xA9;
            lbl_13_bss_40 = 0xA8;
        }
        fn_1_3CC4();
        fn_1_435C(lbl_13_bss_44);
        fn_1_407C();
    }
}
/* fzgx:end fn_13_CDC */

/* fzgx:begin fn_13_E8C */
void fn_13_E8C(void) {
    fn_1_1596DC(2);
    fn_1_A0AA4(fn_1_484CC(2));
    fn_1_47A60(lbl_1_bss_960);
    fn_1_412A0(1);
    lbl_13_bss_4C = fn_1_154D84(lbl_801A63D0);
    fn_1_1547FC(lbl_13_bss_4C);
}
/* fzgx:end fn_13_E8C */

/* fzgx:begin fn_13_EF0 */
void fn_13_EF0(void) {
    lbl_13_bss_50 = 3;
}
/* fzgx:end fn_13_EF0 */

/* fzgx:begin fn_13_F00 */
void fn_13_F00(void) {
    if (lbl_13_bss_50-- <= 0) {
        if (lbl_1_bss_968 != 1 && lbl_13_bss_40 != 0xA7) {
            fn_13_0();
        }
        if (lbl_13_bss_44 != 0) {
            fn_1_435C(lbl_13_bss_44);
            fn_1_41A8();
            fn_1_46B4(lbl_801A6410, lbl_13_bss_44, "replay_mode.c", 713);
            lbl_13_bss_44 = 0;
        }
        lbl_1_bss_96A = lbl_13_bss_40;
    }
}
/* fzgx:end fn_13_F00 */

/* fzgx:begin fn_13_FA8 */
// fn_13_FA8: empty in retail (single blr).
void fn_13_FA8(void) {
}
/* fzgx:end fn_13_FA8 */
