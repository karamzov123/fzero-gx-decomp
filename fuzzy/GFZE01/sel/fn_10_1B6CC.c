/* Non-matching: best partial attempt (97.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

typedef struct Packet1D314 {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8;
    u32 unk_C;
    u32 unk_10;
    u16 unk_14;
    u32 unk_18;
    u8 pad_1C[4];
    u16 unk_20;
    u16 unk_22;
    u16 unk_24;
    u16 unk_26;
    u16 unk_28;
    u16 unk_2A;
    u16 unk_2C;
    s16 unk_2E;
    u8 pad_30[12];
    u8 unk_3C;
    u8 unk_3D;
    u8 unk_3E;
    u8 unk_3F;
    u8 unk_40;
    u8 unk_41;
    u8 pad_42[1];
    char text[16];
    u8 unk_53;
} Packet1D314;

struct fn_10_1B6CC_lbl_10_rodata_158 {
    u8 pad_0[0x44];
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    u8 pad_54[0x4];
    f32 unk_58;
    u8 pad_5C[0x34];
    f64 unk_90;
    u8 pad_98[0x11C];
    f32 unk_1B4;
    u8 pad_1B8[0x64];
    f32 unk_21C;
    u8 pad_220[0x40];
    f32 unk_260;
    u8 pad_264[0x40];
    f32 unk_2A4;
    u8 pad_2A8[0x48];
    f32 unk_2F0;
    u8 pad_2F4[0x94];
    f32 unk_388;
    u8 pad_38C[0x1C];
    f32 unk_3A8;
    u8 pad_3AC[0xE8];
    f32 unk_494;
    u8 pad_498[0x1BC];
    f32 unk_654;
    u8 pad_658[0x518];
    f32 unk_B70;
    u8 pad_B74[0x3E0];
    f32 unk_F54;
    u8 pad_F58[0x1C];
    u32 unk_F74;
    f32 unk_F78;
    f32 unk_F7C;
    f32 unk_F80;
    f32 unk_F84;
    f32 unk_F88;
    f32 unk_F8C;
    f32 unk_F90;
    f32 unk_F94;
    f32 unk_F98;
    f32 unk_F9C;
    f32 unk_FA0;
    f32 unk_FA4;
    f32 unk_FA8;
    f32 unk_FAC;
    f32 unk_FB0;
    f32 unk_FB4;
    f32 unk_FB8;
    f32 unk_FBC;
    f32 unk_FC0;
    f32 unk_FC4;
    f32 unk_FC8;
    f32 unk_FCC;
    f32 unk_FD0;
    f32 unk_FD4;
};

typedef struct SelState {
    u8 pad_00[0x94];
    u32 flags;
    u32 bits;
    u8 pad_9c[8];
    u8 *items;
} SelState;

extern int fn_1_4F734(FontDrawPacket *);
extern int sprintf(char *, const char *, ...);
extern s16 lbl_1_bss_962;
extern u8 lbl_10_data_D00[];
extern struct fn_10_1B6CC_lbl_10_rodata_158 lbl_10_rodata_158;
extern SelState lbl_1_bss_8B3A0;
extern u32 lbl_1_data_418D4[];
extern u32 lbl_801A66A0;
extern s32 lbl_801A66B4;
extern s16 lbl_801A66C0[1];
extern u32 fn_10_1D314(void *);
extern u32 fn_10_21978(void);
extern s32 fn_10_21C20(s16, s16);
extern FontDrawPacket lbl_1_rodata_26F8;
extern void fn_10_1E398(void);
extern void fn_1_133DBC(void *);
extern void fn_1_134AD4(void);
extern void fn_1_1380F0(void *);
extern void fn_1_13B328(u32, s32);
extern void fn_1_13DC54(void);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(void *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);

static inline f32 fn_10_1B6CC_read_pointer(struct fn_10_1B6CC_lbl_10_rodata_158 * owner) { return owner->unk_388; }
#pragma opt_common_subs off
static inline f32 fn_10_1B6CC_read_pointer_(struct fn_10_1B6CC_lbl_10_rodata_158 * owner) { return owner->unk_F84; }
#pragma opt_dead_assignments off
static inline f32 fn_10_1B6CC_read_pointer__(struct fn_10_1B6CC_lbl_10_rodata_158 * owner) { return owner->unk_4C; }
static inline const char * *fn_10_1B6CC_array_read(const char * *array) { return array; }
#pragma opt_loop_invariants off
void fn_10_1B6CC(void) {
    const char **labels;
    u8 *p_lbl_10_data_D00;
    struct fn_10_1B6CC_lbl_10_rodata_158 *p_lbl_10_rodata_158;
    f32 v2;
    f32 v8;
    FontDrawPacket loc_5C;
    Packet1D314 loc_8;
    s32 acc;
    s32 v43;
    s32 i;
    u32 v44;
    Packet1D314 *p;

    p_lbl_10_data_D00 = lbl_10_data_D00;
    p_lbl_10_rodata_158 = &lbl_10_rodata_158;
    fn_1_133DBC((void *)1);
    fn_1_134AD4();
    fn_1_13DC54();
    fn_1_13B328(0, 1);
    if (lbl_1_bss_962 == 21) {
        if (lbl_1_bss_8B3A0.items[25] != 0) {
            fn_1_1380F0((void *)lbl_1_data_418D4[lbl_801A66B4]);
        } else {
            fn_1_1380F0((void *)fn_10_21C20(2, (s16)lbl_801A66B4));
        }
    } else {
        fn_1_1380F0((void *)fn_10_21C20(3, (s16)lbl_801A66B4));
    }
    fn_10_1E398();
    fn_1_49410();
    fn_1_496FC(p_lbl_10_rodata_158->unk_58, p_lbl_10_rodata_158->unk_F78);
    fn_1_495C8((void *)1);
    fn_1_4955C(p_lbl_10_rodata_158->unk_494, p_lbl_10_rodata_158->unk_494);
    fn_1_49590(p_lbl_10_rodata_158->unk_48);
    fn_1_495B0(0x80000000);
    labels = (const char **)(p_lbl_10_data_D00 + 0x55dc);
    fn_1_4AE0C((const char *)(p_lbl_10_data_D00 + 0x5134), fn_10_1B6CC_array_read(labels)[lbl_801A66B4]);
    fn_10_21978();

    if ((*((lbl_801A66C0) + (0))) < 30) {
        v2 = (f32)lbl_801A66C0[0] / p_lbl_10_rodata_158->unk_654;
        v2 = v2 * v2;
        v2 = v2 * v2;
    } else {
        v2 = p_lbl_10_rodata_158->unk_44;
    }

    loc_5C = lbl_1_rodata_26F8;
    loc_5C.y = p_lbl_10_rodata_158->unk_F7C;
    loc_5C.image = 0x10000 - 25063;
    loc_5C.z = p_lbl_10_rodata_158->unk_F80;
    loc_5C.alpha = p_lbl_10_rodata_158->unk_3A8;

    if (lbl_801A66A0 % 120 > 60) {
        v8 = p_lbl_10_rodata_158->unk_2A4 * (p_lbl_10_rodata_158->unk_44 - v2);
        loc_5C.flags = 9;
        loc_5C.u0 = fn_10_1B6CC_read_pointer__(p_lbl_10_rodata_158);
        loc_5C.u1 = fn_10_1B6CC_read_pointer_(p_lbl_10_rodata_158);
        loc_5C.scale_x = fn_10_1B6CC_read_pointer_(p_lbl_10_rodata_158);
        loc_5C.x = fn_10_1B6CC_read_pointer(p_lbl_10_rodata_158) + v8;
        fn_1_4F734(&loc_5C);

        loc_5C.flags = 9;
        loc_5C.u0 = p_lbl_10_rodata_158->unk_F88;
        loc_5C.u1 = p_lbl_10_rodata_158->unk_44;
        loc_5C.scale_x = p_lbl_10_rodata_158->unk_F8C;
        loc_5C.x = p_lbl_10_rodata_158->unk_260 + v8;
        fn_1_4F734(&loc_5C);

        loc_5C.flags = 9;
        loc_5C.u0 = p_lbl_10_rodata_158->unk_F90;
        loc_5C.u1 = p_lbl_10_rodata_158->unk_F94;
        loc_5C.scale_x = p_lbl_10_rodata_158->unk_F98;
        loc_5C.x = p_lbl_10_rodata_158->unk_1B4 + v8;
        fn_1_4F734(&loc_5C);

        loc_5C.flags = 9;
        loc_5C.u0 = p_lbl_10_rodata_158->unk_F9C;
        loc_5C.u1 = p_lbl_10_rodata_158->unk_F88;
        loc_5C.scale_x = p_lbl_10_rodata_158->unk_FA0;
        loc_5C.x = p_lbl_10_rodata_158->unk_FA4 + v8;
        fn_1_4F734(&loc_5C);
    } else {
        loc_5C.flags = 10;
        loc_5C.u1 = p_lbl_10_rodata_158->unk_F9C;
        loc_5C.scale_x = p_lbl_10_rodata_158->unk_F9C;
        loc_5C.x = p_lbl_10_rodata_158->unk_58 + (f32)(p_lbl_10_rodata_158->unk_2A4 * (p_lbl_10_rodata_158->unk_44 - v2));
        fn_1_4F734(&loc_5C);
    }

    loc_5C = lbl_1_rodata_26F8;
    loc_5C.image = 0x10000 - 25052;
    loc_5C.flags = 6;
    loc_5C.z = p_lbl_10_rodata_158->unk_FA8;
    loc_5C.scale_y = p_lbl_10_rodata_158->unk_FAC;
    loc_5C.x = p_lbl_10_rodata_158->unk_B70;
    loc_5C.y = p_lbl_10_rodata_158->unk_FB0;
    fn_1_4F734(&loc_5C);
    loc_5C.y = p_lbl_10_rodata_158->unk_FB4;
    fn_1_4F734(&loc_5C);
    loc_5C.rotation_z = -32768;
    loc_5C.x = p_lbl_10_rodata_158->unk_21C;
    loc_5C.y = p_lbl_10_rodata_158->unk_FB8;
    fn_1_4F734(&loc_5C);
    loc_5C.y = p_lbl_10_rodata_158->unk_FBC;
    fn_1_4F734(&loc_5C);

    loc_5C = lbl_1_rodata_26F8;
    loc_5C.image = 0x10000 - 25052;
    loc_5C.flags = 6;
    loc_5C.z = p_lbl_10_rodata_158->unk_FC0;
    loc_5C.scale_y = p_lbl_10_rodata_158->unk_FC4;
    loc_5C.x = p_lbl_10_rodata_158->unk_B70;
    loc_5C.y = p_lbl_10_rodata_158->unk_F54;
    *(u32 *)((u8 *)&loc_5C + 56) = p_lbl_10_rodata_158->unk_F74;
    fn_1_4F734(&loc_5C);
    loc_5C.rotation_z = -32768;
    loc_5C.x = p_lbl_10_rodata_158->unk_21C;
    loc_5C.y = p_lbl_10_rodata_158->unk_FC8;
    fn_1_4F734(&loc_5C);

    loc_5C = lbl_1_rodata_26F8;
    loc_5C.image = 0x10000 - 25061;
    loc_5C.flags = 10;
    loc_5C.z = p_lbl_10_rodata_158->unk_FA8;
    loc_5C.alpha = p_lbl_10_rodata_158->unk_50;
    loc_5C.x = p_lbl_10_rodata_158->unk_FCC;
    loc_5C.y = p_lbl_10_rodata_158->unk_FD0;
    fn_1_4F734(&loc_5C);

    loc_5C.flags &= ~0x80000;
    loc_5C.flags |= 0x100000;
    loc_5C.x = p_lbl_10_rodata_158->unk_FCC;
    loc_5C.y = p_lbl_10_rodata_158->unk_2F0;
    fn_1_4F734(&loc_5C);

    loc_5C.flags |= 0x80000;
    loc_5C.flags &= ~0x100000;
    loc_5C.x = p_lbl_10_rodata_158->unk_FD4;
    loc_5C.y = p_lbl_10_rodata_158->unk_FD0;
    fn_1_4F734(&loc_5C);

    loc_5C.flags |= 0x80000;
    loc_5C.flags |= 0x100000;
    loc_5C.x = p_lbl_10_rodata_158->unk_FD4;
    loc_5C.y = p_lbl_10_rodata_158->unk_2F0;
    fn_1_4F734(&loc_5C);

    p = &loc_8;
    i = 0;
    acc = 0;
    do {
        v43 = 4 - i;
        v44 = i;
        v44 = v44 + 2;
        p->unk_0 = i;
        p->unk_4 = i;
        p->unk_20 = (i * i) * 3;
        p->unk_8 = 1;
        p->unk_C = 1;
        p->unk_10 = 1;
        p->unk_14 = 1;
        p->unk_53 = 0;
        p->unk_18 = acc;
        p->unk_22 = (v43 & 0x7FFF) << 1;
        p->unk_24 = (v43 & 0x3FFF) << 2;
        p->unk_3C = 0;
        p->unk_26 = v43 * 3;
        p->unk_3D = v44;
        p->unk_28 = (v43 & 0x7FFF) << 1;
        p->unk_3E = (v44 & 0x7F) << 1;
        p->unk_2A = v43;
        p->unk_3F = v44 * 3;
        p->unk_2C = 0;
        p->unk_40 = (v44 & 0x3F) << 2;
        p->unk_2E = -v43;
        p->unk_41 = v44 * 5;
        sprintf(p->text, (const char *)(p_lbl_10_data_D00 + 0x43));
        fn_10_1D314(p);
        i++;
        acc += 11234;
    } while (i < 2);
}
#pragma opt_loop_invariants reset

#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

