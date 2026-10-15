/* Non-matching: best partial attempt (96.03% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct GameEntryC {
    u8 data[0xA0];
} GameEntryC;

typedef struct GameStateC {
    u32 flags;
    u8 pad_4[5];
    u8 unk_9;
    u8 pad_A[0x9D];
    u8 unk_A7;
    u8 pad_A8[0x2C];
    GameEntryC entries[31];
    u8 pad_1434[0x30];
    u32 unk_1464;
    u8 pad_1468[0x4];
    u8 unk_146C;
    u8 unk_146D;
    s16 unk_146E;
    u8 unk_1470;
    u8 pad_1471[0x47];
} GameStateC;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 fzgx_obj_lbl_1_bss_3C08[2];
u8 fzgx_obj_lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u16 fzgx_obj_lbl_1_bss_3C12;
u32 lbl_1_bss_3C12__fzgx_offset_2;
u32 lbl_1_bss_3C12__fzgx_offset_6;
u32 fzgx_obj_lbl_1_bss_3C1C;
u8 lbl_1_bss_3C1C__fzgx_offset_4[10];
u8 fzgx_obj_lbl_1_bss_3C2A;
u8 fzgx_obj_lbl_1_bss_3C2A__b1;
u8 fzgx_obj_lbl_1_bss_3C2A__b2;
u8 fzgx_obj_lbl_1_bss_3C2A__b3;
u8 fzgx_obj_lbl_1_bss_3C2A__b4;
u8 fzgx_obj_lbl_1_bss_3C2A__b5;
GameStateC fzgx_obj_lbl_1_bss_3C30;
s16 lbl_1_bss_3C30__fzgx_offset_14B8;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
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
u32 fzgx_obj_lbl_1_bss_25BA0[2];
u8 lbl_1_bss_25BA0__fzgx_offset_8[0x20];
u8 lbl_1_bss_25BA0__fzgx_offset_28[0x20];
u32 lbl_1_bss_25BA0__fzgx_offset_48[24];
u32 fzgx_obj_lbl_1_bss_25C48[23];
u32 fzgx_obj_lbl_1_bss_25CA4;
u32 lbl_1_bss_25CA4__fzgx_offset_4;
u32 lbl_1_bss_25CA4__fzgx_offset_8;
u32 lbl_1_bss_25CA4__fzgx_offset_C;
u32 lbl_1_bss_25CA4__fzgx_offset_10;
u32 lbl_1_bss_25CA4__fzgx_offset_14;
u32 lbl_1_bss_25CA4__fzgx_offset_18;
u32 lbl_1_bss_25CA4__fzgx_offset_1C;
u32 lbl_1_bss_25CA4__fzgx_offset_20;
u32 lbl_1_bss_25CA4__fzgx_offset_24;
u32 lbl_1_bss_25CA4__fzgx_offset_28;
u32 fzgx_obj_lbl_1_bss_25CD0[97];
u32 lbl_1_bss_25CD0__fzgx_offset_184;
u32 lbl_1_bss_25CD0__fzgx_offset_188;
u32 lbl_1_bss_25CD0__fzgx_offset_18C;
u32 lbl_1_bss_25CD0__fzgx_offset_190;
u32 lbl_1_bss_25CD0__fzgx_offset_194;
u32 lbl_1_bss_25CD0__fzgx_offset_198;
s32 lbl_1_bss_25CD0__fzgx_offset_19C;
s32 lbl_1_bss_25CD0__fzgx_offset_1A0;
u32 fzgx_obj_lbl_1_bss_25E74[2];
s32 lbl_1_bss_25E74__fzgx_offset_8;
s32 lbl_1_bss_25E74__fzgx_offset_C;
s32 lbl_1_bss_25E74__fzgx_offset_10;
u32 lbl_1_bss_25E74__fzgx_offset_14;
u32 lbl_1_bss_25E74__fzgx_offset_18;
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
    s = fzgx_obj_lbl_1_bss_3C08[0];
    s = fzgx_obj_lbl_1_bss_3C10;
    s = fzgx_obj_lbl_1_bss_3C11;
    s = fzgx_obj_lbl_1_bss_3C12;
    s = lbl_1_bss_3C12__fzgx_offset_2;
    s = lbl_1_bss_3C12__fzgx_offset_6;
    s = fzgx_obj_lbl_1_bss_3C1C;
    s = lbl_1_bss_3C1C__fzgx_offset_4[0];
    s = fzgx_obj_lbl_1_bss_3C2A;
    s = fzgx_obj_lbl_1_bss_3C2A__b1;
    s = fzgx_obj_lbl_1_bss_3C2A__b2;
    s = fzgx_obj_lbl_1_bss_3C2A__b3;
    s = fzgx_obj_lbl_1_bss_3C2A__b4;
    s = fzgx_obj_lbl_1_bss_3C2A__b5;
    s = *(u32 *)&fzgx_obj_lbl_1_bss_3C30;
    s = lbl_1_bss_3C30__fzgx_offset_14B8;
    s = fzgx_obj_lbl_1_bss_50EC[0];
    s = fzgx_obj_lbl_1_bss_5100;
    s = fzgx_obj_lbl_1_bss_5104[0];
    s = fzgx_obj_lbl_1_bss_5138[0];
    s = fzgx_obj_lbl_1_bss_523C[0];
    s = fzgx_obj_lbl_1_bss_525C[0];
    s = fzgx_obj_lbl_1_bss_53F4;
    s = fzgx_obj_lbl_1_bss_53F8[0];
    s = fzgx_obj_lbl_1_bss_5480[0];
    s = fzgx_obj_lbl_1_bss_25B80;
    s = fzgx_obj_lbl_1_bss_25B84;
    s = fzgx_obj_lbl_1_bss_25B88[0];
    s = fzgx_obj_lbl_1_bss_25B98;
    s = fzgx_obj_lbl_1_bss_25B9C;
    s = fzgx_obj_lbl_1_bss_25BA0[0];
    s = lbl_1_bss_25BA0__fzgx_offset_8[0];
    s = lbl_1_bss_25BA0__fzgx_offset_28[0];
    s = lbl_1_bss_25BA0__fzgx_offset_48[0];
    s = fzgx_obj_lbl_1_bss_25C48[0];
    s = fzgx_obj_lbl_1_bss_25CA4;
    s = lbl_1_bss_25CA4__fzgx_offset_4;
    s = lbl_1_bss_25CA4__fzgx_offset_8;
    s = lbl_1_bss_25CA4__fzgx_offset_C;
    s = lbl_1_bss_25CA4__fzgx_offset_10;
    s = lbl_1_bss_25CA4__fzgx_offset_14;
    s = lbl_1_bss_25CA4__fzgx_offset_18;
    s = lbl_1_bss_25CA4__fzgx_offset_1C;
    s = lbl_1_bss_25CA4__fzgx_offset_20;
    s = lbl_1_bss_25CA4__fzgx_offset_24;
    s = lbl_1_bss_25CA4__fzgx_offset_28;
    s = fzgx_obj_lbl_1_bss_25CD0[0];
    s = lbl_1_bss_25CD0__fzgx_offset_184;
    s = lbl_1_bss_25CD0__fzgx_offset_188;
    s = lbl_1_bss_25CD0__fzgx_offset_18C;
    s = lbl_1_bss_25CD0__fzgx_offset_190;
    s = lbl_1_bss_25CD0__fzgx_offset_194;
    s = lbl_1_bss_25CD0__fzgx_offset_198;
    s = lbl_1_bss_25CD0__fzgx_offset_19C;
    s = lbl_1_bss_25CD0__fzgx_offset_1A0;
    s = fzgx_obj_lbl_1_bss_25E74[0];
    s = lbl_1_bss_25E74__fzgx_offset_8;
    s = lbl_1_bss_25E74__fzgx_offset_C;
    s = lbl_1_bss_25E74__fzgx_offset_10;
    s = lbl_1_bss_25E74__fzgx_offset_14;
    s = lbl_1_bss_25E74__fzgx_offset_18;
    s = fzgx_obj_lbl_1_bss_25E90[0];
    s = fzgx_obj_lbl_1_bss_25E98[0];
    s = fzgx_obj_lbl_1_bss_25E9C[0];
    s = fzgx_obj_lbl_1_bss_2625C[0];
    s = fzgx_obj_lbl_1_bss_2627C[0];
    s = fzgx_obj_lbl_1_bss_262F4;
    s = fzgx_obj_lbl_1_bss_262F8[0];
    s = fzgx_obj_lbl_1_bss_26300;
    s = fzgx_obj_lbl_1_bss_26304[0];
    s = fzgx_obj_lbl_1_bss_26314[0];
    s = fzgx_obj_lbl_1_bss_26B04[0];
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
    s = fzgx_obj_lbl_1_bss_26B54[0];
    s = fzgx_obj_lbl_1_bss_26B5C[0];
    s = fzgx_obj_lbl_1_bss_26B7A;
    s = fzgx_obj_lbl_1_bss_26B7A__b1;
    s = fzgx_obj_lbl_1_bss_26B7A__b2;
    s = fzgx_obj_lbl_1_bss_26B7A__b3;
    s = fzgx_obj_lbl_1_bss_26B7A__b4;
    s = fzgx_obj_lbl_1_bss_26B7A__b5;
    s = fzgx_obj_lbl_1_bss_26B80[0];
    s = fzgx_obj_lbl_1_bss_26C28;
}
#pragma section code_type ".text"

extern u32 fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_1_105724(void);
extern void fn_1_F2EDC(void);
extern void fn_1_A8F78(void);
extern s32 fn_1_1547FC(void *, u32);
extern void fn_1_C47B4(void);
extern void fn_1_C6F80(u8);
extern void fn_1_79100(void);
extern void fn_1_412A0(u32);
extern void fn_1_E35F0(void);
extern u32 fn_80008E84(u32);

static inline void game_copy_names(void) {
    s32 i;
    for (i = 0; i < fzgx_obj_lbl_1_bss_3C30.unk_9; i++) {
        u8 *d = fzgx_obj_lbl_1_bss_3C30.entries[i].data;
        d[fzgx_obj_lbl_1_bss_3C30.unk_A7 + 0xE] = lbl_1_bss_25BA0__fzgx_offset_8[i];
        d[fzgx_obj_lbl_1_bss_3C30.unk_A7 + 0x13] = lbl_1_bss_25BA0__fzgx_offset_28[i];
    }
}

void fn_1_3AEC4(void) {
    u32 v;

    fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
    if (lbl_1_bss_25E74__fzgx_offset_8 != -1) {
        fn_1_426C(lbl_1_bss_25E74__fzgx_offset_8);
    }
    if (lbl_1_bss_25E74__fzgx_offset_C != -1) {
        fn_1_426C(lbl_1_bss_25E74__fzgx_offset_C);
        fn_1_105724();
    }
    fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
    if (lbl_1_bss_25E74__fzgx_offset_10 != -1) {
        fn_1_426C(lbl_1_bss_25E74__fzgx_offset_10);
    }
    lbl_1_bss_25E74__fzgx_offset_8 = -1;
    lbl_1_bss_25E74__fzgx_offset_C = -1;
    lbl_1_bss_25E74__fzgx_offset_10 = -1;
    if (fzgx_obj_lbl_1_bss_3C30.flags & 0x800000) {
        if (lbl_1_bss_3C30__fzgx_offset_14B8 != 0x2A) {
            fn_1_F2EDC();
        }
    }
    fn_1_A8F78();
    if (lbl_1_bss_25CD0__fzgx_offset_19C != 0) {
        lbl_1_bss_25CD0__fzgx_offset_1A0 = 1;
    }
    if (lbl_1_bss_25CD0__fzgx_offset_1A0 != 0) {
        game_copy_names();
        fzgx_obj_lbl_1_bss_3C30.unk_1464 = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_146C = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_146D = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_1470 = 0;
        fzgx_obj_lbl_1_bss_3C30.unk_146E = 0x5DC;
        fn_1_1547FC(&fzgx_obj_lbl_1_bss_3C30, 0);
        fn_1_C47B4();
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
        if (lbl_1_bss_3C12__fzgx_offset_2 != 0) {
            fn_1_426C(lbl_1_bss_3C12__fzgx_offset_2);
            lbl_1_bss_3C12__fzgx_offset_2 = 0;
        }
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        if (lbl_1_bss_3C12__fzgx_offset_6 != 0) {
            fn_1_426C(lbl_1_bss_3C12__fzgx_offset_6);
            lbl_1_bss_3C12__fzgx_offset_6 = 0;
        }
        fn_1_C6F80(0);
        v = fn_80008E84(lbl_1_bss_25CA4__fzgx_offset_28);
        fn_1_79100();
        fn_80008E84(v);
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(fzgx_obj_lbl_1_bss_25B88[0]);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_10);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_14);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_194);
        fn_1_435C(fzgx_obj_lbl_1_bss_25CA4);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_4);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_8);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_C);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_18);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_1C);
        fn_1_426C(lbl_1_bss_25CA4__fzgx_offset_20);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_188);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_18C);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_190);
        fn_1_426C(lbl_1_bss_25CD0__fzgx_offset_184);
    }
    if (lbl_1_bss_25CD0__fzgx_offset_19C != 0) {
        fzgx_obj_lbl_1_bss_3C30.unk_A7++;
    }
}
