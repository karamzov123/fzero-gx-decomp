/* Non-matching: best partial attempt (79.63% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/burner.h"

extern s16 fn_1_3F0C8(void);
extern int fn_1_58C4(void);
extern void fn_1_103030(void);
extern s32 fn_1_9D230(void);
extern void fn_1_9D260(void);
extern void fn_1_9AD54(void);
extern const f32 lbl_1_rodata_4200;
extern const f64 lbl_1_rodata_4208;

typedef void (*Fn)(void);

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    Fn fn;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
} Entry;

typedef struct {
    s16 unk_0;
    u8 unk_2[4];
    u8 flags[4];
    u16 unk_A;
    u32 counters[4];
    f32 floats[4];
    u8 pad_2C[0x18];
    u32 unk_44;
    u8 pad_48[0x3C];
    s32 unk_84;
    u32 unk_88;
    u8 pad_8C[8];
    f32 unk_94;
    f32 unk_98;
    u8 pad_9C[0x330];
    Entry table[4];
} Ax;

typedef struct {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0xC];
    f32 unk_1C;
} AxOut;

void fn_1_9A5CC(void) {
    u8 *base;
    Ax *p;
    u8 *b;
    u32 *w;
    AxOut *o;
    s32 i;
    u32 v;

    base = (u8 *)&lbl_1_data_2A0C0;
    p = (Ax *)(base + 0x720);
    if (p->unk_84 != 0) {
        v = 4;
    } else {
        v = fn_1_58C4();
    }
    b = (u8 *)p;
    w = (u32 *)p;
    o = (AxOut *)(base + 0x2810);
    *(u32 *)(b + 0x88) = v;
    o->unk_C = *(f32 *)(b + 0x98);
    o->unk_1C = *(f32 *)(b + 0x94);
    for (i = 0; i < 4; i++, b++, w++) {
        b[6] = 0;
        if (i == 1) {
            if (fn_1_3F0C8() != 39) {
                b[6] = 1;
            }
        } else {
            b[6] = 1;
        }
        w[3] += b[6];
        if (w[3] >= 6885000) {
            w[3] = 0;
        }
        *(f32 *)(w + 7) = (f32)w[3];
    }
    p->unk_44++;
    if (*(s16 *)&lbl_1_bss_960 == 10) {
        p->flags[1] = 0;
        p->counters[1] = 6885000;
        p->floats[1] = lbl_1_rodata_4200;
    }
    fn_1_103030();
    if (*(s16 *)(base + 0x720) > 0) {
        fn_1_9D260();
        if (fn_1_9D230() == 0) {
            ((Entry *)(base + 0xAEC))[*(s16 *)(base + 0x720)].fn();
        }
    } else {
        fn_1_9AD54();
    }
}
