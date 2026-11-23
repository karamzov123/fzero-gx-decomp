#include "sasnd/sasnd.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "sdk_addresses.h"
#include "dolphin/dvd.h"
#pragma use_lmw_stmw on

typedef struct DVDFileInfo DVDFileInfo;
typedef void (*DVDCallback)(s32 result, DVDFileInfo *fileInfo);
struct DVDFileInfo {
    DVDCommandBlock cb;
    u32 startAddr;
    u32 length;
    DVDCallback callback;
};

/* the AX voice block read by the sequencer tick */
typedef struct SndAxVoice {
    u8 pad_0[0x146];
    u16 state;
} SndAxVoice;

/* sound bank file header: magics "gcax" and "DTPK" at +0x0, "TBLD" at +0xA4 */
typedef struct SndFileHeader {
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
} SndFileHeader;

/* the block after the TBLD data: magic "PCMD" at +0x4 */
typedef struct SndFileChunk {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[4];
    u32 unk_C;
    u8 pad_10[0x10];
    u32 unk_20;
} SndFileChunk;

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern u32 OSGetTick(void);
extern BOOL DVDOpen(char *, DVDFileInfo *);
extern s32 DVDReadPrio(DVDFileInfo *, void *, s32, s32, s32);
extern BOOL DVDClose(DVDFileInfo *);
extern void DCInvalidateRange(void *, u32);
extern void ARQPostRequest(ARQRequest *, u32, u32, u32, u32, u32, u32, ARQCallback);
extern u32 ARAlloc(u32);
extern u32 ARFree(u32 *);
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern int sprintf(char *, const char *, ...);
extern double floor(double);
extern void *fn_80008E34(u32, u32);
extern void fn_80008E5C(u32, void *);
extern void fn_800211E0(u32, u32);
extern void fn_800211EC(u32, u32);
extern u32 fn_80024378(void *);
extern u32 fn_80024DF0(void *);
extern s32 fn_800253F0(void *);
extern s16 fn_80025C70(void *);
extern void fn_80026D90(void *, s32);
extern s32 fn_80026DB8(void *);
extern void fn_8005CBF4(u32);
extern void fn_8005FCD8(u32);
extern void fn_8005FDE0(u32);
extern u32 fn_8006060C(u32);
extern void fn_800622B0(void);
extern void fn_800631EC(void);
extern u32 fn_80064D4C(u8, u32);
extern void fn_800657F4(u8);
extern s32 fn_80069CE4(u32, s32, s16);
extern void fn_8006A1F8(void);

extern u32 lbl_801A6410;
SndFx3 lbl_801932A8;
SndFx3 lbl_80193308;
SndFx2 lbl_80193368;
SndFx2 lbl_80193404;
SndFx1 lbl_801934A0;
SndFx1 lbl_80193680;
SndFx0 lbl_80193860;
SndFx0 lbl_801939B4;
ARQRequest lbl_80193B08;
ARQRequest lbl_80193B28;
SndState lbl_80193B48;
SndState *lbl_801A6C80;
volatile s32 lbl_801A6C7C; /* Updated asynchronously by the ARQ callback while polling. */
BOOL lbl_801A6C78;
static const char lbl_80092BD8[] = "\nsasnd Ver 1.13h Build:Jul  1 2003 21:06:15\n";
static const char lbl_80092C08[] = "Cannot open %s";
static const char lbl_80092C18[] = "Not Sound Allocation Size %d";
static const u16 lbl_80092C38[132] = {
    0xA3D7, 0x6D3A, 0x51EB, 0x4189, 0x369D, 0x2ECF, 0x28F5, 0x2468, 0x20C4, 0x1DCA, 0x1B4E, 0x1934,
    0x1767, 0x15D8, 0x147A, 0x1346, 0x1234, 0x113F, 0x1062, 0x0F9A, 0x0EE5, 0x0E3F, 0x0DA7, 0x0D1B,
    0x0C9A, 0x0C22, 0x0BB3, 0x0B4C, 0x0AEC, 0x0A92, 0x0A3D, 0x09EE, 0x09A3, 0x095C, 0x091A, 0x08D8,
    0x089F, 0x0866, 0x0831, 0x07EE, 0x07CD, 0x079E, 0x0772, 0x0748, 0x071F, 0x06F8, 0x06D3, 0x06AF,
    0x068D, 0x066C, 0x064D, 0x062E, 0x0611, 0x05F5, 0x05D9, 0x05BF, 0x05A6, 0x058D, 0x0576, 0x055F,
    0x0549, 0x0533, 0x051E, 0x050A, 0x04F7, 0x04E4, 0x04D1, 0x04BF, 0x04AE, 0x049D, 0x048D, 0x047D,
    0x046D, 0x045E, 0x044F, 0x0441, 0x0433, 0x0425, 0x0418, 0x040B, 0x03FF, 0x03F2, 0x03E6, 0x03DA,
    0x03CF, 0x03C4, 0x03B9, 0x03AE, 0x03A4, 0x0399, 0x038F, 0x0386, 0x037C, 0x0373, 0x0369, 0x0360,
    0x0357, 0x034F, 0x0346, 0x033E, 0x0336, 0x032E, 0x0326, 0x031E, 0x0317, 0x030F, 0x0308, 0x0301,
    0x02FA, 0x02F3, 0x02EC, 0x02E6, 0x02DF, 0x02D9, 0x02D3, 0x02CC, 0x02C6, 0x02C0, 0x02BB, 0x02B5,
    0x02AF, 0x02AA, 0x02A4, 0x029F, 0x0299, 0x0294, 0x028F, 0x028A, 0x0000, 0x0000, 0x0000, 0x0000
};
/* 4,200 signed 16-bit samples of concatenated oscillator waveforms: a 64-sample sine cycle at the
 * start, a sawtooth ramp at +0x440, noise, and a constant tail. It is copied to ARAM at init. */
static const s16 lbl_80092D40[4200] = {
#include "sasnd/wave_table.inc"
};
const char *const lbl_801A7328 = lbl_80092BD8;
extern u8 lbl_801A6608[8];

void fn_80065AC4(u32 request);
void fn_80065AD0(u32 request);
s32 fn_80065B08(u32 arg0);
void fn_80068EB4(void);
void fn_800692A4(u32 arg0);
void fn_8006953C(u32 cmd);

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_801932A8;
    s = *(u8 *)&lbl_80193308;
    s = *(u8 *)&lbl_80193368;
    s = *(u8 *)&lbl_80193404;
    s = *(u8 *)&lbl_801934A0;
    s = *(u8 *)&lbl_80193680;
    s = *(u8 *)&lbl_80193860;
    s = *(u8 *)&lbl_801939B4;
    s = *(u8 *)&lbl_80193B08;
    s = *(u8 *)&lbl_80193B28;
    s = *(u8 *)&lbl_80193B48;
}
#pragma section code_type ".text"

static inline s32 QueuePush(u32 value) {
    s32 status = 0;

    if (lbl_801A6C80->busy != 0) {
        status = -3;
    } else {
        lbl_801A6C80->busy = -1;
        if ((value & 0x80000000) == 0) {
            status = -2;
        } else {
            BOOL enabled;
            enabled = OSDisableInterrupts();
            lbl_801A6C78 = enabled;
            if (lbl_801A6C80->inCount < 64 && lbl_801A6C80->inQueue[lbl_801A6C80->inWrite] == 0) {
                lbl_801A6C80->inQueue[lbl_801A6C80->inWrite] = value;
                lbl_801A6C80->inWrite = (lbl_801A6C80->inWrite + 1) & 0x3F;
                lbl_801A6C80->inCount = lbl_801A6C80->inCount + 1;
            } else {
                status = -1;
            }
            OSRestoreInterrupts(lbl_801A6C78);
        }
        lbl_801A6C80->busy = 0;
    }
    return status;
}

s32 fn_800658B4(s32 arg0, u32 arg1) {
    s32 status;
    u32 lab_t0;
    switch (arg0) {
    case 0xA4000000:
        lab_t0 = (arg1 & 0x7F00) - 0x5B900000;
        status = QueuePush(lab_t0);
        if (status != 0) {
            return status;
        }
        arg1 = ((arg1 & 0x7F) << 8) - 0x5C000000;
        break;
    default:
        return -2;
    }
    return QueuePush(arg1);
}

void fn_80065A7C(u32 arg0) {
    if (lbl_801A6C80->outCount >= 0x40) {
        return;
    }
    lbl_801A6C80->outQueue[lbl_801A6C80->outWrite] = arg0;
    lbl_801A6C80->outWrite = (lbl_801A6C80->outWrite + 1) & 0x3f;
    lbl_801A6C80->outCount = lbl_801A6C80->outCount + 1;
}

void fn_80065AC4(u32 request) {
    lbl_801A6C7C = 0;
}

void fn_80065AD0(u32 request) {
    u32 source = ((ARQRequest *)request)->source;

    if (source != 0) {
        fn_80008E5C(lbl_801A6410, (void *)source);
    }
    lbl_801A6C7C = 0;
}

#pragma opt_dead_assignments off
s32 fn_80065B08(u32 arg0) {
 u32 v0; s32 v1; u32 v2; s32 v3; s32 v4;
 u32 v5; u32 v6; u32 v7; s32 v8; u32 v9; u32 v10; u32 v11; u32 v12;
 u32 v13; u32 v14; u32 v15; u32 v16; u32 v17; u32 v18;
 u32 v19; u32 v20; s32 v21; s32 v22;
 u32 v23; u32 v24; u32 v25; u32 v26; u32 v27; u32 v28; u32 v29; u32 v30;
 s32 result;
 u32 v31; u32 v32; u32 v33; u32 v34;
 result = 0; v1 = 0; v2 = arg0; v4 = 1;
 for(v4=1;v4<16;v4++) {
 v5 = *(u32 *)v2;
 v1 += v5;
 v6 = (u32)lbl_801A6C80 + v4 * 4;
 v7 = *(u32 *)(v6 + 256);
 v8 = v7;
 *(u32 *)((u8 *)v6 + 320) = v5;
 v8 = v8 + v5;
 if(v8 <= lbl_801A6C80->unk_104[0] + lbl_801A6C80->unk_194)
 *(u32 *)((u8 *)lbl_801A6C80 + v4 * 4 + 260) = v8;
 else {result=-1; break;}
 v2+=4;
 }
 first_done:
 if(result==0) {
 v17=*(u32 *)v2; v1+=v17;
 lbl_801A6C80->unk_144[15]=v17;
 lbl_801A6C80->unk_198=(u8 *)(lbl_801A6C80->unk_104[0]+v1);
 v2+=4; v22=1;
 lbl_801A6C80->unk_19C=lbl_801A6C80->unk_194-v1;
 for(v22=1;v22<16;v22++) {
 v23=*(u32 *)v2;
 v24=(u32)lbl_801A6C80+v22*4;
 v25=*(u32 *)(v24+424);
 v26=v25;
 *(u32 *)((u8 *)v24+488)=v23;
 v26=v26+v23;
 if(v26<=lbl_801A6C80->unk_1AC[0]+lbl_801A6C80->unk_23C)
 *(u32 *)(((v22*4) + (((u8 *)lbl_801A6C80) + (428))))=v26;
 else {result=-1; break;}
 v2+=4;
 }
 second_done:
 if(result==0) lbl_801A6C80->unk_1EC[15]=*(u32 *)v2;
 }
 if(result==0) lbl_801A6C80->unk_45F=1;
 return result;
}
#pragma opt_dead_assignments reset


s32 fn_80065D70(u32 arg0) {
    s32 ret;
    u32 i;

    ret = 0;
    if (arg0 >= 16) {
        ret = -1;
    } else if (lbl_801A6C80->chan[arg0].unk_0 + 0x10000 != 65535) {
        fn_8006060C(arg0);
        fn_80064D4C(arg0, 0);
        fn_80064D4C(arg0, 1);
        lbl_801A6C80->unk_460 -= lbl_801A6C80->chan[arg0].unk_C;
        lbl_801A6C80->chan[arg0].unk_0 = -1;
        lbl_801A6C80->chan[arg0].unk_E = 0xFF;
        lbl_801A6C80->chan[arg0].id = 0xFF;
        lbl_801A6C80->chan[arg0].unk_C = 0;
        for (i = 0; i < 16; i++) {
            if (lbl_801A6C80->unk_104[i] == (u32)lbl_801A6C80->chan[arg0].bank) {
                lbl_801A6C80->unk_184[i] = 0;
                lbl_801A6C80->chan[arg0].bank = NULL;
            }
            if (lbl_801A6C80->unk_1AC[i] == lbl_801A6C80->chan[arg0].base) {
                lbl_801A6C80->unk_22C[i] = 0;
                lbl_801A6C80->chan[arg0].base = 0;
            }
        }
    } else {
        ret = -2;
    }
    return ret;
}

static inline void fn_80065F34_unload(u32 arg0) {
    u32 i;

    if (arg0 >= 16) {
    } else if (lbl_801A6C80->chan[arg0].unk_0 + 0x10000 != 65535) {
        fn_8006060C(arg0);
        fn_80064D4C(arg0, 0);
        fn_80064D4C(arg0, 1);
        lbl_801A6C80->unk_460 -= lbl_801A6C80->chan[arg0].unk_C;
        lbl_801A6C80->chan[arg0].unk_0 = -1;
        lbl_801A6C80->chan[arg0].unk_E = 0xFF;
        lbl_801A6C80->chan[arg0].id = 0xFF;
        lbl_801A6C80->chan[arg0].unk_C = 0;
        for (i = 0; i < 16; i++) {
            if (lbl_801A6C80->unk_104[i] == (u32)lbl_801A6C80->chan[arg0].bank) {
                lbl_801A6C80->unk_184[i] = 0;
                lbl_801A6C80->chan[arg0].bank = NULL;
            }
            if (lbl_801A6C80->unk_1AC[i] == lbl_801A6C80->chan[arg0].base) {
                lbl_801A6C80->unk_22C[i] = 0;
                lbl_801A6C80->chan[arg0].base = 0;
            }
        }
    }
}

#define SND_ALLOC(dst, sz) { BOOL en = OSDisableInterrupts(); dst = fn_80008E34(lbl_801A6410, sz); OSRestoreInterrupts(en); }
static inline s32 fn_80065F34_read_size(SndState * owner) { return owner->unk_19C; }
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
    s32 read_len;
    u32 key;
    s32 pidx;
    s32 ret;
    u8 *bank;
    struct { s32 value; } n;
    u8 *buf;
    struct { u32 value; } dst;
    s32 rem;
    s32 tries;
    u32 chunk;
    BOOL enabled;
    SndState *p;
    DVDFileInfo fi;
    s32 len;

    ret = 0;
    if (slot >= 16) {
        return -1;
    }
    if (lbl_801A6C80->chan[slot].unk_0 + 0x10000 == 65535) {
        if (!DVDOpen(name, &fi)) {
            sprintf(msg, lbl_80092C08, name);
            return -1;
        }
        SND_ALLOC(hdr, 0x20);
        len = DVDReadPrio(&fi, hdr, 0x20, 0, 2);
        off = len;
        DCInvalidateRange(hdr, len);
        if (hdr[0] == 0x67636178) {
            if (hdr[1] == 0x4454504B) {
                if (hdr[2] >= 0x2280000) {
                    if (lbl_801A6C80->unk_45F == 0) {
                        fn_80008E5C(lbl_801A6410, hdr);
                        SND_ALLOC(hdr, 0x80);
                        n.value = DVDReadPrio(&fi, hdr, 0x80, off, 2);
                        off += n.value;
                        DCInvalidateRange(hdr, n.value);
                        if (fn_80065B08((u32)hdr) != 0) {
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
            DCInvalidateRange(hdr, n.value);
            if (hdr[1] == 0x54424C44 && ret == 0) {
                p = lbl_801A6C80;
                idx = -1;
                cnt = (hdr[10] >> 16) & 0xFF;
                size = hdr[3];
                key = hdr[8];
                id = hdr[9];
                if (p->unk_460 + cnt <= 0x40) {
                    for (i = 0; i < 16; i++) {
                        if (lbl_801A6C80->unk_144[i] == key && lbl_801A6C80->unk_184[i] == 0) {
                            idx = i;
                            break;
                        }
                    }
                    if (idx >= 0) {
                        bank = (u8 *)p->unk_104[idx];
                        n.value = DVDReadPrio(&fi, bank, size, off, 2);
                        off += n.value;
                        DCInvalidateRange(bank, n.value);
                        lbl_801A6C80->unk_184[idx] = 1;
                        lbl_801A6C80->chan[slot].bank = (SndBank *)bank;
                        lbl_801A6C80->chan[slot].unk_C = cnt;
                        lbl_801A6C80->chan[slot].unk_0 = id;
                        lbl_801A6C80->chan[slot].id = hdr[11] >> 24;
                        lbl_801A6C80->chan[slot].unk_E = (hdr[11] >> 16) & 0xFF;
                        lbl_801A6C80->unk_478 = hdr[12];
                        lbl_801A6C80->unk_47C = hdr[13];
                        lbl_801A6C80->unk_460 += cnt;
                        fn_800657F4(slot);
                    } else {
                        ret = -6;
                    }
                } else {
                    ret = -5;
                }
            }

            pidx = -1;
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
                        if (lbl_801A6C80->unk_1EC[i] == key_2 && lbl_801A6C80->unk_22C[i] == 0) {
                            pidx = i;
                            break;
                        }
                    }
                    if (pidx >= 0) {
                        p->unk_22C[pidx] = 1;
                        lbl_801A6C80->chan[slot].base = lbl_801A6C80->unk_1AC[pidx];
                        if (psize != 0) {
                            SND_ALLOC(buf, psize);
                            if (buf != NULL) {
                                n.value = DVDReadPrio(&fi, buf, psize, off, 2);
                                DCInvalidateRange(buf, n.value);
                                lbl_801A6C7C = 1;
                                ARQPostRequest(&lbl_80193B08, 0, 0, 1, (u32)buf, lbl_801A6C80->unk_1AC[pidx], psize, fn_80065AD0);
                                while (1) {
                                    if (lbl_801A6C7C == 0) {
                                        break;
                                    }
                                }
                            } else {
                                rem = psize;
                                if (psize >= 0x20000) {
                                    enabled = OSDisableInterrupts();
                                    for (tries = 20, chunk = 0x14000; tries != 0; tries--, chunk -= 0x1000) {
                                        psize = chunk;
                                        buf = fn_80008E34(lbl_801A6410, chunk);
                                        if (buf != NULL) {
                                            break;
                                        }
                                    }
                                    OSRestoreInterrupts(enabled);
                                } else {
                                    buf = NULL;
                                }
                                if (buf != NULL) {
                                    read_len = psize;
                                    dst.value = lbl_801A6C80->unk_1AC[pidx];
                                    while ((s32)(rem - psize) > 0) {
                                        n.value = DVDReadPrio(&fi, buf, read_len, off, 2);
                                        off += n.value;
                                        rem -= n.value;
                                        DCInvalidateRange(buf, n.value);
                                        lbl_801A6C7C = 1;
                                        ARQPostRequest(&lbl_80193B08, 0, 0, 1, (u32)buf, dst.value, psize, fn_80065AC4);
                                        while (lbl_801A6C7C != 0) {
                                        }
                                        dst.value += n.value;
                                    }
                                    if (rem >= 0) {
                                        n.value = DVDReadPrio(&fi, buf, rem, off, 2);
                                        DCInvalidateRange(buf, n.value);
                                        lbl_801A6C7C = 1;
                                        ARQPostRequest(&lbl_80193B08, 0, 0, 1, (u32)buf, dst.value, rem, fn_80065AD0);
                                        while (1) {
                                            if (lbl_801A6C7C == 0) {
                                                break;
                                            }
                                        }
                                    }
                                } else {
                                    if ((psize = fn_80065F34_read_size(lbl_801A6C80)) != 0) {
                                        buf = lbl_801A6C80->unk_198;
                                        dst.value = lbl_801A6C80->unk_1AC[pidx];
                                        while ((s32)(rem - psize) >= 0) {
                                            n.value = DVDReadPrio(&fi, buf, psize, off, 2);
                                            off += n.value;
                                            rem -= n.value;
                                            DCInvalidateRange(buf, n.value);
                                            lbl_801A6C7C = 1;
                                            ARQPostRequest(&lbl_80193B08, 0, 0, 1, (u32)buf, dst.value, psize, fn_80065AC4);
                                            while (lbl_801A6C7C != 0) {
                                            }
                                            dst.value += n.value;
                                        }
                                        if (rem != 0) {
                                            n.value = DVDReadPrio(&fi, buf, rem, off, 2);
                                            DCInvalidateRange(buf, n.value);
                                            lbl_801A6C7C = 1;
                                            ARQPostRequest(&lbl_80193B08, 0, 0, 1, (u32)buf, dst.value, rem, fn_80065AC4);
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

static inline s32 inline_fn_80065D70(u32 arg0) {
    s32 ret;
    u32 i;

    ret = 0;
    if (arg0 >= 16) {
        ret = -1;
    } else if (lbl_801A6C80->chan[arg0].unk_0 != 0xFFFFFFFF) {
        fn_8006060C(arg0);
        fn_80064D4C(arg0, 0);
        fn_80064D4C(arg0, 1);
        lbl_801A6C80->unk_460 -= lbl_801A6C80->chan[arg0].unk_C;
        lbl_801A6C80->chan[arg0].unk_0 = -1;
        lbl_801A6C80->chan[arg0].unk_E = 0xFF;
        lbl_801A6C80->chan[arg0].id = 0xFF;
        lbl_801A6C80->chan[arg0].unk_C = 0;
        for (i = 0; i < 16; i++) {
            if (lbl_801A6C80->unk_104[i] == (u32)lbl_801A6C80->chan[arg0].bank) {
                lbl_801A6C80->unk_184[i] = 0;
                lbl_801A6C80->chan[arg0].bank = NULL;
            }
            if (lbl_801A6C80->unk_1AC[i] == lbl_801A6C80->chan[arg0].base) {
                lbl_801A6C80->unk_22C[i] = 0;
                lbl_801A6C80->chan[arg0].base = 0;
            }
        }
    } else {
        ret = -2;
    }
    return ret;
}

s32 fn_80066C14(SndFileHeader *data, u32 arg1) {
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
    SndFileChunk *chunk;
    u32 length;
    u32 src;

    ret = 0;
    if (arg1 >= 16) {
        return -1;
    }
    if (lbl_801A6C80->chan[arg1].unk_0 == 0xFFFFFFFF) {
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
                if (lbl_801A6C80->unk_460 + count <= 0x40) {
                    for (i = 0; i < 16; i++) {
                        if (lbl_801A6C80->unk_144[i] == key && lbl_801A6C80->unk_184[i] == 0) {
                            slot = i;
                            break;
                        }
                    }
                    if (slot >= 0) {
                        dst = lbl_801A6C80->unk_104[slot];
                        memcpy((void *)dst, (u8 *)data + off, size);
                        off += size;
                        lbl_801A6C80->unk_184[slot] = 1;
                        lbl_801A6C80->chan[arg1].bank = (SndBank *)dst;
                        lbl_801A6C80->chan[arg1].unk_C = count;
                        lbl_801A6C80->chan[arg1].unk_0 = word;
                        lbl_801A6C80->chan[arg1].id = data->unk_CC;
                        lbl_801A6C80->chan[arg1].unk_E = data->unk_CD;
                        lbl_801A6C80->unk_478 = data->unk_D0;
                        lbl_801A6C80->unk_47C = data->unk_D4;
                        lbl_801A6C80->unk_460 += count;
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
                chunk = (SndFileChunk *)((u32)data + off);
                if (chunk->unk_4 == 'PCMD') {
                    length = chunk->unk_C;
                    key = chunk->unk_20;
                    for (i = 0; i < 16; i++) {
                        if (lbl_801A6C80->unk_1EC[i] == key && lbl_801A6C80->unk_22C[i] == 0) {
                            slot2 = i;
                            break;
                        }
                    }
                    if (slot2 >= 0) {
                        lbl_801A6C80->unk_22C[slot2] = 1;
                        src = (u32)data + (off + 0x20);
                        lbl_801A6C80->chan[arg1].base = lbl_801A6C80->unk_1AC[slot2];
                        if (length != 0) {
                            lbl_801A6C7C = 1;
                            ARQPostRequest(&lbl_80193B08, 0, 0, 1, src, lbl_801A6C80->unk_1AC[slot2], length,
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

s32 fn_800672E4(u32 arg0, s32 arg1) {
    u8 *base;
    u32 offset;
    if (arg0 >= 0x10) {
        return -0x80;
    }
    switch (arg1) {
    case (s32)0xA0040000:
        base = (u8 *)lbl_801A6C80;
        offset = arg0 << 4;
        return base[offset + 0x492];
    case (s32)0xA0100000:
        base = (u8 *)lbl_801A6C80;
        offset = arg0 << 4;
        return base[offset + 0x493];
    default:
        return -0x80;
    }
}


s32 fn_80067344(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u8 *p;
    s32 ret;
    s32 val;

    val = (0x1F & arg0) + ((((arg1 - 1) & 0xF) << 24));
    val = val + arg2;
    if (arg2 != 0) {
        switch (arg2) {
        case 0xB0780000:
            break;
        case 0xB0270000:
        case 0xB0070000:
        case 0xB00D0000:
        case 0xB00E0000:
        case 0xB02D0000:
        case 0xB02E0000:
            val += (arg3 & 0x7F) << 8;
            break;
        case 0xA0110000:
        case 0xB00A0000:
        case 0xB02A0000:
            val += ((arg3 + 0x40) & 0x7F) << 8;
            break;
        default:
            return -2;
        }
    }
    ret = 0;
    p = (u8 *)lbl_801A6C80;
    if ((s8)p[0x464] != 0) {
        ret = -3;
    } else {
        *(s8 *)(p + 0x464) = -1;
        if ((val & 0x80000000) == 0) {
            ret = -2;
        } else {
            lbl_801A6C78 = OSDisableInterrupts();
            p = (u8 *)lbl_801A6C80;
            if (p[0x441] < 0x40 && ((u32 *)(p + 0x240))[p[0x443]] == 0) {
                ((u32 *)(p + 0x240))[p[0x443]] = val;
                p = (u8 *)lbl_801A6C80;
                p[0x443] = (p[0x443] + 1) & 0x3F;
                p = (u8 *)lbl_801A6C80;
                p[0x441] = p[0x441] + 1;
            } else {
                ret = -1;
            }
            OSRestoreInterrupts(lbl_801A6C78);
        }
        p = (u8 *)lbl_801A6C80;
        p[0x464] = 0;
    }
    return ret;
}

s32 fn_800674FC(u32 id, s32 command, s16 value) {
    s32 result;
    u32 message;
    s32 i;
    u16 port;

    port = id;
    message = (id & 0x1F) + command;
    if (command & 0x00FF0000) {
        switch (command) {
        case 0xA0010000:
        case 0xA0040000:
        case 0xA0090000:
        case 0xA00A0000:
        case 0xA0100000:
        case 0xA0190000:
        case 0xA01C0000:
            message += (value & 0x7F) << 8;
            break;
        case 0xA0050000:
        case 0xA0070000:
        case 0xA0110000:
            message += ((value + 0x40) & 0x7F) << 8;
            break;
        case 0xA0280000:
        case 0xA0290000:
            message += ((value - 1) & 0xF) << 8;
            break;
        case 0xA0310000:
            lbl_801A6C80->unk_5A12 = value;
            break;
        case 0xA0340000:
            if (port & 0x10) {
                for (i = 0; i < 16; i++) {
                    lbl_801A6C80->unk_5AB4[i] = value;
                }
            } else {
                lbl_801A6C80->unk_5AB4[(u16)id] = value;
            }
            break;
        case 0xA0400000:
            if (port & 0x10) {
                for (i = 0; i < 16; i++) {
                    lbl_801A6C80->unk_5AD4[i] = value;
                }
            } else {
                lbl_801A6C80->unk_5AD4[(u16)id] = value;
            }
            break;
        case 0xA0020000:
        case 0xA0030000:
            break;
        default:
            return -2;
        }
    }

    result = 0;
    if (lbl_801A6C80->busy) {
        result = -3;
    } else {
        lbl_801A6C80->busy = -1;
        if (!(message & 0x80000000)) {
            result = -2;
        } else {
            lbl_801A6C78 = OSDisableInterrupts();
            if (lbl_801A6C80->inCount < 64 && lbl_801A6C80->inQueue[lbl_801A6C80->inWrite] == 0) {
                lbl_801A6C80->inQueue[lbl_801A6C80->inWrite] = message;
                lbl_801A6C80->inWrite = (lbl_801A6C80->inWrite + 1) & 0x3F;
                lbl_801A6C80->inCount++;
            } else {
                result = -1;
            }
            OSRestoreInterrupts(lbl_801A6C78);
        }
        lbl_801A6C80->busy = 0;
    }
    return result;
}

s32 fn_80067898(u32 value) {
    s32 result = 0;
    SndState *queue;

    queue = lbl_801A6C80;
    if (queue->busy != 0) {
        return -3;
    }

    queue->busy = -1;
    if ((value & 0x80000000) == 0) {
        result = -2;
    } else {
        lbl_801A6C78 = OSDisableInterrupts();
        queue = lbl_801A6C80;
        if (queue->inCount < 0x40 && queue->inQueue[queue->inWrite] == 0) {
            queue->inQueue[queue->inWrite] = value;
            queue = lbl_801A6C80;
            queue->inWrite = (queue->inWrite + 1) & 0x3f;
            queue = lbl_801A6C80;
            queue->inCount++;
        } else {
            result = -1;
        }
        OSRestoreInterrupts(lbl_801A6C78);
    }

    queue = lbl_801A6C80;
    queue->busy = 0;
    return result;
}


u32 __OSBusClock : FZGX_ADDR___OSBusClock;
#define OS_BUS_CLOCK __OSBusClock
#define OS_TIMER_CLOCK (OS_BUS_CLOCK / 4)

void fn_80067974(void) {
    u32 tick;
    u32 elapsed;
    u8 i;
    u8 n;
    SndNote *motion;
    u32 msg;
    s32 r;
    s32 active;
    u16 count;
    u8 type;

    if (lbl_801A6C80->ready != 1) {
        return;
    }
    lbl_801A6C80->ready = 0;
    tick = OSGetTick();
    /* OSTicksToMilliseconds, rounded */
    elapsed = floor((f32)(0.5 + (f32)(((tick - lbl_801A6C80->lastTick) * 8) / (OS_TIMER_CLOCK / 125000)) / 1000.0));
    lbl_801A6C80->elapsed = elapsed;
    if (elapsed != 0) {
        for (i = 0; i < 0x10; i++) {
            active = lbl_801A6C80->seq[i].flags;
            if (active != 0 && !(active & 1)) {
                lbl_801A6C80->seq[i].wait -= lbl_801A6C80->seq[i].tempo * elapsed;
            }
        }
    }
    lbl_801A6C80->lastTick = tick;

    for (i = 0; i < 0x40; i++) {
        type = lbl_801A6C80->voice[i].state;
        if (type == 0xFF) {
            continue;
        }
        if (((SndAxVoice *)lbl_801A6C80->voice[i].obj)->state == 0) {
            if (type != 4 || lbl_801A6C80->voice[i].active != 0) {
                fn_8005FCD8(i);
            }
        } else if (lbl_801A6C80->voice[i].active == 2) {
            if (type == 3) {
                r = fn_80026DB8(lbl_801A6C80->voice[i].obj);
                if (lbl_801A6C80->voice[i].unk_E == 0 || r <= -450) {
                    fn_8005FCD8(i);
                } else {
                    lbl_801A6C80->voice[i].unk_E--;
                    r += lbl_801A6C80->voice[i].step;
                    fn_80026D90(lbl_801A6C80->voice[i].obj, r);
                }
            } else if (lbl_801A6C80->voice[i].unk_E == 2 && lbl_801A6C80->voice[i].unk_BC == (s32)0xFC400000) {
                fn_8005FCD8(i);
            }
        } else if (lbl_801A6C80->voice[i].active == 1) {
            if (lbl_801A6C80->voice[i].unk_E == 0 && lbl_801A6C80->voice[i].unk_BC == 0) {
                motion = lbl_801A6C80->voice[i].note;
                lbl_801A6C80->voice[i].unk_B4 = motion->unk_E << 16;
                lbl_801A6C80->voice[i].unk_B8 = motion->unk_10 << 16;
                lbl_801A6C80->voice[i].unk_E = 1;
            }
        }
    }

    n = lbl_801A6C80->budget;
    if (lbl_801A6C80->inCount != 0) {
        do {
            msg = lbl_801A6C80->inQueue[lbl_801A6C80->inRead];
            if ((msg >> 24) == 0xA0) {
                if (lbl_801A6C80->outCount < 0x40) {
                    lbl_801A6C80->outQueue[lbl_801A6C80->outWrite] = msg | 0x40;
                    lbl_801A6C80->outWrite = (lbl_801A6C80->outWrite + 1) & 0x3F;
                    lbl_801A6C80->outCount++;
                }
                fn_8006953C(msg | 0x40);
            } else if ((msg >> 24) < 0xA8) {
                if (lbl_801A6C80->outCount < 0x40) {
                    lbl_801A6C80->outQueue[lbl_801A6C80->outWrite] = msg;
                    lbl_801A6C80->outWrite = (lbl_801A6C80->outWrite + 1) & 0x3F;
                    lbl_801A6C80->outCount++;
                }
            } else if ((msg >> 24) < 0xAD) {
                fn_8006953C(msg);
            } else {
                if (lbl_801A6C80->outCount < 0x40) {
                    lbl_801A6C80->outQueue[lbl_801A6C80->outWrite] = msg;
                    lbl_801A6C80->outWrite = (lbl_801A6C80->outWrite + 1) & 0x3F;
                    lbl_801A6C80->outCount++;
                }
            }
            n--;
            lbl_801A6C80->inQueue[lbl_801A6C80->inRead] = 0;
            lbl_801A6C80->inRead = (lbl_801A6C80->inRead + 1) & 0x3F;
            lbl_801A6C80->inCount--;
        } while (lbl_801A6C80->inCount != 0 && n != 0);
    }

    if (lbl_801A6C80->outCount != 0) {
        do {
            fn_8005FDE0(lbl_801A6C80->outQueue[lbl_801A6C80->outRead]);
            lbl_801A6C80->outQueue[lbl_801A6C80->outRead] = 0;
            lbl_801A6C80->outRead = (lbl_801A6C80->outRead + 1) & 0x3F;
            lbl_801A6C80->outCount--;
        } while (lbl_801A6C80->outCount != 0);
    }

    fn_80068EB4();
    lbl_801A6C80->frames++;
    lbl_801A6C80->ready = 1;
}

u32 fn_80067DE4(void) {
	SndState *base;
	SndState *base_2;
	u32 val;
	char buf[0x404];

	base = lbl_801A6C80;
	base->command = 0xA0000110;

	fn_8005CBF4(0xA0000100);
	fn_800622B0();
	fn_80069CE4(0x10, 0xA0000500, 0);

	base_2 = lbl_801A6C80;
	if (base_2->unk_454 == 0) {
		fn_80008E5C(lbl_801A6410, (void *)base_2->unk_100);
		ARFree(&val);
		base_2 = lbl_801A6C80;
		if (base_2->unk_23C != val) {
			sprintf(buf, lbl_80092C18, val);
			return val;
		}
	}

	base_2 = lbl_801A6C80;
	switch (base_2->unk_470) {
	case 0:
		fn_80024DF0(&lbl_801939B4);
		break;
	case 1:
		fn_80024378(&lbl_80193680);
		break;
	case 2:
		fn_800253F0(&lbl_80193404);
		break;
	case 3:
		fn_80025C70(&lbl_80193308);
		break;
	}
	fn_800211E0(0, 0);

	base_2 = lbl_801A6C80;
	switch (base_2->unk_471) {
	case 0:
		fn_80024DF0(&lbl_80193860);
		break;
	case 1:
		fn_80024378(&lbl_801934A0);
		break;
	case 2:
		fn_800253F0(&lbl_80193368);
		break;
	case 3:
		fn_80025C70(&lbl_801932A8);
		break;
	}
	fn_800211EC(0, 0);
	return 0;
}

void fn_80067F68(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5) {
    u32 i;
    u32 j;
    u32 k;

    lbl_801A6C80->outCount = 0;
    lbl_801A6C80->inCount = 0;
    lbl_801A6C80->outRead = 0;
    lbl_801A6C80->inWrite = 0;
    lbl_801A6C80->command = 0;
    lbl_801A6C80->outWrite = 0;
    lbl_801A6C80->unk_44C = 1;
    lbl_801A6C80->ready = 1;
    lbl_801A6C80->inRead = 0;
    lbl_801A6C80->unk_448 = 0;
    lbl_801A6C80->frames = 0;
    lbl_801A6C80->unk_45F = 0;
    lbl_801A6C80->unk_460 = 0;
    lbl_801A6C80->masterVolume = 0x7F;
    lbl_801A6C80->unk_462 = 1;
    lbl_801A6C80->unk_463 = 1;
    lbl_801A6C80->budget = 0x40;
    lbl_801A6C80->busy = 0;
    lbl_801A6C80->unk_470 = 0xFF;
    lbl_801A6C80->unk_471 = 0xFF;
    lbl_801A6C80->unk_472 = 0xFF;
    lbl_801A6C80->unk_473 = 0xFF;
    lbl_801A6C80->unk_46C = 0;
    lbl_801A6C80->unk_465 = 0;
    lbl_801A6C80->unk_5B18 = 0;
    lbl_801A6C80->callback = 0;
    lbl_801A6C80->unk_5B20 = -1;

    for (i = 0; i < 64; i++) {
        lbl_801A6C80->inQueue[i] = 0;
        lbl_801A6C80->outQueue[i] = 0;
    }

    for (i = 0; i < 64; i++) {
        lbl_801A6C80->voice[i].state = 0xFF;
        lbl_801A6C80->voice[i].note = 0;
        lbl_801A6C80->voice[i].hdr = 0;
        lbl_801A6C80->voice[i].obj = 0;
        lbl_801A6C80->voice[i].active = 0;
        lbl_801A6C80->voice[i].link0 = 0xFF;
        lbl_801A6C80->voice[i].link1 = 0xFF;
    }

    for (i = 0; i < 64; i++) {
        lbl_801A6C80->slot[i].unk_0 = 0;
        lbl_801A6C80->slot[i].unk_2 = 0;
        lbl_801A6C80->slot[i].unk_11 = 0x40;
        lbl_801A6C80->slot[i].unk_12 = 0;
        lbl_801A6C80->slot[i].unk_13 = 0;
        lbl_801A6C80->slot[i].unk_14 = 0;
        lbl_801A6C80->slot[i].unk_15 = 0;
    }

    for (i = 0; i < 16; i++) {
        lbl_801A6C80->chan[i].unk_0 = -1;
        lbl_801A6C80->chan[i].bank = 0;
        lbl_801A6C80->chan[i].id = 0xFF;
        lbl_801A6C80->chan[i].unk_E = 0xFF;
        lbl_801A6C80->mix[i].unk_8 = 0xFF;
        lbl_801A6C80->mix[i].unk_A = 0x7F;
        lbl_801A6C80->mix[i].unk_B = 0x7F;
        lbl_801A6C80->mix[i].unk_C = 0x40;
        lbl_801A6C80->mix[i].unk_D = 0x40;
        lbl_801A6C80->unk_184[i] = 0;
        lbl_801A6C80->unk_104[i] = 0;
        lbl_801A6C80->unk_144[i] = 0;
        lbl_801A6C80->unk_22C[i] = 0;
        lbl_801A6C80->unk_1AC[i] = 0;
        lbl_801A6C80->unk_1EC[i] = 0;
        for (j = 0; j < 16; j++) {
            for (k = 0; k < 4; k++) {
                lbl_801A6C80->voiceMap[i][j][k] = 0xFF;
            }
        }
    }

    for (i = 0; i < 16; i++) {
        lbl_801A6C80->seq[i].flags = 0;
    }

    lbl_801A6C80->unk_5A10 = 0;
    lbl_801A6C80->unk_5A12 = 0;
    for (i = 0; i < 16; i++) {
        lbl_801A6C80->chanLevel[i] = 0;
        lbl_801A6C80->unk_5A34[i] = 0;
        lbl_801A6C80->unk_5A54[i] = 0;
        lbl_801A6C80->unk_5AB4[i] = 0;
        lbl_801A6C80->unk_5AD4[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        lbl_801A6C80->trackLevel[i] = 0;
        lbl_801A6C80->unk_5A94[i] = 0;
        lbl_801A6C80->trackLevelInit[i] = 0;
    }

    fn_8006A1F8();
}

const s16 *const lbl_801A7348 = lbl_80092D40;

s32 fn_80068BFC(u32 arg0,u32 arg1,u32 arg2,u32 arg3,u32 arg4,u32 arg5) {
    BOOL enabled;
    u32 *buffer;
    u32 i;
    arg5 = (u32)lbl_801A7328;
    lbl_801A6C78 = 0;
    lbl_801A6C7C = 0;
    lbl_801A6C80 = &lbl_80193B48;
    fn_80067F68(arg0,arg1,arg2,arg3,arg4,arg5);
    fn_800631EC();
    if (arg1 == 0) return -1;
    if (arg2 == 0) return -2;
    lbl_801A6C80->unk_194 = arg1;
    lbl_801A6C80->unk_23C = arg2 - 0x21e0;
    lbl_801A6C80->unk_454 = arg0;
    if (arg0 != 0) {
        if (arg3 == 0) return -3;
        if (arg4 == 0) return -4;
        lbl_801A6C80->unk_1A0 = arg4;
        lbl_801A6C80->unk_1A4 = lbl_801A6C80->unk_1A0;
        lbl_801A6C80->unk_100 = arg3;
    } else {
        lbl_801A6C80->unk_1A0 = ARAlloc(arg2);
        lbl_801A6C80->unk_1A4 = lbl_801A6C80->unk_1A0;
        enabled = OSDisableInterrupts();
        lbl_801A6C80->unk_100 = (u32)fn_80008E34(lbl_801A6410,arg1);
        OSRestoreInterrupts(enabled);
    }
    arg4 = OSDisableInterrupts();
    buffer = (u32 *)fn_80008E34(lbl_801A6410,0x100);
    OSRestoreInterrupts(arg4);
    for (i = 0; i < 64; i++) buffer[i] = 0;
    lbl_801A6C7C = 1;
    ARQPostRequest(&lbl_80193B28,0,0,1,(u32)buffer,lbl_801A6C80->unk_1A4,0x100,fn_80065AD0);
    while (lbl_801A6C7C != 0) {}
    lbl_801A6C7C = 1;
    ARQPostRequest(&lbl_80193B28,0,0,1,(u32)lbl_801A7348,lbl_801A6C80->unk_1A4 + 0x100,0x20e0,fn_80065AC4);
    while (lbl_801A6C7C != 0) {}
    lbl_801A6C80->unk_1AC[0] = lbl_801A6C80->unk_1A4 + 0x21e0;
    lbl_801A6C80->unk_1A8 = lbl_801A6C80->unk_1A4 + 0x100;
    lbl_801A6C80->unk_104[0] = lbl_801A6C80->unk_100;
    fn_800211E0(0,0);
    fn_800211EC(0,0);
    return 0;
}


/* Sentinel stored in SeqTrack.loop: no return address pending. */
#define SEQ_NO_LOOP 0xFF000000u

#pragma opt_lifetimes off
void fn_80068EB4(void) {
    u8 i;
    u8 *q;
    u8 *p;
    s32 flags;
    u32 msg;
    u32 w;
    u32 cmd;
    u32 arg;
    s32 c;
    u32 s;
    u32 b;
    u32 lo;
    u32 more;
    u32 b0;
    u32 b1;

    for (i = 0; i < 16; i++) {
        flags = ((i)[lbl_801A6C80->seq]).flags;
        if (flags == 0) {
            continue;
        }
        if (flags & 2) {
            ((i)[lbl_801A6C80->seq]).vol += ((i)[lbl_801A6C80->seq]).volStep;
            if (((i)[lbl_801A6C80->seq]).vol < 0) {
                ((i)[lbl_801A6C80->seq]).vol = 0;
            } else if (((i)[lbl_801A6C80->seq]).vol > 0x7F0000) {
                ((i)[lbl_801A6C80->seq]).vol = 0x7F0000;
            }
        }
        if (((i)[lbl_801A6C80->seq]).flags & 2) {
            ((i)[lbl_801A6C80->seq]).vol &= 0x7F0000;
            if (((i)[lbl_801A6C80->seq]).vol != ((i)[lbl_801A6C80->seq]).prevVol) {
                ((i)[lbl_801A6C80->seq]).prevVol = ((i)[lbl_801A6C80->seq]).vol;
                fn_80065A7C((((i)[lbl_801A6C80->seq]).vol << 8) | 0xA01C0000 | ((i)[lbl_801A6C80->seq]).chan);
                if (((i)[lbl_801A6C80->seq]).vol == 0) {
                    fn_80065A7C(((i)[lbl_801A6C80->seq]).chan | 0xA0000000 | 0x1200);
                    ((i)[lbl_801A6C80->seq]).flags = 0;
                } else if (((i)[lbl_801A6C80->seq]).vol == 0x7F0000) {
                    ((i)[lbl_801A6C80->seq]).flags &= 0xF9;
                }
            }
        }
        if ((((i)[lbl_801A6C80->seq]).wait >> 16) > 0) {
            continue;
        }
        p = ((i)[lbl_801A6C80->seq]).cur;
    top:
        /* labels: the event parser restarts from two nested loops */
        q = p;
        c = *p;
        if (c == 0xFF) {
            p = (u8 *)((i)[lbl_801A6C80->seq]).loop;
            if ((u32)p == SEQ_NO_LOOP) {
                ((i)[lbl_801A6C80->seq]).flags = 0;
                continue;
            }
            for (;;) {
                w = *(u32 *)p;
                p += 4;
                cmd = w >> 24;
                arg = w & 0xFFFFFF;
                if (cmd == 0) {
                    break;
                }
                if (cmd != 0x80) {
                    p = ((i)[lbl_801A6C80->seq]).base + arg;
                    if (cmd != 0x90) {
                        if (arg == 0) {
                            ((i)[lbl_801A6C80->seq]).flags = 0;
                            goto next; /* leave both loops */
                        }
                        ((i)[lbl_801A6C80->seq]).loop = SEQ_NO_LOOP;
                        goto top; /* resume parsing at p */
                    }
                } else {
                    fn_80065A7C((arg << 8) | ((i)[lbl_801A6C80->seq]).chan | 0x80);
                    if (((i)[lbl_801A6C80->seq]).flags & 0x18) {
                        msg = 0xA01C0000;
                        if (((i)[lbl_801A6C80->seq]).flags & 8) {
                            ((i)[lbl_801A6C80->seq]).flags &= 0xF5;
                        } else {
                            ((i)[lbl_801A6C80->seq]).flags &= 0xEF;
                            msg |= 0x7F00;
                        }
                        msg |= ((i)[lbl_801A6C80->seq]).chan;
                        fn_80065A7C(msg);
                    }
                }
            }
            /* command 0: call, the return address goes to loop */
            ((i)[lbl_801A6C80->seq]).loop = (u32)p;
            p = ((i)[lbl_801A6C80->seq]).base + arg;
            goto top; /* resume parsing at p */
        }
        if (c & 0x80) {
            ((i)[lbl_801A6C80->seq]).status = *q;
            s = *q++;
        } else {
            s = ((i)[lbl_801A6C80->seq]).status;
        }
        b = *q++;
        lo = b & 0x7F;
        msg = (s << 24) | (lo << 16);
        more = b & 0x80;
        switch (s & 0xF0) {
        case 0x90:
        case 0xA0:
        case 0xB0:
        case 0xF0:
            b = *q++;
            msg |= (b & 0x7F) << 8;
            more = b & 0x80;
            break;
        case 0xE0:
            msg = (msg & 0xFF00FFFF) | (lo << 8);
            break;
        case 0xD0:
            if (((i)[lbl_801A6C80->seq]).flags2 & 0x80) {
                b1 = ((1)[q]);
                b0 = ((0)[q]);
                q += 2;
                msg &= 0xBFFFFFFF;
                msg |= ((b0 & 0x7F) << 8) | ((b1 & 0x7F) << 4);
                more = b1 & 0x80;
            }
            break;
        }
        msg |= ((i)[lbl_801A6C80->seq]).chan;
        fn_80065A7C(msg);
        if (more & 0x80) {
            p = q;
            goto top; /* another event follows without a delta time */
        }
        msg = *q++;
        if (msg & 0x80) {
            msg = (msg & 0x7F) << 7;
            msg = (msg | (*q++ & 0x7F)) & 0x3FFF;
        }
        ((i)[lbl_801A6C80->seq]).wait += msg << 16;
        ((i)[lbl_801A6C80->seq]).cur = q;
    next:;
    }
}
#pragma opt_lifetimes reset


void fn_800692A4(u32 arg0) {
    u32 v0;
    u32 v2;
    u32 v1;
    u8 i;

    if ((arg0 & 0xFF00) > 0x1900) return;
    v0 = arg0 & ~0xFF;
    v1 = arg0 & 0xF;
    v2 = arg0 & 0x80;
    switch (v0) {
    case (s32)0xA0000100:
        for (i = 0; i < 16; i++) {
            if (v2 == 0) {
                lbl_801A6C80->seq[i].flags = 0;
            } else {
                if (v1 == lbl_801A6C80->seq[i].chan) {
                    if ((lbl_801A6C80->seq[i].flags2 & 0x80) != 0) {
                        lbl_801A6C80->seq[i].flags = 0;
                    }
                } else {
                    lbl_801A6C80->seq[i].flags = 0;
                }
            }
        }
        break;
    case (s32)0xA0000200:
        for (i = 0; i < 16; i++) {
            if ((lbl_801A6C80->seq[i].flags2 & 0x80) == 0) {
                if (v2 == 0) {
                    lbl_801A6C80->seq[i].flags = 0;
                } else if (v1 != lbl_801A6C80->seq[i].chan) {
                    lbl_801A6C80->seq[i].flags = 0;
                }
            }
        }
        break;
    case (s32)0xA0000300:
        for (i = 0; i < 16; i++) {
            if ((lbl_801A6C80->seq[i].flags2 & 0x80) != 0)
                lbl_801A6C80->seq[i].flags = 0;
        }
        break;
    case (s32)0xA0001100:
        for (i = 0; i < 16; i++) {
            if (v1 == lbl_801A6C80->seq[i].chan) {
                if (v2 == 0) {
                    lbl_801A6C80->seq[i].flags = 0;
                } else if ((lbl_801A6C80->seq[i].flags2 & 0x80) != 0) {
                    lbl_801A6C80->seq[i].flags = 0;
                }
            }
        }
        break;
    case (s32)0xA0001200:
        if (v2 != 0) return;
        for (i = 0; i < 16; i++) {
            if (v1 == lbl_801A6C80->seq[i].chan &&
                (lbl_801A6C80->seq[i].flags2 & 0x80) == 0)
                lbl_801A6C80->seq[i].flags = 0;
        }
        break;
    case (s32)0xA0001300:
        for (i = 0; i < 16; i++) {
            if (v1 == lbl_801A6C80->seq[i].chan &&
                (lbl_801A6C80->seq[i].flags2 & 0x80) != 0)
                lbl_801A6C80->seq[i].flags = 0;
        }
        break;
    }
}

static inline void fn_8006953C_loop1(u32 cmd) {
    u8 i;
            for (i = 0; i < 16; i++) {
                if ((cmd & 0xF) == lbl_801A6C80->seq[i].chan && (s32)lbl_801A6C80->seq[i].flags != 0 &&
                    !(lbl_801A6C80->seq[i].flags2 & 0x80)) {
                    lbl_801A6C80->seq[i].flags &= ~1;
                }
            }
}

static inline void fn_8006953C_loop2(u32 cmd) {
    u8 i;
    for (i = 0; i < 16; i++) {
        if ((s32)lbl_801A6C80->seq[i].flags != 0 && (lbl_801A6C80->seq[i].flags2 & 0x80) &&
            (cmd & 0xF) == lbl_801A6C80->seq[i].chan) {
            lbl_801A6C80->seq[i].flags |= 6;
            lbl_801A6C80->seq[i].volStep = lbl_80092C38[(cmd >> 8) & 0x7F];
            lbl_801A6C80->seq[i].volStep = (lbl_801A6C80->seq[i].volStep ^ 0xFFFFFFFF) + 1;
        }
    }
}

void fn_8006953C(u32 cmd) {
    SndChan *fzgx_live;
    u8 idx;
    u8 *d;
    s8 found;
    struct { u8 value; } i;
    u8 j;
    u8 hit;
    u32 *p;
    u32 ofs;
    u32 off;
    u8 *rec;
    u32 sub;
    u8 *tbl;
    u8 flags;
    u8 * rec_2;

    found = -1;

    if ((cmd >> 24) == 0xA0) {
        if ((cmd & 0x00FF0000) > 0xA0000) {
            return;
        }
        switch (cmd & 0x00FF0000) {
        case 0:
            fn_800692A4(cmd);
            break;
        case 0x20000:
            for (i.value = 0; i.value < 16; i.value++) {
                if ((cmd & 0xF) == lbl_801A6C80->seq[i.value].chan && (s32)lbl_801A6C80->seq[i.value].flags != 0 &&
                    !(lbl_801A6C80->seq[i.value].flags2 & 0x80)) {
                    lbl_801A6C80->seq[i.value].flags |= 1;
                }
            }
            break;
        case 0x30000:
            fn_8006953C_loop1(cmd);
            break;
        case 0x60000:
            break;
        case 0x90000:
            lbl_801A6C80->unk_458 = cmd & 0xF;
            lbl_801A6C80->unk_448 = lbl_80092C38[((0x7F) & ((cmd >> 8)))];
            break;
        case 0xA0000:
            fn_8006953C_loop2(cmd);
            break;
        }
        return;
    }

    hit = 0;
    for (i.value = 0; i.value < 16; i.value++) {
        fzgx_live = lbl_801A6C80->chan;
        d = (u8 *)fzgx_live[i.value].bank;
        if (d == NULL) {
            continue;
        }
        p = (u32 *)(d + 0x24);
        ofs = 4;
        tbl = (u8 *)(*p + (u32)d);
        for (j = 0; j <= tbl[0]; ofs += 4, j++) {
            p = (u32 *)(tbl + ofs);
            if ((*p >> 16) == (cmd >> 16)) {
                hit = 1;
                break;
            }
        }
        if (hit) {
            found = i.value;
            break;
        }
    }

    if (found != -1) {
    rec = tbl + (*p & 0xFFFF);
    sub = (cmd >> 8) & 0xFF;
    if (sub > rec[0]) {
        return;
    }
    rec = (u8 *)((sub << 2) + (u32)rec); off = *(u32 *)(rec + 4);
    if (off == 0) {
        return;
    }
    rec_2 = tbl + off;
    idx = 0x7F;
    flags = rec_2[0];
    if (!(flags & 0x80)) {
        for (i.value = 0; i.value < 16; i.value++) {
            if ((s32)lbl_801A6C80->seq[i.value].flags != 0 && lbl_801A6C80->seq[i.value].chan == found &&
                !(lbl_801A6C80->seq[i.value].flags2 & 0x80)) {
                idx = i.value;
                break;
            }
        }
    } else if ((flags & 0x10) == 0x10) {
        for (i.value = 0; i.value < 16; i.value++) {
            if ((s32)lbl_801A6C80->seq[i.value].flags != 0 && (lbl_801A6C80->seq[i.value].flags2 & 0xF) == (flags & 0xF)) {
                idx = i.value;
                break;
            }
        }
    }
    if (idx == 0x7F) {
        for (i.value = 0; i.value < 16; i.value++) {
            if ((s32)lbl_801A6C80->seq[i.value].flags == 0) {
                idx = i.value;
                break;
            }
        }
    }
    if (idx == 0x7F) {
        for (i.value = 0; i.value < 16; i.value++) {
            if (lbl_801A6C80->seq[i.value].flags2 & 0x80) {
                idx = i.value;
                break;
            }
        }
    }

    lbl_801A6C80->seq[idx].chan = found;
    lbl_801A6C80->seq[idx].tempo = 0x10000;
    lbl_801A6C80->seq[idx].cmd = cmd;
    lbl_801A6C80->seq[idx].wait = 0;
    lbl_801A6C80->seq[idx].flags2 = rec_2[0];
    if (!(lbl_801A6C80->seq[idx].flags2 & 0x80)) {
        lbl_801A6C80->seq[idx].flags = 0x90;
        lbl_801A6C80->seq[idx].base = rec_2;
        lbl_801A6C80->seq[idx].loop = (u32)(rec_2 + 4);
        lbl_801A6C80->seq[idx].cur = lbl_801A6608;
        if (lbl_801A6C80->unk_448 == 0) {
            lbl_801A6C80->seq[idx].vol = 0x7F0000;
            lbl_801A6C80->seq[idx].prevVol = 0x7F0000;
        } else if (lbl_801A6C80->unk_458 == found) {
            lbl_801A6C80->seq[idx].volStep = lbl_801A6C80->unk_448;
            lbl_801A6C80->seq[idx].vol = 0;
            lbl_801A6C80->seq[idx].prevVol = 0;
            lbl_801A6C80->seq[idx].flags ^= 0x98;
            lbl_801A6C80->unk_448 = 0;
        } else {
            lbl_801A6C80->seq[idx].vol = 0x7F0000;
            lbl_801A6C80->seq[idx].prevVol = 0x7F0000;
        }
    } else {
        lbl_801A6C80->seq[idx].flags = 0x80;
        lbl_801A6C80->seq[idx].loop = 0xFF000000;
        lbl_801A6C80->seq[idx].cur = rec_2 + 1;
    }
    fn_80068EB4();
    } else if (lbl_801A6C80->callback != NULL) {
        lbl_801A6C80->callback(-3, cmd);
    }
}

void fn_80069AE0(void) {
    u32 flags = lbl_801A6C80->command;

    if ((flags & 0x40) == 0) {
        fn_8006953C(flags);
    }
}
