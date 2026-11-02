#include "dolphin/hw_regs.h"
#include "types.h"

/* one 0xEC-byte entry of the table at lbl_80164D60 */
struct fn_80022EA4_Block {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
    u8 pad_8[0x30];
    u16 unk_38;
    u16 unk_3A;
    u8 pad_3C[0x12];
    u16 unk_4E;
    u16 unk_50;
    u8 pad_52[0x9A];
};

/* one 0x224-byte entry of the table at lbl_80164D60+0x8B00 */
struct fn_80022EA4_Entry {
    u8 pad_0[0xC];
    u32 unk_C;
    u8 pad_10[0x8];
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x4];
    u32 unk_24;
    u32 unk_28;
    u8 pad_2C[0x4];
    void *unk_30;
    u8 unk_34[0x100];
    void *unk_134;
    u16 unk_138;
    u16 unk_13A;
    u16 unk_13C;
    u16 unk_13E;
    u8 pad_140[0x6];
    u16 unk_146;
    u8 pad_148[0x26];
    u16 unk_16E;
    u16 unk_170;
    u16 unk_172;
    u8 pad_174[0x8];
    u16 unk_17C;
    u16 unk_17E;
    u16 unk_180;
    u16 unk_182;
    u16 unk_184;
    u16 unk_186;
    u16 unk_188;
    u8 pad_18A[0x9A];
};

/* lbl_80164D60 is four tables that the retail TU defined, so MWCC addresses them off one section base:
 * 0x40 blocks of 0xEC bytes, 0x40 buffers of 0x40 and of 0x100 bytes, then 0x40 entries of 0x224 bytes */
struct fn_80022EA4_Block fzgx_obj_lbl_80164D60[0x40];
u8 fzgx_obj_lbl_80164D60__fzgx_offset_3B00[0x40][0x40];
u8 fzgx_obj_lbl_80164D60__fzgx_offset_4B00[0x40][0x100];
struct fn_80022EA4_Entry fzgx_obj_lbl_80164D60__fzgx_offset_8B00[0x40];

#pragma section code_type ".fzgxpool"
static void layout____bss_0(void) {
    volatile unsigned char sink; // fzgx-allow: S2 discarded layout primer
    sink = *(unsigned char *)&fzgx_obj_lbl_80164D60;
    sink = *(unsigned char *)&fzgx_obj_lbl_80164D60__fzgx_offset_3B00;
    sink = *(unsigned char *)&fzgx_obj_lbl_80164D60__fzgx_offset_4B00;
    sink = *(unsigned char *)&fzgx_obj_lbl_80164D60__fzgx_offset_8B00;
}
#pragma section code_type ".text"

extern u32 lbl_801A6B60;
extern u32 lbl_801A6B64;

extern void fn_800209DC(struct fn_80022EA4_Entry *entry);
extern void DCFlushRange(void *addr, u32 nBytes);

/* fn_80022E68, which retail inlines here */
static inline void fn_80022E68(struct fn_80022EA4_Entry *entry) {
    entry->unk_146 = 0;
    entry->unk_16E = 0;
    entry->unk_1C = 164;
    entry->unk_28 = 0;
    entry->unk_24 = 0;
    entry->unk_30 = entry->unk_34;
    entry->unk_184 = 0;
    entry->unk_182 = 0;
    entry->unk_180 = 0;
    entry->unk_17E = 0;
    entry->unk_17C = 0;
}

void fn_80022EA4(void) {
    u32 i;
    s32 j;
    struct fn_80022EA4_Block *block;
    u8 *buf40;
    u8 *buf100;
    struct fn_80022EA4_Entry *entry;

    lbl_801A6B60 = OS_BUS_CLOCK / 400;
    lbl_801A6B64 = 0;

    /* a signed index gives retail's eight-store unrolled loops */
    for (j = 0; j < sizeof(fzgx_obj_lbl_80164D60) / 4; j++) {
        ((u32 *)fzgx_obj_lbl_80164D60)[j] = 0;
    }
    for (j = 0; j < sizeof(fzgx_obj_lbl_80164D60__fzgx_offset_3B00) / 4; j++) {
        ((u32 *)fzgx_obj_lbl_80164D60__fzgx_offset_3B00)[j] = 0;
    }
    for (j = 0; j < sizeof(fzgx_obj_lbl_80164D60__fzgx_offset_8B00) / 4; j++) {
        ((u32 *)fzgx_obj_lbl_80164D60__fzgx_offset_8B00)[j] = 0;
    }

    for (i = 0; i < 0x40; i++) {
        block = &fzgx_obj_lbl_80164D60[i];
        buf40 = fzgx_obj_lbl_80164D60__fzgx_offset_3B00[i];
        buf100 = fzgx_obj_lbl_80164D60__fzgx_offset_4B00[i];
        entry = &fzgx_obj_lbl_80164D60__fzgx_offset_8B00[i];

        entry->unk_18 = i;
        entry->unk_30 = entry->unk_34;
        entry->unk_134 = buf40;
        fn_80022E68(entry);

        /* the blocks form a chain: each holds the next one's address as two halves, the last holds 0 */
        if (i == 0x3F) {
            entry->unk_138 = entry->unk_13A = block->unk_0 = block->unk_2 = 0;
        } else {
            entry->unk_138 = (u32)(block + 1) >> 16;
            entry->unk_13A = (u32)(block + 1);
            block->unk_0 = (u32)(block + 1) >> 16;
            block->unk_2 = (u32)(block + 1);
        }
        entry->unk_13C = (u32)block >> 16;
        entry->unk_13E = (u32)block;
        block->unk_4 = (u32)block >> 16;
        block->unk_6 = (u32)block;
        entry->unk_170 = (u32)buf40 >> 16;
        entry->unk_172 = (u32)buf40;
        block->unk_38 = (u32)buf40 >> 16;
        block->unk_3A = (u32)buf40;
        entry->unk_186 = (u32)buf100 >> 16;
        entry->unk_188 = (u32)buf100;
        block->unk_4E = (u32)buf100 >> 16;
        block->unk_50 = (u32)buf100;
        entry->unk_C = 1;
        fn_800209DC(entry);
    }
    DCFlushRange(fzgx_obj_lbl_80164D60, sizeof(fzgx_obj_lbl_80164D60));
}
