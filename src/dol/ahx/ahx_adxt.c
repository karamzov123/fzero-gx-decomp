#include "types.h"

typedef struct AhxPlayer AhxPlayer;

/* The decoder work area of an ADXT object, as far as the AHX hooks use it. */
typedef struct AhxAdxDecoder {
    u8 pad_0[4];
    s32 state;
    u8 pad_8[0x80];
    u32 decoded;
    u8 pad_8C[4];
    u32 delta;
    u32 consumed;
    u8 pad_98[0x18];
    AhxPlayer *player;
    u8 pad_B4[4];
    s32 steps;
} AhxAdxDecoder;

typedef struct AhxAdxSjd {
    u8 pad_0[4];
    AhxAdxDecoder *decoder;
} AhxAdxSjd;

typedef struct AhxAdxt {
    u8 pad_0[4];
    AhxAdxSjd *sjd;
    u8 pad_8[8];
    void *input;
    u8 pad_14[4];
    u8 output[1];
} AhxAdxt;

typedef void (*AhxAdxtHook)(AhxAdxt *adxt);

extern AhxAdxtHook lbl_8017E58C;
extern void (*lbl_8017A280)(AhxAdxDecoder *);
extern void (*lbl_8017A284)(AhxPlayer *, void *);

extern void ADXT_Stop(AhxAdxt *adxt);
extern void fn_80047464(const char *, const char *);
extern void fn_8004EBB4(void);
extern void fn_8004EBD4(void);
extern u32 fn_80053EA0(AhxPlayer *);
extern u32 fn_80053EA8(AhxPlayer *);
extern void fn_80053EB0(AhxPlayer *);
extern void fn_800541EC(AhxPlayer *);
extern void fn_80054224(AhxPlayer *);
extern void fn_800542B4(AhxPlayer *, void *);
extern int fn_800542BC(AhxPlayer *);
extern void fn_800542C8(AhxPlayer *);
extern AhxPlayer *fn_80054354(void *, s32, void *, void *, u32);
extern s32 fn_800545B0(void);
extern s32 fn_80054608(void);

void fn_80051CC0(AhxAdxDecoder *decoder) {
    s32 i;
    AhxPlayer *player;

    fn_8004EBD4();
    player = decoder->player;
    if (fn_800542BC(player) == 0) {
        decoder->decoded = 0;
        fn_800541EC(player);
    }
    if (decoder->state == 1) {
        decoder->decoded = 0;
        fn_80054224(player);
        decoder->state = 2;
    } else if (decoder->state == 2) {
        for (i = 0; i < decoder->steps; i++) {
            fn_80053EB0(player);
        }
        decoder->delta = fn_80053EA0(player) - decoder->decoded;
        decoder->decoded += decoder->delta;
        decoder->consumed = fn_80053EA8(player);
        if (fn_800542BC(player) == 3) {
            fn_800541EC(player);
            decoder->state = 0;
        }
    }
    fn_8004EBB4();
}

void fn_80051DC4(AhxAdxt *adxt) {
    AhxAdxDecoder *decoder;
    AhxPlayer *player;

    ADXT_Stop(adxt);
    decoder = adxt->sjd->decoder;
    player = decoder->player;
    if (player != 0) {
        fn_8004EBD4();
        fn_800541EC(player);
        fn_800542C8(player);
        decoder->player = 0;
        fn_8004EBB4();
        fn_800545B0();
    }
}

void fn_80051E30(AhxAdxt *adxt) {
    if (lbl_8017E58C != 0) {
        lbl_8017E58C(adxt);
    }
}

void fn_80051E64(AhxAdxt *adxt, void *work, u32 size) {
    AhxAdxSjd *sjd;
    AhxAdxDecoder *decoder;
    void *input;
    AhxPlayer *player;

    ADXT_Stop(adxt);
    if (lbl_8017E58C != 0) {
        lbl_8017E58C(adxt);
    }
    fn_80054608();
    sjd = adxt->sjd;
    input = adxt->input;
    decoder = sjd->decoder;
    fn_8004EBD4();
    player = fn_80054354(input, 1, adxt->output, work, size);
    if (player == 0) {
        fn_80047464("E1052501 ADXT_AttachAHX", "can not attach AHX.");
    } else {
        decoder->player = player;
        lbl_8017E58C = fn_80051DC4;
        lbl_8017A280 = fn_80051CC0;
        lbl_8017A284 = fn_800542B4;
        fn_8004EBB4();
    }
}
