#include "sdk_addresses.h"
#include "types.h"

typedef struct Color { u8 r, g, b, a; } Color;

typedef struct Record {
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
} Record;

typedef struct Descriptor {
    u32 unk0;
    s32 type;
    u32 unk8;
    Color color;
} Descriptor;

typedef struct Frame {
    Record *records;
    u32 count;
    u32 ticks;
    u32 other;
} Frame;

extern u32 lbl_801A65F0;
extern u32 lbl_801A6C44;
extern Frame *lbl_801A6C4C;
extern u32 lbl_801A6C74;
extern u8 lbl_8012B658[];
extern Descriptor *lbl_801A6C48;
extern u32 lbl_801A6590;
extern u32 lbl_801A6C60;
extern f32 lbl_801A6594;
extern f32 lbl_801A6C64;
extern u8 lbl_80178C18[144];
extern u32 lbl_801A65F4;
extern u32 lbl_801A65F8;
extern u32 lbl_801A65FC;
extern u32 lbl_801A6600[2];
extern u32 lbl_801A6C6C;

extern Color lbl_801A6598;
extern Color lbl_801A659C;
extern Color lbl_801A65A0;
extern Color lbl_801A65A4;
extern Color lbl_801A65A8;
extern Color lbl_801A65AC;
extern Color lbl_801A65B0;
extern Color lbl_801A65B4;
extern Color lbl_801A65B8;
extern void GXLoadPosMtxImm(void *, u32);
extern void fn_80035828(u32, Color);
extern void fn_8003462C(u32, u32, u32);
extern void GXSetLineWidth(u8, u32);
extern void fn_8003EC44(void *);
extern void fn_8003F834(void);

/* fzgx-allow: A1 SDK absolute-addressed OS clock globals */
u32 __OSCoreClock : (0x80000000 + 0xFC);
typedef union WGPipe { u8 U8; u16 U16; u32 U32; f32 F32; } WGPipe;
/* fzgx-allow: A2 GX write-gather FIFO */
volatile WGPipe __GXWGFifo : FZGX_ADDR_GXFIFO;

static inline void position(f32 x, f32 y, f32 z) {
    register volatile WGPipe *fifo = &__GXWGFifo; /* write-gather pipe: every store is a vertex component */
    fifo->F32 = x;
    fifo->F32 = y;
    fifo->F32 = z;
}

static inline void loadPositionMatrix(void *mtx, u32 index) {
    struct { void *matrix; u32 reserved[9]; } setup;
    setup.matrix = mtx;
    GXLoadPosMtxImm(mtx, index);
}

#define lbl_801A71C8 616.0f
#define lbl_801A71D8 0.0f
#define lbl_801A71F0 7.0f
#define lbl_801A71F4 140.0f
#define lbl_801A71F8 -1.0f
#define lbl_801A71FC 50.0f
#define lbl_801A7204 14.0f
#define lbl_801A7208 21.0f
#define lbl_801A7210 25.0f

static inline f32 scaleTicks(u32 step, u32 n) {
    return lbl_801A71C8 * ((f32)(n * step) / (f32)lbl_801A6C60);
}
#define SCALE(n) (lbl_801A71C8 * ((f32)(u32)(n) / (f32)lbl_801A6C60))
#define DATA(n) (*(f32 *)(p_lbl_8012B658 + (n)))

void fn_8003FF88(void) {
    u8 *p_lbl_8012B658;
    u32 v0;
    u32 v2;
    u32 v3;
    Record *records;
    Record *record;
    Descriptor *desc;
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
        lbl_801A6594 = lbl_801A71C8 / (f32)lbl_801A6590;
        total = SCALE(lbl_801A6C4C[lbl_801A6C44].ticks);
        loadPositionMatrix(lbl_80178C18, 0);
        fn_80035828(4, lbl_801A6598);
        fn_8003462C(0x80, 0, 4);
        position(lbl_801A71D8, lbl_801A71D8, lbl_801A71F8);
        position(lbl_801A71D8, lbl_801A6C64, lbl_801A71F8);
        position(lbl_801A71C8, lbl_801A6C64, lbl_801A71F8);
        position(lbl_801A71C8, lbl_801A71D8, lbl_801A71F8);
        fn_80035828(4, lbl_801A659C);
        GXSetLineWidth(12, 0);
        fn_8003462C(0xA8, 0, 8);
        position(DATA(0), DATA(4), lbl_801A71F8);
        position(DATA(8), DATA(12), lbl_801A71F8);
        position(DATA(16), DATA(20), lbl_801A71F8);
        position(DATA(24), DATA(28), lbl_801A71F8);
        position(DATA(32), DATA(36), lbl_801A71F8);
        position(DATA(40), DATA(44), lbl_801A71F8);
        position(DATA(48), DATA(52), lbl_801A71F8);
        position(DATA(56), DATA(60), lbl_801A71F8);
        if (lbl_801A6590 > 1) {
            fn_8003462C(0xA8, 0, (u16)((lbl_801A6590 - 1) * 2));
            for (j = 1; j < lbl_801A6590; j++) {
                x = scaleTicks(__OSCoreClock / 60, j);
                position(x, DATA(0x44), lbl_801A71F8);
                position(x, DATA(0x4C), lbl_801A71F8);
            }
        }
        fn_80035828(4, lbl_801A65A0);
        GXSetLineWidth(32, 0);
        fn_8003462C(0xA8, 0, 2);
        position(lbl_801A71D8, lbl_801A71D8, lbl_801A71F8);
        position(total, lbl_801A71D8, lbl_801A71F8);
        fn_80035828(4, lbl_801A65A8);
        fn_8003462C(0xA8, 0, 2);
        position(lbl_801A71D8, lbl_801A71D8, lbl_801A71F8);
        position(SCALE(lbl_801A6C4C[lbl_801A6C44].other), lbl_801A71D8, lbl_801A71F8);
        if ((s32)lbl_801A65F4 != 0) {
            height = lbl_801A71F0 + lbl_801A6C64;
            fn_80035828(4, lbl_801A65B0);
            fn_8003462C(0x80, 0, 4);
            position(lbl_801A71D8, height, lbl_801A71F8);
            position(lbl_801A71D8, lbl_801A71F4 + height, lbl_801A71F8);
            position(total, lbl_801A71F4 + height, lbl_801A71F8);
            position(total, height, lbl_801A71F8);
        }
        if ((s32)lbl_801A65F8 != 0) {
            height = lbl_801A71F0 + (lbl_801A71F4 + (lbl_801A71F0 + lbl_801A6C64));
            fn_80035828(4, lbl_801A65B4);
            fn_8003462C(0x80, 0, 4);
            position(lbl_801A71D8, height, lbl_801A71F8);
            position(lbl_801A71D8, lbl_801A71FC + height, lbl_801A71F8);
            position(total, lbl_801A71FC + height, lbl_801A71F8);
            position(total, height, lbl_801A71F8);
            fn_80035828(4, lbl_801A65AC);
            GXSetLineWidth(6, 0);
            fn_8003462C(0xA8, 0, 2);
            position(lbl_801A71D8, lbl_801A7210 + height, lbl_801A71F8);
            position(total, lbl_801A7210 + height, lbl_801A71F8);
        }
        if ((s32)lbl_801A65FC != 0) {
            height = lbl_801A7204 + (lbl_801A71FC + (lbl_801A71F4 + (lbl_801A71F0 + lbl_801A6C64)));
            fn_80035828(4, lbl_801A65B8);
            fn_8003462C(0x80, 0, 4);
            position(lbl_801A71D8, height, lbl_801A71F8);
            position(lbl_801A71D8, lbl_801A71FC + height, lbl_801A71F8);
            position(total, lbl_801A71FC + height, lbl_801A71F8);
            position(total, height, lbl_801A71F8);
        }
        if ((s32)lbl_801A6600[0] != 0) {
            height = lbl_801A71FC + (lbl_801A7208 + (lbl_801A71FC + (lbl_801A71F4 + (lbl_801A71F0 + lbl_801A6C64))));
            fn_80035828(4, lbl_801A65B8);
            fn_8003462C(0x80, 0, 4);
            position(lbl_801A71D8, height, lbl_801A71F8);
            position(lbl_801A71D8, lbl_801A71FC + height, lbl_801A71F8);
            position(total, lbl_801A71FC + height, lbl_801A71F8);
            position(total, height, lbl_801A71F8);
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
                    position(SCALE(record->start), (f32)y, lbl_801A71F8);
                    position(SCALE(record->end), (f32)y, lbl_801A71F8);
                    delta = record->value2C - record->value28;
                    if (delta != 0) {
                        x = SCALE(delta + record->start);
                        fn_80035828(4, lbl_801A65A8);
                        fn_8003462C(0xA8, 0, 2);
                        position(SCALE(record->start), (f32)y, lbl_801A71F8);
                        position(x, (f32)y, lbl_801A71F8);
                    }
                    if (record->value10 != 0) {
                        if (record->flag == 0) {
                            fn_80035828(4, lbl_801A65A4);
                            GXSetLineWidth(32, 0);
                            fn_8003462C(0xA8, 0, 2);
                            position(SCALE(record->valueC), lbl_801A6C64, lbl_801A71F8);
                            position(SCALE(record->value10), lbl_801A6C64, lbl_801A71F8);
                            fn_8003EC44(record);
                            fn_80035828(4, lbl_801A65AC);
                            GXSetLineWidth(6, 0);
                            fn_8003462C(0xA8, 0, 4);
                            position(SCALE(record->valueC), lbl_801A6C64, lbl_801A71F8);
                            position(SCALE(record->start), (f32)y, lbl_801A71F8);
                            position(SCALE(record->value10), lbl_801A6C64, lbl_801A71F8);
                            position(SCALE(record->end), (f32)y, lbl_801A71F8);
                        } else {
                            fn_80035828(4, lbl_801A65A4);
                            GXSetLineWidth(32, 0);
                            fn_8003462C(0xA8, 0, 2);
                            position(SCALE(record->value1C), lbl_801A6C64, lbl_801A71F8);
                            position(SCALE(record->value10), lbl_801A6C64, lbl_801A71F8);
                            fn_8003EC44(record);
                            fn_80035828(4, lbl_801A65AC);
                            GXSetLineWidth(6, 0);
                            fn_8003462C(0xA8, 0, 4);
                            position(SCALE(record->value1C), lbl_801A6C64, lbl_801A71F8);
                            position(SCALE(record->value18), (f32)y, lbl_801A71F8);
                            position(SCALE(record->value10), lbl_801A6C64, lbl_801A71F8);
                            position(SCALE(record->end), (f32)y, lbl_801A71F8);
                        }
                    }
                    break;
                case 0:
                    fn_80035828(4, desc->color);
                    GXSetLineWidth(32, 0);
                    fn_8003462C(0xA8, 0, 2);
                    y = (id + 1) * 7;
                    position(SCALE(record->start), (f32)y, lbl_801A71F8);
                    position(SCALE(record->end), (f32)y, lbl_801A71F8);
                    delta = record->value2C - record->value28;
                    if (delta != 0) {
                        x = SCALE(delta + record->start);
                        fn_80035828(4, lbl_801A65A8);
                        fn_8003462C(0xA8, 0, 2);
                        position(SCALE(record->start), (f32)y, lbl_801A71F8);
                        position(x, (f32)y, lbl_801A71F8);
                    }
                    break;
                case 2:
                    if (record->flag == 0) {
                        fn_80035828(4, lbl_801A65A4);
                        GXSetLineWidth(32, 0);
                        fn_8003462C(0xA8, 0, 2);
                        position(SCALE(record->valueC), lbl_801A6C64, lbl_801A71F8);
                        position(SCALE(record->value10), lbl_801A6C64, lbl_801A71F8);
                        fn_8003EC44(record);
                    } else {
                        fn_80035828(4, lbl_801A65A4);
                        GXSetLineWidth(32, 0);
                        fn_8003462C(0xA8, 0, 2);
                        position(SCALE(record->value1C), lbl_801A6C64, lbl_801A71F8);
                        position(SCALE(record->value10), lbl_801A6C64, lbl_801A71F8);
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
