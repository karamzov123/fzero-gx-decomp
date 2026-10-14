/* Non-matching: best partial attempt (15.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/stcoli.h"

extern void fn_1_6BC0(void);
extern void fn_1_A2D84(u32);
extern const f32 lbl_1_rodata_BD8;
extern void fn_1_49F0(u32 *);
extern int fn_1_4C10(void);
extern u32 fn_1_F45A4(void);
extern u32 fn_1_F4594(void);
extern void *fn_1_435C(void *);
extern u32 fn_1_2C908(void);
extern int fn_1_3F8C(void *, void *, int, int);
extern void fn_1_4A00(int, int, void *);
extern void *fn_1_86254(int);
extern u8 fn_1_86624(void);

struct MainAt0 {
    u8 pad0[0x10];
    u8 field10;
    u8 pad11[0x19];
    s16 field2a;
    u8 pad2c[4];
    u32 flags;
    u8 pad34[0x14cc];
    u32 field1500;
    u8 pad1504[0x2f0];
    u16 field17f4;
};
extern Obj_1_bss_7EFD8 lbl_1_bss_7EFD8;
extern u8 lbl_1_data_5F5C[0x10];

void fn_1_3A330(void)
{
    struct MainAt0 *main = (struct MainAt0 *)&lbl_1_bss_3C00;
    u8 *s = (u8 *)&lbl_1_bss_3C00 + 0x30;
    u8 n;
    u16 t;
    u32 x;
    u32 y;
    u32 *tmp;
    int i;
    if (s[8] == 0) fn_1_6BC0();
    if (main->flags & 0x40000) {
        int ok = 1;
        n = s[13];
        if (n == 0) ok = 0;
        else if (n <= s[12] && *(u16 *)(s + 0xa4) == 0) *(u16 *)(s + 0xa4) = 1;
        if (ok) {
            t = *(u16 *)(s + 0xa4);
            if (t) {
                x = (t - 1) & 0xffff;
                *(u16 *)(s + 0xa4) = x;
                y = (u32)(((s64)(s32)0x88888889 * (s32)x) >> 32) + x;
                if (x - (((s32)y >> 5) * 60) == 0 && (((s32)y >> 5) < 10))
                    fn_1_A2D84(0xa9092700);
            } else {
                t = *(u16 *)((u8 *)&lbl_1_bss_3C00 + 0x20000 + 0x1f80);
                *(u16 *)((u8 *)&lbl_1_bss_3C00 + 0x20000 + 0x1f80) = t + 1;
            }
        }
    }
    if ((main->flags & 0x800) && fn_1_4C10() == 0) {
        fn_1_F45A4();
        x = fn_1_F45A4();
        if (fn_1_F4594() >= x || *((u8 *)lbl_1_bss_7EFD8.unk_40 + 0x1b)) {
            if (main->field2a == 41) {
                fn_1_435C((void *)main->field1500);
                fn_1_3F8C(lbl_1_data_5F5C, (void *)fn_1_2C908, 0, 13);
                tmp = (u32 *)&lbl_1_rodata_BD8;
                fn_1_49F0(tmp);
                fn_1_4A00(0, main->field10 ? 120 : 30, (void *)main->field1500);
                if (s[5] == 1) {
                    *(u8 *)((u8 *)fn_1_86254(0) + 0x475) = 0;
                    for (i = 1; i <= (s8)fn_1_86624(); ++i)
                        *(u8 *)((u8 *)fn_1_86254(i) + 0x475) = 0xff;
                }
            }
        }
    }

    {
        u8 *state = (u8 *)&lbl_1_bss_3C00 + 0x30;
        u8 *other = (u8 *)&lbl_1_bss_3C00 + 0x20000;
        u32 result;
        u32 callback = *(u32 *)(state + 0xb4);
        *(u32 *)(other + 0x1f9c) = 0;
        if (callback != 0) {
            result = ((u32 (*)(void))callback)();
            if (result & 4)
                *(u32 *)(other + 0x1f9c) = 1;
            if ((result & 2) && *(s32 *)(other + 0x1fa0) == 0) {
                *(u16 *)((u8 *)&lbl_1_bss_3C00 + 0x17f4) = state[7];
            }
        }
    }
}
