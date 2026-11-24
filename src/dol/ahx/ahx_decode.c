#include "types.h"

typedef struct AhxBits AhxBits;

typedef struct AhxEntry {
    u32 unk_0;
    s32 unk_4;
    u8 pad_8[0x180 - 0x8];
} AhxEntry;

typedef struct AhxPair {
    u32 a;
    u32 b;
} AhxPair;

/* Decoder state: the frame header fields at 0x354, the stream info at 0x384 and the per-channel tables at 0x3B8. */
typedef struct AhxDecoder {
    f32 *samples;
    u8 pad_4[0x340];
    u8 used;
    u8 unk_345;
    s8 index;
    u8 pad_347;
    s32 unk_348;
    AhxBits *unk_34C;
    void *unk_350;
    s32 unk_354;
    s32 unk_358;
    s32 unk_35C;
    s32 unk_360;
    s32 unk_364;
    s32 unk_368;
    s32 unk_36C;
    s32 unk_370;
    s32 unk_374;
    s32 unk_378;
    s32 unk_37C;
    s32 unk_380;
    s32 unk_384;
    s32 unk_388;
    s32 unk_38C;
    s32 unk_390;
    s32 unk_394;
    s32 unk_398;
    AhxEntry *unk_39C;
    AhxPair unk_3A0;
    s32 unk_3A8;
    AhxPair unk_3AC;
    s32 unk_3B4;
    s32 unk_3B8[14][32];
} AhxDecoder;

typedef struct AhxStreamInfo {
    u8 pad_0[4];
    s32 unk_4;
    u8 pad_8[8];
    s32 unk_10;
    s32 unk_14;
    u32 unk_18;
} AhxStreamInfo;

typedef struct AhxHeader {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    s8 field_3;
    u32 field_4;
    u32 field_8;
    s16 field_C;
    s16 field_E;
    u8 pad_10[0x14];
    AhxPair field_24;
    u32 field_2C;
    AhxPair field_30;
    u32 field_38;
    u8 field_3C;
    u8 field_3D;
} AhxHeader;

extern f32 lbl_80130A48[];
extern u32 lbl_80130B98[];
extern s32 lbl_80130B68[3][4];
extern s32 lbl_80130B48[2][4];
extern s8 lbl_80130C00[];
extern s8 lbl_80130C60[];
extern s8 lbl_80130DE0[];
extern u32 lbl_80186FA8;
extern s32 lbl_80187110;
extern u32 lbl_80187114;
extern u32 lbl_80187118[6];
extern u8 lbl_80187130[512];
extern AhxDecoder *lbl_80187330[16];

extern void *memset(void *, int, u32);
extern s32 fn_8004FF68(AhxBits *);
extern s32 fn_800501F4(AhxBits *, s32);
extern s32 fn_80050670(s32, AhxEntry **);
extern int fn_80053A30(void);
extern void fn_80053A38(void *);
extern void *fn_80053A84(void *, u32);
extern void fn_80053BB4(void);
extern u32 fn_80053BFC(void);
extern void fn_80053DB4(void *, void *, s32, void *);

s32 fn_800519B0(u8 *, u32, u32 *, AhxHeader *);

/* WARNING: compiler-diff device, not original code. Only this function matches with size optimization. */
#pragma optimize_for_size on
void fn_80050698(AhxBits *arg0, AhxStreamInfo *arg1, void *arg2, void *arg3, s32 arg4, void *arg5) {
    void *v13, *v12, *v11;
    void *v9, *v8, *v7;
    u32 v6;
    s32 v5;
    s32 v10;
    s32 v20;
    s32 v1, v2, v3;
    u32 v0;
    void *v4;
    s32 v14;
    u32 v16;
    f32 v17, v18, v19;
    u32 v22;
    s32 v26;
    f32 v30, v31;
    void *v36, *v33;
    s32 v34, v35;
    s32 t0, t1, t2, t3, t4;
    s8 *tp;
    s32 b;
    v0 = arg1->unk_18;
    v1 = arg1->unk_4;
    v2 = arg1->unk_10;
    v3 = arg1->unk_14;
    lbl_80187114 = 0;
    v4 = (u8 *)arg3 + (arg4 << 7);
    lbl_80186FA8 = 0;
    v5 = 0;
    v6 = v0;
    v9 = arg2;
    v7 = arg5;
    v8 = v4;
    while (v5 < v2) {
        v13 = v9;
        v12 = v8;
        v11 = v7;
        v10 = 0;
        while (v10 < (v5 < v3 ? v1 : 1)) {
            v14 = *(s32 *)v13;
            if (v14 != 0) {
                v16 = v6 + v14 * 24;
                v17 = lbl_80130A48[*(u32 *)v12];
                v18 = *(f32 *)(v16 + 16) * v17;
                v19 = *(f32 *)(v16 + 20) * v17;
                if (*(s32 *)(v16 + 8) == 3) {
                    v20 = *(s32 *)(v16 + 4);
                    if (v20 <= 8) {
                        t0 = fn_800501F4(arg0, v20 + (v20 + v20));
                        v22 = lbl_80130B98[v20];
                        *(f32 *)((u8 *)v11 + 256) = v18 * (f32)(s32)(t0 & v22) + v19;
                        t0 >>= v20;
                        *(f32 *)((u8 *)v11 + 128) = v18 * (f32)(s32)(t0 & v22) + v19;
                        t0 >>= v20;
                        *(f32 *)v11 = (f32)t0 * v18 + v19;
                    } else {
                        t1 = fn_800501F4(arg0, v20);
                        *(f32 *)v11 = (f32)t1 * v18 + v19;
                        t2 = fn_800501F4(arg0, v20);
                        *(f32 *)((u8 *)v11 + 128) = (f32)t2 * v18 + v19;
                        t3 = fn_800501F4(arg0, v20);
                        *(f32 *)((u8 *)v11 + 256) = (f32)t3 * v18 + v19;
                    }
                } else {
                    v26 = *(s32 *)v16;
                    t4 = fn_800501F4(arg0, *(s32 *)(v16 + 4));
                    if (v26 == 3) {
                        tp = &lbl_80130C00[t4];
                        b = tp[0];
                        *(f32 *)v11 = (f32)b * v18 + v19;
                        b = tp[32];
                        *(f32 *)((u8 *)v11 + 128) = (f32)b * v18 + v19;
                        b = tp[64];
                        *(f32 *)((u8 *)v11 + 256) = (f32)b * v18 + v19;
                    } else if (v26 == 5) {
                        tp = &lbl_80130C60[t4];
                        b = tp[0];
                        *(f32 *)v11 = (f32)b * v18 + v19;
                        b = tp[128];
                        *(f32 *)((u8 *)v11 + 128) = (f32)b * v18 + v19;
                        b = tp[256];
                        *(f32 *)((u8 *)v11 + 256) = (f32)b * v18 + v19;
                    } else if (v26 == 9) {
                        tp = &lbl_80130DE0[t4];
                        b = tp[0];
                        *(f32 *)v11 = (f32)b * v18 + v19;
                        b = tp[1024];
                        *(f32 *)((u8 *)v11 + 128) = (f32)b * v18 + v19;
                        b = tp[2048];
                        *(f32 *)((u8 *)v11 + 256) = (f32)b * v18 + v19;
                    } else {
                        t1 = t4 % v26;
                        *(f32 *)v11 = (f32)t1 * v18 + v19;
                        t4 /= v26;
                        t1 = t4 % v26;
                        *(f32 *)((u8 *)v11 + 128) = (f32)t1 * v18 + v19;
                        t4 /= v26;
                        t1 = t4 % v26;
                        *(f32 *)((u8 *)v11 + 256) = (f32)t1 * v18 + v19;
                    }
                }
            } else {
                v30 = 0.0f;
                *(f32 *)v11 = v30;
                *(f32 *)((u8 *)v11 + 128) = v30;
                *(f32 *)((u8 *)v11 + 256) = v30;
            }
            if (v1 == 2 && v5 >= v3) {
                *(f32 *)((u8 *)v7 + 384) = *(f32 *)v7;
                *(f32 *)((u8 *)v7 + 512) = *(f32 *)((u8 *)v7 + 128);
                *(f32 *)((u8 *)v7 + 640) = *(f32 *)((u8 *)v7 + 256);
            }
            v13 = (u8 *)v13 + 128;
            v12 = (u8 *)v12 + 384;
            v11 = (u8 *)v11 + 384;
            v10++;
        }
        v9 = (u8 *)v9 + 4;
        v8 = (u8 *)v8 + 4;
        v7 = (u8 *)v7 + 4;
        v6 += 384;
        v5++;
    }
    v31 = 0.0f;
    v33 = (u8 *)arg5 + v2 * 4;
    for (v34 = v2; v34 < 32; v34++) {
        v36 = v33;
        for (v35 = 0; v35 < v1; v35++) {
            *(f32 *)v36 = v31;
            *(f32 *)((u8 *)v36 + 128) = v31;
            *(f32 *)((u8 *)v36 + 256) = v31;
            v36 = (u8 *)v36 + 384;
        }
        v33 = (u8 *)v33 + 4;
    }
}
#pragma optimize_for_size reset

void fn_80050BD4(AhxBits *ctx, AhxStreamInfo *info,
                 u32 present[][32], s32 kind[][32], s32 out[][3][32]) {
    s32 w;
    s32 h;
    s32 x;
    s32 y;

    w = info->unk_10;
    h = info->unk_4;
    for (x = 0; x < w; x++) {
        for (y = 0; y < h; y++) {
            if (present[y][x] != 0) {
                kind[y][x] = fn_800501F4(ctx, 2);
            }
        }
    }
    for (x = w; x < 32; x++) {
        for (y = 0; y < h; y++) {
            kind[y][x] = 0;
        }
    }
    for (x = 0; x < w; x++) {
        for (y = 0; y < h; y++) {
            if (present[y][x] != 0) {
                switch (kind[y][x]) {
                case 0:
                    out[y][0][x] = fn_800501F4(ctx, 6);
                    out[y][1][x] = fn_800501F4(ctx, 6);
                    out[y][2][x] = fn_800501F4(ctx, 6);
                    break;
                case 1:
                    out[y][0][x] = out[y][1][x] = fn_800501F4(ctx, 6);
                    out[y][2][x] = fn_800501F4(ctx, 6);
                    break;
                case 3:
                    out[y][0][x] = fn_800501F4(ctx, 6);
                    out[y][1][x] = out[y][2][x] = fn_800501F4(ctx, 6);
                    break;
                case 2:
                    out[y][0][x] = out[y][1][x] = out[y][2][x] = fn_800501F4(ctx, 6);
                    break;
                }
            } else {
                out[y][0][x] = out[y][1][x] = out[y][2][x] = 63;
            }
        }
    }
    for (x = w; x < 32; x++) {
        for (y = 0; y < h; y++) {
            out[y][0][x] = out[y][1][x] = out[y][2][x] = 63;
        }
    }
}


int fn_80050F64(void) {
    return 96;
}

int fn_80050F6C(void) {
    return 16;
}

s32 fn_80050F74(AhxDecoder *decoder) {
    if ((s8)decoder->unk_345 == 0) {
        return 0;
    }
    return decoder->unk_388;
}

int fn_80050F90(AhxDecoder *obj, char *left, char *right) {
    int channels = obj->unk_388;
    int i;

    if (obj->unk_348 == 12) {
        return 0;
    }

    lbl_80187118[0] = fn_80053A30();
    fn_80050698(obj->unk_34C, (AhxStreamInfo *)&obj->unk_384, obj->unk_3B8, obj->unk_3B8[4], obj->unk_348 >> 2, obj->samples);

    lbl_80187118[3] = fn_80053A30();
    for (i = 0; i < 3; i++) {
        fn_80053DB4(obj->unk_350, (char *)obj->samples + i * 0x80, 0, left + i * 0x40);
    }

    lbl_80187118[4] = fn_80053A30();
    if (channels >= 2) {
        for (i = 0; i < 3; i++) {
            fn_80053DB4(obj->unk_350, (char *)obj->samples + 0x180 + i * 0x80, 1, right + i * 0x40);
        }
    }

    lbl_80187118[5] = fn_80053A30();
    obj->unk_348++;
    return 0x60;
}

u32 fn_800510C4(AhxDecoder *decoder) {
    return (u32)__cntlzw(12 - decoder->unk_348) >> 5;
}

/* the column pointers step through obj itself: unk_3B8[j][i] is read as col->unk_3B8[j][0] */
#define COL_STEP(p, bytes) ((AhxDecoder *)((u8 *)(p) + (bytes)))

s32 fn_800510D8(AhxDecoder *obj) {
    s32 count;
    s32 total;
    struct { AhxBits *value; } dec;
    struct {
        AhxEntry *entries;
        s32 j;
        s32 i;
        AhxBits *src;
        AhxDecoder *row;
        AhxDecoder *col;
        AhxEntry *ent;
        s32 n;
    } loops;
    AhxEntry *ent2;
    AhxDecoder *col2;
    s32 tmp_fn_800501F4;
    AhxDecoder *col3;
    s32 v;

    if (obj->unk_34C == 0) {
        return 0;
    }
    if (fn_8004FF68(obj->unk_34C) != 1) {
        return 1;
    }
    dec.value = obj->unk_34C;
    tmp_fn_800501F4 = fn_800501F4(dec.value, 1);
    obj->unk_354 = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec.value, 2);
    obj->unk_358 = 4 - tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec.value, 1);
    obj->unk_35C = tmp_fn_800501F4 == 0;
    tmp_fn_800501F4 = fn_800501F4(dec.value, 4);
    obj->unk_360 = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec.value, 2);
    obj->unk_364 = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec.value, 1);
    obj->unk_368 = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec.value, 1);
    obj->unk_36C = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec.value, 2);
    obj->unk_370 = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec.value, 2);
    obj->unk_374 = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec.value, 1);
    obj->unk_378 = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec.value, 1);
    obj->unk_37C = tmp_fn_800501F4;
    tmp_fn_800501F4 = fn_800501F4(dec.value, 2);
    obj->unk_380 = tmp_fn_800501F4;

    if (obj->unk_384 == 0) {
        if (obj->unk_370 == 3) {
            obj->unk_388 = 1;
        } else {
            obj->unk_388 = 2;
        }
    }
    if (obj->unk_358 == 2) {
        obj->unk_394 = fn_80050670(0, &obj->unk_39C);
    } else {
        obj->unk_394 = 32;
    }
    if (obj->unk_370 == 1) {
        obj->unk_398 = lbl_80130B68[obj->unk_358][obj->unk_374];
    } else {
        obj->unk_398 = obj->unk_394;
    }
    if (obj->unk_384 == 0) {
        obj->unk_38C = lbl_80130B48[obj->unk_354][obj->unk_364];
    }

    loops.entries = obj->unk_39C;
    loops.j = 0;
    loops.i = 0;
    loops.src = obj->unk_34C;
    loops.row = obj;
    loops.col = obj;
    loops.ent = loops.entries;
    total = obj->unk_394;
    count = obj->unk_388;
    loops.n = obj->unk_398;
    for (; loops.i < loops.n; loops.i++) {
        loops.row = loops.col;
        for (loops.j = 0; loops.j < count; loops.j++) {
            tmp_fn_800501F4 = fn_800501F4(loops.src, loops.ent->unk_4);
            loops.row->unk_3B8[0][0] = tmp_fn_800501F4;
            loops.row = COL_STEP(loops.row, 0x80);
        }
        loops.col = COL_STEP(loops.col, 4);
        loops.ent++;
    }
    ent2 = loops.entries + loops.n;
    col2 = COL_STEP(obj, loops.n * 4);
    while (loops.n < total) {
        tmp_fn_800501F4 = fn_800501F4(loops.src, ent2->unk_4);
        v = tmp_fn_800501F4;
        col2->unk_3B8[1][0] = v;
        col2->unk_3B8[0][0] = v;
        col2 = COL_STEP(col2, 4);
        ent2++;
        loops.n++;
    }
    col3 = COL_STEP(obj, total * 4);
    while (total < 32) {
        for (loops.n = 0; loops.n < count; loops.n++) {
            col3->unk_3B8[loops.n][0] = 0;
        }
        col3 = COL_STEP(col3, 4);
        total++;
    }
    fn_80050BD4(obj->unk_34C, (AhxStreamInfo *)&obj->unk_384, (u32 (*)[32])obj->unk_3B8[0], (s32 (*)[32])obj->unk_3B8[2], (s32 (*)[3][32])obj->unk_3B8[4]);
    obj->unk_345 = 1;
    obj->unk_348 = 0;
    return 0;
}

struct AhxHeaderLocals {
    u32 field_8;
    AhxHeader buf;
};

/* WARNING: compiler-diff device, not original code. Retail reloads the reader and byte cursor without these. */
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_80051448(AhxDecoder *arg0) {
    u8 *p;
    u8 *end;
    AhxBits *v0;
    struct AhxHeaderLocals locals;
    u32 lab_t2;
    AhxBits *t;

    t = arg0->unk_34C;
    v0 = arg0->unk_34C;
    if (t != 0) {
        lab_t2 = 0x40;
        memset(&locals.buf, 0, lab_t2);
        locals.field_8 = 0;
        p = lbl_80187130;
        end = p + 4;
        while (p != end) {
            *p = fn_800501F4(v0, 8);
            p++;
        }
        fn_800519B0(lbl_80187130, 4, &locals.field_8, 0);
        end = end + locals.field_8;
        while (p != end) {
            *p = fn_800501F4(v0, 8);
            p++;
        }
        if (fn_800519B0(lbl_80187130, 0x200, &locals.field_8, &locals.buf) >= 0) {
            arg0->unk_388 = locals.buf.field_3;
            arg0->unk_38C = locals.buf.field_4;
            arg0->unk_390 = locals.buf.field_8;
            arg0->unk_3A0 = locals.buf.field_24;
            arg0->unk_3A8 = locals.buf.field_2C;
            arg0->unk_3AC = locals.buf.field_30;
            arg0->unk_3B4 = locals.buf.field_38;
            arg0->unk_384 = 1;
        }
    }
}
#pragma opt_propagation reset
#pragma opt_common_subs reset

void fn_80051594(AhxDecoder *decoder, AhxBits *bits) {
    void *synth = decoder->unk_350;
    void *v;

    memset(&decoder->unk_354, 0, 48);
    memset(&decoder->unk_384, 0, 52);
    memset(decoder->unk_3B8[0], 0, 256);
    memset(decoder->unk_3B8[2], 0, 256);
    memset(decoder->unk_3B8[4], 0, 768);
    memset(decoder->samples, 0, 768);
    memset(decoder->unk_3B8[10], 0, 768);
    decoder->unk_345 = 0;
    decoder->unk_348 = 0;
    v = decoder->unk_350;
    if (v != 0) {
        decoder->unk_350 = 0;
        fn_80053A38(v);
        decoder->unk_350 = fn_80053A84(synth, 0x2014);
    }
    decoder->unk_34C = bits;
}

void fn_80051678(AhxDecoder *decoder) {
    void *synth = decoder->unk_350;
    void *v;

    memset(&decoder->unk_354, 0, 48);
    memset(&decoder->unk_384, 0, 52);
    memset(decoder->unk_3B8[0], 0, 256);
    memset(decoder->unk_3B8[2], 0, 256);
    memset(decoder->unk_3B8[4], 0, 768);
    memset(decoder->samples, 0, 768);
    memset(decoder->unk_3B8[10], 0, 768);
    decoder->unk_345 = 0;
    decoder->unk_348 = 0;
    v = decoder->unk_350;
    if (v != 0) {
        decoder->unk_350 = 0;
        fn_80053A38(v);
        decoder->unk_350 = fn_80053A84(synth, 0x2014);
    }
}

void fn_8005174C(AhxDecoder *arg0) {
    AhxDecoder *obj;
    s32 index;
    void *synth;

    obj = arg0;
    synth = obj->unk_350;
    index = obj->index;
    if (synth != 0) {
        obj->unk_350 = 0;
        fn_80053A38(synth);
    }
    memset(obj, 0, 3000);
    lbl_80187330[index] = 0;
}

AhxDecoder *fn_800517C0(AhxDecoder *obj, u32 size) {
    AhxDecoder *entry;
    int i;
    void *resource;

    for (i = 0; i < 16; i++) {
        if (lbl_80187330[i] == 0) {
            break;
        }
    }
    if (i == 16) {
        return 0;
    }

    memset(obj, 0, size);
    lbl_80187330[i] = obj;
    entry = lbl_80187330[i];
    entry->index = i;
    resource = fn_80053A84((u8 *)entry + 0xbb8, 0x2014);
    entry->unk_350 = resource;
    if (resource == 0) {
        return 0;
    }

    entry->samples = (f32 *)(((u32)entry + 0x23) & ~31);
    if ((u32)entry->samples & 0x1f) {
        for (;;) {
        }
    }
    entry->used = 1;
    return entry;
}

void fn_8005190C(void) {
    s32 *counter;
    u32 count;

    counter = &lbl_80187110;
    count = *counter - 1;
    *counter = count;
    if (count == 0) {
        memset(lbl_80187330, 0, 64);
        fn_80053BB4();
    }
}

u32 fn_80051958(void) {
    u32 count;

    if (lbl_80187110 == 0) {
        fn_80053BFC();
        memset(lbl_80187330, 0, 64);
    }
    count = lbl_80187110;
    lbl_80187110 = count + 1;
    return count;
}

#define RD_U16(p) ((u16)(((u32)(p)[0] << 8) | (p)[1]))
#define RD_U32(p) (((u32)(p)[0] << 24) | ((u32)(p)[1] << 16) | ((u32)(p)[2] << 8) | (u32)(p)[3])

s32 fn_800519B0(u8 *arg0, u32 arg1, u32 *arg2, AhxHeader *arg3) {
    u32 value;
    s32 size;
    u8 *src;
    u8 *dst;
    s32 i;

    if (arg2 != 0) {
        *arg2 = 0;
    }
    if ((s32)arg1 < 4) {
        return -1;
    }
    value = RD_U16(arg0);
    if (value != 0x8000) {
        return -4;
    }
    size = (arg0[2] << 8) | arg0[3];
    if (arg2 != 0) {
        *arg2 = size;
    }
    if (arg3 == 0) {
        return 0;
    }
    if ((s32)arg1 < size + 4) {
        return -2;
    }
    size -= 6;
    if (size < 16) {
        return -2;
    }
    arg3->field_0 = arg0[4];
    size -= 16;
    arg3->field_1 = arg0[5];
    arg3->field_2 = arg0[6];
    arg3->field_3 = arg0[7];
    arg3->field_4 = RD_U32(arg0 + 8);
    arg3->field_8 = RD_U32(arg0 + 12);
    arg3->field_C = RD_U16(arg0 + 16);
    arg3->field_3C = arg0[18];
    arg3->field_3D = arg0[19];
    if (size < 4) {
        return -2;
    }
    arg3->field_E = RD_U16(arg0 + 22);
    src = arg0 + 0x18;
    if (size < arg3->field_E * 20) {
        return -3;
    }
    dst = (u8 *)arg3;
    for (i = 0; i < arg3->field_E; i++) {
        *(u16 *)(dst + 0x10) = RD_U16(src + 0);
        *(u16 *)(dst + 0x12) = RD_U16(src + 2);
        *(u32 *)(dst + 0x14) = RD_U32(src + 4);
        *(u32 *)(dst + 0x18) = RD_U32(src + 8);
        *(u32 *)(dst + 0x1C) = RD_U32(src + 12);
        *(u32 *)(dst + 0x20) = RD_U32(src + 16);
        dst += 0x14;
    }
    size -= arg3->field_E * 20;
    i = 0;
    dst = (u8 *)arg3;
    while (i < (s8)arg3->field_3) {
        if (size < 12) {
            return 0;
        }
        *(u16 *)(dst + 0x24) = RD_U16(src);
        if (*(s16 *)(dst + 0x24) > 0) {
            *(u16 *)(dst + 0x26) = RD_U16(src + 2);
        }
        dst[0x28] = src[4];
        if ((s8)dst[0x28] > 0) {
            dst[0x29] = src[5];
        }
        dst[0x2A] = src[6];
        if ((s8)dst[0x2A] > 0) {
            dst[0x2B] = src[7];
        }
        dst[0x2C] = src[8];
        if ((s8)dst[0x2C] > 0) {
            dst[0x2D] = src[9];
        }
        dst[0x2E] = src[10];
        if ((s8)dst[0x2E] > 0) {
            dst[0x2F] = src[11];
        }
        src += 12;
        size -= 12;
        dst += 12;
        i++;
    }
    return 0;
}
