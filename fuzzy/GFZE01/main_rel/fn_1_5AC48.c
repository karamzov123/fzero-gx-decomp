/* Non-matching: best partial attempt (73.52% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/effect.h"

struct Fn_1_5AC48_Pool {
    u8 pad_00[0x8];
    f32 unk_8;
    u8 pad_0C[0x14];
    f64 unk_20;
    f32 unk_28;
    u8 pad_2C[0xC];
    f64 unk_38;
    u8 pad_40[0x14];
    f32 unk_54;
    u8 pad_58[0x8];
    f32 unk_60;
    u8 pad_64[0x8];
    f32 unk_6C;
    f32 unk_70;
    u8 pad_74[0x48];
    f32 unk_BC;
    f32 unk_C0;
};
extern struct Fn_1_5AC48_Pool lbl_1_rodata_2950;

typedef union {
    f32 f;
    u32 i;
} Fn_1_5AC48_FU;

typedef struct {
    u8 pad_00[0x10];
    u32 unk_10;
    u8 pad_14[0x4];
    s16 unk_18;
    u8 pad_1A[0x2];
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[0xC];
    Fn_1_5AC48_FU unk_3C;
    Fn_1_5AC48_FU unk_40;
    Fn_1_5AC48_FU unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
} Fn_1_5AC48_Arg;

typedef struct {
    u8 pad_00[0xC];
    s16 unk_0C;
    u8 pad_0E[0xA];
    s16 unk_18;
    s16 unk_1A;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    u8 pad_54[0x94];
} Fn_1_5AC48_Rec;

typedef struct {
    u8 pad_0[0x2];
    s16 unk_2;
    s16 unk_4;
    u8 pad_6[0x6];
    s16 unk_C;
} Fn_1_5AC48_Slot;

typedef void (*Fn_1_5AC48_Handler)(void *);

extern u32 fn_1_3FC58(u32);
extern void *memset(void *, int, u32);
extern void *memcpy(void *, const void *, u32);

void fn_1_5AC48(Fn_1_5AC48_Arg *arg0) {
    struct Fn_1_5AC48_Pool *pool = &lbl_1_rodata_2950;
    Fn_1_5AC48_Arg *a = arg0;
    Fn_1_5AC48_Rec rec;

    a->unk_4C = a->unk_4C + pool->unk_BC;
    a->unk_48 = a->unk_48 * pool->unk_70;
    a->unk_4C = a->unk_4C * pool->unk_70;
    a->unk_50 = a->unk_50 * pool->unk_70;
    a->unk_3C.f = a->unk_3C.f + a->unk_48;
    a->unk_40.f = a->unk_40.f + a->unk_4C;
    a->unk_44.f = a->unk_44.f + a->unk_50;

    memset(&rec, 0, 0xe8);
    rec.unk_18 = a->unk_18;
    rec.unk_0C = 8;
    rec.unk_1A = -1;
    rec.unk_34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 0x70);

    {
        u32 rnd = lbl_1_data_1D628 * 0x41c64e6d + 0x3039;
        lbl_1_data_1D628 = rnd;
        rec.unk_2C = a->unk_2C * (pool->unk_C0 * ((f32)((rnd >> 16) & 0x7fff) / pool->unk_8));
    }

    rec.unk_3C = a->unk_3C.i;
    rec.unk_40 = a->unk_40.i;
    rec.unk_44 = a->unk_44.i;
    rec.unk_48 = pool->unk_54 * a->unk_48;
    rec.unk_4C = pool->unk_54 * a->unk_4C;
    rec.unk_50 = pool->unk_54 * a->unk_50;
    rec.unk_28 = pool->unk_6C * a->unk_28;
    rec.unk_1C = a->unk_1C;
    rec.unk_20 = a->unk_20;
    rec.unk_24 = a->unk_24;

    if (fn_1_3FC58(a->unk_1C) == 0) {
        u8 *p = *(u8 **)&lbl_1_bss_6C848;
        s32 idx = 0;

        while (idx < 190) {
            if (*(s8 *)p == 0) {
                *p = 1;
                goto found;
            }
            p += 0xe8;
            idx++;
        }
        idx = -1;
    found:
        if (idx >= 0) {
            Fn_1_5AC48_Slot *slot =
                (Fn_1_5AC48_Slot *)(*(u8 **)&lbl_1_bss_6C848 + idx * 0xe8);
            s16 c;

            memcpy(slot, &rec, 0xe8);
            *(u8 *)slot = 1;
            slot->unk_2 = (s16)idx;
            ((Fn_1_5AC48_Handler *)lbl_1_data_1D1D8)[slot->unk_C](slot);
            slot->unk_4 = lbl_1_bss_6C850.unk_0;
            c = lbl_1_bss_6C850.unk_0 + 1;
            lbl_1_bss_6C850.unk_0 = c;
            if (c < 0) {
                lbl_1_bss_6C850.unk_0 = 0;
            }
        }
    }

    if ((f32)(s32)a->unk_10 < pool->unk_60) {
        a->unk_28 = a->unk_28 * (pool->unk_28 - pool->unk_28 / (f32)((s32)a->unk_10 + 1));
    }
}
