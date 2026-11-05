/* Non-matching: best partial attempt (95.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

#include "rel/customize/globals.h"

typedef struct {
    u16 unk_0;
    u8 pad_2[0x6];
    u16 unk_8;
    u8 pad_A[0x6];
    volatile u16 unk_10; /* Volatile: retail rereads these flags for each direction test. */
    u16 unk_12;
} Pad_1_bss_9F8;

typedef struct {
    s16 unk_0;          /* item id */
    u8 pad_2[0x8];
    s16 unk_A;          /* price */
    u8 pad_C[0x4];
} Entry_3_bss_7E6F0;

typedef struct {
    u8 pad_0[0xC2];
    s16 unk_C2;
    s16 unk_C4;
    u8 pad_C6[0xA];
} Obj_3_bss_20;

/* the retail TU's .bss objects this function uses, at their retail offsets, so MWCC addresses them off one
 * section base; the fzgx_pool_gap_ objects span the retail objects in between, which this function does not touch */
Obj_3_bss_0 fzgx_obj_lbl_3_bss_0;
u32 fzgx_obj_lbl_3_bss_8;
u32 fzgx_obj_lbl_3_bss_C;
u8 fzgx_pool_gap_10[0x8];
s16 fzgx_obj_lbl_3_bss_18[4];
Obj_3_bss_20 fzgx_obj_lbl_3_bss_20;
Obj_3_bss_F0 fzgx_obj_lbl_3_bss_F0;
u8 fzgx_pool_gap_120[0x7E6F0 - 0x120];
Entry_3_bss_7E6F0 fzgx_obj_lbl_3_bss_7E6F0[75];
s16 fzgx_obj_lbl_3_bss_7EBA0;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_8;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_C;
    s = *(u8 *)&fzgx_pool_gap_10;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_F0;
    s = *(u8 *)&fzgx_pool_gap_120;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7E6F0;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_7EBA0;
}
#pragma section code_type ".text"

extern Pad_1_bss_9F8 lbl_1_bss_9F8[];
extern s32 fn_1_F809C(s16);
extern void fn_1_F8214(s16);
typedef struct {
    u8 pad_0[0x48F8];
    u32 unk_48F8;
} Obj_1_bss_7F0C0;

extern Obj_1_bss_7F0C0 lbl_1_bss_7F0C0;
extern u32 lbl_801A66A8;

extern void fn_3_7A08(s16 *, s16 *, int);
extern void fn_3_BD00(s32, s32, s32, u32);
extern void fn_1_7B4C0(void);
extern void fn_1_7B2E8(s16);
extern void fn_1_A2D84(u32);
extern s32 fn_1_F9028(s16);
extern void fn_1_F946C(s16);
extern void fn_1_F9888(s16);

/* one frame of the 7E084 list (7E23C entries) for the pad in F0's unk_6: the pad's 0x10/0x12 bits 3 and 2 move the
 * cursor (bss_20 +0xC2) up and down, clamped to the list; on a move, sound 0xA9010000 (sound_play), course_unload when
 * the old entry's unk_2 is 1 and course_map_load(unk_6) when the new one's is; scrolls (fn_3_BD00, +0xC4) when the
 * cursor leaves the rows fn_3_7A08 reports. Bit 8 of +0x8 takes the entry's unk_4 from 7F0C0 +0x48F8 when
 * fn_1_F9028(unk_0) is 0 and the amount covers it. Returns -1 when bit 9 of +0x0 is set, else 0 */
s32 fn_3_7360(void) {
    s16 old;
    Obj_3_bss_20 *s;
    s16 lo;
    s16 d;
    s16 id;
    u32 delta;
    s16 hi;
    s16 cost;
    s16 port;

    port = fzgx_obj_lbl_3_bss_F0.unk_6;
    delta = 0;
    if ((lbl_1_bss_9F8[port].unk_10 >> 3) & 1 || (lbl_1_bss_9F8[port].unk_12 >> 3) & 1) {
        delta = -1;
    }
    if ((lbl_1_bss_9F8[port].unk_10 >> 2) & 1 || (lbl_1_bss_9F8[port].unk_12 >> 2) & 1) {
        delta++;
    }

    d = delta;
    s = &fzgx_obj_lbl_3_bss_20;
    old = s->unk_C2;
    {
        s32 cur;

        cur = old;
        cur += d;
        if (cur < 0) {
            cur = 0;
        } else if (cur > fzgx_obj_lbl_3_bss_7EBA0 - 1) {
            cur = fzgx_obj_lbl_3_bss_7EBA0 - 1;
        }
        s->unk_C2 = cur;
    }
    fzgx_obj_lbl_3_bss_18[0] = (fzgx_obj_lbl_3_bss_18[0] + 1 < 10) ? fzgx_obj_lbl_3_bss_18[0] + 1 : 10;
    if (old != s->unk_C2) {
        fzgx_obj_lbl_3_bss_18[0] = 0;
        fn_1_A2D84(0xA9010000);
        lbl_801A66A8 = 0;
        if (old != s->unk_C2) {
            fn_3_7A08(&lo, &hi, 6);
            if (s->unk_C2 < lo || s->unk_C2 > hi) {
                fn_3_BD00(delta, 0, (s16)(d * 10), 0x08000001);
                fzgx_obj_lbl_3_bss_20.unk_C4 -= delta;
            }
        }
    }
    if ((lbl_1_bss_9F8[port].unk_8 >> 8) & 1) {
        Entry_3_bss_7E6F0 *entry = &fzgx_obj_lbl_3_bss_7E6F0[s->unk_C2];

        id = entry->unk_0;
        cost = entry->unk_A;
        if (fn_1_F809C(id) == 0 && lbl_1_bss_7F0C0.unk_48F8 >= (u32)cost) {
            lbl_1_bss_7F0C0.unk_48F8 -= cost;
            fn_1_F8214(id);
            fzgx_obj_lbl_3_bss_8 = 1;
            fn_1_A2D84(0xA9010100);
            fzgx_obj_lbl_3_bss_C = 1;
        } else {
            fn_1_A2D84(0xA9011400);
        }
    }

    if ((lbl_1_bss_9F8[port].unk_0 >> 9) & 1) {
        fn_1_A2D84(0xA9010200);
        return -1;
    }
    return 0;
}
