/* Non-matching: best partial attempt (98.86% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct SndBank {
    u8 pad_0[0x1C];
    u32 prog_offset;
    u8 pad_20[8];
    u32 drum_offset;
} SndBank;

typedef struct SndPort {
    SndBank *bank;
    u8 pad_4[0xC];
} SndPort;

typedef struct SndVoice {
    u8 pad_0;
    u8 flags;
    u8 pad_2[2];
    u8 program;
    u8 bank_sel;
    u8 pad_6;
    u8 cc_07;
    u8 cc_0A;
    u8 pad_9[2];
    u8 cc_0D;
    u8 cc_0E;
    u8 pad_D[4];
    u8 pitch;
    u8 cc_40;
    u8 cc_01;
    u8 cc_02;
    u8 pad_15[7];
    u16 *data;
} SndVoice;

typedef struct Snd {
    u8 pad_0[8];
    SndPort ports[(0x444 - 8) / 0x10];
    u8 pad_448[0x444 - 8 - ((0x444 - 8) / 0x10) * 0x10];
    u32 msg;
    u8 pad_448b[0x13];
    u8 channel;
    u8 pad_45C[0x588 - 0x45C];
    SndVoice voices[64];
    u8 map[16][16][4];
} Snd;

extern Snd *lbl_801A6C80;
extern void fn_8005DCEC(u16 *, u8);

/* Applies the current channel message to every voice mapped to its channel. */
static inline u16 * fn_800643F4_loop1(u8 *base, SndVoice *voice) {
    u32 j;
    u16 *table;
                    table = (u16 *)base;
                    for (j = 0; j <= voice->program; j++) {
                        table++;
                    }
    return table;
}

static inline u8 * fn_800643F4_address_2940(s32 offset, u8 * base) {
    return ((offset) + (base));
}
void fn_800643F4(u16 status) {
    u32 i;
    u32 msg;
    u8 channel;
    u8 data1;
    u8 data2;
    u32 port;
    u32 slot;
    u8 v;
    u16 *table;
    u8 *base;
    u32 j;
    u16 * lab_t0;

    msg = lbl_801A6C80->msg;
    channel = msg & 0xF;
    data1 = (msg >> 16) & 0x7F;
    data2 = (msg >> 8) & 0x7F;
    for (i = 0; i < 4; i++) {
        v = lbl_801A6C80->map[msg & 0xF][(msg >> 24) & 0xF][i];
        if ((s32)v == 0xFF) {
            continue;
        }
        lbl_801A6C80->channel = channel;
        switch (status) {
        case 0x9000:
            if (((*((v) + (lbl_801A6C80->voices))).flags & 0x80) && lbl_801A6C80->voices[v].data != 0) {
                lab_t0 = lbl_801A6C80->voices[v].data + 4;
                fn_8005DCEC(lab_t0, v);
                lab_t0 = lbl_801A6C80->voices[v].data + 5;
                fn_8005DCEC(lab_t0, v);
                lab_t0 = lbl_801A6C80->voices[v].data + 6;
                fn_8005DCEC(lab_t0, v);
                lab_t0 = lbl_801A6C80->voices[v].data + 7;
                fn_8005DCEC(lab_t0, v);
            }
            break;
        case 0xB000:
            lbl_801A6C80->voices[v].program = data2;
            {
                SndVoice *voice = (SndVoice *)((u8 *)lbl_801A6C80->voices + (s32)v * 32);
                SndBank *bank = lbl_801A6C80->ports[msg & 0xF].bank;
                if (voice->flags & 2) {
                    if (bank->drum_offset != 0) {
                        voice->data = (u16 *)((u8 *)bank + bank->drum_offset);
                    } else {
                        voice->data = 0;
                    }
                } else {
                    base = (u8 *)bank + bank->prog_offset;
                    table = fn_800643F4_loop1(base, voice);
                    base = fn_800643F4_address_2940(*table, base);
                    table = (u16 *)base;
                    for (j = 0; j <= voice->bank_sel; j++) {
                        table++;
                    }
                    if (*table != 0) {
                        voice->data = (u16 *)(*table + base);
                    } else {
                        voice->data = 0;
                    }
                }
            }
            break;
        case 0xB001:
            lbl_801A6C80->voices[v].cc_01 = data2;
            break;
        case 0xB002:
            lbl_801A6C80->voices[v].cc_02 = data2;
            break;
        case 0xB007:
            lbl_801A6C80->voices[v].cc_07 = data2;
            break;
        case 0xB00A:
            lbl_801A6C80->voices[v].cc_0A = data2;
            break;
        case 0xB00D:
            lbl_801A6C80->voices[v].cc_0D = data2;
            break;
        case 0xB00E:
            lbl_801A6C80->voices[v].cc_0E = data2;
            break;
        case 0xB040:
            if (data2 >= 0x40) {
                lbl_801A6C80->voices[v].cc_40 = data2;
            } else {
                lbl_801A6C80->voices[v].cc_40 = 0;
            }
            break;
        case 0xC000:
            lbl_801A6C80->voices[v].bank_sel = data1;
            break;
        case 0xE000:
            (*((lbl_801A6C80->voices) + (v))).pitch = data2;
            break;
        }
    }
}

