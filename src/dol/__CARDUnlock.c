#include <dolphin/card/CARDPriv.h>
#include <dolphin/dsp.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/os/OSTime.h>

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

s32 __CARDUnlock(s32 chan, u8 flashID[12]) {
    u32 init_val;
    u32 data;
    s32 dummy;
    s32 rlen;
    u32 rshift;
    u8 fsts;
    u32 wk, wk1;
    u32 Ans1 = 0;
    u32 Ans2 = 0;
    u32 *dp;
    u8 rbuf[64];
    u32 para1A = 0;
    u32 para1B = 0;
    u32 para2A = 0;
    u32 para2B = 0;
    CARDControl *card;
    DSPTaskInfo *task;
    DecodeParameters *param;
    u8 *input;
    u8 *output;
    card = &lbl_80177960[chan];
    task = &card->task;
    param = (DecodeParameters *)card->workArea;
    input = (u8 *)((u8 *)param + sizeof(DecodeParameters));
    input = (u8 *)((((u32)input + 31) & ~31));
    output = input + 32;
    fsts = 0;
    init_val = GetInitVal();
    dummy = DummyLen();
    rlen = dummy;
    if (ReadArrayUnlock(chan, init_val, rbuf, rlen, 0) < 0) {
        return -3;
    }
    rshift = (u32)(dummy * 8 + 1);
    wk = exnor_1st(init_val, rshift);
    wk1 = ~(wk ^ (wk >> 7) ^ (wk >> 15) ^ (wk >> 23));
    card->scramble = (wk | ((wk1 << 31) & 0x80000000));
    card->scramble = bitrev(card->scramble);
    dummy = DummyLen();
    rlen = 20 + dummy;
    data = 0;
    if (ReadArrayUnlock(chan, data, rbuf, rlen, 1) < 0) {
        return -3;
    }
    dp = (u32 *)rbuf;
    para1A = *dp++;
    para1B = *dp++;
    Ans1 = *dp++;
    para2A = *dp++;
    para2B = *dp++;
    para1A = (para1A ^ card->scramble);
    rshift = 32;
    wk = exnor(card->scramble, rshift);
    wk1 = ~(wk ^ (wk << 7) ^ (wk << 15) ^ (wk << 23));
    card->scramble = (wk | ((wk1 >> 31) & 0x00000001));
    para1B = (para1B ^ card->scramble);
    rshift = 32;
    wk = exnor(card->scramble, rshift);
    wk1 = ~(wk ^ (wk << 7) ^ (wk << 15) ^ (wk << 23));
    card->scramble = (wk | ((wk1 >> 31) & 0x00000001));
    Ans1 ^= card->scramble;
    rshift = 32;
    wk = exnor(card->scramble, rshift);
    wk1 = ~(wk ^ (wk << 7) ^ (wk << 15) ^ (wk << 23));
    card->scramble = (wk | ((wk1 >> 31) & 0x00000001));
    para2A = (para2A ^ card->scramble);
    rshift = 32;
    wk = exnor(card->scramble, rshift);
    wk1 = ~(wk ^ (wk << 7) ^ (wk << 15) ^ (wk << 23));
    card->scramble = (wk | ((wk1 >> 31) & 0x00000001));
    para2B = (para2B ^ card->scramble);
    rshift = (u32)(dummy * 8);
    wk = exnor(card->scramble, rshift);
    wk1 = ~(wk ^ (wk << 7) ^ (wk << 15) ^ (wk << 23));
    card->scramble = (wk | ((wk1 >> 31) & 0x00000001));
    rshift = 32 + 1;
    wk = exnor(card->scramble, rshift);
    wk1 = ~(wk ^ (wk << 7) ^ (wk << 15) ^ (wk << 23));
    card->scramble = (wk | ((wk1 >> 31) & 0x00000001));
    *(u32 *)&input[0] = para2A;
    *(u32 *)&input[4] = para2B;
    param->inputAddr = input;
    param->inputLength = 8;
    param->outputAddr = output;
    param->aramAddr = 0;
    DCFlushRange(input, 8);
    DCInvalidateRange(output, 4);
    DCFlushRange(param, sizeof(DecodeParameters));
    task->priority = 255;
    task->iram_mmem_addr = (u16 *)((void *)((u32)(lbl_8012AA60) + (0x8000 << 16)));
    task->iram_length = 0x160;
    task->iram_addr = 0;
    task->dsp_init_vector = 0x10;
    task->init_cb = InitCallback;
    task->res_cb = ((void *)0);
    task->done_cb = DoneCallback;
    task->req_cb = ((void *)0);
    DSPAddTask(task);
    dp = (u32 *)flashID;
    *dp++ = para1A;
    *dp++ = para1B;
    *dp = Ans1;
    return 0;
}
