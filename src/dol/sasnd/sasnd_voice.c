#include "sasnd/sasnd.h"
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

static const s16 lbl_800929D8[16] = {
    -900, -420, -390, -360, -330, -300, -270, -240, -210, -180, -150, -120, -90, -60, -30, 0
};
static const u8 lbl_800929F8[32] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xEF, 0xDF, 0xCF, 0xBF, 0xAF, 0x9F, 0x8F, 0x7F, 0x6F, 0x5F, 0x4F, 0x3F, 0x2F, 0x1F, 0x0F, 0x00
};
static const u8 lbl_80092A18[32] = {
    0x0F, 0x1F, 0x2F, 0x3F, 0x4F, 0x5F, 0x6F, 0x7F, 0x8F, 0x9F, 0xAF, 0xBF, 0xCF, 0xDF, 0xEF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00
};
static const u8 lbl_80092A38[128] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x07, 0x07, 0x08, 0x09,
    0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x13, 0x14, 0x15, 0x17, 0x18, 0x1A, 0x1C, 0x1D,
    0x1F, 0x21, 0x23, 0x25, 0x27, 0x29, 0x2B, 0x2E, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3A, 0x3C, 0x3E,
    0x40, 0x42, 0x44, 0x46, 0x48, 0x4A, 0x4C, 0x4E, 0x50, 0x52, 0x54, 0x57, 0x59, 0x5B, 0x5D, 0x5E,
    0x60, 0x62, 0x64, 0x65, 0x67, 0x68, 0x6A, 0x6B, 0x6C, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74,
    0x75, 0x76, 0x77, 0x77, 0x78, 0x79, 0x79, 0x7A, 0x7B, 0x7B, 0x7C, 0x7C, 0x7C, 0x7D, 0x7D, 0x7D,
    0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F
};
static const u8 lbl_80092AB8[128] = {
    0x00, 0x0B, 0x0F, 0x13, 0x16, 0x19, 0x1B, 0x1D, 0x1F, 0x21, 0x23, 0x25, 0x27, 0x28, 0x2A, 0x2B,
    0x2D, 0x2E, 0x2F, 0x31, 0x32, 0x33, 0x34, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E,
    0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x49, 0x4A, 0x4B, 0x4C, 0x4D,
    0x4E, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x52, 0x53, 0x54, 0x55, 0x55, 0x56, 0x57, 0x58, 0x58, 0x59,
    0x5A, 0x5A, 0x5B, 0x5C, 0x5C, 0x5D, 0x5E, 0x5E, 0x5F, 0x60, 0x60, 0x61, 0x62, 0x62, 0x63, 0x64,
    0x64, 0x65, 0x66, 0x66, 0x67, 0x67, 0x68, 0x69, 0x69, 0x6A, 0x6A, 0x6B, 0x6C, 0x6C, 0x6D, 0x6D,
    0x6E, 0x6E, 0x6F, 0x70, 0x70, 0x71, 0x71, 0x72, 0x72, 0x73, 0x74, 0x74, 0x75, 0x75, 0x76, 0x76,
    0x77, 0x77, 0x78, 0x78, 0x79, 0x79, 0x7A, 0x7A, 0x7B, 0x7B, 0x7C, 0x7C, 0x7D, 0x7D, 0x7E, 0x7F
};

extern void fn_80060BDC(u32);
extern u32 fn_80063F38(u32, u32);
extern u32 fn_8006953C(u32);
extern void fn_8006413C(void *);
void fn_8005DB68(s16 arg0, f32 arg1, s16 arg2, s16 *arg3, s16 *arg4);
void fn_8005FBDC(u32 index);
void fn_8005FCD8(u32 arg0);
extern u32 lbl_801299D0[];
extern u32 lbl_80129AD0[];
extern u32 lbl_80129BD0[];
extern u32 lbl_80129CD0[];
extern u32 lbl_80129DD0[];
extern u32 lbl_80129ED0[];

extern u32 fn_80082908(void);
extern s32 fn_80063EF4(u8, u8, u8);
extern s32 fn_8006496C(u8);
extern void fn_80028130(void *, void *, u32);
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
extern void fn_80028424(void *);

extern void fn_80064A30(u16, u32);
extern void fn_800643F4(u16);
extern void fn_800622B0(void);
extern u32 fn_80021928(void);
extern void fn_80021914(u32);
extern u32 fn_80025EEC(void);
extern void fn_80025EE4(u32);
extern void fn_800647B8(u32);
extern u32 fn_80069AE0(void);
extern void fn_80064230(u16, u16);
extern void fn_800641A8(u16);
extern void fn_80065528(u32);
extern void fn_80065390(void);
extern void fn_8006331C(u8, u8);
extern void fn_80062654(u8);
extern void fn_80064E84(u8, u8);

void fn_8005C298(s32 id, u8 mode) {
SndNote *param;
s8 v;
s32 t;
u8 s;
SndSlot *slot;
SndState *state;
struct { SndHeader *ptr; } in;
state = lbl_801A6C80 ;
slot = (&((SndSlot *)state->slot)[(u8)((&state->voice[id])->slot)]) ;
if (slot->seq == 0) {
return;
}
in.ptr = (&state->voice[id])->hdr;
param = (&state->voice[id])->note;
if (mode != 1) {
return;
}
v = in.ptr->unk_D;
if (v > 0) {
t = (v + 1) * 1200;
t >>= 7;
t *= slot->unk_13;
t >>= 7;
t += param->unk_28;
if (t > 1200) {
t = 1200;
}
} else if (v < 0) {
t = __fabs(v);
t *= 1200;
t >>= 7;
t *= slot->unk_13;
t >>= 7;
t = param->unk_28 - t;
if (t < 0) {
t = 0;
}
} else {
t = param->unk_28;
}
(&lbl_801A6C80->voice[id])->unk_E8 = t << 16;
state = lbl_801A6C80 ;
s = (&state->voice[id])->slot;
v = in.ptr->unk_F;
if (v > 0) {
t = (v + 1) * 120;
t >>= 7;
t *= (&((SndSlot *)state->slot)[s]) ->unk_13;
t >>= 7;
t = param->unk_2A + t;
if (t > 120) {
t = 120;
}
} else if (v < 0) {
t = __fabs(v);
t *= 120;
t >>= 7;
t *= (&((SndSlot *)state->slot)[s]) ->unk_13;
t >>= 7;
t = param->unk_2A - t;
if (t < 0) {
t = 0;
}
} else {
t = param->unk_2A;
}
(&lbl_801A6C80->voice[id])->volEnv = t << 16;
(&lbl_801A6C80->voice[id])->volDelta = ((&lbl_801A6C80->voice[id])->vol - t) << 16;
}

static inline s16 Pitch(u8 slot, u8 *seq, u8 key, SndHeader *hdr, s16 *rnd, SndNote *note) {
    s32 fine;
    s32 coarse;
    s32 detune;

    coarse = seq[0] != 0 ? 0 : key - 60;
    coarse += note->unk_A + lbl_801A6C80->slot[slot].unk_E;
    fine = note->unk_B + lbl_801A6C80->slot[slot].unk_F;
    if (note->unk_14 != 0) {
        fine += *rnd;
    } else {
        *rnd = 0;
    }
    detune = fn_80063EF4(slot, hdr->unk_19, hdr->unk_1A);
    fine += (detune >> 2) & 0x3F;
    coarse += detune >> 8;
    return 100.0 * coarse + 1.5625 * fine;
}

void fn_8005C478(u32 voice) {
    u8 slot;
    u8 *seq;
    SndNote *note;
    SndHeader *hdr;

    slot = lbl_801A6C80->voice[voice].slot;
    seq = lbl_801A6C80->slot[slot].seq;
    if (seq == NULL) {
        return;
    }
    hdr = lbl_801A6C80->voice[voice].hdr;
    note = lbl_801A6C80->voice[voice].note;
    lbl_801A6C80->voice[voice].unk_78 = Pitch(slot, seq, lbl_801A6C80->voice[voice].time >> 16, hdr, &lbl_801A6C80->voice[voice].rnd, note) << 16;
}

#define LEVEL(dst, v)                                                    \
    if ((v) != 0) {                                                      \
        dst = (10.0 * (20.0 * fn_80088578(v / 127.0f)));     \
    } else {                                                             \
        dst = -904;                                                      \
    }

void fn_8005C5C8(s32 arg0) {
    u8 *ptr = lbl_801A6C80->slot[lbl_801A6C80->voice[arg0].slot].seq;
    SndNote *info;
    s32 left;
    s32 right;
    u8 v;
    u8 idx;

    if (ptr == NULL) {
        return;
    }
    info = lbl_801A6C80->voice[arg0].note;
    v = *ptr;
    if (info->unk_15 != 0 || v == 0) {
        idx = lbl_801A6C80->voice[arg0].slot;
        LEVEL(left, lbl_801A6C80->slot[idx].unk_B);
        LEVEL(right, lbl_801A6C80->slot[idx].unk_C);
    } else {
        LEVEL(left, info->unk_17);
        LEVEL(right, info->unk_18);
    }
    lbl_801A6C80->voice[arg0].unk_9C = left;
    lbl_801A6C80->voice[arg0].unk_A8 = right;
}

static inline void fn_8005C7C0_levels(u8 *tbl, s16 arg0, f32 arg1, s16 arg2, s32 *arg3, s32 *arg4) {
    u32 idx = (arg0 / 4 - 1) & 0xFF;
    f32 a;
    f32 b;

    a = arg1 + (f32)(20.0 * fn_80088578((f32)lbl_800929F8[idx] / 255.0f));
    b = arg1 + (f32)(20.0 * fn_80088578((f32)lbl_80092A18[idx] / 255.0f));

    *arg3 = (s32)((f32)arg2 + 10.0f * a);
    *arg4 = (s32)((f32)arg2 + 10.0f * b);

    if ((s16)*arg3 < -960) {
        *arg3 = -960;
    }
    if ((s16)*arg4 < -960) {
        *arg4 = -960;
    }
}

void fn_8005C7C0(u32 arg0) {
    extern s32 fn_8005D258(SndHeader *, SndNote *, u8, u32, f32 *, s16 *);
    SndNote *info;
    s32 result;
    f32 vol;
    s16 pan;
    s32 left;
    s32 right;
    u8 v;
    u8 slot;
    s16 level;
    u32 flags;

    /* WARNING: compiler-diff device, not original code: volatile keeps this load before the note load. */
    flags = ((volatile SndVoice *)lbl_801A6C80->voice)[arg0].time; /* volatile: retail load order */
    info = lbl_801A6C80->voice[arg0].note;
    fn_8005D258(lbl_801A6C80->voice[arg0].hdr, info, lbl_801A6C80->voice[arg0].slot,
                (flags >> 8) & 0xFF, &vol, &pan);
    v = info->pan;
    slot = lbl_801A6C80->voice[arg0].slot;
    if (v & 0x80) {
        v = lbl_801A6C80->slot[slot].unk_8;
    }
    level = lbl_80092A38[v];
    if (lbl_801A6C80->voice[arg0].link0 != 0xFF || lbl_801A6C80->voice[arg0].link1 != 0xFF) {
        fn_8005C7C0_levels((u8 *)lbl_800929D8, level, vol, pan, &left, &right);
        if (lbl_801A6C80->voice[arg0].link0 == arg0) {
            result = (s16)left;
        } else {
            result = (s16)right;
        }
        lbl_801A6C80->voice[arg0].volDelta = (result - (lbl_801A6C80->voice[arg0].volEnv >> 16)) << 16;
        lbl_801A6C80->voice[arg0].vol = result;
    } else {
        lbl_801A6C80->voice[arg0].unk_90 = level;
    }
}

static inline void fn_8005C9D8_levels(u8 *tbl, s16 arg0, f32 arg1, s16 arg2, s32 *arg3, s32 *arg4) {
    u32 idx = (arg0 / 4 - 1) & 0xFF;
    f32 a;
    f32 b;

    a = arg1 + (f32)(20.0 * fn_80088578((f32)lbl_800929F8[idx] / 255.0f));
    b = arg1 + (f32)(20.0 * fn_80088578((f32)lbl_80092A18[idx] / 255.0f));

    *arg3 = (s32)((f32)arg2 + 10.0f * a);
    *arg4 = (s32)((f32)arg2 + 10.0f * b);

    if ((s16)*arg3 < -960) {
        *arg3 = -960;
    }
    if ((s16)*arg4 < -960) {
        *arg4 = -960;
    }
}

void fn_8005C9D8(u32 arg0) {
    extern s32 fn_8005D258(SndHeader *, SndNote *, u8, u32, f32 *, s16 *);
    SndNote *info;
    s32 result;
    f32 vol;
    s16 pan;
    s32 left;
    s32 right;
    u8 v;
    u8 slot;
    u32 flags;

    /* WARNING: compiler-diff device, not original code: volatile keeps this load before the note load. */
    flags = ((volatile SndVoice *)lbl_801A6C80->voice)[arg0].time; /* volatile: retail load order */
    info = lbl_801A6C80->voice[arg0].note;
    result = fn_8005D258(lbl_801A6C80->voice[arg0].hdr, info, lbl_801A6C80->voice[arg0].slot,
                         (flags >> 8) & 0xFF, &vol, &pan);
    result = (s16)result;
    if (lbl_801A6C80->voice[arg0].link0 != 0xFF || lbl_801A6C80->voice[arg0].link1 != 0xFF) {
        v = info->pan;
        slot = lbl_801A6C80->voice[arg0].slot;
        if (v & 0x80) {
            v = lbl_801A6C80->slot[slot].unk_8;
        }
        fn_8005C9D8_levels((u8 *)lbl_800929D8, lbl_80092A38[v], vol, pan, &left, &right);
        if (lbl_801A6C80->voice[arg0].link0 == arg0) {
            result = (s16)left;
        } else {
            result = (s16)right;
        }
    }
    lbl_801A6C80->voice[arg0].volDelta = (result - (lbl_801A6C80->voice[arg0].volEnv >> 16)) << 16;
    lbl_801A6C80->voice[arg0].vol = result;
}

void fn_8005CBF4(u32 arg0) {
    u32 v1;
    u8 v3;
    u32 v4;
    u32 v5;
    s32 v7;
    u32 v8;
    u32 v9;
    u32 v10;
    u32 v11;
    s32 v14;
    u32 v15;
    u32 v16;
    u32 v17;
    u32 v18;
    u8 v19;
    s32 v21;
    u32 v22;
    u32 v23;
    u32 v24;
    u32 v25;
    s32 v28;
    u32 v29;
    u32 v30;
    u32 v31;
    u32 v32;
    u8 v33;
    s32 v35;
    u32 v36;
    u32 v37;
    u32 v38;
    u32 v39;
    u8 v40;
    s32 v42;
    u32 v43;
    u32 v44;
    u32 v45;
    u32 v46;
    u32 v47;
    u32 v2;
    v1 = lbl_801A6C80->command;
    v2 = v1 & 0x1F;
    v3 = 0;
    while (v3 < 64) {
        if (arg0 + 0x60000000 == 256) {
            v7 = (u32)v3 * 280;
            v8 = (u32)lbl_801A6C80 + v7;
            if ((*(u8 *)(v8 + 5136) & 0x80) == 0 && *(u8 *)(v8 + 5128) != 255) {
                fn_80023168(*(void **)(v8 + 5172), 0);
                fn_80026D70(lbl_801A6C80->voice[v3].obj);
                fn_80020ABC(lbl_801A6C80->voice[v3].obj);
                v9 = v7 + 5172;
                lbl_801A6C80->voice[v3].obj = 0;
                if (lbl_801A6C80->voice[v3].state == 3) {
                    fn_80060BDC(v3);
                } else {
                    fn_80028424(lbl_801A6C80->voice[v3].env);
                }
                v4 = 255;
                lbl_801A6C80->voice[v3].state = v4;
                v5 = 0;
                v10 = v7 + 5129;
                lbl_801A6C80->voice[v3].time = v5;
                lbl_801A6C80->voice[v3].active = v5;
                v11 = (u32)lbl_801A6C80 + v7;
                if (*(u8 *)(v11 + 5137) == (u32)v3) {
                    *(u8 *)((u8 *)v11 + 5137) = v4;
                } else if (*(u8 *)(v11 + 5138) == (u32)v3) {
                    *(u8 *)((u8 *)v11 + 5138) = v4;
                }
            }
        }
        else if (arg0 + 0x60000000 == 512) {
            v14 = (u32)v3 * 280;
            v15 = (u32)lbl_801A6C80 + v14;
            if (*(u8 *)(v15 + 5128) == 1 && *(u8 *)(v15 + 5128) != 255) {
                fn_80023168(*(void **)(v15 + 5172), 0);
                fn_80026D70(lbl_801A6C80->voice[v3].obj);
                fn_80020ABC(lbl_801A6C80->voice[v3].obj);
                v16 = v14 + 5172;
                lbl_801A6C80->voice[v3].obj = 0;
                if (lbl_801A6C80->voice[v3].state == 3) {
                    fn_80060BDC(v3);
                } else {
                    fn_80028424(lbl_801A6C80->voice[v3].env);
                }
                v4 = 255;
                lbl_801A6C80->voice[v3].state = v4;
                v5 = 0;
                v17 = v14 + 5129;
                lbl_801A6C80->voice[v3].time = v5;
                lbl_801A6C80->voice[v3].active = v5;
                v18 = (u32)lbl_801A6C80 + v14;
                if (*(u8 *)(v18 + 5137) == (u32)v3) {
                    *(u8 *)((u8 *)v18 + 5137) = v4;
                } else if (*(u8 *)(v18 + 5138) == (u32)v3) {
                    *(u8 *)((u8 *)v18 + 5138) = v4;
                }
            }
        }
        else if (arg0 + 0x60000000 == 768) {
            v21 = (u32)v3 * 280;
            v22 = (u32)lbl_801A6C80 + v21;
            v19 = lbl_801A6C80->voice[v3].state;
            if (v19 == 2 && (lbl_801A6C80->voice[v3].prio & 0x80) == 0 && v19 != 255) {
                fn_80023168(lbl_801A6C80->voice[v3].obj, 0);
                fn_80026D70(lbl_801A6C80->voice[v3].obj);
                fn_80020ABC(lbl_801A6C80->voice[v3].obj);
                v23 = v21 + 5172;
                lbl_801A6C80->voice[v3].obj = 0;
                if (lbl_801A6C80->voice[v3].state == 3) {
                    fn_80060BDC(v3);
                } else {
                    fn_80028424(lbl_801A6C80->voice[v3].env);
                }
                v4 = 255;
                lbl_801A6C80->voice[v3].state = v4;
                v5 = 0;
                v24 = v21 + 5129;
                lbl_801A6C80->voice[v3].time = v5;
                lbl_801A6C80->voice[v3].active = v5;
                v25 = (u32)lbl_801A6C80 + v21;
                if (*(u8 *)(v25 + 5137) == (u32)v3) {
                    *(u8 *)((u8 *)v25 + 5137) = v4;
                } else if (*(u8 *)(v25 + 5138) == (u32)v3) {
                    *(u8 *)((u8 *)v25 + 5138) = v4;
                }
            }
        }
        else if (arg0 + 0x60000000 == 4352) {
            v28 = (u32)v3 * 280;
            v29 = (u32)lbl_801A6C80 + v28;
            if ((*(u32 *)(v29 + 5152) & 0xF) == v2 && (*(u8 *)(v29 + 5136) & 0x80) == 0 && *(u8 *)(v29 + 5128) != 255) {
                fn_80023168(*(void **)(v29 + 5172), 0);
                fn_80026D70(lbl_801A6C80->voice[v3].obj);
                fn_80020ABC(lbl_801A6C80->voice[v3].obj);
                v30 = v28 + 5172;
                lbl_801A6C80->voice[v3].obj = 0;
                if (lbl_801A6C80->voice[v3].state == 3) {
                    fn_80060BDC(v3);
                } else {
                    fn_80028424(lbl_801A6C80->voice[v3].env);
                }
                v4 = 255;
                lbl_801A6C80->voice[v3].state = v4;
                v5 = 0;
                v31 = v28 + 5129;
                lbl_801A6C80->voice[v3].time = v5;
                lbl_801A6C80->voice[v3].active = v5;
                v32 = (u32)lbl_801A6C80 + v28;
                if (*(u8 *)(v32 + 5137) == (u32)v3) {
                    *(u8 *)((u8 *)v32 + 5137) = v4;
                } else if (*(u8 *)(v32 + 5138) == (u32)v3) {
                    *(u8 *)((u8 *)v32 + 5138) = v4;
                }
            }
        }
        else if (arg0 + 0x60000000 == 4608) {
            v35 = (u32)v3 * 280;
            v36 = (u32)lbl_801A6C80 + v35;
            v33 = lbl_801A6C80->voice[v3].state;
            if (v33 == 1 && (lbl_801A6C80->voice[v3].time & 0xF) == v2 && v33 != 255) {
                fn_80023168(lbl_801A6C80->voice[v3].obj, 0);
                fn_80026D70(lbl_801A6C80->voice[v3].obj);
                fn_80020ABC(lbl_801A6C80->voice[v3].obj);
                v37 = v35 + 5172;
                lbl_801A6C80->voice[v3].obj = 0;
                if (lbl_801A6C80->voice[v3].state == 3) {
                    fn_80060BDC(v3);
                } else {
                    fn_80028424(lbl_801A6C80->voice[v3].env);
                }
                v4 = 255;
                lbl_801A6C80->voice[v3].state = v4;
                v5 = 0;
                v38 = v35 + 5129;
                lbl_801A6C80->voice[v3].time = v5;
                lbl_801A6C80->voice[v3].active = v5;
                v39 = (u32)lbl_801A6C80 + v35;
                if (*(u8 *)(v39 + 5137) == (u32)v3) {
                    *(u8 *)((u8 *)v39 + 5137) = v4;
                } else if (*(u8 *)(v39 + 5138) == (u32)v3) {
                    *(u8 *)((u8 *)v39 + 5138) = v4;
                }
            }
        }
        else if (arg0 + 0x60000000 == 4864) {
            v42 = (u32)v3 * 280;
            v43 = (u32)lbl_801A6C80 + v42;
            v40 = lbl_801A6C80->voice[v3].state;
            if (v40 == 2 && (lbl_801A6C80->voice[v3].time & 0xF) == v2 && (lbl_801A6C80->voice[v3].prio & 0x80) == 0 && v40 != 255) {
                fn_80023168(lbl_801A6C80->voice[v3].obj, 0);
                fn_80026D70(lbl_801A6C80->voice[v3].obj);
                fn_80020ABC(lbl_801A6C80->voice[v3].obj);
                v44 = v42 + 5172;
                lbl_801A6C80->voice[v3].obj = 0;
                if (lbl_801A6C80->voice[v3].state == 3) {
                    fn_80060BDC(v3);
                } else {
                    fn_80028424(lbl_801A6C80->voice[v3].env);
                }
                v4 = 255;
                lbl_801A6C80->voice[v3].state = v4;
                v5 = 0;
                v45 = v42 + 5129;
                lbl_801A6C80->voice[v3].time = v5;
                lbl_801A6C80->voice[v3].active = v5;
                v46 = (u32)lbl_801A6C80 + v42;
                if (*(u8 *)(v46 + 5137) == (u32)v3) {
                    *(u8 *)((u8 *)v46 + 5137) = v4;
                } else if (*(u8 *)(v46 + 5138) == (u32)v3) {
                    *(u8 *)((u8 *)v46 + 5138) = v4;
                }
            }
        }
        v3++;
    }
    if (arg0 + 0x60000000 == 256) {
        fn_8006413C((void *)1);
    } else if (arg0 + 0x60000000 == 4352) {
        fn_80063F38(17, v2);
    }
    v47 = lbl_801A6C80->command;
    if ((v47 & 0x40) == 0) {
        fn_8006953C(v47);
    }
}

s16 fn_8005D258(SndHeader *arg0, SndNote *info, u8 slot, u8 count, f32 *out_db, s16 *out_level) {
    SndBank *bank;
    u8 *p;
    u8 i;
    u8 v;
    f32 level;
    s16 result;

    bank = lbl_801A6C80->chan[lbl_801A6C80->curChan].bank;
    if (bank != NULL) {
        /* the record address spelled as integers, as in fn_80069FCC.c */
        p = (u8 *)(bank->levelOffset + (u32)bank + arg0->unk_6 * 0x80 + 4);
        for (i = 0; i < count; i++) {
            p++;
        }
        v = *p;
        if (v != 0) {
            level = 20.0 * fn_80088578(v / 255.0f);
        } else {
            level = -960.0f;
        }
        v = info->unk_9;
        if (v != 0) {
            level += (f32)(20.0 * fn_80088578(v / 255.0f));
        } else {
            level = -960.0f;
        }
        v = lbl_801A6C80->slot[slot].unk_7;
        if (v != 0) {
            level += (f32)(20.0 * fn_80088578(v / 127.0f));
        } else {
            level = -960.0f;
        }
        v = lbl_801A6C80->slot[slot].unk_10;
        if (v != 0) {
            level += (f32)(20.0 * fn_80088578(v / 127.0f));
        } else {
            level = -960.0f;
        }
        if (lbl_801A6C80->slot[slot].unk_1 & 1) {
            result = lbl_801A6C80->unk_5A54[lbl_801A6C80->curChan];
        } else {
            v = lbl_801A6C80->mix[lbl_801A6C80->curChan].unk_9;
            if (v != 0) {
                level += (f32)(20.0 * fn_80088578(v / 127.0f));
            } else {
                level = -960.0f;
            }
            result = lbl_801A6C80->unk_5A34[lbl_801A6C80->curChan];
        }
        v = lbl_801A6C80->masterVolume;
        if (v != 0) {
            level += (f32)(20.0 * fn_80088578(v / 127.0f));
        } else {
            level = -960.0f;
        }
        result += lbl_801A6C80->unk_5A10;
        *out_db = level;
        *out_level = result;
        result += (s16)(10.0f * level);
        if (result < -960) {
            result = -960;
        }
        return result;
    } else {
        *out_db = -960.0f;
        *out_level = -960;
        return -960;
    }
}

static inline void stop(u32 i) {
    s16 value;
    if (lbl_801A6C80->voice[i].state != 255) {
        lbl_801A6C80->voice[i].active = 2;
        if (lbl_801A6C80->voice[i].state == 3) {
            lbl_801A6C80->voice[i].step = -960 / lbl_801A6C80->voice[i].unk_E;
            if (lbl_801A6C80->voice[i].step == 0) lbl_801A6C80->voice[i].step = -1;
        } else {
            value = lbl_801A6C80->voice[i].note->unk_12;
            if (value != 0) lbl_801A6C80->voice[i].unk_B4 = value << 16;
            else lbl_801A6C80->voice[i].unk_B4 = 0xFC400000;
            lbl_801A6C80->voice[i].unk_B8 = 0xFC400000;
            lbl_801A6C80->voice[i].unk_E = 2;
        }
        if (lbl_801A6C80->voice[i].prio >= 2 && !(lbl_801A6C80->voice[i].prio & 0x80)) {
            lbl_801A6C80->voice[i].prio--;
            fn_80020CB0(lbl_801A6C80->voice[i].obj, lbl_801A6C80->voice[i].prio);
        }
    }
}
s32 fn_8005D5A4(SndNote *arg0) {
    u32 i;
    s32 result = 0;
    u32 flags = arg0->unk_1B & 0x8F;
    /* Share the common return path used by all command branches. */
    if (flags == 0) goto end;
    if (flags == 0x80) {
        for (i = 0; i < 64; i++) {
            if ((lbl_801A6C80->voice[i].state == 1 || lbl_801A6C80->voice[i].state == 2) &&
                lbl_801A6C80->voice[i].unk_5 == 0x80 &&
                (lbl_801A6C80->voice[i].time & 0x0F7F00FF) == (lbl_801A6C80->command & 0x0F7F00FF)) {
                stop(i);
            }
        }
    } else if (flags & 1) {
        for (i = 0; i < 64; i++) {
            if ((lbl_801A6C80->voice[i].state == 1 || lbl_801A6C80->voice[i].state == 2) &&
                lbl_801A6C80->voice[i].unk_5 == 0x81 &&
                (lbl_801A6C80->voice[i].time & 0x0F00000F) == (lbl_801A6C80->command & 0x0F00000F) &&
                lbl_801A6C80->voice[i].unk_4 == arg0->unk_1C) {
                stop(i);
            }
        }
    } else if (flags & 2) {
        for (i = 0; i < 64; i++) {
            if ((lbl_801A6C80->voice[i].state == 1 || lbl_801A6C80->voice[i].state == 2) &&
                lbl_801A6C80->voice[i].unk_5 == 0x82 &&
                (lbl_801A6C80->voice[i].time & 0x0F00000F) == (lbl_801A6C80->command & 0x0F00000F) &&
                lbl_801A6C80->voice[i].unk_4 == arg0->unk_1C) {
                result = 1;
                break;
            }
        }
    } else if (flags & 4) {
        for (i = 0; i < 64; i++) {
            if ((lbl_801A6C80->voice[i].state == 1 || lbl_801A6C80->voice[i].state == 2) &&
                lbl_801A6C80->voice[i].unk_5 == 0x84 &&
                (lbl_801A6C80->voice[i].time & 0x0F000000) == (lbl_801A6C80->command & 0x0F000000) &&
                lbl_801A6C80->voice[i].unk_4 == arg0->unk_1C) {
                stop(i);
            }
        }
    } else if (flags & 8) {
        for (i = 0; i < 64; i++) {
            if ((lbl_801A6C80->voice[i].state == 1 || lbl_801A6C80->voice[i].state == 2) &&
                lbl_801A6C80->voice[i].unk_5 == 0x88 &&
                (lbl_801A6C80->voice[i].time & 0x0F000000) == (lbl_801A6C80->command & 0x0F000000) &&
                lbl_801A6C80->voice[i].unk_4 == arg0->unk_1C) {
                result = 1;
                break;
            }
        }
    }
end:
    return result;
}

void fn_8005DB68(s16 arg0, f32 arg1, s16 arg2, s16 *arg3, s16 *arg4) {
    u32 idx = (arg0 / 4 - 1) & 0xFF;
    f32 a;
    f32 b;

    a = arg1 + (f32)(20.0 * fn_80088578(lbl_800929F8[idx] / 255.0f));
    b = arg1 + (f32)(20.0 * fn_80088578(lbl_80092A18[idx] / 255.0f));

    *arg3 = (s16)(s32)((f32)arg2 + 10.0f * a);
    *arg4 = (s16)(s32)((f32)arg2 + 10.0f * b);

    if (*arg3 < -960) {
        *arg3 = -960;
    }
    if (*arg4 < -960) {
        *arg4 = -960;
    }
}

static inline void StereoLevels(s16 arg0, f32 arg1, s16 arg2, s16 *arg3, s16 *arg4) {
    u32 idx = (arg0 / 4 - 1) & 0xFF;
    f32 a;
    f32 b;

    a = arg1 + (f32)(20.0 * fn_80088578((f32)lbl_800929F8[idx] / 255.0f));
    b = arg1 + (f32)(20.0 * fn_80088578((f32)lbl_80092A18[idx] / 255.0f));

    *arg3 = (f32)arg2 + 10.0f * a;
    *arg4 = (f32)arg2 + 10.0f * b;

    if (*arg3 < -960) {
        *arg3 = -960;
    }
    if (*arg4 < -960) {
        *arg4 = -960;
    }
}

static inline void KillVoice(u32 arg0) {
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
    SndBank *bank = lbl_801A6C80->chan[lbl_801A6C80->curChan].bank;
    SndWave *w = (SndWave *)(bank->waveOffset + (u32)bank + 4);
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
    vel = (lbl_801A6C80->command >> 8) & 0xFF;
    key = (lbl_801A6C80->command >> 16) & 0xFF;
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
        n = (((lbl_801A6C80->command >> 4) & 0xF) << 7) | key;
        if ((s32)n <= hdr->count) {
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
        if (lbl_801A6C80->masterVolume == 0) {
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
        lbl_801A6C80->unk_46C = lbl_801A6C80->command;
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
    lbl_801A6C80->voice[voice].time = lbl_801A6C80->command;
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
        StereoLevels(lbl_80092A38[p], db, level, &left, &right);
        vol = left;
    } else {
        p = note->pan;
        if (p & 0x80) {
            p = lbl_801A6C80->slot[arg1].unk_8;
        }
        pan = lbl_80092A38[p];
    }
    if (lbl_801A6C80->unk_462 == 0) {
        if (wave->stereo == 1) {
            pan = 0x40;
            vol = (s16)(0.75f * (left + right) + vol);
        } else {
            left = -20.0 * fn_80088578(sqrt((f32)((127 - pan) / 127)));
            right = 20.0 * fn_80088578(sqrt((f32)(pan / 127)));
            pan = 0x40;
            vol = (s16)(0.75f * (left + right) + vol);
        }
    }

    if (note->unk_8 & 0x80) {
        bend = ((s16 *)lbl_800929D8)[lbl_801A6C80->slot[arg1].unk_6];
    } else {
        bend = ((s16 *)lbl_800929D8)[note->unk_8];
    }

    p = seq[0];
    if (note->unk_15 != 0 || p == 0) {
        fx = lbl_801A6C80->slot[arg1].unk_A;
        if (lbl_801A6C80->slot[arg1].unk_B != 0) {
            rev = 10.0 * (20.0 * fn_80088578(lbl_801A6C80->slot[arg1].unk_B / 127.0f));
        } else {
            rev = -904;
        }
        if (lbl_801A6C80->slot[arg1].unk_C != 0) {
            cho = 10.0 * (20.0 * fn_80088578(lbl_801A6C80->slot[arg1].unk_C / 127.0f));
        } else {
            cho = -904;
        }
    } else {
        fx = note->unk_16;
        if (note->unk_17 != 0) {
            rev = 10.0 * (20.0 * fn_80088578(note->unk_17 / 127.0f));
        } else {
            rev = -904;
        }
        if (note->unk_18 != 0) {
            cho = 10.0 * (20.0 * fn_80088578(note->unk_18 / 127.0f));
        } else {
            cho = -904;
        }
    }

    p = note->unk_7;
    if (p & 0x80) {
        p = lbl_801A6C80->slot[arg1].unk_9;
    }
    pan2 = lbl_80092A38[p];
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
        base = wave->offset + lbl_801A6C80->chan[lbl_801A6C80->curChan].base;
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
        env = note->unk_28 - fn_scale(__fabs(t), 1200, arg1);
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
        env2 = note->unk_2A - fn_scale(__fabs(t), 120, arg1);
        if (env2 < 0) {
            env2 = 0;
        }
    } else {
        env2 = note->unk_2A;
    }
    lbl_801A6C80->voice[voice].volEnv = env2 << 16;
    lbl_801A6C80->voice[voice].vol = vol;
    lbl_801A6C80->voice[voice].volDelta = (vol - env2) << 16;
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
            lbl_801A6C80->voice[voice2].step = lbl_801A6C80->voice[voice].step;
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
            start = wave->offset + lbl_801A6C80->chan[lbl_801A6C80->curChan].base + wave->offset2;
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
            lbl_801A6C80->voice[voice2].volEnv = env2 << 16;
            lbl_801A6C80->voice[voice2].vol = vol;
            lbl_801A6C80->voice[voice2].volDelta = (vol - env2) << 16;
            lbl_801A6C80->voice[voice2].volDelta = vol << 16;
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
        KillVoice((u8)voice);
    }
}

void fn_8005FBDC(u32 index) {
if (lbl_801A6C80->voice[index].state != 0xff) {
lbl_801A6C80->voice[index].active = 2;
if (lbl_801A6C80->voice[index].state == 3) {
lbl_801A6C80->voice[index].step = -960 / lbl_801A6C80->voice[index].unk_E;
if (lbl_801A6C80->voice[index].step == 0) {
lbl_801A6C80->voice[index].step = -1;
}
} else {
s16 value = lbl_801A6C80->voice[index].note->unk_12;
if (value != 0) {
lbl_801A6C80->voice[index].unk_B4 = value << 16;
} else {
lbl_801A6C80->voice[index].unk_B4 = -960 << 16;
}
lbl_801A6C80->voice[index].unk_B8 = -960 << 16;
lbl_801A6C80->voice[index].unk_E = 2;
}
{
SndVoice *entry = &((SndVoice *)lbl_801A6C80->voice)[index];
struct { u32 value; } count;
count.value = entry->prio;
if (count.value >= 2 && !(count.value & 0x80)) {
entry->prio = count.value - 1;
fn_80020CB0(lbl_801A6C80->voice[index].obj, lbl_801A6C80->voice[index].prio);
}
}
}
}

void fn_8005FCD8(u32 arg0) {
    if (lbl_801A6C80->voice[arg0].state != 0xFF) {
        fn_80023168(lbl_801A6C80->voice[arg0].obj,
                    0);
        fn_80026D70(lbl_801A6C80->voice[arg0].obj);
        fn_80020ABC(lbl_801A6C80->voice[arg0].obj);
        lbl_801A6C80->voice[arg0].obj = 0;
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

#pragma opt_dead_assignments off
void fn_8005FDE0(u32 arg0) {
    u32 channel;
    u32 value;
    s32 event;
    u32 v0;
    u32 command;
    v0 = (arg0 >> 24);
    command = arg0 & 0xff700000;
    event = (arg0 >> 16) & 0x7f;
    lbl_801A6C80->command = arg0;
    value = (arg0 >> 8) & 0xff;
    channel = arg0 & 0xf;
    if (v0 >= 0x80) {
        switch (v0 & 0xf0) {
        case 0x80:
            fn_80064A30(0x8000, 0x0f7f00ff);
            break;
        case 0x90:
            if (value != 0) {
                fn_800643F4(0x9000);
            } else {
                fn_80064A30(0x8000, 0x0f7f00ff);
            }
            break;
        case 0xa0:
            switch (v0 & 0xf) {
            case 0:
                switch (event) {
                case 0:
                    switch (value) {
                    case 1:
                        fn_8005CBF4(0xa0000100);
                        fn_800622B0();
                        break;
                    case 2:
                        fn_8005CBF4(0xa0000200);
                        break;
                    case 3:
                        fn_8005CBF4(0xa0000300);
                        break;
                    case 4:
                        fn_800622B0();
                        break;
                    case 8:
                        lbl_801A6C80->unk_462 = 1;
                        lbl_801A6C80->unk_463 = 1;
                        if (fn_80021928() != 0) fn_80021914(0);
                        if (fn_80025EEC() != 1) fn_80025EE4(1);
                        break;
                    case 9:
                        lbl_801A6C80->unk_462 = 0;
                        lbl_801A6C80->unk_463 = 0;
                        if (fn_80021928() != 0) fn_80021914(0);
                        if (fn_80025EEC() != 1) fn_80025EE4(1);
                        break;
                    case 0x11:
                        fn_8005CBF4(0xa0001100);
                        break;
                    case 0x12:
                        fn_8005CBF4(0xa0001200);
                        break;
                    case 0x13:
                        fn_8005CBF4(0xa0001300);
                        break;
                    case 0x18:
                    case 0x19:
                        if (!(arg0 & 0x40)) fn_8006953C(arg0);
                        break;
                    case 0x28:
                        lbl_801A6C80->unk_462 = 1;
                        lbl_801A6C80->unk_463 = 2;
                        if (fn_80021928() != 1) fn_80021914(1);
                        if (fn_80025EEC() != 2) fn_80025EE4(2);
                        break;
                    case 0x29:
                        lbl_801A6C80->unk_462 = 1;
                        lbl_801A6C80->unk_463 = 3;
                        if (fn_80021928() != 2) fn_80021914(2);
                        if (fn_80025EEC() != 3) fn_80025EE4(3);
                        break;
                    }
                    break;
                case 1:
                    lbl_801A6C80->masterVolume = value;
                    fn_80064A30(0xa001, 0);
                    break;
                case 2:
                    fn_800647B8(0xa002);
                    if (!(arg0 & 0x40)) fn_8006953C(arg0);
                    break;
                case 3:
                    fn_80069AE0();
                    break;
                case 4:
                case 5:
                case 0x10:
                case 0x11:
                    {
                        u32 id = event + 0xa000;
                        fn_80064230(id, 0xa004);
                        fn_800641A8(0xa004);
                        fn_800647B8((u16)id);
                    }
                    break;
                case 7:
                    fn_800641A8(0xa007);
                    fn_800647B8(0xa007);
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
                case 0x1c:
                    lbl_801A6C80->mix[(u8)channel].unk_9 = lbl_80092AB8[value];
                    fn_80064A30(0xa01c, 0xf);
                    break;
                case 0x24:
                    {
                        void (*callback)(u32, u32) = lbl_801A6C80->unk_5B18;
                        if (callback != 0) callback(channel, value);
                    }
                    break;
                case 0x28:
                case 0x29:
                    {
                        u8 i;
                        for (i = 0; i < 4; i++) {
                            u8 index = lbl_801A6C80->voiceMap[(u8)channel][(u8)value][i];
                            if (index != 0xff) lbl_801A6C80->slot[index].unk_2 = 0x29 - event;
                        }
                    }
                    break;
                case 0x30:
                    lbl_801A6C80->budget = value;
                    break;
                case 0x31:
                    lbl_801A6C80->unk_5A10 = lbl_801A6C80->unk_5A12;
                    fn_80064A30(0xa001, 0);
                    break;
                case 0x34:
                    fn_80064230(0xa034, 0xa034);
                    fn_800647B8(0xa034);
                    break;
                case 0x37:
                    fn_80065390();
                    break;
                case 0x38:
                    fn_80065528(1);
                    break;
                case 0x40:
                    fn_80064230(0xa040, 0xa034);
                    fn_800647B8(0xa040);
                    break;
                }
                break;
            case 4:
                switch (command) {
                case (s32)0xa4000000:
                    fn_8006331C(lbl_801A6C80->unk_474, value);
                    break;
                case (s32)0xa4700000:
                    lbl_801A6C80->unk_474 = value;
                    break;
                }
                break;
            case 5:
            case 6:
            case 7:
                fn_80062654(channel);
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
        case 0xb0:
            switch (event) {
            case 0:
                fn_800643F4(0xb000);
                break;
            case 1:
            case 2:
                {
                    u32 id = event + 0xb000;
                    fn_800643F4(id);
                    fn_80064A30(id, 0x0f00000f);
                }
                break;
            case 7:
                fn_800643F4(0xb007);
                fn_80064A30(0xb007, 0x0f00000f);
                break;
            case 10:
                fn_800643F4(0xb00a);
                fn_80064A30(0xb00a, 0x0f00000f);
                break;
            case 11:
                break;
            case 13:
                fn_800643F4(0xb00d);
                fn_80064A30(0xb00d, 0x0f00000f);
                break;
            case 14:
                fn_800643F4(0xb00e);
                fn_80064A30(0xb00d, 0x0f00000f);
                break;
            case 0x27:
                fn_800643F4(0xb007);
                break;
            case 0x2a:
                fn_800643F4(0xb00a);
                break;
            case 0x2b:
                break;
            case 0x2d:
                fn_800643F4(0xb00d);
                break;
            case 0x2e:
                fn_800643F4(0xb00e);
                break;
            case 0x40:
                fn_800643F4(0xb040);
                fn_80064A30(0xb040, 0x0f00000f);
                break;
            case 0x41:
                break;
            case 0x78:
                fn_80064A30(0xb078, 0xf);
                break;
            }
            break;
        case 0xc0:
            {
                typedef struct {
                    u32 pad0[2];
                    u8 *data;
                    u32 padC;
                } CommandSlot;
                u8 scan;
                u32 ch;
                u32 chOffset;
                u32 sub;
                u8 *data;
                u32 word;
                SndState *obj;
                u32 indexOffset;
                u8 i;
                u8 *table;
                s32 index;
                word = (obj = lbl_801A6C80)->command;
                ch = word & 0xf;
                chOffset = ch << 6;
                {
                    CommandSlot *slot = (CommandSlot *)&obj->chan[ch];
                    index = obj->voiceMap[0][0][chOffset + (sub = (word >> 22) & 0x3c)];
                    data = slot->data;
                }
                if (index != 0xff) {
                    indexOffset = (u8)index << 5;
                    if (!(obj->slot[(u8)index].unk_1 & 2)) {
                    scan = 0;
                    table = data + *(u32 *)(data + 0x1c);
                    for (data = table; scan <= (&obj->slot[0].unk_3[1])[indexOffset]; scan++) {
                        data += 2;
                    }
                    if ((*(u16 *)(table + *(u16 *)data) >> 8) >= ((word >> 16) & 0x7f)) {
                        fn_800643F4(0xc000);
                        for (i = 0; i < 4; i++) {
                            s32 n = (lbl_801A6C80->voiceMap[0][0] + i)[chOffset + sub];
                            if (n != 0xff) fn_80064E84(ch, n);
                        }
                    }
                    }
                }
            }
            break;
        case 0xe0:
            fn_800643F4(0xe000);
            fn_80064A30(0xe000, 0x0f00000f);
            break;
        }
    }
}
#pragma opt_dead_assignments reset

#pragma opt_dead_assignments reset
