/* Non-matching: best partial attempt (95.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Fn40710Object {
    u8 state;
    u8 enabled;
    u8 applied;
    u8 flags;
    u8 pad[0x24];
    u32 value_28;
    u32 value_2c;
} Fn40710Object;

typedef struct GameStateD {
    u8 pad_0[5];
    u8 unk_5;
    u8 pad_6[0xBE];
    u32 unk_C4;
    u8 pad_C8[0x13F4];
} GameStateD;

typedef struct GameElem9F8 {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[6];
    u16 unk_10;
    u16 unk_12;
} GameElem9F8;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 fzgx_obj_lbl_1_bss_3C12__b1;
u8 fzgx_obj_lbl_1_bss_3C12__b2;
u8 fzgx_obj_lbl_1_bss_3C12__b3;
u8 fzgx_obj_lbl_1_bss_3C12__b4;
u8 fzgx_obj_lbl_1_bss_3C12__b5;
u8 fzgx_obj_lbl_1_bss_3C12__b6;
u8 fzgx_obj_lbl_1_bss_3C12__b7;
u8 fzgx_obj_lbl_1_bss_3C12__b8;
u8 fzgx_obj_lbl_1_bss_3C12__b9;
u32 fzgx_obj_lbl_1_bss_3C1C;
u8 lbl_1_bss_3C1C__fzgx_offset_4[10];
s16 fzgx_obj_lbl_1_bss_3C2A;
s16 lbl_1_bss_3C2A__fzgx_offset_2;
s16 lbl_1_bss_3C2A__fzgx_offset_4;
GameStateD fzgx_obj_lbl_1_bss_3C30;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
s8 fzgx_obj_lbl_1_bss_5104;
Fn40710Object lbl_1_bss_5104__fzgx_offset_4;
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 fzgx_obj_lbl_1_bss_523C[8];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u32 fzgx_obj_lbl_1_bss_53F8[34];
u32 fzgx_obj_lbl_1_bss_5480[33216];
u16 fzgx_obj_lbl_1_bss_25B80;
u32 fzgx_obj_lbl_1_bss_25B84;
u32 fzgx_obj_lbl_1_bss_25B88[4];
u16 fzgx_obj_lbl_1_bss_25B98;
u32 fzgx_obj_lbl_1_bss_25B9C;
u32 fzgx_obj_lbl_1_bss_25BA0[42];
u32 fzgx_obj_lbl_1_bss_25C48[23];
u32 fzgx_obj_lbl_1_bss_25CA4[11];
u32 fzgx_obj_lbl_1_bss_25CD0[105];
u32 fzgx_obj_lbl_1_bss_25E74[7];
u32 fzgx_obj_lbl_1_bss_25E90[2];
u8 fzgx_obj_lbl_1_bss_25E98[1];
u32 fzgx_obj_lbl_1_bss_25E9C[240];
u32 fzgx_obj_lbl_1_bss_2625C[8];
u32 fzgx_obj_lbl_1_bss_2627C[30];
u8 fzgx_obj_lbl_1_bss_262F4;
u32 fzgx_obj_lbl_1_bss_262F8[2];
u16 fzgx_obj_lbl_1_bss_26300;
u32 fzgx_obj_lbl_1_bss_26304[4];
u32 fzgx_obj_lbl_1_bss_26314[508];
u32 fzgx_obj_lbl_1_bss_26B04[5];
u8 fzgx_obj_lbl_1_bss_26B18;
u8 fzgx_obj_lbl_1_bss_26B19;
u8 fzgx_obj_lbl_1_bss_26B1A;
u8 fzgx_pad_26B1B;
u8 fzgx_pad_26B1C;
u8 fzgx_obj_lbl_1_bss_26B1D;
u8 fzgx_obj_lbl_1_bss_26B1E;
u8 fzgx_obj_lbl_1_bss_26B1E__b1;
u8 fzgx_obj_lbl_1_bss_26B1E__b2;
u8 fzgx_obj_lbl_1_bss_26B1E__b3;
u8 fzgx_obj_lbl_1_bss_26B1E__b4;
u8 fzgx_obj_lbl_1_bss_26B1E__b5;
u8 fzgx_obj_lbl_1_bss_26B1E__b6;
u8 fzgx_obj_lbl_1_bss_26B1E__b7;
u8 fzgx_obj_lbl_1_bss_26B1E__b8;
u8 fzgx_obj_lbl_1_bss_26B1E__b9;
u8 fzgx_obj_lbl_1_bss_26B1E__b10;
u8 fzgx_obj_lbl_1_bss_26B1E__b11;
u8 fzgx_obj_lbl_1_bss_26B1E__b12;
u8 fzgx_obj_lbl_1_bss_26B1E__b13;
u8 fzgx_obj_lbl_1_bss_26B1E__b14;
u8 fzgx_obj_lbl_1_bss_26B1E__b15;
u8 fzgx_obj_lbl_1_bss_26B1E__b16;
u8 fzgx_obj_lbl_1_bss_26B1E__b17;
u8 fzgx_obj_lbl_1_bss_26B1E__b18;
u8 fzgx_obj_lbl_1_bss_26B1E__b19;
u8 fzgx_obj_lbl_1_bss_26B1E__b20;
u8 fzgx_obj_lbl_1_bss_26B1E__b21;
u8 fzgx_obj_lbl_1_bss_26B1E__b22;
u8 fzgx_obj_lbl_1_bss_26B1E__b23;
u8 fzgx_obj_lbl_1_bss_26B1E__b24;
u8 fzgx_obj_lbl_1_bss_26B1E__b25;
u8 fzgx_obj_lbl_1_bss_26B1E__b26;
u8 fzgx_obj_lbl_1_bss_26B1E__b27;
u8 fzgx_obj_lbl_1_bss_26B1E__b28;
u8 fzgx_obj_lbl_1_bss_26B1E__b29;
u8 fzgx_obj_lbl_1_bss_26B1E__b30;
u8 fzgx_obj_lbl_1_bss_26B1E__b31;
u8 fzgx_obj_lbl_1_bss_26B1E__b32;
u8 fzgx_obj_lbl_1_bss_26B1E__b33;
u8 fzgx_obj_lbl_1_bss_26B1E__b34;
u8 fzgx_obj_lbl_1_bss_26B1E__b35;
u8 fzgx_obj_lbl_1_bss_26B1E__b36;
u8 fzgx_obj_lbl_1_bss_26B1E__b37;
u8 fzgx_obj_lbl_1_bss_26B1E__b38;
u8 fzgx_obj_lbl_1_bss_26B1E__b39;
u8 fzgx_obj_lbl_1_bss_26B1E__b40;
u8 fzgx_obj_lbl_1_bss_26B1E__b41;
u8 fzgx_obj_lbl_1_bss_26B1E__b42;
u8 fzgx_obj_lbl_1_bss_26B1E__b43;
u8 fzgx_obj_lbl_1_bss_26B1E__b44;
u8 fzgx_obj_lbl_1_bss_26B1E__b45;
u32 fzgx_obj_lbl_1_bss_26B4C;
u32 fzgx_obj_lbl_1_bss_26B50;
u32 fzgx_obj_lbl_1_bss_26B54[2];
u8 fzgx_obj_lbl_1_bss_26B5C[30];
u8 fzgx_obj_lbl_1_bss_26B7A;
u8 fzgx_obj_lbl_1_bss_26B7A__b1;
u8 fzgx_obj_lbl_1_bss_26B7A__b2;
u8 fzgx_obj_lbl_1_bss_26B7A__b3;
u8 fzgx_obj_lbl_1_bss_26B7A__b4;
u8 fzgx_obj_lbl_1_bss_26B7A__b5;
u32 fzgx_obj_lbl_1_bss_26B80[42];
u32 fzgx_obj_lbl_1_bss_26C28;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_1_bss_3C00;
    s = fzgx_obj_lbl_1_bss_3C04;
    s = ((0)[fzgx_obj_lbl_1_bss_3C08]);
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = fzgx_obj_lbl_1_bss_3C12__b1;
    s = fzgx_obj_lbl_1_bss_3C12__b2;
    s = fzgx_obj_lbl_1_bss_3C12__b3;
    s = fzgx_obj_lbl_1_bss_3C12__b4;
    s = fzgx_obj_lbl_1_bss_3C12__b5;
    s = fzgx_obj_lbl_1_bss_3C12__b6;
    s = fzgx_obj_lbl_1_bss_3C12__b7;
    s = fzgx_obj_lbl_1_bss_3C12__b8;
    s = fzgx_obj_lbl_1_bss_3C12__b9;
    s = fzgx_obj_lbl_1_bss_3C1C;
    s = ((0)[lbl_1_bss_3C1C__fzgx_offset_4]);
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = lbl_1_bss_3C2A__fzgx_offset_2;
    s = lbl_1_bss_3C2A__fzgx_offset_4;
    s = *(u32 *)&fzgx_obj_lbl_1_bss_3C30;
    s = ((0)[fzgx_obj_lbl_1_bss_50EC]);
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104;
    s = *(u32 *)&lbl_1_bss_5104__fzgx_offset_4;
    s = ((0)[fzgx_obj_lbl_1_bss_5138]);
    s = ((0)[fzgx_obj_lbl_1_bss_523C]);
    s = ((0)[fzgx_obj_lbl_1_bss_525C]);
    s = fzgx_obj_lbl_1_bss_53F4;
    s = ((0)[fzgx_obj_lbl_1_bss_53F8]);
    s = ((0)[fzgx_obj_lbl_1_bss_5480]);
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = ((0)[fzgx_obj_lbl_1_bss_25B88]);
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = ((0)[fzgx_obj_lbl_1_bss_25BA0]);
    s = ((0)[fzgx_obj_lbl_1_bss_25C48]);
    s = ((0)[fzgx_obj_lbl_1_bss_25CA4]);
    s = ((0)[fzgx_obj_lbl_1_bss_25CD0]);
    s = ((0)[fzgx_obj_lbl_1_bss_25E74]);
    s = ((0)[fzgx_obj_lbl_1_bss_25E90]);
    s = ((0)[fzgx_obj_lbl_1_bss_25E98]);
    s = ((0)[fzgx_obj_lbl_1_bss_25E9C]);
    s = ((0)[fzgx_obj_lbl_1_bss_2625C]);
    s = ((0)[fzgx_obj_lbl_1_bss_2627C]);
    s = fzgx_obj_lbl_1_bss_262F4;
    s = ((0)[fzgx_obj_lbl_1_bss_262F8]);
    s = fzgx_obj_lbl_1_bss_26300;
    s = ((0)[fzgx_obj_lbl_1_bss_26304]);
    s = ((0)[fzgx_obj_lbl_1_bss_26314]);
    s = ((0)[fzgx_obj_lbl_1_bss_26B04]);
    s = fzgx_obj_lbl_1_bss_26B18;
    s = fzgx_obj_lbl_1_bss_26B19;
    s = fzgx_obj_lbl_1_bss_26B1A;
    s = fzgx_pad_26B1B;
    s = fzgx_pad_26B1C;
    s = fzgx_obj_lbl_1_bss_26B1D;
    s = fzgx_obj_lbl_1_bss_26B1E;
    s = fzgx_obj_lbl_1_bss_26B1E__b1;
    s = fzgx_obj_lbl_1_bss_26B1E__b2;
    s = fzgx_obj_lbl_1_bss_26B1E__b3;
    s = fzgx_obj_lbl_1_bss_26B1E__b4;
    s = fzgx_obj_lbl_1_bss_26B1E__b5;
    s = fzgx_obj_lbl_1_bss_26B1E__b6;
    s = fzgx_obj_lbl_1_bss_26B1E__b7;
    s = fzgx_obj_lbl_1_bss_26B1E__b8;
    s = fzgx_obj_lbl_1_bss_26B1E__b9;
    s = fzgx_obj_lbl_1_bss_26B1E__b10;
    s = fzgx_obj_lbl_1_bss_26B1E__b11;
    s = fzgx_obj_lbl_1_bss_26B1E__b12;
    s = fzgx_obj_lbl_1_bss_26B1E__b13;
    s = fzgx_obj_lbl_1_bss_26B1E__b14;
    s = fzgx_obj_lbl_1_bss_26B1E__b15;
    s = fzgx_obj_lbl_1_bss_26B1E__b16;
    s = fzgx_obj_lbl_1_bss_26B1E__b17;
    s = fzgx_obj_lbl_1_bss_26B1E__b18;
    s = fzgx_obj_lbl_1_bss_26B1E__b19;
    s = fzgx_obj_lbl_1_bss_26B1E__b20;
    s = fzgx_obj_lbl_1_bss_26B1E__b21;
    s = fzgx_obj_lbl_1_bss_26B1E__b22;
    s = fzgx_obj_lbl_1_bss_26B1E__b23;
    s = fzgx_obj_lbl_1_bss_26B1E__b24;
    s = fzgx_obj_lbl_1_bss_26B1E__b25;
    s = fzgx_obj_lbl_1_bss_26B1E__b26;
    s = fzgx_obj_lbl_1_bss_26B1E__b27;
    s = fzgx_obj_lbl_1_bss_26B1E__b28;
    s = fzgx_obj_lbl_1_bss_26B1E__b29;
    s = fzgx_obj_lbl_1_bss_26B1E__b30;
    s = fzgx_obj_lbl_1_bss_26B1E__b31;
    s = fzgx_obj_lbl_1_bss_26B1E__b32;
    s = fzgx_obj_lbl_1_bss_26B1E__b33;
    s = fzgx_obj_lbl_1_bss_26B1E__b34;
    s = fzgx_obj_lbl_1_bss_26B1E__b35;
    s = fzgx_obj_lbl_1_bss_26B1E__b36;
    s = fzgx_obj_lbl_1_bss_26B1E__b37;
    s = fzgx_obj_lbl_1_bss_26B1E__b38;
    s = fzgx_obj_lbl_1_bss_26B1E__b39;
    s = fzgx_obj_lbl_1_bss_26B1E__b40;
    s = fzgx_obj_lbl_1_bss_26B1E__b41;
    s = fzgx_obj_lbl_1_bss_26B1E__b42;
    s = fzgx_obj_lbl_1_bss_26B1E__b43;
    s = fzgx_obj_lbl_1_bss_26B1E__b44;
    s = fzgx_obj_lbl_1_bss_26B1E__b45;
    s = fzgx_obj_lbl_1_bss_26B4C;
    s = fzgx_obj_lbl_1_bss_26B50;
    s = ((0)[fzgx_obj_lbl_1_bss_26B54]);
    s = ((0)[fzgx_obj_lbl_1_bss_26B5C]);
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_obj_lbl_1_bss_26B7A__b5;
    s = ((0)[fzgx_obj_lbl_1_bss_26B80]);
    s = fzgx_obj_lbl_1_bss_26C28;
}
#pragma section code_type ".text"

extern int fn_1_4C10(void);
extern void *fn_1_435C(void *);
extern s32 fn_1_3F8C(u32, u32, void *, u32);
extern GameElem9F8 lbl_1_bss_9F8[];
extern u8 lbl_1_data_5F5C[0x10];
extern u32 fn_1_2C908(void);
extern u32 lbl_1_rodata_BD8;
extern void fn_1_49F0(u32 *);
extern void fn_1_4A00(s32, u8, void *);
extern void *fn_1_86254(int);
extern u8 fn_1_86624(void);
extern void fn_1_40710(Fn40710Object *);

#pragma opt_propagation off
#pragma opt_common_subs off
int fn_1_2C97C(void) {
    u8 fzgx_value;
    u16 w12;
    u32 idx;
    s32 w10;
    Fn40710Object *obj;
    u16 w8;
    s32 f4;
    s32 f5;
    s16 i;
    s16 v;
    u32 msg;
    u16 *p12;
    u16 *p8;

    if (fn_1_4C10() != 0) {
        return 4;
    }
    obj = &lbl_1_bss_5104__fzgx_offset_4;
    if ((obj->flags & 1) != 0) {
        idx = ((0)[lbl_1_bss_3C1C__fzgx_offset_4]) * sizeof(GameElem9F8);
        w10 = *(u16 *)((u8 *)(&lbl_1_bss_9F8[0].unk_10) + idx);
        if ((w10 & 1) != 0 || ((p12 = &lbl_1_bss_9F8[0].unk_12, w12 = *(u16 *)((u8 *)p12 + idx)) & 1) != 0) {
            lbl_1_bss_5104__fzgx_offset_4.enabled = 0;
        } else if (((w10 >> 1) & 1) != 0 || ((w12 >> 1) & 1) != 0) {
            fzgx_value = 1;
            lbl_1_bss_5104__fzgx_offset_4.enabled = fzgx_value;
        } else {
            f4 = 0;
            p8 = &lbl_1_bss_9F8[0].unk_8;
            w8 = *(u16 *)((u8 *)p8 + idx);
            f5 = 0;
            if (((w8 >> 9) & 1) != 0 || ((w8 >> 12) & 1) != 0) {
                f4 = 1;
            } else if (((w8 >> 8) & 1) != 0) {
                if (obj->enabled == 0) {
                    f5 = 1;
                } else {
                    f4 = 1;
                }
            }
            if (f4 != 0 || f5 != 0) {
                if (f4) {
                    obj->flags |= 4;
                } else if (f5 != 0) {
                    obj->flags |= 2;
                    if (fzgx_obj_lbl_1_bss_3C2A == 41) {
                        fn_1_435C((void *)fzgx_obj_lbl_1_bss_5100);
                        fn_1_3F8C((u32)"replay_exit_gap", (u32)fn_1_2C908, 0, 13);
                        msg = lbl_1_rodata_BD8;
                        fn_1_49F0(&msg);
                        if (fzgx_obj_lbl_1_bss_3C10 != 0) {
                            fn_1_4A00(0, 0x78, (void *)fzgx_obj_lbl_1_bss_5100);
                        } else {
                            fn_1_4A00(0, 0x1E, (void *)fzgx_obj_lbl_1_bss_5100);
                        }
                        if (fzgx_obj_lbl_1_bss_3C30.unk_5 == 1) {
                            v = 0;
                            *(u8 *)((u8 *)fn_1_86254(0) + 0x475) = v;
                            v = -1;
                            for (i = 1; i < (s8)fn_1_86624(); i++) {
                                *(s8 *)((u8 *)fn_1_86254(i) + 0x475) = v;
                            }
                        }
                    }
                }
                fzgx_obj_lbl_1_bss_3C30.unk_C4 = 0;
                fzgx_obj_lbl_1_bss_5104 = -1;
            }
            fn_1_40710(&lbl_1_bss_5104__fzgx_offset_4);
        }
        return 4;
    }
    return 0;
}
#pragma opt_common_subs reset

#pragma opt_propagation reset
