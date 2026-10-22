/* Non-matching: best partial attempt (98.02% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
/* Non-matching: best partial attempt (96.49% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_7_520_bss {
    u8 pad_0[4];
    u32 unk_4;
    u8 pad_8[0x14];
    u32 unk_1C;
    u8 pad_20[0x8];
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
};

struct fn_7_520_flag {
    u8 pad_0[3];
    s8 unk_3;
};

extern struct fn_7_520_bss lbl_7_bss_0;
extern u8 lbl_7_data_0[];
extern struct fn_7_520_flag lbl_1_bss_9C;
extern u32 lbl_801A6410;
extern void **lbl_1_bss_6EAD0;
extern const f32 lbl_7_rodata_528;

extern void fn_7_4050(void);
extern u32 fn_7_4094(void *, u32, u32, u32);
extern void fn_1_4CC0(void);
extern void fn_8006CE1C(f32);
extern void fn_1_A0680(void);
extern void fn_1_47F74(s32);
extern void fn_1_411A4(u32);
extern u32 fn_1_4706C(void);
extern u32 fn_1_46A60(void);
extern u32 fn_1_4404(void);
extern u32 fn_800090A4(u32);
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern u32 fn_1_46BA0(u32, u32);
extern void fn_1_47E54(s32);
extern void fn_1_41104(u32);
extern u32 fn_1_46BFC(void);
extern u32 fn_1_46B44(u32, void *);
extern u32 fn_80008E84(u32);
extern int sprintf(char *, const char *, ...);
extern s32 fn_1_465D0(char *, s32);
extern void fn_1_4A00(s32, u8, u32);
extern u32 fn_1_A1588(void *, u32);

u32 fn_7_520(void) {
    u8 *base;
    struct fn_7_520_bss *p;
    u32 size;
    u8 i;
    char buf[56];
    const char * lab_t1;

    base = lbl_7_data_0 + 0x10000;
    p = &lbl_7_bss_0;
    fn_7_4050();
    fn_1_4CC0();
    fn_8006CE1C(lbl_7_rodata_528);
    fn_1_A0680();
    fn_1_47F74(0xBA);
    fn_1_47F74(0x9A);
    fn_1_47F74(0x9B);
    fn_1_411A4(1);
    fn_1_411A4(6);
    fn_1_4706C();
    fn_1_46A60();
{
    u32 heap;
    heap = fn_1_4404();
    if (lbl_1_bss_9C.unk_3 != 1) {
        size = fn_800090A4(lbl_801A6410) - 0x10000;
        *(u32 *)(base + 0x2E74) = fn_1_45D0(lbl_801A6410, size, base + 0x3A3C, 0x25F);
        /* fzgx: reloaded */
        fn_1_46BA0(*(volatile u32 *)(base + 0x2E74), size);
    }
    fn_1_47E54(0xBA);
    fn_1_47E54(0x9A);
    fn_1_47E54(0x9B);
    fn_1_41104(1);
    fn_1_41104(6);
    if (*(u32 *)(base + 0x2E74) != 0xFFFFFFFF) {
        fn_1_46BFC();
        fn_1_46B44((u32)fn_7_4094, base + 0x2E74);
    }
    fn_80008E84(heap);
}
    sprintf(buf, (char *)(base + 0x3D9C));
    fn_1_465D0(buf, 1);
    for (i = 1; i < 10; i++) {
        sprintf(buf, (char *)(base + 0x3DB0), i);
        fn_1_465D0(buf, 1);
        lab_t1 = (char *)(base + 0x3DC8);
        sprintf(buf, lab_t1, i);
        fn_1_465D0(buf, 1);
    }
    p->unk_28 = 0;
    p->unk_2C = 10;
    p->unk_30 = 1;
    *(s32 *)(base + 0x2E78) = -1;
    p->unk_4 = 0;
    fn_1_4A00(1, 0x1E, p->unk_1C);
    fn_1_A1588(*lbl_1_bss_6EAD0, 0x2E);
    return (u32)p;
}
