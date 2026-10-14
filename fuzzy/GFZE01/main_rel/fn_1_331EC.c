/* Non-matching: best partial attempt (70.54% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/game.h"

extern const f32 lbl_1_rodata_BD8;
extern u32 fn_1_F2F34(void);
extern u8 fn_1_3BB0(u32);
extern u8 lbl_1_data_2B60[4];
extern u8 lbl_1_bss_D70[8];
extern u8 fn_1_84794(s32);
extern void *fn_1_82EDC(s16, s16, void *);
extern void *fn_1_22B10(void *, f32);
extern void fn_1_22E8C(void *, void *);

#define W(o) (*(u32 *)((u8 *)p + (o)))
#define H(o) (*(s16 *)((u8 *)p + (o)))
#define B(o) (*(u8 *)((u8 *)p + (o)))
#define F(o) (*(f32 *)((u8 *)p + (o)))
#define G(o) (*(u32 *)(g + (o)))
#define GH(o) (*(s16 *)(g + (o)))
#define GB(o) (*(u8 *)(g + (o)))
#define PF(o) (*(f32 *)(pool + (o)))

void fn_1_331EC(void *arg0) {
    u8 *p = (u8 *)arg0;
    u8 *g = (u8 *)&lbl_1_bss_3C00;
    u8 *pool = (u8 *)&lbl_1_rodata_BD8;
    s32 i;
    s32 id;
    s32 index;
    u8 *vehicle;
    u32 flags;
    f32 value;
    f32 t;
    u8 result;
    void *tmp;
    id = 0;
    if ((G(0x30) & 0x10) == 0 && *(s32 *)((u8 *)*(void **)(p + 0x49c) + 0x118) < 1) {
        W(0) &= 0xFBFFFFFF;
    }
    tmp = *(void **)(g + 0x30 + 0xd0);
    if (tmp != 0) ((void (*)(void *, void *))tmp)(g + 0x30, p);
    if (*(u16 *)(g + 0x30 + 0xa4) != 0) W(0) &= 0xF7FFFFFF;
    if (GB(0x35) == 2) {
        if (!(W(0) & 0x10000)) {
            value = F(0x184);
            if (value > PF(0x1e4) || value <= *(f32 *)(g + 0x20000 + 0x2f44)) W(0x58c) |= 0x40;
        }
        *(f32 *)(g + 0x20000 + 0x2f40) = F(0x184);
    }
    if ((G(0x30) & 0x40000) && *(u16 *)(g + 0x30 + 0xa4) == 0 && !(W(0) & 0x200)) {
        if (F(0x17c) < PF(0xc)) F(0x1fc) = PF(4);
        F(0x1f4) = PF(4); F(0x204) = PF(0x30); F(0x1f8) = PF(4); F(0x200) = PF(4);
        W(0) &= 0xFFF7DFFF; W(0) &= 0xFFFEFFF7; W(0) |= 0x10000000;
    } else if ((G(0x30) & 0x80) && !(W(0) & 0x200)) {
        if (F(0x17c) < PF(0xc)) F(0x1fc) = PF(4);
        F(0x1f4) = PF(4); F(0x204) = PF(0xc); F(0x1f8) = PF(4); F(0x200) = PF(4);
        W(0) &= 0xFFF7DFFF; W(0) &= 0xFFFDFFF7;
    } else if (GH(0x2a) <= 0x28) {
        F(0x1fc) = PF(4); F(0x1f4) = PF(4); F(0x1f8) = PF(4);
        if (G(0x30) & 0x800000) {
            id = 1;
            if (!(W(0) & 4)) F(0x200) = PF(0x24c);
            F(0x204) = PF(4);
            W(0) &= 0xFFF7DFFF; W(0) &= 0xFFFEFFF7;
        }
    } else if (G(0x30) & 0x1000) {
        F(0x1fc) = PF(4); F(0x1f4) = PF(4); F(0x204) = PF(0x240); F(0x1f8) = PF(4); F(0x200) = PF(4);
        W(0) &= 0xFFF7DFFF; W(0) &= 0xFFFEFFF7;
    }
    if (GB(0x35) == 2 && !(W(0) & 0x10000) && (W(0x58c) & 0x2000000)) GB(0x35) = 6;
    result = B(0x474);
    if ((s8)result != -1 && G(0x20000 + 0x2f48) != 0 && B(0x590) == 0) {
        if (G(0x30) & 0x100) {
            if (fn_1_F2F34() == 0) {
                result = fn_1_3BB0((s8)B(0x474)); B(0x590) = result;
                index = H(4);
                ((u8 *)&lbl_1_bss_7EFD8)[index + 0x38] = result;
                ((u8 *)&lbl_1_bss_7EFD8)[index + 0x3c] = lbl_1_data_2B60[index];
                lbl_1_bss_D70[index] = lbl_1_data_2B60[index];
            } else {
                index = H(4); B(0x590) = ((u8 *)&lbl_1_bss_7EFD8)[index + 0x38];
                lbl_1_bss_D70[index] = ((u8 *)&lbl_1_bss_7EFD8)[index + 0x3c];
            }
        } else {
            index = H(4); lbl_1_bss_D70[index] = lbl_1_data_2B60[index];
            B(0x590) = fn_1_3BB0((s8)B(0x474));
        }
    } else if (!(G(0x30) & 0x100000) && G(0x20000 + 0x2f48) != 0 && (s8)B(0x474) != -1) {
        result = fn_1_3BB0((s8)B(0x474));
        if ((s8)result != 0 && B(0x590) != result) { GB(0x1624) = 1; B(0x590) = result; }
    }
    id = (s8)B(0x474);
    index = H(6);
    if (id == -1) {
        for (i = 0; i < 4; i++) {
            if (H(4) == (u8)fn_1_84794(i)) { id = i; break; }
        }
    }
    fn_1_82EDC((s16)id, (s16)index, p + 8);
    if (/* id flag */ 0) {}
    if (id != 0 && !(W(0) & 0x04000000)) { F(0x220) = *(f32 *)(p + 0x10); F(0x22c) = *(f32 *)(p + 0x14); }
    else {
        vehicle = *(u8 **)(g + 0x17f8 + H(4) * 4);
        if (vehicle != 0) {
            t = (f32)vehicle[0xb] * PF(0x210);
            fn_1_22B10(p + 8, t);
        } else {
            t = (f32)*(s16 *)(g + 0x20000 + 0x2048 + H(4) * 2) * PF(0x210);
            fn_1_22B10(p + 8, t);
        }
    }
    if ((G(0x30) & 0x10000) && !(W(0) & 0x04000200)) {
        void *a = *(void **)(g + 0x5c);
        void *b = *(void **)(p + 0x49c);
        f32 f5 = PF(0x138);
        f32 x = (f32)*(s32 *)((u8 *)a + 0x11c);
        f32 y = (f32)*(s32 *)((u8 *)b + 0x11c);
        f32 d = ((x-f5) * *(f32 *)((u8 *)a+0xfc) + *(f32 *)((u8 *)a+0x100)) -
                ((y-f5) * *(f32 *)((u8 *)b+0xfc) + *(f32 *)((u8 *)b+0x100));
        if (d > PF(0x238)) d = PF(0x238);
        d *= PF(0x23c);
        *(f32 *)(p+8+0x10) += *(f32 *)(p+8+0x10) * PF(0x240) * d;
        *(f32 *)(p+8+0x14) += *(f32 *)(p+8+0x14) * PF(0x1cc) * d;
        *(f32 *)(p+8+0x18) += *(f32 *)(p+8+0x18) * PF(0x240) * d;
        *(f32 *)(p+8+0x4c) -= *(f32 *)(p+8+0x4c) * PF(0x244) * d;
        *(f32 *)(p+8+0x3c) += *(f32 *)(p+8+0x3c) * PF(0x248) * d;
        *(f32 *)(p+8+0x4dc) = PF(0xc) - PF(0x248) * d;
    }
    if (!(W(0) & 0x20) && id == 0) fn_1_22E8C(p, p+8);
    if (G(0x30) & 0x10000) W(0) |= 1;
    if (((u8 *)(g+0x20000+0x2f20))[H(4)] && GH(0x2a) == 0x2a) W(0) |= 1;
}
