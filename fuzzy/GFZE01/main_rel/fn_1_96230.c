/* Non-matching: best partial attempt (93.10% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/rob.h"

typedef struct Fn196230Object Fn196230Object;
struct Fn196230Object {
    u8 unk_000[4];
    s32 unk_004[5];
    u8 unk_018[0xCC];
    u32 unk_0E4[5];
    u32 unk_0F8[5][4];
};
typedef const char *Fn196230Table[3][5];
extern Fn196230Table lbl_1_rodata_3E48;
extern void sprintf(char *, const char *, ...);
extern void fn_1_12AB38(const char *);
extern void fn_1_12A2B8(int);
extern void fn_1_12A2D0(void *);
extern s32 fn_1_465D0(const char *, int);
extern void *fn_1_12AC00(const char *);
extern u32 fn_1_12ADA0(const char *, void *);

void fn_1_96230(Fn196230Object *arg0, s32 arg1, u32 arg2, u32 arg3, int arg4) {
    const char **others = lbl_1_rodata_3E48[1];
    u8 *data = (u8 *)&lbl_1_data_209C0;
    char buf[0x40];
    s32 flags[5][4];
    u32 value;
    const char **names = lbl_1_rodata_3E48[0];
    s32 i = 0, j, k;
    flags[0][0] = i;
    value = *(u32 *)(data + 0x35c + arg1 * 4);
    flags[0][1] = i;
    flags[0][2] = i;
    flags[0][3] = i;
    flags[1][0] = i;
    flags[1][1] = i;
    flags[1][2] = i;
    flags[1][3] = i;
    flags[2][0] = i;
    flags[2][1] = i;
    flags[2][2] = i;
    flags[2][3] = i;
    flags[3][0] = i;
    flags[3][1] = i;
    flags[3][2] = i;
    flags[3][3] = i;
    flags[4][0] = i;
    flags[4][1] = i;
    flags[4][2] = i;
    flags[4][3] = i;
    for (; i < 5; i++, names++, others++) {
        if (__rlwnm(arg2, (i + 1) & 0x1F, 31, 31)) {
            const char **variants = lbl_1_rodata_3E48[2];
            for (j = 0; j < 4; j++, variants++) {
                u32 res;
                if (__rlwnm(arg3, (j + 1) & 0x1F, 31, 31)) {
                    if (arg4 == 0 && arg0->unk_004[i] != -1 &&
                        (arg3 == 0x80000000u || arg3 == 0x40000000u ||
                         arg3 == 0x20000000u || arg3 == 0x10000000u)) {
                        sprintf(buf, (const char *)(data + 0x6ee0), value,
                                *names, lbl_1_rodata_3E48[2][0]);
                    } else {
                        sprintf(buf, (const char *)(data + 0x6ee0), value,
                                *names, *variants);
                    }
                    if (arg4 != 0) {
                        fn_1_12AB38((const char *)(data + 0x6ed8));
                        flags[i][j] = (fn_1_465D0(buf, 1) >= 0);
                        fn_1_12AB38((const char *)(data + 0x6eec));
                    } else {
                        if (arg0->unk_004[i] != -1) {
                            fn_1_12A2B8(1);
                            fn_1_12A2D0((void *)arg0->unk_004[i]);
                        } else {
                            fn_1_12A2B8(0);
                        }
                        fn_1_12AB38((const char *)(data + 0x6ed8));
                        res = (u32)fn_1_12AC00(buf);
                        arg0->unk_0F8[i][j] = res;
                        flags[i][j] = ((res | -res) >> 31);
                        fn_1_12AB38((const char *)(data + 0x6eec));
                    }
                    if (flags[i][j] == 0) {
                        sprintf(buf, (const char *)(data + 0x7278), value,
                                *names);
                        if (arg4 != 0) {
                            fn_1_12AB38((const char *)(data + 0x6ed8));
                            flags[i][j] = (fn_1_465D0(buf, 1) >= 0);
                            fn_1_12AB38((const char *)(data + 0x6eec));
                        } else {
                            if (arg0->unk_004[i] != -1) {
                                fn_1_12A2B8(1);
                                fn_1_12A2D0((void *)arg0->unk_004[i]);
                            } else {
                                fn_1_12A2B8(0);
                            }
                            fn_1_12AB38((const char *)(data + 0x6ed8));
                            res = (u32)fn_1_12AC00(buf);
                            arg0->unk_0F8[i][j] = res;
                            flags[i][j] = ((res | -res) >> 31);
                            fn_1_12AB38((const char *)(data + 0x6eec));
                        }
                    }
                }
            }
            for (k = 0; k < 4; k++) {
                if (flags[i][k] != 0) {
                    sprintf(buf, (const char *)(data + 0x7284), value,
                            *others);
                    if (arg4 != 0) {
                        fn_1_12AB38((const char *)(data + 0x6ed8));
                        fn_1_465D0(buf, 1);
                        fn_1_12AB38((const char *)(data + 0x6eec));
                    } else {
                        if (arg0->unk_004[i] != -1) {
                            fn_1_12A2B8(1);
                            fn_1_12A2D0((void *)arg0->unk_004[i]);
                        } else {
                            fn_1_12A2B8(0);
                        }
                        fn_1_12AB38((const char *)(data + 0x6ed8));
                        arg0->unk_0E4[i] = fn_1_12ADA0(buf, (void *)arg0->unk_0F8[i][k]);
                        fn_1_12AB38((const char *)(data + 0x6eec));
                    }
                    break;
                }
            }
        }
    }
    if (arg4 == 0) {
        s32 handle;
        s32 m;
        handle = -1;
        for (m = 0; m < 5; m++) {
            if (arg0->unk_004[m] != -1) {
                handle = arg0->unk_004[m];
                break;
            }
        }
        if (handle != -1) {
            fn_1_12A2B8(1);
            fn_1_12A2D0((void *)handle);
        } else {
            fn_1_12A2B8(0);
        }
    }
}
