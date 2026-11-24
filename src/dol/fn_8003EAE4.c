#include "types.h"
#include "sdk_addresses.h"

typedef struct PerfColor {
    u8 r, g, b, a;
} PerfColor;

typedef struct PerfLines {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x8];
    f32 unk_18;
    u8 pad_1C[0x4];
    f32 unk_20;
    u8 pad_24[0x4];
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[0x4];
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    u8 pad_40[0xC];
    f32 unk_4C;
    u8 pad_50[0xC];
    f32 unk_5C;
    u8 pad_60[0x24];
    f32 unk_84;
    u8 pad_88[0x4];
    f32 unk_8C;
} PerfLines;

typedef struct PerfDrawState {
    u8 pad_0[0x30];
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
    f32 unk_68;
    f32 unk_6C;
    u8 pad_70[0x4];
    f32 unk_74;
    f32 unk_78;
    f32 unk_7C;
    f32 unk_80;
    f32 unk_84;
    f32 unk_88;
    u8 pad_8C[0x4];
} PerfDrawState;

typedef struct PerfRecord {
    u8 id;
    u8 pad[3];
    u32 start;
    u32 end;
    u32 valueC;
    u32 value10;
    s32 flag;
    u32 value18;
    u32 value1C;
    u32 value20;
    u32 value24;
    u32 value28;
    u32 value2C;
    u8 tail[0x80];
} PerfRecord;

typedef struct PerfDescriptor {
    u32 unk0;
    s32 type;
    u32 unk8;
    PerfColor color;
} PerfDescriptor;

typedef struct PerfFrame {
    PerfRecord *records;
    u32 count;
    u32 ticks;
    u32 other;
} PerfFrame;

typedef union PerfWGPipe {
    u8 U8;
    u16 U16;
    u32 U32;
    f32 F32;
} PerfWGPipe;

extern PerfLines lbl_8012B658;
extern PerfDrawState lbl_80178C18;
extern u32 lbl_801A6590;
extern f32 lbl_801A6594;
extern PerfColor lbl_801A6598;
extern PerfColor lbl_801A659C;
extern PerfColor lbl_801A65A0;
extern PerfColor lbl_801A65A4;
extern PerfColor lbl_801A65A8;
extern PerfColor lbl_801A65AC;
extern PerfColor lbl_801A65B0;
extern PerfColor lbl_801A65B4;
extern PerfColor lbl_801A65B8;
extern PerfColor lbl_801A65BC;
extern PerfColor lbl_801A65C0;
extern PerfColor lbl_801A65C4;
extern PerfColor lbl_801A65C8;
extern PerfColor lbl_801A65CC;
extern PerfColor lbl_801A65D0;
extern PerfColor lbl_801A65D4;
extern PerfColor lbl_801A65D8;
extern PerfColor lbl_801A65DC;
extern PerfColor lbl_801A65E0;
extern PerfColor lbl_801A65E4;
extern PerfColor lbl_801A65E8;
extern PerfColor lbl_801A65EC;
extern u32 lbl_801A65F0;
extern u32 lbl_801A65F4;
extern u32 lbl_801A65F8;
extern u32 lbl_801A65FC;
extern u32 lbl_801A6600[2];
extern u32 lbl_801A6C44;
extern PerfDescriptor *lbl_801A6C48;
extern PerfFrame *lbl_801A6C4C;
extern u32 lbl_801A6C54;
extern u32 lbl_801A6C60;
extern f32 lbl_801A6C64;
extern u32 lbl_801A6C68;
extern u32 lbl_801A6C6C;
extern f32 lbl_801A6C70;
extern void (*lbl_801A6C74)(void);

extern const f32 lbl_801A71C8;
extern const f64 lbl_801A71D0;
extern const f32 lbl_801A71D8;
extern const f32 lbl_801A71DC;
extern const f32 lbl_801A71E0;
extern const f32 lbl_801A71E4;
extern const f32 lbl_801A71E8;
extern const f32 lbl_801A71EC;
extern const f32 lbl_801A71F0;
extern const f32 lbl_801A71F4;
extern const f32 lbl_801A71F8;
extern const f32 lbl_801A71FC;
extern const f32 lbl_801A7200;
extern const f32 lbl_801A7204;
extern const f32 lbl_801A7208;
extern const f32 lbl_801A720C;

extern void PSMTXIdentity(void *);
extern u32 GXSetProjection(void *, u32);
extern void GXClearVtxDesc(void);
extern void GXInvalidateVtxCache(void);
extern void GXSetTevOrder(u32, u32, u32, u32);
extern void GXSetTevOp(u32, u32);
extern void GXSetVtxDesc(u32, u32);
extern void GXSetVtxAttrFmt(u32, u32, u32, u32, u8);
extern u32 fn_80035960(u32, u32, u32, u32, u32, u32, u32);
extern void GXSetNumTexGens(u32);
extern void fn_8003591C(u8);
extern void GXSetNumTevStages(u32);
extern void fn_80037B14(s32, s32, s32, s32);
extern void fn_80037BC0(u8, s32, u8);
extern void GXSetZCompLoc(u32);
extern void GXGetProjectionv(f32 *);
extern void GXLoadPosMtxImm(void *, u32);
extern void fn_80035828();
extern void fn_8003462C(u32, u32, u32);
extern void GXSetLineWidth(u8, u32);

/* fzgx-allow: A1 SDK absolute-addressed OS clock globals */
u32 __OSBusClock : (0x80000000 + 0xF8);
u32 __OSCoreClock : (0x80000000 + 0xFC);
/* fzgx-allow: A1 SDK absolute-addressed GX write-gather pipe */
volatile PerfWGPipe __GXWGFifo : FZGX_ADDR_GXFIFO;

#pragma opt_propagation off
void fn_8003E9EC(u32 arg0);
#pragma opt_propagation reset

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_lifetimes off

void fn_8003EAE4(void) {
    f32 tmp[4];
    PerfDrawState *p = &lbl_80178C18;

    GXGetProjectionv((f32 *)((u8 *)p + 0x70));
    p->unk_30 = lbl_801A71D8;
    p->unk_34 = lbl_801A71D8;
    p->unk_38 = lbl_801A71D8;
    p->unk_3C = lbl_801A71D8;
    p->unk_40 = lbl_801A71D8;
    p->unk_44 = lbl_801A71D8;
    p->unk_48 = lbl_801A71D8;
    p->unk_4C = lbl_801A71D8;
    p->unk_50 = lbl_801A71D8;
    p->unk_54 = lbl_801A71D8;
    p->unk_58 = lbl_801A71D8;
    p->unk_5C = lbl_801A71D8;
    p->unk_60 = lbl_801A71D8;
    p->unk_64 = lbl_801A71D8;
    p->unk_68 = lbl_801A71D8;
    p->unk_6C = lbl_801A71D8;
    p->unk_30 = lbl_801A71DC;
    p->unk_44 = lbl_801A71E0;
    p->unk_58 = lbl_801A71E4;
    p->unk_6C = lbl_801A71E4;
    p->unk_3C = lbl_801A71E8;
    p->unk_4C = lbl_801A71EC;
    GXSetProjection(&p->unk_30, 1);
    GXClearVtxDesc();
    GXInvalidateVtxCache();
    fn_80037B14(1, 4, 5, 0);
    GXSetZCompLoc(0);
    fn_8003591C(1);
    fn_80035960(4, 0, 0, 0, 0, 0, 2);
    GXSetTevOrder(0, 0xff, 0xff, 4);
    GXSetTevOp(0, 4);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    fn_80037BC0(0, 7, 0);
    GXSetVtxDesc(9, 1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
}

static inline f32 fn_8003EC44_Height(u32 ticks, f32 scale) {
    return lbl_801A71F4 * (ticks / (lbl_801A6C68 * scale));
}

void fn_8003EC44(PerfRecord *arg0) {
    f32 v18;
    u32 v0;
    u32 total;
    u32 v1;
    u32 v2;
    f32 v5;
    u32 v6;
    u32 v9;
    f32 v12;
    f32 v10;
    f32 v11;
    f32 v13;
    f32 v14;
    u32 v15;
    u32 v52;
    u32 v59;
    f32 v64;
    f32 v65;
    u32 v68;
    u32 v69;
    u32 v70;
    u32 v72;
    u32 fzgx_frame_pad_a[6];  /* fzgx: retail frame home */
    PerfColor c0;
    PerfColor c1;
    PerfColor c2;
    PerfColor c3;
    PerfColor c4;
    PerfColor c5;
    PerfColor c6;
    PerfColor c7;
    PerfColor c8;
    PerfColor c9;
    PerfColor c10;
    PerfColor c11;
    PerfColor c12;
    PerfColor c13;
    u32 fzgx_frame_pad_b[2];  /* fzgx: retail frame home */
    f32 loc_1C;
    u32 fzgx_frame_pad_c[4];  /* fzgx: retail frame home */
    v0 = arg0->valueC;
    total = lbl_801A6C60;
    v1 = arg0->value10;
    v2 = (v1 - v0);
    v10 = (f32)v2 / (__OSCoreClock / 60);
    v11 = (lbl_801A71F0 + lbl_801A6C64);
    v5 = (lbl_801A71C8 * ((f32)v0 / total));
    v12 = (lbl_801A71C8 * ((f32)v1 / total));
    v13 = v5;
    loc_1C = (lbl_801A6C70 - v5);
    v6 = (*(u32 *)&loc_1C);
    v9 = (v6 & 0x7FFFFFFF);
    (*(u32 *)&loc_1C) = v9;
    if (loc_1C < lbl_801A71E4) {
        v13 = lbl_801A6C70;
    }
    lbl_801A6C70 = v12;
    v14 = loc_1C;
    v15 = 0x43300000;
    if ((s32)lbl_801A65F4 != 0) {
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 68) - *(u32 *)((u8 *)arg0 + 64), v10);
        if (v18 > lbl_801A71E4) {
            c0 = lbl_801A65C0;
            fn_80035828(4, &c0);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo.F32 = v13;
            v14 = (v11 + v18);
            __GXWGFifo.F32 = v11;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v13;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v11;
            v11 = (v11 + v18);
            __GXWGFifo.F32 = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 76) - *(u32 *)((u8 *)arg0 + 72), v10);
        if (v18 > lbl_801A71E4) {
            c1 = lbl_801A65C4;
            fn_80035828(4, &c1);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo.F32 = v13;
            v14 = (v11 + v18);
            __GXWGFifo.F32 = v11;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v13;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v11;
            v11 = (v11 + v18);
            __GXWGFifo.F32 = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 84) - *(u32 *)((u8 *)arg0 + 80), v10);
        if (v18 > lbl_801A71E4) {
            c2 = lbl_801A65C8;
            fn_80035828(4, &c2);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo.F32 = v13;
            v14 = (v11 + v18);
            __GXWGFifo.F32 = v11;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v13;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v11;
            v11 = (v11 + v18);
            __GXWGFifo.F32 = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 92) - *(u32 *)((u8 *)arg0 + 88), v10);
        if (v18 > lbl_801A71E4) {
            c3 = lbl_801A65CC;
            fn_80035828(4, &c3);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo.F32 = v13;
            v14 = (v11 + v18);
            __GXWGFifo.F32 = v11;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v13;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v11;
            v11 = (v11 + v18);
            __GXWGFifo.F32 = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 100) - *(u32 *)((u8 *)arg0 + 96), v10);
        if (v18 > lbl_801A71E4) {
            c4 = lbl_801A65D0;
            fn_80035828(4, &c4);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo.F32 = v13;
            v14 = (v11 + v18);
            __GXWGFifo.F32 = v11;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v13;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v11;
            v11 = (v11 + v18);
            __GXWGFifo.F32 = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 108) - *(u32 *)((u8 *)arg0 + 104), v10);
        if (v18 > lbl_801A71E4) {
            c5 = lbl_801A65D4;
            fn_80035828(4, &c5);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo.F32 = v13;
            v14 = (v11 + v18);
            __GXWGFifo.F32 = v11;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v13;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v11;
            v11 = (v11 + v18);
            __GXWGFifo.F32 = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 116) - *(u32 *)((u8 *)arg0 + 112), v10);
        if (v18 > lbl_801A71E4) {
            c6 = lbl_801A65D8;
            fn_80035828(4, &c6);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo.F32 = v13;
            v14 = (v11 + v18);
            __GXWGFifo.F32 = v11;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v13;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v11;
            v11 = (v11 + v18);
            __GXWGFifo.F32 = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 124) - *(u32 *)((u8 *)arg0 + 120), v10);
        if (v18 > lbl_801A71E4) {
            c7 = lbl_801A65DC;
            fn_80035828(4, &c7);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo.F32 = v13;
            v14 = (v11 + v18);
            __GXWGFifo.F32 = v11;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v13;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v11;
            v11 = (v11 + v18);
            __GXWGFifo.F32 = lbl_801A71F8;
        }
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 132) - *(u32 *)((u8 *)arg0 + 128), v10);
        if (v18 > lbl_801A71E4) {
            c8 = lbl_801A65E0;
            fn_80035828(4, &c8);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo.F32 = v13;
            v14 = (v11 + v18);
            __GXWGFifo.F32 = v11;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v13;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v11;
            v11 = (v11 + v18);
            __GXWGFifo.F32 = lbl_801A71F8;
        }
        *(u32 *)((u8 *)arg0 + 136) = ((u32)*(u32 *)((u8 *)arg0 + 136) >> 1);
        v52 = ((u32)*(u32 *)((u8 *)arg0 + 140) >> 1);
        *(u32 *)((u8 *)arg0 + 140) = v52;
        v18 = fn_8003EC44_Height(*(u32 *)((u8 *)arg0 + 140) - *(u32 *)((u8 *)arg0 + 136), v10);
        if (v18 > lbl_801A71E4) {
            c9 = lbl_801A65E4;
            fn_80035828(4, &c9);
            v15 = 4;
            fn_8003462C(128, 0, v15);
            __GXWGFifo.F32 = v13;
            v14 = (v11 + v18);
            __GXWGFifo.F32 = v11;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v13;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v11;
            __GXWGFifo.F32 = lbl_801A71F8;
        }
    }
    if ((s32)lbl_801A65F8 != 0) {
        v18 = (lbl_801A71F0 + (lbl_801A71F4 + (lbl_801A71F0 + lbl_801A6C64)));
        v59 = (*(u32 *)((u8 *)arg0 + 36) - *(u32 *)((u8 *)arg0 + 32));
        v11 = lbl_801A71FC * (((f32)(*(u32 *)((u8 *)arg0 + 52) - *(u32 *)((u8 *)arg0 + 48)) / v2) / 2.0f);
        if (v11 > lbl_801A71E4) {
            c10 = lbl_801A65BC;
            fn_80035828(4, &c10);
            fn_8003462C(128, 0, 4);
            __GXWGFifo.F32 = v13;
            v14 = v18 + v11;
            __GXWGFifo.F32 = v18;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v13;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v18;
            __GXWGFifo.F32 = lbl_801A71F8;
        }
        c11 = lbl_801A65A8;
            fn_80035828(4, &c11);
        fn_8003462C(128, 0, 4);
        v64 = lbl_801A71FC + v18;
        v65 = v64 - (lbl_801A71FC * v59) / v2;
        __GXWGFifo.F32 = v13;
        __GXWGFifo.F32 = v65;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = v13;
        __GXWGFifo.F32 = v64;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = v12;
        __GXWGFifo.F32 = v64;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = v12;
        __GXWGFifo.F32 = v65;
        __GXWGFifo.F32 = lbl_801A71F8;
    }
    v2 = (*(u32 *)((u8 *)arg0 + 172) - *(u32 *)((u8 *)arg0 + 168));
    if ((s32)lbl_801A65FC != 0) {
        v18 = lbl_801A7204 + (lbl_801A71FC + (lbl_801A71F4 + (lbl_801A71F0 + lbl_801A6C64)));
        v68 = (*(u32 *)((u8 *)arg0 + 148) - *(u32 *)((u8 *)arg0 + 144));
        v69 = (*(u32 *)((u8 *)arg0 + 156) - *(u32 *)((u8 *)arg0 + 152));
        v70 = v69 + v68;
        if (v2 >= v70) {
            v11 = (lbl_801A71FC * (v2 - v70)) / v2;
            if (v11 > lbl_801A71E4) {
                c12 = lbl_801A65E8;
            fn_80035828(4, &c12);
                fn_8003462C(128, 0, 4);
                __GXWGFifo.F32 = v13;
                v14 = v18 + v11;
                __GXWGFifo.F32 = v18;
                __GXWGFifo.F32 = lbl_801A71F8;
                __GXWGFifo.F32 = v13;
                __GXWGFifo.F32 = v14;
                __GXWGFifo.F32 = lbl_801A71F8;
                __GXWGFifo.F32 = v12;
                __GXWGFifo.F32 = v14;
                __GXWGFifo.F32 = lbl_801A71F8;
                __GXWGFifo.F32 = v12;
                __GXWGFifo.F32 = v18;
                __GXWGFifo.F32 = lbl_801A71F8;
            }
        }
    }
    if ((s32)lbl_801A6600[0] != 0) {
        v18 = lbl_801A71FC + (lbl_801A7208 + (lbl_801A71FC + (lbl_801A71F4 + (lbl_801A71F0 + lbl_801A6C64))));
        v72 = (*(u32 *)((u8 *)arg0 + 164) - *(u32 *)((u8 *)arg0 + 160));
        v11 = (lbl_801A71FC * v72) / v2;
        if (v11 > lbl_801A71E4) {
            c13 = lbl_801A65EC;
            fn_80035828(4, &c13);
            fn_8003462C(128, 0, 4);
            __GXWGFifo.F32 = v13;
            v14 = v18 + v11;
            __GXWGFifo.F32 = v18;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v13;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v14;
            __GXWGFifo.F32 = lbl_801A71F8;
            __GXWGFifo.F32 = v12;
            __GXWGFifo.F32 = v18;
            __GXWGFifo.F32 = lbl_801A71F8;
        }
    }
}

#pragma opt_lifetimes reset

#pragma opt_lifetimes reset

static inline void setBarColor(PerfColor color) {
    (void)color;
}

void fn_8003F834(void) {
    u8 scratch[24];
    u32 v0;
    u32 v2;
    f32 v4;
    f32 v6;
    f32 v7;
    f32 v12;
    f32 v17;
    f32 v22;
    f32 v27;
    f32 v32;
    f32 v37;
    f32 v42;
    f32 v47;
    f32 v52;
    v6 = (lbl_801A71F0 + lbl_801A6C64);
    v0 = lbl_801A6C68;
    v2 = v0 / 10;
    v4 = lbl_801A71F4 * (v2 / (v0 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(4, lbl_801A65C0);
        fn_8003462C(128, 0, 4);
        v7 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v6;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v7;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v7;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v6;
        v6 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * (v2 / (lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(4, lbl_801A65C4);
        fn_8003462C(128, 0, 4);
        v12 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v6;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v12;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v12;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v6;
        v6 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * (v2 / (lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(4, lbl_801A65C8);
        fn_8003462C(128, 0, 4);
        v17 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v6;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v17;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v17;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v6;
        v6 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * (v2 / (lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(4, lbl_801A65CC);
        fn_8003462C(128, 0, 4);
        v22 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v6;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v22;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v22;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v6;
        v6 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * (v2 / (lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(4, lbl_801A65D0);
        fn_8003462C(128, 0, 4);
        v27 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v6;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v27;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v27;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v6;
        v6 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * (v2 / (lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(4, lbl_801A65D4);
        fn_8003462C(128, 0, 4);
        v32 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v6;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v32;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v32;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v6;
        v6 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * (v2 / (lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(4, lbl_801A65D8);
        fn_8003462C(128, 0, 4);
        v37 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v6;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v37;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v37;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v6;
        v6 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * (v2 / (lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(4, lbl_801A65DC);
        fn_8003462C(128, 0, 4);
        v42 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v6;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v42;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v42;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v6;
        v6 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * (v2 / (lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(4, lbl_801A65E0);
        fn_8003462C(128, 0, 4);
        v47 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v6;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v47;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v47;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v6;
        v6 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A71F8;
    }
    v4 = lbl_801A71F4 * (v2 / (lbl_801A6C68 * lbl_801A71E4));
    if (v4 > lbl_801A71E4) {
        fn_80035828(4, lbl_801A65E4);
        fn_8003462C(128, 0, 4);
        v52 = (v6 + v4);
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v6;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A720C;
        __GXWGFifo.F32 = v52;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v52;
        __GXWGFifo.F32 = lbl_801A71F8;
        __GXWGFifo.F32 = lbl_801A71C8;
        __GXWGFifo.F32 = v6;
        __GXWGFifo.F32 = lbl_801A71F8;
    }
    if (0) {
        setBarColor(lbl_801A65E4);
    }
}

#pragma opt_propagation reset
#pragma opt_common_subs reset

static inline void position(f32 x, f32 y, f32 z) {
    register volatile PerfWGPipe *fifo = &__GXWGFifo; /* write-gather pipe: every store is a vertex component */
    fifo->F32 = x;
    fifo->F32 = y;
    fifo->F32 = z;
}

static inline void loadPositionMatrix(void *mtx, u32 index) {
    struct { void *matrix; u32 reserved[9]; } setup;
    setup.matrix = mtx;
    GXLoadPosMtxImm(mtx, index);
}

static inline f32 scaleTicks(u32 step, u32 n) {
    return 616.0f * ((n * step) / (f32)lbl_801A6C60);
}

#define SCALE(n) (616.0f * ((f32)(u32)(n) / (f32)lbl_801A6C60))
#define DATA(n) (*(f32 *)(p_lbl_8012B658 + (n)))

void fn_8003FF88(void) {
    u8 *p_lbl_8012B658;
    u32 v0;
    u32 v2;
    PerfRecord *records;
    PerfRecord *record;
    PerfDescriptor *desc;
    u32 i;
    u32 j;
    u32 id;
    u32 y;
    u32 step;
    u32 delta;
    f32 total;
    f32 height;
    f32 x;

    p_lbl_8012B658 = (u8 *)&lbl_8012B658;
    if (lbl_801A6C74 != 0) {
        records = lbl_801A6C4C[lbl_801A6C44].records;
        if ((s32)lbl_801A65F0 != 0) {
            lbl_801A6590 = lbl_801A6C4C[lbl_801A6C44].ticks / (__OSCoreClock / 60) + 1;
        }
        lbl_801A6C60 = (__OSCoreClock / 60) * lbl_801A6590;
        lbl_801A6594 = 616.0f / lbl_801A6590;
        total = SCALE(lbl_801A6C4C[lbl_801A6C44].ticks);
        loadPositionMatrix(&lbl_80178C18, 0);
        fn_80035828(4, lbl_801A6598);
        fn_8003462C(0x80, 0, 4);
        position(0.0f, 0.0f, -1.0f);
        position(0.0f, lbl_801A6C64, -1.0f);
        position(616.0f, lbl_801A6C64, -1.0f);
        position(616.0f, 0.0f, -1.0f);
        fn_80035828(4, lbl_801A659C);
        GXSetLineWidth(12, 0);
        fn_8003462C(0xA8, 0, 8);
        position(DATA(0), DATA(4), -1.0f);
        position(DATA(8), DATA(12), -1.0f);
        position(DATA(16), DATA(20), -1.0f);
        position(DATA(24), DATA(28), -1.0f);
        position(DATA(32), DATA(36), -1.0f);
        position(DATA(40), DATA(44), -1.0f);
        position(DATA(48), DATA(52), -1.0f);
        position(DATA(56), DATA(60), -1.0f);
        if (lbl_801A6590 > 1) {
            fn_8003462C(0xA8, 0, (u16)((lbl_801A6590 - 1) * 2));
            for (j = 1; j < lbl_801A6590; j++) {
                x = scaleTicks(__OSCoreClock / 60, j);
                position(x, DATA(0x44), -1.0f);
                position(x, DATA(0x4C), -1.0f);
            }
        }
        fn_80035828(4, lbl_801A65A0);
        GXSetLineWidth(32, 0);
        fn_8003462C(0xA8, 0, 2);
        position(0.0f, 0.0f, -1.0f);
        position(total, 0.0f, -1.0f);
        fn_80035828(4, lbl_801A65A8);
        fn_8003462C(0xA8, 0, 2);
        position(0.0f, 0.0f, -1.0f);
        position(SCALE(lbl_801A6C4C[lbl_801A6C44].other), 0.0f, -1.0f);
        if ((s32)lbl_801A65F4 != 0) {
            height = 7.0f + lbl_801A6C64;
            fn_80035828(4, lbl_801A65B0);
            fn_8003462C(0x80, 0, 4);
            position(0.0f, height, -1.0f);
            position(0.0f, 140.0f + height, -1.0f);
            position(total, 140.0f + height, -1.0f);
            position(total, height, -1.0f);
        }
        if ((s32)lbl_801A65F8 != 0) {
            height = 7.0f + (140.0f + (7.0f + lbl_801A6C64));
            fn_80035828(4, lbl_801A65B4);
            fn_8003462C(0x80, 0, 4);
            position(0.0f, height, -1.0f);
            position(0.0f, 50.0f + height, -1.0f);
            position(total, 50.0f + height, -1.0f);
            position(total, height, -1.0f);
            fn_80035828(4, lbl_801A65AC);
            GXSetLineWidth(6, 0);
            fn_8003462C(0xA8, 0, 2);
            position(0.0f, 25.0f + height, -1.0f);
            position(total, 25.0f + height, -1.0f);
        }
        if ((s32)lbl_801A65FC != 0) {
            height = 14.0f + (50.0f + (140.0f + (7.0f + lbl_801A6C64)));
            fn_80035828(4, lbl_801A65B8);
            fn_8003462C(0x80, 0, 4);
            position(0.0f, height, -1.0f);
            position(0.0f, 50.0f + height, -1.0f);
            position(total, 50.0f + height, -1.0f);
            position(total, height, -1.0f);
        }
        if ((s32)lbl_801A6600[0] != 0) {
            height = 50.0f + (21.0f + (50.0f + (140.0f + (7.0f + lbl_801A6C64))));
            fn_80035828(4, lbl_801A65B8);
            fn_8003462C(0x80, 0, 4);
            position(0.0f, height, -1.0f);
            position(0.0f, 50.0f + height, -1.0f);
            position(total, 50.0f + height, -1.0f);
            position(total, height, -1.0f);
        }

        for (i = 0; i < lbl_801A6C4C[lbl_801A6C44].count; i++) {
            record = &records[i];
            id = record->id;
            if (id == 0xFF) {
                fn_8003EC44(record);
            } else {
                desc = &lbl_801A6C48[id];
                switch (desc->type) {
                case 1:
                    fn_80035828(4, desc->color);
                    GXSetLineWidth(32, 0);
                    fn_8003462C(0xA8, 0, 2);
                    y = (id + 1) * 7;
                    position(SCALE(record->start), y, -1.0f);
                    position(SCALE(record->end), y, -1.0f);
                    delta = record->value2C - record->value28;
                    if (delta != 0) {
                        x = SCALE(delta + record->start);
                        fn_80035828(4, lbl_801A65A8);
                        fn_8003462C(0xA8, 0, 2);
                        position(SCALE(record->start), y, -1.0f);
                        position(x, y, -1.0f);
                    }
                    if (record->value10 != 0) {
                        if (record->flag == 0) {
                            fn_80035828(4, lbl_801A65A4);
                            GXSetLineWidth(32, 0);
                            fn_8003462C(0xA8, 0, 2);
                            position(SCALE(record->valueC), lbl_801A6C64, -1.0f);
                            position(SCALE(record->value10), lbl_801A6C64, -1.0f);
                            fn_8003EC44(record);
                            fn_80035828(4, lbl_801A65AC);
                            GXSetLineWidth(6, 0);
                            fn_8003462C(0xA8, 0, 4);
                            position(SCALE(record->valueC), lbl_801A6C64, -1.0f);
                            position(SCALE(record->start), y, -1.0f);
                            position(SCALE(record->value10), lbl_801A6C64, -1.0f);
                            position(SCALE(record->end), y, -1.0f);
                        } else {
                            fn_80035828(4, lbl_801A65A4);
                            GXSetLineWidth(32, 0);
                            fn_8003462C(0xA8, 0, 2);
                            position(SCALE(record->value1C), lbl_801A6C64, -1.0f);
                            position(SCALE(record->value10), lbl_801A6C64, -1.0f);
                            fn_8003EC44(record);
                            fn_80035828(4, lbl_801A65AC);
                            GXSetLineWidth(6, 0);
                            fn_8003462C(0xA8, 0, 4);
                            position(SCALE(record->value1C), lbl_801A6C64, -1.0f);
                            position(SCALE(record->value18), y, -1.0f);
                            position(SCALE(record->value10), lbl_801A6C64, -1.0f);
                            position(SCALE(record->end), y, -1.0f);
                        }
                    }
                    break;
                case 0:
                    fn_80035828(4, desc->color);
                    GXSetLineWidth(32, 0);
                    fn_8003462C(0xA8, 0, 2);
                    y = (id + 1) * 7;
                    position(SCALE(record->start), y, -1.0f);
                    position(SCALE(record->end), y, -1.0f);
                    delta = record->value2C - record->value28;
                    if (delta != 0) {
                        x = SCALE(delta + record->start);
                        fn_80035828(4, lbl_801A65A8);
                        fn_8003462C(0xA8, 0, 2);
                        position(SCALE(record->start), y, -1.0f);
                        position(x, y, -1.0f);
                    }
                    break;
                case 2:
                    if (record->flag == 0) {
                        fn_80035828(4, lbl_801A65A4);
                        GXSetLineWidth(32, 0);
                        fn_8003462C(0xA8, 0, 2);
                        position(SCALE(record->valueC), lbl_801A6C64, -1.0f);
                        position(SCALE(record->value10), lbl_801A6C64, -1.0f);
                        fn_8003EC44(record);
                    } else {
                        fn_80035828(4, lbl_801A65A4);
                        GXSetLineWidth(32, 0);
                        fn_8003462C(0xA8, 0, 2);
                        position(SCALE(record->value1C), lbl_801A6C64, -1.0f);
                        position(SCALE(record->value10), lbl_801A6C64, -1.0f);
                        fn_8003EC44(record);
                    }
                    break;
                }
            }
        }
        if ((s32)lbl_801A6C6C != 0) {
            fn_8003F834();
        }
    }
}

void fn_800410A4(void) {
    PerfDrawState *p = &lbl_80178C18;

    p->unk_30 = lbl_801A71D8;
    p->unk_34 = lbl_801A71D8;
    p->unk_38 = lbl_801A71D8;
    p->unk_3C = lbl_801A71D8;
    p->unk_40 = lbl_801A71D8;
    p->unk_44 = lbl_801A71D8;
    p->unk_48 = lbl_801A71D8;
    p->unk_4C = lbl_801A71D8;
    p->unk_50 = lbl_801A71D8;
    p->unk_54 = lbl_801A71D8;
    p->unk_58 = lbl_801A71D8;
    p->unk_5C = lbl_801A71D8;
    p->unk_60 = lbl_801A71D8;
    p->unk_64 = lbl_801A71D8;
    p->unk_68 = lbl_801A71D8;
    p->unk_6C = lbl_801A71D8;
    p->unk_30 = p->unk_74;
    p->unk_38 = p->unk_78;
    p->unk_44 = p->unk_7C;
    p->unk_48 = p->unk_80;
    p->unk_58 = p->unk_84;
    p->unk_5C = p->unk_88;
    p->unk_68 = lbl_801A71F8;
    GXSetProjection(&p->unk_30, 0);
    lbl_801A6C74();
}

void fn_8004115C(u32 arg0) {
    lbl_801A6C6C = arg0;
}
