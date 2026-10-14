/* Non-matching: best partial attempt (88.05% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef void (*Sig_ARQPostRequest_ARQCallback)(u32 pointerToARQRequest);
typedef struct Sig_ARQPostRequest_ARQRequest {
    struct Sig_ARQPostRequest_ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    Sig_ARQPostRequest_ARQCallback callback;
} Sig_ARQPostRequest_ARQRequest;

struct fn_80066C14_Entry {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 padF;
};
struct fn_80066C14_State {
    struct fn_80066C14_Entry entries[16];
    u8 pad100[4];
    u32 unk104[16];
    u8 pad144[0x40];
    u8 unk184[16];
    u8 pad194[0x18];
    u32 unk1ac[16];
    u8 pad1ec[0x40];
    u8 unk22c[16];
    u8 pad23c[0x224];
    u8 unk45f;
    u8 unk460;
    u8 pad461[0x17];
    u32 unk478;
    u32 unk47c;
};
extern s32 fn_80065B08(u32, u32, u32, u32);
extern struct fn_80066C14_State *lbl_801A6C80;
extern u32 lbl_80193B08[];
extern u32 lbl_801A6C7C;
extern void *memcpy(void *, const void *, u32);
extern void ARQPostRequest(Sig_ARQPostRequest_ARQRequest *, u32, u32, u32, u32, u32, u32, Sig_ARQPostRequest_ARQCallback);
extern void fn_800657F4(u8);
extern void fn_80065AC4(void);
extern u32 fn_8006060C(u32);
extern void fn_80064D4C(u8, u8);

s32 fn_80066C14(u8 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    s32 result = 0;
    u32 offset;
    u32 size;
    u32 i;
    s32 found;
    u8 *file;
    u32 value;

    if (arg1 >= 16) {
        return -1;
    }
    offset = arg1 << 4;
    if (lbl_801A6C80->entries[arg1].unk0 + 0x10000 != 65535) {
        return -3;
    }
    size = 0x20;
    if (*(u32 *)(arg0 + 0) != 0x67636178) {
        return -2;
    }
    if (*(u32 *)(arg0 + 4) == 0x4454504B) {
        if (*(u32 *)(arg0 + 8) >= 0x02280000) {
            if (lbl_801A6C80->unk45f == 0) {
                size = 0xA0;
                if (fn_80065B08((u32)(arg0 + 0x20), (u32)lbl_801A6C80, arg2, arg3) != 0) {
                    result = -4;
                }
            } else {
                result = -9;
            }
        } else {
            result = -9;
        }
    } else {
        result = -2;
    }
    size += 0x20;

    if (*(u32 *)(arg0 + 0xA4) == 0x54424C44 && result == 0) {
        u8 count = arg0[0xC9];
        u32 length = *(u32 *)(arg0 + 0xAC);
        u32 id = *(u32 *)(arg0 + 0xC0);
        u32 dest = *(u32 *)(arg0 + 0xC4);
        if ((s32)(lbl_801A6C80->unk460 + count) <= 0x40) {
            found = -1;
            for (i = 0; i < 4; i++) {
                if (lbl_801A6C80->unk104[i * 4] == id && lbl_801A6C80->unk184[i * 4] == 0) { found = i * 4; break; }
                if (lbl_801A6C80->unk104[i * 4 + 1] == id && lbl_801A6C80->unk184[i * 4 + 1] == 0) { found = i * 4 + 1; break; }
                if (lbl_801A6C80->unk104[i * 4 + 2] == id && lbl_801A6C80->unk184[i * 4 + 2] == 0) { found = i * 4 + 2; break; }
                if (lbl_801A6C80->unk104[i * 4 + 3] == id && lbl_801A6C80->unk184[i * 4 + 3] == 0) { found = i * 4 + 3; break; }
            }
            if (found >= 0) {
                value = lbl_801A6C80->unk104[found];
                file = (u8 *)value;
                memcpy(file, arg0 + size, length);
                size += length;
                lbl_801A6C80->unk184[found] = 1;
                lbl_801A6C80->entries[arg1].unk8 = value;
                lbl_801A6C80->entries[arg1].unkC = count;
                lbl_801A6C80->entries[arg1].unk0 = dest;
                lbl_801A6C80->entries[arg1].unkD = arg0[0xCC];
                lbl_801A6C80->entries[arg1].unkE = arg0[0xCD];
                lbl_801A6C80->unk478 = *(u32 *)(arg0 + 0xD0);
                lbl_801A6C80->unk47c = *(u32 *)(arg0 + 0xD4);
                lbl_801A6C80->unk460 += count;
                fn_800657F4((u8)arg1);
            } else {
                result = -6;
            }
        } else {
            result = -5;
        }
    }

    if (result != 0) return result;
    file = arg0 + size;
    if (*(u32 *)(file + 4) == 0x50434D44) {
        u32 request = *(u32 *)(file + 0xC);
        u32 key = *(u32 *)(file + 0x20);
        found = -1;
        for (i = 0; i < 4; i++) {
            if (lbl_801A6C80->unk1ac[i * 4] == key) { if (lbl_801A6C80->unk22c[i * 4] == 0) { found = i * 4; break; } }
            else if (lbl_801A6C80->unk1ac[i * 4 + 1] == key) { if (lbl_801A6C80->unk22c[i * 4 + 1] == 0) { found = i * 4 + 1; break; } }
            else if (lbl_801A6C80->unk1ac[i * 4 + 2] == key) { if (lbl_801A6C80->unk22c[i * 4 + 2] == 0) { found = i * 4 + 2; break; } }
            else if (lbl_801A6C80->unk1ac[i * 4 + 3] == key) { if (lbl_801A6C80->unk22c[i * 4 + 3] == 0) { found = i * 4 + 3; break; } }
        }
        if (found >= 0) {
            lbl_801A6C80->unk22c[found] = 1;
            lbl_801A6C80->entries[arg1].unk4 = lbl_801A6C80->unk1ac[found];
            if (request != 0) {
                lbl_801A6C7C = 1;
                ARQPostRequest((Sig_ARQPostRequest_ARQRequest *)lbl_80193B08, 0, 0, 1, (u32)(file + 0x20), lbl_801A6C80->unk1ac[found], request, (Sig_ARQPostRequest_ARQCallback)fn_80065AC4);
                while ((s32)lbl_801A6C7C != 0) { }
            }
        } else if (arg1 < 16 && lbl_801A6C80->entries[arg1].unk0 + 0x10000 != 65535) {
            fn_8006060C(arg1);
            fn_80064D4C((u8)arg1, 0);
            fn_80064D4C((u8)arg1, 1);
            lbl_801A6C80->unk460 -= lbl_801A6C80->entries[arg1].unkC;
            lbl_801A6C80->entries[arg1].unk0 = -1;
            lbl_801A6C80->entries[arg1].unkE = 0xFF;
            lbl_801A6C80->entries[arg1].unkD = 0xFF;
            lbl_801A6C80->entries[arg1].unkC = 0;
            for (i = 0; i < 8; i++) {
                if (lbl_801A6C80->unk104[i * 2] == lbl_801A6C80->entries[arg1].unk8) { lbl_801A6C80->unk184[i * 2] = 0; lbl_801A6C80->entries[arg1].unk8 = 0; }
                if (lbl_801A6C80->unk1ac[i * 2] == lbl_801A6C80->entries[arg1].unk4) { lbl_801A6C80->unk22c[i * 2] = 0; lbl_801A6C80->entries[arg1].unk4 = 0; }
            }
            result = -7;
        } else {
            result = -7;
        }
    } else if (arg1 < 16 && lbl_801A6C80->entries[arg1].unk0 + 0x10000 != 65535) {
        fn_8006060C(arg1);
        fn_80064D4C((u8)arg1, 0);
        fn_80064D4C((u8)arg1, 1);
        lbl_801A6C80->unk460 -= lbl_801A6C80->entries[arg1].unkC;
        lbl_801A6C80->entries[arg1].unk0 = -1;
        lbl_801A6C80->entries[arg1].unkE = 0xFF;
        lbl_801A6C80->entries[arg1].unkD = 0xFF;
        lbl_801A6C80->entries[arg1].unkC = 0;
        for (i = 0; i < 8; i++) {
            if (lbl_801A6C80->unk104[i * 2] == lbl_801A6C80->entries[arg1].unk8) { lbl_801A6C80->unk184[i * 2] = 0; lbl_801A6C80->entries[arg1].unk8 = 0; }
            if (lbl_801A6C80->unk1ac[i * 2] == lbl_801A6C80->entries[arg1].unk4) { lbl_801A6C80->unk22c[i * 2] = 0; lbl_801A6C80->entries[arg1].unk4 = 0; }
        }
        result = -2;
    } else {
        result = -2;
    }
    return result;
}
