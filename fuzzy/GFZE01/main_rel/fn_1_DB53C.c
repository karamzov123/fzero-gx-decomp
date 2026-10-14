/* Non-matching: best partial attempt (83.94% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/bg_san.h"

typedef struct { f32 x, y, z; } Vec3;
typedef struct { u32 x, y, z; } Triple;
typedef struct {
    f32 unk_0;
    u8 pad_4[4];
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x24];
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
} Pool;

extern const Pool lbl_1_rodata_6638;
extern s32 fn_1_58C4(void);
extern f32 fn_1_DC084(Vec3 *);
extern s32 fn_1_54E34(void *, f32);
extern s16 fn_1_3F0C8(void);
extern s16 camera_get_mode(void);
extern u32 camera_get_flags(void);
extern void fn_1_862D4(void *, Triple *);
extern u32 fn_1_864E8(void *);
extern s32 fn_1_5910(void);
extern s32 fn_1_6F84(void);
extern u32 camera_forward_status(void);
extern s32 fn_1_1FC98(void *, s32);
extern void *fn_1_8627C(s32);
extern void fn_1_DB9B0(void *, u32);
extern void lbl_8006DCA4(void);
extern void u_gxutil_upload_some_mtx(u32, u32);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80073778(void *, s32);
extern u32 fn_80036104(void *);
extern u32 GXGetTexObjHeight(void *);
extern u32 GXGetTexObjWidth(void *);
extern void *fn_800360D8(void *);
typedef struct { u32 dummy[8]; } GXTexObj;
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, s32, s32, s32, u8);
extern void fn_8007245C(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072EDC(s32, s32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_80073898(u32);
extern u32 lbl_801A6D00;
extern u32 lbl_1_bss_7ADB8[12];

void fn_1_DB53C(void *arg0) {
    s32 count;
    void *texture;
    u32 image;
    u32 height;
    u32 width;
    u32 format;
    s32 index;
    s32 mode;
    s32 mask;
    s32 i;
    u32 flags;
    Vec3 position;
    Triple saved;

    count = fn_1_58C4();
    if (count >= 2)
        return;
    texture = (void *)lbl_1_data_2A7E0.unk_3C;
    i = *(s32 *)((u8 *)arg0 + 8);
    lbl_8006DCA4();
    u_gxutil_upload_some_mtx(lbl_801A6D00, 0);
    fn_80072864(0);
    fn_800728A8(1, 4, 1, 0);
    fn_80073778((void *)((u8 *)texture + 0x24), 0);
    image = fn_80036104((void *)((u8 *)texture + 0x24));
    height = GXGetTexObjHeight((void *)((u8 *)texture + 0x24));
    width = GXGetTexObjWidth((void *)((u8 *)texture + 0x24));
    GXInitTexObj((GXTexObj *)((u8 *)texture + 0x24),
                 fn_800360D8((void *)((u8 *)texture + 0x24)),
                 width, height, image, 0, 1, 0);
    fn_8007245C(0x2a00);
    fn_800747D0(4, 0, 1, 1, 0, 2, 2);
    fn_80073C6C(0);
    fn_800745A4(0, 1, 4, 0x3c, 0, 0x7d);
    fn_800734A8(0, 0, 0, 4);
    fn_80072EDC(0, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80074788(1);
    fn_80073898(0);

    for (index = i; index > 0; index--) {
        u8 *item = (u8 *)texture + 0x14 + (i - index) * 0x1020;
        u32 *source = (u32 *)*(u32 *)item;
        position.x = *(f32 *)((u8 *)source + 0xc) + *(f32 *)(item + 0x820);
        position.y = *(f32 *)((u8 *)source + 0x10) + *(f32 *)(item + 0x824);
        position.z = *(f32 *)((u8 *)source + 0x14) + *(f32 *)(item + 0x828);
        position.x *= 0.5f;
        position.y *= 0.5f;
        position.z *= 0.5f;
        if (fn_1_DC084(&position) > lbl_1_rodata_6638.unk_34) {
            f32 distance = fn_1_DC084(&position);
            if (distance > lbl_1_rodata_6638.unk_38)
                *(f32 *)(item + 0x14) = lbl_1_rodata_6638.unk_0;
            else
                *(f32 *)(item + 0x14) = 1.0f -
                    (distance - lbl_1_rodata_6638.unk_34) /
                    lbl_1_rodata_6638.unk_3C;
        } else {
            *(f32 *)(item + 0x14) = 1.0f;
        }
        lbl_8006DCA4();
        if (fn_1_54E34(&position, lbl_1_rodata_6638.unk_40) != 0 ||
            fn_1_3F0C8() == 0x27) {
            mode = camera_get_mode();
            flags = camera_get_flags();
            if (flags != 0 && (s32)lbl_1_data_3DC70 >= 0)
                mode = lbl_1_data_3DC70;
            lbl_1_data_3DC70 = mode;
            mask = 0;
            if (mode >= 0) {
                fn_1_862D4((void *)mode, &saved);
                if (fn_1_864E8((void *)mode) & 0x800) {
                    s32 slot = fn_1_5910();
                    saved.x = lbl_1_bss_7ADB8[slot * 3];
                    saved.y = lbl_1_bss_7ADB8[slot * 3 + 1];
                    saved.z = lbl_1_bss_7ADB8[slot * 3 + 2];
                } else if (fn_1_6F84() != 0) {
                    if (camera_forward_status() & 1) {
                        s32 slot = fn_1_5910();
                        lbl_1_bss_7ADB8[slot * 3] = saved.x;
                        lbl_1_bss_7ADB8[slot * 3 + 1] = saved.y;
                        lbl_1_bss_7ADB8[slot * 3 + 2] = saved.z;
                    } else {
                        s32 slot = fn_1_5910();
                        saved.x = lbl_1_bss_7ADB8[slot * 3];
                        saved.y = lbl_1_bss_7ADB8[slot * 3 + 1];
                        saved.z = lbl_1_bss_7ADB8[slot * 3 + 2];
                    }
                } else {
                    s32 slot = fn_1_5910();
                    lbl_1_bss_7ADB8[slot * 3] = saved.x;
                    lbl_1_bss_7ADB8[slot * 3 + 1] = saved.y;
                    lbl_1_bss_7ADB8[slot * 3 + 2] = saved.z;
                }
                mask = fn_1_1FC98(&saved, -1);
                {
                    u8 *camera = fn_1_8627C(mode);
                    if (camera != 0 && *(s32 *)(camera + 0xb8) >= 0) {
                        s32 n = *(s32 *)(camera + 0xb8);
                        void *entry = *(void **)(*(u32 *)((u8 *)lbl_1_bss_3BE0 + 0) + 0xc + n * 12 + 8);
                        if (entry != 0)
                            mask |= *(u32 *)((u8 *)entry + 0x38);
                    }
                }
            }
            if (mask & *(u32 *)*(u32 *)item)
                fn_1_DB9B0(item, *(u32 *)((u8 *)arg0 + 8));
            else if (fn_1_3F0C8() == 0x27)
                fn_1_DB9B0(item, *(u32 *)((u8 *)arg0 + 8));
        }
    }
}
