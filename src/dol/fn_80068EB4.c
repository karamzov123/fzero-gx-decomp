#include "types.h"

/* One sequencer track (0x28 bytes); 16 of them live at +0x1188. */
typedef struct {
    u8 flags;       /* 0x00 */
    u8 flags2;      /* 0x01 */
    u8 chan;        /* 0x02 */
    u8 status;      /* 0x03 running status */
    u8 pad4[8];
    s32 wait;       /* 0x0C delta time, 16.16 */
    u8 *base;       /* 0x10 */
    u32 loop;       /* 0x14 return address, or SEQ_NO_LOOP */
    u8 *cur;        /* 0x18 */
    s32 vol;        /* 0x1C */
    s32 prevVol;    /* 0x20 */
    s32 volStep;    /* 0x24 */
} SeqTrack;

typedef struct {
    u8 pad[0x1188];
    SeqTrack tracks[16];
} SeqState;

extern SeqState *lbl_801A6C80;
extern void fn_80065A7C(u32);

/* Sentinel stored in SeqTrack.loop: no return address pending. */
#define SEQ_NO_LOOP 0xFF000000u

#pragma opt_lifetimes off
void fn_80068EB4(void) {
    u8 i;
    u8 *q;
    u8 *p;
    s32 flags;
    struct { u32 value; } msg;
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
        flags = ((i)[lbl_801A6C80->tracks]).flags;
        if (flags == 0) {
            continue;
        }
        if (flags & 2) {
            ((i)[lbl_801A6C80->tracks]).vol += ((i)[lbl_801A6C80->tracks]).volStep;
            if (((i)[lbl_801A6C80->tracks]).vol < 0) {
                ((i)[lbl_801A6C80->tracks]).vol = 0;
            } else if (((i)[lbl_801A6C80->tracks]).vol > 0x7F0000) {
                ((i)[lbl_801A6C80->tracks]).vol = 0x7F0000;
            }
        }
        if (((i)[lbl_801A6C80->tracks]).flags & 2) {
            ((i)[lbl_801A6C80->tracks]).vol &= 0x7F0000;
            if (((i)[lbl_801A6C80->tracks]).vol != ((i)[lbl_801A6C80->tracks]).prevVol) {
                ((i)[lbl_801A6C80->tracks]).prevVol = ((i)[lbl_801A6C80->tracks]).vol;
                fn_80065A7C((((i)[lbl_801A6C80->tracks]).vol << 8) | 0xA01C0000 | ((i)[lbl_801A6C80->tracks]).chan);
                if (((i)[lbl_801A6C80->tracks]).vol == 0) {
                    fn_80065A7C(((i)[lbl_801A6C80->tracks]).chan | 0xA0000000 | 0x1200);
                    ((i)[lbl_801A6C80->tracks]).flags = 0;
                } else if (((i)[lbl_801A6C80->tracks]).vol == 0x7F0000) {
                    ((i)[lbl_801A6C80->tracks]).flags &= 0xF9;
                }
            }
        }
        if ((((i)[lbl_801A6C80->tracks]).wait >> 16) > 0) {
            continue;
        }
        p = ((i)[lbl_801A6C80->tracks]).cur;
    top:
        /* labels: the event parser restarts from two nested loops */
        q = p;
        c = *p;
        if (c == 0xFF) {
            p = (u8 *)((i)[lbl_801A6C80->tracks]).loop;
            if ((u32)p == SEQ_NO_LOOP) {
                ((i)[lbl_801A6C80->tracks]).flags = 0;
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
                    p = ((i)[lbl_801A6C80->tracks]).base + arg;
                    if (cmd != 0x90) {
                        if (arg == 0) {
                            ((i)[lbl_801A6C80->tracks]).flags = 0;
                            goto next; /* leave both loops */
                        }
                        ((i)[lbl_801A6C80->tracks]).loop = SEQ_NO_LOOP;
                        goto top; /* resume parsing at p */
                    }
                } else {
                    fn_80065A7C((arg << 8) | ((i)[lbl_801A6C80->tracks]).chan | 0x80);
                    if (((i)[lbl_801A6C80->tracks]).flags & 0x18) {
                        msg.value = 0xA01C0000;
                        if (((i)[lbl_801A6C80->tracks]).flags & 8) {
                            ((i)[lbl_801A6C80->tracks]).flags &= 0xF5;
                        } else {
                            ((i)[lbl_801A6C80->tracks]).flags &= 0xEF;
                            msg.value |= 0x7F00;
                        }
                        msg.value |= ((i)[lbl_801A6C80->tracks]).chan;
                        fn_80065A7C(msg.value);
                    }
                }
            }
            /* command 0: call, the return address goes to loop */
            ((i)[lbl_801A6C80->tracks]).loop = (u32)p;
            p = ((i)[lbl_801A6C80->tracks]).base + arg;
            goto top; /* resume parsing at p */
        }
        if (c & 0x80) {
            ((i)[lbl_801A6C80->tracks]).status = *q;
            s = *q++;
        } else {
            s = ((i)[lbl_801A6C80->tracks]).status;
        }
        b = *q++;
        lo = b & 0x7F;
        msg.value = (s << 24) | (lo << 16);
        more = b & 0x80;
        switch (s & 0xF0) {
        case 0x90:
        case 0xA0:
        case 0xB0:
        case 0xF0:
            b = *q++;
            msg.value |= (b & 0x7F) << 8;
            more = b & 0x80;
            break;
        case 0xE0:
            msg.value = (msg.value & 0xFF00FFFF) | (lo << 8);
            break;
        case 0xD0:
            if (((i)[lbl_801A6C80->tracks]).flags2 & 0x80) {
                b1 = ((1)[q]);
                b0 = ((0)[q]);
                q += 2;
                msg.value &= 0xBFFFFFFF;
                msg.value |= ((b0 & 0x7F) << 8) | ((b1 & 0x7F) << 4);
                more = b1 & 0x80;
            }
            break;
        }
        msg.value |= ((i)[lbl_801A6C80->tracks]).chan;
        fn_80065A7C(msg.value);
        if (more & 0x80) {
            p = q;
            goto top; /* another event follows without a delta time */
        }
        msg.value = *q++;
        if (msg.value & 0x80) {
            msg.value = (msg.value & 0x7F) << 7;
            msg.value = (msg.value | (*q++ & 0x7F)) & 0x3FFF;
        }
        ((i)[lbl_801A6C80->tracks]).wait += msg.value << 16;
        ((i)[lbl_801A6C80->tracks]).cur = q;
    next:;
    }
}
#pragma opt_lifetimes reset

