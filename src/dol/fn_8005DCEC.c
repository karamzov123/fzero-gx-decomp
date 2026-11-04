#include "types.h"

/* MSL __float_nan / __float_huge */
extern unsigned long lbl_801A6648[];
extern unsigned long lbl_801A664C[];

#define NAN (*(float *)lbl_801A6648)
#define INFINITY (*(float *)lbl_801A664C)

extern f64 __frsqrte(f64);
extern f64 __fabs(f64);

static inline double sqrt(double x) {
    if (x > 0.0) {
        double guess = __frsqrte(x);
        guess = .5 * guess * (3.0 - guess * guess * x);
        guess = .5 * guess * (3.0 - guess * guess * x);
        guess = .5 * guess * (3.0 - guess * guess * x);
        guess = .5 * guess * (3.0 - guess * guess * x);
        return x * guess;
    } else if (x == 0) {
        return 0;
    } else if (x) {
        return NAN;
    }
    return INFINITY;
}

typedef struct SndNote {
    u8 key;
    u8 flags;
    u16 sample;
    u8 pad_4[2];
    u8 pan;
    u8 unk_7;
    u8 unk_8;
    u8 pad_9;
    s8 unk_A;
    s8 unk_B;
    s16 unk_C;
    u8 pad_E[6];
    u8 unk_14;
    u8 unk_15;
    u8 unk_16;
    u8 unk_17;
    u8 unk_18;
    u8 pad_19[2];
    u8 unk_1B;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
    f32 unk_20;
    f32 unk_24;
    u16 unk_28;
    u16 unk_2A;
    u8 pad_2C[4];
} SndNote;

typedef struct SndHeader {
    u16 count;
    u8 lo;
    u8 hi;
    u8 pad_4[9];
    s8 unk_D;
    u8 pad_E;
    s8 unk_F;
    u8 pad_10[9];
    u8 unk_19;
    u8 unk_1A;
    u8 pad_1B[5];
    u8 min;
    u8 max;
    u16 offs[1];
} SndHeader;

typedef struct SndWave {
    u32 offset;
    u32 loop_start;
    u32 loop_end;
    u16 coef[16];
    u16 gain;
    u16 ps;
    u16 yn1;
    u16 yn2;
    u16 loop_ps;
    u16 loop_yn1;
    u16 loop_yn2;
    u8 format;
    u8 stereo;
    u16 rate;
    u8 pad_3E[2];
    u32 offset2;
} SndWave;

typedef struct SndBankData {
    u8 pad_0[4];
    u8 pad_4[0x34];
    u32 wave_offset;
} SndBankData;

typedef struct SndChan {
    u8 pad_0[4];
    u32 unk_4;
    SndBankData *unk_8;
    u8 pad_C[4];
} SndChan;

typedef struct SndSlot {
    u8 pad_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3[3];
    u8 unk_6;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
    u8 unk_C;
    u8 pad_D;
    s8 unk_E;
    s8 unk_F;
    u8 unk_10;
    u8 pad_11;
    u8 unk_12;
    u8 unk_13;
    u8 pad_14[8];
    u8 *seq;
} SndSlot;

typedef struct SndVoice {
    u8 state;
    u8 active;
    u8 slot;
    u8 flags;
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[2];
    u8 prio;
    u8 link0;
    u8 link1;
    u8 pad_B;
    s16 rnd;
    u16 unk_E;
    u32 unk_10;
    s32 vol;
    u32 time;
    SndNote *note;
    SndHeader *hdr;
    u8 pad_24[8];
    void *obj;
    u8 env[0x40];
    u8 unk_70[8];
    s32 unk_78;
    u8 unk_7C[8];
    s32 unk_84;
    u8 unk_88[8];
    u8 unk_90;
    u8 unk_91;
    u8 pad_92[2];
    u8 unk_94[8];
    s32 unk_9C;
    u8 unk_A0[8];
    s32 unk_A8;
    u8 unk_AC[8];
    s32 unk_B4;
    s32 unk_B8;
    s32 unk_BC;
    u8 unk_C0[8];
    u8 unk_C8[0x20];
    s32 unk_E8;
    u8 unk_EC[8];
    u8 unk_F4[0x20];
    s32 unk_114;
} SndVoice;

typedef struct SndState {
    SndChan chan[16];
    u8 pad_100[0x1A4 - 0x100];
    u32 unk_1A4;
    u32 unk_1A8;
    u8 pad_1AC[0x444 - 0x1AC];
    u32 unk_444;
    u8 pad_448[0x45B - 0x448];
    u8 unk_45B;
    u8 pad_45C[0x461 - 0x45C];
    u8 unk_461;
    u8 unk_462;
    u8 pad_463[0x46C - 0x463];
    u32 unk_46C;
    u8 pad_470[0x588 - 0x470];
    SndSlot slot[64];
    u8 pad_D88[0x1408 - 0xD88];
    SndVoice voice[64];
} SndState;

typedef struct SndVoiceParams {
    u16 loop;
    u16 format;
    u16 loop_hi;
    u16 loop_lo;
    u16 end_hi;
    u16 end_lo;
    u16 cur_hi;
    u16 cur_lo;
} SndVoiceParams;

typedef struct SndAdpcm {
    u16 coef[16];
    u16 gain;
    u16 ps;
    u16 yn1;
    u16 yn2;
} SndAdpcm;

typedef struct SndTables {
    s16 unk_0[16];
    u8 unk_20[32];
    u8 unk_40[32];
    u8 unk_60[32];
} SndTables;

extern SndState *lbl_801A6C80;
static const u32 fzgx_pool_rodata_lbl_800929D8[8] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFC7CFE5C, 0xFE7AFE98, 0xFEB6FED4, 0xFEF2FF10, 0xFF2EFF4C, 0xFF6AFF88, 0xFFA6FFC4, 0xFFE20000
};
static const u32 fzgx_pool_rodata_lbl_800929F8[8] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xEFDFCFBF, 0xAF9F8F7F, 0x6F5F4F3F, 0x2F1F0F00
};
static const u32 fzgx_pool_rodata_lbl_80092A18[8] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xF1F2F3F, 0x4F5F6F7F, 0x8F9FAFBF, 0xCFDFEFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFF00
};
static const u32 fzgx_pool_rodata_lbl_800929D8_60[32] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0, 0x1010101, 0x1020202, 0x2030304, 0x4050506, 0x7070809,
    0xA0B0C0D, 0xE0F1011, 0x13141517, 0x181A1C1D, 0x1F212325, 0x27292B2E, 0x30323436, 0x383A3C3E,
    0x40424446, 0x484A4C4E, 0x50525457, 0x595B5D5E, 0x60626465, 0x67686A6B, 0x6C6E6F70, 0x71727374,
    0x75767777, 0x7879797A, 0x7B7B7C7C, 0x7C7D7D7D, 0x7E7E7E7E, 0x7E7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_800929D8(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_800929D8;
    s = *(u8 *)fzgx_pool_rodata_lbl_800929F8;
    s = *(u8 *)fzgx_pool_rodata_lbl_80092A18;
    s = *(u8 *)fzgx_pool_rodata_lbl_800929D8_60;
}
#pragma section code_type ".text"

#define PITCH_TABLE ((s16 *)fzgx_pool_rodata_lbl_800929D8)
#define PAN_TABLE ((u8 *)fzgx_pool_rodata_lbl_800929D8_60)
extern u32 lbl_801299D0[];
extern u32 lbl_80129AD0[];
extern u32 lbl_80129BD0[];
extern u32 lbl_80129CD0[];
extern u32 lbl_80129DD0[];
extern u32 lbl_80129ED0[];

extern s32 fn_8005D5A4(SndNote *);
extern u32 fn_80082908(void);
extern s32 fn_80063EF4(u8, u8, u8);
extern s32 fn_8006496C(u8);
extern void fn_80028130(void *, void *, u32);
extern s16 fn_8005D258(SndHeader *, SndNote *, u8, u8, f32 *, s16 *);
extern f64 fn_80088578(f64);
extern void fn_80023568(void *, u16 *);
extern void fn_80023284(void *, SndVoiceParams *);
extern void fn_80023394(void *, SndAdpcm *);
extern void fn_800230A4(void *, s32);
extern void fn_800284CC(void *);
extern void fn_800284E8(void *);
extern void fn_80028540(void *);
extern void fn_80028554(void *);
extern void fn_80028568(void *);
extern void fn_8002857C(void *);
extern void fn_800284FC(void *);
extern void fn_80028598(void *);
extern void fn_800284A0(void *, u32 *, u32, f32);
extern void fn_800288B4(void *, void *);
extern void fn_80028164(void *);
extern void fn_80026E04(void *);
extern void fn_80026DD4(void *);
extern void fn_80026E84(void *);
extern void fn_80026E54(void *);
extern void fn_80026FB8(void *, s16);
extern void fn_80023168(void *, u16);
extern void fn_80020CB0(void *, u32);
extern void fn_80026D70(void *);
extern void fn_80020ABC(void *);
extern void fn_80060BDC(u32);
extern void fn_80028424(void *);

static inline void fn_8005DB68(s16 arg0, f32 arg1, s16 arg2, s16 *arg3, s16 *arg4) {
    u32 idx = ((s32)arg0 / 4 - 1) & 0xFF;
    f32 a;
    f32 b;

    a = arg1 + (f32)(20.0 * fn_80088578((f32)((u8 *)fzgx_pool_rodata_lbl_800929F8)[idx] / 255.0f));
    b = arg1 + (f32)(20.0 * fn_80088578((f32)((u8 *)fzgx_pool_rodata_lbl_80092A18)[idx] / 255.0f));

    *arg3 = (f32)arg2 + 10.0f * a;
    *arg4 = (f32)arg2 + 10.0f * b;

    if (*arg3 < -960) {
        *arg3 = -960;
    }
    if (*arg4 < -960) {
        *arg4 = -960;
    }
}

static inline void fn_8005FCD8(u32 arg0) {
    if (lbl_801A6C80->voice[arg0].state != 0xFF) {
        fn_80023168(lbl_801A6C80->voice[arg0].obj, 0);
        fn_80026D70(lbl_801A6C80->voice[arg0].obj);
        fn_80020ABC(lbl_801A6C80->voice[arg0].obj);
        lbl_801A6C80->voice[arg0].obj = NULL;
        if (lbl_801A6C80->voice[arg0].state == 3) {
            fn_80060BDC(arg0);
        } else {
            fn_80028424(lbl_801A6C80->voice[arg0].env);
        }
        lbl_801A6C80->voice[arg0].state = 0xFF;
        lbl_801A6C80->voice[arg0].time = 0;
        lbl_801A6C80->voice[arg0].active = 0;
        if (lbl_801A6C80->voice[arg0].link0 == arg0) {
            lbl_801A6C80->voice[arg0].link0 = 0xFF;
        } else {
            if (lbl_801A6C80->voice[arg0].link1 == arg0) {
                lbl_801A6C80->voice[arg0].link1 = 0xFF;
            }
        }
    }
}

static inline s32 fn_scale(s32 x, s32 range, u8 slot) {
    s32 v = x * range;
    v >>= 7;
    v *= lbl_801A6C80->slot[slot].unk_13;
    return v >> 7;
}

static inline SndWave *GetBankWave(u16 sample) {
    SndBankData *bank = lbl_801A6C80->chan[lbl_801A6C80->unk_45B].unk_8;
    SndWave *w = (SndWave *)(bank->wave_offset + (u32)bank + 4);
    u32 i;

    for (i = 0; i < sample - 0x100; i++) {
        w++;
    }
    return w;
}

void fn_8005DCEC(u16 *arg0, u8 arg1) {
    SndWave local_wave;
    SndAdpcm adpcm;
    SndVoiceParams params;
    SndVoiceParams params2;
    u16 loop_ps[3];
    s32 env2;
    u8 bps;
    SndWave *wave;
    SndNote *note = NULL;
    f32 db;
    s16 level;
    u32 pan2;
    s16 bend;
    u32 ok = 1;
    s32 rev;
    s32 voice = -1;
    s32 pitch;
    s32 vol;
    u8 pan;
    s32 fine;
    s32 cho;
    u8 prio;
    s32 mode;
    u8 enable;
    s32 coarse;
    u8 range;
    s32 detune;
    s32 cents;
    u8 vflags;
    u8 *seq;
    u32 n;
    u32 i;
    s32 j;
    s32 k;
    u16 *d;
    u8 p;
    u8 vel;
    s16 left;
    s16 right;
    u32 fx;
    u32 loop_end;
    u32 base;
    u32 loop_start;
    u32 start;
    u32 cur;
    s16 rnd;
    s32 env;
    s8 t;
    s32 voice2;
    u32 key;
    SndHeader *hdr;

    if (*arg0 == 0) {
        return;
    }
    seq = lbl_801A6C80->slot[arg1].seq;
    if (seq == NULL) {
        return;
    }
    mode = seq[0];
    hdr = (SndHeader *)(seq + *arg0);
    vel = (lbl_801A6C80->unk_444 >> 8) & 0xFF;
    key = (lbl_801A6C80->unk_444 >> 16) & 0xFF;
    if (mode == 0) {
        if (vel >= hdr->lo && vel <= hdr->hi) {
            note = (SndNote *)&hdr->min;
            for (i = 0; i < hdr->count; i++) {
                if (note->key >= key) {
                    break;
                }
                note++;
            }
        }
    } else if ((u32)mode == 1) {
        if ((s32)key <= hdr->max) {
            s32 d = key - hdr->min;
            if (d >= 0) {
                s32 o = hdr->offs[d];
                if (o != 0) {
                    note = (SndNote *)((u8 *)hdr + o);
                }
            }
        }
    } else {
        n = (((lbl_801A6C80->unk_444 >> 4) & 0xF) << 7) | key;
        if ((s32)n <= (s32)hdr->count) {
            note = &((SndNote *)&hdr->min)[n];
        }
    }
    if (note != NULL && mode != 0) {
        if (vel >= hdr->lo) {
            if (vel <= hdr->hi) {
                if (fn_8005D5A4(note) != 0) {
                    note = NULL;
                }
            } else {
                note = NULL;
            }
        } else {
            note = NULL;
        }
    }
    if (note == NULL) {
        return;
    }

    enable = 1;
    if (lbl_801A6C80->slot[arg1].unk_2 != 0) {
        if (lbl_801A6C80->unk_461 == 0) {
            enable = 0;
        }
        if (lbl_801A6C80->slot[arg1].unk_10 == 0) {
            enable = 0;
        }
        if (lbl_801A6C80->slot[arg1].unk_7 == 0) {
            enable = 0;
        }
    }
    if (enable == 0) {
        return;
    }
    if (note->sample == 0) {
        return;
    }
    if (lbl_801A6C80->slot[arg1].unk_1 & 1) {
        if (note->unk_1D == 10) {
            prio = 11;
        } else {
            prio = note->unk_1D + 11;
        }
    } else {
        prio = note->unk_1D + 11;
    }

    coarse = seq[0] != 0 ? 0 : key - 60;
    coarse += note->unk_A + lbl_801A6C80->slot[arg1].unk_E;
    fine = note->unk_B + lbl_801A6C80->slot[arg1].unk_F;
    range = note->unk_14;
    if (range != 0) {
        rnd = (s32)fn_80082908() % (range * 2) - range;
        fine += rnd;
    } else {
        rnd = 0;
    }
    detune = fn_80063EF4(arg1, hdr->unk_19, hdr->unk_1A);
    fine += (detune >> 2) & 0x3F;
    coarse += detune >> 8;
    cents = 100.0 * coarse + 1.5625 * fine;
    pitch = cents << 16;
    if (pitch > 2400 << 16) {
        lbl_801A6C80->unk_46C = lbl_801A6C80->unk_444;
    } else {
        voice = fn_8006496C(prio);
    }
    if (voice == -1) {
        return;
    }

    if (lbl_801A6C80->slot[arg1].unk_1 & 1) {
        lbl_801A6C80->voice[voice].state = 2;
    } else {
        lbl_801A6C80->voice[voice].state = 1;
    }
    lbl_801A6C80->voice[voice].time = lbl_801A6C80->unk_444;
    lbl_801A6C80->voice[voice].slot = arg1;
    lbl_801A6C80->voice[voice].note = note;
    lbl_801A6C80->voice[voice].hdr = hdr;
    lbl_801A6C80->voice[voice].rnd = rnd;
    vflags = 0x80;
    if (lbl_801A6C80->slot[arg1].unk_1 & 1) {
        vflags |= 0x40;
    }
    if (note->flags & 0x80) {
        vflags |= 8;
    }
    lbl_801A6C80->voice[voice].flags = vflags;
    if (lbl_801A6C80->slot[arg1].unk_12 != 0) {
        lbl_801A6C80->voice[voice].flags |= 1;
    }
    lbl_801A6C80->voice[voice].unk_4 = note->unk_1C;
    if (lbl_801A6C80->slot[arg1].unk_1 & 1) {
        if (note->unk_1D == 10) {
            lbl_801A6C80->voice[voice].prio = 0x8B;
        } else {
            lbl_801A6C80->voice[voice].prio = prio;
        }
    } else {
        lbl_801A6C80->voice[voice].prio = prio;
    }
    lbl_801A6C80->voice[voice].unk_5 = note->unk_1B & 0xCF;
    lbl_801A6C80->voice[voice].unk_E = 0;

    if (note->sample >= 0x100) {
        wave = GetBankWave(note->sample);
    } else {
        n = note->sample;
        local_wave.rate = 44100;
        local_wave.stereo = 0;
        local_wave.format = 4;
        local_wave.loop_start = 0;
        if (n <= 42) {
            local_wave.offset2 = 200;
            local_wave.loop_end = 99;
            local_wave.offset = (n - 1) * 200;
        } else if (n <= 84) {
            local_wave.offset2 = 400;
            local_wave.loop_end = 199;
            local_wave.offset = (n - 43) * 200;
        } else {
            local_wave.offset2 = 100;
            local_wave.loop_end = 49;
            local_wave.offset = (n - 85) * 100;
        }
        wave = &local_wave;
    }

    fn_80028130(lbl_801A6C80->voice[voice].env, lbl_801A6C80->voice[voice].obj, 32000);
    vol = fn_8005D258(hdr, note, arg1, vel, &db, &level);
    if (wave->stereo == 1) {
        p = note->pan;
        pan = 4;
        if (p & 0x80) {
            p = lbl_801A6C80->slot[arg1].unk_8;
        }
        fn_8005DB68(PAN_TABLE[p], db, level, &left, &right);
        vol = left;
    } else {
        p = note->pan;
        if (p & 0x80) {
            p = lbl_801A6C80->slot[arg1].unk_8;
        }
        pan = PAN_TABLE[p];
    }
    if (lbl_801A6C80->unk_462 == 0) {
        if (wave->stereo == 1) {
            pan = 0x40;
            vol = (s16)(0.75f * (f32)(left + right) + (f32)vol);
        } else {
            left = -20.0 * fn_80088578(sqrt((f32)((127 - pan) / 127)));
            right = 20.0 * fn_80088578(sqrt((f32)(pan / 127)));
            pan = 0x40;
            vol = (s16)(0.75f * (f32)(left + right) + (f32)vol);
        }
    }

    if (note->unk_8 & 0x80) {
        bend = PITCH_TABLE[lbl_801A6C80->slot[arg1].unk_6];
    } else {
        bend = PITCH_TABLE[note->unk_8];
    }

    p = seq[0];
    if (note->unk_15 != 0 || p == 0) {
        fx = lbl_801A6C80->slot[arg1].unk_A;
        if (lbl_801A6C80->slot[arg1].unk_B != 0) {
            rev = 10.0 * (20.0 * fn_80088578((f32)lbl_801A6C80->slot[arg1].unk_B / 127.0f));
        } else {
            rev = -904;
        }
        if (lbl_801A6C80->slot[arg1].unk_C != 0) {
            cho = 10.0 * (20.0 * fn_80088578((f32)lbl_801A6C80->slot[arg1].unk_C / 127.0f));
        } else {
            cho = -904;
        }
    } else {
        fx = note->unk_16;
        if (note->unk_17 != 0) {
            rev = 10.0 * (20.0 * fn_80088578((f32)note->unk_17 / 127.0f));
        } else {
            rev = -904;
        }
        if (note->unk_18 != 0) {
            cho = 10.0 * (20.0 * fn_80088578((f32)note->unk_18 / 127.0f));
        } else {
            cho = -904;
        }
    }

    p = note->unk_7;
    if (p & 0x80) {
        p = lbl_801A6C80->slot[arg1].unk_9;
    }
    pan2 = PAN_TABLE[p];
    if ((wave->format & 3) == 0) {
        params.format = 10;
        bps = 2;
        adpcm.gain = 0x800;
        for (i = 0; i < 16; i++) {
            adpcm.coef[i] = 0;
        }
        adpcm.ps = 0;
        adpcm.yn1 = 0;
        adpcm.yn2 = 0;
    } else if ((wave->format & 3) == 1) {
        params.format = 25;
        bps = 1;
        adpcm.gain = 0x100;
        for (i = 0; i < 16; i++) {
            adpcm.coef[i] = 0;
        }
        adpcm.ps = 0;
        adpcm.yn1 = 0;
        adpcm.yn2 = 0;
    } else {
        params.format = 0;
        bps = 4;
        adpcm.gain = wave->gain;
        d = adpcm.coef;
        for (j = 0; j < 8; j++) {
            for (k = 0; k < 2; k++) {
                *d++ = wave->coef[j * 2 + k];
            }
        }
        adpcm.ps = wave->ps;
        adpcm.yn1 = wave->yn1;
        adpcm.yn2 = wave->yn2;
    }

    if (note->sample >= 0x100) {
        base = wave->offset + lbl_801A6C80->chan[lbl_801A6C80->unk_45B].unk_4;
    } else {
        base = lbl_801A6C80->unk_1A8 + wave->offset;
    }
    if (bps != 4) {
        start = base / bps;
        cur = start;
    } else {
        start = base * 2;
        cur = start + 2;
    }
    if (wave->format & 4) {
        params.loop = 1;
        if (bps != 4) {
            loop_start = start + wave->loop_start;
            loop_end = start + wave->loop_end;
            loop_ps[0] = 0;
            loop_ps[1] = 0;
            loop_ps[2] = 0;
        } else {
            loop_start = start + wave->loop_start;
            loop_end = start + wave->loop_end;
            loop_ps[0] = wave->loop_ps;
            loop_ps[1] = wave->loop_yn1;
            loop_ps[2] = wave->loop_yn2;
        }
        fn_80023568(lbl_801A6C80->voice[voice].obj, loop_ps);
    } else {
        params.loop = 0;
        if (bps != 4) {
            loop_start = lbl_801A6C80->unk_1A4 / bps;
            loop_end = start + wave->loop_end;
        } else {
            loop_start = lbl_801A6C80->unk_1A4 * 2 + 2;
            loop_end = start + wave->loop_end;
        }
    }
    params.loop_hi = loop_start >> 16;
    params.loop_lo = loop_start;
    params.end_hi = loop_end >> 16;
    params.end_lo = loop_end;
    params.cur_hi = cur >> 16;
    params.cur_lo = cur;
    fn_80023284(lbl_801A6C80->voice[voice].obj, &params);
    fn_80023394(lbl_801A6C80->voice[voice].obj, &adpcm);
    fn_800230A4(lbl_801A6C80->voice[voice].obj, 1);
    fn_800284CC(lbl_801A6C80->voice[voice].unk_88);
    fn_800284E8(lbl_801A6C80->voice[voice].unk_70);
    fn_80028540(lbl_801A6C80->voice[voice].unk_7C);
    fn_80028554(lbl_801A6C80->voice[voice].unk_94);
    fn_80028568(lbl_801A6C80->voice[voice].unk_A0);
    fn_8002857C(lbl_801A6C80->voice[voice].unk_AC);
    fn_800284FC(lbl_801A6C80->voice[voice].unk_C0);
    fn_80028598(lbl_801A6C80->voice[voice].unk_EC);
    if (note->unk_1E == 0) {
        fn_800284A0(lbl_801A6C80->voice[voice].unk_C8, lbl_801299D0, 0x40, note->unk_20);
    } else if (note->unk_1E == 1) {
        fn_800284A0(lbl_801A6C80->voice[voice].unk_C8, lbl_80129AD0, 0x40, note->unk_20);
    } else if (note->unk_1E == 2) {
        fn_800284A0(lbl_801A6C80->voice[voice].unk_C8, lbl_80129BD0, 0x40, note->unk_20);
    } else if (note->unk_1E == 3) {
        fn_800284A0(lbl_801A6C80->voice[voice].unk_C8, lbl_80129CD0, 0x40, note->unk_20);
    } else if (note->unk_1E == 4) {
        fn_800284A0(lbl_801A6C80->voice[voice].unk_C8, lbl_80129DD0, 0x40, note->unk_20);
    } else if (note->unk_1E == 5) {
        fn_800284A0(lbl_801A6C80->voice[voice].unk_C8, lbl_80129ED0, 0x40, note->unk_20);
    }
    if (note->unk_1F == 0) {
        fn_800284A0(lbl_801A6C80->voice[voice].unk_F4, lbl_801299D0, 0x40, note->unk_24);
    } else if (note->unk_1F == 1) {
        fn_800284A0(lbl_801A6C80->voice[voice].unk_F4, lbl_80129AD0, 0x40, note->unk_24);
    } else if (note->unk_1F == 2) {
        fn_800284A0(lbl_801A6C80->voice[voice].unk_F4, lbl_80129BD0, 0x40, note->unk_24);
    } else if (note->unk_1F == 3) {
        fn_800284A0(lbl_801A6C80->voice[voice].unk_F4, lbl_80129CD0, 0x40, note->unk_24);
    } else if (note->unk_1F == 4) {
        fn_800284A0(lbl_801A6C80->voice[voice].unk_F4, lbl_80129DD0, 0x40, note->unk_24);
    } else if (note->unk_1F == 5) {
        fn_800284A0(lbl_801A6C80->voice[voice].unk_F4, lbl_80129ED0, 0x40, note->unk_24);
    }
    t = hdr->unk_D;
    if (t > 0) {
        env = t + 1;
        env *= 1200;
        env >>= 7;
        env *= lbl_801A6C80->slot[arg1].unk_13;
        env >>= 7;
        env += note->unk_28;
        if (env > 1200) {
            env = 1200;
        }
    } else if (t < 0) {
        env = note->unk_28 - fn_scale((s32)__fabs(t), 1200, arg1);
        if (env < 0) {
            env = 0;
        }
    } else {
        env = note->unk_28;
    }
    env <<= 16;
    lbl_801A6C80->voice[voice].unk_E8 = env;
    t = hdr->unk_F;
    if (t > 0) {
        env2 = note->unk_2A + fn_scale(t + 1, 120, arg1);
        if (env2 > 120) {
            env2 = 120;
        }
    } else if (t < 0) {
        env2 = note->unk_2A - fn_scale((s32)__fabs(t), 120, arg1);
        if (env2 < 0) {
            env2 = 0;
        }
    } else {
        env2 = note->unk_2A;
    }
    lbl_801A6C80->voice[voice].unk_114 = env2 << 16;
    lbl_801A6C80->voice[voice].vol = vol;
    lbl_801A6C80->voice[voice].unk_84 = (vol - env2) << 16;
    lbl_801A6C80->voice[voice].unk_90 = pan;
    lbl_801A6C80->voice[voice].unk_91 = pan2;
    lbl_801A6C80->voice[voice].unk_78 = pitch;
    lbl_801A6C80->voice[voice].unk_9C = rev;
    lbl_801A6C80->voice[voice].unk_A8 = cho;
    if (note->unk_C != 0) {
        lbl_801A6C80->voice[voice].unk_B4 = note->unk_C << 16;
        lbl_801A6C80->voice[voice].unk_B8 = 0;
        lbl_801A6C80->voice[voice].unk_BC = -960 << 16;
    } else {
        lbl_801A6C80->voice[voice].unk_B4 = 0;
        lbl_801A6C80->voice[voice].unk_B8 = 0;
        lbl_801A6C80->voice[voice].unk_BC = 0;
    }
    fn_800288B4(lbl_801A6C80->voice[voice].env, lbl_801A6C80->voice[voice].unk_70);
    fn_800288B4(lbl_801A6C80->voice[voice].env, lbl_801A6C80->voice[voice].unk_7C);
    fn_800288B4(lbl_801A6C80->voice[voice].env, lbl_801A6C80->voice[voice].unk_94);
    fn_800288B4(lbl_801A6C80->voice[voice].env, lbl_801A6C80->voice[voice].unk_A0);
    fn_800288B4(lbl_801A6C80->voice[voice].env, lbl_801A6C80->voice[voice].unk_AC);
    fn_800288B4(lbl_801A6C80->voice[voice].env, lbl_801A6C80->voice[voice].unk_88);
    fn_800288B4(lbl_801A6C80->voice[voice].env, lbl_801A6C80->voice[voice].unk_C0);
    fn_800288B4(lbl_801A6C80->voice[voice].env, lbl_801A6C80->voice[voice].unk_EC);
    fn_80028164(lbl_801A6C80->voice[voice].env);
    if (fx & 1) {
        fn_80026E04(lbl_801A6C80->voice[voice].obj);
    } else {
        fn_80026DD4(lbl_801A6C80->voice[voice].obj);
    }
    if (fx & 2) {
        fn_80026E84(lbl_801A6C80->voice[voice].obj);
    } else {
        fn_80026E54(lbl_801A6C80->voice[voice].obj);
    }
    fn_80026FB8(lbl_801A6C80->voice[voice].obj, (s32)bend);

    if (wave->stereo == 1) {
        voice2 = fn_8006496C(prio);
        if (voice2 != -1) {
            lbl_801A6C80->voice[voice2].state = lbl_801A6C80->voice[voice].state;
            lbl_801A6C80->voice[voice2].time = lbl_801A6C80->voice[voice].time;
            lbl_801A6C80->voice[voice2].slot = lbl_801A6C80->voice[voice].slot;
            lbl_801A6C80->voice[voice2].note = lbl_801A6C80->voice[voice].note;
            lbl_801A6C80->voice[voice2].hdr = lbl_801A6C80->voice[voice].hdr;
            lbl_801A6C80->voice[voice2].flags = lbl_801A6C80->voice[voice].flags;
            lbl_801A6C80->voice[voice2].unk_4 = lbl_801A6C80->voice[voice].unk_4;
            lbl_801A6C80->voice[voice2].prio = lbl_801A6C80->voice[voice].prio;
            lbl_801A6C80->voice[voice2].unk_5 = lbl_801A6C80->voice[voice].unk_5;
            lbl_801A6C80->voice[voice2].unk_E = lbl_801A6C80->voice[voice].unk_E;
            lbl_801A6C80->voice[voice2].unk_10 = lbl_801A6C80->voice[voice].unk_10;
            if (lbl_801A6C80->unk_462 != 0) {
                vol = right;
                pan = 0x7C;
            }
            fn_80028130(lbl_801A6C80->voice[voice2].env, lbl_801A6C80->voice[voice2].obj, 32000);
            if ((wave->format & 3) == 0) {
                params2.format = 10;
            } else if ((wave->format & 3) == 1) {
                params2.format = 25;
            } else {
                params2.format = 0;
            }
            start = wave->offset + lbl_801A6C80->chan[lbl_801A6C80->unk_45B].unk_4 + wave->offset2;
            if (bps != 4) {
                start /= bps;
            } else {
                start *= 2;
            }
            if (wave->format & 4) {
                params2.loop = 1;
                if (bps != 4) {
                    loop_start = start + wave->loop_start;
                    loop_end = start + wave->loop_end;
                } else {
                    loop_start = start + wave->loop_start;
                    loop_end = start + wave->loop_end;
                }
                fn_80023568(lbl_801A6C80->voice[voice2].obj, loop_ps);
            } else {
                params2.loop = 0;
                if (bps != 4) {
                    loop_start = lbl_801A6C80->unk_1A4 / bps;
                    loop_end = start + wave->loop_end;
                } else {
                    loop_start = lbl_801A6C80->unk_1A4 * 2;
                    loop_end = start + wave->loop_end;
                }
            }
            params2.loop_hi = loop_start >> 16;
            params2.loop_lo = loop_start;
            params2.end_hi = loop_end >> 16;
            params2.end_lo = loop_end;
            params2.cur_hi = start >> 16;
            params2.cur_lo = start;
            fn_800284CC(lbl_801A6C80->voice[voice2].unk_88);
            fn_800284E8(lbl_801A6C80->voice[voice2].unk_70);
            fn_80028540(lbl_801A6C80->voice[voice2].unk_7C);
            fn_80028554(lbl_801A6C80->voice[voice2].unk_94);
            fn_80028568(lbl_801A6C80->voice[voice2].unk_A0);
            fn_8002857C(lbl_801A6C80->voice[voice2].unk_AC);
            fn_800284FC(lbl_801A6C80->voice[voice2].unk_C0);
            fn_80028598(lbl_801A6C80->voice[voice2].unk_EC);
            if (note->unk_1E == 0) {
                fn_800284A0(lbl_801A6C80->voice[voice2].unk_C8, lbl_801299D0, 0x40, note->unk_20);
            } else if (note->unk_1E == 1) {
                fn_800284A0(lbl_801A6C80->voice[voice2].unk_C8, lbl_80129AD0, 0x40, note->unk_20);
            } else if (note->unk_1E == 2) {
                fn_800284A0(lbl_801A6C80->voice[voice2].unk_C8, lbl_80129BD0, 0x40, note->unk_20);
            } else if (note->unk_1E == 3) {
                fn_800284A0(lbl_801A6C80->voice[voice2].unk_C8, lbl_80129CD0, 0x40, note->unk_20);
            } else if (note->unk_1E == 4) {
                fn_800284A0(lbl_801A6C80->voice[voice2].unk_C8, lbl_80129DD0, 0x40, note->unk_20);
            } else if (note->unk_1E == 5) {
                fn_800284A0(lbl_801A6C80->voice[voice2].unk_C8, lbl_80129ED0, 0x40, note->unk_20);
            }
            if (note->unk_1F == 0) {
                fn_800284A0(lbl_801A6C80->voice[voice2].unk_F4, lbl_801299D0, 0x40, note->unk_24);
            } else if (note->unk_1F == 1) {
                fn_800284A0(lbl_801A6C80->voice[voice2].unk_F4, lbl_80129AD0, 0x40, note->unk_24);
            } else if (note->unk_1F == 2) {
                fn_800284A0(lbl_801A6C80->voice[voice2].unk_F4, lbl_80129BD0, 0x40, note->unk_24);
            } else if (note->unk_1F == 3) {
                fn_800284A0(lbl_801A6C80->voice[voice2].unk_F4, lbl_80129CD0, 0x40, note->unk_24);
            } else if (note->unk_1F == 4) {
                fn_800284A0(lbl_801A6C80->voice[voice2].unk_F4, lbl_80129DD0, 0x40, note->unk_24);
            } else if (note->unk_1F == 5) {
                fn_800284A0(lbl_801A6C80->voice[voice2].unk_F4, lbl_80129ED0, 0x40, note->unk_24);
            }
            lbl_801A6C80->voice[voice2].unk_E8 = env;
            lbl_801A6C80->voice[voice2].unk_114 = env2 << 16;
            lbl_801A6C80->voice[voice2].vol = vol;
            lbl_801A6C80->voice[voice2].unk_84 = (vol - env2) << 16;
            lbl_801A6C80->voice[voice2].unk_84 = vol << 16;
            lbl_801A6C80->voice[voice2].unk_90 = pan;
            lbl_801A6C80->voice[voice2].unk_91 = pan2;
            lbl_801A6C80->voice[voice2].unk_78 = pitch;
            lbl_801A6C80->voice[voice2].unk_9C = rev;
            lbl_801A6C80->voice[voice2].unk_A8 = cho;
            if (note->unk_C != 0) {
                lbl_801A6C80->voice[voice2].unk_B4 = note->unk_C << 16;
                lbl_801A6C80->voice[voice2].unk_B8 = 0;
                lbl_801A6C80->voice[voice2].unk_BC = -960 << 16;
            } else {
                lbl_801A6C80->voice[voice2].unk_B4 = 0;
                lbl_801A6C80->voice[voice2].unk_B8 = 0;
                lbl_801A6C80->voice[voice2].unk_BC = 0;
            }
            fn_800288B4(lbl_801A6C80->voice[voice2].env, lbl_801A6C80->voice[voice2].unk_70);
            fn_800288B4(lbl_801A6C80->voice[voice2].env, lbl_801A6C80->voice[voice2].unk_7C);
            fn_800288B4(lbl_801A6C80->voice[voice2].env, lbl_801A6C80->voice[voice2].unk_94);
            fn_800288B4(lbl_801A6C80->voice[voice2].env, lbl_801A6C80->voice[voice2].unk_A0);
            fn_800288B4(lbl_801A6C80->voice[voice2].env, lbl_801A6C80->voice[voice2].unk_AC);
            fn_800288B4(lbl_801A6C80->voice[voice2].env, lbl_801A6C80->voice[voice2].unk_88);
            fn_800288B4(lbl_801A6C80->voice[voice2].env, lbl_801A6C80->voice[voice2].unk_C0);
            fn_800288B4(lbl_801A6C80->voice[voice2].env, lbl_801A6C80->voice[voice2].unk_EC);
            fn_80028164(lbl_801A6C80->voice[voice2].env);
            if (fx & 1) {
                fn_80026E04(lbl_801A6C80->voice[voice2].obj);
            } else {
                fn_80026DD4(lbl_801A6C80->voice[voice2].obj);
            }
            if (fx & 2) {
                fn_80026E84(lbl_801A6C80->voice[voice2].obj);
            } else {
                fn_80026E54(lbl_801A6C80->voice[voice2].obj);
            }
            fn_80026FB8(lbl_801A6C80->voice[voice2].obj, (s32)bend);
            fn_80023284(lbl_801A6C80->voice[voice2].obj, &params2);
            fn_80023394(lbl_801A6C80->voice[voice2].obj, &adpcm);
            fn_800230A4(lbl_801A6C80->voice[voice2].obj, 1);
            fn_80023168(lbl_801A6C80->voice[voice2].obj, 1);
            lbl_801A6C80->voice[voice2].active = 1;
            if (lbl_801A6C80->voice[voice2].prio >= 2 && !(lbl_801A6C80->voice[voice2].prio & 0x80)) {
                lbl_801A6C80->voice[voice2].prio--;
                fn_80020CB0(lbl_801A6C80->voice[voice2].obj, lbl_801A6C80->voice[voice2].prio);
            }
            lbl_801A6C80->voice[voice].link0 = voice;
            lbl_801A6C80->voice[voice].link1 = voice2;
            lbl_801A6C80->voice[voice2].link0 = voice;
            lbl_801A6C80->voice[voice2].link1 = voice2;
        } else {
            ok = 0;
        }
    }

    if (ok) {
        fn_80023168(lbl_801A6C80->voice[voice].obj, 1);
        lbl_801A6C80->voice[voice].active = 1;
        if (lbl_801A6C80->voice[voice].prio >= 2 && !(lbl_801A6C80->voice[voice].prio & 0x80)) {
            lbl_801A6C80->voice[voice].prio--;
            fn_80020CB0(lbl_801A6C80->voice[voice].obj, lbl_801A6C80->voice[voice].prio);
        }
    } else {
        fn_8005FCD8((u8)voice);
    }
}
