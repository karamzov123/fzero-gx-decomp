#include "types.h"
typedef struct Sig_fn_1_8D168_Fn1_8D168State {
    u8 pad[0x60];
    u32 field_60;
} Sig_fn_1_8D168_Fn1_8D168State;

struct _epilog_lbl_16_bss_0 {
    u32 unk_0;
    u8 pad_4[0x148];
    u32 unk_14C;
    u32 unk_150;
};
struct _epilog_lbl_801A6410 {
    u32 unk_0;
};

extern struct _epilog_lbl_16_bss_0 lbl_16_bss_0;
extern struct _epilog_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_412A0(u32);
extern u32 fn_1_435C(u32);
extern s32 fn_1_467F4(void);
extern u32 fn_1_A0AA4(void);
extern u32 lbl_16_data_82BF8;
extern void fn_1_3308(void);
extern void fn_1_41A8(void);
extern void fn_1_451E4(void);
extern void fn_1_469BC(void);
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_48140(int);
extern void fn_1_8D168(Sig_fn_1_8D168_Fn1_8D168State *);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);

void _epilog(void) {
    struct _epilog_lbl_16_bss_0 *p_lbl_16_bss_0;
    Sig_fn_1_8D168_Fn1_8D168State * v2;
    s16 v1;
    p_lbl_16_bss_0 = (struct _epilog_lbl_16_bss_0 *)&lbl_16_bss_0;
    v1 = 0;
    v2 = (Sig_fn_1_8D168_Fn1_8D168State *)(void *)(((u8 *)p_lbl_16_bss_0 + 0x154));
    while ((u32)(s16)v1 < 2) {
        fn_1_8D168(v2);
        v2 = (Sig_fn_1_8D168_Fn1_8D168State *)(void *)(((u8 *)v2 + 0x64));
        v1++;
    }
    fn_1_412A0(1);
    fn_1_48140(0x93);
    fn_1_48140(0x89);
    fn_1_48140(0x9a);
    fn_1_48140(0x65);
    fn_1_48140(0x6d);
    fn_1_48140(0x80);
    fn_1_48140(0x58);
    fn_1_48140(0x69);
    fn_1_48140(0x75);
    fn_1_48140(0x64);
    fn_1_48140(0x74);
    fn_1_48140(0x63);
    fn_1_48140(0x6c);
    fn_1_48140(0x5a);
    fn_1_48140(0x6e);
    fn_1_48140(0x82);
    fn_1_48140(0x6b);
    fn_1_48140(0x79);
    fn_1_48140(0x68);
    fn_1_48140(0x6a);
    fn_1_48140(0x59);
    fn_1_48140(0x6f);
    fn_1_48140(0x57);
    fn_1_48140(0x72);
    fn_1_48140(0x7e);
    fn_1_48140(0x73);
    fn_1_48140(0x71);
    fn_1_48140(0x5b);
    fn_1_48140(0x81);
    fn_1_48140(0x62);
    fn_1_48140(0x7a);
    fn_1_48140(0x5d);
    fn_1_48140(0x7c);
    fn_1_48140(0x5c);
    fn_1_48140(0x61);
    fn_1_48140(0x60);
    fn_1_48140(0x5e);
    fn_1_48140(0x7f);
    fn_1_48140(0x5f);
    fn_1_48140(0x77);
    fn_1_48140(0x70);
    fn_1_48140(0x76);
    fn_1_48140(0x78);
    fn_1_48140(0x7d);
    fn_1_A0AA4();
    fn_1_435C(p_lbl_16_bss_0->unk_14C);
    fn_1_41A8();
    fn_1_435C(p_lbl_16_bss_0->unk_150);
    fn_1_41A8();
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_16_bss_0->unk_0, (const char *)&lbl_16_data_82BF8, 0xda);
    fn_1_469BC();
    while (fn_1_467F4() != 0) {
        fn_1_451E4();
        fn_1_3308();
        fn_1_D3214();
        VIWaitForRetrace();
    }
}
