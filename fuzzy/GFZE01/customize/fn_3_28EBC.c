/* Non-matching: best partial attempt (53.57% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

struct fn_3_28EBC_Copy88 { u32 a[22]; };
struct fn_3_28EBC_Packet {
    u32 color;
    f32 x, y, z;
    f32 a10, a14;
    f32 a18, a1c;
    u8 pad20[8];
    s16 angle;
    u8 pad2a[2];
    u32 flags;
    f32 scale;
    u8 pad38[0x18];
    void (*callback)(void);
};
struct fn_3_28EBC_lbl_3_rodata_768 {
    u8 pad_0[0x98];
    f64 unk_98;
};
extern struct fn_3_28EBC_lbl_3_rodata_768 lbl_3_rodata_768;
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A66A0;
extern void fn_3_2406C(void);
extern int fn_1_4F734(FontDrawPacket *);
extern f32 lbl_8006D188(u32);

void fn_3_28EBC(s16 x0, s16 y0, s16 z0, s16 a3, s16 a4, s16 a5, s32 a6, s16 a7, s16 a8) {
    struct fn_3_28EBC_Copy88 base;
    struct fn_3_28EBC_Packet *p;
    s16 z = z0;
    f32 fz = (f32)(s32)(z - 20);
    u32 cb = (u32)fn_3_2406C;
    s32 date;
    s32 rem;
    s32 deg;
    p = (struct fn_3_28EBC_Packet *)((u8 *)&base + 4);
    base = *(struct fn_3_28EBC_Copy88 *)((u8 *)&lbl_1_rodata_26F8 - 4);
    if (a4) {
        p->color = (u32)a6;
        p->x = (f32)(s32)x0; p->y = (f32)(s32)y0; p->z = fz;
        p->flags = 0x40a; p->callback = (void (*)(void))cb;
        p->scale = 1.0f;
        fn_1_4F734((FontDrawPacket *)p);
    }
    if (a5) {
        base = *(struct fn_3_28EBC_Copy88 *)((u8 *)&lbl_1_rodata_26F8 - 4);
        p->color = (u32)-30422;
        p->x = (f32)(s32)x0; p->y = (f32)(s32)y0; p->z = (f32)(s32)(z + 1);
        p->flags = 0x40a; p->callback = (void (*)(void))cb;
        p->scale = 1.0f;
        fn_1_4F734((FontDrawPacket *)p);
    }
    if (a5) {
        u32 days = lbl_801A66A0;
        u32 rday = days % 360;
        u32 qday = days / 360;
        p->color = (u32)-30472;
        p->x = (f32)(s32)x0;
        p->y = (f32)(s32)y0;
        p->z = (f32)(s32)(z + 1);
        p->a10 = (f32)(s32)x0;
        p->a14 = (f32)(s32)y0;
        date = (s32)((f32)rday * 182.04444885253906f);
        rem = (s32)((f32)qday * 182.04444885253906f);
        p->angle = (s16)date;
        deg = (s32)(f32)days;
        p->color = (u32)-30472;
        fn_1_4F734((FontDrawPacket *)p);
        base = *(struct fn_3_28EBC_Copy88 *)((u8 *)&lbl_1_rodata_26F8 - 4);
        p->color = (u32)-30473;
        p->x = (f32)(s32)x0; p->y = (f32)(s32)y0; p->z = fz;
        p->flags = 0x40a; p->callback = (void (*)(void))cb;
        p->scale = 1.0f;
        fn_1_4F734((FontDrawPacket *)p);
    }
    if (a7) {
        base = *(struct fn_3_28EBC_Copy88 *)((u8 *)&lbl_1_rodata_26F8 - 4);
        p->color = (u32)-30499;
        p->x = (f32)(s32)(x0 - 26);
        if (a7 > 1) p->x = (f32)(s32)(x0 - 28);
        p->y = (f32)(s32)(y0 - 36);
        p->z = (f32)(s32)z0;
        p->flags = 0x407; p->callback = (void (*)(void))cb;
        p->scale = 1.0f;
        fn_1_4F734((FontDrawPacket *)p);
    }
    if (a8) {
        base = *(struct fn_3_28EBC_Copy88 *)((u8 *)&lbl_1_rodata_26F8 - 4);
        p->color = (u32)-30499;
        p->x = (f32)(s32)(x0 + 26);
        if (a8 > 1) p->x = (f32)(s32)(x0 + 28);
        p->y = (f32)(s32)(y0 - 36);
        p->z = (f32)(s32)z0;
        p->flags = 0x800005; p->callback = (void (*)(void))cb;
        p->scale = 1.0f;
        fn_1_4F734((FontDrawPacket *)p);
    }
}
