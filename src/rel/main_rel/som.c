#include "types.h"
extern int sprintf(char *, const char *, ...);
#include "rel/main_rel/globals.h"
#include "rel/main_rel/som.h"

extern u32 lbl_1_bss_3BBC;
extern void fn_1_465D0(char *, int);

extern int fn_1_458A0(void *, void *, u32, u32);
extern void OSPanic(const void *, int, const void *, ...);

/* fzgx:begin fn_1_1304C */
typedef void (*SomCallback)(u32);

typedef struct SomSource {
    u8 pad_0[0x80];
    u8 *dst;
    SomCallback callback;
} SomSource;

extern int fn_1_45730(void *source, void *file);
extern int fn_1_45850(void *file);
extern void *fn_1_45D0(void *heap, u32 size, void *file, u32 line);
extern void fn_1_46B4(void *heap, void *ptr, void *file, u32 line);
extern u8 fn_1_1361C(void *file, void *buffers);
extern void fn_80008BA8(void *dst, void *src, u32 size);
extern void *volatile lbl_801A6410[1];  /* fzgx-allow: S2 volatile keeps the verified access order */
extern volatile u32 lbl_1_data_5184;  /* fzgx-allow: S2 volatile keeps the verified access order */
extern u8 lbl_1_bss_1800[];

/* LZSS decoder: 4 KB ring buffer, 12-bit offsets, 4-bit lengths (threshold 2). */
u32 *fn_1_1304C(SomSource *source, void *image) {
    u32 size;
    void *buffers[2];
    u32 header[2];
    u8 file[0x5c];
    u8 window[0x1000 + 0x12 - 1];
    int offset;
    int r;
    u32 pos;
    u8 *out;
    u32 flags;
    u8 *dst;
    u32 end;
    SomCallback callback;
    int len;
    int k;
    long i;
    u8 c;

    dst = source->dst;
    callback = source->callback;
    *(u32 *)(lbl_1_bss_1800 + 0x2328) = 0;
    *(u32 *)(lbl_1_bss_1800 + 0x232c) = 0;
    lbl_1_bss_1800[0x23b8] = 0;
    if (image != 0) {
        fn_80008BA8(file, image, 0x5c);
    } else if (fn_1_45730(source, file) == 0) {
        return 0;
    }

    buffers[0] = fn_1_45D0(lbl_801A6410[0], lbl_1_data_5184, &lbl_1_data_5188, 0x243);
    buffers[1] = fn_1_45D0(lbl_801A6410[0], lbl_1_data_5184, &lbl_1_data_5188, 0x244);

    header[0] = fn_1_1361C(file, buffers) << 24;
    header[0] |= fn_1_1361C(file, buffers) << 16;
    header[0] |= fn_1_1361C(file, buffers) << 8;
    header[0] |= fn_1_1361C(file, buffers);
    header[1] = fn_1_1361C(file, buffers) << 24;
    header[1] |= fn_1_1361C(file, buffers) << 16;
    header[1] |= fn_1_1361C(file, buffers) << 8;
    header[1] |= fn_1_1361C(file, buffers);

    end = __lwbrx(header, 0) + 8;
    size = __lwbrx(header, 4);
    if (end == 0 || size == 0) {
        return 0;
    }

    out = dst;
    pos = 8;
    for (i = 0; i < 0xfee; i++) {
        window[i] = 0;
    }
    r = 0xfee;
    flags = 0;
    for (;;) {
        flags >>= 1;
        if ((flags & 0x100) == 0) {
            if (pos >= end) {
                break;
            }
            flags = fn_1_1361C(file, buffers) | 0xff00;
            pos++;
        }
        if (flags & 1) {
            if (pos >= end) {
                break;
            }
            c = fn_1_1361C(file, buffers);
            *out++ = c;
            pos++;
            window[r] = c;
            r++;
            r &= 0xfff;
        } else {
            if (pos >= end) {
                break;
            }
            offset = fn_1_1361C(file, buffers);
            if (pos + 1 >= end) {
                break;
            }
            len = fn_1_1361C(file, buffers);
            pos += 2;
            offset |= (len & 0xf0) << 4;
            len = (len & 0xf) + 2;
            for (k = 0; k <= len; k++) {
                c = window[(offset + k) & 0xfff];
                *out++ = c;
                window[r] = c;
                r++;
                r &= 0xfff;
            }
        }
    }

    fn_1_45850(file);
    fn_1_46B4(lbl_801A6410[0], buffers[1], &lbl_1_data_5188, 0x277);
    fn_1_46B4(lbl_801A6410[0], buffers[0], &lbl_1_data_5188, 0x278);
    if (callback != 0) {
        callback(size);
    }
    return &size;
}
/* fzgx:end fn_1_1304C */

/* fzgx:begin fn_1_1350C */
#define lbl_1_data_5184 _lc_lbl_1_data_5184
#include "rel/main_rel/live_camera.h"
#undef lbl_1_data_5184

extern u32 fn_80008E30(u32);
extern u8 lbl_1_bss_17B4[12];
extern void fn_80083DB0(Obj_1_bss_3B30 *, void *);
extern u8 lbl_1_bss_1810[8984];
extern void fn_8000659C(void);
extern u32 OSIsThreadTerminated(u8 *);

extern void fn_1_6DD0(void *);
extern u32 *fn_1_1289C(u32 *);
extern s32 fn_1_4C10(void);
extern s32 fn_1_40BB4(void);
extern s32 fn_1_F2F34(void);
extern u32 fn_1_F45A4(void);
extern u32 fn_1_F4594(void);
extern f32 lbl_1_rodata_4E0[5];
extern f32 lbl_1_bss_1160[403];
extern void fn_1_5370(s32, s16);
extern f32 lbl_1_rodata_4F4[19];
extern const f64 lbl_1_rodata_548[2];
extern u32 lbl_801A63C0;
extern void fn_1_8636C(s16, void *);
extern void fn_1_862A8(s16, void *);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);
extern s32 lbl_8006D24C(f32, f32);

extern s32 fn_1_45B2C(void *arg0);

u8 fn_1_1350C(void *arg0, u8 *arg1) {
    s32 size;
    u8 result;
    if (lbl_1_bss_3B28 == 0) {
        size = lbl_1_data_5180;
        /* volatile: the shared streaming state is read in program order, not CSEd or hoisted */
        if (*(volatile u32 *)&lbl_1_bss_3B2C + *(volatile u32 *)&lbl_1_data_5180 > fn_1_45B2C(arg0)) {
            size = (fn_1_45B2C(arg0) - lbl_1_bss_3B2C + 0x1F) & ~0x1F;
        }
        if (size > 0) {
            fn_1_458A0(arg0, arg1, size, lbl_1_bss_3B2C);
        }
        /* volatile: the two global words are accumulated in the order retail loads them */
        *(volatile u32 *)&lbl_1_bss_3B2C += *(volatile u32 *)&lbl_1_data_5180;
    }
    /* volatile: the index counter is a live shared object, read and advanced as written */
    result = arg1[*(volatile u32 *)&lbl_1_bss_3B28];
    /* volatile: the index counter is a live shared object, read and advanced as written */
    (lbl_1_bss_3B28)++;
    /* volatile: the index counter is a live shared object, read and advanced as written */
    if (*(volatile u32 *)&lbl_1_bss_3B28 >= *(volatile u32 *)&lbl_1_data_5180) {
        lbl_1_bss_3B28 = 0;
    }
    return result;
}
/* fzgx:end fn_1_1350C */

/* fzgx:begin fn_1_1361C */
extern void fn_1_45964(void *a, void *buf, int n, u32 off, void *cb);
extern void fn_1_1383C(void);
extern void DCInvalidateRange(void *addr, u32 len);
extern void fn_8000659C(void);
extern void fn_1_3308(void);
extern void fn_1_D3214(void);
extern void VIWaitForRetrace(void);

extern volatile u32 lbl_1_data_5184;  // volatile: retail reloads it on every access

typedef struct {
    u8 _0[0x2328];
    volatile u32 w2328;   // 0x2328  read cursor (active buffer)
    volatile u32 w232c;   // 0x232c  write offset
    u8 _pad1[0x23b8 - 0x232c - 4];
    volatile u8 b23b8;    // 0x23b8  buffer toggle
    u8 _pad2[3];
    volatile s32 w23bc;   // 0x23bc  DMA-ready flag
} SomRing;


u8 fn_1_1361C(void *a, void *b_ptr) {
    u32 *b = (u32 *)b_ptr;
    SomRing *s = (SomRing *)lbl_1_bss_1800;
    int n;

    if (s->w232c == 0) {
        n = lbl_1_data_5184;
        s->b23b8 = 0;
        if (s->w232c + lbl_1_data_5184 > fn_1_45B2C(a)) {
            n = ((fn_1_45B2C(a) - s->w232c) + 0x1f) & ~0x1f;
        }
        if (n > 0) {
            DCInvalidateRange((void *)b[s->b23b8], lbl_1_data_5184);
            s->w23bc = 0;
            fn_1_45964(a, (void *)b[s->b23b8], n, s->w232c, fn_1_1383C);
        }
        s->w232c += lbl_1_data_5184;
        s->b23b8 = 1 - s->b23b8;
    }

    if (s->w2328 == 0) {
        n = lbl_1_data_5184;
        if (s->w232c + lbl_1_data_5184 > fn_1_45B2C(a)) {
            n = ((fn_1_45B2C(a) - s->w232c) + 0x1f) & ~0x1f;
        }
        while (s->w23bc == 0) {
            fn_8000659C();
            fn_1_3308();
            fn_1_D3214();
            VIWaitForRetrace();
        }
        if (n > 0) {
            DCInvalidateRange((void *)b[s->b23b8], lbl_1_data_5184);
            s->w23bc = 0;
            fn_1_45964(a, (void *)b[s->b23b8], n, s->w232c, fn_1_1383C);
        }
        s->w232c += lbl_1_data_5184;
        s->b23b8 = 1 - s->b23b8;
    }

    {
        u8 *buf = (u8 *)b[s->b23b8];
        u8 ret = buf[s->w2328];
        s->w2328 = s->w2328 + 1;
        if (s->w2328 >= lbl_1_data_5184) s->w2328 = 0;
        return ret;
    }
}
/* fzgx:end fn_1_1361C */

/* fzgx:begin fn_1_1383C */
void fn_1_1383C(void) {
    lbl_1_bss_3BBC = 1;
}
/* fzgx:end fn_1_1383C */
