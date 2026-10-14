/* Non-matching: best partial attempt (95.86% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/customize/emblem.h"

struct fn_3_137AC_FontPacket {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x20];
    u32 unk_30;
    u8 pad_34[0x24];
};

struct fn_3_137AC_Sel {
    u8 unk_0;
    u8 unk_1;
};

struct fn_3_137AC_FlagWord {
    u32 unk_0 : 24;
    u32 unk_1 : 1;
    u32 unk_2 : 7;
};

extern struct fn_3_137AC_FontPacket lbl_1_rodata_26F8;
extern f32 lbl_3_rodata_4E0[22];
extern struct fn_3_137AC_Sel lbl_3_bss_A17D0;

extern void fn_1_133DBC(void *);
extern void fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_1318D4(void);
extern s32 fn_1_B8EDC(u32);
extern u32 fn_3_19C94(void);
extern u32 fn_3_19CE0(void);
extern u32 fn_3_18960(u32);
extern u32 fn_3_15F44(u32);
extern u32 fn_3_17854(u32);
extern u32 fn_3_BF1C(void);
extern u32 fn_3_139F0(void);

void fn_3_137AC(void) {
    struct fn_3_137AC_FontPacket pkt;
    f32 *prodata;
    s32 c;
    s32 n;

    prodata = lbl_3_rodata_4E0;
    fn_1_133DBC((void *)1);
    fn_1_134AD4();

    if ((lbl_3_bss_A17A0.unk_0 & 0x01000000) != 0) {
        fn_1_13ABA8(0x20000000);
    } else {
        if ((u8)fn_3_19C94() == 9) {
            if ((u8)fn_3_19CE0() == 0) {
                fn_1_13ABA8(0x2A200000);
            } else {
                fn_1_13ABA8(0x28200000);
            }
        } else if ((u8)fn_3_19C94() == 10) {
            if ((u8)fn_3_19CE0() == 0) {
                fn_1_13ABA8(0x29200000);
            } else {
                fn_1_13ABA8(0x28200000);
            }
        } else if ((u8)fn_3_19C94() == 16 || (u8)fn_3_19C94() == 15
                   || (u8)fn_3_19C94() == 12 || (u8)fn_3_19C94() == 17) {
            fn_1_13ABA8(0x28000000);
        } else {
            fn_1_13ABA8(0x28200000);
        }
    }

    pkt = lbl_1_rodata_26F8;
    pkt.unk_0 = 0x8606;
    pkt.unk_4 = prodata[1];
    pkt.unk_8 = prodata[2];
    pkt.unk_C = prodata[3];
    pkt.unk_30 = 10;
    fn_1_4F734((FontDrawPacket *)&pkt);

    if (fn_1_1318D4() != 0) {
        return;
    }

    if (lbl_3_bss_A17D0.unk_0 != 0) {
        if (fn_1_B8EDC(0) != 0) {
            lbl_3_bss_A17D0.unk_0 = 0;
        }
    } else if (lbl_3_bss_A17D0.unk_1 != 0) {
        if (fn_1_B8EDC(1) != 0) {
            lbl_3_bss_A17D0.unk_1 = 0;
        }
    } else {
        n = lbl_3_bss_A17A0.unk_14 - 15;
        if (n < 0) {
            c = 0;
        } else {
            c = 15;
            if (n <= 15) {
                c = n;
            }
        }
        fn_3_18960((s16)c);
        fn_3_15F44(lbl_3_bss_A17A0.unk_14);
        fn_3_17854(lbl_3_bss_A17A0.unk_14);
        fn_3_BF1C();
        if (((struct fn_3_137AC_FlagWord *)&lbl_3_bss_A17A0.unk_0)->unk_1 != 0) {
            fn_3_139F0();
        }
    }
}
