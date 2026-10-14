/* Non-matching: best partial attempt (68.18% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_14C35C_lbl_1_data_42878 {
    u8 pad_0[0x600];
    u16 unk_600[29];
    u8 pad_63A[2];
    u16 unk_63C[29];
    u8 pad_676[2];
    u16 unk_678[33];
    u8 pad_6BA[2];
    u16 unk_6BC[13];
    u8 pad_6D6[2];
    u8 unk_6D8[29];
    u8 pad_6F5[3];
    u8 unk_6F8[29];
    u8 pad_715[3];
    u8 unk_718[33];
    u8 pad_739[3];
    u8 unk_73C[13];
    u8 pad_749[3];
    u32 unk_74C;
    u32 unk_750;
    u8 pad_754[0x1C];
    u32 unk_770;
    u32 unk_774;
    u8 pad_778[0x1C];
    char unk_794[4];
};

struct fn_1_14C35C_lbl_1_bss_8E518 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0xC];
    f32 unk_18;
    u8 pad_1C[0x4];
    u32 unk_20;
    u8 pad_24[0xC];
    u8 unk_30;
    u8 pad_31[0xF];
    u8 unk_40;
    u8 unk_41;
    u8 pad_42[0xA];
    u32 unk_4C;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    u32 unk_5C;
    u8 pad_60[0x14];
    u32 unk_74;
    s32 unk_78;
};

extern char * fn_80083DB0(char *, const char *);
extern char * strncpy(char *, const char *, size_t);
extern size_t strlen(const char *);
extern struct fn_1_14C35C_lbl_1_bss_8E518 lbl_1_bss_8E518;
extern struct fn_1_14C35C_lbl_1_data_42878 lbl_1_data_42878;
extern u32 fn_1_1556B4(u32, u32);
extern s32 fn_1_155F7C(void);
extern u32 fn_1_155F8C(void);
extern u32 fn_1_155FB4(const char *);
extern u32 lbl_1_bss_3C04;
extern u32 lbl_1_bss_718E0;
extern u32 lbl_801A66B4;

void fn_1_14C35C(void)
{
    struct fn_1_14C35C_lbl_1_bss_8E518 *p_state = (struct fn_1_14C35C_lbl_1_bss_8E518 *)&lbl_1_bss_8E518;
    struct fn_1_14C35C_lbl_1_data_42878 *p_data = (struct fn_1_14C35C_lbl_1_data_42878 *)&lbl_1_data_42878;
    u8 *kp;
    u8 *src;
    u8 *dst;
    u32 buf[8];
    u32 i;
    u16 *res;
    u32 c;
    s32 value;

    p_state->unk_40 = 42;
    p_state->unk_41 = 0;
    fn_1_1556B4(42, 0);
    p_state->unk_4C = 0;
    if ((s32)lbl_801A66B4 == 5) {
        p_state->unk_50 = p_data->unk_74C;
        p_state->unk_54 = *(u32 *)((u8 *)&p_data->unk_74C + 4);
    } else {
        p_state->unk_50 = p_data->unk_770;
        p_state->unk_54 = *(u32 *)((u8 *)&p_data->unk_770 + 4);
    }
    kp = (u8 *)p_state + 0x60;
    for (i = 0; i < 19; i++) {
        *kp++ = 0;
    }
    p_state->unk_58 = 0;
    p_state->unk_5C = p_state->unk_54 - 1;
    strncpy((char *)((u8 *)p_state + 0x60), (const char *)((u8 *)&lbl_1_bss_718E0 + 0x5522), strlen((const char *)((u8 *)&lbl_1_bss_718E0 + 0x5522)));
    p_state->unk_4C = strlen((const char *)((u8 *)&lbl_1_bss_718E0 + 0x5522)) >> 1;
    if ((s32)lbl_801A66B4 != 5) {
        p_state->unk_4C = strlen((const char *)((u8 *)&lbl_1_bss_718E0 + 0x5522));
        fn_80083DB0((char *)buf, (const char *)((u8 *)p_state + 0x60));
        src = (u8 *)buf;
        dst = (u8 *)p_state + 0x60;
        while ((c = *src) != 0) {
            if (c < 128) {
                kp = p_data->unk_6D8;
                for (i = 0; i < 29; i++) {
                    /* goto leaves the four-table chain on the first key match */
                    if (c == *kp) {
                        res = (u16 *)((u8 *)&p_data->unk_600 + (i << 1));
                        goto found;
                    }
                    kp++;
                }
                kp = p_data->unk_6F8;
                for (i = 0; i < 29; i++) {
                    /* goto leaves the four-table chain on the first key match */
                    if (c == *kp) {
                        res = (u16 *)((u8 *)&p_data->unk_63C + (i << 1));
                        goto found;
                    }
                    kp++;
                }
                kp = p_data->unk_718;
                for (i = 0; i < 33; i++) {
                    /* goto leaves the four-table chain on the first key match */
                    if (c == *kp) {
                        res = (u16 *)((u8 *)&p_data->unk_678 + (i << 1));
                        goto found;
                    }
                    kp++;
                }
                kp = p_data->unk_73C;
                for (i = 0; i < 13; i++) {
                    /* goto leaves the four-table chain on the first key match */
                    if (c == *kp) {
                        res = (u16 *)((u8 *)&p_data->unk_6BC + (i << 1));
                        goto found;
                    }
                    kp++;
                }
                res = 0;
found:
                if (res != 0) {
                    strncpy((char *)dst, (const char *)res, 2);
                    dst += 2;
                }
                src += 1;
            } else {
                strncpy((char *)dst, (const char *)src, 2);
                dst += 2;
                src += 2;
            }
        }
        *dst = 0;
    }
    if ((s32)p_state->unk_4C == 0) {
        p_state->unk_5C = 0;
    }
    if ((s32)p_state->unk_8 != 0) {
        if (fn_1_155F7C() != 0) {
            p_state->unk_8 = 0;
            p_state->unk_74 = 1;
            p_state->unk_78 = fn_1_155F8C();
            fn_1_155FB4(p_data->unk_794);
            value = p_state->unk_78 - 2;
            lbl_1_bss_3C04 = 1860;
            if (value < 0) {
                value = 0;
            } else {
                if (p_state->unk_78 - 2 > 10 - p_state->unk_30) {
                    value = 10 - p_state->unk_30;
                } else {
                    value = p_state->unk_78 - 2;
                }
            }
            p_state->unk_20 = value;
            p_state->unk_18 = (f32)value;
        } else {
            p_state->unk_8 = 0;
            p_state->unk_74 = 0;
            lbl_1_bss_3C04 = 660;
        }
    }
}
