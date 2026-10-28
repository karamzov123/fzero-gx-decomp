/* Non-matching: best partial attempt (99.19% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma use_lmw_stmw on
#include "dolphin/dvd.h"

typedef struct DVDFileInfo DVDFileInfo;
typedef void (*DVDCallback)(s32 result, DVDFileInfo *fileInfo);
struct DVDFileInfo {
    DVDCommandBlock cb;
    u32 startAddr;
    u32 length;
    DVDCallback callback;
};
extern BOOL DVDOpen(char *, DVDFileInfo *);
extern s32 DVDReadPrio(DVDFileInfo *, void *, s32, s32, s32);
extern BOOL DVDClose(DVDFileInfo *);

typedef struct SndBankEntry {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 pad_F;
} SndBankEntry;

typedef struct SndBankState {
    SndBankEntry entries[16];
    u8 pad_100[4];
    u32 unk104[16];
    u32 unk144[16];
    u8 unk184[16];
    u8 pad_194[4];
    u8 *unk198;
    u32 unk19C;
    u8 pad_1A0[0xC];
    u32 unk1AC[16];
    u32 unk1EC[16];
    u8 unk22C[16];
    u8 pad_23C[0x223];
    u8 unk45F;
    u8 unk460;
    u8 pad_461[0x17];
    u32 unk478;
    u32 unk47C;
} SndBankState;

typedef struct ARQRequest {
    struct ARQRequest *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    void (*callback)(u32);
} ARQRequest;

extern SndBankState *lbl_801A6C80;
extern char lbl_80092C08[];
extern u32 lbl_801A6410;
extern volatile s32 lbl_801A6C7C;
extern ARQRequest lbl_80193B08;
extern int sprintf(char *, const char *, ...);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern void *fn_80008E34(u32, u32);
extern void fn_80008E5C(u32, void *);
extern void DCInvalidateRange(void *, u32);
extern s32 fn_80065B08(void *);
extern void fn_800657F4(u8);
extern void fn_80065AD0(u32);
extern void fn_80065AC4(u32);
extern void ARQPostRequest(ARQRequest *, u32, u32, u32, u32, u32, u32, void (*)(u32));
extern u32 fn_8006060C(u32);
extern u32 fn_80064D4C(u8, u32);

static inline SndBankEntry *fn_80065F34_array_read(SndBankEntry *array) { return array; }

static inline void fn_80065F34_unload(u32 arg0) {
    u32 i;

    if (arg0 >= 16) {
    } else if (fn_80065F34_array_read(lbl_801A6C80->entries)[arg0].unk0 + 0x10000 != 65535) {
        fn_8006060C(arg0);
        fn_80064D4C(arg0, 0);
        fn_80064D4C(arg0, 1);
        lbl_801A6C80->unk460 -= fn_80065F34_array_read(lbl_801A6C80->entries)[arg0].unkC;
        fn_80065F34_array_read(lbl_801A6C80->entries)[arg0].unk0 = -1;
        fn_80065F34_array_read(lbl_801A6C80->entries)[arg0].unkE = 0xFF;
        fn_80065F34_array_read(lbl_801A6C80->entries)[arg0].unkD = 0xFF;
        fn_80065F34_array_read(lbl_801A6C80->entries)[arg0].unkC = 0;
        for (i = 0; i < 16; i++) {
            if (lbl_801A6C80->unk104[i] == fn_80065F34_array_read(lbl_801A6C80->entries)[arg0].unk8) {
                lbl_801A6C80->unk184[i] = 0;
                fn_80065F34_array_read(lbl_801A6C80->entries)[arg0].unk8 = 0;
            }
            if (lbl_801A6C80->unk1AC[i] == fn_80065F34_array_read(lbl_801A6C80->entries)[arg0].unk4) {
                lbl_801A6C80->unk22C[i] = 0;
                fn_80065F34_array_read(lbl_801A6C80->entries)[arg0].unk4 = 0;
            }
        }
    }
}

static inline void *fn_80065F34_alloc(u32 size) {
    void *p;
    BOOL enabled;

    SND_ALLOC(p, size);
    return p;
}

#define SND_ALLOC(dst, sz) { BOOL en = OSDisableInterrupts(); dst = fn_80008E34(lbl_801A6410, sz); OSRestoreInterrupts(en); }
static inline u8 * fn_80065F34_read_pointer(SndBankState * owner) { return owner->unk198; }
static inline s32 fn_80065F34_call_DVDReadPrio(DVDFileInfo * a0, void * a1, s32 a2, s32 a3, s32 a4) { return DVDReadPrio(a0, a1, a2, a3, a4); }
s32 fn_80065F34(char *name, u32 slot) {
    u32 i;
    char msg[0x400];
    u32 id;
    u32 *hdr;
    u32 off;
    u32 key_2;
    s32 idx;
    s32 cnt;
    u32 size;
    u32 psize;
    u32 key;
    u32 csize_2;
    s32 ret;
    u8 *bank;
    struct { s32 value; } n;
    u8 *buf;
    u8 *orig;
    struct { u32 value; } dst;
    s32 rem;
    s32 tries;
    u32 chunk;
    u32 csize;
    BOOL enabled;
    SndBankState *p;
    DVDFileInfo fi;
    void * lab_t0;
    void * tmp_call21;

    ret = 0;
    if (slot >= 16) {
        return -1;
    }
    if (lbl_801A6C80->entries[slot].unk0 + 0x10000 == 65535) {
        if (!DVDOpen(name, &fi)) {
            sprintf(msg, lbl_80092C08, name);
            return -1;
        }
        SND_ALLOC(hdr, 0x20);
        off = fn_80065F34_call_DVDReadPrio(&fi, hdr, 0x20, 0, 2);
        DCInvalidateRange(hdr, off);
        if (hdr[0] == 0x67636178) {
            if (hdr[1] == 0x4454504B) {
                if (hdr[2] >= 0x2280000) {
                    if (lbl_801A6C80->unk45F == 0) {
                        fn_80008E5C(lbl_801A6410, hdr);
                        SND_ALLOC(hdr, 0x80);
                        n.value = DVDReadPrio(&fi, hdr, 0x80, off, 2);
                        off += n.value;
                        DCInvalidateRange(hdr, n.value);
                        if (fn_80065B08(hdr) != 0) {
                            ret = -4;
                        }
                    } else {
                        off += 0x80;
                    }
                } else {
                    ret = -9;
                }
            } else {
                ret = -2;
            }

            fn_80008E5C(lbl_801A6410, hdr);
            SND_ALLOC(hdr, 0x40);
            n.value = DVDReadPrio(&fi, hdr, 0x40, off, 2);
            off += 0x20;
            lab_t0 = hdr;
            DCInvalidateRange(lab_t0, n.value);
            if (hdr[1] == 0x54424C44 && ret == 0) {
                p = lbl_801A6C80;
                idx = -1;
                cnt = (hdr[10] >> 16) & 0xFF;
                size = hdr[3];
                key = hdr[8];
                id = hdr[9];
                if (p->unk460 + cnt <= 0x40) {
                    for (i = 0; i < 16; i++) {
                        if (lbl_801A6C80->unk144[i] == key && lbl_801A6C80->unk184[i] == 0) {
                            idx = i;
                            break;
                        }
                    }
                    if (idx >= 0) {
                        bank = (u8 *)p->unk104[idx];
                        n.value = DVDReadPrio(&fi, bank, size, off, 2);
                        off += n.value;
                        DCInvalidateRange(bank, n.value);
                        lbl_801A6C80->unk184[idx] = 1;
                        lbl_801A6C80->entries[slot].unk8 = (u32)bank;
                        lbl_801A6C80->entries[slot].unkC = cnt;
                        lbl_801A6C80->entries[slot].unk0 = id;
                        lbl_801A6C80->entries[slot].unkD = hdr[11] >> 24;
                        lbl_801A6C80->entries[slot].unkE = (hdr[11] >> 16) & 0xFF;
                        lbl_801A6C80->unk478 = hdr[12];
                        lbl_801A6C80->unk47C = hdr[13];
                        lbl_801A6C80->unk460 += cnt;
                        fn_800657F4(slot);
                    } else {
                        ret = -6;
                    }
                } else {
                    ret = -5;
                }
            }

            idx = -1;
            if (ret == 0) {
                fn_80008E5C(lbl_801A6410, hdr);
                SND_ALLOC(hdr, 0x40);
                n.value = DVDReadPrio(&fi, hdr, 0x40, off, 2);
                off += 0x20;
                DCInvalidateRange(hdr, n.value);
                if (hdr[1] == 0x50434D44) {
                    p = lbl_801A6C80;
                    psize = hdr[3];
                    key_2 = hdr[8];
                    for (i = 0; i < 16; i++) {
                        if (lbl_801A6C80->unk1EC[i] == key_2 && lbl_801A6C80->unk22C[i] == 0) {
                            idx = i;
                            break;
                        }
                    }
                    if (idx >= 0) {
                        p->unk22C[idx] = 1;
                        lbl_801A6C80->entries[slot].unk4 = lbl_801A6C80->unk1AC[idx];
                        if (psize != 0) {
                            SND_ALLOC(buf, psize);
                            if (buf != NULL) {
                                n.value = DVDReadPrio(&fi, buf, psize, off, 2);
                                DCInvalidateRange(buf, n.value);
                                lbl_801A6C7C = 1;
                                ARQPostRequest(&lbl_80193B08, 0, 0, 1, (u32)buf, lbl_801A6C80->unk1AC[idx], psize, fn_80065AD0);
                                while (1) {
                                    if (lbl_801A6C7C == 0) {
                                        break;
                                    }
                                }
                            } else {
                                rem = psize;
                                if (psize >= 0x20000) {
                                    enabled = OSDisableInterrupts();
                                    tries = 20;
                                    chunk = 0x14000;
                                    do {
                                        csize = chunk;
                                        tmp_call21 = fn_80008E34(lbl_801A6410, chunk);
                                        buf = tmp_call21;
                                        if (buf != NULL) {
                                            break;
                                        }
                                        chunk -= 0x1000;
                                    } while (--tries != 0);
                                    OSRestoreInterrupts(enabled);
                                } else {
                                    buf = NULL;
                                }
                                if (buf != NULL) {
                                    dst.value = lbl_801A6C80->unk1AC[idx];
                                    orig = buf;
                                    while (rem - (s32)csize > 0) {
                                        n.value = DVDReadPrio(&fi, buf, csize, off, 2);
                                        off += n.value;
                                        rem -= n.value;
                                        DCInvalidateRange(buf, n.value);
                                        lbl_801A6C7C = 1;
                                        ARQPostRequest(&lbl_80193B08, 0, 0, 1, (u32)buf, dst.value, csize, fn_80065AC4);
                                        while (lbl_801A6C7C != 0) {
                                        }
                                        dst.value += n.value;
                                    }
                                    if (rem >= 0) {
                                        n.value = DVDReadPrio(&fi, buf, rem, off, 2);
                                        DCInvalidateRange(buf, n.value);
                                        lbl_801A6C7C = 1;
                                        ARQPostRequest(&lbl_80193B08, 0, 0, 1, (u32)orig, dst.value, rem, fn_80065AD0);
                                        while (1) {
                                            if (lbl_801A6C7C == 0) {
                                                break;
                                            }
                                        }
                                    }
                                } else {
                                    i = lbl_801A6C80->unk19C;
                                    if ((csize_2 = i) != 0) {
                                        buf = fn_80065F34_read_pointer(lbl_801A6C80);
                                        dst.value = lbl_801A6C80->unk1AC[idx];
                                        while (rem - (s32)csize_2 >= 0) {
                                            n.value = DVDReadPrio(&fi, buf, csize_2, off, 2);
                                            off += n.value;
                                            rem -= n.value;
                                            DCInvalidateRange(buf, n.value);
                                            lbl_801A6C7C = 1;
                                            ARQPostRequest(&lbl_80193B08, 0, 0, 1, (u32)buf, dst.value, csize_2, fn_80065AC4);
                                            while (lbl_801A6C7C != 0) {
                                            }
                                            dst.value += n.value;
                                        }
                                        if (rem != 0) {
                                            n.value = DVDReadPrio(&fi, buf, rem, off, 2);
                                            DCInvalidateRange(buf, n.value);
                                            lbl_801A6C7C = 1;
                                            ARQPostRequest(&lbl_80193B08, 0, 0, 1, dst.value, (u32)buf, rem, fn_80065AC4);
                                            while (1) {
                                                if (lbl_801A6C7C == 0) {
                                                    break;
                                                }
                                            }
                                        }
                                    } else {
                                        fn_80065F34_unload(slot);
                                        ret = -8;
                                    }
                                }
                            }
                        }
                    } else {
                        fn_80065F34_unload(slot);
                        ret = -7;
                    }
                } else {
                    fn_80065F34_unload(slot);
                    ret = -2;
                }
            }
        } else {
            ret = -2;
        }
        fn_80008E5C(lbl_801A6410, hdr);
        DVDClose(&fi);
    } else {
        ret = -3;
    }
    return ret;
}
