/* Non-matching: best partial attempt (25.09% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ranking.h"
#include "font.h"

extern f32 lbl_1_rodata_D920[14];
extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_49410(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_5233C(void);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_495C8(u8);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49514(u32 *);
extern void fn_1_494DC(s16);
extern void fn_1_4965C(u8);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_495A0(f32);
extern void fn_1_4A0D8(const char *);

typedef Obj_1_bss_8F568_AtC Entry;

static void draw_packet(u8 *p, s16 x, s16 y, f32 value, f32 scale,
                        s32 width, s32 height, int use_setup) {
    u32 *w=(u32 *)p;
    u32 i;
    for (i=0;i<22;i++) w[i]=(u32)lbl_1_rodata_26F8[i];
    *(f32 *)(p+4)=(f32)x;
    *(f32 *)(p+8)=(f32)y;
    *(f32 *)(p+12)=0.1f;
    *(f32 *)(p+0x2c)=scale;
    *(u32 *)(p+0x30)=10;
    if (use_setup) fn_1_51678((FontDrawPacket *)p,0x100,0,0,(s16)width,(s16)height);
    fn_1_4F734((FontDrawPacket *)p);
}
void fn_1_157FC8(u32 arg0, u32 arg1, s32 arg2) {
    Entry *entry=lbl_1_bss_8F568.unk_C;
    s32 x, y;
    f64 cvt=4503601774854144.0;
    while (*(s16 *)entry != -2) {
        f32 t=(f32)arg2;
        f32 limit=lbl_1_bss_8F568.unk_4;
        if (t <= limit) {
            entry++;
            continue;
        }
        arg2 += entry->unk_2;
        if ((f32)arg2 <= limit) {
            entry++;
            continue;
        }
        x = entry->unk_4;
        y = entry->unk_6;
        {
            f32 scale=0.5f;
            f32 n=30.0f-t;
            if (n <= 30.0f) scale=n/30.0f;
            n=(f32)arg2-limit;
            if (n < 30.0f && n > 0.0f) scale=n/30.0f;
            fn_1_49410();
            switch (entry->unk_10) {
            case 0:
                fn_1_496FC((f32)entry->unk_4,(f32)entry->unk_6);
                fn_1_495B0(0xC0000000);
                fn_1_49738((u32)fn_1_5233C);
                fn_1_49748(5.0f);
                fn_1_495C8((u8)entry->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C((f32)entry->unk_C/24.0f,(f32)entry->unk_E/24.0f);
                *(u32 *)&arg0=entry->unk_14; fn_1_49514(&arg0);
                break;
            case 1:
                fn_1_494DC(5);
                fn_1_496FC((f32)entry->unk_4,(f32)entry->unk_6);
                fn_1_495B0(0xC0000000);
                fn_1_495C8((u8)entry->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C((f32)entry->unk_C/18.0f,(f32)entry->unk_E/18.0f);
                *(u32 *)&arg0=entry->unk_14; fn_1_49514(&arg0);
                break;
            case 2:
                fn_1_496FC((f32)entry->unk_4,(f32)entry->unk_6);
                fn_1_495B0(0xC0000000);
                fn_1_49738((u32)fn_1_5233C);
                fn_1_49748(3.0f);
                fn_1_495C8((u8)entry->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C((f32)entry->unk_C/24.0f,(f32)entry->unk_E/24.0f);
                *(u32 *)&arg0=entry->unk_14; fn_1_49514(&arg0);
                break;
            case 6:
                fn_1_496FC((f32)entry->unk_4,(f32)entry->unk_6);
                fn_1_495B0(0xC0000000);
                fn_1_4965C(2);
                fn_1_49738((u32)fn_1_5233C);
                fn_1_49748(1.0f);
                fn_1_495C8((u8)entry->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C((f32)entry->unk_C/24.0f,(f32)entry->unk_E/24.0f);
                *(u32 *)&arg0=entry->unk_14; fn_1_49514(&arg0);
                break;
            case 3: {
                u8 packet[0x58];
                draw_packet(packet,entry->unk_4,entry->unk_6,0,scale,120,16,1);
                break;
            }
            case 4: {
                u8 packet[0x58];
                draw_packet(packet,entry->unk_4,entry->unk_6,0,scale,248,16,1);
                break;
            }
            case 5: {
                u8 packet[0x58];
                draw_packet(packet,entry->unk_4,entry->unk_6,0,scale,0,0,0);
                break;
            }
            default: break;
            }
        }
        fn_1_495A0(0.5f);
        fn_1_4A0D8((const char *)entry->unk_18);
        x += entry->unk_20;
        y += entry->unk_22;
        entry++;
        if (entry[-1].unk_1C == -1) break;
    }
    if ((f32)entry->unk_2 < lbl_1_bss_8F568.unk_4) *(u32 *)((u8 *)&lbl_1_bss_8F568 + 0x10)=0;
}
