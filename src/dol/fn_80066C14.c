#include "types.h"
#pragma use_lmw_stmw on

/* track slot of the sequencer state; fields as fn_80065D70 names them */
typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 pad_F;
} fn_80066C14_Entry;

typedef struct {
    fn_80066C14_Entry entries[16];
    u8 pad_100[4];
    u32 unk104[16];
    u32 unk144[16];
    u8 unk184[16];
    u8 pad_194[0x18];
    u32 unk1ac[16];
    u32 unk1ec[16];
    u8 unk22c[16];
    u8 pad_23c[0x223];
    u8 unk_45F;
    u8 unk460;
    u8 pad_461[0x17];
    u32 unk_478;
    u32 unk_47C;
} fn_80066C14_State;

/* the file this function reads: magics "gcax" and "DTPK" at +0x0, "TBLD" at +0xA4 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x98];
    u32 unk_A4;
    u8 pad_A8[4];
    u32 unk_AC;
    u8 pad_B0[0x10];
    u32 unk_C0;
    u32 unk_C4;
    u8 pad_C8;
    u8 unk_C9;
    u8 pad_CA[2];
    u8 unk_CC;
    u8 unk_CD;
    u8 pad_CE[2];
    u32 unk_D0;
    u32 unk_D4;
} fn_80066C14_Header;

/* the block after the TBLD data: magic "PCMD" at +0x4 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[4];
    u32 unk_C;
    u8 pad_10[0x10];
    u32 unk_20;
} fn_80066C14_Chunk;

extern fn_80066C14_State *lbl_801A6C80;
extern volatile s32 lbl_801A6C7C; /* Updated asynchronously by the ARQ callback while polling. */
extern u8 lbl_80193B08[0x20];
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern void ARQPostRequest(void *request, u32 owner, u32 type, u32 priority, u32 source, u32 dest, u32 length,
                           void *callback);
extern void fn_80065AC4(void);
extern s32 fn_80065B08(u32 arg0);
extern void fn_800657F4(u8 arg0);
extern u32 fn_8006060C(u32 arg0);
extern u32 fn_80064D4C(u8 arg0, u32 arg1);

/* the body of fn_80065D70, which retail inlines here twice */
static inline s32 inline_fn_80065D70(u32 arg0) {
    s32 ret;
    u32 i;

    ret = 0;
    if (arg0 >= 16) {
        ret = -1;
    } else if (lbl_801A6C80->entries[arg0].unk0 != 0xFFFFFFFF) {
        fn_8006060C(arg0);
        fn_80064D4C(arg0, 0);
        fn_80064D4C(arg0, 1);
        lbl_801A6C80->unk460 -= lbl_801A6C80->entries[arg0].unkC;
        lbl_801A6C80->entries[arg0].unk0 = -1;
        lbl_801A6C80->entries[arg0].unkE = 0xFF;
        lbl_801A6C80->entries[arg0].unkD = 0xFF;
        lbl_801A6C80->entries[arg0].unkC = 0;
        for (i = 0; i < 16; i++) {
            if (lbl_801A6C80->unk104[i] == lbl_801A6C80->entries[arg0].unk8) {
                lbl_801A6C80->unk184[i] = 0;
                lbl_801A6C80->entries[arg0].unk8 = 0;
            }
            if (lbl_801A6C80->unk1ac[i] == lbl_801A6C80->entries[arg0].unk4) {
                lbl_801A6C80->unk22c[i] = 0;
                lbl_801A6C80->entries[arg0].unk4 = 0;
            }
        }
    } else {
        ret = -2;
    }
    return ret;
}

s32 fn_80066C14(fn_80066C14_Header *data, u32 arg1) {
    u32 size;
    u32 word;
    s32 ret;
    s32 slot2;
    u32 i;
    u32 off;
    s32 slot;
    u32 key;
    u8 count;
    u32 dst;
    fn_80066C14_Chunk *chunk;
    u32 length;
    u32 src;

    ret = 0;
    if (arg1 >= 16) {
        return -1;
    }
    if (lbl_801A6C80->entries[arg1].unk0 == 0xFFFFFFFF) {
        off = 0x20;
        if (data->unk_0 == 'gcax') {
            if (data->unk_4 == 'DTPK') {
                if (data->unk_8 >= 0x2280000) {
                    if (lbl_801A6C80->unk_45F == 0) {
                        off = 0xA0;
                        if (fn_80065B08((u32)data + 0x20) != 0) {
                            ret = -4;
                        }
                    } else {
                        off = 0xA0;
                    }
                } else {
                    ret = -9;
                }
            } else {
                ret = -2;
            }
            off += 0x20;
            if (data->unk_A4 == 'TBLD' && ret == 0) {
                slot = -1;
                count = data->unk_C9;
                size = data->unk_AC;
                key = data->unk_C0;
                word = data->unk_C4;
                if (lbl_801A6C80->unk460 + count <= 0x40) {
                    for (i = 0; i < 16; i++) {
                        if (lbl_801A6C80->unk144[i] == key && lbl_801A6C80->unk184[i] == 0) {
                            slot = i;
                            break;
                        }
                    }
                    if (slot >= 0) {
                        dst = lbl_801A6C80->unk104[slot];
                        memcpy((void *)dst, (u8 *)data + off, size);
                        off += size;
                        lbl_801A6C80->unk184[slot] = 1;
                        lbl_801A6C80->entries[arg1].unk8 = dst;
                        lbl_801A6C80->entries[arg1].unkC = count;
                        lbl_801A6C80->entries[arg1].unk0 = word;
                        lbl_801A6C80->entries[arg1].unkD = data->unk_CC;
                        lbl_801A6C80->entries[arg1].unkE = data->unk_CD;
                        lbl_801A6C80->unk_478 = data->unk_D0;
                        lbl_801A6C80->unk_47C = data->unk_D4;
                        lbl_801A6C80->unk460 += count;
                        fn_800657F4(arg1);
                    } else {
                        ret = -6;
                    }
                } else {
                    ret = -5;
                }
            }
            slot2 = -1;
            if (ret == 0) {
                chunk = (fn_80066C14_Chunk *)((u32)data + off);
                if (chunk->unk_4 == 'PCMD') {
                    length = chunk->unk_C;
                    key = chunk->unk_20;
                    for (i = 0; i < 16; i++) {
                        if (lbl_801A6C80->unk1ec[i] == key && lbl_801A6C80->unk22c[i] == 0) {
                            slot2 = i;
                            break;
                        }
                    }
                    if (slot2 >= 0) {
                        lbl_801A6C80->unk22c[slot2] = 1;
                        src = (u32)data + (off + 0x20);
                        lbl_801A6C80->entries[arg1].unk4 = lbl_801A6C80->unk1ac[slot2];
                        if (length != 0) {
                            lbl_801A6C7C = 1;
                            ARQPostRequest(lbl_80193B08, 0, 0, 1, src, lbl_801A6C80->unk1ac[slot2], length,
                                           fn_80065AC4);
                            while (1) {
                                if (lbl_801A6C7C == 0) {
                                    break;
                                }
                            }
                        }
                    } else {
                        inline_fn_80065D70(arg1);
                        ret = -7;
                    }
                } else {
                    inline_fn_80065D70(arg1);
                    ret = -2;
                }
            }
        } else {
            ret = -2;
        }
    } else {
        ret = -3;
    }
    return ret;
}
