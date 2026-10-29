/* Non-matching: best partial attempt (99.98% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

#pragma use_lmw_stmw on

typedef struct SndBank {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 pad_F;
} SndBank;

typedef struct SndState {
    SndBank banks[16];
    u8 pad_100[4];
    u32 unk104[16];
    u32 unk144[16];
    u8 unk184[16];
    u8 pad_194[0x18];
    u32 unk1ac[16];
    s32 unk1ec[16];
    u8 unk22c[16];
    u8 pad_23c[0x223];
    u8 unk45f;
    u8 unk460;
    u8 pad_461[0x17];
    u32 unk478;
    u32 unk47c;
} SndState;

extern SndState *lbl_801A6C80;
// Set by the ARAM transfer callback.
extern volatile s32 lbl_801A6C7C;
extern u8 lbl_80193B08[];
extern s32 fn_80065B08(u8 *data);
extern void fn_800657F4(u8 bank);
extern u32 fn_8006060C(u32);
extern u32 fn_80064D4C(u8, u32);
extern void fn_80065AC4(u32 request);
extern void *memcpy(void *dst, const void *src, u32 n);
extern void ARQPostRequest(void *request, u32 owner, u32 type, u32 priority, u32 source, u32 dest,
                           u32 length, void (*callback)(u32));

static inline s32 snd_unload_bank(u32 bank)
{
    s32 ret;
    u32 i;

    ret = 0;
    if (bank >= 16) {
        ret = -1;
    } else if (lbl_801A6C80->banks[bank].unk0 != 0xFFFFFFFF) {
        fn_8006060C(bank);
        fn_80064D4C(bank, 0);
        fn_80064D4C(bank, 1);
        lbl_801A6C80->unk460 -= lbl_801A6C80->banks[bank].unkC;
        lbl_801A6C80->banks[bank].unk0 = -1;
        lbl_801A6C80->banks[bank].unkE = 0xFF;
        lbl_801A6C80->banks[bank].unkD = 0xFF;
        lbl_801A6C80->banks[bank].unkC = 0;
        for (i = 0; i < 16; i++) {
            if (lbl_801A6C80->unk104[i] == lbl_801A6C80->banks[bank].unk8) {
                lbl_801A6C80->unk184[i] = 0;
                lbl_801A6C80->banks[bank].unk8 = 0;
            }
            if (lbl_801A6C80->unk1ac[i] == lbl_801A6C80->banks[bank].unk4) {
                lbl_801A6C80->unk22c[i] = 0;
                lbl_801A6C80->banks[bank].unk4 = 0;
            }
        }
    } else {
        ret = -2;
    }
    return ret;
}

s32 fn_80066C14(u8 *data, u32 bank)
{
    u8 *chunk;
    u32 i;
    u32 id;
    s32 j;
    s32 index2;
    u32 id2;
    u32 length;
    u32 size;
    u32 value;
    s32 result;
    s32 offset;
    s32 index;
    u8 count;
    u32 dest;
    u32 src;

    result = 0;
    if (bank >= 16) {
        return -1;
    }
    if (lbl_801A6C80->banks[bank].unk0 == 0xFFFFFFFF) {
        offset = 0x20;
        if (*(u32 *)data == 0x67636178) {
            if (*(u32 *)(data + 4) == 0x4454504B) {
                if (*(u32 *)(data + 8) >= 0x2280000) {
                    if (lbl_801A6C80->unk45f == 0) {
                        offset = 0xA0;
                        if (fn_80065B08(data + 0x20) != 0) {
                            result = -4;
                        }
                    } else {
                        offset = 0xA0;
                    }
                } else {
                    result = -9;
                }
            } else {
                result = -2;
            }
            offset += 0x20;
            if (*(u32 *)(data + 0xA4) == 0x54424C44 && result == 0) {
                index = -1;
                count = data[0xC9];
                size = *(u32 *)(data + 0xAC);
                id = *(u32 *)(data + 0xC0);
                value = *(u32 *)(data + 0xC4);
                if (lbl_801A6C80->unk460 + count <= 0x40) {
                    for (i = 0; i < 16; i++) {
                        if (lbl_801A6C80->unk144[i] == id && lbl_801A6C80->unk184[i] == 0) {
                            index = i;
                            break;
                        }
                    }
                    if (index >= 0) {
                        dest = lbl_801A6C80->unk104[index];
                        memcpy((void *)dest, data + offset, size);
                        lbl_801A6C80->unk184[index] = 1;
                        offset += size;
                        lbl_801A6C80->banks[bank].unk8 = dest;
                        lbl_801A6C80->banks[bank].unkC = count;
                        lbl_801A6C80->banks[bank].unk0 = value;
                        lbl_801A6C80->banks[bank].unkD = data[0xCC];
                        lbl_801A6C80->banks[bank].unkE = data[0xCD];
                        lbl_801A6C80->unk478 = *(u32 *)(data + 0xD0);
                        lbl_801A6C80->unk47c = *(u32 *)(data + 0xD4);
                        lbl_801A6C80->unk460 += count;
                        fn_800657F4(bank);
                    } else {
                        result = -6;
                    }
                } else {
                    result = -5;
                }
            }
            index2 = -1;
            if (result == 0) {
                chunk = data;
                chunk += offset;
                if (*(u32 *)(chunk + 4) == 0x50434D44) {
                    length = *(u32 *)(chunk + 0xC);
                    id2 = *(u32 *)(chunk + 0x20);
                    for (j = 0; j < 16; j++) {
                        if (lbl_801A6C80->unk1ec[j] == id2 && lbl_801A6C80->unk22c[j] == 0) {
                            index2 = j;
                            break;
                        }
                    }
                    if (index2 >= 0) {
                        lbl_801A6C80->unk22c[index2] = 1;
                        lbl_801A6C80->banks[bank].unk4 = lbl_801A6C80->unk1ac[index2];
                        chunk = (u8 *)offset;
                        chunk += (u32)data;
                        src = (u32)(chunk + 0x20);
                        if (length != 0) {
                            lbl_801A6C7C = 1;
                            ARQPostRequest(lbl_80193B08, 0, 0, 1, src,
                                           lbl_801A6C80->unk1ac[index2], length, fn_80065AC4);
                            while (1) {
                                if (lbl_801A6C7C == 0) {
                                    break;
                                }
                            }
                        }
                    } else {
                        snd_unload_bank(bank);
                        result = -7;
                    }
                } else {
                    snd_unload_bank(bank);
                    result = -2;
                }
            }
        } else {
            result = -2;
        }
    } else {
        result = -3;
    }
    return result;
}
