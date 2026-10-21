#include "types.h"

typedef struct Buf {
    u32 unk_0;
    u32 unk_4;
} Buf;

struct Stream;
typedef struct StreamVTable {
    u8 pad_0[0x1C];
    void (*put)(struct Stream *, s32, Buf *);
    void (*get)(struct Stream *, s32, Buf *);
} StreamVTable;

typedef struct Stream {
    StreamVTable *vtable;
} Stream;

typedef struct Resampler {
    u32 unk_0;
    u32 unk_4;
} Resampler;

typedef struct Voice {
    u8 pad_0[0x98];
    s16 state;
} Voice;

typedef struct Channel {
    u8 active;
    s8 mode;
    u8 pad_2[2];
    Voice *voice;
    Stream *mainStream;
    Stream *subStreams[2];
    Resampler mainRes;
    Resampler subRes[2];
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    u8 pad_38[8];
    s32 unk_40;
    s32 unk_44;
    u8 pad_48[8];
    void (*callback)(u32, s32, u32, u32);
    u32 callbackArg;
    u8 pad_58[0x44];
} Channel;

extern Channel lbl_801798C0[16];

extern s32 fn_80045414(Voice *);
extern void fn_80041BF8(Channel *);
extern void fn_80044E7C(Voice *);
extern u32 fn_8004550C(Voice *);
extern u32 fn_80045304(Voice *);
extern u32 fn_800452FC(Voice *);
extern void fn_800589BC(Resampler *, s32, Buf *, Buf *);
extern s32 fn_80045588(Voice *);
extern void fn_8004530C(Voice *);
extern void fn_80041EF8(Channel *);

void fn_80041700(void) {
    struct { Voice *value; } voice;
    struct { s32 value; } len;
    struct { Voice *value; } v;
    Channel *ch;
    s32 count;
    s32 i;
    struct { s32 value; } j;
    struct { Stream *value; } main;
    struct { Voice *value; } v2;
    s32 avail;
    s32 len2;
    s32 n;
    s32 lim;
    s16 state;
    Buf b;
    Buf a;

    for (i = 0; i < 16; i++) {
        ch = &lbl_801798C0[i];
        if ((s32)ch->active != 1) {
            continue;
        }
        if (ch->mode == 2) {
            voice.value = ch->voice;
            if (fn_80045414(voice.value) == 0) {
                fn_80041BF8(ch);
            }
            fn_80044E7C(voice.value);
            if (fn_80045414(voice.value) == 3) {
                len.value = 0;
                v.value = ch->voice;
                main.value = ch->mainStream;
                count = fn_8004550C(v.value);
                len.value = fn_80045304(v.value);
                lim = fn_800452FC(v.value);
                count -= ch->unk_34;
                if (lim < count) {
                    count = lim;
                }
                fn_800589BC(&ch->mainRes, len.value, &a, &b);
                main.value->vtable->get(main.value, 0, &a);
                main.value->vtable->put(main.value, 1, &b);
                for (j.value = 0; j.value < fn_80045588(ch->voice); j.value++) {
                    fn_800589BC(&ch->subRes[j.value], count * 2, &a, &b);
                    if (ch->callback != NULL) {
                        ch->callback(ch->callbackArg, j.value, a.unk_0, a.unk_4);
                    }
                    ch->subStreams[j.value]->vtable->get(ch->subStreams[j.value], 1, &a);
                    ch->subStreams[j.value]->vtable->put(ch->subStreams[j.value], 0, &b);
                }
                ch->unk_2C += count;
                ch->unk_30 += len.value;
                ch->unk_34 += count;
                ch->unk_40 += count;
                ch->unk_44 += len.value;
                fn_8004530C(v.value);
            }
            if (voice.value->state == 10 || voice.value->state == 20 || voice.value->state == 11 || voice.value->state == 15) {
                v2.value = ch->voice;
                avail = fn_8004550C(v2.value);
                len2 = fn_80045304(v2.value);
                lim = fn_800452FC(v2.value);
                n = avail - ch->unk_34;
                if (lim < n) {
                    n = lim;
                }
                ch->unk_2C += n;
                ch->unk_30 += len2;
                ch->unk_34 += n;
            }
        } else if (ch->mode == 1) {
            fn_80041EF8(ch);
        }
    }
}
