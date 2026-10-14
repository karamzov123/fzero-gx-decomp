/* Non-matching: best partial attempt (49.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

struct fn_1_13ABA8_lbl_1_rodata_8C14 {
    u32 unk_0, unk_4, unk_8, unk_C, unk_10, unk_14;
};
struct fn_1_13ABA8_copy { u32 words[22]; };
struct fn_1_13ABA8_lbl_1_rodata_8C2C {
    u32 unk_0, unk_4, unk_8, unk_C, unk_10, unk_14;
};
extern struct fn_1_13ABA8_lbl_1_rodata_8C14 lbl_1_rodata_8C14;
extern struct fn_1_13ABA8_lbl_1_rodata_8C2C lbl_1_rodata_8C2C;
extern f32 lbl_1_rodata_26F8[];
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8C44;
extern const f32 lbl_1_rodata_8C48;
extern const f32 lbl_1_rodata_85F0;

extern s32 lbl_801A66B4;
extern int fn_1_4F734(void *);
extern u8 fn_1_B7C00(void);
extern void fn_1_49410(void);
extern void fn_1_495C8(int);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern s32 fn_1_13B24C(s32, s32, s32, s32, u32);
extern u32 fn_1_13F7F8(s16, s16);

#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_common_subs off
void fn_1_13ABA8(u32 arg0) {
    u8 *text = (u8 *)&lbl_1_data_40F58;
    u32 local[34];
    u32 bits = 0x80000000;
    u32 previous = 0;
    s32 pass;
    s32 i;
    s32 y;
    u32 mask;
    u32 index;
    s32 baseY;
    struct { s32 value; } ret;
    struct { u32 id; f32 x, y, z; } packet;

    local[6] = lbl_1_rodata_8C14.unk_0;
    local[7] = lbl_1_rodata_8C14.unk_4;
    local[8] = lbl_1_rodata_8C14.unk_8;
    local[9] = lbl_1_rodata_8C14.unk_C;
    local[10] = lbl_1_rodata_8C14.unk_10;
    local[11] = lbl_1_rodata_8C14.unk_14;
    local[0] = lbl_1_rodata_8C2C.unk_0;
    local[1] = lbl_1_rodata_8C2C.unk_4;
    local[2] = lbl_1_rodata_8C2C.unk_8;
    local[3] = lbl_1_rodata_8C2C.unk_C;
    local[4] = lbl_1_rodata_8C2C.unk_10;
    local[5] = lbl_1_rodata_8C2C.unk_14;
    *(struct fn_1_13ABA8_copy *)&local[12] =
        *(struct fn_1_13ABA8_copy *)lbl_1_rodata_26F8;
    packet.id = 0x9a02;
    packet.x = lbl_1_rodata_861C;
    packet.y = lbl_1_rodata_8C44;
    packet.z = lbl_1_rodata_8C48;
    fn_1_4F734(&packet);
    if (fn_1_B7C00() == 0) {
        fn_1_49410();
        fn_1_495C8(8);
        fn_1_49590(lbl_1_rodata_85F0);
        fn_1_495B0(0x80000000);
        index = 0;
        for (pass = 0; pass <= 1; pass++) {
            u32 n = *(u32 *)&lbl_801A66B4;
            u32 font = local[6 + n];
            baseY = 320 - ((s32)(previous + (previous >> 31)) >> 1);
            mask = arg0;
            y = 0;
            while (mask != 0) {
                u32 bitIndex = __cntlzw(mask);
                s32 caseIndex = bitIndex & 0xff;
                switch (caseIndex) {
                case 0: index = fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, 0x15, (u32)(text + 0xbb8)); y += index; ret.value = fn_1_13F7F8(5, (s16)lbl_801A66B4); y += fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, font, ret.value); break;
                case 1: index = fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, 0x15, (u32)(text + 0xbd8)); y += index; ret.value = fn_1_13F7F8(4, (s16)lbl_801A66B4); y += fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, font, ret.value); break;
                case 2: index = fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, 0x15, (u32)(text + 0xbd8)); y += index; ret.value = fn_1_13F7F8(6, (s16)lbl_801A66B4); y += fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, font, ret.value); break;
                case 3: index = fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, 0x15, (u32)(text + 0xbdc)); y += index; ret.value = fn_1_13F7F8(7, (s16)lbl_801A66B4); y += fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, font, ret.value); break;
                case 4: index = fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, 0x15, (u32)(text + 0xbc0)); y += index; ret.value = fn_1_13F7F8(3, (s16)lbl_801A66B4); y += fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, font, ret.value); break;
                case 5: index = fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, 0x15, (u32)(text + 0xBD8)); y += index; ret.value = fn_1_13F7F8(10, (s16)lbl_801A66B4); y += fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, font, ret.value); break;
                case 6: index = fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, 0x15, (u32)(text + 0xbe8)); y += index; ret.value = fn_1_13F7F8(11, (s16)lbl_801A66B4); y += fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, font, ret.value); break;
                case 7: index = fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, 0x15, (u32)(text + 0xbf0)); y += index; ret.value = fn_1_13F7F8(12, (s16)lbl_801A66B4); y += fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, font, ret.value); break;
                case 8: index = fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, 0x15, (u32)(text + 0xbe0)); y += index; ret.value = fn_1_13F7F8(9, (s16)lbl_801A66B4); y += fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, font, ret.value); break;
                case 9: index = fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, 0x15, (u32)(text + 0xbe0)); y += index; ret.value = fn_1_13F7F8(8, (s16)lbl_801A66B4); y += fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, font, ret.value); break;
                case 10: index = fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, 0x15, (u32)(text + 0xbf8)); y += index; ret.value = fn_1_13F7F8(13, (s16)lbl_801A66B4); y += fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, font, ret.value); break;
                case 11: index = fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, 0x15, (u32)(text + 0xbdc)); y += index; ret.value = fn_1_13F7F8(14, (s16)lbl_801A66B4); y += fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, font, ret.value); break;
                case 12: index = fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, 0x15, (u32)(text + 0xbdc)); y += index; ret.value = fn_1_13F7F8(15, (s16)lbl_801A66B4); y += fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, font, ret.value); break;
                case 13: index = fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, 0x15, (u32)(text + 0xbb8)); y += index; ret.value = fn_1_13F7F8(16, (s16)lbl_801A66B4); y += fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, font, ret.value); break;
                case 14: index = fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, 0x15, (u32)(text + 0xbe0)); y += index; ret.value = fn_1_13F7F8(17, (s16)lbl_801A66B4); y += fn_1_13B24C(pass, ((baseY) + (y)), 0x1b7, font, ret.value); break;
                }
                mask &= ~(bits >> caseIndex);
            }
            if (pass == 0) previous = y;
        }
    }
}
#pragma opt_common_subs reset

#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset

