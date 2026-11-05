#include "types.h"
#pragma use_lmw_stmw on

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

/* key zone: velocity/key split point, base value and slope (8.8 fixed point per key) */
typedef struct SndZone {
    u8 key;
    u8 val;
    s16 slope;
} SndZone;

typedef struct SndPitchZone {
    u8 key;
    u8 pad_1;
    u16 val;
    s16 slope;
} SndPitchZone;

typedef struct SndZoneList {
    u8 count;
    u8 offset;
} SndZoneList;

typedef struct SndRegion {
    u8 size;
    u8 mode;
    u16 sample;
    u8 lo;
    u8 hi;
    u8 pad_6;
    u8 unk_7;
    u8 fader;
    u8 pad_9;
    u8 flags;
    u8 pad_B;
    SndZoneList zone[6]; /* volume, pan, surround pan, pitch, aux A, aux B */
} SndRegion;

typedef struct SndTrackVoice {
    u8 state;
    u8 flags;
    u8 voice;
    u8 voice2;
} SndTrackVoice;

typedef struct SndTrack {
    u8 bank;
    u8 pad_1[3];
    u8 pan;
    u8 span;
    u8 pad_6[3];
    u8 coarse;
    u8 fine;
    u8 pad_B[4];
    u8 prio;
    SndRegion *regions;
    SndTrackVoice voices[16];
} SndTrack;

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
    u32 base;
    SndBankData *bank;
    u8 pad_C[4];
} SndChan;

typedef struct SndVoice {
    u8 state;
    u8 active;
    u8 slot;
    u8 flags;
    u8 unk_4;
    u8 unk_5;
    u8 track;
    u8 index;
    u8 prio;
    u8 link0;
    u8 link1;
    u8 pad_B;
    s16 rnd;
    u16 unk_E;
    u32 unk_10;
    s32 vol;
    u32 time;
    u8 pad_1C[0x10];
    void *obj;
    u8 pad_30[0x118 - 0x30];
} SndVoice;

typedef struct SndState {
    SndChan chan[16];
    u8 pad_100[0x1A4 - 0x100];
    u32 unk_1A4;
    u32 unk_1A8;
    u8 pad_1AC[0x462 - 0x1AC];
    u8 unk_462;
    u8 pad_463[0x1408 - 0x463];
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

typedef struct SndSrc {
    u16 ratio_hi;
    u16 ratio_lo;
    u16 frac;
    u16 last[4];
} SndSrc;

extern SndState *lbl_801A6C80;
extern SndTrack lbl_80192D68[16];
extern const s16 lbl_80092B38[16];
extern const u8 lbl_80092B58[128];

extern s16 fn_80060950(SndRegion *, u8, u8, f32 *, s16 *);
extern void fn_80060724(SndRegion *, u8, u8, s32 *, s32 *, s32 *);
extern void fn_8005DB68(s16, f32, s16, s16 *, s16 *);
extern void fn_8005FCD8(u32);
extern s32 fn_8006496C(u32);
extern f64 fn_80088578(f64);
extern f64 fn_80088598(f64, f64);
extern void fn_80025EF4(void *, u32, s32, s32, s32, s16, s16, s32);
extern void fn_80023438(void *, SndSrc *);
extern void fn_800234D0(void *, f32);
extern void fn_80023568(void *, u16 *);
extern void fn_80023284(void *, SndVoiceParams *);
extern void fn_80023394(void *, SndAdpcm *);
extern void fn_800230A4(void *, s32);
extern void fn_80023168(void *, u16);
extern void fn_80026D90(void *, s32);
extern void fn_80026EE0(void *, s16);
extern void fn_80026F4C(void *, s16);
extern void fn_80026E2C(void *, s32);
extern void fn_80026EAC(void *, s32);

static inline SndWave *GetBankWave(u8 track, u16 sample) {
    SndBankData *bank = lbl_801A6C80->chan[lbl_80192D68[track].bank].bank;
    SndWave *w = (SndWave *)(bank->wave_offset + (u32)bank + 4);
    u32 i;

    for (i = 0; i < sample - 0x100; i++) {
        w++;
    }
    return w;
}

static inline s16 GetZoneLevel(SndRegion *region, s32 k, u8 key) {
    SndZoneList *list = region->zone;
    SndZone *z = (SndZone *)((u8 *)list + list[k].offset);
    u8 i;
    u8 low = region->lo;
    f64 t;

    for (i = 0; i < list[k].count; z++, i++) {
        if (key <= z->key) {
            break;
        }
        low = z->key + 1;
    }
    t = z->slope * (key - low) / 256.0;
    return z->val + t;
}

static inline s16 GetPan(s16 v, u8 offset) {
    v += offset - 64;

    if (v < 0) {
        v = 0;
    } else if (v > 127) {
        v = 127;
    }
    v = lbl_80092B58[v];
    return v;
}

static inline f64 GetZonePitch(SndRegion *region, u8 key) {
    SndZoneList *list = region->zone;
    SndPitchZone *z = (SndPitchZone *)((u8 *)list + list[3].offset);
    u8 i;
    u8 low = region->lo;
    f64 t;

    for (i = 0; i < list[3].count; z++, i++) {
        if (key <= z->key) {
            break;
        }
        low = z->key + 1;
    }
    t = z->slope * (key - low) / 256.0;
    return 3.125 * ((z->val - 0xC00) + t);
}

static inline f64 GetPitchRatio(SndRegion *region, u8 key, u8 track) {
    f64 cents = GetZonePitch(region, key);

    cents += 100.0 * (lbl_80192D68[track].coarse - 64) + 1.5625 * (lbl_80192D68[track].fine - 64);
    if (cents) {
        cents /= 1200.0;
    }
    return fn_80088598(2.0, cents);
}

void fn_80060C54(u8 key, SndRegion *region, u8 track, u8 index) {
    SndWave local_wave;
    SndAdpcm adpcm;
    SndVoiceParams params;
    SndSrc src;
    SndVoiceParams params2;
    SndSrc src2;
    u16 loop_ps[3];
    f32 db;
    s32 aux_a;
    s32 aux_b;
    s32 mode;
    s16 left;
    s16 right;
    s16 level;
    u16 span;
    u16 pan;
    SndWave *wave;
    u32 loop_end;
    u32 loop_start;
    u32 cur;
    u8 bps;
    s32 voice = -1;
    s16 vol;
    u32 ok = 1;
    u32 n;
    u8 state;
    u32 i;
    u32 base;
    u32 start;
    s16 fader;
    f64 ratio;
    u16 hi;
    u16 lo;
    s32 voice2;
    f32 fratio;
    f32 x;
    s32 j;
    s32 k;
    u16 *d;

    if (region->sample >= 0x100) {
        wave = GetBankWave(track, region->sample);
    } else {
        n = region->sample;
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

    state = lbl_80192D68[track].voices[index].state;
    if (state == 0 || (region->flags & 2) == 2) {
        if (!(region->flags & 2) || !(region->flags & 1) || state != 1) {
            voice = fn_8006496C(lbl_80192D68[track].prio);
        }
        if (voice < 0) {
            return;
        }
        vol = fn_80060950(region, key, track, &db, &level);
        if (wave->stereo == 1) {
            pan = 4;
            fn_8005DB68(GetPan(GetZoneLevel(region, 1, key), lbl_80192D68[track].pan), db, level, &left, &right);
            vol = left;
        } else {
            pan = GetPan(GetZoneLevel(region, 1, key), lbl_80192D68[track].pan);
        }
        if (lbl_801A6C80->unk_462 == 0) {
            if (wave->stereo == 1) {
                pan = 0x40;
                vol = 0.75f * (f32)(left + right) + (f32)vol;
            } else {
                x = (127 - (s16)pan) / 127;
                left = -20.0 * fn_80088578(sqrt(x));
                x = (s16)pan / 127;
                right = 20.0 * fn_80088578(sqrt(x));
                pan = 0x40;
                vol = 0.75f * (f32)(left + right) + (f32)vol;
            }
        }
        fader = lbl_80092B38[region->fader];
        fn_80060724(region, track, key, &mode, &aux_a, &aux_b);
        span = GetPan(GetZoneLevel(region, 2, key), lbl_80192D68[track].span);

        lbl_80192D68[track].voices[index].voice = voice;
        lbl_80192D68[track].voices[index].flags = region->flags;
        lbl_801A6C80->voice[voice].time = 0;
        lbl_801A6C80->voice[voice].state = 3;
        lbl_801A6C80->voice[voice].flags = 0;
        lbl_801A6C80->voice[voice].unk_4 = 0;
        lbl_801A6C80->voice[voice].prio = 30;
        lbl_801A6C80->voice[voice].unk_5 = 0;
        lbl_801A6C80->voice[voice].unk_E = region->unk_7;
        lbl_801A6C80->voice[voice].unk_10 = 0;
        lbl_801A6C80->voice[voice].track = track;
        lbl_801A6C80->voice[voice].index = index;
        fn_80025EF4(lbl_801A6C80->voice[voice].obj, mode, vol, aux_a, aux_b, pan, span, fader);

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

        if (region->sample >= 0x100) {
            base = wave->offset + lbl_801A6C80->chan[lbl_80192D68[track].bank].base;
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

        ratio = GetPitchRatio(region, key, track);
        hi = __fabs(ratio);
        lo = (ratio - hi) * fn_80088598(2.0, 16.0);
        if (hi >= 4 && lo != 0) {
            hi = 4;
            lo = 0;
        }
        src.ratio_hi = hi;
        src.ratio_lo = lo;
        src.frac = 0;
        src.last[0] = 0;
        src.last[1] = 0;
        src.last[2] = 0;
        src.last[3] = 0;
        fn_80023438(lbl_801A6C80->voice[voice].obj, &src);
        fn_80023284(lbl_801A6C80->voice[voice].obj, &params);
        fn_80023394(lbl_801A6C80->voice[voice].obj, &adpcm);
        fn_800230A4(lbl_801A6C80->voice[voice].obj, 1);

        if (wave->stereo == 1) {
            voice2 = fn_8006496C(lbl_80192D68[track].prio);
            if (voice2 != -1) {
                lbl_80192D68[track].voices[index].voice2 = voice2;
                lbl_80192D68[track].voices[index].flags = region->flags;
                lbl_801A6C80->voice[voice2].time = 0;
                lbl_801A6C80->voice[voice2].state = 3;
                lbl_801A6C80->voice[voice2].flags = 0;
                lbl_801A6C80->voice[voice2].unk_4 = 0;
                lbl_801A6C80->voice[voice2].prio = 30;
                lbl_801A6C80->voice[voice2].unk_5 = 0;
                lbl_801A6C80->voice[voice2].unk_E = region->unk_7;
                lbl_801A6C80->voice[voice2].unk_10 = 0;
                lbl_801A6C80->voice[voice2].track = track;
                lbl_801A6C80->voice[voice2].index = index;
                if (lbl_801A6C80->unk_462 != 0) {
                    vol = right;
                    pan = 0x7C;
                }
                fn_80025EF4(lbl_801A6C80->voice[voice2].obj, mode, vol, aux_a, aux_b, pan, span, fader);
                if ((wave->format & 3) == 0) {
                    params2.format = 10;
                } else if ((wave->format & 3) == 1) {
                    params2.format = 25;
                } else {
                    params2.format = 0;
                }
                start = wave->offset + lbl_801A6C80->chan[lbl_80192D68[track].bank].base + wave->offset2;
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
                src2.ratio_hi = hi;
                src2.ratio_lo = lo;
                src2.frac = 0;
                src2.last[0] = 0;
                src2.last[1] = 0;
                src2.last[2] = 0;
                src2.last[3] = 0;
                fn_80023284(lbl_801A6C80->voice[voice2].obj, &params2);
                fn_80023394(lbl_801A6C80->voice[voice2].obj, &adpcm);
                fn_800230A4(lbl_801A6C80->voice[voice2].obj, 1);
                fn_80023438(lbl_801A6C80->voice[voice2].obj, &src2);
                fn_80023168(lbl_801A6C80->voice[voice2].obj, 1);
                lbl_801A6C80->voice[voice2].active = 1;
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
            lbl_80192D68[track].voices[index].state = 1;
        } else {
            fn_8005FCD8((u8)voice);
        }
    } else {
        voice = lbl_80192D68[track].voices[index].voice;
        fratio = GetPitchRatio(region, key, track);
        if (fratio > 4.0f) {
            fratio = 4.0f;
        }
        fn_800234D0(lbl_801A6C80->voice[voice].obj, fratio);
        vol = fn_80060950(region, key, track, &db, &level);
        span = GetPan(GetZoneLevel(region, 2, key), lbl_80192D68[track].span);
        fn_80060724(region, track, key, &mode, &aux_a, &aux_b);
        fn_80026E2C(lbl_801A6C80->voice[voice].obj, aux_a);
        fn_80026EAC(lbl_801A6C80->voice[voice].obj, aux_b);
        if (lbl_80192D68[track].voices[index].voice2 == 0xFF) {
            fn_80026D90(lbl_801A6C80->voice[voice].obj, vol);
            pan = GetPan(GetZoneLevel(region, 1, key), lbl_80192D68[track].pan);
            fn_80026EE0(lbl_801A6C80->voice[voice].obj, pan);
            fn_80026F4C(lbl_801A6C80->voice[voice].obj, span);
        } else {
            fn_8005DB68(GetPan(GetZoneLevel(region, 1, key), lbl_80192D68[track].pan), db, level, &left, &right);
            fn_80026D90(lbl_801A6C80->voice[voice].obj, left);
            fn_80026F4C(lbl_801A6C80->voice[voice].obj, span);
            voice2 = lbl_80192D68[track].voices[index].voice2;
            fn_800234D0(lbl_801A6C80->voice[voice2].obj, fratio);
            fn_80026D90(lbl_801A6C80->voice[voice2].obj, right);
            fn_80026F4C(lbl_801A6C80->voice[voice2].obj, span);
            fn_80026E2C(lbl_801A6C80->voice[voice2].obj, aux_a);
            fn_80026EAC(lbl_801A6C80->voice[voice2].obj, aux_b);
        }
    }
}
