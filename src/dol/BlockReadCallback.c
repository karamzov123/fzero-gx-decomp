#include <dolphin/card/CARDPriv.h>
#include <dolphin/dsp.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/os/OSTime.h>


/* --- dol/__CARDUnlock.c --- */
DSPTaskInfo *DSPAddTask(DSPTaskInfo *task);

extern CARDControl lbl_80177960[2];

void InitCallback(void *task);

void DoneCallback(void *task);

extern u8 lbl_8012AA60[];

extern unsigned long int lbl_801A6510;

static inline int CARDRand(void) {
    lbl_801A6510 = lbl_801A6510 * 1103515245 + 12345;
    return (int)((unsigned int)(lbl_801A6510 / 65536) % 32768);
}

static inline void CARDSrand(unsigned int seed) { lbl_801A6510 = seed; }

static inline u32 GetInitVal(void) {
    u32 tmp;
    u32 tick;
    tick = OSGetTick();
    CARDSrand(tick);
    tmp = 0x7fec8000;
    tmp |= CARDRand();
    tmp &= 0xfffff000;
    return tmp;
}

static inline u32 exnor_1st(u32 data, u32 rshift) {
    u32 wk;
    u32 w;
    u32 i;
    w = data;
    for (i = 0; i < rshift; i++) {
        wk = ~(w ^ (w >> 7) ^ (w >> 15) ^ (w >> 23));
        w = (w >> 1) | ((wk << 30) & 0x40000000);
    }
    return w;
}

static inline u32 exnor(u32 data, u32 lshift) {
    u32 wk;
    u32 w;
    u32 i;
    w = data;
    for (i = 0; i < lshift; i++) {
        wk = ~(w ^ (w << 7) ^ (w << 15) ^ (w << 23));
        w = (w << 1) | ((wk >> 30) & 0x00000002);
    }
    return w;
}

u32 bitrev(u32 data);

s32 ReadArrayUnlock(s32 chan, u32 data, void *rbuf, s32 rlen, s32 mode);

s32 DummyLen(void);

void InitCallback(void *_task);

void DoneCallback(void *_task);

s32 __CARDUnlock(s32 chan, u8 flashID[12]);

/* --- dol/InitCallback.c --- */
u32 DSPCheckMailToDSP(void);
void DSPSendMailToDSP(u32 mail);


extern unsigned long int next;

void InitCallback(void *_task);

/* --- dol/DoneCallback.c --- */
BOOL EXIProbe(s32 chan);
s32 ReadArrayUnlock(s32 chan, u32 data, void *rbuf, s32 rlen, s32 mode);
s32 DummyLen(void);




void DoneCallback(void *_task);

/* --- dol/CARDRdwr.c --- */
void BlockReadCallback(s32 chan, s32 result);

void BlockWriteCallback(s32 chan, s32 result);


void BlockReadCallback(s32 chan, s32 result) {
    CARDControl *card;
    CARDCallback callback;
    card = &lbl_80177960[chan];
    if (result < 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    card->xferred += 512u;
    card->addr += 512u;
    (u8 *)card->buffer += 512u;
    if (--card->repeat <= 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    result = __CARDReadSegment(chan, BlockReadCallback);
    if (result < 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    return;
error:
    if (card->apiCallback == 0) {
        __CARDPutControlBlock(card, result);
    }
    callback = card->xferCallback;
    if (callback) {
        card->xferCallback = 0;
        callback(chan, result);
    }
}

s32 __CARDRead(s32 chan, u32 addr, s32 length, void *dst, CARDCallback callback) {
    CARDControl *card;
    card = &lbl_80177960[chan];
    if (!card->attached) {
        return -3;
    }
    card->xferCallback = callback;
    card->repeat = (int)(length / 512u);
    card->addr = addr;
    card->buffer = dst;
    return __CARDReadSegment(chan, BlockReadCallback);
}

void BlockWriteCallback(s32 chan, s32 result) {
    CARDControl *card;
    CARDCallback callback;
    card = &lbl_80177960[chan];
    if (result < 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    card->xferred += 128u;
    card->addr += 128u;
    (u8 *)card->buffer += 128u;
    if (--card->repeat <= 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    result = __CARDWritePage(chan, BlockWriteCallback);
    if (result < 0) {
        goto error; // fzgx-allow: S1 SDK error cleanup path
    }
    return;
error:
    if (card->apiCallback == 0) {
        __CARDPutControlBlock(card, result);
    }
    callback = card->xferCallback;
    if (callback) {
        card->xferCallback = 0;
        callback(chan, result);
    }
}

s32 __CARDWrite(s32 chan, u32 addr, s32 length, void *dst, CARDCallback callback) {
    CARDControl *card;
    card = &lbl_80177960[chan];
    if (!card->attached) {
        return -3;
    }
    card->xferCallback = callback;
    card->repeat = (int)(length / 128u);
    card->addr = addr;
    card->buffer = dst;
    return __CARDWritePage(chan, BlockWriteCallback);
}
