/* Non-matching: best partial attempt (82.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern size_t strlen(const char *);
extern char *strchr(const char *, int);
extern char *strrchr(const char *, int);
extern void OSReport(const char *, ...);
extern char *fn_80083DB0(char *, const char *);

typedef union {
    struct {
        u32 w0;
        u32 w4;
        u32 w8;
        u32 wC;
    } w;
    struct {
        u8 unk_0;
        u8 unk_1;
        u8 unk_2;
        u8 pad_3;
        u16 unk_4;
        s16 unk_6;
        s16 unk_8;
        u8 pad_A[2];
        u32 unk_C;
    } b;
} Rec_A948C;

typedef struct {
    Rec_A948C hdr;
    u8 pad_10[0x1000];
    Rec_A948C recs[0x100];
    s32 unk_2010;
    s32 unk_2014;
    s32 unk_2018;
} Obj_A948C;

extern Obj_A948C lbl_1_bss_6F648;

typedef struct {
    u32 table[3];
    s32 flag;
    char msg1[0x1C];
    char msg2[0x1C];
} Data_A948C;

extern Data_A948C lbl_1_data_35990;

typedef struct {
    u8 pad_0[4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[0x32];
} Info_A948C;

extern Info_A948C lbl_1_data_1AEA8[616];

s32 fn_1_A948C(char *arg0) {
    Data_A948C *d = &lbl_1_data_35990;
    Obj_A948C *bss = &lbl_1_bss_6F648;
    Rec_A948C *rec;
    Info_A948C *info;
    char *dest;
    char *end;
    char *p;
    size_t len;
    s32 n;
    s32 w;
    s32 h;
    s32 lines;

    len = strlen(arg0);
    dest = (char *)bss->hdr.b.unk_C;
    end = dest + len + 1;

    if (d->flag == 0) {
        return 0;
    }

    if (end >= (char *)bss->pad_10 + 0x1000) {
        if (bss->unk_2014 == 0) {
            OSReport(d->msg1);
            bss->unk_2014 = 1;
        }
        return 0;
    }

    n = bss->unk_2010;
    if (n + 1 >= 0x100) {
        if (bss->unk_2018 == 0) {
            OSReport(d->msg2);
            bss->unk_2018 = 1;
        }
        return 0;
    }

    rec = &bss->recs[n];
    *rec = bss->hdr;
    fn_80083DB0(dest, arg0);
    bss->hdr.b.unk_C = (u32)end;
    bss->unk_2010 = n + 1;

    if ((bss->hdr.b.unk_2 >> 1) & 1) {
        info = &lbl_1_data_1AEA8[d->table[bss->hdr.b.unk_0]];
        w = info->unk_4;
    } else {
        w = 1;
    }

    if ((bss->hdr.b.unk_2 >> 1) & 1) {
        info = &lbl_1_data_1AEA8[d->table[bss->hdr.b.unk_0]];
        h = info->unk_5;
    } else {
        h = 1;
    }

    if (strrchr(arg0, '\n') != NULL) {
        bss->hdr.b.unk_8 = w * (strlen(strrchr(arg0, '\n')) - 1);
    } else {
        bss->hdr.b.unk_8 = bss->hdr.b.unk_8 + w * strlen(arg0);
    }

    p = arg0;
    lines = 0;
    while (strchr(p, '\n') != NULL) {
        p = strchr(p, '\n') + 1;
        lines++;
    }
    bss->hdr.b.unk_6 = bss->hdr.b.unk_6 + lines * h;
    return 1;
}
