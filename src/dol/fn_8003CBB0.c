#include "types.h"
#include "gqr.h"

typedef struct ImgComponent {
    u32 width;          /* 0x00 */
    u32 height;         /* 0x04 */
    u8 *base;           /* 0x08 */
    u8 *dest;           /* 0x0C */
    u32 unk_10;         /* 0x10 */
    u32 unk_14;         /* 0x14 */
    u8 pad_18[0x18];
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
    u8 pad_418[0x4];
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

typedef struct ImgStats {
    u8 pad_0[0x70];
    u32 t0_start;   /* 0x70 */
    u32 t0_end;     /* 0x74 */
    u32 t2_start;   /* 0x78 */
    u32 t2_end;     /* 0x7C */
    u32 t1_start;   /* 0x80 */
    u32 t1_end;     /* 0x84 */
    u32 t3_start;   /* 0x88 */
    u32 t3_end;     /* 0x8C */
    u32 t0_total;   /* 0x90 */
    u32 t2_total;   /* 0x94 */
    u32 t1_total;   /* 0x98 */
    u32 t3_total;   /* 0x9C */
    u32 t0_max;     /* 0xA0 */
    u32 count;      /* 0xA4 */
} ImgStats;

extern ImgStats lbl_801789C0;
extern void PPCMtmmcr0(u32 value);
extern void PPCMtmmcr1(u32 value);
extern u32 fn_8000A020(void);
extern u32 fn_8000A030(void);
extern u32 fn_8000A040(void);
extern u32 fn_8000A050(void);
extern void DCStoreRange(void *, u32);
extern void fn_8003B010(ImgDecoder *dec);

void fn_8003CBB0(ImgHandle *handle, u8 *tileY, u8 *tileU, u8 *tileV) {
    ImgDecoder *dec;
    u32 i;
    u32 csize;
    u32 ysize;

    dec = handle->dec;
    dec->unk_400 = dec->unk_404;
    dec->unk_414 = 0x21;
    dec->unk_7AA = 0;
    dec->unk_7AC = 0;
    dec->unk_7A6 = 0;
    dec->unk_41D = 0;
    dec->unk_40C = 0;
    dec->unk_40E = 0;
    dec->unk_7AC = 0;
    dec->comp[0].dest = tileY;
    if (dec->unk_41C >= 2) {
        dec->comp[1].dest = tileU;
    }
    if (dec->unk_41C >= 3) {
        dec->comp[2].dest = tileV;
    }
    dec->gqr2 = gqr_get2();
    gqr_set2_decode();
    dec->gqr5 = gqr_get5();
    gqr_set5_decode();
    dec->gqr6 = gqr_get6();
    gqr_set6_decode();
    dec->gqr7 = gqr_get7();
    gqr_set7_decode();
    while (dec->unk_7AC < dec->unk_40A) {
        dec->unk_7AA = 0;
        fn_8003B010(dec);
        dec->unk_7AC += dec->unk_7A8;
        for (i = 0; i < dec->unk_41C; i++) {
            dec->comp[i].dest += (dec->comp[i].unk_10 * (dec->unk_7A0 * dec->comp[i].unk_14)) << 6;
        }
    }
    PPCMtmmcr1(0);
    PPCMtmmcr0(0);
    lbl_801789C0.t0_start = fn_8000A050();
    lbl_801789C0.t1_start = fn_8000A040();
    lbl_801789C0.t2_start = fn_8000A030();
    lbl_801789C0.t3_start = fn_8000A020();
    PPCMtmmcr0(0x8B);
    PPCMtmmcr1(0x78400000);
    ysize = dec->comp[0].width * dec->comp[0].height;
    csize = dec->comp[1].width * dec->comp[1].height;
    DCStoreRange(tileY, ysize);
    DCStoreRange(tileU, csize);
    DCStoreRange(tileV, csize);
    PPCMtmmcr1(0);
    PPCMtmmcr0(0);
    lbl_801789C0.count++;
    lbl_801789C0.t0_end = fn_8000A050();
    lbl_801789C0.t1_end = fn_8000A040();
    lbl_801789C0.t2_end = fn_8000A030();
    lbl_801789C0.t3_end = fn_8000A020();
    {
        u32 d = lbl_801789C0.t0_end - lbl_801789C0.t0_start;
        u32 max = lbl_801789C0.t0_max;
        if (d > max) {
            max = d;
        }
        lbl_801789C0.t0_max = max;
    }
    lbl_801789C0.t0_total += lbl_801789C0.t0_end - lbl_801789C0.t0_start;
    lbl_801789C0.t1_total += lbl_801789C0.t1_end - lbl_801789C0.t1_start;
    lbl_801789C0.t2_total += lbl_801789C0.t2_end - lbl_801789C0.t2_start;
    lbl_801789C0.t3_total += lbl_801789C0.t3_end - lbl_801789C0.t3_start;
    PPCMtmmcr0(0x8B);
    PPCMtmmcr1(0x78400000);
    gqr_put2(dec->gqr2);
    gqr_put5(dec->gqr5);
    gqr_put6(dec->gqr6);
    gqr_put7(dec->gqr7);
}
