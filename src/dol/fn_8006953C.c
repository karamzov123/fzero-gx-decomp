#include "types.h"

typedef struct {
    u32 w0;
    u32 w4;
    u8 *w8;
    u8 bC;
    u8 bD;
    u8 bE;
    u8 bF;
} SndChan;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u32 w4;
    u32 w8;
    u32 wC;
    u8 *w10;
    u32 w14;
    void *w18;
    u32 w1C;
    u32 w20;
    u32 w24;
} SndBank;

typedef struct {
    SndChan chan[16];       /* 0x0000 */
    u8 pad100[0x448 - 0x100];
    u32 w448;
    u8 pad44C[0x458 - 0x44C];
    u8 b458;
    u8 pad459[0x1188 - 0x459];
    SndBank bank[16];       /* 0x1188 */
    u8 pad1408[0x5B1C - 0x1408];
    void (*cb1C)(s32, u32);
} SndState;

extern SndState *lbl_801A6C80;
extern const u16 lbl_80092C38[];
extern u8 lbl_801A6608[8];
extern void fn_800692A4(u32);
extern void fn_80068EB4(void);

static inline void fn_8006953C_loop1(u32 cmd) {
    u8 i;
            for (i = 0; i < 16; i++) {
                if ((cmd & 0xF) == lbl_801A6C80->bank[i].b2 && (s32)lbl_801A6C80->bank[i].b0 != 0 &&
                    !(lbl_801A6C80->bank[i].b1 & 0x80)) {
                    lbl_801A6C80->bank[i].b0 &= ~1;
                }
            }
}

static inline void fn_8006953C_loop2(u32 cmd) {
    u8 i;
    for (i = 0; i < 16; i++) {
        if ((s32)lbl_801A6C80->bank[i].b0 != 0 && (lbl_801A6C80->bank[i].b1 & 0x80) &&
            (cmd & 0xF) == lbl_801A6C80->bank[i].b2) {
            lbl_801A6C80->bank[i].b0 |= 6;
            lbl_801A6C80->bank[i].w24 = lbl_80092C38[(cmd >> 8) & 0x7F];
            lbl_801A6C80->bank[i].w24 = (lbl_801A6C80->bank[i].w24 ^ 0xFFFFFFFF) + 1;
        }
    }
}

void fn_8006953C(u32 cmd) {
    SndChan * fzgx_live;
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
                if ((cmd & 0xF) == lbl_801A6C80->bank[i.value].b2 && (s32)lbl_801A6C80->bank[i.value].b0 != 0 &&
                    !(lbl_801A6C80->bank[i.value].b1 & 0x80)) {
                    lbl_801A6C80->bank[i.value].b0 |= 1;
                }
            }
            break;
        case 0x30000:
            fn_8006953C_loop1(cmd);
            break;
        case 0x60000:
            break;
        case 0x90000:
            lbl_801A6C80->b458 = cmd & 0xF;
            lbl_801A6C80->w448 = lbl_80092C38[((0x7F) & ((cmd >> 8)))];
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
        d = fzgx_live[i.value].w8;
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
            if ((s32)lbl_801A6C80->bank[i.value].b0 != 0 && lbl_801A6C80->bank[i.value].b2 == found &&
                !(lbl_801A6C80->bank[i.value].b1 & 0x80)) {
                idx = i.value;
                break;
            }
        }
    } else if ((flags & 0x10) == 0x10) {
        for (i.value = 0; i.value < 16; i.value++) {
            if ((s32)lbl_801A6C80->bank[i.value].b0 != 0 && (lbl_801A6C80->bank[i.value].b1 & 0xF) == (flags & 0xF)) {
                idx = i.value;
                break;
            }
        }
    }
    if (idx == 0x7F) {
        for (i.value = 0; i.value < 16; i.value++) {
            if ((s32)lbl_801A6C80->bank[i.value].b0 == 0) {
                idx = i.value;
                break;
            }
        }
    }
    if (idx == 0x7F) {
        for (i.value = 0; i.value < 16; i.value++) {
            if (lbl_801A6C80->bank[i.value].b1 & 0x80) {
                idx = i.value;
                break;
            }
        }
    }

    lbl_801A6C80->bank[idx].b2 = found;
    lbl_801A6C80->bank[idx].w4 = 0x10000;
    lbl_801A6C80->bank[idx].w8 = cmd;
    lbl_801A6C80->bank[idx].wC = 0;
    lbl_801A6C80->bank[idx].b1 = rec_2[0];
    if (!(lbl_801A6C80->bank[idx].b1 & 0x80)) {
        lbl_801A6C80->bank[idx].b0 = 0x90;
        lbl_801A6C80->bank[idx].w10 = rec_2;
        lbl_801A6C80->bank[idx].w14 = (u32)(rec_2 + 4);
        lbl_801A6C80->bank[idx].w18 = lbl_801A6608;
        if (lbl_801A6C80->w448 == 0) {
            lbl_801A6C80->bank[idx].w1C = 0x7F0000;
            lbl_801A6C80->bank[idx].w20 = 0x7F0000;
        } else if (lbl_801A6C80->b458 == found) {
            lbl_801A6C80->bank[idx].w24 = lbl_801A6C80->w448;
            lbl_801A6C80->bank[idx].w1C = 0;
            lbl_801A6C80->bank[idx].w20 = 0;
            lbl_801A6C80->bank[idx].b0 ^= 0x98;
            lbl_801A6C80->w448 = 0;
        } else {
            lbl_801A6C80->bank[idx].w1C = 0x7F0000;
            lbl_801A6C80->bank[idx].w20 = 0x7F0000;
        }
    } else {
        lbl_801A6C80->bank[idx].b0 = 0x80;
        lbl_801A6C80->bank[idx].w14 = 0xFF000000;
        lbl_801A6C80->bank[idx].w18 = rec_2 + 1;
    }
    fn_80068EB4();
    } else if (lbl_801A6C80->cb1C != NULL) {
        lbl_801A6C80->cb1C(-3, cmd);
    }
}
