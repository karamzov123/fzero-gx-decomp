#include "types.h"
#include "font.h"

typedef struct EmbColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} EmbColor;

/* the edit state of the emblem editor (lbl_3_bss_A17A0) */
typedef struct EmblemEditor {
    u32 flags;
    u32 unk_4;
    EmbColor color;
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    s16 unk_12;
    s16 unk_14;
    s16 unk_16;
    s16 unk_18;
    s16 unk_1A;
    u8 unk_1C;
    u8 pad_1D[3];
    u32 unk_20;
    u8 pad_24[4];
    u8 unk_28;
    u8 pad_29[3];
} EmblemEditor;

/* one saved canvas of the undo ring (lbl_3_bss_A17D4) */
typedef struct EmblemEntry {
    u32 flags;
    u8 unk_4;
    u8 pad_5;
    u8 unk_6;
    u8 unk_7;
    union {
        EmbColor color;
        u32 rgba;
    };
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
} EmblemEntry;

/* controller records of 0x14 bytes */
typedef struct PadStatus {
    u16 unk_0;
    u8 pad_2[6];
    u16 unk_8;
    u8 pad_A[6];
    u16 unk_10;
    u16 unk_12;
} PadStatus;

extern u32 lbl_801A6410;
extern s32 lbl_801A66B4;
extern u16 lbl_1_bss_96A;
/* lbl_1_bss_9F8: table of 0x14-byte entries with a u16 flag word at +8 */
extern PadStatus lbl_1_bss_9F8[];
extern FontDrawPacket lbl_1_rodata_26F8;
extern u32 *lbl_1_bss_6EAD0[];

extern u32 fn_1_45D0(u32, u32, const char *, s32);
extern void fn_1_46B4(u32, u32, const char *, int);
extern u32 fn_1_3F8C(const char *, void (*)(void), u32, s32);
extern u32 fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_47F74(s32);
extern void fn_1_48140(int);
extern void fn_1_A176C(u32, u32);
extern void fn_1_A2D84(u32);
extern void fn_1_4CC0(void);
extern int fn_1_B7E98(int);
extern u8 fn_1_B8338(int);
extern s32 fn_1_B8EDC(u32);
extern void fn_1_1317C4(void);
extern s32 fn_1_1318B8(void);
extern s32 fn_1_1318D4(void);
extern void fn_1_133DBC(void *);
extern void fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern s32 fn_1_45730(void *, void *);
extern u32 fn_1_45B2C(void *);
extern void fn_1_458A0(void *, void *, u32, u32);
extern void fn_1_45850(void *);
extern s32 fn_1_F7BE4(u32);
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
extern void fn_1_5233C(void);
extern void fn_8006CE1C(f32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80008BA8(void *, void *, u32);

extern void fn_3_1857C(void);
extern void fn_3_18614(void);
extern u32 fn_3_18960(s16);
extern void fn_3_19C50(void);
extern u8 fn_3_19C94(void);
extern u32 fn_3_19CE0(void);
extern void fn_3_19D50(void);
extern void fn_3_1552C(void);
extern void fn_3_1563C(void);
extern void fn_3_156D0(void);
extern u32 fn_3_15F44(s16);
extern void fn_3_17098(void);
extern void fn_3_170E0(void);
extern void fn_3_177AC(EmbColor);
extern u32 fn_3_17820(void);
extern void fn_3_17830(void);
extern u32 fn_3_17854(s16);
extern u32 fn_3_BF1C(void);
extern void fn_3_14778(u16, u16, u8, u32);

void fn_3_13508(void);
void fn_3_137AC(void);
void fn_3_139F0(void);
u32 fn_3_13D98(const char *path, u32 *out);
u32 fn_3_13EA4(const char *path, u32 *out);
void fn_3_14080(void);
void fn_3_142C4(void);
u8 fn_3_14600(void);

/* help text: [row][language] */
/* string table: [row][language] */
static const char *lbl_3_data_345C[10][6] = {
    {"Move Cursor", "", "", "", "", "\x83J\x81[\x83\\\x83\x8B\x82\xCC\x88\xDA\x93\xAE"},
    {"Help", "", "", "", "", "\x90\xE0\x96\xBE\x95\xB6\x82\xCC\x95\\\x8E\xA6"},
    {"Move Cursor", "", "", "", "", "\x83J\x81[\x83\\\x83\x8B\x82\xCC\x88\xDA\x93\xAE"},
    {"Change Pen Size", "", "", "", "", "\x83y\x83\x93\x83T\x83" "C\x83Y\x82\xCC\x95\xCF\x8DX"},
    {"Display Grid", "", "", "", "", "\x83O\x83\x8A\x83" "b\x83h\x82\xCC\x95\\\x8E\xA6"},
    {"Syringe", "", "", "", "", "\x83X\x83|\x83" "C\x83g"},
    {"Select", "", "", "", "", "\x8C\x88\x92\xE8"},
    {"Back", "", "", "", "", "\x82\xE0\x82\xC7\x82\xE9"},
    {"Change Color", "", "", "", "", "\x90" "F\x82\xCC\x95\xCF\x8DX"},
    {"[EMBLEM EDITOR] HELP", "", "", "", "", "[EMBLEM EDITOR] MANUAL"},
};

u32 lbl_3_bss_A1768 = 0;
u32 *lbl_3_bss_A176C = 0;
u32 *lbl_3_bss_A1770 = 0;
u32 *lbl_3_bss_A1774 = 0;
u8 lbl_3_bss_A1778;
u32 lbl_3_bss_A177C;
u32 lbl_3_bss_A1780;
u32 *lbl_3_bss_A1784;
u32 lbl_3_bss_A1788;
u32 lbl_3_bss_A178C[3];
s32 lbl_3_bss_A1798;
u32 lbl_3_bss_A179C;
EmblemEditor lbl_3_bss_A17A0;
s16 lbl_3_bss_A17CC;
u8 lbl_3_bss_A17D0[2];
s16 lbl_3_bss_A17D2;
EmblemEntry lbl_3_bss_A17D4[128];

/* fzgx:begin fn_3_1307C */
u8 fn_3_1307C(void) {
    return lbl_3_bss_A1778;
}
/* fzgx:end fn_3_1307C */

/* fzgx:begin fn_3_1308C */
void fn_3_1308C(u32 *arg0, u32 arg1, u32 arg2) {
    lbl_3_bss_A177C = arg1;
    lbl_3_bss_A1780 = arg2;
    lbl_3_bss_A176C = arg0;
    lbl_3_bss_A1784 = arg0;
}
/* fzgx:end fn_3_1308C */

/* fzgx:begin fn_3_130A8 */
void fn_3_130A8(void) {
    lbl_3_bss_A177C = 0;
    lbl_3_bss_A1780 = 0;
    lbl_3_bss_A1768 = 0;
    lbl_3_bss_A1784 = 0;
}
/* fzgx:end fn_3_130A8 */

/* fzgx:begin fn_3_130C8 */
void fn_3_130C8(void) {
    s32 n;
    u8 i;

    fn_8006CE1C(0.0f);
    fn_1_435C(lbl_3_bss_A177C);
    lbl_3_bss_A1788 = fn_1_3F8C("emblem_maker_calc", fn_3_13508, 0, 5);
    fn_1_435C(lbl_3_bss_A1780);
    lbl_3_bss_A178C[1] = fn_1_3F8C("emblem_maker_disp", fn_3_137AC, 0, 5);
    lbl_3_bss_A1778 = 0;
    lbl_3_bss_A1798 = 0;
    lbl_3_bss_A179C = 0;
    fn_3_14778(0x40, 0x40, 0x10, 5);
    fn_3_1857C();
    fn_3_1552C();
    fn_3_17098();
    fn_3_14080();
    lbl_3_bss_A1784 = &lbl_3_bss_A17A0.unk_20;
    fn_1_47F74(0x86);
    fn_1_A176C(*lbl_1_bss_6EAD0[0], 8);
    lbl_3_bss_A17A0.unk_20 = fn_1_45D0(lbl_801A6410, 0x2000, "emblem.c", 0x94);
    fn_80008BEC((void *)lbl_3_bss_A17A0.unk_20, 0, 0x2000);
    lbl_3_bss_A17A0.unk_C = 0;
    lbl_3_bss_A17A0.unk_E = 0;
    lbl_3_bss_A17A0.unk_10 = 0x20;
    lbl_3_bss_A17A0.unk_12 = 0x20;
    lbl_3_bss_A17A0.unk_4 = 0;
    lbl_3_bss_A17A0.flags = 0;
    lbl_3_bss_A17A0.unk_18 = 0;
    lbl_3_bss_A17A0.unk_16 = 0;
    lbl_3_bss_A17A0.unk_1A = 0;
    lbl_3_bss_A17A0.unk_14 = 0;
    lbl_3_bss_A17A0.unk_28 = 0;
    lbl_3_bss_A17CC = 0;
    lbl_3_bss_A176C = (u32 *)fn_1_45D0(lbl_801A6410, 0x3b8, "emblem.c", 0xa6);
    n = (s16)fn_3_13D98("./emblem/sample.bin", lbl_3_bss_A176C);
    lbl_3_bss_A17CC = n + fn_3_13EA4("./emblem/chara.bin", lbl_3_bss_A176C + n);
    for (i = lbl_3_bss_A17CC; i < 0xee; i++) {
        lbl_3_bss_A176C[i] = 0;
    }
    lbl_3_bss_A17D0[0] = fn_1_B7E98(0) ? fn_1_B8338(0) : 0;
    if (fn_1_B7E98(1)) {
        lbl_3_bss_A17D0[1] = fn_1_B8338(1);
    } else {
        lbl_3_bss_A17D0[1] = 0;
    }
    fn_1_1317C4();
}
/* fzgx:end fn_3_130C8 */

/* fzgx:begin fn_3_1338C */
void fn_3_1338C(void) {
    u8 i;
    u32 v;

    fn_1_435C(lbl_3_bss_A177C);
    fn_1_426C(lbl_3_bss_A1788);
    fn_1_435C(lbl_3_bss_A1780);
    fn_1_426C(lbl_3_bss_A178C[1]);
    fn_3_1563C();
    fn_3_19C50();
    fn_3_142C4();
    fn_1_46B4(lbl_801A6410, lbl_3_bss_A17A0.unk_20, "emblem.c", 0xd1);
    for (i = 0; i < lbl_3_bss_A17CC; i++) {
        v = lbl_3_bss_A176C[i];
        if (v != 0) {
            fn_1_46B4(lbl_801A6410, v, "emblem.c", 0xd6);
        }
    }
    fn_1_46B4(lbl_801A6410, (u32)lbl_3_bss_A176C, "emblem.c", 0xd8);
    fn_1_48140(0x86);
}
/* fzgx:end fn_3_1338C */

/* fzgx:begin fn_3_1349C */
void fn_3_1349C(void) {
    fn_1_4CC0();
    if ((lbl_3_bss_A17A0.flags & 0x20000000) != 0) {
        if (lbl_3_bss_A17D2 > 0) {
            lbl_3_bss_A17D2--;
            if (lbl_3_bss_A17D2 == 0) {
                lbl_1_bss_96A = 0x5c;
                lbl_3_bss_A17A0.flags &= ~0x20000000;
            }
        }
    }
}
/* fzgx:end fn_3_1349C */

/* fzgx:begin fn_3_13508 */
void fn_3_13508(void) {
    u32 flags;
    s32 v;
    u32 saved;

    if (fn_1_1318B8() != 0) return;
    if (lbl_3_bss_A17D0[0] != 0) return;
    if (lbl_3_bss_A17D0[1] != 0) return;

    if (lbl_3_bss_A17A0.flags & 0x40000000) {
        fn_1_4A00(1, 15, lbl_3_bss_A1780);
        lbl_3_bss_A17A0.flags &= ~0x40000000;
        lbl_3_bss_A17D2 = 15;
        lbl_3_bss_A17A0.flags |= 0x20000000;
        return;
    }

    if (fn_3_19C94() != 16 && fn_3_19C94() != 15 && fn_3_19C94() != 11) {
        flags = lbl_3_bss_A17A0.flags;
        if (!__rlwnm(flags, 7, 31, 31)) {
            if ((lbl_1_bss_9F8[lbl_3_bss_A17A0.unk_28].unk_8 >> 11) & 1) {
                if (flags & 0x80000000) {
                    lbl_3_bss_A17A0.flags = flags & 0x7FFFFFFF;
                } else {
                    lbl_3_bss_A17A0.flags = flags | 0x80000000;
                }
            }
            if ((lbl_1_bss_9F8[lbl_3_bss_A17A0.unk_28].unk_8 >> 4) & 1) {
                fn_1_A2D84(0xA9150600);
                fn_3_19D50();
            }
        }
    }

    flags = lbl_3_bss_A17A0.flags;
    if (__rlwnm(flags, 7, 31, 31)) {
        if ((lbl_1_bss_9F8[lbl_3_bss_A17A0.unk_28].unk_8 >> 9) & 1) {
            lbl_3_bss_A17A0.flags = flags & ~0x02000000;
        }
        return;
    }

    if (((lbl_1_bss_9F8[lbl_3_bss_A17A0.unk_28].unk_8 >> 12) & 1) &&
        fn_3_19C94() != 16 && fn_3_19C94() != 15 &&
        fn_3_19C94() != 17 && fn_3_19C94() != 12) {
        lbl_3_bss_A17A0.flags |= 0x02000000;
        return;
    }

    v = lbl_3_bss_A17A0.unk_14 + 1;
    lbl_3_bss_A17A0.unk_14 = (v < 0) ? 0 : (v > 120 ? 120 : v);
    if (lbl_3_bss_A17A0.flags & 0x60000000) return;

    saved = fn_3_19CE0();
    fn_3_18614();
    if (fn_3_19C94() == 16 || fn_3_19C94() == 15 || fn_3_19C94() == 12 ||
        fn_3_19C94() == 17 || fn_3_19C94() == 11) {
        return;
    }
    if ((u8)saved != 0 && (u8)fn_3_19CE0() == 0) {
        fn_3_170E0();
    } else {
        fn_3_156D0();
        fn_3_170E0();
    }
}
/* fzgx:end fn_3_13508 */

/* fzgx:begin fn_3_137AC */
void fn_3_137AC(void) {
    FontDrawPacket pkt;
    s32 c;
    s32 n;

    fn_1_133DBC((void *)1);
    fn_1_134AD4();

    if (__rlwnm(lbl_3_bss_A17A0.flags, 7, 31, 31)) {
        fn_1_13ABA8(0x20000000);
    } else {
        if (fn_3_19C94() == 9) {
            if ((u8)fn_3_19CE0() == 0) {
                fn_1_13ABA8(0x2A200000);
            } else {
                fn_1_13ABA8(0x28200000);
            }
        } else if (fn_3_19C94() == 10) {
            if ((u8)fn_3_19CE0() == 0) {
                fn_1_13ABA8(0x29200000);
            } else {
                fn_1_13ABA8(0x28200000);
            }
        } else if (fn_3_19C94() == 16 || fn_3_19C94() == 15
                   || fn_3_19C94() == 12 || fn_3_19C94() == 17) {
            fn_1_13ABA8(0x28000000);
        } else {
            fn_1_13ABA8(0x28200000);
        }
    }

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0x8606;
    pkt.x = 165.0f;
    pkt.y = 38.0f;
    pkt.z = 50.0f;
    pkt.flags = 10;
    fn_1_4F734(&pkt);

    if (fn_1_1318D4() != 0) {
        return;
    }

    if (lbl_3_bss_A17D0[0] != 0) {
        if (fn_1_B8EDC(0) != 0) {
            lbl_3_bss_A17D0[0] = 0;
        }
    } else if (lbl_3_bss_A17D0[1] != 0) {
        if (fn_1_B8EDC(1) != 0) {
            lbl_3_bss_A17D0[1] = 0;
        }
    } else {
        n = lbl_3_bss_A17A0.unk_14 - 15;
        if (n < 0) {
            c = 0;
        } else {
            c = 15;
            if (n <= 15) {
                c = n;
            }
        }
        fn_3_18960(c);
        fn_3_15F44(lbl_3_bss_A17A0.unk_14);
        fn_3_17854(lbl_3_bss_A17A0.unk_14);
        fn_3_BF1C();
        if (__rlwnm(lbl_3_bss_A17A0.flags, 7, 31, 31)) {
            fn_3_139F0();
        }
    }
}
/* fzgx:end fn_3_137AC */

/* fzgx:begin fn_3_139F0 */
void fn_3_139F0(void) {
    FontDrawPacket pkt;
    u8 i;

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
        fn_1_4AE0C("%s\n", lbl_3_data_345C[i][lbl_801A66B4]);
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
        fn_1_4AE0C("%s\n", lbl_3_data_345C[i][lbl_801A66B4]);
    }
    fn_1_49410();
    fn_1_494DC(5);
    fn_1_495C8(1);
    fn_1_4954C(7.0f);
    fn_1_496FC(320.0f, 110.0f);
    fn_1_4AE0C("%s", lbl_3_data_345C[9][lbl_801A66B4]);
}
/* fzgx:end fn_3_139F0 */

/* fzgx:begin fn_3_13D98 */
u32 fn_3_13D98(const char *path, u32 *out) {
    u8 header[0x60];
    u8 buffer[0x2000] __attribute__((aligned(32)));
    u8 i;
    u32 count;
    u32 size;

    if (fn_1_45730((void *)path, header) != 0) {
        size = fn_1_45B2C(header);
        count = size >> 13;
        if (count >= 0xc2) {
            count = 0xc2;
        }
        if (size != 0) {
            for (i = 0; i < count; i++) {
                lbl_3_bss_A176C[i] = fn_1_45D0(lbl_801A6410, 0x2000, "emblem.c", 0x236);
                fn_80008BEC((void *)lbl_3_bss_A176C[i], 0, 0x2000);
                fn_1_458A0(header, buffer, 0x2000, ((i << 13) + 0x1f) & ~0x1f);
                fn_80008BA8((void *)lbl_3_bss_A176C[i], buffer, 0x2000);
            }
            fn_1_45850(header);
        }
    }
    return count;
}
/* fzgx:end fn_3_13D98 */

/* fzgx:begin fn_3_13EA4 */
u32 fn_3_13EA4(const char *path, u32 *output) {
    u8 header[0x60];
    u8 buffer[0x2000] __attribute__((aligned(32)));
    u32 *out;
    u8 i;
    u32 count;
    u32 limit;
    u32 size;

    out = output;
    count = 0;
    if (fn_1_45730((void *)path, header) != 0) {
        size = fn_1_45B2C(header);
        limit = size >> 13;
        if (limit >= 0x2c) {
            limit = 0x2c;
        }
        if (size != 0) {
            for (i = 0; i < limit; i++) {
                if ((i == limit - 3 && fn_1_F7BE4(0x15) != 0) ||
                    (i == limit - 2 && fn_1_F7BE4(0x21) != 0) ||
                    (i == limit - 1 && fn_1_F7BE4(0x21) != 0) ||
                    (fn_1_F7BE4(i) != 0)) {
                    out[(u8)count] = fn_1_45D0(lbl_801A6410, 0x2000, "emblem.c", 0x27b);
                    fn_80008BEC((void *)out[(u8)count], 0, 0x2000);
                    fn_1_458A0(header, buffer, 0x2000, ((i << 13) + 0x1f) & ~0x1f);
                    fn_80008BA8((void *)out[(u8)count], buffer, 0x2000);
                    count++;
                }
            }
        }
        fn_1_45850(header);
    }
    return (u8)count;
}
/* fzgx:end fn_3_13EA4 */

/* fzgx:begin fn_3_14008 */
void fn_3_14008(void) {
    lbl_3_bss_A17A0.flags |= 0x40000000;
}
/* fzgx:end fn_3_14008 */

/* fzgx:begin fn_3_1401C */
u32 fn_3_1401C(void) {
    return lbl_3_bss_A17A0.unk_20;
}
/* fzgx:end fn_3_1401C */

/* fzgx:begin fn_3_1402C */
u32 fn_3_1402C(u8 index) {
    if (lbl_3_bss_A17CC <= index) {
        return 0;
    }
    return lbl_3_bss_A176C[index];
}
/* fzgx:end fn_3_1402C */

/* fzgx:begin fn_3_14064 */
u32 fn_3_14064(void) {
    return lbl_3_bss_A17CC & 0xff;
}
/* fzgx:end fn_3_14064 */

/* fzgx:begin fn_3_14074 */
EmblemEditor *fn_3_14074(void) {
    return &lbl_3_bss_A17A0;
}
/* fzgx:end fn_3_14074 */

/* fzgx:begin fn_3_14080 */
void fn_3_14080(void) {
    u8 i;
    EmblemEntry *entry;

    i = 0;
    lbl_3_bss_A1770 = (u32 *)fn_1_45D0(lbl_801A6410, 0x200, "emblem.c", 0x2d1);
    lbl_3_bss_A1774 = (u32 *)fn_1_45D0(lbl_801A6410, 0x200, "emblem.c", 0x2d2);
    for (; i < 0x80; i++) {
        lbl_3_bss_A1770[i] = fn_1_45D0(lbl_801A6410, 0x2000, "emblem.c", 0x2d6);
        lbl_3_bss_A1774[i] = 0;
        fn_80008BEC((void *)lbl_3_bss_A1770[i], 0, 0x2000);
        entry = lbl_3_bss_A17D4;
        entry += i;
        fn_80008BEC(entry, 0, 0x18);
        entry->unk_14 = lbl_3_bss_A1770[i];
        entry->unk_6 = 0x1f;
        entry->unk_7 = 0x1f;
        entry->rgba = fn_3_17820();
        entry->unk_10 = 0;
    }
}
/* fzgx:end fn_3_14080 */

/* fzgx:begin fn_3_141A8 */
void fn_3_141A8(u32 flags) {
    if ((flags & ~0x3fffffffU) == 0) {
        return;
    }
    if (flags & 0x40000000U) {
        flags = 0; /* directions are exclusive: consume the mask */
        if (lbl_3_bss_A17A0.unk_1A + 1 == 0x80) {
            lbl_3_bss_A17A0.unk_1A = 0;
        } else {
            lbl_3_bss_A17A0.unk_1A += 1;
        }
    }
    if (flags & 0x80000000U) {
        if (lbl_3_bss_A17A0.unk_1A - 1 < 0) {
            lbl_3_bss_A17A0.unk_1A = 0x7f;
        } else {
            lbl_3_bss_A17A0.unk_1A -= 1;
        }
    }
    if (lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].flags & 0x20000000U) {
        return;
    }
    fn_80008BA8((void *)lbl_3_bss_A17A0.unk_20, (void *)lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].unk_14, 0x2000);
    lbl_3_bss_A17A0.unk_10 = lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].unk_6;
    lbl_3_bss_A17A0.unk_12 = lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].unk_7;
    fn_3_17830();
    fn_3_177AC(lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].color);
}
/* fzgx:end fn_3_141A8 */

/* fzgx:begin fn_3_142C4 */
void fn_3_142C4(void) {
    u8 i;

    for (i = 0; i < 0x80; i++) {
        if (lbl_3_bss_A1770[i] != 0) {
            fn_1_46B4(lbl_801A6410, lbl_3_bss_A1770[i], "emblem.c", 0x321);
            lbl_3_bss_A1770[i] = 0;
        }

        if (lbl_3_bss_A1774[i] != 0) {
            fn_1_46B4(lbl_801A6410, lbl_3_bss_A1774[i], "emblem.c", 0x326);
            lbl_3_bss_A1774[i] = 0;
        }
    }

    if (lbl_3_bss_A1774 != 0) {
        fn_1_46B4(lbl_801A6410, (u32)lbl_3_bss_A1774, "emblem.c", 0x32e);
        lbl_3_bss_A1774 = 0;
    }

    if (lbl_3_bss_A1770 != 0) {
        fn_1_46B4(lbl_801A6410, (u32)lbl_3_bss_A1770, "emblem.c", 0x334);
        lbl_3_bss_A1770 = 0;
    }
}
/* fzgx:end fn_3_142C4 */

/* fzgx:begin fn_3_1441C */
u8 fn_3_1441C(void) {
    return lbl_3_bss_A17A0.unk_1A == lbl_3_bss_A17A0.unk_18;
}
/* fzgx:end fn_3_1441C */

/* fzgx:begin fn_3_1443C */
u8 fn_3_1443C(void) {
    return lbl_3_bss_A17A0.unk_1A == lbl_3_bss_A17A0.unk_16;
}
/* fzgx:end fn_3_1443C */

/* fzgx:begin fn_3_1445C */
void fn_3_1445C(void) {
    s32 next;
    EmblemEditor *state2;
    s32 flags;

    if ((lbl_3_bss_A17A0.flags & 0x04000000) == 0) {
        if (fn_3_14600() != 0)
            return;
    } else {
        lbl_3_bss_A17A0.flags &= ~0x04000000;
    }

    flags = lbl_3_bss_A17A0.flags;
    flags |= 0x10000000;
    lbl_3_bss_A17A0.flags = flags;
    flags = lbl_3_bss_A17A0.unk_1A;
    next = flags;
    next = next + 1;
    if (0x80 == next)
        lbl_3_bss_A17A0.unk_1A = 0;
    else
        lbl_3_bss_A17A0.unk_1A = next;

    if (lbl_3_bss_A17A0.unk_1A == lbl_3_bss_A17A0.unk_16) {
        flags = lbl_3_bss_A17A0.unk_16 + 1;
        next = flags;
        if (0x80 == next)
            lbl_3_bss_A17A0.unk_16 = 0;
        else
            lbl_3_bss_A17A0.unk_16 = next;
    }

    if (lbl_3_bss_A17A0.unk_1A != lbl_3_bss_A17A0.unk_16)
        lbl_3_bss_A17A0.unk_16 = lbl_3_bss_A17A0.unk_1A;

    state2 = &lbl_3_bss_A17A0;
    if (state2->unk_18 == state2->unk_16) {
        state2->unk_18 = state2->unk_18 + 1;
    }

    if (state2->unk_18 == 0x7f)
        lbl_3_bss_A17A0.unk_18 = 0;

    if (lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].unk_C < 0x2000 &&
        lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].unk_C != 0)
        lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].flags = 0x20000000;

    lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].unk_6 = lbl_3_bss_A17A0.unk_10;
    lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].unk_7 = lbl_3_bss_A17A0.unk_12;
    lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].rgba = fn_3_17820();
    lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].unk_4 = fn_3_19C94();
    fn_80008BA8((void *)lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].unk_14, (void *)lbl_3_bss_A17A0.unk_20, 0x2000);
}
/* fzgx:end fn_3_1445C */

/* fzgx:begin fn_3_14600 */
u8 fn_3_14600(void) {
    u8 mode;

    mode = lbl_3_bss_A17A0.unk_1C;
    if (mode == 11 || mode == 16 || mode == 15) {
        return 0;
    }
    if (lbl_3_bss_A17A0.unk_10 == lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].unk_6 &&
        lbl_3_bss_A17A0.unk_12 == lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].unk_7 &&
        lbl_3_bss_A17A0.color.r == lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].color.r &&
        lbl_3_bss_A17A0.color.g == lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].color.g &&
        lbl_3_bss_A17A0.color.b == lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].color.b &&
        lbl_3_bss_A17A0.color.a == lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].color.a &&
        mode == lbl_3_bss_A17D4[lbl_3_bss_A17A0.unk_1A].unk_4) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_3_14600 */

/* fzgx:begin fn_3_146BC */
// fn_3_146BC: empty in retail (single blr).
void fn_3_146BC(void) {
}
/* fzgx:end fn_3_146BC */

/* fzgx:begin fn_3_146C0 noprologue */
#include "types.h"

typedef struct EmbColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} EmbColor;

extern void *memset(void *, int, u32);
extern void *memcpy(void *, const void *, u32);

void fn_3_14BBC(u8 *canvas, s16 x, s16 y, s16 n, EmbColor *color);
u32 fn_3_149AC(u8 *data, s16 x, s16 y);
void fn_3_14E18(u8 *canvas, s16 x0, s16 y0, s16 x1, s16 y1);

/* canvas state: file-scope objects of this TU (width, height, a flag byte, texture format) */
u16 lbl_3_bss_A23D8;
u16 lbl_3_bss_A23DA;
u8 lbl_3_bss_A23DC;
u32 lbl_3_bss_A23E0;

void fn_3_146C0(u8 *canvas, s16 x, s16 y, s16 n, EmbColor *color) {
    s32 offset;
    EmbColor c;
    s16 m;

    if (x <= 0) {
        m = n;
        if (x + m <= 0) {
            return;
        }
        offset = x - 1;
        offset = ((offset >> 31) ^ offset) - (offset >> 31);
        n = m - offset;
        x = 1;
    } else {
        if (x + n >= lbl_3_bss_A23D8 - 1) {
            n = lbl_3_bss_A23D8 - 1 - x;
        }
    }

    if (y <= 0 || y >= lbl_3_bss_A23DA - 1) {
        return;
    }
    c = *color;
    fn_3_14BBC(canvas, x, y, n, &c);
}
/* fzgx:end fn_3_146C0 */

/* fzgx:begin fn_3_14778 noprologue */
void fn_3_14778(u16 width, u16 height, u8 arg2, u32 format) {
    lbl_3_bss_A23D8 = width;
    lbl_3_bss_A23DA = height;
    lbl_3_bss_A23DC = arg2;
    lbl_3_bss_A23E0 = format;
}
/* fzgx:end fn_3_14778 */

/* fzgx:begin fn_3_14794 noprologue */
/* colour (r, g, b, a) as a texel: RGB565, or RGB5A3 (opaque with 5 bits per colour from alpha 0xE0 up, otherwise
 * 3 bits of alpha and 4 bits per colour) */
#define RGB565(r, g, b) ((u16)((((r) & 0xF8) << 8) | (((g) & 0xFC) << 3) | (((b) & 0xF8) >> 3)))
#define RGB5A3(r, g, b, a)                                                                 \
    (a >= 0xE0 ? (((r) & 0xF8) << 7) | (((g) & 0xF8) << 2) | (((b) & 0xF8) >> 3) | 0x8000 \
                 : (((r) & 0xF0) << 4) | ((g) & 0xF0) | (((b) & 0xF0) >> 4) | (((a) & 0xE0) << 7))

/* WARNING: compiler-diff device, not original code (__restrict canvas: the alpha byte is read again before the
 * first texel store) */
/* writes colour (r, g, b, a bytes) into the canvas pixel at (x, y); lbl_3_bss_A23D8 holds the canvas width and
 * lbl_3_bss_A23E0 its texture format (4 RGB565, 5 RGB5A3), pixels in 4 x 4 tiles of 16-bit texels.
 * canvas is __restrict: retail reads the alpha byte again before it stores the texel's high byte */
void fn_3_14794(u8 *__restrict canvas, s16 x, s16 y, const u8 *color) {
    s16 offset;
    s16 bx;
    s16 by;
    s16 bw;
    s16 px;
    s16 py;
    s16 blk;
    u8 hi;
    u8 lo;

    switch (lbl_3_bss_A23E0) {
    case 4:
        bx = x / 4;
        by = y / 4;
        bw = lbl_3_bss_A23D8 / 4;
        px = x % 4;
        py = y % 4;
        blk = bx + by * bw;
        offset = blk * 32 + (px + py * 4) * 2;
        hi = RGB565(color[0], color[1], color[2]) >> 8;
        lo = RGB565(color[0], color[1], color[2]) & 0xFF;
        memset(&canvas[offset], hi, 1);
        memset(&canvas[offset + 1], lo, 1);
        break;
    case 5:
        bx = x >> 2;
        by = y >> 2;
        bw = lbl_3_bss_A23D8 >> 2;
        blk = bx + by * bw;
        offset = blk * 32 + ((x & 3) + (y & 3) * 4) * 2;
        canvas[offset] = (u16)RGB5A3(color[0], color[1], color[2], color[3]) >> 8;
        canvas[offset + 1] = RGB5A3(color[0], color[1], color[2], color[3]);
        break;
    case 6: /* empty in retail too: its compare tree tests 4, 5 and 6 */
        break;
    }
}
/* fzgx:end fn_3_14794 */

/* fzgx:begin fn_3_149AC noprologue */
/* reads one texel of the canvas (4 x 4 tiles) as an RGBA8 colour */
/* Reads one texel of the emblem texture (4x4 tiles) as an RGBA8 color. */
u32 fn_3_149AC(u8 *data, s16 x, s16 y) {
    u16 pix;
    EmbColor color;
    s16 tileX;
    s16 tileY;
    s16 tilesW;
    s16 tile;
    s16 px;
    s16 py;
    s16 offset;
    u8 hi;
    u8 lo;

    switch (lbl_3_bss_A23E0) {
    default:
    case 6:
        /* All unsupported formats share the common return. */
        goto done;
    case 4:
        tileX = x / 4;
        tileY = y / 4;
        tilesW = (lbl_3_bss_A23D8 + 1) / 4;
        tile = tileX + tileY * tilesW;
        px = x % 4;
        py = y % 4;
        hi = data[(offset = (tile << 5) + ((px + (py << 2)) << 1))];
        lo = data[offset + 1];
        pix = hi << 8;
        pix |= lo;
        color.r = ((((pix & 0xF800) >> 8)) | ((pix & 7)));
        color.g = ((pix & 0x7E0) >> 3) | (pix & 3);
        color.b = (pix & 7) | ((pix & 0x1F) << 3);
        break;
    case 5:
        tileX = x / 4;
        tileY = y / 4;
        tilesW = (lbl_3_bss_A23D8 + 1) / 4;
        tile = tileX + tileY * tilesW;
        px = x % 4;
        py = y % 4;
        offset = (tile << 5) + ((px + (py << 2)) << 1);
        memcpy(&pix, data + offset, 2);
        if (pix & 0x8000) {
            color.a = 0xFF;
            color.r = (pix >> 7) & 0xF8;
            color.g = (pix >> 2) & 0xF8;
            color.b = (pix & 0x1F) << 3;
        } else {
            color.a = (pix >> 8) & 0x70;
            color.r = (pix >> 4) & 0xF0;
            color.g = pix & 0xF0;
            color.b = (pix & 0xF) << 4;
        }
        break;
    }
done:
    return *(u32 *)&color;
}
/* fzgx:end fn_3_149AC */

/* fzgx:begin fn_3_14BBC noprologue */
/* writes colour c into the canvas pixel at (x, y); lbl_3_bss_A23D8 holds the canvas width and lbl_3_bss_A23E0 its
 * texture format (4 RGB565, 5 RGB5A3), pixels in 4 x 4 tiles of 16-bit texels */
static inline void put_pixel(u8 *canvas, s16 x, s16 y, EmbColor c) {
    s16 offset;
    s16 bx;
    s16 by;
    s16 bw;
    s16 px;
    s16 py;
    s16 blk;

    switch (lbl_3_bss_A23E0) {
    case 4:
        bx = x / 4;
        by = y / 4;
        bw = lbl_3_bss_A23D8 / 4;
        px = x % 4;
        py = y % 4;
        blk = bx + by * bw;
        offset = blk * 32 + (px + py * 4) * 2;
        memset(&canvas[offset], (u8)(RGB565(c.r, c.g, c.b) >> 8), 1);
        memset(&canvas[offset + 1], (u8)RGB565(c.r, c.g, c.b), 1);
        break;
    case 5:
        bx = x >> 2;
        by = y >> 2;
        bw = lbl_3_bss_A23D8 >> 2;
        px = x & 3;
        py = y & 3;
        blk = bx + by * bw;
        offset = blk * 32 + (px + py * 4) * 2;
        canvas[offset] = (u16)RGB5A3(c.r, c.g, c.b, c.a) >> 8;
        canvas[offset + 1] = RGB5A3(c.r, c.g, c.b, c.a);
        break;
    case 6: /* empty in retail too: its compare tree tests 4, 5 and 6 */
        break;
    }
}

/* writes *color into n canvas pixels from (x, y) along the row */
void fn_3_14BBC(u8 *canvas, s16 x, s16 y, s16 n, EmbColor *color) {
    s16 i;

    for (i = 0; i < n; i++) {
        put_pixel(canvas, x + i, y, *color);
    }
}
/* fzgx:end fn_3_14BBC */

/* fzgx:begin fn_3_14E18 noprologue */
/* put_pixel with the RGB565 texel held in a variable */
static inline void put_texel(u8 *canvas, s16 x, s16 y, EmbColor c) {
    s16 offset;
    s16 bx;
    s16 by;
    s16 bw;
    s16 px;
    s16 py;
    s16 blk;
    u32 texel; /* u32: as u16 the second call keeps it in another register than retail */

    switch (lbl_3_bss_A23E0) {
    case 4:
        bx = x / 4;
        by = y / 4;
        bw = lbl_3_bss_A23D8 / 4;
        px = x % 4;
        py = y % 4;
        blk = bx + by * bw;
        offset = blk * 32 + (px + py * 4) * 2;
        texel = RGB565(c.r, c.g, c.b);
        memset(&canvas[offset], (u8)(texel >> 8), 1);
        memset(&canvas[offset + 1], (u8)texel, 1);
        break;
    case 5:
        bx = x >> 2;
        by = y >> 2;
        bw = lbl_3_bss_A23D8 >> 2;
        px = x & 3;
        py = y & 3;
        blk = bx + by * bw;
        offset = blk * 32 + (px + py * 4) * 2;
        canvas[offset] = (u16)RGB5A3(c.r, c.g, c.b, c.a) >> 8;
        canvas[offset + 1] = RGB5A3(c.r, c.g, c.b, c.a);
        break;
    case 6: /* empty in retail too: its compare tree tests 4, 5 and 6 */
        break;
    }
}

/* swaps the canvas pixels at (x0, y0) and (x1, y1) */
void fn_3_14E18(u8 *canvas, s16 x0, s16 y0, s16 x1, s16 y1) {
    EmbColor c1;
    EmbColor c0;

    *(u32 *)&c0 = fn_3_149AC(canvas, x0, y0);
    *(u32 *)&c1 = fn_3_149AC(canvas, x1, y1);
    put_texel(canvas, x0, y0, c1);
    put_texel(canvas, x1, y1, c0);
}
/* fzgx:end fn_3_14E18 */

/* fzgx:begin fn_3_15240 noprologue */
void fn_3_15240(u8 *canvas, s16 x0, s16 y0, u16 n, s16 x1, s16 y1) {
    s32 i;
    s32 j;
    s32 count;
    s16 k;

    i = x1;
    j = x0;
    count = n;
    k = 0;
    while (k < count) {
        fn_3_14E18(canvas, j, y0, i, y1);
        i++;
        j++;
        k++;
    }
}
/* fzgx:end fn_3_15240 */

/* fzgx:begin fn_3_152BC noprologue */
/* fills the canvas pixels x0 <= x < x1, y0 <= y < y1 with *color, column by column */
void fn_3_152BC(u8 *canvas, s16 y0, s16 x0, s16 y1, s16 x1, EmbColor *color) {
    s16 x;
    s16 y;

    for (x = x0; x < x1; x++) {
        for (y = y0; y < y1; y++) {
            put_pixel(canvas, x, y, *color);
        }
    }
}
/* fzgx:end fn_3_152BC */
