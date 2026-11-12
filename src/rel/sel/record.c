#include "types.h"

/* fzgx:begin fn_10_26554 */
extern u8 lbl_10_bss_55CE0;
extern char lbl_10_data_6BD0[9];
extern char lbl_10_data_6BDC[19];

extern void fn_1_12EF80(u8, s16 *, s16 *);
extern void fn_1_FA1D8(s16, s16, void *);
extern int fn_1_B7E98(int);
extern void fn_1_F7954(void);
extern void fn_80008BA8(void *, const void *, u32);
extern void OSPanic(const char *, int, const char *, ...);
extern void fn_1_B7CE4(int, void *);
extern void fn_1_AA6D8(int, int, void *);

extern u8 lbl_1_bss_7F0C0[];
extern u32 lbl_1_bss_718C0;
extern u8 lbl_1_bss_8B3A0[];
extern u8 lbl_1_bss_718E0;

static inline void fn_10_26554_call_fn_1_AA6D8(void * a3, void * a2, int a1, int a0) { fn_1_AA6D8(a0, a1, a2); }
void fn_10_26554(void) {
    s16 b;
    u8 work[0x100];
    s16 a;
    u8 *p;

    fn_1_12EF80(lbl_10_bss_55CE0, &b, &a);
    fn_1_FA1D8(b, a, (u8 *)lbl_1_bss_7F0C0 + (b * 6 + a) * 0x180 + 0xf8);
    if (fn_1_B7E98(0) != 0) {
        fn_1_F7954();
        p = (u8 *)lbl_1_bss_718C0 + 4;
        fn_80008BA8(p, (u8 *)lbl_1_bss_8B3A0 + 0x9f, 4);
        fn_80008BA8(p + 4, (u8 *)lbl_1_bss_8B3A0 + 0x8c, 6);
        fn_80008BA8(p + 0xa, (u8 *)lbl_1_bss_8B3A0 + 0xc, 0x80);
        if ((u32)((p + 0x8a) - ((u8 *)lbl_1_bss_718C0 + 4)) != 0x8a) {
            OSPanic(lbl_10_data_6BD0, 0x184, lbl_10_data_6BDC);
        }
        fn_1_B7CE4(1, work);
{
    u8 data[0x24];
        memset(data, 0, 0x24);
        data[0] = 1;
        *(u32 *)(data + 4) = 4;
        *(void **)(data + 0xc) = &lbl_1_bss_718E0;
        *(void **)(data + 8) = work;
        fn_10_26554_call_fn_1_AA6D8(&lbl_1_bss_718E0, data, 0, 0);
}
    }
}
/* fzgx:end fn_10_26554 */

/* fzgx:begin fn_10_266AC noprologue */
#include "types.h"
#include "rel/sel/globals.h"
#include "rel/sel/name_entry.h"


extern u8 lbl_10_bss_55CDC;
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_A8F78(void);
extern void fn_1_48140(int value);
extern void fn_1_412A0(int value);
extern u8 fn_1_B7C00(void);
extern u8 fn_10_26434(void);
extern void fn_10_26554(void);
extern void fn_1_14BD94(void *);
extern void fn_10_26424(void);
extern u16 lbl_1_bss_9F8[5];
extern u8 lbl_1_bss_8B3A0[0x9f];
extern void fn_1_A2D84(void *);
extern void fn_1_14BCBC(void *, u8);
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern s16 fn_1_12EF24(s16, s16);
extern s32 fn_1_F89E4(u8);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_1555B0(u8);
extern void fn_1_47F74(s32);
extern void fn_1_15555C(void);
extern void fn_1_14BD74(void);

#include "font.h"

struct fn_10_266AC_pool {
    u8 pad_0[0x38];
    f32 unk_38, unk_3C, unk_40, unk_44, unk_48, unk_4C, unk_50;
    f32 unk_54, unk_58, unk_5C, unk_60, unk_64, unk_68, unk_6C;
    u8 pad_70[0x38];
    u32 unk_A8;
    f32 unk_AC, unk_B0, unk_B4;
};
extern struct fn_10_266AC_pool lbl_10_rodata_1D70;
extern FontDrawPacket lbl_1_rodata_26F8;
extern u32 lbl_801A66B4;
extern u32 fn_10_261E4(u32, u32);
extern u32 fn_1_4AEC0(u32);
extern u8 fn_1_B7C00(void);
extern void fn_1_49410(void);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AEB4(f32);
extern void fn_1_4FD64(void);
extern void fn_1_50164(void *, f32, f32, f32, f32);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800371F8(s32, void *);
extern void fn_8007245C(u32);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8, s32, u8);

void fn_10_266AC(void) {
    FontDrawPacket packet;
    u32 color;
    struct fn_10_266AC_pool *p = &lbl_10_rodata_1D70;
    u32 str;
    if (fn_1_B7C00() != 0 || lbl_10_bss_55CE1 != 0) {
    fn_1_4FD64();
    fn_80074918(0, 7, 0);
    fn_80074788(1);
    fn_80074660(0);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 255, 255, 4);
    fn_80072C24(0, 15, 15, 15, 2);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 1);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_80072864(2);
    fn_8007245C(512);
    color = p->unk_A8;
    fn_800371F8(1, (void *)&color);
    fn_8003462C(128, 7, 4);
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_6C;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_6C;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_64;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_AC;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_6C;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_64;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_AC;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_B0;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_64;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_6C;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_B0;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(volatile f32 *)((u8 *)0xCC010000 - 32768) = p->unk_64;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    }
    if (lbl_10_bss_55CE1 != 0) {
    packet = lbl_1_rodata_26F8;
    packet.image = 2;
    packet.x = p->unk_38;
    packet.y = p->unk_3C;
    packet.z = p->unk_40;
    packet.flags = 10;
    fn_1_50164((void *)&packet, p->unk_44, p->unk_48, p->unk_4C, p->unk_50);
    str = ((u32 *)lbl_10_data_6B2C)[lbl_801A66B4];
    fn_1_4AEC0(1);
    fn_1_4AEB4(p->unk_54);
    fn_1_49410();
    fn_1_4955C(p->unk_58, p->unk_58);
    fn_1_4954C(p->unk_5C);
    fn_1_495B0(0x80000000);
    fn_1_49590(p->unk_60);
    fn_1_495C8(9);
    fn_1_496FC(p->unk_38, p->unk_B4);
    fn_1_4966C(p->unk_64, p->unk_68);
    fn_1_4A0D8((const char *)str);
    fn_1_4AEC0(0);
    fn_1_4AEB4(p->unk_6C);
    fn_10_261E4(0x118, lbl_10_bss_55CE2);
    }
}
/* fzgx:end fn_10_266AC */
