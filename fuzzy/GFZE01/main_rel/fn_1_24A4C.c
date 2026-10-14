/* Non-matching: best partial attempt (82.56% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

extern f32 lbl_1_rodata_840[3];
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E1D8(void *, f32, f32, f32);
extern void lbl_8006E1B0(void *);
extern void fn_1_2BA48(void *);
extern int fn_1_24F10(void *, f32);
extern void fn_1_25004(void *);
extern u32 fn_1_29A0C(void *);
extern int fn_1_248C0(void *, int);
extern void fn_1_2B684(void *);
extern void *fn_1_868C0(s8);
extern void fn_1_A2D84(u32);
extern u32 *lbl_1_bss_3BE0;
extern u32 *lbl_801A66C8;

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))

void fn_1_24A4C(void *p) {
    int i;
    int effect = 0;
    f32 speed;
    u32 flags;
    void *w;

    if (U32(p, 0x58c) & 8) {
        lbl_8006DBAC((u8 *)p + 0xec);
        *(f32 *)0xe000000c = F32(p, 0x7c);
        *(f32 *)0xe000001c = F32(p, 0x80);
        *(f32 *)0xe000002c = F32(p, 0x84);
        if (U16(p, 0x4e0) != 0)
            fn_1_2BA48(p);
        if (U32(p, 0x218) & 0x40) {
            fn_1_24F10(p, 0.33333334f);
            effect = 1;
            if ((U32(p, 0x58c) & 0x200) && (U32(p, 0) & 0x80))
                fn_1_25004(p);
        }
        lbl_8006DBAC((u8 *)p + 0xec);
        *(f32 *)0xe000000c = F32(p, 0x7c);
        *(f32 *)0xe000001c = F32(p, 0x80);
        *(f32 *)0xe000002c = F32(p, 0x84);
        {
            u8 *a = (u8 *)p;
            u8 *b = (u8 *)p + 0x3b4;
            for (i = 0; i < 4; i++) {
                U32(a, 0x258) = U32(a, 0x264);
                U32(a, 0x25c) = U32(a, 0x268);
                U32(a, 0x260) = U32(a, 0x26c);
                lbl_8006E1D8(a + 0x264, F32(a, 0x24c),
                    F32(a, 0x250) + F32(a, 0x288) - F32(a, 0x28c), F32(a, 0x254));
                U32(b, 0xc) = U32(b, 0x18);
                U32(b, 0x10) = U32(b, 0x1c);
                U32(b, 0x14) = U32(b, 0x20);
                lbl_8006E1B0(b);
                a += 0x5c;
                b += 0x30;
            }
        }
        if (!(U32(p, 0x58c) & 0x10)) {
            speed = F32(p, 0x80);
            if (speed < -5000.0f ||
                F32((void *)(u32)U32((void *)(u32)*lbl_1_bss_3BE0, 0x24), 0) - 900.0f <= speed)
                fn_1_25004(p);
        }
        if (F32(p, 0x80) < -10000.0f) {
            f32 zero = 0.0f;
            F32(p, 0x80) = -10000.0f;
            F32(p, 0x94) = zero;
            F32(p, 0x98) = zero;
            F32(p, 0x9c) = zero;
        }
        fn_1_29A0C(p);
        if (U32(p, 0) & 0x8000) {
            F32(p, 0x17c) = 0.0f;
        } else {
            speed = lbl_8006D0B4((f32)(F32(p, 0x94) * F32(p, 0x94)) +
                                 F32(p, 0x98) * F32(p, 0x98) +
                                 F32(p, 0x9c) * F32(p, 0x9c));
            F32(p, 0x17c) = (f32)(216.0 * (f64)(speed / F32(p, 8)));
            speed = F32(p, 0x17c);
            if (speed > F32(p, 0xd8) &&
                ((speed > F32(p, 0xd8) + 80.0f || speed > 1700.0f) &&
                 (U32(p, 0) & 0x03800000)))
                F32(p, 0xd8) = speed;
        }
        if (fn_1_248C0(p, 1)) {
            if (U16(p, 0x214) == 0) {
                U16(p, 0x214) = 180;
                flags = U32(p, 0);
                if (flags & 0x80) {
                    if ((flags & 0x02800000) || effect) {
                        U16(p, 0x214) = (u16)(U16(p, 0x214) + 90);
                    }
                }
                if (U32(p, 0) & 0x40000000)
                    U16(p, 0x214) = 180;
            }
        } else {
            flags = U32(p, 0);
            if (!(flags & 0x08000201)) {
                if ((flags & 0x80) && U16(p, 0x4e0) == 0)
                    fn_1_2B684(p);
            } else if ((flags & 0x280) == 0x280) {
                speed = F32(p, 0x17c);
                if (speed < 10.0f) {
                    F32(p, 0x94) = 0.0f;
                    F32(p, 0x98) = 0.0f;
                    F32(p, 0x9c) = 0.0f;
                    U32(p, 0x7c) = U32(p, 0x88);
                    U32(p, 0x80) = U32(p, 0x8c);
                    U32(p, 0x84) = U32(p, 0x90);
                    U32(p, 0) |= 0x08000000;
                    w = fn_1_868C0((s8)S16(p, 4));
                    if (!(U32(p, 0x58c) & 0x80)) {
                        U32(p, 0x58c) |= 0x100;
                        U32(w, 0x390) |= 0x200000;
                    }
                    U32(p, 0x58c) |= 0x80;
                    if ((s32)(*lbl_801A66C8 + S16(p, 4)) == 0) {
                        fn_1_A2D84(0xa9092e00);
                        if ((s8)U8(p, 0x475) != -1 && !(U32(p, 0) & 0x04000200))
                            fn_1_A2D84(0xa9091200);
                    }
                } else if (speed < 100.0f) {
                    psvec_scale((u8 *)p + 0x94, 0.95f, (u8 *)p + 0x94);
                } else if (speed < 400.0f) {
                    psvec_scale((u8 *)p + 0x94, 0.99f, (u8 *)p + 0x94);
                }
            }
        }
        if (U8(p, 0x4c0) == 0 && !(U32(p, 0) & 0x880)) {
            speed = lbl_8006D0B4((f32)(F32(p, 0x4b4) * F32(p, 0x4b4)) +
                                 F32(p, 0x4b8) * F32(p, 0x4b8) +
                                 F32(p, 0x4bc) * F32(p, 0x4bc));
            if (speed < 200.0f)
                U8(p, 0x4c0) = 60;
        }
    }
}
