/* Non-matching: best partial attempt (88.31% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct MovieLoc {
    s32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct MovieHead {
    u32 unk_0;
    s32 unk_4;
};

struct fn_12_33A44_Arg0 {
    u8 pad_00[0x40];
    u32 unk_40;
    u8 pad_44[0x78];
    u32 unk_BC;
    u8 pad_C0[0x14];
    u32 unk_D4;
};

struct fn_12_33A44_Arg1 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u8 pad_14[4];
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    struct MovieHead *unk_38;
};

struct fn_12_33A44_Out {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u32 unk_44;
};

extern char lbl_12_rodata_1208[37];
extern char lbl_12_rodata_1230[80];
extern void MWSFSVM_Error(const char *, ...);
extern s32 fn_12_2DF28(u32, struct MovieLoc *);
extern s32 fn_12_38AE0(struct MovieHead *);

void fn_12_33A44(struct fn_12_33A44_Arg0 *arg0, struct fn_12_33A44_Arg1 *arg1, struct fn_12_33A44_Out *out) {
    s32 len;
    struct { s32 value; } type2;
    u32 v40;
    s32 type1;
    s32 v00;
    s32 v04;
    s32 v08;
    s32 v0C;
    struct { s32 value; } v34;
    s32 v18;
    s32 v30;
    s32 v2C;
    struct MovieLoc loc;
    s64 den;
    s32 q1;
    s32 lv;
    u32 ptr;
    s32 v20;
    u32 bc;
    u32 d4;
    struct MovieHead *head;

    v40 = arg0->unk_40;
    v20 = arg1->unk_20;

    switch (arg1->unk_1C) {
    case 1:
        type1 = 1;
        break;
    case 2:
        type1 = 2;
        break;
    case 3:
        type1 = 3;
        break;
    default:
        type1 = 3;
        break;
    }

    v00 = arg1->unk_00;
    v04 = arg1->unk_04;
    v08 = arg1->unk_08;
    v0C = arg1->unk_0C;

    switch (arg1->unk_10) {
    case 1:
        type2.value = 1;
        break;
    case 2:
        type2.value = 2;
        break;
    case 3:
        type2.value = 3;
        break;
    case 4:
        type2.value = 4;
        break;
    default:
        MWSFSVM_Error(lbl_12_rodata_1208);
        type2.value = 1;
        break;
    }

    v34.value = arg1->unk_34;
    loc.unk_8 = arg1->unk_24;
    loc.unk_4 = arg1->unk_28;
    v18 = arg1->unk_18;
    v2C = arg1->unk_2C;
    v30 = arg1->unk_30;
    if (fn_12_2DF28(v40, &loc) != 0) {
        MWSFSVM_Error(lbl_12_rodata_1230);
    }

    den = (s64)v18 * 1000;
    lv = loc.unk_0;
    q1 = (s64)v34.value * lv / den;
    lv = loc.unk_0;

    out->unk_00 = v20;
    out->unk_04 = type1;
    out->unk_08 = v00;
    out->unk_0C = v04;
    out->unk_10 = v08;
    out->unk_14 = v0C;
    out->unk_18 = type2.value;
    out->unk_1C = loc.unk_0;
    out->unk_20 = q1;
    out->unk_24 = v34.value;
    out->unk_28 = v18;
    out->unk_2C = v2C;
    out->unk_30 = ((lv) * ((s64)v30)) / den;
    out->unk_34 = v30;
    bc = (u32)&arg0->unk_BC;
    out->unk_38 = loc.unk_8;
    out->unk_3C = loc.unk_4;

    head = arg1->unk_38;
    d4 = arg0->unk_D4;
    ptr = head->unk_0;
    len = head->unk_4;
    if (fn_12_38AE0(head) != 1) {
        out->unk_40 = 0;
        out->unk_44 = 0;
    } else if (d4 == bc) {
        out->unk_40 = 0;
        out->unk_44 = 0;
    } else {
        if (ptr != 0 && len > 4) {
            ptr += 4;
            len -= 4;
        }
        out->unk_44 = len;
        out->unk_40 = ptr;
    }
}
