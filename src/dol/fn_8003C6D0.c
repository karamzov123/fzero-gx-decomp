#include "types.h"
#include "gqr.h"

typedef struct ImgComponent {
    u32 width;          /* 0x00 */
    u32 height;         /* 0x04 */
    u8 *base;           /* 0x08 */
    u8 *dest;           /* 0x0C */
    u32 unk_10;         /* 0x10 */
    u32 unk_14;         /* 0x14 */
    u8 pad_18[0x11];
    u8 hshift;          /* 0x29 */
    u8 vshift;          /* 0x2A */
    u8 pad_2B[0x5];
} ImgComponent;

typedef struct ImgDecoder {
    u8 pad_0[0x400];
    u32 unk_400;
    u32 unk_404;
    u16 unk_408;
    u16 unk_40A;
    u16 unk_40C;
    u16 unk_40E;
    u8 pad_410[0x4];
    u32 unk_414;
    u8 pad_418[0x2];
    u8 unk_41A;
    u8 unk_41B;
    u8 unk_41C;
    u8 unk_41D;
    u8 pad_41E[0x6C8 - 0x41E];
    ImgComponent comp[3];
    u8 pad_758[0x7A0 - 0x758];
    u16 unk_7A0;
    u8 pad_7A2[0x4];
    u16 unk_7A6;
    u16 unk_7A8;
    u16 unk_7AA;
    u16 unk_7AC;
    u8 pad_7AE[0xA];
    u32 gqr2;
    u32 gqr5;
    u32 gqr6;
    u32 gqr7;
} ImgDecoder;

typedef struct ImgHandle {
    u8 pad_0[0x4];
    ImgDecoder *dec;
} ImgHandle;

typedef struct ProfRec {
    u32 t0_start;
    u32 t0_end;
    u32 t2_start;
    u32 t2_end;
    u32 t1_start;
    u32 t1_end;
    u32 t3_start;
    u32 t3_end;
    u32 t0_total;
    u32 t2_total;
    u32 t1_total;
    u32 t3_total;
    u32 t0_max;
    u32 count;
} ProfRec;

extern ProfRec lbl_801789C0[];
extern void PPCMtmmcr0(u32 value);
extern void PPCMtmmcr1(u32 value);
extern u32 fn_8000A020(void);
extern u32 fn_8000A030(void);
extern u32 fn_8000A040(void);
extern u32 fn_8000A050(void);
extern void DCStoreRange(void *, u32);
extern void fn_8003AB08(ImgDecoder *dec);
extern void fn_8003BB30(u8 *out, u8 *y, u8 *u, u8 *v, u32 width);
extern void fn_8003B9AC(u8 *out, u8 *y, u8 *u, u8 *v, u32 width);

void fn_8003C6D0(ImgHandle *handle, u8 *dst, u32 width, u32 height) {
    u32 stride;
    u8 vsub;
    u8 hsub;
    u32 h;
    s32 hraw;
    s32 vraw;
    u32 i;
    u32 ystride;
    u32 cstride;
    u32 w;
    u8 *out;
    u8 *y;
    u8 *u;
    u8 *v;
    ImgDecoder *dec;

    out = dst - 2;
    dec = handle->dec;
    dec->unk_400 = dec->unk_404;
    dec->unk_414 = 0x21;
    dec->unk_7AA = 0;
    dec->unk_7AC = 0;
    dec->unk_7A6 = 0;
    dec->unk_41D = 0;
    dec->unk_40C = 0;
    dec->unk_40E = 0;
    w = (dec->unk_408 > width) ? width : dec->unk_408;
    h = dec->unk_40A;
    if (h > height) {
        h = height;
    }
    hraw = dec->unk_41A - dec->comp[0].hshift;
    vraw = dec->unk_41B - dec->comp[0].vshift;
    ystride = dec->comp[0].width;
    cstride = dec->comp[1].width;
    {
        u32 j;
        for (j = 0; j < dec->unk_41C; j++) {
            dec->comp[j].dest = dec->comp[j].base;
        }
    }
    dec->unk_7AC = 0;
    PPCMtmmcr1(0);
    PPCMtmmcr0(0);
    lbl_801789C0[5].t0_start = fn_8000A050();
    lbl_801789C0[5].t1_start = fn_8000A040();
    lbl_801789C0[5].t2_start = fn_8000A030();
    lbl_801789C0[5].t3_start = fn_8000A020();
    PPCMtmmcr0(0x8B);
    PPCMtmmcr1(0x78400000);
    dec->gqr2 = gqr_get2();
    gqr_set2_decode();
    dec->gqr5 = gqr_get5();
    gqr_set5_decode();
    dec->gqr6 = gqr_get6();
    gqr_set6_decode();
    dec->gqr7 = gqr_get7();
    gqr_set7_decode();
    stride = width * 2;
    vsub = vraw;
    hsub = hraw;
    while (dec->unk_7AC < h) {
        dec->unk_7AA = 0;
        fn_8003AB08(dec);
        dec->unk_7AC += dec->unk_7A8;
        y = dec->comp[0].dest - 2;
        u = dec->comp[1].dest - 2;
        v = dec->comp[2].dest - 2;
        if (hsub == 0) {
            for (i = 0; i < dec->unk_7A8; i++) {
                fn_8003BB30(out, y, u, v, w);
                out += stride;
                y += ystride;
                u += cstride;
                v += cstride;
            }
        } else if (vsub == 0) {
            for (i = 0; i < dec->unk_7A8; i++) {
                fn_8003B9AC(out, y, u, v, w);
                out += stride;
                y += ystride;
                u += cstride;
                v += cstride;
            }
        } else {
            for (i = 0; i < dec->unk_7A8; i += 2) {
                fn_8003B9AC(out, y, u, v, w);
                out += stride;
                y += ystride;
                fn_8003B9AC(out, y, u, v, w);
                out += stride;
                y += ystride;
                u += cstride;
                v += cstride;
            }
        }
    }
    PPCMtmmcr1(0);
    PPCMtmmcr0(0);
    lbl_801789C0[5].count++;
    lbl_801789C0[5].t0_end = fn_8000A050();
    lbl_801789C0[5].t1_end = fn_8000A040();
    lbl_801789C0[5].t2_end = fn_8000A030();
    lbl_801789C0[5].t3_end = fn_8000A020();
    {
        u32 d = lbl_801789C0[5].t0_end - lbl_801789C0[5].t0_start;
        u32 max = lbl_801789C0[5].t0_max;
        if (d > max) {
            max = d;
        }
        lbl_801789C0[5].t0_max = max;
    }
    lbl_801789C0[5].t0_total += lbl_801789C0[5].t0_end - lbl_801789C0[5].t0_start;
    lbl_801789C0[5].t1_total += lbl_801789C0[5].t1_end - lbl_801789C0[5].t1_start;
    lbl_801789C0[5].t2_total += lbl_801789C0[5].t2_end - lbl_801789C0[5].t2_start;
    lbl_801789C0[5].t3_total += lbl_801789C0[5].t3_end - lbl_801789C0[5].t3_start;
    PPCMtmmcr0(0x8B);
    PPCMtmmcr1(0x78400000);
    PPCMtmmcr1(0);
    PPCMtmmcr0(0);
    lbl_801789C0[9].t0_start = fn_8000A050();
    lbl_801789C0[9].t1_start = fn_8000A040();
    lbl_801789C0[9].t2_start = fn_8000A030();
    lbl_801789C0[9].t3_start = fn_8000A020();
    PPCMtmmcr0(0x8B);
    PPCMtmmcr1(0x78400000);
    DCStoreRange(dst, width * height * 2);
    PPCMtmmcr1(0);
    PPCMtmmcr0(0);
    lbl_801789C0[9].count++;
    lbl_801789C0[9].t0_end = fn_8000A050();
    lbl_801789C0[9].t1_end = fn_8000A040();
    lbl_801789C0[9].t2_end = fn_8000A030();
    lbl_801789C0[9].t3_end = fn_8000A020();
    {
        u32 d = lbl_801789C0[9].t0_end - lbl_801789C0[9].t0_start;
        u32 max = lbl_801789C0[9].t0_max;
        if (d > max) {
            max = d;
        }
        lbl_801789C0[9].t0_max = max;
    }
    lbl_801789C0[9].t0_total += lbl_801789C0[9].t0_end - lbl_801789C0[9].t0_start;
    lbl_801789C0[9].t1_total += lbl_801789C0[9].t1_end - lbl_801789C0[9].t1_start;
    lbl_801789C0[9].t2_total += lbl_801789C0[9].t2_end - lbl_801789C0[9].t2_start;
    lbl_801789C0[9].t3_total += lbl_801789C0[9].t3_end - lbl_801789C0[9].t3_start;
    PPCMtmmcr0(0x8B);
    PPCMtmmcr1(0x78400000);
    gqr_put2(dec->gqr2);
    gqr_put5(dec->gqr5);
    gqr_put6(dec->gqr6);
    gqr_put7(dec->gqr7);
}
