/* Non-matching: best partial attempt (89.36% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"

extern f32 lbl_3_rodata_44[45];

extern void fn_3_11FA0(void);
extern void fn_3_130A8(void);
extern void fn_8006CE1C(f32);
extern void fn_1_3C78(void);
extern u32 fn_1_435C(u32);
extern void fn_1_41A8(void);
extern void fn_1_6400(void);
extern void fn_1_46B4(u32, u32, const char *, int);
extern void OSReport(const char *, ...);
extern void fn_1_A0AA4(void);
extern s32 fn_1_46DC4(s32);
extern void fn_1_48140(int);
extern void fn_1_412A0(u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_1_56298(f32, f32, f32, f32);
extern u32 *lbl_801A6410;
extern u32 *lbl_801A66C8;
extern s32 lbl_1_bss_970;

typedef struct Sig_fn_1_8D168_Fn1_8D168State {
    u8 pad[0x60];
    u32 field_60;
} Sig_fn_1_8D168_Fn1_8D168State;

extern void fn_1_8D168(Sig_fn_1_8D168_Fn1_8D168State *);

typedef struct {
    u8 pad_0[0x84c];
    u32 unk_84c;
    u32 unk_850;
    u32 unk_854;
    u8 pad_858[0x41e0 - 0x858];
    Sig_fn_1_8D168_Fn1_8D168State state[4];
} Obj_epilog;

#pragma opt_dead_assignments off
void _epilog(void) {
    u8 *bss = (u8 *)&lbl_3_bss_0;
    u8 *data = (u8 *)&lbl_3_data_0;
    Obj_epilog *p = (Obj_epilog *)(bss + 0x20000);
    u16 i;
    s32 t;
    u32 h;

    fn_8006CE1C(lbl_3_rodata_44[0]);
    fn_1_3C78();
    fn_1_435C(p->unk_84c);
    fn_1_41A8();
    fn_1_435C(p->unk_850);
    fn_1_41A8();
    fn_1_6400();
    fn_1_46B4(*lbl_801A6410, *(u32 *)(bss + 0x10),
        (const char *)(data + 0x11dc), 0x45e);
    h = *lbl_801A6410;
    *(u32 *)(bss + 0x10) = 0;
    fn_1_46B4(h, p->unk_84c, (const char *)(data + 0x11dc), 0x461);
    fn_1_46B4(*lbl_801A6410, p->unk_850,
        (const char *)(data + 0x11dc), 0x462);
    OSReport((const char *)(data + 0x1218), *lbl_801A66C8);
    fn_1_46B4(*lbl_801A6410, p->unk_854,
        (const char *)(data + 0x11dc), 0x465);
    p->unk_854 = 0;

    for (i = 0; i < 4; i++) {
        fn_1_8D168(&p->state[i]);
    }

    fn_1_48140(0x9a);
    fn_1_48140(0x89);
    fn_1_412A0(1);
    fn_1_412A0(3);
    fn_80008BEC(&lbl_3_bss_140, 0, 0x20700);
    fn_3_11FA0();
    fn_3_130A8();
    ((u8 *)&lbl_1_bss_970)[4] = 0;
    {
        f32 v;

        v = lbl_3_rodata_44[0];
        fn_1_56298(v, v, v, v);
    }
    fn_1_A0AA4();
    t = (s32)(data + 0x1164);
    fn_1_46DC4(t);
    t = (s32)(data + 0x1180);
    fn_1_46DC4(t);
}
#pragma opt_dead_assignments reset
