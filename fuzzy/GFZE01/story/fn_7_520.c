/* Non-matching: best partial attempt (87.53% in the project ledger). Scored for the
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

struct fn_7_520_data {
    u8 pad_0[0x2E74];
    u32 unk_2E74;
    s32 unk_2E78;
    u8 pad_2E7C[0xD20];
    char pad_3A3C[0x1360];
    char fmt_3D9C[0x14];
    char fmt_3DB0[0x18];
    char fmt_3DC8[0x100];
};

struct fn_7_520_flag {
    u8 pad_0[3];
    u8 unk_3;
};

extern struct fn_7_520_bss lbl_7_bss_0;
extern u8 lbl_7_data_0[];
extern struct fn_7_520_flag lbl_1_bss_9C;
extern u32 lbl_801A6410;
extern void *lbl_1_bss_6EAD0;
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
extern s32 fn_1_45D0(u32, u32, void *, u32);
extern void fn_1_46BA0(u32, u32);
extern void fn_1_47E54(s32);
extern void fn_1_41104(u32);
extern u32 fn_1_46BFC(void);
extern u32 fn_1_46B44(u32, void *);
extern u32 fn_80008E84(u32);
extern int sprintf(char *, const char *, ...);
extern s32 fn_1_465D0(char *, s32);
extern void fn_1_4A00(s32, u8, u32);
extern u32 fn_1_A1588(void *, u32);

void fn_7_520(void) {
    struct fn_7_520_data *d;
    struct fn_7_520_bss *p;
    u32 handle;
    s32 t;
    u8 i;
    char buf[56];

    d = (struct fn_7_520_data *)(lbl_7_data_0 + 0x10000);
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
    handle = fn_1_46A60();
    fn_1_4404();
    if (lbl_1_bss_9C.unk_3 != 1) {
        t = (s32)fn_800090A4(lbl_801A6410) - 1;
        d->unk_2E74 = (u32)fn_1_45D0(lbl_801A6410, (u32)t, d->pad_3A3C, 0x25F);
        fn_1_46BA0(d->unk_2E74, (u32)t);
    }
    fn_1_47E54(0xBA);
    fn_1_47E54(0x9A);
    fn_1_47E54(0x9B);
    fn_1_41104(1);
    fn_1_41104(6);
    if (d->unk_2E74 + 1 != 0xFFFF) {
        fn_1_46BFC();
        fn_1_46B44((u32)fn_7_4094, &d->unk_2E74);
    }
    fn_80008E84(handle);
    sprintf(buf, d->fmt_3D9C);
    fn_1_465D0(buf, 1);
    for (i = 1; i < 10; i++) {
        sprintf(buf, d->fmt_3DB0, i);
        fn_1_465D0(buf, 1);
        sprintf(buf, d->fmt_3DC8, i);
        fn_1_465D0(buf, 1);
    }
    p->unk_28 = 0;
    p->unk_2C = 0xA;
    p->unk_30 = 1;
    d->unk_2E78 = -1;
    p->unk_4 = 0;
    fn_1_4A00(1, 0x1E, p->unk_1C);
    fn_1_A1588(lbl_1_bss_6EAD0, 0x2E);
}
