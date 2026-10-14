/* Non-matching: best partial attempt (96.15% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    u8 pad_C[0xE4];
    u32 unk_F0;
    u8 pad_F4[0x20];
    u32 unk_114;
    u8 pad_118[8];
    s32 unk_120;
} ObjA;

typedef struct {
    u8 pad_0[0x850];
    void *unk_850;
    u8 pad_854[0x3B28];
    u8 unk_437C;
    u8 pad_437D[0x23];
    u32 unk_43A0;
    u8 unk_43A4;
    u8 pad_43A5[3];
    u32 unk_43A8;
} ObjB;

extern ObjA lbl_3_bss_0;
extern ObjB lbl_3_bss_140;
extern u32 lbl_3_data_B4;
extern u16 lbl_1_bss_96A;

extern s32 fn_1_1310E0(void);
extern int fn_1_4C10(void);
extern void fn_1_131050(void *, u32);
extern void fn_1_1310B8(void);
extern void fn_1_4A00(s32, u8, void *);

void fn_3_381C(void) {
    ObjB *b = &lbl_3_bss_140;
    ObjA *obj = (ObjA *)((u8 *)b - 0x20000);
    s32 res;
    s32 v;

    if (fn_1_1310E0() != 0) {
        return;
    }
    if (obj->unk_120 == -1) {
        fn_1_4C10();
    }
    if ((obj->unk_114 & 0x80000000) && !(obj->unk_114 & 0x1) && !(obj->unk_F0 & 0x2)) {
        res = 1;
    } else if (fn_1_4C10() != 0) {
        res = 1;
    } else {
        res = 0;
    }
    if (res != 0) {
        return;
    }
    if (obj->unk_120 != -1) {
        lbl_1_bss_96A = (u16)obj->unk_120;
        obj->unk_120 = -1;
        return;
    }
    if (obj->unk_0 != 0) {
        b->unk_43A0 = 1;
        obj->unk_0 = 0;
        fn_1_131050(&lbl_3_bss_140, b->unk_437C);
        return;
    }
    if (obj->unk_4 != 0) {
        b->unk_43A0 = 1;
        obj->unk_4 = 0;
        fn_1_131050(&lbl_3_bss_140, 4);
        return;
    }
    if (obj->unk_8 != 0) {
        b->unk_43A4 = 1;
        b->unk_43A0 = 1;
        obj->unk_8 = 0;
        fn_1_1310B8();
        return;
    }
    if (fn_1_1310E0() != 0) {
        return;
    }
    obj->unk_120 = 0x5f;
    {
        u32 *p = &lbl_3_data_B4;
        if ((s32)*p != -1) {
            obj->unk_120 = *p;
            *p = -1;
        }
    }
    if ((obj->unk_120 == 0x5f && !(obj->unk_F0 & 0x04000000)) || (obj->unk_F0 & 0x01000000)) {
        fn_1_4A00(0, 0xf, b->unk_850);
        b->unk_43A8 = 0;
    } else if (obj->unk_120 == 0x5f && (obj->unk_F0 & 0x04000000)) {
        obj->unk_F0 |= 0x02000000;
    }
}
