/* Non-matching: best partial attempt (89.05% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/phys.h"

extern s16 fn_1_7B054(void);
extern u8 lbl_1_data_2B0D4[0x70];
extern u32 lbl_1_bss_85288[2];
extern char *fn_80083DB0(char *, const char *);
extern size_t strlen(const char *);
extern s32 fn_8006FC5C(void *, void *, size_t);

typedef struct Obj_1_E1E9C_Sub2 Obj_1_E1E9C_Sub2;

typedef struct Obj_1_E1E9C_Sub {
    u32 unk_0;
    u32 unk_4;
    Obj_1_E1E9C_Sub2 *unk_8;
    u32 unk_C;
} Obj_1_E1E9C_Sub;

struct Obj_1_E1E9C_Sub2 {
    u32 unk_0;
    void *unk_4;
    u32 unk_8;
    u32 unk_C;
};

typedef struct {
    u32 unk_0;
    u32 unk_4;
    Obj_1_E1E9C_Sub *unk_8;
    u8 pad_C[0x34];
} Obj_1_E1E9C_Entry;

typedef struct {
    u8 pad_0[0xA];
    s16 unk_A;
    u8 pad_C[2];
    s16 unk_E;
    s16 unk_10[4];
    u8 pad_18[0x120];
    u32 unk_138;
    u32 unk_13C;
} Obj_1_E1E9C_Arg0;

#define TGT ((Obj_1_data_2A7E0_At3C *)lbl_1_bss_3BE0->unk_0)
#define ENT(idx) (((Obj_1_E1E9C_Entry *)TGT->unk_54)[idx])
#define CNT ((s32)TGT->unk_48)

void fn_1_E1E9C(Obj_1_E1E9C_Arg0 *arg0) {
    Obj_1_data_2A7E0_At3C *target;
    Obj_1_E1E9C_Entry *e;
    const char *names;
    s16 sel;
    s16 j;
    s32 i;
    char buf[0x38];

    target = lbl_1_data_2A7E0.unk_3C;
    names = (const char *)&lbl_1_data_3DC98;

    if (((arg0->unk_138 & 0) | (arg0->unk_13C & 0x2000000)) != 0) {
        switch (lbl_1_data_2B0D4[fn_1_7B054()]) {
        case 1:
            if (arg0->unk_A == 1) {
                sel = (s16)target->unk_0;
            } else {
                sel = -1;
            }
            break;
        case 6:
            if (arg0->unk_A == 5) {
                sel = (s16)*(u32 *)((u8 *)target + 0xFD64);
            } else {
                sel = -1;
            }
            break;
        case 13:
            if (arg0->unk_A == 4) {
                sel = (s16)target->unk_0;
            } else {
                sel = -1;
            }
            break;
        default:
            sel = -1;
            break;
        }

        if (sel == -1) {
            switch (arg0->unk_A) {
            case 1:
                sel = (s16)lbl_1_bss_85288[0];
                break;
            case 5:
                sel = (s16)lbl_1_bss_85288[1];
                break;
            default:
                sel = -1;
            }
        }

        if (sel == -1) {
            arg0->unk_10[0] = -1;
            arg0->unk_10[1] = -1;
            arg0->unk_10[2] = -1;
            arg0->unk_10[3] = -1;
            switch (arg0->unk_A) {
            case 5:
                fn_80083DB0(buf, names + 0x124);
                for (i = 0; i < CNT; i++) {
                    if (fn_8006FC5C(ENT(i).unk_8->unk_8->unk_4, buf, strlen(buf)) != 0) {
                        sel = i;
                        break;
                    }
                }
                fn_80083DB0(buf, names + 0x134);
                for (i = 0; i < CNT; i++) {
                    if (fn_8006FC5C(ENT(i).unk_8->unk_8->unk_4, buf, strlen(buf)) != 0) {
                        arg0->unk_10[0] = i;
                        break;
                    }
                }
                fn_80083DB0(buf, names + 0x14C);
                for (i = 0; i < CNT; i++) {
                    if (fn_8006FC5C(ENT(i).unk_8->unk_8->unk_4, buf, strlen(buf)) != 0) {
                        arg0->unk_10[1] = i;
                        break;
                    }
                }
                fn_80083DB0(buf, names + 0x164);
                for (i = 0; i < CNT; i++) {
                    if (fn_8006FC5C(ENT(i).unk_8->unk_8->unk_4, buf, strlen(buf)) != 0) {
                        arg0->unk_10[2] = i;
                        break;
                    }
                }
                break;
            case 1:
                fn_80083DB0(buf, names + 0x17C);
                for (i = 0; i < CNT; i++) {
                    if (fn_8006FC5C(ENT(i).unk_8->unk_8->unk_4, buf, strlen(buf)) != 0) {
                        sel = i;
                        break;
                    }
                }
                fn_80083DB0(buf, names + 0x180);
                for (i = 0; i < CNT; i++) {
                    if (fn_8006FC5C(ENT(i).unk_8->unk_8->unk_4, buf, strlen(buf)) != 0) {
                        arg0->unk_10[0] = i;
                        break;
                    }
                }
                fn_80083DB0(buf, names + 0x18C);
                for (i = 0; i < CNT; i++) {
                    if (fn_8006FC5C(ENT(i).unk_8->unk_8->unk_4, buf, strlen(buf)) != 0) {
                        arg0->unk_10[1] = i;
                        break;
                    }
                }
                fn_80083DB0(buf, names + 0x198);
                for (i = 0; i < CNT; i++) {
                    if (fn_8006FC5C(ENT(i).unk_8->unk_8->unk_4, buf, strlen(buf)) != 0) {
                        arg0->unk_10[2] = i;
                        break;
                    }
                }
                break;
            case 4:
                fn_80083DB0(buf, names + 0x20);
                for (i = 0; i < CNT; i++) {
                    if (fn_8006FC5C(ENT(i).unk_8->unk_8->unk_4, buf, strlen(buf)) != 0) {
                        sel = i;
                        break;
                    }
                }
                break;
            default:
                break;
            }
        }
    }

    if (sel == -1) {
        arg0->unk_13C &= ~0x2000000;
        arg0->unk_138 &= ~0;
    } else {
        arg0->unk_E = sel;
        e = &ENT(arg0->unk_E);
        if (arg0->unk_A == 4) {
            e->unk_8->unk_0 |= 0x20;
        }
        e->unk_0 |= 0x80000000;
        for (j = 0; j < 4; j++) {
            if (arg0->unk_10[j] != -1) {
                ENT(arg0->unk_10[j]).unk_0 |= 0x80000000;
            }
        }
    }
}
