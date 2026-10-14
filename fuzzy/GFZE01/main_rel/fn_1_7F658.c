/* Non-matching: best partial attempt (98.52% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_7F658_lbl_801A6410 {
    u32 unk_0;
};
extern struct fn_1_7F658_lbl_801A6410 lbl_801A6410;
extern u8 lbl_1_data_1FFF0[0xC];

typedef struct {
    u8 pad_340[0x340];
    void *field_340;
} Sig_fn_1_7F658_Item;

typedef struct {
    u8 pad_380[0x380];
    u32 unk_380;
} Sig_fn_1_7F658_Sub;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
} Sig_fn_1_7F658_E34;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    void *unk_8;
    u8 pad_C[0x320];
    u32 unk_32C;
    u32 unk_330;
    Sig_fn_1_7F658_E34 unk_334[5];
    u8 pad_370[0xC];
    u32 unk_37C[4];
    u8 pad_38C[4];
    u32 unk_390;
    u32 unk_394;
    u8 pad_398[8];
    Sig_fn_1_7F658_Item *unk_3A0;
    u32 unk_3A4;
    u8 pad_3A8[0x18];
    u32 unk_3C0[8];
    u32 unk_3E0[8];
    u32 unk_400[5];
    u32 unk_414[5];
} Sig_fn_1_7F658_Car;

extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_14DBCC(Sig_fn_1_7F658_Item *);
extern void fn_1_150464(u32);
extern void fn_1_810E4(u32);
extern void fn_1_A7728(Sig_fn_1_7F658_Car *);
extern void fn_800711A8(u32);
extern void fn_80071718(u32);

void fn_1_7F658(Sig_fn_1_7F658_Car *arg0) {
    struct fn_1_7F658_lbl_801A6410 *p_lbl_801A6410;
    Sig_fn_1_7F658_Sub *p_sub;
    u32 v0;
    s8 flag;
    s16 v1;
    struct { s16 value; } v8;

    if (arg0 != 0) {
        if (arg0 == 0) {
            flag = 0;
        } else {
            if ((arg0->unk_390 & 0x4000000) != 0 && arg0->unk_3A0->field_340 != 0) {
                flag = 1;
            } else {
                flag = 0;
                if (arg0->unk_37C[0] != 0) {
                    flag = 1;
                } else if (arg0->unk_37C[1] != 0) {
                    flag = 1;
                } else {
                    p_sub = (Sig_fn_1_7F658_Sub *)((u8 *)arg0 + 8);
                    if (arg0->unk_37C[2] != 0) {
                        flag = 1;
                    } else {
                        if (p_sub->unk_380 != 0) {
                            flag = 1;
                        }
                    }
                }
            }
        }
        if (flag) {
            p_lbl_801A6410 = &lbl_801A6410;
            v1 = 0;
            while (v1 < 8) {
                v0 = arg0->unk_3C0[v1];
                if (v0 != 0) {
                    fn_1_46B4(p_lbl_801A6410->unk_0, v0, (const char *)lbl_1_data_1FFF0, 0x27D);
                    arg0->unk_3C0[v1] = 0;
                    arg0->unk_3E0[v1] = 0;
                }
                v1++;
            }
            p_lbl_801A6410 = &lbl_801A6410;
            v1 = 0;
            while (v1 < 5) {
                v0 = arg0->unk_400[v1];
                if (v0 != 0) {
                    fn_1_46B4(p_lbl_801A6410->unk_0, v0, (const char *)lbl_1_data_1FFF0, 0x284);
                    arg0->unk_400[v1] = 0;
                    arg0->unk_414[v1] = 0;
                }
                v1++;
            }
            arg0->unk_32C = 0;
            {
                struct { s16 value; } w;
                w.value = 0;
                while (w.value < 4) {
                    v0 = arg0->unk_37C[w.value];
                    if (v0 != 0) {
                        fn_80071718(v0);
                        arg0->unk_37C[w.value] = 0;
                    }
                    w.value++;
                }
                v8.value = w.value;
            }
            v8.value = 0;
            while (v8.value < 5) {
                v0 = arg0->unk_334[v8.value].unk_4;
                if (v0 != 0) {
                    fn_800711A8(v0);
                    arg0->unk_334[v8.value].unk_4 = 0;
                }
                v0 = arg0->unk_334[v8.value].unk_0;
                if (v0 != 0) {
                    fn_1_46B4(lbl_801A6410.unk_0, v0, (const char *)lbl_1_data_1FFF0, 0x290);
                    arg0->unk_334[v8.value].unk_0 = 0;
                }
                v8.value++;
            }
            v0 = arg0->unk_330;
            if (v0 != 0) {
                fn_1_46B4(lbl_801A6410.unk_0, v0, (const char *)lbl_1_data_1FFF0, 0x292);
                arg0->unk_330 = 0;
            }
            if ((void *)((u8 *)arg0 + 0x394) != 0) {
                fn_1_A7728(arg0);
            }
            if ((arg0->unk_390 & 0x4000000) != 0) {
                if (arg0->unk_3A0 != 0) {
                    fn_1_14DBCC(arg0->unk_3A0);
                }
            }
            if (arg0 != 0 && arg0 != 0) {
                if (arg0->unk_3A4 != 0) {
                    if ((arg0->unk_390 & 0x2000000) != 0) {
                        fn_1_150464(arg0->unk_3A4);
                    } else {
                        fn_1_810E4(arg0->unk_3A4);
                    }
                    fn_1_46B4(lbl_801A6410.unk_0, arg0->unk_3A4, (const char *)lbl_1_data_1FFF0, 0x1F7);
                    arg0->unk_3A4 = 0;
                }
            }
            arg0->unk_390 &= ~0x400000;
        }
    }
}
