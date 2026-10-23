/* Non-matching: best partial attempt (96.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma use_lmw_stmw on

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
    s8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 bB;
    u8 bC;
    u8 bD;
    u8 bE;
    u8 bF;
    u8 b10;
    u8 b11;
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
    u8 b18;
    u8 b19;
    u8 b1A;
    u8 b1B;
    u8 *w1C;
} SndSlot;

typedef struct {
    SndChan chan[16];       /* 0x0000 */
    u8 pad100[0x444 - 0x100];
    u32 command;            /* 0x0444 */
    u8 pad448[0x45B - 0x448];
    u8 b45B;
    u8 pad45C[0x588 - 0x45C];
    SndSlot slot[64];       /* 0x0588 */
    u8 pair[16][16][4];     /* 0x0D88 */
} SndState;

extern SndState *lbl_801A6C80;
extern void fn_8005DCEC(u8 *, u8);

#pragma opt_lifetimes off
static inline u8 * fn_800643F4_address_2450(s32 offset, u8 * base) {
    return base + offset;
}
void fn_800643F4(u16 kind_arg) {
    u8 * lab_t0;
#define lo ((cmd >> 8) & 0x7F)
#define hi ((cmd >> 16) & 0x7F)
    u8 ch;
    u32 i;
    s32 v;
    u32 cmd;
    u8 *data;
    u8 *base;
    u16 *cursor;
    u32 j;


    cmd = lbl_801A6C80->command;
    ch = cmd & 0xF;
    for (i = 0; i < 4; i++) {
        v = lbl_801A6C80->pair[cmd & 0xF][((0xF) & ((cmd >> 24)))][i];
        if (v == 0xFF) {
            continue;
        }
        lbl_801A6C80->b45B = ch;
        switch (((u16)(kind_arg))) {
        case 0x9000:
            if (!(lbl_801A6C80->slot[(u8)v].b1 & 0x80)) {
                break;
            }
            if (lbl_801A6C80->slot[(u8)v].w1C == NULL) {
                break;
            }
            lab_t0 = lbl_801A6C80->slot[(u8)v].w1C + 8;
            fn_8005DCEC(lab_t0, v);
            lab_t0 = lbl_801A6C80->slot[(u8)v].w1C + 0xA;
            fn_8005DCEC(lab_t0, v);
            lab_t0 = lbl_801A6C80->slot[(u8)v].w1C + 0xC;
            fn_8005DCEC(lab_t0, v);
            lab_t0 = lbl_801A6C80->slot[(u8)v].w1C + 0xE;
            fn_8005DCEC(lab_t0, v);
            break;
        case 0xB000:
            lbl_801A6C80->slot[(u8)v].b4 = lo;
            data = lbl_801A6C80->chan[cmd & 0xF].w8;
            if (lbl_801A6C80->slot[(u8)v].b1 & 2) {
                if (*(u32 *)(data + 0x28) != 0) {
                    lbl_801A6C80->slot[(u8)v].w1C = data + *(u32 *)(data + 0x28);
                } else {
                    lbl_801A6C80->slot[(u8)v].w1C = NULL;
                }
            } else {
                base = fn_800643F4_address_2450(*(u32 *)(data + 0x1C), data);
                cursor = (u16 *)base;
                for (j = 0; j <= lbl_801A6C80->slot[(u8)v].b4; j++) {
                    cursor++;
                }
                base += *cursor;
                cursor = (u16 *)base;
                for (j = 0; j <= lbl_801A6C80->slot[(u8)v].b5; j++) {
                    cursor++;
                }
                if (*cursor != 0) {
                    lbl_801A6C80->slot[(u8)v].w1C = *cursor + base;
                } else {
                    lbl_801A6C80->slot[(u8)v].w1C = NULL;
                }
            }
            break;
        case 0xB001:
            lbl_801A6C80->slot[(u8)v].b13 = lo;
            break;
        case 0xB002:
            lbl_801A6C80->slot[(u8)v].b14 = lo;
            break;
        case 0xB007:
            (*((lbl_801A6C80->slot) + ((u8)v))).b7 = lo;
            break;
        case 0xB00A:
            lbl_801A6C80->slot[(u8)v].b8 = lo;
            break;
        case 0xB00D:
            lbl_801A6C80->slot[(u8)v].bB = lo;
            break;
        case 0xB00E:
            lbl_801A6C80->slot[(u8)v].bC = lo;
            break;
        case 0xB040:
            if (lo >= 0x40) {
                lbl_801A6C80->slot[(u8)v].b12 = lo;
            } else {
                lbl_801A6C80->slot[(u8)v].b12 = 0;
            }
            break;
        case 0xC000:
            lbl_801A6C80->slot[(u8)v].b5 = hi;
            break;
        case 0xE000:
            lbl_801A6C80->slot[(u8)v].b11 = lo;
            break;
        }
    }
}
#pragma opt_lifetimes reset

