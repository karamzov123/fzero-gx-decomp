#include "types.h"

typedef struct {
    u8 pad00[6];
    u8 unk06;
} Fn8005C7C0Info;

typedef struct {
    u8 unk00;
    u8 pad01[0x20 - 0x01];
} Fn8005C7C0Slot;

/* entries start at 0x1408 in the root, 0x118 bytes each */
typedef struct {
    u8 pad00[0x02];
    u8 slot;
    u8 pad03[0x09 - 0x03];
    u8 unk09;
    u8 unk0A;
    u8 pad0B[0x14 - 0x0B];
    s32 unk14;
    volatile u32 unk18; /* Read the current control flags before resolving the info pointer. */
    Fn8005C7C0Info *info;
    void *unk20;
    u8 pad24[0x84 - 0x24];
    s32 unk84;
    u8 pad88[0x90 - 0x88];
    u8 unk90;
    u8 pad91[0x114 - 0x91];
    s32 unk114;
} Fn8005C7C0Entry;

typedef struct {
    u8 pad0000[0x590];
    Fn8005C7C0Slot slots[0x70];
    u8 pad1390[0x1408 - 0x1390];
    Fn8005C7C0Entry entries[1];
} Fn8005C7C0Root;

extern Fn8005C7C0Root *lbl_801A6C80;
extern f32 fn_80088578(f32 x);
extern s32 fn_8005D258(void *arg0, Fn8005C7C0Info *info, u8 slot, u32 arg3, f32 *vol, s16 *pan);


static const u32 fzgx_pool_rodata_lbl_800929D8[8] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFC7CFE5C, 0xFE7AFE98, 0xFEB6FED4, 0xFEF2FF10, 0xFF2EFF4C, 0xFF6AFF88, 0xFFA6FFC4, 0xFFE20000
};
static const u32 fzgx_pool_rodata_lbl_800929F8[8] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xEFDFCFBF, 0xAF9F8F7F, 0x6F5F4F3F, 0x2F1F0F00
};
static const u32 fzgx_pool_rodata_lbl_80092A18[8] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xF1F2F3F, 0x4F5F6F7F, 0x8F9FAFBF, 0xCFDFEFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFF00
};
static const u32 fzgx_pool_rodata_lbl_800929D8_60[32] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0, 0x1010101, 0x1020202, 0x2030304, 0x4050506, 0x7070809,
    0xA0B0C0D, 0xE0F1011, 0x13141517, 0x181A1C1D, 0x1F212325, 0x27292B2E, 0x30323436, 0x383A3C3E,
    0x40424446, 0x484A4C4E, 0x50525457, 0x595B5D5E, 0x60626465, 0x67686A6B, 0x6C6E6F70, 0x71727374,
    0x75767777, 0x7879797A, 0x7B7B7C7C, 0x7C7D7D7D, 0x7E7E7E7E, 0x7E7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_800929D8(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_800929D8;
    s = *(u8 *)fzgx_pool_rodata_lbl_800929F8;
    s = *(u8 *)fzgx_pool_rodata_lbl_80092A18;
    s = *(u8 *)fzgx_pool_rodata_lbl_800929D8_60;
}
#pragma section code_type ".text"

static inline void fn_8005C7C0_levels(u8 *tbl, s16 arg0, f32 arg1, s16 arg2, s32 *arg3, s32 *arg4) {
    u32 idx = ((s32)arg0 / 4 - 1) & 0xFF;
    f32 a;
    f32 b;

    a = arg1 + (f32)(20.0 * fn_80088578((f32)((u8 *)fzgx_pool_rodata_lbl_800929F8)[idx] / 255.0f));
    b = arg1 + (f32)(20.0 * fn_80088578((f32)((u8 *)fzgx_pool_rodata_lbl_80092A18)[idx] / 255.0f));

    *arg3 = (s32)((f32)arg2 + 10.0f * a);
    *arg4 = (s32)((f32)arg2 + 10.0f * b);

    if ((s16)*arg3 < -960) {
        *arg3 = -960;
    }
    if ((s16)*arg4 < -960) {
        *arg4 = -960;
    }
}

void fn_8005C7C0(u32 arg0) {
    Fn8005C7C0Info *info;
    s32 result;
    f32 vol;
    s16 pan;
    s32 left;
    s32 right;
    u8 v;
    u8 slot;
    s16 level;
    u32 flags;

    flags = lbl_801A6C80->entries[arg0].unk18;
    info = lbl_801A6C80->entries[arg0].info;
    fn_8005D258(lbl_801A6C80->entries[arg0].unk20, info, lbl_801A6C80->entries[arg0].slot,
                (flags >> 8) & 0xFF, &vol, &pan);
    v = info->unk06;
    slot = lbl_801A6C80->entries[arg0].slot;
    if (v & 0x80) {
        v = lbl_801A6C80->slots[slot].unk00;
    }
    level = ((u8 *)fzgx_pool_rodata_lbl_800929D8_60)[v];
    if (lbl_801A6C80->entries[arg0].unk09 != 0xFF || lbl_801A6C80->entries[arg0].unk0A != 0xFF) {
        fn_8005C7C0_levels(((u8 *)fzgx_pool_rodata_lbl_800929D8), level, vol, pan, &left, &right);
        if (lbl_801A6C80->entries[arg0].unk09 == arg0) {
            result = (s16)left;
        } else {
            result = (s16)right;
        }
        lbl_801A6C80->entries[arg0].unk84 = (result - (lbl_801A6C80->entries[arg0].unk114 >> 16)) << 16;
        lbl_801A6C80->entries[arg0].unk14 = result;
    } else {
        lbl_801A6C80->entries[arg0].unk90 = level;
    }
}
