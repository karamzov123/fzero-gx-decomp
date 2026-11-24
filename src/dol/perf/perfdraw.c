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
void fn_8003E9EC(u32 arg0) {
    f32 *fzgx_value;
    f32 v;
    f32 w;
    PerfLines *p;
    u32 counter;

    p = &lbl_8012B658;
    PSMTXIdentity(&lbl_80178C18);
    counter = lbl_801A6C54;
    lbl_801A6C74 = (void (*)(void))arg0;
    lbl_801A6C60 = __OSCoreClock / 60 * 3;
    lbl_801A6C64 = ((counter + 1) * 7);
    lbl_801A6C68 = __OSBusClock / 120;
    v = lbl_801A6C64;
    p->unk_5C = v;
    p->unk_4C = v;
    p->unk_3C = v;
    p->unk_34 = v;
    fzgx_value = &p->unk_2C;
    *fzgx_value = v;
    p->unk_C = v;
    w = (616.0f);
    p->unk_38 = (616.0f);
    p->unk_28 = (616.0f);
    p->unk_20 = (616.0f);
    p->unk_18 = (616.0f);
    p->unk_84 = ((counter + 2) * 19);
    p->unk_8C = p->unk_84;
}
