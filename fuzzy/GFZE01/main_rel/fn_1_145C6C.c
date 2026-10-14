/* Non-matching: best partial attempt (78.32% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

typedef struct Sig_fn_1_5158C_FontDrawPacket Sig_fn_1_5158C_FontDrawPacket;
typedef struct { u32 a[22]; } Copy88;
typedef struct {
    u8 pad_0[0x11c]; f32 unk_11C;
    u8 pad_120[8]; f64 unk_128;
    u8 pad_130[0x60]; f32 unk_190; f32 unk_194;
    u8 pad_198[0x14]; f32 unk_1AC;
    u8 pad_1B0[0x70]; f32 unk_220;
    u8 pad_224[0x84]; f32 unk_2A8;
    u8 pad_2AC[0x178]; f32 unk_424; f32 unk_428;
    f32 unk_42C; f32 unk_430; f32 unk_434; f32 unk_438;
} Pool92C0;

extern Pool92C0 lbl_1_rodata_92C0;
extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_494DC(s16);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4A0D8(const char *);
extern f32 fn_1_4B068(s32);
extern u32 fn_1_12EF80(u32, void *, void *);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(Sig_fn_1_5158C_FontDrawPacket *, u32, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_1461C8(u32, u32);
extern void fn_1_5233C(void *, void *);

void fn_1_145C6C(s32 id, void *selection, f32 arg2) {
    Pool92C0 *pool;
    u8 index;
    u8 *row;
    Obj_1_data_2B0D4 *table;
    u32 *names;
    u32 *screen;
    s32 y;
    s32 iteration;
    s32 top;
    const char *name;
    f32 h;
    s32 next;
    const char *label;
    f32 h2;
    u16 a;
    s16 b;
    Copy88 packet;
    s32 f1;
    pool = &lbl_1_rodata_92C0;
    if (id == 10 || id == 8) {
        fn_1_49410();
        fn_1_495B0(0x80000000);
        fn_1_49738((void *)fn_1_5233C);
        fn_1_49748(pool->unk_190);
        index = *((u8 *)selection + 0x34);
        row = &lbl_1_data_2BD54[index * 0x18];
        table = &lbl_1_data_2B0D4;
        names = (u32 *)lbl_1_data_2AA24;
        screen = (u32 *)0x801A66B4;
        y = 320;
        iteration = 0;
        for (;;) {
            top = y - iteration / 2;
            fn_1_494DC(8);
            fn_1_4955C(pool->unk_11C, pool->unk_11C);
            if (iteration != 0) {
                fn_1_496FC((f32)top, pool->unk_428);
                fn_1_4AE0C((const char *)&lbl_1_data_42478);
            }
            name = (const char *)names[((u8 *)table)[index]];
            fn_1_494DC(8);
            fn_1_4955C(pool->unk_11C, pool->unk_11C);
            if (iteration != 0) {
                fn_1_496FC((f32)(top + 12), pool->unk_428);
                fn_1_4A0D8(name);
            }
            h = fn_1_4B068((s32)name);
            next = (s32)((f32)(12 + iteration) + h);
            fn_1_494DC(8);
            fn_1_4955C(pool->unk_11C, pool->unk_11C);
            if (iteration != 0) {
                fn_1_496FC((f32)(top + next), pool->unk_428);
                fn_1_4AE0C((const char *)&lbl_1_data_4247C);
            }
            label = (const char *)((u32 *)lbl_1_data_2BD54)[*screen];
            fn_1_494DC(42);
            fn_1_4955C(pool->unk_11C, pool->unk_11C);
            if (iteration != 0) {
                fn_1_496FC((f32)(top + next + 18), pool->unk_428);
                fn_1_4A0D8(label);
            }
            h2 = fn_1_4B068((s32)label);
            y = (s32)((f32)(next + 18) + h2);
            iteration++;
            if (iteration > 1) break;
        }

        fn_1_12EF80(*((u8 *)selection + 0x34), &a, &b);
        packet = *(Copy88 *)lbl_1_rodata_26F8;
        packet.a[0] = 0x9800;
        fn_1_51564(0, 0, 36, 36, 6, 1);
        fn_1_5158C((Sig_fn_1_5158C_FontDrawPacket *)&packet, packet.a[0], b, 0);
        *(f32 *)((u8 *)&packet + 4) = pool->unk_42C;
        *(f32 *)((u8 *)&packet + 8) = pool->unk_220;
        *(f32 *)((u8 *)&packet + 12) = pool->unk_1AC;
        fn_1_4F734((FontDrawPacket *)&packet);

        packet = *(Copy88 *)lbl_1_rodata_26F8;
        packet.a[0] = 0x9806;
        fn_1_51564(0, 0, 36, 36, 6, 1);
        fn_1_5158C((Sig_fn_1_5158C_FontDrawPacket *)&packet, packet.a[0], b, 0);
        *(f32 *)((u8 *)&packet + 4) = pool->unk_430;
        *(f32 *)((u8 *)&packet + 8) = pool->unk_220;
        *(f32 *)((u8 *)&packet + 12) = pool->unk_1AC;
        fn_1_4F734((FontDrawPacket *)&packet);

        packet = *(Copy88 *)lbl_1_rodata_26F8;
        f1 = id == 4 || id == 9 || id == 10 || id == 6;
        packet.a[0] = f1 ? 0x9804 : 0x9805;
        *(f32 *)((u8 *)&packet + 4) = pool->unk_424;
        *(f32 *)((u8 *)&packet + 8) = pool->unk_434;
        *(f32 *)((u8 *)&packet + 12) = pool->unk_194;
        packet.a[12] = 6;
        fn_1_4F734((FontDrawPacket *)&packet);

        packet = *(Copy88 *)lbl_1_rodata_26F8;
        packet.a[0] = 0x980B;
        *(f32 *)((u8 *)&packet + 4) = pool->unk_424;
        *(f32 *)((u8 *)&packet + 8) = pool->unk_438;
        *(f32 *)((u8 *)&packet + 12) = pool->unk_2A8;
        packet.a[12] = 6;
        fn_1_4F734((FontDrawPacket *)&packet);
    } else {
        fn_1_1461C8((u32)id, *((u8 *)selection + 0x34));
    }
}
