#include "types.h"
#include "rel/title/globals.h"
#include "rel/title/title.h"
extern u8 lbl_1_bss_58[0x2c];
extern u8 lbl_1_bss_7C850[0xc];
extern u8 lbl_1_bss_7EFD8[];
extern u8 lbl_1_bss_8B3A0[0x14c];
extern s16 lbl_1_bss_960;
extern s16 lbl_1_bss_968;
extern s16 lbl_1_bss_96A;
extern u32 lbl_1_bss_970;
extern u8 lbl_1_bss_9F8[0x50];
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A63C0;
extern void * lbl_801A6410;
extern u32 lbl_801A66A0;
extern s32 lbl_801A66B4;
extern u8 lbl_8_rodata_0[0xC2C];
extern u8 lbl_8_rodata_160[0x28];
extern f32 lbl_8_rodata_C;
extern u32 lbl_1_bss_7167C;
extern u32 lbl_1_bss_71680;
extern u32 lbl_1_bss_71684;
extern s16 lbl_1_bss_964;
extern u32 fn_1_3CF0(u32, u32);
extern u32 fn_1_479F0(u32);
extern void fn_8_AA8(void);
extern void fn_8_B7C(void);
extern void fn_1_A8F78(void);
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern void fn_1_37E98(void);
extern void fn_1_41A8(void);
extern void fn_1_47A60(s16);
extern s16 lbl_1_bss_962;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;
extern void fn_80005E0C(void);
extern void fn_1_A1360(void);
extern u32 fn_1_48140(u32);
extern u32 fn_1_A1364(u32);
extern const f32 lbl_8_rodata_8;
extern s32 fn_1_A66FC(s32);
extern s32 lbl_1_bss_7180C;
extern u32 fn_1_426C(u32);
extern u32 fn_8_69D8(u32, u32);
extern u32 fn_8_6C50(u32, u32);
extern u32 fn_8_D024(void);
extern u32 fn_8_D5F4(void);
extern char lbl_1_bss_198[];
extern u8 *fn_1_36AD0(void);
extern void fn_1_3F02C(void *);
extern void fn_1_F47A0(u32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_80008BEC(void *, int, u32);
extern void fn_8_6594(u32 arg0);
extern void fn_8_67B0(void);
extern void fn_1_F4794(u16);
extern u32 fn_1_D0790(void);
extern u32 fn_8_8C80(u32);

/* fzgx:begin _prolog */
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern u32 fn_8_954(void);

struct _prolog_lbl_8_bss_0 {
    u8 pad_0[0x234];
    u32 unk_234;
    u32 unk_238;
    u8 unk_23C;
    u8 unk_23D;
};
struct _prolog_lbl_801A6410 {
    u32 unk_0;
};
struct _prolog_lbl_1_bss_960 {
    s16 unk_0;
};
struct _prolog_lbl_1_bss_58 {
    u8 pad_0[0x1C];
    u32 unk_1C;
};
struct _prolog_lbl_1_bss_8B3A0 {
    u8 pad_0[0x9E];
    u8 unk_9E;
};

void _prolog(void) {
    struct _prolog_lbl_8_bss_0 *p_lbl_8_bss_0;
    s32 t0;
    s32 t1;
    p_lbl_8_bss_0 = (struct _prolog_lbl_8_bss_0 *)&(*(struct _prolog_lbl_8_bss_0 *)&lbl_8_bss_0);
    t0 = fn_1_45D0((*(struct _prolog_lbl_801A6410 *)&lbl_801A6410).unk_0, 0x173c, &(*(u32 *)&lbl_8_data_434), 0x2f1);
    p_lbl_8_bss_0->unk_234 = t0;
    t1 = fn_1_45D0((*(struct _prolog_lbl_801A6410 *)&lbl_801A6410).unk_0, 0x173c, &(*(u32 *)&lbl_8_data_434), 0x2f2);
    p_lbl_8_bss_0->unk_238 = t1;
    fn_1_3CF0(p_lbl_8_bss_0->unk_234, 0x80);
    fn_1_3CF0(p_lbl_8_bss_0->unk_238, 0x80);
    fn_1_479F0((*(struct _prolog_lbl_1_bss_960 *)&lbl_1_bss_960).unk_0);
    lbl_1_bss_7167C = (u32)fn_8_954;
    lbl_1_bss_71680 = (u32)fn_8_AA8;
    lbl_1_bss_71684 = (u32)fn_8_B7C;
    p_lbl_8_bss_0->unk_23C = 0;
    if (lbl_1_bss_964 == 8 && (s32)(*(struct _prolog_lbl_1_bss_58 *)&lbl_1_bss_58).unk_1C != 0) {
    (*(struct _prolog_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0).unk_9E = 0;
    (*(u16 *)&lbl_1_bss_968) = 1;
    } else {
    (*(u16 *)&lbl_1_bss_96A) = 158;
    }
    p_lbl_8_bss_0->unk_23D = 0;
    fn_1_A8F78();
}
/* fzgx:end _prolog */

/* fzgx:begin fn_8_954 noprologue */
#include "types.h"

extern struct fn_8_954_lbl_8_bss_0 lbl_8_bss_0;
extern struct fn_8_954_lbl_1_bss_9C8 lbl_1_bss_9C8;
extern struct fn_8_954_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern struct fn_8_954_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern s16 lbl_1_bss_968;
extern s16 lbl_1_bss_96A;
extern u8 lbl_801A66B8;
extern u8 lbl_801A66BA;
extern s32 fn_1_4C10(void);
extern s32 fn_1_4CAC(void);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_A5EFC(void);

struct fn_8_954_lbl_8_bss_0 {
    u8 pad_0[1];
    u8 unk_1;
    u8 unk_2;
    u8 pad_3[0x235];
    u32 unk_238;
    u8 pad_23C[1];
    u8 unk_23D;
};
struct fn_8_954_lbl_1_bss_9C8 {
    u8 pad_0[0xA];
    s8 unk_A;
};
struct fn_8_954_lbl_1_bss_9F8 {
    u8 pad_0[8];
    u16 unk_8;
};
struct fn_8_954_lbl_1_bss_8B3A0 {
    u8 pad_0[0x94];
    u32 unk_94;
    u8 pad_98[6];
    u8 unk_9E;
};

#pragma opt_propagation off
static inline s32 check_input(struct fn_8_954_lbl_1_bss_9F8 *unused,
                             struct fn_8_954_lbl_1_bss_9C8 *unused2, s32 unused3) {
    struct fn_8_954_lbl_1_bss_9C8 *q;
    struct fn_8_954_lbl_1_bss_9F8 *w;
    s32 zero;
    s32 result;
    q = &lbl_1_bss_9C8;
    w = &lbl_1_bss_9F8;
    zero = 0;
    if (q->unk_A == 0 && (w->unk_8 & 0x1000) != 0) {
        result = 1;
        lbl_1_bss_8B3A0.unk_9E = zero;
    } else {
        result = 0;
    }
    return result;
}

void fn_8_954(void) {
    struct fn_8_954_lbl_8_bss_0 *p;
    p = &lbl_8_bss_0;
    if (lbl_1_bss_968 != -1 || lbl_1_bss_96A != -1) {
        return;
    }
    {
        if (p->unk_2 == 0 || p->unk_1 == 0) {
            if (p->unk_23D == 0) {
                if (p->unk_2 == 0) {
                    return;
                }
                if (check_input(&lbl_1_bss_9F8, &lbl_1_bss_9C8, 0) == 0) {
                    return;
                }
                if (fn_1_4C10() == 0 || fn_1_4CAC() != 0) {
                    fn_1_4A00(0, 0xF, (void *)p->unk_238);
                }
                p->unk_23D = 1;
                return;
            }
            if (fn_1_4C10() != 0) {
                return;
            }
        }
        if (!lbl_801A66B8) {
            fn_1_A5EFC();
            lbl_801A66B8 = 1;
        }
        lbl_1_bss_8B3A0.unk_94 = 0;
        lbl_1_bss_968 = 1;
        p->unk_23D = 0;
        p->unk_1 = 0;
        lbl_801A66BA = 0;
    }
}
/* fzgx:end fn_8_954 */

/* fzgx:begin fn_8_AA8 */
extern u32 fn_1_435C(u32);

struct fn_8_AA8_lbl_8_bss_234 {
    u32 unk_0;
};
struct fn_8_AA8_lbl_8_bss_238 {
    u32 unk_0;
};

void fn_8_AA8(void) {
    u32 t0, t1, t3;
    t0 = fn_1_435C((*(struct fn_8_AA8_lbl_8_bss_234 *)&lbl_8_bss_234).unk_0);
    t1 = fn_1_407C(t0);
    fn_1_3CC4(t1);
    t3 = fn_1_435C((*(struct fn_8_AA8_lbl_8_bss_238 *)&lbl_8_bss_238).unk_0);
    fn_1_407C(t3);
}
/* fzgx:end fn_8_AA8 */

/* fzgx:begin _epilog */
extern u8 lbl_801A66B9;

extern void fn_1_4FEC(void);
extern void fn_1_C3378(void);
extern void fn_1_F7A20(void);
extern s32 fn_1_3FC38(void);
extern void fn_1_435C(u32);

void _epilog(void) {
    if (!lbl_801A66B9) {
        fn_1_4FEC();
        fn_1_C3378();
        fn_1_F7A20();
        lbl_801A66B9 = 1;
    }
    if (fn_1_3FC38()) {
        fn_1_37E98();
    }
    fn_1_435C(lbl_8_bss_234);
    fn_1_41A8();
    fn_1_435C(lbl_8_bss_238);
    fn_1_41A8();
    fn_1_47A60(lbl_1_bss_960);
}
/* fzgx:end _epilog */

/* fzgx:begin fn_8_B7C */
typedef u32 (*fn_8_B7C_Fn0)(void);
struct fn_8_B7C_lbl_8_data_318_0_E16 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
};
struct fn_8_B7C_lbl_8_data_318 {
    struct fn_8_B7C_lbl_8_data_318_0_E16 unk_0[1];
};

extern struct fn_8_B7C_lbl_8_data_318 lbl_8_data_318;

void fn_8_B7C(void) {
    struct fn_8_B7C_lbl_8_data_318_0_E16 *p;
    s16 idx;
    p = (struct fn_8_B7C_lbl_8_data_318_0_E16 *)&lbl_8_data_318;
    idx = lbl_1_bss_962;
    p += idx - 153;
    lbl_1_bss_71688 = p->unk_8;
    lbl_1_bss_7168C = p->unk_C;
    ((fn_8_B7C_Fn0)p->unk_4)();
}
/* fzgx:end fn_8_B7C */

/* fzgx:begin fn_8_BD8 */
// fn_8_BD8: empty in retail (single blr).
void fn_8_BD8(void) {
}
/* fzgx:end fn_8_BD8 */

/* fzgx:begin fn_8_BDC */
// fn_8_BDC: empty in retail (single blr).
void fn_8_BDC(void) {
}
/* fzgx:end fn_8_BDC */

/* fzgx:begin fn_8_BE0 */
// fn_8_BE0: empty in retail (single blr).
void fn_8_BE0(void) {
}
/* fzgx:end fn_8_BE0 */

/* fzgx:begin fn_8_BE4 */
typedef struct TitleColor {
    u8 r, g, b, a;
} TitleColor;
/* one declaration per callee for the whole unit */
extern void fn_1_3EB78(u32, u32, u32, u32);
extern void fn_1_3ED8C(u32, u32, u32, u32, u32, u32, u32);
extern void fn_1_3EF08(u8);
extern void fn_1_3EF8C(u8);
extern void fn_1_3EFF0(u32, u8);
extern void fn_1_41104(u32);
extern s32 fn_1_465D0(char *, s32);
extern void fn_1_47F74(s32);
extern void fn_1_49514(TitleColor);
extern void fn_1_49528(TitleColor);
extern void fn_1_495C8(u8);
extern void fn_1_4A00(s32, u8, void *);
extern u32 fn_1_4D4C8(TitleColor, f32, f32);
extern void fn_1_4FEC(void);
extern f32 fn_1_52070(u32);
extern u32 fn_1_52088(void);
extern void fn_1_7B084(void *, int);
extern void fn_1_9A958(int, int);
extern void fn_1_C3378(void);
extern void fn_1_F7A20(void);
extern u32 fn_800081C8(TitleColor, TitleColor, f32);
extern void fn_8006CE1C(f32);
extern u32 fn_8_1394(void);
extern f32 fn_8_1FB0(f32 arg0);
extern void fn_8_2124(u32 arg0, u8 *arg1, f32 arg2);
extern void fn_8_2660(f32 arg0, f32 arg1, f32 arg2);
#include "rel/title/data/lbl_8_data_200.h"
#include "rel/title/data/lbl_8_data_318.h"
#include "rel/title/data/lbl_8_data_6C4.h"
#include "font.h"

extern char lbl_8_data_0[4];
extern char lbl_8_data_4[12];
extern char lbl_8_data_10[12];
extern char lbl_8_data_1C[11];
extern char lbl_8_data_28[11];
extern char lbl_8_data_34[5];
extern char lbl_8_data_3C[5];
extern char lbl_8_data_44[8];
extern char lbl_8_data_4C[6];
extern char lbl_8_data_54[11];
extern char lbl_8_data_60[14];
extern char lbl_8_data_70[15];
extern char lbl_8_data_80[7];
extern char lbl_8_data_88[5];
extern char lbl_8_data_90[11];
extern char lbl_8_data_9C[11];
extern char lbl_8_data_A8[14];
extern char lbl_8_data_B8[6];
extern char lbl_8_data_C0[9];
extern char lbl_8_data_CC[12];
extern char lbl_8_data_D8[15];
extern char lbl_8_data_E8[7];
extern char lbl_8_data_F0[10];
extern char lbl_8_data_FC[12];
extern char lbl_8_data_108[15];
extern char lbl_8_data_118[8];
extern char lbl_8_data_120[11];
extern char lbl_8_data_12C[7];
extern char lbl_8_data_134[10];
extern char lbl_8_data_140[14];
extern char lbl_8_data_150[9];
extern char lbl_8_data_15C[11];
extern char lbl_8_data_168[8];
extern char lbl_8_data_170[18];
extern char lbl_8_data_184[13];
extern char lbl_8_data_194[15];
extern char lbl_8_data_1A4[10];
extern char lbl_8_data_1B0[11];
extern char lbl_8_data_1BC[14];
extern char lbl_8_data_1CC[8];
extern char lbl_8_data_1D4[12];
extern char lbl_8_data_1E0[7];
extern char lbl_8_data_1E8[5];
extern char lbl_8_data_1F0[6];
extern char lbl_8_data_1F8[6];



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_0[4] __attribute__((aligned(8))) = "NON";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4[12] __attribute__((aligned(4))) = "MASTER RECV";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_10[12] __attribute__((aligned(8))) = "MASTER SEND";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1C[11] __attribute__((aligned(4))) = "SLAVE SEND";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_28[11] __attribute__((aligned(8))) = "SLAVE RECV";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_34[5] __attribute__((aligned(4))) = "INIT";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3C[5] __attribute__((aligned(4))) = "TEST";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_44[8] __attribute__((aligned(4))) = "TESTEND";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4C[6] __attribute__((aligned(4))) = "SETUP";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_54[11] __attribute__((aligned(4))) = "SETUP_DONE";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_60[14] __attribute__((aligned(8))) = "SETUP_COUNTER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_70[15] __attribute__((aligned(8))) = "SETUP_CNT_DONE";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_80[7] __attribute__((aligned(8))) = "UNLINK";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_88[5] __attribute__((aligned(8))) = "COIN";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_90[11] __attribute__((aligned(8))) = "ENTRY_WAIT";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_9C[11] __attribute__((aligned(4))) = "CHALLENGER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_A8[14] __attribute__((aligned(8))) = "CHALLENGER_OK";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_B8[6] __attribute__((aligned(8))) = "ENTRY";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_C0[9] __attribute__((aligned(8))) = "ENTRY_OK";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_CC[12] __attribute__((aligned(4))) = "SINGLECHECK";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_D8[15] __attribute__((aligned(8))) = "SINGLECHECK_OK";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_E8[7] __attribute__((aligned(8))) = "COURSE";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_F0[10] __attribute__((aligned(8))) = "COURSE_OK";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_FC[12] __attribute__((aligned(4))) = "COURSE_DATA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_108[15] __attribute__((aligned(8))) = "COURSE_DATA_OK";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_118[8] __attribute__((aligned(8))) = "MACHINE";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_120[11] __attribute__((aligned(8))) = "MACHINE_OK";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_12C[7] __attribute__((aligned(4))) = "CONFIG";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_134[10] __attribute__((aligned(4))) = "CONFIG_OK";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_140[14] __attribute__((aligned(8))) = "COUNTERADJUST";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_150[9] __attribute__((aligned(8))) = "LINKWAIT";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_15C[11] __attribute__((aligned(4))) = "LINKWAITOK";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_168[8] __attribute__((aligned(8))) = "LINKSEL";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_170[18] __attribute__((aligned(8))) = "LINKDELIVERYSTART";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_184[13] __attribute__((aligned(4))) = "LINKDELIVERY";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_194[15] __attribute__((aligned(4))) = "LINKDELIVERYOK";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1A4[10] __attribute__((aligned(4))) = "LINKSELOK";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1B0[11] __attribute__((aligned(8))) = "COURSEVIEW";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1BC[14] __attribute__((aligned(4))) = "COURSEVIEW_OK";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1CC[8] __attribute__((aligned(4))) = "LINKREQ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1D4[12] __attribute__((aligned(4))) = "LINKSTANDBY";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1E0[7] __attribute__((aligned(8))) = "LINKOK";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1E8[5] __attribute__((aligned(8))) = "LINK";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1F0[6] __attribute__((aligned(8))) = "PAUSE";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1F8[6] __attribute__((aligned(8))) = "ERROR";
#pragma explicit_zero_data reset
extern char lbl_8_data_2B4[5];
extern char lbl_8_data_2BC[8];
extern char lbl_8_data_2C4[6];
extern char lbl_8_data_2CC[5];
extern char lbl_8_data_2D4[5];
extern char lbl_8_data_2DC[5];
extern char lbl_8_data_2E4[8];
extern char lbl_8_data_2EC[10];


extern char lbl_8_data_108[];
extern char lbl_8_data_10[];
extern char lbl_8_data_118[];
extern char lbl_8_data_120[];
extern char lbl_8_data_12C[];
extern char lbl_8_data_134[];
extern char lbl_8_data_140[];
extern char lbl_8_data_150[];
extern char lbl_8_data_15C[];
extern char lbl_8_data_168[];
extern char lbl_8_data_170[];
extern char lbl_8_data_184[];
extern char lbl_8_data_194[];
extern char lbl_8_data_1A4[];
extern char lbl_8_data_1B0[];
extern char lbl_8_data_1BC[];
extern char lbl_8_data_1CC[];
extern char lbl_8_data_1C[];
extern char lbl_8_data_1D4[];
extern char lbl_8_data_1E0[];
extern char lbl_8_data_1E8[];
extern char lbl_8_data_1F0[];
extern char lbl_8_data_1F8[];
extern char lbl_8_data_28[];
extern char lbl_8_data_34[];
extern char lbl_8_data_3C[];
extern char lbl_8_data_44[];
extern char lbl_8_data_4C[];
extern char lbl_8_data_4[];
extern char lbl_8_data_54[];
extern char lbl_8_data_60[];
extern char lbl_8_data_70[];
extern char lbl_8_data_80[];
extern char lbl_8_data_88[];
extern char lbl_8_data_90[];
extern char lbl_8_data_9C[];
extern char lbl_8_data_A8[];
extern char lbl_8_data_B8[];
extern char lbl_8_data_C0[];
extern char lbl_8_data_CC[];
extern char lbl_8_data_D8[];
extern char lbl_8_data_E8[];
extern char lbl_8_data_F0[];
extern char lbl_8_data_FC[];
#pragma explicit_zero_data on
__declspec(section ".data") Data_lbl_8_data_200 lbl_8_data_200 __attribute__((aligned(8))) = {
    (u8 *)&lbl_8_data_0,
    (u8 *)&lbl_8_data_4,
    (u8 *)&lbl_8_data_10,
    (u8 *)&lbl_8_data_1C,
    (u8 *)&lbl_8_data_28,
    (u8 *)&lbl_8_data_34,
    (u8 *)&lbl_8_data_3C,
    (u8 *)&lbl_8_data_44,
    (u8 *)&lbl_8_data_4C,
    (u8 *)&lbl_8_data_54,
    (u8 *)&lbl_8_data_60,
    (u8 *)&lbl_8_data_70,
    (u8 *)&lbl_8_data_80,
    (u8 *)&lbl_8_data_88,
    (u8 *)&lbl_8_data_90,
    (u8 *)&lbl_8_data_9C,
    (u8 *)&lbl_8_data_A8,
    (u8 *)&lbl_8_data_B8,
    (u8 *)&lbl_8_data_C0,
    (u8 *)&lbl_8_data_CC,
    (u8 *)&lbl_8_data_D8,
    (u8 *)&lbl_8_data_E8,
    (u8 *)&lbl_8_data_F0,
    (u8 *)&lbl_8_data_FC,
    (u8 *)&lbl_8_data_108,
    (u8 *)&lbl_8_data_118,
    (u8 *)&lbl_8_data_120,
    (u8 *)&lbl_8_data_12C,
    (u8 *)&lbl_8_data_134,
    (u8 *)&lbl_8_data_140,
    (u8 *)&lbl_8_data_150,
    (u8 *)&lbl_8_data_15C,
    (u8 *)&lbl_8_data_168,
    (u8 *)&lbl_8_data_170,
    (u8 *)&lbl_8_data_184,
    (u8 *)&lbl_8_data_194,
    (u8 *)&lbl_8_data_1A4,
    (u8 *)&lbl_8_data_1B0,
    (u8 *)&lbl_8_data_1BC,
    (u8 *)&lbl_8_data_1CC,
    (u8 *)&lbl_8_data_1D4,
    (u8 *)&lbl_8_data_1E0,
    (u8 *)&lbl_8_data_1E8,
    (u8 *)&lbl_8_data_1F0,
    (u8 *)&lbl_8_data_1F8
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2B4[5] __attribute__((aligned(4))) = "prog";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2BC[8] __attribute__((aligned(4))) = "memcard";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2C4[6] __attribute__((aligned(4))) = "title";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2CC[5] __attribute__((aligned(4))) = "demo";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2D4[5] __attribute__((aligned(4))) = "menu";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2DC[5] __attribute__((aligned(4))) = "logo";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2E4[8] __attribute__((aligned(4))) = "warning";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2EC[10] __attribute__((aligned(4))) = "operation";
#pragma explicit_zero_data reset
extern char lbl_8_data_2F8[7];



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2F8[7] __attribute__((aligned(8))) = "rating";
#pragma explicit_zero_data reset
extern char lbl_8_data_300[5];



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_300[5] __attribute__((aligned(8))) = "card";
#pragma explicit_zero_data reset
extern char lbl_8_data_308[8];



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_308[8] __attribute__((aligned(8))) = "ranking";
#pragma explicit_zero_data reset
extern char lbl_8_data_310[6];



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_310[6] __attribute__((aligned(8))) = "movie";
#pragma explicit_zero_data reset
extern u8 lbl_8_data_434[0x44];


extern char lbl_8_data_2B4[];
extern char lbl_8_data_2BC[];
extern char lbl_8_data_2C4[];
extern char lbl_8_data_2CC[];
extern char lbl_8_data_2D4[];
extern char lbl_8_data_2DC[];
extern char lbl_8_data_2E4[];
extern char lbl_8_data_2EC[];
extern char lbl_8_data_2F8[];
extern char lbl_8_data_300[];
extern char lbl_8_data_308[];
extern char lbl_8_data_310[];
extern void fn_8_1304(void);
extern void fn_8_1344(void);
extern void fn_8_1C08(void);
extern void fn_8_1C0C(void);
extern void fn_8_1C10(void);
extern void fn_8_1C14(void);
extern void fn_8_1C18(void);
extern void fn_8_1C90(void);
extern void fn_8_1F64(void);
extern void fn_8_1F74(void);
extern void fn_8_2120(void);
extern void fn_8_25F8(void);
extern void fn_8_4E8C(void);
extern void fn_8_4E90(void);
extern void fn_8_4F64(void);
extern void fn_8_516C(void);
extern void fn_8_520C(void);
extern void fn_8_5210(void);
extern void fn_8_5214(void);
extern void fn_8_5218(void);
extern void fn_8_530C(void);
extern void fn_8_5514(void);
extern void fn_8_55CC(void);
extern void fn_8_5608(void);
extern void fn_8_5810(void);
extern void fn_8_5B44(void);
extern void fn_8_5C4C(void);
extern void fn_8_5C50(void);
extern void fn_8_BD8(void);
extern void fn_8_BDC(void);
extern void fn_8_BE0(void);
extern void fn_8_BE4(void);
extern void fn_8_EC4(void);
#pragma explicit_zero_data on
__declspec(section ".data") Data_lbl_8_data_318 lbl_8_data_318 __attribute__((aligned(8))) = {
    (u8 *)&lbl_8_data_2B4,
    fn_8_1F74,
    (void (*)(void))fn_8_1FB0,
    fn_8_2120,
    (u8 *)&lbl_8_data_2BC,
    fn_8_25F8,
    (void (*)(void))fn_8_2660,
    fn_8_4E8C,
    (u8 *)&lbl_8_data_2C4,
    fn_8_1C18,
    fn_8_1C90,
    fn_8_1F64,
    (u8 *)&lbl_8_data_2CC,
    fn_8_1344,
    (void (*)(void))fn_8_1394,
    fn_8_1C08,
    (u8 *)&lbl_8_data_2D4,
    fn_8_1C0C,
    fn_8_1C10,
    fn_8_1C14,
    (u8 *)&lbl_8_data_2DC,
    fn_8_BE4,
    fn_8_EC4,
    fn_8_1304,
    (u8 *)&lbl_8_data_2E4,
    fn_8_BD8,
    fn_8_BDC,
    fn_8_BE0,
    (u8 *)&lbl_8_data_2EC,
    fn_8_4E90,
    fn_8_4F64,
    fn_8_516C,
    (u8 *)&lbl_8_data_2F8,
    fn_8_520C,
    fn_8_5210,
    fn_8_5214,
    (u8 *)&lbl_8_data_300,
    fn_8_5218,
    fn_8_530C,
    fn_8_5514,
    (u8 *)&lbl_8_data_308,
    fn_8_55CC,
    fn_8_5608,
    fn_8_5810,
    (u8 *)&lbl_8_data_310,
    fn_8_5B44,
    fn_8_5C4C,
    fn_8_5C50,
    0x2B200000U,
    0x012C0006U,
    0x4E494E54U,
    0x454E444FU,
    0x00000000U,
    0x414D5553U,
    0x454D454EU,
    0x54205649U,
    0x53494F4EU,
    0x00000000U,
    0x462D5A45U,
    0x524F2066U,
    0x6F722047U,
    0x43000000U,
    0x57454C43U,
    0x4F4D4520U,
    0x544F0000U,
    0x4F564552U,
    0x20323030U,
    0x306B6D2FU,
    0x6820574FU,
    0x524C4421U,
    0x00000000U
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") u8 lbl_8_data_434[0x44] __attribute__((aligned(4))) = {
    0x74U, 0x69U, 0x74U, 0x6CU, 0x65U, 0x2EU, 0x63U, 0x00U, 0x76U, 0x65U, 0x68U, 0x69U, 0x63U, 0x6CU, 0x65U, 0x2FU, 0x25U, 0x73U, 0x5FU, 0x65U, 0x2EU, 0x61U, 0x72U, 0x63U, 0x2EU, 0x6CU, 0x7AU, 0x00U, 0x6DU, 0x6FU, 0x76U, 0x69U, 0x65U, 0x2FU, 0x73U, 0x74U, 0x6FU, 0x72U, 0x79U, 0x30U, 0x30U, 0x2EU, 0x74U, 0x78U, 0x74U, 0x00U, 0x00U, 0x00U, 0x6DU, 0x6FU, 0x76U, 0x69U, 0x65U, 0x2FU, 0x73U, 0x74U, 0x6FU, 0x72U, 0x79U, 0x30U, 0x31U, 0x41U, 0x2EU, 0x74U, 0x78U, 0x74U, 0x00U, 0x00U
};
#pragma explicit_zero_data reset

u8 lbl_8_data_478[0x1B] = "vehicle/vehicle_sel.arc.lz";

struct fn_8_BE4_TitleState {
    u8 unk0[0x2];
    u8 unk2;
    u8 unk3[0x221];
    s16 unk224;
    u8 unk226[0x18];
    u16 unk23e;
    u8 unk240;
};

struct Prng {
    u32 unk0;
};

struct fn_8_BE4_Bss58 {
    u8 unk0[0x15];
    u8 unk15;
};








extern s16 lbl_1_bss_966;
extern u8 lbl_801A66BA;





extern u32 fn_1_4706C(void);
extern void fn_1_46A60(void);
extern u32 fn_1_47E54(u32);
extern void fn_1_7FFF0(void);
extern void fn_1_8001C(void);
extern void *fn_1_7F518(s16, void *, s32);
extern int sprintf(char *, const char *, ...);
extern void fn_1_4100C(void);
extern void fn_1_A1340(void);

void fn_8_BE4(void) {
    struct fn_8_BE4_TitleState *state = (struct fn_8_BE4_TitleState *)&lbl_8_bss_0;
    char *data = (*(char (*)[4])&lbl_8_data_0);
    s32 i;
    int v;

    if (lbl_1_bss_966 != 0xa1) {
        fn_1_47F74(0x8e);
    }

    state->unk23e = 0x1e;

    if (lbl_801A66BA == 0) {
        state->unk2 = 1;
        state->unk240 = 0;
    } else {
        state->unk240 = 1;
    }

    {
        u32 tmp = (*(struct Prng *)&lbl_801A63C0).unk0 * 0x676a4b6b + 0x33cb;
        s32 t;
        s32 c;
        s32 q;
        s32 idx;

        (*(struct Prng *)&lbl_801A63C0).unk0 = tmp;
        t = (tmp >> 16) & 0x7fff;
        c = t >> 8;
        q = c / 14;
        idx = c - q * 14;
        switch (idx) {
        case 0: state->unk224 = 1; break;
        case 1: state->unk224 = 16; break;
        case 2: state->unk224 = 8; break;
        case 3: state->unk224 = 26; break;
        case 4: state->unk224 = 5; break;
        case 5: state->unk224 = 14; break;
        case 6: state->unk224 = 7; break;
        case 7: state->unk224 = 11; break;
        case 8: state->unk224 = 13; break;
        case 9: state->unk224 = 3; break;
        case 10: state->unk224 = 15; break;
        case 11: state->unk224 = 10; break;
        case 12: state->unk224 = 29; break;
        case 13: state->unk224 = 9; break;
        case 14: state->unk224 = 27; break;
        default: state->unk224 = 1; break;
        }
    }

    v = (*(struct fn_8_BE4_Bss58 *)&lbl_1_bss_58).unk15;
    if ((s8)v == 0 || (s8)v == 2) {
        char buf[0x20];
        s8 i;
        fn_1_4706C();
        fn_1_46A60();
        fn_1_47E54(1);
        fn_1_47E54(3);
        fn_1_7B084((void *)state->unk224, 0);
        fn_1_9A958(state->unk224, 0);
        fn_1_7FFF0();
        fn_1_8001C();
        for (i = 0; i < 41; i++) {
            char tmp[0x20];
            sprintf(buf, data + 0x43c, fn_1_7F518(i, tmp, 0));
            fn_1_465D0(buf, 1);
        }
        fn_1_4100C();
        fn_1_41104(2);
    } else {
        fn_1_4706C();
        fn_1_47E54(1);
        fn_1_47E54(0x87);
        fn_1_465D0(data + 0x450, 1);
        fn_1_465D0(data + 0x464, 1);
        fn_1_465D0(data + 0x478, 1);
        fn_1_41104(1);
        fn_1_47E54(0x9a);
        fn_1_47E54(0x9b);
        fn_1_47E54(0x9d);
        fn_1_47E54(0xa1);
        fn_1_47E54(0x9c);
        fn_1_47E54(0xa2);
    }

    fn_8006CE1C((*(f32 (*)[85])&lbl_8_rodata_C)[0]);
    fn_1_A1340();
}

extern char lbl_8_data_4D0[12];
extern char lbl_8_data_4DC[32];
extern char lbl_8_data_4FC[12];
extern char lbl_8_data_508[28];
extern char lbl_8_data_524[12];
extern char lbl_8_data_530[24];
extern char lbl_8_data_548[16];
extern char lbl_8_data_558[20];
extern char lbl_8_data_56C[16];
extern char lbl_8_data_57C[28];
extern char lbl_8_data_598[20];
extern char lbl_8_data_5AC[20];
extern char lbl_8_data_5C0[20];
extern char lbl_8_data_5D4[32];
extern char lbl_8_data_5F4[12];
extern char lbl_8_data_600[24];
extern char lbl_8_data_618[12];
extern char lbl_8_data_624[24];
extern char lbl_8_data_63C[20];
extern char lbl_8_data_650[28];
extern char lbl_8_data_66C[16];
extern char lbl_8_data_67C[12];
extern char lbl_8_data_688[20];
extern char lbl_8_data_69C[24];
extern char lbl_8_data_6B4[16];
extern char lbl_8_data_778[77];
extern char lbl_8_data_7C8[11];
extern char lbl_8_data_7D4[11];
extern char lbl_8_data_7E0[11];
extern char lbl_8_data_7EC[11];
extern char lbl_8_data_7F8[108];
extern char lbl_8_data_864[66];
extern char lbl_8_data_8A8[16];
extern char lbl_8_data_8B8[16];
extern char lbl_8_data_8C8[16];
extern char lbl_8_data_8D8[16];
extern char lbl_8_data_8E8[96];
extern char lbl_8_data_948[111];
extern char lbl_8_data_9B8[10];
extern char lbl_8_data_9C4[10];
extern char lbl_8_data_9D0[10];
extern char lbl_8_data_9DC[10];
extern char lbl_8_data_9E8[232];
extern char lbl_8_data_AD0[88];
extern char lbl_8_data_B28[12];
extern char lbl_8_data_B34[12];
extern char lbl_8_data_B40[12];
extern char lbl_8_data_B4C[12];
extern char lbl_8_data_B58[104];
extern char lbl_8_data_BC0[52];
extern char lbl_8_data_BF4[23];
extern char lbl_8_data_C0C[23];
extern char lbl_8_data_C24[23];
extern char lbl_8_data_C3C[23];
extern char lbl_8_data_C54[40];
extern char lbl_8_data_C7C[48];
extern char lbl_8_data_CAC[23];
extern char lbl_8_data_CC4[23];
extern char lbl_8_data_CDC[23];
extern char lbl_8_data_CF4[23];
extern char lbl_8_data_D0C[40];
extern char lbl_8_data_D34[48];
extern char lbl_8_data_D64[23];
extern char lbl_8_data_D7C[23];
extern char lbl_8_data_D94[23];
extern char lbl_8_data_DAC[23];
extern char lbl_8_data_DC4[48];
extern char lbl_8_data_DF4[48];
extern char lbl_8_data_E24[25];
extern char lbl_8_data_E40[25];
extern char lbl_8_data_E5C[25];
extern char lbl_8_data_E78[25];
extern char lbl_8_data_E94[40];
extern char lbl_8_data_EBC[52];
extern char lbl_8_data_EF0[25];
extern char lbl_8_data_F0C[25];
extern char lbl_8_data_F28[25];
extern char lbl_8_data_F44[25];
extern char lbl_8_data_F60[44];
extern char lbl_8_data_F8C[68];
extern char lbl_8_data_FD0[30];
extern char lbl_8_data_FF0[30];
extern char lbl_8_data_1010[30];
extern char lbl_8_data_1030[30];
extern char lbl_8_data_1050[68];
extern char lbl_8_data_1094[68];
extern char lbl_8_data_10D8[30];
extern char lbl_8_data_10F8[30];
extern char lbl_8_data_1118[30];
extern char lbl_8_data_1138[30];
extern char lbl_8_data_1158[68];
extern char lbl_8_data_119C[48];
extern char lbl_8_data_11CC[30];
extern char lbl_8_data_11EC[30];
extern char lbl_8_data_120C[30];
extern char lbl_8_data_122C[30];
extern char lbl_8_data_124C[48];
extern char lbl_8_data_127C[68];
extern char lbl_8_data_12C0[32];
extern char lbl_8_data_12E0[32];
extern char lbl_8_data_1300[32];
extern char lbl_8_data_1320[32];
extern char lbl_8_data_1340[68];
extern char lbl_8_data_1384[68];
extern char lbl_8_data_13C8[32];
extern char lbl_8_data_13E8[32];
extern char lbl_8_data_1408[32];
extern char lbl_8_data_1428[32];
extern char lbl_8_data_1448[68];
extern char lbl_8_data_148C[32];
extern char lbl_8_data_14AC[14];
extern char lbl_8_data_14BC[14];
extern char lbl_8_data_14CC[14];
extern char lbl_8_data_14DC[14];
extern char lbl_8_data_14EC[28];
extern char lbl_8_data_1508[20];
extern char lbl_8_data_151C[14];
extern char lbl_8_data_152C[14];
extern char lbl_8_data_153C[14];
extern char lbl_8_data_154C[14];
extern char lbl_8_data_155C[16];
extern char lbl_8_data_156C[52];
extern char lbl_8_data_15A0[24];
extern char lbl_8_data_15B8[24];
extern char lbl_8_data_15D0[24];
extern char lbl_8_data_15E8[24];
extern char lbl_8_data_1600[52];
extern char lbl_8_data_1634[52];
extern char lbl_8_data_1668[24];
extern char lbl_8_data_1680[24];
extern char lbl_8_data_1698[24];
extern char lbl_8_data_16B0[24];
extern char lbl_8_data_16C8[52];
extern char lbl_8_data_16FC[32];
extern char lbl_8_data_171C[24];
extern char lbl_8_data_1734[24];
extern char lbl_8_data_174C[24];
extern char lbl_8_data_1764[24];
extern char lbl_8_data_177C[36];
extern char lbl_8_data_17A0[52];
extern char lbl_8_data_17D4[26];
extern char lbl_8_data_17F0[26];
extern char lbl_8_data_180C[26];
extern char lbl_8_data_1828[26];
extern char lbl_8_data_1844[48];
extern char lbl_8_data_1874[56];
extern char lbl_8_data_18AC[26];
extern char lbl_8_data_18C8[26];
extern char lbl_8_data_18E4[26];
extern char lbl_8_data_1900[26];
extern char lbl_8_data_191C[56];
extern char lbl_8_data_1954[64];
extern char lbl_8_data_1994[30];
extern char lbl_8_data_19B4[30];
extern char lbl_8_data_19D4[30];
extern char lbl_8_data_19F4[30];
extern char lbl_8_data_1A14[64];
extern char lbl_8_data_1A54[60];
extern char lbl_8_data_1A90[30];
extern char lbl_8_data_1AB0[30];
extern char lbl_8_data_1AD0[30];
extern char lbl_8_data_1AF0[30];
extern char lbl_8_data_1B10[64];
extern char lbl_8_data_1B50[60];
extern char lbl_8_data_1B8C[30];
extern char lbl_8_data_1BAC[30];
extern char lbl_8_data_1BCC[30];
extern char lbl_8_data_1BEC[30];
extern char lbl_8_data_1C0C[68];
extern char lbl_8_data_1C50[64];
extern char lbl_8_data_1C90[32];
extern char lbl_8_data_1CB0[32];
extern char lbl_8_data_1CD0[32];
extern char lbl_8_data_1CF0[32];
extern char lbl_8_data_1D10[60];
extern char lbl_8_data_1D4C[64];
extern char lbl_8_data_1D8C[32];
extern char lbl_8_data_1DAC[32];
extern char lbl_8_data_1DCC[32];
extern char lbl_8_data_1DEC[32];
extern char lbl_8_data_1E0C[64];
extern char lbl_8_data_1E4C[44];
extern char lbl_8_data_1E78[23];
extern char lbl_8_data_1E90[23];
extern char lbl_8_data_1EA8[23];
extern char lbl_8_data_1EC0[23];
extern char lbl_8_data_1ED8[44];
extern char lbl_8_data_1F04[92];
extern char lbl_8_data_1F60[23];
extern char lbl_8_data_1F78[23];
extern char lbl_8_data_1F90[23];
extern char lbl_8_data_1FA8[23];
extern char lbl_8_data_1FC0[108];
extern char lbl_8_data_202C[48];
extern char lbl_8_data_205C[16];
extern char lbl_8_data_206C[16];
extern char lbl_8_data_207C[16];
extern char lbl_8_data_208C[16];
extern char lbl_8_data_209C[56];
extern char lbl_8_data_20D4[84];
extern char lbl_8_data_2128[19];
extern char lbl_8_data_213C[19];
extern char lbl_8_data_2150[19];
extern char lbl_8_data_2164[19];
extern char lbl_8_data_2178[72];
extern char lbl_8_data_21C0[66];
extern char lbl_8_data_2204[16];
extern char lbl_8_data_2214[16];
extern char lbl_8_data_2224[16];
extern char lbl_8_data_2234[16];
extern char lbl_8_data_2244[68];
extern char lbl_8_data_2288[55];
extern char lbl_8_data_22C0[17];
extern char lbl_8_data_22D4[17];
extern char lbl_8_data_22E8[17];
extern char lbl_8_data_22FC[17];
extern char lbl_8_data_2310[68];
extern char lbl_8_data_2354[55];
extern char lbl_8_data_238C[15];
extern char lbl_8_data_239C[15];
extern char lbl_8_data_23AC[15];
extern char lbl_8_data_23BC[15];
extern char lbl_8_data_23CC[68];
extern char lbl_8_data_2410[94];
extern char lbl_8_data_2470[13];
extern char lbl_8_data_2480[13];
extern char lbl_8_data_2490[13];
extern char lbl_8_data_24A0[13];
extern char lbl_8_data_24B0[88];
extern char lbl_8_data_2508[60];
extern char lbl_8_data_2544[13];
extern char lbl_8_data_2554[13];
extern char lbl_8_data_2564[13];
extern char lbl_8_data_2574[13];
extern char lbl_8_data_2584[88];
extern char lbl_8_data_25DC[94];
extern char lbl_8_data_263C[17];
extern char lbl_8_data_2650[17];
extern char lbl_8_data_2664[17];
extern char lbl_8_data_2678[17];
extern char lbl_8_data_268C[108];
extern char lbl_8_data_26F8[38];
extern char lbl_8_data_2720[18];
extern char lbl_8_data_2734[18];
extern char lbl_8_data_2748[18];
extern char lbl_8_data_275C[18];
extern char lbl_8_data_2770[60];
extern char lbl_8_data_27AC[7];
extern char lbl_8_data_27B4[11];
extern char lbl_8_data_27C0[11];
extern char lbl_8_data_27CC[11];
extern char lbl_8_data_27D8[11];
extern char lbl_8_data_27E4[12];
extern char lbl_8_data_27F0[7];
extern char lbl_8_data_27F8[11];
extern char lbl_8_data_2804[11];
extern char lbl_8_data_2810[11];
extern char lbl_8_data_281C[11];
extern char lbl_8_data_2828[12];
extern char lbl_8_data_2834[4];
extern char lbl_8_data_2838[8];
extern char lbl_8_data_2840[8];
extern char lbl_8_data_2848[8];
extern char lbl_8_data_2850[8];
extern char lbl_8_data_2858[8];
extern char lbl_8_data_2860[3];
extern char lbl_8_data_2864[8];
extern char lbl_8_data_286C[8];
extern char lbl_8_data_2874[8];
extern char lbl_8_data_287C[8];
extern char lbl_8_data_2884[8];
extern char lbl_8_data_288C[58];
extern char lbl_8_data_28C8[18];
extern char lbl_8_data_28DC[18];
extern char lbl_8_data_28F0[18];
extern char lbl_8_data_2904[18];
extern char lbl_8_data_2918[64];
extern char lbl_8_data_2958[400];
extern char lbl_8_data_2AE8[10];
extern char lbl_8_data_2AF4[10];
extern char lbl_8_data_2B00[10];
extern char lbl_8_data_2B0C[10];
extern char lbl_8_data_2B18[592];
extern char lbl_8_data_2D68[228];
extern char lbl_8_data_2E4C[10];
extern char lbl_8_data_2E58[10];
extern char lbl_8_data_2E64[10];
extern char lbl_8_data_2E70[10];
extern char lbl_8_data_2E7C[348];
extern char lbl_8_data_2FD8[400];
extern char lbl_8_data_3168[13];
extern char lbl_8_data_3178[13];
extern char lbl_8_data_3188[13];
extern char lbl_8_data_3198[13];
extern char lbl_8_data_31A8[592];
extern char lbl_8_data_33F8[227];
extern char lbl_8_data_34DC[20];
extern char lbl_8_data_34F0[20];
extern char lbl_8_data_3504[20];
extern char lbl_8_data_3518[20];
extern char lbl_8_data_352C[348];
extern char lbl_8_data_3688[82];
extern char lbl_8_data_36DC[20];
extern char lbl_8_data_36F0[20];
extern char lbl_8_data_3704[20];
extern char lbl_8_data_3718[20];
extern char lbl_8_data_372C[96];
extern char lbl_8_data_378C[38];
extern char lbl_8_data_37B4[21];
extern char lbl_8_data_37CC[21];
extern char lbl_8_data_37E4[21];
extern char lbl_8_data_37FC[21];
extern char lbl_8_data_3814[60];
extern char lbl_8_data_3850[49];
extern char lbl_8_data_3884[13];
extern char lbl_8_data_3894[13];
extern char lbl_8_data_38A4[13];
extern char lbl_8_data_38B4[13];
extern char lbl_8_data_38C4[64];
extern char lbl_8_data_3904[21];
extern char lbl_8_data_391C[18];
extern char lbl_8_data_3930[18];
extern char lbl_8_data_3944[18];
extern char lbl_8_data_3958[18];
extern char lbl_8_data_396C[28];
extern char lbl_8_data_3988[8];
extern char lbl_8_data_3990[11];
extern char lbl_8_data_399C[11];
extern char lbl_8_data_39A8[11];
extern char lbl_8_data_39B4[11];
extern char lbl_8_data_39C0[12];
extern char lbl_8_data_39CC[55];
extern char lbl_8_data_3A04[16];
extern char lbl_8_data_3A14[16];
extern char lbl_8_data_3A24[16];
extern char lbl_8_data_3A34[16];
extern char lbl_8_data_3A44[68];
extern char lbl_8_data_3A88[44];
extern char lbl_8_data_3AB4[15];
extern char lbl_8_data_3AC4[15];
extern char lbl_8_data_3AD4[15];
extern char lbl_8_data_3AE4[15];
extern char lbl_8_data_3AF4[56];
extern char lbl_8_data_3B2C[61];
extern char lbl_8_data_3B6C[13];
extern char lbl_8_data_3B7C[13];
extern char lbl_8_data_3B8C[13];
extern char lbl_8_data_3B9C[13];
extern char lbl_8_data_3BAC[68];
extern char lbl_8_data_3BF0[85];
extern char lbl_8_data_3C48[16];
extern char lbl_8_data_3C58[16];
extern char lbl_8_data_3C68[16];
extern char lbl_8_data_3C78[16];
extern char lbl_8_data_3C88[68];
extern char lbl_8_data_3CCC[70];
extern char lbl_8_data_3D14[11];
extern char lbl_8_data_3D20[11];
extern char lbl_8_data_3D2C[11];
extern char lbl_8_data_3D38[11];
extern char lbl_8_data_3D44[84];
extern char lbl_8_data_3D98[51];
extern char lbl_8_data_3DCC[11];
extern char lbl_8_data_3DD8[11];
extern char lbl_8_data_3DE4[11];
extern char lbl_8_data_3DF0[11];
extern char lbl_8_data_3DFC[52];
extern char lbl_8_data_3E30[53];
extern char lbl_8_data_3E68[11];
extern char lbl_8_data_3E74[11];
extern char lbl_8_data_3E80[11];
extern char lbl_8_data_3E8C[11];
extern char lbl_8_data_3E98[52];
extern char lbl_8_data_3ECC[52];
extern char lbl_8_data_3F00[11];
extern char lbl_8_data_3F0C[11];
extern char lbl_8_data_3F18[11];
extern char lbl_8_data_3F24[11];
extern char lbl_8_data_3F30[52];
extern char lbl_8_data_3F64[53];
extern char lbl_8_data_3F9C[11];
extern char lbl_8_data_3FA8[11];
extern char lbl_8_data_3FB4[11];
extern char lbl_8_data_3FC0[11];
extern char lbl_8_data_3FCC[52];
extern char lbl_8_data_4000[57];
extern char lbl_8_data_403C[16];
extern char lbl_8_data_404C[16];
extern char lbl_8_data_405C[16];
extern char lbl_8_data_406C[16];
extern char lbl_8_data_407C[40];
extern char lbl_8_data_40A4[46];
extern char lbl_8_data_40D4[18];
extern char lbl_8_data_40E8[18];
extern char lbl_8_data_40FC[18];
extern char lbl_8_data_4110[18];
extern char lbl_8_data_4124[60];
extern char lbl_8_data_4160[58];
extern char lbl_8_data_419C[13];
extern char lbl_8_data_41AC[13];
extern char lbl_8_data_41BC[13];
extern char lbl_8_data_41CC[13];
extern char lbl_8_data_41DC[60];
extern char lbl_8_data_4218[39];
extern char lbl_8_data_4240[14];
extern char lbl_8_data_4250[14];
extern char lbl_8_data_4260[14];
extern char lbl_8_data_4270[14];
extern char lbl_8_data_4280[68];
extern char lbl_8_data_42C4[61];
extern char lbl_8_data_4304[15];
extern char lbl_8_data_4314[15];
extern char lbl_8_data_4324[15];
extern char lbl_8_data_4334[15];
extern char lbl_8_data_4344[64];
extern char lbl_8_data_4384[53];
extern char lbl_8_data_43BC[15];
extern char lbl_8_data_43CC[15];
extern char lbl_8_data_43DC[15];
extern char lbl_8_data_43EC[15];
extern char lbl_8_data_43FC[40];
extern char lbl_8_data_4424[15];
extern char lbl_8_data_4434[15];
extern char lbl_8_data_4444[15];
extern char lbl_8_data_4454[15];
extern char lbl_8_data_4464[15];
extern char lbl_8_data_4474[15];
extern char lbl_8_data_4484[11];
extern char lbl_8_data_4490[13];
extern char lbl_8_data_44A0[13];
extern char lbl_8_data_44B0[13];
extern char lbl_8_data_44C0[13];
extern char lbl_8_data_44D0[11];
extern char lbl_8_data_44DC[16];
extern char lbl_8_data_44EC[13];
extern char lbl_8_data_44FC[13];
extern char lbl_8_data_450C[13];
extern char lbl_8_data_451C[13];
extern char lbl_8_data_452C[16];
extern char lbl_8_data_453C[13];
extern char lbl_8_data_454C[13];
extern char lbl_8_data_455C[13];
extern char lbl_8_data_456C[13];
extern char lbl_8_data_457C[13];
extern char lbl_8_data_458C[13];
extern char lbl_8_data_459C[81];
extern char lbl_8_data_45F0[11];
extern char lbl_8_data_45FC[11];
extern char lbl_8_data_4608[11];
extern char lbl_8_data_4614[11];
extern char lbl_8_data_4620[104];
extern char lbl_8_data_4688[81];
extern char lbl_8_data_46DC[11];
extern char lbl_8_data_46E8[11];
extern char lbl_8_data_46F4[11];
extern char lbl_8_data_4700[11];
extern char lbl_8_data_470C[104];
extern char lbl_8_data_4774[44];
extern char lbl_8_data_47A0[15];
extern char lbl_8_data_47B0[15];
extern char lbl_8_data_47C0[15];
extern char lbl_8_data_47D0[15];
extern char lbl_8_data_47E0[44];
extern char lbl_8_data_480C[48];
extern char lbl_8_data_483C[16];
extern char lbl_8_data_484C[16];
extern char lbl_8_data_485C[16];
extern char lbl_8_data_486C[16];
extern char lbl_8_data_487C[52];
extern char lbl_8_data_48B0[152];
extern char lbl_8_data_4948[23];
extern char lbl_8_data_4960[23];
extern char lbl_8_data_4978[23];
extern char lbl_8_data_4990[23];
extern char lbl_8_data_49A8[140];
extern char lbl_8_data_4A34[66];
extern char lbl_8_data_4A78[23];
extern char lbl_8_data_4A90[23];
extern char lbl_8_data_4AA8[23];
extern char lbl_8_data_4AC0[23];
extern char lbl_8_data_4AD8[80];
extern char lbl_8_data_4B28[116];
extern char lbl_8_data_4B9C[4];
extern char lbl_8_data_4BA0[4];
extern char lbl_8_data_4BA4[4];
extern char lbl_8_data_4BA8[4];
extern char lbl_8_data_4BAC[188];
extern char lbl_8_data_4C68[117];
extern char lbl_8_data_4CE0[4];
extern char lbl_8_data_4CE4[4];
extern char lbl_8_data_4CE8[4];
extern char lbl_8_data_4CEC[4];
extern char lbl_8_data_4CF0[92];
extern char lbl_8_data_4D4C[5];
extern char lbl_8_data_4D54[9];
extern char lbl_8_data_4D60[9];
extern char lbl_8_data_4D6C[9];
extern char lbl_8_data_4D78[9];
extern char lbl_8_data_4D84[8];
extern char lbl_8_data_4D8C[5];
extern char lbl_8_data_4D94[11];
extern char lbl_8_data_4DA0[11];
extern char lbl_8_data_4DAC[11];
extern char lbl_8_data_4DB8[11];
extern char lbl_8_data_4DC4[8];
extern char lbl_8_data_4DCC[6];
extern char lbl_8_data_4DD4[10];
extern char lbl_8_data_4DE0[10];
extern char lbl_8_data_4DEC[10];
extern char lbl_8_data_4DF8[10];
extern char lbl_8_data_4E04[12];
extern char lbl_8_data_4E10[7];
extern char lbl_8_data_4E18[11];
extern char lbl_8_data_4E24[11];
extern char lbl_8_data_4E30[11];
extern char lbl_8_data_4E3C[11];
extern char lbl_8_data_4E48[12];
extern char lbl_8_data_4E54[7];
extern char lbl_8_data_4E5C[11];
extern char lbl_8_data_4E68[11];
extern char lbl_8_data_4E74[11];
extern char lbl_8_data_4E80[11];
extern char lbl_8_data_4E8C[12];
extern char lbl_8_data_4E98[6];
extern char lbl_8_data_4EA0[10];
extern char lbl_8_data_4EAC[10];
extern char lbl_8_data_4EB8[10];
extern char lbl_8_data_4EC4[10];
extern char lbl_8_data_4ED0[12];
extern char lbl_8_data_4EDC[7];
extern char lbl_8_data_4EE4[11];
extern char lbl_8_data_4EF0[11];
extern char lbl_8_data_4EFC[11];
extern char lbl_8_data_4F08[11];
extern char lbl_8_data_4F14[12];
extern char lbl_8_data_4F20[5];
extern char lbl_8_data_4F28[9];
extern char lbl_8_data_4F34[9];
extern char lbl_8_data_4F40[9];
extern char lbl_8_data_4F4C[9];
extern char lbl_8_data_4F58[8];
extern char lbl_8_data_4F60[323];
extern char lbl_8_data_50A4[4];
extern char lbl_8_data_50A8[4];
extern char lbl_8_data_50AC[4];
extern char lbl_8_data_50B0[4];
extern char lbl_8_data_50B4[368];
extern char lbl_8_data_5224[67];
extern char lbl_8_data_5268[4];
extern char lbl_8_data_526C[4];
extern char lbl_8_data_5270[4];
extern char lbl_8_data_5274[4];
extern char lbl_8_data_5278[68];
extern char lbl_8_data_52BC[68];
extern char lbl_8_data_5300[4];
extern char lbl_8_data_5304[4];
extern char lbl_8_data_5308[4];
extern char lbl_8_data_530C[4];
extern char lbl_8_data_5310[72];
extern char lbl_8_data_5358[53];
extern char lbl_8_data_5390[4];
extern char lbl_8_data_5394[4];
extern char lbl_8_data_5398[4];
extern char lbl_8_data_539C[4];
extern char lbl_8_data_53A0[88];
extern char lbl_8_data_53F8[5];
extern char lbl_8_data_5400[4];
extern char lbl_8_data_5404[4];
extern char lbl_8_data_5408[4];
extern char lbl_8_data_540C[4];
extern char lbl_8_data_5410[8];
extern char lbl_8_data_5418[5];
extern char lbl_8_data_5420[4];
extern char lbl_8_data_5424[4];
extern char lbl_8_data_5428[4];
extern char lbl_8_data_542C[4];
extern char lbl_8_data_5430[8];
extern char lbl_8_data_5438[5];
extern char lbl_8_data_5440[4];
extern char lbl_8_data_5444[4];
extern char lbl_8_data_5448[4];
extern char lbl_8_data_544C[4];
extern char lbl_8_data_5450[8];
extern char lbl_8_data_5458[6];
extern char lbl_8_data_5460[4];
extern char lbl_8_data_5464[4];
extern char lbl_8_data_5468[4];
extern char lbl_8_data_546C[4];
extern char lbl_8_data_5470[8];
extern char lbl_8_data_5478[52];
extern char lbl_8_data_54AC[4];
extern char lbl_8_data_54B0[4];
extern char lbl_8_data_54B4[4];
extern char lbl_8_data_54B8[4];
extern char lbl_8_data_54BC[84];
extern char lbl_8_data_5510[83];
extern char lbl_8_data_5564[4];
extern char lbl_8_data_5568[4];
extern char lbl_8_data_556C[4];
extern char lbl_8_data_5570[4];
extern char lbl_8_data_5574[76];
extern char lbl_8_data_55C0[7];
extern char lbl_8_data_55C8[4];
extern char lbl_8_data_55CC[4];
extern char lbl_8_data_55D0[4];
extern char lbl_8_data_55D4[4];
extern char lbl_8_data_55D8[12];
extern char lbl_8_data_55E4[64];
extern char lbl_8_data_5624[18];
extern char lbl_8_data_5638[18];
extern char lbl_8_data_564C[18];
extern char lbl_8_data_5660[18];
extern char lbl_8_data_5674[220];
extern char lbl_8_data_5750[121];
extern char lbl_8_data_57CC[13];
extern char lbl_8_data_57DC[13];
extern char lbl_8_data_57EC[13];
extern char lbl_8_data_57FC[13];
extern char lbl_8_data_580C[224];
extern char lbl_8_data_58EC[111];
extern char lbl_8_data_595C[18];
extern char lbl_8_data_5970[18];
extern char lbl_8_data_5984[18];
extern char lbl_8_data_5998[18];
extern u8 lbl_8_data_59AC[4];
extern char lbl_8_data_59B0[166];
extern char lbl_8_data_5A58[13];
extern char lbl_8_data_5A68[13];
extern char lbl_8_data_5A78[13];
extern char lbl_8_data_5A88[13];
extern u8 lbl_8_data_5A98[4];
extern char lbl_8_data_5A9C[168];
extern char lbl_8_data_5B44[13];
extern char lbl_8_data_5B54[13];
extern char lbl_8_data_5B64[13];
extern char lbl_8_data_5B74[13];
extern char lbl_8_data_5B84[184];
extern char lbl_8_data_5C3C[38];
extern char lbl_8_data_5C64[13];
extern char lbl_8_data_5C74[13];
extern char lbl_8_data_5C84[13];
extern char lbl_8_data_5C94[13];
extern char lbl_8_data_5CA4[48];
extern char lbl_8_data_5CD4[70];
extern char lbl_8_data_5D1C[13];
extern char lbl_8_data_5D2C[13];
extern char lbl_8_data_5D3C[13];
extern char lbl_8_data_5D4C[13];
extern char lbl_8_data_5D5C[104];
extern char lbl_8_data_5DC4[53];
extern char lbl_8_data_5DFC[13];
extern char lbl_8_data_5E0C[13];
extern char lbl_8_data_5E1C[13];
extern char lbl_8_data_5E2C[13];
extern char lbl_8_data_5E3C[72];
extern char lbl_8_data_5E84[42];
extern char lbl_8_data_5EB0[20];
extern char lbl_8_data_5EC4[20];
extern char lbl_8_data_5ED8[20];
extern char lbl_8_data_5EEC[20];
extern char lbl_8_data_5F00[48];
extern char lbl_8_data_5F30[18];
extern char lbl_8_data_5F44[15];
extern char lbl_8_data_5F54[15];
extern char lbl_8_data_5F64[15];
extern char lbl_8_data_5F74[15];
extern char lbl_8_data_5F84[12];
extern char lbl_8_data_5F90[19];
extern char lbl_8_data_5FA4[18];
extern char lbl_8_data_5FB8[18];
extern char lbl_8_data_5FCC[18];
extern char lbl_8_data_5FE0[18];
extern char lbl_8_data_5FF4[32];
extern char lbl_8_data_6014[26];
extern char lbl_8_data_6030[20];
extern char lbl_8_data_6044[20];
extern char lbl_8_data_6058[20];
extern char lbl_8_data_606C[20];
extern char lbl_8_data_6080[36];
extern char lbl_8_data_60A4[32];
extern char lbl_8_data_60C4[15];
extern char lbl_8_data_60D4[15];
extern char lbl_8_data_60E4[15];
extern char lbl_8_data_60F4[15];
extern char lbl_8_data_6104[20];
extern char lbl_8_data_6118[49];
extern char lbl_8_data_614C[20];
extern char lbl_8_data_6160[20];
extern char lbl_8_data_6174[20];
extern char lbl_8_data_6188[20];
extern char lbl_8_data_619C[36];
extern char lbl_8_data_61C0[13];
extern char lbl_8_data_61D0[16];
extern char lbl_8_data_61E0[16];
extern char lbl_8_data_61F0[16];
extern char lbl_8_data_6200[16];
extern char lbl_8_data_6210[16];
extern char lbl_8_data_6220[44];
extern char lbl_8_data_624C[20];
extern char lbl_8_data_6260[20];
extern char lbl_8_data_6274[20];
extern char lbl_8_data_6288[20];
extern char lbl_8_data_629C[52];
extern Obj_8_data_62D0 lbl_8_data_62D0;
extern char lbl_8_data_6D68[79];
extern u8 lbl_8_data_6DB8[4];
extern char lbl_8_data_6E48[64];
extern char lbl_8_data_6EDC[29];
extern char lbl_8_data_6F3C[484];
extern char lbl_8_data_7218[59];
extern char lbl_8_data_7288[58];
extern char lbl_8_data_7330[42];
extern char lbl_8_data_73B0[68];
extern char lbl_8_data_7494[54];
extern char lbl_8_data_7524[54];
extern char lbl_8_data_75B4[101];
extern char lbl_8_data_76B8[98];
extern char lbl_8_data_77B8[145];
extern char lbl_8_data_7918[44];
extern char lbl_8_data_7998[72];
extern char lbl_8_data_7A30[68];
extern char lbl_8_data_7AC8[40];
extern char lbl_8_data_7B40[32];
extern char lbl_8_data_7B90[50];



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4D0[12] __attribute__((aligned(8))) = "\203Z\203\214\203N\203^\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4DC[32] __attribute__((aligned(4))) = "\203f\203t\203H\203\213\203g\203Z\203\214\203N\203^\202\311\223\374\202\350\202\334\202\267\000"
    "\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4FC[12] __attribute__((aligned(4))) = "\203Z\203\214\203N\203^2\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_508[28] __attribute__((aligned(8))) = "\203Z\203J\203\223\203h\203Z\203\214\203N\203^\202\311\223\374\202\350\202\334\202\267\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_524[12] __attribute__((aligned(4))) = "AC\203Z\203\214\203N\203^\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_530[24] __attribute__((aligned(8))) = "AC\203Z\203\214\203N\203^\202\311\223\374\202\350\202\334\202\267\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_548[16] __attribute__((aligned(8))) = "\203\200\201[\203r\201[\203e\203X\203g\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_558[20] __attribute__((aligned(8))) = "\203\200\201[\203r\201[\202\360\202\335\202\334\202\267\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_56C[16] __attribute__((aligned(4))) = "\203J\203X\203^\203}\203C\203Y\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_57C[28] __attribute__((aligned(4))) = "\203J\203X\203^\203}\203C\203Y\202\360\202\250\202\261\202\310\202\242\202\334\202\267\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_598[20] __attribute__((aligned(8))) = "\202\255\202\351\202\334\202\242\202\353Change\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5AC[20] __attribute__((aligned(4))) = "\216\324\202\314\220F\202\360\225\317\202\246\202\334\202\267\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5C0[20] __attribute__((aligned(8))) = "\203X\203g\201[\203\212\201[\203\202\201[\203h\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5D4[32] __attribute__((aligned(4))) = "\203X\203g\201[\203\212\201[\203\202\201[\203h\202\360\202\315\202\266\202\337\202\334\202\267"
    "\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5F4[12] __attribute__((aligned(4))) = "\203\212\203v\203\214\203C\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_600[24] __attribute__((aligned(8))) = "\203\212\203v\203\214\203C\212\323\217\334\203\202\201[\203h\202\305\202\267\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_618[12] __attribute__((aligned(8))) = "\203I\203v\203V\203\207\203\223\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_624[24] __attribute__((aligned(4))) = "\203Q\201[\203\200\202\314\220\335\222\350\202\360\225\317\202\246\202\334\202\267\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_63C[20] __attribute__((aligned(4))) = "\203p\203C\203\215\203b\203g\203\202\201[\203h\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_650[28] __attribute__((aligned(8))) = "\203p\203C\203\215\203b\203g\203\202\201[\203h\202\311\223\374\202\350\202\334\202\267\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_66C[16] __attribute__((aligned(4))) = "\225\\\217\262\221\344\203\202\201[\203h\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_67C[12] __attribute__((aligned(4))) = "\225\\\217\262\221\344\202\305\202\267\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_688[20] __attribute__((aligned(8))) = "\203C\203\223\203^\203r\203\205\201[\203\202\201[\203h\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_69C[24] __attribute__((aligned(4))) = "\203C\203\223\203^\203r\203\205\201[\203\202\201[\203h\202\305\202\267\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6B4[16] __attribute__((aligned(4))) = "\203e\203X\203g\203\202\201[\203h\000\000\000";
#pragma explicit_zero_data reset




























#pragma explicit_zero_data on
__declspec(section ".data") Data_lbl_8_data_6C4 lbl_8_data_6C4 __attribute__((aligned(4))) = {
    0x83658358U,
    0x83678382U,
    0x815B8368U,
    0x82C993FCU,
    0x82E882DCU,
    0x82B70000U,
    (u8 *)&lbl_8_data_4D0,
    (u8 *)&lbl_8_data_4DC,
    0x00000001U,
    (u8 *)&lbl_8_data_4FC,
    (u8 *)&lbl_8_data_508,
    0xFFFFFFFEU,
    (u8 *)&lbl_8_data_524,
    (u8 *)&lbl_8_data_530,
    0xFFFFFFFCU,
    (u8 *)&lbl_8_data_548,
    (u8 *)&lbl_8_data_558,
    0x00000008U,
    (u8 *)&lbl_8_data_56C,
    (u8 *)&lbl_8_data_57C,
    0x00000005U,
    (u8 *)&lbl_8_data_598,
    (u8 *)&lbl_8_data_5AC,
    0x00000006U,
    (u8 *)&lbl_8_data_5C0,
    (u8 *)&lbl_8_data_5D4,
    0x00000009U,
    (u8 *)&lbl_8_data_5F4,
    (u8 *)&lbl_8_data_600,
    0x0000000CU,
    (u8 *)&lbl_8_data_618,
    (u8 *)&lbl_8_data_624,
    0x00000003U,
    (u8 *)&lbl_8_data_63C,
    (u8 *)&lbl_8_data_650,
    0x0000000DU,
    (u8 *)&lbl_8_data_66C,
    (u8 *)&lbl_8_data_67C,
    0x0000000EU,
    (u8 *)&lbl_8_data_688,
    (u8 *)&lbl_8_data_69C,
    0x00000010U,
    (u8 *)&lbl_8_data_6B4,
    (u8 *)&lbl_8_data_6C4,
    0x00000004U
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_778[77] __attribute__((aligned(8))) = "A Memory Card is not inserted in SLOT.\nPlease properly insert a Memory Card.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7C8[11] __attribute__((aligned(8))) = "NOCARD GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7D4[11] __attribute__((aligned(4))) = "NOCARD FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7E0[11] __attribute__((aligned(8))) = "NOCARD SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7EC[11] __attribute__((aligned(4))) = "NOCARD ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7F8[108] __attribute__((aligned(8))) = "SLOT\202\311\203\201\203\202\203\212\201[\203J\201[\203h\202\252\214\251[\202\335]\202\302\202"
    "\251\202\350\202\334\202\271\202\361\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\314"
    "\220\332[\202\271\202\302]\221\261[\202\274\202\255]\202\360\212m[\202\251\202\255]\224F[\202"
    "\311\202\361]\202\265\202\304\202\255\202\276\202\263\202\242\201B";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_864[66] __attribute__((aligned(4))) = "The device in SLOT is not supported.\nPlease insert a Memory Card.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_8A8[16] __attribute__((aligned(8))) = "WRONGDEVICE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_8B8[16] __attribute__((aligned(8))) = "WRONGDEVICE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_8C8[16] __attribute__((aligned(8))) = "WRONGDEVICE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_8D8[16] __attribute__((aligned(8))) = "WRONGDEVICE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_8E8[96] __attribute__((aligned(8))) = "SLOT\202\311\202\315\n\203\201\203\202\203\212\201[\203J\201[\203h\210\310[\202\242]\212O[\202"
    "\252\202\242]\202\314\202\340\202\314\202\252\202\263\202\263\202\301\202\304\202\242\202\334"
    "\202\267\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\360\202\263\202\265\202\304\202"
    "\255\202\276\202\263\202\242\201B\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_948[111] __attribute__((aligned(8))) = "A fatal error has occured.\nTurn the power off and refer to the Nintendo GameCube\nhardware manu"
    "al for details. ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_9B8[10] __attribute__((aligned(8))) = "FATAL GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_9C4[10] __attribute__((aligned(4))) = "FATAL FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_9D0[10] __attribute__((aligned(8))) = "FATAL SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_9DC[10] __attribute__((aligned(4))) = "FATAL ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_9E8[232] __attribute__((aligned(8))) = "\222v[\202\277]\226\275[\202\337\202\242]\223I[\202\304\202\253]\202\310\203G\203\211\201[\202"
    "\252\213N[\202\250]\202\261\202\350\202\334\202\265\202\275\201B\n\n\226{[\202\331\202\361]\221"
    "\314[\202\275\202\242]\202\314\203p\203\217\201[\203{\203^\203\223\202\360\211\237[\202\250]\202"
    "\265\202\304\n\223d[\202\305\202\361]\214\271[\202\260\202\361]\202\360\202n\202e\202e\202\311"
    "\202\265\201A\n\226{[\202\331\202\361]\221\314[\202\275\202\242]\202\314\216\346[\202\306]\202"
    "\350\210\265[\202\240\202\302\202\251]\202\242\220\340[\202\271\202\302]\226\276[\202\337\202"
    "\242]\217\221[\202\265\202\345]\202\314\n\216w[\202\265]\216\246[\202\266]\202\311\217][\202\265"
    "\202\275\202\252]\202\301\202\304\202\255\202\276\202\263\202\242\201B\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_AD0[88] __attribute__((aligned(8))) = "This data version is incorrect.\nSave game data again in the Game Data menu in Options. ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_B28[12] __attribute__((aligned(8))) = "VERSION GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_B34[12] __attribute__((aligned(4))) = "VERSION FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_B40[12] __attribute__((aligned(8))) = "VERSION SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_B4C[12] __attribute__((aligned(4))) = "VERSION ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_B58[104] __attribute__((aligned(8))) = "\203f\201[\203^\202\314\203o\201[\203W\203\207\203\223\202\252\210\341[\202\277\202\252]\202\242"
    "\202\334\202\267\201B\n\203I\203v\203V\203\207\203\223\202\314\203Q\201[\203\200\203f\201[\203^"
    "\202\305\n\203f\201[\203^\202\360\203Z\201[\203u\202\265\222\274[\202\310\202\250]\202\265\202"
    "\304\202\255\202\276\202\263\202\242\201B\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_BC0[52] __attribute__((aligned(8))) = "\203\237 \201c Continue without loading\n  \203\262 \201c Try again \000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_BF4[23] __attribute__((aligned(4))) = "CAPTION_LOAD_RETRY GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_C0C[23] __attribute__((aligned(4))) = "CAPTION_LOAD_RETRY FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_C24[23] __attribute__((aligned(4))) = "CAPTION_LOAD_RETRY SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_C3C[23] __attribute__((aligned(4))) = "CAPTION_LOAD_RETRY ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_C54[40] __attribute__((aligned(4))) = "\203\237\201c\203\215\201[\203h\202\271\202\270\202\311\217I[\202\250]\202\355\202\351 \203\262"
    "\201c\203\212\203g\203\211\203C";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_C7C[48] __attribute__((aligned(4))) = "\203\237 \201c Continue without saving\n\203\262 \201c Try again \000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_CAC[23] __attribute__((aligned(4))) = "CAPTION_SAVE_RETRY GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_CC4[23] __attribute__((aligned(4))) = "CAPTION_SAVE_RETRY FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_CDC[23] __attribute__((aligned(4))) = "CAPTION_SAVE_RETRY SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_CF4[23] __attribute__((aligned(4))) = "CAPTION_SAVE_RETRY ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_D0C[40] __attribute__((aligned(4))) = "\203\237\201c\203Z\201[\203u\202\271\202\270\202\311\217I[\202\250]\202\355\202\351 \203\262\201"
    "c\203\212\203g\203\211\203C";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_D34[48] __attribute__((aligned(4))) = "\203\237 \201c Continue without saving\n\203\262 \201c Try again\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_D64[23] __attribute__((aligned(4))) = "CAPTION_LIST_RETRY GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_D7C[23] __attribute__((aligned(4))) = "CAPTION_LIST_RETRY FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_D94[23] __attribute__((aligned(4))) = "CAPTION_LIST_RETRY SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_DAC[23] __attribute__((aligned(4))) = "CAPTION_LIST_RETRY ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_DC4[48] __attribute__((aligned(4))) = "\203\237\201c\203\212\203X\203g\202\360\216\346[\202\306]\202\347\202\270\202\311\217I[\202\250]"
    "\202\355\202\351 \203\262\201c\203\212\203g\203\211\203C";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_DF4[48] __attribute__((aligned(4))) = "\203\237 \201c Continue without erasing\n\203\262 \201c Try again ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_E24[25] __attribute__((aligned(4))) = "CAPTION_DELETE_RETRY GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_E40[25] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_E5C[25] __attribute__((aligned(4))) = "CAPTION_DELETE_RETRY SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_E78[25] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_E94[40] __attribute__((aligned(4))) = "\203\237\201c\217\301[\202\257]\202\263\202\270\202\311\217I[\202\250]\202\355\202\351 \203\262"
    "\201c\203\212\203g\203\211\203C";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_EBC[52] __attribute__((aligned(4))) = "\203\237 \201c Continue without checking\n\203\262 \201c Try again \000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_EF0[25] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_F0C[25] __attribute__((aligned(4))) = "CAPTION_DELETE_RETRY FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_F28[25] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_F44[25] __attribute__((aligned(4))) = "CAPTION_DELETE_RETRY ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_F60[44] __attribute__((aligned(8))) = "\203\237\201c\203`\203F\203b\203N\202\271\202\270\202\311\217I[\202\250]\202\355\202\351 \203"
    "\262\201c\203\212\203g\203\211\203C\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_F8C[68] __attribute__((aligned(4))) = "\203\237 \201c Continue without loading\n\203\262 \201c Try again\n\203\264 \201c Choose Slot "
    "\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_FD0[30] __attribute__((aligned(8))) = "CAPTION_LOAD_RETRY_CHOICE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_FF0[30] __attribute__((aligned(8))) = "CAPTION_LOAD_RETRY_CHOICE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1010[30] __attribute__((aligned(8))) = "CAPTION_LOAD_RETRY_CHOICE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1030[30] __attribute__((aligned(8))) = "CAPTION_LOAD_RETRY_CHOICE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1050[68] __attribute__((aligned(8))) = "\203\237\201c\203\215\201[\203h\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262"
    "\201c\203\212\203g\203\211\203C \203\264\201c\203X\203\215\203b\203g\202\360\221I[\202\246\202"
    "\347]\202\324\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1094[68] __attribute__((aligned(4))) = "\203\237 \201c Continue without saving\n\203\262 \201c Try again\n\203\264 \201c Choose Slot "
    "\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_10D8[30] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY_CHOICE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_10F8[30] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY_CHOICE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1118[30] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY_CHOICE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1138[30] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY_CHOICE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1158[68] __attribute__((aligned(8))) = "\203\237\201c\203Z\201[\203u\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262"
    "\201c\203\212\203g\203\211\203C \203\264\201c\203X\203\215\203b\203g\202\360\221I[\202\246\202"
    "\347]\202\324\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_119C[48] __attribute__((aligned(4))) = "\203\237 \201c Continue without saving\n\203\262 \201c Try again \000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_11CC[30] __attribute__((aligned(4))) = "CAPTION_LIST_RETRY_CHOICE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_11EC[30] __attribute__((aligned(4))) = "CAPTION_LIST_RETRY_CHOICE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_120C[30] __attribute__((aligned(4))) = "CAPTION_LIST_RETRY_CHOICE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_122C[30] __attribute__((aligned(4))) = "CAPTION_LIST_RETRY_CHOICE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_124C[48] __attribute__((aligned(4))) = "\203\237\201c\203\212\203X\203g\202\360\216\346[\202\306]\202\347\202\270\202\311\217I[\202\250]"
    "\202\355\202\351\n\203\262\201c\203\212\203g\203\211\203C";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_127C[68] __attribute__((aligned(4))) = "\203\237 \201c Continue without erasing\n\203\262 \201c Try again\n\203\264 \201c Choose Slot "
    "\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_12C0[32] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY_CHOICE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_12E0[32] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY_CHOICE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1300[32] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY_CHOICE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1320[32] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY_CHOICE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1340[68] __attribute__((aligned(8))) = "\203\237\201c\217\301[\202\257]\202\263\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262"
    "\201c\203\212\203g\203\211\203C \203\264\201c\203X\203\215\203b\203g\202\360\221I[\202\246\202"
    "\347]\202\324\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1384[68] __attribute__((aligned(4))) = "\203\237 \201c Continue without checking\n\203\262 \201c Try again\n\203\264 \201c Choose Slot "
    "\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_13C8[32] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY_CHOICE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_13E8[32] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY_CHOICE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1408[32] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY_CHOICE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1428[32] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY_CHOICE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1448[68] __attribute__((aligned(8))) = "\203\237\201c\203`\203F\203b\203N\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203"
    "\262\201c\203\212\203g\203\211\203C \203\264\201c\203X\203\215\203b\203g\202\360\221I[\202\246"
    "\202\347]\202\324\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_148C[32] __attribute__((aligned(4))) = "Please press the \203\237 Button. \000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_14AC[14] __attribute__((aligned(4))) = "CAPTION_A GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_14BC[14] __attribute__((aligned(4))) = "CAPTION_A FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_14CC[14] __attribute__((aligned(4))) = "CAPTION_A SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_14DC[14] __attribute__((aligned(4))) = "CAPTION_A ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_14EC[28] __attribute__((aligned(4))) = "\203\237\202\360\211\237[\202\250]\202\265\202\304\202\255\202\276\202\263\202\242\201B\000\000"
    "\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1508[20] __attribute__((aligned(8))) = "\203\237 \201c Delete file\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_151C[14] __attribute__((aligned(4))) = "CAPTION_A GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_152C[14] __attribute__((aligned(4))) = "CAPTION_A FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_153C[14] __attribute__((aligned(4))) = "CAPTION_A SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_154C[14] __attribute__((aligned(4))) = "CAPTION_A ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_155C[16] __attribute__((aligned(4))) = "\203\237\201c\217\301[\202\257]\202\267\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_156C[52] __attribute__((aligned(4))) = "\203\237 \201c Continue without loading\n\203\264 \201c Choose a Slot ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_15A0[24] __attribute__((aligned(8))) = "CAPTION_LOAD_CHOICE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_15B8[24] __attribute__((aligned(8))) = "CAPTION_LOAD_CHOICE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_15D0[24] __attribute__((aligned(8))) = "CAPTION_LOAD_CHOICE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_15E8[24] __attribute__((aligned(8))) = "CAPTION_LOAD_CHOICE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1600[52] __attribute__((aligned(8))) = "\203\237\201c\203\215\201[\203h\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\264"
    "\201c\203X\203\215\203b\203g\202\360\221I[\202\246\202\347]\202\324";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1634[52] __attribute__((aligned(4))) = "\203\237 \201c Continue without saving\n\203\264 \201c Choose a Slot \000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1668[24] __attribute__((aligned(8))) = "CAPTION_SAVE_CHOICE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1680[24] __attribute__((aligned(8))) = "CAPTION_SAVE_CHOICE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1698[24] __attribute__((aligned(8))) = "CAPTION_SAVE_CHOICE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_16B0[24] __attribute__((aligned(8))) = "CAPTION_SAVE_CHOICE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_16C8[52] __attribute__((aligned(8))) = "\203\237\201c\203Z\201[\203u\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\264"
    "\201c\203X\203\215\203b\203g\202\360\221I[\202\246\202\347]\202\324";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_16FC[32] __attribute__((aligned(4))) = "\203\237 \201c Continue without saving\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_171C[24] __attribute__((aligned(4))) = "CAPTION_LIST_CHOICE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1734[24] __attribute__((aligned(4))) = "CAPTION_LIST_CHOICE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_174C[24] __attribute__((aligned(4))) = "CAPTION_LIST_CHOICE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1764[24] __attribute__((aligned(4))) = "CAPTION_LIST_CHOICE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_177C[36] __attribute__((aligned(4))) = "\203\237\201c\203\212\203X\203g\202\360\216\346[\202\306]\202\347\202\270\202\311\217I[\202\250]"
    "\202\355\202\351\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_17A0[52] __attribute__((aligned(8))) = "\203\237 \201c Continue without erasing\n\203\264 \201c Choose a Slot ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_17D4[26] __attribute__((aligned(4))) = "CAPTION_DELETE_CHOICE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_17F0[26] __attribute__((aligned(8))) = "CAPTION_DELETE_CHOICE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_180C[26] __attribute__((aligned(4))) = "CAPTION_DELETE_CHOICE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1828[26] __attribute__((aligned(8))) = "CAPTION_DELETE_CHOICE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1844[48] __attribute__((aligned(4))) = "\203\237\201c\202\257\202\263\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\264\201c\203X"
    "\203\215\203b\203g\202\360\221I[\202\246\202\347]\202\324";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1874[56] __attribute__((aligned(4))) = "\203\237 \201c Continue without checking\n\203\264 \201c Choose a Slot \000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_18AC[26] __attribute__((aligned(4))) = "CAPTION_DELETE_CHOICE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_18C8[26] __attribute__((aligned(8))) = "CAPTION_DELETE_CHOICE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_18E4[26] __attribute__((aligned(4))) = "CAPTION_DELETE_CHOICE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1900[26] __attribute__((aligned(8))) = "CAPTION_DELETE_CHOICE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_191C[56] __attribute__((aligned(4))) = "\203\237\201c\203`\203F\203b\203N\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203"
    "\264\201c\203X\203\215\203b\203g\202\360\221I[\202\246\202\347]\202\324\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1954[64] __attribute__((aligned(4))) = "\203\237 \201c Continue without loading\n\203\262 \201c Try again\n\203\264 \201c Format \000"
    "\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1994[30] __attribute__((aligned(4))) = "CAPTION_LOAD_RETRY_FORMAT GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_19B4[30] __attribute__((aligned(4))) = "CAPTION_LOAD_RETRY_FORMAT FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_19D4[30] __attribute__((aligned(4))) = "CAPTION_LOAD_RETRY_FORMAT SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_19F4[30] __attribute__((aligned(4))) = "CAPTION_LOAD_RETRY_FORMAT ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1A14[64] __attribute__((aligned(4))) = "\203\237\201c\203\215\201[\203h\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262"
    "\201c\203\212\203g\203\211\203C \203\264\201c\203t\203H\201[\203}\203b\203g\202\267\202\351\000"
    "\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1A54[60] __attribute__((aligned(4))) = "\203\237 \201c Continue without saving\n\203\262 \201c Try again\n\203\264 \201c Format ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1A90[30] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY_FORMAT GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1AB0[30] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY_FORMAT FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1AD0[30] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY_FORMAT SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1AF0[30] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY_FORMAT ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1B10[64] __attribute__((aligned(8))) = "\203\237\201c\203Z\201[\203u\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262"
    "\201c\203\212\203g\203\211\203C \203\264\201c\203t\203H\201[\203}\203b\203g\202\267\202\351\000"
    "\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1B50[60] __attribute__((aligned(8))) = "\203\237 \201c Continue without saving\n\203\262 \201c Try again\n\203\264 \201c Format ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1B8C[30] __attribute__((aligned(4))) = "CAPTION_LIST_RETRY_FORMAT GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1BAC[30] __attribute__((aligned(4))) = "CAPTION_LIST_RETRY_FORMAT FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1BCC[30] __attribute__((aligned(4))) = "CAPTION_LIST_RETRY_FORMAT SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1BEC[30] __attribute__((aligned(4))) = "CAPTION_LIST_RETRY_FORMAT ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1C0C[68] __attribute__((aligned(4))) = "\203\237\201c\203\212\203X\203g\202\360\202\306\202\347\202\270\202\311\217I[\202\250]\202\355"
    "\202\351\n\203\262\201c\203\212\203g\203\211\203C \203\264\201c\203t\203H\201[\203}\203b\203g"
    "\202\267\202\351\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1C50[64] __attribute__((aligned(8))) = "\203\237 \201c Continue without erasing\n\203\262 \201c Try again\n\203\264 \201c Format \000"
    "\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1C90[32] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY_FORMAT GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1CB0[32] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY_FORMAT FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1CD0[32] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY_FORMAT SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1CF0[32] __attribute__((aligned(8))) = "CAPTION_DELETE_RETRY_FORMAT ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1D10[60] __attribute__((aligned(8))) = "\203\237\201c\202\257\202\263\202\270\202\311\217I[\202\250]\202\355\202\351\n\203\262\201c\203"
    "\212\203g\203\211\203C \203\264\201c\203t\203H\201[\203}\203b\203g\202\267\202\351\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1D4C[64] __attribute__((aligned(4))) = "\203\237 \201c Continue without checking\n\203\262 \201c Try again\n\203\264 \201c Format \000"
    "\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1D8C[32] __attribute__((aligned(4))) = "CAPTION_DELETE_RETRY_FORMAT GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1DAC[32] __attribute__((aligned(4))) = "CAPTION_DELETE_RETRY_FORMAT FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1DCC[32] __attribute__((aligned(4))) = "CAPTION_DELETE_RETRY_FORMAT SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1DEC[32] __attribute__((aligned(4))) = "CAPTION_DELETE_RETRY_FORMAT ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1E0C[64] __attribute__((aligned(4))) = "\203\237\201c\203`\203F\203b\203N\202\271\202\270\202\311\217I[\202\250]\202\355\202\351\n\203"
    "\262\201c\203\212\203g\203\211\203C \203\264\201c\203t\203H\201[\203}\203b\203g\202\267\202\351"
    "\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1E4C[44] __attribute__((aligned(4))) = "\203\237 \201c Begin without saveing\n\203\262 \201c Try again";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1E78[23] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1E90[23] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1EA8[23] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1EC0[23] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1ED8[44] __attribute__((aligned(8))) = "\203\237\201c\203Z\201[\203u\202\271\202\270\202\311\216n[\202\315\202\266]\202\337\202\351 \203"
    "\262\201c\203\212\203g\203\211\203C\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1F04[92] __attribute__((aligned(4))) = "\203\237 \201c Begin without saving\n\203\262 \201c Try again\n\203\264 \201c Reset and access s"
    "ystem Memory Card screen";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1F60[23] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1F78[23] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1F90[23] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1FA8[23] __attribute__((aligned(8))) = "CAPTION_SAVE_RETRY ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_1FC0[108] __attribute__((aligned(8))) = "\203\237\201c\203Z\201[\203u\202\271\202\270\202\311\216n[\202\315\202\266]\202\337\202\351 \203"
    "\262\201c\203\212\203g\203\211\203C\n\203\264\201c\203\212\203Z\203b\203g\202\265\202\304\226{["
    "\202\331\202\361]\221\314[\202\275\202\242]\203\201\203\202\203\212\201[\203J\201[\203h\211\346["
    "\202\252]\226\312[\202\337\202\361]\202\326\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_202C[48] __attribute__((aligned(4))) = "Choose the Slot with the Memory Card inserted. ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_205C[16] __attribute__((aligned(4))) = "CHOICE_SLOT GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_206C[16] __attribute__((aligned(4))) = "CHOICE_SLOT FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_207C[16] __attribute__((aligned(4))) = "CHOICE_SLOT SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_208C[16] __attribute__((aligned(4))) = "CHOICE_SLOT ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_209C[56] __attribute__((aligned(4))) = "\203\201\203\202\203\212\201[\203J\201[\203h\202\360\202\263\202\265\202\275\203X\203\215\203b"
    "\203g\202\360\n\221I[\202\246\202\347]\202\361\202\305\202\255\202\276\202\263\202\242\201B";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_20D4[84] __attribute__((aligned(4))) = "Use  \203\255 or \203\265to select.\nPress the \203\237 Button to confirm and the \203\240 Butto"
    "n cancel. \000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2128[19] __attribute__((aligned(8))) = "CAPTION_CHOICE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_213C[19] __attribute__((aligned(4))) = "CAPTION_CHOICE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2150[19] __attribute__((aligned(8))) = "CAPTION_CHOICE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2164[19] __attribute__((aligned(4))) = "CAPTION_CHOICE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2178[72] __attribute__((aligned(8))) = "\203\255\202\251\203\265\202\305\221I[\202\246\202\347]\202\361\202\305\201A\203\237\202\305\214"
    "\210[\202\253]\202\337\202\304\202\255\202\276\202\263\202\242\201B\n\203\240\202\305\203L\203"
    "\203\203\223\203Z\203\213\202\265\202\334\202\267\201B\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_21C0[66] __attribute__((aligned(8))) = "The FILE Data save to the Memory Card\nin SLOT has been cancelled.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2204[16] __attribute__((aligned(4))) = "NOSAVE_EXIT GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2214[16] __attribute__((aligned(4))) = "NOSAVE_EXIT FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2224[16] __attribute__((aligned(4))) = "NOSAVE_EXIT SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2234[16] __attribute__((aligned(4))) = "NOSAVE_EXIT ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2244[68] __attribute__((aligned(4))) = "FILE\203f\201[\203^\202\314\n\203\201\203\202\203\212\201[\203J\201[\203h\202\326\202\314\203Z"
    "\201[\203u\202\360\222\206[\202\277\202\343\202\244]\216~[\202\265]\202\265\202\334\202\265\202"
    "\275\201B\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2288[55] __attribute__((aligned(8))) = "The Memory Card in SLOT\nis damaged and cannot be used.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_22C0[17] __attribute__((aligned(8))) = "WRONG_SECTOR GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_22D4[17] __attribute__((aligned(4))) = "WRONG_SECTOR FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_22E8[17] __attribute__((aligned(8))) = "WRONG_SECTOR SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_22FC[17] __attribute__((aligned(4))) = "WRONG_SECTOR ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2310[68] __attribute__((aligned(8))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\315\n\202\261\202\355\202\352\202"
    "\304\202\242\202\351\202\314\202\305\216g[\202\265]\227p[\202\346\202\244]\202\305\202\253\202"
    "\334\202\271\202\361\201B\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2354[55] __attribute__((aligned(4))) = "The Memory Card in SLOT\nis damaged and cannot be used.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_238C[15] __attribute__((aligned(4))) = "WRONG_CARD GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_239C[15] __attribute__((aligned(4))) = "WRONG_CARD FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_23AC[15] __attribute__((aligned(4))) = "WRONG_CARD SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_23BC[15] __attribute__((aligned(4))) = "WRONG_CARD ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_23CC[68] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\315\n\202\261\202\355\202\352\202"
    "\304\202\242\202\351\202\314\202\305\216g[\202\265]\227p[\202\346\202\244]\202\305\202\253\202"
    "\334\202\271\202\361\201B\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2410[94] __attribute__((aligned(8))) = "The Memory Card in SLOT\nis corrupted and must be formatted.\nOK to format the Memory Card now"
    "\077";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2470[13] __attribute__((aligned(8))) = "ENCODING GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2480[13] __attribute__((aligned(8))) = "ENCODING FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2490[13] __attribute__((aligned(8))) = "ENCODING SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_24A0[13] __attribute__((aligned(8))) = "ENCODING ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_24B0[88] __attribute__((aligned(8))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\315\216g[\202\302\202\251]\202\246"
    "\202\334\202\271\202\361\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\360\223\374[\202"
    "\242]\202\352\222\274[\202\310\202\250]\202\265\202\304\202\255\202\276\202\263\202\242\201B";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2508[60] __attribute__((aligned(8))) = "The Memory Card in SLOT\nis corrupted and must be formatted.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2544[13] __attribute__((aligned(4))) = "ENCODING GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2554[13] __attribute__((aligned(4))) = "ENCODING FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2564[13] __attribute__((aligned(4))) = "ENCODING SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2574[13] __attribute__((aligned(4))) = "ENCODING ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2584[88] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\315\216g[\202\302\202\251]\202\246"
    "\202\334\202\271\202\361\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\360\223\374[\202"
    "\242]\202\352\222\274[\202\310\202\250]\202\265\202\304\202\255\202\276\202\263\202\242\201B";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_25DC[94] __attribute__((aligned(4))) = "The Memory Card in SLOT\nis corrupted and must be formatted.\nOK to format the Memory Card now"
    "\077";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_263C[17] __attribute__((aligned(4))) = "FORMAT_QUERY GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2650[17] __attribute__((aligned(8))) = "FORMAT_QUERY FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2664[17] __attribute__((aligned(4))) = "FORMAT_QUERY SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2678[17] __attribute__((aligned(8))) = "FORMAT_QUERY ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_268C[108] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\315\203f\201[\203^\202\252\n\202"
    "\261\202\355\202\352\202\304\202\242\202\351\202\314\202\305\203t\203H\201[\203}\203b\203g\202"
    "\252\225K\227v\202\305\202\267\201B\n\203t\203H\201[\203}\203b\203g\202\265\202\304\202\340\202"
    "\346\202\353\202\265\202\242\202\305\202\267\202\251\201H\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_26F8[38] __attribute__((aligned(8))) = "OK to format the\nMemory Card in SLOT\077";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2720[18] __attribute__((aligned(8))) = "FORMAT_QUERY2 GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2734[18] __attribute__((aligned(4))) = "FORMAT_QUERY2 FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2748[18] __attribute__((aligned(8))) = "FORMAT_QUERY2 SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_275C[18] __attribute__((aligned(4))) = "FORMAT_QUERY2 ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2770[60] __attribute__((aligned(8))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\360\n\203t\203H\201[\203}\203b\203g"
    "\202\265\202\304\202\340\202\346\202\353\202\265\202\242\202\305\202\267\202\251\201H\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_27AC[7] __attribute__((aligned(4))) = "Slot A";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_27B4[11] __attribute__((aligned(4))) = "SLOT_A GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_27C0[11] __attribute__((aligned(8))) = "SLOT_A FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_27CC[11] __attribute__((aligned(4))) = "SLOT_A SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_27D8[11] __attribute__((aligned(8))) = "SLOT_A ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_27E4[12] __attribute__((aligned(4))) = "\203X\203\215\203b\203g\202`\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_27F0[7] __attribute__((aligned(8))) = "Slot B";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_27F8[11] __attribute__((aligned(8))) = "SLOT_B GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2804[11] __attribute__((aligned(4))) = "SLOT_B FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2810[11] __attribute__((aligned(8))) = "SLOT_B SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_281C[11] __attribute__((aligned(4))) = "SLOT_B ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2828[12] __attribute__((aligned(8))) = "\203X\203\215\203b\203g\202a\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2834[4] __attribute__((aligned(4))) = "YES";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2838[8] __attribute__((aligned(8))) = "HAI GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2840[8] __attribute__((aligned(8))) = "HAI FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2848[8] __attribute__((aligned(8))) = "HAI SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2850[8] __attribute__((aligned(8))) = "HAI ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2858[8] __attribute__((aligned(8))) = "\202\315\202\242\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2860[3] __attribute__((aligned(8))) = "NO";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2864[8] __attribute__((aligned(4))) = "IIE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_286C[8] __attribute__((aligned(4))) = "IIE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2874[8] __attribute__((aligned(4))) = "IIE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_287C[8] __attribute__((aligned(4))) = "IIE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2884[8] __attribute__((aligned(4))) = "\202\242\202\242\202\246\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_288C[58] __attribute__((aligned(4))) = "Formatting of the Memory Card in SLOT\nhas been cancelled.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_28C8[18] __attribute__((aligned(8))) = "FORMAT_CANCEL GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_28DC[18] __attribute__((aligned(4))) = "FORMAT_CANCEL FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_28F0[18] __attribute__((aligned(8))) = "FORMAT_CANCEL SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2904[18] __attribute__((aligned(4))) = "FORMAT_CANCEL ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2918[64] __attribute__((aligned(8))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\314\n\203t\203H\201[\203}\203b\203g"
    "\202\360\222\206[\202\277\202\343]\216~[\202\244\202\265]\202\265\202\334\202\265\202\275\201B";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2958[400] __attribute__((aligned(8))) = "The Memory Card in SLOT does not have\nenough free space. F-ZERO GX requires the\nfollowing to s"
    "ave its different types of data:\n(To manage files on the Memory Card,\nplease go to the Nintend"
    "o GameCube\nMemory Card management screen.)\nGame Data: 1 File and 4 Blocks\nGarage Data: 1 File"
    " and 18 Blocks\nGhost Data: 1 File and 3 Blocks\nEmblem Data: 1 File and 3 Blocks\nReplay Data: "
    "1 File and 3\201`13 Blocks\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2AE8[10] __attribute__((aligned(8))) = "NOENT GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2AF4[10] __attribute__((aligned(4))) = "NOENT FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2B00[10] __attribute__((aligned(8))) = "NOENT SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2B0C[10] __attribute__((aligned(4))) = "NOENT ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2B18[592] __attribute__((aligned(8))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\213\363[\202\240]\202\253\227e["
    "\202\346\202\244 ]\227\312[\202\350\202\345\202\244]\202\252\202\310\202\242\202\251\201A\n\203t"
    "\203@\203C\203\213\220\224[\202\267\202\244]\202\314\220\247[\202\271\202\242]\214\300[\202\260"
    "\202\361]\202\360\211z[\202\261]\202\246\202\304\202\265\202\334\202\242\202\334\202\267\201B\nF"
    "-ZERO GX\202\314\212e[\202\251\202\255]\203t\203@\203C\203\213\202\360\203Z\201[\203u\202\267"
    "\202\351\202\311\202\315\n\217\255[\202\267\202\255]\202\310\202\255\202\306\202\340\210\310["
    "\202\242]\211\272[\202\251]\202\314\213\363[\202\240]\202\253\227e[\202\346\202\244 ]\227\312["
    "\202\350\202\345\202\244]\202\252\225K[\202\320\202\302]\227v[\202\346\202\244]\202\305\202\267"
    "\201B\n(\203\201\203\202\203\212\201[\203J\201[\203h\202\314\223\340[\202\310\202\242]\227e[\202"
    "\346\202\244]\202\360\220\256[\202\271\202\242]\227\235[\202\350]\202\267\202\351\202\311\202"
    "\315\201A\n\226{[\202\331\202\361]\221\314[\202\275\202\242]\202\314\203\201\203\202\203\212\201"
    "[\203J\201[\203h\211\346[\202\252]\226\312[\202\337\202\361]\202\305\215s[\202\250\202\261]\202"
    "\310\202\301\202\304\202\255\202\276\202\263\202\242)\n  \203Q\201[\203\200\203f\201[\203^:\203t"
    "\203@\203C\203\213\202P\202\302\202\306\202S\203u\203\215\203b\203N\n \203K\203\214\201[\203W"
    "\203f\201[\203^:\203t\203@\203C\203\213\202P\202\302\202\306\202P\202W\203u\203\215\203b\203N\n "
    "\203S\201[\203X\203g\203f\201[\203^:\203t\203@\203C\203\213\202P\202\302\202\306\202R\203u\203"
    "\215\203b\203N\n\203G\203\223\203u\203\214\203\200\203f\201[\203^:\203t\203@\203C\203\213\202P"
    "\202\302\202\306\202R\203u\203\215\203b\203N\n  \203\212\203v\203\214\203C\203f\201[\203^:\203t"
    "\203@\203C\203\213\202P\202\302\202\306\202R\201`\202P\202R\203u\203\215\203b\203N\n";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2D68[228] __attribute__((aligned(8))) = "There is not enough free space on the\nMemory Card in SLOT. To save FILE Data,\nyou need at leas"
    "t 1 file and REQUIRED blocks.\n(To manage files on the Memory Card,\nplease go to the Nintendo G"
    "ameCube\nMemory Card management screen.)";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2E4C[10] __attribute__((aligned(4))) = "NOENT GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2E58[10] __attribute__((aligned(8))) = "NOENT FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2E64[10] __attribute__((aligned(4))) = "NOENT SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2E70[10] __attribute__((aligned(8))) = "NOENT ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2E7C[348] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\213\363[\202\240]\202\253\227e["
    "\202\346\202\244 ]\227\312[\202\350\202\345\202\244]\202\252\202\310\202\242\202\251\201A\n\203t"
    "\203@\203C\203\213\220\224[\202\267\202\244]\202\314\220\247[\202\271\202\242]\214\300[\202\260"
    "\202\361]\202\360\211z[\202\261]\202\246\202\304\202\265\202\334\202\242\202\334\202\267\201B\nF"
    "ILE\203f\201[\203^\202\360\203Z\201[\203u\202\267\202\351\202\311\202\315\n\217\255[\202\267\202"
    "\255]\202\310\202\255\202\306\202\340\203t\203@\203C\203\2131\202\302\202\306REQUIRED\203u\203"
    "\215\203b\203N\225K[\202\320\202\302]\227v[\202\346\202\244]\202\305\202\267\201B\n(\203\201\203"
    "\202\203\212\201[\203J\201[\203h\202\314\223\340[\202\310\202\242]\227e[\202\346\202\244]\202"
    "\360\220\256[\202\271\202\242]\227\235[\202\350]\202\267\202\351\202\311\202\315\201A\n\226{["
    "\202\331\202\361]\221\314[\202\275\202\242]\202\314\203\201\203\202\203\212\201[\203J\201[\203h"
    "\211\346[\202\252]\226\312[\202\337\202\361]\202\305\215s[\202\250\202\261]\202\310\202\301\202"
    "\304\202\255\202\276\202\263\202\242)\n\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_2FD8[400] __attribute__((aligned(8))) = "The Memory Card in SLOT does not have\nenough free space. F-ZERO GX requires the\nfollowing to s"
    "ave its different types of data:\n(To manage files on the Memory Card,\nplease go to the Nintend"
    "o GameCube\nMemory Card management screen.)\nGame Data: 1 File and 4 Blocks\nGarage Data: 1 File"
    " and 18 Blocks\nGhost Data: 1 File and 3 Blocks\nEmblem Data: 1 File and 3 Blocks\nReplay Data: "
    "1 File and 3\201`13 Blocks\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3168[13] __attribute__((aligned(8))) = "INSSPACE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3178[13] __attribute__((aligned(8))) = "INSSPACE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3188[13] __attribute__((aligned(8))) = "INSSPACE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3198[13] __attribute__((aligned(8))) = "INSSPACE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_31A8[592] __attribute__((aligned(8))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\213\363[\202\240]\202\253\227e["
    "\202\346\202\244 ]\227\312[\202\350\202\345\202\244]\202\252\202\310\202\242\202\251\201A\n\203t"
    "\203@\203C\203\213\220\224[\202\267\202\244]\202\314\220\247[\202\271\202\242]\214\300[\202\260"
    "\202\361]\202\360\211z[\202\261]\202\246\202\304\202\265\202\334\202\242\202\334\202\267\201B\nF"
    "-ZERO GX\202\314\212e[\202\251\202\255]\203t\203@\203C\203\213\202\360\203Z\201[\203u\202\267"
    "\202\351\202\311\202\315\n\217\255[\202\267\202\255]\202\310\202\255\202\306\202\340\210\310["
    "\202\242]\211\272[\202\251]\202\314\213\363[\202\240]\202\253\227e[\202\346\202\244 ]\227\312["
    "\202\350\202\345\202\244]\202\252\225K[\202\320\202\302]\227v[\202\346\202\244]\202\305\202\267"
    "\201B\n(\203\201\203\202\203\212\201[\203J\201[\203h\202\314\223\340[\202\310\202\242]\227e[\202"
    "\346\202\244]\202\360\220\256[\202\271\202\242]\227\235[\202\350]\202\267\202\351\202\311\202"
    "\315\201A\n\226{[\202\331\202\361]\221\314[\202\275\202\242]\202\314\203\201\203\202\203\212\201"
    "[\203J\201[\203h\211\346[\202\252]\226\312[\202\337\202\361]\202\305\215s[\202\250\202\261]\202"
    "\310\202\301\202\304\202\255\202\276\202\263\202\242)\n  \203Q\201[\203\200\203f\201[\203^:\203t"
    "\203@\203C\203\213\202P\202\302\202\306\202S\203u\203\215\203b\203N\n \203K\203\214\201[\203W"
    "\203f\201[\203^:\203t\203@\203C\203\213\202P\202\302\202\306\202P\202W\203u\203\215\203b\203N\n "
    "\203S\201[\203X\203g\203f\201[\203^:\203t\203@\203C\203\213\202P\202\302\202\306\202R\203u\203"
    "\215\203b\203N\n\203G\203\223\203u\203\214\203\200\203f\201[\203^:\203t\203@\203C\203\213\202P"
    "\202\302\202\306\202R\203u\203\215\203b\203N\n  \203\212\203v\203\214\203C\203f\201[\203^:\203t"
    "\203@\203C\203\213\202P\202\302\202\306\202R\201`\202P\202R\203u\203\215\203b\203N\n";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_33F8[227] __attribute__((aligned(8))) = "The Memory Card in SLOT does not\nhave enough free space. At least 1 file\nand REQUIRED blocks a"
    "re needed to save\nFILE Data. (To manage files on the Memory\nCard, please go to the Nintendo Ga"
    "meCube\nMemory Card management screen.)";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_34DC[20] __attribute__((aligned(4))) = "INSSPACE_REPLAY GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_34F0[20] __attribute__((aligned(8))) = "INSSPACE_REPLAY FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3504[20] __attribute__((aligned(4))) = "INSSPACE_REPLAY SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3518[20] __attribute__((aligned(8))) = "INSSPACE_REPLAY ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_352C[348] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\213\363[\202\240]\202\253\227e["
    "\202\346\202\244 ]\227\312[\202\350\202\345\202\244]\202\252\202\310\202\242\202\251\201A\n\203t"
    "\203@\203C\203\213\220\224[\202\267\202\244]\202\314\220\247[\202\271\202\242]\214\300[\202\260"
    "\202\361]\202\360\211z[\202\261]\202\246\202\304\202\265\202\334\202\242\202\334\202\267\201B\nF"
    "ILE\203f\201[\203^\202\360\203Z\201[\203u\202\267\202\351\202\311\202\315\n\217\255[\202\267\202"
    "\255]\202\310\202\255\202\306\202\340\203t\203@\203C\203\2131\202\302\202\306REQUIRED\203u\203"
    "\215\203b\203N\225K[\202\320\202\302]\227v[\202\346\202\244]\202\305\202\267\201B\n(\203\201\203"
    "\202\203\212\201[\203J\201[\203h\202\314\223\340[\202\310\202\242]\227e[\202\346\202\244]\202"
    "\360\220\256[\202\271\202\242]\227\235[\202\350]\202\267\202\351\202\311\202\315\201A\n\226{["
    "\202\331\202\361]\221\314[\202\275\202\242]\202\314\203\201\203\202\203\212\201[\203J\201[\203h"
    "\211\346[\202\252]\226\312[\202\337\202\361]\202\305\215s[\202\250\202\261]\202\310\202\301\202"
    "\304\202\255\202\276\202\263\202\242)\n\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3688[82] __attribute__((aligned(8))) = "There is already FILE Data\non the Memory Card in SLOT.\nOK to save over this data\077";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_36DC[20] __attribute__((aligned(4))) = "OVERWRITE_QUERY GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_36F0[20] __attribute__((aligned(8))) = "OVERWRITE_QUERY FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3704[20] __attribute__((aligned(4))) = "OVERWRITE_QUERY SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3718[20] __attribute__((aligned(8))) = "OVERWRITE_QUERY ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_372C[96] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\202\315\n\202\267\202\305\202"
    "\311FILE\203f\201[\203^\202\252\202\240\202\350\202\334\202\267\201B\n\217\343[\202\244\202\355]"
    "\217\221[\202\252]\202\253\202\265\202\304\202\340\202\346\202\353\202\265\202\242\202\305\202"
    "\267\202\251\201H\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_378C[38] __attribute__((aligned(4))) = "The FILE Data overwrite\nwas canceled.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_37B4[21] __attribute__((aligned(4))) = "OVERWRITE_CANCEL GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_37CC[21] __attribute__((aligned(4))) = "OVERWRITE_CANCEL FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_37E4[21] __attribute__((aligned(4))) = "OVERWRITE_CANCEL SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_37FC[21] __attribute__((aligned(4))) = "OVERWRITE_CANCEL ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3814[60] __attribute__((aligned(4))) = "FILE\203f\201[\203^\202\314\n\217\343[\202\244\202\355]\217\221[\202\252]\202\253\202\360\222"
    "\206[\202\277\202\343]\216~[\202\244\202\265]\202\265\202\334\202\265\202\275\201B\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3850[49] __attribute__((aligned(8))) = "FILE Data was saved to\nthe Memory Card in SLOT. ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3884[13] __attribute__((aligned(4))) = "SAVE_END GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3894[13] __attribute__((aligned(4))) = "SAVE_END FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_38A4[13] __attribute__((aligned(4))) = "SAVE_END SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_38B4[13] __attribute__((aligned(4))) = "SAVE_END ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_38C4[64] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\326\nFILE\203f\201[\203^\202\314"
    "\203Z\201[\203u\202\252\217I[\202\250]\202\355\202\350\202\334\202\265\202\275\201B\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3904[21] __attribute__((aligned(4))) = "Free blocks in SLOT:";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_391C[18] __attribute__((aligned(4))) = "REMAIN_BLOCKS GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3930[18] __attribute__((aligned(8))) = "REMAIN_BLOCKS FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3944[18] __attribute__((aligned(4))) = "REMAIN_BLOCKS SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3958[18] __attribute__((aligned(8))) = "REMAIN_BLOCKS ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_396C[28] __attribute__((aligned(4))) = "SLOT\202\314\213\363[\202\240]\202\253\203u\203\215\203b\203N\201F\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3988[8] __attribute__((aligned(8))) = "Blocks:";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3990[11] __attribute__((aligned(8))) = "BLOCKS GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_399C[11] __attribute__((aligned(4))) = "BLOCKS FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_39A8[11] __attribute__((aligned(8))) = "BLOCKS SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_39B4[11] __attribute__((aligned(4))) = "BLOCKS ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_39C0[12] __attribute__((aligned(8))) = "\203u\203\215\203b\203N\201F\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_39CC[55] __attribute__((aligned(4))) = "Loading FILE Data from\nthe Memory Card was cancelled. ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3A04[16] __attribute__((aligned(4))) = "NOLOAD_EXIT GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3A14[16] __attribute__((aligned(4))) = "NOLOAD_EXIT FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3A24[16] __attribute__((aligned(4))) = "NOLOAD_EXIT SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3A34[16] __attribute__((aligned(4))) = "NOLOAD_EXIT ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3A44[68] __attribute__((aligned(4))) = "FILE\203f\201[\203^\202\314\n\203\201\203\202\203\212\201[\203J\201[\203h\202\251\202\347\202"
    "\314\203\215\201[\203h\202\360\222\206[\202\277\202\343\202\244]\216~[\202\265]\202\265\202\334"
    "\202\265\202\275\201B";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3A88[44] __attribute__((aligned(8))) = "The Memory Card in SLOT has been formatted.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3AB4[15] __attribute__((aligned(4))) = "FORMAT_END GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3AC4[15] __attribute__((aligned(4))) = "FORMAT_END FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3AD4[15] __attribute__((aligned(4))) = "FORMAT_END SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3AE4[15] __attribute__((aligned(4))) = "FORMAT_END ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3AF4[56] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\314\n\203t\203H\201[\203}\203b\203g"
    "\202\252\217I[\202\250]\202\355\202\350\202\334\202\265\202\275\201B";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3B2C[61] __attribute__((aligned(4))) = "The FILE Data has been loaded\nfrom the Memory Card in SLOT. ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3B6C[13] __attribute__((aligned(4))) = "LOAD_END GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3B7C[13] __attribute__((aligned(4))) = "LOAD_END FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3B8C[13] __attribute__((aligned(4))) = "LOAD_END SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3B9C[13] __attribute__((aligned(4))) = "LOAD_END ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3BAC[68] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\251\202\347\202\314\nFILE\203f\201["
    "\203^\202\314\203\215\201[\203h\202\252\217I[\202\250]\202\355\202\350\202\334\202\265\202\275"
    "\201B\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3BF0[85] __attribute__((aligned(8))) = "The F-ZERO GX FILE Data on\nthe Memory Card in SLOT\nis corrupted and must be deleted.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3C48[16] __attribute__((aligned(8))) = "DATA_BROKEN GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3C58[16] __attribute__((aligned(8))) = "DATA_BROKEN FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3C68[16] __attribute__((aligned(8))) = "DATA_BROKEN SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3C78[16] __attribute__((aligned(8))) = "DATA_BROKEN ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3C88[68] __attribute__((aligned(8))) = "FILE\203f\201[\203^\202\252\202\261\202\355\202\352\202\304\202\242\202\334\202\267\201B\n\203t"
    "\203@\203C\203\213\202\360\217\301[\202\265\202\345\202\244]\213\216[ \202\253\202\345]\202\265"
    "\202\334\202\267\201B\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3CCC[70] __attribute__((aligned(4))) = "The Memory Card in SLOT was removed.\nMemory Card access was stopped. ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3D14[11] __attribute__((aligned(4))) = "DETACH GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3D20[11] __attribute__((aligned(8))) = "DETACH FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3D2C[11] __attribute__((aligned(4))) = "DETACH SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3D38[11] __attribute__((aligned(8))) = "DETACH ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3D44[84] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\252\224\262[\202\312]\202\251\202"
    "\352\202\334\202\265\202\275\201B\n\215\354[\202\263\202\254]\213\306[\202\345\202\244]\202\360"
    "\222\206[\202\277\202\343]\216~[\202\244\202\265]\202\265\202\334\202\267\201B";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3D98[51] __attribute__((aligned(8))) = "There is no FILE Data on\nthe Memory Card in SLOT. ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3DCC[11] __attribute__((aligned(4))) = "NOFILE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3DD8[11] __attribute__((aligned(8))) = "NOFILE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3DE4[11] __attribute__((aligned(4))) = "NOFILE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3DF0[11] __attribute__((aligned(8))) = "NOFILE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3DFC[52] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\202\315\nFILE\203f\201[\203^"
    "\202\252\202\240\202\350\202\334\202\271\202\361\201B\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3E30[53] __attribute__((aligned(8))) = "There is no Replay Data on\nthe Memory Card in SLOT. ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3E68[11] __attribute__((aligned(8))) = "NOFILE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3E74[11] __attribute__((aligned(4))) = "NOFILE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3E80[11] __attribute__((aligned(8))) = "NOFILE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3E8C[11] __attribute__((aligned(4))) = "NOFILE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3E98[52] __attribute__((aligned(8))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\202\315\nFILE\203f\201[\203^"
    "\202\252\202\240\202\350\202\334\202\271\202\361\201B\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3ECC[52] __attribute__((aligned(4))) = "There is no Ghost Data on\nthe Memory Card in SLOT. ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3F00[11] __attribute__((aligned(8))) = "NOFILE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3F0C[11] __attribute__((aligned(4))) = "NOFILE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3F18[11] __attribute__((aligned(8))) = "NOFILE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3F24[11] __attribute__((aligned(4))) = "NOFILE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3F30[52] __attribute__((aligned(8))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\202\315\nFILE\203f\201[\203^"
    "\202\252\202\240\202\350\202\334\202\271\202\361\201B\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3F64[53] __attribute__((aligned(4))) = "There is no Emblem Data on\nthe Memory Card in SLOT. ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3F9C[11] __attribute__((aligned(4))) = "NOFILE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3FA8[11] __attribute__((aligned(8))) = "NOFILE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3FB4[11] __attribute__((aligned(4))) = "NOFILE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3FC0[11] __attribute__((aligned(8))) = "NOFILE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_3FCC[52] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\202\315\nFILE\203f\201[\203^"
    "\202\252\202\240\202\350\202\334\202\271\202\361\201B\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4000[57] __attribute__((aligned(8))) = "Unable to get the data list\non the Memory Card in SLOT. ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_403C[16] __attribute__((aligned(4))) = "NOLIST_EXIT GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_404C[16] __attribute__((aligned(4))) = "NOLIST_EXIT FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_405C[16] __attribute__((aligned(4))) = "NOLIST_EXIT SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_406C[16] __attribute__((aligned(4))) = "NOLIST_EXIT ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_407C[40] __attribute__((aligned(4))) = "SLOT\202\314\203f\201[\203^\203\212\203X\203g\202\252\n\202\306\202\352\202\334\202\271\202\361"
    "\202\305\202\265\202\275\201B";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_40A4[46] __attribute__((aligned(4))) = "There is no data on\nthe Memory Card in SLOT. ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_40D4[18] __attribute__((aligned(4))) = "LIST_NO_EXIST GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_40E8[18] __attribute__((aligned(8))) = "LIST_NO_EXIST FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_40FC[18] __attribute__((aligned(4))) = "LIST_NO_EXIST SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4110[18] __attribute__((aligned(8))) = "LIST_NO_EXIST ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4124[60] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\202\315\n\203f\201[\203^\202"
    "\2521\202\302\202\340\202\240\202\350\202\334\202\271\202\361\202\305\202\265\202\275\201B\000"
    "\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4160[58] __attribute__((aligned(8))) = "The data list on the Memory Card\nin SLOT has been loaded.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_419C[13] __attribute__((aligned(4))) = "LIST_END GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_41AC[13] __attribute__((aligned(4))) = "LIST_END FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_41BC[13] __attribute__((aligned(4))) = "LIST_END SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_41CC[13] __attribute__((aligned(4))) = "LIST_END ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_41DC[60] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\314\n\203f\201[\203^\203\212\203X"
    "\203g\202\360\223\307[\202\346]\202\335\202\261\202\335\202\334\202\265\202\275\201B\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4218[39] __attribute__((aligned(8))) = "Done checking the Memory Card in SLOT.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4240[14] __attribute__((aligned(8))) = "CHECK_END GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4250[14] __attribute__((aligned(8))) = "CHECK_END FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4260[14] __attribute__((aligned(8))) = "CHECK_END SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4270[14] __attribute__((aligned(8))) = "CHECK_END ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4280[68] __attribute__((aligned(8))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\314\n\203`\203F\203b\203N\202\252["
    "\202\265]\217I[\202\343\202\244]\227\271[\202\350\202\345]\202\265[\202\244]\202\334\202\265\202"
    "\275\201B";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_42C4[61] __attribute__((aligned(4))) = "FILE Data deletion on the Memory Card\nin SLOT was cancelled.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4304[15] __attribute__((aligned(4))) = "NODEL_EXIT GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4314[15] __attribute__((aligned(4))) = "NODEL_EXIT FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4324[15] __attribute__((aligned(4))) = "NODEL_EXIT SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4334[15] __attribute__((aligned(4))) = "NODEL_EXIT ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4344[64] __attribute__((aligned(4))) = "SLOT\202\314FILE\203f\201[\203^\202\314\215\355[\202\263\202\255]\217\234[\202\266\202\345]\202"
    "\360\222\206[\202\277\202\343\202\244]\216~[\202\265]\202\265\202\334\202\265\202\275\201B\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4384[53] __attribute__((aligned(4))) = "1 FILE Data was erased from the Memory Card in SLOT.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_43BC[15] __attribute__((aligned(4))) = "DELETE_END GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_43CC[15] __attribute__((aligned(4))) = "DELETE_END FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_43DC[15] __attribute__((aligned(4))) = "DELETE_END SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_43EC[15] __attribute__((aligned(4))) = "DELETE_END ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_43FC[40] __attribute__((aligned(4))) = "SLOT\202\314FILE\203f\201[\203^\202\360\202P\202\302\217\301[\202\257]\202\265\202\334\202\265"
    "\202\275\201B\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4424[15] __attribute__((aligned(4))) = "NOW FORMATTING";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4434[15] __attribute__((aligned(4))) = "FORMAT_NOW GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4444[15] __attribute__((aligned(4))) = "FORMAT_NOW FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4454[15] __attribute__((aligned(4))) = "FORMAT_NOW SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4464[15] __attribute__((aligned(4))) = "FORMAT_NOW ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4474[15] __attribute__((aligned(4))) = "NOW FORMATTING";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4484[11] __attribute__((aligned(4))) = "NOW SAVING";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4490[13] __attribute__((aligned(8))) = "SAVE_NOW GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_44A0[13] __attribute__((aligned(8))) = "SAVE_NOW FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_44B0[13] __attribute__((aligned(8))) = "SAVE_NOW SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_44C0[13] __attribute__((aligned(8))) = "SAVE_NOW ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_44D0[11] __attribute__((aligned(8))) = "NOW SAVING";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_44DC[16] __attribute__((aligned(4))) = "NOW MAKING LIST";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_44EC[13] __attribute__((aligned(4))) = "LIST_NOW GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_44FC[13] __attribute__((aligned(4))) = "LIST_NOW FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_450C[13] __attribute__((aligned(4))) = "LIST_NOW SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_451C[13] __attribute__((aligned(4))) = "LIST_NOW ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_452C[16] __attribute__((aligned(4))) = "NOW MAKING LIST";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_453C[13] __attribute__((aligned(4))) = "NOW CHECKING";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_454C[13] __attribute__((aligned(4))) = "LIST_NOW GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_455C[13] __attribute__((aligned(4))) = "LIST_NOW FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_456C[13] __attribute__((aligned(4))) = "LIST_NOW SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_457C[13] __attribute__((aligned(4))) = "LIST_NOW ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_458C[13] __attribute__((aligned(4))) = "NOW CHECKING";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_459C[81] __attribute__((aligned(4))) = "Accessing the Memory Card in SLOT.\nDo not touch the Memory Card or POWER Button.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_45F0[11] __attribute__((aligned(8))) = "ACCESS GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_45FC[11] __attribute__((aligned(4))) = "ACCESS FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4608[11] __attribute__((aligned(8))) = "ACCESS SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4614[11] __attribute__((aligned(4))) = "ACCESS ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4620[104] __attribute__((aligned(8))) = "\203\201\203\202\203\212\201[\203J\201[\203h\202\311\203A\203N\203Z\203X\222\206[\202\277\202"
    "\343\202\244]\202\305\202\267\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\342\223d["
    "\202\305\202\361]\214\271[\202\260\202\361]\202\311\220G[\202\263\202\355]\202\347\202\310\202"
    "\242\202\305\202\255\202\276\202\263\202\242\201B\n\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4688[81] __attribute__((aligned(8))) = "Accessing the Memory Card in SLOT.\nDo not touch the Memory Card or POWER Button.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_46DC[11] __attribute__((aligned(4))) = "ACCESS GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_46E8[11] __attribute__((aligned(8))) = "ACCESS FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_46F4[11] __attribute__((aligned(4))) = "ACCESS SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4700[11] __attribute__((aligned(8))) = "ACCESS ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_470C[104] __attribute__((aligned(4))) = "\203\201\203\202\203\212\201[\203J\201[\203h\202\311\203A\203N\203Z\203X\222\206[\202\277\202"
    "\343\202\244]\202\305\202\267\201B\n\203\201\203\202\203\212\201[\203J\201[\203h\202\342\223d["
    "\202\305\202\361]\214\271[\202\260\202\361]\202\311\220G[\202\263\202\355]\202\347\202\310\202"
    "\242\202\305\202\255\202\276\202\263\202\242\201B\n\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4774[44] __attribute__((aligned(4))) = "OK to save FILE to the Memory Card in SLOT\077";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_47A0[15] __attribute__((aligned(8))) = "SAVE_QUERY GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_47B0[15] __attribute__((aligned(8))) = "SAVE_QUERY FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_47C0[15] __attribute__((aligned(8))) = "SAVE_QUERY SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_47D0[15] __attribute__((aligned(8))) = "SAVE_QUERY ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_47E0[44] __attribute__((aligned(8))) = "SLOT\202\311FILE\202\360\203Z\201[\203u\202\265\202\304\202\340\n\202\346\202\353\202\265\202"
    "\242\202\305\202\267\202\251\201H\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_480C[48] __attribute__((aligned(4))) = "If you start now,\nyou will not be able to save.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_483C[16] __attribute__((aligned(4))) = "CANNOT_SAVE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_484C[16] __attribute__((aligned(4))) = "CANNOT_SAVE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_485C[16] __attribute__((aligned(4))) = "CANNOT_SAVE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_486C[16] __attribute__((aligned(4))) = "CANNOT_SAVE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_487C[52] __attribute__((aligned(4))) = "\202\261\202\314\202\334\202\334\216n[\202\315\202\266]\202\337\202\275\217\352[\202\316]\215"
    "\207[\202\240\202\242]\n\203Z\201[\203u\202\305\202\253\202\334\202\271\202\361";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_48B0[152] __attribute__((aligned(8))) = "There are no Memory Cards inserted properly.\nPlease check connections or insert a Memory Card."
    "\nIf you start now, you will not be able to save the game.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4948[23] __attribute__((aligned(8))) = "CANNOT_SAVE_NOCARD GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4960[23] __attribute__((aligned(8))) = "CANNOT_SAVE_NOCARD FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4978[23] __attribute__((aligned(8))) = "CANNOT_SAVE_NOCARD SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4990[23] __attribute__((aligned(8))) = "CANNOT_SAVE_NOCARD ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_49A8[140] __attribute__((aligned(8))) = "\203\201\203\202\203\212\201[\203J\201[\203h\202\252\214\251[\202\335]\202\302\202\251\202\350"
    "\202\334\202\271\202\361\201B\n\220\332[\202\271\202\302]\221\261[\202\274\202\255]\202\360\212m"
    "[\202\251\202\255]\224F[\202\311\202\361]\202\265\202\304\202\255\202\276\202\263\202\242\201B\n"
    "\202\261\202\314\202\334\202\334\216n[\202\315\202\266]\202\337\202\275\217\352[\202\316]\215"
    "\207[\202\240\202\242]\n\203Z\201[\203u\202\305\202\253\202\334\202\271\202\361\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4A34[66] __attribute__((aligned(4))) = "The device in SLOT is not supported.\nPlease insert a Memory Card.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4A78[23] __attribute__((aligned(8))) = "CANNOT_SAVE_NOCARD GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4A90[23] __attribute__((aligned(8))) = "CANNOT_SAVE_NOCARD FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4AA8[23] __attribute__((aligned(8))) = "CANNOT_SAVE_NOCARD SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4AC0[23] __attribute__((aligned(8))) = "CANNOT_SAVE_NOCARD ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4AD8[80] __attribute__((aligned(8))) = "\203\201\203\202\203\212\201[\203J\201[\203h\210\310\212O\202\314\202\340\202\314\202\252\214"
    "\251[\202\335]\202\302\202\251\202\350\202\334\202\265\202\275\201B\n\203\201\203\202\203\212"
    "\201[\203J\201[\203h\202\360\202\263\202\265\202\304\202\255\202\276\202\263\202\242\201B";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4B28[116] __attribute__((aligned(8))) = "Either Game Data was not loaded\nor the original Memory Card,\nfrom which the Game data was load"
    "ed,\nhas been removed.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4B9C[4] __attribute__((aligned(4))) = "GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4BA0[4] __attribute__((aligned(8))) = "FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4BA4[4] __attribute__((aligned(4))) = "SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4BA8[4] __attribute__((aligned(8))) = "ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4BAC[188] __attribute__((aligned(4))) = "\203Q\201[\203\200\203f\201[\203^\202\252\203\215\201[\203h\202\263\202\352\202\304\202\242\202"
    "\310\202\242\202\251\n\203Q\201[\203\200\203f\201[\203^\202\360\203\215\201[\203h\202\265\202"
    "\275\203\201\203\202\203\212\201[\203J\201[\203h\n\202\305\202\315\202\240\202\350\202\334\202"
    "\271\202\361\201B(\203Q\201[\203\200\203f\201[\203^\202\314\203Z\201[\203u\201A\n\203\215\201["
    "\203h\202\315\201A\203I\203v\203V\203\207\203\223\202\314\203\201\203\202\203\212\201[\203J\201["
    "\203h\n\203\201\203j\203\205\201[\202\251\202\347\211\302[\202\251]\224\\[\202\314\202\244]\202"
    "\305\202\267\201B)\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4C68[117] __attribute__((aligned(8))) = "Either Game Data was not loaded\nor the original Memory Card,\nfrom which the Game data was load"
    "ed,\n has been removed.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4CE0[4] __attribute__((aligned(8))) = "GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4CE4[4] __attribute__((aligned(4))) = "FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4CE8[4] __attribute__((aligned(8))) = "SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4CEC[4] __attribute__((aligned(4))) = "ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4CF0[92] __attribute__((aligned(8))) = "\203Q\201[\203\200\203f\201[\203^\202\252\203\215\201[\203h\202\263\202\352\202\304\202\242\202"
    "\310\202\242\202\251\n\203Q\201[\203\200\203f\201[\203^\202\360\203\215\201[\203h\202\265\202"
    "\275\203\201\203\202\203\212\201[\203J\201[\203h\n\202\305\202\315\202\240\202\350\202\334\202"
    "\271\202\361\201B\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4D4C[5] __attribute__((aligned(4))) = "Data";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4D54[9] __attribute__((aligned(4))) = "File GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4D60[9] __attribute__((aligned(8))) = "File FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4D6C[9] __attribute__((aligned(4))) = "File SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4D78[9] __attribute__((aligned(8))) = "File ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4D84[8] __attribute__((aligned(4))) = "\203f\201[\203^\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4D8C[5] __attribute__((aligned(4))) = "Game";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4D94[11] __attribute__((aligned(4))) = "System GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4DA0[11] __attribute__((aligned(8))) = "System FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4DAC[11] __attribute__((aligned(4))) = "System SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4DB8[11] __attribute__((aligned(8))) = "System ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4DC4[8] __attribute__((aligned(4))) = "\203Q\201[\203\200\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4DCC[6] __attribute__((aligned(4))) = "Debug";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4DD4[10] __attribute__((aligned(4))) = "Debug GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4DE0[10] __attribute__((aligned(8))) = "Debug FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4DEC[10] __attribute__((aligned(4))) = "Debug SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4DF8[10] __attribute__((aligned(8))) = "Debug ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4E04[12] __attribute__((aligned(4))) = "\203f\203o\203b\203O\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4E10[7] __attribute__((aligned(8))) = "Replay";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4E18[11] __attribute__((aligned(8))) = "Replay GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4E24[11] __attribute__((aligned(4))) = "Replay FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4E30[11] __attribute__((aligned(8))) = "Replay SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4E3C[11] __attribute__((aligned(4))) = "Replay ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4E48[12] __attribute__((aligned(8))) = "\203\212\203v\203\214\203C\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4E54[7] __attribute__((aligned(4))) = "Emblem";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4E5C[11] __attribute__((aligned(4))) = "Emblem GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4E68[11] __attribute__((aligned(8))) = "Emblem FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4E74[11] __attribute__((aligned(4))) = "Emblem SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4E80[11] __attribute__((aligned(8))) = "Emblem ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4E8C[12] __attribute__((aligned(4))) = "\203G\203\223\203u\203\214\203\200\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4E98[6] __attribute__((aligned(8))) = "Ghost";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4EA0[10] __attribute__((aligned(8))) = "Ghost GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4EAC[10] __attribute__((aligned(4))) = "Ghost FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4EB8[10] __attribute__((aligned(8))) = "Ghost SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4EC4[10] __attribute__((aligned(4))) = "Ghost ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4ED0[12] __attribute__((aligned(8))) = "\203S\201[\203X\203g\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4EDC[7] __attribute__((aligned(4))) = "Garage";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4EE4[11] __attribute__((aligned(4))) = "Custom GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4EF0[11] __attribute__((aligned(8))) = "Custom FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4EFC[11] __attribute__((aligned(4))) = "Custom SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4F08[11] __attribute__((aligned(8))) = "Custom ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4F14[12] __attribute__((aligned(4))) = "\203K\203\214\201[\203W\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4F20[5] __attribute__((aligned(8))) = "Game";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4F28[9] __attribute__((aligned(8))) = "Game GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4F34[9] __attribute__((aligned(4))) = "Game FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4F40[9] __attribute__((aligned(8))) = "Game SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4F4C[9] __attribute__((aligned(4))) = "Game ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4F58[8] __attribute__((aligned(8))) = "\203Q\201[\203\200\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_4F60[323] __attribute__((aligned(8))) = "There is not enough free space on the Memory Card\nin %s to save all types of new files.\nExisti"
    "ng F-ZERO GX files may be erased or overwritten.\n(To manage files on the Memory Card, please go"
    " to\nthe Memory Card management screen.) In order to save\na new file, the following number of f"
    "ree files\nand blocks must be available:";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_50A4[4] __attribute__((aligned(4))) = "GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_50A8[4] __attribute__((aligned(8))) = "FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_50AC[4] __attribute__((aligned(4))) = "SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_50B0[4] __attribute__((aligned(8))) = "ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_50B4[368] __attribute__((aligned(4))) = "\202\242\202\255\202\302\202\251\202\314\203f\201[\203^\202\315\203Z\201[\203u\202\305\202\253"
    "\202\334\202\271\202\361\201B\n%s\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311"
    "\213\363[\202\240]\202\253\227e\227\312\202\252\202\310\202\242\202\251\201A\n\203t\203@\203C"
    "\203\213\220\224[\202\267\202\244]\202\314\220\247[\202\271\202\242]\214\300[\202\260\202\361]"
    "\202\360\211z[\202\261]\202\246\202\304\202\265\202\334\202\242\202\334\202\267\201B\n\203Z\201["
    "\203u\202\267\202\351\202\311\202\315\217\255[\202\267\202\255]\202\310\202\255\202\306\202\340"
    "\210\310[\202\242]\211\272[\202\251]\202\314\213\363[\202\240]\202\253\227e[\202\346\202\244 ]"
    "\227\312[\202\350\202\345\202\244]\202\252\225K[\202\320\202\302]\227v[\202\346\202\244]\202\305"
    "\202\267\201B\n(\203\201\203\202\203\212\201[\203J\201[\203h\202\314\223\340[\202\310\202\242]"
    "\227e[\202\346\202\244]\202\360\220\256[\202\271\202\242]\227\235[\202\350]\202\267\202\351\202"
    "\311\202\315\201A\n\226{[\202\331\202\361]\221\314[\202\275\202\242]\202\314\203\201\203\202\203"
    "\212\201[\203J\201[\203h\211\346[\202\252]\226\312[\202\337\202\361]\202\305\215s[\202\250\202"
    "\261]\202\310\202\301\202\304\202\255\202\276\202\263\202\242)\n";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5224[67] __attribute__((aligned(4))) = "/bcffa0a0/1/bcffffff/ File and /bcffa0a0/        /bcffffff/ Blocks";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5268[4] __attribute__((aligned(8))) = "GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_526C[4] __attribute__((aligned(4))) = "FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5270[4] __attribute__((aligned(8))) = "SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5274[4] __attribute__((aligned(4))) = "ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5278[68] __attribute__((aligned(8))) = "\203t\203@\203C\203\213/bcffa0a0/1/bcffffff/\202\302 \202\306/bcffa0a0/%4d/bcffffff/\203u\203"
    "\215\203b\203N\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_52BC[68] __attribute__((aligned(4))) = "/bcffa0a0/1/bcffffff/ File and /bcffa0a0/\202R\201`%2d/bcffffff/ Blocks\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5300[4] __attribute__((aligned(8))) = "GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5304[4] __attribute__((aligned(4))) = "FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5308[4] __attribute__((aligned(8))) = "SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_530C[4] __attribute__((aligned(4))) = "ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5310[72] __attribute__((aligned(8))) = "\203t\203@\203C\203\213/bcffa0a0/1/bcffffff/\202\302 \202\306/bcffa0a0/\202R\201`%2d/bcffffff/"
    "\203u\203\215\203b\203N\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5358[53] __attribute__((aligned(8))) = "No Memory Card in SLOT.\nPlease insert a Memory Card.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5390[4] __attribute__((aligned(8))) = "GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5394[4] __attribute__((aligned(4))) = "FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5398[4] __attribute__((aligned(8))) = "SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_539C[4] __attribute__((aligned(4))) = "ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_53A0[88] __attribute__((aligned(8))) = "\203\201\203\202\203\212\201[\203J\201[\203h\202\252\214\251[\202\335]\202\302\202\251\202\350"
    "\202\334\202\271\202\361\201B\n\220\332[\202\271\202\302]\221\261[\202\274\202\255]\202\360\212m"
    "[\202\251\202\255]\224F[\202\311\202\361]\202\265\202\304\202\255\202\276\202\263\202\242\201B"
    "\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_53F8[5] __attribute__((aligned(8))) = "SAVE";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5400[4] __attribute__((aligned(8))) = "GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5404[4] __attribute__((aligned(4))) = "FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5408[4] __attribute__((aligned(8))) = "SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_540C[4] __attribute__((aligned(4))) = "ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5410[8] __attribute__((aligned(8))) = "\203Z\201[\203u\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5418[5] __attribute__((aligned(8))) = "LOAD";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5420[4] __attribute__((aligned(8))) = "GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5424[4] __attribute__((aligned(4))) = "FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5428[4] __attribute__((aligned(8))) = "SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_542C[4] __attribute__((aligned(4))) = "ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5430[8] __attribute__((aligned(8))) = "\203\215\201[\203h\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5438[5] __attribute__((aligned(8))) = "COPY";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5440[4] __attribute__((aligned(8))) = "GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5444[4] __attribute__((aligned(4))) = "FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5448[4] __attribute__((aligned(8))) = "SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_544C[4] __attribute__((aligned(4))) = "ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5450[8] __attribute__((aligned(8))) = "\203R\203s\201[\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5458[6] __attribute__((aligned(8))) = "ERASE";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5460[4] __attribute__((aligned(8))) = "GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5464[4] __attribute__((aligned(4))) = "FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5468[4] __attribute__((aligned(8))) = "SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_546C[4] __attribute__((aligned(4))) = "ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5470[8] __attribute__((aligned(8))) = "\202\257 \202\267\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5478[52] __attribute__((aligned(8))) = "This Memory Card cannot be used.\nPlease remove it. ";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_54AC[4] __attribute__((aligned(4))) = "GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_54B0[4] __attribute__((aligned(8))) = "FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_54B4[4] __attribute__((aligned(4))) = "SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_54B8[4] __attribute__((aligned(8))) = "ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_54BC[84] __attribute__((aligned(4))) = "\202\261\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\315\216g[\202\265]\227p[\202"
    "\346\202\244]\202\305\202\253\202\334\202\271\202\361\201B\n\203\201\203\202\203\212\201[\203J"
    "\201[\203h\202\360\224\262[\202\312]\202\242\202\304\202\255\202\276\202\263\202\242\201B";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5510[83] __attribute__((aligned(8))) = "Accessing the Memory Card in Slot A. Do not touch the Memory Card or POWER Button.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5564[4] __attribute__((aligned(4))) = "GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5568[4] __attribute__((aligned(8))) = "FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_556C[4] __attribute__((aligned(4))) = "SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5570[4] __attribute__((aligned(8))) = "ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5574[76] __attribute__((aligned(4))) = "\203\201\203\202\203\212\201[\203J\201[\203h\202\311\203A\203N\203Z\203X\222\206\202\305\202\267"
    "\201B\203\201\203\202\203\212\201[\203J\201[\203h\202\342\223d\214\271\202\311\220G\202\347\202"
    "\310\202\242\202\305\202\255\202\276\202\263\202\242\201B\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_55C0[7] __attribute__((aligned(8))) = "Saving";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_55C8[4] __attribute__((aligned(8))) = "GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_55CC[4] __attribute__((aligned(4))) = "FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_55D0[4] __attribute__((aligned(8))) = "SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_55D4[4] __attribute__((aligned(4))) = "ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_55D8[12] __attribute__((aligned(8))) = "\203Z\201[\203u\222\206\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_55E4[64] __attribute__((aligned(4))) = "Some F-ZERO GX files on\nthe Memory Card in SLOT are corrupted.\n";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5624[18] __attribute__((aligned(4))) = "LIST_NO_EXIST GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5638[18] __attribute__((aligned(8))) = "LIST_NO_EXIST FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_564C[18] __attribute__((aligned(4))) = "LIST_NO_EXIST SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5660[18] __attribute__((aligned(8))) = "LIST_NO_EXIST ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5674[220] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\311\202\315\n\203f\201[\203^\202"
    "\2521\202\302\202\340\202\240\202\350\202\334\202\271\202\361\202\305\202\265\202\275\201B\n("
    "\202\261\202\355\202\352\202\275\203f\201[\203^\202\252\221\266[\202\273\202\361]\215\335[\202"
    "\264\202\242]\202\265\202\304\202\242\202\334\202\267\201B\n\203\201\203\202\203\212\201[\203J"
    "\201[\203h\202\314\223\340[\202\310\202\242]\227e[\202\346\202\244]\202\360\220\256[\202\271\202"
    "\242]\227\235[\202\350]\202\267\202\351\202\311\202\315\201A\n\226{[\202\331\202\361]\221\314["
    "\202\275\202\242]\202\314\203\201\203\202\203\212\201[\203J\201[\203h\211\346\226\312\202\305"
    "\202\250\202\261\202\310\202\301\202\304\202\255\202\276\202\263\202\242)";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5750[121] __attribute__((aligned(8))) = "The data list on the Memory Card in SLOT\nhas been read. (Some F-ZERO GX files on\nthe Memory Ca"
    "rd in SLOT are corrupted.)";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_57CC[13] __attribute__((aligned(4))) = "LIST_END GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_57DC[13] __attribute__((aligned(4))) = "LIST_END FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_57EC[13] __attribute__((aligned(4))) = "LIST_END SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_57FC[13] __attribute__((aligned(4))) = "LIST_END ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_580C[224] __attribute__((aligned(4))) = "SLOT\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\314\n\203f\201[\203^\203\212\203X"
    "\203g\202\360\223\307[\202\346]\202\335\202\261\202\335\202\334\202\265\202\275\201B\n(\202\261"
    "\202\355\202\352\202\275\203f\201[\203^\202\252\221\266[\202\273\202\361]\215\335[\202\264\202"
    "\242]\202\265\202\304\202\242\202\334\202\267\201B\n\203\201\203\202\203\212\201[\203J\201[\203h"
    "\202\314\223\340[\202\310\202\242]\227e[\202\346\202\244]\202\360\220\256[\202\271\202\242]\227"
    "\235[\202\350]\202\267\202\351\202\311\202\315\201A\n\226{[\202\331\202\361]\221\314[\202\275"
    "\202\242]\202\314\203\201\203\202\203\212\201[\203J\201[\203h\211\346\226\312\202\305\202\250"
    "\202\261\202\310\202\301\202\304\202\255\202\276\202\263\202\242)\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_58EC[111] __attribute__((aligned(4))) = "Some F-ZERO GX files on\nthe Memory Card in SLOT are corrupted.\nPlease go to Options to manage "
    "the Memory Card.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_595C[18] __attribute__((aligned(4))) = "LIST_NO_EXIST GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5970[18] __attribute__((aligned(8))) = "LIST_NO_EXIST FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5984[18] __attribute__((aligned(4))) = "LIST_NO_EXIST SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5998[18] __attribute__((aligned(8))) = "LIST_NO_EXIST ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") u8 lbl_8_data_59AC[4] __attribute__((aligned(4))) = {
    0x00U, 0x00U, 0x00U, 0x00U
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_59B0[166] __attribute__((aligned(8))) = "The data list on the Memory Card in SLOT\nhas been read. (Some F-ZERO GX files on\nthe Memory Ca"
    "rd in SLOT are corrupted.\nPlease go to Options manage the Memory Card.)";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5A58[13] __attribute__((aligned(8))) = "LIST_END GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5A68[13] __attribute__((aligned(8))) = "LIST_END FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5A78[13] __attribute__((aligned(8))) = "LIST_END SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5A88[13] __attribute__((aligned(8))) = "LIST_END ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") u8 lbl_8_data_5A98[4] __attribute__((aligned(8))) = {
    0x00U, 0x00U, 0x00U, 0x00U
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5A9C[168] __attribute__((aligned(4))) = "No Memory Card found in Slot A. Please re-insert the\noriginal Memory Card from which the Game d"
    "ata was loaded.\n\203\237 Button \201c Retry\n\203\240 Button \201c Continue without saving\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5B44[13] __attribute__((aligned(4))) = "LIST_END GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5B54[13] __attribute__((aligned(4))) = "LIST_END FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5B64[13] __attribute__((aligned(4))) = "LIST_END SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5B74[13] __attribute__((aligned(4))) = "LIST_END ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5B84[184] __attribute__((aligned(4))) = "\203X\203\215\203b\203g\202`\202\314\203\201\203\202\203\212\201[\203J\201[\203h\202\252\224\262"
    "[\202\312]\202\251\202\352\202\304\202\242\202\334\202\267\201B\n\203Q\201[\203\200\203f\201["
    "\203^\202\360\203\215\201[\203h\202\265\202\275\203\201\203\202\203\212\201[\203J\201[\203h\202"
    "\360\n\203X\203\215\203b\203g\202`\202\311\202\263\202\265\202\304\203\237\203{\203^\203\223\202"
    "\360\211\237[\202\250]\202\265\202\304\202\255\202\276\202\263\202\242\201B\n\203L\203\203\203"
    "\223\203Z\203\213\202\267\202\351\202\311\202\315\203\240\202\360\211\237[\202\250]\202\265\202"
    "\304\202\255\202\276\202\263\202\242\201B\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5C3C[38] __attribute__((aligned(4))) = "Are you sure you\nwant to delete this\077";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5C64[13] __attribute__((aligned(4))) = "LIST_END GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5C74[13] __attribute__((aligned(4))) = "LIST_END FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5C84[13] __attribute__((aligned(4))) = "LIST_END SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5C94[13] __attribute__((aligned(4))) = "LIST_END ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5CA4[48] __attribute__((aligned(4))) = "\226{[\202\331\202\361]\223\226[\202\306\202\244]\202\311\217\301[\202\257]\202\265\202\304\202"
    "\340\n\202\346\202\353\202\265\202\242\202\305\202\267\202\251\077\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5CD4[70] __attribute__((aligned(4))) = "The device in SLOT is not a Memory Card.\nPlease insert a Memory Card.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5D1C[13] __attribute__((aligned(4))) = "LIST_END GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5D2C[13] __attribute__((aligned(4))) = "LIST_END FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5D3C[13] __attribute__((aligned(4))) = "LIST_END SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5D4C[13] __attribute__((aligned(4))) = "LIST_END ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5D5C[104] __attribute__((aligned(4))) = "\203\201\203\202\203\212\201[\203J\201[\203h\210\310\212O\202\314\202\340\202\314\202\252\214"
    "\251[\202\335]\202\302\202\251\202\350\202\334\202\265\202\275\201B\n\202\261\202\314\202\334"
    "\202\334\202\305\202\315\215\354[\202\263\202\254]\213\306[\202\345\202\244]\202\252\225\333["
    "\202\331]\221\266[\202\274\202\361]\202\305\202\253\202\334\202\271\202\361\201B";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5DC4[53] __attribute__((aligned(4))) = "Created Emblems cannot be\nsaved to this Memory Card.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5DFC[13] __attribute__((aligned(4))) = "LIST_END GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5E0C[13] __attribute__((aligned(4))) = "LIST_END FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5E1C[13] __attribute__((aligned(4))) = "LIST_END SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5E2C[13] __attribute__((aligned(4))) = "LIST_END ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5E3C[72] __attribute__((aligned(4))) = "\202\261\202\314\202\334\202\334\202\305\202\315\203G\203\223\203u\203\214\203\200\202\314\215"
    "\354[\202\263\202\254]\213\306[\202\345\202\244]\202\252\225\333[\202\331]\221\266[\202\274\202"
    "\361]\202\305\202\253\202\334\202\271\202\361\201B\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5E84[42] __attribute__((aligned(4))) = "The FILE Data exists in SLOT. \nOverwrite\077";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5EB0[20] __attribute__((aligned(8))) = "OVERWRITE_QUERY GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5EC4[20] __attribute__((aligned(4))) = "OVERWRITE_QUERY FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5ED8[20] __attribute__((aligned(8))) = "OVERWRITE_QUERY SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5EEC[20] __attribute__((aligned(4))) = "OVERWRITE_QUERY ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5F00[48] __attribute__((aligned(8))) = "    \217\343[\202\244\202\355]\217\221[\202\252]\202\253\202\265\202\304\202\340\202\346\202\353"
    "\202\265\202\242\202\305\202\267\202\251\201H    \000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5F30[18] __attribute__((aligned(8))) = "Create a New File";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5F44[15] __attribute__((aligned(4))) = "NEW_CREATE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5F54[15] __attribute__((aligned(4))) = "NEW_CREATE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5F64[15] __attribute__((aligned(4))) = "NEW_CREATE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5F74[15] __attribute__((aligned(4))) = "NEW_CREATE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5F84[12] __attribute__((aligned(4))) = "\220V\213K\215\354\220\254\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5F90[19] __attribute__((aligned(8))) = "Create a new file.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5FA4[18] __attribute__((aligned(4))) = "NEW_CREATE_DO GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5FB8[18] __attribute__((aligned(8))) = "NEW_CREATE_DO FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5FCC[18] __attribute__((aligned(4))) = "NEW_CREATE_DO SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5FE0[18] __attribute__((aligned(8))) = "NEW_CREATE_DO ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_5FF4[32] __attribute__((aligned(4))) = "\220V\213K\202\311\203t\203@\203C\203\213\202\360\215\354\220\254\202\265\202\334\202\267\201B"
    "\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6014[26] __attribute__((aligned(4))) = "Cannot create a new file.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6030[20] __attribute__((aligned(8))) = "NEW_CREATE_DONT GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6044[20] __attribute__((aligned(4))) = "NEW_CREATE_DONT FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6058[20] __attribute__((aligned(8))) = "NEW_CREATE_DONT SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_606C[20] __attribute__((aligned(4))) = "NEW_CREATE_DONT ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6080[36] __attribute__((aligned(8))) = "\220V\213K\202\311\203t\203@\203C\203\213\202\360\215\354\220\254\202\305\202\253\202\334\202"
    "\271\202\361\201B\000\000\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_60A4[32] __attribute__((aligned(4))) = "%d block(s) of space available.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_60C4[15] __attribute__((aligned(4))) = "FREE_SPACE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_60D4[15] __attribute__((aligned(4))) = "FREE_SPACE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_60E4[15] __attribute__((aligned(4))) = "FREE_SPACE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_60F4[15] __attribute__((aligned(4))) = "FREE_SPACE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6104[20] __attribute__((aligned(4))) = "\213\363\202\253\227e\227\312 %d\203u\203\215\203b\203N";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6118[49] __attribute__((aligned(8))) = "%d block(s) needed. (%d free block(s) available)";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_614C[20] __attribute__((aligned(4))) = "FREE_NEED_SPACE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6160[20] __attribute__((aligned(8))) = "FREE_NEED_SPACE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6174[20] __attribute__((aligned(4))) = "FREE_NEED_SPACE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6188[20] __attribute__((aligned(8))) = "FREE_NEED_SPACE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_619C[36] __attribute__((aligned(4))) = "%d\203u\203\215\203b\203N\225K\227v(\213\363\202\253\227e\227\312 %d\203u\203\215\203b\203N)";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_61C0[13] __attribute__((aligned(8))) = "Corrupt File";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_61D0[16] __attribute__((aligned(8))) = "BROKEN_FILE GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_61E0[16] __attribute__((aligned(8))) = "BROKEN_FILE FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_61F0[16] __attribute__((aligned(8))) = "BROKEN_FILE SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6200[16] __attribute__((aligned(8))) = "BROKEN_FILE ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6210[16] __attribute__((aligned(8))) = "\211\363\202\352\202\275\203t\203@\203C\203\213\000";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6220[44] __attribute__((aligned(8))) = "This file is corrupted and must be deleted.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_624C[20] __attribute__((aligned(4))) = "BROKEN_FILE_DEL GER";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6260[20] __attribute__((aligned(8))) = "BROKEN_FILE_DEL FRA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6274[20] __attribute__((aligned(4))) = "BROKEN_FILE_DEL SPA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6288[20] __attribute__((aligned(8))) = "BROKEN_FILE_DEL ITA";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_629C[52] __attribute__((aligned(4))) = "\202\261\202\314\203t\203@\203C\203\213\202\315\211\363\202\352\202\304\202\242\202\351\202\314"
    "\202\305\217\301\202\267\225K\227v\202\252\202\240\202\350\202\334\202\267\201B\000\000\000";
#pragma explicit_zero_data reset








































































































































































































































































































































































































































































































































































































































































































#pragma explicit_zero_data on
__declspec(section ".data") Obj_8_data_62D0 lbl_8_data_62D0 __attribute__((aligned(8))) = {
    {{(const char *)((u8 *)&lbl_8_data_778), (const char *)((u8 *)&lbl_8_data_7C8), (const char *)((u8 *)&lbl_8_data_7D4), (const char *)((u8 *)&lbl_8_data_7E0), (const char *)((u8 *)&lbl_8_data_7EC), (const char *)((u8 *)&lbl_8_data_7F8)}, {(const char *)((u8 *)&lbl_8_data_864), (const char *)((u8 *)&lbl_8_data_8A8), (const char *)((u8 *)&lbl_8_data_8B8), (const char *)((u8 *)&lbl_8_data_8C8), (const char *)((u8 *)&lbl_8_data_8D8), (const char *)((u8 *)&lbl_8_data_8E8)}, {(const char *)((u8 *)&lbl_8_data_948), (const char *)((u8 *)&lbl_8_data_9B8), (const char *)((u8 *)&lbl_8_data_9C4), (const char *)((u8 *)&lbl_8_data_9D0), (const char *)((u8 *)&lbl_8_data_9DC), (const char *)((u8 *)&lbl_8_data_9E8)}, {(const char *)((u8 *)&lbl_8_data_AD0), (const char *)((u8 *)&lbl_8_data_B28), (const char *)((u8 *)&lbl_8_data_B34), (const char *)((u8 *)&lbl_8_data_B40), (const char *)((u8 *)&lbl_8_data_B4C), (const char *)((u8 *)&lbl_8_data_B58)}, {(const char *)((u8 *)&lbl_8_data_BC0), (const char *)((u8 *)&lbl_8_data_BF4), (const char *)((u8 *)&lbl_8_data_C0C), (const char *)((u8 *)&lbl_8_data_C24), (const char *)((u8 *)&lbl_8_data_C3C), (const char *)((u8 *)&lbl_8_data_C54)}, {(const char *)((u8 *)&lbl_8_data_C7C), (const char *)((u8 *)&lbl_8_data_CAC), (const char *)((u8 *)&lbl_8_data_CC4), (const char *)((u8 *)&lbl_8_data_CDC), (const char *)((u8 *)&lbl_8_data_CF4), (const char *)((u8 *)&lbl_8_data_D0C)}, {(const char *)((u8 *)&lbl_8_data_D34), (const char *)((u8 *)&lbl_8_data_D64), (const char *)((u8 *)&lbl_8_data_D7C), (const char *)((u8 *)&lbl_8_data_D94), (const char *)((u8 *)&lbl_8_data_DAC), (const char *)((u8 *)&lbl_8_data_DC4)}, {(const char *)((u8 *)&lbl_8_data_DF4), (const char *)((u8 *)&lbl_8_data_E24), (const char *)((u8 *)&lbl_8_data_E40), (const char *)((u8 *)&lbl_8_data_E5C), (const char *)((u8 *)&lbl_8_data_E78), (const char *)((u8 *)&lbl_8_data_E94)}, {(const char *)((u8 *)&lbl_8_data_EBC), (const char *)((u8 *)&lbl_8_data_EF0), (const char *)((u8 *)&lbl_8_data_F0C), (const char *)((u8 *)&lbl_8_data_F28), (const char *)((u8 *)&lbl_8_data_F44), (const char *)((u8 *)&lbl_8_data_F60)}, {(const char *)((u8 *)&lbl_8_data_F8C), (const char *)((u8 *)&lbl_8_data_FD0), (const char *)((u8 *)&lbl_8_data_FF0), (const char *)((u8 *)&lbl_8_data_1010), (const char *)((u8 *)&lbl_8_data_1030), (const char *)((u8 *)&lbl_8_data_1050)}, {(const char *)((u8 *)&lbl_8_data_1094), (const char *)((u8 *)&lbl_8_data_10D8), (const char *)((u8 *)&lbl_8_data_10F8), (const char *)((u8 *)&lbl_8_data_1118), (const char *)((u8 *)&lbl_8_data_1138), (const char *)((u8 *)&lbl_8_data_1158)}, {(const char *)((u8 *)&lbl_8_data_119C), (const char *)((u8 *)&lbl_8_data_11CC), (const char *)((u8 *)&lbl_8_data_11EC), (const char *)((u8 *)&lbl_8_data_120C), (const char *)((u8 *)&lbl_8_data_122C), (const char *)((u8 *)&lbl_8_data_124C)}, {(const char *)((u8 *)&lbl_8_data_127C), (const char *)((u8 *)&lbl_8_data_12C0), (const char *)((u8 *)&lbl_8_data_12E0), (const char *)((u8 *)&lbl_8_data_1300), (const char *)((u8 *)&lbl_8_data_1320), (const char *)((u8 *)&lbl_8_data_1340)}, {(const char *)((u8 *)&lbl_8_data_1384), (const char *)((u8 *)&lbl_8_data_13C8), (const char *)((u8 *)&lbl_8_data_13E8), (const char *)((u8 *)&lbl_8_data_1408), (const char *)((u8 *)&lbl_8_data_1428), (const char *)((u8 *)&lbl_8_data_1448)}, {(const char *)((u8 *)&lbl_8_data_148C), (const char *)((u8 *)&lbl_8_data_14AC), (const char *)((u8 *)&lbl_8_data_14BC), (const char *)((u8 *)&lbl_8_data_14CC), (const char *)((u8 *)&lbl_8_data_14DC), (const char *)((u8 *)&lbl_8_data_14EC)}, {(const char *)((u8 *)&lbl_8_data_1508), (const char *)((u8 *)&lbl_8_data_151C), (const char *)((u8 *)&lbl_8_data_152C), (const char *)((u8 *)&lbl_8_data_153C), (const char *)((u8 *)&lbl_8_data_154C), (const char *)((u8 *)&lbl_8_data_155C)}, {(const char *)((u8 *)&lbl_8_data_156C), (const char *)((u8 *)&lbl_8_data_15A0), (const char *)((u8 *)&lbl_8_data_15B8), (const char *)((u8 *)&lbl_8_data_15D0), (const char *)((u8 *)&lbl_8_data_15E8), (const char *)((u8 *)&lbl_8_data_1600)}, {(const char *)((u8 *)&lbl_8_data_1634), (const char *)((u8 *)&lbl_8_data_1668), (const char *)((u8 *)&lbl_8_data_1680), (const char *)((u8 *)&lbl_8_data_1698), (const char *)((u8 *)&lbl_8_data_16B0), (const char *)((u8 *)&lbl_8_data_16C8)}, {(const char *)((u8 *)&lbl_8_data_16FC), (const char *)((u8 *)&lbl_8_data_171C), (const char *)((u8 *)&lbl_8_data_1734), (const char *)((u8 *)&lbl_8_data_174C), (const char *)((u8 *)&lbl_8_data_1764), (const char *)((u8 *)&lbl_8_data_177C)}, {(const char *)((u8 *)&lbl_8_data_17A0), (const char *)((u8 *)&lbl_8_data_17D4), (const char *)((u8 *)&lbl_8_data_17F0), (const char *)((u8 *)&lbl_8_data_180C), (const char *)((u8 *)&lbl_8_data_1828), (const char *)((u8 *)&lbl_8_data_1844)}, {(const char *)((u8 *)&lbl_8_data_1874), (const char *)((u8 *)&lbl_8_data_18AC), (const char *)((u8 *)&lbl_8_data_18C8), (const char *)((u8 *)&lbl_8_data_18E4), (const char *)((u8 *)&lbl_8_data_1900), (const char *)((u8 *)&lbl_8_data_191C)}, {(const char *)((u8 *)&lbl_8_data_1954), (const char *)((u8 *)&lbl_8_data_1994), (const char *)((u8 *)&lbl_8_data_19B4), (const char *)((u8 *)&lbl_8_data_19D4), (const char *)((u8 *)&lbl_8_data_19F4), (const char *)((u8 *)&lbl_8_data_1A14)}, {(const char *)((u8 *)&lbl_8_data_1A54), (const char *)((u8 *)&lbl_8_data_1A90), (const char *)((u8 *)&lbl_8_data_1AB0), (const char *)((u8 *)&lbl_8_data_1AD0), (const char *)((u8 *)&lbl_8_data_1AF0), (const char *)((u8 *)&lbl_8_data_1B10)}, {(const char *)((u8 *)&lbl_8_data_1B50), (const char *)((u8 *)&lbl_8_data_1B8C), (const char *)((u8 *)&lbl_8_data_1BAC), (const char *)((u8 *)&lbl_8_data_1BCC), (const char *)((u8 *)&lbl_8_data_1BEC), (const char *)((u8 *)&lbl_8_data_1C0C)}, {(const char *)((u8 *)&lbl_8_data_1C50), (const char *)((u8 *)&lbl_8_data_1C90), (const char *)((u8 *)&lbl_8_data_1CB0), (const char *)((u8 *)&lbl_8_data_1CD0), (const char *)((u8 *)&lbl_8_data_1CF0), (const char *)((u8 *)&lbl_8_data_1D10)}, {(const char *)((u8 *)&lbl_8_data_1D4C), (const char *)((u8 *)&lbl_8_data_1D8C), (const char *)((u8 *)&lbl_8_data_1DAC), (const char *)((u8 *)&lbl_8_data_1DCC), (const char *)((u8 *)&lbl_8_data_1DEC), (const char *)((u8 *)&lbl_8_data_1E0C)}, {(const char *)((u8 *)&lbl_8_data_1E4C), (const char *)((u8 *)&lbl_8_data_1E78), (const char *)((u8 *)&lbl_8_data_1E90), (const char *)((u8 *)&lbl_8_data_1EA8), (const char *)((u8 *)&lbl_8_data_1EC0), (const char *)((u8 *)&lbl_8_data_1ED8)}, {(const char *)((u8 *)&lbl_8_data_1F04), (const char *)((u8 *)&lbl_8_data_1F60), (const char *)((u8 *)&lbl_8_data_1F78), (const char *)((u8 *)&lbl_8_data_1F90), (const char *)((u8 *)&lbl_8_data_1FA8), (const char *)((u8 *)&lbl_8_data_1FC0)}, {(const char *)((u8 *)&lbl_8_data_202C), (const char *)((u8 *)&lbl_8_data_205C), (const char *)((u8 *)&lbl_8_data_206C), (const char *)((u8 *)&lbl_8_data_207C), (const char *)((u8 *)&lbl_8_data_208C), (const char *)((u8 *)&lbl_8_data_209C)}, {(const char *)((u8 *)&lbl_8_data_20D4), (const char *)((u8 *)&lbl_8_data_2128), (const char *)((u8 *)&lbl_8_data_213C), (const char *)((u8 *)&lbl_8_data_2150), (const char *)((u8 *)&lbl_8_data_2164), (const char *)((u8 *)&lbl_8_data_2178)}, {(const char *)((u8 *)&lbl_8_data_21C0), (const char *)((u8 *)&lbl_8_data_2204), (const char *)((u8 *)&lbl_8_data_2214), (const char *)((u8 *)&lbl_8_data_2224), (const char *)((u8 *)&lbl_8_data_2234), (const char *)((u8 *)&lbl_8_data_2244)}, {(const char *)((u8 *)&lbl_8_data_2288), (const char *)((u8 *)&lbl_8_data_22C0), (const char *)((u8 *)&lbl_8_data_22D4), (const char *)((u8 *)&lbl_8_data_22E8), (const char *)((u8 *)&lbl_8_data_22FC), (const char *)((u8 *)&lbl_8_data_2310)}, {(const char *)((u8 *)&lbl_8_data_2354), (const char *)((u8 *)&lbl_8_data_238C), (const char *)((u8 *)&lbl_8_data_239C), (const char *)((u8 *)&lbl_8_data_23AC), (const char *)((u8 *)&lbl_8_data_23BC), (const char *)((u8 *)&lbl_8_data_23CC)}, {(const char *)((u8 *)&lbl_8_data_2410), (const char *)((u8 *)&lbl_8_data_2470), (const char *)((u8 *)&lbl_8_data_2480), (const char *)((u8 *)&lbl_8_data_2490), (const char *)((u8 *)&lbl_8_data_24A0), (const char *)((u8 *)&lbl_8_data_24B0)}, {(const char *)((u8 *)&lbl_8_data_2508), (const char *)((u8 *)&lbl_8_data_2544), (const char *)((u8 *)&lbl_8_data_2554), (const char *)((u8 *)&lbl_8_data_2564), (const char *)((u8 *)&lbl_8_data_2574), (const char *)((u8 *)&lbl_8_data_2584)}, {(const char *)((u8 *)&lbl_8_data_25DC), (const char *)((u8 *)&lbl_8_data_263C), (const char *)((u8 *)&lbl_8_data_2650), (const char *)((u8 *)&lbl_8_data_2664), (const char *)((u8 *)&lbl_8_data_2678), (const char *)((u8 *)&lbl_8_data_268C)}, {(const char *)((u8 *)&lbl_8_data_26F8), (const char *)((u8 *)&lbl_8_data_2720), (const char *)((u8 *)&lbl_8_data_2734), (const char *)((u8 *)&lbl_8_data_2748), (const char *)((u8 *)&lbl_8_data_275C), (const char *)((u8 *)&lbl_8_data_2770)}, {(const char *)((u8 *)&lbl_8_data_27AC), (const char *)((u8 *)&lbl_8_data_27B4), (const char *)((u8 *)&lbl_8_data_27C0), (const char *)((u8 *)&lbl_8_data_27CC), (const char *)((u8 *)&lbl_8_data_27D8), (const char *)((u8 *)&lbl_8_data_27E4)}, {(const char *)((u8 *)&lbl_8_data_27F0), (const char *)((u8 *)&lbl_8_data_27F8), (const char *)((u8 *)&lbl_8_data_2804), (const char *)((u8 *)&lbl_8_data_2810), (const char *)((u8 *)&lbl_8_data_281C), (const char *)((u8 *)&lbl_8_data_2828)}, {(const char *)((u8 *)&lbl_8_data_2834), (const char *)((u8 *)&lbl_8_data_2838), (const char *)((u8 *)&lbl_8_data_2840), (const char *)((u8 *)&lbl_8_data_2848), (const char *)((u8 *)&lbl_8_data_2850), (const char *)((u8 *)&lbl_8_data_2858)}, {(const char *)((u8 *)&lbl_8_data_2860), (const char *)((u8 *)&lbl_8_data_2864), (const char *)((u8 *)&lbl_8_data_286C), (const char *)((u8 *)&lbl_8_data_2874), (const char *)((u8 *)&lbl_8_data_287C), (const char *)((u8 *)&lbl_8_data_2884)}, {(const char *)((u8 *)&lbl_8_data_288C), (const char *)((u8 *)&lbl_8_data_28C8), (const char *)((u8 *)&lbl_8_data_28DC), (const char *)((u8 *)&lbl_8_data_28F0), (const char *)((u8 *)&lbl_8_data_2904), (const char *)((u8 *)&lbl_8_data_2918)}, {(const char *)((u8 *)&lbl_8_data_2958), (const char *)((u8 *)&lbl_8_data_2AE8), (const char *)((u8 *)&lbl_8_data_2AF4), (const char *)((u8 *)&lbl_8_data_2B00), (const char *)((u8 *)&lbl_8_data_2B0C), (const char *)((u8 *)&lbl_8_data_2B18)}, {(const char *)((u8 *)&lbl_8_data_2D68), (const char *)((u8 *)&lbl_8_data_2E4C), (const char *)((u8 *)&lbl_8_data_2E58), (const char *)((u8 *)&lbl_8_data_2E64), (const char *)((u8 *)&lbl_8_data_2E70), (const char *)((u8 *)&lbl_8_data_2E7C)}, {(const char *)((u8 *)&lbl_8_data_2FD8), (const char *)((u8 *)&lbl_8_data_3168), (const char *)((u8 *)&lbl_8_data_3178), (const char *)((u8 *)&lbl_8_data_3188), (const char *)((u8 *)&lbl_8_data_3198), (const char *)((u8 *)&lbl_8_data_31A8)}, {(const char *)((u8 *)&lbl_8_data_33F8), (const char *)((u8 *)&lbl_8_data_34DC), (const char *)((u8 *)&lbl_8_data_34F0), (const char *)((u8 *)&lbl_8_data_3504), (const char *)((u8 *)&lbl_8_data_3518), (const char *)((u8 *)&lbl_8_data_352C)}, {(const char *)((u8 *)&lbl_8_data_3688), (const char *)((u8 *)&lbl_8_data_36DC), (const char *)((u8 *)&lbl_8_data_36F0), (const char *)((u8 *)&lbl_8_data_3704), (const char *)((u8 *)&lbl_8_data_3718), (const char *)((u8 *)&lbl_8_data_372C)}, {(const char *)((u8 *)&lbl_8_data_378C), (const char *)((u8 *)&lbl_8_data_37B4), (const char *)((u8 *)&lbl_8_data_37CC), (const char *)((u8 *)&lbl_8_data_37E4), (const char *)((u8 *)&lbl_8_data_37FC), (const char *)((u8 *)&lbl_8_data_3814)}, {(const char *)((u8 *)&lbl_8_data_3850), (const char *)((u8 *)&lbl_8_data_3884), (const char *)((u8 *)&lbl_8_data_3894), (const char *)((u8 *)&lbl_8_data_38A4), (const char *)((u8 *)&lbl_8_data_38B4), (const char *)((u8 *)&lbl_8_data_38C4)}, {(const char *)((u8 *)&lbl_8_data_3904), (const char *)((u8 *)&lbl_8_data_391C), (const char *)((u8 *)&lbl_8_data_3930), (const char *)((u8 *)&lbl_8_data_3944), (const char *)((u8 *)&lbl_8_data_3958), (const char *)((u8 *)&lbl_8_data_396C)}, {(const char *)((u8 *)&lbl_8_data_3988), (const char *)((u8 *)&lbl_8_data_3990), (const char *)((u8 *)&lbl_8_data_399C), (const char *)((u8 *)&lbl_8_data_39A8), (const char *)((u8 *)&lbl_8_data_39B4), (const char *)((u8 *)&lbl_8_data_39C0)}, {(const char *)((u8 *)&lbl_8_data_39CC), (const char *)((u8 *)&lbl_8_data_3A04), (const char *)((u8 *)&lbl_8_data_3A14), (const char *)((u8 *)&lbl_8_data_3A24), (const char *)((u8 *)&lbl_8_data_3A34), (const char *)((u8 *)&lbl_8_data_3A44)}, {(const char *)((u8 *)&lbl_8_data_3A88), (const char *)((u8 *)&lbl_8_data_3AB4), (const char *)((u8 *)&lbl_8_data_3AC4), (const char *)((u8 *)&lbl_8_data_3AD4), (const char *)((u8 *)&lbl_8_data_3AE4), (const char *)((u8 *)&lbl_8_data_3AF4)}, {(const char *)((u8 *)&lbl_8_data_3B2C), (const char *)((u8 *)&lbl_8_data_3B6C), (const char *)((u8 *)&lbl_8_data_3B7C), (const char *)((u8 *)&lbl_8_data_3B8C), (const char *)((u8 *)&lbl_8_data_3B9C), (const char *)((u8 *)&lbl_8_data_3BAC)}, {(const char *)((u8 *)&lbl_8_data_3BF0), (const char *)((u8 *)&lbl_8_data_3C48), (const char *)((u8 *)&lbl_8_data_3C58), (const char *)((u8 *)&lbl_8_data_3C68), (const char *)((u8 *)&lbl_8_data_3C78), (const char *)((u8 *)&lbl_8_data_3C88)}, {(const char *)((u8 *)&lbl_8_data_3CCC), (const char *)((u8 *)&lbl_8_data_3D14), (const char *)((u8 *)&lbl_8_data_3D20), (const char *)((u8 *)&lbl_8_data_3D2C), (const char *)((u8 *)&lbl_8_data_3D38), (const char *)((u8 *)&lbl_8_data_3D44)}, {(const char *)((u8 *)&lbl_8_data_3D98), (const char *)((u8 *)&lbl_8_data_3DCC), (const char *)((u8 *)&lbl_8_data_3DD8), (const char *)((u8 *)&lbl_8_data_3DE4), (const char *)((u8 *)&lbl_8_data_3DF0), (const char *)((u8 *)&lbl_8_data_3DFC)}, {(const char *)((u8 *)&lbl_8_data_3E30), (const char *)((u8 *)&lbl_8_data_3E68), (const char *)((u8 *)&lbl_8_data_3E74), (const char *)((u8 *)&lbl_8_data_3E80), (const char *)((u8 *)&lbl_8_data_3E8C), (const char *)((u8 *)&lbl_8_data_3E98)}, {(const char *)((u8 *)&lbl_8_data_3ECC), (const char *)((u8 *)&lbl_8_data_3F00), (const char *)((u8 *)&lbl_8_data_3F0C), (const char *)((u8 *)&lbl_8_data_3F18), (const char *)((u8 *)&lbl_8_data_3F24), (const char *)((u8 *)&lbl_8_data_3F30)}, {(const char *)((u8 *)&lbl_8_data_3F64), (const char *)((u8 *)&lbl_8_data_3F9C), (const char *)((u8 *)&lbl_8_data_3FA8), (const char *)((u8 *)&lbl_8_data_3FB4), (const char *)((u8 *)&lbl_8_data_3FC0), (const char *)((u8 *)&lbl_8_data_3FCC)}, {(const char *)((u8 *)&lbl_8_data_4000), (const char *)((u8 *)&lbl_8_data_403C), (const char *)((u8 *)&lbl_8_data_404C), (const char *)((u8 *)&lbl_8_data_405C), (const char *)((u8 *)&lbl_8_data_406C), (const char *)((u8 *)&lbl_8_data_407C)}, {(const char *)((u8 *)&lbl_8_data_40A4), (const char *)((u8 *)&lbl_8_data_40D4), (const char *)((u8 *)&lbl_8_data_40E8), (const char *)((u8 *)&lbl_8_data_40FC), (const char *)((u8 *)&lbl_8_data_4110), (const char *)((u8 *)&lbl_8_data_4124)}, {(const char *)((u8 *)&lbl_8_data_4160), (const char *)((u8 *)&lbl_8_data_419C), (const char *)((u8 *)&lbl_8_data_41AC), (const char *)((u8 *)&lbl_8_data_41BC), (const char *)((u8 *)&lbl_8_data_41CC), (const char *)((u8 *)&lbl_8_data_41DC)}, {(const char *)((u8 *)&lbl_8_data_4218), (const char *)((u8 *)&lbl_8_data_4240), (const char *)((u8 *)&lbl_8_data_4250), (const char *)((u8 *)&lbl_8_data_4260), (const char *)((u8 *)&lbl_8_data_4270), (const char *)((u8 *)&lbl_8_data_4280)}, {(const char *)((u8 *)&lbl_8_data_42C4), (const char *)((u8 *)&lbl_8_data_4304), (const char *)((u8 *)&lbl_8_data_4314), (const char *)((u8 *)&lbl_8_data_4324), (const char *)((u8 *)&lbl_8_data_4334), (const char *)((u8 *)&lbl_8_data_4344)}, {(const char *)((u8 *)&lbl_8_data_4384), (const char *)((u8 *)&lbl_8_data_43BC), (const char *)((u8 *)&lbl_8_data_43CC), (const char *)((u8 *)&lbl_8_data_43DC), (const char *)((u8 *)&lbl_8_data_43EC), (const char *)((u8 *)&lbl_8_data_43FC)}, {(const char *)((u8 *)&lbl_8_data_4424), (const char *)((u8 *)&lbl_8_data_4434), (const char *)((u8 *)&lbl_8_data_4444), (const char *)((u8 *)&lbl_8_data_4454), (const char *)((u8 *)&lbl_8_data_4464), (const char *)((u8 *)&lbl_8_data_4474)}, {(const char *)((u8 *)&lbl_8_data_4484), (const char *)((u8 *)&lbl_8_data_4490), (const char *)((u8 *)&lbl_8_data_44A0), (const char *)((u8 *)&lbl_8_data_44B0), (const char *)((u8 *)&lbl_8_data_44C0), (const char *)((u8 *)&lbl_8_data_44D0)}, {(const char *)((u8 *)&lbl_8_data_44DC), (const char *)((u8 *)&lbl_8_data_44EC), (const char *)((u8 *)&lbl_8_data_44FC), (const char *)((u8 *)&lbl_8_data_450C), (const char *)((u8 *)&lbl_8_data_451C), (const char *)((u8 *)&lbl_8_data_452C)}, {(const char *)((u8 *)&lbl_8_data_453C), (const char *)((u8 *)&lbl_8_data_454C), (const char *)((u8 *)&lbl_8_data_455C), (const char *)((u8 *)&lbl_8_data_456C), (const char *)((u8 *)&lbl_8_data_457C), (const char *)((u8 *)&lbl_8_data_458C)}, {(const char *)((u8 *)&lbl_8_data_459C), (const char *)((u8 *)&lbl_8_data_45F0), (const char *)((u8 *)&lbl_8_data_45FC), (const char *)((u8 *)&lbl_8_data_4608), (const char *)((u8 *)&lbl_8_data_4614), (const char *)((u8 *)&lbl_8_data_4620)}, {(const char *)((u8 *)&lbl_8_data_4688), (const char *)((u8 *)&lbl_8_data_46DC), (const char *)((u8 *)&lbl_8_data_46E8), (const char *)((u8 *)&lbl_8_data_46F4), (const char *)((u8 *)&lbl_8_data_4700), (const char *)((u8 *)&lbl_8_data_470C)}, {(const char *)((u8 *)&lbl_8_data_4774), (const char *)((u8 *)&lbl_8_data_47A0), (const char *)((u8 *)&lbl_8_data_47B0), (const char *)((u8 *)&lbl_8_data_47C0), (const char *)((u8 *)&lbl_8_data_47D0), (const char *)((u8 *)&lbl_8_data_47E0)}, {(const char *)((u8 *)&lbl_8_data_480C), (const char *)((u8 *)&lbl_8_data_483C), (const char *)((u8 *)&lbl_8_data_484C), (const char *)((u8 *)&lbl_8_data_485C), (const char *)((u8 *)&lbl_8_data_486C), (const char *)((u8 *)&lbl_8_data_487C)}, {(const char *)((u8 *)&lbl_8_data_48B0), (const char *)((u8 *)&lbl_8_data_4948), (const char *)((u8 *)&lbl_8_data_4960), (const char *)((u8 *)&lbl_8_data_4978), (const char *)((u8 *)&lbl_8_data_4990), (const char *)((u8 *)&lbl_8_data_49A8)}, {(const char *)((u8 *)&lbl_8_data_4A34), (const char *)((u8 *)&lbl_8_data_4A78), (const char *)((u8 *)&lbl_8_data_4A90), (const char *)((u8 *)&lbl_8_data_4AA8), (const char *)((u8 *)&lbl_8_data_4AC0), (const char *)((u8 *)&lbl_8_data_4AD8)}, {(const char *)((u8 *)&lbl_8_data_4B28), (const char *)((u8 *)&lbl_8_data_4B9C), (const char *)((u8 *)&lbl_8_data_4BA0), (const char *)((u8 *)&lbl_8_data_4BA4), (const char *)((u8 *)&lbl_8_data_4BA8), (const char *)((u8 *)&lbl_8_data_4BAC)}, {(const char *)((u8 *)&lbl_8_data_4C68), (const char *)((u8 *)&lbl_8_data_4CE0), (const char *)((u8 *)&lbl_8_data_4CE4), (const char *)((u8 *)&lbl_8_data_4CE8), (const char *)((u8 *)&lbl_8_data_4CEC), (const char *)((u8 *)&lbl_8_data_4CF0)}, {(const char *)((u8 *)&lbl_8_data_4D4C), (const char *)((u8 *)&lbl_8_data_4D54), (const char *)((u8 *)&lbl_8_data_4D60), (const char *)((u8 *)&lbl_8_data_4D6C), (const char *)((u8 *)&lbl_8_data_4D78), (const char *)((u8 *)&lbl_8_data_4D84)}, {(const char *)((u8 *)&lbl_8_data_4D8C), (const char *)((u8 *)&lbl_8_data_4D94), (const char *)((u8 *)&lbl_8_data_4DA0), (const char *)((u8 *)&lbl_8_data_4DAC), (const char *)((u8 *)&lbl_8_data_4DB8), (const char *)((u8 *)&lbl_8_data_4DC4)}, {(const char *)((u8 *)&lbl_8_data_4DCC), (const char *)((u8 *)&lbl_8_data_4DD4), (const char *)((u8 *)&lbl_8_data_4DE0), (const char *)((u8 *)&lbl_8_data_4DEC), (const char *)((u8 *)&lbl_8_data_4DF8), (const char *)((u8 *)&lbl_8_data_4E04)}, {(const char *)((u8 *)&lbl_8_data_4E10), (const char *)((u8 *)&lbl_8_data_4E18), (const char *)((u8 *)&lbl_8_data_4E24), (const char *)((u8 *)&lbl_8_data_4E30), (const char *)((u8 *)&lbl_8_data_4E3C), (const char *)((u8 *)&lbl_8_data_4E48)}, {(const char *)((u8 *)&lbl_8_data_4E54), (const char *)((u8 *)&lbl_8_data_4E5C), (const char *)((u8 *)&lbl_8_data_4E68), (const char *)((u8 *)&lbl_8_data_4E74), (const char *)((u8 *)&lbl_8_data_4E80), (const char *)((u8 *)&lbl_8_data_4E8C)}, {(const char *)((u8 *)&lbl_8_data_4E98), (const char *)((u8 *)&lbl_8_data_4EA0), (const char *)((u8 *)&lbl_8_data_4EAC), (const char *)((u8 *)&lbl_8_data_4EB8), (const char *)((u8 *)&lbl_8_data_4EC4), (const char *)((u8 *)&lbl_8_data_4ED0)}, {(const char *)((u8 *)&lbl_8_data_4EDC), (const char *)((u8 *)&lbl_8_data_4EE4), (const char *)((u8 *)&lbl_8_data_4EF0), (const char *)((u8 *)&lbl_8_data_4EFC), (const char *)((u8 *)&lbl_8_data_4F08), (const char *)((u8 *)&lbl_8_data_4F14)}, {(const char *)((u8 *)&lbl_8_data_4F20), (const char *)((u8 *)&lbl_8_data_4F28), (const char *)((u8 *)&lbl_8_data_4F34), (const char *)((u8 *)&lbl_8_data_4F40), (const char *)((u8 *)&lbl_8_data_4F4C), (const char *)((u8 *)&lbl_8_data_4F58)}, {(const char *)((u8 *)&lbl_8_data_4F60), (const char *)((u8 *)&lbl_8_data_50A4), (const char *)((u8 *)&lbl_8_data_50A8), (const char *)((u8 *)&lbl_8_data_50AC), (const char *)((u8 *)&lbl_8_data_50B0), (const char *)((u8 *)&lbl_8_data_50B4)}, {(const char *)((u8 *)&lbl_8_data_5224), (const char *)((u8 *)&lbl_8_data_5268), (const char *)((u8 *)&lbl_8_data_526C), (const char *)((u8 *)&lbl_8_data_5270), (const char *)((u8 *)&lbl_8_data_5274), (const char *)((u8 *)&lbl_8_data_5278)}, {(const char *)((u8 *)&lbl_8_data_52BC), (const char *)((u8 *)&lbl_8_data_5300), (const char *)((u8 *)&lbl_8_data_5304), (const char *)((u8 *)&lbl_8_data_5308), (const char *)((u8 *)&lbl_8_data_530C), (const char *)((u8 *)&lbl_8_data_5310)}, {(const char *)((u8 *)&lbl_8_data_5358), (const char *)((u8 *)&lbl_8_data_5390), (const char *)((u8 *)&lbl_8_data_5394), (const char *)((u8 *)&lbl_8_data_5398), (const char *)((u8 *)&lbl_8_data_539C), (const char *)((u8 *)&lbl_8_data_53A0)}, {(const char *)((u8 *)&lbl_8_data_53F8), (const char *)((u8 *)&lbl_8_data_5400), (const char *)((u8 *)&lbl_8_data_5404), (const char *)((u8 *)&lbl_8_data_5408), (const char *)((u8 *)&lbl_8_data_540C), (const char *)((u8 *)&lbl_8_data_5410)}, {(const char *)((u8 *)&lbl_8_data_5418), (const char *)((u8 *)&lbl_8_data_5420), (const char *)((u8 *)&lbl_8_data_5424), (const char *)((u8 *)&lbl_8_data_5428), (const char *)((u8 *)&lbl_8_data_542C), (const char *)((u8 *)&lbl_8_data_5430)}, {(const char *)((u8 *)&lbl_8_data_5438), (const char *)((u8 *)&lbl_8_data_5440), (const char *)((u8 *)&lbl_8_data_5444), (const char *)((u8 *)&lbl_8_data_5448), (const char *)((u8 *)&lbl_8_data_544C), (const char *)((u8 *)&lbl_8_data_5450)}, {(const char *)((u8 *)&lbl_8_data_5458), (const char *)((u8 *)&lbl_8_data_5460), (const char *)((u8 *)&lbl_8_data_5464), (const char *)((u8 *)&lbl_8_data_5468), (const char *)((u8 *)&lbl_8_data_546C), (const char *)((u8 *)&lbl_8_data_5470)}, {(const char *)((u8 *)&lbl_8_data_5478), (const char *)((u8 *)&lbl_8_data_54AC), (const char *)((u8 *)&lbl_8_data_54B0), (const char *)((u8 *)&lbl_8_data_54B4), (const char *)((u8 *)&lbl_8_data_54B8), (const char *)((u8 *)&lbl_8_data_54BC)}, {(const char *)((u8 *)&lbl_8_data_5510), (const char *)((u8 *)&lbl_8_data_5564), (const char *)((u8 *)&lbl_8_data_5568), (const char *)((u8 *)&lbl_8_data_556C), (const char *)((u8 *)&lbl_8_data_5570), (const char *)((u8 *)&lbl_8_data_5574)}, {(const char *)((u8 *)&lbl_8_data_55C0), (const char *)((u8 *)&lbl_8_data_55C8), (const char *)((u8 *)&lbl_8_data_55CC), (const char *)((u8 *)&lbl_8_data_55D0), (const char *)((u8 *)&lbl_8_data_55D4), (const char *)((u8 *)&lbl_8_data_55D8)}, {(const char *)((u8 *)&lbl_8_data_55E4), (const char *)((u8 *)&lbl_8_data_5624), (const char *)((u8 *)&lbl_8_data_5638), (const char *)((u8 *)&lbl_8_data_564C), (const char *)((u8 *)&lbl_8_data_5660), (const char *)((u8 *)&lbl_8_data_5674)}, {(const char *)((u8 *)&lbl_8_data_5750), (const char *)((u8 *)&lbl_8_data_57CC), (const char *)((u8 *)&lbl_8_data_57DC), (const char *)((u8 *)&lbl_8_data_57EC), (const char *)((u8 *)&lbl_8_data_57FC), (const char *)((u8 *)&lbl_8_data_580C)}, {(const char *)((u8 *)&lbl_8_data_58EC), (const char *)((u8 *)&lbl_8_data_595C), (const char *)((u8 *)&lbl_8_data_5970), (const char *)((u8 *)&lbl_8_data_5984), (const char *)((u8 *)&lbl_8_data_5998), (const char *)((u8 *)&lbl_8_data_59AC)}, {(const char *)((u8 *)&lbl_8_data_59B0), (const char *)((u8 *)&lbl_8_data_5A58), (const char *)((u8 *)&lbl_8_data_5A68), (const char *)((u8 *)&lbl_8_data_5A78), (const char *)((u8 *)&lbl_8_data_5A88), (const char *)((u8 *)&lbl_8_data_5A98)}, {(const char *)((u8 *)&lbl_8_data_5A9C), (const char *)((u8 *)&lbl_8_data_5B44), (const char *)((u8 *)&lbl_8_data_5B54), (const char *)((u8 *)&lbl_8_data_5B64), (const char *)((u8 *)&lbl_8_data_5B74), (const char *)((u8 *)&lbl_8_data_5B84)}, {(const char *)((u8 *)&lbl_8_data_5C3C), (const char *)((u8 *)&lbl_8_data_5C64), (const char *)((u8 *)&lbl_8_data_5C74), (const char *)((u8 *)&lbl_8_data_5C84), (const char *)((u8 *)&lbl_8_data_5C94), (const char *)((u8 *)&lbl_8_data_5CA4)}, {(const char *)((u8 *)&lbl_8_data_5CD4), (const char *)((u8 *)&lbl_8_data_5D1C), (const char *)((u8 *)&lbl_8_data_5D2C), (const char *)((u8 *)&lbl_8_data_5D3C), (const char *)((u8 *)&lbl_8_data_5D4C), (const char *)((u8 *)&lbl_8_data_5D5C)}, {(const char *)((u8 *)&lbl_8_data_5DC4), (const char *)((u8 *)&lbl_8_data_5DFC), (const char *)((u8 *)&lbl_8_data_5E0C), (const char *)((u8 *)&lbl_8_data_5E1C), (const char *)((u8 *)&lbl_8_data_5E2C), (const char *)((u8 *)&lbl_8_data_5E3C)}, {(const char *)((u8 *)&lbl_8_data_5E84), (const char *)((u8 *)&lbl_8_data_5EB0), (const char *)((u8 *)&lbl_8_data_5EC4), (const char *)((u8 *)&lbl_8_data_5ED8), (const char *)((u8 *)&lbl_8_data_5EEC), (const char *)((u8 *)&lbl_8_data_5F00)}, {(const char *)((u8 *)&lbl_8_data_5F30), (const char *)((u8 *)&lbl_8_data_5F44), (const char *)((u8 *)&lbl_8_data_5F54), (const char *)((u8 *)&lbl_8_data_5F64), (const char *)((u8 *)&lbl_8_data_5F74), (const char *)((u8 *)&lbl_8_data_5F84)}, {(const char *)((u8 *)&lbl_8_data_5F90), (const char *)((u8 *)&lbl_8_data_5FA4), (const char *)((u8 *)&lbl_8_data_5FB8), (const char *)((u8 *)&lbl_8_data_5FCC), (const char *)((u8 *)&lbl_8_data_5FE0), (const char *)((u8 *)&lbl_8_data_5FF4)}, {(const char *)((u8 *)&lbl_8_data_6014), (const char *)((u8 *)&lbl_8_data_6030), (const char *)((u8 *)&lbl_8_data_6044), (const char *)((u8 *)&lbl_8_data_6058), (const char *)((u8 *)&lbl_8_data_606C), (const char *)((u8 *)&lbl_8_data_6080)}, {(const char *)((u8 *)&lbl_8_data_60A4), (const char *)((u8 *)&lbl_8_data_60C4), (const char *)((u8 *)&lbl_8_data_60D4), (const char *)((u8 *)&lbl_8_data_60E4), (const char *)((u8 *)&lbl_8_data_60F4), (const char *)((u8 *)&lbl_8_data_6104)}, {(const char *)((u8 *)&lbl_8_data_6118), (const char *)((u8 *)&lbl_8_data_614C), (const char *)((u8 *)&lbl_8_data_6160), (const char *)((u8 *)&lbl_8_data_6174), (const char *)((u8 *)&lbl_8_data_6188), (const char *)((u8 *)&lbl_8_data_619C)}, {(const char *)((u8 *)&lbl_8_data_61C0), (const char *)((u8 *)&lbl_8_data_61D0), (const char *)((u8 *)&lbl_8_data_61E0), (const char *)((u8 *)&lbl_8_data_61F0), (const char *)((u8 *)&lbl_8_data_6200), (const char *)((u8 *)&lbl_8_data_6210)}, {(const char *)((u8 *)&lbl_8_data_6220), (const char *)((u8 *)&lbl_8_data_624C), (const char *)((u8 *)&lbl_8_data_6260), (const char *)((u8 *)&lbl_8_data_6274), (const char *)((u8 *)&lbl_8_data_6288), (const char *)((u8 *)&lbl_8_data_629C)}}
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6D68[79] __attribute__((aligned(8))) = "A Memory Card is not inserted in Slot A.\nPlease properly insert a Memory Card.";
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") u8 lbl_8_data_6DB8[4] __attribute__((aligned(8))) = {
    0x00U, 0x00U, 0x00U, 0x00U
};
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6DBC[113] __attribute__((aligned(4))) = "\x83X\x83\x8D\x83" "b\x83gA\x82\xC9\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xAA\x8C\xA9[\x82\xDD]\x82\xC2\x82\xA9\x82\xE8\x82\xDC\x82\xB9\x82\xF1\x81" "B\n\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xCC\x90\xDA[\x82\xB9\x82\xC2]\x91\xB1[\x82\xBC\x82\xAD]\x82\xF0\x8Am[\x82\xA9\x82\xAD]\x94" "F[\x82\xC9\x82\xF1]\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_6E30[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_6D68,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DBC
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6E48[64] __attribute__((aligned(8))) = "There are %d blocks of free space\non the Memory Card in Slot A.";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6E88[59] __attribute__((aligned(8))) = "\x83X\x83\x8D\x83" "b\x83gA\x82\xCC\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xCD\n%d\x83u\x83\x8D\x83" "b\x83N\x82\xCC\x8B\xF3[\x82\xA0]\x82\xAB\x82\xAA\x82\xA0\x82\xE8\x82\xDC\x82\xB7";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_6EC4[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_6E48,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6E88
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6EDC[29] __attribute__((aligned(4))) = "The game could not be saved.";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6EFC[37] __attribute__((aligned(4))) = "\x83Q\x81[\x83\x80\x83" "f\x81[\x83^\x82\xCD\x83Z\x81[\x83u\x82\xB3\x82\xEA\x82\xDC\x82\xB9\x82\xF1\x82\xC5\x82\xB5\x82\xBD";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_6F24[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_6EDC,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6EFC
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_6F3C[484] __attribute__((aligned(4))) = "There is not enough free space on the Memory Card\nin Slot A to save all types of new files .\nE"
    "xisting F-ZERO GX files may be erased or overwritten.\n(To manage files on the Memory Card, plea"
    "se go to the\nNintendo GameCube Memory Card management screen.)\nIn order to save a new file, th"
    "e following number of\nfree files and blocks must be available:\nGame 1 file and 4 blocks\nGarag"
    "e 1 file and 18 blocks\nGhost 1 file and 3 blocks\nEmblem 1 file and 3 blocks\nReplay 1 file and"
    " 3\201`13 blocks\n";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7120[221] __attribute__((aligned(8))) = "\x83X\x83\x8D\x83" "b\x83gA\x82\xCC\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xC9\x8B\xF3\x82\xAB\x97" "e\x97\xCA\x82\xAA\x82\xC8\x82\xA2\x82\xA9\x81" "A\x83t\x83@\x83" "C\x83\x8B\x90\x94\x82\xCC\x90\xA7\x8C\xC0\x82\xF0\n\x89z\x82\xA6\x82\xC4\x82\xB5\x82\xDC\x82\xA2\x82\xDC\x82\xB7\x81" "B\x83Z\x81[\x83u\x82\xB7\x82\xE9\x82\xC9\x82\xCD\x8F\xAD\x82\xC8\x82\xAD\x82\xC6\x82\xE0\x83t\x83@\x83" "C\x83\x8B" "1\x82\xC2\x82\xC6\n4\x83u\x83\x8D\x83" "b\x83N\x95K\x97v\x82\xC5\x82\xB7\x81" "B(\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xCC\x93\xE0\x97" "e\x82\xF0\x90\xAE\x97\x9D\x82\xB7\x82\xE9\x82\xC9\x82\xCD\x81" "A\n\x96{\x91\xCC\x82\xCC\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x89\xE6\x96\xCA\x82\xC5\x8Ds\x82\xC8\x82\xC1\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2)";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_7200[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_6F3C,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_7120
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7218[59] __attribute__((aligned(8))) = "The Memory Card in Slot A\nis corrupted and cannot be used.";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7254[27] __attribute__((aligned(4))) = "\x83G\x83\x93\x83R\x81[\x83h\x82\xAA\x82\xA8\x82\xA9\x82\xB5\x82\xA2\x82\xC5\x82\xB7\x82\xE6";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_7270[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_7218,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_7254
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7288[58] __attribute__((aligned(8))) = "The Memory Card in Slot A is damaged\nand cannot be used. ";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_72C4[81] __attribute__((aligned(4))) = "\x83X\x83\x8D\x83" "b\x83gA\x82\xCC\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xCD\x81" "A\x83" "f\x81[\x83^\x82\xAA\n\x82\xB1\x82\xED\x82\xEA\x82\xC4\x82\xA2\x82\xE9\x82\xCC\x82\xC5\x8Eg[\x82\xB5]\x97p[\x82\xE6\x82\xA4]\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\x81" "B";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_7318[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_7288,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_72C4
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7330[42] __attribute__((aligned(8))) = "Please insert a Memory Card into Slot A. ";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_735C[60] __attribute__((aligned(4))) = "\x83X\x83\x8D\x83" "b\x83gA\x82\xC9\x8Eg[\x82\xB5]\x97p[\x82\xE6\x82\xA4]\x82\xB7\x82\xE9\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xF0\x82\xB3\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_7398[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_7330,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_735C
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_73B0[68] __attribute__((aligned(8))) = "The device in Slot A is not supported.\nPlease insert a Memory Card.";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_73F4[67] __attribute__((aligned(4))) = "\x83X\x83\x8D\x83" "b\x83gA\x82\xC9\x82\xCD\n\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x88\xC8[\x82\xA2]\x8AO[\x82\xAA\x82\xA2]\x82\xCC\x82\xE0\x82\xCC\x82\xAA\x82\xB3\x82\xB3\x82\xC1\x82\xC4\x82\xA2\x82\xDC\x82\xB7\x81" "B";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_7438[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_73B0,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_73F4
};
#pragma explicit_zero_data reset




#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7450[42] __attribute__((aligned(8))) = "\x83\x9F\x81" "cContinue without saving\n\x83\xB2\x81" "cTry again";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_747C[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_7450,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7494[54] __attribute__((aligned(4))) = "Game Data cannot be loaded.\nContinue without saving\077 ";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_74CC[63] __attribute__((aligned(4))) = "\x82\xB1\x82\xCC\x82\xDC\x82\xDC\x82\xC5\x82\xCD\x81" "A\x83Q\x81[\x83\x80\x83" "f\x81[\x83^\x82\xF0\n\x83\x8D\x81[\x83h\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\x82\xAA\x82\xE6\x82\xEB\x82\xB5\x82\xA2\x82\xC5\x82\xB7\x82\xA9?";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_750C[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_7494,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_74CC
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7524[54] __attribute__((aligned(4))) = "Game Data cannot be saved.\n Continue without saving\077 ";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_755C[63] __attribute__((aligned(4))) = "\x82\xB1\x82\xCC\x82\xDC\x82\xDC\x82\xC5\x82\xCD\x81" "A\x83Q\x81[\x83\x80\x83" "f\x81[\x83^\x82\xF0\n\x83Z\x81[\x83u\x82\xC5\x82\xAB\x82\xDC\x82\xB9\x82\xF1\x82\xAA\x82\xE6\x82\xEB\x82\xB5\x82\xA2\x82\xC5\x82\xB7\x82\xA9?";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_759C[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_7524,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_755C
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_75B4[101] __attribute__((aligned(4))) = "Game Data could not be saved.\n You can save and load data from\n the Memory Card menu under Opt"
    "ions. ";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_761C[131] __attribute__((aligned(4))) = "\x83Q\x81[\x83\x80\x83" "f\x81[\x83^\x82\xCD\x83\x8D\x81[\x83h\x82\xB3\x82\xEA\x82\xDC\x82\xB9\x82\xF1\x82\xC5\x82\xB5\x82\xBD\x81" "B\n\x83Q\x81[\x83\x80\x83" "f\x81[\x83^\x82\xCC\x83Z\x81[\x83u\x81" "A\x83\x8D\x81[\x83h\x82\xCD\x81" "A\n\x83I\x83v\x83V\x83\x87\x83\x93\x82\xCC\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x83\x81\x83j\x83\x85\x81[\x82\xA9\x82\xE7\x89\xC2[\x82\xA9]\x94\\[\x82\xCC\x82\xA4]\x82\xC5\x82\xB7\x81" "B";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_76A0[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_75B4,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_761C
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_76B8[98] __attribute__((aligned(8))) = "Game Data could not be saved.\nYou can save and load data from\nthe Memory Card menu under Optio"
    "ns.";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_771C[131] __attribute__((aligned(4))) = "\x83Q\x81[\x83\x80\x83" "f\x81[\x83^\x82\xCD\x83Z\x81[\x83u\x82\xB3\x82\xEA\x82\xDC\x82\xB9\x82\xF1\x82\xC5\x82\xB5\x82\xBD\x81" "B\n\x83Q\x81[\x83\x80\x83" "f\x81[\x83^\x82\xCC\x83Z\x81[\x83u\x81" "A\x83\x8D\x81[\x83h\x82\xCD\x81" "A\n\x83I\x83v\x83V\x83\x87\x83\x93\x82\xCC\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x83\x81\x83j\x83\x85\x81[\x82\xA9\x82\xE7\x89\xC2[\x82\xA9]\x94\\[\x82\xCC\x82\xA4]\x82\xC5\x82\xB7\x81" "B";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_77A0[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_76B8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_771C
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_77B8[145] __attribute__((aligned(8))) = "There is no F-ZERO GX save file\non the Memory Card in Slot A.\nWould you like to create a save "
    "file now\077 \n(1 save file uses 4 blocks of memory.)\n";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_784C[179] __attribute__((aligned(4))) = "\x83X\x83\x8D\x83" "b\x83gA\x82\xCC\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xC9\x82\xCD" "F-ZERO GX\x82\xCC\n\x83Q\x81[\x83\x80\x83" "f\x81[\x83^\x82\xAA\x82\xA0\x82\xE8\x82\xDC\x82\xB9\x82\xF1\x81" "B\x83X\x83\x8D\x83" "b\x83gA\x82\xCC\n\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xC9\x83Q\x81[\x83\x80\x83" "f\x81[\x83^\x82\xF0\x8D\xEC[\x82\xB3\x82\xAD]\x90\xAC[\x82\xB9\x82\xA2]\x82\xB5\x82\xC4\x82\xE0\n\x82\xE6\x82\xEB\x82\xB5\x82\xA2\x82\xC5\x82\xB7\x82\xA9?(4\x83u\x83\x8D\x83" "b\x83N\x8Eg[\x82\xB5]\x97p[\x82\xE6\x82\xA4]\x82\xB5\x82\xDC\x82\xB7)";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_7900[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_77B8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_784C
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7918[44] __attribute__((aligned(8))) = "Advancing to user name\nregistration screen.";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7944[59] __attribute__((aligned(4))) = "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xC9\x83\x86\x81[\x83U\x81[\x96\xBC[\x82\xDF\x82\xA2]\x82\xF0\x93o[\x82\xC6\x82\xA4]\x98^[\x82\xEB\x82\xAD]\x82\xB5\x82\xDC\x82\xB7\x81" "B";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_7980[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_7918,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_7944
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7998[72] __attribute__((aligned(8))) = "The Memory Card in Slot A was removed.\n The process has been cancelled.";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_79E0[56] __attribute__((aligned(8))) = "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xAA\x94\xB2\x82\xA9\x82\xEA\x82\xDC\x82\xB5\x82\xBD\x81" "B\n\x8D\xEC\x8B\xC6\x82\xF0\x83L\x83\x83\x83\x93\x83Z\x83\x8B\x82\xB5\x82\xDC\x82\xB7\x81" "B";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_7A18[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_7998,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_79E0
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7A30[68] __attribute__((aligned(8))) = "Press the \203\237 Button when ready.\n Press the \203\240 Button to cancel. \000\000\000";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7A74[58] __attribute__((aligned(4))) = "\x8F\x80\x94\xF5\x82\xAA\x82\xC5\x82\xAB\x82\xBD\x82\xE7\x83\x9F\x82\xF0\x89\x9F\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B\n\x83\xA0\x82\xC5\x83L\x83\x83\x83\x93\x83Z\x83\x8B\x82\xB5\x82\xDC\x82\xB7\x81" "B";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_7AB0[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_7A30,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_7A74
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7AC8[40] __attribute__((aligned(8))) = "The Memory Card process was cancelled. ";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7AF0[55] __attribute__((aligned(8))) = "\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xCC\x8D\xEC[\x82\xB3\x82\xAC]\x8B\xC6[\x82\xE5\x82\xA4]\x82\xF0\x83L\x83\x83\x83\x93\x83Z\x83\x8B\x82\xB5\x82\xDC\x82\xB5\x82\xBD\x81" "B";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_7B28[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_7AC8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_7AF0
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7B40[32] __attribute__((aligned(8))) = "Please press the \203\237 Button. \000\000\000";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7B60[21] __attribute__((aligned(8))) = "\x83\x9F\x82\xF0\x89\x9F\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2\x81" "B";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_7B78[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_7B40,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_7B60
};
#pragma explicit_zero_data reset



#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7B90[50] __attribute__((aligned(8))) = "Register this name on the\nMemory Card in Slot A\077 ";
#pragma explicit_zero_data reset





#pragma explicit_zero_data on
__declspec(section ".data") char lbl_8_data_7BC4[53] __attribute__((aligned(4))) = "\x82\xB1\x82\xCC\x96\xBC\x91O\x82\xC5\x83\x81\x83\x82\x83\x8A\x81[\x83J\x81[\x83h\x82\xC9\n\x93o\x98^\x82\xB5\x82\xC4\x82\xE0\x82\xE6\x82\xEB\x82\xB5\x82\xA2\x82\xC5\x82\xB7\x82\xA9?";
#pragma explicit_zero_data reset

#pragma explicit_zero_data on
__declspec(section ".data") u8 *lbl_8_data_7BFC[6] __attribute__((aligned(4))) = {
    (u8 *)&lbl_8_data_7B90,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_6DB8,
    (u8 *)&lbl_8_data_7BC4
};
#pragma explicit_zero_data reset

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 362.0f;
    s = 1.0f;
    s = 0.0f;
    s = 0.4000000059604645f;
    s = 3.5f;
    s = 0.6700000166893005f;
    s = 120.0f;
    s = 2.0f;
    s = 0.75f;
    s = 3.0f;
    s = 16.0f;
    s = 464.0f;
    s = 0.009999999776482582f;
    s = 0.10000000149011612f;
    s = 360.0f;
    s = 240.0f;
    s = 200.0f;
}
#pragma section code_type ".text"

#pragma section code_type ".fzgxpool"
static void fzgx_data_layout(void) {
    void *volatile s; /* fzgx-allow: S2 layout primer sink: the .data section base is created before the .bss base */
    s = lbl_8_data_6E30[0];
    s = lbl_8_data_6EC4[0];
    s = lbl_8_data_6F24[0];
}
#pragma section code_type ".text"

/* file-scope objects of the retail TU (from a matched sibling), in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_8_bss_0;
u8 fzgx_pool_lbl_8_bss_0_gap_1;
u8 fzgx_obj_lbl_8_bss_2;
u8 fzgx_pool_lbl_8_bss_0_gap_3;
f32 fzgx_obj_lbl_8_bss_4;
u32 lbl_8_bss_4__fzgx_offset_4;
u32 fzgx_obj_lbl_8_bss_C[5];
u32 lbl_8_bss_20__fzgx_offset_0[128];
f32 lbl_8_bss_20__fzgx_offset_200;
s16 fzgx_obj_lbl_8_bss_224;
u16 fzgx_pool_lbl_8_bss_0_gap_226;
u32 fzgx_obj_lbl_8_bss_228;
u32 fzgx_obj_lbl_8_bss_22C;
u8 fzgx_obj_lbl_8_bss_230;
u8 fzgx_pool_lbl_8_bss_0_gap_231;
u16 fzgx_pool_lbl_8_bss_0_gap_231_fill_232;
u32 fzgx_obj_lbl_8_bss_234;
u32 fzgx_obj_lbl_8_bss_238;
u8 lbl_8_bss_238__fzgx_offset_4;
u8 fzgx_obj_lbl_8_bss_23D;
u16 fzgx_pool_lbl_8_bss_0_gap_23E;
u8 fzgx_pool_lbl_8_bss_0_gap_23E_fill_240;
u8 lbl_8_bss_238__fzgx_offset_9;
u8 fzgx_obj_lbl_8_bss_242;
u8 lbl_8_bss_242__fzgx_offset_1;
s32 lbl_8_bss_242__fzgx_offset_2;
u8 lbl_8_bss_242__fzgx_offset_6;
u8 lbl_8_bss_242__fzgx_offset_7;
u16 lbl_8_bss_242__fzgx_offset_8;
u32 lbl_8_bss_242__fzgx_offset_A;
u8 lbl_8_bss_242__fzgx_offset_E;
u8 lbl_8_bss_242__fzgx_offset_F;
u8 lbl_8_bss_242__fzgx_offset_10;
u8 lbl_8_bss_242__fzgx_offset_11;
s32 lbl_8_bss_242__fzgx_offset_12;
s32 lbl_8_bss_242__fzgx_offset_16;
s32 lbl_8_bss_242__fzgx_offset_1A;
u8 lbl_8_bss_242__fzgx_offset_1E;
u8 lbl_8_bss_242__fzgx_offset_1F;
u16 lbl_8_bss_242__fzgx_offset_20;
s32 lbl_8_bss_242__fzgx_offset_22;
u8 lbl_8_bss_242__fzgx_offset_26;
u8 lbl_8_bss_242__fzgx_offset_27;
u16 lbl_8_bss_242__fzgx_offset_28;
u32 lbl_8_bss_242__fzgx_offset_2A[15];
u16 fzgx_obj_lbl_8_bss_2A8;
u16 fzgx_pool_lbl_8_bss_0_gap_2AA;
u32 fzgx_obj_lbl_8_bss_2AC;
u32 fzgx_obj_lbl_8_bss_2B0;
u32 fzgx_obj_lbl_8_bss_2B4;
u32 fzgx_obj_lbl_8_bss_2B8;
u32 fzgx_obj_lbl_8_bss_2BC;
u32 fzgx_obj_lbl_8_bss_2C0[67];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_8_bss_0;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_1;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_3;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_4;
    s = *(u8 *)&lbl_8_bss_4__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_C;
    s = *(u8 *)&lbl_8_bss_20__fzgx_offset_0;
    s = *(u8 *)&lbl_8_bss_20__fzgx_offset_200;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_224;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_226;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_228;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_22C;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_230;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_231;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_231_fill_232;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_234;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_238;
    s = *(u8 *)&lbl_8_bss_238__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_23D;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_23E;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_23E_fill_240;
    s = *(u8 *)&lbl_8_bss_238__fzgx_offset_9;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_242;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_1;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_2;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_6;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_7;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_8;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_A;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_E;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_F;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_10;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_11;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_12;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_16;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_1A;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_1E;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_1F;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_20;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_22;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_26;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_27;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_28;
    s = *(u8 *)&lbl_8_bss_242__fzgx_offset_2A;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2A8;
    s = *(u8 *)&fzgx_pool_lbl_8_bss_0_gap_2AA;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2AC;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2B0;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2B4;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2B8;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2BC;
    s = *(u8 *)&fzgx_obj_lbl_8_bss_2C0;
}
#pragma section code_type ".text"
/* fzgx:end fn_8_BE4 */

/* fzgx:begin fn_8_EC4 */
typedef struct fn_8_EC4_TitleEntry {
    s32 image;
    u8 flags;
    u8 pad;
    u16 y;
} fn_8_EC4_TitleEntry;


struct fn_8_EC4_Bss58 {
    u8 unk0[0x15];
    s8 unk15;
};


/* title logo lines, two text images per step: -2 = none, -1 = end */
static const fn_8_EC4_TitleEntry fzgx_pool_fn_8_EC4_lines[4][2] = {
    { { -2, 0, 0, 0 }, { -2, 0, 0, 0 } },
    { { 0x8E00, 6, 0, 0x63 }, { 0x8E01, 6, 0, 0x100 } },
    { { 0x8E03, 10, 0, 0xF0 }, { -1, 0, 0, 0 } },
    { { -1, 0, 0, 0 }, { -1, 0, 0, 0 } },
};

extern u8 lbl_801A66BA;

extern void fn_8_784(u32);
extern void fn_80007AB4(TitleColor *);
extern s32 fn_1_4E724(FontDrawPacket *);
extern int fn_1_4C10(void);


void fn_8_EC4(void) {
    s32 step;
    u16 timer;
    s32 mode;
    FontDrawPacket packet;

    fn_1_52070(320);
    fn_80005E0C();
    fn_80005E0C();
    if (fzgx_pool_lbl_8_bss_0_gap_23E != 0) {
        fzgx_pool_lbl_8_bss_0_gap_23E--;
    }
    fn_1_A1360();
    {
        TitleColor color = { 0, 0, 0, 0 };
        fn_80007AB4(&color);
    }

    step = fzgx_pool_lbl_8_bss_0_gap_23E_fill_240;
    if (fzgx_pool_fn_8_EC4_lines[step][0].image != -2) {
        packet = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
        packet.x = 320.0f;
        packet.z = 3.0f;
        if (fzgx_pool_lbl_8_bss_0_gap_23E > 30) {
            packet.alpha = 1.0f;
        } else {
            packet.alpha = (f32)fzgx_pool_lbl_8_bss_0_gap_23E / 30.0f;
        }
        packet.image = fzgx_pool_fn_8_EC4_lines[step][0].image;
        packet.flags = fzgx_pool_fn_8_EC4_lines[step][0].flags;
        packet.y = fzgx_pool_fn_8_EC4_lines[step][0].y;
        fn_1_4E724(&packet);
        if (fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240][1].image != -1) {
            packet.image = fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240][1].image;
            packet.flags = fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240][1].flags;
            packet.y = fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240][1].y;
            fn_1_4E724(&packet);
        }
    }

    if (lbl_8_bss_238__fzgx_offset_9) {
        if (fn_1_4C10()) {
            fn_1_52088();
            return;
        }
        if (lbl_801A66BA) {
            lbl_1_bss_96A = 0x99;
            lbl_801A66BA = 0;
        } else {
            mode = (*(struct fn_8_EC4_Bss58 *)&lbl_1_bss_58).unk15;
            switch (mode) {
            case 1:
            case 3:
                lbl_1_bss_96A = 0xa4;
                break;
            case 0:
            case 2:
            default:
                lbl_1_bss_96A = 0x9c;
                break;
            }
            (*(struct fn_8_EC4_Bss58 *)&lbl_1_bss_58).unk15 = (mode + 1) & 3;
            if (lbl_1_bss_96A == 0x9c) {
                fn_1_3EF8C(6);
                fn_1_3ED8C(0, 3, 1, (u8)fzgx_obj_lbl_8_bss_224, 10, 30, 0);
                fn_1_3EB78(0, 0, 0, 0);
                fn_1_3EFF0((u32)fn_8_784, 1);
                fn_8006CE1C(1.0f);
                fn_1_3EF08(1);
            }
        }
        fn_1_52088();
        return;
    }

    timer = fzgx_pool_lbl_8_bss_0_gap_23E;
    if (timer > 30) {
        fn_1_52088();
        return;
    }
    step = fzgx_pool_lbl_8_bss_0_gap_23E_fill_240;
    if (fzgx_pool_fn_8_EC4_lines[step + 1][0].image == -1) {
        if (fn_1_4C10()) {
            fn_1_52088();
            return;
        }
        fn_1_4A00(0, 0xf, (void *)fzgx_obj_lbl_8_bss_238);
        lbl_8_bss_238__fzgx_offset_9 = 1;
        fn_1_52088();
        return;
    }
    packet = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
    packet.z = 2.0f;
    packet.x = 320.0f;
    packet.alpha = (f32)(30 - timer) / 30.0f;
    packet.image = fzgx_pool_fn_8_EC4_lines[step + 1][0].image;
    packet.flags = fzgx_pool_fn_8_EC4_lines[step + 1][0].flags;
    packet.y = fzgx_pool_fn_8_EC4_lines[step + 1][0].y;
    fn_1_4E724(&packet);
    if (fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240 + 1][1].image != -1) {
        packet.image = fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240 + 1][1].image;
        packet.flags = fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240 + 1][1].flags;
        packet.y = fzgx_pool_fn_8_EC4_lines[fzgx_pool_lbl_8_bss_0_gap_23E_fill_240 + 1][1].y;
        fn_1_4E724(&packet);
    }
    if (fzgx_pool_lbl_8_bss_0_gap_23E == 0) {
        fzgx_pool_lbl_8_bss_0_gap_23E = 0x118;
        fzgx_pool_lbl_8_bss_0_gap_23E_fill_240++;
    }
    fn_1_52088();
}

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    d = 4503599627370496.0;
    d = 4503601774854144.0;
    s = 60.0f;
    s = 180.0f;
    s = 10860.0f;
    s = 1020.0f;
}
static const u32 fzgx_pool_table4[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 500.0f;
    s = 400.0f;
    s = 0.07999999821186066f;
}
static const u32 fzgx_pool_table6[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 300.0f;
}
static const u32 fzgx_pool_table8[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = -1.0f;
    s = 8.0f;
    s = 0.5f;
    s = 4.0f;
    s = 190.0f;
    s = 0.07000000029802322f;
    s = 0.550000011920929f;
    s = 150.0f;
}
#pragma section code_type ".text"
/* fzgx:end fn_8_EC4 */

/* fzgx:begin fn_8_1304 */
extern u8 lbl_8_bss_238__fzgx_offset_9;
extern u8 lbl_8_bss_2;

void fn_8_1304(void) {
    u32 t1;
    lbl_8_bss_2 = 0;
    lbl_8_bss_238__fzgx_offset_9 = 0;
    fn_1_A8F78();
    t1 = fn_1_48140(142);
    fn_1_A1364(t1);
}
/* fzgx:end fn_8_1304 */

/* fzgx:begin fn_8_1344 */
struct fn_8_1344_lbl_8_bss_4 {
    f32 unk_0;
};
extern struct fn_8_1344_lbl_8_bss_4 lbl_8_bss_4;
extern u8 lbl_8_bss_238__fzgx_offset_A;


void fn_8_1344(void) {
    (*(u8 *)&lbl_8_bss_238__fzgx_offset_A) = 0;
    lbl_8_bss_4.unk_0 = 0.0f;
    fn_1_47F74(1);
    fn_1_47F74(3);
}
/* fzgx:end fn_8_1344 */

/* fzgx:begin fn_8_1394 */
struct fn_8_1394_Copy88 { u32 a[22]; };
struct fn_8_1394_lbl_8_bss_0 {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3[0x1];
    f32 unk_4;
    u8 pad_8[0x218];
    f32 unk_220;
    u8 pad_224[0x4];
    u32 unk_228;
    u8 pad_22C[0x16];
    u8 unk_242;
};
extern int fn_1_3F038(void);
extern int fn_1_4C10(void);
extern int fn_1_4F734(FontDrawPacket *);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);


extern u32 fn_1_47E54(u32);
extern u32 fn_1_5370(s8, u32);
extern u32 fn_8_0();




extern int fn_1_3FC38(void);
extern void fn_1_3EF14(void *);
extern void fn_1_3FC68(s32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */


u32 fn_8_1394(void) {
    f32 fn_8_1394_zero;
    u32 v1;
    f32 v3;
    f32 v4;
    f32 v5;
    f32 v6;
    f32 v8;
    u32 v9;
    f32 v10;
    f32 v11;
    f32 v14;
    u32 v15;
    u32 v16;
    f32 v18;
    f32 v19;
    f32 v20;
    f32 v21;
    f32 v22;
    f32 v24;
    u32 v25;
    u32 v26;
    f32 v28;
    f32 v29;
    f32 v30;
    f32 v31;
    f32 v33;
    u32 v34;
    f32 v35;
    f32 v36;
    u32 v40;
    u32 v41;
    s16 v50;
    s16 v49;
    s32 v51;
    f32 v52;
    f32 unk_4;
    f32 unk_1;
    struct { u32 a[1326]; } loc_270;
    FontDrawPacket loc_218;
    FontDrawPacket loc_1C0;
    FontDrawPacket loc_168;
    FontDrawPacket loc_110;
    FontDrawPacket loc_B8;
    struct fn_8_1394_Copy88 loc_60;
    struct fn_8_1394_Copy88 loc_8;
    /* frame */
    int t25;
    u32 t26;
    f32 t27;
    int t29;
    u32 t30;
    f32 t31;
    u32 t32;
    f32 t33;
    u16 t34;
    u16 t35;
    u16 t36;
    int t38;
    u32 t39;
    int t40;
    u32 t41;
    s32 t42;
    u32 t44;
    u32 v45;
    f32 v46;
    f32 v47;

    
    v1 = fzgx_obj_lbl_8_bss_228;
    lbl_8_bss_20__fzgx_offset_200 = 1.0f;
    if ((s32)v1 > 10980 && (s32)v1 <= 11040) {
    v3 = (f32)(s32)(11040 - v1);
    v4 = (v3 / 60.0f);
    fn_1_52070(320);
    loc_218 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v5 = 320.0f;
    v6 = 120.0f;
    loc_218.image = 768;
    loc_218.x = v5;
    loc_218.y = v6;
    loc_218.z = 2.0f;
    loc_218.flags = 6;
    loc_218.color[0] = 255;
    loc_218.color[1] = 255;
    loc_218.color[2] = 255;
    loc_218.alpha = v4;
    loc_218.flags = loc_218.flags | 0x4000000;
    loc_218.vertex_callback = (void (*)(const FontDrawPacket* packet, FontVertex* vertices))(fn_8_0);
    fn_1_4F734((FontDrawPacket *)&loc_218);
    v8 = (0.75f * v4);
    v9 = (loc_218.flags & 0xFBFFFFFF);
    loc_218.image = 770;
    loc_218.flags = v9;
    loc_218.alpha = v8;
    loc_218.z = 3.0f;
    fn_1_4F734((FontDrawPacket *)&loc_218);
    lbl_8_bss_20__fzgx_offset_200 = (1.0f - v4);
    fn_1_52088();
    }
    if ((s32)fzgx_obj_lbl_8_bss_228 > 10680 && (s32)fzgx_obj_lbl_8_bss_228 <= 10980) {
    fn_1_52070(320);
    loc_1C0 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v10 = 320.0f;
    v11 = 120.0f;
    loc_1C0.image = 768;
    loc_1C0.x = v10;
    loc_1C0.y = v11;
    loc_1C0.z = 2.0f;
    loc_1C0.flags = 6;
    loc_1C0.color[0] = 255;
    loc_1C0.color[1] = 255;
    loc_1C0.color[2] = 255;
    loc_1C0.alpha = 1.0f;
    loc_1C0.flags = loc_1C0.flags | 0x4000000;
    loc_1C0.vertex_callback = (void (*)(const FontDrawPacket* packet, FontVertex* vertices))(fn_8_0);
    fn_1_4F734((FontDrawPacket *)&loc_1C0);
    v14 = 0.75f;
    v15 = (loc_1C0.flags & 0xFBFFFFFF);
    loc_1C0.flags = v15;
    loc_1C0.image = 770;
    loc_1C0.alpha = v14;
    loc_1C0.z = 3.0f;
    fn_1_4F734((FontDrawPacket *)&loc_1C0);
    lbl_8_bss_20__fzgx_offset_200 = 0.0f;
    fn_1_52088();
    }
    v16 = fzgx_obj_lbl_8_bss_228;
    if ((s32)v16 > 10620 && (s32)v16 <= 10680) {
    v18 = 1.0f;
    v19 = (f32)(s32)(10680 - v16);
    v20 = (v18 - (v19 / 60.0f));
    fn_1_52070(320);
    loc_168 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v21 = 320.0f;
    v22 = 120.0f;
    loc_168.image = 768;
    loc_168.x = v21;
    loc_168.y = v22;
    loc_168.z = 2.0f;
    loc_168.flags = 6;
    loc_168.color[0] = 255;
    loc_168.color[1] = 255;
    loc_168.color[2] = 255;
    loc_168.alpha = v20;
    loc_168.flags = loc_168.flags | 0x4000000;
    loc_168.vertex_callback = (void (*)(const FontDrawPacket* packet, FontVertex* vertices))(fn_8_0);
    fn_1_4F734((FontDrawPacket *)&loc_168);
    v24 = (0.75f * v20);
    v25 = (loc_168.flags & 0xFBFFFFFF);
    loc_168.image = 770;
    loc_168.flags = v25;
    loc_168.alpha = v24;
    loc_168.z = 3.0f;
    fn_1_4F734((FontDrawPacket *)&loc_168);
    lbl_8_bss_20__fzgx_offset_200 = (1.0f - v20);
    fn_1_52088();
    }
    if ((s32)fn_1_3FC38() != 0 && (s32)fzgx_obj_lbl_8_bss_228 == 1200) {
    fn_1_5370(4, 0);
    fn_1_3FC68(0);
    }
    v26 = fzgx_obj_lbl_8_bss_228;
    if ((s32)v26 > 1020 && (s32)v26 <= 1200) {
    v28 = (f32)(s32)(1200 - v26);
    v29 = (v28 / 180.0f);
    fn_1_52070(320);
    loc_110 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v30 = 320.0f;
    v31 = 120.0f;
    loc_110.image = 768;
    loc_110.x = v30;
    loc_110.y = v31;
    loc_110.z = 2.0f;
    loc_110.flags = 6;
    loc_110.color[0] = 255;
    loc_110.color[1] = 255;
    loc_110.color[2] = 255;
    loc_110.alpha = v29;
    loc_110.flags = loc_110.flags | 0x4000000;
    loc_110.vertex_callback = (void (*)(const FontDrawPacket* packet, FontVertex* vertices))(fn_8_0);
    fn_1_4F734((FontDrawPacket *)&loc_110);
    v33 = (0.75f * v29);
    v34 = (loc_110.flags & 0xFBFFFFFF);
    loc_110.image = 770;
    loc_110.flags = v34;
    loc_110.alpha = v33;
    loc_110.z = 3.0f;
    fn_1_4F734((FontDrawPacket *)&loc_110);
    lbl_8_bss_20__fzgx_offset_200 = (1.0f - v29);
    fn_1_52088();
    }
    if ((s32)fzgx_obj_lbl_8_bss_228 <= 1020) {
    fn_1_52070(320);
    loc_B8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v35 = 320.0f;
    v36 = 120.0f;
    loc_B8.image = 768;
    loc_B8.x = v35;
    loc_B8.y = v36;
    loc_B8.z = 2.0f;
    loc_B8.flags = 6;
    loc_B8.color[0] = 255;
    loc_B8.color[1] = 255;
    loc_B8.color[2] = 255;
    loc_B8.alpha = 1.0f;
    loc_B8.flags = loc_B8.flags | 0x4000000;
    loc_B8.vertex_callback = (void (*)(const FontDrawPacket* packet, FontVertex* vertices))(fn_8_0);
    fn_1_4F734((FontDrawPacket *)&loc_B8);
    v40 = (loc_B8.flags & 0xFBFFFFFF);
    loc_B8.flags = v40;
    loc_B8.image = 770;
    loc_B8.alpha = 0.75f;
    loc_B8.z = 3.0f;
    fn_1_4F734((FontDrawPacket *)&loc_B8);
    lbl_8_bss_20__fzgx_offset_200 = 0.0f;
    fn_1_52088();
    }
    fn_1_3EF14((void *)&loc_270);
    v41 = fzgx_obj_lbl_8_bss_228;
    if (10860.0f <= (f32)(s32)v41) {
    fzgx_obj_lbl_8_bss_2 = 0;
    loc_270.a[0] = (loc_270.a[0] & 0xFFFFFFFB);
    } else {
    if (1020.0f <= (f32)(s32)v41 && (s32)v41 <= 1200) {
    fzgx_obj_lbl_8_bss_2 = 0;
    loc_270.a[0] = (loc_270.a[0] & 0xFFFFFFFB);
    } else {
    fzgx_obj_lbl_8_bss_2 = 1;
    loc_270.a[0] = (loc_270.a[0] | 4);
    }
    }
    if ((s32)v41 == 15 && (s32)fn_1_4C10() == 0) {
    fzgx_obj_lbl_8_bss_242 = 1;
    }
    if (fzgx_obj_lbl_8_bss_242 != 0) {
    t25 = fn_1_3F038();
    v45 = t25;
    if ((s32)v45 != 0) {
    if (fzgx_obj_lbl_8_bss_0 != 0) {
    fzgx_pool_lbl_8_bss_0_gap_1 = 1;
    fzgx_obj_lbl_8_bss_0 = 0;
    } else {
    (*(u16 *)&lbl_1_bss_96A) = 158;
    }
    }
    t26 = fn_1_52088();
    v45 = t26;
    } else {
    t27 = fn_1_52070(96);
    v46 = t27;
    loc_60 = *(struct fn_8_1394_Copy88 *)&lbl_1_rodata_26F8;
    v47 = 16.0f;
    v46 = 464.0f;
    loc_60.a[0] = 256;
    *(f32 *)((u8 *)&loc_60 + 4) = v47;
    *(f32 *)((u8 *)&loc_60 + 8) = v46;
    *(f32 *)((u8 *)&loc_60 + 12) = 0.01f;
    loc_60.a[12] = 13;
    fn_1_51678((FontDrawPacket *)&loc_60, 256, 0, 0, 250, 34);
    t29 = fn_1_4F734((FontDrawPacket *)&loc_60);
    v45 = t29;
    t30 = fn_1_52088();
    v45 = t30;
    t31 = fn_1_52070(544);
    v46 = t31;
    lbl_8_bss_20__fzgx_offset_200 = 1.0f;
    t32 = fn_1_52088();
    v45 = t32;
    t33 = fn_1_52070(320);
    v46 = t33;
    if (fzgx_obj_lbl_8_bss_2 != 0 && (lbl_801A66A0 & 0x18) != 0) {
    loc_8 = *(struct fn_8_1394_Copy88 *)&lbl_1_rodata_26F8;
    loc_8.a[0] = 258;
    v49 = (s16)((fn_1_486C4(loc_8.a[0]) >> 2) & 0x3FFF);
    v50 = (s16)fn_1_48690(loc_8.a[0]);
    v51 = (s16)(((fn_1_486C4(loc_8.a[0]) >> 2) & 0x3FFF) * 3);
    fn_1_51678((FontDrawPacket *)&loc_8, loc_8.a[0], 0, (s16)v51, v50, v49);
    v52 = 320.0f;
    v46 = 362.0f;
    *(f32 *)((u8 *)&loc_8 + 4) = v52;
    *(f32 *)((u8 *)&loc_8 + 8) = v46;
    *(f32 *)((u8 *)&loc_8 + 12) = 1.0f;
    loc_8.a[12] = 6;
    t38 = fn_1_4F734((FontDrawPacket *)&loc_8);
    v45 = t38;
    }
    t39 = fn_1_52088();
    v45 = t39;
    t40 = fn_1_3F038();
    v45 = t40;
    if ((s32)v45 != 0) {
    if (fzgx_obj_lbl_8_bss_0 != 0) {
    fzgx_pool_lbl_8_bss_0_gap_1 = 1;
    fzgx_obj_lbl_8_bss_0 = 0;
    } else {
    (*(u16 *)&lbl_1_bss_96A) = 155;
    }
    }
    t41 = fn_1_52088();
    v45 = t41;
    unk_4 = fzgx_obj_lbl_8_bss_4;
    if ((fn_8_1394_zero = 0.0f, unk_4 == fn_8_1394_zero)) {
    t42 = fn_1_465D0((char *)lbl_8_data_478, 1);
    v45 = t42;
    fn_1_41104(1);
    fn_1_47E54(154);
    fn_1_47E54(155);
    fn_1_47E54(157);
    fn_1_47E54(161);
    v45 = fn_1_47E54(156);
    v45 = fn_1_47E54(162);
    fzgx_obj_lbl_8_bss_4 = 1.0f;
    }
    }
    return v45;
}
/* fzgx:end fn_8_1394 */

/* fzgx:begin fn_8_1C08 */
// fn_8_1C08: empty in retail (single blr).
void fn_8_1C08(void) {
}
/* fzgx:end fn_8_1C08 */

/* fzgx:begin fn_8_1C0C */
// fn_8_1C0C: empty in retail (single blr).
void fn_8_1C0C(void) {
}
/* fzgx:end fn_8_1C0C */

/* fzgx:begin fn_8_1C10 */
// fn_8_1C10: empty in retail (single blr).
void fn_8_1C10(void) {
}
/* fzgx:end fn_8_1C10 */

/* fzgx:begin fn_8_1C14 */
// fn_8_1C14: empty in retail (single blr).
void fn_8_1C14(void) {
}
/* fzgx:end fn_8_1C14 */

/* fzgx:begin fn_8_1C18 */
struct fn_8_1C18_lbl_8_bss_0 {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 pad_3[0x221];
    s16 unk_224;
    u8 pad_226[0x12];
    u32 unk_238;
};




extern u32 fn_1_4706C(void);



void fn_8_1C18(void) {
    struct fn_8_1C18_lbl_8_bss_0 *p_lbl_8_bss_0;
    p_lbl_8_bss_0 = (struct fn_8_1C18_lbl_8_bss_0 *)&(*(struct fn_8_1C18_lbl_8_bss_0 *)&lbl_8_bss_0);
    fn_8006CE1C((0.0f));
    fn_1_4A00(1, 15, (void *)p_lbl_8_bss_0->unk_238);
    lbl_1_bss_970 = 600;
    fn_1_4706C();
    fn_1_7B084((void *)p_lbl_8_bss_0->unk_224, 0);
    fn_1_9A958(p_lbl_8_bss_0->unk_224, 0);
    p_lbl_8_bss_0->unk_2 = 1;
}
/* fzgx:end fn_8_1C18 */

/* fzgx:begin fn_8_1C90 */
struct fn_8_1C90_Copy88 { u32 a[22]; };
struct fn_8_1C90_lbl_8_rodata_0 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0xC];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
};
struct fn_8_1C90_lbl_8_bss_0 {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 pad_3[0x21D];
    f32 unk_220;
    u8 pad_224[0x14];
    u32 unk_238;
};
struct fn_8_1C90_lbl_1_bss_970 {
    s32 unk_0;
};

extern int fn_1_4C10(void);
extern int fn_1_4F734(FontDrawPacket *);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern u32 fn_8_0();
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);

void fn_8_1C90(void) {
    struct fn_8_1C90_lbl_8_bss_0 *p_lbl_8_bss_0;
    struct fn_8_1C90_lbl_8_rodata_0 *p_lbl_8_rodata_0;
    struct fn_8_1C90_lbl_1_bss_970 *p_bss_970;
    f32 v1;
    f32 v0;
    s16 v3;
    s16 v2;
    f32 v5;
    f32 v4;
    f32 v7;
    f32 v6;
    f32 v8;
    u32 v9;
    f32 v10;
    u16 t7;
    u16 t8;
    u16 t9;
    u32 v11;
    s32 v12;
    s32 v13;
    FontDrawPacket loc_B8;
    FontDrawPacket loc_60;
    FontDrawPacket loc_8;
    p_lbl_8_bss_0 = (struct fn_8_1C90_lbl_8_bss_0 *)&lbl_8_bss_0;
    p_lbl_8_rodata_0 = (struct fn_8_1C90_lbl_8_rodata_0 *)&lbl_8_rodata_0;
    fn_1_52070(96);
    loc_B8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v0 = p_lbl_8_rodata_0->unk_2C;
    v1 = p_lbl_8_rodata_0->unk_30;
    loc_B8.image = 256;
    loc_B8.x = v0;
    loc_B8.y = v1;
    loc_B8.z = p_lbl_8_rodata_0->unk_34;
    loc_B8.flags = 13;
    fn_1_51678((FontDrawPacket *)&loc_B8, 256, 0, 0, 250, 34);
    fn_1_4F734((FontDrawPacket *)&loc_B8);
    fn_1_52088();
    fn_1_52070(544);
    p_lbl_8_bss_0->unk_220 = p_lbl_8_rodata_0->unk_8;
    fn_1_52088();
    fn_1_52070(320);
    if (p_lbl_8_bss_0->unk_2 != 0 && (lbl_801A66A0 & 0x18) != 0) {
        loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
        loc_8.image = 258;
        v2 = (s16)((fn_1_486C4((u32)loc_8.image) >> 2) & 0x3FFF);
        v3 = (s16)fn_1_48690((u32)loc_8.image);
        fn_1_51678((FontDrawPacket *)&loc_8, (u32)loc_8.image, 0,
                   (s16)(((fn_1_486C4((u32)loc_8.image) >> 2) & 0x3FFF) * 3),
                   v3, v2);
        loc_8.x = p_lbl_8_rodata_0->unk_0;
        loc_8.y = p_lbl_8_rodata_0->unk_4;
        loc_8.z = p_lbl_8_rodata_0->unk_8;
        loc_8.flags = 6;
        fn_1_4F734((FontDrawPacket *)&loc_8);
    }
    fn_1_52088();
    fn_1_52070(320);
    loc_60 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v6 = p_lbl_8_rodata_0->unk_0;
    v7 = p_lbl_8_rodata_0->unk_1C;
    v8 = p_lbl_8_rodata_0->unk_20;
    loc_60.image = 768;
    loc_60.flags = 6;
    loc_60.x = p_lbl_8_rodata_0->unk_0;
    loc_60.y = p_lbl_8_rodata_0->unk_1C;
    loc_60.z = p_lbl_8_rodata_0->unk_20;
    loc_60.color[0] = 255;
    loc_60.color[1] = 255;
    loc_60.color[2] = 255;
    loc_60.alpha = p_lbl_8_rodata_0->unk_8;
    loc_60.flags |= 0x4000000;
    loc_60.vertex_callback = (void (*)(const FontDrawPacket* packet, FontVertex* vertices))(fn_8_0);
    fn_1_4F734((FontDrawPacket *)&loc_60);
    v10 = p_lbl_8_rodata_0->unk_24;
    v11 = (loc_60.flags & 0xFBFFFFFF);
    loc_60.flags = v11;
    loc_60.image = 770;
    loc_60.alpha = v10;
    loc_60.z = p_lbl_8_rodata_0->unk_28;
    fn_1_4F734((FontDrawPacket *)&loc_60);
    p_lbl_8_bss_0->unk_220 = p_lbl_8_rodata_0->unk_C;
    fn_1_52088();
    p_bss_970 = (struct fn_8_1C90_lbl_1_bss_970 *)&lbl_1_bss_970;
    if (p_bss_970->unk_0 != 0) {
        v13 = --p_bss_970->unk_0;
        if (v13 == 15 && fn_1_4C10() == 0) {
            fn_1_4A00(0, 15, (void *)p_lbl_8_bss_0->unk_238);
        }
    } else {
        if (fn_1_4C10() == 0) {
            (*(u16 *)&lbl_1_bss_96A) = 158;
        }
    }
}
/* fzgx:end fn_8_1C90 */

/* fzgx:begin fn_8_1F64 */
extern u8 lbl_8_bss_2;

void fn_8_1F64(void) {
    lbl_8_bss_2 = 0;
}
/* fzgx:end fn_8_1F64 */

/* fzgx:begin fn_8_1F74 */
extern u32 fn_1_A5EFC(void);
extern u8 lbl_801A66B8;

void fn_8_1F74(void) {
    fn_8006CE1C(lbl_8_rodata_C);
    if (lbl_801A66B8 == 0) {
    fn_1_A5EFC();
    }
}
/* fzgx:end fn_8_1F74 */

/* fzgx:begin fn_8_1FB0 */
extern void fn_8_784(u32);

extern u8 lbl_801A66B8;
extern u8 lbl_801A66B9;

struct fn_8_1FB0_lbl_1_bss_58 {
    u8 pad_0[0x15];
    s8 unk_15;
};

struct fn_8_1FB0_lbl_8_bss_224 {
    s16 unk_0;
};
extern struct fn_8_1FB0_lbl_8_bss_224 lbl_8_bss_224;

struct fn_8_1FB0_lbl_8_bss_238 {
    u32 unk_0;
};

f32 fn_8_1FB0(f32 arg0) {
    s32 v2;

    if (lbl_801A66B8 != 0 || fn_1_A66FC((*(struct fn_8_1FB0_lbl_8_bss_238 *)&lbl_8_bss_238).unk_0) != 0) {
        if (lbl_1_bss_7180C == 0) {
            if (lbl_801A66B9 == 0) {
                fn_1_4FEC();
                fn_1_C3378();
                fn_1_F7A20();
                lbl_801A66B9 = 1;
            }
            v2 = (*(struct fn_8_1FB0_lbl_1_bss_58 *)&lbl_1_bss_58).unk_15;
            switch (v2) {
            case 1:
            case 3:
                lbl_1_bss_96A = 0xa4;
                break;
            case 0:
            case 2:
            default:
                lbl_1_bss_96A = 0x9c;
                break;
            }
            (*(struct fn_8_1FB0_lbl_1_bss_58 *)&lbl_1_bss_58).unk_15 = (v2 + 1) & 3;
            if (lbl_1_bss_96A == 0x9c) {
                fn_1_3EF8C(6);
                fn_1_3ED8C(0, 3, 1, lbl_8_bss_224.unk_0 & 0xff, 10, 30, 0);
                fn_1_3EB78(0, 0, 0, 0);
                fn_1_3EFF0((u32)fn_8_784, 1);
                fn_8006CE1C(lbl_8_rodata_8);
                fn_1_3EF08(1);
            }
        } else {
            lbl_1_bss_96A = 0x9a;
        }
        lbl_801A66B8 = 1;
    }
}
/* fzgx:end fn_8_1FB0 */

/* fzgx:begin fn_8_2120 */
// fn_8_2120: empty in retail (single blr).
void fn_8_2120(void) {
}
/* fzgx:end fn_8_2120 */

/* fzgx:begin fn_8_2124 */
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4D494(void);
extern void fn_1_4AE0C(const char *, ...);

void fn_8_2124(u32 arg0, u8 *arg1, f32 arg2) {
    TitleColor blend;
    f32 scale;

    *(u32 *)&blend = fn_800081C8((TitleColor){ 0xA0, 0x50, 0x50, 0x00 }, (TitleColor){ 0xA0, 0xA0, 0xA0, 0x00 }, 1.0f);
    fn_1_49410();
    scale = 0.75f;
    fn_1_4955C(scale, scale);
    fn_1_4954C(arg2);
    fn_1_495C8(9);
    if (5 != lbl_801A66B4) {
        fn_1_49590(0.5f);
        fn_1_495B0(0x80000000);
        fn_1_4966C(0.0f, 4.0f);
    }
    fn_1_496FC(288.0f, (f32)(s32)arg0);
    fn_1_495C8(10);
    if (*arg1 == 0) {
        fn_1_4D494();
        fn_1_49514((TitleColor){ 0xFF, 0xFF, 0xFF, 0x00 });
        fn_1_4AE0C("%s", lbl_8_data_62D0.text[TITLE_TEXT_YES][lbl_801A66B4]);
        fn_1_4D4C8(blend, arg2, 10.0f);
    } else {
        fn_1_49514((TitleColor){ 0x70, 0x70, 0x70, 0x00 });
        fn_1_49528((TitleColor){ 0x00, 0x00, 0x00, 0x00 });
        fn_1_4AE0C("%s", lbl_8_data_62D0.text[TITLE_TEXT_YES][lbl_801A66B4]);
    }
    fn_1_496FC(352.0f, (f32)(s32)arg0);
    fn_1_495C8(8);
    if (*arg1 == 0) {
        fn_1_49514((TitleColor){ 0x70, 0x70, 0x70, 0x00 });
        fn_1_49528((TitleColor){ 0x00, 0x00, 0x00, 0x00 });
        fn_1_4AE0C("%s", lbl_8_data_62D0.text[TITLE_TEXT_NO][lbl_801A66B4]);
    } else {
        fn_1_4D494();
        fn_1_49514((TitleColor){ 0xFF, 0xFF, 0xFF, 0x00 });
        fn_1_4AE0C("%s", lbl_8_data_62D0.text[TITLE_TEXT_NO][lbl_801A66B4]);
        fn_1_4D4C8(blend, arg2, 10.0f);
    }
}
/* fzgx:end fn_8_2124 */

/* fzgx:begin fn_8_23AC */
extern void fn_1_49410(void);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D494(void);

void fn_8_23AC(void *arg0, f32 arg1) {
    TitleColor blend;
    f32 scale;

    *(u32 *)&blend = fn_800081C8((TitleColor){ 0xA0, 0x50, 0x50, 0x00 }, (TitleColor){ 0xA0, 0xA0, 0xA0, 0x00 }, 1.0f);
    fn_1_49410();
    scale = 0.75f;
    fn_1_4955C(scale, scale);
    fn_1_4954C(arg1);
    fn_1_495C8(9);
    if (lbl_801A66B4 != 5) {
        fn_1_49590(0.5f);
        fn_1_495B0(0x80000000);
        fn_1_4966C(0.0f, 4.0f);
    }
    fn_1_496FC(288.0f, 320.0f);
    fn_1_495C8(10);
    if (*(u8 *)arg0 == 0) {
        fn_1_4D494();
        fn_1_49514((TitleColor){ 0xFF, 0xFF, 0xFF, 0x00 });
        fn_1_4AE0C("%s", lbl_8_data_62D0.text[TITLE_TEXT_YES][lbl_801A66B4]);
        fn_1_4D4C8(blend, arg1, 10.0f);
    } else {
        fn_1_49514((TitleColor){ 0x70, 0x70, 0x70, 0x00 });
        fn_1_49528((TitleColor){ 0x00, 0x00, 0x00, 0x00 });
        fn_1_4AE0C("%s", lbl_8_data_62D0.text[TITLE_TEXT_YES][lbl_801A66B4]);
    }
    fn_1_496FC(352.0f, 320.0f);
    fn_1_495C8(8);
    if (*(u8 *)arg0 == 0) {
        fn_1_49514((TitleColor){ 0x70, 0x70, 0x70, 0x00 });
        fn_1_49528((TitleColor){ 0x00, 0x00, 0x00, 0x00 });
        fn_1_4AE0C("%s", lbl_8_data_62D0.text[TITLE_TEXT_NO][lbl_801A66B4]);
    } else {
        fn_1_4D494();
        fn_1_49514((TitleColor){ 0xFF, 0xFF, 0xFF, 0x00 });
        fn_1_4AE0C("%s", lbl_8_data_62D0.text[TITLE_TEXT_NO][lbl_801A66B4]);
        fn_1_4D4C8(blend, arg1, 10.0f);
    }
}
/* fzgx:end fn_8_23AC */

/* fzgx:begin fn_8_25F8 */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_tail13C[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_tail13C; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 280.0f;
    s = 210.0f;
    s = 0.020000003278255463f;
    s = 220.0f;
    s = 0.030000001192092896f;
    s = 40.0f;
    s = 345.0f;
    s = 260.0f;
}
#pragma section code_type ".text"

struct fn_8_25F8_lbl_8_bss_0 {
    u8 pad_0[0x244];
    u32 unk_244;
    u8 unk_248;
    u8 pad_249[0x3];
    u32 unk_24C;
};


extern u8 lbl_801A66B9;

void fn_8_25F8(void) {
    struct fn_8_25F8_lbl_8_bss_0 *p_lbl_8_bss_0;
    p_lbl_8_bss_0 = (struct fn_8_25F8_lbl_8_bss_0 *)&(*(struct fn_8_25F8_lbl_8_bss_0 *)&lbl_8_bss_0);
    if (lbl_801A66B9 == 0) {
    fn_1_4FEC();
    fn_1_C3378();
    fn_1_F7A20();
    lbl_801A66B9 = 1;
    }
    p_lbl_8_bss_0->unk_244 = 0;
    p_lbl_8_bss_0->unk_248 = 255;
    p_lbl_8_bss_0->unk_24C = 0;
}
/* fzgx:end fn_8_25F8 */

/* fzgx:begin fn_8_2660 */
typedef signed char fn_8_2660_s8;
typedef signed short fn_8_2660_s16;
typedef signed long fn_8_2660_s32;

typedef unsigned char fn_8_2660_u8;
typedef unsigned short fn_8_2660_u16;
typedef unsigned long fn_8_2660_u32;

typedef float fn_8_2660_f32;
typedef double fn_8_2660_f64;


/* title state machine, base lbl_8_bss_0 */
struct fn_8_2660_TitleState {
fn_8_2660_u8 pad_0[0x224];
fn_8_2660_s16 unk_224;
fn_8_2660_u8 pad_226[0xE];
fn_8_2660_u32 unk_234;
fn_8_2660_u32 unk_238;
fn_8_2660_u8 pad_23C[0x8];
fn_8_2660_s32 unk_244;
fn_8_2660_u8 unk_248;
fn_8_2660_u8 pad_249[0x3];
fn_8_2660_u32 unk_24C;
fn_8_2660_u8 unk_250;
fn_8_2660_u8 pad_251;
fn_8_2660_u8 unk_252;
fn_8_2660_u8 pad_253;
fn_8_2660_s32 unk_254;
fn_8_2660_s32 unk_258;
fn_8_2660_s32 unk_25C;
fn_8_2660_u8 unk_260;
fn_8_2660_u8 pad_261[0x3];
fn_8_2660_s32 unk_264;
fn_8_2660_u8 unk_268[0x100];
};
/* resource/format tables, base lbl_8_data_0 */
struct fn_8_2660_TitleData {
fn_8_2660_u8 pad_0[0x6E30];
void *unk_6E30[8];
fn_8_2660_u8 pad_6E50[0x6EC4 - 0x6E50];
void *unk_6EC4[8];
fn_8_2660_u8 pad_6EE4[0x6F24 - 0x6EE4];
void *unk_6F24[8];
fn_8_2660_u8 pad_6F44[0x7200 - 0x6F44];
void *unk_7200[8];
fn_8_2660_u8 pad_7220[0x7270 - 0x7220];
void *unk_7270[8];
fn_8_2660_u8 pad_7290[0x7318 - 0x7290];
void *unk_7318[8];
fn_8_2660_u8 pad_7338[0x7398 - 0x7338];
void *unk_7398[8];
fn_8_2660_u8 pad_73B8[0x7438 - 0x73B8];
void *unk_7438[8];
fn_8_2660_u8 pad_7458[0x747C - 0x7458];
void *unk_747C[8];
fn_8_2660_u8 pad_749C[0x750C - 0x749C];
void *unk_750C[8];
fn_8_2660_u8 pad_752C[0x759C - 0x752C];
void *unk_759C[8];
fn_8_2660_u8 pad_75BC[0x76A0 - 0x75BC];
void *unk_76A0[8];
fn_8_2660_u8 pad_76C0[0x77A0 - 0x76C0];
void *unk_77A0[8];
fn_8_2660_u8 pad_77C0[0x7900 - 0x77C0];
void *unk_7900[8];
fn_8_2660_u8 pad_7920[0x7980 - 0x7920];
void *unk_7980[8];
fn_8_2660_u8 pad_79A0[0x7A18 - 0x79A0];
void *unk_7A18[8];
fn_8_2660_u8 pad_7A38[0x7AB0 - 0x7A38];
void *unk_7AB0[8];
fn_8_2660_u8 pad_7AD0[0x7B28 - 0x7AD0];
void *unk_7B28[8];
fn_8_2660_u8 pad_7B48[0x7B78 - 0x7B48];
void *unk_7B78[8];
fn_8_2660_u8 pad_7B98[0x7BFC - 0x7B98];
void *unk_7BFC[7];
char str_7C18[0x10];
char str_7C28[0xC];
};
/* shared literal pool */
struct fn_8_2660_TitleRodata {
fn_8_2660_f32 unk_0;
fn_8_2660_u8 pad_4[4];
fn_8_2660_f32 unk_8;
fn_8_2660_f32 unk_C;
fn_8_2660_u8 pad_10[0x14];
fn_8_2660_f32 unk_24;
fn_8_2660_u8 pad_28[0x18];
fn_8_2660_f32 unk_40;
fn_8_2660_u8 pad_44[0x48];
fn_8_2660_f32 unk_8C;
fn_8_2660_u8 pad_90[8];
fn_8_2660_f64 unk_98;
fn_8_2660_u8 pad_A0[0x10];
fn_8_2660_u32 unk_B0;
fn_8_2660_f32 unk_B4;
fn_8_2660_f32 unk_B8;
fn_8_2660_f32 unk_BC;
fn_8_2660_u32 unk_C0;
fn_8_2660_f32 unk_C4;
fn_8_2660_u32 unk_C8;
fn_8_2660_f32 unk_CC;
fn_8_2660_f32 unk_D0;
fn_8_2660_f32 unk_D4;
fn_8_2660_f32 unk_D8;
fn_8_2660_f32 unk_DC;
fn_8_2660_f32 unk_E0;
fn_8_2660_f32 unk_E4;
fn_8_2660_f32 unk_E8;
fn_8_2660_f32 unk_EC;
fn_8_2660_u8 pad_F0[0x24];
fn_8_2660_f32 unk_114;
fn_8_2660_u8 pad_118[0x24];
fn_8_2660_u32 unk_13C;
fn_8_2660_f32 unk_140;
fn_8_2660_f32 unk_144;
fn_8_2660_f32 unk_148;
fn_8_2660_f32 unk_14C;
fn_8_2660_f32 unk_150;
fn_8_2660_f32 unk_154;
fn_8_2660_f32 unk_158;
fn_8_2660_f32 unk_15C;
};
struct TitleInput {
fn_8_2660_u8 pad_0[0x8];
fn_8_2660_u16 unk_8;
fn_8_2660_u8 pad_A[0x6];
fn_8_2660_u16 unk_10;
fn_8_2660_u16 unk_12;
};
struct TitleTrans {
fn_8_2660_u8 unk0;
fn_8_2660_u8 pad1[3];
fn_8_2660_u32 unk4;
fn_8_2660_u32 unk8;
fn_8_2660_u32 unkC;
fn_8_2660_u8 pad10[0x14];
};
struct Title8B3A0 {
fn_8_2660_u8 pad_0[0x9E];
fn_8_2660_u8 unk_9E;
};
struct Title858 {
fn_8_2660_u8 pad_0[0x15];
fn_8_2660_s8 unk_15;
};










extern fn_8_2660_u8 lbl_1_bss_718E0;
extern fn_8_2660_u32 *lbl_1_bss_718C0;
extern fn_8_2660_u8 lbl_1_bss_7AC40;




extern void fn_1_54278(fn_8_2660_s32, fn_8_2660_s32);
extern void fn_1_5428C(fn_8_2660_f32);
extern void *memset(void *, int, fn_8_2660_u32);
extern fn_8_2660_s32 fn_1_B800C(fn_8_2660_s32);
extern void fn_1_B80F0(fn_8_2660_s32);
extern fn_8_2660_u8 fn_1_B7C00(void);
extern fn_8_2660_u32 fn_1_AA6D8(fn_8_2660_u32, fn_8_2660_u32, void *);
extern fn_8_2660_s32 fn_1_B7C5C(void);
extern void fn_1_5104(void);
extern fn_8_2660_u32 fn_1_B7CE4(fn_8_2660_u32, void *);
extern fn_8_2660_s32 fn_1_509C(void);
extern fn_8_2660_s32 fn_1_B7EC4(fn_8_2660_s32);
extern void fn_1_B8338(fn_8_2660_s32);
extern void fn_1_B8E84(fn_8_2660_u32, void *, void *, void *);
extern fn_8_2660_s32 fn_1_B7E98(fn_8_2660_s32);
extern void fn_1_53BD8(void *, fn_8_2660_f32, fn_8_2660_f32, fn_8_2660_f32, fn_8_2660_f32, fn_8_2660_f32);
extern void fn_1_A2D84(fn_8_2660_u32);
extern void fn_1_49410(void);
extern void fn_1_4AEC0(fn_8_2660_u32);
extern void fn_1_4AEB4(fn_8_2660_f32);
extern void fn_1_4966C(fn_8_2660_f32, fn_8_2660_f32);
extern void fn_1_49590(fn_8_2660_f32);
extern void fn_1_495B0(fn_8_2660_u32);
extern void fn_1_53C9C(void *, void *, fn_8_2660_f32, fn_8_2660_f32, fn_8_2660_f32, fn_8_2660_f32, fn_8_2660_f32);
extern void fn_1_4955C(fn_8_2660_f32, fn_8_2660_f32);
extern void fn_1_4954C(fn_8_2660_f32);
extern void fn_1_496FC(fn_8_2660_f32, fn_8_2660_f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_C34F0(void);
extern int sprintf(char *, const char *, ...);
extern void fn_1_4FD64(void);
extern void fn_1_4D0A0(void);
extern void fn_1_4D2AC(void *, fn_8_2660_f32, fn_8_2660_f32);
extern void OSReport(const char *, ...);
extern void fn_80083DB0(fn_8_2660_u32, fn_8_2660_u32);
extern fn_8_2660_s32 fn_1_F7954(void);
extern char *strcat(char *, const char *);
extern void fn_1_B7E14(void *);
extern fn_8_2660_u32 fn_1_C3688(void);
extern fn_8_2660_s32 fn_1_B88C4(void);
extern fn_8_2660_s32 fn_1_B8EDC(fn_8_2660_u32);
extern void fn_8_23AC(void *, fn_8_2660_f32);
extern fn_8_2660_u32 fn_8_F9E4(void *, void *, fn_8_2660_u32);
extern void fn_8_FF9C(void);
extern fn_8_2660_s32 fn_8_FC5C(void);
extern void fn_8_10084(fn_8_2660_u32);
extern void fn_8_100B4(void);
extern void *fn_8_5840(void *);
extern void fn_8_784(fn_8_2660_u32);
void fn_8_2660(fn_8_2660_f32 arg0, fn_8_2660_f32 arg1, fn_8_2660_f32 arg2) {

struct TitleInput *p_lbl_1_bss_9F8;
fn_8_2660_u32 loc_60, loc_5C, loc_58, loc_54, loc_50, loc_4C, loc_48, loc_44, loc_40, loc_3C;
fn_8_2660_u32 loc_38, loc_34, loc_30, loc_2C, loc_28, loc_24, loc_20, loc_1C, loc_18, loc_14;
fn_8_2660_u32 loc_10, loc_C, loc_8;
fn_8_2660_u32 buf84[8];
fn_8_2660_u32 buf64[8];
struct TitleTrans args;
fn_8_2660_u32 bufC8[256];
void **title_formats;
void **title_names;
void **p_data_tbl;
fn_8_2660_s32 *p_idx;
void *item;
fn_8_2660_u32 cnt;
fn_8_2660_s32 ret;
fn_8_2660_u16 vHalf;
fn_8_2660_s32 vByte;
fn_8_2660_f32 fTmp;
fn_8_2660_u8 *src;
fn_8_2660_u8 *dst;
fn_8_2660_u8 *cp;



lbl_8_bss_242__fzgx_offset_2 = lbl_8_bss_242__fzgx_offset_2 + 1;
if (lbl_8_bss_242__fzgx_offset_E != lbl_8_bss_242__fzgx_offset_6) {
lbl_8_bss_242__fzgx_offset_6 = lbl_8_bss_242__fzgx_offset_E;
lbl_8_bss_242__fzgx_offset_2 = 0;
}
if (lbl_8_bss_242__fzgx_offset_2 < 10) {
fn_8_2660_f32 f = (fn_8_2660_f32)lbl_8_bss_242__fzgx_offset_2 / (10.0f);
fn_1_54278((fn_8_2660_s32)((320.0f) * ((1.0f) - f) * ((1.0f) - f)), 0);
fn_1_5428C(f * f);
} else {
fn_1_54278(0, 0);
fn_1_5428C((1.0f));
}
memset(&args, 0, 36);
switch (lbl_8_bss_242__fzgx_offset_E) {
case 0:
lbl_8_bss_242__fzgx_offset_10 = 0;
lbl_8_bss_242__fzgx_offset_12 = 0;
lbl_8_bss_242__fzgx_offset_16 = 0;
lbl_8_bss_242__fzgx_offset_E = 1;
lbl_8_bss_242__fzgx_offset_A = lbl_8_bss_242__fzgx_offset_A + 1;
break;
case 1:
lbl_8_bss_242__fzgx_offset_1A = fn_1_B800C(0);
fn_1_B80F0(0);
if (lbl_8_bss_242__fzgx_offset_1A == -6 || lbl_8_bss_242__fzgx_offset_1A == -13) {
if (lbl_8_bss_242__fzgx_offset_A >= 2) {
lbl_8_bss_242__fzgx_offset_E = 33;
} else {
lbl_8_bss_242__fzgx_offset_E = 15;
}
} else if (lbl_8_bss_242__fzgx_offset_1A == 0 || lbl_8_bss_242__fzgx_offset_1A == -3) {
lbl_8_bss_242__fzgx_offset_E = 4;
} else if (lbl_8_bss_242__fzgx_offset_1A == -2) {
lbl_8_bss_242__fzgx_offset_E = 35;
} else {
lbl_8_bss_242__fzgx_offset_E = 33;
}
break;
case 4:
lbl_8_bss_242__fzgx_offset_E = 5;
break;
case 2:
if (fn_1_B7C00() == 0) {
args.unk0 = 0;
args.unk4 = 0x104;
args.unkC = (fn_8_2660_u32)&lbl_1_bss_7AC40;
fn_1_AA6D8(2, 0, &args);
lbl_8_bss_242__fzgx_offset_E = 3;
}
break;
case 3:
if (fn_1_B7C00() == 0) {
ret = fn_1_B7C5C();
lbl_8_bss_242__fzgx_offset_1A = ret;
if (ret == 0) {
fn_1_5104();
lbl_8_bss_242__fzgx_offset_E = 5;
} else if (ret == -4 || ret == -121 || ret == -122) {
args.unk0 = 0;
fn_1_B7CE4(0, buf84);
args.unk8 = (fn_8_2660_u32)buf84;
fn_1_509C();
args.unkC = (fn_8_2660_u32)&lbl_1_bss_7AC40;
args.unk4 = 0x14000;
fn_1_AA6D8(0, 0, &args);
} else {
lbl_8_bss_242__fzgx_offset_E = 5;
}
}
break;
case 5:
if (fn_1_B7EC4(0) == 0) {
lbl_8_bss_242__fzgx_offset_E = 8;
} else if (fn_1_B7EC4(0) != 0) {
fn_1_B8338(0);
fn_1_B8E84(1, &lbl_8_bss_242__fzgx_offset_10, &lbl_8_bss_242__fzgx_offset_12, &lbl_8_bss_242__fzgx_offset_16);
if (lbl_8_bss_242__fzgx_offset_10 != 0) {
lbl_8_bss_242__fzgx_offset_E = 15;
} else if (lbl_8_bss_242__fzgx_offset_12 >= 4 && lbl_8_bss_242__fzgx_offset_16 > 0) {
lbl_8_bss_242__fzgx_offset_E = 19;
} else {
lbl_8_bss_242__fzgx_offset_E = 21;
}
}
break;
case 33:
lbl_8_bss_242__fzgx_offset_1E = 1;
lbl_8_bss_242__fzgx_offset_A = 0;
lbl_8_bss_242__fzgx_offset_E = 0x22;
break;
case 34:
if (fn_1_B7C00() != 0) {
break;
}
if (fn_1_B7E98(0) == 0) {
lbl_8_bss_242__fzgx_offset_E = 11;
break;
}
do { loc_5C = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_5C, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
if (lbl_8_bss_242__fzgx_offset_1A == -13 || lbl_8_bss_242__fzgx_offset_1A == -6) {
do { p_data_tbl = (void **)lbl_8_data_7270; p_idx = &(*(fn_8_2660_s32 *)&lbl_801A66B4); item = (*((p_data_tbl) + (*p_idx))); loc_58 = (*((fzgx_pool_table8) + (0))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); p_data_tbl = (void **)lbl_8_data_7200; p_idx = &(*(fn_8_2660_s32 *)&lbl_801A66B4); if (item == (*((p_data_tbl) + (*p_idx)))) { fn_1_53C9C((void *)&loc_58, item, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f)); } else { fn_1_53C9C((void *)&loc_58, item, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f)); } do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
} else {
do { p_data_tbl = (void **)lbl_8_data_7318; p_idx = &(*(fn_8_2660_s32 *)&lbl_801A66B4); item = (*((p_data_tbl) + (*p_idx))); loc_54 = (*((fzgx_pool_table8) + (0))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); p_data_tbl = (void **)lbl_8_data_7200; p_idx = &(*(fn_8_2660_s32 *)&lbl_801A66B4); if (item == (*((p_data_tbl) + (*p_idx)))) { fn_1_53C9C((void *)&loc_54, item, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f)); } else { fn_1_53C9C((void *)&loc_54, item, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f)); } do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
}
do { p_data_tbl = (void **)lbl_8_data_750C; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (240.0f)); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
fn_8_23AC(&lbl_8_bss_242__fzgx_offset_1E, (0.0700000003f));
do { p_lbl_1_bss_9F8 = (struct TitleInput *)&(*(struct TitleInput *)&lbl_1_bss_9F8); if ((p_lbl_1_bss_9F8->unk_10 & 1) != 0 || (p_lbl_1_bss_9F8->unk_12 & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 0; fn_1_A2D84(0xA9011300); } if (((p_lbl_1_bss_9F8->unk_10 >> 1) & 1) != 0 || (((*(struct TitleInput *)&lbl_1_bss_9F8).unk_12 >> 1) & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 1; fn_1_A2D84(0xA9011300); } } while (0) ;
if (((*(struct TitleInput *)&lbl_1_bss_9F8).unk_8 >> 8) & 1) {
if (lbl_8_bss_242__fzgx_offset_1E == 0) {
fn_1_A2D84(0xA9011100);
lbl_8_bss_242__fzgx_offset_E = 10;
fn_1_C3378();
fn_1_F7A20();
} else {
fn_1_A2D84(0xA9011000);
lbl_8_bss_242__fzgx_offset_E = 11;
}
}
break;
case 35:
lbl_8_bss_242__fzgx_offset_1E = 1;
lbl_8_bss_242__fzgx_offset_E = 0x24;
break;
case 36:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_50 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_50, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_7438; p_idx = &(*(fn_8_2660_s32 *)&lbl_801A66B4); item = (*((p_data_tbl) + (*p_idx))); loc_4C = (*((fzgx_pool_table8) + (0))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); p_data_tbl = (void **)lbl_8_data_7200; p_idx = &(*(fn_8_2660_s32 *)&lbl_801A66B4); if (item == (*((p_data_tbl) + (*p_idx)))) { fn_1_53C9C((void *)&loc_4C, item, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f)); } else { fn_1_53C9C((void *)&loc_4C, item, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f)); } do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_747C; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (280.0f)); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
vHalf = (*(struct TitleInput *)&lbl_1_bss_9F8).unk_8;
if ((vHalf >> 8) & 1) {
fn_1_A2D84(0xA9011100);
lbl_8_bss_242__fzgx_offset_E = 10;
fn_1_C3378();
fn_1_F7A20();
} else if ((vHalf >> 11) & 1) {
fn_1_A2D84(0xA9011000);
lbl_8_bss_242__fzgx_offset_E = 11;
}
break;
case 8:
if (fn_1_B7C00() != 0) {
break;
}
lbl_8_bss_242__fzgx_offset_1E = 1;
lbl_8_bss_242__fzgx_offset_E = 9;
break;
case 9:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_48 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_48, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_6E30; p_idx = &(*(fn_8_2660_s32 *)&lbl_801A66B4); item = (*((p_data_tbl) + (*p_idx))); loc_44 = (*((fzgx_pool_table8) + (0))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); p_data_tbl = (void **)lbl_8_data_7200; p_idx = &(*(fn_8_2660_s32 *)&lbl_801A66B4); if (item == (*((p_data_tbl) + (*p_idx)))) { fn_1_53C9C((void *)&loc_44, item, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f)); } else { fn_1_53C9C((void *)&loc_44, item, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f)); } do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_750C; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (240.0f)); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
fn_8_23AC(&lbl_8_bss_242__fzgx_offset_1E, (0.0700000003f));
do { p_lbl_1_bss_9F8 = (struct TitleInput *)&(*(struct TitleInput *)&lbl_1_bss_9F8); if ((p_lbl_1_bss_9F8->unk_10 & 1) != 0 || (p_lbl_1_bss_9F8->unk_12 & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 0; fn_1_A2D84(0xA9011300); } if (((p_lbl_1_bss_9F8->unk_10 >> 1) & 1) != 0 || (((*(struct TitleInput *)&lbl_1_bss_9F8).unk_12 >> 1) & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 1; fn_1_A2D84(0xA9011300); } } while (0) ;
if (((*(struct TitleInput *)&lbl_1_bss_9F8).unk_8 >> 8) & 1) {
if (lbl_8_bss_242__fzgx_offset_1E == 0) {
fn_1_A2D84(0xA9011100);
lbl_8_bss_242__fzgx_offset_E = 10;
fn_1_C3378();
fn_1_F7A20();
} else {
fn_1_A2D84(0xA9011000);
lbl_8_bss_242__fzgx_offset_E = 11;
}
}
break;
case 10:
do { loc_40 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_40, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_76A0; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (210.0f)); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_7B78; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fTmp = (320.0f); fn_1_496FC(fTmp, fTmp); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
if (((*(struct TitleInput *)&lbl_1_bss_9F8).unk_8 >> 8) & 1) {
fn_1_A2D84(0xA9011100);
lbl_8_bss_242__fzgx_offset_E = 0x25;
}
break;
case 6:
if (fn_1_B7C00() != 0) {
break;
}
lbl_8_bss_242__fzgx_offset_E = 7;
break;
case 7:
if (fn_1_B7C00() != 0) {
break;
}
if (lbl_8_bss_242__fzgx_offset_10 != 0) {
lbl_8_bss_242__fzgx_offset_E = 15;
} else {
lbl_8_bss_242__fzgx_offset_E = 17;
}
break;
case 15:
if (fn_1_B7C00() != 0) {
break;
}
args.unk0 = 1;
args.unk4 = 0x104;
args.unkC = (fn_8_2660_u32)&lbl_1_bss_718E0;
fn_1_AA6D8(2, 0, &args);
lbl_8_bss_242__fzgx_offset_E = 0x10;
break;
case 16:
if (fn_1_B7C00() != 0) {
break;
}
ret = fn_1_B7C5C();
lbl_8_bss_242__fzgx_offset_1A = ret;
if (ret != 0) {
lbl_8_bss_242__fzgx_offset_E = 0;
} else if (ret == 0) {
fn_1_C34F0();
lbl_8_bss_242__fzgx_offset_E = 0x25;
} else {
lbl_8_bss_242__fzgx_offset_E = 0x25;
}
break;
case 17:
if (fn_1_B7C00() != 0) {
break;
}
lbl_8_bss_242__fzgx_offset_E = 0x12;
break;
case 18:
if (fn_1_B7C00() != 0) {
break;
}
if (lbl_8_bss_242__fzgx_offset_12 >= 4 && lbl_8_bss_242__fzgx_offset_16 > 0) {
lbl_8_bss_242__fzgx_offset_E = 0x13;
} else {
lbl_8_bss_242__fzgx_offset_E = 0x15;
}
break;
case 19:
if (fn_1_B7C00() != 0) {
break;
}
lbl_8_bss_242__fzgx_offset_1E = 0;
lbl_8_bss_242__fzgx_offset_E = 0x14;
break;
case 20:
if (fn_1_B7C00() != 0) {
break;
}
if (fn_1_B7E98(0) == 0) {
lbl_8_bss_242__fzgx_offset_E = 11;
break;
}
do { loc_3C = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_3C, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
title_formats = (void **)lbl_8_data_6EC4;
sprintf((char *)bufC8, (const char *)(*((title_formats) + ((*(fn_8_2660_s32 *)&lbl_801A66B4) ))), lbl_8_bss_242__fzgx_offset_12);
loc_38 = (*((fzgx_pool_table8) + (0)));
fn_1_49410();
do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0) ;
title_names = (void **)lbl_8_data_7200;
if ((void *)bufC8 == (*((title_names) + ((*(fn_8_2660_s32 *)&lbl_801A66B4) )))) {
fn_1_53C9C((void *)&loc_38, (void *)bufC8, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f));
} else {
fn_1_53C9C((void *)&loc_38, (void *)bufC8, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f));
}
do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_7900; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (240.0f)); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
fn_8_23AC(&lbl_8_bss_242__fzgx_offset_1E, (0.0700000003f));
do { p_lbl_1_bss_9F8 = (struct TitleInput *)&(*(struct TitleInput *)&lbl_1_bss_9F8); if ((p_lbl_1_bss_9F8->unk_10 & 1) != 0 || (p_lbl_1_bss_9F8->unk_12 & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 0; fn_1_A2D84(0xA9011300); } if (((p_lbl_1_bss_9F8->unk_10 >> 1) & 1) != 0 || (((*(struct TitleInput *)&lbl_1_bss_9F8).unk_12 >> 1) & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 1; fn_1_A2D84(0xA9011300); } } while (0) ;
if (((*(struct TitleInput *)&lbl_1_bss_9F8).unk_8 >> 8) & 1) {
if (lbl_8_bss_242__fzgx_offset_1E == 0) {
lbl_8_bss_242__fzgx_offset_22 = 60;
lbl_8_bss_242__fzgx_offset_E = 0x19;
fn_1_A2D84(0xA9011100);
} else {
lbl_8_bss_242__fzgx_offset_E = 0x1e;
fn_1_A2D84(0xA9011000);
}
}
break;
case 25:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_34 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_34, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_7980; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (240.0f)); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
cnt = lbl_8_bss_242__fzgx_offset_22;
lbl_8_bss_242__fzgx_offset_22 = cnt - 1;
if ((fn_8_2660_s32)cnt < 0) {
lbl_8_bss_242__fzgx_offset_E = 0x1a;
}
break;
case 28:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_30 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_30, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_7A18; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (240.0f)); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
cnt = lbl_8_bss_242__fzgx_offset_22;
lbl_8_bss_242__fzgx_offset_22 = cnt - 1;
if ((fn_8_2660_s32)cnt < 0) {
lbl_8_bss_242__fzgx_offset_E = 0;
}
break;
case 26:
fn_8_F9E4((void *)fzgx_obj_lbl_8_bss_234, (void *)fzgx_obj_lbl_8_bss_238, (*(struct Title8B3A0 *)&lbl_1_bss_8B3A0).unk_9E);
lbl_8_bss_242__fzgx_offset_1E = 1;
lbl_8_bss_242__fzgx_offset_E = 0x1b;
break;
case 27:
if (fn_1_B7C00() != 0) {
break;
}
if (fn_1_B7E98(0) == 0) {
fn_8_FF9C();
lbl_8_bss_242__fzgx_offset_22 = 120;
lbl_8_bss_242__fzgx_offset_E = 0x1c;
} else if (fn_8_FC5C() != 0) {
do { p_lbl_1_bss_9F8 = (struct TitleInput *)&(*(struct TitleInput *)&lbl_1_bss_9F8); if ((p_lbl_1_bss_9F8->unk_10 & 1) != 0 || (p_lbl_1_bss_9F8->unk_12 & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 0; fn_1_A2D84(0xA9011300); } if (((p_lbl_1_bss_9F8->unk_10 >> 1) & 1) != 0 || (((*(struct TitleInput *)&lbl_1_bss_9F8).unk_12 >> 1) & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 1; fn_1_A2D84(0xA9011300); } } while (0) ;
p_lbl_1_bss_9F8 = (struct TitleInput *)&(*(struct TitleInput *)&lbl_1_bss_9F8);
if ((p_lbl_1_bss_9F8->unk_8 >> 9) & 1) {
lbl_8_bss_242__fzgx_offset_1E = 1;
fn_1_A2D84(0xA9011300);
}
vHalf = p_lbl_1_bss_9F8->unk_8;
if (((vHalf >> 8) & 1) || ((vHalf >> 9) & 1)) {
if (lbl_8_bss_242__fzgx_offset_1E == 0) {
fn_8_10084((fn_8_2660_u32)(*(fn_8_2660_u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26));
fn_8_FF9C();
lbl_8_bss_242__fzgx_offset_E = 0x18;
} else {
fn_8_100B4();
}
}
fn_1_4FD64();
fn_1_4D0A0();
fn_1_4AEC0(1);
fn_1_4AEB4((1.5f));
fn_1_49410();
fTmp = (0.75f);
fn_1_4955C(fTmp, fTmp);
fn_1_4954C((0.0200000033f));
fn_1_495C8(9);
fn_1_496FC((320.0f), (220.0f));
fn_1_4966C((-1.0f), (8.0f));
if ((*(fn_8_2660_s32 *)&lbl_801A66B4) != 5) {
fn_1_495B0(0x80000000);
fn_1_49590((0.5f));
fn_1_4966C((-1.0f), (4.0f));
}
p_data_tbl = (void **)lbl_8_data_7BFC;
p_idx = &(*(fn_8_2660_s32 *)&lbl_801A66B4) ;
fn_1_4A0D8((const char *)(*((p_data_tbl) + (*p_idx))));
fn_1_4AEC0(0);
fn_1_4AEB4((0.0f));
fn_8_23AC(&lbl_8_bss_242__fzgx_offset_1E, (0.0200000033f));
loc_60 = (*((fzgx_pool_tail13C) + (0)));
fn_1_4D2AC((void *)&loc_60, (0.0300000012f), (40.0f));
}
break;
case 24:
if (fn_1_B7C00() != 0) {
break;
}
OSReport("@#$@#$@$  %s\n", (const char *)(*(fn_8_2660_u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26));
if ((*(fn_8_2660_s32 *)&lbl_801A66B4) != 5) {
fn_80083DB0((fn_8_2660_u32)buf64, (fn_8_2660_u32)(*(fn_8_2660_u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26));
src = (fn_8_2660_u8 *)buf64;
dst = (*(fn_8_2660_u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26);
while (*src != 0) {
if (*src < 0x80) {
*dst = *src;
src++;
dst++;
} else {
cp = (fn_8_2660_u8 *)fn_8_5840(src);
if (cp != 0) {
*dst = *cp;
dst++;
}
src += 2;
}
}
*dst = 0;
}
OSReport("@#$@#$@$  %s\n", (const char *)(*(fn_8_2660_u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26));
if ((*(fn_8_2660_u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26)[0] == 0) {
sprintf((char *)(*(fn_8_2660_u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26), "\x83G\x83t\x83[\x83\x8D");
}
fn_80083DB0((fn_8_2660_u32)((fn_8_2660_u8 *)&lbl_1_bss_718E0 + 0x5522), (fn_8_2660_u32)(*(fn_8_2660_u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26));
fn_1_F7954();
fn_1_B7CE4(1, buf84);
((fn_8_2660_u8 *)buf84)[8] = 0x20;
((fn_8_2660_u8 *)buf84)[9] = 0;
strcat((char *)buf84, (char *)(*(fn_8_2660_u8 (*)[0x100])&lbl_8_bss_242__fzgx_offset_26));
fn_1_B7E14(buf84);
*lbl_1_bss_718C0 = fn_1_C3688();
args.unk0 = 1;
args.unk8 = (fn_8_2660_u32)buf84;
args.unkC = (fn_8_2660_u32)&lbl_1_bss_718E0;
args.unk4 = 0x14000;
fn_1_AA6D8(0, 0, &args);
lbl_8_bss_242__fzgx_offset_E = 0x1d;
break;
case 29:
if (fn_1_B7C00() != 0) {
break;
}
ret = fn_1_B7C5C();
if (ret == 0) {
fn_1_C34F0();
lbl_8_bss_242__fzgx_offset_E = 0x25;
} else {
lbl_8_bss_242__fzgx_offset_E = 0;
}
break;
case 30:
if (fn_1_B7C00() != 0) {
break;
}
lbl_8_bss_242__fzgx_offset_1E = 1;
lbl_8_bss_242__fzgx_offset_E = 0x1f;
break;
case 31:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_2C = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_2C, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_6F24; p_idx = &(*(fn_8_2660_s32 *)&lbl_801A66B4); item = (*((p_data_tbl) + (*p_idx))); loc_28 = (*((fzgx_pool_table8) + (0))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); p_data_tbl = (void **)lbl_8_data_7200; p_idx = &(*(fn_8_2660_s32 *)&lbl_801A66B4); if (item == (*((p_data_tbl) + (*p_idx)))) { fn_1_53C9C((void *)&loc_28, item, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f)); } else { fn_1_53C9C((void *)&loc_28, item, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f)); } do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_759C; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (240.0f)); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
fn_8_23AC(&lbl_8_bss_242__fzgx_offset_1E, (0.0700000003f));
do { p_lbl_1_bss_9F8 = (struct TitleInput *)&(*(struct TitleInput *)&lbl_1_bss_9F8); if ((p_lbl_1_bss_9F8->unk_10 & 1) != 0 || (p_lbl_1_bss_9F8->unk_12 & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 0; fn_1_A2D84(0xA9011300); } if (((p_lbl_1_bss_9F8->unk_10 >> 1) & 1) != 0 || (((*(struct TitleInput *)&lbl_1_bss_9F8).unk_12 >> 1) & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 1; fn_1_A2D84(0xA9011300); } } while (0) ;
if (((*(struct TitleInput *)&lbl_1_bss_9F8).unk_8 >> 8) & 1) {
if (lbl_8_bss_242__fzgx_offset_1E == 0) {
lbl_8_bss_242__fzgx_offset_E = 0x20;
fn_1_C3378();
fn_1_F7A20();
fn_1_A2D84(0xA9011100);
} else {
lbl_8_bss_242__fzgx_offset_E = 0xb;
fn_1_A2D84(0xA9011000);
}
}
break;
case 32:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_24 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_24, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_76A0; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (210.0f)); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_7B78; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fTmp = (320.0f); fn_1_496FC(fTmp, fTmp); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
if (((*(struct TitleInput *)&lbl_1_bss_9F8).unk_8 >> 8) & 1) {
lbl_8_bss_242__fzgx_offset_E = 0x25;
fn_1_A2D84(0xA9011100);
}
break;
case 21:
if (fn_1_B7C00() != 0) {
break;
}
lbl_8_bss_242__fzgx_offset_1E = 1;
lbl_8_bss_242__fzgx_offset_E = 0x16;
break;
case 22:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_20 = (*((fzgx_pool_table4) + (0))); fn_1_53BD8((void *)&loc_20, (320.0f), (240.0f), (500.0f), (400.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_7200; p_idx = &(*(fn_8_2660_s32 *)&lbl_801A66B4); item = (*((p_data_tbl) + (*p_idx))); loc_1C = (*((fzgx_pool_table8) + (0))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); p_data_tbl = (void **)lbl_8_data_7200; p_idx = &(*(fn_8_2660_s32 *)&lbl_801A66B4); if (item == (*((p_data_tbl) + (*p_idx)))) { fn_1_53C9C((void *)&loc_1C, item, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f)); } else { fn_1_53C9C((void *)&loc_1C, item, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f)); } do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_759C; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (345.0f)); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
fn_8_2124(400, (u8 *)&lbl_8_bss_242__fzgx_offset_1E, (0.0700000003f));
do { p_lbl_1_bss_9F8 = (struct TitleInput *)&(*(struct TitleInput *)&lbl_1_bss_9F8); if ((p_lbl_1_bss_9F8->unk_10 & 1) != 0 || (p_lbl_1_bss_9F8->unk_12 & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 0; fn_1_A2D84(0xA9011300); } if (((p_lbl_1_bss_9F8->unk_10 >> 1) & 1) != 0 || (((*(struct TitleInput *)&lbl_1_bss_9F8).unk_12 >> 1) & 1) != 0) { lbl_8_bss_242__fzgx_offset_1E = 1; fn_1_A2D84(0xA9011300); } } while (0) ;
if (((*(struct TitleInput *)&lbl_1_bss_9F8).unk_8 >> 8) & 1) {
if (lbl_8_bss_242__fzgx_offset_1E == 0) {
lbl_8_bss_242__fzgx_offset_E = 0x17;
fn_1_C3378();
fn_1_F7A20();
fn_1_A2D84(0xA9011100);
} else {
lbl_8_bss_242__fzgx_offset_E = 0xb;
fn_1_A2D84(0xA9011000);
}
}
break;
case 23:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_18 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_18, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_77A0; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (210.0f)); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_7B78; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fTmp = (320.0f); fn_1_496FC(fTmp, fTmp); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
if (((*(struct TitleInput *)&lbl_1_bss_9F8).unk_8 >> 8) & 1) {
lbl_8_bss_242__fzgx_offset_E = 0x25;
fn_1_A2D84(0xA9011100);
}
break;
case 11:
if (fn_1_B7C00() != 0) {
break;
}
lbl_8_bss_242__fzgx_offset_E = 0xc;
break;
case 12:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_14 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_14, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_7398; p_idx = &(*(fn_8_2660_s32 *)&lbl_801A66B4); item = (*((p_data_tbl) + (*p_idx))); loc_10 = (*((fzgx_pool_table8) + (0))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); p_data_tbl = (void **)lbl_8_data_7200; p_idx = &(*(fn_8_2660_s32 *)&lbl_801A66B4); if (item == (*((p_data_tbl) + (*p_idx)))) { fn_1_53C9C((void *)&loc_10, item, (320.0f), (190.0f), (0.0700000003f), (30.0f), (0.550000012f)); } else { fn_1_53C9C((void *)&loc_10, item, (320.0f), (150.0f), (0.0700000003f), (30.0f), (0.75f)); } do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_7AB0; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (260.0f)); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
vHalf = (*(struct TitleInput *)&lbl_1_bss_9F8).unk_8;
if ((vHalf >> 8) & 1) {
lbl_8_bss_242__fzgx_offset_E = 0;
fn_1_A2D84(0xA9011100);
} else if ((vHalf >> 9) & 1) {
lbl_8_bss_242__fzgx_offset_22 = 60;
lbl_8_bss_242__fzgx_offset_E = 0xd;
fn_1_A2D84(0xA9011000);
}
break;
case 13:
do { loc_C = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_C, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_7B28; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (240.0f)); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
cnt = lbl_8_bss_242__fzgx_offset_22;
lbl_8_bss_242__fzgx_offset_22 = cnt - 1;
if ((fn_8_2660_s32)cnt < 0) {
lbl_8_bss_242__fzgx_offset_E = 0xe;
fn_1_C3378();
fn_1_F7A20();
}
break;
case 14:
if (fn_1_B7C00() != 0) {
break;
}
do { loc_8 = (*((fzgx_pool_table6) + (0))); fn_1_53BD8((void *)&loc_8, (320.0f), (240.0f), (500.0f), (300.0f), (0.0799999982f)); if (lbl_8_bss_242__fzgx_offset_2 == 3) { fn_1_A2D84(0xA9010600); } } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_76A0; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fn_1_496FC((320.0f), (210.0f)); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
do { p_data_tbl = (void **)lbl_8_data_7B78; item = (*((p_data_tbl) + ((*(fn_8_2660_s32 *)&lbl_801A66B4)))); fn_1_49410(); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { do { fn_1_4AEC0(1); fn_1_4AEB4((1.5f)); fn_1_4966C((-1.0f), (8.0f)); } while (0); } else { do { fn_1_49590((0.5f)); fn_1_495B0(0x80000000); fn_1_4966C((-1.0f), (4.0f)); } while (0); } } while (0); fTmp = (0.75f); fn_1_4955C(fTmp, fTmp); fn_1_4954C((0.0700000003f)); fn_1_495C8(9); fTmp = (320.0f); fn_1_496FC(fTmp, fTmp); fn_1_4A0D8((const char *)item); do { if ((*(fn_8_2660_s32 *)&lbl_801A66B4) == 5) { fn_1_4AEC0(0); fn_1_4AEB4((0.0f)); } } while (0); } while (0) ;
if (((*(struct TitleInput *)&lbl_1_bss_9F8).unk_8 >> 8) & 1) {
lbl_8_bss_242__fzgx_offset_E = 0x25;
fn_1_A2D84(0xA9011100);
}
break;
case 37:
if (fn_1_B88C4() != 0) {
lbl_8_bss_242__fzgx_offset_E = 0x26;
} else {
lbl_8_bss_242__fzgx_offset_E = 0x27;
}
break;
case 38:
if (fn_1_B8EDC(0) != 0) {
lbl_8_bss_242__fzgx_offset_E = 0x27;
}
break;
case 39:
lbl_8_bss_242__fzgx_offset_E = 0x28;
break;
case 40:
lbl_8_bss_242__fzgx_offset_E = 0x29;
break;
case 41:
vByte = (*(struct Title858 *)&lbl_1_bss_58).unk_15;
switch (vByte) {
case 1:
case 3:
(*(fn_8_2660_s16 *)&lbl_1_bss_96A) = 0xa4;
break;
case 0:
case 2:
default:
(*(fn_8_2660_s16 *)&lbl_1_bss_96A) = 0x9c;
break;
}
(*(struct Title858 *)&lbl_1_bss_58).unk_15 = (vByte + 1) & 3;
if ((*(fn_8_2660_s16 *)&lbl_1_bss_96A) == 0x9c) {
fn_1_3EF8C(6);
fn_1_3ED8C(0, 3, 1, fzgx_obj_lbl_8_bss_224 & 0xFF, 10, 30, 0);
fn_1_3EB78(0, 0, 0, 0);
fn_1_3EFF0((fn_8_2660_u32)fn_8_784, 1);
fn_8006CE1C((1.0f));
fn_1_3EF08(1);
}
break;
}
fn_1_54278(0, 0);
fn_1_5428C((1.0f));
}

/* the names and tables of fn_8_4E90, fn_8_5218, fn_8_5840 and fn_8_5B44 */
char lbl_8_data_7CDC[] = "LightMain";
char lbl_8_data_7CE8[] = "OperationCardDisp";
char lbl_8_data_7CFC[] = "\x82`\x82" "a\x82" "b\x82" "c\x82" "d\x82" "e\x82" "f\x82g\x82h\x82i\x82j\x82k\x82l\x82m\x82n\x82o\x82p\x82q\x82r\x82s\x82t\x82u\x82v\x82w\x82x\x82y";
char lbl_8_data_7D34[] = "\x82\x81\x82\x82\x82\x83\x82\x84\x82\x85\x82\x86\x82\x87\x82\x88\x82\x89\x82\x8A\x82\x8B\x82\x8C\x82\x8D\x82\x8E\x82\x8F\x82\x90\x82\x91\x82\x92\x82\x93\x82\x94\x82\x95\x82\x96\x82\x97\x82\x98\x82\x99\x82\x9A";
char lbl_8_data_7D6C[] = "\x81" "C\x81" "D\x81H\x81I\x81{\x81|\x81^\x81_\x81\x81\x81\x83\x81\x84\x81" "F\x81G\x81L\x81M\x81O\x81Q\x81" "b\x81i\x81j\x81m\x81n\x81o\x81p\x81\x90\x81\x93\x81\x94\x81\x95\x81\x96\x81\x97\x81@";
char lbl_8_data_7DAC[] = "\x82O\x82P\x82Q\x82R\x82S\x82T\x82U\x82V\x82W\x82X";
char lbl_8_data_7DC4[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char lbl_8_data_7DE0[] = "abcdefghijklmnopqrstuvwxyz";
char lbl_8_data_7DFC[] = ",.?!+-/\\=<>:;'`^_|()[]{}$%#&*@  ";
char lbl_8_data_7E20[] = "0123456789";
char lbl_8_data_7E2C[] = "movie/story00";
char lbl_8_data_7E3C[] = "movie/story01A";
char lbl_8_data_7E4C[] = "end";
/* fzgx:end fn_8_2660 */

/* fzgx:begin fn_8_4E8C */
// fn_8_4E8C: empty in retail (single blr).
void fn_8_4E8C(void) {
}
/* fzgx:end fn_8_4E8C */

/* fzgx:begin fn_8_4E90 */
extern u32 fn_1_3F8C(void *, void *, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern u32 fn_1_7BA08(u32, u32, u32);
extern u32 fn_1_7BA48(u32);
extern u32 fn_8_68D8(void);




extern void fn_1_7BAF8(void);

struct fn_8_4E90_lbl_8_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x22C];
    u32 unk_238;
    u8 pad_23C[0x1];
    u8 unk_23D;
    u8 pad_23E[0x4];
    u8 unk_242;
    u8 pad_243[0x45];
    u32 unk_288;
};
struct fn_8_4E90_lbl_801A6410 {
    u32 unk_0;
};

void fn_8_4E90(void) {
    struct fn_8_4E90_lbl_8_bss_0 *p_lbl_8_bss_0;
    u32 t2, t3, t6;
    p_lbl_8_bss_0 = (struct fn_8_4E90_lbl_8_bss_0 *)&(*(struct fn_8_4E90_lbl_8_bss_0 *)&lbl_8_bss_0);
    if (p_lbl_8_bss_0->unk_23D == 0) {
    p_lbl_8_bss_0->unk_242 = 0;
    fn_8_68D8();
    if (p_lbl_8_bss_0->unk_8 != 0) {
    fn_1_46B4((*(struct fn_8_4E90_lbl_801A6410 *)&lbl_801A6410).unk_0, p_lbl_8_bss_0->unk_8, &(*(u32 *)&lbl_8_data_434), 3359);
    p_lbl_8_bss_0->unk_8 = 0;
    }
    t2 = fn_1_7BA08(32, 32, 64);
    t3 = fn_1_45D0((*(struct fn_8_4E90_lbl_801A6410 *)&lbl_801A6410).unk_0, t2, &(*(u32 *)&lbl_8_data_434), 3362);
    p_lbl_8_bss_0->unk_8 = t3;
    fn_1_7BA48(t3);
    fn_1_435C(p_lbl_8_bss_0->unk_238);
    t6 = fn_1_3F8C(&(*(u32 *)&lbl_8_data_7CDC), fn_1_7BAF8, p_lbl_8_bss_0->unk_8, 2);
    p_lbl_8_bss_0->unk_288 = t6;
    }
}
/* fzgx:end fn_8_4E90 */

/* fzgx:begin fn_8_4F64 noprologue */
#include "types.h"

typedef signed short s16;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;

typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);
struct TitleState {
u8 unk0;
u8 unk1;
u8 unk2;
u8 pad3[0x21d];
f32 unk220;
u8 pad224[0x19];
u8 unk23d;
u8 pad23e[4];
u8 unk242;
};
struct TitleRodata {
f32 unk0;
f32 unk4;
f32 unk8;
u8 padC[0x20];
f32 unk2c;
f32 unk30;
f32 unk34;
};
struct FzgxCopy88 { u32 words[22]; };
extern struct TitleState lbl_8_bss_0;
extern struct TitleRodata lbl_8_rodata_0;
extern struct FzgxCopy88 lbl_1_rodata_26F8;
extern u16 lbl_1_bss_96A;
extern u32 lbl_801A66A0;
extern int fn_1_3F038(void);
extern void fn_1_52070(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_1_52088(void);
extern u16 fn_1_486C4(u32);
extern u16 fn_1_48690(u32);
extern void fn_8_68F4(void);
void fn_8_4F64(void) {
struct TitleState *state = (struct TitleState *) &lbl_8_bss_0;
struct TitleRodata *rodata = (struct TitleRodata *) &lbl_8_rodata_0;
struct FzgxCopy88 loc_60;
struct FzgxCopy88 loc_8;
s16 temp_r30;
s16 temp_r29;
if (state->unk23d != 0) {
fn_1_3F038();
return;
}
if (state->unk242 != 0) {
if (fn_1_3F038() != 0) {
if (state->unk0 != 0) {
state->unk1 = 1;
state->unk0 = 0;
return;
}
lbl_1_bss_96A = 0xA3;
}
return;
}
fn_1_52070(0x60);
loc_60 = lbl_1_rodata_26F8;
loc_60.words[0] = 0x100;
*(f32 *) ((u8 *) &loc_60 + 4) = rodata->unk2c;
*(f32 *) ((u8 *) &loc_60 + 8) = rodata->unk30;
*(f32 *) ((u8 *) &loc_60 + 12) = rodata->unk34;
*(u32 *) ((u8 *) &loc_60 + 0x30) = 0xD;
fn_1_51678((FontDrawPacket *) &loc_60, 0x100, 0, 0, 0xFA, 0x22);
fn_1_4F734((FontDrawPacket *) &loc_60);
fn_1_52088();
fn_1_52070(0x220);
state->unk220 = rodata->unk8;
fn_1_52088();
fn_1_52070(0x140);
if (state->unk2 != 0 && (lbl_801A66A0 & 0x18)) {
loc_8 = lbl_1_rodata_26F8;
loc_8.words[0] = 0x102;
fn_1_51678((FontDrawPacket *) &loc_8, loc_8.words[0], 0,
(s16) (((fn_1_486C4(loc_8.words[0]) >> 2) & 0x3FFF) * 3),
(fn_1_48690(loc_8.words[0])), ((fn_1_486C4(0x102) >> 2) & 0x3FFF));
*(f32 *) ((u8 *) &loc_8 + 4) = rodata->unk0;
*(f32 *) ((u8 *) &loc_8 + 8) = rodata->unk4;
*(f32 *) ((u8 *) &loc_8 + 12) = rodata->unk8;
*(u32 *) ((u8 *) &loc_8 + 0x30) = 6;
fn_1_4F734((FontDrawPacket *) &loc_8);
}
fn_1_52088();
fn_8_68F4();
}
/* fzgx:end fn_8_4F64 */

/* fzgx:begin fn_8_516C */
extern u32 fn_1_435C(u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);

struct fn_8_516C_lbl_8_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x22C];
    u32 unk_238;
    u8 pad_23C[0x1];
    u8 unk_23D;
    u8 pad_23E[0x4A];
    u32 unk_288;
};
struct fn_8_516C_lbl_801A6410 {
    u32 unk_0;
};
struct fn_8_516C_lbl_1_bss_7C850 {
    u32 unk_0;
};

void fn_8_516C(void) {
    struct fn_8_516C_lbl_8_bss_0 *p_lbl_8_bss_0;
    u32 v0;
    p_lbl_8_bss_0 = (struct fn_8_516C_lbl_8_bss_0 *)&(*(struct fn_8_516C_lbl_8_bss_0 *)&lbl_8_bss_0);
    fn_1_435C(p_lbl_8_bss_0->unk_238);
    if ((s32)p_lbl_8_bss_0->unk_288 != 0) {
    fn_1_426C(p_lbl_8_bss_0->unk_288);
    p_lbl_8_bss_0->unk_288 = 0;
    }
    if (p_lbl_8_bss_0->unk_8 != 0) {
    fn_1_46B4((*(struct fn_8_516C_lbl_801A6410 *)&lbl_801A6410).unk_0, p_lbl_8_bss_0->unk_8, (u32)&(*(u32 *)&lbl_8_data_434), 3405);
    p_lbl_8_bss_0->unk_8 = 0;
    }
    v0 = (*(struct fn_8_516C_lbl_1_bss_7C850 *)&lbl_1_bss_7C850).unk_0;
    (*(struct fn_8_516C_lbl_1_bss_7C850 *)&lbl_1_bss_7C850).unk_0 = (v0 + 1);
    if (p_lbl_8_bss_0->unk_23D == 0) {
    fn_8_69D8(v0, (u32)&(*(struct fn_8_516C_lbl_1_bss_7C850 *)&lbl_1_bss_7C850));
    }
}
/* fzgx:end fn_8_516C */

/* fzgx:begin fn_8_520C */
// fn_8_520C: empty in retail (single blr).
void fn_8_520C(void) {
}
/* fzgx:end fn_8_520C */

/* fzgx:begin fn_8_5210 */
// fn_8_5210: empty in retail (single blr).
void fn_8_5210(void) {
}
/* fzgx:end fn_8_5210 */

/* fzgx:begin fn_8_5214 */
// fn_8_5214: empty in retail (single blr).
void fn_8_5214(void) {
}
/* fzgx:end fn_8_5214 */

/* fzgx:begin fn_8_5218 */
extern void fn_8_6A50(void);
extern void fn_8_C038(void);
extern void *fn_1_7BA08(u32, u32, u32);
extern void fn_1_7BA48(void);
extern void fn_1_435C(void *);
extern void *fn_1_46B4(void *, void *, void *, u32);
extern void *fn_1_45D0(void *, void *, void *, u32);
extern void *fn_1_3F8C(void *, void *, void *, u32);
extern void fn_1_7BAF8(void);

typedef struct fn_8_5218_TitleState {
    u8 unk0[0x8];
    void *resource;
    u8 unkC[0x22c];
    void *unk238;
    u8 unk23c[1];
    u8 initialized;
    u8 unk23e[3];
    u8 unk241;
    u8 reset;
    u8 unk243[0x45];
    void *unk288;
    void *unk28c;
} fn_8_5218_TitleState;

typedef struct fn_8_5218_TitleData {
    u8 unk0[0x7cdc];
    u8 unk7cdc[0xc];
} fn_8_5218_TitleData;

void fn_8_5218(void) {
    fn_8_5218_TitleState *state = (fn_8_5218_TitleState *)&lbl_8_bss_0;
    fn_8_5218_TitleData *data = (fn_8_5218_TitleData *)&(*(char (*)[4])&lbl_8_data_0);

    if (!state->initialized) {
        state->reset = 0;
        fn_8_6A50();
        if (state->resource != 0) {
            fn_1_46B4(lbl_801A6410, state->resource, &data->unk0[0x434], 0xdb2);
            state->resource = 0;
        }
        state->resource = fn_1_45D0(lbl_801A6410, fn_1_7BA08(0x20, 0x20, 0x40),
                                    &data->unk0[0x434], 0xdb5);
        fn_1_7BA48();
        fn_1_435C(state->unk238);
        state->unk288 = fn_1_3F8C(&data->unk0[0x7cdc], fn_1_7BAF8,
                                  state->resource, 2);
        state->unk28c = fn_1_3F8C(&data->unk0[0x7ce8], fn_8_C038, 0, 0x1c);
    }
}
/* fzgx:end fn_8_5218 */

/* fzgx:begin fn_8_530C noprologue */
#include "types.h"

#include "font.h"

struct TitleState {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3[0x21d];
    f32 unk220;
    u8 pad224[0x19];
    u8 unk23d;
    u8 pad23e[4];
    u8 unk242;
};

struct TitleRodata {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 padC[0x20];
    f32 unk2c;
    f32 unk30;
    f32 unk34;
};

struct FzgxCopy88 { u32 words[22]; };

extern struct TitleState lbl_8_bss_0;
extern struct TitleRodata lbl_8_rodata_0;
extern struct FzgxCopy88 lbl_1_rodata_26F8;
extern u16 lbl_1_bss_96A;
extern u32 lbl_801A66A0;
extern int fn_1_3F038(void);
extern void fn_1_52070(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_1_52088(void);
extern u16 fn_1_486C4(u32);
extern u16 fn_1_48690(u32);
extern void fn_8_6A70(void);

void fn_8_530C(void) {
    struct TitleState *state = (struct TitleState *) &lbl_8_bss_0;
    struct TitleRodata *rodata = (struct TitleRodata *) &lbl_8_rodata_0;
    struct FzgxCopy88 loc_60;
    struct FzgxCopy88 loc_8;
    s16 temp_r30;
    s16 temp_r29;

    if (state->unk23d != 0) {
        fn_1_3F038();
        return;
    }
    if (state->unk242 != 0) {
        if (fn_1_3F038() != 0) {
            if (state->unk0 != 0) {
                state->unk1 = 1;
                state->unk0 = 0;
                return;
            }
            lbl_1_bss_96A = 0xA3;
        }
        return;
    }
    fn_1_52070(0x60);
    loc_60 = lbl_1_rodata_26F8;
    loc_60.words[0] = 0x100;
    *(f32 *) ((u8 *) &loc_60 + 4) = rodata->unk2c;
    *(f32 *) ((u8 *) &loc_60 + 8) = rodata->unk30;
    *(f32 *) ((u8 *) &loc_60 + 12) = rodata->unk34;
    *(u32 *) ((u8 *) &loc_60 + 0x30) = 0xD;
    fn_1_51678((FontDrawPacket *) &loc_60, 0x100, 0, 0, 0xFA, 0x22);
    fn_1_4F734((FontDrawPacket *) &loc_60);
    fn_1_52088();
    fn_1_52070(0x220);
    state->unk220 = rodata->unk8;
    fn_1_52088();
    fn_1_52070(0x140);
    if (state->unk2 != 0 && (lbl_801A66A0 & 0x18)) {
        loc_8 = lbl_1_rodata_26F8;
        loc_8.words[0] = 0x102;
        fn_1_51678((FontDrawPacket *) &loc_8, loc_8.words[0], 0,
                   (s16) (((fn_1_486C4(loc_8.words[0]) >> 2) & 0x3FFF) * 3),
                   (fn_1_48690(loc_8.words[0])), ((fn_1_486C4(0x102) >> 2) & 0x3FFF));
        *(f32 *) ((u8 *) &loc_8 + 4) = rodata->unk0;
        *(f32 *) ((u8 *) &loc_8 + 8) = rodata->unk4;
        *(f32 *) ((u8 *) &loc_8 + 12) = rodata->unk8;
        *(u32 *) ((u8 *) &loc_8 + 0x30) = 6;
        fn_1_4F734((FontDrawPacket *) &loc_8);
    }
    fn_1_52088();
    fn_8_6A70();
}
/* fzgx:end fn_8_530C */

/* fzgx:begin fn_8_5514 */
extern u32 fn_1_435C(u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);

struct fn_8_5514_lbl_8_bss_0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x22C];
    u32 unk_238;
    u8 pad_23C[0x1];
    u8 unk_23D;
    u8 pad_23E[0x4A];
    u32 unk_288;
    u32 unk_28C;
};
struct fn_8_5514_lbl_801A6410 {
    u32 unk_0;
};
struct fn_8_5514_lbl_1_bss_7C850 {
    u32 unk_0;
};

void fn_8_5514(void) {
    struct fn_8_5514_lbl_8_bss_0 *p_lbl_8_bss_0;
    u32 v0;
    p_lbl_8_bss_0 = (struct fn_8_5514_lbl_8_bss_0 *)&(*(struct fn_8_5514_lbl_8_bss_0 *)&lbl_8_bss_0);
    fn_1_435C(p_lbl_8_bss_0->unk_238);
    if ((s32)p_lbl_8_bss_0->unk_28C != 0) {
    fn_1_426C(p_lbl_8_bss_0->unk_28C);
    p_lbl_8_bss_0->unk_28C = 0;
    }
    if ((s32)p_lbl_8_bss_0->unk_288 != 0) {
    fn_1_426C(p_lbl_8_bss_0->unk_288);
    p_lbl_8_bss_0->unk_288 = 0;
    }
    if (p_lbl_8_bss_0->unk_8 != 0) {
    fn_1_46B4((*(struct fn_8_5514_lbl_801A6410 *)&lbl_801A6410).unk_0, p_lbl_8_bss_0->unk_8, (u32)&(*(u32 *)&lbl_8_data_434), 3560);
    p_lbl_8_bss_0->unk_8 = 0;
    }
    v0 = (*(struct fn_8_5514_lbl_1_bss_7C850 *)&lbl_1_bss_7C850).unk_0;
    (*(struct fn_8_5514_lbl_1_bss_7C850 *)&lbl_1_bss_7C850).unk_0 = (v0 + 1);
    if (p_lbl_8_bss_0->unk_23D == 0) {
    fn_8_6C50(v0, (u32)&(*(struct fn_8_5514_lbl_1_bss_7C850 *)&lbl_1_bss_7C850));
    }
}
/* fzgx:end fn_8_5514 */

/* fzgx:begin fn_8_55CC */
extern u8 lbl_8_bss_238__fzgx_offset_5;
extern u8 lbl_8_bss_238__fzgx_offset_A;

void fn_8_55CC(void) {
    if (lbl_8_bss_238__fzgx_offset_5 == 0) {
    (*(u8 *)&lbl_8_bss_238__fzgx_offset_A) = 0;
    fn_8_D024();
    }
}
/* fzgx:end fn_8_55CC */

/* fzgx:begin fn_8_5608 noprologue */
#include "types.h"

#include "font.h"

struct TitleState {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3[0x21d];
    f32 unk220;
    u8 pad224[0x19];
    u8 unk23d;
    u8 pad23e[4];
    u8 unk242;
};

struct TitleRodata {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 padC[0x20];
    f32 unk2c;
    f32 unk30;
    f32 unk34;
};

struct FzgxCopy88 { u32 words[22]; };

extern struct TitleState lbl_8_bss_0;
extern struct TitleRodata lbl_8_rodata_0;
extern struct FzgxCopy88 lbl_1_rodata_26F8;
extern u16 lbl_1_bss_96A;
extern u32 lbl_801A66A0;
extern int fn_1_3F038(void);
extern void fn_1_52070(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_1_52088(void);
extern u16 fn_1_486C4(u32);
extern u16 fn_1_48690(u32);
extern void fn_8_D034(void);

void fn_8_5608(void) {
    struct TitleState *state = (struct TitleState *)&lbl_8_bss_0;
    struct TitleRodata *rodata = (struct TitleRodata *)&lbl_8_rodata_0;
    struct FzgxCopy88 loc_60;
    struct FzgxCopy88 loc_8;

    if (state->unk23d != 0) {
        fn_1_3F038();
        return;
    }
    if (state->unk242 != 0) {
        if (fn_1_3F038() != 0) {
            if (state->unk0 != 0) {
                state->unk1 = 1;
                state->unk0 = 0;
                return;
            }
            lbl_1_bss_96A = 0x9E;
        }
        return;
    }
    fn_1_52070(0x60);
    loc_60 = lbl_1_rodata_26F8;
    loc_60.words[0] = 0x100;
    *(f32 *)((u8 *)&loc_60 + 4) = rodata->unk2c;
    *(f32 *)((u8 *)&loc_60 + 8) = rodata->unk30;
    *(f32 *)((u8 *)&loc_60 + 12) = rodata->unk34;
    *(u32 *)((u8 *)&loc_60 + 0x30) = 0xD;
    fn_1_51678((FontDrawPacket *)&loc_60, 0x100, 0, 0, 0xFA, 0x22);
    fn_1_4F734((FontDrawPacket *)&loc_60);
    fn_1_52088();
    fn_1_52070(0x220);
    state->unk220 = rodata->unk8;
    fn_1_52088();
    fn_1_52070(0x140);
    if (state->unk2 != 0 && (lbl_801A66A0 & 0x18)) {
        loc_8 = lbl_1_rodata_26F8;
        loc_8.words[0] = 0x102;
        fn_1_51678((FontDrawPacket *)&loc_8, loc_8.words[0], 0,
                   (s16)(((fn_1_486C4(loc_8.words[0]) >> 2) & 0x3FFF) * 3),
                   (s16)fn_1_48690(loc_8.words[0]),
                   (s16)((fn_1_486C4(0x102) >> 2) & 0x3FFF));
        *(f32 *)((u8 *)&loc_8 + 4) = rodata->unk0;
        *(f32 *)((u8 *)&loc_8 + 8) = rodata->unk4;
        *(f32 *)((u8 *)&loc_8 + 12) = rodata->unk8;
        *(u32 *)((u8 *)&loc_8 + 0x30) = 6;
        fn_1_4F734((FontDrawPacket *)&loc_8);
    }
    fn_1_52088();
    fn_8_D034();
}
/* fzgx:end fn_8_5608 */

/* fzgx:begin fn_8_5810 */
extern u8 lbl_8_bss_238__fzgx_offset_5;

void fn_8_5810(void) {
    if (lbl_8_bss_238__fzgx_offset_5 == 0) {
    fn_8_D5F4();
    }
}
/* fzgx:end fn_8_5810 */

/* fzgx:begin fn_8_5840 */
/*
 * title.c's .data section up to the code tables: the function addresses the
 * tables off the TU's section base (lbl_8_data_0), so they are defined here in
 * retail layout. The leading block stands in for the TU's earlier data.
 */
static char fzgx_obj_lbl_8_data_0[4] = "NON";
static char fzgx_pool_fzgx_title_data_rest[0x7cfc - 4] = "TU data";
static u8 fzgx_pool_fzgx_codes0[27][2] = { 0 };
static u8 fzgx_pool_fzgx_codes1[27][2] = { 0 };
static u8 fzgx_pool_fzgx_codes2[32][2] = { 0 };
static u8 fzgx_pool_fzgx_codes3[11][2] = { 0 };
static u8 fzgx_pool_fzgx_res0[27] = { 0 };
static u8 fzgx_pool_fzgx_res1[27] = { 0 };
static u8 fzgx_pool_fzgx_res2[36] = { 0 };
static u8 fzgx_pool_fzgx_res3[11] = { 0 };

/* Find the two-byte code KEY in CODES; return its entry in RES. */
#define FIND_CODE(key, codes, res)                                         \
    for (i = 0; i < sizeof(codes); i += 2) {                               \
        if ((key)[0] == ((u8 *)(codes))[i] && (key)[1] == ((u8 *)(codes))[i + 1]) { \
            return &(res)[i / 2];                                          \
        }                                                                  \
    }

/* Map a two-byte code to its entry in one of four lookup tables (code pairs -> result bytes). */
u8 *fn_8_5840(u8 *key) {
    s32 i;

    FIND_CODE(key, fzgx_pool_fzgx_codes0, fzgx_pool_fzgx_res0)
    FIND_CODE(key, fzgx_pool_fzgx_codes1, fzgx_pool_fzgx_res1)
    FIND_CODE(key, fzgx_pool_fzgx_codes2, fzgx_pool_fzgx_res2)
    FIND_CODE(key, fzgx_pool_fzgx_codes3, fzgx_pool_fzgx_res3)
    return 0;
}
/* fzgx:end fn_8_5840 */

/* fzgx:begin fn_8_5B44 */
#include "rel/title/title.h"

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    f32 unk_C;
    f32 unk_10;
    u8 unk_14;
    s8 unk_15;
    u8 unk_16;
    s8 unk_17;
    s16 unk_18;
    u8 pad_1A[2];
    u32 unk_1C;
} TitleDisplayState;

extern const f32 lbl_8_rodata_8;  // = 1.0f (retail literal pool)
extern char *fn_80083DB0(char *, const char *);

void fn_8_5B44(void) {
    struct { const char *value; } data;  // TU .data base held across the copies
    f32 one;

    data.value = (const char *)&lbl_8_data_0;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_0 = (*(u32 *)&lbl_801A66B4);
    one = lbl_8_rodata_8;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_1 = 1;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_2 = 0;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_3 = 0;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_4 = 0x280;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_6 = 0x150;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_8 = 0;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_A = 0;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_C = one;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_10 = one;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_14 = 7;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_16 = 0;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_17 = -1;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_18 = -1;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_1C = 0;

    if ((*(TitleDisplayState *)&lbl_1_bss_58).unk_15 == 2) {
        fn_80083DB0(lbl_1_bss_198, data.value + 0x7e2c);
    } else {
        fn_80083DB0(lbl_1_bss_198, data.value + 0x7e3c);
    }
    fn_80083DB0(lbl_1_bss_198 + 0x40, data.value + 0x7e4c);

    (*(TitleDisplayState *)&lbl_1_bss_58).unk_14 = 4;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_16 = 1;
    (*(TitleDisplayState *)&lbl_1_bss_58).unk_17 = 0;
    (*(u16 *)&lbl_1_bss_968) = 8;
}
/* fzgx:end fn_8_5B44 */

/* fzgx:begin fn_8_5C4C */
// fn_8_5C4C: empty in retail (single blr).
void fn_8_5C4C(void) {
}
/* fzgx:end fn_8_5C4C */

/* fzgx:begin fn_8_5C50 */
// fn_8_5C50: empty in retail (single blr).
void fn_8_5C50(void) {
}
/* fzgx:end fn_8_5C50 */

/* fzgx:begin fn_8_5C54 */
#include "rel/title/title.h"

struct fn_8_5C54_Sig_fn_1_F453C_fn_1_F453C_Arg0 {
    u8 unk_0[1];
};
struct fn_8_5C54_Sig_fn_1_F453C_fn_1_F453C_Arg1 {
    u32 unk_0;
};

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
} Fn5C54Entry;

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6[5];
    u8 unk_B;
} Fn5C54Info;

struct fn_8_5C54_lbl_1_bss_8B3A0 {
    u8 pad_0[0x8];
    u16 unk_8;
};

typedef struct {
    u8 unk_0[4];
    u8 unk_4[0x81BC];
} Fn5C54Big;

extern Fn5C54Entry lbl_1_bss_26B80[];

extern u32 fn_1_F453C(struct fn_8_5C54_Sig_fn_1_F453C_fn_1_F453C_Arg0 *, struct fn_8_5C54_Sig_fn_1_F453C_fn_1_F453C_Arg1 *, u32);
extern void fn_1_3EF8C(u8);
extern void fn_1_3ED8C(s32, s32, s32, u8, s32, u8, s32);
extern void fn_1_3EB78(s32, u8 *, u8 *, s32);
extern void fn_1_3EC88(s32, Fn5C54Info *);
extern void fn_1_3EFF0(void *, s32);

#define RD(n) fn_1_F453C((struct fn_8_5C54_Sig_fn_1_F453C_fn_1_F453C_Arg0 *)lbl_8_bss_2B0, (struct fn_8_5C54_Sig_fn_1_F453C_fn_1_F453C_Arg1 *)&lbl_8_bss_2AC, (n))

void fn_8_5C54(s32 arg0) {
    u8 locC[4];
    Fn5C54Info info[4];
    u8 loc8[4];
    u32 a;
    u32 count;
    s32 k;
    u32 i;
    u32 j;
    u8 v;
    u8 *src;
    s32 tmp_RD;
    s32 n;

    lbl_8_bss_2AC = 0;
    tmp_RD = RD(8);
    tmp_RD;
    tmp_RD = RD(6);
    a = tmp_RD;
    fn_1_F47A0(RD(32));
    tmp_RD = RD(32);
    lbl_801A63C0 = tmp_RD;
    tmp_RD = RD(5);
    count = tmp_RD;
    tmp_RD = RD(3);
    (*(struct fn_8_5C54_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0).unk_8 = tmp_RD;
    tmp_RD = RD(2);
    tmp_RD;
    n = 0;
    for (i = 0; i < count; i++) {
        tmp_RD = RD(1);
        lbl_1_bss_26B80[i].unk_0 = tmp_RD;
        tmp_RD = RD(6);
        lbl_1_bss_26B80[i].unk_1 = tmp_RD;
        if (lbl_1_bss_26B80[i].unk_0 != 0) {
            tmp_RD = RD(2);
            lbl_1_bss_26B80[i].unk_2 = tmp_RD;
            tmp_RD = RD(7);
            lbl_1_bss_26B80[i].unk_3 = tmp_RD;
            k = n & 0xFF;
            locC[k] = lbl_1_bss_26B80[i].unk_1;
            loc8[k] = lbl_1_bss_26B80[i].unk_2;
            tmp_RD = RD(1);
            if ((u8)tmp_RD) {
                for (j = 0; j < 0x81C0; j++) {
                    tmp_RD = RD(8);
                    v = tmp_RD;
                    ((u8 *)&((Fn5C54Big *)fn_1_36AD0())[i])[j] = v;
                }
                src = ((Fn5C54Big *)fn_1_36AD0())[i].unk_4;
                fn_80008BA8(&info[k], src, 12);
            } else {
                info[k].unk_1 = lbl_1_bss_26B80[i].unk_1;
                info[k].unk_2 = 1 << lbl_1_bss_26B80[i].unk_2;
                info[k].unk_B = lbl_1_bss_26B80[i].unk_3;
                info[k].unk_4 = 0;
                info[k].unk_3 = 0;
                info[k].unk_5 = 0;
                info[k].unk_0 = 0;
                fn_80008BEC(info[i].unk_6, 0x41, 5);
            }
            n++;
        } else {
            lbl_1_bss_26B80[i].unk_2 = 0;
            lbl_1_bss_26B80[i].unk_3 = 0;
        }
    }
    for (k = 0; k < (n & 0xFF); k++) {
        tmp_RD = RD(2);
        lbl_1_bss_7EFD8[k + 0x38] = tmp_RD + 1;
    }
    if (arg0 != 0) {
        fn_1_3EF8C(6);
        fn_1_3ED8C(0, 3, 1, a, 10, count, 0);
        fn_1_3EB78(n, locC, loc8, 0);
        fn_1_3EC88(n, info);
        fn_1_3EFF0(fn_8_6594, 1);
        fn_1_3F02C(fn_8_67B0);
    }
}
/* fzgx:end fn_8_5C54 */

/* fzgx:begin fn_8_5FD4 */
#include "rel/title/title.h"

struct fn_8_5FD4_Sig_fn_1_F453C_fn_1_F453C_Arg0 { u8 unk_0[1]; };
struct fn_8_5FD4_Sig_fn_1_F453C_fn_1_F453C_Arg1 { u32 unk_0; };
extern u32 fn_1_F453C(struct fn_8_5FD4_Sig_fn_1_F453C_fn_1_F453C_Arg0 *, struct fn_8_5FD4_Sig_fn_1_F453C_fn_1_F453C_Arg1 *, u32);
extern void fn_1_3EF14(void *);

typedef struct {
    f32 x, y, z;
} TitleVec;

/* 0x80-byte record read from the title bitstream */
typedef struct {
    u32 a : 15;
    u32 c : 3;
    u32 d : 5;
    u32 e : 5;
    u32 : 4;
    u32 b : 15;
    u32 f : 5;
    u32 g : 5;
    u32 h : 5;
    u32 : 2;
    TitleVec va[4];
    TitleVec vb[4];
    TitleVec vc;
    TitleVec vd;
} fn_8_5FD4_TitleEntry;

typedef struct {
    u8 b0, b1, b2, b3, b4, b5, b6;
} TitleRec7;

typedef struct {
    u8 pad_0[0xA0];
    u16 recCount;
    u8 pad_A2[2];
    TitleRec7 recs[(0xFEF0 - 0xA4) / 7];
    u16 count;
    u8 pad_FEF2[0x5A];
    fn_8_5FD4_TitleEntry entries[1];
} fn_8_5FD4_TitleData;

struct fn_8_5FD4_lbl_1_bss_7EFD8 {
    u8 pad_0[0x18];
    u8 unk_18;
    u8 pad_19[0x27];
    fn_8_5FD4_TitleData *unk_40;
};

#define TITLE_READ(n) fn_1_F453C((struct fn_8_5FD4_Sig_fn_1_F453C_fn_1_F453C_Arg0 *)lbl_8_bss_2B0, \
                                 (struct fn_8_5FD4_Sig_fn_1_F453C_fn_1_F453C_Arg1 *)&lbl_8_bss_2AC, (n))

static inline f32 title_read_f32(void) {
    u32 bits = TITLE_READ(32);
    return *(f32 *)&bits;
}

void fn_8_5FD4(void) {
    u8 buf[0x14B8];
    s32 i;
    s32 j;

    fn_1_3EF14(buf);
    (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->count = TITLE_READ(8);
    (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_18 = buf[8];
    for (i = 0; i < (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->count; i++) {
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].a = TITLE_READ(14);
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].b = TITLE_READ(14);
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].c = TITLE_READ(4);
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].d = TITLE_READ(5);
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].e = TITLE_READ(5);
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].f = TITLE_READ(5);
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].g = TITLE_READ(5);
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].h = TITLE_READ(5);
        for (j = 0; j < (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_18; j++) {
            (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].va[j].x = title_read_f32();
            (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].va[j].y = title_read_f32();
            (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].va[j].z = title_read_f32();
            (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].vb[j].x = title_read_f32();
            (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].vb[j].y = title_read_f32();
            (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].vb[j].z = title_read_f32();
        }
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].vc.x = title_read_f32();
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].vc.y = title_read_f32();
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].vc.z = title_read_f32();
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].vd.x = title_read_f32();
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].vd.y = title_read_f32();
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->entries[i].vd.z = title_read_f32();
    }

    (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->recCount = TITLE_READ(13);
    for (i = 0; i <= (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->recCount; i++) {
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->recs[i].b0 = TITLE_READ(8);
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->recs[i].b3 = TITLE_READ(8);
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->recs[i].b4 = TITLE_READ(7);
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->recs[i].b5 = TITLE_READ(7);
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->recs[i].b6 = TITLE_READ(8);
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->recs[i].b1 = TITLE_READ(8);
        (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->recs[i].b2 = TITLE_READ(8);
    }
    fn_1_F4794((*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->recCount);
    (*(struct fn_8_5FD4_lbl_1_bss_7EFD8 *)&lbl_1_bss_7EFD8).unk_40->recCount = 0;
}
/* fzgx:end fn_8_5FD4 */

/* fzgx:begin fn_8_6558 */
// fn_8_6558: returns a constant.
int fn_8_6558(void) {
    return 0;
}
/* fzgx:end fn_8_6558 */

/* fzgx:begin fn_8_6560 */
// fn_8_6560: returns a constant.
int fn_8_6560(void) {
    return 0;
}
/* fzgx:end fn_8_6560 */

/* fzgx:begin fn_8_6568 */
// fn_8_6568: returns a constant.
int fn_8_6568(void) {
    return 2;
}
/* fzgx:end fn_8_6568 */

/* fzgx:begin fn_8_6570 */
s32 fn_8_6570(void) {
    fn_1_D0790();
    return 0;
}
/* fzgx:end fn_8_6570 */

/* fzgx:begin fn_8_6594 */
extern u32 fn_1_3F8C0(void);
extern u32 fn_1_47F74(u32);
extern u32 fn_1_5370(u32, u32);
extern u32 fn_80008E84(u32);
extern u32 lbl_8_bss_2B4;
extern void fn_8_6558(void);
extern void fn_8_6560(void);
extern void fn_8_6568(void);
extern void fn_8_6570(void);

void fn_8_6594(u32 arg0) {
    u32 v0;
    u32 t1, t2;
    *(u32 *)((u8 *)arg0 + 168) = (u32)fn_8_6558;
    *(u32 *)((u8 *)arg0 + 196) = (u32)fn_8_6568;
    *(u32 *)((u8 *)arg0 + 204) = (u32)fn_8_6560;
    *(u32 *)((u8 *)arg0 + 172) = (u32)fn_8_6570;
    fn_1_5370(0, 0);
    *(u32 *)((u8 *)arg0 + 0) = (*(u32 *)((u8 *)arg0 + 0) | 513);
    v0 = (*(u32 *)((u8 *)arg0 + 0) | 0x800000);
    *(u32 *)((u8 *)arg0 + 0) = v0;
    lbl_8_bss_2B4 = 0;
    t1 = fn_1_3F8C0();
    t2 = fn_80008E84(t1);
    fn_1_47F74(148);
    fn_80008E84(t2);
}
/* fzgx:end fn_8_6594 */

/* fzgx:begin fn_8_663C noprologue */
#include "types.h"

struct fn_8_663C_Arg0 {
    u32 unk_0;
    u8 pad_4[0xA4];
    u32 unk_A8;
    u32 unk_AC;
    u8 pad_B0[0x14];
    u32 unk_C4;
    u8 pad_C8[0x4];
    u32 unk_CC;
};
struct fn_8_663C_lbl_8_bss_2A8 {
    u8 pad_0[0xC];
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
};
struct fn_8_663C_lbl_801A6410 {
    u32 unk_0;
};

extern void fn_8_6558(void);
extern void fn_8_6560(void);
extern void fn_8_6568(void);
extern s32 fn_8_6570(void);
extern struct fn_8_663C_lbl_801A6410 lbl_801A6410[];
extern u16 lbl_8_bss_2A8[];
extern u32 lbl_8_data_7E50[];
extern void fn_1_14D728(void *, u32);
extern u32 fn_1_3F8C0(void);
extern u32 fn_1_4630(u32, u32, void *, u32);
extern u32 fn_1_5370(u32, u32);
extern u32 fn_80006E10(u32);
extern u32 fn_80008E84(u32);

void fn_8_663C(struct fn_8_663C_Arg0 *arg0) {
    u32 fzgx_value_;
    u32 fzgx_value;
    u8 *p_lbl_8_data_7E50;
    struct fn_8_663C_lbl_8_bss_2A8 *p_lbl_8_bss_2A8;
    u32 v0;
    struct { u32 a[3]; } loc_18;
    struct { u32 a[4]; } loc_8;
    u32 t1;
    u32 t2;

    p_lbl_8_data_7E50 = (u8 *)&lbl_8_data_7E50;
    p_lbl_8_bss_2A8 = (struct fn_8_663C_lbl_8_bss_2A8 *)&lbl_8_bss_2A8;
    fzgx_value = (u32)(fn_8_6558);
    arg0->unk_A8 = fzgx_value;
    arg0->unk_C4 = (u32)(fn_8_6568);
    arg0->unk_CC = (u32)(fn_8_6560);
    arg0->unk_AC = (u32)(fn_8_6570);
    arg0->unk_0 = (arg0->unk_0 | 513);
    fzgx_value_ = ((arg0->unk_0 | 0x200000) | 256);
    arg0->unk_0 = fzgx_value_;
    arg0->unk_0 = (arg0->unk_0 | 32768);
    v0 = (arg0->unk_0 | 0x1000000);
    arg0->unk_0 = v0;
    p_lbl_8_bss_2A8->unk_C = 0;
    fn_1_5370(1, 0);
    t1 = fn_1_3F8C0();
    t2 = fn_80008E84(t1);
    p_lbl_8_bss_2A8->unk_10 = fn_1_4630(lbl_801A6410[0].unk_0, 2592, p_lbl_8_data_7E50 + 3204, 985);
    p_lbl_8_bss_2A8->unk_14 = fn_1_4630(lbl_801A6410[0].unk_0, 2592, p_lbl_8_data_7E50 + 3204, 986);
    loc_18.a[2] = 2;
    *(u16 *)((u8 *)&loc_18 + 0) = 7;
    *(u16 *)((u8 *)&loc_18 + 2) = 31;
    *(u16 *)((u8 *)&loc_18 + 4) = 50;
    loc_8.a[2] = 2;
    *(u16 *)((u8 *)&loc_8 + 0) = 7;
    *(u16 *)((u8 *)&loc_8 + 2) = 27;
    *(u16 *)((u8 *)&loc_8 + 4) = 59;
    fn_80006E10((u32)(p_lbl_8_data_7E50 + 3216));
    fn_1_14D728((void *)&loc_18, p_lbl_8_bss_2A8->unk_10);
    fn_1_14D728((void *)&loc_8, p_lbl_8_bss_2A8->unk_14);
    fn_80006E10((u32)(p_lbl_8_data_7E50 + 3232));
    fn_80008E84(t2);
}
/* fzgx:end fn_8_663C */

/* fzgx:begin fn_8_67B0 */
extern u32 fn_1_3F8C0(void);
extern u32 fn_80008E84(u32);

void fn_8_67B0(void) {
    u32 t0, t1, t3;
    t0 = fn_1_3F8C0();
    t1 = fn_80008E84(t0);
    fn_1_48140(148);
    t3 = fn_80008E84(t1);
    fn_8_8C80(t3);
}
/* fzgx:end fn_8_67B0 */
