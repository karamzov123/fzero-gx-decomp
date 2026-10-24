#include "types.h"

typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);
typedef struct Sig_fn_12_24A88_MovieObject {
    u8 pad_0000[0x48];
    s32 state;
    u8 pad_004c[0x940];
    Sig_fn_12_24A88_MovieCallback callback;
    void *callback_context;
    s32 callback_data;
} Sig_fn_12_24A88_MovieObject;

extern s32 fn_12_24A88(Sig_fn_12_24A88_MovieObject *, s32);
extern void *memcpy(void *, const void *, u32);
extern void fn_12_33428(u32 *, u32, u32);

/* 36-byte movie description */
typedef struct MovieInfo {
    u32 field00;
    u32 field04;
    u32 field08;
    u32 field0c;
    u32 buf0;      /* 0x10 */
    u32 field14;
    u32 field18;
    s32 count;     /* 0x1c */
    u32 buf1;      /* 0x20 */
} MovieInfo;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base
 * (dtk's lbl_12_bss_96A0 covers the first four objects) */
u32 lbl_12_bss_96A0;
u32 lbl_12_bss_96A0__fzgx_offset_4[16];   /* 0x96A4 */
u32 lbl_12_bss_96A0__fzgx_offset_44[2];    /* 0x96E4 */
MovieInfo lbl_12_bss_96A0__fzgx_offset_4C; /* 0x96EC */
u8 lbl_12_bss_9710[73760];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_12_bss_96A0;
    s = *(u8 *)&lbl_12_bss_96A0__fzgx_offset_4;
    s = *(u8 *)&lbl_12_bss_96A0__fzgx_offset_44;
    s = *(u8 *)&lbl_12_bss_96A0__fzgx_offset_4C;
    s = *(u8 *)&lbl_12_bss_9710;
}
#pragma section code_type ".text"

typedef struct MovieChannel {
    u32 field00;
    u32 buf;
    u32 field08;
    u32 field0c;
    u32 field10;
    u32 field14;
    u32 field18;
    u32 field1c;
    u32 field20;
    u32 *slot;
    u32 queue[20];
} MovieChannel;

typedef struct MovieSetup {
    u32 field000;
    MovieInfo info;        /* 0x004 */
    u32 pair[2];           /* 0x028 */
    u32 bufs[16];          /* 0x030 */
    u32 field070;
    u32 field074;
    u32 field078;
    u32 field07c;
    u32 field080;
    u32 field084;
    u32 field088;
    u32 queue[20];         /* 0x08c */
    s32 field0dc;
    u32 field0e0;
    s32 field0e4;
    u32 field0e8;
    u32 field0ec;
    u32 field0f0;
    s32 field0f4;
    u32 field0f8;
    s32 field0fc;
    u32 field100;
    u32 field104;
    u8 pad108[0x20];
    u32 field128;
    u32 field12c;
    u32 field130;
    u32 pad134;
    MovieChannel ch[16];   /* 0x138 */
    u32 field8b8;
    u32 field8bc;
    u32 field8c0;
    u32 field8c4;
    u32 field8c8;
    u32 slots[16][2];      /* 0x8cc */
} MovieSetup;

s32 fn_12_26D68(Sig_fn_12_24A88_MovieObject *movie, MovieSetup *setup) {
    s32 i;
    MovieChannel *ch;
    u32 *bp;
    u32 j;
    u32 k;
    s32 err;

    /* the pending description: count in range, and when either direct buffer is
     * missing, the pair and every per-stream buffer must be set.  The loop counter
     * is shared with the channel loop below (retail reuses one variable). */
    if (lbl_12_bss_96A0__fzgx_offset_4C.count <= 0 || lbl_12_bss_96A0__fzgx_offset_4C.count > 16) {
        err = -1;
        goto done; /* fzgx-allow: S1 retail joins the four failures on one error value */
    }
    if (lbl_12_bss_96A0__fzgx_offset_4C.buf0 == 0 || lbl_12_bss_96A0__fzgx_offset_4C.buf1 == 0) {
        for (i = 0; i < 2; i++) {
            if (lbl_12_bss_96A0__fzgx_offset_44[i] == 0) {
                err = -1;
                goto done; /* fzgx-allow: S1 */
            }
        }
        for (i = 0; i < lbl_12_bss_96A0__fzgx_offset_4C.count; i++) {
            if (lbl_12_bss_96A0__fzgx_offset_4[i] == 0) {
                err = -1;
                goto done; /* fzgx-allow: S1 */
            }
        }
    }
    err = 0;
done:
    if (err != 0) {
        return fn_12_24A88(movie, 0xff000f15);
    }

    setup->info = lbl_12_bss_96A0__fzgx_offset_4C;
    memcpy(setup->pair, lbl_12_bss_96A0__fzgx_offset_44, 8);
    memcpy(setup->bufs, lbl_12_bss_96A0__fzgx_offset_4, 0x40);
    setup->field000 = 0;
    setup->field070 = 0;
    setup->field074 = 5;
    setup->field078 = 0xc0;
    setup->field100 = 0;
    setup->field104 = 1;
    setup->field07c = 0;
    setup->field080 = 0;
    setup->field128 = 0;
    setup->field12c = 0;
    setup->field130 = 0;
    for (i = 0, bp = (u32 *)setup, ch = setup->ch; i < 16; i++, bp++, ch++) {
        ch->field00 = 0;
        ch->buf = bp[12];
        ch->field08 = 0;
        ch->field0c = 1;
        ch->field10 = 0;
        ch->field14 = 0;
        ch->field18 = 0;
        ch->field1c = 0;
        ch->field20 = 0;
        fn_12_33428(ch->queue, -1, 0x14);
    }
    setup->field084 = 0;
    setup->field088 = 0;
    fn_12_33428(setup->queue, -1, 0x14);
    setup->field0dc = -1;
    setup->field0e0 = 0;
    setup->field0e4 = 0x7fffffff;
    setup->field0e8 = 0;
    setup->field0ec = 0;
    setup->field0f0 = 0;
    setup->field0f4 = -1;
    setup->field0f8 = 0;
    setup->field0fc = -1;
    setup->field8b8 = 0;
    setup->field8bc = 0;
    setup->field8c0 = 0;
    setup->field8c4 = 0;
    setup->field8c8 = 0;
    for (j = 0; j < 16; j++) {
        setup->slots[j][0] = 0;
        setup->slots[j][1] = 0;
    }
    for (k = 0; k < 16; k++) {
        setup->ch[k].slot = setup->slots[k];
    }
    return 0;
}
