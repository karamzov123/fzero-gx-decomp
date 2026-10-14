/* Non-matching: best partial attempt (64.05% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef enum Sig_GXInitTexObj__GXTexFmt {
    Sig_GXInitTexObj_GX_TF_I4 = 0x0,
    Sig_GXInitTexObj_GX_TF_I8 = 0x1,
    Sig_GXInitTexObj_GX_TF_IA4 = 0x2,
    Sig_GXInitTexObj_GX_TF_IA8 = 0x3,
    Sig_GXInitTexObj_GX_TF_RGB565 = 0x4,
    Sig_GXInitTexObj_GX_TF_RGB5A3 = 0x5,
    Sig_GXInitTexObj_GX_TF_RGBA8 = 0x6,
    Sig_GXInitTexObj_GX_TF_CMPR = 0xE,
    Sig_GXInitTexObj_GX_CTF_R4 = 0x0 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA4 = 0x2 | 0x20,
    Sig_GXInitTexObj_GX_CTF_RA8 = 0x3 | 0x20,
    Sig_GXInitTexObj_GX_CTF_YUVA8 = 0x6 | 0x20,
    Sig_GXInitTexObj_GX_CTF_A8 = 0x7 | 0x20,
    Sig_GXInitTexObj_GX_CTF_R8 = 0x8 | 0x20,
    Sig_GXInitTexObj_GX_CTF_G8 = 0x9 | 0x20,
    Sig_GXInitTexObj_GX_CTF_B8 = 0xA | 0x20,
    Sig_GXInitTexObj_GX_CTF_RG8 = 0xB | 0x20,
    Sig_GXInitTexObj_GX_CTF_GB8 = 0xC | 0x20,
    Sig_GXInitTexObj_GX_TF_Z8 = 0x1 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z16 = 0x3 | 0x10,
    Sig_GXInitTexObj_GX_TF_Z24X8 = 0x6 | 0x10,
    Sig_GXInitTexObj_GX_CTF_Z4 = 0x0 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8M = 0x9 | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z8L = 0xA | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_CTF_Z16L = 0xC | 0x10 | 0x20,
    Sig_GXInitTexObj_GX_TF_A8 = Sig_GXInitTexObj_GX_CTF_A8,
} Sig_GXInitTexObj_GXTexFmt;
typedef struct Sig_GXInitTexObj__GXTexObj {
    u32 dummy[8];
} Sig_GXInitTexObj_GXTexObj;
typedef enum Sig_GXInitTexObj__GXTexWrapMode {
    Sig_GXInitTexObj_GX_CLAMP,
    Sig_GXInitTexObj_GX_REPEAT,
    Sig_GXInitTexObj_GX_MIRROR,
    Sig_GXInitTexObj_GX_MAX_TEXWRAPMODE,
} Sig_GXInitTexObj_GXTexWrapMode;

struct fn_10_12E34_Arg0 {
    u8 pad_0[0x54];
    f32 unk_54;
};
struct fn_10_12E34_ro {
    u8 pad_0[0x48];
    f32 unk_48;
    f32 unk_4C;
    u8 pad_50[0x38];
    f64 unk_88;
    u8 pad_90[0x3C4];
    f32 unk_454;
};
struct fn_10_12E34_bss {
    u8 pad_0[0x20];
    f32 unk_20;
    u16 unk_40[0x200];
    u8 pad_440[0x20];
};
struct fn_10_12E34_u32 {
    u32 unk_0;
};

extern struct fn_10_12E34_ro lbl_10_rodata_158;
extern struct fn_10_12E34_bss lbl_10_bss_55680;
extern struct fn_10_12E34_u32 lbl_801A63C0;
extern struct fn_10_12E34_u32 lbl_801A66A0;
extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern u32 lbl_8006D784(u32);
extern void DCFlushRange(void *, void *);
extern void GXInvalidateTexAll(void);
extern void GXInitTexObj(Sig_GXInitTexObj_GXTexObj *, void *, u16, u16, Sig_GXInitTexObj_GXTexFmt, Sig_GXInitTexObj_GXTexWrapMode, Sig_GXInitTexObj_GXTexWrapMode, u8);
extern void fn_80073778(void *, s32);
extern void fn_80073898(u32);
extern void fn_800738E0(s32, s32, s32);
extern void fn_800739E0(s32, s32, s32);
extern void fn_80073A58(int, void *, s8);
extern void fn_80073D60(s32, s32, s32, s32, s32);

void fn_10_12E34(struct fn_10_12E34_Arg0 *arg0) {
    struct fn_10_12E34_ro *p_ro;
    struct fn_10_12E34_bss *p_bss;
    f32 col[6];
    f32 mat[12];
    f32 f;
    s32 i;
    s32 j;
    s32 k;
    s32 x;
    s32 w;
    s32 v;
    u16 h;
    u16 val;
    u16 *row;

    f = arg0->unk_54;
    p_ro = &lbl_10_rodata_158;
    p_bss = &lbl_10_bss_55680;
    row = p_bss->unk_40;
    for (i = 0; i < 128; i++) {
        v = (s32)lbl_801A63C0.unk_0;
        v = v * 0x676A4B6B + 0x33CB;
        lbl_801A63C0.unk_0 = (u32)v;
        x = ((u32)v >> 16) & 0x7FFF;
        h = (u16)(((((x % 14 - 7) & 0xFF) + 0x80) << 8) | 0x80);
        k = i * 4;
        for (j = 0; j < 2; j++) {
            val = h;
            if ((f64)(s32)f != 0.0) {
                w = (s32)((lbl_801A66A0.unk_0 >> 1) & 0x7F) - i;
                if (w < 0) {
                    w = -w;
                }
                if (w >= 2) {
                    val = 0x8080;
                }
            }
            row[k] = val;
            val = h;
            if ((f64)(s32)f != 0.0) {
                w = (s32)((lbl_801A66A0.unk_0 >> 1) & 0x7F) - i;
                if (w < 0) {
                    w = -w;
                }
                if (w >= 2) {
                    val = 0x8080;
                }
            }
            row[k + 1] = val;
            k += 2;
        }
    }
    DCFlushRange(p_bss->unk_40, (void *)(u32)0x400);
    GXInvalidateTexAll();
    GXInitTexObj((Sig_GXInitTexObj_GXTexObj *)((u8 *)p_bss + 0x440), p_bss->unk_40, 4, 128, 3, 1, 1, 0);
    fn_80073778((void *)((u8 *)p_bss + 0x440), 2);
    fn_80073898(1);
    fn_800738E0(0, 0, 2);
    fn_80073D60(0, 0, 1, 0, 1);
    if (lbl_801A66A0.unk_0 % 3 == 0) {
        v = (s32)lbl_801A63C0.unk_0;
        v = v * 0x676A4B6B + 0x33CB;
        lbl_801A63C0.unk_0 = (u32)v;
        x = ((u32)v >> 16) & 0x7FFF;
        p_bss->unk_20 = (f32)((f64)(x ^ 0x8000) - p_ro->unk_88) / p_ro->unk_454;
    }
    col[1] = p_ro->unk_4C;
    col[0] = p_ro->unk_48;
    col[2] = p_ro->unk_4C;
    col[3] = p_ro->unk_4C;
    col[4] = p_ro->unk_48;
    col[5] = p_ro->unk_4C;
    fn_80073A58(1, col, 1);
    fn_800739E0(0, 1, 1);
    lbl_8006D784((u32)mat);
    GXLoadPosMtxImm((u32)mat, 0);
    GXLoadTexMtxImm((u32)mat, 30, 1);
}
