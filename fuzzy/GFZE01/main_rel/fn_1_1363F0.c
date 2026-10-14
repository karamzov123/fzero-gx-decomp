/* Non-matching: best partial attempt (96.64% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

struct fn_1_1363F0_Copy88 { u32 a[22]; };
extern s32 lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_8A10, lbl_1_rodata_8A14, lbl_1_rodata_8A18, lbl_1_rodata_8A1C;
extern const f32 lbl_1_rodata_8A20, lbl_1_rodata_861C, lbl_1_rodata_8A24, lbl_1_rodata_8A28;
extern const f32 lbl_1_rodata_8668, lbl_1_rodata_85E8, lbl_1_rodata_87AC, lbl_1_rodata_8A2C, lbl_1_rodata_863C;
extern const f64 lbl_1_rodata_8600;
extern u8 lbl_1_rodata_8A0C;
extern u8 lbl_1_data_28060[8288];
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16 index);
extern void fn_1_496FC(f32,f32);
extern u32 fn_1_12F118(void);
extern u8 *fn_1_36AD0(void);
extern void fn_1_14E9E4(u32,void *);
extern void fn_1_4966C(f32,f32);
extern void fn_1_49514(void* arg0);
extern void fn_1_4955C(f32,f32);
extern void fn_1_4954C(f32);
extern void fn_1_4AE0C(const char *,...);
extern void fn_1_136714(f32, f32, f32, s32, s32, s32);

static inline u32 fn_1_1363F0_operand(u32 right, u32 left) { return left * right; }
#pragma opt_lifetimes off
static inline u32 fn_1_1363F0_operand_(u32 right, u32 left) { left *= right; return left; }
#pragma opt_dead_assignments off
static inline void fn_1_1363F0_call_fn_1_136714(void * a7, s32 a6, s32 a5, s32 a4, s32 a3, f32 a2, f32 a1, f32 a0) { fn_1_136714(a0, a1, a2, a4, a5, a6); }
static inline u32 * fn_1_1363F0_read_pointer(struct fn_1_1363F0_Copy88 * owner) { return owner->a; }
u32 fn_1_1363F0(u32 arg0, s32 arg1, s32 arg2) {
    struct fn_1_1363F0_Copy88 packet;
    f32 info[4];
    struct Color { u32 value; } color, colorCopy;
    s32 total;
    s32 selected;
    u8 *base;
    u8 *car;
    s32 i;
    packet = *(struct fn_1_1363F0_Copy88 *)&lbl_1_rodata_26F8;
    packet.a[0] = 0x9A24;
    *(f32 *)&packet.a[1] = lbl_1_rodata_8A10;
    *(f32 *)&packet.a[2] = lbl_1_rodata_8A14;
    fn_1_4F734((FontDrawPacket *)&packet);
    packet = *(struct fn_1_1363F0_Copy88 *)&lbl_1_rodata_26F8;
    fn_1_1363F0_read_pointer(&packet)[0] = 0x9A25;
    *(f32 *)&packet.a[1] = lbl_1_rodata_8A18;
    *(f32 *)&packet.a[2] = lbl_1_rodata_8A14;
    fn_1_4F734((FontDrawPacket *)&packet);
    fn_1_49410();
    fn_1_494DC(0x22);
    fn_1_496FC(lbl_1_rodata_8A1C,lbl_1_rodata_8A14);
    selected = ((Obj_1_bss_8B3A0 *)((u8 *)&lbl_1_bss_8B3A0 + (s16)lbl_1_bss_8B3A0.unk_9E * 32))->unk_E;
    if (selected >= 41) {
        base = (u8 *)fn_1_12F118();
        if (base == fn_1_36AD0()) {
            car = base + fn_1_1363F0_operand_((0x81C0), ((s16)arg0));
        } else {
            car = base + fn_1_1363F0_operand((0x81C0), ((selected - 41)));
        }
        if (*(u32 *)car & 0x40000000) {
            total = 0;
            i = 0;
            while ((u32)(s16)i < 3) {
                fn_1_14E9E4(car[0x81A4 + i * 8], info);
                total = (s32)((f32)(s16)total + info[1]);
                i++;
            }
        } else {
            struct Stats { u32 flags; f32 value; u8 pad[0xAC]; };
            total = (s32)((struct Stats *)lbl_1_data_28060)[car[0x81A0]].value;
        }
    } else {
        struct Stats { u32 flags; f32 value; u8 pad[0xAC]; };
        total = (s32)((struct Stats *)lbl_1_data_28060)[selected].value;
    }
    color = *(struct Color *)&lbl_1_rodata_8A0C;
    fn_1_4966C(lbl_1_rodata_8A20,lbl_1_rodata_861C);
    colorCopy = color;
    fn_1_49514((u32 *)&colorCopy);
    if (arg1 != 0) {
        fn_1_49410();
        fn_1_4955C(lbl_1_rodata_8A24,lbl_1_rodata_8A28);
        fn_1_4966C(lbl_1_rodata_8668,lbl_1_rodata_861C);
        fn_1_4954C(lbl_1_rodata_85E8);
        fn_1_4AE0C((const char *)&lbl_1_data_41AC0);
    } else {
        fn_1_4AE0C((const char *)&lbl_1_data_41AC8,(s16)total);
    }
    if (arg2 != 0) {
        fn_1_1363F0_call_fn_1_136714(0, 407, 0x8F, 0x8F, (s16)total, lbl_1_rodata_863C, lbl_1_rodata_8A2C, lbl_1_rodata_87AC);
    }
    return (u32)((s16)((s16)total));
}
#pragma opt_dead_assignments reset

#pragma opt_lifetimes reset

