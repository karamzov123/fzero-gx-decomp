#include "types.h"

/* main .text, size 0x41C */

extern char lbl_8009103C[39];
extern void fn_800474E4(u32);
extern u8 lbl_80178CBC[3076];
extern void *memset(void *, int, u32);
extern void *fn_80058498(u32, u32, u32);
extern void fn_8004CAC8(void *);
extern void *fn_8004B4E0(int, int);
extern void *fn_80042228(void *, s32, void **);
extern void *fn_8004EF28(void *, s32, void *);
extern void *fn_800571EC(void *);
extern void fn_8005710C(void *, int);
extern const f64 lbl_80090A20;  /* = 4503601774854144.0 */
extern const f32 lbl_80091064;  /* = 0.8500000238418579f */

typedef struct Slot4CD70 {
    u8 used;          /* 0x00 */
    u8 pad_01[3];
    void *field_04;   /* 0x04 */
    void *field_08;   /* 0x08 */
    void *field_0C;   /* 0x0C */
    void *field_10;   /* 0x10 */
    u32 field_14;     /* 0x14 */
    void *field_18[16]; /* 0x18 */
    u32 field_20;     /* 0x20 */
    u32 field_24;     /* 0x24 */
    u32 field_28;     /* 0x28 */
    u32 field_2C;     /* 0x2C */
    u32 field_30;     /* 0x30 */
    u32 field_34;     /* 0x34 */
    u32 field_38;     /* 0x38 */
    s16 field_3C;     /* 0x3C */
    s16 field_3E;     /* 0x3E */
    s16 field_40;     /* 0x40 */
    union {
        s16 run[8];       /* 0x42..0x52 */
        struct {
            s16 field_42;
            s16 field_44;
            s16 field_46;
            s16 field_48;
            s16 field_4A;
            s16 field_4C;
            s16 field_50;
            s16 field_52;
        } f;
    } u42;
    u32 field_54;     /* 0x54 */
    u32 field_58;     /* 0x58 */
    u32 field_5C;     /* 0x5C */
    s16 field_60;     /* 0x60 */
    u32 field_64;     /* 0x64 */
    s16 field_68;     /* 0x68 */
    s16 field_6A;     /* 0x6A */
    u8 field_6C;      /* 0x6C */
    u8 field_6D;      /* 0x6D */
    u8 pad_6E[0x26];
    void *field_94;   /* 0x94 */
    u8 pad_98[0x14];
    u32 field_AC;     /* 0xAC */
} Slot4CD70;

/* fn_8004CD70(r3 = ?, r4 = a, r5 = b): allocate and initialise a slot from the
 * 16-entry table at lbl_80178CBC. Returns the slot, or NULL when the table is
 * full, the arguments are out of range, or any allocation step fails. */
void *fn_8004CD70(void *arg, s32 a, s32 b) {
    Slot4CD70 *slot;
    s32 i;
    u32 rounded;
    u32 slack;
    s16 vol;
    f64 tmp;

    if (a < 0 || a == 0 || b < 0) {
        fn_800474E4((u32)lbl_8009103C);
        return 0;
    }

    {
        Slot4CD70 *table = (Slot4CD70 *)lbl_80178CBC;
        for (i = 0; i < 16; i++) {
            if ((s8)table[i].used == 0) {
                break;
            }
        }
        if (i == 16) {
            return 0;
        }
        slot = &table[i];
    }

    memset(slot, 0, 0xC0);

    rounded = (a + 0x3F) & ~0x3F;
    slack = (u32)(b - (rounded - a) - 0x124);
    slack = (slack >> 11) << 11;

    slot->field_20 = rounded;
    slot->field_24 = slack;
    slot->field_28 = 0x24;
    slot->field_AC = slot->field_28 + slot->field_20 + slack;
    slot->field_2C = b;
    slot->field_30 = a;
    slot->field_34 = 0;
    slot->field_14 = 0;

    slot->field_10 = fn_80058498(slot->field_20, slot->field_24, slot->field_28);
    if (slot->field_10 == 0) {
        fn_8004CAC8(slot);
        return 0;
    }

    slot->field_08 = fn_8004B4E0(0, 0);
    if (slot->field_08 == 0) {
        fn_8004CAC8(slot);
        return 0;
    }

    /* per-channel scratch buffers: 8004CF6C..8004CFC0 */
    for (i = 0; i < a; i++) {
        slot->field_18[i] = fn_80058498(
            slot->field_2C + (u32)(slot->field_34 * i) * 2,
            (u32)(slot->field_34 - slot->field_30) * 2,
            (u32)(slot->field_30 * i) * 2);
        if (slot->field_18[i] == 0) {
            fn_8004CAC8(slot);
            return 0;
        }
    }

    slot->field_04 = fn_80042228(slot->field_10, a, (void **)&slot->field_18[0]);
    if (slot->field_04 == 0) {
        fn_8004CAC8(slot);
        return 0;
    }

    /* 8004CFF0: mulli r0,r28,0x40c0 ; add r5,r30,r0 */
    slot->field_0C = fn_8004EF28((void *)&slot->field_18[0], a,
                                 (void *)((u8 *)slot + a * 0x40C0));
    if (slot->field_0C == 0) {
        fn_8004CAC8(slot);
        return 0;
    }

    slot->field_94 = fn_800571EC(slot->field_10);
    if (slot->field_94 == 0) {
        fn_8004CAC8(slot);
        return 0;
    }

    fn_8005710C(slot->field_94, (int)(u32)slot->field_08);

    slot->field_38 = 0x3C;
    slot->field_3C = (s16)(s32)(slot->field_24 >> 11);
    vol = (s16)(s32)((f64)(s16)(slot->field_3C ^ 0x8000) * lbl_80091064 - lbl_80090A20);
    slot->field_3E = vol;
    slot->field_40 = 0;

    for (i = 0; i < a; i++) {
        slot->u42.run[i] = -0x80;
    }

    slot->u42.f.field_46 = 0;
    slot->field_6C = 1;
    slot->field_54 = 0;
    slot->field_58 = 0;
    slot->field_5C = 0;
    slot->field_60 = 0;
    slot->field_64 = 0;
    slot->field_68 = 0;
    slot->field_6A = 0;
    slot->field_6D = 1;

    return slot;
}
