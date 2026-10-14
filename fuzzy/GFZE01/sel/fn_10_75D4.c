/* Non-matching: best partial attempt (92.60% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Slot {
    u8 pad0[0xE];
    s16 unk_E;
    u8 pad1[0x20 - 0x10];
};

struct S8B3A0 {
    struct Slot slots[4];
    u8 pad_80[0x94 - 0x80];
    u32 unk_94;
    u32 unk_98;
    u8 pad_9C[2];
    u8 unk_9E;
    u8 pad_9F[0x129 - 0x9F];
    u8 unk_129;
    u8 pad_12A[0x140 - 0x12A];
    u32 unk_140;
};

typedef struct {
    u8 *at_0;
} Data_lbl_10_rodata_90;

extern struct S8B3A0 lbl_1_bss_8B3A0;
extern u32 lbl_801A63C0;
extern u32 lbl_1_bss_6D82C;
extern u8 lbl_10_bss_0[];
extern u32 lbl_10_bss_3C0[74736];
extern u8 lbl_10_data_0[];
extern const Data_lbl_10_rodata_90 lbl_10_rodata_90;

extern u32 fn_1_128B00(s16);
extern s16 fn_1_14F270(s32, s32, u32);
extern u32 fn_1_151BE8(u8, s32);
extern void fn_1_12F10C(void *);
extern void fn_1_12AB38(void *);
extern void * fn_1_D3884(void *);
extern void fn_10_948C(void *, u32);
extern s16 fn_1_A5D88(void);
extern void fn_1_12BF7C(void *, s32, u16, s32);
extern s16 fn_1_12C930(u8);
extern u32 fn_1_8F198(void *, s32, u32, u32);
extern s16 fn_1_12CCB0(s32, s16);
extern s16 fn_1_12CB04(s32);
extern u32 fn_1_12E0B8(u8, s32, void *, void *, s32, void *, s32);
extern void * fn_1_435C(u32);
extern u32 fn_10_1AD5C(void);
extern s32 fn_1_3F8C(void *, u32, s32, s32);
extern u32 fn_1_12F1E8(s32);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_A2D84(u32);

#pragma opt_propagation on
#pragma opt_common_subs on
extern void OSReport(const char *, ...);
static u32 fzgx_data_lbl_10_data_0[0x1c4] = {  /* fzgx-allow: A1 retail data bytes: the TU's .data objects before its string literals; dropped at integration */
    0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156,
    0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x00000000, 0x54455354,
    0x00000000, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000,
    0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000,
    0x554E4C49, 0x4E4B0000, 0x434F494E, 0x00000000, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C,
    0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000,
    0x454E5452, 0x595F4F4B, 0x00000000, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348,
    0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552,
    0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500,
    0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000,
    0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x00000000, 0x4C494E4B,
    0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152,
    0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x00000000, 0x4C494E4B, 0x44454C49, 0x56455259,
    0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552,
    0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900,
    0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x00000000, 0x50415553, 0x45000000, 0x4552524F, 0x52000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010001, 0x00010001, 0x01010101,
    0x00010101, 0x01010000, 0x00010000, 0x01010101, 0x01010001, 0x01010101, 0x01010101, 0x01010101,
    0x01010000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x0029001F, 0x00200006, 0x00020005, 0x00040001, 0x00210022,
    0x002DFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF002A, 0x00030007, 0x00080009, 0x0000000A,
    0x000B000C, 0x000D002E, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x002B000E, 0x000F0010,
    0x00110012, 0x00130014, 0x00150016, 0x002FFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF002C,
    0x00230024, 0x00170018, 0x0019001A, 0x001B0025, 0x00260030, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFF0036, 0x00370027, 0x001C001D, 0x001E0028, 0x00380039, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0x0031FFFF, 0x0002FFFF, 0x0005FFFF, 0x0024FFFF, 0x0020FFFF, 0x0021FFFF,
    0x0022FFFF, 0x001FFFFF, 0x002EFFFF, 0x0030FFFF, 0x0006FFFF, 0x0004FFFF, 0x0028FFFF, 0x0027FFFF,
    0x0023FFFF, 0x0025FFFF, 0x0026FFFF, 0x002DFFFF, 0x002FFFFF, 0x00010001, 0x00010004, 0x40000000,
    0x02000401, 0x01000801, 0x01000201, 0x01000011, 0x01000201, 0x01001001, 0x01004001, 0x01000201,
    0x01002001, 0x01000801, 0x01000011, 0xFFFFFFFF, 0x02000011, 0x01000401, 0x01000201, 0x01000401,
    0x01000201, 0x01001001, 0x01000401, 0x01008001, 0x01000201, 0x01000801, 0x01001001, 0xFFFFFFFF,
    0x02000801, 0x01000011, 0x01000201, 0x01002001, 0x01000401, 0x01004001, 0x01000201, 0x01000011,
    0x01004001, 0x01000401, 0x01000201, 0xFFFFFFFF, 0x01001003, 0x01000203, 0x01000013, 0x01002003,
    0x01000803, 0x01000803, 0x01004003, 0x01004003, 0xFFFFFFFF, 0x01004003, 0x01000403, 0x01000803,
    0x01004003, 0x01000013, 0x01000203, 0x01008003, 0x01001003, 0xFFFFFFFF, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000005, 0x00000000, 0x00060002, 0x00050004, 0x00060002,
    0x00050004, 0xFFFFFFFF, 0xFFFFFFFF, 0x4341525F, 0x53454C00, 0x00000000, 0xFFFFFFFF, 0x73656C2E,
    0x63000000, 0x57726F6E, 0x67204361, 0x724D6170, 0x20636F6C, 0x20726F77, 0x0A000000, 0x76656869,
    0x636C652F, 0x76656869, 0x636C655F, 0x73656C2E, 0x6172632E, 0x6C7A0000, 0x76656869, 0x636C6520,
    0x61726368, 0x69766520, 0x66696C65, 0x20697320, 0x6E6F7468, 0x696E6700, 0x4C696768, 0x744D6169,
    0x6E000000, 0x41562020, 0x20000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x53656C4D,
    0x6F646544, 0x69737000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x53656C43,
    0x6F757273, 0x65446973, 0x70000000, 0x53656C43, 0x61724D61, 0x70446973, 0x70000000, 0x53656C53,
    0x74617274, 0x596F7572, 0x456E6769, 0x6E654469, 0x73700000, 0x53656C52, 0x65636F72, 0x64446973,
    0x70000000, 0x53656C43, 0x6F6D4469, 0x73700000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x53454C5F, 0x57414954, 0x00000000, 0x53656C4D,
    0x61674361, 0x72644368, 0x65636B44, 0x69737000,
};

#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("vehicle/");
    OSReport("carcmntex.tpl");
    OSReport("..");
    OSReport("SelMagCardDataDisp");
}
#pragma section code_type ".text"

u32 fn_10_75D4(void) {
    struct S8B3A0 *p_lbl_1_bss_8B3A0;
    u8 *p_lbl_10_bss_0;
    struct { s16 value; } slot;
    u32 unk_9E;
    struct { s16 value; } v3;
    u32 seed;
    struct { s16 value; } i;
    s16 j;
    struct { u8 *value; } p_lbl_10_bss_3C0;
    s32 lab_t1;
    s32 tmp_call7;
    s16 lab_t1_;
    u8 * buf2;
    u8 * p2;

    p_lbl_1_bss_8B3A0 = &lbl_1_bss_8B3A0;
    unk_9E = p_lbl_1_bss_8B3A0->unk_9E;
    p_lbl_10_bss_0 = (u8 *)&lbl_10_bss_0;
    seed = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
{
    u8 *mgr;
    mgr = p_lbl_10_bss_0 + 0x50000;
    lbl_801A63C0 = seed;
    
    *(u32 *)(mgr + 0x55FC) = 1;
    v3.value = (s16)((seed >> 16) & 3);

    if ((p_lbl_1_bss_8B3A0->unk_94 & 0x40000000) == 0) {
        *(u32 *)(((0x40e00) + ((u8 *)lbl_10_bss_3C0))) &= 0x3FFFFFFF;
    } else {
        u32 state = *(u32 *)(((0x40e00) + ((u8 *)lbl_10_bss_3C0)));
        if (!(state & 0x80000000) || !(state & 0x40000000)) {
            void *v11;
            void *v13;
            p_lbl_10_bss_3C0.value = (u8 *)&lbl_10_bss_3C0;
            *(u32 *)(p_lbl_10_bss_3C0.value + 0x40e00) |= (3U << 30);
            *(u8 *)(p_lbl_10_bss_3C0.value + 0x40e05) = 0x31;
            v11 = p_lbl_10_bss_3C0.value;
            for (i.value = 0; i.value < 3; i.value++) {
                s32 t0 = fn_1_128B00(i.value);
                s16 t1 = fn_1_14F270(t0, i.value, 1U << 31);
                *(u8 *)((u8 *)v11 + 0x50000 - 0x705c) = t1;
                v11 = (u8 *)v11 + 8;
            }
            *(u8 *)(p_lbl_10_bss_3C0.value + 0x50000 - 0x7060) = fn_1_128B00(i.value);
            v11 = p_lbl_10_bss_3C0.value;
            {
    s16 fzgx_loop_i_2791;
for (fzgx_loop_i_2791 = 0; fzgx_loop_i_2791 < 3; fzgx_loop_i_2791++) {
                v13 = v11;
                for (j = 0; j < 1; j++) {
                    u32 t3 = fn_1_151BE8(*(u8 *)((u8 *)v11 + 0x50000 - 0x705c), j);
                    *(u32 *)((u8 *)v13 + 0x50000 - 0x7058) = t3;
                    v13 = (u8 *)v13 + 4;
                }
                v11 = (u8 *)v11 + 8;
            }
    i.value = fzgx_loop_i_2791;
}
        }
    }

    if ((p_lbl_1_bss_8B3A0->unk_94 & 0x40000000) != 0) {
        void *v17 = (u8 *)&lbl_10_bss_3C0;
        for (i.value = 0; i.value < 3; i.value++) {
            s32 k = v3.value;
            void *v20 = v17;
            {
    s16 fzgx_loop_j_3669;
for (fzgx_loop_j_3669 = 0; fzgx_loop_j_3669 < 1; fzgx_loop_j_3669++) {
                u32 t4 = fn_1_151BE8(*(u8 *)((u8 *)v17 + 0x50000 - 0x705c), (s16)k);
                *(u32 *)((u8 *)v20 + 0x50000 - 0x7058) = t4;
                k++;
                v20 = (u8 *)v20 + 4;
            }
    j = fzgx_loop_j_3669;
}
            v17 = (u8 *)v17 + 8;
        }
        fn_1_12F10C(lbl_10_bss_3C0);
    }

    if (lbl_1_bss_6D82C == 0) {
        fn_1_12AB38((u8 *)"vehicle/");
        lbl_1_bss_6D82C = (u32)fn_1_D3884((u8 *)"(slot = carcmntex.tpl)");
        fn_1_12AB38((u8 *)"..");
    }

    fn_10_948C(mgr - 0x6c60, 0);

    slot.value = unk_9E;
    lbl_1_bss_8B3A0.slots[slot.value].unk_E = 0x31;

    if (!(p_lbl_1_bss_8B3A0->unk_94 & 0x80000000)) {
        fn_1_12BF7C(mgr + 0x17ec, 1, fn_1_A5D88(), 0x1e0);
        fn_1_12BF7C(mgr + 0x197c, 1, fn_1_A5D88(), 0x1e0);
    }

    if (!(p_lbl_1_bss_8B3A0->unk_94 & 0x80000000)) {
        void *table = lbl_10_rodata_90.at_0;
        u32 flag;
        s16 val;
        u8 *buf1;

        switch (v3.value) {
        case 0:
            flag = 1U << 31;
            break;
        case 1:
            flag = 1U << 30;
            break;
        case 2:
            flag = 1U << 29;
            break;
        case 3:
            flag = 1U << 28;
            break;
        default:
            flag = 1U << 31;
            break;
        }

        val = fn_1_12C930(*(u8 *)((u8 *)&lbl_10_bss_3C0 + 0x48fa0));
        buf1 = mgr + 0x1b7c;
        buf1 += slot.value * 0x4e0;
        lab_t1 = val;
        lab_t1_ = lab_t1;
        fn_1_8F198(buf1, lab_t1_, 1U << 31, flag);

        buf2 = mgr + 0x2efc;
        buf2 += slot.value * 0x9c0;
        p2 = buf2;
        for (i.value = 0; i.value < fn_1_12CB04(0x31); i.value++) {
            tmp_call7 = fn_1_12CCB0(0x31, i.value);
            lab_t1 = tmp_call7;
            lab_t1_ = lab_t1;
            fn_1_8F198(p2, lab_t1_, 1U << 31, flag);
            p2 += 0x4e0;
        }

        fn_1_12E0B8(unk_9E, 0x31, buf1, buf2, 0, &table, 1);
    }

    fn_1_435C(*(u32 *)(mgr - 0x6c78));
    *(u32 *)(mgr + 0x1740) = fn_1_3F8C((u8 *)"SelMagCardDataDisp", (u32)fn_10_1AD5C, 0, 8);
    if (*(s32 *)(mgr + 0x55fc) == 1) {
        fn_1_12F1E8(0x1e0);
    } else {
        fn_1_12F1E8(0xf0);
    }
    fn_1_4A00(1, (u8)*(s16 *)(mgr - 0x6c74), *(u32 *)(mgr - 0x6c78));
    *(u32 *)(mgr + 0x1744) = 0;
}
    *(s32 *)(p_lbl_10_bss_0 + 0x14) = -1;
    fn_1_A2D84(0xa9100100);
    p_lbl_1_bss_8B3A0->unk_94 |= 0x800;
    lbl_1_bss_8B3A0.unk_129 = 1;
    return (u32)unk_9E;
}
#pragma opt_common_subs reset

#pragma opt_propagation reset

