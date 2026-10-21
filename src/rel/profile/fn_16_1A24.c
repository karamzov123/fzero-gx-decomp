#include "types.h"
typedef struct Sig_fn_1_95120_Fn195120Data Sig_fn_1_95120_Fn195120Data;
typedef struct Sig_fn_1_95120_Fn195120Owner Sig_fn_1_95120_Fn195120Owner;
struct Sig_fn_1_95120_Fn195120Data { u8 unk_00[0x4C]; f32 value_50; f32 value_4C; };
struct Sig_fn_1_95120_Fn195120Owner { u8 unk_00[8]; Sig_fn_1_95120_Fn195120Data *data; };
typedef struct Sig_fn_1_41488_Fn41488Data { u32 count; char *strings; } Sig_fn_1_41488_Fn41488Data;
typedef struct { u8 pad0[0x1c]; void *field_1c; } Sig_fn_1_933D8_CarObject;
typedef struct { u8 pad0[0x24]; void *field_24; } Sig_fn_1_933D8_EventData;
typedef struct { u8 pad0[8]; Sig_fn_1_933D8_EventData *field_8; void *field_c; } Sig_fn_1_933D8_EventObject;
struct fn_16_1A24_lbl_1_bss_8B614 {
    s16 unk_0;
    u8 pad_2[6];
    s16 unk_8;
    u8 pad_A[2];
    s16 unk_C;
    s16 unk_E;
    u8 pad_10[0x20];
    s16 unk_30;
    u8 pad_32[0x1A];
    u32 unk_4C;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
};
struct fn_16_1A24_lbl_16_data_82B34 { u32 unk_0[8]; };
extern int fn_1_41488(Sig_fn_1_41488_Fn41488Data *, const char *);
extern s16 lbl_16_bss_860B8;
extern s32 fn_1_12CB04(s16);
extern s32 fn_1_95120(Sig_fn_1_95120_Fn195120Owner *);
extern struct fn_16_1A24_lbl_16_data_82B34 lbl_16_data_82B34;
extern struct fn_16_1A24_lbl_1_bss_8B614 lbl_1_bss_8B614;
extern s32 fn_1_FA1A8(u32);
extern u32 lbl_1_bss_9F8;
extern void fn_1_933D8(Sig_fn_1_933D8_CarObject *, Sig_fn_1_933D8_EventObject *, u32);
extern void fn_1_A2D84(u32);
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_loop_invariants off
s32 fn_16_1A24(void) {
    struct fn_16_1A24_lbl_1_bss_8B614 *p_lbl_1_bss_8B614;
    s32 v0;
    u16 *v1;
    u16 *v8;
    s32 v3;
    s32 v4;
    s16 v5;
    s16 v6;
    u8 *v14;
    int v12;
    s32 v13;
    u8 *v10;
    v3 = 0;
    v1 = (u16 *)&lbl_1_bss_9F8;
    v0 = lbl_1_bss_8B614.unk_8 * 20;
    v1 = (u16 *)((u8 *)v1 + v0);
    if (((*(v1 += 4) >> 9) & 1) != 0) {
        fn_1_A2D84(0xA9010200);
        return -1;
    }
    if (((*v1 >> 10) & 1) != 0) {
        fn_1_A2D84(0xA9010100);
        return 1;
    }
    if (((*v1 >> 11) & 1) != 0 && fn_1_FA1A8(lbl_1_bss_8B614.unk_C) == 1) {
        fn_1_A2D84(0xA9010100);
        return 2;
    }
    v8 = (u16 *)((u8 *)&lbl_1_bss_9F8 + v0);
    if (((*(v8 += 9) >> 8) & 1) != 0) v3 = 1;
    if (((*v8 >> 9) & 1) != 0) v3--;
    p_lbl_1_bss_8B614 = &lbl_1_bss_8B614;
    v4 = p_lbl_1_bss_8B614->unk_30 + (s16)v3;
    { s32 result;
      if (v4 > 3) result = 0;
      else { result = 3; if (v4 >= 0) result = v4; }
      p_lbl_1_bss_8B614->unk_30 = result;
    }
    if ((s16)v3 != 0) fn_1_A2D84(0xA9010000);
    v6 = lbl_16_bss_860B8 - 10;
    p_lbl_1_bss_8B614 = &lbl_1_bss_8B614;
    v5 = p_lbl_1_bss_8B614->unk_E;
    if (v6 > 0) {
        v3 = 0;
        v1 = (u16 *)((u8 *)&lbl_1_bss_9F8 + v0);
        if (((*(v1 += 8) >> 2) & 1) != 0 || ((*v8 >> 2) & 1) != 0) v3 = 1;
        if (((*v1 >> 3) & 1) != 0 || ((*v8 >> 3) & 1) != 0) v3--;
        v4 = p_lbl_1_bss_8B614->unk_E + (s16)v3;
        if (v4 < 0) v4 = 0;
        else if (v4 > v6) v4 = v6;
        p_lbl_1_bss_8B614->unk_E = v4;
    } else p_lbl_1_bss_8B614->unk_E = 0;
    if (v5 != p_lbl_1_bss_8B614->unk_E) {
        if ((lbl_1_bss_8B614.unk_4C & 0x80000000) == 0) {
            lbl_1_bss_8B614.unk_50 = v3;
            lbl_1_bss_8B614.unk_4C = 0;
            lbl_1_bss_8B614.unk_4C |= 0x80000000;
            lbl_1_bss_8B614.unk_4C |= 0x02000001;
            lbl_1_bss_8B614.unk_52 = 0;
            lbl_1_bss_8B614.unk_54 = v3 * 5;
        }
        fn_1_A2D84(0xA9010000);
    }
    if (*(s16 *)((u8 *)&lbl_1_bss_8B614 + 0x58) == 4) {
        v10 = (u8 *)&lbl_1_bss_8B614 + 0x74;
        if (fn_1_95120((Sig_fn_1_95120_Fn195120Owner *)(v10 + 0x148)) != 0) {
            v12 = fn_1_41488((Sig_fn_1_41488_Fn41488Data *)(*(Sig_fn_1_933D8_EventData **)(v10 + 0x150))->field_24,
                (const char *)lbl_16_data_82B34.unk_0[lbl_1_bss_8B614.unk_0]);
            fn_1_933D8((Sig_fn_1_933D8_CarObject *)v10, (Sig_fn_1_933D8_EventObject *)(v10 + 0x148), v12 & 0xffff);
            p_lbl_1_bss_8B614 = (struct fn_16_1A24_lbl_1_bss_8B614 *)&lbl_1_bss_8B614;
            v14 = (u8 *)p_lbl_1_bss_8B614;
            for (v13 = 0; (s16)v13 < (s16)fn_1_12CB04(p_lbl_1_bss_8B614->unk_C); v13++) {
                fn_1_933D8((Sig_fn_1_933D8_CarObject *)(v14 + 0x55c), (Sig_fn_1_933D8_EventObject *)(v14 + 0x6a4), v12 & 0xffff);
                v14 += 0x4e8;
            }
            lbl_1_bss_8B614.unk_0++;
            lbl_1_bss_8B614.unk_0 &= 7;
        }
    }
    return 0;
}
#pragma opt_common_subs reset
