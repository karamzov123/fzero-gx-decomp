#include <dolphin/card/CARDPriv.h>

BOOL EXIProbe(s32 chan);
s32 ReadArrayUnlock(s32 chan, u32 data, void *rbuf, s32 rlen, s32 mode);
s32 DummyLen(void);

extern CARDControl lbl_80177960[2];

extern unsigned long int next;

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

void DoneCallback(void *_task) {
    u8 rbuf[64];
    u32 data;
    s32 dummy;
    s32 rlen;
    u32 rshift;
    u8 unk;
    u32 wk, wk1;
    u32 Ans2;
    s32 chan;
    CARDControl *card;
    s32 result;
    DSPTaskInfo *task;
    DecodeParameters *param;
    u8 *input;
    u8 *output;
    task = _task;
    for (chan = 0; chan < 2; ++chan) {
        card = &lbl_80177960[chan];
        if ((DSPTaskInfo *)&card->task == task) {
            break;
        }
    }
    param = (DecodeParameters *)card->workArea;
    input = (u8 *)((u8 *)param + sizeof(DecodeParameters));
    input = (u8 *)((((u32)input + 31) & ~31));
    output = input + 32;
    Ans2 = *(u32 *)output;
    dummy = DummyLen();
    rlen = dummy;
    data = ((Ans2 ^ card->scramble) & 0xffff0000);
    if (ReadArrayUnlock(chan, data, rbuf, rlen, 1) < 0) {
        EXIUnlock(chan);
        __CARDMountCallback(chan, -3);
        return;
    }
    rshift = (u32)((dummy + 4 + card->latency) * 8 + 1);
    wk = exnor(card->scramble, rshift);
    wk1 = ~(wk ^ (wk << 7) ^ (wk << 15) ^ (wk << 23));
    card->scramble = (wk | ((wk1 >> 31) & 0x00000001));
    dummy = DummyLen();
    rlen = dummy;
    data = (((Ans2 << 16) ^ card->scramble) & 0xffff0000);
    if (ReadArrayUnlock(chan, data, rbuf, rlen, 1) < 0) {
        EXIUnlock(chan);
        __CARDMountCallback(chan, -3);
        return;
    }
    result = __CARDReadStatus(chan, &unk);
    if (!EXIProbe(chan)) {
        EXIUnlock(chan);
        __CARDMountCallback(chan, -3);
        return;
    }
    if (result == 0 && !(unk & 0x40)) {
        EXIUnlock(chan);
        result = -5;
    }
    __CARDMountCallback(chan, result);
}
