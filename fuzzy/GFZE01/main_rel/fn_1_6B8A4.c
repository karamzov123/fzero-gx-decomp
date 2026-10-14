/* Non-matching: best partial attempt (36.95% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect_car.h"

struct fn_1_6B8A4_lbl_1_rodata_2D70 {
    f32 unk_0; f32 unk_4; u8 pad_8[0x14]; f32 unk_1C; u8 pad_20[4];
    f32 unk_24; u8 pad_28[0x18]; f64 unk_40; u8 pad_48[0x18];
    f32 unk_60; u8 pad_64[0x18]; f32 unk_7C; u8 pad_80[0x10];
    f32 unk_90; f32 unk_94; u8 pad_98[0x20]; f32 unk_B8;
    u8 pad_BC[0x1C]; f32 unk_D8; u8 pad_DC[0x14]; f32 unk_F0;
    f32 unk_F4; u8 pad_F8[4]; f32 unk_FC; f64 unk_100; f64 unk_108;
};
extern struct fn_1_6B8A4_lbl_1_rodata_2D70 lbl_1_rodata_2D70;
extern u32 lbl_801A66A0;
extern u32 fn_1_58C4(void);
extern u32 fn_1_584AC(void);
extern s16 fn_1_58F50(const void *);
extern void lbl_8006DD14(u32, void *);
extern f32 lbl_8006D0B4(f32);
extern u8 *memset(u8 *, int, u32);

typedef struct {
    u8 pad[0x48];
    f32 x, y, z;
} Vec3_6B8A4;
typedef struct {
    u8 pad0[0x14];
    u32 a; u32 b; u32 c; u32 d; u32 e;
    u8 pad1[0x10];
    f32 x,y,z;
} Frame_6B8A4;
typedef struct {
    u8 pad0[0x14];
    u32 left[5];
    u8 pad1[0x18];
    f32 x,y,z;
    u8 pad2[0x14];
    u32 w;
    u8 pad3[0x24];
    f32 pos[3];
} Record_6B8A4;
typedef struct {
    u8 bytes[232];
} Packet_6B8A4;

void fn_1_6B8A4(u8 *car, f32 *delta) {
    u8 *data;
    Record_6B8A4 *rec;
    Packet_6B8A4 packet;
    u32 serial[12];
    s32 i;
    f32 speed2, magnitude, jitter, t, blend;
    f32 x, y, z;
    f64 d;
    data = *(u8 **)(car + 0x38);
    lbl_8006DD14((u32)(car + 0xB8), serial);
    *(u16 *)((u8 *)&packet + 0x1a) = 0;
    if ((s8)data[0x475] == -1) {
        u32 n = lbl_801A66A0;
        if (n - (((u32)(((u64)(u32)(0xCCCD0000 - 0x3333) * n) >> 32) >> 2) * 5) != 0)
            return;
    }
    if (fn_1_58C4() >= 2)
        return;
    for (i = 4; i > 0; --i) {
        rec = (Record_6B8A4 *)(data + 0x244 + (4-i)*0x5c);
        if ((*(u32 *)rec & 2) != 0)
            continue;
        speed2 = car[0]; /* replaced below */
        x = *(f32 *)(car + 0x48);
        y = *(f32 *)(car + 0x4c);
        z = *(f32 *)(car + 0x50);
        speed2 = x*x + y*y + z*z;
        if (speed2 > lbl_1_rodata_2D70.unk_FC)
            speed2 = lbl_1_rodata_2D70.unk_FC;
        if (packet.bytes[0x1a] == 0) {
            memset(packet.bytes, 0, sizeof(packet.bytes));
            *(s16 *)(packet.bytes + 0x18) = *(s16 *)(car + 0x18);
            *(u16 *)(packet.bytes + 0x0c) = 24;
            *(u16 *)(packet.bytes + 0x1a) = 1;
            *(u32 *)(packet.bytes + 0x34) = lbl_1_bss_38458->unk_8;
        }
        x *= lbl_1_rodata_2D70.unk_90;
        y *= lbl_1_rodata_2D70.unk_90;
        z *= lbl_1_rodata_2D70.unk_90;
        jitter = lbl_1_rodata_2D70.unk_D8;
        if (i == 3 || i == 1)
            jitter *= -1.0f;
        x += delta[0] * jitter; y += delta[1] * jitter; z += delta[2] * jitter;
        magnitude = lbl_8006D0B4(x*x + y*y + z*z);
        t = lbl_1_rodata_2D70.unk_60 * magnitude;
        x += t * ((f32)(fn_1_584AC() & 0xffff) / lbl_1_rodata_2D70.unk_24 - lbl_1_rodata_2D70.unk_1C);
        y += t * ((f32)(fn_1_584AC() & 0xffff) / lbl_1_rodata_2D70.unk_24 - lbl_1_rodata_2D70.unk_1C);
        z += t * ((f32)(fn_1_584AC() & 0xffff) / lbl_1_rodata_2D70.unk_24 - lbl_1_rodata_2D70.unk_1C);
        {
            f32 a=*(f32 *)(data+0x27c), b=*(f32 *)(data+0x280), c=*(f32 *)(data+0x284);
            f32 dot=x*a+y*b+z*c;
            x=x-dot*a+a*lbl_1_rodata_2D70.unk_90;
            y=y-dot*b+b*lbl_1_rodata_2D70.unk_90;
            z=z-dot*c+c*lbl_1_rodata_2D70.unk_90;
        }
        {
            f32 p0=*(f32 *)(data+0x258), p1=*(f32 *)(data+0x25c), p2=*(f32 *)(data+0x260);
            f32 q0=*(f32 *)(data+0x268), q1=*(f32 *)(data+0x26c), q2=*(f32 *)(data+0x270);
            magnitude=lbl_8006D0B4((p0-q0)*(p0-q0)+(p1-q1)*(p1-q1)+(p2-q2)*(p2-q2));
            blend=magnitude;
        }
        d = 0.0;
        while (blend > d) {
            f32 u=blend/magnitude, v=1.0f-u;
            packet.bytes[0x60]=(u8)(x*u + (*(f32 *)(data+0x258))*v);
            {
                f32 cr=lbl_1_rodata_2D70.unk_F4*(speed2*((f32)(fn_1_584AC()&0xffff)/lbl_1_rodata_2D70.unk_24));
                *(s32 *)(packet.bytes+0x10)=(s32)(lbl_1_rodata_2D70.unk_7C + cr)*lbl_1_rodata_2D70.unk_B8;
            }
            fn_1_584AC();
            fn_1_58F50(&packet);
            blend -= 0.2;
            d=0.0;
        }
    }
}
