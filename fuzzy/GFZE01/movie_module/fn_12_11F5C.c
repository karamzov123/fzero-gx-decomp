/* Non-matching: best partial attempt (58.93% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieModule MovieModule;
typedef struct MovieRec MovieRec;
typedef struct MoviePoint MoviePoint;
typedef struct MovieInfo MovieInfo;
typedef struct MovieSize MovieSize;

struct MoviePoint {
    s32 x;
    s32 y;
};

struct MovieInfo {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    s16 unk_C;
    s16 unk_E;
};

struct MovieSize {
    u8 pad_0[0x18];
    s32 unk_18;
    s32 unk_1C;
};

struct MovieRec {
    u8 pad_0[0x18];
    u32 unk_18;
    u8 pad_1C[4];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
};

struct MovieModule {
    u8 unk_000[0x19C];
    u32 unk_19C;
    u8 unk_1A0[0xF0];
    void (*unk_290)(MovieModule *, u32);
    u8 unk_294[0x74];
    u32 unk_308;
};

extern u32 lbl_12_bss_6948[8];
extern u32 lbl_12_bss_6968[8];

void fn_12_11F5C(MovieModule *module, u32 arg1, MoviePoint *point,
                 MovieInfo *info, MovieSize *size) {
    u32 index = module->unk_19C;
    s16 countE = info->unk_E;
    s16 countC = info->unk_C;
    MovieRec *rec = (MovieRec *)((u8 *)module + 0xCC);
    void (*f1)(MovieRec *, u32);
    void (*f2)(MovieRec *, u32);
    s32 base0;
    s32 base1;
    s32 x;
    s32 y;
    s32 hx;
    s32 hy;
    s32 v;

    module->unk_290(module, module->unk_308);

    x = size->unk_18;
    y = size->unk_1C;
    hx = x / 2;
    hy = y / 2;
    f1 = (void (*)(MovieRec *, u32))lbl_12_bss_6968[index * 4 + 2 * (hy & 1) + (hx & 1)];
    f2 = (void (*)(MovieRec *, u32))lbl_12_bss_6948[index * 4 + 2 * (y & 1) + (x & 1)];
    base0 = point->x + (hx / 2 + (hy / 2) * countC);
    base1 = point->y + (hx + hy * countE);

    rec->unk_20 = countC;
    rec->unk_18 = arg1;
    v = info->unk_0 + base0;
    rec->unk_24 = v;
    rec->unk_28 = v + countC + ((hx & 1) & index);
    f1(rec, v);

    rec->unk_18 = arg1 + 0x40;
    v = info->unk_4 + base0;
    rec->unk_24 = v;
    rec->unk_28 = v + countC + ((hx & 1) & index);
    f1(rec, v);

    rec->unk_20 = countE;
    rec->unk_18 = arg1 + 0x80;
    v = info->unk_8 + base1;
    rec->unk_24 = v;
    rec->unk_28 = v + countE + ((x & 1) & index);
    f2(rec, v);
}
