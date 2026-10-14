/* Non-matching: best partial attempt (73.05% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern s32 lbl_801A66B4;
extern u8 lbl_4_data_0[0xC];

struct fn_4_3128_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x6];
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 unk_12;
    u8 pad_13[0x45];
    u8 unk_58;
    u8 unk_59;
    u8 unk_5A;
    u8 unk_5B;
    u8 unk_5C;
    u8 unk_5D;
};

extern struct fn_4_3128_lbl_4_bss_0 lbl_4_bss_0;

extern void fn_1_49410(void);
extern void fn_1_495C8(u8);
extern void fn_1_49738(u32);
extern void fn_1_5233C(void);
extern void fn_1_49748(f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_53E40(u32, u32, f32, f32, f32, f32, f32);
extern void fn_4_2D4(u32, u32, u32);
extern void fn_4_18B8(void);
extern void fn_4_28FC(void);
extern int sprintf(char *, const char *, ...);
extern void fn_1_1380F0(void *);
extern u32 fn_1_13ABA8(u32);

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[2] = {0, 0};
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s;
    s = 0.5f;
}
static const u32 fzgx_pool_table3[15] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s;
    s = 5.0f;
}
static const u32 fzgx_pool_table5[1] = {0};
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s;
    s = 320.0f;
    s = 240.0f;
}
static const u32 fzgx_pool_table7[25] = {
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0
};
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s;
    s = 0.05f;
    s = 48.0f;
    s = 0.8f;
}
static const u32 fzgx_pool_table9[1] = {0};
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s;
    s = 1.0f;
}
static const u32 fzgx_pool_table11[65] = {
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0
};
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s;
    s = 368.8f;
    s = 38.4f;
    s = 0.7f;
    s = 136.7f;
}

#define TBL(off) (*(u32 *)((u8 *)p_data + (off) + (lbl_801A66B4 << 2)))

#pragma section code_type ".text"

void fn_4_3128(void) {
    struct fn_4_3128_lbl_4_bss_0 *p = (struct fn_4_3128_lbl_4_bss_0 *)&lbl_4_bss_0;
    u8 *p_data = lbl_4_data_0;
    u32 v;
    u32 ret;
    char buf[0x200];

    v = TBL(0x1a4);
    ret = 0x2000;
    fn_1_49410();
    fn_1_495C8(1);
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(5.0f);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000U);
        fn_1_49590(0.5f);
    }
    switch (p->unk_5A) {
    case 0:
        ret = 0x2800;
        v = TBL(0x23c);
        fn_1_53E40(0, TBL(0x6bc), 320.0f, 240.0f, 0.05f, 48.0f, 1.0f);
        break;
    case 1:
        if (p->unk_5B == 0) {
            ret = 0;
            v = TBL(0x1a4);
        } else {
            u32 w = TBL(0xe8);
            ret = 0x4800;
            v = w;
            fn_4_2D4(p->unk_5C & 1, TBL(0x884), w);
        }
        break;
    case 2:
        switch (p->unk_12) {
        case 0:
            ret = 0x4800;
            v = TBL(0x2b4);
            fn_1_53E40(0, TBL(0xc00), 320.0f, 368.8f, 0.05f, 38.4f, 0.7f);
            fn_4_18B8();
            break;
        case 1:
            ret = 0x2800;
            v = TBL(0x314);
            fn_1_53E40(0, TBL(0xd38), 320.0f, 136.7f, 0.05f, 38.4f, 0.8f);
            fn_4_28FC();
            break;
        }
        break;
    case 3:
        {
            u32 w = TBL(0xe8);
            ret = 0x4800;
            v = w;
            fn_4_2D4(p->unk_5C, TBL(0x8c0), w);
        }
        switch (p->unk_12) {
        case 0:
            fn_4_18B8();
            break;
        case 1:
            fn_4_28FC();
            break;
        }
        break;
    case 4:
        {
            u8 k = p->unk_5D;
            ret = 0;
            v = (u32)(p_data + 0xC);
            fn_1_49410();
            fn_1_49738((u32)fn_1_5233C);
            fn_1_49748(5.0f);
            if (lbl_801A66B4 != 5) {
                fn_1_495B0(0x80000000U);
                fn_1_49590(0.5f);
            }
            sprintf(buf, *(char **)(p_data + 0x560 + (lbl_801A66B4 << 2)), k + 1);
            fn_1_53E40(0, (u32)buf, 320.0f, 240.0f, 0.05f, 48.0f, 0.8f);
        }
        break;
    case 5:
        {
            u32 w = TBL(0xe8);
            ret = 0x4800;
            v = w;
            fn_4_2D4(p->unk_5C, TBL(0x364), w);
        }
        switch (p->unk_12) {
        case 0:
            fn_4_18B8();
            break;
        case 1:
            fn_4_28FC();
            break;
        }
        break;
    }
    fn_1_1380F0((void *)v);
    fn_1_13ABA8(ret);
}
