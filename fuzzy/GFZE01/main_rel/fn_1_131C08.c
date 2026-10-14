/* Non-matching: best partial attempt (47.48% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/custom_memcard.h"

typedef struct {
    u8 pad[0x64];
    s16 unk_64;
} Arg;
typedef struct { u8 pad[0x1c]; s16 values[1]; } Inner;
typedef struct { u8 pad[0x7e60]; u8 unk_7e60; } Far;
extern int fn_1_D6698(void);
extern int fn_1_D66B0(void);
extern int fn_1_D66B8(void);
extern void fn_1_D66F8(u8, u8 *, s8 *);
extern void fn_1_F7870(u32);
extern const f64 lbl_1_rodata_8608;
extern const f32 lbl_1_rodata_8620, lbl_1_rodata_8630, lbl_1_rodata_8634;
extern const f64 lbl_1_rodata_8628;
extern const f32 lbl_1_rodata_8638, lbl_1_rodata_863C;
extern u8 lbl_1_bss_8E3C8[8];
extern void fn_1_13C134(void);
extern void fn_1_13C16C(void);
extern u32 fn_1_12F118(void);
extern u8 *fn_1_36AD0(void);
extern void fn_1_151BDC(void *);
extern void fn_1_14E2DC(void *, s16, f32);
extern void *fn_1_13F8B0(u32);
extern void fn_1_FCFA4(void *);
extern void *fn_1_7F428(u32);
extern void fn_1_FD27C(void *, void *);
extern void fn_1_FDD7C(void);
extern void fn_8006F038(void *, void *, s16);
extern void lbl_8006DCDC(void);
extern void lbl_8006D758(void);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void lbl_8006E14C(f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DFE8(void *);
extern void fn_80072558(void);
extern void fn_1_870BC(void *, s8, void *, s32, u32, f32);
extern u32 lbl_801A66A0;
extern s16 lbl_1_bss_96A;
extern void *lbl_801A6D00;

s32 fn_1_131C08(Arg *arg0, f32 unused) {
    s16 idx = *(s16 *)arg0;
    s16 state = *(s16 *)((u8 *)&lbl_1_bss_8B3A0 + idx * 32 + 0xE);
    s32 count = 0;
    u32 mask = 1;
    u8 *bits = (u8 *)&lbl_1_bss_8B3A0 + idx * 32 + 0x14;
    u32 type = *(u32 *)((u8 *)arg0 + 0x50 + idx * 4);
    s32 bit;
    s32 active;
    s32 i;
    s16 n;
    void *obj;
    void *item;
    u8 slot;
    s8 chosen;
    s16 temp;
    if (type == 0xFFFFFFFF) { }
    bit = 0;
    do {
        if (bits[0] & (1 << (bit & 0xFF))) break;
        bit++;
    } while ((bit & 0xFF) < 8);
    count = bit;
    if (lbl_1_bss_8B3A0.unk_94 & 0x40000000) {
        if ((fn_1_D6698() & 0xFF) == 0) {
            u8 cur = (u8)fn_1_D66B0();
            if (arg0->unk_64 != cur) {
                fn_1_D66F8((u8)arg0->unk_64, &slot, &chosen);
                if (chosen != -1) { count = slot; state = chosen; }
            }
        }
    }
    if (lbl_1_bss_8B3A0.unk_94 & 0x80000000) return 0;
    if (state == -1) return 0;
    fn_8006F038((u8 *)arg0 + 0x38, (u8 *)arg0 + 0x44, 0);
    lbl_8006DCDC();
    fn_1_F7870((u32)&lbl_1_data_1E5C0);
    if (lbl_1_bss_8B3A0.unk_94 & 0x40000000) {
        if ((fn_1_D6698() & 0xFF) == 0) {
            s16 player = arg0->unk_64;
            u8 current = (u8)fn_1_D66B0();
            active = 0;
            if (player == current) {
                if (lbl_1_bss_960 == 1) {
                    active = *(s16 *)((u8 *)lbl_1_bss_8B3A0.unk_A4 +
                                     lbl_1_bss_962 * 148 - 0x7F4) != 0;
                } else {
                    active = *(s16 *)*(u32 *)((u8 *)arg0 + 0x1C) != 0;
                }
            }
            if (!active) {
                u32 phase = lbl_801A66A0 % 360;
                *(s16 *)(lbl_1_bss_8E3C8 + (u8)player * 2) =
                    (s16)(lbl_1_rodata_8620 * (f32)(360 - phase));
            }
        }
    } else {
        idx = *(s16 *)arg0;
        if (lbl_1_bss_960 == 1) {
            n = *(s16 *)&lbl_1_bss_962;
            active = *(s16 *)((u8 *)lbl_1_bss_8B3A0.unk_A4 +
                             n * 148 + idx * 28 - 0x7F4);
        } else {
            active = ((Inner *)*(u32 *)((u8 *)arg0 + 0x1C))->values[idx];
        }
        if (!active) {
            u32 phase = lbl_801A66A0 % 360;
            *(s16 *)(lbl_1_bss_8E3C8 + idx * 2) =
                (s16)(lbl_1_rodata_8620 * (f32)(360 - phase));
        } else {
            u16 angle = *(u16 *)(lbl_1_bss_8E3C8 + idx * 2);
            if (angle < 0x7555) {
                *(s16 *)(lbl_1_bss_8E3C8 + idx * 2) =
                    (s16)((f32)angle + lbl_1_rodata_8628 *
                          (lbl_1_rodata_8630 - (f32)angle));
            } else {
                *(s16 *)(lbl_1_bss_8E3C8 + idx * 2) =
                    (s16)((f32)angle + lbl_1_rodata_8628 *
                          (lbl_1_rodata_8634 - (f32)angle));
            }
        }
    }
    lbl_8006D758();
    mathutil_mtxA_rotate_x(0xEAAA);
    mathutil_mtxA_rotate_y(*(s16 *)(lbl_1_bss_8E3C8 + (u8)idx * 2));
    lbl_8006E14C(lbl_1_rodata_8638);
    lbl_8006DB74((u8 *)*(void **)((u8 *)&lbl_801A6D00 + 0) + 0x60);
    lbl_8006DB74((u8 *)__builtin_frame_address(0) + 0xC);
    if (state < 0x29) {
        obj = *(void **)((u8 *)arg0 + 0xC);
        item = (u8 *)obj + state * 0x440;
        if (!item) return 0;
        lbl_8006DFE8(*(u8 **)((u8 *)&lbl_801A6D00 + 0) + 0x60);
        fn_80072558();
        if (type == 1) fn_1_13C134();
        fn_1_870BC(item, *(s8 *)((u8 *)arg0 + 0x14), item, 0, count, lbl_1_rodata_863C);
        if (type == 1) fn_1_13C16C();
    } else {
        if (lbl_1_bss_962 == 0x14 || lbl_1_bss_96A == 0x14) goto done;
        i = state - 0x29;
        item = (u8 *)fn_1_12F118();
        if (item == fn_1_36AD0()) {
            if (lbl_1_bss_8B3A0.unk_94 & 0x40000000) {
                if (fn_1_D6698() & 0xFF) idx = *(s16 *)arg0;
                else idx = (u8)fn_1_D66B8();
            } else idx = *(s16 *)arg0;
        }
        obj = (u8 *)item + (s16)idx * 0x181C0;
        if (!(*(u32 *)obj & 0x80000000)) return 0;
        lbl_8006DFE8(*(u8 **)((u8 *)&lbl_801A6D00 + 0) + 0x60);
        fn_80072558();
        if (*(u32 *)obj & 0x40000000) {
            fn_1_151BDC(obj);
            fn_1_14E2DC((u8 *)*(u32 *)((u8 *)arg0 + 0x10) + (s16)idx * 0xA20,
                       *(s16 *)((u8 *)arg0 + 0x14), lbl_1_rodata_863C);
        } else {
            u8 which = *((u8 *)obj + 0x1A0);
            obj = (u8 *)*(u32 *)((u8 *)arg0 + 0xC) + which * 0x440;
            fn_1_870BC(obj, *(s8 *)((u8 *)arg0 + 0x14), obj, 0, count, lbl_1_rodata_863C);
        }
    }
done:
    if (lbl_1_bss_962 == 0x14 || lbl_1_bss_96A == 0x14) return 0;
    item = (u8 *)fn_1_12F118();
    idx = *(s16 *)arg0;
    if (lbl_1_bss_962 == 0x10) {
        if (state < 0x29) return 0;
        idx = state - 0x29;
    }
    if (!item) return 0;
    obj = (u8 *)item + (s16)idx * 0x181C0;
    if (!(*(u32 *)obj & 0x80000000)) return 0;
    if (lbl_1_bss_962 == 0x10 || lbl_1_bss_962 == 0x12) {
        if (lbl_1_bss_962 == 0x10 && lbl_1_bss_8B3A0.unk_0 != 0) return 0;
        if (idx >= 8 || *((u8 *)obj + 7) == 0) return 0;
        lbl_8006DFE8((u8 *)__builtin_frame_address(0) + 0xC);
        fn_80072558();
        if (fn_1_13F8B0((u8)idx)) fn_1_FCFA4(fn_1_13F8B0((u8)idx));
    } else if (lbl_1_bss_962 == 0x24) {
        void *p = fn_1_7F428((u8)idx);
        if (!p) return 0;
        item = *(void **)p;
        if (idx >= 4 || *((u8 *)obj + 7) == 0 || !item) return 0;
        if (p) {
            s16 old = *(s16 *)((u8 *)item + 0x3BA);
            void *saved = *(void **)((u8 *)p + 0xC);
            u8 value = (u8)old;
            lbl_8006DFE8((u8 *)__builtin_frame_address(0) + 0xC);
            fn_80072558();
            if (lbl_1_bss_8B3A0.unk_0 == 0) *(s16 *)((u8 *)item + 0x3BA) = 1;
            else {
                *(u32 *)((u8 *)item + 0x390) &= ~0x200000;
                *(s16 *)((u8 *)item + 0x3BA) = 0;
            }
            *(u32 *)((u8 *)p + 0x42C) = (u32)fn_1_FD27C;
            *(u32 *)((u8 *)p + 0xC) = 0x20000000;
            fn_1_FCFA4(p);
            *(u32 *)((u8 *)p + 0x42C) = (u32)fn_1_FDD7C;
            *(void **)((u8 *)p + 0xC) = saved;
            *(s16 *)((u8 *)item + 0x3BA) = value;
        }
    }
    return 0;
}
