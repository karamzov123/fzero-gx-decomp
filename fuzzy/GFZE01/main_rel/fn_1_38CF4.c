/* Non-matching: best partial attempt (97.73% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/stcoli.h"

extern void *fn_1_86900(s8);
extern void fn_1_8019C(void *);
extern void fn_1_12B3F8(void *, void *, void *, void *, void *, void *);
extern void fn_1_81408(void *, u8, u8);
extern void fn_1_A75DC(void *, int);
extern void fn_1_1596DC(int);
extern void fn_1_48140(int);
extern void fn_1_412A0(int);
extern void fn_1_A8F78(void);
extern void fn_1_30054(void);
extern void fn_1_5370(int, int);
extern void fn_1_FCF74(void);
extern void fn_800713E0(void *, u32);
extern u32 fn_80008E84(u32);

typedef struct {
    u8 pad_0[0xB];
    u8 unk_B;
} Sub38CF4;

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[2];
    u8 unk_8;
    u8 pad_9[0x14C];
    u8 unk_155;
} Hdr38CF4;

#pragma opt_propagation off
#pragma opt_lifetimes off
#pragma opt_common_subs off
void fn_1_38CF4(void) {
    u8 *g3;
    u8 *g2;
    u8 *base;
    u8 *part;
    s16 *tab;
    u8 *out;
    u8 *p8;
    s16 i;
    s16 j;
    s16 n;
    s8 flag;
    u8 *car;
    void *m;
    u32 saved;
    Hdr38CF4 * hdr_2;
    Hdr38CF4 *hdr;
    Sub38CF4 **pp;
    s16 *dst;
    u8 *src;
    u32 saved_2;
    u8 * q_2;
    s16 k;
    u8 *q;
    s8 lab_t0;
    s8 lab_t0_;

    base = &lbl_1_bss_3C00;
    k = 0;
    hdr = (Hdr38CF4 *)(base + 0x30);
    p8 = (u8 *)&lbl_1_bss_8B3A0;
    g2 = base + 0x20000;
    src = p8;
    g3 = base + 0x30000;
    pp = (Sub38CF4 **)(base + 0x17F8);
    dst = (s16 *)(g2 + 0x2048);
    flag = hdr->unk_8 == 1;
    for (k = 0; k < hdr->unk_8; k++) {
        if (*pp == NULL) {
            *dst = src[0x9F];
        } else {
            (*pp)->unk_B = src[0x9F];
        }
        pp++;
        src++;
        dst++;
    }
    hdr_2 = (Hdr38CF4 *)(base + 0x30);
    if (hdr_2->unk_5 == 2) {
        if (((Sub38CF4 **)(base + 0x17F8))[0] == NULL) {
            hdr_2->unk_155 = ((s16 *)(g2 + 0x2048))[0];
        } else {
            hdr_2->unk_155 = ((Sub38CF4 **)(base + 0x17F8))[0]->unk_B;
        }
    }
    for (i = 0; i < 4; i++) {
        lab_t0 = i;
        lab_t0_ = lab_t0;
        car = fn_1_86900(lab_t0_);
        if (car != NULL && !(*(u32 *)(car + 0x390) & 0x4000000)) {
            tab = (s16 *)(g2 + 0x6BE0);
            tab[(s8)car[0x328] * 0x220 + 0x1DC] = *(s16 *)(car + 0x3B8);
            part = car;
            for (j = 0; j < 6; part += 12, j++) {
                m = *(void **)(part + 0x338);
                if (m != NULL) {
                    fn_800713E0(m, ((u32 *)car)[*(s16 *)(car + 0x3B8) % 4 + 0xDF]);
                    fn_1_8019C(m);
                }
            }
        }
    }
    saved = fn_80008E84(*(u32 *)(g2 + 0x20CC));
    fn_1_12B3F8(g2 + 0x3070, *(void **)(g2 + 0x1F88), *(void **)(g2 + 0x20A4),
                g3 + 0x45C0, g3 + 0x45D0, g3 + 0x45F0);
    fn_80008E84(saved);
    out = base + 0x163C;
    for (i = 0; i < 4; i++) {
        lab_t0 = i;
        lab_t0_ = lab_t0;
        car = fn_1_86900(lab_t0_);
        if (car != NULL) {
            if (p8[0x14] != (u8)(1 << *(s16 *)(car + 0x3B8))) {
                if (*(u32 *)(car + 0x390) & 0x4000000) {
                    q = p8 + 0x14;
                    for (n = 0; n < 8; n++) {
                        if ((1 << n) == *q) {
                            break;
                        }
                    }
                    *(s16 *)(car + 0x3B8) = n;
                } else {
                    fn_1_81408(car, 1 << *(s16 *)(car + 0x3B8),
                               p8[0x14] << (flag ? 0 : 4));
                }
            }
            q_2 = p8 + 0x14;
            for (n = 0; n < 32; n++) {
                if ((1 << n) == *q_2) {
                    break;
                }
            }
            fn_1_A75DC(car, n);
            *out = 1 << *(s16 *)(car + 0x3B8);
        }
        p8 += 0x20;
        out++;
    }
    fn_1_1596DC(2);
    fn_1_48140(0xA1);
    saved_2 = fn_80008E84(*(u32 *)(g2 + 0x20CC));
    fn_1_412A0(1);
    if (flag) {
        fn_1_48140(0x9B);
    } else {
        fn_1_48140(0x9D);
    }
    fn_1_48140(0x9A);
    fn_80008E84(saved_2);
    fn_1_A8F78();
    if (*(s32 *)(g2 + 0x2270) != 0) {
        fn_1_30054();
    }
    if (lbl_1_data_5B86 >= 40) {
        u32 w0 = *(u32 *)(base + 0x30);
        u32 w1 = w0 | 0x200;
        s32 r = (w1 & 0x201) != 0;
        u32 w2 = w1 & ~0x200;
        *(u32 *)(base + 0x30) = w1;
        w1 = (w1 & ~0x200) | (w0 & 0x200);
        *(u32 *)(base + 0x30) = w2;
        *(u32 *)(base + 0x30) = w1;
        *(s16 *)(base + 0x14E8) = r + 0x27;
    }
    fn_1_5370(0, 0);
    fn_1_FCF74();
    if (g3[0x45F4] != 0) {
        *(u32 *)(base + 0x30) |= 0x100000;
    }
}
#pragma opt_common_subs reset

#pragma opt_lifetimes reset
#pragma opt_propagation reset
