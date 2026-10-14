/* Non-matching: best partial attempt (54.12% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/sel/sel.h"

extern u8 lbl_1_bss_8B3A0[];
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_96A;
extern u32 lbl_1_bss_9F8[];
extern u8 lbl_1_bss_9C8[];
extern u32 lbl_1_bss_6EAB4;
extern u32 lbl_801A66C0;
extern s32 fn_10_C258(void *, s32);
extern void fn_10_C274(void *, s32);
extern void fn_1_A2D84(u32);
extern void fn_1_8F62C(void *);
extern s32 fn_1_12CB04(s16);
extern s32 fn_1_4C10(void);
extern void fn_1_12F150(s16, u32, u32);
extern s32 fn_1_12F258(void);
extern u32 fn_1_12F228(void);
extern void fn_1_12F17C(void);
extern u32 fn_1_12F1E8(s32);
extern void fn_1_4A00(s32, u8, void *);

void fn_10_7A10(void) {
    u8 *manager = (u8 *)&lbl_10_bss_0 + 0x50000;
    u8 *state = lbl_1_bss_8B3A0;
    s16 index = fn_10_C258(state, lbl_1_bss_962);
    s16 selected = (s16)state[0x9e];
    s32 count = 0;
    s32 activate = 0;
    s32 i;
    u32 status;
    s16 pending;
    u16 *flag;
    if (lbl_801A66C0 == 0x78)
        fn_1_A2D84(0xA9122000);

    if ((*(u32 *)(state + 0x94) & 0x80000000) == 0) {
        fn_1_8F62C(manager + 0x1b7c + selected * 0x4e0);
        i = 0;
        while ((s16)i < (s16)fn_1_12CB04(*(s16 *)(state + (selected << 5) + 0xe))) {
            fn_1_8F62C(manager + 0x2efc + selected * 0x9c0 + i * 0x4e0);
            i++;
        }
    }

    if (*(s32 *)(manager + 0x14) == -1)
        fn_1_4C10();

    status = *(u32 *)(state + 0x140);
    if (!((status & 0x80000000) && !(status & 0x40000000) &&
          !(*(u32 *)(state + 0x94) & 0x8)))
        status = fn_1_4C10();
    else
        status = 1;
    if (status == 0) {
        if (*(s32 *)(manager + 0x14) != -1) {
            s16 pending = *(s16 *)(manager + 0x14);
            *(s32 *)(manager + 0x14) = -1;
            lbl_1_bss_96A = pending;
        } else if (*(s32 *)(manager + 0x55fc) == 1) {
            if (index == 0 || index == 1) {
                s32 i;
                for (i = 0; i < 4; i++) {
                    if ((s8)lbl_1_bss_9C8[i * 0xc + 0xa] != -1 &&
                        ((*(u32 *)(state + 0x98) >> ((i + 1) & 31)) & 1)) {
                        u16 *flag = (u16 *)((u8 *)&lbl_1_bss_9F8[selected * 5] + 8);
                        if (flag[i * 6] & 0x100)
                            count++;
                        if (flag[i * 6] & 0x100)
                            fn_1_12F150(i, 0, 1);
                        if (index == 1 && (flag[i * 6] & 0x100))
                            fn_1_12F17C();
                    }
                }
                if (index == 0) {
                    if (count == 0) {
                        s32 value = fn_1_12F258();
                        if ((u32)(0x1e0 - value) <= 0xf0 && fn_1_12F228() == 0)
                            goto done;
                    }
                    fn_10_C274(state, lbl_1_bss_962);
                    fn_1_12F150(selected, 0, 1);
                } else {
                    if (count == 0 && fn_1_12F228() == 0)
                        goto done;
                    fn_10_C274(state, lbl_1_bss_962);
                    activate = 1;
                }
            } else {
                s32 i;
                for (i = 0; i < 4; i++) {
                    if ((s8)lbl_1_bss_9C8[i * 0xc + 0xa] != -1 &&
                        ((*(u32 *)(state + 0x98) >> ((i + 1) & 31)) & 1)) {
                        u16 *flag = (u16 *)((u8 *)&lbl_1_bss_9F8[selected * 5] + 8);
                        if (flag[i * 6] & 0x100)
                            count++;
                        if (flag[i * 6] & 0x100) {
                            fn_1_12F150(i, 0, 1);
                            fn_1_12F17C();
                        }
                    }
                }
                if (count == 0 && fn_1_12F228() == 0)
                    goto done;
                activate = 1;
            }
        } else {
            s32 i;
            for (i = 0; i < 4; i++) {
                if ((s8)lbl_1_bss_9C8[i * 0xc + 0xa] != -1 &&
                    ((*(u32 *)(state + 0x98) >> ((i + 1) & 31)) & 1)) {
                    u16 *flag = (u16 *)((u8 *)&lbl_1_bss_9F8[selected * 5] + 8);
                    if (flag[i * 6] & 0x100)
                        count++;
                    if (flag[i * 6] & 0x100) {
                        fn_1_12F150(i, 0, 1);
                        fn_1_12F17C();
                    }
                }
            }
            if (count != 0 || fn_1_12F228() != 0)
                activate = 1;
        }
        if (activate) {
            *(s32 *)(manager + 0x14) =
                (*(u32 *)(state + 0x94) & 0x2000) ? 0x15 : 0xe;
            fn_1_12F1E8(0);
            fn_1_4A00(0, (u8)*(s16 *)(manager - 0x6c74),
                      *(void **)(manager - 0x6c78));
            *(u32 *)(manager + 0x1744) = 0;
            lbl_1_bss_6EAB4 |= 0x24;
            state[0x129] = 0;
        }
    }
done:
    ;
}
