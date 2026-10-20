/* Non-matching: best partial attempt (71.08% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
struct Sig_fn_3_12FD4_fn_3_12FD4_Arg3 {
    f32 unk_0;
};
struct Sig_fn_3_12FD4_fn_3_12FD4_Arg4 {
    f32 unk_0;
};

struct fn_3_10260_lbl_1_bss_9F8_8_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};
struct fn_3_10260_lbl_3_bss_7EDC0 {
    u32 unk_0;
    u8 pad_4[0x8];
    u32 unk_C;
};
struct fn_3_10260_lbl_1_bss_9F8 {
    u8 pad_0[0x8];
    struct fn_3_10260_lbl_1_bss_9F8_8_E20 unk_8[1];
};
struct fn_3_10260_lbl_3_bss_7EE40 {
    u8 pad_0[0x8];
    u8 unk_8;
};

extern struct fn_3_10260_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern struct fn_3_10260_lbl_3_bss_7EDC0 lbl_3_bss_7EDC0;
extern struct fn_3_10260_lbl_3_bss_7EE40 lbl_3_bss_7EE40;
extern u32 lbl_3_bss_87040;
extern void fn_1_A2D84(u32);
extern void fn_3_12FD4(u32, u32, u32, struct Sig_fn_3_12FD4_fn_3_12FD4_Arg3 *, struct Sig_fn_3_12FD4_fn_3_12FD4_Arg4 *);

void fn_3_10260(void) {
    struct fn_3_10260_lbl_3_bss_7EDC0 *p_lbl_3_bss_7EDC0;
    void * v0;
    s32 v1;
    void * v2;
    u8 v3;
    u32 v4;
    s32 v5;
    void * v6;
    u8 v7;
    u32 v8;
    void * v9;
    u32 v10;
    s16 v11;
    u8 v12;
    u32 v13;
    void * v14;
    u32 unk_1;
    s16 v16;
    u8 v17;
    void * v18;
    s32 v19;
    p_lbl_3_bss_7EDC0 = (struct fn_3_10260_lbl_3_bss_7EDC0 *)&lbl_3_bss_7EDC0;
    v0 = (void *)(((u8 *)(u32)p_lbl_3_bss_7EDC0 + 24));
    if (((lbl_1_bss_9F8.unk_8[*(u8 *)((u8 *)v0 + 20)].unk_0 >> 4) & 0x1) != 0) {
    *(u32 *)((u8 *)v0 + 16) = *(u32 *)((u8 *)v0 + 12);
    *(u32 *)((u8 *)v0 + 12) = 0x1000000;
    }
    v1 = (*(u8 *)((u8 *)v0 + 20) * 20);
    if (((*(u16 *)((u8 *)((u8 *)&lbl_1_bss_9F8 + 16) + v1) >> 3) & 0x1) != 0 || ((*(u16 *)((u8 *)((u8 *)&lbl_1_bss_9F8 + v1) + 18) >> 3) & 0x1) != 0) {
    v2 = (void *)(((u8 *)(u32)p_lbl_3_bss_7EDC0 + 24));
    v3 = lbl_3_bss_7EE40.unk_8;
    v4 = ((*(s16 *)((u8 *)v2 + 28) + v3) - 1);
    *(u16 *)((u8 *)v2 + 28) = (v4 - (((s32)v4 / (s32)v3) * v3));
    fn_1_A2D84(0xA9010000);
    }
    v5 = (*(u8 *)((u8 *)v0 + 20) * 20);
    if (((*(u16 *)((u8 *)((u8 *)&lbl_1_bss_9F8 + 16) + v5) >> 2) & 0x1) != 0 || ((*(u16 *)((u8 *)((u8 *)&lbl_1_bss_9F8 + v5) + 18) >> 2) & 0x1) != 0) {
    v6 = (void *)(((u8 *)(u32)p_lbl_3_bss_7EDC0 + 24));
    v7 = lbl_3_bss_7EE40.unk_8;
    v8 = (*(s16 *)((u8 *)v6 + 28) + 1);
    *(u16 *)((u8 *)v6 + 28) = (v8 - (((s32)v8 / (s32)v7) * v7));
    fn_1_A2D84(0xA9010000);
    }
    v9 = (void *)(((u8 *)(u32)p_lbl_3_bss_7EDC0 + 24));
    v10 = (lbl_3_bss_7EE40.unk_8 - 1);
    v11 = *(s16 *)((u8 *)v9 + 28);
    if (*(s16 *)((u8 *)v9 + 28) > (s32)v10) {
    v11 = 0;
    } else {
    if ((s16)v11 < 0) {
    v11 = v10;
    }
    }
    v12 = *(u8 *)((u8 *)v0 + 20);
    *(u16 *)((u8 *)v9 + 28) = v11;
    v13 = v10;
    if (((lbl_1_bss_9F8.unk_8[v12].unk_0 >> 8) & 0x1) != 0) {
    v13 = 0xA9010100;
    fn_1_A2D84(v13);
    v14 = (void *)(((u8 *)(u32)p_lbl_3_bss_7EDC0 + 24));
    *(u32 *)((u8 *)v14 + 12) = 0x8000000;
    v13 = *(u32 *)((u8 *)p_lbl_3_bss_7EDC0->unk_C + 912);
    unk_1 = ((v13 << 6) | (v13 >> 25)) & 1;
    if (unk_1 == 0) {
    v16 = *(s16 *)((u8 *)v9 + 28);
    v17 = *(u8 *)((u8 *)v13 + -32348);
    v18 = (void *)((u8 *)&lbl_3_bss_87040 + (*(u8 *)((u8 *)v14 + 21) * 8288));
    fn_3_12FD4(5, (u8)v16, v17, (struct Sig_fn_3_12FD4_fn_3_12FD4_Arg3 *)((u8 *)v18 + 48), (struct Sig_fn_3_12FD4_fn_3_12FD4_Arg4 *)((u8 *)v18 + 52));
    } else {
    v18 = (void *)((u8 *)&lbl_3_bss_87040 + (*(u8 *)((u8 *)v14 + 21) * 8288));
    fn_3_12FD4(0, *(s16 *)((u8 *)v9 + 28) & 0xFF, *(u8 *)((u8 *)p_lbl_3_bss_7EDC0->unk_C + 808), (struct Sig_fn_3_12FD4_fn_3_12FD4_Arg3 *)((u8 *)v18 + 48), (struct Sig_fn_3_12FD4_fn_3_12FD4_Arg4 *)((u8 *)v18 + 52));
    }
    }
    v19 = v13;
    if (((lbl_1_bss_9F8.unk_8[*(u8 *)((u8 *)v0 + 20)].unk_0 >> 9) & 0x1) != 0) {
    v19 = 0xA9010200;
    fn_1_A2D84(v19);
    v19 = (u32)((u8 *)(u32)p_lbl_3_bss_7EDC0 + 24);
    *(u32 *)((u8 *)v19 + 12) = 0x40000000;
    }
}
