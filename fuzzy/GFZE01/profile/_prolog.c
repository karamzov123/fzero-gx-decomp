/* Non-matching: best partial attempt (50.43% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/profile/data/lbl_16_data_0.h"

struct _prolog_lbl_1_bss_8B614 { u8 pad_0[4]; u32 unk_4; };
struct PrologPtrs { u32 p[42]; };
struct PrologState { u8 pad[0x154]; };
extern struct _prolog_lbl_1_bss_8B614 lbl_1_bss_8B614;
extern struct PrologPtrs lbl_16_bss_0;
extern ProfileTextData lbl_16_data_0;
extern const f32 lbl_16_rodata_0[18];
extern u32 lbl_1_bss_7167C, lbl_1_bss_71680, lbl_1_bss_71684;
extern s16 lbl_1_bss_96A;
extern u8 lbl_1_bss_8B3A0[];
extern u32 lbl_801A66B4, lbl_801A6410;
extern void fn_16_96C(u32);
extern void fn_16_9EC(void);
extern void fn_16_910(void);
extern void *fn_16_B10(void);
extern void fn_16_A34(void);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_4BB0(void);
extern void fn_8006CE1C(f32);
extern s32 fn_1_45D0(u32, u32, u32, u32);
extern void fn_1_3CF0(u32, u32);
extern u32 fn_1_435C(u32);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_7BA08(u16,u16,u16);
extern void fn_1_7BA48(void);
extern void fn_1_A0680(void);
extern void fn_1_47F74(s32);
extern void fn_1_411A4(u32);
extern u16 fn_1_A5D88(void);
extern void fn_1_8CED0(void *, u16, u16);
extern void fn_1_8D0A4(void *);
void _prolog(void) {
    u8 *d = (u8 *)&lbl_16_data_0;
    u8 *b = (u8 *)&lbl_16_bss_0;
    u8 *q;
    u32 v = lbl_1_bss_8B614.unk_4;
    u32 vals[] = {0x65,0x6d,0x80,0x58,0x69,0x75,0x64,0x74,0x63,0x6c,0x5a,0x6e,0x82,0x6b,0x79,0x68,0x6a,0x59,0x6f,0x57,0x72,0x7e,0x73,0x71,0x5b,0x81,0x62,0x7a,0x5d,0x7c,0x5c,0x61,0x60,0x5e,0x7f,0x5f,0x77,0x70,0x76,0x78,0x7d,0x9a,0x89,0x93};
    s32 i;
    lbl_1_bss_7167C = (u32)fn_16_96C;
    lbl_1_bss_71680 = (u32)fn_16_9EC;
    lbl_1_bss_71684 = (u32)fn_16_910;
    if ((v & 0x20000000) == 0) {
        lbl_1_bss_96A = (s16)0xbf;
        fn_80008BEC(0, 0x140c, 0);
        lbl_1_bss_8B614.unk_4 = (lbl_1_bss_8B614.unk_4);
    } else {
        lbl_1_bss_8B614.unk_4 = v & ~0x20000000;
        lbl_1_bss_96A = (s16)0xc0;
    }
    ((struct PrologPtrs *)b)->p[1] = (u32)d;
    ((struct PrologPtrs *)b)->p[2] = (u32)(d + 0x30000);
    ((struct PrologPtrs *)b)->p[3] = (u32)(d + 0x60000);
    ((struct PrologPtrs *)b)->p[4] = (u32)(d + 0x90000);
    ((struct PrologPtrs *)b)->p[5] = (u32)(d + 0xC0000);
    ((struct PrologPtrs *)b)->p[6] = (u32)(d + 0xF0000);
    ((struct PrologPtrs *)b)->p[7] = (u32)(d + 0x120000);
    ((struct PrologPtrs *)b)->p[8] = (u32)(d + 0x150000);
    ((struct PrologPtrs *)b)->p[9] = (u32)(d + 0x180000);
    ((struct PrologPtrs *)b)->p[10] = (u32)(d + 0x1b0000);
    ((struct PrologPtrs *)b)->p[11] = (u32)(d + 0x1e0000);
    ((struct PrologPtrs *)b)->p[12] = (u32)(d + 0x210000);
    ((struct PrologPtrs *)b)->p[13] = (u32)(d + 0x240000);
    ((struct PrologPtrs *)b)->p[14] = (u32)(d + 0x270000);
    ((struct PrologPtrs *)b)->p[15] = (u32)(d + 0x2a0000);
    ((struct PrologPtrs *)b)->p[16] = (u32)(d + 0x2d0000);
    ((struct PrologPtrs *)b)->p[17] = (u32)(d + 0x300000);
    ((struct PrologPtrs *)b)->p[18] = (u32)(d + 0x330000);
    ((struct PrologPtrs *)b)->p[19] = (u32)(d + 0x360000);
    ((struct PrologPtrs *)b)->p[20] = (u32)(d + 0x390000);
    ((struct PrologPtrs *)b)->p[21] = (u32)(d + 0x3c0000);
    ((struct PrologPtrs *)b)->p[22] = (u32)(d + 0x3f0000);
    ((struct PrologPtrs *)b)->p[23] = (u32)(d + 0x420000);
    ((struct PrologPtrs *)b)->p[24] = (u32)(d + 0x450000);
    ((struct PrologPtrs *)b)->p[25] = (u32)(d + 0x480000);
    ((struct PrologPtrs *)b)->p[26] = (u32)(d + 0x4b0000);
    ((struct PrologPtrs *)b)->p[27] = (u32)(d + 0x4e0000);
    ((struct PrologPtrs *)b)->p[28] = (u32)(d + 0x510000);
    ((struct PrologPtrs *)b)->p[29] = (u32)(d + 0x540000);
    ((struct PrologPtrs *)b)->p[30] = (u32)(d + 0x570000);
    ((struct PrologPtrs *)b)->p[31] = (u32)(d + 0x5a0000);
    ((struct PrologPtrs *)b)->p[32] = (u32)(d + 0x5d0000);
    ((struct PrologPtrs *)b)->p[33] = (u32)(d + 0x600000);
    ((struct PrologPtrs *)b)->p[34] = (u32)(d + 0x630000);
    ((struct PrologPtrs *)b)->p[35] = (u32)(d + 0x660000);
    ((struct PrologPtrs *)b)->p[36] = (u32)(d + 0x690000);
    ((struct PrologPtrs *)b)->p[37] = (u32)(d + 0x6c0000);
    ((struct PrologPtrs *)b)->p[38] = (u32)(d + 0x6f0000);
    ((struct PrologPtrs *)b)->p[39] = (u32)(d + 0x720000);
    ((struct PrologPtrs *)b)->p[40] = (u32)(d + 0x750000);
    ((struct PrologPtrs *)b)->p[41] = (u32)(d + 0x780000);
    fn_1_4BB0();
    fn_8006CE1C(lbl_16_rodata_0[0]);
    fn_1_45D0(lbl_801A6410, 0x9bc, (u32)&((u8 *)0)[0], 0xa2);
    fn_1_45D0(lbl_801A6410, 0x9bc, (u32)&((u8 *)0)[0], 0xa3);
    fn_1_3CF0(0, 0x20);
    fn_1_3CF0(0, 0x20);
    fn_1_435C(0);
    fn_1_435C(0);
    fn_1_3F8C(0, 0, 0, 0);
    fn_1_7BA08(0x20, 0x20, 0x40);
    fn_1_45D0(0, 0, 0, 0xab);
    fn_1_7BA48();
    fn_1_435C(0);
    fn_1_3F8C(0, 0, 0, 2);
    fn_1_A0680();
    fn_1_47F74(0x65); fn_1_47F74(0x6d); fn_1_47F74(0x80); fn_1_47F74(0x58);
    fn_1_47F74(0x69); fn_1_47F74(0x75); fn_1_47F74(0x64); fn_1_47F74(0x74);
    fn_1_47F74(0x63); fn_1_47F74(0x6c); fn_1_47F74(0x5a); fn_1_47F74(0x6e);
    fn_1_47F74(0x82); fn_1_47F74(0x6b); fn_1_47F74(0x79); fn_1_47F74(0x68);
    fn_1_47F74(0x6a); fn_1_47F74(0x59); fn_1_47F74(0x6f); fn_1_47F74(0x57);
    fn_1_47F74(0x72); fn_1_47F74(0x7e); fn_1_47F74(0x73); fn_1_47F74(0x71);
    fn_1_47F74(0x5b); fn_1_47F74(0x81); fn_1_47F74(0x62); fn_1_47F74(0x7a);
    fn_1_47F74(0x5d); fn_1_47F74(0x7c); fn_1_47F74(0x5c); fn_1_47F74(0x61);
    fn_1_47F74(0x60); fn_1_47F74(0x5e); fn_1_47F74(0x7f); fn_1_47F74(0x5f);
    fn_1_47F74(0x77); fn_1_47F74(0x70); fn_1_47F74(0x76); fn_1_47F74(0x78);
    fn_1_47F74(0x7d); fn_1_47F74(0x9a); fn_1_47F74(0x89); fn_1_47F74(0x93);
    fn_1_411A4(1);
    for (i=0;i<2;i++) {
        q = (u8 *)((u32)b + 0x154 + i*0x64);
        fn_1_8CED0(q, fn_1_A5D88(), 0x1e0);
        fn_1_8D0A4(q);
    }
    fn_16_A34();
}
