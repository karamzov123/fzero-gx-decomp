#include "types.h"

typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
    u8 bC;
    u8 bD;
    u8 bE;
    u8 bF;
} SndChan;

typedef struct {
    u32 w0;
    u32 w4;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 bB;
    u8 bC;
    u8 bD;
    u8 bE;
    u8 bF;
} SndMix;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 pad3[0xE];
    u8 b11;
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
    u8 pad16[0xA];
} SndSlot;

typedef struct {
    u8 b0;
    u8 pad1[0x27];
} SndBank;

typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[7];
    u8 b9;
    u8 bA;
    u8 padB[0x11];
    u32 w1C;
    u32 w20;
    u8 pad24[8];
    u32 w2C;
    u8 pad30[0xE8];
} SndVoice;

typedef struct {
    SndChan chan[16];       /* 0x0000 */
    u32 w100;               /* 0x0100 */
    u32 w104[16];           /* 0x0104 */
    u32 w144[16];           /* 0x0144 */
    u8 b184[16];            /* 0x0184 */
    u8 pad194[0x18];        /* 0x0194 */
    u32 w1AC[16];           /* 0x01AC */
    u32 w1EC[16];           /* 0x01EC */
    u8 b22C[16];            /* 0x022C */
    u8 pad23C[4];           /* 0x023C */
    u32 w240[64];           /* 0x0240 */
    u32 w340[64];           /* 0x0340 */
    u8 b440;
    u8 b441;
    u8 b442;
    u8 b443;
    u32 w444;
    u32 w448;
    u32 w44C;
    u8 pad450[9];
    u8 b459;
    u8 b45A;
    u8 pad45B[2];
    u8 b45D;
    u8 b45E;
    u8 b45F;
    u8 b460;
    u8 b461;
    u8 b462;
    u8 b463;
    u8 b464;
    u8 b465;
    u8 pad466[2];
    u32 w468;
    u32 w46C;
    u8 b470;
    u8 b471;
    u8 b472;
    u8 b473;
    u8 pad474[0x14];
    SndMix mix[16];         /* 0x0488 */
    SndSlot slot[64];       /* 0x0588 */
    u8 pair[16][16][4];     /* 0x0D88 */
    SndBank bank[16];       /* 0x1188 */
    SndVoice voice[64];     /* 0x1408 */
    u8 pad5A08[8];
    s16 h5A10;
    s16 h5A12;
    s16 h5A14[16];
    s16 h5A34[16];
    s16 h5A54[16];
    s16 h5A74[16];
    s16 h5A94[16];
    s16 h5AB4[16];
    s16 h5AD4[16];
    s16 h5AF4[16];
    u32 w5B14;
    u32 w5B18;
    u32 w5B1C;
    s32 w5B20;
} SndState;

extern SndState *lbl_801A6C80;
extern void fn_8006A1F8(void);

void fn_80067F68(void) {
    u32 i;
    u32 j;
    u32 k;

    lbl_801A6C80->b440 = 0;
    lbl_801A6C80->b441 = 0;
    lbl_801A6C80->b442 = 0;
    lbl_801A6C80->b443 = 0;
    lbl_801A6C80->w444 = 0;
    lbl_801A6C80->b459 = 0;
    lbl_801A6C80->w44C = 1;
    lbl_801A6C80->b45D = 1;
    lbl_801A6C80->b45A = 0;
    lbl_801A6C80->w448 = 0;
    lbl_801A6C80->w468 = 0;
    lbl_801A6C80->b45F = 0;
    lbl_801A6C80->b460 = 0;
    lbl_801A6C80->b461 = 0x7F;
    lbl_801A6C80->b462 = 1;
    lbl_801A6C80->b463 = 1;
    lbl_801A6C80->b45E = 0x40;
    lbl_801A6C80->b464 = 0;
    lbl_801A6C80->b470 = 0xFF;
    lbl_801A6C80->b471 = 0xFF;
    lbl_801A6C80->b472 = 0xFF;
    lbl_801A6C80->b473 = 0xFF;
    lbl_801A6C80->w46C = 0;
    lbl_801A6C80->b465 = 0;
    lbl_801A6C80->w5B18 = 0;
    lbl_801A6C80->w5B1C = 0;
    lbl_801A6C80->w5B20 = -1;

    for (i = 0; i < 64; i++) {
        lbl_801A6C80->w240[i] = 0;
        lbl_801A6C80->w340[i] = 0;
    }

    for (i = 0; i < 64; i++) {
        lbl_801A6C80->voice[i].b0 = 0xFF;
        lbl_801A6C80->voice[i].w1C = 0;
        lbl_801A6C80->voice[i].w20 = 0;
        lbl_801A6C80->voice[i].w2C = 0;
        lbl_801A6C80->voice[i].b1 = 0;
        lbl_801A6C80->voice[i].b9 = 0xFF;
        lbl_801A6C80->voice[i].bA = 0xFF;
    }

    for (i = 0; i < 64; i++) {
        lbl_801A6C80->slot[i].b0 = 0;
        lbl_801A6C80->slot[i].b2 = 0;
        lbl_801A6C80->slot[i].b11 = 0x40;
        lbl_801A6C80->slot[i].b12 = 0;
        lbl_801A6C80->slot[i].b13 = 0;
        lbl_801A6C80->slot[i].b14 = 0;
        lbl_801A6C80->slot[i].b15 = 0;
    }

    for (i = 0; i < 16; i++) {
        lbl_801A6C80->chan[i].w0 = -1;
        lbl_801A6C80->chan[i].w8 = 0;
        lbl_801A6C80->chan[i].bD = 0xFF;
        lbl_801A6C80->chan[i].bE = 0xFF;
        lbl_801A6C80->mix[i].b8 = 0xFF;
        lbl_801A6C80->mix[i].bA = 0x7F;
        lbl_801A6C80->mix[i].bB = 0x7F;
        lbl_801A6C80->mix[i].bC = 0x40;
        lbl_801A6C80->mix[i].bD = 0x40;
        lbl_801A6C80->b184[i] = 0;
        lbl_801A6C80->w104[i] = 0;
        lbl_801A6C80->w144[i] = 0;
        lbl_801A6C80->b22C[i] = 0;
        lbl_801A6C80->w1AC[i] = 0;
        lbl_801A6C80->w1EC[i] = 0;
        for (j = 0; j < 16; j++) {
            for (k = 0; k < 4; k++) {
                lbl_801A6C80->pair[i][j][k] = 0xFF;
            }
        }
    }

    for (i = 0; i < 16; i++) {
        lbl_801A6C80->bank[i].b0 = 0;
    }

    lbl_801A6C80->h5A10 = 0;
    lbl_801A6C80->h5A12 = 0;
    for (i = 0; i < 16; i++) {
        lbl_801A6C80->h5A14[i] = 0;
        lbl_801A6C80->h5A34[i] = 0;
        lbl_801A6C80->h5A54[i] = 0;
        lbl_801A6C80->h5AB4[i] = 0;
        lbl_801A6C80->h5AD4[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        lbl_801A6C80->h5A74[i] = 0;
        lbl_801A6C80->h5A94[i] = 0;
        lbl_801A6C80->h5AF4[i] = 0;
    }

    fn_8006A1F8();
}
