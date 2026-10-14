/* Non-matching: best partial attempt (43.47% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/screen_effect.h"
#include "types.h"

typedef struct { u32 x, y, z; } Sig_fn_1_862D4_Triple;
struct Copy20 { u32 a[5]; };
struct Copy16 { u32 a[4]; };
struct Copy24 { u32 a[6]; };

extern const f32 lbl_1_rodata_32C8;
extern const f32 lbl_1_rodata_32CC;
extern const f64 lbl_1_rodata_32D0;
extern const f64 lbl_1_rodata_32D8;
extern s16 fn_1_6B48(void);
extern s32 fn_1_6F84(void);
extern u32 fn_1_1FB80(void *, u32);
extern u32 fn_1_7A6B4(void);
extern u32 fn_1_7AA50(f32);
extern u8 fn_1_58C4(void);
extern void fn_1_681C(u32, u32 *);
extern void fn_1_7A9B8(void);
extern void fn_1_862D4(int, Sig_fn_1_862D4_Triple *);

void fn_1_789E8(void) {
    Obj_1_data_1DFA4 *p = (Obj_1_data_1DFA4 *)&lbl_1_data_1DFA4;
    u8 *base = (u8 *)&lbl_1_bss_6D600;
    u32 i;
    s16 id;
    u32 n;
    f32 t, a, b, q;
    u32 x;
    Sig_fn_1_862D4_Triple loc;
    if (p->unk_8 != -1) {
        p->unk_0 = (f32)(s32)p->unk_4;
        fn_1_7A6B4();
        fn_1_7A9B8();
        if (lbl_1_bss_3BE0 != 0 && lbl_1_bss_3BE0->unk_80 != 0)
            fn_1_7AA50(lbl_1_data_1DFA4.unk_0);

        for (i = 0; i < fn_1_58C4(); i++) {
            u8 *cur = base + 0x20 + i * 0x18;
            u8 *old = base + 0x80 + i * 0x18;
            u8 *newp = base + 0xe0 + i * 0x18;
            u8 *src;
            id = fn_1_6B48();
            if (id >= 0) {
                if (fn_1_6F84() != 0)
                    fn_1_681C(i & 0xff, (u32 *)&loc);
                else
                    fn_1_862D4(id, &loc);
                x = fn_1_1FB80(&loc, 0x4000);
                src = base + ((x & 0x4000) ? 0x140 : 0x158);
            } else {
                src = base + 0x158;
            }

            if (*(u32 *)(cur + 20) != (u32)src) {
                *(struct Copy20 *)old = *(struct Copy20 *)cur;
                *(u32 *)(old + 20) = *(u32 *)(cur + 20);
                *(struct Copy16 *)cur = *(struct Copy16 *)src;
                *(struct Copy24 *)newp = *(struct Copy24 *)src;
                if ((s8)old[15] == 0) {
                    a = *(f32 *)(newp + 8);
                    *(u8 *)old = *newp;
                    *(f32 *)(old + 4) = a;
                    *(f32 *)(old + 8) = a + (a - *(f32 *)(newp + 4));
                    old[12] = newp[12]; old[13] = newp[13]; old[14] = newp[14];
                }
                if ((s8)newp[15] == 0) {
                    a = *(f32 *)(old + 8);
                    *(u8 *)newp = *old;
                    *(f32 *)(newp + 4) = a;
                    *(f32 *)(newp + 8) = a + (a - *(f32 *)(old + 4));
                    newp[12] = old[12]; newp[13] = old[13]; newp[14] = old[14];
                    cur[15] = old[15];
                }
                *(u32 *)(cur + 20) = (u32)src;
                *(u32 *)(cur + 16) = ((s8)newp[0] == (s8)old[0]) ? 0x20 : 0;
            }
            if ((s8)newp[15] != 0)
                *(struct Copy24 *)newp = *(struct Copy24 *)src;
            n = *(u32 *)(cur + 16);
            if ((s32)n < 32)
                *(u32 *)(cur + 16) = n + 1;
            else
                cur[15] = *((u8 *)*(u32 *)(cur + 20) + 15);
            n = *(u32 *)(cur + 16);

            a = *(f32 *)(old + 4);
            b = *(f32 *)(newp + 4);
            q = (f32)(s32)n * lbl_1_rodata_32C8;
            t = lbl_1_rodata_32CC - q;
            if (a != b) *(f32 *)(cur + 4) = t * a + q * b;
            else *(f32 *)(cur + 4) = b;
            a = *(f32 *)(old + 8); b = *(f32 *)(newp + 8);
            if (a != b) *(f32 *)(cur + 8) = t * a + q * b;
            else *(f32 *)(cur + 8) = b;
            if (old[12] != newp[12]) cur[12] = (u8)(s32)(t * (f32)old[12] + q * (f32)newp[12]);
            else cur[12] = newp[12];
            if (old[13] != newp[13]) cur[13] = (u8)(s32)(t * (f32)old[13] + q * (f32)newp[13]);
            else cur[13] = newp[13];
            if (old[14] != newp[14]) cur[14] = (u8)(s32)(t * (f32)old[14] + q * (f32)newp[14]);
            else cur[14] = newp[14];
        }
        p->unk_4++;
    }
}
