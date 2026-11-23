#include "sasnd/sasnd.h"
#pragma use_lmw_stmw on

extern f64 fn_80088578(f64 x);
extern f64 fn_80088598(f64, f64);
extern void fn_8005FBDC(u8 value);
void fn_80060C54(u8 key, SndRegion *region, u8 track, u8 index);
void fn_80062360(u32 slot, u32 sel);
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

typedef struct SndPitchZone {
    u8 key;
    u8 pad_1;
    u16 val;
    s16 slope;
} SndPitchZone;

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

extern const s16 lbl_80092B38[16];
extern const u8 lbl_80092B58[128];

extern void fn_8005DB68(s16, f32, s16, s16 *, s16 *);
extern void fn_8005FCD8(u32);
extern s32 fn_8006496C(u32);
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


void fn_8006060C(u32 arg0) {
    SndTrack *entries = lbl_80192D68;
    u32 i;
    u32 key;
    struct { volatile u8 *value; } cursor; /* Preserve observable record reads. */
    struct { u32 value; } counter;
    key = arg0;
    for (i = 0; i < 16; i++) {
        if (key == entries[i].bank) {
            if (entries[i].active) {
                cursor.value = (u8 *)entries[i].regions;
                for (counter.value = 0; (u8)counter.value <= entries[i].count; counter.value++) {
                    if (lbl_80192D68[(u8)i].voices[(u8)counter.value][SND_STEP_STATE] == 1) {
                        if (lbl_80192D68[(u8)i].voices[(u8)counter.value][SND_STEP_VOICE] != 0xff) {
                            fn_8005FBDC(lbl_80192D68[(u8)i].voices[(u8)counter.value][SND_STEP_VOICE]);
                        }
                        if (lbl_80192D68[(u8)i].voices[(u8)counter.value][SND_STEP_VOICE2] != 0xff) {
                            fn_8005FBDC(lbl_80192D68[(u8)i].voices[(u8)counter.value][SND_STEP_VOICE2]);
                        }
                        lbl_80192D68[(u8)i].voices[(u8)counter.value][SND_STEP_STATE] = 0;
                    }
                    cursor.value += *cursor.value;
                }
                entries[i].program = 0;
            } else {
                void (*callback)(s32, u32) = lbl_801A6C80->callback;
                if (callback) {
                    callback(-5, lbl_801A6C80->command);
                }
            }
            entries[i].bank = 0xff;
            entries[i].active = 0;
        }
    }
}

#define LEVEL(dst, v)                                                    \
    if ((v) != 0) {                                                      \
        dst = (10.0 * (20.0 * fn_80088578(v / 127.0f)));     \
    } else {                                                             \
        dst = -904;                                                      \
    }

static s16 GetZoneLevel(SndRegion *region, s32 k, u8 key) {
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

void fn_80060724(SndRegion *info, u8 index, u8 value, s32 *out0, s32 *out1, s32 *out2) {
    SndZoneList *table = info->zone;
    SndZone *range;
    SndZone *range2;
    u8 low = info->lo;
    u8 i;
    s32 level;

    *out0 = info->mode;
    range = (SndZone *)((u8 *)table + table[4].offset);
    for (i = 0; i < table[4].count; range++, i++) {
        if (value <= range->key) {
            break;
        }
        low = range->key + 1;
    }
    level = (range->slope * (value - low)) >> 8;
    level += ((lbl_80192D68[index].auxA - 64) << 1) + range->val;
    if (level > 127) {
        level = 127;
    } else if (level < 0) {
        level = 0;
    }
    LEVEL(*out1, level);
    range2 = (SndZone *)((u8 *)table + table[5].offset);
    for (i = 0; i < table[5].count; range2++, i++) {
        if (value <= range2->key) {
            break;
        }
        low = range2->key + 1;
    }
    level = (range2->slope * (value - low)) >> 8;
    level += ((lbl_80192D68[index].auxB - 64) << 1) + range2->val;
    if (level > 127) {
        level = 127;
    } else if (level < 0) {
        level = 0;
    }
    LEVEL(*out2, level);
}


s16 fn_80060950(SndRegion *info, u8 value, u8 index, f32 *out_db, s16 *out_level) {
    SndZoneList *table = info->zone;
    SndZone *range;
    SndBank *sample;
    u8 *p;
    u8 i;
    u8 low = info->lo;
    u32 n;
    u8 b;
    f32 db;
    s16 level;

    range = (SndZone *)((u8 *)table + table[0].offset);
    for (i = 0; i < table[0].count; range++, i++) {
        if (value <= range->key) {
            break;
        }
        low = range->key + 1;
    }
    n = (range->slope * (value - low)) >> 8;
    sample = lbl_801A6C80->chan[lbl_80192D68[index].bank].bank;
    /* sample->unk_84 + sample->levelOffset, spelled as integers: retail adds the offset first (add r4,r3,r4) */
    p = (u8 *)(sample->levelOffset + (u32)sample + 0x84);
    n += range->val;
    for (i = 0; i < n; i++) {
        p++;
    }
    b = *p;
    if (b != 0) {
        db = 20.0 * fn_80088578(b / 255.0f);
    } else {
        db = -960.0f;
    }
    b = lbl_80192D68[index].volume;
    if (b != 0) {
        db += (f32)(20.0 * fn_80088578(b / 127.0f));
    } else {
        db = -960.0f;
    }
    b = lbl_80192D68[index].fader;
    if (b != 0) {
        db += (f32)(20.0 * fn_80088578(b / 127.0f));
    } else {
        db = -960.0f;
    }
    level = lbl_801A6C80->trackLevel[index];
    b = lbl_801A6C80->masterVolume;
    if (b != 0) {
        db += (f32)(20.0 * fn_80088578(b / 127.0f));
    } else {
        db = -960.0f;
    }
    level += lbl_801A6C80->unk_5A10;
    *out_db = db;
    *out_level = level;
    level += (s16)(10.0f * db);
    if (level < -960) {
        level = -960;
    }
    return level;
}


void fn_80060BDC(u32 arg0) {
    u8 i = lbl_801A6C80->voice[arg0].track;
    u8 j = lbl_801A6C80->voice[arg0].index;

    if (arg0 == lbl_80192D68[i].voices[j][SND_STEP_VOICE]) {
        lbl_80192D68[i].voices[j][SND_STEP_VOICE] = 0xff;
        lbl_80192D68[i].voices[j][SND_STEP_STATE] = 0;
        return;
    }
    if (arg0 == lbl_80192D68[i].voices[j][SND_STEP_VOICE2]) {
        lbl_80192D68[i].voices[j][SND_STEP_VOICE2] = 0xff;
        lbl_80192D68[i].voices[j][SND_STEP_STATE] = 0;
    }
}

static inline SndWave *GetBankWave(u8 track, u16 sample) {
    SndBank *bank = lbl_801A6C80->chan[lbl_80192D68[track].bank].bank;
    SndWave *w = (SndWave *)(bank->waveOffset + (u32)bank + 4);
    u32 i;

    for (i = 0; i < sample - 0x100; i++) {
        w++;
    }
    return w;
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

static f64 GetZonePitch(SndRegion *region, u8 key) {
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

static f64 GetPitchRatio(SndRegion *region, u8 key, u8 track) {
    f64 cents = GetZonePitch(region, key);

    cents += 100.0 * (lbl_80192D68[track].coarse - 64) + 1.5625 * (lbl_80192D68[track].fine - 64);
    if (cents) {
        cents /= 1200.0;
    }
    return fn_80088598(2.0, cents);
}

static f64 GetRatioFrac(f64 ratio, u16 whole) {
    return (ratio - whole) * fn_80088598(2.0, 16.0);
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

    state = lbl_80192D68[track].voices[index][SND_STEP_STATE];
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
                vol = 0.75f * (left + right) + vol;
            } else {
                x = (127 - (s16)pan) / 127;
                left = -20.0 * fn_80088578(sqrt(x));
                x = (s16)pan / 127;
                right = 20.0 * fn_80088578(sqrt(x));
                pan = 0x40;
                vol = 0.75f * (left + right) + vol;
            }
        }
        fader = lbl_80092B38[region->fader];
        fn_80060724(region, track, key, &mode, &aux_a, &aux_b);
        span = GetPan(GetZoneLevel(region, 2, key), lbl_80192D68[track].span);

        lbl_80192D68[track].voices[index][SND_STEP_VOICE] = voice;
        lbl_80192D68[track].voices[index][SND_STEP_FLAGS] = region->flags;
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
        lo = GetRatioFrac(ratio, hi);
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
                lbl_80192D68[track].voices[index][SND_STEP_VOICE2] = voice2;
                lbl_80192D68[track].voices[index][SND_STEP_FLAGS] = region->flags;
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
            lbl_80192D68[track].voices[index][SND_STEP_STATE] = 1;
        } else {
            fn_8005FCD8((u8)voice);
        }
    } else {
        voice = lbl_80192D68[track].voices[index][SND_STEP_VOICE];
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
        if (lbl_80192D68[track].voices[index][SND_STEP_VOICE2] == 0xFF) {
            fn_80026D90(lbl_801A6C80->voice[voice].obj, vol);
            pan = GetPan(GetZoneLevel(region, 1, key), lbl_80192D68[track].pan);
            fn_80026EE0(lbl_801A6C80->voice[voice].obj, pan);
            fn_80026F4C(lbl_801A6C80->voice[voice].obj, span);
        } else {
            fn_8005DB68(GetPan(GetZoneLevel(region, 1, key), lbl_80192D68[track].pan), db, level, &left, &right);
            fn_80026D90(lbl_801A6C80->voice[voice].obj, left);
            fn_80026F4C(lbl_801A6C80->voice[voice].obj, span);
            voice2 = lbl_80192D68[track].voices[index][SND_STEP_VOICE2];
            fn_800234D0(lbl_801A6C80->voice[voice2].obj, fratio);
            fn_80026D90(lbl_801A6C80->voice[voice2].obj, right);
            fn_80026F4C(lbl_801A6C80->voice[voice2].obj, span);
            fn_80026E2C(lbl_801A6C80->voice[voice2].obj, aux_a);
            fn_80026EAC(lbl_801A6C80->voice[voice2].obj, aux_b);
        }
    }
}

void fn_800622B0(void) {
    SndTrack *entries = lbl_80192D68;
    u8 i;
    u8 j;

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            if (entries[i].voices[j][SND_STEP_STATE] == 1) {
                if (entries[i].voices[j][SND_STEP_VOICE] != 0xff) {
                    fn_8005FBDC(entries[i].voices[j][SND_STEP_VOICE]);
                }
                if (entries[i].voices[j][SND_STEP_VOICE2] != 0xff) {
                    fn_8005FBDC(entries[i].voices[j][SND_STEP_VOICE2]);
                }
                entries[i].voices[j][SND_STEP_STATE] = 0;
            }
        }
        entries[i].program = 0;
    }
}

/* Release the voices held by every step of the slot's current record. */
static inline void fn_80062360_release(u32 slot) {
    u8 j;
    volatile u8 *script = (u8 *)lbl_80192D68[slot].regions; /* retail keeps the record walk (lbz/add) although nothing reads it */

    for (j = 0; j <= lbl_80192D68[slot].count; j++) {
        if (lbl_80192D68[(u8)slot].voices[j][SND_STEP_STATE] == 1) {
            if (lbl_80192D68[(u8)slot].voices[j][SND_STEP_VOICE] != 0xff) {
                fn_8005FBDC(lbl_80192D68[(u8)slot].voices[j][SND_STEP_VOICE]);
            }
            if (lbl_80192D68[(u8)slot].voices[j][SND_STEP_VOICE2] != 0xff) {
                fn_8005FBDC(lbl_80192D68[(u8)slot].voices[j][SND_STEP_VOICE2]);
            }
            lbl_80192D68[(u8)slot].voices[j][SND_STEP_STATE] = 0;
        }
        script += *script;
    }
}

#pragma opt_propagation off
static inline u8 *fn_80062360_table(SndState *obj, s32 found) {
    SndChan *row = &obj->chan[found];
    return (u8 *)row->bank;
}

/* Step past the first sel+1 record offsets of the table. */
static inline u32 *fn_80062360_skip(u32 *p, u32 sel) {
    s8 k;
    for (k = 0; k <= sel; k++) {
        p++;
    }
    return p;
}

static inline void fn_80062360_apply(u32 slot, u32 level) {
    u8 j;
    u8 *script;
                script = (u8 *)lbl_80192D68[slot].regions;
                for (j = 0; j <= lbl_80192D68[slot].count; j++) {
                    if (script[4] <= level && script[5] >= level && level != 0) {
                        fn_80060C54(level, (SndRegion *)script, slot, j);
                    } else if (lbl_80192D68[(u8)slot].voices[j][SND_STEP_STATE] == 1) {
                        if (lbl_80192D68[(u8)slot].voices[j][SND_STEP_VOICE] != 0xff) {
                            fn_8005FBDC(lbl_80192D68[(u8)slot].voices[j][SND_STEP_VOICE]);
                        }
                        if (lbl_80192D68[(u8)slot].voices[j][SND_STEP_VOICE2] != 0xff) {
                            fn_8005FBDC(lbl_80192D68[(u8)slot].voices[j][SND_STEP_VOICE2]);
                        }
                        lbl_80192D68[(u8)slot].voices[j][SND_STEP_STATE] = 0;
                    }
                    script += *script;
                }
}

void fn_80062360(u32 slot, u32 sel) {
    u8 *script;
    u32 j;
    s8 found = -1;
    u8 level;
    struct { u8 key; SndChan *value; } row_cursor;
    s8 i;
    u32 *pointer;
    s8 counter;
    u8 *base;
    u8 *table;
    u8 *rec;
    SndState *obj;

    row_cursor.key = 0;
    row_cursor.value = lbl_801A6C80->chan;
    for (i = 0; i < 16; row_cursor.value++, i++) {
        row_cursor.key = lbl_80192D68[slot].id;
        if (row_cursor.key == row_cursor.value->id) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        level = lbl_80192D68[slot].program;
        if (level != 0) {
            if (lbl_80192D68[slot].active) {
                fn_80062360_release(slot);
                lbl_80192D68[slot].program = 0;
            } else {
                void (*callback)(s32, u32) = lbl_801A6C80->callback;
                if (callback) {
                    callback(-5, lbl_801A6C80->command);
                }
            }
        }

        obj = lbl_801A6C80;
        lbl_80192D68[slot].active = 1;
        base = fn_80062360_table(obj, found);
        table = base + *(s32 *)(base + 0x2c);
        rec = table + *fn_80062360_skip((u32 *)table, sel);
        lbl_80192D68[slot].count = rec[0];
        lbl_80192D68[slot].unk_D = rec[1];
        lbl_80192D68[slot].fader = rec[2];
        lbl_80192D68[slot].prio = rec[3] + 0x15;
        lbl_80192D68[slot].regions = (SndRegion *)(rec + 8);
        lbl_80192D68[slot].bank = found;

        if (level != 0) {
            if (lbl_80192D68[slot].active) {
                fn_80062360_apply(slot, level);
                lbl_80192D68[slot].program = level;
            } else {
                void (*callback)(s32, u32) = obj->callback;
                if (callback) {
                    callback(-5, obj->command);
                }
            }
        }
    } else {
        void (*callback)(s32, u32) = lbl_801A6C80->callback;
        if (callback) {
            callback(-4, lbl_801A6C80->command);
        }
    }
}
#pragma opt_propagation reset

static inline void set_program(u32 track, u32 program) {
    u8 i;
    SndRegion *r;

    if (lbl_80192D68[track].active != 0) {
        r = lbl_80192D68[track].regions;
        for (i = 0; i <= lbl_80192D68[track].count; i++) {
            if (r->lo <= program && r->hi >= program && program != 0) {
                fn_80060C54(program, r, track, i);
            } else if (lbl_80192D68[track].voices[i][SND_STEP_STATE] == 1) {
                if (lbl_80192D68[track].voices[i][SND_STEP_VOICE] != 0xFF) {
                    fn_8005FBDC(lbl_80192D68[track].voices[i][SND_STEP_VOICE]);
                }
                if (lbl_80192D68[track].voices[i][SND_STEP_VOICE2] != 0xFF) {
                    fn_8005FBDC(lbl_80192D68[track].voices[i][SND_STEP_VOICE2]);
                }
                lbl_80192D68[track].voices[i][SND_STEP_STATE] = 0;
            }
            r = (SndRegion *)((u8 *)r + r->size);
        }
        lbl_80192D68[track].program = program;
    } else if (lbl_801A6C80->callback != NULL) {
        lbl_801A6C80->callback(-5, lbl_801A6C80->command);
    }
}

static inline void refresh(u32 track) {
    if (lbl_80192D68[track].active != 0 && lbl_80192D68[track].program != 0) {
        set_program(track, lbl_80192D68[track].program);
    }
}

void fn_80062654(void) {
    u32 command = lbl_801A6C80->command;
    u32 track = (command >> 16) & 0xF;
    u32 value = (command >> 8) & 0x7F;

    switch (command & 0xFF700000) {
    case 0xA5000000:
        fn_80062360(track, value);
        break;
    case 0xA5100000:
        lbl_80192D68[track].volume = value;
        refresh(track);
        break;
    case 0xA5200000:
        lbl_80192D68[track].pan = value;
        refresh(track);
        break;
    case 0xA5300000:
        lbl_80192D68[track].span = value;
        refresh(track);
        break;
    case 0xA5400000:
        lbl_80192D68[track].auxA = value;
        refresh(track);
        break;
    case 0xA5500000:
        lbl_80192D68[track].auxB = value;
        refresh(track);
        break;
    case 0xA5700000:
        lbl_80192D68[track].id = value;
        break;
    case 0xA7000000:
        lbl_80192D68[track].coarse = value;
        refresh(track);
        break;
    case 0xA7100000:
        lbl_80192D68[track].fine = value;
        refresh(track);
        break;
    case 0xA6100000:
        value += 0x80;
    case 0xA6000000:
        set_program(track, value);
        break;
    case 0xA7200000:
        lbl_801A6C80->trackLevel[track] = lbl_801A6C80->trackLevelInit[track];
        refresh(track);
        break;
    }
}

extern s32 fn_80067898(u32);

s32 fn_80063094(s32 arg0, s32 arg1, s32 arg2) {
    u32 v0 = (arg0 & 0xF) << 16;
    u8 *p = (u8 *)(v0 + arg1);
    s32 r;

    switch (arg1) {
    case 0xA5000000:
        r = fn_80067898((u32)((v0 - 0x5A900000) + (arg2 & 0x7F00)));
        if (r != 0)
            return r;
        p = (u8 *)(v0 - 0x5B000000) + ((arg2 & 0x7F) << 8);
        break;
    case 0xA5100000:
        p += (arg2 & 0x7F) << 8;
        break;
    case 0xA5200000:
    case 0xA5300000:
    case 0xA5400000:
    case 0xA5500000:
    case 0xA7000000:
    case 0xA7100000:
        p += ((arg2 + 0x40) & 0x7F) << 8;
        break;
    case 0xA6000000:
        p += ((arg2 & 0x7F) << 8) + ((arg2 << 13) & 0x100000);
        break;
    case 0xA7200000: {
        u8 *q = (u8 *)lbl_801A6C80;
        q += (arg0 & 0xF) << 1;
        *(u16 *)(q + 0x5AF4) = arg2;
        break;
    }
    default:
        return -2;
    }
    return fn_80067898((u32)p);
}


void fn_800631EC(void) {
    u8 i;
    u8 j;

    for (i = 0; i < 16; i++) {
        lbl_80192D68[i].bank = 0xff;
        lbl_80192D68[i].active = 0;
        lbl_80192D68[i].volume = 0x7f;
        lbl_80192D68[i].pan = 0x40;
        lbl_80192D68[i].span = 0x40;
        lbl_80192D68[i].auxA = 0x40;
        lbl_80192D68[i].auxB = 0x40;
        lbl_80192D68[i].coarse = 0x40;
        lbl_80192D68[i].fine = 0x40;
        lbl_80192D68[i].program = 0;
        lbl_80192D68[i].count = 0;
        lbl_80192D68[i].unk_D = 0;
        lbl_80192D68[i].fader = 0;
        lbl_80192D68[i].prio = 0;
        lbl_80192D68[i].regions = 0;
        for (j = 0; j < 16; j++) {
            lbl_80192D68[i].voices[j][SND_STEP_STATE] = 0;
            lbl_80192D68[i].voices[j][SND_STEP_FLAGS] = 0;
            lbl_80192D68[i].voices[j][SND_STEP_VOICE] = 0xff;
            lbl_80192D68[i].voices[j][SND_STEP_VOICE2] = 0xff;
        }
    }
}
