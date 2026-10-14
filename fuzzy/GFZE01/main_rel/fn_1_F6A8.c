/* Non-matching: best partial attempt (96.36% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_F6A8_lbl_1_bss_1148 {
    u8 pad_0[0x67C];
    void *unk_67C;
    void *unk_680;
    void *unk_684;
};

struct fn_1_F6A8_lbl_1_data_43B8 {
    u8 pad_0[0x68];
    u8 unk_68[4];
    u8 pad_6C[0xD0];
    s32 unk_13C;
    s32 unk_140;
    s32 unk_144;
    u8 pad_148[0x138];
    u8 pad_280[4];
    u8 str_284[0x1C];
    u8 str_2A0[0x1C];
    u8 str_2BC[0x18];
    u8 str_2D4[0x18];
    u8 str_2EC[0x18];
    u8 str_304[0x20];
    u8 str_324[0x18];
    u8 str_33C[0x14];
    u8 pad_350[4];
    u8 str_354[0x10];
    u8 str_364[0x10];
    u8 str_374[0x14];
    u8 str_388[0x20];
};

struct fn_1_F6A8_lbl_1_bss_525C {
    u8 pad_0[0x191];
    u8 unk_191;
    u8 unk_192;
};

typedef struct {
    u8 lab_pad[4];
    s32 kind;
    u8 pad[0x50];
    void *value;
} LoadInfo;

extern struct fn_1_F6A8_lbl_1_bss_1148 lbl_1_bss_1148;
extern struct fn_1_F6A8_lbl_1_data_43B8 lbl_1_data_43B8;
extern struct fn_1_F6A8_lbl_1_bss_525C lbl_1_bss_525C;
extern s16 lbl_1_bss_960;
extern u32 *lbl_801A6410;

extern u32 fn_1_3F1F8(void);
extern s32 fn_1_45730(void *, LoadInfo *);
extern void *fn_1_45B2C(LoadInfo *);
extern void *fn_1_4630(u32, u32, void *, u32);
extern void fn_1_458A0(LoadInfo *, void *, u32, u32);
extern void fn_1_45850(LoadInfo *);
extern s16 fn_1_7B054(void);
extern void fn_80006E10(u32);
extern int sprintf(char *, const char *, ...);

#pragma opt_dead_assignments off
void fn_1_F6A8(void) {
    struct fn_1_F6A8_lbl_1_data_43B8 *p_data;
    struct fn_1_F6A8_lbl_1_bss_1148 *p_bss;
    char buf[0x80];
    LoadInfo info;
    s16 mode;
    s32 sz;
    u32 mem;

    p_data = &lbl_1_data_43B8;
    p_bss = &lbl_1_bss_1148;

    if (p_data->unk_13C >= 0 && p_data->unk_140 >= 0 && p_data->unk_144 >= 0) {
        return;
    }

    fn_80006E10((u32)&p_data->pad_280);
    p_data->unk_13C = 0;
    p_bss->unk_67C = 0;
    p_data->unk_140 = 0;
    p_bss->unk_680 = 0;
    p_data->unk_144 = 0;
    p_bss->unk_684 = 0;
    mode = lbl_1_bss_960;

    if (mode == 10) {
        sprintf(buf, (const char *)p_data->str_284, fn_1_3F1F8() & 0xFF);
        if (fn_1_45730(buf, &info) == 0) {
            sprintf(buf, (const char *)p_data->str_2A0);
            fn_1_45730(buf, &info);
        }
    } else if (mode == 14) {
        if (lbl_1_bss_525C.unk_191 & 2) {
            switch (lbl_1_bss_525C.unk_192) {
            case 4:
                sprintf(buf, (const char *)p_data->str_2BC);
                break;
            case 3:
                sprintf(buf, (const char *)p_data->str_2D4);
                break;
            case 2:
                sprintf(buf, (const char *)p_data->str_2EC);
                break;
            default:
                sprintf(buf, (const char *)p_data->str_2EC);
                break;
            }
        } else {
            sprintf(buf, (const char *)p_data->str_304);
        }
        fn_1_45730(buf, &info);
    } else {
        sprintf(buf, (const char *)p_data->str_324, fn_1_3F1F8() & 0xFF);
        if (fn_1_45730(buf, &info) == 0) {
            sprintf(buf, (const char *)p_data->str_33C);
            fn_1_45730(buf, &info);
        }
    }

    p_data->unk_13C = (u32)fn_1_45B2C(&info) / 84;

    sz = ((u32)fn_1_45B2C(&info) + 0x1F) & ~0x1F;
    p_bss->unk_67C = fn_1_4630(*lbl_801A6410, sz, p_data->unk_68, 0x58D);
    fn_1_458A0(&info, p_bss->unk_67C, sz, 0);
    fn_1_45850(&info);

    if (fn_1_7B054() == 50) {
        fn_80006E10((u32)&p_data->pad_350);
        return;
    }

    sprintf(buf, (const char *)p_data->str_354, fn_1_3F1F8() & 0xFF);
    if (fn_1_45730(buf, &info) == 0) {
        sprintf(buf, (const char *)p_data->str_364);
        fn_1_45730(buf, &info);
    }

    p_data->unk_140 = (u32)fn_1_45B2C(&info) / 40;

    sz = ((u32)fn_1_45B2C(&info) + 0x1F) & ~0x1F;
    p_bss->unk_680 = fn_1_4630(*lbl_801A6410, sz, p_data->unk_68, 0x5A5);
    fn_1_458A0(&info, p_bss->unk_680, sz, 0);
    fn_1_45850(&info);

    sprintf(buf, (const char *)p_data->str_374, fn_1_3F1F8() & 0xFF);
    if (fn_1_45730(buf, &info) == 0) {
        sprintf(buf, (const char *)p_data->str_388);
        fn_1_45730(buf, &info);
    }

    p_data->unk_144 = (u32)fn_1_45B2C(&info) / 12;

    sz = ((u32)fn_1_45B2C(&info) + 0x1F) & ~0x1F;
    p_bss->unk_684 = fn_1_4630(*lbl_801A6410, sz, p_data->unk_68, 0x5B6);
    fn_1_458A0(&info, p_bss->unk_684, sz, 0);
    fn_1_45850(&info);

    fn_80006E10((u32)&p_data->pad_350);
}
#pragma opt_dead_assignments reset
