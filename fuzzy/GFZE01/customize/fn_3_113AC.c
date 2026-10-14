/* Non-matching: best partial attempt (56.76% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/emb_paste_editor.h"

extern u16 lbl_1_bss_9F8[];

extern s32 fn_1_1310E0(void);
extern void fn_1_A2D84(u32);
extern void fn_3_12D4(void);
extern void fn_3_14C4(void *);
extern void fn_3_131C(s32, const char *);
extern void fn_3_11974(void);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_1_130EE8(void *, void *);
extern void fn_1_131050(u32, u32);
extern u32 fn_1_B7F08(void);
extern void fn_1_131004(void);
extern void fn_1_130F98(void);
extern u32 lbl_801A66B4;

void fn_3_113AC(void) {
    Obj_3_bss_7EDC0 *p = &lbl_3_bss_7EDC0;
    Obj_3_bss_7EDC0_At0 *sub = (Obj_3_bss_7EDC0_At0 *)((u8 *)p + 0x18);
    u8 mode;
    u32 flags;
    s32 i, count;
    s32 stride = 0x10000 - 0x7e40;
    Obj_3_bss_7EE40 *entries = &lbl_3_bss_7EE40;

    if (fn_1_1310E0() != 0) return;
    mode = *((u8 *)p + 0x16);
    if (mode != 0) {
        if (mode == 4) {
            *((u8 *)p + 0x16) = 0;
            p->unk_0[0].unk_8 = p->unk_0[0].unk_8; 
            *((u32 *)((u8 *)p + 0x24)) |= 0x800000;
            return;
        }
        {
            u16 *sel = (u16 *)((u8 *)&lbl_1_bss_9F8 + (*(s16 *)((u8 *)&lbl_3_bss_F0 + 6) * 0x14));
            if ((sel[8] & 1) || (sel[9] & 1)) {
                *((u8 *)((u8 *)p + 0x20000 + 0x8f4)) = 0;
                fn_1_A2D84(0xa9011300);
            }
            if ((sel[0] & 2) || (sel[9] & 2)) {
                *((u8 *)((u8 *)p + 0x20000 + 0x8f4)) = 1;
                fn_1_A2D84(0xa9011300);
            }
            if (sel[4] & 0x200) *((u8 *)((u8 *)p + 0x20000 + 0x8f4)) = 1;
            flags = sel[4];
            if ((flags & 0x100) || (flags & 0x200)) {
                if (mode == 1) {
                    if (*((u8 *)((u8 *)p + 0x20000 + 0x8f4)) == 0) {
                        fn_1_A2D84(0xa9010100);
                        *((u32 *)((u8 *)p + 0x20000 + 0x904)) = 0x40000000;
                    } else {
                        fn_1_A2D84(0xa9010200);
                        *((u32 *)((u8 *)p + 0x24)) = 0x40000000;
                    }
                    *((u8 *)p + 0x16) = 0;
                    return;
                }
                if (mode == 2) {
                    if (*((u8 *)((u8 *)p + 0x20000 + 0x8f4)) == 0) {
                        fn_1_A2D84(0xa9010100);
                        *((u32 *)((u8 *)p + 0x20000 + 0x904)) = 0x00800000;
                        *((u8 *)p + 0x16) = 0;
                    } else {
                        fn_1_A2D84(0xa9010200);
                        *((u8 *)p + 0x16) = 3;
                    }
                    return;
                }
                if (mode == 3) {
                    if (*((u8 *)((u8 *)p + 0x20000 + 0x8f4)) == 0) {
                        fn_1_A2D84(0xa9010100);
                        *((u32 *)((u8 *)p + 0x24)) |= 0x800000;
                    } else {
                        fn_1_A2D84(0xa9010200);
                        *((u32 *)((u8 *)p + 0x24)) = 0x40000000;
                    }
                    *((u8 *)p + 0x16) = 0;
                    return;
                }
                return;
            }
        }
        fn_3_12D4();
        fn_3_14C4((u8 *)p + 0x20000 + 0x8f4);
        if (mode == 1) fn_3_131C(0xdc, (const char *)*(u32 *)((u8 *)&lbl_3_data_1A40 + 0x74 + 4 * lbl_801A66B4));
        else if (mode == 2) fn_3_131C(0xdc, (const char *)*(u32 *)((u8 *)&lbl_3_data_1A40 + 0x15c + 4 * lbl_801A66B4));
        else if (mode == 3) fn_3_131C(0xdc, (const char *)*(u32 *)((u8 *)&lbl_3_data_1A40 + 0x20c + 4 * lbl_801A66B4));
    } else {
        if (*((u8 *)p + 0x14) == 0) {
            fn_80008BA8(&lbl_3_bss_87040, (void *)(p->unk_0 + sub->unk_8 * stride), stride);
            count = 0;
            for (i = 0; i < 4; i++) if (entries[i].unk_24 & 0x80000000) count++;
            *((u8 *)(p->unk_0 + sub->unk_8 * stride) + 7) = count;
            ((u8 *)entries)[7] = count;
            for (i = 0; i < 4; i++)
                fn_80008BA8((void *)(p->unk_0 + sub->unk_8 * stride + i * 0x2060 + 0x20),
                            (u8 *)entries + i * 0x2060 + 0x20, 0x2060);
            fn_1_130EE8((void *)*((u32 *)((u8 *)p + 0x18)), (void *)*((u32 *)((u8 *)p + 0x1c)));
            fn_1_131050((u32)p->unk_0, *((u8 *)p + 0x5f));
            *((u8 *)p + 0x14) = 1;
        } else if (*((u8 *)p + 0x15) != 0) {
            if (fn_1_B7F08()) fn_80008BA8((void *)(p->unk_0 + sub->unk_8 * stride), &lbl_3_bss_87040, stride);
            else fn_3_11974();
            fn_1_131004();
            flags = *((u32 *)((u8 *)p + 0x20000 + 0x904));
            *((u8 *)p + 0x14) = 0;
            *((u8 *)p + 0x15) = 0;
            if (flags == 0x00800000) *((u32 *)((u8 *)p + 0x24)) |= 0x800000;
            else *((u32 *)((u8 *)p + 0x24)) = flags;
        } else {
            fn_1_130F98();
            *((u8 *)p + 0x15) = 1;
        }
    }
}
