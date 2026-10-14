/* Non-matching: best partial attempt (84.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/archive.h"

extern int fn_1_4C10(void);
extern void fn_1_A2D84(u32);
extern u32 fn_1_12E0B8(s16, s16, void *, void *, u32, void *, u32);
extern void fn_1_12C0EC(void *);
extern void fn_1_12F150(s16, u32, u32);
extern u32 fn_1_467F4(void);
extern void fn_1_A5344(u8, s16);
extern void fn_1_12B664(s16, void *, void *);
extern u32 fn_1_12F228(void);
extern void fn_1_12F1E8(s32);
extern void fn_1_12ECA8(s16, s16, void *, void *, void *);
extern int fn_1_D6698(void);
extern int fn_1_D6690(void);
extern void fn_1_12F17C(void);
extern u8 lbl_1_bss_A48[64];
extern u8 lbl_1_data_407BC[0xC];

typedef struct {
    s16 state;
    u8 pad_2[0xC];
    s16 unk_E;
} FnData;

int fn_1_12BB18(void *arg0, void *arg1, void *arg2, FnData *arg3, int arg4) {
    int result;
    s32 count = 0;
    s16 i;
    u8 *out = (u8 *)arg0;
    u8 *params = (u8 *)arg1;
    FnData *entry = arg3;
    Obj_1_bss_8B3A0 *global;

    result = fn_1_4C10();
    if (result != 0) {
        return 0;
    }
    global = (Obj_1_bss_8B3A0 *)&lbl_1_bss_8B3A0;

    for (i = 0; i < 4; i++) {
        s16 mode = *(s16 *)((u8 *)arg2 + i * 0x20 + 0xE);
        s16 *state = &entry[i].state;
        if (mode != -1) {
            if (*state == 0) {
                u32 flags = *(u32 *)((u8 *)arg2 + 0x98);
                if ((flags & (1U << ((i + 1) & 31))) != 0 &&
                    (lbl_1_bss_9F8.unk_8 & 0x200) != 0 &&
                    ((global->unk_94 & 0x40000000) == 0 ||
                     (global->unk_94 & 0x4000) != 0)) {
                    if (lbl_1_bss_960 == 1) {
                        fn_1_A2D84(0xA9010200);
                    }
                    return -1;
                }
                fn_1_12E0B8(i, mode, (u8 *)arg0 + i * 0x4E0,
                            params + i * 0x9C0, 1, lbl_1_data_407BC, 3);
            } else {
                u16 flags = lbl_1_bss_9F8.unk_8;
                global->unk_129 = 0;
                if ((flags & 0x200) != 0 &&
                    ((global->unk_94 & 0x40000000) == 0 ||
                     (global->unk_94 & 0x4000) != 0)) {
                    fn_1_12E0B8(i, mode, (u8 *)arg0 + i * 0x4E0,
                                params + i * 0x9C0, 0, lbl_1_data_407BC, 3);
                    fn_1_12C0EC((void *)((u8 *)arg2 + i * 0x20));
                    fn_1_A2D84(0xA9010200);
                    fn_1_12F150(i, 8, 0);
                } else if (*state == 2) {
                    if (arg4 != 0 || fn_1_467F4() != 0) {
                    } else {
                        count++;
                    }
                } else if (*state == 1) {
                    if ((global->unk_94 & 0x80000000) == 0) {
                        if ((lbl_1_bss_9F8.unk_8 & 0x100) != 0 &&
                            (arg4 != 0 || fn_1_467F4() == 0)) {
                            *state = 2;
                        }
                    } else if ((lbl_1_bss_9F8.unk_8 & 0x100) != 0) {
                        *state = 2;
                    }
                    if (*state == 2) {
                        count++;
                    }
                }
            }

            {
                s8 change;
                s8 value = (s8)lbl_1_bss_A48[i * 16];
                s32 magnitude = ((s32)value ^ ((s32)value >> 31)) - ((s32)value >> 31);
                if (magnitude == 72) {
                    change = value < 0 ? -3 : 3;
                } else if (magnitude > 60) {
                    change = value < 0 ? -2 : 2;
                } else if (magnitude > 40) {
                    change = value < 0 ? -1 : 1;
                } else if ((lbl_1_bss_9F8.unk_12 & 1) != 0) {
                    change = -1;
                } else if ((lbl_1_bss_9F8.unk_12 & 2) != 0) {
                    change = 1;
                } else {
                    change = 0;
                }

                {
                    s32 value2 = ((u8 *)arg2)[i + 0x9F] + change;
                    if (value2 < 0) value2 = 0;
                    if (value2 > 100) value2 = 100;
                    global[i].unk_9F = (u8)value2;
                }
                if ((lbl_1_bss_9F8.unk_10 & 1) != 0) {
                    s32 value2 = global[i].unk_9F - 1;
                    if (value2 < 0) value2 = 0;
                    if (value2 > 100) value2 = 100;
                    global[i].unk_9F = (u8)value2;
                }
                if ((lbl_1_bss_9F8.unk_10 & 2) != 0) {
                    s32 value2 = global[i].unk_9F + 1;
                    if (value2 < 0) value2 = 0;
                    if (value2 > 100) value2 = 100;
                    global[i].unk_9F = (u8)value2;
                }
            }
            fn_1_A5344(global[i].unk_9F, i);
            fn_1_12B664(i, arg2, state);
            if ((lbl_1_bss_9F8.unk_8 & 0x100) != 0 || fn_1_12F228() != 0) {
                if (*state == 0) {
                    fn_1_12F1E8(0);
                    *state = 1;
                    fn_1_12ECA8(i, mode, (u8 *)arg0 + i * 0x4E0,
                                params + i * 0x9C0, state);
                    fn_1_12F150(i, 7, 1);
                    if ((fn_1_D6698() & 0xFF) != 0 ||
                        (fn_1_D6690() & 0xFF) != 0) {
                        fn_1_A2D84(0xA9010100);
                    }
                }
            }
        }
    }
    if (count >= *(s16 *)((u8 *)arg2 + 4)) {
        fn_1_12F17C();
        return 1;
    }
    return 0;
}
