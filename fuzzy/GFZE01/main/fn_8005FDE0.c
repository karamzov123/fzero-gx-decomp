/* Non-matching: best partial attempt (96.75% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
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
    u8 b3;
    u8 b4;
    u8 pad5[0x1B];
} SndSlot;

typedef struct {
    SndChan chan[16];       /* 0x0000 */
    u8 pad100[0x444 - 0x100];
    u32 command;            /* 0x0444 */
    u8 pad448[0x45E - 0x448];
    u8 b45E;
    u8 pad45F[2];
    u8 b461;
    u8 b462;
    u8 b463;
    u8 pad464[0x474 - 0x464];
    u8 b474;
    u8 pad475[0x488 - 0x475];
    SndMix mix[16];         /* 0x0488 */
    SndSlot slot[64];       /* 0x0588 */
    u8 pair[16][16][4];     /* 0x0D88 */
    u8 pad1188[0x5A10 - 0x1188];
    s16 h5A10;
    s16 h5A12;
    u8 pad5A14[0x5B18 - 0x5A14];
    void (*cb18)(u8, u32);
    void (*cb1C)(s32, u32);
} SndState;

extern SndState *lbl_801A6C80;
extern u8 lbl_80092AB8[];

extern void fn_80064A30(u16, u32);
extern void fn_800643F4(u16);
extern void fn_8005CBF4(u32);
extern void fn_800622B0(void);
extern u32 fn_80021928(void);
extern void fn_80021914(u32);
extern u32 fn_80025EEC(void);
extern void fn_80025EE4(u32);
extern void fn_8006953C(u32);
extern void fn_800647B8(u16);
extern void fn_80069AE0(void);
extern void fn_80064230(u16, u16);
extern void fn_800641A8(u16);
extern void fn_80065528(u32);
extern void fn_80065390(void);
extern void fn_8006331C(u8, u32);
extern void fn_80062654(void);
extern void fn_80064E84(u8, u8);

static inline void note_on(void) {
    u8 *base;
    u32 cmd;
    u16 *cursor;
    SndState *g;
    u8 j;
    u8 *data;
    s32 v;
    u8 ch;
    u8 k;

    g = lbl_801A6C80;
    cmd = g->command;
    data = g->chan[cmd & 0xF].w8;
    ch = cmd & 0xF;
    v = g->pair[cmd & 0xF][(cmd >> 24) & 0xF][0];
    if (v == 0xFF) {
        return;
    }
    if (g->slot[(u8)v].b1 & 2) {
        return;
    }
    base = data + *(u32 *)(data + 0x1C);
    cursor = (u16 *)base;
    for (j = 0; j <= g->slot[(u8)v].b4; j++) {
        cursor++;
    }
    if ((*(u16 *)(base + *cursor) >> 8) < ((cmd >> 16) & 0x7F)) {
        return;
    }
    fn_800643F4(0xC000);
    for (k = 0; k < 4; k++) {
        if ((s32)lbl_801A6C80->pair[cmd & 0xF][(cmd >> 24) & 0xF][k] != 0xFF) {
            fn_80064E84(ch, lbl_801A6C80->pair[cmd & 0xF][(cmd >> 24) & 0xF][k]);
        }
    }
}

void fn_8005FDE0(u32 cmd) {
    u32 status = cmd >> 24;
    u32 mask;
    u8 a;
    u8 b;
    u8 ch;
    u8 i;
    u8 v;

    lbl_801A6C80->command = cmd;
    mask = cmd & 0xFF700000;
    a = (cmd >> 16) & 0x7F;
    b = (cmd >> 8) & 0xFF;
    ch = cmd & 0xF;
    if (status < 0x80) {
        return;
    }
    switch (status & 0xF0) {
    case 0x80:
        fn_80064A30(0x8000, 0x0F7F00FF);
        break;
    case 0x90:
        if (b != 0) {
            fn_800643F4(0x9000);
        } else {
            fn_80064A30(0x8000, 0x0F7F00FF);
        }
        break;
    case 0xA0:
        switch (status & 0xF) {
        case 0:
            switch (a) {
            case 0:
                switch (b) {
                case 1:
                    fn_8005CBF4(0xA0000100);
                    fn_800622B0();
                    break;
                case 2:
                    fn_8005CBF4(0xA0000200);
                    break;
                case 3:
                    fn_8005CBF4(0xA0000300);
                    break;
                case 4:
                    fn_800622B0();
                    break;
                case 8:
                    lbl_801A6C80->b462 = 1;
                    lbl_801A6C80->b463 = 1;
                    if (fn_80021928() != 0) {
                        fn_80021914(0);
                    }
                    if (fn_80025EEC() != 1) {
                        fn_80025EE4(1);
                    }
                    break;
                case 9:
                    lbl_801A6C80->b462 = 0;
                    lbl_801A6C80->b463 = 0;
                    if (fn_80021928() != 0) {
                        fn_80021914(0);
                    }
                    if (fn_80025EEC() != 1) {
                        fn_80025EE4(1);
                    }
                    break;
                case 0x11:
                    fn_8005CBF4(0xA0001100);
                    break;
                case 0x12:
                    fn_8005CBF4(0xA0001200);
                    break;
                case 0x13:
                    fn_8005CBF4(0xA0001300);
                    break;
                case 0x18:
                case 0x19:
                    if (!(cmd & 0x40)) {
                        fn_8006953C(cmd);
                    }
                    break;
                case 0x28:
                    lbl_801A6C80->b462 = 1;
                    lbl_801A6C80->b463 = 2;
                    if (fn_80021928() != 1) {
                        fn_80021914(1);
                    }
                    if (fn_80025EEC() != 2) {
                        fn_80025EE4(2);
                    }
                    break;
                case 0x29:
                    lbl_801A6C80->b462 = 1;
                    lbl_801A6C80->b463 = 3;
                    if (fn_80021928() != 2) {
                        fn_80021914(2);
                    }
                    if (fn_80025EEC() != 3) {
                        fn_80025EE4(3);
                    }
                    break;
                }
                break;
            case 1:
                lbl_801A6C80->b461 = b;
                fn_80064A30(0xA001, 0);
                break;
            case 2:
                fn_800647B8(0xA002);
                if (!(cmd & 0x40)) {
                    fn_8006953C(cmd);
                }
                break;
            case 3:
                fn_80069AE0();
                break;
            case 4:
            case 5:
            case 0x10:
            case 0x11:
                cmd = a + 0xA000;
                fn_80064230(cmd, 0xA004);
                fn_800641A8(0xA004);
                fn_800647B8(cmd);
                break;
            case 7:
                fn_800641A8(0xA007);
                fn_800647B8(0xA007);
                break;
            case 9:
                fn_80069AE0();
                break;
            case 10:
                fn_80069AE0();
                break;
            case 0x19:
                fn_80065528(0);
                break;
            case 0x1C:
                lbl_801A6C80->mix[ch].b9 = lbl_80092AB8[b];
                fn_80064A30(0xA01C, 0xF);
                break;
            case 0x24:
                if (lbl_801A6C80->cb18 != NULL) {
                    lbl_801A6C80->cb18(ch, b);
                }
                break;
            case 0x28:
            case 0x29:
                for (i = 0; i < 4; i++) {
                    v = lbl_801A6C80->pair[ch][(u8)b][i];
                    if (v != 0xFF) {
                        lbl_801A6C80->slot[v].b2 = 0x29 - a;
                    }
                }
                break;
            case 0x30:
                lbl_801A6C80->b45E = b;
                break;
            case 0x31:
                lbl_801A6C80->h5A10 = lbl_801A6C80->h5A12;
                fn_80064A30(0xA001, 0);
                break;
            case 0x34:
                fn_80064230(0xA034, 0xA034);
                fn_800647B8(0xA034);
                break;
            case 0x37:
                fn_80065390();
                break;
            case 0x38:
                fn_80065528(1);
                break;
            case 0x40:
                fn_80064230(0xA040, 0xA034);
                fn_800647B8(0xA040);
                break;
            }
            break;
        case 4:
            switch (mask) {
            case 0xA4000000:
                fn_8006331C(lbl_801A6C80->b474, b);
                break;
            case 0xA4700000:
                lbl_801A6C80->b474 = b;
                break;
            }
            break;
        case 5:
        case 6:
        case 7:
            fn_80062654();
            break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            fn_80069AE0();
            break;
        }
        break;
    case 0xB0:
        switch (a) {
        case 0:
            fn_800643F4(0xB000);
            break;
        case 1:
        case 2:
            cmd = a + 0xB000;
            fn_800643F4(cmd);
            fn_80064A30(cmd, 0x0F00000F);
            break;
        case 7:
            fn_800643F4(0xB007);
            fn_80064A30(0xB007, 0x0F00000F);
            break;
        case 10:
            fn_800643F4(0xB00A);
            fn_80064A30(0xB00A, 0x0F00000F);
            break;
        case 13:
            fn_800643F4(0xB00D);
            fn_80064A30(0xB00D, 0x0F00000F);
            break;
        case 14:
            fn_800643F4(0xB00E);
            fn_80064A30(0xB00D, 0x0F00000F);
            break;
        case 0x27:
            fn_800643F4(0xB007);
            break;
        case 0x2A:
            fn_800643F4(0xB00A);
            break;
        case 0x2B:
            break;
        case 0xB:
            break;
        case 0x2D:
            fn_800643F4(0xB00D);
            break;
        case 0x2E:
            fn_800643F4(0xB00E);
            break;
        case 0x40:
            fn_800643F4(0xB040);
            fn_80064A30(0xB040, 0x0F00000F);
            break;
        case 0x41:
            break;
        case 0x78:
            fn_80064A30(0xB078, 0xF);
            break;
        }
        break;
    case 0xC0:
        note_on();
        break;
    case 0xE0:
        fn_800643F4(0xE000);
        fn_80064A30(0xE000, 0x0F00000F);
        break;
    }
}
